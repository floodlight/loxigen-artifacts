/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

static void
of_match_v2_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_1:
        *(uint16_t *)(buf + 0) = htobe16(0x0); /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_match_v2 of_match_v2
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_match_v2_push_wire_values(of_match_v2_t *obj)
{

    of_match_v2_push_wire_types(obj);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_match_v2 object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * Use new_from_message to bind an existing message to a message object,
 * or a _get function for non-message objects.
 *
 * \ingroup of_match_v2
 */

of_match_v2_t *
of_match_v2_new(of_version_t version)
{
    of_match_v2_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_MATCH_V2] + of_object_extra_len[version][OF_MATCH_V2];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_match_v2_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_match_v2_init(obj, version, bytes, 0);

    if (of_match_v2_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_match_v2.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_match_v2_init(of_match_v2_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    ASSERT(of_object_fixed_len[version][OF_MATCH_V2] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_MATCH_V2] + of_object_extra_len[version][OF_MATCH_V2];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_MATCH_V2;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_match_v2_push_wire_types;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get in_port from an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param in_port Pointer to the child object of type
 * of_port_no_t to be filled out.
 *
 */
void
of_match_v2_in_port_get(
    of_match_v2_t *obj,
    of_port_no_t *in_port)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 4;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_port_no_get(ver, wbuf, abs_offset, in_port);
    OF_PORT_NO_VALUE_CHECK(*in_port, ver);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set in_port in an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param in_port The value to write into the object
 */
void
of_match_v2_in_port_set(
    of_match_v2_t *obj,
    of_port_no_t in_port)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 4;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_port_no_set(ver, wbuf, abs_offset, in_port);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get wildcards from an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param wildcards Pointer to the child object of type
 * of_wc_bmap_t to be filled out.
 *
 */
void
of_match_v2_wildcards_get(
    of_match_v2_t *obj,
    of_wc_bmap_t *wildcards)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 8;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_wc_bmap_get(ver, wbuf, abs_offset, wildcards);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set wildcards in an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param wildcards The value to write into the object
 */
void
of_match_v2_wildcards_set(
    of_match_v2_t *obj,
    of_wc_bmap_t wildcards)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 8;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_wc_bmap_set(ver, wbuf, abs_offset, wildcards);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get eth_src from an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param eth_src Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_match_v2_eth_src_get(
    of_match_v2_t *obj,
    of_mac_addr_t *eth_src)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 12;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_get(wbuf, abs_offset, eth_src);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set eth_src in an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param eth_src The value to write into the object
 */
void
of_match_v2_eth_src_set(
    of_match_v2_t *obj,
    of_mac_addr_t eth_src)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 12;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_set(wbuf, abs_offset, eth_src);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get eth_src_mask from an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param eth_src_mask Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_match_v2_eth_src_mask_get(
    of_match_v2_t *obj,
    of_mac_addr_t *eth_src_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 18;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_get(wbuf, abs_offset, eth_src_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set eth_src_mask in an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param eth_src_mask The value to write into the object
 */
void
of_match_v2_eth_src_mask_set(
    of_match_v2_t *obj,
    of_mac_addr_t eth_src_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 18;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_set(wbuf, abs_offset, eth_src_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get eth_dst from an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param eth_dst Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_match_v2_eth_dst_get(
    of_match_v2_t *obj,
    of_mac_addr_t *eth_dst)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 24;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_get(wbuf, abs_offset, eth_dst);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set eth_dst in an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param eth_dst The value to write into the object
 */
void
of_match_v2_eth_dst_set(
    of_match_v2_t *obj,
    of_mac_addr_t eth_dst)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 24;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_set(wbuf, abs_offset, eth_dst);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get eth_dst_mask from an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param eth_dst_mask Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_match_v2_eth_dst_mask_get(
    of_match_v2_t *obj,
    of_mac_addr_t *eth_dst_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 30;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_get(wbuf, abs_offset, eth_dst_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set eth_dst_mask in an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param eth_dst_mask The value to write into the object
 */
void
of_match_v2_eth_dst_mask_set(
    of_match_v2_t *obj,
    of_mac_addr_t eth_dst_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 30;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_set(wbuf, abs_offset, eth_dst_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get vlan_vid from an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param vlan_vid Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_match_v2_vlan_vid_get(
    of_match_v2_t *obj,
    uint16_t *vlan_vid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 36;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, vlan_vid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set vlan_vid in an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param vlan_vid The value to write into the object
 */
void
of_match_v2_vlan_vid_set(
    of_match_v2_t *obj,
    uint16_t vlan_vid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 36;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, vlan_vid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get vlan_pcp from an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param vlan_pcp Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_match_v2_vlan_pcp_get(
    of_match_v2_t *obj,
    uint8_t *vlan_pcp)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 38;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, vlan_pcp);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set vlan_pcp in an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param vlan_pcp The value to write into the object
 */
void
of_match_v2_vlan_pcp_set(
    of_match_v2_t *obj,
    uint8_t vlan_pcp)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 38;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, vlan_pcp);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get eth_type from an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param eth_type Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_match_v2_eth_type_get(
    of_match_v2_t *obj,
    uint16_t *eth_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 40;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, eth_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set eth_type in an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param eth_type The value to write into the object
 */
void
of_match_v2_eth_type_set(
    of_match_v2_t *obj,
    uint16_t eth_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 40;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, eth_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get ip_dscp from an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param ip_dscp Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_match_v2_ip_dscp_get(
    of_match_v2_t *obj,
    uint8_t *ip_dscp)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 42;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, ip_dscp);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set ip_dscp in an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param ip_dscp The value to write into the object
 */
void
of_match_v2_ip_dscp_set(
    of_match_v2_t *obj,
    uint8_t ip_dscp)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 42;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, ip_dscp);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get ip_proto from an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param ip_proto Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_match_v2_ip_proto_get(
    of_match_v2_t *obj,
    uint8_t *ip_proto)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 43;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, ip_proto);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set ip_proto in an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param ip_proto The value to write into the object
 */
void
of_match_v2_ip_proto_set(
    of_match_v2_t *obj,
    uint8_t ip_proto)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 43;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, ip_proto);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get ipv4_src from an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param ipv4_src Pointer to the child object of type
 * of_ipv4_t to be filled out.
 *
 */
void
of_match_v2_ipv4_src_get(
    of_match_v2_t *obj,
    of_ipv4_t *ipv4_src)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 44;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv4_get(wbuf, abs_offset, ipv4_src);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set ipv4_src in an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param ipv4_src The value to write into the object
 */
void
of_match_v2_ipv4_src_set(
    of_match_v2_t *obj,
    of_ipv4_t ipv4_src)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 44;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv4_set(wbuf, abs_offset, ipv4_src);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get ipv4_src_mask from an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param ipv4_src_mask Pointer to the child object of type
 * of_ipv4_t to be filled out.
 *
 */
void
of_match_v2_ipv4_src_mask_get(
    of_match_v2_t *obj,
    of_ipv4_t *ipv4_src_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 48;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv4_get(wbuf, abs_offset, ipv4_src_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set ipv4_src_mask in an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param ipv4_src_mask The value to write into the object
 */
void
of_match_v2_ipv4_src_mask_set(
    of_match_v2_t *obj,
    of_ipv4_t ipv4_src_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 48;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv4_set(wbuf, abs_offset, ipv4_src_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get ipv4_dst from an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param ipv4_dst Pointer to the child object of type
 * of_ipv4_t to be filled out.
 *
 */
void
of_match_v2_ipv4_dst_get(
    of_match_v2_t *obj,
    of_ipv4_t *ipv4_dst)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 52;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv4_get(wbuf, abs_offset, ipv4_dst);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set ipv4_dst in an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param ipv4_dst The value to write into the object
 */
void
of_match_v2_ipv4_dst_set(
    of_match_v2_t *obj,
    of_ipv4_t ipv4_dst)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 52;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv4_set(wbuf, abs_offset, ipv4_dst);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get ipv4_dst_mask from an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param ipv4_dst_mask Pointer to the child object of type
 * of_ipv4_t to be filled out.
 *
 */
void
of_match_v2_ipv4_dst_mask_get(
    of_match_v2_t *obj,
    of_ipv4_t *ipv4_dst_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 56;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv4_get(wbuf, abs_offset, ipv4_dst_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set ipv4_dst_mask in an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param ipv4_dst_mask The value to write into the object
 */
void
of_match_v2_ipv4_dst_mask_set(
    of_match_v2_t *obj,
    of_ipv4_t ipv4_dst_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 56;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv4_set(wbuf, abs_offset, ipv4_dst_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get tcp_src from an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param tcp_src Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_match_v2_tcp_src_get(
    of_match_v2_t *obj,
    uint16_t *tcp_src)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 60;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, tcp_src);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set tcp_src in an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param tcp_src The value to write into the object
 */
void
of_match_v2_tcp_src_set(
    of_match_v2_t *obj,
    uint16_t tcp_src)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 60;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, tcp_src);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get tcp_dst from an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param tcp_dst Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_match_v2_tcp_dst_get(
    of_match_v2_t *obj,
    uint16_t *tcp_dst)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 62;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, tcp_dst);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set tcp_dst in an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param tcp_dst The value to write into the object
 */
void
of_match_v2_tcp_dst_set(
    of_match_v2_t *obj,
    uint16_t tcp_dst)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 62;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, tcp_dst);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get mpls_label from an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param mpls_label Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_match_v2_mpls_label_get(
    of_match_v2_t *obj,
    uint32_t *mpls_label)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 64;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, mpls_label);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set mpls_label in an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param mpls_label The value to write into the object
 */
void
of_match_v2_mpls_label_set(
    of_match_v2_t *obj,
    uint32_t mpls_label)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 64;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, mpls_label);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get mpls_tc from an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param mpls_tc Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_match_v2_mpls_tc_get(
    of_match_v2_t *obj,
    uint8_t *mpls_tc)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 68;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, mpls_tc);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set mpls_tc in an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param mpls_tc The value to write into the object
 */
void
of_match_v2_mpls_tc_set(
    of_match_v2_t *obj,
    uint8_t mpls_tc)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 68;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, mpls_tc);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get metadata from an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param metadata Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_match_v2_metadata_get(
    of_match_v2_t *obj,
    uint64_t *metadata)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 72;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, metadata);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set metadata in an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param metadata The value to write into the object
 */
void
of_match_v2_metadata_set(
    of_match_v2_t *obj,
    uint64_t metadata)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 72;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, metadata);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get metadata_mask from an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param metadata_mask Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_match_v2_metadata_mask_get(
    of_match_v2_t *obj,
    uint64_t *metadata_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 80;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, metadata_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set metadata_mask in an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param metadata_mask The value to write into the object
 */
void
of_match_v2_metadata_mask_set(
    of_match_v2_t *obj,
    uint64_t metadata_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 80;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, metadata_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
