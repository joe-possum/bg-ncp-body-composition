/* standard library headers */
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

/* BG stack headers */
#include "bg_types.h"
#include "gecko_bglib.h"

/* Own header */
#include "app.h"
#include "dump.h"
#include "support.h"
#include "common.h"

#define gattdb_body_composition_feature         16
#define gattdb_body_composition_measurement         18

// App booted flag
static bool appBooted = false;
static struct {
  char *name;
  uint32 advertising_interval, features;
  uint16 connection_interval, mtu; 
  uint8 connection, subscribed, userid;
  uint16 bfp, bmr, mp, mm,ffm,slm,bwm,impedance,weight,height;
} config = {
	     .connection = 0xff,
	     .name = NULL,
	     .advertising_interval = 160, // 100 ms
	     .connection_interval = 80, // 100 ms
	     .mtu = 23,
	     .features = 0, // Timestamp
	     .bfp = 50,
};

#define ADD(X) do { memcpy(data,&X,sizeof(X)); data += sizeof(X); len += sizeof(X); } while(0)
void send_notification(void) {
  struct timeval now;
  gettimeofday(&now,NULL);
  time_t time_now = now.tv_sec;
  struct tm *tm = localtime(&time_now);
  uint8 buf[43];
  uint8 *data = buf;
  uint8 len = 0;
  struct __attribute__((__packed__)) ts {
    uint16 year;
    uint8 month, day, hours, minutes, seconds;
  } ts = {tm->tm_year+1900,tm->tm_mon+1,tm->tm_mday,tm->tm_hour,tm->tm_min,tm->tm_sec};
  printf("Timestamp: year:%d, month:%d, day:%d, hours:%d, minutes:%d, seconds:%d\n",ts.year,ts.month,ts.day,ts.hours,ts.minutes,ts.seconds);
  uint16 flags = 1 | (config.features << 1);
  ADD(flags);
  ADD(config.bfp);
  if(flags & 2) ADD(ts);
  if(flags & 4) ADD(config.userid);
  if(flags & 8) ADD(config.bmr);
  if(flags & 16) ADD(config.mp);
  if(flags & 32) ADD(config.mm);
  if(flags & 64) ADD(config.ffm);
  if(flags & 128) ADD(config.slm);
  if(flags & 256) ADD(config.bwm);
  if(flags & 512) ADD(config.impedance);
  if(flags & 1024) ADD(config.weight);
  if(flags & 2048) ADD(config.height);
  gecko_cmd_gatt_server_send_characteristic_notification(config.connection,
							 gattdb_body_composition_measurement,
							 len,
							 buf);

}

const char *getAppOptions(void) {
  return "a<remote-address>n<name>f<body-fat-percentage>b<basal-metabolism-kJ>m<muscle-percentage>M<muscle-mass-lb>r<fat-free-mass-lb>s<soft-lean-mass>e<body-water-mass-lb>z<impedance-ohms>w<weight-lb>h<height-inches>";
}

void appOption(int option, const char *arg) {
  double dv;
  int iv;
  switch(option) {
  case 'i':
    sscanf(arg,"%lf",&dv);
    config.advertising_interval = round(dv/0.625);
    config.connection_interval = round(dv/1.25);
    break;
  case 'f':
    sscanf(arg,"%lf",&dv);
    config.bfp = round(10*dv);
    break;
  case 'n':
    config.name = strdup(arg);
    break;
  case 'u':
    config.features |= 2;
    sscanf(arg,"%i",&iv);
    config.userid = iv;
    break;
  case 'b':
    config.features |= 4;
    sscanf(arg,"%lf",&dv);
    config.bmr = round(dv);
    break;
  case 'm':
    config.features |= 8;
    sscanf(arg,"%lf",&dv);
    config.mp = round(10*dv);
    break;
  case 'M':
    config.features |= 16;
    sscanf(arg,"%lf",&dv);
    config.mm = round(100*dv);
    break;
  case 'r':
    config.features |= 32;
    sscanf(arg,"%lf",&dv);
    config.ffm = round(100*dv);
    break;
  case 's':
    config.features |= 64;
    sscanf(arg,"%lf",&dv);
    config.slm = round(100*dv);
    break;
  case 'e':
    config.features |= 128;
    sscanf(arg,"%lf",&dv);
    config.bwm = round(100*dv);
    break;
  case 'z':
    config.features |= 256;
    sscanf(arg,"%lf",&dv);
    config.impedance = round(10*dv);
    break;
  case 'w':
    config.features |= 512;
    sscanf(arg,"%lf",&dv);
    config.weight = round(100*dv);
    break;
  case 'h':
    config.features |= 1024;
    sscanf(arg,"%lf",&dv);
    config.height = round(10*dv);
    break;

  default:
    fprintf(stderr,"Unhandled option '-%c'\n",option);
    exit(1);
  }
}

void appInit(void) {
}

/***********************************************************************************************//**
 *  \brief  Event handler function.
 *  \param[in] evt Event pointer.
 **************************************************************************************************/
void appHandleEvents(struct gecko_cmd_packet *evt)
{
  if (NULL == evt) {
    return;
  }

  // Do not handle any events until system is booted up properly.
  if ((BGLIB_MSG_ID(evt->header) != gecko_evt_system_boot_id)
      && !appBooted) {
#if defined(DEBUG)
    printf("Event: 0x%04x\n", BGLIB_MSG_ID(evt->header));
#endif
    millisleep(50);
    return;
  }

  /* Handle events */
#ifdef DUMP
  switch (BGLIB_MSG_ID(evt->header)) {
  default:
    dump_event(evt);
  }
#endif
  switch (BGLIB_MSG_ID(evt->header)) {
  case gecko_evt_system_boot_id: /*********************************************************************************** system_boot **/
#define ED evt->data.evt_system_boot
    appBooted = true;
    uint8 discoverable_mode = le_gap_general_discoverable;
    if(config.name) {
      uint8 buf[31];
      uint8 len = 0;
      len += ad_flags(&buf[len],6);
      len += ad_name(&buf[len],config.name);
      gecko_cmd_le_gap_bt5_set_adv_data(0,0,len,buf);
      discoverable_mode = le_gap_user_data;
    }
    gecko_cmd_le_gap_set_advertise_timing(0,config.advertising_interval,config.advertising_interval,0,0);
    gecko_cmd_le_gap_start_advertising(0,discoverable_mode,le_gap_connectable_scannable);
    gecko_cmd_system_get_bt_address();
    gecko_cmd_gatt_server_write_attribute_value(gattdb_body_composition_feature,0,4,(uint8*)&config.features);
    break;
#undef ED

  case gecko_evt_hardware_soft_timer_id: /******************************************************************* hardware_soft_timer **/
#define ED evt->data.evt_hardware_soft_timer
    if(config.subscribed) send_notification();
    break;
#undef ED

  case gecko_evt_le_connection_opened_id: /***************************************************************** le_connection_opened **/
#define ED evt->data.evt_le_connection_opened
    config.connection = ED.connection;
    config.subscribed = 0;
    break;
#undef ED

  case gecko_evt_gatt_server_characteristic_status_id: /*************************************** gatt_server_characteristic_status **/
#define ED evt->data.evt_gatt_server_characteristic_status
    if(1 == ED.status_flags) config.subscribed = ED.client_config_flags;
    break;
#undef ED

  case gecko_evt_gatt_mtu_exchanged_id: /********************************************************************* gatt_mtu_exchanged **/
#define ED evt->data.evt_gatt_mtu_exchanged
    config.mtu = ED.mtu;
    gecko_cmd_hardware_set_soft_timer(1<<15,0,0);
    break;
#undef ED

  case gecko_evt_le_connection_closed_id: /***************************************************************** le_connection_closed **/
#define ED evt->data.evt_le_connection_closed
    exit(1);
    break;
#undef ED

  default:
    break;
  }
}
