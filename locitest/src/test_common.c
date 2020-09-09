/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */

/*
 * Common test code for LOCI
 *
 * AUTOMATICALLY GENERATED FILE.  Edits will be lost on regen.
 */

#define DISABLE_WARN_UNUSED_RESULT
#include "loci_log.h"
#include <loci/loci_obj_dump.h>
#include <locitest/unittest.h>
#include <locitest/test_common.h>

/* mcheck is a glibc extension */
#if defined(__linux__)
#include <mcheck.h>
#define MCHECK_INIT mcheck(NULL)
#else
#define MCHECK_INIT do { } while (0)
#endif

/**
 * Exit on error if set to 1
 */
int exit_on_error = 1;

/**
 * Global error state: 0 is okay, 1 is error
 */
int global_error = 0;


/**
 * Macros for initializing and checking scalar types
 *
 * @param var The variable being initialized or checked
 * @param val The integer value to set/check against, see below
 *
 * Note that equality means something special for strings.  Each byte
 * is initialized to an incrementing value.  So check is done against that.
 *
 */


#define VAR_UINT8_T_INIT(var, val) var = (uint8_t)(val)
#define VAR_UINT8_T_CHECK(var, val) ((var) == (uint8_t)(val))

#define VAR_UINT16_T_INIT(var, val) var = (uint16_t)(val)
#define VAR_UINT16_T_CHECK(var, val) ((var) == (uint16_t)(val))

#define VAR_UINT32_T_INIT(var, val) var = (uint32_t)(val)
#define VAR_UINT32_T_CHECK(var, val) ((var) == (uint32_t)(val))

#define VAR_UINT64_T_INIT(var, val) var = (uint64_t)(val)
#define VAR_UINT64_T_CHECK(var, val) ((var) == (uint64_t)(val))

#define VAR_OF_PORT_NO_T_INIT(var, val) var = (of_port_no_t)(val)
#define VAR_OF_PORT_NO_T_CHECK(var, val) ((var) == (of_port_no_t)(val))

#define VAR_OF_FM_CMD_T_INIT(var, val) var = (of_fm_cmd_t)(val)
#define VAR_OF_FM_CMD_T_CHECK(var, val) ((var) == (of_fm_cmd_t)(val))

#define VAR_OF_WC_BMAP_T_INIT(var, val) var = (of_wc_bmap_t)(val)
#define VAR_OF_WC_BMAP_T_CHECK(var, val) ((var) == (of_wc_bmap_t)(val))

#define VAR_OF_MATCH_BMAP_T_INIT(var, val) var = (of_match_bmap_t)(val)
#define VAR_OF_MATCH_BMAP_T_CHECK(var, val) ((var) == (of_match_bmap_t)(val))

#define VAR_OF_IPV4_T_INIT(var, val) var = (of_ipv4_t)(val)
#define VAR_OF_IPV4_T_CHECK(var, val) ((var) == (of_ipv4_t)(val))

#define VAR_OF_PORT_NAME_T_INIT(var, val) \
    of_test_str_fill((uint8_t *)&(var), val, sizeof(var))
#define VAR_OF_PORT_NAME_T_CHECK(var, val) \
    of_test_str_check((uint8_t *)&(var), val, sizeof(var))

#define VAR_OF_TABLE_NAME_T_INIT(var, val) \
    of_test_str_fill((uint8_t *)&(var), val, sizeof(var))
#define VAR_OF_TABLE_NAME_T_CHECK(var, val) \
    of_test_str_check((uint8_t *)&(var), val, sizeof(var))

#define VAR_UINT128_T_INIT(var, val) \
    of_test_str_fill((uint8_t *)&(var), val, sizeof(var))
#define VAR_UINT128_T_CHECK(var, val) \
    of_test_str_check((uint8_t *)&(var), val, sizeof(var))

#define VAR_OF_DESC_STR_T_INIT(var, val) \
    of_test_str_fill((uint8_t *)&(var), val, sizeof(var))
#define VAR_OF_DESC_STR_T_CHECK(var, val) \
    of_test_str_check((uint8_t *)&(var), val, sizeof(var))

#define VAR_OF_SERIAL_NUM_T_INIT(var, val) \
    of_test_str_fill((uint8_t *)&(var), val, sizeof(var))
#define VAR_OF_SERIAL_NUM_T_CHECK(var, val) \
    of_test_str_check((uint8_t *)&(var), val, sizeof(var))

#define VAR_OF_MAC_ADDR_T_INIT(var, val) \
    of_test_str_fill((uint8_t *)&(var), val, sizeof(var))
#define VAR_OF_MAC_ADDR_T_CHECK(var, val) \
    of_test_str_check((uint8_t *)&(var), val, sizeof(var))

#define VAR_OF_IPV6_T_INIT(var, val) \
    of_test_str_fill((uint8_t *)&(var), val, sizeof(var))
#define VAR_OF_IPV6_T_CHECK(var, val) \
    of_test_str_check((uint8_t *)&(var), val, sizeof(var))

#define VAR_OF_BITMAP_128_T_INIT(var, val) \
    of_test_str_fill((uint8_t *)&(var), val, sizeof(var))
#define VAR_OF_BITMAP_128_T_CHECK(var, val) \
    of_test_str_check((uint8_t *)&(var), val, sizeof(var))

#define VAR_OF_CHECKSUM_128_T_INIT(var, val) \
    of_test_str_fill((uint8_t *)&(var), val, sizeof(var))
#define VAR_OF_CHECKSUM_128_T_CHECK(var, val) \
    of_test_str_check((uint8_t *)&(var), val, sizeof(var))

#define VAR_OF_STR64_T_INIT(var, val) \
    of_test_str_fill((uint8_t *)&(var), val, sizeof(var))
#define VAR_OF_STR64_T_CHECK(var, val) \
    of_test_str_check((uint8_t *)&(var), val, sizeof(var))

#define VAR_OF_BITMAP_512_T_INIT(var, val) \
    of_test_str_fill((uint8_t *)&(var), val, sizeof(var))
#define VAR_OF_BITMAP_512_T_CHECK(var, val) \
    of_test_str_check((uint8_t *)&(var), val, sizeof(var))


/**
 * The increment to use on values inside a string
 */
#define OF_TEST_STR_INCR 3

/**
 * Fill in a buffer with incrementing values starting
 * at the given offset with the given value
 * @param buf The buffer to fill
 * @param value The value to use for data
 * @param len The number of bytes to fill
 */

void
of_test_str_fill(uint8_t *buf, int value, int len)
{
    int i;

    for (i = 0; i < len; i++) {
        *buf = value;
        value += OF_TEST_STR_INCR;
        buf++;
    }
}

/**
 * Given a buffer, verify that it's filled as above
 * @param buf The buffer to check
 * @param value The value to use for data
 * @param len The number of bytes to fill
 * @return Boolean True on equality (success)
 */

int
of_test_str_check(uint8_t *buf, int value, int len)
{
    int i;
    uint8_t val8;

    val8 = value;

    for (i = 0; i < len; i++) {
        if (*buf != val8) {
            return 0;
        }
        val8 += OF_TEST_STR_INCR;
        buf++;
    }

    return 1;
}

/**
 * Global that determines how octets should be populated
 * -1 means use value % MAX (below) to determine length
 * 0, 1, ... means used that fixed length
 *
 * Note: Was 16K, but that made objects too big.  May add flexibility
 * to call populate with a max parameter for length
 */
int octets_pop_style = -1;
#define OCTETS_MAX_VALUE (64) /* 16K was too big */
#define OCTETS_MULTIPLIER 6367 /* A prime */

int
of_octets_populate(of_octets_t *octets, int value)
{
    if (octets_pop_style < 0) {
        octets->bytes = (value * OCTETS_MULTIPLIER) % OCTETS_MAX_VALUE;
    } else {
        octets->bytes = octets_pop_style;
    }

    if (octets->bytes != 0) {
        if ((octets->data = (uint8_t *)MALLOC(octets->bytes)) == NULL) {
            return 0;
        }
        of_test_str_fill(octets->data, value, octets->bytes);
        value += 1;
    }

    return value;
}

int
of_octets_check(of_octets_t *octets, int value)
{
    int len;

    if (octets_pop_style < 0) {
        len =  (value * OCTETS_MULTIPLIER) % OCTETS_MAX_VALUE;
        TEST_ASSERT(octets->bytes == len);
    } else {
        TEST_ASSERT(octets->bytes == octets_pop_style);
    }

    if (octets->bytes != 0) {
        TEST_ASSERT(of_test_str_check(octets->data, value, octets->bytes)
            == 1);
        value += 1;
    }

    return value;
}

int
of_match_populate(of_match_t *match, of_version_t version, int value)
{
    MEMSET(match, 0, sizeof(*match));
    match->version = version;

    if (version == 1) {
        OF_MATCH_MASK_ETH_DST_EXACT_SET(match);
        VAR_OF_MAC_ADDR_T_INIT(match->fields.eth_dst, value);
        value += 1;

        OF_MATCH_MASK_ETH_SRC_EXACT_SET(match);
        VAR_OF_MAC_ADDR_T_INIT(match->fields.eth_src, value);
        value += 1;

        OF_MATCH_MASK_ETH_TYPE_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.eth_type, value);
        value += 1;

        OF_MATCH_MASK_IN_PORT_EXACT_SET(match);
        VAR_OF_PORT_NO_T_INIT(match->fields.in_port, value);
        value += 1;

        OF_MATCH_MASK_IPV4_DST_EXACT_SET(match);
        VAR_OF_IPV4_T_INIT(match->fields.ipv4_dst, value);
        value += 1;

        OF_MATCH_MASK_IP_PROTO_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.ip_proto, value);
        value += 1;

        OF_MATCH_MASK_IPV4_SRC_EXACT_SET(match);
        VAR_OF_IPV4_T_INIT(match->fields.ipv4_src, value);
        value += 1;

        OF_MATCH_MASK_IP_DSCP_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.ip_dscp, value);
        value += 1;

        OF_MATCH_MASK_TCP_DST_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.tcp_dst, value);
        value += 1;

        OF_MATCH_MASK_TCP_SRC_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.tcp_src, value);
        value += 1;

        OF_MATCH_MASK_VLAN_PCP_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.vlan_pcp, value);
        value += 1;

        OF_MATCH_MASK_VLAN_VID_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.vlan_vid, value);
        value += 1;

    }


    if (version == 2) {
        OF_MATCH_MASK_ETH_DST_EXACT_SET(match);
        VAR_OF_MAC_ADDR_T_INIT(match->fields.eth_dst, value);
        value += 1;

        OF_MATCH_MASK_ETH_SRC_EXACT_SET(match);
        VAR_OF_MAC_ADDR_T_INIT(match->fields.eth_src, value);
        value += 1;

        OF_MATCH_MASK_ETH_TYPE_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.eth_type, value);
        value += 1;

        OF_MATCH_MASK_IN_PORT_EXACT_SET(match);
        VAR_OF_PORT_NO_T_INIT(match->fields.in_port, value);
        value += 1;

        OF_MATCH_MASK_IPV4_DST_EXACT_SET(match);
        VAR_OF_IPV4_T_INIT(match->fields.ipv4_dst, value);
        value += 1;

        OF_MATCH_MASK_IP_PROTO_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.ip_proto, value);
        value += 1;

        OF_MATCH_MASK_IPV4_SRC_EXACT_SET(match);
        VAR_OF_IPV4_T_INIT(match->fields.ipv4_src, value);
        value += 1;

        OF_MATCH_MASK_IP_DSCP_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.ip_dscp, value);
        value += 1;

        OF_MATCH_MASK_TCP_DST_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.tcp_dst, value);
        value += 1;

        OF_MATCH_MASK_TCP_SRC_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.tcp_src, value);
        value += 1;

        OF_MATCH_MASK_VLAN_PCP_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.vlan_pcp, value);
        value += 1;

        OF_MATCH_MASK_VLAN_VID_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.vlan_vid, value);
        value += 1;

        OF_MATCH_MASK_MPLS_LABEL_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.mpls_label, value);
        value += 1;

        OF_MATCH_MASK_MPLS_TC_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.mpls_tc, value);
        value += 1;

        OF_MATCH_MASK_METADATA_EXACT_SET(match);
        VAR_UINT64_T_INIT(match->fields.metadata, value);
        value += 1;

    }


    if (version == 3) {
        OF_MATCH_MASK_ARP_OP_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.arp_op, value);
        value += 1;

        OF_MATCH_MASK_ARP_SHA_EXACT_SET(match);
        VAR_OF_MAC_ADDR_T_INIT(match->fields.arp_sha, value);
        value += 1;

        OF_MATCH_MASK_ARP_SPA_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.arp_spa, value);
        value += 1;

        OF_MATCH_MASK_ARP_THA_EXACT_SET(match);
        VAR_OF_MAC_ADDR_T_INIT(match->fields.arp_tha, value);
        value += 1;

        OF_MATCH_MASK_ARP_TPA_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.arp_tpa, value);
        value += 1;

        OF_MATCH_MASK_BSN_EGR_PORT_GROUP_ID_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_egr_port_group_id, value);
        value += 1;

        OF_MATCH_MASK_BSN_GLOBAL_VRF_ALLOWED_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.bsn_global_vrf_allowed, value);
        value += 1;

        OF_MATCH_MASK_BSN_IN_PORTS_128_EXACT_SET(match);
        VAR_OF_BITMAP_128_T_INIT(match->fields.bsn_in_ports_128, value);
        value += 1;

        OF_MATCH_MASK_BSN_IN_PORTS_512_EXACT_SET(match);
        VAR_OF_BITMAP_512_T_INIT(match->fields.bsn_in_ports_512, value);
        value += 1;

        OF_MATCH_MASK_BSN_INGRESS_PORT_GROUP_ID_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_ingress_port_group_id, value);
        value += 1;

        OF_MATCH_MASK_BSN_IP_FRAGMENTATION_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.bsn_ip_fragmentation, value);
        value += 1;

        OF_MATCH_MASK_BSN_L2_CACHE_HIT_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.bsn_l2_cache_hit, value);
        value += 1;

        OF_MATCH_MASK_BSN_L3_DST_CLASS_ID_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_l3_dst_class_id, value);
        value += 1;

        OF_MATCH_MASK_BSN_L3_INTERFACE_CLASS_ID_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_l3_interface_class_id, value);
        value += 1;

        OF_MATCH_MASK_BSN_L3_SRC_CLASS_ID_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_l3_src_class_id, value);
        value += 1;

        OF_MATCH_MASK_BSN_LAG_ID_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_lag_id, value);
        value += 1;

        OF_MATCH_MASK_BSN_TCP_FLAGS_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.bsn_tcp_flags, value);
        value += 1;

        OF_MATCH_MASK_BSN_UDF0_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_udf0, value);
        value += 1;

        OF_MATCH_MASK_BSN_UDF1_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_udf1, value);
        value += 1;

        OF_MATCH_MASK_BSN_UDF2_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_udf2, value);
        value += 1;

        OF_MATCH_MASK_BSN_UDF3_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_udf3, value);
        value += 1;

        OF_MATCH_MASK_BSN_UDF4_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_udf4, value);
        value += 1;

        OF_MATCH_MASK_BSN_UDF5_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_udf5, value);
        value += 1;

        OF_MATCH_MASK_BSN_UDF6_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_udf6, value);
        value += 1;

        OF_MATCH_MASK_BSN_UDF7_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_udf7, value);
        value += 1;

        OF_MATCH_MASK_BSN_VLAN_XLATE_PORT_GROUP_ID_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_vlan_xlate_port_group_id, value);
        value += 1;

        OF_MATCH_MASK_BSN_VRF_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_vrf, value);
        value += 1;

        OF_MATCH_MASK_CONN_TRACKING_IPV6_DST_EXACT_SET(match);
        VAR_OF_IPV6_T_INIT(match->fields.conn_tracking_ipv6_dst, value);
        value += 1;

        OF_MATCH_MASK_CONN_TRACKING_IPV6_SRC_EXACT_SET(match);
        VAR_OF_IPV6_T_INIT(match->fields.conn_tracking_ipv6_src, value);
        value += 1;

        OF_MATCH_MASK_CONN_TRACKING_LABEL_EXACT_SET(match);
        VAR_UINT128_T_INIT(match->fields.conn_tracking_label, value);
        value += 1;

        OF_MATCH_MASK_CONN_TRACKING_MARK_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.conn_tracking_mark, value);
        value += 1;

        OF_MATCH_MASK_CONN_TRACKING_NW_DST_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.conn_tracking_nw_dst, value);
        value += 1;

        OF_MATCH_MASK_CONN_TRACKING_NW_PROTO_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.conn_tracking_nw_proto, value);
        value += 1;

        OF_MATCH_MASK_CONN_TRACKING_NW_SRC_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.conn_tracking_nw_src, value);
        value += 1;

        OF_MATCH_MASK_CONN_TRACKING_STATE_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.conn_tracking_state, value);
        value += 1;

        OF_MATCH_MASK_CONN_TRACKING_TP_DST_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.conn_tracking_tp_dst, value);
        value += 1;

        OF_MATCH_MASK_CONN_TRACKING_TP_SRC_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.conn_tracking_tp_src, value);
        value += 1;

        OF_MATCH_MASK_CONN_TRACKING_ZONE_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.conn_tracking_zone, value);
        value += 1;

        OF_MATCH_MASK_ETH_DST_EXACT_SET(match);
        VAR_OF_MAC_ADDR_T_INIT(match->fields.eth_dst, value);
        value += 1;

        OF_MATCH_MASK_ETH_SRC_EXACT_SET(match);
        VAR_OF_MAC_ADDR_T_INIT(match->fields.eth_src, value);
        value += 1;

        OF_MATCH_MASK_ETH_TYPE_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.eth_type, value);
        value += 1;

        OF_MATCH_MASK_ICMPV4_CODE_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.icmpv4_code, value);
        value += 1;

        OF_MATCH_MASK_ICMPV4_TYPE_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.icmpv4_type, value);
        value += 1;

        OF_MATCH_MASK_ICMPV6_CODE_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.icmpv6_code, value);
        value += 1;

        OF_MATCH_MASK_ICMPV6_TYPE_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.icmpv6_type, value);
        value += 1;

        OF_MATCH_MASK_IN_PHY_PORT_EXACT_SET(match);
        VAR_OF_PORT_NO_T_INIT(match->fields.in_phy_port, value);
        value += 1;

        OF_MATCH_MASK_IN_PORT_EXACT_SET(match);
        VAR_OF_PORT_NO_T_INIT(match->fields.in_port, value);
        value += 1;

        OF_MATCH_MASK_IP_DSCP_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.ip_dscp, value);
        value += 1;

        OF_MATCH_MASK_IP_ECN_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.ip_ecn, value);
        value += 1;

        OF_MATCH_MASK_IP_PROTO_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.ip_proto, value);
        value += 1;

        OF_MATCH_MASK_IPV4_DST_EXACT_SET(match);
        VAR_OF_IPV4_T_INIT(match->fields.ipv4_dst, value);
        value += 1;

        OF_MATCH_MASK_IPV4_SRC_EXACT_SET(match);
        VAR_OF_IPV4_T_INIT(match->fields.ipv4_src, value);
        value += 1;

        OF_MATCH_MASK_IPV6_DST_EXACT_SET(match);
        VAR_OF_IPV6_T_INIT(match->fields.ipv6_dst, value);
        value += 1;

        OF_MATCH_MASK_IPV6_FLABEL_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.ipv6_flabel, value);
        value += 1;

        OF_MATCH_MASK_IPV6_ND_SLL_EXACT_SET(match);
        VAR_OF_MAC_ADDR_T_INIT(match->fields.ipv6_nd_sll, value);
        value += 1;

        OF_MATCH_MASK_IPV6_ND_TARGET_EXACT_SET(match);
        VAR_OF_IPV6_T_INIT(match->fields.ipv6_nd_target, value);
        value += 1;

        OF_MATCH_MASK_IPV6_ND_TLL_EXACT_SET(match);
        VAR_OF_MAC_ADDR_T_INIT(match->fields.ipv6_nd_tll, value);
        value += 1;

        OF_MATCH_MASK_IPV6_SRC_EXACT_SET(match);
        VAR_OF_IPV6_T_INIT(match->fields.ipv6_src, value);
        value += 1;

        OF_MATCH_MASK_METADATA_EXACT_SET(match);
        VAR_UINT64_T_INIT(match->fields.metadata, value);
        value += 1;

        OF_MATCH_MASK_MPLS_LABEL_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.mpls_label, value);
        value += 1;

        OF_MATCH_MASK_MPLS_TC_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.mpls_tc, value);
        value += 1;

        OF_MATCH_MASK_OVS_TCP_FLAGS_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.ovs_tcp_flags, value);
        value += 1;

        OF_MATCH_MASK_SCTP_DST_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.sctp_dst, value);
        value += 1;

        OF_MATCH_MASK_SCTP_SRC_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.sctp_src, value);
        value += 1;

        OF_MATCH_MASK_TCP_DST_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.tcp_dst, value);
        value += 1;

        OF_MATCH_MASK_TCP_SRC_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.tcp_src, value);
        value += 1;

        OF_MATCH_MASK_TUNNEL_IPV4_DST_EXACT_SET(match);
        VAR_OF_IPV4_T_INIT(match->fields.tunnel_ipv4_dst, value);
        value += 1;

        OF_MATCH_MASK_TUNNEL_IPV4_SRC_EXACT_SET(match);
        VAR_OF_IPV4_T_INIT(match->fields.tunnel_ipv4_src, value);
        value += 1;

        OF_MATCH_MASK_UDP_DST_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.udp_dst, value);
        value += 1;

        OF_MATCH_MASK_UDP_SRC_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.udp_src, value);
        value += 1;

        OF_MATCH_MASK_VLAN_PCP_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.vlan_pcp, value);
        value += 1;

        OF_MATCH_MASK_VLAN_VID_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.vlan_vid, value);
        value += 1;

    }


    if (version == 4) {
        OF_MATCH_MASK_ARP_OP_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.arp_op, value);
        value += 1;

        OF_MATCH_MASK_ARP_SHA_EXACT_SET(match);
        VAR_OF_MAC_ADDR_T_INIT(match->fields.arp_sha, value);
        value += 1;

        OF_MATCH_MASK_ARP_SPA_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.arp_spa, value);
        value += 1;

        OF_MATCH_MASK_ARP_THA_EXACT_SET(match);
        VAR_OF_MAC_ADDR_T_INIT(match->fields.arp_tha, value);
        value += 1;

        OF_MATCH_MASK_ARP_TPA_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.arp_tpa, value);
        value += 1;

        OF_MATCH_MASK_BSN_EGR_PORT_GROUP_ID_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_egr_port_group_id, value);
        value += 1;

        OF_MATCH_MASK_BSN_GLOBAL_VRF_ALLOWED_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.bsn_global_vrf_allowed, value);
        value += 1;

        OF_MATCH_MASK_BSN_IN_PORTS_128_EXACT_SET(match);
        VAR_OF_BITMAP_128_T_INIT(match->fields.bsn_in_ports_128, value);
        value += 1;

        OF_MATCH_MASK_BSN_IN_PORTS_512_EXACT_SET(match);
        VAR_OF_BITMAP_512_T_INIT(match->fields.bsn_in_ports_512, value);
        value += 1;

        OF_MATCH_MASK_BSN_INGRESS_PORT_GROUP_ID_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_ingress_port_group_id, value);
        value += 1;

        OF_MATCH_MASK_BSN_IP_FRAGMENTATION_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.bsn_ip_fragmentation, value);
        value += 1;

        OF_MATCH_MASK_BSN_L2_CACHE_HIT_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.bsn_l2_cache_hit, value);
        value += 1;

        OF_MATCH_MASK_BSN_L3_DST_CLASS_ID_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_l3_dst_class_id, value);
        value += 1;

        OF_MATCH_MASK_BSN_L3_INTERFACE_CLASS_ID_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_l3_interface_class_id, value);
        value += 1;

        OF_MATCH_MASK_BSN_L3_SRC_CLASS_ID_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_l3_src_class_id, value);
        value += 1;

        OF_MATCH_MASK_BSN_LAG_ID_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_lag_id, value);
        value += 1;

        OF_MATCH_MASK_BSN_TCP_FLAGS_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.bsn_tcp_flags, value);
        value += 1;

        OF_MATCH_MASK_BSN_UDF0_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_udf0, value);
        value += 1;

        OF_MATCH_MASK_BSN_UDF1_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_udf1, value);
        value += 1;

        OF_MATCH_MASK_BSN_UDF2_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_udf2, value);
        value += 1;

        OF_MATCH_MASK_BSN_UDF3_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_udf3, value);
        value += 1;

        OF_MATCH_MASK_BSN_UDF4_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_udf4, value);
        value += 1;

        OF_MATCH_MASK_BSN_UDF5_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_udf5, value);
        value += 1;

        OF_MATCH_MASK_BSN_UDF6_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_udf6, value);
        value += 1;

        OF_MATCH_MASK_BSN_UDF7_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_udf7, value);
        value += 1;

        OF_MATCH_MASK_BSN_VLAN_XLATE_PORT_GROUP_ID_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_vlan_xlate_port_group_id, value);
        value += 1;

        OF_MATCH_MASK_BSN_VRF_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_vrf, value);
        value += 1;

        OF_MATCH_MASK_CONN_TRACKING_IPV6_DST_EXACT_SET(match);
        VAR_OF_IPV6_T_INIT(match->fields.conn_tracking_ipv6_dst, value);
        value += 1;

        OF_MATCH_MASK_CONN_TRACKING_IPV6_SRC_EXACT_SET(match);
        VAR_OF_IPV6_T_INIT(match->fields.conn_tracking_ipv6_src, value);
        value += 1;

        OF_MATCH_MASK_CONN_TRACKING_LABEL_EXACT_SET(match);
        VAR_UINT128_T_INIT(match->fields.conn_tracking_label, value);
        value += 1;

        OF_MATCH_MASK_CONN_TRACKING_MARK_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.conn_tracking_mark, value);
        value += 1;

        OF_MATCH_MASK_CONN_TRACKING_NW_DST_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.conn_tracking_nw_dst, value);
        value += 1;

        OF_MATCH_MASK_CONN_TRACKING_NW_PROTO_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.conn_tracking_nw_proto, value);
        value += 1;

        OF_MATCH_MASK_CONN_TRACKING_NW_SRC_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.conn_tracking_nw_src, value);
        value += 1;

        OF_MATCH_MASK_CONN_TRACKING_STATE_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.conn_tracking_state, value);
        value += 1;

        OF_MATCH_MASK_CONN_TRACKING_TP_DST_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.conn_tracking_tp_dst, value);
        value += 1;

        OF_MATCH_MASK_CONN_TRACKING_TP_SRC_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.conn_tracking_tp_src, value);
        value += 1;

        OF_MATCH_MASK_CONN_TRACKING_ZONE_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.conn_tracking_zone, value);
        value += 1;

        OF_MATCH_MASK_ETH_DST_EXACT_SET(match);
        VAR_OF_MAC_ADDR_T_INIT(match->fields.eth_dst, value);
        value += 1;

        OF_MATCH_MASK_ETH_SRC_EXACT_SET(match);
        VAR_OF_MAC_ADDR_T_INIT(match->fields.eth_src, value);
        value += 1;

        OF_MATCH_MASK_ETH_TYPE_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.eth_type, value);
        value += 1;

        OF_MATCH_MASK_ICMPV4_CODE_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.icmpv4_code, value);
        value += 1;

        OF_MATCH_MASK_ICMPV4_TYPE_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.icmpv4_type, value);
        value += 1;

        OF_MATCH_MASK_ICMPV6_CODE_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.icmpv6_code, value);
        value += 1;

        OF_MATCH_MASK_ICMPV6_TYPE_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.icmpv6_type, value);
        value += 1;

        OF_MATCH_MASK_IN_PHY_PORT_EXACT_SET(match);
        VAR_OF_PORT_NO_T_INIT(match->fields.in_phy_port, value);
        value += 1;

        OF_MATCH_MASK_IN_PORT_EXACT_SET(match);
        VAR_OF_PORT_NO_T_INIT(match->fields.in_port, value);
        value += 1;

        OF_MATCH_MASK_IP_DSCP_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.ip_dscp, value);
        value += 1;

        OF_MATCH_MASK_IP_ECN_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.ip_ecn, value);
        value += 1;

        OF_MATCH_MASK_IP_PROTO_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.ip_proto, value);
        value += 1;

        OF_MATCH_MASK_IPV4_DST_EXACT_SET(match);
        VAR_OF_IPV4_T_INIT(match->fields.ipv4_dst, value);
        value += 1;

        OF_MATCH_MASK_IPV4_SRC_EXACT_SET(match);
        VAR_OF_IPV4_T_INIT(match->fields.ipv4_src, value);
        value += 1;

        OF_MATCH_MASK_IPV6_DST_EXACT_SET(match);
        VAR_OF_IPV6_T_INIT(match->fields.ipv6_dst, value);
        value += 1;

        OF_MATCH_MASK_IPV6_FLABEL_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.ipv6_flabel, value);
        value += 1;

        OF_MATCH_MASK_IPV6_ND_SLL_EXACT_SET(match);
        VAR_OF_MAC_ADDR_T_INIT(match->fields.ipv6_nd_sll, value);
        value += 1;

        OF_MATCH_MASK_IPV6_ND_TARGET_EXACT_SET(match);
        VAR_OF_IPV6_T_INIT(match->fields.ipv6_nd_target, value);
        value += 1;

        OF_MATCH_MASK_IPV6_ND_TLL_EXACT_SET(match);
        VAR_OF_MAC_ADDR_T_INIT(match->fields.ipv6_nd_tll, value);
        value += 1;

        OF_MATCH_MASK_IPV6_SRC_EXACT_SET(match);
        VAR_OF_IPV6_T_INIT(match->fields.ipv6_src, value);
        value += 1;

        OF_MATCH_MASK_METADATA_EXACT_SET(match);
        VAR_UINT64_T_INIT(match->fields.metadata, value);
        value += 1;

        OF_MATCH_MASK_MPLS_LABEL_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.mpls_label, value);
        value += 1;

        OF_MATCH_MASK_MPLS_TC_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.mpls_tc, value);
        value += 1;

        OF_MATCH_MASK_OVS_TCP_FLAGS_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.ovs_tcp_flags, value);
        value += 1;

        OF_MATCH_MASK_SCTP_DST_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.sctp_dst, value);
        value += 1;

        OF_MATCH_MASK_SCTP_SRC_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.sctp_src, value);
        value += 1;

        OF_MATCH_MASK_TCP_DST_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.tcp_dst, value);
        value += 1;

        OF_MATCH_MASK_TCP_SRC_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.tcp_src, value);
        value += 1;

        OF_MATCH_MASK_TUNNEL_IPV4_DST_EXACT_SET(match);
        VAR_OF_IPV4_T_INIT(match->fields.tunnel_ipv4_dst, value);
        value += 1;

        OF_MATCH_MASK_TUNNEL_IPV4_SRC_EXACT_SET(match);
        VAR_OF_IPV4_T_INIT(match->fields.tunnel_ipv4_src, value);
        value += 1;

        OF_MATCH_MASK_UDP_DST_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.udp_dst, value);
        value += 1;

        OF_MATCH_MASK_UDP_SRC_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.udp_src, value);
        value += 1;

        OF_MATCH_MASK_VLAN_PCP_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.vlan_pcp, value);
        value += 1;

        OF_MATCH_MASK_VLAN_VID_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.vlan_vid, value);
        value += 1;

        OF_MATCH_MASK_BSN_INNER_ETH_DST_EXACT_SET(match);
        VAR_OF_MAC_ADDR_T_INIT(match->fields.bsn_inner_eth_dst, value);
        value += 1;

        OF_MATCH_MASK_BSN_INNER_ETH_SRC_EXACT_SET(match);
        VAR_OF_MAC_ADDR_T_INIT(match->fields.bsn_inner_eth_src, value);
        value += 1;

        OF_MATCH_MASK_BSN_INNER_VLAN_VID_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.bsn_inner_vlan_vid, value);
        value += 1;

        OF_MATCH_MASK_BSN_VFI_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.bsn_vfi, value);
        value += 1;

        OF_MATCH_MASK_BSN_VXLAN_NETWORK_ID_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_vxlan_network_id, value);
        value += 1;

        OF_MATCH_MASK_IPV6_EXTHDR_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.ipv6_exthdr, value);
        value += 1;

        OF_MATCH_MASK_MPLS_BOS_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.mpls_bos, value);
        value += 1;

        OF_MATCH_MASK_TUNNEL_ID_EXACT_SET(match);
        VAR_UINT64_T_INIT(match->fields.tunnel_id, value);
        value += 1;

    }


    if (version == 5) {
        OF_MATCH_MASK_ARP_OP_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.arp_op, value);
        value += 1;

        OF_MATCH_MASK_ARP_SHA_EXACT_SET(match);
        VAR_OF_MAC_ADDR_T_INIT(match->fields.arp_sha, value);
        value += 1;

        OF_MATCH_MASK_ARP_SPA_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.arp_spa, value);
        value += 1;

        OF_MATCH_MASK_ARP_THA_EXACT_SET(match);
        VAR_OF_MAC_ADDR_T_INIT(match->fields.arp_tha, value);
        value += 1;

        OF_MATCH_MASK_ARP_TPA_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.arp_tpa, value);
        value += 1;

        OF_MATCH_MASK_BSN_EGR_PORT_GROUP_ID_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_egr_port_group_id, value);
        value += 1;

        OF_MATCH_MASK_BSN_IN_PORTS_128_EXACT_SET(match);
        VAR_OF_BITMAP_128_T_INIT(match->fields.bsn_in_ports_128, value);
        value += 1;

        OF_MATCH_MASK_BSN_IN_PORTS_512_EXACT_SET(match);
        VAR_OF_BITMAP_512_T_INIT(match->fields.bsn_in_ports_512, value);
        value += 1;

        OF_MATCH_MASK_BSN_INGRESS_PORT_GROUP_ID_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_ingress_port_group_id, value);
        value += 1;

        OF_MATCH_MASK_BSN_IP_FRAGMENTATION_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.bsn_ip_fragmentation, value);
        value += 1;

        OF_MATCH_MASK_BSN_L2_CACHE_HIT_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.bsn_l2_cache_hit, value);
        value += 1;

        OF_MATCH_MASK_BSN_L3_INTERFACE_CLASS_ID_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_l3_interface_class_id, value);
        value += 1;

        OF_MATCH_MASK_BSN_L3_SRC_CLASS_ID_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_l3_src_class_id, value);
        value += 1;

        OF_MATCH_MASK_BSN_LAG_ID_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_lag_id, value);
        value += 1;

        OF_MATCH_MASK_BSN_TCP_FLAGS_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.bsn_tcp_flags, value);
        value += 1;

        OF_MATCH_MASK_BSN_UDF0_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_udf0, value);
        value += 1;

        OF_MATCH_MASK_BSN_UDF1_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_udf1, value);
        value += 1;

        OF_MATCH_MASK_BSN_UDF2_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_udf2, value);
        value += 1;

        OF_MATCH_MASK_BSN_UDF3_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_udf3, value);
        value += 1;

        OF_MATCH_MASK_BSN_UDF4_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_udf4, value);
        value += 1;

        OF_MATCH_MASK_BSN_UDF5_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_udf5, value);
        value += 1;

        OF_MATCH_MASK_BSN_UDF6_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_udf6, value);
        value += 1;

        OF_MATCH_MASK_BSN_UDF7_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_udf7, value);
        value += 1;

        OF_MATCH_MASK_BSN_VLAN_XLATE_PORT_GROUP_ID_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_vlan_xlate_port_group_id, value);
        value += 1;

        OF_MATCH_MASK_BSN_VRF_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_vrf, value);
        value += 1;

        OF_MATCH_MASK_CONN_TRACKING_IPV6_DST_EXACT_SET(match);
        VAR_OF_IPV6_T_INIT(match->fields.conn_tracking_ipv6_dst, value);
        value += 1;

        OF_MATCH_MASK_CONN_TRACKING_IPV6_SRC_EXACT_SET(match);
        VAR_OF_IPV6_T_INIT(match->fields.conn_tracking_ipv6_src, value);
        value += 1;

        OF_MATCH_MASK_CONN_TRACKING_LABEL_EXACT_SET(match);
        VAR_UINT128_T_INIT(match->fields.conn_tracking_label, value);
        value += 1;

        OF_MATCH_MASK_CONN_TRACKING_MARK_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.conn_tracking_mark, value);
        value += 1;

        OF_MATCH_MASK_CONN_TRACKING_NW_DST_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.conn_tracking_nw_dst, value);
        value += 1;

        OF_MATCH_MASK_CONN_TRACKING_NW_PROTO_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.conn_tracking_nw_proto, value);
        value += 1;

        OF_MATCH_MASK_CONN_TRACKING_NW_SRC_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.conn_tracking_nw_src, value);
        value += 1;

        OF_MATCH_MASK_CONN_TRACKING_STATE_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.conn_tracking_state, value);
        value += 1;

        OF_MATCH_MASK_CONN_TRACKING_TP_DST_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.conn_tracking_tp_dst, value);
        value += 1;

        OF_MATCH_MASK_CONN_TRACKING_TP_SRC_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.conn_tracking_tp_src, value);
        value += 1;

        OF_MATCH_MASK_CONN_TRACKING_ZONE_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.conn_tracking_zone, value);
        value += 1;

        OF_MATCH_MASK_ETH_DST_EXACT_SET(match);
        VAR_OF_MAC_ADDR_T_INIT(match->fields.eth_dst, value);
        value += 1;

        OF_MATCH_MASK_ETH_SRC_EXACT_SET(match);
        VAR_OF_MAC_ADDR_T_INIT(match->fields.eth_src, value);
        value += 1;

        OF_MATCH_MASK_ETH_TYPE_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.eth_type, value);
        value += 1;

        OF_MATCH_MASK_ICMPV4_CODE_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.icmpv4_code, value);
        value += 1;

        OF_MATCH_MASK_ICMPV4_TYPE_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.icmpv4_type, value);
        value += 1;

        OF_MATCH_MASK_ICMPV6_CODE_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.icmpv6_code, value);
        value += 1;

        OF_MATCH_MASK_ICMPV6_TYPE_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.icmpv6_type, value);
        value += 1;

        OF_MATCH_MASK_IN_PHY_PORT_EXACT_SET(match);
        VAR_OF_PORT_NO_T_INIT(match->fields.in_phy_port, value);
        value += 1;

        OF_MATCH_MASK_IN_PORT_EXACT_SET(match);
        VAR_OF_PORT_NO_T_INIT(match->fields.in_port, value);
        value += 1;

        OF_MATCH_MASK_IP_DSCP_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.ip_dscp, value);
        value += 1;

        OF_MATCH_MASK_IP_ECN_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.ip_ecn, value);
        value += 1;

        OF_MATCH_MASK_IP_PROTO_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.ip_proto, value);
        value += 1;

        OF_MATCH_MASK_IPV4_DST_EXACT_SET(match);
        VAR_OF_IPV4_T_INIT(match->fields.ipv4_dst, value);
        value += 1;

        OF_MATCH_MASK_IPV4_SRC_EXACT_SET(match);
        VAR_OF_IPV4_T_INIT(match->fields.ipv4_src, value);
        value += 1;

        OF_MATCH_MASK_IPV6_DST_EXACT_SET(match);
        VAR_OF_IPV6_T_INIT(match->fields.ipv6_dst, value);
        value += 1;

        OF_MATCH_MASK_IPV6_FLABEL_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.ipv6_flabel, value);
        value += 1;

        OF_MATCH_MASK_IPV6_ND_SLL_EXACT_SET(match);
        VAR_OF_MAC_ADDR_T_INIT(match->fields.ipv6_nd_sll, value);
        value += 1;

        OF_MATCH_MASK_IPV6_ND_TARGET_EXACT_SET(match);
        VAR_OF_IPV6_T_INIT(match->fields.ipv6_nd_target, value);
        value += 1;

        OF_MATCH_MASK_IPV6_ND_TLL_EXACT_SET(match);
        VAR_OF_MAC_ADDR_T_INIT(match->fields.ipv6_nd_tll, value);
        value += 1;

        OF_MATCH_MASK_IPV6_SRC_EXACT_SET(match);
        VAR_OF_IPV6_T_INIT(match->fields.ipv6_src, value);
        value += 1;

        OF_MATCH_MASK_METADATA_EXACT_SET(match);
        VAR_UINT64_T_INIT(match->fields.metadata, value);
        value += 1;

        OF_MATCH_MASK_MPLS_LABEL_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.mpls_label, value);
        value += 1;

        OF_MATCH_MASK_MPLS_TC_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.mpls_tc, value);
        value += 1;

        OF_MATCH_MASK_OVS_TCP_FLAGS_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.ovs_tcp_flags, value);
        value += 1;

        OF_MATCH_MASK_SCTP_DST_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.sctp_dst, value);
        value += 1;

        OF_MATCH_MASK_SCTP_SRC_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.sctp_src, value);
        value += 1;

        OF_MATCH_MASK_TCP_DST_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.tcp_dst, value);
        value += 1;

        OF_MATCH_MASK_TCP_SRC_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.tcp_src, value);
        value += 1;

        OF_MATCH_MASK_TUNNEL_IPV4_DST_EXACT_SET(match);
        VAR_OF_IPV4_T_INIT(match->fields.tunnel_ipv4_dst, value);
        value += 1;

        OF_MATCH_MASK_TUNNEL_IPV4_SRC_EXACT_SET(match);
        VAR_OF_IPV4_T_INIT(match->fields.tunnel_ipv4_src, value);
        value += 1;

        OF_MATCH_MASK_UDP_DST_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.udp_dst, value);
        value += 1;

        OF_MATCH_MASK_UDP_SRC_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.udp_src, value);
        value += 1;

        OF_MATCH_MASK_VLAN_PCP_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.vlan_pcp, value);
        value += 1;

        OF_MATCH_MASK_VLAN_VID_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.vlan_vid, value);
        value += 1;

        OF_MATCH_MASK_BSN_INNER_ETH_DST_EXACT_SET(match);
        VAR_OF_MAC_ADDR_T_INIT(match->fields.bsn_inner_eth_dst, value);
        value += 1;

        OF_MATCH_MASK_BSN_INNER_ETH_SRC_EXACT_SET(match);
        VAR_OF_MAC_ADDR_T_INIT(match->fields.bsn_inner_eth_src, value);
        value += 1;

        OF_MATCH_MASK_BSN_INNER_VLAN_VID_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.bsn_inner_vlan_vid, value);
        value += 1;

        OF_MATCH_MASK_BSN_VFI_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.bsn_vfi, value);
        value += 1;

        OF_MATCH_MASK_BSN_VXLAN_NETWORK_ID_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_vxlan_network_id, value);
        value += 1;

        OF_MATCH_MASK_IPV6_EXTHDR_EXACT_SET(match);
        VAR_UINT16_T_INIT(match->fields.ipv6_exthdr, value);
        value += 1;

        OF_MATCH_MASK_MPLS_BOS_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.mpls_bos, value);
        value += 1;

        OF_MATCH_MASK_TUNNEL_ID_EXACT_SET(match);
        VAR_UINT64_T_INIT(match->fields.tunnel_id, value);
        value += 1;

        OF_MATCH_MASK_BSN_IFP_CLASS_ID_EXACT_SET(match);
        VAR_UINT32_T_INIT(match->fields.bsn_ifp_class_id, value);
        value += 1;

        OF_MATCH_MASK_PBB_UCA_EXACT_SET(match);
        VAR_UINT8_T_INIT(match->fields.pbb_uca, value);
        value += 1;

    }


    if (value % 2) {
        /* Sometimes set ipv4 addr masks to non-exact */
        match->masks.ipv4_src = 0xffff0000;
        match->masks.ipv4_dst = 0xfffff800;
    }

    /* Restrict values according to masks */
    of_memmask(&match->fields, &match->masks, sizeof(match->fields));
    return value;
}

int
of_match_check(of_match_t *match, of_version_t version, int value)
{
    of_match_t check;

    value = of_match_populate(&check, match->version, value);
    TEST_ASSERT(value != 0);
    TEST_ASSERT(MEMCMP(match, &check, sizeof(check)) == 0);

    return value;
}

/**
 * Test cases for all flag accessor macros
 * These only test self consistency (and that they compile)
 */
int
test_ident_macros(void)
{
    int value __attribute__((unused));
    uint32_t flags;

    value = BSN_PDU_SLOT_NUM_ANY;
    TEST_ASSERT(BSN_PDU_SLOT_NUM_ANY_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(BSN_PDU_SLOT_NUM_ANY_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(BSN_PDU_SLOT_NUM_ANY_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(BSN_PDU_SLOT_NUM_ANY_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(BSN_PDU_SLOT_NUM_ANY_SUPPORTED(OF_VERSION_1_4));
    value = OF_BSN_VPORT_STATUS_OK;
    TEST_ASSERT(OF_BSN_VPORT_STATUS_OK_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_BSN_VPORT_STATUS_OK_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_BSN_VPORT_STATUS_OK_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_BSN_VPORT_STATUS_OK_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_BSN_VPORT_STATUS_OK_SUPPORTED(OF_VERSION_1_4));
    value = OF_BSN_VPORT_STATUS_FAILED;
    TEST_ASSERT(OF_BSN_VPORT_STATUS_FAILED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_BSN_VPORT_STATUS_FAILED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_BSN_VPORT_STATUS_FAILED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_BSN_VPORT_STATUS_FAILED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_BSN_VPORT_STATUS_FAILED_SUPPORTED(OF_VERSION_1_4));
    value = OF_BSN_VPORT_Q_IN_Q_UNTAGGED;
    TEST_ASSERT(OF_BSN_VPORT_Q_IN_Q_UNTAGGED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_BSN_VPORT_Q_IN_Q_UNTAGGED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_BSN_VPORT_Q_IN_Q_UNTAGGED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_BSN_VPORT_Q_IN_Q_UNTAGGED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_BSN_VPORT_Q_IN_Q_UNTAGGED_SUPPORTED(OF_VERSION_1_4));
    value = OF_BSN_VPORT_L2GRE_LOCAL_MAC_IS_VALID;
    TEST_ASSERT(OF_BSN_VPORT_L2GRE_LOCAL_MAC_IS_VALID_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_BSN_VPORT_L2GRE_LOCAL_MAC_IS_VALID_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_BSN_VPORT_L2GRE_LOCAL_MAC_IS_VALID_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_BSN_VPORT_L2GRE_LOCAL_MAC_IS_VALID_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_BSN_VPORT_L2GRE_LOCAL_MAC_IS_VALID_SUPPORTED(OF_VERSION_1_4));
    value = OF_BSN_VPORT_L2GRE_DSCP_ASSIGN;
    TEST_ASSERT(OF_BSN_VPORT_L2GRE_DSCP_ASSIGN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_BSN_VPORT_L2GRE_DSCP_ASSIGN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_BSN_VPORT_L2GRE_DSCP_ASSIGN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_BSN_VPORT_L2GRE_DSCP_ASSIGN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_BSN_VPORT_L2GRE_DSCP_ASSIGN_SUPPORTED(OF_VERSION_1_4));
    value = OF_BSN_VPORT_L2GRE_DSCP_COPY;
    TEST_ASSERT(OF_BSN_VPORT_L2GRE_DSCP_COPY_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_BSN_VPORT_L2GRE_DSCP_COPY_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_BSN_VPORT_L2GRE_DSCP_COPY_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_BSN_VPORT_L2GRE_DSCP_COPY_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_BSN_VPORT_L2GRE_DSCP_COPY_SUPPORTED(OF_VERSION_1_4));
    value = OF_BSN_VPORT_L2GRE_LOOPBACK_IS_VALID;
    TEST_ASSERT(OF_BSN_VPORT_L2GRE_LOOPBACK_IS_VALID_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_BSN_VPORT_L2GRE_LOOPBACK_IS_VALID_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_BSN_VPORT_L2GRE_LOOPBACK_IS_VALID_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_BSN_VPORT_L2GRE_LOOPBACK_IS_VALID_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_BSN_VPORT_L2GRE_LOOPBACK_IS_VALID_SUPPORTED(OF_VERSION_1_4));
    value = OF_BSN_VPORT_L2GRE_RATE_LIMIT_IS_VALID;
    TEST_ASSERT(OF_BSN_VPORT_L2GRE_RATE_LIMIT_IS_VALID_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_BSN_VPORT_L2GRE_RATE_LIMIT_IS_VALID_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_BSN_VPORT_L2GRE_RATE_LIMIT_IS_VALID_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_BSN_VPORT_L2GRE_RATE_LIMIT_IS_VALID_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_BSN_VPORT_L2GRE_RATE_LIMIT_IS_VALID_SUPPORTED(OF_VERSION_1_4));
    value = OF_NICIRA_CONTROLLER_ROLE_OTHER;
    TEST_ASSERT(OF_NICIRA_CONTROLLER_ROLE_OTHER_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_NICIRA_CONTROLLER_ROLE_OTHER_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_NICIRA_CONTROLLER_ROLE_OTHER_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_NICIRA_CONTROLLER_ROLE_OTHER_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_NICIRA_CONTROLLER_ROLE_OTHER_SUPPORTED(OF_VERSION_1_4));
    value = OF_NICIRA_CONTROLLER_ROLE_MASTER;
    TEST_ASSERT(OF_NICIRA_CONTROLLER_ROLE_MASTER_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_NICIRA_CONTROLLER_ROLE_MASTER_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_NICIRA_CONTROLLER_ROLE_MASTER_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_NICIRA_CONTROLLER_ROLE_MASTER_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_NICIRA_CONTROLLER_ROLE_MASTER_SUPPORTED(OF_VERSION_1_4));
    value = OF_NICIRA_CONTROLLER_ROLE_SLAVE;
    TEST_ASSERT(OF_NICIRA_CONTROLLER_ROLE_SLAVE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_NICIRA_CONTROLLER_ROLE_SLAVE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_NICIRA_CONTROLLER_ROLE_SLAVE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_NICIRA_CONTROLLER_ROLE_SLAVE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_NICIRA_CONTROLLER_ROLE_SLAVE_SUPPORTED(OF_VERSION_1_4));
    value = OF_MAX_TABLE_NAME_LEN;
    TEST_ASSERT(OF_MAX_TABLE_NAME_LEN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_MAX_TABLE_NAME_LEN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_MAX_TABLE_NAME_LEN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_MAX_TABLE_NAME_LEN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_MAX_TABLE_NAME_LEN_SUPPORTED(OF_VERSION_1_4));
    value = OF_MAX_PORT_NAME_LEN;
    TEST_ASSERT(OF_MAX_PORT_NAME_LEN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_MAX_PORT_NAME_LEN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_MAX_PORT_NAME_LEN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_MAX_PORT_NAME_LEN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_MAX_PORT_NAME_LEN_SUPPORTED(OF_VERSION_1_4));
    value = OF_TCP_PORT;
    TEST_ASSERT(OF_TCP_PORT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_TCP_PORT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_TCP_PORT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_TCP_PORT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_TCP_PORT_SUPPORTED(OF_VERSION_1_4));
    value = OF_SSL_PORT;
    TEST_ASSERT(OF_SSL_PORT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_SSL_PORT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_SSL_PORT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_SSL_PORT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_SSL_PORT_SUPPORTED(OF_VERSION_1_4));
    value = OF_ETH_ALEN;
    TEST_ASSERT(OF_ETH_ALEN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ETH_ALEN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ETH_ALEN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ETH_ALEN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ETH_ALEN_SUPPORTED(OF_VERSION_1_4));
    value = OF_DEFAULT_MISS_SEND_LEN;
    TEST_ASSERT(OF_DEFAULT_MISS_SEND_LEN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_DEFAULT_MISS_SEND_LEN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_DEFAULT_MISS_SEND_LEN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_DEFAULT_MISS_SEND_LEN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_DEFAULT_MISS_SEND_LEN_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_WC_V1_ICMP_TYPE;
    TEST_ASSERT(OF_FLOW_WC_V1_ICMP_TYPE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_FLOW_WC_V1_ICMP_TYPE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_FLOW_WC_V1_ICMP_TYPE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_FLOW_WC_V1_ICMP_TYPE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_FLOW_WC_V1_ICMP_TYPE_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_WC_V1_ICMP_CODE;
    TEST_ASSERT(OF_FLOW_WC_V1_ICMP_CODE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_FLOW_WC_V1_ICMP_CODE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_FLOW_WC_V1_ICMP_CODE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_FLOW_WC_V1_ICMP_CODE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_FLOW_WC_V1_ICMP_CODE_SUPPORTED(OF_VERSION_1_4));
    value = OF_DL_TYPE_ETH2_CUTOFF;
    TEST_ASSERT(OF_DL_TYPE_ETH2_CUTOFF_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_DL_TYPE_ETH2_CUTOFF_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_DL_TYPE_ETH2_CUTOFF_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_DL_TYPE_ETH2_CUTOFF_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_DL_TYPE_ETH2_CUTOFF_SUPPORTED(OF_VERSION_1_4));
    value = OF_DL_TYPE_NOT_ETH_TYPE;
    TEST_ASSERT(OF_DL_TYPE_NOT_ETH_TYPE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_DL_TYPE_NOT_ETH_TYPE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_DL_TYPE_NOT_ETH_TYPE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_DL_TYPE_NOT_ETH_TYPE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_DL_TYPE_NOT_ETH_TYPE_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_PERMANENT;
    TEST_ASSERT(OF_FLOW_PERMANENT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_FLOW_PERMANENT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_FLOW_PERMANENT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_FLOW_PERMANENT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_FLOW_PERMANENT_SUPPORTED(OF_VERSION_1_4));
    value = OF_DEFAULT_PRIORITY;
    TEST_ASSERT(OF_DEFAULT_PRIORITY_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_DEFAULT_PRIORITY_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_DEFAULT_PRIORITY_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_DEFAULT_PRIORITY_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_DEFAULT_PRIORITY_SUPPORTED(OF_VERSION_1_4));
    value = OF_DESC_STR_LEN;
    TEST_ASSERT(OF_DESC_STR_LEN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_DESC_STR_LEN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_DESC_STR_LEN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_DESC_STR_LEN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_DESC_STR_LEN_SUPPORTED(OF_VERSION_1_4));
    value = OF_SERIAL_NUM_LEN;
    TEST_ASSERT(OF_SERIAL_NUM_LEN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_SERIAL_NUM_LEN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_SERIAL_NUM_LEN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_SERIAL_NUM_LEN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_SERIAL_NUM_LEN_SUPPORTED(OF_VERSION_1_4));
    value = OF_QUEUE_ALL;
    TEST_ASSERT(OF_QUEUE_ALL_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_QUEUE_ALL_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_QUEUE_ALL_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_QUEUE_ALL_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_QUEUE_ALL_SUPPORTED(OF_VERSION_1_4));
    value = OF_QUEUE_MIN_RATE_UNCFG;
    TEST_ASSERT(OF_QUEUE_MIN_RATE_UNCFG_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_QUEUE_MIN_RATE_UNCFG_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_QUEUE_MIN_RATE_UNCFG_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_QUEUE_MIN_RATE_UNCFG_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_QUEUE_MIN_RATE_UNCFG_SUPPORTED(OF_VERSION_1_4));
    value = OF_OBJ_TYPE_HELLO;
    TEST_ASSERT(OF_OBJ_TYPE_HELLO_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_OBJ_TYPE_HELLO_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_OBJ_TYPE_HELLO_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_OBJ_TYPE_HELLO_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_OBJ_TYPE_HELLO_SUPPORTED(OF_VERSION_1_4));
    value = OF_OBJ_TYPE_ERROR;
    TEST_ASSERT(OF_OBJ_TYPE_ERROR_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_OBJ_TYPE_ERROR_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_OBJ_TYPE_ERROR_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_OBJ_TYPE_ERROR_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_OBJ_TYPE_ERROR_SUPPORTED(OF_VERSION_1_4));
    value = OF_OBJ_TYPE_ECHO_REQUEST;
    TEST_ASSERT(OF_OBJ_TYPE_ECHO_REQUEST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_OBJ_TYPE_ECHO_REQUEST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_OBJ_TYPE_ECHO_REQUEST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_OBJ_TYPE_ECHO_REQUEST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_OBJ_TYPE_ECHO_REQUEST_SUPPORTED(OF_VERSION_1_4));
    value = OF_OBJ_TYPE_ECHO_REPLY;
    TEST_ASSERT(OF_OBJ_TYPE_ECHO_REPLY_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_OBJ_TYPE_ECHO_REPLY_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_OBJ_TYPE_ECHO_REPLY_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_OBJ_TYPE_ECHO_REPLY_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_OBJ_TYPE_ECHO_REPLY_SUPPORTED(OF_VERSION_1_4));
    value = OF_OBJ_TYPE_EXPERIMENTER;
    TEST_ASSERT(OF_OBJ_TYPE_EXPERIMENTER_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_OBJ_TYPE_EXPERIMENTER_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_OBJ_TYPE_EXPERIMENTER_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_OBJ_TYPE_EXPERIMENTER_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_OBJ_TYPE_EXPERIMENTER_SUPPORTED(OF_VERSION_1_4));
    value = OF_OBJ_TYPE_FEATURES_REQUEST;
    TEST_ASSERT(OF_OBJ_TYPE_FEATURES_REQUEST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_OBJ_TYPE_FEATURES_REQUEST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_OBJ_TYPE_FEATURES_REQUEST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_OBJ_TYPE_FEATURES_REQUEST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_OBJ_TYPE_FEATURES_REQUEST_SUPPORTED(OF_VERSION_1_4));
    value = OF_OBJ_TYPE_FEATURES_REPLY;
    TEST_ASSERT(OF_OBJ_TYPE_FEATURES_REPLY_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_OBJ_TYPE_FEATURES_REPLY_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_OBJ_TYPE_FEATURES_REPLY_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_OBJ_TYPE_FEATURES_REPLY_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_OBJ_TYPE_FEATURES_REPLY_SUPPORTED(OF_VERSION_1_4));
    value = OF_OBJ_TYPE_GET_CONFIG_REQUEST;
    TEST_ASSERT(OF_OBJ_TYPE_GET_CONFIG_REQUEST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_OBJ_TYPE_GET_CONFIG_REQUEST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_OBJ_TYPE_GET_CONFIG_REQUEST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_OBJ_TYPE_GET_CONFIG_REQUEST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_OBJ_TYPE_GET_CONFIG_REQUEST_SUPPORTED(OF_VERSION_1_4));
    value = OF_OBJ_TYPE_GET_CONFIG_REPLY;
    TEST_ASSERT(OF_OBJ_TYPE_GET_CONFIG_REPLY_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_OBJ_TYPE_GET_CONFIG_REPLY_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_OBJ_TYPE_GET_CONFIG_REPLY_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_OBJ_TYPE_GET_CONFIG_REPLY_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_OBJ_TYPE_GET_CONFIG_REPLY_SUPPORTED(OF_VERSION_1_4));
    value = OF_OBJ_TYPE_SET_CONFIG;
    TEST_ASSERT(OF_OBJ_TYPE_SET_CONFIG_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_OBJ_TYPE_SET_CONFIG_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_OBJ_TYPE_SET_CONFIG_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_OBJ_TYPE_SET_CONFIG_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_OBJ_TYPE_SET_CONFIG_SUPPORTED(OF_VERSION_1_4));
    value = OF_OBJ_TYPE_PACKET_IN;
    TEST_ASSERT(OF_OBJ_TYPE_PACKET_IN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_OBJ_TYPE_PACKET_IN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_OBJ_TYPE_PACKET_IN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_OBJ_TYPE_PACKET_IN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_OBJ_TYPE_PACKET_IN_SUPPORTED(OF_VERSION_1_4));
    value = OF_OBJ_TYPE_FLOW_REMOVED;
    TEST_ASSERT(OF_OBJ_TYPE_FLOW_REMOVED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_OBJ_TYPE_FLOW_REMOVED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_OBJ_TYPE_FLOW_REMOVED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_OBJ_TYPE_FLOW_REMOVED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_OBJ_TYPE_FLOW_REMOVED_SUPPORTED(OF_VERSION_1_4));
    value = OF_OBJ_TYPE_PORT_STATUS;
    TEST_ASSERT(OF_OBJ_TYPE_PORT_STATUS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_OBJ_TYPE_PORT_STATUS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_OBJ_TYPE_PORT_STATUS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_OBJ_TYPE_PORT_STATUS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_OBJ_TYPE_PORT_STATUS_SUPPORTED(OF_VERSION_1_4));
    value = OF_OBJ_TYPE_PACKET_OUT;
    TEST_ASSERT(OF_OBJ_TYPE_PACKET_OUT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_OBJ_TYPE_PACKET_OUT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_OBJ_TYPE_PACKET_OUT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_OBJ_TYPE_PACKET_OUT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_OBJ_TYPE_PACKET_OUT_SUPPORTED(OF_VERSION_1_4));
    value = OF_OBJ_TYPE_FLOW_MOD;
    TEST_ASSERT(OF_OBJ_TYPE_FLOW_MOD_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_OBJ_TYPE_FLOW_MOD_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_OBJ_TYPE_FLOW_MOD_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_OBJ_TYPE_FLOW_MOD_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_OBJ_TYPE_FLOW_MOD_SUPPORTED(OF_VERSION_1_4));
    value = OF_PORT_CONFIG_FLAG_PORT_DOWN;
    TEST_ASSERT(OF_PORT_CONFIG_FLAG_PORT_DOWN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_CONFIG_FLAG_PORT_DOWN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_PORT_CONFIG_FLAG_PORT_DOWN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PORT_CONFIG_FLAG_PORT_DOWN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PORT_CONFIG_FLAG_PORT_DOWN_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_PORT_CONFIG_FLAG_PORT_DOWN_SET(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == OF_PORT_CONFIG_FLAG_PORT_DOWN_BY_VERSION(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_CONFIG_FLAG_PORT_DOWN_TEST(flags, OF_VERSION_1_0));
    OF_PORT_CONFIG_FLAG_PORT_DOWN_CLEAR(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_PORT_CONFIG_FLAG_PORT_DOWN_TEST(flags, OF_VERSION_1_0));
    value = OF_PORT_CONFIG_FLAG_NO_STP;
    TEST_ASSERT(OF_PORT_CONFIG_FLAG_NO_STP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_PORT_CONFIG_FLAG_NO_STP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_PORT_CONFIG_FLAG_NO_STP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_PORT_CONFIG_FLAG_NO_STP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_PORT_CONFIG_FLAG_NO_STP_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_PORT_CONFIG_FLAG_NO_STP_SET(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == OF_PORT_CONFIG_FLAG_NO_STP_BY_VERSION(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_CONFIG_FLAG_NO_STP_TEST(flags, OF_VERSION_1_0));
    OF_PORT_CONFIG_FLAG_NO_STP_CLEAR(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_PORT_CONFIG_FLAG_NO_STP_TEST(flags, OF_VERSION_1_0));
    value = OF_PORT_CONFIG_FLAG_NO_RECV;
    TEST_ASSERT(OF_PORT_CONFIG_FLAG_NO_RECV_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_CONFIG_FLAG_NO_RECV_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_PORT_CONFIG_FLAG_NO_RECV_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PORT_CONFIG_FLAG_NO_RECV_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PORT_CONFIG_FLAG_NO_RECV_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_PORT_CONFIG_FLAG_NO_RECV_SET(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == OF_PORT_CONFIG_FLAG_NO_RECV_BY_VERSION(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_CONFIG_FLAG_NO_RECV_TEST(flags, OF_VERSION_1_0));
    OF_PORT_CONFIG_FLAG_NO_RECV_CLEAR(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_PORT_CONFIG_FLAG_NO_RECV_TEST(flags, OF_VERSION_1_0));
    value = OF_PORT_CONFIG_FLAG_NO_RECV_STP;
    TEST_ASSERT(OF_PORT_CONFIG_FLAG_NO_RECV_STP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_PORT_CONFIG_FLAG_NO_RECV_STP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_PORT_CONFIG_FLAG_NO_RECV_STP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_PORT_CONFIG_FLAG_NO_RECV_STP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_PORT_CONFIG_FLAG_NO_RECV_STP_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_PORT_CONFIG_FLAG_NO_RECV_STP_SET(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == OF_PORT_CONFIG_FLAG_NO_RECV_STP_BY_VERSION(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_CONFIG_FLAG_NO_RECV_STP_TEST(flags, OF_VERSION_1_0));
    OF_PORT_CONFIG_FLAG_NO_RECV_STP_CLEAR(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_PORT_CONFIG_FLAG_NO_RECV_STP_TEST(flags, OF_VERSION_1_0));
    value = OF_PORT_CONFIG_FLAG_NO_FLOOD;
    TEST_ASSERT(OF_PORT_CONFIG_FLAG_NO_FLOOD_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_PORT_CONFIG_FLAG_NO_FLOOD_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_PORT_CONFIG_FLAG_NO_FLOOD_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_PORT_CONFIG_FLAG_NO_FLOOD_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_PORT_CONFIG_FLAG_NO_FLOOD_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_PORT_CONFIG_FLAG_NO_FLOOD_SET(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == OF_PORT_CONFIG_FLAG_NO_FLOOD_BY_VERSION(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_CONFIG_FLAG_NO_FLOOD_TEST(flags, OF_VERSION_1_0));
    OF_PORT_CONFIG_FLAG_NO_FLOOD_CLEAR(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_PORT_CONFIG_FLAG_NO_FLOOD_TEST(flags, OF_VERSION_1_0));
    value = OF_PORT_CONFIG_FLAG_NO_FWD;
    TEST_ASSERT(OF_PORT_CONFIG_FLAG_NO_FWD_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_CONFIG_FLAG_NO_FWD_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_PORT_CONFIG_FLAG_NO_FWD_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PORT_CONFIG_FLAG_NO_FWD_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PORT_CONFIG_FLAG_NO_FWD_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_PORT_CONFIG_FLAG_NO_FWD_SET(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == OF_PORT_CONFIG_FLAG_NO_FWD_BY_VERSION(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_CONFIG_FLAG_NO_FWD_TEST(flags, OF_VERSION_1_0));
    OF_PORT_CONFIG_FLAG_NO_FWD_CLEAR(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_PORT_CONFIG_FLAG_NO_FWD_TEST(flags, OF_VERSION_1_0));
    value = OF_PORT_CONFIG_FLAG_NO_PACKET_IN;
    TEST_ASSERT(OF_PORT_CONFIG_FLAG_NO_PACKET_IN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_CONFIG_FLAG_NO_PACKET_IN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_PORT_CONFIG_FLAG_NO_PACKET_IN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PORT_CONFIG_FLAG_NO_PACKET_IN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PORT_CONFIG_FLAG_NO_PACKET_IN_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_PORT_CONFIG_FLAG_NO_PACKET_IN_SET(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == OF_PORT_CONFIG_FLAG_NO_PACKET_IN_BY_VERSION(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_CONFIG_FLAG_NO_PACKET_IN_TEST(flags, OF_VERSION_1_0));
    OF_PORT_CONFIG_FLAG_NO_PACKET_IN_CLEAR(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_PORT_CONFIG_FLAG_NO_PACKET_IN_TEST(flags, OF_VERSION_1_0));
    value = OF_PORT_CONFIG_FLAG_BSN_MIRROR_DEST;
    TEST_ASSERT(OF_PORT_CONFIG_FLAG_BSN_MIRROR_DEST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_CONFIG_FLAG_BSN_MIRROR_DEST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_PORT_CONFIG_FLAG_BSN_MIRROR_DEST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PORT_CONFIG_FLAG_BSN_MIRROR_DEST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PORT_CONFIG_FLAG_BSN_MIRROR_DEST_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_PORT_CONFIG_FLAG_BSN_MIRROR_DEST_SET(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == OF_PORT_CONFIG_FLAG_BSN_MIRROR_DEST_BY_VERSION(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_CONFIG_FLAG_BSN_MIRROR_DEST_TEST(flags, OF_VERSION_1_0));
    OF_PORT_CONFIG_FLAG_BSN_MIRROR_DEST_CLEAR(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_PORT_CONFIG_FLAG_BSN_MIRROR_DEST_TEST(flags, OF_VERSION_1_0));
    value = OF_PORT_STATE_FLAG_LINK_DOWN;
    TEST_ASSERT(OF_PORT_STATE_FLAG_LINK_DOWN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_STATE_FLAG_LINK_DOWN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_PORT_STATE_FLAG_LINK_DOWN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PORT_STATE_FLAG_LINK_DOWN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PORT_STATE_FLAG_LINK_DOWN_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_PORT_STATE_FLAG_LINK_DOWN_SET(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == OF_PORT_STATE_FLAG_LINK_DOWN_BY_VERSION(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_STATE_FLAG_LINK_DOWN_TEST(flags, OF_VERSION_1_0));
    OF_PORT_STATE_FLAG_LINK_DOWN_CLEAR(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_PORT_STATE_FLAG_LINK_DOWN_TEST(flags, OF_VERSION_1_0));
    value = OF_PORT_STATE_FLAG_STP_LISTEN;
    TEST_ASSERT(OF_PORT_STATE_FLAG_STP_LISTEN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_PORT_STATE_FLAG_STP_LISTEN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_PORT_STATE_FLAG_STP_LISTEN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_PORT_STATE_FLAG_STP_LISTEN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_PORT_STATE_FLAG_STP_LISTEN_SUPPORTED(OF_VERSION_1_4));
    value = OF_PORT_STATE_FLAG_STP_LEARN;
    TEST_ASSERT(OF_PORT_STATE_FLAG_STP_LEARN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_PORT_STATE_FLAG_STP_LEARN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_PORT_STATE_FLAG_STP_LEARN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_PORT_STATE_FLAG_STP_LEARN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_PORT_STATE_FLAG_STP_LEARN_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_PORT_STATE_FLAG_STP_LEARN_SET(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == OF_PORT_STATE_FLAG_STP_LEARN_BY_VERSION(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_STATE_FLAG_STP_LEARN_TEST(flags, OF_VERSION_1_0));
    OF_PORT_STATE_FLAG_STP_LEARN_CLEAR(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_PORT_STATE_FLAG_STP_LEARN_TEST(flags, OF_VERSION_1_0));
    value = OF_PORT_STATE_FLAG_STP_FORWARD;
    TEST_ASSERT(OF_PORT_STATE_FLAG_STP_FORWARD_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_PORT_STATE_FLAG_STP_FORWARD_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_PORT_STATE_FLAG_STP_FORWARD_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_PORT_STATE_FLAG_STP_FORWARD_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_PORT_STATE_FLAG_STP_FORWARD_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_PORT_STATE_FLAG_STP_FORWARD_SET(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == OF_PORT_STATE_FLAG_STP_FORWARD_BY_VERSION(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_STATE_FLAG_STP_FORWARD_TEST(flags, OF_VERSION_1_0));
    OF_PORT_STATE_FLAG_STP_FORWARD_CLEAR(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_PORT_STATE_FLAG_STP_FORWARD_TEST(flags, OF_VERSION_1_0));
    value = OF_PORT_STATE_FLAG_STP_BLOCK;
    TEST_ASSERT(OF_PORT_STATE_FLAG_STP_BLOCK_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_PORT_STATE_FLAG_STP_BLOCK_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_PORT_STATE_FLAG_STP_BLOCK_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_PORT_STATE_FLAG_STP_BLOCK_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_PORT_STATE_FLAG_STP_BLOCK_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_PORT_STATE_FLAG_STP_BLOCK_SET(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == OF_PORT_STATE_FLAG_STP_BLOCK_BY_VERSION(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_STATE_FLAG_STP_BLOCK_TEST(flags, OF_VERSION_1_0));
    OF_PORT_STATE_FLAG_STP_BLOCK_CLEAR(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_PORT_STATE_FLAG_STP_BLOCK_TEST(flags, OF_VERSION_1_0));
    value = OF_PORT_STATE_FLAG_STP_MASK;
    TEST_ASSERT(OF_PORT_STATE_FLAG_STP_MASK_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_PORT_STATE_FLAG_STP_MASK_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_PORT_STATE_FLAG_STP_MASK_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_PORT_STATE_FLAG_STP_MASK_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_PORT_STATE_FLAG_STP_MASK_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_PORT_STATE_FLAG_STP_MASK_SET(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == OF_PORT_STATE_FLAG_STP_MASK_BY_VERSION(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_STATE_FLAG_STP_MASK_TEST(flags, OF_VERSION_1_0));
    OF_PORT_STATE_FLAG_STP_MASK_CLEAR(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_PORT_STATE_FLAG_STP_MASK_TEST(flags, OF_VERSION_1_0));
    value = OF_PORT_NUMBER_MAX;
    TEST_ASSERT(OF_PORT_NUMBER_MAX_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_NUMBER_MAX_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_PORT_NUMBER_MAX_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PORT_NUMBER_MAX_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PORT_NUMBER_MAX_SUPPORTED(OF_VERSION_1_4));
    value = OF_PORT_DEST_IN_PORT;
    TEST_ASSERT(OF_PORT_DEST_IN_PORT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_DEST_IN_PORT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_PORT_DEST_IN_PORT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PORT_DEST_IN_PORT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PORT_DEST_IN_PORT_SUPPORTED(OF_VERSION_1_4));
    value = OF_PORT_DEST_USE_TABLE;
    TEST_ASSERT(OF_PORT_DEST_USE_TABLE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_DEST_USE_TABLE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_PORT_DEST_USE_TABLE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PORT_DEST_USE_TABLE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PORT_DEST_USE_TABLE_SUPPORTED(OF_VERSION_1_4));
    value = OF_PORT_DEST_NORMAL;
    TEST_ASSERT(OF_PORT_DEST_NORMAL_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_DEST_NORMAL_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_PORT_DEST_NORMAL_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PORT_DEST_NORMAL_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PORT_DEST_NORMAL_SUPPORTED(OF_VERSION_1_4));
    value = OF_PORT_DEST_FLOOD;
    TEST_ASSERT(OF_PORT_DEST_FLOOD_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_DEST_FLOOD_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_PORT_DEST_FLOOD_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PORT_DEST_FLOOD_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PORT_DEST_FLOOD_SUPPORTED(OF_VERSION_1_4));
    value = OF_PORT_DEST_ALL;
    TEST_ASSERT(OF_PORT_DEST_ALL_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_DEST_ALL_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_PORT_DEST_ALL_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PORT_DEST_ALL_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PORT_DEST_ALL_SUPPORTED(OF_VERSION_1_4));
    value = OF_PORT_DEST_CONTROLLER;
    TEST_ASSERT(OF_PORT_DEST_CONTROLLER_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_DEST_CONTROLLER_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_PORT_DEST_CONTROLLER_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PORT_DEST_CONTROLLER_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PORT_DEST_CONTROLLER_SUPPORTED(OF_VERSION_1_4));
    value = OF_PORT_DEST_LOCAL;
    TEST_ASSERT(OF_PORT_DEST_LOCAL_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_DEST_LOCAL_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_PORT_DEST_LOCAL_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PORT_DEST_LOCAL_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PORT_DEST_LOCAL_SUPPORTED(OF_VERSION_1_4));
    value = OF_PORT_DEST_NONE;
    TEST_ASSERT(OF_PORT_DEST_NONE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_PORT_DEST_NONE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_PORT_DEST_NONE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_PORT_DEST_NONE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_PORT_DEST_NONE_SUPPORTED(OF_VERSION_1_4));
    value = OF_PORT_FEATURE_FLAG_10MB_HD;
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_10MB_HD_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_10MB_HD_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_10MB_HD_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_10MB_HD_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_10MB_HD_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_PORT_FEATURE_FLAG_10MB_HD_SET(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == OF_PORT_FEATURE_FLAG_10MB_HD_BY_VERSION(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_10MB_HD_TEST(flags, OF_VERSION_1_0));
    OF_PORT_FEATURE_FLAG_10MB_HD_CLEAR(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_PORT_FEATURE_FLAG_10MB_HD_TEST(flags, OF_VERSION_1_0));
    value = OF_PORT_FEATURE_FLAG_10MB_FD;
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_10MB_FD_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_10MB_FD_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_10MB_FD_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_10MB_FD_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_10MB_FD_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_PORT_FEATURE_FLAG_10MB_FD_SET(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == OF_PORT_FEATURE_FLAG_10MB_FD_BY_VERSION(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_10MB_FD_TEST(flags, OF_VERSION_1_0));
    OF_PORT_FEATURE_FLAG_10MB_FD_CLEAR(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_PORT_FEATURE_FLAG_10MB_FD_TEST(flags, OF_VERSION_1_0));
    value = OF_PORT_FEATURE_FLAG_100MB_HD;
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_100MB_HD_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_100MB_HD_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_100MB_HD_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_100MB_HD_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_100MB_HD_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_PORT_FEATURE_FLAG_100MB_HD_SET(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == OF_PORT_FEATURE_FLAG_100MB_HD_BY_VERSION(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_100MB_HD_TEST(flags, OF_VERSION_1_0));
    OF_PORT_FEATURE_FLAG_100MB_HD_CLEAR(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_PORT_FEATURE_FLAG_100MB_HD_TEST(flags, OF_VERSION_1_0));
    value = OF_PORT_FEATURE_FLAG_100MB_FD;
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_100MB_FD_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_100MB_FD_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_100MB_FD_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_100MB_FD_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_100MB_FD_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_PORT_FEATURE_FLAG_100MB_FD_SET(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == OF_PORT_FEATURE_FLAG_100MB_FD_BY_VERSION(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_100MB_FD_TEST(flags, OF_VERSION_1_0));
    OF_PORT_FEATURE_FLAG_100MB_FD_CLEAR(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_PORT_FEATURE_FLAG_100MB_FD_TEST(flags, OF_VERSION_1_0));
    value = OF_PORT_FEATURE_FLAG_1GB_HD;
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_1GB_HD_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_1GB_HD_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_1GB_HD_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_1GB_HD_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_1GB_HD_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_PORT_FEATURE_FLAG_1GB_HD_SET(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == OF_PORT_FEATURE_FLAG_1GB_HD_BY_VERSION(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_1GB_HD_TEST(flags, OF_VERSION_1_0));
    OF_PORT_FEATURE_FLAG_1GB_HD_CLEAR(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_PORT_FEATURE_FLAG_1GB_HD_TEST(flags, OF_VERSION_1_0));
    value = OF_PORT_FEATURE_FLAG_1GB_FD;
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_1GB_FD_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_1GB_FD_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_1GB_FD_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_1GB_FD_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_1GB_FD_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_PORT_FEATURE_FLAG_1GB_FD_SET(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == OF_PORT_FEATURE_FLAG_1GB_FD_BY_VERSION(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_1GB_FD_TEST(flags, OF_VERSION_1_0));
    OF_PORT_FEATURE_FLAG_1GB_FD_CLEAR(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_PORT_FEATURE_FLAG_1GB_FD_TEST(flags, OF_VERSION_1_0));
    value = OF_PORT_FEATURE_FLAG_10GB_FD;
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_10GB_FD_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_10GB_FD_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_10GB_FD_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_10GB_FD_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_10GB_FD_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_PORT_FEATURE_FLAG_10GB_FD_SET(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == OF_PORT_FEATURE_FLAG_10GB_FD_BY_VERSION(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_10GB_FD_TEST(flags, OF_VERSION_1_0));
    OF_PORT_FEATURE_FLAG_10GB_FD_CLEAR(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_PORT_FEATURE_FLAG_10GB_FD_TEST(flags, OF_VERSION_1_0));
    value = OF_QUEUE_PROPERTY_NONE;
    TEST_ASSERT(OF_QUEUE_PROPERTY_NONE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_QUEUE_PROPERTY_NONE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_QUEUE_PROPERTY_NONE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_QUEUE_PROPERTY_NONE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_QUEUE_PROPERTY_NONE_SUPPORTED(OF_VERSION_1_4));
    value = OF_QUEUE_PROPERTY_MIN_RATE;
    TEST_ASSERT(OF_QUEUE_PROPERTY_MIN_RATE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_QUEUE_PROPERTY_MIN_RATE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_QUEUE_PROPERTY_MIN_RATE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_QUEUE_PROPERTY_MIN_RATE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_QUEUE_PROPERTY_MIN_RATE_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_WC_V1_IN_PORT;
    TEST_ASSERT(OF_FLOW_WC_V1_IN_PORT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_FLOW_WC_V1_IN_PORT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_FLOW_WC_V1_IN_PORT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_FLOW_WC_V1_IN_PORT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_FLOW_WC_V1_IN_PORT_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_WC_V1_DL_VLAN;
    TEST_ASSERT(OF_FLOW_WC_V1_DL_VLAN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_FLOW_WC_V1_DL_VLAN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_FLOW_WC_V1_DL_VLAN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_FLOW_WC_V1_DL_VLAN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_FLOW_WC_V1_DL_VLAN_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_WC_V1_DL_SRC;
    TEST_ASSERT(OF_FLOW_WC_V1_DL_SRC_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_FLOW_WC_V1_DL_SRC_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_FLOW_WC_V1_DL_SRC_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_FLOW_WC_V1_DL_SRC_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_FLOW_WC_V1_DL_SRC_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_WC_V1_NW_DST_BITS;
    TEST_ASSERT(OF_FLOW_WC_V1_NW_DST_BITS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_FLOW_WC_V1_NW_DST_BITS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_FLOW_WC_V1_NW_DST_BITS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_FLOW_WC_V1_NW_DST_BITS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_FLOW_WC_V1_NW_DST_BITS_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_WC_V1_NW_SRC_BITS;
    TEST_ASSERT(OF_FLOW_WC_V1_NW_SRC_BITS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_FLOW_WC_V1_NW_SRC_BITS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_FLOW_WC_V1_NW_SRC_BITS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_FLOW_WC_V1_NW_SRC_BITS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_FLOW_WC_V1_NW_SRC_BITS_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_WC_V1_NW_SRC_SHIFT;
    TEST_ASSERT(OF_FLOW_WC_V1_NW_SRC_SHIFT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_FLOW_WC_V1_NW_SRC_SHIFT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_FLOW_WC_V1_NW_SRC_SHIFT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_FLOW_WC_V1_NW_SRC_SHIFT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_FLOW_WC_V1_NW_SRC_SHIFT_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_WC_V1_DL_DST;
    TEST_ASSERT(OF_FLOW_WC_V1_DL_DST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_FLOW_WC_V1_DL_DST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_FLOW_WC_V1_DL_DST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_FLOW_WC_V1_DL_DST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_FLOW_WC_V1_DL_DST_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_WC_V1_NW_DST_SHIFT;
    TEST_ASSERT(OF_FLOW_WC_V1_NW_DST_SHIFT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_FLOW_WC_V1_NW_DST_SHIFT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_FLOW_WC_V1_NW_DST_SHIFT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_FLOW_WC_V1_NW_DST_SHIFT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_FLOW_WC_V1_NW_DST_SHIFT_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_WC_V1_NW_PROTO;
    TEST_ASSERT(OF_FLOW_WC_V1_NW_PROTO_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_FLOW_WC_V1_NW_PROTO_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_FLOW_WC_V1_NW_PROTO_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_FLOW_WC_V1_NW_PROTO_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_FLOW_WC_V1_NW_PROTO_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_WC_V1_TP_SRC;
    TEST_ASSERT(OF_FLOW_WC_V1_TP_SRC_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_FLOW_WC_V1_TP_SRC_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_FLOW_WC_V1_TP_SRC_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_FLOW_WC_V1_TP_SRC_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_FLOW_WC_V1_TP_SRC_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_WC_V1_TP_DST;
    TEST_ASSERT(OF_FLOW_WC_V1_TP_DST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_FLOW_WC_V1_TP_DST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_FLOW_WC_V1_TP_DST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_FLOW_WC_V1_TP_DST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_FLOW_WC_V1_TP_DST_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_WC_V1_NW_SRC_ALL;
    TEST_ASSERT(OF_FLOW_WC_V1_NW_SRC_ALL_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_FLOW_WC_V1_NW_SRC_ALL_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_FLOW_WC_V1_NW_SRC_ALL_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_FLOW_WC_V1_NW_SRC_ALL_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_FLOW_WC_V1_NW_SRC_ALL_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_WC_V1_NW_SRC_MASK;
    TEST_ASSERT(OF_FLOW_WC_V1_NW_SRC_MASK_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_FLOW_WC_V1_NW_SRC_MASK_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_FLOW_WC_V1_NW_SRC_MASK_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_FLOW_WC_V1_NW_SRC_MASK_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_FLOW_WC_V1_NW_SRC_MASK_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_WC_V1_NW_DST_ALL;
    TEST_ASSERT(OF_FLOW_WC_V1_NW_DST_ALL_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_FLOW_WC_V1_NW_DST_ALL_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_FLOW_WC_V1_NW_DST_ALL_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_FLOW_WC_V1_NW_DST_ALL_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_FLOW_WC_V1_NW_DST_ALL_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_WC_V1_NW_DST_MASK;
    TEST_ASSERT(OF_FLOW_WC_V1_NW_DST_MASK_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_FLOW_WC_V1_NW_DST_MASK_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_FLOW_WC_V1_NW_DST_MASK_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_FLOW_WC_V1_NW_DST_MASK_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_FLOW_WC_V1_NW_DST_MASK_SUPPORTED(OF_VERSION_1_4));
    value = OF_ACTION_TYPE_OUTPUT;
    TEST_ASSERT(OF_ACTION_TYPE_OUTPUT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ACTION_TYPE_OUTPUT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ACTION_TYPE_OUTPUT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ACTION_TYPE_OUTPUT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ACTION_TYPE_OUTPUT_SUPPORTED(OF_VERSION_1_4));
    value = OF_ACTION_TYPE_SET_VLAN_VID;
    TEST_ASSERT(OF_ACTION_TYPE_SET_VLAN_VID_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ACTION_TYPE_SET_VLAN_VID_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_ACTION_TYPE_SET_VLAN_VID_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_ACTION_TYPE_SET_VLAN_VID_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_ACTION_TYPE_SET_VLAN_VID_SUPPORTED(OF_VERSION_1_4));
    value = OF_ACTION_TYPE_SET_VLAN_PCP;
    TEST_ASSERT(OF_ACTION_TYPE_SET_VLAN_PCP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ACTION_TYPE_SET_VLAN_PCP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_ACTION_TYPE_SET_VLAN_PCP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_ACTION_TYPE_SET_VLAN_PCP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_ACTION_TYPE_SET_VLAN_PCP_SUPPORTED(OF_VERSION_1_4));
    value = OF_ACTION_TYPE_STRIP_VLAN;
    TEST_ASSERT(OF_ACTION_TYPE_STRIP_VLAN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_ACTION_TYPE_STRIP_VLAN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_ACTION_TYPE_STRIP_VLAN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_ACTION_TYPE_STRIP_VLAN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_ACTION_TYPE_STRIP_VLAN_SUPPORTED(OF_VERSION_1_4));
    value = OF_ACTION_TYPE_SET_TP_SRC;
    TEST_ASSERT(OF_ACTION_TYPE_SET_TP_SRC_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ACTION_TYPE_SET_TP_SRC_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_ACTION_TYPE_SET_TP_SRC_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_ACTION_TYPE_SET_TP_SRC_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_ACTION_TYPE_SET_TP_SRC_SUPPORTED(OF_VERSION_1_4));
    value = OF_ACTION_TYPE_SET_TP_DST;
    TEST_ASSERT(OF_ACTION_TYPE_SET_TP_DST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ACTION_TYPE_SET_TP_DST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_ACTION_TYPE_SET_TP_DST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_ACTION_TYPE_SET_TP_DST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_ACTION_TYPE_SET_TP_DST_SUPPORTED(OF_VERSION_1_4));
    value = OF_ACTION_TYPE_ENQUEUE;
    TEST_ASSERT(OF_ACTION_TYPE_ENQUEUE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_ACTION_TYPE_ENQUEUE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_ACTION_TYPE_ENQUEUE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_ACTION_TYPE_ENQUEUE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_ACTION_TYPE_ENQUEUE_SUPPORTED(OF_VERSION_1_4));
    value = OF_ACTION_TYPE_EXPERIMENTER;
    TEST_ASSERT(OF_ACTION_TYPE_EXPERIMENTER_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ACTION_TYPE_EXPERIMENTER_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ACTION_TYPE_EXPERIMENTER_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ACTION_TYPE_EXPERIMENTER_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ACTION_TYPE_EXPERIMENTER_SUPPORTED(OF_VERSION_1_4));
    value = OF_CAPABILITIES_FLAG_FLOW_STATS;
    TEST_ASSERT(OF_CAPABILITIES_FLAG_FLOW_STATS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_CAPABILITIES_FLAG_FLOW_STATS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_CAPABILITIES_FLAG_FLOW_STATS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_CAPABILITIES_FLAG_FLOW_STATS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_CAPABILITIES_FLAG_FLOW_STATS_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_CAPABILITIES_FLAG_FLOW_STATS_SET(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == OF_CAPABILITIES_FLAG_FLOW_STATS_BY_VERSION(OF_VERSION_1_0));
    TEST_ASSERT(OF_CAPABILITIES_FLAG_FLOW_STATS_TEST(flags, OF_VERSION_1_0));
    OF_CAPABILITIES_FLAG_FLOW_STATS_CLEAR(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_CAPABILITIES_FLAG_FLOW_STATS_TEST(flags, OF_VERSION_1_0));
    value = OF_CAPABILITIES_FLAG_TABLE_STATS;
    TEST_ASSERT(OF_CAPABILITIES_FLAG_TABLE_STATS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_CAPABILITIES_FLAG_TABLE_STATS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_CAPABILITIES_FLAG_TABLE_STATS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_CAPABILITIES_FLAG_TABLE_STATS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_CAPABILITIES_FLAG_TABLE_STATS_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_CAPABILITIES_FLAG_TABLE_STATS_SET(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == OF_CAPABILITIES_FLAG_TABLE_STATS_BY_VERSION(OF_VERSION_1_0));
    TEST_ASSERT(OF_CAPABILITIES_FLAG_TABLE_STATS_TEST(flags, OF_VERSION_1_0));
    OF_CAPABILITIES_FLAG_TABLE_STATS_CLEAR(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_CAPABILITIES_FLAG_TABLE_STATS_TEST(flags, OF_VERSION_1_0));
    value = OF_CAPABILITIES_FLAG_PORT_STATS;
    TEST_ASSERT(OF_CAPABILITIES_FLAG_PORT_STATS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_CAPABILITIES_FLAG_PORT_STATS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_CAPABILITIES_FLAG_PORT_STATS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_CAPABILITIES_FLAG_PORT_STATS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_CAPABILITIES_FLAG_PORT_STATS_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_CAPABILITIES_FLAG_PORT_STATS_SET(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == OF_CAPABILITIES_FLAG_PORT_STATS_BY_VERSION(OF_VERSION_1_0));
    TEST_ASSERT(OF_CAPABILITIES_FLAG_PORT_STATS_TEST(flags, OF_VERSION_1_0));
    OF_CAPABILITIES_FLAG_PORT_STATS_CLEAR(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_CAPABILITIES_FLAG_PORT_STATS_TEST(flags, OF_VERSION_1_0));
    value = OF_CAPABILITIES_FLAG_STP;
    TEST_ASSERT(OF_CAPABILITIES_FLAG_STP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_CAPABILITIES_FLAG_STP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_CAPABILITIES_FLAG_STP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_CAPABILITIES_FLAG_STP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_CAPABILITIES_FLAG_STP_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_CAPABILITIES_FLAG_STP_SET(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == OF_CAPABILITIES_FLAG_STP_BY_VERSION(OF_VERSION_1_0));
    TEST_ASSERT(OF_CAPABILITIES_FLAG_STP_TEST(flags, OF_VERSION_1_0));
    OF_CAPABILITIES_FLAG_STP_CLEAR(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_CAPABILITIES_FLAG_STP_TEST(flags, OF_VERSION_1_0));
    value = OF_CAPABILITIES_FLAG_RESERVED;
    TEST_ASSERT(OF_CAPABILITIES_FLAG_RESERVED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_CAPABILITIES_FLAG_RESERVED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_CAPABILITIES_FLAG_RESERVED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_CAPABILITIES_FLAG_RESERVED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_CAPABILITIES_FLAG_RESERVED_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_CAPABILITIES_FLAG_RESERVED_SET(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == OF_CAPABILITIES_FLAG_RESERVED_BY_VERSION(OF_VERSION_1_0));
    TEST_ASSERT(OF_CAPABILITIES_FLAG_RESERVED_TEST(flags, OF_VERSION_1_0));
    OF_CAPABILITIES_FLAG_RESERVED_CLEAR(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_CAPABILITIES_FLAG_RESERVED_TEST(flags, OF_VERSION_1_0));
    value = OF_CAPABILITIES_FLAG_IP_REASM;
    TEST_ASSERT(OF_CAPABILITIES_FLAG_IP_REASM_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_CAPABILITIES_FLAG_IP_REASM_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_CAPABILITIES_FLAG_IP_REASM_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_CAPABILITIES_FLAG_IP_REASM_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_CAPABILITIES_FLAG_IP_REASM_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_CAPABILITIES_FLAG_IP_REASM_SET(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == OF_CAPABILITIES_FLAG_IP_REASM_BY_VERSION(OF_VERSION_1_0));
    TEST_ASSERT(OF_CAPABILITIES_FLAG_IP_REASM_TEST(flags, OF_VERSION_1_0));
    OF_CAPABILITIES_FLAG_IP_REASM_CLEAR(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_CAPABILITIES_FLAG_IP_REASM_TEST(flags, OF_VERSION_1_0));
    value = OF_CAPABILITIES_FLAG_QUEUE_STATS;
    TEST_ASSERT(OF_CAPABILITIES_FLAG_QUEUE_STATS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_CAPABILITIES_FLAG_QUEUE_STATS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_CAPABILITIES_FLAG_QUEUE_STATS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_CAPABILITIES_FLAG_QUEUE_STATS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_CAPABILITIES_FLAG_QUEUE_STATS_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_CAPABILITIES_FLAG_QUEUE_STATS_SET(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == OF_CAPABILITIES_FLAG_QUEUE_STATS_BY_VERSION(OF_VERSION_1_0));
    TEST_ASSERT(OF_CAPABILITIES_FLAG_QUEUE_STATS_TEST(flags, OF_VERSION_1_0));
    OF_CAPABILITIES_FLAG_QUEUE_STATS_CLEAR(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_CAPABILITIES_FLAG_QUEUE_STATS_TEST(flags, OF_VERSION_1_0));
    value = OF_CAPABILITIES_FLAG_ARP_MATCH_IP;
    TEST_ASSERT(OF_CAPABILITIES_FLAG_ARP_MATCH_IP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_CAPABILITIES_FLAG_ARP_MATCH_IP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_CAPABILITIES_FLAG_ARP_MATCH_IP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_CAPABILITIES_FLAG_ARP_MATCH_IP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_CAPABILITIES_FLAG_ARP_MATCH_IP_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_CAPABILITIES_FLAG_ARP_MATCH_IP_SET(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == OF_CAPABILITIES_FLAG_ARP_MATCH_IP_BY_VERSION(OF_VERSION_1_0));
    TEST_ASSERT(OF_CAPABILITIES_FLAG_ARP_MATCH_IP_TEST(flags, OF_VERSION_1_0));
    OF_CAPABILITIES_FLAG_ARP_MATCH_IP_CLEAR(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_CAPABILITIES_FLAG_ARP_MATCH_IP_TEST(flags, OF_VERSION_1_0));
    value = OF_CONFIG_FRAG_NORMAL;
    TEST_ASSERT(OF_CONFIG_FRAG_NORMAL_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_CONFIG_FRAG_NORMAL_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_CONFIG_FRAG_NORMAL_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_CONFIG_FRAG_NORMAL_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_CONFIG_FRAG_NORMAL_SUPPORTED(OF_VERSION_1_4));
    value = OF_CONFIG_FRAG_DROP;
    TEST_ASSERT(OF_CONFIG_FRAG_DROP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_CONFIG_FRAG_DROP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_CONFIG_FRAG_DROP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_CONFIG_FRAG_DROP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_CONFIG_FRAG_DROP_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_CONFIG_FRAG_DROP_SET(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == OF_CONFIG_FRAG_DROP_BY_VERSION(OF_VERSION_1_0));
    TEST_ASSERT(OF_CONFIG_FRAG_DROP_TEST(flags, OF_VERSION_1_0));
    OF_CONFIG_FRAG_DROP_CLEAR(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_CONFIG_FRAG_DROP_TEST(flags, OF_VERSION_1_0));
    value = OF_CONFIG_FRAG_REASM;
    TEST_ASSERT(OF_CONFIG_FRAG_REASM_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_CONFIG_FRAG_REASM_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_CONFIG_FRAG_REASM_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_CONFIG_FRAG_REASM_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_CONFIG_FRAG_REASM_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_CONFIG_FRAG_REASM_SET(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == OF_CONFIG_FRAG_REASM_BY_VERSION(OF_VERSION_1_0));
    TEST_ASSERT(OF_CONFIG_FRAG_REASM_TEST(flags, OF_VERSION_1_0));
    OF_CONFIG_FRAG_REASM_CLEAR(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_CONFIG_FRAG_REASM_TEST(flags, OF_VERSION_1_0));
    value = OF_CONFIG_FRAG_MASK;
    TEST_ASSERT(OF_CONFIG_FRAG_MASK_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_CONFIG_FRAG_MASK_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_CONFIG_FRAG_MASK_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_CONFIG_FRAG_MASK_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_CONFIG_FRAG_MASK_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_CONFIG_FRAG_MASK_SET(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == OF_CONFIG_FRAG_MASK_BY_VERSION(OF_VERSION_1_0));
    TEST_ASSERT(OF_CONFIG_FRAG_MASK_TEST(flags, OF_VERSION_1_0));
    OF_CONFIG_FRAG_MASK_CLEAR(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_CONFIG_FRAG_MASK_TEST(flags, OF_VERSION_1_0));
    value = OF_FLOW_MOD_COMMAND_ADD;
    TEST_ASSERT(OF_FLOW_MOD_COMMAND_ADD_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_FLOW_MOD_COMMAND_ADD_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_FLOW_MOD_COMMAND_ADD_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_FLOW_MOD_COMMAND_ADD_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_FLOW_MOD_COMMAND_ADD_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_MOD_COMMAND_MODIFY;
    TEST_ASSERT(OF_FLOW_MOD_COMMAND_MODIFY_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_FLOW_MOD_COMMAND_MODIFY_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_FLOW_MOD_COMMAND_MODIFY_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_FLOW_MOD_COMMAND_MODIFY_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_FLOW_MOD_COMMAND_MODIFY_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_MOD_COMMAND_MODIFY_STRICT;
    TEST_ASSERT(OF_FLOW_MOD_COMMAND_MODIFY_STRICT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_FLOW_MOD_COMMAND_MODIFY_STRICT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_FLOW_MOD_COMMAND_MODIFY_STRICT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_FLOW_MOD_COMMAND_MODIFY_STRICT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_FLOW_MOD_COMMAND_MODIFY_STRICT_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_MOD_COMMAND_DELETE;
    TEST_ASSERT(OF_FLOW_MOD_COMMAND_DELETE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_FLOW_MOD_COMMAND_DELETE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_FLOW_MOD_COMMAND_DELETE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_FLOW_MOD_COMMAND_DELETE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_FLOW_MOD_COMMAND_DELETE_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_MOD_COMMAND_DELETE_STRICT;
    TEST_ASSERT(OF_FLOW_MOD_COMMAND_DELETE_STRICT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_FLOW_MOD_COMMAND_DELETE_STRICT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_FLOW_MOD_COMMAND_DELETE_STRICT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_FLOW_MOD_COMMAND_DELETE_STRICT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_FLOW_MOD_COMMAND_DELETE_STRICT_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_MOD_FLAG_SEND_FLOW_REM;
    TEST_ASSERT(OF_FLOW_MOD_FLAG_SEND_FLOW_REM_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_FLOW_MOD_FLAG_SEND_FLOW_REM_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_FLOW_MOD_FLAG_SEND_FLOW_REM_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_FLOW_MOD_FLAG_SEND_FLOW_REM_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_FLOW_MOD_FLAG_SEND_FLOW_REM_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_FLOW_MOD_FLAG_SEND_FLOW_REM_SET(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == OF_FLOW_MOD_FLAG_SEND_FLOW_REM_BY_VERSION(OF_VERSION_1_0));
    TEST_ASSERT(OF_FLOW_MOD_FLAG_SEND_FLOW_REM_TEST(flags, OF_VERSION_1_0));
    OF_FLOW_MOD_FLAG_SEND_FLOW_REM_CLEAR(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_FLOW_MOD_FLAG_SEND_FLOW_REM_TEST(flags, OF_VERSION_1_0));
    value = OF_FLOW_MOD_FLAG_CHECK_OVERLAP;
    TEST_ASSERT(OF_FLOW_MOD_FLAG_CHECK_OVERLAP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_FLOW_MOD_FLAG_CHECK_OVERLAP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_FLOW_MOD_FLAG_CHECK_OVERLAP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_FLOW_MOD_FLAG_CHECK_OVERLAP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_FLOW_MOD_FLAG_CHECK_OVERLAP_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_FLOW_MOD_FLAG_CHECK_OVERLAP_SET(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == OF_FLOW_MOD_FLAG_CHECK_OVERLAP_BY_VERSION(OF_VERSION_1_0));
    TEST_ASSERT(OF_FLOW_MOD_FLAG_CHECK_OVERLAP_TEST(flags, OF_VERSION_1_0));
    OF_FLOW_MOD_FLAG_CHECK_OVERLAP_CLEAR(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_FLOW_MOD_FLAG_CHECK_OVERLAP_TEST(flags, OF_VERSION_1_0));
    value = OF_FLOW_MOD_FLAG_EMERG;
    TEST_ASSERT(OF_FLOW_MOD_FLAG_EMERG_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_FLOW_MOD_FLAG_EMERG_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_FLOW_MOD_FLAG_EMERG_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_FLOW_MOD_FLAG_EMERG_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_FLOW_MOD_FLAG_EMERG_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_FLOW_MOD_FLAG_EMERG_SET(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == OF_FLOW_MOD_FLAG_EMERG_BY_VERSION(OF_VERSION_1_0));
    TEST_ASSERT(OF_FLOW_MOD_FLAG_EMERG_TEST(flags, OF_VERSION_1_0));
    OF_FLOW_MOD_FLAG_EMERG_CLEAR(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_FLOW_MOD_FLAG_EMERG_TEST(flags, OF_VERSION_1_0));
    value = OF_STATS_REPLY_FLAG_REPLY_MORE;
    TEST_ASSERT(OF_STATS_REPLY_FLAG_REPLY_MORE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_STATS_REPLY_FLAG_REPLY_MORE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_STATS_REPLY_FLAG_REPLY_MORE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_STATS_REPLY_FLAG_REPLY_MORE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_STATS_REPLY_FLAG_REPLY_MORE_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_STATS_REPLY_FLAG_REPLY_MORE_SET(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == OF_STATS_REPLY_FLAG_REPLY_MORE_BY_VERSION(OF_VERSION_1_0));
    TEST_ASSERT(OF_STATS_REPLY_FLAG_REPLY_MORE_TEST(flags, OF_VERSION_1_0));
    OF_STATS_REPLY_FLAG_REPLY_MORE_CLEAR(flags, OF_VERSION_1_0);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_STATS_REPLY_FLAG_REPLY_MORE_TEST(flags, OF_VERSION_1_0));
    value = OF_STATS_TYPE_DESC;
    TEST_ASSERT(OF_STATS_TYPE_DESC_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_STATS_TYPE_DESC_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_STATS_TYPE_DESC_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_STATS_TYPE_DESC_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_STATS_TYPE_DESC_SUPPORTED(OF_VERSION_1_4));
    value = OF_STATS_TYPE_FLOW;
    TEST_ASSERT(OF_STATS_TYPE_FLOW_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_STATS_TYPE_FLOW_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_STATS_TYPE_FLOW_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_STATS_TYPE_FLOW_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_STATS_TYPE_FLOW_SUPPORTED(OF_VERSION_1_4));
    value = OF_STATS_TYPE_AGGREGATE;
    TEST_ASSERT(OF_STATS_TYPE_AGGREGATE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_STATS_TYPE_AGGREGATE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_STATS_TYPE_AGGREGATE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_STATS_TYPE_AGGREGATE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_STATS_TYPE_AGGREGATE_SUPPORTED(OF_VERSION_1_4));
    value = OF_STATS_TYPE_TABLE;
    TEST_ASSERT(OF_STATS_TYPE_TABLE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_STATS_TYPE_TABLE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_STATS_TYPE_TABLE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_STATS_TYPE_TABLE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_STATS_TYPE_TABLE_SUPPORTED(OF_VERSION_1_4));
    value = OF_STATS_TYPE_PORT;
    TEST_ASSERT(OF_STATS_TYPE_PORT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_STATS_TYPE_PORT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_STATS_TYPE_PORT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_STATS_TYPE_PORT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_STATS_TYPE_PORT_SUPPORTED(OF_VERSION_1_4));
    value = OF_STATS_TYPE_QUEUE;
    TEST_ASSERT(OF_STATS_TYPE_QUEUE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_STATS_TYPE_QUEUE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_STATS_TYPE_QUEUE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_STATS_TYPE_QUEUE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_STATS_TYPE_QUEUE_SUPPORTED(OF_VERSION_1_4));
    value = OF_STATS_TYPE_EXPERIMENTER;
    TEST_ASSERT(OF_STATS_TYPE_EXPERIMENTER_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_STATS_TYPE_EXPERIMENTER_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_STATS_TYPE_EXPERIMENTER_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_STATS_TYPE_EXPERIMENTER_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_STATS_TYPE_EXPERIMENTER_SUPPORTED(OF_VERSION_1_4));
    value = OF_PACKET_IN_REASON_NO_MATCH;
    TEST_ASSERT(OF_PACKET_IN_REASON_NO_MATCH_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_PACKET_IN_REASON_NO_MATCH_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_PACKET_IN_REASON_NO_MATCH_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PACKET_IN_REASON_NO_MATCH_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PACKET_IN_REASON_NO_MATCH_SUPPORTED(OF_VERSION_1_4));
    value = OF_PACKET_IN_REASON_ACTION;
    TEST_ASSERT(OF_PACKET_IN_REASON_ACTION_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_PACKET_IN_REASON_ACTION_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_PACKET_IN_REASON_ACTION_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PACKET_IN_REASON_ACTION_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PACKET_IN_REASON_ACTION_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_REMOVED_REASON_IDLE_TIMEOUT;
    TEST_ASSERT(OF_FLOW_REMOVED_REASON_IDLE_TIMEOUT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_FLOW_REMOVED_REASON_IDLE_TIMEOUT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_FLOW_REMOVED_REASON_IDLE_TIMEOUT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_FLOW_REMOVED_REASON_IDLE_TIMEOUT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_FLOW_REMOVED_REASON_IDLE_TIMEOUT_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_REMOVED_REASON_HARD_TIMEOUT;
    TEST_ASSERT(OF_FLOW_REMOVED_REASON_HARD_TIMEOUT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_FLOW_REMOVED_REASON_HARD_TIMEOUT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_FLOW_REMOVED_REASON_HARD_TIMEOUT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_FLOW_REMOVED_REASON_HARD_TIMEOUT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_FLOW_REMOVED_REASON_HARD_TIMEOUT_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_REMOVED_REASON_DELETE;
    TEST_ASSERT(OF_FLOW_REMOVED_REASON_DELETE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_FLOW_REMOVED_REASON_DELETE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_FLOW_REMOVED_REASON_DELETE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_FLOW_REMOVED_REASON_DELETE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_FLOW_REMOVED_REASON_DELETE_SUPPORTED(OF_VERSION_1_4));
    value = OF_PORT_CHANGE_REASON_ADD;
    TEST_ASSERT(OF_PORT_CHANGE_REASON_ADD_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_CHANGE_REASON_ADD_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_PORT_CHANGE_REASON_ADD_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PORT_CHANGE_REASON_ADD_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PORT_CHANGE_REASON_ADD_SUPPORTED(OF_VERSION_1_4));
    value = OF_PORT_CHANGE_REASON_DELETE;
    TEST_ASSERT(OF_PORT_CHANGE_REASON_DELETE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_CHANGE_REASON_DELETE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_PORT_CHANGE_REASON_DELETE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PORT_CHANGE_REASON_DELETE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PORT_CHANGE_REASON_DELETE_SUPPORTED(OF_VERSION_1_4));
    value = OF_PORT_CHANGE_REASON_MODIFY;
    TEST_ASSERT(OF_PORT_CHANGE_REASON_MODIFY_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_CHANGE_REASON_MODIFY_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_PORT_CHANGE_REASON_MODIFY_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PORT_CHANGE_REASON_MODIFY_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PORT_CHANGE_REASON_MODIFY_SUPPORTED(OF_VERSION_1_4));
    value = OF_ERROR_TYPE_HELLO_FAILED;
    TEST_ASSERT(OF_ERROR_TYPE_HELLO_FAILED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ERROR_TYPE_HELLO_FAILED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ERROR_TYPE_HELLO_FAILED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ERROR_TYPE_HELLO_FAILED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ERROR_TYPE_HELLO_FAILED_SUPPORTED(OF_VERSION_1_4));
    value = OF_ERROR_TYPE_BAD_REQUEST;
    TEST_ASSERT(OF_ERROR_TYPE_BAD_REQUEST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ERROR_TYPE_BAD_REQUEST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ERROR_TYPE_BAD_REQUEST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ERROR_TYPE_BAD_REQUEST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ERROR_TYPE_BAD_REQUEST_SUPPORTED(OF_VERSION_1_4));
    value = OF_ERROR_TYPE_BAD_ACTION;
    TEST_ASSERT(OF_ERROR_TYPE_BAD_ACTION_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ERROR_TYPE_BAD_ACTION_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ERROR_TYPE_BAD_ACTION_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ERROR_TYPE_BAD_ACTION_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ERROR_TYPE_BAD_ACTION_SUPPORTED(OF_VERSION_1_4));
    value = OF_HELLO_FAILED_INCOMPATIBLE;
    TEST_ASSERT(OF_HELLO_FAILED_INCOMPATIBLE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_HELLO_FAILED_INCOMPATIBLE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_HELLO_FAILED_INCOMPATIBLE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_HELLO_FAILED_INCOMPATIBLE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_HELLO_FAILED_INCOMPATIBLE_SUPPORTED(OF_VERSION_1_4));
    value = OF_HELLO_FAILED_EPERM;
    TEST_ASSERT(OF_HELLO_FAILED_EPERM_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_HELLO_FAILED_EPERM_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_HELLO_FAILED_EPERM_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_HELLO_FAILED_EPERM_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_HELLO_FAILED_EPERM_SUPPORTED(OF_VERSION_1_4));
    value = OF_REQUEST_FAILED_BAD_VERSION;
    TEST_ASSERT(OF_REQUEST_FAILED_BAD_VERSION_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_REQUEST_FAILED_BAD_VERSION_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_REQUEST_FAILED_BAD_VERSION_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_REQUEST_FAILED_BAD_VERSION_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_REQUEST_FAILED_BAD_VERSION_SUPPORTED(OF_VERSION_1_4));
    value = OF_REQUEST_FAILED_BAD_TYPE;
    TEST_ASSERT(OF_REQUEST_FAILED_BAD_TYPE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_REQUEST_FAILED_BAD_TYPE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_REQUEST_FAILED_BAD_TYPE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_REQUEST_FAILED_BAD_TYPE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_REQUEST_FAILED_BAD_TYPE_SUPPORTED(OF_VERSION_1_4));
    value = OF_REQUEST_FAILED_BAD_STAT;
    TEST_ASSERT(OF_REQUEST_FAILED_BAD_STAT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_REQUEST_FAILED_BAD_STAT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_REQUEST_FAILED_BAD_STAT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_REQUEST_FAILED_BAD_STAT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_REQUEST_FAILED_BAD_STAT_SUPPORTED(OF_VERSION_1_4));
    value = OF_REQUEST_FAILED_BAD_EXPERIMENTER;
    TEST_ASSERT(OF_REQUEST_FAILED_BAD_EXPERIMENTER_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_REQUEST_FAILED_BAD_EXPERIMENTER_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_REQUEST_FAILED_BAD_EXPERIMENTER_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_REQUEST_FAILED_BAD_EXPERIMENTER_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_REQUEST_FAILED_BAD_EXPERIMENTER_SUPPORTED(OF_VERSION_1_4));
    value = OF_REQUEST_FAILED_BAD_SUBTYPE;
    TEST_ASSERT(OF_REQUEST_FAILED_BAD_SUBTYPE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_REQUEST_FAILED_BAD_SUBTYPE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_REQUEST_FAILED_BAD_SUBTYPE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_REQUEST_FAILED_BAD_SUBTYPE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_REQUEST_FAILED_BAD_SUBTYPE_SUPPORTED(OF_VERSION_1_4));
    value = OF_REQUEST_FAILED_EPERM;
    TEST_ASSERT(OF_REQUEST_FAILED_EPERM_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_REQUEST_FAILED_EPERM_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_REQUEST_FAILED_EPERM_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_REQUEST_FAILED_EPERM_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_REQUEST_FAILED_EPERM_SUPPORTED(OF_VERSION_1_4));
    value = OF_REQUEST_FAILED_BAD_LEN;
    TEST_ASSERT(OF_REQUEST_FAILED_BAD_LEN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_REQUEST_FAILED_BAD_LEN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_REQUEST_FAILED_BAD_LEN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_REQUEST_FAILED_BAD_LEN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_REQUEST_FAILED_BAD_LEN_SUPPORTED(OF_VERSION_1_4));
    value = OF_REQUEST_FAILED_BUFFER_EMPTY;
    TEST_ASSERT(OF_REQUEST_FAILED_BUFFER_EMPTY_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_REQUEST_FAILED_BUFFER_EMPTY_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_REQUEST_FAILED_BUFFER_EMPTY_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_REQUEST_FAILED_BUFFER_EMPTY_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_REQUEST_FAILED_BUFFER_EMPTY_SUPPORTED(OF_VERSION_1_4));
    value = OF_REQUEST_FAILED_BUFFER_UNKNOWN;
    TEST_ASSERT(OF_REQUEST_FAILED_BUFFER_UNKNOWN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_REQUEST_FAILED_BUFFER_UNKNOWN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_REQUEST_FAILED_BUFFER_UNKNOWN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_REQUEST_FAILED_BUFFER_UNKNOWN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_REQUEST_FAILED_BUFFER_UNKNOWN_SUPPORTED(OF_VERSION_1_4));
    value = OF_ACTION_FAILED_BAD_TYPE;
    TEST_ASSERT(OF_ACTION_FAILED_BAD_TYPE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_TYPE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_TYPE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_TYPE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_TYPE_SUPPORTED(OF_VERSION_1_4));
    value = OF_ACTION_FAILED_BAD_LEN;
    TEST_ASSERT(OF_ACTION_FAILED_BAD_LEN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_LEN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_LEN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_LEN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_LEN_SUPPORTED(OF_VERSION_1_4));
    value = OF_ACTION_FAILED_BAD_EXPERIMENTER;
    TEST_ASSERT(OF_ACTION_FAILED_BAD_EXPERIMENTER_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_EXPERIMENTER_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_EXPERIMENTER_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_EXPERIMENTER_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_EXPERIMENTER_SUPPORTED(OF_VERSION_1_4));
    value = OF_ACTION_FAILED_BAD_EXPERIMENTER_TYPE;
    TEST_ASSERT(OF_ACTION_FAILED_BAD_EXPERIMENTER_TYPE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_EXPERIMENTER_TYPE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_EXPERIMENTER_TYPE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_EXPERIMENTER_TYPE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_EXPERIMENTER_TYPE_SUPPORTED(OF_VERSION_1_4));
    value = OF_ACTION_FAILED_BAD_OUT_PORT;
    TEST_ASSERT(OF_ACTION_FAILED_BAD_OUT_PORT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_OUT_PORT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_OUT_PORT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_OUT_PORT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_OUT_PORT_SUPPORTED(OF_VERSION_1_4));
    value = OF_ACTION_FAILED_BAD_ARGUMENT;
    TEST_ASSERT(OF_ACTION_FAILED_BAD_ARGUMENT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_ARGUMENT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_ARGUMENT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_ARGUMENT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_ARGUMENT_SUPPORTED(OF_VERSION_1_4));
    value = OF_ACTION_FAILED_EPERM;
    TEST_ASSERT(OF_ACTION_FAILED_EPERM_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ACTION_FAILED_EPERM_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ACTION_FAILED_EPERM_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ACTION_FAILED_EPERM_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ACTION_FAILED_EPERM_SUPPORTED(OF_VERSION_1_4));
    value = OF_ACTION_FAILED_TOO_MANY;
    TEST_ASSERT(OF_ACTION_FAILED_TOO_MANY_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ACTION_FAILED_TOO_MANY_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ACTION_FAILED_TOO_MANY_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ACTION_FAILED_TOO_MANY_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ACTION_FAILED_TOO_MANY_SUPPORTED(OF_VERSION_1_4));
    value = OF_ACTION_FAILED_BAD_QUEUE;
    TEST_ASSERT(OF_ACTION_FAILED_BAD_QUEUE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_QUEUE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_QUEUE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_QUEUE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_QUEUE_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_MOD_FAILED_ALL_TABLES_FULL;
    TEST_ASSERT(OF_FLOW_MOD_FAILED_ALL_TABLES_FULL_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_FLOW_MOD_FAILED_ALL_TABLES_FULL_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_FLOW_MOD_FAILED_ALL_TABLES_FULL_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_FLOW_MOD_FAILED_ALL_TABLES_FULL_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_FLOW_MOD_FAILED_ALL_TABLES_FULL_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_MOD_FAILED_BAD_EMERG_TIMEOUT;
    TEST_ASSERT(OF_FLOW_MOD_FAILED_BAD_EMERG_TIMEOUT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_FLOW_MOD_FAILED_BAD_EMERG_TIMEOUT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_FLOW_MOD_FAILED_BAD_EMERG_TIMEOUT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_FLOW_MOD_FAILED_BAD_EMERG_TIMEOUT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_FLOW_MOD_FAILED_BAD_EMERG_TIMEOUT_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_MOD_FAILED_UNSUPPORTED;
    TEST_ASSERT(OF_FLOW_MOD_FAILED_UNSUPPORTED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_FLOW_MOD_FAILED_UNSUPPORTED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_FLOW_MOD_FAILED_UNSUPPORTED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_FLOW_MOD_FAILED_UNSUPPORTED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_FLOW_MOD_FAILED_UNSUPPORTED_SUPPORTED(OF_VERSION_1_4));
    value = OF_PORT_MOD_FAILED_BAD_PORT;
    TEST_ASSERT(OF_PORT_MOD_FAILED_BAD_PORT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_MOD_FAILED_BAD_PORT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_PORT_MOD_FAILED_BAD_PORT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PORT_MOD_FAILED_BAD_PORT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PORT_MOD_FAILED_BAD_PORT_SUPPORTED(OF_VERSION_1_4));
    value = OF_PORT_MOD_FAILED_BAD_HW_ADDR;
    TEST_ASSERT(OF_PORT_MOD_FAILED_BAD_HW_ADDR_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_MOD_FAILED_BAD_HW_ADDR_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_PORT_MOD_FAILED_BAD_HW_ADDR_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PORT_MOD_FAILED_BAD_HW_ADDR_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PORT_MOD_FAILED_BAD_HW_ADDR_SUPPORTED(OF_VERSION_1_4));
    value = OF_QUEUE_OP_FAILED_BAD_PORT;
    TEST_ASSERT(OF_QUEUE_OP_FAILED_BAD_PORT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_QUEUE_OP_FAILED_BAD_PORT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_QUEUE_OP_FAILED_BAD_PORT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_QUEUE_OP_FAILED_BAD_PORT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_QUEUE_OP_FAILED_BAD_PORT_SUPPORTED(OF_VERSION_1_4));
    value = OF_QUEUE_OP_FAILED_BAD_QUEUE;
    TEST_ASSERT(OF_QUEUE_OP_FAILED_BAD_QUEUE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_QUEUE_OP_FAILED_BAD_QUEUE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_QUEUE_OP_FAILED_BAD_QUEUE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_QUEUE_OP_FAILED_BAD_QUEUE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_QUEUE_OP_FAILED_BAD_QUEUE_SUPPORTED(OF_VERSION_1_4));
    value = OF_QUEUE_OP_FAILED_EPERM;
    TEST_ASSERT(OF_QUEUE_OP_FAILED_EPERM_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_QUEUE_OP_FAILED_EPERM_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_QUEUE_OP_FAILED_EPERM_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_QUEUE_OP_FAILED_EPERM_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_QUEUE_OP_FAILED_EPERM_SUPPORTED(OF_VERSION_1_4));
    value = OF_MATCH_TYPE_STANDARD_LENGTH;
    TEST_ASSERT(!OF_MATCH_TYPE_STANDARD_LENGTH_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_MATCH_TYPE_STANDARD_LENGTH_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_MATCH_TYPE_STANDARD_LENGTH_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_MATCH_TYPE_STANDARD_LENGTH_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_MATCH_TYPE_STANDARD_LENGTH_SUPPORTED(OF_VERSION_1_4));
    value = OF_PORT_DEST_WILDCARD;
    TEST_ASSERT(!OF_PORT_DEST_WILDCARD_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_DEST_WILDCARD_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_PORT_DEST_WILDCARD_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PORT_DEST_WILDCARD_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PORT_DEST_WILDCARD_SUPPORTED(OF_VERSION_1_4));
    value = OF_OBJ_TYPE_GROUP_MOD;
    TEST_ASSERT(!OF_OBJ_TYPE_GROUP_MOD_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_OBJ_TYPE_GROUP_MOD_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_OBJ_TYPE_GROUP_MOD_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_OBJ_TYPE_GROUP_MOD_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_OBJ_TYPE_GROUP_MOD_SUPPORTED(OF_VERSION_1_4));
    value = OF_OBJ_TYPE_TABLE_MOD;
    TEST_ASSERT(!OF_OBJ_TYPE_TABLE_MOD_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_OBJ_TYPE_TABLE_MOD_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_OBJ_TYPE_TABLE_MOD_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_OBJ_TYPE_TABLE_MOD_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_OBJ_TYPE_TABLE_MOD_SUPPORTED(OF_VERSION_1_4));
    value = OF_CONFIG_INVALID_TTL_TO_CONTROLLER;
    TEST_ASSERT(!OF_CONFIG_INVALID_TTL_TO_CONTROLLER_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_CONFIG_INVALID_TTL_TO_CONTROLLER_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_CONFIG_INVALID_TTL_TO_CONTROLLER_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_CONFIG_INVALID_TTL_TO_CONTROLLER_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_CONFIG_INVALID_TTL_TO_CONTROLLER_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_CONFIG_INVALID_TTL_TO_CONTROLLER_SET(flags, OF_VERSION_1_1);
    TEST_ASSERT(flags == OF_CONFIG_INVALID_TTL_TO_CONTROLLER_BY_VERSION(OF_VERSION_1_1));
    TEST_ASSERT(OF_CONFIG_INVALID_TTL_TO_CONTROLLER_TEST(flags, OF_VERSION_1_1));
    OF_CONFIG_INVALID_TTL_TO_CONTROLLER_CLEAR(flags, OF_VERSION_1_1);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_CONFIG_INVALID_TTL_TO_CONTROLLER_TEST(flags, OF_VERSION_1_1));
    value = OF_TABLE_CONFIG_TABLE_MISS_CONTROLLER;
    TEST_ASSERT(!OF_TABLE_CONFIG_TABLE_MISS_CONTROLLER_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_TABLE_CONFIG_TABLE_MISS_CONTROLLER_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_TABLE_CONFIG_TABLE_MISS_CONTROLLER_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_TABLE_CONFIG_TABLE_MISS_CONTROLLER_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_TABLE_CONFIG_TABLE_MISS_CONTROLLER_SUPPORTED(OF_VERSION_1_4));
    value = OF_TABLE_CONFIG_TABLE_MISS_CONTINUE;
    TEST_ASSERT(!OF_TABLE_CONFIG_TABLE_MISS_CONTINUE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_TABLE_CONFIG_TABLE_MISS_CONTINUE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_TABLE_CONFIG_TABLE_MISS_CONTINUE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_TABLE_CONFIG_TABLE_MISS_CONTINUE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_TABLE_CONFIG_TABLE_MISS_CONTINUE_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_TABLE_CONFIG_TABLE_MISS_CONTINUE_SET(flags, OF_VERSION_1_1);
    TEST_ASSERT(flags == OF_TABLE_CONFIG_TABLE_MISS_CONTINUE_BY_VERSION(OF_VERSION_1_1));
    TEST_ASSERT(OF_TABLE_CONFIG_TABLE_MISS_CONTINUE_TEST(flags, OF_VERSION_1_1));
    OF_TABLE_CONFIG_TABLE_MISS_CONTINUE_CLEAR(flags, OF_VERSION_1_1);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_TABLE_CONFIG_TABLE_MISS_CONTINUE_TEST(flags, OF_VERSION_1_1));
    value = OF_TABLE_CONFIG_TABLE_MISS_DROP;
    TEST_ASSERT(!OF_TABLE_CONFIG_TABLE_MISS_DROP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_TABLE_CONFIG_TABLE_MISS_DROP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_TABLE_CONFIG_TABLE_MISS_DROP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_TABLE_CONFIG_TABLE_MISS_DROP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_TABLE_CONFIG_TABLE_MISS_DROP_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_TABLE_CONFIG_TABLE_MISS_DROP_SET(flags, OF_VERSION_1_1);
    TEST_ASSERT(flags == OF_TABLE_CONFIG_TABLE_MISS_DROP_BY_VERSION(OF_VERSION_1_1));
    TEST_ASSERT(OF_TABLE_CONFIG_TABLE_MISS_DROP_TEST(flags, OF_VERSION_1_1));
    OF_TABLE_CONFIG_TABLE_MISS_DROP_CLEAR(flags, OF_VERSION_1_1);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_TABLE_CONFIG_TABLE_MISS_DROP_TEST(flags, OF_VERSION_1_1));
    value = OF_TABLE_CONFIG_TABLE_MISS_MASK;
    TEST_ASSERT(!OF_TABLE_CONFIG_TABLE_MISS_MASK_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_TABLE_CONFIG_TABLE_MISS_MASK_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_TABLE_CONFIG_TABLE_MISS_MASK_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_TABLE_CONFIG_TABLE_MISS_MASK_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_TABLE_CONFIG_TABLE_MISS_MASK_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_TABLE_CONFIG_TABLE_MISS_MASK_SET(flags, OF_VERSION_1_1);
    TEST_ASSERT(flags == OF_TABLE_CONFIG_TABLE_MISS_MASK_BY_VERSION(OF_VERSION_1_1));
    TEST_ASSERT(OF_TABLE_CONFIG_TABLE_MISS_MASK_TEST(flags, OF_VERSION_1_1));
    OF_TABLE_CONFIG_TABLE_MISS_MASK_CLEAR(flags, OF_VERSION_1_1);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_TABLE_CONFIG_TABLE_MISS_MASK_TEST(flags, OF_VERSION_1_1));
    value = OF_CAPABILITIES_FLAG_GROUP_STATS;
    TEST_ASSERT(!OF_CAPABILITIES_FLAG_GROUP_STATS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_CAPABILITIES_FLAG_GROUP_STATS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_CAPABILITIES_FLAG_GROUP_STATS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_CAPABILITIES_FLAG_GROUP_STATS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_CAPABILITIES_FLAG_GROUP_STATS_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_CAPABILITIES_FLAG_GROUP_STATS_SET(flags, OF_VERSION_1_1);
    TEST_ASSERT(flags == OF_CAPABILITIES_FLAG_GROUP_STATS_BY_VERSION(OF_VERSION_1_1));
    TEST_ASSERT(OF_CAPABILITIES_FLAG_GROUP_STATS_TEST(flags, OF_VERSION_1_1));
    OF_CAPABILITIES_FLAG_GROUP_STATS_CLEAR(flags, OF_VERSION_1_1);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_CAPABILITIES_FLAG_GROUP_STATS_TEST(flags, OF_VERSION_1_1));
    value = OF_PORT_STATE_FLAG_BLOCKED;
    TEST_ASSERT(!OF_PORT_STATE_FLAG_BLOCKED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_STATE_FLAG_BLOCKED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_PORT_STATE_FLAG_BLOCKED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PORT_STATE_FLAG_BLOCKED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PORT_STATE_FLAG_BLOCKED_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_PORT_STATE_FLAG_BLOCKED_SET(flags, OF_VERSION_1_1);
    TEST_ASSERT(flags == OF_PORT_STATE_FLAG_BLOCKED_BY_VERSION(OF_VERSION_1_1));
    TEST_ASSERT(OF_PORT_STATE_FLAG_BLOCKED_TEST(flags, OF_VERSION_1_1));
    OF_PORT_STATE_FLAG_BLOCKED_CLEAR(flags, OF_VERSION_1_1);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_PORT_STATE_FLAG_BLOCKED_TEST(flags, OF_VERSION_1_1));
    value = OF_PORT_STATE_FLAG_LIVE;
    TEST_ASSERT(!OF_PORT_STATE_FLAG_LIVE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_STATE_FLAG_LIVE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_PORT_STATE_FLAG_LIVE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PORT_STATE_FLAG_LIVE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PORT_STATE_FLAG_LIVE_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_PORT_STATE_FLAG_LIVE_SET(flags, OF_VERSION_1_1);
    TEST_ASSERT(flags == OF_PORT_STATE_FLAG_LIVE_BY_VERSION(OF_VERSION_1_1));
    TEST_ASSERT(OF_PORT_STATE_FLAG_LIVE_TEST(flags, OF_VERSION_1_1));
    OF_PORT_STATE_FLAG_LIVE_CLEAR(flags, OF_VERSION_1_1);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_PORT_STATE_FLAG_LIVE_TEST(flags, OF_VERSION_1_1));
    value = OF_PORT_FEATURE_FLAG_40GB_FD;
    TEST_ASSERT(!OF_PORT_FEATURE_FLAG_40GB_FD_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_40GB_FD_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_40GB_FD_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_40GB_FD_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_40GB_FD_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_PORT_FEATURE_FLAG_40GB_FD_SET(flags, OF_VERSION_1_1);
    TEST_ASSERT(flags == OF_PORT_FEATURE_FLAG_40GB_FD_BY_VERSION(OF_VERSION_1_1));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_40GB_FD_TEST(flags, OF_VERSION_1_1));
    OF_PORT_FEATURE_FLAG_40GB_FD_CLEAR(flags, OF_VERSION_1_1);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_PORT_FEATURE_FLAG_40GB_FD_TEST(flags, OF_VERSION_1_1));
    value = OF_PORT_FEATURE_FLAG_100GB_FD;
    TEST_ASSERT(!OF_PORT_FEATURE_FLAG_100GB_FD_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_100GB_FD_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_100GB_FD_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_100GB_FD_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_100GB_FD_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_PORT_FEATURE_FLAG_100GB_FD_SET(flags, OF_VERSION_1_1);
    TEST_ASSERT(flags == OF_PORT_FEATURE_FLAG_100GB_FD_BY_VERSION(OF_VERSION_1_1));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_100GB_FD_TEST(flags, OF_VERSION_1_1));
    OF_PORT_FEATURE_FLAG_100GB_FD_CLEAR(flags, OF_VERSION_1_1);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_PORT_FEATURE_FLAG_100GB_FD_TEST(flags, OF_VERSION_1_1));
    value = OF_PORT_FEATURE_FLAG_1TB_FD;
    TEST_ASSERT(!OF_PORT_FEATURE_FLAG_1TB_FD_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_1TB_FD_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_1TB_FD_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_1TB_FD_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_1TB_FD_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_PORT_FEATURE_FLAG_1TB_FD_SET(flags, OF_VERSION_1_1);
    TEST_ASSERT(flags == OF_PORT_FEATURE_FLAG_1TB_FD_BY_VERSION(OF_VERSION_1_1));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_1TB_FD_TEST(flags, OF_VERSION_1_1));
    OF_PORT_FEATURE_FLAG_1TB_FD_CLEAR(flags, OF_VERSION_1_1);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_PORT_FEATURE_FLAG_1TB_FD_TEST(flags, OF_VERSION_1_1));
    value = OF_PORT_FEATURE_FLAG_OTHER;
    TEST_ASSERT(!OF_PORT_FEATURE_FLAG_OTHER_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_OTHER_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_OTHER_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_OTHER_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_OTHER_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_PORT_FEATURE_FLAG_OTHER_SET(flags, OF_VERSION_1_1);
    TEST_ASSERT(flags == OF_PORT_FEATURE_FLAG_OTHER_BY_VERSION(OF_VERSION_1_1));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_OTHER_TEST(flags, OF_VERSION_1_1));
    OF_PORT_FEATURE_FLAG_OTHER_CLEAR(flags, OF_VERSION_1_1);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_PORT_FEATURE_FLAG_OTHER_TEST(flags, OF_VERSION_1_1));
    value = OF_ACTION_TYPE_SET_NW_ECN;
    TEST_ASSERT(!OF_ACTION_TYPE_SET_NW_ECN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ACTION_TYPE_SET_NW_ECN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_ACTION_TYPE_SET_NW_ECN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_ACTION_TYPE_SET_NW_ECN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_ACTION_TYPE_SET_NW_ECN_SUPPORTED(OF_VERSION_1_4));
    value = OF_ACTION_TYPE_COPY_TTL_OUT;
    TEST_ASSERT(!OF_ACTION_TYPE_COPY_TTL_OUT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ACTION_TYPE_COPY_TTL_OUT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ACTION_TYPE_COPY_TTL_OUT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ACTION_TYPE_COPY_TTL_OUT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ACTION_TYPE_COPY_TTL_OUT_SUPPORTED(OF_VERSION_1_4));
    value = OF_ACTION_TYPE_COPY_TTL_IN;
    TEST_ASSERT(!OF_ACTION_TYPE_COPY_TTL_IN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ACTION_TYPE_COPY_TTL_IN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ACTION_TYPE_COPY_TTL_IN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ACTION_TYPE_COPY_TTL_IN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ACTION_TYPE_COPY_TTL_IN_SUPPORTED(OF_VERSION_1_4));
    value = OF_ACTION_TYPE_SET_MPLS_LABEL;
    TEST_ASSERT(!OF_ACTION_TYPE_SET_MPLS_LABEL_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ACTION_TYPE_SET_MPLS_LABEL_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_ACTION_TYPE_SET_MPLS_LABEL_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_ACTION_TYPE_SET_MPLS_LABEL_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_ACTION_TYPE_SET_MPLS_LABEL_SUPPORTED(OF_VERSION_1_4));
    value = OF_ACTION_TYPE_SET_MPLS_TC;
    TEST_ASSERT(!OF_ACTION_TYPE_SET_MPLS_TC_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ACTION_TYPE_SET_MPLS_TC_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_ACTION_TYPE_SET_MPLS_TC_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_ACTION_TYPE_SET_MPLS_TC_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_ACTION_TYPE_SET_MPLS_TC_SUPPORTED(OF_VERSION_1_4));
    value = OF_ACTION_TYPE_SET_MPLS_TTL;
    TEST_ASSERT(!OF_ACTION_TYPE_SET_MPLS_TTL_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ACTION_TYPE_SET_MPLS_TTL_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ACTION_TYPE_SET_MPLS_TTL_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ACTION_TYPE_SET_MPLS_TTL_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ACTION_TYPE_SET_MPLS_TTL_SUPPORTED(OF_VERSION_1_4));
    value = OF_ACTION_TYPE_DEC_MPLS_TTL;
    TEST_ASSERT(!OF_ACTION_TYPE_DEC_MPLS_TTL_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ACTION_TYPE_DEC_MPLS_TTL_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ACTION_TYPE_DEC_MPLS_TTL_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ACTION_TYPE_DEC_MPLS_TTL_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ACTION_TYPE_DEC_MPLS_TTL_SUPPORTED(OF_VERSION_1_4));
    value = OF_ACTION_TYPE_PUSH_VLAN;
    TEST_ASSERT(!OF_ACTION_TYPE_PUSH_VLAN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ACTION_TYPE_PUSH_VLAN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ACTION_TYPE_PUSH_VLAN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ACTION_TYPE_PUSH_VLAN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ACTION_TYPE_PUSH_VLAN_SUPPORTED(OF_VERSION_1_4));
    value = OF_ACTION_TYPE_POP_VLAN;
    TEST_ASSERT(!OF_ACTION_TYPE_POP_VLAN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ACTION_TYPE_POP_VLAN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ACTION_TYPE_POP_VLAN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ACTION_TYPE_POP_VLAN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ACTION_TYPE_POP_VLAN_SUPPORTED(OF_VERSION_1_4));
    value = OF_ACTION_TYPE_PUSH_MPLS;
    TEST_ASSERT(!OF_ACTION_TYPE_PUSH_MPLS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ACTION_TYPE_PUSH_MPLS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ACTION_TYPE_PUSH_MPLS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ACTION_TYPE_PUSH_MPLS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ACTION_TYPE_PUSH_MPLS_SUPPORTED(OF_VERSION_1_4));
    value = OF_ACTION_TYPE_POP_MPLS;
    TEST_ASSERT(!OF_ACTION_TYPE_POP_MPLS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ACTION_TYPE_POP_MPLS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ACTION_TYPE_POP_MPLS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ACTION_TYPE_POP_MPLS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ACTION_TYPE_POP_MPLS_SUPPORTED(OF_VERSION_1_4));
    value = OF_ACTION_TYPE_SET_QUEUE;
    TEST_ASSERT(!OF_ACTION_TYPE_SET_QUEUE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ACTION_TYPE_SET_QUEUE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ACTION_TYPE_SET_QUEUE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ACTION_TYPE_SET_QUEUE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ACTION_TYPE_SET_QUEUE_SUPPORTED(OF_VERSION_1_4));
    value = OF_ACTION_TYPE_GROUP;
    TEST_ASSERT(!OF_ACTION_TYPE_GROUP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ACTION_TYPE_GROUP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ACTION_TYPE_GROUP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ACTION_TYPE_GROUP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ACTION_TYPE_GROUP_SUPPORTED(OF_VERSION_1_4));
    value = OF_ACTION_TYPE_SET_NW_TTL;
    TEST_ASSERT(!OF_ACTION_TYPE_SET_NW_TTL_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ACTION_TYPE_SET_NW_TTL_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ACTION_TYPE_SET_NW_TTL_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ACTION_TYPE_SET_NW_TTL_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ACTION_TYPE_SET_NW_TTL_SUPPORTED(OF_VERSION_1_4));
    value = OF_ACTION_TYPE_DEC_NW_TTL;
    TEST_ASSERT(!OF_ACTION_TYPE_DEC_NW_TTL_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ACTION_TYPE_DEC_NW_TTL_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ACTION_TYPE_DEC_NW_TTL_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ACTION_TYPE_DEC_NW_TTL_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ACTION_TYPE_DEC_NW_TTL_SUPPORTED(OF_VERSION_1_4));
    value = OF_GROUP_MOD_COMMAND_ADD;
    TEST_ASSERT(!OF_GROUP_MOD_COMMAND_ADD_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_GROUP_MOD_COMMAND_ADD_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_GROUP_MOD_COMMAND_ADD_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_GROUP_MOD_COMMAND_ADD_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_GROUP_MOD_COMMAND_ADD_SUPPORTED(OF_VERSION_1_4));
    value = OF_GROUP_MOD_COMMAND_MODIFY;
    TEST_ASSERT(!OF_GROUP_MOD_COMMAND_MODIFY_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_GROUP_MOD_COMMAND_MODIFY_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_GROUP_MOD_COMMAND_MODIFY_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_GROUP_MOD_COMMAND_MODIFY_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_GROUP_MOD_COMMAND_MODIFY_SUPPORTED(OF_VERSION_1_4));
    value = OF_GROUP_MOD_COMMAND_DELETE;
    TEST_ASSERT(!OF_GROUP_MOD_COMMAND_DELETE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_GROUP_MOD_COMMAND_DELETE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_GROUP_MOD_COMMAND_DELETE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_GROUP_MOD_COMMAND_DELETE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_GROUP_MOD_COMMAND_DELETE_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_WC_V1_MPLS_LABEL;
    TEST_ASSERT(!OF_FLOW_WC_V1_MPLS_LABEL_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_FLOW_WC_V1_MPLS_LABEL_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_FLOW_WC_V1_MPLS_LABEL_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_FLOW_WC_V1_MPLS_LABEL_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_FLOW_WC_V1_MPLS_LABEL_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_WC_V1_MPLS_TC;
    TEST_ASSERT(!OF_FLOW_WC_V1_MPLS_TC_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_FLOW_WC_V1_MPLS_TC_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_FLOW_WC_V1_MPLS_TC_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_FLOW_WC_V1_MPLS_TC_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_FLOW_WC_V1_MPLS_TC_SUPPORTED(OF_VERSION_1_4));
    value = OF_VLAN_TAG_ANY;
    TEST_ASSERT(!OF_VLAN_TAG_ANY_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_VLAN_TAG_ANY_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_VLAN_TAG_ANY_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_VLAN_TAG_ANY_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_VLAN_TAG_ANY_SUPPORTED(OF_VERSION_1_4));
    value = OF_MATCH_TYPE_STANDARD;
    TEST_ASSERT(!OF_MATCH_TYPE_STANDARD_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_MATCH_TYPE_STANDARD_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_MATCH_TYPE_STANDARD_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_MATCH_TYPE_STANDARD_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_MATCH_TYPE_STANDARD_SUPPORTED(OF_VERSION_1_4));
    value = OF_INSTRUCTION_TYPE_GOTO_TABLE;
    TEST_ASSERT(!OF_INSTRUCTION_TYPE_GOTO_TABLE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_INSTRUCTION_TYPE_GOTO_TABLE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_INSTRUCTION_TYPE_GOTO_TABLE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_INSTRUCTION_TYPE_GOTO_TABLE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_INSTRUCTION_TYPE_GOTO_TABLE_SUPPORTED(OF_VERSION_1_4));
    value = OF_INSTRUCTION_TYPE_WRITE_METADATA;
    TEST_ASSERT(!OF_INSTRUCTION_TYPE_WRITE_METADATA_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_INSTRUCTION_TYPE_WRITE_METADATA_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_INSTRUCTION_TYPE_WRITE_METADATA_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_INSTRUCTION_TYPE_WRITE_METADATA_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_INSTRUCTION_TYPE_WRITE_METADATA_SUPPORTED(OF_VERSION_1_4));
    value = OF_INSTRUCTION_TYPE_WRITE_ACTIONS;
    TEST_ASSERT(!OF_INSTRUCTION_TYPE_WRITE_ACTIONS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_INSTRUCTION_TYPE_WRITE_ACTIONS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_INSTRUCTION_TYPE_WRITE_ACTIONS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_INSTRUCTION_TYPE_WRITE_ACTIONS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_INSTRUCTION_TYPE_WRITE_ACTIONS_SUPPORTED(OF_VERSION_1_4));
    value = OF_INSTRUCTION_TYPE_APPLY_ACTIONS;
    TEST_ASSERT(!OF_INSTRUCTION_TYPE_APPLY_ACTIONS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_INSTRUCTION_TYPE_APPLY_ACTIONS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_INSTRUCTION_TYPE_APPLY_ACTIONS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_INSTRUCTION_TYPE_APPLY_ACTIONS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_INSTRUCTION_TYPE_APPLY_ACTIONS_SUPPORTED(OF_VERSION_1_4));
    value = OF_INSTRUCTION_TYPE_CLEAR_ACTIONS;
    TEST_ASSERT(!OF_INSTRUCTION_TYPE_CLEAR_ACTIONS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_INSTRUCTION_TYPE_CLEAR_ACTIONS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_INSTRUCTION_TYPE_CLEAR_ACTIONS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_INSTRUCTION_TYPE_CLEAR_ACTIONS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_INSTRUCTION_TYPE_CLEAR_ACTIONS_SUPPORTED(OF_VERSION_1_4));
    value = OF_INSTRUCTION_TYPE_EXPERIMENTER;
    TEST_ASSERT(!OF_INSTRUCTION_TYPE_EXPERIMENTER_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_INSTRUCTION_TYPE_EXPERIMENTER_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_INSTRUCTION_TYPE_EXPERIMENTER_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_INSTRUCTION_TYPE_EXPERIMENTER_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_INSTRUCTION_TYPE_EXPERIMENTER_SUPPORTED(OF_VERSION_1_4));
    value = OF_GROUP_MAX;
    TEST_ASSERT(!OF_GROUP_MAX_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_GROUP_MAX_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_GROUP_MAX_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_GROUP_MAX_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_GROUP_MAX_SUPPORTED(OF_VERSION_1_4));
    value = OF_GROUP_ALL;
    TEST_ASSERT(!OF_GROUP_ALL_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_GROUP_ALL_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_GROUP_ALL_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_GROUP_ALL_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_GROUP_ALL_SUPPORTED(OF_VERSION_1_4));
    value = OF_GROUP_ANY;
    TEST_ASSERT(!OF_GROUP_ANY_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_GROUP_ANY_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_GROUP_ANY_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_GROUP_ANY_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_GROUP_ANY_SUPPORTED(OF_VERSION_1_4));
    value = OF_GROUP_TYPE_ALL;
    TEST_ASSERT(!OF_GROUP_TYPE_ALL_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_GROUP_TYPE_ALL_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_GROUP_TYPE_ALL_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_GROUP_TYPE_ALL_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_GROUP_TYPE_ALL_SUPPORTED(OF_VERSION_1_4));
    value = OF_GROUP_TYPE_SELECT;
    TEST_ASSERT(!OF_GROUP_TYPE_SELECT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_GROUP_TYPE_SELECT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_GROUP_TYPE_SELECT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_GROUP_TYPE_SELECT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_GROUP_TYPE_SELECT_SUPPORTED(OF_VERSION_1_4));
    value = OF_GROUP_TYPE_INDIRECT;
    TEST_ASSERT(!OF_GROUP_TYPE_INDIRECT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_GROUP_TYPE_INDIRECT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_GROUP_TYPE_INDIRECT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_GROUP_TYPE_INDIRECT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_GROUP_TYPE_INDIRECT_SUPPORTED(OF_VERSION_1_4));
    value = OF_GROUP_TYPE_FF;
    TEST_ASSERT(!OF_GROUP_TYPE_FF_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_GROUP_TYPE_FF_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_GROUP_TYPE_FF_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_GROUP_TYPE_FF_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_GROUP_TYPE_FF_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_REMOVED_REASON_GROUP_DELETE;
    TEST_ASSERT(!OF_FLOW_REMOVED_REASON_GROUP_DELETE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_FLOW_REMOVED_REASON_GROUP_DELETE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_FLOW_REMOVED_REASON_GROUP_DELETE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_FLOW_REMOVED_REASON_GROUP_DELETE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_FLOW_REMOVED_REASON_GROUP_DELETE_SUPPORTED(OF_VERSION_1_4));
    value = OF_ERROR_TYPE_BAD_INSTRUCTION;
    TEST_ASSERT(!OF_ERROR_TYPE_BAD_INSTRUCTION_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ERROR_TYPE_BAD_INSTRUCTION_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ERROR_TYPE_BAD_INSTRUCTION_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ERROR_TYPE_BAD_INSTRUCTION_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ERROR_TYPE_BAD_INSTRUCTION_SUPPORTED(OF_VERSION_1_4));
    value = OF_ERROR_TYPE_BAD_MATCH;
    TEST_ASSERT(!OF_ERROR_TYPE_BAD_MATCH_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ERROR_TYPE_BAD_MATCH_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ERROR_TYPE_BAD_MATCH_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ERROR_TYPE_BAD_MATCH_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ERROR_TYPE_BAD_MATCH_SUPPORTED(OF_VERSION_1_4));
    value = OF_ERROR_TYPE_GROUP_MOD_FAILED;
    TEST_ASSERT(!OF_ERROR_TYPE_GROUP_MOD_FAILED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ERROR_TYPE_GROUP_MOD_FAILED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ERROR_TYPE_GROUP_MOD_FAILED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ERROR_TYPE_GROUP_MOD_FAILED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ERROR_TYPE_GROUP_MOD_FAILED_SUPPORTED(OF_VERSION_1_4));
    value = OF_ERROR_TYPE_TABLE_MOD_FAILED;
    TEST_ASSERT(!OF_ERROR_TYPE_TABLE_MOD_FAILED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ERROR_TYPE_TABLE_MOD_FAILED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ERROR_TYPE_TABLE_MOD_FAILED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ERROR_TYPE_TABLE_MOD_FAILED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ERROR_TYPE_TABLE_MOD_FAILED_SUPPORTED(OF_VERSION_1_4));
    value = OF_ERROR_TYPE_SWITCH_CONFIG_FAILED;
    TEST_ASSERT(!OF_ERROR_TYPE_SWITCH_CONFIG_FAILED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ERROR_TYPE_SWITCH_CONFIG_FAILED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ERROR_TYPE_SWITCH_CONFIG_FAILED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ERROR_TYPE_SWITCH_CONFIG_FAILED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ERROR_TYPE_SWITCH_CONFIG_FAILED_SUPPORTED(OF_VERSION_1_4));
    value = OF_REQUEST_FAILED_BAD_TABLE_ID;
    TEST_ASSERT(!OF_REQUEST_FAILED_BAD_TABLE_ID_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_REQUEST_FAILED_BAD_TABLE_ID_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_REQUEST_FAILED_BAD_TABLE_ID_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_REQUEST_FAILED_BAD_TABLE_ID_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_REQUEST_FAILED_BAD_TABLE_ID_SUPPORTED(OF_VERSION_1_4));
    value = OF_ACTION_FAILED_BAD_OUT_GROUP;
    TEST_ASSERT(!OF_ACTION_FAILED_BAD_OUT_GROUP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_OUT_GROUP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_OUT_GROUP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_OUT_GROUP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_OUT_GROUP_SUPPORTED(OF_VERSION_1_4));
    value = OF_ACTION_FAILED_MATCH_INCONSISTENT;
    TEST_ASSERT(!OF_ACTION_FAILED_MATCH_INCONSISTENT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ACTION_FAILED_MATCH_INCONSISTENT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ACTION_FAILED_MATCH_INCONSISTENT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ACTION_FAILED_MATCH_INCONSISTENT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ACTION_FAILED_MATCH_INCONSISTENT_SUPPORTED(OF_VERSION_1_4));
    value = OF_ACTION_FAILED_UNSUPPORTED_ORDER;
    TEST_ASSERT(!OF_ACTION_FAILED_UNSUPPORTED_ORDER_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ACTION_FAILED_UNSUPPORTED_ORDER_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ACTION_FAILED_UNSUPPORTED_ORDER_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ACTION_FAILED_UNSUPPORTED_ORDER_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ACTION_FAILED_UNSUPPORTED_ORDER_SUPPORTED(OF_VERSION_1_4));
    value = OF_ACTION_FAILED_BAD_TAG;
    TEST_ASSERT(!OF_ACTION_FAILED_BAD_TAG_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_TAG_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_TAG_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_TAG_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_TAG_SUPPORTED(OF_VERSION_1_4));
    value = OF_INSTRUCTION_FAILED_UNKNOWN_INST;
    TEST_ASSERT(!OF_INSTRUCTION_FAILED_UNKNOWN_INST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_INSTRUCTION_FAILED_UNKNOWN_INST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_INSTRUCTION_FAILED_UNKNOWN_INST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_INSTRUCTION_FAILED_UNKNOWN_INST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_INSTRUCTION_FAILED_UNKNOWN_INST_SUPPORTED(OF_VERSION_1_4));
    value = OF_INSTRUCTION_FAILED_UNSUP_INST;
    TEST_ASSERT(!OF_INSTRUCTION_FAILED_UNSUP_INST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_INSTRUCTION_FAILED_UNSUP_INST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_INSTRUCTION_FAILED_UNSUP_INST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_INSTRUCTION_FAILED_UNSUP_INST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_INSTRUCTION_FAILED_UNSUP_INST_SUPPORTED(OF_VERSION_1_4));
    value = OF_INSTRUCTION_FAILED_BAD_TABLE_ID;
    TEST_ASSERT(!OF_INSTRUCTION_FAILED_BAD_TABLE_ID_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_INSTRUCTION_FAILED_BAD_TABLE_ID_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_INSTRUCTION_FAILED_BAD_TABLE_ID_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_INSTRUCTION_FAILED_BAD_TABLE_ID_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_INSTRUCTION_FAILED_BAD_TABLE_ID_SUPPORTED(OF_VERSION_1_4));
    value = OF_INSTRUCTION_FAILED_UNSUP_METADATA;
    TEST_ASSERT(!OF_INSTRUCTION_FAILED_UNSUP_METADATA_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_INSTRUCTION_FAILED_UNSUP_METADATA_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_INSTRUCTION_FAILED_UNSUP_METADATA_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_INSTRUCTION_FAILED_UNSUP_METADATA_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_INSTRUCTION_FAILED_UNSUP_METADATA_SUPPORTED(OF_VERSION_1_4));
    value = OF_INSTRUCTION_FAILED_UNSUP_METADATA_MASK;
    TEST_ASSERT(!OF_INSTRUCTION_FAILED_UNSUP_METADATA_MASK_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_INSTRUCTION_FAILED_UNSUP_METADATA_MASK_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_INSTRUCTION_FAILED_UNSUP_METADATA_MASK_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_INSTRUCTION_FAILED_UNSUP_METADATA_MASK_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_INSTRUCTION_FAILED_UNSUP_METADATA_MASK_SUPPORTED(OF_VERSION_1_4));
    value = OF_INSTRUCTION_FAILED_UNSUP_EXP_INST;
    TEST_ASSERT(!OF_INSTRUCTION_FAILED_UNSUP_EXP_INST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_INSTRUCTION_FAILED_UNSUP_EXP_INST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_INSTRUCTION_FAILED_UNSUP_EXP_INST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_INSTRUCTION_FAILED_UNSUP_EXP_INST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_INSTRUCTION_FAILED_UNSUP_EXP_INST_SUPPORTED(OF_VERSION_1_4));
    value = OF_MATCH_FAILED_BAD_TYPE;
    TEST_ASSERT(!OF_MATCH_FAILED_BAD_TYPE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_MATCH_FAILED_BAD_TYPE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_MATCH_FAILED_BAD_TYPE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_MATCH_FAILED_BAD_TYPE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_MATCH_FAILED_BAD_TYPE_SUPPORTED(OF_VERSION_1_4));
    value = OF_MATCH_FAILED_BAD_LEN;
    TEST_ASSERT(!OF_MATCH_FAILED_BAD_LEN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_MATCH_FAILED_BAD_LEN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_MATCH_FAILED_BAD_LEN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_MATCH_FAILED_BAD_LEN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_MATCH_FAILED_BAD_LEN_SUPPORTED(OF_VERSION_1_4));
    value = OF_MATCH_FAILED_BAD_TAG;
    TEST_ASSERT(!OF_MATCH_FAILED_BAD_TAG_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_MATCH_FAILED_BAD_TAG_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_MATCH_FAILED_BAD_TAG_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_MATCH_FAILED_BAD_TAG_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_MATCH_FAILED_BAD_TAG_SUPPORTED(OF_VERSION_1_4));
    value = OF_MATCH_FAILED_BAD_DL_ADDR_MASK;
    TEST_ASSERT(!OF_MATCH_FAILED_BAD_DL_ADDR_MASK_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_MATCH_FAILED_BAD_DL_ADDR_MASK_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_MATCH_FAILED_BAD_DL_ADDR_MASK_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_MATCH_FAILED_BAD_DL_ADDR_MASK_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_MATCH_FAILED_BAD_DL_ADDR_MASK_SUPPORTED(OF_VERSION_1_4));
    value = OF_MATCH_FAILED_BAD_NW_ADDR_MASK;
    TEST_ASSERT(!OF_MATCH_FAILED_BAD_NW_ADDR_MASK_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_MATCH_FAILED_BAD_NW_ADDR_MASK_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_MATCH_FAILED_BAD_NW_ADDR_MASK_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_MATCH_FAILED_BAD_NW_ADDR_MASK_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_MATCH_FAILED_BAD_NW_ADDR_MASK_SUPPORTED(OF_VERSION_1_4));
    value = OF_MATCH_FAILED_BAD_WILDCARDS;
    TEST_ASSERT(!OF_MATCH_FAILED_BAD_WILDCARDS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_MATCH_FAILED_BAD_WILDCARDS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_MATCH_FAILED_BAD_WILDCARDS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_MATCH_FAILED_BAD_WILDCARDS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_MATCH_FAILED_BAD_WILDCARDS_SUPPORTED(OF_VERSION_1_4));
    value = OF_MATCH_FAILED_BAD_FIELD;
    TEST_ASSERT(!OF_MATCH_FAILED_BAD_FIELD_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_MATCH_FAILED_BAD_FIELD_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_MATCH_FAILED_BAD_FIELD_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_MATCH_FAILED_BAD_FIELD_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_MATCH_FAILED_BAD_FIELD_SUPPORTED(OF_VERSION_1_4));
    value = OF_MATCH_FAILED_BAD_VALUE;
    TEST_ASSERT(!OF_MATCH_FAILED_BAD_VALUE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_MATCH_FAILED_BAD_VALUE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_MATCH_FAILED_BAD_VALUE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_MATCH_FAILED_BAD_VALUE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_MATCH_FAILED_BAD_VALUE_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_MOD_FAILED_UNKNOWN;
    TEST_ASSERT(!OF_FLOW_MOD_FAILED_UNKNOWN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_FLOW_MOD_FAILED_UNKNOWN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_FLOW_MOD_FAILED_UNKNOWN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_FLOW_MOD_FAILED_UNKNOWN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_FLOW_MOD_FAILED_UNKNOWN_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_MOD_FAILED_TABLE_FULL;
    TEST_ASSERT(!OF_FLOW_MOD_FAILED_TABLE_FULL_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_FLOW_MOD_FAILED_TABLE_FULL_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_FLOW_MOD_FAILED_TABLE_FULL_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_FLOW_MOD_FAILED_TABLE_FULL_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_FLOW_MOD_FAILED_TABLE_FULL_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_MOD_FAILED_BAD_TABLE_ID;
    TEST_ASSERT(!OF_FLOW_MOD_FAILED_BAD_TABLE_ID_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_FLOW_MOD_FAILED_BAD_TABLE_ID_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_FLOW_MOD_FAILED_BAD_TABLE_ID_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_FLOW_MOD_FAILED_BAD_TABLE_ID_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_FLOW_MOD_FAILED_BAD_TABLE_ID_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_MOD_FAILED_BAD_TIMEOUT;
    TEST_ASSERT(!OF_FLOW_MOD_FAILED_BAD_TIMEOUT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_FLOW_MOD_FAILED_BAD_TIMEOUT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_FLOW_MOD_FAILED_BAD_TIMEOUT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_FLOW_MOD_FAILED_BAD_TIMEOUT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_FLOW_MOD_FAILED_BAD_TIMEOUT_SUPPORTED(OF_VERSION_1_4));
    value = OF_GROUP_MOD_FAILED_GROUP_EXISTS;
    TEST_ASSERT(!OF_GROUP_MOD_FAILED_GROUP_EXISTS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_GROUP_EXISTS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_GROUP_EXISTS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_GROUP_EXISTS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_GROUP_EXISTS_SUPPORTED(OF_VERSION_1_4));
    value = OF_GROUP_MOD_FAILED_INVALID_GROUP;
    TEST_ASSERT(!OF_GROUP_MOD_FAILED_INVALID_GROUP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_INVALID_GROUP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_INVALID_GROUP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_INVALID_GROUP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_INVALID_GROUP_SUPPORTED(OF_VERSION_1_4));
    value = OF_GROUP_MOD_FAILED_WEIGHT_UNSUPPORTED;
    TEST_ASSERT(!OF_GROUP_MOD_FAILED_WEIGHT_UNSUPPORTED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_WEIGHT_UNSUPPORTED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_WEIGHT_UNSUPPORTED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_WEIGHT_UNSUPPORTED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_WEIGHT_UNSUPPORTED_SUPPORTED(OF_VERSION_1_4));
    value = OF_GROUP_MOD_FAILED_OUT_OF_GROUPS;
    TEST_ASSERT(!OF_GROUP_MOD_FAILED_OUT_OF_GROUPS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_OUT_OF_GROUPS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_OUT_OF_GROUPS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_OUT_OF_GROUPS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_OUT_OF_GROUPS_SUPPORTED(OF_VERSION_1_4));
    value = OF_GROUP_MOD_FAILED_OUT_OF_BUCKETS;
    TEST_ASSERT(!OF_GROUP_MOD_FAILED_OUT_OF_BUCKETS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_OUT_OF_BUCKETS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_OUT_OF_BUCKETS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_OUT_OF_BUCKETS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_OUT_OF_BUCKETS_SUPPORTED(OF_VERSION_1_4));
    value = OF_GROUP_MOD_FAILED_CHAINING_UNSUPPORTED;
    TEST_ASSERT(!OF_GROUP_MOD_FAILED_CHAINING_UNSUPPORTED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_CHAINING_UNSUPPORTED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_CHAINING_UNSUPPORTED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_CHAINING_UNSUPPORTED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_CHAINING_UNSUPPORTED_SUPPORTED(OF_VERSION_1_4));
    value = OF_GROUP_MOD_FAILED_WATCH_UNSUPPORTED;
    TEST_ASSERT(!OF_GROUP_MOD_FAILED_WATCH_UNSUPPORTED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_WATCH_UNSUPPORTED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_WATCH_UNSUPPORTED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_WATCH_UNSUPPORTED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_WATCH_UNSUPPORTED_SUPPORTED(OF_VERSION_1_4));
    value = OF_GROUP_MOD_FAILED_LOOP;
    TEST_ASSERT(!OF_GROUP_MOD_FAILED_LOOP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_LOOP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_LOOP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_LOOP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_LOOP_SUPPORTED(OF_VERSION_1_4));
    value = OF_GROUP_MOD_FAILED_UNKNOWN_GROUP;
    TEST_ASSERT(!OF_GROUP_MOD_FAILED_UNKNOWN_GROUP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_UNKNOWN_GROUP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_UNKNOWN_GROUP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_UNKNOWN_GROUP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_UNKNOWN_GROUP_SUPPORTED(OF_VERSION_1_4));
    value = OF_PORT_MOD_FAILED_BAD_CONFIG;
    TEST_ASSERT(!OF_PORT_MOD_FAILED_BAD_CONFIG_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_MOD_FAILED_BAD_CONFIG_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_PORT_MOD_FAILED_BAD_CONFIG_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PORT_MOD_FAILED_BAD_CONFIG_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PORT_MOD_FAILED_BAD_CONFIG_SUPPORTED(OF_VERSION_1_4));
    value = OF_PORT_MOD_FAILED_BAD_ADVERTISE;
    TEST_ASSERT(!OF_PORT_MOD_FAILED_BAD_ADVERTISE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_PORT_MOD_FAILED_BAD_ADVERTISE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_PORT_MOD_FAILED_BAD_ADVERTISE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PORT_MOD_FAILED_BAD_ADVERTISE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PORT_MOD_FAILED_BAD_ADVERTISE_SUPPORTED(OF_VERSION_1_4));
    value = OF_TABLE_MOD_FAILED_BAD_TABLE;
    TEST_ASSERT(!OF_TABLE_MOD_FAILED_BAD_TABLE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_TABLE_MOD_FAILED_BAD_TABLE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_TABLE_MOD_FAILED_BAD_TABLE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_TABLE_MOD_FAILED_BAD_TABLE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_TABLE_MOD_FAILED_BAD_TABLE_SUPPORTED(OF_VERSION_1_4));
    value = OF_TABLE_MOD_FAILED_BAD_CONFIG;
    TEST_ASSERT(!OF_TABLE_MOD_FAILED_BAD_CONFIG_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_TABLE_MOD_FAILED_BAD_CONFIG_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_TABLE_MOD_FAILED_BAD_CONFIG_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_TABLE_MOD_FAILED_BAD_CONFIG_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_TABLE_MOD_FAILED_BAD_CONFIG_SUPPORTED(OF_VERSION_1_4));
    value = OF_SWITCH_CONFIG_FAILED_BAD_FLAGS;
    TEST_ASSERT(!OF_SWITCH_CONFIG_FAILED_BAD_FLAGS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_SWITCH_CONFIG_FAILED_BAD_FLAGS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_SWITCH_CONFIG_FAILED_BAD_FLAGS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_SWITCH_CONFIG_FAILED_BAD_FLAGS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_SWITCH_CONFIG_FAILED_BAD_FLAGS_SUPPORTED(OF_VERSION_1_4));
    value = OF_SWITCH_CONFIG_FAILED_BAD_LEN;
    TEST_ASSERT(!OF_SWITCH_CONFIG_FAILED_BAD_LEN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_SWITCH_CONFIG_FAILED_BAD_LEN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_SWITCH_CONFIG_FAILED_BAD_LEN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_SWITCH_CONFIG_FAILED_BAD_LEN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_SWITCH_CONFIG_FAILED_BAD_LEN_SUPPORTED(OF_VERSION_1_4));
    value = OF_STATS_TYPE_GROUP;
    TEST_ASSERT(!OF_STATS_TYPE_GROUP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_STATS_TYPE_GROUP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_STATS_TYPE_GROUP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_STATS_TYPE_GROUP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_STATS_TYPE_GROUP_SUPPORTED(OF_VERSION_1_4));
    value = OF_STATS_TYPE_GROUP_DESC;
    TEST_ASSERT(!OF_STATS_TYPE_GROUP_DESC_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(OF_STATS_TYPE_GROUP_DESC_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_STATS_TYPE_GROUP_DESC_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_STATS_TYPE_GROUP_DESC_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_STATS_TYPE_GROUP_DESC_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_TCP_FLAG_FIN;
    TEST_ASSERT(!OFP_BSN_TCP_FLAG_FIN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_TCP_FLAG_FIN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OFP_BSN_TCP_FLAG_FIN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_TCP_FLAG_FIN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_TCP_FLAG_FIN_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_BSN_TCP_FLAG_FIN_SET(flags, OF_VERSION_1_2);
    TEST_ASSERT(flags == OFP_BSN_TCP_FLAG_FIN_BY_VERSION(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_TCP_FLAG_FIN_TEST(flags, OF_VERSION_1_2));
    OFP_BSN_TCP_FLAG_FIN_CLEAR(flags, OF_VERSION_1_2);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_BSN_TCP_FLAG_FIN_TEST(flags, OF_VERSION_1_2));
    value = OFP_BSN_TCP_FLAG_SYN;
    TEST_ASSERT(!OFP_BSN_TCP_FLAG_SYN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_TCP_FLAG_SYN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OFP_BSN_TCP_FLAG_SYN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_TCP_FLAG_SYN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_TCP_FLAG_SYN_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_BSN_TCP_FLAG_SYN_SET(flags, OF_VERSION_1_2);
    TEST_ASSERT(flags == OFP_BSN_TCP_FLAG_SYN_BY_VERSION(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_TCP_FLAG_SYN_TEST(flags, OF_VERSION_1_2));
    OFP_BSN_TCP_FLAG_SYN_CLEAR(flags, OF_VERSION_1_2);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_BSN_TCP_FLAG_SYN_TEST(flags, OF_VERSION_1_2));
    value = OFP_BSN_TCP_FLAG_RST;
    TEST_ASSERT(!OFP_BSN_TCP_FLAG_RST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_TCP_FLAG_RST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OFP_BSN_TCP_FLAG_RST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_TCP_FLAG_RST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_TCP_FLAG_RST_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_BSN_TCP_FLAG_RST_SET(flags, OF_VERSION_1_2);
    TEST_ASSERT(flags == OFP_BSN_TCP_FLAG_RST_BY_VERSION(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_TCP_FLAG_RST_TEST(flags, OF_VERSION_1_2));
    OFP_BSN_TCP_FLAG_RST_CLEAR(flags, OF_VERSION_1_2);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_BSN_TCP_FLAG_RST_TEST(flags, OF_VERSION_1_2));
    value = OFP_BSN_TCP_FLAG_PSH;
    TEST_ASSERT(!OFP_BSN_TCP_FLAG_PSH_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_TCP_FLAG_PSH_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OFP_BSN_TCP_FLAG_PSH_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_TCP_FLAG_PSH_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_TCP_FLAG_PSH_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_BSN_TCP_FLAG_PSH_SET(flags, OF_VERSION_1_2);
    TEST_ASSERT(flags == OFP_BSN_TCP_FLAG_PSH_BY_VERSION(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_TCP_FLAG_PSH_TEST(flags, OF_VERSION_1_2));
    OFP_BSN_TCP_FLAG_PSH_CLEAR(flags, OF_VERSION_1_2);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_BSN_TCP_FLAG_PSH_TEST(flags, OF_VERSION_1_2));
    value = OFP_BSN_TCP_FLAG_ACK;
    TEST_ASSERT(!OFP_BSN_TCP_FLAG_ACK_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_TCP_FLAG_ACK_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OFP_BSN_TCP_FLAG_ACK_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_TCP_FLAG_ACK_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_TCP_FLAG_ACK_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_BSN_TCP_FLAG_ACK_SET(flags, OF_VERSION_1_2);
    TEST_ASSERT(flags == OFP_BSN_TCP_FLAG_ACK_BY_VERSION(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_TCP_FLAG_ACK_TEST(flags, OF_VERSION_1_2));
    OFP_BSN_TCP_FLAG_ACK_CLEAR(flags, OF_VERSION_1_2);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_BSN_TCP_FLAG_ACK_TEST(flags, OF_VERSION_1_2));
    value = OFP_BSN_TCP_FLAG_URG;
    TEST_ASSERT(!OFP_BSN_TCP_FLAG_URG_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_TCP_FLAG_URG_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OFP_BSN_TCP_FLAG_URG_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_TCP_FLAG_URG_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_TCP_FLAG_URG_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_BSN_TCP_FLAG_URG_SET(flags, OF_VERSION_1_2);
    TEST_ASSERT(flags == OFP_BSN_TCP_FLAG_URG_BY_VERSION(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_TCP_FLAG_URG_TEST(flags, OF_VERSION_1_2));
    OFP_BSN_TCP_FLAG_URG_CLEAR(flags, OF_VERSION_1_2);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_BSN_TCP_FLAG_URG_TEST(flags, OF_VERSION_1_2));
    value = OFP_BSN_TCP_FLAG_ECE;
    TEST_ASSERT(!OFP_BSN_TCP_FLAG_ECE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_TCP_FLAG_ECE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OFP_BSN_TCP_FLAG_ECE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_TCP_FLAG_ECE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_TCP_FLAG_ECE_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_BSN_TCP_FLAG_ECE_SET(flags, OF_VERSION_1_2);
    TEST_ASSERT(flags == OFP_BSN_TCP_FLAG_ECE_BY_VERSION(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_TCP_FLAG_ECE_TEST(flags, OF_VERSION_1_2));
    OFP_BSN_TCP_FLAG_ECE_CLEAR(flags, OF_VERSION_1_2);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_BSN_TCP_FLAG_ECE_TEST(flags, OF_VERSION_1_2));
    value = OFP_BSN_TCP_FLAG_CWR;
    TEST_ASSERT(!OFP_BSN_TCP_FLAG_CWR_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_TCP_FLAG_CWR_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OFP_BSN_TCP_FLAG_CWR_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_TCP_FLAG_CWR_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_TCP_FLAG_CWR_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_BSN_TCP_FLAG_CWR_SET(flags, OF_VERSION_1_2);
    TEST_ASSERT(flags == OFP_BSN_TCP_FLAG_CWR_BY_VERSION(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_TCP_FLAG_CWR_TEST(flags, OF_VERSION_1_2));
    OFP_BSN_TCP_FLAG_CWR_CLEAR(flags, OF_VERSION_1_2);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_BSN_TCP_FLAG_CWR_TEST(flags, OF_VERSION_1_2));
    value = OFP_BSN_TCP_FLAG_NS;
    TEST_ASSERT(!OFP_BSN_TCP_FLAG_NS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_TCP_FLAG_NS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OFP_BSN_TCP_FLAG_NS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_TCP_FLAG_NS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_TCP_FLAG_NS_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_BSN_TCP_FLAG_NS_SET(flags, OF_VERSION_1_2);
    TEST_ASSERT(flags == OFP_BSN_TCP_FLAG_NS_BY_VERSION(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_TCP_FLAG_NS_TEST(flags, OF_VERSION_1_2));
    OFP_BSN_TCP_FLAG_NS_CLEAR(flags, OF_VERSION_1_2);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_BSN_TCP_FLAG_NS_TEST(flags, OF_VERSION_1_2));
    value = OFP_OVS_TCP_FLAG_FIN;
    TEST_ASSERT(!OFP_OVS_TCP_FLAG_FIN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_OVS_TCP_FLAG_FIN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OFP_OVS_TCP_FLAG_FIN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_OVS_TCP_FLAG_FIN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_OVS_TCP_FLAG_FIN_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_OVS_TCP_FLAG_FIN_SET(flags, OF_VERSION_1_2);
    TEST_ASSERT(flags == OFP_OVS_TCP_FLAG_FIN_BY_VERSION(OF_VERSION_1_2));
    TEST_ASSERT(OFP_OVS_TCP_FLAG_FIN_TEST(flags, OF_VERSION_1_2));
    OFP_OVS_TCP_FLAG_FIN_CLEAR(flags, OF_VERSION_1_2);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_OVS_TCP_FLAG_FIN_TEST(flags, OF_VERSION_1_2));
    value = OFP_OVS_TCP_FLAG_SYN;
    TEST_ASSERT(!OFP_OVS_TCP_FLAG_SYN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_OVS_TCP_FLAG_SYN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OFP_OVS_TCP_FLAG_SYN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_OVS_TCP_FLAG_SYN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_OVS_TCP_FLAG_SYN_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_OVS_TCP_FLAG_SYN_SET(flags, OF_VERSION_1_2);
    TEST_ASSERT(flags == OFP_OVS_TCP_FLAG_SYN_BY_VERSION(OF_VERSION_1_2));
    TEST_ASSERT(OFP_OVS_TCP_FLAG_SYN_TEST(flags, OF_VERSION_1_2));
    OFP_OVS_TCP_FLAG_SYN_CLEAR(flags, OF_VERSION_1_2);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_OVS_TCP_FLAG_SYN_TEST(flags, OF_VERSION_1_2));
    value = OFP_OVS_TCP_FLAG_RST;
    TEST_ASSERT(!OFP_OVS_TCP_FLAG_RST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_OVS_TCP_FLAG_RST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OFP_OVS_TCP_FLAG_RST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_OVS_TCP_FLAG_RST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_OVS_TCP_FLAG_RST_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_OVS_TCP_FLAG_RST_SET(flags, OF_VERSION_1_2);
    TEST_ASSERT(flags == OFP_OVS_TCP_FLAG_RST_BY_VERSION(OF_VERSION_1_2));
    TEST_ASSERT(OFP_OVS_TCP_FLAG_RST_TEST(flags, OF_VERSION_1_2));
    OFP_OVS_TCP_FLAG_RST_CLEAR(flags, OF_VERSION_1_2);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_OVS_TCP_FLAG_RST_TEST(flags, OF_VERSION_1_2));
    value = OFP_OVS_TCP_FLAG_PSH;
    TEST_ASSERT(!OFP_OVS_TCP_FLAG_PSH_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_OVS_TCP_FLAG_PSH_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OFP_OVS_TCP_FLAG_PSH_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_OVS_TCP_FLAG_PSH_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_OVS_TCP_FLAG_PSH_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_OVS_TCP_FLAG_PSH_SET(flags, OF_VERSION_1_2);
    TEST_ASSERT(flags == OFP_OVS_TCP_FLAG_PSH_BY_VERSION(OF_VERSION_1_2));
    TEST_ASSERT(OFP_OVS_TCP_FLAG_PSH_TEST(flags, OF_VERSION_1_2));
    OFP_OVS_TCP_FLAG_PSH_CLEAR(flags, OF_VERSION_1_2);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_OVS_TCP_FLAG_PSH_TEST(flags, OF_VERSION_1_2));
    value = OFP_OVS_TCP_FLAG_ACK;
    TEST_ASSERT(!OFP_OVS_TCP_FLAG_ACK_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_OVS_TCP_FLAG_ACK_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OFP_OVS_TCP_FLAG_ACK_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_OVS_TCP_FLAG_ACK_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_OVS_TCP_FLAG_ACK_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_OVS_TCP_FLAG_ACK_SET(flags, OF_VERSION_1_2);
    TEST_ASSERT(flags == OFP_OVS_TCP_FLAG_ACK_BY_VERSION(OF_VERSION_1_2));
    TEST_ASSERT(OFP_OVS_TCP_FLAG_ACK_TEST(flags, OF_VERSION_1_2));
    OFP_OVS_TCP_FLAG_ACK_CLEAR(flags, OF_VERSION_1_2);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_OVS_TCP_FLAG_ACK_TEST(flags, OF_VERSION_1_2));
    value = OFP_OVS_TCP_FLAG_URG;
    TEST_ASSERT(!OFP_OVS_TCP_FLAG_URG_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_OVS_TCP_FLAG_URG_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OFP_OVS_TCP_FLAG_URG_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_OVS_TCP_FLAG_URG_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_OVS_TCP_FLAG_URG_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_OVS_TCP_FLAG_URG_SET(flags, OF_VERSION_1_2);
    TEST_ASSERT(flags == OFP_OVS_TCP_FLAG_URG_BY_VERSION(OF_VERSION_1_2));
    TEST_ASSERT(OFP_OVS_TCP_FLAG_URG_TEST(flags, OF_VERSION_1_2));
    OFP_OVS_TCP_FLAG_URG_CLEAR(flags, OF_VERSION_1_2);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_OVS_TCP_FLAG_URG_TEST(flags, OF_VERSION_1_2));
    value = OFP_OVS_TCP_FLAG_ECE;
    TEST_ASSERT(!OFP_OVS_TCP_FLAG_ECE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_OVS_TCP_FLAG_ECE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OFP_OVS_TCP_FLAG_ECE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_OVS_TCP_FLAG_ECE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_OVS_TCP_FLAG_ECE_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_OVS_TCP_FLAG_ECE_SET(flags, OF_VERSION_1_2);
    TEST_ASSERT(flags == OFP_OVS_TCP_FLAG_ECE_BY_VERSION(OF_VERSION_1_2));
    TEST_ASSERT(OFP_OVS_TCP_FLAG_ECE_TEST(flags, OF_VERSION_1_2));
    OFP_OVS_TCP_FLAG_ECE_CLEAR(flags, OF_VERSION_1_2);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_OVS_TCP_FLAG_ECE_TEST(flags, OF_VERSION_1_2));
    value = OFP_OVS_TCP_FLAG_CWR;
    TEST_ASSERT(!OFP_OVS_TCP_FLAG_CWR_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_OVS_TCP_FLAG_CWR_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OFP_OVS_TCP_FLAG_CWR_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_OVS_TCP_FLAG_CWR_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_OVS_TCP_FLAG_CWR_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_OVS_TCP_FLAG_CWR_SET(flags, OF_VERSION_1_2);
    TEST_ASSERT(flags == OFP_OVS_TCP_FLAG_CWR_BY_VERSION(OF_VERSION_1_2));
    TEST_ASSERT(OFP_OVS_TCP_FLAG_CWR_TEST(flags, OF_VERSION_1_2));
    OFP_OVS_TCP_FLAG_CWR_CLEAR(flags, OF_VERSION_1_2);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_OVS_TCP_FLAG_CWR_TEST(flags, OF_VERSION_1_2));
    value = OFP_OVS_TCP_FLAG_NS;
    TEST_ASSERT(!OFP_OVS_TCP_FLAG_NS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_OVS_TCP_FLAG_NS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OFP_OVS_TCP_FLAG_NS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_OVS_TCP_FLAG_NS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_OVS_TCP_FLAG_NS_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_OVS_TCP_FLAG_NS_SET(flags, OF_VERSION_1_2);
    TEST_ASSERT(flags == OFP_OVS_TCP_FLAG_NS_BY_VERSION(OF_VERSION_1_2));
    TEST_ASSERT(OFP_OVS_TCP_FLAG_NS_TEST(flags, OF_VERSION_1_2));
    OFP_OVS_TCP_FLAG_NS_CLEAR(flags, OF_VERSION_1_2);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_OVS_TCP_FLAG_NS_TEST(flags, OF_VERSION_1_2));
    value = OF_BUFFER_ID_NO_BUFFER;
    TEST_ASSERT(!OF_BUFFER_ID_NO_BUFFER_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_BUFFER_ID_NO_BUFFER_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_BUFFER_ID_NO_BUFFER_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_BUFFER_ID_NO_BUFFER_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_BUFFER_ID_NO_BUFFER_SUPPORTED(OF_VERSION_1_4));
    value = OF_QUEUE_MAX_RATE_UNCFG;
    TEST_ASSERT(!OF_QUEUE_MAX_RATE_UNCFG_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_QUEUE_MAX_RATE_UNCFG_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_QUEUE_MAX_RATE_UNCFG_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_QUEUE_MAX_RATE_UNCFG_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_QUEUE_MAX_RATE_UNCFG_SUPPORTED(OF_VERSION_1_4));
    value = OF_OBJ_TYPE_ROLE_REQUEST;
    TEST_ASSERT(!OF_OBJ_TYPE_ROLE_REQUEST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_OBJ_TYPE_ROLE_REQUEST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_OBJ_TYPE_ROLE_REQUEST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_OBJ_TYPE_ROLE_REQUEST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_OBJ_TYPE_ROLE_REQUEST_SUPPORTED(OF_VERSION_1_4));
    value = OF_OBJ_TYPE_ROLE_REPLY;
    TEST_ASSERT(!OF_OBJ_TYPE_ROLE_REPLY_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_OBJ_TYPE_ROLE_REPLY_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_OBJ_TYPE_ROLE_REPLY_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_OBJ_TYPE_ROLE_REPLY_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_OBJ_TYPE_ROLE_REPLY_SUPPORTED(OF_VERSION_1_4));
    value = OF_TABLE_MAX;
    TEST_ASSERT(!OF_TABLE_MAX_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_TABLE_MAX_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_TABLE_MAX_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_TABLE_MAX_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_TABLE_MAX_SUPPORTED(OF_VERSION_1_4));
    value = OF_TABLE_ALL;
    TEST_ASSERT(!OF_TABLE_ALL_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_TABLE_ALL_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_TABLE_ALL_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_TABLE_ALL_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_TABLE_ALL_SUPPORTED(OF_VERSION_1_4));
    value = OF_CAPABILITIES_FLAG_PORT_BLOCKED;
    TEST_ASSERT(!OF_CAPABILITIES_FLAG_PORT_BLOCKED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_CAPABILITIES_FLAG_PORT_BLOCKED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_CAPABILITIES_FLAG_PORT_BLOCKED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_CAPABILITIES_FLAG_PORT_BLOCKED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_CAPABILITIES_FLAG_PORT_BLOCKED_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_CAPABILITIES_FLAG_PORT_BLOCKED_SET(flags, OF_VERSION_1_2);
    TEST_ASSERT(flags == OF_CAPABILITIES_FLAG_PORT_BLOCKED_BY_VERSION(OF_VERSION_1_2));
    TEST_ASSERT(OF_CAPABILITIES_FLAG_PORT_BLOCKED_TEST(flags, OF_VERSION_1_2));
    OF_CAPABILITIES_FLAG_PORT_BLOCKED_CLEAR(flags, OF_VERSION_1_2);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_CAPABILITIES_FLAG_PORT_BLOCKED_TEST(flags, OF_VERSION_1_2));
    value = OF_MATCH_TYPE_OXM;
    TEST_ASSERT(!OF_MATCH_TYPE_OXM_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_MATCH_TYPE_OXM_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_MATCH_TYPE_OXM_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_MATCH_TYPE_OXM_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_MATCH_TYPE_OXM_SUPPORTED(OF_VERSION_1_4));
    value = OF_OXM_CLASS_NXM_0;
    TEST_ASSERT(!OF_OXM_CLASS_NXM_0_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_OXM_CLASS_NXM_0_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_OXM_CLASS_NXM_0_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_OXM_CLASS_NXM_0_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_OXM_CLASS_NXM_0_SUPPORTED(OF_VERSION_1_4));
    value = OF_OXM_CLASS_NXM_1;
    TEST_ASSERT(!OF_OXM_CLASS_NXM_1_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_OXM_CLASS_NXM_1_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_OXM_CLASS_NXM_1_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_OXM_CLASS_NXM_1_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_OXM_CLASS_NXM_1_SUPPORTED(OF_VERSION_1_4));
    value = OF_OXM_CLASS_OPENFLOW_BASIC;
    TEST_ASSERT(!OF_OXM_CLASS_OPENFLOW_BASIC_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_OXM_CLASS_OPENFLOW_BASIC_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_OXM_CLASS_OPENFLOW_BASIC_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_OXM_CLASS_OPENFLOW_BASIC_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_OXM_CLASS_OPENFLOW_BASIC_SUPPORTED(OF_VERSION_1_4));
    value = OF_OXM_CLASS_EXPERIMENTER;
    TEST_ASSERT(!OF_OXM_CLASS_EXPERIMENTER_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_OXM_CLASS_EXPERIMENTER_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_OXM_CLASS_EXPERIMENTER_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_OXM_CLASS_EXPERIMENTER_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_OXM_CLASS_EXPERIMENTER_SUPPORTED(OF_VERSION_1_4));
    value = OF_VLAN_TAG_PRESENT;
    TEST_ASSERT(!OF_VLAN_TAG_PRESENT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_VLAN_TAG_PRESENT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_VLAN_TAG_PRESENT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_VLAN_TAG_PRESENT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_VLAN_TAG_PRESENT_SUPPORTED(OF_VERSION_1_4));
    value = OF_ACTION_TYPE_SET_FIELD;
    TEST_ASSERT(!OF_ACTION_TYPE_SET_FIELD_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_ACTION_TYPE_SET_FIELD_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ACTION_TYPE_SET_FIELD_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ACTION_TYPE_SET_FIELD_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ACTION_TYPE_SET_FIELD_SUPPORTED(OF_VERSION_1_4));
    value = OF_CONTROLLER_PKT_MAX;
    TEST_ASSERT(!OF_CONTROLLER_PKT_MAX_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_CONTROLLER_PKT_MAX_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_CONTROLLER_PKT_MAX_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_CONTROLLER_PKT_MAX_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_CONTROLLER_PKT_MAX_SUPPORTED(OF_VERSION_1_4));
    value = OF_CONTROLLER_PKT_NO_BUFFER;
    TEST_ASSERT(!OF_CONTROLLER_PKT_NO_BUFFER_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_CONTROLLER_PKT_NO_BUFFER_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_CONTROLLER_PKT_NO_BUFFER_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_CONTROLLER_PKT_NO_BUFFER_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_CONTROLLER_PKT_NO_BUFFER_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_MOD_FLAG_RESET_COUNTS;
    TEST_ASSERT(!OF_FLOW_MOD_FLAG_RESET_COUNTS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_FLOW_MOD_FLAG_RESET_COUNTS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_FLOW_MOD_FLAG_RESET_COUNTS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_FLOW_MOD_FLAG_RESET_COUNTS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_FLOW_MOD_FLAG_RESET_COUNTS_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_FLOW_MOD_FLAG_RESET_COUNTS_SET(flags, OF_VERSION_1_2);
    TEST_ASSERT(flags == OF_FLOW_MOD_FLAG_RESET_COUNTS_BY_VERSION(OF_VERSION_1_2));
    TEST_ASSERT(OF_FLOW_MOD_FLAG_RESET_COUNTS_TEST(flags, OF_VERSION_1_2));
    OF_FLOW_MOD_FLAG_RESET_COUNTS_CLEAR(flags, OF_VERSION_1_2);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_FLOW_MOD_FLAG_RESET_COUNTS_TEST(flags, OF_VERSION_1_2));
    value = OF_PACKET_IN_REASON_INVALID_TTL;
    TEST_ASSERT(!OF_PACKET_IN_REASON_INVALID_TTL_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_PACKET_IN_REASON_INVALID_TTL_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_PACKET_IN_REASON_INVALID_TTL_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PACKET_IN_REASON_INVALID_TTL_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PACKET_IN_REASON_INVALID_TTL_SUPPORTED(OF_VERSION_1_4));
    value = OF_ERROR_TYPE_ROLE_REQUEST_FAILED;
    TEST_ASSERT(!OF_ERROR_TYPE_ROLE_REQUEST_FAILED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_ERROR_TYPE_ROLE_REQUEST_FAILED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ERROR_TYPE_ROLE_REQUEST_FAILED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ERROR_TYPE_ROLE_REQUEST_FAILED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ERROR_TYPE_ROLE_REQUEST_FAILED_SUPPORTED(OF_VERSION_1_4));
    value = OF_ERROR_TYPE_EXPERIMENTER;
    TEST_ASSERT(!OF_ERROR_TYPE_EXPERIMENTER_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_ERROR_TYPE_EXPERIMENTER_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ERROR_TYPE_EXPERIMENTER_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ERROR_TYPE_EXPERIMENTER_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ERROR_TYPE_EXPERIMENTER_SUPPORTED(OF_VERSION_1_4));
    value = OF_REQUEST_FAILED_BAD_EXPERIMENTER_TYPE;
    TEST_ASSERT(!OF_REQUEST_FAILED_BAD_EXPERIMENTER_TYPE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_REQUEST_FAILED_BAD_EXPERIMENTER_TYPE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_REQUEST_FAILED_BAD_EXPERIMENTER_TYPE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_REQUEST_FAILED_BAD_EXPERIMENTER_TYPE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_REQUEST_FAILED_BAD_EXPERIMENTER_TYPE_SUPPORTED(OF_VERSION_1_4));
    value = OF_REQUEST_FAILED_IS_SLAVE;
    TEST_ASSERT(!OF_REQUEST_FAILED_IS_SLAVE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_REQUEST_FAILED_IS_SLAVE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_REQUEST_FAILED_IS_SLAVE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_REQUEST_FAILED_IS_SLAVE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_REQUEST_FAILED_IS_SLAVE_SUPPORTED(OF_VERSION_1_4));
    value = OF_REQUEST_FAILED_BAD_PORT;
    TEST_ASSERT(!OF_REQUEST_FAILED_BAD_PORT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_REQUEST_FAILED_BAD_PORT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_REQUEST_FAILED_BAD_PORT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_REQUEST_FAILED_BAD_PORT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_REQUEST_FAILED_BAD_PORT_SUPPORTED(OF_VERSION_1_4));
    value = OF_REQUEST_FAILED_BAD_PACKET;
    TEST_ASSERT(!OF_REQUEST_FAILED_BAD_PACKET_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_REQUEST_FAILED_BAD_PACKET_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_REQUEST_FAILED_BAD_PACKET_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_REQUEST_FAILED_BAD_PACKET_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_REQUEST_FAILED_BAD_PACKET_SUPPORTED(OF_VERSION_1_4));
    value = OF_ACTION_FAILED_BAD_SET_TYPE;
    TEST_ASSERT(!OF_ACTION_FAILED_BAD_SET_TYPE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_ACTION_FAILED_BAD_SET_TYPE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_SET_TYPE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_SET_TYPE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_SET_TYPE_SUPPORTED(OF_VERSION_1_4));
    value = OF_ACTION_FAILED_BAD_SET_LEN;
    TEST_ASSERT(!OF_ACTION_FAILED_BAD_SET_LEN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_ACTION_FAILED_BAD_SET_LEN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_SET_LEN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_SET_LEN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_SET_LEN_SUPPORTED(OF_VERSION_1_4));
    value = OF_ACTION_FAILED_BAD_SET_ARGUMENT;
    TEST_ASSERT(!OF_ACTION_FAILED_BAD_SET_ARGUMENT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_ACTION_FAILED_BAD_SET_ARGUMENT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_SET_ARGUMENT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_SET_ARGUMENT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ACTION_FAILED_BAD_SET_ARGUMENT_SUPPORTED(OF_VERSION_1_4));
    value = OF_INSTRUCTION_FAILED_BAD_EXPERIMENTER;
    TEST_ASSERT(!OF_INSTRUCTION_FAILED_BAD_EXPERIMENTER_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_INSTRUCTION_FAILED_BAD_EXPERIMENTER_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_INSTRUCTION_FAILED_BAD_EXPERIMENTER_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_INSTRUCTION_FAILED_BAD_EXPERIMENTER_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_INSTRUCTION_FAILED_BAD_EXPERIMENTER_SUPPORTED(OF_VERSION_1_4));
    value = OF_INSTRUCTION_FAILED_BAD_EXPERIMENTER_TYPE;
    TEST_ASSERT(!OF_INSTRUCTION_FAILED_BAD_EXPERIMENTER_TYPE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_INSTRUCTION_FAILED_BAD_EXPERIMENTER_TYPE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_INSTRUCTION_FAILED_BAD_EXPERIMENTER_TYPE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_INSTRUCTION_FAILED_BAD_EXPERIMENTER_TYPE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_INSTRUCTION_FAILED_BAD_EXPERIMENTER_TYPE_SUPPORTED(OF_VERSION_1_4));
    value = OF_INSTRUCTION_FAILED_BAD_LEN;
    TEST_ASSERT(!OF_INSTRUCTION_FAILED_BAD_LEN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_INSTRUCTION_FAILED_BAD_LEN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_INSTRUCTION_FAILED_BAD_LEN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_INSTRUCTION_FAILED_BAD_LEN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_INSTRUCTION_FAILED_BAD_LEN_SUPPORTED(OF_VERSION_1_4));
    value = OF_INSTRUCTION_FAILED_EPERM;
    TEST_ASSERT(!OF_INSTRUCTION_FAILED_EPERM_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_INSTRUCTION_FAILED_EPERM_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_INSTRUCTION_FAILED_EPERM_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_INSTRUCTION_FAILED_EPERM_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_INSTRUCTION_FAILED_EPERM_SUPPORTED(OF_VERSION_1_4));
    value = OF_MATCH_FAILED_BAD_MASK;
    TEST_ASSERT(!OF_MATCH_FAILED_BAD_MASK_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_MATCH_FAILED_BAD_MASK_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_MATCH_FAILED_BAD_MASK_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_MATCH_FAILED_BAD_MASK_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_MATCH_FAILED_BAD_MASK_SUPPORTED(OF_VERSION_1_4));
    value = OF_MATCH_FAILED_BAD_PREREQ;
    TEST_ASSERT(!OF_MATCH_FAILED_BAD_PREREQ_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_MATCH_FAILED_BAD_PREREQ_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_MATCH_FAILED_BAD_PREREQ_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_MATCH_FAILED_BAD_PREREQ_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_MATCH_FAILED_BAD_PREREQ_SUPPORTED(OF_VERSION_1_4));
    value = OF_MATCH_FAILED_DUP_FIELD;
    TEST_ASSERT(!OF_MATCH_FAILED_DUP_FIELD_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_MATCH_FAILED_DUP_FIELD_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_MATCH_FAILED_DUP_FIELD_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_MATCH_FAILED_DUP_FIELD_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_MATCH_FAILED_DUP_FIELD_SUPPORTED(OF_VERSION_1_4));
    value = OF_MATCH_FAILED_EPERM;
    TEST_ASSERT(!OF_MATCH_FAILED_EPERM_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_MATCH_FAILED_EPERM_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_MATCH_FAILED_EPERM_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_MATCH_FAILED_EPERM_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_MATCH_FAILED_EPERM_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_MOD_FAILED_BAD_FLAGS;
    TEST_ASSERT(!OF_FLOW_MOD_FAILED_BAD_FLAGS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_FLOW_MOD_FAILED_BAD_FLAGS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_FLOW_MOD_FAILED_BAD_FLAGS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_FLOW_MOD_FAILED_BAD_FLAGS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_FLOW_MOD_FAILED_BAD_FLAGS_SUPPORTED(OF_VERSION_1_4));
    value = OF_GROUP_MOD_FAILED_CHAINED_GROUP;
    TEST_ASSERT(!OF_GROUP_MOD_FAILED_CHAINED_GROUP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_GROUP_MOD_FAILED_CHAINED_GROUP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_CHAINED_GROUP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_CHAINED_GROUP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_CHAINED_GROUP_SUPPORTED(OF_VERSION_1_4));
    value = OF_GROUP_MOD_FAILED_BAD_TYPE;
    TEST_ASSERT(!OF_GROUP_MOD_FAILED_BAD_TYPE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_GROUP_MOD_FAILED_BAD_TYPE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_BAD_TYPE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_BAD_TYPE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_BAD_TYPE_SUPPORTED(OF_VERSION_1_4));
    value = OF_GROUP_MOD_FAILED_BAD_COMMAND;
    TEST_ASSERT(!OF_GROUP_MOD_FAILED_BAD_COMMAND_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_GROUP_MOD_FAILED_BAD_COMMAND_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_BAD_COMMAND_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_BAD_COMMAND_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_BAD_COMMAND_SUPPORTED(OF_VERSION_1_4));
    value = OF_GROUP_MOD_FAILED_BAD_BUCKET;
    TEST_ASSERT(!OF_GROUP_MOD_FAILED_BAD_BUCKET_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_GROUP_MOD_FAILED_BAD_BUCKET_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_BAD_BUCKET_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_BAD_BUCKET_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_BAD_BUCKET_SUPPORTED(OF_VERSION_1_4));
    value = OF_GROUP_MOD_FAILED_BAD_WATCH;
    TEST_ASSERT(!OF_GROUP_MOD_FAILED_BAD_WATCH_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_GROUP_MOD_FAILED_BAD_WATCH_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_BAD_WATCH_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_BAD_WATCH_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_BAD_WATCH_SUPPORTED(OF_VERSION_1_4));
    value = OF_GROUP_MOD_FAILED_EPERM;
    TEST_ASSERT(!OF_GROUP_MOD_FAILED_EPERM_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_GROUP_MOD_FAILED_EPERM_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_EPERM_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_EPERM_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_GROUP_MOD_FAILED_EPERM_SUPPORTED(OF_VERSION_1_4));
    value = OF_PORT_MOD_FAILED_EPERM;
    TEST_ASSERT(!OF_PORT_MOD_FAILED_EPERM_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_PORT_MOD_FAILED_EPERM_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_PORT_MOD_FAILED_EPERM_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PORT_MOD_FAILED_EPERM_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PORT_MOD_FAILED_EPERM_SUPPORTED(OF_VERSION_1_4));
    value = OF_TABLE_MOD_FAILED_EPERM;
    TEST_ASSERT(!OF_TABLE_MOD_FAILED_EPERM_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_TABLE_MOD_FAILED_EPERM_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_TABLE_MOD_FAILED_EPERM_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_TABLE_MOD_FAILED_EPERM_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_TABLE_MOD_FAILED_EPERM_SUPPORTED(OF_VERSION_1_4));
    value = OF_SWITCH_CONFIG_FAILED_EPERM;
    TEST_ASSERT(!OF_SWITCH_CONFIG_FAILED_EPERM_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_SWITCH_CONFIG_FAILED_EPERM_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_SWITCH_CONFIG_FAILED_EPERM_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_SWITCH_CONFIG_FAILED_EPERM_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_SWITCH_CONFIG_FAILED_EPERM_SUPPORTED(OF_VERSION_1_4));
    value = OF_ROLE_REQUEST_FAILED_STALE;
    TEST_ASSERT(!OF_ROLE_REQUEST_FAILED_STALE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_ROLE_REQUEST_FAILED_STALE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ROLE_REQUEST_FAILED_STALE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ROLE_REQUEST_FAILED_STALE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ROLE_REQUEST_FAILED_STALE_SUPPORTED(OF_VERSION_1_4));
    value = OF_ROLE_REQUEST_FAILED_UNSUP;
    TEST_ASSERT(!OF_ROLE_REQUEST_FAILED_UNSUP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_ROLE_REQUEST_FAILED_UNSUP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ROLE_REQUEST_FAILED_UNSUP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ROLE_REQUEST_FAILED_UNSUP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ROLE_REQUEST_FAILED_UNSUP_SUPPORTED(OF_VERSION_1_4));
    value = OF_ROLE_REQUEST_FAILED_BAD_ROLE;
    TEST_ASSERT(!OF_ROLE_REQUEST_FAILED_BAD_ROLE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_ROLE_REQUEST_FAILED_BAD_ROLE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_ROLE_REQUEST_FAILED_BAD_ROLE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ROLE_REQUEST_FAILED_BAD_ROLE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ROLE_REQUEST_FAILED_BAD_ROLE_SUPPORTED(OF_VERSION_1_4));
    value = OF_STATS_TYPE_GROUP_FEATURES;
    TEST_ASSERT(!OF_STATS_TYPE_GROUP_FEATURES_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_STATS_TYPE_GROUP_FEATURES_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_STATS_TYPE_GROUP_FEATURES_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_STATS_TYPE_GROUP_FEATURES_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_STATS_TYPE_GROUP_FEATURES_SUPPORTED(OF_VERSION_1_4));
    value = OF_GROUP_CAPABILITIES_SELECT_WEIGHT;
    TEST_ASSERT(!OF_GROUP_CAPABILITIES_SELECT_WEIGHT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_GROUP_CAPABILITIES_SELECT_WEIGHT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_GROUP_CAPABILITIES_SELECT_WEIGHT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_GROUP_CAPABILITIES_SELECT_WEIGHT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_GROUP_CAPABILITIES_SELECT_WEIGHT_SUPPORTED(OF_VERSION_1_4));
    value = OF_GROUP_CAPABILITIES_SELECT_LIVENESS;
    TEST_ASSERT(!OF_GROUP_CAPABILITIES_SELECT_LIVENESS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_GROUP_CAPABILITIES_SELECT_LIVENESS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_GROUP_CAPABILITIES_SELECT_LIVENESS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_GROUP_CAPABILITIES_SELECT_LIVENESS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_GROUP_CAPABILITIES_SELECT_LIVENESS_SUPPORTED(OF_VERSION_1_4));
    value = OF_GROUP_CAPABILITIES_CHAINING;
    TEST_ASSERT(!OF_GROUP_CAPABILITIES_CHAINING_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_GROUP_CAPABILITIES_CHAINING_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_GROUP_CAPABILITIES_CHAINING_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_GROUP_CAPABILITIES_CHAINING_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_GROUP_CAPABILITIES_CHAINING_SUPPORTED(OF_VERSION_1_4));
    value = OF_GROUP_CAPABILITIES_CHAINING_CHECKS;
    TEST_ASSERT(!OF_GROUP_CAPABILITIES_CHAINING_CHECKS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_GROUP_CAPABILITIES_CHAINING_CHECKS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_GROUP_CAPABILITIES_CHAINING_CHECKS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_GROUP_CAPABILITIES_CHAINING_CHECKS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_GROUP_CAPABILITIES_CHAINING_CHECKS_SUPPORTED(OF_VERSION_1_4));
    value = OF_QUEUE_PROPERTY_MAX_RATE;
    TEST_ASSERT(!OF_QUEUE_PROPERTY_MAX_RATE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_QUEUE_PROPERTY_MAX_RATE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_QUEUE_PROPERTY_MAX_RATE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_QUEUE_PROPERTY_MAX_RATE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_QUEUE_PROPERTY_MAX_RATE_SUPPORTED(OF_VERSION_1_4));
    value = OF_QUEUE_PROPERTY_EXPERIMENTER;
    TEST_ASSERT(!OF_QUEUE_PROPERTY_EXPERIMENTER_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_QUEUE_PROPERTY_EXPERIMENTER_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_QUEUE_PROPERTY_EXPERIMENTER_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_QUEUE_PROPERTY_EXPERIMENTER_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_QUEUE_PROPERTY_EXPERIMENTER_SUPPORTED(OF_VERSION_1_4));
    value = OF_CONTROLLER_ROLE_NOCHANGE;
    TEST_ASSERT(!OF_CONTROLLER_ROLE_NOCHANGE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_CONTROLLER_ROLE_NOCHANGE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_CONTROLLER_ROLE_NOCHANGE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_CONTROLLER_ROLE_NOCHANGE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_CONTROLLER_ROLE_NOCHANGE_SUPPORTED(OF_VERSION_1_4));
    value = OF_CONTROLLER_ROLE_EQUAL;
    TEST_ASSERT(!OF_CONTROLLER_ROLE_EQUAL_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_CONTROLLER_ROLE_EQUAL_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_CONTROLLER_ROLE_EQUAL_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_CONTROLLER_ROLE_EQUAL_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_CONTROLLER_ROLE_EQUAL_SUPPORTED(OF_VERSION_1_4));
    value = OF_CONTROLLER_ROLE_MASTER;
    TEST_ASSERT(!OF_CONTROLLER_ROLE_MASTER_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_CONTROLLER_ROLE_MASTER_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_CONTROLLER_ROLE_MASTER_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_CONTROLLER_ROLE_MASTER_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_CONTROLLER_ROLE_MASTER_SUPPORTED(OF_VERSION_1_4));
    value = OF_CONTROLLER_ROLE_SLAVE;
    TEST_ASSERT(!OF_CONTROLLER_ROLE_SLAVE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_CONTROLLER_ROLE_SLAVE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(OF_CONTROLLER_ROLE_SLAVE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_CONTROLLER_ROLE_SLAVE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_CONTROLLER_ROLE_SLAVE_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_CONTROLLER_CONNECTION_STATE_DISCONNECTED;
    TEST_ASSERT(!OFP_BSN_CONTROLLER_CONNECTION_STATE_DISCONNECTED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_CONTROLLER_CONNECTION_STATE_DISCONNECTED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_CONTROLLER_CONNECTION_STATE_DISCONNECTED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_CONTROLLER_CONNECTION_STATE_DISCONNECTED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_CONTROLLER_CONNECTION_STATE_DISCONNECTED_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_CONTROLLER_CONNECTION_STATE_CONNECTED;
    TEST_ASSERT(!OFP_BSN_CONTROLLER_CONNECTION_STATE_CONNECTED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_CONTROLLER_CONNECTION_STATE_CONNECTED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_CONTROLLER_CONNECTION_STATE_CONNECTED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_CONTROLLER_CONNECTION_STATE_CONNECTED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_CONTROLLER_CONNECTION_STATE_CONNECTED_SUPPORTED(OF_VERSION_1_4));
    value = OF_BSN_GENTABLE_ERROR_UNKNOWN;
    TEST_ASSERT(!OF_BSN_GENTABLE_ERROR_UNKNOWN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_BSN_GENTABLE_ERROR_UNKNOWN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_BSN_GENTABLE_ERROR_UNKNOWN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_BSN_GENTABLE_ERROR_UNKNOWN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_BSN_GENTABLE_ERROR_UNKNOWN_SUPPORTED(OF_VERSION_1_4));
    value = OF_BSN_GENTABLE_ERROR_PARAM;
    TEST_ASSERT(!OF_BSN_GENTABLE_ERROR_PARAM_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_BSN_GENTABLE_ERROR_PARAM_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_BSN_GENTABLE_ERROR_PARAM_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_BSN_GENTABLE_ERROR_PARAM_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_BSN_GENTABLE_ERROR_PARAM_SUPPORTED(OF_VERSION_1_4));
    value = OF_BSN_GENTABLE_ERROR_TABLE_FULL;
    TEST_ASSERT(!OF_BSN_GENTABLE_ERROR_TABLE_FULL_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_BSN_GENTABLE_ERROR_TABLE_FULL_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_BSN_GENTABLE_ERROR_TABLE_FULL_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_BSN_GENTABLE_ERROR_TABLE_FULL_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_BSN_GENTABLE_ERROR_TABLE_FULL_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_HASH_SELECT_SRC_IP;
    TEST_ASSERT(!OFP_BSN_HASH_SELECT_SRC_IP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_HASH_SELECT_SRC_IP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_HASH_SELECT_SRC_IP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_HASH_SELECT_SRC_IP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_HASH_SELECT_SRC_IP_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_HASH_SELECT_DST_IP;
    TEST_ASSERT(!OFP_BSN_HASH_SELECT_DST_IP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_HASH_SELECT_DST_IP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_HASH_SELECT_DST_IP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_HASH_SELECT_DST_IP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_HASH_SELECT_DST_IP_SUPPORTED(OF_VERSION_1_4));
    value = LACP_SUCCESS;
    TEST_ASSERT(!LACP_SUCCESS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!LACP_SUCCESS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!LACP_SUCCESS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(LACP_SUCCESS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(LACP_SUCCESS_SUPPORTED(OF_VERSION_1_4));
    value = LACP_TIMEDOUT;
    TEST_ASSERT(!LACP_TIMEDOUT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!LACP_TIMEDOUT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!LACP_TIMEDOUT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(LACP_TIMEDOUT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(LACP_TIMEDOUT_SUPPORTED(OF_VERSION_1_4));
    value = LACP_OUT_OF_SYNC;
    TEST_ASSERT(!LACP_OUT_OF_SYNC_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!LACP_OUT_OF_SYNC_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!LACP_OUT_OF_SYNC_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(LACP_OUT_OF_SYNC_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(LACP_OUT_OF_SYNC_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_LOGLEVEL_MSG;
    TEST_ASSERT(!OFP_BSN_LOGLEVEL_MSG_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_LOGLEVEL_MSG_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_LOGLEVEL_MSG_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_LOGLEVEL_MSG_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_LOGLEVEL_MSG_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_LOGLEVEL_ERROR;
    TEST_ASSERT(!OFP_BSN_LOGLEVEL_ERROR_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_LOGLEVEL_ERROR_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_LOGLEVEL_ERROR_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_LOGLEVEL_ERROR_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_LOGLEVEL_ERROR_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_LOGLEVEL_WARN;
    TEST_ASSERT(!OFP_BSN_LOGLEVEL_WARN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_LOGLEVEL_WARN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_LOGLEVEL_WARN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_LOGLEVEL_WARN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_LOGLEVEL_WARN_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_LOGLEVEL_INFO;
    TEST_ASSERT(!OFP_BSN_LOGLEVEL_INFO_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_LOGLEVEL_INFO_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_LOGLEVEL_INFO_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_LOGLEVEL_INFO_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_LOGLEVEL_INFO_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_LOGLEVEL_VERBOSE;
    TEST_ASSERT(!OFP_BSN_LOGLEVEL_VERBOSE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_LOGLEVEL_VERBOSE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_LOGLEVEL_VERBOSE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_LOGLEVEL_VERBOSE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_LOGLEVEL_VERBOSE_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_LOGLEVEL_TRACE;
    TEST_ASSERT(!OFP_BSN_LOGLEVEL_TRACE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_LOGLEVEL_TRACE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_LOGLEVEL_TRACE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_LOGLEVEL_TRACE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_LOGLEVEL_TRACE_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_LUA_UPLOAD_MORE;
    TEST_ASSERT(!OFP_BSN_LUA_UPLOAD_MORE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_LUA_UPLOAD_MORE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_LUA_UPLOAD_MORE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_LUA_UPLOAD_MORE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_LUA_UPLOAD_MORE_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_LUA_UPLOAD_FORCE;
    TEST_ASSERT(!OFP_BSN_LUA_UPLOAD_FORCE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_LUA_UPLOAD_FORCE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_LUA_UPLOAD_FORCE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_LUA_UPLOAD_FORCE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_LUA_UPLOAD_FORCE_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PKTIN_FLAG_PDU;
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_PDU_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_PDU_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_PDU_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_PDU_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_PDU_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_BSN_PKTIN_FLAG_PDU_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OFP_BSN_PKTIN_FLAG_PDU_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_PDU_TEST(flags, OF_VERSION_1_3));
    OFP_BSN_PKTIN_FLAG_PDU_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_PDU_TEST(flags, OF_VERSION_1_3));
    value = OFP_BSN_PKTIN_FLAG_NEW_HOST;
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_NEW_HOST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_NEW_HOST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_NEW_HOST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_NEW_HOST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_NEW_HOST_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_BSN_PKTIN_FLAG_NEW_HOST_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OFP_BSN_PKTIN_FLAG_NEW_HOST_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_NEW_HOST_TEST(flags, OF_VERSION_1_3));
    OFP_BSN_PKTIN_FLAG_NEW_HOST_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_NEW_HOST_TEST(flags, OF_VERSION_1_3));
    value = OFP_BSN_PKTIN_FLAG_STATION_MOVE;
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_STATION_MOVE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_STATION_MOVE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_STATION_MOVE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_STATION_MOVE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_STATION_MOVE_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_BSN_PKTIN_FLAG_STATION_MOVE_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OFP_BSN_PKTIN_FLAG_STATION_MOVE_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_STATION_MOVE_TEST(flags, OF_VERSION_1_3));
    OFP_BSN_PKTIN_FLAG_STATION_MOVE_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_STATION_MOVE_TEST(flags, OF_VERSION_1_3));
    value = OFP_BSN_PKTIN_FLAG_ARP;
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_ARP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_ARP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_ARP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_ARP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_ARP_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_BSN_PKTIN_FLAG_ARP_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OFP_BSN_PKTIN_FLAG_ARP_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_ARP_TEST(flags, OF_VERSION_1_3));
    OFP_BSN_PKTIN_FLAG_ARP_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_ARP_TEST(flags, OF_VERSION_1_3));
    value = OFP_BSN_PKTIN_FLAG_DHCP;
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_DHCP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_DHCP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_DHCP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_DHCP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_DHCP_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_BSN_PKTIN_FLAG_DHCP_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OFP_BSN_PKTIN_FLAG_DHCP_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_DHCP_TEST(flags, OF_VERSION_1_3));
    OFP_BSN_PKTIN_FLAG_DHCP_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_DHCP_TEST(flags, OF_VERSION_1_3));
    value = OFP_BSN_PKTIN_FLAG_L2_CPU;
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_L2_CPU_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_L2_CPU_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_L2_CPU_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_L2_CPU_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_L2_CPU_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_BSN_PKTIN_FLAG_L2_CPU_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OFP_BSN_PKTIN_FLAG_L2_CPU_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_L2_CPU_TEST(flags, OF_VERSION_1_3));
    OFP_BSN_PKTIN_FLAG_L2_CPU_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_L2_CPU_TEST(flags, OF_VERSION_1_3));
    value = OFP_BSN_PKTIN_FLAG_DEBUG;
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_DEBUG_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_DEBUG_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_DEBUG_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_DEBUG_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_DEBUG_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_BSN_PKTIN_FLAG_DEBUG_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OFP_BSN_PKTIN_FLAG_DEBUG_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_DEBUG_TEST(flags, OF_VERSION_1_3));
    OFP_BSN_PKTIN_FLAG_DEBUG_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_DEBUG_TEST(flags, OF_VERSION_1_3));
    value = OFP_BSN_PKTIN_FLAG_TTL_EXPIRED;
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_TTL_EXPIRED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_TTL_EXPIRED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_TTL_EXPIRED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_TTL_EXPIRED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_TTL_EXPIRED_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_BSN_PKTIN_FLAG_TTL_EXPIRED_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OFP_BSN_PKTIN_FLAG_TTL_EXPIRED_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_TTL_EXPIRED_TEST(flags, OF_VERSION_1_3));
    OFP_BSN_PKTIN_FLAG_TTL_EXPIRED_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_TTL_EXPIRED_TEST(flags, OF_VERSION_1_3));
    value = OFP_BSN_PKTIN_FLAG_L3_MISS;
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_L3_MISS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_L3_MISS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_L3_MISS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_L3_MISS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_L3_MISS_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_BSN_PKTIN_FLAG_L3_MISS_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OFP_BSN_PKTIN_FLAG_L3_MISS_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_L3_MISS_TEST(flags, OF_VERSION_1_3));
    OFP_BSN_PKTIN_FLAG_L3_MISS_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_L3_MISS_TEST(flags, OF_VERSION_1_3));
    value = OFP_BSN_PKTIN_FLAG_L3_CPU;
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_L3_CPU_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_L3_CPU_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_L3_CPU_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_L3_CPU_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_L3_CPU_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_BSN_PKTIN_FLAG_L3_CPU_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OFP_BSN_PKTIN_FLAG_L3_CPU_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_L3_CPU_TEST(flags, OF_VERSION_1_3));
    OFP_BSN_PKTIN_FLAG_L3_CPU_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_L3_CPU_TEST(flags, OF_VERSION_1_3));
    value = OFP_BSN_PKTIN_FLAG_INGRESS_ACL;
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_INGRESS_ACL_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_INGRESS_ACL_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_INGRESS_ACL_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_INGRESS_ACL_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_INGRESS_ACL_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_BSN_PKTIN_FLAG_INGRESS_ACL_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OFP_BSN_PKTIN_FLAG_INGRESS_ACL_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_INGRESS_ACL_TEST(flags, OF_VERSION_1_3));
    OFP_BSN_PKTIN_FLAG_INGRESS_ACL_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_INGRESS_ACL_TEST(flags, OF_VERSION_1_3));
    value = OFP_BSN_PKTIN_FLAG_SFLOW;
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_SFLOW_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_SFLOW_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_SFLOW_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_SFLOW_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_SFLOW_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_BSN_PKTIN_FLAG_SFLOW_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OFP_BSN_PKTIN_FLAG_SFLOW_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_SFLOW_TEST(flags, OF_VERSION_1_3));
    OFP_BSN_PKTIN_FLAG_SFLOW_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_SFLOW_TEST(flags, OF_VERSION_1_3));
    value = OFP_BSN_PKTIN_FLAG_ARP_CACHE;
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_ARP_CACHE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_ARP_CACHE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_ARP_CACHE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_ARP_CACHE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_ARP_CACHE_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_BSN_PKTIN_FLAG_ARP_CACHE_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OFP_BSN_PKTIN_FLAG_ARP_CACHE_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_ARP_CACHE_TEST(flags, OF_VERSION_1_3));
    OFP_BSN_PKTIN_FLAG_ARP_CACHE_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_ARP_CACHE_TEST(flags, OF_VERSION_1_3));
    value = OFP_BSN_PKTIN_FLAG_ARP_TARGET;
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_ARP_TARGET_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_ARP_TARGET_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_ARP_TARGET_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_ARP_TARGET_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_ARP_TARGET_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_BSN_PKTIN_FLAG_ARP_TARGET_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OFP_BSN_PKTIN_FLAG_ARP_TARGET_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_ARP_TARGET_TEST(flags, OF_VERSION_1_3));
    OFP_BSN_PKTIN_FLAG_ARP_TARGET_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_ARP_TARGET_TEST(flags, OF_VERSION_1_3));
    value = OFP_BSN_PKTIN_FLAG_IGMP;
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_IGMP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_IGMP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_IGMP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_IGMP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_IGMP_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_BSN_PKTIN_FLAG_IGMP_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OFP_BSN_PKTIN_FLAG_IGMP_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_IGMP_TEST(flags, OF_VERSION_1_3));
    OFP_BSN_PKTIN_FLAG_IGMP_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_IGMP_TEST(flags, OF_VERSION_1_3));
    value = OFP_BSN_PKTIN_FLAG_PIM;
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_PIM_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_PIM_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_PIM_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_PIM_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_PIM_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_BSN_PKTIN_FLAG_PIM_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OFP_BSN_PKTIN_FLAG_PIM_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_PIM_TEST(flags, OF_VERSION_1_3));
    OFP_BSN_PKTIN_FLAG_PIM_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_PIM_TEST(flags, OF_VERSION_1_3));
    value = OFP_BSN_PKTIN_FLAG_VXLAN_SIP_MISS;
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_VXLAN_SIP_MISS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_VXLAN_SIP_MISS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_VXLAN_SIP_MISS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_VXLAN_SIP_MISS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_VXLAN_SIP_MISS_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_BSN_PKTIN_FLAG_VXLAN_SIP_MISS_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OFP_BSN_PKTIN_FLAG_VXLAN_SIP_MISS_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_VXLAN_SIP_MISS_TEST(flags, OF_VERSION_1_3));
    OFP_BSN_PKTIN_FLAG_VXLAN_SIP_MISS_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_VXLAN_SIP_MISS_TEST(flags, OF_VERSION_1_3));
    value = OFP_BSN_PKTIN_FLAG_MC_RESERVED;
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_MC_RESERVED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_MC_RESERVED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_MC_RESERVED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_MC_RESERVED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_MC_RESERVED_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_BSN_PKTIN_FLAG_MC_RESERVED_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OFP_BSN_PKTIN_FLAG_MC_RESERVED_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_MC_RESERVED_TEST(flags, OF_VERSION_1_3));
    OFP_BSN_PKTIN_FLAG_MC_RESERVED_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_MC_RESERVED_TEST(flags, OF_VERSION_1_3));
    value = OFP_BSN_PKTIN_FLAG_ANALYTICS;
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_ANALYTICS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_ANALYTICS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_ANALYTICS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_ANALYTICS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_ANALYTICS_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_BSN_PKTIN_FLAG_ANALYTICS_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OFP_BSN_PKTIN_FLAG_ANALYTICS_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_ANALYTICS_TEST(flags, OF_VERSION_1_3));
    OFP_BSN_PKTIN_FLAG_ANALYTICS_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_ANALYTICS_TEST(flags, OF_VERSION_1_3));
    value = OFP_BSN_PKTIN_FLAG_ICMPV6;
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_ICMPV6_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_ICMPV6_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_ICMPV6_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_ICMPV6_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_ICMPV6_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_BSN_PKTIN_FLAG_ICMPV6_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OFP_BSN_PKTIN_FLAG_ICMPV6_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_ICMPV6_TEST(flags, OF_VERSION_1_3));
    OFP_BSN_PKTIN_FLAG_ICMPV6_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_ICMPV6_TEST(flags, OF_VERSION_1_3));
    value = OFP_BSN_PKTIN_FLAG_INGRESS_ACL_LOCAL;
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_INGRESS_ACL_LOCAL_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_INGRESS_ACL_LOCAL_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_INGRESS_ACL_LOCAL_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_INGRESS_ACL_LOCAL_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_INGRESS_ACL_LOCAL_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_BSN_PKTIN_FLAG_INGRESS_ACL_LOCAL_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OFP_BSN_PKTIN_FLAG_INGRESS_ACL_LOCAL_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_INGRESS_ACL_LOCAL_TEST(flags, OF_VERSION_1_3));
    OFP_BSN_PKTIN_FLAG_INGRESS_ACL_LOCAL_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_INGRESS_ACL_LOCAL_TEST(flags, OF_VERSION_1_3));
    value = OFP_BSN_PKTIN_FLAG_IPMC_MISS;
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_IPMC_MISS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_IPMC_MISS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_IPMC_MISS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_IPMC_MISS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_IPMC_MISS_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_BSN_PKTIN_FLAG_IPMC_MISS_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OFP_BSN_PKTIN_FLAG_IPMC_MISS_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_IPMC_MISS_TEST(flags, OF_VERSION_1_3));
    OFP_BSN_PKTIN_FLAG_IPMC_MISS_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_IPMC_MISS_TEST(flags, OF_VERSION_1_3));
    value = OFP_BSN_PKTIN_FLAG_IPMC_RPF_FAILED;
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_IPMC_RPF_FAILED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_IPMC_RPF_FAILED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_IPMC_RPF_FAILED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_IPMC_RPF_FAILED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_IPMC_RPF_FAILED_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_BSN_PKTIN_FLAG_IPMC_RPF_FAILED_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OFP_BSN_PKTIN_FLAG_IPMC_RPF_FAILED_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_IPMC_RPF_FAILED_TEST(flags, OF_VERSION_1_3));
    OFP_BSN_PKTIN_FLAG_IPMC_RPF_FAILED_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_IPMC_RPF_FAILED_TEST(flags, OF_VERSION_1_3));
    value = OFP_BSN_PKTIN_FLAG_BFD_SLOWPATH;
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_BFD_SLOWPATH_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_BFD_SLOWPATH_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_BFD_SLOWPATH_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_BFD_SLOWPATH_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_BFD_SLOWPATH_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_BSN_PKTIN_FLAG_BFD_SLOWPATH_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OFP_BSN_PKTIN_FLAG_BFD_SLOWPATH_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_BFD_SLOWPATH_TEST(flags, OF_VERSION_1_3));
    OFP_BSN_PKTIN_FLAG_BFD_SLOWPATH_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_BFD_SLOWPATH_TEST(flags, OF_VERSION_1_3));
    value = OFP_BSN_PKTIN_FLAG_SFLOW_EGRESS;
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_SFLOW_EGRESS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_SFLOW_EGRESS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_SFLOW_EGRESS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_SFLOW_EGRESS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_SFLOW_EGRESS_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_BSN_PKTIN_FLAG_SFLOW_EGRESS_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OFP_BSN_PKTIN_FLAG_SFLOW_EGRESS_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PKTIN_FLAG_SFLOW_EGRESS_TEST(flags, OF_VERSION_1_3));
    OFP_BSN_PKTIN_FLAG_SFLOW_EGRESS_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_BSN_PKTIN_FLAG_SFLOW_EGRESS_TEST(flags, OF_VERSION_1_3));
    value = OFP_BSN_PORT_COUNTER_RX_BYTES;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_BYTES_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_BYTES_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_BYTES_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_BYTES_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_BYTES_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_RX_PACKETS_UNICAST;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PACKETS_UNICAST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PACKETS_UNICAST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PACKETS_UNICAST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PACKETS_UNICAST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PACKETS_UNICAST_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_RX_PACKETS_BROADCAST;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PACKETS_BROADCAST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PACKETS_BROADCAST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PACKETS_BROADCAST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PACKETS_BROADCAST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PACKETS_BROADCAST_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_RX_PACKETS_MULTICAST;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PACKETS_MULTICAST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PACKETS_MULTICAST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PACKETS_MULTICAST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PACKETS_MULTICAST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PACKETS_MULTICAST_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_RX_DROPPED;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_DROPPED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_DROPPED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_DROPPED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_DROPPED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_DROPPED_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_RX_ERRORS;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_ERRORS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_ERRORS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_ERRORS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_ERRORS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_ERRORS_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_TX_BYTES;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_BYTES_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_BYTES_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_BYTES_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_TX_BYTES_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_TX_BYTES_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_TX_PACKETS_UNICAST;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_PACKETS_UNICAST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_PACKETS_UNICAST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_PACKETS_UNICAST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_TX_PACKETS_UNICAST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_TX_PACKETS_UNICAST_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_TX_PACKETS_BROADCAST;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_PACKETS_BROADCAST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_PACKETS_BROADCAST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_PACKETS_BROADCAST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_TX_PACKETS_BROADCAST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_TX_PACKETS_BROADCAST_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_TX_PACKETS_MULTICAST;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_PACKETS_MULTICAST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_PACKETS_MULTICAST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_PACKETS_MULTICAST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_TX_PACKETS_MULTICAST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_TX_PACKETS_MULTICAST_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_TX_DROPPED;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_DROPPED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_DROPPED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_DROPPED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_TX_DROPPED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_TX_DROPPED_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_TX_ERRORS;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_ERRORS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_ERRORS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_ERRORS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_TX_ERRORS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_TX_ERRORS_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_RX_RUNTS;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_RUNTS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_RUNTS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_RUNTS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_RUNTS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_RUNTS_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_RX_GIANTS;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_GIANTS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_GIANTS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_GIANTS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_GIANTS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_GIANTS_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_RX_CRC_ERRORS;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_CRC_ERRORS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_CRC_ERRORS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_CRC_ERRORS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_CRC_ERRORS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_CRC_ERRORS_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_RX_ALIGNMENT_ERRORS;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_ALIGNMENT_ERRORS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_ALIGNMENT_ERRORS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_ALIGNMENT_ERRORS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_ALIGNMENT_ERRORS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_ALIGNMENT_ERRORS_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_RX_SYMBOL_ERRORS;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_SYMBOL_ERRORS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_SYMBOL_ERRORS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_SYMBOL_ERRORS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_SYMBOL_ERRORS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_SYMBOL_ERRORS_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_RX_PAUSE_INPUT;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PAUSE_INPUT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PAUSE_INPUT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PAUSE_INPUT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PAUSE_INPUT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PAUSE_INPUT_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_TX_COLLISIONS;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_COLLISIONS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_COLLISIONS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_COLLISIONS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_TX_COLLISIONS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_TX_COLLISIONS_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_TX_LATE_COLLISIONS;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_LATE_COLLISIONS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_LATE_COLLISIONS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_LATE_COLLISIONS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_TX_LATE_COLLISIONS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_TX_LATE_COLLISIONS_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_TX_DEFERRED;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_DEFERRED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_DEFERRED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_DEFERRED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_TX_DEFERRED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_TX_DEFERRED_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_TX_PAUSE_OUTPUT;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_PAUSE_OUTPUT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_PAUSE_OUTPUT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_PAUSE_OUTPUT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_TX_PAUSE_OUTPUT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_TX_PAUSE_OUTPUT_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_RX_PACKETS;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PACKETS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PACKETS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PACKETS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PACKETS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PACKETS_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_TX_PACKETS;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_PACKETS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_PACKETS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_PACKETS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_TX_PACKETS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_TX_PACKETS_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_RX_LENGTH_ERRORS;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_LENGTH_ERRORS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_LENGTH_ERRORS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_LENGTH_ERRORS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_LENGTH_ERRORS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_LENGTH_ERRORS_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_RX_OVERFLOW_ERRORS;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_OVERFLOW_ERRORS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_OVERFLOW_ERRORS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_OVERFLOW_ERRORS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_OVERFLOW_ERRORS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_OVERFLOW_ERRORS_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_TX_CARRIER_ERRORS;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_CARRIER_ERRORS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_CARRIER_ERRORS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_CARRIER_ERRORS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_TX_CARRIER_ERRORS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_TX_CARRIER_ERRORS_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_RX_PACKETS_BAD_VLAN;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PACKETS_BAD_VLAN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PACKETS_BAD_VLAN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PACKETS_BAD_VLAN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PACKETS_BAD_VLAN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PACKETS_BAD_VLAN_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_LINK_UP;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_LINK_UP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_LINK_UP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_LINK_UP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_LINK_UP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_LINK_UP_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_LINK_DOWN;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_LINK_DOWN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_LINK_DOWN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_LINK_DOWN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_LINK_DOWN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_LINK_DOWN_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_RX_PFC_CONTROL_FRAME;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_CONTROL_FRAME_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_CONTROL_FRAME_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_CONTROL_FRAME_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PFC_CONTROL_FRAME_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PFC_CONTROL_FRAME_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_TX_PFC_CONTROL_FRAME;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_PFC_CONTROL_FRAME_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_PFC_CONTROL_FRAME_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_PFC_CONTROL_FRAME_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_TX_PFC_CONTROL_FRAME_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_TX_PFC_CONTROL_FRAME_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_0;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_0_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_0_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_0_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_0_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_0_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_1;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_1_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_1_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_1_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_1_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_1_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_2;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_2_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_2_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_2_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_2_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_2_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_3;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_3_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_3_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_3_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_3_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_3_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_4;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_4_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_4_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_4_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_4_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_4_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_5;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_5_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_5_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_5_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_5_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_5_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_6;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_6_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_6_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_6_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_6_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_6_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_7;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_7_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_7_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_7_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_7_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_XON_PRIORITY_7_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_0;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_0_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_0_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_0_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_0_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_0_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_1;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_1_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_1_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_1_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_1_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_1_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_2;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_2_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_2_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_2_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_2_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_2_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_3;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_3_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_3_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_3_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_3_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_3_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_4;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_4_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_4_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_4_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_4_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_4_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_5;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_5_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_5_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_5_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_5_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_5_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_6;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_6_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_6_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_6_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_6_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_6_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_7;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_7_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_7_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_7_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_7_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_RX_PFC_FRAME_PRIORITY_7_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_0;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_0_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_0_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_0_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_0_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_0_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_1;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_1_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_1_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_1_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_1_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_1_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_2;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_2_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_2_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_2_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_2_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_2_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_3;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_3_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_3_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_3_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_3_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_3_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_4;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_4_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_4_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_4_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_4_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_4_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_5;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_5_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_5_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_5_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_5_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_5_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_6;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_6_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_6_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_6_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_6_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_6_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_7;
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_7_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_7_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_7_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_7_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_COUNTER_TX_PFC_FRAME_PRIORITY_7_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_CONTROLLER_ROLE_REASON_MASTER_REQUEST;
    TEST_ASSERT(!OFP_BSN_CONTROLLER_ROLE_REASON_MASTER_REQUEST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_CONTROLLER_ROLE_REASON_MASTER_REQUEST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_CONTROLLER_ROLE_REASON_MASTER_REQUEST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_CONTROLLER_ROLE_REASON_MASTER_REQUEST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OFP_BSN_CONTROLLER_ROLE_REASON_MASTER_REQUEST_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_CONTROLLER_ROLE_REASON_CONFIG;
    TEST_ASSERT(!OFP_BSN_CONTROLLER_ROLE_REASON_CONFIG_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_CONTROLLER_ROLE_REASON_CONFIG_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_CONTROLLER_ROLE_REASON_CONFIG_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_CONTROLLER_ROLE_REASON_CONFIG_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OFP_BSN_CONTROLLER_ROLE_REASON_CONFIG_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_CONTROLLER_ROLE_REASON_EXPERIMENTER;
    TEST_ASSERT(!OFP_BSN_CONTROLLER_ROLE_REASON_EXPERIMENTER_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_CONTROLLER_ROLE_REASON_EXPERIMENTER_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_CONTROLLER_ROLE_REASON_EXPERIMENTER_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_CONTROLLER_ROLE_REASON_EXPERIMENTER_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OFP_BSN_CONTROLLER_ROLE_REASON_EXPERIMENTER_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_UDF_ANCHOR_PACKET_START;
    TEST_ASSERT(!OFP_BSN_UDF_ANCHOR_PACKET_START_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_UDF_ANCHOR_PACKET_START_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_UDF_ANCHOR_PACKET_START_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_UDF_ANCHOR_PACKET_START_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_UDF_ANCHOR_PACKET_START_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_UDF_ANCHOR_L3_HEADER_START;
    TEST_ASSERT(!OFP_BSN_UDF_ANCHOR_L3_HEADER_START_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_UDF_ANCHOR_L3_HEADER_START_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_UDF_ANCHOR_L3_HEADER_START_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_UDF_ANCHOR_L3_HEADER_START_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_UDF_ANCHOR_L3_HEADER_START_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_UDF_ANCHOR_L4_HEADER_START;
    TEST_ASSERT(!OFP_BSN_UDF_ANCHOR_L4_HEADER_START_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_UDF_ANCHOR_L4_HEADER_START_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_UDF_ANCHOR_L4_HEADER_START_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_UDF_ANCHOR_L4_HEADER_START_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_UDF_ANCHOR_L4_HEADER_START_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_LACP_STATE_ACTIVITY;
    TEST_ASSERT(!OFP_BSN_LACP_STATE_ACTIVITY_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_LACP_STATE_ACTIVITY_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_LACP_STATE_ACTIVITY_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_LACP_STATE_ACTIVITY_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_LACP_STATE_ACTIVITY_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_LACP_STATE_TIMEOUT;
    TEST_ASSERT(!OFP_BSN_LACP_STATE_TIMEOUT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_LACP_STATE_TIMEOUT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_LACP_STATE_TIMEOUT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_LACP_STATE_TIMEOUT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_LACP_STATE_TIMEOUT_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_LACP_STATE_AGGREGATION;
    TEST_ASSERT(!OFP_BSN_LACP_STATE_AGGREGATION_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_LACP_STATE_AGGREGATION_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_LACP_STATE_AGGREGATION_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_LACP_STATE_AGGREGATION_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_LACP_STATE_AGGREGATION_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_LACP_STATE_SYNCHRONIZATION;
    TEST_ASSERT(!OFP_BSN_LACP_STATE_SYNCHRONIZATION_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_LACP_STATE_SYNCHRONIZATION_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_LACP_STATE_SYNCHRONIZATION_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_LACP_STATE_SYNCHRONIZATION_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_LACP_STATE_SYNCHRONIZATION_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_LACP_STATE_COLLECTING;
    TEST_ASSERT(!OFP_BSN_LACP_STATE_COLLECTING_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_LACP_STATE_COLLECTING_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_LACP_STATE_COLLECTING_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_LACP_STATE_COLLECTING_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_LACP_STATE_COLLECTING_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_LACP_STATE_DISTRIBUTING;
    TEST_ASSERT(!OFP_BSN_LACP_STATE_DISTRIBUTING_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_LACP_STATE_DISTRIBUTING_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_LACP_STATE_DISTRIBUTING_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_LACP_STATE_DISTRIBUTING_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_LACP_STATE_DISTRIBUTING_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_LACP_STATE_DEFAULTED;
    TEST_ASSERT(!OFP_BSN_LACP_STATE_DEFAULTED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_LACP_STATE_DEFAULTED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_LACP_STATE_DEFAULTED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_LACP_STATE_DEFAULTED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_LACP_STATE_DEFAULTED_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_LACP_STATE_EXPIRED;
    TEST_ASSERT(!OFP_BSN_LACP_STATE_EXPIRED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_LACP_STATE_EXPIRED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_LACP_STATE_EXPIRED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_LACP_STATE_EXPIRED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_LACP_STATE_EXPIRED_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_STRIP_VLAN_FIRST;
    TEST_ASSERT(!OFP_BSN_STRIP_VLAN_FIRST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_STRIP_VLAN_FIRST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_STRIP_VLAN_FIRST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_STRIP_VLAN_FIRST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_STRIP_VLAN_FIRST_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_STRIP_VLAN_SECOND;
    TEST_ASSERT(!OFP_BSN_STRIP_VLAN_SECOND_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_STRIP_VLAN_SECOND_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_STRIP_VLAN_SECOND_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_STRIP_VLAN_SECOND_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_STRIP_VLAN_SECOND_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_STRIP_VLAN_THIRD;
    TEST_ASSERT(!OFP_BSN_STRIP_VLAN_THIRD_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_STRIP_VLAN_THIRD_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_STRIP_VLAN_THIRD_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_STRIP_VLAN_THIRD_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_STRIP_VLAN_THIRD_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_ANCHOR_PACKET_START;
    TEST_ASSERT(!OFP_BSN_ANCHOR_PACKET_START_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_ANCHOR_PACKET_START_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_ANCHOR_PACKET_START_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_ANCHOR_PACKET_START_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_ANCHOR_PACKET_START_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_ANCHOR_L3_HEADER_START;
    TEST_ASSERT(!OFP_BSN_ANCHOR_L3_HEADER_START_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_ANCHOR_L3_HEADER_START_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_ANCHOR_L3_HEADER_START_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_ANCHOR_L3_HEADER_START_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_ANCHOR_L3_HEADER_START_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_ANCHOR_L4_HEADER_START;
    TEST_ASSERT(!OFP_BSN_ANCHOR_L4_HEADER_START_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_ANCHOR_L4_HEADER_START_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_ANCHOR_L4_HEADER_START_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_ANCHOR_L4_HEADER_START_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_ANCHOR_L4_HEADER_START_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_ANCHOR_L4_PAYLOAD_START;
    TEST_ASSERT(!OFP_BSN_ANCHOR_L4_PAYLOAD_START_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_ANCHOR_L4_PAYLOAD_START_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_ANCHOR_L4_PAYLOAD_START_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_ANCHOR_L4_PAYLOAD_START_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_ANCHOR_L4_PAYLOAD_START_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_DECAP_VXLAN;
    TEST_ASSERT(!OFP_BSN_DECAP_VXLAN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_DECAP_VXLAN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_DECAP_VXLAN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_DECAP_VXLAN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_DECAP_VXLAN_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_DECAP_ERSPAN;
    TEST_ASSERT(!OFP_BSN_DECAP_ERSPAN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_DECAP_ERSPAN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_DECAP_ERSPAN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_DECAP_ERSPAN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_DECAP_ERSPAN_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_DECAP_L2_GRE;
    TEST_ASSERT(!OFP_BSN_DECAP_L2_GRE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_DECAP_L2_GRE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_DECAP_L2_GRE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_DECAP_L2_GRE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_DECAP_L2_GRE_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_DECAP_NVGRE;
    TEST_ASSERT(!OFP_BSN_DECAP_NVGRE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_DECAP_NVGRE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_DECAP_NVGRE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_DECAP_NVGRE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_DECAP_NVGRE_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_DECAP_CAPWAP;
    TEST_ASSERT(!OFP_BSN_DECAP_CAPWAP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_DECAP_CAPWAP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_DECAP_CAPWAP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_DECAP_CAPWAP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_DECAP_CAPWAP_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_DECAP_L2_MPLS;
    TEST_ASSERT(!OFP_BSN_DECAP_L2_MPLS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_DECAP_L2_MPLS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_DECAP_L2_MPLS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_DECAP_L2_MPLS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_DECAP_L2_MPLS_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_DECAP_L3_GRE;
    TEST_ASSERT(!OFP_BSN_DECAP_L3_GRE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_DECAP_L3_GRE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_DECAP_L3_GRE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_DECAP_L3_GRE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_DECAP_L3_GRE_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_DECAP_GTP;
    TEST_ASSERT(!OFP_BSN_DECAP_GTP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_DECAP_GTP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_DECAP_GTP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_DECAP_GTP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_DECAP_GTP_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_DECAP_L3_MPLS;
    TEST_ASSERT(!OFP_BSN_DECAP_L3_MPLS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_DECAP_L3_MPLS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_DECAP_L3_MPLS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_DECAP_L3_MPLS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_DECAP_L3_MPLS_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_VXLAN_RECIRCULATION_ENABLE;
    TEST_ASSERT(!OFP_BSN_PORT_VXLAN_RECIRCULATION_ENABLE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_VXLAN_RECIRCULATION_ENABLE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_VXLAN_RECIRCULATION_ENABLE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_VXLAN_RECIRCULATION_ENABLE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_VXLAN_RECIRCULATION_ENABLE_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_VXLAN_TERMINATION_ENABLE;
    TEST_ASSERT(!OFP_BSN_PORT_VXLAN_TERMINATION_ENABLE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_VXLAN_TERMINATION_ENABLE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_VXLAN_TERMINATION_ENABLE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_VXLAN_TERMINATION_ENABLE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_VXLAN_TERMINATION_ENABLE_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_RATE_UNIT_PPS;
    TEST_ASSERT(!OFP_BSN_RATE_UNIT_PPS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_RATE_UNIT_PPS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_RATE_UNIT_PPS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_RATE_UNIT_PPS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_RATE_UNIT_PPS_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_RATE_UNIT_KBITPS;
    TEST_ASSERT(!OFP_BSN_RATE_UNIT_KBITPS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_RATE_UNIT_KBITPS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_RATE_UNIT_KBITPS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_RATE_UNIT_KBITPS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_RATE_UNIT_KBITPS_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_STATUS_DISABLE;
    TEST_ASSERT(!OFP_BSN_STATUS_DISABLE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_STATUS_DISABLE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_STATUS_DISABLE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_STATUS_DISABLE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_STATUS_DISABLE_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_STATUS_ENABLE;
    TEST_ASSERT(!OFP_BSN_STATUS_ENABLE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_STATUS_ENABLE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_STATUS_ENABLE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_STATUS_ENABLE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_STATUS_ENABLE_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_HASH_TYPE_L2;
    TEST_ASSERT(!OFP_BSN_HASH_TYPE_L2_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_HASH_TYPE_L2_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_HASH_TYPE_L2_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_HASH_TYPE_L2_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_HASH_TYPE_L2_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_HASH_TYPE_L3;
    TEST_ASSERT(!OFP_BSN_HASH_TYPE_L3_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_HASH_TYPE_L3_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_HASH_TYPE_L3_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_HASH_TYPE_L3_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_HASH_TYPE_L3_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_HASH_TYPE_ENHANCED;
    TEST_ASSERT(!OFP_BSN_HASH_TYPE_ENHANCED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_HASH_TYPE_ENHANCED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_HASH_TYPE_ENHANCED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_HASH_TYPE_ENHANCED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_HASH_TYPE_ENHANCED_SUPPORTED(OF_VERSION_1_4));
    value = OF_BSN_HASH_PACKET_L2;
    TEST_ASSERT(!OF_BSN_HASH_PACKET_L2_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_BSN_HASH_PACKET_L2_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_BSN_HASH_PACKET_L2_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_BSN_HASH_PACKET_L2_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_BSN_HASH_PACKET_L2_SUPPORTED(OF_VERSION_1_4));
    value = OF_BSN_HASH_PACKET_L2GRE;
    TEST_ASSERT(!OF_BSN_HASH_PACKET_L2GRE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_BSN_HASH_PACKET_L2GRE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_BSN_HASH_PACKET_L2GRE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_BSN_HASH_PACKET_L2GRE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_BSN_HASH_PACKET_L2GRE_SUPPORTED(OF_VERSION_1_4));
    value = OF_BSN_HASH_PACKET_IPV4;
    TEST_ASSERT(!OF_BSN_HASH_PACKET_IPV4_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_BSN_HASH_PACKET_IPV4_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_BSN_HASH_PACKET_IPV4_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_BSN_HASH_PACKET_IPV4_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_BSN_HASH_PACKET_IPV4_SUPPORTED(OF_VERSION_1_4));
    value = OF_BSN_HASH_PACKET_IPV6;
    TEST_ASSERT(!OF_BSN_HASH_PACKET_IPV6_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_BSN_HASH_PACKET_IPV6_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_BSN_HASH_PACKET_IPV6_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_BSN_HASH_PACKET_IPV6_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_BSN_HASH_PACKET_IPV6_SUPPORTED(OF_VERSION_1_4));
    value = OF_BSN_HASH_PACKET_MPLS;
    TEST_ASSERT(!OF_BSN_HASH_PACKET_MPLS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_BSN_HASH_PACKET_MPLS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_BSN_HASH_PACKET_MPLS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_BSN_HASH_PACKET_MPLS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_BSN_HASH_PACKET_MPLS_SUPPORTED(OF_VERSION_1_4));
    value = OF_BSN_HASH_PACKET_SYMMETRIC;
    TEST_ASSERT(!OF_BSN_HASH_PACKET_SYMMETRIC_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_BSN_HASH_PACKET_SYMMETRIC_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_BSN_HASH_PACKET_SYMMETRIC_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_BSN_HASH_PACKET_SYMMETRIC_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_BSN_HASH_PACKET_SYMMETRIC_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_HASH_FIELD_DST_MAC;
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_DST_MAC_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_DST_MAC_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_DST_MAC_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_HASH_FIELD_DST_MAC_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_HASH_FIELD_DST_MAC_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_HASH_FIELD_SRC_MAC;
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_SRC_MAC_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_SRC_MAC_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_SRC_MAC_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_HASH_FIELD_SRC_MAC_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_HASH_FIELD_SRC_MAC_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_HASH_FIELD_ETH_TYPE;
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_ETH_TYPE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_ETH_TYPE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_ETH_TYPE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_HASH_FIELD_ETH_TYPE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_HASH_FIELD_ETH_TYPE_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_HASH_FIELD_VLAN_ID;
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_VLAN_ID_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_VLAN_ID_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_VLAN_ID_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_HASH_FIELD_VLAN_ID_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_HASH_FIELD_VLAN_ID_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_HASH_FIELD_INNER_L2;
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_INNER_L2_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_INNER_L2_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_INNER_L2_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_HASH_FIELD_INNER_L2_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_HASH_FIELD_INNER_L2_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_HASH_FIELD_INNER_L3;
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_INNER_L3_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_INNER_L3_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_INNER_L3_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_HASH_FIELD_INNER_L3_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_HASH_FIELD_INNER_L3_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_HASH_FIELD_SRC_IP;
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_SRC_IP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_SRC_IP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_SRC_IP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_HASH_FIELD_SRC_IP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_HASH_FIELD_SRC_IP_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_HASH_FIELD_DST_IP;
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_DST_IP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_DST_IP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_DST_IP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_HASH_FIELD_DST_IP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_HASH_FIELD_DST_IP_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_HASH_FIELD_IP_PROTO;
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_IP_PROTO_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_IP_PROTO_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_IP_PROTO_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_HASH_FIELD_IP_PROTO_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_HASH_FIELD_IP_PROTO_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_HASH_FIELD_SRC_L4_PORT;
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_SRC_L4_PORT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_SRC_L4_PORT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_SRC_L4_PORT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_HASH_FIELD_SRC_L4_PORT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_HASH_FIELD_SRC_L4_PORT_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_HASH_FIELD_DST_L4_PORT;
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_DST_L4_PORT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_DST_L4_PORT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_DST_L4_PORT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_HASH_FIELD_DST_L4_PORT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_HASH_FIELD_DST_L4_PORT_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_HASH_FIELD_MPLS_LABEL1;
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_MPLS_LABEL1_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_MPLS_LABEL1_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_MPLS_LABEL1_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_HASH_FIELD_MPLS_LABEL1_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_HASH_FIELD_MPLS_LABEL1_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_HASH_FIELD_MPLS_LABEL2;
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_MPLS_LABEL2_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_MPLS_LABEL2_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_MPLS_LABEL2_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_HASH_FIELD_MPLS_LABEL2_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_HASH_FIELD_MPLS_LABEL2_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_HASH_FIELD_MPLS_LABEL3;
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_MPLS_LABEL3_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_MPLS_LABEL3_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_MPLS_LABEL3_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_HASH_FIELD_MPLS_LABEL3_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_HASH_FIELD_MPLS_LABEL3_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_HASH_FIELD_MPLS_LABEL_HI_BITS;
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_MPLS_LABEL_HI_BITS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_MPLS_LABEL_HI_BITS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_MPLS_LABEL_HI_BITS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_HASH_FIELD_MPLS_LABEL_HI_BITS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_HASH_FIELD_MPLS_LABEL_HI_BITS_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_HASH_FIELD_MPLS_PAYLOAD_SRC_IP;
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_MPLS_PAYLOAD_SRC_IP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_MPLS_PAYLOAD_SRC_IP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_MPLS_PAYLOAD_SRC_IP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_HASH_FIELD_MPLS_PAYLOAD_SRC_IP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_HASH_FIELD_MPLS_PAYLOAD_SRC_IP_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_HASH_FIELD_MPLS_PAYLOAD_DST_IP;
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_MPLS_PAYLOAD_DST_IP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_MPLS_PAYLOAD_DST_IP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_MPLS_PAYLOAD_DST_IP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_HASH_FIELD_MPLS_PAYLOAD_DST_IP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_HASH_FIELD_MPLS_PAYLOAD_DST_IP_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_HASH_FIELD_SYMMETRIC;
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_SYMMETRIC_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_SYMMETRIC_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_HASH_FIELD_SYMMETRIC_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_HASH_FIELD_SYMMETRIC_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_HASH_FIELD_SYMMETRIC_SUPPORTED(OF_VERSION_1_4));
    value = OF_BSN_HASH_GTP_PORT_MATCH_SRC;
    TEST_ASSERT(!OF_BSN_HASH_GTP_PORT_MATCH_SRC_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_BSN_HASH_GTP_PORT_MATCH_SRC_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_BSN_HASH_GTP_PORT_MATCH_SRC_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_BSN_HASH_GTP_PORT_MATCH_SRC_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_BSN_HASH_GTP_PORT_MATCH_SRC_SUPPORTED(OF_VERSION_1_4));
    value = OF_BSN_HASH_GTP_PORT_MATCH_DST;
    TEST_ASSERT(!OF_BSN_HASH_GTP_PORT_MATCH_DST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_BSN_HASH_GTP_PORT_MATCH_DST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_BSN_HASH_GTP_PORT_MATCH_DST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_BSN_HASH_GTP_PORT_MATCH_DST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_BSN_HASH_GTP_PORT_MATCH_DST_SUPPORTED(OF_VERSION_1_4));
    value = OF_BSN_HASH_GTP_PORT_MATCH_SRC_OR_DST;
    TEST_ASSERT(!OF_BSN_HASH_GTP_PORT_MATCH_SRC_OR_DST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_BSN_HASH_GTP_PORT_MATCH_SRC_OR_DST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_BSN_HASH_GTP_PORT_MATCH_SRC_OR_DST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_BSN_HASH_GTP_PORT_MATCH_SRC_OR_DST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_BSN_HASH_GTP_PORT_MATCH_SRC_OR_DST_SUPPORTED(OF_VERSION_1_4));
    value = OF_BSN_HASH_GTP_PORT_MATCH_SRC_AND_DST;
    TEST_ASSERT(!OF_BSN_HASH_GTP_PORT_MATCH_SRC_AND_DST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_BSN_HASH_GTP_PORT_MATCH_SRC_AND_DST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_BSN_HASH_GTP_PORT_MATCH_SRC_AND_DST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_BSN_HASH_GTP_PORT_MATCH_SRC_AND_DST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_BSN_HASH_GTP_PORT_MATCH_SRC_AND_DST_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PUSH_VLAN_UNTAGGED;
    TEST_ASSERT(!OFP_BSN_PUSH_VLAN_UNTAGGED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PUSH_VLAN_UNTAGGED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PUSH_VLAN_UNTAGGED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PUSH_VLAN_UNTAGGED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PUSH_VLAN_UNTAGGED_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PUSH_VLAN_SINGLE_TAGGED;
    TEST_ASSERT(!OFP_BSN_PUSH_VLAN_SINGLE_TAGGED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PUSH_VLAN_SINGLE_TAGGED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PUSH_VLAN_SINGLE_TAGGED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PUSH_VLAN_SINGLE_TAGGED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PUSH_VLAN_SINGLE_TAGGED_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PUSH_VLAN_DOUBLE_TAGGED;
    TEST_ASSERT(!OFP_BSN_PUSH_VLAN_DOUBLE_TAGGED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PUSH_VLAN_DOUBLE_TAGGED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PUSH_VLAN_DOUBLE_TAGGED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PUSH_VLAN_DOUBLE_TAGGED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PUSH_VLAN_DOUBLE_TAGGED_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_UNUSED;
    TEST_ASSERT(!OFP_BSN_PORT_UNUSED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_UNUSED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_UNUSED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_UNUSED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_UNUSED_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_TRANSMIT_ONLY;
    TEST_ASSERT(!OFP_BSN_PORT_TRANSMIT_ONLY_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_TRANSMIT_ONLY_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_TRANSMIT_ONLY_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_TRANSMIT_ONLY_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_TRANSMIT_ONLY_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_RECEIVE_ONLY;
    TEST_ASSERT(!OFP_BSN_PORT_RECEIVE_ONLY_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_RECEIVE_ONLY_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_RECEIVE_ONLY_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_RECEIVE_ONLY_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_RECEIVE_ONLY_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_BIDIRECTION;
    TEST_ASSERT(!OFP_BSN_PORT_BIDIRECTION_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_BIDIRECTION_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_BIDIRECTION_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_BIDIRECTION_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_BIDIRECTION_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_TUNNEL_L2GRE;
    TEST_ASSERT(!OFP_BSN_TUNNEL_L2GRE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_TUNNEL_L2GRE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_TUNNEL_L2GRE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_TUNNEL_L2GRE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_TUNNEL_L2GRE_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_TUNNEL_VXLAN;
    TEST_ASSERT(!OFP_BSN_TUNNEL_VXLAN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_TUNNEL_VXLAN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_TUNNEL_VXLAN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_TUNNEL_VXLAN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_TUNNEL_VXLAN_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_ENHANCED_HASH_L2;
    TEST_ASSERT(!OFP_BSN_ENHANCED_HASH_L2_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_ENHANCED_HASH_L2_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_ENHANCED_HASH_L2_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_ENHANCED_HASH_L2_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_ENHANCED_HASH_L2_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_ENHANCED_HASH_L3;
    TEST_ASSERT(!OFP_BSN_ENHANCED_HASH_L3_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_ENHANCED_HASH_L3_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_ENHANCED_HASH_L3_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_ENHANCED_HASH_L3_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_ENHANCED_HASH_L3_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_ENHANCED_HASH_L2GRE;
    TEST_ASSERT(!OFP_BSN_ENHANCED_HASH_L2GRE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_ENHANCED_HASH_L2GRE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_ENHANCED_HASH_L2GRE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_ENHANCED_HASH_L2GRE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_ENHANCED_HASH_L2GRE_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_ENHANCED_HASH_MPLS;
    TEST_ASSERT(!OFP_BSN_ENHANCED_HASH_MPLS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_ENHANCED_HASH_MPLS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_ENHANCED_HASH_MPLS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_ENHANCED_HASH_MPLS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_ENHANCED_HASH_MPLS_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_ENHANCED_HASH_GTP;
    TEST_ASSERT(!OFP_BSN_ENHANCED_HASH_GTP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_ENHANCED_HASH_GTP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_ENHANCED_HASH_GTP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_ENHANCED_HASH_GTP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_ENHANCED_HASH_GTP_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_ENHANCED_HASH_SYMMETRIC;
    TEST_ASSERT(!OFP_BSN_ENHANCED_HASH_SYMMETRIC_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_ENHANCED_HASH_SYMMETRIC_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_ENHANCED_HASH_SYMMETRIC_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_ENHANCED_HASH_SYMMETRIC_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_ENHANCED_HASH_SYMMETRIC_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_AUTO_NEGOTIATION_DEFAULT;
    TEST_ASSERT(!OFP_BSN_AUTO_NEGOTIATION_DEFAULT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_AUTO_NEGOTIATION_DEFAULT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_AUTO_NEGOTIATION_DEFAULT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_AUTO_NEGOTIATION_DEFAULT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_AUTO_NEGOTIATION_DEFAULT_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_AUTO_NEGOTIATION_ENABLE;
    TEST_ASSERT(!OFP_BSN_AUTO_NEGOTIATION_ENABLE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_AUTO_NEGOTIATION_ENABLE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_AUTO_NEGOTIATION_ENABLE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_AUTO_NEGOTIATION_ENABLE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_AUTO_NEGOTIATION_ENABLE_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_AUTO_NEGOTIATION_DISABLE;
    TEST_ASSERT(!OFP_BSN_AUTO_NEGOTIATION_DISABLE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_AUTO_NEGOTIATION_DISABLE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_AUTO_NEGOTIATION_DISABLE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_AUTO_NEGOTIATION_DISABLE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_AUTO_NEGOTIATION_DISABLE_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_HASH_ALGORITHM_CRC16XOR8;
    TEST_ASSERT(!OFP_BSN_HASH_ALGORITHM_CRC16XOR8_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_HASH_ALGORITHM_CRC16XOR8_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_HASH_ALGORITHM_CRC16XOR8_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_HASH_ALGORITHM_CRC16XOR8_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_HASH_ALGORITHM_CRC16XOR8_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_HASH_ALGORITHM_CRC16XOR4;
    TEST_ASSERT(!OFP_BSN_HASH_ALGORITHM_CRC16XOR4_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_HASH_ALGORITHM_CRC16XOR4_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_HASH_ALGORITHM_CRC16XOR4_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_HASH_ALGORITHM_CRC16XOR4_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_HASH_ALGORITHM_CRC16XOR4_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_HASH_ALGORITHM_CRC16XOR2;
    TEST_ASSERT(!OFP_BSN_HASH_ALGORITHM_CRC16XOR2_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_HASH_ALGORITHM_CRC16XOR2_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_HASH_ALGORITHM_CRC16XOR2_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_HASH_ALGORITHM_CRC16XOR2_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_HASH_ALGORITHM_CRC16XOR2_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_HASH_ALGORITHM_CRC16XOR1;
    TEST_ASSERT(!OFP_BSN_HASH_ALGORITHM_CRC16XOR1_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_HASH_ALGORITHM_CRC16XOR1_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_HASH_ALGORITHM_CRC16XOR1_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_HASH_ALGORITHM_CRC16XOR1_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_HASH_ALGORITHM_CRC16XOR1_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_HASH_ALGORITHM_CRC16;
    TEST_ASSERT(!OFP_BSN_HASH_ALGORITHM_CRC16_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_HASH_ALGORITHM_CRC16_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_HASH_ALGORITHM_CRC16_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_HASH_ALGORITHM_CRC16_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_HASH_ALGORITHM_CRC16_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_HASH_ALGORITHM_XOR16;
    TEST_ASSERT(!OFP_BSN_HASH_ALGORITHM_XOR16_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_HASH_ALGORITHM_XOR16_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_HASH_ALGORITHM_XOR16_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_HASH_ALGORITHM_XOR16_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_HASH_ALGORITHM_XOR16_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_HASH_ALGORITHM_CRC16CCITT;
    TEST_ASSERT(!OFP_BSN_HASH_ALGORITHM_CRC16CCITT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_HASH_ALGORITHM_CRC16CCITT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_HASH_ALGORITHM_CRC16CCITT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_HASH_ALGORITHM_CRC16CCITT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_HASH_ALGORITHM_CRC16CCITT_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_HASH_ALGORITHM_CRC32LO;
    TEST_ASSERT(!OFP_BSN_HASH_ALGORITHM_CRC32LO_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_HASH_ALGORITHM_CRC32LO_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_HASH_ALGORITHM_CRC32LO_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_HASH_ALGORITHM_CRC32LO_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_HASH_ALGORITHM_CRC32LO_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_HASH_ALGORITHM_CRC32HI;
    TEST_ASSERT(!OFP_BSN_HASH_ALGORITHM_CRC32HI_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_HASH_ALGORITHM_CRC32HI_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_HASH_ALGORITHM_CRC32HI_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_HASH_ALGORITHM_CRC32HI_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_HASH_ALGORITHM_CRC32HI_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_LOOPBACK_MODE_NONE;
    TEST_ASSERT(!OFP_BSN_LOOPBACK_MODE_NONE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_LOOPBACK_MODE_NONE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_LOOPBACK_MODE_NONE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_LOOPBACK_MODE_NONE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_LOOPBACK_MODE_NONE_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_LOOPBACK_MODE_MAC;
    TEST_ASSERT(!OFP_BSN_LOOPBACK_MODE_MAC_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_LOOPBACK_MODE_MAC_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_LOOPBACK_MODE_MAC_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_LOOPBACK_MODE_MAC_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_LOOPBACK_MODE_MAC_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_LOOPBACK_MODE_PHY;
    TEST_ASSERT(!OFP_BSN_LOOPBACK_MODE_PHY_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_LOOPBACK_MODE_PHY_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_LOOPBACK_MODE_PHY_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_LOOPBACK_MODE_PHY_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_LOOPBACK_MODE_PHY_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_LOOPBACK_MODE_PHY_REMOTE;
    TEST_ASSERT(!OFP_BSN_LOOPBACK_MODE_PHY_REMOTE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_LOOPBACK_MODE_PHY_REMOTE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_LOOPBACK_MODE_PHY_REMOTE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_LOOPBACK_MODE_PHY_REMOTE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_LOOPBACK_MODE_PHY_REMOTE_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_FORWARD_ERROR_CORRECTION_DEFAULT;
    TEST_ASSERT(!OFP_BSN_FORWARD_ERROR_CORRECTION_DEFAULT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_FORWARD_ERROR_CORRECTION_DEFAULT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_FORWARD_ERROR_CORRECTION_DEFAULT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_FORWARD_ERROR_CORRECTION_DEFAULT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_FORWARD_ERROR_CORRECTION_DEFAULT_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_FORWARD_ERROR_CORRECTION_ENABLE;
    TEST_ASSERT(!OFP_BSN_FORWARD_ERROR_CORRECTION_ENABLE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_FORWARD_ERROR_CORRECTION_ENABLE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_FORWARD_ERROR_CORRECTION_ENABLE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_FORWARD_ERROR_CORRECTION_ENABLE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_FORWARD_ERROR_CORRECTION_ENABLE_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_FORWARD_ERROR_CORRECTION_DISABLE;
    TEST_ASSERT(!OFP_BSN_FORWARD_ERROR_CORRECTION_DISABLE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_FORWARD_ERROR_CORRECTION_DISABLE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_FORWARD_ERROR_CORRECTION_DISABLE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_FORWARD_ERROR_CORRECTION_DISABLE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_FORWARD_ERROR_CORRECTION_DISABLE_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_SPEED_GBPS_1;
    TEST_ASSERT(!OFP_BSN_PORT_SPEED_GBPS_1_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_SPEED_GBPS_1_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_SPEED_GBPS_1_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_SPEED_GBPS_1_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_SPEED_GBPS_1_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_SPEED_GBPS_10;
    TEST_ASSERT(!OFP_BSN_PORT_SPEED_GBPS_10_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_SPEED_GBPS_10_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_SPEED_GBPS_10_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_SPEED_GBPS_10_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_SPEED_GBPS_10_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_SPEED_GBPS_25;
    TEST_ASSERT(!OFP_BSN_PORT_SPEED_GBPS_25_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_SPEED_GBPS_25_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_SPEED_GBPS_25_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_SPEED_GBPS_25_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_SPEED_GBPS_25_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_SPEED_GBPS_40;
    TEST_ASSERT(!OFP_BSN_PORT_SPEED_GBPS_40_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_SPEED_GBPS_40_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_SPEED_GBPS_40_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_SPEED_GBPS_40_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_SPEED_GBPS_40_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_SPEED_GBPS_50;
    TEST_ASSERT(!OFP_BSN_PORT_SPEED_GBPS_50_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_SPEED_GBPS_50_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_SPEED_GBPS_50_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_SPEED_GBPS_50_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_SPEED_GBPS_50_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_SPEED_GBPS_100;
    TEST_ASSERT(!OFP_BSN_PORT_SPEED_GBPS_100_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_SPEED_GBPS_100_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_SPEED_GBPS_100_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_SPEED_GBPS_100_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_SPEED_GBPS_100_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_LAG_FLAG_AUTO_RECOVERY;
    TEST_ASSERT(!OFP_BSN_LAG_FLAG_AUTO_RECOVERY_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_LAG_FLAG_AUTO_RECOVERY_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_LAG_FLAG_AUTO_RECOVERY_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_LAG_FLAG_AUTO_RECOVERY_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_LAG_FLAG_AUTO_RECOVERY_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFP_BSN_LAG_FLAG_AUTO_RECOVERY_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OFP_BSN_LAG_FLAG_AUTO_RECOVERY_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_LAG_FLAG_AUTO_RECOVERY_TEST(flags, OF_VERSION_1_3));
    OFP_BSN_LAG_FLAG_AUTO_RECOVERY_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFP_BSN_LAG_FLAG_AUTO_RECOVERY_TEST(flags, OF_VERSION_1_3));
    value = OFP_BSN_ROUTING_PARAM_OSPF_UCAST;
    TEST_ASSERT(!OFP_BSN_ROUTING_PARAM_OSPF_UCAST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_ROUTING_PARAM_OSPF_UCAST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_ROUTING_PARAM_OSPF_UCAST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_ROUTING_PARAM_OSPF_UCAST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_ROUTING_PARAM_OSPF_UCAST_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_ROUTING_PARAM_OSPF_MCAST;
    TEST_ASSERT(!OFP_BSN_ROUTING_PARAM_OSPF_MCAST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_ROUTING_PARAM_OSPF_MCAST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_ROUTING_PARAM_OSPF_MCAST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_ROUTING_PARAM_OSPF_MCAST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_ROUTING_PARAM_OSPF_MCAST_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_ROUTING_PARAM_ARP_FRR;
    TEST_ASSERT(!OFP_BSN_ROUTING_PARAM_ARP_FRR_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_ROUTING_PARAM_ARP_FRR_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_ROUTING_PARAM_ARP_FRR_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_ROUTING_PARAM_ARP_FRR_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_ROUTING_PARAM_ARP_FRR_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_ROUTING_PARAM_IPV6_OSPF_UCAST;
    TEST_ASSERT(!OFP_BSN_ROUTING_PARAM_IPV6_OSPF_UCAST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_ROUTING_PARAM_IPV6_OSPF_UCAST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_ROUTING_PARAM_IPV6_OSPF_UCAST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_ROUTING_PARAM_IPV6_OSPF_UCAST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_ROUTING_PARAM_IPV6_OSPF_UCAST_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_ROUTING_PARAM_IPV6_OSPF_MCAST;
    TEST_ASSERT(!OFP_BSN_ROUTING_PARAM_IPV6_OSPF_MCAST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_ROUTING_PARAM_IPV6_OSPF_MCAST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_ROUTING_PARAM_IPV6_OSPF_MCAST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_ROUTING_PARAM_IPV6_OSPF_MCAST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_ROUTING_PARAM_IPV6_OSPF_MCAST_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_ROUTING_PARAM_IPV6_NDP_FRR;
    TEST_ASSERT(!OFP_BSN_ROUTING_PARAM_IPV6_NDP_FRR_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_ROUTING_PARAM_IPV6_NDP_FRR_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_ROUTING_PARAM_IPV6_NDP_FRR_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_ROUTING_PARAM_IPV6_NDP_FRR_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_ROUTING_PARAM_IPV6_NDP_FRR_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_UPGRADE_INVALID;
    TEST_ASSERT(!OFP_BSN_UPGRADE_INVALID_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_UPGRADE_INVALID_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_UPGRADE_INVALID_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_UPGRADE_INVALID_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_UPGRADE_INVALID_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_UPGRADE_IN_PROGRESS;
    TEST_ASSERT(!OFP_BSN_UPGRADE_IN_PROGRESS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_UPGRADE_IN_PROGRESS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_UPGRADE_IN_PROGRESS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_UPGRADE_IN_PROGRESS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_UPGRADE_IN_PROGRESS_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_FABRIC_PORT_ROLE_PARTITIONED_SPINE;
    TEST_ASSERT(!OFP_BSN_FABRIC_PORT_ROLE_PARTITIONED_SPINE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_FABRIC_PORT_ROLE_PARTITIONED_SPINE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_FABRIC_PORT_ROLE_PARTITIONED_SPINE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_FABRIC_PORT_ROLE_PARTITIONED_SPINE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_FABRIC_PORT_ROLE_PARTITIONED_SPINE_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_IP_TUNNEL_TYPE_NONE;
    TEST_ASSERT(!OFP_BSN_IP_TUNNEL_TYPE_NONE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_IP_TUNNEL_TYPE_NONE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_IP_TUNNEL_TYPE_NONE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_IP_TUNNEL_TYPE_NONE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_IP_TUNNEL_TYPE_NONE_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_IP_TUNNEL_TYPE_PIM;
    TEST_ASSERT(!OFP_BSN_IP_TUNNEL_TYPE_PIM_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_IP_TUNNEL_TYPE_PIM_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_IP_TUNNEL_TYPE_PIM_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_IP_TUNNEL_TYPE_PIM_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_IP_TUNNEL_TYPE_PIM_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_MULTICAST_PACKET_NONE;
    TEST_ASSERT(!OFP_BSN_MULTICAST_PACKET_NONE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_MULTICAST_PACKET_NONE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_MULTICAST_PACKET_NONE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_MULTICAST_PACKET_NONE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_MULTICAST_PACKET_NONE_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_MULTICAST_PACKET_PIM_HELLO;
    TEST_ASSERT(!OFP_BSN_MULTICAST_PACKET_PIM_HELLO_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_MULTICAST_PACKET_PIM_HELLO_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_MULTICAST_PACKET_PIM_HELLO_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_MULTICAST_PACKET_PIM_HELLO_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_MULTICAST_PACKET_PIM_HELLO_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_MULTICAST_PACKET_PIM_JOIN_PRUNE;
    TEST_ASSERT(!OFP_BSN_MULTICAST_PACKET_PIM_JOIN_PRUNE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_MULTICAST_PACKET_PIM_JOIN_PRUNE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_MULTICAST_PACKET_PIM_JOIN_PRUNE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_MULTICAST_PACKET_PIM_JOIN_PRUNE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_MULTICAST_PACKET_PIM_JOIN_PRUNE_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_MULTICAST_PACKET_PIM_ASSERT;
    TEST_ASSERT(!OFP_BSN_MULTICAST_PACKET_PIM_ASSERT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_MULTICAST_PACKET_PIM_ASSERT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_MULTICAST_PACKET_PIM_ASSERT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_MULTICAST_PACKET_PIM_ASSERT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_MULTICAST_PACKET_PIM_ASSERT_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_ENCAP_UNUSED;
    TEST_ASSERT(!OFP_BSN_ENCAP_UNUSED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_ENCAP_UNUSED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_ENCAP_UNUSED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_ENCAP_UNUSED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_ENCAP_UNUSED_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_ENCAP_IPV4_UDP;
    TEST_ASSERT(!OFP_BSN_ENCAP_IPV4_UDP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_ENCAP_IPV4_UDP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_ENCAP_IPV4_UDP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_ENCAP_IPV4_UDP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_ENCAP_IPV4_UDP_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_ENCAP_IPV6_UDP;
    TEST_ASSERT(!OFP_BSN_ENCAP_IPV6_UDP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_ENCAP_IPV6_UDP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_ENCAP_IPV6_UDP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_ENCAP_IPV6_UDP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_ENCAP_IPV6_UDP_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_BFD_UNUSED;
    TEST_ASSERT(!OFP_BSN_BFD_UNUSED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_BFD_UNUSED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_BFD_UNUSED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_BFD_UNUSED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_BFD_UNUSED_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_BFD_MICRO;
    TEST_ASSERT(!OFP_BSN_BFD_MICRO_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_BFD_MICRO_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_BFD_MICRO_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_BFD_MICRO_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_BFD_MICRO_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_BFD_1_HOP;
    TEST_ASSERT(!OFP_BSN_BFD_1_HOP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_BFD_1_HOP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_BFD_1_HOP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_BFD_1_HOP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_BFD_1_HOP_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_BFD_MULTI_HOP;
    TEST_ASSERT(!OFP_BSN_BFD_MULTI_HOP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_BFD_MULTI_HOP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_BFD_MULTI_HOP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_BFD_MULTI_HOP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_BFD_MULTI_HOP_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_BFD_ENDPOINT_STATE_ADMINDOWN;
    TEST_ASSERT(!OFP_BSN_BFD_ENDPOINT_STATE_ADMINDOWN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_BFD_ENDPOINT_STATE_ADMINDOWN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_BFD_ENDPOINT_STATE_ADMINDOWN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_BFD_ENDPOINT_STATE_ADMINDOWN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_BFD_ENDPOINT_STATE_ADMINDOWN_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_BFD_ENDPOINT_STATE_DOWN;
    TEST_ASSERT(!OFP_BSN_BFD_ENDPOINT_STATE_DOWN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_BFD_ENDPOINT_STATE_DOWN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_BFD_ENDPOINT_STATE_DOWN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_BFD_ENDPOINT_STATE_DOWN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_BFD_ENDPOINT_STATE_DOWN_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_BFD_ENDPOINT_STATE_INIT;
    TEST_ASSERT(!OFP_BSN_BFD_ENDPOINT_STATE_INIT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_BFD_ENDPOINT_STATE_INIT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_BFD_ENDPOINT_STATE_INIT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_BFD_ENDPOINT_STATE_INIT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_BFD_ENDPOINT_STATE_INIT_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_BFD_ENDPOINT_STATE_UP;
    TEST_ASSERT(!OFP_BSN_BFD_ENDPOINT_STATE_UP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_BFD_ENDPOINT_STATE_UP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_BFD_ENDPOINT_STATE_UP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_BFD_ENDPOINT_STATE_UP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_BFD_ENDPOINT_STATE_UP_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_BFD_ENDPOINT_SESSION_ERROR;
    TEST_ASSERT(!OFP_BSN_BFD_ENDPOINT_SESSION_ERROR_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_BFD_ENDPOINT_SESSION_ERROR_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_BFD_ENDPOINT_SESSION_ERROR_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_BFD_ENDPOINT_SESSION_ERROR_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_BFD_ENDPOINT_SESSION_ERROR_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_BFD_ENDPOINT_REMOTE_ADMINDOWN;
    TEST_ASSERT(!OFP_BSN_BFD_ENDPOINT_REMOTE_ADMINDOWN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_BFD_ENDPOINT_REMOTE_ADMINDOWN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_BFD_ENDPOINT_REMOTE_ADMINDOWN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_BFD_ENDPOINT_REMOTE_ADMINDOWN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_BFD_ENDPOINT_REMOTE_ADMINDOWN_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_BFD_ENDPOINT_PARAMS_CHANGE;
    TEST_ASSERT(!OFP_BSN_BFD_ENDPOINT_PARAMS_CHANGE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_BFD_ENDPOINT_PARAMS_CHANGE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_BFD_ENDPOINT_PARAMS_CHANGE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_BFD_ENDPOINT_PARAMS_CHANGE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_BFD_ENDPOINT_PARAMS_CHANGE_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_MODE_NONE;
    TEST_ASSERT(!OFP_BSN_PORT_MODE_NONE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_MODE_NONE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_MODE_NONE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_MODE_NONE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_MODE_NONE_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_MODE_4XX;
    TEST_ASSERT(!OFP_BSN_PORT_MODE_4XX_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_MODE_4XX_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_MODE_4XX_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_MODE_4XX_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_MODE_4XX_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_MODE_4X1;
    TEST_ASSERT(!OFP_BSN_PORT_MODE_4X1_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_MODE_4X1_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_MODE_4X1_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_MODE_4X1_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_MODE_4X1_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_MODE_4X10;
    TEST_ASSERT(!OFP_BSN_PORT_MODE_4X10_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_MODE_4X10_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_MODE_4X10_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_MODE_4X10_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_MODE_4X10_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_MODE_4X25;
    TEST_ASSERT(!OFP_BSN_PORT_MODE_4X25_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_MODE_4X25_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_MODE_4X25_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_MODE_4X25_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_MODE_4X25_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_MODE_2X50;
    TEST_ASSERT(!OFP_BSN_PORT_MODE_2X50_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_MODE_2X50_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_MODE_2X50_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_MODE_2X50_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_MODE_2X50_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_MODE_1X1;
    TEST_ASSERT(!OFP_BSN_PORT_MODE_1X1_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_MODE_1X1_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_MODE_1X1_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_MODE_1X1_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_MODE_1X1_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_MODE_1X10;
    TEST_ASSERT(!OFP_BSN_PORT_MODE_1X10_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_MODE_1X10_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_MODE_1X10_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_MODE_1X10_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_MODE_1X10_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_MODE_1X25;
    TEST_ASSERT(!OFP_BSN_PORT_MODE_1X25_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_MODE_1X25_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_MODE_1X25_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_MODE_1X25_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_MODE_1X25_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_MODE_1X40;
    TEST_ASSERT(!OFP_BSN_PORT_MODE_1X40_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_MODE_1X40_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_MODE_1X40_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_MODE_1X40_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_MODE_1X40_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_MODE_1X100;
    TEST_ASSERT(!OFP_BSN_PORT_MODE_1X100_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_MODE_1X100_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_MODE_1X100_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_MODE_1X100_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_MODE_1X100_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_MODE_8X25;
    TEST_ASSERT(!OFP_BSN_PORT_MODE_8X25_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_MODE_8X25_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_MODE_8X25_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_MODE_8X25_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_MODE_8X25_SUPPORTED(OF_VERSION_1_4));
    value = OPF_BSN_PORT_MODE_8X50;
    TEST_ASSERT(!OPF_BSN_PORT_MODE_8X50_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OPF_BSN_PORT_MODE_8X50_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OPF_BSN_PORT_MODE_8X50_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OPF_BSN_PORT_MODE_8X50_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OPF_BSN_PORT_MODE_8X50_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_MODE_4X50;
    TEST_ASSERT(!OFP_BSN_PORT_MODE_4X50_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_MODE_4X50_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_MODE_4X50_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_MODE_4X50_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_MODE_4X50_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_MODE_1X50;
    TEST_ASSERT(!OFP_BSN_PORT_MODE_1X50_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_MODE_1X50_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_MODE_1X50_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_MODE_1X50_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_MODE_1X50_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_MODE_1X200;
    TEST_ASSERT(!OFP_BSN_PORT_MODE_1X200_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_MODE_1X200_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_MODE_1X200_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_MODE_1X200_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_MODE_1X200_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_PORT_MODE_1X400;
    TEST_ASSERT(!OFP_BSN_PORT_MODE_1X400_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_PORT_MODE_1X400_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_PORT_MODE_1X400_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_PORT_MODE_1X400_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_PORT_MODE_1X400_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_UDF_8X2_BYTES;
    TEST_ASSERT(!OFP_BSN_UDF_8X2_BYTES_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_UDF_8X2_BYTES_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_UDF_8X2_BYTES_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_UDF_8X2_BYTES_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_UDF_8X2_BYTES_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_FLOW_CLASSIFIER_NONE;
    TEST_ASSERT(!OFP_BSN_FLOW_CLASSIFIER_NONE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_FLOW_CLASSIFIER_NONE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_FLOW_CLASSIFIER_NONE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_FLOW_CLASSIFIER_NONE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_FLOW_CLASSIFIER_NONE_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_FLOW_CLASSIFIER_L2BC;
    TEST_ASSERT(!OFP_BSN_FLOW_CLASSIFIER_L2BC_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_FLOW_CLASSIFIER_L2BC_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_FLOW_CLASSIFIER_L2BC_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_FLOW_CLASSIFIER_L2BC_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_FLOW_CLASSIFIER_L2BC_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_FLOW_CLASSIFIER_L2UC;
    TEST_ASSERT(!OFP_BSN_FLOW_CLASSIFIER_L2UC_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_FLOW_CLASSIFIER_L2UC_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_FLOW_CLASSIFIER_L2UC_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_FLOW_CLASSIFIER_L2UC_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_FLOW_CLASSIFIER_L2UC_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_FLOW_CLASSIFIER_L2UNKNOWN;
    TEST_ASSERT(!OFP_BSN_FLOW_CLASSIFIER_L2UNKNOWN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_FLOW_CLASSIFIER_L2UNKNOWN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_FLOW_CLASSIFIER_L2UNKNOWN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_FLOW_CLASSIFIER_L2UNKNOWN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_FLOW_CLASSIFIER_L2UNKNOWN_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_FLOW_CLASSIFIER_L2MCKNOWN;
    TEST_ASSERT(!OFP_BSN_FLOW_CLASSIFIER_L2MCKNOWN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_FLOW_CLASSIFIER_L2MCKNOWN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_FLOW_CLASSIFIER_L2MCKNOWN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_FLOW_CLASSIFIER_L2MCKNOWN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_FLOW_CLASSIFIER_L2MCKNOWN_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_FLOW_CLASSIFIER_L2MCUNKNOWN;
    TEST_ASSERT(!OFP_BSN_FLOW_CLASSIFIER_L2MCUNKNOWN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_FLOW_CLASSIFIER_L2MCUNKNOWN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_FLOW_CLASSIFIER_L2MCUNKNOWN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_FLOW_CLASSIFIER_L2MCUNKNOWN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_FLOW_CLASSIFIER_L2MCUNKNOWN_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_FLOW_CLASSIFIER_L3MCUNKNOWN;
    TEST_ASSERT(!OFP_BSN_FLOW_CLASSIFIER_L3MCUNKNOWN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_FLOW_CLASSIFIER_L3MCUNKNOWN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_FLOW_CLASSIFIER_L3MCUNKNOWN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_FLOW_CLASSIFIER_L3MCUNKNOWN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_FLOW_CLASSIFIER_L3MCUNKNOWN_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_FLOW_CLASSIFIER_L3MCKNOWN;
    TEST_ASSERT(!OFP_BSN_FLOW_CLASSIFIER_L3MCKNOWN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_FLOW_CLASSIFIER_L3MCKNOWN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_FLOW_CLASSIFIER_L3MCKNOWN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_FLOW_CLASSIFIER_L3MCKNOWN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_FLOW_CLASSIFIER_L3MCKNOWN_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_FLOW_CLASSIFIER_L3UCKNOWN;
    TEST_ASSERT(!OFP_BSN_FLOW_CLASSIFIER_L3UCKNOWN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_FLOW_CLASSIFIER_L3UCKNOWN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_FLOW_CLASSIFIER_L3UCKNOWN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_FLOW_CLASSIFIER_L3UCKNOWN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_FLOW_CLASSIFIER_L3UCKNOWN_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_FLOW_CLASSIFIER_L3UCUNKNOWN;
    TEST_ASSERT(!OFP_BSN_FLOW_CLASSIFIER_L3UCUNKNOWN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_FLOW_CLASSIFIER_L3UCUNKNOWN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_FLOW_CLASSIFIER_L3UCUNKNOWN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_FLOW_CLASSIFIER_L3UCUNKNOWN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_FLOW_CLASSIFIER_L3UCUNKNOWN_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_CML_NONE;
    TEST_ASSERT(!OFP_BSN_CML_NONE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_CML_NONE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_CML_NONE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_CML_NONE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_CML_NONE_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_CML_CPU_DROP;
    TEST_ASSERT(!OFP_BSN_CML_CPU_DROP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_CML_CPU_DROP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_CML_CPU_DROP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_CML_CPU_DROP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_CML_CPU_DROP_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_CML_FORWARD;
    TEST_ASSERT(!OFP_BSN_CML_FORWARD_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_CML_FORWARD_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_CML_FORWARD_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_CML_FORWARD_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_CML_FORWARD_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_CML_CPU_FORWARD;
    TEST_ASSERT(!OFP_BSN_CML_CPU_FORWARD_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_CML_CPU_FORWARD_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_CML_CPU_FORWARD_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_CML_CPU_FORWARD_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_CML_CPU_FORWARD_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_IP_FRAGMENTATION_PRESENT;
    TEST_ASSERT(!OFP_BSN_IP_FRAGMENTATION_PRESENT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_IP_FRAGMENTATION_PRESENT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_IP_FRAGMENTATION_PRESENT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_IP_FRAGMENTATION_PRESENT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_IP_FRAGMENTATION_PRESENT_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_IP_FRAGMENTATION_NOT_PRESENT;
    TEST_ASSERT(!OFP_BSN_IP_FRAGMENTATION_NOT_PRESENT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_IP_FRAGMENTATION_NOT_PRESENT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_IP_FRAGMENTATION_NOT_PRESENT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_IP_FRAGMENTATION_NOT_PRESENT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_IP_FRAGMENTATION_NOT_PRESENT_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_ADMIN_STATE_DISABLED;
    TEST_ASSERT(!OFP_BSN_ADMIN_STATE_DISABLED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_ADMIN_STATE_DISABLED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_ADMIN_STATE_DISABLED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_ADMIN_STATE_DISABLED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_ADMIN_STATE_DISABLED_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_ADMIN_STATE_ENABLED;
    TEST_ASSERT(!OFP_BSN_ADMIN_STATE_ENABLED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_ADMIN_STATE_ENABLED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_ADMIN_STATE_ENABLED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_ADMIN_STATE_ENABLED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_ADMIN_STATE_ENABLED_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_VLAN_ALL;
    TEST_ASSERT(!OFP_BSN_VLAN_ALL_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_VLAN_ALL_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_VLAN_ALL_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_VLAN_ALL_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_VLAN_ALL_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_VLAN_COUNTER_RX_BYTES;
    TEST_ASSERT(!OFP_BSN_VLAN_COUNTER_RX_BYTES_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_VLAN_COUNTER_RX_BYTES_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_VLAN_COUNTER_RX_BYTES_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_VLAN_COUNTER_RX_BYTES_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_VLAN_COUNTER_RX_BYTES_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_VLAN_COUNTER_RX_PACKETS;
    TEST_ASSERT(!OFP_BSN_VLAN_COUNTER_RX_PACKETS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_VLAN_COUNTER_RX_PACKETS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_VLAN_COUNTER_RX_PACKETS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_VLAN_COUNTER_RX_PACKETS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_VLAN_COUNTER_RX_PACKETS_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_VLAN_COUNTER_TX_BYTES;
    TEST_ASSERT(!OFP_BSN_VLAN_COUNTER_TX_BYTES_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_VLAN_COUNTER_TX_BYTES_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_VLAN_COUNTER_TX_BYTES_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_VLAN_COUNTER_TX_BYTES_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_VLAN_COUNTER_TX_BYTES_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_VLAN_COUNTER_TX_PACKETS;
    TEST_ASSERT(!OFP_BSN_VLAN_COUNTER_TX_PACKETS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_VLAN_COUNTER_TX_PACKETS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_VLAN_COUNTER_TX_PACKETS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_VLAN_COUNTER_TX_PACKETS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_VLAN_COUNTER_TX_PACKETS_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_VRF_ALL;
    TEST_ASSERT(!OFP_BSN_VRF_ALL_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_VRF_ALL_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_VRF_ALL_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_VRF_ALL_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_VRF_ALL_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_VRF_COUNTER_BYTES;
    TEST_ASSERT(!OFP_BSN_VRF_COUNTER_BYTES_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_VRF_COUNTER_BYTES_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_VRF_COUNTER_BYTES_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_VRF_COUNTER_BYTES_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_VRF_COUNTER_BYTES_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_VRF_COUNTER_PACKETS;
    TEST_ASSERT(!OFP_BSN_VRF_COUNTER_PACKETS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_VRF_COUNTER_PACKETS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_VRF_COUNTER_PACKETS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OFP_BSN_VRF_COUNTER_PACKETS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_VRF_COUNTER_PACKETS_SUPPORTED(OF_VERSION_1_4));
    value = OF_OBJ_TYPE_GET_ASYNC_REQUEST;
    TEST_ASSERT(!OF_OBJ_TYPE_GET_ASYNC_REQUEST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_OBJ_TYPE_GET_ASYNC_REQUEST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_OBJ_TYPE_GET_ASYNC_REQUEST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_OBJ_TYPE_GET_ASYNC_REQUEST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_OBJ_TYPE_GET_ASYNC_REQUEST_SUPPORTED(OF_VERSION_1_4));
    value = OF_OBJ_TYPE_GET_ASYNC_REPLY;
    TEST_ASSERT(!OF_OBJ_TYPE_GET_ASYNC_REPLY_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_OBJ_TYPE_GET_ASYNC_REPLY_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_OBJ_TYPE_GET_ASYNC_REPLY_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_OBJ_TYPE_GET_ASYNC_REPLY_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_OBJ_TYPE_GET_ASYNC_REPLY_SUPPORTED(OF_VERSION_1_4));
    value = OF_OBJ_TYPE_SET_ASYNC;
    TEST_ASSERT(!OF_OBJ_TYPE_SET_ASYNC_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_OBJ_TYPE_SET_ASYNC_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_OBJ_TYPE_SET_ASYNC_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_OBJ_TYPE_SET_ASYNC_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_OBJ_TYPE_SET_ASYNC_SUPPORTED(OF_VERSION_1_4));
    value = OF_OBJ_TYPE_METER_MOD;
    TEST_ASSERT(!OF_OBJ_TYPE_METER_MOD_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_OBJ_TYPE_METER_MOD_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_OBJ_TYPE_METER_MOD_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_OBJ_TYPE_METER_MOD_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_OBJ_TYPE_METER_MOD_SUPPORTED(OF_VERSION_1_4));
    value = OF_TABLE_CONFIG_DEPRECATED_MASK;
    TEST_ASSERT(!OF_TABLE_CONFIG_DEPRECATED_MASK_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_TABLE_CONFIG_DEPRECATED_MASK_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_TABLE_CONFIG_DEPRECATED_MASK_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_TABLE_CONFIG_DEPRECATED_MASK_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_TABLE_CONFIG_DEPRECATED_MASK_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_TABLE_CONFIG_DEPRECATED_MASK_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OF_TABLE_CONFIG_DEPRECATED_MASK_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OF_TABLE_CONFIG_DEPRECATED_MASK_TEST(flags, OF_VERSION_1_3));
    OF_TABLE_CONFIG_DEPRECATED_MASK_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_TABLE_CONFIG_DEPRECATED_MASK_TEST(flags, OF_VERSION_1_3));
    value = OF_PORT_FEATURE_FLAG_BSN_BREAKOUT_CAPABLE;
    TEST_ASSERT(!OF_PORT_FEATURE_FLAG_BSN_BREAKOUT_CAPABLE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_PORT_FEATURE_FLAG_BSN_BREAKOUT_CAPABLE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_PORT_FEATURE_FLAG_BSN_BREAKOUT_CAPABLE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_BSN_BREAKOUT_CAPABLE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_BSN_BREAKOUT_CAPABLE_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_PORT_FEATURE_FLAG_BSN_BREAKOUT_CAPABLE_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OF_PORT_FEATURE_FLAG_BSN_BREAKOUT_CAPABLE_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OF_PORT_FEATURE_FLAG_BSN_BREAKOUT_CAPABLE_TEST(flags, OF_VERSION_1_3));
    OF_PORT_FEATURE_FLAG_BSN_BREAKOUT_CAPABLE_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_PORT_FEATURE_FLAG_BSN_BREAKOUT_CAPABLE_TEST(flags, OF_VERSION_1_3));
    value = OF_IPV6_EXT_HDR_FLAG_NONEXT;
    TEST_ASSERT(!OF_IPV6_EXT_HDR_FLAG_NONEXT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_IPV6_EXT_HDR_FLAG_NONEXT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_IPV6_EXT_HDR_FLAG_NONEXT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_IPV6_EXT_HDR_FLAG_NONEXT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_IPV6_EXT_HDR_FLAG_NONEXT_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_IPV6_EXT_HDR_FLAG_NONEXT_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OF_IPV6_EXT_HDR_FLAG_NONEXT_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OF_IPV6_EXT_HDR_FLAG_NONEXT_TEST(flags, OF_VERSION_1_3));
    OF_IPV6_EXT_HDR_FLAG_NONEXT_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_IPV6_EXT_HDR_FLAG_NONEXT_TEST(flags, OF_VERSION_1_3));
    value = OF_IPV6_EXT_HDR_FLAG_ESP;
    TEST_ASSERT(!OF_IPV6_EXT_HDR_FLAG_ESP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_IPV6_EXT_HDR_FLAG_ESP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_IPV6_EXT_HDR_FLAG_ESP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_IPV6_EXT_HDR_FLAG_ESP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_IPV6_EXT_HDR_FLAG_ESP_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_IPV6_EXT_HDR_FLAG_ESP_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OF_IPV6_EXT_HDR_FLAG_ESP_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OF_IPV6_EXT_HDR_FLAG_ESP_TEST(flags, OF_VERSION_1_3));
    OF_IPV6_EXT_HDR_FLAG_ESP_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_IPV6_EXT_HDR_FLAG_ESP_TEST(flags, OF_VERSION_1_3));
    value = OF_IPV6_EXT_HDR_FLAG_AUTH;
    TEST_ASSERT(!OF_IPV6_EXT_HDR_FLAG_AUTH_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_IPV6_EXT_HDR_FLAG_AUTH_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_IPV6_EXT_HDR_FLAG_AUTH_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_IPV6_EXT_HDR_FLAG_AUTH_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_IPV6_EXT_HDR_FLAG_AUTH_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_IPV6_EXT_HDR_FLAG_AUTH_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OF_IPV6_EXT_HDR_FLAG_AUTH_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OF_IPV6_EXT_HDR_FLAG_AUTH_TEST(flags, OF_VERSION_1_3));
    OF_IPV6_EXT_HDR_FLAG_AUTH_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_IPV6_EXT_HDR_FLAG_AUTH_TEST(flags, OF_VERSION_1_3));
    value = OF_IPV6_EXT_HDR_FLAG_DEST;
    TEST_ASSERT(!OF_IPV6_EXT_HDR_FLAG_DEST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_IPV6_EXT_HDR_FLAG_DEST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_IPV6_EXT_HDR_FLAG_DEST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_IPV6_EXT_HDR_FLAG_DEST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_IPV6_EXT_HDR_FLAG_DEST_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_IPV6_EXT_HDR_FLAG_DEST_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OF_IPV6_EXT_HDR_FLAG_DEST_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OF_IPV6_EXT_HDR_FLAG_DEST_TEST(flags, OF_VERSION_1_3));
    OF_IPV6_EXT_HDR_FLAG_DEST_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_IPV6_EXT_HDR_FLAG_DEST_TEST(flags, OF_VERSION_1_3));
    value = OF_IPV6_EXT_HDR_FLAG_FRAG;
    TEST_ASSERT(!OF_IPV6_EXT_HDR_FLAG_FRAG_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_IPV6_EXT_HDR_FLAG_FRAG_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_IPV6_EXT_HDR_FLAG_FRAG_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_IPV6_EXT_HDR_FLAG_FRAG_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_IPV6_EXT_HDR_FLAG_FRAG_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_IPV6_EXT_HDR_FLAG_FRAG_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OF_IPV6_EXT_HDR_FLAG_FRAG_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OF_IPV6_EXT_HDR_FLAG_FRAG_TEST(flags, OF_VERSION_1_3));
    OF_IPV6_EXT_HDR_FLAG_FRAG_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_IPV6_EXT_HDR_FLAG_FRAG_TEST(flags, OF_VERSION_1_3));
    value = OF_IPV6_EXT_HDR_FLAG_ROUTER;
    TEST_ASSERT(!OF_IPV6_EXT_HDR_FLAG_ROUTER_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_IPV6_EXT_HDR_FLAG_ROUTER_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_IPV6_EXT_HDR_FLAG_ROUTER_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_IPV6_EXT_HDR_FLAG_ROUTER_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_IPV6_EXT_HDR_FLAG_ROUTER_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_IPV6_EXT_HDR_FLAG_ROUTER_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OF_IPV6_EXT_HDR_FLAG_ROUTER_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OF_IPV6_EXT_HDR_FLAG_ROUTER_TEST(flags, OF_VERSION_1_3));
    OF_IPV6_EXT_HDR_FLAG_ROUTER_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_IPV6_EXT_HDR_FLAG_ROUTER_TEST(flags, OF_VERSION_1_3));
    value = OF_IPV6_EXT_HDR_FLAG_HOP;
    TEST_ASSERT(!OF_IPV6_EXT_HDR_FLAG_HOP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_IPV6_EXT_HDR_FLAG_HOP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_IPV6_EXT_HDR_FLAG_HOP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_IPV6_EXT_HDR_FLAG_HOP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_IPV6_EXT_HDR_FLAG_HOP_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_IPV6_EXT_HDR_FLAG_HOP_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OF_IPV6_EXT_HDR_FLAG_HOP_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OF_IPV6_EXT_HDR_FLAG_HOP_TEST(flags, OF_VERSION_1_3));
    OF_IPV6_EXT_HDR_FLAG_HOP_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_IPV6_EXT_HDR_FLAG_HOP_TEST(flags, OF_VERSION_1_3));
    value = OF_IPV6_EXT_HDR_FLAG_UNREP;
    TEST_ASSERT(!OF_IPV6_EXT_HDR_FLAG_UNREP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_IPV6_EXT_HDR_FLAG_UNREP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_IPV6_EXT_HDR_FLAG_UNREP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_IPV6_EXT_HDR_FLAG_UNREP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_IPV6_EXT_HDR_FLAG_UNREP_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_IPV6_EXT_HDR_FLAG_UNREP_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OF_IPV6_EXT_HDR_FLAG_UNREP_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OF_IPV6_EXT_HDR_FLAG_UNREP_TEST(flags, OF_VERSION_1_3));
    OF_IPV6_EXT_HDR_FLAG_UNREP_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_IPV6_EXT_HDR_FLAG_UNREP_TEST(flags, OF_VERSION_1_3));
    value = OF_IPV6_EXT_HDR_FLAG_UNSEQ;
    TEST_ASSERT(!OF_IPV6_EXT_HDR_FLAG_UNSEQ_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_IPV6_EXT_HDR_FLAG_UNSEQ_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_IPV6_EXT_HDR_FLAG_UNSEQ_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_IPV6_EXT_HDR_FLAG_UNSEQ_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_IPV6_EXT_HDR_FLAG_UNSEQ_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_IPV6_EXT_HDR_FLAG_UNSEQ_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OF_IPV6_EXT_HDR_FLAG_UNSEQ_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OF_IPV6_EXT_HDR_FLAG_UNSEQ_TEST(flags, OF_VERSION_1_3));
    OF_IPV6_EXT_HDR_FLAG_UNSEQ_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_IPV6_EXT_HDR_FLAG_UNSEQ_TEST(flags, OF_VERSION_1_3));
    value = OF_ACTION_TYPE_PUSH_PBB;
    TEST_ASSERT(!OF_ACTION_TYPE_PUSH_PBB_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_ACTION_TYPE_PUSH_PBB_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_ACTION_TYPE_PUSH_PBB_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ACTION_TYPE_PUSH_PBB_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ACTION_TYPE_PUSH_PBB_SUPPORTED(OF_VERSION_1_4));
    value = OF_ACTION_TYPE_POP_PBB;
    TEST_ASSERT(!OF_ACTION_TYPE_POP_PBB_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_ACTION_TYPE_POP_PBB_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_ACTION_TYPE_POP_PBB_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ACTION_TYPE_POP_PBB_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ACTION_TYPE_POP_PBB_SUPPORTED(OF_VERSION_1_4));
    value = OF_INSTRUCTION_TYPE_METER;
    TEST_ASSERT(!OF_INSTRUCTION_TYPE_METER_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_INSTRUCTION_TYPE_METER_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_INSTRUCTION_TYPE_METER_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_INSTRUCTION_TYPE_METER_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_INSTRUCTION_TYPE_METER_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_MOD_FLAG_NO_PKT_COUNTS;
    TEST_ASSERT(!OF_FLOW_MOD_FLAG_NO_PKT_COUNTS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_FLOW_MOD_FLAG_NO_PKT_COUNTS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_FLOW_MOD_FLAG_NO_PKT_COUNTS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_FLOW_MOD_FLAG_NO_PKT_COUNTS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_FLOW_MOD_FLAG_NO_PKT_COUNTS_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_FLOW_MOD_FLAG_NO_PKT_COUNTS_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OF_FLOW_MOD_FLAG_NO_PKT_COUNTS_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OF_FLOW_MOD_FLAG_NO_PKT_COUNTS_TEST(flags, OF_VERSION_1_3));
    OF_FLOW_MOD_FLAG_NO_PKT_COUNTS_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_FLOW_MOD_FLAG_NO_PKT_COUNTS_TEST(flags, OF_VERSION_1_3));
    value = OF_FLOW_MOD_FLAG_NO_BYT_COUNTS;
    TEST_ASSERT(!OF_FLOW_MOD_FLAG_NO_BYT_COUNTS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_FLOW_MOD_FLAG_NO_BYT_COUNTS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_FLOW_MOD_FLAG_NO_BYT_COUNTS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_FLOW_MOD_FLAG_NO_BYT_COUNTS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_FLOW_MOD_FLAG_NO_BYT_COUNTS_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_FLOW_MOD_FLAG_NO_BYT_COUNTS_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OF_FLOW_MOD_FLAG_NO_BYT_COUNTS_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OF_FLOW_MOD_FLAG_NO_BYT_COUNTS_TEST(flags, OF_VERSION_1_3));
    OF_FLOW_MOD_FLAG_NO_BYT_COUNTS_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_FLOW_MOD_FLAG_NO_BYT_COUNTS_TEST(flags, OF_VERSION_1_3));
    value = OF_FLOW_MOD_FLAG_BSN_SEND_IDLE;
    TEST_ASSERT(!OF_FLOW_MOD_FLAG_BSN_SEND_IDLE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_FLOW_MOD_FLAG_BSN_SEND_IDLE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_FLOW_MOD_FLAG_BSN_SEND_IDLE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_FLOW_MOD_FLAG_BSN_SEND_IDLE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_FLOW_MOD_FLAG_BSN_SEND_IDLE_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_FLOW_MOD_FLAG_BSN_SEND_IDLE_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OF_FLOW_MOD_FLAG_BSN_SEND_IDLE_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OF_FLOW_MOD_FLAG_BSN_SEND_IDLE_TEST(flags, OF_VERSION_1_3));
    OF_FLOW_MOD_FLAG_BSN_SEND_IDLE_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_FLOW_MOD_FLAG_BSN_SEND_IDLE_TEST(flags, OF_VERSION_1_3));
    value = OF_PACKET_IN_REASON_BSN_NEW_HOST;
    TEST_ASSERT(!OF_PACKET_IN_REASON_BSN_NEW_HOST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_PACKET_IN_REASON_BSN_NEW_HOST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_PACKET_IN_REASON_BSN_NEW_HOST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PACKET_IN_REASON_BSN_NEW_HOST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PACKET_IN_REASON_BSN_NEW_HOST_SUPPORTED(OF_VERSION_1_4));
    value = OF_PACKET_IN_REASON_BSN_STATION_MOVE;
    TEST_ASSERT(!OF_PACKET_IN_REASON_BSN_STATION_MOVE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_PACKET_IN_REASON_BSN_STATION_MOVE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_PACKET_IN_REASON_BSN_STATION_MOVE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PACKET_IN_REASON_BSN_STATION_MOVE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PACKET_IN_REASON_BSN_STATION_MOVE_SUPPORTED(OF_VERSION_1_4));
    value = OF_PACKET_IN_REASON_BSN_BAD_VLAN;
    TEST_ASSERT(!OF_PACKET_IN_REASON_BSN_BAD_VLAN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_PACKET_IN_REASON_BSN_BAD_VLAN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_PACKET_IN_REASON_BSN_BAD_VLAN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PACKET_IN_REASON_BSN_BAD_VLAN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PACKET_IN_REASON_BSN_BAD_VLAN_SUPPORTED(OF_VERSION_1_4));
    value = OF_PACKET_IN_REASON_BSN_DESTINATION_LOOKUP_FAILURE;
    TEST_ASSERT(!OF_PACKET_IN_REASON_BSN_DESTINATION_LOOKUP_FAILURE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_PACKET_IN_REASON_BSN_DESTINATION_LOOKUP_FAILURE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_PACKET_IN_REASON_BSN_DESTINATION_LOOKUP_FAILURE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PACKET_IN_REASON_BSN_DESTINATION_LOOKUP_FAILURE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PACKET_IN_REASON_BSN_DESTINATION_LOOKUP_FAILURE_SUPPORTED(OF_VERSION_1_4));
    value = OF_PACKET_IN_REASON_BSN_NO_ROUTE;
    TEST_ASSERT(!OF_PACKET_IN_REASON_BSN_NO_ROUTE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_PACKET_IN_REASON_BSN_NO_ROUTE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_PACKET_IN_REASON_BSN_NO_ROUTE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PACKET_IN_REASON_BSN_NO_ROUTE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PACKET_IN_REASON_BSN_NO_ROUTE_SUPPORTED(OF_VERSION_1_4));
    value = OF_PACKET_IN_REASON_BSN_ICMP_ECHO_REQUEST;
    TEST_ASSERT(!OF_PACKET_IN_REASON_BSN_ICMP_ECHO_REQUEST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_PACKET_IN_REASON_BSN_ICMP_ECHO_REQUEST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_PACKET_IN_REASON_BSN_ICMP_ECHO_REQUEST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PACKET_IN_REASON_BSN_ICMP_ECHO_REQUEST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PACKET_IN_REASON_BSN_ICMP_ECHO_REQUEST_SUPPORTED(OF_VERSION_1_4));
    value = OF_PACKET_IN_REASON_BSN_DEST_NETWORK_UNREACHABLE;
    TEST_ASSERT(!OF_PACKET_IN_REASON_BSN_DEST_NETWORK_UNREACHABLE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_PACKET_IN_REASON_BSN_DEST_NETWORK_UNREACHABLE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_PACKET_IN_REASON_BSN_DEST_NETWORK_UNREACHABLE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PACKET_IN_REASON_BSN_DEST_NETWORK_UNREACHABLE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PACKET_IN_REASON_BSN_DEST_NETWORK_UNREACHABLE_SUPPORTED(OF_VERSION_1_4));
    value = OF_PACKET_IN_REASON_BSN_DEST_HOST_UNREACHABLE;
    TEST_ASSERT(!OF_PACKET_IN_REASON_BSN_DEST_HOST_UNREACHABLE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_PACKET_IN_REASON_BSN_DEST_HOST_UNREACHABLE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_PACKET_IN_REASON_BSN_DEST_HOST_UNREACHABLE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PACKET_IN_REASON_BSN_DEST_HOST_UNREACHABLE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PACKET_IN_REASON_BSN_DEST_HOST_UNREACHABLE_SUPPORTED(OF_VERSION_1_4));
    value = OF_PACKET_IN_REASON_BSN_DEST_PORT_UNREACHABLE;
    TEST_ASSERT(!OF_PACKET_IN_REASON_BSN_DEST_PORT_UNREACHABLE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_PACKET_IN_REASON_BSN_DEST_PORT_UNREACHABLE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_PACKET_IN_REASON_BSN_DEST_PORT_UNREACHABLE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PACKET_IN_REASON_BSN_DEST_PORT_UNREACHABLE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PACKET_IN_REASON_BSN_DEST_PORT_UNREACHABLE_SUPPORTED(OF_VERSION_1_4));
    value = OF_PACKET_IN_REASON_BSN_FRAGMENTATION_REQUIRED;
    TEST_ASSERT(!OF_PACKET_IN_REASON_BSN_FRAGMENTATION_REQUIRED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_PACKET_IN_REASON_BSN_FRAGMENTATION_REQUIRED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_PACKET_IN_REASON_BSN_FRAGMENTATION_REQUIRED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PACKET_IN_REASON_BSN_FRAGMENTATION_REQUIRED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PACKET_IN_REASON_BSN_FRAGMENTATION_REQUIRED_SUPPORTED(OF_VERSION_1_4));
    value = OF_PACKET_IN_REASON_BSN_ARP;
    TEST_ASSERT(!OF_PACKET_IN_REASON_BSN_ARP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_PACKET_IN_REASON_BSN_ARP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_PACKET_IN_REASON_BSN_ARP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PACKET_IN_REASON_BSN_ARP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PACKET_IN_REASON_BSN_ARP_SUPPORTED(OF_VERSION_1_4));
    value = OF_PACKET_IN_REASON_BSN_DHCP;
    TEST_ASSERT(!OF_PACKET_IN_REASON_BSN_DHCP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_PACKET_IN_REASON_BSN_DHCP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_PACKET_IN_REASON_BSN_DHCP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PACKET_IN_REASON_BSN_DHCP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PACKET_IN_REASON_BSN_DHCP_SUPPORTED(OF_VERSION_1_4));
    value = OF_PACKET_IN_REASON_BSN_DEBUG;
    TEST_ASSERT(!OF_PACKET_IN_REASON_BSN_DEBUG_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_PACKET_IN_REASON_BSN_DEBUG_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_PACKET_IN_REASON_BSN_DEBUG_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PACKET_IN_REASON_BSN_DEBUG_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PACKET_IN_REASON_BSN_DEBUG_SUPPORTED(OF_VERSION_1_4));
    value = OF_PACKET_IN_REASON_BSN_PACKET_OF_DEATH;
    TEST_ASSERT(!OF_PACKET_IN_REASON_BSN_PACKET_OF_DEATH_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_PACKET_IN_REASON_BSN_PACKET_OF_DEATH_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_PACKET_IN_REASON_BSN_PACKET_OF_DEATH_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_PACKET_IN_REASON_BSN_PACKET_OF_DEATH_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PACKET_IN_REASON_BSN_PACKET_OF_DEATH_SUPPORTED(OF_VERSION_1_4));
    value = OF_METER_MAX;
    TEST_ASSERT(!OF_METER_MAX_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_METER_MAX_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_METER_MAX_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_METER_MAX_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_METER_MAX_SUPPORTED(OF_VERSION_1_4));
    value = OF_METER_SLOWPATH;
    TEST_ASSERT(!OF_METER_SLOWPATH_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_METER_SLOWPATH_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_METER_SLOWPATH_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_METER_SLOWPATH_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_METER_SLOWPATH_SUPPORTED(OF_VERSION_1_4));
    value = OF_METER_CONTROLLER;
    TEST_ASSERT(!OF_METER_CONTROLLER_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_METER_CONTROLLER_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_METER_CONTROLLER_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_METER_CONTROLLER_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_METER_CONTROLLER_SUPPORTED(OF_VERSION_1_4));
    value = OF_METER_ALL;
    TEST_ASSERT(!OF_METER_ALL_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_METER_ALL_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_METER_ALL_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_METER_ALL_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_METER_ALL_SUPPORTED(OF_VERSION_1_4));
    value = OF_METER_BAND_TYPE_DROP;
    TEST_ASSERT(!OF_METER_BAND_TYPE_DROP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_METER_BAND_TYPE_DROP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_METER_BAND_TYPE_DROP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_METER_BAND_TYPE_DROP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_METER_BAND_TYPE_DROP_SUPPORTED(OF_VERSION_1_4));
    value = OF_METER_BAND_TYPE_DSCP_REMARK;
    TEST_ASSERT(!OF_METER_BAND_TYPE_DSCP_REMARK_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_METER_BAND_TYPE_DSCP_REMARK_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_METER_BAND_TYPE_DSCP_REMARK_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_METER_BAND_TYPE_DSCP_REMARK_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_METER_BAND_TYPE_DSCP_REMARK_SUPPORTED(OF_VERSION_1_4));
    value = OF_METER_BAND_TYPE_EXPERIMENTER;
    TEST_ASSERT(!OF_METER_BAND_TYPE_EXPERIMENTER_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_METER_BAND_TYPE_EXPERIMENTER_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_METER_BAND_TYPE_EXPERIMENTER_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_METER_BAND_TYPE_EXPERIMENTER_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_METER_BAND_TYPE_EXPERIMENTER_SUPPORTED(OF_VERSION_1_4));
    value = OF_METER_MOD_COMMAND_ADD;
    TEST_ASSERT(!OF_METER_MOD_COMMAND_ADD_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_METER_MOD_COMMAND_ADD_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_METER_MOD_COMMAND_ADD_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_METER_MOD_COMMAND_ADD_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_METER_MOD_COMMAND_ADD_SUPPORTED(OF_VERSION_1_4));
    value = OF_METER_MOD_COMMAND_MODIFY;
    TEST_ASSERT(!OF_METER_MOD_COMMAND_MODIFY_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_METER_MOD_COMMAND_MODIFY_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_METER_MOD_COMMAND_MODIFY_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_METER_MOD_COMMAND_MODIFY_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_METER_MOD_COMMAND_MODIFY_SUPPORTED(OF_VERSION_1_4));
    value = OF_METER_MOD_COMMAND_DELETE;
    TEST_ASSERT(!OF_METER_MOD_COMMAND_DELETE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_METER_MOD_COMMAND_DELETE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_METER_MOD_COMMAND_DELETE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_METER_MOD_COMMAND_DELETE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_METER_MOD_COMMAND_DELETE_SUPPORTED(OF_VERSION_1_4));
    value = OF_METER_FLAG_KBPS;
    TEST_ASSERT(!OF_METER_FLAG_KBPS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_METER_FLAG_KBPS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_METER_FLAG_KBPS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_METER_FLAG_KBPS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_METER_FLAG_KBPS_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_METER_FLAG_KBPS_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OF_METER_FLAG_KBPS_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OF_METER_FLAG_KBPS_TEST(flags, OF_VERSION_1_3));
    OF_METER_FLAG_KBPS_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_METER_FLAG_KBPS_TEST(flags, OF_VERSION_1_3));
    value = OF_METER_FLAG_PKTPS;
    TEST_ASSERT(!OF_METER_FLAG_PKTPS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_METER_FLAG_PKTPS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_METER_FLAG_PKTPS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_METER_FLAG_PKTPS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_METER_FLAG_PKTPS_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_METER_FLAG_PKTPS_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OF_METER_FLAG_PKTPS_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OF_METER_FLAG_PKTPS_TEST(flags, OF_VERSION_1_3));
    OF_METER_FLAG_PKTPS_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_METER_FLAG_PKTPS_TEST(flags, OF_VERSION_1_3));
    value = OF_METER_FLAG_BURST;
    TEST_ASSERT(!OF_METER_FLAG_BURST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_METER_FLAG_BURST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_METER_FLAG_BURST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_METER_FLAG_BURST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_METER_FLAG_BURST_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_METER_FLAG_BURST_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OF_METER_FLAG_BURST_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OF_METER_FLAG_BURST_TEST(flags, OF_VERSION_1_3));
    OF_METER_FLAG_BURST_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_METER_FLAG_BURST_TEST(flags, OF_VERSION_1_3));
    value = OF_METER_FLAG_STATS;
    TEST_ASSERT(!OF_METER_FLAG_STATS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_METER_FLAG_STATS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_METER_FLAG_STATS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_METER_FLAG_STATS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_METER_FLAG_STATS_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_METER_FLAG_STATS_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OF_METER_FLAG_STATS_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OF_METER_FLAG_STATS_TEST(flags, OF_VERSION_1_3));
    OF_METER_FLAG_STATS_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_METER_FLAG_STATS_TEST(flags, OF_VERSION_1_3));
    value = OF_ERROR_TYPE_METER_MOD_FAILED;
    TEST_ASSERT(!OF_ERROR_TYPE_METER_MOD_FAILED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_ERROR_TYPE_METER_MOD_FAILED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_ERROR_TYPE_METER_MOD_FAILED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ERROR_TYPE_METER_MOD_FAILED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ERROR_TYPE_METER_MOD_FAILED_SUPPORTED(OF_VERSION_1_4));
    value = OF_ERROR_TYPE_TABLE_FEATURES_FAILED;
    TEST_ASSERT(!OF_ERROR_TYPE_TABLE_FEATURES_FAILED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_ERROR_TYPE_TABLE_FEATURES_FAILED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_ERROR_TYPE_TABLE_FEATURES_FAILED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_ERROR_TYPE_TABLE_FEATURES_FAILED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ERROR_TYPE_TABLE_FEATURES_FAILED_SUPPORTED(OF_VERSION_1_4));
    value = OF_REQUEST_FAILED_MULTIPART_BUFFER_OVERFLOW;
    TEST_ASSERT(!OF_REQUEST_FAILED_MULTIPART_BUFFER_OVERFLOW_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_REQUEST_FAILED_MULTIPART_BUFFER_OVERFLOW_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_REQUEST_FAILED_MULTIPART_BUFFER_OVERFLOW_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_REQUEST_FAILED_MULTIPART_BUFFER_OVERFLOW_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_REQUEST_FAILED_MULTIPART_BUFFER_OVERFLOW_SUPPORTED(OF_VERSION_1_4));
    value = OF_METER_MOD_FAILED_UNKNOWN;
    TEST_ASSERT(!OF_METER_MOD_FAILED_UNKNOWN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_METER_MOD_FAILED_UNKNOWN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_METER_MOD_FAILED_UNKNOWN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_METER_MOD_FAILED_UNKNOWN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_METER_MOD_FAILED_UNKNOWN_SUPPORTED(OF_VERSION_1_4));
    value = OF_METER_MOD_FAILED_METER_EXISTS;
    TEST_ASSERT(!OF_METER_MOD_FAILED_METER_EXISTS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_METER_MOD_FAILED_METER_EXISTS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_METER_MOD_FAILED_METER_EXISTS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_METER_MOD_FAILED_METER_EXISTS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_METER_MOD_FAILED_METER_EXISTS_SUPPORTED(OF_VERSION_1_4));
    value = OF_METER_MOD_FAILED_INVALID_METER;
    TEST_ASSERT(!OF_METER_MOD_FAILED_INVALID_METER_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_METER_MOD_FAILED_INVALID_METER_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_METER_MOD_FAILED_INVALID_METER_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_METER_MOD_FAILED_INVALID_METER_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_METER_MOD_FAILED_INVALID_METER_SUPPORTED(OF_VERSION_1_4));
    value = OF_METER_MOD_FAILED_UNKNOWN_METER;
    TEST_ASSERT(!OF_METER_MOD_FAILED_UNKNOWN_METER_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_METER_MOD_FAILED_UNKNOWN_METER_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_METER_MOD_FAILED_UNKNOWN_METER_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_METER_MOD_FAILED_UNKNOWN_METER_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_METER_MOD_FAILED_UNKNOWN_METER_SUPPORTED(OF_VERSION_1_4));
    value = OF_METER_MOD_FAILED_BAD_COMMAND;
    TEST_ASSERT(!OF_METER_MOD_FAILED_BAD_COMMAND_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_METER_MOD_FAILED_BAD_COMMAND_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_METER_MOD_FAILED_BAD_COMMAND_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_METER_MOD_FAILED_BAD_COMMAND_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_METER_MOD_FAILED_BAD_COMMAND_SUPPORTED(OF_VERSION_1_4));
    value = OF_METER_MOD_FAILED_BAD_FLAGS;
    TEST_ASSERT(!OF_METER_MOD_FAILED_BAD_FLAGS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_METER_MOD_FAILED_BAD_FLAGS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_METER_MOD_FAILED_BAD_FLAGS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_METER_MOD_FAILED_BAD_FLAGS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_METER_MOD_FAILED_BAD_FLAGS_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_METER_MOD_FAILED_BAD_FLAGS_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OF_METER_MOD_FAILED_BAD_FLAGS_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OF_METER_MOD_FAILED_BAD_FLAGS_TEST(flags, OF_VERSION_1_3));
    OF_METER_MOD_FAILED_BAD_FLAGS_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_METER_MOD_FAILED_BAD_FLAGS_TEST(flags, OF_VERSION_1_3));
    value = OF_METER_MOD_FAILED_BAD_RATE;
    TEST_ASSERT(!OF_METER_MOD_FAILED_BAD_RATE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_METER_MOD_FAILED_BAD_RATE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_METER_MOD_FAILED_BAD_RATE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_METER_MOD_FAILED_BAD_RATE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_METER_MOD_FAILED_BAD_RATE_SUPPORTED(OF_VERSION_1_4));
    value = OF_METER_MOD_FAILED_BAD_BURST;
    TEST_ASSERT(!OF_METER_MOD_FAILED_BAD_BURST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_METER_MOD_FAILED_BAD_BURST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_METER_MOD_FAILED_BAD_BURST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_METER_MOD_FAILED_BAD_BURST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_METER_MOD_FAILED_BAD_BURST_SUPPORTED(OF_VERSION_1_4));
    value = OF_METER_MOD_FAILED_BAD_BAND;
    TEST_ASSERT(!OF_METER_MOD_FAILED_BAD_BAND_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_METER_MOD_FAILED_BAD_BAND_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_METER_MOD_FAILED_BAD_BAND_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_METER_MOD_FAILED_BAD_BAND_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_METER_MOD_FAILED_BAD_BAND_SUPPORTED(OF_VERSION_1_4));
    value = OF_METER_MOD_FAILED_BAD_BAND_VALUE;
    TEST_ASSERT(!OF_METER_MOD_FAILED_BAD_BAND_VALUE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_METER_MOD_FAILED_BAD_BAND_VALUE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_METER_MOD_FAILED_BAD_BAND_VALUE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_METER_MOD_FAILED_BAD_BAND_VALUE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_METER_MOD_FAILED_BAD_BAND_VALUE_SUPPORTED(OF_VERSION_1_4));
    value = OF_METER_MOD_FAILED_OUT_OF_METERS;
    TEST_ASSERT(!OF_METER_MOD_FAILED_OUT_OF_METERS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_METER_MOD_FAILED_OUT_OF_METERS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_METER_MOD_FAILED_OUT_OF_METERS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_METER_MOD_FAILED_OUT_OF_METERS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_METER_MOD_FAILED_OUT_OF_METERS_SUPPORTED(OF_VERSION_1_4));
    value = OF_METER_MOD_FAILED_OUT_OF_BANDS;
    TEST_ASSERT(!OF_METER_MOD_FAILED_OUT_OF_BANDS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_METER_MOD_FAILED_OUT_OF_BANDS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_METER_MOD_FAILED_OUT_OF_BANDS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_METER_MOD_FAILED_OUT_OF_BANDS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_METER_MOD_FAILED_OUT_OF_BANDS_SUPPORTED(OF_VERSION_1_4));
    value = OF_TABLE_REQUEST_FAILED_BAD_TABLE;
    TEST_ASSERT(!OF_TABLE_REQUEST_FAILED_BAD_TABLE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_TABLE_REQUEST_FAILED_BAD_TABLE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_TABLE_REQUEST_FAILED_BAD_TABLE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_TABLE_REQUEST_FAILED_BAD_TABLE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_TABLE_REQUEST_FAILED_BAD_TABLE_SUPPORTED(OF_VERSION_1_4));
    value = OF_TABLE_REQUEST_FAILED_BAD_METADATA;
    TEST_ASSERT(!OF_TABLE_REQUEST_FAILED_BAD_METADATA_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_TABLE_REQUEST_FAILED_BAD_METADATA_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_TABLE_REQUEST_FAILED_BAD_METADATA_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_TABLE_REQUEST_FAILED_BAD_METADATA_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_TABLE_REQUEST_FAILED_BAD_METADATA_SUPPORTED(OF_VERSION_1_4));
    value = OF_TABLE_REQUEST_FAILED_BAD_TYPE;
    TEST_ASSERT(!OF_TABLE_REQUEST_FAILED_BAD_TYPE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_TABLE_REQUEST_FAILED_BAD_TYPE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_TABLE_REQUEST_FAILED_BAD_TYPE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_TABLE_REQUEST_FAILED_BAD_TYPE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_TABLE_REQUEST_FAILED_BAD_TYPE_SUPPORTED(OF_VERSION_1_4));
    value = OF_TABLE_REQUEST_FAILED_BAD_LEN;
    TEST_ASSERT(!OF_TABLE_REQUEST_FAILED_BAD_LEN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_TABLE_REQUEST_FAILED_BAD_LEN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_TABLE_REQUEST_FAILED_BAD_LEN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_TABLE_REQUEST_FAILED_BAD_LEN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_TABLE_REQUEST_FAILED_BAD_LEN_SUPPORTED(OF_VERSION_1_4));
    value = OF_TABLE_REQUEST_FAILED_BAD_ARGUMENT;
    TEST_ASSERT(!OF_TABLE_REQUEST_FAILED_BAD_ARGUMENT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_TABLE_REQUEST_FAILED_BAD_ARGUMENT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_TABLE_REQUEST_FAILED_BAD_ARGUMENT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_TABLE_REQUEST_FAILED_BAD_ARGUMENT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(!OF_TABLE_REQUEST_FAILED_BAD_ARGUMENT_SUPPORTED(OF_VERSION_1_4));
    value = OF_TABLE_REQUEST_FAILED_EPERM;
    TEST_ASSERT(!OF_TABLE_REQUEST_FAILED_EPERM_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_TABLE_REQUEST_FAILED_EPERM_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_TABLE_REQUEST_FAILED_EPERM_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_TABLE_REQUEST_FAILED_EPERM_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_TABLE_REQUEST_FAILED_EPERM_SUPPORTED(OF_VERSION_1_4));
    value = OF_STATS_TYPE_METER;
    TEST_ASSERT(!OF_STATS_TYPE_METER_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_STATS_TYPE_METER_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_STATS_TYPE_METER_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_STATS_TYPE_METER_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_STATS_TYPE_METER_SUPPORTED(OF_VERSION_1_4));
    value = OF_STATS_TYPE_METER_CONFIG;
    TEST_ASSERT(!OF_STATS_TYPE_METER_CONFIG_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_STATS_TYPE_METER_CONFIG_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_STATS_TYPE_METER_CONFIG_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_STATS_TYPE_METER_CONFIG_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_STATS_TYPE_METER_CONFIG_SUPPORTED(OF_VERSION_1_4));
    value = OF_STATS_TYPE_METER_FEATURES;
    TEST_ASSERT(!OF_STATS_TYPE_METER_FEATURES_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_STATS_TYPE_METER_FEATURES_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_STATS_TYPE_METER_FEATURES_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_STATS_TYPE_METER_FEATURES_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_STATS_TYPE_METER_FEATURES_SUPPORTED(OF_VERSION_1_4));
    value = OF_STATS_TYPE_TABLE_FEATURES;
    TEST_ASSERT(!OF_STATS_TYPE_TABLE_FEATURES_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_STATS_TYPE_TABLE_FEATURES_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_STATS_TYPE_TABLE_FEATURES_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_STATS_TYPE_TABLE_FEATURES_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_STATS_TYPE_TABLE_FEATURES_SUPPORTED(OF_VERSION_1_4));
    value = OF_STATS_TYPE_PORT_DESC;
    TEST_ASSERT(!OF_STATS_TYPE_PORT_DESC_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_STATS_TYPE_PORT_DESC_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_STATS_TYPE_PORT_DESC_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_STATS_TYPE_PORT_DESC_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_STATS_TYPE_PORT_DESC_SUPPORTED(OF_VERSION_1_4));
    value = OF_STATS_REPLY_FLAG_REQ_MORE;
    TEST_ASSERT(!OF_STATS_REPLY_FLAG_REQ_MORE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_STATS_REPLY_FLAG_REQ_MORE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_STATS_REPLY_FLAG_REQ_MORE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_STATS_REPLY_FLAG_REQ_MORE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_STATS_REPLY_FLAG_REQ_MORE_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_STATS_REPLY_FLAG_REQ_MORE_SET(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == OF_STATS_REPLY_FLAG_REQ_MORE_BY_VERSION(OF_VERSION_1_3));
    TEST_ASSERT(OF_STATS_REPLY_FLAG_REQ_MORE_TEST(flags, OF_VERSION_1_3));
    OF_STATS_REPLY_FLAG_REQ_MORE_CLEAR(flags, OF_VERSION_1_3);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_STATS_REPLY_FLAG_REQ_MORE_TEST(flags, OF_VERSION_1_3));
    value = OF_TABLE_FEATURE_INSTRUCTIONS;
    TEST_ASSERT(!OF_TABLE_FEATURE_INSTRUCTIONS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_TABLE_FEATURE_INSTRUCTIONS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_TABLE_FEATURE_INSTRUCTIONS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_TABLE_FEATURE_INSTRUCTIONS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_TABLE_FEATURE_INSTRUCTIONS_SUPPORTED(OF_VERSION_1_4));
    value = OF_TABLE_FEATURE_INSTRUCTIONS_MISS;
    TEST_ASSERT(!OF_TABLE_FEATURE_INSTRUCTIONS_MISS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_TABLE_FEATURE_INSTRUCTIONS_MISS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_TABLE_FEATURE_INSTRUCTIONS_MISS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_TABLE_FEATURE_INSTRUCTIONS_MISS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_TABLE_FEATURE_INSTRUCTIONS_MISS_SUPPORTED(OF_VERSION_1_4));
    value = OF_TABLE_FEATURE_NEXT_TABLES;
    TEST_ASSERT(!OF_TABLE_FEATURE_NEXT_TABLES_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_TABLE_FEATURE_NEXT_TABLES_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_TABLE_FEATURE_NEXT_TABLES_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_TABLE_FEATURE_NEXT_TABLES_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_TABLE_FEATURE_NEXT_TABLES_SUPPORTED(OF_VERSION_1_4));
    value = OF_TABLE_FEATURE_NEXT_TABLES_MISS;
    TEST_ASSERT(!OF_TABLE_FEATURE_NEXT_TABLES_MISS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_TABLE_FEATURE_NEXT_TABLES_MISS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_TABLE_FEATURE_NEXT_TABLES_MISS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_TABLE_FEATURE_NEXT_TABLES_MISS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_TABLE_FEATURE_NEXT_TABLES_MISS_SUPPORTED(OF_VERSION_1_4));
    value = OF_TABLE_FEATURE_WRITE_ACTIONS;
    TEST_ASSERT(!OF_TABLE_FEATURE_WRITE_ACTIONS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_TABLE_FEATURE_WRITE_ACTIONS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_TABLE_FEATURE_WRITE_ACTIONS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_TABLE_FEATURE_WRITE_ACTIONS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_TABLE_FEATURE_WRITE_ACTIONS_SUPPORTED(OF_VERSION_1_4));
    value = OF_TABLE_FEATURE_WRITE_ACTIONS_MISS;
    TEST_ASSERT(!OF_TABLE_FEATURE_WRITE_ACTIONS_MISS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_TABLE_FEATURE_WRITE_ACTIONS_MISS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_TABLE_FEATURE_WRITE_ACTIONS_MISS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_TABLE_FEATURE_WRITE_ACTIONS_MISS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_TABLE_FEATURE_WRITE_ACTIONS_MISS_SUPPORTED(OF_VERSION_1_4));
    value = OF_TABLE_FEATURE_APPLY_ACTIONS;
    TEST_ASSERT(!OF_TABLE_FEATURE_APPLY_ACTIONS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_TABLE_FEATURE_APPLY_ACTIONS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_TABLE_FEATURE_APPLY_ACTIONS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_TABLE_FEATURE_APPLY_ACTIONS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_TABLE_FEATURE_APPLY_ACTIONS_SUPPORTED(OF_VERSION_1_4));
    value = OF_TABLE_FEATURE_APPLY_ACTIONS_MISS;
    TEST_ASSERT(!OF_TABLE_FEATURE_APPLY_ACTIONS_MISS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_TABLE_FEATURE_APPLY_ACTIONS_MISS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_TABLE_FEATURE_APPLY_ACTIONS_MISS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_TABLE_FEATURE_APPLY_ACTIONS_MISS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_TABLE_FEATURE_APPLY_ACTIONS_MISS_SUPPORTED(OF_VERSION_1_4));
    value = OF_TABLE_FEATURE_MATCH;
    TEST_ASSERT(!OF_TABLE_FEATURE_MATCH_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_TABLE_FEATURE_MATCH_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_TABLE_FEATURE_MATCH_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_TABLE_FEATURE_MATCH_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_TABLE_FEATURE_MATCH_SUPPORTED(OF_VERSION_1_4));
    value = OF_TABLE_FEATURE_WILDCARDS;
    TEST_ASSERT(!OF_TABLE_FEATURE_WILDCARDS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_TABLE_FEATURE_WILDCARDS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_TABLE_FEATURE_WILDCARDS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_TABLE_FEATURE_WILDCARDS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_TABLE_FEATURE_WILDCARDS_SUPPORTED(OF_VERSION_1_4));
    value = OF_TABLE_FEATURE_WRITE_SETFIELD;
    TEST_ASSERT(!OF_TABLE_FEATURE_WRITE_SETFIELD_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_TABLE_FEATURE_WRITE_SETFIELD_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_TABLE_FEATURE_WRITE_SETFIELD_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_TABLE_FEATURE_WRITE_SETFIELD_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_TABLE_FEATURE_WRITE_SETFIELD_SUPPORTED(OF_VERSION_1_4));
    value = OF_TABLE_FEATURE_WRITE_SETFIELD_MISS;
    TEST_ASSERT(!OF_TABLE_FEATURE_WRITE_SETFIELD_MISS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_TABLE_FEATURE_WRITE_SETFIELD_MISS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_TABLE_FEATURE_WRITE_SETFIELD_MISS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_TABLE_FEATURE_WRITE_SETFIELD_MISS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_TABLE_FEATURE_WRITE_SETFIELD_MISS_SUPPORTED(OF_VERSION_1_4));
    value = OF_TABLE_FEATURE_APPLY_SETFIELD;
    TEST_ASSERT(!OF_TABLE_FEATURE_APPLY_SETFIELD_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_TABLE_FEATURE_APPLY_SETFIELD_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_TABLE_FEATURE_APPLY_SETFIELD_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_TABLE_FEATURE_APPLY_SETFIELD_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_TABLE_FEATURE_APPLY_SETFIELD_SUPPORTED(OF_VERSION_1_4));
    value = OF_TABLE_FEATURE_APPLY_SETFIELD_MISS;
    TEST_ASSERT(!OF_TABLE_FEATURE_APPLY_SETFIELD_MISS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_TABLE_FEATURE_APPLY_SETFIELD_MISS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_TABLE_FEATURE_APPLY_SETFIELD_MISS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_TABLE_FEATURE_APPLY_SETFIELD_MISS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_TABLE_FEATURE_APPLY_SETFIELD_MISS_SUPPORTED(OF_VERSION_1_4));
    value = OF_TABLE_FEATURE_EXPERIMENTER;
    TEST_ASSERT(!OF_TABLE_FEATURE_EXPERIMENTER_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_TABLE_FEATURE_EXPERIMENTER_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_TABLE_FEATURE_EXPERIMENTER_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_TABLE_FEATURE_EXPERIMENTER_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_TABLE_FEATURE_EXPERIMENTER_SUPPORTED(OF_VERSION_1_4));
    value = OF_TABLE_FEATURE_EXPERIMENTER_MISS;
    TEST_ASSERT(!OF_TABLE_FEATURE_EXPERIMENTER_MISS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_TABLE_FEATURE_EXPERIMENTER_MISS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_TABLE_FEATURE_EXPERIMENTER_MISS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_TABLE_FEATURE_EXPERIMENTER_MISS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_TABLE_FEATURE_EXPERIMENTER_MISS_SUPPORTED(OF_VERSION_1_4));
    value = OF_HELLO_ELEM_TYPE__VERSIONBITMAP;
    TEST_ASSERT(!OF_HELLO_ELEM_TYPE__VERSIONBITMAP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_HELLO_ELEM_TYPE__VERSIONBITMAP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_HELLO_ELEM_TYPE__VERSIONBITMAP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(OF_HELLO_ELEM_TYPE__VERSIONBITMAP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_HELLO_ELEM_TYPE__VERSIONBITMAP_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_FEC_CONFIG_STATE_UNSET;
    TEST_ASSERT(!OFP_BSN_FEC_CONFIG_STATE_UNSET_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_FEC_CONFIG_STATE_UNSET_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_FEC_CONFIG_STATE_UNSET_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFP_BSN_FEC_CONFIG_STATE_UNSET_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_FEC_CONFIG_STATE_UNSET_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_FEC_CONFIG_STATE_ENABLED;
    TEST_ASSERT(!OFP_BSN_FEC_CONFIG_STATE_ENABLED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_FEC_CONFIG_STATE_ENABLED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_FEC_CONFIG_STATE_ENABLED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFP_BSN_FEC_CONFIG_STATE_ENABLED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_FEC_CONFIG_STATE_ENABLED_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_FEC_CONFIG_STATE_DISABLED;
    TEST_ASSERT(!OFP_BSN_FEC_CONFIG_STATE_DISABLED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_FEC_CONFIG_STATE_DISABLED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_FEC_CONFIG_STATE_DISABLED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFP_BSN_FEC_CONFIG_STATE_DISABLED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_FEC_CONFIG_STATE_DISABLED_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_SPEED_CAP_10M;
    TEST_ASSERT(!OFP_BSN_SPEED_CAP_10M_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_SPEED_CAP_10M_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_SPEED_CAP_10M_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFP_BSN_SPEED_CAP_10M_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_SPEED_CAP_10M_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_SPEED_CAP_100M;
    TEST_ASSERT(!OFP_BSN_SPEED_CAP_100M_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_SPEED_CAP_100M_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_SPEED_CAP_100M_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFP_BSN_SPEED_CAP_100M_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_SPEED_CAP_100M_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_SPEED_CAP_1GB;
    TEST_ASSERT(!OFP_BSN_SPEED_CAP_1GB_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_SPEED_CAP_1GB_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_SPEED_CAP_1GB_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFP_BSN_SPEED_CAP_1GB_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_SPEED_CAP_1GB_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_SPEED_CAP_10GB;
    TEST_ASSERT(!OFP_BSN_SPEED_CAP_10GB_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_SPEED_CAP_10GB_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_SPEED_CAP_10GB_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFP_BSN_SPEED_CAP_10GB_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_SPEED_CAP_10GB_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_SPEED_CAP_25GB;
    TEST_ASSERT(!OFP_BSN_SPEED_CAP_25GB_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_SPEED_CAP_25GB_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_SPEED_CAP_25GB_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFP_BSN_SPEED_CAP_25GB_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_SPEED_CAP_25GB_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_SPEED_CAP_40GB;
    TEST_ASSERT(!OFP_BSN_SPEED_CAP_40GB_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_SPEED_CAP_40GB_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_SPEED_CAP_40GB_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFP_BSN_SPEED_CAP_40GB_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_SPEED_CAP_40GB_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_SPEED_CAP_50GB;
    TEST_ASSERT(!OFP_BSN_SPEED_CAP_50GB_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_SPEED_CAP_50GB_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_SPEED_CAP_50GB_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFP_BSN_SPEED_CAP_50GB_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_SPEED_CAP_50GB_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_SPEED_CAP_100GB;
    TEST_ASSERT(!OFP_BSN_SPEED_CAP_100GB_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_SPEED_CAP_100GB_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_SPEED_CAP_100GB_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFP_BSN_SPEED_CAP_100GB_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_SPEED_CAP_100GB_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_MISC_CAP_FEC;
    TEST_ASSERT(!OFP_BSN_MISC_CAP_FEC_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_MISC_CAP_FEC_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_MISC_CAP_FEC_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFP_BSN_MISC_CAP_FEC_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_MISC_CAP_FEC_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_EXT_CAP_AN;
    TEST_ASSERT(!OFP_BSN_EXT_CAP_AN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_EXT_CAP_AN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_EXT_CAP_AN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFP_BSN_EXT_CAP_AN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_EXT_CAP_AN_SUPPORTED(OF_VERSION_1_4));
    value = OFP_BSN_EXT_CAP_FEC;
    TEST_ASSERT(!OFP_BSN_EXT_CAP_FEC_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFP_BSN_EXT_CAP_FEC_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFP_BSN_EXT_CAP_FEC_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFP_BSN_EXT_CAP_FEC_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFP_BSN_EXT_CAP_FEC_SUPPORTED(OF_VERSION_1_4));
    value = OF_OBJ_TYPE_ROLE_STATUS;
    TEST_ASSERT(!OF_OBJ_TYPE_ROLE_STATUS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_OBJ_TYPE_ROLE_STATUS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_OBJ_TYPE_ROLE_STATUS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_OBJ_TYPE_ROLE_STATUS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_OBJ_TYPE_ROLE_STATUS_SUPPORTED(OF_VERSION_1_4));
    value = OF_OBJ_TYPE_TABLE_STATUS;
    TEST_ASSERT(!OF_OBJ_TYPE_TABLE_STATUS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_OBJ_TYPE_TABLE_STATUS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_OBJ_TYPE_TABLE_STATUS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_OBJ_TYPE_TABLE_STATUS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_OBJ_TYPE_TABLE_STATUS_SUPPORTED(OF_VERSION_1_4));
    value = OF_OBJ_TYPE_REQUESTFORWARD;
    TEST_ASSERT(!OF_OBJ_TYPE_REQUESTFORWARD_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_OBJ_TYPE_REQUESTFORWARD_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_OBJ_TYPE_REQUESTFORWARD_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_OBJ_TYPE_REQUESTFORWARD_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_OBJ_TYPE_REQUESTFORWARD_SUPPORTED(OF_VERSION_1_4));
    value = OF_OBJ_TYPE_BUNDLE_CONTROL;
    TEST_ASSERT(!OF_OBJ_TYPE_BUNDLE_CONTROL_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_OBJ_TYPE_BUNDLE_CONTROL_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_OBJ_TYPE_BUNDLE_CONTROL_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_OBJ_TYPE_BUNDLE_CONTROL_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_OBJ_TYPE_BUNDLE_CONTROL_SUPPORTED(OF_VERSION_1_4));
    value = OF_OBJ_TYPE_BUNDLE_ADD_MESSAGE;
    TEST_ASSERT(!OF_OBJ_TYPE_BUNDLE_ADD_MESSAGE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_OBJ_TYPE_BUNDLE_ADD_MESSAGE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_OBJ_TYPE_BUNDLE_ADD_MESSAGE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_OBJ_TYPE_BUNDLE_ADD_MESSAGE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_OBJ_TYPE_BUNDLE_ADD_MESSAGE_SUPPORTED(OF_VERSION_1_4));
    value = OF_TABLE_CONFIG_EVICTION;
    TEST_ASSERT(!OF_TABLE_CONFIG_EVICTION_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_TABLE_CONFIG_EVICTION_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_TABLE_CONFIG_EVICTION_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_TABLE_CONFIG_EVICTION_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_TABLE_CONFIG_EVICTION_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_TABLE_CONFIG_EVICTION_SET(flags, OF_VERSION_1_4);
    TEST_ASSERT(flags == OF_TABLE_CONFIG_EVICTION_BY_VERSION(OF_VERSION_1_4));
    TEST_ASSERT(OF_TABLE_CONFIG_EVICTION_TEST(flags, OF_VERSION_1_4));
    OF_TABLE_CONFIG_EVICTION_CLEAR(flags, OF_VERSION_1_4);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_TABLE_CONFIG_EVICTION_TEST(flags, OF_VERSION_1_4));
    value = OF_TABLE_CONFIG_VACANCY_EVENTS;
    TEST_ASSERT(!OF_TABLE_CONFIG_VACANCY_EVENTS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_TABLE_CONFIG_VACANCY_EVENTS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_TABLE_CONFIG_VACANCY_EVENTS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_TABLE_CONFIG_VACANCY_EVENTS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_TABLE_CONFIG_VACANCY_EVENTS_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OF_TABLE_CONFIG_VACANCY_EVENTS_SET(flags, OF_VERSION_1_4);
    TEST_ASSERT(flags == OF_TABLE_CONFIG_VACANCY_EVENTS_BY_VERSION(OF_VERSION_1_4));
    TEST_ASSERT(OF_TABLE_CONFIG_VACANCY_EVENTS_TEST(flags, OF_VERSION_1_4));
    OF_TABLE_CONFIG_VACANCY_EVENTS_CLEAR(flags, OF_VERSION_1_4);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OF_TABLE_CONFIG_VACANCY_EVENTS_TEST(flags, OF_VERSION_1_4));
    value = OF_PACKET_IN_REASON_ACTION_SET;
    TEST_ASSERT(!OF_PACKET_IN_REASON_ACTION_SET_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_PACKET_IN_REASON_ACTION_SET_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_PACKET_IN_REASON_ACTION_SET_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_PACKET_IN_REASON_ACTION_SET_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PACKET_IN_REASON_ACTION_SET_SUPPORTED(OF_VERSION_1_4));
    value = OF_PACKET_IN_REASON_GROUP;
    TEST_ASSERT(!OF_PACKET_IN_REASON_GROUP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_PACKET_IN_REASON_GROUP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_PACKET_IN_REASON_GROUP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_PACKET_IN_REASON_GROUP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PACKET_IN_REASON_GROUP_SUPPORTED(OF_VERSION_1_4));
    value = OF_PACKET_IN_REASON_PACKET_OUT;
    TEST_ASSERT(!OF_PACKET_IN_REASON_PACKET_OUT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_PACKET_IN_REASON_PACKET_OUT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_PACKET_IN_REASON_PACKET_OUT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_PACKET_IN_REASON_PACKET_OUT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_PACKET_IN_REASON_PACKET_OUT_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_REMOVED_REASON_METER_DELETE;
    TEST_ASSERT(!OF_FLOW_REMOVED_REASON_METER_DELETE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_FLOW_REMOVED_REASON_METER_DELETE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_FLOW_REMOVED_REASON_METER_DELETE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_FLOW_REMOVED_REASON_METER_DELETE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_FLOW_REMOVED_REASON_METER_DELETE_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_REMOVED_REASON_EVICTION;
    TEST_ASSERT(!OF_FLOW_REMOVED_REASON_EVICTION_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_FLOW_REMOVED_REASON_EVICTION_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_FLOW_REMOVED_REASON_EVICTION_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_FLOW_REMOVED_REASON_EVICTION_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_FLOW_REMOVED_REASON_EVICTION_SUPPORTED(OF_VERSION_1_4));
    value = OF_ERROR_TYPE_BAD_PROPERTY;
    TEST_ASSERT(!OF_ERROR_TYPE_BAD_PROPERTY_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_ERROR_TYPE_BAD_PROPERTY_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_ERROR_TYPE_BAD_PROPERTY_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_ERROR_TYPE_BAD_PROPERTY_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ERROR_TYPE_BAD_PROPERTY_SUPPORTED(OF_VERSION_1_4));
    value = OF_ERROR_TYPE_ASYNC_CONFIG_FAILED;
    TEST_ASSERT(!OF_ERROR_TYPE_ASYNC_CONFIG_FAILED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_ERROR_TYPE_ASYNC_CONFIG_FAILED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_ERROR_TYPE_ASYNC_CONFIG_FAILED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_ERROR_TYPE_ASYNC_CONFIG_FAILED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ERROR_TYPE_ASYNC_CONFIG_FAILED_SUPPORTED(OF_VERSION_1_4));
    value = OF_ERROR_TYPE_FLOW_MONITOR_FAILED;
    TEST_ASSERT(!OF_ERROR_TYPE_FLOW_MONITOR_FAILED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_ERROR_TYPE_FLOW_MONITOR_FAILED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_ERROR_TYPE_FLOW_MONITOR_FAILED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_ERROR_TYPE_FLOW_MONITOR_FAILED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ERROR_TYPE_FLOW_MONITOR_FAILED_SUPPORTED(OF_VERSION_1_4));
    value = OF_ERROR_TYPE_BUNDLE_FAILED;
    TEST_ASSERT(!OF_ERROR_TYPE_BUNDLE_FAILED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_ERROR_TYPE_BUNDLE_FAILED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_ERROR_TYPE_BUNDLE_FAILED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_ERROR_TYPE_BUNDLE_FAILED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_ERROR_TYPE_BUNDLE_FAILED_SUPPORTED(OF_VERSION_1_4));
    value = OF_REQUEST_FAILED_MULTIPART_REQUEST_TIMEOUT;
    TEST_ASSERT(!OF_REQUEST_FAILED_MULTIPART_REQUEST_TIMEOUT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_REQUEST_FAILED_MULTIPART_REQUEST_TIMEOUT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_REQUEST_FAILED_MULTIPART_REQUEST_TIMEOUT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_REQUEST_FAILED_MULTIPART_REQUEST_TIMEOUT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_REQUEST_FAILED_MULTIPART_REQUEST_TIMEOUT_SUPPORTED(OF_VERSION_1_4));
    value = OF_REQUEST_FAILED_MULTIPART_REPLY_TIMEOUT;
    TEST_ASSERT(!OF_REQUEST_FAILED_MULTIPART_REPLY_TIMEOUT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_REQUEST_FAILED_MULTIPART_REPLY_TIMEOUT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_REQUEST_FAILED_MULTIPART_REPLY_TIMEOUT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_REQUEST_FAILED_MULTIPART_REPLY_TIMEOUT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_REQUEST_FAILED_MULTIPART_REPLY_TIMEOUT_SUPPORTED(OF_VERSION_1_4));
    value = OF_INSTRUCTION_FAILED_DUP_INST;
    TEST_ASSERT(!OF_INSTRUCTION_FAILED_DUP_INST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_INSTRUCTION_FAILED_DUP_INST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_INSTRUCTION_FAILED_DUP_INST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_INSTRUCTION_FAILED_DUP_INST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_INSTRUCTION_FAILED_DUP_INST_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_MOD_FAILED_CANT_SYNC;
    TEST_ASSERT(!OF_FLOW_MOD_FAILED_CANT_SYNC_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_FLOW_MOD_FAILED_CANT_SYNC_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_FLOW_MOD_FAILED_CANT_SYNC_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_FLOW_MOD_FAILED_CANT_SYNC_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_FLOW_MOD_FAILED_CANT_SYNC_SUPPORTED(OF_VERSION_1_4));
    value = OF_FLOW_MOD_FAILED_BAD_PRIORITY;
    TEST_ASSERT(!OF_FLOW_MOD_FAILED_BAD_PRIORITY_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_FLOW_MOD_FAILED_BAD_PRIORITY_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_FLOW_MOD_FAILED_BAD_PRIORITY_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_FLOW_MOD_FAILED_BAD_PRIORITY_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_FLOW_MOD_FAILED_BAD_PRIORITY_SUPPORTED(OF_VERSION_1_4));
    value = OFPBPC_BAD_TYPE;
    TEST_ASSERT(!OFPBPC_BAD_TYPE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPBPC_BAD_TYPE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPBPC_BAD_TYPE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPBPC_BAD_TYPE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPBPC_BAD_TYPE_SUPPORTED(OF_VERSION_1_4));
    value = OFPBPC_BAD_LEN;
    TEST_ASSERT(!OFPBPC_BAD_LEN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPBPC_BAD_LEN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPBPC_BAD_LEN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPBPC_BAD_LEN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPBPC_BAD_LEN_SUPPORTED(OF_VERSION_1_4));
    value = OFPBPC_BAD_VALUE;
    TEST_ASSERT(!OFPBPC_BAD_VALUE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPBPC_BAD_VALUE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPBPC_BAD_VALUE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPBPC_BAD_VALUE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPBPC_BAD_VALUE_SUPPORTED(OF_VERSION_1_4));
    value = OFPBPC_TOO_MANY;
    TEST_ASSERT(!OFPBPC_TOO_MANY_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPBPC_TOO_MANY_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPBPC_TOO_MANY_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPBPC_TOO_MANY_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPBPC_TOO_MANY_SUPPORTED(OF_VERSION_1_4));
    value = OFPBPC_DUP_TYPE;
    TEST_ASSERT(!OFPBPC_DUP_TYPE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPBPC_DUP_TYPE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPBPC_DUP_TYPE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPBPC_DUP_TYPE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPBPC_DUP_TYPE_SUPPORTED(OF_VERSION_1_4));
    value = OFPBPC_BAD_EXPERIMENTER;
    TEST_ASSERT(!OFPBPC_BAD_EXPERIMENTER_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPBPC_BAD_EXPERIMENTER_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPBPC_BAD_EXPERIMENTER_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPBPC_BAD_EXPERIMENTER_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPBPC_BAD_EXPERIMENTER_SUPPORTED(OF_VERSION_1_4));
    value = OFPBPC_BAD_EXP_TYPE;
    TEST_ASSERT(!OFPBPC_BAD_EXP_TYPE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPBPC_BAD_EXP_TYPE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPBPC_BAD_EXP_TYPE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPBPC_BAD_EXP_TYPE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPBPC_BAD_EXP_TYPE_SUPPORTED(OF_VERSION_1_4));
    value = OFPBPC_BAD_EXP_VALUE;
    TEST_ASSERT(!OFPBPC_BAD_EXP_VALUE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPBPC_BAD_EXP_VALUE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPBPC_BAD_EXP_VALUE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPBPC_BAD_EXP_VALUE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPBPC_BAD_EXP_VALUE_SUPPORTED(OF_VERSION_1_4));
    value = OFPBPC_EPERM;
    TEST_ASSERT(!OFPBPC_EPERM_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPBPC_EPERM_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPBPC_EPERM_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPBPC_EPERM_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPBPC_EPERM_SUPPORTED(OF_VERSION_1_4));
    value = OFPACFC_INVALID;
    TEST_ASSERT(!OFPACFC_INVALID_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPACFC_INVALID_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPACFC_INVALID_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPACFC_INVALID_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPACFC_INVALID_SUPPORTED(OF_VERSION_1_4));
    value = OFPACFC_UNSUPPORTED;
    TEST_ASSERT(!OFPACFC_UNSUPPORTED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPACFC_UNSUPPORTED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPACFC_UNSUPPORTED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPACFC_UNSUPPORTED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPACFC_UNSUPPORTED_SUPPORTED(OF_VERSION_1_4));
    value = OFPACFC_EPERM;
    TEST_ASSERT(!OFPACFC_EPERM_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPACFC_EPERM_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPACFC_EPERM_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPACFC_EPERM_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPACFC_EPERM_SUPPORTED(OF_VERSION_1_4));
    value = OFPMOFC_UNKNOWN;
    TEST_ASSERT(!OFPMOFC_UNKNOWN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPMOFC_UNKNOWN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPMOFC_UNKNOWN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPMOFC_UNKNOWN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPMOFC_UNKNOWN_SUPPORTED(OF_VERSION_1_4));
    value = OFPMOFC_MONITOR_EXISTS;
    TEST_ASSERT(!OFPMOFC_MONITOR_EXISTS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPMOFC_MONITOR_EXISTS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPMOFC_MONITOR_EXISTS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPMOFC_MONITOR_EXISTS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPMOFC_MONITOR_EXISTS_SUPPORTED(OF_VERSION_1_4));
    value = OFPMOFC_INVALID_MONITOR;
    TEST_ASSERT(!OFPMOFC_INVALID_MONITOR_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPMOFC_INVALID_MONITOR_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPMOFC_INVALID_MONITOR_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPMOFC_INVALID_MONITOR_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPMOFC_INVALID_MONITOR_SUPPORTED(OF_VERSION_1_4));
    value = OFPMOFC_UNKNOWN_MONITOR;
    TEST_ASSERT(!OFPMOFC_UNKNOWN_MONITOR_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPMOFC_UNKNOWN_MONITOR_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPMOFC_UNKNOWN_MONITOR_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPMOFC_UNKNOWN_MONITOR_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPMOFC_UNKNOWN_MONITOR_SUPPORTED(OF_VERSION_1_4));
    value = OFPMOFC_BAD_COMMAND;
    TEST_ASSERT(!OFPMOFC_BAD_COMMAND_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPMOFC_BAD_COMMAND_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPMOFC_BAD_COMMAND_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPMOFC_BAD_COMMAND_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPMOFC_BAD_COMMAND_SUPPORTED(OF_VERSION_1_4));
    value = OFPMOFC_BAD_FLAGS;
    TEST_ASSERT(!OFPMOFC_BAD_FLAGS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPMOFC_BAD_FLAGS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPMOFC_BAD_FLAGS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPMOFC_BAD_FLAGS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPMOFC_BAD_FLAGS_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFPMOFC_BAD_FLAGS_SET(flags, OF_VERSION_1_4);
    TEST_ASSERT(flags == OFPMOFC_BAD_FLAGS_BY_VERSION(OF_VERSION_1_4));
    TEST_ASSERT(OFPMOFC_BAD_FLAGS_TEST(flags, OF_VERSION_1_4));
    OFPMOFC_BAD_FLAGS_CLEAR(flags, OF_VERSION_1_4);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFPMOFC_BAD_FLAGS_TEST(flags, OF_VERSION_1_4));
    value = OFPMOFC_BAD_TABLE_ID;
    TEST_ASSERT(!OFPMOFC_BAD_TABLE_ID_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPMOFC_BAD_TABLE_ID_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPMOFC_BAD_TABLE_ID_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPMOFC_BAD_TABLE_ID_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPMOFC_BAD_TABLE_ID_SUPPORTED(OF_VERSION_1_4));
    value = OFPMOFC_BAD_OUT;
    TEST_ASSERT(!OFPMOFC_BAD_OUT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPMOFC_BAD_OUT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPMOFC_BAD_OUT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPMOFC_BAD_OUT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPMOFC_BAD_OUT_SUPPORTED(OF_VERSION_1_4));
    value = OFPBFC_UNKNOWN;
    TEST_ASSERT(!OFPBFC_UNKNOWN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPBFC_UNKNOWN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPBFC_UNKNOWN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPBFC_UNKNOWN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPBFC_UNKNOWN_SUPPORTED(OF_VERSION_1_4));
    value = OFPBFC_EPERM;
    TEST_ASSERT(!OFPBFC_EPERM_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPBFC_EPERM_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPBFC_EPERM_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPBFC_EPERM_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPBFC_EPERM_SUPPORTED(OF_VERSION_1_4));
    value = OFPBFC_BAD_ID;
    TEST_ASSERT(!OFPBFC_BAD_ID_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPBFC_BAD_ID_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPBFC_BAD_ID_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPBFC_BAD_ID_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPBFC_BAD_ID_SUPPORTED(OF_VERSION_1_4));
    value = OFPBFC_BUNDLE_EXIST;
    TEST_ASSERT(!OFPBFC_BUNDLE_EXIST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPBFC_BUNDLE_EXIST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPBFC_BUNDLE_EXIST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPBFC_BUNDLE_EXIST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPBFC_BUNDLE_EXIST_SUPPORTED(OF_VERSION_1_4));
    value = OFPBFC_BUNDLE_CLOSED;
    TEST_ASSERT(!OFPBFC_BUNDLE_CLOSED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPBFC_BUNDLE_CLOSED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPBFC_BUNDLE_CLOSED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPBFC_BUNDLE_CLOSED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPBFC_BUNDLE_CLOSED_SUPPORTED(OF_VERSION_1_4));
    value = OFPBFC_OUT_OF_BUNDLES;
    TEST_ASSERT(!OFPBFC_OUT_OF_BUNDLES_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPBFC_OUT_OF_BUNDLES_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPBFC_OUT_OF_BUNDLES_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPBFC_OUT_OF_BUNDLES_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPBFC_OUT_OF_BUNDLES_SUPPORTED(OF_VERSION_1_4));
    value = OFPBFC_BAD_TYPE;
    TEST_ASSERT(!OFPBFC_BAD_TYPE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPBFC_BAD_TYPE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPBFC_BAD_TYPE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPBFC_BAD_TYPE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPBFC_BAD_TYPE_SUPPORTED(OF_VERSION_1_4));
    value = OFPBFC_BAD_FLAGS;
    TEST_ASSERT(!OFPBFC_BAD_FLAGS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPBFC_BAD_FLAGS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPBFC_BAD_FLAGS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPBFC_BAD_FLAGS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPBFC_BAD_FLAGS_SUPPORTED(OF_VERSION_1_4));

    flags = 0;
    OFPBFC_BAD_FLAGS_SET(flags, OF_VERSION_1_4);
    TEST_ASSERT(flags == OFPBFC_BAD_FLAGS_BY_VERSION(OF_VERSION_1_4));
    TEST_ASSERT(OFPBFC_BAD_FLAGS_TEST(flags, OF_VERSION_1_4));
    OFPBFC_BAD_FLAGS_CLEAR(flags, OF_VERSION_1_4);
    TEST_ASSERT(flags == 0);
    TEST_ASSERT(!OFPBFC_BAD_FLAGS_TEST(flags, OF_VERSION_1_4));
    value = OFPBFC_MSG_BAD_LEN;
    TEST_ASSERT(!OFPBFC_MSG_BAD_LEN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPBFC_MSG_BAD_LEN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPBFC_MSG_BAD_LEN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPBFC_MSG_BAD_LEN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPBFC_MSG_BAD_LEN_SUPPORTED(OF_VERSION_1_4));
    value = OFPBFC_MSG_BAD_XID;
    TEST_ASSERT(!OFPBFC_MSG_BAD_XID_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPBFC_MSG_BAD_XID_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPBFC_MSG_BAD_XID_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPBFC_MSG_BAD_XID_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPBFC_MSG_BAD_XID_SUPPORTED(OF_VERSION_1_4));
    value = OFPBFC_MSG_UNSUP;
    TEST_ASSERT(!OFPBFC_MSG_UNSUP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPBFC_MSG_UNSUP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPBFC_MSG_UNSUP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPBFC_MSG_UNSUP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPBFC_MSG_UNSUP_SUPPORTED(OF_VERSION_1_4));
    value = OFPBFC_MSG_CONFLICT;
    TEST_ASSERT(!OFPBFC_MSG_CONFLICT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPBFC_MSG_CONFLICT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPBFC_MSG_CONFLICT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPBFC_MSG_CONFLICT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPBFC_MSG_CONFLICT_SUPPORTED(OF_VERSION_1_4));
    value = OFPBFC_MSG_TOO_MANY;
    TEST_ASSERT(!OFPBFC_MSG_TOO_MANY_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPBFC_MSG_TOO_MANY_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPBFC_MSG_TOO_MANY_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPBFC_MSG_TOO_MANY_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPBFC_MSG_TOO_MANY_SUPPORTED(OF_VERSION_1_4));
    value = OFPBFC_MSG_FAILED;
    TEST_ASSERT(!OFPBFC_MSG_FAILED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPBFC_MSG_FAILED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPBFC_MSG_FAILED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPBFC_MSG_FAILED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPBFC_MSG_FAILED_SUPPORTED(OF_VERSION_1_4));
    value = OFPBFC_TIMEOUT;
    TEST_ASSERT(!OFPBFC_TIMEOUT_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPBFC_TIMEOUT_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPBFC_TIMEOUT_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPBFC_TIMEOUT_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPBFC_TIMEOUT_SUPPORTED(OF_VERSION_1_4));
    value = OFPBFC_BUNDLE_IN_PROGRESS;
    TEST_ASSERT(!OFPBFC_BUNDLE_IN_PROGRESS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPBFC_BUNDLE_IN_PROGRESS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPBFC_BUNDLE_IN_PROGRESS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPBFC_BUNDLE_IN_PROGRESS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPBFC_BUNDLE_IN_PROGRESS_SUPPORTED(OF_VERSION_1_4));
    value = OFPPSPT_ETHERNET;
    TEST_ASSERT(!OFPPSPT_ETHERNET_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPPSPT_ETHERNET_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPPSPT_ETHERNET_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPPSPT_ETHERNET_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPPSPT_ETHERNET_SUPPORTED(OF_VERSION_1_4));
    value = OFPPSPT_OPTICAL;
    TEST_ASSERT(!OFPPSPT_OPTICAL_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPPSPT_OPTICAL_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPPSPT_OPTICAL_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPPSPT_OPTICAL_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPPSPT_OPTICAL_SUPPORTED(OF_VERSION_1_4));
    value = OFPPSPT_EXPERIMENTER;
    TEST_ASSERT(!OFPPSPT_EXPERIMENTER_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPPSPT_EXPERIMENTER_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPPSPT_EXPERIMENTER_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPPSPT_EXPERIMENTER_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPPSPT_EXPERIMENTER_SUPPORTED(OF_VERSION_1_4));
    value = OF_MULTIPART_TABLE_DESC;
    TEST_ASSERT(!OF_MULTIPART_TABLE_DESC_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_MULTIPART_TABLE_DESC_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_MULTIPART_TABLE_DESC_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_MULTIPART_TABLE_DESC_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_MULTIPART_TABLE_DESC_SUPPORTED(OF_VERSION_1_4));
    value = OF_MULTIPART_QUEUE_DESC;
    TEST_ASSERT(!OF_MULTIPART_QUEUE_DESC_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_MULTIPART_QUEUE_DESC_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_MULTIPART_QUEUE_DESC_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_MULTIPART_QUEUE_DESC_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_MULTIPART_QUEUE_DESC_SUPPORTED(OF_VERSION_1_4));
    value = OF_MULTIPART_FLOW_MONITOR;
    TEST_ASSERT(!OF_MULTIPART_FLOW_MONITOR_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_MULTIPART_FLOW_MONITOR_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_MULTIPART_FLOW_MONITOR_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_MULTIPART_FLOW_MONITOR_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_MULTIPART_FLOW_MONITOR_SUPPORTED(OF_VERSION_1_4));
    value = OF_TABLE_FEATURE_TABLE_SYNC_FROM;
    TEST_ASSERT(!OF_TABLE_FEATURE_TABLE_SYNC_FROM_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OF_TABLE_FEATURE_TABLE_SYNC_FROM_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OF_TABLE_FEATURE_TABLE_SYNC_FROM_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OF_TABLE_FEATURE_TABLE_SYNC_FROM_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OF_TABLE_FEATURE_TABLE_SYNC_FROM_SUPPORTED(OF_VERSION_1_4));
    value = OFPOPF_RX_TUNE;
    TEST_ASSERT(!OFPOPF_RX_TUNE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPOPF_RX_TUNE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPOPF_RX_TUNE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPOPF_RX_TUNE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPOPF_RX_TUNE_SUPPORTED(OF_VERSION_1_4));
    value = OFPOPF_TX_TUNE;
    TEST_ASSERT(!OFPOPF_TX_TUNE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPOPF_TX_TUNE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPOPF_TX_TUNE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPOPF_TX_TUNE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPOPF_TX_TUNE_SUPPORTED(OF_VERSION_1_4));
    value = OFPOPF_TX_PWR;
    TEST_ASSERT(!OFPOPF_TX_PWR_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPOPF_TX_PWR_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPOPF_TX_PWR_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPOPF_TX_PWR_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPOPF_TX_PWR_SUPPORTED(OF_VERSION_1_4));
    value = OFPOPF_USE_FREQ;
    TEST_ASSERT(!OFPOPF_USE_FREQ_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPOPF_USE_FREQ_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPOPF_USE_FREQ_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPOPF_USE_FREQ_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPOPF_USE_FREQ_SUPPORTED(OF_VERSION_1_4));
    value = OFPTMPEF_OTHER;
    TEST_ASSERT(!OFPTMPEF_OTHER_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPTMPEF_OTHER_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPTMPEF_OTHER_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPTMPEF_OTHER_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPTMPEF_OTHER_SUPPORTED(OF_VERSION_1_4));
    value = OFPTMPEF_IMPORTANCE;
    TEST_ASSERT(!OFPTMPEF_IMPORTANCE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPTMPEF_IMPORTANCE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPTMPEF_IMPORTANCE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPTMPEF_IMPORTANCE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPTMPEF_IMPORTANCE_SUPPORTED(OF_VERSION_1_4));
    value = OFPTMPEF_LIFETIME;
    TEST_ASSERT(!OFPTMPEF_LIFETIME_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPTMPEF_LIFETIME_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPTMPEF_LIFETIME_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPTMPEF_LIFETIME_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPTMPEF_LIFETIME_SUPPORTED(OF_VERSION_1_4));
    value = OFPOSF_RX_TUNE;
    TEST_ASSERT(!OFPOSF_RX_TUNE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPOSF_RX_TUNE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPOSF_RX_TUNE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPOSF_RX_TUNE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPOSF_RX_TUNE_SUPPORTED(OF_VERSION_1_4));
    value = OFPOSF_TX_TUNE;
    TEST_ASSERT(!OFPOSF_TX_TUNE_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPOSF_TX_TUNE_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPOSF_TX_TUNE_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPOSF_TX_TUNE_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPOSF_TX_TUNE_SUPPORTED(OF_VERSION_1_4));
    value = OFPOSF_TX_PWR;
    TEST_ASSERT(!OFPOSF_TX_PWR_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPOSF_TX_PWR_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPOSF_TX_PWR_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPOSF_TX_PWR_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPOSF_TX_PWR_SUPPORTED(OF_VERSION_1_4));
    value = OFPOSF_RX_PWR;
    TEST_ASSERT(!OFPOSF_RX_PWR_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPOSF_RX_PWR_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPOSF_RX_PWR_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPOSF_RX_PWR_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPOSF_RX_PWR_SUPPORTED(OF_VERSION_1_4));
    value = OFPOSF_TX_BIAS;
    TEST_ASSERT(!OFPOSF_TX_BIAS_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPOSF_TX_BIAS_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPOSF_TX_BIAS_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPOSF_TX_BIAS_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPOSF_TX_BIAS_SUPPORTED(OF_VERSION_1_4));
    value = OFPOSF_TX_TEMP;
    TEST_ASSERT(!OFPOSF_TX_TEMP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPOSF_TX_TEMP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPOSF_TX_TEMP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPOSF_TX_TEMP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPOSF_TX_TEMP_SUPPORTED(OF_VERSION_1_4));
    value = OFPBCT_OPEN_REQUEST;
    TEST_ASSERT(!OFPBCT_OPEN_REQUEST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPBCT_OPEN_REQUEST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPBCT_OPEN_REQUEST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPBCT_OPEN_REQUEST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPBCT_OPEN_REQUEST_SUPPORTED(OF_VERSION_1_4));
    value = OFPBCT_OPEN_REPLY;
    TEST_ASSERT(!OFPBCT_OPEN_REPLY_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPBCT_OPEN_REPLY_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPBCT_OPEN_REPLY_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPBCT_OPEN_REPLY_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPBCT_OPEN_REPLY_SUPPORTED(OF_VERSION_1_4));
    value = OFPBCT_CLOSE_REQUEST;
    TEST_ASSERT(!OFPBCT_CLOSE_REQUEST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPBCT_CLOSE_REQUEST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPBCT_CLOSE_REQUEST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPBCT_CLOSE_REQUEST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPBCT_CLOSE_REQUEST_SUPPORTED(OF_VERSION_1_4));
    value = OFPBCT_CLOSE_REPLY;
    TEST_ASSERT(!OFPBCT_CLOSE_REPLY_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPBCT_CLOSE_REPLY_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPBCT_CLOSE_REPLY_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPBCT_CLOSE_REPLY_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPBCT_CLOSE_REPLY_SUPPORTED(OF_VERSION_1_4));
    value = OFPBCT_COMMIT_REQUEST;
    TEST_ASSERT(!OFPBCT_COMMIT_REQUEST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPBCT_COMMIT_REQUEST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPBCT_COMMIT_REQUEST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPBCT_COMMIT_REQUEST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPBCT_COMMIT_REQUEST_SUPPORTED(OF_VERSION_1_4));
    value = OFPBCT_COMMIT_REPLY;
    TEST_ASSERT(!OFPBCT_COMMIT_REPLY_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPBCT_COMMIT_REPLY_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPBCT_COMMIT_REPLY_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPBCT_COMMIT_REPLY_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPBCT_COMMIT_REPLY_SUPPORTED(OF_VERSION_1_4));
    value = OFPBCT_DISCARD_REQUEST;
    TEST_ASSERT(!OFPBCT_DISCARD_REQUEST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPBCT_DISCARD_REQUEST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPBCT_DISCARD_REQUEST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPBCT_DISCARD_REQUEST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPBCT_DISCARD_REQUEST_SUPPORTED(OF_VERSION_1_4));
    value = OFPBCT_DISCARD_REPLY;
    TEST_ASSERT(!OFPBCT_DISCARD_REPLY_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPBCT_DISCARD_REPLY_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPBCT_DISCARD_REPLY_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPBCT_DISCARD_REPLY_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPBCT_DISCARD_REPLY_SUPPORTED(OF_VERSION_1_4));
    value = OFPBF_ATOMIC;
    TEST_ASSERT(!OFPBF_ATOMIC_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPBF_ATOMIC_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPBF_ATOMIC_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPBF_ATOMIC_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPBF_ATOMIC_SUPPORTED(OF_VERSION_1_4));
    value = OFPBF_ORDERED;
    TEST_ASSERT(!OFPBF_ORDERED_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPBF_ORDERED_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPBF_ORDERED_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPBF_ORDERED_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPBF_ORDERED_SUPPORTED(OF_VERSION_1_4));
    value = OFPCRR_MASTER_REQUEST;
    TEST_ASSERT(!OFPCRR_MASTER_REQUEST_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPCRR_MASTER_REQUEST_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPCRR_MASTER_REQUEST_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPCRR_MASTER_REQUEST_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPCRR_MASTER_REQUEST_SUPPORTED(OF_VERSION_1_4));
    value = OFPCRR_CONFIG;
    TEST_ASSERT(!OFPCRR_CONFIG_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPCRR_CONFIG_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPCRR_CONFIG_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPCRR_CONFIG_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPCRR_CONFIG_SUPPORTED(OF_VERSION_1_4));
    value = OFPCRR_EXPERIMENTER;
    TEST_ASSERT(!OFPCRR_EXPERIMENTER_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPCRR_EXPERIMENTER_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPCRR_EXPERIMENTER_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPCRR_EXPERIMENTER_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPCRR_EXPERIMENTER_SUPPORTED(OF_VERSION_1_4));
    value = OFPTR_VACANCY_DOWN;
    TEST_ASSERT(!OFPTR_VACANCY_DOWN_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPTR_VACANCY_DOWN_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPTR_VACANCY_DOWN_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPTR_VACANCY_DOWN_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPTR_VACANCY_DOWN_SUPPORTED(OF_VERSION_1_4));
    value = OFPTR_VACANCY_UP;
    TEST_ASSERT(!OFPTR_VACANCY_UP_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPTR_VACANCY_UP_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPTR_VACANCY_UP_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPTR_VACANCY_UP_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPTR_VACANCY_UP_SUPPORTED(OF_VERSION_1_4));
    value = OFPRFR_GROUP_MOD;
    TEST_ASSERT(!OFPRFR_GROUP_MOD_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPRFR_GROUP_MOD_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPRFR_GROUP_MOD_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPRFR_GROUP_MOD_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPRFR_GROUP_MOD_SUPPORTED(OF_VERSION_1_4));
    value = OFPRFR_METER_MOD;
    TEST_ASSERT(!OFPRFR_METER_MOD_SUPPORTED(OF_VERSION_1_0));
    TEST_ASSERT(!OFPRFR_METER_MOD_SUPPORTED(OF_VERSION_1_1));
    TEST_ASSERT(!OFPRFR_METER_MOD_SUPPORTED(OF_VERSION_1_2));
    TEST_ASSERT(!OFPRFR_METER_MOD_SUPPORTED(OF_VERSION_1_3));
    TEST_ASSERT(OFPRFR_METER_MOD_SUPPORTED(OF_VERSION_1_4));

    return TEST_PASS;
}


/**
 * Test object dump functions
 */

int
test_dump_objs(void)
{
    of_object_t *obj;

    FILE *out = fopen("/dev/null", "w");

    /* Call each obj dump function */

    obj = (of_object_t *)of_aggregate_stats_reply_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_aggregate_stats_request_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bad_action_error_msg_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bad_request_error_msg_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_barrier_reply_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_barrier_request_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_bw_clear_data_reply_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_bw_clear_data_request_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_bw_enable_get_reply_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_bw_enable_get_request_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_bw_enable_set_reply_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_bw_enable_set_request_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_get_interfaces_reply_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_get_interfaces_request_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_get_ip_mask_reply_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_get_ip_mask_request_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_get_l2_table_reply_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_get_l2_table_request_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_get_mirroring_reply_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_get_mirroring_request_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_hybrid_get_reply_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_hybrid_get_request_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_pdu_rx_reply_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_pdu_rx_request_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_pdu_rx_timeout_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_pdu_tx_reply_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_pdu_tx_request_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_set_ip_mask_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_set_l2_table_reply_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_set_l2_table_request_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_set_mirroring_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_set_pktin_suppression_reply_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_set_pktin_suppression_request_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_shell_command_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_shell_output_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_shell_status_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_virtual_port_create_reply_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_virtual_port_create_request_new(OF_VERSION_1_0);
    {
        of_object_t *vport = of_bsn_vport_q_in_q_new(OF_VERSION_1_0);
        of_bsn_virtual_port_create_request_vport_set(obj, vport);
        of_object_delete(vport);
    }
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_virtual_port_remove_reply_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_virtual_port_remove_request_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_desc_stats_reply_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_desc_stats_request_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_echo_reply_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_echo_request_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_features_reply_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_features_request_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_add_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_delete_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_delete_strict_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_mod_failed_error_msg_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_modify_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_modify_strict_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_removed_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_stats_reply_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_stats_request_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_get_config_reply_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_get_config_request_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_hello_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_hello_failed_error_msg_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_nicira_controller_role_reply_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_nicira_controller_role_request_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_packet_in_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_packet_out_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_mod_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_mod_failed_error_msg_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_stats_reply_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_stats_request_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_status_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_queue_get_config_reply_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_queue_get_config_request_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_queue_op_failed_error_msg_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_queue_stats_reply_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_queue_stats_request_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_set_config_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_mod_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_stats_reply_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_stats_request_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_bsn_checksum_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_bsn_mirror_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_bsn_set_tunnel_dst_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_enqueue_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_nicira_dec_ttl_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_output_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_set_dl_dst_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_set_dl_src_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_set_nw_dst_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_set_nw_src_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_set_nw_tos_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_set_tp_dst_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_set_tp_src_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_set_vlan_pcp_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_set_vlan_vid_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_strip_vlan_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_interface_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_vport_l2gre_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_vport_q_in_q_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_stats_entry_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_match_v1_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_packet_queue_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_desc_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_stats_entry_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_queue_prop_min_rate_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_queue_stats_entry_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_stats_entry_new(OF_VERSION_1_0);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_aggregate_stats_reply_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_aggregate_stats_request_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bad_action_error_msg_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bad_instruction_error_msg_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bad_match_error_msg_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bad_request_error_msg_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_barrier_reply_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_barrier_request_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_bw_clear_data_reply_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_bw_clear_data_request_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_bw_enable_get_reply_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_bw_enable_get_request_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_bw_enable_set_reply_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_bw_enable_set_request_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_get_interfaces_reply_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_get_interfaces_request_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_get_mirroring_reply_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_get_mirroring_request_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_pdu_rx_reply_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_pdu_rx_request_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_pdu_rx_timeout_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_pdu_tx_reply_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_pdu_tx_request_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_set_mirroring_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_set_pktin_suppression_reply_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_set_pktin_suppression_request_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_virtual_port_create_reply_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_virtual_port_create_request_new(OF_VERSION_1_1);
    {
        of_object_t *vport = of_bsn_vport_q_in_q_new(OF_VERSION_1_1);
        of_bsn_virtual_port_create_request_vport_set(obj, vport);
        of_object_delete(vport);
    }
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_virtual_port_remove_reply_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_virtual_port_remove_request_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_desc_stats_reply_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_desc_stats_request_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_echo_reply_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_echo_request_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_features_reply_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_features_request_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_add_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_delete_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_delete_strict_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_mod_failed_error_msg_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_modify_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_modify_strict_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_removed_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_stats_reply_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_stats_request_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_get_config_reply_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_get_config_request_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_add_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_delete_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_desc_stats_reply_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_desc_stats_request_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_mod_failed_error_msg_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_modify_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_stats_reply_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_stats_request_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_hello_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_hello_failed_error_msg_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_packet_in_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_packet_out_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_mod_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_mod_failed_error_msg_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_stats_reply_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_stats_request_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_status_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_queue_get_config_reply_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_queue_get_config_request_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_queue_op_failed_error_msg_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_queue_stats_reply_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_queue_stats_request_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_set_config_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_switch_config_failed_error_msg_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_mod_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_mod_failed_error_msg_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_stats_reply_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_stats_request_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_bsn_checksum_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_bsn_mirror_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_bsn_set_tunnel_dst_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_copy_ttl_in_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_copy_ttl_out_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_dec_mpls_ttl_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_dec_nw_ttl_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_group_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_nicira_dec_ttl_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_output_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_pop_mpls_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_pop_vlan_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_push_mpls_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_push_vlan_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_set_dl_dst_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_set_dl_src_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_set_mpls_label_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_set_mpls_tc_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_set_mpls_ttl_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_set_nw_dst_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_set_nw_ecn_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_set_nw_src_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_set_nw_tos_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_set_nw_ttl_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_set_queue_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_set_tp_dst_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_set_tp_src_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_set_vlan_pcp_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_set_vlan_vid_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_interface_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_vport_l2gre_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_vport_q_in_q_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bucket_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bucket_counter_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_stats_entry_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_desc_stats_entry_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_stats_entry_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_apply_actions_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_clear_actions_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_goto_table_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_write_actions_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_write_metadata_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_match_v2_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_packet_queue_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_desc_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_stats_entry_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_queue_prop_min_rate_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_queue_stats_entry_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_stats_entry_new(OF_VERSION_1_1);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_aggregate_stats_reply_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_aggregate_stats_request_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bad_action_error_msg_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bad_instruction_error_msg_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bad_match_error_msg_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bad_request_error_msg_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_barrier_reply_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_barrier_request_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_bw_clear_data_reply_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_bw_clear_data_request_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_bw_enable_get_reply_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_bw_enable_get_request_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_bw_enable_set_reply_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_bw_enable_set_request_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_get_interfaces_reply_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_get_interfaces_request_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_get_mirroring_reply_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_get_mirroring_request_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_pdu_rx_reply_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_pdu_rx_request_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_pdu_rx_timeout_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_pdu_tx_reply_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_pdu_tx_request_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_set_mirroring_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_set_pktin_suppression_reply_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_set_pktin_suppression_request_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_virtual_port_create_reply_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_virtual_port_create_request_new(OF_VERSION_1_2);
    {
        of_object_t *vport = of_bsn_vport_q_in_q_new(OF_VERSION_1_2);
        of_bsn_virtual_port_create_request_vport_set(obj, vport);
        of_object_delete(vport);
    }
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_virtual_port_remove_reply_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_virtual_port_remove_request_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_desc_stats_reply_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_desc_stats_request_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_echo_reply_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_echo_request_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_features_reply_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_features_request_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_add_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_delete_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_delete_strict_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_mod_failed_error_msg_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_modify_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_modify_strict_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_removed_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_stats_reply_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_stats_request_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_get_config_reply_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_get_config_request_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_add_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_delete_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_desc_stats_reply_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_desc_stats_request_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_features_stats_reply_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_features_stats_request_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_mod_failed_error_msg_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_modify_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_stats_reply_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_stats_request_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_hello_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_hello_failed_error_msg_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_packet_in_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_packet_out_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_mod_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_mod_failed_error_msg_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_stats_reply_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_stats_request_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_status_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_queue_get_config_reply_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_queue_get_config_request_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_queue_op_failed_error_msg_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_queue_stats_reply_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_queue_stats_request_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_role_reply_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_role_request_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_role_request_failed_error_msg_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_set_config_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_switch_config_failed_error_msg_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_mod_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_mod_failed_error_msg_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_stats_reply_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_stats_request_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_bsn_checksum_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_bsn_mirror_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_bsn_set_tunnel_dst_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_copy_ttl_in_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_copy_ttl_out_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_dec_mpls_ttl_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_dec_nw_ttl_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_group_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_nicira_dec_ttl_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_output_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_pop_mpls_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_pop_vlan_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_push_mpls_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_push_vlan_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_set_field_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_set_mpls_ttl_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_set_nw_ttl_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_set_queue_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_interface_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_vport_l2gre_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_vport_q_in_q_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bucket_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bucket_counter_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_stats_entry_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_desc_stats_entry_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_stats_entry_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_apply_actions_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_clear_actions_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_goto_table_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_write_actions_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_write_metadata_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_match_v3_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_arp_op_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_arp_op_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_arp_sha_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_arp_sha_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_arp_spa_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_arp_spa_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_arp_tha_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_arp_tha_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_arp_tpa_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_arp_tpa_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_egr_port_group_id_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_egr_port_group_id_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_global_vrf_allowed_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_global_vrf_allowed_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_in_ports_128_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_in_ports_128_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_in_ports_512_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_in_ports_512_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_ingress_port_group_id_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_ingress_port_group_id_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_ip_fragmentation_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_ip_fragmentation_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_l2_cache_hit_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_l2_cache_hit_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_l3_dst_class_id_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_l3_dst_class_id_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_l3_interface_class_id_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_l3_interface_class_id_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_l3_src_class_id_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_l3_src_class_id_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_lag_id_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_lag_id_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_tcp_flags_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_tcp_flags_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf0_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf0_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf1_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf1_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf2_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf2_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf3_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf3_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf4_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf4_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf5_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf5_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf6_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf6_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf7_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf7_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_vlan_xlate_port_group_id_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_vlan_xlate_port_group_id_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_vrf_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_vrf_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_ipv6_dst_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_ipv6_dst_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_ipv6_src_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_ipv6_src_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_label_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_label_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_mark_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_mark_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_nw_dst_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_nw_dst_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_nw_proto_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_nw_proto_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_nw_src_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_nw_src_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_state_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_state_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_tp_dst_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_tp_dst_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_tp_src_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_tp_src_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_zone_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_zone_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_eth_dst_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_eth_dst_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_eth_src_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_eth_src_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_eth_type_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_eth_type_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_icmpv4_code_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_icmpv4_code_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_icmpv4_type_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_icmpv4_type_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_icmpv6_code_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_icmpv6_code_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_icmpv6_type_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_icmpv6_type_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_in_phy_port_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_in_phy_port_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_in_port_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_in_port_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ip_dscp_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ip_dscp_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ip_ecn_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ip_ecn_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ip_proto_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ip_proto_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv4_dst_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv4_dst_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv4_src_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv4_src_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv6_dst_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv6_dst_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv6_flabel_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv6_flabel_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv6_nd_sll_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv6_nd_sll_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv6_nd_target_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv6_nd_target_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv6_nd_tll_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv6_nd_tll_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv6_src_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv6_src_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_metadata_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_metadata_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_mpls_label_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_mpls_label_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_mpls_tc_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_mpls_tc_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ovs_tcp_flags_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ovs_tcp_flags_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_sctp_dst_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_sctp_dst_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_sctp_src_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_sctp_src_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_tcp_dst_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_tcp_dst_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_tcp_src_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_tcp_src_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_tunnel_ipv4_dst_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_tunnel_ipv4_dst_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_tunnel_ipv4_src_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_tunnel_ipv4_src_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_udp_dst_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_udp_dst_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_udp_src_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_udp_src_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_vlan_pcp_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_vlan_pcp_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_vlan_vid_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_vlan_vid_masked_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_packet_queue_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_desc_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_stats_entry_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_queue_prop_max_rate_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_queue_prop_min_rate_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_queue_stats_entry_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_stats_entry_new(OF_VERSION_1_2);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_aggregate_stats_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_aggregate_stats_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_async_get_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_async_get_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_async_set_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bad_action_error_msg_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bad_instruction_error_msg_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bad_match_error_msg_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bad_request_error_msg_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_barrier_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_barrier_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_arp_idle_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_bw_clear_data_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_bw_clear_data_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_bw_enable_get_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_bw_enable_get_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_bw_enable_set_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_bw_enable_set_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_controller_connections_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_controller_connections_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_debug_counter_desc_stats_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_debug_counter_desc_stats_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_debug_counter_stats_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_debug_counter_stats_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_error_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_flow_checksum_bucket_stats_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_flow_checksum_bucket_stats_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_flow_idle_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_flow_idle_enable_get_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_flow_idle_enable_get_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_flow_idle_enable_set_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_flow_idle_enable_set_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_generic_stats_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_generic_stats_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_gentable_bucket_stats_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_gentable_bucket_stats_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_gentable_clear_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_gentable_clear_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_gentable_desc_stats_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_gentable_desc_stats_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_gentable_entry_add_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_gentable_entry_delete_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_gentable_entry_desc_stats_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_gentable_entry_desc_stats_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_gentable_entry_stats_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_gentable_entry_stats_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_gentable_error_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_gentable_set_buckets_size_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_gentable_stats_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_gentable_stats_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_get_interfaces_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_get_interfaces_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_get_mirroring_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_get_mirroring_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_get_switch_pipeline_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_get_switch_pipeline_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_image_desc_stats_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_image_desc_stats_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_lacp_convergence_notif_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_lacp_stats_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_lacp_stats_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_log_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_lua_command_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_lua_command_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_lua_notification_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_lua_upload_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_pdu_rx_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_pdu_rx_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_pdu_rx_timeout_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_pdu_tx_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_pdu_tx_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_port_counter_stats_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_port_counter_stats_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_role_status_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_set_aux_cxns_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_set_aux_cxns_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_set_lacp_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_set_lacp_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_set_mirroring_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_set_pktin_suppression_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_set_pktin_suppression_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_set_switch_pipeline_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_set_switch_pipeline_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_switch_pipeline_stats_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_switch_pipeline_stats_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_table_checksum_stats_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_table_checksum_stats_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_table_set_buckets_size_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_time_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_time_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_virtual_port_create_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_virtual_port_create_request_new(OF_VERSION_1_3);
    {
        of_object_t *vport = of_bsn_vport_q_in_q_new(OF_VERSION_1_3);
        of_bsn_virtual_port_create_request_vport_set(obj, vport);
        of_object_delete(vport);
    }
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_virtual_port_remove_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_virtual_port_remove_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_vlan_counter_clear_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_vlan_counter_stats_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_vlan_counter_stats_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_vrf_counter_stats_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_vrf_counter_stats_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_desc_stats_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_desc_stats_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_echo_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_echo_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_features_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_features_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_add_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_delete_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_delete_strict_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_mod_failed_error_msg_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_modify_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_modify_strict_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_removed_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_stats_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_stats_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_get_config_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_get_config_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_add_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_delete_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_desc_stats_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_desc_stats_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_features_stats_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_features_stats_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_mod_failed_error_msg_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_modify_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_stats_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_stats_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_hello_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_hello_failed_error_msg_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_meter_config_stats_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_meter_config_stats_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_meter_features_stats_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_meter_features_stats_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_meter_mod_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_meter_mod_failed_error_msg_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_meter_stats_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_meter_stats_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_packet_in_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_packet_out_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_desc_stats_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_desc_stats_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_mod_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_mod_failed_error_msg_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_stats_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_stats_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_status_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_queue_get_config_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_queue_get_config_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_queue_op_failed_error_msg_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_queue_stats_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_queue_stats_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_role_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_role_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_role_request_failed_error_msg_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_set_config_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_switch_config_failed_error_msg_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_features_failed_error_msg_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_features_stats_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_features_stats_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_mod_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_mod_failed_error_msg_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_stats_reply_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_stats_request_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_bsn_checksum_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_bsn_gentable_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_bsn_mirror_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_bsn_set_tunnel_dst_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_copy_ttl_in_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_copy_ttl_out_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_dec_mpls_ttl_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_dec_nw_ttl_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_group_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_id_bsn_checksum_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_id_bsn_gentable_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_id_bsn_mirror_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_id_bsn_set_tunnel_dst_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_id_copy_ttl_in_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_id_copy_ttl_out_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_id_dec_mpls_ttl_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_id_dec_nw_ttl_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_id_group_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_id_nicira_dec_ttl_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_id_output_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_id_pop_mpls_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_id_pop_pbb_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_id_pop_vlan_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_id_push_mpls_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_id_push_pbb_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_id_push_vlan_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_id_set_field_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_id_set_mpls_ttl_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_id_set_nw_ttl_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_id_set_queue_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_nicira_dec_ttl_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_output_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_pop_mpls_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_pop_pbb_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_pop_vlan_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_push_mpls_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_push_pbb_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_push_vlan_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_set_field_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_set_mpls_ttl_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_set_nw_ttl_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_set_queue_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_controller_connection_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_debug_counter_desc_stats_entry_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_debug_counter_stats_entry_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_flow_checksum_bucket_stats_entry_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_generic_stats_entry_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_gentable_bucket_stats_entry_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_gentable_desc_stats_entry_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_gentable_entry_desc_stats_entry_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_gentable_entry_stats_entry_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_gentable_stats_entry_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_interface_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_lacp_stats_entry_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_port_counter_stats_entry_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_switch_pipeline_stats_entry_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_table_checksum_stats_entry_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_active_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_actor_key_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_actor_port_num_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_actor_port_priority_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_actor_state_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_actor_system_mac_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_actor_system_priority_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_admin_state_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_analytics_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_anchor_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_apply_bytes_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_apply_packets_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_arp_spa_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_arp_tpa_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_auto_negotiation_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_bfd_endpoint_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_bfd_state_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_broadcast_query_timeout_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_broadcast_rate_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_bucket_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_circuit_id_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_convergence_status_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_cpu_lag_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_crc_enabled_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_data_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_data_mask_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_decap_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_disable_src_mac_check_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_disable_xmit_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_dns_analytics_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_drop_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_drop_control_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_dscp_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_ecn_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_egress_only_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_egress_port_group_id_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_egress_sampling_rate_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_encap_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_enhanced_hash_capability_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_eth_dst_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_eth_src_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_eth_type_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_external_gateway_ip_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_external_gateway_mac_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_external_ip_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_external_mac_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_external_netmask_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_fabric_port_role_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_fail_count_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_flood_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_flow_classifier_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_flow_classify_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_flow_identifier_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_force_link_up_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_forward_error_correction_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_free_count_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_generation_id_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_hash_algorithm_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_hash_gtp_header_match_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_hash_gtp_port_match_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_hash_packet_field_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_hash_packet_type_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_hash_seed_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_hash_type_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_header_size_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_icmp_code_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_icmp_id_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_icmp_type_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_icmpv6_chksum_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_icmpv6_code_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_icmpv6_type_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_identifier_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_idle_notification_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_idle_time_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_idle_timeout_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_ifp_class_id_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_igmp_snooping_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_ingress_port_group_id_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_inner_vlan_vid_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_internal_gateway_mac_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_internal_mac_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_interval_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_ip_fragmentation_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_ip_proto_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_ip_tunnel_type_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_ipv4_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_ipv4_dst_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_ipv4_netmask_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_ipv4_src_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_ipv6_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_ipv6_dst_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_ipv6_prefix_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_ipv6_src_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_known_multicast_rate_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_l2_cache_hit_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_l2_multicast_lookup_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_l3_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_l3_dst_class_id_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_l3_interface_class_id_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_l3_src_class_id_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_lag_options_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_lcore_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_link_up_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_load_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_lookup_count_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_loopback_mode_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_loopback_port_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_lossless_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_lr_all_enabled_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_mac_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_mac_mask_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_matched_count_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_max_count_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_mcg_type_vxlan_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_mgmt_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_mgmt_reselect_on_failure_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_miss_packets_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_mpls_control_word_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_mpls_label_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_mpls_sequenced_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_multicast_interface_id_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_multicast_packet_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_multiplier_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_name_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_ndp_offload_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_ndp_static_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_negate_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_next_hop_ipv4_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_next_hop_mac_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_nexthop_type_vxlan_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_no_arp_response_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_no_ns_response_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_offset_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_optics_always_enabled_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_outer_src_mac_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_parent_port_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_partner_key_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_partner_port_num_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_partner_port_priority_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_partner_state_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_partner_system_mac_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_partner_system_priority_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_passive_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_pdua_rx_instance_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_pim_dr_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_pim_hello_flood_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_port_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_port_mode_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_port_speed_gbps_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_port_usage_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_port_vxlan_mode_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_preserve_vlan_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_priority_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_push_vlan_on_egress_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_push_vlan_on_ingress_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_qos_priority_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_queue_id_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_queue_weight_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_rate_limit_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_rate_unit_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_record_packets_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_redundant_mgmt_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_reference_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_reply_packets_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_request_packets_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_rest_server_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_routing_param_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_rx_bytes_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_rx_packets_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_sampling_rate_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_sctp_dst_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_sctp_src_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_set_loopback_mode_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_socket_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_src_mac_cml_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_status_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_strip_mpls_l2_on_ingress_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_strip_mpls_l3_on_ingress_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_strip_vlan_on_egress_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_sub_agent_id_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_tcp_dst_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_tcp_flags_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_tcp_src_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_thread_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_timestamp_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_ttl_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_tunnel_capability_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_tx_bytes_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_tx_packets_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_udf_anchor_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_udf_capability_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_udf_data_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_udf_id_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_udf_length_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_udf_offset_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_udp_dst_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_udp_src_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_uint32_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_uint64_list_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_unicast_query_timeout_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_unicast_rate_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_unknown_multicast_rate_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_untagged_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_upgrade_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_uri_scheme_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_use_packet_state_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_user_configured_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_vfi_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_vfp_class_id_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_virtual_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_vlan_mac_list_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_vlan_pcp_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_vlan_vid_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_vlan_vid_mask_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_vni_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_vpn_key_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_vrf_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_vxlan_egress_lag_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_vlan_counter_stats_entry_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_vlan_mac_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_vport_l2gre_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_vport_q_in_q_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_vrf_counter_stats_entry_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bucket_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bucket_counter_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_stats_entry_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_desc_stats_entry_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_stats_entry_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_hello_elem_versionbitmap_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_apply_actions_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_bsn_arp_offload_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_bsn_auto_negotiation_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_bsn_deny_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_bsn_dhcp_offload_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_bsn_directed_broadcast_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_bsn_disable_l3_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_bsn_disable_split_horizon_check_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_bsn_disable_src_mac_check_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_bsn_disable_vlan_counters_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_bsn_hash_select_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_bsn_internal_priority_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_bsn_ndp_offload_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_bsn_packet_of_death_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_bsn_permit_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_bsn_prioritize_pdus_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_bsn_require_vlan_xlate_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_bsn_span_destination_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_clear_actions_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_goto_table_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_apply_actions_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_bsn_arp_offload_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_bsn_auto_negotiation_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_bsn_deny_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_bsn_dhcp_offload_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_bsn_directed_broadcast_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_bsn_disable_l3_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_bsn_disable_split_horizon_check_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_bsn_disable_src_mac_check_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_bsn_disable_vlan_counters_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_bsn_hash_select_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_bsn_internal_priority_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_bsn_ndp_offload_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_bsn_packet_of_death_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_bsn_permit_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_bsn_prioritize_pdus_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_bsn_require_vlan_xlate_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_bsn_span_destination_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_clear_actions_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_goto_table_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_meter_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_write_actions_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_write_metadata_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_meter_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_write_actions_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_write_metadata_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_match_v3_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_meter_band_drop_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_meter_band_dscp_remark_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_meter_band_experimenter_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_meter_band_stats_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_meter_config_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_meter_features_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_meter_stats_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_arp_op_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_arp_op_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_arp_sha_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_arp_sha_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_arp_spa_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_arp_spa_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_arp_tha_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_arp_tha_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_arp_tpa_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_arp_tpa_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_egr_port_group_id_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_egr_port_group_id_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_global_vrf_allowed_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_global_vrf_allowed_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_in_ports_128_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_in_ports_128_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_in_ports_512_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_in_ports_512_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_ingress_port_group_id_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_ingress_port_group_id_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_inner_eth_dst_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_inner_eth_dst_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_inner_eth_src_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_inner_eth_src_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_inner_vlan_vid_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_inner_vlan_vid_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_ip_fragmentation_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_ip_fragmentation_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_l2_cache_hit_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_l2_cache_hit_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_l3_dst_class_id_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_l3_dst_class_id_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_l3_interface_class_id_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_l3_interface_class_id_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_l3_src_class_id_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_l3_src_class_id_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_lag_id_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_lag_id_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_tcp_flags_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_tcp_flags_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf0_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf0_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf1_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf1_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf2_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf2_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf3_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf3_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf4_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf4_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf5_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf5_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf6_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf6_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf7_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf7_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_vfi_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_vfi_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_vlan_xlate_port_group_id_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_vlan_xlate_port_group_id_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_vrf_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_vrf_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_vxlan_network_id_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_vxlan_network_id_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_ipv6_dst_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_ipv6_dst_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_ipv6_src_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_ipv6_src_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_label_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_label_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_mark_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_mark_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_nw_dst_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_nw_dst_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_nw_proto_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_nw_proto_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_nw_src_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_nw_src_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_state_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_state_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_tp_dst_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_tp_dst_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_tp_src_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_tp_src_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_zone_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_zone_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_eth_dst_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_eth_dst_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_eth_src_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_eth_src_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_eth_type_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_eth_type_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_icmpv4_code_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_icmpv4_code_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_icmpv4_type_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_icmpv4_type_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_icmpv6_code_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_icmpv6_code_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_icmpv6_type_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_icmpv6_type_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_in_phy_port_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_in_phy_port_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_in_port_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_in_port_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ip_dscp_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ip_dscp_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ip_ecn_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ip_ecn_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ip_proto_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ip_proto_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv4_dst_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv4_dst_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv4_src_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv4_src_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv6_dst_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv6_dst_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv6_exthdr_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv6_exthdr_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv6_flabel_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv6_flabel_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv6_nd_sll_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv6_nd_sll_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv6_nd_target_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv6_nd_target_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv6_nd_tll_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv6_nd_tll_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv6_src_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv6_src_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_metadata_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_metadata_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_mpls_bos_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_mpls_bos_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_mpls_label_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_mpls_label_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_mpls_tc_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_mpls_tc_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ovs_tcp_flags_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ovs_tcp_flags_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_sctp_dst_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_sctp_dst_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_sctp_src_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_sctp_src_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_tcp_dst_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_tcp_dst_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_tcp_src_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_tcp_src_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_tunnel_id_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_tunnel_id_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_tunnel_ipv4_dst_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_tunnel_ipv4_dst_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_tunnel_ipv4_src_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_tunnel_ipv4_src_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_udp_dst_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_udp_dst_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_udp_src_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_udp_src_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_vlan_pcp_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_vlan_pcp_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_vlan_vid_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_vlan_vid_masked_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_packet_queue_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_desc_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_stats_entry_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_queue_prop_max_rate_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_queue_prop_min_rate_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_queue_stats_entry_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_feature_prop_apply_actions_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_feature_prop_apply_actions_miss_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_feature_prop_apply_setfield_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_feature_prop_apply_setfield_miss_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_feature_prop_instructions_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_feature_prop_instructions_miss_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_feature_prop_match_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_feature_prop_next_tables_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_feature_prop_next_tables_miss_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_feature_prop_wildcards_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_feature_prop_write_actions_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_feature_prop_write_actions_miss_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_feature_prop_write_setfield_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_feature_prop_write_setfield_miss_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_features_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_stats_entry_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_uint32_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_uint64_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_uint8_new(OF_VERSION_1_3);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_aggregate_stats_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_aggregate_stats_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_async_config_failed_error_msg_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_async_get_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_async_get_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_async_set_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bad_action_error_msg_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bad_instruction_error_msg_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bad_match_error_msg_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bad_property_error_msg_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bad_request_error_msg_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_barrier_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_barrier_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_arp_idle_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_bw_clear_data_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_bw_clear_data_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_bw_enable_get_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_bw_enable_get_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_bw_enable_set_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_bw_enable_set_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_controller_connections_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_controller_connections_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_debug_counter_desc_stats_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_debug_counter_desc_stats_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_debug_counter_stats_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_debug_counter_stats_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_error_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_flow_checksum_bucket_stats_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_flow_checksum_bucket_stats_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_flow_idle_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_flow_idle_enable_get_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_flow_idle_enable_get_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_flow_idle_enable_set_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_flow_idle_enable_set_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_generic_async_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_generic_command_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_generic_stats_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_generic_stats_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_gentable_bucket_stats_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_gentable_bucket_stats_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_gentable_clear_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_gentable_clear_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_gentable_desc_stats_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_gentable_desc_stats_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_gentable_entry_add_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_gentable_entry_delete_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_gentable_entry_desc_stats_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_gentable_entry_desc_stats_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_gentable_entry_stats_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_gentable_entry_stats_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_gentable_error_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_gentable_set_buckets_size_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_gentable_stats_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_gentable_stats_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_get_interfaces_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_get_interfaces_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_get_mirroring_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_get_mirroring_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_get_switch_pipeline_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_get_switch_pipeline_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_image_desc_stats_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_image_desc_stats_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_lacp_convergence_notif_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_lacp_stats_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_lacp_stats_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_log_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_lua_command_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_lua_command_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_lua_notification_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_lua_upload_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_pdu_rx_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_pdu_rx_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_pdu_rx_timeout_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_pdu_tx_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_pdu_tx_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_port_counter_stats_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_port_counter_stats_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_set_aux_cxns_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_set_aux_cxns_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_set_lacp_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_set_lacp_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_set_mirroring_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_set_pktin_suppression_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_set_pktin_suppression_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_set_switch_pipeline_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_set_switch_pipeline_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_switch_pipeline_stats_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_switch_pipeline_stats_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_table_checksum_stats_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_table_checksum_stats_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_table_set_buckets_size_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_takeover_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_time_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_time_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_virtual_port_create_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_virtual_port_create_request_new(OF_VERSION_1_4);
    {
        of_object_t *vport = of_bsn_vport_q_in_q_new(OF_VERSION_1_4);
        of_bsn_virtual_port_create_request_vport_set(obj, vport);
        of_object_delete(vport);
    }
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_virtual_port_remove_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_virtual_port_remove_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_vlan_counter_clear_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_vlan_counter_stats_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_vlan_counter_stats_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_vrf_counter_stats_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_vrf_counter_stats_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bundle_add_msg_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bundle_ctrl_msg_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bundle_failed_error_msg_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_desc_stats_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_desc_stats_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_echo_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_echo_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_features_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_features_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_add_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_delete_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_delete_strict_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_mod_failed_error_msg_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_modify_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_modify_strict_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_monitor_failed_error_msg_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_removed_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_stats_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_stats_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_get_config_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_get_config_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_add_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_delete_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_desc_stats_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_desc_stats_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_features_stats_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_features_stats_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_mod_failed_error_msg_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_modify_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_stats_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_stats_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_hello_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_hello_failed_error_msg_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_meter_config_stats_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_meter_config_stats_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_meter_features_stats_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_meter_features_stats_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_meter_mod_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_meter_mod_failed_error_msg_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_meter_stats_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_meter_stats_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_packet_in_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_packet_out_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_desc_stats_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_desc_stats_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_mod_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_mod_failed_error_msg_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_stats_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_stats_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_status_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_queue_desc_stats_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_queue_desc_stats_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_queue_op_failed_error_msg_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_queue_stats_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_queue_stats_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_requestforward_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_role_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_role_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_role_request_failed_error_msg_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_role_status_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_set_config_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_switch_config_failed_error_msg_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_desc_stats_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_desc_stats_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_features_failed_error_msg_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_features_stats_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_features_stats_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_mod_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_mod_failed_error_msg_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_stats_reply_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_stats_request_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_status_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_bsn_checksum_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_bsn_gentable_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_bsn_mirror_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_bsn_set_tunnel_dst_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_copy_ttl_in_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_copy_ttl_out_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_dec_mpls_ttl_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_dec_nw_ttl_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_group_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_id_bsn_checksum_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_id_bsn_gentable_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_id_bsn_mirror_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_id_bsn_set_tunnel_dst_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_id_copy_ttl_in_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_id_copy_ttl_out_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_id_dec_mpls_ttl_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_id_dec_nw_ttl_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_id_group_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_id_nicira_dec_ttl_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_id_output_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_id_pop_mpls_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_id_pop_pbb_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_id_pop_vlan_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_id_push_mpls_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_id_push_pbb_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_id_push_vlan_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_id_set_field_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_id_set_mpls_ttl_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_id_set_nw_ttl_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_id_set_queue_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_nicira_dec_ttl_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_output_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_pop_mpls_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_pop_pbb_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_pop_vlan_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_push_mpls_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_push_pbb_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_push_vlan_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_set_field_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_set_mpls_ttl_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_set_nw_ttl_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_action_set_queue_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_async_config_prop_experimenter_master_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_async_config_prop_experimenter_slave_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_async_config_prop_flow_removed_master_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_async_config_prop_flow_removed_slave_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_async_config_prop_packet_in_master_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_async_config_prop_packet_in_slave_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_async_config_prop_port_status_master_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_async_config_prop_port_status_slave_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_async_config_prop_requestforward_master_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_async_config_prop_requestforward_slave_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_async_config_prop_role_status_master_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_async_config_prop_role_status_slave_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_async_config_prop_table_status_master_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_async_config_prop_table_status_slave_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_controller_connection_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_debug_counter_desc_stats_entry_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_debug_counter_stats_entry_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_flow_checksum_bucket_stats_entry_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_generic_stats_entry_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_gentable_bucket_stats_entry_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_gentable_desc_stats_entry_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_gentable_entry_desc_stats_entry_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_gentable_entry_stats_entry_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_gentable_stats_entry_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_interface_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_lacp_stats_entry_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_port_counter_stats_entry_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_switch_pipeline_stats_entry_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_table_checksum_stats_entry_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_active_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_actor_key_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_actor_port_num_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_actor_port_priority_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_actor_state_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_actor_system_mac_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_actor_system_priority_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_admin_state_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_analytics_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_anchor_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_apply_bytes_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_apply_packets_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_arp_spa_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_arp_tpa_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_auto_negotiation_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_bfd_endpoint_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_bfd_state_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_broadcast_query_timeout_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_broadcast_rate_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_bucket_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_circuit_id_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_convergence_status_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_cpu_lag_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_crc_enabled_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_data_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_data_mask_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_decap_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_disable_src_mac_check_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_disable_xmit_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_dns_analytics_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_drop_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_drop_control_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_dscp_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_ecn_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_egress_only_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_egress_port_group_id_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_egress_sampling_rate_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_encap_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_enhanced_hash_capability_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_eth_dst_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_eth_src_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_eth_type_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_external_gateway_ip_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_external_gateway_mac_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_external_ip_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_external_mac_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_external_netmask_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_fabric_port_role_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_fail_count_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_flood_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_flow_classifier_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_flow_classify_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_flow_identifier_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_force_link_up_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_forward_error_correction_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_free_count_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_generation_id_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_hash_algorithm_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_hash_gtp_header_match_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_hash_gtp_port_match_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_hash_packet_field_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_hash_packet_type_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_hash_seed_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_hash_type_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_header_size_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_icmp_code_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_icmp_id_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_icmp_type_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_icmpv6_chksum_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_icmpv6_code_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_icmpv6_type_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_identifier_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_idle_notification_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_idle_time_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_idle_timeout_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_ifp_class_id_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_igmp_snooping_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_ingress_port_group_id_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_inner_vlan_vid_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_internal_gateway_mac_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_internal_mac_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_interval_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_ip_fragmentation_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_ip_proto_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_ip_tunnel_type_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_ipv4_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_ipv4_dst_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_ipv4_netmask_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_ipv4_src_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_ipv6_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_ipv6_dst_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_ipv6_prefix_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_ipv6_src_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_known_multicast_rate_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_l2_cache_hit_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_l2_multicast_lookup_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_l3_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_l3_dst_class_id_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_l3_interface_class_id_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_l3_src_class_id_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_lag_options_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_lcore_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_link_up_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_load_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_lookup_count_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_loopback_mode_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_loopback_port_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_lossless_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_lr_all_enabled_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_mac_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_mac_mask_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_matched_count_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_max_count_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_mcg_type_vxlan_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_mgmt_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_mgmt_reselect_on_failure_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_miss_packets_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_mpls_control_word_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_mpls_label_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_mpls_sequenced_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_multicast_interface_id_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_multicast_packet_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_multiplier_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_name_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_ndp_offload_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_ndp_static_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_negate_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_next_hop_ipv4_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_next_hop_mac_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_nexthop_type_vxlan_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_no_arp_response_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_no_ns_response_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_offset_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_optics_always_enabled_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_outer_src_mac_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_parent_port_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_partner_key_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_partner_port_num_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_partner_port_priority_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_partner_state_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_partner_system_mac_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_partner_system_priority_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_passive_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_pdua_rx_instance_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_pim_dr_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_pim_hello_flood_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_port_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_port_mode_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_port_speed_gbps_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_port_usage_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_port_vxlan_mode_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_preserve_vlan_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_priority_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_push_vlan_on_egress_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_push_vlan_on_ingress_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_qos_priority_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_queue_id_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_queue_weight_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_rate_limit_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_rate_unit_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_record_packets_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_redundant_mgmt_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_reference_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_reply_packets_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_request_packets_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_rest_server_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_routing_param_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_rx_bytes_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_rx_packets_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_sampling_rate_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_sctp_dst_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_sctp_src_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_set_loopback_mode_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_socket_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_src_mac_cml_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_status_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_strip_mpls_l2_on_ingress_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_strip_mpls_l3_on_ingress_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_strip_vlan_on_egress_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_sub_agent_id_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_tcp_dst_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_tcp_flags_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_tcp_src_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_thread_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_timestamp_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_ttl_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_tunnel_capability_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_tx_bytes_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_tx_packets_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_udf_anchor_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_udf_capability_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_udf_data_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_udf_id_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_udf_length_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_udf_offset_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_udp_dst_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_udp_src_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_uint32_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_uint64_list_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_unicast_query_timeout_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_unicast_rate_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_unknown_multicast_rate_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_untagged_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_upgrade_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_uri_scheme_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_use_packet_state_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_user_configured_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_vfi_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_vfp_class_id_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_virtual_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_vlan_mac_list_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_vlan_pcp_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_vlan_vid_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_vlan_vid_mask_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_vni_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_vpn_key_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_vrf_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_tlv_vxlan_egress_lag_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_vlan_counter_stats_entry_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_vlan_mac_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_vport_l2gre_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_vport_q_in_q_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bsn_vrf_counter_stats_entry_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bucket_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_bucket_counter_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_flow_stats_entry_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_desc_stats_entry_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_group_stats_entry_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_hello_elem_versionbitmap_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_apply_actions_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_bsn_arp_offload_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_bsn_auto_negotiation_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_bsn_deny_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_bsn_dhcp_offload_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_bsn_directed_broadcast_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_bsn_disable_l3_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_bsn_disable_src_mac_check_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_bsn_disable_vlan_counters_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_bsn_hash_select_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_bsn_internal_priority_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_bsn_ndp_offload_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_bsn_packet_of_death_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_bsn_permit_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_bsn_prioritize_pdus_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_bsn_require_vlan_xlate_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_bsn_span_destination_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_clear_actions_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_goto_table_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_apply_actions_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_bsn_arp_offload_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_bsn_auto_negotiation_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_bsn_deny_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_bsn_dhcp_offload_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_bsn_directed_broadcast_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_bsn_disable_l3_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_bsn_disable_src_mac_check_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_bsn_disable_vlan_counters_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_bsn_hash_select_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_bsn_internal_priority_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_bsn_ndp_offload_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_bsn_packet_of_death_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_bsn_permit_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_bsn_prioritize_pdus_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_bsn_require_vlan_xlate_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_bsn_span_destination_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_clear_actions_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_goto_table_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_meter_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_write_actions_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_id_write_metadata_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_meter_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_write_actions_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_instruction_write_metadata_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_match_v3_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_meter_band_drop_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_meter_band_dscp_remark_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_meter_band_experimenter_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_meter_band_stats_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_meter_config_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_meter_features_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_meter_stats_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_arp_op_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_arp_op_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_arp_sha_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_arp_sha_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_arp_spa_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_arp_spa_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_arp_tha_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_arp_tha_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_arp_tpa_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_arp_tpa_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_egr_port_group_id_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_egr_port_group_id_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_ifp_class_id_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_ifp_class_id_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_in_ports_128_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_in_ports_128_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_in_ports_512_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_in_ports_512_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_ingress_port_group_id_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_ingress_port_group_id_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_inner_eth_dst_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_inner_eth_dst_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_inner_eth_src_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_inner_eth_src_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_inner_vlan_vid_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_inner_vlan_vid_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_ip_fragmentation_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_ip_fragmentation_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_l2_cache_hit_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_l2_cache_hit_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_l3_interface_class_id_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_l3_interface_class_id_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_l3_src_class_id_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_l3_src_class_id_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_lag_id_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_lag_id_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_tcp_flags_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_tcp_flags_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf0_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf0_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf1_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf1_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf2_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf2_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf3_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf3_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf4_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf4_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf5_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf5_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf6_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf6_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf7_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_udf7_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_vfi_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_vfi_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_vlan_xlate_port_group_id_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_vlan_xlate_port_group_id_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_vrf_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_vrf_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_vxlan_network_id_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_bsn_vxlan_network_id_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_ipv6_dst_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_ipv6_dst_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_ipv6_src_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_ipv6_src_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_label_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_label_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_mark_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_mark_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_nw_dst_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_nw_dst_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_nw_proto_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_nw_proto_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_nw_src_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_nw_src_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_state_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_state_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_tp_dst_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_tp_dst_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_tp_src_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_tp_src_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_zone_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_conn_tracking_zone_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_eth_dst_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_eth_dst_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_eth_src_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_eth_src_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_eth_type_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_eth_type_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_icmpv4_code_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_icmpv4_code_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_icmpv4_type_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_icmpv4_type_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_icmpv6_code_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_icmpv6_code_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_icmpv6_type_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_icmpv6_type_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_in_phy_port_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_in_phy_port_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_in_port_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_in_port_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ip_dscp_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ip_dscp_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ip_ecn_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ip_ecn_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ip_proto_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ip_proto_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv4_dst_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv4_dst_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv4_src_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv4_src_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv6_dst_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv6_dst_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv6_exthdr_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv6_exthdr_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv6_flabel_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv6_flabel_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv6_nd_sll_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv6_nd_sll_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv6_nd_target_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv6_nd_target_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv6_nd_tll_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv6_nd_tll_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv6_src_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ipv6_src_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_metadata_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_metadata_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_mpls_bos_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_mpls_bos_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_mpls_label_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_mpls_label_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_mpls_tc_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_mpls_tc_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ovs_tcp_flags_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_ovs_tcp_flags_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_pbb_uca_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_pbb_uca_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_sctp_dst_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_sctp_dst_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_sctp_src_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_sctp_src_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_tcp_dst_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_tcp_dst_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_tcp_src_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_tcp_src_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_tunnel_id_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_tunnel_id_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_tunnel_ipv4_dst_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_tunnel_ipv4_dst_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_tunnel_ipv4_src_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_tunnel_ipv4_src_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_udp_dst_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_udp_dst_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_udp_src_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_udp_src_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_vlan_pcp_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_vlan_pcp_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_vlan_vid_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_oxm_vlan_vid_masked_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_packet_queue_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_desc_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_desc_prop_bsn_breakout_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_desc_prop_bsn_driver_info_json_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_desc_prop_bsn_extended_capabilities_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_desc_prop_bsn_forward_error_correction_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_desc_prop_bsn_generation_id_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_desc_prop_bsn_misc_capabilities_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_desc_prop_bsn_sff_json_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_desc_prop_bsn_speed_capabilities_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_desc_prop_bsn_uplink_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_desc_prop_ethernet_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_desc_prop_optical_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_mod_prop_ethernet_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_mod_prop_optical_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_stats_entry_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_stats_prop_ethernet_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_stats_prop_experimenter_intel_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_port_stats_prop_optical_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_queue_desc_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_queue_desc_prop_bsn_queue_name_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_queue_desc_prop_max_rate_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_queue_desc_prop_min_rate_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_queue_prop_max_rate_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_queue_prop_min_rate_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_queue_stats_entry_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_desc_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_feature_prop_apply_actions_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_feature_prop_apply_actions_miss_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_feature_prop_apply_setfield_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_feature_prop_apply_setfield_miss_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_feature_prop_instructions_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_feature_prop_instructions_miss_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_feature_prop_match_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_feature_prop_next_tables_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_feature_prop_next_tables_miss_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_feature_prop_table_sync_from_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_feature_prop_wildcards_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_feature_prop_write_actions_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_feature_prop_write_actions_miss_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_feature_prop_write_setfield_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_feature_prop_write_setfield_miss_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_features_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_mod_prop_eviction_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_mod_prop_vacancy_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_table_stats_entry_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_uint32_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_uint64_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    obj = (of_object_t *)of_uint8_new(OF_VERSION_1_4);
    of_object_dump((loci_writer_f)fprintf, out, obj);
    of_object_delete(obj);

    fclose(out);
    return TEST_PASS;
}
