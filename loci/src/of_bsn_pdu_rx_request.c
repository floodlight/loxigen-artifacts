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
of_bsn_pdu_rx_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x21); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_bsn_pdu_rx_request of_bsn_pdu_rx_request
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_pdu_rx_request_push_wire_values(of_bsn_pdu_rx_request_t *obj)
{

    of_bsn_pdu_rx_request_push_wire_types(obj);

    /* Message obj; set length */
    of_message_t msg;

    if ((msg = OF_OBJECT_TO_MESSAGE(obj)) != NULL) {
        of_message_length_set(msg, obj->length);
    }

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_pdu_rx_request object
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
 * \ingroup of_bsn_pdu_rx_request
 */

of_bsn_pdu_rx_request_t *
of_bsn_pdu_rx_request_new(of_version_t version)
{
    of_bsn_pdu_rx_request_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_PDU_RX_REQUEST] + of_object_extra_len[version][OF_BSN_PDU_RX_REQUEST];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_pdu_rx_request_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_pdu_rx_request_init(obj, version, bytes, 0);

    if (of_bsn_pdu_rx_request_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_pdu_rx_request.
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
of_bsn_pdu_rx_request_init(of_bsn_pdu_rx_request_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    ASSERT(of_object_fixed_len[version][OF_BSN_PDU_RX_REQUEST] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_PDU_RX_REQUEST] + of_object_extra_len[version][OF_BSN_PDU_RX_REQUEST];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_PDU_RX_REQUEST;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_bsn_pdu_rx_request_push_wire_types;

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
 * Create a new of_bsn_pdu_rx_request object and bind it to an existing message
 *
 * @param msg The message to bind the new object to
 * @return Pointer to the newly create object or NULL on error
 *
 * \ingroup of_bsn_pdu_rx_request
 */

of_bsn_pdu_rx_request_t *
of_bsn_pdu_rx_request_new_from_message(of_message_t msg)
{
    of_bsn_pdu_rx_request_t *obj = NULL;
    of_version_t version;
    int length;

    if (msg == NULL) return NULL;

    version = of_message_version_get(msg);
    if (!OF_VERSION_OKAY(version)) return NULL;

    length = of_message_length_get(msg);

    if ((obj = (of_bsn_pdu_rx_request_t *)of_object_new(-1)) == NULL) {
        return NULL;
    }

    of_bsn_pdu_rx_request_init(obj, version, 0, 0);

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
 * Get xid from an object of type of_bsn_pdu_rx_request.
 * @param obj Pointer to an object of type of_bsn_pdu_rx_request.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_pdu_rx_request_xid_get(
    of_bsn_pdu_rx_request_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_PDU_RX_REQUEST);
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
 * Set xid in an object of type of_bsn_pdu_rx_request.
 * @param obj Pointer to an object of type of_bsn_pdu_rx_request.
 * @param xid The value to write into the object
 */
void
of_bsn_pdu_rx_request_xid_set(
    of_bsn_pdu_rx_request_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_PDU_RX_REQUEST);
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
 * Get experimenter from an object of type of_bsn_pdu_rx_request.
 * @param obj Pointer to an object of type of_bsn_pdu_rx_request.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_pdu_rx_request_experimenter_get(
    of_bsn_pdu_rx_request_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_PDU_RX_REQUEST);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_bsn_pdu_rx_request.
 * @param obj Pointer to an object of type of_bsn_pdu_rx_request.
 * @param experimenter The value to write into the object
 */
void
of_bsn_pdu_rx_request_experimenter_set(
    of_bsn_pdu_rx_request_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_PDU_RX_REQUEST);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_bsn_pdu_rx_request.
 * @param obj Pointer to an object of type of_bsn_pdu_rx_request.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_pdu_rx_request_subtype_get(
    of_bsn_pdu_rx_request_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_PDU_RX_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 12;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_bsn_pdu_rx_request.
 * @param obj Pointer to an object of type of_bsn_pdu_rx_request.
 * @param subtype The value to write into the object
 */
void
of_bsn_pdu_rx_request_subtype_set(
    of_bsn_pdu_rx_request_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_PDU_RX_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 12;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get timeout_ms from an object of type of_bsn_pdu_rx_request.
 * @param obj Pointer to an object of type of_bsn_pdu_rx_request.
 * @param timeout_ms Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_pdu_rx_request_timeout_ms_get(
    of_bsn_pdu_rx_request_t *obj,
    uint32_t *timeout_ms)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_PDU_RX_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
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
    of_wire_buffer_u32_get(wbuf, abs_offset, timeout_ms);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set timeout_ms in an object of type of_bsn_pdu_rx_request.
 * @param obj Pointer to an object of type of_bsn_pdu_rx_request.
 * @param timeout_ms The value to write into the object
 */
void
of_bsn_pdu_rx_request_timeout_ms_set(
    of_bsn_pdu_rx_request_t *obj,
    uint32_t timeout_ms)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_PDU_RX_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
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
    of_wire_buffer_u32_set(wbuf, abs_offset, timeout_ms);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get port_no from an object of type of_bsn_pdu_rx_request.
 * @param obj Pointer to an object of type of_bsn_pdu_rx_request.
 * @param port_no Pointer to the child object of type
 * of_port_no_t to be filled out.
 *
 */
void
of_bsn_pdu_rx_request_port_no_get(
    of_bsn_pdu_rx_request_t *obj,
    of_port_no_t *port_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_PDU_RX_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 20;
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_port_no_get(ver, wbuf, abs_offset, port_no);
    OF_PORT_NO_VALUE_CHECK(*port_no, ver);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set port_no in an object of type of_bsn_pdu_rx_request.
 * @param obj Pointer to an object of type of_bsn_pdu_rx_request.
 * @param port_no The value to write into the object
 */
void
of_bsn_pdu_rx_request_port_no_set(
    of_bsn_pdu_rx_request_t *obj,
    of_port_no_t port_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_PDU_RX_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 20;
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_port_no_set(ver, wbuf, abs_offset, port_no);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get slot_num from an object of type of_bsn_pdu_rx_request.
 * @param obj Pointer to an object of type of_bsn_pdu_rx_request.
 * @param slot_num Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_bsn_pdu_rx_request_slot_num_get(
    of_bsn_pdu_rx_request_t *obj,
    uint8_t *slot_num)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_PDU_RX_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 22;
        break;
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
    of_wire_buffer_u8_get(wbuf, abs_offset, slot_num);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set slot_num in an object of type of_bsn_pdu_rx_request.
 * @param obj Pointer to an object of type of_bsn_pdu_rx_request.
 * @param slot_num The value to write into the object
 */
void
of_bsn_pdu_rx_request_slot_num_set(
    of_bsn_pdu_rx_request_t *obj,
    uint8_t slot_num)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_PDU_RX_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 22;
        break;
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
    of_wire_buffer_u8_set(wbuf, abs_offset, slot_num);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get data from an object of type of_bsn_pdu_rx_request.
 * @param obj Pointer to an object of type of_bsn_pdu_rx_request.
 * @param data Pointer to the child object of type
 * of_octets_t to be filled out.
 *
 */
void
of_bsn_pdu_rx_request_data_get(
    of_bsn_pdu_rx_request_t *obj,
    of_octets_t *data)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    ASSERT(obj->object_id == OF_BSN_PDU_RX_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 26;
        cur_len = _END_LEN(obj, offset);
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 28;
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
 * Set data in an object of type of_bsn_pdu_rx_request.
 * @param obj Pointer to an object of type of_bsn_pdu_rx_request.
 * @param data The value to write into the object
 */
int WARN_UNUSED_RESULT
of_bsn_pdu_rx_request_data_set(
    of_bsn_pdu_rx_request_t *obj,
    of_octets_t *data)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    ASSERT(obj->object_id == OF_BSN_PDU_RX_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 26;
        cur_len = _END_LEN(obj, offset);
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 28;
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
