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
 * \defgroup of_group_stats_entry of_group_stats_entry
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_group_stats_entry_push_wire_values(of_group_stats_entry_t *obj)
{

    obj->wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_group_stats_entry object
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
 * \ingroup of_group_stats_entry
 */

of_group_stats_entry_t *
of_group_stats_entry_new(of_version_t version)
{
    of_group_stats_entry_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_GROUP_STATS_ENTRY] + of_object_extra_len[version][OF_GROUP_STATS_ENTRY];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_group_stats_entry_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_group_stats_entry_init(obj, version, bytes, 0);

    if (of_group_stats_entry_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_group_stats_entry.
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
of_group_stats_entry_init(of_group_stats_entry_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    ASSERT(of_object_fixed_len[version][OF_GROUP_STATS_ENTRY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_GROUP_STATS_ENTRY] + of_object_extra_len[version][OF_GROUP_STATS_ENTRY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_GROUP_STATS_ENTRY;

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
 * Get group_id from an object of type of_group_stats_entry.
 * @param obj Pointer to an object of type of_group_stats_entry.
 * @param group_id Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_group_stats_entry_group_id_get(
    of_group_stats_entry_t *obj,
    uint32_t *group_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_GROUP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
    of_wire_buffer_u32_get(wbuf, abs_offset, group_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set group_id in an object of type of_group_stats_entry.
 * @param obj Pointer to an object of type of_group_stats_entry.
 * @param group_id The value to write into the object
 */
void
of_group_stats_entry_group_id_set(
    of_group_stats_entry_t *obj,
    uint32_t group_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_GROUP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
    of_wire_buffer_u32_set(wbuf, abs_offset, group_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get ref_count from an object of type of_group_stats_entry.
 * @param obj Pointer to an object of type of_group_stats_entry.
 * @param ref_count Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_group_stats_entry_ref_count_get(
    of_group_stats_entry_t *obj,
    uint32_t *ref_count)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_GROUP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
    of_wire_buffer_u32_get(wbuf, abs_offset, ref_count);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set ref_count in an object of type of_group_stats_entry.
 * @param obj Pointer to an object of type of_group_stats_entry.
 * @param ref_count The value to write into the object
 */
void
of_group_stats_entry_ref_count_set(
    of_group_stats_entry_t *obj,
    uint32_t ref_count)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_GROUP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
    of_wire_buffer_u32_set(wbuf, abs_offset, ref_count);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get packet_count from an object of type of_group_stats_entry.
 * @param obj Pointer to an object of type of_group_stats_entry.
 * @param packet_count Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_group_stats_entry_packet_count_get(
    of_group_stats_entry_t *obj,
    uint64_t *packet_count)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_GROUP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
    of_wire_buffer_u64_get(wbuf, abs_offset, packet_count);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set packet_count in an object of type of_group_stats_entry.
 * @param obj Pointer to an object of type of_group_stats_entry.
 * @param packet_count The value to write into the object
 */
void
of_group_stats_entry_packet_count_set(
    of_group_stats_entry_t *obj,
    uint64_t packet_count)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_GROUP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
    of_wire_buffer_u64_set(wbuf, abs_offset, packet_count);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get byte_count from an object of type of_group_stats_entry.
 * @param obj Pointer to an object of type of_group_stats_entry.
 * @param byte_count Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_group_stats_entry_byte_count_get(
    of_group_stats_entry_t *obj,
    uint64_t *byte_count)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_GROUP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
    of_wire_buffer_u64_get(wbuf, abs_offset, byte_count);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set byte_count in an object of type of_group_stats_entry.
 * @param obj Pointer to an object of type of_group_stats_entry.
 * @param byte_count The value to write into the object
 */
void
of_group_stats_entry_byte_count_set(
    of_group_stats_entry_t *obj,
    uint64_t byte_count)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_GROUP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
    of_wire_buffer_u64_set(wbuf, abs_offset, byte_count);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get duration_sec from an object of type of_group_stats_entry.
 * @param obj Pointer to an object of type of_group_stats_entry.
 * @param duration_sec Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_group_stats_entry_duration_sec_get(
    of_group_stats_entry_t *obj,
    uint32_t *duration_sec)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_GROUP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 32;
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
 * Set duration_sec in an object of type of_group_stats_entry.
 * @param obj Pointer to an object of type of_group_stats_entry.
 * @param duration_sec The value to write into the object
 */
void
of_group_stats_entry_duration_sec_set(
    of_group_stats_entry_t *obj,
    uint32_t duration_sec)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_GROUP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 32;
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
 * Get duration_nsec from an object of type of_group_stats_entry.
 * @param obj Pointer to an object of type of_group_stats_entry.
 * @param duration_nsec Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_group_stats_entry_duration_nsec_get(
    of_group_stats_entry_t *obj,
    uint32_t *duration_nsec)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_GROUP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 36;
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
 * Set duration_nsec in an object of type of_group_stats_entry.
 * @param obj Pointer to an object of type of_group_stats_entry.
 * @param duration_nsec The value to write into the object
 */
void
of_group_stats_entry_duration_nsec_set(
    of_group_stats_entry_t *obj,
    uint32_t duration_nsec)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_GROUP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 36;
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
 * Bind an object of type of_list_bucket_counter_t to the parent of type of_group_stats_entry for
 * member bucket_stats
 * @param obj Pointer to an object of type of_group_stats_entry.
 * @param bucket_stats Pointer to the child object of type
 * of_list_bucket_counter_t to be filled out.
 * \ingroup of_group_stats_entry
 *
 * The parameter bucket_stats is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_group_stats_entry_bucket_stats_bind(
    of_group_stats_entry_t *obj,
    of_list_bucket_counter_t *bucket_stats)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    ASSERT(obj->object_id == OF_GROUP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
        offset = 32;
        cur_len = _END_LEN(obj, offset);
        break;
    case OF_VERSION_1_3:
        offset = 40;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_list_bucket_counter_init(bucket_stats, obj->version, 0, 1);
    /* Attach to parent */
    bucket_stats->parent = (of_object_t *)obj;
    bucket_stats->wire_object.wbuf = obj->wire_object.wbuf;
    bucket_stats->wire_object.obj_offset = abs_offset;
    bucket_stats->wire_object.owned = 0;
    bucket_stats->length = cur_len;

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of bucket_stats into a new variable of type of_list_bucket_counter_t from
 * a of_group_stats_entry instance.
 *
 * @param obj Pointer to the source of type of_group_stats_entry_t
 * @returns A pointer to a new instance of type of_list_bucket_counter_t whose contents
 * match that of bucket_stats from source
 * @returns NULL if an error occurs
 */
of_list_bucket_counter_t *
of_group_stats_entry_bucket_stats_get(of_group_stats_entry_t *obj) {
    of_list_bucket_counter_t _bucket_stats;
    of_list_bucket_counter_t *_bucket_stats_ptr;

    of_group_stats_entry_bucket_stats_bind(obj, &_bucket_stats);
    _bucket_stats_ptr = (of_list_bucket_counter_t *)of_object_dup(&_bucket_stats);
    return _bucket_stats_ptr;
}

/**
 * Set bucket_stats in an object of type of_group_stats_entry.
 * @param obj Pointer to an object of type of_group_stats_entry.
 * @param bucket_stats Pointer to the child of type of_list_bucket_counter_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_group_stats_entry_bucket_stats_set(
    of_group_stats_entry_t *obj,
    of_list_bucket_counter_t *bucket_stats)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    ASSERT(obj->object_id == OF_GROUP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
        offset = 32;
        cur_len = _END_LEN(obj, offset);
        break;
    case OF_VERSION_1_3:
        offset = 40;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = bucket_stats->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wire_object.wbuf == bucket_stats->wire_object.wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(bucket_stats, 0));
        /* ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(bucket_stats, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    if (bucket_stats->wire_length_set != NULL) {
        bucket_stats->wire_length_set((of_object_t *)bucket_stats, bucket_stats->length);
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
