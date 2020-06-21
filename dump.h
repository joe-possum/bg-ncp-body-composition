#ifndef DUMP_H_
#define DUMP_H_
#define DUMP
#include "host_gecko.h"
#include <stdio.h>
extern void dump_event(struct gecko_cmd_packet *evt);
void dump_timestamp(int);
extern int dump_mode;
extern void dump_footer(void);
extern void dump_command_header(const char*);
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
static inline void dump_dfu_flash_set_address(struct gecko_msg_dfu_flash_set_address_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_dfu_flash_upload(struct gecko_msg_dfu_flash_upload_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_dfu_flash_upload_finish(struct gecko_msg_dfu_flash_upload_finish_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_system_hello(struct gecko_msg_system_hello_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_system_get_bt_address(struct gecko_msg_system_get_bt_address_rsp_t* resp) {
   printf("      bd_addr     address: ");
   for(int i = 0; i < 6; i++)
      printf("%s%02x",(i)?":":"",resp->address.addr[5-i]);
   printf("\n");
}
static inline void dump_system_set_bt_address(struct gecko_msg_system_set_bt_address_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_system_set_tx_power(struct gecko_msg_system_set_tx_power_rsp_t* resp) {
   printf("      int16 set_power: 0x%04x\n",(int)resp->set_power);
}
static inline void dump_system_get_random_data(struct gecko_msg_system_get_random_data_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint8array  data: %d:",(int)resp->data.len);
   for(int i = 0; i < resp->data.len; i++)
      printf("%s%02x",(i)?",":"{",resp->data.data[i]);
   printf("}\n");
}
static inline void dump_system_halt(struct gecko_msg_system_halt_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_system_set_device_name(struct gecko_msg_system_set_device_name_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_system_linklayer_configure(struct gecko_msg_system_linklayer_configure_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_system_get_counters(struct gecko_msg_system_get_counters_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint16      tx_packets: 0x%04x\n",(int)resp->tx_packets);
   printf("      uint16      rx_packets: 0x%04x\n",(int)resp->rx_packets);
   printf("      uint16      crc_errors: 0x%04x\n",(int)resp->crc_errors);
   printf("      uint16      failures: 0x%04x\n",(int)resp->failures);
}
static inline void dump_system_data_buffer_write(struct gecko_msg_system_data_buffer_write_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_system_set_identity_address(struct gecko_msg_system_set_identity_address_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_system_data_buffer_clear(struct gecko_msg_system_data_buffer_clear_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_open(struct gecko_msg_le_gap_open_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint8       connection: 0x%02x\n",(int)resp->connection);
}
static inline void dump_le_gap_set_mode(struct gecko_msg_le_gap_set_mode_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_discover(struct gecko_msg_le_gap_discover_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_end_procedure(struct gecko_msg_le_gap_end_procedure_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_set_adv_parameters(struct gecko_msg_le_gap_set_adv_parameters_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_set_conn_parameters(struct gecko_msg_le_gap_set_conn_parameters_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_set_scan_parameters(struct gecko_msg_le_gap_set_scan_parameters_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_set_adv_data(struct gecko_msg_le_gap_set_adv_data_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_set_adv_timeout(struct gecko_msg_le_gap_set_adv_timeout_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_set_conn_phy(struct gecko_msg_le_gap_set_conn_phy_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_bt5_set_mode(struct gecko_msg_le_gap_bt5_set_mode_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_bt5_set_adv_parameters(struct gecko_msg_le_gap_bt5_set_adv_parameters_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_bt5_set_adv_data(struct gecko_msg_le_gap_bt5_set_adv_data_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_set_privacy_mode(struct gecko_msg_le_gap_set_privacy_mode_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_set_advertise_timing(struct gecko_msg_le_gap_set_advertise_timing_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_set_advertise_channel_map(struct gecko_msg_le_gap_set_advertise_channel_map_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_set_advertise_report_scan_request(struct gecko_msg_le_gap_set_advertise_report_scan_request_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_set_advertise_phy(struct gecko_msg_le_gap_set_advertise_phy_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_set_advertise_configuration(struct gecko_msg_le_gap_set_advertise_configuration_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_clear_advertise_configuration(struct gecko_msg_le_gap_clear_advertise_configuration_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_start_advertising(struct gecko_msg_le_gap_start_advertising_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_stop_advertising(struct gecko_msg_le_gap_stop_advertising_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_set_discovery_timing(struct gecko_msg_le_gap_set_discovery_timing_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_set_discovery_type(struct gecko_msg_le_gap_set_discovery_type_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_start_discovery(struct gecko_msg_le_gap_start_discovery_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_set_data_channel_classification(struct gecko_msg_le_gap_set_data_channel_classification_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_connect(struct gecko_msg_le_gap_connect_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint8       connection: 0x%02x\n",(int)resp->connection);
}
static inline void dump_le_gap_set_advertise_tx_power(struct gecko_msg_le_gap_set_advertise_tx_power_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      int16 set_power: 0x%04x\n",(int)resp->set_power);
}
static inline void dump_le_gap_set_discovery_extended_scan_response(struct gecko_msg_le_gap_set_discovery_extended_scan_response_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_start_periodic_advertising(struct gecko_msg_le_gap_start_periodic_advertising_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_stop_periodic_advertising(struct gecko_msg_le_gap_stop_periodic_advertising_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_set_long_advertising_data(struct gecko_msg_le_gap_set_long_advertising_data_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_enable_whitelisting(struct gecko_msg_le_gap_enable_whitelisting_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_gap_set_conn_timing_parameters(struct gecko_msg_le_gap_set_conn_timing_parameters_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_sync_open(struct gecko_msg_sync_open_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint8       sync: 0x%02x\n",(int)resp->sync);
}
static inline void dump_sync_close(struct gecko_msg_sync_close_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_connection_set_parameters(struct gecko_msg_le_connection_set_parameters_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_connection_get_rssi(struct gecko_msg_le_connection_get_rssi_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_connection_disable_slave_latency(struct gecko_msg_le_connection_disable_slave_latency_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_connection_set_phy(struct gecko_msg_le_connection_set_phy_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_connection_close(struct gecko_msg_le_connection_close_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_connection_set_timing_parameters(struct gecko_msg_le_connection_set_timing_parameters_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_le_connection_set_preferred_phy(struct gecko_msg_le_connection_set_preferred_phy_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_gatt_set_max_mtu(struct gecko_msg_gatt_set_max_mtu_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint16      max_mtu: 0x%04x\n",(int)resp->max_mtu);
}
static inline void dump_gatt_discover_primary_services(struct gecko_msg_gatt_discover_primary_services_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_gatt_discover_primary_services_by_uuid(struct gecko_msg_gatt_discover_primary_services_by_uuid_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_gatt_discover_characteristics(struct gecko_msg_gatt_discover_characteristics_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_gatt_discover_characteristics_by_uuid(struct gecko_msg_gatt_discover_characteristics_by_uuid_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_gatt_set_characteristic_notification(struct gecko_msg_gatt_set_characteristic_notification_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_gatt_discover_descriptors(struct gecko_msg_gatt_discover_descriptors_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_gatt_read_characteristic_value(struct gecko_msg_gatt_read_characteristic_value_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_gatt_read_characteristic_value_by_uuid(struct gecko_msg_gatt_read_characteristic_value_by_uuid_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_gatt_write_characteristic_value(struct gecko_msg_gatt_write_characteristic_value_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_gatt_write_characteristic_value_without_response(struct gecko_msg_gatt_write_characteristic_value_without_response_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint16      sent_len: 0x%04x\n",(int)resp->sent_len);
}
static inline void dump_gatt_prepare_characteristic_value_write(struct gecko_msg_gatt_prepare_characteristic_value_write_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint16      sent_len: 0x%04x\n",(int)resp->sent_len);
}
static inline void dump_gatt_execute_characteristic_value_write(struct gecko_msg_gatt_execute_characteristic_value_write_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_gatt_send_characteristic_confirmation(struct gecko_msg_gatt_send_characteristic_confirmation_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_gatt_read_descriptor_value(struct gecko_msg_gatt_read_descriptor_value_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_gatt_write_descriptor_value(struct gecko_msg_gatt_write_descriptor_value_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_gatt_find_included_services(struct gecko_msg_gatt_find_included_services_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_gatt_read_multiple_characteristic_values(struct gecko_msg_gatt_read_multiple_characteristic_values_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_gatt_read_characteristic_value_from_offset(struct gecko_msg_gatt_read_characteristic_value_from_offset_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_gatt_prepare_characteristic_value_reliable_write(struct gecko_msg_gatt_prepare_characteristic_value_reliable_write_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint16      sent_len: 0x%04x\n",(int)resp->sent_len);
}
static inline void dump_gatt_server_read_attribute_value(struct gecko_msg_gatt_server_read_attribute_value_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint8array  value: %d:",(int)resp->value.len);
   for(int i = 0; i < resp->value.len; i++)
      printf("%s%02x",(i)?",":"{",resp->value.data[i]);
   printf("}\n");
}
static inline void dump_gatt_server_read_attribute_type(struct gecko_msg_gatt_server_read_attribute_type_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint8array  type: %d:",(int)resp->type.len);
   for(int i = 0; i < resp->type.len; i++)
      printf("%s%02x",(i)?",":"{",resp->type.data[i]);
   printf("}\n");
}
static inline void dump_gatt_server_write_attribute_value(struct gecko_msg_gatt_server_write_attribute_value_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_gatt_server_send_user_read_response(struct gecko_msg_gatt_server_send_user_read_response_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint16      sent_len: 0x%04x\n",(int)resp->sent_len);
}
static inline void dump_gatt_server_send_user_write_response(struct gecko_msg_gatt_server_send_user_write_response_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_gatt_server_send_characteristic_notification(struct gecko_msg_gatt_server_send_characteristic_notification_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint16      sent_len: 0x%04x\n",(int)resp->sent_len);
}
static inline void dump_gatt_server_find_attribute(struct gecko_msg_gatt_server_find_attribute_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint16      attribute: 0x%04x\n",(int)resp->attribute);
}
static inline void dump_gatt_server_set_capabilities(struct gecko_msg_gatt_server_set_capabilities_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_gatt_server_set_max_mtu(struct gecko_msg_gatt_server_set_max_mtu_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint16      max_mtu: 0x%04x\n",(int)resp->max_mtu);
}
static inline void dump_hardware_set_soft_timer(struct gecko_msg_hardware_set_soft_timer_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_hardware_get_time(struct gecko_msg_hardware_get_time_rsp_t* resp) {
   printf("      uint32      seconds: 0x%08x\n",(int)resp->seconds);
   printf("      uint16      ticks: 0x%04x\n",(int)resp->ticks);
}
static inline void dump_hardware_set_lazy_soft_timer(struct gecko_msg_hardware_set_lazy_soft_timer_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_flash_ps_erase_all(struct gecko_msg_flash_ps_erase_all_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_flash_ps_save(struct gecko_msg_flash_ps_save_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_flash_ps_load(struct gecko_msg_flash_ps_load_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint8array  value: %d:",(int)resp->value.len);
   for(int i = 0; i < resp->value.len; i++)
      printf("%s%02x",(i)?",":"{",resp->value.data[i]);
   printf("}\n");
}
static inline void dump_flash_ps_erase(struct gecko_msg_flash_ps_erase_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_test_dtm_tx(struct gecko_msg_test_dtm_tx_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_test_dtm_rx(struct gecko_msg_test_dtm_rx_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_test_dtm_end(struct gecko_msg_test_dtm_end_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_sm_set_bondable_mode(struct gecko_msg_sm_set_bondable_mode_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_sm_configure(struct gecko_msg_sm_configure_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_sm_store_bonding_configuration(struct gecko_msg_sm_store_bonding_configuration_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_sm_increase_security(struct gecko_msg_sm_increase_security_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_sm_delete_bonding(struct gecko_msg_sm_delete_bonding_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_sm_delete_bondings(struct gecko_msg_sm_delete_bondings_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_sm_enter_passkey(struct gecko_msg_sm_enter_passkey_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_sm_passkey_confirm(struct gecko_msg_sm_passkey_confirm_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_sm_set_oob_data(struct gecko_msg_sm_set_oob_data_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_sm_list_all_bondings(struct gecko_msg_sm_list_all_bondings_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_sm_bonding_confirm(struct gecko_msg_sm_bonding_confirm_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_sm_set_debug_mode(struct gecko_msg_sm_set_debug_mode_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_sm_set_passkey(struct gecko_msg_sm_set_passkey_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_sm_use_sc_oob(struct gecko_msg_sm_use_sc_oob_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint8array  oob_data: %d:",(int)resp->oob_data.len);
   for(int i = 0; i < resp->oob_data.len; i++)
      printf("%s%02x",(i)?",":"{",resp->oob_data.data[i]);
   printf("}\n");
}
static inline void dump_sm_set_sc_remote_oob_data(struct gecko_msg_sm_set_sc_remote_oob_data_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_sm_add_to_whitelist(struct gecko_msg_sm_add_to_whitelist_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_sm_set_minimum_key_size(struct gecko_msg_sm_set_minimum_key_size_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_homekit_configure(struct gecko_msg_homekit_configure_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_homekit_advertise(struct gecko_msg_homekit_advertise_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_homekit_delete_pairings(struct gecko_msg_homekit_delete_pairings_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_homekit_check_authcp(struct gecko_msg_homekit_check_authcp_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_homekit_get_pairing_id(struct gecko_msg_homekit_get_pairing_id_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint8array  pairing_id: %d:",(int)resp->pairing_id.len);
   for(int i = 0; i < resp->pairing_id.len; i++)
      printf("%s%02x",(i)?",":"{",resp->pairing_id.data[i]);
   printf("}\n");
}
static inline void dump_homekit_send_write_response(struct gecko_msg_homekit_send_write_response_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_homekit_send_read_response(struct gecko_msg_homekit_send_read_response_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_homekit_gsn_action(struct gecko_msg_homekit_gsn_action_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_homekit_event_notification(struct gecko_msg_homekit_event_notification_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_homekit_broadcast_action(struct gecko_msg_homekit_broadcast_action_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_coex_set_options(struct gecko_msg_coex_set_options_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_coex_get_counters(struct gecko_msg_coex_get_counters_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint8array  counters: %d:",(int)resp->counters.len);
   for(int i = 0; i < resp->counters.len; i++)
      printf("%s%02x",(i)?",":"{",resp->counters.data[i]);
   printf("}\n");
}
static inline void dump_l2cap_coc_send_connection_request(struct gecko_msg_l2cap_coc_send_connection_request_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_l2cap_coc_send_connection_response(struct gecko_msg_l2cap_coc_send_connection_response_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_l2cap_coc_send_le_flow_control_credit(struct gecko_msg_l2cap_coc_send_le_flow_control_credit_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_l2cap_coc_send_disconnection_request(struct gecko_msg_l2cap_coc_send_disconnection_request_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_l2cap_coc_send_data(struct gecko_msg_l2cap_coc_send_data_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_cte_transmitter_enable_cte_response(struct gecko_msg_cte_transmitter_enable_cte_response_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_cte_transmitter_disable_cte_response(struct gecko_msg_cte_transmitter_disable_cte_response_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_cte_transmitter_start_connectionless_cte(struct gecko_msg_cte_transmitter_start_connectionless_cte_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_cte_transmitter_stop_connectionless_cte(struct gecko_msg_cte_transmitter_stop_connectionless_cte_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_cte_transmitter_set_dtm_parameters(struct gecko_msg_cte_transmitter_set_dtm_parameters_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_cte_transmitter_clear_dtm_parameters(struct gecko_msg_cte_transmitter_clear_dtm_parameters_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_cte_receiver_configure(struct gecko_msg_cte_receiver_configure_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_cte_receiver_start_iq_sampling(struct gecko_msg_cte_receiver_start_iq_sampling_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_cte_receiver_stop_iq_sampling(struct gecko_msg_cte_receiver_stop_iq_sampling_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_cte_receiver_start_connectionless_iq_sampling(struct gecko_msg_cte_receiver_start_connectionless_iq_sampling_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_cte_receiver_stop_connectionless_iq_sampling(struct gecko_msg_cte_receiver_stop_connectionless_iq_sampling_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_cte_receiver_set_dtm_parameters(struct gecko_msg_cte_receiver_set_dtm_parameters_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_cte_receiver_clear_dtm_parameters(struct gecko_msg_cte_receiver_clear_dtm_parameters_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
}
static inline void dump_user_message_to_target(struct gecko_msg_user_message_to_target_rsp_t* resp) {
   printf("      uint16      result: 0x%04x\n",(int)resp->result);
   printf("      uint8array  data: %d:",(int)resp->data.len);
   for(int i = 0; i < resp->data.len; i++)
      printf("%s%02x",(i)?",":"{",resp->data.data[i]);
   printf("}\n");
}
static inline struct gecko_msg_dfu_flash_set_address_rsp_t* cmd_dfu_flash_set_address(uint32 address) {
  dump_command_header("dfu_flash_set_address");
  printf("  uint32 address: 0x%04x\n",(int)address);
  struct gecko_msg_dfu_flash_set_address_rsp_t* resp = gecko_cmd_dfu_flash_set_address(address);
  printf("    RETURNED\n");
  dump_dfu_flash_set_address(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_dfu_flash_upload_rsp_t* cmd_dfu_flash_upload(uint8 data_len, const uint8* data_data) {
  dump_command_header("dfu_flash_upload");
  printf("  uint8 data_len: 0x%02x\n",(int)data_len);
  printf("  const uint8* data_data: 0x%p\n",data_data);
  struct gecko_msg_dfu_flash_upload_rsp_t* resp = gecko_cmd_dfu_flash_upload(data_len,data_data);
  printf("    RETURNED\n");
  dump_dfu_flash_upload(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_dfu_flash_upload_finish_rsp_t* cmd_dfu_flash_upload_finish() {
  dump_command_header("dfu_flash_upload_finish");
  struct gecko_msg_dfu_flash_upload_finish_rsp_t* resp = gecko_cmd_dfu_flash_upload_finish();
  printf("    RETURNED\n");
  dump_dfu_flash_upload_finish(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_system_hello_rsp_t* cmd_system_hello() {
  dump_command_header("system_hello");
  struct gecko_msg_system_hello_rsp_t* resp = gecko_cmd_system_hello();
  printf("    RETURNED\n");
  dump_system_hello(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_system_get_bt_address_rsp_t* cmd_system_get_bt_address() {
  dump_command_header("system_get_bt_address");
  struct gecko_msg_system_get_bt_address_rsp_t* resp = gecko_cmd_system_get_bt_address();
  printf("    RETURNED\n");
  dump_system_get_bt_address(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_system_set_bt_address_rsp_t* cmd_system_set_bt_address(bd_addr address) {
  dump_command_header("system_set_bt_address");
  printf("  bd_addr address: ");
   for(int i = 0; i < 6; i++)
      printf("%s%02x",(i)?":":"",address.addr[5-i]);
   printf("\n");
  struct gecko_msg_system_set_bt_address_rsp_t* resp = gecko_cmd_system_set_bt_address(address);
  printf("    RETURNED\n");
  dump_system_set_bt_address(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_system_set_tx_power_rsp_t* cmd_system_set_tx_power(int16 power) {
  dump_command_header("system_set_tx_power");
  printf("  int16 power: 0x%04x\n",(int)power);
  struct gecko_msg_system_set_tx_power_rsp_t* resp = gecko_cmd_system_set_tx_power(power);
  printf("    RETURNED\n");
  dump_system_set_tx_power(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_system_get_random_data_rsp_t* cmd_system_get_random_data(uint8 length) {
  dump_command_header("system_get_random_data");
  printf("  uint8 length: 0x%02x\n",(int)length);
  struct gecko_msg_system_get_random_data_rsp_t* resp = gecko_cmd_system_get_random_data(length);
  printf("    RETURNED\n");
  dump_system_get_random_data(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_system_halt_rsp_t* cmd_system_halt(uint8 halt) {
  dump_command_header("system_halt");
  printf("  uint8 halt: 0x%02x\n",(int)halt);
  struct gecko_msg_system_halt_rsp_t* resp = gecko_cmd_system_halt(halt);
  printf("    RETURNED\n");
  dump_system_halt(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_system_set_device_name_rsp_t* cmd_system_set_device_name(uint8 type,uint8 name_len, const uint8* name_data) {
  dump_command_header("system_set_device_name");
  printf("  uint8 type: 0x%02x\n",(int)type);
  printf("  uint8 name_len: 0x%02x\n",(int)name_len);
  printf("  const uint8* name_data: 0x%p\n",name_data);
  struct gecko_msg_system_set_device_name_rsp_t* resp = gecko_cmd_system_set_device_name(type,name_len,name_data);
  printf("    RETURNED\n");
  dump_system_set_device_name(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_system_linklayer_configure_rsp_t* cmd_system_linklayer_configure(uint8 key,uint8 data_len, const uint8* data_data) {
  dump_command_header("system_linklayer_configure");
  printf("  uint8 key: 0x%02x\n",(int)key);
  printf("  uint8 data_len: 0x%02x\n",(int)data_len);
  printf("  const uint8* data_data: 0x%p\n",data_data);
  struct gecko_msg_system_linklayer_configure_rsp_t* resp = gecko_cmd_system_linklayer_configure(key,data_len,data_data);
  printf("    RETURNED\n");
  dump_system_linklayer_configure(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_system_get_counters_rsp_t* cmd_system_get_counters(uint8 reset) {
  dump_command_header("system_get_counters");
  printf("  uint8 reset: 0x%02x\n",(int)reset);
  struct gecko_msg_system_get_counters_rsp_t* resp = gecko_cmd_system_get_counters(reset);
  printf("    RETURNED\n");
  dump_system_get_counters(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_system_data_buffer_write_rsp_t* cmd_system_data_buffer_write(uint8 data_len, const uint8* data_data) {
  dump_command_header("system_data_buffer_write");
  printf("  uint8 data_len: 0x%02x\n",(int)data_len);
  printf("  const uint8* data_data: 0x%p\n",data_data);
  struct gecko_msg_system_data_buffer_write_rsp_t* resp = gecko_cmd_system_data_buffer_write(data_len,data_data);
  printf("    RETURNED\n");
  dump_system_data_buffer_write(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_system_set_identity_address_rsp_t* cmd_system_set_identity_address(bd_addr address,uint8 type) {
  dump_command_header("system_set_identity_address");
  printf("  bd_addr address: ");
   for(int i = 0; i < 6; i++)
      printf("%s%02x",(i)?":":"",address.addr[5-i]);
   printf("\n");
  printf("  uint8 type: 0x%02x\n",(int)type);
  struct gecko_msg_system_set_identity_address_rsp_t* resp = gecko_cmd_system_set_identity_address(address,type);
  printf("    RETURNED\n");
  dump_system_set_identity_address(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_system_data_buffer_clear_rsp_t* cmd_system_data_buffer_clear() {
  dump_command_header("system_data_buffer_clear");
  struct gecko_msg_system_data_buffer_clear_rsp_t* resp = gecko_cmd_system_data_buffer_clear();
  printf("    RETURNED\n");
  dump_system_data_buffer_clear(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_open_rsp_t* cmd_le_gap_open(bd_addr address,uint8 address_type) {
  dump_command_header("le_gap_open");
  printf("  bd_addr address: ");
   for(int i = 0; i < 6; i++)
      printf("%s%02x",(i)?":":"",address.addr[5-i]);
   printf("\n");
  printf("  uint8 address_type: 0x%02x\n",(int)address_type);
  struct gecko_msg_le_gap_open_rsp_t* resp = gecko_cmd_le_gap_open(address,address_type);
  printf("    RETURNED\n");
  dump_le_gap_open(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_set_mode_rsp_t* cmd_le_gap_set_mode(uint8 discover,uint8 connect) {
  dump_command_header("le_gap_set_mode");
  printf("  uint8 discover: 0x%02x\n",(int)discover);
  printf("  uint8 connect: 0x%02x\n",(int)connect);
  struct gecko_msg_le_gap_set_mode_rsp_t* resp = gecko_cmd_le_gap_set_mode(discover,connect);
  printf("    RETURNED\n");
  dump_le_gap_set_mode(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_discover_rsp_t* cmd_le_gap_discover(uint8 mode) {
  dump_command_header("le_gap_discover");
  printf("  uint8 mode: 0x%02x\n",(int)mode);
  struct gecko_msg_le_gap_discover_rsp_t* resp = gecko_cmd_le_gap_discover(mode);
  printf("    RETURNED\n");
  dump_le_gap_discover(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_end_procedure_rsp_t* cmd_le_gap_end_procedure() {
  dump_command_header("le_gap_end_procedure");
  struct gecko_msg_le_gap_end_procedure_rsp_t* resp = gecko_cmd_le_gap_end_procedure();
  printf("    RETURNED\n");
  dump_le_gap_end_procedure(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_set_adv_parameters_rsp_t* cmd_le_gap_set_adv_parameters(uint16 interval_min,uint16 interval_max,uint8 channel_map) {
  dump_command_header("le_gap_set_adv_parameters");
  printf("  uint16 interval_min: 0x%04x\n",(int)interval_min);
  printf("  uint16 interval_max: 0x%04x\n",(int)interval_max);
  printf("  uint8 channel_map: 0x%02x\n",(int)channel_map);
  struct gecko_msg_le_gap_set_adv_parameters_rsp_t* resp = gecko_cmd_le_gap_set_adv_parameters(interval_min,interval_max,channel_map);
  printf("    RETURNED\n");
  dump_le_gap_set_adv_parameters(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_set_conn_parameters_rsp_t* cmd_le_gap_set_conn_parameters(uint16 min_interval,uint16 max_interval,uint16 latency,uint16 timeout) {
  dump_command_header("le_gap_set_conn_parameters");
  printf("  uint16 min_interval: 0x%04x\n",(int)min_interval);
  printf("  uint16 max_interval: 0x%04x\n",(int)max_interval);
  printf("  uint16 latency: 0x%04x\n",(int)latency);
  printf("  uint16 timeout: 0x%04x\n",(int)timeout);
  struct gecko_msg_le_gap_set_conn_parameters_rsp_t* resp = gecko_cmd_le_gap_set_conn_parameters(min_interval,max_interval,latency,timeout);
  printf("    RETURNED\n");
  dump_le_gap_set_conn_parameters(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_set_scan_parameters_rsp_t* cmd_le_gap_set_scan_parameters(uint16 scan_interval,uint16 scan_window,uint8 active) {
  dump_command_header("le_gap_set_scan_parameters");
  printf("  uint16 scan_interval: 0x%04x\n",(int)scan_interval);
  printf("  uint16 scan_window: 0x%04x\n",(int)scan_window);
  printf("  uint8 active: 0x%02x\n",(int)active);
  struct gecko_msg_le_gap_set_scan_parameters_rsp_t* resp = gecko_cmd_le_gap_set_scan_parameters(scan_interval,scan_window,active);
  printf("    RETURNED\n");
  dump_le_gap_set_scan_parameters(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_set_adv_data_rsp_t* cmd_le_gap_set_adv_data(uint8 scan_rsp,uint8 adv_data_len, const uint8* adv_data_data) {
  dump_command_header("le_gap_set_adv_data");
  printf("  uint8 scan_rsp: 0x%02x\n",(int)scan_rsp);
  printf("  uint8 adv_data_len: 0x%02x\n",(int)adv_data_len);
  printf("  const uint8* adv_data_data: 0x%p\n",adv_data_data);
  struct gecko_msg_le_gap_set_adv_data_rsp_t* resp = gecko_cmd_le_gap_set_adv_data(scan_rsp,adv_data_len,adv_data_data);
  printf("    RETURNED\n");
  dump_le_gap_set_adv_data(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_set_adv_timeout_rsp_t* cmd_le_gap_set_adv_timeout(uint8 maxevents) {
  dump_command_header("le_gap_set_adv_timeout");
  printf("  uint8 maxevents: 0x%02x\n",(int)maxevents);
  struct gecko_msg_le_gap_set_adv_timeout_rsp_t* resp = gecko_cmd_le_gap_set_adv_timeout(maxevents);
  printf("    RETURNED\n");
  dump_le_gap_set_adv_timeout(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_set_conn_phy_rsp_t* cmd_le_gap_set_conn_phy(uint8 preferred_phy,uint8 accepted_phy) {
  dump_command_header("le_gap_set_conn_phy");
  printf("  uint8 preferred_phy: 0x%02x\n",(int)preferred_phy);
  printf("  uint8 accepted_phy: 0x%02x\n",(int)accepted_phy);
  struct gecko_msg_le_gap_set_conn_phy_rsp_t* resp = gecko_cmd_le_gap_set_conn_phy(preferred_phy,accepted_phy);
  printf("    RETURNED\n");
  dump_le_gap_set_conn_phy(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_bt5_set_mode_rsp_t* cmd_le_gap_bt5_set_mode(uint8 handle,uint8 discover,uint8 connect,uint16 maxevents,uint8 address_type) {
  dump_command_header("le_gap_bt5_set_mode");
  printf("  uint8 handle: 0x%02x\n",(int)handle);
  printf("  uint8 discover: 0x%02x\n",(int)discover);
  printf("  uint8 connect: 0x%02x\n",(int)connect);
  printf("  uint16 maxevents: 0x%04x\n",(int)maxevents);
  printf("  uint8 address_type: 0x%02x\n",(int)address_type);
  struct gecko_msg_le_gap_bt5_set_mode_rsp_t* resp = gecko_cmd_le_gap_bt5_set_mode(handle,discover,connect,maxevents,address_type);
  printf("    RETURNED\n");
  dump_le_gap_bt5_set_mode(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_bt5_set_adv_parameters_rsp_t* cmd_le_gap_bt5_set_adv_parameters(uint8 handle,uint16 interval_min,uint16 interval_max,uint8 channel_map,uint8 report_scan) {
  dump_command_header("le_gap_bt5_set_adv_parameters");
  printf("  uint8 handle: 0x%02x\n",(int)handle);
  printf("  uint16 interval_min: 0x%04x\n",(int)interval_min);
  printf("  uint16 interval_max: 0x%04x\n",(int)interval_max);
  printf("  uint8 channel_map: 0x%02x\n",(int)channel_map);
  printf("  uint8 report_scan: 0x%02x\n",(int)report_scan);
  struct gecko_msg_le_gap_bt5_set_adv_parameters_rsp_t* resp = gecko_cmd_le_gap_bt5_set_adv_parameters(handle,interval_min,interval_max,channel_map,report_scan);
  printf("    RETURNED\n");
  dump_le_gap_bt5_set_adv_parameters(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_bt5_set_adv_data_rsp_t* cmd_le_gap_bt5_set_adv_data(uint8 handle,uint8 scan_rsp,uint8 adv_data_len, const uint8* adv_data_data) {
  dump_command_header("le_gap_bt5_set_adv_data");
  printf("  uint8 handle: 0x%02x\n",(int)handle);
  printf("  uint8 scan_rsp: 0x%02x\n",(int)scan_rsp);
  printf("  uint8 adv_data_len: 0x%02x\n",(int)adv_data_len);
  printf("  const uint8* adv_data_data: 0x%p\n",adv_data_data);
  struct gecko_msg_le_gap_bt5_set_adv_data_rsp_t* resp = gecko_cmd_le_gap_bt5_set_adv_data(handle,scan_rsp,adv_data_len,adv_data_data);
  printf("    RETURNED\n");
  dump_le_gap_bt5_set_adv_data(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_set_privacy_mode_rsp_t* cmd_le_gap_set_privacy_mode(uint8 privacy,uint8 interval) {
  dump_command_header("le_gap_set_privacy_mode");
  printf("  uint8 privacy: 0x%02x\n",(int)privacy);
  printf("  uint8 interval: 0x%02x\n",(int)interval);
  struct gecko_msg_le_gap_set_privacy_mode_rsp_t* resp = gecko_cmd_le_gap_set_privacy_mode(privacy,interval);
  printf("    RETURNED\n");
  dump_le_gap_set_privacy_mode(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_set_advertise_timing_rsp_t* cmd_le_gap_set_advertise_timing(uint8 handle,uint32 interval_min,uint32 interval_max,uint16 duration,uint8 maxevents) {
  dump_command_header("le_gap_set_advertise_timing");
  printf("  uint8 handle: 0x%02x\n",(int)handle);
  printf("  uint32 interval_min: 0x%04x\n",(int)interval_min);
  printf("  uint32 interval_max: 0x%04x\n",(int)interval_max);
  printf("  uint16 duration: 0x%04x\n",(int)duration);
  printf("  uint8 maxevents: 0x%02x\n",(int)maxevents);
  struct gecko_msg_le_gap_set_advertise_timing_rsp_t* resp = gecko_cmd_le_gap_set_advertise_timing(handle,interval_min,interval_max,duration,maxevents);
  printf("    RETURNED\n");
  dump_le_gap_set_advertise_timing(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_set_advertise_channel_map_rsp_t* cmd_le_gap_set_advertise_channel_map(uint8 handle,uint8 channel_map) {
  dump_command_header("le_gap_set_advertise_channel_map");
  printf("  uint8 handle: 0x%02x\n",(int)handle);
  printf("  uint8 channel_map: 0x%02x\n",(int)channel_map);
  struct gecko_msg_le_gap_set_advertise_channel_map_rsp_t* resp = gecko_cmd_le_gap_set_advertise_channel_map(handle,channel_map);
  printf("    RETURNED\n");
  dump_le_gap_set_advertise_channel_map(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_set_advertise_report_scan_request_rsp_t* cmd_le_gap_set_advertise_report_scan_request(uint8 handle,uint8 report_scan_req) {
  dump_command_header("le_gap_set_advertise_report_scan_request");
  printf("  uint8 handle: 0x%02x\n",(int)handle);
  printf("  uint8 report_scan_req: 0x%02x\n",(int)report_scan_req);
  struct gecko_msg_le_gap_set_advertise_report_scan_request_rsp_t* resp = gecko_cmd_le_gap_set_advertise_report_scan_request(handle,report_scan_req);
  printf("    RETURNED\n");
  dump_le_gap_set_advertise_report_scan_request(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_set_advertise_phy_rsp_t* cmd_le_gap_set_advertise_phy(uint8 handle,uint8 primary_phy,uint8 secondary_phy) {
  dump_command_header("le_gap_set_advertise_phy");
  printf("  uint8 handle: 0x%02x\n",(int)handle);
  printf("  uint8 primary_phy: 0x%02x\n",(int)primary_phy);
  printf("  uint8 secondary_phy: 0x%02x\n",(int)secondary_phy);
  struct gecko_msg_le_gap_set_advertise_phy_rsp_t* resp = gecko_cmd_le_gap_set_advertise_phy(handle,primary_phy,secondary_phy);
  printf("    RETURNED\n");
  dump_le_gap_set_advertise_phy(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_set_advertise_configuration_rsp_t* cmd_le_gap_set_advertise_configuration(uint8 handle,uint32 configurations) {
  dump_command_header("le_gap_set_advertise_configuration");
  printf("  uint8 handle: 0x%02x\n",(int)handle);
  printf("  uint32 configurations: 0x%04x\n",(int)configurations);
  struct gecko_msg_le_gap_set_advertise_configuration_rsp_t* resp = gecko_cmd_le_gap_set_advertise_configuration(handle,configurations);
  printf("    RETURNED\n");
  dump_le_gap_set_advertise_configuration(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_clear_advertise_configuration_rsp_t* cmd_le_gap_clear_advertise_configuration(uint8 handle,uint32 configurations) {
  dump_command_header("le_gap_clear_advertise_configuration");
  printf("  uint8 handle: 0x%02x\n",(int)handle);
  printf("  uint32 configurations: 0x%04x\n",(int)configurations);
  struct gecko_msg_le_gap_clear_advertise_configuration_rsp_t* resp = gecko_cmd_le_gap_clear_advertise_configuration(handle,configurations);
  printf("    RETURNED\n");
  dump_le_gap_clear_advertise_configuration(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_start_advertising_rsp_t* cmd_le_gap_start_advertising(uint8 handle,uint8 discover,uint8 connect) {
  dump_command_header("le_gap_start_advertising");
  printf("  uint8 handle: 0x%02x\n",(int)handle);
  printf("  uint8 discover: 0x%02x\n",(int)discover);
  printf("  uint8 connect: 0x%02x\n",(int)connect);
  struct gecko_msg_le_gap_start_advertising_rsp_t* resp = gecko_cmd_le_gap_start_advertising(handle,discover,connect);
  printf("    RETURNED\n");
  dump_le_gap_start_advertising(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_stop_advertising_rsp_t* cmd_le_gap_stop_advertising(uint8 handle) {
  dump_command_header("le_gap_stop_advertising");
  printf("  uint8 handle: 0x%02x\n",(int)handle);
  struct gecko_msg_le_gap_stop_advertising_rsp_t* resp = gecko_cmd_le_gap_stop_advertising(handle);
  printf("    RETURNED\n");
  dump_le_gap_stop_advertising(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_set_discovery_timing_rsp_t* cmd_le_gap_set_discovery_timing(uint8 phys,uint16 scan_interval,uint16 scan_window) {
  dump_command_header("le_gap_set_discovery_timing");
  printf("  uint8 phys: 0x%02x\n",(int)phys);
  printf("  uint16 scan_interval: 0x%04x\n",(int)scan_interval);
  printf("  uint16 scan_window: 0x%04x\n",(int)scan_window);
  struct gecko_msg_le_gap_set_discovery_timing_rsp_t* resp = gecko_cmd_le_gap_set_discovery_timing(phys,scan_interval,scan_window);
  printf("    RETURNED\n");
  dump_le_gap_set_discovery_timing(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_set_discovery_type_rsp_t* cmd_le_gap_set_discovery_type(uint8 phys,uint8 scan_type) {
  dump_command_header("le_gap_set_discovery_type");
  printf("  uint8 phys: 0x%02x\n",(int)phys);
  printf("  uint8 scan_type: 0x%02x\n",(int)scan_type);
  struct gecko_msg_le_gap_set_discovery_type_rsp_t* resp = gecko_cmd_le_gap_set_discovery_type(phys,scan_type);
  printf("    RETURNED\n");
  dump_le_gap_set_discovery_type(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_start_discovery_rsp_t* cmd_le_gap_start_discovery(uint8 scanning_phy,uint8 mode) {
  dump_command_header("le_gap_start_discovery");
  printf("  uint8 scanning_phy: 0x%02x\n",(int)scanning_phy);
  printf("  uint8 mode: 0x%02x\n",(int)mode);
  struct gecko_msg_le_gap_start_discovery_rsp_t* resp = gecko_cmd_le_gap_start_discovery(scanning_phy,mode);
  printf("    RETURNED\n");
  dump_le_gap_start_discovery(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_set_data_channel_classification_rsp_t* cmd_le_gap_set_data_channel_classification(uint8 channel_map_len, const uint8* channel_map_data) {
  dump_command_header("le_gap_set_data_channel_classification");
  printf("  uint8 channel_map_len: 0x%02x\n",(int)channel_map_len);
  printf("  const uint8* channel_map_data: 0x%p\n",channel_map_data);
  struct gecko_msg_le_gap_set_data_channel_classification_rsp_t* resp = gecko_cmd_le_gap_set_data_channel_classification(channel_map_len,channel_map_data);
  printf("    RETURNED\n");
  dump_le_gap_set_data_channel_classification(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_connect_rsp_t* cmd_le_gap_connect(bd_addr address,uint8 address_type,uint8 initiating_phy) {
  dump_command_header("le_gap_connect");
  printf("  bd_addr address: ");
   for(int i = 0; i < 6; i++)
      printf("%s%02x",(i)?":":"",address.addr[5-i]);
   printf("\n");
  printf("  uint8 address_type: 0x%02x\n",(int)address_type);
  printf("  uint8 initiating_phy: 0x%02x\n",(int)initiating_phy);
  struct gecko_msg_le_gap_connect_rsp_t* resp = gecko_cmd_le_gap_connect(address,address_type,initiating_phy);
  printf("    RETURNED\n");
  dump_le_gap_connect(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_set_advertise_tx_power_rsp_t* cmd_le_gap_set_advertise_tx_power(uint8 handle,int16 power) {
  dump_command_header("le_gap_set_advertise_tx_power");
  printf("  uint8 handle: 0x%02x\n",(int)handle);
  printf("  int16 power: 0x%04x\n",(int)power);
  struct gecko_msg_le_gap_set_advertise_tx_power_rsp_t* resp = gecko_cmd_le_gap_set_advertise_tx_power(handle,power);
  printf("    RETURNED\n");
  dump_le_gap_set_advertise_tx_power(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_set_discovery_extended_scan_response_rsp_t* cmd_le_gap_set_discovery_extended_scan_response(uint8 enable) {
  dump_command_header("le_gap_set_discovery_extended_scan_response");
  printf("  uint8 enable: 0x%02x\n",(int)enable);
  struct gecko_msg_le_gap_set_discovery_extended_scan_response_rsp_t* resp = gecko_cmd_le_gap_set_discovery_extended_scan_response(enable);
  printf("    RETURNED\n");
  dump_le_gap_set_discovery_extended_scan_response(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_start_periodic_advertising_rsp_t* cmd_le_gap_start_periodic_advertising(uint8 handle,uint16 interval_min,uint16 interval_max,uint32 flags) {
  dump_command_header("le_gap_start_periodic_advertising");
  printf("  uint8 handle: 0x%02x\n",(int)handle);
  printf("  uint16 interval_min: 0x%04x\n",(int)interval_min);
  printf("  uint16 interval_max: 0x%04x\n",(int)interval_max);
  printf("  uint32 flags: 0x%04x\n",(int)flags);
  struct gecko_msg_le_gap_start_periodic_advertising_rsp_t* resp = gecko_cmd_le_gap_start_periodic_advertising(handle,interval_min,interval_max,flags);
  printf("    RETURNED\n");
  dump_le_gap_start_periodic_advertising(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_stop_periodic_advertising_rsp_t* cmd_le_gap_stop_periodic_advertising(uint8 handle) {
  dump_command_header("le_gap_stop_periodic_advertising");
  printf("  uint8 handle: 0x%02x\n",(int)handle);
  struct gecko_msg_le_gap_stop_periodic_advertising_rsp_t* resp = gecko_cmd_le_gap_stop_periodic_advertising(handle);
  printf("    RETURNED\n");
  dump_le_gap_stop_periodic_advertising(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_set_long_advertising_data_rsp_t* cmd_le_gap_set_long_advertising_data(uint8 handle,uint8 packet_type) {
  dump_command_header("le_gap_set_long_advertising_data");
  printf("  uint8 handle: 0x%02x\n",(int)handle);
  printf("  uint8 packet_type: 0x%02x\n",(int)packet_type);
  struct gecko_msg_le_gap_set_long_advertising_data_rsp_t* resp = gecko_cmd_le_gap_set_long_advertising_data(handle,packet_type);
  printf("    RETURNED\n");
  dump_le_gap_set_long_advertising_data(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_enable_whitelisting_rsp_t* cmd_le_gap_enable_whitelisting(uint8 enable) {
  dump_command_header("le_gap_enable_whitelisting");
  printf("  uint8 enable: 0x%02x\n",(int)enable);
  struct gecko_msg_le_gap_enable_whitelisting_rsp_t* resp = gecko_cmd_le_gap_enable_whitelisting(enable);
  printf("    RETURNED\n");
  dump_le_gap_enable_whitelisting(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_gap_set_conn_timing_parameters_rsp_t* cmd_le_gap_set_conn_timing_parameters(uint16 min_interval,uint16 max_interval,uint16 latency,uint16 timeout,uint16 min_ce_length,uint16 max_ce_length) {
  dump_command_header("le_gap_set_conn_timing_parameters");
  printf("  uint16 min_interval: 0x%04x\n",(int)min_interval);
  printf("  uint16 max_interval: 0x%04x\n",(int)max_interval);
  printf("  uint16 latency: 0x%04x\n",(int)latency);
  printf("  uint16 timeout: 0x%04x\n",(int)timeout);
  printf("  uint16 min_ce_length: 0x%04x\n",(int)min_ce_length);
  printf("  uint16 max_ce_length: 0x%04x\n",(int)max_ce_length);
  struct gecko_msg_le_gap_set_conn_timing_parameters_rsp_t* resp = gecko_cmd_le_gap_set_conn_timing_parameters(min_interval,max_interval,latency,timeout,min_ce_length,max_ce_length);
  printf("    RETURNED\n");
  dump_le_gap_set_conn_timing_parameters(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_sync_open_rsp_t* cmd_sync_open(uint8 adv_sid,uint16 skip,uint16 timeout,bd_addr address,uint8 address_type) {
  dump_command_header("sync_open");
  printf("  uint8 adv_sid: 0x%02x\n",(int)adv_sid);
  printf("  uint16 skip: 0x%04x\n",(int)skip);
  printf("  uint16 timeout: 0x%04x\n",(int)timeout);
  printf("  bd_addr address: ");
   for(int i = 0; i < 6; i++)
      printf("%s%02x",(i)?":":"",address.addr[5-i]);
   printf("\n");
  printf("  uint8 address_type: 0x%02x\n",(int)address_type);
  struct gecko_msg_sync_open_rsp_t* resp = gecko_cmd_sync_open(adv_sid,skip,timeout,address,address_type);
  printf("    RETURNED\n");
  dump_sync_open(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_sync_close_rsp_t* cmd_sync_close(uint8 sync) {
  dump_command_header("sync_close");
  printf("  uint8 sync: 0x%02x\n",(int)sync);
  struct gecko_msg_sync_close_rsp_t* resp = gecko_cmd_sync_close(sync);
  printf("    RETURNED\n");
  dump_sync_close(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_connection_set_parameters_rsp_t* cmd_le_connection_set_parameters(uint8 connection,uint16 min_interval,uint16 max_interval,uint16 latency,uint16 timeout) {
  dump_command_header("le_connection_set_parameters");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 min_interval: 0x%04x\n",(int)min_interval);
  printf("  uint16 max_interval: 0x%04x\n",(int)max_interval);
  printf("  uint16 latency: 0x%04x\n",(int)latency);
  printf("  uint16 timeout: 0x%04x\n",(int)timeout);
  struct gecko_msg_le_connection_set_parameters_rsp_t* resp = gecko_cmd_le_connection_set_parameters(connection,min_interval,max_interval,latency,timeout);
  printf("    RETURNED\n");
  dump_le_connection_set_parameters(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_connection_get_rssi_rsp_t* cmd_le_connection_get_rssi(uint8 connection) {
  dump_command_header("le_connection_get_rssi");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  struct gecko_msg_le_connection_get_rssi_rsp_t* resp = gecko_cmd_le_connection_get_rssi(connection);
  printf("    RETURNED\n");
  dump_le_connection_get_rssi(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_connection_disable_slave_latency_rsp_t* cmd_le_connection_disable_slave_latency(uint8 connection,uint8 disable) {
  dump_command_header("le_connection_disable_slave_latency");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint8 disable: 0x%02x\n",(int)disable);
  struct gecko_msg_le_connection_disable_slave_latency_rsp_t* resp = gecko_cmd_le_connection_disable_slave_latency(connection,disable);
  printf("    RETURNED\n");
  dump_le_connection_disable_slave_latency(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_connection_set_phy_rsp_t* cmd_le_connection_set_phy(uint8 connection,uint8 phy) {
  dump_command_header("le_connection_set_phy");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint8 phy: 0x%02x\n",(int)phy);
  struct gecko_msg_le_connection_set_phy_rsp_t* resp = gecko_cmd_le_connection_set_phy(connection,phy);
  printf("    RETURNED\n");
  dump_le_connection_set_phy(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_connection_close_rsp_t* cmd_le_connection_close(uint8 connection) {
  dump_command_header("le_connection_close");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  struct gecko_msg_le_connection_close_rsp_t* resp = gecko_cmd_le_connection_close(connection);
  printf("    RETURNED\n");
  dump_le_connection_close(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_connection_set_timing_parameters_rsp_t* cmd_le_connection_set_timing_parameters(uint8 connection,uint16 min_interval,uint16 max_interval,uint16 latency,uint16 timeout,uint16 min_ce_length,uint16 max_ce_length) {
  dump_command_header("le_connection_set_timing_parameters");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 min_interval: 0x%04x\n",(int)min_interval);
  printf("  uint16 max_interval: 0x%04x\n",(int)max_interval);
  printf("  uint16 latency: 0x%04x\n",(int)latency);
  printf("  uint16 timeout: 0x%04x\n",(int)timeout);
  printf("  uint16 min_ce_length: 0x%04x\n",(int)min_ce_length);
  printf("  uint16 max_ce_length: 0x%04x\n",(int)max_ce_length);
  struct gecko_msg_le_connection_set_timing_parameters_rsp_t* resp = gecko_cmd_le_connection_set_timing_parameters(connection,min_interval,max_interval,latency,timeout,min_ce_length,max_ce_length);
  printf("    RETURNED\n");
  dump_le_connection_set_timing_parameters(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_le_connection_set_preferred_phy_rsp_t* cmd_le_connection_set_preferred_phy(uint8 connection,uint8 preferred_phy,uint8 accepted_phy) {
  dump_command_header("le_connection_set_preferred_phy");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint8 preferred_phy: 0x%02x\n",(int)preferred_phy);
  printf("  uint8 accepted_phy: 0x%02x\n",(int)accepted_phy);
  struct gecko_msg_le_connection_set_preferred_phy_rsp_t* resp = gecko_cmd_le_connection_set_preferred_phy(connection,preferred_phy,accepted_phy);
  printf("    RETURNED\n");
  dump_le_connection_set_preferred_phy(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_set_max_mtu_rsp_t* cmd_gatt_set_max_mtu(uint16 max_mtu) {
  dump_command_header("gatt_set_max_mtu");
  printf("  uint16 max_mtu: 0x%04x\n",(int)max_mtu);
  struct gecko_msg_gatt_set_max_mtu_rsp_t* resp = gecko_cmd_gatt_set_max_mtu(max_mtu);
  printf("    RETURNED\n");
  dump_gatt_set_max_mtu(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_discover_primary_services_rsp_t* cmd_gatt_discover_primary_services(uint8 connection) {
  dump_command_header("gatt_discover_primary_services");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  struct gecko_msg_gatt_discover_primary_services_rsp_t* resp = gecko_cmd_gatt_discover_primary_services(connection);
  printf("    RETURNED\n");
  dump_gatt_discover_primary_services(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_discover_primary_services_by_uuid_rsp_t* cmd_gatt_discover_primary_services_by_uuid(uint8 connection,uint8 uuid_len, const uint8* uuid_data) {
  dump_command_header("gatt_discover_primary_services_by_uuid");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint8 uuid_len: 0x%02x\n",(int)uuid_len);
  printf("  const uint8* uuid_data: 0x%p\n",uuid_data);
  struct gecko_msg_gatt_discover_primary_services_by_uuid_rsp_t* resp = gecko_cmd_gatt_discover_primary_services_by_uuid(connection,uuid_len,uuid_data);
  printf("    RETURNED\n");
  dump_gatt_discover_primary_services_by_uuid(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_discover_characteristics_rsp_t* cmd_gatt_discover_characteristics(uint8 connection,uint32 service) {
  dump_command_header("gatt_discover_characteristics");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint32 service: 0x%04x\n",(int)service);
  struct gecko_msg_gatt_discover_characteristics_rsp_t* resp = gecko_cmd_gatt_discover_characteristics(connection,service);
  printf("    RETURNED\n");
  dump_gatt_discover_characteristics(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_discover_characteristics_by_uuid_rsp_t* cmd_gatt_discover_characteristics_by_uuid(uint8 connection,uint32 service,uint8 uuid_len, const uint8* uuid_data) {
  dump_command_header("gatt_discover_characteristics_by_uuid");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint32 service: 0x%04x\n",(int)service);
  printf("  uint8 uuid_len: 0x%02x\n",(int)uuid_len);
  printf("  const uint8* uuid_data: 0x%p\n",uuid_data);
  struct gecko_msg_gatt_discover_characteristics_by_uuid_rsp_t* resp = gecko_cmd_gatt_discover_characteristics_by_uuid(connection,service,uuid_len,uuid_data);
  printf("    RETURNED\n");
  dump_gatt_discover_characteristics_by_uuid(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_set_characteristic_notification_rsp_t* cmd_gatt_set_characteristic_notification(uint8 connection,uint16 characteristic,uint8 flags) {
  dump_command_header("gatt_set_characteristic_notification");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 characteristic: 0x%04x\n",(int)characteristic);
  printf("  uint8 flags: 0x%02x\n",(int)flags);
  struct gecko_msg_gatt_set_characteristic_notification_rsp_t* resp = gecko_cmd_gatt_set_characteristic_notification(connection,characteristic,flags);
  printf("    RETURNED\n");
  dump_gatt_set_characteristic_notification(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_discover_descriptors_rsp_t* cmd_gatt_discover_descriptors(uint8 connection,uint16 characteristic) {
  dump_command_header("gatt_discover_descriptors");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 characteristic: 0x%04x\n",(int)characteristic);
  struct gecko_msg_gatt_discover_descriptors_rsp_t* resp = gecko_cmd_gatt_discover_descriptors(connection,characteristic);
  printf("    RETURNED\n");
  dump_gatt_discover_descriptors(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_read_characteristic_value_rsp_t* cmd_gatt_read_characteristic_value(uint8 connection,uint16 characteristic) {
  dump_command_header("gatt_read_characteristic_value");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 characteristic: 0x%04x\n",(int)characteristic);
  struct gecko_msg_gatt_read_characteristic_value_rsp_t* resp = gecko_cmd_gatt_read_characteristic_value(connection,characteristic);
  printf("    RETURNED\n");
  dump_gatt_read_characteristic_value(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_read_characteristic_value_by_uuid_rsp_t* cmd_gatt_read_characteristic_value_by_uuid(uint8 connection,uint32 service,uint8 uuid_len, const uint8* uuid_data) {
  dump_command_header("gatt_read_characteristic_value_by_uuid");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint32 service: 0x%04x\n",(int)service);
  printf("  uint8 uuid_len: 0x%02x\n",(int)uuid_len);
  printf("  const uint8* uuid_data: 0x%p\n",uuid_data);
  struct gecko_msg_gatt_read_characteristic_value_by_uuid_rsp_t* resp = gecko_cmd_gatt_read_characteristic_value_by_uuid(connection,service,uuid_len,uuid_data);
  printf("    RETURNED\n");
  dump_gatt_read_characteristic_value_by_uuid(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_write_characteristic_value_rsp_t* cmd_gatt_write_characteristic_value(uint8 connection,uint16 characteristic,uint8 value_len, const uint8* value_data) {
  dump_command_header("gatt_write_characteristic_value");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 characteristic: 0x%04x\n",(int)characteristic);
  printf("  uint8 value_len: 0x%02x\n",(int)value_len);
  printf("  const uint8* value_data: 0x%p\n",value_data);
  struct gecko_msg_gatt_write_characteristic_value_rsp_t* resp = gecko_cmd_gatt_write_characteristic_value(connection,characteristic,value_len,value_data);
  printf("    RETURNED\n");
  dump_gatt_write_characteristic_value(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_write_characteristic_value_without_response_rsp_t* cmd_gatt_write_characteristic_value_without_response(uint8 connection,uint16 characteristic,uint8 value_len, const uint8* value_data) {
  dump_command_header("gatt_write_characteristic_value_without_response");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 characteristic: 0x%04x\n",(int)characteristic);
  printf("  uint8 value_len: 0x%02x\n",(int)value_len);
  printf("  const uint8* value_data: 0x%p\n",value_data);
  struct gecko_msg_gatt_write_characteristic_value_without_response_rsp_t* resp = gecko_cmd_gatt_write_characteristic_value_without_response(connection,characteristic,value_len,value_data);
  printf("    RETURNED\n");
  dump_gatt_write_characteristic_value_without_response(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_prepare_characteristic_value_write_rsp_t* cmd_gatt_prepare_characteristic_value_write(uint8 connection,uint16 characteristic,uint16 offset,uint8 value_len, const uint8* value_data) {
  dump_command_header("gatt_prepare_characteristic_value_write");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 characteristic: 0x%04x\n",(int)characteristic);
  printf("  uint16 offset: 0x%04x\n",(int)offset);
  printf("  uint8 value_len: 0x%02x\n",(int)value_len);
  printf("  const uint8* value_data: 0x%p\n",value_data);
  struct gecko_msg_gatt_prepare_characteristic_value_write_rsp_t* resp = gecko_cmd_gatt_prepare_characteristic_value_write(connection,characteristic,offset,value_len,value_data);
  printf("    RETURNED\n");
  dump_gatt_prepare_characteristic_value_write(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_execute_characteristic_value_write_rsp_t* cmd_gatt_execute_characteristic_value_write(uint8 connection,uint8 flags) {
  dump_command_header("gatt_execute_characteristic_value_write");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint8 flags: 0x%02x\n",(int)flags);
  struct gecko_msg_gatt_execute_characteristic_value_write_rsp_t* resp = gecko_cmd_gatt_execute_characteristic_value_write(connection,flags);
  printf("    RETURNED\n");
  dump_gatt_execute_characteristic_value_write(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_send_characteristic_confirmation_rsp_t* cmd_gatt_send_characteristic_confirmation(uint8 connection) {
  dump_command_header("gatt_send_characteristic_confirmation");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  struct gecko_msg_gatt_send_characteristic_confirmation_rsp_t* resp = gecko_cmd_gatt_send_characteristic_confirmation(connection);
  printf("    RETURNED\n");
  dump_gatt_send_characteristic_confirmation(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_read_descriptor_value_rsp_t* cmd_gatt_read_descriptor_value(uint8 connection,uint16 descriptor) {
  dump_command_header("gatt_read_descriptor_value");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 descriptor: 0x%04x\n",(int)descriptor);
  struct gecko_msg_gatt_read_descriptor_value_rsp_t* resp = gecko_cmd_gatt_read_descriptor_value(connection,descriptor);
  printf("    RETURNED\n");
  dump_gatt_read_descriptor_value(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_write_descriptor_value_rsp_t* cmd_gatt_write_descriptor_value(uint8 connection,uint16 descriptor,uint8 value_len, const uint8* value_data) {
  dump_command_header("gatt_write_descriptor_value");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 descriptor: 0x%04x\n",(int)descriptor);
  printf("  uint8 value_len: 0x%02x\n",(int)value_len);
  printf("  const uint8* value_data: 0x%p\n",value_data);
  struct gecko_msg_gatt_write_descriptor_value_rsp_t* resp = gecko_cmd_gatt_write_descriptor_value(connection,descriptor,value_len,value_data);
  printf("    RETURNED\n");
  dump_gatt_write_descriptor_value(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_find_included_services_rsp_t* cmd_gatt_find_included_services(uint8 connection,uint32 service) {
  dump_command_header("gatt_find_included_services");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint32 service: 0x%04x\n",(int)service);
  struct gecko_msg_gatt_find_included_services_rsp_t* resp = gecko_cmd_gatt_find_included_services(connection,service);
  printf("    RETURNED\n");
  dump_gatt_find_included_services(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_read_multiple_characteristic_values_rsp_t* cmd_gatt_read_multiple_characteristic_values(uint8 connection,uint8 characteristic_list_len, const uint8* characteristic_list_data) {
  dump_command_header("gatt_read_multiple_characteristic_values");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint8 characteristic_list_len: 0x%02x\n",(int)characteristic_list_len);
  printf("  const uint8* characteristic_list_data: 0x%p\n",characteristic_list_data);
  struct gecko_msg_gatt_read_multiple_characteristic_values_rsp_t* resp = gecko_cmd_gatt_read_multiple_characteristic_values(connection,characteristic_list_len,characteristic_list_data);
  printf("    RETURNED\n");
  dump_gatt_read_multiple_characteristic_values(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_read_characteristic_value_from_offset_rsp_t* cmd_gatt_read_characteristic_value_from_offset(uint8 connection,uint16 characteristic,uint16 offset,uint16 maxlen) {
  dump_command_header("gatt_read_characteristic_value_from_offset");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 characteristic: 0x%04x\n",(int)characteristic);
  printf("  uint16 offset: 0x%04x\n",(int)offset);
  printf("  uint16 maxlen: 0x%04x\n",(int)maxlen);
  struct gecko_msg_gatt_read_characteristic_value_from_offset_rsp_t* resp = gecko_cmd_gatt_read_characteristic_value_from_offset(connection,characteristic,offset,maxlen);
  printf("    RETURNED\n");
  dump_gatt_read_characteristic_value_from_offset(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_prepare_characteristic_value_reliable_write_rsp_t* cmd_gatt_prepare_characteristic_value_reliable_write(uint8 connection,uint16 characteristic,uint16 offset,uint8 value_len, const uint8* value_data) {
  dump_command_header("gatt_prepare_characteristic_value_reliable_write");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 characteristic: 0x%04x\n",(int)characteristic);
  printf("  uint16 offset: 0x%04x\n",(int)offset);
  printf("  uint8 value_len: 0x%02x\n",(int)value_len);
  printf("  const uint8* value_data: 0x%p\n",value_data);
  struct gecko_msg_gatt_prepare_characteristic_value_reliable_write_rsp_t* resp = gecko_cmd_gatt_prepare_characteristic_value_reliable_write(connection,characteristic,offset,value_len,value_data);
  printf("    RETURNED\n");
  dump_gatt_prepare_characteristic_value_reliable_write(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_server_read_attribute_value_rsp_t* cmd_gatt_server_read_attribute_value(uint16 attribute,uint16 offset) {
  dump_command_header("gatt_server_read_attribute_value");
  printf("  uint16 attribute: 0x%04x\n",(int)attribute);
  printf("  uint16 offset: 0x%04x\n",(int)offset);
  struct gecko_msg_gatt_server_read_attribute_value_rsp_t* resp = gecko_cmd_gatt_server_read_attribute_value(attribute,offset);
  printf("    RETURNED\n");
  dump_gatt_server_read_attribute_value(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_server_read_attribute_type_rsp_t* cmd_gatt_server_read_attribute_type(uint16 attribute) {
  dump_command_header("gatt_server_read_attribute_type");
  printf("  uint16 attribute: 0x%04x\n",(int)attribute);
  struct gecko_msg_gatt_server_read_attribute_type_rsp_t* resp = gecko_cmd_gatt_server_read_attribute_type(attribute);
  printf("    RETURNED\n");
  dump_gatt_server_read_attribute_type(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_server_write_attribute_value_rsp_t* cmd_gatt_server_write_attribute_value(uint16 attribute,uint16 offset,uint8 value_len, const uint8* value_data) {
  dump_command_header("gatt_server_write_attribute_value");
  printf("  uint16 attribute: 0x%04x\n",(int)attribute);
  printf("  uint16 offset: 0x%04x\n",(int)offset);
  printf("  uint8 value_len: 0x%02x\n",(int)value_len);
  printf("  const uint8* value_data: 0x%p\n",value_data);
  struct gecko_msg_gatt_server_write_attribute_value_rsp_t* resp = gecko_cmd_gatt_server_write_attribute_value(attribute,offset,value_len,value_data);
  printf("    RETURNED\n");
  dump_gatt_server_write_attribute_value(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_server_send_user_read_response_rsp_t* cmd_gatt_server_send_user_read_response(uint8 connection,uint16 characteristic,uint8 att_errorcode,uint8 value_len, const uint8* value_data) {
  dump_command_header("gatt_server_send_user_read_response");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 characteristic: 0x%04x\n",(int)characteristic);
  printf("  uint8 att_errorcode: 0x%02x\n",(int)att_errorcode);
  printf("  uint8 value_len: 0x%02x\n",(int)value_len);
  printf("  const uint8* value_data: 0x%p\n",value_data);
  struct gecko_msg_gatt_server_send_user_read_response_rsp_t* resp = gecko_cmd_gatt_server_send_user_read_response(connection,characteristic,att_errorcode,value_len,value_data);
  printf("    RETURNED\n");
  dump_gatt_server_send_user_read_response(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_server_send_user_write_response_rsp_t* cmd_gatt_server_send_user_write_response(uint8 connection,uint16 characteristic,uint8 att_errorcode) {
  dump_command_header("gatt_server_send_user_write_response");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 characteristic: 0x%04x\n",(int)characteristic);
  printf("  uint8 att_errorcode: 0x%02x\n",(int)att_errorcode);
  struct gecko_msg_gatt_server_send_user_write_response_rsp_t* resp = gecko_cmd_gatt_server_send_user_write_response(connection,characteristic,att_errorcode);
  printf("    RETURNED\n");
  dump_gatt_server_send_user_write_response(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_server_send_characteristic_notification_rsp_t* cmd_gatt_server_send_characteristic_notification(uint8 connection,uint16 characteristic,uint8 value_len, const uint8* value_data) {
  dump_command_header("gatt_server_send_characteristic_notification");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 characteristic: 0x%04x\n",(int)characteristic);
  printf("  uint8 value_len: 0x%02x\n",(int)value_len);
  printf("  const uint8* value_data: 0x%p\n",value_data);
  struct gecko_msg_gatt_server_send_characteristic_notification_rsp_t* resp = gecko_cmd_gatt_server_send_characteristic_notification(connection,characteristic,value_len,value_data);
  printf("    RETURNED\n");
  dump_gatt_server_send_characteristic_notification(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_server_find_attribute_rsp_t* cmd_gatt_server_find_attribute(uint16 start,uint8 type_len, const uint8* type_data) {
  dump_command_header("gatt_server_find_attribute");
  printf("  uint16 start: 0x%04x\n",(int)start);
  printf("  uint8 type_len: 0x%02x\n",(int)type_len);
  printf("  const uint8* type_data: 0x%p\n",type_data);
  struct gecko_msg_gatt_server_find_attribute_rsp_t* resp = gecko_cmd_gatt_server_find_attribute(start,type_len,type_data);
  printf("    RETURNED\n");
  dump_gatt_server_find_attribute(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_server_set_capabilities_rsp_t* cmd_gatt_server_set_capabilities(uint32 caps,uint32 reserved) {
  dump_command_header("gatt_server_set_capabilities");
  printf("  uint32 caps: 0x%04x\n",(int)caps);
  printf("  uint32 reserved: 0x%04x\n",(int)reserved);
  struct gecko_msg_gatt_server_set_capabilities_rsp_t* resp = gecko_cmd_gatt_server_set_capabilities(caps,reserved);
  printf("    RETURNED\n");
  dump_gatt_server_set_capabilities(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_gatt_server_set_max_mtu_rsp_t* cmd_gatt_server_set_max_mtu(uint16 max_mtu) {
  dump_command_header("gatt_server_set_max_mtu");
  printf("  uint16 max_mtu: 0x%04x\n",(int)max_mtu);
  struct gecko_msg_gatt_server_set_max_mtu_rsp_t* resp = gecko_cmd_gatt_server_set_max_mtu(max_mtu);
  printf("    RETURNED\n");
  dump_gatt_server_set_max_mtu(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_hardware_set_soft_timer_rsp_t* cmd_hardware_set_soft_timer(uint32 time,uint8 handle,uint8 single_shot) {
  dump_command_header("hardware_set_soft_timer");
  printf("  uint32 time: 0x%04x\n",(int)time);
  printf("  uint8 handle: 0x%02x\n",(int)handle);
  printf("  uint8 single_shot: 0x%02x\n",(int)single_shot);
  struct gecko_msg_hardware_set_soft_timer_rsp_t* resp = gecko_cmd_hardware_set_soft_timer(time,handle,single_shot);
  printf("    RETURNED\n");
  dump_hardware_set_soft_timer(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_hardware_get_time_rsp_t* cmd_hardware_get_time() {
  dump_command_header("hardware_get_time");
  struct gecko_msg_hardware_get_time_rsp_t* resp = gecko_cmd_hardware_get_time();
  printf("    RETURNED\n");
  dump_hardware_get_time(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_hardware_set_lazy_soft_timer_rsp_t* cmd_hardware_set_lazy_soft_timer(uint32 time,uint32 slack,uint8 handle,uint8 single_shot) {
  dump_command_header("hardware_set_lazy_soft_timer");
  printf("  uint32 time: 0x%04x\n",(int)time);
  printf("  uint32 slack: 0x%04x\n",(int)slack);
  printf("  uint8 handle: 0x%02x\n",(int)handle);
  printf("  uint8 single_shot: 0x%02x\n",(int)single_shot);
  struct gecko_msg_hardware_set_lazy_soft_timer_rsp_t* resp = gecko_cmd_hardware_set_lazy_soft_timer(time,slack,handle,single_shot);
  printf("    RETURNED\n");
  dump_hardware_set_lazy_soft_timer(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_flash_ps_erase_all_rsp_t* cmd_flash_ps_erase_all() {
  dump_command_header("flash_ps_erase_all");
  struct gecko_msg_flash_ps_erase_all_rsp_t* resp = gecko_cmd_flash_ps_erase_all();
  printf("    RETURNED\n");
  dump_flash_ps_erase_all(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_flash_ps_save_rsp_t* cmd_flash_ps_save(uint16 key,uint8 value_len, const uint8* value_data) {
  dump_command_header("flash_ps_save");
  printf("  uint16 key: 0x%04x\n",(int)key);
  printf("  uint8 value_len: 0x%02x\n",(int)value_len);
  printf("  const uint8* value_data: 0x%p\n",value_data);
  struct gecko_msg_flash_ps_save_rsp_t* resp = gecko_cmd_flash_ps_save(key,value_len,value_data);
  printf("    RETURNED\n");
  dump_flash_ps_save(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_flash_ps_load_rsp_t* cmd_flash_ps_load(uint16 key) {
  dump_command_header("flash_ps_load");
  printf("  uint16 key: 0x%04x\n",(int)key);
  struct gecko_msg_flash_ps_load_rsp_t* resp = gecko_cmd_flash_ps_load(key);
  printf("    RETURNED\n");
  dump_flash_ps_load(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_flash_ps_erase_rsp_t* cmd_flash_ps_erase(uint16 key) {
  dump_command_header("flash_ps_erase");
  printf("  uint16 key: 0x%04x\n",(int)key);
  struct gecko_msg_flash_ps_erase_rsp_t* resp = gecko_cmd_flash_ps_erase(key);
  printf("    RETURNED\n");
  dump_flash_ps_erase(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_test_dtm_tx_rsp_t* cmd_test_dtm_tx(uint8 packet_type,uint8 length,uint8 channel,uint8 phy) {
  dump_command_header("test_dtm_tx");
  printf("  uint8 packet_type: 0x%02x\n",(int)packet_type);
  printf("  uint8 length: 0x%02x\n",(int)length);
  printf("  uint8 channel: 0x%02x\n",(int)channel);
  printf("  uint8 phy: 0x%02x\n",(int)phy);
  struct gecko_msg_test_dtm_tx_rsp_t* resp = gecko_cmd_test_dtm_tx(packet_type,length,channel,phy);
  printf("    RETURNED\n");
  dump_test_dtm_tx(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_test_dtm_rx_rsp_t* cmd_test_dtm_rx(uint8 channel,uint8 phy) {
  dump_command_header("test_dtm_rx");
  printf("  uint8 channel: 0x%02x\n",(int)channel);
  printf("  uint8 phy: 0x%02x\n",(int)phy);
  struct gecko_msg_test_dtm_rx_rsp_t* resp = gecko_cmd_test_dtm_rx(channel,phy);
  printf("    RETURNED\n");
  dump_test_dtm_rx(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_test_dtm_end_rsp_t* cmd_test_dtm_end() {
  dump_command_header("test_dtm_end");
  struct gecko_msg_test_dtm_end_rsp_t* resp = gecko_cmd_test_dtm_end();
  printf("    RETURNED\n");
  dump_test_dtm_end(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_sm_set_bondable_mode_rsp_t* cmd_sm_set_bondable_mode(uint8 bondable) {
  dump_command_header("sm_set_bondable_mode");
  printf("  uint8 bondable: 0x%02x\n",(int)bondable);
  struct gecko_msg_sm_set_bondable_mode_rsp_t* resp = gecko_cmd_sm_set_bondable_mode(bondable);
  printf("    RETURNED\n");
  dump_sm_set_bondable_mode(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_sm_configure_rsp_t* cmd_sm_configure(uint8 flags,uint8 io_capabilities) {
  dump_command_header("sm_configure");
  printf("  uint8 flags: 0x%02x\n",(int)flags);
  printf("  uint8 io_capabilities: 0x%02x\n",(int)io_capabilities);
  struct gecko_msg_sm_configure_rsp_t* resp = gecko_cmd_sm_configure(flags,io_capabilities);
  printf("    RETURNED\n");
  dump_sm_configure(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_sm_store_bonding_configuration_rsp_t* cmd_sm_store_bonding_configuration(uint8 max_bonding_count,uint8 policy_flags) {
  dump_command_header("sm_store_bonding_configuration");
  printf("  uint8 max_bonding_count: 0x%02x\n",(int)max_bonding_count);
  printf("  uint8 policy_flags: 0x%02x\n",(int)policy_flags);
  struct gecko_msg_sm_store_bonding_configuration_rsp_t* resp = gecko_cmd_sm_store_bonding_configuration(max_bonding_count,policy_flags);
  printf("    RETURNED\n");
  dump_sm_store_bonding_configuration(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_sm_increase_security_rsp_t* cmd_sm_increase_security(uint8 connection) {
  dump_command_header("sm_increase_security");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  struct gecko_msg_sm_increase_security_rsp_t* resp = gecko_cmd_sm_increase_security(connection);
  printf("    RETURNED\n");
  dump_sm_increase_security(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_sm_delete_bonding_rsp_t* cmd_sm_delete_bonding(uint8 bonding) {
  dump_command_header("sm_delete_bonding");
  printf("  uint8 bonding: 0x%02x\n",(int)bonding);
  struct gecko_msg_sm_delete_bonding_rsp_t* resp = gecko_cmd_sm_delete_bonding(bonding);
  printf("    RETURNED\n");
  dump_sm_delete_bonding(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_sm_delete_bondings_rsp_t* cmd_sm_delete_bondings() {
  dump_command_header("sm_delete_bondings");
  struct gecko_msg_sm_delete_bondings_rsp_t* resp = gecko_cmd_sm_delete_bondings();
  printf("    RETURNED\n");
  dump_sm_delete_bondings(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_sm_enter_passkey_rsp_t* cmd_sm_enter_passkey(uint8 connection,int32 passkey) {
  dump_command_header("sm_enter_passkey");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  int32 passkey: 0x%04x\n",(int)passkey);
  struct gecko_msg_sm_enter_passkey_rsp_t* resp = gecko_cmd_sm_enter_passkey(connection,passkey);
  printf("    RETURNED\n");
  dump_sm_enter_passkey(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_sm_passkey_confirm_rsp_t* cmd_sm_passkey_confirm(uint8 connection,uint8 confirm) {
  dump_command_header("sm_passkey_confirm");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint8 confirm: 0x%02x\n",(int)confirm);
  struct gecko_msg_sm_passkey_confirm_rsp_t* resp = gecko_cmd_sm_passkey_confirm(connection,confirm);
  printf("    RETURNED\n");
  dump_sm_passkey_confirm(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_sm_set_oob_data_rsp_t* cmd_sm_set_oob_data(uint8 oob_data_len, const uint8* oob_data_data) {
  dump_command_header("sm_set_oob_data");
  printf("  uint8 oob_data_len: 0x%02x\n",(int)oob_data_len);
  printf("  const uint8* oob_data_data: 0x%p\n",oob_data_data);
  struct gecko_msg_sm_set_oob_data_rsp_t* resp = gecko_cmd_sm_set_oob_data(oob_data_len,oob_data_data);
  printf("    RETURNED\n");
  dump_sm_set_oob_data(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_sm_list_all_bondings_rsp_t* cmd_sm_list_all_bondings() {
  dump_command_header("sm_list_all_bondings");
  struct gecko_msg_sm_list_all_bondings_rsp_t* resp = gecko_cmd_sm_list_all_bondings();
  printf("    RETURNED\n");
  dump_sm_list_all_bondings(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_sm_bonding_confirm_rsp_t* cmd_sm_bonding_confirm(uint8 connection,uint8 confirm) {
  dump_command_header("sm_bonding_confirm");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint8 confirm: 0x%02x\n",(int)confirm);
  struct gecko_msg_sm_bonding_confirm_rsp_t* resp = gecko_cmd_sm_bonding_confirm(connection,confirm);
  printf("    RETURNED\n");
  dump_sm_bonding_confirm(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_sm_set_debug_mode_rsp_t* cmd_sm_set_debug_mode() {
  dump_command_header("sm_set_debug_mode");
  struct gecko_msg_sm_set_debug_mode_rsp_t* resp = gecko_cmd_sm_set_debug_mode();
  printf("    RETURNED\n");
  dump_sm_set_debug_mode(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_sm_set_passkey_rsp_t* cmd_sm_set_passkey(int32 passkey) {
  dump_command_header("sm_set_passkey");
  printf("  int32 passkey: 0x%04x\n",(int)passkey);
  struct gecko_msg_sm_set_passkey_rsp_t* resp = gecko_cmd_sm_set_passkey(passkey);
  printf("    RETURNED\n");
  dump_sm_set_passkey(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_sm_use_sc_oob_rsp_t* cmd_sm_use_sc_oob(uint8 enable) {
  dump_command_header("sm_use_sc_oob");
  printf("  uint8 enable: 0x%02x\n",(int)enable);
  struct gecko_msg_sm_use_sc_oob_rsp_t* resp = gecko_cmd_sm_use_sc_oob(enable);
  printf("    RETURNED\n");
  dump_sm_use_sc_oob(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_sm_set_sc_remote_oob_data_rsp_t* cmd_sm_set_sc_remote_oob_data(uint8 oob_data_len, const uint8* oob_data_data) {
  dump_command_header("sm_set_sc_remote_oob_data");
  printf("  uint8 oob_data_len: 0x%02x\n",(int)oob_data_len);
  printf("  const uint8* oob_data_data: 0x%p\n",oob_data_data);
  struct gecko_msg_sm_set_sc_remote_oob_data_rsp_t* resp = gecko_cmd_sm_set_sc_remote_oob_data(oob_data_len,oob_data_data);
  printf("    RETURNED\n");
  dump_sm_set_sc_remote_oob_data(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_sm_add_to_whitelist_rsp_t* cmd_sm_add_to_whitelist(bd_addr address,uint8 address_type) {
  dump_command_header("sm_add_to_whitelist");
  printf("  bd_addr address: ");
   for(int i = 0; i < 6; i++)
      printf("%s%02x",(i)?":":"",address.addr[5-i]);
   printf("\n");
  printf("  uint8 address_type: 0x%02x\n",(int)address_type);
  struct gecko_msg_sm_add_to_whitelist_rsp_t* resp = gecko_cmd_sm_add_to_whitelist(address,address_type);
  printf("    RETURNED\n");
  dump_sm_add_to_whitelist(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_sm_set_minimum_key_size_rsp_t* cmd_sm_set_minimum_key_size(uint8 minimum_key_size) {
  dump_command_header("sm_set_minimum_key_size");
  printf("  uint8 minimum_key_size: 0x%02x\n",(int)minimum_key_size);
  struct gecko_msg_sm_set_minimum_key_size_rsp_t* resp = gecko_cmd_sm_set_minimum_key_size(minimum_key_size);
  printf("    RETURNED\n");
  dump_sm_set_minimum_key_size(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_homekit_configure_rsp_t* cmd_homekit_configure(uint8 i2c_address,uint8 support_display,uint8 hap_attribute_features,uint16 category,uint8 configuration_number,uint16 fast_advert_interval,uint16 fast_advert_timeout,uint32 flag,uint16 broadcast_advert_timeout,uint8 model_name_len, const uint8* model_name_data) {
  dump_command_header("homekit_configure");
  printf("  uint8 i2c_address: 0x%02x\n",(int)i2c_address);
  printf("  uint8 support_display: 0x%02x\n",(int)support_display);
  printf("  uint8 hap_attribute_features: 0x%02x\n",(int)hap_attribute_features);
  printf("  uint16 category: 0x%04x\n",(int)category);
  printf("  uint8 configuration_number: 0x%02x\n",(int)configuration_number);
  printf("  uint16 fast_advert_interval: 0x%04x\n",(int)fast_advert_interval);
  printf("  uint16 fast_advert_timeout: 0x%04x\n",(int)fast_advert_timeout);
  printf("  uint32 flag: 0x%04x\n",(int)flag);
  printf("  uint16 broadcast_advert_timeout: 0x%04x\n",(int)broadcast_advert_timeout);
  printf("  uint8 model_name_len: 0x%02x\n",(int)model_name_len);
  printf("  const uint8* model_name_data: 0x%p\n",model_name_data);
  struct gecko_msg_homekit_configure_rsp_t* resp = gecko_cmd_homekit_configure(i2c_address,support_display,hap_attribute_features,category,configuration_number,fast_advert_interval,fast_advert_timeout,flag,broadcast_advert_timeout,model_name_len,model_name_data);
  printf("    RETURNED\n");
  dump_homekit_configure(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_homekit_advertise_rsp_t* cmd_homekit_advertise(uint8 enable,uint16 interval_min,uint16 interval_max,uint8 channel_map) {
  dump_command_header("homekit_advertise");
  printf("  uint8 enable: 0x%02x\n",(int)enable);
  printf("  uint16 interval_min: 0x%04x\n",(int)interval_min);
  printf("  uint16 interval_max: 0x%04x\n",(int)interval_max);
  printf("  uint8 channel_map: 0x%02x\n",(int)channel_map);
  struct gecko_msg_homekit_advertise_rsp_t* resp = gecko_cmd_homekit_advertise(enable,interval_min,interval_max,channel_map);
  printf("    RETURNED\n");
  dump_homekit_advertise(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_homekit_delete_pairings_rsp_t* cmd_homekit_delete_pairings() {
  dump_command_header("homekit_delete_pairings");
  struct gecko_msg_homekit_delete_pairings_rsp_t* resp = gecko_cmd_homekit_delete_pairings();
  printf("    RETURNED\n");
  dump_homekit_delete_pairings(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_homekit_check_authcp_rsp_t* cmd_homekit_check_authcp() {
  dump_command_header("homekit_check_authcp");
  struct gecko_msg_homekit_check_authcp_rsp_t* resp = gecko_cmd_homekit_check_authcp();
  printf("    RETURNED\n");
  dump_homekit_check_authcp(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_homekit_get_pairing_id_rsp_t* cmd_homekit_get_pairing_id(uint8 connection) {
  dump_command_header("homekit_get_pairing_id");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  struct gecko_msg_homekit_get_pairing_id_rsp_t* resp = gecko_cmd_homekit_get_pairing_id(connection);
  printf("    RETURNED\n");
  dump_homekit_get_pairing_id(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_homekit_send_write_response_rsp_t* cmd_homekit_send_write_response(uint8 connection,uint16 characteristic,uint8 status_code) {
  dump_command_header("homekit_send_write_response");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 characteristic: 0x%04x\n",(int)characteristic);
  printf("  uint8 status_code: 0x%02x\n",(int)status_code);
  struct gecko_msg_homekit_send_write_response_rsp_t* resp = gecko_cmd_homekit_send_write_response(connection,characteristic,status_code);
  printf("    RETURNED\n");
  dump_homekit_send_write_response(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_homekit_send_read_response_rsp_t* cmd_homekit_send_read_response(uint8 connection,uint16 characteristic,uint8 status_code,uint16 attribute_size,uint8 value_len, const uint8* value_data) {
  dump_command_header("homekit_send_read_response");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 characteristic: 0x%04x\n",(int)characteristic);
  printf("  uint8 status_code: 0x%02x\n",(int)status_code);
  printf("  uint16 attribute_size: 0x%04x\n",(int)attribute_size);
  printf("  uint8 value_len: 0x%02x\n",(int)value_len);
  printf("  const uint8* value_data: 0x%p\n",value_data);
  struct gecko_msg_homekit_send_read_response_rsp_t* resp = gecko_cmd_homekit_send_read_response(connection,characteristic,status_code,attribute_size,value_len,value_data);
  printf("    RETURNED\n");
  dump_homekit_send_read_response(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_homekit_gsn_action_rsp_t* cmd_homekit_gsn_action(uint8 action) {
  dump_command_header("homekit_gsn_action");
  printf("  uint8 action: 0x%02x\n",(int)action);
  struct gecko_msg_homekit_gsn_action_rsp_t* resp = gecko_cmd_homekit_gsn_action(action);
  printf("    RETURNED\n");
  dump_homekit_gsn_action(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_homekit_event_notification_rsp_t* cmd_homekit_event_notification(uint8 connection,uint16 characteristic,uint8 change_originator,uint8 value_len, const uint8* value_data) {
  dump_command_header("homekit_event_notification");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 characteristic: 0x%04x\n",(int)characteristic);
  printf("  uint8 change_originator: 0x%02x\n",(int)change_originator);
  printf("  uint8 value_len: 0x%02x\n",(int)value_len);
  printf("  const uint8* value_data: 0x%p\n",value_data);
  struct gecko_msg_homekit_event_notification_rsp_t* resp = gecko_cmd_homekit_event_notification(connection,characteristic,change_originator,value_len,value_data);
  printf("    RETURNED\n");
  dump_homekit_event_notification(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_homekit_broadcast_action_rsp_t* cmd_homekit_broadcast_action(uint8 action,uint8 params_len, const uint8* params_data) {
  dump_command_header("homekit_broadcast_action");
  printf("  uint8 action: 0x%02x\n",(int)action);
  printf("  uint8 params_len: 0x%02x\n",(int)params_len);
  printf("  const uint8* params_data: 0x%p\n",params_data);
  struct gecko_msg_homekit_broadcast_action_rsp_t* resp = gecko_cmd_homekit_broadcast_action(action,params_len,params_data);
  printf("    RETURNED\n");
  dump_homekit_broadcast_action(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_coex_set_options_rsp_t* cmd_coex_set_options(uint32 mask,uint32 options) {
  dump_command_header("coex_set_options");
  printf("  uint32 mask: 0x%04x\n",(int)mask);
  printf("  uint32 options: 0x%04x\n",(int)options);
  struct gecko_msg_coex_set_options_rsp_t* resp = gecko_cmd_coex_set_options(mask,options);
  printf("    RETURNED\n");
  dump_coex_set_options(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_coex_get_counters_rsp_t* cmd_coex_get_counters(uint8 reset) {
  dump_command_header("coex_get_counters");
  printf("  uint8 reset: 0x%02x\n",(int)reset);
  struct gecko_msg_coex_get_counters_rsp_t* resp = gecko_cmd_coex_get_counters(reset);
  printf("    RETURNED\n");
  dump_coex_get_counters(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_l2cap_coc_send_connection_request_rsp_t* cmd_l2cap_coc_send_connection_request(uint8 connection,uint16 le_psm,uint16 mtu,uint16 mps,uint16 initial_credit) {
  dump_command_header("l2cap_coc_send_connection_request");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 le_psm: 0x%04x\n",(int)le_psm);
  printf("  uint16 mtu: 0x%04x\n",(int)mtu);
  printf("  uint16 mps: 0x%04x\n",(int)mps);
  printf("  uint16 initial_credit: 0x%04x\n",(int)initial_credit);
  struct gecko_msg_l2cap_coc_send_connection_request_rsp_t* resp = gecko_cmd_l2cap_coc_send_connection_request(connection,le_psm,mtu,mps,initial_credit);
  printf("    RETURNED\n");
  dump_l2cap_coc_send_connection_request(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_l2cap_coc_send_connection_response_rsp_t* cmd_l2cap_coc_send_connection_response(uint8 connection,uint16 cid,uint16 mtu,uint16 mps,uint16 initial_credit,uint16 result) {
  dump_command_header("l2cap_coc_send_connection_response");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 cid: 0x%04x\n",(int)cid);
  printf("  uint16 mtu: 0x%04x\n",(int)mtu);
  printf("  uint16 mps: 0x%04x\n",(int)mps);
  printf("  uint16 initial_credit: 0x%04x\n",(int)initial_credit);
  printf("  uint16 result: 0x%04x\n",(int)result);
  struct gecko_msg_l2cap_coc_send_connection_response_rsp_t* resp = gecko_cmd_l2cap_coc_send_connection_response(connection,cid,mtu,mps,initial_credit,result);
  printf("    RETURNED\n");
  dump_l2cap_coc_send_connection_response(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_l2cap_coc_send_le_flow_control_credit_rsp_t* cmd_l2cap_coc_send_le_flow_control_credit(uint8 connection,uint16 cid,uint16 credits) {
  dump_command_header("l2cap_coc_send_le_flow_control_credit");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 cid: 0x%04x\n",(int)cid);
  printf("  uint16 credits: 0x%04x\n",(int)credits);
  struct gecko_msg_l2cap_coc_send_le_flow_control_credit_rsp_t* resp = gecko_cmd_l2cap_coc_send_le_flow_control_credit(connection,cid,credits);
  printf("    RETURNED\n");
  dump_l2cap_coc_send_le_flow_control_credit(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_l2cap_coc_send_disconnection_request_rsp_t* cmd_l2cap_coc_send_disconnection_request(uint8 connection,uint16 cid) {
  dump_command_header("l2cap_coc_send_disconnection_request");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 cid: 0x%04x\n",(int)cid);
  struct gecko_msg_l2cap_coc_send_disconnection_request_rsp_t* resp = gecko_cmd_l2cap_coc_send_disconnection_request(connection,cid);
  printf("    RETURNED\n");
  dump_l2cap_coc_send_disconnection_request(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_l2cap_coc_send_data_rsp_t* cmd_l2cap_coc_send_data(uint8 connection,uint16 cid,uint8 data_len, const uint8* data_data) {
  dump_command_header("l2cap_coc_send_data");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 cid: 0x%04x\n",(int)cid);
  printf("  uint8 data_len: 0x%02x\n",(int)data_len);
  printf("  const uint8* data_data: 0x%p\n",data_data);
  struct gecko_msg_l2cap_coc_send_data_rsp_t* resp = gecko_cmd_l2cap_coc_send_data(connection,cid,data_len,data_data);
  printf("    RETURNED\n");
  dump_l2cap_coc_send_data(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_cte_transmitter_enable_cte_response_rsp_t* cmd_cte_transmitter_enable_cte_response(uint8 connection,uint8 cte_types,uint8 switching_pattern_len, const uint8* switching_pattern_data) {
  dump_command_header("cte_transmitter_enable_cte_response");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint8 cte_types: 0x%02x\n",(int)cte_types);
  printf("  uint8 switching_pattern_len: 0x%02x\n",(int)switching_pattern_len);
  printf("  const uint8* switching_pattern_data: 0x%p\n",switching_pattern_data);
  struct gecko_msg_cte_transmitter_enable_cte_response_rsp_t* resp = gecko_cmd_cte_transmitter_enable_cte_response(connection,cte_types,switching_pattern_len,switching_pattern_data);
  printf("    RETURNED\n");
  dump_cte_transmitter_enable_cte_response(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_cte_transmitter_disable_cte_response_rsp_t* cmd_cte_transmitter_disable_cte_response(uint8 connection) {
  dump_command_header("cte_transmitter_disable_cte_response");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  struct gecko_msg_cte_transmitter_disable_cte_response_rsp_t* resp = gecko_cmd_cte_transmitter_disable_cte_response(connection);
  printf("    RETURNED\n");
  dump_cte_transmitter_disable_cte_response(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_cte_transmitter_start_connectionless_cte_rsp_t* cmd_cte_transmitter_start_connectionless_cte(uint8 adv,uint8 cte_length,uint8 cte_type,uint8 cte_count,uint8 switching_pattern_len, const uint8* switching_pattern_data) {
  dump_command_header("cte_transmitter_start_connectionless_cte");
  printf("  uint8 adv: 0x%02x\n",(int)adv);
  printf("  uint8 cte_length: 0x%02x\n",(int)cte_length);
  printf("  uint8 cte_type: 0x%02x\n",(int)cte_type);
  printf("  uint8 cte_count: 0x%02x\n",(int)cte_count);
  printf("  uint8 switching_pattern_len: 0x%02x\n",(int)switching_pattern_len);
  printf("  const uint8* switching_pattern_data: 0x%p\n",switching_pattern_data);
  struct gecko_msg_cte_transmitter_start_connectionless_cte_rsp_t* resp = gecko_cmd_cte_transmitter_start_connectionless_cte(adv,cte_length,cte_type,cte_count,switching_pattern_len,switching_pattern_data);
  printf("    RETURNED\n");
  dump_cte_transmitter_start_connectionless_cte(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_cte_transmitter_stop_connectionless_cte_rsp_t* cmd_cte_transmitter_stop_connectionless_cte(uint8 adv) {
  dump_command_header("cte_transmitter_stop_connectionless_cte");
  printf("  uint8 adv: 0x%02x\n",(int)adv);
  struct gecko_msg_cte_transmitter_stop_connectionless_cte_rsp_t* resp = gecko_cmd_cte_transmitter_stop_connectionless_cte(adv);
  printf("    RETURNED\n");
  dump_cte_transmitter_stop_connectionless_cte(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_cte_transmitter_set_dtm_parameters_rsp_t* cmd_cte_transmitter_set_dtm_parameters(uint8 cte_length,uint8 cte_type,uint8 switching_pattern_len, const uint8* switching_pattern_data) {
  dump_command_header("cte_transmitter_set_dtm_parameters");
  printf("  uint8 cte_length: 0x%02x\n",(int)cte_length);
  printf("  uint8 cte_type: 0x%02x\n",(int)cte_type);
  printf("  uint8 switching_pattern_len: 0x%02x\n",(int)switching_pattern_len);
  printf("  const uint8* switching_pattern_data: 0x%p\n",switching_pattern_data);
  struct gecko_msg_cte_transmitter_set_dtm_parameters_rsp_t* resp = gecko_cmd_cte_transmitter_set_dtm_parameters(cte_length,cte_type,switching_pattern_len,switching_pattern_data);
  printf("    RETURNED\n");
  dump_cte_transmitter_set_dtm_parameters(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_cte_transmitter_clear_dtm_parameters_rsp_t* cmd_cte_transmitter_clear_dtm_parameters() {
  dump_command_header("cte_transmitter_clear_dtm_parameters");
  struct gecko_msg_cte_transmitter_clear_dtm_parameters_rsp_t* resp = gecko_cmd_cte_transmitter_clear_dtm_parameters();
  printf("    RETURNED\n");
  dump_cte_transmitter_clear_dtm_parameters(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_cte_receiver_configure_rsp_t* cmd_cte_receiver_configure(uint8 flags) {
  dump_command_header("cte_receiver_configure");
  printf("  uint8 flags: 0x%02x\n",(int)flags);
  struct gecko_msg_cte_receiver_configure_rsp_t* resp = gecko_cmd_cte_receiver_configure(flags);
  printf("    RETURNED\n");
  dump_cte_receiver_configure(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_cte_receiver_start_iq_sampling_rsp_t* cmd_cte_receiver_start_iq_sampling(uint8 connection,uint16 interval,uint8 cte_length,uint8 cte_type,uint8 slot_durations,uint8 switching_pattern_len, const uint8* switching_pattern_data) {
  dump_command_header("cte_receiver_start_iq_sampling");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  printf("  uint16 interval: 0x%04x\n",(int)interval);
  printf("  uint8 cte_length: 0x%02x\n",(int)cte_length);
  printf("  uint8 cte_type: 0x%02x\n",(int)cte_type);
  printf("  uint8 slot_durations: 0x%02x\n",(int)slot_durations);
  printf("  uint8 switching_pattern_len: 0x%02x\n",(int)switching_pattern_len);
  printf("  const uint8* switching_pattern_data: 0x%p\n",switching_pattern_data);
  struct gecko_msg_cte_receiver_start_iq_sampling_rsp_t* resp = gecko_cmd_cte_receiver_start_iq_sampling(connection,interval,cte_length,cte_type,slot_durations,switching_pattern_len,switching_pattern_data);
  printf("    RETURNED\n");
  dump_cte_receiver_start_iq_sampling(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_cte_receiver_stop_iq_sampling_rsp_t* cmd_cte_receiver_stop_iq_sampling(uint8 connection) {
  dump_command_header("cte_receiver_stop_iq_sampling");
  printf("  uint8 connection: 0x%02x\n",(int)connection);
  struct gecko_msg_cte_receiver_stop_iq_sampling_rsp_t* resp = gecko_cmd_cte_receiver_stop_iq_sampling(connection);
  printf("    RETURNED\n");
  dump_cte_receiver_stop_iq_sampling(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_cte_receiver_start_connectionless_iq_sampling_rsp_t* cmd_cte_receiver_start_connectionless_iq_sampling(uint8 sync,uint8 slot_durations,uint8 cte_count,uint8 switching_pattern_len, const uint8* switching_pattern_data) {
  dump_command_header("cte_receiver_start_connectionless_iq_sampling");
  printf("  uint8 sync: 0x%02x\n",(int)sync);
  printf("  uint8 slot_durations: 0x%02x\n",(int)slot_durations);
  printf("  uint8 cte_count: 0x%02x\n",(int)cte_count);
  printf("  uint8 switching_pattern_len: 0x%02x\n",(int)switching_pattern_len);
  printf("  const uint8* switching_pattern_data: 0x%p\n",switching_pattern_data);
  struct gecko_msg_cte_receiver_start_connectionless_iq_sampling_rsp_t* resp = gecko_cmd_cte_receiver_start_connectionless_iq_sampling(sync,slot_durations,cte_count,switching_pattern_len,switching_pattern_data);
  printf("    RETURNED\n");
  dump_cte_receiver_start_connectionless_iq_sampling(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_cte_receiver_stop_connectionless_iq_sampling_rsp_t* cmd_cte_receiver_stop_connectionless_iq_sampling(uint8 sync) {
  dump_command_header("cte_receiver_stop_connectionless_iq_sampling");
  printf("  uint8 sync: 0x%02x\n",(int)sync);
  struct gecko_msg_cte_receiver_stop_connectionless_iq_sampling_rsp_t* resp = gecko_cmd_cte_receiver_stop_connectionless_iq_sampling(sync);
  printf("    RETURNED\n");
  dump_cte_receiver_stop_connectionless_iq_sampling(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_cte_receiver_set_dtm_parameters_rsp_t* cmd_cte_receiver_set_dtm_parameters(uint8 cte_length,uint8 cte_type,uint8 slot_durations,uint8 switching_pattern_len, const uint8* switching_pattern_data) {
  dump_command_header("cte_receiver_set_dtm_parameters");
  printf("  uint8 cte_length: 0x%02x\n",(int)cte_length);
  printf("  uint8 cte_type: 0x%02x\n",(int)cte_type);
  printf("  uint8 slot_durations: 0x%02x\n",(int)slot_durations);
  printf("  uint8 switching_pattern_len: 0x%02x\n",(int)switching_pattern_len);
  printf("  const uint8* switching_pattern_data: 0x%p\n",switching_pattern_data);
  struct gecko_msg_cte_receiver_set_dtm_parameters_rsp_t* resp = gecko_cmd_cte_receiver_set_dtm_parameters(cte_length,cte_type,slot_durations,switching_pattern_len,switching_pattern_data);
  printf("    RETURNED\n");
  dump_cte_receiver_set_dtm_parameters(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_cte_receiver_clear_dtm_parameters_rsp_t* cmd_cte_receiver_clear_dtm_parameters() {
  dump_command_header("cte_receiver_clear_dtm_parameters");
  struct gecko_msg_cte_receiver_clear_dtm_parameters_rsp_t* resp = gecko_cmd_cte_receiver_clear_dtm_parameters();
  printf("    RETURNED\n");
  dump_cte_receiver_clear_dtm_parameters(resp);
  dump_footer();
  return resp;
}
static inline struct gecko_msg_user_message_to_target_rsp_t* cmd_user_message_to_target(uint8 data_len, const uint8* data_data) {
  dump_command_header("user_message_to_target");
  printf("  uint8 data_len: 0x%02x\n",(int)data_len);
  printf("  const uint8* data_data: 0x%p\n",data_data);
  struct gecko_msg_user_message_to_target_rsp_t* resp = gecko_cmd_user_message_to_target(data_len,data_data);
  printf("    RETURNED\n");
  dump_user_message_to_target(resp);
  dump_footer();
  return resp;
}
#define gecko_cmd_dfu_flash_set_address cmd_dfu_flash_set_address
#define gecko_cmd_dfu_flash_upload cmd_dfu_flash_upload
#define gecko_cmd_dfu_flash_upload_finish cmd_dfu_flash_upload_finish
#define gecko_cmd_system_hello cmd_system_hello
#define gecko_cmd_system_get_bt_address cmd_system_get_bt_address
#define gecko_cmd_system_set_bt_address cmd_system_set_bt_address
#define gecko_cmd_system_set_tx_power cmd_system_set_tx_power
#define gecko_cmd_system_get_random_data cmd_system_get_random_data
#define gecko_cmd_system_halt cmd_system_halt
#define gecko_cmd_system_set_device_name cmd_system_set_device_name
#define gecko_cmd_system_linklayer_configure cmd_system_linklayer_configure
#define gecko_cmd_system_get_counters cmd_system_get_counters
#define gecko_cmd_system_data_buffer_write cmd_system_data_buffer_write
#define gecko_cmd_system_set_identity_address cmd_system_set_identity_address
#define gecko_cmd_system_data_buffer_clear cmd_system_data_buffer_clear
#define gecko_cmd_le_gap_open cmd_le_gap_open
#define gecko_cmd_le_gap_set_mode cmd_le_gap_set_mode
#define gecko_cmd_le_gap_discover cmd_le_gap_discover
#define gecko_cmd_le_gap_end_procedure cmd_le_gap_end_procedure
#define gecko_cmd_le_gap_set_adv_parameters cmd_le_gap_set_adv_parameters
#define gecko_cmd_le_gap_set_conn_parameters cmd_le_gap_set_conn_parameters
#define gecko_cmd_le_gap_set_scan_parameters cmd_le_gap_set_scan_parameters
#define gecko_cmd_le_gap_set_adv_data cmd_le_gap_set_adv_data
#define gecko_cmd_le_gap_set_adv_timeout cmd_le_gap_set_adv_timeout
#define gecko_cmd_le_gap_set_conn_phy cmd_le_gap_set_conn_phy
#define gecko_cmd_le_gap_bt5_set_mode cmd_le_gap_bt5_set_mode
#define gecko_cmd_le_gap_bt5_set_adv_parameters cmd_le_gap_bt5_set_adv_parameters
#define gecko_cmd_le_gap_bt5_set_adv_data cmd_le_gap_bt5_set_adv_data
#define gecko_cmd_le_gap_set_privacy_mode cmd_le_gap_set_privacy_mode
#define gecko_cmd_le_gap_set_advertise_timing cmd_le_gap_set_advertise_timing
#define gecko_cmd_le_gap_set_advertise_channel_map cmd_le_gap_set_advertise_channel_map
#define gecko_cmd_le_gap_set_advertise_report_scan_request cmd_le_gap_set_advertise_report_scan_request
#define gecko_cmd_le_gap_set_advertise_phy cmd_le_gap_set_advertise_phy
#define gecko_cmd_le_gap_set_advertise_configuration cmd_le_gap_set_advertise_configuration
#define gecko_cmd_le_gap_clear_advertise_configuration cmd_le_gap_clear_advertise_configuration
#define gecko_cmd_le_gap_start_advertising cmd_le_gap_start_advertising
#define gecko_cmd_le_gap_stop_advertising cmd_le_gap_stop_advertising
#define gecko_cmd_le_gap_set_discovery_timing cmd_le_gap_set_discovery_timing
#define gecko_cmd_le_gap_set_discovery_type cmd_le_gap_set_discovery_type
#define gecko_cmd_le_gap_start_discovery cmd_le_gap_start_discovery
#define gecko_cmd_le_gap_set_data_channel_classification cmd_le_gap_set_data_channel_classification
#define gecko_cmd_le_gap_connect cmd_le_gap_connect
#define gecko_cmd_le_gap_set_advertise_tx_power cmd_le_gap_set_advertise_tx_power
#define gecko_cmd_le_gap_set_discovery_extended_scan_response cmd_le_gap_set_discovery_extended_scan_response
#define gecko_cmd_le_gap_start_periodic_advertising cmd_le_gap_start_periodic_advertising
#define gecko_cmd_le_gap_stop_periodic_advertising cmd_le_gap_stop_periodic_advertising
#define gecko_cmd_le_gap_set_long_advertising_data cmd_le_gap_set_long_advertising_data
#define gecko_cmd_le_gap_enable_whitelisting cmd_le_gap_enable_whitelisting
#define gecko_cmd_le_gap_set_conn_timing_parameters cmd_le_gap_set_conn_timing_parameters
#define gecko_cmd_sync_open cmd_sync_open
#define gecko_cmd_sync_close cmd_sync_close
#define gecko_cmd_le_connection_set_parameters cmd_le_connection_set_parameters
#define gecko_cmd_le_connection_get_rssi cmd_le_connection_get_rssi
#define gecko_cmd_le_connection_disable_slave_latency cmd_le_connection_disable_slave_latency
#define gecko_cmd_le_connection_set_phy cmd_le_connection_set_phy
#define gecko_cmd_le_connection_close cmd_le_connection_close
#define gecko_cmd_le_connection_set_timing_parameters cmd_le_connection_set_timing_parameters
#define gecko_cmd_le_connection_set_preferred_phy cmd_le_connection_set_preferred_phy
#define gecko_cmd_gatt_set_max_mtu cmd_gatt_set_max_mtu
#define gecko_cmd_gatt_discover_primary_services cmd_gatt_discover_primary_services
#define gecko_cmd_gatt_discover_primary_services_by_uuid cmd_gatt_discover_primary_services_by_uuid
#define gecko_cmd_gatt_discover_characteristics cmd_gatt_discover_characteristics
#define gecko_cmd_gatt_discover_characteristics_by_uuid cmd_gatt_discover_characteristics_by_uuid
#define gecko_cmd_gatt_set_characteristic_notification cmd_gatt_set_characteristic_notification
#define gecko_cmd_gatt_discover_descriptors cmd_gatt_discover_descriptors
#define gecko_cmd_gatt_read_characteristic_value cmd_gatt_read_characteristic_value
#define gecko_cmd_gatt_read_characteristic_value_by_uuid cmd_gatt_read_characteristic_value_by_uuid
#define gecko_cmd_gatt_write_characteristic_value cmd_gatt_write_characteristic_value
#define gecko_cmd_gatt_write_characteristic_value_without_response cmd_gatt_write_characteristic_value_without_response
#define gecko_cmd_gatt_prepare_characteristic_value_write cmd_gatt_prepare_characteristic_value_write
#define gecko_cmd_gatt_execute_characteristic_value_write cmd_gatt_execute_characteristic_value_write
#define gecko_cmd_gatt_send_characteristic_confirmation cmd_gatt_send_characteristic_confirmation
#define gecko_cmd_gatt_read_descriptor_value cmd_gatt_read_descriptor_value
#define gecko_cmd_gatt_write_descriptor_value cmd_gatt_write_descriptor_value
#define gecko_cmd_gatt_find_included_services cmd_gatt_find_included_services
#define gecko_cmd_gatt_read_multiple_characteristic_values cmd_gatt_read_multiple_characteristic_values
#define gecko_cmd_gatt_read_characteristic_value_from_offset cmd_gatt_read_characteristic_value_from_offset
#define gecko_cmd_gatt_prepare_characteristic_value_reliable_write cmd_gatt_prepare_characteristic_value_reliable_write
#define gecko_cmd_gatt_server_read_attribute_value cmd_gatt_server_read_attribute_value
#define gecko_cmd_gatt_server_read_attribute_type cmd_gatt_server_read_attribute_type
#define gecko_cmd_gatt_server_write_attribute_value cmd_gatt_server_write_attribute_value
#define gecko_cmd_gatt_server_send_user_read_response cmd_gatt_server_send_user_read_response
#define gecko_cmd_gatt_server_send_user_write_response cmd_gatt_server_send_user_write_response
#define gecko_cmd_gatt_server_send_characteristic_notification cmd_gatt_server_send_characteristic_notification
#define gecko_cmd_gatt_server_find_attribute cmd_gatt_server_find_attribute
#define gecko_cmd_gatt_server_set_capabilities cmd_gatt_server_set_capabilities
#define gecko_cmd_gatt_server_set_max_mtu cmd_gatt_server_set_max_mtu
#define gecko_cmd_hardware_set_soft_timer cmd_hardware_set_soft_timer
#define gecko_cmd_hardware_get_time cmd_hardware_get_time
#define gecko_cmd_hardware_set_lazy_soft_timer cmd_hardware_set_lazy_soft_timer
#define gecko_cmd_flash_ps_erase_all cmd_flash_ps_erase_all
#define gecko_cmd_flash_ps_save cmd_flash_ps_save
#define gecko_cmd_flash_ps_load cmd_flash_ps_load
#define gecko_cmd_flash_ps_erase cmd_flash_ps_erase
#define gecko_cmd_test_dtm_tx cmd_test_dtm_tx
#define gecko_cmd_test_dtm_rx cmd_test_dtm_rx
#define gecko_cmd_test_dtm_end cmd_test_dtm_end
#define gecko_cmd_sm_set_bondable_mode cmd_sm_set_bondable_mode
#define gecko_cmd_sm_configure cmd_sm_configure
#define gecko_cmd_sm_store_bonding_configuration cmd_sm_store_bonding_configuration
#define gecko_cmd_sm_increase_security cmd_sm_increase_security
#define gecko_cmd_sm_delete_bonding cmd_sm_delete_bonding
#define gecko_cmd_sm_delete_bondings cmd_sm_delete_bondings
#define gecko_cmd_sm_enter_passkey cmd_sm_enter_passkey
#define gecko_cmd_sm_passkey_confirm cmd_sm_passkey_confirm
#define gecko_cmd_sm_set_oob_data cmd_sm_set_oob_data
#define gecko_cmd_sm_list_all_bondings cmd_sm_list_all_bondings
#define gecko_cmd_sm_bonding_confirm cmd_sm_bonding_confirm
#define gecko_cmd_sm_set_debug_mode cmd_sm_set_debug_mode
#define gecko_cmd_sm_set_passkey cmd_sm_set_passkey
#define gecko_cmd_sm_use_sc_oob cmd_sm_use_sc_oob
#define gecko_cmd_sm_set_sc_remote_oob_data cmd_sm_set_sc_remote_oob_data
#define gecko_cmd_sm_add_to_whitelist cmd_sm_add_to_whitelist
#define gecko_cmd_sm_set_minimum_key_size cmd_sm_set_minimum_key_size
#define gecko_cmd_homekit_configure cmd_homekit_configure
#define gecko_cmd_homekit_advertise cmd_homekit_advertise
#define gecko_cmd_homekit_delete_pairings cmd_homekit_delete_pairings
#define gecko_cmd_homekit_check_authcp cmd_homekit_check_authcp
#define gecko_cmd_homekit_get_pairing_id cmd_homekit_get_pairing_id
#define gecko_cmd_homekit_send_write_response cmd_homekit_send_write_response
#define gecko_cmd_homekit_send_read_response cmd_homekit_send_read_response
#define gecko_cmd_homekit_gsn_action cmd_homekit_gsn_action
#define gecko_cmd_homekit_event_notification cmd_homekit_event_notification
#define gecko_cmd_homekit_broadcast_action cmd_homekit_broadcast_action
#define gecko_cmd_coex_set_options cmd_coex_set_options
#define gecko_cmd_coex_get_counters cmd_coex_get_counters
#define gecko_cmd_l2cap_coc_send_connection_request cmd_l2cap_coc_send_connection_request
#define gecko_cmd_l2cap_coc_send_connection_response cmd_l2cap_coc_send_connection_response
#define gecko_cmd_l2cap_coc_send_le_flow_control_credit cmd_l2cap_coc_send_le_flow_control_credit
#define gecko_cmd_l2cap_coc_send_disconnection_request cmd_l2cap_coc_send_disconnection_request
#define gecko_cmd_l2cap_coc_send_data cmd_l2cap_coc_send_data
#define gecko_cmd_cte_transmitter_enable_cte_response cmd_cte_transmitter_enable_cte_response
#define gecko_cmd_cte_transmitter_disable_cte_response cmd_cte_transmitter_disable_cte_response
#define gecko_cmd_cte_transmitter_start_connectionless_cte cmd_cte_transmitter_start_connectionless_cte
#define gecko_cmd_cte_transmitter_stop_connectionless_cte cmd_cte_transmitter_stop_connectionless_cte
#define gecko_cmd_cte_transmitter_set_dtm_parameters cmd_cte_transmitter_set_dtm_parameters
#define gecko_cmd_cte_transmitter_clear_dtm_parameters cmd_cte_transmitter_clear_dtm_parameters
#define gecko_cmd_cte_receiver_configure cmd_cte_receiver_configure
#define gecko_cmd_cte_receiver_start_iq_sampling cmd_cte_receiver_start_iq_sampling
#define gecko_cmd_cte_receiver_stop_iq_sampling cmd_cte_receiver_stop_iq_sampling
#define gecko_cmd_cte_receiver_start_connectionless_iq_sampling cmd_cte_receiver_start_connectionless_iq_sampling
#define gecko_cmd_cte_receiver_stop_connectionless_iq_sampling cmd_cte_receiver_stop_connectionless_iq_sampling
#define gecko_cmd_cte_receiver_set_dtm_parameters cmd_cte_receiver_set_dtm_parameters
#define gecko_cmd_cte_receiver_clear_dtm_parameters cmd_cte_receiver_clear_dtm_parameters
#define gecko_cmd_user_message_to_target cmd_user_message_to_target

#endif
