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
of_group_features_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x13; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x8); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_group_features_stats_reply of_group_features_stats_reply
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_group_features_stats_reply_push_wire_values(of_group_features_stats_reply_t *obj)
{

    of_group_features_stats_reply_push_wire_types(obj);

    /* Message obj; set length */
    of_message_t msg;

    if ((msg = OF_OBJECT_TO_MESSAGE(obj)) != NULL) {
        of_message_length_set(msg, obj->length);
    }

    return OF_ERROR_NONE;
}

/**
 * Create a new of_group_features_stats_reply object
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
 * \ingroup of_group_features_stats_reply
 */

of_group_features_stats_reply_t *
of_group_features_stats_reply_new(of_version_t version)
{
    of_group_features_stats_reply_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_GROUP_FEATURES_STATS_REPLY] + of_object_extra_len[version][OF_GROUP_FEATURES_STATS_REPLY];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_group_features_stats_reply_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_group_features_stats_reply_init(obj, version, bytes, 0);

    if (of_group_features_stats_reply_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_group_features_stats_reply.
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
of_group_features_stats_reply_init(of_group_features_stats_reply_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    ASSERT(of_object_fixed_len[version][OF_GROUP_FEATURES_STATS_REPLY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_GROUP_FEATURES_STATS_REPLY] + of_object_extra_len[version][OF_GROUP_FEATURES_STATS_REPLY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_GROUP_FEATURES_STATS_REPLY;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_group_features_stats_reply_push_wire_types;

    obj->wire_length_get = of_object_message_wire_length_get;
    obj->wire_length_set = of_object_message_wire_length_set;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Create a new of_group_features_stats_reply object and bind it to an existing message
 *
 * @param msg The message to bind the new object to
 * @return Pointer to the newly create object or NULL on error
 *
 * \ingroup of_group_features_stats_reply
 */

of_group_features_stats_reply_t *
of_group_features_stats_reply_new_from_message(of_message_t msg)
{
    of_group_features_stats_reply_t *obj = NULL;
    of_version_t version;
    int length;

    if (msg == NULL) return NULL;

    version = of_message_version_get(msg);
    if (!OF_VERSION_OKAY(version)) return NULL;

    length = of_message_length_get(msg);

    if ((obj = (of_group_features_stats_reply_t *)of_object_new(-1)) == NULL) {
        return NULL;
    }

    of_group_features_stats_reply_init(obj, version, 0, 0);

    if ((of_object_buffer_bind((of_object_t *)obj, OF_MESSAGE_TO_BUFFER(msg),
                               length, OF_MESSAGE_FREE_FUNCTION)) < 0) {
       FREE(obj);
       return NULL;
    }
    obj->length = length;
    obj->version = version;

    return obj;
}

/**
 * Get xid from an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_group_features_stats_reply_xid_get(
    of_group_features_stats_reply_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param xid The value to write into the object
 */
void
of_group_features_stats_reply_xid_set(
    of_group_features_stats_reply_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get flags from an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param flags Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_group_features_stats_reply_flags_get(
    of_group_features_stats_reply_t *obj,
    uint16_t *flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 10;
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
 * Set flags in an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param flags The value to write into the object
 */
void
of_group_features_stats_reply_flags_set(
    of_group_features_stats_reply_t *obj,
    uint16_t flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 10;
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
 * Get types from an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param types Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_group_features_stats_reply_types_get(
    of_group_features_stats_reply_t *obj,
    uint32_t *types)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, types);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set types in an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param types The value to write into the object
 */
void
of_group_features_stats_reply_types_set(
    of_group_features_stats_reply_t *obj,
    uint32_t types)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, types);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get capabilities from an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param capabilities Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_group_features_stats_reply_capabilities_get(
    of_group_features_stats_reply_t *obj,
    uint32_t *capabilities)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, capabilities);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set capabilities in an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param capabilities The value to write into the object
 */
void
of_group_features_stats_reply_capabilities_set(
    of_group_features_stats_reply_t *obj,
    uint32_t capabilities)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, capabilities);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get max_groups_all from an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param max_groups_all Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_group_features_stats_reply_max_groups_all_get(
    of_group_features_stats_reply_t *obj,
    uint32_t *max_groups_all)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 24;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, max_groups_all);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set max_groups_all in an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param max_groups_all The value to write into the object
 */
void
of_group_features_stats_reply_max_groups_all_set(
    of_group_features_stats_reply_t *obj,
    uint32_t max_groups_all)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 24;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, max_groups_all);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get max_groups_select from an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param max_groups_select Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_group_features_stats_reply_max_groups_select_get(
    of_group_features_stats_reply_t *obj,
    uint32_t *max_groups_select)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 28;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, max_groups_select);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set max_groups_select in an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param max_groups_select The value to write into the object
 */
void
of_group_features_stats_reply_max_groups_select_set(
    of_group_features_stats_reply_t *obj,
    uint32_t max_groups_select)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 28;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, max_groups_select);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get max_groups_indirect from an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param max_groups_indirect Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_group_features_stats_reply_max_groups_indirect_get(
    of_group_features_stats_reply_t *obj,
    uint32_t *max_groups_indirect)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 32;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, max_groups_indirect);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set max_groups_indirect in an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param max_groups_indirect The value to write into the object
 */
void
of_group_features_stats_reply_max_groups_indirect_set(
    of_group_features_stats_reply_t *obj,
    uint32_t max_groups_indirect)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 32;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, max_groups_indirect);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get max_groups_ff from an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param max_groups_ff Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_group_features_stats_reply_max_groups_ff_get(
    of_group_features_stats_reply_t *obj,
    uint32_t *max_groups_ff)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 36;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, max_groups_ff);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set max_groups_ff in an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param max_groups_ff The value to write into the object
 */
void
of_group_features_stats_reply_max_groups_ff_set(
    of_group_features_stats_reply_t *obj,
    uint32_t max_groups_ff)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 36;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, max_groups_ff);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get actions_all from an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param actions_all Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_group_features_stats_reply_actions_all_get(
    of_group_features_stats_reply_t *obj,
    uint32_t *actions_all)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 40;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, actions_all);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set actions_all in an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param actions_all The value to write into the object
 */
void
of_group_features_stats_reply_actions_all_set(
    of_group_features_stats_reply_t *obj,
    uint32_t actions_all)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 40;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, actions_all);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get actions_select from an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param actions_select Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_group_features_stats_reply_actions_select_get(
    of_group_features_stats_reply_t *obj,
    uint32_t *actions_select)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 44;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, actions_select);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set actions_select in an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param actions_select The value to write into the object
 */
void
of_group_features_stats_reply_actions_select_set(
    of_group_features_stats_reply_t *obj,
    uint32_t actions_select)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 44;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, actions_select);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get actions_indirect from an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param actions_indirect Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_group_features_stats_reply_actions_indirect_get(
    of_group_features_stats_reply_t *obj,
    uint32_t *actions_indirect)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 48;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, actions_indirect);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set actions_indirect in an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param actions_indirect The value to write into the object
 */
void
of_group_features_stats_reply_actions_indirect_set(
    of_group_features_stats_reply_t *obj,
    uint32_t actions_indirect)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 48;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, actions_indirect);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get actions_ff from an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param actions_ff Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_group_features_stats_reply_actions_ff_get(
    of_group_features_stats_reply_t *obj,
    uint32_t *actions_ff)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 52;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, actions_ff);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set actions_ff in an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param actions_ff The value to write into the object
 */
void
of_group_features_stats_reply_actions_ff_set(
    of_group_features_stats_reply_t *obj,
    uint32_t actions_ff)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 52;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, actions_ff);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
