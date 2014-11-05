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
    -1,   /* 3: of_async_get_reply */
    -1,   /* 4: of_async_get_request */
    -1,   /* 5: of_async_set */
    12,   /* 6: of_bad_action_error_msg */
    -1,   /* 7: of_bad_instruction_error_msg */
    -1,   /* 8: of_bad_match_error_msg */
    12,   /* 9: of_bad_request_error_msg */
    8,    /* 10: of_barrier_reply */
    8,    /* 11: of_barrier_request */
    -1,   /* 12: of_bsn_arp_idle */
    20,   /* 13: of_bsn_bw_clear_data_reply */
    16,   /* 14: of_bsn_bw_clear_data_request */
    20,   /* 15: of_bsn_bw_enable_get_reply */
    16,   /* 16: of_bsn_bw_enable_get_request */
    24,   /* 17: of_bsn_bw_enable_set_reply */
    20,   /* 18: of_bsn_bw_enable_set_request */
    -1,   /* 19: of_bsn_controller_connections_reply */
    -1,   /* 20: of_bsn_controller_connections_request */
    -1,   /* 21: of_bsn_debug_counter_desc_stats_reply */
    -1,   /* 22: of_bsn_debug_counter_desc_stats_request */
    -1,   /* 23: of_bsn_debug_counter_stats_reply */
    -1,   /* 24: of_bsn_debug_counter_stats_request */
    -1,   /* 25: of_bsn_flow_checksum_bucket_stats_reply */
    -1,   /* 26: of_bsn_flow_checksum_bucket_stats_request */
    -1,   /* 27: of_bsn_flow_idle */
    -1,   /* 28: of_bsn_flow_idle_enable_get_reply */
    -1,   /* 29: of_bsn_flow_idle_enable_get_request */
    -1,   /* 30: of_bsn_flow_idle_enable_set_reply */
    -1,   /* 31: of_bsn_flow_idle_enable_set_request */
    -1,   /* 32: of_bsn_gentable_bucket_stats_reply */
    -1,   /* 33: of_bsn_gentable_bucket_stats_request */
    -1,   /* 34: of_bsn_gentable_clear_reply */
    -1,   /* 35: of_bsn_gentable_clear_request */
    -1,   /* 36: of_bsn_gentable_desc_stats_reply */
    -1,   /* 37: of_bsn_gentable_desc_stats_request */
    -1,   /* 38: of_bsn_gentable_entry_add */
    -1,   /* 39: of_bsn_gentable_entry_delete */
    -1,   /* 40: of_bsn_gentable_entry_desc_stats_reply */
    -1,   /* 41: of_bsn_gentable_entry_desc_stats_request */
    -1,   /* 42: of_bsn_gentable_entry_stats_reply */
    -1,   /* 43: of_bsn_gentable_entry_stats_request */
    -1,   /* 44: of_bsn_gentable_set_buckets_size */
    -1,   /* 45: of_bsn_gentable_stats_reply */
    -1,   /* 46: of_bsn_gentable_stats_request */
    16,   /* 47: of_bsn_get_interfaces_reply */
    16,   /* 48: of_bsn_get_interfaces_request */
    24,   /* 49: of_bsn_get_ip_mask_reply */
    24,   /* 50: of_bsn_get_ip_mask_request */
    24,   /* 51: of_bsn_get_l2_table_reply */
    16,   /* 52: of_bsn_get_l2_table_request */
    20,   /* 53: of_bsn_get_mirroring_reply */
    20,   /* 54: of_bsn_get_mirroring_request */
    -1,   /* 55: of_bsn_get_switch_pipeline_reply */
    -1,   /* 56: of_bsn_get_switch_pipeline_request */
    16,   /* 57: of_bsn_header */
    24,   /* 58: of_bsn_hybrid_get_reply */
    16,   /* 59: of_bsn_hybrid_get_request */
    -1,   /* 60: of_bsn_image_desc_stats_reply */
    -1,   /* 61: of_bsn_image_desc_stats_request */
    -1,   /* 62: of_bsn_lacp_convergence_notif */
    -1,   /* 63: of_bsn_lacp_stats_reply */
    -1,   /* 64: of_bsn_lacp_stats_request */
    -1,   /* 65: of_bsn_log */
    23,   /* 66: of_bsn_pdu_rx_reply */
    26,   /* 67: of_bsn_pdu_rx_request */
    19,   /* 68: of_bsn_pdu_rx_timeout */
    23,   /* 69: of_bsn_pdu_tx_reply */
    26,   /* 70: of_bsn_pdu_tx_request */
    -1,   /* 71: of_bsn_port_counter_stats_reply */
    -1,   /* 72: of_bsn_port_counter_stats_request */
    -1,   /* 73: of_bsn_role_status */
    -1,   /* 74: of_bsn_set_aux_cxns_reply */
    -1,   /* 75: of_bsn_set_aux_cxns_request */
    24,   /* 76: of_bsn_set_ip_mask */
    24,   /* 77: of_bsn_set_l2_table_reply */
    24,   /* 78: of_bsn_set_l2_table_request */
    -1,   /* 79: of_bsn_set_lacp_reply */
    -1,   /* 80: of_bsn_set_lacp_request */
    20,   /* 81: of_bsn_set_mirroring */
    20,   /* 82: of_bsn_set_pktin_suppression_reply */
    32,   /* 83: of_bsn_set_pktin_suppression_request */
    -1,   /* 84: of_bsn_set_switch_pipeline_reply */
    -1,   /* 85: of_bsn_set_switch_pipeline_request */
    20,   /* 86: of_bsn_shell_command */
    16,   /* 87: of_bsn_shell_output */
    20,   /* 88: of_bsn_shell_status */
    24,   /* 89: of_bsn_stats_reply */
    24,   /* 90: of_bsn_stats_request */
    -1,   /* 91: of_bsn_switch_pipeline_stats_reply */
    -1,   /* 92: of_bsn_switch_pipeline_stats_request */
    -1,   /* 93: of_bsn_table_checksum_stats_reply */
    -1,   /* 94: of_bsn_table_checksum_stats_request */
    -1,   /* 95: of_bsn_table_set_buckets_size */
    -1,   /* 96: of_bsn_time_reply */
    -1,   /* 97: of_bsn_time_request */
    24,   /* 98: of_bsn_virtual_port_create_reply */
    20,   /* 99: of_bsn_virtual_port_create_request */
    20,   /* 100: of_bsn_virtual_port_remove_reply */
    20,   /* 101: of_bsn_virtual_port_remove_request */
    -1,   /* 102: of_bsn_vlan_counter_stats_reply */
    -1,   /* 103: of_bsn_vlan_counter_stats_request */
    -1,   /* 104: of_bsn_vrf_counter_stats_reply */
    -1,   /* 105: of_bsn_vrf_counter_stats_request */
    -1,   /* 106: of_bundle_add_msg */
    -1,   /* 107: of_bundle_ctrl_msg */
    1068, /* 108: of_desc_stats_reply */
    12,   /* 109: of_desc_stats_request */
    8,    /* 110: of_echo_reply */
    8,    /* 111: of_echo_request */
    10,   /* 112: of_error_msg */
    12,   /* 113: of_experimenter */
    -1,   /* 114: of_experimenter_error_msg */
    16,   /* 115: of_experimenter_stats_reply */
    16,   /* 116: of_experimenter_stats_request */
    32,   /* 117: of_features_reply */
    8,    /* 118: of_features_request */
    72,   /* 119: of_flow_add */
    72,   /* 120: of_flow_delete */
    72,   /* 121: of_flow_delete_strict */
    72,   /* 122: of_flow_mod */
    12,   /* 123: of_flow_mod_failed_error_msg */
    72,   /* 124: of_flow_modify */
    72,   /* 125: of_flow_modify_strict */
    88,   /* 126: of_flow_removed */
    12,   /* 127: of_flow_stats_reply */
    56,   /* 128: of_flow_stats_request */
    12,   /* 129: of_get_config_reply */
    8,    /* 130: of_get_config_request */
    -1,   /* 131: of_group_add */
    -1,   /* 132: of_group_delete */
    -1,   /* 133: of_group_desc_stats_reply */
    -1,   /* 134: of_group_desc_stats_request */
    -1,   /* 135: of_group_features_stats_reply */
    -1,   /* 136: of_group_features_stats_request */
    -1,   /* 137: of_group_mod */
    -1,   /* 138: of_group_mod_failed_error_msg */
    -1,   /* 139: of_group_modify */
    -1,   /* 140: of_group_stats_reply */
    -1,   /* 141: of_group_stats_request */
    8,    /* 142: of_header */
    8,    /* 143: of_hello */
    12,   /* 144: of_hello_failed_error_msg */
    -1,   /* 145: of_meter_config_stats_reply */
    -1,   /* 146: of_meter_config_stats_request */
    -1,   /* 147: of_meter_features_stats_reply */
    -1,   /* 148: of_meter_features_stats_request */
    -1,   /* 149: of_meter_mod */
    -1,   /* 150: of_meter_mod_failed_error_msg */
    -1,   /* 151: of_meter_stats_reply */
    -1,   /* 152: of_meter_stats_request */
    20,   /* 153: of_nicira_controller_role_reply */
    20,   /* 154: of_nicira_controller_role_request */
    16,   /* 155: of_nicira_header */
    18,   /* 156: of_packet_in */
    16,   /* 157: of_packet_out */
    -1,   /* 158: of_port_desc_stats_reply */
    -1,   /* 159: of_port_desc_stats_request */
    32,   /* 160: of_port_mod */
    12,   /* 161: of_port_mod_failed_error_msg */
    12,   /* 162: of_port_stats_reply */
    20,   /* 163: of_port_stats_request */
    64,   /* 164: of_port_status */
    -1,   /* 165: of_queue_desc_stats_reply */
    -1,   /* 166: of_queue_desc_stats_request */
    16,   /* 167: of_queue_get_config_reply */
    12,   /* 168: of_queue_get_config_request */
    12,   /* 169: of_queue_op_failed_error_msg */
    12,   /* 170: of_queue_stats_reply */
    20,   /* 171: of_queue_stats_request */
    -1,   /* 172: of_requestforward */
    -1,   /* 173: of_role_reply */
    -1,   /* 174: of_role_request */
    -1,   /* 175: of_role_request_failed_error_msg */
    -1,   /* 176: of_role_status */
    12,   /* 177: of_set_config */
    12,   /* 178: of_stats_reply */
    12,   /* 179: of_stats_request */
    -1,   /* 180: of_switch_config_failed_error_msg */
    -1,   /* 181: of_table_desc_stats_reply */
    -1,   /* 182: of_table_desc_stats_request */
    -1,   /* 183: of_table_features_failed_error_msg */
    -1,   /* 184: of_table_features_stats_reply */
    -1,   /* 185: of_table_features_stats_request */
    16,   /* 186: of_table_mod */
    -1,   /* 187: of_table_mod_failed_error_msg */
    12,   /* 188: of_table_stats_reply */
    12,   /* 189: of_table_stats_request */
    -1,   /* 190: of_table_status */
    8,    /* 191: of_action */
    16,   /* 192: of_action_bsn */
    28,   /* 193: of_action_bsn_checksum */
    -1,   /* 194: of_action_bsn_gentable */
    24,   /* 195: of_action_bsn_mirror */
    16,   /* 196: of_action_bsn_set_tunnel_dst */
    -1,   /* 197: of_action_copy_ttl_in */
    -1,   /* 198: of_action_copy_ttl_out */
    -1,   /* 199: of_action_dec_mpls_ttl */
    -1,   /* 200: of_action_dec_nw_ttl */
    16,   /* 201: of_action_enqueue */
    8,    /* 202: of_action_experimenter */
    -1,   /* 203: of_action_group */
    8,    /* 204: of_action_header */
    -1,   /* 205: of_action_id */
    -1,   /* 206: of_action_id_bsn */
    -1,   /* 207: of_action_id_bsn_checksum */
    -1,   /* 208: of_action_id_bsn_gentable */
    -1,   /* 209: of_action_id_bsn_mirror */
    -1,   /* 210: of_action_id_bsn_set_tunnel_dst */
    -1,   /* 211: of_action_id_copy_ttl_in */
    -1,   /* 212: of_action_id_copy_ttl_out */
    -1,   /* 213: of_action_id_dec_mpls_ttl */
    -1,   /* 214: of_action_id_dec_nw_ttl */
    -1,   /* 215: of_action_id_experimenter */
    -1,   /* 216: of_action_id_group */
    -1,   /* 217: of_action_id_header */
    -1,   /* 218: of_action_id_nicira */
    -1,   /* 219: of_action_id_nicira_dec_ttl */
    -1,   /* 220: of_action_id_output */
    -1,   /* 221: of_action_id_pop_mpls */
    -1,   /* 222: of_action_id_pop_pbb */
    -1,   /* 223: of_action_id_pop_vlan */
    -1,   /* 224: of_action_id_push_mpls */
    -1,   /* 225: of_action_id_push_pbb */
    -1,   /* 226: of_action_id_push_vlan */
    -1,   /* 227: of_action_id_set_field */
    -1,   /* 228: of_action_id_set_mpls_ttl */
    -1,   /* 229: of_action_id_set_nw_ttl */
    -1,   /* 230: of_action_id_set_queue */
    16,   /* 231: of_action_nicira */
    16,   /* 232: of_action_nicira_dec_ttl */
    8,    /* 233: of_action_output */
    -1,   /* 234: of_action_pop_mpls */
    -1,   /* 235: of_action_pop_pbb */
    -1,   /* 236: of_action_pop_vlan */
    -1,   /* 237: of_action_push_mpls */
    -1,   /* 238: of_action_push_pbb */
    -1,   /* 239: of_action_push_vlan */
    16,   /* 240: of_action_set_dl_dst */
    16,   /* 241: of_action_set_dl_src */
    -1,   /* 242: of_action_set_field */
    -1,   /* 243: of_action_set_mpls_label */
    -1,   /* 244: of_action_set_mpls_tc */
    -1,   /* 245: of_action_set_mpls_ttl */
    8,    /* 246: of_action_set_nw_dst */
    -1,   /* 247: of_action_set_nw_ecn */
    8,    /* 248: of_action_set_nw_src */
    8,    /* 249: of_action_set_nw_tos */
    -1,   /* 250: of_action_set_nw_ttl */
    -1,   /* 251: of_action_set_queue */
    8,    /* 252: of_action_set_tp_dst */
    8,    /* 253: of_action_set_tp_src */
    8,    /* 254: of_action_set_vlan_pcp */
    8,    /* 255: of_action_set_vlan_vid */
    8,    /* 256: of_action_strip_vlan */
    -1,   /* 257: of_async_config_prop */
    -1,   /* 258: of_async_config_prop_experimenter_master */
    -1,   /* 259: of_async_config_prop_experimenter_slave */
    -1,   /* 260: of_async_config_prop_flow_removed_master */
    -1,   /* 261: of_async_config_prop_flow_removed_slave */
    -1,   /* 262: of_async_config_prop_header */
    -1,   /* 263: of_async_config_prop_packet_in_master */
    -1,   /* 264: of_async_config_prop_packet_in_slave */
    -1,   /* 265: of_async_config_prop_port_status_master */
    -1,   /* 266: of_async_config_prop_port_status_slave */
    -1,   /* 267: of_async_config_prop_requestforward_master */
    -1,   /* 268: of_async_config_prop_requestforward_slave */
    -1,   /* 269: of_async_config_prop_role_status_master */
    -1,   /* 270: of_async_config_prop_role_status_slave */
    -1,   /* 271: of_async_config_prop_table_status_master */
    -1,   /* 272: of_async_config_prop_table_status_slave */
    -1,   /* 273: of_bsn_controller_connection */
    -1,   /* 274: of_bsn_debug_counter_desc_stats_entry */
    -1,   /* 275: of_bsn_debug_counter_stats_entry */
    -1,   /* 276: of_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 277: of_bsn_gentable_bucket_stats_entry */
    -1,   /* 278: of_bsn_gentable_desc_stats_entry */
    -1,   /* 279: of_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 280: of_bsn_gentable_entry_stats_entry */
    -1,   /* 281: of_bsn_gentable_stats_entry */
    32,   /* 282: of_bsn_interface */
    -1,   /* 283: of_bsn_lacp_stats_entry */
    -1,   /* 284: of_bsn_port_counter_stats_entry */
    -1,   /* 285: of_bsn_switch_pipeline_stats_entry */
    -1,   /* 286: of_bsn_table_checksum_stats_entry */
    -1,   /* 287: of_bsn_tlv */
    -1,   /* 288: of_bsn_tlv_actor_key */
    -1,   /* 289: of_bsn_tlv_actor_port_num */
    -1,   /* 290: of_bsn_tlv_actor_port_priority */
    -1,   /* 291: of_bsn_tlv_actor_state */
    -1,   /* 292: of_bsn_tlv_actor_system_mac */
    -1,   /* 293: of_bsn_tlv_actor_system_priority */
    -1,   /* 294: of_bsn_tlv_broadcast_query_timeout */
    -1,   /* 295: of_bsn_tlv_circuit_id */
    -1,   /* 296: of_bsn_tlv_convergence_status */
    -1,   /* 297: of_bsn_tlv_crc_enabled */
    -1,   /* 298: of_bsn_tlv_data */
    -1,   /* 299: of_bsn_tlv_eth_dst */
    -1,   /* 300: of_bsn_tlv_eth_src */
    -1,   /* 301: of_bsn_tlv_external_gateway_ip */
    -1,   /* 302: of_bsn_tlv_external_gateway_mac */
    -1,   /* 303: of_bsn_tlv_external_ip */
    -1,   /* 304: of_bsn_tlv_external_mac */
    -1,   /* 305: of_bsn_tlv_external_netmask */
    -1,   /* 306: of_bsn_tlv_header */
    -1,   /* 307: of_bsn_tlv_header_size */
    -1,   /* 308: of_bsn_tlv_idle_notification */
    -1,   /* 309: of_bsn_tlv_idle_time */
    -1,   /* 310: of_bsn_tlv_idle_timeout */
    -1,   /* 311: of_bsn_tlv_internal_gateway_mac */
    -1,   /* 312: of_bsn_tlv_internal_mac */
    -1,   /* 313: of_bsn_tlv_ipv4 */
    -1,   /* 314: of_bsn_tlv_ipv4_dst */
    -1,   /* 315: of_bsn_tlv_ipv4_src */
    -1,   /* 316: of_bsn_tlv_mac */
    -1,   /* 317: of_bsn_tlv_miss_packets */
    -1,   /* 318: of_bsn_tlv_name */
    -1,   /* 319: of_bsn_tlv_partner_key */
    -1,   /* 320: of_bsn_tlv_partner_port_num */
    -1,   /* 321: of_bsn_tlv_partner_port_priority */
    -1,   /* 322: of_bsn_tlv_partner_state */
    -1,   /* 323: of_bsn_tlv_partner_system_mac */
    -1,   /* 324: of_bsn_tlv_partner_system_priority */
    -1,   /* 325: of_bsn_tlv_port */
    -1,   /* 326: of_bsn_tlv_queue_id */
    -1,   /* 327: of_bsn_tlv_queue_weight */
    -1,   /* 328: of_bsn_tlv_reply_packets */
    -1,   /* 329: of_bsn_tlv_request_packets */
    -1,   /* 330: of_bsn_tlv_rx_packets */
    -1,   /* 331: of_bsn_tlv_sampling_rate */
    -1,   /* 332: of_bsn_tlv_sub_agent_id */
    -1,   /* 333: of_bsn_tlv_tx_bytes */
    -1,   /* 334: of_bsn_tlv_tx_packets */
    -1,   /* 335: of_bsn_tlv_udf_anchor */
    -1,   /* 336: of_bsn_tlv_udf_id */
    -1,   /* 337: of_bsn_tlv_udf_length */
    -1,   /* 338: of_bsn_tlv_udf_offset */
    -1,   /* 339: of_bsn_tlv_udp_dst */
    -1,   /* 340: of_bsn_tlv_udp_src */
    -1,   /* 341: of_bsn_tlv_unicast_query_timeout */
    -1,   /* 342: of_bsn_tlv_vlan_vid */
    -1,   /* 343: of_bsn_tlv_vrf */
    -1,   /* 344: of_bsn_vlan_counter_stats_entry */
    4,    /* 345: of_bsn_vport */
    4,    /* 346: of_bsn_vport_header */
    60,   /* 347: of_bsn_vport_l2gre */
    32,   /* 348: of_bsn_vport_q_in_q */
    -1,   /* 349: of_bsn_vrf_counter_stats_entry */
    -1,   /* 350: of_bucket */
    -1,   /* 351: of_bucket_counter */
    -1,   /* 352: of_bundle_prop */
    -1,   /* 353: of_bundle_prop_experimenter */
    -1,   /* 354: of_bundle_prop_header */
    88,   /* 355: of_flow_stats_entry */
    -1,   /* 356: of_group_desc_stats_entry */
    -1,   /* 357: of_group_stats_entry */
    -1,   /* 358: of_hello_elem */
    -1,   /* 359: of_hello_elem_header */
    -1,   /* 360: of_hello_elem_versionbitmap */
    -1,   /* 361: of_instruction */
    -1,   /* 362: of_instruction_apply_actions */
    -1,   /* 363: of_instruction_bsn */
    -1,   /* 364: of_instruction_bsn_arp_offload */
    -1,   /* 365: of_instruction_bsn_deny */
    -1,   /* 366: of_instruction_bsn_dhcp_offload */
    -1,   /* 367: of_instruction_bsn_disable_split_horizon_check */
    -1,   /* 368: of_instruction_bsn_disable_src_mac_check */
    -1,   /* 369: of_instruction_bsn_disable_vlan_counters */
    -1,   /* 370: of_instruction_bsn_packet_of_death */
    -1,   /* 371: of_instruction_bsn_permit */
    -1,   /* 372: of_instruction_bsn_prioritize_pdus */
    -1,   /* 373: of_instruction_bsn_require_vlan_xlate */
    -1,   /* 374: of_instruction_bsn_span_destination */
    -1,   /* 375: of_instruction_clear_actions */
    -1,   /* 376: of_instruction_experimenter */
    -1,   /* 377: of_instruction_goto_table */
    -1,   /* 378: of_instruction_header */
    -1,   /* 379: of_instruction_id */
    -1,   /* 380: of_instruction_id_apply_actions */
    -1,   /* 381: of_instruction_id_bsn */
    -1,   /* 382: of_instruction_id_bsn_arp_offload */
    -1,   /* 383: of_instruction_id_bsn_deny */
    -1,   /* 384: of_instruction_id_bsn_dhcp_offload */
    -1,   /* 385: of_instruction_id_bsn_disable_split_horizon_check */
    -1,   /* 386: of_instruction_id_bsn_disable_src_mac_check */
    -1,   /* 387: of_instruction_id_bsn_disable_vlan_counters */
    -1,   /* 388: of_instruction_id_bsn_packet_of_death */
    -1,   /* 389: of_instruction_id_bsn_permit */
    -1,   /* 390: of_instruction_id_bsn_prioritize_pdus */
    -1,   /* 391: of_instruction_id_bsn_require_vlan_xlate */
    -1,   /* 392: of_instruction_id_bsn_span_destination */
    -1,   /* 393: of_instruction_id_clear_actions */
    -1,   /* 394: of_instruction_id_experimenter */
    -1,   /* 395: of_instruction_id_goto_table */
    -1,   /* 396: of_instruction_id_header */
    -1,   /* 397: of_instruction_id_meter */
    -1,   /* 398: of_instruction_id_write_actions */
    -1,   /* 399: of_instruction_id_write_metadata */
    -1,   /* 400: of_instruction_meter */
    -1,   /* 401: of_instruction_write_actions */
    -1,   /* 402: of_instruction_write_metadata */
    40,   /* 403: of_match_v1 */
    -1,   /* 404: of_match_v2 */
    -1,   /* 405: of_match_v3 */
    -1,   /* 406: of_meter_band */
    -1,   /* 407: of_meter_band_drop */
    -1,   /* 408: of_meter_band_dscp_remark */
    -1,   /* 409: of_meter_band_experimenter */
    -1,   /* 410: of_meter_band_header */
    -1,   /* 411: of_meter_band_stats */
    -1,   /* 412: of_meter_config */
    -1,   /* 413: of_meter_features */
    -1,   /* 414: of_meter_stats */
    -1,   /* 415: of_oxm */
    -1,   /* 416: of_oxm_arp_op */
    -1,   /* 417: of_oxm_arp_op_masked */
    -1,   /* 418: of_oxm_arp_sha */
    -1,   /* 419: of_oxm_arp_sha_masked */
    -1,   /* 420: of_oxm_arp_spa */
    -1,   /* 421: of_oxm_arp_spa_masked */
    -1,   /* 422: of_oxm_arp_tha */
    -1,   /* 423: of_oxm_arp_tha_masked */
    -1,   /* 424: of_oxm_arp_tpa */
    -1,   /* 425: of_oxm_arp_tpa_masked */
    -1,   /* 426: of_oxm_bsn_egr_port_group_id */
    -1,   /* 427: of_oxm_bsn_egr_port_group_id_masked */
    -1,   /* 428: of_oxm_bsn_global_vrf_allowed */
    -1,   /* 429: of_oxm_bsn_global_vrf_allowed_masked */
    -1,   /* 430: of_oxm_bsn_in_ports_128 */
    -1,   /* 431: of_oxm_bsn_in_ports_128_masked */
    -1,   /* 432: of_oxm_bsn_l3_dst_class_id */
    -1,   /* 433: of_oxm_bsn_l3_dst_class_id_masked */
    -1,   /* 434: of_oxm_bsn_l3_interface_class_id */
    -1,   /* 435: of_oxm_bsn_l3_interface_class_id_masked */
    -1,   /* 436: of_oxm_bsn_l3_src_class_id */
    -1,   /* 437: of_oxm_bsn_l3_src_class_id_masked */
    -1,   /* 438: of_oxm_bsn_lag_id */
    -1,   /* 439: of_oxm_bsn_lag_id_masked */
    -1,   /* 440: of_oxm_bsn_tcp_flags */
    -1,   /* 441: of_oxm_bsn_tcp_flags_masked */
    -1,   /* 442: of_oxm_bsn_udf0 */
    -1,   /* 443: of_oxm_bsn_udf0_masked */
    -1,   /* 444: of_oxm_bsn_udf1 */
    -1,   /* 445: of_oxm_bsn_udf1_masked */
    -1,   /* 446: of_oxm_bsn_udf2 */
    -1,   /* 447: of_oxm_bsn_udf2_masked */
    -1,   /* 448: of_oxm_bsn_udf3 */
    -1,   /* 449: of_oxm_bsn_udf3_masked */
    -1,   /* 450: of_oxm_bsn_udf4 */
    -1,   /* 451: of_oxm_bsn_udf4_masked */
    -1,   /* 452: of_oxm_bsn_udf5 */
    -1,   /* 453: of_oxm_bsn_udf5_masked */
    -1,   /* 454: of_oxm_bsn_udf6 */
    -1,   /* 455: of_oxm_bsn_udf6_masked */
    -1,   /* 456: of_oxm_bsn_udf7 */
    -1,   /* 457: of_oxm_bsn_udf7_masked */
    -1,   /* 458: of_oxm_bsn_vlan_xlate_port_group_id */
    -1,   /* 459: of_oxm_bsn_vlan_xlate_port_group_id_masked */
    -1,   /* 460: of_oxm_bsn_vrf */
    -1,   /* 461: of_oxm_bsn_vrf_masked */
    -1,   /* 462: of_oxm_eth_dst */
    -1,   /* 463: of_oxm_eth_dst_masked */
    -1,   /* 464: of_oxm_eth_src */
    -1,   /* 465: of_oxm_eth_src_masked */
    -1,   /* 466: of_oxm_eth_type */
    -1,   /* 467: of_oxm_eth_type_masked */
    -1,   /* 468: of_oxm_header */
    -1,   /* 469: of_oxm_icmpv4_code */
    -1,   /* 470: of_oxm_icmpv4_code_masked */
    -1,   /* 471: of_oxm_icmpv4_type */
    -1,   /* 472: of_oxm_icmpv4_type_masked */
    -1,   /* 473: of_oxm_icmpv6_code */
    -1,   /* 474: of_oxm_icmpv6_code_masked */
    -1,   /* 475: of_oxm_icmpv6_type */
    -1,   /* 476: of_oxm_icmpv6_type_masked */
    -1,   /* 477: of_oxm_in_phy_port */
    -1,   /* 478: of_oxm_in_phy_port_masked */
    -1,   /* 479: of_oxm_in_port */
    -1,   /* 480: of_oxm_in_port_masked */
    -1,   /* 481: of_oxm_ip_dscp */
    -1,   /* 482: of_oxm_ip_dscp_masked */
    -1,   /* 483: of_oxm_ip_ecn */
    -1,   /* 484: of_oxm_ip_ecn_masked */
    -1,   /* 485: of_oxm_ip_proto */
    -1,   /* 486: of_oxm_ip_proto_masked */
    -1,   /* 487: of_oxm_ipv4_dst */
    -1,   /* 488: of_oxm_ipv4_dst_masked */
    -1,   /* 489: of_oxm_ipv4_src */
    -1,   /* 490: of_oxm_ipv4_src_masked */
    -1,   /* 491: of_oxm_ipv6_dst */
    -1,   /* 492: of_oxm_ipv6_dst_masked */
    -1,   /* 493: of_oxm_ipv6_flabel */
    -1,   /* 494: of_oxm_ipv6_flabel_masked */
    -1,   /* 495: of_oxm_ipv6_nd_sll */
    -1,   /* 496: of_oxm_ipv6_nd_sll_masked */
    -1,   /* 497: of_oxm_ipv6_nd_target */
    -1,   /* 498: of_oxm_ipv6_nd_target_masked */
    -1,   /* 499: of_oxm_ipv6_nd_tll */
    -1,   /* 500: of_oxm_ipv6_nd_tll_masked */
    -1,   /* 501: of_oxm_ipv6_src */
    -1,   /* 502: of_oxm_ipv6_src_masked */
    -1,   /* 503: of_oxm_metadata */
    -1,   /* 504: of_oxm_metadata_masked */
    -1,   /* 505: of_oxm_mpls_bos */
    -1,   /* 506: of_oxm_mpls_bos_masked */
    -1,   /* 507: of_oxm_mpls_label */
    -1,   /* 508: of_oxm_mpls_label_masked */
    -1,   /* 509: of_oxm_mpls_tc */
    -1,   /* 510: of_oxm_mpls_tc_masked */
    -1,   /* 511: of_oxm_sctp_dst */
    -1,   /* 512: of_oxm_sctp_dst_masked */
    -1,   /* 513: of_oxm_sctp_src */
    -1,   /* 514: of_oxm_sctp_src_masked */
    -1,   /* 515: of_oxm_tcp_dst */
    -1,   /* 516: of_oxm_tcp_dst_masked */
    -1,   /* 517: of_oxm_tcp_src */
    -1,   /* 518: of_oxm_tcp_src_masked */
    -1,   /* 519: of_oxm_tunnel_id */
    -1,   /* 520: of_oxm_tunnel_id_masked */
    -1,   /* 521: of_oxm_udp_dst */
    -1,   /* 522: of_oxm_udp_dst_masked */
    -1,   /* 523: of_oxm_udp_src */
    -1,   /* 524: of_oxm_udp_src_masked */
    -1,   /* 525: of_oxm_vlan_pcp */
    -1,   /* 526: of_oxm_vlan_pcp_masked */
    -1,   /* 527: of_oxm_vlan_vid */
    -1,   /* 528: of_oxm_vlan_vid_masked */
    8,    /* 529: of_packet_queue */
    48,   /* 530: of_port_desc */
    -1,   /* 531: of_port_desc_prop */
    -1,   /* 532: of_port_desc_prop_ethernet */
    -1,   /* 533: of_port_desc_prop_experimenter */
    -1,   /* 534: of_port_desc_prop_header */
    -1,   /* 535: of_port_desc_prop_optical */
    -1,   /* 536: of_port_mod_prop */
    -1,   /* 537: of_port_mod_prop_ethernet */
    -1,   /* 538: of_port_mod_prop_experimenter */
    -1,   /* 539: of_port_mod_prop_header */
    -1,   /* 540: of_port_mod_prop_optical */
    104,  /* 541: of_port_stats_entry */
    -1,   /* 542: of_port_stats_prop */
    -1,   /* 543: of_port_stats_prop_ethernet */
    -1,   /* 544: of_port_stats_prop_experimenter */
    -1,   /* 545: of_port_stats_prop_header */
    -1,   /* 546: of_port_stats_prop_optical */
    -1,   /* 547: of_queue_desc */
    -1,   /* 548: of_queue_desc_prop */
    -1,   /* 549: of_queue_desc_prop_experimenter */
    -1,   /* 550: of_queue_desc_prop_header */
    -1,   /* 551: of_queue_desc_prop_max_rate */
    -1,   /* 552: of_queue_desc_prop_min_rate */
    8,    /* 553: of_queue_prop */
    -1,   /* 554: of_queue_prop_experimenter */
    8,    /* 555: of_queue_prop_header */
    -1,   /* 556: of_queue_prop_max_rate */
    16,   /* 557: of_queue_prop_min_rate */
    32,   /* 558: of_queue_stats_entry */
    -1,   /* 559: of_queue_stats_prop */
    -1,   /* 560: of_queue_stats_prop_experimenter */
    -1,   /* 561: of_queue_stats_prop_header */
    -1,   /* 562: of_role_prop */
    -1,   /* 563: of_role_prop_experimenter */
    -1,   /* 564: of_role_prop_header */
    -1,   /* 565: of_table_desc */
    -1,   /* 566: of_table_feature_prop */
    -1,   /* 567: of_table_feature_prop_apply_actions */
    -1,   /* 568: of_table_feature_prop_apply_actions_miss */
    -1,   /* 569: of_table_feature_prop_apply_setfield */
    -1,   /* 570: of_table_feature_prop_apply_setfield_miss */
    -1,   /* 571: of_table_feature_prop_experimenter */
    -1,   /* 572: of_table_feature_prop_experimenter_miss */
    -1,   /* 573: of_table_feature_prop_header */
    -1,   /* 574: of_table_feature_prop_instructions */
    -1,   /* 575: of_table_feature_prop_instructions_miss */
    -1,   /* 576: of_table_feature_prop_match */
    -1,   /* 577: of_table_feature_prop_next_tables */
    -1,   /* 578: of_table_feature_prop_next_tables_miss */
    -1,   /* 579: of_table_feature_prop_table_sync_from */
    -1,   /* 580: of_table_feature_prop_wildcards */
    -1,   /* 581: of_table_feature_prop_write_actions */
    -1,   /* 582: of_table_feature_prop_write_actions_miss */
    -1,   /* 583: of_table_feature_prop_write_setfield */
    -1,   /* 584: of_table_feature_prop_write_setfield_miss */
    -1,   /* 585: of_table_features */
    -1,   /* 586: of_table_mod_prop */
    -1,   /* 587: of_table_mod_prop_eviction */
    -1,   /* 588: of_table_mod_prop_experimenter */
    -1,   /* 589: of_table_mod_prop_vacancy */
    64,   /* 590: of_table_stats_entry */
    -1,   /* 591: of_uint32 */
    -1,   /* 592: of_uint64 */
    -1,   /* 593: of_uint8 */
    0,    /* 594: of_list_action */
    -1,   /* 595: of_list_action_id */
    -1,   /* 596: of_list_async_config_prop */
    -1,   /* 597: of_list_bsn_controller_connection */
    -1,   /* 598: of_list_bsn_debug_counter_desc_stats_entry */
    -1,   /* 599: of_list_bsn_debug_counter_stats_entry */
    -1,   /* 600: of_list_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 601: of_list_bsn_gentable_bucket_stats_entry */
    -1,   /* 602: of_list_bsn_gentable_desc_stats_entry */
    -1,   /* 603: of_list_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 604: of_list_bsn_gentable_entry_stats_entry */
    -1,   /* 605: of_list_bsn_gentable_stats_entry */
    0,    /* 606: of_list_bsn_interface */
    -1,   /* 607: of_list_bsn_lacp_stats_entry */
    -1,   /* 608: of_list_bsn_port_counter_stats_entry */
    -1,   /* 609: of_list_bsn_switch_pipeline_stats_entry */
    -1,   /* 610: of_list_bsn_table_checksum_stats_entry */
    -1,   /* 611: of_list_bsn_tlv */
    -1,   /* 612: of_list_bsn_vlan_counter_stats_entry */
    -1,   /* 613: of_list_bsn_vrf_counter_stats_entry */
    -1,   /* 614: of_list_bucket */
    -1,   /* 615: of_list_bucket_counter */
    -1,   /* 616: of_list_bundle_prop */
    0,    /* 617: of_list_flow_stats_entry */
    -1,   /* 618: of_list_group_desc_stats_entry */
    -1,   /* 619: of_list_group_stats_entry */
    -1,   /* 620: of_list_hello_elem */
    -1,   /* 621: of_list_instruction */
    -1,   /* 622: of_list_instruction_id */
    -1,   /* 623: of_list_meter_band */
    -1,   /* 624: of_list_meter_band_stats */
    -1,   /* 625: of_list_meter_stats */
    -1,   /* 626: of_list_oxm */
    0,    /* 627: of_list_packet_queue */
    0,    /* 628: of_list_port_desc */
    -1,   /* 629: of_list_port_desc_prop */
    -1,   /* 630: of_list_port_mod_prop */
    0,    /* 631: of_list_port_stats_entry */
    -1,   /* 632: of_list_port_stats_prop */
    -1,   /* 633: of_list_queue_desc */
    -1,   /* 634: of_list_queue_desc_prop */
    0,    /* 635: of_list_queue_prop */
    0,    /* 636: of_list_queue_stats_entry */
    -1,   /* 637: of_list_queue_stats_prop */
    -1,   /* 638: of_list_role_prop */
    -1,   /* 639: of_list_table_desc */
    -1,   /* 640: of_list_table_feature_prop */
    -1,   /* 641: of_list_table_features */
    -1,   /* 642: of_list_table_mod_prop */
    0,    /* 643: of_list_table_stats_entry */
    -1,   /* 644: of_list_uint32 */
    -1,   /* 645: of_list_uint64 */
    -1    /* 646: of_list_uint8 */
};

static const int
of_object_fixed_len_v2[OF_OBJECT_COUNT] = {
    -1,   /* of_object is not instantiable */
    40,   /* 1: of_aggregate_stats_reply */
    136,  /* 2: of_aggregate_stats_request */
    -1,   /* 3: of_async_get_reply */
    -1,   /* 4: of_async_get_request */
    -1,   /* 5: of_async_set */
    12,   /* 6: of_bad_action_error_msg */
    12,   /* 7: of_bad_instruction_error_msg */
    12,   /* 8: of_bad_match_error_msg */
    12,   /* 9: of_bad_request_error_msg */
    8,    /* 10: of_barrier_reply */
    8,    /* 11: of_barrier_request */
    -1,   /* 12: of_bsn_arp_idle */
    20,   /* 13: of_bsn_bw_clear_data_reply */
    16,   /* 14: of_bsn_bw_clear_data_request */
    20,   /* 15: of_bsn_bw_enable_get_reply */
    16,   /* 16: of_bsn_bw_enable_get_request */
    24,   /* 17: of_bsn_bw_enable_set_reply */
    20,   /* 18: of_bsn_bw_enable_set_request */
    -1,   /* 19: of_bsn_controller_connections_reply */
    -1,   /* 20: of_bsn_controller_connections_request */
    -1,   /* 21: of_bsn_debug_counter_desc_stats_reply */
    -1,   /* 22: of_bsn_debug_counter_desc_stats_request */
    -1,   /* 23: of_bsn_debug_counter_stats_reply */
    -1,   /* 24: of_bsn_debug_counter_stats_request */
    -1,   /* 25: of_bsn_flow_checksum_bucket_stats_reply */
    -1,   /* 26: of_bsn_flow_checksum_bucket_stats_request */
    -1,   /* 27: of_bsn_flow_idle */
    -1,   /* 28: of_bsn_flow_idle_enable_get_reply */
    -1,   /* 29: of_bsn_flow_idle_enable_get_request */
    -1,   /* 30: of_bsn_flow_idle_enable_set_reply */
    -1,   /* 31: of_bsn_flow_idle_enable_set_request */
    -1,   /* 32: of_bsn_gentable_bucket_stats_reply */
    -1,   /* 33: of_bsn_gentable_bucket_stats_request */
    -1,   /* 34: of_bsn_gentable_clear_reply */
    -1,   /* 35: of_bsn_gentable_clear_request */
    -1,   /* 36: of_bsn_gentable_desc_stats_reply */
    -1,   /* 37: of_bsn_gentable_desc_stats_request */
    -1,   /* 38: of_bsn_gentable_entry_add */
    -1,   /* 39: of_bsn_gentable_entry_delete */
    -1,   /* 40: of_bsn_gentable_entry_desc_stats_reply */
    -1,   /* 41: of_bsn_gentable_entry_desc_stats_request */
    -1,   /* 42: of_bsn_gentable_entry_stats_reply */
    -1,   /* 43: of_bsn_gentable_entry_stats_request */
    -1,   /* 44: of_bsn_gentable_set_buckets_size */
    -1,   /* 45: of_bsn_gentable_stats_reply */
    -1,   /* 46: of_bsn_gentable_stats_request */
    16,   /* 47: of_bsn_get_interfaces_reply */
    16,   /* 48: of_bsn_get_interfaces_request */
    -1,   /* 49: of_bsn_get_ip_mask_reply */
    -1,   /* 50: of_bsn_get_ip_mask_request */
    -1,   /* 51: of_bsn_get_l2_table_reply */
    -1,   /* 52: of_bsn_get_l2_table_request */
    20,   /* 53: of_bsn_get_mirroring_reply */
    20,   /* 54: of_bsn_get_mirroring_request */
    -1,   /* 55: of_bsn_get_switch_pipeline_reply */
    -1,   /* 56: of_bsn_get_switch_pipeline_request */
    16,   /* 57: of_bsn_header */
    -1,   /* 58: of_bsn_hybrid_get_reply */
    -1,   /* 59: of_bsn_hybrid_get_request */
    -1,   /* 60: of_bsn_image_desc_stats_reply */
    -1,   /* 61: of_bsn_image_desc_stats_request */
    -1,   /* 62: of_bsn_lacp_convergence_notif */
    -1,   /* 63: of_bsn_lacp_stats_reply */
    -1,   /* 64: of_bsn_lacp_stats_request */
    -1,   /* 65: of_bsn_log */
    25,   /* 66: of_bsn_pdu_rx_reply */
    28,   /* 67: of_bsn_pdu_rx_request */
    21,   /* 68: of_bsn_pdu_rx_timeout */
    25,   /* 69: of_bsn_pdu_tx_reply */
    28,   /* 70: of_bsn_pdu_tx_request */
    -1,   /* 71: of_bsn_port_counter_stats_reply */
    -1,   /* 72: of_bsn_port_counter_stats_request */
    -1,   /* 73: of_bsn_role_status */
    -1,   /* 74: of_bsn_set_aux_cxns_reply */
    -1,   /* 75: of_bsn_set_aux_cxns_request */
    -1,   /* 76: of_bsn_set_ip_mask */
    -1,   /* 77: of_bsn_set_l2_table_reply */
    -1,   /* 78: of_bsn_set_l2_table_request */
    -1,   /* 79: of_bsn_set_lacp_reply */
    -1,   /* 80: of_bsn_set_lacp_request */
    20,   /* 81: of_bsn_set_mirroring */
    20,   /* 82: of_bsn_set_pktin_suppression_reply */
    32,   /* 83: of_bsn_set_pktin_suppression_request */
    -1,   /* 84: of_bsn_set_switch_pipeline_reply */
    -1,   /* 85: of_bsn_set_switch_pipeline_request */
    -1,   /* 86: of_bsn_shell_command */
    -1,   /* 87: of_bsn_shell_output */
    -1,   /* 88: of_bsn_shell_status */
    24,   /* 89: of_bsn_stats_reply */
    24,   /* 90: of_bsn_stats_request */
    -1,   /* 91: of_bsn_switch_pipeline_stats_reply */
    -1,   /* 92: of_bsn_switch_pipeline_stats_request */
    -1,   /* 93: of_bsn_table_checksum_stats_reply */
    -1,   /* 94: of_bsn_table_checksum_stats_request */
    -1,   /* 95: of_bsn_table_set_buckets_size */
    -1,   /* 96: of_bsn_time_reply */
    -1,   /* 97: of_bsn_time_request */
    24,   /* 98: of_bsn_virtual_port_create_reply */
    20,   /* 99: of_bsn_virtual_port_create_request */
    20,   /* 100: of_bsn_virtual_port_remove_reply */
    20,   /* 101: of_bsn_virtual_port_remove_request */
    -1,   /* 102: of_bsn_vlan_counter_stats_reply */
    -1,   /* 103: of_bsn_vlan_counter_stats_request */
    -1,   /* 104: of_bsn_vrf_counter_stats_reply */
    -1,   /* 105: of_bsn_vrf_counter_stats_request */
    -1,   /* 106: of_bundle_add_msg */
    -1,   /* 107: of_bundle_ctrl_msg */
    1072, /* 108: of_desc_stats_reply */
    16,   /* 109: of_desc_stats_request */
    8,    /* 110: of_echo_reply */
    8,    /* 111: of_echo_request */
    10,   /* 112: of_error_msg */
    12,   /* 113: of_experimenter */
    -1,   /* 114: of_experimenter_error_msg */
    24,   /* 115: of_experimenter_stats_reply */
    24,   /* 116: of_experimenter_stats_request */
    32,   /* 117: of_features_reply */
    8,    /* 118: of_features_request */
    136,  /* 119: of_flow_add */
    136,  /* 120: of_flow_delete */
    136,  /* 121: of_flow_delete_strict */
    136,  /* 122: of_flow_mod */
    12,   /* 123: of_flow_mod_failed_error_msg */
    136,  /* 124: of_flow_modify */
    136,  /* 125: of_flow_modify_strict */
    136,  /* 126: of_flow_removed */
    16,   /* 127: of_flow_stats_reply */
    136,  /* 128: of_flow_stats_request */
    12,   /* 129: of_get_config_reply */
    8,    /* 130: of_get_config_request */
    16,   /* 131: of_group_add */
    16,   /* 132: of_group_delete */
    16,   /* 133: of_group_desc_stats_reply */
    16,   /* 134: of_group_desc_stats_request */
    -1,   /* 135: of_group_features_stats_reply */
    -1,   /* 136: of_group_features_stats_request */
    16,   /* 137: of_group_mod */
    12,   /* 138: of_group_mod_failed_error_msg */
    16,   /* 139: of_group_modify */
    16,   /* 140: of_group_stats_reply */
    24,   /* 141: of_group_stats_request */
    8,    /* 142: of_header */
    8,    /* 143: of_hello */
    12,   /* 144: of_hello_failed_error_msg */
    -1,   /* 145: of_meter_config_stats_reply */
    -1,   /* 146: of_meter_config_stats_request */
    -1,   /* 147: of_meter_features_stats_reply */
    -1,   /* 148: of_meter_features_stats_request */
    -1,   /* 149: of_meter_mod */
    -1,   /* 150: of_meter_mod_failed_error_msg */
    -1,   /* 151: of_meter_stats_reply */
    -1,   /* 152: of_meter_stats_request */
    -1,   /* 153: of_nicira_controller_role_reply */
    -1,   /* 154: of_nicira_controller_role_request */
    16,   /* 155: of_nicira_header */
    24,   /* 156: of_packet_in */
    24,   /* 157: of_packet_out */
    -1,   /* 158: of_port_desc_stats_reply */
    -1,   /* 159: of_port_desc_stats_request */
    40,   /* 160: of_port_mod */
    12,   /* 161: of_port_mod_failed_error_msg */
    16,   /* 162: of_port_stats_reply */
    24,   /* 163: of_port_stats_request */
    80,   /* 164: of_port_status */
    -1,   /* 165: of_queue_desc_stats_reply */
    -1,   /* 166: of_queue_desc_stats_request */
    16,   /* 167: of_queue_get_config_reply */
    16,   /* 168: of_queue_get_config_request */
    12,   /* 169: of_queue_op_failed_error_msg */
    16,   /* 170: of_queue_stats_reply */
    24,   /* 171: of_queue_stats_request */
    -1,   /* 172: of_requestforward */
    -1,   /* 173: of_role_reply */
    -1,   /* 174: of_role_request */
    -1,   /* 175: of_role_request_failed_error_msg */
    -1,   /* 176: of_role_status */
    12,   /* 177: of_set_config */
    16,   /* 178: of_stats_reply */
    16,   /* 179: of_stats_request */
    12,   /* 180: of_switch_config_failed_error_msg */
    -1,   /* 181: of_table_desc_stats_reply */
    -1,   /* 182: of_table_desc_stats_request */
    -1,   /* 183: of_table_features_failed_error_msg */
    -1,   /* 184: of_table_features_stats_reply */
    -1,   /* 185: of_table_features_stats_request */
    16,   /* 186: of_table_mod */
    12,   /* 187: of_table_mod_failed_error_msg */
    16,   /* 188: of_table_stats_reply */
    16,   /* 189: of_table_stats_request */
    -1,   /* 190: of_table_status */
    8,    /* 191: of_action */
    16,   /* 192: of_action_bsn */
    28,   /* 193: of_action_bsn_checksum */
    -1,   /* 194: of_action_bsn_gentable */
    24,   /* 195: of_action_bsn_mirror */
    16,   /* 196: of_action_bsn_set_tunnel_dst */
    8,    /* 197: of_action_copy_ttl_in */
    8,    /* 198: of_action_copy_ttl_out */
    8,    /* 199: of_action_dec_mpls_ttl */
    8,    /* 200: of_action_dec_nw_ttl */
    -1,   /* 201: of_action_enqueue */
    8,    /* 202: of_action_experimenter */
    8,    /* 203: of_action_group */
    8,    /* 204: of_action_header */
    -1,   /* 205: of_action_id */
    -1,   /* 206: of_action_id_bsn */
    -1,   /* 207: of_action_id_bsn_checksum */
    -1,   /* 208: of_action_id_bsn_gentable */
    -1,   /* 209: of_action_id_bsn_mirror */
    -1,   /* 210: of_action_id_bsn_set_tunnel_dst */
    -1,   /* 211: of_action_id_copy_ttl_in */
    -1,   /* 212: of_action_id_copy_ttl_out */
    -1,   /* 213: of_action_id_dec_mpls_ttl */
    -1,   /* 214: of_action_id_dec_nw_ttl */
    -1,   /* 215: of_action_id_experimenter */
    -1,   /* 216: of_action_id_group */
    -1,   /* 217: of_action_id_header */
    -1,   /* 218: of_action_id_nicira */
    -1,   /* 219: of_action_id_nicira_dec_ttl */
    -1,   /* 220: of_action_id_output */
    -1,   /* 221: of_action_id_pop_mpls */
    -1,   /* 222: of_action_id_pop_pbb */
    -1,   /* 223: of_action_id_pop_vlan */
    -1,   /* 224: of_action_id_push_mpls */
    -1,   /* 225: of_action_id_push_pbb */
    -1,   /* 226: of_action_id_push_vlan */
    -1,   /* 227: of_action_id_set_field */
    -1,   /* 228: of_action_id_set_mpls_ttl */
    -1,   /* 229: of_action_id_set_nw_ttl */
    -1,   /* 230: of_action_id_set_queue */
    16,   /* 231: of_action_nicira */
    16,   /* 232: of_action_nicira_dec_ttl */
    16,   /* 233: of_action_output */
    8,    /* 234: of_action_pop_mpls */
    -1,   /* 235: of_action_pop_pbb */
    8,    /* 236: of_action_pop_vlan */
    8,    /* 237: of_action_push_mpls */
    -1,   /* 238: of_action_push_pbb */
    8,    /* 239: of_action_push_vlan */
    16,   /* 240: of_action_set_dl_dst */
    16,   /* 241: of_action_set_dl_src */
    -1,   /* 242: of_action_set_field */
    8,    /* 243: of_action_set_mpls_label */
    8,    /* 244: of_action_set_mpls_tc */
    8,    /* 245: of_action_set_mpls_ttl */
    8,    /* 246: of_action_set_nw_dst */
    8,    /* 247: of_action_set_nw_ecn */
    8,    /* 248: of_action_set_nw_src */
    8,    /* 249: of_action_set_nw_tos */
    8,    /* 250: of_action_set_nw_ttl */
    8,    /* 251: of_action_set_queue */
    8,    /* 252: of_action_set_tp_dst */
    8,    /* 253: of_action_set_tp_src */
    8,    /* 254: of_action_set_vlan_pcp */
    8,    /* 255: of_action_set_vlan_vid */
    -1,   /* 256: of_action_strip_vlan */
    -1,   /* 257: of_async_config_prop */
    -1,   /* 258: of_async_config_prop_experimenter_master */
    -1,   /* 259: of_async_config_prop_experimenter_slave */
    -1,   /* 260: of_async_config_prop_flow_removed_master */
    -1,   /* 261: of_async_config_prop_flow_removed_slave */
    -1,   /* 262: of_async_config_prop_header */
    -1,   /* 263: of_async_config_prop_packet_in_master */
    -1,   /* 264: of_async_config_prop_packet_in_slave */
    -1,   /* 265: of_async_config_prop_port_status_master */
    -1,   /* 266: of_async_config_prop_port_status_slave */
    -1,   /* 267: of_async_config_prop_requestforward_master */
    -1,   /* 268: of_async_config_prop_requestforward_slave */
    -1,   /* 269: of_async_config_prop_role_status_master */
    -1,   /* 270: of_async_config_prop_role_status_slave */
    -1,   /* 271: of_async_config_prop_table_status_master */
    -1,   /* 272: of_async_config_prop_table_status_slave */
    -1,   /* 273: of_bsn_controller_connection */
    -1,   /* 274: of_bsn_debug_counter_desc_stats_entry */
    -1,   /* 275: of_bsn_debug_counter_stats_entry */
    -1,   /* 276: of_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 277: of_bsn_gentable_bucket_stats_entry */
    -1,   /* 278: of_bsn_gentable_desc_stats_entry */
    -1,   /* 279: of_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 280: of_bsn_gentable_entry_stats_entry */
    -1,   /* 281: of_bsn_gentable_stats_entry */
    32,   /* 282: of_bsn_interface */
    -1,   /* 283: of_bsn_lacp_stats_entry */
    -1,   /* 284: of_bsn_port_counter_stats_entry */
    -1,   /* 285: of_bsn_switch_pipeline_stats_entry */
    -1,   /* 286: of_bsn_table_checksum_stats_entry */
    -1,   /* 287: of_bsn_tlv */
    -1,   /* 288: of_bsn_tlv_actor_key */
    -1,   /* 289: of_bsn_tlv_actor_port_num */
    -1,   /* 290: of_bsn_tlv_actor_port_priority */
    -1,   /* 291: of_bsn_tlv_actor_state */
    -1,   /* 292: of_bsn_tlv_actor_system_mac */
    -1,   /* 293: of_bsn_tlv_actor_system_priority */
    -1,   /* 294: of_bsn_tlv_broadcast_query_timeout */
    -1,   /* 295: of_bsn_tlv_circuit_id */
    -1,   /* 296: of_bsn_tlv_convergence_status */
    -1,   /* 297: of_bsn_tlv_crc_enabled */
    -1,   /* 298: of_bsn_tlv_data */
    -1,   /* 299: of_bsn_tlv_eth_dst */
    -1,   /* 300: of_bsn_tlv_eth_src */
    -1,   /* 301: of_bsn_tlv_external_gateway_ip */
    -1,   /* 302: of_bsn_tlv_external_gateway_mac */
    -1,   /* 303: of_bsn_tlv_external_ip */
    -1,   /* 304: of_bsn_tlv_external_mac */
    -1,   /* 305: of_bsn_tlv_external_netmask */
    -1,   /* 306: of_bsn_tlv_header */
    -1,   /* 307: of_bsn_tlv_header_size */
    -1,   /* 308: of_bsn_tlv_idle_notification */
    -1,   /* 309: of_bsn_tlv_idle_time */
    -1,   /* 310: of_bsn_tlv_idle_timeout */
    -1,   /* 311: of_bsn_tlv_internal_gateway_mac */
    -1,   /* 312: of_bsn_tlv_internal_mac */
    -1,   /* 313: of_bsn_tlv_ipv4 */
    -1,   /* 314: of_bsn_tlv_ipv4_dst */
    -1,   /* 315: of_bsn_tlv_ipv4_src */
    -1,   /* 316: of_bsn_tlv_mac */
    -1,   /* 317: of_bsn_tlv_miss_packets */
    -1,   /* 318: of_bsn_tlv_name */
    -1,   /* 319: of_bsn_tlv_partner_key */
    -1,   /* 320: of_bsn_tlv_partner_port_num */
    -1,   /* 321: of_bsn_tlv_partner_port_priority */
    -1,   /* 322: of_bsn_tlv_partner_state */
    -1,   /* 323: of_bsn_tlv_partner_system_mac */
    -1,   /* 324: of_bsn_tlv_partner_system_priority */
    -1,   /* 325: of_bsn_tlv_port */
    -1,   /* 326: of_bsn_tlv_queue_id */
    -1,   /* 327: of_bsn_tlv_queue_weight */
    -1,   /* 328: of_bsn_tlv_reply_packets */
    -1,   /* 329: of_bsn_tlv_request_packets */
    -1,   /* 330: of_bsn_tlv_rx_packets */
    -1,   /* 331: of_bsn_tlv_sampling_rate */
    -1,   /* 332: of_bsn_tlv_sub_agent_id */
    -1,   /* 333: of_bsn_tlv_tx_bytes */
    -1,   /* 334: of_bsn_tlv_tx_packets */
    -1,   /* 335: of_bsn_tlv_udf_anchor */
    -1,   /* 336: of_bsn_tlv_udf_id */
    -1,   /* 337: of_bsn_tlv_udf_length */
    -1,   /* 338: of_bsn_tlv_udf_offset */
    -1,   /* 339: of_bsn_tlv_udp_dst */
    -1,   /* 340: of_bsn_tlv_udp_src */
    -1,   /* 341: of_bsn_tlv_unicast_query_timeout */
    -1,   /* 342: of_bsn_tlv_vlan_vid */
    -1,   /* 343: of_bsn_tlv_vrf */
    -1,   /* 344: of_bsn_vlan_counter_stats_entry */
    4,    /* 345: of_bsn_vport */
    4,    /* 346: of_bsn_vport_header */
    64,   /* 347: of_bsn_vport_l2gre */
    32,   /* 348: of_bsn_vport_q_in_q */
    -1,   /* 349: of_bsn_vrf_counter_stats_entry */
    16,   /* 350: of_bucket */
    16,   /* 351: of_bucket_counter */
    -1,   /* 352: of_bundle_prop */
    -1,   /* 353: of_bundle_prop_experimenter */
    -1,   /* 354: of_bundle_prop_header */
    136,  /* 355: of_flow_stats_entry */
    8,    /* 356: of_group_desc_stats_entry */
    32,   /* 357: of_group_stats_entry */
    -1,   /* 358: of_hello_elem */
    -1,   /* 359: of_hello_elem_header */
    -1,   /* 360: of_hello_elem_versionbitmap */
    8,    /* 361: of_instruction */
    8,    /* 362: of_instruction_apply_actions */
    -1,   /* 363: of_instruction_bsn */
    -1,   /* 364: of_instruction_bsn_arp_offload */
    -1,   /* 365: of_instruction_bsn_deny */
    -1,   /* 366: of_instruction_bsn_dhcp_offload */
    -1,   /* 367: of_instruction_bsn_disable_split_horizon_check */
    -1,   /* 368: of_instruction_bsn_disable_src_mac_check */
    -1,   /* 369: of_instruction_bsn_disable_vlan_counters */
    -1,   /* 370: of_instruction_bsn_packet_of_death */
    -1,   /* 371: of_instruction_bsn_permit */
    -1,   /* 372: of_instruction_bsn_prioritize_pdus */
    -1,   /* 373: of_instruction_bsn_require_vlan_xlate */
    -1,   /* 374: of_instruction_bsn_span_destination */
    8,    /* 375: of_instruction_clear_actions */
    8,    /* 376: of_instruction_experimenter */
    8,    /* 377: of_instruction_goto_table */
    8,    /* 378: of_instruction_header */
    -1,   /* 379: of_instruction_id */
    -1,   /* 380: of_instruction_id_apply_actions */
    -1,   /* 381: of_instruction_id_bsn */
    -1,   /* 382: of_instruction_id_bsn_arp_offload */
    -1,   /* 383: of_instruction_id_bsn_deny */
    -1,   /* 384: of_instruction_id_bsn_dhcp_offload */
    -1,   /* 385: of_instruction_id_bsn_disable_split_horizon_check */
    -1,   /* 386: of_instruction_id_bsn_disable_src_mac_check */
    -1,   /* 387: of_instruction_id_bsn_disable_vlan_counters */
    -1,   /* 388: of_instruction_id_bsn_packet_of_death */
    -1,   /* 389: of_instruction_id_bsn_permit */
    -1,   /* 390: of_instruction_id_bsn_prioritize_pdus */
    -1,   /* 391: of_instruction_id_bsn_require_vlan_xlate */
    -1,   /* 392: of_instruction_id_bsn_span_destination */
    -1,   /* 393: of_instruction_id_clear_actions */
    -1,   /* 394: of_instruction_id_experimenter */
    -1,   /* 395: of_instruction_id_goto_table */
    -1,   /* 396: of_instruction_id_header */
    -1,   /* 397: of_instruction_id_meter */
    -1,   /* 398: of_instruction_id_write_actions */
    -1,   /* 399: of_instruction_id_write_metadata */
    -1,   /* 400: of_instruction_meter */
    8,    /* 401: of_instruction_write_actions */
    24,   /* 402: of_instruction_write_metadata */
    -1,   /* 403: of_match_v1 */
    88,   /* 404: of_match_v2 */
    -1,   /* 405: of_match_v3 */
    -1,   /* 406: of_meter_band */
    -1,   /* 407: of_meter_band_drop */
    -1,   /* 408: of_meter_band_dscp_remark */
    -1,   /* 409: of_meter_band_experimenter */
    -1,   /* 410: of_meter_band_header */
    -1,   /* 411: of_meter_band_stats */
    -1,   /* 412: of_meter_config */
    -1,   /* 413: of_meter_features */
    -1,   /* 414: of_meter_stats */
    -1,   /* 415: of_oxm */
    -1,   /* 416: of_oxm_arp_op */
    -1,   /* 417: of_oxm_arp_op_masked */
    -1,   /* 418: of_oxm_arp_sha */
    -1,   /* 419: of_oxm_arp_sha_masked */
    -1,   /* 420: of_oxm_arp_spa */
    -1,   /* 421: of_oxm_arp_spa_masked */
    -1,   /* 422: of_oxm_arp_tha */
    -1,   /* 423: of_oxm_arp_tha_masked */
    -1,   /* 424: of_oxm_arp_tpa */
    -1,   /* 425: of_oxm_arp_tpa_masked */
    -1,   /* 426: of_oxm_bsn_egr_port_group_id */
    -1,   /* 427: of_oxm_bsn_egr_port_group_id_masked */
    -1,   /* 428: of_oxm_bsn_global_vrf_allowed */
    -1,   /* 429: of_oxm_bsn_global_vrf_allowed_masked */
    -1,   /* 430: of_oxm_bsn_in_ports_128 */
    -1,   /* 431: of_oxm_bsn_in_ports_128_masked */
    -1,   /* 432: of_oxm_bsn_l3_dst_class_id */
    -1,   /* 433: of_oxm_bsn_l3_dst_class_id_masked */
    -1,   /* 434: of_oxm_bsn_l3_interface_class_id */
    -1,   /* 435: of_oxm_bsn_l3_interface_class_id_masked */
    -1,   /* 436: of_oxm_bsn_l3_src_class_id */
    -1,   /* 437: of_oxm_bsn_l3_src_class_id_masked */
    -1,   /* 438: of_oxm_bsn_lag_id */
    -1,   /* 439: of_oxm_bsn_lag_id_masked */
    -1,   /* 440: of_oxm_bsn_tcp_flags */
    -1,   /* 441: of_oxm_bsn_tcp_flags_masked */
    -1,   /* 442: of_oxm_bsn_udf0 */
    -1,   /* 443: of_oxm_bsn_udf0_masked */
    -1,   /* 444: of_oxm_bsn_udf1 */
    -1,   /* 445: of_oxm_bsn_udf1_masked */
    -1,   /* 446: of_oxm_bsn_udf2 */
    -1,   /* 447: of_oxm_bsn_udf2_masked */
    -1,   /* 448: of_oxm_bsn_udf3 */
    -1,   /* 449: of_oxm_bsn_udf3_masked */
    -1,   /* 450: of_oxm_bsn_udf4 */
    -1,   /* 451: of_oxm_bsn_udf4_masked */
    -1,   /* 452: of_oxm_bsn_udf5 */
    -1,   /* 453: of_oxm_bsn_udf5_masked */
    -1,   /* 454: of_oxm_bsn_udf6 */
    -1,   /* 455: of_oxm_bsn_udf6_masked */
    -1,   /* 456: of_oxm_bsn_udf7 */
    -1,   /* 457: of_oxm_bsn_udf7_masked */
    -1,   /* 458: of_oxm_bsn_vlan_xlate_port_group_id */
    -1,   /* 459: of_oxm_bsn_vlan_xlate_port_group_id_masked */
    -1,   /* 460: of_oxm_bsn_vrf */
    -1,   /* 461: of_oxm_bsn_vrf_masked */
    -1,   /* 462: of_oxm_eth_dst */
    -1,   /* 463: of_oxm_eth_dst_masked */
    -1,   /* 464: of_oxm_eth_src */
    -1,   /* 465: of_oxm_eth_src_masked */
    -1,   /* 466: of_oxm_eth_type */
    -1,   /* 467: of_oxm_eth_type_masked */
    -1,   /* 468: of_oxm_header */
    -1,   /* 469: of_oxm_icmpv4_code */
    -1,   /* 470: of_oxm_icmpv4_code_masked */
    -1,   /* 471: of_oxm_icmpv4_type */
    -1,   /* 472: of_oxm_icmpv4_type_masked */
    -1,   /* 473: of_oxm_icmpv6_code */
    -1,   /* 474: of_oxm_icmpv6_code_masked */
    -1,   /* 475: of_oxm_icmpv6_type */
    -1,   /* 476: of_oxm_icmpv6_type_masked */
    -1,   /* 477: of_oxm_in_phy_port */
    -1,   /* 478: of_oxm_in_phy_port_masked */
    -1,   /* 479: of_oxm_in_port */
    -1,   /* 480: of_oxm_in_port_masked */
    -1,   /* 481: of_oxm_ip_dscp */
    -1,   /* 482: of_oxm_ip_dscp_masked */
    -1,   /* 483: of_oxm_ip_ecn */
    -1,   /* 484: of_oxm_ip_ecn_masked */
    -1,   /* 485: of_oxm_ip_proto */
    -1,   /* 486: of_oxm_ip_proto_masked */
    -1,   /* 487: of_oxm_ipv4_dst */
    -1,   /* 488: of_oxm_ipv4_dst_masked */
    -1,   /* 489: of_oxm_ipv4_src */
    -1,   /* 490: of_oxm_ipv4_src_masked */
    -1,   /* 491: of_oxm_ipv6_dst */
    -1,   /* 492: of_oxm_ipv6_dst_masked */
    -1,   /* 493: of_oxm_ipv6_flabel */
    -1,   /* 494: of_oxm_ipv6_flabel_masked */
    -1,   /* 495: of_oxm_ipv6_nd_sll */
    -1,   /* 496: of_oxm_ipv6_nd_sll_masked */
    -1,   /* 497: of_oxm_ipv6_nd_target */
    -1,   /* 498: of_oxm_ipv6_nd_target_masked */
    -1,   /* 499: of_oxm_ipv6_nd_tll */
    -1,   /* 500: of_oxm_ipv6_nd_tll_masked */
    -1,   /* 501: of_oxm_ipv6_src */
    -1,   /* 502: of_oxm_ipv6_src_masked */
    -1,   /* 503: of_oxm_metadata */
    -1,   /* 504: of_oxm_metadata_masked */
    -1,   /* 505: of_oxm_mpls_bos */
    -1,   /* 506: of_oxm_mpls_bos_masked */
    -1,   /* 507: of_oxm_mpls_label */
    -1,   /* 508: of_oxm_mpls_label_masked */
    -1,   /* 509: of_oxm_mpls_tc */
    -1,   /* 510: of_oxm_mpls_tc_masked */
    -1,   /* 511: of_oxm_sctp_dst */
    -1,   /* 512: of_oxm_sctp_dst_masked */
    -1,   /* 513: of_oxm_sctp_src */
    -1,   /* 514: of_oxm_sctp_src_masked */
    -1,   /* 515: of_oxm_tcp_dst */
    -1,   /* 516: of_oxm_tcp_dst_masked */
    -1,   /* 517: of_oxm_tcp_src */
    -1,   /* 518: of_oxm_tcp_src_masked */
    -1,   /* 519: of_oxm_tunnel_id */
    -1,   /* 520: of_oxm_tunnel_id_masked */
    -1,   /* 521: of_oxm_udp_dst */
    -1,   /* 522: of_oxm_udp_dst_masked */
    -1,   /* 523: of_oxm_udp_src */
    -1,   /* 524: of_oxm_udp_src_masked */
    -1,   /* 525: of_oxm_vlan_pcp */
    -1,   /* 526: of_oxm_vlan_pcp_masked */
    -1,   /* 527: of_oxm_vlan_vid */
    -1,   /* 528: of_oxm_vlan_vid_masked */
    8,    /* 529: of_packet_queue */
    64,   /* 530: of_port_desc */
    -1,   /* 531: of_port_desc_prop */
    -1,   /* 532: of_port_desc_prop_ethernet */
    -1,   /* 533: of_port_desc_prop_experimenter */
    -1,   /* 534: of_port_desc_prop_header */
    -1,   /* 535: of_port_desc_prop_optical */
    -1,   /* 536: of_port_mod_prop */
    -1,   /* 537: of_port_mod_prop_ethernet */
    -1,   /* 538: of_port_mod_prop_experimenter */
    -1,   /* 539: of_port_mod_prop_header */
    -1,   /* 540: of_port_mod_prop_optical */
    104,  /* 541: of_port_stats_entry */
    -1,   /* 542: of_port_stats_prop */
    -1,   /* 543: of_port_stats_prop_ethernet */
    -1,   /* 544: of_port_stats_prop_experimenter */
    -1,   /* 545: of_port_stats_prop_header */
    -1,   /* 546: of_port_stats_prop_optical */
    -1,   /* 547: of_queue_desc */
    -1,   /* 548: of_queue_desc_prop */
    -1,   /* 549: of_queue_desc_prop_experimenter */
    -1,   /* 550: of_queue_desc_prop_header */
    -1,   /* 551: of_queue_desc_prop_max_rate */
    -1,   /* 552: of_queue_desc_prop_min_rate */
    8,    /* 553: of_queue_prop */
    -1,   /* 554: of_queue_prop_experimenter */
    8,    /* 555: of_queue_prop_header */
    -1,   /* 556: of_queue_prop_max_rate */
    16,   /* 557: of_queue_prop_min_rate */
    32,   /* 558: of_queue_stats_entry */
    -1,   /* 559: of_queue_stats_prop */
    -1,   /* 560: of_queue_stats_prop_experimenter */
    -1,   /* 561: of_queue_stats_prop_header */
    -1,   /* 562: of_role_prop */
    -1,   /* 563: of_role_prop_experimenter */
    -1,   /* 564: of_role_prop_header */
    -1,   /* 565: of_table_desc */
    -1,   /* 566: of_table_feature_prop */
    -1,   /* 567: of_table_feature_prop_apply_actions */
    -1,   /* 568: of_table_feature_prop_apply_actions_miss */
    -1,   /* 569: of_table_feature_prop_apply_setfield */
    -1,   /* 570: of_table_feature_prop_apply_setfield_miss */
    -1,   /* 571: of_table_feature_prop_experimenter */
    -1,   /* 572: of_table_feature_prop_experimenter_miss */
    -1,   /* 573: of_table_feature_prop_header */
    -1,   /* 574: of_table_feature_prop_instructions */
    -1,   /* 575: of_table_feature_prop_instructions_miss */
    -1,   /* 576: of_table_feature_prop_match */
    -1,   /* 577: of_table_feature_prop_next_tables */
    -1,   /* 578: of_table_feature_prop_next_tables_miss */
    -1,   /* 579: of_table_feature_prop_table_sync_from */
    -1,   /* 580: of_table_feature_prop_wildcards */
    -1,   /* 581: of_table_feature_prop_write_actions */
    -1,   /* 582: of_table_feature_prop_write_actions_miss */
    -1,   /* 583: of_table_feature_prop_write_setfield */
    -1,   /* 584: of_table_feature_prop_write_setfield_miss */
    -1,   /* 585: of_table_features */
    -1,   /* 586: of_table_mod_prop */
    -1,   /* 587: of_table_mod_prop_eviction */
    -1,   /* 588: of_table_mod_prop_experimenter */
    -1,   /* 589: of_table_mod_prop_vacancy */
    88,   /* 590: of_table_stats_entry */
    -1,   /* 591: of_uint32 */
    -1,   /* 592: of_uint64 */
    -1,   /* 593: of_uint8 */
    0,    /* 594: of_list_action */
    -1,   /* 595: of_list_action_id */
    -1,   /* 596: of_list_async_config_prop */
    -1,   /* 597: of_list_bsn_controller_connection */
    -1,   /* 598: of_list_bsn_debug_counter_desc_stats_entry */
    -1,   /* 599: of_list_bsn_debug_counter_stats_entry */
    -1,   /* 600: of_list_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 601: of_list_bsn_gentable_bucket_stats_entry */
    -1,   /* 602: of_list_bsn_gentable_desc_stats_entry */
    -1,   /* 603: of_list_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 604: of_list_bsn_gentable_entry_stats_entry */
    -1,   /* 605: of_list_bsn_gentable_stats_entry */
    0,    /* 606: of_list_bsn_interface */
    -1,   /* 607: of_list_bsn_lacp_stats_entry */
    -1,   /* 608: of_list_bsn_port_counter_stats_entry */
    -1,   /* 609: of_list_bsn_switch_pipeline_stats_entry */
    -1,   /* 610: of_list_bsn_table_checksum_stats_entry */
    -1,   /* 611: of_list_bsn_tlv */
    -1,   /* 612: of_list_bsn_vlan_counter_stats_entry */
    -1,   /* 613: of_list_bsn_vrf_counter_stats_entry */
    0,    /* 614: of_list_bucket */
    0,    /* 615: of_list_bucket_counter */
    -1,   /* 616: of_list_bundle_prop */
    0,    /* 617: of_list_flow_stats_entry */
    0,    /* 618: of_list_group_desc_stats_entry */
    0,    /* 619: of_list_group_stats_entry */
    -1,   /* 620: of_list_hello_elem */
    0,    /* 621: of_list_instruction */
    -1,   /* 622: of_list_instruction_id */
    -1,   /* 623: of_list_meter_band */
    -1,   /* 624: of_list_meter_band_stats */
    -1,   /* 625: of_list_meter_stats */
    -1,   /* 626: of_list_oxm */
    0,    /* 627: of_list_packet_queue */
    0,    /* 628: of_list_port_desc */
    -1,   /* 629: of_list_port_desc_prop */
    -1,   /* 630: of_list_port_mod_prop */
    0,    /* 631: of_list_port_stats_entry */
    -1,   /* 632: of_list_port_stats_prop */
    -1,   /* 633: of_list_queue_desc */
    -1,   /* 634: of_list_queue_desc_prop */
    0,    /* 635: of_list_queue_prop */
    0,    /* 636: of_list_queue_stats_entry */
    -1,   /* 637: of_list_queue_stats_prop */
    -1,   /* 638: of_list_role_prop */
    -1,   /* 639: of_list_table_desc */
    -1,   /* 640: of_list_table_feature_prop */
    -1,   /* 641: of_list_table_features */
    -1,   /* 642: of_list_table_mod_prop */
    0,    /* 643: of_list_table_stats_entry */
    -1,   /* 644: of_list_uint32 */
    -1,   /* 645: of_list_uint64 */
    -1    /* 646: of_list_uint8 */
};

static const int
of_object_fixed_len_v3[OF_OBJECT_COUNT] = {
    -1,   /* of_object is not instantiable */
    40,   /* 1: of_aggregate_stats_reply */
    56,   /* 2: of_aggregate_stats_request */
    -1,   /* 3: of_async_get_reply */
    -1,   /* 4: of_async_get_request */
    -1,   /* 5: of_async_set */
    12,   /* 6: of_bad_action_error_msg */
    12,   /* 7: of_bad_instruction_error_msg */
    12,   /* 8: of_bad_match_error_msg */
    12,   /* 9: of_bad_request_error_msg */
    8,    /* 10: of_barrier_reply */
    8,    /* 11: of_barrier_request */
    -1,   /* 12: of_bsn_arp_idle */
    20,   /* 13: of_bsn_bw_clear_data_reply */
    16,   /* 14: of_bsn_bw_clear_data_request */
    20,   /* 15: of_bsn_bw_enable_get_reply */
    16,   /* 16: of_bsn_bw_enable_get_request */
    24,   /* 17: of_bsn_bw_enable_set_reply */
    20,   /* 18: of_bsn_bw_enable_set_request */
    -1,   /* 19: of_bsn_controller_connections_reply */
    -1,   /* 20: of_bsn_controller_connections_request */
    -1,   /* 21: of_bsn_debug_counter_desc_stats_reply */
    -1,   /* 22: of_bsn_debug_counter_desc_stats_request */
    -1,   /* 23: of_bsn_debug_counter_stats_reply */
    -1,   /* 24: of_bsn_debug_counter_stats_request */
    -1,   /* 25: of_bsn_flow_checksum_bucket_stats_reply */
    -1,   /* 26: of_bsn_flow_checksum_bucket_stats_request */
    -1,   /* 27: of_bsn_flow_idle */
    -1,   /* 28: of_bsn_flow_idle_enable_get_reply */
    -1,   /* 29: of_bsn_flow_idle_enable_get_request */
    -1,   /* 30: of_bsn_flow_idle_enable_set_reply */
    -1,   /* 31: of_bsn_flow_idle_enable_set_request */
    -1,   /* 32: of_bsn_gentable_bucket_stats_reply */
    -1,   /* 33: of_bsn_gentable_bucket_stats_request */
    -1,   /* 34: of_bsn_gentable_clear_reply */
    -1,   /* 35: of_bsn_gentable_clear_request */
    -1,   /* 36: of_bsn_gentable_desc_stats_reply */
    -1,   /* 37: of_bsn_gentable_desc_stats_request */
    -1,   /* 38: of_bsn_gentable_entry_add */
    -1,   /* 39: of_bsn_gentable_entry_delete */
    -1,   /* 40: of_bsn_gentable_entry_desc_stats_reply */
    -1,   /* 41: of_bsn_gentable_entry_desc_stats_request */
    -1,   /* 42: of_bsn_gentable_entry_stats_reply */
    -1,   /* 43: of_bsn_gentable_entry_stats_request */
    -1,   /* 44: of_bsn_gentable_set_buckets_size */
    -1,   /* 45: of_bsn_gentable_stats_reply */
    -1,   /* 46: of_bsn_gentable_stats_request */
    16,   /* 47: of_bsn_get_interfaces_reply */
    16,   /* 48: of_bsn_get_interfaces_request */
    -1,   /* 49: of_bsn_get_ip_mask_reply */
    -1,   /* 50: of_bsn_get_ip_mask_request */
    -1,   /* 51: of_bsn_get_l2_table_reply */
    -1,   /* 52: of_bsn_get_l2_table_request */
    20,   /* 53: of_bsn_get_mirroring_reply */
    20,   /* 54: of_bsn_get_mirroring_request */
    -1,   /* 55: of_bsn_get_switch_pipeline_reply */
    -1,   /* 56: of_bsn_get_switch_pipeline_request */
    16,   /* 57: of_bsn_header */
    -1,   /* 58: of_bsn_hybrid_get_reply */
    -1,   /* 59: of_bsn_hybrid_get_request */
    -1,   /* 60: of_bsn_image_desc_stats_reply */
    -1,   /* 61: of_bsn_image_desc_stats_request */
    -1,   /* 62: of_bsn_lacp_convergence_notif */
    -1,   /* 63: of_bsn_lacp_stats_reply */
    -1,   /* 64: of_bsn_lacp_stats_request */
    -1,   /* 65: of_bsn_log */
    25,   /* 66: of_bsn_pdu_rx_reply */
    28,   /* 67: of_bsn_pdu_rx_request */
    21,   /* 68: of_bsn_pdu_rx_timeout */
    25,   /* 69: of_bsn_pdu_tx_reply */
    28,   /* 70: of_bsn_pdu_tx_request */
    -1,   /* 71: of_bsn_port_counter_stats_reply */
    -1,   /* 72: of_bsn_port_counter_stats_request */
    -1,   /* 73: of_bsn_role_status */
    -1,   /* 74: of_bsn_set_aux_cxns_reply */
    -1,   /* 75: of_bsn_set_aux_cxns_request */
    -1,   /* 76: of_bsn_set_ip_mask */
    -1,   /* 77: of_bsn_set_l2_table_reply */
    -1,   /* 78: of_bsn_set_l2_table_request */
    -1,   /* 79: of_bsn_set_lacp_reply */
    -1,   /* 80: of_bsn_set_lacp_request */
    20,   /* 81: of_bsn_set_mirroring */
    20,   /* 82: of_bsn_set_pktin_suppression_reply */
    32,   /* 83: of_bsn_set_pktin_suppression_request */
    -1,   /* 84: of_bsn_set_switch_pipeline_reply */
    -1,   /* 85: of_bsn_set_switch_pipeline_request */
    -1,   /* 86: of_bsn_shell_command */
    -1,   /* 87: of_bsn_shell_output */
    -1,   /* 88: of_bsn_shell_status */
    24,   /* 89: of_bsn_stats_reply */
    24,   /* 90: of_bsn_stats_request */
    -1,   /* 91: of_bsn_switch_pipeline_stats_reply */
    -1,   /* 92: of_bsn_switch_pipeline_stats_request */
    -1,   /* 93: of_bsn_table_checksum_stats_reply */
    -1,   /* 94: of_bsn_table_checksum_stats_request */
    -1,   /* 95: of_bsn_table_set_buckets_size */
    -1,   /* 96: of_bsn_time_reply */
    -1,   /* 97: of_bsn_time_request */
    24,   /* 98: of_bsn_virtual_port_create_reply */
    20,   /* 99: of_bsn_virtual_port_create_request */
    20,   /* 100: of_bsn_virtual_port_remove_reply */
    20,   /* 101: of_bsn_virtual_port_remove_request */
    -1,   /* 102: of_bsn_vlan_counter_stats_reply */
    -1,   /* 103: of_bsn_vlan_counter_stats_request */
    -1,   /* 104: of_bsn_vrf_counter_stats_reply */
    -1,   /* 105: of_bsn_vrf_counter_stats_request */
    -1,   /* 106: of_bundle_add_msg */
    -1,   /* 107: of_bundle_ctrl_msg */
    1072, /* 108: of_desc_stats_reply */
    16,   /* 109: of_desc_stats_request */
    8,    /* 110: of_echo_reply */
    8,    /* 111: of_echo_request */
    10,   /* 112: of_error_msg */
    16,   /* 113: of_experimenter */
    16,   /* 114: of_experimenter_error_msg */
    24,   /* 115: of_experimenter_stats_reply */
    24,   /* 116: of_experimenter_stats_request */
    32,   /* 117: of_features_reply */
    8,    /* 118: of_features_request */
    56,   /* 119: of_flow_add */
    56,   /* 120: of_flow_delete */
    56,   /* 121: of_flow_delete_strict */
    56,   /* 122: of_flow_mod */
    12,   /* 123: of_flow_mod_failed_error_msg */
    56,   /* 124: of_flow_modify */
    56,   /* 125: of_flow_modify_strict */
    56,   /* 126: of_flow_removed */
    16,   /* 127: of_flow_stats_reply */
    56,   /* 128: of_flow_stats_request */
    12,   /* 129: of_get_config_reply */
    8,    /* 130: of_get_config_request */
    16,   /* 131: of_group_add */
    16,   /* 132: of_group_delete */
    16,   /* 133: of_group_desc_stats_reply */
    16,   /* 134: of_group_desc_stats_request */
    56,   /* 135: of_group_features_stats_reply */
    16,   /* 136: of_group_features_stats_request */
    16,   /* 137: of_group_mod */
    12,   /* 138: of_group_mod_failed_error_msg */
    16,   /* 139: of_group_modify */
    16,   /* 140: of_group_stats_reply */
    24,   /* 141: of_group_stats_request */
    8,    /* 142: of_header */
    8,    /* 143: of_hello */
    12,   /* 144: of_hello_failed_error_msg */
    -1,   /* 145: of_meter_config_stats_reply */
    -1,   /* 146: of_meter_config_stats_request */
    -1,   /* 147: of_meter_features_stats_reply */
    -1,   /* 148: of_meter_features_stats_request */
    -1,   /* 149: of_meter_mod */
    -1,   /* 150: of_meter_mod_failed_error_msg */
    -1,   /* 151: of_meter_stats_reply */
    -1,   /* 152: of_meter_stats_request */
    -1,   /* 153: of_nicira_controller_role_reply */
    -1,   /* 154: of_nicira_controller_role_request */
    16,   /* 155: of_nicira_header */
    26,   /* 156: of_packet_in */
    24,   /* 157: of_packet_out */
    -1,   /* 158: of_port_desc_stats_reply */
    -1,   /* 159: of_port_desc_stats_request */
    40,   /* 160: of_port_mod */
    12,   /* 161: of_port_mod_failed_error_msg */
    16,   /* 162: of_port_stats_reply */
    24,   /* 163: of_port_stats_request */
    80,   /* 164: of_port_status */
    -1,   /* 165: of_queue_desc_stats_reply */
    -1,   /* 166: of_queue_desc_stats_request */
    16,   /* 167: of_queue_get_config_reply */
    16,   /* 168: of_queue_get_config_request */
    12,   /* 169: of_queue_op_failed_error_msg */
    16,   /* 170: of_queue_stats_reply */
    24,   /* 171: of_queue_stats_request */
    -1,   /* 172: of_requestforward */
    24,   /* 173: of_role_reply */
    24,   /* 174: of_role_request */
    12,   /* 175: of_role_request_failed_error_msg */
    -1,   /* 176: of_role_status */
    12,   /* 177: of_set_config */
    16,   /* 178: of_stats_reply */
    16,   /* 179: of_stats_request */
    12,   /* 180: of_switch_config_failed_error_msg */
    -1,   /* 181: of_table_desc_stats_reply */
    -1,   /* 182: of_table_desc_stats_request */
    -1,   /* 183: of_table_features_failed_error_msg */
    -1,   /* 184: of_table_features_stats_reply */
    -1,   /* 185: of_table_features_stats_request */
    16,   /* 186: of_table_mod */
    12,   /* 187: of_table_mod_failed_error_msg */
    16,   /* 188: of_table_stats_reply */
    16,   /* 189: of_table_stats_request */
    -1,   /* 190: of_table_status */
    8,    /* 191: of_action */
    16,   /* 192: of_action_bsn */
    28,   /* 193: of_action_bsn_checksum */
    -1,   /* 194: of_action_bsn_gentable */
    24,   /* 195: of_action_bsn_mirror */
    16,   /* 196: of_action_bsn_set_tunnel_dst */
    8,    /* 197: of_action_copy_ttl_in */
    8,    /* 198: of_action_copy_ttl_out */
    8,    /* 199: of_action_dec_mpls_ttl */
    8,    /* 200: of_action_dec_nw_ttl */
    -1,   /* 201: of_action_enqueue */
    8,    /* 202: of_action_experimenter */
    8,    /* 203: of_action_group */
    8,    /* 204: of_action_header */
    -1,   /* 205: of_action_id */
    -1,   /* 206: of_action_id_bsn */
    -1,   /* 207: of_action_id_bsn_checksum */
    -1,   /* 208: of_action_id_bsn_gentable */
    -1,   /* 209: of_action_id_bsn_mirror */
    -1,   /* 210: of_action_id_bsn_set_tunnel_dst */
    -1,   /* 211: of_action_id_copy_ttl_in */
    -1,   /* 212: of_action_id_copy_ttl_out */
    -1,   /* 213: of_action_id_dec_mpls_ttl */
    -1,   /* 214: of_action_id_dec_nw_ttl */
    -1,   /* 215: of_action_id_experimenter */
    -1,   /* 216: of_action_id_group */
    -1,   /* 217: of_action_id_header */
    -1,   /* 218: of_action_id_nicira */
    -1,   /* 219: of_action_id_nicira_dec_ttl */
    -1,   /* 220: of_action_id_output */
    -1,   /* 221: of_action_id_pop_mpls */
    -1,   /* 222: of_action_id_pop_pbb */
    -1,   /* 223: of_action_id_pop_vlan */
    -1,   /* 224: of_action_id_push_mpls */
    -1,   /* 225: of_action_id_push_pbb */
    -1,   /* 226: of_action_id_push_vlan */
    -1,   /* 227: of_action_id_set_field */
    -1,   /* 228: of_action_id_set_mpls_ttl */
    -1,   /* 229: of_action_id_set_nw_ttl */
    -1,   /* 230: of_action_id_set_queue */
    16,   /* 231: of_action_nicira */
    16,   /* 232: of_action_nicira_dec_ttl */
    16,   /* 233: of_action_output */
    8,    /* 234: of_action_pop_mpls */
    -1,   /* 235: of_action_pop_pbb */
    8,    /* 236: of_action_pop_vlan */
    8,    /* 237: of_action_push_mpls */
    -1,   /* 238: of_action_push_pbb */
    8,    /* 239: of_action_push_vlan */
    -1,   /* 240: of_action_set_dl_dst */
    -1,   /* 241: of_action_set_dl_src */
    8,    /* 242: of_action_set_field */
    -1,   /* 243: of_action_set_mpls_label */
    -1,   /* 244: of_action_set_mpls_tc */
    8,    /* 245: of_action_set_mpls_ttl */
    -1,   /* 246: of_action_set_nw_dst */
    -1,   /* 247: of_action_set_nw_ecn */
    -1,   /* 248: of_action_set_nw_src */
    -1,   /* 249: of_action_set_nw_tos */
    8,    /* 250: of_action_set_nw_ttl */
    8,    /* 251: of_action_set_queue */
    -1,   /* 252: of_action_set_tp_dst */
    -1,   /* 253: of_action_set_tp_src */
    -1,   /* 254: of_action_set_vlan_pcp */
    -1,   /* 255: of_action_set_vlan_vid */
    -1,   /* 256: of_action_strip_vlan */
    -1,   /* 257: of_async_config_prop */
    -1,   /* 258: of_async_config_prop_experimenter_master */
    -1,   /* 259: of_async_config_prop_experimenter_slave */
    -1,   /* 260: of_async_config_prop_flow_removed_master */
    -1,   /* 261: of_async_config_prop_flow_removed_slave */
    -1,   /* 262: of_async_config_prop_header */
    -1,   /* 263: of_async_config_prop_packet_in_master */
    -1,   /* 264: of_async_config_prop_packet_in_slave */
    -1,   /* 265: of_async_config_prop_port_status_master */
    -1,   /* 266: of_async_config_prop_port_status_slave */
    -1,   /* 267: of_async_config_prop_requestforward_master */
    -1,   /* 268: of_async_config_prop_requestforward_slave */
    -1,   /* 269: of_async_config_prop_role_status_master */
    -1,   /* 270: of_async_config_prop_role_status_slave */
    -1,   /* 271: of_async_config_prop_table_status_master */
    -1,   /* 272: of_async_config_prop_table_status_slave */
    -1,   /* 273: of_bsn_controller_connection */
    -1,   /* 274: of_bsn_debug_counter_desc_stats_entry */
    -1,   /* 275: of_bsn_debug_counter_stats_entry */
    -1,   /* 276: of_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 277: of_bsn_gentable_bucket_stats_entry */
    -1,   /* 278: of_bsn_gentable_desc_stats_entry */
    -1,   /* 279: of_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 280: of_bsn_gentable_entry_stats_entry */
    -1,   /* 281: of_bsn_gentable_stats_entry */
    32,   /* 282: of_bsn_interface */
    -1,   /* 283: of_bsn_lacp_stats_entry */
    -1,   /* 284: of_bsn_port_counter_stats_entry */
    -1,   /* 285: of_bsn_switch_pipeline_stats_entry */
    -1,   /* 286: of_bsn_table_checksum_stats_entry */
    -1,   /* 287: of_bsn_tlv */
    -1,   /* 288: of_bsn_tlv_actor_key */
    -1,   /* 289: of_bsn_tlv_actor_port_num */
    -1,   /* 290: of_bsn_tlv_actor_port_priority */
    -1,   /* 291: of_bsn_tlv_actor_state */
    -1,   /* 292: of_bsn_tlv_actor_system_mac */
    -1,   /* 293: of_bsn_tlv_actor_system_priority */
    -1,   /* 294: of_bsn_tlv_broadcast_query_timeout */
    -1,   /* 295: of_bsn_tlv_circuit_id */
    -1,   /* 296: of_bsn_tlv_convergence_status */
    -1,   /* 297: of_bsn_tlv_crc_enabled */
    -1,   /* 298: of_bsn_tlv_data */
    -1,   /* 299: of_bsn_tlv_eth_dst */
    -1,   /* 300: of_bsn_tlv_eth_src */
    -1,   /* 301: of_bsn_tlv_external_gateway_ip */
    -1,   /* 302: of_bsn_tlv_external_gateway_mac */
    -1,   /* 303: of_bsn_tlv_external_ip */
    -1,   /* 304: of_bsn_tlv_external_mac */
    -1,   /* 305: of_bsn_tlv_external_netmask */
    -1,   /* 306: of_bsn_tlv_header */
    -1,   /* 307: of_bsn_tlv_header_size */
    -1,   /* 308: of_bsn_tlv_idle_notification */
    -1,   /* 309: of_bsn_tlv_idle_time */
    -1,   /* 310: of_bsn_tlv_idle_timeout */
    -1,   /* 311: of_bsn_tlv_internal_gateway_mac */
    -1,   /* 312: of_bsn_tlv_internal_mac */
    -1,   /* 313: of_bsn_tlv_ipv4 */
    -1,   /* 314: of_bsn_tlv_ipv4_dst */
    -1,   /* 315: of_bsn_tlv_ipv4_src */
    -1,   /* 316: of_bsn_tlv_mac */
    -1,   /* 317: of_bsn_tlv_miss_packets */
    -1,   /* 318: of_bsn_tlv_name */
    -1,   /* 319: of_bsn_tlv_partner_key */
    -1,   /* 320: of_bsn_tlv_partner_port_num */
    -1,   /* 321: of_bsn_tlv_partner_port_priority */
    -1,   /* 322: of_bsn_tlv_partner_state */
    -1,   /* 323: of_bsn_tlv_partner_system_mac */
    -1,   /* 324: of_bsn_tlv_partner_system_priority */
    -1,   /* 325: of_bsn_tlv_port */
    -1,   /* 326: of_bsn_tlv_queue_id */
    -1,   /* 327: of_bsn_tlv_queue_weight */
    -1,   /* 328: of_bsn_tlv_reply_packets */
    -1,   /* 329: of_bsn_tlv_request_packets */
    -1,   /* 330: of_bsn_tlv_rx_packets */
    -1,   /* 331: of_bsn_tlv_sampling_rate */
    -1,   /* 332: of_bsn_tlv_sub_agent_id */
    -1,   /* 333: of_bsn_tlv_tx_bytes */
    -1,   /* 334: of_bsn_tlv_tx_packets */
    -1,   /* 335: of_bsn_tlv_udf_anchor */
    -1,   /* 336: of_bsn_tlv_udf_id */
    -1,   /* 337: of_bsn_tlv_udf_length */
    -1,   /* 338: of_bsn_tlv_udf_offset */
    -1,   /* 339: of_bsn_tlv_udp_dst */
    -1,   /* 340: of_bsn_tlv_udp_src */
    -1,   /* 341: of_bsn_tlv_unicast_query_timeout */
    -1,   /* 342: of_bsn_tlv_vlan_vid */
    -1,   /* 343: of_bsn_tlv_vrf */
    -1,   /* 344: of_bsn_vlan_counter_stats_entry */
    4,    /* 345: of_bsn_vport */
    4,    /* 346: of_bsn_vport_header */
    64,   /* 347: of_bsn_vport_l2gre */
    32,   /* 348: of_bsn_vport_q_in_q */
    -1,   /* 349: of_bsn_vrf_counter_stats_entry */
    16,   /* 350: of_bucket */
    16,   /* 351: of_bucket_counter */
    -1,   /* 352: of_bundle_prop */
    -1,   /* 353: of_bundle_prop_experimenter */
    -1,   /* 354: of_bundle_prop_header */
    56,   /* 355: of_flow_stats_entry */
    8,    /* 356: of_group_desc_stats_entry */
    32,   /* 357: of_group_stats_entry */
    -1,   /* 358: of_hello_elem */
    -1,   /* 359: of_hello_elem_header */
    -1,   /* 360: of_hello_elem_versionbitmap */
    8,    /* 361: of_instruction */
    8,    /* 362: of_instruction_apply_actions */
    -1,   /* 363: of_instruction_bsn */
    -1,   /* 364: of_instruction_bsn_arp_offload */
    -1,   /* 365: of_instruction_bsn_deny */
    -1,   /* 366: of_instruction_bsn_dhcp_offload */
    -1,   /* 367: of_instruction_bsn_disable_split_horizon_check */
    -1,   /* 368: of_instruction_bsn_disable_src_mac_check */
    -1,   /* 369: of_instruction_bsn_disable_vlan_counters */
    -1,   /* 370: of_instruction_bsn_packet_of_death */
    -1,   /* 371: of_instruction_bsn_permit */
    -1,   /* 372: of_instruction_bsn_prioritize_pdus */
    -1,   /* 373: of_instruction_bsn_require_vlan_xlate */
    -1,   /* 374: of_instruction_bsn_span_destination */
    8,    /* 375: of_instruction_clear_actions */
    8,    /* 376: of_instruction_experimenter */
    8,    /* 377: of_instruction_goto_table */
    8,    /* 378: of_instruction_header */
    -1,   /* 379: of_instruction_id */
    -1,   /* 380: of_instruction_id_apply_actions */
    -1,   /* 381: of_instruction_id_bsn */
    -1,   /* 382: of_instruction_id_bsn_arp_offload */
    -1,   /* 383: of_instruction_id_bsn_deny */
    -1,   /* 384: of_instruction_id_bsn_dhcp_offload */
    -1,   /* 385: of_instruction_id_bsn_disable_split_horizon_check */
    -1,   /* 386: of_instruction_id_bsn_disable_src_mac_check */
    -1,   /* 387: of_instruction_id_bsn_disable_vlan_counters */
    -1,   /* 388: of_instruction_id_bsn_packet_of_death */
    -1,   /* 389: of_instruction_id_bsn_permit */
    -1,   /* 390: of_instruction_id_bsn_prioritize_pdus */
    -1,   /* 391: of_instruction_id_bsn_require_vlan_xlate */
    -1,   /* 392: of_instruction_id_bsn_span_destination */
    -1,   /* 393: of_instruction_id_clear_actions */
    -1,   /* 394: of_instruction_id_experimenter */
    -1,   /* 395: of_instruction_id_goto_table */
    -1,   /* 396: of_instruction_id_header */
    -1,   /* 397: of_instruction_id_meter */
    -1,   /* 398: of_instruction_id_write_actions */
    -1,   /* 399: of_instruction_id_write_metadata */
    -1,   /* 400: of_instruction_meter */
    8,    /* 401: of_instruction_write_actions */
    24,   /* 402: of_instruction_write_metadata */
    -1,   /* 403: of_match_v1 */
    -1,   /* 404: of_match_v2 */
    4,    /* 405: of_match_v3 */
    -1,   /* 406: of_meter_band */
    -1,   /* 407: of_meter_band_drop */
    -1,   /* 408: of_meter_band_dscp_remark */
    -1,   /* 409: of_meter_band_experimenter */
    -1,   /* 410: of_meter_band_header */
    -1,   /* 411: of_meter_band_stats */
    -1,   /* 412: of_meter_config */
    -1,   /* 413: of_meter_features */
    -1,   /* 414: of_meter_stats */
    4,    /* 415: of_oxm */
    6,    /* 416: of_oxm_arp_op */
    8,    /* 417: of_oxm_arp_op_masked */
    10,   /* 418: of_oxm_arp_sha */
    16,   /* 419: of_oxm_arp_sha_masked */
    8,    /* 420: of_oxm_arp_spa */
    12,   /* 421: of_oxm_arp_spa_masked */
    10,   /* 422: of_oxm_arp_tha */
    16,   /* 423: of_oxm_arp_tha_masked */
    8,    /* 424: of_oxm_arp_tpa */
    12,   /* 425: of_oxm_arp_tpa_masked */
    8,    /* 426: of_oxm_bsn_egr_port_group_id */
    12,   /* 427: of_oxm_bsn_egr_port_group_id_masked */
    5,    /* 428: of_oxm_bsn_global_vrf_allowed */
    6,    /* 429: of_oxm_bsn_global_vrf_allowed_masked */
    20,   /* 430: of_oxm_bsn_in_ports_128 */
    36,   /* 431: of_oxm_bsn_in_ports_128_masked */
    8,    /* 432: of_oxm_bsn_l3_dst_class_id */
    12,   /* 433: of_oxm_bsn_l3_dst_class_id_masked */
    8,    /* 434: of_oxm_bsn_l3_interface_class_id */
    12,   /* 435: of_oxm_bsn_l3_interface_class_id_masked */
    8,    /* 436: of_oxm_bsn_l3_src_class_id */
    12,   /* 437: of_oxm_bsn_l3_src_class_id_masked */
    8,    /* 438: of_oxm_bsn_lag_id */
    12,   /* 439: of_oxm_bsn_lag_id_masked */
    6,    /* 440: of_oxm_bsn_tcp_flags */
    8,    /* 441: of_oxm_bsn_tcp_flags_masked */
    8,    /* 442: of_oxm_bsn_udf0 */
    12,   /* 443: of_oxm_bsn_udf0_masked */
    8,    /* 444: of_oxm_bsn_udf1 */
    12,   /* 445: of_oxm_bsn_udf1_masked */
    8,    /* 446: of_oxm_bsn_udf2 */
    12,   /* 447: of_oxm_bsn_udf2_masked */
    8,    /* 448: of_oxm_bsn_udf3 */
    12,   /* 449: of_oxm_bsn_udf3_masked */
    8,    /* 450: of_oxm_bsn_udf4 */
    12,   /* 451: of_oxm_bsn_udf4_masked */
    8,    /* 452: of_oxm_bsn_udf5 */
    12,   /* 453: of_oxm_bsn_udf5_masked */
    8,    /* 454: of_oxm_bsn_udf6 */
    12,   /* 455: of_oxm_bsn_udf6_masked */
    8,    /* 456: of_oxm_bsn_udf7 */
    12,   /* 457: of_oxm_bsn_udf7_masked */
    8,    /* 458: of_oxm_bsn_vlan_xlate_port_group_id */
    12,   /* 459: of_oxm_bsn_vlan_xlate_port_group_id_masked */
    8,    /* 460: of_oxm_bsn_vrf */
    12,   /* 461: of_oxm_bsn_vrf_masked */
    10,   /* 462: of_oxm_eth_dst */
    16,   /* 463: of_oxm_eth_dst_masked */
    10,   /* 464: of_oxm_eth_src */
    16,   /* 465: of_oxm_eth_src_masked */
    6,    /* 466: of_oxm_eth_type */
    8,    /* 467: of_oxm_eth_type_masked */
    4,    /* 468: of_oxm_header */
    5,    /* 469: of_oxm_icmpv4_code */
    6,    /* 470: of_oxm_icmpv4_code_masked */
    5,    /* 471: of_oxm_icmpv4_type */
    6,    /* 472: of_oxm_icmpv4_type_masked */
    5,    /* 473: of_oxm_icmpv6_code */
    6,    /* 474: of_oxm_icmpv6_code_masked */
    5,    /* 475: of_oxm_icmpv6_type */
    6,    /* 476: of_oxm_icmpv6_type_masked */
    8,    /* 477: of_oxm_in_phy_port */
    12,   /* 478: of_oxm_in_phy_port_masked */
    8,    /* 479: of_oxm_in_port */
    12,   /* 480: of_oxm_in_port_masked */
    5,    /* 481: of_oxm_ip_dscp */
    6,    /* 482: of_oxm_ip_dscp_masked */
    5,    /* 483: of_oxm_ip_ecn */
    6,    /* 484: of_oxm_ip_ecn_masked */
    5,    /* 485: of_oxm_ip_proto */
    6,    /* 486: of_oxm_ip_proto_masked */
    8,    /* 487: of_oxm_ipv4_dst */
    12,   /* 488: of_oxm_ipv4_dst_masked */
    8,    /* 489: of_oxm_ipv4_src */
    12,   /* 490: of_oxm_ipv4_src_masked */
    20,   /* 491: of_oxm_ipv6_dst */
    36,   /* 492: of_oxm_ipv6_dst_masked */
    8,    /* 493: of_oxm_ipv6_flabel */
    12,   /* 494: of_oxm_ipv6_flabel_masked */
    10,   /* 495: of_oxm_ipv6_nd_sll */
    16,   /* 496: of_oxm_ipv6_nd_sll_masked */
    20,   /* 497: of_oxm_ipv6_nd_target */
    36,   /* 498: of_oxm_ipv6_nd_target_masked */
    10,   /* 499: of_oxm_ipv6_nd_tll */
    16,   /* 500: of_oxm_ipv6_nd_tll_masked */
    20,   /* 501: of_oxm_ipv6_src */
    36,   /* 502: of_oxm_ipv6_src_masked */
    12,   /* 503: of_oxm_metadata */
    20,   /* 504: of_oxm_metadata_masked */
    -1,   /* 505: of_oxm_mpls_bos */
    -1,   /* 506: of_oxm_mpls_bos_masked */
    8,    /* 507: of_oxm_mpls_label */
    12,   /* 508: of_oxm_mpls_label_masked */
    5,    /* 509: of_oxm_mpls_tc */
    6,    /* 510: of_oxm_mpls_tc_masked */
    6,    /* 511: of_oxm_sctp_dst */
    8,    /* 512: of_oxm_sctp_dst_masked */
    6,    /* 513: of_oxm_sctp_src */
    8,    /* 514: of_oxm_sctp_src_masked */
    6,    /* 515: of_oxm_tcp_dst */
    8,    /* 516: of_oxm_tcp_dst_masked */
    6,    /* 517: of_oxm_tcp_src */
    8,    /* 518: of_oxm_tcp_src_masked */
    -1,   /* 519: of_oxm_tunnel_id */
    -1,   /* 520: of_oxm_tunnel_id_masked */
    6,    /* 521: of_oxm_udp_dst */
    8,    /* 522: of_oxm_udp_dst_masked */
    6,    /* 523: of_oxm_udp_src */
    8,    /* 524: of_oxm_udp_src_masked */
    5,    /* 525: of_oxm_vlan_pcp */
    6,    /* 526: of_oxm_vlan_pcp_masked */
    6,    /* 527: of_oxm_vlan_vid */
    8,    /* 528: of_oxm_vlan_vid_masked */
    16,   /* 529: of_packet_queue */
    64,   /* 530: of_port_desc */
    -1,   /* 531: of_port_desc_prop */
    -1,   /* 532: of_port_desc_prop_ethernet */
    -1,   /* 533: of_port_desc_prop_experimenter */
    -1,   /* 534: of_port_desc_prop_header */
    -1,   /* 535: of_port_desc_prop_optical */
    -1,   /* 536: of_port_mod_prop */
    -1,   /* 537: of_port_mod_prop_ethernet */
    -1,   /* 538: of_port_mod_prop_experimenter */
    -1,   /* 539: of_port_mod_prop_header */
    -1,   /* 540: of_port_mod_prop_optical */
    104,  /* 541: of_port_stats_entry */
    -1,   /* 542: of_port_stats_prop */
    -1,   /* 543: of_port_stats_prop_ethernet */
    -1,   /* 544: of_port_stats_prop_experimenter */
    -1,   /* 545: of_port_stats_prop_header */
    -1,   /* 546: of_port_stats_prop_optical */
    -1,   /* 547: of_queue_desc */
    -1,   /* 548: of_queue_desc_prop */
    -1,   /* 549: of_queue_desc_prop_experimenter */
    -1,   /* 550: of_queue_desc_prop_header */
    -1,   /* 551: of_queue_desc_prop_max_rate */
    -1,   /* 552: of_queue_desc_prop_min_rate */
    8,    /* 553: of_queue_prop */
    16,   /* 554: of_queue_prop_experimenter */
    8,    /* 555: of_queue_prop_header */
    16,   /* 556: of_queue_prop_max_rate */
    16,   /* 557: of_queue_prop_min_rate */
    32,   /* 558: of_queue_stats_entry */
    -1,   /* 559: of_queue_stats_prop */
    -1,   /* 560: of_queue_stats_prop_experimenter */
    -1,   /* 561: of_queue_stats_prop_header */
    -1,   /* 562: of_role_prop */
    -1,   /* 563: of_role_prop_experimenter */
    -1,   /* 564: of_role_prop_header */
    -1,   /* 565: of_table_desc */
    -1,   /* 566: of_table_feature_prop */
    -1,   /* 567: of_table_feature_prop_apply_actions */
    -1,   /* 568: of_table_feature_prop_apply_actions_miss */
    -1,   /* 569: of_table_feature_prop_apply_setfield */
    -1,   /* 570: of_table_feature_prop_apply_setfield_miss */
    -1,   /* 571: of_table_feature_prop_experimenter */
    -1,   /* 572: of_table_feature_prop_experimenter_miss */
    -1,   /* 573: of_table_feature_prop_header */
    -1,   /* 574: of_table_feature_prop_instructions */
    -1,   /* 575: of_table_feature_prop_instructions_miss */
    -1,   /* 576: of_table_feature_prop_match */
    -1,   /* 577: of_table_feature_prop_next_tables */
    -1,   /* 578: of_table_feature_prop_next_tables_miss */
    -1,   /* 579: of_table_feature_prop_table_sync_from */
    -1,   /* 580: of_table_feature_prop_wildcards */
    -1,   /* 581: of_table_feature_prop_write_actions */
    -1,   /* 582: of_table_feature_prop_write_actions_miss */
    -1,   /* 583: of_table_feature_prop_write_setfield */
    -1,   /* 584: of_table_feature_prop_write_setfield_miss */
    -1,   /* 585: of_table_features */
    -1,   /* 586: of_table_mod_prop */
    -1,   /* 587: of_table_mod_prop_eviction */
    -1,   /* 588: of_table_mod_prop_experimenter */
    -1,   /* 589: of_table_mod_prop_vacancy */
    128,  /* 590: of_table_stats_entry */
    -1,   /* 591: of_uint32 */
    -1,   /* 592: of_uint64 */
    -1,   /* 593: of_uint8 */
    0,    /* 594: of_list_action */
    -1,   /* 595: of_list_action_id */
    -1,   /* 596: of_list_async_config_prop */
    -1,   /* 597: of_list_bsn_controller_connection */
    -1,   /* 598: of_list_bsn_debug_counter_desc_stats_entry */
    -1,   /* 599: of_list_bsn_debug_counter_stats_entry */
    -1,   /* 600: of_list_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 601: of_list_bsn_gentable_bucket_stats_entry */
    -1,   /* 602: of_list_bsn_gentable_desc_stats_entry */
    -1,   /* 603: of_list_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 604: of_list_bsn_gentable_entry_stats_entry */
    -1,   /* 605: of_list_bsn_gentable_stats_entry */
    0,    /* 606: of_list_bsn_interface */
    -1,   /* 607: of_list_bsn_lacp_stats_entry */
    -1,   /* 608: of_list_bsn_port_counter_stats_entry */
    -1,   /* 609: of_list_bsn_switch_pipeline_stats_entry */
    -1,   /* 610: of_list_bsn_table_checksum_stats_entry */
    -1,   /* 611: of_list_bsn_tlv */
    -1,   /* 612: of_list_bsn_vlan_counter_stats_entry */
    -1,   /* 613: of_list_bsn_vrf_counter_stats_entry */
    0,    /* 614: of_list_bucket */
    0,    /* 615: of_list_bucket_counter */
    -1,   /* 616: of_list_bundle_prop */
    0,    /* 617: of_list_flow_stats_entry */
    0,    /* 618: of_list_group_desc_stats_entry */
    0,    /* 619: of_list_group_stats_entry */
    -1,   /* 620: of_list_hello_elem */
    0,    /* 621: of_list_instruction */
    -1,   /* 622: of_list_instruction_id */
    -1,   /* 623: of_list_meter_band */
    -1,   /* 624: of_list_meter_band_stats */
    -1,   /* 625: of_list_meter_stats */
    0,    /* 626: of_list_oxm */
    0,    /* 627: of_list_packet_queue */
    0,    /* 628: of_list_port_desc */
    -1,   /* 629: of_list_port_desc_prop */
    -1,   /* 630: of_list_port_mod_prop */
    0,    /* 631: of_list_port_stats_entry */
    -1,   /* 632: of_list_port_stats_prop */
    -1,   /* 633: of_list_queue_desc */
    -1,   /* 634: of_list_queue_desc_prop */
    0,    /* 635: of_list_queue_prop */
    0,    /* 636: of_list_queue_stats_entry */
    -1,   /* 637: of_list_queue_stats_prop */
    -1,   /* 638: of_list_role_prop */
    -1,   /* 639: of_list_table_desc */
    -1,   /* 640: of_list_table_feature_prop */
    -1,   /* 641: of_list_table_features */
    -1,   /* 642: of_list_table_mod_prop */
    0,    /* 643: of_list_table_stats_entry */
    -1,   /* 644: of_list_uint32 */
    -1,   /* 645: of_list_uint64 */
    -1    /* 646: of_list_uint8 */
};

static const int
of_object_fixed_len_v4[OF_OBJECT_COUNT] = {
    -1,   /* of_object is not instantiable */
    40,   /* 1: of_aggregate_stats_reply */
    56,   /* 2: of_aggregate_stats_request */
    32,   /* 3: of_async_get_reply */
    32,   /* 4: of_async_get_request */
    32,   /* 5: of_async_set */
    12,   /* 6: of_bad_action_error_msg */
    12,   /* 7: of_bad_instruction_error_msg */
    12,   /* 8: of_bad_match_error_msg */
    12,   /* 9: of_bad_request_error_msg */
    8,    /* 10: of_barrier_reply */
    8,    /* 11: of_barrier_request */
    24,   /* 12: of_bsn_arp_idle */
    20,   /* 13: of_bsn_bw_clear_data_reply */
    16,   /* 14: of_bsn_bw_clear_data_request */
    20,   /* 15: of_bsn_bw_enable_get_reply */
    16,   /* 16: of_bsn_bw_enable_get_request */
    24,   /* 17: of_bsn_bw_enable_set_reply */
    20,   /* 18: of_bsn_bw_enable_set_request */
    16,   /* 19: of_bsn_controller_connections_reply */
    16,   /* 20: of_bsn_controller_connections_request */
    24,   /* 21: of_bsn_debug_counter_desc_stats_reply */
    24,   /* 22: of_bsn_debug_counter_desc_stats_request */
    24,   /* 23: of_bsn_debug_counter_stats_reply */
    24,   /* 24: of_bsn_debug_counter_stats_request */
    24,   /* 25: of_bsn_flow_checksum_bucket_stats_reply */
    25,   /* 26: of_bsn_flow_checksum_bucket_stats_request */
    40,   /* 27: of_bsn_flow_idle */
    20,   /* 28: of_bsn_flow_idle_enable_get_reply */
    16,   /* 29: of_bsn_flow_idle_enable_get_request */
    24,   /* 30: of_bsn_flow_idle_enable_set_reply */
    20,   /* 31: of_bsn_flow_idle_enable_set_request */
    24,   /* 32: of_bsn_gentable_bucket_stats_reply */
    26,   /* 33: of_bsn_gentable_bucket_stats_request */
    28,   /* 34: of_bsn_gentable_clear_reply */
    52,   /* 35: of_bsn_gentable_clear_request */
    24,   /* 36: of_bsn_gentable_desc_stats_reply */
    24,   /* 37: of_bsn_gentable_desc_stats_request */
    36,   /* 38: of_bsn_gentable_entry_add */
    18,   /* 39: of_bsn_gentable_entry_delete */
    24,   /* 40: of_bsn_gentable_entry_desc_stats_reply */
    60,   /* 41: of_bsn_gentable_entry_desc_stats_request */
    24,   /* 42: of_bsn_gentable_entry_stats_reply */
    60,   /* 43: of_bsn_gentable_entry_stats_request */
    24,   /* 44: of_bsn_gentable_set_buckets_size */
    24,   /* 45: of_bsn_gentable_stats_reply */
    24,   /* 46: of_bsn_gentable_stats_request */
    16,   /* 47: of_bsn_get_interfaces_reply */
    16,   /* 48: of_bsn_get_interfaces_request */
    -1,   /* 49: of_bsn_get_ip_mask_reply */
    -1,   /* 50: of_bsn_get_ip_mask_request */
    -1,   /* 51: of_bsn_get_l2_table_reply */
    -1,   /* 52: of_bsn_get_l2_table_request */
    20,   /* 53: of_bsn_get_mirroring_reply */
    20,   /* 54: of_bsn_get_mirroring_request */
    272,  /* 55: of_bsn_get_switch_pipeline_reply */
    16,   /* 56: of_bsn_get_switch_pipeline_request */
    16,   /* 57: of_bsn_header */
    -1,   /* 58: of_bsn_hybrid_get_reply */
    -1,   /* 59: of_bsn_hybrid_get_request */
    536,  /* 60: of_bsn_image_desc_stats_reply */
    24,   /* 61: of_bsn_image_desc_stats_request */
    52,   /* 62: of_bsn_lacp_convergence_notif */
    24,   /* 63: of_bsn_lacp_stats_reply */
    24,   /* 64: of_bsn_lacp_stats_request */
    17,   /* 65: of_bsn_log */
    25,   /* 66: of_bsn_pdu_rx_reply */
    28,   /* 67: of_bsn_pdu_rx_request */
    21,   /* 68: of_bsn_pdu_rx_timeout */
    25,   /* 69: of_bsn_pdu_tx_reply */
    28,   /* 70: of_bsn_pdu_tx_request */
    24,   /* 71: of_bsn_port_counter_stats_reply */
    28,   /* 72: of_bsn_port_counter_stats_request */
    32,   /* 73: of_bsn_role_status */
    24,   /* 74: of_bsn_set_aux_cxns_reply */
    20,   /* 75: of_bsn_set_aux_cxns_request */
    -1,   /* 76: of_bsn_set_ip_mask */
    -1,   /* 77: of_bsn_set_l2_table_reply */
    -1,   /* 78: of_bsn_set_l2_table_request */
    24,   /* 79: of_bsn_set_lacp_reply */
    38,   /* 80: of_bsn_set_lacp_request */
    20,   /* 81: of_bsn_set_mirroring */
    20,   /* 82: of_bsn_set_pktin_suppression_reply */
    32,   /* 83: of_bsn_set_pktin_suppression_request */
    20,   /* 84: of_bsn_set_switch_pipeline_reply */
    272,  /* 85: of_bsn_set_switch_pipeline_request */
    -1,   /* 86: of_bsn_shell_command */
    -1,   /* 87: of_bsn_shell_output */
    -1,   /* 88: of_bsn_shell_status */
    24,   /* 89: of_bsn_stats_reply */
    24,   /* 90: of_bsn_stats_request */
    24,   /* 91: of_bsn_switch_pipeline_stats_reply */
    24,   /* 92: of_bsn_switch_pipeline_stats_request */
    24,   /* 93: of_bsn_table_checksum_stats_reply */
    24,   /* 94: of_bsn_table_checksum_stats_request */
    24,   /* 95: of_bsn_table_set_buckets_size */
    24,   /* 96: of_bsn_time_reply */
    16,   /* 97: of_bsn_time_request */
    24,   /* 98: of_bsn_virtual_port_create_reply */
    20,   /* 99: of_bsn_virtual_port_create_request */
    20,   /* 100: of_bsn_virtual_port_remove_reply */
    20,   /* 101: of_bsn_virtual_port_remove_request */
    24,   /* 102: of_bsn_vlan_counter_stats_reply */
    26,   /* 103: of_bsn_vlan_counter_stats_request */
    24,   /* 104: of_bsn_vrf_counter_stats_reply */
    28,   /* 105: of_bsn_vrf_counter_stats_request */
    -1,   /* 106: of_bundle_add_msg */
    -1,   /* 107: of_bundle_ctrl_msg */
    1072, /* 108: of_desc_stats_reply */
    16,   /* 109: of_desc_stats_request */
    8,    /* 110: of_echo_reply */
    8,    /* 111: of_echo_request */
    10,   /* 112: of_error_msg */
    16,   /* 113: of_experimenter */
    16,   /* 114: of_experimenter_error_msg */
    24,   /* 115: of_experimenter_stats_reply */
    24,   /* 116: of_experimenter_stats_request */
    32,   /* 117: of_features_reply */
    8,    /* 118: of_features_request */
    56,   /* 119: of_flow_add */
    56,   /* 120: of_flow_delete */
    56,   /* 121: of_flow_delete_strict */
    56,   /* 122: of_flow_mod */
    12,   /* 123: of_flow_mod_failed_error_msg */
    56,   /* 124: of_flow_modify */
    56,   /* 125: of_flow_modify_strict */
    56,   /* 126: of_flow_removed */
    16,   /* 127: of_flow_stats_reply */
    56,   /* 128: of_flow_stats_request */
    12,   /* 129: of_get_config_reply */
    8,    /* 130: of_get_config_request */
    16,   /* 131: of_group_add */
    16,   /* 132: of_group_delete */
    16,   /* 133: of_group_desc_stats_reply */
    16,   /* 134: of_group_desc_stats_request */
    56,   /* 135: of_group_features_stats_reply */
    16,   /* 136: of_group_features_stats_request */
    16,   /* 137: of_group_mod */
    12,   /* 138: of_group_mod_failed_error_msg */
    16,   /* 139: of_group_modify */
    16,   /* 140: of_group_stats_reply */
    24,   /* 141: of_group_stats_request */
    8,    /* 142: of_header */
    8,    /* 143: of_hello */
    12,   /* 144: of_hello_failed_error_msg */
    16,   /* 145: of_meter_config_stats_reply */
    24,   /* 146: of_meter_config_stats_request */
    32,   /* 147: of_meter_features_stats_reply */
    16,   /* 148: of_meter_features_stats_request */
    16,   /* 149: of_meter_mod */
    12,   /* 150: of_meter_mod_failed_error_msg */
    16,   /* 151: of_meter_stats_reply */
    24,   /* 152: of_meter_stats_request */
    -1,   /* 153: of_nicira_controller_role_reply */
    -1,   /* 154: of_nicira_controller_role_request */
    16,   /* 155: of_nicira_header */
    34,   /* 156: of_packet_in */
    24,   /* 157: of_packet_out */
    16,   /* 158: of_port_desc_stats_reply */
    16,   /* 159: of_port_desc_stats_request */
    40,   /* 160: of_port_mod */
    12,   /* 161: of_port_mod_failed_error_msg */
    16,   /* 162: of_port_stats_reply */
    24,   /* 163: of_port_stats_request */
    80,   /* 164: of_port_status */
    -1,   /* 165: of_queue_desc_stats_reply */
    -1,   /* 166: of_queue_desc_stats_request */
    16,   /* 167: of_queue_get_config_reply */
    16,   /* 168: of_queue_get_config_request */
    12,   /* 169: of_queue_op_failed_error_msg */
    16,   /* 170: of_queue_stats_reply */
    24,   /* 171: of_queue_stats_request */
    -1,   /* 172: of_requestforward */
    24,   /* 173: of_role_reply */
    24,   /* 174: of_role_request */
    12,   /* 175: of_role_request_failed_error_msg */
    -1,   /* 176: of_role_status */
    12,   /* 177: of_set_config */
    16,   /* 178: of_stats_reply */
    16,   /* 179: of_stats_request */
    12,   /* 180: of_switch_config_failed_error_msg */
    -1,   /* 181: of_table_desc_stats_reply */
    -1,   /* 182: of_table_desc_stats_request */
    12,   /* 183: of_table_features_failed_error_msg */
    16,   /* 184: of_table_features_stats_reply */
    16,   /* 185: of_table_features_stats_request */
    16,   /* 186: of_table_mod */
    12,   /* 187: of_table_mod_failed_error_msg */
    16,   /* 188: of_table_stats_reply */
    16,   /* 189: of_table_stats_request */
    -1,   /* 190: of_table_status */
    8,    /* 191: of_action */
    16,   /* 192: of_action_bsn */
    28,   /* 193: of_action_bsn_checksum */
    16,   /* 194: of_action_bsn_gentable */
    24,   /* 195: of_action_bsn_mirror */
    16,   /* 196: of_action_bsn_set_tunnel_dst */
    8,    /* 197: of_action_copy_ttl_in */
    8,    /* 198: of_action_copy_ttl_out */
    8,    /* 199: of_action_dec_mpls_ttl */
    8,    /* 200: of_action_dec_nw_ttl */
    -1,   /* 201: of_action_enqueue */
    8,    /* 202: of_action_experimenter */
    8,    /* 203: of_action_group */
    8,    /* 204: of_action_header */
    4,    /* 205: of_action_id */
    12,   /* 206: of_action_id_bsn */
    12,   /* 207: of_action_id_bsn_checksum */
    12,   /* 208: of_action_id_bsn_gentable */
    12,   /* 209: of_action_id_bsn_mirror */
    12,   /* 210: of_action_id_bsn_set_tunnel_dst */
    4,    /* 211: of_action_id_copy_ttl_in */
    4,    /* 212: of_action_id_copy_ttl_out */
    4,    /* 213: of_action_id_dec_mpls_ttl */
    4,    /* 214: of_action_id_dec_nw_ttl */
    8,    /* 215: of_action_id_experimenter */
    4,    /* 216: of_action_id_group */
    4,    /* 217: of_action_id_header */
    10,   /* 218: of_action_id_nicira */
    10,   /* 219: of_action_id_nicira_dec_ttl */
    4,    /* 220: of_action_id_output */
    4,    /* 221: of_action_id_pop_mpls */
    4,    /* 222: of_action_id_pop_pbb */
    4,    /* 223: of_action_id_pop_vlan */
    4,    /* 224: of_action_id_push_mpls */
    4,    /* 225: of_action_id_push_pbb */
    4,    /* 226: of_action_id_push_vlan */
    4,    /* 227: of_action_id_set_field */
    4,    /* 228: of_action_id_set_mpls_ttl */
    4,    /* 229: of_action_id_set_nw_ttl */
    4,    /* 230: of_action_id_set_queue */
    16,   /* 231: of_action_nicira */
    16,   /* 232: of_action_nicira_dec_ttl */
    16,   /* 233: of_action_output */
    8,    /* 234: of_action_pop_mpls */
    8,    /* 235: of_action_pop_pbb */
    8,    /* 236: of_action_pop_vlan */
    8,    /* 237: of_action_push_mpls */
    8,    /* 238: of_action_push_pbb */
    8,    /* 239: of_action_push_vlan */
    -1,   /* 240: of_action_set_dl_dst */
    -1,   /* 241: of_action_set_dl_src */
    8,    /* 242: of_action_set_field */
    -1,   /* 243: of_action_set_mpls_label */
    -1,   /* 244: of_action_set_mpls_tc */
    8,    /* 245: of_action_set_mpls_ttl */
    -1,   /* 246: of_action_set_nw_dst */
    -1,   /* 247: of_action_set_nw_ecn */
    -1,   /* 248: of_action_set_nw_src */
    -1,   /* 249: of_action_set_nw_tos */
    8,    /* 250: of_action_set_nw_ttl */
    8,    /* 251: of_action_set_queue */
    -1,   /* 252: of_action_set_tp_dst */
    -1,   /* 253: of_action_set_tp_src */
    -1,   /* 254: of_action_set_vlan_pcp */
    -1,   /* 255: of_action_set_vlan_vid */
    -1,   /* 256: of_action_strip_vlan */
    -1,   /* 257: of_async_config_prop */
    -1,   /* 258: of_async_config_prop_experimenter_master */
    -1,   /* 259: of_async_config_prop_experimenter_slave */
    -1,   /* 260: of_async_config_prop_flow_removed_master */
    -1,   /* 261: of_async_config_prop_flow_removed_slave */
    -1,   /* 262: of_async_config_prop_header */
    -1,   /* 263: of_async_config_prop_packet_in_master */
    -1,   /* 264: of_async_config_prop_packet_in_slave */
    -1,   /* 265: of_async_config_prop_port_status_master */
    -1,   /* 266: of_async_config_prop_port_status_slave */
    -1,   /* 267: of_async_config_prop_requestforward_master */
    -1,   /* 268: of_async_config_prop_requestforward_slave */
    -1,   /* 269: of_async_config_prop_role_status_master */
    -1,   /* 270: of_async_config_prop_role_status_slave */
    -1,   /* 271: of_async_config_prop_table_status_master */
    -1,   /* 272: of_async_config_prop_table_status_slave */
    264,  /* 273: of_bsn_controller_connection */
    328,  /* 274: of_bsn_debug_counter_desc_stats_entry */
    16,   /* 275: of_bsn_debug_counter_stats_entry */
    8,    /* 276: of_bsn_flow_checksum_bucket_stats_entry */
    16,   /* 277: of_bsn_gentable_bucket_stats_entry */
    48,   /* 278: of_bsn_gentable_desc_stats_entry */
    20,   /* 279: of_bsn_gentable_entry_desc_stats_entry */
    4,    /* 280: of_bsn_gentable_entry_stats_entry */
    24,   /* 281: of_bsn_gentable_stats_entry */
    32,   /* 282: of_bsn_interface */
    36,   /* 283: of_bsn_lacp_stats_entry */
    8,    /* 284: of_bsn_port_counter_stats_entry */
    256,  /* 285: of_bsn_switch_pipeline_stats_entry */
    9,    /* 286: of_bsn_table_checksum_stats_entry */
    4,    /* 287: of_bsn_tlv */
    6,    /* 288: of_bsn_tlv_actor_key */
    6,    /* 289: of_bsn_tlv_actor_port_num */
    6,    /* 290: of_bsn_tlv_actor_port_priority */
    5,    /* 291: of_bsn_tlv_actor_state */
    10,   /* 292: of_bsn_tlv_actor_system_mac */
    6,    /* 293: of_bsn_tlv_actor_system_priority */
    8,    /* 294: of_bsn_tlv_broadcast_query_timeout */
    4,    /* 295: of_bsn_tlv_circuit_id */
    5,    /* 296: of_bsn_tlv_convergence_status */
    5,    /* 297: of_bsn_tlv_crc_enabled */
    4,    /* 298: of_bsn_tlv_data */
    10,   /* 299: of_bsn_tlv_eth_dst */
    10,   /* 300: of_bsn_tlv_eth_src */
    8,    /* 301: of_bsn_tlv_external_gateway_ip */
    10,   /* 302: of_bsn_tlv_external_gateway_mac */
    8,    /* 303: of_bsn_tlv_external_ip */
    10,   /* 304: of_bsn_tlv_external_mac */
    8,    /* 305: of_bsn_tlv_external_netmask */
    4,    /* 306: of_bsn_tlv_header */
    8,    /* 307: of_bsn_tlv_header_size */
    4,    /* 308: of_bsn_tlv_idle_notification */
    12,   /* 309: of_bsn_tlv_idle_time */
    8,    /* 310: of_bsn_tlv_idle_timeout */
    10,   /* 311: of_bsn_tlv_internal_gateway_mac */
    10,   /* 312: of_bsn_tlv_internal_mac */
    8,    /* 313: of_bsn_tlv_ipv4 */
    8,    /* 314: of_bsn_tlv_ipv4_dst */
    8,    /* 315: of_bsn_tlv_ipv4_src */
    10,   /* 316: of_bsn_tlv_mac */
    12,   /* 317: of_bsn_tlv_miss_packets */
    4,    /* 318: of_bsn_tlv_name */
    6,    /* 319: of_bsn_tlv_partner_key */
    6,    /* 320: of_bsn_tlv_partner_port_num */
    6,    /* 321: of_bsn_tlv_partner_port_priority */
    5,    /* 322: of_bsn_tlv_partner_state */
    10,   /* 323: of_bsn_tlv_partner_system_mac */
    6,    /* 324: of_bsn_tlv_partner_system_priority */
    8,    /* 325: of_bsn_tlv_port */
    8,    /* 326: of_bsn_tlv_queue_id */
    8,    /* 327: of_bsn_tlv_queue_weight */
    12,   /* 328: of_bsn_tlv_reply_packets */
    12,   /* 329: of_bsn_tlv_request_packets */
    12,   /* 330: of_bsn_tlv_rx_packets */
    8,    /* 331: of_bsn_tlv_sampling_rate */
    8,    /* 332: of_bsn_tlv_sub_agent_id */
    12,   /* 333: of_bsn_tlv_tx_bytes */
    12,   /* 334: of_bsn_tlv_tx_packets */
    6,    /* 335: of_bsn_tlv_udf_anchor */
    6,    /* 336: of_bsn_tlv_udf_id */
    6,    /* 337: of_bsn_tlv_udf_length */
    6,    /* 338: of_bsn_tlv_udf_offset */
    6,    /* 339: of_bsn_tlv_udp_dst */
    6,    /* 340: of_bsn_tlv_udp_src */
    8,    /* 341: of_bsn_tlv_unicast_query_timeout */
    6,    /* 342: of_bsn_tlv_vlan_vid */
    8,    /* 343: of_bsn_tlv_vrf */
    8,    /* 344: of_bsn_vlan_counter_stats_entry */
    4,    /* 345: of_bsn_vport */
    4,    /* 346: of_bsn_vport_header */
    64,   /* 347: of_bsn_vport_l2gre */
    32,   /* 348: of_bsn_vport_q_in_q */
    8,    /* 349: of_bsn_vrf_counter_stats_entry */
    16,   /* 350: of_bucket */
    16,   /* 351: of_bucket_counter */
    -1,   /* 352: of_bundle_prop */
    -1,   /* 353: of_bundle_prop_experimenter */
    -1,   /* 354: of_bundle_prop_header */
    56,   /* 355: of_flow_stats_entry */
    8,    /* 356: of_group_desc_stats_entry */
    40,   /* 357: of_group_stats_entry */
    4,    /* 358: of_hello_elem */
    4,    /* 359: of_hello_elem_header */
    4,    /* 360: of_hello_elem_versionbitmap */
    4,    /* 361: of_instruction */
    8,    /* 362: of_instruction_apply_actions */
    16,   /* 363: of_instruction_bsn */
    16,   /* 364: of_instruction_bsn_arp_offload */
    16,   /* 365: of_instruction_bsn_deny */
    16,   /* 366: of_instruction_bsn_dhcp_offload */
    16,   /* 367: of_instruction_bsn_disable_split_horizon_check */
    16,   /* 368: of_instruction_bsn_disable_src_mac_check */
    16,   /* 369: of_instruction_bsn_disable_vlan_counters */
    16,   /* 370: of_instruction_bsn_packet_of_death */
    16,   /* 371: of_instruction_bsn_permit */
    16,   /* 372: of_instruction_bsn_prioritize_pdus */
    16,   /* 373: of_instruction_bsn_require_vlan_xlate */
    16,   /* 374: of_instruction_bsn_span_destination */
    8,    /* 375: of_instruction_clear_actions */
    8,    /* 376: of_instruction_experimenter */
    8,    /* 377: of_instruction_goto_table */
    4,    /* 378: of_instruction_header */
    4,    /* 379: of_instruction_id */
    4,    /* 380: of_instruction_id_apply_actions */
    12,   /* 381: of_instruction_id_bsn */
    12,   /* 382: of_instruction_id_bsn_arp_offload */
    12,   /* 383: of_instruction_id_bsn_deny */
    12,   /* 384: of_instruction_id_bsn_dhcp_offload */
    12,   /* 385: of_instruction_id_bsn_disable_split_horizon_check */
    12,   /* 386: of_instruction_id_bsn_disable_src_mac_check */
    12,   /* 387: of_instruction_id_bsn_disable_vlan_counters */
    12,   /* 388: of_instruction_id_bsn_packet_of_death */
    12,   /* 389: of_instruction_id_bsn_permit */
    12,   /* 390: of_instruction_id_bsn_prioritize_pdus */
    12,   /* 391: of_instruction_id_bsn_require_vlan_xlate */
    12,   /* 392: of_instruction_id_bsn_span_destination */
    4,    /* 393: of_instruction_id_clear_actions */
    8,    /* 394: of_instruction_id_experimenter */
    4,    /* 395: of_instruction_id_goto_table */
    4,    /* 396: of_instruction_id_header */
    4,    /* 397: of_instruction_id_meter */
    4,    /* 398: of_instruction_id_write_actions */
    4,    /* 399: of_instruction_id_write_metadata */
    8,    /* 400: of_instruction_meter */
    8,    /* 401: of_instruction_write_actions */
    24,   /* 402: of_instruction_write_metadata */
    -1,   /* 403: of_match_v1 */
    -1,   /* 404: of_match_v2 */
    4,    /* 405: of_match_v3 */
    4,    /* 406: of_meter_band */
    16,   /* 407: of_meter_band_drop */
    16,   /* 408: of_meter_band_dscp_remark */
    16,   /* 409: of_meter_band_experimenter */
    4,    /* 410: of_meter_band_header */
    16,   /* 411: of_meter_band_stats */
    8,    /* 412: of_meter_config */
    16,   /* 413: of_meter_features */
    40,   /* 414: of_meter_stats */
    4,    /* 415: of_oxm */
    6,    /* 416: of_oxm_arp_op */
    8,    /* 417: of_oxm_arp_op_masked */
    10,   /* 418: of_oxm_arp_sha */
    16,   /* 419: of_oxm_arp_sha_masked */
    8,    /* 420: of_oxm_arp_spa */
    12,   /* 421: of_oxm_arp_spa_masked */
    10,   /* 422: of_oxm_arp_tha */
    16,   /* 423: of_oxm_arp_tha_masked */
    8,    /* 424: of_oxm_arp_tpa */
    12,   /* 425: of_oxm_arp_tpa_masked */
    8,    /* 426: of_oxm_bsn_egr_port_group_id */
    12,   /* 427: of_oxm_bsn_egr_port_group_id_masked */
    5,    /* 428: of_oxm_bsn_global_vrf_allowed */
    6,    /* 429: of_oxm_bsn_global_vrf_allowed_masked */
    20,   /* 430: of_oxm_bsn_in_ports_128 */
    36,   /* 431: of_oxm_bsn_in_ports_128_masked */
    8,    /* 432: of_oxm_bsn_l3_dst_class_id */
    12,   /* 433: of_oxm_bsn_l3_dst_class_id_masked */
    8,    /* 434: of_oxm_bsn_l3_interface_class_id */
    12,   /* 435: of_oxm_bsn_l3_interface_class_id_masked */
    8,    /* 436: of_oxm_bsn_l3_src_class_id */
    12,   /* 437: of_oxm_bsn_l3_src_class_id_masked */
    8,    /* 438: of_oxm_bsn_lag_id */
    12,   /* 439: of_oxm_bsn_lag_id_masked */
    6,    /* 440: of_oxm_bsn_tcp_flags */
    8,    /* 441: of_oxm_bsn_tcp_flags_masked */
    8,    /* 442: of_oxm_bsn_udf0 */
    12,   /* 443: of_oxm_bsn_udf0_masked */
    8,    /* 444: of_oxm_bsn_udf1 */
    12,   /* 445: of_oxm_bsn_udf1_masked */
    8,    /* 446: of_oxm_bsn_udf2 */
    12,   /* 447: of_oxm_bsn_udf2_masked */
    8,    /* 448: of_oxm_bsn_udf3 */
    12,   /* 449: of_oxm_bsn_udf3_masked */
    8,    /* 450: of_oxm_bsn_udf4 */
    12,   /* 451: of_oxm_bsn_udf4_masked */
    8,    /* 452: of_oxm_bsn_udf5 */
    12,   /* 453: of_oxm_bsn_udf5_masked */
    8,    /* 454: of_oxm_bsn_udf6 */
    12,   /* 455: of_oxm_bsn_udf6_masked */
    8,    /* 456: of_oxm_bsn_udf7 */
    12,   /* 457: of_oxm_bsn_udf7_masked */
    8,    /* 458: of_oxm_bsn_vlan_xlate_port_group_id */
    12,   /* 459: of_oxm_bsn_vlan_xlate_port_group_id_masked */
    8,    /* 460: of_oxm_bsn_vrf */
    12,   /* 461: of_oxm_bsn_vrf_masked */
    10,   /* 462: of_oxm_eth_dst */
    16,   /* 463: of_oxm_eth_dst_masked */
    10,   /* 464: of_oxm_eth_src */
    16,   /* 465: of_oxm_eth_src_masked */
    6,    /* 466: of_oxm_eth_type */
    8,    /* 467: of_oxm_eth_type_masked */
    4,    /* 468: of_oxm_header */
    5,    /* 469: of_oxm_icmpv4_code */
    6,    /* 470: of_oxm_icmpv4_code_masked */
    5,    /* 471: of_oxm_icmpv4_type */
    6,    /* 472: of_oxm_icmpv4_type_masked */
    5,    /* 473: of_oxm_icmpv6_code */
    6,    /* 474: of_oxm_icmpv6_code_masked */
    5,    /* 475: of_oxm_icmpv6_type */
    6,    /* 476: of_oxm_icmpv6_type_masked */
    8,    /* 477: of_oxm_in_phy_port */
    12,   /* 478: of_oxm_in_phy_port_masked */
    8,    /* 479: of_oxm_in_port */
    12,   /* 480: of_oxm_in_port_masked */
    5,    /* 481: of_oxm_ip_dscp */
    6,    /* 482: of_oxm_ip_dscp_masked */
    5,    /* 483: of_oxm_ip_ecn */
    6,    /* 484: of_oxm_ip_ecn_masked */
    5,    /* 485: of_oxm_ip_proto */
    6,    /* 486: of_oxm_ip_proto_masked */
    8,    /* 487: of_oxm_ipv4_dst */
    12,   /* 488: of_oxm_ipv4_dst_masked */
    8,    /* 489: of_oxm_ipv4_src */
    12,   /* 490: of_oxm_ipv4_src_masked */
    20,   /* 491: of_oxm_ipv6_dst */
    36,   /* 492: of_oxm_ipv6_dst_masked */
    8,    /* 493: of_oxm_ipv6_flabel */
    12,   /* 494: of_oxm_ipv6_flabel_masked */
    10,   /* 495: of_oxm_ipv6_nd_sll */
    16,   /* 496: of_oxm_ipv6_nd_sll_masked */
    20,   /* 497: of_oxm_ipv6_nd_target */
    36,   /* 498: of_oxm_ipv6_nd_target_masked */
    10,   /* 499: of_oxm_ipv6_nd_tll */
    16,   /* 500: of_oxm_ipv6_nd_tll_masked */
    20,   /* 501: of_oxm_ipv6_src */
    36,   /* 502: of_oxm_ipv6_src_masked */
    12,   /* 503: of_oxm_metadata */
    20,   /* 504: of_oxm_metadata_masked */
    5,    /* 505: of_oxm_mpls_bos */
    6,    /* 506: of_oxm_mpls_bos_masked */
    8,    /* 507: of_oxm_mpls_label */
    12,   /* 508: of_oxm_mpls_label_masked */
    5,    /* 509: of_oxm_mpls_tc */
    6,    /* 510: of_oxm_mpls_tc_masked */
    6,    /* 511: of_oxm_sctp_dst */
    8,    /* 512: of_oxm_sctp_dst_masked */
    6,    /* 513: of_oxm_sctp_src */
    8,    /* 514: of_oxm_sctp_src_masked */
    6,    /* 515: of_oxm_tcp_dst */
    8,    /* 516: of_oxm_tcp_dst_masked */
    6,    /* 517: of_oxm_tcp_src */
    8,    /* 518: of_oxm_tcp_src_masked */
    12,   /* 519: of_oxm_tunnel_id */
    20,   /* 520: of_oxm_tunnel_id_masked */
    6,    /* 521: of_oxm_udp_dst */
    8,    /* 522: of_oxm_udp_dst_masked */
    6,    /* 523: of_oxm_udp_src */
    8,    /* 524: of_oxm_udp_src_masked */
    5,    /* 525: of_oxm_vlan_pcp */
    6,    /* 526: of_oxm_vlan_pcp_masked */
    6,    /* 527: of_oxm_vlan_vid */
    8,    /* 528: of_oxm_vlan_vid_masked */
    16,   /* 529: of_packet_queue */
    64,   /* 530: of_port_desc */
    -1,   /* 531: of_port_desc_prop */
    -1,   /* 532: of_port_desc_prop_ethernet */
    -1,   /* 533: of_port_desc_prop_experimenter */
    -1,   /* 534: of_port_desc_prop_header */
    -1,   /* 535: of_port_desc_prop_optical */
    -1,   /* 536: of_port_mod_prop */
    -1,   /* 537: of_port_mod_prop_ethernet */
    -1,   /* 538: of_port_mod_prop_experimenter */
    -1,   /* 539: of_port_mod_prop_header */
    -1,   /* 540: of_port_mod_prop_optical */
    112,  /* 541: of_port_stats_entry */
    -1,   /* 542: of_port_stats_prop */
    -1,   /* 543: of_port_stats_prop_ethernet */
    -1,   /* 544: of_port_stats_prop_experimenter */
    -1,   /* 545: of_port_stats_prop_header */
    -1,   /* 546: of_port_stats_prop_optical */
    -1,   /* 547: of_queue_desc */
    -1,   /* 548: of_queue_desc_prop */
    -1,   /* 549: of_queue_desc_prop_experimenter */
    -1,   /* 550: of_queue_desc_prop_header */
    -1,   /* 551: of_queue_desc_prop_max_rate */
    -1,   /* 552: of_queue_desc_prop_min_rate */
    8,    /* 553: of_queue_prop */
    16,   /* 554: of_queue_prop_experimenter */
    8,    /* 555: of_queue_prop_header */
    16,   /* 556: of_queue_prop_max_rate */
    16,   /* 557: of_queue_prop_min_rate */
    40,   /* 558: of_queue_stats_entry */
    -1,   /* 559: of_queue_stats_prop */
    -1,   /* 560: of_queue_stats_prop_experimenter */
    -1,   /* 561: of_queue_stats_prop_header */
    -1,   /* 562: of_role_prop */
    -1,   /* 563: of_role_prop_experimenter */
    -1,   /* 564: of_role_prop_header */
    -1,   /* 565: of_table_desc */
    4,    /* 566: of_table_feature_prop */
    4,    /* 567: of_table_feature_prop_apply_actions */
    4,    /* 568: of_table_feature_prop_apply_actions_miss */
    4,    /* 569: of_table_feature_prop_apply_setfield */
    4,    /* 570: of_table_feature_prop_apply_setfield_miss */
    12,   /* 571: of_table_feature_prop_experimenter */
    12,   /* 572: of_table_feature_prop_experimenter_miss */
    4,    /* 573: of_table_feature_prop_header */
    4,    /* 574: of_table_feature_prop_instructions */
    4,    /* 575: of_table_feature_prop_instructions_miss */
    4,    /* 576: of_table_feature_prop_match */
    4,    /* 577: of_table_feature_prop_next_tables */
    4,    /* 578: of_table_feature_prop_next_tables_miss */
    -1,   /* 579: of_table_feature_prop_table_sync_from */
    4,    /* 580: of_table_feature_prop_wildcards */
    4,    /* 581: of_table_feature_prop_write_actions */
    4,    /* 582: of_table_feature_prop_write_actions_miss */
    4,    /* 583: of_table_feature_prop_write_setfield */
    4,    /* 584: of_table_feature_prop_write_setfield_miss */
    64,   /* 585: of_table_features */
    -1,   /* 586: of_table_mod_prop */
    -1,   /* 587: of_table_mod_prop_eviction */
    -1,   /* 588: of_table_mod_prop_experimenter */
    -1,   /* 589: of_table_mod_prop_vacancy */
    24,   /* 590: of_table_stats_entry */
    4,    /* 591: of_uint32 */
    8,    /* 592: of_uint64 */
    1,    /* 593: of_uint8 */
    0,    /* 594: of_list_action */
    0,    /* 595: of_list_action_id */
    -1,   /* 596: of_list_async_config_prop */
    0,    /* 597: of_list_bsn_controller_connection */
    0,    /* 598: of_list_bsn_debug_counter_desc_stats_entry */
    0,    /* 599: of_list_bsn_debug_counter_stats_entry */
    0,    /* 600: of_list_bsn_flow_checksum_bucket_stats_entry */
    0,    /* 601: of_list_bsn_gentable_bucket_stats_entry */
    0,    /* 602: of_list_bsn_gentable_desc_stats_entry */
    0,    /* 603: of_list_bsn_gentable_entry_desc_stats_entry */
    0,    /* 604: of_list_bsn_gentable_entry_stats_entry */
    0,    /* 605: of_list_bsn_gentable_stats_entry */
    0,    /* 606: of_list_bsn_interface */
    0,    /* 607: of_list_bsn_lacp_stats_entry */
    0,    /* 608: of_list_bsn_port_counter_stats_entry */
    0,    /* 609: of_list_bsn_switch_pipeline_stats_entry */
    0,    /* 610: of_list_bsn_table_checksum_stats_entry */
    0,    /* 611: of_list_bsn_tlv */
    0,    /* 612: of_list_bsn_vlan_counter_stats_entry */
    0,    /* 613: of_list_bsn_vrf_counter_stats_entry */
    0,    /* 614: of_list_bucket */
    0,    /* 615: of_list_bucket_counter */
    -1,   /* 616: of_list_bundle_prop */
    0,    /* 617: of_list_flow_stats_entry */
    0,    /* 618: of_list_group_desc_stats_entry */
    0,    /* 619: of_list_group_stats_entry */
    0,    /* 620: of_list_hello_elem */
    0,    /* 621: of_list_instruction */
    0,    /* 622: of_list_instruction_id */
    0,    /* 623: of_list_meter_band */
    0,    /* 624: of_list_meter_band_stats */
    0,    /* 625: of_list_meter_stats */
    0,    /* 626: of_list_oxm */
    0,    /* 627: of_list_packet_queue */
    0,    /* 628: of_list_port_desc */
    -1,   /* 629: of_list_port_desc_prop */
    -1,   /* 630: of_list_port_mod_prop */
    0,    /* 631: of_list_port_stats_entry */
    -1,   /* 632: of_list_port_stats_prop */
    -1,   /* 633: of_list_queue_desc */
    -1,   /* 634: of_list_queue_desc_prop */
    0,    /* 635: of_list_queue_prop */
    0,    /* 636: of_list_queue_stats_entry */
    -1,   /* 637: of_list_queue_stats_prop */
    -1,   /* 638: of_list_role_prop */
    -1,   /* 639: of_list_table_desc */
    0,    /* 640: of_list_table_feature_prop */
    0,    /* 641: of_list_table_features */
    -1,   /* 642: of_list_table_mod_prop */
    0,    /* 643: of_list_table_stats_entry */
    0,    /* 644: of_list_uint32 */
    0,    /* 645: of_list_uint64 */
    0     /* 646: of_list_uint8 */
};

static const int
of_object_fixed_len_v5[OF_OBJECT_COUNT] = {
    -1,   /* of_object is not instantiable */
    40,   /* 1: of_aggregate_stats_reply */
    56,   /* 2: of_aggregate_stats_request */
    8,    /* 3: of_async_get_reply */
    8,    /* 4: of_async_get_request */
    8,    /* 5: of_async_set */
    12,   /* 6: of_bad_action_error_msg */
    12,   /* 7: of_bad_instruction_error_msg */
    12,   /* 8: of_bad_match_error_msg */
    12,   /* 9: of_bad_request_error_msg */
    8,    /* 10: of_barrier_reply */
    8,    /* 11: of_barrier_request */
    -1,   /* 12: of_bsn_arp_idle */
    20,   /* 13: of_bsn_bw_clear_data_reply */
    16,   /* 14: of_bsn_bw_clear_data_request */
    20,   /* 15: of_bsn_bw_enable_get_reply */
    16,   /* 16: of_bsn_bw_enable_get_request */
    24,   /* 17: of_bsn_bw_enable_set_reply */
    20,   /* 18: of_bsn_bw_enable_set_request */
    -1,   /* 19: of_bsn_controller_connections_reply */
    -1,   /* 20: of_bsn_controller_connections_request */
    -1,   /* 21: of_bsn_debug_counter_desc_stats_reply */
    -1,   /* 22: of_bsn_debug_counter_desc_stats_request */
    -1,   /* 23: of_bsn_debug_counter_stats_reply */
    -1,   /* 24: of_bsn_debug_counter_stats_request */
    -1,   /* 25: of_bsn_flow_checksum_bucket_stats_reply */
    -1,   /* 26: of_bsn_flow_checksum_bucket_stats_request */
    -1,   /* 27: of_bsn_flow_idle */
    -1,   /* 28: of_bsn_flow_idle_enable_get_reply */
    -1,   /* 29: of_bsn_flow_idle_enable_get_request */
    -1,   /* 30: of_bsn_flow_idle_enable_set_reply */
    -1,   /* 31: of_bsn_flow_idle_enable_set_request */
    -1,   /* 32: of_bsn_gentable_bucket_stats_reply */
    -1,   /* 33: of_bsn_gentable_bucket_stats_request */
    -1,   /* 34: of_bsn_gentable_clear_reply */
    -1,   /* 35: of_bsn_gentable_clear_request */
    -1,   /* 36: of_bsn_gentable_desc_stats_reply */
    -1,   /* 37: of_bsn_gentable_desc_stats_request */
    -1,   /* 38: of_bsn_gentable_entry_add */
    -1,   /* 39: of_bsn_gentable_entry_delete */
    -1,   /* 40: of_bsn_gentable_entry_desc_stats_reply */
    -1,   /* 41: of_bsn_gentable_entry_desc_stats_request */
    -1,   /* 42: of_bsn_gentable_entry_stats_reply */
    -1,   /* 43: of_bsn_gentable_entry_stats_request */
    -1,   /* 44: of_bsn_gentable_set_buckets_size */
    -1,   /* 45: of_bsn_gentable_stats_reply */
    -1,   /* 46: of_bsn_gentable_stats_request */
    16,   /* 47: of_bsn_get_interfaces_reply */
    16,   /* 48: of_bsn_get_interfaces_request */
    -1,   /* 49: of_bsn_get_ip_mask_reply */
    -1,   /* 50: of_bsn_get_ip_mask_request */
    -1,   /* 51: of_bsn_get_l2_table_reply */
    -1,   /* 52: of_bsn_get_l2_table_request */
    20,   /* 53: of_bsn_get_mirroring_reply */
    20,   /* 54: of_bsn_get_mirroring_request */
    -1,   /* 55: of_bsn_get_switch_pipeline_reply */
    -1,   /* 56: of_bsn_get_switch_pipeline_request */
    16,   /* 57: of_bsn_header */
    -1,   /* 58: of_bsn_hybrid_get_reply */
    -1,   /* 59: of_bsn_hybrid_get_request */
    -1,   /* 60: of_bsn_image_desc_stats_reply */
    -1,   /* 61: of_bsn_image_desc_stats_request */
    -1,   /* 62: of_bsn_lacp_convergence_notif */
    -1,   /* 63: of_bsn_lacp_stats_reply */
    -1,   /* 64: of_bsn_lacp_stats_request */
    -1,   /* 65: of_bsn_log */
    25,   /* 66: of_bsn_pdu_rx_reply */
    28,   /* 67: of_bsn_pdu_rx_request */
    21,   /* 68: of_bsn_pdu_rx_timeout */
    25,   /* 69: of_bsn_pdu_tx_reply */
    28,   /* 70: of_bsn_pdu_tx_request */
    -1,   /* 71: of_bsn_port_counter_stats_reply */
    -1,   /* 72: of_bsn_port_counter_stats_request */
    -1,   /* 73: of_bsn_role_status */
    -1,   /* 74: of_bsn_set_aux_cxns_reply */
    -1,   /* 75: of_bsn_set_aux_cxns_request */
    -1,   /* 76: of_bsn_set_ip_mask */
    -1,   /* 77: of_bsn_set_l2_table_reply */
    -1,   /* 78: of_bsn_set_l2_table_request */
    -1,   /* 79: of_bsn_set_lacp_reply */
    -1,   /* 80: of_bsn_set_lacp_request */
    20,   /* 81: of_bsn_set_mirroring */
    20,   /* 82: of_bsn_set_pktin_suppression_reply */
    32,   /* 83: of_bsn_set_pktin_suppression_request */
    -1,   /* 84: of_bsn_set_switch_pipeline_reply */
    -1,   /* 85: of_bsn_set_switch_pipeline_request */
    -1,   /* 86: of_bsn_shell_command */
    -1,   /* 87: of_bsn_shell_output */
    -1,   /* 88: of_bsn_shell_status */
    24,   /* 89: of_bsn_stats_reply */
    24,   /* 90: of_bsn_stats_request */
    -1,   /* 91: of_bsn_switch_pipeline_stats_reply */
    -1,   /* 92: of_bsn_switch_pipeline_stats_request */
    -1,   /* 93: of_bsn_table_checksum_stats_reply */
    -1,   /* 94: of_bsn_table_checksum_stats_request */
    -1,   /* 95: of_bsn_table_set_buckets_size */
    -1,   /* 96: of_bsn_time_reply */
    -1,   /* 97: of_bsn_time_request */
    24,   /* 98: of_bsn_virtual_port_create_reply */
    20,   /* 99: of_bsn_virtual_port_create_request */
    20,   /* 100: of_bsn_virtual_port_remove_reply */
    20,   /* 101: of_bsn_virtual_port_remove_request */
    -1,   /* 102: of_bsn_vlan_counter_stats_reply */
    -1,   /* 103: of_bsn_vlan_counter_stats_request */
    -1,   /* 104: of_bsn_vrf_counter_stats_reply */
    -1,   /* 105: of_bsn_vrf_counter_stats_request */
    16,   /* 106: of_bundle_add_msg */
    16,   /* 107: of_bundle_ctrl_msg */
    1072, /* 108: of_desc_stats_reply */
    16,   /* 109: of_desc_stats_request */
    8,    /* 110: of_echo_reply */
    8,    /* 111: of_echo_request */
    10,   /* 112: of_error_msg */
    16,   /* 113: of_experimenter */
    16,   /* 114: of_experimenter_error_msg */
    24,   /* 115: of_experimenter_stats_reply */
    24,   /* 116: of_experimenter_stats_request */
    32,   /* 117: of_features_reply */
    8,    /* 118: of_features_request */
    56,   /* 119: of_flow_add */
    56,   /* 120: of_flow_delete */
    56,   /* 121: of_flow_delete_strict */
    56,   /* 122: of_flow_mod */
    12,   /* 123: of_flow_mod_failed_error_msg */
    56,   /* 124: of_flow_modify */
    56,   /* 125: of_flow_modify_strict */
    56,   /* 126: of_flow_removed */
    16,   /* 127: of_flow_stats_reply */
    56,   /* 128: of_flow_stats_request */
    12,   /* 129: of_get_config_reply */
    8,    /* 130: of_get_config_request */
    16,   /* 131: of_group_add */
    16,   /* 132: of_group_delete */
    16,   /* 133: of_group_desc_stats_reply */
    16,   /* 134: of_group_desc_stats_request */
    56,   /* 135: of_group_features_stats_reply */
    16,   /* 136: of_group_features_stats_request */
    16,   /* 137: of_group_mod */
    12,   /* 138: of_group_mod_failed_error_msg */
    16,   /* 139: of_group_modify */
    16,   /* 140: of_group_stats_reply */
    24,   /* 141: of_group_stats_request */
    8,    /* 142: of_header */
    8,    /* 143: of_hello */
    12,   /* 144: of_hello_failed_error_msg */
    16,   /* 145: of_meter_config_stats_reply */
    24,   /* 146: of_meter_config_stats_request */
    32,   /* 147: of_meter_features_stats_reply */
    16,   /* 148: of_meter_features_stats_request */
    16,   /* 149: of_meter_mod */
    12,   /* 150: of_meter_mod_failed_error_msg */
    16,   /* 151: of_meter_stats_reply */
    24,   /* 152: of_meter_stats_request */
    -1,   /* 153: of_nicira_controller_role_reply */
    -1,   /* 154: of_nicira_controller_role_request */
    16,   /* 155: of_nicira_header */
    34,   /* 156: of_packet_in */
    24,   /* 157: of_packet_out */
    16,   /* 158: of_port_desc_stats_reply */
    16,   /* 159: of_port_desc_stats_request */
    32,   /* 160: of_port_mod */
    12,   /* 161: of_port_mod_failed_error_msg */
    16,   /* 162: of_port_stats_reply */
    24,   /* 163: of_port_stats_request */
    56,   /* 164: of_port_status */
    16,   /* 165: of_queue_desc_stats_reply */
    16,   /* 166: of_queue_desc_stats_request */
    -1,   /* 167: of_queue_get_config_reply */
    -1,   /* 168: of_queue_get_config_request */
    12,   /* 169: of_queue_op_failed_error_msg */
    16,   /* 170: of_queue_stats_reply */
    24,   /* 171: of_queue_stats_request */
    12,   /* 172: of_requestforward */
    24,   /* 173: of_role_reply */
    24,   /* 174: of_role_request */
    12,   /* 175: of_role_request_failed_error_msg */
    24,   /* 176: of_role_status */
    12,   /* 177: of_set_config */
    16,   /* 178: of_stats_reply */
    16,   /* 179: of_stats_request */
    12,   /* 180: of_switch_config_failed_error_msg */
    16,   /* 181: of_table_desc_stats_reply */
    16,   /* 182: of_table_desc_stats_request */
    12,   /* 183: of_table_features_failed_error_msg */
    16,   /* 184: of_table_features_stats_reply */
    16,   /* 185: of_table_features_stats_request */
    16,   /* 186: of_table_mod */
    12,   /* 187: of_table_mod_failed_error_msg */
    16,   /* 188: of_table_stats_reply */
    16,   /* 189: of_table_stats_request */
    28,   /* 190: of_table_status */
    8,    /* 191: of_action */
    16,   /* 192: of_action_bsn */
    28,   /* 193: of_action_bsn_checksum */
    -1,   /* 194: of_action_bsn_gentable */
    24,   /* 195: of_action_bsn_mirror */
    16,   /* 196: of_action_bsn_set_tunnel_dst */
    8,    /* 197: of_action_copy_ttl_in */
    8,    /* 198: of_action_copy_ttl_out */
    8,    /* 199: of_action_dec_mpls_ttl */
    8,    /* 200: of_action_dec_nw_ttl */
    -1,   /* 201: of_action_enqueue */
    8,    /* 202: of_action_experimenter */
    8,    /* 203: of_action_group */
    8,    /* 204: of_action_header */
    4,    /* 205: of_action_id */
    12,   /* 206: of_action_id_bsn */
    12,   /* 207: of_action_id_bsn_checksum */
    -1,   /* 208: of_action_id_bsn_gentable */
    12,   /* 209: of_action_id_bsn_mirror */
    12,   /* 210: of_action_id_bsn_set_tunnel_dst */
    4,    /* 211: of_action_id_copy_ttl_in */
    4,    /* 212: of_action_id_copy_ttl_out */
    4,    /* 213: of_action_id_dec_mpls_ttl */
    4,    /* 214: of_action_id_dec_nw_ttl */
    8,    /* 215: of_action_id_experimenter */
    4,    /* 216: of_action_id_group */
    4,    /* 217: of_action_id_header */
    10,   /* 218: of_action_id_nicira */
    10,   /* 219: of_action_id_nicira_dec_ttl */
    4,    /* 220: of_action_id_output */
    4,    /* 221: of_action_id_pop_mpls */
    4,    /* 222: of_action_id_pop_pbb */
    4,    /* 223: of_action_id_pop_vlan */
    4,    /* 224: of_action_id_push_mpls */
    4,    /* 225: of_action_id_push_pbb */
    4,    /* 226: of_action_id_push_vlan */
    4,    /* 227: of_action_id_set_field */
    4,    /* 228: of_action_id_set_mpls_ttl */
    4,    /* 229: of_action_id_set_nw_ttl */
    4,    /* 230: of_action_id_set_queue */
    16,   /* 231: of_action_nicira */
    16,   /* 232: of_action_nicira_dec_ttl */
    16,   /* 233: of_action_output */
    8,    /* 234: of_action_pop_mpls */
    8,    /* 235: of_action_pop_pbb */
    8,    /* 236: of_action_pop_vlan */
    8,    /* 237: of_action_push_mpls */
    8,    /* 238: of_action_push_pbb */
    8,    /* 239: of_action_push_vlan */
    -1,   /* 240: of_action_set_dl_dst */
    -1,   /* 241: of_action_set_dl_src */
    8,    /* 242: of_action_set_field */
    -1,   /* 243: of_action_set_mpls_label */
    -1,   /* 244: of_action_set_mpls_tc */
    8,    /* 245: of_action_set_mpls_ttl */
    -1,   /* 246: of_action_set_nw_dst */
    -1,   /* 247: of_action_set_nw_ecn */
    -1,   /* 248: of_action_set_nw_src */
    -1,   /* 249: of_action_set_nw_tos */
    8,    /* 250: of_action_set_nw_ttl */
    8,    /* 251: of_action_set_queue */
    -1,   /* 252: of_action_set_tp_dst */
    -1,   /* 253: of_action_set_tp_src */
    -1,   /* 254: of_action_set_vlan_pcp */
    -1,   /* 255: of_action_set_vlan_vid */
    -1,   /* 256: of_action_strip_vlan */
    4,    /* 257: of_async_config_prop */
    4,    /* 258: of_async_config_prop_experimenter_master */
    4,    /* 259: of_async_config_prop_experimenter_slave */
    8,    /* 260: of_async_config_prop_flow_removed_master */
    8,    /* 261: of_async_config_prop_flow_removed_slave */
    4,    /* 262: of_async_config_prop_header */
    8,    /* 263: of_async_config_prop_packet_in_master */
    8,    /* 264: of_async_config_prop_packet_in_slave */
    8,    /* 265: of_async_config_prop_port_status_master */
    8,    /* 266: of_async_config_prop_port_status_slave */
    8,    /* 267: of_async_config_prop_requestforward_master */
    8,    /* 268: of_async_config_prop_requestforward_slave */
    8,    /* 269: of_async_config_prop_role_status_master */
    8,    /* 270: of_async_config_prop_role_status_slave */
    8,    /* 271: of_async_config_prop_table_status_master */
    8,    /* 272: of_async_config_prop_table_status_slave */
    -1,   /* 273: of_bsn_controller_connection */
    -1,   /* 274: of_bsn_debug_counter_desc_stats_entry */
    -1,   /* 275: of_bsn_debug_counter_stats_entry */
    -1,   /* 276: of_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 277: of_bsn_gentable_bucket_stats_entry */
    -1,   /* 278: of_bsn_gentable_desc_stats_entry */
    -1,   /* 279: of_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 280: of_bsn_gentable_entry_stats_entry */
    -1,   /* 281: of_bsn_gentable_stats_entry */
    32,   /* 282: of_bsn_interface */
    -1,   /* 283: of_bsn_lacp_stats_entry */
    -1,   /* 284: of_bsn_port_counter_stats_entry */
    -1,   /* 285: of_bsn_switch_pipeline_stats_entry */
    -1,   /* 286: of_bsn_table_checksum_stats_entry */
    -1,   /* 287: of_bsn_tlv */
    -1,   /* 288: of_bsn_tlv_actor_key */
    -1,   /* 289: of_bsn_tlv_actor_port_num */
    -1,   /* 290: of_bsn_tlv_actor_port_priority */
    -1,   /* 291: of_bsn_tlv_actor_state */
    -1,   /* 292: of_bsn_tlv_actor_system_mac */
    -1,   /* 293: of_bsn_tlv_actor_system_priority */
    -1,   /* 294: of_bsn_tlv_broadcast_query_timeout */
    -1,   /* 295: of_bsn_tlv_circuit_id */
    -1,   /* 296: of_bsn_tlv_convergence_status */
    -1,   /* 297: of_bsn_tlv_crc_enabled */
    -1,   /* 298: of_bsn_tlv_data */
    -1,   /* 299: of_bsn_tlv_eth_dst */
    -1,   /* 300: of_bsn_tlv_eth_src */
    -1,   /* 301: of_bsn_tlv_external_gateway_ip */
    -1,   /* 302: of_bsn_tlv_external_gateway_mac */
    -1,   /* 303: of_bsn_tlv_external_ip */
    -1,   /* 304: of_bsn_tlv_external_mac */
    -1,   /* 305: of_bsn_tlv_external_netmask */
    -1,   /* 306: of_bsn_tlv_header */
    -1,   /* 307: of_bsn_tlv_header_size */
    -1,   /* 308: of_bsn_tlv_idle_notification */
    -1,   /* 309: of_bsn_tlv_idle_time */
    -1,   /* 310: of_bsn_tlv_idle_timeout */
    -1,   /* 311: of_bsn_tlv_internal_gateway_mac */
    -1,   /* 312: of_bsn_tlv_internal_mac */
    -1,   /* 313: of_bsn_tlv_ipv4 */
    -1,   /* 314: of_bsn_tlv_ipv4_dst */
    -1,   /* 315: of_bsn_tlv_ipv4_src */
    -1,   /* 316: of_bsn_tlv_mac */
    -1,   /* 317: of_bsn_tlv_miss_packets */
    -1,   /* 318: of_bsn_tlv_name */
    -1,   /* 319: of_bsn_tlv_partner_key */
    -1,   /* 320: of_bsn_tlv_partner_port_num */
    -1,   /* 321: of_bsn_tlv_partner_port_priority */
    -1,   /* 322: of_bsn_tlv_partner_state */
    -1,   /* 323: of_bsn_tlv_partner_system_mac */
    -1,   /* 324: of_bsn_tlv_partner_system_priority */
    -1,   /* 325: of_bsn_tlv_port */
    -1,   /* 326: of_bsn_tlv_queue_id */
    -1,   /* 327: of_bsn_tlv_queue_weight */
    -1,   /* 328: of_bsn_tlv_reply_packets */
    -1,   /* 329: of_bsn_tlv_request_packets */
    -1,   /* 330: of_bsn_tlv_rx_packets */
    -1,   /* 331: of_bsn_tlv_sampling_rate */
    -1,   /* 332: of_bsn_tlv_sub_agent_id */
    -1,   /* 333: of_bsn_tlv_tx_bytes */
    -1,   /* 334: of_bsn_tlv_tx_packets */
    -1,   /* 335: of_bsn_tlv_udf_anchor */
    -1,   /* 336: of_bsn_tlv_udf_id */
    -1,   /* 337: of_bsn_tlv_udf_length */
    -1,   /* 338: of_bsn_tlv_udf_offset */
    -1,   /* 339: of_bsn_tlv_udp_dst */
    -1,   /* 340: of_bsn_tlv_udp_src */
    -1,   /* 341: of_bsn_tlv_unicast_query_timeout */
    -1,   /* 342: of_bsn_tlv_vlan_vid */
    -1,   /* 343: of_bsn_tlv_vrf */
    -1,   /* 344: of_bsn_vlan_counter_stats_entry */
    4,    /* 345: of_bsn_vport */
    4,    /* 346: of_bsn_vport_header */
    64,   /* 347: of_bsn_vport_l2gre */
    32,   /* 348: of_bsn_vport_q_in_q */
    -1,   /* 349: of_bsn_vrf_counter_stats_entry */
    16,   /* 350: of_bucket */
    16,   /* 351: of_bucket_counter */
    4,    /* 352: of_bundle_prop */
    12,   /* 353: of_bundle_prop_experimenter */
    4,    /* 354: of_bundle_prop_header */
    56,   /* 355: of_flow_stats_entry */
    8,    /* 356: of_group_desc_stats_entry */
    40,   /* 357: of_group_stats_entry */
    4,    /* 358: of_hello_elem */
    4,    /* 359: of_hello_elem_header */
    4,    /* 360: of_hello_elem_versionbitmap */
    4,    /* 361: of_instruction */
    8,    /* 362: of_instruction_apply_actions */
    -1,   /* 363: of_instruction_bsn */
    -1,   /* 364: of_instruction_bsn_arp_offload */
    -1,   /* 365: of_instruction_bsn_deny */
    -1,   /* 366: of_instruction_bsn_dhcp_offload */
    -1,   /* 367: of_instruction_bsn_disable_split_horizon_check */
    -1,   /* 368: of_instruction_bsn_disable_src_mac_check */
    -1,   /* 369: of_instruction_bsn_disable_vlan_counters */
    -1,   /* 370: of_instruction_bsn_packet_of_death */
    -1,   /* 371: of_instruction_bsn_permit */
    -1,   /* 372: of_instruction_bsn_prioritize_pdus */
    -1,   /* 373: of_instruction_bsn_require_vlan_xlate */
    -1,   /* 374: of_instruction_bsn_span_destination */
    8,    /* 375: of_instruction_clear_actions */
    8,    /* 376: of_instruction_experimenter */
    8,    /* 377: of_instruction_goto_table */
    4,    /* 378: of_instruction_header */
    4,    /* 379: of_instruction_id */
    4,    /* 380: of_instruction_id_apply_actions */
    -1,   /* 381: of_instruction_id_bsn */
    -1,   /* 382: of_instruction_id_bsn_arp_offload */
    -1,   /* 383: of_instruction_id_bsn_deny */
    -1,   /* 384: of_instruction_id_bsn_dhcp_offload */
    -1,   /* 385: of_instruction_id_bsn_disable_split_horizon_check */
    -1,   /* 386: of_instruction_id_bsn_disable_src_mac_check */
    -1,   /* 387: of_instruction_id_bsn_disable_vlan_counters */
    -1,   /* 388: of_instruction_id_bsn_packet_of_death */
    -1,   /* 389: of_instruction_id_bsn_permit */
    -1,   /* 390: of_instruction_id_bsn_prioritize_pdus */
    -1,   /* 391: of_instruction_id_bsn_require_vlan_xlate */
    -1,   /* 392: of_instruction_id_bsn_span_destination */
    4,    /* 393: of_instruction_id_clear_actions */
    8,    /* 394: of_instruction_id_experimenter */
    4,    /* 395: of_instruction_id_goto_table */
    4,    /* 396: of_instruction_id_header */
    4,    /* 397: of_instruction_id_meter */
    4,    /* 398: of_instruction_id_write_actions */
    4,    /* 399: of_instruction_id_write_metadata */
    8,    /* 400: of_instruction_meter */
    8,    /* 401: of_instruction_write_actions */
    24,   /* 402: of_instruction_write_metadata */
    -1,   /* 403: of_match_v1 */
    -1,   /* 404: of_match_v2 */
    4,    /* 405: of_match_v3 */
    4,    /* 406: of_meter_band */
    16,   /* 407: of_meter_band_drop */
    16,   /* 408: of_meter_band_dscp_remark */
    16,   /* 409: of_meter_band_experimenter */
    4,    /* 410: of_meter_band_header */
    16,   /* 411: of_meter_band_stats */
    8,    /* 412: of_meter_config */
    16,   /* 413: of_meter_features */
    40,   /* 414: of_meter_stats */
    4,    /* 415: of_oxm */
    6,    /* 416: of_oxm_arp_op */
    8,    /* 417: of_oxm_arp_op_masked */
    10,   /* 418: of_oxm_arp_sha */
    16,   /* 419: of_oxm_arp_sha_masked */
    8,    /* 420: of_oxm_arp_spa */
    12,   /* 421: of_oxm_arp_spa_masked */
    10,   /* 422: of_oxm_arp_tha */
    16,   /* 423: of_oxm_arp_tha_masked */
    8,    /* 424: of_oxm_arp_tpa */
    12,   /* 425: of_oxm_arp_tpa_masked */
    -1,   /* 426: of_oxm_bsn_egr_port_group_id */
    -1,   /* 427: of_oxm_bsn_egr_port_group_id_masked */
    -1,   /* 428: of_oxm_bsn_global_vrf_allowed */
    -1,   /* 429: of_oxm_bsn_global_vrf_allowed_masked */
    -1,   /* 430: of_oxm_bsn_in_ports_128 */
    -1,   /* 431: of_oxm_bsn_in_ports_128_masked */
    -1,   /* 432: of_oxm_bsn_l3_dst_class_id */
    -1,   /* 433: of_oxm_bsn_l3_dst_class_id_masked */
    -1,   /* 434: of_oxm_bsn_l3_interface_class_id */
    -1,   /* 435: of_oxm_bsn_l3_interface_class_id_masked */
    -1,   /* 436: of_oxm_bsn_l3_src_class_id */
    -1,   /* 437: of_oxm_bsn_l3_src_class_id_masked */
    -1,   /* 438: of_oxm_bsn_lag_id */
    -1,   /* 439: of_oxm_bsn_lag_id_masked */
    -1,   /* 440: of_oxm_bsn_tcp_flags */
    -1,   /* 441: of_oxm_bsn_tcp_flags_masked */
    -1,   /* 442: of_oxm_bsn_udf0 */
    -1,   /* 443: of_oxm_bsn_udf0_masked */
    -1,   /* 444: of_oxm_bsn_udf1 */
    -1,   /* 445: of_oxm_bsn_udf1_masked */
    -1,   /* 446: of_oxm_bsn_udf2 */
    -1,   /* 447: of_oxm_bsn_udf2_masked */
    -1,   /* 448: of_oxm_bsn_udf3 */
    -1,   /* 449: of_oxm_bsn_udf3_masked */
    -1,   /* 450: of_oxm_bsn_udf4 */
    -1,   /* 451: of_oxm_bsn_udf4_masked */
    -1,   /* 452: of_oxm_bsn_udf5 */
    -1,   /* 453: of_oxm_bsn_udf5_masked */
    -1,   /* 454: of_oxm_bsn_udf6 */
    -1,   /* 455: of_oxm_bsn_udf6_masked */
    -1,   /* 456: of_oxm_bsn_udf7 */
    -1,   /* 457: of_oxm_bsn_udf7_masked */
    -1,   /* 458: of_oxm_bsn_vlan_xlate_port_group_id */
    -1,   /* 459: of_oxm_bsn_vlan_xlate_port_group_id_masked */
    -1,   /* 460: of_oxm_bsn_vrf */
    -1,   /* 461: of_oxm_bsn_vrf_masked */
    10,   /* 462: of_oxm_eth_dst */
    16,   /* 463: of_oxm_eth_dst_masked */
    10,   /* 464: of_oxm_eth_src */
    16,   /* 465: of_oxm_eth_src_masked */
    6,    /* 466: of_oxm_eth_type */
    8,    /* 467: of_oxm_eth_type_masked */
    4,    /* 468: of_oxm_header */
    5,    /* 469: of_oxm_icmpv4_code */
    6,    /* 470: of_oxm_icmpv4_code_masked */
    5,    /* 471: of_oxm_icmpv4_type */
    6,    /* 472: of_oxm_icmpv4_type_masked */
    5,    /* 473: of_oxm_icmpv6_code */
    6,    /* 474: of_oxm_icmpv6_code_masked */
    5,    /* 475: of_oxm_icmpv6_type */
    6,    /* 476: of_oxm_icmpv6_type_masked */
    8,    /* 477: of_oxm_in_phy_port */
    12,   /* 478: of_oxm_in_phy_port_masked */
    8,    /* 479: of_oxm_in_port */
    12,   /* 480: of_oxm_in_port_masked */
    5,    /* 481: of_oxm_ip_dscp */
    6,    /* 482: of_oxm_ip_dscp_masked */
    5,    /* 483: of_oxm_ip_ecn */
    6,    /* 484: of_oxm_ip_ecn_masked */
    5,    /* 485: of_oxm_ip_proto */
    6,    /* 486: of_oxm_ip_proto_masked */
    8,    /* 487: of_oxm_ipv4_dst */
    12,   /* 488: of_oxm_ipv4_dst_masked */
    8,    /* 489: of_oxm_ipv4_src */
    12,   /* 490: of_oxm_ipv4_src_masked */
    20,   /* 491: of_oxm_ipv6_dst */
    36,   /* 492: of_oxm_ipv6_dst_masked */
    8,    /* 493: of_oxm_ipv6_flabel */
    12,   /* 494: of_oxm_ipv6_flabel_masked */
    10,   /* 495: of_oxm_ipv6_nd_sll */
    16,   /* 496: of_oxm_ipv6_nd_sll_masked */
    20,   /* 497: of_oxm_ipv6_nd_target */
    36,   /* 498: of_oxm_ipv6_nd_target_masked */
    10,   /* 499: of_oxm_ipv6_nd_tll */
    16,   /* 500: of_oxm_ipv6_nd_tll_masked */
    20,   /* 501: of_oxm_ipv6_src */
    36,   /* 502: of_oxm_ipv6_src_masked */
    12,   /* 503: of_oxm_metadata */
    20,   /* 504: of_oxm_metadata_masked */
    5,    /* 505: of_oxm_mpls_bos */
    6,    /* 506: of_oxm_mpls_bos_masked */
    8,    /* 507: of_oxm_mpls_label */
    12,   /* 508: of_oxm_mpls_label_masked */
    5,    /* 509: of_oxm_mpls_tc */
    6,    /* 510: of_oxm_mpls_tc_masked */
    6,    /* 511: of_oxm_sctp_dst */
    8,    /* 512: of_oxm_sctp_dst_masked */
    6,    /* 513: of_oxm_sctp_src */
    8,    /* 514: of_oxm_sctp_src_masked */
    6,    /* 515: of_oxm_tcp_dst */
    8,    /* 516: of_oxm_tcp_dst_masked */
    6,    /* 517: of_oxm_tcp_src */
    8,    /* 518: of_oxm_tcp_src_masked */
    12,   /* 519: of_oxm_tunnel_id */
    20,   /* 520: of_oxm_tunnel_id_masked */
    6,    /* 521: of_oxm_udp_dst */
    8,    /* 522: of_oxm_udp_dst_masked */
    6,    /* 523: of_oxm_udp_src */
    8,    /* 524: of_oxm_udp_src_masked */
    5,    /* 525: of_oxm_vlan_pcp */
    6,    /* 526: of_oxm_vlan_pcp_masked */
    6,    /* 527: of_oxm_vlan_vid */
    8,    /* 528: of_oxm_vlan_vid_masked */
    16,   /* 529: of_packet_queue */
    40,   /* 530: of_port_desc */
    4,    /* 531: of_port_desc_prop */
    32,   /* 532: of_port_desc_prop_ethernet */
    12,   /* 533: of_port_desc_prop_experimenter */
    4,    /* 534: of_port_desc_prop_header */
    44,   /* 535: of_port_desc_prop_optical */
    4,    /* 536: of_port_mod_prop */
    8,    /* 537: of_port_mod_prop_ethernet */
    12,   /* 538: of_port_mod_prop_experimenter */
    4,    /* 539: of_port_mod_prop_header */
    24,   /* 540: of_port_mod_prop_optical */
    80,   /* 541: of_port_stats_entry */
    4,    /* 542: of_port_stats_prop */
    40,   /* 543: of_port_stats_prop_ethernet */
    12,   /* 544: of_port_stats_prop_experimenter */
    4,    /* 545: of_port_stats_prop_header */
    44,   /* 546: of_port_stats_prop_optical */
    16,   /* 547: of_queue_desc */
    4,    /* 548: of_queue_desc_prop */
    12,   /* 549: of_queue_desc_prop_experimenter */
    4,    /* 550: of_queue_desc_prop_header */
    8,    /* 551: of_queue_desc_prop_max_rate */
    8,    /* 552: of_queue_desc_prop_min_rate */
    8,    /* 553: of_queue_prop */
    16,   /* 554: of_queue_prop_experimenter */
    8,    /* 555: of_queue_prop_header */
    16,   /* 556: of_queue_prop_max_rate */
    16,   /* 557: of_queue_prop_min_rate */
    48,   /* 558: of_queue_stats_entry */
    4,    /* 559: of_queue_stats_prop */
    12,   /* 560: of_queue_stats_prop_experimenter */
    4,    /* 561: of_queue_stats_prop_header */
    4,    /* 562: of_role_prop */
    12,   /* 563: of_role_prop_experimenter */
    4,    /* 564: of_role_prop_header */
    8,    /* 565: of_table_desc */
    4,    /* 566: of_table_feature_prop */
    4,    /* 567: of_table_feature_prop_apply_actions */
    4,    /* 568: of_table_feature_prop_apply_actions_miss */
    4,    /* 569: of_table_feature_prop_apply_setfield */
    4,    /* 570: of_table_feature_prop_apply_setfield_miss */
    12,   /* 571: of_table_feature_prop_experimenter */
    12,   /* 572: of_table_feature_prop_experimenter_miss */
    4,    /* 573: of_table_feature_prop_header */
    4,    /* 574: of_table_feature_prop_instructions */
    4,    /* 575: of_table_feature_prop_instructions_miss */
    4,    /* 576: of_table_feature_prop_match */
    4,    /* 577: of_table_feature_prop_next_tables */
    4,    /* 578: of_table_feature_prop_next_tables_miss */
    4,    /* 579: of_table_feature_prop_table_sync_from */
    4,    /* 580: of_table_feature_prop_wildcards */
    4,    /* 581: of_table_feature_prop_write_actions */
    4,    /* 582: of_table_feature_prop_write_actions_miss */
    4,    /* 583: of_table_feature_prop_write_setfield */
    4,    /* 584: of_table_feature_prop_write_setfield_miss */
    64,   /* 585: of_table_features */
    4,    /* 586: of_table_mod_prop */
    8,    /* 587: of_table_mod_prop_eviction */
    12,   /* 588: of_table_mod_prop_experimenter */
    8,    /* 589: of_table_mod_prop_vacancy */
    24,   /* 590: of_table_stats_entry */
    4,    /* 591: of_uint32 */
    8,    /* 592: of_uint64 */
    1,    /* 593: of_uint8 */
    0,    /* 594: of_list_action */
    0,    /* 595: of_list_action_id */
    0,    /* 596: of_list_async_config_prop */
    -1,   /* 597: of_list_bsn_controller_connection */
    -1,   /* 598: of_list_bsn_debug_counter_desc_stats_entry */
    -1,   /* 599: of_list_bsn_debug_counter_stats_entry */
    -1,   /* 600: of_list_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 601: of_list_bsn_gentable_bucket_stats_entry */
    -1,   /* 602: of_list_bsn_gentable_desc_stats_entry */
    -1,   /* 603: of_list_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 604: of_list_bsn_gentable_entry_stats_entry */
    -1,   /* 605: of_list_bsn_gentable_stats_entry */
    0,    /* 606: of_list_bsn_interface */
    -1,   /* 607: of_list_bsn_lacp_stats_entry */
    -1,   /* 608: of_list_bsn_port_counter_stats_entry */
    -1,   /* 609: of_list_bsn_switch_pipeline_stats_entry */
    -1,   /* 610: of_list_bsn_table_checksum_stats_entry */
    -1,   /* 611: of_list_bsn_tlv */
    -1,   /* 612: of_list_bsn_vlan_counter_stats_entry */
    -1,   /* 613: of_list_bsn_vrf_counter_stats_entry */
    0,    /* 614: of_list_bucket */
    0,    /* 615: of_list_bucket_counter */
    0,    /* 616: of_list_bundle_prop */
    0,    /* 617: of_list_flow_stats_entry */
    0,    /* 618: of_list_group_desc_stats_entry */
    0,    /* 619: of_list_group_stats_entry */
    0,    /* 620: of_list_hello_elem */
    0,    /* 621: of_list_instruction */
    0,    /* 622: of_list_instruction_id */
    0,    /* 623: of_list_meter_band */
    0,    /* 624: of_list_meter_band_stats */
    0,    /* 625: of_list_meter_stats */
    0,    /* 626: of_list_oxm */
    -1,   /* 627: of_list_packet_queue */
    0,    /* 628: of_list_port_desc */
    0,    /* 629: of_list_port_desc_prop */
    0,    /* 630: of_list_port_mod_prop */
    0,    /* 631: of_list_port_stats_entry */
    0,    /* 632: of_list_port_stats_prop */
    0,    /* 633: of_list_queue_desc */
    0,    /* 634: of_list_queue_desc_prop */
    0,    /* 635: of_list_queue_prop */
    0,    /* 636: of_list_queue_stats_entry */
    0,    /* 637: of_list_queue_stats_prop */
    0,    /* 638: of_list_role_prop */
    0,    /* 639: of_list_table_desc */
    0,    /* 640: of_list_table_feature_prop */
    0,    /* 641: of_list_table_features */
    0,    /* 642: of_list_table_mod_prop */
    0,    /* 643: of_list_table_stats_entry */
    0,    /* 644: of_list_uint32 */
    -1,   /* 645: of_list_uint64 */
    0     /* 646: of_list_uint8 */
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
