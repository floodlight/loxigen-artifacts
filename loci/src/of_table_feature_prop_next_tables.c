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
of_table_feature_prop_next_tables_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x2); /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_table_feature_prop_next_tables of_table_feature_prop_next_tables
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_table_feature_prop_next_tables_push_wire_values(of_table_feature_prop_next_tables_t *obj)
{

    of_table_feature_prop_next_tables_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_table_feature_prop_next_tables object
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
 * \ingroup of_table_feature_prop_next_tables
 */

of_table_feature_prop_next_tables_t *
of_table_feature_prop_next_tables_new(of_version_t version)
{
    of_table_feature_prop_next_tables_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_TABLE_FEATURE_PROP_NEXT_TABLES] + of_object_extra_len[version][OF_TABLE_FEATURE_PROP_NEXT_TABLES];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_table_feature_prop_next_tables_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_table_feature_prop_next_tables_init(obj, version, bytes, 0);

    if (of_table_feature_prop_next_tables_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_table_feature_prop_next_tables.
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
of_table_feature_prop_next_tables_init(of_table_feature_prop_next_tables_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    ASSERT(of_object_fixed_len[version][OF_TABLE_FEATURE_PROP_NEXT_TABLES] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_TABLE_FEATURE_PROP_NEXT_TABLES] + of_object_extra_len[version][OF_TABLE_FEATURE_PROP_NEXT_TABLES];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_TABLE_FEATURE_PROP_NEXT_TABLES;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_table_feature_prop_next_tables_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_table_feature_prop_wire_object_id_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Bind an object of type of_list_uint8_t to the parent of type of_table_feature_prop_next_tables for
 * member next_table_ids
 * @param obj Pointer to an object of type of_table_feature_prop_next_tables.
 * @param next_table_ids Pointer to the child object of type
 * of_list_uint8_t to be filled out.
 * \ingroup of_table_feature_prop_next_tables
 *
 * The parameter next_table_ids is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_table_feature_prop_next_tables_next_table_ids_bind(
    of_table_feature_prop_next_tables_t *obj,
    of_list_uint8_t *next_table_ids)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    ASSERT(obj->object_id == OF_TABLE_FEATURE_PROP_NEXT_TABLES);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_list_uint8_init(next_table_ids, obj->version, 0, 1);
    /* Attach to parent */
    next_table_ids->parent = (of_object_t *)obj;
    next_table_ids->wire_object.wbuf = obj->wire_object.wbuf;
    next_table_ids->wire_object.obj_offset = abs_offset;
    next_table_ids->wire_object.owned = 0;
    next_table_ids->length = cur_len;

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of next_table_ids into a new variable of type of_list_uint8_t from
 * a of_table_feature_prop_next_tables instance.
 *
 * @param obj Pointer to the source of type of_table_feature_prop_next_tables_t
 * @returns A pointer to a new instance of type of_list_uint8_t whose contents
 * match that of next_table_ids from source
 * @returns NULL if an error occurs
 */
of_list_uint8_t *
of_table_feature_prop_next_tables_next_table_ids_get(of_table_feature_prop_next_tables_t *obj) {
    of_list_uint8_t _next_table_ids;
    of_list_uint8_t *_next_table_ids_ptr;

    of_table_feature_prop_next_tables_next_table_ids_bind(obj, &_next_table_ids);
    _next_table_ids_ptr = (of_list_uint8_t *)of_object_dup(&_next_table_ids);
    return _next_table_ids_ptr;
}

/**
 * Set next_table_ids in an object of type of_table_feature_prop_next_tables.
 * @param obj Pointer to an object of type of_table_feature_prop_next_tables.
 * @param next_table_ids Pointer to the child of type of_list_uint8_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_table_feature_prop_next_tables_next_table_ids_set(
    of_table_feature_prop_next_tables_t *obj,
    of_list_uint8_t *next_table_ids)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    ASSERT(obj->object_id == OF_TABLE_FEATURE_PROP_NEXT_TABLES);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = next_table_ids->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wire_object.wbuf == next_table_ids->wire_object.wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(next_table_ids, 0));
        /* ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(next_table_ids, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    if (next_table_ids->wire_length_set != NULL) {
        next_table_ids->wire_length_set((of_object_t *)next_table_ids, next_table_ids->length);
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
