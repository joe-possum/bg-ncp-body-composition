#ifdef WIN32
#  include "host_gecko.h"
#else
#  include "host_gecko.h"
#endif
#include <stdio.h>
int dump_mode = 0;
void dump_timestamp(int onoff) {
  if(onoff) dump_mode |= 1; else dump_mode &= ~1u;
}
#undef gecko_cmd_hardware_get_time
static char timestamp_buffer[32];
char *dump_get_timestamp(void) {
  struct gecko_msg_hardware_get_time_rsp_t*t = gecko_cmd_hardware_get_time();
  sprintf(timestamp_buffer,"%u.%05lu",t->seconds,(3052UL*t->ticks)/1000);
  return timestamp_buffer;
}
void dump_event_header(const char*str) {
 if(1&dump_mode) printf("@%s\n",dump_get_timestamp()); else printf("\n\033[36m");
  printf("EVENT %s\n",str);
}
void dump_command_header(const char*str) {
 if(1&dump_mode) printf("@%s\n",dump_get_timestamp()); else printf("\n\033[31m");
  printf("COMMAND %s\n",str);
}
void dump_footer(void) {
 if(1&dump_mode) return; else printf("\n\033[0m");
}
void dump_event(struct gecko_cmd_packet *evt) {
  switch(BGLIB_MSG_ID(evt->header)) {
  case gecko_evt_dfu_boot_id:
    dump_event_header("dfu_boot");
   printf("  uint32      version: 0x%08x\n",(int)evt->data.evt_dfu_boot.version);
    break;
  case gecko_evt_dfu_boot_failure_id:
    dump_event_header("dfu_boot_failure");
   printf("  uint16      reason: 0x%04x\n",(int)evt->data.evt_dfu_boot_failure.reason);
    break;
  case gecko_evt_system_boot_id:
    dump_event_header("system_boot");
   printf("  uint16      major: 0x%04x\n",(int)evt->data.evt_system_boot.major);
   printf("  uint16      minor: 0x%04x\n",(int)evt->data.evt_system_boot.minor);
   printf("  uint16      patch: 0x%04x\n",(int)evt->data.evt_system_boot.patch);
   printf("  uint16      build: 0x%04x\n",(int)evt->data.evt_system_boot.build);
   printf("  uint32      bootloader: 0x%08x\n",(int)evt->data.evt_system_boot.bootloader);
   printf("  uint16      hw: 0x%04x\n",(int)evt->data.evt_system_boot.hw);
   printf("  uint32      hash: 0x%08x\n",(int)evt->data.evt_system_boot.hash);
    break;
  case gecko_evt_system_external_signal_id:
    dump_event_header("system_external_signal");
   printf("  uint32      extsignals: 0x%08x\n",(int)evt->data.evt_system_external_signal.extsignals);
    break;
  case gecko_evt_system_hardware_error_id:
    dump_event_header("system_hardware_error");
   printf("  uint16      status: 0x%04x\n",(int)evt->data.evt_system_hardware_error.status);
    break;
  case gecko_evt_system_error_id:
    dump_event_header("system_error");
   printf("  uint16      reason: 0x%04x\n",(int)evt->data.evt_system_error.reason);
   printf("  uint8array  data: %d:",(int)evt->data.evt_system_error.data.len);
   for(int i = 0; i < evt->data.evt_system_error.data.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_system_error.data.data[i]);
   printf("}\n");
    break;
  case gecko_evt_le_gap_scan_response_id:
    dump_event_header("le_gap_scan_response");
   printf("  int8        rssi: 0x%02x\n",(int)evt->data.evt_le_gap_scan_response.rssi);
   printf("  uint8       packet_type: 0x%02x\n",(int)evt->data.evt_le_gap_scan_response.packet_type);
   printf("  bd_addr     address: ");
   for(int i = 0; i < 6; i++)
      printf("%s%02x",(i)?":":"",evt->data.evt_le_gap_scan_response.address.addr[5-i]);
   printf("\n");
   printf("  uint8       address_type: 0x%02x\n",(int)evt->data.evt_le_gap_scan_response.address_type);
   printf("  uint8       bonding: 0x%02x\n",(int)evt->data.evt_le_gap_scan_response.bonding);
   printf("  uint8array  data: %d:",(int)evt->data.evt_le_gap_scan_response.data.len);
   for(int i = 0; i < evt->data.evt_le_gap_scan_response.data.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_le_gap_scan_response.data.data[i]);
   printf("}\n");
    break;
  case gecko_evt_le_gap_adv_timeout_id:
    dump_event_header("le_gap_adv_timeout");
   printf("  uint8       handle: 0x%02x\n",(int)evt->data.evt_le_gap_adv_timeout.handle);
    break;
  case gecko_evt_le_gap_scan_request_id:
    dump_event_header("le_gap_scan_request");
   printf("  uint8       handle: 0x%02x\n",(int)evt->data.evt_le_gap_scan_request.handle);
   printf("  bd_addr     address: ");
   for(int i = 0; i < 6; i++)
      printf("%s%02x",(i)?":":"",evt->data.evt_le_gap_scan_request.address.addr[5-i]);
   printf("\n");
   printf("  uint8       address_type: 0x%02x\n",(int)evt->data.evt_le_gap_scan_request.address_type);
   printf("  uint8       bonding: 0x%02x\n",(int)evt->data.evt_le_gap_scan_request.bonding);
    break;
  case gecko_evt_le_gap_extended_scan_response_id:
    dump_event_header("le_gap_extended_scan_response");
   printf("  uint8       packet_type: 0x%02x\n",(int)evt->data.evt_le_gap_extended_scan_response.packet_type);
   printf("  bd_addr     address: ");
   for(int i = 0; i < 6; i++)
      printf("%s%02x",(i)?":":"",evt->data.evt_le_gap_extended_scan_response.address.addr[5-i]);
   printf("\n");
   printf("  uint8       address_type: 0x%02x\n",(int)evt->data.evt_le_gap_extended_scan_response.address_type);
   printf("  uint8       bonding: 0x%02x\n",(int)evt->data.evt_le_gap_extended_scan_response.bonding);
   printf("  uint8       primary_phy: 0x%02x\n",(int)evt->data.evt_le_gap_extended_scan_response.primary_phy);
   printf("  uint8       secondary_phy: 0x%02x\n",(int)evt->data.evt_le_gap_extended_scan_response.secondary_phy);
   printf("  uint8       adv_sid: 0x%02x\n",(int)evt->data.evt_le_gap_extended_scan_response.adv_sid);
   printf("  int8        tx_power: 0x%02x\n",(int)evt->data.evt_le_gap_extended_scan_response.tx_power);
   printf("  int8        rssi: 0x%02x\n",(int)evt->data.evt_le_gap_extended_scan_response.rssi);
   printf("  uint8       channel: 0x%02x\n",(int)evt->data.evt_le_gap_extended_scan_response.channel);
   printf("  uint16      periodic_interval: 0x%04x\n",(int)evt->data.evt_le_gap_extended_scan_response.periodic_interval);
   printf("  uint8array  data: %d:",(int)evt->data.evt_le_gap_extended_scan_response.data.len);
   for(int i = 0; i < evt->data.evt_le_gap_extended_scan_response.data.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_le_gap_extended_scan_response.data.data[i]);
   printf("}\n");
    break;
  case gecko_evt_le_gap_periodic_advertising_status_id:
    dump_event_header("le_gap_periodic_advertising_status");
   printf("  uint8       sid: 0x%02x\n",(int)evt->data.evt_le_gap_periodic_advertising_status.sid);
   printf("  uint32      status: 0x%08x\n",(int)evt->data.evt_le_gap_periodic_advertising_status.status);
    break;
  case gecko_evt_sync_opened_id:
    dump_event_header("sync_opened");
   printf("  uint8       sync: 0x%02x\n",(int)evt->data.evt_sync_opened.sync);
   printf("  uint8       adv_sid: 0x%02x\n",(int)evt->data.evt_sync_opened.adv_sid);
   printf("  bd_addr     address: ");
   for(int i = 0; i < 6; i++)
      printf("%s%02x",(i)?":":"",evt->data.evt_sync_opened.address.addr[5-i]);
   printf("\n");
   printf("  uint8       address_type: 0x%02x\n",(int)evt->data.evt_sync_opened.address_type);
   printf("  uint8       adv_phy: 0x%02x\n",(int)evt->data.evt_sync_opened.adv_phy);
   printf("  uint16      adv_interval: 0x%04x\n",(int)evt->data.evt_sync_opened.adv_interval);
   printf("  uint16      clock_accuracy: 0x%04x\n",(int)evt->data.evt_sync_opened.clock_accuracy);
    break;
  case gecko_evt_sync_closed_id:
    dump_event_header("sync_closed");
   printf("  uint16      reason: 0x%04x\n",(int)evt->data.evt_sync_closed.reason);
   printf("  uint8       sync: 0x%02x\n",(int)evt->data.evt_sync_closed.sync);
    break;
  case gecko_evt_sync_data_id:
    dump_event_header("sync_data");
   printf("  uint8       sync: 0x%02x\n",(int)evt->data.evt_sync_data.sync);
   printf("  int8        tx_power: 0x%02x\n",(int)evt->data.evt_sync_data.tx_power);
   printf("  int8        rssi: 0x%02x\n",(int)evt->data.evt_sync_data.rssi);
   printf("  uint8       data_status: 0x%02x\n",(int)evt->data.evt_sync_data.data_status);
   printf("  uint8array  data: %d:",(int)evt->data.evt_sync_data.data.len);
   for(int i = 0; i < evt->data.evt_sync_data.data.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_sync_data.data.data[i]);
   printf("}\n");
    break;
  case gecko_evt_le_connection_opened_id:
    dump_event_header("le_connection_opened");
   printf("  bd_addr     address: ");
   for(int i = 0; i < 6; i++)
      printf("%s%02x",(i)?":":"",evt->data.evt_le_connection_opened.address.addr[5-i]);
   printf("\n");
   printf("  uint8       address_type: 0x%02x\n",(int)evt->data.evt_le_connection_opened.address_type);
   printf("  uint8       master: 0x%02x\n",(int)evt->data.evt_le_connection_opened.master);
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_le_connection_opened.connection);
   printf("  uint8       bonding: 0x%02x\n",(int)evt->data.evt_le_connection_opened.bonding);
   printf("  uint8       advertiser: 0x%02x\n",(int)evt->data.evt_le_connection_opened.advertiser);
    break;
  case gecko_evt_le_connection_closed_id:
    dump_event_header("le_connection_closed");
   printf("  uint16      reason: 0x%04x\n",(int)evt->data.evt_le_connection_closed.reason);
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_le_connection_closed.connection);
    break;
  case gecko_evt_le_connection_parameters_id:
    dump_event_header("le_connection_parameters");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_le_connection_parameters.connection);
   printf("  uint16      interval: 0x%04x\n",(int)evt->data.evt_le_connection_parameters.interval);
   printf("  uint16      latency: 0x%04x\n",(int)evt->data.evt_le_connection_parameters.latency);
   printf("  uint16      timeout: 0x%04x\n",(int)evt->data.evt_le_connection_parameters.timeout);
   printf("  uint8       security_mode: 0x%02x\n",(int)evt->data.evt_le_connection_parameters.security_mode);
   printf("  uint16      txsize: 0x%04x\n",(int)evt->data.evt_le_connection_parameters.txsize);
    break;
  case gecko_evt_le_connection_rssi_id:
    dump_event_header("le_connection_rssi");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_le_connection_rssi.connection);
   printf("  uint8       status: 0x%02x\n",(int)evt->data.evt_le_connection_rssi.status);
   printf("  int8        rssi: 0x%02x\n",(int)evt->data.evt_le_connection_rssi.rssi);
    break;
  case gecko_evt_le_connection_phy_status_id:
    dump_event_header("le_connection_phy_status");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_le_connection_phy_status.connection);
   printf("  uint8       phy: 0x%02x\n",(int)evt->data.evt_le_connection_phy_status.phy);
    break;
  case gecko_evt_gatt_mtu_exchanged_id:
    dump_event_header("gatt_mtu_exchanged");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_gatt_mtu_exchanged.connection);
   printf("  uint16      mtu: 0x%04x\n",(int)evt->data.evt_gatt_mtu_exchanged.mtu);
    break;
  case gecko_evt_gatt_service_id:
    dump_event_header("gatt_service");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_gatt_service.connection);
   printf("  uint32      service: 0x%08x\n",(int)evt->data.evt_gatt_service.service);
   printf("  uint8array  uuid: %d:",(int)evt->data.evt_gatt_service.uuid.len);
   for(int i = 0; i < evt->data.evt_gatt_service.uuid.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_gatt_service.uuid.data[i]);
   printf("}\n");
    break;
  case gecko_evt_gatt_characteristic_id:
    dump_event_header("gatt_characteristic");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_gatt_characteristic.connection);
   printf("  uint16      characteristic: 0x%04x\n",(int)evt->data.evt_gatt_characteristic.characteristic);
   printf("  uint8       properties: 0x%02x\n",(int)evt->data.evt_gatt_characteristic.properties);
   printf("  uint8array  uuid: %d:",(int)evt->data.evt_gatt_characteristic.uuid.len);
   for(int i = 0; i < evt->data.evt_gatt_characteristic.uuid.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_gatt_characteristic.uuid.data[i]);
   printf("}\n");
    break;
  case gecko_evt_gatt_descriptor_id:
    dump_event_header("gatt_descriptor");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_gatt_descriptor.connection);
   printf("  uint16      descriptor: 0x%04x\n",(int)evt->data.evt_gatt_descriptor.descriptor);
   printf("  uint8array  uuid: %d:",(int)evt->data.evt_gatt_descriptor.uuid.len);
   for(int i = 0; i < evt->data.evt_gatt_descriptor.uuid.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_gatt_descriptor.uuid.data[i]);
   printf("}\n");
    break;
  case gecko_evt_gatt_characteristic_value_id:
    dump_event_header("gatt_characteristic_value");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_gatt_characteristic_value.connection);
   printf("  uint16      characteristic: 0x%04x\n",(int)evt->data.evt_gatt_characteristic_value.characteristic);
   printf("  uint8       att_opcode: 0x%02x\n",(int)evt->data.evt_gatt_characteristic_value.att_opcode);
   printf("  uint16      offset: 0x%04x\n",(int)evt->data.evt_gatt_characteristic_value.offset);
   printf("  uint8array  value: %d:",(int)evt->data.evt_gatt_characteristic_value.value.len);
   for(int i = 0; i < evt->data.evt_gatt_characteristic_value.value.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_gatt_characteristic_value.value.data[i]);
   printf("}\n");
    break;
  case gecko_evt_gatt_descriptor_value_id:
    dump_event_header("gatt_descriptor_value");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_gatt_descriptor_value.connection);
   printf("  uint16      descriptor: 0x%04x\n",(int)evt->data.evt_gatt_descriptor_value.descriptor);
   printf("  uint16      offset: 0x%04x\n",(int)evt->data.evt_gatt_descriptor_value.offset);
   printf("  uint8array  value: %d:",(int)evt->data.evt_gatt_descriptor_value.value.len);
   for(int i = 0; i < evt->data.evt_gatt_descriptor_value.value.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_gatt_descriptor_value.value.data[i]);
   printf("}\n");
    break;
  case gecko_evt_gatt_procedure_completed_id:
    dump_event_header("gatt_procedure_completed");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_gatt_procedure_completed.connection);
   printf("  uint16      result: 0x%04x\n",(int)evt->data.evt_gatt_procedure_completed.result);
    break;
  case gecko_evt_gatt_server_attribute_value_id:
    dump_event_header("gatt_server_attribute_value");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_gatt_server_attribute_value.connection);
   printf("  uint16      attribute: 0x%04x\n",(int)evt->data.evt_gatt_server_attribute_value.attribute);
   printf("  uint8       att_opcode: 0x%02x\n",(int)evt->data.evt_gatt_server_attribute_value.att_opcode);
   printf("  uint16      offset: 0x%04x\n",(int)evt->data.evt_gatt_server_attribute_value.offset);
   printf("  uint8array  value: %d:",(int)evt->data.evt_gatt_server_attribute_value.value.len);
   for(int i = 0; i < evt->data.evt_gatt_server_attribute_value.value.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_gatt_server_attribute_value.value.data[i]);
   printf("}\n");
    break;
  case gecko_evt_gatt_server_user_read_request_id:
    dump_event_header("gatt_server_user_read_request");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_gatt_server_user_read_request.connection);
   printf("  uint16      characteristic: 0x%04x\n",(int)evt->data.evt_gatt_server_user_read_request.characteristic);
   printf("  uint8       att_opcode: 0x%02x\n",(int)evt->data.evt_gatt_server_user_read_request.att_opcode);
   printf("  uint16      offset: 0x%04x\n",(int)evt->data.evt_gatt_server_user_read_request.offset);
    break;
  case gecko_evt_gatt_server_user_write_request_id:
    dump_event_header("gatt_server_user_write_request");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_gatt_server_user_write_request.connection);
   printf("  uint16      characteristic: 0x%04x\n",(int)evt->data.evt_gatt_server_user_write_request.characteristic);
   printf("  uint8       att_opcode: 0x%02x\n",(int)evt->data.evt_gatt_server_user_write_request.att_opcode);
   printf("  uint16      offset: 0x%04x\n",(int)evt->data.evt_gatt_server_user_write_request.offset);
   printf("  uint8array  value: %d:",(int)evt->data.evt_gatt_server_user_write_request.value.len);
   for(int i = 0; i < evt->data.evt_gatt_server_user_write_request.value.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_gatt_server_user_write_request.value.data[i]);
   printf("}\n");
    break;
  case gecko_evt_gatt_server_characteristic_status_id:
    dump_event_header("gatt_server_characteristic_status");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_gatt_server_characteristic_status.connection);
   printf("  uint16      characteristic: 0x%04x\n",(int)evt->data.evt_gatt_server_characteristic_status.characteristic);
   printf("  uint8       status_flags: 0x%02x\n",(int)evt->data.evt_gatt_server_characteristic_status.status_flags);
   printf("  uint16      client_config_flags: 0x%04x\n",(int)evt->data.evt_gatt_server_characteristic_status.client_config_flags);
    break;
  case gecko_evt_gatt_server_execute_write_completed_id:
    dump_event_header("gatt_server_execute_write_completed");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_gatt_server_execute_write_completed.connection);
   printf("  uint16      result: 0x%04x\n",(int)evt->data.evt_gatt_server_execute_write_completed.result);
    break;
  case gecko_evt_hardware_soft_timer_id:
    dump_event_header("hardware_soft_timer");
   printf("  uint8       handle: 0x%02x\n",(int)evt->data.evt_hardware_soft_timer.handle);
    break;
  case gecko_evt_test_dtm_completed_id:
    dump_event_header("test_dtm_completed");
   printf("  uint16      result: 0x%04x\n",(int)evt->data.evt_test_dtm_completed.result);
   printf("  uint16      number_of_packets: 0x%04x\n",(int)evt->data.evt_test_dtm_completed.number_of_packets);
    break;
  case gecko_evt_sm_passkey_display_id:
    dump_event_header("sm_passkey_display");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_sm_passkey_display.connection);
   printf("  uint32      passkey: 0x%08x\n",(int)evt->data.evt_sm_passkey_display.passkey);
    break;
  case gecko_evt_sm_passkey_request_id:
    dump_event_header("sm_passkey_request");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_sm_passkey_request.connection);
    break;
  case gecko_evt_sm_confirm_passkey_id:
    dump_event_header("sm_confirm_passkey");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_sm_confirm_passkey.connection);
   printf("  uint32      passkey: 0x%08x\n",(int)evt->data.evt_sm_confirm_passkey.passkey);
    break;
  case gecko_evt_sm_bonded_id:
    dump_event_header("sm_bonded");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_sm_bonded.connection);
   printf("  uint8       bonding: 0x%02x\n",(int)evt->data.evt_sm_bonded.bonding);
    break;
  case gecko_evt_sm_bonding_failed_id:
    dump_event_header("sm_bonding_failed");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_sm_bonding_failed.connection);
   printf("  uint16      reason: 0x%04x\n",(int)evt->data.evt_sm_bonding_failed.reason);
    break;
  case gecko_evt_sm_list_bonding_entry_id:
    dump_event_header("sm_list_bonding_entry");
   printf("  uint8       bonding: 0x%02x\n",(int)evt->data.evt_sm_list_bonding_entry.bonding);
   printf("  bd_addr     address: ");
   for(int i = 0; i < 6; i++)
      printf("%s%02x",(i)?":":"",evt->data.evt_sm_list_bonding_entry.address.addr[5-i]);
   printf("\n");
   printf("  uint8       address_type: 0x%02x\n",(int)evt->data.evt_sm_list_bonding_entry.address_type);
    break;
  case gecko_evt_sm_confirm_bonding_id:
    dump_event_header("sm_confirm_bonding");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_sm_confirm_bonding.connection);
   printf("  int8        bonding_handle: 0x%02x\n",(int)evt->data.evt_sm_confirm_bonding.bonding_handle);
    break;
  case gecko_evt_homekit_setupcode_display_id:
    dump_event_header("homekit_setupcode_display");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_homekit_setupcode_display.connection);
   printf("  uint8array  setupcode: %d:",(int)evt->data.evt_homekit_setupcode_display.setupcode.len);
   for(int i = 0; i < evt->data.evt_homekit_setupcode_display.setupcode.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_homekit_setupcode_display.setupcode.data[i]);
   printf("}\n");
    break;
  case gecko_evt_homekit_paired_id:
    dump_event_header("homekit_paired");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_homekit_paired.connection);
   printf("  uint16      reason: 0x%04x\n",(int)evt->data.evt_homekit_paired.reason);
    break;
  case gecko_evt_homekit_pair_verified_id:
    dump_event_header("homekit_pair_verified");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_homekit_pair_verified.connection);
   printf("  uint16      reason: 0x%04x\n",(int)evt->data.evt_homekit_pair_verified.reason);
    break;
  case gecko_evt_homekit_connection_opened_id:
    dump_event_header("homekit_connection_opened");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_homekit_connection_opened.connection);
    break;
  case gecko_evt_homekit_connection_closed_id:
    dump_event_header("homekit_connection_closed");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_homekit_connection_closed.connection);
   printf("  uint16      reason: 0x%04x\n",(int)evt->data.evt_homekit_connection_closed.reason);
    break;
  case gecko_evt_homekit_identify_id:
    dump_event_header("homekit_identify");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_homekit_identify.connection);
    break;
  case gecko_evt_homekit_write_request_id:
    dump_event_header("homekit_write_request");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_homekit_write_request.connection);
   printf("  uint16      characteristic: 0x%04x\n",(int)evt->data.evt_homekit_write_request.characteristic);
   printf("  uint16      chr_value_size: 0x%04x\n",(int)evt->data.evt_homekit_write_request.chr_value_size);
   printf("  uint16      authorization_size: 0x%04x\n",(int)evt->data.evt_homekit_write_request.authorization_size);
   printf("  uint16      value_offset: 0x%04x\n",(int)evt->data.evt_homekit_write_request.value_offset);
   printf("  uint8array  value: %d:",(int)evt->data.evt_homekit_write_request.value.len);
   for(int i = 0; i < evt->data.evt_homekit_write_request.value.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_homekit_write_request.value.data[i]);
   printf("}\n");
    break;
  case gecko_evt_homekit_read_request_id:
    dump_event_header("homekit_read_request");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_homekit_read_request.connection);
   printf("  uint16      characteristic: 0x%04x\n",(int)evt->data.evt_homekit_read_request.characteristic);
   printf("  uint16      offset: 0x%04x\n",(int)evt->data.evt_homekit_read_request.offset);
    break;
  case gecko_evt_homekit_disconnection_required_id:
    dump_event_header("homekit_disconnection_required");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_homekit_disconnection_required.connection);
   printf("  uint16      reason: 0x%04x\n",(int)evt->data.evt_homekit_disconnection_required.reason);
    break;
  case gecko_evt_homekit_pairing_removed_id:
    dump_event_header("homekit_pairing_removed");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_homekit_pairing_removed.connection);
   printf("  uint16      remaining_pairings: 0x%04x\n",(int)evt->data.evt_homekit_pairing_removed.remaining_pairings);
   printf("  uint8array  pairing_id: %d:",(int)evt->data.evt_homekit_pairing_removed.pairing_id.len);
   for(int i = 0; i < evt->data.evt_homekit_pairing_removed.pairing_id.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_homekit_pairing_removed.pairing_id.data[i]);
   printf("}\n");
    break;
  case gecko_evt_homekit_setuppayload_display_id:
    dump_event_header("homekit_setuppayload_display");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_homekit_setuppayload_display.connection);
   printf("  uint8array  setuppayload: %d:",(int)evt->data.evt_homekit_setuppayload_display.setuppayload.len);
   for(int i = 0; i < evt->data.evt_homekit_setuppayload_display.setuppayload.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_homekit_setuppayload_display.setuppayload.data[i]);
   printf("}\n");
    break;
  case gecko_evt_l2cap_coc_connection_request_id:
    dump_event_header("l2cap_coc_connection_request");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_l2cap_coc_connection_request.connection);
   printf("  uint16      le_psm: 0x%04x\n",(int)evt->data.evt_l2cap_coc_connection_request.le_psm);
   printf("  uint16      source_cid: 0x%04x\n",(int)evt->data.evt_l2cap_coc_connection_request.source_cid);
   printf("  uint16      mtu: 0x%04x\n",(int)evt->data.evt_l2cap_coc_connection_request.mtu);
   printf("  uint16      mps: 0x%04x\n",(int)evt->data.evt_l2cap_coc_connection_request.mps);
   printf("  uint16      initial_credit: 0x%04x\n",(int)evt->data.evt_l2cap_coc_connection_request.initial_credit);
   printf("  uint8       flags: 0x%02x\n",(int)evt->data.evt_l2cap_coc_connection_request.flags);
   printf("  uint8       encryption_key_size: 0x%02x\n",(int)evt->data.evt_l2cap_coc_connection_request.encryption_key_size);
    break;
  case gecko_evt_l2cap_coc_connection_response_id:
    dump_event_header("l2cap_coc_connection_response");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_l2cap_coc_connection_response.connection);
   printf("  uint16      destination_cid: 0x%04x\n",(int)evt->data.evt_l2cap_coc_connection_response.destination_cid);
   printf("  uint16      mtu: 0x%04x\n",(int)evt->data.evt_l2cap_coc_connection_response.mtu);
   printf("  uint16      mps: 0x%04x\n",(int)evt->data.evt_l2cap_coc_connection_response.mps);
   printf("  uint16      initial_credit: 0x%04x\n",(int)evt->data.evt_l2cap_coc_connection_response.initial_credit);
   printf("  uint16      result: 0x%04x\n",(int)evt->data.evt_l2cap_coc_connection_response.result);
    break;
  case gecko_evt_l2cap_coc_le_flow_control_credit_id:
    dump_event_header("l2cap_coc_le_flow_control_credit");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_l2cap_coc_le_flow_control_credit.connection);
   printf("  uint16      cid: 0x%04x\n",(int)evt->data.evt_l2cap_coc_le_flow_control_credit.cid);
   printf("  uint16      credits: 0x%04x\n",(int)evt->data.evt_l2cap_coc_le_flow_control_credit.credits);
    break;
  case gecko_evt_l2cap_coc_channel_disconnected_id:
    dump_event_header("l2cap_coc_channel_disconnected");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_l2cap_coc_channel_disconnected.connection);
   printf("  uint16      cid: 0x%04x\n",(int)evt->data.evt_l2cap_coc_channel_disconnected.cid);
   printf("  uint16      reason: 0x%04x\n",(int)evt->data.evt_l2cap_coc_channel_disconnected.reason);
    break;
  case gecko_evt_l2cap_coc_data_id:
    dump_event_header("l2cap_coc_data");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_l2cap_coc_data.connection);
   printf("  uint16      cid: 0x%04x\n",(int)evt->data.evt_l2cap_coc_data.cid);
   printf("  uint8array  data: %d:",(int)evt->data.evt_l2cap_coc_data.data.len);
   for(int i = 0; i < evt->data.evt_l2cap_coc_data.data.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_l2cap_coc_data.data.data[i]);
   printf("}\n");
    break;
  case gecko_evt_l2cap_command_rejected_id:
    dump_event_header("l2cap_command_rejected");
   printf("  uint8       connection: 0x%02x\n",(int)evt->data.evt_l2cap_command_rejected.connection);
   printf("  uint8       code: 0x%02x\n",(int)evt->data.evt_l2cap_command_rejected.code);
   printf("  uint16      reason: 0x%04x\n",(int)evt->data.evt_l2cap_command_rejected.reason);
    break;
  case gecko_evt_cte_receiver_iq_report_id:
    dump_event_header("cte_receiver_iq_report");
   printf("  uint16      status: 0x%04x\n",(int)evt->data.evt_cte_receiver_iq_report.status);
   printf("  uint8       packet_type: 0x%02x\n",(int)evt->data.evt_cte_receiver_iq_report.packet_type);
   printf("  uint8       handle: 0x%02x\n",(int)evt->data.evt_cte_receiver_iq_report.handle);
   printf("  uint8       phy: 0x%02x\n",(int)evt->data.evt_cte_receiver_iq_report.phy);
   printf("  uint8       channel: 0x%02x\n",(int)evt->data.evt_cte_receiver_iq_report.channel);
   printf("  int8        rssi: 0x%02x\n",(int)evt->data.evt_cte_receiver_iq_report.rssi);
   printf("  uint8       rssi_antenna_id: 0x%02x\n",(int)evt->data.evt_cte_receiver_iq_report.rssi_antenna_id);
   printf("  uint8       cte_type: 0x%02x\n",(int)evt->data.evt_cte_receiver_iq_report.cte_type);
   printf("  uint8       slot_durations: 0x%02x\n",(int)evt->data.evt_cte_receiver_iq_report.slot_durations);
   printf("  uint16      event_counter: 0x%04x\n",(int)evt->data.evt_cte_receiver_iq_report.event_counter);
   printf("  uint8array  samples: %d:",(int)evt->data.evt_cte_receiver_iq_report.samples.len);
   for(int i = 0; i < evt->data.evt_cte_receiver_iq_report.samples.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_cte_receiver_iq_report.samples.data[i]);
   printf("}\n");
    break;
  case gecko_evt_user_message_to_host_id:
    dump_event_header("user_message_to_host");
   printf("  uint8array  data: %d:",(int)evt->data.evt_user_message_to_host.data.len);
   for(int i = 0; i < evt->data.evt_user_message_to_host.data.len; i++)
      printf("%s%02x",(i)?",":"{",evt->data.evt_user_message_to_host.data.data[i]);
   printf("}\n");
    break;
  }
  dump_footer();
}
