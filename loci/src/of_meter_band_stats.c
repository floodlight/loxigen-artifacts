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
 * \defgroup of_meter_band_stats of_meter_band_stats
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_meter_band_stats_push_wire_values(of_meter_band_stats_t *obj)
{

    return OF_ERROR_NONE;
}

/**
 * Create a new of_meter_band_stats object
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
 * \ingroup of_meter_band_stats
 */

of_meter_band_stats_t *
of_meter_band_stats_new(of_version_t version)
{
    of_meter_band_stats_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_METER_BAND_STATS] + of_object_extra_len[version][OF_METER_BAND_STATS];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_meter_band_stats_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_meter_band_stats_init(obj, version, bytes, 0);

    if (of_meter_band_stats_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_meter_band_stats.
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
of_meter_band_stats_init(of_meter_band_stats_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    ASSERT(of_object_fixed_len[version][OF_METER_BAND_STATS] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_METER_BAND_STATS] + of_object_extra_len[version][OF_METER_BAND_STATS];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_METER_BAND_STATS;

    /* Set up the object's function pointers */

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get packet_band_count from an object of type of_meter_band_stats.
 * @param obj Pointer to an object of type of_meter_band_stats.
 * @param packet_band_count Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_meter_band_stats_packet_band_count_get(
    of_meter_band_stats_t *obj,
    uint64_t *packet_band_count)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_METER_BAND_STATS);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 0;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, packet_band_count);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set packet_band_count in an object of type of_meter_band_stats.
 * @param obj Pointer to an object of type of_meter_band_stats.
 * @param packet_band_count The value to write into the object
 */
void
of_meter_band_stats_packet_band_count_set(
    of_meter_band_stats_t *obj,
    uint64_t packet_band_count)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_METER_BAND_STATS);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 0;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, packet_band_count);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get byte_band_count from an object of type of_meter_band_stats.
 * @param obj Pointer to an object of type of_meter_band_stats.
 * @param byte_band_count Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_meter_band_stats_byte_band_count_get(
    of_meter_band_stats_t *obj,
    uint64_t *byte_band_count)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_METER_BAND_STATS);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, byte_band_count);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set byte_band_count in an object of type of_meter_band_stats.
 * @param obj Pointer to an object of type of_meter_band_stats.
 * @param byte_band_count The value to write into the object
 */
void
of_meter_band_stats_byte_band_count_set(
    of_meter_band_stats_t *obj,
    uint64_t byte_band_count)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_METER_BAND_STATS);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, byte_band_count);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
