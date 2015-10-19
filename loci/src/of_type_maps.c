/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */

/****************************************************************
 *
 * Functions related to mapping wire values to object types
 * and lengths
 *
 ****************************************************************/

#include <loci/loci.h>
#include <loci/of_message.h>


/**
 * An array with the number of bytes in the fixed length part
 * of each OF object
 */

static const int
of_object_fixed_len_v1[OF_OBJECT_COUNT] = {
    -1,   /* of_object is not instantiable */
    36,   /* 1: of_aggregate_stats_reply */
    56,   /* 2: of_aggregate_stats_request */
    -1,   /* 3: of_async_config_failed_error_msg */
    -1,   /* 4: of_async_get_reply */
    -1,   /* 5: of_async_get_request */
    -1,   /* 6: of_async_set */
    12,   /* 7: of_bad_action_error_msg */
    -1,   /* 8: of_bad_instruction_error_msg */
    -1,   /* 9: of_bad_match_error_msg */
    -1,   /* 10: of_bad_property_error_msg */
    12,   /* 11: of_bad_request_error_msg */
    8,    /* 12: of_barrier_reply */
    8,    /* 13: of_barrier_request */
    -1,   /* 14: of_bsn_arp_idle */
    20,   /* 15: of_bsn_bw_clear_data_reply */
    16,   /* 16: of_bsn_bw_clear_data_request */
    20,   /* 17: of_bsn_bw_enable_get_reply */
    16,   /* 18: of_bsn_bw_enable_get_request */
    24,   /* 19: of_bsn_bw_enable_set_reply */
    20,   /* 20: of_bsn_bw_enable_set_request */
    -1,   /* 21: of_bsn_controller_connections_reply */
    -1,   /* 22: of_bsn_controller_connections_request */
    -1,   /* 23: of_bsn_debug_counter_desc_stats_reply */
    -1,   /* 24: of_bsn_debug_counter_desc_stats_request */
    -1,   /* 25: of_bsn_debug_counter_stats_reply */
    -1,   /* 26: of_bsn_debug_counter_stats_request */
    -1,   /* 27: of_bsn_flow_checksum_bucket_stats_reply */
    -1,   /* 28: of_bsn_flow_checksum_bucket_stats_request */
    -1,   /* 29: of_bsn_flow_idle */
    -1,   /* 30: of_bsn_flow_idle_enable_get_reply */
    -1,   /* 31: of_bsn_flow_idle_enable_get_request */
    -1,   /* 32: of_bsn_flow_idle_enable_set_reply */
    -1,   /* 33: of_bsn_flow_idle_enable_set_request */
    -1,   /* 34: of_bsn_generic_async */
    -1,   /* 35: of_bsn_generic_stats_reply */
    -1,   /* 36: of_bsn_generic_stats_request */
    -1,   /* 37: of_bsn_gentable_bucket_stats_reply */
    -1,   /* 38: of_bsn_gentable_bucket_stats_request */
    -1,   /* 39: of_bsn_gentable_clear_reply */
    -1,   /* 40: of_bsn_gentable_clear_request */
    -1,   /* 41: of_bsn_gentable_desc_stats_reply */
    -1,   /* 42: of_bsn_gentable_desc_stats_request */
    -1,   /* 43: of_bsn_gentable_entry_add */
    -1,   /* 44: of_bsn_gentable_entry_delete */
    -1,   /* 45: of_bsn_gentable_entry_desc_stats_reply */
    -1,   /* 46: of_bsn_gentable_entry_desc_stats_request */
    -1,   /* 47: of_bsn_gentable_entry_stats_reply */
    -1,   /* 48: of_bsn_gentable_entry_stats_request */
    -1,   /* 49: of_bsn_gentable_set_buckets_size */
    -1,   /* 50: of_bsn_gentable_stats_reply */
    -1,   /* 51: of_bsn_gentable_stats_request */
    16,   /* 52: of_bsn_get_interfaces_reply */
    16,   /* 53: of_bsn_get_interfaces_request */
    24,   /* 54: of_bsn_get_ip_mask_reply */
    24,   /* 55: of_bsn_get_ip_mask_request */
    24,   /* 56: of_bsn_get_l2_table_reply */
    16,   /* 57: of_bsn_get_l2_table_request */
    20,   /* 58: of_bsn_get_mirroring_reply */
    20,   /* 59: of_bsn_get_mirroring_request */
    -1,   /* 60: of_bsn_get_switch_pipeline_reply */
    -1,   /* 61: of_bsn_get_switch_pipeline_request */
    16,   /* 62: of_bsn_header */
    24,   /* 63: of_bsn_hybrid_get_reply */
    16,   /* 64: of_bsn_hybrid_get_request */
    -1,   /* 65: of_bsn_image_desc_stats_reply */
    -1,   /* 66: of_bsn_image_desc_stats_request */
    -1,   /* 67: of_bsn_lacp_convergence_notif */
    -1,   /* 68: of_bsn_lacp_stats_reply */
    -1,   /* 69: of_bsn_lacp_stats_request */
    -1,   /* 70: of_bsn_log */
    -1,   /* 71: of_bsn_lua_command_reply */
    -1,   /* 72: of_bsn_lua_command_request */
    -1,   /* 73: of_bsn_lua_notification */
    -1,   /* 74: of_bsn_lua_upload */
    23,   /* 75: of_bsn_pdu_rx_reply */
    26,   /* 76: of_bsn_pdu_rx_request */
    19,   /* 77: of_bsn_pdu_rx_timeout */
    23,   /* 78: of_bsn_pdu_tx_reply */
    26,   /* 79: of_bsn_pdu_tx_request */
    -1,   /* 80: of_bsn_port_counter_stats_reply */
    -1,   /* 81: of_bsn_port_counter_stats_request */
    -1,   /* 82: of_bsn_role_status */
    -1,   /* 83: of_bsn_set_aux_cxns_reply */
    -1,   /* 84: of_bsn_set_aux_cxns_request */
    24,   /* 85: of_bsn_set_ip_mask */
    24,   /* 86: of_bsn_set_l2_table_reply */
    24,   /* 87: of_bsn_set_l2_table_request */
    -1,   /* 88: of_bsn_set_lacp_reply */
    -1,   /* 89: of_bsn_set_lacp_request */
    20,   /* 90: of_bsn_set_mirroring */
    20,   /* 91: of_bsn_set_pktin_suppression_reply */
    32,   /* 92: of_bsn_set_pktin_suppression_request */
    -1,   /* 93: of_bsn_set_switch_pipeline_reply */
    -1,   /* 94: of_bsn_set_switch_pipeline_request */
    20,   /* 95: of_bsn_shell_command */
    16,   /* 96: of_bsn_shell_output */
    20,   /* 97: of_bsn_shell_status */
    24,   /* 98: of_bsn_stats_reply */
    24,   /* 99: of_bsn_stats_request */
    -1,   /* 100: of_bsn_switch_pipeline_stats_reply */
    -1,   /* 101: of_bsn_switch_pipeline_stats_request */
    -1,   /* 102: of_bsn_table_checksum_stats_reply */
    -1,   /* 103: of_bsn_table_checksum_stats_request */
    -1,   /* 104: of_bsn_table_set_buckets_size */
    -1,   /* 105: of_bsn_takeover */
    -1,   /* 106: of_bsn_time_reply */
    -1,   /* 107: of_bsn_time_request */
    24,   /* 108: of_bsn_virtual_port_create_reply */
    20,   /* 109: of_bsn_virtual_port_create_request */
    20,   /* 110: of_bsn_virtual_port_remove_reply */
    20,   /* 111: of_bsn_virtual_port_remove_request */
    -1,   /* 112: of_bsn_vlan_counter_clear */
    -1,   /* 113: of_bsn_vlan_counter_stats_reply */
    -1,   /* 114: of_bsn_vlan_counter_stats_request */
    -1,   /* 115: of_bsn_vrf_counter_stats_reply */
    -1,   /* 116: of_bsn_vrf_counter_stats_request */
    -1,   /* 117: of_bundle_add_msg */
    -1,   /* 118: of_bundle_ctrl_msg */
    -1,   /* 119: of_bundle_failed_error_msg */
    1068, /* 120: of_desc_stats_reply */
    12,   /* 121: of_desc_stats_request */
    8,    /* 122: of_echo_reply */
    8,    /* 123: of_echo_request */
    10,   /* 124: of_error_msg */
    12,   /* 125: of_experimenter */
    -1,   /* 126: of_experimenter_error_msg */
    16,   /* 127: of_experimenter_stats_reply */
    16,   /* 128: of_experimenter_stats_request */
    32,   /* 129: of_features_reply */
    8,    /* 130: of_features_request */
    72,   /* 131: of_flow_add */
    72,   /* 132: of_flow_delete */
    72,   /* 133: of_flow_delete_strict */
    72,   /* 134: of_flow_mod */
    12,   /* 135: of_flow_mod_failed_error_msg */
    72,   /* 136: of_flow_modify */
    72,   /* 137: of_flow_modify_strict */
    -1,   /* 138: of_flow_monitor_failed_error_msg */
    88,   /* 139: of_flow_removed */
    12,   /* 140: of_flow_stats_reply */
    56,   /* 141: of_flow_stats_request */
    12,   /* 142: of_get_config_reply */
    8,    /* 143: of_get_config_request */
    -1,   /* 144: of_group_add */
    -1,   /* 145: of_group_delete */
    -1,   /* 146: of_group_desc_stats_reply */
    -1,   /* 147: of_group_desc_stats_request */
    -1,   /* 148: of_group_features_stats_reply */
    -1,   /* 149: of_group_features_stats_request */
    -1,   /* 150: of_group_mod */
    -1,   /* 151: of_group_mod_failed_error_msg */
    -1,   /* 152: of_group_modify */
    -1,   /* 153: of_group_stats_reply */
    -1,   /* 154: of_group_stats_request */
    8,    /* 155: of_header */
    8,    /* 156: of_hello */
    12,   /* 157: of_hello_failed_error_msg */
    -1,   /* 158: of_meter_config_stats_reply */
    -1,   /* 159: of_meter_config_stats_request */
    -1,   /* 160: of_meter_features_stats_reply */
    -1,   /* 161: of_meter_features_stats_request */
    -1,   /* 162: of_meter_mod */
    -1,   /* 163: of_meter_mod_failed_error_msg */
    -1,   /* 164: of_meter_stats_reply */
    -1,   /* 165: of_meter_stats_request */
    20,   /* 166: of_nicira_controller_role_reply */
    20,   /* 167: of_nicira_controller_role_request */
    16,   /* 168: of_nicira_header */
    18,   /* 169: of_packet_in */
    16,   /* 170: of_packet_out */
    -1,   /* 171: of_port_desc_stats_reply */
    -1,   /* 172: of_port_desc_stats_request */
    32,   /* 173: of_port_mod */
    12,   /* 174: of_port_mod_failed_error_msg */
    12,   /* 175: of_port_stats_reply */
    20,   /* 176: of_port_stats_request */
    64,   /* 177: of_port_status */
    -1,   /* 178: of_queue_desc_stats_reply */
    -1,   /* 179: of_queue_desc_stats_request */
    16,   /* 180: of_queue_get_config_reply */
    12,   /* 181: of_queue_get_config_request */
    12,   /* 182: of_queue_op_failed_error_msg */
    12,   /* 183: of_queue_stats_reply */
    20,   /* 184: of_queue_stats_request */
    -1,   /* 185: of_requestforward */
    -1,   /* 186: of_role_reply */
    -1,   /* 187: of_role_request */
    -1,   /* 188: of_role_request_failed_error_msg */
    -1,   /* 189: of_role_status */
    12,   /* 190: of_set_config */
    12,   /* 191: of_stats_reply */
    12,   /* 192: of_stats_request */
    -1,   /* 193: of_switch_config_failed_error_msg */
    -1,   /* 194: of_table_desc_stats_reply */
    -1,   /* 195: of_table_desc_stats_request */
    -1,   /* 196: of_table_features_failed_error_msg */
    -1,   /* 197: of_table_features_stats_reply */
    -1,   /* 198: of_table_features_stats_request */
    16,   /* 199: of_table_mod */
    -1,   /* 200: of_table_mod_failed_error_msg */
    12,   /* 201: of_table_stats_reply */
    12,   /* 202: of_table_stats_request */
    -1,   /* 203: of_table_status */
    8,    /* 204: of_action */
    16,   /* 205: of_action_bsn */
    28,   /* 206: of_action_bsn_checksum */
    -1,   /* 207: of_action_bsn_gentable */
    24,   /* 208: of_action_bsn_mirror */
    16,   /* 209: of_action_bsn_set_tunnel_dst */
    -1,   /* 210: of_action_copy_ttl_in */
    -1,   /* 211: of_action_copy_ttl_out */
    -1,   /* 212: of_action_dec_mpls_ttl */
    -1,   /* 213: of_action_dec_nw_ttl */
    16,   /* 214: of_action_enqueue */
    8,    /* 215: of_action_experimenter */
    -1,   /* 216: of_action_group */
    -1,   /* 217: of_action_id */
    -1,   /* 218: of_action_id_bsn */
    -1,   /* 219: of_action_id_bsn_checksum */
    -1,   /* 220: of_action_id_bsn_gentable */
    -1,   /* 221: of_action_id_bsn_mirror */
    -1,   /* 222: of_action_id_bsn_set_tunnel_dst */
    -1,   /* 223: of_action_id_copy_ttl_in */
    -1,   /* 224: of_action_id_copy_ttl_out */
    -1,   /* 225: of_action_id_dec_mpls_ttl */
    -1,   /* 226: of_action_id_dec_nw_ttl */
    -1,   /* 227: of_action_id_experimenter */
    -1,   /* 228: of_action_id_group */
    -1,   /* 229: of_action_id_nicira */
    -1,   /* 230: of_action_id_nicira_dec_ttl */
    -1,   /* 231: of_action_id_output */
    -1,   /* 232: of_action_id_pop_mpls */
    -1,   /* 233: of_action_id_pop_pbb */
    -1,   /* 234: of_action_id_pop_vlan */
    -1,   /* 235: of_action_id_push_mpls */
    -1,   /* 236: of_action_id_push_pbb */
    -1,   /* 237: of_action_id_push_vlan */
    -1,   /* 238: of_action_id_set_field */
    -1,   /* 239: of_action_id_set_mpls_ttl */
    -1,   /* 240: of_action_id_set_nw_ttl */
    -1,   /* 241: of_action_id_set_queue */
    16,   /* 242: of_action_nicira */
    16,   /* 243: of_action_nicira_dec_ttl */
    8,    /* 244: of_action_output */
    -1,   /* 245: of_action_pop_mpls */
    -1,   /* 246: of_action_pop_pbb */
    -1,   /* 247: of_action_pop_vlan */
    -1,   /* 248: of_action_push_mpls */
    -1,   /* 249: of_action_push_pbb */
    -1,   /* 250: of_action_push_vlan */
    16,   /* 251: of_action_set_dl_dst */
    16,   /* 252: of_action_set_dl_src */
    -1,   /* 253: of_action_set_field */
    -1,   /* 254: of_action_set_mpls_label */
    -1,   /* 255: of_action_set_mpls_tc */
    -1,   /* 256: of_action_set_mpls_ttl */
    8,    /* 257: of_action_set_nw_dst */
    -1,   /* 258: of_action_set_nw_ecn */
    8,    /* 259: of_action_set_nw_src */
    8,    /* 260: of_action_set_nw_tos */
    -1,   /* 261: of_action_set_nw_ttl */
    -1,   /* 262: of_action_set_queue */
    8,    /* 263: of_action_set_tp_dst */
    8,    /* 264: of_action_set_tp_src */
    8,    /* 265: of_action_set_vlan_pcp */
    8,    /* 266: of_action_set_vlan_vid */
    8,    /* 267: of_action_strip_vlan */
    -1,   /* 268: of_async_config_prop */
    -1,   /* 269: of_async_config_prop_experimenter_master */
    -1,   /* 270: of_async_config_prop_experimenter_slave */
    -1,   /* 271: of_async_config_prop_flow_removed_master */
    -1,   /* 272: of_async_config_prop_flow_removed_slave */
    -1,   /* 273: of_async_config_prop_packet_in_master */
    -1,   /* 274: of_async_config_prop_packet_in_slave */
    -1,   /* 275: of_async_config_prop_port_status_master */
    -1,   /* 276: of_async_config_prop_port_status_slave */
    -1,   /* 277: of_async_config_prop_requestforward_master */
    -1,   /* 278: of_async_config_prop_requestforward_slave */
    -1,   /* 279: of_async_config_prop_role_status_master */
    -1,   /* 280: of_async_config_prop_role_status_slave */
    -1,   /* 281: of_async_config_prop_table_status_master */
    -1,   /* 282: of_async_config_prop_table_status_slave */
    -1,   /* 283: of_bsn_controller_connection */
    -1,   /* 284: of_bsn_debug_counter_desc_stats_entry */
    -1,   /* 285: of_bsn_debug_counter_stats_entry */
    -1,   /* 286: of_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 287: of_bsn_generic_stats_entry */
    -1,   /* 288: of_bsn_gentable_bucket_stats_entry */
    -1,   /* 289: of_bsn_gentable_desc_stats_entry */
    -1,   /* 290: of_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 291: of_bsn_gentable_entry_stats_entry */
    -1,   /* 292: of_bsn_gentable_stats_entry */
    32,   /* 293: of_bsn_interface */
    -1,   /* 294: of_bsn_lacp_stats_entry */
    -1,   /* 295: of_bsn_port_counter_stats_entry */
    -1,   /* 296: of_bsn_switch_pipeline_stats_entry */
    -1,   /* 297: of_bsn_table_checksum_stats_entry */
    -1,   /* 298: of_bsn_tlv */
    -1,   /* 299: of_bsn_tlv_actor_key */
    -1,   /* 300: of_bsn_tlv_actor_port_num */
    -1,   /* 301: of_bsn_tlv_actor_port_priority */
    -1,   /* 302: of_bsn_tlv_actor_state */
    -1,   /* 303: of_bsn_tlv_actor_system_mac */
    -1,   /* 304: of_bsn_tlv_actor_system_priority */
    -1,   /* 305: of_bsn_tlv_anchor */
    -1,   /* 306: of_bsn_tlv_broadcast_query_timeout */
    -1,   /* 307: of_bsn_tlv_broadcast_rate */
    -1,   /* 308: of_bsn_tlv_bucket */
    -1,   /* 309: of_bsn_tlv_circuit_id */
    -1,   /* 310: of_bsn_tlv_convergence_status */
    -1,   /* 311: of_bsn_tlv_crc_enabled */
    -1,   /* 312: of_bsn_tlv_data */
    -1,   /* 313: of_bsn_tlv_decap */
    -1,   /* 314: of_bsn_tlv_eth_dst */
    -1,   /* 315: of_bsn_tlv_eth_src */
    -1,   /* 316: of_bsn_tlv_external_gateway_ip */
    -1,   /* 317: of_bsn_tlv_external_gateway_mac */
    -1,   /* 318: of_bsn_tlv_external_ip */
    -1,   /* 319: of_bsn_tlv_external_mac */
    -1,   /* 320: of_bsn_tlv_external_netmask */
    -1,   /* 321: of_bsn_tlv_generation_id */
    -1,   /* 322: of_bsn_tlv_header_size */
    -1,   /* 323: of_bsn_tlv_icmp_code */
    -1,   /* 324: of_bsn_tlv_icmp_id */
    -1,   /* 325: of_bsn_tlv_icmp_type */
    -1,   /* 326: of_bsn_tlv_idle_notification */
    -1,   /* 327: of_bsn_tlv_idle_time */
    -1,   /* 328: of_bsn_tlv_idle_timeout */
    -1,   /* 329: of_bsn_tlv_igmp_snooping */
    -1,   /* 330: of_bsn_tlv_internal_gateway_mac */
    -1,   /* 331: of_bsn_tlv_internal_mac */
    -1,   /* 332: of_bsn_tlv_interval */
    -1,   /* 333: of_bsn_tlv_ip_proto */
    -1,   /* 334: of_bsn_tlv_ipv4 */
    -1,   /* 335: of_bsn_tlv_ipv4_dst */
    -1,   /* 336: of_bsn_tlv_ipv4_netmask */
    -1,   /* 337: of_bsn_tlv_ipv4_src */
    -1,   /* 338: of_bsn_tlv_ipv6 */
    -1,   /* 339: of_bsn_tlv_known_multicast_rate */
    -1,   /* 340: of_bsn_tlv_l2_multicast_lookup */
    -1,   /* 341: of_bsn_tlv_mac */
    -1,   /* 342: of_bsn_tlv_mac_mask */
    -1,   /* 343: of_bsn_tlv_mcg_type_vxlan */
    -1,   /* 344: of_bsn_tlv_miss_packets */
    -1,   /* 345: of_bsn_tlv_mpls_control_word */
    -1,   /* 346: of_bsn_tlv_mpls_label */
    -1,   /* 347: of_bsn_tlv_mpls_sequenced */
    -1,   /* 348: of_bsn_tlv_multicast_interface_id */
    -1,   /* 349: of_bsn_tlv_name */
    -1,   /* 350: of_bsn_tlv_negate */
    -1,   /* 351: of_bsn_tlv_nexthop_type_vxlan */
    -1,   /* 352: of_bsn_tlv_offset */
    -1,   /* 353: of_bsn_tlv_partner_key */
    -1,   /* 354: of_bsn_tlv_partner_port_num */
    -1,   /* 355: of_bsn_tlv_partner_port_priority */
    -1,   /* 356: of_bsn_tlv_partner_state */
    -1,   /* 357: of_bsn_tlv_partner_system_mac */
    -1,   /* 358: of_bsn_tlv_partner_system_priority */
    -1,   /* 359: of_bsn_tlv_port */
    -1,   /* 360: of_bsn_tlv_port_vxlan_mode */
    -1,   /* 361: of_bsn_tlv_priority */
    -1,   /* 362: of_bsn_tlv_queue_id */
    -1,   /* 363: of_bsn_tlv_queue_weight */
    -1,   /* 364: of_bsn_tlv_rate_unit */
    -1,   /* 365: of_bsn_tlv_reference */
    -1,   /* 366: of_bsn_tlv_reply_packets */
    -1,   /* 367: of_bsn_tlv_request_packets */
    -1,   /* 368: of_bsn_tlv_rx_bytes */
    -1,   /* 369: of_bsn_tlv_rx_packets */
    -1,   /* 370: of_bsn_tlv_sampling_rate */
    -1,   /* 371: of_bsn_tlv_set_loopback_mode */
    -1,   /* 372: of_bsn_tlv_strip_mpls_l2_on_ingress */
    -1,   /* 373: of_bsn_tlv_strip_mpls_l3_on_ingress */
    -1,   /* 374: of_bsn_tlv_strip_vlan_on_egress */
    -1,   /* 375: of_bsn_tlv_sub_agent_id */
    -1,   /* 376: of_bsn_tlv_tcp_dst */
    -1,   /* 377: of_bsn_tlv_tcp_src */
    -1,   /* 378: of_bsn_tlv_tx_bytes */
    -1,   /* 379: of_bsn_tlv_tx_packets */
    -1,   /* 380: of_bsn_tlv_udf_anchor */
    -1,   /* 381: of_bsn_tlv_udf_id */
    -1,   /* 382: of_bsn_tlv_udf_length */
    -1,   /* 383: of_bsn_tlv_udf_offset */
    -1,   /* 384: of_bsn_tlv_udp_dst */
    -1,   /* 385: of_bsn_tlv_udp_src */
    -1,   /* 386: of_bsn_tlv_unicast_query_timeout */
    -1,   /* 387: of_bsn_tlv_unicast_rate */
    -1,   /* 388: of_bsn_tlv_unknown_multicast_rate */
    -1,   /* 389: of_bsn_tlv_vlan_pcp */
    -1,   /* 390: of_bsn_tlv_vlan_vid */
    -1,   /* 391: of_bsn_tlv_vlan_vid_mask */
    -1,   /* 392: of_bsn_tlv_vni */
    -1,   /* 393: of_bsn_tlv_vrf */
    -1,   /* 394: of_bsn_vlan_counter_stats_entry */
    4,    /* 395: of_bsn_vport */
    60,   /* 396: of_bsn_vport_l2gre */
    32,   /* 397: of_bsn_vport_q_in_q */
    -1,   /* 398: of_bsn_vrf_counter_stats_entry */
    -1,   /* 399: of_bucket */
    -1,   /* 400: of_bucket_counter */
    -1,   /* 401: of_bundle_prop */
    -1,   /* 402: of_bundle_prop_experimenter */
    88,   /* 403: of_flow_stats_entry */
    -1,   /* 404: of_group_desc_stats_entry */
    -1,   /* 405: of_group_stats_entry */
    -1,   /* 406: of_hello_elem */
    -1,   /* 407: of_hello_elem_versionbitmap */
    -1,   /* 408: of_instruction */
    -1,   /* 409: of_instruction_apply_actions */
    -1,   /* 410: of_instruction_bsn */
    -1,   /* 411: of_instruction_bsn_arp_offload */
    -1,   /* 412: of_instruction_bsn_auto_negotiation */
    -1,   /* 413: of_instruction_bsn_deny */
    -1,   /* 414: of_instruction_bsn_dhcp_offload */
    -1,   /* 415: of_instruction_bsn_disable_l3 */
    -1,   /* 416: of_instruction_bsn_disable_split_horizon_check */
    -1,   /* 417: of_instruction_bsn_disable_src_mac_check */
    -1,   /* 418: of_instruction_bsn_disable_vlan_counters */
    -1,   /* 419: of_instruction_bsn_internal_priority */
    -1,   /* 420: of_instruction_bsn_packet_of_death */
    -1,   /* 421: of_instruction_bsn_permit */
    -1,   /* 422: of_instruction_bsn_prioritize_pdus */
    -1,   /* 423: of_instruction_bsn_require_vlan_xlate */
    -1,   /* 424: of_instruction_bsn_span_destination */
    -1,   /* 425: of_instruction_clear_actions */
    -1,   /* 426: of_instruction_experimenter */
    -1,   /* 427: of_instruction_goto_table */
    -1,   /* 428: of_instruction_id */
    -1,   /* 429: of_instruction_id_apply_actions */
    -1,   /* 430: of_instruction_id_bsn */
    -1,   /* 431: of_instruction_id_bsn_arp_offload */
    -1,   /* 432: of_instruction_id_bsn_auto_negotiation */
    -1,   /* 433: of_instruction_id_bsn_deny */
    -1,   /* 434: of_instruction_id_bsn_dhcp_offload */
    -1,   /* 435: of_instruction_id_bsn_disable_l3 */
    -1,   /* 436: of_instruction_id_bsn_disable_split_horizon_check */
    -1,   /* 437: of_instruction_id_bsn_disable_src_mac_check */
    -1,   /* 438: of_instruction_id_bsn_disable_vlan_counters */
    -1,   /* 439: of_instruction_id_bsn_internal_priority */
    -1,   /* 440: of_instruction_id_bsn_packet_of_death */
    -1,   /* 441: of_instruction_id_bsn_permit */
    -1,   /* 442: of_instruction_id_bsn_prioritize_pdus */
    -1,   /* 443: of_instruction_id_bsn_require_vlan_xlate */
    -1,   /* 444: of_instruction_id_bsn_span_destination */
    -1,   /* 445: of_instruction_id_clear_actions */
    -1,   /* 446: of_instruction_id_experimenter */
    -1,   /* 447: of_instruction_id_goto_table */
    -1,   /* 448: of_instruction_id_meter */
    -1,   /* 449: of_instruction_id_write_actions */
    -1,   /* 450: of_instruction_id_write_metadata */
    -1,   /* 451: of_instruction_meter */
    -1,   /* 452: of_instruction_write_actions */
    -1,   /* 453: of_instruction_write_metadata */
    40,   /* 454: of_match_v1 */
    -1,   /* 455: of_match_v2 */
    -1,   /* 456: of_match_v3 */
    -1,   /* 457: of_meter_band */
    -1,   /* 458: of_meter_band_drop */
    -1,   /* 459: of_meter_band_dscp_remark */
    -1,   /* 460: of_meter_band_experimenter */
    -1,   /* 461: of_meter_band_stats */
    -1,   /* 462: of_meter_config */
    -1,   /* 463: of_meter_features */
    -1,   /* 464: of_meter_stats */
    -1,   /* 465: of_oxm */
    -1,   /* 466: of_oxm_arp_op */
    -1,   /* 467: of_oxm_arp_op_masked */
    -1,   /* 468: of_oxm_arp_sha */
    -1,   /* 469: of_oxm_arp_sha_masked */
    -1,   /* 470: of_oxm_arp_spa */
    -1,   /* 471: of_oxm_arp_spa_masked */
    -1,   /* 472: of_oxm_arp_tha */
    -1,   /* 473: of_oxm_arp_tha_masked */
    -1,   /* 474: of_oxm_arp_tpa */
    -1,   /* 475: of_oxm_arp_tpa_masked */
    -1,   /* 476: of_oxm_bsn_egr_port_group_id */
    -1,   /* 477: of_oxm_bsn_egr_port_group_id_masked */
    -1,   /* 478: of_oxm_bsn_global_vrf_allowed */
    -1,   /* 479: of_oxm_bsn_global_vrf_allowed_masked */
    -1,   /* 480: of_oxm_bsn_in_ports_128 */
    -1,   /* 481: of_oxm_bsn_in_ports_128_masked */
    -1,   /* 482: of_oxm_bsn_in_ports_512 */
    -1,   /* 483: of_oxm_bsn_in_ports_512_masked */
    -1,   /* 484: of_oxm_bsn_ingress_port_group_id */
    -1,   /* 485: of_oxm_bsn_ingress_port_group_id_masked */
    -1,   /* 486: of_oxm_bsn_inner_eth_dst */
    -1,   /* 487: of_oxm_bsn_inner_eth_dst_masked */
    -1,   /* 488: of_oxm_bsn_inner_eth_src */
    -1,   /* 489: of_oxm_bsn_inner_eth_src_masked */
    -1,   /* 490: of_oxm_bsn_inner_vlan_vid */
    -1,   /* 491: of_oxm_bsn_inner_vlan_vid_masked */
    -1,   /* 492: of_oxm_bsn_l2_cache_hit */
    -1,   /* 493: of_oxm_bsn_l2_cache_hit_masked */
    -1,   /* 494: of_oxm_bsn_l3_dst_class_id */
    -1,   /* 495: of_oxm_bsn_l3_dst_class_id_masked */
    -1,   /* 496: of_oxm_bsn_l3_interface_class_id */
    -1,   /* 497: of_oxm_bsn_l3_interface_class_id_masked */
    -1,   /* 498: of_oxm_bsn_l3_src_class_id */
    -1,   /* 499: of_oxm_bsn_l3_src_class_id_masked */
    -1,   /* 500: of_oxm_bsn_lag_id */
    -1,   /* 501: of_oxm_bsn_lag_id_masked */
    -1,   /* 502: of_oxm_bsn_tcp_flags */
    -1,   /* 503: of_oxm_bsn_tcp_flags_masked */
    -1,   /* 504: of_oxm_bsn_udf0 */
    -1,   /* 505: of_oxm_bsn_udf0_masked */
    -1,   /* 506: of_oxm_bsn_udf1 */
    -1,   /* 507: of_oxm_bsn_udf1_masked */
    -1,   /* 508: of_oxm_bsn_udf2 */
    -1,   /* 509: of_oxm_bsn_udf2_masked */
    -1,   /* 510: of_oxm_bsn_udf3 */
    -1,   /* 511: of_oxm_bsn_udf3_masked */
    -1,   /* 512: of_oxm_bsn_udf4 */
    -1,   /* 513: of_oxm_bsn_udf4_masked */
    -1,   /* 514: of_oxm_bsn_udf5 */
    -1,   /* 515: of_oxm_bsn_udf5_masked */
    -1,   /* 516: of_oxm_bsn_udf6 */
    -1,   /* 517: of_oxm_bsn_udf6_masked */
    -1,   /* 518: of_oxm_bsn_udf7 */
    -1,   /* 519: of_oxm_bsn_udf7_masked */
    -1,   /* 520: of_oxm_bsn_vlan_xlate_port_group_id */
    -1,   /* 521: of_oxm_bsn_vlan_xlate_port_group_id_masked */
    -1,   /* 522: of_oxm_bsn_vrf */
    -1,   /* 523: of_oxm_bsn_vrf_masked */
    -1,   /* 524: of_oxm_bsn_vxlan_network_id */
    -1,   /* 525: of_oxm_bsn_vxlan_network_id_masked */
    -1,   /* 526: of_oxm_eth_dst */
    -1,   /* 527: of_oxm_eth_dst_masked */
    -1,   /* 528: of_oxm_eth_src */
    -1,   /* 529: of_oxm_eth_src_masked */
    -1,   /* 530: of_oxm_eth_type */
    -1,   /* 531: of_oxm_eth_type_masked */
    -1,   /* 532: of_oxm_icmpv4_code */
    -1,   /* 533: of_oxm_icmpv4_code_masked */
    -1,   /* 534: of_oxm_icmpv4_type */
    -1,   /* 535: of_oxm_icmpv4_type_masked */
    -1,   /* 536: of_oxm_icmpv6_code */
    -1,   /* 537: of_oxm_icmpv6_code_masked */
    -1,   /* 538: of_oxm_icmpv6_type */
    -1,   /* 539: of_oxm_icmpv6_type_masked */
    -1,   /* 540: of_oxm_in_phy_port */
    -1,   /* 541: of_oxm_in_phy_port_masked */
    -1,   /* 542: of_oxm_in_port */
    -1,   /* 543: of_oxm_in_port_masked */
    -1,   /* 544: of_oxm_ip_dscp */
    -1,   /* 545: of_oxm_ip_dscp_masked */
    -1,   /* 546: of_oxm_ip_ecn */
    -1,   /* 547: of_oxm_ip_ecn_masked */
    -1,   /* 548: of_oxm_ip_proto */
    -1,   /* 549: of_oxm_ip_proto_masked */
    -1,   /* 550: of_oxm_ipv4_dst */
    -1,   /* 551: of_oxm_ipv4_dst_masked */
    -1,   /* 552: of_oxm_ipv4_src */
    -1,   /* 553: of_oxm_ipv4_src_masked */
    -1,   /* 554: of_oxm_ipv6_dst */
    -1,   /* 555: of_oxm_ipv6_dst_masked */
    -1,   /* 556: of_oxm_ipv6_exthdr */
    -1,   /* 557: of_oxm_ipv6_exthdr_masked */
    -1,   /* 558: of_oxm_ipv6_flabel */
    -1,   /* 559: of_oxm_ipv6_flabel_masked */
    -1,   /* 560: of_oxm_ipv6_nd_sll */
    -1,   /* 561: of_oxm_ipv6_nd_sll_masked */
    -1,   /* 562: of_oxm_ipv6_nd_target */
    -1,   /* 563: of_oxm_ipv6_nd_target_masked */
    -1,   /* 564: of_oxm_ipv6_nd_tll */
    -1,   /* 565: of_oxm_ipv6_nd_tll_masked */
    -1,   /* 566: of_oxm_ipv6_src */
    -1,   /* 567: of_oxm_ipv6_src_masked */
    -1,   /* 568: of_oxm_metadata */
    -1,   /* 569: of_oxm_metadata_masked */
    -1,   /* 570: of_oxm_mpls_bos */
    -1,   /* 571: of_oxm_mpls_bos_masked */
    -1,   /* 572: of_oxm_mpls_label */
    -1,   /* 573: of_oxm_mpls_label_masked */
    -1,   /* 574: of_oxm_mpls_tc */
    -1,   /* 575: of_oxm_mpls_tc_masked */
    -1,   /* 576: of_oxm_pbb_uca */
    -1,   /* 577: of_oxm_pbb_uca_masked */
    -1,   /* 578: of_oxm_sctp_dst */
    -1,   /* 579: of_oxm_sctp_dst_masked */
    -1,   /* 580: of_oxm_sctp_src */
    -1,   /* 581: of_oxm_sctp_src_masked */
    -1,   /* 582: of_oxm_tcp_dst */
    -1,   /* 583: of_oxm_tcp_dst_masked */
    -1,   /* 584: of_oxm_tcp_src */
    -1,   /* 585: of_oxm_tcp_src_masked */
    -1,   /* 586: of_oxm_tunnel_id */
    -1,   /* 587: of_oxm_tunnel_id_masked */
    -1,   /* 588: of_oxm_tunnel_ipv4_dst */
    -1,   /* 589: of_oxm_tunnel_ipv4_dst_masked */
    -1,   /* 590: of_oxm_tunnel_ipv4_src */
    -1,   /* 591: of_oxm_tunnel_ipv4_src_masked */
    -1,   /* 592: of_oxm_udp_dst */
    -1,   /* 593: of_oxm_udp_dst_masked */
    -1,   /* 594: of_oxm_udp_src */
    -1,   /* 595: of_oxm_udp_src_masked */
    -1,   /* 596: of_oxm_vlan_pcp */
    -1,   /* 597: of_oxm_vlan_pcp_masked */
    -1,   /* 598: of_oxm_vlan_vid */
    -1,   /* 599: of_oxm_vlan_vid_masked */
    8,    /* 600: of_packet_queue */
    48,   /* 601: of_port_desc */
    -1,   /* 602: of_port_desc_prop */
    -1,   /* 603: of_port_desc_prop_bsn */
    -1,   /* 604: of_port_desc_prop_bsn_generation_id */
    -1,   /* 605: of_port_desc_prop_bsn_uplink */
    -1,   /* 606: of_port_desc_prop_ethernet */
    -1,   /* 607: of_port_desc_prop_experimenter */
    -1,   /* 608: of_port_desc_prop_optical */
    -1,   /* 609: of_port_mod_prop */
    -1,   /* 610: of_port_mod_prop_ethernet */
    -1,   /* 611: of_port_mod_prop_experimenter */
    -1,   /* 612: of_port_mod_prop_optical */
    104,  /* 613: of_port_stats_entry */
    -1,   /* 614: of_port_stats_prop */
    -1,   /* 615: of_port_stats_prop_ethernet */
    -1,   /* 616: of_port_stats_prop_experimenter */
    -1,   /* 617: of_port_stats_prop_optical */
    -1,   /* 618: of_queue_desc */
    -1,   /* 619: of_queue_desc_prop */
    -1,   /* 620: of_queue_desc_prop_experimenter */
    -1,   /* 621: of_queue_desc_prop_max_rate */
    -1,   /* 622: of_queue_desc_prop_min_rate */
    8,    /* 623: of_queue_prop */
    -1,   /* 624: of_queue_prop_experimenter */
    -1,   /* 625: of_queue_prop_max_rate */
    16,   /* 626: of_queue_prop_min_rate */
    32,   /* 627: of_queue_stats_entry */
    -1,   /* 628: of_queue_stats_prop */
    -1,   /* 629: of_queue_stats_prop_experimenter */
    -1,   /* 630: of_role_prop */
    -1,   /* 631: of_role_prop_experimenter */
    -1,   /* 632: of_table_desc */
    -1,   /* 633: of_table_feature_prop */
    -1,   /* 634: of_table_feature_prop_apply_actions */
    -1,   /* 635: of_table_feature_prop_apply_actions_miss */
    -1,   /* 636: of_table_feature_prop_apply_setfield */
    -1,   /* 637: of_table_feature_prop_apply_setfield_miss */
    -1,   /* 638: of_table_feature_prop_experimenter */
    -1,   /* 639: of_table_feature_prop_experimenter_miss */
    -1,   /* 640: of_table_feature_prop_instructions */
    -1,   /* 641: of_table_feature_prop_instructions_miss */
    -1,   /* 642: of_table_feature_prop_match */
    -1,   /* 643: of_table_feature_prop_next_tables */
    -1,   /* 644: of_table_feature_prop_next_tables_miss */
    -1,   /* 645: of_table_feature_prop_table_sync_from */
    -1,   /* 646: of_table_feature_prop_wildcards */
    -1,   /* 647: of_table_feature_prop_write_actions */
    -1,   /* 648: of_table_feature_prop_write_actions_miss */
    -1,   /* 649: of_table_feature_prop_write_setfield */
    -1,   /* 650: of_table_feature_prop_write_setfield_miss */
    -1,   /* 651: of_table_features */
    -1,   /* 652: of_table_mod_prop */
    -1,   /* 653: of_table_mod_prop_eviction */
    -1,   /* 654: of_table_mod_prop_experimenter */
    -1,   /* 655: of_table_mod_prop_vacancy */
    64,   /* 656: of_table_stats_entry */
    -1,   /* 657: of_uint32 */
    -1,   /* 658: of_uint64 */
    -1,   /* 659: of_uint8 */
    0,    /* 660: of_list_action */
    -1,   /* 661: of_list_action_id */
    -1,   /* 662: of_list_async_config_prop */
    -1,   /* 663: of_list_bsn_controller_connection */
    -1,   /* 664: of_list_bsn_debug_counter_desc_stats_entry */
    -1,   /* 665: of_list_bsn_debug_counter_stats_entry */
    -1,   /* 666: of_list_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 667: of_list_bsn_generic_stats_entry */
    -1,   /* 668: of_list_bsn_gentable_bucket_stats_entry */
    -1,   /* 669: of_list_bsn_gentable_desc_stats_entry */
    -1,   /* 670: of_list_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 671: of_list_bsn_gentable_entry_stats_entry */
    -1,   /* 672: of_list_bsn_gentable_stats_entry */
    0,    /* 673: of_list_bsn_interface */
    -1,   /* 674: of_list_bsn_lacp_stats_entry */
    -1,   /* 675: of_list_bsn_port_counter_stats_entry */
    -1,   /* 676: of_list_bsn_switch_pipeline_stats_entry */
    -1,   /* 677: of_list_bsn_table_checksum_stats_entry */
    -1,   /* 678: of_list_bsn_tlv */
    -1,   /* 679: of_list_bsn_vlan_counter_stats_entry */
    -1,   /* 680: of_list_bsn_vrf_counter_stats_entry */
    -1,   /* 681: of_list_bucket */
    -1,   /* 682: of_list_bucket_counter */
    -1,   /* 683: of_list_bundle_prop */
    0,    /* 684: of_list_flow_stats_entry */
    -1,   /* 685: of_list_group_desc_stats_entry */
    -1,   /* 686: of_list_group_stats_entry */
    -1,   /* 687: of_list_hello_elem */
    -1,   /* 688: of_list_instruction */
    -1,   /* 689: of_list_instruction_id */
    -1,   /* 690: of_list_meter_band */
    -1,   /* 691: of_list_meter_band_stats */
    -1,   /* 692: of_list_meter_config */
    -1,   /* 693: of_list_meter_stats */
    -1,   /* 694: of_list_oxm */
    0,    /* 695: of_list_packet_queue */
    0,    /* 696: of_list_port_desc */
    -1,   /* 697: of_list_port_desc_prop */
    -1,   /* 698: of_list_port_mod_prop */
    0,    /* 699: of_list_port_stats_entry */
    -1,   /* 700: of_list_port_stats_prop */
    -1,   /* 701: of_list_queue_desc */
    -1,   /* 702: of_list_queue_desc_prop */
    0,    /* 703: of_list_queue_prop */
    0,    /* 704: of_list_queue_stats_entry */
    -1,   /* 705: of_list_queue_stats_prop */
    -1,   /* 706: of_list_role_prop */
    -1,   /* 707: of_list_table_desc */
    -1,   /* 708: of_list_table_feature_prop */
    -1,   /* 709: of_list_table_features */
    -1,   /* 710: of_list_table_mod_prop */
    0,    /* 711: of_list_table_stats_entry */
    -1,   /* 712: of_list_uint32 */
    -1,   /* 713: of_list_uint64 */
    -1    /* 714: of_list_uint8 */
};

static const int
of_object_fixed_len_v2[OF_OBJECT_COUNT] = {
    -1,   /* of_object is not instantiable */
    40,   /* 1: of_aggregate_stats_reply */
    136,  /* 2: of_aggregate_stats_request */
    -1,   /* 3: of_async_config_failed_error_msg */
    -1,   /* 4: of_async_get_reply */
    -1,   /* 5: of_async_get_request */
    -1,   /* 6: of_async_set */
    12,   /* 7: of_bad_action_error_msg */
    12,   /* 8: of_bad_instruction_error_msg */
    12,   /* 9: of_bad_match_error_msg */
    -1,   /* 10: of_bad_property_error_msg */
    12,   /* 11: of_bad_request_error_msg */
    8,    /* 12: of_barrier_reply */
    8,    /* 13: of_barrier_request */
    -1,   /* 14: of_bsn_arp_idle */
    20,   /* 15: of_bsn_bw_clear_data_reply */
    16,   /* 16: of_bsn_bw_clear_data_request */
    20,   /* 17: of_bsn_bw_enable_get_reply */
    16,   /* 18: of_bsn_bw_enable_get_request */
    24,   /* 19: of_bsn_bw_enable_set_reply */
    20,   /* 20: of_bsn_bw_enable_set_request */
    -1,   /* 21: of_bsn_controller_connections_reply */
    -1,   /* 22: of_bsn_controller_connections_request */
    -1,   /* 23: of_bsn_debug_counter_desc_stats_reply */
    -1,   /* 24: of_bsn_debug_counter_desc_stats_request */
    -1,   /* 25: of_bsn_debug_counter_stats_reply */
    -1,   /* 26: of_bsn_debug_counter_stats_request */
    -1,   /* 27: of_bsn_flow_checksum_bucket_stats_reply */
    -1,   /* 28: of_bsn_flow_checksum_bucket_stats_request */
    -1,   /* 29: of_bsn_flow_idle */
    -1,   /* 30: of_bsn_flow_idle_enable_get_reply */
    -1,   /* 31: of_bsn_flow_idle_enable_get_request */
    -1,   /* 32: of_bsn_flow_idle_enable_set_reply */
    -1,   /* 33: of_bsn_flow_idle_enable_set_request */
    -1,   /* 34: of_bsn_generic_async */
    -1,   /* 35: of_bsn_generic_stats_reply */
    -1,   /* 36: of_bsn_generic_stats_request */
    -1,   /* 37: of_bsn_gentable_bucket_stats_reply */
    -1,   /* 38: of_bsn_gentable_bucket_stats_request */
    -1,   /* 39: of_bsn_gentable_clear_reply */
    -1,   /* 40: of_bsn_gentable_clear_request */
    -1,   /* 41: of_bsn_gentable_desc_stats_reply */
    -1,   /* 42: of_bsn_gentable_desc_stats_request */
    -1,   /* 43: of_bsn_gentable_entry_add */
    -1,   /* 44: of_bsn_gentable_entry_delete */
    -1,   /* 45: of_bsn_gentable_entry_desc_stats_reply */
    -1,   /* 46: of_bsn_gentable_entry_desc_stats_request */
    -1,   /* 47: of_bsn_gentable_entry_stats_reply */
    -1,   /* 48: of_bsn_gentable_entry_stats_request */
    -1,   /* 49: of_bsn_gentable_set_buckets_size */
    -1,   /* 50: of_bsn_gentable_stats_reply */
    -1,   /* 51: of_bsn_gentable_stats_request */
    16,   /* 52: of_bsn_get_interfaces_reply */
    16,   /* 53: of_bsn_get_interfaces_request */
    -1,   /* 54: of_bsn_get_ip_mask_reply */
    -1,   /* 55: of_bsn_get_ip_mask_request */
    -1,   /* 56: of_bsn_get_l2_table_reply */
    -1,   /* 57: of_bsn_get_l2_table_request */
    20,   /* 58: of_bsn_get_mirroring_reply */
    20,   /* 59: of_bsn_get_mirroring_request */
    -1,   /* 60: of_bsn_get_switch_pipeline_reply */
    -1,   /* 61: of_bsn_get_switch_pipeline_request */
    16,   /* 62: of_bsn_header */
    -1,   /* 63: of_bsn_hybrid_get_reply */
    -1,   /* 64: of_bsn_hybrid_get_request */
    -1,   /* 65: of_bsn_image_desc_stats_reply */
    -1,   /* 66: of_bsn_image_desc_stats_request */
    -1,   /* 67: of_bsn_lacp_convergence_notif */
    -1,   /* 68: of_bsn_lacp_stats_reply */
    -1,   /* 69: of_bsn_lacp_stats_request */
    -1,   /* 70: of_bsn_log */
    -1,   /* 71: of_bsn_lua_command_reply */
    -1,   /* 72: of_bsn_lua_command_request */
    -1,   /* 73: of_bsn_lua_notification */
    -1,   /* 74: of_bsn_lua_upload */
    25,   /* 75: of_bsn_pdu_rx_reply */
    28,   /* 76: of_bsn_pdu_rx_request */
    21,   /* 77: of_bsn_pdu_rx_timeout */
    25,   /* 78: of_bsn_pdu_tx_reply */
    28,   /* 79: of_bsn_pdu_tx_request */
    -1,   /* 80: of_bsn_port_counter_stats_reply */
    -1,   /* 81: of_bsn_port_counter_stats_request */
    -1,   /* 82: of_bsn_role_status */
    -1,   /* 83: of_bsn_set_aux_cxns_reply */
    -1,   /* 84: of_bsn_set_aux_cxns_request */
    -1,   /* 85: of_bsn_set_ip_mask */
    -1,   /* 86: of_bsn_set_l2_table_reply */
    -1,   /* 87: of_bsn_set_l2_table_request */
    -1,   /* 88: of_bsn_set_lacp_reply */
    -1,   /* 89: of_bsn_set_lacp_request */
    20,   /* 90: of_bsn_set_mirroring */
    20,   /* 91: of_bsn_set_pktin_suppression_reply */
    32,   /* 92: of_bsn_set_pktin_suppression_request */
    -1,   /* 93: of_bsn_set_switch_pipeline_reply */
    -1,   /* 94: of_bsn_set_switch_pipeline_request */
    -1,   /* 95: of_bsn_shell_command */
    -1,   /* 96: of_bsn_shell_output */
    -1,   /* 97: of_bsn_shell_status */
    24,   /* 98: of_bsn_stats_reply */
    24,   /* 99: of_bsn_stats_request */
    -1,   /* 100: of_bsn_switch_pipeline_stats_reply */
    -1,   /* 101: of_bsn_switch_pipeline_stats_request */
    -1,   /* 102: of_bsn_table_checksum_stats_reply */
    -1,   /* 103: of_bsn_table_checksum_stats_request */
    -1,   /* 104: of_bsn_table_set_buckets_size */
    -1,   /* 105: of_bsn_takeover */
    -1,   /* 106: of_bsn_time_reply */
    -1,   /* 107: of_bsn_time_request */
    24,   /* 108: of_bsn_virtual_port_create_reply */
    20,   /* 109: of_bsn_virtual_port_create_request */
    20,   /* 110: of_bsn_virtual_port_remove_reply */
    20,   /* 111: of_bsn_virtual_port_remove_request */
    -1,   /* 112: of_bsn_vlan_counter_clear */
    -1,   /* 113: of_bsn_vlan_counter_stats_reply */
    -1,   /* 114: of_bsn_vlan_counter_stats_request */
    -1,   /* 115: of_bsn_vrf_counter_stats_reply */
    -1,   /* 116: of_bsn_vrf_counter_stats_request */
    -1,   /* 117: of_bundle_add_msg */
    -1,   /* 118: of_bundle_ctrl_msg */
    -1,   /* 119: of_bundle_failed_error_msg */
    1072, /* 120: of_desc_stats_reply */
    16,   /* 121: of_desc_stats_request */
    8,    /* 122: of_echo_reply */
    8,    /* 123: of_echo_request */
    10,   /* 124: of_error_msg */
    12,   /* 125: of_experimenter */
    -1,   /* 126: of_experimenter_error_msg */
    24,   /* 127: of_experimenter_stats_reply */
    24,   /* 128: of_experimenter_stats_request */
    32,   /* 129: of_features_reply */
    8,    /* 130: of_features_request */
    136,  /* 131: of_flow_add */
    136,  /* 132: of_flow_delete */
    136,  /* 133: of_flow_delete_strict */
    136,  /* 134: of_flow_mod */
    12,   /* 135: of_flow_mod_failed_error_msg */
    136,  /* 136: of_flow_modify */
    136,  /* 137: of_flow_modify_strict */
    -1,   /* 138: of_flow_monitor_failed_error_msg */
    136,  /* 139: of_flow_removed */
    16,   /* 140: of_flow_stats_reply */
    136,  /* 141: of_flow_stats_request */
    12,   /* 142: of_get_config_reply */
    8,    /* 143: of_get_config_request */
    16,   /* 144: of_group_add */
    16,   /* 145: of_group_delete */
    16,   /* 146: of_group_desc_stats_reply */
    16,   /* 147: of_group_desc_stats_request */
    -1,   /* 148: of_group_features_stats_reply */
    -1,   /* 149: of_group_features_stats_request */
    16,   /* 150: of_group_mod */
    12,   /* 151: of_group_mod_failed_error_msg */
    16,   /* 152: of_group_modify */
    16,   /* 153: of_group_stats_reply */
    24,   /* 154: of_group_stats_request */
    8,    /* 155: of_header */
    8,    /* 156: of_hello */
    12,   /* 157: of_hello_failed_error_msg */
    -1,   /* 158: of_meter_config_stats_reply */
    -1,   /* 159: of_meter_config_stats_request */
    -1,   /* 160: of_meter_features_stats_reply */
    -1,   /* 161: of_meter_features_stats_request */
    -1,   /* 162: of_meter_mod */
    -1,   /* 163: of_meter_mod_failed_error_msg */
    -1,   /* 164: of_meter_stats_reply */
    -1,   /* 165: of_meter_stats_request */
    -1,   /* 166: of_nicira_controller_role_reply */
    -1,   /* 167: of_nicira_controller_role_request */
    16,   /* 168: of_nicira_header */
    24,   /* 169: of_packet_in */
    24,   /* 170: of_packet_out */
    -1,   /* 171: of_port_desc_stats_reply */
    -1,   /* 172: of_port_desc_stats_request */
    40,   /* 173: of_port_mod */
    12,   /* 174: of_port_mod_failed_error_msg */
    16,   /* 175: of_port_stats_reply */
    24,   /* 176: of_port_stats_request */
    80,   /* 177: of_port_status */
    -1,   /* 178: of_queue_desc_stats_reply */
    -1,   /* 179: of_queue_desc_stats_request */
    16,   /* 180: of_queue_get_config_reply */
    16,   /* 181: of_queue_get_config_request */
    12,   /* 182: of_queue_op_failed_error_msg */
    16,   /* 183: of_queue_stats_reply */
    24,   /* 184: of_queue_stats_request */
    -1,   /* 185: of_requestforward */
    -1,   /* 186: of_role_reply */
    -1,   /* 187: of_role_request */
    -1,   /* 188: of_role_request_failed_error_msg */
    -1,   /* 189: of_role_status */
    12,   /* 190: of_set_config */
    16,   /* 191: of_stats_reply */
    16,   /* 192: of_stats_request */
    12,   /* 193: of_switch_config_failed_error_msg */
    -1,   /* 194: of_table_desc_stats_reply */
    -1,   /* 195: of_table_desc_stats_request */
    -1,   /* 196: of_table_features_failed_error_msg */
    -1,   /* 197: of_table_features_stats_reply */
    -1,   /* 198: of_table_features_stats_request */
    16,   /* 199: of_table_mod */
    12,   /* 200: of_table_mod_failed_error_msg */
    16,   /* 201: of_table_stats_reply */
    16,   /* 202: of_table_stats_request */
    -1,   /* 203: of_table_status */
    8,    /* 204: of_action */
    16,   /* 205: of_action_bsn */
    28,   /* 206: of_action_bsn_checksum */
    -1,   /* 207: of_action_bsn_gentable */
    24,   /* 208: of_action_bsn_mirror */
    16,   /* 209: of_action_bsn_set_tunnel_dst */
    8,    /* 210: of_action_copy_ttl_in */
    8,    /* 211: of_action_copy_ttl_out */
    8,    /* 212: of_action_dec_mpls_ttl */
    8,    /* 213: of_action_dec_nw_ttl */
    -1,   /* 214: of_action_enqueue */
    8,    /* 215: of_action_experimenter */
    8,    /* 216: of_action_group */
    -1,   /* 217: of_action_id */
    -1,   /* 218: of_action_id_bsn */
    -1,   /* 219: of_action_id_bsn_checksum */
    -1,   /* 220: of_action_id_bsn_gentable */
    -1,   /* 221: of_action_id_bsn_mirror */
    -1,   /* 222: of_action_id_bsn_set_tunnel_dst */
    -1,   /* 223: of_action_id_copy_ttl_in */
    -1,   /* 224: of_action_id_copy_ttl_out */
    -1,   /* 225: of_action_id_dec_mpls_ttl */
    -1,   /* 226: of_action_id_dec_nw_ttl */
    -1,   /* 227: of_action_id_experimenter */
    -1,   /* 228: of_action_id_group */
    -1,   /* 229: of_action_id_nicira */
    -1,   /* 230: of_action_id_nicira_dec_ttl */
    -1,   /* 231: of_action_id_output */
    -1,   /* 232: of_action_id_pop_mpls */
    -1,   /* 233: of_action_id_pop_pbb */
    -1,   /* 234: of_action_id_pop_vlan */
    -1,   /* 235: of_action_id_push_mpls */
    -1,   /* 236: of_action_id_push_pbb */
    -1,   /* 237: of_action_id_push_vlan */
    -1,   /* 238: of_action_id_set_field */
    -1,   /* 239: of_action_id_set_mpls_ttl */
    -1,   /* 240: of_action_id_set_nw_ttl */
    -1,   /* 241: of_action_id_set_queue */
    16,   /* 242: of_action_nicira */
    16,   /* 243: of_action_nicira_dec_ttl */
    16,   /* 244: of_action_output */
    8,    /* 245: of_action_pop_mpls */
    -1,   /* 246: of_action_pop_pbb */
    8,    /* 247: of_action_pop_vlan */
    8,    /* 248: of_action_push_mpls */
    -1,   /* 249: of_action_push_pbb */
    8,    /* 250: of_action_push_vlan */
    16,   /* 251: of_action_set_dl_dst */
    16,   /* 252: of_action_set_dl_src */
    -1,   /* 253: of_action_set_field */
    8,    /* 254: of_action_set_mpls_label */
    8,    /* 255: of_action_set_mpls_tc */
    8,    /* 256: of_action_set_mpls_ttl */
    8,    /* 257: of_action_set_nw_dst */
    8,    /* 258: of_action_set_nw_ecn */
    8,    /* 259: of_action_set_nw_src */
    8,    /* 260: of_action_set_nw_tos */
    8,    /* 261: of_action_set_nw_ttl */
    8,    /* 262: of_action_set_queue */
    8,    /* 263: of_action_set_tp_dst */
    8,    /* 264: of_action_set_tp_src */
    8,    /* 265: of_action_set_vlan_pcp */
    8,    /* 266: of_action_set_vlan_vid */
    -1,   /* 267: of_action_strip_vlan */
    -1,   /* 268: of_async_config_prop */
    -1,   /* 269: of_async_config_prop_experimenter_master */
    -1,   /* 270: of_async_config_prop_experimenter_slave */
    -1,   /* 271: of_async_config_prop_flow_removed_master */
    -1,   /* 272: of_async_config_prop_flow_removed_slave */
    -1,   /* 273: of_async_config_prop_packet_in_master */
    -1,   /* 274: of_async_config_prop_packet_in_slave */
    -1,   /* 275: of_async_config_prop_port_status_master */
    -1,   /* 276: of_async_config_prop_port_status_slave */
    -1,   /* 277: of_async_config_prop_requestforward_master */
    -1,   /* 278: of_async_config_prop_requestforward_slave */
    -1,   /* 279: of_async_config_prop_role_status_master */
    -1,   /* 280: of_async_config_prop_role_status_slave */
    -1,   /* 281: of_async_config_prop_table_status_master */
    -1,   /* 282: of_async_config_prop_table_status_slave */
    -1,   /* 283: of_bsn_controller_connection */
    -1,   /* 284: of_bsn_debug_counter_desc_stats_entry */
    -1,   /* 285: of_bsn_debug_counter_stats_entry */
    -1,   /* 286: of_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 287: of_bsn_generic_stats_entry */
    -1,   /* 288: of_bsn_gentable_bucket_stats_entry */
    -1,   /* 289: of_bsn_gentable_desc_stats_entry */
    -1,   /* 290: of_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 291: of_bsn_gentable_entry_stats_entry */
    -1,   /* 292: of_bsn_gentable_stats_entry */
    32,   /* 293: of_bsn_interface */
    -1,   /* 294: of_bsn_lacp_stats_entry */
    -1,   /* 295: of_bsn_port_counter_stats_entry */
    -1,   /* 296: of_bsn_switch_pipeline_stats_entry */
    -1,   /* 297: of_bsn_table_checksum_stats_entry */
    -1,   /* 298: of_bsn_tlv */
    -1,   /* 299: of_bsn_tlv_actor_key */
    -1,   /* 300: of_bsn_tlv_actor_port_num */
    -1,   /* 301: of_bsn_tlv_actor_port_priority */
    -1,   /* 302: of_bsn_tlv_actor_state */
    -1,   /* 303: of_bsn_tlv_actor_system_mac */
    -1,   /* 304: of_bsn_tlv_actor_system_priority */
    -1,   /* 305: of_bsn_tlv_anchor */
    -1,   /* 306: of_bsn_tlv_broadcast_query_timeout */
    -1,   /* 307: of_bsn_tlv_broadcast_rate */
    -1,   /* 308: of_bsn_tlv_bucket */
    -1,   /* 309: of_bsn_tlv_circuit_id */
    -1,   /* 310: of_bsn_tlv_convergence_status */
    -1,   /* 311: of_bsn_tlv_crc_enabled */
    -1,   /* 312: of_bsn_tlv_data */
    -1,   /* 313: of_bsn_tlv_decap */
    -1,   /* 314: of_bsn_tlv_eth_dst */
    -1,   /* 315: of_bsn_tlv_eth_src */
    -1,   /* 316: of_bsn_tlv_external_gateway_ip */
    -1,   /* 317: of_bsn_tlv_external_gateway_mac */
    -1,   /* 318: of_bsn_tlv_external_ip */
    -1,   /* 319: of_bsn_tlv_external_mac */
    -1,   /* 320: of_bsn_tlv_external_netmask */
    -1,   /* 321: of_bsn_tlv_generation_id */
    -1,   /* 322: of_bsn_tlv_header_size */
    -1,   /* 323: of_bsn_tlv_icmp_code */
    -1,   /* 324: of_bsn_tlv_icmp_id */
    -1,   /* 325: of_bsn_tlv_icmp_type */
    -1,   /* 326: of_bsn_tlv_idle_notification */
    -1,   /* 327: of_bsn_tlv_idle_time */
    -1,   /* 328: of_bsn_tlv_idle_timeout */
    -1,   /* 329: of_bsn_tlv_igmp_snooping */
    -1,   /* 330: of_bsn_tlv_internal_gateway_mac */
    -1,   /* 331: of_bsn_tlv_internal_mac */
    -1,   /* 332: of_bsn_tlv_interval */
    -1,   /* 333: of_bsn_tlv_ip_proto */
    -1,   /* 334: of_bsn_tlv_ipv4 */
    -1,   /* 335: of_bsn_tlv_ipv4_dst */
    -1,   /* 336: of_bsn_tlv_ipv4_netmask */
    -1,   /* 337: of_bsn_tlv_ipv4_src */
    -1,   /* 338: of_bsn_tlv_ipv6 */
    -1,   /* 339: of_bsn_tlv_known_multicast_rate */
    -1,   /* 340: of_bsn_tlv_l2_multicast_lookup */
    -1,   /* 341: of_bsn_tlv_mac */
    -1,   /* 342: of_bsn_tlv_mac_mask */
    -1,   /* 343: of_bsn_tlv_mcg_type_vxlan */
    -1,   /* 344: of_bsn_tlv_miss_packets */
    -1,   /* 345: of_bsn_tlv_mpls_control_word */
    -1,   /* 346: of_bsn_tlv_mpls_label */
    -1,   /* 347: of_bsn_tlv_mpls_sequenced */
    -1,   /* 348: of_bsn_tlv_multicast_interface_id */
    -1,   /* 349: of_bsn_tlv_name */
    -1,   /* 350: of_bsn_tlv_negate */
    -1,   /* 351: of_bsn_tlv_nexthop_type_vxlan */
    -1,   /* 352: of_bsn_tlv_offset */
    -1,   /* 353: of_bsn_tlv_partner_key */
    -1,   /* 354: of_bsn_tlv_partner_port_num */
    -1,   /* 355: of_bsn_tlv_partner_port_priority */
    -1,   /* 356: of_bsn_tlv_partner_state */
    -1,   /* 357: of_bsn_tlv_partner_system_mac */
    -1,   /* 358: of_bsn_tlv_partner_system_priority */
    -1,   /* 359: of_bsn_tlv_port */
    -1,   /* 360: of_bsn_tlv_port_vxlan_mode */
    -1,   /* 361: of_bsn_tlv_priority */
    -1,   /* 362: of_bsn_tlv_queue_id */
    -1,   /* 363: of_bsn_tlv_queue_weight */
    -1,   /* 364: of_bsn_tlv_rate_unit */
    -1,   /* 365: of_bsn_tlv_reference */
    -1,   /* 366: of_bsn_tlv_reply_packets */
    -1,   /* 367: of_bsn_tlv_request_packets */
    -1,   /* 368: of_bsn_tlv_rx_bytes */
    -1,   /* 369: of_bsn_tlv_rx_packets */
    -1,   /* 370: of_bsn_tlv_sampling_rate */
    -1,   /* 371: of_bsn_tlv_set_loopback_mode */
    -1,   /* 372: of_bsn_tlv_strip_mpls_l2_on_ingress */
    -1,   /* 373: of_bsn_tlv_strip_mpls_l3_on_ingress */
    -1,   /* 374: of_bsn_tlv_strip_vlan_on_egress */
    -1,   /* 375: of_bsn_tlv_sub_agent_id */
    -1,   /* 376: of_bsn_tlv_tcp_dst */
    -1,   /* 377: of_bsn_tlv_tcp_src */
    -1,   /* 378: of_bsn_tlv_tx_bytes */
    -1,   /* 379: of_bsn_tlv_tx_packets */
    -1,   /* 380: of_bsn_tlv_udf_anchor */
    -1,   /* 381: of_bsn_tlv_udf_id */
    -1,   /* 382: of_bsn_tlv_udf_length */
    -1,   /* 383: of_bsn_tlv_udf_offset */
    -1,   /* 384: of_bsn_tlv_udp_dst */
    -1,   /* 385: of_bsn_tlv_udp_src */
    -1,   /* 386: of_bsn_tlv_unicast_query_timeout */
    -1,   /* 387: of_bsn_tlv_unicast_rate */
    -1,   /* 388: of_bsn_tlv_unknown_multicast_rate */
    -1,   /* 389: of_bsn_tlv_vlan_pcp */
    -1,   /* 390: of_bsn_tlv_vlan_vid */
    -1,   /* 391: of_bsn_tlv_vlan_vid_mask */
    -1,   /* 392: of_bsn_tlv_vni */
    -1,   /* 393: of_bsn_tlv_vrf */
    -1,   /* 394: of_bsn_vlan_counter_stats_entry */
    4,    /* 395: of_bsn_vport */
    64,   /* 396: of_bsn_vport_l2gre */
    32,   /* 397: of_bsn_vport_q_in_q */
    -1,   /* 398: of_bsn_vrf_counter_stats_entry */
    16,   /* 399: of_bucket */
    16,   /* 400: of_bucket_counter */
    -1,   /* 401: of_bundle_prop */
    -1,   /* 402: of_bundle_prop_experimenter */
    136,  /* 403: of_flow_stats_entry */
    8,    /* 404: of_group_desc_stats_entry */
    32,   /* 405: of_group_stats_entry */
    -1,   /* 406: of_hello_elem */
    -1,   /* 407: of_hello_elem_versionbitmap */
    8,    /* 408: of_instruction */
    8,    /* 409: of_instruction_apply_actions */
    -1,   /* 410: of_instruction_bsn */
    -1,   /* 411: of_instruction_bsn_arp_offload */
    -1,   /* 412: of_instruction_bsn_auto_negotiation */
    -1,   /* 413: of_instruction_bsn_deny */
    -1,   /* 414: of_instruction_bsn_dhcp_offload */
    -1,   /* 415: of_instruction_bsn_disable_l3 */
    -1,   /* 416: of_instruction_bsn_disable_split_horizon_check */
    -1,   /* 417: of_instruction_bsn_disable_src_mac_check */
    -1,   /* 418: of_instruction_bsn_disable_vlan_counters */
    -1,   /* 419: of_instruction_bsn_internal_priority */
    -1,   /* 420: of_instruction_bsn_packet_of_death */
    -1,   /* 421: of_instruction_bsn_permit */
    -1,   /* 422: of_instruction_bsn_prioritize_pdus */
    -1,   /* 423: of_instruction_bsn_require_vlan_xlate */
    -1,   /* 424: of_instruction_bsn_span_destination */
    8,    /* 425: of_instruction_clear_actions */
    8,    /* 426: of_instruction_experimenter */
    8,    /* 427: of_instruction_goto_table */
    -1,   /* 428: of_instruction_id */
    -1,   /* 429: of_instruction_id_apply_actions */
    -1,   /* 430: of_instruction_id_bsn */
    -1,   /* 431: of_instruction_id_bsn_arp_offload */
    -1,   /* 432: of_instruction_id_bsn_auto_negotiation */
    -1,   /* 433: of_instruction_id_bsn_deny */
    -1,   /* 434: of_instruction_id_bsn_dhcp_offload */
    -1,   /* 435: of_instruction_id_bsn_disable_l3 */
    -1,   /* 436: of_instruction_id_bsn_disable_split_horizon_check */
    -1,   /* 437: of_instruction_id_bsn_disable_src_mac_check */
    -1,   /* 438: of_instruction_id_bsn_disable_vlan_counters */
    -1,   /* 439: of_instruction_id_bsn_internal_priority */
    -1,   /* 440: of_instruction_id_bsn_packet_of_death */
    -1,   /* 441: of_instruction_id_bsn_permit */
    -1,   /* 442: of_instruction_id_bsn_prioritize_pdus */
    -1,   /* 443: of_instruction_id_bsn_require_vlan_xlate */
    -1,   /* 444: of_instruction_id_bsn_span_destination */
    -1,   /* 445: of_instruction_id_clear_actions */
    -1,   /* 446: of_instruction_id_experimenter */
    -1,   /* 447: of_instruction_id_goto_table */
    -1,   /* 448: of_instruction_id_meter */
    -1,   /* 449: of_instruction_id_write_actions */
    -1,   /* 450: of_instruction_id_write_metadata */
    -1,   /* 451: of_instruction_meter */
    8,    /* 452: of_instruction_write_actions */
    24,   /* 453: of_instruction_write_metadata */
    -1,   /* 454: of_match_v1 */
    88,   /* 455: of_match_v2 */
    -1,   /* 456: of_match_v3 */
    -1,   /* 457: of_meter_band */
    -1,   /* 458: of_meter_band_drop */
    -1,   /* 459: of_meter_band_dscp_remark */
    -1,   /* 460: of_meter_band_experimenter */
    -1,   /* 461: of_meter_band_stats */
    -1,   /* 462: of_meter_config */
    -1,   /* 463: of_meter_features */
    -1,   /* 464: of_meter_stats */
    -1,   /* 465: of_oxm */
    -1,   /* 466: of_oxm_arp_op */
    -1,   /* 467: of_oxm_arp_op_masked */
    -1,   /* 468: of_oxm_arp_sha */
    -1,   /* 469: of_oxm_arp_sha_masked */
    -1,   /* 470: of_oxm_arp_spa */
    -1,   /* 471: of_oxm_arp_spa_masked */
    -1,   /* 472: of_oxm_arp_tha */
    -1,   /* 473: of_oxm_arp_tha_masked */
    -1,   /* 474: of_oxm_arp_tpa */
    -1,   /* 475: of_oxm_arp_tpa_masked */
    -1,   /* 476: of_oxm_bsn_egr_port_group_id */
    -1,   /* 477: of_oxm_bsn_egr_port_group_id_masked */
    -1,   /* 478: of_oxm_bsn_global_vrf_allowed */
    -1,   /* 479: of_oxm_bsn_global_vrf_allowed_masked */
    -1,   /* 480: of_oxm_bsn_in_ports_128 */
    -1,   /* 481: of_oxm_bsn_in_ports_128_masked */
    -1,   /* 482: of_oxm_bsn_in_ports_512 */
    -1,   /* 483: of_oxm_bsn_in_ports_512_masked */
    -1,   /* 484: of_oxm_bsn_ingress_port_group_id */
    -1,   /* 485: of_oxm_bsn_ingress_port_group_id_masked */
    -1,   /* 486: of_oxm_bsn_inner_eth_dst */
    -1,   /* 487: of_oxm_bsn_inner_eth_dst_masked */
    -1,   /* 488: of_oxm_bsn_inner_eth_src */
    -1,   /* 489: of_oxm_bsn_inner_eth_src_masked */
    -1,   /* 490: of_oxm_bsn_inner_vlan_vid */
    -1,   /* 491: of_oxm_bsn_inner_vlan_vid_masked */
    -1,   /* 492: of_oxm_bsn_l2_cache_hit */
    -1,   /* 493: of_oxm_bsn_l2_cache_hit_masked */
    -1,   /* 494: of_oxm_bsn_l3_dst_class_id */
    -1,   /* 495: of_oxm_bsn_l3_dst_class_id_masked */
    -1,   /* 496: of_oxm_bsn_l3_interface_class_id */
    -1,   /* 497: of_oxm_bsn_l3_interface_class_id_masked */
    -1,   /* 498: of_oxm_bsn_l3_src_class_id */
    -1,   /* 499: of_oxm_bsn_l3_src_class_id_masked */
    -1,   /* 500: of_oxm_bsn_lag_id */
    -1,   /* 501: of_oxm_bsn_lag_id_masked */
    -1,   /* 502: of_oxm_bsn_tcp_flags */
    -1,   /* 503: of_oxm_bsn_tcp_flags_masked */
    -1,   /* 504: of_oxm_bsn_udf0 */
    -1,   /* 505: of_oxm_bsn_udf0_masked */
    -1,   /* 506: of_oxm_bsn_udf1 */
    -1,   /* 507: of_oxm_bsn_udf1_masked */
    -1,   /* 508: of_oxm_bsn_udf2 */
    -1,   /* 509: of_oxm_bsn_udf2_masked */
    -1,   /* 510: of_oxm_bsn_udf3 */
    -1,   /* 511: of_oxm_bsn_udf3_masked */
    -1,   /* 512: of_oxm_bsn_udf4 */
    -1,   /* 513: of_oxm_bsn_udf4_masked */
    -1,   /* 514: of_oxm_bsn_udf5 */
    -1,   /* 515: of_oxm_bsn_udf5_masked */
    -1,   /* 516: of_oxm_bsn_udf6 */
    -1,   /* 517: of_oxm_bsn_udf6_masked */
    -1,   /* 518: of_oxm_bsn_udf7 */
    -1,   /* 519: of_oxm_bsn_udf7_masked */
    -1,   /* 520: of_oxm_bsn_vlan_xlate_port_group_id */
    -1,   /* 521: of_oxm_bsn_vlan_xlate_port_group_id_masked */
    -1,   /* 522: of_oxm_bsn_vrf */
    -1,   /* 523: of_oxm_bsn_vrf_masked */
    -1,   /* 524: of_oxm_bsn_vxlan_network_id */
    -1,   /* 525: of_oxm_bsn_vxlan_network_id_masked */
    -1,   /* 526: of_oxm_eth_dst */
    -1,   /* 527: of_oxm_eth_dst_masked */
    -1,   /* 528: of_oxm_eth_src */
    -1,   /* 529: of_oxm_eth_src_masked */
    -1,   /* 530: of_oxm_eth_type */
    -1,   /* 531: of_oxm_eth_type_masked */
    -1,   /* 532: of_oxm_icmpv4_code */
    -1,   /* 533: of_oxm_icmpv4_code_masked */
    -1,   /* 534: of_oxm_icmpv4_type */
    -1,   /* 535: of_oxm_icmpv4_type_masked */
    -1,   /* 536: of_oxm_icmpv6_code */
    -1,   /* 537: of_oxm_icmpv6_code_masked */
    -1,   /* 538: of_oxm_icmpv6_type */
    -1,   /* 539: of_oxm_icmpv6_type_masked */
    -1,   /* 540: of_oxm_in_phy_port */
    -1,   /* 541: of_oxm_in_phy_port_masked */
    -1,   /* 542: of_oxm_in_port */
    -1,   /* 543: of_oxm_in_port_masked */
    -1,   /* 544: of_oxm_ip_dscp */
    -1,   /* 545: of_oxm_ip_dscp_masked */
    -1,   /* 546: of_oxm_ip_ecn */
    -1,   /* 547: of_oxm_ip_ecn_masked */
    -1,   /* 548: of_oxm_ip_proto */
    -1,   /* 549: of_oxm_ip_proto_masked */
    -1,   /* 550: of_oxm_ipv4_dst */
    -1,   /* 551: of_oxm_ipv4_dst_masked */
    -1,   /* 552: of_oxm_ipv4_src */
    -1,   /* 553: of_oxm_ipv4_src_masked */
    -1,   /* 554: of_oxm_ipv6_dst */
    -1,   /* 555: of_oxm_ipv6_dst_masked */
    -1,   /* 556: of_oxm_ipv6_exthdr */
    -1,   /* 557: of_oxm_ipv6_exthdr_masked */
    -1,   /* 558: of_oxm_ipv6_flabel */
    -1,   /* 559: of_oxm_ipv6_flabel_masked */
    -1,   /* 560: of_oxm_ipv6_nd_sll */
    -1,   /* 561: of_oxm_ipv6_nd_sll_masked */
    -1,   /* 562: of_oxm_ipv6_nd_target */
    -1,   /* 563: of_oxm_ipv6_nd_target_masked */
    -1,   /* 564: of_oxm_ipv6_nd_tll */
    -1,   /* 565: of_oxm_ipv6_nd_tll_masked */
    -1,   /* 566: of_oxm_ipv6_src */
    -1,   /* 567: of_oxm_ipv6_src_masked */
    -1,   /* 568: of_oxm_metadata */
    -1,   /* 569: of_oxm_metadata_masked */
    -1,   /* 570: of_oxm_mpls_bos */
    -1,   /* 571: of_oxm_mpls_bos_masked */
    -1,   /* 572: of_oxm_mpls_label */
    -1,   /* 573: of_oxm_mpls_label_masked */
    -1,   /* 574: of_oxm_mpls_tc */
    -1,   /* 575: of_oxm_mpls_tc_masked */
    -1,   /* 576: of_oxm_pbb_uca */
    -1,   /* 577: of_oxm_pbb_uca_masked */
    -1,   /* 578: of_oxm_sctp_dst */
    -1,   /* 579: of_oxm_sctp_dst_masked */
    -1,   /* 580: of_oxm_sctp_src */
    -1,   /* 581: of_oxm_sctp_src_masked */
    -1,   /* 582: of_oxm_tcp_dst */
    -1,   /* 583: of_oxm_tcp_dst_masked */
    -1,   /* 584: of_oxm_tcp_src */
    -1,   /* 585: of_oxm_tcp_src_masked */
    -1,   /* 586: of_oxm_tunnel_id */
    -1,   /* 587: of_oxm_tunnel_id_masked */
    -1,   /* 588: of_oxm_tunnel_ipv4_dst */
    -1,   /* 589: of_oxm_tunnel_ipv4_dst_masked */
    -1,   /* 590: of_oxm_tunnel_ipv4_src */
    -1,   /* 591: of_oxm_tunnel_ipv4_src_masked */
    -1,   /* 592: of_oxm_udp_dst */
    -1,   /* 593: of_oxm_udp_dst_masked */
    -1,   /* 594: of_oxm_udp_src */
    -1,   /* 595: of_oxm_udp_src_masked */
    -1,   /* 596: of_oxm_vlan_pcp */
    -1,   /* 597: of_oxm_vlan_pcp_masked */
    -1,   /* 598: of_oxm_vlan_vid */
    -1,   /* 599: of_oxm_vlan_vid_masked */
    8,    /* 600: of_packet_queue */
    64,   /* 601: of_port_desc */
    -1,   /* 602: of_port_desc_prop */
    -1,   /* 603: of_port_desc_prop_bsn */
    -1,   /* 604: of_port_desc_prop_bsn_generation_id */
    -1,   /* 605: of_port_desc_prop_bsn_uplink */
    -1,   /* 606: of_port_desc_prop_ethernet */
    -1,   /* 607: of_port_desc_prop_experimenter */
    -1,   /* 608: of_port_desc_prop_optical */
    -1,   /* 609: of_port_mod_prop */
    -1,   /* 610: of_port_mod_prop_ethernet */
    -1,   /* 611: of_port_mod_prop_experimenter */
    -1,   /* 612: of_port_mod_prop_optical */
    104,  /* 613: of_port_stats_entry */
    -1,   /* 614: of_port_stats_prop */
    -1,   /* 615: of_port_stats_prop_ethernet */
    -1,   /* 616: of_port_stats_prop_experimenter */
    -1,   /* 617: of_port_stats_prop_optical */
    -1,   /* 618: of_queue_desc */
    -1,   /* 619: of_queue_desc_prop */
    -1,   /* 620: of_queue_desc_prop_experimenter */
    -1,   /* 621: of_queue_desc_prop_max_rate */
    -1,   /* 622: of_queue_desc_prop_min_rate */
    8,    /* 623: of_queue_prop */
    -1,   /* 624: of_queue_prop_experimenter */
    -1,   /* 625: of_queue_prop_max_rate */
    16,   /* 626: of_queue_prop_min_rate */
    32,   /* 627: of_queue_stats_entry */
    -1,   /* 628: of_queue_stats_prop */
    -1,   /* 629: of_queue_stats_prop_experimenter */
    -1,   /* 630: of_role_prop */
    -1,   /* 631: of_role_prop_experimenter */
    -1,   /* 632: of_table_desc */
    -1,   /* 633: of_table_feature_prop */
    -1,   /* 634: of_table_feature_prop_apply_actions */
    -1,   /* 635: of_table_feature_prop_apply_actions_miss */
    -1,   /* 636: of_table_feature_prop_apply_setfield */
    -1,   /* 637: of_table_feature_prop_apply_setfield_miss */
    -1,   /* 638: of_table_feature_prop_experimenter */
    -1,   /* 639: of_table_feature_prop_experimenter_miss */
    -1,   /* 640: of_table_feature_prop_instructions */
    -1,   /* 641: of_table_feature_prop_instructions_miss */
    -1,   /* 642: of_table_feature_prop_match */
    -1,   /* 643: of_table_feature_prop_next_tables */
    -1,   /* 644: of_table_feature_prop_next_tables_miss */
    -1,   /* 645: of_table_feature_prop_table_sync_from */
    -1,   /* 646: of_table_feature_prop_wildcards */
    -1,   /* 647: of_table_feature_prop_write_actions */
    -1,   /* 648: of_table_feature_prop_write_actions_miss */
    -1,   /* 649: of_table_feature_prop_write_setfield */
    -1,   /* 650: of_table_feature_prop_write_setfield_miss */
    -1,   /* 651: of_table_features */
    -1,   /* 652: of_table_mod_prop */
    -1,   /* 653: of_table_mod_prop_eviction */
    -1,   /* 654: of_table_mod_prop_experimenter */
    -1,   /* 655: of_table_mod_prop_vacancy */
    88,   /* 656: of_table_stats_entry */
    -1,   /* 657: of_uint32 */
    -1,   /* 658: of_uint64 */
    -1,   /* 659: of_uint8 */
    0,    /* 660: of_list_action */
    -1,   /* 661: of_list_action_id */
    -1,   /* 662: of_list_async_config_prop */
    -1,   /* 663: of_list_bsn_controller_connection */
    -1,   /* 664: of_list_bsn_debug_counter_desc_stats_entry */
    -1,   /* 665: of_list_bsn_debug_counter_stats_entry */
    -1,   /* 666: of_list_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 667: of_list_bsn_generic_stats_entry */
    -1,   /* 668: of_list_bsn_gentable_bucket_stats_entry */
    -1,   /* 669: of_list_bsn_gentable_desc_stats_entry */
    -1,   /* 670: of_list_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 671: of_list_bsn_gentable_entry_stats_entry */
    -1,   /* 672: of_list_bsn_gentable_stats_entry */
    0,    /* 673: of_list_bsn_interface */
    -1,   /* 674: of_list_bsn_lacp_stats_entry */
    -1,   /* 675: of_list_bsn_port_counter_stats_entry */
    -1,   /* 676: of_list_bsn_switch_pipeline_stats_entry */
    -1,   /* 677: of_list_bsn_table_checksum_stats_entry */
    -1,   /* 678: of_list_bsn_tlv */
    -1,   /* 679: of_list_bsn_vlan_counter_stats_entry */
    -1,   /* 680: of_list_bsn_vrf_counter_stats_entry */
    0,    /* 681: of_list_bucket */
    0,    /* 682: of_list_bucket_counter */
    -1,   /* 683: of_list_bundle_prop */
    0,    /* 684: of_list_flow_stats_entry */
    0,    /* 685: of_list_group_desc_stats_entry */
    0,    /* 686: of_list_group_stats_entry */
    -1,   /* 687: of_list_hello_elem */
    0,    /* 688: of_list_instruction */
    -1,   /* 689: of_list_instruction_id */
    -1,   /* 690: of_list_meter_band */
    -1,   /* 691: of_list_meter_band_stats */
    -1,   /* 692: of_list_meter_config */
    -1,   /* 693: of_list_meter_stats */
    -1,   /* 694: of_list_oxm */
    0,    /* 695: of_list_packet_queue */
    0,    /* 696: of_list_port_desc */
    -1,   /* 697: of_list_port_desc_prop */
    -1,   /* 698: of_list_port_mod_prop */
    0,    /* 699: of_list_port_stats_entry */
    -1,   /* 700: of_list_port_stats_prop */
    -1,   /* 701: of_list_queue_desc */
    -1,   /* 702: of_list_queue_desc_prop */
    0,    /* 703: of_list_queue_prop */
    0,    /* 704: of_list_queue_stats_entry */
    -1,   /* 705: of_list_queue_stats_prop */
    -1,   /* 706: of_list_role_prop */
    -1,   /* 707: of_list_table_desc */
    -1,   /* 708: of_list_table_feature_prop */
    -1,   /* 709: of_list_table_features */
    -1,   /* 710: of_list_table_mod_prop */
    0,    /* 711: of_list_table_stats_entry */
    -1,   /* 712: of_list_uint32 */
    -1,   /* 713: of_list_uint64 */
    -1    /* 714: of_list_uint8 */
};

static const int
of_object_fixed_len_v3[OF_OBJECT_COUNT] = {
    -1,   /* of_object is not instantiable */
    40,   /* 1: of_aggregate_stats_reply */
    56,   /* 2: of_aggregate_stats_request */
    -1,   /* 3: of_async_config_failed_error_msg */
    -1,   /* 4: of_async_get_reply */
    -1,   /* 5: of_async_get_request */
    -1,   /* 6: of_async_set */
    12,   /* 7: of_bad_action_error_msg */
    12,   /* 8: of_bad_instruction_error_msg */
    12,   /* 9: of_bad_match_error_msg */
    -1,   /* 10: of_bad_property_error_msg */
    12,   /* 11: of_bad_request_error_msg */
    8,    /* 12: of_barrier_reply */
    8,    /* 13: of_barrier_request */
    -1,   /* 14: of_bsn_arp_idle */
    20,   /* 15: of_bsn_bw_clear_data_reply */
    16,   /* 16: of_bsn_bw_clear_data_request */
    20,   /* 17: of_bsn_bw_enable_get_reply */
    16,   /* 18: of_bsn_bw_enable_get_request */
    24,   /* 19: of_bsn_bw_enable_set_reply */
    20,   /* 20: of_bsn_bw_enable_set_request */
    -1,   /* 21: of_bsn_controller_connections_reply */
    -1,   /* 22: of_bsn_controller_connections_request */
    -1,   /* 23: of_bsn_debug_counter_desc_stats_reply */
    -1,   /* 24: of_bsn_debug_counter_desc_stats_request */
    -1,   /* 25: of_bsn_debug_counter_stats_reply */
    -1,   /* 26: of_bsn_debug_counter_stats_request */
    -1,   /* 27: of_bsn_flow_checksum_bucket_stats_reply */
    -1,   /* 28: of_bsn_flow_checksum_bucket_stats_request */
    -1,   /* 29: of_bsn_flow_idle */
    -1,   /* 30: of_bsn_flow_idle_enable_get_reply */
    -1,   /* 31: of_bsn_flow_idle_enable_get_request */
    -1,   /* 32: of_bsn_flow_idle_enable_set_reply */
    -1,   /* 33: of_bsn_flow_idle_enable_set_request */
    -1,   /* 34: of_bsn_generic_async */
    -1,   /* 35: of_bsn_generic_stats_reply */
    -1,   /* 36: of_bsn_generic_stats_request */
    -1,   /* 37: of_bsn_gentable_bucket_stats_reply */
    -1,   /* 38: of_bsn_gentable_bucket_stats_request */
    -1,   /* 39: of_bsn_gentable_clear_reply */
    -1,   /* 40: of_bsn_gentable_clear_request */
    -1,   /* 41: of_bsn_gentable_desc_stats_reply */
    -1,   /* 42: of_bsn_gentable_desc_stats_request */
    -1,   /* 43: of_bsn_gentable_entry_add */
    -1,   /* 44: of_bsn_gentable_entry_delete */
    -1,   /* 45: of_bsn_gentable_entry_desc_stats_reply */
    -1,   /* 46: of_bsn_gentable_entry_desc_stats_request */
    -1,   /* 47: of_bsn_gentable_entry_stats_reply */
    -1,   /* 48: of_bsn_gentable_entry_stats_request */
    -1,   /* 49: of_bsn_gentable_set_buckets_size */
    -1,   /* 50: of_bsn_gentable_stats_reply */
    -1,   /* 51: of_bsn_gentable_stats_request */
    16,   /* 52: of_bsn_get_interfaces_reply */
    16,   /* 53: of_bsn_get_interfaces_request */
    -1,   /* 54: of_bsn_get_ip_mask_reply */
    -1,   /* 55: of_bsn_get_ip_mask_request */
    -1,   /* 56: of_bsn_get_l2_table_reply */
    -1,   /* 57: of_bsn_get_l2_table_request */
    20,   /* 58: of_bsn_get_mirroring_reply */
    20,   /* 59: of_bsn_get_mirroring_request */
    -1,   /* 60: of_bsn_get_switch_pipeline_reply */
    -1,   /* 61: of_bsn_get_switch_pipeline_request */
    16,   /* 62: of_bsn_header */
    -1,   /* 63: of_bsn_hybrid_get_reply */
    -1,   /* 64: of_bsn_hybrid_get_request */
    -1,   /* 65: of_bsn_image_desc_stats_reply */
    -1,   /* 66: of_bsn_image_desc_stats_request */
    -1,   /* 67: of_bsn_lacp_convergence_notif */
    -1,   /* 68: of_bsn_lacp_stats_reply */
    -1,   /* 69: of_bsn_lacp_stats_request */
    -1,   /* 70: of_bsn_log */
    -1,   /* 71: of_bsn_lua_command_reply */
    -1,   /* 72: of_bsn_lua_command_request */
    -1,   /* 73: of_bsn_lua_notification */
    -1,   /* 74: of_bsn_lua_upload */
    25,   /* 75: of_bsn_pdu_rx_reply */
    28,   /* 76: of_bsn_pdu_rx_request */
    21,   /* 77: of_bsn_pdu_rx_timeout */
    25,   /* 78: of_bsn_pdu_tx_reply */
    28,   /* 79: of_bsn_pdu_tx_request */
    -1,   /* 80: of_bsn_port_counter_stats_reply */
    -1,   /* 81: of_bsn_port_counter_stats_request */
    -1,   /* 82: of_bsn_role_status */
    -1,   /* 83: of_bsn_set_aux_cxns_reply */
    -1,   /* 84: of_bsn_set_aux_cxns_request */
    -1,   /* 85: of_bsn_set_ip_mask */
    -1,   /* 86: of_bsn_set_l2_table_reply */
    -1,   /* 87: of_bsn_set_l2_table_request */
    -1,   /* 88: of_bsn_set_lacp_reply */
    -1,   /* 89: of_bsn_set_lacp_request */
    20,   /* 90: of_bsn_set_mirroring */
    20,   /* 91: of_bsn_set_pktin_suppression_reply */
    32,   /* 92: of_bsn_set_pktin_suppression_request */
    -1,   /* 93: of_bsn_set_switch_pipeline_reply */
    -1,   /* 94: of_bsn_set_switch_pipeline_request */
    -1,   /* 95: of_bsn_shell_command */
    -1,   /* 96: of_bsn_shell_output */
    -1,   /* 97: of_bsn_shell_status */
    24,   /* 98: of_bsn_stats_reply */
    24,   /* 99: of_bsn_stats_request */
    -1,   /* 100: of_bsn_switch_pipeline_stats_reply */
    -1,   /* 101: of_bsn_switch_pipeline_stats_request */
    -1,   /* 102: of_bsn_table_checksum_stats_reply */
    -1,   /* 103: of_bsn_table_checksum_stats_request */
    -1,   /* 104: of_bsn_table_set_buckets_size */
    -1,   /* 105: of_bsn_takeover */
    -1,   /* 106: of_bsn_time_reply */
    -1,   /* 107: of_bsn_time_request */
    24,   /* 108: of_bsn_virtual_port_create_reply */
    20,   /* 109: of_bsn_virtual_port_create_request */
    20,   /* 110: of_bsn_virtual_port_remove_reply */
    20,   /* 111: of_bsn_virtual_port_remove_request */
    -1,   /* 112: of_bsn_vlan_counter_clear */
    -1,   /* 113: of_bsn_vlan_counter_stats_reply */
    -1,   /* 114: of_bsn_vlan_counter_stats_request */
    -1,   /* 115: of_bsn_vrf_counter_stats_reply */
    -1,   /* 116: of_bsn_vrf_counter_stats_request */
    -1,   /* 117: of_bundle_add_msg */
    -1,   /* 118: of_bundle_ctrl_msg */
    -1,   /* 119: of_bundle_failed_error_msg */
    1072, /* 120: of_desc_stats_reply */
    16,   /* 121: of_desc_stats_request */
    8,    /* 122: of_echo_reply */
    8,    /* 123: of_echo_request */
    10,   /* 124: of_error_msg */
    16,   /* 125: of_experimenter */
    16,   /* 126: of_experimenter_error_msg */
    24,   /* 127: of_experimenter_stats_reply */
    24,   /* 128: of_experimenter_stats_request */
    32,   /* 129: of_features_reply */
    8,    /* 130: of_features_request */
    56,   /* 131: of_flow_add */
    56,   /* 132: of_flow_delete */
    56,   /* 133: of_flow_delete_strict */
    56,   /* 134: of_flow_mod */
    12,   /* 135: of_flow_mod_failed_error_msg */
    56,   /* 136: of_flow_modify */
    56,   /* 137: of_flow_modify_strict */
    -1,   /* 138: of_flow_monitor_failed_error_msg */
    56,   /* 139: of_flow_removed */
    16,   /* 140: of_flow_stats_reply */
    56,   /* 141: of_flow_stats_request */
    12,   /* 142: of_get_config_reply */
    8,    /* 143: of_get_config_request */
    16,   /* 144: of_group_add */
    16,   /* 145: of_group_delete */
    16,   /* 146: of_group_desc_stats_reply */
    16,   /* 147: of_group_desc_stats_request */
    56,   /* 148: of_group_features_stats_reply */
    16,   /* 149: of_group_features_stats_request */
    16,   /* 150: of_group_mod */
    12,   /* 151: of_group_mod_failed_error_msg */
    16,   /* 152: of_group_modify */
    16,   /* 153: of_group_stats_reply */
    24,   /* 154: of_group_stats_request */
    8,    /* 155: of_header */
    8,    /* 156: of_hello */
    12,   /* 157: of_hello_failed_error_msg */
    -1,   /* 158: of_meter_config_stats_reply */
    -1,   /* 159: of_meter_config_stats_request */
    -1,   /* 160: of_meter_features_stats_reply */
    -1,   /* 161: of_meter_features_stats_request */
    -1,   /* 162: of_meter_mod */
    -1,   /* 163: of_meter_mod_failed_error_msg */
    -1,   /* 164: of_meter_stats_reply */
    -1,   /* 165: of_meter_stats_request */
    -1,   /* 166: of_nicira_controller_role_reply */
    -1,   /* 167: of_nicira_controller_role_request */
    16,   /* 168: of_nicira_header */
    26,   /* 169: of_packet_in */
    24,   /* 170: of_packet_out */
    -1,   /* 171: of_port_desc_stats_reply */
    -1,   /* 172: of_port_desc_stats_request */
    40,   /* 173: of_port_mod */
    12,   /* 174: of_port_mod_failed_error_msg */
    16,   /* 175: of_port_stats_reply */
    24,   /* 176: of_port_stats_request */
    80,   /* 177: of_port_status */
    -1,   /* 178: of_queue_desc_stats_reply */
    -1,   /* 179: of_queue_desc_stats_request */
    16,   /* 180: of_queue_get_config_reply */
    16,   /* 181: of_queue_get_config_request */
    12,   /* 182: of_queue_op_failed_error_msg */
    16,   /* 183: of_queue_stats_reply */
    24,   /* 184: of_queue_stats_request */
    -1,   /* 185: of_requestforward */
    24,   /* 186: of_role_reply */
    24,   /* 187: of_role_request */
    12,   /* 188: of_role_request_failed_error_msg */
    -1,   /* 189: of_role_status */
    12,   /* 190: of_set_config */
    16,   /* 191: of_stats_reply */
    16,   /* 192: of_stats_request */
    12,   /* 193: of_switch_config_failed_error_msg */
    -1,   /* 194: of_table_desc_stats_reply */
    -1,   /* 195: of_table_desc_stats_request */
    -1,   /* 196: of_table_features_failed_error_msg */
    -1,   /* 197: of_table_features_stats_reply */
    -1,   /* 198: of_table_features_stats_request */
    16,   /* 199: of_table_mod */
    12,   /* 200: of_table_mod_failed_error_msg */
    16,   /* 201: of_table_stats_reply */
    16,   /* 202: of_table_stats_request */
    -1,   /* 203: of_table_status */
    8,    /* 204: of_action */
    16,   /* 205: of_action_bsn */
    28,   /* 206: of_action_bsn_checksum */
    -1,   /* 207: of_action_bsn_gentable */
    24,   /* 208: of_action_bsn_mirror */
    16,   /* 209: of_action_bsn_set_tunnel_dst */
    8,    /* 210: of_action_copy_ttl_in */
    8,    /* 211: of_action_copy_ttl_out */
    8,    /* 212: of_action_dec_mpls_ttl */
    8,    /* 213: of_action_dec_nw_ttl */
    -1,   /* 214: of_action_enqueue */
    8,    /* 215: of_action_experimenter */
    8,    /* 216: of_action_group */
    -1,   /* 217: of_action_id */
    -1,   /* 218: of_action_id_bsn */
    -1,   /* 219: of_action_id_bsn_checksum */
    -1,   /* 220: of_action_id_bsn_gentable */
    -1,   /* 221: of_action_id_bsn_mirror */
    -1,   /* 222: of_action_id_bsn_set_tunnel_dst */
    -1,   /* 223: of_action_id_copy_ttl_in */
    -1,   /* 224: of_action_id_copy_ttl_out */
    -1,   /* 225: of_action_id_dec_mpls_ttl */
    -1,   /* 226: of_action_id_dec_nw_ttl */
    -1,   /* 227: of_action_id_experimenter */
    -1,   /* 228: of_action_id_group */
    -1,   /* 229: of_action_id_nicira */
    -1,   /* 230: of_action_id_nicira_dec_ttl */
    -1,   /* 231: of_action_id_output */
    -1,   /* 232: of_action_id_pop_mpls */
    -1,   /* 233: of_action_id_pop_pbb */
    -1,   /* 234: of_action_id_pop_vlan */
    -1,   /* 235: of_action_id_push_mpls */
    -1,   /* 236: of_action_id_push_pbb */
    -1,   /* 237: of_action_id_push_vlan */
    -1,   /* 238: of_action_id_set_field */
    -1,   /* 239: of_action_id_set_mpls_ttl */
    -1,   /* 240: of_action_id_set_nw_ttl */
    -1,   /* 241: of_action_id_set_queue */
    16,   /* 242: of_action_nicira */
    16,   /* 243: of_action_nicira_dec_ttl */
    16,   /* 244: of_action_output */
    8,    /* 245: of_action_pop_mpls */
    -1,   /* 246: of_action_pop_pbb */
    8,    /* 247: of_action_pop_vlan */
    8,    /* 248: of_action_push_mpls */
    -1,   /* 249: of_action_push_pbb */
    8,    /* 250: of_action_push_vlan */
    -1,   /* 251: of_action_set_dl_dst */
    -1,   /* 252: of_action_set_dl_src */
    8,    /* 253: of_action_set_field */
    -1,   /* 254: of_action_set_mpls_label */
    -1,   /* 255: of_action_set_mpls_tc */
    8,    /* 256: of_action_set_mpls_ttl */
    -1,   /* 257: of_action_set_nw_dst */
    -1,   /* 258: of_action_set_nw_ecn */
    -1,   /* 259: of_action_set_nw_src */
    -1,   /* 260: of_action_set_nw_tos */
    8,    /* 261: of_action_set_nw_ttl */
    8,    /* 262: of_action_set_queue */
    -1,   /* 263: of_action_set_tp_dst */
    -1,   /* 264: of_action_set_tp_src */
    -1,   /* 265: of_action_set_vlan_pcp */
    -1,   /* 266: of_action_set_vlan_vid */
    -1,   /* 267: of_action_strip_vlan */
    -1,   /* 268: of_async_config_prop */
    -1,   /* 269: of_async_config_prop_experimenter_master */
    -1,   /* 270: of_async_config_prop_experimenter_slave */
    -1,   /* 271: of_async_config_prop_flow_removed_master */
    -1,   /* 272: of_async_config_prop_flow_removed_slave */
    -1,   /* 273: of_async_config_prop_packet_in_master */
    -1,   /* 274: of_async_config_prop_packet_in_slave */
    -1,   /* 275: of_async_config_prop_port_status_master */
    -1,   /* 276: of_async_config_prop_port_status_slave */
    -1,   /* 277: of_async_config_prop_requestforward_master */
    -1,   /* 278: of_async_config_prop_requestforward_slave */
    -1,   /* 279: of_async_config_prop_role_status_master */
    -1,   /* 280: of_async_config_prop_role_status_slave */
    -1,   /* 281: of_async_config_prop_table_status_master */
    -1,   /* 282: of_async_config_prop_table_status_slave */
    -1,   /* 283: of_bsn_controller_connection */
    -1,   /* 284: of_bsn_debug_counter_desc_stats_entry */
    -1,   /* 285: of_bsn_debug_counter_stats_entry */
    -1,   /* 286: of_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 287: of_bsn_generic_stats_entry */
    -1,   /* 288: of_bsn_gentable_bucket_stats_entry */
    -1,   /* 289: of_bsn_gentable_desc_stats_entry */
    -1,   /* 290: of_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 291: of_bsn_gentable_entry_stats_entry */
    -1,   /* 292: of_bsn_gentable_stats_entry */
    32,   /* 293: of_bsn_interface */
    -1,   /* 294: of_bsn_lacp_stats_entry */
    -1,   /* 295: of_bsn_port_counter_stats_entry */
    -1,   /* 296: of_bsn_switch_pipeline_stats_entry */
    -1,   /* 297: of_bsn_table_checksum_stats_entry */
    -1,   /* 298: of_bsn_tlv */
    -1,   /* 299: of_bsn_tlv_actor_key */
    -1,   /* 300: of_bsn_tlv_actor_port_num */
    -1,   /* 301: of_bsn_tlv_actor_port_priority */
    -1,   /* 302: of_bsn_tlv_actor_state */
    -1,   /* 303: of_bsn_tlv_actor_system_mac */
    -1,   /* 304: of_bsn_tlv_actor_system_priority */
    -1,   /* 305: of_bsn_tlv_anchor */
    -1,   /* 306: of_bsn_tlv_broadcast_query_timeout */
    -1,   /* 307: of_bsn_tlv_broadcast_rate */
    -1,   /* 308: of_bsn_tlv_bucket */
    -1,   /* 309: of_bsn_tlv_circuit_id */
    -1,   /* 310: of_bsn_tlv_convergence_status */
    -1,   /* 311: of_bsn_tlv_crc_enabled */
    -1,   /* 312: of_bsn_tlv_data */
    -1,   /* 313: of_bsn_tlv_decap */
    -1,   /* 314: of_bsn_tlv_eth_dst */
    -1,   /* 315: of_bsn_tlv_eth_src */
    -1,   /* 316: of_bsn_tlv_external_gateway_ip */
    -1,   /* 317: of_bsn_tlv_external_gateway_mac */
    -1,   /* 318: of_bsn_tlv_external_ip */
    -1,   /* 319: of_bsn_tlv_external_mac */
    -1,   /* 320: of_bsn_tlv_external_netmask */
    -1,   /* 321: of_bsn_tlv_generation_id */
    -1,   /* 322: of_bsn_tlv_header_size */
    -1,   /* 323: of_bsn_tlv_icmp_code */
    -1,   /* 324: of_bsn_tlv_icmp_id */
    -1,   /* 325: of_bsn_tlv_icmp_type */
    -1,   /* 326: of_bsn_tlv_idle_notification */
    -1,   /* 327: of_bsn_tlv_idle_time */
    -1,   /* 328: of_bsn_tlv_idle_timeout */
    -1,   /* 329: of_bsn_tlv_igmp_snooping */
    -1,   /* 330: of_bsn_tlv_internal_gateway_mac */
    -1,   /* 331: of_bsn_tlv_internal_mac */
    -1,   /* 332: of_bsn_tlv_interval */
    -1,   /* 333: of_bsn_tlv_ip_proto */
    -1,   /* 334: of_bsn_tlv_ipv4 */
    -1,   /* 335: of_bsn_tlv_ipv4_dst */
    -1,   /* 336: of_bsn_tlv_ipv4_netmask */
    -1,   /* 337: of_bsn_tlv_ipv4_src */
    -1,   /* 338: of_bsn_tlv_ipv6 */
    -1,   /* 339: of_bsn_tlv_known_multicast_rate */
    -1,   /* 340: of_bsn_tlv_l2_multicast_lookup */
    -1,   /* 341: of_bsn_tlv_mac */
    -1,   /* 342: of_bsn_tlv_mac_mask */
    -1,   /* 343: of_bsn_tlv_mcg_type_vxlan */
    -1,   /* 344: of_bsn_tlv_miss_packets */
    -1,   /* 345: of_bsn_tlv_mpls_control_word */
    -1,   /* 346: of_bsn_tlv_mpls_label */
    -1,   /* 347: of_bsn_tlv_mpls_sequenced */
    -1,   /* 348: of_bsn_tlv_multicast_interface_id */
    -1,   /* 349: of_bsn_tlv_name */
    -1,   /* 350: of_bsn_tlv_negate */
    -1,   /* 351: of_bsn_tlv_nexthop_type_vxlan */
    -1,   /* 352: of_bsn_tlv_offset */
    -1,   /* 353: of_bsn_tlv_partner_key */
    -1,   /* 354: of_bsn_tlv_partner_port_num */
    -1,   /* 355: of_bsn_tlv_partner_port_priority */
    -1,   /* 356: of_bsn_tlv_partner_state */
    -1,   /* 357: of_bsn_tlv_partner_system_mac */
    -1,   /* 358: of_bsn_tlv_partner_system_priority */
    -1,   /* 359: of_bsn_tlv_port */
    -1,   /* 360: of_bsn_tlv_port_vxlan_mode */
    -1,   /* 361: of_bsn_tlv_priority */
    -1,   /* 362: of_bsn_tlv_queue_id */
    -1,   /* 363: of_bsn_tlv_queue_weight */
    -1,   /* 364: of_bsn_tlv_rate_unit */
    -1,   /* 365: of_bsn_tlv_reference */
    -1,   /* 366: of_bsn_tlv_reply_packets */
    -1,   /* 367: of_bsn_tlv_request_packets */
    -1,   /* 368: of_bsn_tlv_rx_bytes */
    -1,   /* 369: of_bsn_tlv_rx_packets */
    -1,   /* 370: of_bsn_tlv_sampling_rate */
    -1,   /* 371: of_bsn_tlv_set_loopback_mode */
    -1,   /* 372: of_bsn_tlv_strip_mpls_l2_on_ingress */
    -1,   /* 373: of_bsn_tlv_strip_mpls_l3_on_ingress */
    -1,   /* 374: of_bsn_tlv_strip_vlan_on_egress */
    -1,   /* 375: of_bsn_tlv_sub_agent_id */
    -1,   /* 376: of_bsn_tlv_tcp_dst */
    -1,   /* 377: of_bsn_tlv_tcp_src */
    -1,   /* 378: of_bsn_tlv_tx_bytes */
    -1,   /* 379: of_bsn_tlv_tx_packets */
    -1,   /* 380: of_bsn_tlv_udf_anchor */
    -1,   /* 381: of_bsn_tlv_udf_id */
    -1,   /* 382: of_bsn_tlv_udf_length */
    -1,   /* 383: of_bsn_tlv_udf_offset */
    -1,   /* 384: of_bsn_tlv_udp_dst */
    -1,   /* 385: of_bsn_tlv_udp_src */
    -1,   /* 386: of_bsn_tlv_unicast_query_timeout */
    -1,   /* 387: of_bsn_tlv_unicast_rate */
    -1,   /* 388: of_bsn_tlv_unknown_multicast_rate */
    -1,   /* 389: of_bsn_tlv_vlan_pcp */
    -1,   /* 390: of_bsn_tlv_vlan_vid */
    -1,   /* 391: of_bsn_tlv_vlan_vid_mask */
    -1,   /* 392: of_bsn_tlv_vni */
    -1,   /* 393: of_bsn_tlv_vrf */
    -1,   /* 394: of_bsn_vlan_counter_stats_entry */
    4,    /* 395: of_bsn_vport */
    64,   /* 396: of_bsn_vport_l2gre */
    32,   /* 397: of_bsn_vport_q_in_q */
    -1,   /* 398: of_bsn_vrf_counter_stats_entry */
    16,   /* 399: of_bucket */
    16,   /* 400: of_bucket_counter */
    -1,   /* 401: of_bundle_prop */
    -1,   /* 402: of_bundle_prop_experimenter */
    56,   /* 403: of_flow_stats_entry */
    8,    /* 404: of_group_desc_stats_entry */
    32,   /* 405: of_group_stats_entry */
    -1,   /* 406: of_hello_elem */
    -1,   /* 407: of_hello_elem_versionbitmap */
    8,    /* 408: of_instruction */
    8,    /* 409: of_instruction_apply_actions */
    -1,   /* 410: of_instruction_bsn */
    -1,   /* 411: of_instruction_bsn_arp_offload */
    -1,   /* 412: of_instruction_bsn_auto_negotiation */
    -1,   /* 413: of_instruction_bsn_deny */
    -1,   /* 414: of_instruction_bsn_dhcp_offload */
    -1,   /* 415: of_instruction_bsn_disable_l3 */
    -1,   /* 416: of_instruction_bsn_disable_split_horizon_check */
    -1,   /* 417: of_instruction_bsn_disable_src_mac_check */
    -1,   /* 418: of_instruction_bsn_disable_vlan_counters */
    -1,   /* 419: of_instruction_bsn_internal_priority */
    -1,   /* 420: of_instruction_bsn_packet_of_death */
    -1,   /* 421: of_instruction_bsn_permit */
    -1,   /* 422: of_instruction_bsn_prioritize_pdus */
    -1,   /* 423: of_instruction_bsn_require_vlan_xlate */
    -1,   /* 424: of_instruction_bsn_span_destination */
    8,    /* 425: of_instruction_clear_actions */
    8,    /* 426: of_instruction_experimenter */
    8,    /* 427: of_instruction_goto_table */
    -1,   /* 428: of_instruction_id */
    -1,   /* 429: of_instruction_id_apply_actions */
    -1,   /* 430: of_instruction_id_bsn */
    -1,   /* 431: of_instruction_id_bsn_arp_offload */
    -1,   /* 432: of_instruction_id_bsn_auto_negotiation */
    -1,   /* 433: of_instruction_id_bsn_deny */
    -1,   /* 434: of_instruction_id_bsn_dhcp_offload */
    -1,   /* 435: of_instruction_id_bsn_disable_l3 */
    -1,   /* 436: of_instruction_id_bsn_disable_split_horizon_check */
    -1,   /* 437: of_instruction_id_bsn_disable_src_mac_check */
    -1,   /* 438: of_instruction_id_bsn_disable_vlan_counters */
    -1,   /* 439: of_instruction_id_bsn_internal_priority */
    -1,   /* 440: of_instruction_id_bsn_packet_of_death */
    -1,   /* 441: of_instruction_id_bsn_permit */
    -1,   /* 442: of_instruction_id_bsn_prioritize_pdus */
    -1,   /* 443: of_instruction_id_bsn_require_vlan_xlate */
    -1,   /* 444: of_instruction_id_bsn_span_destination */
    -1,   /* 445: of_instruction_id_clear_actions */
    -1,   /* 446: of_instruction_id_experimenter */
    -1,   /* 447: of_instruction_id_goto_table */
    -1,   /* 448: of_instruction_id_meter */
    -1,   /* 449: of_instruction_id_write_actions */
    -1,   /* 450: of_instruction_id_write_metadata */
    -1,   /* 451: of_instruction_meter */
    8,    /* 452: of_instruction_write_actions */
    24,   /* 453: of_instruction_write_metadata */
    -1,   /* 454: of_match_v1 */
    -1,   /* 455: of_match_v2 */
    4,    /* 456: of_match_v3 */
    -1,   /* 457: of_meter_band */
    -1,   /* 458: of_meter_band_drop */
    -1,   /* 459: of_meter_band_dscp_remark */
    -1,   /* 460: of_meter_band_experimenter */
    -1,   /* 461: of_meter_band_stats */
    -1,   /* 462: of_meter_config */
    -1,   /* 463: of_meter_features */
    -1,   /* 464: of_meter_stats */
    4,    /* 465: of_oxm */
    6,    /* 466: of_oxm_arp_op */
    8,    /* 467: of_oxm_arp_op_masked */
    10,   /* 468: of_oxm_arp_sha */
    16,   /* 469: of_oxm_arp_sha_masked */
    8,    /* 470: of_oxm_arp_spa */
    12,   /* 471: of_oxm_arp_spa_masked */
    10,   /* 472: of_oxm_arp_tha */
    16,   /* 473: of_oxm_arp_tha_masked */
    8,    /* 474: of_oxm_arp_tpa */
    12,   /* 475: of_oxm_arp_tpa_masked */
    8,    /* 476: of_oxm_bsn_egr_port_group_id */
    12,   /* 477: of_oxm_bsn_egr_port_group_id_masked */
    5,    /* 478: of_oxm_bsn_global_vrf_allowed */
    6,    /* 479: of_oxm_bsn_global_vrf_allowed_masked */
    20,   /* 480: of_oxm_bsn_in_ports_128 */
    36,   /* 481: of_oxm_bsn_in_ports_128_masked */
    68,   /* 482: of_oxm_bsn_in_ports_512 */
    132,  /* 483: of_oxm_bsn_in_ports_512_masked */
    8,    /* 484: of_oxm_bsn_ingress_port_group_id */
    12,   /* 485: of_oxm_bsn_ingress_port_group_id_masked */
    -1,   /* 486: of_oxm_bsn_inner_eth_dst */
    -1,   /* 487: of_oxm_bsn_inner_eth_dst_masked */
    -1,   /* 488: of_oxm_bsn_inner_eth_src */
    -1,   /* 489: of_oxm_bsn_inner_eth_src_masked */
    -1,   /* 490: of_oxm_bsn_inner_vlan_vid */
    -1,   /* 491: of_oxm_bsn_inner_vlan_vid_masked */
    5,    /* 492: of_oxm_bsn_l2_cache_hit */
    6,    /* 493: of_oxm_bsn_l2_cache_hit_masked */
    8,    /* 494: of_oxm_bsn_l3_dst_class_id */
    12,   /* 495: of_oxm_bsn_l3_dst_class_id_masked */
    8,    /* 496: of_oxm_bsn_l3_interface_class_id */
    12,   /* 497: of_oxm_bsn_l3_interface_class_id_masked */
    8,    /* 498: of_oxm_bsn_l3_src_class_id */
    12,   /* 499: of_oxm_bsn_l3_src_class_id_masked */
    8,    /* 500: of_oxm_bsn_lag_id */
    12,   /* 501: of_oxm_bsn_lag_id_masked */
    6,    /* 502: of_oxm_bsn_tcp_flags */
    8,    /* 503: of_oxm_bsn_tcp_flags_masked */
    8,    /* 504: of_oxm_bsn_udf0 */
    12,   /* 505: of_oxm_bsn_udf0_masked */
    8,    /* 506: of_oxm_bsn_udf1 */
    12,   /* 507: of_oxm_bsn_udf1_masked */
    8,    /* 508: of_oxm_bsn_udf2 */
    12,   /* 509: of_oxm_bsn_udf2_masked */
    8,    /* 510: of_oxm_bsn_udf3 */
    12,   /* 511: of_oxm_bsn_udf3_masked */
    8,    /* 512: of_oxm_bsn_udf4 */
    12,   /* 513: of_oxm_bsn_udf4_masked */
    8,    /* 514: of_oxm_bsn_udf5 */
    12,   /* 515: of_oxm_bsn_udf5_masked */
    8,    /* 516: of_oxm_bsn_udf6 */
    12,   /* 517: of_oxm_bsn_udf6_masked */
    8,    /* 518: of_oxm_bsn_udf7 */
    12,   /* 519: of_oxm_bsn_udf7_masked */
    8,    /* 520: of_oxm_bsn_vlan_xlate_port_group_id */
    12,   /* 521: of_oxm_bsn_vlan_xlate_port_group_id_masked */
    8,    /* 522: of_oxm_bsn_vrf */
    12,   /* 523: of_oxm_bsn_vrf_masked */
    -1,   /* 524: of_oxm_bsn_vxlan_network_id */
    -1,   /* 525: of_oxm_bsn_vxlan_network_id_masked */
    10,   /* 526: of_oxm_eth_dst */
    16,   /* 527: of_oxm_eth_dst_masked */
    10,   /* 528: of_oxm_eth_src */
    16,   /* 529: of_oxm_eth_src_masked */
    6,    /* 530: of_oxm_eth_type */
    8,    /* 531: of_oxm_eth_type_masked */
    5,    /* 532: of_oxm_icmpv4_code */
    6,    /* 533: of_oxm_icmpv4_code_masked */
    5,    /* 534: of_oxm_icmpv4_type */
    6,    /* 535: of_oxm_icmpv4_type_masked */
    5,    /* 536: of_oxm_icmpv6_code */
    6,    /* 537: of_oxm_icmpv6_code_masked */
    5,    /* 538: of_oxm_icmpv6_type */
    6,    /* 539: of_oxm_icmpv6_type_masked */
    8,    /* 540: of_oxm_in_phy_port */
    12,   /* 541: of_oxm_in_phy_port_masked */
    8,    /* 542: of_oxm_in_port */
    12,   /* 543: of_oxm_in_port_masked */
    5,    /* 544: of_oxm_ip_dscp */
    6,    /* 545: of_oxm_ip_dscp_masked */
    5,    /* 546: of_oxm_ip_ecn */
    6,    /* 547: of_oxm_ip_ecn_masked */
    5,    /* 548: of_oxm_ip_proto */
    6,    /* 549: of_oxm_ip_proto_masked */
    8,    /* 550: of_oxm_ipv4_dst */
    12,   /* 551: of_oxm_ipv4_dst_masked */
    8,    /* 552: of_oxm_ipv4_src */
    12,   /* 553: of_oxm_ipv4_src_masked */
    20,   /* 554: of_oxm_ipv6_dst */
    36,   /* 555: of_oxm_ipv6_dst_masked */
    -1,   /* 556: of_oxm_ipv6_exthdr */
    -1,   /* 557: of_oxm_ipv6_exthdr_masked */
    8,    /* 558: of_oxm_ipv6_flabel */
    12,   /* 559: of_oxm_ipv6_flabel_masked */
    10,   /* 560: of_oxm_ipv6_nd_sll */
    16,   /* 561: of_oxm_ipv6_nd_sll_masked */
    20,   /* 562: of_oxm_ipv6_nd_target */
    36,   /* 563: of_oxm_ipv6_nd_target_masked */
    10,   /* 564: of_oxm_ipv6_nd_tll */
    16,   /* 565: of_oxm_ipv6_nd_tll_masked */
    20,   /* 566: of_oxm_ipv6_src */
    36,   /* 567: of_oxm_ipv6_src_masked */
    12,   /* 568: of_oxm_metadata */
    20,   /* 569: of_oxm_metadata_masked */
    -1,   /* 570: of_oxm_mpls_bos */
    -1,   /* 571: of_oxm_mpls_bos_masked */
    8,    /* 572: of_oxm_mpls_label */
    12,   /* 573: of_oxm_mpls_label_masked */
    5,    /* 574: of_oxm_mpls_tc */
    6,    /* 575: of_oxm_mpls_tc_masked */
    -1,   /* 576: of_oxm_pbb_uca */
    -1,   /* 577: of_oxm_pbb_uca_masked */
    6,    /* 578: of_oxm_sctp_dst */
    8,    /* 579: of_oxm_sctp_dst_masked */
    6,    /* 580: of_oxm_sctp_src */
    8,    /* 581: of_oxm_sctp_src_masked */
    6,    /* 582: of_oxm_tcp_dst */
    8,    /* 583: of_oxm_tcp_dst_masked */
    6,    /* 584: of_oxm_tcp_src */
    8,    /* 585: of_oxm_tcp_src_masked */
    -1,   /* 586: of_oxm_tunnel_id */
    -1,   /* 587: of_oxm_tunnel_id_masked */
    8,    /* 588: of_oxm_tunnel_ipv4_dst */
    12,   /* 589: of_oxm_tunnel_ipv4_dst_masked */
    8,    /* 590: of_oxm_tunnel_ipv4_src */
    12,   /* 591: of_oxm_tunnel_ipv4_src_masked */
    6,    /* 592: of_oxm_udp_dst */
    8,    /* 593: of_oxm_udp_dst_masked */
    6,    /* 594: of_oxm_udp_src */
    8,    /* 595: of_oxm_udp_src_masked */
    5,    /* 596: of_oxm_vlan_pcp */
    6,    /* 597: of_oxm_vlan_pcp_masked */
    6,    /* 598: of_oxm_vlan_vid */
    8,    /* 599: of_oxm_vlan_vid_masked */
    16,   /* 600: of_packet_queue */
    64,   /* 601: of_port_desc */
    -1,   /* 602: of_port_desc_prop */
    -1,   /* 603: of_port_desc_prop_bsn */
    -1,   /* 604: of_port_desc_prop_bsn_generation_id */
    -1,   /* 605: of_port_desc_prop_bsn_uplink */
    -1,   /* 606: of_port_desc_prop_ethernet */
    -1,   /* 607: of_port_desc_prop_experimenter */
    -1,   /* 608: of_port_desc_prop_optical */
    -1,   /* 609: of_port_mod_prop */
    -1,   /* 610: of_port_mod_prop_ethernet */
    -1,   /* 611: of_port_mod_prop_experimenter */
    -1,   /* 612: of_port_mod_prop_optical */
    104,  /* 613: of_port_stats_entry */
    -1,   /* 614: of_port_stats_prop */
    -1,   /* 615: of_port_stats_prop_ethernet */
    -1,   /* 616: of_port_stats_prop_experimenter */
    -1,   /* 617: of_port_stats_prop_optical */
    -1,   /* 618: of_queue_desc */
    -1,   /* 619: of_queue_desc_prop */
    -1,   /* 620: of_queue_desc_prop_experimenter */
    -1,   /* 621: of_queue_desc_prop_max_rate */
    -1,   /* 622: of_queue_desc_prop_min_rate */
    8,    /* 623: of_queue_prop */
    16,   /* 624: of_queue_prop_experimenter */
    16,   /* 625: of_queue_prop_max_rate */
    16,   /* 626: of_queue_prop_min_rate */
    32,   /* 627: of_queue_stats_entry */
    -1,   /* 628: of_queue_stats_prop */
    -1,   /* 629: of_queue_stats_prop_experimenter */
    -1,   /* 630: of_role_prop */
    -1,   /* 631: of_role_prop_experimenter */
    -1,   /* 632: of_table_desc */
    -1,   /* 633: of_table_feature_prop */
    -1,   /* 634: of_table_feature_prop_apply_actions */
    -1,   /* 635: of_table_feature_prop_apply_actions_miss */
    -1,   /* 636: of_table_feature_prop_apply_setfield */
    -1,   /* 637: of_table_feature_prop_apply_setfield_miss */
    -1,   /* 638: of_table_feature_prop_experimenter */
    -1,   /* 639: of_table_feature_prop_experimenter_miss */
    -1,   /* 640: of_table_feature_prop_instructions */
    -1,   /* 641: of_table_feature_prop_instructions_miss */
    -1,   /* 642: of_table_feature_prop_match */
    -1,   /* 643: of_table_feature_prop_next_tables */
    -1,   /* 644: of_table_feature_prop_next_tables_miss */
    -1,   /* 645: of_table_feature_prop_table_sync_from */
    -1,   /* 646: of_table_feature_prop_wildcards */
    -1,   /* 647: of_table_feature_prop_write_actions */
    -1,   /* 648: of_table_feature_prop_write_actions_miss */
    -1,   /* 649: of_table_feature_prop_write_setfield */
    -1,   /* 650: of_table_feature_prop_write_setfield_miss */
    -1,   /* 651: of_table_features */
    -1,   /* 652: of_table_mod_prop */
    -1,   /* 653: of_table_mod_prop_eviction */
    -1,   /* 654: of_table_mod_prop_experimenter */
    -1,   /* 655: of_table_mod_prop_vacancy */
    128,  /* 656: of_table_stats_entry */
    -1,   /* 657: of_uint32 */
    -1,   /* 658: of_uint64 */
    -1,   /* 659: of_uint8 */
    0,    /* 660: of_list_action */
    -1,   /* 661: of_list_action_id */
    -1,   /* 662: of_list_async_config_prop */
    -1,   /* 663: of_list_bsn_controller_connection */
    -1,   /* 664: of_list_bsn_debug_counter_desc_stats_entry */
    -1,   /* 665: of_list_bsn_debug_counter_stats_entry */
    -1,   /* 666: of_list_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 667: of_list_bsn_generic_stats_entry */
    -1,   /* 668: of_list_bsn_gentable_bucket_stats_entry */
    -1,   /* 669: of_list_bsn_gentable_desc_stats_entry */
    -1,   /* 670: of_list_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 671: of_list_bsn_gentable_entry_stats_entry */
    -1,   /* 672: of_list_bsn_gentable_stats_entry */
    0,    /* 673: of_list_bsn_interface */
    -1,   /* 674: of_list_bsn_lacp_stats_entry */
    -1,   /* 675: of_list_bsn_port_counter_stats_entry */
    -1,   /* 676: of_list_bsn_switch_pipeline_stats_entry */
    -1,   /* 677: of_list_bsn_table_checksum_stats_entry */
    -1,   /* 678: of_list_bsn_tlv */
    -1,   /* 679: of_list_bsn_vlan_counter_stats_entry */
    -1,   /* 680: of_list_bsn_vrf_counter_stats_entry */
    0,    /* 681: of_list_bucket */
    0,    /* 682: of_list_bucket_counter */
    -1,   /* 683: of_list_bundle_prop */
    0,    /* 684: of_list_flow_stats_entry */
    0,    /* 685: of_list_group_desc_stats_entry */
    0,    /* 686: of_list_group_stats_entry */
    -1,   /* 687: of_list_hello_elem */
    0,    /* 688: of_list_instruction */
    -1,   /* 689: of_list_instruction_id */
    -1,   /* 690: of_list_meter_band */
    -1,   /* 691: of_list_meter_band_stats */
    -1,   /* 692: of_list_meter_config */
    -1,   /* 693: of_list_meter_stats */
    0,    /* 694: of_list_oxm */
    0,    /* 695: of_list_packet_queue */
    0,    /* 696: of_list_port_desc */
    -1,   /* 697: of_list_port_desc_prop */
    -1,   /* 698: of_list_port_mod_prop */
    0,    /* 699: of_list_port_stats_entry */
    -1,   /* 700: of_list_port_stats_prop */
    -1,   /* 701: of_list_queue_desc */
    -1,   /* 702: of_list_queue_desc_prop */
    0,    /* 703: of_list_queue_prop */
    0,    /* 704: of_list_queue_stats_entry */
    -1,   /* 705: of_list_queue_stats_prop */
    -1,   /* 706: of_list_role_prop */
    -1,   /* 707: of_list_table_desc */
    -1,   /* 708: of_list_table_feature_prop */
    -1,   /* 709: of_list_table_features */
    -1,   /* 710: of_list_table_mod_prop */
    0,    /* 711: of_list_table_stats_entry */
    -1,   /* 712: of_list_uint32 */
    -1,   /* 713: of_list_uint64 */
    -1    /* 714: of_list_uint8 */
};

static const int
of_object_fixed_len_v4[OF_OBJECT_COUNT] = {
    -1,   /* of_object is not instantiable */
    40,   /* 1: of_aggregate_stats_reply */
    56,   /* 2: of_aggregate_stats_request */
    -1,   /* 3: of_async_config_failed_error_msg */
    32,   /* 4: of_async_get_reply */
    32,   /* 5: of_async_get_request */
    32,   /* 6: of_async_set */
    12,   /* 7: of_bad_action_error_msg */
    12,   /* 8: of_bad_instruction_error_msg */
    12,   /* 9: of_bad_match_error_msg */
    -1,   /* 10: of_bad_property_error_msg */
    12,   /* 11: of_bad_request_error_msg */
    8,    /* 12: of_barrier_reply */
    8,    /* 13: of_barrier_request */
    24,   /* 14: of_bsn_arp_idle */
    20,   /* 15: of_bsn_bw_clear_data_reply */
    16,   /* 16: of_bsn_bw_clear_data_request */
    20,   /* 17: of_bsn_bw_enable_get_reply */
    16,   /* 18: of_bsn_bw_enable_get_request */
    24,   /* 19: of_bsn_bw_enable_set_reply */
    20,   /* 20: of_bsn_bw_enable_set_request */
    16,   /* 21: of_bsn_controller_connections_reply */
    16,   /* 22: of_bsn_controller_connections_request */
    24,   /* 23: of_bsn_debug_counter_desc_stats_reply */
    24,   /* 24: of_bsn_debug_counter_desc_stats_request */
    24,   /* 25: of_bsn_debug_counter_stats_reply */
    24,   /* 26: of_bsn_debug_counter_stats_request */
    24,   /* 27: of_bsn_flow_checksum_bucket_stats_reply */
    25,   /* 28: of_bsn_flow_checksum_bucket_stats_request */
    40,   /* 29: of_bsn_flow_idle */
    20,   /* 30: of_bsn_flow_idle_enable_get_reply */
    16,   /* 31: of_bsn_flow_idle_enable_get_request */
    24,   /* 32: of_bsn_flow_idle_enable_set_reply */
    20,   /* 33: of_bsn_flow_idle_enable_set_request */
    -1,   /* 34: of_bsn_generic_async */
    24,   /* 35: of_bsn_generic_stats_reply */
    88,   /* 36: of_bsn_generic_stats_request */
    24,   /* 37: of_bsn_gentable_bucket_stats_reply */
    26,   /* 38: of_bsn_gentable_bucket_stats_request */
    28,   /* 39: of_bsn_gentable_clear_reply */
    52,   /* 40: of_bsn_gentable_clear_request */
    24,   /* 41: of_bsn_gentable_desc_stats_reply */
    24,   /* 42: of_bsn_gentable_desc_stats_request */
    36,   /* 43: of_bsn_gentable_entry_add */
    18,   /* 44: of_bsn_gentable_entry_delete */
    24,   /* 45: of_bsn_gentable_entry_desc_stats_reply */
    60,   /* 46: of_bsn_gentable_entry_desc_stats_request */
    24,   /* 47: of_bsn_gentable_entry_stats_reply */
    60,   /* 48: of_bsn_gentable_entry_stats_request */
    24,   /* 49: of_bsn_gentable_set_buckets_size */
    24,   /* 50: of_bsn_gentable_stats_reply */
    24,   /* 51: of_bsn_gentable_stats_request */
    16,   /* 52: of_bsn_get_interfaces_reply */
    16,   /* 53: of_bsn_get_interfaces_request */
    -1,   /* 54: of_bsn_get_ip_mask_reply */
    -1,   /* 55: of_bsn_get_ip_mask_request */
    -1,   /* 56: of_bsn_get_l2_table_reply */
    -1,   /* 57: of_bsn_get_l2_table_request */
    20,   /* 58: of_bsn_get_mirroring_reply */
    20,   /* 59: of_bsn_get_mirroring_request */
    272,  /* 60: of_bsn_get_switch_pipeline_reply */
    16,   /* 61: of_bsn_get_switch_pipeline_request */
    16,   /* 62: of_bsn_header */
    -1,   /* 63: of_bsn_hybrid_get_reply */
    -1,   /* 64: of_bsn_hybrid_get_request */
    536,  /* 65: of_bsn_image_desc_stats_reply */
    24,   /* 66: of_bsn_image_desc_stats_request */
    52,   /* 67: of_bsn_lacp_convergence_notif */
    24,   /* 68: of_bsn_lacp_stats_reply */
    24,   /* 69: of_bsn_lacp_stats_request */
    17,   /* 70: of_bsn_log */
    16,   /* 71: of_bsn_lua_command_reply */
    16,   /* 72: of_bsn_lua_command_request */
    16,   /* 73: of_bsn_lua_notification */
    82,   /* 74: of_bsn_lua_upload */
    25,   /* 75: of_bsn_pdu_rx_reply */
    28,   /* 76: of_bsn_pdu_rx_request */
    21,   /* 77: of_bsn_pdu_rx_timeout */
    25,   /* 78: of_bsn_pdu_tx_reply */
    28,   /* 79: of_bsn_pdu_tx_request */
    24,   /* 80: of_bsn_port_counter_stats_reply */
    28,   /* 81: of_bsn_port_counter_stats_request */
    32,   /* 82: of_bsn_role_status */
    24,   /* 83: of_bsn_set_aux_cxns_reply */
    20,   /* 84: of_bsn_set_aux_cxns_request */
    -1,   /* 85: of_bsn_set_ip_mask */
    -1,   /* 86: of_bsn_set_l2_table_reply */
    -1,   /* 87: of_bsn_set_l2_table_request */
    24,   /* 88: of_bsn_set_lacp_reply */
    38,   /* 89: of_bsn_set_lacp_request */
    20,   /* 90: of_bsn_set_mirroring */
    20,   /* 91: of_bsn_set_pktin_suppression_reply */
    32,   /* 92: of_bsn_set_pktin_suppression_request */
    20,   /* 93: of_bsn_set_switch_pipeline_reply */
    272,  /* 94: of_bsn_set_switch_pipeline_request */
    -1,   /* 95: of_bsn_shell_command */
    -1,   /* 96: of_bsn_shell_output */
    -1,   /* 97: of_bsn_shell_status */
    24,   /* 98: of_bsn_stats_reply */
    24,   /* 99: of_bsn_stats_request */
    24,   /* 100: of_bsn_switch_pipeline_stats_reply */
    24,   /* 101: of_bsn_switch_pipeline_stats_request */
    24,   /* 102: of_bsn_table_checksum_stats_reply */
    24,   /* 103: of_bsn_table_checksum_stats_request */
    24,   /* 104: of_bsn_table_set_buckets_size */
    -1,   /* 105: of_bsn_takeover */
    24,   /* 106: of_bsn_time_reply */
    16,   /* 107: of_bsn_time_request */
    24,   /* 108: of_bsn_virtual_port_create_reply */
    20,   /* 109: of_bsn_virtual_port_create_request */
    20,   /* 110: of_bsn_virtual_port_remove_reply */
    20,   /* 111: of_bsn_virtual_port_remove_request */
    18,   /* 112: of_bsn_vlan_counter_clear */
    24,   /* 113: of_bsn_vlan_counter_stats_reply */
    26,   /* 114: of_bsn_vlan_counter_stats_request */
    24,   /* 115: of_bsn_vrf_counter_stats_reply */
    28,   /* 116: of_bsn_vrf_counter_stats_request */
    -1,   /* 117: of_bundle_add_msg */
    -1,   /* 118: of_bundle_ctrl_msg */
    -1,   /* 119: of_bundle_failed_error_msg */
    1072, /* 120: of_desc_stats_reply */
    16,   /* 121: of_desc_stats_request */
    8,    /* 122: of_echo_reply */
    8,    /* 123: of_echo_request */
    10,   /* 124: of_error_msg */
    16,   /* 125: of_experimenter */
    16,   /* 126: of_experimenter_error_msg */
    24,   /* 127: of_experimenter_stats_reply */
    24,   /* 128: of_experimenter_stats_request */
    32,   /* 129: of_features_reply */
    8,    /* 130: of_features_request */
    56,   /* 131: of_flow_add */
    56,   /* 132: of_flow_delete */
    56,   /* 133: of_flow_delete_strict */
    56,   /* 134: of_flow_mod */
    12,   /* 135: of_flow_mod_failed_error_msg */
    56,   /* 136: of_flow_modify */
    56,   /* 137: of_flow_modify_strict */
    -1,   /* 138: of_flow_monitor_failed_error_msg */
    56,   /* 139: of_flow_removed */
    16,   /* 140: of_flow_stats_reply */
    56,   /* 141: of_flow_stats_request */
    12,   /* 142: of_get_config_reply */
    8,    /* 143: of_get_config_request */
    16,   /* 144: of_group_add */
    16,   /* 145: of_group_delete */
    16,   /* 146: of_group_desc_stats_reply */
    16,   /* 147: of_group_desc_stats_request */
    56,   /* 148: of_group_features_stats_reply */
    16,   /* 149: of_group_features_stats_request */
    16,   /* 150: of_group_mod */
    12,   /* 151: of_group_mod_failed_error_msg */
    16,   /* 152: of_group_modify */
    16,   /* 153: of_group_stats_reply */
    24,   /* 154: of_group_stats_request */
    8,    /* 155: of_header */
    8,    /* 156: of_hello */
    12,   /* 157: of_hello_failed_error_msg */
    16,   /* 158: of_meter_config_stats_reply */
    24,   /* 159: of_meter_config_stats_request */
    32,   /* 160: of_meter_features_stats_reply */
    16,   /* 161: of_meter_features_stats_request */
    16,   /* 162: of_meter_mod */
    12,   /* 163: of_meter_mod_failed_error_msg */
    16,   /* 164: of_meter_stats_reply */
    24,   /* 165: of_meter_stats_request */
    -1,   /* 166: of_nicira_controller_role_reply */
    -1,   /* 167: of_nicira_controller_role_request */
    16,   /* 168: of_nicira_header */
    34,   /* 169: of_packet_in */
    24,   /* 170: of_packet_out */
    16,   /* 171: of_port_desc_stats_reply */
    16,   /* 172: of_port_desc_stats_request */
    40,   /* 173: of_port_mod */
    12,   /* 174: of_port_mod_failed_error_msg */
    16,   /* 175: of_port_stats_reply */
    24,   /* 176: of_port_stats_request */
    80,   /* 177: of_port_status */
    -1,   /* 178: of_queue_desc_stats_reply */
    -1,   /* 179: of_queue_desc_stats_request */
    16,   /* 180: of_queue_get_config_reply */
    16,   /* 181: of_queue_get_config_request */
    12,   /* 182: of_queue_op_failed_error_msg */
    16,   /* 183: of_queue_stats_reply */
    24,   /* 184: of_queue_stats_request */
    -1,   /* 185: of_requestforward */
    24,   /* 186: of_role_reply */
    24,   /* 187: of_role_request */
    12,   /* 188: of_role_request_failed_error_msg */
    -1,   /* 189: of_role_status */
    12,   /* 190: of_set_config */
    16,   /* 191: of_stats_reply */
    16,   /* 192: of_stats_request */
    12,   /* 193: of_switch_config_failed_error_msg */
    -1,   /* 194: of_table_desc_stats_reply */
    -1,   /* 195: of_table_desc_stats_request */
    12,   /* 196: of_table_features_failed_error_msg */
    16,   /* 197: of_table_features_stats_reply */
    16,   /* 198: of_table_features_stats_request */
    16,   /* 199: of_table_mod */
    12,   /* 200: of_table_mod_failed_error_msg */
    16,   /* 201: of_table_stats_reply */
    16,   /* 202: of_table_stats_request */
    -1,   /* 203: of_table_status */
    8,    /* 204: of_action */
    16,   /* 205: of_action_bsn */
    28,   /* 206: of_action_bsn_checksum */
    16,   /* 207: of_action_bsn_gentable */
    24,   /* 208: of_action_bsn_mirror */
    16,   /* 209: of_action_bsn_set_tunnel_dst */
    8,    /* 210: of_action_copy_ttl_in */
    8,    /* 211: of_action_copy_ttl_out */
    8,    /* 212: of_action_dec_mpls_ttl */
    8,    /* 213: of_action_dec_nw_ttl */
    -1,   /* 214: of_action_enqueue */
    8,    /* 215: of_action_experimenter */
    8,    /* 216: of_action_group */
    4,    /* 217: of_action_id */
    12,   /* 218: of_action_id_bsn */
    12,   /* 219: of_action_id_bsn_checksum */
    12,   /* 220: of_action_id_bsn_gentable */
    12,   /* 221: of_action_id_bsn_mirror */
    12,   /* 222: of_action_id_bsn_set_tunnel_dst */
    4,    /* 223: of_action_id_copy_ttl_in */
    4,    /* 224: of_action_id_copy_ttl_out */
    4,    /* 225: of_action_id_dec_mpls_ttl */
    4,    /* 226: of_action_id_dec_nw_ttl */
    8,    /* 227: of_action_id_experimenter */
    4,    /* 228: of_action_id_group */
    10,   /* 229: of_action_id_nicira */
    10,   /* 230: of_action_id_nicira_dec_ttl */
    4,    /* 231: of_action_id_output */
    4,    /* 232: of_action_id_pop_mpls */
    4,    /* 233: of_action_id_pop_pbb */
    4,    /* 234: of_action_id_pop_vlan */
    4,    /* 235: of_action_id_push_mpls */
    4,    /* 236: of_action_id_push_pbb */
    4,    /* 237: of_action_id_push_vlan */
    4,    /* 238: of_action_id_set_field */
    4,    /* 239: of_action_id_set_mpls_ttl */
    4,    /* 240: of_action_id_set_nw_ttl */
    4,    /* 241: of_action_id_set_queue */
    16,   /* 242: of_action_nicira */
    16,   /* 243: of_action_nicira_dec_ttl */
    16,   /* 244: of_action_output */
    8,    /* 245: of_action_pop_mpls */
    8,    /* 246: of_action_pop_pbb */
    8,    /* 247: of_action_pop_vlan */
    8,    /* 248: of_action_push_mpls */
    8,    /* 249: of_action_push_pbb */
    8,    /* 250: of_action_push_vlan */
    -1,   /* 251: of_action_set_dl_dst */
    -1,   /* 252: of_action_set_dl_src */
    8,    /* 253: of_action_set_field */
    -1,   /* 254: of_action_set_mpls_label */
    -1,   /* 255: of_action_set_mpls_tc */
    8,    /* 256: of_action_set_mpls_ttl */
    -1,   /* 257: of_action_set_nw_dst */
    -1,   /* 258: of_action_set_nw_ecn */
    -1,   /* 259: of_action_set_nw_src */
    -1,   /* 260: of_action_set_nw_tos */
    8,    /* 261: of_action_set_nw_ttl */
    8,    /* 262: of_action_set_queue */
    -1,   /* 263: of_action_set_tp_dst */
    -1,   /* 264: of_action_set_tp_src */
    -1,   /* 265: of_action_set_vlan_pcp */
    -1,   /* 266: of_action_set_vlan_vid */
    -1,   /* 267: of_action_strip_vlan */
    -1,   /* 268: of_async_config_prop */
    -1,   /* 269: of_async_config_prop_experimenter_master */
    -1,   /* 270: of_async_config_prop_experimenter_slave */
    -1,   /* 271: of_async_config_prop_flow_removed_master */
    -1,   /* 272: of_async_config_prop_flow_removed_slave */
    -1,   /* 273: of_async_config_prop_packet_in_master */
    -1,   /* 274: of_async_config_prop_packet_in_slave */
    -1,   /* 275: of_async_config_prop_port_status_master */
    -1,   /* 276: of_async_config_prop_port_status_slave */
    -1,   /* 277: of_async_config_prop_requestforward_master */
    -1,   /* 278: of_async_config_prop_requestforward_slave */
    -1,   /* 279: of_async_config_prop_role_status_master */
    -1,   /* 280: of_async_config_prop_role_status_slave */
    -1,   /* 281: of_async_config_prop_table_status_master */
    -1,   /* 282: of_async_config_prop_table_status_slave */
    264,  /* 283: of_bsn_controller_connection */
    328,  /* 284: of_bsn_debug_counter_desc_stats_entry */
    16,   /* 285: of_bsn_debug_counter_stats_entry */
    8,    /* 286: of_bsn_flow_checksum_bucket_stats_entry */
    2,    /* 287: of_bsn_generic_stats_entry */
    16,   /* 288: of_bsn_gentable_bucket_stats_entry */
    48,   /* 289: of_bsn_gentable_desc_stats_entry */
    20,   /* 290: of_bsn_gentable_entry_desc_stats_entry */
    4,    /* 291: of_bsn_gentable_entry_stats_entry */
    24,   /* 292: of_bsn_gentable_stats_entry */
    32,   /* 293: of_bsn_interface */
    36,   /* 294: of_bsn_lacp_stats_entry */
    8,    /* 295: of_bsn_port_counter_stats_entry */
    256,  /* 296: of_bsn_switch_pipeline_stats_entry */
    9,    /* 297: of_bsn_table_checksum_stats_entry */
    4,    /* 298: of_bsn_tlv */
    6,    /* 299: of_bsn_tlv_actor_key */
    6,    /* 300: of_bsn_tlv_actor_port_num */
    6,    /* 301: of_bsn_tlv_actor_port_priority */
    5,    /* 302: of_bsn_tlv_actor_state */
    10,   /* 303: of_bsn_tlv_actor_system_mac */
    6,    /* 304: of_bsn_tlv_actor_system_priority */
    6,    /* 305: of_bsn_tlv_anchor */
    8,    /* 306: of_bsn_tlv_broadcast_query_timeout */
    8,    /* 307: of_bsn_tlv_broadcast_rate */
    4,    /* 308: of_bsn_tlv_bucket */
    4,    /* 309: of_bsn_tlv_circuit_id */
    5,    /* 310: of_bsn_tlv_convergence_status */
    5,    /* 311: of_bsn_tlv_crc_enabled */
    4,    /* 312: of_bsn_tlv_data */
    6,    /* 313: of_bsn_tlv_decap */
    10,   /* 314: of_bsn_tlv_eth_dst */
    10,   /* 315: of_bsn_tlv_eth_src */
    8,    /* 316: of_bsn_tlv_external_gateway_ip */
    10,   /* 317: of_bsn_tlv_external_gateway_mac */
    8,    /* 318: of_bsn_tlv_external_ip */
    10,   /* 319: of_bsn_tlv_external_mac */
    8,    /* 320: of_bsn_tlv_external_netmask */
    12,   /* 321: of_bsn_tlv_generation_id */
    8,    /* 322: of_bsn_tlv_header_size */
    5,    /* 323: of_bsn_tlv_icmp_code */
    6,    /* 324: of_bsn_tlv_icmp_id */
    5,    /* 325: of_bsn_tlv_icmp_type */
    4,    /* 326: of_bsn_tlv_idle_notification */
    12,   /* 327: of_bsn_tlv_idle_time */
    8,    /* 328: of_bsn_tlv_idle_timeout */
    4,    /* 329: of_bsn_tlv_igmp_snooping */
    10,   /* 330: of_bsn_tlv_internal_gateway_mac */
    10,   /* 331: of_bsn_tlv_internal_mac */
    8,    /* 332: of_bsn_tlv_interval */
    5,    /* 333: of_bsn_tlv_ip_proto */
    8,    /* 334: of_bsn_tlv_ipv4 */
    8,    /* 335: of_bsn_tlv_ipv4_dst */
    8,    /* 336: of_bsn_tlv_ipv4_netmask */
    8,    /* 337: of_bsn_tlv_ipv4_src */
    20,   /* 338: of_bsn_tlv_ipv6 */
    8,    /* 339: of_bsn_tlv_known_multicast_rate */
    4,    /* 340: of_bsn_tlv_l2_multicast_lookup */
    10,   /* 341: of_bsn_tlv_mac */
    10,   /* 342: of_bsn_tlv_mac_mask */
    4,    /* 343: of_bsn_tlv_mcg_type_vxlan */
    12,   /* 344: of_bsn_tlv_miss_packets */
    5,    /* 345: of_bsn_tlv_mpls_control_word */
    8,    /* 346: of_bsn_tlv_mpls_label */
    5,    /* 347: of_bsn_tlv_mpls_sequenced */
    8,    /* 348: of_bsn_tlv_multicast_interface_id */
    4,    /* 349: of_bsn_tlv_name */
    4,    /* 350: of_bsn_tlv_negate */
    4,    /* 351: of_bsn_tlv_nexthop_type_vxlan */
    6,    /* 352: of_bsn_tlv_offset */
    6,    /* 353: of_bsn_tlv_partner_key */
    6,    /* 354: of_bsn_tlv_partner_port_num */
    6,    /* 355: of_bsn_tlv_partner_port_priority */
    5,    /* 356: of_bsn_tlv_partner_state */
    10,   /* 357: of_bsn_tlv_partner_system_mac */
    6,    /* 358: of_bsn_tlv_partner_system_priority */
    8,    /* 359: of_bsn_tlv_port */
    5,    /* 360: of_bsn_tlv_port_vxlan_mode */
    8,    /* 361: of_bsn_tlv_priority */
    8,    /* 362: of_bsn_tlv_queue_id */
    8,    /* 363: of_bsn_tlv_queue_weight */
    5,    /* 364: of_bsn_tlv_rate_unit */
    6,    /* 365: of_bsn_tlv_reference */
    12,   /* 366: of_bsn_tlv_reply_packets */
    12,   /* 367: of_bsn_tlv_request_packets */
    12,   /* 368: of_bsn_tlv_rx_bytes */
    12,   /* 369: of_bsn_tlv_rx_packets */
    8,    /* 370: of_bsn_tlv_sampling_rate */
    4,    /* 371: of_bsn_tlv_set_loopback_mode */
    4,    /* 372: of_bsn_tlv_strip_mpls_l2_on_ingress */
    4,    /* 373: of_bsn_tlv_strip_mpls_l3_on_ingress */
    4,    /* 374: of_bsn_tlv_strip_vlan_on_egress */
    8,    /* 375: of_bsn_tlv_sub_agent_id */
    6,    /* 376: of_bsn_tlv_tcp_dst */
    6,    /* 377: of_bsn_tlv_tcp_src */
    12,   /* 378: of_bsn_tlv_tx_bytes */
    12,   /* 379: of_bsn_tlv_tx_packets */
    6,    /* 380: of_bsn_tlv_udf_anchor */
    6,    /* 381: of_bsn_tlv_udf_id */
    6,    /* 382: of_bsn_tlv_udf_length */
    6,    /* 383: of_bsn_tlv_udf_offset */
    6,    /* 384: of_bsn_tlv_udp_dst */
    6,    /* 385: of_bsn_tlv_udp_src */
    8,    /* 386: of_bsn_tlv_unicast_query_timeout */
    8,    /* 387: of_bsn_tlv_unicast_rate */
    8,    /* 388: of_bsn_tlv_unknown_multicast_rate */
    5,    /* 389: of_bsn_tlv_vlan_pcp */
    6,    /* 390: of_bsn_tlv_vlan_vid */
    6,    /* 391: of_bsn_tlv_vlan_vid_mask */
    8,    /* 392: of_bsn_tlv_vni */
    8,    /* 393: of_bsn_tlv_vrf */
    8,    /* 394: of_bsn_vlan_counter_stats_entry */
    4,    /* 395: of_bsn_vport */
    64,   /* 396: of_bsn_vport_l2gre */
    32,   /* 397: of_bsn_vport_q_in_q */
    8,    /* 398: of_bsn_vrf_counter_stats_entry */
    16,   /* 399: of_bucket */
    16,   /* 400: of_bucket_counter */
    -1,   /* 401: of_bundle_prop */
    -1,   /* 402: of_bundle_prop_experimenter */
    56,   /* 403: of_flow_stats_entry */
    8,    /* 404: of_group_desc_stats_entry */
    40,   /* 405: of_group_stats_entry */
    4,    /* 406: of_hello_elem */
    4,    /* 407: of_hello_elem_versionbitmap */
    4,    /* 408: of_instruction */
    8,    /* 409: of_instruction_apply_actions */
    16,   /* 410: of_instruction_bsn */
    16,   /* 411: of_instruction_bsn_arp_offload */
    16,   /* 412: of_instruction_bsn_auto_negotiation */
    16,   /* 413: of_instruction_bsn_deny */
    16,   /* 414: of_instruction_bsn_dhcp_offload */
    16,   /* 415: of_instruction_bsn_disable_l3 */
    16,   /* 416: of_instruction_bsn_disable_split_horizon_check */
    16,   /* 417: of_instruction_bsn_disable_src_mac_check */
    16,   /* 418: of_instruction_bsn_disable_vlan_counters */
    16,   /* 419: of_instruction_bsn_internal_priority */
    16,   /* 420: of_instruction_bsn_packet_of_death */
    16,   /* 421: of_instruction_bsn_permit */
    16,   /* 422: of_instruction_bsn_prioritize_pdus */
    16,   /* 423: of_instruction_bsn_require_vlan_xlate */
    16,   /* 424: of_instruction_bsn_span_destination */
    8,    /* 425: of_instruction_clear_actions */
    8,    /* 426: of_instruction_experimenter */
    8,    /* 427: of_instruction_goto_table */
    4,    /* 428: of_instruction_id */
    4,    /* 429: of_instruction_id_apply_actions */
    12,   /* 430: of_instruction_id_bsn */
    12,   /* 431: of_instruction_id_bsn_arp_offload */
    12,   /* 432: of_instruction_id_bsn_auto_negotiation */
    12,   /* 433: of_instruction_id_bsn_deny */
    12,   /* 434: of_instruction_id_bsn_dhcp_offload */
    12,   /* 435: of_instruction_id_bsn_disable_l3 */
    12,   /* 436: of_instruction_id_bsn_disable_split_horizon_check */
    12,   /* 437: of_instruction_id_bsn_disable_src_mac_check */
    12,   /* 438: of_instruction_id_bsn_disable_vlan_counters */
    12,   /* 439: of_instruction_id_bsn_internal_priority */
    12,   /* 440: of_instruction_id_bsn_packet_of_death */
    12,   /* 441: of_instruction_id_bsn_permit */
    12,   /* 442: of_instruction_id_bsn_prioritize_pdus */
    12,   /* 443: of_instruction_id_bsn_require_vlan_xlate */
    12,   /* 444: of_instruction_id_bsn_span_destination */
    4,    /* 445: of_instruction_id_clear_actions */
    8,    /* 446: of_instruction_id_experimenter */
    4,    /* 447: of_instruction_id_goto_table */
    4,    /* 448: of_instruction_id_meter */
    4,    /* 449: of_instruction_id_write_actions */
    4,    /* 450: of_instruction_id_write_metadata */
    8,    /* 451: of_instruction_meter */
    8,    /* 452: of_instruction_write_actions */
    24,   /* 453: of_instruction_write_metadata */
    -1,   /* 454: of_match_v1 */
    -1,   /* 455: of_match_v2 */
    4,    /* 456: of_match_v3 */
    4,    /* 457: of_meter_band */
    16,   /* 458: of_meter_band_drop */
    16,   /* 459: of_meter_band_dscp_remark */
    16,   /* 460: of_meter_band_experimenter */
    16,   /* 461: of_meter_band_stats */
    8,    /* 462: of_meter_config */
    16,   /* 463: of_meter_features */
    40,   /* 464: of_meter_stats */
    4,    /* 465: of_oxm */
    6,    /* 466: of_oxm_arp_op */
    8,    /* 467: of_oxm_arp_op_masked */
    10,   /* 468: of_oxm_arp_sha */
    16,   /* 469: of_oxm_arp_sha_masked */
    8,    /* 470: of_oxm_arp_spa */
    12,   /* 471: of_oxm_arp_spa_masked */
    10,   /* 472: of_oxm_arp_tha */
    16,   /* 473: of_oxm_arp_tha_masked */
    8,    /* 474: of_oxm_arp_tpa */
    12,   /* 475: of_oxm_arp_tpa_masked */
    8,    /* 476: of_oxm_bsn_egr_port_group_id */
    12,   /* 477: of_oxm_bsn_egr_port_group_id_masked */
    5,    /* 478: of_oxm_bsn_global_vrf_allowed */
    6,    /* 479: of_oxm_bsn_global_vrf_allowed_masked */
    20,   /* 480: of_oxm_bsn_in_ports_128 */
    36,   /* 481: of_oxm_bsn_in_ports_128_masked */
    68,   /* 482: of_oxm_bsn_in_ports_512 */
    132,  /* 483: of_oxm_bsn_in_ports_512_masked */
    8,    /* 484: of_oxm_bsn_ingress_port_group_id */
    12,   /* 485: of_oxm_bsn_ingress_port_group_id_masked */
    10,   /* 486: of_oxm_bsn_inner_eth_dst */
    16,   /* 487: of_oxm_bsn_inner_eth_dst_masked */
    10,   /* 488: of_oxm_bsn_inner_eth_src */
    16,   /* 489: of_oxm_bsn_inner_eth_src_masked */
    6,    /* 490: of_oxm_bsn_inner_vlan_vid */
    8,    /* 491: of_oxm_bsn_inner_vlan_vid_masked */
    5,    /* 492: of_oxm_bsn_l2_cache_hit */
    6,    /* 493: of_oxm_bsn_l2_cache_hit_masked */
    8,    /* 494: of_oxm_bsn_l3_dst_class_id */
    12,   /* 495: of_oxm_bsn_l3_dst_class_id_masked */
    8,    /* 496: of_oxm_bsn_l3_interface_class_id */
    12,   /* 497: of_oxm_bsn_l3_interface_class_id_masked */
    8,    /* 498: of_oxm_bsn_l3_src_class_id */
    12,   /* 499: of_oxm_bsn_l3_src_class_id_masked */
    8,    /* 500: of_oxm_bsn_lag_id */
    12,   /* 501: of_oxm_bsn_lag_id_masked */
    6,    /* 502: of_oxm_bsn_tcp_flags */
    8,    /* 503: of_oxm_bsn_tcp_flags_masked */
    8,    /* 504: of_oxm_bsn_udf0 */
    12,   /* 505: of_oxm_bsn_udf0_masked */
    8,    /* 506: of_oxm_bsn_udf1 */
    12,   /* 507: of_oxm_bsn_udf1_masked */
    8,    /* 508: of_oxm_bsn_udf2 */
    12,   /* 509: of_oxm_bsn_udf2_masked */
    8,    /* 510: of_oxm_bsn_udf3 */
    12,   /* 511: of_oxm_bsn_udf3_masked */
    8,    /* 512: of_oxm_bsn_udf4 */
    12,   /* 513: of_oxm_bsn_udf4_masked */
    8,    /* 514: of_oxm_bsn_udf5 */
    12,   /* 515: of_oxm_bsn_udf5_masked */
    8,    /* 516: of_oxm_bsn_udf6 */
    12,   /* 517: of_oxm_bsn_udf6_masked */
    8,    /* 518: of_oxm_bsn_udf7 */
    12,   /* 519: of_oxm_bsn_udf7_masked */
    8,    /* 520: of_oxm_bsn_vlan_xlate_port_group_id */
    12,   /* 521: of_oxm_bsn_vlan_xlate_port_group_id_masked */
    8,    /* 522: of_oxm_bsn_vrf */
    12,   /* 523: of_oxm_bsn_vrf_masked */
    8,    /* 524: of_oxm_bsn_vxlan_network_id */
    12,   /* 525: of_oxm_bsn_vxlan_network_id_masked */
    10,   /* 526: of_oxm_eth_dst */
    16,   /* 527: of_oxm_eth_dst_masked */
    10,   /* 528: of_oxm_eth_src */
    16,   /* 529: of_oxm_eth_src_masked */
    6,    /* 530: of_oxm_eth_type */
    8,    /* 531: of_oxm_eth_type_masked */
    5,    /* 532: of_oxm_icmpv4_code */
    6,    /* 533: of_oxm_icmpv4_code_masked */
    5,    /* 534: of_oxm_icmpv4_type */
    6,    /* 535: of_oxm_icmpv4_type_masked */
    5,    /* 536: of_oxm_icmpv6_code */
    6,    /* 537: of_oxm_icmpv6_code_masked */
    5,    /* 538: of_oxm_icmpv6_type */
    6,    /* 539: of_oxm_icmpv6_type_masked */
    8,    /* 540: of_oxm_in_phy_port */
    12,   /* 541: of_oxm_in_phy_port_masked */
    8,    /* 542: of_oxm_in_port */
    12,   /* 543: of_oxm_in_port_masked */
    5,    /* 544: of_oxm_ip_dscp */
    6,    /* 545: of_oxm_ip_dscp_masked */
    5,    /* 546: of_oxm_ip_ecn */
    6,    /* 547: of_oxm_ip_ecn_masked */
    5,    /* 548: of_oxm_ip_proto */
    6,    /* 549: of_oxm_ip_proto_masked */
    8,    /* 550: of_oxm_ipv4_dst */
    12,   /* 551: of_oxm_ipv4_dst_masked */
    8,    /* 552: of_oxm_ipv4_src */
    12,   /* 553: of_oxm_ipv4_src_masked */
    20,   /* 554: of_oxm_ipv6_dst */
    36,   /* 555: of_oxm_ipv6_dst_masked */
    6,    /* 556: of_oxm_ipv6_exthdr */
    8,    /* 557: of_oxm_ipv6_exthdr_masked */
    8,    /* 558: of_oxm_ipv6_flabel */
    12,   /* 559: of_oxm_ipv6_flabel_masked */
    10,   /* 560: of_oxm_ipv6_nd_sll */
    16,   /* 561: of_oxm_ipv6_nd_sll_masked */
    20,   /* 562: of_oxm_ipv6_nd_target */
    36,   /* 563: of_oxm_ipv6_nd_target_masked */
    10,   /* 564: of_oxm_ipv6_nd_tll */
    16,   /* 565: of_oxm_ipv6_nd_tll_masked */
    20,   /* 566: of_oxm_ipv6_src */
    36,   /* 567: of_oxm_ipv6_src_masked */
    12,   /* 568: of_oxm_metadata */
    20,   /* 569: of_oxm_metadata_masked */
    5,    /* 570: of_oxm_mpls_bos */
    6,    /* 571: of_oxm_mpls_bos_masked */
    8,    /* 572: of_oxm_mpls_label */
    12,   /* 573: of_oxm_mpls_label_masked */
    5,    /* 574: of_oxm_mpls_tc */
    6,    /* 575: of_oxm_mpls_tc_masked */
    -1,   /* 576: of_oxm_pbb_uca */
    -1,   /* 577: of_oxm_pbb_uca_masked */
    6,    /* 578: of_oxm_sctp_dst */
    8,    /* 579: of_oxm_sctp_dst_masked */
    6,    /* 580: of_oxm_sctp_src */
    8,    /* 581: of_oxm_sctp_src_masked */
    6,    /* 582: of_oxm_tcp_dst */
    8,    /* 583: of_oxm_tcp_dst_masked */
    6,    /* 584: of_oxm_tcp_src */
    8,    /* 585: of_oxm_tcp_src_masked */
    12,   /* 586: of_oxm_tunnel_id */
    20,   /* 587: of_oxm_tunnel_id_masked */
    8,    /* 588: of_oxm_tunnel_ipv4_dst */
    12,   /* 589: of_oxm_tunnel_ipv4_dst_masked */
    8,    /* 590: of_oxm_tunnel_ipv4_src */
    12,   /* 591: of_oxm_tunnel_ipv4_src_masked */
    6,    /* 592: of_oxm_udp_dst */
    8,    /* 593: of_oxm_udp_dst_masked */
    6,    /* 594: of_oxm_udp_src */
    8,    /* 595: of_oxm_udp_src_masked */
    5,    /* 596: of_oxm_vlan_pcp */
    6,    /* 597: of_oxm_vlan_pcp_masked */
    6,    /* 598: of_oxm_vlan_vid */
    8,    /* 599: of_oxm_vlan_vid_masked */
    16,   /* 600: of_packet_queue */
    64,   /* 601: of_port_desc */
    -1,   /* 602: of_port_desc_prop */
    -1,   /* 603: of_port_desc_prop_bsn */
    -1,   /* 604: of_port_desc_prop_bsn_generation_id */
    -1,   /* 605: of_port_desc_prop_bsn_uplink */
    -1,   /* 606: of_port_desc_prop_ethernet */
    -1,   /* 607: of_port_desc_prop_experimenter */
    -1,   /* 608: of_port_desc_prop_optical */
    -1,   /* 609: of_port_mod_prop */
    -1,   /* 610: of_port_mod_prop_ethernet */
    -1,   /* 611: of_port_mod_prop_experimenter */
    -1,   /* 612: of_port_mod_prop_optical */
    112,  /* 613: of_port_stats_entry */
    -1,   /* 614: of_port_stats_prop */
    -1,   /* 615: of_port_stats_prop_ethernet */
    -1,   /* 616: of_port_stats_prop_experimenter */
    -1,   /* 617: of_port_stats_prop_optical */
    -1,   /* 618: of_queue_desc */
    -1,   /* 619: of_queue_desc_prop */
    -1,   /* 620: of_queue_desc_prop_experimenter */
    -1,   /* 621: of_queue_desc_prop_max_rate */
    -1,   /* 622: of_queue_desc_prop_min_rate */
    8,    /* 623: of_queue_prop */
    16,   /* 624: of_queue_prop_experimenter */
    16,   /* 625: of_queue_prop_max_rate */
    16,   /* 626: of_queue_prop_min_rate */
    40,   /* 627: of_queue_stats_entry */
    -1,   /* 628: of_queue_stats_prop */
    -1,   /* 629: of_queue_stats_prop_experimenter */
    -1,   /* 630: of_role_prop */
    -1,   /* 631: of_role_prop_experimenter */
    -1,   /* 632: of_table_desc */
    4,    /* 633: of_table_feature_prop */
    4,    /* 634: of_table_feature_prop_apply_actions */
    4,    /* 635: of_table_feature_prop_apply_actions_miss */
    4,    /* 636: of_table_feature_prop_apply_setfield */
    4,    /* 637: of_table_feature_prop_apply_setfield_miss */
    12,   /* 638: of_table_feature_prop_experimenter */
    12,   /* 639: of_table_feature_prop_experimenter_miss */
    4,    /* 640: of_table_feature_prop_instructions */
    4,    /* 641: of_table_feature_prop_instructions_miss */
    4,    /* 642: of_table_feature_prop_match */
    4,    /* 643: of_table_feature_prop_next_tables */
    4,    /* 644: of_table_feature_prop_next_tables_miss */
    -1,   /* 645: of_table_feature_prop_table_sync_from */
    4,    /* 646: of_table_feature_prop_wildcards */
    4,    /* 647: of_table_feature_prop_write_actions */
    4,    /* 648: of_table_feature_prop_write_actions_miss */
    4,    /* 649: of_table_feature_prop_write_setfield */
    4,    /* 650: of_table_feature_prop_write_setfield_miss */
    64,   /* 651: of_table_features */
    -1,   /* 652: of_table_mod_prop */
    -1,   /* 653: of_table_mod_prop_eviction */
    -1,   /* 654: of_table_mod_prop_experimenter */
    -1,   /* 655: of_table_mod_prop_vacancy */
    24,   /* 656: of_table_stats_entry */
    4,    /* 657: of_uint32 */
    8,    /* 658: of_uint64 */
    1,    /* 659: of_uint8 */
    0,    /* 660: of_list_action */
    0,    /* 661: of_list_action_id */
    -1,   /* 662: of_list_async_config_prop */
    0,    /* 663: of_list_bsn_controller_connection */
    0,    /* 664: of_list_bsn_debug_counter_desc_stats_entry */
    0,    /* 665: of_list_bsn_debug_counter_stats_entry */
    0,    /* 666: of_list_bsn_flow_checksum_bucket_stats_entry */
    0,    /* 667: of_list_bsn_generic_stats_entry */
    0,    /* 668: of_list_bsn_gentable_bucket_stats_entry */
    0,    /* 669: of_list_bsn_gentable_desc_stats_entry */
    0,    /* 670: of_list_bsn_gentable_entry_desc_stats_entry */
    0,    /* 671: of_list_bsn_gentable_entry_stats_entry */
    0,    /* 672: of_list_bsn_gentable_stats_entry */
    0,    /* 673: of_list_bsn_interface */
    0,    /* 674: of_list_bsn_lacp_stats_entry */
    0,    /* 675: of_list_bsn_port_counter_stats_entry */
    0,    /* 676: of_list_bsn_switch_pipeline_stats_entry */
    0,    /* 677: of_list_bsn_table_checksum_stats_entry */
    0,    /* 678: of_list_bsn_tlv */
    0,    /* 679: of_list_bsn_vlan_counter_stats_entry */
    0,    /* 680: of_list_bsn_vrf_counter_stats_entry */
    0,    /* 681: of_list_bucket */
    0,    /* 682: of_list_bucket_counter */
    -1,   /* 683: of_list_bundle_prop */
    0,    /* 684: of_list_flow_stats_entry */
    0,    /* 685: of_list_group_desc_stats_entry */
    0,    /* 686: of_list_group_stats_entry */
    0,    /* 687: of_list_hello_elem */
    0,    /* 688: of_list_instruction */
    0,    /* 689: of_list_instruction_id */
    0,    /* 690: of_list_meter_band */
    0,    /* 691: of_list_meter_band_stats */
    0,    /* 692: of_list_meter_config */
    0,    /* 693: of_list_meter_stats */
    0,    /* 694: of_list_oxm */
    0,    /* 695: of_list_packet_queue */
    0,    /* 696: of_list_port_desc */
    -1,   /* 697: of_list_port_desc_prop */
    -1,   /* 698: of_list_port_mod_prop */
    0,    /* 699: of_list_port_stats_entry */
    -1,   /* 700: of_list_port_stats_prop */
    -1,   /* 701: of_list_queue_desc */
    -1,   /* 702: of_list_queue_desc_prop */
    0,    /* 703: of_list_queue_prop */
    0,    /* 704: of_list_queue_stats_entry */
    -1,   /* 705: of_list_queue_stats_prop */
    -1,   /* 706: of_list_role_prop */
    -1,   /* 707: of_list_table_desc */
    0,    /* 708: of_list_table_feature_prop */
    0,    /* 709: of_list_table_features */
    -1,   /* 710: of_list_table_mod_prop */
    0,    /* 711: of_list_table_stats_entry */
    0,    /* 712: of_list_uint32 */
    0,    /* 713: of_list_uint64 */
    0     /* 714: of_list_uint8 */
};

static const int
of_object_fixed_len_v5[OF_OBJECT_COUNT] = {
    -1,   /* of_object is not instantiable */
    40,   /* 1: of_aggregate_stats_reply */
    56,   /* 2: of_aggregate_stats_request */
    12,   /* 3: of_async_config_failed_error_msg */
    8,    /* 4: of_async_get_reply */
    8,    /* 5: of_async_get_request */
    8,    /* 6: of_async_set */
    12,   /* 7: of_bad_action_error_msg */
    12,   /* 8: of_bad_instruction_error_msg */
    12,   /* 9: of_bad_match_error_msg */
    12,   /* 10: of_bad_property_error_msg */
    12,   /* 11: of_bad_request_error_msg */
    8,    /* 12: of_barrier_reply */
    8,    /* 13: of_barrier_request */
    24,   /* 14: of_bsn_arp_idle */
    20,   /* 15: of_bsn_bw_clear_data_reply */
    16,   /* 16: of_bsn_bw_clear_data_request */
    20,   /* 17: of_bsn_bw_enable_get_reply */
    16,   /* 18: of_bsn_bw_enable_get_request */
    24,   /* 19: of_bsn_bw_enable_set_reply */
    20,   /* 20: of_bsn_bw_enable_set_request */
    16,   /* 21: of_bsn_controller_connections_reply */
    16,   /* 22: of_bsn_controller_connections_request */
    24,   /* 23: of_bsn_debug_counter_desc_stats_reply */
    24,   /* 24: of_bsn_debug_counter_desc_stats_request */
    24,   /* 25: of_bsn_debug_counter_stats_reply */
    24,   /* 26: of_bsn_debug_counter_stats_request */
    24,   /* 27: of_bsn_flow_checksum_bucket_stats_reply */
    25,   /* 28: of_bsn_flow_checksum_bucket_stats_request */
    40,   /* 29: of_bsn_flow_idle */
    20,   /* 30: of_bsn_flow_idle_enable_get_reply */
    16,   /* 31: of_bsn_flow_idle_enable_get_request */
    24,   /* 32: of_bsn_flow_idle_enable_set_reply */
    20,   /* 33: of_bsn_flow_idle_enable_set_request */
    80,   /* 34: of_bsn_generic_async */
    24,   /* 35: of_bsn_generic_stats_reply */
    88,   /* 36: of_bsn_generic_stats_request */
    24,   /* 37: of_bsn_gentable_bucket_stats_reply */
    26,   /* 38: of_bsn_gentable_bucket_stats_request */
    28,   /* 39: of_bsn_gentable_clear_reply */
    52,   /* 40: of_bsn_gentable_clear_request */
    24,   /* 41: of_bsn_gentable_desc_stats_reply */
    24,   /* 42: of_bsn_gentable_desc_stats_request */
    36,   /* 43: of_bsn_gentable_entry_add */
    18,   /* 44: of_bsn_gentable_entry_delete */
    24,   /* 45: of_bsn_gentable_entry_desc_stats_reply */
    60,   /* 46: of_bsn_gentable_entry_desc_stats_request */
    24,   /* 47: of_bsn_gentable_entry_stats_reply */
    60,   /* 48: of_bsn_gentable_entry_stats_request */
    24,   /* 49: of_bsn_gentable_set_buckets_size */
    24,   /* 50: of_bsn_gentable_stats_reply */
    24,   /* 51: of_bsn_gentable_stats_request */
    16,   /* 52: of_bsn_get_interfaces_reply */
    16,   /* 53: of_bsn_get_interfaces_request */
    -1,   /* 54: of_bsn_get_ip_mask_reply */
    -1,   /* 55: of_bsn_get_ip_mask_request */
    -1,   /* 56: of_bsn_get_l2_table_reply */
    -1,   /* 57: of_bsn_get_l2_table_request */
    20,   /* 58: of_bsn_get_mirroring_reply */
    20,   /* 59: of_bsn_get_mirroring_request */
    272,  /* 60: of_bsn_get_switch_pipeline_reply */
    16,   /* 61: of_bsn_get_switch_pipeline_request */
    16,   /* 62: of_bsn_header */
    -1,   /* 63: of_bsn_hybrid_get_reply */
    -1,   /* 64: of_bsn_hybrid_get_request */
    536,  /* 65: of_bsn_image_desc_stats_reply */
    24,   /* 66: of_bsn_image_desc_stats_request */
    52,   /* 67: of_bsn_lacp_convergence_notif */
    24,   /* 68: of_bsn_lacp_stats_reply */
    24,   /* 69: of_bsn_lacp_stats_request */
    17,   /* 70: of_bsn_log */
    16,   /* 71: of_bsn_lua_command_reply */
    16,   /* 72: of_bsn_lua_command_request */
    16,   /* 73: of_bsn_lua_notification */
    82,   /* 74: of_bsn_lua_upload */
    25,   /* 75: of_bsn_pdu_rx_reply */
    28,   /* 76: of_bsn_pdu_rx_request */
    21,   /* 77: of_bsn_pdu_rx_timeout */
    25,   /* 78: of_bsn_pdu_tx_reply */
    28,   /* 79: of_bsn_pdu_tx_request */
    24,   /* 80: of_bsn_port_counter_stats_reply */
    28,   /* 81: of_bsn_port_counter_stats_request */
    -1,   /* 82: of_bsn_role_status */
    24,   /* 83: of_bsn_set_aux_cxns_reply */
    20,   /* 84: of_bsn_set_aux_cxns_request */
    -1,   /* 85: of_bsn_set_ip_mask */
    -1,   /* 86: of_bsn_set_l2_table_reply */
    -1,   /* 87: of_bsn_set_l2_table_request */
    24,   /* 88: of_bsn_set_lacp_reply */
    38,   /* 89: of_bsn_set_lacp_request */
    20,   /* 90: of_bsn_set_mirroring */
    20,   /* 91: of_bsn_set_pktin_suppression_reply */
    32,   /* 92: of_bsn_set_pktin_suppression_request */
    20,   /* 93: of_bsn_set_switch_pipeline_reply */
    272,  /* 94: of_bsn_set_switch_pipeline_request */
    -1,   /* 95: of_bsn_shell_command */
    -1,   /* 96: of_bsn_shell_output */
    -1,   /* 97: of_bsn_shell_status */
    24,   /* 98: of_bsn_stats_reply */
    24,   /* 99: of_bsn_stats_request */
    24,   /* 100: of_bsn_switch_pipeline_stats_reply */
    24,   /* 101: of_bsn_switch_pipeline_stats_request */
    24,   /* 102: of_bsn_table_checksum_stats_reply */
    24,   /* 103: of_bsn_table_checksum_stats_request */
    24,   /* 104: of_bsn_table_set_buckets_size */
    16,   /* 105: of_bsn_takeover */
    24,   /* 106: of_bsn_time_reply */
    16,   /* 107: of_bsn_time_request */
    24,   /* 108: of_bsn_virtual_port_create_reply */
    20,   /* 109: of_bsn_virtual_port_create_request */
    20,   /* 110: of_bsn_virtual_port_remove_reply */
    20,   /* 111: of_bsn_virtual_port_remove_request */
    18,   /* 112: of_bsn_vlan_counter_clear */
    24,   /* 113: of_bsn_vlan_counter_stats_reply */
    26,   /* 114: of_bsn_vlan_counter_stats_request */
    24,   /* 115: of_bsn_vrf_counter_stats_reply */
    28,   /* 116: of_bsn_vrf_counter_stats_request */
    16,   /* 117: of_bundle_add_msg */
    16,   /* 118: of_bundle_ctrl_msg */
    12,   /* 119: of_bundle_failed_error_msg */
    1072, /* 120: of_desc_stats_reply */
    16,   /* 121: of_desc_stats_request */
    8,    /* 122: of_echo_reply */
    8,    /* 123: of_echo_request */
    10,   /* 124: of_error_msg */
    16,   /* 125: of_experimenter */
    16,   /* 126: of_experimenter_error_msg */
    24,   /* 127: of_experimenter_stats_reply */
    24,   /* 128: of_experimenter_stats_request */
    32,   /* 129: of_features_reply */
    8,    /* 130: of_features_request */
    56,   /* 131: of_flow_add */
    56,   /* 132: of_flow_delete */
    56,   /* 133: of_flow_delete_strict */
    56,   /* 134: of_flow_mod */
    12,   /* 135: of_flow_mod_failed_error_msg */
    56,   /* 136: of_flow_modify */
    56,   /* 137: of_flow_modify_strict */
    12,   /* 138: of_flow_monitor_failed_error_msg */
    56,   /* 139: of_flow_removed */
    16,   /* 140: of_flow_stats_reply */
    56,   /* 141: of_flow_stats_request */
    12,   /* 142: of_get_config_reply */
    8,    /* 143: of_get_config_request */
    16,   /* 144: of_group_add */
    16,   /* 145: of_group_delete */
    16,   /* 146: of_group_desc_stats_reply */
    16,   /* 147: of_group_desc_stats_request */
    56,   /* 148: of_group_features_stats_reply */
    16,   /* 149: of_group_features_stats_request */
    16,   /* 150: of_group_mod */
    12,   /* 151: of_group_mod_failed_error_msg */
    16,   /* 152: of_group_modify */
    16,   /* 153: of_group_stats_reply */
    24,   /* 154: of_group_stats_request */
    8,    /* 155: of_header */
    8,    /* 156: of_hello */
    12,   /* 157: of_hello_failed_error_msg */
    16,   /* 158: of_meter_config_stats_reply */
    24,   /* 159: of_meter_config_stats_request */
    32,   /* 160: of_meter_features_stats_reply */
    16,   /* 161: of_meter_features_stats_request */
    16,   /* 162: of_meter_mod */
    12,   /* 163: of_meter_mod_failed_error_msg */
    16,   /* 164: of_meter_stats_reply */
    24,   /* 165: of_meter_stats_request */
    -1,   /* 166: of_nicira_controller_role_reply */
    -1,   /* 167: of_nicira_controller_role_request */
    16,   /* 168: of_nicira_header */
    34,   /* 169: of_packet_in */
    24,   /* 170: of_packet_out */
    16,   /* 171: of_port_desc_stats_reply */
    16,   /* 172: of_port_desc_stats_request */
    32,   /* 173: of_port_mod */
    12,   /* 174: of_port_mod_failed_error_msg */
    16,   /* 175: of_port_stats_reply */
    24,   /* 176: of_port_stats_request */
    56,   /* 177: of_port_status */
    16,   /* 178: of_queue_desc_stats_reply */
    16,   /* 179: of_queue_desc_stats_request */
    -1,   /* 180: of_queue_get_config_reply */
    -1,   /* 181: of_queue_get_config_request */
    12,   /* 182: of_queue_op_failed_error_msg */
    16,   /* 183: of_queue_stats_reply */
    24,   /* 184: of_queue_stats_request */
    12,   /* 185: of_requestforward */
    24,   /* 186: of_role_reply */
    24,   /* 187: of_role_request */
    12,   /* 188: of_role_request_failed_error_msg */
    24,   /* 189: of_role_status */
    12,   /* 190: of_set_config */
    16,   /* 191: of_stats_reply */
    16,   /* 192: of_stats_request */
    12,   /* 193: of_switch_config_failed_error_msg */
    16,   /* 194: of_table_desc_stats_reply */
    16,   /* 195: of_table_desc_stats_request */
    12,   /* 196: of_table_features_failed_error_msg */
    16,   /* 197: of_table_features_stats_reply */
    16,   /* 198: of_table_features_stats_request */
    16,   /* 199: of_table_mod */
    12,   /* 200: of_table_mod_failed_error_msg */
    16,   /* 201: of_table_stats_reply */
    16,   /* 202: of_table_stats_request */
    28,   /* 203: of_table_status */
    8,    /* 204: of_action */
    16,   /* 205: of_action_bsn */
    28,   /* 206: of_action_bsn_checksum */
    16,   /* 207: of_action_bsn_gentable */
    24,   /* 208: of_action_bsn_mirror */
    16,   /* 209: of_action_bsn_set_tunnel_dst */
    8,    /* 210: of_action_copy_ttl_in */
    8,    /* 211: of_action_copy_ttl_out */
    8,    /* 212: of_action_dec_mpls_ttl */
    8,    /* 213: of_action_dec_nw_ttl */
    -1,   /* 214: of_action_enqueue */
    8,    /* 215: of_action_experimenter */
    8,    /* 216: of_action_group */
    4,    /* 217: of_action_id */
    12,   /* 218: of_action_id_bsn */
    12,   /* 219: of_action_id_bsn_checksum */
    12,   /* 220: of_action_id_bsn_gentable */
    12,   /* 221: of_action_id_bsn_mirror */
    12,   /* 222: of_action_id_bsn_set_tunnel_dst */
    4,    /* 223: of_action_id_copy_ttl_in */
    4,    /* 224: of_action_id_copy_ttl_out */
    4,    /* 225: of_action_id_dec_mpls_ttl */
    4,    /* 226: of_action_id_dec_nw_ttl */
    8,    /* 227: of_action_id_experimenter */
    4,    /* 228: of_action_id_group */
    10,   /* 229: of_action_id_nicira */
    10,   /* 230: of_action_id_nicira_dec_ttl */
    4,    /* 231: of_action_id_output */
    4,    /* 232: of_action_id_pop_mpls */
    4,    /* 233: of_action_id_pop_pbb */
    4,    /* 234: of_action_id_pop_vlan */
    4,    /* 235: of_action_id_push_mpls */
    4,    /* 236: of_action_id_push_pbb */
    4,    /* 237: of_action_id_push_vlan */
    4,    /* 238: of_action_id_set_field */
    4,    /* 239: of_action_id_set_mpls_ttl */
    4,    /* 240: of_action_id_set_nw_ttl */
    4,    /* 241: of_action_id_set_queue */
    16,   /* 242: of_action_nicira */
    16,   /* 243: of_action_nicira_dec_ttl */
    16,   /* 244: of_action_output */
    8,    /* 245: of_action_pop_mpls */
    8,    /* 246: of_action_pop_pbb */
    8,    /* 247: of_action_pop_vlan */
    8,    /* 248: of_action_push_mpls */
    8,    /* 249: of_action_push_pbb */
    8,    /* 250: of_action_push_vlan */
    -1,   /* 251: of_action_set_dl_dst */
    -1,   /* 252: of_action_set_dl_src */
    8,    /* 253: of_action_set_field */
    -1,   /* 254: of_action_set_mpls_label */
    -1,   /* 255: of_action_set_mpls_tc */
    8,    /* 256: of_action_set_mpls_ttl */
    -1,   /* 257: of_action_set_nw_dst */
    -1,   /* 258: of_action_set_nw_ecn */
    -1,   /* 259: of_action_set_nw_src */
    -1,   /* 260: of_action_set_nw_tos */
    8,    /* 261: of_action_set_nw_ttl */
    8,    /* 262: of_action_set_queue */
    -1,   /* 263: of_action_set_tp_dst */
    -1,   /* 264: of_action_set_tp_src */
    -1,   /* 265: of_action_set_vlan_pcp */
    -1,   /* 266: of_action_set_vlan_vid */
    -1,   /* 267: of_action_strip_vlan */
    4,    /* 268: of_async_config_prop */
    4,    /* 269: of_async_config_prop_experimenter_master */
    4,    /* 270: of_async_config_prop_experimenter_slave */
    8,    /* 271: of_async_config_prop_flow_removed_master */
    8,    /* 272: of_async_config_prop_flow_removed_slave */
    8,    /* 273: of_async_config_prop_packet_in_master */
    8,    /* 274: of_async_config_prop_packet_in_slave */
    8,    /* 275: of_async_config_prop_port_status_master */
    8,    /* 276: of_async_config_prop_port_status_slave */
    8,    /* 277: of_async_config_prop_requestforward_master */
    8,    /* 278: of_async_config_prop_requestforward_slave */
    8,    /* 279: of_async_config_prop_role_status_master */
    8,    /* 280: of_async_config_prop_role_status_slave */
    8,    /* 281: of_async_config_prop_table_status_master */
    8,    /* 282: of_async_config_prop_table_status_slave */
    264,  /* 283: of_bsn_controller_connection */
    328,  /* 284: of_bsn_debug_counter_desc_stats_entry */
    16,   /* 285: of_bsn_debug_counter_stats_entry */
    8,    /* 286: of_bsn_flow_checksum_bucket_stats_entry */
    2,    /* 287: of_bsn_generic_stats_entry */
    16,   /* 288: of_bsn_gentable_bucket_stats_entry */
    48,   /* 289: of_bsn_gentable_desc_stats_entry */
    20,   /* 290: of_bsn_gentable_entry_desc_stats_entry */
    4,    /* 291: of_bsn_gentable_entry_stats_entry */
    24,   /* 292: of_bsn_gentable_stats_entry */
    32,   /* 293: of_bsn_interface */
    36,   /* 294: of_bsn_lacp_stats_entry */
    8,    /* 295: of_bsn_port_counter_stats_entry */
    256,  /* 296: of_bsn_switch_pipeline_stats_entry */
    9,    /* 297: of_bsn_table_checksum_stats_entry */
    4,    /* 298: of_bsn_tlv */
    6,    /* 299: of_bsn_tlv_actor_key */
    6,    /* 300: of_bsn_tlv_actor_port_num */
    6,    /* 301: of_bsn_tlv_actor_port_priority */
    5,    /* 302: of_bsn_tlv_actor_state */
    10,   /* 303: of_bsn_tlv_actor_system_mac */
    6,    /* 304: of_bsn_tlv_actor_system_priority */
    6,    /* 305: of_bsn_tlv_anchor */
    8,    /* 306: of_bsn_tlv_broadcast_query_timeout */
    8,    /* 307: of_bsn_tlv_broadcast_rate */
    4,    /* 308: of_bsn_tlv_bucket */
    4,    /* 309: of_bsn_tlv_circuit_id */
    5,    /* 310: of_bsn_tlv_convergence_status */
    5,    /* 311: of_bsn_tlv_crc_enabled */
    4,    /* 312: of_bsn_tlv_data */
    6,    /* 313: of_bsn_tlv_decap */
    10,   /* 314: of_bsn_tlv_eth_dst */
    10,   /* 315: of_bsn_tlv_eth_src */
    8,    /* 316: of_bsn_tlv_external_gateway_ip */
    10,   /* 317: of_bsn_tlv_external_gateway_mac */
    8,    /* 318: of_bsn_tlv_external_ip */
    10,   /* 319: of_bsn_tlv_external_mac */
    8,    /* 320: of_bsn_tlv_external_netmask */
    12,   /* 321: of_bsn_tlv_generation_id */
    8,    /* 322: of_bsn_tlv_header_size */
    5,    /* 323: of_bsn_tlv_icmp_code */
    6,    /* 324: of_bsn_tlv_icmp_id */
    5,    /* 325: of_bsn_tlv_icmp_type */
    4,    /* 326: of_bsn_tlv_idle_notification */
    12,   /* 327: of_bsn_tlv_idle_time */
    8,    /* 328: of_bsn_tlv_idle_timeout */
    4,    /* 329: of_bsn_tlv_igmp_snooping */
    10,   /* 330: of_bsn_tlv_internal_gateway_mac */
    10,   /* 331: of_bsn_tlv_internal_mac */
    8,    /* 332: of_bsn_tlv_interval */
    5,    /* 333: of_bsn_tlv_ip_proto */
    8,    /* 334: of_bsn_tlv_ipv4 */
    8,    /* 335: of_bsn_tlv_ipv4_dst */
    8,    /* 336: of_bsn_tlv_ipv4_netmask */
    8,    /* 337: of_bsn_tlv_ipv4_src */
    20,   /* 338: of_bsn_tlv_ipv6 */
    8,    /* 339: of_bsn_tlv_known_multicast_rate */
    4,    /* 340: of_bsn_tlv_l2_multicast_lookup */
    10,   /* 341: of_bsn_tlv_mac */
    10,   /* 342: of_bsn_tlv_mac_mask */
    4,    /* 343: of_bsn_tlv_mcg_type_vxlan */
    12,   /* 344: of_bsn_tlv_miss_packets */
    5,    /* 345: of_bsn_tlv_mpls_control_word */
    8,    /* 346: of_bsn_tlv_mpls_label */
    5,    /* 347: of_bsn_tlv_mpls_sequenced */
    8,    /* 348: of_bsn_tlv_multicast_interface_id */
    4,    /* 349: of_bsn_tlv_name */
    4,    /* 350: of_bsn_tlv_negate */
    4,    /* 351: of_bsn_tlv_nexthop_type_vxlan */
    6,    /* 352: of_bsn_tlv_offset */
    6,    /* 353: of_bsn_tlv_partner_key */
    6,    /* 354: of_bsn_tlv_partner_port_num */
    6,    /* 355: of_bsn_tlv_partner_port_priority */
    5,    /* 356: of_bsn_tlv_partner_state */
    10,   /* 357: of_bsn_tlv_partner_system_mac */
    6,    /* 358: of_bsn_tlv_partner_system_priority */
    8,    /* 359: of_bsn_tlv_port */
    5,    /* 360: of_bsn_tlv_port_vxlan_mode */
    8,    /* 361: of_bsn_tlv_priority */
    8,    /* 362: of_bsn_tlv_queue_id */
    8,    /* 363: of_bsn_tlv_queue_weight */
    5,    /* 364: of_bsn_tlv_rate_unit */
    6,    /* 365: of_bsn_tlv_reference */
    12,   /* 366: of_bsn_tlv_reply_packets */
    12,   /* 367: of_bsn_tlv_request_packets */
    12,   /* 368: of_bsn_tlv_rx_bytes */
    12,   /* 369: of_bsn_tlv_rx_packets */
    8,    /* 370: of_bsn_tlv_sampling_rate */
    4,    /* 371: of_bsn_tlv_set_loopback_mode */
    4,    /* 372: of_bsn_tlv_strip_mpls_l2_on_ingress */
    4,    /* 373: of_bsn_tlv_strip_mpls_l3_on_ingress */
    4,    /* 374: of_bsn_tlv_strip_vlan_on_egress */
    8,    /* 375: of_bsn_tlv_sub_agent_id */
    6,    /* 376: of_bsn_tlv_tcp_dst */
    6,    /* 377: of_bsn_tlv_tcp_src */
    12,   /* 378: of_bsn_tlv_tx_bytes */
    12,   /* 379: of_bsn_tlv_tx_packets */
    6,    /* 380: of_bsn_tlv_udf_anchor */
    6,    /* 381: of_bsn_tlv_udf_id */
    6,    /* 382: of_bsn_tlv_udf_length */
    6,    /* 383: of_bsn_tlv_udf_offset */
    6,    /* 384: of_bsn_tlv_udp_dst */
    6,    /* 385: of_bsn_tlv_udp_src */
    8,    /* 386: of_bsn_tlv_unicast_query_timeout */
    8,    /* 387: of_bsn_tlv_unicast_rate */
    8,    /* 388: of_bsn_tlv_unknown_multicast_rate */
    5,    /* 389: of_bsn_tlv_vlan_pcp */
    6,    /* 390: of_bsn_tlv_vlan_vid */
    6,    /* 391: of_bsn_tlv_vlan_vid_mask */
    8,    /* 392: of_bsn_tlv_vni */
    8,    /* 393: of_bsn_tlv_vrf */
    8,    /* 394: of_bsn_vlan_counter_stats_entry */
    4,    /* 395: of_bsn_vport */
    64,   /* 396: of_bsn_vport_l2gre */
    32,   /* 397: of_bsn_vport_q_in_q */
    8,    /* 398: of_bsn_vrf_counter_stats_entry */
    16,   /* 399: of_bucket */
    16,   /* 400: of_bucket_counter */
    4,    /* 401: of_bundle_prop */
    12,   /* 402: of_bundle_prop_experimenter */
    56,   /* 403: of_flow_stats_entry */
    8,    /* 404: of_group_desc_stats_entry */
    40,   /* 405: of_group_stats_entry */
    4,    /* 406: of_hello_elem */
    4,    /* 407: of_hello_elem_versionbitmap */
    4,    /* 408: of_instruction */
    8,    /* 409: of_instruction_apply_actions */
    16,   /* 410: of_instruction_bsn */
    16,   /* 411: of_instruction_bsn_arp_offload */
    16,   /* 412: of_instruction_bsn_auto_negotiation */
    16,   /* 413: of_instruction_bsn_deny */
    16,   /* 414: of_instruction_bsn_dhcp_offload */
    16,   /* 415: of_instruction_bsn_disable_l3 */
    -1,   /* 416: of_instruction_bsn_disable_split_horizon_check */
    16,   /* 417: of_instruction_bsn_disable_src_mac_check */
    16,   /* 418: of_instruction_bsn_disable_vlan_counters */
    16,   /* 419: of_instruction_bsn_internal_priority */
    16,   /* 420: of_instruction_bsn_packet_of_death */
    16,   /* 421: of_instruction_bsn_permit */
    16,   /* 422: of_instruction_bsn_prioritize_pdus */
    16,   /* 423: of_instruction_bsn_require_vlan_xlate */
    16,   /* 424: of_instruction_bsn_span_destination */
    8,    /* 425: of_instruction_clear_actions */
    8,    /* 426: of_instruction_experimenter */
    8,    /* 427: of_instruction_goto_table */
    4,    /* 428: of_instruction_id */
    4,    /* 429: of_instruction_id_apply_actions */
    12,   /* 430: of_instruction_id_bsn */
    12,   /* 431: of_instruction_id_bsn_arp_offload */
    12,   /* 432: of_instruction_id_bsn_auto_negotiation */
    12,   /* 433: of_instruction_id_bsn_deny */
    12,   /* 434: of_instruction_id_bsn_dhcp_offload */
    12,   /* 435: of_instruction_id_bsn_disable_l3 */
    -1,   /* 436: of_instruction_id_bsn_disable_split_horizon_check */
    12,   /* 437: of_instruction_id_bsn_disable_src_mac_check */
    12,   /* 438: of_instruction_id_bsn_disable_vlan_counters */
    12,   /* 439: of_instruction_id_bsn_internal_priority */
    12,   /* 440: of_instruction_id_bsn_packet_of_death */
    12,   /* 441: of_instruction_id_bsn_permit */
    12,   /* 442: of_instruction_id_bsn_prioritize_pdus */
    12,   /* 443: of_instruction_id_bsn_require_vlan_xlate */
    12,   /* 444: of_instruction_id_bsn_span_destination */
    4,    /* 445: of_instruction_id_clear_actions */
    8,    /* 446: of_instruction_id_experimenter */
    4,    /* 447: of_instruction_id_goto_table */
    4,    /* 448: of_instruction_id_meter */
    4,    /* 449: of_instruction_id_write_actions */
    4,    /* 450: of_instruction_id_write_metadata */
    8,    /* 451: of_instruction_meter */
    8,    /* 452: of_instruction_write_actions */
    24,   /* 453: of_instruction_write_metadata */
    -1,   /* 454: of_match_v1 */
    -1,   /* 455: of_match_v2 */
    4,    /* 456: of_match_v3 */
    4,    /* 457: of_meter_band */
    16,   /* 458: of_meter_band_drop */
    16,   /* 459: of_meter_band_dscp_remark */
    16,   /* 460: of_meter_band_experimenter */
    16,   /* 461: of_meter_band_stats */
    8,    /* 462: of_meter_config */
    16,   /* 463: of_meter_features */
    40,   /* 464: of_meter_stats */
    4,    /* 465: of_oxm */
    6,    /* 466: of_oxm_arp_op */
    8,    /* 467: of_oxm_arp_op_masked */
    10,   /* 468: of_oxm_arp_sha */
    16,   /* 469: of_oxm_arp_sha_masked */
    8,    /* 470: of_oxm_arp_spa */
    12,   /* 471: of_oxm_arp_spa_masked */
    10,   /* 472: of_oxm_arp_tha */
    16,   /* 473: of_oxm_arp_tha_masked */
    8,    /* 474: of_oxm_arp_tpa */
    12,   /* 475: of_oxm_arp_tpa_masked */
    8,    /* 476: of_oxm_bsn_egr_port_group_id */
    12,   /* 477: of_oxm_bsn_egr_port_group_id_masked */
    -1,   /* 478: of_oxm_bsn_global_vrf_allowed */
    -1,   /* 479: of_oxm_bsn_global_vrf_allowed_masked */
    20,   /* 480: of_oxm_bsn_in_ports_128 */
    36,   /* 481: of_oxm_bsn_in_ports_128_masked */
    68,   /* 482: of_oxm_bsn_in_ports_512 */
    132,  /* 483: of_oxm_bsn_in_ports_512_masked */
    8,    /* 484: of_oxm_bsn_ingress_port_group_id */
    12,   /* 485: of_oxm_bsn_ingress_port_group_id_masked */
    10,   /* 486: of_oxm_bsn_inner_eth_dst */
    16,   /* 487: of_oxm_bsn_inner_eth_dst_masked */
    10,   /* 488: of_oxm_bsn_inner_eth_src */
    16,   /* 489: of_oxm_bsn_inner_eth_src_masked */
    6,    /* 490: of_oxm_bsn_inner_vlan_vid */
    8,    /* 491: of_oxm_bsn_inner_vlan_vid_masked */
    -1,   /* 492: of_oxm_bsn_l2_cache_hit */
    -1,   /* 493: of_oxm_bsn_l2_cache_hit_masked */
    -1,   /* 494: of_oxm_bsn_l3_dst_class_id */
    -1,   /* 495: of_oxm_bsn_l3_dst_class_id_masked */
    8,    /* 496: of_oxm_bsn_l3_interface_class_id */
    12,   /* 497: of_oxm_bsn_l3_interface_class_id_masked */
    8,    /* 498: of_oxm_bsn_l3_src_class_id */
    12,   /* 499: of_oxm_bsn_l3_src_class_id_masked */
    8,    /* 500: of_oxm_bsn_lag_id */
    12,   /* 501: of_oxm_bsn_lag_id_masked */
    6,    /* 502: of_oxm_bsn_tcp_flags */
    8,    /* 503: of_oxm_bsn_tcp_flags_masked */
    8,    /* 504: of_oxm_bsn_udf0 */
    12,   /* 505: of_oxm_bsn_udf0_masked */
    8,    /* 506: of_oxm_bsn_udf1 */
    12,   /* 507: of_oxm_bsn_udf1_masked */
    8,    /* 508: of_oxm_bsn_udf2 */
    12,   /* 509: of_oxm_bsn_udf2_masked */
    8,    /* 510: of_oxm_bsn_udf3 */
    12,   /* 511: of_oxm_bsn_udf3_masked */
    8,    /* 512: of_oxm_bsn_udf4 */
    12,   /* 513: of_oxm_bsn_udf4_masked */
    8,    /* 514: of_oxm_bsn_udf5 */
    12,   /* 515: of_oxm_bsn_udf5_masked */
    8,    /* 516: of_oxm_bsn_udf6 */
    12,   /* 517: of_oxm_bsn_udf6_masked */
    8,    /* 518: of_oxm_bsn_udf7 */
    12,   /* 519: of_oxm_bsn_udf7_masked */
    8,    /* 520: of_oxm_bsn_vlan_xlate_port_group_id */
    12,   /* 521: of_oxm_bsn_vlan_xlate_port_group_id_masked */
    8,    /* 522: of_oxm_bsn_vrf */
    12,   /* 523: of_oxm_bsn_vrf_masked */
    8,    /* 524: of_oxm_bsn_vxlan_network_id */
    12,   /* 525: of_oxm_bsn_vxlan_network_id_masked */
    10,   /* 526: of_oxm_eth_dst */
    16,   /* 527: of_oxm_eth_dst_masked */
    10,   /* 528: of_oxm_eth_src */
    16,   /* 529: of_oxm_eth_src_masked */
    6,    /* 530: of_oxm_eth_type */
    8,    /* 531: of_oxm_eth_type_masked */
    5,    /* 532: of_oxm_icmpv4_code */
    6,    /* 533: of_oxm_icmpv4_code_masked */
    5,    /* 534: of_oxm_icmpv4_type */
    6,    /* 535: of_oxm_icmpv4_type_masked */
    5,    /* 536: of_oxm_icmpv6_code */
    6,    /* 537: of_oxm_icmpv6_code_masked */
    5,    /* 538: of_oxm_icmpv6_type */
    6,    /* 539: of_oxm_icmpv6_type_masked */
    8,    /* 540: of_oxm_in_phy_port */
    12,   /* 541: of_oxm_in_phy_port_masked */
    8,    /* 542: of_oxm_in_port */
    12,   /* 543: of_oxm_in_port_masked */
    5,    /* 544: of_oxm_ip_dscp */
    6,    /* 545: of_oxm_ip_dscp_masked */
    5,    /* 546: of_oxm_ip_ecn */
    6,    /* 547: of_oxm_ip_ecn_masked */
    5,    /* 548: of_oxm_ip_proto */
    6,    /* 549: of_oxm_ip_proto_masked */
    8,    /* 550: of_oxm_ipv4_dst */
    12,   /* 551: of_oxm_ipv4_dst_masked */
    8,    /* 552: of_oxm_ipv4_src */
    12,   /* 553: of_oxm_ipv4_src_masked */
    20,   /* 554: of_oxm_ipv6_dst */
    36,   /* 555: of_oxm_ipv6_dst_masked */
    6,    /* 556: of_oxm_ipv6_exthdr */
    8,    /* 557: of_oxm_ipv6_exthdr_masked */
    8,    /* 558: of_oxm_ipv6_flabel */
    12,   /* 559: of_oxm_ipv6_flabel_masked */
    10,   /* 560: of_oxm_ipv6_nd_sll */
    16,   /* 561: of_oxm_ipv6_nd_sll_masked */
    20,   /* 562: of_oxm_ipv6_nd_target */
    36,   /* 563: of_oxm_ipv6_nd_target_masked */
    10,   /* 564: of_oxm_ipv6_nd_tll */
    16,   /* 565: of_oxm_ipv6_nd_tll_masked */
    20,   /* 566: of_oxm_ipv6_src */
    36,   /* 567: of_oxm_ipv6_src_masked */
    12,   /* 568: of_oxm_metadata */
    20,   /* 569: of_oxm_metadata_masked */
    5,    /* 570: of_oxm_mpls_bos */
    6,    /* 571: of_oxm_mpls_bos_masked */
    8,    /* 572: of_oxm_mpls_label */
    12,   /* 573: of_oxm_mpls_label_masked */
    5,    /* 574: of_oxm_mpls_tc */
    6,    /* 575: of_oxm_mpls_tc_masked */
    5,    /* 576: of_oxm_pbb_uca */
    6,    /* 577: of_oxm_pbb_uca_masked */
    6,    /* 578: of_oxm_sctp_dst */
    8,    /* 579: of_oxm_sctp_dst_masked */
    6,    /* 580: of_oxm_sctp_src */
    8,    /* 581: of_oxm_sctp_src_masked */
    6,    /* 582: of_oxm_tcp_dst */
    8,    /* 583: of_oxm_tcp_dst_masked */
    6,    /* 584: of_oxm_tcp_src */
    8,    /* 585: of_oxm_tcp_src_masked */
    12,   /* 586: of_oxm_tunnel_id */
    20,   /* 587: of_oxm_tunnel_id_masked */
    8,    /* 588: of_oxm_tunnel_ipv4_dst */
    12,   /* 589: of_oxm_tunnel_ipv4_dst_masked */
    8,    /* 590: of_oxm_tunnel_ipv4_src */
    12,   /* 591: of_oxm_tunnel_ipv4_src_masked */
    6,    /* 592: of_oxm_udp_dst */
    8,    /* 593: of_oxm_udp_dst_masked */
    6,    /* 594: of_oxm_udp_src */
    8,    /* 595: of_oxm_udp_src_masked */
    5,    /* 596: of_oxm_vlan_pcp */
    6,    /* 597: of_oxm_vlan_pcp_masked */
    6,    /* 598: of_oxm_vlan_vid */
    8,    /* 599: of_oxm_vlan_vid_masked */
    16,   /* 600: of_packet_queue */
    40,   /* 601: of_port_desc */
    4,    /* 602: of_port_desc_prop */
    12,   /* 603: of_port_desc_prop_bsn */
    20,   /* 604: of_port_desc_prop_bsn_generation_id */
    12,   /* 605: of_port_desc_prop_bsn_uplink */
    32,   /* 606: of_port_desc_prop_ethernet */
    8,    /* 607: of_port_desc_prop_experimenter */
    44,   /* 608: of_port_desc_prop_optical */
    4,    /* 609: of_port_mod_prop */
    8,    /* 610: of_port_mod_prop_ethernet */
    12,   /* 611: of_port_mod_prop_experimenter */
    24,   /* 612: of_port_mod_prop_optical */
    80,   /* 613: of_port_stats_entry */
    4,    /* 614: of_port_stats_prop */
    40,   /* 615: of_port_stats_prop_ethernet */
    12,   /* 616: of_port_stats_prop_experimenter */
    44,   /* 617: of_port_stats_prop_optical */
    16,   /* 618: of_queue_desc */
    4,    /* 619: of_queue_desc_prop */
    12,   /* 620: of_queue_desc_prop_experimenter */
    8,    /* 621: of_queue_desc_prop_max_rate */
    8,    /* 622: of_queue_desc_prop_min_rate */
    8,    /* 623: of_queue_prop */
    16,   /* 624: of_queue_prop_experimenter */
    16,   /* 625: of_queue_prop_max_rate */
    16,   /* 626: of_queue_prop_min_rate */
    48,   /* 627: of_queue_stats_entry */
    4,    /* 628: of_queue_stats_prop */
    12,   /* 629: of_queue_stats_prop_experimenter */
    4,    /* 630: of_role_prop */
    12,   /* 631: of_role_prop_experimenter */
    8,    /* 632: of_table_desc */
    4,    /* 633: of_table_feature_prop */
    4,    /* 634: of_table_feature_prop_apply_actions */
    4,    /* 635: of_table_feature_prop_apply_actions_miss */
    4,    /* 636: of_table_feature_prop_apply_setfield */
    4,    /* 637: of_table_feature_prop_apply_setfield_miss */
    12,   /* 638: of_table_feature_prop_experimenter */
    12,   /* 639: of_table_feature_prop_experimenter_miss */
    4,    /* 640: of_table_feature_prop_instructions */
    4,    /* 641: of_table_feature_prop_instructions_miss */
    4,    /* 642: of_table_feature_prop_match */
    4,    /* 643: of_table_feature_prop_next_tables */
    4,    /* 644: of_table_feature_prop_next_tables_miss */
    4,    /* 645: of_table_feature_prop_table_sync_from */
    4,    /* 646: of_table_feature_prop_wildcards */
    4,    /* 647: of_table_feature_prop_write_actions */
    4,    /* 648: of_table_feature_prop_write_actions_miss */
    4,    /* 649: of_table_feature_prop_write_setfield */
    4,    /* 650: of_table_feature_prop_write_setfield_miss */
    64,   /* 651: of_table_features */
    4,    /* 652: of_table_mod_prop */
    8,    /* 653: of_table_mod_prop_eviction */
    12,   /* 654: of_table_mod_prop_experimenter */
    8,    /* 655: of_table_mod_prop_vacancy */
    24,   /* 656: of_table_stats_entry */
    4,    /* 657: of_uint32 */
    8,    /* 658: of_uint64 */
    1,    /* 659: of_uint8 */
    0,    /* 660: of_list_action */
    0,    /* 661: of_list_action_id */
    0,    /* 662: of_list_async_config_prop */
    0,    /* 663: of_list_bsn_controller_connection */
    0,    /* 664: of_list_bsn_debug_counter_desc_stats_entry */
    0,    /* 665: of_list_bsn_debug_counter_stats_entry */
    0,    /* 666: of_list_bsn_flow_checksum_bucket_stats_entry */
    0,    /* 667: of_list_bsn_generic_stats_entry */
    0,    /* 668: of_list_bsn_gentable_bucket_stats_entry */
    0,    /* 669: of_list_bsn_gentable_desc_stats_entry */
    0,    /* 670: of_list_bsn_gentable_entry_desc_stats_entry */
    0,    /* 671: of_list_bsn_gentable_entry_stats_entry */
    0,    /* 672: of_list_bsn_gentable_stats_entry */
    0,    /* 673: of_list_bsn_interface */
    0,    /* 674: of_list_bsn_lacp_stats_entry */
    0,    /* 675: of_list_bsn_port_counter_stats_entry */
    0,    /* 676: of_list_bsn_switch_pipeline_stats_entry */
    0,    /* 677: of_list_bsn_table_checksum_stats_entry */
    0,    /* 678: of_list_bsn_tlv */
    0,    /* 679: of_list_bsn_vlan_counter_stats_entry */
    0,    /* 680: of_list_bsn_vrf_counter_stats_entry */
    0,    /* 681: of_list_bucket */
    0,    /* 682: of_list_bucket_counter */
    0,    /* 683: of_list_bundle_prop */
    0,    /* 684: of_list_flow_stats_entry */
    0,    /* 685: of_list_group_desc_stats_entry */
    0,    /* 686: of_list_group_stats_entry */
    0,    /* 687: of_list_hello_elem */
    0,    /* 688: of_list_instruction */
    0,    /* 689: of_list_instruction_id */
    0,    /* 690: of_list_meter_band */
    0,    /* 691: of_list_meter_band_stats */
    0,    /* 692: of_list_meter_config */
    0,    /* 693: of_list_meter_stats */
    0,    /* 694: of_list_oxm */
    -1,   /* 695: of_list_packet_queue */
    0,    /* 696: of_list_port_desc */
    0,    /* 697: of_list_port_desc_prop */
    0,    /* 698: of_list_port_mod_prop */
    0,    /* 699: of_list_port_stats_entry */
    0,    /* 700: of_list_port_stats_prop */
    0,    /* 701: of_list_queue_desc */
    0,    /* 702: of_list_queue_desc_prop */
    0,    /* 703: of_list_queue_prop */
    0,    /* 704: of_list_queue_stats_entry */
    0,    /* 705: of_list_queue_stats_prop */
    0,    /* 706: of_list_role_prop */
    0,    /* 707: of_list_table_desc */
    0,    /* 708: of_list_table_feature_prop */
    0,    /* 709: of_list_table_features */
    0,    /* 710: of_list_table_mod_prop */
    0,    /* 711: of_list_table_stats_entry */
    0,    /* 712: of_list_uint32 */
    0,    /* 713: of_list_uint64 */
    0     /* 714: of_list_uint8 */
};

/**
 * Unified map of fixed length part of each object
 */
const int *const of_object_fixed_len[OF_VERSION_ARRAY_MAX] = {
    NULL,
    of_object_fixed_len_v1,
    of_object_fixed_len_v2,
    of_object_fixed_len_v3,
    of_object_fixed_len_v4,
    of_object_fixed_len_v5,

};


/****************************************************************
 * Top level OpenFlow message length functions
 ****************************************************************/

/**
 * Get the length of a message object as reported on the wire
 * @param obj The object to check
 * @param bytes (out) Where the length is stored
 * @returns OF_ERROR_ code
 */
void
of_object_message_wire_length_get(of_object_t *obj, int *bytes)
{
    LOCI_ASSERT(OF_OBJECT_TO_WBUF(obj) != NULL);
    // LOCI_ASSERT(obj is message)
    *bytes = of_message_length_get(OF_OBJECT_TO_MESSAGE(obj));
}

/**
 * Set the length of a message object as reported on the wire
 * @param obj The object to check
 * @param bytes The new length of the object
 * @returns OF_ERROR_ code
 */
void
of_object_message_wire_length_set(of_object_t *obj, int bytes)
{
    LOCI_ASSERT(OF_OBJECT_TO_WBUF(obj) != NULL);
    // LOCI_ASSERT(obj is message)
    of_message_length_set(OF_OBJECT_TO_MESSAGE(obj), bytes);
}

/****************************************************************
 * TLV16 type/length functions
 ****************************************************************/

/**
 * Many objects are TLVs and use uint16 for the type and length values
 * stored on the wire at the beginning of the buffer.
 */
#define TLV16_WIRE_TYPE_OFFSET 0
#define TLV16_WIRE_LENGTH_OFFSET 2

/**
 * Get the length field from the wire for a standard TLV
 * object that uses uint16 for both type and length.
 * @param obj The object being referenced
 * @param bytes (out) Where to store the length
 */

void
of_tlv16_wire_length_get(of_object_t *obj, int *bytes)
{
    uint16_t val16;
    of_wire_buffer_t *wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    of_wire_buffer_u16_get(wbuf, 
           OF_OBJECT_ABSOLUTE_OFFSET(obj, TLV16_WIRE_LENGTH_OFFSET), &val16);
    *bytes = val16;
}

/**
 * Set the length field in the wire buffer for a standard TLV
 * object that uses uint16 for both type and length.
 * @param obj The object being referenced
 * @param bytes The length value to use
 */

void
of_tlv16_wire_length_set(of_object_t *obj, int bytes)
{
    of_wire_buffer_t *wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    of_wire_buffer_u16_set(wbuf, 
        OF_OBJECT_ABSOLUTE_OFFSET(obj, TLV16_WIRE_LENGTH_OFFSET), bytes);
}


/****************************************************************
 * OXM type/length functions.
 ****************************************************************/

/* Where does the OXM type-length header lie in the buffer */
#define OXM_HDR_OFFSET 0

/**
 * Get the OXM header (type-length fields) from the wire buffer
 * associated with an OXM object
 *
 * Will return if error; set hdr to the OXM header
 */

#define _GET_OXM_TYPE_LEN(obj, tl_p, wbuf) do {                         \
        wbuf = OF_OBJECT_TO_WBUF(obj);                                  \
        LOCI_ASSERT(wbuf != NULL);                                           \
        of_wire_buffer_u32_get(wbuf,                                    \
            OF_OBJECT_ABSOLUTE_OFFSET(obj, OXM_HDR_OFFSET), (tl_p));    \
    } while (0)

#define _SET_OXM_TYPE_LEN(obj, tl_p, wbuf) do {                         \
        wbuf = OF_OBJECT_TO_WBUF(obj);                                  \
        LOCI_ASSERT(wbuf != NULL);                                           \
        of_wire_buffer_u32_set(wbuf,                                    \
            OF_OBJECT_ABSOLUTE_OFFSET(obj, OXM_HDR_OFFSET), (tl_p));    \
    } while (0)

/**
 * Get the length of an OXM object from the wire buffer
 * @param obj The object whose wire buffer is an OXM type
 * @param bytes (out) Where length is stored 
 */

void
of_oxm_wire_length_get(of_object_t *obj, int *bytes)
{
    uint32_t type_len;
    of_wire_buffer_t *wbuf;

    _GET_OXM_TYPE_LEN(obj, &type_len, wbuf);
    *bytes = OF_OXM_LENGTH_GET(type_len);
}

#define OF_U16_LEN_LENGTH_OFFSET 0

/**
 * Get the wire length for an object with a uint16 length as first member
 * @param obj The object being referenced
 * @param bytes Pointer to location to store length
 */
void
of_u16_len_wire_length_get(of_object_t *obj, int *bytes)
{
    of_wire_buffer_t *wbuf = OF_OBJECT_TO_WBUF(obj);
    uint16_t u16;

    LOCI_ASSERT(wbuf != NULL);

    of_wire_buffer_u16_get(wbuf, 
           OF_OBJECT_ABSOLUTE_OFFSET(obj, OF_U16_LEN_LENGTH_OFFSET),
           &u16);

    *bytes = u16;
}

/**
 * Set the wire length for an object with a uint16 length as first member
 * @param obj The object being referenced
 * @param bytes The length of the object
 */

void
of_u16_len_wire_length_set(of_object_t *obj, int bytes)
{
    of_wire_buffer_t *wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* LOCI_ASSERT(obj is u16-len entry) */

    of_wire_buffer_u16_set(wbuf, 
           OF_OBJECT_ABSOLUTE_OFFSET(obj, OF_U16_LEN_LENGTH_OFFSET),
           bytes);
}


#define OF_PACKET_QUEUE_LENGTH_OFFSET(ver) \
    (((ver) >= OF_VERSION_1_2) ? 8 : 4)

/**
 * Get the wire length for a packet queue object
 * @param obj The object being referenced
 * @param bytes Pointer to location to store length
 *
 * The length is a uint16 at the offset indicated above
 */
void
of_packet_queue_wire_length_get(of_object_t *obj, int *bytes)
{
    of_wire_buffer_t *wbuf = OF_OBJECT_TO_WBUF(obj);
    uint16_t u16;
    int offset;

    LOCI_ASSERT(wbuf != NULL);

    /* LOCI_ASSERT(obj is packet queue obj) */
    offset = OF_PACKET_QUEUE_LENGTH_OFFSET(obj->version);
    of_wire_buffer_u16_get(wbuf, OF_OBJECT_ABSOLUTE_OFFSET(obj, offset),
                           &u16);

    *bytes = u16;
}

/**
 * Set the wire length for a 1.2 packet queue object
 * @param obj The object being referenced
 * @param bytes The length of the object
 *
 * The length is a uint16 at the offset indicated above
 */

void
of_packet_queue_wire_length_set(of_object_t *obj, int bytes)
{
    of_wire_buffer_t *wbuf = OF_OBJECT_TO_WBUF(obj);
    int offset;

    LOCI_ASSERT(wbuf != NULL);

    /* LOCI_ASSERT(obj is packet queue obj) */
    offset = OF_PACKET_QUEUE_LENGTH_OFFSET(obj->version);
    of_wire_buffer_u16_set(wbuf, OF_OBJECT_ABSOLUTE_OFFSET(obj, offset),
                                  bytes);
}

/**
 * Get the wire length for a meter band stats list
 * @param obj The object being referenced
 * @param bytes Pointer to location to store length
 *
 * Must a meter_stats object as a parent
 */

void
of_list_meter_band_stats_wire_length_get(of_object_t *obj, int *bytes)
{
    LOCI_ASSERT(obj->parent != NULL);
    LOCI_ASSERT(obj->parent->object_id == OF_METER_STATS);

    /* We're counting on the parent being properly initialized already.
     * The length is stored in a uint16 at offset 4 of the parent.
     */
    *bytes = obj->parent->length - OF_OBJECT_FIXED_LENGTH(obj->parent);
}

#define OF_METER_STATS_LENGTH_OFFSET 4

/**
 * Get/set the wire length for a meter stats object
 * @param obj The object being referenced
 * @param bytes Pointer to location to store length
 *
 * It's almost a TLV....
 */

void
of_meter_stats_wire_length_get(of_object_t *obj, int *bytes)
{
    uint16_t val16;
    of_wire_buffer_t *wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);
    of_wire_buffer_u16_get(wbuf, 
               OF_OBJECT_ABSOLUTE_OFFSET(obj, OF_METER_STATS_LENGTH_OFFSET),
               &val16);
    *bytes = val16;
}

void
of_meter_stats_wire_length_set(of_object_t *obj, int bytes)
{
    of_wire_buffer_t *wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    of_wire_buffer_u16_set(wbuf, 
        OF_OBJECT_ABSOLUTE_OFFSET(obj, OF_METER_STATS_LENGTH_OFFSET), bytes);
}

/**
 * Get the wire length for a port desc object
 * @param obj The object being referenced
 * @param bytes Pointer to location to store length
 *
 * The length is only present for OF 1.4+.
 */
void
of_port_desc_wire_length_get(of_object_t *obj, int *bytes)
{
    of_wire_buffer_t *wbuf = OF_OBJECT_TO_WBUF(obj);
    uint16_t u16;

    LOCI_ASSERT(wbuf != NULL);

    if (obj->version >= OF_VERSION_1_4) {
        of_wire_buffer_u16_get(wbuf, OF_OBJECT_ABSOLUTE_OFFSET(obj, 4),
                               &u16);
        *bytes = u16;
    } else {
        *bytes = OF_OBJECT_FIXED_LENGTH(obj);
    }
}

/**
 * Set the wire length for a port desc object
 * @param obj The object being referenced
 * @param bytes The length of the object
 *
 * The length is only present for OF 1.4+.
 */

void
of_port_desc_wire_length_set(of_object_t *obj, int bytes)
{
    of_wire_buffer_t *wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    if (obj->version >= OF_VERSION_1_4) {
        of_wire_buffer_u16_set(wbuf, OF_OBJECT_ABSOLUTE_OFFSET(obj, 4),
                               bytes);
    } else {
        LOCI_ASSERT(obj->length == OF_OBJECT_FIXED_LENGTH(obj));
    }
}

/**
 * Get the wire length for a port stats_entry object
 * @param obj The object being referenced
 * @param bytes Pointer to location to store length
 *
 * The length is only present for OF 1.4+.
 */
void
of_port_stats_entry_wire_length_get(of_object_t *obj, int *bytes)
{
    of_wire_buffer_t *wbuf = OF_OBJECT_TO_WBUF(obj);
    uint16_t u16;

    LOCI_ASSERT(wbuf != NULL);

    if (obj->version >= OF_VERSION_1_4) {
        of_wire_buffer_u16_get(wbuf, OF_OBJECT_ABSOLUTE_OFFSET(obj, 0),
                               &u16);
        *bytes = u16;
    } else {
        *bytes = OF_OBJECT_FIXED_LENGTH(obj);
    }
}

/**
 * Set the wire length for a port stats_entry object
 * @param obj The object being referenced
 * @param bytes The length of the object
 *
 * The length is only present for OF 1.4+.
 */

void
of_port_stats_entry_wire_length_set(of_object_t *obj, int bytes)
{
    of_wire_buffer_t *wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    if (obj->version >= OF_VERSION_1_4) {
        of_wire_buffer_u16_set(wbuf, OF_OBJECT_ABSOLUTE_OFFSET(obj, 0),
                               bytes);
    } else {
        LOCI_ASSERT(obj->length == OF_OBJECT_FIXED_LENGTH(obj));
    }
}

/**
 * Get the wire length for a queue stats_entry object
 * @param obj The object being referenced
 * @param bytes Pointer to location to store length
 *
 * The length is only present for OF 1.4+.
 */
void
of_queue_stats_entry_wire_length_get(of_object_t *obj, int *bytes)
{
    of_wire_buffer_t *wbuf = OF_OBJECT_TO_WBUF(obj);
    uint16_t u16;

    LOCI_ASSERT(wbuf != NULL);

    if (obj->version >= OF_VERSION_1_4) {
        of_wire_buffer_u16_get(wbuf, OF_OBJECT_ABSOLUTE_OFFSET(obj, 0),
                               &u16);
        *bytes = u16;
    } else {
        *bytes = OF_OBJECT_FIXED_LENGTH(obj);
    }
}

/**
 * Set the wire length for a queue stats_entry object
 * @param obj The object being referenced
 * @param bytes The length of the object
 *
 * The length is only present for OF 1.4+.
 */

void
of_queue_stats_entry_wire_length_set(of_object_t *obj, int bytes)
{
    of_wire_buffer_t *wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    if (obj->version >= OF_VERSION_1_4) {
        of_wire_buffer_u16_set(wbuf, OF_OBJECT_ABSOLUTE_OFFSET(obj, 0),
                               bytes);
    } else {
        LOCI_ASSERT(obj->length == OF_OBJECT_FIXED_LENGTH(obj));
    }
}

/**
 * Get the wire length for a queue_desc object
 * @param obj The object being referenced
 * @param bytes Pointer to location to store length
 */
void
of_queue_desc_wire_length_get(of_object_t *obj, int *bytes)
{
    of_wire_buffer_t *wbuf = OF_OBJECT_TO_WBUF(obj);
    uint16_t u16;

    LOCI_ASSERT(wbuf != NULL);

    of_wire_buffer_u16_get(wbuf, OF_OBJECT_ABSOLUTE_OFFSET(obj, 8), &u16);
    *bytes = u16;
}

/**
 * Set the wire length for a queue_desc object
 * @param obj The object being referenced
 * @param bytes The length of the object
 */

void
of_queue_desc_wire_length_set(of_object_t *obj, int bytes)
{
    of_wire_buffer_t *wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    of_wire_buffer_u16_set(wbuf, OF_OBJECT_ABSOLUTE_OFFSET(obj, 8), bytes);
}
