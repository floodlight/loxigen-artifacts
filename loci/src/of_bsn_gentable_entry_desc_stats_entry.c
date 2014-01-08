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
 * \defgroup of_bsn_gentable_entry_desc_stats_entry of_bsn_gentable_entry_desc_stats_entry
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_gentable_entry_desc_stats_entry_push_wire_values(of_bsn_gentable_entry_desc_stats_entry_t *obj)
{

    obj->wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_gentable_entry_desc_stats_entry object
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
 * \ingroup of_bsn_gentable_entry_desc_stats_entry
 */

of_bsn_gentable_entry_desc_stats_entry_t *
of_bsn_gentable_entry_desc_stats_entry_new(of_version_t version)
{
    of_bsn_gentable_entry_desc_stats_entry_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_GENTABLE_ENTRY_DESC_STATS_ENTRY] + of_object_extra_len[version][OF_BSN_GENTABLE_ENTRY_DESC_STATS_ENTRY];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_gentable_entry_desc_stats_entry_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_gentable_entry_desc_stats_entry_init(obj, version, bytes, 0);

    if (of_bsn_gentable_entry_desc_stats_entry_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_gentable_entry_desc_stats_entry.
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
of_bsn_gentable_entry_desc_stats_entry_init(of_bsn_gentable_entry_desc_stats_entry_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    ASSERT(of_object_fixed_len[version][OF_BSN_GENTABLE_ENTRY_DESC_STATS_ENTRY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_GENTABLE_ENTRY_DESC_STATS_ENTRY] + of_object_extra_len[version][OF_BSN_GENTABLE_ENTRY_DESC_STATS_ENTRY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_GENTABLE_ENTRY_DESC_STATS_ENTRY;

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
 * Get checksum from an object of type of_bsn_gentable_entry_desc_stats_entry.
 * @param obj Pointer to an object of type of_bsn_gentable_entry_desc_stats_entry.
 * @param checksum Pointer to the child object of type
 * of_checksum_128_t to be filled out.
 *
 */
void
of_bsn_gentable_entry_desc_stats_entry_checksum_get(
    of_bsn_gentable_entry_desc_stats_entry_t *obj,
    of_checksum_128_t *checksum)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_GENTABLE_ENTRY_DESC_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_checksum_128_get(wbuf, abs_offset, checksum);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set checksum in an object of type of_bsn_gentable_entry_desc_stats_entry.
 * @param obj Pointer to an object of type of_bsn_gentable_entry_desc_stats_entry.
 * @param checksum The value to write into the object
 */
void
of_bsn_gentable_entry_desc_stats_entry_checksum_set(
    of_bsn_gentable_entry_desc_stats_entry_t *obj,
    of_checksum_128_t checksum)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_GENTABLE_ENTRY_DESC_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_checksum_128_set(wbuf, abs_offset, checksum);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Bind an object of type of_list_bsn_tlv_t to the parent of type of_bsn_gentable_entry_desc_stats_entry for
 * member key
 * @param obj Pointer to an object of type of_bsn_gentable_entry_desc_stats_entry.
 * @param key Pointer to the child object of type
 * of_list_bsn_tlv_t to be filled out.
 * \ingroup of_bsn_gentable_entry_desc_stats_entry
 *
 * The parameter key is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_bsn_gentable_entry_desc_stats_entry_key_bind(
    of_bsn_gentable_entry_desc_stats_entry_t *obj,
    of_list_bsn_tlv_t *key)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    ASSERT(obj->object_id == OF_BSN_GENTABLE_ENTRY_DESC_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        cur_len = of_object_u16_get(obj, 2);
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_list_bsn_tlv_init(key, obj->version, 0, 1);
    /* Attach to parent */
    key->parent = (of_object_t *)obj;
    key->wire_object.wbuf = obj->wire_object.wbuf;
    key->wire_object.obj_offset = abs_offset;
    key->wire_object.owned = 0;
    key->length = cur_len;

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of key into a new variable of type of_list_bsn_tlv_t from
 * a of_bsn_gentable_entry_desc_stats_entry instance.
 *
 * @param obj Pointer to the source of type of_bsn_gentable_entry_desc_stats_entry_t
 * @returns A pointer to a new instance of type of_list_bsn_tlv_t whose contents
 * match that of key from source
 * @returns NULL if an error occurs
 */
of_list_bsn_tlv_t *
of_bsn_gentable_entry_desc_stats_entry_key_get(of_bsn_gentable_entry_desc_stats_entry_t *obj) {
    of_list_bsn_tlv_t _key;
    of_list_bsn_tlv_t *_key_ptr;

    of_bsn_gentable_entry_desc_stats_entry_key_bind(obj, &_key);
    _key_ptr = (of_list_bsn_tlv_t *)of_object_dup(&_key);
    return _key_ptr;
}

/**
 * Set key in an object of type of_bsn_gentable_entry_desc_stats_entry.
 * @param obj Pointer to an object of type of_bsn_gentable_entry_desc_stats_entry.
 * @param key Pointer to the child of type of_list_bsn_tlv_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_bsn_gentable_entry_desc_stats_entry_key_set(
    of_bsn_gentable_entry_desc_stats_entry_t *obj,
    of_list_bsn_tlv_t *key)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    ASSERT(obj->object_id == OF_BSN_GENTABLE_ENTRY_DESC_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        cur_len = of_object_u16_get(obj, 2);
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = key->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wire_object.wbuf == key->wire_object.wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(key, 0));
        /* ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(key, 0), new_len);

    /* Special case for setting key length */
    of_object_u16_set(obj, 2, key->length);

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
 * Bind an object of type of_list_bsn_tlv_t to the parent of type of_bsn_gentable_entry_desc_stats_entry for
 * member value
 * @param obj Pointer to an object of type of_bsn_gentable_entry_desc_stats_entry.
 * @param value Pointer to the child object of type
 * of_list_bsn_tlv_t to be filled out.
 * \ingroup of_bsn_gentable_entry_desc_stats_entry
 *
 * The parameter value is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_bsn_gentable_entry_desc_stats_entry_value_bind(
    of_bsn_gentable_entry_desc_stats_entry_t *obj,
    of_list_bsn_tlv_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    ASSERT(obj->object_id == OF_BSN_GENTABLE_ENTRY_DESC_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = _BSN_GENTABLE_ENTRY_DESC_STATS_ENTRY_VALUE_OFFSET(obj);
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_list_bsn_tlv_init(value, obj->version, 0, 1);
    /* Attach to parent */
    value->parent = (of_object_t *)obj;
    value->wire_object.wbuf = obj->wire_object.wbuf;
    value->wire_object.obj_offset = abs_offset;
    value->wire_object.owned = 0;
    value->length = cur_len;

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of value into a new variable of type of_list_bsn_tlv_t from
 * a of_bsn_gentable_entry_desc_stats_entry instance.
 *
 * @param obj Pointer to the source of type of_bsn_gentable_entry_desc_stats_entry_t
 * @returns A pointer to a new instance of type of_list_bsn_tlv_t whose contents
 * match that of value from source
 * @returns NULL if an error occurs
 */
of_list_bsn_tlv_t *
of_bsn_gentable_entry_desc_stats_entry_value_get(of_bsn_gentable_entry_desc_stats_entry_t *obj) {
    of_list_bsn_tlv_t _value;
    of_list_bsn_tlv_t *_value_ptr;

    of_bsn_gentable_entry_desc_stats_entry_value_bind(obj, &_value);
    _value_ptr = (of_list_bsn_tlv_t *)of_object_dup(&_value);
    return _value_ptr;
}

/**
 * Set value in an object of type of_bsn_gentable_entry_desc_stats_entry.
 * @param obj Pointer to an object of type of_bsn_gentable_entry_desc_stats_entry.
 * @param value Pointer to the child of type of_list_bsn_tlv_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_bsn_gentable_entry_desc_stats_entry_value_set(
    of_bsn_gentable_entry_desc_stats_entry_t *obj,
    of_list_bsn_tlv_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    ASSERT(obj->object_id == OF_BSN_GENTABLE_ENTRY_DESC_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = _BSN_GENTABLE_ENTRY_DESC_STATS_ENTRY_VALUE_OFFSET(obj);
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = value->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wire_object.wbuf == value->wire_object.wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(value, 0));
        /* ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(value, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    if (value->wire_length_set != NULL) {
        value->wire_length_set((of_object_t *)value, value->length);
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
