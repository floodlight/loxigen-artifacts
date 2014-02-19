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


/**
 * \defgroup of_bsn_lacp_stats_entry of_bsn_lacp_stats_entry
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_lacp_stats_entry_push_wire_values(of_bsn_lacp_stats_entry_t *obj)
{

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_lacp_stats_entry object
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
 * \ingroup of_bsn_lacp_stats_entry
 */

of_bsn_lacp_stats_entry_t *
of_bsn_lacp_stats_entry_new(of_version_t version)
{
    of_bsn_lacp_stats_entry_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_LACP_STATS_ENTRY] + of_object_extra_len[version][OF_BSN_LACP_STATS_ENTRY];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_lacp_stats_entry_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_lacp_stats_entry_init(obj, version, bytes, 0);

    if (of_bsn_lacp_stats_entry_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_lacp_stats_entry.
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
of_bsn_lacp_stats_entry_init(of_bsn_lacp_stats_entry_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_LACP_STATS_ENTRY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_LACP_STATS_ENTRY] + of_object_extra_len[version][OF_BSN_LACP_STATS_ENTRY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_LACP_STATS_ENTRY;

    /* Set up the object's function pointers */

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get port_no from an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param port_no Pointer to the child object of type
 * of_port_no_t to be filled out.
 *
 */
void
of_bsn_lacp_stats_entry_port_no_get(
    of_bsn_lacp_stats_entry_t *obj,
    of_port_no_t *port_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 0;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_port_no_get(ver, wbuf, abs_offset, port_no);
    OF_PORT_NO_VALUE_CHECK(*port_no, ver);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set port_no in an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param port_no The value to write into the object
 */
void
of_bsn_lacp_stats_entry_port_no_set(
    of_bsn_lacp_stats_entry_t *obj,
    of_port_no_t port_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 0;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_port_no_set(ver, wbuf, abs_offset, port_no);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get actor_sys_priority from an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param actor_sys_priority Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_lacp_stats_entry_actor_sys_priority_get(
    of_bsn_lacp_stats_entry_t *obj,
    uint16_t *actor_sys_priority)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, actor_sys_priority);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set actor_sys_priority in an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param actor_sys_priority The value to write into the object
 */
void
of_bsn_lacp_stats_entry_actor_sys_priority_set(
    of_bsn_lacp_stats_entry_t *obj,
    uint16_t actor_sys_priority)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, actor_sys_priority);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get actor_sys_mac from an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param actor_sys_mac Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_bsn_lacp_stats_entry_actor_sys_mac_get(
    of_bsn_lacp_stats_entry_t *obj,
    of_mac_addr_t *actor_sys_mac)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 6;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_get(wbuf, abs_offset, actor_sys_mac);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set actor_sys_mac in an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param actor_sys_mac The value to write into the object
 */
void
of_bsn_lacp_stats_entry_actor_sys_mac_set(
    of_bsn_lacp_stats_entry_t *obj,
    of_mac_addr_t actor_sys_mac)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 6;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_set(wbuf, abs_offset, actor_sys_mac);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get actor_port_priority from an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param actor_port_priority Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_lacp_stats_entry_actor_port_priority_get(
    of_bsn_lacp_stats_entry_t *obj,
    uint16_t *actor_port_priority)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, actor_port_priority);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set actor_port_priority in an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param actor_port_priority The value to write into the object
 */
void
of_bsn_lacp_stats_entry_actor_port_priority_set(
    of_bsn_lacp_stats_entry_t *obj,
    uint16_t actor_port_priority)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, actor_port_priority);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get actor_port_num from an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param actor_port_num Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_lacp_stats_entry_actor_port_num_get(
    of_bsn_lacp_stats_entry_t *obj,
    uint16_t *actor_port_num)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 14;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, actor_port_num);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set actor_port_num in an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param actor_port_num The value to write into the object
 */
void
of_bsn_lacp_stats_entry_actor_port_num_set(
    of_bsn_lacp_stats_entry_t *obj,
    uint16_t actor_port_num)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 14;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, actor_port_num);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get actor_key from an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param actor_key Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_lacp_stats_entry_actor_key_get(
    of_bsn_lacp_stats_entry_t *obj,
    uint16_t *actor_key)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, actor_key);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set actor_key in an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param actor_key The value to write into the object
 */
void
of_bsn_lacp_stats_entry_actor_key_set(
    of_bsn_lacp_stats_entry_t *obj,
    uint16_t actor_key)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, actor_key);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get convergence_status from an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param convergence_status Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_bsn_lacp_stats_entry_convergence_status_get(
    of_bsn_lacp_stats_entry_t *obj,
    uint8_t *convergence_status)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 18;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, convergence_status);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set convergence_status in an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param convergence_status The value to write into the object
 */
void
of_bsn_lacp_stats_entry_convergence_status_set(
    of_bsn_lacp_stats_entry_t *obj,
    uint8_t convergence_status)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 18;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, convergence_status);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get partner_sys_priority from an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param partner_sys_priority Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_lacp_stats_entry_partner_sys_priority_get(
    of_bsn_lacp_stats_entry_t *obj,
    uint16_t *partner_sys_priority)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, partner_sys_priority);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set partner_sys_priority in an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param partner_sys_priority The value to write into the object
 */
void
of_bsn_lacp_stats_entry_partner_sys_priority_set(
    of_bsn_lacp_stats_entry_t *obj,
    uint16_t partner_sys_priority)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, partner_sys_priority);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get partner_sys_mac from an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param partner_sys_mac Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_bsn_lacp_stats_entry_partner_sys_mac_get(
    of_bsn_lacp_stats_entry_t *obj,
    of_mac_addr_t *partner_sys_mac)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 22;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_get(wbuf, abs_offset, partner_sys_mac);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set partner_sys_mac in an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param partner_sys_mac The value to write into the object
 */
void
of_bsn_lacp_stats_entry_partner_sys_mac_set(
    of_bsn_lacp_stats_entry_t *obj,
    of_mac_addr_t partner_sys_mac)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 22;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_set(wbuf, abs_offset, partner_sys_mac);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get partner_port_priority from an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param partner_port_priority Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_lacp_stats_entry_partner_port_priority_get(
    of_bsn_lacp_stats_entry_t *obj,
    uint16_t *partner_port_priority)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 28;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, partner_port_priority);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set partner_port_priority in an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param partner_port_priority The value to write into the object
 */
void
of_bsn_lacp_stats_entry_partner_port_priority_set(
    of_bsn_lacp_stats_entry_t *obj,
    uint16_t partner_port_priority)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 28;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, partner_port_priority);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get partner_port_num from an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param partner_port_num Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_lacp_stats_entry_partner_port_num_get(
    of_bsn_lacp_stats_entry_t *obj,
    uint16_t *partner_port_num)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 30;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, partner_port_num);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set partner_port_num in an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param partner_port_num The value to write into the object
 */
void
of_bsn_lacp_stats_entry_partner_port_num_set(
    of_bsn_lacp_stats_entry_t *obj,
    uint16_t partner_port_num)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 30;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, partner_port_num);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get partner_key from an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param partner_key Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_lacp_stats_entry_partner_key_get(
    of_bsn_lacp_stats_entry_t *obj,
    uint16_t *partner_key)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 32;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, partner_key);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set partner_key in an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param partner_key The value to write into the object
 */
void
of_bsn_lacp_stats_entry_partner_key_set(
    of_bsn_lacp_stats_entry_t *obj,
    uint16_t partner_key)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 32;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, partner_key);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
