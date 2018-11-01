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
    -1,   /* 52: of_bsn_gentable_error */
    -1,   /* 53: of_bsn_gentable_set_buckets_size */
    -1,   /* 54: of_bsn_gentable_stats_reply */
    -1,   /* 55: of_bsn_gentable_stats_request */
    16,   /* 56: of_bsn_get_interfaces_reply */
    16,   /* 57: of_bsn_get_interfaces_request */
    24,   /* 58: of_bsn_get_ip_mask_reply */
    24,   /* 59: of_bsn_get_ip_mask_request */
    24,   /* 60: of_bsn_get_l2_table_reply */
    16,   /* 61: of_bsn_get_l2_table_request */
    20,   /* 62: of_bsn_get_mirroring_reply */
    20,   /* 63: of_bsn_get_mirroring_request */
    -1,   /* 64: of_bsn_get_switch_pipeline_reply */
    -1,   /* 65: of_bsn_get_switch_pipeline_request */
    16,   /* 66: of_bsn_header */
    24,   /* 67: of_bsn_hybrid_get_reply */
    16,   /* 68: of_bsn_hybrid_get_request */
    -1,   /* 69: of_bsn_image_desc_stats_reply */
    -1,   /* 70: of_bsn_image_desc_stats_request */
    -1,   /* 71: of_bsn_lacp_convergence_notif */
    -1,   /* 72: of_bsn_lacp_stats_reply */
    -1,   /* 73: of_bsn_lacp_stats_request */
    -1,   /* 74: of_bsn_log */
    -1,   /* 75: of_bsn_lua_command_reply */
    -1,   /* 76: of_bsn_lua_command_request */
    -1,   /* 77: of_bsn_lua_notification */
    -1,   /* 78: of_bsn_lua_upload */
    23,   /* 79: of_bsn_pdu_rx_reply */
    26,   /* 80: of_bsn_pdu_rx_request */
    19,   /* 81: of_bsn_pdu_rx_timeout */
    23,   /* 82: of_bsn_pdu_tx_reply */
    26,   /* 83: of_bsn_pdu_tx_request */
    -1,   /* 84: of_bsn_port_counter_stats_reply */
    -1,   /* 85: of_bsn_port_counter_stats_request */
    -1,   /* 86: of_bsn_role_status */
    -1,   /* 87: of_bsn_set_aux_cxns_reply */
    -1,   /* 88: of_bsn_set_aux_cxns_request */
    24,   /* 89: of_bsn_set_ip_mask */
    24,   /* 90: of_bsn_set_l2_table_reply */
    24,   /* 91: of_bsn_set_l2_table_request */
    -1,   /* 92: of_bsn_set_lacp_reply */
    -1,   /* 93: of_bsn_set_lacp_request */
    20,   /* 94: of_bsn_set_mirroring */
    20,   /* 95: of_bsn_set_pktin_suppression_reply */
    32,   /* 96: of_bsn_set_pktin_suppression_request */
    -1,   /* 97: of_bsn_set_switch_pipeline_reply */
    -1,   /* 98: of_bsn_set_switch_pipeline_request */
    20,   /* 99: of_bsn_shell_command */
    16,   /* 100: of_bsn_shell_output */
    20,   /* 101: of_bsn_shell_status */
    24,   /* 102: of_bsn_stats_reply */
    24,   /* 103: of_bsn_stats_request */
    -1,   /* 104: of_bsn_switch_pipeline_stats_reply */
    -1,   /* 105: of_bsn_switch_pipeline_stats_request */
    -1,   /* 106: of_bsn_table_checksum_stats_reply */
    -1,   /* 107: of_bsn_table_checksum_stats_request */
    -1,   /* 108: of_bsn_table_set_buckets_size */
    -1,   /* 109: of_bsn_takeover */
    -1,   /* 110: of_bsn_time_reply */
    -1,   /* 111: of_bsn_time_request */
    24,   /* 112: of_bsn_virtual_port_create_reply */
    20,   /* 113: of_bsn_virtual_port_create_request */
    20,   /* 114: of_bsn_virtual_port_remove_reply */
    20,   /* 115: of_bsn_virtual_port_remove_request */
    -1,   /* 116: of_bsn_vlan_counter_clear */
    -1,   /* 117: of_bsn_vlan_counter_stats_reply */
    -1,   /* 118: of_bsn_vlan_counter_stats_request */
    -1,   /* 119: of_bsn_vrf_counter_stats_reply */
    -1,   /* 120: of_bsn_vrf_counter_stats_request */
    -1,   /* 121: of_bundle_add_msg */
    -1,   /* 122: of_bundle_ctrl_msg */
    -1,   /* 123: of_bundle_failed_error_msg */
    1068, /* 124: of_desc_stats_reply */
    12,   /* 125: of_desc_stats_request */
    8,    /* 126: of_echo_reply */
    8,    /* 127: of_echo_request */
    10,   /* 128: of_error_msg */
    12,   /* 129: of_experimenter */
    -1,   /* 130: of_experimenter_error_msg */
    16,   /* 131: of_experimenter_stats_reply */
    16,   /* 132: of_experimenter_stats_request */
    32,   /* 133: of_features_reply */
    8,    /* 134: of_features_request */
    72,   /* 135: of_flow_add */
    72,   /* 136: of_flow_delete */
    72,   /* 137: of_flow_delete_strict */
    72,   /* 138: of_flow_mod */
    12,   /* 139: of_flow_mod_failed_error_msg */
    72,   /* 140: of_flow_modify */
    72,   /* 141: of_flow_modify_strict */
    -1,   /* 142: of_flow_monitor_failed_error_msg */
    88,   /* 143: of_flow_removed */
    12,   /* 144: of_flow_stats_reply */
    56,   /* 145: of_flow_stats_request */
    12,   /* 146: of_get_config_reply */
    8,    /* 147: of_get_config_request */
    -1,   /* 148: of_group_add */
    -1,   /* 149: of_group_delete */
    -1,   /* 150: of_group_desc_stats_reply */
    -1,   /* 151: of_group_desc_stats_request */
    -1,   /* 152: of_group_features_stats_reply */
    -1,   /* 153: of_group_features_stats_request */
    -1,   /* 154: of_group_mod */
    -1,   /* 155: of_group_mod_failed_error_msg */
    -1,   /* 156: of_group_modify */
    -1,   /* 157: of_group_stats_reply */
    -1,   /* 158: of_group_stats_request */
    8,    /* 159: of_header */
    8,    /* 160: of_hello */
    12,   /* 161: of_hello_failed_error_msg */
    -1,   /* 162: of_meter_config_stats_reply */
    -1,   /* 163: of_meter_config_stats_request */
    -1,   /* 164: of_meter_features_stats_reply */
    -1,   /* 165: of_meter_features_stats_request */
    -1,   /* 166: of_meter_mod */
    -1,   /* 167: of_meter_mod_failed_error_msg */
    -1,   /* 168: of_meter_stats_reply */
    -1,   /* 169: of_meter_stats_request */
    20,   /* 170: of_nicira_controller_role_reply */
    20,   /* 171: of_nicira_controller_role_request */
    16,   /* 172: of_nicira_header */
    18,   /* 173: of_packet_in */
    16,   /* 174: of_packet_out */
    -1,   /* 175: of_port_desc_stats_reply */
    -1,   /* 176: of_port_desc_stats_request */
    32,   /* 177: of_port_mod */
    12,   /* 178: of_port_mod_failed_error_msg */
    12,   /* 179: of_port_stats_reply */
    20,   /* 180: of_port_stats_request */
    64,   /* 181: of_port_status */
    -1,   /* 182: of_queue_desc_stats_reply */
    -1,   /* 183: of_queue_desc_stats_request */
    16,   /* 184: of_queue_get_config_reply */
    12,   /* 185: of_queue_get_config_request */
    12,   /* 186: of_queue_op_failed_error_msg */
    12,   /* 187: of_queue_stats_reply */
    20,   /* 188: of_queue_stats_request */
    -1,   /* 189: of_requestforward */
    -1,   /* 190: of_role_reply */
    -1,   /* 191: of_role_request */
    -1,   /* 192: of_role_request_failed_error_msg */
    -1,   /* 193: of_role_status */
    12,   /* 194: of_set_config */
    12,   /* 195: of_stats_reply */
    12,   /* 196: of_stats_request */
    -1,   /* 197: of_switch_config_failed_error_msg */
    -1,   /* 198: of_table_desc_stats_reply */
    -1,   /* 199: of_table_desc_stats_request */
    -1,   /* 200: of_table_features_failed_error_msg */
    -1,   /* 201: of_table_features_stats_reply */
    -1,   /* 202: of_table_features_stats_request */
    16,   /* 203: of_table_mod */
    -1,   /* 204: of_table_mod_failed_error_msg */
    12,   /* 205: of_table_stats_reply */
    12,   /* 206: of_table_stats_request */
    -1,   /* 207: of_table_status */
    8,    /* 208: of_action */
    16,   /* 209: of_action_bsn */
    28,   /* 210: of_action_bsn_checksum */
    -1,   /* 211: of_action_bsn_gentable */
    24,   /* 212: of_action_bsn_mirror */
    16,   /* 213: of_action_bsn_set_tunnel_dst */
    -1,   /* 214: of_action_copy_ttl_in */
    -1,   /* 215: of_action_copy_ttl_out */
    -1,   /* 216: of_action_dec_mpls_ttl */
    -1,   /* 217: of_action_dec_nw_ttl */
    16,   /* 218: of_action_enqueue */
    8,    /* 219: of_action_experimenter */
    -1,   /* 220: of_action_group */
    -1,   /* 221: of_action_id */
    -1,   /* 222: of_action_id_bsn */
    -1,   /* 223: of_action_id_bsn_checksum */
    -1,   /* 224: of_action_id_bsn_gentable */
    -1,   /* 225: of_action_id_bsn_mirror */
    -1,   /* 226: of_action_id_bsn_set_tunnel_dst */
    -1,   /* 227: of_action_id_copy_ttl_in */
    -1,   /* 228: of_action_id_copy_ttl_out */
    -1,   /* 229: of_action_id_dec_mpls_ttl */
    -1,   /* 230: of_action_id_dec_nw_ttl */
    -1,   /* 231: of_action_id_experimenter */
    -1,   /* 232: of_action_id_group */
    -1,   /* 233: of_action_id_nicira */
    -1,   /* 234: of_action_id_nicira_dec_ttl */
    -1,   /* 235: of_action_id_output */
    -1,   /* 236: of_action_id_pop_mpls */
    -1,   /* 237: of_action_id_pop_pbb */
    -1,   /* 238: of_action_id_pop_vlan */
    -1,   /* 239: of_action_id_push_mpls */
    -1,   /* 240: of_action_id_push_pbb */
    -1,   /* 241: of_action_id_push_vlan */
    -1,   /* 242: of_action_id_set_field */
    -1,   /* 243: of_action_id_set_mpls_ttl */
    -1,   /* 244: of_action_id_set_nw_ttl */
    -1,   /* 245: of_action_id_set_queue */
    16,   /* 246: of_action_nicira */
    16,   /* 247: of_action_nicira_dec_ttl */
    8,    /* 248: of_action_output */
    -1,   /* 249: of_action_pop_mpls */
    -1,   /* 250: of_action_pop_pbb */
    -1,   /* 251: of_action_pop_vlan */
    -1,   /* 252: of_action_push_mpls */
    -1,   /* 253: of_action_push_pbb */
    -1,   /* 254: of_action_push_vlan */
    16,   /* 255: of_action_set_dl_dst */
    16,   /* 256: of_action_set_dl_src */
    -1,   /* 257: of_action_set_field */
    -1,   /* 258: of_action_set_mpls_label */
    -1,   /* 259: of_action_set_mpls_tc */
    -1,   /* 260: of_action_set_mpls_ttl */
    8,    /* 261: of_action_set_nw_dst */
    -1,   /* 262: of_action_set_nw_ecn */
    8,    /* 263: of_action_set_nw_src */
    8,    /* 264: of_action_set_nw_tos */
    -1,   /* 265: of_action_set_nw_ttl */
    -1,   /* 266: of_action_set_queue */
    8,    /* 267: of_action_set_tp_dst */
    8,    /* 268: of_action_set_tp_src */
    8,    /* 269: of_action_set_vlan_pcp */
    8,    /* 270: of_action_set_vlan_vid */
    8,    /* 271: of_action_strip_vlan */
    -1,   /* 272: of_async_config_prop */
    -1,   /* 273: of_async_config_prop_experimenter_master */
    -1,   /* 274: of_async_config_prop_experimenter_slave */
    -1,   /* 275: of_async_config_prop_flow_removed_master */
    -1,   /* 276: of_async_config_prop_flow_removed_slave */
    -1,   /* 277: of_async_config_prop_packet_in_master */
    -1,   /* 278: of_async_config_prop_packet_in_slave */
    -1,   /* 279: of_async_config_prop_port_status_master */
    -1,   /* 280: of_async_config_prop_port_status_slave */
    -1,   /* 281: of_async_config_prop_requestforward_master */
    -1,   /* 282: of_async_config_prop_requestforward_slave */
    -1,   /* 283: of_async_config_prop_role_status_master */
    -1,   /* 284: of_async_config_prop_role_status_slave */
    -1,   /* 285: of_async_config_prop_table_status_master */
    -1,   /* 286: of_async_config_prop_table_status_slave */
    -1,   /* 287: of_bsn_controller_connection */
    -1,   /* 288: of_bsn_debug_counter_desc_stats_entry */
    -1,   /* 289: of_bsn_debug_counter_stats_entry */
    -1,   /* 290: of_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 291: of_bsn_generic_stats_entry */
    -1,   /* 292: of_bsn_gentable_bucket_stats_entry */
    -1,   /* 293: of_bsn_gentable_desc_stats_entry */
    -1,   /* 294: of_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 295: of_bsn_gentable_entry_stats_entry */
    -1,   /* 296: of_bsn_gentable_stats_entry */
    32,   /* 297: of_bsn_interface */
    -1,   /* 298: of_bsn_lacp_stats_entry */
    -1,   /* 299: of_bsn_port_counter_stats_entry */
    -1,   /* 300: of_bsn_switch_pipeline_stats_entry */
    -1,   /* 301: of_bsn_table_checksum_stats_entry */
    -1,   /* 302: of_bsn_tlv */
    -1,   /* 303: of_bsn_tlv_actor_key */
    -1,   /* 304: of_bsn_tlv_actor_port_num */
    -1,   /* 305: of_bsn_tlv_actor_port_priority */
    -1,   /* 306: of_bsn_tlv_actor_state */
    -1,   /* 307: of_bsn_tlv_actor_system_mac */
    -1,   /* 308: of_bsn_tlv_actor_system_priority */
    -1,   /* 309: of_bsn_tlv_anchor */
    -1,   /* 310: of_bsn_tlv_apply_bytes */
    -1,   /* 311: of_bsn_tlv_apply_packets */
    -1,   /* 312: of_bsn_tlv_auto_negotiation */
    -1,   /* 313: of_bsn_tlv_bfd_endpoint */
    -1,   /* 314: of_bsn_tlv_bfd_state */
    -1,   /* 315: of_bsn_tlv_broadcast_query_timeout */
    -1,   /* 316: of_bsn_tlv_broadcast_rate */
    -1,   /* 317: of_bsn_tlv_bucket */
    -1,   /* 318: of_bsn_tlv_circuit_id */
    -1,   /* 319: of_bsn_tlv_convergence_status */
    -1,   /* 320: of_bsn_tlv_cpu_lag */
    -1,   /* 321: of_bsn_tlv_crc_enabled */
    -1,   /* 322: of_bsn_tlv_data */
    -1,   /* 323: of_bsn_tlv_data_mask */
    -1,   /* 324: of_bsn_tlv_decap */
    -1,   /* 325: of_bsn_tlv_disable_src_mac_check */
    -1,   /* 326: of_bsn_tlv_drop */
    -1,   /* 327: of_bsn_tlv_dscp */
    -1,   /* 328: of_bsn_tlv_ecn */
    -1,   /* 329: of_bsn_tlv_egress_only */
    -1,   /* 330: of_bsn_tlv_egress_port_group_id */
    -1,   /* 331: of_bsn_tlv_encap */
    -1,   /* 332: of_bsn_tlv_enhanced_hash_capability */
    -1,   /* 333: of_bsn_tlv_eth_dst */
    -1,   /* 334: of_bsn_tlv_eth_src */
    -1,   /* 335: of_bsn_tlv_eth_type */
    -1,   /* 336: of_bsn_tlv_external_gateway_ip */
    -1,   /* 337: of_bsn_tlv_external_gateway_mac */
    -1,   /* 338: of_bsn_tlv_external_ip */
    -1,   /* 339: of_bsn_tlv_external_mac */
    -1,   /* 340: of_bsn_tlv_external_netmask */
    -1,   /* 341: of_bsn_tlv_fabric_port_role */
    -1,   /* 342: of_bsn_tlv_flood */
    -1,   /* 343: of_bsn_tlv_flow_classifier */
    -1,   /* 344: of_bsn_tlv_flow_classify */
    -1,   /* 345: of_bsn_tlv_flow_identifier */
    -1,   /* 346: of_bsn_tlv_force_link_up */
    -1,   /* 347: of_bsn_tlv_forward_error_correction */
    -1,   /* 348: of_bsn_tlv_generation_id */
    -1,   /* 349: of_bsn_tlv_hash_algorithm */
    -1,   /* 350: of_bsn_tlv_hash_gtp_header_match */
    -1,   /* 351: of_bsn_tlv_hash_gtp_port_match */
    -1,   /* 352: of_bsn_tlv_hash_packet_field */
    -1,   /* 353: of_bsn_tlv_hash_packet_type */
    -1,   /* 354: of_bsn_tlv_hash_seed */
    -1,   /* 355: of_bsn_tlv_hash_type */
    -1,   /* 356: of_bsn_tlv_header_size */
    -1,   /* 357: of_bsn_tlv_icmp_code */
    -1,   /* 358: of_bsn_tlv_icmp_id */
    -1,   /* 359: of_bsn_tlv_icmp_type */
    -1,   /* 360: of_bsn_tlv_icmpv6_chksum */
    -1,   /* 361: of_bsn_tlv_identifier */
    -1,   /* 362: of_bsn_tlv_idle_notification */
    -1,   /* 363: of_bsn_tlv_idle_time */
    -1,   /* 364: of_bsn_tlv_idle_timeout */
    -1,   /* 365: of_bsn_tlv_igmp_snooping */
    -1,   /* 366: of_bsn_tlv_ingress_port_group_id */
    -1,   /* 367: of_bsn_tlv_internal_gateway_mac */
    -1,   /* 368: of_bsn_tlv_internal_mac */
    -1,   /* 369: of_bsn_tlv_interval */
    -1,   /* 370: of_bsn_tlv_ip_proto */
    -1,   /* 371: of_bsn_tlv_ip_tunnel_type */
    -1,   /* 372: of_bsn_tlv_ipv4 */
    -1,   /* 373: of_bsn_tlv_ipv4_dst */
    -1,   /* 374: of_bsn_tlv_ipv4_netmask */
    -1,   /* 375: of_bsn_tlv_ipv4_src */
    -1,   /* 376: of_bsn_tlv_ipv6 */
    -1,   /* 377: of_bsn_tlv_ipv6_dst */
    -1,   /* 378: of_bsn_tlv_ipv6_prefix */
    -1,   /* 379: of_bsn_tlv_ipv6_src */
    -1,   /* 380: of_bsn_tlv_known_multicast_rate */
    -1,   /* 381: of_bsn_tlv_l2_multicast_lookup */
    -1,   /* 382: of_bsn_tlv_l3 */
    -1,   /* 383: of_bsn_tlv_l3_dst_class_id */
    -1,   /* 384: of_bsn_tlv_l3_interface_class_id */
    -1,   /* 385: of_bsn_tlv_l3_src_class_id */
    -1,   /* 386: of_bsn_tlv_lag_options */
    -1,   /* 387: of_bsn_tlv_loopback_mode */
    -1,   /* 388: of_bsn_tlv_loopback_port */
    -1,   /* 389: of_bsn_tlv_lr_all_enabled */
    -1,   /* 390: of_bsn_tlv_mac */
    -1,   /* 391: of_bsn_tlv_mac_mask */
    -1,   /* 392: of_bsn_tlv_mcg_type_vxlan */
    -1,   /* 393: of_bsn_tlv_miss_packets */
    -1,   /* 394: of_bsn_tlv_mpls_control_word */
    -1,   /* 395: of_bsn_tlv_mpls_label */
    -1,   /* 396: of_bsn_tlv_mpls_sequenced */
    -1,   /* 397: of_bsn_tlv_multicast_interface_id */
    -1,   /* 398: of_bsn_tlv_multicast_packet */
    -1,   /* 399: of_bsn_tlv_multiplier */
    -1,   /* 400: of_bsn_tlv_name */
    -1,   /* 401: of_bsn_tlv_ndp_offload */
    -1,   /* 402: of_bsn_tlv_ndp_static */
    -1,   /* 403: of_bsn_tlv_negate */
    -1,   /* 404: of_bsn_tlv_next_hop_ipv4 */
    -1,   /* 405: of_bsn_tlv_next_hop_mac */
    -1,   /* 406: of_bsn_tlv_nexthop_type_vxlan */
    -1,   /* 407: of_bsn_tlv_no_arp_response */
    -1,   /* 408: of_bsn_tlv_no_ns_response */
    -1,   /* 409: of_bsn_tlv_offset */
    -1,   /* 410: of_bsn_tlv_optics_always_enabled */
    -1,   /* 411: of_bsn_tlv_outer_src_mac */
    -1,   /* 412: of_bsn_tlv_parent_port */
    -1,   /* 413: of_bsn_tlv_partner_key */
    -1,   /* 414: of_bsn_tlv_partner_port_num */
    -1,   /* 415: of_bsn_tlv_partner_port_priority */
    -1,   /* 416: of_bsn_tlv_partner_state */
    -1,   /* 417: of_bsn_tlv_partner_system_mac */
    -1,   /* 418: of_bsn_tlv_partner_system_priority */
    -1,   /* 419: of_bsn_tlv_passive */
    -1,   /* 420: of_bsn_tlv_pdua_rx_instance */
    -1,   /* 421: of_bsn_tlv_pim_dr */
    -1,   /* 422: of_bsn_tlv_pim_hello_flood */
    -1,   /* 423: of_bsn_tlv_port */
    -1,   /* 424: of_bsn_tlv_port_mode */
    -1,   /* 425: of_bsn_tlv_port_speed_gbps */
    -1,   /* 426: of_bsn_tlv_port_usage */
    -1,   /* 427: of_bsn_tlv_port_vxlan_mode */
    -1,   /* 428: of_bsn_tlv_priority */
    -1,   /* 429: of_bsn_tlv_push_vlan_on_egress */
    -1,   /* 430: of_bsn_tlv_push_vlan_on_ingress */
    -1,   /* 431: of_bsn_tlv_qos_priority */
    -1,   /* 432: of_bsn_tlv_queue_id */
    -1,   /* 433: of_bsn_tlv_queue_weight */
    -1,   /* 434: of_bsn_tlv_rate_limit */
    -1,   /* 435: of_bsn_tlv_rate_unit */
    -1,   /* 436: of_bsn_tlv_record_packets */
    -1,   /* 437: of_bsn_tlv_reference */
    -1,   /* 438: of_bsn_tlv_reply_packets */
    -1,   /* 439: of_bsn_tlv_request_packets */
    -1,   /* 440: of_bsn_tlv_rest_server */
    -1,   /* 441: of_bsn_tlv_routing_param */
    -1,   /* 442: of_bsn_tlv_rx_bytes */
    -1,   /* 443: of_bsn_tlv_rx_packets */
    -1,   /* 444: of_bsn_tlv_sampling_rate */
    -1,   /* 445: of_bsn_tlv_set_loopback_mode */
    -1,   /* 446: of_bsn_tlv_status */
    -1,   /* 447: of_bsn_tlv_strip_mpls_l2_on_ingress */
    -1,   /* 448: of_bsn_tlv_strip_mpls_l3_on_ingress */
    -1,   /* 449: of_bsn_tlv_strip_vlan_on_egress */
    -1,   /* 450: of_bsn_tlv_sub_agent_id */
    -1,   /* 451: of_bsn_tlv_tcp_dst */
    -1,   /* 452: of_bsn_tlv_tcp_flags */
    -1,   /* 453: of_bsn_tlv_tcp_src */
    -1,   /* 454: of_bsn_tlv_timestamp */
    -1,   /* 455: of_bsn_tlv_ttl */
    -1,   /* 456: of_bsn_tlv_tunnel_capability */
    -1,   /* 457: of_bsn_tlv_tx_bytes */
    -1,   /* 458: of_bsn_tlv_tx_packets */
    -1,   /* 459: of_bsn_tlv_udf_anchor */
    -1,   /* 460: of_bsn_tlv_udf_capability */
    -1,   /* 461: of_bsn_tlv_udf_id */
    -1,   /* 462: of_bsn_tlv_udf_length */
    -1,   /* 463: of_bsn_tlv_udf_offset */
    -1,   /* 464: of_bsn_tlv_udp_dst */
    -1,   /* 465: of_bsn_tlv_udp_src */
    -1,   /* 466: of_bsn_tlv_uint32 */
    -1,   /* 467: of_bsn_tlv_uint64_list */
    -1,   /* 468: of_bsn_tlv_unicast_query_timeout */
    -1,   /* 469: of_bsn_tlv_unicast_rate */
    -1,   /* 470: of_bsn_tlv_unknown_multicast_rate */
    -1,   /* 471: of_bsn_tlv_untagged */
    -1,   /* 472: of_bsn_tlv_upgrade */
    -1,   /* 473: of_bsn_tlv_uri_scheme */
    -1,   /* 474: of_bsn_tlv_use_packet_state */
    -1,   /* 475: of_bsn_tlv_user_configured */
    -1,   /* 476: of_bsn_tlv_vfi */
    -1,   /* 477: of_bsn_tlv_vfp_class_id */
    -1,   /* 478: of_bsn_tlv_virtual */
    -1,   /* 479: of_bsn_tlv_vlan_mac_list */
    -1,   /* 480: of_bsn_tlv_vlan_pcp */
    -1,   /* 481: of_bsn_tlv_vlan_vid */
    -1,   /* 482: of_bsn_tlv_vlan_vid_mask */
    -1,   /* 483: of_bsn_tlv_vni */
    -1,   /* 484: of_bsn_tlv_vpn_key */
    -1,   /* 485: of_bsn_tlv_vrf */
    -1,   /* 486: of_bsn_tlv_vxlan_egress_lag */
    -1,   /* 487: of_bsn_vlan_counter_stats_entry */
    -1,   /* 488: of_bsn_vlan_mac */
    4,    /* 489: of_bsn_vport */
    60,   /* 490: of_bsn_vport_l2gre */
    32,   /* 491: of_bsn_vport_q_in_q */
    -1,   /* 492: of_bsn_vrf_counter_stats_entry */
    -1,   /* 493: of_bucket */
    -1,   /* 494: of_bucket_counter */
    -1,   /* 495: of_bundle_prop */
    -1,   /* 496: of_bundle_prop_experimenter */
    88,   /* 497: of_flow_stats_entry */
    -1,   /* 498: of_group_desc_stats_entry */
    -1,   /* 499: of_group_stats_entry */
    -1,   /* 500: of_hello_elem */
    -1,   /* 501: of_hello_elem_versionbitmap */
    -1,   /* 502: of_instruction */
    -1,   /* 503: of_instruction_apply_actions */
    -1,   /* 504: of_instruction_bsn */
    -1,   /* 505: of_instruction_bsn_arp_offload */
    -1,   /* 506: of_instruction_bsn_auto_negotiation */
    -1,   /* 507: of_instruction_bsn_deny */
    -1,   /* 508: of_instruction_bsn_dhcp_offload */
    -1,   /* 509: of_instruction_bsn_directed_broadcast */
    -1,   /* 510: of_instruction_bsn_disable_l3 */
    -1,   /* 511: of_instruction_bsn_disable_split_horizon_check */
    -1,   /* 512: of_instruction_bsn_disable_src_mac_check */
    -1,   /* 513: of_instruction_bsn_disable_vlan_counters */
    -1,   /* 514: of_instruction_bsn_hash_select */
    -1,   /* 515: of_instruction_bsn_internal_priority */
    -1,   /* 516: of_instruction_bsn_ndp_offload */
    -1,   /* 517: of_instruction_bsn_packet_of_death */
    -1,   /* 518: of_instruction_bsn_permit */
    -1,   /* 519: of_instruction_bsn_prioritize_pdus */
    -1,   /* 520: of_instruction_bsn_require_vlan_xlate */
    -1,   /* 521: of_instruction_bsn_span_destination */
    -1,   /* 522: of_instruction_clear_actions */
    -1,   /* 523: of_instruction_experimenter */
    -1,   /* 524: of_instruction_goto_table */
    -1,   /* 525: of_instruction_id */
    -1,   /* 526: of_instruction_id_apply_actions */
    -1,   /* 527: of_instruction_id_bsn */
    -1,   /* 528: of_instruction_id_bsn_arp_offload */
    -1,   /* 529: of_instruction_id_bsn_auto_negotiation */
    -1,   /* 530: of_instruction_id_bsn_deny */
    -1,   /* 531: of_instruction_id_bsn_dhcp_offload */
    -1,   /* 532: of_instruction_id_bsn_directed_broadcast */
    -1,   /* 533: of_instruction_id_bsn_disable_l3 */
    -1,   /* 534: of_instruction_id_bsn_disable_split_horizon_check */
    -1,   /* 535: of_instruction_id_bsn_disable_src_mac_check */
    -1,   /* 536: of_instruction_id_bsn_disable_vlan_counters */
    -1,   /* 537: of_instruction_id_bsn_hash_select */
    -1,   /* 538: of_instruction_id_bsn_internal_priority */
    -1,   /* 539: of_instruction_id_bsn_ndp_offload */
    -1,   /* 540: of_instruction_id_bsn_packet_of_death */
    -1,   /* 541: of_instruction_id_bsn_permit */
    -1,   /* 542: of_instruction_id_bsn_prioritize_pdus */
    -1,   /* 543: of_instruction_id_bsn_require_vlan_xlate */
    -1,   /* 544: of_instruction_id_bsn_span_destination */
    -1,   /* 545: of_instruction_id_clear_actions */
    -1,   /* 546: of_instruction_id_experimenter */
    -1,   /* 547: of_instruction_id_goto_table */
    -1,   /* 548: of_instruction_id_meter */
    -1,   /* 549: of_instruction_id_write_actions */
    -1,   /* 550: of_instruction_id_write_metadata */
    -1,   /* 551: of_instruction_meter */
    -1,   /* 552: of_instruction_write_actions */
    -1,   /* 553: of_instruction_write_metadata */
    40,   /* 554: of_match_v1 */
    -1,   /* 555: of_match_v2 */
    -1,   /* 556: of_match_v3 */
    -1,   /* 557: of_meter_band */
    -1,   /* 558: of_meter_band_drop */
    -1,   /* 559: of_meter_band_dscp_remark */
    -1,   /* 560: of_meter_band_experimenter */
    -1,   /* 561: of_meter_band_stats */
    -1,   /* 562: of_meter_config */
    -1,   /* 563: of_meter_features */
    -1,   /* 564: of_meter_stats */
    -1,   /* 565: of_oxm */
    -1,   /* 566: of_oxm_arp_op */
    -1,   /* 567: of_oxm_arp_op_masked */
    -1,   /* 568: of_oxm_arp_sha */
    -1,   /* 569: of_oxm_arp_sha_masked */
    -1,   /* 570: of_oxm_arp_spa */
    -1,   /* 571: of_oxm_arp_spa_masked */
    -1,   /* 572: of_oxm_arp_tha */
    -1,   /* 573: of_oxm_arp_tha_masked */
    -1,   /* 574: of_oxm_arp_tpa */
    -1,   /* 575: of_oxm_arp_tpa_masked */
    -1,   /* 576: of_oxm_bsn_egr_port_group_id */
    -1,   /* 577: of_oxm_bsn_egr_port_group_id_masked */
    -1,   /* 578: of_oxm_bsn_global_vrf_allowed */
    -1,   /* 579: of_oxm_bsn_global_vrf_allowed_masked */
    -1,   /* 580: of_oxm_bsn_ifp_class_id */
    -1,   /* 581: of_oxm_bsn_ifp_class_id_masked */
    -1,   /* 582: of_oxm_bsn_in_ports_128 */
    -1,   /* 583: of_oxm_bsn_in_ports_128_masked */
    -1,   /* 584: of_oxm_bsn_in_ports_512 */
    -1,   /* 585: of_oxm_bsn_in_ports_512_masked */
    -1,   /* 586: of_oxm_bsn_ingress_port_group_id */
    -1,   /* 587: of_oxm_bsn_ingress_port_group_id_masked */
    -1,   /* 588: of_oxm_bsn_inner_eth_dst */
    -1,   /* 589: of_oxm_bsn_inner_eth_dst_masked */
    -1,   /* 590: of_oxm_bsn_inner_eth_src */
    -1,   /* 591: of_oxm_bsn_inner_eth_src_masked */
    -1,   /* 592: of_oxm_bsn_inner_vlan_vid */
    -1,   /* 593: of_oxm_bsn_inner_vlan_vid_masked */
    -1,   /* 594: of_oxm_bsn_ip_fragmentation */
    -1,   /* 595: of_oxm_bsn_ip_fragmentation_masked */
    -1,   /* 596: of_oxm_bsn_l2_cache_hit */
    -1,   /* 597: of_oxm_bsn_l2_cache_hit_masked */
    -1,   /* 598: of_oxm_bsn_l3_dst_class_id */
    -1,   /* 599: of_oxm_bsn_l3_dst_class_id_masked */
    -1,   /* 600: of_oxm_bsn_l3_interface_class_id */
    -1,   /* 601: of_oxm_bsn_l3_interface_class_id_masked */
    -1,   /* 602: of_oxm_bsn_l3_src_class_id */
    -1,   /* 603: of_oxm_bsn_l3_src_class_id_masked */
    -1,   /* 604: of_oxm_bsn_lag_id */
    -1,   /* 605: of_oxm_bsn_lag_id_masked */
    -1,   /* 606: of_oxm_bsn_tcp_flags */
    -1,   /* 607: of_oxm_bsn_tcp_flags_masked */
    -1,   /* 608: of_oxm_bsn_udf0 */
    -1,   /* 609: of_oxm_bsn_udf0_masked */
    -1,   /* 610: of_oxm_bsn_udf1 */
    -1,   /* 611: of_oxm_bsn_udf1_masked */
    -1,   /* 612: of_oxm_bsn_udf2 */
    -1,   /* 613: of_oxm_bsn_udf2_masked */
    -1,   /* 614: of_oxm_bsn_udf3 */
    -1,   /* 615: of_oxm_bsn_udf3_masked */
    -1,   /* 616: of_oxm_bsn_udf4 */
    -1,   /* 617: of_oxm_bsn_udf4_masked */
    -1,   /* 618: of_oxm_bsn_udf5 */
    -1,   /* 619: of_oxm_bsn_udf5_masked */
    -1,   /* 620: of_oxm_bsn_udf6 */
    -1,   /* 621: of_oxm_bsn_udf6_masked */
    -1,   /* 622: of_oxm_bsn_udf7 */
    -1,   /* 623: of_oxm_bsn_udf7_masked */
    -1,   /* 624: of_oxm_bsn_vfi */
    -1,   /* 625: of_oxm_bsn_vfi_masked */
    -1,   /* 626: of_oxm_bsn_vlan_xlate_port_group_id */
    -1,   /* 627: of_oxm_bsn_vlan_xlate_port_group_id_masked */
    -1,   /* 628: of_oxm_bsn_vrf */
    -1,   /* 629: of_oxm_bsn_vrf_masked */
    -1,   /* 630: of_oxm_bsn_vxlan_network_id */
    -1,   /* 631: of_oxm_bsn_vxlan_network_id_masked */
    -1,   /* 632: of_oxm_conn_tracking_ipv6_dst */
    -1,   /* 633: of_oxm_conn_tracking_ipv6_dst_masked */
    -1,   /* 634: of_oxm_conn_tracking_ipv6_src */
    -1,   /* 635: of_oxm_conn_tracking_ipv6_src_masked */
    -1,   /* 636: of_oxm_conn_tracking_label */
    -1,   /* 637: of_oxm_conn_tracking_label_masked */
    -1,   /* 638: of_oxm_conn_tracking_mark */
    -1,   /* 639: of_oxm_conn_tracking_mark_masked */
    -1,   /* 640: of_oxm_conn_tracking_nw_dst */
    -1,   /* 641: of_oxm_conn_tracking_nw_dst_masked */
    -1,   /* 642: of_oxm_conn_tracking_nw_proto */
    -1,   /* 643: of_oxm_conn_tracking_nw_proto_masked */
    -1,   /* 644: of_oxm_conn_tracking_nw_src */
    -1,   /* 645: of_oxm_conn_tracking_nw_src_masked */
    -1,   /* 646: of_oxm_conn_tracking_state */
    -1,   /* 647: of_oxm_conn_tracking_state_masked */
    -1,   /* 648: of_oxm_conn_tracking_tp_dst */
    -1,   /* 649: of_oxm_conn_tracking_tp_dst_masked */
    -1,   /* 650: of_oxm_conn_tracking_tp_src */
    -1,   /* 651: of_oxm_conn_tracking_tp_src_masked */
    -1,   /* 652: of_oxm_conn_tracking_zone */
    -1,   /* 653: of_oxm_conn_tracking_zone_masked */
    -1,   /* 654: of_oxm_eth_dst */
    -1,   /* 655: of_oxm_eth_dst_masked */
    -1,   /* 656: of_oxm_eth_src */
    -1,   /* 657: of_oxm_eth_src_masked */
    -1,   /* 658: of_oxm_eth_type */
    -1,   /* 659: of_oxm_eth_type_masked */
    -1,   /* 660: of_oxm_icmpv4_code */
    -1,   /* 661: of_oxm_icmpv4_code_masked */
    -1,   /* 662: of_oxm_icmpv4_type */
    -1,   /* 663: of_oxm_icmpv4_type_masked */
    -1,   /* 664: of_oxm_icmpv6_code */
    -1,   /* 665: of_oxm_icmpv6_code_masked */
    -1,   /* 666: of_oxm_icmpv6_type */
    -1,   /* 667: of_oxm_icmpv6_type_masked */
    -1,   /* 668: of_oxm_in_phy_port */
    -1,   /* 669: of_oxm_in_phy_port_masked */
    -1,   /* 670: of_oxm_in_port */
    -1,   /* 671: of_oxm_in_port_masked */
    -1,   /* 672: of_oxm_ip_dscp */
    -1,   /* 673: of_oxm_ip_dscp_masked */
    -1,   /* 674: of_oxm_ip_ecn */
    -1,   /* 675: of_oxm_ip_ecn_masked */
    -1,   /* 676: of_oxm_ip_proto */
    -1,   /* 677: of_oxm_ip_proto_masked */
    -1,   /* 678: of_oxm_ipv4_dst */
    -1,   /* 679: of_oxm_ipv4_dst_masked */
    -1,   /* 680: of_oxm_ipv4_src */
    -1,   /* 681: of_oxm_ipv4_src_masked */
    -1,   /* 682: of_oxm_ipv6_dst */
    -1,   /* 683: of_oxm_ipv6_dst_masked */
    -1,   /* 684: of_oxm_ipv6_exthdr */
    -1,   /* 685: of_oxm_ipv6_exthdr_masked */
    -1,   /* 686: of_oxm_ipv6_flabel */
    -1,   /* 687: of_oxm_ipv6_flabel_masked */
    -1,   /* 688: of_oxm_ipv6_nd_sll */
    -1,   /* 689: of_oxm_ipv6_nd_sll_masked */
    -1,   /* 690: of_oxm_ipv6_nd_target */
    -1,   /* 691: of_oxm_ipv6_nd_target_masked */
    -1,   /* 692: of_oxm_ipv6_nd_tll */
    -1,   /* 693: of_oxm_ipv6_nd_tll_masked */
    -1,   /* 694: of_oxm_ipv6_src */
    -1,   /* 695: of_oxm_ipv6_src_masked */
    -1,   /* 696: of_oxm_metadata */
    -1,   /* 697: of_oxm_metadata_masked */
    -1,   /* 698: of_oxm_mpls_bos */
    -1,   /* 699: of_oxm_mpls_bos_masked */
    -1,   /* 700: of_oxm_mpls_label */
    -1,   /* 701: of_oxm_mpls_label_masked */
    -1,   /* 702: of_oxm_mpls_tc */
    -1,   /* 703: of_oxm_mpls_tc_masked */
    -1,   /* 704: of_oxm_ovs_tcp_flags */
    -1,   /* 705: of_oxm_ovs_tcp_flags_masked */
    -1,   /* 706: of_oxm_pbb_uca */
    -1,   /* 707: of_oxm_pbb_uca_masked */
    -1,   /* 708: of_oxm_sctp_dst */
    -1,   /* 709: of_oxm_sctp_dst_masked */
    -1,   /* 710: of_oxm_sctp_src */
    -1,   /* 711: of_oxm_sctp_src_masked */
    -1,   /* 712: of_oxm_tcp_dst */
    -1,   /* 713: of_oxm_tcp_dst_masked */
    -1,   /* 714: of_oxm_tcp_src */
    -1,   /* 715: of_oxm_tcp_src_masked */
    -1,   /* 716: of_oxm_tunnel_id */
    -1,   /* 717: of_oxm_tunnel_id_masked */
    -1,   /* 718: of_oxm_tunnel_ipv4_dst */
    -1,   /* 719: of_oxm_tunnel_ipv4_dst_masked */
    -1,   /* 720: of_oxm_tunnel_ipv4_src */
    -1,   /* 721: of_oxm_tunnel_ipv4_src_masked */
    -1,   /* 722: of_oxm_udp_dst */
    -1,   /* 723: of_oxm_udp_dst_masked */
    -1,   /* 724: of_oxm_udp_src */
    -1,   /* 725: of_oxm_udp_src_masked */
    -1,   /* 726: of_oxm_vlan_pcp */
    -1,   /* 727: of_oxm_vlan_pcp_masked */
    -1,   /* 728: of_oxm_vlan_vid */
    -1,   /* 729: of_oxm_vlan_vid_masked */
    8,    /* 730: of_packet_queue */
    48,   /* 731: of_port_desc */
    -1,   /* 732: of_port_desc_prop */
    -1,   /* 733: of_port_desc_prop_bsn */
    -1,   /* 734: of_port_desc_prop_bsn_breakout */
    -1,   /* 735: of_port_desc_prop_bsn_driver_info_json */
    -1,   /* 736: of_port_desc_prop_bsn_forward_error_correction */
    -1,   /* 737: of_port_desc_prop_bsn_generation_id */
    -1,   /* 738: of_port_desc_prop_bsn_misc_capabilities */
    -1,   /* 739: of_port_desc_prop_bsn_sff_json */
    -1,   /* 740: of_port_desc_prop_bsn_speed_capabilities */
    -1,   /* 741: of_port_desc_prop_bsn_uplink */
    -1,   /* 742: of_port_desc_prop_ethernet */
    -1,   /* 743: of_port_desc_prop_experimenter */
    -1,   /* 744: of_port_desc_prop_optical */
    -1,   /* 745: of_port_mod_prop */
    -1,   /* 746: of_port_mod_prop_ethernet */
    -1,   /* 747: of_port_mod_prop_experimenter */
    -1,   /* 748: of_port_mod_prop_optical */
    104,  /* 749: of_port_stats_entry */
    -1,   /* 750: of_port_stats_prop */
    -1,   /* 751: of_port_stats_prop_ethernet */
    -1,   /* 752: of_port_stats_prop_experimenter */
    -1,   /* 753: of_port_stats_prop_experimenter_intel */
    -1,   /* 754: of_port_stats_prop_optical */
    -1,   /* 755: of_queue_desc */
    -1,   /* 756: of_queue_desc_prop */
    -1,   /* 757: of_queue_desc_prop_bsn */
    -1,   /* 758: of_queue_desc_prop_bsn_queue_name */
    -1,   /* 759: of_queue_desc_prop_experimenter */
    -1,   /* 760: of_queue_desc_prop_max_rate */
    -1,   /* 761: of_queue_desc_prop_min_rate */
    8,    /* 762: of_queue_prop */
    -1,   /* 763: of_queue_prop_experimenter */
    -1,   /* 764: of_queue_prop_max_rate */
    16,   /* 765: of_queue_prop_min_rate */
    32,   /* 766: of_queue_stats_entry */
    -1,   /* 767: of_queue_stats_prop */
    -1,   /* 768: of_queue_stats_prop_experimenter */
    -1,   /* 769: of_role_prop */
    -1,   /* 770: of_role_prop_experimenter */
    -1,   /* 771: of_table_desc */
    -1,   /* 772: of_table_feature_prop */
    -1,   /* 773: of_table_feature_prop_apply_actions */
    -1,   /* 774: of_table_feature_prop_apply_actions_miss */
    -1,   /* 775: of_table_feature_prop_apply_setfield */
    -1,   /* 776: of_table_feature_prop_apply_setfield_miss */
    -1,   /* 777: of_table_feature_prop_experimenter */
    -1,   /* 778: of_table_feature_prop_experimenter_miss */
    -1,   /* 779: of_table_feature_prop_instructions */
    -1,   /* 780: of_table_feature_prop_instructions_miss */
    -1,   /* 781: of_table_feature_prop_match */
    -1,   /* 782: of_table_feature_prop_next_tables */
    -1,   /* 783: of_table_feature_prop_next_tables_miss */
    -1,   /* 784: of_table_feature_prop_table_sync_from */
    -1,   /* 785: of_table_feature_prop_wildcards */
    -1,   /* 786: of_table_feature_prop_write_actions */
    -1,   /* 787: of_table_feature_prop_write_actions_miss */
    -1,   /* 788: of_table_feature_prop_write_setfield */
    -1,   /* 789: of_table_feature_prop_write_setfield_miss */
    -1,   /* 790: of_table_features */
    -1,   /* 791: of_table_mod_prop */
    -1,   /* 792: of_table_mod_prop_eviction */
    -1,   /* 793: of_table_mod_prop_experimenter */
    -1,   /* 794: of_table_mod_prop_vacancy */
    64,   /* 795: of_table_stats_entry */
    -1,   /* 796: of_uint32 */
    -1,   /* 797: of_uint64 */
    -1,   /* 798: of_uint8 */
    0,    /* 799: of_list_action */
    -1,   /* 800: of_list_action_id */
    -1,   /* 801: of_list_async_config_prop */
    -1,   /* 802: of_list_bsn_controller_connection */
    -1,   /* 803: of_list_bsn_debug_counter_desc_stats_entry */
    -1,   /* 804: of_list_bsn_debug_counter_stats_entry */
    -1,   /* 805: of_list_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 806: of_list_bsn_generic_stats_entry */
    -1,   /* 807: of_list_bsn_gentable_bucket_stats_entry */
    -1,   /* 808: of_list_bsn_gentable_desc_stats_entry */
    -1,   /* 809: of_list_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 810: of_list_bsn_gentable_entry_stats_entry */
    -1,   /* 811: of_list_bsn_gentable_stats_entry */
    0,    /* 812: of_list_bsn_interface */
    -1,   /* 813: of_list_bsn_lacp_stats_entry */
    -1,   /* 814: of_list_bsn_port_counter_stats_entry */
    -1,   /* 815: of_list_bsn_switch_pipeline_stats_entry */
    -1,   /* 816: of_list_bsn_table_checksum_stats_entry */
    -1,   /* 817: of_list_bsn_tlv */
    -1,   /* 818: of_list_bsn_vlan_counter_stats_entry */
    -1,   /* 819: of_list_bsn_vlan_mac */
    -1,   /* 820: of_list_bsn_vrf_counter_stats_entry */
    -1,   /* 821: of_list_bucket */
    -1,   /* 822: of_list_bucket_counter */
    -1,   /* 823: of_list_bundle_prop */
    0,    /* 824: of_list_flow_stats_entry */
    -1,   /* 825: of_list_group_desc_stats_entry */
    -1,   /* 826: of_list_group_stats_entry */
    -1,   /* 827: of_list_hello_elem */
    -1,   /* 828: of_list_instruction */
    -1,   /* 829: of_list_instruction_id */
    -1,   /* 830: of_list_meter_band */
    -1,   /* 831: of_list_meter_band_stats */
    -1,   /* 832: of_list_meter_config */
    -1,   /* 833: of_list_meter_stats */
    -1,   /* 834: of_list_oxm */
    0,    /* 835: of_list_packet_queue */
    0,    /* 836: of_list_port_desc */
    -1,   /* 837: of_list_port_desc_prop */
    -1,   /* 838: of_list_port_mod_prop */
    0,    /* 839: of_list_port_stats_entry */
    -1,   /* 840: of_list_port_stats_prop */
    -1,   /* 841: of_list_queue_desc */
    -1,   /* 842: of_list_queue_desc_prop */
    0,    /* 843: of_list_queue_prop */
    0,    /* 844: of_list_queue_stats_entry */
    -1,   /* 845: of_list_queue_stats_prop */
    -1,   /* 846: of_list_role_prop */
    -1,   /* 847: of_list_table_desc */
    -1,   /* 848: of_list_table_feature_prop */
    -1,   /* 849: of_list_table_features */
    -1,   /* 850: of_list_table_mod_prop */
    0,    /* 851: of_list_table_stats_entry */
    -1,   /* 852: of_list_uint32 */
    -1,   /* 853: of_list_uint64 */
    -1    /* 854: of_list_uint8 */
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
    -1,   /* 52: of_bsn_gentable_error */
    -1,   /* 53: of_bsn_gentable_set_buckets_size */
    -1,   /* 54: of_bsn_gentable_stats_reply */
    -1,   /* 55: of_bsn_gentable_stats_request */
    16,   /* 56: of_bsn_get_interfaces_reply */
    16,   /* 57: of_bsn_get_interfaces_request */
    -1,   /* 58: of_bsn_get_ip_mask_reply */
    -1,   /* 59: of_bsn_get_ip_mask_request */
    -1,   /* 60: of_bsn_get_l2_table_reply */
    -1,   /* 61: of_bsn_get_l2_table_request */
    20,   /* 62: of_bsn_get_mirroring_reply */
    20,   /* 63: of_bsn_get_mirroring_request */
    -1,   /* 64: of_bsn_get_switch_pipeline_reply */
    -1,   /* 65: of_bsn_get_switch_pipeline_request */
    16,   /* 66: of_bsn_header */
    -1,   /* 67: of_bsn_hybrid_get_reply */
    -1,   /* 68: of_bsn_hybrid_get_request */
    -1,   /* 69: of_bsn_image_desc_stats_reply */
    -1,   /* 70: of_bsn_image_desc_stats_request */
    -1,   /* 71: of_bsn_lacp_convergence_notif */
    -1,   /* 72: of_bsn_lacp_stats_reply */
    -1,   /* 73: of_bsn_lacp_stats_request */
    -1,   /* 74: of_bsn_log */
    -1,   /* 75: of_bsn_lua_command_reply */
    -1,   /* 76: of_bsn_lua_command_request */
    -1,   /* 77: of_bsn_lua_notification */
    -1,   /* 78: of_bsn_lua_upload */
    25,   /* 79: of_bsn_pdu_rx_reply */
    28,   /* 80: of_bsn_pdu_rx_request */
    21,   /* 81: of_bsn_pdu_rx_timeout */
    25,   /* 82: of_bsn_pdu_tx_reply */
    28,   /* 83: of_bsn_pdu_tx_request */
    -1,   /* 84: of_bsn_port_counter_stats_reply */
    -1,   /* 85: of_bsn_port_counter_stats_request */
    -1,   /* 86: of_bsn_role_status */
    -1,   /* 87: of_bsn_set_aux_cxns_reply */
    -1,   /* 88: of_bsn_set_aux_cxns_request */
    -1,   /* 89: of_bsn_set_ip_mask */
    -1,   /* 90: of_bsn_set_l2_table_reply */
    -1,   /* 91: of_bsn_set_l2_table_request */
    -1,   /* 92: of_bsn_set_lacp_reply */
    -1,   /* 93: of_bsn_set_lacp_request */
    20,   /* 94: of_bsn_set_mirroring */
    20,   /* 95: of_bsn_set_pktin_suppression_reply */
    32,   /* 96: of_bsn_set_pktin_suppression_request */
    -1,   /* 97: of_bsn_set_switch_pipeline_reply */
    -1,   /* 98: of_bsn_set_switch_pipeline_request */
    -1,   /* 99: of_bsn_shell_command */
    -1,   /* 100: of_bsn_shell_output */
    -1,   /* 101: of_bsn_shell_status */
    24,   /* 102: of_bsn_stats_reply */
    24,   /* 103: of_bsn_stats_request */
    -1,   /* 104: of_bsn_switch_pipeline_stats_reply */
    -1,   /* 105: of_bsn_switch_pipeline_stats_request */
    -1,   /* 106: of_bsn_table_checksum_stats_reply */
    -1,   /* 107: of_bsn_table_checksum_stats_request */
    -1,   /* 108: of_bsn_table_set_buckets_size */
    -1,   /* 109: of_bsn_takeover */
    -1,   /* 110: of_bsn_time_reply */
    -1,   /* 111: of_bsn_time_request */
    24,   /* 112: of_bsn_virtual_port_create_reply */
    20,   /* 113: of_bsn_virtual_port_create_request */
    20,   /* 114: of_bsn_virtual_port_remove_reply */
    20,   /* 115: of_bsn_virtual_port_remove_request */
    -1,   /* 116: of_bsn_vlan_counter_clear */
    -1,   /* 117: of_bsn_vlan_counter_stats_reply */
    -1,   /* 118: of_bsn_vlan_counter_stats_request */
    -1,   /* 119: of_bsn_vrf_counter_stats_reply */
    -1,   /* 120: of_bsn_vrf_counter_stats_request */
    -1,   /* 121: of_bundle_add_msg */
    -1,   /* 122: of_bundle_ctrl_msg */
    -1,   /* 123: of_bundle_failed_error_msg */
    1072, /* 124: of_desc_stats_reply */
    16,   /* 125: of_desc_stats_request */
    8,    /* 126: of_echo_reply */
    8,    /* 127: of_echo_request */
    10,   /* 128: of_error_msg */
    12,   /* 129: of_experimenter */
    -1,   /* 130: of_experimenter_error_msg */
    24,   /* 131: of_experimenter_stats_reply */
    24,   /* 132: of_experimenter_stats_request */
    32,   /* 133: of_features_reply */
    8,    /* 134: of_features_request */
    136,  /* 135: of_flow_add */
    136,  /* 136: of_flow_delete */
    136,  /* 137: of_flow_delete_strict */
    136,  /* 138: of_flow_mod */
    12,   /* 139: of_flow_mod_failed_error_msg */
    136,  /* 140: of_flow_modify */
    136,  /* 141: of_flow_modify_strict */
    -1,   /* 142: of_flow_monitor_failed_error_msg */
    136,  /* 143: of_flow_removed */
    16,   /* 144: of_flow_stats_reply */
    136,  /* 145: of_flow_stats_request */
    12,   /* 146: of_get_config_reply */
    8,    /* 147: of_get_config_request */
    16,   /* 148: of_group_add */
    16,   /* 149: of_group_delete */
    16,   /* 150: of_group_desc_stats_reply */
    16,   /* 151: of_group_desc_stats_request */
    -1,   /* 152: of_group_features_stats_reply */
    -1,   /* 153: of_group_features_stats_request */
    16,   /* 154: of_group_mod */
    12,   /* 155: of_group_mod_failed_error_msg */
    16,   /* 156: of_group_modify */
    16,   /* 157: of_group_stats_reply */
    24,   /* 158: of_group_stats_request */
    8,    /* 159: of_header */
    8,    /* 160: of_hello */
    12,   /* 161: of_hello_failed_error_msg */
    -1,   /* 162: of_meter_config_stats_reply */
    -1,   /* 163: of_meter_config_stats_request */
    -1,   /* 164: of_meter_features_stats_reply */
    -1,   /* 165: of_meter_features_stats_request */
    -1,   /* 166: of_meter_mod */
    -1,   /* 167: of_meter_mod_failed_error_msg */
    -1,   /* 168: of_meter_stats_reply */
    -1,   /* 169: of_meter_stats_request */
    -1,   /* 170: of_nicira_controller_role_reply */
    -1,   /* 171: of_nicira_controller_role_request */
    16,   /* 172: of_nicira_header */
    24,   /* 173: of_packet_in */
    24,   /* 174: of_packet_out */
    -1,   /* 175: of_port_desc_stats_reply */
    -1,   /* 176: of_port_desc_stats_request */
    40,   /* 177: of_port_mod */
    12,   /* 178: of_port_mod_failed_error_msg */
    16,   /* 179: of_port_stats_reply */
    24,   /* 180: of_port_stats_request */
    80,   /* 181: of_port_status */
    -1,   /* 182: of_queue_desc_stats_reply */
    -1,   /* 183: of_queue_desc_stats_request */
    16,   /* 184: of_queue_get_config_reply */
    16,   /* 185: of_queue_get_config_request */
    12,   /* 186: of_queue_op_failed_error_msg */
    16,   /* 187: of_queue_stats_reply */
    24,   /* 188: of_queue_stats_request */
    -1,   /* 189: of_requestforward */
    -1,   /* 190: of_role_reply */
    -1,   /* 191: of_role_request */
    -1,   /* 192: of_role_request_failed_error_msg */
    -1,   /* 193: of_role_status */
    12,   /* 194: of_set_config */
    16,   /* 195: of_stats_reply */
    16,   /* 196: of_stats_request */
    12,   /* 197: of_switch_config_failed_error_msg */
    -1,   /* 198: of_table_desc_stats_reply */
    -1,   /* 199: of_table_desc_stats_request */
    -1,   /* 200: of_table_features_failed_error_msg */
    -1,   /* 201: of_table_features_stats_reply */
    -1,   /* 202: of_table_features_stats_request */
    16,   /* 203: of_table_mod */
    12,   /* 204: of_table_mod_failed_error_msg */
    16,   /* 205: of_table_stats_reply */
    16,   /* 206: of_table_stats_request */
    -1,   /* 207: of_table_status */
    8,    /* 208: of_action */
    16,   /* 209: of_action_bsn */
    28,   /* 210: of_action_bsn_checksum */
    -1,   /* 211: of_action_bsn_gentable */
    24,   /* 212: of_action_bsn_mirror */
    16,   /* 213: of_action_bsn_set_tunnel_dst */
    8,    /* 214: of_action_copy_ttl_in */
    8,    /* 215: of_action_copy_ttl_out */
    8,    /* 216: of_action_dec_mpls_ttl */
    8,    /* 217: of_action_dec_nw_ttl */
    -1,   /* 218: of_action_enqueue */
    8,    /* 219: of_action_experimenter */
    8,    /* 220: of_action_group */
    -1,   /* 221: of_action_id */
    -1,   /* 222: of_action_id_bsn */
    -1,   /* 223: of_action_id_bsn_checksum */
    -1,   /* 224: of_action_id_bsn_gentable */
    -1,   /* 225: of_action_id_bsn_mirror */
    -1,   /* 226: of_action_id_bsn_set_tunnel_dst */
    -1,   /* 227: of_action_id_copy_ttl_in */
    -1,   /* 228: of_action_id_copy_ttl_out */
    -1,   /* 229: of_action_id_dec_mpls_ttl */
    -1,   /* 230: of_action_id_dec_nw_ttl */
    -1,   /* 231: of_action_id_experimenter */
    -1,   /* 232: of_action_id_group */
    -1,   /* 233: of_action_id_nicira */
    -1,   /* 234: of_action_id_nicira_dec_ttl */
    -1,   /* 235: of_action_id_output */
    -1,   /* 236: of_action_id_pop_mpls */
    -1,   /* 237: of_action_id_pop_pbb */
    -1,   /* 238: of_action_id_pop_vlan */
    -1,   /* 239: of_action_id_push_mpls */
    -1,   /* 240: of_action_id_push_pbb */
    -1,   /* 241: of_action_id_push_vlan */
    -1,   /* 242: of_action_id_set_field */
    -1,   /* 243: of_action_id_set_mpls_ttl */
    -1,   /* 244: of_action_id_set_nw_ttl */
    -1,   /* 245: of_action_id_set_queue */
    16,   /* 246: of_action_nicira */
    16,   /* 247: of_action_nicira_dec_ttl */
    16,   /* 248: of_action_output */
    8,    /* 249: of_action_pop_mpls */
    -1,   /* 250: of_action_pop_pbb */
    8,    /* 251: of_action_pop_vlan */
    8,    /* 252: of_action_push_mpls */
    -1,   /* 253: of_action_push_pbb */
    8,    /* 254: of_action_push_vlan */
    16,   /* 255: of_action_set_dl_dst */
    16,   /* 256: of_action_set_dl_src */
    -1,   /* 257: of_action_set_field */
    8,    /* 258: of_action_set_mpls_label */
    8,    /* 259: of_action_set_mpls_tc */
    8,    /* 260: of_action_set_mpls_ttl */
    8,    /* 261: of_action_set_nw_dst */
    8,    /* 262: of_action_set_nw_ecn */
    8,    /* 263: of_action_set_nw_src */
    8,    /* 264: of_action_set_nw_tos */
    8,    /* 265: of_action_set_nw_ttl */
    8,    /* 266: of_action_set_queue */
    8,    /* 267: of_action_set_tp_dst */
    8,    /* 268: of_action_set_tp_src */
    8,    /* 269: of_action_set_vlan_pcp */
    8,    /* 270: of_action_set_vlan_vid */
    -1,   /* 271: of_action_strip_vlan */
    -1,   /* 272: of_async_config_prop */
    -1,   /* 273: of_async_config_prop_experimenter_master */
    -1,   /* 274: of_async_config_prop_experimenter_slave */
    -1,   /* 275: of_async_config_prop_flow_removed_master */
    -1,   /* 276: of_async_config_prop_flow_removed_slave */
    -1,   /* 277: of_async_config_prop_packet_in_master */
    -1,   /* 278: of_async_config_prop_packet_in_slave */
    -1,   /* 279: of_async_config_prop_port_status_master */
    -1,   /* 280: of_async_config_prop_port_status_slave */
    -1,   /* 281: of_async_config_prop_requestforward_master */
    -1,   /* 282: of_async_config_prop_requestforward_slave */
    -1,   /* 283: of_async_config_prop_role_status_master */
    -1,   /* 284: of_async_config_prop_role_status_slave */
    -1,   /* 285: of_async_config_prop_table_status_master */
    -1,   /* 286: of_async_config_prop_table_status_slave */
    -1,   /* 287: of_bsn_controller_connection */
    -1,   /* 288: of_bsn_debug_counter_desc_stats_entry */
    -1,   /* 289: of_bsn_debug_counter_stats_entry */
    -1,   /* 290: of_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 291: of_bsn_generic_stats_entry */
    -1,   /* 292: of_bsn_gentable_bucket_stats_entry */
    -1,   /* 293: of_bsn_gentable_desc_stats_entry */
    -1,   /* 294: of_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 295: of_bsn_gentable_entry_stats_entry */
    -1,   /* 296: of_bsn_gentable_stats_entry */
    32,   /* 297: of_bsn_interface */
    -1,   /* 298: of_bsn_lacp_stats_entry */
    -1,   /* 299: of_bsn_port_counter_stats_entry */
    -1,   /* 300: of_bsn_switch_pipeline_stats_entry */
    -1,   /* 301: of_bsn_table_checksum_stats_entry */
    -1,   /* 302: of_bsn_tlv */
    -1,   /* 303: of_bsn_tlv_actor_key */
    -1,   /* 304: of_bsn_tlv_actor_port_num */
    -1,   /* 305: of_bsn_tlv_actor_port_priority */
    -1,   /* 306: of_bsn_tlv_actor_state */
    -1,   /* 307: of_bsn_tlv_actor_system_mac */
    -1,   /* 308: of_bsn_tlv_actor_system_priority */
    -1,   /* 309: of_bsn_tlv_anchor */
    -1,   /* 310: of_bsn_tlv_apply_bytes */
    -1,   /* 311: of_bsn_tlv_apply_packets */
    -1,   /* 312: of_bsn_tlv_auto_negotiation */
    -1,   /* 313: of_bsn_tlv_bfd_endpoint */
    -1,   /* 314: of_bsn_tlv_bfd_state */
    -1,   /* 315: of_bsn_tlv_broadcast_query_timeout */
    -1,   /* 316: of_bsn_tlv_broadcast_rate */
    -1,   /* 317: of_bsn_tlv_bucket */
    -1,   /* 318: of_bsn_tlv_circuit_id */
    -1,   /* 319: of_bsn_tlv_convergence_status */
    -1,   /* 320: of_bsn_tlv_cpu_lag */
    -1,   /* 321: of_bsn_tlv_crc_enabled */
    -1,   /* 322: of_bsn_tlv_data */
    -1,   /* 323: of_bsn_tlv_data_mask */
    -1,   /* 324: of_bsn_tlv_decap */
    -1,   /* 325: of_bsn_tlv_disable_src_mac_check */
    -1,   /* 326: of_bsn_tlv_drop */
    -1,   /* 327: of_bsn_tlv_dscp */
    -1,   /* 328: of_bsn_tlv_ecn */
    -1,   /* 329: of_bsn_tlv_egress_only */
    -1,   /* 330: of_bsn_tlv_egress_port_group_id */
    -1,   /* 331: of_bsn_tlv_encap */
    -1,   /* 332: of_bsn_tlv_enhanced_hash_capability */
    -1,   /* 333: of_bsn_tlv_eth_dst */
    -1,   /* 334: of_bsn_tlv_eth_src */
    -1,   /* 335: of_bsn_tlv_eth_type */
    -1,   /* 336: of_bsn_tlv_external_gateway_ip */
    -1,   /* 337: of_bsn_tlv_external_gateway_mac */
    -1,   /* 338: of_bsn_tlv_external_ip */
    -1,   /* 339: of_bsn_tlv_external_mac */
    -1,   /* 340: of_bsn_tlv_external_netmask */
    -1,   /* 341: of_bsn_tlv_fabric_port_role */
    -1,   /* 342: of_bsn_tlv_flood */
    -1,   /* 343: of_bsn_tlv_flow_classifier */
    -1,   /* 344: of_bsn_tlv_flow_classify */
    -1,   /* 345: of_bsn_tlv_flow_identifier */
    -1,   /* 346: of_bsn_tlv_force_link_up */
    -1,   /* 347: of_bsn_tlv_forward_error_correction */
    -1,   /* 348: of_bsn_tlv_generation_id */
    -1,   /* 349: of_bsn_tlv_hash_algorithm */
    -1,   /* 350: of_bsn_tlv_hash_gtp_header_match */
    -1,   /* 351: of_bsn_tlv_hash_gtp_port_match */
    -1,   /* 352: of_bsn_tlv_hash_packet_field */
    -1,   /* 353: of_bsn_tlv_hash_packet_type */
    -1,   /* 354: of_bsn_tlv_hash_seed */
    -1,   /* 355: of_bsn_tlv_hash_type */
    -1,   /* 356: of_bsn_tlv_header_size */
    -1,   /* 357: of_bsn_tlv_icmp_code */
    -1,   /* 358: of_bsn_tlv_icmp_id */
    -1,   /* 359: of_bsn_tlv_icmp_type */
    -1,   /* 360: of_bsn_tlv_icmpv6_chksum */
    -1,   /* 361: of_bsn_tlv_identifier */
    -1,   /* 362: of_bsn_tlv_idle_notification */
    -1,   /* 363: of_bsn_tlv_idle_time */
    -1,   /* 364: of_bsn_tlv_idle_timeout */
    -1,   /* 365: of_bsn_tlv_igmp_snooping */
    -1,   /* 366: of_bsn_tlv_ingress_port_group_id */
    -1,   /* 367: of_bsn_tlv_internal_gateway_mac */
    -1,   /* 368: of_bsn_tlv_internal_mac */
    -1,   /* 369: of_bsn_tlv_interval */
    -1,   /* 370: of_bsn_tlv_ip_proto */
    -1,   /* 371: of_bsn_tlv_ip_tunnel_type */
    -1,   /* 372: of_bsn_tlv_ipv4 */
    -1,   /* 373: of_bsn_tlv_ipv4_dst */
    -1,   /* 374: of_bsn_tlv_ipv4_netmask */
    -1,   /* 375: of_bsn_tlv_ipv4_src */
    -1,   /* 376: of_bsn_tlv_ipv6 */
    -1,   /* 377: of_bsn_tlv_ipv6_dst */
    -1,   /* 378: of_bsn_tlv_ipv6_prefix */
    -1,   /* 379: of_bsn_tlv_ipv6_src */
    -1,   /* 380: of_bsn_tlv_known_multicast_rate */
    -1,   /* 381: of_bsn_tlv_l2_multicast_lookup */
    -1,   /* 382: of_bsn_tlv_l3 */
    -1,   /* 383: of_bsn_tlv_l3_dst_class_id */
    -1,   /* 384: of_bsn_tlv_l3_interface_class_id */
    -1,   /* 385: of_bsn_tlv_l3_src_class_id */
    -1,   /* 386: of_bsn_tlv_lag_options */
    -1,   /* 387: of_bsn_tlv_loopback_mode */
    -1,   /* 388: of_bsn_tlv_loopback_port */
    -1,   /* 389: of_bsn_tlv_lr_all_enabled */
    -1,   /* 390: of_bsn_tlv_mac */
    -1,   /* 391: of_bsn_tlv_mac_mask */
    -1,   /* 392: of_bsn_tlv_mcg_type_vxlan */
    -1,   /* 393: of_bsn_tlv_miss_packets */
    -1,   /* 394: of_bsn_tlv_mpls_control_word */
    -1,   /* 395: of_bsn_tlv_mpls_label */
    -1,   /* 396: of_bsn_tlv_mpls_sequenced */
    -1,   /* 397: of_bsn_tlv_multicast_interface_id */
    -1,   /* 398: of_bsn_tlv_multicast_packet */
    -1,   /* 399: of_bsn_tlv_multiplier */
    -1,   /* 400: of_bsn_tlv_name */
    -1,   /* 401: of_bsn_tlv_ndp_offload */
    -1,   /* 402: of_bsn_tlv_ndp_static */
    -1,   /* 403: of_bsn_tlv_negate */
    -1,   /* 404: of_bsn_tlv_next_hop_ipv4 */
    -1,   /* 405: of_bsn_tlv_next_hop_mac */
    -1,   /* 406: of_bsn_tlv_nexthop_type_vxlan */
    -1,   /* 407: of_bsn_tlv_no_arp_response */
    -1,   /* 408: of_bsn_tlv_no_ns_response */
    -1,   /* 409: of_bsn_tlv_offset */
    -1,   /* 410: of_bsn_tlv_optics_always_enabled */
    -1,   /* 411: of_bsn_tlv_outer_src_mac */
    -1,   /* 412: of_bsn_tlv_parent_port */
    -1,   /* 413: of_bsn_tlv_partner_key */
    -1,   /* 414: of_bsn_tlv_partner_port_num */
    -1,   /* 415: of_bsn_tlv_partner_port_priority */
    -1,   /* 416: of_bsn_tlv_partner_state */
    -1,   /* 417: of_bsn_tlv_partner_system_mac */
    -1,   /* 418: of_bsn_tlv_partner_system_priority */
    -1,   /* 419: of_bsn_tlv_passive */
    -1,   /* 420: of_bsn_tlv_pdua_rx_instance */
    -1,   /* 421: of_bsn_tlv_pim_dr */
    -1,   /* 422: of_bsn_tlv_pim_hello_flood */
    -1,   /* 423: of_bsn_tlv_port */
    -1,   /* 424: of_bsn_tlv_port_mode */
    -1,   /* 425: of_bsn_tlv_port_speed_gbps */
    -1,   /* 426: of_bsn_tlv_port_usage */
    -1,   /* 427: of_bsn_tlv_port_vxlan_mode */
    -1,   /* 428: of_bsn_tlv_priority */
    -1,   /* 429: of_bsn_tlv_push_vlan_on_egress */
    -1,   /* 430: of_bsn_tlv_push_vlan_on_ingress */
    -1,   /* 431: of_bsn_tlv_qos_priority */
    -1,   /* 432: of_bsn_tlv_queue_id */
    -1,   /* 433: of_bsn_tlv_queue_weight */
    -1,   /* 434: of_bsn_tlv_rate_limit */
    -1,   /* 435: of_bsn_tlv_rate_unit */
    -1,   /* 436: of_bsn_tlv_record_packets */
    -1,   /* 437: of_bsn_tlv_reference */
    -1,   /* 438: of_bsn_tlv_reply_packets */
    -1,   /* 439: of_bsn_tlv_request_packets */
    -1,   /* 440: of_bsn_tlv_rest_server */
    -1,   /* 441: of_bsn_tlv_routing_param */
    -1,   /* 442: of_bsn_tlv_rx_bytes */
    -1,   /* 443: of_bsn_tlv_rx_packets */
    -1,   /* 444: of_bsn_tlv_sampling_rate */
    -1,   /* 445: of_bsn_tlv_set_loopback_mode */
    -1,   /* 446: of_bsn_tlv_status */
    -1,   /* 447: of_bsn_tlv_strip_mpls_l2_on_ingress */
    -1,   /* 448: of_bsn_tlv_strip_mpls_l3_on_ingress */
    -1,   /* 449: of_bsn_tlv_strip_vlan_on_egress */
    -1,   /* 450: of_bsn_tlv_sub_agent_id */
    -1,   /* 451: of_bsn_tlv_tcp_dst */
    -1,   /* 452: of_bsn_tlv_tcp_flags */
    -1,   /* 453: of_bsn_tlv_tcp_src */
    -1,   /* 454: of_bsn_tlv_timestamp */
    -1,   /* 455: of_bsn_tlv_ttl */
    -1,   /* 456: of_bsn_tlv_tunnel_capability */
    -1,   /* 457: of_bsn_tlv_tx_bytes */
    -1,   /* 458: of_bsn_tlv_tx_packets */
    -1,   /* 459: of_bsn_tlv_udf_anchor */
    -1,   /* 460: of_bsn_tlv_udf_capability */
    -1,   /* 461: of_bsn_tlv_udf_id */
    -1,   /* 462: of_bsn_tlv_udf_length */
    -1,   /* 463: of_bsn_tlv_udf_offset */
    -1,   /* 464: of_bsn_tlv_udp_dst */
    -1,   /* 465: of_bsn_tlv_udp_src */
    -1,   /* 466: of_bsn_tlv_uint32 */
    -1,   /* 467: of_bsn_tlv_uint64_list */
    -1,   /* 468: of_bsn_tlv_unicast_query_timeout */
    -1,   /* 469: of_bsn_tlv_unicast_rate */
    -1,   /* 470: of_bsn_tlv_unknown_multicast_rate */
    -1,   /* 471: of_bsn_tlv_untagged */
    -1,   /* 472: of_bsn_tlv_upgrade */
    -1,   /* 473: of_bsn_tlv_uri_scheme */
    -1,   /* 474: of_bsn_tlv_use_packet_state */
    -1,   /* 475: of_bsn_tlv_user_configured */
    -1,   /* 476: of_bsn_tlv_vfi */
    -1,   /* 477: of_bsn_tlv_vfp_class_id */
    -1,   /* 478: of_bsn_tlv_virtual */
    -1,   /* 479: of_bsn_tlv_vlan_mac_list */
    -1,   /* 480: of_bsn_tlv_vlan_pcp */
    -1,   /* 481: of_bsn_tlv_vlan_vid */
    -1,   /* 482: of_bsn_tlv_vlan_vid_mask */
    -1,   /* 483: of_bsn_tlv_vni */
    -1,   /* 484: of_bsn_tlv_vpn_key */
    -1,   /* 485: of_bsn_tlv_vrf */
    -1,   /* 486: of_bsn_tlv_vxlan_egress_lag */
    -1,   /* 487: of_bsn_vlan_counter_stats_entry */
    -1,   /* 488: of_bsn_vlan_mac */
    4,    /* 489: of_bsn_vport */
    64,   /* 490: of_bsn_vport_l2gre */
    32,   /* 491: of_bsn_vport_q_in_q */
    -1,   /* 492: of_bsn_vrf_counter_stats_entry */
    16,   /* 493: of_bucket */
    16,   /* 494: of_bucket_counter */
    -1,   /* 495: of_bundle_prop */
    -1,   /* 496: of_bundle_prop_experimenter */
    136,  /* 497: of_flow_stats_entry */
    8,    /* 498: of_group_desc_stats_entry */
    32,   /* 499: of_group_stats_entry */
    -1,   /* 500: of_hello_elem */
    -1,   /* 501: of_hello_elem_versionbitmap */
    8,    /* 502: of_instruction */
    8,    /* 503: of_instruction_apply_actions */
    -1,   /* 504: of_instruction_bsn */
    -1,   /* 505: of_instruction_bsn_arp_offload */
    -1,   /* 506: of_instruction_bsn_auto_negotiation */
    -1,   /* 507: of_instruction_bsn_deny */
    -1,   /* 508: of_instruction_bsn_dhcp_offload */
    -1,   /* 509: of_instruction_bsn_directed_broadcast */
    -1,   /* 510: of_instruction_bsn_disable_l3 */
    -1,   /* 511: of_instruction_bsn_disable_split_horizon_check */
    -1,   /* 512: of_instruction_bsn_disable_src_mac_check */
    -1,   /* 513: of_instruction_bsn_disable_vlan_counters */
    -1,   /* 514: of_instruction_bsn_hash_select */
    -1,   /* 515: of_instruction_bsn_internal_priority */
    -1,   /* 516: of_instruction_bsn_ndp_offload */
    -1,   /* 517: of_instruction_bsn_packet_of_death */
    -1,   /* 518: of_instruction_bsn_permit */
    -1,   /* 519: of_instruction_bsn_prioritize_pdus */
    -1,   /* 520: of_instruction_bsn_require_vlan_xlate */
    -1,   /* 521: of_instruction_bsn_span_destination */
    8,    /* 522: of_instruction_clear_actions */
    8,    /* 523: of_instruction_experimenter */
    8,    /* 524: of_instruction_goto_table */
    -1,   /* 525: of_instruction_id */
    -1,   /* 526: of_instruction_id_apply_actions */
    -1,   /* 527: of_instruction_id_bsn */
    -1,   /* 528: of_instruction_id_bsn_arp_offload */
    -1,   /* 529: of_instruction_id_bsn_auto_negotiation */
    -1,   /* 530: of_instruction_id_bsn_deny */
    -1,   /* 531: of_instruction_id_bsn_dhcp_offload */
    -1,   /* 532: of_instruction_id_bsn_directed_broadcast */
    -1,   /* 533: of_instruction_id_bsn_disable_l3 */
    -1,   /* 534: of_instruction_id_bsn_disable_split_horizon_check */
    -1,   /* 535: of_instruction_id_bsn_disable_src_mac_check */
    -1,   /* 536: of_instruction_id_bsn_disable_vlan_counters */
    -1,   /* 537: of_instruction_id_bsn_hash_select */
    -1,   /* 538: of_instruction_id_bsn_internal_priority */
    -1,   /* 539: of_instruction_id_bsn_ndp_offload */
    -1,   /* 540: of_instruction_id_bsn_packet_of_death */
    -1,   /* 541: of_instruction_id_bsn_permit */
    -1,   /* 542: of_instruction_id_bsn_prioritize_pdus */
    -1,   /* 543: of_instruction_id_bsn_require_vlan_xlate */
    -1,   /* 544: of_instruction_id_bsn_span_destination */
    -1,   /* 545: of_instruction_id_clear_actions */
    -1,   /* 546: of_instruction_id_experimenter */
    -1,   /* 547: of_instruction_id_goto_table */
    -1,   /* 548: of_instruction_id_meter */
    -1,   /* 549: of_instruction_id_write_actions */
    -1,   /* 550: of_instruction_id_write_metadata */
    -1,   /* 551: of_instruction_meter */
    8,    /* 552: of_instruction_write_actions */
    24,   /* 553: of_instruction_write_metadata */
    -1,   /* 554: of_match_v1 */
    88,   /* 555: of_match_v2 */
    -1,   /* 556: of_match_v3 */
    -1,   /* 557: of_meter_band */
    -1,   /* 558: of_meter_band_drop */
    -1,   /* 559: of_meter_band_dscp_remark */
    -1,   /* 560: of_meter_band_experimenter */
    -1,   /* 561: of_meter_band_stats */
    -1,   /* 562: of_meter_config */
    -1,   /* 563: of_meter_features */
    -1,   /* 564: of_meter_stats */
    -1,   /* 565: of_oxm */
    -1,   /* 566: of_oxm_arp_op */
    -1,   /* 567: of_oxm_arp_op_masked */
    -1,   /* 568: of_oxm_arp_sha */
    -1,   /* 569: of_oxm_arp_sha_masked */
    -1,   /* 570: of_oxm_arp_spa */
    -1,   /* 571: of_oxm_arp_spa_masked */
    -1,   /* 572: of_oxm_arp_tha */
    -1,   /* 573: of_oxm_arp_tha_masked */
    -1,   /* 574: of_oxm_arp_tpa */
    -1,   /* 575: of_oxm_arp_tpa_masked */
    -1,   /* 576: of_oxm_bsn_egr_port_group_id */
    -1,   /* 577: of_oxm_bsn_egr_port_group_id_masked */
    -1,   /* 578: of_oxm_bsn_global_vrf_allowed */
    -1,   /* 579: of_oxm_bsn_global_vrf_allowed_masked */
    -1,   /* 580: of_oxm_bsn_ifp_class_id */
    -1,   /* 581: of_oxm_bsn_ifp_class_id_masked */
    -1,   /* 582: of_oxm_bsn_in_ports_128 */
    -1,   /* 583: of_oxm_bsn_in_ports_128_masked */
    -1,   /* 584: of_oxm_bsn_in_ports_512 */
    -1,   /* 585: of_oxm_bsn_in_ports_512_masked */
    -1,   /* 586: of_oxm_bsn_ingress_port_group_id */
    -1,   /* 587: of_oxm_bsn_ingress_port_group_id_masked */
    -1,   /* 588: of_oxm_bsn_inner_eth_dst */
    -1,   /* 589: of_oxm_bsn_inner_eth_dst_masked */
    -1,   /* 590: of_oxm_bsn_inner_eth_src */
    -1,   /* 591: of_oxm_bsn_inner_eth_src_masked */
    -1,   /* 592: of_oxm_bsn_inner_vlan_vid */
    -1,   /* 593: of_oxm_bsn_inner_vlan_vid_masked */
    -1,   /* 594: of_oxm_bsn_ip_fragmentation */
    -1,   /* 595: of_oxm_bsn_ip_fragmentation_masked */
    -1,   /* 596: of_oxm_bsn_l2_cache_hit */
    -1,   /* 597: of_oxm_bsn_l2_cache_hit_masked */
    -1,   /* 598: of_oxm_bsn_l3_dst_class_id */
    -1,   /* 599: of_oxm_bsn_l3_dst_class_id_masked */
    -1,   /* 600: of_oxm_bsn_l3_interface_class_id */
    -1,   /* 601: of_oxm_bsn_l3_interface_class_id_masked */
    -1,   /* 602: of_oxm_bsn_l3_src_class_id */
    -1,   /* 603: of_oxm_bsn_l3_src_class_id_masked */
    -1,   /* 604: of_oxm_bsn_lag_id */
    -1,   /* 605: of_oxm_bsn_lag_id_masked */
    -1,   /* 606: of_oxm_bsn_tcp_flags */
    -1,   /* 607: of_oxm_bsn_tcp_flags_masked */
    -1,   /* 608: of_oxm_bsn_udf0 */
    -1,   /* 609: of_oxm_bsn_udf0_masked */
    -1,   /* 610: of_oxm_bsn_udf1 */
    -1,   /* 611: of_oxm_bsn_udf1_masked */
    -1,   /* 612: of_oxm_bsn_udf2 */
    -1,   /* 613: of_oxm_bsn_udf2_masked */
    -1,   /* 614: of_oxm_bsn_udf3 */
    -1,   /* 615: of_oxm_bsn_udf3_masked */
    -1,   /* 616: of_oxm_bsn_udf4 */
    -1,   /* 617: of_oxm_bsn_udf4_masked */
    -1,   /* 618: of_oxm_bsn_udf5 */
    -1,   /* 619: of_oxm_bsn_udf5_masked */
    -1,   /* 620: of_oxm_bsn_udf6 */
    -1,   /* 621: of_oxm_bsn_udf6_masked */
    -1,   /* 622: of_oxm_bsn_udf7 */
    -1,   /* 623: of_oxm_bsn_udf7_masked */
    -1,   /* 624: of_oxm_bsn_vfi */
    -1,   /* 625: of_oxm_bsn_vfi_masked */
    -1,   /* 626: of_oxm_bsn_vlan_xlate_port_group_id */
    -1,   /* 627: of_oxm_bsn_vlan_xlate_port_group_id_masked */
    -1,   /* 628: of_oxm_bsn_vrf */
    -1,   /* 629: of_oxm_bsn_vrf_masked */
    -1,   /* 630: of_oxm_bsn_vxlan_network_id */
    -1,   /* 631: of_oxm_bsn_vxlan_network_id_masked */
    -1,   /* 632: of_oxm_conn_tracking_ipv6_dst */
    -1,   /* 633: of_oxm_conn_tracking_ipv6_dst_masked */
    -1,   /* 634: of_oxm_conn_tracking_ipv6_src */
    -1,   /* 635: of_oxm_conn_tracking_ipv6_src_masked */
    -1,   /* 636: of_oxm_conn_tracking_label */
    -1,   /* 637: of_oxm_conn_tracking_label_masked */
    -1,   /* 638: of_oxm_conn_tracking_mark */
    -1,   /* 639: of_oxm_conn_tracking_mark_masked */
    -1,   /* 640: of_oxm_conn_tracking_nw_dst */
    -1,   /* 641: of_oxm_conn_tracking_nw_dst_masked */
    -1,   /* 642: of_oxm_conn_tracking_nw_proto */
    -1,   /* 643: of_oxm_conn_tracking_nw_proto_masked */
    -1,   /* 644: of_oxm_conn_tracking_nw_src */
    -1,   /* 645: of_oxm_conn_tracking_nw_src_masked */
    -1,   /* 646: of_oxm_conn_tracking_state */
    -1,   /* 647: of_oxm_conn_tracking_state_masked */
    -1,   /* 648: of_oxm_conn_tracking_tp_dst */
    -1,   /* 649: of_oxm_conn_tracking_tp_dst_masked */
    -1,   /* 650: of_oxm_conn_tracking_tp_src */
    -1,   /* 651: of_oxm_conn_tracking_tp_src_masked */
    -1,   /* 652: of_oxm_conn_tracking_zone */
    -1,   /* 653: of_oxm_conn_tracking_zone_masked */
    -1,   /* 654: of_oxm_eth_dst */
    -1,   /* 655: of_oxm_eth_dst_masked */
    -1,   /* 656: of_oxm_eth_src */
    -1,   /* 657: of_oxm_eth_src_masked */
    -1,   /* 658: of_oxm_eth_type */
    -1,   /* 659: of_oxm_eth_type_masked */
    -1,   /* 660: of_oxm_icmpv4_code */
    -1,   /* 661: of_oxm_icmpv4_code_masked */
    -1,   /* 662: of_oxm_icmpv4_type */
    -1,   /* 663: of_oxm_icmpv4_type_masked */
    -1,   /* 664: of_oxm_icmpv6_code */
    -1,   /* 665: of_oxm_icmpv6_code_masked */
    -1,   /* 666: of_oxm_icmpv6_type */
    -1,   /* 667: of_oxm_icmpv6_type_masked */
    -1,   /* 668: of_oxm_in_phy_port */
    -1,   /* 669: of_oxm_in_phy_port_masked */
    -1,   /* 670: of_oxm_in_port */
    -1,   /* 671: of_oxm_in_port_masked */
    -1,   /* 672: of_oxm_ip_dscp */
    -1,   /* 673: of_oxm_ip_dscp_masked */
    -1,   /* 674: of_oxm_ip_ecn */
    -1,   /* 675: of_oxm_ip_ecn_masked */
    -1,   /* 676: of_oxm_ip_proto */
    -1,   /* 677: of_oxm_ip_proto_masked */
    -1,   /* 678: of_oxm_ipv4_dst */
    -1,   /* 679: of_oxm_ipv4_dst_masked */
    -1,   /* 680: of_oxm_ipv4_src */
    -1,   /* 681: of_oxm_ipv4_src_masked */
    -1,   /* 682: of_oxm_ipv6_dst */
    -1,   /* 683: of_oxm_ipv6_dst_masked */
    -1,   /* 684: of_oxm_ipv6_exthdr */
    -1,   /* 685: of_oxm_ipv6_exthdr_masked */
    -1,   /* 686: of_oxm_ipv6_flabel */
    -1,   /* 687: of_oxm_ipv6_flabel_masked */
    -1,   /* 688: of_oxm_ipv6_nd_sll */
    -1,   /* 689: of_oxm_ipv6_nd_sll_masked */
    -1,   /* 690: of_oxm_ipv6_nd_target */
    -1,   /* 691: of_oxm_ipv6_nd_target_masked */
    -1,   /* 692: of_oxm_ipv6_nd_tll */
    -1,   /* 693: of_oxm_ipv6_nd_tll_masked */
    -1,   /* 694: of_oxm_ipv6_src */
    -1,   /* 695: of_oxm_ipv6_src_masked */
    -1,   /* 696: of_oxm_metadata */
    -1,   /* 697: of_oxm_metadata_masked */
    -1,   /* 698: of_oxm_mpls_bos */
    -1,   /* 699: of_oxm_mpls_bos_masked */
    -1,   /* 700: of_oxm_mpls_label */
    -1,   /* 701: of_oxm_mpls_label_masked */
    -1,   /* 702: of_oxm_mpls_tc */
    -1,   /* 703: of_oxm_mpls_tc_masked */
    -1,   /* 704: of_oxm_ovs_tcp_flags */
    -1,   /* 705: of_oxm_ovs_tcp_flags_masked */
    -1,   /* 706: of_oxm_pbb_uca */
    -1,   /* 707: of_oxm_pbb_uca_masked */
    -1,   /* 708: of_oxm_sctp_dst */
    -1,   /* 709: of_oxm_sctp_dst_masked */
    -1,   /* 710: of_oxm_sctp_src */
    -1,   /* 711: of_oxm_sctp_src_masked */
    -1,   /* 712: of_oxm_tcp_dst */
    -1,   /* 713: of_oxm_tcp_dst_masked */
    -1,   /* 714: of_oxm_tcp_src */
    -1,   /* 715: of_oxm_tcp_src_masked */
    -1,   /* 716: of_oxm_tunnel_id */
    -1,   /* 717: of_oxm_tunnel_id_masked */
    -1,   /* 718: of_oxm_tunnel_ipv4_dst */
    -1,   /* 719: of_oxm_tunnel_ipv4_dst_masked */
    -1,   /* 720: of_oxm_tunnel_ipv4_src */
    -1,   /* 721: of_oxm_tunnel_ipv4_src_masked */
    -1,   /* 722: of_oxm_udp_dst */
    -1,   /* 723: of_oxm_udp_dst_masked */
    -1,   /* 724: of_oxm_udp_src */
    -1,   /* 725: of_oxm_udp_src_masked */
    -1,   /* 726: of_oxm_vlan_pcp */
    -1,   /* 727: of_oxm_vlan_pcp_masked */
    -1,   /* 728: of_oxm_vlan_vid */
    -1,   /* 729: of_oxm_vlan_vid_masked */
    8,    /* 730: of_packet_queue */
    64,   /* 731: of_port_desc */
    -1,   /* 732: of_port_desc_prop */
    -1,   /* 733: of_port_desc_prop_bsn */
    -1,   /* 734: of_port_desc_prop_bsn_breakout */
    -1,   /* 735: of_port_desc_prop_bsn_driver_info_json */
    -1,   /* 736: of_port_desc_prop_bsn_forward_error_correction */
    -1,   /* 737: of_port_desc_prop_bsn_generation_id */
    -1,   /* 738: of_port_desc_prop_bsn_misc_capabilities */
    -1,   /* 739: of_port_desc_prop_bsn_sff_json */
    -1,   /* 740: of_port_desc_prop_bsn_speed_capabilities */
    -1,   /* 741: of_port_desc_prop_bsn_uplink */
    -1,   /* 742: of_port_desc_prop_ethernet */
    -1,   /* 743: of_port_desc_prop_experimenter */
    -1,   /* 744: of_port_desc_prop_optical */
    -1,   /* 745: of_port_mod_prop */
    -1,   /* 746: of_port_mod_prop_ethernet */
    -1,   /* 747: of_port_mod_prop_experimenter */
    -1,   /* 748: of_port_mod_prop_optical */
    104,  /* 749: of_port_stats_entry */
    -1,   /* 750: of_port_stats_prop */
    -1,   /* 751: of_port_stats_prop_ethernet */
    -1,   /* 752: of_port_stats_prop_experimenter */
    -1,   /* 753: of_port_stats_prop_experimenter_intel */
    -1,   /* 754: of_port_stats_prop_optical */
    -1,   /* 755: of_queue_desc */
    -1,   /* 756: of_queue_desc_prop */
    -1,   /* 757: of_queue_desc_prop_bsn */
    -1,   /* 758: of_queue_desc_prop_bsn_queue_name */
    -1,   /* 759: of_queue_desc_prop_experimenter */
    -1,   /* 760: of_queue_desc_prop_max_rate */
    -1,   /* 761: of_queue_desc_prop_min_rate */
    8,    /* 762: of_queue_prop */
    -1,   /* 763: of_queue_prop_experimenter */
    -1,   /* 764: of_queue_prop_max_rate */
    16,   /* 765: of_queue_prop_min_rate */
    32,   /* 766: of_queue_stats_entry */
    -1,   /* 767: of_queue_stats_prop */
    -1,   /* 768: of_queue_stats_prop_experimenter */
    -1,   /* 769: of_role_prop */
    -1,   /* 770: of_role_prop_experimenter */
    -1,   /* 771: of_table_desc */
    -1,   /* 772: of_table_feature_prop */
    -1,   /* 773: of_table_feature_prop_apply_actions */
    -1,   /* 774: of_table_feature_prop_apply_actions_miss */
    -1,   /* 775: of_table_feature_prop_apply_setfield */
    -1,   /* 776: of_table_feature_prop_apply_setfield_miss */
    -1,   /* 777: of_table_feature_prop_experimenter */
    -1,   /* 778: of_table_feature_prop_experimenter_miss */
    -1,   /* 779: of_table_feature_prop_instructions */
    -1,   /* 780: of_table_feature_prop_instructions_miss */
    -1,   /* 781: of_table_feature_prop_match */
    -1,   /* 782: of_table_feature_prop_next_tables */
    -1,   /* 783: of_table_feature_prop_next_tables_miss */
    -1,   /* 784: of_table_feature_prop_table_sync_from */
    -1,   /* 785: of_table_feature_prop_wildcards */
    -1,   /* 786: of_table_feature_prop_write_actions */
    -1,   /* 787: of_table_feature_prop_write_actions_miss */
    -1,   /* 788: of_table_feature_prop_write_setfield */
    -1,   /* 789: of_table_feature_prop_write_setfield_miss */
    -1,   /* 790: of_table_features */
    -1,   /* 791: of_table_mod_prop */
    -1,   /* 792: of_table_mod_prop_eviction */
    -1,   /* 793: of_table_mod_prop_experimenter */
    -1,   /* 794: of_table_mod_prop_vacancy */
    88,   /* 795: of_table_stats_entry */
    -1,   /* 796: of_uint32 */
    -1,   /* 797: of_uint64 */
    -1,   /* 798: of_uint8 */
    0,    /* 799: of_list_action */
    -1,   /* 800: of_list_action_id */
    -1,   /* 801: of_list_async_config_prop */
    -1,   /* 802: of_list_bsn_controller_connection */
    -1,   /* 803: of_list_bsn_debug_counter_desc_stats_entry */
    -1,   /* 804: of_list_bsn_debug_counter_stats_entry */
    -1,   /* 805: of_list_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 806: of_list_bsn_generic_stats_entry */
    -1,   /* 807: of_list_bsn_gentable_bucket_stats_entry */
    -1,   /* 808: of_list_bsn_gentable_desc_stats_entry */
    -1,   /* 809: of_list_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 810: of_list_bsn_gentable_entry_stats_entry */
    -1,   /* 811: of_list_bsn_gentable_stats_entry */
    0,    /* 812: of_list_bsn_interface */
    -1,   /* 813: of_list_bsn_lacp_stats_entry */
    -1,   /* 814: of_list_bsn_port_counter_stats_entry */
    -1,   /* 815: of_list_bsn_switch_pipeline_stats_entry */
    -1,   /* 816: of_list_bsn_table_checksum_stats_entry */
    -1,   /* 817: of_list_bsn_tlv */
    -1,   /* 818: of_list_bsn_vlan_counter_stats_entry */
    -1,   /* 819: of_list_bsn_vlan_mac */
    -1,   /* 820: of_list_bsn_vrf_counter_stats_entry */
    0,    /* 821: of_list_bucket */
    0,    /* 822: of_list_bucket_counter */
    -1,   /* 823: of_list_bundle_prop */
    0,    /* 824: of_list_flow_stats_entry */
    0,    /* 825: of_list_group_desc_stats_entry */
    0,    /* 826: of_list_group_stats_entry */
    -1,   /* 827: of_list_hello_elem */
    0,    /* 828: of_list_instruction */
    -1,   /* 829: of_list_instruction_id */
    -1,   /* 830: of_list_meter_band */
    -1,   /* 831: of_list_meter_band_stats */
    -1,   /* 832: of_list_meter_config */
    -1,   /* 833: of_list_meter_stats */
    -1,   /* 834: of_list_oxm */
    0,    /* 835: of_list_packet_queue */
    0,    /* 836: of_list_port_desc */
    -1,   /* 837: of_list_port_desc_prop */
    -1,   /* 838: of_list_port_mod_prop */
    0,    /* 839: of_list_port_stats_entry */
    -1,   /* 840: of_list_port_stats_prop */
    -1,   /* 841: of_list_queue_desc */
    -1,   /* 842: of_list_queue_desc_prop */
    0,    /* 843: of_list_queue_prop */
    0,    /* 844: of_list_queue_stats_entry */
    -1,   /* 845: of_list_queue_stats_prop */
    -1,   /* 846: of_list_role_prop */
    -1,   /* 847: of_list_table_desc */
    -1,   /* 848: of_list_table_feature_prop */
    -1,   /* 849: of_list_table_features */
    -1,   /* 850: of_list_table_mod_prop */
    0,    /* 851: of_list_table_stats_entry */
    -1,   /* 852: of_list_uint32 */
    -1,   /* 853: of_list_uint64 */
    -1    /* 854: of_list_uint8 */
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
    -1,   /* 52: of_bsn_gentable_error */
    -1,   /* 53: of_bsn_gentable_set_buckets_size */
    -1,   /* 54: of_bsn_gentable_stats_reply */
    -1,   /* 55: of_bsn_gentable_stats_request */
    16,   /* 56: of_bsn_get_interfaces_reply */
    16,   /* 57: of_bsn_get_interfaces_request */
    -1,   /* 58: of_bsn_get_ip_mask_reply */
    -1,   /* 59: of_bsn_get_ip_mask_request */
    -1,   /* 60: of_bsn_get_l2_table_reply */
    -1,   /* 61: of_bsn_get_l2_table_request */
    20,   /* 62: of_bsn_get_mirroring_reply */
    20,   /* 63: of_bsn_get_mirroring_request */
    -1,   /* 64: of_bsn_get_switch_pipeline_reply */
    -1,   /* 65: of_bsn_get_switch_pipeline_request */
    16,   /* 66: of_bsn_header */
    -1,   /* 67: of_bsn_hybrid_get_reply */
    -1,   /* 68: of_bsn_hybrid_get_request */
    -1,   /* 69: of_bsn_image_desc_stats_reply */
    -1,   /* 70: of_bsn_image_desc_stats_request */
    -1,   /* 71: of_bsn_lacp_convergence_notif */
    -1,   /* 72: of_bsn_lacp_stats_reply */
    -1,   /* 73: of_bsn_lacp_stats_request */
    -1,   /* 74: of_bsn_log */
    -1,   /* 75: of_bsn_lua_command_reply */
    -1,   /* 76: of_bsn_lua_command_request */
    -1,   /* 77: of_bsn_lua_notification */
    -1,   /* 78: of_bsn_lua_upload */
    25,   /* 79: of_bsn_pdu_rx_reply */
    28,   /* 80: of_bsn_pdu_rx_request */
    21,   /* 81: of_bsn_pdu_rx_timeout */
    25,   /* 82: of_bsn_pdu_tx_reply */
    28,   /* 83: of_bsn_pdu_tx_request */
    -1,   /* 84: of_bsn_port_counter_stats_reply */
    -1,   /* 85: of_bsn_port_counter_stats_request */
    -1,   /* 86: of_bsn_role_status */
    -1,   /* 87: of_bsn_set_aux_cxns_reply */
    -1,   /* 88: of_bsn_set_aux_cxns_request */
    -1,   /* 89: of_bsn_set_ip_mask */
    -1,   /* 90: of_bsn_set_l2_table_reply */
    -1,   /* 91: of_bsn_set_l2_table_request */
    -1,   /* 92: of_bsn_set_lacp_reply */
    -1,   /* 93: of_bsn_set_lacp_request */
    20,   /* 94: of_bsn_set_mirroring */
    20,   /* 95: of_bsn_set_pktin_suppression_reply */
    32,   /* 96: of_bsn_set_pktin_suppression_request */
    -1,   /* 97: of_bsn_set_switch_pipeline_reply */
    -1,   /* 98: of_bsn_set_switch_pipeline_request */
    -1,   /* 99: of_bsn_shell_command */
    -1,   /* 100: of_bsn_shell_output */
    -1,   /* 101: of_bsn_shell_status */
    24,   /* 102: of_bsn_stats_reply */
    24,   /* 103: of_bsn_stats_request */
    -1,   /* 104: of_bsn_switch_pipeline_stats_reply */
    -1,   /* 105: of_bsn_switch_pipeline_stats_request */
    -1,   /* 106: of_bsn_table_checksum_stats_reply */
    -1,   /* 107: of_bsn_table_checksum_stats_request */
    -1,   /* 108: of_bsn_table_set_buckets_size */
    -1,   /* 109: of_bsn_takeover */
    -1,   /* 110: of_bsn_time_reply */
    -1,   /* 111: of_bsn_time_request */
    24,   /* 112: of_bsn_virtual_port_create_reply */
    20,   /* 113: of_bsn_virtual_port_create_request */
    20,   /* 114: of_bsn_virtual_port_remove_reply */
    20,   /* 115: of_bsn_virtual_port_remove_request */
    -1,   /* 116: of_bsn_vlan_counter_clear */
    -1,   /* 117: of_bsn_vlan_counter_stats_reply */
    -1,   /* 118: of_bsn_vlan_counter_stats_request */
    -1,   /* 119: of_bsn_vrf_counter_stats_reply */
    -1,   /* 120: of_bsn_vrf_counter_stats_request */
    -1,   /* 121: of_bundle_add_msg */
    -1,   /* 122: of_bundle_ctrl_msg */
    -1,   /* 123: of_bundle_failed_error_msg */
    1072, /* 124: of_desc_stats_reply */
    16,   /* 125: of_desc_stats_request */
    8,    /* 126: of_echo_reply */
    8,    /* 127: of_echo_request */
    10,   /* 128: of_error_msg */
    16,   /* 129: of_experimenter */
    16,   /* 130: of_experimenter_error_msg */
    24,   /* 131: of_experimenter_stats_reply */
    24,   /* 132: of_experimenter_stats_request */
    32,   /* 133: of_features_reply */
    8,    /* 134: of_features_request */
    56,   /* 135: of_flow_add */
    56,   /* 136: of_flow_delete */
    56,   /* 137: of_flow_delete_strict */
    56,   /* 138: of_flow_mod */
    12,   /* 139: of_flow_mod_failed_error_msg */
    56,   /* 140: of_flow_modify */
    56,   /* 141: of_flow_modify_strict */
    -1,   /* 142: of_flow_monitor_failed_error_msg */
    56,   /* 143: of_flow_removed */
    16,   /* 144: of_flow_stats_reply */
    56,   /* 145: of_flow_stats_request */
    12,   /* 146: of_get_config_reply */
    8,    /* 147: of_get_config_request */
    16,   /* 148: of_group_add */
    16,   /* 149: of_group_delete */
    16,   /* 150: of_group_desc_stats_reply */
    16,   /* 151: of_group_desc_stats_request */
    56,   /* 152: of_group_features_stats_reply */
    16,   /* 153: of_group_features_stats_request */
    16,   /* 154: of_group_mod */
    12,   /* 155: of_group_mod_failed_error_msg */
    16,   /* 156: of_group_modify */
    16,   /* 157: of_group_stats_reply */
    24,   /* 158: of_group_stats_request */
    8,    /* 159: of_header */
    8,    /* 160: of_hello */
    12,   /* 161: of_hello_failed_error_msg */
    -1,   /* 162: of_meter_config_stats_reply */
    -1,   /* 163: of_meter_config_stats_request */
    -1,   /* 164: of_meter_features_stats_reply */
    -1,   /* 165: of_meter_features_stats_request */
    -1,   /* 166: of_meter_mod */
    -1,   /* 167: of_meter_mod_failed_error_msg */
    -1,   /* 168: of_meter_stats_reply */
    -1,   /* 169: of_meter_stats_request */
    -1,   /* 170: of_nicira_controller_role_reply */
    -1,   /* 171: of_nicira_controller_role_request */
    16,   /* 172: of_nicira_header */
    26,   /* 173: of_packet_in */
    24,   /* 174: of_packet_out */
    -1,   /* 175: of_port_desc_stats_reply */
    -1,   /* 176: of_port_desc_stats_request */
    40,   /* 177: of_port_mod */
    12,   /* 178: of_port_mod_failed_error_msg */
    16,   /* 179: of_port_stats_reply */
    24,   /* 180: of_port_stats_request */
    80,   /* 181: of_port_status */
    -1,   /* 182: of_queue_desc_stats_reply */
    -1,   /* 183: of_queue_desc_stats_request */
    16,   /* 184: of_queue_get_config_reply */
    16,   /* 185: of_queue_get_config_request */
    12,   /* 186: of_queue_op_failed_error_msg */
    16,   /* 187: of_queue_stats_reply */
    24,   /* 188: of_queue_stats_request */
    -1,   /* 189: of_requestforward */
    24,   /* 190: of_role_reply */
    24,   /* 191: of_role_request */
    12,   /* 192: of_role_request_failed_error_msg */
    -1,   /* 193: of_role_status */
    12,   /* 194: of_set_config */
    16,   /* 195: of_stats_reply */
    16,   /* 196: of_stats_request */
    12,   /* 197: of_switch_config_failed_error_msg */
    -1,   /* 198: of_table_desc_stats_reply */
    -1,   /* 199: of_table_desc_stats_request */
    -1,   /* 200: of_table_features_failed_error_msg */
    -1,   /* 201: of_table_features_stats_reply */
    -1,   /* 202: of_table_features_stats_request */
    16,   /* 203: of_table_mod */
    12,   /* 204: of_table_mod_failed_error_msg */
    16,   /* 205: of_table_stats_reply */
    16,   /* 206: of_table_stats_request */
    -1,   /* 207: of_table_status */
    8,    /* 208: of_action */
    16,   /* 209: of_action_bsn */
    28,   /* 210: of_action_bsn_checksum */
    -1,   /* 211: of_action_bsn_gentable */
    24,   /* 212: of_action_bsn_mirror */
    16,   /* 213: of_action_bsn_set_tunnel_dst */
    8,    /* 214: of_action_copy_ttl_in */
    8,    /* 215: of_action_copy_ttl_out */
    8,    /* 216: of_action_dec_mpls_ttl */
    8,    /* 217: of_action_dec_nw_ttl */
    -1,   /* 218: of_action_enqueue */
    8,    /* 219: of_action_experimenter */
    8,    /* 220: of_action_group */
    -1,   /* 221: of_action_id */
    -1,   /* 222: of_action_id_bsn */
    -1,   /* 223: of_action_id_bsn_checksum */
    -1,   /* 224: of_action_id_bsn_gentable */
    -1,   /* 225: of_action_id_bsn_mirror */
    -1,   /* 226: of_action_id_bsn_set_tunnel_dst */
    -1,   /* 227: of_action_id_copy_ttl_in */
    -1,   /* 228: of_action_id_copy_ttl_out */
    -1,   /* 229: of_action_id_dec_mpls_ttl */
    -1,   /* 230: of_action_id_dec_nw_ttl */
    -1,   /* 231: of_action_id_experimenter */
    -1,   /* 232: of_action_id_group */
    -1,   /* 233: of_action_id_nicira */
    -1,   /* 234: of_action_id_nicira_dec_ttl */
    -1,   /* 235: of_action_id_output */
    -1,   /* 236: of_action_id_pop_mpls */
    -1,   /* 237: of_action_id_pop_pbb */
    -1,   /* 238: of_action_id_pop_vlan */
    -1,   /* 239: of_action_id_push_mpls */
    -1,   /* 240: of_action_id_push_pbb */
    -1,   /* 241: of_action_id_push_vlan */
    -1,   /* 242: of_action_id_set_field */
    -1,   /* 243: of_action_id_set_mpls_ttl */
    -1,   /* 244: of_action_id_set_nw_ttl */
    -1,   /* 245: of_action_id_set_queue */
    16,   /* 246: of_action_nicira */
    16,   /* 247: of_action_nicira_dec_ttl */
    16,   /* 248: of_action_output */
    8,    /* 249: of_action_pop_mpls */
    -1,   /* 250: of_action_pop_pbb */
    8,    /* 251: of_action_pop_vlan */
    8,    /* 252: of_action_push_mpls */
    -1,   /* 253: of_action_push_pbb */
    8,    /* 254: of_action_push_vlan */
    -1,   /* 255: of_action_set_dl_dst */
    -1,   /* 256: of_action_set_dl_src */
    8,    /* 257: of_action_set_field */
    -1,   /* 258: of_action_set_mpls_label */
    -1,   /* 259: of_action_set_mpls_tc */
    8,    /* 260: of_action_set_mpls_ttl */
    -1,   /* 261: of_action_set_nw_dst */
    -1,   /* 262: of_action_set_nw_ecn */
    -1,   /* 263: of_action_set_nw_src */
    -1,   /* 264: of_action_set_nw_tos */
    8,    /* 265: of_action_set_nw_ttl */
    8,    /* 266: of_action_set_queue */
    -1,   /* 267: of_action_set_tp_dst */
    -1,   /* 268: of_action_set_tp_src */
    -1,   /* 269: of_action_set_vlan_pcp */
    -1,   /* 270: of_action_set_vlan_vid */
    -1,   /* 271: of_action_strip_vlan */
    -1,   /* 272: of_async_config_prop */
    -1,   /* 273: of_async_config_prop_experimenter_master */
    -1,   /* 274: of_async_config_prop_experimenter_slave */
    -1,   /* 275: of_async_config_prop_flow_removed_master */
    -1,   /* 276: of_async_config_prop_flow_removed_slave */
    -1,   /* 277: of_async_config_prop_packet_in_master */
    -1,   /* 278: of_async_config_prop_packet_in_slave */
    -1,   /* 279: of_async_config_prop_port_status_master */
    -1,   /* 280: of_async_config_prop_port_status_slave */
    -1,   /* 281: of_async_config_prop_requestforward_master */
    -1,   /* 282: of_async_config_prop_requestforward_slave */
    -1,   /* 283: of_async_config_prop_role_status_master */
    -1,   /* 284: of_async_config_prop_role_status_slave */
    -1,   /* 285: of_async_config_prop_table_status_master */
    -1,   /* 286: of_async_config_prop_table_status_slave */
    -1,   /* 287: of_bsn_controller_connection */
    -1,   /* 288: of_bsn_debug_counter_desc_stats_entry */
    -1,   /* 289: of_bsn_debug_counter_stats_entry */
    -1,   /* 290: of_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 291: of_bsn_generic_stats_entry */
    -1,   /* 292: of_bsn_gentable_bucket_stats_entry */
    -1,   /* 293: of_bsn_gentable_desc_stats_entry */
    -1,   /* 294: of_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 295: of_bsn_gentable_entry_stats_entry */
    -1,   /* 296: of_bsn_gentable_stats_entry */
    32,   /* 297: of_bsn_interface */
    -1,   /* 298: of_bsn_lacp_stats_entry */
    -1,   /* 299: of_bsn_port_counter_stats_entry */
    -1,   /* 300: of_bsn_switch_pipeline_stats_entry */
    -1,   /* 301: of_bsn_table_checksum_stats_entry */
    -1,   /* 302: of_bsn_tlv */
    -1,   /* 303: of_bsn_tlv_actor_key */
    -1,   /* 304: of_bsn_tlv_actor_port_num */
    -1,   /* 305: of_bsn_tlv_actor_port_priority */
    -1,   /* 306: of_bsn_tlv_actor_state */
    -1,   /* 307: of_bsn_tlv_actor_system_mac */
    -1,   /* 308: of_bsn_tlv_actor_system_priority */
    -1,   /* 309: of_bsn_tlv_anchor */
    -1,   /* 310: of_bsn_tlv_apply_bytes */
    -1,   /* 311: of_bsn_tlv_apply_packets */
    -1,   /* 312: of_bsn_tlv_auto_negotiation */
    -1,   /* 313: of_bsn_tlv_bfd_endpoint */
    -1,   /* 314: of_bsn_tlv_bfd_state */
    -1,   /* 315: of_bsn_tlv_broadcast_query_timeout */
    -1,   /* 316: of_bsn_tlv_broadcast_rate */
    -1,   /* 317: of_bsn_tlv_bucket */
    -1,   /* 318: of_bsn_tlv_circuit_id */
    -1,   /* 319: of_bsn_tlv_convergence_status */
    -1,   /* 320: of_bsn_tlv_cpu_lag */
    -1,   /* 321: of_bsn_tlv_crc_enabled */
    -1,   /* 322: of_bsn_tlv_data */
    -1,   /* 323: of_bsn_tlv_data_mask */
    -1,   /* 324: of_bsn_tlv_decap */
    -1,   /* 325: of_bsn_tlv_disable_src_mac_check */
    -1,   /* 326: of_bsn_tlv_drop */
    -1,   /* 327: of_bsn_tlv_dscp */
    -1,   /* 328: of_bsn_tlv_ecn */
    -1,   /* 329: of_bsn_tlv_egress_only */
    -1,   /* 330: of_bsn_tlv_egress_port_group_id */
    -1,   /* 331: of_bsn_tlv_encap */
    -1,   /* 332: of_bsn_tlv_enhanced_hash_capability */
    -1,   /* 333: of_bsn_tlv_eth_dst */
    -1,   /* 334: of_bsn_tlv_eth_src */
    -1,   /* 335: of_bsn_tlv_eth_type */
    -1,   /* 336: of_bsn_tlv_external_gateway_ip */
    -1,   /* 337: of_bsn_tlv_external_gateway_mac */
    -1,   /* 338: of_bsn_tlv_external_ip */
    -1,   /* 339: of_bsn_tlv_external_mac */
    -1,   /* 340: of_bsn_tlv_external_netmask */
    -1,   /* 341: of_bsn_tlv_fabric_port_role */
    -1,   /* 342: of_bsn_tlv_flood */
    -1,   /* 343: of_bsn_tlv_flow_classifier */
    -1,   /* 344: of_bsn_tlv_flow_classify */
    -1,   /* 345: of_bsn_tlv_flow_identifier */
    -1,   /* 346: of_bsn_tlv_force_link_up */
    -1,   /* 347: of_bsn_tlv_forward_error_correction */
    -1,   /* 348: of_bsn_tlv_generation_id */
    -1,   /* 349: of_bsn_tlv_hash_algorithm */
    -1,   /* 350: of_bsn_tlv_hash_gtp_header_match */
    -1,   /* 351: of_bsn_tlv_hash_gtp_port_match */
    -1,   /* 352: of_bsn_tlv_hash_packet_field */
    -1,   /* 353: of_bsn_tlv_hash_packet_type */
    -1,   /* 354: of_bsn_tlv_hash_seed */
    -1,   /* 355: of_bsn_tlv_hash_type */
    -1,   /* 356: of_bsn_tlv_header_size */
    -1,   /* 357: of_bsn_tlv_icmp_code */
    -1,   /* 358: of_bsn_tlv_icmp_id */
    -1,   /* 359: of_bsn_tlv_icmp_type */
    -1,   /* 360: of_bsn_tlv_icmpv6_chksum */
    -1,   /* 361: of_bsn_tlv_identifier */
    -1,   /* 362: of_bsn_tlv_idle_notification */
    -1,   /* 363: of_bsn_tlv_idle_time */
    -1,   /* 364: of_bsn_tlv_idle_timeout */
    -1,   /* 365: of_bsn_tlv_igmp_snooping */
    -1,   /* 366: of_bsn_tlv_ingress_port_group_id */
    -1,   /* 367: of_bsn_tlv_internal_gateway_mac */
    -1,   /* 368: of_bsn_tlv_internal_mac */
    -1,   /* 369: of_bsn_tlv_interval */
    -1,   /* 370: of_bsn_tlv_ip_proto */
    -1,   /* 371: of_bsn_tlv_ip_tunnel_type */
    -1,   /* 372: of_bsn_tlv_ipv4 */
    -1,   /* 373: of_bsn_tlv_ipv4_dst */
    -1,   /* 374: of_bsn_tlv_ipv4_netmask */
    -1,   /* 375: of_bsn_tlv_ipv4_src */
    -1,   /* 376: of_bsn_tlv_ipv6 */
    -1,   /* 377: of_bsn_tlv_ipv6_dst */
    -1,   /* 378: of_bsn_tlv_ipv6_prefix */
    -1,   /* 379: of_bsn_tlv_ipv6_src */
    -1,   /* 380: of_bsn_tlv_known_multicast_rate */
    -1,   /* 381: of_bsn_tlv_l2_multicast_lookup */
    -1,   /* 382: of_bsn_tlv_l3 */
    -1,   /* 383: of_bsn_tlv_l3_dst_class_id */
    -1,   /* 384: of_bsn_tlv_l3_interface_class_id */
    -1,   /* 385: of_bsn_tlv_l3_src_class_id */
    -1,   /* 386: of_bsn_tlv_lag_options */
    -1,   /* 387: of_bsn_tlv_loopback_mode */
    -1,   /* 388: of_bsn_tlv_loopback_port */
    -1,   /* 389: of_bsn_tlv_lr_all_enabled */
    -1,   /* 390: of_bsn_tlv_mac */
    -1,   /* 391: of_bsn_tlv_mac_mask */
    -1,   /* 392: of_bsn_tlv_mcg_type_vxlan */
    -1,   /* 393: of_bsn_tlv_miss_packets */
    -1,   /* 394: of_bsn_tlv_mpls_control_word */
    -1,   /* 395: of_bsn_tlv_mpls_label */
    -1,   /* 396: of_bsn_tlv_mpls_sequenced */
    -1,   /* 397: of_bsn_tlv_multicast_interface_id */
    -1,   /* 398: of_bsn_tlv_multicast_packet */
    -1,   /* 399: of_bsn_tlv_multiplier */
    -1,   /* 400: of_bsn_tlv_name */
    -1,   /* 401: of_bsn_tlv_ndp_offload */
    -1,   /* 402: of_bsn_tlv_ndp_static */
    -1,   /* 403: of_bsn_tlv_negate */
    -1,   /* 404: of_bsn_tlv_next_hop_ipv4 */
    -1,   /* 405: of_bsn_tlv_next_hop_mac */
    -1,   /* 406: of_bsn_tlv_nexthop_type_vxlan */
    -1,   /* 407: of_bsn_tlv_no_arp_response */
    -1,   /* 408: of_bsn_tlv_no_ns_response */
    -1,   /* 409: of_bsn_tlv_offset */
    -1,   /* 410: of_bsn_tlv_optics_always_enabled */
    -1,   /* 411: of_bsn_tlv_outer_src_mac */
    -1,   /* 412: of_bsn_tlv_parent_port */
    -1,   /* 413: of_bsn_tlv_partner_key */
    -1,   /* 414: of_bsn_tlv_partner_port_num */
    -1,   /* 415: of_bsn_tlv_partner_port_priority */
    -1,   /* 416: of_bsn_tlv_partner_state */
    -1,   /* 417: of_bsn_tlv_partner_system_mac */
    -1,   /* 418: of_bsn_tlv_partner_system_priority */
    -1,   /* 419: of_bsn_tlv_passive */
    -1,   /* 420: of_bsn_tlv_pdua_rx_instance */
    -1,   /* 421: of_bsn_tlv_pim_dr */
    -1,   /* 422: of_bsn_tlv_pim_hello_flood */
    -1,   /* 423: of_bsn_tlv_port */
    -1,   /* 424: of_bsn_tlv_port_mode */
    -1,   /* 425: of_bsn_tlv_port_speed_gbps */
    -1,   /* 426: of_bsn_tlv_port_usage */
    -1,   /* 427: of_bsn_tlv_port_vxlan_mode */
    -1,   /* 428: of_bsn_tlv_priority */
    -1,   /* 429: of_bsn_tlv_push_vlan_on_egress */
    -1,   /* 430: of_bsn_tlv_push_vlan_on_ingress */
    -1,   /* 431: of_bsn_tlv_qos_priority */
    -1,   /* 432: of_bsn_tlv_queue_id */
    -1,   /* 433: of_bsn_tlv_queue_weight */
    -1,   /* 434: of_bsn_tlv_rate_limit */
    -1,   /* 435: of_bsn_tlv_rate_unit */
    -1,   /* 436: of_bsn_tlv_record_packets */
    -1,   /* 437: of_bsn_tlv_reference */
    -1,   /* 438: of_bsn_tlv_reply_packets */
    -1,   /* 439: of_bsn_tlv_request_packets */
    -1,   /* 440: of_bsn_tlv_rest_server */
    -1,   /* 441: of_bsn_tlv_routing_param */
    -1,   /* 442: of_bsn_tlv_rx_bytes */
    -1,   /* 443: of_bsn_tlv_rx_packets */
    -1,   /* 444: of_bsn_tlv_sampling_rate */
    -1,   /* 445: of_bsn_tlv_set_loopback_mode */
    -1,   /* 446: of_bsn_tlv_status */
    -1,   /* 447: of_bsn_tlv_strip_mpls_l2_on_ingress */
    -1,   /* 448: of_bsn_tlv_strip_mpls_l3_on_ingress */
    -1,   /* 449: of_bsn_tlv_strip_vlan_on_egress */
    -1,   /* 450: of_bsn_tlv_sub_agent_id */
    -1,   /* 451: of_bsn_tlv_tcp_dst */
    -1,   /* 452: of_bsn_tlv_tcp_flags */
    -1,   /* 453: of_bsn_tlv_tcp_src */
    -1,   /* 454: of_bsn_tlv_timestamp */
    -1,   /* 455: of_bsn_tlv_ttl */
    -1,   /* 456: of_bsn_tlv_tunnel_capability */
    -1,   /* 457: of_bsn_tlv_tx_bytes */
    -1,   /* 458: of_bsn_tlv_tx_packets */
    -1,   /* 459: of_bsn_tlv_udf_anchor */
    -1,   /* 460: of_bsn_tlv_udf_capability */
    -1,   /* 461: of_bsn_tlv_udf_id */
    -1,   /* 462: of_bsn_tlv_udf_length */
    -1,   /* 463: of_bsn_tlv_udf_offset */
    -1,   /* 464: of_bsn_tlv_udp_dst */
    -1,   /* 465: of_bsn_tlv_udp_src */
    -1,   /* 466: of_bsn_tlv_uint32 */
    -1,   /* 467: of_bsn_tlv_uint64_list */
    -1,   /* 468: of_bsn_tlv_unicast_query_timeout */
    -1,   /* 469: of_bsn_tlv_unicast_rate */
    -1,   /* 470: of_bsn_tlv_unknown_multicast_rate */
    -1,   /* 471: of_bsn_tlv_untagged */
    -1,   /* 472: of_bsn_tlv_upgrade */
    -1,   /* 473: of_bsn_tlv_uri_scheme */
    -1,   /* 474: of_bsn_tlv_use_packet_state */
    -1,   /* 475: of_bsn_tlv_user_configured */
    -1,   /* 476: of_bsn_tlv_vfi */
    -1,   /* 477: of_bsn_tlv_vfp_class_id */
    -1,   /* 478: of_bsn_tlv_virtual */
    -1,   /* 479: of_bsn_tlv_vlan_mac_list */
    -1,   /* 480: of_bsn_tlv_vlan_pcp */
    -1,   /* 481: of_bsn_tlv_vlan_vid */
    -1,   /* 482: of_bsn_tlv_vlan_vid_mask */
    -1,   /* 483: of_bsn_tlv_vni */
    -1,   /* 484: of_bsn_tlv_vpn_key */
    -1,   /* 485: of_bsn_tlv_vrf */
    -1,   /* 486: of_bsn_tlv_vxlan_egress_lag */
    -1,   /* 487: of_bsn_vlan_counter_stats_entry */
    -1,   /* 488: of_bsn_vlan_mac */
    4,    /* 489: of_bsn_vport */
    64,   /* 490: of_bsn_vport_l2gre */
    32,   /* 491: of_bsn_vport_q_in_q */
    -1,   /* 492: of_bsn_vrf_counter_stats_entry */
    16,   /* 493: of_bucket */
    16,   /* 494: of_bucket_counter */
    -1,   /* 495: of_bundle_prop */
    -1,   /* 496: of_bundle_prop_experimenter */
    56,   /* 497: of_flow_stats_entry */
    8,    /* 498: of_group_desc_stats_entry */
    32,   /* 499: of_group_stats_entry */
    -1,   /* 500: of_hello_elem */
    -1,   /* 501: of_hello_elem_versionbitmap */
    8,    /* 502: of_instruction */
    8,    /* 503: of_instruction_apply_actions */
    -1,   /* 504: of_instruction_bsn */
    -1,   /* 505: of_instruction_bsn_arp_offload */
    -1,   /* 506: of_instruction_bsn_auto_negotiation */
    -1,   /* 507: of_instruction_bsn_deny */
    -1,   /* 508: of_instruction_bsn_dhcp_offload */
    -1,   /* 509: of_instruction_bsn_directed_broadcast */
    -1,   /* 510: of_instruction_bsn_disable_l3 */
    -1,   /* 511: of_instruction_bsn_disable_split_horizon_check */
    -1,   /* 512: of_instruction_bsn_disable_src_mac_check */
    -1,   /* 513: of_instruction_bsn_disable_vlan_counters */
    -1,   /* 514: of_instruction_bsn_hash_select */
    -1,   /* 515: of_instruction_bsn_internal_priority */
    -1,   /* 516: of_instruction_bsn_ndp_offload */
    -1,   /* 517: of_instruction_bsn_packet_of_death */
    -1,   /* 518: of_instruction_bsn_permit */
    -1,   /* 519: of_instruction_bsn_prioritize_pdus */
    -1,   /* 520: of_instruction_bsn_require_vlan_xlate */
    -1,   /* 521: of_instruction_bsn_span_destination */
    8,    /* 522: of_instruction_clear_actions */
    8,    /* 523: of_instruction_experimenter */
    8,    /* 524: of_instruction_goto_table */
    -1,   /* 525: of_instruction_id */
    -1,   /* 526: of_instruction_id_apply_actions */
    -1,   /* 527: of_instruction_id_bsn */
    -1,   /* 528: of_instruction_id_bsn_arp_offload */
    -1,   /* 529: of_instruction_id_bsn_auto_negotiation */
    -1,   /* 530: of_instruction_id_bsn_deny */
    -1,   /* 531: of_instruction_id_bsn_dhcp_offload */
    -1,   /* 532: of_instruction_id_bsn_directed_broadcast */
    -1,   /* 533: of_instruction_id_bsn_disable_l3 */
    -1,   /* 534: of_instruction_id_bsn_disable_split_horizon_check */
    -1,   /* 535: of_instruction_id_bsn_disable_src_mac_check */
    -1,   /* 536: of_instruction_id_bsn_disable_vlan_counters */
    -1,   /* 537: of_instruction_id_bsn_hash_select */
    -1,   /* 538: of_instruction_id_bsn_internal_priority */
    -1,   /* 539: of_instruction_id_bsn_ndp_offload */
    -1,   /* 540: of_instruction_id_bsn_packet_of_death */
    -1,   /* 541: of_instruction_id_bsn_permit */
    -1,   /* 542: of_instruction_id_bsn_prioritize_pdus */
    -1,   /* 543: of_instruction_id_bsn_require_vlan_xlate */
    -1,   /* 544: of_instruction_id_bsn_span_destination */
    -1,   /* 545: of_instruction_id_clear_actions */
    -1,   /* 546: of_instruction_id_experimenter */
    -1,   /* 547: of_instruction_id_goto_table */
    -1,   /* 548: of_instruction_id_meter */
    -1,   /* 549: of_instruction_id_write_actions */
    -1,   /* 550: of_instruction_id_write_metadata */
    -1,   /* 551: of_instruction_meter */
    8,    /* 552: of_instruction_write_actions */
    24,   /* 553: of_instruction_write_metadata */
    -1,   /* 554: of_match_v1 */
    -1,   /* 555: of_match_v2 */
    4,    /* 556: of_match_v3 */
    -1,   /* 557: of_meter_band */
    -1,   /* 558: of_meter_band_drop */
    -1,   /* 559: of_meter_band_dscp_remark */
    -1,   /* 560: of_meter_band_experimenter */
    -1,   /* 561: of_meter_band_stats */
    -1,   /* 562: of_meter_config */
    -1,   /* 563: of_meter_features */
    -1,   /* 564: of_meter_stats */
    4,    /* 565: of_oxm */
    6,    /* 566: of_oxm_arp_op */
    8,    /* 567: of_oxm_arp_op_masked */
    10,   /* 568: of_oxm_arp_sha */
    16,   /* 569: of_oxm_arp_sha_masked */
    8,    /* 570: of_oxm_arp_spa */
    12,   /* 571: of_oxm_arp_spa_masked */
    10,   /* 572: of_oxm_arp_tha */
    16,   /* 573: of_oxm_arp_tha_masked */
    8,    /* 574: of_oxm_arp_tpa */
    12,   /* 575: of_oxm_arp_tpa_masked */
    8,    /* 576: of_oxm_bsn_egr_port_group_id */
    12,   /* 577: of_oxm_bsn_egr_port_group_id_masked */
    5,    /* 578: of_oxm_bsn_global_vrf_allowed */
    6,    /* 579: of_oxm_bsn_global_vrf_allowed_masked */
    -1,   /* 580: of_oxm_bsn_ifp_class_id */
    -1,   /* 581: of_oxm_bsn_ifp_class_id_masked */
    20,   /* 582: of_oxm_bsn_in_ports_128 */
    36,   /* 583: of_oxm_bsn_in_ports_128_masked */
    68,   /* 584: of_oxm_bsn_in_ports_512 */
    132,  /* 585: of_oxm_bsn_in_ports_512_masked */
    8,    /* 586: of_oxm_bsn_ingress_port_group_id */
    12,   /* 587: of_oxm_bsn_ingress_port_group_id_masked */
    -1,   /* 588: of_oxm_bsn_inner_eth_dst */
    -1,   /* 589: of_oxm_bsn_inner_eth_dst_masked */
    -1,   /* 590: of_oxm_bsn_inner_eth_src */
    -1,   /* 591: of_oxm_bsn_inner_eth_src_masked */
    -1,   /* 592: of_oxm_bsn_inner_vlan_vid */
    -1,   /* 593: of_oxm_bsn_inner_vlan_vid_masked */
    5,    /* 594: of_oxm_bsn_ip_fragmentation */
    6,    /* 595: of_oxm_bsn_ip_fragmentation_masked */
    5,    /* 596: of_oxm_bsn_l2_cache_hit */
    6,    /* 597: of_oxm_bsn_l2_cache_hit_masked */
    8,    /* 598: of_oxm_bsn_l3_dst_class_id */
    12,   /* 599: of_oxm_bsn_l3_dst_class_id_masked */
    8,    /* 600: of_oxm_bsn_l3_interface_class_id */
    12,   /* 601: of_oxm_bsn_l3_interface_class_id_masked */
    8,    /* 602: of_oxm_bsn_l3_src_class_id */
    12,   /* 603: of_oxm_bsn_l3_src_class_id_masked */
    8,    /* 604: of_oxm_bsn_lag_id */
    12,   /* 605: of_oxm_bsn_lag_id_masked */
    6,    /* 606: of_oxm_bsn_tcp_flags */
    8,    /* 607: of_oxm_bsn_tcp_flags_masked */
    8,    /* 608: of_oxm_bsn_udf0 */
    12,   /* 609: of_oxm_bsn_udf0_masked */
    8,    /* 610: of_oxm_bsn_udf1 */
    12,   /* 611: of_oxm_bsn_udf1_masked */
    8,    /* 612: of_oxm_bsn_udf2 */
    12,   /* 613: of_oxm_bsn_udf2_masked */
    8,    /* 614: of_oxm_bsn_udf3 */
    12,   /* 615: of_oxm_bsn_udf3_masked */
    8,    /* 616: of_oxm_bsn_udf4 */
    12,   /* 617: of_oxm_bsn_udf4_masked */
    8,    /* 618: of_oxm_bsn_udf5 */
    12,   /* 619: of_oxm_bsn_udf5_masked */
    8,    /* 620: of_oxm_bsn_udf6 */
    12,   /* 621: of_oxm_bsn_udf6_masked */
    8,    /* 622: of_oxm_bsn_udf7 */
    12,   /* 623: of_oxm_bsn_udf7_masked */
    -1,   /* 624: of_oxm_bsn_vfi */
    -1,   /* 625: of_oxm_bsn_vfi_masked */
    8,    /* 626: of_oxm_bsn_vlan_xlate_port_group_id */
    12,   /* 627: of_oxm_bsn_vlan_xlate_port_group_id_masked */
    8,    /* 628: of_oxm_bsn_vrf */
    12,   /* 629: of_oxm_bsn_vrf_masked */
    -1,   /* 630: of_oxm_bsn_vxlan_network_id */
    -1,   /* 631: of_oxm_bsn_vxlan_network_id_masked */
    20,   /* 632: of_oxm_conn_tracking_ipv6_dst */
    36,   /* 633: of_oxm_conn_tracking_ipv6_dst_masked */
    20,   /* 634: of_oxm_conn_tracking_ipv6_src */
    36,   /* 635: of_oxm_conn_tracking_ipv6_src_masked */
    20,   /* 636: of_oxm_conn_tracking_label */
    36,   /* 637: of_oxm_conn_tracking_label_masked */
    8,    /* 638: of_oxm_conn_tracking_mark */
    12,   /* 639: of_oxm_conn_tracking_mark_masked */
    8,    /* 640: of_oxm_conn_tracking_nw_dst */
    12,   /* 641: of_oxm_conn_tracking_nw_dst_masked */
    5,    /* 642: of_oxm_conn_tracking_nw_proto */
    6,    /* 643: of_oxm_conn_tracking_nw_proto_masked */
    8,    /* 644: of_oxm_conn_tracking_nw_src */
    12,   /* 645: of_oxm_conn_tracking_nw_src_masked */
    8,    /* 646: of_oxm_conn_tracking_state */
    12,   /* 647: of_oxm_conn_tracking_state_masked */
    6,    /* 648: of_oxm_conn_tracking_tp_dst */
    8,    /* 649: of_oxm_conn_tracking_tp_dst_masked */
    6,    /* 650: of_oxm_conn_tracking_tp_src */
    8,    /* 651: of_oxm_conn_tracking_tp_src_masked */
    6,    /* 652: of_oxm_conn_tracking_zone */
    8,    /* 653: of_oxm_conn_tracking_zone_masked */
    10,   /* 654: of_oxm_eth_dst */
    16,   /* 655: of_oxm_eth_dst_masked */
    10,   /* 656: of_oxm_eth_src */
    16,   /* 657: of_oxm_eth_src_masked */
    6,    /* 658: of_oxm_eth_type */
    8,    /* 659: of_oxm_eth_type_masked */
    5,    /* 660: of_oxm_icmpv4_code */
    6,    /* 661: of_oxm_icmpv4_code_masked */
    5,    /* 662: of_oxm_icmpv4_type */
    6,    /* 663: of_oxm_icmpv4_type_masked */
    5,    /* 664: of_oxm_icmpv6_code */
    6,    /* 665: of_oxm_icmpv6_code_masked */
    5,    /* 666: of_oxm_icmpv6_type */
    6,    /* 667: of_oxm_icmpv6_type_masked */
    8,    /* 668: of_oxm_in_phy_port */
    12,   /* 669: of_oxm_in_phy_port_masked */
    8,    /* 670: of_oxm_in_port */
    12,   /* 671: of_oxm_in_port_masked */
    5,    /* 672: of_oxm_ip_dscp */
    6,    /* 673: of_oxm_ip_dscp_masked */
    5,    /* 674: of_oxm_ip_ecn */
    6,    /* 675: of_oxm_ip_ecn_masked */
    5,    /* 676: of_oxm_ip_proto */
    6,    /* 677: of_oxm_ip_proto_masked */
    8,    /* 678: of_oxm_ipv4_dst */
    12,   /* 679: of_oxm_ipv4_dst_masked */
    8,    /* 680: of_oxm_ipv4_src */
    12,   /* 681: of_oxm_ipv4_src_masked */
    20,   /* 682: of_oxm_ipv6_dst */
    36,   /* 683: of_oxm_ipv6_dst_masked */
    -1,   /* 684: of_oxm_ipv6_exthdr */
    -1,   /* 685: of_oxm_ipv6_exthdr_masked */
    8,    /* 686: of_oxm_ipv6_flabel */
    12,   /* 687: of_oxm_ipv6_flabel_masked */
    10,   /* 688: of_oxm_ipv6_nd_sll */
    16,   /* 689: of_oxm_ipv6_nd_sll_masked */
    20,   /* 690: of_oxm_ipv6_nd_target */
    36,   /* 691: of_oxm_ipv6_nd_target_masked */
    10,   /* 692: of_oxm_ipv6_nd_tll */
    16,   /* 693: of_oxm_ipv6_nd_tll_masked */
    20,   /* 694: of_oxm_ipv6_src */
    36,   /* 695: of_oxm_ipv6_src_masked */
    12,   /* 696: of_oxm_metadata */
    20,   /* 697: of_oxm_metadata_masked */
    -1,   /* 698: of_oxm_mpls_bos */
    -1,   /* 699: of_oxm_mpls_bos_masked */
    8,    /* 700: of_oxm_mpls_label */
    12,   /* 701: of_oxm_mpls_label_masked */
    5,    /* 702: of_oxm_mpls_tc */
    6,    /* 703: of_oxm_mpls_tc_masked */
    10,   /* 704: of_oxm_ovs_tcp_flags */
    12,   /* 705: of_oxm_ovs_tcp_flags_masked */
    -1,   /* 706: of_oxm_pbb_uca */
    -1,   /* 707: of_oxm_pbb_uca_masked */
    6,    /* 708: of_oxm_sctp_dst */
    8,    /* 709: of_oxm_sctp_dst_masked */
    6,    /* 710: of_oxm_sctp_src */
    8,    /* 711: of_oxm_sctp_src_masked */
    6,    /* 712: of_oxm_tcp_dst */
    8,    /* 713: of_oxm_tcp_dst_masked */
    6,    /* 714: of_oxm_tcp_src */
    8,    /* 715: of_oxm_tcp_src_masked */
    -1,   /* 716: of_oxm_tunnel_id */
    -1,   /* 717: of_oxm_tunnel_id_masked */
    8,    /* 718: of_oxm_tunnel_ipv4_dst */
    12,   /* 719: of_oxm_tunnel_ipv4_dst_masked */
    8,    /* 720: of_oxm_tunnel_ipv4_src */
    12,   /* 721: of_oxm_tunnel_ipv4_src_masked */
    6,    /* 722: of_oxm_udp_dst */
    8,    /* 723: of_oxm_udp_dst_masked */
    6,    /* 724: of_oxm_udp_src */
    8,    /* 725: of_oxm_udp_src_masked */
    5,    /* 726: of_oxm_vlan_pcp */
    6,    /* 727: of_oxm_vlan_pcp_masked */
    6,    /* 728: of_oxm_vlan_vid */
    8,    /* 729: of_oxm_vlan_vid_masked */
    16,   /* 730: of_packet_queue */
    64,   /* 731: of_port_desc */
    -1,   /* 732: of_port_desc_prop */
    -1,   /* 733: of_port_desc_prop_bsn */
    -1,   /* 734: of_port_desc_prop_bsn_breakout */
    -1,   /* 735: of_port_desc_prop_bsn_driver_info_json */
    -1,   /* 736: of_port_desc_prop_bsn_forward_error_correction */
    -1,   /* 737: of_port_desc_prop_bsn_generation_id */
    -1,   /* 738: of_port_desc_prop_bsn_misc_capabilities */
    -1,   /* 739: of_port_desc_prop_bsn_sff_json */
    -1,   /* 740: of_port_desc_prop_bsn_speed_capabilities */
    -1,   /* 741: of_port_desc_prop_bsn_uplink */
    -1,   /* 742: of_port_desc_prop_ethernet */
    -1,   /* 743: of_port_desc_prop_experimenter */
    -1,   /* 744: of_port_desc_prop_optical */
    -1,   /* 745: of_port_mod_prop */
    -1,   /* 746: of_port_mod_prop_ethernet */
    -1,   /* 747: of_port_mod_prop_experimenter */
    -1,   /* 748: of_port_mod_prop_optical */
    104,  /* 749: of_port_stats_entry */
    -1,   /* 750: of_port_stats_prop */
    -1,   /* 751: of_port_stats_prop_ethernet */
    -1,   /* 752: of_port_stats_prop_experimenter */
    -1,   /* 753: of_port_stats_prop_experimenter_intel */
    -1,   /* 754: of_port_stats_prop_optical */
    -1,   /* 755: of_queue_desc */
    -1,   /* 756: of_queue_desc_prop */
    -1,   /* 757: of_queue_desc_prop_bsn */
    -1,   /* 758: of_queue_desc_prop_bsn_queue_name */
    -1,   /* 759: of_queue_desc_prop_experimenter */
    -1,   /* 760: of_queue_desc_prop_max_rate */
    -1,   /* 761: of_queue_desc_prop_min_rate */
    8,    /* 762: of_queue_prop */
    16,   /* 763: of_queue_prop_experimenter */
    16,   /* 764: of_queue_prop_max_rate */
    16,   /* 765: of_queue_prop_min_rate */
    32,   /* 766: of_queue_stats_entry */
    -1,   /* 767: of_queue_stats_prop */
    -1,   /* 768: of_queue_stats_prop_experimenter */
    -1,   /* 769: of_role_prop */
    -1,   /* 770: of_role_prop_experimenter */
    -1,   /* 771: of_table_desc */
    -1,   /* 772: of_table_feature_prop */
    -1,   /* 773: of_table_feature_prop_apply_actions */
    -1,   /* 774: of_table_feature_prop_apply_actions_miss */
    -1,   /* 775: of_table_feature_prop_apply_setfield */
    -1,   /* 776: of_table_feature_prop_apply_setfield_miss */
    -1,   /* 777: of_table_feature_prop_experimenter */
    -1,   /* 778: of_table_feature_prop_experimenter_miss */
    -1,   /* 779: of_table_feature_prop_instructions */
    -1,   /* 780: of_table_feature_prop_instructions_miss */
    -1,   /* 781: of_table_feature_prop_match */
    -1,   /* 782: of_table_feature_prop_next_tables */
    -1,   /* 783: of_table_feature_prop_next_tables_miss */
    -1,   /* 784: of_table_feature_prop_table_sync_from */
    -1,   /* 785: of_table_feature_prop_wildcards */
    -1,   /* 786: of_table_feature_prop_write_actions */
    -1,   /* 787: of_table_feature_prop_write_actions_miss */
    -1,   /* 788: of_table_feature_prop_write_setfield */
    -1,   /* 789: of_table_feature_prop_write_setfield_miss */
    -1,   /* 790: of_table_features */
    -1,   /* 791: of_table_mod_prop */
    -1,   /* 792: of_table_mod_prop_eviction */
    -1,   /* 793: of_table_mod_prop_experimenter */
    -1,   /* 794: of_table_mod_prop_vacancy */
    128,  /* 795: of_table_stats_entry */
    -1,   /* 796: of_uint32 */
    -1,   /* 797: of_uint64 */
    -1,   /* 798: of_uint8 */
    0,    /* 799: of_list_action */
    -1,   /* 800: of_list_action_id */
    -1,   /* 801: of_list_async_config_prop */
    -1,   /* 802: of_list_bsn_controller_connection */
    -1,   /* 803: of_list_bsn_debug_counter_desc_stats_entry */
    -1,   /* 804: of_list_bsn_debug_counter_stats_entry */
    -1,   /* 805: of_list_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 806: of_list_bsn_generic_stats_entry */
    -1,   /* 807: of_list_bsn_gentable_bucket_stats_entry */
    -1,   /* 808: of_list_bsn_gentable_desc_stats_entry */
    -1,   /* 809: of_list_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 810: of_list_bsn_gentable_entry_stats_entry */
    -1,   /* 811: of_list_bsn_gentable_stats_entry */
    0,    /* 812: of_list_bsn_interface */
    -1,   /* 813: of_list_bsn_lacp_stats_entry */
    -1,   /* 814: of_list_bsn_port_counter_stats_entry */
    -1,   /* 815: of_list_bsn_switch_pipeline_stats_entry */
    -1,   /* 816: of_list_bsn_table_checksum_stats_entry */
    -1,   /* 817: of_list_bsn_tlv */
    -1,   /* 818: of_list_bsn_vlan_counter_stats_entry */
    -1,   /* 819: of_list_bsn_vlan_mac */
    -1,   /* 820: of_list_bsn_vrf_counter_stats_entry */
    0,    /* 821: of_list_bucket */
    0,    /* 822: of_list_bucket_counter */
    -1,   /* 823: of_list_bundle_prop */
    0,    /* 824: of_list_flow_stats_entry */
    0,    /* 825: of_list_group_desc_stats_entry */
    0,    /* 826: of_list_group_stats_entry */
    -1,   /* 827: of_list_hello_elem */
    0,    /* 828: of_list_instruction */
    -1,   /* 829: of_list_instruction_id */
    -1,   /* 830: of_list_meter_band */
    -1,   /* 831: of_list_meter_band_stats */
    -1,   /* 832: of_list_meter_config */
    -1,   /* 833: of_list_meter_stats */
    0,    /* 834: of_list_oxm */
    0,    /* 835: of_list_packet_queue */
    0,    /* 836: of_list_port_desc */
    -1,   /* 837: of_list_port_desc_prop */
    -1,   /* 838: of_list_port_mod_prop */
    0,    /* 839: of_list_port_stats_entry */
    -1,   /* 840: of_list_port_stats_prop */
    -1,   /* 841: of_list_queue_desc */
    -1,   /* 842: of_list_queue_desc_prop */
    0,    /* 843: of_list_queue_prop */
    0,    /* 844: of_list_queue_stats_entry */
    -1,   /* 845: of_list_queue_stats_prop */
    -1,   /* 846: of_list_role_prop */
    -1,   /* 847: of_list_table_desc */
    -1,   /* 848: of_list_table_feature_prop */
    -1,   /* 849: of_list_table_features */
    -1,   /* 850: of_list_table_mod_prop */
    0,    /* 851: of_list_table_stats_entry */
    -1,   /* 852: of_list_uint32 */
    -1,   /* 853: of_list_uint64 */
    -1    /* 854: of_list_uint8 */
};

static const int
of_object_fixed_len_v4[OF_OBJECT_COUNT] = {
    -1,   /* of_object is not instantiable */
    40,   /* 1: of_aggregate_stats_reply */
    56,   /* 2: of_aggregate_stats_request */
    -1,   /* 3: of_async_config_failed_error_msg */
    32,   /* 4: of_async_get_reply */
    8,    /* 5: of_async_get_request */
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
    276,  /* 52: of_bsn_gentable_error */
    24,   /* 53: of_bsn_gentable_set_buckets_size */
    24,   /* 54: of_bsn_gentable_stats_reply */
    24,   /* 55: of_bsn_gentable_stats_request */
    16,   /* 56: of_bsn_get_interfaces_reply */
    16,   /* 57: of_bsn_get_interfaces_request */
    -1,   /* 58: of_bsn_get_ip_mask_reply */
    -1,   /* 59: of_bsn_get_ip_mask_request */
    -1,   /* 60: of_bsn_get_l2_table_reply */
    -1,   /* 61: of_bsn_get_l2_table_request */
    20,   /* 62: of_bsn_get_mirroring_reply */
    20,   /* 63: of_bsn_get_mirroring_request */
    272,  /* 64: of_bsn_get_switch_pipeline_reply */
    16,   /* 65: of_bsn_get_switch_pipeline_request */
    16,   /* 66: of_bsn_header */
    -1,   /* 67: of_bsn_hybrid_get_reply */
    -1,   /* 68: of_bsn_hybrid_get_request */
    536,  /* 69: of_bsn_image_desc_stats_reply */
    24,   /* 70: of_bsn_image_desc_stats_request */
    52,   /* 71: of_bsn_lacp_convergence_notif */
    24,   /* 72: of_bsn_lacp_stats_reply */
    24,   /* 73: of_bsn_lacp_stats_request */
    17,   /* 74: of_bsn_log */
    16,   /* 75: of_bsn_lua_command_reply */
    16,   /* 76: of_bsn_lua_command_request */
    16,   /* 77: of_bsn_lua_notification */
    82,   /* 78: of_bsn_lua_upload */
    25,   /* 79: of_bsn_pdu_rx_reply */
    28,   /* 80: of_bsn_pdu_rx_request */
    21,   /* 81: of_bsn_pdu_rx_timeout */
    25,   /* 82: of_bsn_pdu_tx_reply */
    28,   /* 83: of_bsn_pdu_tx_request */
    24,   /* 84: of_bsn_port_counter_stats_reply */
    28,   /* 85: of_bsn_port_counter_stats_request */
    32,   /* 86: of_bsn_role_status */
    24,   /* 87: of_bsn_set_aux_cxns_reply */
    20,   /* 88: of_bsn_set_aux_cxns_request */
    -1,   /* 89: of_bsn_set_ip_mask */
    -1,   /* 90: of_bsn_set_l2_table_reply */
    -1,   /* 91: of_bsn_set_l2_table_request */
    24,   /* 92: of_bsn_set_lacp_reply */
    38,   /* 93: of_bsn_set_lacp_request */
    20,   /* 94: of_bsn_set_mirroring */
    20,   /* 95: of_bsn_set_pktin_suppression_reply */
    32,   /* 96: of_bsn_set_pktin_suppression_request */
    20,   /* 97: of_bsn_set_switch_pipeline_reply */
    272,  /* 98: of_bsn_set_switch_pipeline_request */
    -1,   /* 99: of_bsn_shell_command */
    -1,   /* 100: of_bsn_shell_output */
    -1,   /* 101: of_bsn_shell_status */
    24,   /* 102: of_bsn_stats_reply */
    24,   /* 103: of_bsn_stats_request */
    24,   /* 104: of_bsn_switch_pipeline_stats_reply */
    24,   /* 105: of_bsn_switch_pipeline_stats_request */
    24,   /* 106: of_bsn_table_checksum_stats_reply */
    24,   /* 107: of_bsn_table_checksum_stats_request */
    24,   /* 108: of_bsn_table_set_buckets_size */
    -1,   /* 109: of_bsn_takeover */
    24,   /* 110: of_bsn_time_reply */
    16,   /* 111: of_bsn_time_request */
    24,   /* 112: of_bsn_virtual_port_create_reply */
    20,   /* 113: of_bsn_virtual_port_create_request */
    20,   /* 114: of_bsn_virtual_port_remove_reply */
    20,   /* 115: of_bsn_virtual_port_remove_request */
    18,   /* 116: of_bsn_vlan_counter_clear */
    24,   /* 117: of_bsn_vlan_counter_stats_reply */
    26,   /* 118: of_bsn_vlan_counter_stats_request */
    24,   /* 119: of_bsn_vrf_counter_stats_reply */
    28,   /* 120: of_bsn_vrf_counter_stats_request */
    -1,   /* 121: of_bundle_add_msg */
    -1,   /* 122: of_bundle_ctrl_msg */
    -1,   /* 123: of_bundle_failed_error_msg */
    1072, /* 124: of_desc_stats_reply */
    16,   /* 125: of_desc_stats_request */
    8,    /* 126: of_echo_reply */
    8,    /* 127: of_echo_request */
    10,   /* 128: of_error_msg */
    16,   /* 129: of_experimenter */
    16,   /* 130: of_experimenter_error_msg */
    24,   /* 131: of_experimenter_stats_reply */
    24,   /* 132: of_experimenter_stats_request */
    32,   /* 133: of_features_reply */
    8,    /* 134: of_features_request */
    56,   /* 135: of_flow_add */
    56,   /* 136: of_flow_delete */
    56,   /* 137: of_flow_delete_strict */
    56,   /* 138: of_flow_mod */
    12,   /* 139: of_flow_mod_failed_error_msg */
    56,   /* 140: of_flow_modify */
    56,   /* 141: of_flow_modify_strict */
    -1,   /* 142: of_flow_monitor_failed_error_msg */
    56,   /* 143: of_flow_removed */
    16,   /* 144: of_flow_stats_reply */
    56,   /* 145: of_flow_stats_request */
    12,   /* 146: of_get_config_reply */
    8,    /* 147: of_get_config_request */
    16,   /* 148: of_group_add */
    16,   /* 149: of_group_delete */
    16,   /* 150: of_group_desc_stats_reply */
    16,   /* 151: of_group_desc_stats_request */
    56,   /* 152: of_group_features_stats_reply */
    16,   /* 153: of_group_features_stats_request */
    16,   /* 154: of_group_mod */
    12,   /* 155: of_group_mod_failed_error_msg */
    16,   /* 156: of_group_modify */
    16,   /* 157: of_group_stats_reply */
    24,   /* 158: of_group_stats_request */
    8,    /* 159: of_header */
    8,    /* 160: of_hello */
    12,   /* 161: of_hello_failed_error_msg */
    16,   /* 162: of_meter_config_stats_reply */
    24,   /* 163: of_meter_config_stats_request */
    32,   /* 164: of_meter_features_stats_reply */
    16,   /* 165: of_meter_features_stats_request */
    16,   /* 166: of_meter_mod */
    12,   /* 167: of_meter_mod_failed_error_msg */
    16,   /* 168: of_meter_stats_reply */
    24,   /* 169: of_meter_stats_request */
    -1,   /* 170: of_nicira_controller_role_reply */
    -1,   /* 171: of_nicira_controller_role_request */
    16,   /* 172: of_nicira_header */
    34,   /* 173: of_packet_in */
    24,   /* 174: of_packet_out */
    16,   /* 175: of_port_desc_stats_reply */
    16,   /* 176: of_port_desc_stats_request */
    40,   /* 177: of_port_mod */
    12,   /* 178: of_port_mod_failed_error_msg */
    16,   /* 179: of_port_stats_reply */
    24,   /* 180: of_port_stats_request */
    80,   /* 181: of_port_status */
    -1,   /* 182: of_queue_desc_stats_reply */
    -1,   /* 183: of_queue_desc_stats_request */
    16,   /* 184: of_queue_get_config_reply */
    16,   /* 185: of_queue_get_config_request */
    12,   /* 186: of_queue_op_failed_error_msg */
    16,   /* 187: of_queue_stats_reply */
    24,   /* 188: of_queue_stats_request */
    -1,   /* 189: of_requestforward */
    24,   /* 190: of_role_reply */
    24,   /* 191: of_role_request */
    12,   /* 192: of_role_request_failed_error_msg */
    -1,   /* 193: of_role_status */
    12,   /* 194: of_set_config */
    16,   /* 195: of_stats_reply */
    16,   /* 196: of_stats_request */
    12,   /* 197: of_switch_config_failed_error_msg */
    -1,   /* 198: of_table_desc_stats_reply */
    -1,   /* 199: of_table_desc_stats_request */
    12,   /* 200: of_table_features_failed_error_msg */
    16,   /* 201: of_table_features_stats_reply */
    16,   /* 202: of_table_features_stats_request */
    16,   /* 203: of_table_mod */
    12,   /* 204: of_table_mod_failed_error_msg */
    16,   /* 205: of_table_stats_reply */
    16,   /* 206: of_table_stats_request */
    -1,   /* 207: of_table_status */
    8,    /* 208: of_action */
    16,   /* 209: of_action_bsn */
    28,   /* 210: of_action_bsn_checksum */
    16,   /* 211: of_action_bsn_gentable */
    24,   /* 212: of_action_bsn_mirror */
    16,   /* 213: of_action_bsn_set_tunnel_dst */
    8,    /* 214: of_action_copy_ttl_in */
    8,    /* 215: of_action_copy_ttl_out */
    8,    /* 216: of_action_dec_mpls_ttl */
    8,    /* 217: of_action_dec_nw_ttl */
    -1,   /* 218: of_action_enqueue */
    8,    /* 219: of_action_experimenter */
    8,    /* 220: of_action_group */
    4,    /* 221: of_action_id */
    12,   /* 222: of_action_id_bsn */
    12,   /* 223: of_action_id_bsn_checksum */
    12,   /* 224: of_action_id_bsn_gentable */
    12,   /* 225: of_action_id_bsn_mirror */
    12,   /* 226: of_action_id_bsn_set_tunnel_dst */
    4,    /* 227: of_action_id_copy_ttl_in */
    4,    /* 228: of_action_id_copy_ttl_out */
    4,    /* 229: of_action_id_dec_mpls_ttl */
    4,    /* 230: of_action_id_dec_nw_ttl */
    8,    /* 231: of_action_id_experimenter */
    4,    /* 232: of_action_id_group */
    10,   /* 233: of_action_id_nicira */
    10,   /* 234: of_action_id_nicira_dec_ttl */
    4,    /* 235: of_action_id_output */
    4,    /* 236: of_action_id_pop_mpls */
    4,    /* 237: of_action_id_pop_pbb */
    4,    /* 238: of_action_id_pop_vlan */
    4,    /* 239: of_action_id_push_mpls */
    4,    /* 240: of_action_id_push_pbb */
    4,    /* 241: of_action_id_push_vlan */
    4,    /* 242: of_action_id_set_field */
    4,    /* 243: of_action_id_set_mpls_ttl */
    4,    /* 244: of_action_id_set_nw_ttl */
    4,    /* 245: of_action_id_set_queue */
    16,   /* 246: of_action_nicira */
    16,   /* 247: of_action_nicira_dec_ttl */
    16,   /* 248: of_action_output */
    8,    /* 249: of_action_pop_mpls */
    8,    /* 250: of_action_pop_pbb */
    8,    /* 251: of_action_pop_vlan */
    8,    /* 252: of_action_push_mpls */
    8,    /* 253: of_action_push_pbb */
    8,    /* 254: of_action_push_vlan */
    -1,   /* 255: of_action_set_dl_dst */
    -1,   /* 256: of_action_set_dl_src */
    8,    /* 257: of_action_set_field */
    -1,   /* 258: of_action_set_mpls_label */
    -1,   /* 259: of_action_set_mpls_tc */
    8,    /* 260: of_action_set_mpls_ttl */
    -1,   /* 261: of_action_set_nw_dst */
    -1,   /* 262: of_action_set_nw_ecn */
    -1,   /* 263: of_action_set_nw_src */
    -1,   /* 264: of_action_set_nw_tos */
    8,    /* 265: of_action_set_nw_ttl */
    8,    /* 266: of_action_set_queue */
    -1,   /* 267: of_action_set_tp_dst */
    -1,   /* 268: of_action_set_tp_src */
    -1,   /* 269: of_action_set_vlan_pcp */
    -1,   /* 270: of_action_set_vlan_vid */
    -1,   /* 271: of_action_strip_vlan */
    -1,   /* 272: of_async_config_prop */
    -1,   /* 273: of_async_config_prop_experimenter_master */
    -1,   /* 274: of_async_config_prop_experimenter_slave */
    -1,   /* 275: of_async_config_prop_flow_removed_master */
    -1,   /* 276: of_async_config_prop_flow_removed_slave */
    -1,   /* 277: of_async_config_prop_packet_in_master */
    -1,   /* 278: of_async_config_prop_packet_in_slave */
    -1,   /* 279: of_async_config_prop_port_status_master */
    -1,   /* 280: of_async_config_prop_port_status_slave */
    -1,   /* 281: of_async_config_prop_requestforward_master */
    -1,   /* 282: of_async_config_prop_requestforward_slave */
    -1,   /* 283: of_async_config_prop_role_status_master */
    -1,   /* 284: of_async_config_prop_role_status_slave */
    -1,   /* 285: of_async_config_prop_table_status_master */
    -1,   /* 286: of_async_config_prop_table_status_slave */
    264,  /* 287: of_bsn_controller_connection */
    328,  /* 288: of_bsn_debug_counter_desc_stats_entry */
    16,   /* 289: of_bsn_debug_counter_stats_entry */
    8,    /* 290: of_bsn_flow_checksum_bucket_stats_entry */
    2,    /* 291: of_bsn_generic_stats_entry */
    16,   /* 292: of_bsn_gentable_bucket_stats_entry */
    48,   /* 293: of_bsn_gentable_desc_stats_entry */
    20,   /* 294: of_bsn_gentable_entry_desc_stats_entry */
    4,    /* 295: of_bsn_gentable_entry_stats_entry */
    24,   /* 296: of_bsn_gentable_stats_entry */
    32,   /* 297: of_bsn_interface */
    36,   /* 298: of_bsn_lacp_stats_entry */
    8,    /* 299: of_bsn_port_counter_stats_entry */
    256,  /* 300: of_bsn_switch_pipeline_stats_entry */
    9,    /* 301: of_bsn_table_checksum_stats_entry */
    4,    /* 302: of_bsn_tlv */
    6,    /* 303: of_bsn_tlv_actor_key */
    6,    /* 304: of_bsn_tlv_actor_port_num */
    6,    /* 305: of_bsn_tlv_actor_port_priority */
    5,    /* 306: of_bsn_tlv_actor_state */
    10,   /* 307: of_bsn_tlv_actor_system_mac */
    6,    /* 308: of_bsn_tlv_actor_system_priority */
    6,    /* 309: of_bsn_tlv_anchor */
    12,   /* 310: of_bsn_tlv_apply_bytes */
    12,   /* 311: of_bsn_tlv_apply_packets */
    5,    /* 312: of_bsn_tlv_auto_negotiation */
    5,    /* 313: of_bsn_tlv_bfd_endpoint */
    5,    /* 314: of_bsn_tlv_bfd_state */
    8,    /* 315: of_bsn_tlv_broadcast_query_timeout */
    8,    /* 316: of_bsn_tlv_broadcast_rate */
    4,    /* 317: of_bsn_tlv_bucket */
    4,    /* 318: of_bsn_tlv_circuit_id */
    5,    /* 319: of_bsn_tlv_convergence_status */
    4,    /* 320: of_bsn_tlv_cpu_lag */
    5,    /* 321: of_bsn_tlv_crc_enabled */
    4,    /* 322: of_bsn_tlv_data */
    4,    /* 323: of_bsn_tlv_data_mask */
    6,    /* 324: of_bsn_tlv_decap */
    4,    /* 325: of_bsn_tlv_disable_src_mac_check */
    4,    /* 326: of_bsn_tlv_drop */
    6,    /* 327: of_bsn_tlv_dscp */
    5,    /* 328: of_bsn_tlv_ecn */
    4,    /* 329: of_bsn_tlv_egress_only */
    8,    /* 330: of_bsn_tlv_egress_port_group_id */
    5,    /* 331: of_bsn_tlv_encap */
    12,   /* 332: of_bsn_tlv_enhanced_hash_capability */
    10,   /* 333: of_bsn_tlv_eth_dst */
    10,   /* 334: of_bsn_tlv_eth_src */
    6,    /* 335: of_bsn_tlv_eth_type */
    8,    /* 336: of_bsn_tlv_external_gateway_ip */
    10,   /* 337: of_bsn_tlv_external_gateway_mac */
    8,    /* 338: of_bsn_tlv_external_ip */
    10,   /* 339: of_bsn_tlv_external_mac */
    8,    /* 340: of_bsn_tlv_external_netmask */
    6,    /* 341: of_bsn_tlv_fabric_port_role */
    4,    /* 342: of_bsn_tlv_flood */
    6,    /* 343: of_bsn_tlv_flow_classifier */
    4,    /* 344: of_bsn_tlv_flow_classify */
    8,    /* 345: of_bsn_tlv_flow_identifier */
    4,    /* 346: of_bsn_tlv_force_link_up */
    5,    /* 347: of_bsn_tlv_forward_error_correction */
    12,   /* 348: of_bsn_tlv_generation_id */
    6,    /* 349: of_bsn_tlv_hash_algorithm */
    6,    /* 350: of_bsn_tlv_hash_gtp_header_match */
    9,    /* 351: of_bsn_tlv_hash_gtp_port_match */
    12,   /* 352: of_bsn_tlv_hash_packet_field */
    5,    /* 353: of_bsn_tlv_hash_packet_type */
    12,   /* 354: of_bsn_tlv_hash_seed */
    5,    /* 355: of_bsn_tlv_hash_type */
    8,    /* 356: of_bsn_tlv_header_size */
    5,    /* 357: of_bsn_tlv_icmp_code */
    6,    /* 358: of_bsn_tlv_icmp_id */
    5,    /* 359: of_bsn_tlv_icmp_type */
    6,    /* 360: of_bsn_tlv_icmpv6_chksum */
    8,    /* 361: of_bsn_tlv_identifier */
    4,    /* 362: of_bsn_tlv_idle_notification */
    12,   /* 363: of_bsn_tlv_idle_time */
    8,    /* 364: of_bsn_tlv_idle_timeout */
    4,    /* 365: of_bsn_tlv_igmp_snooping */
    8,    /* 366: of_bsn_tlv_ingress_port_group_id */
    10,   /* 367: of_bsn_tlv_internal_gateway_mac */
    10,   /* 368: of_bsn_tlv_internal_mac */
    8,    /* 369: of_bsn_tlv_interval */
    5,    /* 370: of_bsn_tlv_ip_proto */
    6,    /* 371: of_bsn_tlv_ip_tunnel_type */
    8,    /* 372: of_bsn_tlv_ipv4 */
    8,    /* 373: of_bsn_tlv_ipv4_dst */
    8,    /* 374: of_bsn_tlv_ipv4_netmask */
    8,    /* 375: of_bsn_tlv_ipv4_src */
    20,   /* 376: of_bsn_tlv_ipv6 */
    20,   /* 377: of_bsn_tlv_ipv6_dst */
    21,   /* 378: of_bsn_tlv_ipv6_prefix */
    20,   /* 379: of_bsn_tlv_ipv6_src */
    8,    /* 380: of_bsn_tlv_known_multicast_rate */
    4,    /* 381: of_bsn_tlv_l2_multicast_lookup */
    4,    /* 382: of_bsn_tlv_l3 */
    8,    /* 383: of_bsn_tlv_l3_dst_class_id */
    8,    /* 384: of_bsn_tlv_l3_interface_class_id */
    8,    /* 385: of_bsn_tlv_l3_src_class_id */
    6,    /* 386: of_bsn_tlv_lag_options */
    5,    /* 387: of_bsn_tlv_loopback_mode */
    8,    /* 388: of_bsn_tlv_loopback_port */
    4,    /* 389: of_bsn_tlv_lr_all_enabled */
    10,   /* 390: of_bsn_tlv_mac */
    10,   /* 391: of_bsn_tlv_mac_mask */
    4,    /* 392: of_bsn_tlv_mcg_type_vxlan */
    12,   /* 393: of_bsn_tlv_miss_packets */
    5,    /* 394: of_bsn_tlv_mpls_control_word */
    8,    /* 395: of_bsn_tlv_mpls_label */
    5,    /* 396: of_bsn_tlv_mpls_sequenced */
    8,    /* 397: of_bsn_tlv_multicast_interface_id */
    6,    /* 398: of_bsn_tlv_multicast_packet */
    8,    /* 399: of_bsn_tlv_multiplier */
    4,    /* 400: of_bsn_tlv_name */
    4,    /* 401: of_bsn_tlv_ndp_offload */
    4,    /* 402: of_bsn_tlv_ndp_static */
    4,    /* 403: of_bsn_tlv_negate */
    8,    /* 404: of_bsn_tlv_next_hop_ipv4 */
    10,   /* 405: of_bsn_tlv_next_hop_mac */
    4,    /* 406: of_bsn_tlv_nexthop_type_vxlan */
    4,    /* 407: of_bsn_tlv_no_arp_response */
    4,    /* 408: of_bsn_tlv_no_ns_response */
    6,    /* 409: of_bsn_tlv_offset */
    4,    /* 410: of_bsn_tlv_optics_always_enabled */
    10,   /* 411: of_bsn_tlv_outer_src_mac */
    8,    /* 412: of_bsn_tlv_parent_port */
    6,    /* 413: of_bsn_tlv_partner_key */
    6,    /* 414: of_bsn_tlv_partner_port_num */
    6,    /* 415: of_bsn_tlv_partner_port_priority */
    5,    /* 416: of_bsn_tlv_partner_state */
    10,   /* 417: of_bsn_tlv_partner_system_mac */
    6,    /* 418: of_bsn_tlv_partner_system_priority */
    4,    /* 419: of_bsn_tlv_passive */
    4,    /* 420: of_bsn_tlv_pdua_rx_instance */
    4,    /* 421: of_bsn_tlv_pim_dr */
    4,    /* 422: of_bsn_tlv_pim_hello_flood */
    8,    /* 423: of_bsn_tlv_port */
    6,    /* 424: of_bsn_tlv_port_mode */
    8,    /* 425: of_bsn_tlv_port_speed_gbps */
    6,    /* 426: of_bsn_tlv_port_usage */
    5,    /* 427: of_bsn_tlv_port_vxlan_mode */
    8,    /* 428: of_bsn_tlv_priority */
    4,    /* 429: of_bsn_tlv_push_vlan_on_egress */
    5,    /* 430: of_bsn_tlv_push_vlan_on_ingress */
    8,    /* 431: of_bsn_tlv_qos_priority */
    8,    /* 432: of_bsn_tlv_queue_id */
    8,    /* 433: of_bsn_tlv_queue_weight */
    8,    /* 434: of_bsn_tlv_rate_limit */
    5,    /* 435: of_bsn_tlv_rate_unit */
    8,    /* 436: of_bsn_tlv_record_packets */
    6,    /* 437: of_bsn_tlv_reference */
    12,   /* 438: of_bsn_tlv_reply_packets */
    12,   /* 439: of_bsn_tlv_request_packets */
    4,    /* 440: of_bsn_tlv_rest_server */
    6,    /* 441: of_bsn_tlv_routing_param */
    12,   /* 442: of_bsn_tlv_rx_bytes */
    12,   /* 443: of_bsn_tlv_rx_packets */
    8,    /* 444: of_bsn_tlv_sampling_rate */
    4,    /* 445: of_bsn_tlv_set_loopback_mode */
    5,    /* 446: of_bsn_tlv_status */
    4,    /* 447: of_bsn_tlv_strip_mpls_l2_on_ingress */
    4,    /* 448: of_bsn_tlv_strip_mpls_l3_on_ingress */
    5,    /* 449: of_bsn_tlv_strip_vlan_on_egress */
    8,    /* 450: of_bsn_tlv_sub_agent_id */
    6,    /* 451: of_bsn_tlv_tcp_dst */
    6,    /* 452: of_bsn_tlv_tcp_flags */
    6,    /* 453: of_bsn_tlv_tcp_src */
    12,   /* 454: of_bsn_tlv_timestamp */
    6,    /* 455: of_bsn_tlv_ttl */
    12,   /* 456: of_bsn_tlv_tunnel_capability */
    12,   /* 457: of_bsn_tlv_tx_bytes */
    12,   /* 458: of_bsn_tlv_tx_packets */
    6,    /* 459: of_bsn_tlv_udf_anchor */
    5,    /* 460: of_bsn_tlv_udf_capability */
    6,    /* 461: of_bsn_tlv_udf_id */
    6,    /* 462: of_bsn_tlv_udf_length */
    6,    /* 463: of_bsn_tlv_udf_offset */
    6,    /* 464: of_bsn_tlv_udp_dst */
    6,    /* 465: of_bsn_tlv_udp_src */
    8,    /* 466: of_bsn_tlv_uint32 */
    4,    /* 467: of_bsn_tlv_uint64_list */
    8,    /* 468: of_bsn_tlv_unicast_query_timeout */
    8,    /* 469: of_bsn_tlv_unicast_rate */
    8,    /* 470: of_bsn_tlv_unknown_multicast_rate */
    4,    /* 471: of_bsn_tlv_untagged */
    6,    /* 472: of_bsn_tlv_upgrade */
    4,    /* 473: of_bsn_tlv_uri_scheme */
    5,    /* 474: of_bsn_tlv_use_packet_state */
    4,    /* 475: of_bsn_tlv_user_configured */
    6,    /* 476: of_bsn_tlv_vfi */
    8,    /* 477: of_bsn_tlv_vfp_class_id */
    4,    /* 478: of_bsn_tlv_virtual */
    4,    /* 479: of_bsn_tlv_vlan_mac_list */
    5,    /* 480: of_bsn_tlv_vlan_pcp */
    6,    /* 481: of_bsn_tlv_vlan_vid */
    6,    /* 482: of_bsn_tlv_vlan_vid_mask */
    8,    /* 483: of_bsn_tlv_vni */
    8,    /* 484: of_bsn_tlv_vpn_key */
    8,    /* 485: of_bsn_tlv_vrf */
    4,    /* 486: of_bsn_tlv_vxlan_egress_lag */
    8,    /* 487: of_bsn_vlan_counter_stats_entry */
    8,    /* 488: of_bsn_vlan_mac */
    4,    /* 489: of_bsn_vport */
    64,   /* 490: of_bsn_vport_l2gre */
    32,   /* 491: of_bsn_vport_q_in_q */
    8,    /* 492: of_bsn_vrf_counter_stats_entry */
    16,   /* 493: of_bucket */
    16,   /* 494: of_bucket_counter */
    -1,   /* 495: of_bundle_prop */
    -1,   /* 496: of_bundle_prop_experimenter */
    56,   /* 497: of_flow_stats_entry */
    8,    /* 498: of_group_desc_stats_entry */
    40,   /* 499: of_group_stats_entry */
    4,    /* 500: of_hello_elem */
    4,    /* 501: of_hello_elem_versionbitmap */
    4,    /* 502: of_instruction */
    8,    /* 503: of_instruction_apply_actions */
    16,   /* 504: of_instruction_bsn */
    16,   /* 505: of_instruction_bsn_arp_offload */
    16,   /* 506: of_instruction_bsn_auto_negotiation */
    16,   /* 507: of_instruction_bsn_deny */
    16,   /* 508: of_instruction_bsn_dhcp_offload */
    16,   /* 509: of_instruction_bsn_directed_broadcast */
    16,   /* 510: of_instruction_bsn_disable_l3 */
    16,   /* 511: of_instruction_bsn_disable_split_horizon_check */
    16,   /* 512: of_instruction_bsn_disable_src_mac_check */
    16,   /* 513: of_instruction_bsn_disable_vlan_counters */
    16,   /* 514: of_instruction_bsn_hash_select */
    16,   /* 515: of_instruction_bsn_internal_priority */
    16,   /* 516: of_instruction_bsn_ndp_offload */
    16,   /* 517: of_instruction_bsn_packet_of_death */
    16,   /* 518: of_instruction_bsn_permit */
    16,   /* 519: of_instruction_bsn_prioritize_pdus */
    16,   /* 520: of_instruction_bsn_require_vlan_xlate */
    16,   /* 521: of_instruction_bsn_span_destination */
    8,    /* 522: of_instruction_clear_actions */
    8,    /* 523: of_instruction_experimenter */
    8,    /* 524: of_instruction_goto_table */
    4,    /* 525: of_instruction_id */
    4,    /* 526: of_instruction_id_apply_actions */
    12,   /* 527: of_instruction_id_bsn */
    12,   /* 528: of_instruction_id_bsn_arp_offload */
    12,   /* 529: of_instruction_id_bsn_auto_negotiation */
    12,   /* 530: of_instruction_id_bsn_deny */
    12,   /* 531: of_instruction_id_bsn_dhcp_offload */
    12,   /* 532: of_instruction_id_bsn_directed_broadcast */
    12,   /* 533: of_instruction_id_bsn_disable_l3 */
    12,   /* 534: of_instruction_id_bsn_disable_split_horizon_check */
    12,   /* 535: of_instruction_id_bsn_disable_src_mac_check */
    12,   /* 536: of_instruction_id_bsn_disable_vlan_counters */
    12,   /* 537: of_instruction_id_bsn_hash_select */
    12,   /* 538: of_instruction_id_bsn_internal_priority */
    12,   /* 539: of_instruction_id_bsn_ndp_offload */
    12,   /* 540: of_instruction_id_bsn_packet_of_death */
    12,   /* 541: of_instruction_id_bsn_permit */
    12,   /* 542: of_instruction_id_bsn_prioritize_pdus */
    12,   /* 543: of_instruction_id_bsn_require_vlan_xlate */
    12,   /* 544: of_instruction_id_bsn_span_destination */
    4,    /* 545: of_instruction_id_clear_actions */
    8,    /* 546: of_instruction_id_experimenter */
    4,    /* 547: of_instruction_id_goto_table */
    4,    /* 548: of_instruction_id_meter */
    4,    /* 549: of_instruction_id_write_actions */
    4,    /* 550: of_instruction_id_write_metadata */
    8,    /* 551: of_instruction_meter */
    8,    /* 552: of_instruction_write_actions */
    24,   /* 553: of_instruction_write_metadata */
    -1,   /* 554: of_match_v1 */
    -1,   /* 555: of_match_v2 */
    4,    /* 556: of_match_v3 */
    4,    /* 557: of_meter_band */
    16,   /* 558: of_meter_band_drop */
    16,   /* 559: of_meter_band_dscp_remark */
    16,   /* 560: of_meter_band_experimenter */
    16,   /* 561: of_meter_band_stats */
    8,    /* 562: of_meter_config */
    16,   /* 563: of_meter_features */
    40,   /* 564: of_meter_stats */
    4,    /* 565: of_oxm */
    6,    /* 566: of_oxm_arp_op */
    8,    /* 567: of_oxm_arp_op_masked */
    10,   /* 568: of_oxm_arp_sha */
    16,   /* 569: of_oxm_arp_sha_masked */
    8,    /* 570: of_oxm_arp_spa */
    12,   /* 571: of_oxm_arp_spa_masked */
    10,   /* 572: of_oxm_arp_tha */
    16,   /* 573: of_oxm_arp_tha_masked */
    8,    /* 574: of_oxm_arp_tpa */
    12,   /* 575: of_oxm_arp_tpa_masked */
    8,    /* 576: of_oxm_bsn_egr_port_group_id */
    12,   /* 577: of_oxm_bsn_egr_port_group_id_masked */
    5,    /* 578: of_oxm_bsn_global_vrf_allowed */
    6,    /* 579: of_oxm_bsn_global_vrf_allowed_masked */
    -1,   /* 580: of_oxm_bsn_ifp_class_id */
    -1,   /* 581: of_oxm_bsn_ifp_class_id_masked */
    20,   /* 582: of_oxm_bsn_in_ports_128 */
    36,   /* 583: of_oxm_bsn_in_ports_128_masked */
    68,   /* 584: of_oxm_bsn_in_ports_512 */
    132,  /* 585: of_oxm_bsn_in_ports_512_masked */
    8,    /* 586: of_oxm_bsn_ingress_port_group_id */
    12,   /* 587: of_oxm_bsn_ingress_port_group_id_masked */
    10,   /* 588: of_oxm_bsn_inner_eth_dst */
    16,   /* 589: of_oxm_bsn_inner_eth_dst_masked */
    10,   /* 590: of_oxm_bsn_inner_eth_src */
    16,   /* 591: of_oxm_bsn_inner_eth_src_masked */
    6,    /* 592: of_oxm_bsn_inner_vlan_vid */
    8,    /* 593: of_oxm_bsn_inner_vlan_vid_masked */
    5,    /* 594: of_oxm_bsn_ip_fragmentation */
    6,    /* 595: of_oxm_bsn_ip_fragmentation_masked */
    5,    /* 596: of_oxm_bsn_l2_cache_hit */
    6,    /* 597: of_oxm_bsn_l2_cache_hit_masked */
    8,    /* 598: of_oxm_bsn_l3_dst_class_id */
    12,   /* 599: of_oxm_bsn_l3_dst_class_id_masked */
    8,    /* 600: of_oxm_bsn_l3_interface_class_id */
    12,   /* 601: of_oxm_bsn_l3_interface_class_id_masked */
    8,    /* 602: of_oxm_bsn_l3_src_class_id */
    12,   /* 603: of_oxm_bsn_l3_src_class_id_masked */
    8,    /* 604: of_oxm_bsn_lag_id */
    12,   /* 605: of_oxm_bsn_lag_id_masked */
    6,    /* 606: of_oxm_bsn_tcp_flags */
    8,    /* 607: of_oxm_bsn_tcp_flags_masked */
    8,    /* 608: of_oxm_bsn_udf0 */
    12,   /* 609: of_oxm_bsn_udf0_masked */
    8,    /* 610: of_oxm_bsn_udf1 */
    12,   /* 611: of_oxm_bsn_udf1_masked */
    8,    /* 612: of_oxm_bsn_udf2 */
    12,   /* 613: of_oxm_bsn_udf2_masked */
    8,    /* 614: of_oxm_bsn_udf3 */
    12,   /* 615: of_oxm_bsn_udf3_masked */
    8,    /* 616: of_oxm_bsn_udf4 */
    12,   /* 617: of_oxm_bsn_udf4_masked */
    8,    /* 618: of_oxm_bsn_udf5 */
    12,   /* 619: of_oxm_bsn_udf5_masked */
    8,    /* 620: of_oxm_bsn_udf6 */
    12,   /* 621: of_oxm_bsn_udf6_masked */
    8,    /* 622: of_oxm_bsn_udf7 */
    12,   /* 623: of_oxm_bsn_udf7_masked */
    6,    /* 624: of_oxm_bsn_vfi */
    8,    /* 625: of_oxm_bsn_vfi_masked */
    8,    /* 626: of_oxm_bsn_vlan_xlate_port_group_id */
    12,   /* 627: of_oxm_bsn_vlan_xlate_port_group_id_masked */
    8,    /* 628: of_oxm_bsn_vrf */
    12,   /* 629: of_oxm_bsn_vrf_masked */
    8,    /* 630: of_oxm_bsn_vxlan_network_id */
    12,   /* 631: of_oxm_bsn_vxlan_network_id_masked */
    20,   /* 632: of_oxm_conn_tracking_ipv6_dst */
    36,   /* 633: of_oxm_conn_tracking_ipv6_dst_masked */
    20,   /* 634: of_oxm_conn_tracking_ipv6_src */
    36,   /* 635: of_oxm_conn_tracking_ipv6_src_masked */
    20,   /* 636: of_oxm_conn_tracking_label */
    36,   /* 637: of_oxm_conn_tracking_label_masked */
    8,    /* 638: of_oxm_conn_tracking_mark */
    12,   /* 639: of_oxm_conn_tracking_mark_masked */
    8,    /* 640: of_oxm_conn_tracking_nw_dst */
    12,   /* 641: of_oxm_conn_tracking_nw_dst_masked */
    5,    /* 642: of_oxm_conn_tracking_nw_proto */
    6,    /* 643: of_oxm_conn_tracking_nw_proto_masked */
    8,    /* 644: of_oxm_conn_tracking_nw_src */
    12,   /* 645: of_oxm_conn_tracking_nw_src_masked */
    8,    /* 646: of_oxm_conn_tracking_state */
    12,   /* 647: of_oxm_conn_tracking_state_masked */
    6,    /* 648: of_oxm_conn_tracking_tp_dst */
    8,    /* 649: of_oxm_conn_tracking_tp_dst_masked */
    6,    /* 650: of_oxm_conn_tracking_tp_src */
    8,    /* 651: of_oxm_conn_tracking_tp_src_masked */
    6,    /* 652: of_oxm_conn_tracking_zone */
    8,    /* 653: of_oxm_conn_tracking_zone_masked */
    10,   /* 654: of_oxm_eth_dst */
    16,   /* 655: of_oxm_eth_dst_masked */
    10,   /* 656: of_oxm_eth_src */
    16,   /* 657: of_oxm_eth_src_masked */
    6,    /* 658: of_oxm_eth_type */
    8,    /* 659: of_oxm_eth_type_masked */
    5,    /* 660: of_oxm_icmpv4_code */
    6,    /* 661: of_oxm_icmpv4_code_masked */
    5,    /* 662: of_oxm_icmpv4_type */
    6,    /* 663: of_oxm_icmpv4_type_masked */
    5,    /* 664: of_oxm_icmpv6_code */
    6,    /* 665: of_oxm_icmpv6_code_masked */
    5,    /* 666: of_oxm_icmpv6_type */
    6,    /* 667: of_oxm_icmpv6_type_masked */
    8,    /* 668: of_oxm_in_phy_port */
    12,   /* 669: of_oxm_in_phy_port_masked */
    8,    /* 670: of_oxm_in_port */
    12,   /* 671: of_oxm_in_port_masked */
    5,    /* 672: of_oxm_ip_dscp */
    6,    /* 673: of_oxm_ip_dscp_masked */
    5,    /* 674: of_oxm_ip_ecn */
    6,    /* 675: of_oxm_ip_ecn_masked */
    5,    /* 676: of_oxm_ip_proto */
    6,    /* 677: of_oxm_ip_proto_masked */
    8,    /* 678: of_oxm_ipv4_dst */
    12,   /* 679: of_oxm_ipv4_dst_masked */
    8,    /* 680: of_oxm_ipv4_src */
    12,   /* 681: of_oxm_ipv4_src_masked */
    20,   /* 682: of_oxm_ipv6_dst */
    36,   /* 683: of_oxm_ipv6_dst_masked */
    6,    /* 684: of_oxm_ipv6_exthdr */
    8,    /* 685: of_oxm_ipv6_exthdr_masked */
    8,    /* 686: of_oxm_ipv6_flabel */
    12,   /* 687: of_oxm_ipv6_flabel_masked */
    10,   /* 688: of_oxm_ipv6_nd_sll */
    16,   /* 689: of_oxm_ipv6_nd_sll_masked */
    20,   /* 690: of_oxm_ipv6_nd_target */
    36,   /* 691: of_oxm_ipv6_nd_target_masked */
    10,   /* 692: of_oxm_ipv6_nd_tll */
    16,   /* 693: of_oxm_ipv6_nd_tll_masked */
    20,   /* 694: of_oxm_ipv6_src */
    36,   /* 695: of_oxm_ipv6_src_masked */
    12,   /* 696: of_oxm_metadata */
    20,   /* 697: of_oxm_metadata_masked */
    5,    /* 698: of_oxm_mpls_bos */
    6,    /* 699: of_oxm_mpls_bos_masked */
    8,    /* 700: of_oxm_mpls_label */
    12,   /* 701: of_oxm_mpls_label_masked */
    5,    /* 702: of_oxm_mpls_tc */
    6,    /* 703: of_oxm_mpls_tc_masked */
    10,   /* 704: of_oxm_ovs_tcp_flags */
    12,   /* 705: of_oxm_ovs_tcp_flags_masked */
    -1,   /* 706: of_oxm_pbb_uca */
    -1,   /* 707: of_oxm_pbb_uca_masked */
    6,    /* 708: of_oxm_sctp_dst */
    8,    /* 709: of_oxm_sctp_dst_masked */
    6,    /* 710: of_oxm_sctp_src */
    8,    /* 711: of_oxm_sctp_src_masked */
    6,    /* 712: of_oxm_tcp_dst */
    8,    /* 713: of_oxm_tcp_dst_masked */
    6,    /* 714: of_oxm_tcp_src */
    8,    /* 715: of_oxm_tcp_src_masked */
    12,   /* 716: of_oxm_tunnel_id */
    20,   /* 717: of_oxm_tunnel_id_masked */
    8,    /* 718: of_oxm_tunnel_ipv4_dst */
    12,   /* 719: of_oxm_tunnel_ipv4_dst_masked */
    8,    /* 720: of_oxm_tunnel_ipv4_src */
    12,   /* 721: of_oxm_tunnel_ipv4_src_masked */
    6,    /* 722: of_oxm_udp_dst */
    8,    /* 723: of_oxm_udp_dst_masked */
    6,    /* 724: of_oxm_udp_src */
    8,    /* 725: of_oxm_udp_src_masked */
    5,    /* 726: of_oxm_vlan_pcp */
    6,    /* 727: of_oxm_vlan_pcp_masked */
    6,    /* 728: of_oxm_vlan_vid */
    8,    /* 729: of_oxm_vlan_vid_masked */
    16,   /* 730: of_packet_queue */
    64,   /* 731: of_port_desc */
    -1,   /* 732: of_port_desc_prop */
    -1,   /* 733: of_port_desc_prop_bsn */
    -1,   /* 734: of_port_desc_prop_bsn_breakout */
    -1,   /* 735: of_port_desc_prop_bsn_driver_info_json */
    -1,   /* 736: of_port_desc_prop_bsn_forward_error_correction */
    -1,   /* 737: of_port_desc_prop_bsn_generation_id */
    -1,   /* 738: of_port_desc_prop_bsn_misc_capabilities */
    -1,   /* 739: of_port_desc_prop_bsn_sff_json */
    -1,   /* 740: of_port_desc_prop_bsn_speed_capabilities */
    -1,   /* 741: of_port_desc_prop_bsn_uplink */
    -1,   /* 742: of_port_desc_prop_ethernet */
    -1,   /* 743: of_port_desc_prop_experimenter */
    -1,   /* 744: of_port_desc_prop_optical */
    -1,   /* 745: of_port_mod_prop */
    -1,   /* 746: of_port_mod_prop_ethernet */
    -1,   /* 747: of_port_mod_prop_experimenter */
    -1,   /* 748: of_port_mod_prop_optical */
    112,  /* 749: of_port_stats_entry */
    -1,   /* 750: of_port_stats_prop */
    -1,   /* 751: of_port_stats_prop_ethernet */
    -1,   /* 752: of_port_stats_prop_experimenter */
    -1,   /* 753: of_port_stats_prop_experimenter_intel */
    -1,   /* 754: of_port_stats_prop_optical */
    -1,   /* 755: of_queue_desc */
    -1,   /* 756: of_queue_desc_prop */
    -1,   /* 757: of_queue_desc_prop_bsn */
    -1,   /* 758: of_queue_desc_prop_bsn_queue_name */
    -1,   /* 759: of_queue_desc_prop_experimenter */
    -1,   /* 760: of_queue_desc_prop_max_rate */
    -1,   /* 761: of_queue_desc_prop_min_rate */
    8,    /* 762: of_queue_prop */
    16,   /* 763: of_queue_prop_experimenter */
    16,   /* 764: of_queue_prop_max_rate */
    16,   /* 765: of_queue_prop_min_rate */
    40,   /* 766: of_queue_stats_entry */
    -1,   /* 767: of_queue_stats_prop */
    -1,   /* 768: of_queue_stats_prop_experimenter */
    -1,   /* 769: of_role_prop */
    -1,   /* 770: of_role_prop_experimenter */
    -1,   /* 771: of_table_desc */
    4,    /* 772: of_table_feature_prop */
    4,    /* 773: of_table_feature_prop_apply_actions */
    4,    /* 774: of_table_feature_prop_apply_actions_miss */
    4,    /* 775: of_table_feature_prop_apply_setfield */
    4,    /* 776: of_table_feature_prop_apply_setfield_miss */
    12,   /* 777: of_table_feature_prop_experimenter */
    12,   /* 778: of_table_feature_prop_experimenter_miss */
    4,    /* 779: of_table_feature_prop_instructions */
    4,    /* 780: of_table_feature_prop_instructions_miss */
    4,    /* 781: of_table_feature_prop_match */
    4,    /* 782: of_table_feature_prop_next_tables */
    4,    /* 783: of_table_feature_prop_next_tables_miss */
    -1,   /* 784: of_table_feature_prop_table_sync_from */
    4,    /* 785: of_table_feature_prop_wildcards */
    4,    /* 786: of_table_feature_prop_write_actions */
    4,    /* 787: of_table_feature_prop_write_actions_miss */
    4,    /* 788: of_table_feature_prop_write_setfield */
    4,    /* 789: of_table_feature_prop_write_setfield_miss */
    64,   /* 790: of_table_features */
    -1,   /* 791: of_table_mod_prop */
    -1,   /* 792: of_table_mod_prop_eviction */
    -1,   /* 793: of_table_mod_prop_experimenter */
    -1,   /* 794: of_table_mod_prop_vacancy */
    24,   /* 795: of_table_stats_entry */
    4,    /* 796: of_uint32 */
    8,    /* 797: of_uint64 */
    1,    /* 798: of_uint8 */
    0,    /* 799: of_list_action */
    0,    /* 800: of_list_action_id */
    -1,   /* 801: of_list_async_config_prop */
    0,    /* 802: of_list_bsn_controller_connection */
    0,    /* 803: of_list_bsn_debug_counter_desc_stats_entry */
    0,    /* 804: of_list_bsn_debug_counter_stats_entry */
    0,    /* 805: of_list_bsn_flow_checksum_bucket_stats_entry */
    0,    /* 806: of_list_bsn_generic_stats_entry */
    0,    /* 807: of_list_bsn_gentable_bucket_stats_entry */
    0,    /* 808: of_list_bsn_gentable_desc_stats_entry */
    0,    /* 809: of_list_bsn_gentable_entry_desc_stats_entry */
    0,    /* 810: of_list_bsn_gentable_entry_stats_entry */
    0,    /* 811: of_list_bsn_gentable_stats_entry */
    0,    /* 812: of_list_bsn_interface */
    0,    /* 813: of_list_bsn_lacp_stats_entry */
    0,    /* 814: of_list_bsn_port_counter_stats_entry */
    0,    /* 815: of_list_bsn_switch_pipeline_stats_entry */
    0,    /* 816: of_list_bsn_table_checksum_stats_entry */
    0,    /* 817: of_list_bsn_tlv */
    0,    /* 818: of_list_bsn_vlan_counter_stats_entry */
    0,    /* 819: of_list_bsn_vlan_mac */
    0,    /* 820: of_list_bsn_vrf_counter_stats_entry */
    0,    /* 821: of_list_bucket */
    0,    /* 822: of_list_bucket_counter */
    -1,   /* 823: of_list_bundle_prop */
    0,    /* 824: of_list_flow_stats_entry */
    0,    /* 825: of_list_group_desc_stats_entry */
    0,    /* 826: of_list_group_stats_entry */
    0,    /* 827: of_list_hello_elem */
    0,    /* 828: of_list_instruction */
    0,    /* 829: of_list_instruction_id */
    0,    /* 830: of_list_meter_band */
    0,    /* 831: of_list_meter_band_stats */
    0,    /* 832: of_list_meter_config */
    0,    /* 833: of_list_meter_stats */
    0,    /* 834: of_list_oxm */
    0,    /* 835: of_list_packet_queue */
    0,    /* 836: of_list_port_desc */
    -1,   /* 837: of_list_port_desc_prop */
    -1,   /* 838: of_list_port_mod_prop */
    0,    /* 839: of_list_port_stats_entry */
    -1,   /* 840: of_list_port_stats_prop */
    -1,   /* 841: of_list_queue_desc */
    -1,   /* 842: of_list_queue_desc_prop */
    0,    /* 843: of_list_queue_prop */
    0,    /* 844: of_list_queue_stats_entry */
    -1,   /* 845: of_list_queue_stats_prop */
    -1,   /* 846: of_list_role_prop */
    -1,   /* 847: of_list_table_desc */
    0,    /* 848: of_list_table_feature_prop */
    0,    /* 849: of_list_table_features */
    -1,   /* 850: of_list_table_mod_prop */
    0,    /* 851: of_list_table_stats_entry */
    0,    /* 852: of_list_uint32 */
    0,    /* 853: of_list_uint64 */
    0     /* 854: of_list_uint8 */
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
    276,  /* 52: of_bsn_gentable_error */
    24,   /* 53: of_bsn_gentable_set_buckets_size */
    24,   /* 54: of_bsn_gentable_stats_reply */
    24,   /* 55: of_bsn_gentable_stats_request */
    16,   /* 56: of_bsn_get_interfaces_reply */
    16,   /* 57: of_bsn_get_interfaces_request */
    -1,   /* 58: of_bsn_get_ip_mask_reply */
    -1,   /* 59: of_bsn_get_ip_mask_request */
    -1,   /* 60: of_bsn_get_l2_table_reply */
    -1,   /* 61: of_bsn_get_l2_table_request */
    20,   /* 62: of_bsn_get_mirroring_reply */
    20,   /* 63: of_bsn_get_mirroring_request */
    272,  /* 64: of_bsn_get_switch_pipeline_reply */
    16,   /* 65: of_bsn_get_switch_pipeline_request */
    16,   /* 66: of_bsn_header */
    -1,   /* 67: of_bsn_hybrid_get_reply */
    -1,   /* 68: of_bsn_hybrid_get_request */
    536,  /* 69: of_bsn_image_desc_stats_reply */
    24,   /* 70: of_bsn_image_desc_stats_request */
    52,   /* 71: of_bsn_lacp_convergence_notif */
    24,   /* 72: of_bsn_lacp_stats_reply */
    24,   /* 73: of_bsn_lacp_stats_request */
    17,   /* 74: of_bsn_log */
    16,   /* 75: of_bsn_lua_command_reply */
    16,   /* 76: of_bsn_lua_command_request */
    16,   /* 77: of_bsn_lua_notification */
    82,   /* 78: of_bsn_lua_upload */
    25,   /* 79: of_bsn_pdu_rx_reply */
    28,   /* 80: of_bsn_pdu_rx_request */
    21,   /* 81: of_bsn_pdu_rx_timeout */
    25,   /* 82: of_bsn_pdu_tx_reply */
    28,   /* 83: of_bsn_pdu_tx_request */
    24,   /* 84: of_bsn_port_counter_stats_reply */
    28,   /* 85: of_bsn_port_counter_stats_request */
    -1,   /* 86: of_bsn_role_status */
    24,   /* 87: of_bsn_set_aux_cxns_reply */
    20,   /* 88: of_bsn_set_aux_cxns_request */
    -1,   /* 89: of_bsn_set_ip_mask */
    -1,   /* 90: of_bsn_set_l2_table_reply */
    -1,   /* 91: of_bsn_set_l2_table_request */
    24,   /* 92: of_bsn_set_lacp_reply */
    38,   /* 93: of_bsn_set_lacp_request */
    20,   /* 94: of_bsn_set_mirroring */
    20,   /* 95: of_bsn_set_pktin_suppression_reply */
    32,   /* 96: of_bsn_set_pktin_suppression_request */
    20,   /* 97: of_bsn_set_switch_pipeline_reply */
    272,  /* 98: of_bsn_set_switch_pipeline_request */
    -1,   /* 99: of_bsn_shell_command */
    -1,   /* 100: of_bsn_shell_output */
    -1,   /* 101: of_bsn_shell_status */
    24,   /* 102: of_bsn_stats_reply */
    24,   /* 103: of_bsn_stats_request */
    24,   /* 104: of_bsn_switch_pipeline_stats_reply */
    24,   /* 105: of_bsn_switch_pipeline_stats_request */
    24,   /* 106: of_bsn_table_checksum_stats_reply */
    24,   /* 107: of_bsn_table_checksum_stats_request */
    24,   /* 108: of_bsn_table_set_buckets_size */
    16,   /* 109: of_bsn_takeover */
    24,   /* 110: of_bsn_time_reply */
    16,   /* 111: of_bsn_time_request */
    24,   /* 112: of_bsn_virtual_port_create_reply */
    20,   /* 113: of_bsn_virtual_port_create_request */
    20,   /* 114: of_bsn_virtual_port_remove_reply */
    20,   /* 115: of_bsn_virtual_port_remove_request */
    18,   /* 116: of_bsn_vlan_counter_clear */
    24,   /* 117: of_bsn_vlan_counter_stats_reply */
    26,   /* 118: of_bsn_vlan_counter_stats_request */
    24,   /* 119: of_bsn_vrf_counter_stats_reply */
    28,   /* 120: of_bsn_vrf_counter_stats_request */
    16,   /* 121: of_bundle_add_msg */
    16,   /* 122: of_bundle_ctrl_msg */
    12,   /* 123: of_bundle_failed_error_msg */
    1072, /* 124: of_desc_stats_reply */
    16,   /* 125: of_desc_stats_request */
    8,    /* 126: of_echo_reply */
    8,    /* 127: of_echo_request */
    10,   /* 128: of_error_msg */
    16,   /* 129: of_experimenter */
    16,   /* 130: of_experimenter_error_msg */
    24,   /* 131: of_experimenter_stats_reply */
    24,   /* 132: of_experimenter_stats_request */
    32,   /* 133: of_features_reply */
    8,    /* 134: of_features_request */
    56,   /* 135: of_flow_add */
    56,   /* 136: of_flow_delete */
    56,   /* 137: of_flow_delete_strict */
    56,   /* 138: of_flow_mod */
    12,   /* 139: of_flow_mod_failed_error_msg */
    56,   /* 140: of_flow_modify */
    56,   /* 141: of_flow_modify_strict */
    12,   /* 142: of_flow_monitor_failed_error_msg */
    56,   /* 143: of_flow_removed */
    16,   /* 144: of_flow_stats_reply */
    56,   /* 145: of_flow_stats_request */
    12,   /* 146: of_get_config_reply */
    8,    /* 147: of_get_config_request */
    16,   /* 148: of_group_add */
    16,   /* 149: of_group_delete */
    16,   /* 150: of_group_desc_stats_reply */
    16,   /* 151: of_group_desc_stats_request */
    56,   /* 152: of_group_features_stats_reply */
    16,   /* 153: of_group_features_stats_request */
    16,   /* 154: of_group_mod */
    12,   /* 155: of_group_mod_failed_error_msg */
    16,   /* 156: of_group_modify */
    16,   /* 157: of_group_stats_reply */
    24,   /* 158: of_group_stats_request */
    8,    /* 159: of_header */
    8,    /* 160: of_hello */
    12,   /* 161: of_hello_failed_error_msg */
    16,   /* 162: of_meter_config_stats_reply */
    24,   /* 163: of_meter_config_stats_request */
    32,   /* 164: of_meter_features_stats_reply */
    16,   /* 165: of_meter_features_stats_request */
    16,   /* 166: of_meter_mod */
    12,   /* 167: of_meter_mod_failed_error_msg */
    16,   /* 168: of_meter_stats_reply */
    24,   /* 169: of_meter_stats_request */
    -1,   /* 170: of_nicira_controller_role_reply */
    -1,   /* 171: of_nicira_controller_role_request */
    16,   /* 172: of_nicira_header */
    34,   /* 173: of_packet_in */
    24,   /* 174: of_packet_out */
    16,   /* 175: of_port_desc_stats_reply */
    16,   /* 176: of_port_desc_stats_request */
    32,   /* 177: of_port_mod */
    12,   /* 178: of_port_mod_failed_error_msg */
    16,   /* 179: of_port_stats_reply */
    24,   /* 180: of_port_stats_request */
    56,   /* 181: of_port_status */
    16,   /* 182: of_queue_desc_stats_reply */
    24,   /* 183: of_queue_desc_stats_request */
    -1,   /* 184: of_queue_get_config_reply */
    -1,   /* 185: of_queue_get_config_request */
    12,   /* 186: of_queue_op_failed_error_msg */
    16,   /* 187: of_queue_stats_reply */
    24,   /* 188: of_queue_stats_request */
    12,   /* 189: of_requestforward */
    24,   /* 190: of_role_reply */
    24,   /* 191: of_role_request */
    12,   /* 192: of_role_request_failed_error_msg */
    24,   /* 193: of_role_status */
    12,   /* 194: of_set_config */
    16,   /* 195: of_stats_reply */
    16,   /* 196: of_stats_request */
    12,   /* 197: of_switch_config_failed_error_msg */
    16,   /* 198: of_table_desc_stats_reply */
    16,   /* 199: of_table_desc_stats_request */
    12,   /* 200: of_table_features_failed_error_msg */
    16,   /* 201: of_table_features_stats_reply */
    16,   /* 202: of_table_features_stats_request */
    16,   /* 203: of_table_mod */
    12,   /* 204: of_table_mod_failed_error_msg */
    16,   /* 205: of_table_stats_reply */
    16,   /* 206: of_table_stats_request */
    28,   /* 207: of_table_status */
    8,    /* 208: of_action */
    16,   /* 209: of_action_bsn */
    28,   /* 210: of_action_bsn_checksum */
    16,   /* 211: of_action_bsn_gentable */
    24,   /* 212: of_action_bsn_mirror */
    16,   /* 213: of_action_bsn_set_tunnel_dst */
    8,    /* 214: of_action_copy_ttl_in */
    8,    /* 215: of_action_copy_ttl_out */
    8,    /* 216: of_action_dec_mpls_ttl */
    8,    /* 217: of_action_dec_nw_ttl */
    -1,   /* 218: of_action_enqueue */
    8,    /* 219: of_action_experimenter */
    8,    /* 220: of_action_group */
    4,    /* 221: of_action_id */
    12,   /* 222: of_action_id_bsn */
    12,   /* 223: of_action_id_bsn_checksum */
    12,   /* 224: of_action_id_bsn_gentable */
    12,   /* 225: of_action_id_bsn_mirror */
    12,   /* 226: of_action_id_bsn_set_tunnel_dst */
    4,    /* 227: of_action_id_copy_ttl_in */
    4,    /* 228: of_action_id_copy_ttl_out */
    4,    /* 229: of_action_id_dec_mpls_ttl */
    4,    /* 230: of_action_id_dec_nw_ttl */
    8,    /* 231: of_action_id_experimenter */
    4,    /* 232: of_action_id_group */
    10,   /* 233: of_action_id_nicira */
    10,   /* 234: of_action_id_nicira_dec_ttl */
    4,    /* 235: of_action_id_output */
    4,    /* 236: of_action_id_pop_mpls */
    4,    /* 237: of_action_id_pop_pbb */
    4,    /* 238: of_action_id_pop_vlan */
    4,    /* 239: of_action_id_push_mpls */
    4,    /* 240: of_action_id_push_pbb */
    4,    /* 241: of_action_id_push_vlan */
    4,    /* 242: of_action_id_set_field */
    4,    /* 243: of_action_id_set_mpls_ttl */
    4,    /* 244: of_action_id_set_nw_ttl */
    4,    /* 245: of_action_id_set_queue */
    16,   /* 246: of_action_nicira */
    16,   /* 247: of_action_nicira_dec_ttl */
    16,   /* 248: of_action_output */
    8,    /* 249: of_action_pop_mpls */
    8,    /* 250: of_action_pop_pbb */
    8,    /* 251: of_action_pop_vlan */
    8,    /* 252: of_action_push_mpls */
    8,    /* 253: of_action_push_pbb */
    8,    /* 254: of_action_push_vlan */
    -1,   /* 255: of_action_set_dl_dst */
    -1,   /* 256: of_action_set_dl_src */
    8,    /* 257: of_action_set_field */
    -1,   /* 258: of_action_set_mpls_label */
    -1,   /* 259: of_action_set_mpls_tc */
    8,    /* 260: of_action_set_mpls_ttl */
    -1,   /* 261: of_action_set_nw_dst */
    -1,   /* 262: of_action_set_nw_ecn */
    -1,   /* 263: of_action_set_nw_src */
    -1,   /* 264: of_action_set_nw_tos */
    8,    /* 265: of_action_set_nw_ttl */
    8,    /* 266: of_action_set_queue */
    -1,   /* 267: of_action_set_tp_dst */
    -1,   /* 268: of_action_set_tp_src */
    -1,   /* 269: of_action_set_vlan_pcp */
    -1,   /* 270: of_action_set_vlan_vid */
    -1,   /* 271: of_action_strip_vlan */
    4,    /* 272: of_async_config_prop */
    4,    /* 273: of_async_config_prop_experimenter_master */
    4,    /* 274: of_async_config_prop_experimenter_slave */
    8,    /* 275: of_async_config_prop_flow_removed_master */
    8,    /* 276: of_async_config_prop_flow_removed_slave */
    8,    /* 277: of_async_config_prop_packet_in_master */
    8,    /* 278: of_async_config_prop_packet_in_slave */
    8,    /* 279: of_async_config_prop_port_status_master */
    8,    /* 280: of_async_config_prop_port_status_slave */
    8,    /* 281: of_async_config_prop_requestforward_master */
    8,    /* 282: of_async_config_prop_requestforward_slave */
    8,    /* 283: of_async_config_prop_role_status_master */
    8,    /* 284: of_async_config_prop_role_status_slave */
    8,    /* 285: of_async_config_prop_table_status_master */
    8,    /* 286: of_async_config_prop_table_status_slave */
    264,  /* 287: of_bsn_controller_connection */
    328,  /* 288: of_bsn_debug_counter_desc_stats_entry */
    16,   /* 289: of_bsn_debug_counter_stats_entry */
    8,    /* 290: of_bsn_flow_checksum_bucket_stats_entry */
    2,    /* 291: of_bsn_generic_stats_entry */
    16,   /* 292: of_bsn_gentable_bucket_stats_entry */
    48,   /* 293: of_bsn_gentable_desc_stats_entry */
    20,   /* 294: of_bsn_gentable_entry_desc_stats_entry */
    4,    /* 295: of_bsn_gentable_entry_stats_entry */
    24,   /* 296: of_bsn_gentable_stats_entry */
    32,   /* 297: of_bsn_interface */
    36,   /* 298: of_bsn_lacp_stats_entry */
    8,    /* 299: of_bsn_port_counter_stats_entry */
    256,  /* 300: of_bsn_switch_pipeline_stats_entry */
    9,    /* 301: of_bsn_table_checksum_stats_entry */
    4,    /* 302: of_bsn_tlv */
    6,    /* 303: of_bsn_tlv_actor_key */
    6,    /* 304: of_bsn_tlv_actor_port_num */
    6,    /* 305: of_bsn_tlv_actor_port_priority */
    5,    /* 306: of_bsn_tlv_actor_state */
    10,   /* 307: of_bsn_tlv_actor_system_mac */
    6,    /* 308: of_bsn_tlv_actor_system_priority */
    6,    /* 309: of_bsn_tlv_anchor */
    12,   /* 310: of_bsn_tlv_apply_bytes */
    12,   /* 311: of_bsn_tlv_apply_packets */
    5,    /* 312: of_bsn_tlv_auto_negotiation */
    5,    /* 313: of_bsn_tlv_bfd_endpoint */
    5,    /* 314: of_bsn_tlv_bfd_state */
    8,    /* 315: of_bsn_tlv_broadcast_query_timeout */
    8,    /* 316: of_bsn_tlv_broadcast_rate */
    4,    /* 317: of_bsn_tlv_bucket */
    4,    /* 318: of_bsn_tlv_circuit_id */
    5,    /* 319: of_bsn_tlv_convergence_status */
    4,    /* 320: of_bsn_tlv_cpu_lag */
    5,    /* 321: of_bsn_tlv_crc_enabled */
    4,    /* 322: of_bsn_tlv_data */
    4,    /* 323: of_bsn_tlv_data_mask */
    6,    /* 324: of_bsn_tlv_decap */
    4,    /* 325: of_bsn_tlv_disable_src_mac_check */
    4,    /* 326: of_bsn_tlv_drop */
    6,    /* 327: of_bsn_tlv_dscp */
    5,    /* 328: of_bsn_tlv_ecn */
    4,    /* 329: of_bsn_tlv_egress_only */
    8,    /* 330: of_bsn_tlv_egress_port_group_id */
    5,    /* 331: of_bsn_tlv_encap */
    12,   /* 332: of_bsn_tlv_enhanced_hash_capability */
    10,   /* 333: of_bsn_tlv_eth_dst */
    10,   /* 334: of_bsn_tlv_eth_src */
    6,    /* 335: of_bsn_tlv_eth_type */
    8,    /* 336: of_bsn_tlv_external_gateway_ip */
    10,   /* 337: of_bsn_tlv_external_gateway_mac */
    8,    /* 338: of_bsn_tlv_external_ip */
    10,   /* 339: of_bsn_tlv_external_mac */
    8,    /* 340: of_bsn_tlv_external_netmask */
    6,    /* 341: of_bsn_tlv_fabric_port_role */
    4,    /* 342: of_bsn_tlv_flood */
    6,    /* 343: of_bsn_tlv_flow_classifier */
    4,    /* 344: of_bsn_tlv_flow_classify */
    8,    /* 345: of_bsn_tlv_flow_identifier */
    4,    /* 346: of_bsn_tlv_force_link_up */
    5,    /* 347: of_bsn_tlv_forward_error_correction */
    12,   /* 348: of_bsn_tlv_generation_id */
    6,    /* 349: of_bsn_tlv_hash_algorithm */
    6,    /* 350: of_bsn_tlv_hash_gtp_header_match */
    9,    /* 351: of_bsn_tlv_hash_gtp_port_match */
    12,   /* 352: of_bsn_tlv_hash_packet_field */
    5,    /* 353: of_bsn_tlv_hash_packet_type */
    12,   /* 354: of_bsn_tlv_hash_seed */
    5,    /* 355: of_bsn_tlv_hash_type */
    8,    /* 356: of_bsn_tlv_header_size */
    5,    /* 357: of_bsn_tlv_icmp_code */
    6,    /* 358: of_bsn_tlv_icmp_id */
    5,    /* 359: of_bsn_tlv_icmp_type */
    6,    /* 360: of_bsn_tlv_icmpv6_chksum */
    8,    /* 361: of_bsn_tlv_identifier */
    4,    /* 362: of_bsn_tlv_idle_notification */
    12,   /* 363: of_bsn_tlv_idle_time */
    8,    /* 364: of_bsn_tlv_idle_timeout */
    4,    /* 365: of_bsn_tlv_igmp_snooping */
    8,    /* 366: of_bsn_tlv_ingress_port_group_id */
    10,   /* 367: of_bsn_tlv_internal_gateway_mac */
    10,   /* 368: of_bsn_tlv_internal_mac */
    8,    /* 369: of_bsn_tlv_interval */
    5,    /* 370: of_bsn_tlv_ip_proto */
    6,    /* 371: of_bsn_tlv_ip_tunnel_type */
    8,    /* 372: of_bsn_tlv_ipv4 */
    8,    /* 373: of_bsn_tlv_ipv4_dst */
    8,    /* 374: of_bsn_tlv_ipv4_netmask */
    8,    /* 375: of_bsn_tlv_ipv4_src */
    20,   /* 376: of_bsn_tlv_ipv6 */
    20,   /* 377: of_bsn_tlv_ipv6_dst */
    21,   /* 378: of_bsn_tlv_ipv6_prefix */
    20,   /* 379: of_bsn_tlv_ipv6_src */
    8,    /* 380: of_bsn_tlv_known_multicast_rate */
    4,    /* 381: of_bsn_tlv_l2_multicast_lookup */
    4,    /* 382: of_bsn_tlv_l3 */
    8,    /* 383: of_bsn_tlv_l3_dst_class_id */
    8,    /* 384: of_bsn_tlv_l3_interface_class_id */
    8,    /* 385: of_bsn_tlv_l3_src_class_id */
    6,    /* 386: of_bsn_tlv_lag_options */
    5,    /* 387: of_bsn_tlv_loopback_mode */
    8,    /* 388: of_bsn_tlv_loopback_port */
    4,    /* 389: of_bsn_tlv_lr_all_enabled */
    10,   /* 390: of_bsn_tlv_mac */
    10,   /* 391: of_bsn_tlv_mac_mask */
    4,    /* 392: of_bsn_tlv_mcg_type_vxlan */
    12,   /* 393: of_bsn_tlv_miss_packets */
    5,    /* 394: of_bsn_tlv_mpls_control_word */
    8,    /* 395: of_bsn_tlv_mpls_label */
    5,    /* 396: of_bsn_tlv_mpls_sequenced */
    8,    /* 397: of_bsn_tlv_multicast_interface_id */
    6,    /* 398: of_bsn_tlv_multicast_packet */
    8,    /* 399: of_bsn_tlv_multiplier */
    4,    /* 400: of_bsn_tlv_name */
    4,    /* 401: of_bsn_tlv_ndp_offload */
    4,    /* 402: of_bsn_tlv_ndp_static */
    4,    /* 403: of_bsn_tlv_negate */
    8,    /* 404: of_bsn_tlv_next_hop_ipv4 */
    10,   /* 405: of_bsn_tlv_next_hop_mac */
    4,    /* 406: of_bsn_tlv_nexthop_type_vxlan */
    4,    /* 407: of_bsn_tlv_no_arp_response */
    4,    /* 408: of_bsn_tlv_no_ns_response */
    6,    /* 409: of_bsn_tlv_offset */
    4,    /* 410: of_bsn_tlv_optics_always_enabled */
    10,   /* 411: of_bsn_tlv_outer_src_mac */
    8,    /* 412: of_bsn_tlv_parent_port */
    6,    /* 413: of_bsn_tlv_partner_key */
    6,    /* 414: of_bsn_tlv_partner_port_num */
    6,    /* 415: of_bsn_tlv_partner_port_priority */
    5,    /* 416: of_bsn_tlv_partner_state */
    10,   /* 417: of_bsn_tlv_partner_system_mac */
    6,    /* 418: of_bsn_tlv_partner_system_priority */
    4,    /* 419: of_bsn_tlv_passive */
    4,    /* 420: of_bsn_tlv_pdua_rx_instance */
    4,    /* 421: of_bsn_tlv_pim_dr */
    4,    /* 422: of_bsn_tlv_pim_hello_flood */
    8,    /* 423: of_bsn_tlv_port */
    6,    /* 424: of_bsn_tlv_port_mode */
    8,    /* 425: of_bsn_tlv_port_speed_gbps */
    6,    /* 426: of_bsn_tlv_port_usage */
    5,    /* 427: of_bsn_tlv_port_vxlan_mode */
    8,    /* 428: of_bsn_tlv_priority */
    4,    /* 429: of_bsn_tlv_push_vlan_on_egress */
    5,    /* 430: of_bsn_tlv_push_vlan_on_ingress */
    8,    /* 431: of_bsn_tlv_qos_priority */
    8,    /* 432: of_bsn_tlv_queue_id */
    8,    /* 433: of_bsn_tlv_queue_weight */
    8,    /* 434: of_bsn_tlv_rate_limit */
    5,    /* 435: of_bsn_tlv_rate_unit */
    8,    /* 436: of_bsn_tlv_record_packets */
    6,    /* 437: of_bsn_tlv_reference */
    12,   /* 438: of_bsn_tlv_reply_packets */
    12,   /* 439: of_bsn_tlv_request_packets */
    4,    /* 440: of_bsn_tlv_rest_server */
    6,    /* 441: of_bsn_tlv_routing_param */
    12,   /* 442: of_bsn_tlv_rx_bytes */
    12,   /* 443: of_bsn_tlv_rx_packets */
    8,    /* 444: of_bsn_tlv_sampling_rate */
    4,    /* 445: of_bsn_tlv_set_loopback_mode */
    5,    /* 446: of_bsn_tlv_status */
    4,    /* 447: of_bsn_tlv_strip_mpls_l2_on_ingress */
    4,    /* 448: of_bsn_tlv_strip_mpls_l3_on_ingress */
    5,    /* 449: of_bsn_tlv_strip_vlan_on_egress */
    8,    /* 450: of_bsn_tlv_sub_agent_id */
    6,    /* 451: of_bsn_tlv_tcp_dst */
    6,    /* 452: of_bsn_tlv_tcp_flags */
    6,    /* 453: of_bsn_tlv_tcp_src */
    12,   /* 454: of_bsn_tlv_timestamp */
    6,    /* 455: of_bsn_tlv_ttl */
    12,   /* 456: of_bsn_tlv_tunnel_capability */
    12,   /* 457: of_bsn_tlv_tx_bytes */
    12,   /* 458: of_bsn_tlv_tx_packets */
    6,    /* 459: of_bsn_tlv_udf_anchor */
    5,    /* 460: of_bsn_tlv_udf_capability */
    6,    /* 461: of_bsn_tlv_udf_id */
    6,    /* 462: of_bsn_tlv_udf_length */
    6,    /* 463: of_bsn_tlv_udf_offset */
    6,    /* 464: of_bsn_tlv_udp_dst */
    6,    /* 465: of_bsn_tlv_udp_src */
    8,    /* 466: of_bsn_tlv_uint32 */
    4,    /* 467: of_bsn_tlv_uint64_list */
    8,    /* 468: of_bsn_tlv_unicast_query_timeout */
    8,    /* 469: of_bsn_tlv_unicast_rate */
    8,    /* 470: of_bsn_tlv_unknown_multicast_rate */
    4,    /* 471: of_bsn_tlv_untagged */
    6,    /* 472: of_bsn_tlv_upgrade */
    4,    /* 473: of_bsn_tlv_uri_scheme */
    5,    /* 474: of_bsn_tlv_use_packet_state */
    4,    /* 475: of_bsn_tlv_user_configured */
    6,    /* 476: of_bsn_tlv_vfi */
    8,    /* 477: of_bsn_tlv_vfp_class_id */
    4,    /* 478: of_bsn_tlv_virtual */
    4,    /* 479: of_bsn_tlv_vlan_mac_list */
    5,    /* 480: of_bsn_tlv_vlan_pcp */
    6,    /* 481: of_bsn_tlv_vlan_vid */
    6,    /* 482: of_bsn_tlv_vlan_vid_mask */
    8,    /* 483: of_bsn_tlv_vni */
    8,    /* 484: of_bsn_tlv_vpn_key */
    8,    /* 485: of_bsn_tlv_vrf */
    4,    /* 486: of_bsn_tlv_vxlan_egress_lag */
    8,    /* 487: of_bsn_vlan_counter_stats_entry */
    8,    /* 488: of_bsn_vlan_mac */
    4,    /* 489: of_bsn_vport */
    64,   /* 490: of_bsn_vport_l2gre */
    32,   /* 491: of_bsn_vport_q_in_q */
    8,    /* 492: of_bsn_vrf_counter_stats_entry */
    16,   /* 493: of_bucket */
    16,   /* 494: of_bucket_counter */
    4,    /* 495: of_bundle_prop */
    12,   /* 496: of_bundle_prop_experimenter */
    56,   /* 497: of_flow_stats_entry */
    8,    /* 498: of_group_desc_stats_entry */
    40,   /* 499: of_group_stats_entry */
    4,    /* 500: of_hello_elem */
    4,    /* 501: of_hello_elem_versionbitmap */
    4,    /* 502: of_instruction */
    8,    /* 503: of_instruction_apply_actions */
    16,   /* 504: of_instruction_bsn */
    16,   /* 505: of_instruction_bsn_arp_offload */
    16,   /* 506: of_instruction_bsn_auto_negotiation */
    16,   /* 507: of_instruction_bsn_deny */
    16,   /* 508: of_instruction_bsn_dhcp_offload */
    16,   /* 509: of_instruction_bsn_directed_broadcast */
    16,   /* 510: of_instruction_bsn_disable_l3 */
    -1,   /* 511: of_instruction_bsn_disable_split_horizon_check */
    16,   /* 512: of_instruction_bsn_disable_src_mac_check */
    16,   /* 513: of_instruction_bsn_disable_vlan_counters */
    16,   /* 514: of_instruction_bsn_hash_select */
    16,   /* 515: of_instruction_bsn_internal_priority */
    16,   /* 516: of_instruction_bsn_ndp_offload */
    16,   /* 517: of_instruction_bsn_packet_of_death */
    16,   /* 518: of_instruction_bsn_permit */
    16,   /* 519: of_instruction_bsn_prioritize_pdus */
    16,   /* 520: of_instruction_bsn_require_vlan_xlate */
    16,   /* 521: of_instruction_bsn_span_destination */
    8,    /* 522: of_instruction_clear_actions */
    8,    /* 523: of_instruction_experimenter */
    8,    /* 524: of_instruction_goto_table */
    4,    /* 525: of_instruction_id */
    4,    /* 526: of_instruction_id_apply_actions */
    12,   /* 527: of_instruction_id_bsn */
    12,   /* 528: of_instruction_id_bsn_arp_offload */
    12,   /* 529: of_instruction_id_bsn_auto_negotiation */
    12,   /* 530: of_instruction_id_bsn_deny */
    12,   /* 531: of_instruction_id_bsn_dhcp_offload */
    12,   /* 532: of_instruction_id_bsn_directed_broadcast */
    12,   /* 533: of_instruction_id_bsn_disable_l3 */
    -1,   /* 534: of_instruction_id_bsn_disable_split_horizon_check */
    12,   /* 535: of_instruction_id_bsn_disable_src_mac_check */
    12,   /* 536: of_instruction_id_bsn_disable_vlan_counters */
    12,   /* 537: of_instruction_id_bsn_hash_select */
    12,   /* 538: of_instruction_id_bsn_internal_priority */
    12,   /* 539: of_instruction_id_bsn_ndp_offload */
    12,   /* 540: of_instruction_id_bsn_packet_of_death */
    12,   /* 541: of_instruction_id_bsn_permit */
    12,   /* 542: of_instruction_id_bsn_prioritize_pdus */
    12,   /* 543: of_instruction_id_bsn_require_vlan_xlate */
    12,   /* 544: of_instruction_id_bsn_span_destination */
    4,    /* 545: of_instruction_id_clear_actions */
    8,    /* 546: of_instruction_id_experimenter */
    4,    /* 547: of_instruction_id_goto_table */
    4,    /* 548: of_instruction_id_meter */
    4,    /* 549: of_instruction_id_write_actions */
    4,    /* 550: of_instruction_id_write_metadata */
    8,    /* 551: of_instruction_meter */
    8,    /* 552: of_instruction_write_actions */
    24,   /* 553: of_instruction_write_metadata */
    -1,   /* 554: of_match_v1 */
    -1,   /* 555: of_match_v2 */
    4,    /* 556: of_match_v3 */
    4,    /* 557: of_meter_band */
    16,   /* 558: of_meter_band_drop */
    16,   /* 559: of_meter_band_dscp_remark */
    16,   /* 560: of_meter_band_experimenter */
    16,   /* 561: of_meter_band_stats */
    8,    /* 562: of_meter_config */
    16,   /* 563: of_meter_features */
    40,   /* 564: of_meter_stats */
    4,    /* 565: of_oxm */
    6,    /* 566: of_oxm_arp_op */
    8,    /* 567: of_oxm_arp_op_masked */
    10,   /* 568: of_oxm_arp_sha */
    16,   /* 569: of_oxm_arp_sha_masked */
    8,    /* 570: of_oxm_arp_spa */
    12,   /* 571: of_oxm_arp_spa_masked */
    10,   /* 572: of_oxm_arp_tha */
    16,   /* 573: of_oxm_arp_tha_masked */
    8,    /* 574: of_oxm_arp_tpa */
    12,   /* 575: of_oxm_arp_tpa_masked */
    8,    /* 576: of_oxm_bsn_egr_port_group_id */
    12,   /* 577: of_oxm_bsn_egr_port_group_id_masked */
    -1,   /* 578: of_oxm_bsn_global_vrf_allowed */
    -1,   /* 579: of_oxm_bsn_global_vrf_allowed_masked */
    8,    /* 580: of_oxm_bsn_ifp_class_id */
    12,   /* 581: of_oxm_bsn_ifp_class_id_masked */
    20,   /* 582: of_oxm_bsn_in_ports_128 */
    36,   /* 583: of_oxm_bsn_in_ports_128_masked */
    68,   /* 584: of_oxm_bsn_in_ports_512 */
    132,  /* 585: of_oxm_bsn_in_ports_512_masked */
    8,    /* 586: of_oxm_bsn_ingress_port_group_id */
    12,   /* 587: of_oxm_bsn_ingress_port_group_id_masked */
    10,   /* 588: of_oxm_bsn_inner_eth_dst */
    16,   /* 589: of_oxm_bsn_inner_eth_dst_masked */
    10,   /* 590: of_oxm_bsn_inner_eth_src */
    16,   /* 591: of_oxm_bsn_inner_eth_src_masked */
    6,    /* 592: of_oxm_bsn_inner_vlan_vid */
    8,    /* 593: of_oxm_bsn_inner_vlan_vid_masked */
    5,    /* 594: of_oxm_bsn_ip_fragmentation */
    6,    /* 595: of_oxm_bsn_ip_fragmentation_masked */
    5,    /* 596: of_oxm_bsn_l2_cache_hit */
    6,    /* 597: of_oxm_bsn_l2_cache_hit_masked */
    -1,   /* 598: of_oxm_bsn_l3_dst_class_id */
    -1,   /* 599: of_oxm_bsn_l3_dst_class_id_masked */
    8,    /* 600: of_oxm_bsn_l3_interface_class_id */
    12,   /* 601: of_oxm_bsn_l3_interface_class_id_masked */
    8,    /* 602: of_oxm_bsn_l3_src_class_id */
    12,   /* 603: of_oxm_bsn_l3_src_class_id_masked */
    8,    /* 604: of_oxm_bsn_lag_id */
    12,   /* 605: of_oxm_bsn_lag_id_masked */
    6,    /* 606: of_oxm_bsn_tcp_flags */
    8,    /* 607: of_oxm_bsn_tcp_flags_masked */
    8,    /* 608: of_oxm_bsn_udf0 */
    12,   /* 609: of_oxm_bsn_udf0_masked */
    8,    /* 610: of_oxm_bsn_udf1 */
    12,   /* 611: of_oxm_bsn_udf1_masked */
    8,    /* 612: of_oxm_bsn_udf2 */
    12,   /* 613: of_oxm_bsn_udf2_masked */
    8,    /* 614: of_oxm_bsn_udf3 */
    12,   /* 615: of_oxm_bsn_udf3_masked */
    8,    /* 616: of_oxm_bsn_udf4 */
    12,   /* 617: of_oxm_bsn_udf4_masked */
    8,    /* 618: of_oxm_bsn_udf5 */
    12,   /* 619: of_oxm_bsn_udf5_masked */
    8,    /* 620: of_oxm_bsn_udf6 */
    12,   /* 621: of_oxm_bsn_udf6_masked */
    8,    /* 622: of_oxm_bsn_udf7 */
    12,   /* 623: of_oxm_bsn_udf7_masked */
    6,    /* 624: of_oxm_bsn_vfi */
    8,    /* 625: of_oxm_bsn_vfi_masked */
    8,    /* 626: of_oxm_bsn_vlan_xlate_port_group_id */
    12,   /* 627: of_oxm_bsn_vlan_xlate_port_group_id_masked */
    8,    /* 628: of_oxm_bsn_vrf */
    12,   /* 629: of_oxm_bsn_vrf_masked */
    8,    /* 630: of_oxm_bsn_vxlan_network_id */
    12,   /* 631: of_oxm_bsn_vxlan_network_id_masked */
    20,   /* 632: of_oxm_conn_tracking_ipv6_dst */
    36,   /* 633: of_oxm_conn_tracking_ipv6_dst_masked */
    20,   /* 634: of_oxm_conn_tracking_ipv6_src */
    36,   /* 635: of_oxm_conn_tracking_ipv6_src_masked */
    20,   /* 636: of_oxm_conn_tracking_label */
    36,   /* 637: of_oxm_conn_tracking_label_masked */
    8,    /* 638: of_oxm_conn_tracking_mark */
    12,   /* 639: of_oxm_conn_tracking_mark_masked */
    8,    /* 640: of_oxm_conn_tracking_nw_dst */
    12,   /* 641: of_oxm_conn_tracking_nw_dst_masked */
    5,    /* 642: of_oxm_conn_tracking_nw_proto */
    6,    /* 643: of_oxm_conn_tracking_nw_proto_masked */
    8,    /* 644: of_oxm_conn_tracking_nw_src */
    12,   /* 645: of_oxm_conn_tracking_nw_src_masked */
    8,    /* 646: of_oxm_conn_tracking_state */
    12,   /* 647: of_oxm_conn_tracking_state_masked */
    6,    /* 648: of_oxm_conn_tracking_tp_dst */
    8,    /* 649: of_oxm_conn_tracking_tp_dst_masked */
    6,    /* 650: of_oxm_conn_tracking_tp_src */
    8,    /* 651: of_oxm_conn_tracking_tp_src_masked */
    6,    /* 652: of_oxm_conn_tracking_zone */
    8,    /* 653: of_oxm_conn_tracking_zone_masked */
    10,   /* 654: of_oxm_eth_dst */
    16,   /* 655: of_oxm_eth_dst_masked */
    10,   /* 656: of_oxm_eth_src */
    16,   /* 657: of_oxm_eth_src_masked */
    6,    /* 658: of_oxm_eth_type */
    8,    /* 659: of_oxm_eth_type_masked */
    5,    /* 660: of_oxm_icmpv4_code */
    6,    /* 661: of_oxm_icmpv4_code_masked */
    5,    /* 662: of_oxm_icmpv4_type */
    6,    /* 663: of_oxm_icmpv4_type_masked */
    5,    /* 664: of_oxm_icmpv6_code */
    6,    /* 665: of_oxm_icmpv6_code_masked */
    5,    /* 666: of_oxm_icmpv6_type */
    6,    /* 667: of_oxm_icmpv6_type_masked */
    8,    /* 668: of_oxm_in_phy_port */
    12,   /* 669: of_oxm_in_phy_port_masked */
    8,    /* 670: of_oxm_in_port */
    12,   /* 671: of_oxm_in_port_masked */
    5,    /* 672: of_oxm_ip_dscp */
    6,    /* 673: of_oxm_ip_dscp_masked */
    5,    /* 674: of_oxm_ip_ecn */
    6,    /* 675: of_oxm_ip_ecn_masked */
    5,    /* 676: of_oxm_ip_proto */
    6,    /* 677: of_oxm_ip_proto_masked */
    8,    /* 678: of_oxm_ipv4_dst */
    12,   /* 679: of_oxm_ipv4_dst_masked */
    8,    /* 680: of_oxm_ipv4_src */
    12,   /* 681: of_oxm_ipv4_src_masked */
    20,   /* 682: of_oxm_ipv6_dst */
    36,   /* 683: of_oxm_ipv6_dst_masked */
    6,    /* 684: of_oxm_ipv6_exthdr */
    8,    /* 685: of_oxm_ipv6_exthdr_masked */
    8,    /* 686: of_oxm_ipv6_flabel */
    12,   /* 687: of_oxm_ipv6_flabel_masked */
    10,   /* 688: of_oxm_ipv6_nd_sll */
    16,   /* 689: of_oxm_ipv6_nd_sll_masked */
    20,   /* 690: of_oxm_ipv6_nd_target */
    36,   /* 691: of_oxm_ipv6_nd_target_masked */
    10,   /* 692: of_oxm_ipv6_nd_tll */
    16,   /* 693: of_oxm_ipv6_nd_tll_masked */
    20,   /* 694: of_oxm_ipv6_src */
    36,   /* 695: of_oxm_ipv6_src_masked */
    12,   /* 696: of_oxm_metadata */
    20,   /* 697: of_oxm_metadata_masked */
    5,    /* 698: of_oxm_mpls_bos */
    6,    /* 699: of_oxm_mpls_bos_masked */
    8,    /* 700: of_oxm_mpls_label */
    12,   /* 701: of_oxm_mpls_label_masked */
    5,    /* 702: of_oxm_mpls_tc */
    6,    /* 703: of_oxm_mpls_tc_masked */
    10,   /* 704: of_oxm_ovs_tcp_flags */
    12,   /* 705: of_oxm_ovs_tcp_flags_masked */
    5,    /* 706: of_oxm_pbb_uca */
    6,    /* 707: of_oxm_pbb_uca_masked */
    6,    /* 708: of_oxm_sctp_dst */
    8,    /* 709: of_oxm_sctp_dst_masked */
    6,    /* 710: of_oxm_sctp_src */
    8,    /* 711: of_oxm_sctp_src_masked */
    6,    /* 712: of_oxm_tcp_dst */
    8,    /* 713: of_oxm_tcp_dst_masked */
    6,    /* 714: of_oxm_tcp_src */
    8,    /* 715: of_oxm_tcp_src_masked */
    12,   /* 716: of_oxm_tunnel_id */
    20,   /* 717: of_oxm_tunnel_id_masked */
    8,    /* 718: of_oxm_tunnel_ipv4_dst */
    12,   /* 719: of_oxm_tunnel_ipv4_dst_masked */
    8,    /* 720: of_oxm_tunnel_ipv4_src */
    12,   /* 721: of_oxm_tunnel_ipv4_src_masked */
    6,    /* 722: of_oxm_udp_dst */
    8,    /* 723: of_oxm_udp_dst_masked */
    6,    /* 724: of_oxm_udp_src */
    8,    /* 725: of_oxm_udp_src_masked */
    5,    /* 726: of_oxm_vlan_pcp */
    6,    /* 727: of_oxm_vlan_pcp_masked */
    6,    /* 728: of_oxm_vlan_vid */
    8,    /* 729: of_oxm_vlan_vid_masked */
    16,   /* 730: of_packet_queue */
    40,   /* 731: of_port_desc */
    4,    /* 732: of_port_desc_prop */
    12,   /* 733: of_port_desc_prop_bsn */
    16,   /* 734: of_port_desc_prop_bsn_breakout */
    12,   /* 735: of_port_desc_prop_bsn_driver_info_json */
    20,   /* 736: of_port_desc_prop_bsn_forward_error_correction */
    20,   /* 737: of_port_desc_prop_bsn_generation_id */
    36,   /* 738: of_port_desc_prop_bsn_misc_capabilities */
    12,   /* 739: of_port_desc_prop_bsn_sff_json */
    36,   /* 740: of_port_desc_prop_bsn_speed_capabilities */
    12,   /* 741: of_port_desc_prop_bsn_uplink */
    32,   /* 742: of_port_desc_prop_ethernet */
    8,    /* 743: of_port_desc_prop_experimenter */
    44,   /* 744: of_port_desc_prop_optical */
    4,    /* 745: of_port_mod_prop */
    8,    /* 746: of_port_mod_prop_ethernet */
    12,   /* 747: of_port_mod_prop_experimenter */
    24,   /* 748: of_port_mod_prop_optical */
    80,   /* 749: of_port_stats_entry */
    4,    /* 750: of_port_stats_prop */
    40,   /* 751: of_port_stats_prop_ethernet */
    12,   /* 752: of_port_stats_prop_experimenter */
    184,  /* 753: of_port_stats_prop_experimenter_intel */
    44,   /* 754: of_port_stats_prop_optical */
    16,   /* 755: of_queue_desc */
    4,    /* 756: of_queue_desc_prop */
    12,   /* 757: of_queue_desc_prop_bsn */
    12,   /* 758: of_queue_desc_prop_bsn_queue_name */
    12,   /* 759: of_queue_desc_prop_experimenter */
    8,    /* 760: of_queue_desc_prop_max_rate */
    8,    /* 761: of_queue_desc_prop_min_rate */
    8,    /* 762: of_queue_prop */
    16,   /* 763: of_queue_prop_experimenter */
    16,   /* 764: of_queue_prop_max_rate */
    16,   /* 765: of_queue_prop_min_rate */
    48,   /* 766: of_queue_stats_entry */
    4,    /* 767: of_queue_stats_prop */
    12,   /* 768: of_queue_stats_prop_experimenter */
    4,    /* 769: of_role_prop */
    12,   /* 770: of_role_prop_experimenter */
    8,    /* 771: of_table_desc */
    4,    /* 772: of_table_feature_prop */
    4,    /* 773: of_table_feature_prop_apply_actions */
    4,    /* 774: of_table_feature_prop_apply_actions_miss */
    4,    /* 775: of_table_feature_prop_apply_setfield */
    4,    /* 776: of_table_feature_prop_apply_setfield_miss */
    12,   /* 777: of_table_feature_prop_experimenter */
    12,   /* 778: of_table_feature_prop_experimenter_miss */
    4,    /* 779: of_table_feature_prop_instructions */
    4,    /* 780: of_table_feature_prop_instructions_miss */
    4,    /* 781: of_table_feature_prop_match */
    4,    /* 782: of_table_feature_prop_next_tables */
    4,    /* 783: of_table_feature_prop_next_tables_miss */
    4,    /* 784: of_table_feature_prop_table_sync_from */
    4,    /* 785: of_table_feature_prop_wildcards */
    4,    /* 786: of_table_feature_prop_write_actions */
    4,    /* 787: of_table_feature_prop_write_actions_miss */
    4,    /* 788: of_table_feature_prop_write_setfield */
    4,    /* 789: of_table_feature_prop_write_setfield_miss */
    64,   /* 790: of_table_features */
    4,    /* 791: of_table_mod_prop */
    8,    /* 792: of_table_mod_prop_eviction */
    12,   /* 793: of_table_mod_prop_experimenter */
    8,    /* 794: of_table_mod_prop_vacancy */
    24,   /* 795: of_table_stats_entry */
    4,    /* 796: of_uint32 */
    8,    /* 797: of_uint64 */
    1,    /* 798: of_uint8 */
    0,    /* 799: of_list_action */
    0,    /* 800: of_list_action_id */
    0,    /* 801: of_list_async_config_prop */
    0,    /* 802: of_list_bsn_controller_connection */
    0,    /* 803: of_list_bsn_debug_counter_desc_stats_entry */
    0,    /* 804: of_list_bsn_debug_counter_stats_entry */
    0,    /* 805: of_list_bsn_flow_checksum_bucket_stats_entry */
    0,    /* 806: of_list_bsn_generic_stats_entry */
    0,    /* 807: of_list_bsn_gentable_bucket_stats_entry */
    0,    /* 808: of_list_bsn_gentable_desc_stats_entry */
    0,    /* 809: of_list_bsn_gentable_entry_desc_stats_entry */
    0,    /* 810: of_list_bsn_gentable_entry_stats_entry */
    0,    /* 811: of_list_bsn_gentable_stats_entry */
    0,    /* 812: of_list_bsn_interface */
    0,    /* 813: of_list_bsn_lacp_stats_entry */
    0,    /* 814: of_list_bsn_port_counter_stats_entry */
    0,    /* 815: of_list_bsn_switch_pipeline_stats_entry */
    0,    /* 816: of_list_bsn_table_checksum_stats_entry */
    0,    /* 817: of_list_bsn_tlv */
    0,    /* 818: of_list_bsn_vlan_counter_stats_entry */
    0,    /* 819: of_list_bsn_vlan_mac */
    0,    /* 820: of_list_bsn_vrf_counter_stats_entry */
    0,    /* 821: of_list_bucket */
    0,    /* 822: of_list_bucket_counter */
    0,    /* 823: of_list_bundle_prop */
    0,    /* 824: of_list_flow_stats_entry */
    0,    /* 825: of_list_group_desc_stats_entry */
    0,    /* 826: of_list_group_stats_entry */
    0,    /* 827: of_list_hello_elem */
    0,    /* 828: of_list_instruction */
    0,    /* 829: of_list_instruction_id */
    0,    /* 830: of_list_meter_band */
    0,    /* 831: of_list_meter_band_stats */
    0,    /* 832: of_list_meter_config */
    0,    /* 833: of_list_meter_stats */
    0,    /* 834: of_list_oxm */
    -1,   /* 835: of_list_packet_queue */
    0,    /* 836: of_list_port_desc */
    0,    /* 837: of_list_port_desc_prop */
    0,    /* 838: of_list_port_mod_prop */
    0,    /* 839: of_list_port_stats_entry */
    0,    /* 840: of_list_port_stats_prop */
    0,    /* 841: of_list_queue_desc */
    0,    /* 842: of_list_queue_desc_prop */
    0,    /* 843: of_list_queue_prop */
    0,    /* 844: of_list_queue_stats_entry */
    0,    /* 845: of_list_queue_stats_prop */
    0,    /* 846: of_list_role_prop */
    0,    /* 847: of_list_table_desc */
    0,    /* 848: of_list_table_feature_prop */
    0,    /* 849: of_list_table_features */
    0,    /* 850: of_list_table_mod_prop */
    0,    /* 851: of_list_table_stats_entry */
    0,    /* 852: of_list_uint32 */
    0,    /* 853: of_list_uint64 */
    0     /* 854: of_list_uint8 */
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
