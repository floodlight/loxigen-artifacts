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

void
of_bsn_switch_pipeline_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x13; /* type */
        *(uint16_t *)(buf + 8) = U16_HTON(0xffff); /* stats_type */
        *(uint32_t *)(buf + 16) = U32_HTON(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 20) = U32_HTON(0x6); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_switch_pipeline_stats_reply of_bsn_switch_pipeline_stats_reply
 */

/**
 * Create a new of_bsn_switch_pipeline_stats_reply object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_switch_pipeline_stats_reply
 */

of_object_t *
of_bsn_switch_pipeline_stats_reply_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_SWITCH_PIPELINE_STATS_REPLY];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_switch_pipeline_stats_reply_init(obj, version, bytes, 0);
    of_bsn_switch_pipeline_stats_reply_push_wire_types(obj);
    of_object_message_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_switch_pipeline_stats_reply.
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
of_bsn_switch_pipeline_stats_reply_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_SWITCH_PIPELINE_STATS_REPLY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_SWITCH_PIPELINE_STATS_REPLY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_SWITCH_PIPELINE_STATS_REPLY;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_bsn_switch_pipeline_stats_reply.
 * @param obj Pointer to an object of type of_bsn_switch_pipeline_stats_reply.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_switch_pipeline_stats_reply_xid_get(
    of_bsn_switch_pipeline_stats_reply_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SWITCH_PIPELINE_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_bsn_switch_pipeline_stats_reply.
 * @param obj Pointer to an object of type of_bsn_switch_pipeline_stats_reply.
 * @param xid The value to write into the object
 */
void
of_bsn_switch_pipeline_stats_reply_xid_set(
    of_bsn_switch_pipeline_stats_reply_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SWITCH_PIPELINE_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get flags from an object of type of_bsn_switch_pipeline_stats_reply.
 * @param obj Pointer to an object of type of_bsn_switch_pipeline_stats_reply.
 * @param flags Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_switch_pipeline_stats_reply_flags_get(
    of_bsn_switch_pipeline_stats_reply_t *obj,
    uint16_t *flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SWITCH_PIPELINE_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 10;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set flags in an object of type of_bsn_switch_pipeline_stats_reply.
 * @param obj Pointer to an object of type of_bsn_switch_pipeline_stats_reply.
 * @param flags The value to write into the object
 */
void
of_bsn_switch_pipeline_stats_reply_flags_set(
    of_bsn_switch_pipeline_stats_reply_t *obj,
    uint16_t flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SWITCH_PIPELINE_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 10;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_bsn_switch_pipeline_stats_reply.
 * @param obj Pointer to an object of type of_bsn_switch_pipeline_stats_reply.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_switch_pipeline_stats_reply_experimenter_get(
    of_bsn_switch_pipeline_stats_reply_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SWITCH_PIPELINE_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_bsn_switch_pipeline_stats_reply.
 * @param obj Pointer to an object of type of_bsn_switch_pipeline_stats_reply.
 * @param experimenter The value to write into the object
 */
void
of_bsn_switch_pipeline_stats_reply_experimenter_set(
    of_bsn_switch_pipeline_stats_reply_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SWITCH_PIPELINE_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_bsn_switch_pipeline_stats_reply.
 * @param obj Pointer to an object of type of_bsn_switch_pipeline_stats_reply.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_switch_pipeline_stats_reply_subtype_get(
    of_bsn_switch_pipeline_stats_reply_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SWITCH_PIPELINE_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_bsn_switch_pipeline_stats_reply.
 * @param obj Pointer to an object of type of_bsn_switch_pipeline_stats_reply.
 * @param subtype The value to write into the object
 */
void
of_bsn_switch_pipeline_stats_reply_subtype_set(
    of_bsn_switch_pipeline_stats_reply_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SWITCH_PIPELINE_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Bind an object of type of_list_bsn_switch_pipeline_stats_entry_t to the parent of type of_bsn_switch_pipeline_stats_reply for
 * member entries
 * @param obj Pointer to an object of type of_bsn_switch_pipeline_stats_reply.
 * @param entries Pointer to the child object of type
 * of_list_bsn_switch_pipeline_stats_entry_t to be filled out.
 * \ingroup of_bsn_switch_pipeline_stats_reply
 *
 * The parameter entries is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_bsn_switch_pipeline_stats_reply_entries_bind(
    of_bsn_switch_pipeline_stats_reply_t *obj,
    of_list_bsn_switch_pipeline_stats_entry_t *entries)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_BSN_SWITCH_PIPELINE_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 24;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_list_bsn_switch_pipeline_stats_entry_init(entries, obj->version, 0, 1);
    /* Attach to parent */
    of_object_attach(obj, entries, offset, cur_len);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of entries into a new variable of type of_list_bsn_switch_pipeline_stats_entry_t from
 * a of_bsn_switch_pipeline_stats_reply instance.
 *
 * @param obj Pointer to the source of type of_bsn_switch_pipeline_stats_reply_t
 * @returns A pointer to a new instance of type of_list_bsn_switch_pipeline_stats_entry_t whose contents
 * match that of entries from source
 * @returns NULL if an error occurs
 */
of_list_bsn_switch_pipeline_stats_entry_t *
of_bsn_switch_pipeline_stats_reply_entries_get(of_bsn_switch_pipeline_stats_reply_t *obj) {
    of_list_bsn_switch_pipeline_stats_entry_t _entries;
    of_list_bsn_switch_pipeline_stats_entry_t *_entries_ptr;

    of_bsn_switch_pipeline_stats_reply_entries_bind(obj, &_entries);
    _entries_ptr = (of_list_bsn_switch_pipeline_stats_entry_t *)of_object_dup(&_entries);
    return _entries_ptr;
}

/**
 * Set entries in an object of type of_bsn_switch_pipeline_stats_reply.
 * @param obj Pointer to an object of type of_bsn_switch_pipeline_stats_reply.
 * @param entries Pointer to the child of type of_list_bsn_switch_pipeline_stats_entry_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_bsn_switch_pipeline_stats_reply_entries_set(
    of_bsn_switch_pipeline_stats_reply_t *obj,
    of_list_bsn_switch_pipeline_stats_entry_t *entries)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_BSN_SWITCH_PIPELINE_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 24;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = entries->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wbuf == entries->wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(entries, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(entries, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    of_object_wire_length_set((of_object_t *)entries, entries->length);

    /* Not scalar, update lengths if needed */
    delta = new_len - cur_len;
    if (delta != 0) {
        /* Update parent(s) */
        of_object_parent_length_update((of_object_t *)obj, delta);
    }

    OF_LENGTH_CHECK_ASSERT(obj);

    return OF_ERROR_NONE;
}
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

void
of_bsn_switch_pipeline_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x12; /* type */
        *(uint16_t *)(buf + 8) = U16_HTON(0xffff); /* stats_type */
        *(uint32_t *)(buf + 16) = U32_HTON(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 20) = U32_HTON(0x6); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_switch_pipeline_stats_request of_bsn_switch_pipeline_stats_request
 */

/**
 * Create a new of_bsn_switch_pipeline_stats_request object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_switch_pipeline_stats_request
 */

of_object_t *
of_bsn_switch_pipeline_stats_request_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_SWITCH_PIPELINE_STATS_REQUEST];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_switch_pipeline_stats_request_init(obj, version, bytes, 0);
    of_bsn_switch_pipeline_stats_request_push_wire_types(obj);
    of_object_message_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_switch_pipeline_stats_request.
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
of_bsn_switch_pipeline_stats_request_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_SWITCH_PIPELINE_STATS_REQUEST] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_SWITCH_PIPELINE_STATS_REQUEST];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_SWITCH_PIPELINE_STATS_REQUEST;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_bsn_switch_pipeline_stats_request.
 * @param obj Pointer to an object of type of_bsn_switch_pipeline_stats_request.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_switch_pipeline_stats_request_xid_get(
    of_bsn_switch_pipeline_stats_request_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SWITCH_PIPELINE_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_bsn_switch_pipeline_stats_request.
 * @param obj Pointer to an object of type of_bsn_switch_pipeline_stats_request.
 * @param xid The value to write into the object
 */
void
of_bsn_switch_pipeline_stats_request_xid_set(
    of_bsn_switch_pipeline_stats_request_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SWITCH_PIPELINE_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get flags from an object of type of_bsn_switch_pipeline_stats_request.
 * @param obj Pointer to an object of type of_bsn_switch_pipeline_stats_request.
 * @param flags Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_switch_pipeline_stats_request_flags_get(
    of_bsn_switch_pipeline_stats_request_t *obj,
    uint16_t *flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SWITCH_PIPELINE_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 10;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set flags in an object of type of_bsn_switch_pipeline_stats_request.
 * @param obj Pointer to an object of type of_bsn_switch_pipeline_stats_request.
 * @param flags The value to write into the object
 */
void
of_bsn_switch_pipeline_stats_request_flags_set(
    of_bsn_switch_pipeline_stats_request_t *obj,
    uint16_t flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SWITCH_PIPELINE_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 10;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_bsn_switch_pipeline_stats_request.
 * @param obj Pointer to an object of type of_bsn_switch_pipeline_stats_request.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_switch_pipeline_stats_request_experimenter_get(
    of_bsn_switch_pipeline_stats_request_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SWITCH_PIPELINE_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_bsn_switch_pipeline_stats_request.
 * @param obj Pointer to an object of type of_bsn_switch_pipeline_stats_request.
 * @param experimenter The value to write into the object
 */
void
of_bsn_switch_pipeline_stats_request_experimenter_set(
    of_bsn_switch_pipeline_stats_request_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SWITCH_PIPELINE_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_bsn_switch_pipeline_stats_request.
 * @param obj Pointer to an object of type of_bsn_switch_pipeline_stats_request.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_switch_pipeline_stats_request_subtype_get(
    of_bsn_switch_pipeline_stats_request_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SWITCH_PIPELINE_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_bsn_switch_pipeline_stats_request.
 * @param obj Pointer to an object of type of_bsn_switch_pipeline_stats_request.
 * @param subtype The value to write into the object
 */
void
of_bsn_switch_pipeline_stats_request_subtype_set(
    of_bsn_switch_pipeline_stats_request_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SWITCH_PIPELINE_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
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
 * \defgroup of_bsn_table_checksum_stats_entry of_bsn_table_checksum_stats_entry
 */

/**
 * Create a new of_bsn_table_checksum_stats_entry object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_table_checksum_stats_entry
 */

of_object_t *
of_bsn_table_checksum_stats_entry_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TABLE_CHECKSUM_STATS_ENTRY];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_table_checksum_stats_entry_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_bsn_table_checksum_stats_entry.
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
of_bsn_table_checksum_stats_entry_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TABLE_CHECKSUM_STATS_ENTRY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TABLE_CHECKSUM_STATS_ENTRY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TABLE_CHECKSUM_STATS_ENTRY;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get table_id from an object of type of_bsn_table_checksum_stats_entry.
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_entry.
 * @param table_id Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_bsn_table_checksum_stats_entry_table_id_get(
    of_bsn_table_checksum_stats_entry_t *obj,
    uint8_t *table_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
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
 * Set table_id in an object of type of_bsn_table_checksum_stats_entry.
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_entry.
 * @param table_id The value to write into the object
 */
void
of_bsn_table_checksum_stats_entry_table_id_set(
    of_bsn_table_checksum_stats_entry_t *obj,
    uint8_t table_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
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
 * Get checksum from an object of type of_bsn_table_checksum_stats_entry.
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_entry.
 * @param checksum Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_bsn_table_checksum_stats_entry_checksum_get(
    of_bsn_table_checksum_stats_entry_t *obj,
    uint64_t *checksum)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 1;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, checksum);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set checksum in an object of type of_bsn_table_checksum_stats_entry.
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_entry.
 * @param checksum The value to write into the object
 */
void
of_bsn_table_checksum_stats_entry_checksum_set(
    of_bsn_table_checksum_stats_entry_t *obj,
    uint64_t checksum)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 1;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, checksum);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
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

void
of_bsn_table_checksum_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x13; /* type */
        *(uint16_t *)(buf + 8) = U16_HTON(0xffff); /* stats_type */
        *(uint32_t *)(buf + 16) = U32_HTON(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 20) = U32_HTON(0xb); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_table_checksum_stats_reply of_bsn_table_checksum_stats_reply
 */

/**
 * Create a new of_bsn_table_checksum_stats_reply object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_table_checksum_stats_reply
 */

of_object_t *
of_bsn_table_checksum_stats_reply_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TABLE_CHECKSUM_STATS_REPLY];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_table_checksum_stats_reply_init(obj, version, bytes, 0);
    of_bsn_table_checksum_stats_reply_push_wire_types(obj);
    of_object_message_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_table_checksum_stats_reply.
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
of_bsn_table_checksum_stats_reply_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TABLE_CHECKSUM_STATS_REPLY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TABLE_CHECKSUM_STATS_REPLY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TABLE_CHECKSUM_STATS_REPLY;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_bsn_table_checksum_stats_reply.
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_reply.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_table_checksum_stats_reply_xid_get(
    of_bsn_table_checksum_stats_reply_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_bsn_table_checksum_stats_reply.
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_reply.
 * @param xid The value to write into the object
 */
void
of_bsn_table_checksum_stats_reply_xid_set(
    of_bsn_table_checksum_stats_reply_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get flags from an object of type of_bsn_table_checksum_stats_reply.
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_reply.
 * @param flags Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_table_checksum_stats_reply_flags_get(
    of_bsn_table_checksum_stats_reply_t *obj,
    uint16_t *flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 10;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set flags in an object of type of_bsn_table_checksum_stats_reply.
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_reply.
 * @param flags The value to write into the object
 */
void
of_bsn_table_checksum_stats_reply_flags_set(
    of_bsn_table_checksum_stats_reply_t *obj,
    uint16_t flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 10;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_bsn_table_checksum_stats_reply.
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_reply.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_table_checksum_stats_reply_experimenter_get(
    of_bsn_table_checksum_stats_reply_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_bsn_table_checksum_stats_reply.
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_reply.
 * @param experimenter The value to write into the object
 */
void
of_bsn_table_checksum_stats_reply_experimenter_set(
    of_bsn_table_checksum_stats_reply_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_bsn_table_checksum_stats_reply.
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_reply.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_table_checksum_stats_reply_subtype_get(
    of_bsn_table_checksum_stats_reply_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_bsn_table_checksum_stats_reply.
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_reply.
 * @param subtype The value to write into the object
 */
void
of_bsn_table_checksum_stats_reply_subtype_set(
    of_bsn_table_checksum_stats_reply_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Bind an object of type of_list_bsn_table_checksum_stats_entry_t to the parent of type of_bsn_table_checksum_stats_reply for
 * member entries
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_reply.
 * @param entries Pointer to the child object of type
 * of_list_bsn_table_checksum_stats_entry_t to be filled out.
 * \ingroup of_bsn_table_checksum_stats_reply
 *
 * The parameter entries is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_bsn_table_checksum_stats_reply_entries_bind(
    of_bsn_table_checksum_stats_reply_t *obj,
    of_list_bsn_table_checksum_stats_entry_t *entries)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 24;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_list_bsn_table_checksum_stats_entry_init(entries, obj->version, 0, 1);
    /* Attach to parent */
    of_object_attach(obj, entries, offset, cur_len);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of entries into a new variable of type of_list_bsn_table_checksum_stats_entry_t from
 * a of_bsn_table_checksum_stats_reply instance.
 *
 * @param obj Pointer to the source of type of_bsn_table_checksum_stats_reply_t
 * @returns A pointer to a new instance of type of_list_bsn_table_checksum_stats_entry_t whose contents
 * match that of entries from source
 * @returns NULL if an error occurs
 */
of_list_bsn_table_checksum_stats_entry_t *
of_bsn_table_checksum_stats_reply_entries_get(of_bsn_table_checksum_stats_reply_t *obj) {
    of_list_bsn_table_checksum_stats_entry_t _entries;
    of_list_bsn_table_checksum_stats_entry_t *_entries_ptr;

    of_bsn_table_checksum_stats_reply_entries_bind(obj, &_entries);
    _entries_ptr = (of_list_bsn_table_checksum_stats_entry_t *)of_object_dup(&_entries);
    return _entries_ptr;
}

/**
 * Set entries in an object of type of_bsn_table_checksum_stats_reply.
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_reply.
 * @param entries Pointer to the child of type of_list_bsn_table_checksum_stats_entry_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_bsn_table_checksum_stats_reply_entries_set(
    of_bsn_table_checksum_stats_reply_t *obj,
    of_list_bsn_table_checksum_stats_entry_t *entries)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 24;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = entries->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wbuf == entries->wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(entries, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(entries, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    of_object_wire_length_set((of_object_t *)entries, entries->length);

    /* Not scalar, update lengths if needed */
    delta = new_len - cur_len;
    if (delta != 0) {
        /* Update parent(s) */
        of_object_parent_length_update((of_object_t *)obj, delta);
    }

    OF_LENGTH_CHECK_ASSERT(obj);

    return OF_ERROR_NONE;
}
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

void
of_bsn_table_checksum_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x12; /* type */
        *(uint16_t *)(buf + 8) = U16_HTON(0xffff); /* stats_type */
        *(uint32_t *)(buf + 16) = U32_HTON(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 20) = U32_HTON(0xb); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_table_checksum_stats_request of_bsn_table_checksum_stats_request
 */

/**
 * Create a new of_bsn_table_checksum_stats_request object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_table_checksum_stats_request
 */

of_object_t *
of_bsn_table_checksum_stats_request_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TABLE_CHECKSUM_STATS_REQUEST];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_table_checksum_stats_request_init(obj, version, bytes, 0);
    of_bsn_table_checksum_stats_request_push_wire_types(obj);
    of_object_message_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_table_checksum_stats_request.
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
of_bsn_table_checksum_stats_request_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TABLE_CHECKSUM_STATS_REQUEST] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TABLE_CHECKSUM_STATS_REQUEST];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TABLE_CHECKSUM_STATS_REQUEST;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_bsn_table_checksum_stats_request.
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_request.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_table_checksum_stats_request_xid_get(
    of_bsn_table_checksum_stats_request_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_bsn_table_checksum_stats_request.
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_request.
 * @param xid The value to write into the object
 */
void
of_bsn_table_checksum_stats_request_xid_set(
    of_bsn_table_checksum_stats_request_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get flags from an object of type of_bsn_table_checksum_stats_request.
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_request.
 * @param flags Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_table_checksum_stats_request_flags_get(
    of_bsn_table_checksum_stats_request_t *obj,
    uint16_t *flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 10;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set flags in an object of type of_bsn_table_checksum_stats_request.
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_request.
 * @param flags The value to write into the object
 */
void
of_bsn_table_checksum_stats_request_flags_set(
    of_bsn_table_checksum_stats_request_t *obj,
    uint16_t flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 10;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_bsn_table_checksum_stats_request.
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_request.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_table_checksum_stats_request_experimenter_get(
    of_bsn_table_checksum_stats_request_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_bsn_table_checksum_stats_request.
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_request.
 * @param experimenter The value to write into the object
 */
void
of_bsn_table_checksum_stats_request_experimenter_set(
    of_bsn_table_checksum_stats_request_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_bsn_table_checksum_stats_request.
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_request.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_table_checksum_stats_request_subtype_get(
    of_bsn_table_checksum_stats_request_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_bsn_table_checksum_stats_request.
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_request.
 * @param subtype The value to write into the object
 */
void
of_bsn_table_checksum_stats_request_subtype_set(
    of_bsn_table_checksum_stats_request_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
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

void
of_bsn_table_set_buckets_size_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = U32_HTON(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = U32_HTON(0x3d); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_table_set_buckets_size of_bsn_table_set_buckets_size
 */

/**
 * Create a new of_bsn_table_set_buckets_size object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_table_set_buckets_size
 */

of_object_t *
of_bsn_table_set_buckets_size_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TABLE_SET_BUCKETS_SIZE];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_table_set_buckets_size_init(obj, version, bytes, 0);
    of_bsn_table_set_buckets_size_push_wire_types(obj);
    of_object_message_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_table_set_buckets_size.
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
of_bsn_table_set_buckets_size_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TABLE_SET_BUCKETS_SIZE] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TABLE_SET_BUCKETS_SIZE];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TABLE_SET_BUCKETS_SIZE;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_bsn_table_set_buckets_size.
 * @param obj Pointer to an object of type of_bsn_table_set_buckets_size.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_table_set_buckets_size_xid_get(
    of_bsn_table_set_buckets_size_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_SET_BUCKETS_SIZE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_bsn_table_set_buckets_size.
 * @param obj Pointer to an object of type of_bsn_table_set_buckets_size.
 * @param xid The value to write into the object
 */
void
of_bsn_table_set_buckets_size_xid_set(
    of_bsn_table_set_buckets_size_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_SET_BUCKETS_SIZE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_bsn_table_set_buckets_size.
 * @param obj Pointer to an object of type of_bsn_table_set_buckets_size.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_table_set_buckets_size_experimenter_get(
    of_bsn_table_set_buckets_size_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_SET_BUCKETS_SIZE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_bsn_table_set_buckets_size.
 * @param obj Pointer to an object of type of_bsn_table_set_buckets_size.
 * @param experimenter The value to write into the object
 */
void
of_bsn_table_set_buckets_size_experimenter_set(
    of_bsn_table_set_buckets_size_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_SET_BUCKETS_SIZE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_bsn_table_set_buckets_size.
 * @param obj Pointer to an object of type of_bsn_table_set_buckets_size.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_table_set_buckets_size_subtype_get(
    of_bsn_table_set_buckets_size_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_SET_BUCKETS_SIZE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_bsn_table_set_buckets_size.
 * @param obj Pointer to an object of type of_bsn_table_set_buckets_size.
 * @param subtype The value to write into the object
 */
void
of_bsn_table_set_buckets_size_subtype_set(
    of_bsn_table_set_buckets_size_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_SET_BUCKETS_SIZE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get table_id from an object of type of_bsn_table_set_buckets_size.
 * @param obj Pointer to an object of type of_bsn_table_set_buckets_size.
 * @param table_id Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_bsn_table_set_buckets_size_table_id_get(
    of_bsn_table_set_buckets_size_t *obj,
    uint8_t *table_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_SET_BUCKETS_SIZE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 17;
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
 * Set table_id in an object of type of_bsn_table_set_buckets_size.
 * @param obj Pointer to an object of type of_bsn_table_set_buckets_size.
 * @param table_id The value to write into the object
 */
void
of_bsn_table_set_buckets_size_table_id_set(
    of_bsn_table_set_buckets_size_t *obj,
    uint8_t table_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_SET_BUCKETS_SIZE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 17;
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
 * Get buckets_size from an object of type of_bsn_table_set_buckets_size.
 * @param obj Pointer to an object of type of_bsn_table_set_buckets_size.
 * @param buckets_size Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_table_set_buckets_size_buckets_size_get(
    of_bsn_table_set_buckets_size_t *obj,
    uint32_t *buckets_size)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_SET_BUCKETS_SIZE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, buckets_size);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set buckets_size in an object of type of_bsn_table_set_buckets_size.
 * @param obj Pointer to an object of type of_bsn_table_set_buckets_size.
 * @param buckets_size The value to write into the object
 */
void
of_bsn_table_set_buckets_size_buckets_size_set(
    of_bsn_table_set_buckets_size_t *obj,
    uint32_t buckets_size)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_SET_BUCKETS_SIZE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, buckets_size);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
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

void
of_bsn_time_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = U32_HTON(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = U32_HTON(0x2d); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_time_reply of_bsn_time_reply
 */

/**
 * Create a new of_bsn_time_reply object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_time_reply
 */

of_object_t *
of_bsn_time_reply_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TIME_REPLY];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_time_reply_init(obj, version, bytes, 0);
    of_bsn_time_reply_push_wire_types(obj);
    of_object_message_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_time_reply.
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
of_bsn_time_reply_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TIME_REPLY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TIME_REPLY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TIME_REPLY;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_bsn_time_reply.
 * @param obj Pointer to an object of type of_bsn_time_reply.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_time_reply_xid_get(
    of_bsn_time_reply_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TIME_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_bsn_time_reply.
 * @param obj Pointer to an object of type of_bsn_time_reply.
 * @param xid The value to write into the object
 */
void
of_bsn_time_reply_xid_set(
    of_bsn_time_reply_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TIME_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_bsn_time_reply.
 * @param obj Pointer to an object of type of_bsn_time_reply.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_time_reply_experimenter_get(
    of_bsn_time_reply_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TIME_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_bsn_time_reply.
 * @param obj Pointer to an object of type of_bsn_time_reply.
 * @param experimenter The value to write into the object
 */
void
of_bsn_time_reply_experimenter_set(
    of_bsn_time_reply_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TIME_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_bsn_time_reply.
 * @param obj Pointer to an object of type of_bsn_time_reply.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_time_reply_subtype_get(
    of_bsn_time_reply_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TIME_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_bsn_time_reply.
 * @param obj Pointer to an object of type of_bsn_time_reply.
 * @param subtype The value to write into the object
 */
void
of_bsn_time_reply_subtype_set(
    of_bsn_time_reply_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TIME_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get time_ms from an object of type of_bsn_time_reply.
 * @param obj Pointer to an object of type of_bsn_time_reply.
 * @param time_ms Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_bsn_time_reply_time_ms_get(
    of_bsn_time_reply_t *obj,
    uint64_t *time_ms)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TIME_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, time_ms);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set time_ms in an object of type of_bsn_time_reply.
 * @param obj Pointer to an object of type of_bsn_time_reply.
 * @param time_ms The value to write into the object
 */
void
of_bsn_time_reply_time_ms_set(
    of_bsn_time_reply_t *obj,
    uint64_t time_ms)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TIME_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, time_ms);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
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

void
of_bsn_time_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = U32_HTON(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = U32_HTON(0x2c); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_time_request of_bsn_time_request
 */

/**
 * Create a new of_bsn_time_request object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_time_request
 */

of_object_t *
of_bsn_time_request_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TIME_REQUEST];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_time_request_init(obj, version, bytes, 0);
    of_bsn_time_request_push_wire_types(obj);
    of_object_message_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_time_request.
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
of_bsn_time_request_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TIME_REQUEST] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TIME_REQUEST];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TIME_REQUEST;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_bsn_time_request.
 * @param obj Pointer to an object of type of_bsn_time_request.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_time_request_xid_get(
    of_bsn_time_request_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TIME_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_bsn_time_request.
 * @param obj Pointer to an object of type of_bsn_time_request.
 * @param xid The value to write into the object
 */
void
of_bsn_time_request_xid_set(
    of_bsn_time_request_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TIME_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_bsn_time_request.
 * @param obj Pointer to an object of type of_bsn_time_request.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_time_request_experimenter_get(
    of_bsn_time_request_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TIME_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_bsn_time_request.
 * @param obj Pointer to an object of type of_bsn_time_request.
 * @param experimenter The value to write into the object
 */
void
of_bsn_time_request_experimenter_set(
    of_bsn_time_request_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TIME_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_bsn_time_request.
 * @param obj Pointer to an object of type of_bsn_time_request.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_time_request_subtype_get(
    of_bsn_time_request_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TIME_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_bsn_time_request.
 * @param obj Pointer to an object of type of_bsn_time_request.
 * @param subtype The value to write into the object
 */
void
of_bsn_time_request_subtype_set(
    of_bsn_time_request_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TIME_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
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


void
of_bsn_tlv_wire_object_id_get(of_object_t *obj, of_object_id_t *id)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3: {
        uint16_t value = U16_NTOH(*(uint16_t *)(buf + 0)); /* type */
        switch (value) {
        case 0x0:
            *id = OF_BSN_TLV_PORT;
            break;
        case 0x1:
            *id = OF_BSN_TLV_MAC;
            break;
        case 0x2:
            *id = OF_BSN_TLV_RX_PACKETS;
            break;
        case 0x3:
            *id = OF_BSN_TLV_TX_PACKETS;
            break;
        case 0x4:
            *id = OF_BSN_TLV_IPV4;
            break;
        case 0x5:
            *id = OF_BSN_TLV_IDLE_TIME;
            break;
        case 0x6:
            *id = OF_BSN_TLV_VLAN_VID;
            break;
        case 0x7:
            *id = OF_BSN_TLV_IDLE_NOTIFICATION;
            break;
        case 0x8:
            *id = OF_BSN_TLV_IDLE_TIMEOUT;
            break;
        case 0x9:
            *id = OF_BSN_TLV_UNICAST_QUERY_TIMEOUT;
            break;
        case 0xa:
            *id = OF_BSN_TLV_BROADCAST_QUERY_TIMEOUT;
            break;
        case 0xb:
            *id = OF_BSN_TLV_REQUEST_PACKETS;
            break;
        case 0xc:
            *id = OF_BSN_TLV_REPLY_PACKETS;
            break;
        case 0xd:
            *id = OF_BSN_TLV_MISS_PACKETS;
            break;
        case 0xe:
            *id = OF_BSN_TLV_CIRCUIT_ID;
            break;
        case 0xf:
            *id = OF_BSN_TLV_UDF_ID;
            break;
        case 0x10:
            *id = OF_BSN_TLV_UDF_ANCHOR;
            break;
        case 0x11:
            *id = OF_BSN_TLV_UDF_OFFSET;
            break;
        case 0x12:
            *id = OF_BSN_TLV_UDF_LENGTH;
            break;
        case 0x13:
            *id = OF_BSN_TLV_VRF;
            break;
        case 0x14:
            *id = OF_BSN_TLV_QUEUE_ID;
            break;
        case 0x15:
            *id = OF_BSN_TLV_QUEUE_WEIGHT;
            break;
        case 0x16:
            *id = OF_BSN_TLV_CRC_ENABLED;
            break;
        case 0x17:
            *id = OF_BSN_TLV_EXTERNAL_IP;
            break;
        case 0x18:
            *id = OF_BSN_TLV_EXTERNAL_MAC;
            break;
        case 0x19:
            *id = OF_BSN_TLV_EXTERNAL_NETMASK;
            break;
        case 0x1a:
            *id = OF_BSN_TLV_EXTERNAL_GATEWAY_IP;
            break;
        case 0x1b:
            *id = OF_BSN_TLV_INTERNAL_MAC;
            break;
        case 0x1c:
            *id = OF_BSN_TLV_INTERNAL_GATEWAY_MAC;
            break;
        case 0x1d:
            *id = OF_BSN_TLV_EXTERNAL_GATEWAY_MAC;
            break;
        case 0x1e:
            *id = OF_BSN_TLV_SAMPLING_RATE;
            break;
        case 0x1f:
            *id = OF_BSN_TLV_HEADER_SIZE;
            break;
        case 0x20:
            *id = OF_BSN_TLV_ETH_SRC;
            break;
        case 0x21:
            *id = OF_BSN_TLV_ETH_DST;
            break;
        case 0x22:
            *id = OF_BSN_TLV_IPV4_SRC;
            break;
        case 0x23:
            *id = OF_BSN_TLV_IPV4_DST;
            break;
        case 0x24:
            *id = OF_BSN_TLV_UDP_SRC;
            break;
        case 0x25:
            *id = OF_BSN_TLV_UDP_DST;
            break;
        case 0x26:
            *id = OF_BSN_TLV_SUB_AGENT_ID;
            break;
        case 0x27:
            *id = OF_BSN_TLV_TX_BYTES;
            break;
        case 0x28:
            *id = OF_BSN_TLV_ACTOR_SYSTEM_PRIORITY;
            break;
        case 0x29:
            *id = OF_BSN_TLV_ACTOR_SYSTEM_MAC;
            break;
        case 0x2a:
            *id = OF_BSN_TLV_ACTOR_PORT_PRIORITY;
            break;
        case 0x2b:
            *id = OF_BSN_TLV_ACTOR_PORT_NUM;
            break;
        case 0x2c:
            *id = OF_BSN_TLV_ACTOR_KEY;
            break;
        case 0x2d:
            *id = OF_BSN_TLV_CONVERGENCE_STATUS;
            break;
        case 0x2f:
            *id = OF_BSN_TLV_PARTNER_SYSTEM_PRIORITY;
            break;
        case 0x30:
            *id = OF_BSN_TLV_PARTNER_SYSTEM_MAC;
            break;
        case 0x31:
            *id = OF_BSN_TLV_PARTNER_PORT_PRIORITY;
            break;
        case 0x32:
            *id = OF_BSN_TLV_PARTNER_PORT_NUM;
            break;
        case 0x33:
            *id = OF_BSN_TLV_PARTNER_KEY;
            break;
        case 0x34:
            *id = OF_BSN_TLV_NAME;
            break;
        case 0x35:
            *id = OF_BSN_TLV_ACTOR_STATE;
            break;
        case 0x36:
            *id = OF_BSN_TLV_PARTNER_STATE;
            break;
        case 0x37:
            *id = OF_BSN_TLV_DATA;
            break;
        case 0x38:
            *id = OF_BSN_TLV_MAC_MASK;
            break;
        case 0x39:
            *id = OF_BSN_TLV_PRIORITY;
            break;
        case 0x3a:
            *id = OF_BSN_TLV_INTERVAL;
            break;
        case 0x3b:
            *id = OF_BSN_TLV_REFERENCE;
            break;
        case 0x3c:
            *id = OF_BSN_TLV_IPV4_NETMASK;
            break;
        case 0x3d:
            *id = OF_BSN_TLV_MPLS_LABEL;
            break;
        case 0x3e:
            *id = OF_BSN_TLV_MPLS_CONTROL_WORD;
            break;
        case 0x3f:
            *id = OF_BSN_TLV_MPLS_SEQUENCED;
            break;
        case 0x40:
            *id = OF_BSN_TLV_BUCKET;
            break;
        case 0x41:
            *id = OF_BSN_TLV_TCP_SRC;
            break;
        case 0x42:
            *id = OF_BSN_TLV_TCP_DST;
            break;
        case 0x43:
            *id = OF_BSN_TLV_IP_PROTO;
            break;
        case 0x44:
            *id = OF_BSN_TLV_ICMP_TYPE;
            break;
        case 0x45:
            *id = OF_BSN_TLV_ICMP_CODE;
            break;
        case 0x46:
            *id = OF_BSN_TLV_ICMP_ID;
            break;
        case 0x47:
            *id = OF_BSN_TLV_RX_BYTES;
            break;
        case 0x48:
            *id = OF_BSN_TLV_VLAN_PCP;
            break;
        case 0x49:
            *id = OF_BSN_TLV_STRIP_VLAN_ON_EGRESS;
            break;
        case 0x4a:
            *id = OF_BSN_TLV_SET_LOOPBACK_MODE;
            break;
        case 0x4b:
            *id = OF_BSN_TLV_STRIP_MPLS_L2_ON_INGRESS;
            break;
        case 0x4c:
            *id = OF_BSN_TLV_STRIP_MPLS_L3_ON_INGRESS;
            break;
        case 0x4d:
            *id = OF_BSN_TLV_VLAN_VID_MASK;
            break;
        case 0x4e:
            *id = OF_BSN_TLV_IGMP_SNOOPING;
            break;
        case 0x4f:
            *id = OF_BSN_TLV_L2_MULTICAST_LOOKUP;
            break;
        case 0x50:
            *id = OF_BSN_TLV_GENERATION_ID;
            break;
        case 0x51:
            *id = OF_BSN_TLV_ANCHOR;
            break;
        case 0x52:
            *id = OF_BSN_TLV_OFFSET;
            break;
        case 0x53:
            *id = OF_BSN_TLV_NEGATE;
            break;
        case 0x54:
            *id = OF_BSN_TLV_IPV6;
            break;
        case 0x55:
            *id = OF_BSN_TLV_DECAP;
            break;
        case 0x56:
            *id = OF_BSN_TLV_VNI;
            break;
        case 0x57:
            *id = OF_BSN_TLV_MCG_TYPE_VXLAN;
            break;
        case 0x58:
            *id = OF_BSN_TLV_PORT_VXLAN_MODE;
            break;
        case 0x59:
            *id = OF_BSN_TLV_RATE_UNIT;
            break;
        case 0x5a:
            *id = OF_BSN_TLV_BROADCAST_RATE;
            break;
        case 0x5b:
            *id = OF_BSN_TLV_KNOWN_MULTICAST_RATE;
            break;
        case 0x5c:
            *id = OF_BSN_TLV_UNKNOWN_MULTICAST_RATE;
            break;
        case 0x5d:
            *id = OF_BSN_TLV_UNICAST_RATE;
            break;
        case 0x5e:
            *id = OF_BSN_TLV_NEXTHOP_TYPE_VXLAN;
            break;
        case 0x5f:
            *id = OF_BSN_TLV_MULTICAST_INTERFACE_ID;
            break;
        case 0x60:
            *id = OF_BSN_TLV_USE_PACKET_STATE;
            break;
        case 0x61:
            *id = OF_BSN_TLV_STATUS;
            break;
        case 0x62:
            *id = OF_BSN_TLV_VLAN_MAC_LIST;
            break;
        case 0x63:
            *id = OF_BSN_TLV_VFI;
            break;
        case 0x64:
            *id = OF_BSN_TLV_HASH_SEED;
            break;
        case 0x65:
            *id = OF_BSN_TLV_HASH_TYPE;
            break;
        case 0x66:
            *id = OF_BSN_TLV_HASH_PACKET_TYPE;
            break;
        case 0x67:
            *id = OF_BSN_TLV_HASH_PACKET_FIELD;
            break;
        case 0x68:
            *id = OF_BSN_TLV_HASH_GTP_HEADER_MATCH;
            break;
        case 0x69:
            *id = OF_BSN_TLV_HASH_GTP_PORT_MATCH;
            break;
        case 0x6a:
            *id = OF_BSN_TLV_UNTAGGED;
            break;
        case 0x6b:
            *id = OF_BSN_TLV_VFP_CLASS_ID;
            break;
        case 0x6c:
            *id = OF_BSN_TLV_QOS_PRIORITY;
            break;
        case 0x6d:
            *id = OF_BSN_TLV_PARENT_PORT;
            break;
        case 0x6e:
            *id = OF_BSN_TLV_LOOPBACK_PORT;
            break;
        case 0x6f:
            *id = OF_BSN_TLV_VPN_KEY;
            break;
        case 0x70:
            *id = OF_BSN_TLV_DSCP;
            break;
        case 0x71:
            *id = OF_BSN_TLV_TTL;
            break;
        case 0x72:
            *id = OF_BSN_TLV_NEXT_HOP_MAC;
            break;
        case 0x73:
            *id = OF_BSN_TLV_NEXT_HOP_IPV4;
            break;
        case 0x74:
            *id = OF_BSN_TLV_RATE_LIMIT;
            break;
        case 0x75:
            *id = OF_BSN_TLV_VXLAN_EGRESS_LAG;
            break;
        case 0x76:
            *id = OF_BSN_TLV_CPU_LAG;
            break;
        case 0x77:
            *id = OF_BSN_TLV_UINT64_LIST;
            break;
        case 0x78:
            *id = OF_BSN_TLV_DISABLE_SRC_MAC_CHECK;
            break;
        case 0x79:
            *id = OF_BSN_TLV_DROP;
            break;
        case 0x7a:
            *id = OF_BSN_TLV_IPV6_PREFIX;
            break;
        case 0x7b:
            *id = OF_BSN_TLV_NDP_OFFLOAD;
            break;
        case 0x7c:
            *id = OF_BSN_TLV_NDP_STATIC;
            break;
        case 0x7d:
            *id = OF_BSN_TLV_ICMPV6_CHKSUM;
            break;
        case 0x7e:
            *id = OF_BSN_TLV_IPV6_SRC;
            break;
        case 0x7f:
            *id = OF_BSN_TLV_IPV6_DST;
            break;
        case 0x80:
            *id = OF_BSN_TLV_PUSH_VLAN_ON_INGRESS;
            break;
        case 0x81:
            *id = OF_BSN_TLV_APPLY_PACKETS;
            break;
        case 0x82:
            *id = OF_BSN_TLV_APPLY_BYTES;
            break;
        case 0x83:
            *id = OF_BSN_TLV_ETH_TYPE;
            break;
        case 0x84:
            *id = OF_BSN_TLV_ECN;
            break;
        case 0x85:
            *id = OF_BSN_TLV_TCP_FLAGS;
            break;
        case 0x86:
            *id = OF_BSN_TLV_L3_INTERFACE_CLASS_ID;
            break;
        case 0x87:
            *id = OF_BSN_TLV_L3_SRC_CLASS_ID;
            break;
        case 0x88:
            *id = OF_BSN_TLV_L3_DST_CLASS_ID;
            break;
        case 0x89:
            *id = OF_BSN_TLV_EGRESS_ONLY;
            break;
        case 0x8a:
            *id = OF_BSN_TLV_INGRESS_PORT_GROUP_ID;
            break;
        case 0x8b:
            *id = OF_BSN_TLV_EGRESS_PORT_GROUP_ID;
            break;
        case 0x8c:
            *id = OF_BSN_TLV_DATA_MASK;
            break;
        case 0x8d:
            *id = OF_BSN_TLV_PORT_USAGE;
            break;
        case 0x8e:
            *id = OF_BSN_TLV_TUNNEL_CAPABILITY;
            break;
        case 0x8f:
            *id = OF_BSN_TLV_ENHANCED_HASH_CAPABILITY;
            break;
        case 0x90:
            *id = OF_BSN_TLV_AUTO_NEGOTIATION;
            break;
        case 0x91:
            *id = OF_BSN_TLV_HASH_ALGORITHM;
            break;
        case 0x92:
            *id = OF_BSN_TLV_LOOPBACK_MODE;
            break;
        case 0x93:
            *id = OF_BSN_TLV_NO_ARP_RESPONSE;
            break;
        case 0x94:
            *id = OF_BSN_TLV_NO_NS_RESPONSE;
            break;
        case 0x95:
            *id = OF_BSN_TLV_FORWARD_ERROR_CORRECTION;
            break;
        case 0x96:
            *id = OF_BSN_TLV_OPTICS_ALWAYS_ENABLED;
            break;
        case 0x97:
            *id = OF_BSN_TLV_FORCE_LINK_UP;
            break;
        case 0x98:
            *id = OF_BSN_TLV_REST_SERVER;
            break;
        case 0x99:
            *id = OF_BSN_TLV_URI_SCHEME;
            break;
        case 0x9a:
            *id = OF_BSN_TLV_TIMESTAMP;
            break;
        case 0x9b:
            *id = OF_BSN_TLV_RECORD_PACKETS;
            break;
        case 0x9c:
            *id = OF_BSN_TLV_PORT_SPEED_GBPS;
            break;
        case 0x9d:
            *id = OF_BSN_TLV_OUTER_SRC_MAC;
            break;
        case 0x9e:
            *id = OF_BSN_TLV_VIRTUAL;
            break;
        case 0x9f:
            *id = OF_BSN_TLV_PDUA_RX_INSTANCE;
            break;
        case 0xa0:
            *id = OF_BSN_TLV_LAG_OPTIONS;
            break;
        case 0xa1:
            *id = OF_BSN_TLV_ROUTING_PARAM;
            break;
        case 0xa2:
            *id = OF_BSN_TLV_PUSH_VLAN_ON_EGRESS;
            break;
        case 0xa3:
            *id = OF_BSN_TLV_FLOOD;
            break;
        case 0xa4:
            *id = OF_BSN_TLV_UPGRADE;
            break;
        case 0xa5:
            *id = OF_BSN_TLV_FABRIC_PORT_ROLE;
            break;
        case 0xa6:
            *id = OF_BSN_TLV_USER_CONFIGURED;
            break;
        case 0xa7:
            *id = OF_BSN_TLV_UINT32;
            break;
        case 0xa8:
            *id = OF_BSN_TLV_L3;
            break;
        case 0xa9:
            *id = OF_BSN_TLV_IP_TUNNEL_TYPE;
            break;
        case 0xaa:
            *id = OF_BSN_TLV_MULTICAST_PACKET;
            break;
        case 0xab:
            *id = OF_BSN_TLV_PIM_DR;
            break;
        case 0xac:
            *id = OF_BSN_TLV_PASSIVE;
            break;
        case 0xad:
            *id = OF_BSN_TLV_IDENTIFIER;
            break;
        case 0xae:
            *id = OF_BSN_TLV_MULTIPLIER;
            break;
        case 0xaf:
            *id = OF_BSN_TLV_ENCAP;
            break;
        case 0xb0:
            *id = OF_BSN_TLV_BFD_ENDPOINT;
            break;
        case 0xb1:
            *id = OF_BSN_TLV_BFD_STATE;
            break;
        case 0xb2:
            *id = OF_BSN_TLV_LR_ALL_ENABLED;
            break;
        case 0xb3:
            *id = OF_BSN_TLV_PORT_MODE;
            break;
        case 0xb4:
            *id = OF_BSN_TLV_UDF_CAPABILITY;
            break;
        case 0xb5:
            *id = OF_BSN_TLV_PIM_HELLO_FLOOD;
            break;
        case 0xb6:
            *id = OF_BSN_TLV_FLOW_CLASSIFY;
            break;
        case 0xb7:
            *id = OF_BSN_TLV_FLOW_IDENTIFIER;
            break;
        case 0xb8:
            *id = OF_BSN_TLV_FLOW_CLASSIFIER;
            break;
        case 0xb9:
            *id = OF_BSN_TLV_DISABLE_XMIT;
            break;
        case 0xba:
            *id = OF_BSN_TLV_PRESERVE_VLAN;
            break;
        case 0xbb:
            *id = OF_BSN_TLV_DROP_CONTROL;
            break;
        case 0xbc:
            *id = OF_BSN_TLV_LOSSLESS;
            break;
        case 0xbd:
            *id = OF_BSN_TLV_REDUNDANT_MGMT;
            break;
        case 0xbe:
            *id = OF_BSN_TLV_DNS_ANALYTICS;
            break;
        case 0xbf:
            *id = OF_BSN_TLV_SRC_MAC_CML;
            break;
        case 0xc0:
            *id = OF_BSN_TLV_ACTIVE;
            break;
        case 0xc1:
            *id = OF_BSN_TLV_LINK_UP;
            break;
        case 0xc2:
            *id = OF_BSN_TLV_FAIL_COUNT;
            break;
        case 0xc3:
            *id = OF_BSN_TLV_EGRESS_SAMPLING_RATE;
            break;
        case 0xc4:
            *id = OF_BSN_TLV_L2_CACHE_HIT;
            break;
        case 0xc5:
            *id = OF_BSN_TLV_INNER_VLAN_VID;
            break;
        case 0xc6:
            *id = OF_BSN_TLV_ARP_TPA;
            break;
        case 0xc7:
            *id = OF_BSN_TLV_ARP_SPA;
            break;
        case 0xc8:
            *id = OF_BSN_TLV_IFP_CLASS_ID;
            break;
        case 0xc9:
            *id = OF_BSN_TLV_IP_FRAGMENTATION;
            break;
        case 0xca:
            *id = OF_BSN_TLV_SCTP_SRC;
            break;
        case 0xcb:
            *id = OF_BSN_TLV_SCTP_DST;
            break;
        case 0xcc:
            *id = OF_BSN_TLV_ICMPV6_TYPE;
            break;
        case 0xcd:
            *id = OF_BSN_TLV_ICMPV6_CODE;
            break;
        case 0xce:
            *id = OF_BSN_TLV_ANALYTICS;
            break;
        case 0xcf:
            *id = OF_BSN_TLV_UDF_DATA;
            break;
        case 0xd0:
            *id = OF_BSN_TLV_MGMT_RESELECT_ON_FAILURE;
            break;
        case 0xd1:
            *id = OF_BSN_TLV_LCORE;
            break;
        case 0xd2:
            *id = OF_BSN_TLV_THREAD;
            break;
        case 0xd3:
            *id = OF_BSN_TLV_MGMT;
            break;
        case 0xd4:
            *id = OF_BSN_TLV_SOCKET;
            break;
        case 0xd5:
            *id = OF_BSN_TLV_LOAD;
            break;
        case 0xd6:
            *id = OF_BSN_TLV_MAX_COUNT;
            break;
        case 0xd7:
            *id = OF_BSN_TLV_FREE_COUNT;
            break;
        case 0xd8:
            *id = OF_BSN_TLV_ADMIN_STATE;
            break;
        case 0xd9:
            *id = OF_BSN_TLV_MATCHED_COUNT;
            break;
        case 0xda:
            *id = OF_BSN_TLV_LOOKUP_COUNT;
            break;
        case 0xdb:
            *id = OF_BSN_TLV_PUSH_TWO_TAGS_CAPABILITY;
            break;
        case 0xdc:
            *id = OF_BSN_TLV_PUSH_TWO_PER_POLICY;
            break;
        case 0xdd:
            *id = OF_BSN_TLV_METADATA;
            break;
        case 0xde:
            *id = OF_BSN_TLV_PACKET_FIELD;
            break;
        case 0xdf:
            *id = OF_BSN_TLV_NO_DROP;
            break;
        case 0xe0:
            *id = OF_BSN_TLV_REMOTE_ID;
            break;
        case 0xe1:
            *id = OF_BSN_TLV_CLIENT_LL_ADDR;
            break;
        case 0xe2:
            *id = OF_BSN_TLV_ACTION_STATE;
            break;
        case 0xe3:
            *id = OF_BSN_TLV_LAG_TYPE;
            break;
        case 0xe4:
            *id = OF_BSN_TLV_SWL_FEATURE;
            break;
        default:
            *id = OF_BSN_TLV;
            break;
        }
        break;
    }
    case OF_VERSION_1_4: {
        uint16_t value = U16_NTOH(*(uint16_t *)(buf + 0)); /* type */
        switch (value) {
        case 0x0:
            *id = OF_BSN_TLV_PORT;
            break;
        case 0x1:
            *id = OF_BSN_TLV_MAC;
            break;
        case 0x2:
            *id = OF_BSN_TLV_RX_PACKETS;
            break;
        case 0x3:
            *id = OF_BSN_TLV_TX_PACKETS;
            break;
        case 0x4:
            *id = OF_BSN_TLV_IPV4;
            break;
        case 0x5:
            *id = OF_BSN_TLV_IDLE_TIME;
            break;
        case 0x6:
            *id = OF_BSN_TLV_VLAN_VID;
            break;
        case 0x7:
            *id = OF_BSN_TLV_IDLE_NOTIFICATION;
            break;
        case 0x8:
            *id = OF_BSN_TLV_IDLE_TIMEOUT;
            break;
        case 0x9:
            *id = OF_BSN_TLV_UNICAST_QUERY_TIMEOUT;
            break;
        case 0xa:
            *id = OF_BSN_TLV_BROADCAST_QUERY_TIMEOUT;
            break;
        case 0xb:
            *id = OF_BSN_TLV_REQUEST_PACKETS;
            break;
        case 0xc:
            *id = OF_BSN_TLV_REPLY_PACKETS;
            break;
        case 0xd:
            *id = OF_BSN_TLV_MISS_PACKETS;
            break;
        case 0xe:
            *id = OF_BSN_TLV_CIRCUIT_ID;
            break;
        case 0xf:
            *id = OF_BSN_TLV_UDF_ID;
            break;
        case 0x10:
            *id = OF_BSN_TLV_UDF_ANCHOR;
            break;
        case 0x11:
            *id = OF_BSN_TLV_UDF_OFFSET;
            break;
        case 0x12:
            *id = OF_BSN_TLV_UDF_LENGTH;
            break;
        case 0x13:
            *id = OF_BSN_TLV_VRF;
            break;
        case 0x14:
            *id = OF_BSN_TLV_QUEUE_ID;
            break;
        case 0x15:
            *id = OF_BSN_TLV_QUEUE_WEIGHT;
            break;
        case 0x16:
            *id = OF_BSN_TLV_CRC_ENABLED;
            break;
        case 0x17:
            *id = OF_BSN_TLV_EXTERNAL_IP;
            break;
        case 0x18:
            *id = OF_BSN_TLV_EXTERNAL_MAC;
            break;
        case 0x19:
            *id = OF_BSN_TLV_EXTERNAL_NETMASK;
            break;
        case 0x1a:
            *id = OF_BSN_TLV_EXTERNAL_GATEWAY_IP;
            break;
        case 0x1b:
            *id = OF_BSN_TLV_INTERNAL_MAC;
            break;
        case 0x1c:
            *id = OF_BSN_TLV_INTERNAL_GATEWAY_MAC;
            break;
        case 0x1d:
            *id = OF_BSN_TLV_EXTERNAL_GATEWAY_MAC;
            break;
        case 0x1e:
            *id = OF_BSN_TLV_SAMPLING_RATE;
            break;
        case 0x1f:
            *id = OF_BSN_TLV_HEADER_SIZE;
            break;
        case 0x20:
            *id = OF_BSN_TLV_ETH_SRC;
            break;
        case 0x21:
            *id = OF_BSN_TLV_ETH_DST;
            break;
        case 0x22:
            *id = OF_BSN_TLV_IPV4_SRC;
            break;
        case 0x23:
            *id = OF_BSN_TLV_IPV4_DST;
            break;
        case 0x24:
            *id = OF_BSN_TLV_UDP_SRC;
            break;
        case 0x25:
            *id = OF_BSN_TLV_UDP_DST;
            break;
        case 0x26:
            *id = OF_BSN_TLV_SUB_AGENT_ID;
            break;
        case 0x27:
            *id = OF_BSN_TLV_TX_BYTES;
            break;
        case 0x28:
            *id = OF_BSN_TLV_ACTOR_SYSTEM_PRIORITY;
            break;
        case 0x29:
            *id = OF_BSN_TLV_ACTOR_SYSTEM_MAC;
            break;
        case 0x2a:
            *id = OF_BSN_TLV_ACTOR_PORT_PRIORITY;
            break;
        case 0x2b:
            *id = OF_BSN_TLV_ACTOR_PORT_NUM;
            break;
        case 0x2c:
            *id = OF_BSN_TLV_ACTOR_KEY;
            break;
        case 0x2d:
            *id = OF_BSN_TLV_CONVERGENCE_STATUS;
            break;
        case 0x2f:
            *id = OF_BSN_TLV_PARTNER_SYSTEM_PRIORITY;
            break;
        case 0x30:
            *id = OF_BSN_TLV_PARTNER_SYSTEM_MAC;
            break;
        case 0x31:
            *id = OF_BSN_TLV_PARTNER_PORT_PRIORITY;
            break;
        case 0x32:
            *id = OF_BSN_TLV_PARTNER_PORT_NUM;
            break;
        case 0x33:
            *id = OF_BSN_TLV_PARTNER_KEY;
            break;
        case 0x34:
            *id = OF_BSN_TLV_NAME;
            break;
        case 0x35:
            *id = OF_BSN_TLV_ACTOR_STATE;
            break;
        case 0x36:
            *id = OF_BSN_TLV_PARTNER_STATE;
            break;
        case 0x37:
            *id = OF_BSN_TLV_DATA;
            break;
        case 0x38:
            *id = OF_BSN_TLV_MAC_MASK;
            break;
        case 0x39:
            *id = OF_BSN_TLV_PRIORITY;
            break;
        case 0x3a:
            *id = OF_BSN_TLV_INTERVAL;
            break;
        case 0x3b:
            *id = OF_BSN_TLV_REFERENCE;
            break;
        case 0x3c:
            *id = OF_BSN_TLV_IPV4_NETMASK;
            break;
        case 0x3d:
            *id = OF_BSN_TLV_MPLS_LABEL;
            break;
        case 0x3e:
            *id = OF_BSN_TLV_MPLS_CONTROL_WORD;
            break;
        case 0x3f:
            *id = OF_BSN_TLV_MPLS_SEQUENCED;
            break;
        case 0x40:
            *id = OF_BSN_TLV_BUCKET;
            break;
        case 0x41:
            *id = OF_BSN_TLV_TCP_SRC;
            break;
        case 0x42:
            *id = OF_BSN_TLV_TCP_DST;
            break;
        case 0x43:
            *id = OF_BSN_TLV_IP_PROTO;
            break;
        case 0x44:
            *id = OF_BSN_TLV_ICMP_TYPE;
            break;
        case 0x45:
            *id = OF_BSN_TLV_ICMP_CODE;
            break;
        case 0x46:
            *id = OF_BSN_TLV_ICMP_ID;
            break;
        case 0x47:
            *id = OF_BSN_TLV_RX_BYTES;
            break;
        case 0x48:
            *id = OF_BSN_TLV_VLAN_PCP;
            break;
        case 0x49:
            *id = OF_BSN_TLV_STRIP_VLAN_ON_EGRESS;
            break;
        case 0x4a:
            *id = OF_BSN_TLV_SET_LOOPBACK_MODE;
            break;
        case 0x4b:
            *id = OF_BSN_TLV_STRIP_MPLS_L2_ON_INGRESS;
            break;
        case 0x4c:
            *id = OF_BSN_TLV_STRIP_MPLS_L3_ON_INGRESS;
            break;
        case 0x4d:
            *id = OF_BSN_TLV_VLAN_VID_MASK;
            break;
        case 0x4e:
            *id = OF_BSN_TLV_IGMP_SNOOPING;
            break;
        case 0x4f:
            *id = OF_BSN_TLV_L2_MULTICAST_LOOKUP;
            break;
        case 0x50:
            *id = OF_BSN_TLV_GENERATION_ID;
            break;
        case 0x51:
            *id = OF_BSN_TLV_ANCHOR;
            break;
        case 0x52:
            *id = OF_BSN_TLV_OFFSET;
            break;
        case 0x53:
            *id = OF_BSN_TLV_NEGATE;
            break;
        case 0x54:
            *id = OF_BSN_TLV_IPV6;
            break;
        case 0x55:
            *id = OF_BSN_TLV_DECAP;
            break;
        case 0x56:
            *id = OF_BSN_TLV_VNI;
            break;
        case 0x57:
            *id = OF_BSN_TLV_MCG_TYPE_VXLAN;
            break;
        case 0x58:
            *id = OF_BSN_TLV_PORT_VXLAN_MODE;
            break;
        case 0x59:
            *id = OF_BSN_TLV_RATE_UNIT;
            break;
        case 0x5a:
            *id = OF_BSN_TLV_BROADCAST_RATE;
            break;
        case 0x5b:
            *id = OF_BSN_TLV_KNOWN_MULTICAST_RATE;
            break;
        case 0x5c:
            *id = OF_BSN_TLV_UNKNOWN_MULTICAST_RATE;
            break;
        case 0x5d:
            *id = OF_BSN_TLV_UNICAST_RATE;
            break;
        case 0x5e:
            *id = OF_BSN_TLV_NEXTHOP_TYPE_VXLAN;
            break;
        case 0x5f:
            *id = OF_BSN_TLV_MULTICAST_INTERFACE_ID;
            break;
        case 0x60:
            *id = OF_BSN_TLV_USE_PACKET_STATE;
            break;
        case 0x61:
            *id = OF_BSN_TLV_STATUS;
            break;
        case 0x62:
            *id = OF_BSN_TLV_VLAN_MAC_LIST;
            break;
        case 0x63:
            *id = OF_BSN_TLV_VFI;
            break;
        case 0x64:
            *id = OF_BSN_TLV_HASH_SEED;
            break;
        case 0x65:
            *id = OF_BSN_TLV_HASH_TYPE;
            break;
        case 0x66:
            *id = OF_BSN_TLV_HASH_PACKET_TYPE;
            break;
        case 0x67:
            *id = OF_BSN_TLV_HASH_PACKET_FIELD;
            break;
        case 0x68:
            *id = OF_BSN_TLV_HASH_GTP_HEADER_MATCH;
            break;
        case 0x69:
            *id = OF_BSN_TLV_HASH_GTP_PORT_MATCH;
            break;
        case 0x6a:
            *id = OF_BSN_TLV_UNTAGGED;
            break;
        case 0x6b:
            *id = OF_BSN_TLV_VFP_CLASS_ID;
            break;
        case 0x6c:
            *id = OF_BSN_TLV_QOS_PRIORITY;
            break;
        case 0x6d:
            *id = OF_BSN_TLV_PARENT_PORT;
            break;
        case 0x6e:
            *id = OF_BSN_TLV_LOOPBACK_PORT;
            break;
        case 0x6f:
            *id = OF_BSN_TLV_VPN_KEY;
            break;
        case 0x70:
            *id = OF_BSN_TLV_DSCP;
            break;
        case 0x71:
            *id = OF_BSN_TLV_TTL;
            break;
        case 0x72:
            *id = OF_BSN_TLV_NEXT_HOP_MAC;
            break;
        case 0x73:
            *id = OF_BSN_TLV_NEXT_HOP_IPV4;
            break;
        case 0x74:
            *id = OF_BSN_TLV_RATE_LIMIT;
            break;
        case 0x75:
            *id = OF_BSN_TLV_VXLAN_EGRESS_LAG;
            break;
        case 0x76:
            *id = OF_BSN_TLV_CPU_LAG;
            break;
        case 0x77:
            *id = OF_BSN_TLV_UINT64_LIST;
            break;
        case 0x78:
            *id = OF_BSN_TLV_DISABLE_SRC_MAC_CHECK;
            break;
        case 0x79:
            *id = OF_BSN_TLV_DROP;
            break;
        case 0x7a:
            *id = OF_BSN_TLV_IPV6_PREFIX;
            break;
        case 0x7b:
            *id = OF_BSN_TLV_NDP_OFFLOAD;
            break;
        case 0x7c:
            *id = OF_BSN_TLV_NDP_STATIC;
            break;
        case 0x7d:
            *id = OF_BSN_TLV_ICMPV6_CHKSUM;
            break;
        case 0x7e:
            *id = OF_BSN_TLV_IPV6_SRC;
            break;
        case 0x7f:
            *id = OF_BSN_TLV_IPV6_DST;
            break;
        case 0x80:
            *id = OF_BSN_TLV_PUSH_VLAN_ON_INGRESS;
            break;
        case 0x81:
            *id = OF_BSN_TLV_APPLY_PACKETS;
            break;
        case 0x82:
            *id = OF_BSN_TLV_APPLY_BYTES;
            break;
        case 0x83:
            *id = OF_BSN_TLV_ETH_TYPE;
            break;
        case 0x84:
            *id = OF_BSN_TLV_ECN;
            break;
        case 0x85:
            *id = OF_BSN_TLV_TCP_FLAGS;
            break;
        case 0x86:
            *id = OF_BSN_TLV_L3_INTERFACE_CLASS_ID;
            break;
        case 0x87:
            *id = OF_BSN_TLV_L3_SRC_CLASS_ID;
            break;
        case 0x88:
            *id = OF_BSN_TLV_L3_DST_CLASS_ID;
            break;
        case 0x89:
            *id = OF_BSN_TLV_EGRESS_ONLY;
            break;
        case 0x8a:
            *id = OF_BSN_TLV_INGRESS_PORT_GROUP_ID;
            break;
        case 0x8b:
            *id = OF_BSN_TLV_EGRESS_PORT_GROUP_ID;
            break;
        case 0x8c:
            *id = OF_BSN_TLV_DATA_MASK;
            break;
        case 0x8d:
            *id = OF_BSN_TLV_PORT_USAGE;
            break;
        case 0x8e:
            *id = OF_BSN_TLV_TUNNEL_CAPABILITY;
            break;
        case 0x8f:
            *id = OF_BSN_TLV_ENHANCED_HASH_CAPABILITY;
            break;
        case 0x90:
            *id = OF_BSN_TLV_AUTO_NEGOTIATION;
            break;
        case 0x91:
            *id = OF_BSN_TLV_HASH_ALGORITHM;
            break;
        case 0x92:
            *id = OF_BSN_TLV_LOOPBACK_MODE;
            break;
        case 0x93:
            *id = OF_BSN_TLV_NO_ARP_RESPONSE;
            break;
        case 0x94:
            *id = OF_BSN_TLV_NO_NS_RESPONSE;
            break;
        case 0x95:
            *id = OF_BSN_TLV_FORWARD_ERROR_CORRECTION;
            break;
        case 0x96:
            *id = OF_BSN_TLV_OPTICS_ALWAYS_ENABLED;
            break;
        case 0x97:
            *id = OF_BSN_TLV_FORCE_LINK_UP;
            break;
        case 0x98:
            *id = OF_BSN_TLV_REST_SERVER;
            break;
        case 0x99:
            *id = OF_BSN_TLV_URI_SCHEME;
            break;
        case 0x9a:
            *id = OF_BSN_TLV_TIMESTAMP;
            break;
        case 0x9b:
            *id = OF_BSN_TLV_RECORD_PACKETS;
            break;
        case 0x9c:
            *id = OF_BSN_TLV_PORT_SPEED_GBPS;
            break;
        case 0x9d:
            *id = OF_BSN_TLV_OUTER_SRC_MAC;
            break;
        case 0x9e:
            *id = OF_BSN_TLV_VIRTUAL;
            break;
        case 0x9f:
            *id = OF_BSN_TLV_PDUA_RX_INSTANCE;
            break;
        case 0xa0:
            *id = OF_BSN_TLV_LAG_OPTIONS;
            break;
        case 0xa1:
            *id = OF_BSN_TLV_ROUTING_PARAM;
            break;
        case 0xa2:
            *id = OF_BSN_TLV_PUSH_VLAN_ON_EGRESS;
            break;
        case 0xa3:
            *id = OF_BSN_TLV_FLOOD;
            break;
        case 0xa4:
            *id = OF_BSN_TLV_UPGRADE;
            break;
        case 0xa5:
            *id = OF_BSN_TLV_FABRIC_PORT_ROLE;
            break;
        case 0xa6:
            *id = OF_BSN_TLV_USER_CONFIGURED;
            break;
        case 0xa7:
            *id = OF_BSN_TLV_UINT32;
            break;
        case 0xa8:
            *id = OF_BSN_TLV_L3;
            break;
        case 0xa9:
            *id = OF_BSN_TLV_IP_TUNNEL_TYPE;
            break;
        case 0xaa:
            *id = OF_BSN_TLV_MULTICAST_PACKET;
            break;
        case 0xab:
            *id = OF_BSN_TLV_PIM_DR;
            break;
        case 0xac:
            *id = OF_BSN_TLV_PASSIVE;
            break;
        case 0xad:
            *id = OF_BSN_TLV_IDENTIFIER;
            break;
        case 0xae:
            *id = OF_BSN_TLV_MULTIPLIER;
            break;
        case 0xaf:
            *id = OF_BSN_TLV_ENCAP;
            break;
        case 0xb0:
            *id = OF_BSN_TLV_BFD_ENDPOINT;
            break;
        case 0xb1:
            *id = OF_BSN_TLV_BFD_STATE;
            break;
        case 0xb2:
            *id = OF_BSN_TLV_LR_ALL_ENABLED;
            break;
        case 0xb3:
            *id = OF_BSN_TLV_PORT_MODE;
            break;
        case 0xb4:
            *id = OF_BSN_TLV_UDF_CAPABILITY;
            break;
        case 0xb5:
            *id = OF_BSN_TLV_PIM_HELLO_FLOOD;
            break;
        case 0xb6:
            *id = OF_BSN_TLV_FLOW_CLASSIFY;
            break;
        case 0xb7:
            *id = OF_BSN_TLV_FLOW_IDENTIFIER;
            break;
        case 0xb8:
            *id = OF_BSN_TLV_FLOW_CLASSIFIER;
            break;
        case 0xb9:
            *id = OF_BSN_TLV_DISABLE_XMIT;
            break;
        case 0xba:
            *id = OF_BSN_TLV_PRESERVE_VLAN;
            break;
        case 0xbb:
            *id = OF_BSN_TLV_DROP_CONTROL;
            break;
        case 0xbc:
            *id = OF_BSN_TLV_LOSSLESS;
            break;
        case 0xbd:
            *id = OF_BSN_TLV_REDUNDANT_MGMT;
            break;
        case 0xbe:
            *id = OF_BSN_TLV_DNS_ANALYTICS;
            break;
        case 0xbf:
            *id = OF_BSN_TLV_SRC_MAC_CML;
            break;
        case 0xc0:
            *id = OF_BSN_TLV_ACTIVE;
            break;
        case 0xc1:
            *id = OF_BSN_TLV_LINK_UP;
            break;
        case 0xc2:
            *id = OF_BSN_TLV_FAIL_COUNT;
            break;
        case 0xc3:
            *id = OF_BSN_TLV_EGRESS_SAMPLING_RATE;
            break;
        case 0xc4:
            *id = OF_BSN_TLV_L2_CACHE_HIT;
            break;
        case 0xc5:
            *id = OF_BSN_TLV_INNER_VLAN_VID;
            break;
        case 0xc6:
            *id = OF_BSN_TLV_ARP_TPA;
            break;
        case 0xc7:
            *id = OF_BSN_TLV_ARP_SPA;
            break;
        case 0xc8:
            *id = OF_BSN_TLV_IFP_CLASS_ID;
            break;
        case 0xc9:
            *id = OF_BSN_TLV_IP_FRAGMENTATION;
            break;
        case 0xca:
            *id = OF_BSN_TLV_SCTP_SRC;
            break;
        case 0xcb:
            *id = OF_BSN_TLV_SCTP_DST;
            break;
        case 0xcc:
            *id = OF_BSN_TLV_ICMPV6_TYPE;
            break;
        case 0xcd:
            *id = OF_BSN_TLV_ICMPV6_CODE;
            break;
        case 0xce:
            *id = OF_BSN_TLV_ANALYTICS;
            break;
        case 0xcf:
            *id = OF_BSN_TLV_UDF_DATA;
            break;
        case 0xd0:
            *id = OF_BSN_TLV_MGMT_RESELECT_ON_FAILURE;
            break;
        case 0xd1:
            *id = OF_BSN_TLV_LCORE;
            break;
        case 0xd2:
            *id = OF_BSN_TLV_THREAD;
            break;
        case 0xd3:
            *id = OF_BSN_TLV_MGMT;
            break;
        case 0xd4:
            *id = OF_BSN_TLV_SOCKET;
            break;
        case 0xd5:
            *id = OF_BSN_TLV_LOAD;
            break;
        case 0xd6:
            *id = OF_BSN_TLV_MAX_COUNT;
            break;
        case 0xd7:
            *id = OF_BSN_TLV_FREE_COUNT;
            break;
        case 0xd8:
            *id = OF_BSN_TLV_ADMIN_STATE;
            break;
        case 0xd9:
            *id = OF_BSN_TLV_MATCHED_COUNT;
            break;
        case 0xda:
            *id = OF_BSN_TLV_LOOKUP_COUNT;
            break;
        case 0xdb:
            *id = OF_BSN_TLV_PUSH_TWO_TAGS_CAPABILITY;
            break;
        case 0xdc:
            *id = OF_BSN_TLV_PUSH_TWO_PER_POLICY;
            break;
        case 0xdd:
            *id = OF_BSN_TLV_METADATA;
            break;
        case 0xde:
            *id = OF_BSN_TLV_PACKET_FIELD;
            break;
        case 0xdf:
            *id = OF_BSN_TLV_NO_DROP;
            break;
        case 0xe0:
            *id = OF_BSN_TLV_REMOTE_ID;
            break;
        case 0xe1:
            *id = OF_BSN_TLV_CLIENT_LL_ADDR;
            break;
        case 0xe2:
            *id = OF_BSN_TLV_ACTION_STATE;
            break;
        case 0xe3:
            *id = OF_BSN_TLV_LAG_TYPE;
            break;
        case 0xe4:
            *id = OF_BSN_TLV_SWL_FEATURE;
            break;
        default:
            *id = OF_BSN_TLV;
            break;
        }
        break;
    }
    default:
        LOCI_ASSERT(0);
    }
}


/**
 * \defgroup of_bsn_tlv of_bsn_tlv
 */

/**
 * Create a new of_bsn_tlv object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv
 */

of_object_t *
of_bsn_tlv_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv.
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
of_bsn_tlv_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}
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

void
of_bsn_tlv_action_state_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xe2); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_action_state of_bsn_tlv_action_state
 */

/**
 * Create a new of_bsn_tlv_action_state object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_action_state
 */

of_object_t *
of_bsn_tlv_action_state_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_ACTION_STATE];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_action_state_init(obj, version, bytes, 0);
    of_bsn_tlv_action_state_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_action_state.
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
of_bsn_tlv_action_state_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_ACTION_STATE] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_ACTION_STATE];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_ACTION_STATE;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_bsn_tlv_action_state.
 * @param obj Pointer to an object of type of_bsn_tlv_action_state.
 * @param value Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_tlv_action_state_value_get(
    of_bsn_tlv_action_state_t *obj,
    uint16_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_ACTION_STATE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_bsn_tlv_action_state.
 * @param obj Pointer to an object of type of_bsn_tlv_action_state.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_action_state_value_set(
    of_bsn_tlv_action_state_t *obj,
    uint16_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_ACTION_STATE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
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

void
of_bsn_tlv_active_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xc0); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_active of_bsn_tlv_active
 */

/**
 * Create a new of_bsn_tlv_active object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_active
 */

of_object_t *
of_bsn_tlv_active_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_ACTIVE];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_active_init(obj, version, bytes, 0);
    of_bsn_tlv_active_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_active.
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
of_bsn_tlv_active_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_ACTIVE] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_ACTIVE];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_ACTIVE;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}
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

void
of_bsn_tlv_actor_key_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0x2c); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_actor_key of_bsn_tlv_actor_key
 */

/**
 * Create a new of_bsn_tlv_actor_key object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_actor_key
 */

of_object_t *
of_bsn_tlv_actor_key_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_ACTOR_KEY];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_actor_key_init(obj, version, bytes, 0);
    of_bsn_tlv_actor_key_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_actor_key.
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
of_bsn_tlv_actor_key_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_ACTOR_KEY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_ACTOR_KEY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_ACTOR_KEY;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_bsn_tlv_actor_key.
 * @param obj Pointer to an object of type of_bsn_tlv_actor_key.
 * @param value Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_tlv_actor_key_value_get(
    of_bsn_tlv_actor_key_t *obj,
    uint16_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_ACTOR_KEY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_bsn_tlv_actor_key.
 * @param obj Pointer to an object of type of_bsn_tlv_actor_key.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_actor_key_value_set(
    of_bsn_tlv_actor_key_t *obj,
    uint16_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_ACTOR_KEY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
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

void
of_bsn_tlv_actor_port_num_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0x2b); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_actor_port_num of_bsn_tlv_actor_port_num
 */

/**
 * Create a new of_bsn_tlv_actor_port_num object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_actor_port_num
 */

of_object_t *
of_bsn_tlv_actor_port_num_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_ACTOR_PORT_NUM];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_actor_port_num_init(obj, version, bytes, 0);
    of_bsn_tlv_actor_port_num_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_actor_port_num.
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
of_bsn_tlv_actor_port_num_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_ACTOR_PORT_NUM] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_ACTOR_PORT_NUM];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_ACTOR_PORT_NUM;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_bsn_tlv_actor_port_num.
 * @param obj Pointer to an object of type of_bsn_tlv_actor_port_num.
 * @param value Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_tlv_actor_port_num_value_get(
    of_bsn_tlv_actor_port_num_t *obj,
    uint16_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_ACTOR_PORT_NUM);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_bsn_tlv_actor_port_num.
 * @param obj Pointer to an object of type of_bsn_tlv_actor_port_num.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_actor_port_num_value_set(
    of_bsn_tlv_actor_port_num_t *obj,
    uint16_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_ACTOR_PORT_NUM);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
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

void
of_bsn_tlv_actor_port_priority_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0x2a); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_actor_port_priority of_bsn_tlv_actor_port_priority
 */

/**
 * Create a new of_bsn_tlv_actor_port_priority object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_actor_port_priority
 */

of_object_t *
of_bsn_tlv_actor_port_priority_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_ACTOR_PORT_PRIORITY];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_actor_port_priority_init(obj, version, bytes, 0);
    of_bsn_tlv_actor_port_priority_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_actor_port_priority.
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
of_bsn_tlv_actor_port_priority_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_ACTOR_PORT_PRIORITY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_ACTOR_PORT_PRIORITY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_ACTOR_PORT_PRIORITY;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_bsn_tlv_actor_port_priority.
 * @param obj Pointer to an object of type of_bsn_tlv_actor_port_priority.
 * @param value Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_tlv_actor_port_priority_value_get(
    of_bsn_tlv_actor_port_priority_t *obj,
    uint16_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_ACTOR_PORT_PRIORITY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_bsn_tlv_actor_port_priority.
 * @param obj Pointer to an object of type of_bsn_tlv_actor_port_priority.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_actor_port_priority_value_set(
    of_bsn_tlv_actor_port_priority_t *obj,
    uint16_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_ACTOR_PORT_PRIORITY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
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

void
of_bsn_tlv_actor_state_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0x35); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_actor_state of_bsn_tlv_actor_state
 */

/**
 * Create a new of_bsn_tlv_actor_state object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_actor_state
 */

of_object_t *
of_bsn_tlv_actor_state_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_ACTOR_STATE];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_actor_state_init(obj, version, bytes, 0);
    of_bsn_tlv_actor_state_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_actor_state.
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
of_bsn_tlv_actor_state_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_ACTOR_STATE] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_ACTOR_STATE];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_ACTOR_STATE;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_bsn_tlv_actor_state.
 * @param obj Pointer to an object of type of_bsn_tlv_actor_state.
 * @param value Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_bsn_tlv_actor_state_value_get(
    of_bsn_tlv_actor_state_t *obj,
    uint8_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_ACTOR_STATE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_bsn_tlv_actor_state.
 * @param obj Pointer to an object of type of_bsn_tlv_actor_state.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_actor_state_value_set(
    of_bsn_tlv_actor_state_t *obj,
    uint8_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_ACTOR_STATE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
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

void
of_bsn_tlv_actor_system_mac_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0x29); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_actor_system_mac of_bsn_tlv_actor_system_mac
 */

/**
 * Create a new of_bsn_tlv_actor_system_mac object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_actor_system_mac
 */

of_object_t *
of_bsn_tlv_actor_system_mac_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_ACTOR_SYSTEM_MAC];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_actor_system_mac_init(obj, version, bytes, 0);
    of_bsn_tlv_actor_system_mac_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_actor_system_mac.
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
of_bsn_tlv_actor_system_mac_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_ACTOR_SYSTEM_MAC] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_ACTOR_SYSTEM_MAC];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_ACTOR_SYSTEM_MAC;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_bsn_tlv_actor_system_mac.
 * @param obj Pointer to an object of type of_bsn_tlv_actor_system_mac.
 * @param value Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_bsn_tlv_actor_system_mac_value_get(
    of_bsn_tlv_actor_system_mac_t *obj,
    of_mac_addr_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_ACTOR_SYSTEM_MAC);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_bsn_tlv_actor_system_mac.
 * @param obj Pointer to an object of type of_bsn_tlv_actor_system_mac.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_actor_system_mac_value_set(
    of_bsn_tlv_actor_system_mac_t *obj,
    of_mac_addr_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_ACTOR_SYSTEM_MAC);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
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

void
of_bsn_tlv_actor_system_priority_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0x28); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_actor_system_priority of_bsn_tlv_actor_system_priority
 */

/**
 * Create a new of_bsn_tlv_actor_system_priority object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_actor_system_priority
 */

of_object_t *
of_bsn_tlv_actor_system_priority_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_ACTOR_SYSTEM_PRIORITY];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_actor_system_priority_init(obj, version, bytes, 0);
    of_bsn_tlv_actor_system_priority_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_actor_system_priority.
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
of_bsn_tlv_actor_system_priority_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_ACTOR_SYSTEM_PRIORITY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_ACTOR_SYSTEM_PRIORITY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_ACTOR_SYSTEM_PRIORITY;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_bsn_tlv_actor_system_priority.
 * @param obj Pointer to an object of type of_bsn_tlv_actor_system_priority.
 * @param value Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_tlv_actor_system_priority_value_get(
    of_bsn_tlv_actor_system_priority_t *obj,
    uint16_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_ACTOR_SYSTEM_PRIORITY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_bsn_tlv_actor_system_priority.
 * @param obj Pointer to an object of type of_bsn_tlv_actor_system_priority.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_actor_system_priority_value_set(
    of_bsn_tlv_actor_system_priority_t *obj,
    uint16_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_ACTOR_SYSTEM_PRIORITY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
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

void
of_bsn_tlv_admin_state_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xd8); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_admin_state of_bsn_tlv_admin_state
 */

/**
 * Create a new of_bsn_tlv_admin_state object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_admin_state
 */

of_object_t *
of_bsn_tlv_admin_state_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_ADMIN_STATE];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_admin_state_init(obj, version, bytes, 0);
    of_bsn_tlv_admin_state_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_admin_state.
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
of_bsn_tlv_admin_state_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_ADMIN_STATE] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_ADMIN_STATE];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_ADMIN_STATE;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_bsn_tlv_admin_state.
 * @param obj Pointer to an object of type of_bsn_tlv_admin_state.
 * @param value Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_bsn_tlv_admin_state_value_get(
    of_bsn_tlv_admin_state_t *obj,
    uint8_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_ADMIN_STATE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_bsn_tlv_admin_state.
 * @param obj Pointer to an object of type of_bsn_tlv_admin_state.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_admin_state_value_set(
    of_bsn_tlv_admin_state_t *obj,
    uint8_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_ADMIN_STATE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
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

void
of_bsn_tlv_analytics_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xce); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_analytics of_bsn_tlv_analytics
 */

/**
 * Create a new of_bsn_tlv_analytics object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_analytics
 */

of_object_t *
of_bsn_tlv_analytics_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_ANALYTICS];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_analytics_init(obj, version, bytes, 0);
    of_bsn_tlv_analytics_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_analytics.
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
of_bsn_tlv_analytics_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_ANALYTICS] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_ANALYTICS];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_ANALYTICS;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}
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

void
of_bsn_tlv_anchor_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0x51); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_anchor of_bsn_tlv_anchor
 */

/**
 * Create a new of_bsn_tlv_anchor object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_anchor
 */

of_object_t *
of_bsn_tlv_anchor_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_ANCHOR];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_anchor_init(obj, version, bytes, 0);
    of_bsn_tlv_anchor_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_anchor.
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
of_bsn_tlv_anchor_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_ANCHOR] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_ANCHOR];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_ANCHOR;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_bsn_tlv_anchor.
 * @param obj Pointer to an object of type of_bsn_tlv_anchor.
 * @param value Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_tlv_anchor_value_get(
    of_bsn_tlv_anchor_t *obj,
    uint16_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_ANCHOR);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_bsn_tlv_anchor.
 * @param obj Pointer to an object of type of_bsn_tlv_anchor.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_anchor_value_set(
    of_bsn_tlv_anchor_t *obj,
    uint16_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_ANCHOR);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
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

void
of_bsn_tlv_apply_bytes_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0x82); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_apply_bytes of_bsn_tlv_apply_bytes
 */

/**
 * Create a new of_bsn_tlv_apply_bytes object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_apply_bytes
 */

of_object_t *
of_bsn_tlv_apply_bytes_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_APPLY_BYTES];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_apply_bytes_init(obj, version, bytes, 0);
    of_bsn_tlv_apply_bytes_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_apply_bytes.
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
of_bsn_tlv_apply_bytes_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_APPLY_BYTES] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_APPLY_BYTES];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_APPLY_BYTES;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_bsn_tlv_apply_bytes.
 * @param obj Pointer to an object of type of_bsn_tlv_apply_bytes.
 * @param value Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_bsn_tlv_apply_bytes_value_get(
    of_bsn_tlv_apply_bytes_t *obj,
    uint64_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_APPLY_BYTES);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_bsn_tlv_apply_bytes.
 * @param obj Pointer to an object of type of_bsn_tlv_apply_bytes.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_apply_bytes_value_set(
    of_bsn_tlv_apply_bytes_t *obj,
    uint64_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_APPLY_BYTES);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
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

void
of_bsn_tlv_apply_packets_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0x81); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_apply_packets of_bsn_tlv_apply_packets
 */

/**
 * Create a new of_bsn_tlv_apply_packets object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_apply_packets
 */

of_object_t *
of_bsn_tlv_apply_packets_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_APPLY_PACKETS];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_apply_packets_init(obj, version, bytes, 0);
    of_bsn_tlv_apply_packets_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_apply_packets.
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
of_bsn_tlv_apply_packets_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_APPLY_PACKETS] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_APPLY_PACKETS];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_APPLY_PACKETS;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_bsn_tlv_apply_packets.
 * @param obj Pointer to an object of type of_bsn_tlv_apply_packets.
 * @param value Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_bsn_tlv_apply_packets_value_get(
    of_bsn_tlv_apply_packets_t *obj,
    uint64_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_APPLY_PACKETS);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_bsn_tlv_apply_packets.
 * @param obj Pointer to an object of type of_bsn_tlv_apply_packets.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_apply_packets_value_set(
    of_bsn_tlv_apply_packets_t *obj,
    uint64_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_APPLY_PACKETS);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
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

void
of_bsn_tlv_arp_spa_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xc7); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_arp_spa of_bsn_tlv_arp_spa
 */

/**
 * Create a new of_bsn_tlv_arp_spa object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_arp_spa
 */

of_object_t *
of_bsn_tlv_arp_spa_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_ARP_SPA];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_arp_spa_init(obj, version, bytes, 0);
    of_bsn_tlv_arp_spa_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_arp_spa.
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
of_bsn_tlv_arp_spa_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_ARP_SPA] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_ARP_SPA];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_ARP_SPA;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_bsn_tlv_arp_spa.
 * @param obj Pointer to an object of type of_bsn_tlv_arp_spa.
 * @param value Pointer to the child object of type
 * of_ipv4_t to be filled out.
 *
 */
void
of_bsn_tlv_arp_spa_value_get(
    of_bsn_tlv_arp_spa_t *obj,
    of_ipv4_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_ARP_SPA);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv4_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_bsn_tlv_arp_spa.
 * @param obj Pointer to an object of type of_bsn_tlv_arp_spa.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_arp_spa_value_set(
    of_bsn_tlv_arp_spa_t *obj,
    of_ipv4_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_ARP_SPA);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv4_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
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

void
of_bsn_tlv_arp_tpa_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xc6); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_arp_tpa of_bsn_tlv_arp_tpa
 */

/**
 * Create a new of_bsn_tlv_arp_tpa object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_arp_tpa
 */

of_object_t *
of_bsn_tlv_arp_tpa_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_ARP_TPA];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_arp_tpa_init(obj, version, bytes, 0);
    of_bsn_tlv_arp_tpa_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_arp_tpa.
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
of_bsn_tlv_arp_tpa_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_ARP_TPA] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_ARP_TPA];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_ARP_TPA;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_bsn_tlv_arp_tpa.
 * @param obj Pointer to an object of type of_bsn_tlv_arp_tpa.
 * @param value Pointer to the child object of type
 * of_ipv4_t to be filled out.
 *
 */
void
of_bsn_tlv_arp_tpa_value_get(
    of_bsn_tlv_arp_tpa_t *obj,
    of_ipv4_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_ARP_TPA);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv4_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_bsn_tlv_arp_tpa.
 * @param obj Pointer to an object of type of_bsn_tlv_arp_tpa.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_arp_tpa_value_set(
    of_bsn_tlv_arp_tpa_t *obj,
    of_ipv4_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_ARP_TPA);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv4_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
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

void
of_bsn_tlv_auto_negotiation_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0x90); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_auto_negotiation of_bsn_tlv_auto_negotiation
 */

/**
 * Create a new of_bsn_tlv_auto_negotiation object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_auto_negotiation
 */

of_object_t *
of_bsn_tlv_auto_negotiation_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_AUTO_NEGOTIATION];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_auto_negotiation_init(obj, version, bytes, 0);
    of_bsn_tlv_auto_negotiation_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_auto_negotiation.
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
of_bsn_tlv_auto_negotiation_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_AUTO_NEGOTIATION] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_AUTO_NEGOTIATION];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_AUTO_NEGOTIATION;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_bsn_tlv_auto_negotiation.
 * @param obj Pointer to an object of type of_bsn_tlv_auto_negotiation.
 * @param value Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_bsn_tlv_auto_negotiation_value_get(
    of_bsn_tlv_auto_negotiation_t *obj,
    uint8_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_AUTO_NEGOTIATION);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_bsn_tlv_auto_negotiation.
 * @param obj Pointer to an object of type of_bsn_tlv_auto_negotiation.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_auto_negotiation_value_set(
    of_bsn_tlv_auto_negotiation_t *obj,
    uint8_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_AUTO_NEGOTIATION);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
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

void
of_bsn_tlv_bfd_endpoint_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xb0); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_bfd_endpoint of_bsn_tlv_bfd_endpoint
 */

/**
 * Create a new of_bsn_tlv_bfd_endpoint object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_bfd_endpoint
 */

of_object_t *
of_bsn_tlv_bfd_endpoint_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_BFD_ENDPOINT];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_bfd_endpoint_init(obj, version, bytes, 0);
    of_bsn_tlv_bfd_endpoint_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_bfd_endpoint.
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
of_bsn_tlv_bfd_endpoint_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_BFD_ENDPOINT] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_BFD_ENDPOINT];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_BFD_ENDPOINT;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_bsn_tlv_bfd_endpoint.
 * @param obj Pointer to an object of type of_bsn_tlv_bfd_endpoint.
 * @param value Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_bsn_tlv_bfd_endpoint_value_get(
    of_bsn_tlv_bfd_endpoint_t *obj,
    uint8_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_BFD_ENDPOINT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_bsn_tlv_bfd_endpoint.
 * @param obj Pointer to an object of type of_bsn_tlv_bfd_endpoint.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_bfd_endpoint_value_set(
    of_bsn_tlv_bfd_endpoint_t *obj,
    uint8_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_BFD_ENDPOINT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
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

void
of_bsn_tlv_bfd_state_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xb1); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_bfd_state of_bsn_tlv_bfd_state
 */

/**
 * Create a new of_bsn_tlv_bfd_state object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_bfd_state
 */

of_object_t *
of_bsn_tlv_bfd_state_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_BFD_STATE];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_bfd_state_init(obj, version, bytes, 0);
    of_bsn_tlv_bfd_state_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_bfd_state.
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
of_bsn_tlv_bfd_state_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_BFD_STATE] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_BFD_STATE];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_BFD_STATE;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_bsn_tlv_bfd_state.
 * @param obj Pointer to an object of type of_bsn_tlv_bfd_state.
 * @param value Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_bsn_tlv_bfd_state_value_get(
    of_bsn_tlv_bfd_state_t *obj,
    uint8_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_BFD_STATE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_bsn_tlv_bfd_state.
 * @param obj Pointer to an object of type of_bsn_tlv_bfd_state.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_bfd_state_value_set(
    of_bsn_tlv_bfd_state_t *obj,
    uint8_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_BFD_STATE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
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

void
of_bsn_tlv_broadcast_query_timeout_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xa); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_broadcast_query_timeout of_bsn_tlv_broadcast_query_timeout
 */

/**
 * Create a new of_bsn_tlv_broadcast_query_timeout object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_broadcast_query_timeout
 */

of_object_t *
of_bsn_tlv_broadcast_query_timeout_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_BROADCAST_QUERY_TIMEOUT];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_broadcast_query_timeout_init(obj, version, bytes, 0);
    of_bsn_tlv_broadcast_query_timeout_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_broadcast_query_timeout.
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
of_bsn_tlv_broadcast_query_timeout_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_BROADCAST_QUERY_TIMEOUT] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_BROADCAST_QUERY_TIMEOUT];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_BROADCAST_QUERY_TIMEOUT;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_bsn_tlv_broadcast_query_timeout.
 * @param obj Pointer to an object of type of_bsn_tlv_broadcast_query_timeout.
 * @param value Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_tlv_broadcast_query_timeout_value_get(
    of_bsn_tlv_broadcast_query_timeout_t *obj,
    uint32_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_BROADCAST_QUERY_TIMEOUT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_bsn_tlv_broadcast_query_timeout.
 * @param obj Pointer to an object of type of_bsn_tlv_broadcast_query_timeout.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_broadcast_query_timeout_value_set(
    of_bsn_tlv_broadcast_query_timeout_t *obj,
    uint32_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_BROADCAST_QUERY_TIMEOUT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
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

void
of_bsn_tlv_broadcast_rate_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0x5a); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_broadcast_rate of_bsn_tlv_broadcast_rate
 */

/**
 * Create a new of_bsn_tlv_broadcast_rate object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_broadcast_rate
 */

of_object_t *
of_bsn_tlv_broadcast_rate_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_BROADCAST_RATE];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_broadcast_rate_init(obj, version, bytes, 0);
    of_bsn_tlv_broadcast_rate_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_broadcast_rate.
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
of_bsn_tlv_broadcast_rate_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_BROADCAST_RATE] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_BROADCAST_RATE];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_BROADCAST_RATE;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_bsn_tlv_broadcast_rate.
 * @param obj Pointer to an object of type of_bsn_tlv_broadcast_rate.
 * @param value Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_tlv_broadcast_rate_value_get(
    of_bsn_tlv_broadcast_rate_t *obj,
    uint32_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_BROADCAST_RATE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_bsn_tlv_broadcast_rate.
 * @param obj Pointer to an object of type of_bsn_tlv_broadcast_rate.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_broadcast_rate_value_set(
    of_bsn_tlv_broadcast_rate_t *obj,
    uint32_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_BROADCAST_RATE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
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

void
of_bsn_tlv_bucket_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0x40); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_bucket of_bsn_tlv_bucket
 */

/**
 * Create a new of_bsn_tlv_bucket object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_bucket
 */

of_object_t *
of_bsn_tlv_bucket_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_BUCKET];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_bucket_init(obj, version, bytes, 0);
    of_bsn_tlv_bucket_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_bucket.
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
of_bsn_tlv_bucket_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_BUCKET] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_BUCKET];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_BUCKET;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Bind an object of type of_list_bsn_tlv_t to the parent of type of_bsn_tlv_bucket for
 * member value
 * @param obj Pointer to an object of type of_bsn_tlv_bucket.
 * @param value Pointer to the child object of type
 * of_list_bsn_tlv_t to be filled out.
 * \ingroup of_bsn_tlv_bucket
 *
 * The parameter value is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_bsn_tlv_bucket_value_bind(
    of_bsn_tlv_bucket_t *obj,
    of_list_bsn_tlv_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_BUCKET);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_list_bsn_tlv_init(value, obj->version, 0, 1);
    /* Attach to parent */
    of_object_attach(obj, value, offset, cur_len);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of value into a new variable of type of_list_bsn_tlv_t from
 * a of_bsn_tlv_bucket instance.
 *
 * @param obj Pointer to the source of type of_bsn_tlv_bucket_t
 * @returns A pointer to a new instance of type of_list_bsn_tlv_t whose contents
 * match that of value from source
 * @returns NULL if an error occurs
 */
of_list_bsn_tlv_t *
of_bsn_tlv_bucket_value_get(of_bsn_tlv_bucket_t *obj) {
    of_list_bsn_tlv_t _value;
    of_list_bsn_tlv_t *_value_ptr;

    of_bsn_tlv_bucket_value_bind(obj, &_value);
    _value_ptr = (of_list_bsn_tlv_t *)of_object_dup(&_value);
    return _value_ptr;
}

/**
 * Set value in an object of type of_bsn_tlv_bucket.
 * @param obj Pointer to an object of type of_bsn_tlv_bucket.
 * @param value Pointer to the child of type of_list_bsn_tlv_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_bsn_tlv_bucket_value_set(
    of_bsn_tlv_bucket_t *obj,
    of_list_bsn_tlv_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_BUCKET);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = value->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wbuf == value->wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(value, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(value, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    of_object_wire_length_set((of_object_t *)value, value->length);

    /* Not scalar, update lengths if needed */
    delta = new_len - cur_len;
    if (delta != 0) {
        /* Update parent(s) */
        of_object_parent_length_update((of_object_t *)obj, delta);
    }

    OF_LENGTH_CHECK_ASSERT(obj);

    return OF_ERROR_NONE;
}
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

void
of_bsn_tlv_circuit_id_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xe); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_circuit_id of_bsn_tlv_circuit_id
 */

/**
 * Create a new of_bsn_tlv_circuit_id object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_circuit_id
 */

of_object_t *
of_bsn_tlv_circuit_id_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_CIRCUIT_ID];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_circuit_id_init(obj, version, bytes, 0);
    of_bsn_tlv_circuit_id_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_circuit_id.
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
of_bsn_tlv_circuit_id_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_CIRCUIT_ID] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_CIRCUIT_ID];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_CIRCUIT_ID;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_bsn_tlv_circuit_id.
 * @param obj Pointer to an object of type of_bsn_tlv_circuit_id.
 * @param value Pointer to the child object of type
 * of_octets_t to be filled out.
 *
 */
void
of_bsn_tlv_circuit_id_value_get(
    of_bsn_tlv_circuit_id_t *obj,
    of_octets_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_CIRCUIT_ID);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);
    LOCI_ASSERT(cur_len + abs_offset <= WBUF_CURRENT_BYTES(wbuf));
    value->bytes = cur_len;
    value->data = OF_WIRE_BUFFER_INDEX(wbuf, abs_offset);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_bsn_tlv_circuit_id.
 * @param obj Pointer to an object of type of_bsn_tlv_circuit_id.
 * @param value The value to write into the object
 */
int WARN_UNUSED_RESULT
of_bsn_tlv_circuit_id_value_set(
    of_bsn_tlv_circuit_id_t *obj,
    of_octets_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_CIRCUIT_ID);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);
    new_len = value->bytes;
    of_wire_buffer_grow(wbuf, abs_offset + (new_len - cur_len));
    of_wire_buffer_octets_data_set(wbuf, abs_offset, value, cur_len);

    /* Not scalar, update lengths if needed */
    delta = new_len - cur_len;
    if (delta != 0) {
        /* Update parent(s) */
        of_object_parent_length_update((of_object_t *)obj, delta);
    }

    OF_LENGTH_CHECK_ASSERT(obj);

    return OF_ERROR_NONE;
}
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

void
of_bsn_tlv_client_ll_addr_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xe1); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_client_ll_addr of_bsn_tlv_client_ll_addr
 */

/**
 * Create a new of_bsn_tlv_client_ll_addr object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_client_ll_addr
 */

of_object_t *
of_bsn_tlv_client_ll_addr_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_CLIENT_LL_ADDR];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_client_ll_addr_init(obj, version, bytes, 0);
    of_bsn_tlv_client_ll_addr_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_client_ll_addr.
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
of_bsn_tlv_client_ll_addr_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_CLIENT_LL_ADDR] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_CLIENT_LL_ADDR];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_CLIENT_LL_ADDR;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}
