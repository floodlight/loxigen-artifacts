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
of_bsn_tlv_reply_packets_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0xc); /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_bsn_tlv_reply_packets of_bsn_tlv_reply_packets
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_tlv_reply_packets_push_wire_values(of_bsn_tlv_reply_packets_t *obj)
{

    of_bsn_tlv_reply_packets_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_tlv_reply_packets object
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
 * \ingroup of_bsn_tlv_reply_packets
 */

of_bsn_tlv_reply_packets_t *
of_bsn_tlv_reply_packets_new(of_version_t version)
{
    of_bsn_tlv_reply_packets_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_REPLY_PACKETS] + of_object_extra_len[version][OF_BSN_TLV_REPLY_PACKETS];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_tlv_reply_packets_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_reply_packets_init(obj, version, bytes, 0);

    if (of_bsn_tlv_reply_packets_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_reply_packets.
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
of_bsn_tlv_reply_packets_init(of_bsn_tlv_reply_packets_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_REPLY_PACKETS] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_REPLY_PACKETS] + of_object_extra_len[version][OF_BSN_TLV_REPLY_PACKETS];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_REPLY_PACKETS;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_bsn_tlv_reply_packets_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_bsn_tlv_wire_object_id_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get value from an object of type of_bsn_tlv_reply_packets.
 * @param obj Pointer to an object of type of_bsn_tlv_reply_packets.
 * @param value Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_bsn_tlv_reply_packets_value_get(
    of_bsn_tlv_reply_packets_t *obj,
    uint64_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_REPLY_PACKETS);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
 * Set value in an object of type of_bsn_tlv_reply_packets.
 * @param obj Pointer to an object of type of_bsn_tlv_reply_packets.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_reply_packets_value_set(
    of_bsn_tlv_reply_packets_t *obj,
    uint64_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_REPLY_PACKETS);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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

static void
of_bsn_tlv_request_packets_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0xb); /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_bsn_tlv_request_packets of_bsn_tlv_request_packets
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_tlv_request_packets_push_wire_values(of_bsn_tlv_request_packets_t *obj)
{

    of_bsn_tlv_request_packets_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_tlv_request_packets object
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
 * \ingroup of_bsn_tlv_request_packets
 */

of_bsn_tlv_request_packets_t *
of_bsn_tlv_request_packets_new(of_version_t version)
{
    of_bsn_tlv_request_packets_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_REQUEST_PACKETS] + of_object_extra_len[version][OF_BSN_TLV_REQUEST_PACKETS];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_tlv_request_packets_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_request_packets_init(obj, version, bytes, 0);

    if (of_bsn_tlv_request_packets_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_request_packets.
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
of_bsn_tlv_request_packets_init(of_bsn_tlv_request_packets_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_REQUEST_PACKETS] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_REQUEST_PACKETS] + of_object_extra_len[version][OF_BSN_TLV_REQUEST_PACKETS];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_REQUEST_PACKETS;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_bsn_tlv_request_packets_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_bsn_tlv_wire_object_id_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get value from an object of type of_bsn_tlv_request_packets.
 * @param obj Pointer to an object of type of_bsn_tlv_request_packets.
 * @param value Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_bsn_tlv_request_packets_value_get(
    of_bsn_tlv_request_packets_t *obj,
    uint64_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_REQUEST_PACKETS);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
 * Set value in an object of type of_bsn_tlv_request_packets.
 * @param obj Pointer to an object of type of_bsn_tlv_request_packets.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_request_packets_value_set(
    of_bsn_tlv_request_packets_t *obj,
    uint64_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_REQUEST_PACKETS);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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

static void
of_bsn_tlv_rx_packets_push_wire_types(of_object_t *obj)
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
 * \defgroup of_bsn_tlv_rx_packets of_bsn_tlv_rx_packets
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_tlv_rx_packets_push_wire_values(of_bsn_tlv_rx_packets_t *obj)
{

    of_bsn_tlv_rx_packets_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_tlv_rx_packets object
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
 * \ingroup of_bsn_tlv_rx_packets
 */

of_bsn_tlv_rx_packets_t *
of_bsn_tlv_rx_packets_new(of_version_t version)
{
    of_bsn_tlv_rx_packets_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_RX_PACKETS] + of_object_extra_len[version][OF_BSN_TLV_RX_PACKETS];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_tlv_rx_packets_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_rx_packets_init(obj, version, bytes, 0);

    if (of_bsn_tlv_rx_packets_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_rx_packets.
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
of_bsn_tlv_rx_packets_init(of_bsn_tlv_rx_packets_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_RX_PACKETS] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_RX_PACKETS] + of_object_extra_len[version][OF_BSN_TLV_RX_PACKETS];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_RX_PACKETS;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_bsn_tlv_rx_packets_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_bsn_tlv_wire_object_id_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get value from an object of type of_bsn_tlv_rx_packets.
 * @param obj Pointer to an object of type of_bsn_tlv_rx_packets.
 * @param value Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_bsn_tlv_rx_packets_value_get(
    of_bsn_tlv_rx_packets_t *obj,
    uint64_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_RX_PACKETS);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
 * Set value in an object of type of_bsn_tlv_rx_packets.
 * @param obj Pointer to an object of type of_bsn_tlv_rx_packets.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_rx_packets_value_set(
    of_bsn_tlv_rx_packets_t *obj,
    uint64_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_RX_PACKETS);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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

static void
of_bsn_tlv_tx_packets_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x3); /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_bsn_tlv_tx_packets of_bsn_tlv_tx_packets
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_tlv_tx_packets_push_wire_values(of_bsn_tlv_tx_packets_t *obj)
{

    of_bsn_tlv_tx_packets_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_tlv_tx_packets object
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
 * \ingroup of_bsn_tlv_tx_packets
 */

of_bsn_tlv_tx_packets_t *
of_bsn_tlv_tx_packets_new(of_version_t version)
{
    of_bsn_tlv_tx_packets_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_TX_PACKETS] + of_object_extra_len[version][OF_BSN_TLV_TX_PACKETS];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_tlv_tx_packets_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_tx_packets_init(obj, version, bytes, 0);

    if (of_bsn_tlv_tx_packets_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_tx_packets.
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
of_bsn_tlv_tx_packets_init(of_bsn_tlv_tx_packets_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_TX_PACKETS] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_TX_PACKETS] + of_object_extra_len[version][OF_BSN_TLV_TX_PACKETS];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_TX_PACKETS;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_bsn_tlv_tx_packets_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_bsn_tlv_wire_object_id_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get value from an object of type of_bsn_tlv_tx_packets.
 * @param obj Pointer to an object of type of_bsn_tlv_tx_packets.
 * @param value Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_bsn_tlv_tx_packets_value_get(
    of_bsn_tlv_tx_packets_t *obj,
    uint64_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_TX_PACKETS);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
 * Set value in an object of type of_bsn_tlv_tx_packets.
 * @param obj Pointer to an object of type of_bsn_tlv_tx_packets.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_tx_packets_value_set(
    of_bsn_tlv_tx_packets_t *obj,
    uint64_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_TX_PACKETS);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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

static void
of_bsn_tlv_unicast_query_timeout_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x9); /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_bsn_tlv_unicast_query_timeout of_bsn_tlv_unicast_query_timeout
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_tlv_unicast_query_timeout_push_wire_values(of_bsn_tlv_unicast_query_timeout_t *obj)
{

    of_bsn_tlv_unicast_query_timeout_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_tlv_unicast_query_timeout object
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
 * \ingroup of_bsn_tlv_unicast_query_timeout
 */

of_bsn_tlv_unicast_query_timeout_t *
of_bsn_tlv_unicast_query_timeout_new(of_version_t version)
{
    of_bsn_tlv_unicast_query_timeout_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_UNICAST_QUERY_TIMEOUT] + of_object_extra_len[version][OF_BSN_TLV_UNICAST_QUERY_TIMEOUT];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_tlv_unicast_query_timeout_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_unicast_query_timeout_init(obj, version, bytes, 0);

    if (of_bsn_tlv_unicast_query_timeout_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_unicast_query_timeout.
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
of_bsn_tlv_unicast_query_timeout_init(of_bsn_tlv_unicast_query_timeout_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_UNICAST_QUERY_TIMEOUT] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_UNICAST_QUERY_TIMEOUT] + of_object_extra_len[version][OF_BSN_TLV_UNICAST_QUERY_TIMEOUT];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_UNICAST_QUERY_TIMEOUT;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_bsn_tlv_unicast_query_timeout_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_bsn_tlv_wire_object_id_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get value from an object of type of_bsn_tlv_unicast_query_timeout.
 * @param obj Pointer to an object of type of_bsn_tlv_unicast_query_timeout.
 * @param value Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_tlv_unicast_query_timeout_value_get(
    of_bsn_tlv_unicast_query_timeout_t *obj,
    uint32_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_UNICAST_QUERY_TIMEOUT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
 * Set value in an object of type of_bsn_tlv_unicast_query_timeout.
 * @param obj Pointer to an object of type of_bsn_tlv_unicast_query_timeout.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_unicast_query_timeout_value_set(
    of_bsn_tlv_unicast_query_timeout_t *obj,
    uint32_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_UNICAST_QUERY_TIMEOUT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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

static void
of_bsn_tlv_vlan_vid_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x6); /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_bsn_tlv_vlan_vid of_bsn_tlv_vlan_vid
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_tlv_vlan_vid_push_wire_values(of_bsn_tlv_vlan_vid_t *obj)
{

    of_bsn_tlv_vlan_vid_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_tlv_vlan_vid object
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
 * \ingroup of_bsn_tlv_vlan_vid
 */

of_bsn_tlv_vlan_vid_t *
of_bsn_tlv_vlan_vid_new(of_version_t version)
{
    of_bsn_tlv_vlan_vid_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_VLAN_VID] + of_object_extra_len[version][OF_BSN_TLV_VLAN_VID];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_tlv_vlan_vid_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_vlan_vid_init(obj, version, bytes, 0);

    if (of_bsn_tlv_vlan_vid_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_vlan_vid.
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
of_bsn_tlv_vlan_vid_init(of_bsn_tlv_vlan_vid_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_VLAN_VID] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_VLAN_VID] + of_object_extra_len[version][OF_BSN_TLV_VLAN_VID];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_VLAN_VID;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_bsn_tlv_vlan_vid_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_bsn_tlv_wire_object_id_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get value from an object of type of_bsn_tlv_vlan_vid.
 * @param obj Pointer to an object of type of_bsn_tlv_vlan_vid.
 * @param value Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_tlv_vlan_vid_value_get(
    of_bsn_tlv_vlan_vid_t *obj,
    uint16_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_VLAN_VID);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
 * Set value in an object of type of_bsn_tlv_vlan_vid.
 * @param obj Pointer to an object of type of_bsn_tlv_vlan_vid.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_vlan_vid_value_set(
    of_bsn_tlv_vlan_vid_t *obj,
    uint16_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_VLAN_VID);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_VLAN_COUNTER_STATS_ENTRY] >= 0);
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

    LOCI_ASSERT(obj->object_id == OF_BSN_VLAN_COUNTER_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 2;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
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

    LOCI_ASSERT(obj->object_id == OF_BSN_VLAN_COUNTER_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 2;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
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

    LOCI_ASSERT(obj->object_id == OF_BSN_VLAN_COUNTER_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

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

    LOCI_ASSERT(obj->object_id == OF_BSN_VLAN_COUNTER_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = values->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wire_object.wbuf == values->wire_object.wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(values, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
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
of_bsn_vlan_counter_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x13; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0xffff); /* stats_type */
        *(uint32_t *)(buf + 16) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 20) = htobe32(0x9); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_bsn_vlan_counter_stats_reply of_bsn_vlan_counter_stats_reply
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_vlan_counter_stats_reply_push_wire_values(of_bsn_vlan_counter_stats_reply_t *obj)
{

    of_bsn_vlan_counter_stats_reply_push_wire_types(obj);

    /* Message obj; set length */
    of_message_t msg;

    if ((msg = OF_OBJECT_TO_MESSAGE(obj)) != NULL) {
        of_message_length_set(msg, obj->length);
    }

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_vlan_counter_stats_reply object
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
 * \ingroup of_bsn_vlan_counter_stats_reply
 */

of_bsn_vlan_counter_stats_reply_t *
of_bsn_vlan_counter_stats_reply_new(of_version_t version)
{
    of_bsn_vlan_counter_stats_reply_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_VLAN_COUNTER_STATS_REPLY] + of_object_extra_len[version][OF_BSN_VLAN_COUNTER_STATS_REPLY];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_vlan_counter_stats_reply_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_vlan_counter_stats_reply_init(obj, version, bytes, 0);

    if (of_bsn_vlan_counter_stats_reply_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_vlan_counter_stats_reply.
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
of_bsn_vlan_counter_stats_reply_init(of_bsn_vlan_counter_stats_reply_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_VLAN_COUNTER_STATS_REPLY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_VLAN_COUNTER_STATS_REPLY] + of_object_extra_len[version][OF_BSN_VLAN_COUNTER_STATS_REPLY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_VLAN_COUNTER_STATS_REPLY;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_bsn_vlan_counter_stats_reply_push_wire_types;

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
 * Create a new of_bsn_vlan_counter_stats_reply object and bind it to an existing message
 *
 * @param msg The message to bind the new object to
 * @return Pointer to the newly create object or NULL on error
 *
 * \ingroup of_bsn_vlan_counter_stats_reply
 */

of_bsn_vlan_counter_stats_reply_t *
of_bsn_vlan_counter_stats_reply_new_from_message(of_message_t msg)
{
    of_bsn_vlan_counter_stats_reply_t *obj = NULL;
    of_version_t version;
    int length;

    if (msg == NULL) return NULL;

    version = of_message_version_get(msg);
    if (!OF_VERSION_OKAY(version)) return NULL;

    length = of_message_length_get(msg);

    if ((obj = (of_bsn_vlan_counter_stats_reply_t *)of_object_new(-1)) == NULL) {
        return NULL;
    }

    of_bsn_vlan_counter_stats_reply_init(obj, version, 0, 0);

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
 * Get xid from an object of type of_bsn_vlan_counter_stats_reply.
 * @param obj Pointer to an object of type of_bsn_vlan_counter_stats_reply.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_vlan_counter_stats_reply_xid_get(
    of_bsn_vlan_counter_stats_reply_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_VLAN_COUNTER_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
 * Set xid in an object of type of_bsn_vlan_counter_stats_reply.
 * @param obj Pointer to an object of type of_bsn_vlan_counter_stats_reply.
 * @param xid The value to write into the object
 */
void
of_bsn_vlan_counter_stats_reply_xid_set(
    of_bsn_vlan_counter_stats_reply_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_VLAN_COUNTER_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
 * Get flags from an object of type of_bsn_vlan_counter_stats_reply.
 * @param obj Pointer to an object of type of_bsn_vlan_counter_stats_reply.
 * @param flags Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_vlan_counter_stats_reply_flags_get(
    of_bsn_vlan_counter_stats_reply_t *obj,
    uint16_t *flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_VLAN_COUNTER_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
 * Set flags in an object of type of_bsn_vlan_counter_stats_reply.
 * @param obj Pointer to an object of type of_bsn_vlan_counter_stats_reply.
 * @param flags The value to write into the object
 */
void
of_bsn_vlan_counter_stats_reply_flags_set(
    of_bsn_vlan_counter_stats_reply_t *obj,
    uint16_t flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_VLAN_COUNTER_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
 * Get experimenter from an object of type of_bsn_vlan_counter_stats_reply.
 * @param obj Pointer to an object of type of_bsn_vlan_counter_stats_reply.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_vlan_counter_stats_reply_experimenter_get(
    of_bsn_vlan_counter_stats_reply_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_VLAN_COUNTER_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
 * Set experimenter in an object of type of_bsn_vlan_counter_stats_reply.
 * @param obj Pointer to an object of type of_bsn_vlan_counter_stats_reply.
 * @param experimenter The value to write into the object
 */
void
of_bsn_vlan_counter_stats_reply_experimenter_set(
    of_bsn_vlan_counter_stats_reply_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_VLAN_COUNTER_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
 * Get subtype from an object of type of_bsn_vlan_counter_stats_reply.
 * @param obj Pointer to an object of type of_bsn_vlan_counter_stats_reply.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_vlan_counter_stats_reply_subtype_get(
    of_bsn_vlan_counter_stats_reply_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_VLAN_COUNTER_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
 * Set subtype in an object of type of_bsn_vlan_counter_stats_reply.
 * @param obj Pointer to an object of type of_bsn_vlan_counter_stats_reply.
 * @param subtype The value to write into the object
 */
void
of_bsn_vlan_counter_stats_reply_subtype_set(
    of_bsn_vlan_counter_stats_reply_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_VLAN_COUNTER_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
 * Bind an object of type of_list_bsn_vlan_counter_stats_entry_t to the parent of type of_bsn_vlan_counter_stats_reply for
 * member entries
 * @param obj Pointer to an object of type of_bsn_vlan_counter_stats_reply.
 * @param entries Pointer to the child object of type
 * of_list_bsn_vlan_counter_stats_entry_t to be filled out.
 * \ingroup of_bsn_vlan_counter_stats_reply
 *
 * The parameter entries is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_bsn_vlan_counter_stats_reply_entries_bind(
    of_bsn_vlan_counter_stats_reply_t *obj,
    of_list_bsn_vlan_counter_stats_entry_t *entries)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_BSN_VLAN_COUNTER_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
    of_list_bsn_vlan_counter_stats_entry_init(entries, obj->version, 0, 1);
    /* Attach to parent */
    entries->parent = (of_object_t *)obj;
    entries->wire_object.wbuf = obj->wire_object.wbuf;
    entries->wire_object.obj_offset = abs_offset;
    entries->wire_object.owned = 0;
    entries->length = cur_len;

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of entries into a new variable of type of_list_bsn_vlan_counter_stats_entry_t from
 * a of_bsn_vlan_counter_stats_reply instance.
 *
 * @param obj Pointer to the source of type of_bsn_vlan_counter_stats_reply_t
 * @returns A pointer to a new instance of type of_list_bsn_vlan_counter_stats_entry_t whose contents
 * match that of entries from source
 * @returns NULL if an error occurs
 */
of_list_bsn_vlan_counter_stats_entry_t *
of_bsn_vlan_counter_stats_reply_entries_get(of_bsn_vlan_counter_stats_reply_t *obj) {
    of_list_bsn_vlan_counter_stats_entry_t _entries;
    of_list_bsn_vlan_counter_stats_entry_t *_entries_ptr;

    of_bsn_vlan_counter_stats_reply_entries_bind(obj, &_entries);
    _entries_ptr = (of_list_bsn_vlan_counter_stats_entry_t *)of_object_dup(&_entries);
    return _entries_ptr;
}

/**
 * Set entries in an object of type of_bsn_vlan_counter_stats_reply.
 * @param obj Pointer to an object of type of_bsn_vlan_counter_stats_reply.
 * @param entries Pointer to the child of type of_list_bsn_vlan_counter_stats_entry_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_bsn_vlan_counter_stats_reply_entries_set(
    of_bsn_vlan_counter_stats_reply_t *obj,
    of_list_bsn_vlan_counter_stats_entry_t *entries)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_BSN_VLAN_COUNTER_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
    if (obj->wire_object.wbuf == entries->wire_object.wbuf) {
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
    if (entries->wire_length_set != NULL) {
        entries->wire_length_set((of_object_t *)entries, entries->length);
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
of_bsn_vlan_counter_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x12; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0xffff); /* stats_type */
        *(uint32_t *)(buf + 16) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 20) = htobe32(0x9); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_bsn_vlan_counter_stats_request of_bsn_vlan_counter_stats_request
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_vlan_counter_stats_request_push_wire_values(of_bsn_vlan_counter_stats_request_t *obj)
{

    of_bsn_vlan_counter_stats_request_push_wire_types(obj);

    /* Message obj; set length */
    of_message_t msg;

    if ((msg = OF_OBJECT_TO_MESSAGE(obj)) != NULL) {
        of_message_length_set(msg, obj->length);
    }

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_vlan_counter_stats_request object
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
 * \ingroup of_bsn_vlan_counter_stats_request
 */

of_bsn_vlan_counter_stats_request_t *
of_bsn_vlan_counter_stats_request_new(of_version_t version)
{
    of_bsn_vlan_counter_stats_request_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_VLAN_COUNTER_STATS_REQUEST] + of_object_extra_len[version][OF_BSN_VLAN_COUNTER_STATS_REQUEST];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_vlan_counter_stats_request_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_vlan_counter_stats_request_init(obj, version, bytes, 0);

    if (of_bsn_vlan_counter_stats_request_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_vlan_counter_stats_request.
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
of_bsn_vlan_counter_stats_request_init(of_bsn_vlan_counter_stats_request_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_VLAN_COUNTER_STATS_REQUEST] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_VLAN_COUNTER_STATS_REQUEST] + of_object_extra_len[version][OF_BSN_VLAN_COUNTER_STATS_REQUEST];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_VLAN_COUNTER_STATS_REQUEST;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_bsn_vlan_counter_stats_request_push_wire_types;

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
 * Create a new of_bsn_vlan_counter_stats_request object and bind it to an existing message
 *
 * @param msg The message to bind the new object to
 * @return Pointer to the newly create object or NULL on error
 *
 * \ingroup of_bsn_vlan_counter_stats_request
 */

of_bsn_vlan_counter_stats_request_t *
of_bsn_vlan_counter_stats_request_new_from_message(of_message_t msg)
{
    of_bsn_vlan_counter_stats_request_t *obj = NULL;
    of_version_t version;
    int length;

    if (msg == NULL) return NULL;

    version = of_message_version_get(msg);
    if (!OF_VERSION_OKAY(version)) return NULL;

    length = of_message_length_get(msg);

    if ((obj = (of_bsn_vlan_counter_stats_request_t *)of_object_new(-1)) == NULL) {
        return NULL;
    }

    of_bsn_vlan_counter_stats_request_init(obj, version, 0, 0);

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
 * Get xid from an object of type of_bsn_vlan_counter_stats_request.
 * @param obj Pointer to an object of type of_bsn_vlan_counter_stats_request.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_vlan_counter_stats_request_xid_get(
    of_bsn_vlan_counter_stats_request_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_VLAN_COUNTER_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
 * Set xid in an object of type of_bsn_vlan_counter_stats_request.
 * @param obj Pointer to an object of type of_bsn_vlan_counter_stats_request.
 * @param xid The value to write into the object
 */
void
of_bsn_vlan_counter_stats_request_xid_set(
    of_bsn_vlan_counter_stats_request_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_VLAN_COUNTER_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
 * Get flags from an object of type of_bsn_vlan_counter_stats_request.
 * @param obj Pointer to an object of type of_bsn_vlan_counter_stats_request.
 * @param flags Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_vlan_counter_stats_request_flags_get(
    of_bsn_vlan_counter_stats_request_t *obj,
    uint16_t *flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_VLAN_COUNTER_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
 * Set flags in an object of type of_bsn_vlan_counter_stats_request.
 * @param obj Pointer to an object of type of_bsn_vlan_counter_stats_request.
 * @param flags The value to write into the object
 */
void
of_bsn_vlan_counter_stats_request_flags_set(
    of_bsn_vlan_counter_stats_request_t *obj,
    uint16_t flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_VLAN_COUNTER_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
 * Get experimenter from an object of type of_bsn_vlan_counter_stats_request.
 * @param obj Pointer to an object of type of_bsn_vlan_counter_stats_request.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_vlan_counter_stats_request_experimenter_get(
    of_bsn_vlan_counter_stats_request_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_VLAN_COUNTER_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
 * Set experimenter in an object of type of_bsn_vlan_counter_stats_request.
 * @param obj Pointer to an object of type of_bsn_vlan_counter_stats_request.
 * @param experimenter The value to write into the object
 */
void
of_bsn_vlan_counter_stats_request_experimenter_set(
    of_bsn_vlan_counter_stats_request_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_VLAN_COUNTER_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
 * Get subtype from an object of type of_bsn_vlan_counter_stats_request.
 * @param obj Pointer to an object of type of_bsn_vlan_counter_stats_request.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_vlan_counter_stats_request_subtype_get(
    of_bsn_vlan_counter_stats_request_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_VLAN_COUNTER_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
 * Set subtype in an object of type of_bsn_vlan_counter_stats_request.
 * @param obj Pointer to an object of type of_bsn_vlan_counter_stats_request.
 * @param subtype The value to write into the object
 */
void
of_bsn_vlan_counter_stats_request_subtype_set(
    of_bsn_vlan_counter_stats_request_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_VLAN_COUNTER_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
 * Get vlan_vid from an object of type of_bsn_vlan_counter_stats_request.
 * @param obj Pointer to an object of type of_bsn_vlan_counter_stats_request.
 * @param vlan_vid Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_vlan_counter_stats_request_vlan_vid_get(
    of_bsn_vlan_counter_stats_request_t *obj,
    uint16_t *vlan_vid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_VLAN_COUNTER_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, vlan_vid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set vlan_vid in an object of type of_bsn_vlan_counter_stats_request.
 * @param obj Pointer to an object of type of_bsn_vlan_counter_stats_request.
 * @param vlan_vid The value to write into the object
 */
void
of_bsn_vlan_counter_stats_request_vlan_vid_set(
    of_bsn_vlan_counter_stats_request_t *obj,
    uint16_t vlan_vid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_VLAN_COUNTER_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, vlan_vid);

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
 * \defgroup of_experimenter_stats_header of_experimenter_stats_header
 */

/**
 * Create a new of_experimenter_stats_header object
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
 * \ingroup of_experimenter_stats_header
 */

of_experimenter_stats_header_t *
of_experimenter_stats_header_new(of_version_t version)
{
    of_experimenter_stats_header_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_EXPERIMENTER_STATS_HEADER] + of_object_extra_len[version][OF_EXPERIMENTER_STATS_HEADER];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_experimenter_stats_header_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_experimenter_stats_header_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_experimenter_stats_header.
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
of_experimenter_stats_header_init(of_experimenter_stats_header_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_EXPERIMENTER_STATS_HEADER] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_EXPERIMENTER_STATS_HEADER] + of_object_extra_len[version][OF_EXPERIMENTER_STATS_HEADER];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_EXPERIMENTER_STATS_HEADER;

    /* Set up the object's function pointers */

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get experimenter from an object of type of_experimenter_stats_header.
 * @param obj Pointer to an object of type of_experimenter_stats_header.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_experimenter_stats_header_experimenter_get(
    of_experimenter_stats_header_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_EXPERIMENTER_STATS_HEADER);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 0;
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
 * Set experimenter in an object of type of_experimenter_stats_header.
 * @param obj Pointer to an object of type of_experimenter_stats_header.
 * @param experimenter The value to write into the object
 */
void
of_experimenter_stats_header_experimenter_set(
    of_experimenter_stats_header_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_EXPERIMENTER_STATS_HEADER);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 0;
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
 * Get subtype from an object of type of_experimenter_stats_header.
 * @param obj Pointer to an object of type of_experimenter_stats_header.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_experimenter_stats_header_subtype_get(
    of_experimenter_stats_header_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_EXPERIMENTER_STATS_HEADER);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
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
 * Set subtype in an object of type of_experimenter_stats_header.
 * @param obj Pointer to an object of type of_experimenter_stats_header.
 * @param subtype The value to write into the object
 */
void
of_experimenter_stats_header_subtype_set(
    of_experimenter_stats_header_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_EXPERIMENTER_STATS_HEADER);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
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
 * \defgroup of_hello_elem of_hello_elem
 */

/**
 * Create a new of_hello_elem object
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
 * \ingroup of_hello_elem
 */

of_hello_elem_t *
of_hello_elem_new(of_version_t version)
{
    of_hello_elem_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_HELLO_ELEM] + of_object_extra_len[version][OF_HELLO_ELEM];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_hello_elem_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_hello_elem_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_hello_elem.
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
of_hello_elem_init(of_hello_elem_t *obj_p,
    of_version_t version, int bytes, int clean_wire)
{
    of_hello_elem_header_t *obj;

    obj = &obj_p->header;  /* Need instantiable subclass */

    LOCI_ASSERT(of_object_fixed_len[version][OF_HELLO_ELEM] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_HELLO_ELEM] + of_object_extra_len[version][OF_HELLO_ELEM];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_HELLO_ELEM;

    /* Set up the object's function pointers */

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_hello_elem_wire_object_id_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
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

static void
of_hello_elem_versionbitmap_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x1); /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_hello_elem_versionbitmap of_hello_elem_versionbitmap
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_hello_elem_versionbitmap_push_wire_values(of_hello_elem_versionbitmap_t *obj)
{

    of_hello_elem_versionbitmap_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_hello_elem_versionbitmap object
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
 * \ingroup of_hello_elem_versionbitmap
 */

of_hello_elem_versionbitmap_t *
of_hello_elem_versionbitmap_new(of_version_t version)
{
    of_hello_elem_versionbitmap_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_HELLO_ELEM_VERSIONBITMAP] + of_object_extra_len[version][OF_HELLO_ELEM_VERSIONBITMAP];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_hello_elem_versionbitmap_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_hello_elem_versionbitmap_init(obj, version, bytes, 0);

    if (of_hello_elem_versionbitmap_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_hello_elem_versionbitmap.
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
of_hello_elem_versionbitmap_init(of_hello_elem_versionbitmap_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_HELLO_ELEM_VERSIONBITMAP] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_HELLO_ELEM_VERSIONBITMAP] + of_object_extra_len[version][OF_HELLO_ELEM_VERSIONBITMAP];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_HELLO_ELEM_VERSIONBITMAP;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_hello_elem_versionbitmap_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_hello_elem_wire_object_id_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Bind an object of type of_list_uint32_t to the parent of type of_hello_elem_versionbitmap for
 * member bitmaps
 * @param obj Pointer to an object of type of_hello_elem_versionbitmap.
 * @param bitmaps Pointer to the child object of type
 * of_list_uint32_t to be filled out.
 * \ingroup of_hello_elem_versionbitmap
 *
 * The parameter bitmaps is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_hello_elem_versionbitmap_bitmaps_bind(
    of_hello_elem_versionbitmap_t *obj,
    of_list_uint32_t *bitmaps)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_HELLO_ELEM_VERSIONBITMAP);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
    of_list_uint32_init(bitmaps, obj->version, 0, 1);
    /* Attach to parent */
    bitmaps->parent = (of_object_t *)obj;
    bitmaps->wire_object.wbuf = obj->wire_object.wbuf;
    bitmaps->wire_object.obj_offset = abs_offset;
    bitmaps->wire_object.owned = 0;
    bitmaps->length = cur_len;

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of bitmaps into a new variable of type of_list_uint32_t from
 * a of_hello_elem_versionbitmap instance.
 *
 * @param obj Pointer to the source of type of_hello_elem_versionbitmap_t
 * @returns A pointer to a new instance of type of_list_uint32_t whose contents
 * match that of bitmaps from source
 * @returns NULL if an error occurs
 */
of_list_uint32_t *
of_hello_elem_versionbitmap_bitmaps_get(of_hello_elem_versionbitmap_t *obj) {
    of_list_uint32_t _bitmaps;
    of_list_uint32_t *_bitmaps_ptr;

    of_hello_elem_versionbitmap_bitmaps_bind(obj, &_bitmaps);
    _bitmaps_ptr = (of_list_uint32_t *)of_object_dup(&_bitmaps);
    return _bitmaps_ptr;
}

/**
 * Set bitmaps in an object of type of_hello_elem_versionbitmap.
 * @param obj Pointer to an object of type of_hello_elem_versionbitmap.
 * @param bitmaps Pointer to the child of type of_list_uint32_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_hello_elem_versionbitmap_bitmaps_set(
    of_hello_elem_versionbitmap_t *obj,
    of_list_uint32_t *bitmaps)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_HELLO_ELEM_VERSIONBITMAP);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
    new_len = bitmaps->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wire_object.wbuf == bitmaps->wire_object.wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(bitmaps, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(bitmaps, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    if (bitmaps->wire_length_set != NULL) {
        bitmaps->wire_length_set((of_object_t *)bitmaps, bitmaps->length);
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
 * \defgroup of_instruction_id of_instruction_id
 */

/**
 * Create a new of_instruction_id object
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
 * \ingroup of_instruction_id
 */

of_instruction_id_t *
of_instruction_id_new(of_version_t version)
{
    of_instruction_id_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_INSTRUCTION_ID] + of_object_extra_len[version][OF_INSTRUCTION_ID];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_instruction_id_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_instruction_id_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_instruction_id.
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
of_instruction_id_init(of_instruction_id_t *obj_p,
    of_version_t version, int bytes, int clean_wire)
{
    of_instruction_id_header_t *obj;

    obj = &obj_p->header;  /* Need instantiable subclass */

    LOCI_ASSERT(of_object_fixed_len[version][OF_INSTRUCTION_ID] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_INSTRUCTION_ID] + of_object_extra_len[version][OF_INSTRUCTION_ID];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_INSTRUCTION_ID;

    /* Set up the object's function pointers */

    obj->wire_length_get = of_tlv16_wire_length_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
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

static void
of_instruction_id_apply_actions_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x4); /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_instruction_id_apply_actions of_instruction_id_apply_actions
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_instruction_id_apply_actions_push_wire_values(of_instruction_id_apply_actions_t *obj)
{

    of_instruction_id_apply_actions_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_instruction_id_apply_actions object
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
 * \ingroup of_instruction_id_apply_actions
 */

of_instruction_id_apply_actions_t *
of_instruction_id_apply_actions_new(of_version_t version)
{
    of_instruction_id_apply_actions_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_INSTRUCTION_ID_APPLY_ACTIONS] + of_object_extra_len[version][OF_INSTRUCTION_ID_APPLY_ACTIONS];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_instruction_id_apply_actions_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_instruction_id_apply_actions_init(obj, version, bytes, 0);

    if (of_instruction_id_apply_actions_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_instruction_id_apply_actions.
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
of_instruction_id_apply_actions_init(of_instruction_id_apply_actions_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_INSTRUCTION_ID_APPLY_ACTIONS] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_INSTRUCTION_ID_APPLY_ACTIONS] + of_object_extra_len[version][OF_INSTRUCTION_ID_APPLY_ACTIONS];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_INSTRUCTION_ID_APPLY_ACTIONS;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_instruction_id_apply_actions_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
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


/**
 * \defgroup of_instruction_bsn of_instruction_bsn
 */

/**
 * Create a new of_instruction_bsn object
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
 * \ingroup of_instruction_bsn
 */

of_instruction_bsn_t *
of_instruction_bsn_new(of_version_t version)
{
    of_instruction_bsn_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_INSTRUCTION_BSN] + of_object_extra_len[version][OF_INSTRUCTION_BSN];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_instruction_bsn_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_instruction_bsn_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_instruction_bsn.
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
of_instruction_bsn_init(of_instruction_bsn_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_INSTRUCTION_BSN] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_INSTRUCTION_BSN] + of_object_extra_len[version][OF_INSTRUCTION_BSN];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_INSTRUCTION_BSN;

    /* Set up the object's function pointers */

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_instruction_wire_object_id_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get experimenter from an object of type of_instruction_bsn.
 * @param obj Pointer to an object of type of_instruction_bsn.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_instruction_bsn_experimenter_get(
    of_instruction_bsn_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_BSN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
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
 * Set experimenter in an object of type of_instruction_bsn.
 * @param obj Pointer to an object of type of_instruction_bsn.
 * @param experimenter The value to write into the object
 */
void
of_instruction_bsn_experimenter_set(
    of_instruction_bsn_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_BSN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
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
 * Get subtype from an object of type of_instruction_bsn.
 * @param obj Pointer to an object of type of_instruction_bsn.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_instruction_bsn_subtype_get(
    of_instruction_bsn_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_BSN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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
 * Set subtype in an object of type of_instruction_bsn.
 * @param obj Pointer to an object of type of_instruction_bsn.
 * @param subtype The value to write into the object
 */
void
of_instruction_bsn_subtype_set(
    of_instruction_bsn_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_BSN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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
 * \defgroup of_instruction_id_experimenter of_instruction_id_experimenter
 */

/**
 * Create a new of_instruction_id_experimenter object
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
 * \ingroup of_instruction_id_experimenter
 */

of_instruction_id_experimenter_t *
of_instruction_id_experimenter_new(of_version_t version)
{
    of_instruction_id_experimenter_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_INSTRUCTION_ID_EXPERIMENTER] + of_object_extra_len[version][OF_INSTRUCTION_ID_EXPERIMENTER];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_instruction_id_experimenter_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_instruction_id_experimenter_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_instruction_id_experimenter.
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
of_instruction_id_experimenter_init(of_instruction_id_experimenter_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_INSTRUCTION_ID_EXPERIMENTER] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_INSTRUCTION_ID_EXPERIMENTER] + of_object_extra_len[version][OF_INSTRUCTION_ID_EXPERIMENTER];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_INSTRUCTION_ID_EXPERIMENTER;

    /* Set up the object's function pointers */

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get experimenter from an object of type of_instruction_id_experimenter.
 * @param obj Pointer to an object of type of_instruction_id_experimenter.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_instruction_id_experimenter_experimenter_get(
    of_instruction_id_experimenter_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_ID_EXPERIMENTER);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
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
 * Set experimenter in an object of type of_instruction_id_experimenter.
 * @param obj Pointer to an object of type of_instruction_id_experimenter.
 * @param experimenter The value to write into the object
 */
void
of_instruction_id_experimenter_experimenter_set(
    of_instruction_id_experimenter_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_ID_EXPERIMENTER);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
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
 * \defgroup of_instruction_id_bsn of_instruction_id_bsn
 */

/**
 * Create a new of_instruction_id_bsn object
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
 * \ingroup of_instruction_id_bsn
 */

of_instruction_id_bsn_t *
of_instruction_id_bsn_new(of_version_t version)
{
    of_instruction_id_bsn_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_INSTRUCTION_ID_BSN] + of_object_extra_len[version][OF_INSTRUCTION_ID_BSN];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_instruction_id_bsn_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_instruction_id_bsn_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_instruction_id_bsn.
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
of_instruction_id_bsn_init(of_instruction_id_bsn_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_INSTRUCTION_ID_BSN] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_INSTRUCTION_ID_BSN] + of_object_extra_len[version][OF_INSTRUCTION_ID_BSN];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_INSTRUCTION_ID_BSN;

    /* Set up the object's function pointers */

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get experimenter from an object of type of_instruction_id_bsn.
 * @param obj Pointer to an object of type of_instruction_id_bsn.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_instruction_id_bsn_experimenter_get(
    of_instruction_id_bsn_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_ID_BSN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
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
 * Set experimenter in an object of type of_instruction_id_bsn.
 * @param obj Pointer to an object of type of_instruction_id_bsn.
 * @param experimenter The value to write into the object
 */
void
of_instruction_id_bsn_experimenter_set(
    of_instruction_id_bsn_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_ID_BSN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
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
 * Get subtype from an object of type of_instruction_id_bsn.
 * @param obj Pointer to an object of type of_instruction_id_bsn.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_instruction_id_bsn_subtype_get(
    of_instruction_id_bsn_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_ID_BSN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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
 * Set subtype in an object of type of_instruction_id_bsn.
 * @param obj Pointer to an object of type of_instruction_id_bsn.
 * @param subtype The value to write into the object
 */
void
of_instruction_id_bsn_subtype_set(
    of_instruction_id_bsn_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_ID_BSN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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

static void
of_instruction_bsn_arp_offload_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0xffff); /* type */
        *(uint32_t *)(buf + 4) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 8) = htobe32(0x1); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_instruction_bsn_arp_offload of_instruction_bsn_arp_offload
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_instruction_bsn_arp_offload_push_wire_values(of_instruction_bsn_arp_offload_t *obj)
{

    of_instruction_bsn_arp_offload_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_instruction_bsn_arp_offload object
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
 * \ingroup of_instruction_bsn_arp_offload
 */

of_instruction_bsn_arp_offload_t *
of_instruction_bsn_arp_offload_new(of_version_t version)
{
    of_instruction_bsn_arp_offload_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_INSTRUCTION_BSN_ARP_OFFLOAD] + of_object_extra_len[version][OF_INSTRUCTION_BSN_ARP_OFFLOAD];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_instruction_bsn_arp_offload_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_instruction_bsn_arp_offload_init(obj, version, bytes, 0);

    if (of_instruction_bsn_arp_offload_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_instruction_bsn_arp_offload.
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
of_instruction_bsn_arp_offload_init(of_instruction_bsn_arp_offload_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_INSTRUCTION_BSN_ARP_OFFLOAD] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_INSTRUCTION_BSN_ARP_OFFLOAD] + of_object_extra_len[version][OF_INSTRUCTION_BSN_ARP_OFFLOAD];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_INSTRUCTION_BSN_ARP_OFFLOAD;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_instruction_bsn_arp_offload_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_instruction_wire_object_id_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get experimenter from an object of type of_instruction_bsn_arp_offload.
 * @param obj Pointer to an object of type of_instruction_bsn_arp_offload.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_instruction_bsn_arp_offload_experimenter_get(
    of_instruction_bsn_arp_offload_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_BSN_ARP_OFFLOAD);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
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
 * Set experimenter in an object of type of_instruction_bsn_arp_offload.
 * @param obj Pointer to an object of type of_instruction_bsn_arp_offload.
 * @param experimenter The value to write into the object
 */
void
of_instruction_bsn_arp_offload_experimenter_set(
    of_instruction_bsn_arp_offload_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_BSN_ARP_OFFLOAD);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
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
 * Get subtype from an object of type of_instruction_bsn_arp_offload.
 * @param obj Pointer to an object of type of_instruction_bsn_arp_offload.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_instruction_bsn_arp_offload_subtype_get(
    of_instruction_bsn_arp_offload_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_BSN_ARP_OFFLOAD);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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
 * Set subtype in an object of type of_instruction_bsn_arp_offload.
 * @param obj Pointer to an object of type of_instruction_bsn_arp_offload.
 * @param subtype The value to write into the object
 */
void
of_instruction_bsn_arp_offload_subtype_set(
    of_instruction_bsn_arp_offload_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_BSN_ARP_OFFLOAD);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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

static void
of_instruction_id_bsn_arp_offload_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0xffff); /* type */
        *(uint32_t *)(buf + 4) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 8) = htobe32(0x1); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_instruction_id_bsn_arp_offload of_instruction_id_bsn_arp_offload
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_instruction_id_bsn_arp_offload_push_wire_values(of_instruction_id_bsn_arp_offload_t *obj)
{

    of_instruction_id_bsn_arp_offload_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_instruction_id_bsn_arp_offload object
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
 * \ingroup of_instruction_id_bsn_arp_offload
 */

of_instruction_id_bsn_arp_offload_t *
of_instruction_id_bsn_arp_offload_new(of_version_t version)
{
    of_instruction_id_bsn_arp_offload_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_INSTRUCTION_ID_BSN_ARP_OFFLOAD] + of_object_extra_len[version][OF_INSTRUCTION_ID_BSN_ARP_OFFLOAD];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_instruction_id_bsn_arp_offload_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_instruction_id_bsn_arp_offload_init(obj, version, bytes, 0);

    if (of_instruction_id_bsn_arp_offload_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_instruction_id_bsn_arp_offload.
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
of_instruction_id_bsn_arp_offload_init(of_instruction_id_bsn_arp_offload_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_INSTRUCTION_ID_BSN_ARP_OFFLOAD] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_INSTRUCTION_ID_BSN_ARP_OFFLOAD] + of_object_extra_len[version][OF_INSTRUCTION_ID_BSN_ARP_OFFLOAD];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_INSTRUCTION_ID_BSN_ARP_OFFLOAD;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_instruction_id_bsn_arp_offload_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get experimenter from an object of type of_instruction_id_bsn_arp_offload.
 * @param obj Pointer to an object of type of_instruction_id_bsn_arp_offload.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_instruction_id_bsn_arp_offload_experimenter_get(
    of_instruction_id_bsn_arp_offload_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_ID_BSN_ARP_OFFLOAD);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
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
 * Set experimenter in an object of type of_instruction_id_bsn_arp_offload.
 * @param obj Pointer to an object of type of_instruction_id_bsn_arp_offload.
 * @param experimenter The value to write into the object
 */
void
of_instruction_id_bsn_arp_offload_experimenter_set(
    of_instruction_id_bsn_arp_offload_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_ID_BSN_ARP_OFFLOAD);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
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
 * Get subtype from an object of type of_instruction_id_bsn_arp_offload.
 * @param obj Pointer to an object of type of_instruction_id_bsn_arp_offload.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_instruction_id_bsn_arp_offload_subtype_get(
    of_instruction_id_bsn_arp_offload_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_ID_BSN_ARP_OFFLOAD);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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
 * Set subtype in an object of type of_instruction_id_bsn_arp_offload.
 * @param obj Pointer to an object of type of_instruction_id_bsn_arp_offload.
 * @param subtype The value to write into the object
 */
void
of_instruction_id_bsn_arp_offload_subtype_set(
    of_instruction_id_bsn_arp_offload_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_ID_BSN_ARP_OFFLOAD);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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

static void
of_instruction_bsn_deny_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0xffff); /* type */
        *(uint32_t *)(buf + 4) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 8) = htobe32(0x5); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_instruction_bsn_deny of_instruction_bsn_deny
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_instruction_bsn_deny_push_wire_values(of_instruction_bsn_deny_t *obj)
{

    of_instruction_bsn_deny_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_instruction_bsn_deny object
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
 * \ingroup of_instruction_bsn_deny
 */

of_instruction_bsn_deny_t *
of_instruction_bsn_deny_new(of_version_t version)
{
    of_instruction_bsn_deny_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_INSTRUCTION_BSN_DENY] + of_object_extra_len[version][OF_INSTRUCTION_BSN_DENY];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_instruction_bsn_deny_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_instruction_bsn_deny_init(obj, version, bytes, 0);

    if (of_instruction_bsn_deny_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_instruction_bsn_deny.
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
of_instruction_bsn_deny_init(of_instruction_bsn_deny_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_INSTRUCTION_BSN_DENY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_INSTRUCTION_BSN_DENY] + of_object_extra_len[version][OF_INSTRUCTION_BSN_DENY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_INSTRUCTION_BSN_DENY;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_instruction_bsn_deny_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_instruction_wire_object_id_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get experimenter from an object of type of_instruction_bsn_deny.
 * @param obj Pointer to an object of type of_instruction_bsn_deny.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_instruction_bsn_deny_experimenter_get(
    of_instruction_bsn_deny_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_BSN_DENY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
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
 * Set experimenter in an object of type of_instruction_bsn_deny.
 * @param obj Pointer to an object of type of_instruction_bsn_deny.
 * @param experimenter The value to write into the object
 */
void
of_instruction_bsn_deny_experimenter_set(
    of_instruction_bsn_deny_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_BSN_DENY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
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
 * Get subtype from an object of type of_instruction_bsn_deny.
 * @param obj Pointer to an object of type of_instruction_bsn_deny.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_instruction_bsn_deny_subtype_get(
    of_instruction_bsn_deny_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_BSN_DENY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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
 * Set subtype in an object of type of_instruction_bsn_deny.
 * @param obj Pointer to an object of type of_instruction_bsn_deny.
 * @param subtype The value to write into the object
 */
void
of_instruction_bsn_deny_subtype_set(
    of_instruction_bsn_deny_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_BSN_DENY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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

static void
of_instruction_id_bsn_deny_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0xffff); /* type */
        *(uint32_t *)(buf + 4) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 8) = htobe32(0x5); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_instruction_id_bsn_deny of_instruction_id_bsn_deny
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_instruction_id_bsn_deny_push_wire_values(of_instruction_id_bsn_deny_t *obj)
{

    of_instruction_id_bsn_deny_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_instruction_id_bsn_deny object
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
 * \ingroup of_instruction_id_bsn_deny
 */

of_instruction_id_bsn_deny_t *
of_instruction_id_bsn_deny_new(of_version_t version)
{
    of_instruction_id_bsn_deny_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_INSTRUCTION_ID_BSN_DENY] + of_object_extra_len[version][OF_INSTRUCTION_ID_BSN_DENY];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_instruction_id_bsn_deny_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_instruction_id_bsn_deny_init(obj, version, bytes, 0);

    if (of_instruction_id_bsn_deny_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_instruction_id_bsn_deny.
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
of_instruction_id_bsn_deny_init(of_instruction_id_bsn_deny_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_INSTRUCTION_ID_BSN_DENY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_INSTRUCTION_ID_BSN_DENY] + of_object_extra_len[version][OF_INSTRUCTION_ID_BSN_DENY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_INSTRUCTION_ID_BSN_DENY;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_instruction_id_bsn_deny_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get experimenter from an object of type of_instruction_id_bsn_deny.
 * @param obj Pointer to an object of type of_instruction_id_bsn_deny.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_instruction_id_bsn_deny_experimenter_get(
    of_instruction_id_bsn_deny_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_ID_BSN_DENY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
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
 * Set experimenter in an object of type of_instruction_id_bsn_deny.
 * @param obj Pointer to an object of type of_instruction_id_bsn_deny.
 * @param experimenter The value to write into the object
 */
void
of_instruction_id_bsn_deny_experimenter_set(
    of_instruction_id_bsn_deny_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_ID_BSN_DENY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
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
 * Get subtype from an object of type of_instruction_id_bsn_deny.
 * @param obj Pointer to an object of type of_instruction_id_bsn_deny.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_instruction_id_bsn_deny_subtype_get(
    of_instruction_id_bsn_deny_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_ID_BSN_DENY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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
 * Set subtype in an object of type of_instruction_id_bsn_deny.
 * @param obj Pointer to an object of type of_instruction_id_bsn_deny.
 * @param subtype The value to write into the object
 */
void
of_instruction_id_bsn_deny_subtype_set(
    of_instruction_id_bsn_deny_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_ID_BSN_DENY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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

static void
of_instruction_bsn_dhcp_offload_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0xffff); /* type */
        *(uint32_t *)(buf + 4) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 8) = htobe32(0x2); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_instruction_bsn_dhcp_offload of_instruction_bsn_dhcp_offload
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_instruction_bsn_dhcp_offload_push_wire_values(of_instruction_bsn_dhcp_offload_t *obj)
{

    of_instruction_bsn_dhcp_offload_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_instruction_bsn_dhcp_offload object
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
 * \ingroup of_instruction_bsn_dhcp_offload
 */

of_instruction_bsn_dhcp_offload_t *
of_instruction_bsn_dhcp_offload_new(of_version_t version)
{
    of_instruction_bsn_dhcp_offload_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_INSTRUCTION_BSN_DHCP_OFFLOAD] + of_object_extra_len[version][OF_INSTRUCTION_BSN_DHCP_OFFLOAD];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_instruction_bsn_dhcp_offload_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_instruction_bsn_dhcp_offload_init(obj, version, bytes, 0);

    if (of_instruction_bsn_dhcp_offload_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_instruction_bsn_dhcp_offload.
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
of_instruction_bsn_dhcp_offload_init(of_instruction_bsn_dhcp_offload_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_INSTRUCTION_BSN_DHCP_OFFLOAD] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_INSTRUCTION_BSN_DHCP_OFFLOAD] + of_object_extra_len[version][OF_INSTRUCTION_BSN_DHCP_OFFLOAD];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_INSTRUCTION_BSN_DHCP_OFFLOAD;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_instruction_bsn_dhcp_offload_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_instruction_wire_object_id_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get experimenter from an object of type of_instruction_bsn_dhcp_offload.
 * @param obj Pointer to an object of type of_instruction_bsn_dhcp_offload.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_instruction_bsn_dhcp_offload_experimenter_get(
    of_instruction_bsn_dhcp_offload_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_BSN_DHCP_OFFLOAD);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
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
 * Set experimenter in an object of type of_instruction_bsn_dhcp_offload.
 * @param obj Pointer to an object of type of_instruction_bsn_dhcp_offload.
 * @param experimenter The value to write into the object
 */
void
of_instruction_bsn_dhcp_offload_experimenter_set(
    of_instruction_bsn_dhcp_offload_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_BSN_DHCP_OFFLOAD);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
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
 * Get subtype from an object of type of_instruction_bsn_dhcp_offload.
 * @param obj Pointer to an object of type of_instruction_bsn_dhcp_offload.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_instruction_bsn_dhcp_offload_subtype_get(
    of_instruction_bsn_dhcp_offload_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_BSN_DHCP_OFFLOAD);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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
 * Set subtype in an object of type of_instruction_bsn_dhcp_offload.
 * @param obj Pointer to an object of type of_instruction_bsn_dhcp_offload.
 * @param subtype The value to write into the object
 */
void
of_instruction_bsn_dhcp_offload_subtype_set(
    of_instruction_bsn_dhcp_offload_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_BSN_DHCP_OFFLOAD);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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

static void
of_instruction_id_bsn_dhcp_offload_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0xffff); /* type */
        *(uint32_t *)(buf + 4) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 8) = htobe32(0x2); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_instruction_id_bsn_dhcp_offload of_instruction_id_bsn_dhcp_offload
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_instruction_id_bsn_dhcp_offload_push_wire_values(of_instruction_id_bsn_dhcp_offload_t *obj)
{

    of_instruction_id_bsn_dhcp_offload_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_instruction_id_bsn_dhcp_offload object
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
 * \ingroup of_instruction_id_bsn_dhcp_offload
 */

of_instruction_id_bsn_dhcp_offload_t *
of_instruction_id_bsn_dhcp_offload_new(of_version_t version)
{
    of_instruction_id_bsn_dhcp_offload_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_INSTRUCTION_ID_BSN_DHCP_OFFLOAD] + of_object_extra_len[version][OF_INSTRUCTION_ID_BSN_DHCP_OFFLOAD];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_instruction_id_bsn_dhcp_offload_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_instruction_id_bsn_dhcp_offload_init(obj, version, bytes, 0);

    if (of_instruction_id_bsn_dhcp_offload_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_instruction_id_bsn_dhcp_offload.
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
of_instruction_id_bsn_dhcp_offload_init(of_instruction_id_bsn_dhcp_offload_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_INSTRUCTION_ID_BSN_DHCP_OFFLOAD] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_INSTRUCTION_ID_BSN_DHCP_OFFLOAD] + of_object_extra_len[version][OF_INSTRUCTION_ID_BSN_DHCP_OFFLOAD];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_INSTRUCTION_ID_BSN_DHCP_OFFLOAD;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_instruction_id_bsn_dhcp_offload_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get experimenter from an object of type of_instruction_id_bsn_dhcp_offload.
 * @param obj Pointer to an object of type of_instruction_id_bsn_dhcp_offload.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_instruction_id_bsn_dhcp_offload_experimenter_get(
    of_instruction_id_bsn_dhcp_offload_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_ID_BSN_DHCP_OFFLOAD);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
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
 * Set experimenter in an object of type of_instruction_id_bsn_dhcp_offload.
 * @param obj Pointer to an object of type of_instruction_id_bsn_dhcp_offload.
 * @param experimenter The value to write into the object
 */
void
of_instruction_id_bsn_dhcp_offload_experimenter_set(
    of_instruction_id_bsn_dhcp_offload_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_ID_BSN_DHCP_OFFLOAD);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
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
 * Get subtype from an object of type of_instruction_id_bsn_dhcp_offload.
 * @param obj Pointer to an object of type of_instruction_id_bsn_dhcp_offload.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_instruction_id_bsn_dhcp_offload_subtype_get(
    of_instruction_id_bsn_dhcp_offload_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_ID_BSN_DHCP_OFFLOAD);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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
 * Set subtype in an object of type of_instruction_id_bsn_dhcp_offload.
 * @param obj Pointer to an object of type of_instruction_id_bsn_dhcp_offload.
 * @param subtype The value to write into the object
 */
void
of_instruction_id_bsn_dhcp_offload_subtype_set(
    of_instruction_id_bsn_dhcp_offload_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_ID_BSN_DHCP_OFFLOAD);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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

static void
of_instruction_bsn_disable_split_horizon_check_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0xffff); /* type */
        *(uint32_t *)(buf + 4) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 8) = htobe32(0x3); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_instruction_bsn_disable_split_horizon_check of_instruction_bsn_disable_split_horizon_check
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_instruction_bsn_disable_split_horizon_check_push_wire_values(of_instruction_bsn_disable_split_horizon_check_t *obj)
{

    of_instruction_bsn_disable_split_horizon_check_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_instruction_bsn_disable_split_horizon_check object
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
 * \ingroup of_instruction_bsn_disable_split_horizon_check
 */

of_instruction_bsn_disable_split_horizon_check_t *
of_instruction_bsn_disable_split_horizon_check_new(of_version_t version)
{
    of_instruction_bsn_disable_split_horizon_check_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_INSTRUCTION_BSN_DISABLE_SPLIT_HORIZON_CHECK] + of_object_extra_len[version][OF_INSTRUCTION_BSN_DISABLE_SPLIT_HORIZON_CHECK];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_instruction_bsn_disable_split_horizon_check_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_instruction_bsn_disable_split_horizon_check_init(obj, version, bytes, 0);

    if (of_instruction_bsn_disable_split_horizon_check_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_instruction_bsn_disable_split_horizon_check.
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
of_instruction_bsn_disable_split_horizon_check_init(of_instruction_bsn_disable_split_horizon_check_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_INSTRUCTION_BSN_DISABLE_SPLIT_HORIZON_CHECK] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_INSTRUCTION_BSN_DISABLE_SPLIT_HORIZON_CHECK] + of_object_extra_len[version][OF_INSTRUCTION_BSN_DISABLE_SPLIT_HORIZON_CHECK];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_INSTRUCTION_BSN_DISABLE_SPLIT_HORIZON_CHECK;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_instruction_bsn_disable_split_horizon_check_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_instruction_wire_object_id_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get experimenter from an object of type of_instruction_bsn_disable_split_horizon_check.
 * @param obj Pointer to an object of type of_instruction_bsn_disable_split_horizon_check.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_instruction_bsn_disable_split_horizon_check_experimenter_get(
    of_instruction_bsn_disable_split_horizon_check_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_BSN_DISABLE_SPLIT_HORIZON_CHECK);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
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
 * Set experimenter in an object of type of_instruction_bsn_disable_split_horizon_check.
 * @param obj Pointer to an object of type of_instruction_bsn_disable_split_horizon_check.
 * @param experimenter The value to write into the object
 */
void
of_instruction_bsn_disable_split_horizon_check_experimenter_set(
    of_instruction_bsn_disable_split_horizon_check_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_BSN_DISABLE_SPLIT_HORIZON_CHECK);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
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
 * Get subtype from an object of type of_instruction_bsn_disable_split_horizon_check.
 * @param obj Pointer to an object of type of_instruction_bsn_disable_split_horizon_check.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_instruction_bsn_disable_split_horizon_check_subtype_get(
    of_instruction_bsn_disable_split_horizon_check_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_BSN_DISABLE_SPLIT_HORIZON_CHECK);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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
 * Set subtype in an object of type of_instruction_bsn_disable_split_horizon_check.
 * @param obj Pointer to an object of type of_instruction_bsn_disable_split_horizon_check.
 * @param subtype The value to write into the object
 */
void
of_instruction_bsn_disable_split_horizon_check_subtype_set(
    of_instruction_bsn_disable_split_horizon_check_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_BSN_DISABLE_SPLIT_HORIZON_CHECK);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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

static void
of_instruction_id_bsn_disable_split_horizon_check_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0xffff); /* type */
        *(uint32_t *)(buf + 4) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 8) = htobe32(0x3); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_instruction_id_bsn_disable_split_horizon_check of_instruction_id_bsn_disable_split_horizon_check
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_instruction_id_bsn_disable_split_horizon_check_push_wire_values(of_instruction_id_bsn_disable_split_horizon_check_t *obj)
{

    of_instruction_id_bsn_disable_split_horizon_check_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_instruction_id_bsn_disable_split_horizon_check object
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
 * \ingroup of_instruction_id_bsn_disable_split_horizon_check
 */

of_instruction_id_bsn_disable_split_horizon_check_t *
of_instruction_id_bsn_disable_split_horizon_check_new(of_version_t version)
{
    of_instruction_id_bsn_disable_split_horizon_check_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_INSTRUCTION_ID_BSN_DISABLE_SPLIT_HORIZON_CHECK] + of_object_extra_len[version][OF_INSTRUCTION_ID_BSN_DISABLE_SPLIT_HORIZON_CHECK];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_instruction_id_bsn_disable_split_horizon_check_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_instruction_id_bsn_disable_split_horizon_check_init(obj, version, bytes, 0);

    if (of_instruction_id_bsn_disable_split_horizon_check_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_instruction_id_bsn_disable_split_horizon_check.
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
of_instruction_id_bsn_disable_split_horizon_check_init(of_instruction_id_bsn_disable_split_horizon_check_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_INSTRUCTION_ID_BSN_DISABLE_SPLIT_HORIZON_CHECK] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_INSTRUCTION_ID_BSN_DISABLE_SPLIT_HORIZON_CHECK] + of_object_extra_len[version][OF_INSTRUCTION_ID_BSN_DISABLE_SPLIT_HORIZON_CHECK];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_INSTRUCTION_ID_BSN_DISABLE_SPLIT_HORIZON_CHECK;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_instruction_id_bsn_disable_split_horizon_check_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get experimenter from an object of type of_instruction_id_bsn_disable_split_horizon_check.
 * @param obj Pointer to an object of type of_instruction_id_bsn_disable_split_horizon_check.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_instruction_id_bsn_disable_split_horizon_check_experimenter_get(
    of_instruction_id_bsn_disable_split_horizon_check_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_ID_BSN_DISABLE_SPLIT_HORIZON_CHECK);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
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
 * Set experimenter in an object of type of_instruction_id_bsn_disable_split_horizon_check.
 * @param obj Pointer to an object of type of_instruction_id_bsn_disable_split_horizon_check.
 * @param experimenter The value to write into the object
 */
void
of_instruction_id_bsn_disable_split_horizon_check_experimenter_set(
    of_instruction_id_bsn_disable_split_horizon_check_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_ID_BSN_DISABLE_SPLIT_HORIZON_CHECK);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
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
 * Get subtype from an object of type of_instruction_id_bsn_disable_split_horizon_check.
 * @param obj Pointer to an object of type of_instruction_id_bsn_disable_split_horizon_check.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_instruction_id_bsn_disable_split_horizon_check_subtype_get(
    of_instruction_id_bsn_disable_split_horizon_check_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_ID_BSN_DISABLE_SPLIT_HORIZON_CHECK);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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
 * Set subtype in an object of type of_instruction_id_bsn_disable_split_horizon_check.
 * @param obj Pointer to an object of type of_instruction_id_bsn_disable_split_horizon_check.
 * @param subtype The value to write into the object
 */
void
of_instruction_id_bsn_disable_split_horizon_check_subtype_set(
    of_instruction_id_bsn_disable_split_horizon_check_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_ID_BSN_DISABLE_SPLIT_HORIZON_CHECK);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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

static void
of_instruction_bsn_disable_src_mac_check_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0xffff); /* type */
        *(uint32_t *)(buf + 4) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 8) = htobe32(0x0); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_instruction_bsn_disable_src_mac_check of_instruction_bsn_disable_src_mac_check
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_instruction_bsn_disable_src_mac_check_push_wire_values(of_instruction_bsn_disable_src_mac_check_t *obj)
{

    of_instruction_bsn_disable_src_mac_check_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_instruction_bsn_disable_src_mac_check object
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
 * \ingroup of_instruction_bsn_disable_src_mac_check
 */

of_instruction_bsn_disable_src_mac_check_t *
of_instruction_bsn_disable_src_mac_check_new(of_version_t version)
{
    of_instruction_bsn_disable_src_mac_check_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_INSTRUCTION_BSN_DISABLE_SRC_MAC_CHECK] + of_object_extra_len[version][OF_INSTRUCTION_BSN_DISABLE_SRC_MAC_CHECK];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_instruction_bsn_disable_src_mac_check_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_instruction_bsn_disable_src_mac_check_init(obj, version, bytes, 0);

    if (of_instruction_bsn_disable_src_mac_check_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_instruction_bsn_disable_src_mac_check.
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
of_instruction_bsn_disable_src_mac_check_init(of_instruction_bsn_disable_src_mac_check_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_INSTRUCTION_BSN_DISABLE_SRC_MAC_CHECK] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_INSTRUCTION_BSN_DISABLE_SRC_MAC_CHECK] + of_object_extra_len[version][OF_INSTRUCTION_BSN_DISABLE_SRC_MAC_CHECK];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_INSTRUCTION_BSN_DISABLE_SRC_MAC_CHECK;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_instruction_bsn_disable_src_mac_check_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_instruction_wire_object_id_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get experimenter from an object of type of_instruction_bsn_disable_src_mac_check.
 * @param obj Pointer to an object of type of_instruction_bsn_disable_src_mac_check.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_instruction_bsn_disable_src_mac_check_experimenter_get(
    of_instruction_bsn_disable_src_mac_check_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_BSN_DISABLE_SRC_MAC_CHECK);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
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
 * Set experimenter in an object of type of_instruction_bsn_disable_src_mac_check.
 * @param obj Pointer to an object of type of_instruction_bsn_disable_src_mac_check.
 * @param experimenter The value to write into the object
 */
void
of_instruction_bsn_disable_src_mac_check_experimenter_set(
    of_instruction_bsn_disable_src_mac_check_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_BSN_DISABLE_SRC_MAC_CHECK);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
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
 * Get subtype from an object of type of_instruction_bsn_disable_src_mac_check.
 * @param obj Pointer to an object of type of_instruction_bsn_disable_src_mac_check.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_instruction_bsn_disable_src_mac_check_subtype_get(
    of_instruction_bsn_disable_src_mac_check_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_BSN_DISABLE_SRC_MAC_CHECK);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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
 * Set subtype in an object of type of_instruction_bsn_disable_src_mac_check.
 * @param obj Pointer to an object of type of_instruction_bsn_disable_src_mac_check.
 * @param subtype The value to write into the object
 */
void
of_instruction_bsn_disable_src_mac_check_subtype_set(
    of_instruction_bsn_disable_src_mac_check_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_BSN_DISABLE_SRC_MAC_CHECK);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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

static void
of_instruction_id_bsn_disable_src_mac_check_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0xffff); /* type */
        *(uint32_t *)(buf + 4) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 8) = htobe32(0x0); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_instruction_id_bsn_disable_src_mac_check of_instruction_id_bsn_disable_src_mac_check
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_instruction_id_bsn_disable_src_mac_check_push_wire_values(of_instruction_id_bsn_disable_src_mac_check_t *obj)
{

    of_instruction_id_bsn_disable_src_mac_check_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_instruction_id_bsn_disable_src_mac_check object
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
 * \ingroup of_instruction_id_bsn_disable_src_mac_check
 */

of_instruction_id_bsn_disable_src_mac_check_t *
of_instruction_id_bsn_disable_src_mac_check_new(of_version_t version)
{
    of_instruction_id_bsn_disable_src_mac_check_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_INSTRUCTION_ID_BSN_DISABLE_SRC_MAC_CHECK] + of_object_extra_len[version][OF_INSTRUCTION_ID_BSN_DISABLE_SRC_MAC_CHECK];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_instruction_id_bsn_disable_src_mac_check_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_instruction_id_bsn_disable_src_mac_check_init(obj, version, bytes, 0);

    if (of_instruction_id_bsn_disable_src_mac_check_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_instruction_id_bsn_disable_src_mac_check.
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
of_instruction_id_bsn_disable_src_mac_check_init(of_instruction_id_bsn_disable_src_mac_check_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_INSTRUCTION_ID_BSN_DISABLE_SRC_MAC_CHECK] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_INSTRUCTION_ID_BSN_DISABLE_SRC_MAC_CHECK] + of_object_extra_len[version][OF_INSTRUCTION_ID_BSN_DISABLE_SRC_MAC_CHECK];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_INSTRUCTION_ID_BSN_DISABLE_SRC_MAC_CHECK;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_instruction_id_bsn_disable_src_mac_check_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get experimenter from an object of type of_instruction_id_bsn_disable_src_mac_check.
 * @param obj Pointer to an object of type of_instruction_id_bsn_disable_src_mac_check.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_instruction_id_bsn_disable_src_mac_check_experimenter_get(
    of_instruction_id_bsn_disable_src_mac_check_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_ID_BSN_DISABLE_SRC_MAC_CHECK);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
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
 * Set experimenter in an object of type of_instruction_id_bsn_disable_src_mac_check.
 * @param obj Pointer to an object of type of_instruction_id_bsn_disable_src_mac_check.
 * @param experimenter The value to write into the object
 */
void
of_instruction_id_bsn_disable_src_mac_check_experimenter_set(
    of_instruction_id_bsn_disable_src_mac_check_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_ID_BSN_DISABLE_SRC_MAC_CHECK);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
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
 * Get subtype from an object of type of_instruction_id_bsn_disable_src_mac_check.
 * @param obj Pointer to an object of type of_instruction_id_bsn_disable_src_mac_check.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_instruction_id_bsn_disable_src_mac_check_subtype_get(
    of_instruction_id_bsn_disable_src_mac_check_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_ID_BSN_DISABLE_SRC_MAC_CHECK);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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
 * Set subtype in an object of type of_instruction_id_bsn_disable_src_mac_check.
 * @param obj Pointer to an object of type of_instruction_id_bsn_disable_src_mac_check.
 * @param subtype The value to write into the object
 */
void
of_instruction_id_bsn_disable_src_mac_check_subtype_set(
    of_instruction_id_bsn_disable_src_mac_check_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_ID_BSN_DISABLE_SRC_MAC_CHECK);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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

static void
of_instruction_bsn_permit_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0xffff); /* type */
        *(uint32_t *)(buf + 4) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 8) = htobe32(0x4); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_instruction_bsn_permit of_instruction_bsn_permit
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_instruction_bsn_permit_push_wire_values(of_instruction_bsn_permit_t *obj)
{

    of_instruction_bsn_permit_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_instruction_bsn_permit object
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
 * \ingroup of_instruction_bsn_permit
 */

of_instruction_bsn_permit_t *
of_instruction_bsn_permit_new(of_version_t version)
{
    of_instruction_bsn_permit_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_INSTRUCTION_BSN_PERMIT] + of_object_extra_len[version][OF_INSTRUCTION_BSN_PERMIT];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_instruction_bsn_permit_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_instruction_bsn_permit_init(obj, version, bytes, 0);

    if (of_instruction_bsn_permit_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_instruction_bsn_permit.
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
of_instruction_bsn_permit_init(of_instruction_bsn_permit_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_INSTRUCTION_BSN_PERMIT] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_INSTRUCTION_BSN_PERMIT] + of_object_extra_len[version][OF_INSTRUCTION_BSN_PERMIT];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_INSTRUCTION_BSN_PERMIT;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_instruction_bsn_permit_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_instruction_wire_object_id_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get experimenter from an object of type of_instruction_bsn_permit.
 * @param obj Pointer to an object of type of_instruction_bsn_permit.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_instruction_bsn_permit_experimenter_get(
    of_instruction_bsn_permit_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_BSN_PERMIT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
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
 * Set experimenter in an object of type of_instruction_bsn_permit.
 * @param obj Pointer to an object of type of_instruction_bsn_permit.
 * @param experimenter The value to write into the object
 */
void
of_instruction_bsn_permit_experimenter_set(
    of_instruction_bsn_permit_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_BSN_PERMIT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
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
 * Get subtype from an object of type of_instruction_bsn_permit.
 * @param obj Pointer to an object of type of_instruction_bsn_permit.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_instruction_bsn_permit_subtype_get(
    of_instruction_bsn_permit_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_BSN_PERMIT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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
 * Set subtype in an object of type of_instruction_bsn_permit.
 * @param obj Pointer to an object of type of_instruction_bsn_permit.
 * @param subtype The value to write into the object
 */
void
of_instruction_bsn_permit_subtype_set(
    of_instruction_bsn_permit_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_BSN_PERMIT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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

static void
of_instruction_id_bsn_permit_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0xffff); /* type */
        *(uint32_t *)(buf + 4) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 8) = htobe32(0x4); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_instruction_id_bsn_permit of_instruction_id_bsn_permit
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_instruction_id_bsn_permit_push_wire_values(of_instruction_id_bsn_permit_t *obj)
{

    of_instruction_id_bsn_permit_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_instruction_id_bsn_permit object
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
 * \ingroup of_instruction_id_bsn_permit
 */

of_instruction_id_bsn_permit_t *
of_instruction_id_bsn_permit_new(of_version_t version)
{
    of_instruction_id_bsn_permit_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_INSTRUCTION_ID_BSN_PERMIT] + of_object_extra_len[version][OF_INSTRUCTION_ID_BSN_PERMIT];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_instruction_id_bsn_permit_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_instruction_id_bsn_permit_init(obj, version, bytes, 0);

    if (of_instruction_id_bsn_permit_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_instruction_id_bsn_permit.
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
of_instruction_id_bsn_permit_init(of_instruction_id_bsn_permit_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_INSTRUCTION_ID_BSN_PERMIT] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_INSTRUCTION_ID_BSN_PERMIT] + of_object_extra_len[version][OF_INSTRUCTION_ID_BSN_PERMIT];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_INSTRUCTION_ID_BSN_PERMIT;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_instruction_id_bsn_permit_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get experimenter from an object of type of_instruction_id_bsn_permit.
 * @param obj Pointer to an object of type of_instruction_id_bsn_permit.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_instruction_id_bsn_permit_experimenter_get(
    of_instruction_id_bsn_permit_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_ID_BSN_PERMIT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
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
 * Set experimenter in an object of type of_instruction_id_bsn_permit.
 * @param obj Pointer to an object of type of_instruction_id_bsn_permit.
 * @param experimenter The value to write into the object
 */
void
of_instruction_id_bsn_permit_experimenter_set(
    of_instruction_id_bsn_permit_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_ID_BSN_PERMIT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
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
 * Get subtype from an object of type of_instruction_id_bsn_permit.
 * @param obj Pointer to an object of type of_instruction_id_bsn_permit.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_instruction_id_bsn_permit_subtype_get(
    of_instruction_id_bsn_permit_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_ID_BSN_PERMIT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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
 * Set subtype in an object of type of_instruction_id_bsn_permit.
 * @param obj Pointer to an object of type of_instruction_id_bsn_permit.
 * @param subtype The value to write into the object
 */
void
of_instruction_id_bsn_permit_subtype_set(
    of_instruction_id_bsn_permit_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_ID_BSN_PERMIT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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

static void
of_instruction_id_clear_actions_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x5); /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_instruction_id_clear_actions of_instruction_id_clear_actions
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_instruction_id_clear_actions_push_wire_values(of_instruction_id_clear_actions_t *obj)
{

    of_instruction_id_clear_actions_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_instruction_id_clear_actions object
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
 * \ingroup of_instruction_id_clear_actions
 */

of_instruction_id_clear_actions_t *
of_instruction_id_clear_actions_new(of_version_t version)
{
    of_instruction_id_clear_actions_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_INSTRUCTION_ID_CLEAR_ACTIONS] + of_object_extra_len[version][OF_INSTRUCTION_ID_CLEAR_ACTIONS];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_instruction_id_clear_actions_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_instruction_id_clear_actions_init(obj, version, bytes, 0);

    if (of_instruction_id_clear_actions_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_instruction_id_clear_actions.
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
of_instruction_id_clear_actions_init(of_instruction_id_clear_actions_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_INSTRUCTION_ID_CLEAR_ACTIONS] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_INSTRUCTION_ID_CLEAR_ACTIONS] + of_object_extra_len[version][OF_INSTRUCTION_ID_CLEAR_ACTIONS];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_INSTRUCTION_ID_CLEAR_ACTIONS;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_instruction_id_clear_actions_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
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

static void
of_instruction_id_goto_table_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x1); /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_instruction_id_goto_table of_instruction_id_goto_table
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_instruction_id_goto_table_push_wire_values(of_instruction_id_goto_table_t *obj)
{

    of_instruction_id_goto_table_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_instruction_id_goto_table object
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
 * \ingroup of_instruction_id_goto_table
 */

of_instruction_id_goto_table_t *
of_instruction_id_goto_table_new(of_version_t version)
{
    of_instruction_id_goto_table_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_INSTRUCTION_ID_GOTO_TABLE] + of_object_extra_len[version][OF_INSTRUCTION_ID_GOTO_TABLE];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_instruction_id_goto_table_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_instruction_id_goto_table_init(obj, version, bytes, 0);

    if (of_instruction_id_goto_table_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_instruction_id_goto_table.
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
of_instruction_id_goto_table_init(of_instruction_id_goto_table_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_INSTRUCTION_ID_GOTO_TABLE] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_INSTRUCTION_ID_GOTO_TABLE] + of_object_extra_len[version][OF_INSTRUCTION_ID_GOTO_TABLE];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_INSTRUCTION_ID_GOTO_TABLE;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_instruction_id_goto_table_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
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

static void
of_instruction_meter_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x6); /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_instruction_meter of_instruction_meter
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_instruction_meter_push_wire_values(of_instruction_meter_t *obj)
{

    of_instruction_meter_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_instruction_meter object
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
 * \ingroup of_instruction_meter
 */

of_instruction_meter_t *
of_instruction_meter_new(of_version_t version)
{
    of_instruction_meter_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_INSTRUCTION_METER] + of_object_extra_len[version][OF_INSTRUCTION_METER];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_instruction_meter_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_instruction_meter_init(obj, version, bytes, 0);

    if (of_instruction_meter_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_instruction_meter.
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
of_instruction_meter_init(of_instruction_meter_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_INSTRUCTION_METER] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_INSTRUCTION_METER] + of_object_extra_len[version][OF_INSTRUCTION_METER];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_INSTRUCTION_METER;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_instruction_meter_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_instruction_wire_object_id_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get meter_id from an object of type of_instruction_meter.
 * @param obj Pointer to an object of type of_instruction_meter.
 * @param meter_id Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_instruction_meter_meter_id_get(
    of_instruction_meter_t *obj,
    uint32_t *meter_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_METER);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, meter_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set meter_id in an object of type of_instruction_meter.
 * @param obj Pointer to an object of type of_instruction_meter.
 * @param meter_id The value to write into the object
 */
void
of_instruction_meter_meter_id_set(
    of_instruction_meter_t *obj,
    uint32_t meter_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_METER);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, meter_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
