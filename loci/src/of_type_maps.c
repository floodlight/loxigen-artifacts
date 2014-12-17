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
    -1,   /* 34: of_bsn_generic_stats_reply */
    -1,   /* 35: of_bsn_generic_stats_request */
    -1,   /* 36: of_bsn_gentable_bucket_stats_reply */
    -1,   /* 37: of_bsn_gentable_bucket_stats_request */
    -1,   /* 38: of_bsn_gentable_clear_reply */
    -1,   /* 39: of_bsn_gentable_clear_request */
    -1,   /* 40: of_bsn_gentable_desc_stats_reply */
    -1,   /* 41: of_bsn_gentable_desc_stats_request */
    -1,   /* 42: of_bsn_gentable_entry_add */
    -1,   /* 43: of_bsn_gentable_entry_delete */
    -1,   /* 44: of_bsn_gentable_entry_desc_stats_reply */
    -1,   /* 45: of_bsn_gentable_entry_desc_stats_request */
    -1,   /* 46: of_bsn_gentable_entry_stats_reply */
    -1,   /* 47: of_bsn_gentable_entry_stats_request */
    -1,   /* 48: of_bsn_gentable_set_buckets_size */
    -1,   /* 49: of_bsn_gentable_stats_reply */
    -1,   /* 50: of_bsn_gentable_stats_request */
    16,   /* 51: of_bsn_get_interfaces_reply */
    16,   /* 52: of_bsn_get_interfaces_request */
    24,   /* 53: of_bsn_get_ip_mask_reply */
    24,   /* 54: of_bsn_get_ip_mask_request */
    24,   /* 55: of_bsn_get_l2_table_reply */
    16,   /* 56: of_bsn_get_l2_table_request */
    20,   /* 57: of_bsn_get_mirroring_reply */
    20,   /* 58: of_bsn_get_mirroring_request */
    -1,   /* 59: of_bsn_get_switch_pipeline_reply */
    -1,   /* 60: of_bsn_get_switch_pipeline_request */
    16,   /* 61: of_bsn_header */
    24,   /* 62: of_bsn_hybrid_get_reply */
    16,   /* 63: of_bsn_hybrid_get_request */
    -1,   /* 64: of_bsn_image_desc_stats_reply */
    -1,   /* 65: of_bsn_image_desc_stats_request */
    -1,   /* 66: of_bsn_lacp_convergence_notif */
    -1,   /* 67: of_bsn_lacp_stats_reply */
    -1,   /* 68: of_bsn_lacp_stats_request */
    -1,   /* 69: of_bsn_log */
    23,   /* 70: of_bsn_pdu_rx_reply */
    26,   /* 71: of_bsn_pdu_rx_request */
    19,   /* 72: of_bsn_pdu_rx_timeout */
    23,   /* 73: of_bsn_pdu_tx_reply */
    26,   /* 74: of_bsn_pdu_tx_request */
    -1,   /* 75: of_bsn_port_counter_stats_reply */
    -1,   /* 76: of_bsn_port_counter_stats_request */
    -1,   /* 77: of_bsn_role_status */
    -1,   /* 78: of_bsn_set_aux_cxns_reply */
    -1,   /* 79: of_bsn_set_aux_cxns_request */
    24,   /* 80: of_bsn_set_ip_mask */
    24,   /* 81: of_bsn_set_l2_table_reply */
    24,   /* 82: of_bsn_set_l2_table_request */
    -1,   /* 83: of_bsn_set_lacp_reply */
    -1,   /* 84: of_bsn_set_lacp_request */
    20,   /* 85: of_bsn_set_mirroring */
    20,   /* 86: of_bsn_set_pktin_suppression_reply */
    32,   /* 87: of_bsn_set_pktin_suppression_request */
    -1,   /* 88: of_bsn_set_switch_pipeline_reply */
    -1,   /* 89: of_bsn_set_switch_pipeline_request */
    20,   /* 90: of_bsn_shell_command */
    16,   /* 91: of_bsn_shell_output */
    20,   /* 92: of_bsn_shell_status */
    24,   /* 93: of_bsn_stats_reply */
    24,   /* 94: of_bsn_stats_request */
    -1,   /* 95: of_bsn_switch_pipeline_stats_reply */
    -1,   /* 96: of_bsn_switch_pipeline_stats_request */
    -1,   /* 97: of_bsn_table_checksum_stats_reply */
    -1,   /* 98: of_bsn_table_checksum_stats_request */
    -1,   /* 99: of_bsn_table_set_buckets_size */
    -1,   /* 100: of_bsn_time_reply */
    -1,   /* 101: of_bsn_time_request */
    24,   /* 102: of_bsn_virtual_port_create_reply */
    20,   /* 103: of_bsn_virtual_port_create_request */
    20,   /* 104: of_bsn_virtual_port_remove_reply */
    20,   /* 105: of_bsn_virtual_port_remove_request */
    -1,   /* 106: of_bsn_vlan_counter_stats_reply */
    -1,   /* 107: of_bsn_vlan_counter_stats_request */
    -1,   /* 108: of_bsn_vrf_counter_stats_reply */
    -1,   /* 109: of_bsn_vrf_counter_stats_request */
    -1,   /* 110: of_bundle_add_msg */
    -1,   /* 111: of_bundle_ctrl_msg */
    -1,   /* 112: of_bundle_failed_error_msg */
    1068, /* 113: of_desc_stats_reply */
    12,   /* 114: of_desc_stats_request */
    8,    /* 115: of_echo_reply */
    8,    /* 116: of_echo_request */
    10,   /* 117: of_error_msg */
    12,   /* 118: of_experimenter */
    -1,   /* 119: of_experimenter_error_msg */
    16,   /* 120: of_experimenter_stats_reply */
    16,   /* 121: of_experimenter_stats_request */
    32,   /* 122: of_features_reply */
    8,    /* 123: of_features_request */
    72,   /* 124: of_flow_add */
    72,   /* 125: of_flow_delete */
    72,   /* 126: of_flow_delete_strict */
    72,   /* 127: of_flow_mod */
    12,   /* 128: of_flow_mod_failed_error_msg */
    72,   /* 129: of_flow_modify */
    72,   /* 130: of_flow_modify_strict */
    -1,   /* 131: of_flow_monitor_failed_error_msg */
    88,   /* 132: of_flow_removed */
    12,   /* 133: of_flow_stats_reply */
    56,   /* 134: of_flow_stats_request */
    12,   /* 135: of_get_config_reply */
    8,    /* 136: of_get_config_request */
    -1,   /* 137: of_group_add */
    -1,   /* 138: of_group_delete */
    -1,   /* 139: of_group_desc_stats_reply */
    -1,   /* 140: of_group_desc_stats_request */
    -1,   /* 141: of_group_features_stats_reply */
    -1,   /* 142: of_group_features_stats_request */
    -1,   /* 143: of_group_mod */
    -1,   /* 144: of_group_mod_failed_error_msg */
    -1,   /* 145: of_group_modify */
    -1,   /* 146: of_group_stats_reply */
    -1,   /* 147: of_group_stats_request */
    8,    /* 148: of_header */
    8,    /* 149: of_hello */
    12,   /* 150: of_hello_failed_error_msg */
    -1,   /* 151: of_meter_config_stats_reply */
    -1,   /* 152: of_meter_config_stats_request */
    -1,   /* 153: of_meter_features_stats_reply */
    -1,   /* 154: of_meter_features_stats_request */
    -1,   /* 155: of_meter_mod */
    -1,   /* 156: of_meter_mod_failed_error_msg */
    -1,   /* 157: of_meter_stats_reply */
    -1,   /* 158: of_meter_stats_request */
    20,   /* 159: of_nicira_controller_role_reply */
    20,   /* 160: of_nicira_controller_role_request */
    16,   /* 161: of_nicira_header */
    18,   /* 162: of_packet_in */
    16,   /* 163: of_packet_out */
    -1,   /* 164: of_port_desc_stats_reply */
    -1,   /* 165: of_port_desc_stats_request */
    32,   /* 166: of_port_mod */
    12,   /* 167: of_port_mod_failed_error_msg */
    12,   /* 168: of_port_stats_reply */
    20,   /* 169: of_port_stats_request */
    64,   /* 170: of_port_status */
    -1,   /* 171: of_queue_desc_stats_reply */
    -1,   /* 172: of_queue_desc_stats_request */
    16,   /* 173: of_queue_get_config_reply */
    12,   /* 174: of_queue_get_config_request */
    12,   /* 175: of_queue_op_failed_error_msg */
    12,   /* 176: of_queue_stats_reply */
    20,   /* 177: of_queue_stats_request */
    -1,   /* 178: of_requestforward */
    -1,   /* 179: of_role_reply */
    -1,   /* 180: of_role_request */
    -1,   /* 181: of_role_request_failed_error_msg */
    -1,   /* 182: of_role_status */
    12,   /* 183: of_set_config */
    12,   /* 184: of_stats_reply */
    12,   /* 185: of_stats_request */
    -1,   /* 186: of_switch_config_failed_error_msg */
    -1,   /* 187: of_table_desc_stats_reply */
    -1,   /* 188: of_table_desc_stats_request */
    -1,   /* 189: of_table_features_failed_error_msg */
    -1,   /* 190: of_table_features_stats_reply */
    -1,   /* 191: of_table_features_stats_request */
    16,   /* 192: of_table_mod */
    -1,   /* 193: of_table_mod_failed_error_msg */
    12,   /* 194: of_table_stats_reply */
    12,   /* 195: of_table_stats_request */
    -1,   /* 196: of_table_status */
    8,    /* 197: of_action */
    16,   /* 198: of_action_bsn */
    28,   /* 199: of_action_bsn_checksum */
    -1,   /* 200: of_action_bsn_gentable */
    24,   /* 201: of_action_bsn_mirror */
    16,   /* 202: of_action_bsn_set_tunnel_dst */
    -1,   /* 203: of_action_copy_ttl_in */
    -1,   /* 204: of_action_copy_ttl_out */
    -1,   /* 205: of_action_dec_mpls_ttl */
    -1,   /* 206: of_action_dec_nw_ttl */
    16,   /* 207: of_action_enqueue */
    8,    /* 208: of_action_experimenter */
    -1,   /* 209: of_action_group */
    -1,   /* 210: of_action_id */
    -1,   /* 211: of_action_id_bsn */
    -1,   /* 212: of_action_id_bsn_checksum */
    -1,   /* 213: of_action_id_bsn_gentable */
    -1,   /* 214: of_action_id_bsn_mirror */
    -1,   /* 215: of_action_id_bsn_set_tunnel_dst */
    -1,   /* 216: of_action_id_copy_ttl_in */
    -1,   /* 217: of_action_id_copy_ttl_out */
    -1,   /* 218: of_action_id_dec_mpls_ttl */
    -1,   /* 219: of_action_id_dec_nw_ttl */
    -1,   /* 220: of_action_id_experimenter */
    -1,   /* 221: of_action_id_group */
    -1,   /* 222: of_action_id_nicira */
    -1,   /* 223: of_action_id_nicira_dec_ttl */
    -1,   /* 224: of_action_id_output */
    -1,   /* 225: of_action_id_pop_mpls */
    -1,   /* 226: of_action_id_pop_pbb */
    -1,   /* 227: of_action_id_pop_vlan */
    -1,   /* 228: of_action_id_push_mpls */
    -1,   /* 229: of_action_id_push_pbb */
    -1,   /* 230: of_action_id_push_vlan */
    -1,   /* 231: of_action_id_set_field */
    -1,   /* 232: of_action_id_set_mpls_ttl */
    -1,   /* 233: of_action_id_set_nw_ttl */
    -1,   /* 234: of_action_id_set_queue */
    16,   /* 235: of_action_nicira */
    16,   /* 236: of_action_nicira_dec_ttl */
    8,    /* 237: of_action_output */
    -1,   /* 238: of_action_pop_mpls */
    -1,   /* 239: of_action_pop_pbb */
    -1,   /* 240: of_action_pop_vlan */
    -1,   /* 241: of_action_push_mpls */
    -1,   /* 242: of_action_push_pbb */
    -1,   /* 243: of_action_push_vlan */
    16,   /* 244: of_action_set_dl_dst */
    16,   /* 245: of_action_set_dl_src */
    -1,   /* 246: of_action_set_field */
    -1,   /* 247: of_action_set_mpls_label */
    -1,   /* 248: of_action_set_mpls_tc */
    -1,   /* 249: of_action_set_mpls_ttl */
    8,    /* 250: of_action_set_nw_dst */
    -1,   /* 251: of_action_set_nw_ecn */
    8,    /* 252: of_action_set_nw_src */
    8,    /* 253: of_action_set_nw_tos */
    -1,   /* 254: of_action_set_nw_ttl */
    -1,   /* 255: of_action_set_queue */
    8,    /* 256: of_action_set_tp_dst */
    8,    /* 257: of_action_set_tp_src */
    8,    /* 258: of_action_set_vlan_pcp */
    8,    /* 259: of_action_set_vlan_vid */
    8,    /* 260: of_action_strip_vlan */
    -1,   /* 261: of_async_config_prop */
    -1,   /* 262: of_async_config_prop_experimenter_master */
    -1,   /* 263: of_async_config_prop_experimenter_slave */
    -1,   /* 264: of_async_config_prop_flow_removed_master */
    -1,   /* 265: of_async_config_prop_flow_removed_slave */
    -1,   /* 266: of_async_config_prop_packet_in_master */
    -1,   /* 267: of_async_config_prop_packet_in_slave */
    -1,   /* 268: of_async_config_prop_port_status_master */
    -1,   /* 269: of_async_config_prop_port_status_slave */
    -1,   /* 270: of_async_config_prop_requestforward_master */
    -1,   /* 271: of_async_config_prop_requestforward_slave */
    -1,   /* 272: of_async_config_prop_role_status_master */
    -1,   /* 273: of_async_config_prop_role_status_slave */
    -1,   /* 274: of_async_config_prop_table_status_master */
    -1,   /* 275: of_async_config_prop_table_status_slave */
    -1,   /* 276: of_bsn_controller_connection */
    -1,   /* 277: of_bsn_debug_counter_desc_stats_entry */
    -1,   /* 278: of_bsn_debug_counter_stats_entry */
    -1,   /* 279: of_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 280: of_bsn_generic_stats_entry */
    -1,   /* 281: of_bsn_gentable_bucket_stats_entry */
    -1,   /* 282: of_bsn_gentable_desc_stats_entry */
    -1,   /* 283: of_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 284: of_bsn_gentable_entry_stats_entry */
    -1,   /* 285: of_bsn_gentable_stats_entry */
    32,   /* 286: of_bsn_interface */
    -1,   /* 287: of_bsn_lacp_stats_entry */
    -1,   /* 288: of_bsn_port_counter_stats_entry */
    -1,   /* 289: of_bsn_switch_pipeline_stats_entry */
    -1,   /* 290: of_bsn_table_checksum_stats_entry */
    -1,   /* 291: of_bsn_tlv */
    -1,   /* 292: of_bsn_tlv_actor_key */
    -1,   /* 293: of_bsn_tlv_actor_port_num */
    -1,   /* 294: of_bsn_tlv_actor_port_priority */
    -1,   /* 295: of_bsn_tlv_actor_state */
    -1,   /* 296: of_bsn_tlv_actor_system_mac */
    -1,   /* 297: of_bsn_tlv_actor_system_priority */
    -1,   /* 298: of_bsn_tlv_broadcast_query_timeout */
    -1,   /* 299: of_bsn_tlv_bucket */
    -1,   /* 300: of_bsn_tlv_circuit_id */
    -1,   /* 301: of_bsn_tlv_convergence_status */
    -1,   /* 302: of_bsn_tlv_crc_enabled */
    -1,   /* 303: of_bsn_tlv_data */
    -1,   /* 304: of_bsn_tlv_eth_dst */
    -1,   /* 305: of_bsn_tlv_eth_src */
    -1,   /* 306: of_bsn_tlv_external_gateway_ip */
    -1,   /* 307: of_bsn_tlv_external_gateway_mac */
    -1,   /* 308: of_bsn_tlv_external_ip */
    -1,   /* 309: of_bsn_tlv_external_mac */
    -1,   /* 310: of_bsn_tlv_external_netmask */
    -1,   /* 311: of_bsn_tlv_header_size */
    -1,   /* 312: of_bsn_tlv_idle_notification */
    -1,   /* 313: of_bsn_tlv_idle_time */
    -1,   /* 314: of_bsn_tlv_idle_timeout */
    -1,   /* 315: of_bsn_tlv_internal_gateway_mac */
    -1,   /* 316: of_bsn_tlv_internal_mac */
    -1,   /* 317: of_bsn_tlv_interval */
    -1,   /* 318: of_bsn_tlv_ipv4 */
    -1,   /* 319: of_bsn_tlv_ipv4_dst */
    -1,   /* 320: of_bsn_tlv_ipv4_netmask */
    -1,   /* 321: of_bsn_tlv_ipv4_src */
    -1,   /* 322: of_bsn_tlv_mac */
    -1,   /* 323: of_bsn_tlv_mac_mask */
    -1,   /* 324: of_bsn_tlv_miss_packets */
    -1,   /* 325: of_bsn_tlv_mpls_control_word */
    -1,   /* 326: of_bsn_tlv_mpls_label */
    -1,   /* 327: of_bsn_tlv_mpls_sequenced */
    -1,   /* 328: of_bsn_tlv_name */
    -1,   /* 329: of_bsn_tlv_partner_key */
    -1,   /* 330: of_bsn_tlv_partner_port_num */
    -1,   /* 331: of_bsn_tlv_partner_port_priority */
    -1,   /* 332: of_bsn_tlv_partner_state */
    -1,   /* 333: of_bsn_tlv_partner_system_mac */
    -1,   /* 334: of_bsn_tlv_partner_system_priority */
    -1,   /* 335: of_bsn_tlv_port */
    -1,   /* 336: of_bsn_tlv_priority */
    -1,   /* 337: of_bsn_tlv_queue_id */
    -1,   /* 338: of_bsn_tlv_queue_weight */
    -1,   /* 339: of_bsn_tlv_reference */
    -1,   /* 340: of_bsn_tlv_reply_packets */
    -1,   /* 341: of_bsn_tlv_request_packets */
    -1,   /* 342: of_bsn_tlv_rx_packets */
    -1,   /* 343: of_bsn_tlv_sampling_rate */
    -1,   /* 344: of_bsn_tlv_sub_agent_id */
    -1,   /* 345: of_bsn_tlv_tx_bytes */
    -1,   /* 346: of_bsn_tlv_tx_packets */
    -1,   /* 347: of_bsn_tlv_udf_anchor */
    -1,   /* 348: of_bsn_tlv_udf_id */
    -1,   /* 349: of_bsn_tlv_udf_length */
    -1,   /* 350: of_bsn_tlv_udf_offset */
    -1,   /* 351: of_bsn_tlv_udp_dst */
    -1,   /* 352: of_bsn_tlv_udp_src */
    -1,   /* 353: of_bsn_tlv_unicast_query_timeout */
    -1,   /* 354: of_bsn_tlv_vlan_vid */
    -1,   /* 355: of_bsn_tlv_vrf */
    -1,   /* 356: of_bsn_vlan_counter_stats_entry */
    4,    /* 357: of_bsn_vport */
    60,   /* 358: of_bsn_vport_l2gre */
    32,   /* 359: of_bsn_vport_q_in_q */
    -1,   /* 360: of_bsn_vrf_counter_stats_entry */
    -1,   /* 361: of_bucket */
    -1,   /* 362: of_bucket_counter */
    -1,   /* 363: of_bundle_prop */
    -1,   /* 364: of_bundle_prop_experimenter */
    88,   /* 365: of_flow_stats_entry */
    -1,   /* 366: of_group_desc_stats_entry */
    -1,   /* 367: of_group_stats_entry */
    -1,   /* 368: of_hello_elem */
    -1,   /* 369: of_hello_elem_versionbitmap */
    -1,   /* 370: of_instruction */
    -1,   /* 371: of_instruction_apply_actions */
    -1,   /* 372: of_instruction_bsn */
    -1,   /* 373: of_instruction_bsn_arp_offload */
    -1,   /* 374: of_instruction_bsn_auto_negotiation */
    -1,   /* 375: of_instruction_bsn_deny */
    -1,   /* 376: of_instruction_bsn_dhcp_offload */
    -1,   /* 377: of_instruction_bsn_disable_split_horizon_check */
    -1,   /* 378: of_instruction_bsn_disable_src_mac_check */
    -1,   /* 379: of_instruction_bsn_disable_vlan_counters */
    -1,   /* 380: of_instruction_bsn_packet_of_death */
    -1,   /* 381: of_instruction_bsn_permit */
    -1,   /* 382: of_instruction_bsn_prioritize_pdus */
    -1,   /* 383: of_instruction_bsn_require_vlan_xlate */
    -1,   /* 384: of_instruction_bsn_span_destination */
    -1,   /* 385: of_instruction_clear_actions */
    -1,   /* 386: of_instruction_experimenter */
    -1,   /* 387: of_instruction_goto_table */
    -1,   /* 388: of_instruction_id */
    -1,   /* 389: of_instruction_id_apply_actions */
    -1,   /* 390: of_instruction_id_bsn */
    -1,   /* 391: of_instruction_id_bsn_arp_offload */
    -1,   /* 392: of_instruction_id_bsn_auto_negotiation */
    -1,   /* 393: of_instruction_id_bsn_deny */
    -1,   /* 394: of_instruction_id_bsn_dhcp_offload */
    -1,   /* 395: of_instruction_id_bsn_disable_split_horizon_check */
    -1,   /* 396: of_instruction_id_bsn_disable_src_mac_check */
    -1,   /* 397: of_instruction_id_bsn_disable_vlan_counters */
    -1,   /* 398: of_instruction_id_bsn_packet_of_death */
    -1,   /* 399: of_instruction_id_bsn_permit */
    -1,   /* 400: of_instruction_id_bsn_prioritize_pdus */
    -1,   /* 401: of_instruction_id_bsn_require_vlan_xlate */
    -1,   /* 402: of_instruction_id_bsn_span_destination */
    -1,   /* 403: of_instruction_id_clear_actions */
    -1,   /* 404: of_instruction_id_experimenter */
    -1,   /* 405: of_instruction_id_goto_table */
    -1,   /* 406: of_instruction_id_meter */
    -1,   /* 407: of_instruction_id_write_actions */
    -1,   /* 408: of_instruction_id_write_metadata */
    -1,   /* 409: of_instruction_meter */
    -1,   /* 410: of_instruction_write_actions */
    -1,   /* 411: of_instruction_write_metadata */
    40,   /* 412: of_match_v1 */
    -1,   /* 413: of_match_v2 */
    -1,   /* 414: of_match_v3 */
    -1,   /* 415: of_meter_band */
    -1,   /* 416: of_meter_band_drop */
    -1,   /* 417: of_meter_band_dscp_remark */
    -1,   /* 418: of_meter_band_experimenter */
    -1,   /* 419: of_meter_band_stats */
    -1,   /* 420: of_meter_config */
    -1,   /* 421: of_meter_features */
    -1,   /* 422: of_meter_stats */
    -1,   /* 423: of_oxm */
    -1,   /* 424: of_oxm_arp_op */
    -1,   /* 425: of_oxm_arp_op_masked */
    -1,   /* 426: of_oxm_arp_sha */
    -1,   /* 427: of_oxm_arp_sha_masked */
    -1,   /* 428: of_oxm_arp_spa */
    -1,   /* 429: of_oxm_arp_spa_masked */
    -1,   /* 430: of_oxm_arp_tha */
    -1,   /* 431: of_oxm_arp_tha_masked */
    -1,   /* 432: of_oxm_arp_tpa */
    -1,   /* 433: of_oxm_arp_tpa_masked */
    -1,   /* 434: of_oxm_bsn_egr_port_group_id */
    -1,   /* 435: of_oxm_bsn_egr_port_group_id_masked */
    -1,   /* 436: of_oxm_bsn_global_vrf_allowed */
    -1,   /* 437: of_oxm_bsn_global_vrf_allowed_masked */
    -1,   /* 438: of_oxm_bsn_in_ports_128 */
    -1,   /* 439: of_oxm_bsn_in_ports_128_masked */
    -1,   /* 440: of_oxm_bsn_l2_cache_hit */
    -1,   /* 441: of_oxm_bsn_l2_cache_hit_masked */
    -1,   /* 442: of_oxm_bsn_l3_dst_class_id */
    -1,   /* 443: of_oxm_bsn_l3_dst_class_id_masked */
    -1,   /* 444: of_oxm_bsn_l3_interface_class_id */
    -1,   /* 445: of_oxm_bsn_l3_interface_class_id_masked */
    -1,   /* 446: of_oxm_bsn_l3_src_class_id */
    -1,   /* 447: of_oxm_bsn_l3_src_class_id_masked */
    -1,   /* 448: of_oxm_bsn_lag_id */
    -1,   /* 449: of_oxm_bsn_lag_id_masked */
    -1,   /* 450: of_oxm_bsn_tcp_flags */
    -1,   /* 451: of_oxm_bsn_tcp_flags_masked */
    -1,   /* 452: of_oxm_bsn_udf0 */
    -1,   /* 453: of_oxm_bsn_udf0_masked */
    -1,   /* 454: of_oxm_bsn_udf1 */
    -1,   /* 455: of_oxm_bsn_udf1_masked */
    -1,   /* 456: of_oxm_bsn_udf2 */
    -1,   /* 457: of_oxm_bsn_udf2_masked */
    -1,   /* 458: of_oxm_bsn_udf3 */
    -1,   /* 459: of_oxm_bsn_udf3_masked */
    -1,   /* 460: of_oxm_bsn_udf4 */
    -1,   /* 461: of_oxm_bsn_udf4_masked */
    -1,   /* 462: of_oxm_bsn_udf5 */
    -1,   /* 463: of_oxm_bsn_udf5_masked */
    -1,   /* 464: of_oxm_bsn_udf6 */
    -1,   /* 465: of_oxm_bsn_udf6_masked */
    -1,   /* 466: of_oxm_bsn_udf7 */
    -1,   /* 467: of_oxm_bsn_udf7_masked */
    -1,   /* 468: of_oxm_bsn_vlan_xlate_port_group_id */
    -1,   /* 469: of_oxm_bsn_vlan_xlate_port_group_id_masked */
    -1,   /* 470: of_oxm_bsn_vrf */
    -1,   /* 471: of_oxm_bsn_vrf_masked */
    -1,   /* 472: of_oxm_eth_dst */
    -1,   /* 473: of_oxm_eth_dst_masked */
    -1,   /* 474: of_oxm_eth_src */
    -1,   /* 475: of_oxm_eth_src_masked */
    -1,   /* 476: of_oxm_eth_type */
    -1,   /* 477: of_oxm_eth_type_masked */
    -1,   /* 478: of_oxm_icmpv4_code */
    -1,   /* 479: of_oxm_icmpv4_code_masked */
    -1,   /* 480: of_oxm_icmpv4_type */
    -1,   /* 481: of_oxm_icmpv4_type_masked */
    -1,   /* 482: of_oxm_icmpv6_code */
    -1,   /* 483: of_oxm_icmpv6_code_masked */
    -1,   /* 484: of_oxm_icmpv6_type */
    -1,   /* 485: of_oxm_icmpv6_type_masked */
    -1,   /* 486: of_oxm_in_phy_port */
    -1,   /* 487: of_oxm_in_phy_port_masked */
    -1,   /* 488: of_oxm_in_port */
    -1,   /* 489: of_oxm_in_port_masked */
    -1,   /* 490: of_oxm_ip_dscp */
    -1,   /* 491: of_oxm_ip_dscp_masked */
    -1,   /* 492: of_oxm_ip_ecn */
    -1,   /* 493: of_oxm_ip_ecn_masked */
    -1,   /* 494: of_oxm_ip_proto */
    -1,   /* 495: of_oxm_ip_proto_masked */
    -1,   /* 496: of_oxm_ipv4_dst */
    -1,   /* 497: of_oxm_ipv4_dst_masked */
    -1,   /* 498: of_oxm_ipv4_src */
    -1,   /* 499: of_oxm_ipv4_src_masked */
    -1,   /* 500: of_oxm_ipv6_dst */
    -1,   /* 501: of_oxm_ipv6_dst_masked */
    -1,   /* 502: of_oxm_ipv6_exthdr */
    -1,   /* 503: of_oxm_ipv6_exthdr_masked */
    -1,   /* 504: of_oxm_ipv6_flabel */
    -1,   /* 505: of_oxm_ipv6_flabel_masked */
    -1,   /* 506: of_oxm_ipv6_nd_sll */
    -1,   /* 507: of_oxm_ipv6_nd_sll_masked */
    -1,   /* 508: of_oxm_ipv6_nd_target */
    -1,   /* 509: of_oxm_ipv6_nd_target_masked */
    -1,   /* 510: of_oxm_ipv6_nd_tll */
    -1,   /* 511: of_oxm_ipv6_nd_tll_masked */
    -1,   /* 512: of_oxm_ipv6_src */
    -1,   /* 513: of_oxm_ipv6_src_masked */
    -1,   /* 514: of_oxm_metadata */
    -1,   /* 515: of_oxm_metadata_masked */
    -1,   /* 516: of_oxm_mpls_bos */
    -1,   /* 517: of_oxm_mpls_bos_masked */
    -1,   /* 518: of_oxm_mpls_label */
    -1,   /* 519: of_oxm_mpls_label_masked */
    -1,   /* 520: of_oxm_mpls_tc */
    -1,   /* 521: of_oxm_mpls_tc_masked */
    -1,   /* 522: of_oxm_pbb_uca */
    -1,   /* 523: of_oxm_pbb_uca_masked */
    -1,   /* 524: of_oxm_sctp_dst */
    -1,   /* 525: of_oxm_sctp_dst_masked */
    -1,   /* 526: of_oxm_sctp_src */
    -1,   /* 527: of_oxm_sctp_src_masked */
    -1,   /* 528: of_oxm_tcp_dst */
    -1,   /* 529: of_oxm_tcp_dst_masked */
    -1,   /* 530: of_oxm_tcp_src */
    -1,   /* 531: of_oxm_tcp_src_masked */
    -1,   /* 532: of_oxm_tunnel_id */
    -1,   /* 533: of_oxm_tunnel_id_masked */
    -1,   /* 534: of_oxm_tunnel_ipv4_dst */
    -1,   /* 535: of_oxm_tunnel_ipv4_dst_masked */
    -1,   /* 536: of_oxm_tunnel_ipv4_src */
    -1,   /* 537: of_oxm_tunnel_ipv4_src_masked */
    -1,   /* 538: of_oxm_udp_dst */
    -1,   /* 539: of_oxm_udp_dst_masked */
    -1,   /* 540: of_oxm_udp_src */
    -1,   /* 541: of_oxm_udp_src_masked */
    -1,   /* 542: of_oxm_vlan_pcp */
    -1,   /* 543: of_oxm_vlan_pcp_masked */
    -1,   /* 544: of_oxm_vlan_vid */
    -1,   /* 545: of_oxm_vlan_vid_masked */
    8,    /* 546: of_packet_queue */
    48,   /* 547: of_port_desc */
    -1,   /* 548: of_port_desc_prop */
    -1,   /* 549: of_port_desc_prop_ethernet */
    -1,   /* 550: of_port_desc_prop_experimenter */
    -1,   /* 551: of_port_desc_prop_optical */
    -1,   /* 552: of_port_mod_prop */
    -1,   /* 553: of_port_mod_prop_ethernet */
    -1,   /* 554: of_port_mod_prop_experimenter */
    -1,   /* 555: of_port_mod_prop_optical */
    104,  /* 556: of_port_stats_entry */
    -1,   /* 557: of_port_stats_prop */
    -1,   /* 558: of_port_stats_prop_ethernet */
    -1,   /* 559: of_port_stats_prop_experimenter */
    -1,   /* 560: of_port_stats_prop_optical */
    -1,   /* 561: of_queue_desc */
    -1,   /* 562: of_queue_desc_prop */
    -1,   /* 563: of_queue_desc_prop_experimenter */
    -1,   /* 564: of_queue_desc_prop_max_rate */
    -1,   /* 565: of_queue_desc_prop_min_rate */
    8,    /* 566: of_queue_prop */
    -1,   /* 567: of_queue_prop_experimenter */
    -1,   /* 568: of_queue_prop_max_rate */
    16,   /* 569: of_queue_prop_min_rate */
    32,   /* 570: of_queue_stats_entry */
    -1,   /* 571: of_queue_stats_prop */
    -1,   /* 572: of_queue_stats_prop_experimenter */
    -1,   /* 573: of_role_prop */
    -1,   /* 574: of_role_prop_experimenter */
    -1,   /* 575: of_table_desc */
    -1,   /* 576: of_table_feature_prop */
    -1,   /* 577: of_table_feature_prop_apply_actions */
    -1,   /* 578: of_table_feature_prop_apply_actions_miss */
    -1,   /* 579: of_table_feature_prop_apply_setfield */
    -1,   /* 580: of_table_feature_prop_apply_setfield_miss */
    -1,   /* 581: of_table_feature_prop_experimenter */
    -1,   /* 582: of_table_feature_prop_experimenter_miss */
    -1,   /* 583: of_table_feature_prop_instructions */
    -1,   /* 584: of_table_feature_prop_instructions_miss */
    -1,   /* 585: of_table_feature_prop_match */
    -1,   /* 586: of_table_feature_prop_next_tables */
    -1,   /* 587: of_table_feature_prop_next_tables_miss */
    -1,   /* 588: of_table_feature_prop_table_sync_from */
    -1,   /* 589: of_table_feature_prop_wildcards */
    -1,   /* 590: of_table_feature_prop_write_actions */
    -1,   /* 591: of_table_feature_prop_write_actions_miss */
    -1,   /* 592: of_table_feature_prop_write_setfield */
    -1,   /* 593: of_table_feature_prop_write_setfield_miss */
    -1,   /* 594: of_table_features */
    -1,   /* 595: of_table_mod_prop */
    -1,   /* 596: of_table_mod_prop_eviction */
    -1,   /* 597: of_table_mod_prop_experimenter */
    -1,   /* 598: of_table_mod_prop_vacancy */
    64,   /* 599: of_table_stats_entry */
    -1,   /* 600: of_uint32 */
    -1,   /* 601: of_uint64 */
    -1,   /* 602: of_uint8 */
    0,    /* 603: of_list_action */
    -1,   /* 604: of_list_action_id */
    -1,   /* 605: of_list_async_config_prop */
    -1,   /* 606: of_list_bsn_controller_connection */
    -1,   /* 607: of_list_bsn_debug_counter_desc_stats_entry */
    -1,   /* 608: of_list_bsn_debug_counter_stats_entry */
    -1,   /* 609: of_list_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 610: of_list_bsn_generic_stats_entry */
    -1,   /* 611: of_list_bsn_gentable_bucket_stats_entry */
    -1,   /* 612: of_list_bsn_gentable_desc_stats_entry */
    -1,   /* 613: of_list_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 614: of_list_bsn_gentable_entry_stats_entry */
    -1,   /* 615: of_list_bsn_gentable_stats_entry */
    0,    /* 616: of_list_bsn_interface */
    -1,   /* 617: of_list_bsn_lacp_stats_entry */
    -1,   /* 618: of_list_bsn_port_counter_stats_entry */
    -1,   /* 619: of_list_bsn_switch_pipeline_stats_entry */
    -1,   /* 620: of_list_bsn_table_checksum_stats_entry */
    -1,   /* 621: of_list_bsn_tlv */
    -1,   /* 622: of_list_bsn_vlan_counter_stats_entry */
    -1,   /* 623: of_list_bsn_vrf_counter_stats_entry */
    -1,   /* 624: of_list_bucket */
    -1,   /* 625: of_list_bucket_counter */
    -1,   /* 626: of_list_bundle_prop */
    0,    /* 627: of_list_flow_stats_entry */
    -1,   /* 628: of_list_group_desc_stats_entry */
    -1,   /* 629: of_list_group_stats_entry */
    -1,   /* 630: of_list_hello_elem */
    -1,   /* 631: of_list_instruction */
    -1,   /* 632: of_list_instruction_id */
    -1,   /* 633: of_list_meter_band */
    -1,   /* 634: of_list_meter_band_stats */
    -1,   /* 635: of_list_meter_stats */
    -1,   /* 636: of_list_oxm */
    0,    /* 637: of_list_packet_queue */
    0,    /* 638: of_list_port_desc */
    -1,   /* 639: of_list_port_desc_prop */
    -1,   /* 640: of_list_port_mod_prop */
    0,    /* 641: of_list_port_stats_entry */
    -1,   /* 642: of_list_port_stats_prop */
    -1,   /* 643: of_list_queue_desc */
    -1,   /* 644: of_list_queue_desc_prop */
    0,    /* 645: of_list_queue_prop */
    0,    /* 646: of_list_queue_stats_entry */
    -1,   /* 647: of_list_queue_stats_prop */
    -1,   /* 648: of_list_role_prop */
    -1,   /* 649: of_list_table_desc */
    -1,   /* 650: of_list_table_feature_prop */
    -1,   /* 651: of_list_table_features */
    -1,   /* 652: of_list_table_mod_prop */
    0,    /* 653: of_list_table_stats_entry */
    -1,   /* 654: of_list_uint32 */
    -1,   /* 655: of_list_uint64 */
    -1    /* 656: of_list_uint8 */
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
    -1,   /* 34: of_bsn_generic_stats_reply */
    -1,   /* 35: of_bsn_generic_stats_request */
    -1,   /* 36: of_bsn_gentable_bucket_stats_reply */
    -1,   /* 37: of_bsn_gentable_bucket_stats_request */
    -1,   /* 38: of_bsn_gentable_clear_reply */
    -1,   /* 39: of_bsn_gentable_clear_request */
    -1,   /* 40: of_bsn_gentable_desc_stats_reply */
    -1,   /* 41: of_bsn_gentable_desc_stats_request */
    -1,   /* 42: of_bsn_gentable_entry_add */
    -1,   /* 43: of_bsn_gentable_entry_delete */
    -1,   /* 44: of_bsn_gentable_entry_desc_stats_reply */
    -1,   /* 45: of_bsn_gentable_entry_desc_stats_request */
    -1,   /* 46: of_bsn_gentable_entry_stats_reply */
    -1,   /* 47: of_bsn_gentable_entry_stats_request */
    -1,   /* 48: of_bsn_gentable_set_buckets_size */
    -1,   /* 49: of_bsn_gentable_stats_reply */
    -1,   /* 50: of_bsn_gentable_stats_request */
    16,   /* 51: of_bsn_get_interfaces_reply */
    16,   /* 52: of_bsn_get_interfaces_request */
    -1,   /* 53: of_bsn_get_ip_mask_reply */
    -1,   /* 54: of_bsn_get_ip_mask_request */
    -1,   /* 55: of_bsn_get_l2_table_reply */
    -1,   /* 56: of_bsn_get_l2_table_request */
    20,   /* 57: of_bsn_get_mirroring_reply */
    20,   /* 58: of_bsn_get_mirroring_request */
    -1,   /* 59: of_bsn_get_switch_pipeline_reply */
    -1,   /* 60: of_bsn_get_switch_pipeline_request */
    16,   /* 61: of_bsn_header */
    -1,   /* 62: of_bsn_hybrid_get_reply */
    -1,   /* 63: of_bsn_hybrid_get_request */
    -1,   /* 64: of_bsn_image_desc_stats_reply */
    -1,   /* 65: of_bsn_image_desc_stats_request */
    -1,   /* 66: of_bsn_lacp_convergence_notif */
    -1,   /* 67: of_bsn_lacp_stats_reply */
    -1,   /* 68: of_bsn_lacp_stats_request */
    -1,   /* 69: of_bsn_log */
    25,   /* 70: of_bsn_pdu_rx_reply */
    28,   /* 71: of_bsn_pdu_rx_request */
    21,   /* 72: of_bsn_pdu_rx_timeout */
    25,   /* 73: of_bsn_pdu_tx_reply */
    28,   /* 74: of_bsn_pdu_tx_request */
    -1,   /* 75: of_bsn_port_counter_stats_reply */
    -1,   /* 76: of_bsn_port_counter_stats_request */
    -1,   /* 77: of_bsn_role_status */
    -1,   /* 78: of_bsn_set_aux_cxns_reply */
    -1,   /* 79: of_bsn_set_aux_cxns_request */
    -1,   /* 80: of_bsn_set_ip_mask */
    -1,   /* 81: of_bsn_set_l2_table_reply */
    -1,   /* 82: of_bsn_set_l2_table_request */
    -1,   /* 83: of_bsn_set_lacp_reply */
    -1,   /* 84: of_bsn_set_lacp_request */
    20,   /* 85: of_bsn_set_mirroring */
    20,   /* 86: of_bsn_set_pktin_suppression_reply */
    32,   /* 87: of_bsn_set_pktin_suppression_request */
    -1,   /* 88: of_bsn_set_switch_pipeline_reply */
    -1,   /* 89: of_bsn_set_switch_pipeline_request */
    -1,   /* 90: of_bsn_shell_command */
    -1,   /* 91: of_bsn_shell_output */
    -1,   /* 92: of_bsn_shell_status */
    24,   /* 93: of_bsn_stats_reply */
    24,   /* 94: of_bsn_stats_request */
    -1,   /* 95: of_bsn_switch_pipeline_stats_reply */
    -1,   /* 96: of_bsn_switch_pipeline_stats_request */
    -1,   /* 97: of_bsn_table_checksum_stats_reply */
    -1,   /* 98: of_bsn_table_checksum_stats_request */
    -1,   /* 99: of_bsn_table_set_buckets_size */
    -1,   /* 100: of_bsn_time_reply */
    -1,   /* 101: of_bsn_time_request */
    24,   /* 102: of_bsn_virtual_port_create_reply */
    20,   /* 103: of_bsn_virtual_port_create_request */
    20,   /* 104: of_bsn_virtual_port_remove_reply */
    20,   /* 105: of_bsn_virtual_port_remove_request */
    -1,   /* 106: of_bsn_vlan_counter_stats_reply */
    -1,   /* 107: of_bsn_vlan_counter_stats_request */
    -1,   /* 108: of_bsn_vrf_counter_stats_reply */
    -1,   /* 109: of_bsn_vrf_counter_stats_request */
    -1,   /* 110: of_bundle_add_msg */
    -1,   /* 111: of_bundle_ctrl_msg */
    -1,   /* 112: of_bundle_failed_error_msg */
    1072, /* 113: of_desc_stats_reply */
    16,   /* 114: of_desc_stats_request */
    8,    /* 115: of_echo_reply */
    8,    /* 116: of_echo_request */
    10,   /* 117: of_error_msg */
    12,   /* 118: of_experimenter */
    -1,   /* 119: of_experimenter_error_msg */
    24,   /* 120: of_experimenter_stats_reply */
    24,   /* 121: of_experimenter_stats_request */
    32,   /* 122: of_features_reply */
    8,    /* 123: of_features_request */
    136,  /* 124: of_flow_add */
    136,  /* 125: of_flow_delete */
    136,  /* 126: of_flow_delete_strict */
    136,  /* 127: of_flow_mod */
    12,   /* 128: of_flow_mod_failed_error_msg */
    136,  /* 129: of_flow_modify */
    136,  /* 130: of_flow_modify_strict */
    -1,   /* 131: of_flow_monitor_failed_error_msg */
    136,  /* 132: of_flow_removed */
    16,   /* 133: of_flow_stats_reply */
    136,  /* 134: of_flow_stats_request */
    12,   /* 135: of_get_config_reply */
    8,    /* 136: of_get_config_request */
    16,   /* 137: of_group_add */
    16,   /* 138: of_group_delete */
    16,   /* 139: of_group_desc_stats_reply */
    16,   /* 140: of_group_desc_stats_request */
    -1,   /* 141: of_group_features_stats_reply */
    -1,   /* 142: of_group_features_stats_request */
    16,   /* 143: of_group_mod */
    12,   /* 144: of_group_mod_failed_error_msg */
    16,   /* 145: of_group_modify */
    16,   /* 146: of_group_stats_reply */
    24,   /* 147: of_group_stats_request */
    8,    /* 148: of_header */
    8,    /* 149: of_hello */
    12,   /* 150: of_hello_failed_error_msg */
    -1,   /* 151: of_meter_config_stats_reply */
    -1,   /* 152: of_meter_config_stats_request */
    -1,   /* 153: of_meter_features_stats_reply */
    -1,   /* 154: of_meter_features_stats_request */
    -1,   /* 155: of_meter_mod */
    -1,   /* 156: of_meter_mod_failed_error_msg */
    -1,   /* 157: of_meter_stats_reply */
    -1,   /* 158: of_meter_stats_request */
    -1,   /* 159: of_nicira_controller_role_reply */
    -1,   /* 160: of_nicira_controller_role_request */
    16,   /* 161: of_nicira_header */
    24,   /* 162: of_packet_in */
    24,   /* 163: of_packet_out */
    -1,   /* 164: of_port_desc_stats_reply */
    -1,   /* 165: of_port_desc_stats_request */
    40,   /* 166: of_port_mod */
    12,   /* 167: of_port_mod_failed_error_msg */
    16,   /* 168: of_port_stats_reply */
    24,   /* 169: of_port_stats_request */
    80,   /* 170: of_port_status */
    -1,   /* 171: of_queue_desc_stats_reply */
    -1,   /* 172: of_queue_desc_stats_request */
    16,   /* 173: of_queue_get_config_reply */
    16,   /* 174: of_queue_get_config_request */
    12,   /* 175: of_queue_op_failed_error_msg */
    16,   /* 176: of_queue_stats_reply */
    24,   /* 177: of_queue_stats_request */
    -1,   /* 178: of_requestforward */
    -1,   /* 179: of_role_reply */
    -1,   /* 180: of_role_request */
    -1,   /* 181: of_role_request_failed_error_msg */
    -1,   /* 182: of_role_status */
    12,   /* 183: of_set_config */
    16,   /* 184: of_stats_reply */
    16,   /* 185: of_stats_request */
    12,   /* 186: of_switch_config_failed_error_msg */
    -1,   /* 187: of_table_desc_stats_reply */
    -1,   /* 188: of_table_desc_stats_request */
    -1,   /* 189: of_table_features_failed_error_msg */
    -1,   /* 190: of_table_features_stats_reply */
    -1,   /* 191: of_table_features_stats_request */
    16,   /* 192: of_table_mod */
    12,   /* 193: of_table_mod_failed_error_msg */
    16,   /* 194: of_table_stats_reply */
    16,   /* 195: of_table_stats_request */
    -1,   /* 196: of_table_status */
    8,    /* 197: of_action */
    16,   /* 198: of_action_bsn */
    28,   /* 199: of_action_bsn_checksum */
    -1,   /* 200: of_action_bsn_gentable */
    24,   /* 201: of_action_bsn_mirror */
    16,   /* 202: of_action_bsn_set_tunnel_dst */
    8,    /* 203: of_action_copy_ttl_in */
    8,    /* 204: of_action_copy_ttl_out */
    8,    /* 205: of_action_dec_mpls_ttl */
    8,    /* 206: of_action_dec_nw_ttl */
    -1,   /* 207: of_action_enqueue */
    8,    /* 208: of_action_experimenter */
    8,    /* 209: of_action_group */
    -1,   /* 210: of_action_id */
    -1,   /* 211: of_action_id_bsn */
    -1,   /* 212: of_action_id_bsn_checksum */
    -1,   /* 213: of_action_id_bsn_gentable */
    -1,   /* 214: of_action_id_bsn_mirror */
    -1,   /* 215: of_action_id_bsn_set_tunnel_dst */
    -1,   /* 216: of_action_id_copy_ttl_in */
    -1,   /* 217: of_action_id_copy_ttl_out */
    -1,   /* 218: of_action_id_dec_mpls_ttl */
    -1,   /* 219: of_action_id_dec_nw_ttl */
    -1,   /* 220: of_action_id_experimenter */
    -1,   /* 221: of_action_id_group */
    -1,   /* 222: of_action_id_nicira */
    -1,   /* 223: of_action_id_nicira_dec_ttl */
    -1,   /* 224: of_action_id_output */
    -1,   /* 225: of_action_id_pop_mpls */
    -1,   /* 226: of_action_id_pop_pbb */
    -1,   /* 227: of_action_id_pop_vlan */
    -1,   /* 228: of_action_id_push_mpls */
    -1,   /* 229: of_action_id_push_pbb */
    -1,   /* 230: of_action_id_push_vlan */
    -1,   /* 231: of_action_id_set_field */
    -1,   /* 232: of_action_id_set_mpls_ttl */
    -1,   /* 233: of_action_id_set_nw_ttl */
    -1,   /* 234: of_action_id_set_queue */
    16,   /* 235: of_action_nicira */
    16,   /* 236: of_action_nicira_dec_ttl */
    16,   /* 237: of_action_output */
    8,    /* 238: of_action_pop_mpls */
    -1,   /* 239: of_action_pop_pbb */
    8,    /* 240: of_action_pop_vlan */
    8,    /* 241: of_action_push_mpls */
    -1,   /* 242: of_action_push_pbb */
    8,    /* 243: of_action_push_vlan */
    16,   /* 244: of_action_set_dl_dst */
    16,   /* 245: of_action_set_dl_src */
    -1,   /* 246: of_action_set_field */
    8,    /* 247: of_action_set_mpls_label */
    8,    /* 248: of_action_set_mpls_tc */
    8,    /* 249: of_action_set_mpls_ttl */
    8,    /* 250: of_action_set_nw_dst */
    8,    /* 251: of_action_set_nw_ecn */
    8,    /* 252: of_action_set_nw_src */
    8,    /* 253: of_action_set_nw_tos */
    8,    /* 254: of_action_set_nw_ttl */
    8,    /* 255: of_action_set_queue */
    8,    /* 256: of_action_set_tp_dst */
    8,    /* 257: of_action_set_tp_src */
    8,    /* 258: of_action_set_vlan_pcp */
    8,    /* 259: of_action_set_vlan_vid */
    -1,   /* 260: of_action_strip_vlan */
    -1,   /* 261: of_async_config_prop */
    -1,   /* 262: of_async_config_prop_experimenter_master */
    -1,   /* 263: of_async_config_prop_experimenter_slave */
    -1,   /* 264: of_async_config_prop_flow_removed_master */
    -1,   /* 265: of_async_config_prop_flow_removed_slave */
    -1,   /* 266: of_async_config_prop_packet_in_master */
    -1,   /* 267: of_async_config_prop_packet_in_slave */
    -1,   /* 268: of_async_config_prop_port_status_master */
    -1,   /* 269: of_async_config_prop_port_status_slave */
    -1,   /* 270: of_async_config_prop_requestforward_master */
    -1,   /* 271: of_async_config_prop_requestforward_slave */
    -1,   /* 272: of_async_config_prop_role_status_master */
    -1,   /* 273: of_async_config_prop_role_status_slave */
    -1,   /* 274: of_async_config_prop_table_status_master */
    -1,   /* 275: of_async_config_prop_table_status_slave */
    -1,   /* 276: of_bsn_controller_connection */
    -1,   /* 277: of_bsn_debug_counter_desc_stats_entry */
    -1,   /* 278: of_bsn_debug_counter_stats_entry */
    -1,   /* 279: of_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 280: of_bsn_generic_stats_entry */
    -1,   /* 281: of_bsn_gentable_bucket_stats_entry */
    -1,   /* 282: of_bsn_gentable_desc_stats_entry */
    -1,   /* 283: of_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 284: of_bsn_gentable_entry_stats_entry */
    -1,   /* 285: of_bsn_gentable_stats_entry */
    32,   /* 286: of_bsn_interface */
    -1,   /* 287: of_bsn_lacp_stats_entry */
    -1,   /* 288: of_bsn_port_counter_stats_entry */
    -1,   /* 289: of_bsn_switch_pipeline_stats_entry */
    -1,   /* 290: of_bsn_table_checksum_stats_entry */
    -1,   /* 291: of_bsn_tlv */
    -1,   /* 292: of_bsn_tlv_actor_key */
    -1,   /* 293: of_bsn_tlv_actor_port_num */
    -1,   /* 294: of_bsn_tlv_actor_port_priority */
    -1,   /* 295: of_bsn_tlv_actor_state */
    -1,   /* 296: of_bsn_tlv_actor_system_mac */
    -1,   /* 297: of_bsn_tlv_actor_system_priority */
    -1,   /* 298: of_bsn_tlv_broadcast_query_timeout */
    -1,   /* 299: of_bsn_tlv_bucket */
    -1,   /* 300: of_bsn_tlv_circuit_id */
    -1,   /* 301: of_bsn_tlv_convergence_status */
    -1,   /* 302: of_bsn_tlv_crc_enabled */
    -1,   /* 303: of_bsn_tlv_data */
    -1,   /* 304: of_bsn_tlv_eth_dst */
    -1,   /* 305: of_bsn_tlv_eth_src */
    -1,   /* 306: of_bsn_tlv_external_gateway_ip */
    -1,   /* 307: of_bsn_tlv_external_gateway_mac */
    -1,   /* 308: of_bsn_tlv_external_ip */
    -1,   /* 309: of_bsn_tlv_external_mac */
    -1,   /* 310: of_bsn_tlv_external_netmask */
    -1,   /* 311: of_bsn_tlv_header_size */
    -1,   /* 312: of_bsn_tlv_idle_notification */
    -1,   /* 313: of_bsn_tlv_idle_time */
    -1,   /* 314: of_bsn_tlv_idle_timeout */
    -1,   /* 315: of_bsn_tlv_internal_gateway_mac */
    -1,   /* 316: of_bsn_tlv_internal_mac */
    -1,   /* 317: of_bsn_tlv_interval */
    -1,   /* 318: of_bsn_tlv_ipv4 */
    -1,   /* 319: of_bsn_tlv_ipv4_dst */
    -1,   /* 320: of_bsn_tlv_ipv4_netmask */
    -1,   /* 321: of_bsn_tlv_ipv4_src */
    -1,   /* 322: of_bsn_tlv_mac */
    -1,   /* 323: of_bsn_tlv_mac_mask */
    -1,   /* 324: of_bsn_tlv_miss_packets */
    -1,   /* 325: of_bsn_tlv_mpls_control_word */
    -1,   /* 326: of_bsn_tlv_mpls_label */
    -1,   /* 327: of_bsn_tlv_mpls_sequenced */
    -1,   /* 328: of_bsn_tlv_name */
    -1,   /* 329: of_bsn_tlv_partner_key */
    -1,   /* 330: of_bsn_tlv_partner_port_num */
    -1,   /* 331: of_bsn_tlv_partner_port_priority */
    -1,   /* 332: of_bsn_tlv_partner_state */
    -1,   /* 333: of_bsn_tlv_partner_system_mac */
    -1,   /* 334: of_bsn_tlv_partner_system_priority */
    -1,   /* 335: of_bsn_tlv_port */
    -1,   /* 336: of_bsn_tlv_priority */
    -1,   /* 337: of_bsn_tlv_queue_id */
    -1,   /* 338: of_bsn_tlv_queue_weight */
    -1,   /* 339: of_bsn_tlv_reference */
    -1,   /* 340: of_bsn_tlv_reply_packets */
    -1,   /* 341: of_bsn_tlv_request_packets */
    -1,   /* 342: of_bsn_tlv_rx_packets */
    -1,   /* 343: of_bsn_tlv_sampling_rate */
    -1,   /* 344: of_bsn_tlv_sub_agent_id */
    -1,   /* 345: of_bsn_tlv_tx_bytes */
    -1,   /* 346: of_bsn_tlv_tx_packets */
    -1,   /* 347: of_bsn_tlv_udf_anchor */
    -1,   /* 348: of_bsn_tlv_udf_id */
    -1,   /* 349: of_bsn_tlv_udf_length */
    -1,   /* 350: of_bsn_tlv_udf_offset */
    -1,   /* 351: of_bsn_tlv_udp_dst */
    -1,   /* 352: of_bsn_tlv_udp_src */
    -1,   /* 353: of_bsn_tlv_unicast_query_timeout */
    -1,   /* 354: of_bsn_tlv_vlan_vid */
    -1,   /* 355: of_bsn_tlv_vrf */
    -1,   /* 356: of_bsn_vlan_counter_stats_entry */
    4,    /* 357: of_bsn_vport */
    64,   /* 358: of_bsn_vport_l2gre */
    32,   /* 359: of_bsn_vport_q_in_q */
    -1,   /* 360: of_bsn_vrf_counter_stats_entry */
    16,   /* 361: of_bucket */
    16,   /* 362: of_bucket_counter */
    -1,   /* 363: of_bundle_prop */
    -1,   /* 364: of_bundle_prop_experimenter */
    136,  /* 365: of_flow_stats_entry */
    8,    /* 366: of_group_desc_stats_entry */
    32,   /* 367: of_group_stats_entry */
    -1,   /* 368: of_hello_elem */
    -1,   /* 369: of_hello_elem_versionbitmap */
    8,    /* 370: of_instruction */
    8,    /* 371: of_instruction_apply_actions */
    -1,   /* 372: of_instruction_bsn */
    -1,   /* 373: of_instruction_bsn_arp_offload */
    -1,   /* 374: of_instruction_bsn_auto_negotiation */
    -1,   /* 375: of_instruction_bsn_deny */
    -1,   /* 376: of_instruction_bsn_dhcp_offload */
    -1,   /* 377: of_instruction_bsn_disable_split_horizon_check */
    -1,   /* 378: of_instruction_bsn_disable_src_mac_check */
    -1,   /* 379: of_instruction_bsn_disable_vlan_counters */
    -1,   /* 380: of_instruction_bsn_packet_of_death */
    -1,   /* 381: of_instruction_bsn_permit */
    -1,   /* 382: of_instruction_bsn_prioritize_pdus */
    -1,   /* 383: of_instruction_bsn_require_vlan_xlate */
    -1,   /* 384: of_instruction_bsn_span_destination */
    8,    /* 385: of_instruction_clear_actions */
    8,    /* 386: of_instruction_experimenter */
    8,    /* 387: of_instruction_goto_table */
    -1,   /* 388: of_instruction_id */
    -1,   /* 389: of_instruction_id_apply_actions */
    -1,   /* 390: of_instruction_id_bsn */
    -1,   /* 391: of_instruction_id_bsn_arp_offload */
    -1,   /* 392: of_instruction_id_bsn_auto_negotiation */
    -1,   /* 393: of_instruction_id_bsn_deny */
    -1,   /* 394: of_instruction_id_bsn_dhcp_offload */
    -1,   /* 395: of_instruction_id_bsn_disable_split_horizon_check */
    -1,   /* 396: of_instruction_id_bsn_disable_src_mac_check */
    -1,   /* 397: of_instruction_id_bsn_disable_vlan_counters */
    -1,   /* 398: of_instruction_id_bsn_packet_of_death */
    -1,   /* 399: of_instruction_id_bsn_permit */
    -1,   /* 400: of_instruction_id_bsn_prioritize_pdus */
    -1,   /* 401: of_instruction_id_bsn_require_vlan_xlate */
    -1,   /* 402: of_instruction_id_bsn_span_destination */
    -1,   /* 403: of_instruction_id_clear_actions */
    -1,   /* 404: of_instruction_id_experimenter */
    -1,   /* 405: of_instruction_id_goto_table */
    -1,   /* 406: of_instruction_id_meter */
    -1,   /* 407: of_instruction_id_write_actions */
    -1,   /* 408: of_instruction_id_write_metadata */
    -1,   /* 409: of_instruction_meter */
    8,    /* 410: of_instruction_write_actions */
    24,   /* 411: of_instruction_write_metadata */
    -1,   /* 412: of_match_v1 */
    88,   /* 413: of_match_v2 */
    -1,   /* 414: of_match_v3 */
    -1,   /* 415: of_meter_band */
    -1,   /* 416: of_meter_band_drop */
    -1,   /* 417: of_meter_band_dscp_remark */
    -1,   /* 418: of_meter_band_experimenter */
    -1,   /* 419: of_meter_band_stats */
    -1,   /* 420: of_meter_config */
    -1,   /* 421: of_meter_features */
    -1,   /* 422: of_meter_stats */
    -1,   /* 423: of_oxm */
    -1,   /* 424: of_oxm_arp_op */
    -1,   /* 425: of_oxm_arp_op_masked */
    -1,   /* 426: of_oxm_arp_sha */
    -1,   /* 427: of_oxm_arp_sha_masked */
    -1,   /* 428: of_oxm_arp_spa */
    -1,   /* 429: of_oxm_arp_spa_masked */
    -1,   /* 430: of_oxm_arp_tha */
    -1,   /* 431: of_oxm_arp_tha_masked */
    -1,   /* 432: of_oxm_arp_tpa */
    -1,   /* 433: of_oxm_arp_tpa_masked */
    -1,   /* 434: of_oxm_bsn_egr_port_group_id */
    -1,   /* 435: of_oxm_bsn_egr_port_group_id_masked */
    -1,   /* 436: of_oxm_bsn_global_vrf_allowed */
    -1,   /* 437: of_oxm_bsn_global_vrf_allowed_masked */
    -1,   /* 438: of_oxm_bsn_in_ports_128 */
    -1,   /* 439: of_oxm_bsn_in_ports_128_masked */
    -1,   /* 440: of_oxm_bsn_l2_cache_hit */
    -1,   /* 441: of_oxm_bsn_l2_cache_hit_masked */
    -1,   /* 442: of_oxm_bsn_l3_dst_class_id */
    -1,   /* 443: of_oxm_bsn_l3_dst_class_id_masked */
    -1,   /* 444: of_oxm_bsn_l3_interface_class_id */
    -1,   /* 445: of_oxm_bsn_l3_interface_class_id_masked */
    -1,   /* 446: of_oxm_bsn_l3_src_class_id */
    -1,   /* 447: of_oxm_bsn_l3_src_class_id_masked */
    -1,   /* 448: of_oxm_bsn_lag_id */
    -1,   /* 449: of_oxm_bsn_lag_id_masked */
    -1,   /* 450: of_oxm_bsn_tcp_flags */
    -1,   /* 451: of_oxm_bsn_tcp_flags_masked */
    -1,   /* 452: of_oxm_bsn_udf0 */
    -1,   /* 453: of_oxm_bsn_udf0_masked */
    -1,   /* 454: of_oxm_bsn_udf1 */
    -1,   /* 455: of_oxm_bsn_udf1_masked */
    -1,   /* 456: of_oxm_bsn_udf2 */
    -1,   /* 457: of_oxm_bsn_udf2_masked */
    -1,   /* 458: of_oxm_bsn_udf3 */
    -1,   /* 459: of_oxm_bsn_udf3_masked */
    -1,   /* 460: of_oxm_bsn_udf4 */
    -1,   /* 461: of_oxm_bsn_udf4_masked */
    -1,   /* 462: of_oxm_bsn_udf5 */
    -1,   /* 463: of_oxm_bsn_udf5_masked */
    -1,   /* 464: of_oxm_bsn_udf6 */
    -1,   /* 465: of_oxm_bsn_udf6_masked */
    -1,   /* 466: of_oxm_bsn_udf7 */
    -1,   /* 467: of_oxm_bsn_udf7_masked */
    -1,   /* 468: of_oxm_bsn_vlan_xlate_port_group_id */
    -1,   /* 469: of_oxm_bsn_vlan_xlate_port_group_id_masked */
    -1,   /* 470: of_oxm_bsn_vrf */
    -1,   /* 471: of_oxm_bsn_vrf_masked */
    -1,   /* 472: of_oxm_eth_dst */
    -1,   /* 473: of_oxm_eth_dst_masked */
    -1,   /* 474: of_oxm_eth_src */
    -1,   /* 475: of_oxm_eth_src_masked */
    -1,   /* 476: of_oxm_eth_type */
    -1,   /* 477: of_oxm_eth_type_masked */
    -1,   /* 478: of_oxm_icmpv4_code */
    -1,   /* 479: of_oxm_icmpv4_code_masked */
    -1,   /* 480: of_oxm_icmpv4_type */
    -1,   /* 481: of_oxm_icmpv4_type_masked */
    -1,   /* 482: of_oxm_icmpv6_code */
    -1,   /* 483: of_oxm_icmpv6_code_masked */
    -1,   /* 484: of_oxm_icmpv6_type */
    -1,   /* 485: of_oxm_icmpv6_type_masked */
    -1,   /* 486: of_oxm_in_phy_port */
    -1,   /* 487: of_oxm_in_phy_port_masked */
    -1,   /* 488: of_oxm_in_port */
    -1,   /* 489: of_oxm_in_port_masked */
    -1,   /* 490: of_oxm_ip_dscp */
    -1,   /* 491: of_oxm_ip_dscp_masked */
    -1,   /* 492: of_oxm_ip_ecn */
    -1,   /* 493: of_oxm_ip_ecn_masked */
    -1,   /* 494: of_oxm_ip_proto */
    -1,   /* 495: of_oxm_ip_proto_masked */
    -1,   /* 496: of_oxm_ipv4_dst */
    -1,   /* 497: of_oxm_ipv4_dst_masked */
    -1,   /* 498: of_oxm_ipv4_src */
    -1,   /* 499: of_oxm_ipv4_src_masked */
    -1,   /* 500: of_oxm_ipv6_dst */
    -1,   /* 501: of_oxm_ipv6_dst_masked */
    -1,   /* 502: of_oxm_ipv6_exthdr */
    -1,   /* 503: of_oxm_ipv6_exthdr_masked */
    -1,   /* 504: of_oxm_ipv6_flabel */
    -1,   /* 505: of_oxm_ipv6_flabel_masked */
    -1,   /* 506: of_oxm_ipv6_nd_sll */
    -1,   /* 507: of_oxm_ipv6_nd_sll_masked */
    -1,   /* 508: of_oxm_ipv6_nd_target */
    -1,   /* 509: of_oxm_ipv6_nd_target_masked */
    -1,   /* 510: of_oxm_ipv6_nd_tll */
    -1,   /* 511: of_oxm_ipv6_nd_tll_masked */
    -1,   /* 512: of_oxm_ipv6_src */
    -1,   /* 513: of_oxm_ipv6_src_masked */
    -1,   /* 514: of_oxm_metadata */
    -1,   /* 515: of_oxm_metadata_masked */
    -1,   /* 516: of_oxm_mpls_bos */
    -1,   /* 517: of_oxm_mpls_bos_masked */
    -1,   /* 518: of_oxm_mpls_label */
    -1,   /* 519: of_oxm_mpls_label_masked */
    -1,   /* 520: of_oxm_mpls_tc */
    -1,   /* 521: of_oxm_mpls_tc_masked */
    -1,   /* 522: of_oxm_pbb_uca */
    -1,   /* 523: of_oxm_pbb_uca_masked */
    -1,   /* 524: of_oxm_sctp_dst */
    -1,   /* 525: of_oxm_sctp_dst_masked */
    -1,   /* 526: of_oxm_sctp_src */
    -1,   /* 527: of_oxm_sctp_src_masked */
    -1,   /* 528: of_oxm_tcp_dst */
    -1,   /* 529: of_oxm_tcp_dst_masked */
    -1,   /* 530: of_oxm_tcp_src */
    -1,   /* 531: of_oxm_tcp_src_masked */
    -1,   /* 532: of_oxm_tunnel_id */
    -1,   /* 533: of_oxm_tunnel_id_masked */
    -1,   /* 534: of_oxm_tunnel_ipv4_dst */
    -1,   /* 535: of_oxm_tunnel_ipv4_dst_masked */
    -1,   /* 536: of_oxm_tunnel_ipv4_src */
    -1,   /* 537: of_oxm_tunnel_ipv4_src_masked */
    -1,   /* 538: of_oxm_udp_dst */
    -1,   /* 539: of_oxm_udp_dst_masked */
    -1,   /* 540: of_oxm_udp_src */
    -1,   /* 541: of_oxm_udp_src_masked */
    -1,   /* 542: of_oxm_vlan_pcp */
    -1,   /* 543: of_oxm_vlan_pcp_masked */
    -1,   /* 544: of_oxm_vlan_vid */
    -1,   /* 545: of_oxm_vlan_vid_masked */
    8,    /* 546: of_packet_queue */
    64,   /* 547: of_port_desc */
    -1,   /* 548: of_port_desc_prop */
    -1,   /* 549: of_port_desc_prop_ethernet */
    -1,   /* 550: of_port_desc_prop_experimenter */
    -1,   /* 551: of_port_desc_prop_optical */
    -1,   /* 552: of_port_mod_prop */
    -1,   /* 553: of_port_mod_prop_ethernet */
    -1,   /* 554: of_port_mod_prop_experimenter */
    -1,   /* 555: of_port_mod_prop_optical */
    104,  /* 556: of_port_stats_entry */
    -1,   /* 557: of_port_stats_prop */
    -1,   /* 558: of_port_stats_prop_ethernet */
    -1,   /* 559: of_port_stats_prop_experimenter */
    -1,   /* 560: of_port_stats_prop_optical */
    -1,   /* 561: of_queue_desc */
    -1,   /* 562: of_queue_desc_prop */
    -1,   /* 563: of_queue_desc_prop_experimenter */
    -1,   /* 564: of_queue_desc_prop_max_rate */
    -1,   /* 565: of_queue_desc_prop_min_rate */
    8,    /* 566: of_queue_prop */
    -1,   /* 567: of_queue_prop_experimenter */
    -1,   /* 568: of_queue_prop_max_rate */
    16,   /* 569: of_queue_prop_min_rate */
    32,   /* 570: of_queue_stats_entry */
    -1,   /* 571: of_queue_stats_prop */
    -1,   /* 572: of_queue_stats_prop_experimenter */
    -1,   /* 573: of_role_prop */
    -1,   /* 574: of_role_prop_experimenter */
    -1,   /* 575: of_table_desc */
    -1,   /* 576: of_table_feature_prop */
    -1,   /* 577: of_table_feature_prop_apply_actions */
    -1,   /* 578: of_table_feature_prop_apply_actions_miss */
    -1,   /* 579: of_table_feature_prop_apply_setfield */
    -1,   /* 580: of_table_feature_prop_apply_setfield_miss */
    -1,   /* 581: of_table_feature_prop_experimenter */
    -1,   /* 582: of_table_feature_prop_experimenter_miss */
    -1,   /* 583: of_table_feature_prop_instructions */
    -1,   /* 584: of_table_feature_prop_instructions_miss */
    -1,   /* 585: of_table_feature_prop_match */
    -1,   /* 586: of_table_feature_prop_next_tables */
    -1,   /* 587: of_table_feature_prop_next_tables_miss */
    -1,   /* 588: of_table_feature_prop_table_sync_from */
    -1,   /* 589: of_table_feature_prop_wildcards */
    -1,   /* 590: of_table_feature_prop_write_actions */
    -1,   /* 591: of_table_feature_prop_write_actions_miss */
    -1,   /* 592: of_table_feature_prop_write_setfield */
    -1,   /* 593: of_table_feature_prop_write_setfield_miss */
    -1,   /* 594: of_table_features */
    -1,   /* 595: of_table_mod_prop */
    -1,   /* 596: of_table_mod_prop_eviction */
    -1,   /* 597: of_table_mod_prop_experimenter */
    -1,   /* 598: of_table_mod_prop_vacancy */
    88,   /* 599: of_table_stats_entry */
    -1,   /* 600: of_uint32 */
    -1,   /* 601: of_uint64 */
    -1,   /* 602: of_uint8 */
    0,    /* 603: of_list_action */
    -1,   /* 604: of_list_action_id */
    -1,   /* 605: of_list_async_config_prop */
    -1,   /* 606: of_list_bsn_controller_connection */
    -1,   /* 607: of_list_bsn_debug_counter_desc_stats_entry */
    -1,   /* 608: of_list_bsn_debug_counter_stats_entry */
    -1,   /* 609: of_list_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 610: of_list_bsn_generic_stats_entry */
    -1,   /* 611: of_list_bsn_gentable_bucket_stats_entry */
    -1,   /* 612: of_list_bsn_gentable_desc_stats_entry */
    -1,   /* 613: of_list_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 614: of_list_bsn_gentable_entry_stats_entry */
    -1,   /* 615: of_list_bsn_gentable_stats_entry */
    0,    /* 616: of_list_bsn_interface */
    -1,   /* 617: of_list_bsn_lacp_stats_entry */
    -1,   /* 618: of_list_bsn_port_counter_stats_entry */
    -1,   /* 619: of_list_bsn_switch_pipeline_stats_entry */
    -1,   /* 620: of_list_bsn_table_checksum_stats_entry */
    -1,   /* 621: of_list_bsn_tlv */
    -1,   /* 622: of_list_bsn_vlan_counter_stats_entry */
    -1,   /* 623: of_list_bsn_vrf_counter_stats_entry */
    0,    /* 624: of_list_bucket */
    0,    /* 625: of_list_bucket_counter */
    -1,   /* 626: of_list_bundle_prop */
    0,    /* 627: of_list_flow_stats_entry */
    0,    /* 628: of_list_group_desc_stats_entry */
    0,    /* 629: of_list_group_stats_entry */
    -1,   /* 630: of_list_hello_elem */
    0,    /* 631: of_list_instruction */
    -1,   /* 632: of_list_instruction_id */
    -1,   /* 633: of_list_meter_band */
    -1,   /* 634: of_list_meter_band_stats */
    -1,   /* 635: of_list_meter_stats */
    -1,   /* 636: of_list_oxm */
    0,    /* 637: of_list_packet_queue */
    0,    /* 638: of_list_port_desc */
    -1,   /* 639: of_list_port_desc_prop */
    -1,   /* 640: of_list_port_mod_prop */
    0,    /* 641: of_list_port_stats_entry */
    -1,   /* 642: of_list_port_stats_prop */
    -1,   /* 643: of_list_queue_desc */
    -1,   /* 644: of_list_queue_desc_prop */
    0,    /* 645: of_list_queue_prop */
    0,    /* 646: of_list_queue_stats_entry */
    -1,   /* 647: of_list_queue_stats_prop */
    -1,   /* 648: of_list_role_prop */
    -1,   /* 649: of_list_table_desc */
    -1,   /* 650: of_list_table_feature_prop */
    -1,   /* 651: of_list_table_features */
    -1,   /* 652: of_list_table_mod_prop */
    0,    /* 653: of_list_table_stats_entry */
    -1,   /* 654: of_list_uint32 */
    -1,   /* 655: of_list_uint64 */
    -1    /* 656: of_list_uint8 */
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
    -1,   /* 34: of_bsn_generic_stats_reply */
    -1,   /* 35: of_bsn_generic_stats_request */
    -1,   /* 36: of_bsn_gentable_bucket_stats_reply */
    -1,   /* 37: of_bsn_gentable_bucket_stats_request */
    -1,   /* 38: of_bsn_gentable_clear_reply */
    -1,   /* 39: of_bsn_gentable_clear_request */
    -1,   /* 40: of_bsn_gentable_desc_stats_reply */
    -1,   /* 41: of_bsn_gentable_desc_stats_request */
    -1,   /* 42: of_bsn_gentable_entry_add */
    -1,   /* 43: of_bsn_gentable_entry_delete */
    -1,   /* 44: of_bsn_gentable_entry_desc_stats_reply */
    -1,   /* 45: of_bsn_gentable_entry_desc_stats_request */
    -1,   /* 46: of_bsn_gentable_entry_stats_reply */
    -1,   /* 47: of_bsn_gentable_entry_stats_request */
    -1,   /* 48: of_bsn_gentable_set_buckets_size */
    -1,   /* 49: of_bsn_gentable_stats_reply */
    -1,   /* 50: of_bsn_gentable_stats_request */
    16,   /* 51: of_bsn_get_interfaces_reply */
    16,   /* 52: of_bsn_get_interfaces_request */
    -1,   /* 53: of_bsn_get_ip_mask_reply */
    -1,   /* 54: of_bsn_get_ip_mask_request */
    -1,   /* 55: of_bsn_get_l2_table_reply */
    -1,   /* 56: of_bsn_get_l2_table_request */
    20,   /* 57: of_bsn_get_mirroring_reply */
    20,   /* 58: of_bsn_get_mirroring_request */
    -1,   /* 59: of_bsn_get_switch_pipeline_reply */
    -1,   /* 60: of_bsn_get_switch_pipeline_request */
    16,   /* 61: of_bsn_header */
    -1,   /* 62: of_bsn_hybrid_get_reply */
    -1,   /* 63: of_bsn_hybrid_get_request */
    -1,   /* 64: of_bsn_image_desc_stats_reply */
    -1,   /* 65: of_bsn_image_desc_stats_request */
    -1,   /* 66: of_bsn_lacp_convergence_notif */
    -1,   /* 67: of_bsn_lacp_stats_reply */
    -1,   /* 68: of_bsn_lacp_stats_request */
    -1,   /* 69: of_bsn_log */
    25,   /* 70: of_bsn_pdu_rx_reply */
    28,   /* 71: of_bsn_pdu_rx_request */
    21,   /* 72: of_bsn_pdu_rx_timeout */
    25,   /* 73: of_bsn_pdu_tx_reply */
    28,   /* 74: of_bsn_pdu_tx_request */
    -1,   /* 75: of_bsn_port_counter_stats_reply */
    -1,   /* 76: of_bsn_port_counter_stats_request */
    -1,   /* 77: of_bsn_role_status */
    -1,   /* 78: of_bsn_set_aux_cxns_reply */
    -1,   /* 79: of_bsn_set_aux_cxns_request */
    -1,   /* 80: of_bsn_set_ip_mask */
    -1,   /* 81: of_bsn_set_l2_table_reply */
    -1,   /* 82: of_bsn_set_l2_table_request */
    -1,   /* 83: of_bsn_set_lacp_reply */
    -1,   /* 84: of_bsn_set_lacp_request */
    20,   /* 85: of_bsn_set_mirroring */
    20,   /* 86: of_bsn_set_pktin_suppression_reply */
    32,   /* 87: of_bsn_set_pktin_suppression_request */
    -1,   /* 88: of_bsn_set_switch_pipeline_reply */
    -1,   /* 89: of_bsn_set_switch_pipeline_request */
    -1,   /* 90: of_bsn_shell_command */
    -1,   /* 91: of_bsn_shell_output */
    -1,   /* 92: of_bsn_shell_status */
    24,   /* 93: of_bsn_stats_reply */
    24,   /* 94: of_bsn_stats_request */
    -1,   /* 95: of_bsn_switch_pipeline_stats_reply */
    -1,   /* 96: of_bsn_switch_pipeline_stats_request */
    -1,   /* 97: of_bsn_table_checksum_stats_reply */
    -1,   /* 98: of_bsn_table_checksum_stats_request */
    -1,   /* 99: of_bsn_table_set_buckets_size */
    -1,   /* 100: of_bsn_time_reply */
    -1,   /* 101: of_bsn_time_request */
    24,   /* 102: of_bsn_virtual_port_create_reply */
    20,   /* 103: of_bsn_virtual_port_create_request */
    20,   /* 104: of_bsn_virtual_port_remove_reply */
    20,   /* 105: of_bsn_virtual_port_remove_request */
    -1,   /* 106: of_bsn_vlan_counter_stats_reply */
    -1,   /* 107: of_bsn_vlan_counter_stats_request */
    -1,   /* 108: of_bsn_vrf_counter_stats_reply */
    -1,   /* 109: of_bsn_vrf_counter_stats_request */
    -1,   /* 110: of_bundle_add_msg */
    -1,   /* 111: of_bundle_ctrl_msg */
    -1,   /* 112: of_bundle_failed_error_msg */
    1072, /* 113: of_desc_stats_reply */
    16,   /* 114: of_desc_stats_request */
    8,    /* 115: of_echo_reply */
    8,    /* 116: of_echo_request */
    10,   /* 117: of_error_msg */
    16,   /* 118: of_experimenter */
    16,   /* 119: of_experimenter_error_msg */
    24,   /* 120: of_experimenter_stats_reply */
    24,   /* 121: of_experimenter_stats_request */
    32,   /* 122: of_features_reply */
    8,    /* 123: of_features_request */
    56,   /* 124: of_flow_add */
    56,   /* 125: of_flow_delete */
    56,   /* 126: of_flow_delete_strict */
    56,   /* 127: of_flow_mod */
    12,   /* 128: of_flow_mod_failed_error_msg */
    56,   /* 129: of_flow_modify */
    56,   /* 130: of_flow_modify_strict */
    -1,   /* 131: of_flow_monitor_failed_error_msg */
    56,   /* 132: of_flow_removed */
    16,   /* 133: of_flow_stats_reply */
    56,   /* 134: of_flow_stats_request */
    12,   /* 135: of_get_config_reply */
    8,    /* 136: of_get_config_request */
    16,   /* 137: of_group_add */
    16,   /* 138: of_group_delete */
    16,   /* 139: of_group_desc_stats_reply */
    16,   /* 140: of_group_desc_stats_request */
    56,   /* 141: of_group_features_stats_reply */
    16,   /* 142: of_group_features_stats_request */
    16,   /* 143: of_group_mod */
    12,   /* 144: of_group_mod_failed_error_msg */
    16,   /* 145: of_group_modify */
    16,   /* 146: of_group_stats_reply */
    24,   /* 147: of_group_stats_request */
    8,    /* 148: of_header */
    8,    /* 149: of_hello */
    12,   /* 150: of_hello_failed_error_msg */
    -1,   /* 151: of_meter_config_stats_reply */
    -1,   /* 152: of_meter_config_stats_request */
    -1,   /* 153: of_meter_features_stats_reply */
    -1,   /* 154: of_meter_features_stats_request */
    -1,   /* 155: of_meter_mod */
    -1,   /* 156: of_meter_mod_failed_error_msg */
    -1,   /* 157: of_meter_stats_reply */
    -1,   /* 158: of_meter_stats_request */
    -1,   /* 159: of_nicira_controller_role_reply */
    -1,   /* 160: of_nicira_controller_role_request */
    16,   /* 161: of_nicira_header */
    26,   /* 162: of_packet_in */
    24,   /* 163: of_packet_out */
    -1,   /* 164: of_port_desc_stats_reply */
    -1,   /* 165: of_port_desc_stats_request */
    40,   /* 166: of_port_mod */
    12,   /* 167: of_port_mod_failed_error_msg */
    16,   /* 168: of_port_stats_reply */
    24,   /* 169: of_port_stats_request */
    80,   /* 170: of_port_status */
    -1,   /* 171: of_queue_desc_stats_reply */
    -1,   /* 172: of_queue_desc_stats_request */
    16,   /* 173: of_queue_get_config_reply */
    16,   /* 174: of_queue_get_config_request */
    12,   /* 175: of_queue_op_failed_error_msg */
    16,   /* 176: of_queue_stats_reply */
    24,   /* 177: of_queue_stats_request */
    -1,   /* 178: of_requestforward */
    24,   /* 179: of_role_reply */
    24,   /* 180: of_role_request */
    12,   /* 181: of_role_request_failed_error_msg */
    -1,   /* 182: of_role_status */
    12,   /* 183: of_set_config */
    16,   /* 184: of_stats_reply */
    16,   /* 185: of_stats_request */
    12,   /* 186: of_switch_config_failed_error_msg */
    -1,   /* 187: of_table_desc_stats_reply */
    -1,   /* 188: of_table_desc_stats_request */
    -1,   /* 189: of_table_features_failed_error_msg */
    -1,   /* 190: of_table_features_stats_reply */
    -1,   /* 191: of_table_features_stats_request */
    16,   /* 192: of_table_mod */
    12,   /* 193: of_table_mod_failed_error_msg */
    16,   /* 194: of_table_stats_reply */
    16,   /* 195: of_table_stats_request */
    -1,   /* 196: of_table_status */
    8,    /* 197: of_action */
    16,   /* 198: of_action_bsn */
    28,   /* 199: of_action_bsn_checksum */
    -1,   /* 200: of_action_bsn_gentable */
    24,   /* 201: of_action_bsn_mirror */
    16,   /* 202: of_action_bsn_set_tunnel_dst */
    8,    /* 203: of_action_copy_ttl_in */
    8,    /* 204: of_action_copy_ttl_out */
    8,    /* 205: of_action_dec_mpls_ttl */
    8,    /* 206: of_action_dec_nw_ttl */
    -1,   /* 207: of_action_enqueue */
    8,    /* 208: of_action_experimenter */
    8,    /* 209: of_action_group */
    -1,   /* 210: of_action_id */
    -1,   /* 211: of_action_id_bsn */
    -1,   /* 212: of_action_id_bsn_checksum */
    -1,   /* 213: of_action_id_bsn_gentable */
    -1,   /* 214: of_action_id_bsn_mirror */
    -1,   /* 215: of_action_id_bsn_set_tunnel_dst */
    -1,   /* 216: of_action_id_copy_ttl_in */
    -1,   /* 217: of_action_id_copy_ttl_out */
    -1,   /* 218: of_action_id_dec_mpls_ttl */
    -1,   /* 219: of_action_id_dec_nw_ttl */
    -1,   /* 220: of_action_id_experimenter */
    -1,   /* 221: of_action_id_group */
    -1,   /* 222: of_action_id_nicira */
    -1,   /* 223: of_action_id_nicira_dec_ttl */
    -1,   /* 224: of_action_id_output */
    -1,   /* 225: of_action_id_pop_mpls */
    -1,   /* 226: of_action_id_pop_pbb */
    -1,   /* 227: of_action_id_pop_vlan */
    -1,   /* 228: of_action_id_push_mpls */
    -1,   /* 229: of_action_id_push_pbb */
    -1,   /* 230: of_action_id_push_vlan */
    -1,   /* 231: of_action_id_set_field */
    -1,   /* 232: of_action_id_set_mpls_ttl */
    -1,   /* 233: of_action_id_set_nw_ttl */
    -1,   /* 234: of_action_id_set_queue */
    16,   /* 235: of_action_nicira */
    16,   /* 236: of_action_nicira_dec_ttl */
    16,   /* 237: of_action_output */
    8,    /* 238: of_action_pop_mpls */
    -1,   /* 239: of_action_pop_pbb */
    8,    /* 240: of_action_pop_vlan */
    8,    /* 241: of_action_push_mpls */
    -1,   /* 242: of_action_push_pbb */
    8,    /* 243: of_action_push_vlan */
    -1,   /* 244: of_action_set_dl_dst */
    -1,   /* 245: of_action_set_dl_src */
    8,    /* 246: of_action_set_field */
    -1,   /* 247: of_action_set_mpls_label */
    -1,   /* 248: of_action_set_mpls_tc */
    8,    /* 249: of_action_set_mpls_ttl */
    -1,   /* 250: of_action_set_nw_dst */
    -1,   /* 251: of_action_set_nw_ecn */
    -1,   /* 252: of_action_set_nw_src */
    -1,   /* 253: of_action_set_nw_tos */
    8,    /* 254: of_action_set_nw_ttl */
    8,    /* 255: of_action_set_queue */
    -1,   /* 256: of_action_set_tp_dst */
    -1,   /* 257: of_action_set_tp_src */
    -1,   /* 258: of_action_set_vlan_pcp */
    -1,   /* 259: of_action_set_vlan_vid */
    -1,   /* 260: of_action_strip_vlan */
    -1,   /* 261: of_async_config_prop */
    -1,   /* 262: of_async_config_prop_experimenter_master */
    -1,   /* 263: of_async_config_prop_experimenter_slave */
    -1,   /* 264: of_async_config_prop_flow_removed_master */
    -1,   /* 265: of_async_config_prop_flow_removed_slave */
    -1,   /* 266: of_async_config_prop_packet_in_master */
    -1,   /* 267: of_async_config_prop_packet_in_slave */
    -1,   /* 268: of_async_config_prop_port_status_master */
    -1,   /* 269: of_async_config_prop_port_status_slave */
    -1,   /* 270: of_async_config_prop_requestforward_master */
    -1,   /* 271: of_async_config_prop_requestforward_slave */
    -1,   /* 272: of_async_config_prop_role_status_master */
    -1,   /* 273: of_async_config_prop_role_status_slave */
    -1,   /* 274: of_async_config_prop_table_status_master */
    -1,   /* 275: of_async_config_prop_table_status_slave */
    -1,   /* 276: of_bsn_controller_connection */
    -1,   /* 277: of_bsn_debug_counter_desc_stats_entry */
    -1,   /* 278: of_bsn_debug_counter_stats_entry */
    -1,   /* 279: of_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 280: of_bsn_generic_stats_entry */
    -1,   /* 281: of_bsn_gentable_bucket_stats_entry */
    -1,   /* 282: of_bsn_gentable_desc_stats_entry */
    -1,   /* 283: of_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 284: of_bsn_gentable_entry_stats_entry */
    -1,   /* 285: of_bsn_gentable_stats_entry */
    32,   /* 286: of_bsn_interface */
    -1,   /* 287: of_bsn_lacp_stats_entry */
    -1,   /* 288: of_bsn_port_counter_stats_entry */
    -1,   /* 289: of_bsn_switch_pipeline_stats_entry */
    -1,   /* 290: of_bsn_table_checksum_stats_entry */
    -1,   /* 291: of_bsn_tlv */
    -1,   /* 292: of_bsn_tlv_actor_key */
    -1,   /* 293: of_bsn_tlv_actor_port_num */
    -1,   /* 294: of_bsn_tlv_actor_port_priority */
    -1,   /* 295: of_bsn_tlv_actor_state */
    -1,   /* 296: of_bsn_tlv_actor_system_mac */
    -1,   /* 297: of_bsn_tlv_actor_system_priority */
    -1,   /* 298: of_bsn_tlv_broadcast_query_timeout */
    -1,   /* 299: of_bsn_tlv_bucket */
    -1,   /* 300: of_bsn_tlv_circuit_id */
    -1,   /* 301: of_bsn_tlv_convergence_status */
    -1,   /* 302: of_bsn_tlv_crc_enabled */
    -1,   /* 303: of_bsn_tlv_data */
    -1,   /* 304: of_bsn_tlv_eth_dst */
    -1,   /* 305: of_bsn_tlv_eth_src */
    -1,   /* 306: of_bsn_tlv_external_gateway_ip */
    -1,   /* 307: of_bsn_tlv_external_gateway_mac */
    -1,   /* 308: of_bsn_tlv_external_ip */
    -1,   /* 309: of_bsn_tlv_external_mac */
    -1,   /* 310: of_bsn_tlv_external_netmask */
    -1,   /* 311: of_bsn_tlv_header_size */
    -1,   /* 312: of_bsn_tlv_idle_notification */
    -1,   /* 313: of_bsn_tlv_idle_time */
    -1,   /* 314: of_bsn_tlv_idle_timeout */
    -1,   /* 315: of_bsn_tlv_internal_gateway_mac */
    -1,   /* 316: of_bsn_tlv_internal_mac */
    -1,   /* 317: of_bsn_tlv_interval */
    -1,   /* 318: of_bsn_tlv_ipv4 */
    -1,   /* 319: of_bsn_tlv_ipv4_dst */
    -1,   /* 320: of_bsn_tlv_ipv4_netmask */
    -1,   /* 321: of_bsn_tlv_ipv4_src */
    -1,   /* 322: of_bsn_tlv_mac */
    -1,   /* 323: of_bsn_tlv_mac_mask */
    -1,   /* 324: of_bsn_tlv_miss_packets */
    -1,   /* 325: of_bsn_tlv_mpls_control_word */
    -1,   /* 326: of_bsn_tlv_mpls_label */
    -1,   /* 327: of_bsn_tlv_mpls_sequenced */
    -1,   /* 328: of_bsn_tlv_name */
    -1,   /* 329: of_bsn_tlv_partner_key */
    -1,   /* 330: of_bsn_tlv_partner_port_num */
    -1,   /* 331: of_bsn_tlv_partner_port_priority */
    -1,   /* 332: of_bsn_tlv_partner_state */
    -1,   /* 333: of_bsn_tlv_partner_system_mac */
    -1,   /* 334: of_bsn_tlv_partner_system_priority */
    -1,   /* 335: of_bsn_tlv_port */
    -1,   /* 336: of_bsn_tlv_priority */
    -1,   /* 337: of_bsn_tlv_queue_id */
    -1,   /* 338: of_bsn_tlv_queue_weight */
    -1,   /* 339: of_bsn_tlv_reference */
    -1,   /* 340: of_bsn_tlv_reply_packets */
    -1,   /* 341: of_bsn_tlv_request_packets */
    -1,   /* 342: of_bsn_tlv_rx_packets */
    -1,   /* 343: of_bsn_tlv_sampling_rate */
    -1,   /* 344: of_bsn_tlv_sub_agent_id */
    -1,   /* 345: of_bsn_tlv_tx_bytes */
    -1,   /* 346: of_bsn_tlv_tx_packets */
    -1,   /* 347: of_bsn_tlv_udf_anchor */
    -1,   /* 348: of_bsn_tlv_udf_id */
    -1,   /* 349: of_bsn_tlv_udf_length */
    -1,   /* 350: of_bsn_tlv_udf_offset */
    -1,   /* 351: of_bsn_tlv_udp_dst */
    -1,   /* 352: of_bsn_tlv_udp_src */
    -1,   /* 353: of_bsn_tlv_unicast_query_timeout */
    -1,   /* 354: of_bsn_tlv_vlan_vid */
    -1,   /* 355: of_bsn_tlv_vrf */
    -1,   /* 356: of_bsn_vlan_counter_stats_entry */
    4,    /* 357: of_bsn_vport */
    64,   /* 358: of_bsn_vport_l2gre */
    32,   /* 359: of_bsn_vport_q_in_q */
    -1,   /* 360: of_bsn_vrf_counter_stats_entry */
    16,   /* 361: of_bucket */
    16,   /* 362: of_bucket_counter */
    -1,   /* 363: of_bundle_prop */
    -1,   /* 364: of_bundle_prop_experimenter */
    56,   /* 365: of_flow_stats_entry */
    8,    /* 366: of_group_desc_stats_entry */
    32,   /* 367: of_group_stats_entry */
    -1,   /* 368: of_hello_elem */
    -1,   /* 369: of_hello_elem_versionbitmap */
    8,    /* 370: of_instruction */
    8,    /* 371: of_instruction_apply_actions */
    -1,   /* 372: of_instruction_bsn */
    -1,   /* 373: of_instruction_bsn_arp_offload */
    -1,   /* 374: of_instruction_bsn_auto_negotiation */
    -1,   /* 375: of_instruction_bsn_deny */
    -1,   /* 376: of_instruction_bsn_dhcp_offload */
    -1,   /* 377: of_instruction_bsn_disable_split_horizon_check */
    -1,   /* 378: of_instruction_bsn_disable_src_mac_check */
    -1,   /* 379: of_instruction_bsn_disable_vlan_counters */
    -1,   /* 380: of_instruction_bsn_packet_of_death */
    -1,   /* 381: of_instruction_bsn_permit */
    -1,   /* 382: of_instruction_bsn_prioritize_pdus */
    -1,   /* 383: of_instruction_bsn_require_vlan_xlate */
    -1,   /* 384: of_instruction_bsn_span_destination */
    8,    /* 385: of_instruction_clear_actions */
    8,    /* 386: of_instruction_experimenter */
    8,    /* 387: of_instruction_goto_table */
    -1,   /* 388: of_instruction_id */
    -1,   /* 389: of_instruction_id_apply_actions */
    -1,   /* 390: of_instruction_id_bsn */
    -1,   /* 391: of_instruction_id_bsn_arp_offload */
    -1,   /* 392: of_instruction_id_bsn_auto_negotiation */
    -1,   /* 393: of_instruction_id_bsn_deny */
    -1,   /* 394: of_instruction_id_bsn_dhcp_offload */
    -1,   /* 395: of_instruction_id_bsn_disable_split_horizon_check */
    -1,   /* 396: of_instruction_id_bsn_disable_src_mac_check */
    -1,   /* 397: of_instruction_id_bsn_disable_vlan_counters */
    -1,   /* 398: of_instruction_id_bsn_packet_of_death */
    -1,   /* 399: of_instruction_id_bsn_permit */
    -1,   /* 400: of_instruction_id_bsn_prioritize_pdus */
    -1,   /* 401: of_instruction_id_bsn_require_vlan_xlate */
    -1,   /* 402: of_instruction_id_bsn_span_destination */
    -1,   /* 403: of_instruction_id_clear_actions */
    -1,   /* 404: of_instruction_id_experimenter */
    -1,   /* 405: of_instruction_id_goto_table */
    -1,   /* 406: of_instruction_id_meter */
    -1,   /* 407: of_instruction_id_write_actions */
    -1,   /* 408: of_instruction_id_write_metadata */
    -1,   /* 409: of_instruction_meter */
    8,    /* 410: of_instruction_write_actions */
    24,   /* 411: of_instruction_write_metadata */
    -1,   /* 412: of_match_v1 */
    -1,   /* 413: of_match_v2 */
    4,    /* 414: of_match_v3 */
    -1,   /* 415: of_meter_band */
    -1,   /* 416: of_meter_band_drop */
    -1,   /* 417: of_meter_band_dscp_remark */
    -1,   /* 418: of_meter_band_experimenter */
    -1,   /* 419: of_meter_band_stats */
    -1,   /* 420: of_meter_config */
    -1,   /* 421: of_meter_features */
    -1,   /* 422: of_meter_stats */
    4,    /* 423: of_oxm */
    6,    /* 424: of_oxm_arp_op */
    8,    /* 425: of_oxm_arp_op_masked */
    10,   /* 426: of_oxm_arp_sha */
    16,   /* 427: of_oxm_arp_sha_masked */
    8,    /* 428: of_oxm_arp_spa */
    12,   /* 429: of_oxm_arp_spa_masked */
    10,   /* 430: of_oxm_arp_tha */
    16,   /* 431: of_oxm_arp_tha_masked */
    8,    /* 432: of_oxm_arp_tpa */
    12,   /* 433: of_oxm_arp_tpa_masked */
    8,    /* 434: of_oxm_bsn_egr_port_group_id */
    12,   /* 435: of_oxm_bsn_egr_port_group_id_masked */
    5,    /* 436: of_oxm_bsn_global_vrf_allowed */
    6,    /* 437: of_oxm_bsn_global_vrf_allowed_masked */
    20,   /* 438: of_oxm_bsn_in_ports_128 */
    36,   /* 439: of_oxm_bsn_in_ports_128_masked */
    5,    /* 440: of_oxm_bsn_l2_cache_hit */
    6,    /* 441: of_oxm_bsn_l2_cache_hit_masked */
    8,    /* 442: of_oxm_bsn_l3_dst_class_id */
    12,   /* 443: of_oxm_bsn_l3_dst_class_id_masked */
    8,    /* 444: of_oxm_bsn_l3_interface_class_id */
    12,   /* 445: of_oxm_bsn_l3_interface_class_id_masked */
    8,    /* 446: of_oxm_bsn_l3_src_class_id */
    12,   /* 447: of_oxm_bsn_l3_src_class_id_masked */
    8,    /* 448: of_oxm_bsn_lag_id */
    12,   /* 449: of_oxm_bsn_lag_id_masked */
    6,    /* 450: of_oxm_bsn_tcp_flags */
    8,    /* 451: of_oxm_bsn_tcp_flags_masked */
    8,    /* 452: of_oxm_bsn_udf0 */
    12,   /* 453: of_oxm_bsn_udf0_masked */
    8,    /* 454: of_oxm_bsn_udf1 */
    12,   /* 455: of_oxm_bsn_udf1_masked */
    8,    /* 456: of_oxm_bsn_udf2 */
    12,   /* 457: of_oxm_bsn_udf2_masked */
    8,    /* 458: of_oxm_bsn_udf3 */
    12,   /* 459: of_oxm_bsn_udf3_masked */
    8,    /* 460: of_oxm_bsn_udf4 */
    12,   /* 461: of_oxm_bsn_udf4_masked */
    8,    /* 462: of_oxm_bsn_udf5 */
    12,   /* 463: of_oxm_bsn_udf5_masked */
    8,    /* 464: of_oxm_bsn_udf6 */
    12,   /* 465: of_oxm_bsn_udf6_masked */
    8,    /* 466: of_oxm_bsn_udf7 */
    12,   /* 467: of_oxm_bsn_udf7_masked */
    8,    /* 468: of_oxm_bsn_vlan_xlate_port_group_id */
    12,   /* 469: of_oxm_bsn_vlan_xlate_port_group_id_masked */
    8,    /* 470: of_oxm_bsn_vrf */
    12,   /* 471: of_oxm_bsn_vrf_masked */
    10,   /* 472: of_oxm_eth_dst */
    16,   /* 473: of_oxm_eth_dst_masked */
    10,   /* 474: of_oxm_eth_src */
    16,   /* 475: of_oxm_eth_src_masked */
    6,    /* 476: of_oxm_eth_type */
    8,    /* 477: of_oxm_eth_type_masked */
    5,    /* 478: of_oxm_icmpv4_code */
    6,    /* 479: of_oxm_icmpv4_code_masked */
    5,    /* 480: of_oxm_icmpv4_type */
    6,    /* 481: of_oxm_icmpv4_type_masked */
    5,    /* 482: of_oxm_icmpv6_code */
    6,    /* 483: of_oxm_icmpv6_code_masked */
    5,    /* 484: of_oxm_icmpv6_type */
    6,    /* 485: of_oxm_icmpv6_type_masked */
    8,    /* 486: of_oxm_in_phy_port */
    12,   /* 487: of_oxm_in_phy_port_masked */
    8,    /* 488: of_oxm_in_port */
    12,   /* 489: of_oxm_in_port_masked */
    5,    /* 490: of_oxm_ip_dscp */
    6,    /* 491: of_oxm_ip_dscp_masked */
    5,    /* 492: of_oxm_ip_ecn */
    6,    /* 493: of_oxm_ip_ecn_masked */
    5,    /* 494: of_oxm_ip_proto */
    6,    /* 495: of_oxm_ip_proto_masked */
    8,    /* 496: of_oxm_ipv4_dst */
    12,   /* 497: of_oxm_ipv4_dst_masked */
    8,    /* 498: of_oxm_ipv4_src */
    12,   /* 499: of_oxm_ipv4_src_masked */
    20,   /* 500: of_oxm_ipv6_dst */
    36,   /* 501: of_oxm_ipv6_dst_masked */
    -1,   /* 502: of_oxm_ipv6_exthdr */
    -1,   /* 503: of_oxm_ipv6_exthdr_masked */
    8,    /* 504: of_oxm_ipv6_flabel */
    12,   /* 505: of_oxm_ipv6_flabel_masked */
    10,   /* 506: of_oxm_ipv6_nd_sll */
    16,   /* 507: of_oxm_ipv6_nd_sll_masked */
    20,   /* 508: of_oxm_ipv6_nd_target */
    36,   /* 509: of_oxm_ipv6_nd_target_masked */
    10,   /* 510: of_oxm_ipv6_nd_tll */
    16,   /* 511: of_oxm_ipv6_nd_tll_masked */
    20,   /* 512: of_oxm_ipv6_src */
    36,   /* 513: of_oxm_ipv6_src_masked */
    12,   /* 514: of_oxm_metadata */
    20,   /* 515: of_oxm_metadata_masked */
    -1,   /* 516: of_oxm_mpls_bos */
    -1,   /* 517: of_oxm_mpls_bos_masked */
    8,    /* 518: of_oxm_mpls_label */
    12,   /* 519: of_oxm_mpls_label_masked */
    5,    /* 520: of_oxm_mpls_tc */
    6,    /* 521: of_oxm_mpls_tc_masked */
    -1,   /* 522: of_oxm_pbb_uca */
    -1,   /* 523: of_oxm_pbb_uca_masked */
    6,    /* 524: of_oxm_sctp_dst */
    8,    /* 525: of_oxm_sctp_dst_masked */
    6,    /* 526: of_oxm_sctp_src */
    8,    /* 527: of_oxm_sctp_src_masked */
    6,    /* 528: of_oxm_tcp_dst */
    8,    /* 529: of_oxm_tcp_dst_masked */
    6,    /* 530: of_oxm_tcp_src */
    8,    /* 531: of_oxm_tcp_src_masked */
    -1,   /* 532: of_oxm_tunnel_id */
    -1,   /* 533: of_oxm_tunnel_id_masked */
    8,    /* 534: of_oxm_tunnel_ipv4_dst */
    12,   /* 535: of_oxm_tunnel_ipv4_dst_masked */
    8,    /* 536: of_oxm_tunnel_ipv4_src */
    12,   /* 537: of_oxm_tunnel_ipv4_src_masked */
    6,    /* 538: of_oxm_udp_dst */
    8,    /* 539: of_oxm_udp_dst_masked */
    6,    /* 540: of_oxm_udp_src */
    8,    /* 541: of_oxm_udp_src_masked */
    5,    /* 542: of_oxm_vlan_pcp */
    6,    /* 543: of_oxm_vlan_pcp_masked */
    6,    /* 544: of_oxm_vlan_vid */
    8,    /* 545: of_oxm_vlan_vid_masked */
    16,   /* 546: of_packet_queue */
    64,   /* 547: of_port_desc */
    -1,   /* 548: of_port_desc_prop */
    -1,   /* 549: of_port_desc_prop_ethernet */
    -1,   /* 550: of_port_desc_prop_experimenter */
    -1,   /* 551: of_port_desc_prop_optical */
    -1,   /* 552: of_port_mod_prop */
    -1,   /* 553: of_port_mod_prop_ethernet */
    -1,   /* 554: of_port_mod_prop_experimenter */
    -1,   /* 555: of_port_mod_prop_optical */
    104,  /* 556: of_port_stats_entry */
    -1,   /* 557: of_port_stats_prop */
    -1,   /* 558: of_port_stats_prop_ethernet */
    -1,   /* 559: of_port_stats_prop_experimenter */
    -1,   /* 560: of_port_stats_prop_optical */
    -1,   /* 561: of_queue_desc */
    -1,   /* 562: of_queue_desc_prop */
    -1,   /* 563: of_queue_desc_prop_experimenter */
    -1,   /* 564: of_queue_desc_prop_max_rate */
    -1,   /* 565: of_queue_desc_prop_min_rate */
    8,    /* 566: of_queue_prop */
    16,   /* 567: of_queue_prop_experimenter */
    16,   /* 568: of_queue_prop_max_rate */
    16,   /* 569: of_queue_prop_min_rate */
    32,   /* 570: of_queue_stats_entry */
    -1,   /* 571: of_queue_stats_prop */
    -1,   /* 572: of_queue_stats_prop_experimenter */
    -1,   /* 573: of_role_prop */
    -1,   /* 574: of_role_prop_experimenter */
    -1,   /* 575: of_table_desc */
    -1,   /* 576: of_table_feature_prop */
    -1,   /* 577: of_table_feature_prop_apply_actions */
    -1,   /* 578: of_table_feature_prop_apply_actions_miss */
    -1,   /* 579: of_table_feature_prop_apply_setfield */
    -1,   /* 580: of_table_feature_prop_apply_setfield_miss */
    -1,   /* 581: of_table_feature_prop_experimenter */
    -1,   /* 582: of_table_feature_prop_experimenter_miss */
    -1,   /* 583: of_table_feature_prop_instructions */
    -1,   /* 584: of_table_feature_prop_instructions_miss */
    -1,   /* 585: of_table_feature_prop_match */
    -1,   /* 586: of_table_feature_prop_next_tables */
    -1,   /* 587: of_table_feature_prop_next_tables_miss */
    -1,   /* 588: of_table_feature_prop_table_sync_from */
    -1,   /* 589: of_table_feature_prop_wildcards */
    -1,   /* 590: of_table_feature_prop_write_actions */
    -1,   /* 591: of_table_feature_prop_write_actions_miss */
    -1,   /* 592: of_table_feature_prop_write_setfield */
    -1,   /* 593: of_table_feature_prop_write_setfield_miss */
    -1,   /* 594: of_table_features */
    -1,   /* 595: of_table_mod_prop */
    -1,   /* 596: of_table_mod_prop_eviction */
    -1,   /* 597: of_table_mod_prop_experimenter */
    -1,   /* 598: of_table_mod_prop_vacancy */
    128,  /* 599: of_table_stats_entry */
    -1,   /* 600: of_uint32 */
    -1,   /* 601: of_uint64 */
    -1,   /* 602: of_uint8 */
    0,    /* 603: of_list_action */
    -1,   /* 604: of_list_action_id */
    -1,   /* 605: of_list_async_config_prop */
    -1,   /* 606: of_list_bsn_controller_connection */
    -1,   /* 607: of_list_bsn_debug_counter_desc_stats_entry */
    -1,   /* 608: of_list_bsn_debug_counter_stats_entry */
    -1,   /* 609: of_list_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 610: of_list_bsn_generic_stats_entry */
    -1,   /* 611: of_list_bsn_gentable_bucket_stats_entry */
    -1,   /* 612: of_list_bsn_gentable_desc_stats_entry */
    -1,   /* 613: of_list_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 614: of_list_bsn_gentable_entry_stats_entry */
    -1,   /* 615: of_list_bsn_gentable_stats_entry */
    0,    /* 616: of_list_bsn_interface */
    -1,   /* 617: of_list_bsn_lacp_stats_entry */
    -1,   /* 618: of_list_bsn_port_counter_stats_entry */
    -1,   /* 619: of_list_bsn_switch_pipeline_stats_entry */
    -1,   /* 620: of_list_bsn_table_checksum_stats_entry */
    -1,   /* 621: of_list_bsn_tlv */
    -1,   /* 622: of_list_bsn_vlan_counter_stats_entry */
    -1,   /* 623: of_list_bsn_vrf_counter_stats_entry */
    0,    /* 624: of_list_bucket */
    0,    /* 625: of_list_bucket_counter */
    -1,   /* 626: of_list_bundle_prop */
    0,    /* 627: of_list_flow_stats_entry */
    0,    /* 628: of_list_group_desc_stats_entry */
    0,    /* 629: of_list_group_stats_entry */
    -1,   /* 630: of_list_hello_elem */
    0,    /* 631: of_list_instruction */
    -1,   /* 632: of_list_instruction_id */
    -1,   /* 633: of_list_meter_band */
    -1,   /* 634: of_list_meter_band_stats */
    -1,   /* 635: of_list_meter_stats */
    0,    /* 636: of_list_oxm */
    0,    /* 637: of_list_packet_queue */
    0,    /* 638: of_list_port_desc */
    -1,   /* 639: of_list_port_desc_prop */
    -1,   /* 640: of_list_port_mod_prop */
    0,    /* 641: of_list_port_stats_entry */
    -1,   /* 642: of_list_port_stats_prop */
    -1,   /* 643: of_list_queue_desc */
    -1,   /* 644: of_list_queue_desc_prop */
    0,    /* 645: of_list_queue_prop */
    0,    /* 646: of_list_queue_stats_entry */
    -1,   /* 647: of_list_queue_stats_prop */
    -1,   /* 648: of_list_role_prop */
    -1,   /* 649: of_list_table_desc */
    -1,   /* 650: of_list_table_feature_prop */
    -1,   /* 651: of_list_table_features */
    -1,   /* 652: of_list_table_mod_prop */
    0,    /* 653: of_list_table_stats_entry */
    -1,   /* 654: of_list_uint32 */
    -1,   /* 655: of_list_uint64 */
    -1    /* 656: of_list_uint8 */
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
    24,   /* 34: of_bsn_generic_stats_reply */
    88,   /* 35: of_bsn_generic_stats_request */
    24,   /* 36: of_bsn_gentable_bucket_stats_reply */
    26,   /* 37: of_bsn_gentable_bucket_stats_request */
    28,   /* 38: of_bsn_gentable_clear_reply */
    52,   /* 39: of_bsn_gentable_clear_request */
    24,   /* 40: of_bsn_gentable_desc_stats_reply */
    24,   /* 41: of_bsn_gentable_desc_stats_request */
    36,   /* 42: of_bsn_gentable_entry_add */
    18,   /* 43: of_bsn_gentable_entry_delete */
    24,   /* 44: of_bsn_gentable_entry_desc_stats_reply */
    60,   /* 45: of_bsn_gentable_entry_desc_stats_request */
    24,   /* 46: of_bsn_gentable_entry_stats_reply */
    60,   /* 47: of_bsn_gentable_entry_stats_request */
    24,   /* 48: of_bsn_gentable_set_buckets_size */
    24,   /* 49: of_bsn_gentable_stats_reply */
    24,   /* 50: of_bsn_gentable_stats_request */
    16,   /* 51: of_bsn_get_interfaces_reply */
    16,   /* 52: of_bsn_get_interfaces_request */
    -1,   /* 53: of_bsn_get_ip_mask_reply */
    -1,   /* 54: of_bsn_get_ip_mask_request */
    -1,   /* 55: of_bsn_get_l2_table_reply */
    -1,   /* 56: of_bsn_get_l2_table_request */
    20,   /* 57: of_bsn_get_mirroring_reply */
    20,   /* 58: of_bsn_get_mirroring_request */
    272,  /* 59: of_bsn_get_switch_pipeline_reply */
    16,   /* 60: of_bsn_get_switch_pipeline_request */
    16,   /* 61: of_bsn_header */
    -1,   /* 62: of_bsn_hybrid_get_reply */
    -1,   /* 63: of_bsn_hybrid_get_request */
    536,  /* 64: of_bsn_image_desc_stats_reply */
    24,   /* 65: of_bsn_image_desc_stats_request */
    52,   /* 66: of_bsn_lacp_convergence_notif */
    24,   /* 67: of_bsn_lacp_stats_reply */
    24,   /* 68: of_bsn_lacp_stats_request */
    17,   /* 69: of_bsn_log */
    25,   /* 70: of_bsn_pdu_rx_reply */
    28,   /* 71: of_bsn_pdu_rx_request */
    21,   /* 72: of_bsn_pdu_rx_timeout */
    25,   /* 73: of_bsn_pdu_tx_reply */
    28,   /* 74: of_bsn_pdu_tx_request */
    24,   /* 75: of_bsn_port_counter_stats_reply */
    28,   /* 76: of_bsn_port_counter_stats_request */
    32,   /* 77: of_bsn_role_status */
    24,   /* 78: of_bsn_set_aux_cxns_reply */
    20,   /* 79: of_bsn_set_aux_cxns_request */
    -1,   /* 80: of_bsn_set_ip_mask */
    -1,   /* 81: of_bsn_set_l2_table_reply */
    -1,   /* 82: of_bsn_set_l2_table_request */
    24,   /* 83: of_bsn_set_lacp_reply */
    38,   /* 84: of_bsn_set_lacp_request */
    20,   /* 85: of_bsn_set_mirroring */
    20,   /* 86: of_bsn_set_pktin_suppression_reply */
    32,   /* 87: of_bsn_set_pktin_suppression_request */
    20,   /* 88: of_bsn_set_switch_pipeline_reply */
    272,  /* 89: of_bsn_set_switch_pipeline_request */
    -1,   /* 90: of_bsn_shell_command */
    -1,   /* 91: of_bsn_shell_output */
    -1,   /* 92: of_bsn_shell_status */
    24,   /* 93: of_bsn_stats_reply */
    24,   /* 94: of_bsn_stats_request */
    24,   /* 95: of_bsn_switch_pipeline_stats_reply */
    24,   /* 96: of_bsn_switch_pipeline_stats_request */
    24,   /* 97: of_bsn_table_checksum_stats_reply */
    24,   /* 98: of_bsn_table_checksum_stats_request */
    24,   /* 99: of_bsn_table_set_buckets_size */
    24,   /* 100: of_bsn_time_reply */
    16,   /* 101: of_bsn_time_request */
    24,   /* 102: of_bsn_virtual_port_create_reply */
    20,   /* 103: of_bsn_virtual_port_create_request */
    20,   /* 104: of_bsn_virtual_port_remove_reply */
    20,   /* 105: of_bsn_virtual_port_remove_request */
    24,   /* 106: of_bsn_vlan_counter_stats_reply */
    26,   /* 107: of_bsn_vlan_counter_stats_request */
    24,   /* 108: of_bsn_vrf_counter_stats_reply */
    28,   /* 109: of_bsn_vrf_counter_stats_request */
    -1,   /* 110: of_bundle_add_msg */
    -1,   /* 111: of_bundle_ctrl_msg */
    -1,   /* 112: of_bundle_failed_error_msg */
    1072, /* 113: of_desc_stats_reply */
    16,   /* 114: of_desc_stats_request */
    8,    /* 115: of_echo_reply */
    8,    /* 116: of_echo_request */
    10,   /* 117: of_error_msg */
    16,   /* 118: of_experimenter */
    16,   /* 119: of_experimenter_error_msg */
    24,   /* 120: of_experimenter_stats_reply */
    24,   /* 121: of_experimenter_stats_request */
    32,   /* 122: of_features_reply */
    8,    /* 123: of_features_request */
    56,   /* 124: of_flow_add */
    56,   /* 125: of_flow_delete */
    56,   /* 126: of_flow_delete_strict */
    56,   /* 127: of_flow_mod */
    12,   /* 128: of_flow_mod_failed_error_msg */
    56,   /* 129: of_flow_modify */
    56,   /* 130: of_flow_modify_strict */
    -1,   /* 131: of_flow_monitor_failed_error_msg */
    56,   /* 132: of_flow_removed */
    16,   /* 133: of_flow_stats_reply */
    56,   /* 134: of_flow_stats_request */
    12,   /* 135: of_get_config_reply */
    8,    /* 136: of_get_config_request */
    16,   /* 137: of_group_add */
    16,   /* 138: of_group_delete */
    16,   /* 139: of_group_desc_stats_reply */
    16,   /* 140: of_group_desc_stats_request */
    56,   /* 141: of_group_features_stats_reply */
    16,   /* 142: of_group_features_stats_request */
    16,   /* 143: of_group_mod */
    12,   /* 144: of_group_mod_failed_error_msg */
    16,   /* 145: of_group_modify */
    16,   /* 146: of_group_stats_reply */
    24,   /* 147: of_group_stats_request */
    8,    /* 148: of_header */
    8,    /* 149: of_hello */
    12,   /* 150: of_hello_failed_error_msg */
    16,   /* 151: of_meter_config_stats_reply */
    24,   /* 152: of_meter_config_stats_request */
    32,   /* 153: of_meter_features_stats_reply */
    16,   /* 154: of_meter_features_stats_request */
    16,   /* 155: of_meter_mod */
    12,   /* 156: of_meter_mod_failed_error_msg */
    16,   /* 157: of_meter_stats_reply */
    24,   /* 158: of_meter_stats_request */
    -1,   /* 159: of_nicira_controller_role_reply */
    -1,   /* 160: of_nicira_controller_role_request */
    16,   /* 161: of_nicira_header */
    34,   /* 162: of_packet_in */
    24,   /* 163: of_packet_out */
    16,   /* 164: of_port_desc_stats_reply */
    16,   /* 165: of_port_desc_stats_request */
    40,   /* 166: of_port_mod */
    12,   /* 167: of_port_mod_failed_error_msg */
    16,   /* 168: of_port_stats_reply */
    24,   /* 169: of_port_stats_request */
    80,   /* 170: of_port_status */
    -1,   /* 171: of_queue_desc_stats_reply */
    -1,   /* 172: of_queue_desc_stats_request */
    16,   /* 173: of_queue_get_config_reply */
    16,   /* 174: of_queue_get_config_request */
    12,   /* 175: of_queue_op_failed_error_msg */
    16,   /* 176: of_queue_stats_reply */
    24,   /* 177: of_queue_stats_request */
    -1,   /* 178: of_requestforward */
    24,   /* 179: of_role_reply */
    24,   /* 180: of_role_request */
    12,   /* 181: of_role_request_failed_error_msg */
    -1,   /* 182: of_role_status */
    12,   /* 183: of_set_config */
    16,   /* 184: of_stats_reply */
    16,   /* 185: of_stats_request */
    12,   /* 186: of_switch_config_failed_error_msg */
    -1,   /* 187: of_table_desc_stats_reply */
    -1,   /* 188: of_table_desc_stats_request */
    12,   /* 189: of_table_features_failed_error_msg */
    16,   /* 190: of_table_features_stats_reply */
    16,   /* 191: of_table_features_stats_request */
    16,   /* 192: of_table_mod */
    12,   /* 193: of_table_mod_failed_error_msg */
    16,   /* 194: of_table_stats_reply */
    16,   /* 195: of_table_stats_request */
    -1,   /* 196: of_table_status */
    8,    /* 197: of_action */
    16,   /* 198: of_action_bsn */
    28,   /* 199: of_action_bsn_checksum */
    16,   /* 200: of_action_bsn_gentable */
    24,   /* 201: of_action_bsn_mirror */
    16,   /* 202: of_action_bsn_set_tunnel_dst */
    8,    /* 203: of_action_copy_ttl_in */
    8,    /* 204: of_action_copy_ttl_out */
    8,    /* 205: of_action_dec_mpls_ttl */
    8,    /* 206: of_action_dec_nw_ttl */
    -1,   /* 207: of_action_enqueue */
    8,    /* 208: of_action_experimenter */
    8,    /* 209: of_action_group */
    4,    /* 210: of_action_id */
    12,   /* 211: of_action_id_bsn */
    12,   /* 212: of_action_id_bsn_checksum */
    12,   /* 213: of_action_id_bsn_gentable */
    12,   /* 214: of_action_id_bsn_mirror */
    12,   /* 215: of_action_id_bsn_set_tunnel_dst */
    4,    /* 216: of_action_id_copy_ttl_in */
    4,    /* 217: of_action_id_copy_ttl_out */
    4,    /* 218: of_action_id_dec_mpls_ttl */
    4,    /* 219: of_action_id_dec_nw_ttl */
    8,    /* 220: of_action_id_experimenter */
    4,    /* 221: of_action_id_group */
    10,   /* 222: of_action_id_nicira */
    10,   /* 223: of_action_id_nicira_dec_ttl */
    4,    /* 224: of_action_id_output */
    4,    /* 225: of_action_id_pop_mpls */
    4,    /* 226: of_action_id_pop_pbb */
    4,    /* 227: of_action_id_pop_vlan */
    4,    /* 228: of_action_id_push_mpls */
    4,    /* 229: of_action_id_push_pbb */
    4,    /* 230: of_action_id_push_vlan */
    4,    /* 231: of_action_id_set_field */
    4,    /* 232: of_action_id_set_mpls_ttl */
    4,    /* 233: of_action_id_set_nw_ttl */
    4,    /* 234: of_action_id_set_queue */
    16,   /* 235: of_action_nicira */
    16,   /* 236: of_action_nicira_dec_ttl */
    16,   /* 237: of_action_output */
    8,    /* 238: of_action_pop_mpls */
    8,    /* 239: of_action_pop_pbb */
    8,    /* 240: of_action_pop_vlan */
    8,    /* 241: of_action_push_mpls */
    8,    /* 242: of_action_push_pbb */
    8,    /* 243: of_action_push_vlan */
    -1,   /* 244: of_action_set_dl_dst */
    -1,   /* 245: of_action_set_dl_src */
    8,    /* 246: of_action_set_field */
    -1,   /* 247: of_action_set_mpls_label */
    -1,   /* 248: of_action_set_mpls_tc */
    8,    /* 249: of_action_set_mpls_ttl */
    -1,   /* 250: of_action_set_nw_dst */
    -1,   /* 251: of_action_set_nw_ecn */
    -1,   /* 252: of_action_set_nw_src */
    -1,   /* 253: of_action_set_nw_tos */
    8,    /* 254: of_action_set_nw_ttl */
    8,    /* 255: of_action_set_queue */
    -1,   /* 256: of_action_set_tp_dst */
    -1,   /* 257: of_action_set_tp_src */
    -1,   /* 258: of_action_set_vlan_pcp */
    -1,   /* 259: of_action_set_vlan_vid */
    -1,   /* 260: of_action_strip_vlan */
    -1,   /* 261: of_async_config_prop */
    -1,   /* 262: of_async_config_prop_experimenter_master */
    -1,   /* 263: of_async_config_prop_experimenter_slave */
    -1,   /* 264: of_async_config_prop_flow_removed_master */
    -1,   /* 265: of_async_config_prop_flow_removed_slave */
    -1,   /* 266: of_async_config_prop_packet_in_master */
    -1,   /* 267: of_async_config_prop_packet_in_slave */
    -1,   /* 268: of_async_config_prop_port_status_master */
    -1,   /* 269: of_async_config_prop_port_status_slave */
    -1,   /* 270: of_async_config_prop_requestforward_master */
    -1,   /* 271: of_async_config_prop_requestforward_slave */
    -1,   /* 272: of_async_config_prop_role_status_master */
    -1,   /* 273: of_async_config_prop_role_status_slave */
    -1,   /* 274: of_async_config_prop_table_status_master */
    -1,   /* 275: of_async_config_prop_table_status_slave */
    264,  /* 276: of_bsn_controller_connection */
    328,  /* 277: of_bsn_debug_counter_desc_stats_entry */
    16,   /* 278: of_bsn_debug_counter_stats_entry */
    8,    /* 279: of_bsn_flow_checksum_bucket_stats_entry */
    2,    /* 280: of_bsn_generic_stats_entry */
    16,   /* 281: of_bsn_gentable_bucket_stats_entry */
    48,   /* 282: of_bsn_gentable_desc_stats_entry */
    20,   /* 283: of_bsn_gentable_entry_desc_stats_entry */
    4,    /* 284: of_bsn_gentable_entry_stats_entry */
    24,   /* 285: of_bsn_gentable_stats_entry */
    32,   /* 286: of_bsn_interface */
    36,   /* 287: of_bsn_lacp_stats_entry */
    8,    /* 288: of_bsn_port_counter_stats_entry */
    256,  /* 289: of_bsn_switch_pipeline_stats_entry */
    9,    /* 290: of_bsn_table_checksum_stats_entry */
    4,    /* 291: of_bsn_tlv */
    6,    /* 292: of_bsn_tlv_actor_key */
    6,    /* 293: of_bsn_tlv_actor_port_num */
    6,    /* 294: of_bsn_tlv_actor_port_priority */
    5,    /* 295: of_bsn_tlv_actor_state */
    10,   /* 296: of_bsn_tlv_actor_system_mac */
    6,    /* 297: of_bsn_tlv_actor_system_priority */
    8,    /* 298: of_bsn_tlv_broadcast_query_timeout */
    4,    /* 299: of_bsn_tlv_bucket */
    4,    /* 300: of_bsn_tlv_circuit_id */
    5,    /* 301: of_bsn_tlv_convergence_status */
    5,    /* 302: of_bsn_tlv_crc_enabled */
    4,    /* 303: of_bsn_tlv_data */
    10,   /* 304: of_bsn_tlv_eth_dst */
    10,   /* 305: of_bsn_tlv_eth_src */
    8,    /* 306: of_bsn_tlv_external_gateway_ip */
    10,   /* 307: of_bsn_tlv_external_gateway_mac */
    8,    /* 308: of_bsn_tlv_external_ip */
    10,   /* 309: of_bsn_tlv_external_mac */
    8,    /* 310: of_bsn_tlv_external_netmask */
    8,    /* 311: of_bsn_tlv_header_size */
    4,    /* 312: of_bsn_tlv_idle_notification */
    12,   /* 313: of_bsn_tlv_idle_time */
    8,    /* 314: of_bsn_tlv_idle_timeout */
    10,   /* 315: of_bsn_tlv_internal_gateway_mac */
    10,   /* 316: of_bsn_tlv_internal_mac */
    8,    /* 317: of_bsn_tlv_interval */
    8,    /* 318: of_bsn_tlv_ipv4 */
    8,    /* 319: of_bsn_tlv_ipv4_dst */
    8,    /* 320: of_bsn_tlv_ipv4_netmask */
    8,    /* 321: of_bsn_tlv_ipv4_src */
    10,   /* 322: of_bsn_tlv_mac */
    10,   /* 323: of_bsn_tlv_mac_mask */
    12,   /* 324: of_bsn_tlv_miss_packets */
    5,    /* 325: of_bsn_tlv_mpls_control_word */
    8,    /* 326: of_bsn_tlv_mpls_label */
    5,    /* 327: of_bsn_tlv_mpls_sequenced */
    4,    /* 328: of_bsn_tlv_name */
    6,    /* 329: of_bsn_tlv_partner_key */
    6,    /* 330: of_bsn_tlv_partner_port_num */
    6,    /* 331: of_bsn_tlv_partner_port_priority */
    5,    /* 332: of_bsn_tlv_partner_state */
    10,   /* 333: of_bsn_tlv_partner_system_mac */
    6,    /* 334: of_bsn_tlv_partner_system_priority */
    8,    /* 335: of_bsn_tlv_port */
    8,    /* 336: of_bsn_tlv_priority */
    8,    /* 337: of_bsn_tlv_queue_id */
    8,    /* 338: of_bsn_tlv_queue_weight */
    6,    /* 339: of_bsn_tlv_reference */
    12,   /* 340: of_bsn_tlv_reply_packets */
    12,   /* 341: of_bsn_tlv_request_packets */
    12,   /* 342: of_bsn_tlv_rx_packets */
    8,    /* 343: of_bsn_tlv_sampling_rate */
    8,    /* 344: of_bsn_tlv_sub_agent_id */
    12,   /* 345: of_bsn_tlv_tx_bytes */
    12,   /* 346: of_bsn_tlv_tx_packets */
    6,    /* 347: of_bsn_tlv_udf_anchor */
    6,    /* 348: of_bsn_tlv_udf_id */
    6,    /* 349: of_bsn_tlv_udf_length */
    6,    /* 350: of_bsn_tlv_udf_offset */
    6,    /* 351: of_bsn_tlv_udp_dst */
    6,    /* 352: of_bsn_tlv_udp_src */
    8,    /* 353: of_bsn_tlv_unicast_query_timeout */
    6,    /* 354: of_bsn_tlv_vlan_vid */
    8,    /* 355: of_bsn_tlv_vrf */
    8,    /* 356: of_bsn_vlan_counter_stats_entry */
    4,    /* 357: of_bsn_vport */
    64,   /* 358: of_bsn_vport_l2gre */
    32,   /* 359: of_bsn_vport_q_in_q */
    8,    /* 360: of_bsn_vrf_counter_stats_entry */
    16,   /* 361: of_bucket */
    16,   /* 362: of_bucket_counter */
    -1,   /* 363: of_bundle_prop */
    -1,   /* 364: of_bundle_prop_experimenter */
    56,   /* 365: of_flow_stats_entry */
    8,    /* 366: of_group_desc_stats_entry */
    40,   /* 367: of_group_stats_entry */
    4,    /* 368: of_hello_elem */
    4,    /* 369: of_hello_elem_versionbitmap */
    4,    /* 370: of_instruction */
    8,    /* 371: of_instruction_apply_actions */
    16,   /* 372: of_instruction_bsn */
    16,   /* 373: of_instruction_bsn_arp_offload */
    16,   /* 374: of_instruction_bsn_auto_negotiation */
    16,   /* 375: of_instruction_bsn_deny */
    16,   /* 376: of_instruction_bsn_dhcp_offload */
    16,   /* 377: of_instruction_bsn_disable_split_horizon_check */
    16,   /* 378: of_instruction_bsn_disable_src_mac_check */
    16,   /* 379: of_instruction_bsn_disable_vlan_counters */
    16,   /* 380: of_instruction_bsn_packet_of_death */
    16,   /* 381: of_instruction_bsn_permit */
    16,   /* 382: of_instruction_bsn_prioritize_pdus */
    16,   /* 383: of_instruction_bsn_require_vlan_xlate */
    16,   /* 384: of_instruction_bsn_span_destination */
    8,    /* 385: of_instruction_clear_actions */
    8,    /* 386: of_instruction_experimenter */
    8,    /* 387: of_instruction_goto_table */
    4,    /* 388: of_instruction_id */
    4,    /* 389: of_instruction_id_apply_actions */
    12,   /* 390: of_instruction_id_bsn */
    12,   /* 391: of_instruction_id_bsn_arp_offload */
    12,   /* 392: of_instruction_id_bsn_auto_negotiation */
    12,   /* 393: of_instruction_id_bsn_deny */
    12,   /* 394: of_instruction_id_bsn_dhcp_offload */
    12,   /* 395: of_instruction_id_bsn_disable_split_horizon_check */
    12,   /* 396: of_instruction_id_bsn_disable_src_mac_check */
    12,   /* 397: of_instruction_id_bsn_disable_vlan_counters */
    12,   /* 398: of_instruction_id_bsn_packet_of_death */
    12,   /* 399: of_instruction_id_bsn_permit */
    12,   /* 400: of_instruction_id_bsn_prioritize_pdus */
    12,   /* 401: of_instruction_id_bsn_require_vlan_xlate */
    12,   /* 402: of_instruction_id_bsn_span_destination */
    4,    /* 403: of_instruction_id_clear_actions */
    8,    /* 404: of_instruction_id_experimenter */
    4,    /* 405: of_instruction_id_goto_table */
    4,    /* 406: of_instruction_id_meter */
    4,    /* 407: of_instruction_id_write_actions */
    4,    /* 408: of_instruction_id_write_metadata */
    8,    /* 409: of_instruction_meter */
    8,    /* 410: of_instruction_write_actions */
    24,   /* 411: of_instruction_write_metadata */
    -1,   /* 412: of_match_v1 */
    -1,   /* 413: of_match_v2 */
    4,    /* 414: of_match_v3 */
    4,    /* 415: of_meter_band */
    16,   /* 416: of_meter_band_drop */
    16,   /* 417: of_meter_band_dscp_remark */
    16,   /* 418: of_meter_band_experimenter */
    16,   /* 419: of_meter_band_stats */
    8,    /* 420: of_meter_config */
    16,   /* 421: of_meter_features */
    40,   /* 422: of_meter_stats */
    4,    /* 423: of_oxm */
    6,    /* 424: of_oxm_arp_op */
    8,    /* 425: of_oxm_arp_op_masked */
    10,   /* 426: of_oxm_arp_sha */
    16,   /* 427: of_oxm_arp_sha_masked */
    8,    /* 428: of_oxm_arp_spa */
    12,   /* 429: of_oxm_arp_spa_masked */
    10,   /* 430: of_oxm_arp_tha */
    16,   /* 431: of_oxm_arp_tha_masked */
    8,    /* 432: of_oxm_arp_tpa */
    12,   /* 433: of_oxm_arp_tpa_masked */
    8,    /* 434: of_oxm_bsn_egr_port_group_id */
    12,   /* 435: of_oxm_bsn_egr_port_group_id_masked */
    5,    /* 436: of_oxm_bsn_global_vrf_allowed */
    6,    /* 437: of_oxm_bsn_global_vrf_allowed_masked */
    20,   /* 438: of_oxm_bsn_in_ports_128 */
    36,   /* 439: of_oxm_bsn_in_ports_128_masked */
    5,    /* 440: of_oxm_bsn_l2_cache_hit */
    6,    /* 441: of_oxm_bsn_l2_cache_hit_masked */
    8,    /* 442: of_oxm_bsn_l3_dst_class_id */
    12,   /* 443: of_oxm_bsn_l3_dst_class_id_masked */
    8,    /* 444: of_oxm_bsn_l3_interface_class_id */
    12,   /* 445: of_oxm_bsn_l3_interface_class_id_masked */
    8,    /* 446: of_oxm_bsn_l3_src_class_id */
    12,   /* 447: of_oxm_bsn_l3_src_class_id_masked */
    8,    /* 448: of_oxm_bsn_lag_id */
    12,   /* 449: of_oxm_bsn_lag_id_masked */
    6,    /* 450: of_oxm_bsn_tcp_flags */
    8,    /* 451: of_oxm_bsn_tcp_flags_masked */
    8,    /* 452: of_oxm_bsn_udf0 */
    12,   /* 453: of_oxm_bsn_udf0_masked */
    8,    /* 454: of_oxm_bsn_udf1 */
    12,   /* 455: of_oxm_bsn_udf1_masked */
    8,    /* 456: of_oxm_bsn_udf2 */
    12,   /* 457: of_oxm_bsn_udf2_masked */
    8,    /* 458: of_oxm_bsn_udf3 */
    12,   /* 459: of_oxm_bsn_udf3_masked */
    8,    /* 460: of_oxm_bsn_udf4 */
    12,   /* 461: of_oxm_bsn_udf4_masked */
    8,    /* 462: of_oxm_bsn_udf5 */
    12,   /* 463: of_oxm_bsn_udf5_masked */
    8,    /* 464: of_oxm_bsn_udf6 */
    12,   /* 465: of_oxm_bsn_udf6_masked */
    8,    /* 466: of_oxm_bsn_udf7 */
    12,   /* 467: of_oxm_bsn_udf7_masked */
    8,    /* 468: of_oxm_bsn_vlan_xlate_port_group_id */
    12,   /* 469: of_oxm_bsn_vlan_xlate_port_group_id_masked */
    8,    /* 470: of_oxm_bsn_vrf */
    12,   /* 471: of_oxm_bsn_vrf_masked */
    10,   /* 472: of_oxm_eth_dst */
    16,   /* 473: of_oxm_eth_dst_masked */
    10,   /* 474: of_oxm_eth_src */
    16,   /* 475: of_oxm_eth_src_masked */
    6,    /* 476: of_oxm_eth_type */
    8,    /* 477: of_oxm_eth_type_masked */
    5,    /* 478: of_oxm_icmpv4_code */
    6,    /* 479: of_oxm_icmpv4_code_masked */
    5,    /* 480: of_oxm_icmpv4_type */
    6,    /* 481: of_oxm_icmpv4_type_masked */
    5,    /* 482: of_oxm_icmpv6_code */
    6,    /* 483: of_oxm_icmpv6_code_masked */
    5,    /* 484: of_oxm_icmpv6_type */
    6,    /* 485: of_oxm_icmpv6_type_masked */
    8,    /* 486: of_oxm_in_phy_port */
    12,   /* 487: of_oxm_in_phy_port_masked */
    8,    /* 488: of_oxm_in_port */
    12,   /* 489: of_oxm_in_port_masked */
    5,    /* 490: of_oxm_ip_dscp */
    6,    /* 491: of_oxm_ip_dscp_masked */
    5,    /* 492: of_oxm_ip_ecn */
    6,    /* 493: of_oxm_ip_ecn_masked */
    5,    /* 494: of_oxm_ip_proto */
    6,    /* 495: of_oxm_ip_proto_masked */
    8,    /* 496: of_oxm_ipv4_dst */
    12,   /* 497: of_oxm_ipv4_dst_masked */
    8,    /* 498: of_oxm_ipv4_src */
    12,   /* 499: of_oxm_ipv4_src_masked */
    20,   /* 500: of_oxm_ipv6_dst */
    36,   /* 501: of_oxm_ipv6_dst_masked */
    6,    /* 502: of_oxm_ipv6_exthdr */
    8,    /* 503: of_oxm_ipv6_exthdr_masked */
    8,    /* 504: of_oxm_ipv6_flabel */
    12,   /* 505: of_oxm_ipv6_flabel_masked */
    10,   /* 506: of_oxm_ipv6_nd_sll */
    16,   /* 507: of_oxm_ipv6_nd_sll_masked */
    20,   /* 508: of_oxm_ipv6_nd_target */
    36,   /* 509: of_oxm_ipv6_nd_target_masked */
    10,   /* 510: of_oxm_ipv6_nd_tll */
    16,   /* 511: of_oxm_ipv6_nd_tll_masked */
    20,   /* 512: of_oxm_ipv6_src */
    36,   /* 513: of_oxm_ipv6_src_masked */
    12,   /* 514: of_oxm_metadata */
    20,   /* 515: of_oxm_metadata_masked */
    5,    /* 516: of_oxm_mpls_bos */
    6,    /* 517: of_oxm_mpls_bos_masked */
    8,    /* 518: of_oxm_mpls_label */
    12,   /* 519: of_oxm_mpls_label_masked */
    5,    /* 520: of_oxm_mpls_tc */
    6,    /* 521: of_oxm_mpls_tc_masked */
    -1,   /* 522: of_oxm_pbb_uca */
    -1,   /* 523: of_oxm_pbb_uca_masked */
    6,    /* 524: of_oxm_sctp_dst */
    8,    /* 525: of_oxm_sctp_dst_masked */
    6,    /* 526: of_oxm_sctp_src */
    8,    /* 527: of_oxm_sctp_src_masked */
    6,    /* 528: of_oxm_tcp_dst */
    8,    /* 529: of_oxm_tcp_dst_masked */
    6,    /* 530: of_oxm_tcp_src */
    8,    /* 531: of_oxm_tcp_src_masked */
    12,   /* 532: of_oxm_tunnel_id */
    20,   /* 533: of_oxm_tunnel_id_masked */
    8,    /* 534: of_oxm_tunnel_ipv4_dst */
    12,   /* 535: of_oxm_tunnel_ipv4_dst_masked */
    8,    /* 536: of_oxm_tunnel_ipv4_src */
    12,   /* 537: of_oxm_tunnel_ipv4_src_masked */
    6,    /* 538: of_oxm_udp_dst */
    8,    /* 539: of_oxm_udp_dst_masked */
    6,    /* 540: of_oxm_udp_src */
    8,    /* 541: of_oxm_udp_src_masked */
    5,    /* 542: of_oxm_vlan_pcp */
    6,    /* 543: of_oxm_vlan_pcp_masked */
    6,    /* 544: of_oxm_vlan_vid */
    8,    /* 545: of_oxm_vlan_vid_masked */
    16,   /* 546: of_packet_queue */
    64,   /* 547: of_port_desc */
    -1,   /* 548: of_port_desc_prop */
    -1,   /* 549: of_port_desc_prop_ethernet */
    -1,   /* 550: of_port_desc_prop_experimenter */
    -1,   /* 551: of_port_desc_prop_optical */
    -1,   /* 552: of_port_mod_prop */
    -1,   /* 553: of_port_mod_prop_ethernet */
    -1,   /* 554: of_port_mod_prop_experimenter */
    -1,   /* 555: of_port_mod_prop_optical */
    112,  /* 556: of_port_stats_entry */
    -1,   /* 557: of_port_stats_prop */
    -1,   /* 558: of_port_stats_prop_ethernet */
    -1,   /* 559: of_port_stats_prop_experimenter */
    -1,   /* 560: of_port_stats_prop_optical */
    -1,   /* 561: of_queue_desc */
    -1,   /* 562: of_queue_desc_prop */
    -1,   /* 563: of_queue_desc_prop_experimenter */
    -1,   /* 564: of_queue_desc_prop_max_rate */
    -1,   /* 565: of_queue_desc_prop_min_rate */
    8,    /* 566: of_queue_prop */
    16,   /* 567: of_queue_prop_experimenter */
    16,   /* 568: of_queue_prop_max_rate */
    16,   /* 569: of_queue_prop_min_rate */
    40,   /* 570: of_queue_stats_entry */
    -1,   /* 571: of_queue_stats_prop */
    -1,   /* 572: of_queue_stats_prop_experimenter */
    -1,   /* 573: of_role_prop */
    -1,   /* 574: of_role_prop_experimenter */
    -1,   /* 575: of_table_desc */
    4,    /* 576: of_table_feature_prop */
    4,    /* 577: of_table_feature_prop_apply_actions */
    4,    /* 578: of_table_feature_prop_apply_actions_miss */
    4,    /* 579: of_table_feature_prop_apply_setfield */
    4,    /* 580: of_table_feature_prop_apply_setfield_miss */
    12,   /* 581: of_table_feature_prop_experimenter */
    12,   /* 582: of_table_feature_prop_experimenter_miss */
    4,    /* 583: of_table_feature_prop_instructions */
    4,    /* 584: of_table_feature_prop_instructions_miss */
    4,    /* 585: of_table_feature_prop_match */
    4,    /* 586: of_table_feature_prop_next_tables */
    4,    /* 587: of_table_feature_prop_next_tables_miss */
    -1,   /* 588: of_table_feature_prop_table_sync_from */
    4,    /* 589: of_table_feature_prop_wildcards */
    4,    /* 590: of_table_feature_prop_write_actions */
    4,    /* 591: of_table_feature_prop_write_actions_miss */
    4,    /* 592: of_table_feature_prop_write_setfield */
    4,    /* 593: of_table_feature_prop_write_setfield_miss */
    64,   /* 594: of_table_features */
    -1,   /* 595: of_table_mod_prop */
    -1,   /* 596: of_table_mod_prop_eviction */
    -1,   /* 597: of_table_mod_prop_experimenter */
    -1,   /* 598: of_table_mod_prop_vacancy */
    24,   /* 599: of_table_stats_entry */
    4,    /* 600: of_uint32 */
    8,    /* 601: of_uint64 */
    1,    /* 602: of_uint8 */
    0,    /* 603: of_list_action */
    0,    /* 604: of_list_action_id */
    -1,   /* 605: of_list_async_config_prop */
    0,    /* 606: of_list_bsn_controller_connection */
    0,    /* 607: of_list_bsn_debug_counter_desc_stats_entry */
    0,    /* 608: of_list_bsn_debug_counter_stats_entry */
    0,    /* 609: of_list_bsn_flow_checksum_bucket_stats_entry */
    0,    /* 610: of_list_bsn_generic_stats_entry */
    0,    /* 611: of_list_bsn_gentable_bucket_stats_entry */
    0,    /* 612: of_list_bsn_gentable_desc_stats_entry */
    0,    /* 613: of_list_bsn_gentable_entry_desc_stats_entry */
    0,    /* 614: of_list_bsn_gentable_entry_stats_entry */
    0,    /* 615: of_list_bsn_gentable_stats_entry */
    0,    /* 616: of_list_bsn_interface */
    0,    /* 617: of_list_bsn_lacp_stats_entry */
    0,    /* 618: of_list_bsn_port_counter_stats_entry */
    0,    /* 619: of_list_bsn_switch_pipeline_stats_entry */
    0,    /* 620: of_list_bsn_table_checksum_stats_entry */
    0,    /* 621: of_list_bsn_tlv */
    0,    /* 622: of_list_bsn_vlan_counter_stats_entry */
    0,    /* 623: of_list_bsn_vrf_counter_stats_entry */
    0,    /* 624: of_list_bucket */
    0,    /* 625: of_list_bucket_counter */
    -1,   /* 626: of_list_bundle_prop */
    0,    /* 627: of_list_flow_stats_entry */
    0,    /* 628: of_list_group_desc_stats_entry */
    0,    /* 629: of_list_group_stats_entry */
    0,    /* 630: of_list_hello_elem */
    0,    /* 631: of_list_instruction */
    0,    /* 632: of_list_instruction_id */
    0,    /* 633: of_list_meter_band */
    0,    /* 634: of_list_meter_band_stats */
    0,    /* 635: of_list_meter_stats */
    0,    /* 636: of_list_oxm */
    0,    /* 637: of_list_packet_queue */
    0,    /* 638: of_list_port_desc */
    -1,   /* 639: of_list_port_desc_prop */
    -1,   /* 640: of_list_port_mod_prop */
    0,    /* 641: of_list_port_stats_entry */
    -1,   /* 642: of_list_port_stats_prop */
    -1,   /* 643: of_list_queue_desc */
    -1,   /* 644: of_list_queue_desc_prop */
    0,    /* 645: of_list_queue_prop */
    0,    /* 646: of_list_queue_stats_entry */
    -1,   /* 647: of_list_queue_stats_prop */
    -1,   /* 648: of_list_role_prop */
    -1,   /* 649: of_list_table_desc */
    0,    /* 650: of_list_table_feature_prop */
    0,    /* 651: of_list_table_features */
    -1,   /* 652: of_list_table_mod_prop */
    0,    /* 653: of_list_table_stats_entry */
    0,    /* 654: of_list_uint32 */
    0,    /* 655: of_list_uint64 */
    0     /* 656: of_list_uint8 */
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
    24,   /* 34: of_bsn_generic_stats_reply */
    88,   /* 35: of_bsn_generic_stats_request */
    24,   /* 36: of_bsn_gentable_bucket_stats_reply */
    26,   /* 37: of_bsn_gentable_bucket_stats_request */
    28,   /* 38: of_bsn_gentable_clear_reply */
    52,   /* 39: of_bsn_gentable_clear_request */
    24,   /* 40: of_bsn_gentable_desc_stats_reply */
    24,   /* 41: of_bsn_gentable_desc_stats_request */
    36,   /* 42: of_bsn_gentable_entry_add */
    18,   /* 43: of_bsn_gentable_entry_delete */
    24,   /* 44: of_bsn_gentable_entry_desc_stats_reply */
    60,   /* 45: of_bsn_gentable_entry_desc_stats_request */
    24,   /* 46: of_bsn_gentable_entry_stats_reply */
    60,   /* 47: of_bsn_gentable_entry_stats_request */
    24,   /* 48: of_bsn_gentable_set_buckets_size */
    24,   /* 49: of_bsn_gentable_stats_reply */
    24,   /* 50: of_bsn_gentable_stats_request */
    16,   /* 51: of_bsn_get_interfaces_reply */
    16,   /* 52: of_bsn_get_interfaces_request */
    -1,   /* 53: of_bsn_get_ip_mask_reply */
    -1,   /* 54: of_bsn_get_ip_mask_request */
    -1,   /* 55: of_bsn_get_l2_table_reply */
    -1,   /* 56: of_bsn_get_l2_table_request */
    20,   /* 57: of_bsn_get_mirroring_reply */
    20,   /* 58: of_bsn_get_mirroring_request */
    272,  /* 59: of_bsn_get_switch_pipeline_reply */
    16,   /* 60: of_bsn_get_switch_pipeline_request */
    16,   /* 61: of_bsn_header */
    -1,   /* 62: of_bsn_hybrid_get_reply */
    -1,   /* 63: of_bsn_hybrid_get_request */
    536,  /* 64: of_bsn_image_desc_stats_reply */
    24,   /* 65: of_bsn_image_desc_stats_request */
    52,   /* 66: of_bsn_lacp_convergence_notif */
    24,   /* 67: of_bsn_lacp_stats_reply */
    24,   /* 68: of_bsn_lacp_stats_request */
    17,   /* 69: of_bsn_log */
    25,   /* 70: of_bsn_pdu_rx_reply */
    28,   /* 71: of_bsn_pdu_rx_request */
    21,   /* 72: of_bsn_pdu_rx_timeout */
    25,   /* 73: of_bsn_pdu_tx_reply */
    28,   /* 74: of_bsn_pdu_tx_request */
    24,   /* 75: of_bsn_port_counter_stats_reply */
    28,   /* 76: of_bsn_port_counter_stats_request */
    -1,   /* 77: of_bsn_role_status */
    24,   /* 78: of_bsn_set_aux_cxns_reply */
    20,   /* 79: of_bsn_set_aux_cxns_request */
    -1,   /* 80: of_bsn_set_ip_mask */
    -1,   /* 81: of_bsn_set_l2_table_reply */
    -1,   /* 82: of_bsn_set_l2_table_request */
    24,   /* 83: of_bsn_set_lacp_reply */
    38,   /* 84: of_bsn_set_lacp_request */
    20,   /* 85: of_bsn_set_mirroring */
    20,   /* 86: of_bsn_set_pktin_suppression_reply */
    32,   /* 87: of_bsn_set_pktin_suppression_request */
    20,   /* 88: of_bsn_set_switch_pipeline_reply */
    272,  /* 89: of_bsn_set_switch_pipeline_request */
    -1,   /* 90: of_bsn_shell_command */
    -1,   /* 91: of_bsn_shell_output */
    -1,   /* 92: of_bsn_shell_status */
    24,   /* 93: of_bsn_stats_reply */
    24,   /* 94: of_bsn_stats_request */
    24,   /* 95: of_bsn_switch_pipeline_stats_reply */
    24,   /* 96: of_bsn_switch_pipeline_stats_request */
    24,   /* 97: of_bsn_table_checksum_stats_reply */
    24,   /* 98: of_bsn_table_checksum_stats_request */
    24,   /* 99: of_bsn_table_set_buckets_size */
    24,   /* 100: of_bsn_time_reply */
    16,   /* 101: of_bsn_time_request */
    24,   /* 102: of_bsn_virtual_port_create_reply */
    20,   /* 103: of_bsn_virtual_port_create_request */
    20,   /* 104: of_bsn_virtual_port_remove_reply */
    20,   /* 105: of_bsn_virtual_port_remove_request */
    24,   /* 106: of_bsn_vlan_counter_stats_reply */
    26,   /* 107: of_bsn_vlan_counter_stats_request */
    24,   /* 108: of_bsn_vrf_counter_stats_reply */
    28,   /* 109: of_bsn_vrf_counter_stats_request */
    16,   /* 110: of_bundle_add_msg */
    16,   /* 111: of_bundle_ctrl_msg */
    12,   /* 112: of_bundle_failed_error_msg */
    1072, /* 113: of_desc_stats_reply */
    16,   /* 114: of_desc_stats_request */
    8,    /* 115: of_echo_reply */
    8,    /* 116: of_echo_request */
    10,   /* 117: of_error_msg */
    16,   /* 118: of_experimenter */
    16,   /* 119: of_experimenter_error_msg */
    24,   /* 120: of_experimenter_stats_reply */
    24,   /* 121: of_experimenter_stats_request */
    32,   /* 122: of_features_reply */
    8,    /* 123: of_features_request */
    56,   /* 124: of_flow_add */
    56,   /* 125: of_flow_delete */
    56,   /* 126: of_flow_delete_strict */
    56,   /* 127: of_flow_mod */
    12,   /* 128: of_flow_mod_failed_error_msg */
    56,   /* 129: of_flow_modify */
    56,   /* 130: of_flow_modify_strict */
    12,   /* 131: of_flow_monitor_failed_error_msg */
    56,   /* 132: of_flow_removed */
    16,   /* 133: of_flow_stats_reply */
    56,   /* 134: of_flow_stats_request */
    12,   /* 135: of_get_config_reply */
    8,    /* 136: of_get_config_request */
    16,   /* 137: of_group_add */
    16,   /* 138: of_group_delete */
    16,   /* 139: of_group_desc_stats_reply */
    16,   /* 140: of_group_desc_stats_request */
    56,   /* 141: of_group_features_stats_reply */
    16,   /* 142: of_group_features_stats_request */
    16,   /* 143: of_group_mod */
    12,   /* 144: of_group_mod_failed_error_msg */
    16,   /* 145: of_group_modify */
    16,   /* 146: of_group_stats_reply */
    24,   /* 147: of_group_stats_request */
    8,    /* 148: of_header */
    8,    /* 149: of_hello */
    12,   /* 150: of_hello_failed_error_msg */
    16,   /* 151: of_meter_config_stats_reply */
    24,   /* 152: of_meter_config_stats_request */
    32,   /* 153: of_meter_features_stats_reply */
    16,   /* 154: of_meter_features_stats_request */
    16,   /* 155: of_meter_mod */
    12,   /* 156: of_meter_mod_failed_error_msg */
    16,   /* 157: of_meter_stats_reply */
    24,   /* 158: of_meter_stats_request */
    -1,   /* 159: of_nicira_controller_role_reply */
    -1,   /* 160: of_nicira_controller_role_request */
    16,   /* 161: of_nicira_header */
    34,   /* 162: of_packet_in */
    24,   /* 163: of_packet_out */
    16,   /* 164: of_port_desc_stats_reply */
    16,   /* 165: of_port_desc_stats_request */
    32,   /* 166: of_port_mod */
    12,   /* 167: of_port_mod_failed_error_msg */
    16,   /* 168: of_port_stats_reply */
    24,   /* 169: of_port_stats_request */
    56,   /* 170: of_port_status */
    16,   /* 171: of_queue_desc_stats_reply */
    16,   /* 172: of_queue_desc_stats_request */
    -1,   /* 173: of_queue_get_config_reply */
    -1,   /* 174: of_queue_get_config_request */
    12,   /* 175: of_queue_op_failed_error_msg */
    16,   /* 176: of_queue_stats_reply */
    24,   /* 177: of_queue_stats_request */
    12,   /* 178: of_requestforward */
    24,   /* 179: of_role_reply */
    24,   /* 180: of_role_request */
    12,   /* 181: of_role_request_failed_error_msg */
    24,   /* 182: of_role_status */
    12,   /* 183: of_set_config */
    16,   /* 184: of_stats_reply */
    16,   /* 185: of_stats_request */
    12,   /* 186: of_switch_config_failed_error_msg */
    16,   /* 187: of_table_desc_stats_reply */
    16,   /* 188: of_table_desc_stats_request */
    12,   /* 189: of_table_features_failed_error_msg */
    16,   /* 190: of_table_features_stats_reply */
    16,   /* 191: of_table_features_stats_request */
    16,   /* 192: of_table_mod */
    12,   /* 193: of_table_mod_failed_error_msg */
    16,   /* 194: of_table_stats_reply */
    16,   /* 195: of_table_stats_request */
    28,   /* 196: of_table_status */
    8,    /* 197: of_action */
    16,   /* 198: of_action_bsn */
    28,   /* 199: of_action_bsn_checksum */
    16,   /* 200: of_action_bsn_gentable */
    24,   /* 201: of_action_bsn_mirror */
    16,   /* 202: of_action_bsn_set_tunnel_dst */
    8,    /* 203: of_action_copy_ttl_in */
    8,    /* 204: of_action_copy_ttl_out */
    8,    /* 205: of_action_dec_mpls_ttl */
    8,    /* 206: of_action_dec_nw_ttl */
    -1,   /* 207: of_action_enqueue */
    8,    /* 208: of_action_experimenter */
    8,    /* 209: of_action_group */
    4,    /* 210: of_action_id */
    12,   /* 211: of_action_id_bsn */
    12,   /* 212: of_action_id_bsn_checksum */
    12,   /* 213: of_action_id_bsn_gentable */
    12,   /* 214: of_action_id_bsn_mirror */
    12,   /* 215: of_action_id_bsn_set_tunnel_dst */
    4,    /* 216: of_action_id_copy_ttl_in */
    4,    /* 217: of_action_id_copy_ttl_out */
    4,    /* 218: of_action_id_dec_mpls_ttl */
    4,    /* 219: of_action_id_dec_nw_ttl */
    8,    /* 220: of_action_id_experimenter */
    4,    /* 221: of_action_id_group */
    10,   /* 222: of_action_id_nicira */
    10,   /* 223: of_action_id_nicira_dec_ttl */
    4,    /* 224: of_action_id_output */
    4,    /* 225: of_action_id_pop_mpls */
    4,    /* 226: of_action_id_pop_pbb */
    4,    /* 227: of_action_id_pop_vlan */
    4,    /* 228: of_action_id_push_mpls */
    4,    /* 229: of_action_id_push_pbb */
    4,    /* 230: of_action_id_push_vlan */
    4,    /* 231: of_action_id_set_field */
    4,    /* 232: of_action_id_set_mpls_ttl */
    4,    /* 233: of_action_id_set_nw_ttl */
    4,    /* 234: of_action_id_set_queue */
    16,   /* 235: of_action_nicira */
    16,   /* 236: of_action_nicira_dec_ttl */
    16,   /* 237: of_action_output */
    8,    /* 238: of_action_pop_mpls */
    8,    /* 239: of_action_pop_pbb */
    8,    /* 240: of_action_pop_vlan */
    8,    /* 241: of_action_push_mpls */
    8,    /* 242: of_action_push_pbb */
    8,    /* 243: of_action_push_vlan */
    -1,   /* 244: of_action_set_dl_dst */
    -1,   /* 245: of_action_set_dl_src */
    8,    /* 246: of_action_set_field */
    -1,   /* 247: of_action_set_mpls_label */
    -1,   /* 248: of_action_set_mpls_tc */
    8,    /* 249: of_action_set_mpls_ttl */
    -1,   /* 250: of_action_set_nw_dst */
    -1,   /* 251: of_action_set_nw_ecn */
    -1,   /* 252: of_action_set_nw_src */
    -1,   /* 253: of_action_set_nw_tos */
    8,    /* 254: of_action_set_nw_ttl */
    8,    /* 255: of_action_set_queue */
    -1,   /* 256: of_action_set_tp_dst */
    -1,   /* 257: of_action_set_tp_src */
    -1,   /* 258: of_action_set_vlan_pcp */
    -1,   /* 259: of_action_set_vlan_vid */
    -1,   /* 260: of_action_strip_vlan */
    4,    /* 261: of_async_config_prop */
    4,    /* 262: of_async_config_prop_experimenter_master */
    4,    /* 263: of_async_config_prop_experimenter_slave */
    8,    /* 264: of_async_config_prop_flow_removed_master */
    8,    /* 265: of_async_config_prop_flow_removed_slave */
    8,    /* 266: of_async_config_prop_packet_in_master */
    8,    /* 267: of_async_config_prop_packet_in_slave */
    8,    /* 268: of_async_config_prop_port_status_master */
    8,    /* 269: of_async_config_prop_port_status_slave */
    8,    /* 270: of_async_config_prop_requestforward_master */
    8,    /* 271: of_async_config_prop_requestforward_slave */
    8,    /* 272: of_async_config_prop_role_status_master */
    8,    /* 273: of_async_config_prop_role_status_slave */
    8,    /* 274: of_async_config_prop_table_status_master */
    8,    /* 275: of_async_config_prop_table_status_slave */
    264,  /* 276: of_bsn_controller_connection */
    328,  /* 277: of_bsn_debug_counter_desc_stats_entry */
    16,   /* 278: of_bsn_debug_counter_stats_entry */
    8,    /* 279: of_bsn_flow_checksum_bucket_stats_entry */
    2,    /* 280: of_bsn_generic_stats_entry */
    16,   /* 281: of_bsn_gentable_bucket_stats_entry */
    48,   /* 282: of_bsn_gentable_desc_stats_entry */
    20,   /* 283: of_bsn_gentable_entry_desc_stats_entry */
    4,    /* 284: of_bsn_gentable_entry_stats_entry */
    24,   /* 285: of_bsn_gentable_stats_entry */
    32,   /* 286: of_bsn_interface */
    36,   /* 287: of_bsn_lacp_stats_entry */
    8,    /* 288: of_bsn_port_counter_stats_entry */
    256,  /* 289: of_bsn_switch_pipeline_stats_entry */
    9,    /* 290: of_bsn_table_checksum_stats_entry */
    4,    /* 291: of_bsn_tlv */
    6,    /* 292: of_bsn_tlv_actor_key */
    6,    /* 293: of_bsn_tlv_actor_port_num */
    6,    /* 294: of_bsn_tlv_actor_port_priority */
    5,    /* 295: of_bsn_tlv_actor_state */
    10,   /* 296: of_bsn_tlv_actor_system_mac */
    6,    /* 297: of_bsn_tlv_actor_system_priority */
    8,    /* 298: of_bsn_tlv_broadcast_query_timeout */
    4,    /* 299: of_bsn_tlv_bucket */
    4,    /* 300: of_bsn_tlv_circuit_id */
    5,    /* 301: of_bsn_tlv_convergence_status */
    5,    /* 302: of_bsn_tlv_crc_enabled */
    4,    /* 303: of_bsn_tlv_data */
    10,   /* 304: of_bsn_tlv_eth_dst */
    10,   /* 305: of_bsn_tlv_eth_src */
    8,    /* 306: of_bsn_tlv_external_gateway_ip */
    10,   /* 307: of_bsn_tlv_external_gateway_mac */
    8,    /* 308: of_bsn_tlv_external_ip */
    10,   /* 309: of_bsn_tlv_external_mac */
    8,    /* 310: of_bsn_tlv_external_netmask */
    8,    /* 311: of_bsn_tlv_header_size */
    4,    /* 312: of_bsn_tlv_idle_notification */
    12,   /* 313: of_bsn_tlv_idle_time */
    8,    /* 314: of_bsn_tlv_idle_timeout */
    10,   /* 315: of_bsn_tlv_internal_gateway_mac */
    10,   /* 316: of_bsn_tlv_internal_mac */
    8,    /* 317: of_bsn_tlv_interval */
    8,    /* 318: of_bsn_tlv_ipv4 */
    8,    /* 319: of_bsn_tlv_ipv4_dst */
    8,    /* 320: of_bsn_tlv_ipv4_netmask */
    8,    /* 321: of_bsn_tlv_ipv4_src */
    10,   /* 322: of_bsn_tlv_mac */
    10,   /* 323: of_bsn_tlv_mac_mask */
    12,   /* 324: of_bsn_tlv_miss_packets */
    5,    /* 325: of_bsn_tlv_mpls_control_word */
    8,    /* 326: of_bsn_tlv_mpls_label */
    5,    /* 327: of_bsn_tlv_mpls_sequenced */
    4,    /* 328: of_bsn_tlv_name */
    6,    /* 329: of_bsn_tlv_partner_key */
    6,    /* 330: of_bsn_tlv_partner_port_num */
    6,    /* 331: of_bsn_tlv_partner_port_priority */
    5,    /* 332: of_bsn_tlv_partner_state */
    10,   /* 333: of_bsn_tlv_partner_system_mac */
    6,    /* 334: of_bsn_tlv_partner_system_priority */
    8,    /* 335: of_bsn_tlv_port */
    8,    /* 336: of_bsn_tlv_priority */
    8,    /* 337: of_bsn_tlv_queue_id */
    8,    /* 338: of_bsn_tlv_queue_weight */
    6,    /* 339: of_bsn_tlv_reference */
    12,   /* 340: of_bsn_tlv_reply_packets */
    12,   /* 341: of_bsn_tlv_request_packets */
    12,   /* 342: of_bsn_tlv_rx_packets */
    8,    /* 343: of_bsn_tlv_sampling_rate */
    8,    /* 344: of_bsn_tlv_sub_agent_id */
    12,   /* 345: of_bsn_tlv_tx_bytes */
    12,   /* 346: of_bsn_tlv_tx_packets */
    6,    /* 347: of_bsn_tlv_udf_anchor */
    6,    /* 348: of_bsn_tlv_udf_id */
    6,    /* 349: of_bsn_tlv_udf_length */
    6,    /* 350: of_bsn_tlv_udf_offset */
    6,    /* 351: of_bsn_tlv_udp_dst */
    6,    /* 352: of_bsn_tlv_udp_src */
    8,    /* 353: of_bsn_tlv_unicast_query_timeout */
    6,    /* 354: of_bsn_tlv_vlan_vid */
    8,    /* 355: of_bsn_tlv_vrf */
    8,    /* 356: of_bsn_vlan_counter_stats_entry */
    4,    /* 357: of_bsn_vport */
    64,   /* 358: of_bsn_vport_l2gre */
    32,   /* 359: of_bsn_vport_q_in_q */
    8,    /* 360: of_bsn_vrf_counter_stats_entry */
    16,   /* 361: of_bucket */
    16,   /* 362: of_bucket_counter */
    4,    /* 363: of_bundle_prop */
    12,   /* 364: of_bundle_prop_experimenter */
    56,   /* 365: of_flow_stats_entry */
    8,    /* 366: of_group_desc_stats_entry */
    40,   /* 367: of_group_stats_entry */
    4,    /* 368: of_hello_elem */
    4,    /* 369: of_hello_elem_versionbitmap */
    4,    /* 370: of_instruction */
    8,    /* 371: of_instruction_apply_actions */
    16,   /* 372: of_instruction_bsn */
    16,   /* 373: of_instruction_bsn_arp_offload */
    16,   /* 374: of_instruction_bsn_auto_negotiation */
    16,   /* 375: of_instruction_bsn_deny */
    16,   /* 376: of_instruction_bsn_dhcp_offload */
    -1,   /* 377: of_instruction_bsn_disable_split_horizon_check */
    16,   /* 378: of_instruction_bsn_disable_src_mac_check */
    16,   /* 379: of_instruction_bsn_disable_vlan_counters */
    16,   /* 380: of_instruction_bsn_packet_of_death */
    16,   /* 381: of_instruction_bsn_permit */
    16,   /* 382: of_instruction_bsn_prioritize_pdus */
    16,   /* 383: of_instruction_bsn_require_vlan_xlate */
    16,   /* 384: of_instruction_bsn_span_destination */
    8,    /* 385: of_instruction_clear_actions */
    8,    /* 386: of_instruction_experimenter */
    8,    /* 387: of_instruction_goto_table */
    4,    /* 388: of_instruction_id */
    4,    /* 389: of_instruction_id_apply_actions */
    12,   /* 390: of_instruction_id_bsn */
    12,   /* 391: of_instruction_id_bsn_arp_offload */
    12,   /* 392: of_instruction_id_bsn_auto_negotiation */
    12,   /* 393: of_instruction_id_bsn_deny */
    12,   /* 394: of_instruction_id_bsn_dhcp_offload */
    -1,   /* 395: of_instruction_id_bsn_disable_split_horizon_check */
    12,   /* 396: of_instruction_id_bsn_disable_src_mac_check */
    12,   /* 397: of_instruction_id_bsn_disable_vlan_counters */
    12,   /* 398: of_instruction_id_bsn_packet_of_death */
    12,   /* 399: of_instruction_id_bsn_permit */
    12,   /* 400: of_instruction_id_bsn_prioritize_pdus */
    12,   /* 401: of_instruction_id_bsn_require_vlan_xlate */
    12,   /* 402: of_instruction_id_bsn_span_destination */
    4,    /* 403: of_instruction_id_clear_actions */
    8,    /* 404: of_instruction_id_experimenter */
    4,    /* 405: of_instruction_id_goto_table */
    4,    /* 406: of_instruction_id_meter */
    4,    /* 407: of_instruction_id_write_actions */
    4,    /* 408: of_instruction_id_write_metadata */
    8,    /* 409: of_instruction_meter */
    8,    /* 410: of_instruction_write_actions */
    24,   /* 411: of_instruction_write_metadata */
    -1,   /* 412: of_match_v1 */
    -1,   /* 413: of_match_v2 */
    4,    /* 414: of_match_v3 */
    4,    /* 415: of_meter_band */
    16,   /* 416: of_meter_band_drop */
    16,   /* 417: of_meter_band_dscp_remark */
    16,   /* 418: of_meter_band_experimenter */
    16,   /* 419: of_meter_band_stats */
    8,    /* 420: of_meter_config */
    16,   /* 421: of_meter_features */
    40,   /* 422: of_meter_stats */
    4,    /* 423: of_oxm */
    6,    /* 424: of_oxm_arp_op */
    8,    /* 425: of_oxm_arp_op_masked */
    10,   /* 426: of_oxm_arp_sha */
    16,   /* 427: of_oxm_arp_sha_masked */
    8,    /* 428: of_oxm_arp_spa */
    12,   /* 429: of_oxm_arp_spa_masked */
    10,   /* 430: of_oxm_arp_tha */
    16,   /* 431: of_oxm_arp_tha_masked */
    8,    /* 432: of_oxm_arp_tpa */
    12,   /* 433: of_oxm_arp_tpa_masked */
    8,    /* 434: of_oxm_bsn_egr_port_group_id */
    12,   /* 435: of_oxm_bsn_egr_port_group_id_masked */
    -1,   /* 436: of_oxm_bsn_global_vrf_allowed */
    -1,   /* 437: of_oxm_bsn_global_vrf_allowed_masked */
    20,   /* 438: of_oxm_bsn_in_ports_128 */
    36,   /* 439: of_oxm_bsn_in_ports_128_masked */
    -1,   /* 440: of_oxm_bsn_l2_cache_hit */
    -1,   /* 441: of_oxm_bsn_l2_cache_hit_masked */
    -1,   /* 442: of_oxm_bsn_l3_dst_class_id */
    -1,   /* 443: of_oxm_bsn_l3_dst_class_id_masked */
    8,    /* 444: of_oxm_bsn_l3_interface_class_id */
    12,   /* 445: of_oxm_bsn_l3_interface_class_id_masked */
    8,    /* 446: of_oxm_bsn_l3_src_class_id */
    12,   /* 447: of_oxm_bsn_l3_src_class_id_masked */
    8,    /* 448: of_oxm_bsn_lag_id */
    12,   /* 449: of_oxm_bsn_lag_id_masked */
    6,    /* 450: of_oxm_bsn_tcp_flags */
    8,    /* 451: of_oxm_bsn_tcp_flags_masked */
    8,    /* 452: of_oxm_bsn_udf0 */
    12,   /* 453: of_oxm_bsn_udf0_masked */
    8,    /* 454: of_oxm_bsn_udf1 */
    12,   /* 455: of_oxm_bsn_udf1_masked */
    8,    /* 456: of_oxm_bsn_udf2 */
    12,   /* 457: of_oxm_bsn_udf2_masked */
    8,    /* 458: of_oxm_bsn_udf3 */
    12,   /* 459: of_oxm_bsn_udf3_masked */
    8,    /* 460: of_oxm_bsn_udf4 */
    12,   /* 461: of_oxm_bsn_udf4_masked */
    8,    /* 462: of_oxm_bsn_udf5 */
    12,   /* 463: of_oxm_bsn_udf5_masked */
    8,    /* 464: of_oxm_bsn_udf6 */
    12,   /* 465: of_oxm_bsn_udf6_masked */
    8,    /* 466: of_oxm_bsn_udf7 */
    12,   /* 467: of_oxm_bsn_udf7_masked */
    8,    /* 468: of_oxm_bsn_vlan_xlate_port_group_id */
    12,   /* 469: of_oxm_bsn_vlan_xlate_port_group_id_masked */
    8,    /* 470: of_oxm_bsn_vrf */
    12,   /* 471: of_oxm_bsn_vrf_masked */
    10,   /* 472: of_oxm_eth_dst */
    16,   /* 473: of_oxm_eth_dst_masked */
    10,   /* 474: of_oxm_eth_src */
    16,   /* 475: of_oxm_eth_src_masked */
    6,    /* 476: of_oxm_eth_type */
    8,    /* 477: of_oxm_eth_type_masked */
    5,    /* 478: of_oxm_icmpv4_code */
    6,    /* 479: of_oxm_icmpv4_code_masked */
    5,    /* 480: of_oxm_icmpv4_type */
    6,    /* 481: of_oxm_icmpv4_type_masked */
    5,    /* 482: of_oxm_icmpv6_code */
    6,    /* 483: of_oxm_icmpv6_code_masked */
    5,    /* 484: of_oxm_icmpv6_type */
    6,    /* 485: of_oxm_icmpv6_type_masked */
    8,    /* 486: of_oxm_in_phy_port */
    12,   /* 487: of_oxm_in_phy_port_masked */
    8,    /* 488: of_oxm_in_port */
    12,   /* 489: of_oxm_in_port_masked */
    5,    /* 490: of_oxm_ip_dscp */
    6,    /* 491: of_oxm_ip_dscp_masked */
    5,    /* 492: of_oxm_ip_ecn */
    6,    /* 493: of_oxm_ip_ecn_masked */
    5,    /* 494: of_oxm_ip_proto */
    6,    /* 495: of_oxm_ip_proto_masked */
    8,    /* 496: of_oxm_ipv4_dst */
    12,   /* 497: of_oxm_ipv4_dst_masked */
    8,    /* 498: of_oxm_ipv4_src */
    12,   /* 499: of_oxm_ipv4_src_masked */
    20,   /* 500: of_oxm_ipv6_dst */
    36,   /* 501: of_oxm_ipv6_dst_masked */
    6,    /* 502: of_oxm_ipv6_exthdr */
    8,    /* 503: of_oxm_ipv6_exthdr_masked */
    8,    /* 504: of_oxm_ipv6_flabel */
    12,   /* 505: of_oxm_ipv6_flabel_masked */
    10,   /* 506: of_oxm_ipv6_nd_sll */
    16,   /* 507: of_oxm_ipv6_nd_sll_masked */
    20,   /* 508: of_oxm_ipv6_nd_target */
    36,   /* 509: of_oxm_ipv6_nd_target_masked */
    10,   /* 510: of_oxm_ipv6_nd_tll */
    16,   /* 511: of_oxm_ipv6_nd_tll_masked */
    20,   /* 512: of_oxm_ipv6_src */
    36,   /* 513: of_oxm_ipv6_src_masked */
    12,   /* 514: of_oxm_metadata */
    20,   /* 515: of_oxm_metadata_masked */
    5,    /* 516: of_oxm_mpls_bos */
    6,    /* 517: of_oxm_mpls_bos_masked */
    8,    /* 518: of_oxm_mpls_label */
    12,   /* 519: of_oxm_mpls_label_masked */
    5,    /* 520: of_oxm_mpls_tc */
    6,    /* 521: of_oxm_mpls_tc_masked */
    5,    /* 522: of_oxm_pbb_uca */
    6,    /* 523: of_oxm_pbb_uca_masked */
    6,    /* 524: of_oxm_sctp_dst */
    8,    /* 525: of_oxm_sctp_dst_masked */
    6,    /* 526: of_oxm_sctp_src */
    8,    /* 527: of_oxm_sctp_src_masked */
    6,    /* 528: of_oxm_tcp_dst */
    8,    /* 529: of_oxm_tcp_dst_masked */
    6,    /* 530: of_oxm_tcp_src */
    8,    /* 531: of_oxm_tcp_src_masked */
    12,   /* 532: of_oxm_tunnel_id */
    20,   /* 533: of_oxm_tunnel_id_masked */
    8,    /* 534: of_oxm_tunnel_ipv4_dst */
    12,   /* 535: of_oxm_tunnel_ipv4_dst_masked */
    8,    /* 536: of_oxm_tunnel_ipv4_src */
    12,   /* 537: of_oxm_tunnel_ipv4_src_masked */
    6,    /* 538: of_oxm_udp_dst */
    8,    /* 539: of_oxm_udp_dst_masked */
    6,    /* 540: of_oxm_udp_src */
    8,    /* 541: of_oxm_udp_src_masked */
    5,    /* 542: of_oxm_vlan_pcp */
    6,    /* 543: of_oxm_vlan_pcp_masked */
    6,    /* 544: of_oxm_vlan_vid */
    8,    /* 545: of_oxm_vlan_vid_masked */
    16,   /* 546: of_packet_queue */
    40,   /* 547: of_port_desc */
    4,    /* 548: of_port_desc_prop */
    32,   /* 549: of_port_desc_prop_ethernet */
    12,   /* 550: of_port_desc_prop_experimenter */
    44,   /* 551: of_port_desc_prop_optical */
    4,    /* 552: of_port_mod_prop */
    8,    /* 553: of_port_mod_prop_ethernet */
    12,   /* 554: of_port_mod_prop_experimenter */
    24,   /* 555: of_port_mod_prop_optical */
    80,   /* 556: of_port_stats_entry */
    4,    /* 557: of_port_stats_prop */
    40,   /* 558: of_port_stats_prop_ethernet */
    12,   /* 559: of_port_stats_prop_experimenter */
    44,   /* 560: of_port_stats_prop_optical */
    16,   /* 561: of_queue_desc */
    4,    /* 562: of_queue_desc_prop */
    12,   /* 563: of_queue_desc_prop_experimenter */
    8,    /* 564: of_queue_desc_prop_max_rate */
    8,    /* 565: of_queue_desc_prop_min_rate */
    8,    /* 566: of_queue_prop */
    16,   /* 567: of_queue_prop_experimenter */
    16,   /* 568: of_queue_prop_max_rate */
    16,   /* 569: of_queue_prop_min_rate */
    48,   /* 570: of_queue_stats_entry */
    4,    /* 571: of_queue_stats_prop */
    12,   /* 572: of_queue_stats_prop_experimenter */
    4,    /* 573: of_role_prop */
    12,   /* 574: of_role_prop_experimenter */
    8,    /* 575: of_table_desc */
    4,    /* 576: of_table_feature_prop */
    4,    /* 577: of_table_feature_prop_apply_actions */
    4,    /* 578: of_table_feature_prop_apply_actions_miss */
    4,    /* 579: of_table_feature_prop_apply_setfield */
    4,    /* 580: of_table_feature_prop_apply_setfield_miss */
    12,   /* 581: of_table_feature_prop_experimenter */
    12,   /* 582: of_table_feature_prop_experimenter_miss */
    4,    /* 583: of_table_feature_prop_instructions */
    4,    /* 584: of_table_feature_prop_instructions_miss */
    4,    /* 585: of_table_feature_prop_match */
    4,    /* 586: of_table_feature_prop_next_tables */
    4,    /* 587: of_table_feature_prop_next_tables_miss */
    4,    /* 588: of_table_feature_prop_table_sync_from */
    4,    /* 589: of_table_feature_prop_wildcards */
    4,    /* 590: of_table_feature_prop_write_actions */
    4,    /* 591: of_table_feature_prop_write_actions_miss */
    4,    /* 592: of_table_feature_prop_write_setfield */
    4,    /* 593: of_table_feature_prop_write_setfield_miss */
    64,   /* 594: of_table_features */
    4,    /* 595: of_table_mod_prop */
    8,    /* 596: of_table_mod_prop_eviction */
    12,   /* 597: of_table_mod_prop_experimenter */
    8,    /* 598: of_table_mod_prop_vacancy */
    24,   /* 599: of_table_stats_entry */
    4,    /* 600: of_uint32 */
    8,    /* 601: of_uint64 */
    1,    /* 602: of_uint8 */
    0,    /* 603: of_list_action */
    0,    /* 604: of_list_action_id */
    0,    /* 605: of_list_async_config_prop */
    0,    /* 606: of_list_bsn_controller_connection */
    0,    /* 607: of_list_bsn_debug_counter_desc_stats_entry */
    0,    /* 608: of_list_bsn_debug_counter_stats_entry */
    0,    /* 609: of_list_bsn_flow_checksum_bucket_stats_entry */
    0,    /* 610: of_list_bsn_generic_stats_entry */
    0,    /* 611: of_list_bsn_gentable_bucket_stats_entry */
    0,    /* 612: of_list_bsn_gentable_desc_stats_entry */
    0,    /* 613: of_list_bsn_gentable_entry_desc_stats_entry */
    0,    /* 614: of_list_bsn_gentable_entry_stats_entry */
    0,    /* 615: of_list_bsn_gentable_stats_entry */
    0,    /* 616: of_list_bsn_interface */
    0,    /* 617: of_list_bsn_lacp_stats_entry */
    0,    /* 618: of_list_bsn_port_counter_stats_entry */
    0,    /* 619: of_list_bsn_switch_pipeline_stats_entry */
    0,    /* 620: of_list_bsn_table_checksum_stats_entry */
    0,    /* 621: of_list_bsn_tlv */
    0,    /* 622: of_list_bsn_vlan_counter_stats_entry */
    0,    /* 623: of_list_bsn_vrf_counter_stats_entry */
    0,    /* 624: of_list_bucket */
    0,    /* 625: of_list_bucket_counter */
    0,    /* 626: of_list_bundle_prop */
    0,    /* 627: of_list_flow_stats_entry */
    0,    /* 628: of_list_group_desc_stats_entry */
    0,    /* 629: of_list_group_stats_entry */
    0,    /* 630: of_list_hello_elem */
    0,    /* 631: of_list_instruction */
    0,    /* 632: of_list_instruction_id */
    0,    /* 633: of_list_meter_band */
    0,    /* 634: of_list_meter_band_stats */
    0,    /* 635: of_list_meter_stats */
    0,    /* 636: of_list_oxm */
    -1,   /* 637: of_list_packet_queue */
    0,    /* 638: of_list_port_desc */
    0,    /* 639: of_list_port_desc_prop */
    0,    /* 640: of_list_port_mod_prop */
    0,    /* 641: of_list_port_stats_entry */
    0,    /* 642: of_list_port_stats_prop */
    0,    /* 643: of_list_queue_desc */
    0,    /* 644: of_list_queue_desc_prop */
    0,    /* 645: of_list_queue_prop */
    0,    /* 646: of_list_queue_stats_entry */
    0,    /* 647: of_list_queue_stats_prop */
    0,    /* 648: of_list_role_prop */
    0,    /* 649: of_list_table_desc */
    0,    /* 650: of_list_table_feature_prop */
    0,    /* 651: of_list_table_features */
    0,    /* 652: of_list_table_mod_prop */
    0,    /* 653: of_list_table_stats_entry */
    0,    /* 654: of_list_uint32 */
    0,    /* 655: of_list_uint64 */
    0     /* 656: of_list_uint8 */
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
