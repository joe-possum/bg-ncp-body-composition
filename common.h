/* BG stack headers */
#include "bg_types.h"

void parse_address(const char *fmt,bd_addr *address);
uint8_t ad_flags(uint8_t *buffer, uint8_t flags);
uint8_t ad_name(uint8_t *buffer, char *name);
uint8_t ad_manufacturer(uint8_t *buffer, uint8_t len, uint8_t *data);
int ad_match_local_name(uint8_t len, uint8_t *data, char *name);
uint8_t *ad_get_manufacturer(uint8_t len, uint8_t *data, uint8_t accept_len);
char *str_address(bd_addr addr);
