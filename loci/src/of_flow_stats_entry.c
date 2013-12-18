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
 * \defgroup of_flow_stats_entry of_flow_stats_entry
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_flow_stats_entry_push_wire_values(of_flow_stats_entry_t *obj)
{

    obj->wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_flow_stats_entry object
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
 * \ingroup of_flow_stats_entry
 */

of_flow_stats_entry_t *
of_flow_stats_entry_new(of_version_t version)
{
    of_flow_stats_entry_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_FLOW_STATS_ENTRY] + of_object_extra_len[version][OF_FLOW_STATS_ENTRY];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_flow_stats_entry_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_flow_stats_entry_init(obj, version, bytes, 0);

    if (of_flow_stats_entry_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    /* Initialize match TLV for 1.2 */
    /* FIXME: Check 1.3 below */
    if ((version == OF_VERSION_1_2) || (version == OF_VERSION_1_3)) {
        of_object_u16_set((of_object_t *)obj, 48 + 2, 4);
    }

    return obj;
}

/**
 * Initialize an object of type of_flow_stats_entry.
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
of_flow_stats_entry_init(of_flow_stats_entry_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    ASSERT(of_object_fixed_len[version][OF_FLOW_STATS_ENTRY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_FLOW_STATS_ENTRY] + of_object_extra_len[version][OF_FLOW_STATS_ENTRY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_FLOW_STATS_ENTRY;

    /* Set up the object's function pointers */

    obj->wire_length_get = of_u16_len_wire_length_get;
    obj->wire_length_set = of_u16_len_wire_length_set;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get table_id from an object of type of_flow_stats_entry.
 * @param obj Pointer to an object of type of_flow_stats_entry.
 * @param table_id Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_flow_stats_entry_table_id_get(
    of_flow_stats_entry_t *obj,
    uint8_t *table_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_FLOW_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 2;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, table_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set table_id in an object of type of_flow_stats_entry.
 * @param obj Pointer to an object of type of_flow_stats_entry.
 * @param table_id The value to write into the object
 */
void
of_flow_stats_entry_table_id_set(
    of_flow_stats_entry_t *obj,
    uint8_t table_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_FLOW_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 2;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, table_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get duration_sec from an object of type of_flow_stats_entry.
 * @param obj Pointer to an object of type of_flow_stats_entry.
 * @param duration_sec Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_flow_stats_entry_duration_sec_get(
    of_flow_stats_entry_t *obj,
    uint32_t *duration_sec)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_FLOW_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 44;
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 4;
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
 * Set duration_sec in an object of type of_flow_stats_entry.
 * @param obj Pointer to an object of type of_flow_stats_entry.
 * @param duration_sec The value to write into the object
 */
void
of_flow_stats_entry_duration_sec_set(
    of_flow_stats_entry_t *obj,
    uint32_t duration_sec)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_FLOW_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 44;
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 4;
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
 * Get duration_nsec from an object of type of_flow_stats_entry.
 * @param obj Pointer to an object of type of_flow_stats_entry.
 * @param duration_nsec Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_flow_stats_entry_duration_nsec_get(
    of_flow_stats_entry_t *obj,
    uint32_t *duration_nsec)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_FLOW_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 48;
        break;
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
    of_wire_buffer_u32_get(wbuf, abs_offset, duration_nsec);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set duration_nsec in an object of type of_flow_stats_entry.
 * @param obj Pointer to an object of type of_flow_stats_entry.
 * @param duration_nsec The value to write into the object
 */
void
of_flow_stats_entry_duration_nsec_set(
    of_flow_stats_entry_t *obj,
    uint32_t duration_nsec)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_FLOW_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 48;
        break;
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
    of_wire_buffer_u32_set(wbuf, abs_offset, duration_nsec);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get priority from an object of type of_flow_stats_entry.
 * @param obj Pointer to an object of type of_flow_stats_entry.
 * @param priority Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_flow_stats_entry_priority_get(
    of_flow_stats_entry_t *obj,
    uint16_t *priority)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_FLOW_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 52;
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 12;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, priority);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set priority in an object of type of_flow_stats_entry.
 * @param obj Pointer to an object of type of_flow_stats_entry.
 * @param priority The value to write into the object
 */
void
of_flow_stats_entry_priority_set(
    of_flow_stats_entry_t *obj,
    uint16_t priority)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_FLOW_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 52;
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 12;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, priority);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get idle_timeout from an object of type of_flow_stats_entry.
 * @param obj Pointer to an object of type of_flow_stats_entry.
 * @param idle_timeout Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_flow_stats_entry_idle_timeout_get(
    of_flow_stats_entry_t *obj,
    uint16_t *idle_timeout)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_FLOW_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 54;
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 14;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, idle_timeout);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set idle_timeout in an object of type of_flow_stats_entry.
 * @param obj Pointer to an object of type of_flow_stats_entry.
 * @param idle_timeout The value to write into the object
 */
void
of_flow_stats_entry_idle_timeout_set(
    of_flow_stats_entry_t *obj,
    uint16_t idle_timeout)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_FLOW_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 54;
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 14;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, idle_timeout);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get hard_timeout from an object of type of_flow_stats_entry.
 * @param obj Pointer to an object of type of_flow_stats_entry.
 * @param hard_timeout Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_flow_stats_entry_hard_timeout_get(
    of_flow_stats_entry_t *obj,
    uint16_t *hard_timeout)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_FLOW_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 56;
        break;
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
    of_wire_buffer_u16_get(wbuf, abs_offset, hard_timeout);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set hard_timeout in an object of type of_flow_stats_entry.
 * @param obj Pointer to an object of type of_flow_stats_entry.
 * @param hard_timeout The value to write into the object
 */
void
of_flow_stats_entry_hard_timeout_set(
    of_flow_stats_entry_t *obj,
    uint16_t hard_timeout)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_FLOW_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 56;
        break;
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
    of_wire_buffer_u16_set(wbuf, abs_offset, hard_timeout);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get flags from an object of type of_flow_stats_entry.
 * @param obj Pointer to an object of type of_flow_stats_entry.
 * @param flags Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_flow_stats_entry_flags_get(
    of_flow_stats_entry_t *obj,
    uint16_t *flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_FLOW_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 18;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set flags in an object of type of_flow_stats_entry.
 * @param obj Pointer to an object of type of_flow_stats_entry.
 * @param flags The value to write into the object
 */
void
of_flow_stats_entry_flags_set(
    of_flow_stats_entry_t *obj,
    uint16_t flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_FLOW_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 18;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get cookie from an object of type of_flow_stats_entry.
 * @param obj Pointer to an object of type of_flow_stats_entry.
 * @param cookie Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_flow_stats_entry_cookie_get(
    of_flow_stats_entry_t *obj,
    uint64_t *cookie)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_FLOW_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 64;
        break;
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
    of_wire_buffer_u64_get(wbuf, abs_offset, cookie);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set cookie in an object of type of_flow_stats_entry.
 * @param obj Pointer to an object of type of_flow_stats_entry.
 * @param cookie The value to write into the object
 */
void
of_flow_stats_entry_cookie_set(
    of_flow_stats_entry_t *obj,
    uint64_t cookie)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_FLOW_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 64;
        break;
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
    of_wire_buffer_u64_set(wbuf, abs_offset, cookie);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get packet_count from an object of type of_flow_stats_entry.
 * @param obj Pointer to an object of type of_flow_stats_entry.
 * @param packet_count Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_flow_stats_entry_packet_count_get(
    of_flow_stats_entry_t *obj,
    uint64_t *packet_count)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_FLOW_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 72;
        break;
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
    of_wire_buffer_u64_get(wbuf, abs_offset, packet_count);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set packet_count in an object of type of_flow_stats_entry.
 * @param obj Pointer to an object of type of_flow_stats_entry.
 * @param packet_count The value to write into the object
 */
void
of_flow_stats_entry_packet_count_set(
    of_flow_stats_entry_t *obj,
    uint64_t packet_count)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_FLOW_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 72;
        break;
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
    of_wire_buffer_u64_set(wbuf, abs_offset, packet_count);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get byte_count from an object of type of_flow_stats_entry.
 * @param obj Pointer to an object of type of_flow_stats_entry.
 * @param byte_count Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_flow_stats_entry_byte_count_get(
    of_flow_stats_entry_t *obj,
    uint64_t *byte_count)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_FLOW_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 80;
        break;
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
    of_wire_buffer_u64_get(wbuf, abs_offset, byte_count);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set byte_count in an object of type of_flow_stats_entry.
 * @param obj Pointer to an object of type of_flow_stats_entry.
 * @param byte_count The value to write into the object
 */
void
of_flow_stats_entry_byte_count_set(
    of_flow_stats_entry_t *obj,
    uint64_t byte_count)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_FLOW_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 80;
        break;
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
    of_wire_buffer_u64_set(wbuf, abs_offset, byte_count);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get match from an object of type of_flow_stats_entry.
 * @param obj Pointer to an object of type of_flow_stats_entry.
 * @param match Pointer to the child object of type
 * of_match_t to be filled out.
 *
 */
int WARN_UNUSED_RESULT
of_flow_stats_entry_match_get(
    of_flow_stats_entry_t *obj,
    of_match_t *match)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    of_octets_t match_octets; /* Serialized string for match */

    ASSERT(obj->object_id == OF_FLOW_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 4;
        cur_len = _WIRE_MATCH_PADDED_LEN(obj, offset);
        break;
    case OF_VERSION_1_1:
        offset = 48;
        cur_len = _WIRE_MATCH_PADDED_LEN(obj, offset);
        break;
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 48;
        cur_len = _WIRE_MATCH_PADDED_LEN(obj, offset);
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    ASSERT(cur_len + abs_offset <= WBUF_CURRENT_BYTES(wbuf));
    match_octets.bytes = cur_len;
    match_octets.data = OF_OBJECT_BUFFER_INDEX(obj, offset);
    OF_TRY(of_match_deserialize(ver, match, &match_octets));

    OF_LENGTH_CHECK_ASSERT(obj);

    return OF_ERROR_NONE;
}

/**
 * Set match in an object of type of_flow_stats_entry.
 * @param obj Pointer to an object of type of_flow_stats_entry.
 * @param match Pointer to the child of type of_match_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_flow_stats_entry_match_set(
    of_flow_stats_entry_t *obj,
    of_match_t *match)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */
    of_octets_t match_octets; /* Serialized string for match */

    ASSERT(obj->object_id == OF_FLOW_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 4;
        cur_len = _WIRE_MATCH_PADDED_LEN(obj, offset);
        break;
    case OF_VERSION_1_1:
        offset = 48;
        cur_len = _WIRE_MATCH_PADDED_LEN(obj, offset);
        break;
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 48;
        cur_len = _WIRE_MATCH_PADDED_LEN(obj, offset);
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Match object */
    OF_TRY(of_match_serialize(ver, match, &match_octets));
    new_len = match_octets.bytes;
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        match_octets.data, new_len);
    /* Free match serialized octets */
    FREE(match_octets.data);

    /* Not scalar, update lengths if needed */
    delta = new_len - cur_len;
    if (delta != 0) {
        /* Update parent(s) */
        of_object_parent_length_update((of_object_t *)obj, delta);
    }

    OF_LENGTH_CHECK_ASSERT(obj);

    return OF_ERROR_NONE;
}

/**
 * Bind an object of type of_list_instruction_t to the parent of type of_flow_stats_entry for
 * member instructions
 * @param obj Pointer to an object of type of_flow_stats_entry.
 * @param instructions Pointer to the child object of type
 * of_list_instruction_t to be filled out.
 * \ingroup of_flow_stats_entry
 *
 * The parameter instructions is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_flow_stats_entry_instructions_bind(
    of_flow_stats_entry_t *obj,
    of_list_instruction_t *instructions)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    ASSERT(obj->object_id == OF_FLOW_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 136;
        cur_len = _END_LEN(obj, offset);
        break;
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = _FLOW_STATS_ENTRY_INSTRUCTIONS_OFFSET(obj);
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_list_instruction_init(instructions, obj->version, 0, 1);
    /* Attach to parent */
    instructions->parent = (of_object_t *)obj;
    instructions->wire_object.wbuf = obj->wire_object.wbuf;
    instructions->wire_object.obj_offset = abs_offset;
    instructions->wire_object.owned = 0;
    instructions->length = cur_len;

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of instructions into a new variable of type of_list_instruction_t from
 * a of_flow_stats_entry instance.
 *
 * @param obj Pointer to the source of type of_flow_stats_entry_t
 * @returns A pointer to a new instance of type of_list_instruction_t whose contents
 * match that of instructions from source
 * @returns NULL if an error occurs
 */
of_list_instruction_t *
of_flow_stats_entry_instructions_get(of_flow_stats_entry_t *obj) {
    of_list_instruction_t _instructions;
    of_list_instruction_t *_instructions_ptr;

    of_flow_stats_entry_instructions_bind(obj, &_instructions);
    _instructions_ptr = (of_list_instruction_t *)of_object_dup(&_instructions);
    return _instructions_ptr;
}

/**
 * Set instructions in an object of type of_flow_stats_entry.
 * @param obj Pointer to an object of type of_flow_stats_entry.
 * @param instructions Pointer to the child of type of_list_instruction_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_flow_stats_entry_instructions_set(
    of_flow_stats_entry_t *obj,
    of_list_instruction_t *instructions)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    ASSERT(obj->object_id == OF_FLOW_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 136;
        cur_len = _END_LEN(obj, offset);
        break;
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = _FLOW_STATS_ENTRY_INSTRUCTIONS_OFFSET(obj);
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = instructions->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wire_object.wbuf == instructions->wire_object.wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(instructions, 0));
        /* ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(instructions, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    if (instructions->wire_length_set != NULL) {
        instructions->wire_length_set((of_object_t *)instructions, instructions->length);
    }

    /* Not scalar, update lengths if needed */
    delta = new_len - cur_len;
    if (delta != 0) {
        /* Update parent(s) */
        of_object_parent_length_update((of_object_t *)obj, delta);
    }

    OF_LENGTH_CHECK_ASSERT(obj);

    return OF_ERROR_NONE;
}

/**
 * Bind an object of type of_list_action_t to the parent of type of_flow_stats_entry for
 * member actions
 * @param obj Pointer to an object of type of_flow_stats_entry.
 * @param actions Pointer to the child object of type
 * of_list_action_t to be filled out.
 * \ingroup of_flow_stats_entry
 *
 * The parameter actions is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_flow_stats_entry_actions_bind(
    of_flow_stats_entry_t *obj,
    of_list_action_t *actions)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    ASSERT(obj->object_id == OF_FLOW_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 88;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_list_action_init(actions, obj->version, 0, 1);
    /* Attach to parent */
    actions->parent = (of_object_t *)obj;
    actions->wire_object.wbuf = obj->wire_object.wbuf;
    actions->wire_object.obj_offset = abs_offset;
    actions->wire_object.owned = 0;
    actions->length = cur_len;

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of actions into a new variable of type of_list_action_t from
 * a of_flow_stats_entry instance.
 *
 * @param obj Pointer to the source of type of_flow_stats_entry_t
 * @returns A pointer to a new instance of type of_list_action_t whose contents
 * match that of actions from source
 * @returns NULL if an error occurs
 */
of_list_action_t *
of_flow_stats_entry_actions_get(of_flow_stats_entry_t *obj) {
    of_list_action_t _actions;
    of_list_action_t *_actions_ptr;

    of_flow_stats_entry_actions_bind(obj, &_actions);
    _actions_ptr = (of_list_action_t *)of_object_dup(&_actions);
    return _actions_ptr;
}

/**
 * Set actions in an object of type of_flow_stats_entry.
 * @param obj Pointer to an object of type of_flow_stats_entry.
 * @param actions Pointer to the child of type of_list_action_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_flow_stats_entry_actions_set(
    of_flow_stats_entry_t *obj,
    of_list_action_t *actions)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    ASSERT(obj->object_id == OF_FLOW_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 88;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = actions->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wire_object.wbuf == actions->wire_object.wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(actions, 0));
        /* ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(actions, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    if (actions->wire_length_set != NULL) {
        actions->wire_length_set((of_object_t *)actions, actions->length);
    }

    /* Not scalar, update lengths if needed */
    delta = new_len - cur_len;
    if (delta != 0) {
        /* Update parent(s) */
        of_object_parent_length_update((of_object_t *)obj, delta);
    }

    OF_LENGTH_CHECK_ASSERT(obj);

    return OF_ERROR_NONE;
}
