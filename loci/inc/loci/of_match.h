/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */

/****************************************************************
 * File: of_match.h
 *
 * DO NOT EDIT
 *
 * This file is automatically generated
 *
 ****************************************************************/


#if !defined(_OF_MATCH_H_)
#define _OF_MATCH_H_


#include <loci/loci_base.h>

/* Identify bits in unified match that are incompatible with V1, V2 matches */
#define OF_MATCH_V1_INCOMPAT ( (uint64_t)0 \
    | ((uint64_t)1 << OF_OXM_INDEX_IPV6_FLABEL)\
    | ((uint64_t)1 << OF_OXM_INDEX_BSN_LAG_ID)\
    | ((uint64_t)1 << OF_OXM_INDEX_IPV6_DST)\
    | ((uint64_t)1 << OF_OXM_INDEX_ARP_TPA)\
    | ((uint64_t)1 << OF_OXM_INDEX_ICMPV6_TYPE)\
    | ((uint64_t)1 << OF_OXM_INDEX_BSN_IN_PORTS_128)\
    | ((uint64_t)1 << OF_OXM_INDEX_ARP_SHA)\
    | ((uint64_t)1 << OF_OXM_INDEX_IPV6_SRC)\
    | ((uint64_t)1 << OF_OXM_INDEX_SCTP_SRC)\
    | ((uint64_t)1 << OF_OXM_INDEX_ICMPV6_CODE)\
    | ((uint64_t)1 << OF_OXM_INDEX_BSN_L3_DST_CLASS_ID)\
    | ((uint64_t)1 << OF_OXM_INDEX_IPV6_ND_SLL)\
    | ((uint64_t)1 << OF_OXM_INDEX_MPLS_TC)\
    | ((uint64_t)1 << OF_OXM_INDEX_IPV6_ND_TLL)\
    | ((uint64_t)1 << OF_OXM_INDEX_BSN_EGR_PORT_GROUP_ID)\
    | ((uint64_t)1 << OF_OXM_INDEX_BSN_UDF2)\
    | ((uint64_t)1 << OF_OXM_INDEX_ARP_OP)\
    | ((uint64_t)1 << OF_OXM_INDEX_ARP_THA)\
    | ((uint64_t)1 << OF_OXM_INDEX_METADATA)\
    | ((uint64_t)1 << OF_OXM_INDEX_BSN_UDF7)\
    | ((uint64_t)1 << OF_OXM_INDEX_BSN_L3_SRC_CLASS_ID)\
    | ((uint64_t)1 << OF_OXM_INDEX_SCTP_DST)\
    | ((uint64_t)1 << OF_OXM_INDEX_ICMPV4_CODE)\
    | ((uint64_t)1 << OF_OXM_INDEX_BSN_VRF)\
    | ((uint64_t)1 << OF_OXM_INDEX_IP_ECN)\
    | ((uint64_t)1 << OF_OXM_INDEX_BSN_UDF4)\
    | ((uint64_t)1 << OF_OXM_INDEX_BSN_GLOBAL_VRF_ALLOWED)\
    | ((uint64_t)1 << OF_OXM_INDEX_UDP_DST)\
    | ((uint64_t)1 << OF_OXM_INDEX_ARP_SPA)\
    | ((uint64_t)1 << OF_OXM_INDEX_IPV6_ND_TARGET)\
    | ((uint64_t)1 << OF_OXM_INDEX_IN_PHY_PORT)\
    | ((uint64_t)1 << OF_OXM_INDEX_UDP_SRC)\
    | ((uint64_t)1 << OF_OXM_INDEX_BSN_UDF1)\
    | ((uint64_t)1 << OF_OXM_INDEX_BSN_UDF0)\
    | ((uint64_t)1 << OF_OXM_INDEX_BSN_UDF3)\
    | ((uint64_t)1 << OF_OXM_INDEX_ICMPV4_TYPE)\
    | ((uint64_t)1 << OF_OXM_INDEX_BSN_UDF5)\
    | ((uint64_t)1 << OF_OXM_INDEX_MPLS_LABEL)\
    | ((uint64_t)1 << OF_OXM_INDEX_BSN_UDF6)\
    | ((uint64_t)1 << OF_OXM_INDEX_BSN_L3_INTERFACE_CLASS_ID))

#define OF_MATCH_V2_INCOMPAT ( (uint64_t)0 \
    | ((uint64_t)1 << OF_OXM_INDEX_IPV6_FLABEL)\
    | ((uint64_t)1 << OF_OXM_INDEX_BSN_LAG_ID)\
    | ((uint64_t)1 << OF_OXM_INDEX_IPV6_DST)\
    | ((uint64_t)1 << OF_OXM_INDEX_ARP_TPA)\
    | ((uint64_t)1 << OF_OXM_INDEX_ICMPV6_TYPE)\
    | ((uint64_t)1 << OF_OXM_INDEX_BSN_IN_PORTS_128)\
    | ((uint64_t)1 << OF_OXM_INDEX_ARP_SHA)\
    | ((uint64_t)1 << OF_OXM_INDEX_IPV6_SRC)\
    | ((uint64_t)1 << OF_OXM_INDEX_SCTP_SRC)\
    | ((uint64_t)1 << OF_OXM_INDEX_ICMPV6_CODE)\
    | ((uint64_t)1 << OF_OXM_INDEX_BSN_L3_DST_CLASS_ID)\
    | ((uint64_t)1 << OF_OXM_INDEX_IPV6_ND_SLL)\
    | ((uint64_t)1 << OF_OXM_INDEX_IPV6_ND_TLL)\
    | ((uint64_t)1 << OF_OXM_INDEX_BSN_EGR_PORT_GROUP_ID)\
    | ((uint64_t)1 << OF_OXM_INDEX_BSN_UDF2)\
    | ((uint64_t)1 << OF_OXM_INDEX_ARP_OP)\
    | ((uint64_t)1 << OF_OXM_INDEX_ARP_THA)\
    | ((uint64_t)1 << OF_OXM_INDEX_BSN_UDF7)\
    | ((uint64_t)1 << OF_OXM_INDEX_BSN_L3_SRC_CLASS_ID)\
    | ((uint64_t)1 << OF_OXM_INDEX_SCTP_DST)\
    | ((uint64_t)1 << OF_OXM_INDEX_ICMPV4_CODE)\
    | ((uint64_t)1 << OF_OXM_INDEX_BSN_VRF)\
    | ((uint64_t)1 << OF_OXM_INDEX_IP_ECN)\
    | ((uint64_t)1 << OF_OXM_INDEX_BSN_UDF4)\
    | ((uint64_t)1 << OF_OXM_INDEX_BSN_GLOBAL_VRF_ALLOWED)\
    | ((uint64_t)1 << OF_OXM_INDEX_UDP_DST)\
    | ((uint64_t)1 << OF_OXM_INDEX_ARP_SPA)\
    | ((uint64_t)1 << OF_OXM_INDEX_IPV6_ND_TARGET)\
    | ((uint64_t)1 << OF_OXM_INDEX_IN_PHY_PORT)\
    | ((uint64_t)1 << OF_OXM_INDEX_UDP_SRC)\
    | ((uint64_t)1 << OF_OXM_INDEX_BSN_UDF1)\
    | ((uint64_t)1 << OF_OXM_INDEX_BSN_UDF0)\
    | ((uint64_t)1 << OF_OXM_INDEX_BSN_UDF3)\
    | ((uint64_t)1 << OF_OXM_INDEX_ICMPV4_TYPE)\
    | ((uint64_t)1 << OF_OXM_INDEX_BSN_UDF5)\
    | ((uint64_t)1 << OF_OXM_INDEX_BSN_UDF6)\
    | ((uint64_t)1 << OF_OXM_INDEX_BSN_L3_INTERFACE_CLASS_ID))

/* Indexed by version number */
extern const uint64_t of_match_incompat[4];
/* Unified, flat OpenFlow match structure based on OF 1.2 */
typedef struct of_match_fields_s {
    /* Version 1.2 is used for field names */
    of_port_no_t         in_port;
    of_port_no_t         in_phy_port;
    uint64_t             metadata;
    of_mac_addr_t        eth_dst;
    of_mac_addr_t        eth_src;
    uint16_t             eth_type;
    uint16_t             vlan_vid;
    uint8_t              vlan_pcp;
    uint8_t              ip_dscp;
    uint8_t              ip_ecn;
    uint8_t              ip_proto;
    of_ipv4_t            ipv4_src;
    of_ipv4_t            ipv4_dst;
    uint16_t             tcp_dst;
    uint16_t             tcp_src;
    uint16_t             udp_dst;
    uint16_t             udp_src;
    uint16_t             sctp_dst;
    uint16_t             sctp_src;
    uint8_t              icmpv4_type;
    uint8_t              icmpv4_code;
    uint16_t             arp_op;
    uint32_t             arp_spa;
    uint32_t             arp_tpa;
    of_mac_addr_t        arp_sha;
    of_mac_addr_t        arp_tha;
    of_ipv6_t            ipv6_src;
    of_ipv6_t            ipv6_dst;
    uint32_t             ipv6_flabel;
    uint8_t              icmpv6_type;
    uint8_t              icmpv6_code;
    of_ipv6_t            ipv6_nd_target;
    of_mac_addr_t        ipv6_nd_sll;
    of_mac_addr_t        ipv6_nd_tll;
    uint32_t             mpls_label;
    uint8_t              mpls_tc;
    of_bitmap_128_t      bsn_in_ports_128;
    uint32_t             bsn_lag_id;
    uint32_t             bsn_vrf;
    uint8_t              bsn_global_vrf_allowed;
    uint32_t             bsn_l3_interface_class_id;
    uint32_t             bsn_l3_src_class_id;
    uint32_t             bsn_l3_dst_class_id;
    uint32_t             bsn_egr_port_group_id;
    uint32_t             bsn_udf2;
    uint32_t             bsn_udf7;
    uint32_t             bsn_udf4;
    uint32_t             bsn_udf1;
    uint32_t             bsn_udf0;
    uint32_t             bsn_udf3;
    uint32_t             bsn_udf5;
    uint32_t             bsn_udf6;

} of_match_fields_t;

/**
 * @brief The LOCI match structure.
 */

typedef struct of_match_s {
    of_version_t version;
    of_match_fields_t fields;
    of_match_fields_t masks;
} of_match_t;

/**
 * Mask the values in the match structure according to its fields
 */
static inline void of_match_values_mask(of_match_t *match)
{
    int idx;

    for (idx = 0; idx < sizeof(of_match_fields_t); idx++) {
        ((uint8_t *)&match->fields)[idx] &= ((uint8_t *)&match->masks)[idx];
    }
}

/**
 * IP Mask map.  IP maks wildcards from OF 1.0 are interpretted as
 * indices into the map below.
 *
 * of_ip_mask_map: Array mapping index to mask
 * of_ip_mask_use_map: Boolean indication set when map is initialized
 * of_ip_mask_map_init: Initialize to default values; set "use map".
 */
#define OF_IP_MASK_MAP_COUNT 64
extern uint32_t of_ip_mask_map[OF_IP_MASK_MAP_COUNT];
extern int of_ip_mask_map_init_done;

#define OF_IP_MASK_INIT_CHECK     if (!of_ip_mask_map_init_done) of_ip_mask_map_init()

/**
 * Initialize map
 */
extern void of_ip_mask_map_init(void);

extern int of_ip_mask_map_set(int index, uint32_t mask);
extern int of_ip_mask_map_get(int index, uint32_t *mask);

/**
 * @brief Map from mask to index
 */

extern int of_ip_mask_to_index(uint32_t mask);

/**
 * @brief Map from index to mask
 */

extern uint32_t of_ip_index_to_mask(int index);

/**
 * The signalling of an untagged packet varies by OF version.
 * Use this macro to set the field value.
 */
#define OF_MATCH_UNTAGGED_VLAN_ID(version) \
    ((version) == OF_VERSION_1_0 ? 0xffff : \
     ((version) == OF_VERSION_1_1 ? 0xffff : 0))

/**
 * Version 1.1 had the notion of "any" vlan but must be set
 */
#define OF_MATCH_VLAN_TAG_PRESENT_ANY_ID(version) \
    ((version) == OF_VERSION_1_0 ? 0 /* @fixme */  : \
     ((version) == OF_VERSION_1_1 ? 0xfffe : 0x1000))

/**
 * Determine "more specific" relationship between mac addrs
 * @return true if v1 is equal to or more specific than v2
 *
 * @todo Could be optimized
 *
 * Check: Every bit in v2 is set in v1; v1 may have add'l bits set.
 * That is, return false if there is a bit set in v2 and not in v1.
 */

static inline int
of_more_specific_ipv6(of_ipv6_t *v1, of_ipv6_t *v2) {
    int idx;

    for (idx = 0; idx < OF_IPV6_BYTES; idx++) {
        /* If there's a bit set in v2 that is clear in v1, return false */
        if (~v1->addr[idx] & v2->addr[idx]) {
            return 0;
        }
    }

    return 1;
}

/**
 * Boolean test if two values agree when restricted to a mask
 */

static inline int
of_restricted_match_ipv6(of_ipv6_t *v1, of_ipv6_t *v2, of_ipv6_t *mask) {
    int idx;

    for (idx = 0; idx < OF_IPV6_BYTES; idx++) {
        if ((v1->addr[idx] & mask->addr[idx]) !=
               (v2->addr[idx] & mask->addr[idx])) {
            return 0;
        }
    }

    return 1;
}

/**
 * Boolean test if two values "overlap" (agree on common masks)
 */

static inline int
of_overlap_ipv6(of_ipv6_t *v1, of_ipv6_t *v2,
                         of_ipv6_t *m1, of_ipv6_t *m2) {
    int idx;

    for (idx = 0; idx < OF_IPV6_BYTES; idx++) {
        if (((v1->addr[idx] & m1->addr[idx]) & m2->addr[idx]) !=
               ((v2->addr[idx] & m1->addr[idx]) & m2->addr[idx])) {
            return 0;
        }
    }

    return 1;
}

#define OF_MORE_SPECIFIC_IPV6(v1, v2) of_more_specific_ipv6((v1), (v2))

#define OF_RESTRICTED_MATCH_IPV6(v1, v2, mask) \
    of_restricted_match_ipv6((v1), (v2), (mask))

#define OF_OVERLAP_IPV6(v1, v2, m1, m2) of_overlap_ipv6((v1), (v2), (m1), (m2))

/**
 * Determine "more specific" relationship between mac addrs
 * @return true if v1 is equal to or more specific than v2
 *
 * @todo Could be optimized
 *
 * Check: Every bit in v2 is set in v1; v1 may have add'l bits set.
 * That is, return false if there is a bit set in v2 and not in v1.
 */
static inline int
of_more_specific_mac_addr(of_mac_addr_t *v1, of_mac_addr_t *v2) {
    int idx;

    for (idx = 0; idx < OF_MAC_ADDR_BYTES; idx++) {
        /* If there's a bit set in v2 that is clear in v1, return false */
        if (~v1->addr[idx] & v2->addr[idx]) {
            return 0;
        }
    }

    return 1;
}

/**
 * Boolean test if two values agree when restricted to a mask
 */
static inline int
of_restricted_match_mac_addr(of_mac_addr_t *v1, of_mac_addr_t *v2,
                             of_mac_addr_t *mask) {
    int idx;

    for (idx = 0; idx < OF_MAC_ADDR_BYTES; idx++) {
        if ((v1->addr[idx] & mask->addr[idx]) !=
               (v2->addr[idx] & mask->addr[idx])) {
            return 0;
        }
    }

    return 1;
}

/**
 * Boolean test if two values "overlap" (agree on common masks)
 */

static inline int
of_overlap_mac_addr(of_mac_addr_t *v1, of_mac_addr_t *v2,
                         of_mac_addr_t *m1, of_mac_addr_t *m2) {
    int idx;

    for (idx = 0; idx < OF_MAC_ADDR_BYTES; idx++) {
        if (((v1->addr[idx] & m1->addr[idx]) & m2->addr[idx]) !=
               ((v2->addr[idx] & m1->addr[idx]) & m2->addr[idx])) {
            return 0;
        }
    }

    return 1;
}

#define OF_MORE_SPECIFIC_MAC_ADDR(v1, v2) of_more_specific_mac_addr((v1), (v2))

#define OF_RESTRICTED_MATCH_MAC_ADDR(v1, v2, mask) \
    of_restricted_match_mac_addr((v1), (v2), (mask))

#define OF_OVERLAP_MAC_ADDR(v1, v2, m1, m2) \
    of_overlap_mac_addr((v1), (v2), (m1), (m2))

#define OF_MORE_SPECIFIC_BITMAP_128(v1, v2) \
    (OF_MORE_SPECIFIC_INT((v1)->lo, (v2)->lo) && OF_MORE_SPECIFIC_INT((v1)->hi, (v2)->hi))

#define OF_RESTRICTED_MATCH_BITMAP_128(v1, v2, mask) \
    (OF_RESTRICTED_MATCH_INT((v1)->lo, (v2)->lo, (mask)->lo) && OF_RESTRICTED_MATCH_INT((v1)->hi, (v2)->hi, (mask)->hi))

#define OF_OVERLAP_BITMAP_128(v1, v2, m1, m2) \
    (OF_OVERLAP_INT((v1)->lo, (v2)->lo, (m1)->lo, (m2)->lo) && OF_OVERLAP_INT((v1)->hi, (v2)->hi, (m1)->hi, (m2)->hi))

/**
 * More-specific-than macro for integer types; see above
 * @return true if v1 is equal to or more specific than v2
 *
 * If there is a bit that is set in v2 and not in v1, return false.
 */
#define OF_MORE_SPECIFIC_INT(v1, v2) (!(~(v1) & (v2)))

/**
 * Boolean test if two values agree when restricted to a mask
 */
#define OF_RESTRICTED_MATCH_INT(v1, v2, mask) \
   (((v1) & (mask)) == ((v2) & (mask)))


#define OF_OVERLAP_INT(v1, v2, m1, m2) \
    ((((v1) & (m1)) & (m2)) == (((v2) & (m1)) & (m2)))

/**
 * Compare two match structures for exact equality
 *
 * We just do memcmp assuming structs were memset to 0 on init
 */
static inline int
of_match_eq(of_match_t *match1, of_match_t *match2)
{
    return (MEMCMP(match1, match2, sizeof(of_match_t)) == 0);
}

/**
 * Is the entry match more specific than (or equal to) the query match?
 * @param entry Match expected to be more specific (subset of query)
 * @param query Match expected to be less specific (superset of entry)
 * @returns Boolean, see below
 *
 * The assumption is that a query is being done for a non-strict
 * match against an entry in a table.  The result is true if the
 * entry match indicates a more specific (but compatible) flow space
 * specification than that in the query match.  This means that the
 * values agree between the two where they overlap, and that each mask
 * for the entry is more specific than that of the query.
 *
 * The query has the less specific mask (fewer mask bits) so it is
 * used for the mask when checking values.
 */

static inline int
of_match_more_specific(of_match_t *entry, of_match_t *query)
{
    of_match_fields_t *q_m, *e_m;  /* Short hand for masks, fields */
    of_match_fields_t *q_f, *e_f;

    q_m = &query->masks;
    e_m = &entry->masks;
    q_f = &query->fields;
    e_f = &entry->fields;

    /* Mask and values for ipv6_flabel */
    if (!OF_MORE_SPECIFIC_INT(e_m->ipv6_flabel, q_m->ipv6_flabel)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_INT(e_f->ipv6_flabel, q_f->ipv6_flabel,
            q_m->ipv6_flabel)) {
        return 0;
    }

    /* Mask and values for bsn_lag_id */
    if (!OF_MORE_SPECIFIC_INT(e_m->bsn_lag_id, q_m->bsn_lag_id)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_INT(e_f->bsn_lag_id, q_f->bsn_lag_id,
            q_m->bsn_lag_id)) {
        return 0;
    }

    /* Mask and values for vlan_pcp */
    if (!OF_MORE_SPECIFIC_INT(e_m->vlan_pcp, q_m->vlan_pcp)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_INT(e_f->vlan_pcp, q_f->vlan_pcp,
            q_m->vlan_pcp)) {
        return 0;
    }

    /* Mask and values for ipv4_src */
    if (!OF_MORE_SPECIFIC_INT(e_m->ipv4_src, q_m->ipv4_src)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_INT(e_f->ipv4_src, q_f->ipv4_src,
            q_m->ipv4_src)) {
        return 0;
    }

    /* Mask and values for ipv6_dst */
    if (!OF_MORE_SPECIFIC_IPV6(&e_m->ipv6_dst, &q_m->ipv6_dst)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_IPV6(&e_f->ipv6_dst, &q_f->ipv6_dst,
            &q_m->ipv6_dst)) {
        return 0;
    }

    /* Mask and values for arp_tpa */
    if (!OF_MORE_SPECIFIC_INT(e_m->arp_tpa, q_m->arp_tpa)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_INT(e_f->arp_tpa, q_f->arp_tpa,
            q_m->arp_tpa)) {
        return 0;
    }

    /* Mask and values for icmpv6_type */
    if (!OF_MORE_SPECIFIC_INT(e_m->icmpv6_type, q_m->icmpv6_type)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_INT(e_f->icmpv6_type, q_f->icmpv6_type,
            q_m->icmpv6_type)) {
        return 0;
    }

    /* Mask and values for bsn_in_ports_128 */
    if (!OF_MORE_SPECIFIC_BITMAP_128(&e_m->bsn_in_ports_128, &q_m->bsn_in_ports_128)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_BITMAP_128(&e_f->bsn_in_ports_128, &q_f->bsn_in_ports_128,
            &q_m->bsn_in_ports_128)) {
        return 0;
    }

    /* Mask and values for arp_sha */
    if (!OF_MORE_SPECIFIC_MAC_ADDR(&e_m->arp_sha, &q_m->arp_sha)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_MAC_ADDR(&e_f->arp_sha, &q_f->arp_sha,
            &q_m->arp_sha)) {
        return 0;
    }

    /* Mask and values for ipv6_src */
    if (!OF_MORE_SPECIFIC_IPV6(&e_m->ipv6_src, &q_m->ipv6_src)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_IPV6(&e_f->ipv6_src, &q_f->ipv6_src,
            &q_m->ipv6_src)) {
        return 0;
    }

    /* Mask and values for sctp_src */
    if (!OF_MORE_SPECIFIC_INT(e_m->sctp_src, q_m->sctp_src)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_INT(e_f->sctp_src, q_f->sctp_src,
            q_m->sctp_src)) {
        return 0;
    }

    /* Mask and values for icmpv6_code */
    if (!OF_MORE_SPECIFIC_INT(e_m->icmpv6_code, q_m->icmpv6_code)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_INT(e_f->icmpv6_code, q_f->icmpv6_code,
            q_m->icmpv6_code)) {
        return 0;
    }

    /* Mask and values for eth_dst */
    if (!OF_MORE_SPECIFIC_MAC_ADDR(&e_m->eth_dst, &q_m->eth_dst)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_MAC_ADDR(&e_f->eth_dst, &q_f->eth_dst,
            &q_m->eth_dst)) {
        return 0;
    }

    /* Mask and values for bsn_l3_dst_class_id */
    if (!OF_MORE_SPECIFIC_INT(e_m->bsn_l3_dst_class_id, q_m->bsn_l3_dst_class_id)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_INT(e_f->bsn_l3_dst_class_id, q_f->bsn_l3_dst_class_id,
            q_m->bsn_l3_dst_class_id)) {
        return 0;
    }

    /* Mask and values for ipv6_nd_sll */
    if (!OF_MORE_SPECIFIC_MAC_ADDR(&e_m->ipv6_nd_sll, &q_m->ipv6_nd_sll)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_MAC_ADDR(&e_f->ipv6_nd_sll, &q_f->ipv6_nd_sll,
            &q_m->ipv6_nd_sll)) {
        return 0;
    }

    /* Mask and values for mpls_tc */
    if (!OF_MORE_SPECIFIC_INT(e_m->mpls_tc, q_m->mpls_tc)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_INT(e_f->mpls_tc, q_f->mpls_tc,
            q_m->mpls_tc)) {
        return 0;
    }

    /* Mask and values for ipv6_nd_tll */
    if (!OF_MORE_SPECIFIC_MAC_ADDR(&e_m->ipv6_nd_tll, &q_m->ipv6_nd_tll)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_MAC_ADDR(&e_f->ipv6_nd_tll, &q_f->ipv6_nd_tll,
            &q_m->ipv6_nd_tll)) {
        return 0;
    }

    /* Mask and values for bsn_egr_port_group_id */
    if (!OF_MORE_SPECIFIC_INT(e_m->bsn_egr_port_group_id, q_m->bsn_egr_port_group_id)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_INT(e_f->bsn_egr_port_group_id, q_f->bsn_egr_port_group_id,
            q_m->bsn_egr_port_group_id)) {
        return 0;
    }

    /* Mask and values for bsn_udf2 */
    if (!OF_MORE_SPECIFIC_INT(e_m->bsn_udf2, q_m->bsn_udf2)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_INT(e_f->bsn_udf2, q_f->bsn_udf2,
            q_m->bsn_udf2)) {
        return 0;
    }

    /* Mask and values for eth_type */
    if (!OF_MORE_SPECIFIC_INT(e_m->eth_type, q_m->eth_type)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_INT(e_f->eth_type, q_f->eth_type,
            q_m->eth_type)) {
        return 0;
    }

    /* Mask and values for arp_op */
    if (!OF_MORE_SPECIFIC_INT(e_m->arp_op, q_m->arp_op)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_INT(e_f->arp_op, q_f->arp_op,
            q_m->arp_op)) {
        return 0;
    }

    /* Mask and values for vlan_vid */
    if (!OF_MORE_SPECIFIC_INT(e_m->vlan_vid, q_m->vlan_vid)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_INT(e_f->vlan_vid, q_f->vlan_vid,
            q_m->vlan_vid)) {
        return 0;
    }

    /* Mask and values for arp_tha */
    if (!OF_MORE_SPECIFIC_MAC_ADDR(&e_m->arp_tha, &q_m->arp_tha)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_MAC_ADDR(&e_f->arp_tha, &q_f->arp_tha,
            &q_m->arp_tha)) {
        return 0;
    }

    /* Mask and values for in_port */
    if (!OF_MORE_SPECIFIC_INT(e_m->in_port, q_m->in_port)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_INT(e_f->in_port, q_f->in_port,
            q_m->in_port)) {
        return 0;
    }

    /* Mask and values for metadata */
    if (!OF_MORE_SPECIFIC_INT(e_m->metadata, q_m->metadata)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_INT(e_f->metadata, q_f->metadata,
            q_m->metadata)) {
        return 0;
    }

    /* Mask and values for bsn_udf7 */
    if (!OF_MORE_SPECIFIC_INT(e_m->bsn_udf7, q_m->bsn_udf7)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_INT(e_f->bsn_udf7, q_f->bsn_udf7,
            q_m->bsn_udf7)) {
        return 0;
    }

    /* Mask and values for bsn_l3_src_class_id */
    if (!OF_MORE_SPECIFIC_INT(e_m->bsn_l3_src_class_id, q_m->bsn_l3_src_class_id)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_INT(e_f->bsn_l3_src_class_id, q_f->bsn_l3_src_class_id,
            q_m->bsn_l3_src_class_id)) {
        return 0;
    }

    /* Mask and values for sctp_dst */
    if (!OF_MORE_SPECIFIC_INT(e_m->sctp_dst, q_m->sctp_dst)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_INT(e_f->sctp_dst, q_f->sctp_dst,
            q_m->sctp_dst)) {
        return 0;
    }

    /* Mask and values for icmpv4_code */
    if (!OF_MORE_SPECIFIC_INT(e_m->icmpv4_code, q_m->icmpv4_code)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_INT(e_f->icmpv4_code, q_f->icmpv4_code,
            q_m->icmpv4_code)) {
        return 0;
    }

    /* Mask and values for tcp_src */
    if (!OF_MORE_SPECIFIC_INT(e_m->tcp_src, q_m->tcp_src)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_INT(e_f->tcp_src, q_f->tcp_src,
            q_m->tcp_src)) {
        return 0;
    }

    /* Mask and values for bsn_vrf */
    if (!OF_MORE_SPECIFIC_INT(e_m->bsn_vrf, q_m->bsn_vrf)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_INT(e_f->bsn_vrf, q_f->bsn_vrf,
            q_m->bsn_vrf)) {
        return 0;
    }

    /* Mask and values for ip_ecn */
    if (!OF_MORE_SPECIFIC_INT(e_m->ip_ecn, q_m->ip_ecn)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_INT(e_f->ip_ecn, q_f->ip_ecn,
            q_m->ip_ecn)) {
        return 0;
    }

    /* Mask and values for bsn_udf4 */
    if (!OF_MORE_SPECIFIC_INT(e_m->bsn_udf4, q_m->bsn_udf4)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_INT(e_f->bsn_udf4, q_f->bsn_udf4,
            q_m->bsn_udf4)) {
        return 0;
    }

    /* Mask and values for bsn_global_vrf_allowed */
    if (!OF_MORE_SPECIFIC_INT(e_m->bsn_global_vrf_allowed, q_m->bsn_global_vrf_allowed)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_INT(e_f->bsn_global_vrf_allowed, q_f->bsn_global_vrf_allowed,
            q_m->bsn_global_vrf_allowed)) {
        return 0;
    }

    /* Mask and values for udp_dst */
    if (!OF_MORE_SPECIFIC_INT(e_m->udp_dst, q_m->udp_dst)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_INT(e_f->udp_dst, q_f->udp_dst,
            q_m->udp_dst)) {
        return 0;
    }

    /* Mask and values for arp_spa */
    if (!OF_MORE_SPECIFIC_INT(e_m->arp_spa, q_m->arp_spa)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_INT(e_f->arp_spa, q_f->arp_spa,
            q_m->arp_spa)) {
        return 0;
    }

    /* Mask and values for ipv6_nd_target */
    if (!OF_MORE_SPECIFIC_IPV6(&e_m->ipv6_nd_target, &q_m->ipv6_nd_target)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_IPV6(&e_f->ipv6_nd_target, &q_f->ipv6_nd_target,
            &q_m->ipv6_nd_target)) {
        return 0;
    }

    /* Mask and values for in_phy_port */
    if (!OF_MORE_SPECIFIC_INT(e_m->in_phy_port, q_m->in_phy_port)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_INT(e_f->in_phy_port, q_f->in_phy_port,
            q_m->in_phy_port)) {
        return 0;
    }

    /* Mask and values for ipv4_dst */
    if (!OF_MORE_SPECIFIC_INT(e_m->ipv4_dst, q_m->ipv4_dst)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_INT(e_f->ipv4_dst, q_f->ipv4_dst,
            q_m->ipv4_dst)) {
        return 0;
    }

    /* Mask and values for eth_src */
    if (!OF_MORE_SPECIFIC_MAC_ADDR(&e_m->eth_src, &q_m->eth_src)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_MAC_ADDR(&e_f->eth_src, &q_f->eth_src,
            &q_m->eth_src)) {
        return 0;
    }

    /* Mask and values for udp_src */
    if (!OF_MORE_SPECIFIC_INT(e_m->udp_src, q_m->udp_src)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_INT(e_f->udp_src, q_f->udp_src,
            q_m->udp_src)) {
        return 0;
    }

    /* Mask and values for bsn_udf1 */
    if (!OF_MORE_SPECIFIC_INT(e_m->bsn_udf1, q_m->bsn_udf1)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_INT(e_f->bsn_udf1, q_f->bsn_udf1,
            q_m->bsn_udf1)) {
        return 0;
    }

    /* Mask and values for bsn_udf0 */
    if (!OF_MORE_SPECIFIC_INT(e_m->bsn_udf0, q_m->bsn_udf0)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_INT(e_f->bsn_udf0, q_f->bsn_udf0,
            q_m->bsn_udf0)) {
        return 0;
    }

    /* Mask and values for bsn_udf3 */
    if (!OF_MORE_SPECIFIC_INT(e_m->bsn_udf3, q_m->bsn_udf3)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_INT(e_f->bsn_udf3, q_f->bsn_udf3,
            q_m->bsn_udf3)) {
        return 0;
    }

    /* Mask and values for icmpv4_type */
    if (!OF_MORE_SPECIFIC_INT(e_m->icmpv4_type, q_m->icmpv4_type)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_INT(e_f->icmpv4_type, q_f->icmpv4_type,
            q_m->icmpv4_type)) {
        return 0;
    }

    /* Mask and values for bsn_udf5 */
    if (!OF_MORE_SPECIFIC_INT(e_m->bsn_udf5, q_m->bsn_udf5)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_INT(e_f->bsn_udf5, q_f->bsn_udf5,
            q_m->bsn_udf5)) {
        return 0;
    }

    /* Mask and values for mpls_label */
    if (!OF_MORE_SPECIFIC_INT(e_m->mpls_label, q_m->mpls_label)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_INT(e_f->mpls_label, q_f->mpls_label,
            q_m->mpls_label)) {
        return 0;
    }

    /* Mask and values for tcp_dst */
    if (!OF_MORE_SPECIFIC_INT(e_m->tcp_dst, q_m->tcp_dst)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_INT(e_f->tcp_dst, q_f->tcp_dst,
            q_m->tcp_dst)) {
        return 0;
    }

    /* Mask and values for bsn_udf6 */
    if (!OF_MORE_SPECIFIC_INT(e_m->bsn_udf6, q_m->bsn_udf6)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_INT(e_f->bsn_udf6, q_f->bsn_udf6,
            q_m->bsn_udf6)) {
        return 0;
    }

    /* Mask and values for ip_proto */
    if (!OF_MORE_SPECIFIC_INT(e_m->ip_proto, q_m->ip_proto)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_INT(e_f->ip_proto, q_f->ip_proto,
            q_m->ip_proto)) {
        return 0;
    }

    /* Mask and values for bsn_l3_interface_class_id */
    if (!OF_MORE_SPECIFIC_INT(e_m->bsn_l3_interface_class_id, q_m->bsn_l3_interface_class_id)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_INT(e_f->bsn_l3_interface_class_id, q_f->bsn_l3_interface_class_id,
            q_m->bsn_l3_interface_class_id)) {
        return 0;
    }

    /* Mask and values for ip_dscp */
    if (!OF_MORE_SPECIFIC_INT(e_m->ip_dscp, q_m->ip_dscp)) {
        return 0;
    }
    if (!OF_RESTRICTED_MATCH_INT(e_f->ip_dscp, q_f->ip_dscp,
            q_m->ip_dscp)) {
        return 0;
    }

    return 1;
}


/**
 * Do two entries overlap?
 * @param match1 One match struct
 * @param match2 Another match struct
 * @returns Boolean: true if there is a packet that would match both
 *
 */

static inline int
of_match_overlap(of_match_t *match1, of_match_t *match2)
{
    of_match_fields_t *m1, *m2;  /* Short hand for masks, fields */
    of_match_fields_t *f1, *f2;

    m1 = &match1->masks;
    m2 = &match2->masks;
    f1 = &match1->fields;
    f2 = &match2->fields;

    /* Check overlap for ipv6_flabel */
    if (!OF_OVERLAP_INT(f1->ipv6_flabel, f2->ipv6_flabel,
        m2->ipv6_flabel, m1->ipv6_flabel)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for bsn_lag_id */
    if (!OF_OVERLAP_INT(f1->bsn_lag_id, f2->bsn_lag_id,
        m2->bsn_lag_id, m1->bsn_lag_id)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for vlan_pcp */
    if (!OF_OVERLAP_INT(f1->vlan_pcp, f2->vlan_pcp,
        m2->vlan_pcp, m1->vlan_pcp)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for ipv4_src */
    if (!OF_OVERLAP_INT(f1->ipv4_src, f2->ipv4_src,
        m2->ipv4_src, m1->ipv4_src)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for ipv6_dst */
    if (!OF_OVERLAP_IPV6(&f1->ipv6_dst, &f2->ipv6_dst,
        &m2->ipv6_dst, &m1->ipv6_dst)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for arp_tpa */
    if (!OF_OVERLAP_INT(f1->arp_tpa, f2->arp_tpa,
        m2->arp_tpa, m1->arp_tpa)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for icmpv6_type */
    if (!OF_OVERLAP_INT(f1->icmpv6_type, f2->icmpv6_type,
        m2->icmpv6_type, m1->icmpv6_type)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for bsn_in_ports_128 */
    if (!OF_OVERLAP_BITMAP_128(&f1->bsn_in_ports_128, &f2->bsn_in_ports_128,
        &m2->bsn_in_ports_128, &m1->bsn_in_ports_128)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for arp_sha */
    if (!OF_OVERLAP_MAC_ADDR(&f1->arp_sha, &f2->arp_sha,
        &m2->arp_sha, &m1->arp_sha)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for ipv6_src */
    if (!OF_OVERLAP_IPV6(&f1->ipv6_src, &f2->ipv6_src,
        &m2->ipv6_src, &m1->ipv6_src)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for sctp_src */
    if (!OF_OVERLAP_INT(f1->sctp_src, f2->sctp_src,
        m2->sctp_src, m1->sctp_src)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for icmpv6_code */
    if (!OF_OVERLAP_INT(f1->icmpv6_code, f2->icmpv6_code,
        m2->icmpv6_code, m1->icmpv6_code)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for eth_dst */
    if (!OF_OVERLAP_MAC_ADDR(&f1->eth_dst, &f2->eth_dst,
        &m2->eth_dst, &m1->eth_dst)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for bsn_l3_dst_class_id */
    if (!OF_OVERLAP_INT(f1->bsn_l3_dst_class_id, f2->bsn_l3_dst_class_id,
        m2->bsn_l3_dst_class_id, m1->bsn_l3_dst_class_id)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for ipv6_nd_sll */
    if (!OF_OVERLAP_MAC_ADDR(&f1->ipv6_nd_sll, &f2->ipv6_nd_sll,
        &m2->ipv6_nd_sll, &m1->ipv6_nd_sll)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for mpls_tc */
    if (!OF_OVERLAP_INT(f1->mpls_tc, f2->mpls_tc,
        m2->mpls_tc, m1->mpls_tc)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for ipv6_nd_tll */
    if (!OF_OVERLAP_MAC_ADDR(&f1->ipv6_nd_tll, &f2->ipv6_nd_tll,
        &m2->ipv6_nd_tll, &m1->ipv6_nd_tll)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for bsn_egr_port_group_id */
    if (!OF_OVERLAP_INT(f1->bsn_egr_port_group_id, f2->bsn_egr_port_group_id,
        m2->bsn_egr_port_group_id, m1->bsn_egr_port_group_id)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for bsn_udf2 */
    if (!OF_OVERLAP_INT(f1->bsn_udf2, f2->bsn_udf2,
        m2->bsn_udf2, m1->bsn_udf2)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for eth_type */
    if (!OF_OVERLAP_INT(f1->eth_type, f2->eth_type,
        m2->eth_type, m1->eth_type)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for arp_op */
    if (!OF_OVERLAP_INT(f1->arp_op, f2->arp_op,
        m2->arp_op, m1->arp_op)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for vlan_vid */
    if (!OF_OVERLAP_INT(f1->vlan_vid, f2->vlan_vid,
        m2->vlan_vid, m1->vlan_vid)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for arp_tha */
    if (!OF_OVERLAP_MAC_ADDR(&f1->arp_tha, &f2->arp_tha,
        &m2->arp_tha, &m1->arp_tha)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for in_port */
    if (!OF_OVERLAP_INT(f1->in_port, f2->in_port,
        m2->in_port, m1->in_port)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for metadata */
    if (!OF_OVERLAP_INT(f1->metadata, f2->metadata,
        m2->metadata, m1->metadata)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for bsn_udf7 */
    if (!OF_OVERLAP_INT(f1->bsn_udf7, f2->bsn_udf7,
        m2->bsn_udf7, m1->bsn_udf7)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for bsn_l3_src_class_id */
    if (!OF_OVERLAP_INT(f1->bsn_l3_src_class_id, f2->bsn_l3_src_class_id,
        m2->bsn_l3_src_class_id, m1->bsn_l3_src_class_id)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for sctp_dst */
    if (!OF_OVERLAP_INT(f1->sctp_dst, f2->sctp_dst,
        m2->sctp_dst, m1->sctp_dst)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for icmpv4_code */
    if (!OF_OVERLAP_INT(f1->icmpv4_code, f2->icmpv4_code,
        m2->icmpv4_code, m1->icmpv4_code)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for tcp_src */
    if (!OF_OVERLAP_INT(f1->tcp_src, f2->tcp_src,
        m2->tcp_src, m1->tcp_src)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for bsn_vrf */
    if (!OF_OVERLAP_INT(f1->bsn_vrf, f2->bsn_vrf,
        m2->bsn_vrf, m1->bsn_vrf)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for ip_ecn */
    if (!OF_OVERLAP_INT(f1->ip_ecn, f2->ip_ecn,
        m2->ip_ecn, m1->ip_ecn)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for bsn_udf4 */
    if (!OF_OVERLAP_INT(f1->bsn_udf4, f2->bsn_udf4,
        m2->bsn_udf4, m1->bsn_udf4)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for bsn_global_vrf_allowed */
    if (!OF_OVERLAP_INT(f1->bsn_global_vrf_allowed, f2->bsn_global_vrf_allowed,
        m2->bsn_global_vrf_allowed, m1->bsn_global_vrf_allowed)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for udp_dst */
    if (!OF_OVERLAP_INT(f1->udp_dst, f2->udp_dst,
        m2->udp_dst, m1->udp_dst)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for arp_spa */
    if (!OF_OVERLAP_INT(f1->arp_spa, f2->arp_spa,
        m2->arp_spa, m1->arp_spa)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for ipv6_nd_target */
    if (!OF_OVERLAP_IPV6(&f1->ipv6_nd_target, &f2->ipv6_nd_target,
        &m2->ipv6_nd_target, &m1->ipv6_nd_target)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for in_phy_port */
    if (!OF_OVERLAP_INT(f1->in_phy_port, f2->in_phy_port,
        m2->in_phy_port, m1->in_phy_port)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for ipv4_dst */
    if (!OF_OVERLAP_INT(f1->ipv4_dst, f2->ipv4_dst,
        m2->ipv4_dst, m1->ipv4_dst)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for eth_src */
    if (!OF_OVERLAP_MAC_ADDR(&f1->eth_src, &f2->eth_src,
        &m2->eth_src, &m1->eth_src)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for udp_src */
    if (!OF_OVERLAP_INT(f1->udp_src, f2->udp_src,
        m2->udp_src, m1->udp_src)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for bsn_udf1 */
    if (!OF_OVERLAP_INT(f1->bsn_udf1, f2->bsn_udf1,
        m2->bsn_udf1, m1->bsn_udf1)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for bsn_udf0 */
    if (!OF_OVERLAP_INT(f1->bsn_udf0, f2->bsn_udf0,
        m2->bsn_udf0, m1->bsn_udf0)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for bsn_udf3 */
    if (!OF_OVERLAP_INT(f1->bsn_udf3, f2->bsn_udf3,
        m2->bsn_udf3, m1->bsn_udf3)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for icmpv4_type */
    if (!OF_OVERLAP_INT(f1->icmpv4_type, f2->icmpv4_type,
        m2->icmpv4_type, m1->icmpv4_type)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for bsn_udf5 */
    if (!OF_OVERLAP_INT(f1->bsn_udf5, f2->bsn_udf5,
        m2->bsn_udf5, m1->bsn_udf5)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for mpls_label */
    if (!OF_OVERLAP_INT(f1->mpls_label, f2->mpls_label,
        m2->mpls_label, m1->mpls_label)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for tcp_dst */
    if (!OF_OVERLAP_INT(f1->tcp_dst, f2->tcp_dst,
        m2->tcp_dst, m1->tcp_dst)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for bsn_udf6 */
    if (!OF_OVERLAP_INT(f1->bsn_udf6, f2->bsn_udf6,
        m2->bsn_udf6, m1->bsn_udf6)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for ip_proto */
    if (!OF_OVERLAP_INT(f1->ip_proto, f2->ip_proto,
        m2->ip_proto, m1->ip_proto)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for bsn_l3_interface_class_id */
    if (!OF_OVERLAP_INT(f1->bsn_l3_interface_class_id, f2->bsn_l3_interface_class_id,
        m2->bsn_l3_interface_class_id, m1->bsn_l3_interface_class_id)) {
        return 0; /* This field differentiates; all done */
    }

    /* Check overlap for ip_dscp */
    if (!OF_OVERLAP_INT(f1->ip_dscp, f2->ip_dscp,
        m2->ip_dscp, m1->ip_dscp)) {
        return 0; /* This field differentiates; all done */
    }

    return 1; /* No field differentiates matches */
}

#endif /* Match header file */
