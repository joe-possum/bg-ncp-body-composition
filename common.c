#include "common.h"
#include <stdio.h>
#include <string.h>

void parse_address(const char *fmt,bd_addr *address) {
  char buf[3];
  int octet;
  for(uint8_t i = 0; i < 6; i++) {
    memcpy(buf,&fmt[3*i],2);
    buf[2] = 0;
    sscanf(buf,"%02x",&octet);
    address->addr[5-i] = octet;
  }
}

uint8_t ad_flags(uint8_t *buffer, uint8_t flags) {
  if(0 == flags) return 0;
  buffer[0] = 2;
  buffer[1] = 1;
  buffer[2] = flags;
  return 3;
}

uint8_t ad_name(uint8_t *buffer, char *name) {
  uint8_t len = strlen(name);
  buffer[0] = len + 1;
  buffer[1] = 9;
  memcpy(&buffer[2],&name[0],len);
  return len + 2;
}

uint8_t ad_manufacturer(uint8_t *buffer, uint8_t len, uint8_t *data) {
  buffer[0] = len + 1;
  buffer[1] = 0xff;
  memcpy(&buffer[2],data,len);
  return len + 2;
}

int ad_match_local_name(uint8_t len, uint8_t *data, char *name) {
  uint8_t *end = data + len;
  while(data < end) {
    uint8_t elen = *data++;
    uint8_t type = *data++;
    if(--elen == strlen(name) && (0x09 == type)) {
      if(!memcmp(data,name,elen)) return 1;
      break;
    }
    data  += elen;
  }
  return 0;
}

uint8_t *ad_get_manufacturer(uint8_t len, uint8_t *data, uint8_t accept_len) {
  uint8_t *end = data + len;
  while(data < end) {
    uint8_t elen = *data++;
    uint8_t type = *data++;
    if(--elen == accept_len && (0xff == type)) {
      return data;
    }
    data  += elen;
  }
  return 0;
}

char *str_address(bd_addr addr) {
  static char buf[19];
  for(int i = 0; i < 6; i++) {
    sprintf(&buf[3*i],"%02x:",addr.addr[5-i]);
  }
  buf[18] = 0;
  return buf;
}
