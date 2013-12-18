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
 * \defgroup of_bsn_vlan_counter_stats_entry of_bsn_vlan_counter_stats_entry
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_vlan_counter_stats_entry_push_wire_values(of_bsn_vlan_counter_stats_entry_t *obj)
{

    obj->wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_vlan_counter_stats_entry object
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
 * \ingroup of_bsn_vlan_counter_stats_entry
 */

of_bsn_vlan_counter_stats_entry_t *
of_bsn_vlan_counter_stats_entry_new(of_version_t version)
{
    of_bsn_vlan_counter_stats_entry_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_VLAN_COUNTER_STATS_ENTRY] + of_object_extra_len[version][OF_BSN_VLAN_COUNTER_STATS_ENTRY];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_vlan_counter_stats_entry_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_vlan_counter_stats_entry_init(obj, version, bytes, 0);

    if (of_bsn_vlan_counter_stats_entry_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_vlan_counter_stats_entry.
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
of_bsn_vlan_counter_stats_entry_init(of_bsn_vlan_counter_stats_entry_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    ASSERT(of_object_fixed_len[version][OF_BSN_VLAN_COUNTER_STATS_ENTRY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_VLAN_COUNTER_STATS_ENTRY] + of_object_extra_len[version][OF_BSN_VLAN_COUNTER_STATS_ENTRY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_VLAN_COUNTER_STATS_ENTRY;

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
 * Get vlan_vid from an object of type of_bsn_vlan_counter_stats_entry.
 * @param obj Pointer to an object of type of_bsn_vlan_counter_stats_entry.
 * @param vlan_vid Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_vlan_counter_stats_entry_vlan_vid_get(
    of_bsn_vlan_counter_stats_entry_t *obj,
    uint16_t *vlan_vid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_VLAN_COUNTER_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 2;
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
 * Set vlan_vid in an object of type of_bsn_vlan_counter_stats_entry.
 * @param obj Pointer to an object of type of_bsn_vlan_counter_stats_entry.
 * @param vlan_vid The value to write into the object
 */
void
of_bsn_vlan_counter_stats_entry_vlan_vid_set(
    of_bsn_vlan_counter_stats_entry_t *obj,
    uint16_t vlan_vid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_VLAN_COUNTER_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 2;
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
 * Bind an object of type of_list_uint64_t to the parent of type of_bsn_vlan_counter_stats_entry for
 * member values
 * @param obj Pointer to an object of type of_bsn_vlan_counter_stats_entry.
 * @param values Pointer to the child object of type
 * of_list_uint64_t to be filled out.
 * \ingroup of_bsn_vlan_counter_stats_entry
 *
 * The parameter values is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_bsn_vlan_counter_stats_entry_values_bind(
    of_bsn_vlan_counter_stats_entry_t *obj,
    of_list_uint64_t *values)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    ASSERT(obj->object_id == OF_BSN_VLAN_COUNTER_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_list_uint64_init(values, obj->version, 0, 1);
    /* Attach to parent */
    values->parent = (of_object_t *)obj;
    values->wire_object.wbuf = obj->wire_object.wbuf;
    values->wire_object.obj_offset = abs_offset;
    values->wire_object.owned = 0;
    values->length = cur_len;

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of values into a new variable of type of_list_uint64_t from
 * a of_bsn_vlan_counter_stats_entry instance.
 *
 * @param obj Pointer to the source of type of_bsn_vlan_counter_stats_entry_t
 * @returns A pointer to a new instance of type of_list_uint64_t whose contents
 * match that of values from source
 * @returns NULL if an error occurs
 */
of_list_uint64_t *
of_bsn_vlan_counter_stats_entry_values_get(of_bsn_vlan_counter_stats_entry_t *obj) {
    of_list_uint64_t _values;
    of_list_uint64_t *_values_ptr;

    of_bsn_vlan_counter_stats_entry_values_bind(obj, &_values);
    _values_ptr = (of_list_uint64_t *)of_object_dup(&_values);
    return _values_ptr;
}

/**
 * Set values in an object of type of_bsn_vlan_counter_stats_entry.
 * @param obj Pointer to an object of type of_bsn_vlan_counter_stats_entry.
 * @param values Pointer to the child of type of_list_uint64_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_bsn_vlan_counter_stats_entry_values_set(
    of_bsn_vlan_counter_stats_entry_t *obj,
    of_list_uint64_t *values)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    ASSERT(obj->object_id == OF_BSN_VLAN_COUNTER_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = values->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wire_object.wbuf == values->wire_object.wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(values, 0));
        /* ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(values, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    if (values->wire_length_set != NULL) {
        values->wire_length_set((of_object_t *)values, values->length);
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
