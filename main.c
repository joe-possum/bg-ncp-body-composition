/***************************************************************************//**
 * @file
 * @brief main.c
 *******************************************************************************
 * # License
 * <b>Copyright 2018 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

/**
 * This an example application that demonstrates Bluetooth connectivity
 * using BGLIB C function definitions. The example enables Bluetooth advertisements
 * and connections.
 *
 * Most of the functionality in BGAPI uses a request-response-event pattern
 * where the module responds to a command with a command response indicating
 * it has processed the request and then later sending an event indicating
 * the requested operation has been completed. */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>

#include "infrastructure.h"

/* BG stack headers */
#include "gecko_bglib.h"

/* hardware specific headers */
#include "uart.h"

/* application specific files */
#include "app.h"

/***************************************************************************************************
 * Local Macros and Definitions
 **************************************************************************************************/

BGLIB_DEFINE();

/** The default baud rate to use. */
static uint32_t default_baud_rate = 115200;

/** The serial port to use for BGAPI communication. */
static char* uart_port = NULL;

/** The baud rate to use. */
static uint32_t baud_rate = 0;

/** Usage string */
#define USAGE "Usage: %s -p <serial port> [ -b <baud rate> ] [ -f flow control: 1(on, default) or 0(off) ]\n\n"

/***************************************************************************************************
 * Static Function Declarations
 **************************************************************************************************/

static int appSerialPortInit(int argc, char* argv[], int32_t timeout);
static void on_message_send(uint32_t msg_len, uint8_t* msg_data);

/***************************************************************************************************
 * Public Function Definitions
 **************************************************************************************************/

/***********************************************************************************************//**
 *  \brief  The main program.
 *  \param[in] argc Argument count.
 *  \param[in] argv Buffer contaning Serial Port data.
 *  \return  0 on success, -1 on failure.
 **************************************************************************************************/
int main(int argc, char* argv[])
{
  struct gecko_cmd_packet* evt;

  /* Initialize BGLIB with our output function for sending messages. */
  BGLIB_INITIALIZE_NONBLOCK(on_message_send, uartRx, uartRxPeek);

  /* Initialise serial communication as non-blocking. */
  if (appSerialPortInit(argc, argv, 100) < 0) {
    printf("Non-blocking serial port init failure\n");
    exit(EXIT_FAILURE);
  }

  // Flush std output
  fflush(stdout);

  printf("Starting up...\nResetting NCP target...\n");

  /* Reset NCP to ensure it gets into a defined state.
   * Once the chip successfully boots, gecko_evt_system_boot_id event should be received. */
  gecko_cmd_system_reset(0);

  while (1) {
    /* Check for stack event. */
    evt = gecko_peek_event();
    /* Run application and event handler. */
    appHandleEvents(evt);
  }

  return -1;
}

/***************************************************************************************************
 * Static Function Definitions
 **************************************************************************************************/

/***********************************************************************************************//**
 *  \brief  Function called when a message needs to be written to the serial port.
 *  \param[in] msg_len Length of the message.
 *  \param[in] msg_data Message data, including the header.
 **************************************************************************************************/
static void on_message_send(uint32_t msg_len, uint8_t* msg_data)
{
  /** Variable for storing function return values. */
  int32_t ret;

  ret = uartTx(msg_len, msg_data);
  if (ret < 0) {
    printf("Failed to write to serial port %s, ret: %d, errno: %d\n", uart_port, ret, errno);
    exit(EXIT_FAILURE);
  }
}

void help(char *const*argv) {
  fprintf(stderr, "Usage: %s -P port [ -B baudrate ] [ -F flowcontrol ] [ -H ]", argv[0]);
  const char *appOptions = getAppOptions();
  int n = strlen(appOptions);
  int state = 0;
  for(int i = 0; i < n; i++) {
    if(0 == state) {
      fprintf(stderr," [ -%c ",appOptions[i]);
      state = 1;
      continue;
    }
    if(1 == state) {
      if('<' == appOptions[i]) {
	fprintf(stderr,"<");
	state = 2;
	continue;
      }
      if(',' == appOptions[i]) {
	fprintf(stderr,">");
	state = 0;
	continue;
      }
      fprintf(stderr,"!!!-FAILURE-STATE-1-!!!\n");
      exit(1);
    }
    if(2 == state) {
      if(']' == appOptions[i]) {
	fprintf(stderr,"> ");
	state = 1;
	continue;
      }
      fprintf(stderr,"%c",appOptions[i]);
      continue;
    }
    fprintf(stderr,"!!!-FAILURE-STATE-%d-!!!\n",state);
    exit(1);
  }
  if(1 == state) {
    fprintf(stderr,"]\n");
  }
}

int optparse(const char *str,char *target) {
  int state = 0;
  int len = 0;
  int n = strlen(str);
  for(int i = 0; i < n; i++) {
    char ch = str[i];
    if((state == 0) && ('<' == ch)) {
      len++;
      if(target) *target++ = ':';
      state = 1;
      continue;
    }
    if((1 == state) && ('>' == ch)) {
      state = 0;
      continue;
    }
    if(0 == state) {
      len++;
      if(target) *target++ = ch;
    }
    if(('<' == ch) || ('>' == ch)) {
      fprintf(stderr,"illegal '%c' in state %d\n",ch,state);
      exit(1);
    }
  }
  if(state) {
    fprintf(stderr,"illegal end of string in state %d\n",state);
    exit(1);
  }
  if(target) *target = 0;
  return len;
}

int optstrlen(const char *str) {
  return optparse(str,NULL);
}

void optstrcpy(char *target, const char *str) {
  optparse(str,target);
}

/***********************************************************************************************//**
 *  \brief  Serial Port initialisation routine.
 *  \param[in] argc Argument count.
 *  \param[in] argv Buffer contaning Serial Port data.
 *  \return  0 on success, -1 on failure.
 **************************************************************************************************/
static int appSerialPortInit(int argc, char* argv[], int32_t timeout)
{
  uint32_t flowcontrol = 1;

  /**
   * Handle the command-line arguments.
   */

  const char* appOptions = getAppOptions();
  char options[8+optstrlen(appOptions)];
  strcpy(options,"B:P:F:H");
  optstrcpy(options+7,appOptions);
  printf("options: '%s'\n", options);
  baud_rate = default_baud_rate;
  int done = 0;
  while(!done) {
    int rc = getopt(argc,argv,options);
    switch(rc) {
    case 'B':
      baud_rate = atoi(optarg);
      break;
    case 'P':
      uart_port = optarg;
      break;
    case 'F':
      flowcontrol = atoi(optarg);
      break;
    case 'H':
      help(argv);
      exit(0);
    case -1:
      done = 1;
      break;
    default:
      if(strchr(appOptions,rc)) appOption(rc,optarg);
      else {
	fprintf(stderr,"Unknown option '%c'\n",rc);
	exit(1);
      }
    }
  }
  if (!uart_port || !baud_rate || (flowcontrol > 1)) {
    printf(USAGE, argv[0]);
    exit(EXIT_FAILURE);
  }

  /* Initialise the serial port with RTS/CTS enabled. */
  int rc = uartOpen((int8_t*)uart_port, baud_rate, flowcontrol, timeout);
  appInit();
  return rc;
}
