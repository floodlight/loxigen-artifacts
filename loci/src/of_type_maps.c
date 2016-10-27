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
    -1,   /* 15: of_bsn_base_error */
    20,   /* 16: of_bsn_bw_clear_data_reply */
    16,   /* 17: of_bsn_bw_clear_data_request */
    20,   /* 18: of_bsn_bw_enable_get_reply */
    16,   /* 19: of_bsn_bw_enable_get_request */
    24,   /* 20: of_bsn_bw_enable_set_reply */
    20,   /* 21: of_bsn_bw_enable_set_request */
    -1,   /* 22: of_bsn_controller_connections_reply */
    -1,   /* 23: of_bsn_controller_connections_request */
    -1,   /* 24: of_bsn_debug_counter_desc_stats_reply */
    -1,   /* 25: of_bsn_debug_counter_desc_stats_request */
    -1,   /* 26: of_bsn_debug_counter_stats_reply */
    -1,   /* 27: of_bsn_debug_counter_stats_request */
    -1,   /* 28: of_bsn_error */
    -1,   /* 29: of_bsn_flow_checksum_bucket_stats_reply */
    -1,   /* 30: of_bsn_flow_checksum_bucket_stats_request */
    -1,   /* 31: of_bsn_flow_idle */
    -1,   /* 32: of_bsn_flow_idle_enable_get_reply */
    -1,   /* 33: of_bsn_flow_idle_enable_get_request */
    -1,   /* 34: of_bsn_flow_idle_enable_set_reply */
    -1,   /* 35: of_bsn_flow_idle_enable_set_request */
    -1,   /* 36: of_bsn_generic_async */
    -1,   /* 37: of_bsn_generic_command */
    -1,   /* 38: of_bsn_generic_stats_reply */
    -1,   /* 39: of_bsn_generic_stats_request */
    -1,   /* 40: of_bsn_gentable_bucket_stats_reply */
    -1,   /* 41: of_bsn_gentable_bucket_stats_request */
    -1,   /* 42: of_bsn_gentable_clear_reply */
    -1,   /* 43: of_bsn_gentable_clear_request */
    -1,   /* 44: of_bsn_gentable_desc_stats_reply */
    -1,   /* 45: of_bsn_gentable_desc_stats_request */
    -1,   /* 46: of_bsn_gentable_entry_add */
    -1,   /* 47: of_bsn_gentable_entry_delete */
    -1,   /* 48: of_bsn_gentable_entry_desc_stats_reply */
    -1,   /* 49: of_bsn_gentable_entry_desc_stats_request */
    -1,   /* 50: of_bsn_gentable_entry_stats_reply */
    -1,   /* 51: of_bsn_gentable_entry_stats_request */
    -1,   /* 52: of_bsn_gentable_set_buckets_size */
    -1,   /* 53: of_bsn_gentable_stats_reply */
    -1,   /* 54: of_bsn_gentable_stats_request */
    16,   /* 55: of_bsn_get_interfaces_reply */
    16,   /* 56: of_bsn_get_interfaces_request */
    24,   /* 57: of_bsn_get_ip_mask_reply */
    24,   /* 58: of_bsn_get_ip_mask_request */
    24,   /* 59: of_bsn_get_l2_table_reply */
    16,   /* 60: of_bsn_get_l2_table_request */
    20,   /* 61: of_bsn_get_mirroring_reply */
    20,   /* 62: of_bsn_get_mirroring_request */
    -1,   /* 63: of_bsn_get_switch_pipeline_reply */
    -1,   /* 64: of_bsn_get_switch_pipeline_request */
    16,   /* 65: of_bsn_header */
    24,   /* 66: of_bsn_hybrid_get_reply */
    16,   /* 67: of_bsn_hybrid_get_request */
    -1,   /* 68: of_bsn_image_desc_stats_reply */
    -1,   /* 69: of_bsn_image_desc_stats_request */
    -1,   /* 70: of_bsn_lacp_convergence_notif */
    -1,   /* 71: of_bsn_lacp_stats_reply */
    -1,   /* 72: of_bsn_lacp_stats_request */
    -1,   /* 73: of_bsn_log */
    -1,   /* 74: of_bsn_lua_command_reply */
    -1,   /* 75: of_bsn_lua_command_request */
    -1,   /* 76: of_bsn_lua_notification */
    -1,   /* 77: of_bsn_lua_upload */
    23,   /* 78: of_bsn_pdu_rx_reply */
    26,   /* 79: of_bsn_pdu_rx_request */
    19,   /* 80: of_bsn_pdu_rx_timeout */
    23,   /* 81: of_bsn_pdu_tx_reply */
    26,   /* 82: of_bsn_pdu_tx_request */
    -1,   /* 83: of_bsn_port_counter_stats_reply */
    -1,   /* 84: of_bsn_port_counter_stats_request */
    -1,   /* 85: of_bsn_role_status */
    -1,   /* 86: of_bsn_set_aux_cxns_reply */
    -1,   /* 87: of_bsn_set_aux_cxns_request */
    24,   /* 88: of_bsn_set_ip_mask */
    24,   /* 89: of_bsn_set_l2_table_reply */
    24,   /* 90: of_bsn_set_l2_table_request */
    -1,   /* 91: of_bsn_set_lacp_reply */
    -1,   /* 92: of_bsn_set_lacp_request */
    20,   /* 93: of_bsn_set_mirroring */
    20,   /* 94: of_bsn_set_pktin_suppression_reply */
    32,   /* 95: of_bsn_set_pktin_suppression_request */
    -1,   /* 96: of_bsn_set_switch_pipeline_reply */
    -1,   /* 97: of_bsn_set_switch_pipeline_request */
    20,   /* 98: of_bsn_shell_command */
    16,   /* 99: of_bsn_shell_output */
    20,   /* 100: of_bsn_shell_status */
    24,   /* 101: of_bsn_stats_reply */
    24,   /* 102: of_bsn_stats_request */
    -1,   /* 103: of_bsn_switch_pipeline_stats_reply */
    -1,   /* 104: of_bsn_switch_pipeline_stats_request */
    -1,   /* 105: of_bsn_table_checksum_stats_reply */
    -1,   /* 106: of_bsn_table_checksum_stats_request */
    -1,   /* 107: of_bsn_table_set_buckets_size */
    -1,   /* 108: of_bsn_takeover */
    -1,   /* 109: of_bsn_time_reply */
    -1,   /* 110: of_bsn_time_request */
    24,   /* 111: of_bsn_virtual_port_create_reply */
    20,   /* 112: of_bsn_virtual_port_create_request */
    20,   /* 113: of_bsn_virtual_port_remove_reply */
    20,   /* 114: of_bsn_virtual_port_remove_request */
    -1,   /* 115: of_bsn_vlan_counter_clear */
    -1,   /* 116: of_bsn_vlan_counter_stats_reply */
    -1,   /* 117: of_bsn_vlan_counter_stats_request */
    -1,   /* 118: of_bsn_vrf_counter_stats_reply */
    -1,   /* 119: of_bsn_vrf_counter_stats_request */
    -1,   /* 120: of_bundle_add_msg */
    -1,   /* 121: of_bundle_ctrl_msg */
    -1,   /* 122: of_bundle_failed_error_msg */
    1068, /* 123: of_desc_stats_reply */
    12,   /* 124: of_desc_stats_request */
    8,    /* 125: of_echo_reply */
    8,    /* 126: of_echo_request */
    10,   /* 127: of_error_msg */
    12,   /* 128: of_experimenter */
    -1,   /* 129: of_experimenter_error_msg */
    16,   /* 130: of_experimenter_stats_reply */
    16,   /* 131: of_experimenter_stats_request */
    32,   /* 132: of_features_reply */
    8,    /* 133: of_features_request */
    72,   /* 134: of_flow_add */
    72,   /* 135: of_flow_delete */
    72,   /* 136: of_flow_delete_strict */
    72,   /* 137: of_flow_mod */
    12,   /* 138: of_flow_mod_failed_error_msg */
    72,   /* 139: of_flow_modify */
    72,   /* 140: of_flow_modify_strict */
    -1,   /* 141: of_flow_monitor_failed_error_msg */
    88,   /* 142: of_flow_removed */
    12,   /* 143: of_flow_stats_reply */
    56,   /* 144: of_flow_stats_request */
    12,   /* 145: of_get_config_reply */
    8,    /* 146: of_get_config_request */
    -1,   /* 147: of_group_add */
    -1,   /* 148: of_group_delete */
    -1,   /* 149: of_group_desc_stats_reply */
    -1,   /* 150: of_group_desc_stats_request */
    -1,   /* 151: of_group_features_stats_reply */
    -1,   /* 152: of_group_features_stats_request */
    -1,   /* 153: of_group_mod */
    -1,   /* 154: of_group_mod_failed_error_msg */
    -1,   /* 155: of_group_modify */
    -1,   /* 156: of_group_stats_reply */
    -1,   /* 157: of_group_stats_request */
    8,    /* 158: of_header */
    8,    /* 159: of_hello */
    12,   /* 160: of_hello_failed_error_msg */
    -1,   /* 161: of_meter_config_stats_reply */
    -1,   /* 162: of_meter_config_stats_request */
    -1,   /* 163: of_meter_features_stats_reply */
    -1,   /* 164: of_meter_features_stats_request */
    -1,   /* 165: of_meter_mod */
    -1,   /* 166: of_meter_mod_failed_error_msg */
    -1,   /* 167: of_meter_stats_reply */
    -1,   /* 168: of_meter_stats_request */
    20,   /* 169: of_nicira_controller_role_reply */
    20,   /* 170: of_nicira_controller_role_request */
    16,   /* 171: of_nicira_header */
    18,   /* 172: of_packet_in */
    16,   /* 173: of_packet_out */
    -1,   /* 174: of_port_desc_stats_reply */
    -1,   /* 175: of_port_desc_stats_request */
    32,   /* 176: of_port_mod */
    12,   /* 177: of_port_mod_failed_error_msg */
    12,   /* 178: of_port_stats_reply */
    20,   /* 179: of_port_stats_request */
    64,   /* 180: of_port_status */
    -1,   /* 181: of_queue_desc_stats_reply */
    -1,   /* 182: of_queue_desc_stats_request */
    16,   /* 183: of_queue_get_config_reply */
    12,   /* 184: of_queue_get_config_request */
    12,   /* 185: of_queue_op_failed_error_msg */
    12,   /* 186: of_queue_stats_reply */
    20,   /* 187: of_queue_stats_request */
    -1,   /* 188: of_requestforward */
    -1,   /* 189: of_role_reply */
    -1,   /* 190: of_role_request */
    -1,   /* 191: of_role_request_failed_error_msg */
    -1,   /* 192: of_role_status */
    12,   /* 193: of_set_config */
    12,   /* 194: of_stats_reply */
    12,   /* 195: of_stats_request */
    -1,   /* 196: of_switch_config_failed_error_msg */
    -1,   /* 197: of_table_desc_stats_reply */
    -1,   /* 198: of_table_desc_stats_request */
    -1,   /* 199: of_table_features_failed_error_msg */
    -1,   /* 200: of_table_features_stats_reply */
    -1,   /* 201: of_table_features_stats_request */
    16,   /* 202: of_table_mod */
    -1,   /* 203: of_table_mod_failed_error_msg */
    12,   /* 204: of_table_stats_reply */
    12,   /* 205: of_table_stats_request */
    -1,   /* 206: of_table_status */
    8,    /* 207: of_action */
    16,   /* 208: of_action_bsn */
    28,   /* 209: of_action_bsn_checksum */
    -1,   /* 210: of_action_bsn_gentable */
    24,   /* 211: of_action_bsn_mirror */
    16,   /* 212: of_action_bsn_set_tunnel_dst */
    -1,   /* 213: of_action_copy_ttl_in */
    -1,   /* 214: of_action_copy_ttl_out */
    -1,   /* 215: of_action_dec_mpls_ttl */
    -1,   /* 216: of_action_dec_nw_ttl */
    16,   /* 217: of_action_enqueue */
    8,    /* 218: of_action_experimenter */
    -1,   /* 219: of_action_group */
    -1,   /* 220: of_action_id */
    -1,   /* 221: of_action_id_bsn */
    -1,   /* 222: of_action_id_bsn_checksum */
    -1,   /* 223: of_action_id_bsn_gentable */
    -1,   /* 224: of_action_id_bsn_mirror */
    -1,   /* 225: of_action_id_bsn_set_tunnel_dst */
    -1,   /* 226: of_action_id_copy_ttl_in */
    -1,   /* 227: of_action_id_copy_ttl_out */
    -1,   /* 228: of_action_id_dec_mpls_ttl */
    -1,   /* 229: of_action_id_dec_nw_ttl */
    -1,   /* 230: of_action_id_experimenter */
    -1,   /* 231: of_action_id_group */
    -1,   /* 232: of_action_id_nicira */
    -1,   /* 233: of_action_id_nicira_dec_ttl */
    -1,   /* 234: of_action_id_output */
    -1,   /* 235: of_action_id_pop_mpls */
    -1,   /* 236: of_action_id_pop_pbb */
    -1,   /* 237: of_action_id_pop_vlan */
    -1,   /* 238: of_action_id_push_mpls */
    -1,   /* 239: of_action_id_push_pbb */
    -1,   /* 240: of_action_id_push_vlan */
    -1,   /* 241: of_action_id_set_field */
    -1,   /* 242: of_action_id_set_mpls_ttl */
    -1,   /* 243: of_action_id_set_nw_ttl */
    -1,   /* 244: of_action_id_set_queue */
    16,   /* 245: of_action_nicira */
    16,   /* 246: of_action_nicira_dec_ttl */
    8,    /* 247: of_action_output */
    -1,   /* 248: of_action_pop_mpls */
    -1,   /* 249: of_action_pop_pbb */
    -1,   /* 250: of_action_pop_vlan */
    -1,   /* 251: of_action_push_mpls */
    -1,   /* 252: of_action_push_pbb */
    -1,   /* 253: of_action_push_vlan */
    16,   /* 254: of_action_set_dl_dst */
    16,   /* 255: of_action_set_dl_src */
    -1,   /* 256: of_action_set_field */
    -1,   /* 257: of_action_set_mpls_label */
    -1,   /* 258: of_action_set_mpls_tc */
    -1,   /* 259: of_action_set_mpls_ttl */
    8,    /* 260: of_action_set_nw_dst */
    -1,   /* 261: of_action_set_nw_ecn */
    8,    /* 262: of_action_set_nw_src */
    8,    /* 263: of_action_set_nw_tos */
    -1,   /* 264: of_action_set_nw_ttl */
    -1,   /* 265: of_action_set_queue */
    8,    /* 266: of_action_set_tp_dst */
    8,    /* 267: of_action_set_tp_src */
    8,    /* 268: of_action_set_vlan_pcp */
    8,    /* 269: of_action_set_vlan_vid */
    8,    /* 270: of_action_strip_vlan */
    -1,   /* 271: of_async_config_prop */
    -1,   /* 272: of_async_config_prop_experimenter_master */
    -1,   /* 273: of_async_config_prop_experimenter_slave */
    -1,   /* 274: of_async_config_prop_flow_removed_master */
    -1,   /* 275: of_async_config_prop_flow_removed_slave */
    -1,   /* 276: of_async_config_prop_packet_in_master */
    -1,   /* 277: of_async_config_prop_packet_in_slave */
    -1,   /* 278: of_async_config_prop_port_status_master */
    -1,   /* 279: of_async_config_prop_port_status_slave */
    -1,   /* 280: of_async_config_prop_requestforward_master */
    -1,   /* 281: of_async_config_prop_requestforward_slave */
    -1,   /* 282: of_async_config_prop_role_status_master */
    -1,   /* 283: of_async_config_prop_role_status_slave */
    -1,   /* 284: of_async_config_prop_table_status_master */
    -1,   /* 285: of_async_config_prop_table_status_slave */
    -1,   /* 286: of_bsn_controller_connection */
    -1,   /* 287: of_bsn_debug_counter_desc_stats_entry */
    -1,   /* 288: of_bsn_debug_counter_stats_entry */
    -1,   /* 289: of_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 290: of_bsn_generic_stats_entry */
    -1,   /* 291: of_bsn_gentable_bucket_stats_entry */
    -1,   /* 292: of_bsn_gentable_desc_stats_entry */
    -1,   /* 293: of_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 294: of_bsn_gentable_entry_stats_entry */
    -1,   /* 295: of_bsn_gentable_stats_entry */
    32,   /* 296: of_bsn_interface */
    -1,   /* 297: of_bsn_lacp_stats_entry */
    -1,   /* 298: of_bsn_port_counter_stats_entry */
    -1,   /* 299: of_bsn_switch_pipeline_stats_entry */
    -1,   /* 300: of_bsn_table_checksum_stats_entry */
    -1,   /* 301: of_bsn_tlv */
    -1,   /* 302: of_bsn_tlv_actor_key */
    -1,   /* 303: of_bsn_tlv_actor_port_num */
    -1,   /* 304: of_bsn_tlv_actor_port_priority */
    -1,   /* 305: of_bsn_tlv_actor_state */
    -1,   /* 306: of_bsn_tlv_actor_system_mac */
    -1,   /* 307: of_bsn_tlv_actor_system_priority */
    -1,   /* 308: of_bsn_tlv_anchor */
    -1,   /* 309: of_bsn_tlv_apply_bytes */
    -1,   /* 310: of_bsn_tlv_apply_packets */
    -1,   /* 311: of_bsn_tlv_broadcast_query_timeout */
    -1,   /* 312: of_bsn_tlv_broadcast_rate */
    -1,   /* 313: of_bsn_tlv_bucket */
    -1,   /* 314: of_bsn_tlv_circuit_id */
    -1,   /* 315: of_bsn_tlv_convergence_status */
    -1,   /* 316: of_bsn_tlv_cpu_lag */
    -1,   /* 317: of_bsn_tlv_crc_enabled */
    -1,   /* 318: of_bsn_tlv_data */
    -1,   /* 319: of_bsn_tlv_data_mask */
    -1,   /* 320: of_bsn_tlv_decap */
    -1,   /* 321: of_bsn_tlv_disable_src_mac_check */
    -1,   /* 322: of_bsn_tlv_drop */
    -1,   /* 323: of_bsn_tlv_dscp */
    -1,   /* 324: of_bsn_tlv_ecn */
    -1,   /* 325: of_bsn_tlv_egress_only */
    -1,   /* 326: of_bsn_tlv_egress_port_group_id */
    -1,   /* 327: of_bsn_tlv_eth_dst */
    -1,   /* 328: of_bsn_tlv_eth_src */
    -1,   /* 329: of_bsn_tlv_eth_type */
    -1,   /* 330: of_bsn_tlv_external_gateway_ip */
    -1,   /* 331: of_bsn_tlv_external_gateway_mac */
    -1,   /* 332: of_bsn_tlv_external_ip */
    -1,   /* 333: of_bsn_tlv_external_mac */
    -1,   /* 334: of_bsn_tlv_external_netmask */
    -1,   /* 335: of_bsn_tlv_generation_id */
    -1,   /* 336: of_bsn_tlv_hash_gtp_header_match */
    -1,   /* 337: of_bsn_tlv_hash_gtp_port_match */
    -1,   /* 338: of_bsn_tlv_hash_packet_field */
    -1,   /* 339: of_bsn_tlv_hash_packet_type */
    -1,   /* 340: of_bsn_tlv_hash_seed */
    -1,   /* 341: of_bsn_tlv_hash_type */
    -1,   /* 342: of_bsn_tlv_header_size */
    -1,   /* 343: of_bsn_tlv_icmp_code */
    -1,   /* 344: of_bsn_tlv_icmp_id */
    -1,   /* 345: of_bsn_tlv_icmp_type */
    -1,   /* 346: of_bsn_tlv_icmpv6_chksum */
    -1,   /* 347: of_bsn_tlv_idle_notification */
    -1,   /* 348: of_bsn_tlv_idle_time */
    -1,   /* 349: of_bsn_tlv_idle_timeout */
    -1,   /* 350: of_bsn_tlv_igmp_snooping */
    -1,   /* 351: of_bsn_tlv_ingress_port_group_id */
    -1,   /* 352: of_bsn_tlv_internal_gateway_mac */
    -1,   /* 353: of_bsn_tlv_internal_mac */
    -1,   /* 354: of_bsn_tlv_interval */
    -1,   /* 355: of_bsn_tlv_ip_proto */
    -1,   /* 356: of_bsn_tlv_ipv4 */
    -1,   /* 357: of_bsn_tlv_ipv4_dst */
    -1,   /* 358: of_bsn_tlv_ipv4_netmask */
    -1,   /* 359: of_bsn_tlv_ipv4_src */
    -1,   /* 360: of_bsn_tlv_ipv6 */
    -1,   /* 361: of_bsn_tlv_ipv6_dst */
    -1,   /* 362: of_bsn_tlv_ipv6_prefix */
    -1,   /* 363: of_bsn_tlv_ipv6_src */
    -1,   /* 364: of_bsn_tlv_known_multicast_rate */
    -1,   /* 365: of_bsn_tlv_l2_multicast_lookup */
    -1,   /* 366: of_bsn_tlv_l3_dst_class_id */
    -1,   /* 367: of_bsn_tlv_l3_interface_class_id */
    -1,   /* 368: of_bsn_tlv_l3_src_class_id */
    -1,   /* 369: of_bsn_tlv_loopback_port */
    -1,   /* 370: of_bsn_tlv_mac */
    -1,   /* 371: of_bsn_tlv_mac_mask */
    -1,   /* 372: of_bsn_tlv_mcg_type_vxlan */
    -1,   /* 373: of_bsn_tlv_miss_packets */
    -1,   /* 374: of_bsn_tlv_mpls_control_word */
    -1,   /* 375: of_bsn_tlv_mpls_label */
    -1,   /* 376: of_bsn_tlv_mpls_sequenced */
    -1,   /* 377: of_bsn_tlv_multicast_interface_id */
    -1,   /* 378: of_bsn_tlv_name */
    -1,   /* 379: of_bsn_tlv_ndp_offload */
    -1,   /* 380: of_bsn_tlv_ndp_static */
    -1,   /* 381: of_bsn_tlv_negate */
    -1,   /* 382: of_bsn_tlv_next_hop_ipv4 */
    -1,   /* 383: of_bsn_tlv_next_hop_mac */
    -1,   /* 384: of_bsn_tlv_nexthop_type_vxlan */
    -1,   /* 385: of_bsn_tlv_offset */
    -1,   /* 386: of_bsn_tlv_parent_port */
    -1,   /* 387: of_bsn_tlv_partner_key */
    -1,   /* 388: of_bsn_tlv_partner_port_num */
    -1,   /* 389: of_bsn_tlv_partner_port_priority */
    -1,   /* 390: of_bsn_tlv_partner_state */
    -1,   /* 391: of_bsn_tlv_partner_system_mac */
    -1,   /* 392: of_bsn_tlv_partner_system_priority */
    -1,   /* 393: of_bsn_tlv_port */
    -1,   /* 394: of_bsn_tlv_port_usage */
    -1,   /* 395: of_bsn_tlv_port_vxlan_mode */
    -1,   /* 396: of_bsn_tlv_priority */
    -1,   /* 397: of_bsn_tlv_push_vlan_on_ingress */
    -1,   /* 398: of_bsn_tlv_qos_priority */
    -1,   /* 399: of_bsn_tlv_queue_id */
    -1,   /* 400: of_bsn_tlv_queue_weight */
    -1,   /* 401: of_bsn_tlv_rate_limit */
    -1,   /* 402: of_bsn_tlv_rate_unit */
    -1,   /* 403: of_bsn_tlv_reference */
    -1,   /* 404: of_bsn_tlv_reply_packets */
    -1,   /* 405: of_bsn_tlv_request_packets */
    -1,   /* 406: of_bsn_tlv_rx_bytes */
    -1,   /* 407: of_bsn_tlv_rx_packets */
    -1,   /* 408: of_bsn_tlv_sampling_rate */
    -1,   /* 409: of_bsn_tlv_set_loopback_mode */
    -1,   /* 410: of_bsn_tlv_status */
    -1,   /* 411: of_bsn_tlv_strip_mpls_l2_on_ingress */
    -1,   /* 412: of_bsn_tlv_strip_mpls_l3_on_ingress */
    -1,   /* 413: of_bsn_tlv_strip_vlan_on_egress */
    -1,   /* 414: of_bsn_tlv_sub_agent_id */
    -1,   /* 415: of_bsn_tlv_tcp_dst */
    -1,   /* 416: of_bsn_tlv_tcp_flags */
    -1,   /* 417: of_bsn_tlv_tcp_src */
    -1,   /* 418: of_bsn_tlv_ttl */
    -1,   /* 419: of_bsn_tlv_tx_bytes */
    -1,   /* 420: of_bsn_tlv_tx_packets */
    -1,   /* 421: of_bsn_tlv_udf_anchor */
    -1,   /* 422: of_bsn_tlv_udf_id */
    -1,   /* 423: of_bsn_tlv_udf_length */
    -1,   /* 424: of_bsn_tlv_udf_offset */
    -1,   /* 425: of_bsn_tlv_udp_dst */
    -1,   /* 426: of_bsn_tlv_udp_src */
    -1,   /* 427: of_bsn_tlv_uint64_list */
    -1,   /* 428: of_bsn_tlv_unicast_query_timeout */
    -1,   /* 429: of_bsn_tlv_unicast_rate */
    -1,   /* 430: of_bsn_tlv_unknown_multicast_rate */
    -1,   /* 431: of_bsn_tlv_untagged */
    -1,   /* 432: of_bsn_tlv_use_packet_state */
    -1,   /* 433: of_bsn_tlv_vfi */
    -1,   /* 434: of_bsn_tlv_vfp_class_id */
    -1,   /* 435: of_bsn_tlv_vlan_mac_list */
    -1,   /* 436: of_bsn_tlv_vlan_pcp */
    -1,   /* 437: of_bsn_tlv_vlan_vid */
    -1,   /* 438: of_bsn_tlv_vlan_vid_mask */
    -1,   /* 439: of_bsn_tlv_vni */
    -1,   /* 440: of_bsn_tlv_vpn_key */
    -1,   /* 441: of_bsn_tlv_vrf */
    -1,   /* 442: of_bsn_tlv_vxlan_egress_lag */
    -1,   /* 443: of_bsn_vlan_counter_stats_entry */
    -1,   /* 444: of_bsn_vlan_mac */
    4,    /* 445: of_bsn_vport */
    60,   /* 446: of_bsn_vport_l2gre */
    32,   /* 447: of_bsn_vport_q_in_q */
    -1,   /* 448: of_bsn_vrf_counter_stats_entry */
    -1,   /* 449: of_bucket */
    -1,   /* 450: of_bucket_counter */
    -1,   /* 451: of_bundle_prop */
    -1,   /* 452: of_bundle_prop_experimenter */
    88,   /* 453: of_flow_stats_entry */
    -1,   /* 454: of_group_desc_stats_entry */
    -1,   /* 455: of_group_stats_entry */
    -1,   /* 456: of_hello_elem */
    -1,   /* 457: of_hello_elem_versionbitmap */
    -1,   /* 458: of_instruction */
    -1,   /* 459: of_instruction_apply_actions */
    -1,   /* 460: of_instruction_bsn */
    -1,   /* 461: of_instruction_bsn_arp_offload */
    -1,   /* 462: of_instruction_bsn_auto_negotiation */
    -1,   /* 463: of_instruction_bsn_deny */
    -1,   /* 464: of_instruction_bsn_dhcp_offload */
    -1,   /* 465: of_instruction_bsn_disable_l3 */
    -1,   /* 466: of_instruction_bsn_disable_split_horizon_check */
    -1,   /* 467: of_instruction_bsn_disable_src_mac_check */
    -1,   /* 468: of_instruction_bsn_disable_vlan_counters */
    -1,   /* 469: of_instruction_bsn_hash_select */
    -1,   /* 470: of_instruction_bsn_internal_priority */
    -1,   /* 471: of_instruction_bsn_ndp_offload */
    -1,   /* 472: of_instruction_bsn_packet_of_death */
    -1,   /* 473: of_instruction_bsn_permit */
    -1,   /* 474: of_instruction_bsn_prioritize_pdus */
    -1,   /* 475: of_instruction_bsn_require_vlan_xlate */
    -1,   /* 476: of_instruction_bsn_span_destination */
    -1,   /* 477: of_instruction_clear_actions */
    -1,   /* 478: of_instruction_experimenter */
    -1,   /* 479: of_instruction_goto_table */
    -1,   /* 480: of_instruction_id */
    -1,   /* 481: of_instruction_id_apply_actions */
    -1,   /* 482: of_instruction_id_bsn */
    -1,   /* 483: of_instruction_id_bsn_arp_offload */
    -1,   /* 484: of_instruction_id_bsn_auto_negotiation */
    -1,   /* 485: of_instruction_id_bsn_deny */
    -1,   /* 486: of_instruction_id_bsn_dhcp_offload */
    -1,   /* 487: of_instruction_id_bsn_disable_l3 */
    -1,   /* 488: of_instruction_id_bsn_disable_split_horizon_check */
    -1,   /* 489: of_instruction_id_bsn_disable_src_mac_check */
    -1,   /* 490: of_instruction_id_bsn_disable_vlan_counters */
    -1,   /* 491: of_instruction_id_bsn_hash_select */
    -1,   /* 492: of_instruction_id_bsn_internal_priority */
    -1,   /* 493: of_instruction_id_bsn_ndp_offload */
    -1,   /* 494: of_instruction_id_bsn_packet_of_death */
    -1,   /* 495: of_instruction_id_bsn_permit */
    -1,   /* 496: of_instruction_id_bsn_prioritize_pdus */
    -1,   /* 497: of_instruction_id_bsn_require_vlan_xlate */
    -1,   /* 498: of_instruction_id_bsn_span_destination */
    -1,   /* 499: of_instruction_id_clear_actions */
    -1,   /* 500: of_instruction_id_experimenter */
    -1,   /* 501: of_instruction_id_goto_table */
    -1,   /* 502: of_instruction_id_meter */
    -1,   /* 503: of_instruction_id_write_actions */
    -1,   /* 504: of_instruction_id_write_metadata */
    -1,   /* 505: of_instruction_meter */
    -1,   /* 506: of_instruction_write_actions */
    -1,   /* 507: of_instruction_write_metadata */
    40,   /* 508: of_match_v1 */
    -1,   /* 509: of_match_v2 */
    -1,   /* 510: of_match_v3 */
    -1,   /* 511: of_meter_band */
    -1,   /* 512: of_meter_band_drop */
    -1,   /* 513: of_meter_band_dscp_remark */
    -1,   /* 514: of_meter_band_experimenter */
    -1,   /* 515: of_meter_band_stats */
    -1,   /* 516: of_meter_config */
    -1,   /* 517: of_meter_features */
    -1,   /* 518: of_meter_stats */
    -1,   /* 519: of_oxm */
    -1,   /* 520: of_oxm_arp_op */
    -1,   /* 521: of_oxm_arp_op_masked */
    -1,   /* 522: of_oxm_arp_sha */
    -1,   /* 523: of_oxm_arp_sha_masked */
    -1,   /* 524: of_oxm_arp_spa */
    -1,   /* 525: of_oxm_arp_spa_masked */
    -1,   /* 526: of_oxm_arp_tha */
    -1,   /* 527: of_oxm_arp_tha_masked */
    -1,   /* 528: of_oxm_arp_tpa */
    -1,   /* 529: of_oxm_arp_tpa_masked */
    -1,   /* 530: of_oxm_bsn_egr_port_group_id */
    -1,   /* 531: of_oxm_bsn_egr_port_group_id_masked */
    -1,   /* 532: of_oxm_bsn_global_vrf_allowed */
    -1,   /* 533: of_oxm_bsn_global_vrf_allowed_masked */
    -1,   /* 534: of_oxm_bsn_in_ports_128 */
    -1,   /* 535: of_oxm_bsn_in_ports_128_masked */
    -1,   /* 536: of_oxm_bsn_in_ports_512 */
    -1,   /* 537: of_oxm_bsn_in_ports_512_masked */
    -1,   /* 538: of_oxm_bsn_ingress_port_group_id */
    -1,   /* 539: of_oxm_bsn_ingress_port_group_id_masked */
    -1,   /* 540: of_oxm_bsn_inner_eth_dst */
    -1,   /* 541: of_oxm_bsn_inner_eth_dst_masked */
    -1,   /* 542: of_oxm_bsn_inner_eth_src */
    -1,   /* 543: of_oxm_bsn_inner_eth_src_masked */
    -1,   /* 544: of_oxm_bsn_inner_vlan_vid */
    -1,   /* 545: of_oxm_bsn_inner_vlan_vid_masked */
    -1,   /* 546: of_oxm_bsn_ip_fragmentation */
    -1,   /* 547: of_oxm_bsn_ip_fragmentation_masked */
    -1,   /* 548: of_oxm_bsn_l2_cache_hit */
    -1,   /* 549: of_oxm_bsn_l2_cache_hit_masked */
    -1,   /* 550: of_oxm_bsn_l3_dst_class_id */
    -1,   /* 551: of_oxm_bsn_l3_dst_class_id_masked */
    -1,   /* 552: of_oxm_bsn_l3_interface_class_id */
    -1,   /* 553: of_oxm_bsn_l3_interface_class_id_masked */
    -1,   /* 554: of_oxm_bsn_l3_src_class_id */
    -1,   /* 555: of_oxm_bsn_l3_src_class_id_masked */
    -1,   /* 556: of_oxm_bsn_lag_id */
    -1,   /* 557: of_oxm_bsn_lag_id_masked */
    -1,   /* 558: of_oxm_bsn_tcp_flags */
    -1,   /* 559: of_oxm_bsn_tcp_flags_masked */
    -1,   /* 560: of_oxm_bsn_udf0 */
    -1,   /* 561: of_oxm_bsn_udf0_masked */
    -1,   /* 562: of_oxm_bsn_udf1 */
    -1,   /* 563: of_oxm_bsn_udf1_masked */
    -1,   /* 564: of_oxm_bsn_udf2 */
    -1,   /* 565: of_oxm_bsn_udf2_masked */
    -1,   /* 566: of_oxm_bsn_udf3 */
    -1,   /* 567: of_oxm_bsn_udf3_masked */
    -1,   /* 568: of_oxm_bsn_udf4 */
    -1,   /* 569: of_oxm_bsn_udf4_masked */
    -1,   /* 570: of_oxm_bsn_udf5 */
    -1,   /* 571: of_oxm_bsn_udf5_masked */
    -1,   /* 572: of_oxm_bsn_udf6 */
    -1,   /* 573: of_oxm_bsn_udf6_masked */
    -1,   /* 574: of_oxm_bsn_udf7 */
    -1,   /* 575: of_oxm_bsn_udf7_masked */
    -1,   /* 576: of_oxm_bsn_vfi */
    -1,   /* 577: of_oxm_bsn_vfi_masked */
    -1,   /* 578: of_oxm_bsn_vlan_xlate_port_group_id */
    -1,   /* 579: of_oxm_bsn_vlan_xlate_port_group_id_masked */
    -1,   /* 580: of_oxm_bsn_vrf */
    -1,   /* 581: of_oxm_bsn_vrf_masked */
    -1,   /* 582: of_oxm_bsn_vxlan_network_id */
    -1,   /* 583: of_oxm_bsn_vxlan_network_id_masked */
    -1,   /* 584: of_oxm_eth_dst */
    -1,   /* 585: of_oxm_eth_dst_masked */
    -1,   /* 586: of_oxm_eth_src */
    -1,   /* 587: of_oxm_eth_src_masked */
    -1,   /* 588: of_oxm_eth_type */
    -1,   /* 589: of_oxm_eth_type_masked */
    -1,   /* 590: of_oxm_icmpv4_code */
    -1,   /* 591: of_oxm_icmpv4_code_masked */
    -1,   /* 592: of_oxm_icmpv4_type */
    -1,   /* 593: of_oxm_icmpv4_type_masked */
    -1,   /* 594: of_oxm_icmpv6_code */
    -1,   /* 595: of_oxm_icmpv6_code_masked */
    -1,   /* 596: of_oxm_icmpv6_type */
    -1,   /* 597: of_oxm_icmpv6_type_masked */
    -1,   /* 598: of_oxm_in_phy_port */
    -1,   /* 599: of_oxm_in_phy_port_masked */
    -1,   /* 600: of_oxm_in_port */
    -1,   /* 601: of_oxm_in_port_masked */
    -1,   /* 602: of_oxm_ip_dscp */
    -1,   /* 603: of_oxm_ip_dscp_masked */
    -1,   /* 604: of_oxm_ip_ecn */
    -1,   /* 605: of_oxm_ip_ecn_masked */
    -1,   /* 606: of_oxm_ip_proto */
    -1,   /* 607: of_oxm_ip_proto_masked */
    -1,   /* 608: of_oxm_ipv4_dst */
    -1,   /* 609: of_oxm_ipv4_dst_masked */
    -1,   /* 610: of_oxm_ipv4_src */
    -1,   /* 611: of_oxm_ipv4_src_masked */
    -1,   /* 612: of_oxm_ipv6_dst */
    -1,   /* 613: of_oxm_ipv6_dst_masked */
    -1,   /* 614: of_oxm_ipv6_exthdr */
    -1,   /* 615: of_oxm_ipv6_exthdr_masked */
    -1,   /* 616: of_oxm_ipv6_flabel */
    -1,   /* 617: of_oxm_ipv6_flabel_masked */
    -1,   /* 618: of_oxm_ipv6_nd_sll */
    -1,   /* 619: of_oxm_ipv6_nd_sll_masked */
    -1,   /* 620: of_oxm_ipv6_nd_target */
    -1,   /* 621: of_oxm_ipv6_nd_target_masked */
    -1,   /* 622: of_oxm_ipv6_nd_tll */
    -1,   /* 623: of_oxm_ipv6_nd_tll_masked */
    -1,   /* 624: of_oxm_ipv6_src */
    -1,   /* 625: of_oxm_ipv6_src_masked */
    -1,   /* 626: of_oxm_metadata */
    -1,   /* 627: of_oxm_metadata_masked */
    -1,   /* 628: of_oxm_mpls_bos */
    -1,   /* 629: of_oxm_mpls_bos_masked */
    -1,   /* 630: of_oxm_mpls_label */
    -1,   /* 631: of_oxm_mpls_label_masked */
    -1,   /* 632: of_oxm_mpls_tc */
    -1,   /* 633: of_oxm_mpls_tc_masked */
    -1,   /* 634: of_oxm_ovs_tcp_flags */
    -1,   /* 635: of_oxm_ovs_tcp_flags_masked */
    -1,   /* 636: of_oxm_pbb_uca */
    -1,   /* 637: of_oxm_pbb_uca_masked */
    -1,   /* 638: of_oxm_sctp_dst */
    -1,   /* 639: of_oxm_sctp_dst_masked */
    -1,   /* 640: of_oxm_sctp_src */
    -1,   /* 641: of_oxm_sctp_src_masked */
    -1,   /* 642: of_oxm_tcp_dst */
    -1,   /* 643: of_oxm_tcp_dst_masked */
    -1,   /* 644: of_oxm_tcp_src */
    -1,   /* 645: of_oxm_tcp_src_masked */
    -1,   /* 646: of_oxm_tunnel_id */
    -1,   /* 647: of_oxm_tunnel_id_masked */
    -1,   /* 648: of_oxm_tunnel_ipv4_dst */
    -1,   /* 649: of_oxm_tunnel_ipv4_dst_masked */
    -1,   /* 650: of_oxm_tunnel_ipv4_src */
    -1,   /* 651: of_oxm_tunnel_ipv4_src_masked */
    -1,   /* 652: of_oxm_udp_dst */
    -1,   /* 653: of_oxm_udp_dst_masked */
    -1,   /* 654: of_oxm_udp_src */
    -1,   /* 655: of_oxm_udp_src_masked */
    -1,   /* 656: of_oxm_vlan_pcp */
    -1,   /* 657: of_oxm_vlan_pcp_masked */
    -1,   /* 658: of_oxm_vlan_vid */
    -1,   /* 659: of_oxm_vlan_vid_masked */
    8,    /* 660: of_packet_queue */
    48,   /* 661: of_port_desc */
    -1,   /* 662: of_port_desc_prop */
    -1,   /* 663: of_port_desc_prop_bsn */
    -1,   /* 664: of_port_desc_prop_bsn_generation_id */
    -1,   /* 665: of_port_desc_prop_bsn_uplink */
    -1,   /* 666: of_port_desc_prop_ethernet */
    -1,   /* 667: of_port_desc_prop_experimenter */
    -1,   /* 668: of_port_desc_prop_optical */
    -1,   /* 669: of_port_mod_prop */
    -1,   /* 670: of_port_mod_prop_ethernet */
    -1,   /* 671: of_port_mod_prop_experimenter */
    -1,   /* 672: of_port_mod_prop_optical */
    104,  /* 673: of_port_stats_entry */
    -1,   /* 674: of_port_stats_prop */
    -1,   /* 675: of_port_stats_prop_ethernet */
    -1,   /* 676: of_port_stats_prop_experimenter */
    -1,   /* 677: of_port_stats_prop_optical */
    -1,   /* 678: of_queue_desc */
    -1,   /* 679: of_queue_desc_prop */
    -1,   /* 680: of_queue_desc_prop_bsn */
    -1,   /* 681: of_queue_desc_prop_bsn_queue_name */
    -1,   /* 682: of_queue_desc_prop_experimenter */
    -1,   /* 683: of_queue_desc_prop_max_rate */
    -1,   /* 684: of_queue_desc_prop_min_rate */
    8,    /* 685: of_queue_prop */
    -1,   /* 686: of_queue_prop_experimenter */
    -1,   /* 687: of_queue_prop_max_rate */
    16,   /* 688: of_queue_prop_min_rate */
    32,   /* 689: of_queue_stats_entry */
    -1,   /* 690: of_queue_stats_prop */
    -1,   /* 691: of_queue_stats_prop_experimenter */
    -1,   /* 692: of_role_prop */
    -1,   /* 693: of_role_prop_experimenter */
    -1,   /* 694: of_table_desc */
    -1,   /* 695: of_table_feature_prop */
    -1,   /* 696: of_table_feature_prop_apply_actions */
    -1,   /* 697: of_table_feature_prop_apply_actions_miss */
    -1,   /* 698: of_table_feature_prop_apply_setfield */
    -1,   /* 699: of_table_feature_prop_apply_setfield_miss */
    -1,   /* 700: of_table_feature_prop_experimenter */
    -1,   /* 701: of_table_feature_prop_experimenter_miss */
    -1,   /* 702: of_table_feature_prop_instructions */
    -1,   /* 703: of_table_feature_prop_instructions_miss */
    -1,   /* 704: of_table_feature_prop_match */
    -1,   /* 705: of_table_feature_prop_next_tables */
    -1,   /* 706: of_table_feature_prop_next_tables_miss */
    -1,   /* 707: of_table_feature_prop_table_sync_from */
    -1,   /* 708: of_table_feature_prop_wildcards */
    -1,   /* 709: of_table_feature_prop_write_actions */
    -1,   /* 710: of_table_feature_prop_write_actions_miss */
    -1,   /* 711: of_table_feature_prop_write_setfield */
    -1,   /* 712: of_table_feature_prop_write_setfield_miss */
    -1,   /* 713: of_table_features */
    -1,   /* 714: of_table_mod_prop */
    -1,   /* 715: of_table_mod_prop_eviction */
    -1,   /* 716: of_table_mod_prop_experimenter */
    -1,   /* 717: of_table_mod_prop_vacancy */
    64,   /* 718: of_table_stats_entry */
    -1,   /* 719: of_uint32 */
    -1,   /* 720: of_uint64 */
    -1,   /* 721: of_uint8 */
    0,    /* 722: of_list_action */
    -1,   /* 723: of_list_action_id */
    -1,   /* 724: of_list_async_config_prop */
    -1,   /* 725: of_list_bsn_controller_connection */
    -1,   /* 726: of_list_bsn_debug_counter_desc_stats_entry */
    -1,   /* 727: of_list_bsn_debug_counter_stats_entry */
    -1,   /* 728: of_list_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 729: of_list_bsn_generic_stats_entry */
    -1,   /* 730: of_list_bsn_gentable_bucket_stats_entry */
    -1,   /* 731: of_list_bsn_gentable_desc_stats_entry */
    -1,   /* 732: of_list_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 733: of_list_bsn_gentable_entry_stats_entry */
    -1,   /* 734: of_list_bsn_gentable_stats_entry */
    0,    /* 735: of_list_bsn_interface */
    -1,   /* 736: of_list_bsn_lacp_stats_entry */
    -1,   /* 737: of_list_bsn_port_counter_stats_entry */
    -1,   /* 738: of_list_bsn_switch_pipeline_stats_entry */
    -1,   /* 739: of_list_bsn_table_checksum_stats_entry */
    -1,   /* 740: of_list_bsn_tlv */
    -1,   /* 741: of_list_bsn_vlan_counter_stats_entry */
    -1,   /* 742: of_list_bsn_vlan_mac */
    -1,   /* 743: of_list_bsn_vrf_counter_stats_entry */
    -1,   /* 744: of_list_bucket */
    -1,   /* 745: of_list_bucket_counter */
    -1,   /* 746: of_list_bundle_prop */
    0,    /* 747: of_list_flow_stats_entry */
    -1,   /* 748: of_list_group_desc_stats_entry */
    -1,   /* 749: of_list_group_stats_entry */
    -1,   /* 750: of_list_hello_elem */
    -1,   /* 751: of_list_instruction */
    -1,   /* 752: of_list_instruction_id */
    -1,   /* 753: of_list_meter_band */
    -1,   /* 754: of_list_meter_band_stats */
    -1,   /* 755: of_list_meter_config */
    -1,   /* 756: of_list_meter_stats */
    -1,   /* 757: of_list_oxm */
    0,    /* 758: of_list_packet_queue */
    0,    /* 759: of_list_port_desc */
    -1,   /* 760: of_list_port_desc_prop */
    -1,   /* 761: of_list_port_mod_prop */
    0,    /* 762: of_list_port_stats_entry */
    -1,   /* 763: of_list_port_stats_prop */
    -1,   /* 764: of_list_queue_desc */
    -1,   /* 765: of_list_queue_desc_prop */
    0,    /* 766: of_list_queue_prop */
    0,    /* 767: of_list_queue_stats_entry */
    -1,   /* 768: of_list_queue_stats_prop */
    -1,   /* 769: of_list_role_prop */
    -1,   /* 770: of_list_table_desc */
    -1,   /* 771: of_list_table_feature_prop */
    -1,   /* 772: of_list_table_features */
    -1,   /* 773: of_list_table_mod_prop */
    0,    /* 774: of_list_table_stats_entry */
    -1,   /* 775: of_list_uint32 */
    -1,   /* 776: of_list_uint64 */
    -1    /* 777: of_list_uint8 */
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
    -1,   /* 15: of_bsn_base_error */
    20,   /* 16: of_bsn_bw_clear_data_reply */
    16,   /* 17: of_bsn_bw_clear_data_request */
    20,   /* 18: of_bsn_bw_enable_get_reply */
    16,   /* 19: of_bsn_bw_enable_get_request */
    24,   /* 20: of_bsn_bw_enable_set_reply */
    20,   /* 21: of_bsn_bw_enable_set_request */
    -1,   /* 22: of_bsn_controller_connections_reply */
    -1,   /* 23: of_bsn_controller_connections_request */
    -1,   /* 24: of_bsn_debug_counter_desc_stats_reply */
    -1,   /* 25: of_bsn_debug_counter_desc_stats_request */
    -1,   /* 26: of_bsn_debug_counter_stats_reply */
    -1,   /* 27: of_bsn_debug_counter_stats_request */
    -1,   /* 28: of_bsn_error */
    -1,   /* 29: of_bsn_flow_checksum_bucket_stats_reply */
    -1,   /* 30: of_bsn_flow_checksum_bucket_stats_request */
    -1,   /* 31: of_bsn_flow_idle */
    -1,   /* 32: of_bsn_flow_idle_enable_get_reply */
    -1,   /* 33: of_bsn_flow_idle_enable_get_request */
    -1,   /* 34: of_bsn_flow_idle_enable_set_reply */
    -1,   /* 35: of_bsn_flow_idle_enable_set_request */
    -1,   /* 36: of_bsn_generic_async */
    -1,   /* 37: of_bsn_generic_command */
    -1,   /* 38: of_bsn_generic_stats_reply */
    -1,   /* 39: of_bsn_generic_stats_request */
    -1,   /* 40: of_bsn_gentable_bucket_stats_reply */
    -1,   /* 41: of_bsn_gentable_bucket_stats_request */
    -1,   /* 42: of_bsn_gentable_clear_reply */
    -1,   /* 43: of_bsn_gentable_clear_request */
    -1,   /* 44: of_bsn_gentable_desc_stats_reply */
    -1,   /* 45: of_bsn_gentable_desc_stats_request */
    -1,   /* 46: of_bsn_gentable_entry_add */
    -1,   /* 47: of_bsn_gentable_entry_delete */
    -1,   /* 48: of_bsn_gentable_entry_desc_stats_reply */
    -1,   /* 49: of_bsn_gentable_entry_desc_stats_request */
    -1,   /* 50: of_bsn_gentable_entry_stats_reply */
    -1,   /* 51: of_bsn_gentable_entry_stats_request */
    -1,   /* 52: of_bsn_gentable_set_buckets_size */
    -1,   /* 53: of_bsn_gentable_stats_reply */
    -1,   /* 54: of_bsn_gentable_stats_request */
    16,   /* 55: of_bsn_get_interfaces_reply */
    16,   /* 56: of_bsn_get_interfaces_request */
    -1,   /* 57: of_bsn_get_ip_mask_reply */
    -1,   /* 58: of_bsn_get_ip_mask_request */
    -1,   /* 59: of_bsn_get_l2_table_reply */
    -1,   /* 60: of_bsn_get_l2_table_request */
    20,   /* 61: of_bsn_get_mirroring_reply */
    20,   /* 62: of_bsn_get_mirroring_request */
    -1,   /* 63: of_bsn_get_switch_pipeline_reply */
    -1,   /* 64: of_bsn_get_switch_pipeline_request */
    16,   /* 65: of_bsn_header */
    -1,   /* 66: of_bsn_hybrid_get_reply */
    -1,   /* 67: of_bsn_hybrid_get_request */
    -1,   /* 68: of_bsn_image_desc_stats_reply */
    -1,   /* 69: of_bsn_image_desc_stats_request */
    -1,   /* 70: of_bsn_lacp_convergence_notif */
    -1,   /* 71: of_bsn_lacp_stats_reply */
    -1,   /* 72: of_bsn_lacp_stats_request */
    -1,   /* 73: of_bsn_log */
    -1,   /* 74: of_bsn_lua_command_reply */
    -1,   /* 75: of_bsn_lua_command_request */
    -1,   /* 76: of_bsn_lua_notification */
    -1,   /* 77: of_bsn_lua_upload */
    25,   /* 78: of_bsn_pdu_rx_reply */
    28,   /* 79: of_bsn_pdu_rx_request */
    21,   /* 80: of_bsn_pdu_rx_timeout */
    25,   /* 81: of_bsn_pdu_tx_reply */
    28,   /* 82: of_bsn_pdu_tx_request */
    -1,   /* 83: of_bsn_port_counter_stats_reply */
    -1,   /* 84: of_bsn_port_counter_stats_request */
    -1,   /* 85: of_bsn_role_status */
    -1,   /* 86: of_bsn_set_aux_cxns_reply */
    -1,   /* 87: of_bsn_set_aux_cxns_request */
    -1,   /* 88: of_bsn_set_ip_mask */
    -1,   /* 89: of_bsn_set_l2_table_reply */
    -1,   /* 90: of_bsn_set_l2_table_request */
    -1,   /* 91: of_bsn_set_lacp_reply */
    -1,   /* 92: of_bsn_set_lacp_request */
    20,   /* 93: of_bsn_set_mirroring */
    20,   /* 94: of_bsn_set_pktin_suppression_reply */
    32,   /* 95: of_bsn_set_pktin_suppression_request */
    -1,   /* 96: of_bsn_set_switch_pipeline_reply */
    -1,   /* 97: of_bsn_set_switch_pipeline_request */
    -1,   /* 98: of_bsn_shell_command */
    -1,   /* 99: of_bsn_shell_output */
    -1,   /* 100: of_bsn_shell_status */
    24,   /* 101: of_bsn_stats_reply */
    24,   /* 102: of_bsn_stats_request */
    -1,   /* 103: of_bsn_switch_pipeline_stats_reply */
    -1,   /* 104: of_bsn_switch_pipeline_stats_request */
    -1,   /* 105: of_bsn_table_checksum_stats_reply */
    -1,   /* 106: of_bsn_table_checksum_stats_request */
    -1,   /* 107: of_bsn_table_set_buckets_size */
    -1,   /* 108: of_bsn_takeover */
    -1,   /* 109: of_bsn_time_reply */
    -1,   /* 110: of_bsn_time_request */
    24,   /* 111: of_bsn_virtual_port_create_reply */
    20,   /* 112: of_bsn_virtual_port_create_request */
    20,   /* 113: of_bsn_virtual_port_remove_reply */
    20,   /* 114: of_bsn_virtual_port_remove_request */
    -1,   /* 115: of_bsn_vlan_counter_clear */
    -1,   /* 116: of_bsn_vlan_counter_stats_reply */
    -1,   /* 117: of_bsn_vlan_counter_stats_request */
    -1,   /* 118: of_bsn_vrf_counter_stats_reply */
    -1,   /* 119: of_bsn_vrf_counter_stats_request */
    -1,   /* 120: of_bundle_add_msg */
    -1,   /* 121: of_bundle_ctrl_msg */
    -1,   /* 122: of_bundle_failed_error_msg */
    1072, /* 123: of_desc_stats_reply */
    16,   /* 124: of_desc_stats_request */
    8,    /* 125: of_echo_reply */
    8,    /* 126: of_echo_request */
    10,   /* 127: of_error_msg */
    12,   /* 128: of_experimenter */
    -1,   /* 129: of_experimenter_error_msg */
    24,   /* 130: of_experimenter_stats_reply */
    24,   /* 131: of_experimenter_stats_request */
    32,   /* 132: of_features_reply */
    8,    /* 133: of_features_request */
    136,  /* 134: of_flow_add */
    136,  /* 135: of_flow_delete */
    136,  /* 136: of_flow_delete_strict */
    136,  /* 137: of_flow_mod */
    12,   /* 138: of_flow_mod_failed_error_msg */
    136,  /* 139: of_flow_modify */
    136,  /* 140: of_flow_modify_strict */
    -1,   /* 141: of_flow_monitor_failed_error_msg */
    136,  /* 142: of_flow_removed */
    16,   /* 143: of_flow_stats_reply */
    136,  /* 144: of_flow_stats_request */
    12,   /* 145: of_get_config_reply */
    8,    /* 146: of_get_config_request */
    16,   /* 147: of_group_add */
    16,   /* 148: of_group_delete */
    16,   /* 149: of_group_desc_stats_reply */
    16,   /* 150: of_group_desc_stats_request */
    -1,   /* 151: of_group_features_stats_reply */
    -1,   /* 152: of_group_features_stats_request */
    16,   /* 153: of_group_mod */
    12,   /* 154: of_group_mod_failed_error_msg */
    16,   /* 155: of_group_modify */
    16,   /* 156: of_group_stats_reply */
    24,   /* 157: of_group_stats_request */
    8,    /* 158: of_header */
    8,    /* 159: of_hello */
    12,   /* 160: of_hello_failed_error_msg */
    -1,   /* 161: of_meter_config_stats_reply */
    -1,   /* 162: of_meter_config_stats_request */
    -1,   /* 163: of_meter_features_stats_reply */
    -1,   /* 164: of_meter_features_stats_request */
    -1,   /* 165: of_meter_mod */
    -1,   /* 166: of_meter_mod_failed_error_msg */
    -1,   /* 167: of_meter_stats_reply */
    -1,   /* 168: of_meter_stats_request */
    -1,   /* 169: of_nicira_controller_role_reply */
    -1,   /* 170: of_nicira_controller_role_request */
    16,   /* 171: of_nicira_header */
    24,   /* 172: of_packet_in */
    24,   /* 173: of_packet_out */
    -1,   /* 174: of_port_desc_stats_reply */
    -1,   /* 175: of_port_desc_stats_request */
    40,   /* 176: of_port_mod */
    12,   /* 177: of_port_mod_failed_error_msg */
    16,   /* 178: of_port_stats_reply */
    24,   /* 179: of_port_stats_request */
    80,   /* 180: of_port_status */
    -1,   /* 181: of_queue_desc_stats_reply */
    -1,   /* 182: of_queue_desc_stats_request */
    16,   /* 183: of_queue_get_config_reply */
    16,   /* 184: of_queue_get_config_request */
    12,   /* 185: of_queue_op_failed_error_msg */
    16,   /* 186: of_queue_stats_reply */
    24,   /* 187: of_queue_stats_request */
    -1,   /* 188: of_requestforward */
    -1,   /* 189: of_role_reply */
    -1,   /* 190: of_role_request */
    -1,   /* 191: of_role_request_failed_error_msg */
    -1,   /* 192: of_role_status */
    12,   /* 193: of_set_config */
    16,   /* 194: of_stats_reply */
    16,   /* 195: of_stats_request */
    12,   /* 196: of_switch_config_failed_error_msg */
    -1,   /* 197: of_table_desc_stats_reply */
    -1,   /* 198: of_table_desc_stats_request */
    -1,   /* 199: of_table_features_failed_error_msg */
    -1,   /* 200: of_table_features_stats_reply */
    -1,   /* 201: of_table_features_stats_request */
    16,   /* 202: of_table_mod */
    12,   /* 203: of_table_mod_failed_error_msg */
    16,   /* 204: of_table_stats_reply */
    16,   /* 205: of_table_stats_request */
    -1,   /* 206: of_table_status */
    8,    /* 207: of_action */
    16,   /* 208: of_action_bsn */
    28,   /* 209: of_action_bsn_checksum */
    -1,   /* 210: of_action_bsn_gentable */
    24,   /* 211: of_action_bsn_mirror */
    16,   /* 212: of_action_bsn_set_tunnel_dst */
    8,    /* 213: of_action_copy_ttl_in */
    8,    /* 214: of_action_copy_ttl_out */
    8,    /* 215: of_action_dec_mpls_ttl */
    8,    /* 216: of_action_dec_nw_ttl */
    -1,   /* 217: of_action_enqueue */
    8,    /* 218: of_action_experimenter */
    8,    /* 219: of_action_group */
    -1,   /* 220: of_action_id */
    -1,   /* 221: of_action_id_bsn */
    -1,   /* 222: of_action_id_bsn_checksum */
    -1,   /* 223: of_action_id_bsn_gentable */
    -1,   /* 224: of_action_id_bsn_mirror */
    -1,   /* 225: of_action_id_bsn_set_tunnel_dst */
    -1,   /* 226: of_action_id_copy_ttl_in */
    -1,   /* 227: of_action_id_copy_ttl_out */
    -1,   /* 228: of_action_id_dec_mpls_ttl */
    -1,   /* 229: of_action_id_dec_nw_ttl */
    -1,   /* 230: of_action_id_experimenter */
    -1,   /* 231: of_action_id_group */
    -1,   /* 232: of_action_id_nicira */
    -1,   /* 233: of_action_id_nicira_dec_ttl */
    -1,   /* 234: of_action_id_output */
    -1,   /* 235: of_action_id_pop_mpls */
    -1,   /* 236: of_action_id_pop_pbb */
    -1,   /* 237: of_action_id_pop_vlan */
    -1,   /* 238: of_action_id_push_mpls */
    -1,   /* 239: of_action_id_push_pbb */
    -1,   /* 240: of_action_id_push_vlan */
    -1,   /* 241: of_action_id_set_field */
    -1,   /* 242: of_action_id_set_mpls_ttl */
    -1,   /* 243: of_action_id_set_nw_ttl */
    -1,   /* 244: of_action_id_set_queue */
    16,   /* 245: of_action_nicira */
    16,   /* 246: of_action_nicira_dec_ttl */
    16,   /* 247: of_action_output */
    8,    /* 248: of_action_pop_mpls */
    -1,   /* 249: of_action_pop_pbb */
    8,    /* 250: of_action_pop_vlan */
    8,    /* 251: of_action_push_mpls */
    -1,   /* 252: of_action_push_pbb */
    8,    /* 253: of_action_push_vlan */
    16,   /* 254: of_action_set_dl_dst */
    16,   /* 255: of_action_set_dl_src */
    -1,   /* 256: of_action_set_field */
    8,    /* 257: of_action_set_mpls_label */
    8,    /* 258: of_action_set_mpls_tc */
    8,    /* 259: of_action_set_mpls_ttl */
    8,    /* 260: of_action_set_nw_dst */
    8,    /* 261: of_action_set_nw_ecn */
    8,    /* 262: of_action_set_nw_src */
    8,    /* 263: of_action_set_nw_tos */
    8,    /* 264: of_action_set_nw_ttl */
    8,    /* 265: of_action_set_queue */
    8,    /* 266: of_action_set_tp_dst */
    8,    /* 267: of_action_set_tp_src */
    8,    /* 268: of_action_set_vlan_pcp */
    8,    /* 269: of_action_set_vlan_vid */
    -1,   /* 270: of_action_strip_vlan */
    -1,   /* 271: of_async_config_prop */
    -1,   /* 272: of_async_config_prop_experimenter_master */
    -1,   /* 273: of_async_config_prop_experimenter_slave */
    -1,   /* 274: of_async_config_prop_flow_removed_master */
    -1,   /* 275: of_async_config_prop_flow_removed_slave */
    -1,   /* 276: of_async_config_prop_packet_in_master */
    -1,   /* 277: of_async_config_prop_packet_in_slave */
    -1,   /* 278: of_async_config_prop_port_status_master */
    -1,   /* 279: of_async_config_prop_port_status_slave */
    -1,   /* 280: of_async_config_prop_requestforward_master */
    -1,   /* 281: of_async_config_prop_requestforward_slave */
    -1,   /* 282: of_async_config_prop_role_status_master */
    -1,   /* 283: of_async_config_prop_role_status_slave */
    -1,   /* 284: of_async_config_prop_table_status_master */
    -1,   /* 285: of_async_config_prop_table_status_slave */
    -1,   /* 286: of_bsn_controller_connection */
    -1,   /* 287: of_bsn_debug_counter_desc_stats_entry */
    -1,   /* 288: of_bsn_debug_counter_stats_entry */
    -1,   /* 289: of_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 290: of_bsn_generic_stats_entry */
    -1,   /* 291: of_bsn_gentable_bucket_stats_entry */
    -1,   /* 292: of_bsn_gentable_desc_stats_entry */
    -1,   /* 293: of_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 294: of_bsn_gentable_entry_stats_entry */
    -1,   /* 295: of_bsn_gentable_stats_entry */
    32,   /* 296: of_bsn_interface */
    -1,   /* 297: of_bsn_lacp_stats_entry */
    -1,   /* 298: of_bsn_port_counter_stats_entry */
    -1,   /* 299: of_bsn_switch_pipeline_stats_entry */
    -1,   /* 300: of_bsn_table_checksum_stats_entry */
    -1,   /* 301: of_bsn_tlv */
    -1,   /* 302: of_bsn_tlv_actor_key */
    -1,   /* 303: of_bsn_tlv_actor_port_num */
    -1,   /* 304: of_bsn_tlv_actor_port_priority */
    -1,   /* 305: of_bsn_tlv_actor_state */
    -1,   /* 306: of_bsn_tlv_actor_system_mac */
    -1,   /* 307: of_bsn_tlv_actor_system_priority */
    -1,   /* 308: of_bsn_tlv_anchor */
    -1,   /* 309: of_bsn_tlv_apply_bytes */
    -1,   /* 310: of_bsn_tlv_apply_packets */
    -1,   /* 311: of_bsn_tlv_broadcast_query_timeout */
    -1,   /* 312: of_bsn_tlv_broadcast_rate */
    -1,   /* 313: of_bsn_tlv_bucket */
    -1,   /* 314: of_bsn_tlv_circuit_id */
    -1,   /* 315: of_bsn_tlv_convergence_status */
    -1,   /* 316: of_bsn_tlv_cpu_lag */
    -1,   /* 317: of_bsn_tlv_crc_enabled */
    -1,   /* 318: of_bsn_tlv_data */
    -1,   /* 319: of_bsn_tlv_data_mask */
    -1,   /* 320: of_bsn_tlv_decap */
    -1,   /* 321: of_bsn_tlv_disable_src_mac_check */
    -1,   /* 322: of_bsn_tlv_drop */
    -1,   /* 323: of_bsn_tlv_dscp */
    -1,   /* 324: of_bsn_tlv_ecn */
    -1,   /* 325: of_bsn_tlv_egress_only */
    -1,   /* 326: of_bsn_tlv_egress_port_group_id */
    -1,   /* 327: of_bsn_tlv_eth_dst */
    -1,   /* 328: of_bsn_tlv_eth_src */
    -1,   /* 329: of_bsn_tlv_eth_type */
    -1,   /* 330: of_bsn_tlv_external_gateway_ip */
    -1,   /* 331: of_bsn_tlv_external_gateway_mac */
    -1,   /* 332: of_bsn_tlv_external_ip */
    -1,   /* 333: of_bsn_tlv_external_mac */
    -1,   /* 334: of_bsn_tlv_external_netmask */
    -1,   /* 335: of_bsn_tlv_generation_id */
    -1,   /* 336: of_bsn_tlv_hash_gtp_header_match */
    -1,   /* 337: of_bsn_tlv_hash_gtp_port_match */
    -1,   /* 338: of_bsn_tlv_hash_packet_field */
    -1,   /* 339: of_bsn_tlv_hash_packet_type */
    -1,   /* 340: of_bsn_tlv_hash_seed */
    -1,   /* 341: of_bsn_tlv_hash_type */
    -1,   /* 342: of_bsn_tlv_header_size */
    -1,   /* 343: of_bsn_tlv_icmp_code */
    -1,   /* 344: of_bsn_tlv_icmp_id */
    -1,   /* 345: of_bsn_tlv_icmp_type */
    -1,   /* 346: of_bsn_tlv_icmpv6_chksum */
    -1,   /* 347: of_bsn_tlv_idle_notification */
    -1,   /* 348: of_bsn_tlv_idle_time */
    -1,   /* 349: of_bsn_tlv_idle_timeout */
    -1,   /* 350: of_bsn_tlv_igmp_snooping */
    -1,   /* 351: of_bsn_tlv_ingress_port_group_id */
    -1,   /* 352: of_bsn_tlv_internal_gateway_mac */
    -1,   /* 353: of_bsn_tlv_internal_mac */
    -1,   /* 354: of_bsn_tlv_interval */
    -1,   /* 355: of_bsn_tlv_ip_proto */
    -1,   /* 356: of_bsn_tlv_ipv4 */
    -1,   /* 357: of_bsn_tlv_ipv4_dst */
    -1,   /* 358: of_bsn_tlv_ipv4_netmask */
    -1,   /* 359: of_bsn_tlv_ipv4_src */
    -1,   /* 360: of_bsn_tlv_ipv6 */
    -1,   /* 361: of_bsn_tlv_ipv6_dst */
    -1,   /* 362: of_bsn_tlv_ipv6_prefix */
    -1,   /* 363: of_bsn_tlv_ipv6_src */
    -1,   /* 364: of_bsn_tlv_known_multicast_rate */
    -1,   /* 365: of_bsn_tlv_l2_multicast_lookup */
    -1,   /* 366: of_bsn_tlv_l3_dst_class_id */
    -1,   /* 367: of_bsn_tlv_l3_interface_class_id */
    -1,   /* 368: of_bsn_tlv_l3_src_class_id */
    -1,   /* 369: of_bsn_tlv_loopback_port */
    -1,   /* 370: of_bsn_tlv_mac */
    -1,   /* 371: of_bsn_tlv_mac_mask */
    -1,   /* 372: of_bsn_tlv_mcg_type_vxlan */
    -1,   /* 373: of_bsn_tlv_miss_packets */
    -1,   /* 374: of_bsn_tlv_mpls_control_word */
    -1,   /* 375: of_bsn_tlv_mpls_label */
    -1,   /* 376: of_bsn_tlv_mpls_sequenced */
    -1,   /* 377: of_bsn_tlv_multicast_interface_id */
    -1,   /* 378: of_bsn_tlv_name */
    -1,   /* 379: of_bsn_tlv_ndp_offload */
    -1,   /* 380: of_bsn_tlv_ndp_static */
    -1,   /* 381: of_bsn_tlv_negate */
    -1,   /* 382: of_bsn_tlv_next_hop_ipv4 */
    -1,   /* 383: of_bsn_tlv_next_hop_mac */
    -1,   /* 384: of_bsn_tlv_nexthop_type_vxlan */
    -1,   /* 385: of_bsn_tlv_offset */
    -1,   /* 386: of_bsn_tlv_parent_port */
    -1,   /* 387: of_bsn_tlv_partner_key */
    -1,   /* 388: of_bsn_tlv_partner_port_num */
    -1,   /* 389: of_bsn_tlv_partner_port_priority */
    -1,   /* 390: of_bsn_tlv_partner_state */
    -1,   /* 391: of_bsn_tlv_partner_system_mac */
    -1,   /* 392: of_bsn_tlv_partner_system_priority */
    -1,   /* 393: of_bsn_tlv_port */
    -1,   /* 394: of_bsn_tlv_port_usage */
    -1,   /* 395: of_bsn_tlv_port_vxlan_mode */
    -1,   /* 396: of_bsn_tlv_priority */
    -1,   /* 397: of_bsn_tlv_push_vlan_on_ingress */
    -1,   /* 398: of_bsn_tlv_qos_priority */
    -1,   /* 399: of_bsn_tlv_queue_id */
    -1,   /* 400: of_bsn_tlv_queue_weight */
    -1,   /* 401: of_bsn_tlv_rate_limit */
    -1,   /* 402: of_bsn_tlv_rate_unit */
    -1,   /* 403: of_bsn_tlv_reference */
    -1,   /* 404: of_bsn_tlv_reply_packets */
    -1,   /* 405: of_bsn_tlv_request_packets */
    -1,   /* 406: of_bsn_tlv_rx_bytes */
    -1,   /* 407: of_bsn_tlv_rx_packets */
    -1,   /* 408: of_bsn_tlv_sampling_rate */
    -1,   /* 409: of_bsn_tlv_set_loopback_mode */
    -1,   /* 410: of_bsn_tlv_status */
    -1,   /* 411: of_bsn_tlv_strip_mpls_l2_on_ingress */
    -1,   /* 412: of_bsn_tlv_strip_mpls_l3_on_ingress */
    -1,   /* 413: of_bsn_tlv_strip_vlan_on_egress */
    -1,   /* 414: of_bsn_tlv_sub_agent_id */
    -1,   /* 415: of_bsn_tlv_tcp_dst */
    -1,   /* 416: of_bsn_tlv_tcp_flags */
    -1,   /* 417: of_bsn_tlv_tcp_src */
    -1,   /* 418: of_bsn_tlv_ttl */
    -1,   /* 419: of_bsn_tlv_tx_bytes */
    -1,   /* 420: of_bsn_tlv_tx_packets */
    -1,   /* 421: of_bsn_tlv_udf_anchor */
    -1,   /* 422: of_bsn_tlv_udf_id */
    -1,   /* 423: of_bsn_tlv_udf_length */
    -1,   /* 424: of_bsn_tlv_udf_offset */
    -1,   /* 425: of_bsn_tlv_udp_dst */
    -1,   /* 426: of_bsn_tlv_udp_src */
    -1,   /* 427: of_bsn_tlv_uint64_list */
    -1,   /* 428: of_bsn_tlv_unicast_query_timeout */
    -1,   /* 429: of_bsn_tlv_unicast_rate */
    -1,   /* 430: of_bsn_tlv_unknown_multicast_rate */
    -1,   /* 431: of_bsn_tlv_untagged */
    -1,   /* 432: of_bsn_tlv_use_packet_state */
    -1,   /* 433: of_bsn_tlv_vfi */
    -1,   /* 434: of_bsn_tlv_vfp_class_id */
    -1,   /* 435: of_bsn_tlv_vlan_mac_list */
    -1,   /* 436: of_bsn_tlv_vlan_pcp */
    -1,   /* 437: of_bsn_tlv_vlan_vid */
    -1,   /* 438: of_bsn_tlv_vlan_vid_mask */
    -1,   /* 439: of_bsn_tlv_vni */
    -1,   /* 440: of_bsn_tlv_vpn_key */
    -1,   /* 441: of_bsn_tlv_vrf */
    -1,   /* 442: of_bsn_tlv_vxlan_egress_lag */
    -1,   /* 443: of_bsn_vlan_counter_stats_entry */
    -1,   /* 444: of_bsn_vlan_mac */
    4,    /* 445: of_bsn_vport */
    64,   /* 446: of_bsn_vport_l2gre */
    32,   /* 447: of_bsn_vport_q_in_q */
    -1,   /* 448: of_bsn_vrf_counter_stats_entry */
    16,   /* 449: of_bucket */
    16,   /* 450: of_bucket_counter */
    -1,   /* 451: of_bundle_prop */
    -1,   /* 452: of_bundle_prop_experimenter */
    136,  /* 453: of_flow_stats_entry */
    8,    /* 454: of_group_desc_stats_entry */
    32,   /* 455: of_group_stats_entry */
    -1,   /* 456: of_hello_elem */
    -1,   /* 457: of_hello_elem_versionbitmap */
    8,    /* 458: of_instruction */
    8,    /* 459: of_instruction_apply_actions */
    -1,   /* 460: of_instruction_bsn */
    -1,   /* 461: of_instruction_bsn_arp_offload */
    -1,   /* 462: of_instruction_bsn_auto_negotiation */
    -1,   /* 463: of_instruction_bsn_deny */
    -1,   /* 464: of_instruction_bsn_dhcp_offload */
    -1,   /* 465: of_instruction_bsn_disable_l3 */
    -1,   /* 466: of_instruction_bsn_disable_split_horizon_check */
    -1,   /* 467: of_instruction_bsn_disable_src_mac_check */
    -1,   /* 468: of_instruction_bsn_disable_vlan_counters */
    -1,   /* 469: of_instruction_bsn_hash_select */
    -1,   /* 470: of_instruction_bsn_internal_priority */
    -1,   /* 471: of_instruction_bsn_ndp_offload */
    -1,   /* 472: of_instruction_bsn_packet_of_death */
    -1,   /* 473: of_instruction_bsn_permit */
    -1,   /* 474: of_instruction_bsn_prioritize_pdus */
    -1,   /* 475: of_instruction_bsn_require_vlan_xlate */
    -1,   /* 476: of_instruction_bsn_span_destination */
    8,    /* 477: of_instruction_clear_actions */
    8,    /* 478: of_instruction_experimenter */
    8,    /* 479: of_instruction_goto_table */
    -1,   /* 480: of_instruction_id */
    -1,   /* 481: of_instruction_id_apply_actions */
    -1,   /* 482: of_instruction_id_bsn */
    -1,   /* 483: of_instruction_id_bsn_arp_offload */
    -1,   /* 484: of_instruction_id_bsn_auto_negotiation */
    -1,   /* 485: of_instruction_id_bsn_deny */
    -1,   /* 486: of_instruction_id_bsn_dhcp_offload */
    -1,   /* 487: of_instruction_id_bsn_disable_l3 */
    -1,   /* 488: of_instruction_id_bsn_disable_split_horizon_check */
    -1,   /* 489: of_instruction_id_bsn_disable_src_mac_check */
    -1,   /* 490: of_instruction_id_bsn_disable_vlan_counters */
    -1,   /* 491: of_instruction_id_bsn_hash_select */
    -1,   /* 492: of_instruction_id_bsn_internal_priority */
    -1,   /* 493: of_instruction_id_bsn_ndp_offload */
    -1,   /* 494: of_instruction_id_bsn_packet_of_death */
    -1,   /* 495: of_instruction_id_bsn_permit */
    -1,   /* 496: of_instruction_id_bsn_prioritize_pdus */
    -1,   /* 497: of_instruction_id_bsn_require_vlan_xlate */
    -1,   /* 498: of_instruction_id_bsn_span_destination */
    -1,   /* 499: of_instruction_id_clear_actions */
    -1,   /* 500: of_instruction_id_experimenter */
    -1,   /* 501: of_instruction_id_goto_table */
    -1,   /* 502: of_instruction_id_meter */
    -1,   /* 503: of_instruction_id_write_actions */
    -1,   /* 504: of_instruction_id_write_metadata */
    -1,   /* 505: of_instruction_meter */
    8,    /* 506: of_instruction_write_actions */
    24,   /* 507: of_instruction_write_metadata */
    -1,   /* 508: of_match_v1 */
    88,   /* 509: of_match_v2 */
    -1,   /* 510: of_match_v3 */
    -1,   /* 511: of_meter_band */
    -1,   /* 512: of_meter_band_drop */
    -1,   /* 513: of_meter_band_dscp_remark */
    -1,   /* 514: of_meter_band_experimenter */
    -1,   /* 515: of_meter_band_stats */
    -1,   /* 516: of_meter_config */
    -1,   /* 517: of_meter_features */
    -1,   /* 518: of_meter_stats */
    -1,   /* 519: of_oxm */
    -1,   /* 520: of_oxm_arp_op */
    -1,   /* 521: of_oxm_arp_op_masked */
    -1,   /* 522: of_oxm_arp_sha */
    -1,   /* 523: of_oxm_arp_sha_masked */
    -1,   /* 524: of_oxm_arp_spa */
    -1,   /* 525: of_oxm_arp_spa_masked */
    -1,   /* 526: of_oxm_arp_tha */
    -1,   /* 527: of_oxm_arp_tha_masked */
    -1,   /* 528: of_oxm_arp_tpa */
    -1,   /* 529: of_oxm_arp_tpa_masked */
    -1,   /* 530: of_oxm_bsn_egr_port_group_id */
    -1,   /* 531: of_oxm_bsn_egr_port_group_id_masked */
    -1,   /* 532: of_oxm_bsn_global_vrf_allowed */
    -1,   /* 533: of_oxm_bsn_global_vrf_allowed_masked */
    -1,   /* 534: of_oxm_bsn_in_ports_128 */
    -1,   /* 535: of_oxm_bsn_in_ports_128_masked */
    -1,   /* 536: of_oxm_bsn_in_ports_512 */
    -1,   /* 537: of_oxm_bsn_in_ports_512_masked */
    -1,   /* 538: of_oxm_bsn_ingress_port_group_id */
    -1,   /* 539: of_oxm_bsn_ingress_port_group_id_masked */
    -1,   /* 540: of_oxm_bsn_inner_eth_dst */
    -1,   /* 541: of_oxm_bsn_inner_eth_dst_masked */
    -1,   /* 542: of_oxm_bsn_inner_eth_src */
    -1,   /* 543: of_oxm_bsn_inner_eth_src_masked */
    -1,   /* 544: of_oxm_bsn_inner_vlan_vid */
    -1,   /* 545: of_oxm_bsn_inner_vlan_vid_masked */
    -1,   /* 546: of_oxm_bsn_ip_fragmentation */
    -1,   /* 547: of_oxm_bsn_ip_fragmentation_masked */
    -1,   /* 548: of_oxm_bsn_l2_cache_hit */
    -1,   /* 549: of_oxm_bsn_l2_cache_hit_masked */
    -1,   /* 550: of_oxm_bsn_l3_dst_class_id */
    -1,   /* 551: of_oxm_bsn_l3_dst_class_id_masked */
    -1,   /* 552: of_oxm_bsn_l3_interface_class_id */
    -1,   /* 553: of_oxm_bsn_l3_interface_class_id_masked */
    -1,   /* 554: of_oxm_bsn_l3_src_class_id */
    -1,   /* 555: of_oxm_bsn_l3_src_class_id_masked */
    -1,   /* 556: of_oxm_bsn_lag_id */
    -1,   /* 557: of_oxm_bsn_lag_id_masked */
    -1,   /* 558: of_oxm_bsn_tcp_flags */
    -1,   /* 559: of_oxm_bsn_tcp_flags_masked */
    -1,   /* 560: of_oxm_bsn_udf0 */
    -1,   /* 561: of_oxm_bsn_udf0_masked */
    -1,   /* 562: of_oxm_bsn_udf1 */
    -1,   /* 563: of_oxm_bsn_udf1_masked */
    -1,   /* 564: of_oxm_bsn_udf2 */
    -1,   /* 565: of_oxm_bsn_udf2_masked */
    -1,   /* 566: of_oxm_bsn_udf3 */
    -1,   /* 567: of_oxm_bsn_udf3_masked */
    -1,   /* 568: of_oxm_bsn_udf4 */
    -1,   /* 569: of_oxm_bsn_udf4_masked */
    -1,   /* 570: of_oxm_bsn_udf5 */
    -1,   /* 571: of_oxm_bsn_udf5_masked */
    -1,   /* 572: of_oxm_bsn_udf6 */
    -1,   /* 573: of_oxm_bsn_udf6_masked */
    -1,   /* 574: of_oxm_bsn_udf7 */
    -1,   /* 575: of_oxm_bsn_udf7_masked */
    -1,   /* 576: of_oxm_bsn_vfi */
    -1,   /* 577: of_oxm_bsn_vfi_masked */
    -1,   /* 578: of_oxm_bsn_vlan_xlate_port_group_id */
    -1,   /* 579: of_oxm_bsn_vlan_xlate_port_group_id_masked */
    -1,   /* 580: of_oxm_bsn_vrf */
    -1,   /* 581: of_oxm_bsn_vrf_masked */
    -1,   /* 582: of_oxm_bsn_vxlan_network_id */
    -1,   /* 583: of_oxm_bsn_vxlan_network_id_masked */
    -1,   /* 584: of_oxm_eth_dst */
    -1,   /* 585: of_oxm_eth_dst_masked */
    -1,   /* 586: of_oxm_eth_src */
    -1,   /* 587: of_oxm_eth_src_masked */
    -1,   /* 588: of_oxm_eth_type */
    -1,   /* 589: of_oxm_eth_type_masked */
    -1,   /* 590: of_oxm_icmpv4_code */
    -1,   /* 591: of_oxm_icmpv4_code_masked */
    -1,   /* 592: of_oxm_icmpv4_type */
    -1,   /* 593: of_oxm_icmpv4_type_masked */
    -1,   /* 594: of_oxm_icmpv6_code */
    -1,   /* 595: of_oxm_icmpv6_code_masked */
    -1,   /* 596: of_oxm_icmpv6_type */
    -1,   /* 597: of_oxm_icmpv6_type_masked */
    -1,   /* 598: of_oxm_in_phy_port */
    -1,   /* 599: of_oxm_in_phy_port_masked */
    -1,   /* 600: of_oxm_in_port */
    -1,   /* 601: of_oxm_in_port_masked */
    -1,   /* 602: of_oxm_ip_dscp */
    -1,   /* 603: of_oxm_ip_dscp_masked */
    -1,   /* 604: of_oxm_ip_ecn */
    -1,   /* 605: of_oxm_ip_ecn_masked */
    -1,   /* 606: of_oxm_ip_proto */
    -1,   /* 607: of_oxm_ip_proto_masked */
    -1,   /* 608: of_oxm_ipv4_dst */
    -1,   /* 609: of_oxm_ipv4_dst_masked */
    -1,   /* 610: of_oxm_ipv4_src */
    -1,   /* 611: of_oxm_ipv4_src_masked */
    -1,   /* 612: of_oxm_ipv6_dst */
    -1,   /* 613: of_oxm_ipv6_dst_masked */
    -1,   /* 614: of_oxm_ipv6_exthdr */
    -1,   /* 615: of_oxm_ipv6_exthdr_masked */
    -1,   /* 616: of_oxm_ipv6_flabel */
    -1,   /* 617: of_oxm_ipv6_flabel_masked */
    -1,   /* 618: of_oxm_ipv6_nd_sll */
    -1,   /* 619: of_oxm_ipv6_nd_sll_masked */
    -1,   /* 620: of_oxm_ipv6_nd_target */
    -1,   /* 621: of_oxm_ipv6_nd_target_masked */
    -1,   /* 622: of_oxm_ipv6_nd_tll */
    -1,   /* 623: of_oxm_ipv6_nd_tll_masked */
    -1,   /* 624: of_oxm_ipv6_src */
    -1,   /* 625: of_oxm_ipv6_src_masked */
    -1,   /* 626: of_oxm_metadata */
    -1,   /* 627: of_oxm_metadata_masked */
    -1,   /* 628: of_oxm_mpls_bos */
    -1,   /* 629: of_oxm_mpls_bos_masked */
    -1,   /* 630: of_oxm_mpls_label */
    -1,   /* 631: of_oxm_mpls_label_masked */
    -1,   /* 632: of_oxm_mpls_tc */
    -1,   /* 633: of_oxm_mpls_tc_masked */
    -1,   /* 634: of_oxm_ovs_tcp_flags */
    -1,   /* 635: of_oxm_ovs_tcp_flags_masked */
    -1,   /* 636: of_oxm_pbb_uca */
    -1,   /* 637: of_oxm_pbb_uca_masked */
    -1,   /* 638: of_oxm_sctp_dst */
    -1,   /* 639: of_oxm_sctp_dst_masked */
    -1,   /* 640: of_oxm_sctp_src */
    -1,   /* 641: of_oxm_sctp_src_masked */
    -1,   /* 642: of_oxm_tcp_dst */
    -1,   /* 643: of_oxm_tcp_dst_masked */
    -1,   /* 644: of_oxm_tcp_src */
    -1,   /* 645: of_oxm_tcp_src_masked */
    -1,   /* 646: of_oxm_tunnel_id */
    -1,   /* 647: of_oxm_tunnel_id_masked */
    -1,   /* 648: of_oxm_tunnel_ipv4_dst */
    -1,   /* 649: of_oxm_tunnel_ipv4_dst_masked */
    -1,   /* 650: of_oxm_tunnel_ipv4_src */
    -1,   /* 651: of_oxm_tunnel_ipv4_src_masked */
    -1,   /* 652: of_oxm_udp_dst */
    -1,   /* 653: of_oxm_udp_dst_masked */
    -1,   /* 654: of_oxm_udp_src */
    -1,   /* 655: of_oxm_udp_src_masked */
    -1,   /* 656: of_oxm_vlan_pcp */
    -1,   /* 657: of_oxm_vlan_pcp_masked */
    -1,   /* 658: of_oxm_vlan_vid */
    -1,   /* 659: of_oxm_vlan_vid_masked */
    8,    /* 660: of_packet_queue */
    64,   /* 661: of_port_desc */
    -1,   /* 662: of_port_desc_prop */
    -1,   /* 663: of_port_desc_prop_bsn */
    -1,   /* 664: of_port_desc_prop_bsn_generation_id */
    -1,   /* 665: of_port_desc_prop_bsn_uplink */
    -1,   /* 666: of_port_desc_prop_ethernet */
    -1,   /* 667: of_port_desc_prop_experimenter */
    -1,   /* 668: of_port_desc_prop_optical */
    -1,   /* 669: of_port_mod_prop */
    -1,   /* 670: of_port_mod_prop_ethernet */
    -1,   /* 671: of_port_mod_prop_experimenter */
    -1,   /* 672: of_port_mod_prop_optical */
    104,  /* 673: of_port_stats_entry */
    -1,   /* 674: of_port_stats_prop */
    -1,   /* 675: of_port_stats_prop_ethernet */
    -1,   /* 676: of_port_stats_prop_experimenter */
    -1,   /* 677: of_port_stats_prop_optical */
    -1,   /* 678: of_queue_desc */
    -1,   /* 679: of_queue_desc_prop */
    -1,   /* 680: of_queue_desc_prop_bsn */
    -1,   /* 681: of_queue_desc_prop_bsn_queue_name */
    -1,   /* 682: of_queue_desc_prop_experimenter */
    -1,   /* 683: of_queue_desc_prop_max_rate */
    -1,   /* 684: of_queue_desc_prop_min_rate */
    8,    /* 685: of_queue_prop */
    -1,   /* 686: of_queue_prop_experimenter */
    -1,   /* 687: of_queue_prop_max_rate */
    16,   /* 688: of_queue_prop_min_rate */
    32,   /* 689: of_queue_stats_entry */
    -1,   /* 690: of_queue_stats_prop */
    -1,   /* 691: of_queue_stats_prop_experimenter */
    -1,   /* 692: of_role_prop */
    -1,   /* 693: of_role_prop_experimenter */
    -1,   /* 694: of_table_desc */
    -1,   /* 695: of_table_feature_prop */
    -1,   /* 696: of_table_feature_prop_apply_actions */
    -1,   /* 697: of_table_feature_prop_apply_actions_miss */
    -1,   /* 698: of_table_feature_prop_apply_setfield */
    -1,   /* 699: of_table_feature_prop_apply_setfield_miss */
    -1,   /* 700: of_table_feature_prop_experimenter */
    -1,   /* 701: of_table_feature_prop_experimenter_miss */
    -1,   /* 702: of_table_feature_prop_instructions */
    -1,   /* 703: of_table_feature_prop_instructions_miss */
    -1,   /* 704: of_table_feature_prop_match */
    -1,   /* 705: of_table_feature_prop_next_tables */
    -1,   /* 706: of_table_feature_prop_next_tables_miss */
    -1,   /* 707: of_table_feature_prop_table_sync_from */
    -1,   /* 708: of_table_feature_prop_wildcards */
    -1,   /* 709: of_table_feature_prop_write_actions */
    -1,   /* 710: of_table_feature_prop_write_actions_miss */
    -1,   /* 711: of_table_feature_prop_write_setfield */
    -1,   /* 712: of_table_feature_prop_write_setfield_miss */
    -1,   /* 713: of_table_features */
    -1,   /* 714: of_table_mod_prop */
    -1,   /* 715: of_table_mod_prop_eviction */
    -1,   /* 716: of_table_mod_prop_experimenter */
    -1,   /* 717: of_table_mod_prop_vacancy */
    88,   /* 718: of_table_stats_entry */
    -1,   /* 719: of_uint32 */
    -1,   /* 720: of_uint64 */
    -1,   /* 721: of_uint8 */
    0,    /* 722: of_list_action */
    -1,   /* 723: of_list_action_id */
    -1,   /* 724: of_list_async_config_prop */
    -1,   /* 725: of_list_bsn_controller_connection */
    -1,   /* 726: of_list_bsn_debug_counter_desc_stats_entry */
    -1,   /* 727: of_list_bsn_debug_counter_stats_entry */
    -1,   /* 728: of_list_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 729: of_list_bsn_generic_stats_entry */
    -1,   /* 730: of_list_bsn_gentable_bucket_stats_entry */
    -1,   /* 731: of_list_bsn_gentable_desc_stats_entry */
    -1,   /* 732: of_list_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 733: of_list_bsn_gentable_entry_stats_entry */
    -1,   /* 734: of_list_bsn_gentable_stats_entry */
    0,    /* 735: of_list_bsn_interface */
    -1,   /* 736: of_list_bsn_lacp_stats_entry */
    -1,   /* 737: of_list_bsn_port_counter_stats_entry */
    -1,   /* 738: of_list_bsn_switch_pipeline_stats_entry */
    -1,   /* 739: of_list_bsn_table_checksum_stats_entry */
    -1,   /* 740: of_list_bsn_tlv */
    -1,   /* 741: of_list_bsn_vlan_counter_stats_entry */
    -1,   /* 742: of_list_bsn_vlan_mac */
    -1,   /* 743: of_list_bsn_vrf_counter_stats_entry */
    0,    /* 744: of_list_bucket */
    0,    /* 745: of_list_bucket_counter */
    -1,   /* 746: of_list_bundle_prop */
    0,    /* 747: of_list_flow_stats_entry */
    0,    /* 748: of_list_group_desc_stats_entry */
    0,    /* 749: of_list_group_stats_entry */
    -1,   /* 750: of_list_hello_elem */
    0,    /* 751: of_list_instruction */
    -1,   /* 752: of_list_instruction_id */
    -1,   /* 753: of_list_meter_band */
    -1,   /* 754: of_list_meter_band_stats */
    -1,   /* 755: of_list_meter_config */
    -1,   /* 756: of_list_meter_stats */
    -1,   /* 757: of_list_oxm */
    0,    /* 758: of_list_packet_queue */
    0,    /* 759: of_list_port_desc */
    -1,   /* 760: of_list_port_desc_prop */
    -1,   /* 761: of_list_port_mod_prop */
    0,    /* 762: of_list_port_stats_entry */
    -1,   /* 763: of_list_port_stats_prop */
    -1,   /* 764: of_list_queue_desc */
    -1,   /* 765: of_list_queue_desc_prop */
    0,    /* 766: of_list_queue_prop */
    0,    /* 767: of_list_queue_stats_entry */
    -1,   /* 768: of_list_queue_stats_prop */
    -1,   /* 769: of_list_role_prop */
    -1,   /* 770: of_list_table_desc */
    -1,   /* 771: of_list_table_feature_prop */
    -1,   /* 772: of_list_table_features */
    -1,   /* 773: of_list_table_mod_prop */
    0,    /* 774: of_list_table_stats_entry */
    -1,   /* 775: of_list_uint32 */
    -1,   /* 776: of_list_uint64 */
    -1    /* 777: of_list_uint8 */
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
    -1,   /* 15: of_bsn_base_error */
    20,   /* 16: of_bsn_bw_clear_data_reply */
    16,   /* 17: of_bsn_bw_clear_data_request */
    20,   /* 18: of_bsn_bw_enable_get_reply */
    16,   /* 19: of_bsn_bw_enable_get_request */
    24,   /* 20: of_bsn_bw_enable_set_reply */
    20,   /* 21: of_bsn_bw_enable_set_request */
    -1,   /* 22: of_bsn_controller_connections_reply */
    -1,   /* 23: of_bsn_controller_connections_request */
    -1,   /* 24: of_bsn_debug_counter_desc_stats_reply */
    -1,   /* 25: of_bsn_debug_counter_desc_stats_request */
    -1,   /* 26: of_bsn_debug_counter_stats_reply */
    -1,   /* 27: of_bsn_debug_counter_stats_request */
    -1,   /* 28: of_bsn_error */
    -1,   /* 29: of_bsn_flow_checksum_bucket_stats_reply */
    -1,   /* 30: of_bsn_flow_checksum_bucket_stats_request */
    -1,   /* 31: of_bsn_flow_idle */
    -1,   /* 32: of_bsn_flow_idle_enable_get_reply */
    -1,   /* 33: of_bsn_flow_idle_enable_get_request */
    -1,   /* 34: of_bsn_flow_idle_enable_set_reply */
    -1,   /* 35: of_bsn_flow_idle_enable_set_request */
    -1,   /* 36: of_bsn_generic_async */
    -1,   /* 37: of_bsn_generic_command */
    -1,   /* 38: of_bsn_generic_stats_reply */
    -1,   /* 39: of_bsn_generic_stats_request */
    -1,   /* 40: of_bsn_gentable_bucket_stats_reply */
    -1,   /* 41: of_bsn_gentable_bucket_stats_request */
    -1,   /* 42: of_bsn_gentable_clear_reply */
    -1,   /* 43: of_bsn_gentable_clear_request */
    -1,   /* 44: of_bsn_gentable_desc_stats_reply */
    -1,   /* 45: of_bsn_gentable_desc_stats_request */
    -1,   /* 46: of_bsn_gentable_entry_add */
    -1,   /* 47: of_bsn_gentable_entry_delete */
    -1,   /* 48: of_bsn_gentable_entry_desc_stats_reply */
    -1,   /* 49: of_bsn_gentable_entry_desc_stats_request */
    -1,   /* 50: of_bsn_gentable_entry_stats_reply */
    -1,   /* 51: of_bsn_gentable_entry_stats_request */
    -1,   /* 52: of_bsn_gentable_set_buckets_size */
    -1,   /* 53: of_bsn_gentable_stats_reply */
    -1,   /* 54: of_bsn_gentable_stats_request */
    16,   /* 55: of_bsn_get_interfaces_reply */
    16,   /* 56: of_bsn_get_interfaces_request */
    -1,   /* 57: of_bsn_get_ip_mask_reply */
    -1,   /* 58: of_bsn_get_ip_mask_request */
    -1,   /* 59: of_bsn_get_l2_table_reply */
    -1,   /* 60: of_bsn_get_l2_table_request */
    20,   /* 61: of_bsn_get_mirroring_reply */
    20,   /* 62: of_bsn_get_mirroring_request */
    -1,   /* 63: of_bsn_get_switch_pipeline_reply */
    -1,   /* 64: of_bsn_get_switch_pipeline_request */
    16,   /* 65: of_bsn_header */
    -1,   /* 66: of_bsn_hybrid_get_reply */
    -1,   /* 67: of_bsn_hybrid_get_request */
    -1,   /* 68: of_bsn_image_desc_stats_reply */
    -1,   /* 69: of_bsn_image_desc_stats_request */
    -1,   /* 70: of_bsn_lacp_convergence_notif */
    -1,   /* 71: of_bsn_lacp_stats_reply */
    -1,   /* 72: of_bsn_lacp_stats_request */
    -1,   /* 73: of_bsn_log */
    -1,   /* 74: of_bsn_lua_command_reply */
    -1,   /* 75: of_bsn_lua_command_request */
    -1,   /* 76: of_bsn_lua_notification */
    -1,   /* 77: of_bsn_lua_upload */
    25,   /* 78: of_bsn_pdu_rx_reply */
    28,   /* 79: of_bsn_pdu_rx_request */
    21,   /* 80: of_bsn_pdu_rx_timeout */
    25,   /* 81: of_bsn_pdu_tx_reply */
    28,   /* 82: of_bsn_pdu_tx_request */
    -1,   /* 83: of_bsn_port_counter_stats_reply */
    -1,   /* 84: of_bsn_port_counter_stats_request */
    -1,   /* 85: of_bsn_role_status */
    -1,   /* 86: of_bsn_set_aux_cxns_reply */
    -1,   /* 87: of_bsn_set_aux_cxns_request */
    -1,   /* 88: of_bsn_set_ip_mask */
    -1,   /* 89: of_bsn_set_l2_table_reply */
    -1,   /* 90: of_bsn_set_l2_table_request */
    -1,   /* 91: of_bsn_set_lacp_reply */
    -1,   /* 92: of_bsn_set_lacp_request */
    20,   /* 93: of_bsn_set_mirroring */
    20,   /* 94: of_bsn_set_pktin_suppression_reply */
    32,   /* 95: of_bsn_set_pktin_suppression_request */
    -1,   /* 96: of_bsn_set_switch_pipeline_reply */
    -1,   /* 97: of_bsn_set_switch_pipeline_request */
    -1,   /* 98: of_bsn_shell_command */
    -1,   /* 99: of_bsn_shell_output */
    -1,   /* 100: of_bsn_shell_status */
    24,   /* 101: of_bsn_stats_reply */
    24,   /* 102: of_bsn_stats_request */
    -1,   /* 103: of_bsn_switch_pipeline_stats_reply */
    -1,   /* 104: of_bsn_switch_pipeline_stats_request */
    -1,   /* 105: of_bsn_table_checksum_stats_reply */
    -1,   /* 106: of_bsn_table_checksum_stats_request */
    -1,   /* 107: of_bsn_table_set_buckets_size */
    -1,   /* 108: of_bsn_takeover */
    -1,   /* 109: of_bsn_time_reply */
    -1,   /* 110: of_bsn_time_request */
    24,   /* 111: of_bsn_virtual_port_create_reply */
    20,   /* 112: of_bsn_virtual_port_create_request */
    20,   /* 113: of_bsn_virtual_port_remove_reply */
    20,   /* 114: of_bsn_virtual_port_remove_request */
    -1,   /* 115: of_bsn_vlan_counter_clear */
    -1,   /* 116: of_bsn_vlan_counter_stats_reply */
    -1,   /* 117: of_bsn_vlan_counter_stats_request */
    -1,   /* 118: of_bsn_vrf_counter_stats_reply */
    -1,   /* 119: of_bsn_vrf_counter_stats_request */
    -1,   /* 120: of_bundle_add_msg */
    -1,   /* 121: of_bundle_ctrl_msg */
    -1,   /* 122: of_bundle_failed_error_msg */
    1072, /* 123: of_desc_stats_reply */
    16,   /* 124: of_desc_stats_request */
    8,    /* 125: of_echo_reply */
    8,    /* 126: of_echo_request */
    10,   /* 127: of_error_msg */
    16,   /* 128: of_experimenter */
    16,   /* 129: of_experimenter_error_msg */
    24,   /* 130: of_experimenter_stats_reply */
    24,   /* 131: of_experimenter_stats_request */
    32,   /* 132: of_features_reply */
    8,    /* 133: of_features_request */
    56,   /* 134: of_flow_add */
    56,   /* 135: of_flow_delete */
    56,   /* 136: of_flow_delete_strict */
    56,   /* 137: of_flow_mod */
    12,   /* 138: of_flow_mod_failed_error_msg */
    56,   /* 139: of_flow_modify */
    56,   /* 140: of_flow_modify_strict */
    -1,   /* 141: of_flow_monitor_failed_error_msg */
    56,   /* 142: of_flow_removed */
    16,   /* 143: of_flow_stats_reply */
    56,   /* 144: of_flow_stats_request */
    12,   /* 145: of_get_config_reply */
    8,    /* 146: of_get_config_request */
    16,   /* 147: of_group_add */
    16,   /* 148: of_group_delete */
    16,   /* 149: of_group_desc_stats_reply */
    16,   /* 150: of_group_desc_stats_request */
    56,   /* 151: of_group_features_stats_reply */
    16,   /* 152: of_group_features_stats_request */
    16,   /* 153: of_group_mod */
    12,   /* 154: of_group_mod_failed_error_msg */
    16,   /* 155: of_group_modify */
    16,   /* 156: of_group_stats_reply */
    24,   /* 157: of_group_stats_request */
    8,    /* 158: of_header */
    8,    /* 159: of_hello */
    12,   /* 160: of_hello_failed_error_msg */
    -1,   /* 161: of_meter_config_stats_reply */
    -1,   /* 162: of_meter_config_stats_request */
    -1,   /* 163: of_meter_features_stats_reply */
    -1,   /* 164: of_meter_features_stats_request */
    -1,   /* 165: of_meter_mod */
    -1,   /* 166: of_meter_mod_failed_error_msg */
    -1,   /* 167: of_meter_stats_reply */
    -1,   /* 168: of_meter_stats_request */
    -1,   /* 169: of_nicira_controller_role_reply */
    -1,   /* 170: of_nicira_controller_role_request */
    16,   /* 171: of_nicira_header */
    26,   /* 172: of_packet_in */
    24,   /* 173: of_packet_out */
    -1,   /* 174: of_port_desc_stats_reply */
    -1,   /* 175: of_port_desc_stats_request */
    40,   /* 176: of_port_mod */
    12,   /* 177: of_port_mod_failed_error_msg */
    16,   /* 178: of_port_stats_reply */
    24,   /* 179: of_port_stats_request */
    80,   /* 180: of_port_status */
    -1,   /* 181: of_queue_desc_stats_reply */
    -1,   /* 182: of_queue_desc_stats_request */
    16,   /* 183: of_queue_get_config_reply */
    16,   /* 184: of_queue_get_config_request */
    12,   /* 185: of_queue_op_failed_error_msg */
    16,   /* 186: of_queue_stats_reply */
    24,   /* 187: of_queue_stats_request */
    -1,   /* 188: of_requestforward */
    24,   /* 189: of_role_reply */
    24,   /* 190: of_role_request */
    12,   /* 191: of_role_request_failed_error_msg */
    -1,   /* 192: of_role_status */
    12,   /* 193: of_set_config */
    16,   /* 194: of_stats_reply */
    16,   /* 195: of_stats_request */
    12,   /* 196: of_switch_config_failed_error_msg */
    -1,   /* 197: of_table_desc_stats_reply */
    -1,   /* 198: of_table_desc_stats_request */
    -1,   /* 199: of_table_features_failed_error_msg */
    -1,   /* 200: of_table_features_stats_reply */
    -1,   /* 201: of_table_features_stats_request */
    16,   /* 202: of_table_mod */
    12,   /* 203: of_table_mod_failed_error_msg */
    16,   /* 204: of_table_stats_reply */
    16,   /* 205: of_table_stats_request */
    -1,   /* 206: of_table_status */
    8,    /* 207: of_action */
    16,   /* 208: of_action_bsn */
    28,   /* 209: of_action_bsn_checksum */
    -1,   /* 210: of_action_bsn_gentable */
    24,   /* 211: of_action_bsn_mirror */
    16,   /* 212: of_action_bsn_set_tunnel_dst */
    8,    /* 213: of_action_copy_ttl_in */
    8,    /* 214: of_action_copy_ttl_out */
    8,    /* 215: of_action_dec_mpls_ttl */
    8,    /* 216: of_action_dec_nw_ttl */
    -1,   /* 217: of_action_enqueue */
    8,    /* 218: of_action_experimenter */
    8,    /* 219: of_action_group */
    -1,   /* 220: of_action_id */
    -1,   /* 221: of_action_id_bsn */
    -1,   /* 222: of_action_id_bsn_checksum */
    -1,   /* 223: of_action_id_bsn_gentable */
    -1,   /* 224: of_action_id_bsn_mirror */
    -1,   /* 225: of_action_id_bsn_set_tunnel_dst */
    -1,   /* 226: of_action_id_copy_ttl_in */
    -1,   /* 227: of_action_id_copy_ttl_out */
    -1,   /* 228: of_action_id_dec_mpls_ttl */
    -1,   /* 229: of_action_id_dec_nw_ttl */
    -1,   /* 230: of_action_id_experimenter */
    -1,   /* 231: of_action_id_group */
    -1,   /* 232: of_action_id_nicira */
    -1,   /* 233: of_action_id_nicira_dec_ttl */
    -1,   /* 234: of_action_id_output */
    -1,   /* 235: of_action_id_pop_mpls */
    -1,   /* 236: of_action_id_pop_pbb */
    -1,   /* 237: of_action_id_pop_vlan */
    -1,   /* 238: of_action_id_push_mpls */
    -1,   /* 239: of_action_id_push_pbb */
    -1,   /* 240: of_action_id_push_vlan */
    -1,   /* 241: of_action_id_set_field */
    -1,   /* 242: of_action_id_set_mpls_ttl */
    -1,   /* 243: of_action_id_set_nw_ttl */
    -1,   /* 244: of_action_id_set_queue */
    16,   /* 245: of_action_nicira */
    16,   /* 246: of_action_nicira_dec_ttl */
    16,   /* 247: of_action_output */
    8,    /* 248: of_action_pop_mpls */
    -1,   /* 249: of_action_pop_pbb */
    8,    /* 250: of_action_pop_vlan */
    8,    /* 251: of_action_push_mpls */
    -1,   /* 252: of_action_push_pbb */
    8,    /* 253: of_action_push_vlan */
    -1,   /* 254: of_action_set_dl_dst */
    -1,   /* 255: of_action_set_dl_src */
    8,    /* 256: of_action_set_field */
    -1,   /* 257: of_action_set_mpls_label */
    -1,   /* 258: of_action_set_mpls_tc */
    8,    /* 259: of_action_set_mpls_ttl */
    -1,   /* 260: of_action_set_nw_dst */
    -1,   /* 261: of_action_set_nw_ecn */
    -1,   /* 262: of_action_set_nw_src */
    -1,   /* 263: of_action_set_nw_tos */
    8,    /* 264: of_action_set_nw_ttl */
    8,    /* 265: of_action_set_queue */
    -1,   /* 266: of_action_set_tp_dst */
    -1,   /* 267: of_action_set_tp_src */
    -1,   /* 268: of_action_set_vlan_pcp */
    -1,   /* 269: of_action_set_vlan_vid */
    -1,   /* 270: of_action_strip_vlan */
    -1,   /* 271: of_async_config_prop */
    -1,   /* 272: of_async_config_prop_experimenter_master */
    -1,   /* 273: of_async_config_prop_experimenter_slave */
    -1,   /* 274: of_async_config_prop_flow_removed_master */
    -1,   /* 275: of_async_config_prop_flow_removed_slave */
    -1,   /* 276: of_async_config_prop_packet_in_master */
    -1,   /* 277: of_async_config_prop_packet_in_slave */
    -1,   /* 278: of_async_config_prop_port_status_master */
    -1,   /* 279: of_async_config_prop_port_status_slave */
    -1,   /* 280: of_async_config_prop_requestforward_master */
    -1,   /* 281: of_async_config_prop_requestforward_slave */
    -1,   /* 282: of_async_config_prop_role_status_master */
    -1,   /* 283: of_async_config_prop_role_status_slave */
    -1,   /* 284: of_async_config_prop_table_status_master */
    -1,   /* 285: of_async_config_prop_table_status_slave */
    -1,   /* 286: of_bsn_controller_connection */
    -1,   /* 287: of_bsn_debug_counter_desc_stats_entry */
    -1,   /* 288: of_bsn_debug_counter_stats_entry */
    -1,   /* 289: of_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 290: of_bsn_generic_stats_entry */
    -1,   /* 291: of_bsn_gentable_bucket_stats_entry */
    -1,   /* 292: of_bsn_gentable_desc_stats_entry */
    -1,   /* 293: of_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 294: of_bsn_gentable_entry_stats_entry */
    -1,   /* 295: of_bsn_gentable_stats_entry */
    32,   /* 296: of_bsn_interface */
    -1,   /* 297: of_bsn_lacp_stats_entry */
    -1,   /* 298: of_bsn_port_counter_stats_entry */
    -1,   /* 299: of_bsn_switch_pipeline_stats_entry */
    -1,   /* 300: of_bsn_table_checksum_stats_entry */
    -1,   /* 301: of_bsn_tlv */
    -1,   /* 302: of_bsn_tlv_actor_key */
    -1,   /* 303: of_bsn_tlv_actor_port_num */
    -1,   /* 304: of_bsn_tlv_actor_port_priority */
    -1,   /* 305: of_bsn_tlv_actor_state */
    -1,   /* 306: of_bsn_tlv_actor_system_mac */
    -1,   /* 307: of_bsn_tlv_actor_system_priority */
    -1,   /* 308: of_bsn_tlv_anchor */
    -1,   /* 309: of_bsn_tlv_apply_bytes */
    -1,   /* 310: of_bsn_tlv_apply_packets */
    -1,   /* 311: of_bsn_tlv_broadcast_query_timeout */
    -1,   /* 312: of_bsn_tlv_broadcast_rate */
    -1,   /* 313: of_bsn_tlv_bucket */
    -1,   /* 314: of_bsn_tlv_circuit_id */
    -1,   /* 315: of_bsn_tlv_convergence_status */
    -1,   /* 316: of_bsn_tlv_cpu_lag */
    -1,   /* 317: of_bsn_tlv_crc_enabled */
    -1,   /* 318: of_bsn_tlv_data */
    -1,   /* 319: of_bsn_tlv_data_mask */
    -1,   /* 320: of_bsn_tlv_decap */
    -1,   /* 321: of_bsn_tlv_disable_src_mac_check */
    -1,   /* 322: of_bsn_tlv_drop */
    -1,   /* 323: of_bsn_tlv_dscp */
    -1,   /* 324: of_bsn_tlv_ecn */
    -1,   /* 325: of_bsn_tlv_egress_only */
    -1,   /* 326: of_bsn_tlv_egress_port_group_id */
    -1,   /* 327: of_bsn_tlv_eth_dst */
    -1,   /* 328: of_bsn_tlv_eth_src */
    -1,   /* 329: of_bsn_tlv_eth_type */
    -1,   /* 330: of_bsn_tlv_external_gateway_ip */
    -1,   /* 331: of_bsn_tlv_external_gateway_mac */
    -1,   /* 332: of_bsn_tlv_external_ip */
    -1,   /* 333: of_bsn_tlv_external_mac */
    -1,   /* 334: of_bsn_tlv_external_netmask */
    -1,   /* 335: of_bsn_tlv_generation_id */
    -1,   /* 336: of_bsn_tlv_hash_gtp_header_match */
    -1,   /* 337: of_bsn_tlv_hash_gtp_port_match */
    -1,   /* 338: of_bsn_tlv_hash_packet_field */
    -1,   /* 339: of_bsn_tlv_hash_packet_type */
    -1,   /* 340: of_bsn_tlv_hash_seed */
    -1,   /* 341: of_bsn_tlv_hash_type */
    -1,   /* 342: of_bsn_tlv_header_size */
    -1,   /* 343: of_bsn_tlv_icmp_code */
    -1,   /* 344: of_bsn_tlv_icmp_id */
    -1,   /* 345: of_bsn_tlv_icmp_type */
    -1,   /* 346: of_bsn_tlv_icmpv6_chksum */
    -1,   /* 347: of_bsn_tlv_idle_notification */
    -1,   /* 348: of_bsn_tlv_idle_time */
    -1,   /* 349: of_bsn_tlv_idle_timeout */
    -1,   /* 350: of_bsn_tlv_igmp_snooping */
    -1,   /* 351: of_bsn_tlv_ingress_port_group_id */
    -1,   /* 352: of_bsn_tlv_internal_gateway_mac */
    -1,   /* 353: of_bsn_tlv_internal_mac */
    -1,   /* 354: of_bsn_tlv_interval */
    -1,   /* 355: of_bsn_tlv_ip_proto */
    -1,   /* 356: of_bsn_tlv_ipv4 */
    -1,   /* 357: of_bsn_tlv_ipv4_dst */
    -1,   /* 358: of_bsn_tlv_ipv4_netmask */
    -1,   /* 359: of_bsn_tlv_ipv4_src */
    -1,   /* 360: of_bsn_tlv_ipv6 */
    -1,   /* 361: of_bsn_tlv_ipv6_dst */
    -1,   /* 362: of_bsn_tlv_ipv6_prefix */
    -1,   /* 363: of_bsn_tlv_ipv6_src */
    -1,   /* 364: of_bsn_tlv_known_multicast_rate */
    -1,   /* 365: of_bsn_tlv_l2_multicast_lookup */
    -1,   /* 366: of_bsn_tlv_l3_dst_class_id */
    -1,   /* 367: of_bsn_tlv_l3_interface_class_id */
    -1,   /* 368: of_bsn_tlv_l3_src_class_id */
    -1,   /* 369: of_bsn_tlv_loopback_port */
    -1,   /* 370: of_bsn_tlv_mac */
    -1,   /* 371: of_bsn_tlv_mac_mask */
    -1,   /* 372: of_bsn_tlv_mcg_type_vxlan */
    -1,   /* 373: of_bsn_tlv_miss_packets */
    -1,   /* 374: of_bsn_tlv_mpls_control_word */
    -1,   /* 375: of_bsn_tlv_mpls_label */
    -1,   /* 376: of_bsn_tlv_mpls_sequenced */
    -1,   /* 377: of_bsn_tlv_multicast_interface_id */
    -1,   /* 378: of_bsn_tlv_name */
    -1,   /* 379: of_bsn_tlv_ndp_offload */
    -1,   /* 380: of_bsn_tlv_ndp_static */
    -1,   /* 381: of_bsn_tlv_negate */
    -1,   /* 382: of_bsn_tlv_next_hop_ipv4 */
    -1,   /* 383: of_bsn_tlv_next_hop_mac */
    -1,   /* 384: of_bsn_tlv_nexthop_type_vxlan */
    -1,   /* 385: of_bsn_tlv_offset */
    -1,   /* 386: of_bsn_tlv_parent_port */
    -1,   /* 387: of_bsn_tlv_partner_key */
    -1,   /* 388: of_bsn_tlv_partner_port_num */
    -1,   /* 389: of_bsn_tlv_partner_port_priority */
    -1,   /* 390: of_bsn_tlv_partner_state */
    -1,   /* 391: of_bsn_tlv_partner_system_mac */
    -1,   /* 392: of_bsn_tlv_partner_system_priority */
    -1,   /* 393: of_bsn_tlv_port */
    -1,   /* 394: of_bsn_tlv_port_usage */
    -1,   /* 395: of_bsn_tlv_port_vxlan_mode */
    -1,   /* 396: of_bsn_tlv_priority */
    -1,   /* 397: of_bsn_tlv_push_vlan_on_ingress */
    -1,   /* 398: of_bsn_tlv_qos_priority */
    -1,   /* 399: of_bsn_tlv_queue_id */
    -1,   /* 400: of_bsn_tlv_queue_weight */
    -1,   /* 401: of_bsn_tlv_rate_limit */
    -1,   /* 402: of_bsn_tlv_rate_unit */
    -1,   /* 403: of_bsn_tlv_reference */
    -1,   /* 404: of_bsn_tlv_reply_packets */
    -1,   /* 405: of_bsn_tlv_request_packets */
    -1,   /* 406: of_bsn_tlv_rx_bytes */
    -1,   /* 407: of_bsn_tlv_rx_packets */
    -1,   /* 408: of_bsn_tlv_sampling_rate */
    -1,   /* 409: of_bsn_tlv_set_loopback_mode */
    -1,   /* 410: of_bsn_tlv_status */
    -1,   /* 411: of_bsn_tlv_strip_mpls_l2_on_ingress */
    -1,   /* 412: of_bsn_tlv_strip_mpls_l3_on_ingress */
    -1,   /* 413: of_bsn_tlv_strip_vlan_on_egress */
    -1,   /* 414: of_bsn_tlv_sub_agent_id */
    -1,   /* 415: of_bsn_tlv_tcp_dst */
    -1,   /* 416: of_bsn_tlv_tcp_flags */
    -1,   /* 417: of_bsn_tlv_tcp_src */
    -1,   /* 418: of_bsn_tlv_ttl */
    -1,   /* 419: of_bsn_tlv_tx_bytes */
    -1,   /* 420: of_bsn_tlv_tx_packets */
    -1,   /* 421: of_bsn_tlv_udf_anchor */
    -1,   /* 422: of_bsn_tlv_udf_id */
    -1,   /* 423: of_bsn_tlv_udf_length */
    -1,   /* 424: of_bsn_tlv_udf_offset */
    -1,   /* 425: of_bsn_tlv_udp_dst */
    -1,   /* 426: of_bsn_tlv_udp_src */
    -1,   /* 427: of_bsn_tlv_uint64_list */
    -1,   /* 428: of_bsn_tlv_unicast_query_timeout */
    -1,   /* 429: of_bsn_tlv_unicast_rate */
    -1,   /* 430: of_bsn_tlv_unknown_multicast_rate */
    -1,   /* 431: of_bsn_tlv_untagged */
    -1,   /* 432: of_bsn_tlv_use_packet_state */
    -1,   /* 433: of_bsn_tlv_vfi */
    -1,   /* 434: of_bsn_tlv_vfp_class_id */
    -1,   /* 435: of_bsn_tlv_vlan_mac_list */
    -1,   /* 436: of_bsn_tlv_vlan_pcp */
    -1,   /* 437: of_bsn_tlv_vlan_vid */
    -1,   /* 438: of_bsn_tlv_vlan_vid_mask */
    -1,   /* 439: of_bsn_tlv_vni */
    -1,   /* 440: of_bsn_tlv_vpn_key */
    -1,   /* 441: of_bsn_tlv_vrf */
    -1,   /* 442: of_bsn_tlv_vxlan_egress_lag */
    -1,   /* 443: of_bsn_vlan_counter_stats_entry */
    -1,   /* 444: of_bsn_vlan_mac */
    4,    /* 445: of_bsn_vport */
    64,   /* 446: of_bsn_vport_l2gre */
    32,   /* 447: of_bsn_vport_q_in_q */
    -1,   /* 448: of_bsn_vrf_counter_stats_entry */
    16,   /* 449: of_bucket */
    16,   /* 450: of_bucket_counter */
    -1,   /* 451: of_bundle_prop */
    -1,   /* 452: of_bundle_prop_experimenter */
    56,   /* 453: of_flow_stats_entry */
    8,    /* 454: of_group_desc_stats_entry */
    32,   /* 455: of_group_stats_entry */
    -1,   /* 456: of_hello_elem */
    -1,   /* 457: of_hello_elem_versionbitmap */
    8,    /* 458: of_instruction */
    8,    /* 459: of_instruction_apply_actions */
    -1,   /* 460: of_instruction_bsn */
    -1,   /* 461: of_instruction_bsn_arp_offload */
    -1,   /* 462: of_instruction_bsn_auto_negotiation */
    -1,   /* 463: of_instruction_bsn_deny */
    -1,   /* 464: of_instruction_bsn_dhcp_offload */
    -1,   /* 465: of_instruction_bsn_disable_l3 */
    -1,   /* 466: of_instruction_bsn_disable_split_horizon_check */
    -1,   /* 467: of_instruction_bsn_disable_src_mac_check */
    -1,   /* 468: of_instruction_bsn_disable_vlan_counters */
    -1,   /* 469: of_instruction_bsn_hash_select */
    -1,   /* 470: of_instruction_bsn_internal_priority */
    -1,   /* 471: of_instruction_bsn_ndp_offload */
    -1,   /* 472: of_instruction_bsn_packet_of_death */
    -1,   /* 473: of_instruction_bsn_permit */
    -1,   /* 474: of_instruction_bsn_prioritize_pdus */
    -1,   /* 475: of_instruction_bsn_require_vlan_xlate */
    -1,   /* 476: of_instruction_bsn_span_destination */
    8,    /* 477: of_instruction_clear_actions */
    8,    /* 478: of_instruction_experimenter */
    8,    /* 479: of_instruction_goto_table */
    -1,   /* 480: of_instruction_id */
    -1,   /* 481: of_instruction_id_apply_actions */
    -1,   /* 482: of_instruction_id_bsn */
    -1,   /* 483: of_instruction_id_bsn_arp_offload */
    -1,   /* 484: of_instruction_id_bsn_auto_negotiation */
    -1,   /* 485: of_instruction_id_bsn_deny */
    -1,   /* 486: of_instruction_id_bsn_dhcp_offload */
    -1,   /* 487: of_instruction_id_bsn_disable_l3 */
    -1,   /* 488: of_instruction_id_bsn_disable_split_horizon_check */
    -1,   /* 489: of_instruction_id_bsn_disable_src_mac_check */
    -1,   /* 490: of_instruction_id_bsn_disable_vlan_counters */
    -1,   /* 491: of_instruction_id_bsn_hash_select */
    -1,   /* 492: of_instruction_id_bsn_internal_priority */
    -1,   /* 493: of_instruction_id_bsn_ndp_offload */
    -1,   /* 494: of_instruction_id_bsn_packet_of_death */
    -1,   /* 495: of_instruction_id_bsn_permit */
    -1,   /* 496: of_instruction_id_bsn_prioritize_pdus */
    -1,   /* 497: of_instruction_id_bsn_require_vlan_xlate */
    -1,   /* 498: of_instruction_id_bsn_span_destination */
    -1,   /* 499: of_instruction_id_clear_actions */
    -1,   /* 500: of_instruction_id_experimenter */
    -1,   /* 501: of_instruction_id_goto_table */
    -1,   /* 502: of_instruction_id_meter */
    -1,   /* 503: of_instruction_id_write_actions */
    -1,   /* 504: of_instruction_id_write_metadata */
    -1,   /* 505: of_instruction_meter */
    8,    /* 506: of_instruction_write_actions */
    24,   /* 507: of_instruction_write_metadata */
    -1,   /* 508: of_match_v1 */
    -1,   /* 509: of_match_v2 */
    4,    /* 510: of_match_v3 */
    -1,   /* 511: of_meter_band */
    -1,   /* 512: of_meter_band_drop */
    -1,   /* 513: of_meter_band_dscp_remark */
    -1,   /* 514: of_meter_band_experimenter */
    -1,   /* 515: of_meter_band_stats */
    -1,   /* 516: of_meter_config */
    -1,   /* 517: of_meter_features */
    -1,   /* 518: of_meter_stats */
    4,    /* 519: of_oxm */
    6,    /* 520: of_oxm_arp_op */
    8,    /* 521: of_oxm_arp_op_masked */
    10,   /* 522: of_oxm_arp_sha */
    16,   /* 523: of_oxm_arp_sha_masked */
    8,    /* 524: of_oxm_arp_spa */
    12,   /* 525: of_oxm_arp_spa_masked */
    10,   /* 526: of_oxm_arp_tha */
    16,   /* 527: of_oxm_arp_tha_masked */
    8,    /* 528: of_oxm_arp_tpa */
    12,   /* 529: of_oxm_arp_tpa_masked */
    8,    /* 530: of_oxm_bsn_egr_port_group_id */
    12,   /* 531: of_oxm_bsn_egr_port_group_id_masked */
    5,    /* 532: of_oxm_bsn_global_vrf_allowed */
    6,    /* 533: of_oxm_bsn_global_vrf_allowed_masked */
    20,   /* 534: of_oxm_bsn_in_ports_128 */
    36,   /* 535: of_oxm_bsn_in_ports_128_masked */
    68,   /* 536: of_oxm_bsn_in_ports_512 */
    132,  /* 537: of_oxm_bsn_in_ports_512_masked */
    8,    /* 538: of_oxm_bsn_ingress_port_group_id */
    12,   /* 539: of_oxm_bsn_ingress_port_group_id_masked */
    -1,   /* 540: of_oxm_bsn_inner_eth_dst */
    -1,   /* 541: of_oxm_bsn_inner_eth_dst_masked */
    -1,   /* 542: of_oxm_bsn_inner_eth_src */
    -1,   /* 543: of_oxm_bsn_inner_eth_src_masked */
    -1,   /* 544: of_oxm_bsn_inner_vlan_vid */
    -1,   /* 545: of_oxm_bsn_inner_vlan_vid_masked */
    5,    /* 546: of_oxm_bsn_ip_fragmentation */
    6,    /* 547: of_oxm_bsn_ip_fragmentation_masked */
    5,    /* 548: of_oxm_bsn_l2_cache_hit */
    6,    /* 549: of_oxm_bsn_l2_cache_hit_masked */
    8,    /* 550: of_oxm_bsn_l3_dst_class_id */
    12,   /* 551: of_oxm_bsn_l3_dst_class_id_masked */
    8,    /* 552: of_oxm_bsn_l3_interface_class_id */
    12,   /* 553: of_oxm_bsn_l3_interface_class_id_masked */
    8,    /* 554: of_oxm_bsn_l3_src_class_id */
    12,   /* 555: of_oxm_bsn_l3_src_class_id_masked */
    8,    /* 556: of_oxm_bsn_lag_id */
    12,   /* 557: of_oxm_bsn_lag_id_masked */
    6,    /* 558: of_oxm_bsn_tcp_flags */
    8,    /* 559: of_oxm_bsn_tcp_flags_masked */
    8,    /* 560: of_oxm_bsn_udf0 */
    12,   /* 561: of_oxm_bsn_udf0_masked */
    8,    /* 562: of_oxm_bsn_udf1 */
    12,   /* 563: of_oxm_bsn_udf1_masked */
    8,    /* 564: of_oxm_bsn_udf2 */
    12,   /* 565: of_oxm_bsn_udf2_masked */
    8,    /* 566: of_oxm_bsn_udf3 */
    12,   /* 567: of_oxm_bsn_udf3_masked */
    8,    /* 568: of_oxm_bsn_udf4 */
    12,   /* 569: of_oxm_bsn_udf4_masked */
    8,    /* 570: of_oxm_bsn_udf5 */
    12,   /* 571: of_oxm_bsn_udf5_masked */
    8,    /* 572: of_oxm_bsn_udf6 */
    12,   /* 573: of_oxm_bsn_udf6_masked */
    8,    /* 574: of_oxm_bsn_udf7 */
    12,   /* 575: of_oxm_bsn_udf7_masked */
    -1,   /* 576: of_oxm_bsn_vfi */
    -1,   /* 577: of_oxm_bsn_vfi_masked */
    8,    /* 578: of_oxm_bsn_vlan_xlate_port_group_id */
    12,   /* 579: of_oxm_bsn_vlan_xlate_port_group_id_masked */
    8,    /* 580: of_oxm_bsn_vrf */
    12,   /* 581: of_oxm_bsn_vrf_masked */
    -1,   /* 582: of_oxm_bsn_vxlan_network_id */
    -1,   /* 583: of_oxm_bsn_vxlan_network_id_masked */
    10,   /* 584: of_oxm_eth_dst */
    16,   /* 585: of_oxm_eth_dst_masked */
    10,   /* 586: of_oxm_eth_src */
    16,   /* 587: of_oxm_eth_src_masked */
    6,    /* 588: of_oxm_eth_type */
    8,    /* 589: of_oxm_eth_type_masked */
    5,    /* 590: of_oxm_icmpv4_code */
    6,    /* 591: of_oxm_icmpv4_code_masked */
    5,    /* 592: of_oxm_icmpv4_type */
    6,    /* 593: of_oxm_icmpv4_type_masked */
    5,    /* 594: of_oxm_icmpv6_code */
    6,    /* 595: of_oxm_icmpv6_code_masked */
    5,    /* 596: of_oxm_icmpv6_type */
    6,    /* 597: of_oxm_icmpv6_type_masked */
    8,    /* 598: of_oxm_in_phy_port */
    12,   /* 599: of_oxm_in_phy_port_masked */
    8,    /* 600: of_oxm_in_port */
    12,   /* 601: of_oxm_in_port_masked */
    5,    /* 602: of_oxm_ip_dscp */
    6,    /* 603: of_oxm_ip_dscp_masked */
    5,    /* 604: of_oxm_ip_ecn */
    6,    /* 605: of_oxm_ip_ecn_masked */
    5,    /* 606: of_oxm_ip_proto */
    6,    /* 607: of_oxm_ip_proto_masked */
    8,    /* 608: of_oxm_ipv4_dst */
    12,   /* 609: of_oxm_ipv4_dst_masked */
    8,    /* 610: of_oxm_ipv4_src */
    12,   /* 611: of_oxm_ipv4_src_masked */
    20,   /* 612: of_oxm_ipv6_dst */
    36,   /* 613: of_oxm_ipv6_dst_masked */
    -1,   /* 614: of_oxm_ipv6_exthdr */
    -1,   /* 615: of_oxm_ipv6_exthdr_masked */
    8,    /* 616: of_oxm_ipv6_flabel */
    12,   /* 617: of_oxm_ipv6_flabel_masked */
    10,   /* 618: of_oxm_ipv6_nd_sll */
    16,   /* 619: of_oxm_ipv6_nd_sll_masked */
    20,   /* 620: of_oxm_ipv6_nd_target */
    36,   /* 621: of_oxm_ipv6_nd_target_masked */
    10,   /* 622: of_oxm_ipv6_nd_tll */
    16,   /* 623: of_oxm_ipv6_nd_tll_masked */
    20,   /* 624: of_oxm_ipv6_src */
    36,   /* 625: of_oxm_ipv6_src_masked */
    12,   /* 626: of_oxm_metadata */
    20,   /* 627: of_oxm_metadata_masked */
    -1,   /* 628: of_oxm_mpls_bos */
    -1,   /* 629: of_oxm_mpls_bos_masked */
    8,    /* 630: of_oxm_mpls_label */
    12,   /* 631: of_oxm_mpls_label_masked */
    5,    /* 632: of_oxm_mpls_tc */
    6,    /* 633: of_oxm_mpls_tc_masked */
    10,   /* 634: of_oxm_ovs_tcp_flags */
    12,   /* 635: of_oxm_ovs_tcp_flags_masked */
    -1,   /* 636: of_oxm_pbb_uca */
    -1,   /* 637: of_oxm_pbb_uca_masked */
    6,    /* 638: of_oxm_sctp_dst */
    8,    /* 639: of_oxm_sctp_dst_masked */
    6,    /* 640: of_oxm_sctp_src */
    8,    /* 641: of_oxm_sctp_src_masked */
    6,    /* 642: of_oxm_tcp_dst */
    8,    /* 643: of_oxm_tcp_dst_masked */
    6,    /* 644: of_oxm_tcp_src */
    8,    /* 645: of_oxm_tcp_src_masked */
    -1,   /* 646: of_oxm_tunnel_id */
    -1,   /* 647: of_oxm_tunnel_id_masked */
    8,    /* 648: of_oxm_tunnel_ipv4_dst */
    12,   /* 649: of_oxm_tunnel_ipv4_dst_masked */
    8,    /* 650: of_oxm_tunnel_ipv4_src */
    12,   /* 651: of_oxm_tunnel_ipv4_src_masked */
    6,    /* 652: of_oxm_udp_dst */
    8,    /* 653: of_oxm_udp_dst_masked */
    6,    /* 654: of_oxm_udp_src */
    8,    /* 655: of_oxm_udp_src_masked */
    5,    /* 656: of_oxm_vlan_pcp */
    6,    /* 657: of_oxm_vlan_pcp_masked */
    6,    /* 658: of_oxm_vlan_vid */
    8,    /* 659: of_oxm_vlan_vid_masked */
    16,   /* 660: of_packet_queue */
    64,   /* 661: of_port_desc */
    -1,   /* 662: of_port_desc_prop */
    -1,   /* 663: of_port_desc_prop_bsn */
    -1,   /* 664: of_port_desc_prop_bsn_generation_id */
    -1,   /* 665: of_port_desc_prop_bsn_uplink */
    -1,   /* 666: of_port_desc_prop_ethernet */
    -1,   /* 667: of_port_desc_prop_experimenter */
    -1,   /* 668: of_port_desc_prop_optical */
    -1,   /* 669: of_port_mod_prop */
    -1,   /* 670: of_port_mod_prop_ethernet */
    -1,   /* 671: of_port_mod_prop_experimenter */
    -1,   /* 672: of_port_mod_prop_optical */
    104,  /* 673: of_port_stats_entry */
    -1,   /* 674: of_port_stats_prop */
    -1,   /* 675: of_port_stats_prop_ethernet */
    -1,   /* 676: of_port_stats_prop_experimenter */
    -1,   /* 677: of_port_stats_prop_optical */
    -1,   /* 678: of_queue_desc */
    -1,   /* 679: of_queue_desc_prop */
    -1,   /* 680: of_queue_desc_prop_bsn */
    -1,   /* 681: of_queue_desc_prop_bsn_queue_name */
    -1,   /* 682: of_queue_desc_prop_experimenter */
    -1,   /* 683: of_queue_desc_prop_max_rate */
    -1,   /* 684: of_queue_desc_prop_min_rate */
    8,    /* 685: of_queue_prop */
    16,   /* 686: of_queue_prop_experimenter */
    16,   /* 687: of_queue_prop_max_rate */
    16,   /* 688: of_queue_prop_min_rate */
    32,   /* 689: of_queue_stats_entry */
    -1,   /* 690: of_queue_stats_prop */
    -1,   /* 691: of_queue_stats_prop_experimenter */
    -1,   /* 692: of_role_prop */
    -1,   /* 693: of_role_prop_experimenter */
    -1,   /* 694: of_table_desc */
    -1,   /* 695: of_table_feature_prop */
    -1,   /* 696: of_table_feature_prop_apply_actions */
    -1,   /* 697: of_table_feature_prop_apply_actions_miss */
    -1,   /* 698: of_table_feature_prop_apply_setfield */
    -1,   /* 699: of_table_feature_prop_apply_setfield_miss */
    -1,   /* 700: of_table_feature_prop_experimenter */
    -1,   /* 701: of_table_feature_prop_experimenter_miss */
    -1,   /* 702: of_table_feature_prop_instructions */
    -1,   /* 703: of_table_feature_prop_instructions_miss */
    -1,   /* 704: of_table_feature_prop_match */
    -1,   /* 705: of_table_feature_prop_next_tables */
    -1,   /* 706: of_table_feature_prop_next_tables_miss */
    -1,   /* 707: of_table_feature_prop_table_sync_from */
    -1,   /* 708: of_table_feature_prop_wildcards */
    -1,   /* 709: of_table_feature_prop_write_actions */
    -1,   /* 710: of_table_feature_prop_write_actions_miss */
    -1,   /* 711: of_table_feature_prop_write_setfield */
    -1,   /* 712: of_table_feature_prop_write_setfield_miss */
    -1,   /* 713: of_table_features */
    -1,   /* 714: of_table_mod_prop */
    -1,   /* 715: of_table_mod_prop_eviction */
    -1,   /* 716: of_table_mod_prop_experimenter */
    -1,   /* 717: of_table_mod_prop_vacancy */
    128,  /* 718: of_table_stats_entry */
    -1,   /* 719: of_uint32 */
    -1,   /* 720: of_uint64 */
    -1,   /* 721: of_uint8 */
    0,    /* 722: of_list_action */
    -1,   /* 723: of_list_action_id */
    -1,   /* 724: of_list_async_config_prop */
    -1,   /* 725: of_list_bsn_controller_connection */
    -1,   /* 726: of_list_bsn_debug_counter_desc_stats_entry */
    -1,   /* 727: of_list_bsn_debug_counter_stats_entry */
    -1,   /* 728: of_list_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 729: of_list_bsn_generic_stats_entry */
    -1,   /* 730: of_list_bsn_gentable_bucket_stats_entry */
    -1,   /* 731: of_list_bsn_gentable_desc_stats_entry */
    -1,   /* 732: of_list_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 733: of_list_bsn_gentable_entry_stats_entry */
    -1,   /* 734: of_list_bsn_gentable_stats_entry */
    0,    /* 735: of_list_bsn_interface */
    -1,   /* 736: of_list_bsn_lacp_stats_entry */
    -1,   /* 737: of_list_bsn_port_counter_stats_entry */
    -1,   /* 738: of_list_bsn_switch_pipeline_stats_entry */
    -1,   /* 739: of_list_bsn_table_checksum_stats_entry */
    -1,   /* 740: of_list_bsn_tlv */
    -1,   /* 741: of_list_bsn_vlan_counter_stats_entry */
    -1,   /* 742: of_list_bsn_vlan_mac */
    -1,   /* 743: of_list_bsn_vrf_counter_stats_entry */
    0,    /* 744: of_list_bucket */
    0,    /* 745: of_list_bucket_counter */
    -1,   /* 746: of_list_bundle_prop */
    0,    /* 747: of_list_flow_stats_entry */
    0,    /* 748: of_list_group_desc_stats_entry */
    0,    /* 749: of_list_group_stats_entry */
    -1,   /* 750: of_list_hello_elem */
    0,    /* 751: of_list_instruction */
    -1,   /* 752: of_list_instruction_id */
    -1,   /* 753: of_list_meter_band */
    -1,   /* 754: of_list_meter_band_stats */
    -1,   /* 755: of_list_meter_config */
    -1,   /* 756: of_list_meter_stats */
    0,    /* 757: of_list_oxm */
    0,    /* 758: of_list_packet_queue */
    0,    /* 759: of_list_port_desc */
    -1,   /* 760: of_list_port_desc_prop */
    -1,   /* 761: of_list_port_mod_prop */
    0,    /* 762: of_list_port_stats_entry */
    -1,   /* 763: of_list_port_stats_prop */
    -1,   /* 764: of_list_queue_desc */
    -1,   /* 765: of_list_queue_desc_prop */
    0,    /* 766: of_list_queue_prop */
    0,    /* 767: of_list_queue_stats_entry */
    -1,   /* 768: of_list_queue_stats_prop */
    -1,   /* 769: of_list_role_prop */
    -1,   /* 770: of_list_table_desc */
    -1,   /* 771: of_list_table_feature_prop */
    -1,   /* 772: of_list_table_features */
    -1,   /* 773: of_list_table_mod_prop */
    0,    /* 774: of_list_table_stats_entry */
    -1,   /* 775: of_list_uint32 */
    -1,   /* 776: of_list_uint64 */
    -1    /* 777: of_list_uint8 */
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
    272,  /* 15: of_bsn_base_error */
    20,   /* 16: of_bsn_bw_clear_data_reply */
    16,   /* 17: of_bsn_bw_clear_data_request */
    20,   /* 18: of_bsn_bw_enable_get_reply */
    16,   /* 19: of_bsn_bw_enable_get_request */
    24,   /* 20: of_bsn_bw_enable_set_reply */
    20,   /* 21: of_bsn_bw_enable_set_request */
    16,   /* 22: of_bsn_controller_connections_reply */
    16,   /* 23: of_bsn_controller_connections_request */
    24,   /* 24: of_bsn_debug_counter_desc_stats_reply */
    24,   /* 25: of_bsn_debug_counter_desc_stats_request */
    24,   /* 26: of_bsn_debug_counter_stats_reply */
    24,   /* 27: of_bsn_debug_counter_stats_request */
    272,  /* 28: of_bsn_error */
    24,   /* 29: of_bsn_flow_checksum_bucket_stats_reply */
    25,   /* 30: of_bsn_flow_checksum_bucket_stats_request */
    40,   /* 31: of_bsn_flow_idle */
    20,   /* 32: of_bsn_flow_idle_enable_get_reply */
    16,   /* 33: of_bsn_flow_idle_enable_get_request */
    24,   /* 34: of_bsn_flow_idle_enable_set_reply */
    20,   /* 35: of_bsn_flow_idle_enable_set_request */
    -1,   /* 36: of_bsn_generic_async */
    -1,   /* 37: of_bsn_generic_command */
    24,   /* 38: of_bsn_generic_stats_reply */
    88,   /* 39: of_bsn_generic_stats_request */
    24,   /* 40: of_bsn_gentable_bucket_stats_reply */
    26,   /* 41: of_bsn_gentable_bucket_stats_request */
    28,   /* 42: of_bsn_gentable_clear_reply */
    52,   /* 43: of_bsn_gentable_clear_request */
    24,   /* 44: of_bsn_gentable_desc_stats_reply */
    24,   /* 45: of_bsn_gentable_desc_stats_request */
    36,   /* 46: of_bsn_gentable_entry_add */
    18,   /* 47: of_bsn_gentable_entry_delete */
    24,   /* 48: of_bsn_gentable_entry_desc_stats_reply */
    60,   /* 49: of_bsn_gentable_entry_desc_stats_request */
    24,   /* 50: of_bsn_gentable_entry_stats_reply */
    60,   /* 51: of_bsn_gentable_entry_stats_request */
    24,   /* 52: of_bsn_gentable_set_buckets_size */
    24,   /* 53: of_bsn_gentable_stats_reply */
    24,   /* 54: of_bsn_gentable_stats_request */
    16,   /* 55: of_bsn_get_interfaces_reply */
    16,   /* 56: of_bsn_get_interfaces_request */
    -1,   /* 57: of_bsn_get_ip_mask_reply */
    -1,   /* 58: of_bsn_get_ip_mask_request */
    -1,   /* 59: of_bsn_get_l2_table_reply */
    -1,   /* 60: of_bsn_get_l2_table_request */
    20,   /* 61: of_bsn_get_mirroring_reply */
    20,   /* 62: of_bsn_get_mirroring_request */
    272,  /* 63: of_bsn_get_switch_pipeline_reply */
    16,   /* 64: of_bsn_get_switch_pipeline_request */
    16,   /* 65: of_bsn_header */
    -1,   /* 66: of_bsn_hybrid_get_reply */
    -1,   /* 67: of_bsn_hybrid_get_request */
    536,  /* 68: of_bsn_image_desc_stats_reply */
    24,   /* 69: of_bsn_image_desc_stats_request */
    52,   /* 70: of_bsn_lacp_convergence_notif */
    24,   /* 71: of_bsn_lacp_stats_reply */
    24,   /* 72: of_bsn_lacp_stats_request */
    17,   /* 73: of_bsn_log */
    16,   /* 74: of_bsn_lua_command_reply */
    16,   /* 75: of_bsn_lua_command_request */
    16,   /* 76: of_bsn_lua_notification */
    82,   /* 77: of_bsn_lua_upload */
    25,   /* 78: of_bsn_pdu_rx_reply */
    28,   /* 79: of_bsn_pdu_rx_request */
    21,   /* 80: of_bsn_pdu_rx_timeout */
    25,   /* 81: of_bsn_pdu_tx_reply */
    28,   /* 82: of_bsn_pdu_tx_request */
    24,   /* 83: of_bsn_port_counter_stats_reply */
    28,   /* 84: of_bsn_port_counter_stats_request */
    32,   /* 85: of_bsn_role_status */
    24,   /* 86: of_bsn_set_aux_cxns_reply */
    20,   /* 87: of_bsn_set_aux_cxns_request */
    -1,   /* 88: of_bsn_set_ip_mask */
    -1,   /* 89: of_bsn_set_l2_table_reply */
    -1,   /* 90: of_bsn_set_l2_table_request */
    24,   /* 91: of_bsn_set_lacp_reply */
    38,   /* 92: of_bsn_set_lacp_request */
    20,   /* 93: of_bsn_set_mirroring */
    20,   /* 94: of_bsn_set_pktin_suppression_reply */
    32,   /* 95: of_bsn_set_pktin_suppression_request */
    20,   /* 96: of_bsn_set_switch_pipeline_reply */
    272,  /* 97: of_bsn_set_switch_pipeline_request */
    -1,   /* 98: of_bsn_shell_command */
    -1,   /* 99: of_bsn_shell_output */
    -1,   /* 100: of_bsn_shell_status */
    24,   /* 101: of_bsn_stats_reply */
    24,   /* 102: of_bsn_stats_request */
    24,   /* 103: of_bsn_switch_pipeline_stats_reply */
    24,   /* 104: of_bsn_switch_pipeline_stats_request */
    24,   /* 105: of_bsn_table_checksum_stats_reply */
    24,   /* 106: of_bsn_table_checksum_stats_request */
    24,   /* 107: of_bsn_table_set_buckets_size */
    -1,   /* 108: of_bsn_takeover */
    24,   /* 109: of_bsn_time_reply */
    16,   /* 110: of_bsn_time_request */
    24,   /* 111: of_bsn_virtual_port_create_reply */
    20,   /* 112: of_bsn_virtual_port_create_request */
    20,   /* 113: of_bsn_virtual_port_remove_reply */
    20,   /* 114: of_bsn_virtual_port_remove_request */
    18,   /* 115: of_bsn_vlan_counter_clear */
    24,   /* 116: of_bsn_vlan_counter_stats_reply */
    26,   /* 117: of_bsn_vlan_counter_stats_request */
    24,   /* 118: of_bsn_vrf_counter_stats_reply */
    28,   /* 119: of_bsn_vrf_counter_stats_request */
    -1,   /* 120: of_bundle_add_msg */
    -1,   /* 121: of_bundle_ctrl_msg */
    -1,   /* 122: of_bundle_failed_error_msg */
    1072, /* 123: of_desc_stats_reply */
    16,   /* 124: of_desc_stats_request */
    8,    /* 125: of_echo_reply */
    8,    /* 126: of_echo_request */
    10,   /* 127: of_error_msg */
    16,   /* 128: of_experimenter */
    16,   /* 129: of_experimenter_error_msg */
    24,   /* 130: of_experimenter_stats_reply */
    24,   /* 131: of_experimenter_stats_request */
    32,   /* 132: of_features_reply */
    8,    /* 133: of_features_request */
    56,   /* 134: of_flow_add */
    56,   /* 135: of_flow_delete */
    56,   /* 136: of_flow_delete_strict */
    56,   /* 137: of_flow_mod */
    12,   /* 138: of_flow_mod_failed_error_msg */
    56,   /* 139: of_flow_modify */
    56,   /* 140: of_flow_modify_strict */
    -1,   /* 141: of_flow_monitor_failed_error_msg */
    56,   /* 142: of_flow_removed */
    16,   /* 143: of_flow_stats_reply */
    56,   /* 144: of_flow_stats_request */
    12,   /* 145: of_get_config_reply */
    8,    /* 146: of_get_config_request */
    16,   /* 147: of_group_add */
    16,   /* 148: of_group_delete */
    16,   /* 149: of_group_desc_stats_reply */
    16,   /* 150: of_group_desc_stats_request */
    56,   /* 151: of_group_features_stats_reply */
    16,   /* 152: of_group_features_stats_request */
    16,   /* 153: of_group_mod */
    12,   /* 154: of_group_mod_failed_error_msg */
    16,   /* 155: of_group_modify */
    16,   /* 156: of_group_stats_reply */
    24,   /* 157: of_group_stats_request */
    8,    /* 158: of_header */
    8,    /* 159: of_hello */
    12,   /* 160: of_hello_failed_error_msg */
    16,   /* 161: of_meter_config_stats_reply */
    24,   /* 162: of_meter_config_stats_request */
    32,   /* 163: of_meter_features_stats_reply */
    16,   /* 164: of_meter_features_stats_request */
    16,   /* 165: of_meter_mod */
    12,   /* 166: of_meter_mod_failed_error_msg */
    16,   /* 167: of_meter_stats_reply */
    24,   /* 168: of_meter_stats_request */
    -1,   /* 169: of_nicira_controller_role_reply */
    -1,   /* 170: of_nicira_controller_role_request */
    16,   /* 171: of_nicira_header */
    34,   /* 172: of_packet_in */
    24,   /* 173: of_packet_out */
    16,   /* 174: of_port_desc_stats_reply */
    16,   /* 175: of_port_desc_stats_request */
    40,   /* 176: of_port_mod */
    12,   /* 177: of_port_mod_failed_error_msg */
    16,   /* 178: of_port_stats_reply */
    24,   /* 179: of_port_stats_request */
    80,   /* 180: of_port_status */
    -1,   /* 181: of_queue_desc_stats_reply */
    -1,   /* 182: of_queue_desc_stats_request */
    16,   /* 183: of_queue_get_config_reply */
    16,   /* 184: of_queue_get_config_request */
    12,   /* 185: of_queue_op_failed_error_msg */
    16,   /* 186: of_queue_stats_reply */
    24,   /* 187: of_queue_stats_request */
    -1,   /* 188: of_requestforward */
    24,   /* 189: of_role_reply */
    24,   /* 190: of_role_request */
    12,   /* 191: of_role_request_failed_error_msg */
    -1,   /* 192: of_role_status */
    12,   /* 193: of_set_config */
    16,   /* 194: of_stats_reply */
    16,   /* 195: of_stats_request */
    12,   /* 196: of_switch_config_failed_error_msg */
    -1,   /* 197: of_table_desc_stats_reply */
    -1,   /* 198: of_table_desc_stats_request */
    12,   /* 199: of_table_features_failed_error_msg */
    16,   /* 200: of_table_features_stats_reply */
    16,   /* 201: of_table_features_stats_request */
    16,   /* 202: of_table_mod */
    12,   /* 203: of_table_mod_failed_error_msg */
    16,   /* 204: of_table_stats_reply */
    16,   /* 205: of_table_stats_request */
    -1,   /* 206: of_table_status */
    8,    /* 207: of_action */
    16,   /* 208: of_action_bsn */
    28,   /* 209: of_action_bsn_checksum */
    16,   /* 210: of_action_bsn_gentable */
    24,   /* 211: of_action_bsn_mirror */
    16,   /* 212: of_action_bsn_set_tunnel_dst */
    8,    /* 213: of_action_copy_ttl_in */
    8,    /* 214: of_action_copy_ttl_out */
    8,    /* 215: of_action_dec_mpls_ttl */
    8,    /* 216: of_action_dec_nw_ttl */
    -1,   /* 217: of_action_enqueue */
    8,    /* 218: of_action_experimenter */
    8,    /* 219: of_action_group */
    4,    /* 220: of_action_id */
    12,   /* 221: of_action_id_bsn */
    12,   /* 222: of_action_id_bsn_checksum */
    12,   /* 223: of_action_id_bsn_gentable */
    12,   /* 224: of_action_id_bsn_mirror */
    12,   /* 225: of_action_id_bsn_set_tunnel_dst */
    4,    /* 226: of_action_id_copy_ttl_in */
    4,    /* 227: of_action_id_copy_ttl_out */
    4,    /* 228: of_action_id_dec_mpls_ttl */
    4,    /* 229: of_action_id_dec_nw_ttl */
    8,    /* 230: of_action_id_experimenter */
    4,    /* 231: of_action_id_group */
    10,   /* 232: of_action_id_nicira */
    10,   /* 233: of_action_id_nicira_dec_ttl */
    4,    /* 234: of_action_id_output */
    4,    /* 235: of_action_id_pop_mpls */
    4,    /* 236: of_action_id_pop_pbb */
    4,    /* 237: of_action_id_pop_vlan */
    4,    /* 238: of_action_id_push_mpls */
    4,    /* 239: of_action_id_push_pbb */
    4,    /* 240: of_action_id_push_vlan */
    4,    /* 241: of_action_id_set_field */
    4,    /* 242: of_action_id_set_mpls_ttl */
    4,    /* 243: of_action_id_set_nw_ttl */
    4,    /* 244: of_action_id_set_queue */
    16,   /* 245: of_action_nicira */
    16,   /* 246: of_action_nicira_dec_ttl */
    16,   /* 247: of_action_output */
    8,    /* 248: of_action_pop_mpls */
    8,    /* 249: of_action_pop_pbb */
    8,    /* 250: of_action_pop_vlan */
    8,    /* 251: of_action_push_mpls */
    8,    /* 252: of_action_push_pbb */
    8,    /* 253: of_action_push_vlan */
    -1,   /* 254: of_action_set_dl_dst */
    -1,   /* 255: of_action_set_dl_src */
    8,    /* 256: of_action_set_field */
    -1,   /* 257: of_action_set_mpls_label */
    -1,   /* 258: of_action_set_mpls_tc */
    8,    /* 259: of_action_set_mpls_ttl */
    -1,   /* 260: of_action_set_nw_dst */
    -1,   /* 261: of_action_set_nw_ecn */
    -1,   /* 262: of_action_set_nw_src */
    -1,   /* 263: of_action_set_nw_tos */
    8,    /* 264: of_action_set_nw_ttl */
    8,    /* 265: of_action_set_queue */
    -1,   /* 266: of_action_set_tp_dst */
    -1,   /* 267: of_action_set_tp_src */
    -1,   /* 268: of_action_set_vlan_pcp */
    -1,   /* 269: of_action_set_vlan_vid */
    -1,   /* 270: of_action_strip_vlan */
    -1,   /* 271: of_async_config_prop */
    -1,   /* 272: of_async_config_prop_experimenter_master */
    -1,   /* 273: of_async_config_prop_experimenter_slave */
    -1,   /* 274: of_async_config_prop_flow_removed_master */
    -1,   /* 275: of_async_config_prop_flow_removed_slave */
    -1,   /* 276: of_async_config_prop_packet_in_master */
    -1,   /* 277: of_async_config_prop_packet_in_slave */
    -1,   /* 278: of_async_config_prop_port_status_master */
    -1,   /* 279: of_async_config_prop_port_status_slave */
    -1,   /* 280: of_async_config_prop_requestforward_master */
    -1,   /* 281: of_async_config_prop_requestforward_slave */
    -1,   /* 282: of_async_config_prop_role_status_master */
    -1,   /* 283: of_async_config_prop_role_status_slave */
    -1,   /* 284: of_async_config_prop_table_status_master */
    -1,   /* 285: of_async_config_prop_table_status_slave */
    264,  /* 286: of_bsn_controller_connection */
    328,  /* 287: of_bsn_debug_counter_desc_stats_entry */
    16,   /* 288: of_bsn_debug_counter_stats_entry */
    8,    /* 289: of_bsn_flow_checksum_bucket_stats_entry */
    2,    /* 290: of_bsn_generic_stats_entry */
    16,   /* 291: of_bsn_gentable_bucket_stats_entry */
    48,   /* 292: of_bsn_gentable_desc_stats_entry */
    20,   /* 293: of_bsn_gentable_entry_desc_stats_entry */
    4,    /* 294: of_bsn_gentable_entry_stats_entry */
    24,   /* 295: of_bsn_gentable_stats_entry */
    32,   /* 296: of_bsn_interface */
    36,   /* 297: of_bsn_lacp_stats_entry */
    8,    /* 298: of_bsn_port_counter_stats_entry */
    256,  /* 299: of_bsn_switch_pipeline_stats_entry */
    9,    /* 300: of_bsn_table_checksum_stats_entry */
    4,    /* 301: of_bsn_tlv */
    6,    /* 302: of_bsn_tlv_actor_key */
    6,    /* 303: of_bsn_tlv_actor_port_num */
    6,    /* 304: of_bsn_tlv_actor_port_priority */
    5,    /* 305: of_bsn_tlv_actor_state */
    10,   /* 306: of_bsn_tlv_actor_system_mac */
    6,    /* 307: of_bsn_tlv_actor_system_priority */
    6,    /* 308: of_bsn_tlv_anchor */
    12,   /* 309: of_bsn_tlv_apply_bytes */
    12,   /* 310: of_bsn_tlv_apply_packets */
    8,    /* 311: of_bsn_tlv_broadcast_query_timeout */
    8,    /* 312: of_bsn_tlv_broadcast_rate */
    4,    /* 313: of_bsn_tlv_bucket */
    4,    /* 314: of_bsn_tlv_circuit_id */
    5,    /* 315: of_bsn_tlv_convergence_status */
    4,    /* 316: of_bsn_tlv_cpu_lag */
    5,    /* 317: of_bsn_tlv_crc_enabled */
    4,    /* 318: of_bsn_tlv_data */
    4,    /* 319: of_bsn_tlv_data_mask */
    6,    /* 320: of_bsn_tlv_decap */
    4,    /* 321: of_bsn_tlv_disable_src_mac_check */
    4,    /* 322: of_bsn_tlv_drop */
    6,    /* 323: of_bsn_tlv_dscp */
    5,    /* 324: of_bsn_tlv_ecn */
    4,    /* 325: of_bsn_tlv_egress_only */
    8,    /* 326: of_bsn_tlv_egress_port_group_id */
    10,   /* 327: of_bsn_tlv_eth_dst */
    10,   /* 328: of_bsn_tlv_eth_src */
    6,    /* 329: of_bsn_tlv_eth_type */
    8,    /* 330: of_bsn_tlv_external_gateway_ip */
    10,   /* 331: of_bsn_tlv_external_gateway_mac */
    8,    /* 332: of_bsn_tlv_external_ip */
    10,   /* 333: of_bsn_tlv_external_mac */
    8,    /* 334: of_bsn_tlv_external_netmask */
    12,   /* 335: of_bsn_tlv_generation_id */
    6,    /* 336: of_bsn_tlv_hash_gtp_header_match */
    9,    /* 337: of_bsn_tlv_hash_gtp_port_match */
    12,   /* 338: of_bsn_tlv_hash_packet_field */
    5,    /* 339: of_bsn_tlv_hash_packet_type */
    12,   /* 340: of_bsn_tlv_hash_seed */
    5,    /* 341: of_bsn_tlv_hash_type */
    8,    /* 342: of_bsn_tlv_header_size */
    5,    /* 343: of_bsn_tlv_icmp_code */
    6,    /* 344: of_bsn_tlv_icmp_id */
    5,    /* 345: of_bsn_tlv_icmp_type */
    6,    /* 346: of_bsn_tlv_icmpv6_chksum */
    4,    /* 347: of_bsn_tlv_idle_notification */
    12,   /* 348: of_bsn_tlv_idle_time */
    8,    /* 349: of_bsn_tlv_idle_timeout */
    4,    /* 350: of_bsn_tlv_igmp_snooping */
    8,    /* 351: of_bsn_tlv_ingress_port_group_id */
    10,   /* 352: of_bsn_tlv_internal_gateway_mac */
    10,   /* 353: of_bsn_tlv_internal_mac */
    8,    /* 354: of_bsn_tlv_interval */
    5,    /* 355: of_bsn_tlv_ip_proto */
    8,    /* 356: of_bsn_tlv_ipv4 */
    8,    /* 357: of_bsn_tlv_ipv4_dst */
    8,    /* 358: of_bsn_tlv_ipv4_netmask */
    8,    /* 359: of_bsn_tlv_ipv4_src */
    20,   /* 360: of_bsn_tlv_ipv6 */
    20,   /* 361: of_bsn_tlv_ipv6_dst */
    21,   /* 362: of_bsn_tlv_ipv6_prefix */
    20,   /* 363: of_bsn_tlv_ipv6_src */
    8,    /* 364: of_bsn_tlv_known_multicast_rate */
    4,    /* 365: of_bsn_tlv_l2_multicast_lookup */
    8,    /* 366: of_bsn_tlv_l3_dst_class_id */
    8,    /* 367: of_bsn_tlv_l3_interface_class_id */
    8,    /* 368: of_bsn_tlv_l3_src_class_id */
    8,    /* 369: of_bsn_tlv_loopback_port */
    10,   /* 370: of_bsn_tlv_mac */
    10,   /* 371: of_bsn_tlv_mac_mask */
    4,    /* 372: of_bsn_tlv_mcg_type_vxlan */
    12,   /* 373: of_bsn_tlv_miss_packets */
    5,    /* 374: of_bsn_tlv_mpls_control_word */
    8,    /* 375: of_bsn_tlv_mpls_label */
    5,    /* 376: of_bsn_tlv_mpls_sequenced */
    8,    /* 377: of_bsn_tlv_multicast_interface_id */
    4,    /* 378: of_bsn_tlv_name */
    4,    /* 379: of_bsn_tlv_ndp_offload */
    4,    /* 380: of_bsn_tlv_ndp_static */
    4,    /* 381: of_bsn_tlv_negate */
    8,    /* 382: of_bsn_tlv_next_hop_ipv4 */
    10,   /* 383: of_bsn_tlv_next_hop_mac */
    4,    /* 384: of_bsn_tlv_nexthop_type_vxlan */
    6,    /* 385: of_bsn_tlv_offset */
    8,    /* 386: of_bsn_tlv_parent_port */
    6,    /* 387: of_bsn_tlv_partner_key */
    6,    /* 388: of_bsn_tlv_partner_port_num */
    6,    /* 389: of_bsn_tlv_partner_port_priority */
    5,    /* 390: of_bsn_tlv_partner_state */
    10,   /* 391: of_bsn_tlv_partner_system_mac */
    6,    /* 392: of_bsn_tlv_partner_system_priority */
    8,    /* 393: of_bsn_tlv_port */
    6,    /* 394: of_bsn_tlv_port_usage */
    5,    /* 395: of_bsn_tlv_port_vxlan_mode */
    8,    /* 396: of_bsn_tlv_priority */
    4,    /* 397: of_bsn_tlv_push_vlan_on_ingress */
    8,    /* 398: of_bsn_tlv_qos_priority */
    8,    /* 399: of_bsn_tlv_queue_id */
    8,    /* 400: of_bsn_tlv_queue_weight */
    8,    /* 401: of_bsn_tlv_rate_limit */
    5,    /* 402: of_bsn_tlv_rate_unit */
    6,    /* 403: of_bsn_tlv_reference */
    12,   /* 404: of_bsn_tlv_reply_packets */
    12,   /* 405: of_bsn_tlv_request_packets */
    12,   /* 406: of_bsn_tlv_rx_bytes */
    12,   /* 407: of_bsn_tlv_rx_packets */
    8,    /* 408: of_bsn_tlv_sampling_rate */
    4,    /* 409: of_bsn_tlv_set_loopback_mode */
    5,    /* 410: of_bsn_tlv_status */
    4,    /* 411: of_bsn_tlv_strip_mpls_l2_on_ingress */
    4,    /* 412: of_bsn_tlv_strip_mpls_l3_on_ingress */
    4,    /* 413: of_bsn_tlv_strip_vlan_on_egress */
    8,    /* 414: of_bsn_tlv_sub_agent_id */
    6,    /* 415: of_bsn_tlv_tcp_dst */
    6,    /* 416: of_bsn_tlv_tcp_flags */
    6,    /* 417: of_bsn_tlv_tcp_src */
    6,    /* 418: of_bsn_tlv_ttl */
    12,   /* 419: of_bsn_tlv_tx_bytes */
    12,   /* 420: of_bsn_tlv_tx_packets */
    6,    /* 421: of_bsn_tlv_udf_anchor */
    6,    /* 422: of_bsn_tlv_udf_id */
    6,    /* 423: of_bsn_tlv_udf_length */
    6,    /* 424: of_bsn_tlv_udf_offset */
    6,    /* 425: of_bsn_tlv_udp_dst */
    6,    /* 426: of_bsn_tlv_udp_src */
    4,    /* 427: of_bsn_tlv_uint64_list */
    8,    /* 428: of_bsn_tlv_unicast_query_timeout */
    8,    /* 429: of_bsn_tlv_unicast_rate */
    8,    /* 430: of_bsn_tlv_unknown_multicast_rate */
    4,    /* 431: of_bsn_tlv_untagged */
    5,    /* 432: of_bsn_tlv_use_packet_state */
    6,    /* 433: of_bsn_tlv_vfi */
    8,    /* 434: of_bsn_tlv_vfp_class_id */
    4,    /* 435: of_bsn_tlv_vlan_mac_list */
    5,    /* 436: of_bsn_tlv_vlan_pcp */
    6,    /* 437: of_bsn_tlv_vlan_vid */
    6,    /* 438: of_bsn_tlv_vlan_vid_mask */
    8,    /* 439: of_bsn_tlv_vni */
    8,    /* 440: of_bsn_tlv_vpn_key */
    8,    /* 441: of_bsn_tlv_vrf */
    4,    /* 442: of_bsn_tlv_vxlan_egress_lag */
    8,    /* 443: of_bsn_vlan_counter_stats_entry */
    8,    /* 444: of_bsn_vlan_mac */
    4,    /* 445: of_bsn_vport */
    64,   /* 446: of_bsn_vport_l2gre */
    32,   /* 447: of_bsn_vport_q_in_q */
    8,    /* 448: of_bsn_vrf_counter_stats_entry */
    16,   /* 449: of_bucket */
    16,   /* 450: of_bucket_counter */
    -1,   /* 451: of_bundle_prop */
    -1,   /* 452: of_bundle_prop_experimenter */
    56,   /* 453: of_flow_stats_entry */
    8,    /* 454: of_group_desc_stats_entry */
    40,   /* 455: of_group_stats_entry */
    4,    /* 456: of_hello_elem */
    4,    /* 457: of_hello_elem_versionbitmap */
    4,    /* 458: of_instruction */
    8,    /* 459: of_instruction_apply_actions */
    16,   /* 460: of_instruction_bsn */
    16,   /* 461: of_instruction_bsn_arp_offload */
    16,   /* 462: of_instruction_bsn_auto_negotiation */
    16,   /* 463: of_instruction_bsn_deny */
    16,   /* 464: of_instruction_bsn_dhcp_offload */
    16,   /* 465: of_instruction_bsn_disable_l3 */
    16,   /* 466: of_instruction_bsn_disable_split_horizon_check */
    16,   /* 467: of_instruction_bsn_disable_src_mac_check */
    16,   /* 468: of_instruction_bsn_disable_vlan_counters */
    16,   /* 469: of_instruction_bsn_hash_select */
    16,   /* 470: of_instruction_bsn_internal_priority */
    16,   /* 471: of_instruction_bsn_ndp_offload */
    16,   /* 472: of_instruction_bsn_packet_of_death */
    16,   /* 473: of_instruction_bsn_permit */
    16,   /* 474: of_instruction_bsn_prioritize_pdus */
    16,   /* 475: of_instruction_bsn_require_vlan_xlate */
    16,   /* 476: of_instruction_bsn_span_destination */
    8,    /* 477: of_instruction_clear_actions */
    8,    /* 478: of_instruction_experimenter */
    8,    /* 479: of_instruction_goto_table */
    4,    /* 480: of_instruction_id */
    4,    /* 481: of_instruction_id_apply_actions */
    12,   /* 482: of_instruction_id_bsn */
    12,   /* 483: of_instruction_id_bsn_arp_offload */
    12,   /* 484: of_instruction_id_bsn_auto_negotiation */
    12,   /* 485: of_instruction_id_bsn_deny */
    12,   /* 486: of_instruction_id_bsn_dhcp_offload */
    12,   /* 487: of_instruction_id_bsn_disable_l3 */
    12,   /* 488: of_instruction_id_bsn_disable_split_horizon_check */
    12,   /* 489: of_instruction_id_bsn_disable_src_mac_check */
    12,   /* 490: of_instruction_id_bsn_disable_vlan_counters */
    12,   /* 491: of_instruction_id_bsn_hash_select */
    12,   /* 492: of_instruction_id_bsn_internal_priority */
    12,   /* 493: of_instruction_id_bsn_ndp_offload */
    12,   /* 494: of_instruction_id_bsn_packet_of_death */
    12,   /* 495: of_instruction_id_bsn_permit */
    12,   /* 496: of_instruction_id_bsn_prioritize_pdus */
    12,   /* 497: of_instruction_id_bsn_require_vlan_xlate */
    12,   /* 498: of_instruction_id_bsn_span_destination */
    4,    /* 499: of_instruction_id_clear_actions */
    8,    /* 500: of_instruction_id_experimenter */
    4,    /* 501: of_instruction_id_goto_table */
    4,    /* 502: of_instruction_id_meter */
    4,    /* 503: of_instruction_id_write_actions */
    4,    /* 504: of_instruction_id_write_metadata */
    8,    /* 505: of_instruction_meter */
    8,    /* 506: of_instruction_write_actions */
    24,   /* 507: of_instruction_write_metadata */
    -1,   /* 508: of_match_v1 */
    -1,   /* 509: of_match_v2 */
    4,    /* 510: of_match_v3 */
    4,    /* 511: of_meter_band */
    16,   /* 512: of_meter_band_drop */
    16,   /* 513: of_meter_band_dscp_remark */
    16,   /* 514: of_meter_band_experimenter */
    16,   /* 515: of_meter_band_stats */
    8,    /* 516: of_meter_config */
    16,   /* 517: of_meter_features */
    40,   /* 518: of_meter_stats */
    4,    /* 519: of_oxm */
    6,    /* 520: of_oxm_arp_op */
    8,    /* 521: of_oxm_arp_op_masked */
    10,   /* 522: of_oxm_arp_sha */
    16,   /* 523: of_oxm_arp_sha_masked */
    8,    /* 524: of_oxm_arp_spa */
    12,   /* 525: of_oxm_arp_spa_masked */
    10,   /* 526: of_oxm_arp_tha */
    16,   /* 527: of_oxm_arp_tha_masked */
    8,    /* 528: of_oxm_arp_tpa */
    12,   /* 529: of_oxm_arp_tpa_masked */
    8,    /* 530: of_oxm_bsn_egr_port_group_id */
    12,   /* 531: of_oxm_bsn_egr_port_group_id_masked */
    5,    /* 532: of_oxm_bsn_global_vrf_allowed */
    6,    /* 533: of_oxm_bsn_global_vrf_allowed_masked */
    20,   /* 534: of_oxm_bsn_in_ports_128 */
    36,   /* 535: of_oxm_bsn_in_ports_128_masked */
    68,   /* 536: of_oxm_bsn_in_ports_512 */
    132,  /* 537: of_oxm_bsn_in_ports_512_masked */
    8,    /* 538: of_oxm_bsn_ingress_port_group_id */
    12,   /* 539: of_oxm_bsn_ingress_port_group_id_masked */
    10,   /* 540: of_oxm_bsn_inner_eth_dst */
    16,   /* 541: of_oxm_bsn_inner_eth_dst_masked */
    10,   /* 542: of_oxm_bsn_inner_eth_src */
    16,   /* 543: of_oxm_bsn_inner_eth_src_masked */
    6,    /* 544: of_oxm_bsn_inner_vlan_vid */
    8,    /* 545: of_oxm_bsn_inner_vlan_vid_masked */
    5,    /* 546: of_oxm_bsn_ip_fragmentation */
    6,    /* 547: of_oxm_bsn_ip_fragmentation_masked */
    5,    /* 548: of_oxm_bsn_l2_cache_hit */
    6,    /* 549: of_oxm_bsn_l2_cache_hit_masked */
    8,    /* 550: of_oxm_bsn_l3_dst_class_id */
    12,   /* 551: of_oxm_bsn_l3_dst_class_id_masked */
    8,    /* 552: of_oxm_bsn_l3_interface_class_id */
    12,   /* 553: of_oxm_bsn_l3_interface_class_id_masked */
    8,    /* 554: of_oxm_bsn_l3_src_class_id */
    12,   /* 555: of_oxm_bsn_l3_src_class_id_masked */
    8,    /* 556: of_oxm_bsn_lag_id */
    12,   /* 557: of_oxm_bsn_lag_id_masked */
    6,    /* 558: of_oxm_bsn_tcp_flags */
    8,    /* 559: of_oxm_bsn_tcp_flags_masked */
    8,    /* 560: of_oxm_bsn_udf0 */
    12,   /* 561: of_oxm_bsn_udf0_masked */
    8,    /* 562: of_oxm_bsn_udf1 */
    12,   /* 563: of_oxm_bsn_udf1_masked */
    8,    /* 564: of_oxm_bsn_udf2 */
    12,   /* 565: of_oxm_bsn_udf2_masked */
    8,    /* 566: of_oxm_bsn_udf3 */
    12,   /* 567: of_oxm_bsn_udf3_masked */
    8,    /* 568: of_oxm_bsn_udf4 */
    12,   /* 569: of_oxm_bsn_udf4_masked */
    8,    /* 570: of_oxm_bsn_udf5 */
    12,   /* 571: of_oxm_bsn_udf5_masked */
    8,    /* 572: of_oxm_bsn_udf6 */
    12,   /* 573: of_oxm_bsn_udf6_masked */
    8,    /* 574: of_oxm_bsn_udf7 */
    12,   /* 575: of_oxm_bsn_udf7_masked */
    6,    /* 576: of_oxm_bsn_vfi */
    8,    /* 577: of_oxm_bsn_vfi_masked */
    8,    /* 578: of_oxm_bsn_vlan_xlate_port_group_id */
    12,   /* 579: of_oxm_bsn_vlan_xlate_port_group_id_masked */
    8,    /* 580: of_oxm_bsn_vrf */
    12,   /* 581: of_oxm_bsn_vrf_masked */
    8,    /* 582: of_oxm_bsn_vxlan_network_id */
    12,   /* 583: of_oxm_bsn_vxlan_network_id_masked */
    10,   /* 584: of_oxm_eth_dst */
    16,   /* 585: of_oxm_eth_dst_masked */
    10,   /* 586: of_oxm_eth_src */
    16,   /* 587: of_oxm_eth_src_masked */
    6,    /* 588: of_oxm_eth_type */
    8,    /* 589: of_oxm_eth_type_masked */
    5,    /* 590: of_oxm_icmpv4_code */
    6,    /* 591: of_oxm_icmpv4_code_masked */
    5,    /* 592: of_oxm_icmpv4_type */
    6,    /* 593: of_oxm_icmpv4_type_masked */
    5,    /* 594: of_oxm_icmpv6_code */
    6,    /* 595: of_oxm_icmpv6_code_masked */
    5,    /* 596: of_oxm_icmpv6_type */
    6,    /* 597: of_oxm_icmpv6_type_masked */
    8,    /* 598: of_oxm_in_phy_port */
    12,   /* 599: of_oxm_in_phy_port_masked */
    8,    /* 600: of_oxm_in_port */
    12,   /* 601: of_oxm_in_port_masked */
    5,    /* 602: of_oxm_ip_dscp */
    6,    /* 603: of_oxm_ip_dscp_masked */
    5,    /* 604: of_oxm_ip_ecn */
    6,    /* 605: of_oxm_ip_ecn_masked */
    5,    /* 606: of_oxm_ip_proto */
    6,    /* 607: of_oxm_ip_proto_masked */
    8,    /* 608: of_oxm_ipv4_dst */
    12,   /* 609: of_oxm_ipv4_dst_masked */
    8,    /* 610: of_oxm_ipv4_src */
    12,   /* 611: of_oxm_ipv4_src_masked */
    20,   /* 612: of_oxm_ipv6_dst */
    36,   /* 613: of_oxm_ipv6_dst_masked */
    6,    /* 614: of_oxm_ipv6_exthdr */
    8,    /* 615: of_oxm_ipv6_exthdr_masked */
    8,    /* 616: of_oxm_ipv6_flabel */
    12,   /* 617: of_oxm_ipv6_flabel_masked */
    10,   /* 618: of_oxm_ipv6_nd_sll */
    16,   /* 619: of_oxm_ipv6_nd_sll_masked */
    20,   /* 620: of_oxm_ipv6_nd_target */
    36,   /* 621: of_oxm_ipv6_nd_target_masked */
    10,   /* 622: of_oxm_ipv6_nd_tll */
    16,   /* 623: of_oxm_ipv6_nd_tll_masked */
    20,   /* 624: of_oxm_ipv6_src */
    36,   /* 625: of_oxm_ipv6_src_masked */
    12,   /* 626: of_oxm_metadata */
    20,   /* 627: of_oxm_metadata_masked */
    5,    /* 628: of_oxm_mpls_bos */
    6,    /* 629: of_oxm_mpls_bos_masked */
    8,    /* 630: of_oxm_mpls_label */
    12,   /* 631: of_oxm_mpls_label_masked */
    5,    /* 632: of_oxm_mpls_tc */
    6,    /* 633: of_oxm_mpls_tc_masked */
    10,   /* 634: of_oxm_ovs_tcp_flags */
    12,   /* 635: of_oxm_ovs_tcp_flags_masked */
    -1,   /* 636: of_oxm_pbb_uca */
    -1,   /* 637: of_oxm_pbb_uca_masked */
    6,    /* 638: of_oxm_sctp_dst */
    8,    /* 639: of_oxm_sctp_dst_masked */
    6,    /* 640: of_oxm_sctp_src */
    8,    /* 641: of_oxm_sctp_src_masked */
    6,    /* 642: of_oxm_tcp_dst */
    8,    /* 643: of_oxm_tcp_dst_masked */
    6,    /* 644: of_oxm_tcp_src */
    8,    /* 645: of_oxm_tcp_src_masked */
    12,   /* 646: of_oxm_tunnel_id */
    20,   /* 647: of_oxm_tunnel_id_masked */
    8,    /* 648: of_oxm_tunnel_ipv4_dst */
    12,   /* 649: of_oxm_tunnel_ipv4_dst_masked */
    8,    /* 650: of_oxm_tunnel_ipv4_src */
    12,   /* 651: of_oxm_tunnel_ipv4_src_masked */
    6,    /* 652: of_oxm_udp_dst */
    8,    /* 653: of_oxm_udp_dst_masked */
    6,    /* 654: of_oxm_udp_src */
    8,    /* 655: of_oxm_udp_src_masked */
    5,    /* 656: of_oxm_vlan_pcp */
    6,    /* 657: of_oxm_vlan_pcp_masked */
    6,    /* 658: of_oxm_vlan_vid */
    8,    /* 659: of_oxm_vlan_vid_masked */
    16,   /* 660: of_packet_queue */
    64,   /* 661: of_port_desc */
    -1,   /* 662: of_port_desc_prop */
    -1,   /* 663: of_port_desc_prop_bsn */
    -1,   /* 664: of_port_desc_prop_bsn_generation_id */
    -1,   /* 665: of_port_desc_prop_bsn_uplink */
    -1,   /* 666: of_port_desc_prop_ethernet */
    -1,   /* 667: of_port_desc_prop_experimenter */
    -1,   /* 668: of_port_desc_prop_optical */
    -1,   /* 669: of_port_mod_prop */
    -1,   /* 670: of_port_mod_prop_ethernet */
    -1,   /* 671: of_port_mod_prop_experimenter */
    -1,   /* 672: of_port_mod_prop_optical */
    112,  /* 673: of_port_stats_entry */
    -1,   /* 674: of_port_stats_prop */
    -1,   /* 675: of_port_stats_prop_ethernet */
    -1,   /* 676: of_port_stats_prop_experimenter */
    -1,   /* 677: of_port_stats_prop_optical */
    -1,   /* 678: of_queue_desc */
    -1,   /* 679: of_queue_desc_prop */
    -1,   /* 680: of_queue_desc_prop_bsn */
    -1,   /* 681: of_queue_desc_prop_bsn_queue_name */
    -1,   /* 682: of_queue_desc_prop_experimenter */
    -1,   /* 683: of_queue_desc_prop_max_rate */
    -1,   /* 684: of_queue_desc_prop_min_rate */
    8,    /* 685: of_queue_prop */
    16,   /* 686: of_queue_prop_experimenter */
    16,   /* 687: of_queue_prop_max_rate */
    16,   /* 688: of_queue_prop_min_rate */
    40,   /* 689: of_queue_stats_entry */
    -1,   /* 690: of_queue_stats_prop */
    -1,   /* 691: of_queue_stats_prop_experimenter */
    -1,   /* 692: of_role_prop */
    -1,   /* 693: of_role_prop_experimenter */
    -1,   /* 694: of_table_desc */
    4,    /* 695: of_table_feature_prop */
    4,    /* 696: of_table_feature_prop_apply_actions */
    4,    /* 697: of_table_feature_prop_apply_actions_miss */
    4,    /* 698: of_table_feature_prop_apply_setfield */
    4,    /* 699: of_table_feature_prop_apply_setfield_miss */
    12,   /* 700: of_table_feature_prop_experimenter */
    12,   /* 701: of_table_feature_prop_experimenter_miss */
    4,    /* 702: of_table_feature_prop_instructions */
    4,    /* 703: of_table_feature_prop_instructions_miss */
    4,    /* 704: of_table_feature_prop_match */
    4,    /* 705: of_table_feature_prop_next_tables */
    4,    /* 706: of_table_feature_prop_next_tables_miss */
    -1,   /* 707: of_table_feature_prop_table_sync_from */
    4,    /* 708: of_table_feature_prop_wildcards */
    4,    /* 709: of_table_feature_prop_write_actions */
    4,    /* 710: of_table_feature_prop_write_actions_miss */
    4,    /* 711: of_table_feature_prop_write_setfield */
    4,    /* 712: of_table_feature_prop_write_setfield_miss */
    64,   /* 713: of_table_features */
    -1,   /* 714: of_table_mod_prop */
    -1,   /* 715: of_table_mod_prop_eviction */
    -1,   /* 716: of_table_mod_prop_experimenter */
    -1,   /* 717: of_table_mod_prop_vacancy */
    24,   /* 718: of_table_stats_entry */
    4,    /* 719: of_uint32 */
    8,    /* 720: of_uint64 */
    1,    /* 721: of_uint8 */
    0,    /* 722: of_list_action */
    0,    /* 723: of_list_action_id */
    -1,   /* 724: of_list_async_config_prop */
    0,    /* 725: of_list_bsn_controller_connection */
    0,    /* 726: of_list_bsn_debug_counter_desc_stats_entry */
    0,    /* 727: of_list_bsn_debug_counter_stats_entry */
    0,    /* 728: of_list_bsn_flow_checksum_bucket_stats_entry */
    0,    /* 729: of_list_bsn_generic_stats_entry */
    0,    /* 730: of_list_bsn_gentable_bucket_stats_entry */
    0,    /* 731: of_list_bsn_gentable_desc_stats_entry */
    0,    /* 732: of_list_bsn_gentable_entry_desc_stats_entry */
    0,    /* 733: of_list_bsn_gentable_entry_stats_entry */
    0,    /* 734: of_list_bsn_gentable_stats_entry */
    0,    /* 735: of_list_bsn_interface */
    0,    /* 736: of_list_bsn_lacp_stats_entry */
    0,    /* 737: of_list_bsn_port_counter_stats_entry */
    0,    /* 738: of_list_bsn_switch_pipeline_stats_entry */
    0,    /* 739: of_list_bsn_table_checksum_stats_entry */
    0,    /* 740: of_list_bsn_tlv */
    0,    /* 741: of_list_bsn_vlan_counter_stats_entry */
    0,    /* 742: of_list_bsn_vlan_mac */
    0,    /* 743: of_list_bsn_vrf_counter_stats_entry */
    0,    /* 744: of_list_bucket */
    0,    /* 745: of_list_bucket_counter */
    -1,   /* 746: of_list_bundle_prop */
    0,    /* 747: of_list_flow_stats_entry */
    0,    /* 748: of_list_group_desc_stats_entry */
    0,    /* 749: of_list_group_stats_entry */
    0,    /* 750: of_list_hello_elem */
    0,    /* 751: of_list_instruction */
    0,    /* 752: of_list_instruction_id */
    0,    /* 753: of_list_meter_band */
    0,    /* 754: of_list_meter_band_stats */
    0,    /* 755: of_list_meter_config */
    0,    /* 756: of_list_meter_stats */
    0,    /* 757: of_list_oxm */
    0,    /* 758: of_list_packet_queue */
    0,    /* 759: of_list_port_desc */
    -1,   /* 760: of_list_port_desc_prop */
    -1,   /* 761: of_list_port_mod_prop */
    0,    /* 762: of_list_port_stats_entry */
    -1,   /* 763: of_list_port_stats_prop */
    -1,   /* 764: of_list_queue_desc */
    -1,   /* 765: of_list_queue_desc_prop */
    0,    /* 766: of_list_queue_prop */
    0,    /* 767: of_list_queue_stats_entry */
    -1,   /* 768: of_list_queue_stats_prop */
    -1,   /* 769: of_list_role_prop */
    -1,   /* 770: of_list_table_desc */
    0,    /* 771: of_list_table_feature_prop */
    0,    /* 772: of_list_table_features */
    -1,   /* 773: of_list_table_mod_prop */
    0,    /* 774: of_list_table_stats_entry */
    0,    /* 775: of_list_uint32 */
    0,    /* 776: of_list_uint64 */
    0     /* 777: of_list_uint8 */
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
    272,  /* 15: of_bsn_base_error */
    20,   /* 16: of_bsn_bw_clear_data_reply */
    16,   /* 17: of_bsn_bw_clear_data_request */
    20,   /* 18: of_bsn_bw_enable_get_reply */
    16,   /* 19: of_bsn_bw_enable_get_request */
    24,   /* 20: of_bsn_bw_enable_set_reply */
    20,   /* 21: of_bsn_bw_enable_set_request */
    16,   /* 22: of_bsn_controller_connections_reply */
    16,   /* 23: of_bsn_controller_connections_request */
    24,   /* 24: of_bsn_debug_counter_desc_stats_reply */
    24,   /* 25: of_bsn_debug_counter_desc_stats_request */
    24,   /* 26: of_bsn_debug_counter_stats_reply */
    24,   /* 27: of_bsn_debug_counter_stats_request */
    272,  /* 28: of_bsn_error */
    24,   /* 29: of_bsn_flow_checksum_bucket_stats_reply */
    25,   /* 30: of_bsn_flow_checksum_bucket_stats_request */
    40,   /* 31: of_bsn_flow_idle */
    20,   /* 32: of_bsn_flow_idle_enable_get_reply */
    16,   /* 33: of_bsn_flow_idle_enable_get_request */
    24,   /* 34: of_bsn_flow_idle_enable_set_reply */
    20,   /* 35: of_bsn_flow_idle_enable_set_request */
    80,   /* 36: of_bsn_generic_async */
    80,   /* 37: of_bsn_generic_command */
    24,   /* 38: of_bsn_generic_stats_reply */
    88,   /* 39: of_bsn_generic_stats_request */
    24,   /* 40: of_bsn_gentable_bucket_stats_reply */
    26,   /* 41: of_bsn_gentable_bucket_stats_request */
    28,   /* 42: of_bsn_gentable_clear_reply */
    52,   /* 43: of_bsn_gentable_clear_request */
    24,   /* 44: of_bsn_gentable_desc_stats_reply */
    24,   /* 45: of_bsn_gentable_desc_stats_request */
    36,   /* 46: of_bsn_gentable_entry_add */
    18,   /* 47: of_bsn_gentable_entry_delete */
    24,   /* 48: of_bsn_gentable_entry_desc_stats_reply */
    60,   /* 49: of_bsn_gentable_entry_desc_stats_request */
    24,   /* 50: of_bsn_gentable_entry_stats_reply */
    60,   /* 51: of_bsn_gentable_entry_stats_request */
    24,   /* 52: of_bsn_gentable_set_buckets_size */
    24,   /* 53: of_bsn_gentable_stats_reply */
    24,   /* 54: of_bsn_gentable_stats_request */
    16,   /* 55: of_bsn_get_interfaces_reply */
    16,   /* 56: of_bsn_get_interfaces_request */
    -1,   /* 57: of_bsn_get_ip_mask_reply */
    -1,   /* 58: of_bsn_get_ip_mask_request */
    -1,   /* 59: of_bsn_get_l2_table_reply */
    -1,   /* 60: of_bsn_get_l2_table_request */
    20,   /* 61: of_bsn_get_mirroring_reply */
    20,   /* 62: of_bsn_get_mirroring_request */
    272,  /* 63: of_bsn_get_switch_pipeline_reply */
    16,   /* 64: of_bsn_get_switch_pipeline_request */
    16,   /* 65: of_bsn_header */
    -1,   /* 66: of_bsn_hybrid_get_reply */
    -1,   /* 67: of_bsn_hybrid_get_request */
    536,  /* 68: of_bsn_image_desc_stats_reply */
    24,   /* 69: of_bsn_image_desc_stats_request */
    52,   /* 70: of_bsn_lacp_convergence_notif */
    24,   /* 71: of_bsn_lacp_stats_reply */
    24,   /* 72: of_bsn_lacp_stats_request */
    17,   /* 73: of_bsn_log */
    16,   /* 74: of_bsn_lua_command_reply */
    16,   /* 75: of_bsn_lua_command_request */
    16,   /* 76: of_bsn_lua_notification */
    82,   /* 77: of_bsn_lua_upload */
    25,   /* 78: of_bsn_pdu_rx_reply */
    28,   /* 79: of_bsn_pdu_rx_request */
    21,   /* 80: of_bsn_pdu_rx_timeout */
    25,   /* 81: of_bsn_pdu_tx_reply */
    28,   /* 82: of_bsn_pdu_tx_request */
    24,   /* 83: of_bsn_port_counter_stats_reply */
    28,   /* 84: of_bsn_port_counter_stats_request */
    -1,   /* 85: of_bsn_role_status */
    24,   /* 86: of_bsn_set_aux_cxns_reply */
    20,   /* 87: of_bsn_set_aux_cxns_request */
    -1,   /* 88: of_bsn_set_ip_mask */
    -1,   /* 89: of_bsn_set_l2_table_reply */
    -1,   /* 90: of_bsn_set_l2_table_request */
    24,   /* 91: of_bsn_set_lacp_reply */
    38,   /* 92: of_bsn_set_lacp_request */
    20,   /* 93: of_bsn_set_mirroring */
    20,   /* 94: of_bsn_set_pktin_suppression_reply */
    32,   /* 95: of_bsn_set_pktin_suppression_request */
    20,   /* 96: of_bsn_set_switch_pipeline_reply */
    272,  /* 97: of_bsn_set_switch_pipeline_request */
    -1,   /* 98: of_bsn_shell_command */
    -1,   /* 99: of_bsn_shell_output */
    -1,   /* 100: of_bsn_shell_status */
    24,   /* 101: of_bsn_stats_reply */
    24,   /* 102: of_bsn_stats_request */
    24,   /* 103: of_bsn_switch_pipeline_stats_reply */
    24,   /* 104: of_bsn_switch_pipeline_stats_request */
    24,   /* 105: of_bsn_table_checksum_stats_reply */
    24,   /* 106: of_bsn_table_checksum_stats_request */
    24,   /* 107: of_bsn_table_set_buckets_size */
    16,   /* 108: of_bsn_takeover */
    24,   /* 109: of_bsn_time_reply */
    16,   /* 110: of_bsn_time_request */
    24,   /* 111: of_bsn_virtual_port_create_reply */
    20,   /* 112: of_bsn_virtual_port_create_request */
    20,   /* 113: of_bsn_virtual_port_remove_reply */
    20,   /* 114: of_bsn_virtual_port_remove_request */
    18,   /* 115: of_bsn_vlan_counter_clear */
    24,   /* 116: of_bsn_vlan_counter_stats_reply */
    26,   /* 117: of_bsn_vlan_counter_stats_request */
    24,   /* 118: of_bsn_vrf_counter_stats_reply */
    28,   /* 119: of_bsn_vrf_counter_stats_request */
    16,   /* 120: of_bundle_add_msg */
    16,   /* 121: of_bundle_ctrl_msg */
    12,   /* 122: of_bundle_failed_error_msg */
    1072, /* 123: of_desc_stats_reply */
    16,   /* 124: of_desc_stats_request */
    8,    /* 125: of_echo_reply */
    8,    /* 126: of_echo_request */
    10,   /* 127: of_error_msg */
    16,   /* 128: of_experimenter */
    16,   /* 129: of_experimenter_error_msg */
    24,   /* 130: of_experimenter_stats_reply */
    24,   /* 131: of_experimenter_stats_request */
    32,   /* 132: of_features_reply */
    8,    /* 133: of_features_request */
    56,   /* 134: of_flow_add */
    56,   /* 135: of_flow_delete */
    56,   /* 136: of_flow_delete_strict */
    56,   /* 137: of_flow_mod */
    12,   /* 138: of_flow_mod_failed_error_msg */
    56,   /* 139: of_flow_modify */
    56,   /* 140: of_flow_modify_strict */
    12,   /* 141: of_flow_monitor_failed_error_msg */
    56,   /* 142: of_flow_removed */
    16,   /* 143: of_flow_stats_reply */
    56,   /* 144: of_flow_stats_request */
    12,   /* 145: of_get_config_reply */
    8,    /* 146: of_get_config_request */
    16,   /* 147: of_group_add */
    16,   /* 148: of_group_delete */
    16,   /* 149: of_group_desc_stats_reply */
    16,   /* 150: of_group_desc_stats_request */
    56,   /* 151: of_group_features_stats_reply */
    16,   /* 152: of_group_features_stats_request */
    16,   /* 153: of_group_mod */
    12,   /* 154: of_group_mod_failed_error_msg */
    16,   /* 155: of_group_modify */
    16,   /* 156: of_group_stats_reply */
    24,   /* 157: of_group_stats_request */
    8,    /* 158: of_header */
    8,    /* 159: of_hello */
    12,   /* 160: of_hello_failed_error_msg */
    16,   /* 161: of_meter_config_stats_reply */
    24,   /* 162: of_meter_config_stats_request */
    32,   /* 163: of_meter_features_stats_reply */
    16,   /* 164: of_meter_features_stats_request */
    16,   /* 165: of_meter_mod */
    12,   /* 166: of_meter_mod_failed_error_msg */
    16,   /* 167: of_meter_stats_reply */
    24,   /* 168: of_meter_stats_request */
    -1,   /* 169: of_nicira_controller_role_reply */
    -1,   /* 170: of_nicira_controller_role_request */
    16,   /* 171: of_nicira_header */
    34,   /* 172: of_packet_in */
    24,   /* 173: of_packet_out */
    16,   /* 174: of_port_desc_stats_reply */
    16,   /* 175: of_port_desc_stats_request */
    32,   /* 176: of_port_mod */
    12,   /* 177: of_port_mod_failed_error_msg */
    16,   /* 178: of_port_stats_reply */
    24,   /* 179: of_port_stats_request */
    56,   /* 180: of_port_status */
    16,   /* 181: of_queue_desc_stats_reply */
    24,   /* 182: of_queue_desc_stats_request */
    -1,   /* 183: of_queue_get_config_reply */
    -1,   /* 184: of_queue_get_config_request */
    12,   /* 185: of_queue_op_failed_error_msg */
    16,   /* 186: of_queue_stats_reply */
    24,   /* 187: of_queue_stats_request */
    12,   /* 188: of_requestforward */
    24,   /* 189: of_role_reply */
    24,   /* 190: of_role_request */
    12,   /* 191: of_role_request_failed_error_msg */
    24,   /* 192: of_role_status */
    12,   /* 193: of_set_config */
    16,   /* 194: of_stats_reply */
    16,   /* 195: of_stats_request */
    12,   /* 196: of_switch_config_failed_error_msg */
    16,   /* 197: of_table_desc_stats_reply */
    16,   /* 198: of_table_desc_stats_request */
    12,   /* 199: of_table_features_failed_error_msg */
    16,   /* 200: of_table_features_stats_reply */
    16,   /* 201: of_table_features_stats_request */
    16,   /* 202: of_table_mod */
    12,   /* 203: of_table_mod_failed_error_msg */
    16,   /* 204: of_table_stats_reply */
    16,   /* 205: of_table_stats_request */
    28,   /* 206: of_table_status */
    8,    /* 207: of_action */
    16,   /* 208: of_action_bsn */
    28,   /* 209: of_action_bsn_checksum */
    16,   /* 210: of_action_bsn_gentable */
    24,   /* 211: of_action_bsn_mirror */
    16,   /* 212: of_action_bsn_set_tunnel_dst */
    8,    /* 213: of_action_copy_ttl_in */
    8,    /* 214: of_action_copy_ttl_out */
    8,    /* 215: of_action_dec_mpls_ttl */
    8,    /* 216: of_action_dec_nw_ttl */
    -1,   /* 217: of_action_enqueue */
    8,    /* 218: of_action_experimenter */
    8,    /* 219: of_action_group */
    4,    /* 220: of_action_id */
    12,   /* 221: of_action_id_bsn */
    12,   /* 222: of_action_id_bsn_checksum */
    12,   /* 223: of_action_id_bsn_gentable */
    12,   /* 224: of_action_id_bsn_mirror */
    12,   /* 225: of_action_id_bsn_set_tunnel_dst */
    4,    /* 226: of_action_id_copy_ttl_in */
    4,    /* 227: of_action_id_copy_ttl_out */
    4,    /* 228: of_action_id_dec_mpls_ttl */
    4,    /* 229: of_action_id_dec_nw_ttl */
    8,    /* 230: of_action_id_experimenter */
    4,    /* 231: of_action_id_group */
    10,   /* 232: of_action_id_nicira */
    10,   /* 233: of_action_id_nicira_dec_ttl */
    4,    /* 234: of_action_id_output */
    4,    /* 235: of_action_id_pop_mpls */
    4,    /* 236: of_action_id_pop_pbb */
    4,    /* 237: of_action_id_pop_vlan */
    4,    /* 238: of_action_id_push_mpls */
    4,    /* 239: of_action_id_push_pbb */
    4,    /* 240: of_action_id_push_vlan */
    4,    /* 241: of_action_id_set_field */
    4,    /* 242: of_action_id_set_mpls_ttl */
    4,    /* 243: of_action_id_set_nw_ttl */
    4,    /* 244: of_action_id_set_queue */
    16,   /* 245: of_action_nicira */
    16,   /* 246: of_action_nicira_dec_ttl */
    16,   /* 247: of_action_output */
    8,    /* 248: of_action_pop_mpls */
    8,    /* 249: of_action_pop_pbb */
    8,    /* 250: of_action_pop_vlan */
    8,    /* 251: of_action_push_mpls */
    8,    /* 252: of_action_push_pbb */
    8,    /* 253: of_action_push_vlan */
    -1,   /* 254: of_action_set_dl_dst */
    -1,   /* 255: of_action_set_dl_src */
    8,    /* 256: of_action_set_field */
    -1,   /* 257: of_action_set_mpls_label */
    -1,   /* 258: of_action_set_mpls_tc */
    8,    /* 259: of_action_set_mpls_ttl */
    -1,   /* 260: of_action_set_nw_dst */
    -1,   /* 261: of_action_set_nw_ecn */
    -1,   /* 262: of_action_set_nw_src */
    -1,   /* 263: of_action_set_nw_tos */
    8,    /* 264: of_action_set_nw_ttl */
    8,    /* 265: of_action_set_queue */
    -1,   /* 266: of_action_set_tp_dst */
    -1,   /* 267: of_action_set_tp_src */
    -1,   /* 268: of_action_set_vlan_pcp */
    -1,   /* 269: of_action_set_vlan_vid */
    -1,   /* 270: of_action_strip_vlan */
    4,    /* 271: of_async_config_prop */
    4,    /* 272: of_async_config_prop_experimenter_master */
    4,    /* 273: of_async_config_prop_experimenter_slave */
    8,    /* 274: of_async_config_prop_flow_removed_master */
    8,    /* 275: of_async_config_prop_flow_removed_slave */
    8,    /* 276: of_async_config_prop_packet_in_master */
    8,    /* 277: of_async_config_prop_packet_in_slave */
    8,    /* 278: of_async_config_prop_port_status_master */
    8,    /* 279: of_async_config_prop_port_status_slave */
    8,    /* 280: of_async_config_prop_requestforward_master */
    8,    /* 281: of_async_config_prop_requestforward_slave */
    8,    /* 282: of_async_config_prop_role_status_master */
    8,    /* 283: of_async_config_prop_role_status_slave */
    8,    /* 284: of_async_config_prop_table_status_master */
    8,    /* 285: of_async_config_prop_table_status_slave */
    264,  /* 286: of_bsn_controller_connection */
    328,  /* 287: of_bsn_debug_counter_desc_stats_entry */
    16,   /* 288: of_bsn_debug_counter_stats_entry */
    8,    /* 289: of_bsn_flow_checksum_bucket_stats_entry */
    2,    /* 290: of_bsn_generic_stats_entry */
    16,   /* 291: of_bsn_gentable_bucket_stats_entry */
    48,   /* 292: of_bsn_gentable_desc_stats_entry */
    20,   /* 293: of_bsn_gentable_entry_desc_stats_entry */
    4,    /* 294: of_bsn_gentable_entry_stats_entry */
    24,   /* 295: of_bsn_gentable_stats_entry */
    32,   /* 296: of_bsn_interface */
    36,   /* 297: of_bsn_lacp_stats_entry */
    8,    /* 298: of_bsn_port_counter_stats_entry */
    256,  /* 299: of_bsn_switch_pipeline_stats_entry */
    9,    /* 300: of_bsn_table_checksum_stats_entry */
    4,    /* 301: of_bsn_tlv */
    6,    /* 302: of_bsn_tlv_actor_key */
    6,    /* 303: of_bsn_tlv_actor_port_num */
    6,    /* 304: of_bsn_tlv_actor_port_priority */
    5,    /* 305: of_bsn_tlv_actor_state */
    10,   /* 306: of_bsn_tlv_actor_system_mac */
    6,    /* 307: of_bsn_tlv_actor_system_priority */
    6,    /* 308: of_bsn_tlv_anchor */
    12,   /* 309: of_bsn_tlv_apply_bytes */
    12,   /* 310: of_bsn_tlv_apply_packets */
    8,    /* 311: of_bsn_tlv_broadcast_query_timeout */
    8,    /* 312: of_bsn_tlv_broadcast_rate */
    4,    /* 313: of_bsn_tlv_bucket */
    4,    /* 314: of_bsn_tlv_circuit_id */
    5,    /* 315: of_bsn_tlv_convergence_status */
    4,    /* 316: of_bsn_tlv_cpu_lag */
    5,    /* 317: of_bsn_tlv_crc_enabled */
    4,    /* 318: of_bsn_tlv_data */
    4,    /* 319: of_bsn_tlv_data_mask */
    6,    /* 320: of_bsn_tlv_decap */
    4,    /* 321: of_bsn_tlv_disable_src_mac_check */
    4,    /* 322: of_bsn_tlv_drop */
    6,    /* 323: of_bsn_tlv_dscp */
    5,    /* 324: of_bsn_tlv_ecn */
    4,    /* 325: of_bsn_tlv_egress_only */
    8,    /* 326: of_bsn_tlv_egress_port_group_id */
    10,   /* 327: of_bsn_tlv_eth_dst */
    10,   /* 328: of_bsn_tlv_eth_src */
    6,    /* 329: of_bsn_tlv_eth_type */
    8,    /* 330: of_bsn_tlv_external_gateway_ip */
    10,   /* 331: of_bsn_tlv_external_gateway_mac */
    8,    /* 332: of_bsn_tlv_external_ip */
    10,   /* 333: of_bsn_tlv_external_mac */
    8,    /* 334: of_bsn_tlv_external_netmask */
    12,   /* 335: of_bsn_tlv_generation_id */
    6,    /* 336: of_bsn_tlv_hash_gtp_header_match */
    9,    /* 337: of_bsn_tlv_hash_gtp_port_match */
    12,   /* 338: of_bsn_tlv_hash_packet_field */
    5,    /* 339: of_bsn_tlv_hash_packet_type */
    12,   /* 340: of_bsn_tlv_hash_seed */
    5,    /* 341: of_bsn_tlv_hash_type */
    8,    /* 342: of_bsn_tlv_header_size */
    5,    /* 343: of_bsn_tlv_icmp_code */
    6,    /* 344: of_bsn_tlv_icmp_id */
    5,    /* 345: of_bsn_tlv_icmp_type */
    6,    /* 346: of_bsn_tlv_icmpv6_chksum */
    4,    /* 347: of_bsn_tlv_idle_notification */
    12,   /* 348: of_bsn_tlv_idle_time */
    8,    /* 349: of_bsn_tlv_idle_timeout */
    4,    /* 350: of_bsn_tlv_igmp_snooping */
    8,    /* 351: of_bsn_tlv_ingress_port_group_id */
    10,   /* 352: of_bsn_tlv_internal_gateway_mac */
    10,   /* 353: of_bsn_tlv_internal_mac */
    8,    /* 354: of_bsn_tlv_interval */
    5,    /* 355: of_bsn_tlv_ip_proto */
    8,    /* 356: of_bsn_tlv_ipv4 */
    8,    /* 357: of_bsn_tlv_ipv4_dst */
    8,    /* 358: of_bsn_tlv_ipv4_netmask */
    8,    /* 359: of_bsn_tlv_ipv4_src */
    20,   /* 360: of_bsn_tlv_ipv6 */
    20,   /* 361: of_bsn_tlv_ipv6_dst */
    21,   /* 362: of_bsn_tlv_ipv6_prefix */
    20,   /* 363: of_bsn_tlv_ipv6_src */
    8,    /* 364: of_bsn_tlv_known_multicast_rate */
    4,    /* 365: of_bsn_tlv_l2_multicast_lookup */
    8,    /* 366: of_bsn_tlv_l3_dst_class_id */
    8,    /* 367: of_bsn_tlv_l3_interface_class_id */
    8,    /* 368: of_bsn_tlv_l3_src_class_id */
    8,    /* 369: of_bsn_tlv_loopback_port */
    10,   /* 370: of_bsn_tlv_mac */
    10,   /* 371: of_bsn_tlv_mac_mask */
    4,    /* 372: of_bsn_tlv_mcg_type_vxlan */
    12,   /* 373: of_bsn_tlv_miss_packets */
    5,    /* 374: of_bsn_tlv_mpls_control_word */
    8,    /* 375: of_bsn_tlv_mpls_label */
    5,    /* 376: of_bsn_tlv_mpls_sequenced */
    8,    /* 377: of_bsn_tlv_multicast_interface_id */
    4,    /* 378: of_bsn_tlv_name */
    4,    /* 379: of_bsn_tlv_ndp_offload */
    4,    /* 380: of_bsn_tlv_ndp_static */
    4,    /* 381: of_bsn_tlv_negate */
    8,    /* 382: of_bsn_tlv_next_hop_ipv4 */
    10,   /* 383: of_bsn_tlv_next_hop_mac */
    4,    /* 384: of_bsn_tlv_nexthop_type_vxlan */
    6,    /* 385: of_bsn_tlv_offset */
    8,    /* 386: of_bsn_tlv_parent_port */
    6,    /* 387: of_bsn_tlv_partner_key */
    6,    /* 388: of_bsn_tlv_partner_port_num */
    6,    /* 389: of_bsn_tlv_partner_port_priority */
    5,    /* 390: of_bsn_tlv_partner_state */
    10,   /* 391: of_bsn_tlv_partner_system_mac */
    6,    /* 392: of_bsn_tlv_partner_system_priority */
    8,    /* 393: of_bsn_tlv_port */
    6,    /* 394: of_bsn_tlv_port_usage */
    5,    /* 395: of_bsn_tlv_port_vxlan_mode */
    8,    /* 396: of_bsn_tlv_priority */
    4,    /* 397: of_bsn_tlv_push_vlan_on_ingress */
    8,    /* 398: of_bsn_tlv_qos_priority */
    8,    /* 399: of_bsn_tlv_queue_id */
    8,    /* 400: of_bsn_tlv_queue_weight */
    8,    /* 401: of_bsn_tlv_rate_limit */
    5,    /* 402: of_bsn_tlv_rate_unit */
    6,    /* 403: of_bsn_tlv_reference */
    12,   /* 404: of_bsn_tlv_reply_packets */
    12,   /* 405: of_bsn_tlv_request_packets */
    12,   /* 406: of_bsn_tlv_rx_bytes */
    12,   /* 407: of_bsn_tlv_rx_packets */
    8,    /* 408: of_bsn_tlv_sampling_rate */
    4,    /* 409: of_bsn_tlv_set_loopback_mode */
    5,    /* 410: of_bsn_tlv_status */
    4,    /* 411: of_bsn_tlv_strip_mpls_l2_on_ingress */
    4,    /* 412: of_bsn_tlv_strip_mpls_l3_on_ingress */
    4,    /* 413: of_bsn_tlv_strip_vlan_on_egress */
    8,    /* 414: of_bsn_tlv_sub_agent_id */
    6,    /* 415: of_bsn_tlv_tcp_dst */
    6,    /* 416: of_bsn_tlv_tcp_flags */
    6,    /* 417: of_bsn_tlv_tcp_src */
    6,    /* 418: of_bsn_tlv_ttl */
    12,   /* 419: of_bsn_tlv_tx_bytes */
    12,   /* 420: of_bsn_tlv_tx_packets */
    6,    /* 421: of_bsn_tlv_udf_anchor */
    6,    /* 422: of_bsn_tlv_udf_id */
    6,    /* 423: of_bsn_tlv_udf_length */
    6,    /* 424: of_bsn_tlv_udf_offset */
    6,    /* 425: of_bsn_tlv_udp_dst */
    6,    /* 426: of_bsn_tlv_udp_src */
    4,    /* 427: of_bsn_tlv_uint64_list */
    8,    /* 428: of_bsn_tlv_unicast_query_timeout */
    8,    /* 429: of_bsn_tlv_unicast_rate */
    8,    /* 430: of_bsn_tlv_unknown_multicast_rate */
    4,    /* 431: of_bsn_tlv_untagged */
    5,    /* 432: of_bsn_tlv_use_packet_state */
    6,    /* 433: of_bsn_tlv_vfi */
    8,    /* 434: of_bsn_tlv_vfp_class_id */
    4,    /* 435: of_bsn_tlv_vlan_mac_list */
    5,    /* 436: of_bsn_tlv_vlan_pcp */
    6,    /* 437: of_bsn_tlv_vlan_vid */
    6,    /* 438: of_bsn_tlv_vlan_vid_mask */
    8,    /* 439: of_bsn_tlv_vni */
    8,    /* 440: of_bsn_tlv_vpn_key */
    8,    /* 441: of_bsn_tlv_vrf */
    4,    /* 442: of_bsn_tlv_vxlan_egress_lag */
    8,    /* 443: of_bsn_vlan_counter_stats_entry */
    8,    /* 444: of_bsn_vlan_mac */
    4,    /* 445: of_bsn_vport */
    64,   /* 446: of_bsn_vport_l2gre */
    32,   /* 447: of_bsn_vport_q_in_q */
    8,    /* 448: of_bsn_vrf_counter_stats_entry */
    16,   /* 449: of_bucket */
    16,   /* 450: of_bucket_counter */
    4,    /* 451: of_bundle_prop */
    12,   /* 452: of_bundle_prop_experimenter */
    56,   /* 453: of_flow_stats_entry */
    8,    /* 454: of_group_desc_stats_entry */
    40,   /* 455: of_group_stats_entry */
    4,    /* 456: of_hello_elem */
    4,    /* 457: of_hello_elem_versionbitmap */
    4,    /* 458: of_instruction */
    8,    /* 459: of_instruction_apply_actions */
    16,   /* 460: of_instruction_bsn */
    16,   /* 461: of_instruction_bsn_arp_offload */
    16,   /* 462: of_instruction_bsn_auto_negotiation */
    16,   /* 463: of_instruction_bsn_deny */
    16,   /* 464: of_instruction_bsn_dhcp_offload */
    16,   /* 465: of_instruction_bsn_disable_l3 */
    -1,   /* 466: of_instruction_bsn_disable_split_horizon_check */
    16,   /* 467: of_instruction_bsn_disable_src_mac_check */
    16,   /* 468: of_instruction_bsn_disable_vlan_counters */
    16,   /* 469: of_instruction_bsn_hash_select */
    16,   /* 470: of_instruction_bsn_internal_priority */
    16,   /* 471: of_instruction_bsn_ndp_offload */
    16,   /* 472: of_instruction_bsn_packet_of_death */
    16,   /* 473: of_instruction_bsn_permit */
    16,   /* 474: of_instruction_bsn_prioritize_pdus */
    16,   /* 475: of_instruction_bsn_require_vlan_xlate */
    16,   /* 476: of_instruction_bsn_span_destination */
    8,    /* 477: of_instruction_clear_actions */
    8,    /* 478: of_instruction_experimenter */
    8,    /* 479: of_instruction_goto_table */
    4,    /* 480: of_instruction_id */
    4,    /* 481: of_instruction_id_apply_actions */
    12,   /* 482: of_instruction_id_bsn */
    12,   /* 483: of_instruction_id_bsn_arp_offload */
    12,   /* 484: of_instruction_id_bsn_auto_negotiation */
    12,   /* 485: of_instruction_id_bsn_deny */
    12,   /* 486: of_instruction_id_bsn_dhcp_offload */
    12,   /* 487: of_instruction_id_bsn_disable_l3 */
    -1,   /* 488: of_instruction_id_bsn_disable_split_horizon_check */
    12,   /* 489: of_instruction_id_bsn_disable_src_mac_check */
    12,   /* 490: of_instruction_id_bsn_disable_vlan_counters */
    12,   /* 491: of_instruction_id_bsn_hash_select */
    12,   /* 492: of_instruction_id_bsn_internal_priority */
    12,   /* 493: of_instruction_id_bsn_ndp_offload */
    12,   /* 494: of_instruction_id_bsn_packet_of_death */
    12,   /* 495: of_instruction_id_bsn_permit */
    12,   /* 496: of_instruction_id_bsn_prioritize_pdus */
    12,   /* 497: of_instruction_id_bsn_require_vlan_xlate */
    12,   /* 498: of_instruction_id_bsn_span_destination */
    4,    /* 499: of_instruction_id_clear_actions */
    8,    /* 500: of_instruction_id_experimenter */
    4,    /* 501: of_instruction_id_goto_table */
    4,    /* 502: of_instruction_id_meter */
    4,    /* 503: of_instruction_id_write_actions */
    4,    /* 504: of_instruction_id_write_metadata */
    8,    /* 505: of_instruction_meter */
    8,    /* 506: of_instruction_write_actions */
    24,   /* 507: of_instruction_write_metadata */
    -1,   /* 508: of_match_v1 */
    -1,   /* 509: of_match_v2 */
    4,    /* 510: of_match_v3 */
    4,    /* 511: of_meter_band */
    16,   /* 512: of_meter_band_drop */
    16,   /* 513: of_meter_band_dscp_remark */
    16,   /* 514: of_meter_band_experimenter */
    16,   /* 515: of_meter_band_stats */
    8,    /* 516: of_meter_config */
    16,   /* 517: of_meter_features */
    40,   /* 518: of_meter_stats */
    4,    /* 519: of_oxm */
    6,    /* 520: of_oxm_arp_op */
    8,    /* 521: of_oxm_arp_op_masked */
    10,   /* 522: of_oxm_arp_sha */
    16,   /* 523: of_oxm_arp_sha_masked */
    8,    /* 524: of_oxm_arp_spa */
    12,   /* 525: of_oxm_arp_spa_masked */
    10,   /* 526: of_oxm_arp_tha */
    16,   /* 527: of_oxm_arp_tha_masked */
    8,    /* 528: of_oxm_arp_tpa */
    12,   /* 529: of_oxm_arp_tpa_masked */
    8,    /* 530: of_oxm_bsn_egr_port_group_id */
    12,   /* 531: of_oxm_bsn_egr_port_group_id_masked */
    -1,   /* 532: of_oxm_bsn_global_vrf_allowed */
    -1,   /* 533: of_oxm_bsn_global_vrf_allowed_masked */
    20,   /* 534: of_oxm_bsn_in_ports_128 */
    36,   /* 535: of_oxm_bsn_in_ports_128_masked */
    68,   /* 536: of_oxm_bsn_in_ports_512 */
    132,  /* 537: of_oxm_bsn_in_ports_512_masked */
    8,    /* 538: of_oxm_bsn_ingress_port_group_id */
    12,   /* 539: of_oxm_bsn_ingress_port_group_id_masked */
    10,   /* 540: of_oxm_bsn_inner_eth_dst */
    16,   /* 541: of_oxm_bsn_inner_eth_dst_masked */
    10,   /* 542: of_oxm_bsn_inner_eth_src */
    16,   /* 543: of_oxm_bsn_inner_eth_src_masked */
    6,    /* 544: of_oxm_bsn_inner_vlan_vid */
    8,    /* 545: of_oxm_bsn_inner_vlan_vid_masked */
    5,    /* 546: of_oxm_bsn_ip_fragmentation */
    6,    /* 547: of_oxm_bsn_ip_fragmentation_masked */
    5,    /* 548: of_oxm_bsn_l2_cache_hit */
    6,    /* 549: of_oxm_bsn_l2_cache_hit_masked */
    -1,   /* 550: of_oxm_bsn_l3_dst_class_id */
    -1,   /* 551: of_oxm_bsn_l3_dst_class_id_masked */
    8,    /* 552: of_oxm_bsn_l3_interface_class_id */
    12,   /* 553: of_oxm_bsn_l3_interface_class_id_masked */
    8,    /* 554: of_oxm_bsn_l3_src_class_id */
    12,   /* 555: of_oxm_bsn_l3_src_class_id_masked */
    8,    /* 556: of_oxm_bsn_lag_id */
    12,   /* 557: of_oxm_bsn_lag_id_masked */
    6,    /* 558: of_oxm_bsn_tcp_flags */
    8,    /* 559: of_oxm_bsn_tcp_flags_masked */
    8,    /* 560: of_oxm_bsn_udf0 */
    12,   /* 561: of_oxm_bsn_udf0_masked */
    8,    /* 562: of_oxm_bsn_udf1 */
    12,   /* 563: of_oxm_bsn_udf1_masked */
    8,    /* 564: of_oxm_bsn_udf2 */
    12,   /* 565: of_oxm_bsn_udf2_masked */
    8,    /* 566: of_oxm_bsn_udf3 */
    12,   /* 567: of_oxm_bsn_udf3_masked */
    8,    /* 568: of_oxm_bsn_udf4 */
    12,   /* 569: of_oxm_bsn_udf4_masked */
    8,    /* 570: of_oxm_bsn_udf5 */
    12,   /* 571: of_oxm_bsn_udf5_masked */
    8,    /* 572: of_oxm_bsn_udf6 */
    12,   /* 573: of_oxm_bsn_udf6_masked */
    8,    /* 574: of_oxm_bsn_udf7 */
    12,   /* 575: of_oxm_bsn_udf7_masked */
    6,    /* 576: of_oxm_bsn_vfi */
    8,    /* 577: of_oxm_bsn_vfi_masked */
    8,    /* 578: of_oxm_bsn_vlan_xlate_port_group_id */
    12,   /* 579: of_oxm_bsn_vlan_xlate_port_group_id_masked */
    8,    /* 580: of_oxm_bsn_vrf */
    12,   /* 581: of_oxm_bsn_vrf_masked */
    8,    /* 582: of_oxm_bsn_vxlan_network_id */
    12,   /* 583: of_oxm_bsn_vxlan_network_id_masked */
    10,   /* 584: of_oxm_eth_dst */
    16,   /* 585: of_oxm_eth_dst_masked */
    10,   /* 586: of_oxm_eth_src */
    16,   /* 587: of_oxm_eth_src_masked */
    6,    /* 588: of_oxm_eth_type */
    8,    /* 589: of_oxm_eth_type_masked */
    5,    /* 590: of_oxm_icmpv4_code */
    6,    /* 591: of_oxm_icmpv4_code_masked */
    5,    /* 592: of_oxm_icmpv4_type */
    6,    /* 593: of_oxm_icmpv4_type_masked */
    5,    /* 594: of_oxm_icmpv6_code */
    6,    /* 595: of_oxm_icmpv6_code_masked */
    5,    /* 596: of_oxm_icmpv6_type */
    6,    /* 597: of_oxm_icmpv6_type_masked */
    8,    /* 598: of_oxm_in_phy_port */
    12,   /* 599: of_oxm_in_phy_port_masked */
    8,    /* 600: of_oxm_in_port */
    12,   /* 601: of_oxm_in_port_masked */
    5,    /* 602: of_oxm_ip_dscp */
    6,    /* 603: of_oxm_ip_dscp_masked */
    5,    /* 604: of_oxm_ip_ecn */
    6,    /* 605: of_oxm_ip_ecn_masked */
    5,    /* 606: of_oxm_ip_proto */
    6,    /* 607: of_oxm_ip_proto_masked */
    8,    /* 608: of_oxm_ipv4_dst */
    12,   /* 609: of_oxm_ipv4_dst_masked */
    8,    /* 610: of_oxm_ipv4_src */
    12,   /* 611: of_oxm_ipv4_src_masked */
    20,   /* 612: of_oxm_ipv6_dst */
    36,   /* 613: of_oxm_ipv6_dst_masked */
    6,    /* 614: of_oxm_ipv6_exthdr */
    8,    /* 615: of_oxm_ipv6_exthdr_masked */
    8,    /* 616: of_oxm_ipv6_flabel */
    12,   /* 617: of_oxm_ipv6_flabel_masked */
    10,   /* 618: of_oxm_ipv6_nd_sll */
    16,   /* 619: of_oxm_ipv6_nd_sll_masked */
    20,   /* 620: of_oxm_ipv6_nd_target */
    36,   /* 621: of_oxm_ipv6_nd_target_masked */
    10,   /* 622: of_oxm_ipv6_nd_tll */
    16,   /* 623: of_oxm_ipv6_nd_tll_masked */
    20,   /* 624: of_oxm_ipv6_src */
    36,   /* 625: of_oxm_ipv6_src_masked */
    12,   /* 626: of_oxm_metadata */
    20,   /* 627: of_oxm_metadata_masked */
    5,    /* 628: of_oxm_mpls_bos */
    6,    /* 629: of_oxm_mpls_bos_masked */
    8,    /* 630: of_oxm_mpls_label */
    12,   /* 631: of_oxm_mpls_label_masked */
    5,    /* 632: of_oxm_mpls_tc */
    6,    /* 633: of_oxm_mpls_tc_masked */
    10,   /* 634: of_oxm_ovs_tcp_flags */
    12,   /* 635: of_oxm_ovs_tcp_flags_masked */
    5,    /* 636: of_oxm_pbb_uca */
    6,    /* 637: of_oxm_pbb_uca_masked */
    6,    /* 638: of_oxm_sctp_dst */
    8,    /* 639: of_oxm_sctp_dst_masked */
    6,    /* 640: of_oxm_sctp_src */
    8,    /* 641: of_oxm_sctp_src_masked */
    6,    /* 642: of_oxm_tcp_dst */
    8,    /* 643: of_oxm_tcp_dst_masked */
    6,    /* 644: of_oxm_tcp_src */
    8,    /* 645: of_oxm_tcp_src_masked */
    12,   /* 646: of_oxm_tunnel_id */
    20,   /* 647: of_oxm_tunnel_id_masked */
    8,    /* 648: of_oxm_tunnel_ipv4_dst */
    12,   /* 649: of_oxm_tunnel_ipv4_dst_masked */
    8,    /* 650: of_oxm_tunnel_ipv4_src */
    12,   /* 651: of_oxm_tunnel_ipv4_src_masked */
    6,    /* 652: of_oxm_udp_dst */
    8,    /* 653: of_oxm_udp_dst_masked */
    6,    /* 654: of_oxm_udp_src */
    8,    /* 655: of_oxm_udp_src_masked */
    5,    /* 656: of_oxm_vlan_pcp */
    6,    /* 657: of_oxm_vlan_pcp_masked */
    6,    /* 658: of_oxm_vlan_vid */
    8,    /* 659: of_oxm_vlan_vid_masked */
    16,   /* 660: of_packet_queue */
    40,   /* 661: of_port_desc */
    4,    /* 662: of_port_desc_prop */
    12,   /* 663: of_port_desc_prop_bsn */
    20,   /* 664: of_port_desc_prop_bsn_generation_id */
    12,   /* 665: of_port_desc_prop_bsn_uplink */
    32,   /* 666: of_port_desc_prop_ethernet */
    8,    /* 667: of_port_desc_prop_experimenter */
    44,   /* 668: of_port_desc_prop_optical */
    4,    /* 669: of_port_mod_prop */
    8,    /* 670: of_port_mod_prop_ethernet */
    12,   /* 671: of_port_mod_prop_experimenter */
    24,   /* 672: of_port_mod_prop_optical */
    80,   /* 673: of_port_stats_entry */
    4,    /* 674: of_port_stats_prop */
    40,   /* 675: of_port_stats_prop_ethernet */
    12,   /* 676: of_port_stats_prop_experimenter */
    44,   /* 677: of_port_stats_prop_optical */
    16,   /* 678: of_queue_desc */
    4,    /* 679: of_queue_desc_prop */
    12,   /* 680: of_queue_desc_prop_bsn */
    12,   /* 681: of_queue_desc_prop_bsn_queue_name */
    12,   /* 682: of_queue_desc_prop_experimenter */
    8,    /* 683: of_queue_desc_prop_max_rate */
    8,    /* 684: of_queue_desc_prop_min_rate */
    8,    /* 685: of_queue_prop */
    16,   /* 686: of_queue_prop_experimenter */
    16,   /* 687: of_queue_prop_max_rate */
    16,   /* 688: of_queue_prop_min_rate */
    48,   /* 689: of_queue_stats_entry */
    4,    /* 690: of_queue_stats_prop */
    12,   /* 691: of_queue_stats_prop_experimenter */
    4,    /* 692: of_role_prop */
    12,   /* 693: of_role_prop_experimenter */
    8,    /* 694: of_table_desc */
    4,    /* 695: of_table_feature_prop */
    4,    /* 696: of_table_feature_prop_apply_actions */
    4,    /* 697: of_table_feature_prop_apply_actions_miss */
    4,    /* 698: of_table_feature_prop_apply_setfield */
    4,    /* 699: of_table_feature_prop_apply_setfield_miss */
    12,   /* 700: of_table_feature_prop_experimenter */
    12,   /* 701: of_table_feature_prop_experimenter_miss */
    4,    /* 702: of_table_feature_prop_instructions */
    4,    /* 703: of_table_feature_prop_instructions_miss */
    4,    /* 704: of_table_feature_prop_match */
    4,    /* 705: of_table_feature_prop_next_tables */
    4,    /* 706: of_table_feature_prop_next_tables_miss */
    4,    /* 707: of_table_feature_prop_table_sync_from */
    4,    /* 708: of_table_feature_prop_wildcards */
    4,    /* 709: of_table_feature_prop_write_actions */
    4,    /* 710: of_table_feature_prop_write_actions_miss */
    4,    /* 711: of_table_feature_prop_write_setfield */
    4,    /* 712: of_table_feature_prop_write_setfield_miss */
    64,   /* 713: of_table_features */
    4,    /* 714: of_table_mod_prop */
    8,    /* 715: of_table_mod_prop_eviction */
    12,   /* 716: of_table_mod_prop_experimenter */
    8,    /* 717: of_table_mod_prop_vacancy */
    24,   /* 718: of_table_stats_entry */
    4,    /* 719: of_uint32 */
    8,    /* 720: of_uint64 */
    1,    /* 721: of_uint8 */
    0,    /* 722: of_list_action */
    0,    /* 723: of_list_action_id */
    0,    /* 724: of_list_async_config_prop */
    0,    /* 725: of_list_bsn_controller_connection */
    0,    /* 726: of_list_bsn_debug_counter_desc_stats_entry */
    0,    /* 727: of_list_bsn_debug_counter_stats_entry */
    0,    /* 728: of_list_bsn_flow_checksum_bucket_stats_entry */
    0,    /* 729: of_list_bsn_generic_stats_entry */
    0,    /* 730: of_list_bsn_gentable_bucket_stats_entry */
    0,    /* 731: of_list_bsn_gentable_desc_stats_entry */
    0,    /* 732: of_list_bsn_gentable_entry_desc_stats_entry */
    0,    /* 733: of_list_bsn_gentable_entry_stats_entry */
    0,    /* 734: of_list_bsn_gentable_stats_entry */
    0,    /* 735: of_list_bsn_interface */
    0,    /* 736: of_list_bsn_lacp_stats_entry */
    0,    /* 737: of_list_bsn_port_counter_stats_entry */
    0,    /* 738: of_list_bsn_switch_pipeline_stats_entry */
    0,    /* 739: of_list_bsn_table_checksum_stats_entry */
    0,    /* 740: of_list_bsn_tlv */
    0,    /* 741: of_list_bsn_vlan_counter_stats_entry */
    0,    /* 742: of_list_bsn_vlan_mac */
    0,    /* 743: of_list_bsn_vrf_counter_stats_entry */
    0,    /* 744: of_list_bucket */
    0,    /* 745: of_list_bucket_counter */
    0,    /* 746: of_list_bundle_prop */
    0,    /* 747: of_list_flow_stats_entry */
    0,    /* 748: of_list_group_desc_stats_entry */
    0,    /* 749: of_list_group_stats_entry */
    0,    /* 750: of_list_hello_elem */
    0,    /* 751: of_list_instruction */
    0,    /* 752: of_list_instruction_id */
    0,    /* 753: of_list_meter_band */
    0,    /* 754: of_list_meter_band_stats */
    0,    /* 755: of_list_meter_config */
    0,    /* 756: of_list_meter_stats */
    0,    /* 757: of_list_oxm */
    -1,   /* 758: of_list_packet_queue */
    0,    /* 759: of_list_port_desc */
    0,    /* 760: of_list_port_desc_prop */
    0,    /* 761: of_list_port_mod_prop */
    0,    /* 762: of_list_port_stats_entry */
    0,    /* 763: of_list_port_stats_prop */
    0,    /* 764: of_list_queue_desc */
    0,    /* 765: of_list_queue_desc_prop */
    0,    /* 766: of_list_queue_prop */
    0,    /* 767: of_list_queue_stats_entry */
    0,    /* 768: of_list_queue_stats_prop */
    0,    /* 769: of_list_role_prop */
    0,    /* 770: of_list_table_desc */
    0,    /* 771: of_list_table_feature_prop */
    0,    /* 772: of_list_table_features */
    0,    /* 773: of_list_table_mod_prop */
    0,    /* 774: of_list_table_stats_entry */
    0,    /* 775: of_list_uint32 */
    0,    /* 776: of_list_uint64 */
    0     /* 777: of_list_uint8 */
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
