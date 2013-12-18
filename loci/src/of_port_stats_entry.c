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
 * \defgroup of_port_stats_entry of_port_stats_entry
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_port_stats_entry_push_wire_values(of_port_stats_entry_t *obj)
{

    return OF_ERROR_NONE;
}

/**
 * Create a new of_port_stats_entry object
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
 * \ingroup of_port_stats_entry
 */

of_port_stats_entry_t *
of_port_stats_entry_new(of_version_t version)
{
    of_port_stats_entry_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_PORT_STATS_ENTRY] + of_object_extra_len[version][OF_PORT_STATS_ENTRY];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_port_stats_entry_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_port_stats_entry_init(obj, version, bytes, 0);

    if (of_port_stats_entry_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_port_stats_entry.
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
of_port_stats_entry_init(of_port_stats_entry_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    ASSERT(of_object_fixed_len[version][OF_PORT_STATS_ENTRY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_PORT_STATS_ENTRY] + of_object_extra_len[version][OF_PORT_STATS_ENTRY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_PORT_STATS_ENTRY;

    /* Set up the object's function pointers */

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get port_no from an object of type of_port_stats_entry.
 * @param obj Pointer to an object of type of_port_stats_entry.
 * @param port_no Pointer to the child object of type
 * of_port_no_t to be filled out.
 *
 */
void
of_port_stats_entry_port_no_get(
    of_port_stats_entry_t *obj,
    of_port_no_t *port_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PORT_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 0;
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 0;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_port_no_get(ver, wbuf, abs_offset, port_no);
    OF_PORT_NO_VALUE_CHECK(*port_no, ver);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set port_no in an object of type of_port_stats_entry.
 * @param obj Pointer to an object of type of_port_stats_entry.
 * @param port_no The value to write into the object
 */
void
of_port_stats_entry_port_no_set(
    of_port_stats_entry_t *obj,
    of_port_no_t port_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PORT_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 0;
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 0;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_port_no_set(ver, wbuf, abs_offset, port_no);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get rx_packets from an object of type of_port_stats_entry.
 * @param obj Pointer to an object of type of_port_stats_entry.
 * @param rx_packets Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_port_stats_entry_rx_packets_get(
    of_port_stats_entry_t *obj,
    uint64_t *rx_packets)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PORT_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, rx_packets);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set rx_packets in an object of type of_port_stats_entry.
 * @param obj Pointer to an object of type of_port_stats_entry.
 * @param rx_packets The value to write into the object
 */
void
of_port_stats_entry_rx_packets_set(
    of_port_stats_entry_t *obj,
    uint64_t rx_packets)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PORT_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, rx_packets);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get tx_packets from an object of type of_port_stats_entry.
 * @param obj Pointer to an object of type of_port_stats_entry.
 * @param tx_packets Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_port_stats_entry_tx_packets_get(
    of_port_stats_entry_t *obj,
    uint64_t *tx_packets)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PORT_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, tx_packets);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set tx_packets in an object of type of_port_stats_entry.
 * @param obj Pointer to an object of type of_port_stats_entry.
 * @param tx_packets The value to write into the object
 */
void
of_port_stats_entry_tx_packets_set(
    of_port_stats_entry_t *obj,
    uint64_t tx_packets)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PORT_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, tx_packets);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get rx_bytes from an object of type of_port_stats_entry.
 * @param obj Pointer to an object of type of_port_stats_entry.
 * @param rx_bytes Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_port_stats_entry_rx_bytes_get(
    of_port_stats_entry_t *obj,
    uint64_t *rx_bytes)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PORT_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 24;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, rx_bytes);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set rx_bytes in an object of type of_port_stats_entry.
 * @param obj Pointer to an object of type of_port_stats_entry.
 * @param rx_bytes The value to write into the object
 */
void
of_port_stats_entry_rx_bytes_set(
    of_port_stats_entry_t *obj,
    uint64_t rx_bytes)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PORT_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 24;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, rx_bytes);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get tx_bytes from an object of type of_port_stats_entry.
 * @param obj Pointer to an object of type of_port_stats_entry.
 * @param tx_bytes Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_port_stats_entry_tx_bytes_get(
    of_port_stats_entry_t *obj,
    uint64_t *tx_bytes)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PORT_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 32;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, tx_bytes);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set tx_bytes in an object of type of_port_stats_entry.
 * @param obj Pointer to an object of type of_port_stats_entry.
 * @param tx_bytes The value to write into the object
 */
void
of_port_stats_entry_tx_bytes_set(
    of_port_stats_entry_t *obj,
    uint64_t tx_bytes)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PORT_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 32;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, tx_bytes);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get rx_dropped from an object of type of_port_stats_entry.
 * @param obj Pointer to an object of type of_port_stats_entry.
 * @param rx_dropped Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_port_stats_entry_rx_dropped_get(
    of_port_stats_entry_t *obj,
    uint64_t *rx_dropped)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PORT_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 40;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, rx_dropped);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set rx_dropped in an object of type of_port_stats_entry.
 * @param obj Pointer to an object of type of_port_stats_entry.
 * @param rx_dropped The value to write into the object
 */
void
of_port_stats_entry_rx_dropped_set(
    of_port_stats_entry_t *obj,
    uint64_t rx_dropped)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PORT_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 40;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, rx_dropped);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get tx_dropped from an object of type of_port_stats_entry.
 * @param obj Pointer to an object of type of_port_stats_entry.
 * @param tx_dropped Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_port_stats_entry_tx_dropped_get(
    of_port_stats_entry_t *obj,
    uint64_t *tx_dropped)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PORT_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 48;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, tx_dropped);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set tx_dropped in an object of type of_port_stats_entry.
 * @param obj Pointer to an object of type of_port_stats_entry.
 * @param tx_dropped The value to write into the object
 */
void
of_port_stats_entry_tx_dropped_set(
    of_port_stats_entry_t *obj,
    uint64_t tx_dropped)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PORT_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 48;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, tx_dropped);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get rx_errors from an object of type of_port_stats_entry.
 * @param obj Pointer to an object of type of_port_stats_entry.
 * @param rx_errors Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_port_stats_entry_rx_errors_get(
    of_port_stats_entry_t *obj,
    uint64_t *rx_errors)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PORT_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 56;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, rx_errors);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set rx_errors in an object of type of_port_stats_entry.
 * @param obj Pointer to an object of type of_port_stats_entry.
 * @param rx_errors The value to write into the object
 */
void
of_port_stats_entry_rx_errors_set(
    of_port_stats_entry_t *obj,
    uint64_t rx_errors)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PORT_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 56;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, rx_errors);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get tx_errors from an object of type of_port_stats_entry.
 * @param obj Pointer to an object of type of_port_stats_entry.
 * @param tx_errors Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_port_stats_entry_tx_errors_get(
    of_port_stats_entry_t *obj,
    uint64_t *tx_errors)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PORT_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 64;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, tx_errors);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set tx_errors in an object of type of_port_stats_entry.
 * @param obj Pointer to an object of type of_port_stats_entry.
 * @param tx_errors The value to write into the object
 */
void
of_port_stats_entry_tx_errors_set(
    of_port_stats_entry_t *obj,
    uint64_t tx_errors)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PORT_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 64;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, tx_errors);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get rx_frame_err from an object of type of_port_stats_entry.
 * @param obj Pointer to an object of type of_port_stats_entry.
 * @param rx_frame_err Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_port_stats_entry_rx_frame_err_get(
    of_port_stats_entry_t *obj,
    uint64_t *rx_frame_err)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PORT_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 72;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, rx_frame_err);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set rx_frame_err in an object of type of_port_stats_entry.
 * @param obj Pointer to an object of type of_port_stats_entry.
 * @param rx_frame_err The value to write into the object
 */
void
of_port_stats_entry_rx_frame_err_set(
    of_port_stats_entry_t *obj,
    uint64_t rx_frame_err)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PORT_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 72;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, rx_frame_err);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get rx_over_err from an object of type of_port_stats_entry.
 * @param obj Pointer to an object of type of_port_stats_entry.
 * @param rx_over_err Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_port_stats_entry_rx_over_err_get(
    of_port_stats_entry_t *obj,
    uint64_t *rx_over_err)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PORT_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 80;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, rx_over_err);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set rx_over_err in an object of type of_port_stats_entry.
 * @param obj Pointer to an object of type of_port_stats_entry.
 * @param rx_over_err The value to write into the object
 */
void
of_port_stats_entry_rx_over_err_set(
    of_port_stats_entry_t *obj,
    uint64_t rx_over_err)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PORT_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 80;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, rx_over_err);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get rx_crc_err from an object of type of_port_stats_entry.
 * @param obj Pointer to an object of type of_port_stats_entry.
 * @param rx_crc_err Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_port_stats_entry_rx_crc_err_get(
    of_port_stats_entry_t *obj,
    uint64_t *rx_crc_err)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PORT_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 88;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, rx_crc_err);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set rx_crc_err in an object of type of_port_stats_entry.
 * @param obj Pointer to an object of type of_port_stats_entry.
 * @param rx_crc_err The value to write into the object
 */
void
of_port_stats_entry_rx_crc_err_set(
    of_port_stats_entry_t *obj,
    uint64_t rx_crc_err)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PORT_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 88;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, rx_crc_err);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get collisions from an object of type of_port_stats_entry.
 * @param obj Pointer to an object of type of_port_stats_entry.
 * @param collisions Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_port_stats_entry_collisions_get(
    of_port_stats_entry_t *obj,
    uint64_t *collisions)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PORT_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 96;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, collisions);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set collisions in an object of type of_port_stats_entry.
 * @param obj Pointer to an object of type of_port_stats_entry.
 * @param collisions The value to write into the object
 */
void
of_port_stats_entry_collisions_set(
    of_port_stats_entry_t *obj,
    uint64_t collisions)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PORT_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 96;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, collisions);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get duration_sec from an object of type of_port_stats_entry.
 * @param obj Pointer to an object of type of_port_stats_entry.
 * @param duration_sec Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_stats_entry_duration_sec_get(
    of_port_stats_entry_t *obj,
    uint32_t *duration_sec)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PORT_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 104;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, duration_sec);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set duration_sec in an object of type of_port_stats_entry.
 * @param obj Pointer to an object of type of_port_stats_entry.
 * @param duration_sec The value to write into the object
 */
void
of_port_stats_entry_duration_sec_set(
    of_port_stats_entry_t *obj,
    uint32_t duration_sec)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PORT_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 104;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, duration_sec);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get duration_nsec from an object of type of_port_stats_entry.
 * @param obj Pointer to an object of type of_port_stats_entry.
 * @param duration_nsec Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_stats_entry_duration_nsec_get(
    of_port_stats_entry_t *obj,
    uint32_t *duration_nsec)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PORT_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 108;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, duration_nsec);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set duration_nsec in an object of type of_port_stats_entry.
 * @param obj Pointer to an object of type of_port_stats_entry.
 * @param duration_nsec The value to write into the object
 */
void
of_port_stats_entry_duration_nsec_set(
    of_port_stats_entry_t *obj,
    uint32_t duration_nsec)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PORT_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 108;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, duration_nsec);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
