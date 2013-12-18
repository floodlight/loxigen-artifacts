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
of_action_set_tp_dst_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
        *(uint16_t *)(buf + 0) = htobe16(0xa); /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_action_set_tp_dst of_action_set_tp_dst
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_action_set_tp_dst_push_wire_values(of_action_set_tp_dst_t *obj)
{

    of_action_set_tp_dst_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_action_set_tp_dst object
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
 * \ingroup of_action_set_tp_dst
 */

of_action_set_tp_dst_t *
of_action_set_tp_dst_new(of_version_t version)
{
    of_action_set_tp_dst_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_SET_TP_DST] + of_object_extra_len[version][OF_ACTION_SET_TP_DST];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_action_set_tp_dst_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_action_set_tp_dst_init(obj, version, bytes, 0);

    if (of_action_set_tp_dst_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_action_set_tp_dst.
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
of_action_set_tp_dst_init(of_action_set_tp_dst_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    ASSERT(of_object_fixed_len[version][OF_ACTION_SET_TP_DST] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_SET_TP_DST] + of_object_extra_len[version][OF_ACTION_SET_TP_DST];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_SET_TP_DST;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_action_set_tp_dst_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_action_wire_object_id_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get tp_port from an object of type of_action_set_tp_dst.
 * @param obj Pointer to an object of type of_action_set_tp_dst.
 * @param tp_port Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_action_set_tp_dst_tp_port_get(
    of_action_set_tp_dst_t *obj,
    uint16_t *tp_port)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_ACTION_SET_TP_DST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
        offset = 4;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, tp_port);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set tp_port in an object of type of_action_set_tp_dst.
 * @param obj Pointer to an object of type of_action_set_tp_dst.
 * @param tp_port The value to write into the object
 */
void
of_action_set_tp_dst_tp_port_set(
    of_action_set_tp_dst_t *obj,
    uint16_t tp_port)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_ACTION_SET_TP_DST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
        offset = 4;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, tp_port);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
