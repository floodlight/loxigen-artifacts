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
 * \defgroup of_table_stats_entry of_table_stats_entry
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_table_stats_entry_push_wire_values(of_table_stats_entry_t *obj)
{

    return OF_ERROR_NONE;
}

/**
 * Create a new of_table_stats_entry object
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
 * \ingroup of_table_stats_entry
 */

of_table_stats_entry_t *
of_table_stats_entry_new(of_version_t version)
{
    of_table_stats_entry_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_TABLE_STATS_ENTRY] + of_object_extra_len[version][OF_TABLE_STATS_ENTRY];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_table_stats_entry_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_table_stats_entry_init(obj, version, bytes, 0);

    if (of_table_stats_entry_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_table_stats_entry.
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
of_table_stats_entry_init(of_table_stats_entry_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_TABLE_STATS_ENTRY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_TABLE_STATS_ENTRY] + of_object_extra_len[version][OF_TABLE_STATS_ENTRY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_TABLE_STATS_ENTRY;

    /* Set up the object's function pointers */

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get table_id from an object of type of_table_stats_entry.
 * @param obj Pointer to an object of type of_table_stats_entry.
 * @param table_id Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_table_stats_entry_table_id_get(
    of_table_stats_entry_t *obj,
    uint8_t *table_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_TABLE_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 0;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, table_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set table_id in an object of type of_table_stats_entry.
 * @param obj Pointer to an object of type of_table_stats_entry.
 * @param table_id The value to write into the object
 */
void
of_table_stats_entry_table_id_set(
    of_table_stats_entry_t *obj,
    uint8_t table_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_TABLE_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 0;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, table_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get active_count from an object of type of_table_stats_entry.
 * @param obj Pointer to an object of type of_table_stats_entry.
 * @param active_count Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_table_stats_entry_active_count_get(
    of_table_stats_entry_t *obj,
    uint32_t *active_count)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_TABLE_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 44;
        break;
    case OF_VERSION_1_1:
        offset = 68;
        break;
    case OF_VERSION_1_2:
        offset = 108;
        break;
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, active_count);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set active_count in an object of type of_table_stats_entry.
 * @param obj Pointer to an object of type of_table_stats_entry.
 * @param active_count The value to write into the object
 */
void
of_table_stats_entry_active_count_set(
    of_table_stats_entry_t *obj,
    uint32_t active_count)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_TABLE_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 44;
        break;
    case OF_VERSION_1_1:
        offset = 68;
        break;
    case OF_VERSION_1_2:
        offset = 108;
        break;
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, active_count);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get lookup_count from an object of type of_table_stats_entry.
 * @param obj Pointer to an object of type of_table_stats_entry.
 * @param lookup_count Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_table_stats_entry_lookup_count_get(
    of_table_stats_entry_t *obj,
    uint64_t *lookup_count)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_TABLE_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 48;
        break;
    case OF_VERSION_1_1:
        offset = 72;
        break;
    case OF_VERSION_1_2:
        offset = 112;
        break;
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, lookup_count);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set lookup_count in an object of type of_table_stats_entry.
 * @param obj Pointer to an object of type of_table_stats_entry.
 * @param lookup_count The value to write into the object
 */
void
of_table_stats_entry_lookup_count_set(
    of_table_stats_entry_t *obj,
    uint64_t lookup_count)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_TABLE_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 48;
        break;
    case OF_VERSION_1_1:
        offset = 72;
        break;
    case OF_VERSION_1_2:
        offset = 112;
        break;
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, lookup_count);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get matched_count from an object of type of_table_stats_entry.
 * @param obj Pointer to an object of type of_table_stats_entry.
 * @param matched_count Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_table_stats_entry_matched_count_get(
    of_table_stats_entry_t *obj,
    uint64_t *matched_count)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_TABLE_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 56;
        break;
    case OF_VERSION_1_1:
        offset = 80;
        break;
    case OF_VERSION_1_2:
        offset = 120;
        break;
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, matched_count);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set matched_count in an object of type of_table_stats_entry.
 * @param obj Pointer to an object of type of_table_stats_entry.
 * @param matched_count The value to write into the object
 */
void
of_table_stats_entry_matched_count_set(
    of_table_stats_entry_t *obj,
    uint64_t matched_count)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_TABLE_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 56;
        break;
    case OF_VERSION_1_1:
        offset = 80;
        break;
    case OF_VERSION_1_2:
        offset = 120;
        break;
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, matched_count);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get name from an object of type of_table_stats_entry.
 * @param obj Pointer to an object of type of_table_stats_entry.
 * @param name Pointer to the child object of type
 * of_table_name_t to be filled out.
 *
 */
void
of_table_stats_entry_name_get(
    of_table_stats_entry_t *obj,
    of_table_name_t *name)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_TABLE_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 4;
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_tab_name_get(wbuf, abs_offset, name);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set name in an object of type of_table_stats_entry.
 * @param obj Pointer to an object of type of_table_stats_entry.
 * @param name The value to write into the object
 */
void
of_table_stats_entry_name_set(
    of_table_stats_entry_t *obj,
    of_table_name_t name)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_TABLE_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 4;
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_tab_name_set(wbuf, abs_offset, name);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get match from an object of type of_table_stats_entry.
 * @param obj Pointer to an object of type of_table_stats_entry.
 * @param match Pointer to the child object of type
 * of_match_bmap_t to be filled out.
 *
 */
void
of_table_stats_entry_match_get(
    of_table_stats_entry_t *obj,
    of_match_bmap_t *match)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_TABLE_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 44;
        break;
    case OF_VERSION_1_2:
        offset = 40;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_match_bmap_get(ver, wbuf, abs_offset, match);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set match in an object of type of_table_stats_entry.
 * @param obj Pointer to an object of type of_table_stats_entry.
 * @param match The value to write into the object
 */
void
of_table_stats_entry_match_set(
    of_table_stats_entry_t *obj,
    of_match_bmap_t match)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_TABLE_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 44;
        break;
    case OF_VERSION_1_2:
        offset = 40;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_match_bmap_set(ver, wbuf, abs_offset, match);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get wildcards from an object of type of_table_stats_entry.
 * @param obj Pointer to an object of type of_table_stats_entry.
 * @param wildcards Pointer to the child object of type
 * of_wc_bmap_t to be filled out.
 *
 */
void
of_table_stats_entry_wildcards_get(
    of_table_stats_entry_t *obj,
    of_wc_bmap_t *wildcards)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_TABLE_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 36;
        break;
    case OF_VERSION_1_1:
        offset = 40;
        break;
    case OF_VERSION_1_2:
        offset = 48;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_wc_bmap_get(ver, wbuf, abs_offset, wildcards);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set wildcards in an object of type of_table_stats_entry.
 * @param obj Pointer to an object of type of_table_stats_entry.
 * @param wildcards The value to write into the object
 */
void
of_table_stats_entry_wildcards_set(
    of_table_stats_entry_t *obj,
    of_wc_bmap_t wildcards)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_TABLE_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 36;
        break;
    case OF_VERSION_1_1:
        offset = 40;
        break;
    case OF_VERSION_1_2:
        offset = 48;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_wc_bmap_set(ver, wbuf, abs_offset, wildcards);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get write_actions from an object of type of_table_stats_entry.
 * @param obj Pointer to an object of type of_table_stats_entry.
 * @param write_actions Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_table_stats_entry_write_actions_get(
    of_table_stats_entry_t *obj,
    uint32_t *write_actions)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_TABLE_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 52;
        break;
    case OF_VERSION_1_2:
        offset = 56;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, write_actions);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set write_actions in an object of type of_table_stats_entry.
 * @param obj Pointer to an object of type of_table_stats_entry.
 * @param write_actions The value to write into the object
 */
void
of_table_stats_entry_write_actions_set(
    of_table_stats_entry_t *obj,
    uint32_t write_actions)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_TABLE_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 52;
        break;
    case OF_VERSION_1_2:
        offset = 56;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, write_actions);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get apply_actions from an object of type of_table_stats_entry.
 * @param obj Pointer to an object of type of_table_stats_entry.
 * @param apply_actions Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_table_stats_entry_apply_actions_get(
    of_table_stats_entry_t *obj,
    uint32_t *apply_actions)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_TABLE_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 56;
        break;
    case OF_VERSION_1_2:
        offset = 60;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, apply_actions);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set apply_actions in an object of type of_table_stats_entry.
 * @param obj Pointer to an object of type of_table_stats_entry.
 * @param apply_actions The value to write into the object
 */
void
of_table_stats_entry_apply_actions_set(
    of_table_stats_entry_t *obj,
    uint32_t apply_actions)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_TABLE_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 56;
        break;
    case OF_VERSION_1_2:
        offset = 60;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, apply_actions);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get write_setfields from an object of type of_table_stats_entry.
 * @param obj Pointer to an object of type of_table_stats_entry.
 * @param write_setfields Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_table_stats_entry_write_setfields_get(
    of_table_stats_entry_t *obj,
    uint64_t *write_setfields)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_TABLE_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
        offset = 64;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, write_setfields);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set write_setfields in an object of type of_table_stats_entry.
 * @param obj Pointer to an object of type of_table_stats_entry.
 * @param write_setfields The value to write into the object
 */
void
of_table_stats_entry_write_setfields_set(
    of_table_stats_entry_t *obj,
    uint64_t write_setfields)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_TABLE_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
        offset = 64;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, write_setfields);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get apply_setfields from an object of type of_table_stats_entry.
 * @param obj Pointer to an object of type of_table_stats_entry.
 * @param apply_setfields Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_table_stats_entry_apply_setfields_get(
    of_table_stats_entry_t *obj,
    uint64_t *apply_setfields)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_TABLE_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
        offset = 72;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, apply_setfields);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set apply_setfields in an object of type of_table_stats_entry.
 * @param obj Pointer to an object of type of_table_stats_entry.
 * @param apply_setfields The value to write into the object
 */
void
of_table_stats_entry_apply_setfields_set(
    of_table_stats_entry_t *obj,
    uint64_t apply_setfields)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_TABLE_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
        offset = 72;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, apply_setfields);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get metadata_match from an object of type of_table_stats_entry.
 * @param obj Pointer to an object of type of_table_stats_entry.
 * @param metadata_match Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_table_stats_entry_metadata_match_get(
    of_table_stats_entry_t *obj,
    uint64_t *metadata_match)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_TABLE_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
        offset = 80;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, metadata_match);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set metadata_match in an object of type of_table_stats_entry.
 * @param obj Pointer to an object of type of_table_stats_entry.
 * @param metadata_match The value to write into the object
 */
void
of_table_stats_entry_metadata_match_set(
    of_table_stats_entry_t *obj,
    uint64_t metadata_match)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_TABLE_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
        offset = 80;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, metadata_match);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get metadata_write from an object of type of_table_stats_entry.
 * @param obj Pointer to an object of type of_table_stats_entry.
 * @param metadata_write Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_table_stats_entry_metadata_write_get(
    of_table_stats_entry_t *obj,
    uint64_t *metadata_write)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_TABLE_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
        offset = 88;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, metadata_write);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set metadata_write in an object of type of_table_stats_entry.
 * @param obj Pointer to an object of type of_table_stats_entry.
 * @param metadata_write The value to write into the object
 */
void
of_table_stats_entry_metadata_write_set(
    of_table_stats_entry_t *obj,
    uint64_t metadata_write)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_TABLE_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
        offset = 88;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, metadata_write);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get instructions from an object of type of_table_stats_entry.
 * @param obj Pointer to an object of type of_table_stats_entry.
 * @param instructions Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_table_stats_entry_instructions_get(
    of_table_stats_entry_t *obj,
    uint32_t *instructions)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_TABLE_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 48;
        break;
    case OF_VERSION_1_2:
        offset = 96;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, instructions);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set instructions in an object of type of_table_stats_entry.
 * @param obj Pointer to an object of type of_table_stats_entry.
 * @param instructions The value to write into the object
 */
void
of_table_stats_entry_instructions_set(
    of_table_stats_entry_t *obj,
    uint32_t instructions)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_TABLE_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 48;
        break;
    case OF_VERSION_1_2:
        offset = 96;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, instructions);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get config from an object of type of_table_stats_entry.
 * @param obj Pointer to an object of type of_table_stats_entry.
 * @param config Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_table_stats_entry_config_get(
    of_table_stats_entry_t *obj,
    uint32_t *config)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_TABLE_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 60;
        break;
    case OF_VERSION_1_2:
        offset = 100;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, config);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set config in an object of type of_table_stats_entry.
 * @param obj Pointer to an object of type of_table_stats_entry.
 * @param config The value to write into the object
 */
void
of_table_stats_entry_config_set(
    of_table_stats_entry_t *obj,
    uint32_t config)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_TABLE_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 60;
        break;
    case OF_VERSION_1_2:
        offset = 100;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, config);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get max_entries from an object of type of_table_stats_entry.
 * @param obj Pointer to an object of type of_table_stats_entry.
 * @param max_entries Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_table_stats_entry_max_entries_get(
    of_table_stats_entry_t *obj,
    uint32_t *max_entries)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_TABLE_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 40;
        break;
    case OF_VERSION_1_1:
        offset = 64;
        break;
    case OF_VERSION_1_2:
        offset = 104;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, max_entries);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set max_entries in an object of type of_table_stats_entry.
 * @param obj Pointer to an object of type of_table_stats_entry.
 * @param max_entries The value to write into the object
 */
void
of_table_stats_entry_max_entries_set(
    of_table_stats_entry_t *obj,
    uint32_t max_entries)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_TABLE_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 40;
        break;
    case OF_VERSION_1_1:
        offset = 64;
        break;
    case OF_VERSION_1_2:
        offset = 104;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, max_entries);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
