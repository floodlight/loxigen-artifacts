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
of_packet_in_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0xa; /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_packet_in of_packet_in
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_packet_in_push_wire_values(of_packet_in_t *obj)
{

    of_packet_in_push_wire_types(obj);

    /* Message obj; set length */
    of_message_t msg;

    if ((msg = OF_OBJECT_TO_MESSAGE(obj)) != NULL) {
        of_message_length_set(msg, obj->length);
    }

    return OF_ERROR_NONE;
}

/**
 * Create a new of_packet_in object
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
 * \ingroup of_packet_in
 */

of_packet_in_t *
of_packet_in_new(of_version_t version)
{
    of_packet_in_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_PACKET_IN] + of_object_extra_len[version][OF_PACKET_IN];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_packet_in_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_packet_in_init(obj, version, bytes, 0);

    if (of_packet_in_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    /* Initialize match TLV for 1.2 */
    /* FIXME: Check 1.3 below */
    if ((version == OF_VERSION_1_2) || (version == OF_VERSION_1_3)) {
        of_object_u16_set((of_object_t *)obj, 16 + 2, 4);
    }

    return obj;
}

/**
 * Initialize an object of type of_packet_in.
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
of_packet_in_init(of_packet_in_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    ASSERT(of_object_fixed_len[version][OF_PACKET_IN] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_PACKET_IN] + of_object_extra_len[version][OF_PACKET_IN];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_PACKET_IN;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_packet_in_push_wire_types;

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
 * Create a new of_packet_in object and bind it to an existing message
 *
 * @param msg The message to bind the new object to
 * @return Pointer to the newly create object or NULL on error
 *
 * \ingroup of_packet_in
 */

of_packet_in_t *
of_packet_in_new_from_message(of_message_t msg)
{
    of_packet_in_t *obj = NULL;
    of_version_t version;
    int length;

    if (msg == NULL) return NULL;

    version = of_message_version_get(msg);
    if (!OF_VERSION_OKAY(version)) return NULL;

    length = of_message_length_get(msg);

    if ((obj = (of_packet_in_t *)of_object_new(-1)) == NULL) {
        return NULL;
    }

    of_packet_in_init(obj, version, 0, 0);

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
 * Get xid from an object of type of_packet_in.
 * @param obj Pointer to an object of type of_packet_in.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_packet_in_xid_get(
    of_packet_in_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PACKET_IN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
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
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_packet_in.
 * @param obj Pointer to an object of type of_packet_in.
 * @param xid The value to write into the object
 */
void
of_packet_in_xid_set(
    of_packet_in_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PACKET_IN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
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
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get buffer_id from an object of type of_packet_in.
 * @param obj Pointer to an object of type of_packet_in.
 * @param buffer_id Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_packet_in_buffer_id_get(
    of_packet_in_t *obj,
    uint32_t *buffer_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PACKET_IN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
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
    of_wire_buffer_u32_get(wbuf, abs_offset, buffer_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set buffer_id in an object of type of_packet_in.
 * @param obj Pointer to an object of type of_packet_in.
 * @param buffer_id The value to write into the object
 */
void
of_packet_in_buffer_id_set(
    of_packet_in_t *obj,
    uint32_t buffer_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PACKET_IN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
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
    of_wire_buffer_u32_set(wbuf, abs_offset, buffer_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get total_len from an object of type of_packet_in.
 * @param obj Pointer to an object of type of_packet_in.
 * @param total_len Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_packet_in_total_len_get(
    of_packet_in_t *obj,
    uint16_t *total_len)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PACKET_IN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 12;
        break;
    case OF_VERSION_1_1:
        offset = 20;
        break;
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 12;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, total_len);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set total_len in an object of type of_packet_in.
 * @param obj Pointer to an object of type of_packet_in.
 * @param total_len The value to write into the object
 */
void
of_packet_in_total_len_set(
    of_packet_in_t *obj,
    uint16_t total_len)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PACKET_IN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 12;
        break;
    case OF_VERSION_1_1:
        offset = 20;
        break;
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 12;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, total_len);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get reason from an object of type of_packet_in.
 * @param obj Pointer to an object of type of_packet_in.
 * @param reason Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_packet_in_reason_get(
    of_packet_in_t *obj,
    uint8_t *reason)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PACKET_IN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 16;
        break;
    case OF_VERSION_1_1:
        offset = 22;
        break;
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 14;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, reason);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set reason in an object of type of_packet_in.
 * @param obj Pointer to an object of type of_packet_in.
 * @param reason The value to write into the object
 */
void
of_packet_in_reason_set(
    of_packet_in_t *obj,
    uint8_t reason)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PACKET_IN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 16;
        break;
    case OF_VERSION_1_1:
        offset = 22;
        break;
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 14;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, reason);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get table_id from an object of type of_packet_in.
 * @param obj Pointer to an object of type of_packet_in.
 * @param table_id Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_packet_in_table_id_get(
    of_packet_in_t *obj,
    uint8_t *table_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PACKET_IN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 23;
        break;
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 15;
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
 * Set table_id in an object of type of_packet_in.
 * @param obj Pointer to an object of type of_packet_in.
 * @param table_id The value to write into the object
 */
void
of_packet_in_table_id_set(
    of_packet_in_t *obj,
    uint8_t table_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PACKET_IN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 23;
        break;
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 15;
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
 * Get cookie from an object of type of_packet_in.
 * @param obj Pointer to an object of type of_packet_in.
 * @param cookie Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_packet_in_cookie_get(
    of_packet_in_t *obj,
    uint64_t *cookie)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PACKET_IN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 16;
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
 * Set cookie in an object of type of_packet_in.
 * @param obj Pointer to an object of type of_packet_in.
 * @param cookie The value to write into the object
 */
void
of_packet_in_cookie_set(
    of_packet_in_t *obj,
    uint64_t cookie)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PACKET_IN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 16;
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
 * Get match from an object of type of_packet_in.
 * @param obj Pointer to an object of type of_packet_in.
 * @param match Pointer to the child object of type
 * of_match_t to be filled out.
 *
 */
int WARN_UNUSED_RESULT
of_packet_in_match_get(
    of_packet_in_t *obj,
    of_match_t *match)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    of_octets_t match_octets; /* Serialized string for match */

    ASSERT(obj->object_id == OF_PACKET_IN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
        offset = 16;
        cur_len = _WIRE_MATCH_PADDED_LEN(obj, offset);
        break;
    case OF_VERSION_1_3:
        offset = 24;
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
 * Set match in an object of type of_packet_in.
 * @param obj Pointer to an object of type of_packet_in.
 * @param match Pointer to the child of type of_match_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_packet_in_match_set(
    of_packet_in_t *obj,
    of_match_t *match)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */
    of_octets_t match_octets; /* Serialized string for match */

    ASSERT(obj->object_id == OF_PACKET_IN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
        offset = 16;
        cur_len = _WIRE_MATCH_PADDED_LEN(obj, offset);
        break;
    case OF_VERSION_1_3:
        offset = 24;
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
 * Get data from an object of type of_packet_in.
 * @param obj Pointer to an object of type of_packet_in.
 * @param data Pointer to the child object of type
 * of_octets_t to be filled out.
 *
 */
void
of_packet_in_data_get(
    of_packet_in_t *obj,
    of_octets_t *data)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    ASSERT(obj->object_id == OF_PACKET_IN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 18;
        cur_len = _END_LEN(obj, offset);
        break;
    case OF_VERSION_1_1:
        offset = 24;
        cur_len = _END_LEN(obj, offset);
        break;
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = _PACKET_IN_DATA_OFFSET(obj);
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    ASSERT(cur_len >= 0 && cur_len < 64 * 1024);
    ASSERT(cur_len + abs_offset <= WBUF_CURRENT_BYTES(wbuf));
    data->bytes = cur_len;
    data->data = OF_WIRE_BUFFER_INDEX(wbuf, abs_offset);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set data in an object of type of_packet_in.
 * @param obj Pointer to an object of type of_packet_in.
 * @param data The value to write into the object
 */
int WARN_UNUSED_RESULT
of_packet_in_data_set(
    of_packet_in_t *obj,
    of_octets_t *data)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    ASSERT(obj->object_id == OF_PACKET_IN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 18;
        cur_len = _END_LEN(obj, offset);
        break;
    case OF_VERSION_1_1:
        offset = 24;
        cur_len = _END_LEN(obj, offset);
        break;
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = _PACKET_IN_DATA_OFFSET(obj);
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    ASSERT(cur_len >= 0 && cur_len < 64 * 1024);
    new_len = data->bytes;
    of_wire_buffer_grow(wbuf, abs_offset + (new_len - cur_len));
    of_wire_buffer_octets_data_set(wbuf, abs_offset, data, cur_len);

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
 * Get in_port from an object of type of_packet_in.
 * @param obj Pointer to an object of type of_packet_in.
 * @param in_port Pointer to the child object of type
 * of_port_no_t to be filled out.
 *
 */
void
of_packet_in_in_port_get(
    of_packet_in_t *obj,
    of_port_no_t *in_port)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PACKET_IN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 14;
        break;
    case OF_VERSION_1_1:
        offset = 12;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_port_no_get(ver, wbuf, abs_offset, in_port);
    OF_PORT_NO_VALUE_CHECK(*in_port, ver);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set in_port in an object of type of_packet_in.
 * @param obj Pointer to an object of type of_packet_in.
 * @param in_port The value to write into the object
 */
void
of_packet_in_in_port_set(
    of_packet_in_t *obj,
    of_port_no_t in_port)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PACKET_IN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 14;
        break;
    case OF_VERSION_1_1:
        offset = 12;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_port_no_set(ver, wbuf, abs_offset, in_port);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get in_phy_port from an object of type of_packet_in.
 * @param obj Pointer to an object of type of_packet_in.
 * @param in_phy_port Pointer to the child object of type
 * of_port_no_t to be filled out.
 *
 */
void
of_packet_in_in_phy_port_get(
    of_packet_in_t *obj,
    of_port_no_t *in_phy_port)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PACKET_IN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 16;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_port_no_get(ver, wbuf, abs_offset, in_phy_port);
    OF_PORT_NO_VALUE_CHECK(*in_phy_port, ver);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set in_phy_port in an object of type of_packet_in.
 * @param obj Pointer to an object of type of_packet_in.
 * @param in_phy_port The value to write into the object
 */
void
of_packet_in_in_phy_port_set(
    of_packet_in_t *obj,
    of_port_no_t in_phy_port)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_PACKET_IN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 16;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_port_no_set(ver, wbuf, abs_offset, in_phy_port);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
