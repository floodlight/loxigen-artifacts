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
 * \defgroup of_bsn_unit of_bsn_unit
 */

/**
 * Create a new of_bsn_unit object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_unit
 */

of_object_t *
of_bsn_unit_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_UNIT];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_unit_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_bsn_unit.
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
of_bsn_unit_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_UNIT] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_UNIT];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_UNIT;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_bsn_unit.
 * @param obj Pointer to an object of type of_bsn_unit.
 * @param value Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_unit_value_get(
    of_bsn_unit_t *obj,
    uint32_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_UNIT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 0;
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
 * Set value in an object of type of_bsn_unit.
 * @param obj Pointer to an object of type of_bsn_unit.
 * @param value The value to write into the object
 */
void
of_bsn_unit_value_set(
    of_bsn_unit_t *obj,
    uint32_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_UNIT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 0;
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

/**
 * Get unit from an object of type of_bsn_unit.
 * @param obj Pointer to an object of type of_bsn_unit.
 * @param unit Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_bsn_unit_unit_get(
    of_bsn_unit_t *obj,
    uint8_t *unit)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_UNIT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, unit);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set unit in an object of type of_bsn_unit.
 * @param obj Pointer to an object of type of_bsn_unit.
 * @param unit The value to write into the object
 */
void
of_bsn_unit_unit_set(
    of_bsn_unit_t *obj,
    uint8_t unit)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_UNIT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, unit);

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
of_bundle_add_msg_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_4:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x22; /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bundle_add_msg of_bundle_add_msg
 */

/**
 * Create a new of_bundle_add_msg object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bundle_add_msg
 */

of_object_t *
of_bundle_add_msg_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BUNDLE_ADD_MSG];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bundle_add_msg_init(obj, version, bytes, 0);
    of_bundle_add_msg_push_wire_types(obj);
    of_object_message_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bundle_add_msg.
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
of_bundle_add_msg_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BUNDLE_ADD_MSG] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BUNDLE_ADD_MSG];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BUNDLE_ADD_MSG;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_bundle_add_msg.
 * @param obj Pointer to an object of type of_bundle_add_msg.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bundle_add_msg_xid_get(
    of_bundle_add_msg_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BUNDLE_ADD_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
 * Set xid in an object of type of_bundle_add_msg.
 * @param obj Pointer to an object of type of_bundle_add_msg.
 * @param xid The value to write into the object
 */
void
of_bundle_add_msg_xid_set(
    of_bundle_add_msg_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BUNDLE_ADD_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
 * Get bundle_id from an object of type of_bundle_add_msg.
 * @param obj Pointer to an object of type of_bundle_add_msg.
 * @param bundle_id Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bundle_add_msg_bundle_id_get(
    of_bundle_add_msg_t *obj,
    uint32_t *bundle_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BUNDLE_ADD_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, bundle_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set bundle_id in an object of type of_bundle_add_msg.
 * @param obj Pointer to an object of type of_bundle_add_msg.
 * @param bundle_id The value to write into the object
 */
void
of_bundle_add_msg_bundle_id_set(
    of_bundle_add_msg_t *obj,
    uint32_t bundle_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BUNDLE_ADD_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, bundle_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get flags from an object of type of_bundle_add_msg.
 * @param obj Pointer to an object of type of_bundle_add_msg.
 * @param flags Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bundle_add_msg_flags_get(
    of_bundle_add_msg_t *obj,
    uint16_t *flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BUNDLE_ADD_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 14;
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
 * Set flags in an object of type of_bundle_add_msg.
 * @param obj Pointer to an object of type of_bundle_add_msg.
 * @param flags The value to write into the object
 */
void
of_bundle_add_msg_flags_set(
    of_bundle_add_msg_t *obj,
    uint16_t flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BUNDLE_ADD_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 14;
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
 * Get data from an object of type of_bundle_add_msg.
 * @param obj Pointer to an object of type of_bundle_add_msg.
 * @param data Pointer to the child object of type
 * of_octets_t to be filled out.
 *
 */
void
of_bundle_add_msg_data_get(
    of_bundle_add_msg_t *obj,
    of_octets_t *data)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_BUNDLE_ADD_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 16;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);
    LOCI_ASSERT(cur_len + abs_offset <= WBUF_CURRENT_BYTES(wbuf));
    data->bytes = cur_len;
    data->data = OF_WIRE_BUFFER_INDEX(wbuf, abs_offset);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set data in an object of type of_bundle_add_msg.
 * @param obj Pointer to an object of type of_bundle_add_msg.
 * @param data The value to write into the object
 */
int WARN_UNUSED_RESULT
of_bundle_add_msg_data_set(
    of_bundle_add_msg_t *obj,
    of_octets_t *data)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_BUNDLE_ADD_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 16;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);
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
of_bundle_ctrl_msg_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_4:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x21; /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bundle_ctrl_msg of_bundle_ctrl_msg
 */

/**
 * Create a new of_bundle_ctrl_msg object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bundle_ctrl_msg
 */

of_object_t *
of_bundle_ctrl_msg_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BUNDLE_CTRL_MSG];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bundle_ctrl_msg_init(obj, version, bytes, 0);
    of_bundle_ctrl_msg_push_wire_types(obj);
    of_object_message_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bundle_ctrl_msg.
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
of_bundle_ctrl_msg_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BUNDLE_CTRL_MSG] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BUNDLE_CTRL_MSG];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BUNDLE_CTRL_MSG;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_bundle_ctrl_msg.
 * @param obj Pointer to an object of type of_bundle_ctrl_msg.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bundle_ctrl_msg_xid_get(
    of_bundle_ctrl_msg_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BUNDLE_CTRL_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
 * Set xid in an object of type of_bundle_ctrl_msg.
 * @param obj Pointer to an object of type of_bundle_ctrl_msg.
 * @param xid The value to write into the object
 */
void
of_bundle_ctrl_msg_xid_set(
    of_bundle_ctrl_msg_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BUNDLE_CTRL_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
 * Get bundle_id from an object of type of_bundle_ctrl_msg.
 * @param obj Pointer to an object of type of_bundle_ctrl_msg.
 * @param bundle_id Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bundle_ctrl_msg_bundle_id_get(
    of_bundle_ctrl_msg_t *obj,
    uint32_t *bundle_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BUNDLE_CTRL_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, bundle_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set bundle_id in an object of type of_bundle_ctrl_msg.
 * @param obj Pointer to an object of type of_bundle_ctrl_msg.
 * @param bundle_id The value to write into the object
 */
void
of_bundle_ctrl_msg_bundle_id_set(
    of_bundle_ctrl_msg_t *obj,
    uint32_t bundle_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BUNDLE_CTRL_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, bundle_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get bundle_ctrl_type from an object of type of_bundle_ctrl_msg.
 * @param obj Pointer to an object of type of_bundle_ctrl_msg.
 * @param bundle_ctrl_type Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bundle_ctrl_msg_bundle_ctrl_type_get(
    of_bundle_ctrl_msg_t *obj,
    uint16_t *bundle_ctrl_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BUNDLE_CTRL_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, bundle_ctrl_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set bundle_ctrl_type in an object of type of_bundle_ctrl_msg.
 * @param obj Pointer to an object of type of_bundle_ctrl_msg.
 * @param bundle_ctrl_type The value to write into the object
 */
void
of_bundle_ctrl_msg_bundle_ctrl_type_set(
    of_bundle_ctrl_msg_t *obj,
    uint16_t bundle_ctrl_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BUNDLE_CTRL_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, bundle_ctrl_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get flags from an object of type of_bundle_ctrl_msg.
 * @param obj Pointer to an object of type of_bundle_ctrl_msg.
 * @param flags Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bundle_ctrl_msg_flags_get(
    of_bundle_ctrl_msg_t *obj,
    uint16_t *flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BUNDLE_CTRL_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 14;
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
 * Set flags in an object of type of_bundle_ctrl_msg.
 * @param obj Pointer to an object of type of_bundle_ctrl_msg.
 * @param flags The value to write into the object
 */
void
of_bundle_ctrl_msg_flags_set(
    of_bundle_ctrl_msg_t *obj,
    uint16_t flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BUNDLE_CTRL_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 14;
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
 * Bind an object of type of_list_bundle_prop_t to the parent of type of_bundle_ctrl_msg for
 * member properties
 * @param obj Pointer to an object of type of_bundle_ctrl_msg.
 * @param properties Pointer to the child object of type
 * of_list_bundle_prop_t to be filled out.
 * \ingroup of_bundle_ctrl_msg
 *
 * The parameter properties is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_bundle_ctrl_msg_properties_bind(
    of_bundle_ctrl_msg_t *obj,
    of_list_bundle_prop_t *properties)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_BUNDLE_CTRL_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 16;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_list_bundle_prop_init(properties, obj->version, 0, 1);
    /* Attach to parent */
    of_object_attach(obj, properties, offset, cur_len);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of properties into a new variable of type of_list_bundle_prop_t from
 * a of_bundle_ctrl_msg instance.
 *
 * @param obj Pointer to the source of type of_bundle_ctrl_msg_t
 * @returns A pointer to a new instance of type of_list_bundle_prop_t whose contents
 * match that of properties from source
 * @returns NULL if an error occurs
 */
of_list_bundle_prop_t *
of_bundle_ctrl_msg_properties_get(of_bundle_ctrl_msg_t *obj) {
    of_list_bundle_prop_t _properties;
    of_list_bundle_prop_t *_properties_ptr;

    of_bundle_ctrl_msg_properties_bind(obj, &_properties);
    _properties_ptr = (of_list_bundle_prop_t *)of_object_dup(&_properties);
    return _properties_ptr;
}

/**
 * Set properties in an object of type of_bundle_ctrl_msg.
 * @param obj Pointer to an object of type of_bundle_ctrl_msg.
 * @param properties Pointer to the child of type of_list_bundle_prop_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_bundle_ctrl_msg_properties_set(
    of_bundle_ctrl_msg_t *obj,
    of_list_bundle_prop_t *properties)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_BUNDLE_CTRL_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 16;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = properties->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wbuf == properties->wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(properties, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(properties, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    of_object_wire_length_set((of_object_t *)properties, properties->length);

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
of_bundle_failed_error_msg_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_4:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x1; /* type */
        *(uint16_t *)(buf + 8) = U16_HTON(0x11); /* err_type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bundle_failed_error_msg of_bundle_failed_error_msg
 */

/**
 * Create a new of_bundle_failed_error_msg object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bundle_failed_error_msg
 */

of_object_t *
of_bundle_failed_error_msg_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BUNDLE_FAILED_ERROR_MSG];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bundle_failed_error_msg_init(obj, version, bytes, 0);
    of_bundle_failed_error_msg_push_wire_types(obj);
    of_object_message_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bundle_failed_error_msg.
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
of_bundle_failed_error_msg_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BUNDLE_FAILED_ERROR_MSG] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BUNDLE_FAILED_ERROR_MSG];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BUNDLE_FAILED_ERROR_MSG;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_bundle_failed_error_msg.
 * @param obj Pointer to an object of type of_bundle_failed_error_msg.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bundle_failed_error_msg_xid_get(
    of_bundle_failed_error_msg_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BUNDLE_FAILED_ERROR_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
 * Set xid in an object of type of_bundle_failed_error_msg.
 * @param obj Pointer to an object of type of_bundle_failed_error_msg.
 * @param xid The value to write into the object
 */
void
of_bundle_failed_error_msg_xid_set(
    of_bundle_failed_error_msg_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BUNDLE_FAILED_ERROR_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
 * Get code from an object of type of_bundle_failed_error_msg.
 * @param obj Pointer to an object of type of_bundle_failed_error_msg.
 * @param code Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bundle_failed_error_msg_code_get(
    of_bundle_failed_error_msg_t *obj,
    uint16_t *code)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BUNDLE_FAILED_ERROR_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 10;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, code);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set code in an object of type of_bundle_failed_error_msg.
 * @param obj Pointer to an object of type of_bundle_failed_error_msg.
 * @param code The value to write into the object
 */
void
of_bundle_failed_error_msg_code_set(
    of_bundle_failed_error_msg_t *obj,
    uint16_t code)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BUNDLE_FAILED_ERROR_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 10;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, code);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get data from an object of type of_bundle_failed_error_msg.
 * @param obj Pointer to an object of type of_bundle_failed_error_msg.
 * @param data Pointer to the child object of type
 * of_octets_t to be filled out.
 *
 */
void
of_bundle_failed_error_msg_data_get(
    of_bundle_failed_error_msg_t *obj,
    of_octets_t *data)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_BUNDLE_FAILED_ERROR_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 12;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);
    LOCI_ASSERT(cur_len + abs_offset <= WBUF_CURRENT_BYTES(wbuf));
    data->bytes = cur_len;
    data->data = OF_WIRE_BUFFER_INDEX(wbuf, abs_offset);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set data in an object of type of_bundle_failed_error_msg.
 * @param obj Pointer to an object of type of_bundle_failed_error_msg.
 * @param data The value to write into the object
 */
int WARN_UNUSED_RESULT
of_bundle_failed_error_msg_data_set(
    of_bundle_failed_error_msg_t *obj,
    of_octets_t *data)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_BUNDLE_FAILED_ERROR_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 12;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);
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
of_bundle_prop_wire_object_id_get(of_object_t *obj, of_object_id_t *id)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_4: {
        uint16_t value = U16_NTOH(*(uint16_t *)(buf + 0)); /* type */
        switch (value) {
        case 0xffff:
            of_bundle_prop_experimenter_wire_object_id_get(obj, id);
            break;
        default:
            *id = OF_BUNDLE_PROP;
            break;
        }
        break;
    }
    default:
        LOCI_ASSERT(0);
    }
}


/**
 * \defgroup of_bundle_prop of_bundle_prop
 */

/**
 * Create a new of_bundle_prop object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bundle_prop
 */

of_object_t *
of_bundle_prop_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BUNDLE_PROP];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bundle_prop_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_bundle_prop.
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
of_bundle_prop_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BUNDLE_PROP] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BUNDLE_PROP];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BUNDLE_PROP;

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
of_bundle_prop_experimenter_wire_object_id_get(of_object_t *obj, of_object_id_t *id)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_4: {
        uint32_t value = U32_NTOH(*(uint32_t *)(buf + 4)); /* experimenter */
        switch (value) {
        default:
            *id = OF_BUNDLE_PROP_EXPERIMENTER;
            break;
        }
        break;
    }
    default:
        LOCI_ASSERT(0);
    }
}


/**
 * \defgroup of_bundle_prop_experimenter of_bundle_prop_experimenter
 */

/**
 * Create a new of_bundle_prop_experimenter object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bundle_prop_experimenter
 */

of_object_t *
of_bundle_prop_experimenter_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BUNDLE_PROP_EXPERIMENTER];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bundle_prop_experimenter_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_bundle_prop_experimenter.
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
of_bundle_prop_experimenter_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BUNDLE_PROP_EXPERIMENTER] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BUNDLE_PROP_EXPERIMENTER];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BUNDLE_PROP_EXPERIMENTER;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get experimenter from an object of type of_bundle_prop_experimenter.
 * @param obj Pointer to an object of type of_bundle_prop_experimenter.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bundle_prop_experimenter_experimenter_get(
    of_bundle_prop_experimenter_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BUNDLE_PROP_EXPERIMENTER);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
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
 * Set experimenter in an object of type of_bundle_prop_experimenter.
 * @param obj Pointer to an object of type of_bundle_prop_experimenter.
 * @param experimenter The value to write into the object
 */
void
of_bundle_prop_experimenter_experimenter_set(
    of_bundle_prop_experimenter_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BUNDLE_PROP_EXPERIMENTER);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
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
 * Get exp_type from an object of type of_bundle_prop_experimenter.
 * @param obj Pointer to an object of type of_bundle_prop_experimenter.
 * @param exp_type Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bundle_prop_experimenter_exp_type_get(
    of_bundle_prop_experimenter_t *obj,
    uint32_t *exp_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BUNDLE_PROP_EXPERIMENTER);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, exp_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set exp_type in an object of type of_bundle_prop_experimenter.
 * @param obj Pointer to an object of type of_bundle_prop_experimenter.
 * @param exp_type The value to write into the object
 */
void
of_bundle_prop_experimenter_exp_type_set(
    of_bundle_prop_experimenter_t *obj,
    uint32_t exp_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BUNDLE_PROP_EXPERIMENTER);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, exp_type);

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
of_flow_monitor_failed_error_msg_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_4:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x1; /* type */
        *(uint16_t *)(buf + 8) = U16_HTON(0x10); /* err_type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_flow_monitor_failed_error_msg of_flow_monitor_failed_error_msg
 */

/**
 * Create a new of_flow_monitor_failed_error_msg object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_flow_monitor_failed_error_msg
 */

of_object_t *
of_flow_monitor_failed_error_msg_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_FLOW_MONITOR_FAILED_ERROR_MSG];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_flow_monitor_failed_error_msg_init(obj, version, bytes, 0);
    of_flow_monitor_failed_error_msg_push_wire_types(obj);
    of_object_message_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_flow_monitor_failed_error_msg.
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
of_flow_monitor_failed_error_msg_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_FLOW_MONITOR_FAILED_ERROR_MSG] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_FLOW_MONITOR_FAILED_ERROR_MSG];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_FLOW_MONITOR_FAILED_ERROR_MSG;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_flow_monitor_failed_error_msg.
 * @param obj Pointer to an object of type of_flow_monitor_failed_error_msg.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_flow_monitor_failed_error_msg_xid_get(
    of_flow_monitor_failed_error_msg_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_FLOW_MONITOR_FAILED_ERROR_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
 * Set xid in an object of type of_flow_monitor_failed_error_msg.
 * @param obj Pointer to an object of type of_flow_monitor_failed_error_msg.
 * @param xid The value to write into the object
 */
void
of_flow_monitor_failed_error_msg_xid_set(
    of_flow_monitor_failed_error_msg_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_FLOW_MONITOR_FAILED_ERROR_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
 * Get code from an object of type of_flow_monitor_failed_error_msg.
 * @param obj Pointer to an object of type of_flow_monitor_failed_error_msg.
 * @param code Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_flow_monitor_failed_error_msg_code_get(
    of_flow_monitor_failed_error_msg_t *obj,
    uint16_t *code)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_FLOW_MONITOR_FAILED_ERROR_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 10;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, code);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set code in an object of type of_flow_monitor_failed_error_msg.
 * @param obj Pointer to an object of type of_flow_monitor_failed_error_msg.
 * @param code The value to write into the object
 */
void
of_flow_monitor_failed_error_msg_code_set(
    of_flow_monitor_failed_error_msg_t *obj,
    uint16_t code)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_FLOW_MONITOR_FAILED_ERROR_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 10;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, code);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get data from an object of type of_flow_monitor_failed_error_msg.
 * @param obj Pointer to an object of type of_flow_monitor_failed_error_msg.
 * @param data Pointer to the child object of type
 * of_octets_t to be filled out.
 *
 */
void
of_flow_monitor_failed_error_msg_data_get(
    of_flow_monitor_failed_error_msg_t *obj,
    of_octets_t *data)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_FLOW_MONITOR_FAILED_ERROR_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 12;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);
    LOCI_ASSERT(cur_len + abs_offset <= WBUF_CURRENT_BYTES(wbuf));
    data->bytes = cur_len;
    data->data = OF_WIRE_BUFFER_INDEX(wbuf, abs_offset);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set data in an object of type of_flow_monitor_failed_error_msg.
 * @param obj Pointer to an object of type of_flow_monitor_failed_error_msg.
 * @param data The value to write into the object
 */
int WARN_UNUSED_RESULT
of_flow_monitor_failed_error_msg_data_set(
    of_flow_monitor_failed_error_msg_t *obj,
    of_octets_t *data)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_FLOW_MONITOR_FAILED_ERROR_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 12;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);
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
of_oxm_bsn_ifp_class_id_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x33604); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_bsn_ifp_class_id of_oxm_bsn_ifp_class_id
 */

/**
 * Create a new of_oxm_bsn_ifp_class_id object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_bsn_ifp_class_id
 */

of_object_t *
of_oxm_bsn_ifp_class_id_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_BSN_IFP_CLASS_ID];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_bsn_ifp_class_id_init(obj, version, bytes, 0);
    of_oxm_bsn_ifp_class_id_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_bsn_ifp_class_id.
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
of_oxm_bsn_ifp_class_id_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_BSN_IFP_CLASS_ID] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_BSN_IFP_CLASS_ID];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_BSN_IFP_CLASS_ID;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_bsn_ifp_class_id.
 * @param obj Pointer to an object of type of_oxm_bsn_ifp_class_id.
 * @param value Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_bsn_ifp_class_id_value_get(
    of_oxm_bsn_ifp_class_id_t *obj,
    uint32_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_BSN_IFP_CLASS_ID);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
 * Set value in an object of type of_oxm_bsn_ifp_class_id.
 * @param obj Pointer to an object of type of_oxm_bsn_ifp_class_id.
 * @param value The value to write into the object
 */
void
of_oxm_bsn_ifp_class_id_value_set(
    of_oxm_bsn_ifp_class_id_t *obj,
    uint32_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_BSN_IFP_CLASS_ID);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
of_oxm_bsn_ifp_class_id_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x33708); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_bsn_ifp_class_id_masked of_oxm_bsn_ifp_class_id_masked
 */

/**
 * Create a new of_oxm_bsn_ifp_class_id_masked object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_bsn_ifp_class_id_masked
 */

of_object_t *
of_oxm_bsn_ifp_class_id_masked_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_BSN_IFP_CLASS_ID_MASKED];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_bsn_ifp_class_id_masked_init(obj, version, bytes, 0);
    of_oxm_bsn_ifp_class_id_masked_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_bsn_ifp_class_id_masked.
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
of_oxm_bsn_ifp_class_id_masked_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_BSN_IFP_CLASS_ID_MASKED] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_BSN_IFP_CLASS_ID_MASKED];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_BSN_IFP_CLASS_ID_MASKED;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_bsn_ifp_class_id_masked.
 * @param obj Pointer to an object of type of_oxm_bsn_ifp_class_id_masked.
 * @param value Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_bsn_ifp_class_id_masked_value_get(
    of_oxm_bsn_ifp_class_id_masked_t *obj,
    uint32_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_BSN_IFP_CLASS_ID_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
 * Set value in an object of type of_oxm_bsn_ifp_class_id_masked.
 * @param obj Pointer to an object of type of_oxm_bsn_ifp_class_id_masked.
 * @param value The value to write into the object
 */
void
of_oxm_bsn_ifp_class_id_masked_value_set(
    of_oxm_bsn_ifp_class_id_masked_t *obj,
    uint32_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_BSN_IFP_CLASS_ID_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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

/**
 * Get value_mask from an object of type of_oxm_bsn_ifp_class_id_masked.
 * @param obj Pointer to an object of type of_oxm_bsn_ifp_class_id_masked.
 * @param value_mask Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_bsn_ifp_class_id_masked_value_mask_get(
    of_oxm_bsn_ifp_class_id_masked_t *obj,
    uint32_t *value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_BSN_IFP_CLASS_ID_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, value_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value_mask in an object of type of_oxm_bsn_ifp_class_id_masked.
 * @param obj Pointer to an object of type of_oxm_bsn_ifp_class_id_masked.
 * @param value_mask The value to write into the object
 */
void
of_oxm_bsn_ifp_class_id_masked_value_mask_set(
    of_oxm_bsn_ifp_class_id_masked_t *obj,
    uint32_t value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_BSN_IFP_CLASS_ID_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, value_mask);

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
of_oxm_pbb_uca_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x80005201); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_pbb_uca of_oxm_pbb_uca
 */

/**
 * Create a new of_oxm_pbb_uca object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_pbb_uca
 */

of_object_t *
of_oxm_pbb_uca_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_PBB_UCA];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_pbb_uca_init(obj, version, bytes, 0);
    of_oxm_pbb_uca_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_pbb_uca.
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
of_oxm_pbb_uca_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_PBB_UCA] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_PBB_UCA];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_PBB_UCA;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_pbb_uca.
 * @param obj Pointer to an object of type of_oxm_pbb_uca.
 * @param value Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_oxm_pbb_uca_value_get(
    of_oxm_pbb_uca_t *obj,
    uint8_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_PBB_UCA);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
 * Set value in an object of type of_oxm_pbb_uca.
 * @param obj Pointer to an object of type of_oxm_pbb_uca.
 * @param value The value to write into the object
 */
void
of_oxm_pbb_uca_value_set(
    of_oxm_pbb_uca_t *obj,
    uint8_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_PBB_UCA);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
of_oxm_pbb_uca_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x80005302); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_pbb_uca_masked of_oxm_pbb_uca_masked
 */

/**
 * Create a new of_oxm_pbb_uca_masked object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_pbb_uca_masked
 */

of_object_t *
of_oxm_pbb_uca_masked_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_PBB_UCA_MASKED];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_pbb_uca_masked_init(obj, version, bytes, 0);
    of_oxm_pbb_uca_masked_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_pbb_uca_masked.
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
of_oxm_pbb_uca_masked_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_PBB_UCA_MASKED] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_PBB_UCA_MASKED];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_PBB_UCA_MASKED;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_pbb_uca_masked.
 * @param obj Pointer to an object of type of_oxm_pbb_uca_masked.
 * @param value Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_oxm_pbb_uca_masked_value_get(
    of_oxm_pbb_uca_masked_t *obj,
    uint8_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_PBB_UCA_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
 * Set value in an object of type of_oxm_pbb_uca_masked.
 * @param obj Pointer to an object of type of_oxm_pbb_uca_masked.
 * @param value The value to write into the object
 */
void
of_oxm_pbb_uca_masked_value_set(
    of_oxm_pbb_uca_masked_t *obj,
    uint8_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_PBB_UCA_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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

/**
 * Get value_mask from an object of type of_oxm_pbb_uca_masked.
 * @param obj Pointer to an object of type of_oxm_pbb_uca_masked.
 * @param value_mask Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_oxm_pbb_uca_masked_value_mask_get(
    of_oxm_pbb_uca_masked_t *obj,
    uint8_t *value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_PBB_UCA_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 5;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, value_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value_mask in an object of type of_oxm_pbb_uca_masked.
 * @param obj Pointer to an object of type of_oxm_pbb_uca_masked.
 * @param value_mask The value to write into the object
 */
void
of_oxm_pbb_uca_masked_value_mask_set(
    of_oxm_pbb_uca_masked_t *obj,
    uint8_t value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_PBB_UCA_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 5;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, value_mask);

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
of_port_desc_prop_wire_object_id_get(of_object_t *obj, of_object_id_t *id)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_4: {
        uint16_t value = U16_NTOH(*(uint16_t *)(buf + 0)); /* type */
        switch (value) {
        case 0x0:
            *id = OF_PORT_DESC_PROP_ETHERNET;
            break;
        case 0x1:
            *id = OF_PORT_DESC_PROP_OPTICAL;
            break;
        case 0xffff:
            of_port_desc_prop_experimenter_wire_object_id_get(obj, id);
            break;
        default:
            *id = OF_PORT_DESC_PROP;
            break;
        }
        break;
    }
    default:
        LOCI_ASSERT(0);
    }
}


/**
 * \defgroup of_port_desc_prop of_port_desc_prop
 */

/**
 * Create a new of_port_desc_prop object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_port_desc_prop
 */

of_object_t *
of_port_desc_prop_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_PORT_DESC_PROP];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_port_desc_prop_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_port_desc_prop.
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
of_port_desc_prop_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_PORT_DESC_PROP] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_PORT_DESC_PROP];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_PORT_DESC_PROP;

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
of_port_desc_prop_experimenter_wire_object_id_get(of_object_t *obj, of_object_id_t *id)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_4: {
        uint32_t value = U32_NTOH(*(uint32_t *)(buf + 4)); /* experimenter */
        switch (value) {
        case 0x5c16c7:
            of_port_desc_prop_bsn_wire_object_id_get(obj, id);
            break;
        default:
            *id = OF_PORT_DESC_PROP_EXPERIMENTER;
            break;
        }
        break;
    }
    default:
        LOCI_ASSERT(0);
    }
}


/**
 * \defgroup of_port_desc_prop_experimenter of_port_desc_prop_experimenter
 */

/**
 * Create a new of_port_desc_prop_experimenter object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_port_desc_prop_experimenter
 */

of_object_t *
of_port_desc_prop_experimenter_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_PORT_DESC_PROP_EXPERIMENTER];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_port_desc_prop_experimenter_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_port_desc_prop_experimenter.
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
of_port_desc_prop_experimenter_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_PORT_DESC_PROP_EXPERIMENTER] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_PORT_DESC_PROP_EXPERIMENTER];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_PORT_DESC_PROP_EXPERIMENTER;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get experimenter from an object of type of_port_desc_prop_experimenter.
 * @param obj Pointer to an object of type of_port_desc_prop_experimenter.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_experimenter_experimenter_get(
    of_port_desc_prop_experimenter_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_EXPERIMENTER);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
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
 * Set experimenter in an object of type of_port_desc_prop_experimenter.
 * @param obj Pointer to an object of type of_port_desc_prop_experimenter.
 * @param experimenter The value to write into the object
 */
void
of_port_desc_prop_experimenter_experimenter_set(
    of_port_desc_prop_experimenter_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_EXPERIMENTER);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
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


void
of_port_desc_prop_bsn_wire_object_id_get(of_object_t *obj, of_object_id_t *id)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_4: {
        uint32_t value = U32_NTOH(*(uint32_t *)(buf + 8)); /* exp_type */
        switch (value) {
        case 0x0:
            *id = OF_PORT_DESC_PROP_BSN_UPLINK;
            break;
        case 0x1:
            *id = OF_PORT_DESC_PROP_BSN_GENERATION_ID;
            break;
        case 0x2:
            *id = OF_PORT_DESC_PROP_BSN_FORWARD_ERROR_CORRECTION;
            break;
        case 0x3:
            *id = OF_PORT_DESC_PROP_BSN_BREAKOUT;
            break;
        case 0x4:
            *id = OF_PORT_DESC_PROP_BSN_SPEED_CAPABILITIES;
            break;
        case 0x5:
            *id = OF_PORT_DESC_PROP_BSN_MISC_CAPABILITIES;
            break;
        case 0x6:
            *id = OF_PORT_DESC_PROP_BSN_ETHTOOL;
            break;
        case 0x7:
            *id = OF_PORT_DESC_PROP_BSN_DIAG;
            break;
        case 0x8:
            *id = OF_PORT_DESC_PROP_BSN_ALARM;
            break;
        default:
            *id = OF_PORT_DESC_PROP_BSN;
            break;
        }
        break;
    }
    default:
        LOCI_ASSERT(0);
    }
}


/**
 * \defgroup of_port_desc_prop_bsn of_port_desc_prop_bsn
 */

/**
 * Create a new of_port_desc_prop_bsn object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_port_desc_prop_bsn
 */

of_object_t *
of_port_desc_prop_bsn_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_PORT_DESC_PROP_BSN];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_port_desc_prop_bsn_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_port_desc_prop_bsn.
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
of_port_desc_prop_bsn_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_PORT_DESC_PROP_BSN] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_PORT_DESC_PROP_BSN];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_PORT_DESC_PROP_BSN;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get experimenter from an object of type of_port_desc_prop_bsn.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_experimenter_get(
    of_port_desc_prop_bsn_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
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
 * Set experimenter in an object of type of_port_desc_prop_bsn.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn.
 * @param experimenter The value to write into the object
 */
void
of_port_desc_prop_bsn_experimenter_set(
    of_port_desc_prop_bsn_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
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
 * Get exp_type from an object of type of_port_desc_prop_bsn.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn.
 * @param exp_type Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_exp_type_get(
    of_port_desc_prop_bsn_t *obj,
    uint32_t *exp_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, exp_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set exp_type in an object of type of_port_desc_prop_bsn.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn.
 * @param exp_type The value to write into the object
 */
void
of_port_desc_prop_bsn_exp_type_set(
    of_port_desc_prop_bsn_t *obj,
    uint32_t exp_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, exp_type);

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
of_port_desc_prop_bsn_alarm_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xffff); /* type */
        *(uint32_t *)(buf + 4) = U32_HTON(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 8) = U32_HTON(0x8); /* exp_type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_port_desc_prop_bsn_alarm of_port_desc_prop_bsn_alarm
 */

/**
 * Create a new of_port_desc_prop_bsn_alarm object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_port_desc_prop_bsn_alarm
 */

of_object_t *
of_port_desc_prop_bsn_alarm_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_PORT_DESC_PROP_BSN_ALARM];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_port_desc_prop_bsn_alarm_init(obj, version, bytes, 0);
    of_port_desc_prop_bsn_alarm_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_port_desc_prop_bsn_alarm.
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
of_port_desc_prop_bsn_alarm_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_PORT_DESC_PROP_BSN_ALARM] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_PORT_DESC_PROP_BSN_ALARM];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_PORT_DESC_PROP_BSN_ALARM;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get experimenter from an object of type of_port_desc_prop_bsn_alarm.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_alarm.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_alarm_experimenter_get(
    of_port_desc_prop_bsn_alarm_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ALARM);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
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
 * Set experimenter in an object of type of_port_desc_prop_bsn_alarm.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_alarm.
 * @param experimenter The value to write into the object
 */
void
of_port_desc_prop_bsn_alarm_experimenter_set(
    of_port_desc_prop_bsn_alarm_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ALARM);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
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
 * Get exp_type from an object of type of_port_desc_prop_bsn_alarm.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_alarm.
 * @param exp_type Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_alarm_exp_type_get(
    of_port_desc_prop_bsn_alarm_t *obj,
    uint32_t *exp_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ALARM);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, exp_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set exp_type in an object of type of_port_desc_prop_bsn_alarm.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_alarm.
 * @param exp_type The value to write into the object
 */
void
of_port_desc_prop_bsn_alarm_exp_type_set(
    of_port_desc_prop_bsn_alarm_t *obj,
    uint32_t exp_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ALARM);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, exp_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get alarm_set from an object of type of_port_desc_prop_bsn_alarm.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_alarm.
 * @param alarm_set Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_alarm_alarm_set_get(
    of_port_desc_prop_bsn_alarm_t *obj,
    uint8_t *alarm_set)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ALARM);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, alarm_set);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set alarm_set in an object of type of_port_desc_prop_bsn_alarm.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_alarm.
 * @param alarm_set The value to write into the object
 */
void
of_port_desc_prop_bsn_alarm_alarm_set_set(
    of_port_desc_prop_bsn_alarm_t *obj,
    uint8_t alarm_set)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ALARM);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, alarm_set);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get high from an object of type of_port_desc_prop_bsn_alarm.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_alarm.
 * @param high Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_alarm_high_get(
    of_port_desc_prop_bsn_alarm_t *obj,
    uint32_t *high)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ALARM);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 13;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, high);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set high in an object of type of_port_desc_prop_bsn_alarm.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_alarm.
 * @param high The value to write into the object
 */
void
of_port_desc_prop_bsn_alarm_high_set(
    of_port_desc_prop_bsn_alarm_t *obj,
    uint32_t high)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ALARM);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 13;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, high);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get high_warn from an object of type of_port_desc_prop_bsn_alarm.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_alarm.
 * @param high_warn Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_alarm_high_warn_get(
    of_port_desc_prop_bsn_alarm_t *obj,
    uint32_t *high_warn)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ALARM);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 17;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, high_warn);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set high_warn in an object of type of_port_desc_prop_bsn_alarm.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_alarm.
 * @param high_warn The value to write into the object
 */
void
of_port_desc_prop_bsn_alarm_high_warn_set(
    of_port_desc_prop_bsn_alarm_t *obj,
    uint32_t high_warn)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ALARM);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 17;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, high_warn);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get low from an object of type of_port_desc_prop_bsn_alarm.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_alarm.
 * @param low Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_alarm_low_get(
    of_port_desc_prop_bsn_alarm_t *obj,
    uint32_t *low)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ALARM);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 21;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, low);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set low in an object of type of_port_desc_prop_bsn_alarm.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_alarm.
 * @param low The value to write into the object
 */
void
of_port_desc_prop_bsn_alarm_low_set(
    of_port_desc_prop_bsn_alarm_t *obj,
    uint32_t low)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ALARM);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 21;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, low);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get low_warn from an object of type of_port_desc_prop_bsn_alarm.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_alarm.
 * @param low_warn Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_alarm_low_warn_get(
    of_port_desc_prop_bsn_alarm_t *obj,
    uint32_t *low_warn)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ALARM);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 25;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, low_warn);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set low_warn in an object of type of_port_desc_prop_bsn_alarm.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_alarm.
 * @param low_warn The value to write into the object
 */
void
of_port_desc_prop_bsn_alarm_low_warn_set(
    of_port_desc_prop_bsn_alarm_t *obj,
    uint32_t low_warn)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ALARM);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 25;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, low_warn);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get alarm_type from an object of type of_port_desc_prop_bsn_alarm.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_alarm.
 * @param alarm_type Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_alarm_alarm_type_get(
    of_port_desc_prop_bsn_alarm_t *obj,
    uint8_t *alarm_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ALARM);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 29;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, alarm_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set alarm_type in an object of type of_port_desc_prop_bsn_alarm.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_alarm.
 * @param alarm_type The value to write into the object
 */
void
of_port_desc_prop_bsn_alarm_alarm_type_set(
    of_port_desc_prop_bsn_alarm_t *obj,
    uint8_t alarm_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ALARM);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 29;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, alarm_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get unit from an object of type of_port_desc_prop_bsn_alarm.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_alarm.
 * @param unit Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_alarm_unit_get(
    of_port_desc_prop_bsn_alarm_t *obj,
    uint8_t *unit)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ALARM);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 30;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, unit);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set unit in an object of type of_port_desc_prop_bsn_alarm.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_alarm.
 * @param unit The value to write into the object
 */
void
of_port_desc_prop_bsn_alarm_unit_set(
    of_port_desc_prop_bsn_alarm_t *obj,
    uint8_t unit)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ALARM);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 30;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, unit);

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
of_port_desc_prop_bsn_breakout_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xffff); /* type */
        *(uint32_t *)(buf + 4) = U32_HTON(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 8) = U32_HTON(0x3); /* exp_type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_port_desc_prop_bsn_breakout of_port_desc_prop_bsn_breakout
 */

/**
 * Create a new of_port_desc_prop_bsn_breakout object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_port_desc_prop_bsn_breakout
 */

of_object_t *
of_port_desc_prop_bsn_breakout_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_PORT_DESC_PROP_BSN_BREAKOUT];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_port_desc_prop_bsn_breakout_init(obj, version, bytes, 0);
    of_port_desc_prop_bsn_breakout_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_port_desc_prop_bsn_breakout.
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
of_port_desc_prop_bsn_breakout_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_PORT_DESC_PROP_BSN_BREAKOUT] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_PORT_DESC_PROP_BSN_BREAKOUT];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_PORT_DESC_PROP_BSN_BREAKOUT;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get experimenter from an object of type of_port_desc_prop_bsn_breakout.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_breakout.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_breakout_experimenter_get(
    of_port_desc_prop_bsn_breakout_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_BREAKOUT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
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
 * Set experimenter in an object of type of_port_desc_prop_bsn_breakout.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_breakout.
 * @param experimenter The value to write into the object
 */
void
of_port_desc_prop_bsn_breakout_experimenter_set(
    of_port_desc_prop_bsn_breakout_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_BREAKOUT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
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
 * Get exp_type from an object of type of_port_desc_prop_bsn_breakout.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_breakout.
 * @param exp_type Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_breakout_exp_type_get(
    of_port_desc_prop_bsn_breakout_t *obj,
    uint32_t *exp_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_BREAKOUT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, exp_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set exp_type in an object of type of_port_desc_prop_bsn_breakout.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_breakout.
 * @param exp_type The value to write into the object
 */
void
of_port_desc_prop_bsn_breakout_exp_type_set(
    of_port_desc_prop_bsn_breakout_t *obj,
    uint32_t exp_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_BREAKOUT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, exp_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get sub_interface_count from an object of type of_port_desc_prop_bsn_breakout.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_breakout.
 * @param sub_interface_count Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_breakout_sub_interface_count_get(
    of_port_desc_prop_bsn_breakout_t *obj,
    uint16_t *sub_interface_count)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_BREAKOUT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, sub_interface_count);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set sub_interface_count in an object of type of_port_desc_prop_bsn_breakout.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_breakout.
 * @param sub_interface_count The value to write into the object
 */
void
of_port_desc_prop_bsn_breakout_sub_interface_count_set(
    of_port_desc_prop_bsn_breakout_t *obj,
    uint16_t sub_interface_count)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_BREAKOUT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, sub_interface_count);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get sub_interface_speed_gbps from an object of type of_port_desc_prop_bsn_breakout.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_breakout.
 * @param sub_interface_speed_gbps Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_breakout_sub_interface_speed_gbps_get(
    of_port_desc_prop_bsn_breakout_t *obj,
    uint16_t *sub_interface_speed_gbps)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_BREAKOUT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 14;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, sub_interface_speed_gbps);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set sub_interface_speed_gbps in an object of type of_port_desc_prop_bsn_breakout.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_breakout.
 * @param sub_interface_speed_gbps The value to write into the object
 */
void
of_port_desc_prop_bsn_breakout_sub_interface_speed_gbps_set(
    of_port_desc_prop_bsn_breakout_t *obj,
    uint16_t sub_interface_speed_gbps)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_BREAKOUT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 14;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, sub_interface_speed_gbps);

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
of_port_desc_prop_bsn_diag_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xffff); /* type */
        *(uint32_t *)(buf + 4) = U32_HTON(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 8) = U32_HTON(0x7); /* exp_type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_port_desc_prop_bsn_diag of_port_desc_prop_bsn_diag
 */

/**
 * Create a new of_port_desc_prop_bsn_diag object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_port_desc_prop_bsn_diag
 */

of_object_t *
of_port_desc_prop_bsn_diag_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_PORT_DESC_PROP_BSN_DIAG];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_port_desc_prop_bsn_diag_init(obj, version, bytes, 0);
    of_port_desc_prop_bsn_diag_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_port_desc_prop_bsn_diag.
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
of_port_desc_prop_bsn_diag_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_PORT_DESC_PROP_BSN_DIAG] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_PORT_DESC_PROP_BSN_DIAG];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_PORT_DESC_PROP_BSN_DIAG;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get experimenter from an object of type of_port_desc_prop_bsn_diag.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_diag.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_diag_experimenter_get(
    of_port_desc_prop_bsn_diag_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_DIAG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
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
 * Set experimenter in an object of type of_port_desc_prop_bsn_diag.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_diag.
 * @param experimenter The value to write into the object
 */
void
of_port_desc_prop_bsn_diag_experimenter_set(
    of_port_desc_prop_bsn_diag_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_DIAG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
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
 * Get exp_type from an object of type of_port_desc_prop_bsn_diag.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_diag.
 * @param exp_type Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_diag_exp_type_get(
    of_port_desc_prop_bsn_diag_t *obj,
    uint32_t *exp_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_DIAG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, exp_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set exp_type in an object of type of_port_desc_prop_bsn_diag.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_diag.
 * @param exp_type The value to write into the object
 */
void
of_port_desc_prop_bsn_diag_exp_type_set(
    of_port_desc_prop_bsn_diag_t *obj,
    uint32_t exp_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_DIAG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, exp_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Bind an object of type of_bsn_unit_t to the parent of type of_port_desc_prop_bsn_diag for
 * member laser_bias_curr
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_diag.
 * @param laser_bias_curr Pointer to the child object of type
 * of_bsn_unit_t to be filled out.
 * \ingroup of_port_desc_prop_bsn_diag
 *
 * The parameter laser_bias_curr is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_port_desc_prop_bsn_diag_laser_bias_curr_bind(
    of_port_desc_prop_bsn_diag_t *obj,
    of_bsn_unit_t *laser_bias_curr)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_DIAG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 12;
        cur_len = 5;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_bsn_unit_init(laser_bias_curr, obj->version, 0, 1);
    /* Attach to parent */
    of_object_attach(obj, laser_bias_curr, offset, cur_len);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of laser_bias_curr into a new variable of type of_bsn_unit_t from
 * a of_port_desc_prop_bsn_diag instance.
 *
 * @param obj Pointer to the source of type of_port_desc_prop_bsn_diag_t
 * @returns A pointer to a new instance of type of_bsn_unit_t whose contents
 * match that of laser_bias_curr from source
 * @returns NULL if an error occurs
 */
of_bsn_unit_t *
of_port_desc_prop_bsn_diag_laser_bias_curr_get(of_port_desc_prop_bsn_diag_t *obj) {
    of_bsn_unit_t _laser_bias_curr;
    of_bsn_unit_t *_laser_bias_curr_ptr;

    of_port_desc_prop_bsn_diag_laser_bias_curr_bind(obj, &_laser_bias_curr);
    _laser_bias_curr_ptr = (of_bsn_unit_t *)of_object_dup(&_laser_bias_curr);
    return _laser_bias_curr_ptr;
}

/**
 * Set laser_bias_curr in an object of type of_port_desc_prop_bsn_diag.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_diag.
 * @param laser_bias_curr Pointer to the child of type of_bsn_unit_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_port_desc_prop_bsn_diag_laser_bias_curr_set(
    of_port_desc_prop_bsn_diag_t *obj,
    of_bsn_unit_t *laser_bias_curr)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_DIAG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 12;
        cur_len = 5;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = laser_bias_curr->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wbuf == laser_bias_curr->wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(laser_bias_curr, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(laser_bias_curr, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    of_object_wire_length_set((of_object_t *)laser_bias_curr, laser_bias_curr->length);

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
 * Bind an object of type of_bsn_unit_t to the parent of type of_port_desc_prop_bsn_diag for
 * member laser_output_power
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_diag.
 * @param laser_output_power Pointer to the child object of type
 * of_bsn_unit_t to be filled out.
 * \ingroup of_port_desc_prop_bsn_diag
 *
 * The parameter laser_output_power is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_port_desc_prop_bsn_diag_laser_output_power_bind(
    of_port_desc_prop_bsn_diag_t *obj,
    of_bsn_unit_t *laser_output_power)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_DIAG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 17;
        cur_len = 5;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_bsn_unit_init(laser_output_power, obj->version, 0, 1);
    /* Attach to parent */
    of_object_attach(obj, laser_output_power, offset, cur_len);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of laser_output_power into a new variable of type of_bsn_unit_t from
 * a of_port_desc_prop_bsn_diag instance.
 *
 * @param obj Pointer to the source of type of_port_desc_prop_bsn_diag_t
 * @returns A pointer to a new instance of type of_bsn_unit_t whose contents
 * match that of laser_output_power from source
 * @returns NULL if an error occurs
 */
of_bsn_unit_t *
of_port_desc_prop_bsn_diag_laser_output_power_get(of_port_desc_prop_bsn_diag_t *obj) {
    of_bsn_unit_t _laser_output_power;
    of_bsn_unit_t *_laser_output_power_ptr;

    of_port_desc_prop_bsn_diag_laser_output_power_bind(obj, &_laser_output_power);
    _laser_output_power_ptr = (of_bsn_unit_t *)of_object_dup(&_laser_output_power);
    return _laser_output_power_ptr;
}

/**
 * Set laser_output_power in an object of type of_port_desc_prop_bsn_diag.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_diag.
 * @param laser_output_power Pointer to the child of type of_bsn_unit_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_port_desc_prop_bsn_diag_laser_output_power_set(
    of_port_desc_prop_bsn_diag_t *obj,
    of_bsn_unit_t *laser_output_power)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_DIAG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 17;
        cur_len = 5;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = laser_output_power->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wbuf == laser_output_power->wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(laser_output_power, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(laser_output_power, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    of_object_wire_length_set((of_object_t *)laser_output_power, laser_output_power->length);

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
 * Get laser_receiver_power_type from an object of type of_port_desc_prop_bsn_diag.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_diag.
 * @param laser_receiver_power_type Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_diag_laser_receiver_power_type_get(
    of_port_desc_prop_bsn_diag_t *obj,
    uint8_t *laser_receiver_power_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_DIAG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 22;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, laser_receiver_power_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set laser_receiver_power_type in an object of type of_port_desc_prop_bsn_diag.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_diag.
 * @param laser_receiver_power_type The value to write into the object
 */
void
of_port_desc_prop_bsn_diag_laser_receiver_power_type_set(
    of_port_desc_prop_bsn_diag_t *obj,
    uint8_t laser_receiver_power_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_DIAG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 22;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, laser_receiver_power_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Bind an object of type of_bsn_unit_t to the parent of type of_port_desc_prop_bsn_diag for
 * member laser_receiver_power
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_diag.
 * @param laser_receiver_power Pointer to the child object of type
 * of_bsn_unit_t to be filled out.
 * \ingroup of_port_desc_prop_bsn_diag
 *
 * The parameter laser_receiver_power is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_port_desc_prop_bsn_diag_laser_receiver_power_bind(
    of_port_desc_prop_bsn_diag_t *obj,
    of_bsn_unit_t *laser_receiver_power)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_DIAG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 23;
        cur_len = 5;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_bsn_unit_init(laser_receiver_power, obj->version, 0, 1);
    /* Attach to parent */
    of_object_attach(obj, laser_receiver_power, offset, cur_len);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of laser_receiver_power into a new variable of type of_bsn_unit_t from
 * a of_port_desc_prop_bsn_diag instance.
 *
 * @param obj Pointer to the source of type of_port_desc_prop_bsn_diag_t
 * @returns A pointer to a new instance of type of_bsn_unit_t whose contents
 * match that of laser_receiver_power from source
 * @returns NULL if an error occurs
 */
of_bsn_unit_t *
of_port_desc_prop_bsn_diag_laser_receiver_power_get(of_port_desc_prop_bsn_diag_t *obj) {
    of_bsn_unit_t _laser_receiver_power;
    of_bsn_unit_t *_laser_receiver_power_ptr;

    of_port_desc_prop_bsn_diag_laser_receiver_power_bind(obj, &_laser_receiver_power);
    _laser_receiver_power_ptr = (of_bsn_unit_t *)of_object_dup(&_laser_receiver_power);
    return _laser_receiver_power_ptr;
}

/**
 * Set laser_receiver_power in an object of type of_port_desc_prop_bsn_diag.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_diag.
 * @param laser_receiver_power Pointer to the child of type of_bsn_unit_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_port_desc_prop_bsn_diag_laser_receiver_power_set(
    of_port_desc_prop_bsn_diag_t *obj,
    of_bsn_unit_t *laser_receiver_power)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_DIAG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 23;
        cur_len = 5;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = laser_receiver_power->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wbuf == laser_receiver_power->wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(laser_receiver_power, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(laser_receiver_power, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    of_object_wire_length_set((of_object_t *)laser_receiver_power, laser_receiver_power->length);

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
 * Bind an object of type of_bsn_unit_t to the parent of type of_port_desc_prop_bsn_diag for
 * member module_temp
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_diag.
 * @param module_temp Pointer to the child object of type
 * of_bsn_unit_t to be filled out.
 * \ingroup of_port_desc_prop_bsn_diag
 *
 * The parameter module_temp is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_port_desc_prop_bsn_diag_module_temp_bind(
    of_port_desc_prop_bsn_diag_t *obj,
    of_bsn_unit_t *module_temp)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_DIAG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 28;
        cur_len = 5;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_bsn_unit_init(module_temp, obj->version, 0, 1);
    /* Attach to parent */
    of_object_attach(obj, module_temp, offset, cur_len);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of module_temp into a new variable of type of_bsn_unit_t from
 * a of_port_desc_prop_bsn_diag instance.
 *
 * @param obj Pointer to the source of type of_port_desc_prop_bsn_diag_t
 * @returns A pointer to a new instance of type of_bsn_unit_t whose contents
 * match that of module_temp from source
 * @returns NULL if an error occurs
 */
of_bsn_unit_t *
of_port_desc_prop_bsn_diag_module_temp_get(of_port_desc_prop_bsn_diag_t *obj) {
    of_bsn_unit_t _module_temp;
    of_bsn_unit_t *_module_temp_ptr;

    of_port_desc_prop_bsn_diag_module_temp_bind(obj, &_module_temp);
    _module_temp_ptr = (of_bsn_unit_t *)of_object_dup(&_module_temp);
    return _module_temp_ptr;
}

/**
 * Set module_temp in an object of type of_port_desc_prop_bsn_diag.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_diag.
 * @param module_temp Pointer to the child of type of_bsn_unit_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_port_desc_prop_bsn_diag_module_temp_set(
    of_port_desc_prop_bsn_diag_t *obj,
    of_bsn_unit_t *module_temp)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_DIAG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 28;
        cur_len = 5;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = module_temp->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wbuf == module_temp->wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(module_temp, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(module_temp, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    of_object_wire_length_set((of_object_t *)module_temp, module_temp->length);

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
 * Bind an object of type of_bsn_unit_t to the parent of type of_port_desc_prop_bsn_diag for
 * member module_voltage
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_diag.
 * @param module_voltage Pointer to the child object of type
 * of_bsn_unit_t to be filled out.
 * \ingroup of_port_desc_prop_bsn_diag
 *
 * The parameter module_voltage is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_port_desc_prop_bsn_diag_module_voltage_bind(
    of_port_desc_prop_bsn_diag_t *obj,
    of_bsn_unit_t *module_voltage)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_DIAG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 33;
        cur_len = 5;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_bsn_unit_init(module_voltage, obj->version, 0, 1);
    /* Attach to parent */
    of_object_attach(obj, module_voltage, offset, cur_len);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of module_voltage into a new variable of type of_bsn_unit_t from
 * a of_port_desc_prop_bsn_diag instance.
 *
 * @param obj Pointer to the source of type of_port_desc_prop_bsn_diag_t
 * @returns A pointer to a new instance of type of_bsn_unit_t whose contents
 * match that of module_voltage from source
 * @returns NULL if an error occurs
 */
of_bsn_unit_t *
of_port_desc_prop_bsn_diag_module_voltage_get(of_port_desc_prop_bsn_diag_t *obj) {
    of_bsn_unit_t _module_voltage;
    of_bsn_unit_t *_module_voltage_ptr;

    of_port_desc_prop_bsn_diag_module_voltage_bind(obj, &_module_voltage);
    _module_voltage_ptr = (of_bsn_unit_t *)of_object_dup(&_module_voltage);
    return _module_voltage_ptr;
}

/**
 * Set module_voltage in an object of type of_port_desc_prop_bsn_diag.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_diag.
 * @param module_voltage Pointer to the child of type of_bsn_unit_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_port_desc_prop_bsn_diag_module_voltage_set(
    of_port_desc_prop_bsn_diag_t *obj,
    of_bsn_unit_t *module_voltage)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_DIAG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 33;
        cur_len = 5;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = module_voltage->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wbuf == module_voltage->wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(module_voltage, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(module_voltage, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    of_object_wire_length_set((of_object_t *)module_voltage, module_voltage->length);

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
 * \defgroup ofp_bsn_module_eeprom_transceiver ofp_bsn_module_eeprom_transceiver
 */

/**
 * Create a new ofp_bsn_module_eeprom_transceiver object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup ofp_bsn_module_eeprom_transceiver
 */

of_object_t *
ofp_bsn_module_eeprom_transceiver_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OFP_BSN_MODULE_EEPROM_TRANSCEIVER];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    ofp_bsn_module_eeprom_transceiver_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type ofp_bsn_module_eeprom_transceiver.
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
ofp_bsn_module_eeprom_transceiver_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OFP_BSN_MODULE_EEPROM_TRANSCEIVER] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OFP_BSN_MODULE_EEPROM_TRANSCEIVER];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OFP_BSN_MODULE_EEPROM_TRANSCEIVER;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get codes from an object of type ofp_bsn_module_eeprom_transceiver.
 * @param obj Pointer to an object of type ofp_bsn_module_eeprom_transceiver.
 * @param codes Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
ofp_bsn_module_eeprom_transceiver_codes_get(
    ofp_bsn_module_eeprom_transceiver_t *obj,
    uint64_t *codes)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OFP_BSN_MODULE_EEPROM_TRANSCEIVER);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 0;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, codes);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set codes in an object of type ofp_bsn_module_eeprom_transceiver.
 * @param obj Pointer to an object of type ofp_bsn_module_eeprom_transceiver.
 * @param codes The value to write into the object
 */
void
ofp_bsn_module_eeprom_transceiver_codes_set(
    ofp_bsn_module_eeprom_transceiver_t *obj,
    uint64_t codes)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OFP_BSN_MODULE_EEPROM_TRANSCEIVER);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 0;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, codes);

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
of_port_desc_prop_bsn_ethtool_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xffff); /* type */
        *(uint32_t *)(buf + 4) = U32_HTON(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 8) = U32_HTON(0x6); /* exp_type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_port_desc_prop_bsn_ethtool of_port_desc_prop_bsn_ethtool
 */

/**
 * Create a new of_port_desc_prop_bsn_ethtool object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_port_desc_prop_bsn_ethtool
 */

of_object_t *
of_port_desc_prop_bsn_ethtool_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_PORT_DESC_PROP_BSN_ETHTOOL];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_port_desc_prop_bsn_ethtool_init(obj, version, bytes, 0);
    of_port_desc_prop_bsn_ethtool_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_port_desc_prop_bsn_ethtool.
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
of_port_desc_prop_bsn_ethtool_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_PORT_DESC_PROP_BSN_ETHTOOL] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_PORT_DESC_PROP_BSN_ETHTOOL];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_PORT_DESC_PROP_BSN_ETHTOOL;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get experimenter from an object of type of_port_desc_prop_bsn_ethtool.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_ethtool_experimenter_get(
    of_port_desc_prop_bsn_ethtool_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
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
 * Set experimenter in an object of type of_port_desc_prop_bsn_ethtool.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param experimenter The value to write into the object
 */
void
of_port_desc_prop_bsn_ethtool_experimenter_set(
    of_port_desc_prop_bsn_ethtool_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
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
 * Get exp_type from an object of type of_port_desc_prop_bsn_ethtool.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param exp_type Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_ethtool_exp_type_get(
    of_port_desc_prop_bsn_ethtool_t *obj,
    uint32_t *exp_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, exp_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set exp_type in an object of type of_port_desc_prop_bsn_ethtool.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param exp_type The value to write into the object
 */
void
of_port_desc_prop_bsn_ethtool_exp_type_set(
    of_port_desc_prop_bsn_ethtool_t *obj,
    uint32_t exp_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, exp_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get identifier from an object of type of_port_desc_prop_bsn_ethtool.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param identifier Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_ethtool_identifier_get(
    of_port_desc_prop_bsn_ethtool_t *obj,
    uint8_t *identifier)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, identifier);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set identifier in an object of type of_port_desc_prop_bsn_ethtool.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param identifier The value to write into the object
 */
void
of_port_desc_prop_bsn_ethtool_identifier_set(
    of_port_desc_prop_bsn_ethtool_t *obj,
    uint8_t identifier)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, identifier);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get extidentifier from an object of type of_port_desc_prop_bsn_ethtool.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param extidentifier Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_ethtool_extidentifier_get(
    of_port_desc_prop_bsn_ethtool_t *obj,
    uint8_t *extidentifier)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 13;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, extidentifier);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set extidentifier in an object of type of_port_desc_prop_bsn_ethtool.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param extidentifier The value to write into the object
 */
void
of_port_desc_prop_bsn_ethtool_extidentifier_set(
    of_port_desc_prop_bsn_ethtool_t *obj,
    uint8_t extidentifier)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 13;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, extidentifier);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get connector from an object of type of_port_desc_prop_bsn_ethtool.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param connector Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_ethtool_connector_get(
    of_port_desc_prop_bsn_ethtool_t *obj,
    uint8_t *connector)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 14;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, connector);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set connector in an object of type of_port_desc_prop_bsn_ethtool.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param connector The value to write into the object
 */
void
of_port_desc_prop_bsn_ethtool_connector_set(
    of_port_desc_prop_bsn_ethtool_t *obj,
    uint8_t connector)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 14;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, connector);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Bind an object of type ofp_bsn_module_eeprom_transceiver_t to the parent of type of_port_desc_prop_bsn_ethtool for
 * member transdata
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param transdata Pointer to the child object of type
 * ofp_bsn_module_eeprom_transceiver_t to be filled out.
 * \ingroup of_port_desc_prop_bsn_ethtool
 *
 * The parameter transdata is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_port_desc_prop_bsn_ethtool_transdata_bind(
    of_port_desc_prop_bsn_ethtool_t *obj,
    ofp_bsn_module_eeprom_transceiver_t *transdata)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 15;
        cur_len = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    ofp_bsn_module_eeprom_transceiver_init(transdata, obj->version, 0, 1);
    /* Attach to parent */
    of_object_attach(obj, transdata, offset, cur_len);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of transdata into a new variable of type ofp_bsn_module_eeprom_transceiver_t from
 * a of_port_desc_prop_bsn_ethtool instance.
 *
 * @param obj Pointer to the source of type of_port_desc_prop_bsn_ethtool_t
 * @returns A pointer to a new instance of type ofp_bsn_module_eeprom_transceiver_t whose contents
 * match that of transdata from source
 * @returns NULL if an error occurs
 */
ofp_bsn_module_eeprom_transceiver_t *
of_port_desc_prop_bsn_ethtool_transdata_get(of_port_desc_prop_bsn_ethtool_t *obj) {
    ofp_bsn_module_eeprom_transceiver_t _transdata;
    ofp_bsn_module_eeprom_transceiver_t *_transdata_ptr;

    of_port_desc_prop_bsn_ethtool_transdata_bind(obj, &_transdata);
    _transdata_ptr = (ofp_bsn_module_eeprom_transceiver_t *)of_object_dup(&_transdata);
    return _transdata_ptr;
}

/**
 * Set transdata in an object of type of_port_desc_prop_bsn_ethtool.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param transdata Pointer to the child of type ofp_bsn_module_eeprom_transceiver_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_port_desc_prop_bsn_ethtool_transdata_set(
    of_port_desc_prop_bsn_ethtool_t *obj,
    ofp_bsn_module_eeprom_transceiver_t *transdata)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 15;
        cur_len = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = transdata->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wbuf == transdata->wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(transdata, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(transdata, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    of_object_wire_length_set((of_object_t *)transdata, transdata->length);

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
 * Get encoding from an object of type of_port_desc_prop_bsn_ethtool.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param encoding Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_ethtool_encoding_get(
    of_port_desc_prop_bsn_ethtool_t *obj,
    uint8_t *encoding)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 23;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, encoding);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set encoding in an object of type of_port_desc_prop_bsn_ethtool.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param encoding The value to write into the object
 */
void
of_port_desc_prop_bsn_ethtool_encoding_set(
    of_port_desc_prop_bsn_ethtool_t *obj,
    uint8_t encoding)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 23;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, encoding);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Bind an object of type of_bsn_unit_t to the parent of type of_port_desc_prop_bsn_ethtool for
 * member br_nominal
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param br_nominal Pointer to the child object of type
 * of_bsn_unit_t to be filled out.
 * \ingroup of_port_desc_prop_bsn_ethtool
 *
 * The parameter br_nominal is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_port_desc_prop_bsn_ethtool_br_nominal_bind(
    of_port_desc_prop_bsn_ethtool_t *obj,
    of_bsn_unit_t *br_nominal)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 24;
        cur_len = 5;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_bsn_unit_init(br_nominal, obj->version, 0, 1);
    /* Attach to parent */
    of_object_attach(obj, br_nominal, offset, cur_len);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of br_nominal into a new variable of type of_bsn_unit_t from
 * a of_port_desc_prop_bsn_ethtool instance.
 *
 * @param obj Pointer to the source of type of_port_desc_prop_bsn_ethtool_t
 * @returns A pointer to a new instance of type of_bsn_unit_t whose contents
 * match that of br_nominal from source
 * @returns NULL if an error occurs
 */
of_bsn_unit_t *
of_port_desc_prop_bsn_ethtool_br_nominal_get(of_port_desc_prop_bsn_ethtool_t *obj) {
    of_bsn_unit_t _br_nominal;
    of_bsn_unit_t *_br_nominal_ptr;

    of_port_desc_prop_bsn_ethtool_br_nominal_bind(obj, &_br_nominal);
    _br_nominal_ptr = (of_bsn_unit_t *)of_object_dup(&_br_nominal);
    return _br_nominal_ptr;
}

/**
 * Set br_nominal in an object of type of_port_desc_prop_bsn_ethtool.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param br_nominal Pointer to the child of type of_bsn_unit_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_port_desc_prop_bsn_ethtool_br_nominal_set(
    of_port_desc_prop_bsn_ethtool_t *obj,
    of_bsn_unit_t *br_nominal)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 24;
        cur_len = 5;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = br_nominal->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wbuf == br_nominal->wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(br_nominal, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(br_nominal, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    of_object_wire_length_set((of_object_t *)br_nominal, br_nominal->length);

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
 * Get rateidentifier from an object of type of_port_desc_prop_bsn_ethtool.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param rateidentifier Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_ethtool_rateidentifier_get(
    of_port_desc_prop_bsn_ethtool_t *obj,
    uint8_t *rateidentifier)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 29;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, rateidentifier);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set rateidentifier in an object of type of_port_desc_prop_bsn_ethtool.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param rateidentifier The value to write into the object
 */
void
of_port_desc_prop_bsn_ethtool_rateidentifier_set(
    of_port_desc_prop_bsn_ethtool_t *obj,
    uint8_t rateidentifier)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 29;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, rateidentifier);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Bind an object of type of_bsn_unit_t to the parent of type of_port_desc_prop_bsn_ethtool for
 * member length_SMF_KM
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param length_SMF_KM Pointer to the child object of type
 * of_bsn_unit_t to be filled out.
 * \ingroup of_port_desc_prop_bsn_ethtool
 *
 * The parameter length_SMF_KM is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_port_desc_prop_bsn_ethtool_length_SMF_KM_bind(
    of_port_desc_prop_bsn_ethtool_t *obj,
    of_bsn_unit_t *length_SMF_KM)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 30;
        cur_len = 5;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_bsn_unit_init(length_SMF_KM, obj->version, 0, 1);
    /* Attach to parent */
    of_object_attach(obj, length_SMF_KM, offset, cur_len);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of length_SMF_KM into a new variable of type of_bsn_unit_t from
 * a of_port_desc_prop_bsn_ethtool instance.
 *
 * @param obj Pointer to the source of type of_port_desc_prop_bsn_ethtool_t
 * @returns A pointer to a new instance of type of_bsn_unit_t whose contents
 * match that of length_SMF_KM from source
 * @returns NULL if an error occurs
 */
of_bsn_unit_t *
of_port_desc_prop_bsn_ethtool_length_SMF_KM_get(of_port_desc_prop_bsn_ethtool_t *obj) {
    of_bsn_unit_t _length_SMF_KM;
    of_bsn_unit_t *_length_SMF_KM_ptr;

    of_port_desc_prop_bsn_ethtool_length_SMF_KM_bind(obj, &_length_SMF_KM);
    _length_SMF_KM_ptr = (of_bsn_unit_t *)of_object_dup(&_length_SMF_KM);
    return _length_SMF_KM_ptr;
}

/**
 * Set length_SMF_KM in an object of type of_port_desc_prop_bsn_ethtool.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param length_SMF_KM Pointer to the child of type of_bsn_unit_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_port_desc_prop_bsn_ethtool_length_SMF_KM_set(
    of_port_desc_prop_bsn_ethtool_t *obj,
    of_bsn_unit_t *length_SMF_KM)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 30;
        cur_len = 5;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = length_SMF_KM->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wbuf == length_SMF_KM->wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(length_SMF_KM, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(length_SMF_KM, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    of_object_wire_length_set((of_object_t *)length_SMF_KM, length_SMF_KM->length);

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
 * Bind an object of type of_bsn_unit_t to the parent of type of_port_desc_prop_bsn_ethtool for
 * member length_SMF
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param length_SMF Pointer to the child object of type
 * of_bsn_unit_t to be filled out.
 * \ingroup of_port_desc_prop_bsn_ethtool
 *
 * The parameter length_SMF is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_port_desc_prop_bsn_ethtool_length_SMF_bind(
    of_port_desc_prop_bsn_ethtool_t *obj,
    of_bsn_unit_t *length_SMF)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 35;
        cur_len = 5;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_bsn_unit_init(length_SMF, obj->version, 0, 1);
    /* Attach to parent */
    of_object_attach(obj, length_SMF, offset, cur_len);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of length_SMF into a new variable of type of_bsn_unit_t from
 * a of_port_desc_prop_bsn_ethtool instance.
 *
 * @param obj Pointer to the source of type of_port_desc_prop_bsn_ethtool_t
 * @returns A pointer to a new instance of type of_bsn_unit_t whose contents
 * match that of length_SMF from source
 * @returns NULL if an error occurs
 */
of_bsn_unit_t *
of_port_desc_prop_bsn_ethtool_length_SMF_get(of_port_desc_prop_bsn_ethtool_t *obj) {
    of_bsn_unit_t _length_SMF;
    of_bsn_unit_t *_length_SMF_ptr;

    of_port_desc_prop_bsn_ethtool_length_SMF_bind(obj, &_length_SMF);
    _length_SMF_ptr = (of_bsn_unit_t *)of_object_dup(&_length_SMF);
    return _length_SMF_ptr;
}

/**
 * Set length_SMF in an object of type of_port_desc_prop_bsn_ethtool.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param length_SMF Pointer to the child of type of_bsn_unit_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_port_desc_prop_bsn_ethtool_length_SMF_set(
    of_port_desc_prop_bsn_ethtool_t *obj,
    of_bsn_unit_t *length_SMF)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 35;
        cur_len = 5;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = length_SMF->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wbuf == length_SMF->wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(length_SMF, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(length_SMF, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    of_object_wire_length_set((of_object_t *)length_SMF, length_SMF->length);

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
 * Bind an object of type of_bsn_unit_t to the parent of type of_port_desc_prop_bsn_ethtool for
 * member length_50_um
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param length_50_um Pointer to the child object of type
 * of_bsn_unit_t to be filled out.
 * \ingroup of_port_desc_prop_bsn_ethtool
 *
 * The parameter length_50_um is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_port_desc_prop_bsn_ethtool_length_50_um_bind(
    of_port_desc_prop_bsn_ethtool_t *obj,
    of_bsn_unit_t *length_50_um)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 40;
        cur_len = 5;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_bsn_unit_init(length_50_um, obj->version, 0, 1);
    /* Attach to parent */
    of_object_attach(obj, length_50_um, offset, cur_len);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of length_50_um into a new variable of type of_bsn_unit_t from
 * a of_port_desc_prop_bsn_ethtool instance.
 *
 * @param obj Pointer to the source of type of_port_desc_prop_bsn_ethtool_t
 * @returns A pointer to a new instance of type of_bsn_unit_t whose contents
 * match that of length_50_um from source
 * @returns NULL if an error occurs
 */
of_bsn_unit_t *
of_port_desc_prop_bsn_ethtool_length_50_um_get(of_port_desc_prop_bsn_ethtool_t *obj) {
    of_bsn_unit_t _length_50_um;
    of_bsn_unit_t *_length_50_um_ptr;

    of_port_desc_prop_bsn_ethtool_length_50_um_bind(obj, &_length_50_um);
    _length_50_um_ptr = (of_bsn_unit_t *)of_object_dup(&_length_50_um);
    return _length_50_um_ptr;
}

/**
 * Set length_50_um in an object of type of_port_desc_prop_bsn_ethtool.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param length_50_um Pointer to the child of type of_bsn_unit_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_port_desc_prop_bsn_ethtool_length_50_um_set(
    of_port_desc_prop_bsn_ethtool_t *obj,
    of_bsn_unit_t *length_50_um)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 40;
        cur_len = 5;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = length_50_um->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wbuf == length_50_um->wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(length_50_um, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(length_50_um, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    of_object_wire_length_set((of_object_t *)length_50_um, length_50_um->length);

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
 * Bind an object of type of_bsn_unit_t to the parent of type of_port_desc_prop_bsn_ethtool for
 * member length_625_um
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param length_625_um Pointer to the child object of type
 * of_bsn_unit_t to be filled out.
 * \ingroup of_port_desc_prop_bsn_ethtool
 *
 * The parameter length_625_um is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_port_desc_prop_bsn_ethtool_length_625_um_bind(
    of_port_desc_prop_bsn_ethtool_t *obj,
    of_bsn_unit_t *length_625_um)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 45;
        cur_len = 5;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_bsn_unit_init(length_625_um, obj->version, 0, 1);
    /* Attach to parent */
    of_object_attach(obj, length_625_um, offset, cur_len);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of length_625_um into a new variable of type of_bsn_unit_t from
 * a of_port_desc_prop_bsn_ethtool instance.
 *
 * @param obj Pointer to the source of type of_port_desc_prop_bsn_ethtool_t
 * @returns A pointer to a new instance of type of_bsn_unit_t whose contents
 * match that of length_625_um from source
 * @returns NULL if an error occurs
 */
of_bsn_unit_t *
of_port_desc_prop_bsn_ethtool_length_625_um_get(of_port_desc_prop_bsn_ethtool_t *obj) {
    of_bsn_unit_t _length_625_um;
    of_bsn_unit_t *_length_625_um_ptr;

    of_port_desc_prop_bsn_ethtool_length_625_um_bind(obj, &_length_625_um);
    _length_625_um_ptr = (of_bsn_unit_t *)of_object_dup(&_length_625_um);
    return _length_625_um_ptr;
}

/**
 * Set length_625_um in an object of type of_port_desc_prop_bsn_ethtool.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param length_625_um Pointer to the child of type of_bsn_unit_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_port_desc_prop_bsn_ethtool_length_625_um_set(
    of_port_desc_prop_bsn_ethtool_t *obj,
    of_bsn_unit_t *length_625_um)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 45;
        cur_len = 5;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = length_625_um->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wbuf == length_625_um->wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(length_625_um, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(length_625_um, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    of_object_wire_length_set((of_object_t *)length_625_um, length_625_um->length);

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
 * Bind an object of type of_bsn_unit_t to the parent of type of_port_desc_prop_bsn_ethtool for
 * member length_copper
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param length_copper Pointer to the child object of type
 * of_bsn_unit_t to be filled out.
 * \ingroup of_port_desc_prop_bsn_ethtool
 *
 * The parameter length_copper is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_port_desc_prop_bsn_ethtool_length_copper_bind(
    of_port_desc_prop_bsn_ethtool_t *obj,
    of_bsn_unit_t *length_copper)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 50;
        cur_len = 5;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_bsn_unit_init(length_copper, obj->version, 0, 1);
    /* Attach to parent */
    of_object_attach(obj, length_copper, offset, cur_len);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of length_copper into a new variable of type of_bsn_unit_t from
 * a of_port_desc_prop_bsn_ethtool instance.
 *
 * @param obj Pointer to the source of type of_port_desc_prop_bsn_ethtool_t
 * @returns A pointer to a new instance of type of_bsn_unit_t whose contents
 * match that of length_copper from source
 * @returns NULL if an error occurs
 */
of_bsn_unit_t *
of_port_desc_prop_bsn_ethtool_length_copper_get(of_port_desc_prop_bsn_ethtool_t *obj) {
    of_bsn_unit_t _length_copper;
    of_bsn_unit_t *_length_copper_ptr;

    of_port_desc_prop_bsn_ethtool_length_copper_bind(obj, &_length_copper);
    _length_copper_ptr = (of_bsn_unit_t *)of_object_dup(&_length_copper);
    return _length_copper_ptr;
}

/**
 * Set length_copper in an object of type of_port_desc_prop_bsn_ethtool.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param length_copper Pointer to the child of type of_bsn_unit_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_port_desc_prop_bsn_ethtool_length_copper_set(
    of_port_desc_prop_bsn_ethtool_t *obj,
    of_bsn_unit_t *length_copper)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 50;
        cur_len = 5;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = length_copper->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wbuf == length_copper->wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(length_copper, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(length_copper, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    of_object_wire_length_set((of_object_t *)length_copper, length_copper->length);

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
 * Bind an object of type of_bsn_unit_t to the parent of type of_port_desc_prop_bsn_ethtool for
 * member length_OM3
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param length_OM3 Pointer to the child object of type
 * of_bsn_unit_t to be filled out.
 * \ingroup of_port_desc_prop_bsn_ethtool
 *
 * The parameter length_OM3 is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_port_desc_prop_bsn_ethtool_length_OM3_bind(
    of_port_desc_prop_bsn_ethtool_t *obj,
    of_bsn_unit_t *length_OM3)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 55;
        cur_len = 5;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_bsn_unit_init(length_OM3, obj->version, 0, 1);
    /* Attach to parent */
    of_object_attach(obj, length_OM3, offset, cur_len);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of length_OM3 into a new variable of type of_bsn_unit_t from
 * a of_port_desc_prop_bsn_ethtool instance.
 *
 * @param obj Pointer to the source of type of_port_desc_prop_bsn_ethtool_t
 * @returns A pointer to a new instance of type of_bsn_unit_t whose contents
 * match that of length_OM3 from source
 * @returns NULL if an error occurs
 */
of_bsn_unit_t *
of_port_desc_prop_bsn_ethtool_length_OM3_get(of_port_desc_prop_bsn_ethtool_t *obj) {
    of_bsn_unit_t _length_OM3;
    of_bsn_unit_t *_length_OM3_ptr;

    of_port_desc_prop_bsn_ethtool_length_OM3_bind(obj, &_length_OM3);
    _length_OM3_ptr = (of_bsn_unit_t *)of_object_dup(&_length_OM3);
    return _length_OM3_ptr;
}

/**
 * Set length_OM3 in an object of type of_port_desc_prop_bsn_ethtool.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param length_OM3 Pointer to the child of type of_bsn_unit_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_port_desc_prop_bsn_ethtool_length_OM3_set(
    of_port_desc_prop_bsn_ethtool_t *obj,
    of_bsn_unit_t *length_OM3)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 55;
        cur_len = 5;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = length_OM3->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wbuf == length_OM3->wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(length_OM3, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(length_OM3, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    of_object_wire_length_set((of_object_t *)length_OM3, length_OM3->length);

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
 * Get vendor_name_lo from an object of type of_port_desc_prop_bsn_ethtool.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param vendor_name_lo Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_ethtool_vendor_name_lo_get(
    of_port_desc_prop_bsn_ethtool_t *obj,
    uint64_t *vendor_name_lo)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 60;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, vendor_name_lo);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set vendor_name_lo in an object of type of_port_desc_prop_bsn_ethtool.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param vendor_name_lo The value to write into the object
 */
void
of_port_desc_prop_bsn_ethtool_vendor_name_lo_set(
    of_port_desc_prop_bsn_ethtool_t *obj,
    uint64_t vendor_name_lo)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 60;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, vendor_name_lo);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get vendor_name_hi from an object of type of_port_desc_prop_bsn_ethtool.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param vendor_name_hi Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_ethtool_vendor_name_hi_get(
    of_port_desc_prop_bsn_ethtool_t *obj,
    uint64_t *vendor_name_hi)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 68;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, vendor_name_hi);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set vendor_name_hi in an object of type of_port_desc_prop_bsn_ethtool.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param vendor_name_hi The value to write into the object
 */
void
of_port_desc_prop_bsn_ethtool_vendor_name_hi_set(
    of_port_desc_prop_bsn_ethtool_t *obj,
    uint64_t vendor_name_hi)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 68;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, vendor_name_hi);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get vendor_oui from an object of type of_port_desc_prop_bsn_ethtool.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param vendor_oui Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_ethtool_vendor_oui_get(
    of_port_desc_prop_bsn_ethtool_t *obj,
    uint32_t *vendor_oui)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 76;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, vendor_oui);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set vendor_oui in an object of type of_port_desc_prop_bsn_ethtool.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param vendor_oui The value to write into the object
 */
void
of_port_desc_prop_bsn_ethtool_vendor_oui_set(
    of_port_desc_prop_bsn_ethtool_t *obj,
    uint32_t vendor_oui)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 76;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, vendor_oui);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get vendor_pn_lo from an object of type of_port_desc_prop_bsn_ethtool.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param vendor_pn_lo Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_ethtool_vendor_pn_lo_get(
    of_port_desc_prop_bsn_ethtool_t *obj,
    uint64_t *vendor_pn_lo)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 80;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, vendor_pn_lo);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set vendor_pn_lo in an object of type of_port_desc_prop_bsn_ethtool.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param vendor_pn_lo The value to write into the object
 */
void
of_port_desc_prop_bsn_ethtool_vendor_pn_lo_set(
    of_port_desc_prop_bsn_ethtool_t *obj,
    uint64_t vendor_pn_lo)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 80;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, vendor_pn_lo);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get vendor_pn_hi from an object of type of_port_desc_prop_bsn_ethtool.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param vendor_pn_hi Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_ethtool_vendor_pn_hi_get(
    of_port_desc_prop_bsn_ethtool_t *obj,
    uint64_t *vendor_pn_hi)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 88;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, vendor_pn_hi);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set vendor_pn_hi in an object of type of_port_desc_prop_bsn_ethtool.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param vendor_pn_hi The value to write into the object
 */
void
of_port_desc_prop_bsn_ethtool_vendor_pn_hi_set(
    of_port_desc_prop_bsn_ethtool_t *obj,
    uint64_t vendor_pn_hi)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 88;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, vendor_pn_hi);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get vendor_rev from an object of type of_port_desc_prop_bsn_ethtool.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param vendor_rev Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_ethtool_vendor_rev_get(
    of_port_desc_prop_bsn_ethtool_t *obj,
    uint32_t *vendor_rev)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 96;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, vendor_rev);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set vendor_rev in an object of type of_port_desc_prop_bsn_ethtool.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param vendor_rev The value to write into the object
 */
void
of_port_desc_prop_bsn_ethtool_vendor_rev_set(
    of_port_desc_prop_bsn_ethtool_t *obj,
    uint32_t vendor_rev)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 96;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, vendor_rev);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Bind an object of type of_list_port_desc_prop_t to the parent of type of_port_desc_prop_bsn_ethtool for
 * member more_properties
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param more_properties Pointer to the child object of type
 * of_list_port_desc_prop_t to be filled out.
 * \ingroup of_port_desc_prop_bsn_ethtool
 *
 * The parameter more_properties is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_port_desc_prop_bsn_ethtool_more_properties_bind(
    of_port_desc_prop_bsn_ethtool_t *obj,
    of_list_port_desc_prop_t *more_properties)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 100;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_list_port_desc_prop_init(more_properties, obj->version, 0, 1);
    /* Attach to parent */
    of_object_attach(obj, more_properties, offset, cur_len);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of more_properties into a new variable of type of_list_port_desc_prop_t from
 * a of_port_desc_prop_bsn_ethtool instance.
 *
 * @param obj Pointer to the source of type of_port_desc_prop_bsn_ethtool_t
 * @returns A pointer to a new instance of type of_list_port_desc_prop_t whose contents
 * match that of more_properties from source
 * @returns NULL if an error occurs
 */
of_list_port_desc_prop_t *
of_port_desc_prop_bsn_ethtool_more_properties_get(of_port_desc_prop_bsn_ethtool_t *obj) {
    of_list_port_desc_prop_t _more_properties;
    of_list_port_desc_prop_t *_more_properties_ptr;

    of_port_desc_prop_bsn_ethtool_more_properties_bind(obj, &_more_properties);
    _more_properties_ptr = (of_list_port_desc_prop_t *)of_object_dup(&_more_properties);
    return _more_properties_ptr;
}

/**
 * Set more_properties in an object of type of_port_desc_prop_bsn_ethtool.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_ethtool.
 * @param more_properties Pointer to the child of type of_list_port_desc_prop_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_port_desc_prop_bsn_ethtool_more_properties_set(
    of_port_desc_prop_bsn_ethtool_t *obj,
    of_list_port_desc_prop_t *more_properties)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_ETHTOOL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 100;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = more_properties->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wbuf == more_properties->wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(more_properties, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(more_properties, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    of_object_wire_length_set((of_object_t *)more_properties, more_properties->length);

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
of_port_desc_prop_bsn_forward_error_correction_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xffff); /* type */
        *(uint32_t *)(buf + 4) = U32_HTON(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 8) = U32_HTON(0x2); /* exp_type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_port_desc_prop_bsn_forward_error_correction of_port_desc_prop_bsn_forward_error_correction
 */

/**
 * Create a new of_port_desc_prop_bsn_forward_error_correction object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_port_desc_prop_bsn_forward_error_correction
 */

of_object_t *
of_port_desc_prop_bsn_forward_error_correction_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_PORT_DESC_PROP_BSN_FORWARD_ERROR_CORRECTION];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_port_desc_prop_bsn_forward_error_correction_init(obj, version, bytes, 0);
    of_port_desc_prop_bsn_forward_error_correction_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_port_desc_prop_bsn_forward_error_correction.
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
of_port_desc_prop_bsn_forward_error_correction_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_PORT_DESC_PROP_BSN_FORWARD_ERROR_CORRECTION] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_PORT_DESC_PROP_BSN_FORWARD_ERROR_CORRECTION];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_PORT_DESC_PROP_BSN_FORWARD_ERROR_CORRECTION;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get experimenter from an object of type of_port_desc_prop_bsn_forward_error_correction.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_forward_error_correction.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_forward_error_correction_experimenter_get(
    of_port_desc_prop_bsn_forward_error_correction_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_FORWARD_ERROR_CORRECTION);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
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
 * Set experimenter in an object of type of_port_desc_prop_bsn_forward_error_correction.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_forward_error_correction.
 * @param experimenter The value to write into the object
 */
void
of_port_desc_prop_bsn_forward_error_correction_experimenter_set(
    of_port_desc_prop_bsn_forward_error_correction_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_FORWARD_ERROR_CORRECTION);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
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
 * Get exp_type from an object of type of_port_desc_prop_bsn_forward_error_correction.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_forward_error_correction.
 * @param exp_type Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_forward_error_correction_exp_type_get(
    of_port_desc_prop_bsn_forward_error_correction_t *obj,
    uint32_t *exp_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_FORWARD_ERROR_CORRECTION);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, exp_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set exp_type in an object of type of_port_desc_prop_bsn_forward_error_correction.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_forward_error_correction.
 * @param exp_type The value to write into the object
 */
void
of_port_desc_prop_bsn_forward_error_correction_exp_type_set(
    of_port_desc_prop_bsn_forward_error_correction_t *obj,
    uint32_t exp_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_FORWARD_ERROR_CORRECTION);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, exp_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get configured from an object of type of_port_desc_prop_bsn_forward_error_correction.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_forward_error_correction.
 * @param configured Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_forward_error_correction_configured_get(
    of_port_desc_prop_bsn_forward_error_correction_t *obj,
    uint32_t *configured)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_FORWARD_ERROR_CORRECTION);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, configured);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set configured in an object of type of_port_desc_prop_bsn_forward_error_correction.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_forward_error_correction.
 * @param configured The value to write into the object
 */
void
of_port_desc_prop_bsn_forward_error_correction_configured_set(
    of_port_desc_prop_bsn_forward_error_correction_t *obj,
    uint32_t configured)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_FORWARD_ERROR_CORRECTION);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, configured);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get enabled from an object of type of_port_desc_prop_bsn_forward_error_correction.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_forward_error_correction.
 * @param enabled Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_forward_error_correction_enabled_get(
    of_port_desc_prop_bsn_forward_error_correction_t *obj,
    uint32_t *enabled)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_FORWARD_ERROR_CORRECTION);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, enabled);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set enabled in an object of type of_port_desc_prop_bsn_forward_error_correction.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_forward_error_correction.
 * @param enabled The value to write into the object
 */
void
of_port_desc_prop_bsn_forward_error_correction_enabled_set(
    of_port_desc_prop_bsn_forward_error_correction_t *obj,
    uint32_t enabled)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_FORWARD_ERROR_CORRECTION);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, enabled);

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
of_port_desc_prop_bsn_generation_id_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xffff); /* type */
        *(uint32_t *)(buf + 4) = U32_HTON(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 8) = U32_HTON(0x1); /* exp_type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_port_desc_prop_bsn_generation_id of_port_desc_prop_bsn_generation_id
 */

/**
 * Create a new of_port_desc_prop_bsn_generation_id object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_port_desc_prop_bsn_generation_id
 */

of_object_t *
of_port_desc_prop_bsn_generation_id_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_PORT_DESC_PROP_BSN_GENERATION_ID];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_port_desc_prop_bsn_generation_id_init(obj, version, bytes, 0);
    of_port_desc_prop_bsn_generation_id_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_port_desc_prop_bsn_generation_id.
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
of_port_desc_prop_bsn_generation_id_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_PORT_DESC_PROP_BSN_GENERATION_ID] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_PORT_DESC_PROP_BSN_GENERATION_ID];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_PORT_DESC_PROP_BSN_GENERATION_ID;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get experimenter from an object of type of_port_desc_prop_bsn_generation_id.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_generation_id.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_generation_id_experimenter_get(
    of_port_desc_prop_bsn_generation_id_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_GENERATION_ID);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
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
 * Set experimenter in an object of type of_port_desc_prop_bsn_generation_id.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_generation_id.
 * @param experimenter The value to write into the object
 */
void
of_port_desc_prop_bsn_generation_id_experimenter_set(
    of_port_desc_prop_bsn_generation_id_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_GENERATION_ID);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
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
 * Get exp_type from an object of type of_port_desc_prop_bsn_generation_id.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_generation_id.
 * @param exp_type Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_generation_id_exp_type_get(
    of_port_desc_prop_bsn_generation_id_t *obj,
    uint32_t *exp_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_GENERATION_ID);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, exp_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set exp_type in an object of type of_port_desc_prop_bsn_generation_id.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_generation_id.
 * @param exp_type The value to write into the object
 */
void
of_port_desc_prop_bsn_generation_id_exp_type_set(
    of_port_desc_prop_bsn_generation_id_t *obj,
    uint32_t exp_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_GENERATION_ID);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, exp_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get generation_id from an object of type of_port_desc_prop_bsn_generation_id.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_generation_id.
 * @param generation_id Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_generation_id_generation_id_get(
    of_port_desc_prop_bsn_generation_id_t *obj,
    uint64_t *generation_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_GENERATION_ID);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, generation_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set generation_id in an object of type of_port_desc_prop_bsn_generation_id.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_generation_id.
 * @param generation_id The value to write into the object
 */
void
of_port_desc_prop_bsn_generation_id_generation_id_set(
    of_port_desc_prop_bsn_generation_id_t *obj,
    uint64_t generation_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_GENERATION_ID);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, generation_id);

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
of_port_desc_prop_bsn_misc_capabilities_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xffff); /* type */
        *(uint32_t *)(buf + 4) = U32_HTON(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 8) = U32_HTON(0x5); /* exp_type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_port_desc_prop_bsn_misc_capabilities of_port_desc_prop_bsn_misc_capabilities
 */

/**
 * Create a new of_port_desc_prop_bsn_misc_capabilities object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_port_desc_prop_bsn_misc_capabilities
 */

of_object_t *
of_port_desc_prop_bsn_misc_capabilities_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_PORT_DESC_PROP_BSN_MISC_CAPABILITIES];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_port_desc_prop_bsn_misc_capabilities_init(obj, version, bytes, 0);
    of_port_desc_prop_bsn_misc_capabilities_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_port_desc_prop_bsn_misc_capabilities.
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
of_port_desc_prop_bsn_misc_capabilities_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_PORT_DESC_PROP_BSN_MISC_CAPABILITIES] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_PORT_DESC_PROP_BSN_MISC_CAPABILITIES];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_PORT_DESC_PROP_BSN_MISC_CAPABILITIES;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get experimenter from an object of type of_port_desc_prop_bsn_misc_capabilities.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_misc_capabilities.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_misc_capabilities_experimenter_get(
    of_port_desc_prop_bsn_misc_capabilities_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_MISC_CAPABILITIES);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
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
 * Set experimenter in an object of type of_port_desc_prop_bsn_misc_capabilities.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_misc_capabilities.
 * @param experimenter The value to write into the object
 */
void
of_port_desc_prop_bsn_misc_capabilities_experimenter_set(
    of_port_desc_prop_bsn_misc_capabilities_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_MISC_CAPABILITIES);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
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
 * Get exp_type from an object of type of_port_desc_prop_bsn_misc_capabilities.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_misc_capabilities.
 * @param exp_type Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_misc_capabilities_exp_type_get(
    of_port_desc_prop_bsn_misc_capabilities_t *obj,
    uint32_t *exp_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_MISC_CAPABILITIES);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, exp_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set exp_type in an object of type of_port_desc_prop_bsn_misc_capabilities.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_misc_capabilities.
 * @param exp_type The value to write into the object
 */
void
of_port_desc_prop_bsn_misc_capabilities_exp_type_set(
    of_port_desc_prop_bsn_misc_capabilities_t *obj,
    uint32_t exp_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_MISC_CAPABILITIES);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, exp_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get current from an object of type of_port_desc_prop_bsn_misc_capabilities.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_misc_capabilities.
 * @param current Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_misc_capabilities_current_get(
    of_port_desc_prop_bsn_misc_capabilities_t *obj,
    uint64_t *current)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_MISC_CAPABILITIES);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, current);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set current in an object of type of_port_desc_prop_bsn_misc_capabilities.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_misc_capabilities.
 * @param current The value to write into the object
 */
void
of_port_desc_prop_bsn_misc_capabilities_current_set(
    of_port_desc_prop_bsn_misc_capabilities_t *obj,
    uint64_t current)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_MISC_CAPABILITIES);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, current);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get available from an object of type of_port_desc_prop_bsn_misc_capabilities.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_misc_capabilities.
 * @param available Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_misc_capabilities_available_get(
    of_port_desc_prop_bsn_misc_capabilities_t *obj,
    uint64_t *available)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_MISC_CAPABILITIES);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, available);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set available in an object of type of_port_desc_prop_bsn_misc_capabilities.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_misc_capabilities.
 * @param available The value to write into the object
 */
void
of_port_desc_prop_bsn_misc_capabilities_available_set(
    of_port_desc_prop_bsn_misc_capabilities_t *obj,
    uint64_t available)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_MISC_CAPABILITIES);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, available);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get supported from an object of type of_port_desc_prop_bsn_misc_capabilities.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_misc_capabilities.
 * @param supported Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_misc_capabilities_supported_get(
    of_port_desc_prop_bsn_misc_capabilities_t *obj,
    uint64_t *supported)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_MISC_CAPABILITIES);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 28;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, supported);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set supported in an object of type of_port_desc_prop_bsn_misc_capabilities.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_misc_capabilities.
 * @param supported The value to write into the object
 */
void
of_port_desc_prop_bsn_misc_capabilities_supported_set(
    of_port_desc_prop_bsn_misc_capabilities_t *obj,
    uint64_t supported)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_MISC_CAPABILITIES);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 28;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, supported);

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
of_port_desc_prop_bsn_speed_capabilities_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xffff); /* type */
        *(uint32_t *)(buf + 4) = U32_HTON(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 8) = U32_HTON(0x4); /* exp_type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_port_desc_prop_bsn_speed_capabilities of_port_desc_prop_bsn_speed_capabilities
 */

/**
 * Create a new of_port_desc_prop_bsn_speed_capabilities object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_port_desc_prop_bsn_speed_capabilities
 */

of_object_t *
of_port_desc_prop_bsn_speed_capabilities_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_PORT_DESC_PROP_BSN_SPEED_CAPABILITIES];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_port_desc_prop_bsn_speed_capabilities_init(obj, version, bytes, 0);
    of_port_desc_prop_bsn_speed_capabilities_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_port_desc_prop_bsn_speed_capabilities.
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
of_port_desc_prop_bsn_speed_capabilities_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_PORT_DESC_PROP_BSN_SPEED_CAPABILITIES] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_PORT_DESC_PROP_BSN_SPEED_CAPABILITIES];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_PORT_DESC_PROP_BSN_SPEED_CAPABILITIES;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get experimenter from an object of type of_port_desc_prop_bsn_speed_capabilities.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_speed_capabilities.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_speed_capabilities_experimenter_get(
    of_port_desc_prop_bsn_speed_capabilities_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_SPEED_CAPABILITIES);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
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
 * Set experimenter in an object of type of_port_desc_prop_bsn_speed_capabilities.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_speed_capabilities.
 * @param experimenter The value to write into the object
 */
void
of_port_desc_prop_bsn_speed_capabilities_experimenter_set(
    of_port_desc_prop_bsn_speed_capabilities_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_SPEED_CAPABILITIES);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
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
 * Get exp_type from an object of type of_port_desc_prop_bsn_speed_capabilities.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_speed_capabilities.
 * @param exp_type Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_speed_capabilities_exp_type_get(
    of_port_desc_prop_bsn_speed_capabilities_t *obj,
    uint32_t *exp_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_SPEED_CAPABILITIES);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, exp_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set exp_type in an object of type of_port_desc_prop_bsn_speed_capabilities.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_speed_capabilities.
 * @param exp_type The value to write into the object
 */
void
of_port_desc_prop_bsn_speed_capabilities_exp_type_set(
    of_port_desc_prop_bsn_speed_capabilities_t *obj,
    uint32_t exp_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_SPEED_CAPABILITIES);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, exp_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get current from an object of type of_port_desc_prop_bsn_speed_capabilities.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_speed_capabilities.
 * @param current Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_speed_capabilities_current_get(
    of_port_desc_prop_bsn_speed_capabilities_t *obj,
    uint64_t *current)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_SPEED_CAPABILITIES);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, current);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set current in an object of type of_port_desc_prop_bsn_speed_capabilities.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_speed_capabilities.
 * @param current The value to write into the object
 */
void
of_port_desc_prop_bsn_speed_capabilities_current_set(
    of_port_desc_prop_bsn_speed_capabilities_t *obj,
    uint64_t current)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_SPEED_CAPABILITIES);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, current);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get available from an object of type of_port_desc_prop_bsn_speed_capabilities.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_speed_capabilities.
 * @param available Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_speed_capabilities_available_get(
    of_port_desc_prop_bsn_speed_capabilities_t *obj,
    uint64_t *available)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_SPEED_CAPABILITIES);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, available);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set available in an object of type of_port_desc_prop_bsn_speed_capabilities.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_speed_capabilities.
 * @param available The value to write into the object
 */
void
of_port_desc_prop_bsn_speed_capabilities_available_set(
    of_port_desc_prop_bsn_speed_capabilities_t *obj,
    uint64_t available)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_SPEED_CAPABILITIES);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, available);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get supported from an object of type of_port_desc_prop_bsn_speed_capabilities.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_speed_capabilities.
 * @param supported Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_speed_capabilities_supported_get(
    of_port_desc_prop_bsn_speed_capabilities_t *obj,
    uint64_t *supported)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_SPEED_CAPABILITIES);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 28;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, supported);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set supported in an object of type of_port_desc_prop_bsn_speed_capabilities.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_speed_capabilities.
 * @param supported The value to write into the object
 */
void
of_port_desc_prop_bsn_speed_capabilities_supported_set(
    of_port_desc_prop_bsn_speed_capabilities_t *obj,
    uint64_t supported)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_SPEED_CAPABILITIES);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 28;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, supported);

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
of_port_desc_prop_bsn_uplink_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xffff); /* type */
        *(uint32_t *)(buf + 4) = U32_HTON(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 8) = U32_HTON(0x0); /* exp_type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_port_desc_prop_bsn_uplink of_port_desc_prop_bsn_uplink
 */

/**
 * Create a new of_port_desc_prop_bsn_uplink object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_port_desc_prop_bsn_uplink
 */

of_object_t *
of_port_desc_prop_bsn_uplink_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_PORT_DESC_PROP_BSN_UPLINK];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_port_desc_prop_bsn_uplink_init(obj, version, bytes, 0);
    of_port_desc_prop_bsn_uplink_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_port_desc_prop_bsn_uplink.
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
of_port_desc_prop_bsn_uplink_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_PORT_DESC_PROP_BSN_UPLINK] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_PORT_DESC_PROP_BSN_UPLINK];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_PORT_DESC_PROP_BSN_UPLINK;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get experimenter from an object of type of_port_desc_prop_bsn_uplink.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_uplink.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_uplink_experimenter_get(
    of_port_desc_prop_bsn_uplink_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_UPLINK);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
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
 * Set experimenter in an object of type of_port_desc_prop_bsn_uplink.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_uplink.
 * @param experimenter The value to write into the object
 */
void
of_port_desc_prop_bsn_uplink_experimenter_set(
    of_port_desc_prop_bsn_uplink_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_UPLINK);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
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
 * Get exp_type from an object of type of_port_desc_prop_bsn_uplink.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_uplink.
 * @param exp_type Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_bsn_uplink_exp_type_get(
    of_port_desc_prop_bsn_uplink_t *obj,
    uint32_t *exp_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_UPLINK);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, exp_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set exp_type in an object of type of_port_desc_prop_bsn_uplink.
 * @param obj Pointer to an object of type of_port_desc_prop_bsn_uplink.
 * @param exp_type The value to write into the object
 */
void
of_port_desc_prop_bsn_uplink_exp_type_set(
    of_port_desc_prop_bsn_uplink_t *obj,
    uint32_t exp_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_BSN_UPLINK);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, exp_type);

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
of_port_desc_prop_ethernet_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0x0); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_port_desc_prop_ethernet of_port_desc_prop_ethernet
 */

/**
 * Create a new of_port_desc_prop_ethernet object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_port_desc_prop_ethernet
 */

of_object_t *
of_port_desc_prop_ethernet_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_PORT_DESC_PROP_ETHERNET];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_port_desc_prop_ethernet_init(obj, version, bytes, 0);
    of_port_desc_prop_ethernet_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_port_desc_prop_ethernet.
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
of_port_desc_prop_ethernet_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_PORT_DESC_PROP_ETHERNET] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_PORT_DESC_PROP_ETHERNET];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_PORT_DESC_PROP_ETHERNET;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get curr from an object of type of_port_desc_prop_ethernet.
 * @param obj Pointer to an object of type of_port_desc_prop_ethernet.
 * @param curr Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_ethernet_curr_get(
    of_port_desc_prop_ethernet_t *obj,
    uint32_t *curr)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_ETHERNET);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, curr);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set curr in an object of type of_port_desc_prop_ethernet.
 * @param obj Pointer to an object of type of_port_desc_prop_ethernet.
 * @param curr The value to write into the object
 */
void
of_port_desc_prop_ethernet_curr_set(
    of_port_desc_prop_ethernet_t *obj,
    uint32_t curr)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_ETHERNET);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, curr);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get advertised from an object of type of_port_desc_prop_ethernet.
 * @param obj Pointer to an object of type of_port_desc_prop_ethernet.
 * @param advertised Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_ethernet_advertised_get(
    of_port_desc_prop_ethernet_t *obj,
    uint32_t *advertised)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_ETHERNET);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, advertised);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set advertised in an object of type of_port_desc_prop_ethernet.
 * @param obj Pointer to an object of type of_port_desc_prop_ethernet.
 * @param advertised The value to write into the object
 */
void
of_port_desc_prop_ethernet_advertised_set(
    of_port_desc_prop_ethernet_t *obj,
    uint32_t advertised)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_ETHERNET);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, advertised);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get supported from an object of type of_port_desc_prop_ethernet.
 * @param obj Pointer to an object of type of_port_desc_prop_ethernet.
 * @param supported Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_ethernet_supported_get(
    of_port_desc_prop_ethernet_t *obj,
    uint32_t *supported)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_ETHERNET);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, supported);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set supported in an object of type of_port_desc_prop_ethernet.
 * @param obj Pointer to an object of type of_port_desc_prop_ethernet.
 * @param supported The value to write into the object
 */
void
of_port_desc_prop_ethernet_supported_set(
    of_port_desc_prop_ethernet_t *obj,
    uint32_t supported)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_ETHERNET);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, supported);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get peer from an object of type of_port_desc_prop_ethernet.
 * @param obj Pointer to an object of type of_port_desc_prop_ethernet.
 * @param peer Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_ethernet_peer_get(
    of_port_desc_prop_ethernet_t *obj,
    uint32_t *peer)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_ETHERNET);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, peer);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set peer in an object of type of_port_desc_prop_ethernet.
 * @param obj Pointer to an object of type of_port_desc_prop_ethernet.
 * @param peer The value to write into the object
 */
void
of_port_desc_prop_ethernet_peer_set(
    of_port_desc_prop_ethernet_t *obj,
    uint32_t peer)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_ETHERNET);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, peer);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get curr_speed from an object of type of_port_desc_prop_ethernet.
 * @param obj Pointer to an object of type of_port_desc_prop_ethernet.
 * @param curr_speed Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_ethernet_curr_speed_get(
    of_port_desc_prop_ethernet_t *obj,
    uint32_t *curr_speed)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_ETHERNET);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, curr_speed);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set curr_speed in an object of type of_port_desc_prop_ethernet.
 * @param obj Pointer to an object of type of_port_desc_prop_ethernet.
 * @param curr_speed The value to write into the object
 */
void
of_port_desc_prop_ethernet_curr_speed_set(
    of_port_desc_prop_ethernet_t *obj,
    uint32_t curr_speed)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_ETHERNET);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, curr_speed);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get max_speed from an object of type of_port_desc_prop_ethernet.
 * @param obj Pointer to an object of type of_port_desc_prop_ethernet.
 * @param max_speed Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_ethernet_max_speed_get(
    of_port_desc_prop_ethernet_t *obj,
    uint32_t *max_speed)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_ETHERNET);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 28;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, max_speed);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set max_speed in an object of type of_port_desc_prop_ethernet.
 * @param obj Pointer to an object of type of_port_desc_prop_ethernet.
 * @param max_speed The value to write into the object
 */
void
of_port_desc_prop_ethernet_max_speed_set(
    of_port_desc_prop_ethernet_t *obj,
    uint32_t max_speed)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_ETHERNET);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 28;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, max_speed);

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
of_port_desc_prop_optical_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0x1); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_port_desc_prop_optical of_port_desc_prop_optical
 */

/**
 * Create a new of_port_desc_prop_optical object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_port_desc_prop_optical
 */

of_object_t *
of_port_desc_prop_optical_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_PORT_DESC_PROP_OPTICAL];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_port_desc_prop_optical_init(obj, version, bytes, 0);
    of_port_desc_prop_optical_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_port_desc_prop_optical.
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
of_port_desc_prop_optical_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_PORT_DESC_PROP_OPTICAL] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_PORT_DESC_PROP_OPTICAL];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_PORT_DESC_PROP_OPTICAL;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get supported from an object of type of_port_desc_prop_optical.
 * @param obj Pointer to an object of type of_port_desc_prop_optical.
 * @param supported Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_optical_supported_get(
    of_port_desc_prop_optical_t *obj,
    uint32_t *supported)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_OPTICAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, supported);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set supported in an object of type of_port_desc_prop_optical.
 * @param obj Pointer to an object of type of_port_desc_prop_optical.
 * @param supported The value to write into the object
 */
void
of_port_desc_prop_optical_supported_set(
    of_port_desc_prop_optical_t *obj,
    uint32_t supported)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_OPTICAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, supported);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get tx_min_freq_lmda from an object of type of_port_desc_prop_optical.
 * @param obj Pointer to an object of type of_port_desc_prop_optical.
 * @param tx_min_freq_lmda Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_optical_tx_min_freq_lmda_get(
    of_port_desc_prop_optical_t *obj,
    uint32_t *tx_min_freq_lmda)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_OPTICAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, tx_min_freq_lmda);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set tx_min_freq_lmda in an object of type of_port_desc_prop_optical.
 * @param obj Pointer to an object of type of_port_desc_prop_optical.
 * @param tx_min_freq_lmda The value to write into the object
 */
void
of_port_desc_prop_optical_tx_min_freq_lmda_set(
    of_port_desc_prop_optical_t *obj,
    uint32_t tx_min_freq_lmda)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_OPTICAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, tx_min_freq_lmda);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get tx_max_freq_lmda from an object of type of_port_desc_prop_optical.
 * @param obj Pointer to an object of type of_port_desc_prop_optical.
 * @param tx_max_freq_lmda Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_optical_tx_max_freq_lmda_get(
    of_port_desc_prop_optical_t *obj,
    uint32_t *tx_max_freq_lmda)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_OPTICAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, tx_max_freq_lmda);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set tx_max_freq_lmda in an object of type of_port_desc_prop_optical.
 * @param obj Pointer to an object of type of_port_desc_prop_optical.
 * @param tx_max_freq_lmda The value to write into the object
 */
void
of_port_desc_prop_optical_tx_max_freq_lmda_set(
    of_port_desc_prop_optical_t *obj,
    uint32_t tx_max_freq_lmda)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_OPTICAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, tx_max_freq_lmda);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get tx_grid_freq_lmda from an object of type of_port_desc_prop_optical.
 * @param obj Pointer to an object of type of_port_desc_prop_optical.
 * @param tx_grid_freq_lmda Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_optical_tx_grid_freq_lmda_get(
    of_port_desc_prop_optical_t *obj,
    uint32_t *tx_grid_freq_lmda)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_OPTICAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, tx_grid_freq_lmda);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set tx_grid_freq_lmda in an object of type of_port_desc_prop_optical.
 * @param obj Pointer to an object of type of_port_desc_prop_optical.
 * @param tx_grid_freq_lmda The value to write into the object
 */
void
of_port_desc_prop_optical_tx_grid_freq_lmda_set(
    of_port_desc_prop_optical_t *obj,
    uint32_t tx_grid_freq_lmda)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_OPTICAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, tx_grid_freq_lmda);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get rx_min_freq_lmda from an object of type of_port_desc_prop_optical.
 * @param obj Pointer to an object of type of_port_desc_prop_optical.
 * @param rx_min_freq_lmda Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_optical_rx_min_freq_lmda_get(
    of_port_desc_prop_optical_t *obj,
    uint32_t *rx_min_freq_lmda)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_OPTICAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, rx_min_freq_lmda);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set rx_min_freq_lmda in an object of type of_port_desc_prop_optical.
 * @param obj Pointer to an object of type of_port_desc_prop_optical.
 * @param rx_min_freq_lmda The value to write into the object
 */
void
of_port_desc_prop_optical_rx_min_freq_lmda_set(
    of_port_desc_prop_optical_t *obj,
    uint32_t rx_min_freq_lmda)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_OPTICAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, rx_min_freq_lmda);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get rx_max_freq_lmda from an object of type of_port_desc_prop_optical.
 * @param obj Pointer to an object of type of_port_desc_prop_optical.
 * @param rx_max_freq_lmda Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_optical_rx_max_freq_lmda_get(
    of_port_desc_prop_optical_t *obj,
    uint32_t *rx_max_freq_lmda)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_OPTICAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 28;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, rx_max_freq_lmda);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set rx_max_freq_lmda in an object of type of_port_desc_prop_optical.
 * @param obj Pointer to an object of type of_port_desc_prop_optical.
 * @param rx_max_freq_lmda The value to write into the object
 */
void
of_port_desc_prop_optical_rx_max_freq_lmda_set(
    of_port_desc_prop_optical_t *obj,
    uint32_t rx_max_freq_lmda)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_OPTICAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 28;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, rx_max_freq_lmda);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get rx_grid_freq_lmda from an object of type of_port_desc_prop_optical.
 * @param obj Pointer to an object of type of_port_desc_prop_optical.
 * @param rx_grid_freq_lmda Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_optical_rx_grid_freq_lmda_get(
    of_port_desc_prop_optical_t *obj,
    uint32_t *rx_grid_freq_lmda)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_OPTICAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 32;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, rx_grid_freq_lmda);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set rx_grid_freq_lmda in an object of type of_port_desc_prop_optical.
 * @param obj Pointer to an object of type of_port_desc_prop_optical.
 * @param rx_grid_freq_lmda The value to write into the object
 */
void
of_port_desc_prop_optical_rx_grid_freq_lmda_set(
    of_port_desc_prop_optical_t *obj,
    uint32_t rx_grid_freq_lmda)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_OPTICAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 32;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, rx_grid_freq_lmda);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get tx_pwr_min from an object of type of_port_desc_prop_optical.
 * @param obj Pointer to an object of type of_port_desc_prop_optical.
 * @param tx_pwr_min Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_optical_tx_pwr_min_get(
    of_port_desc_prop_optical_t *obj,
    uint32_t *tx_pwr_min)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_OPTICAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 36;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, tx_pwr_min);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set tx_pwr_min in an object of type of_port_desc_prop_optical.
 * @param obj Pointer to an object of type of_port_desc_prop_optical.
 * @param tx_pwr_min The value to write into the object
 */
void
of_port_desc_prop_optical_tx_pwr_min_set(
    of_port_desc_prop_optical_t *obj,
    uint32_t tx_pwr_min)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_OPTICAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 36;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, tx_pwr_min);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get tx_pwr_max from an object of type of_port_desc_prop_optical.
 * @param obj Pointer to an object of type of_port_desc_prop_optical.
 * @param tx_pwr_max Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_prop_optical_tx_pwr_max_get(
    of_port_desc_prop_optical_t *obj,
    uint32_t *tx_pwr_max)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_OPTICAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 40;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, tx_pwr_max);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set tx_pwr_max in an object of type of_port_desc_prop_optical.
 * @param obj Pointer to an object of type of_port_desc_prop_optical.
 * @param tx_pwr_max The value to write into the object
 */
void
of_port_desc_prop_optical_tx_pwr_max_set(
    of_port_desc_prop_optical_t *obj,
    uint32_t tx_pwr_max)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_OPTICAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 40;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, tx_pwr_max);

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
of_port_mod_prop_wire_object_id_get(of_object_t *obj, of_object_id_t *id)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_4: {
        uint16_t value = U16_NTOH(*(uint16_t *)(buf + 0)); /* type */
        switch (value) {
        case 0x0:
            *id = OF_PORT_MOD_PROP_ETHERNET;
            break;
        case 0x1:
            *id = OF_PORT_MOD_PROP_OPTICAL;
            break;
        case 0xffff:
            of_port_mod_prop_experimenter_wire_object_id_get(obj, id);
            break;
        default:
            *id = OF_PORT_MOD_PROP;
            break;
        }
        break;
    }
    default:
        LOCI_ASSERT(0);
    }
}


/**
 * \defgroup of_port_mod_prop of_port_mod_prop
 */

/**
 * Create a new of_port_mod_prop object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_port_mod_prop
 */

of_object_t *
of_port_mod_prop_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_PORT_MOD_PROP];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_port_mod_prop_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_port_mod_prop.
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
of_port_mod_prop_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_PORT_MOD_PROP] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_PORT_MOD_PROP];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_PORT_MOD_PROP;

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
of_port_mod_prop_ethernet_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0x0); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_port_mod_prop_ethernet of_port_mod_prop_ethernet
 */

/**
 * Create a new of_port_mod_prop_ethernet object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_port_mod_prop_ethernet
 */

of_object_t *
of_port_mod_prop_ethernet_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_PORT_MOD_PROP_ETHERNET];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_port_mod_prop_ethernet_init(obj, version, bytes, 0);
    of_port_mod_prop_ethernet_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_port_mod_prop_ethernet.
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
of_port_mod_prop_ethernet_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_PORT_MOD_PROP_ETHERNET] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_PORT_MOD_PROP_ETHERNET];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_PORT_MOD_PROP_ETHERNET;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get advertise from an object of type of_port_mod_prop_ethernet.
 * @param obj Pointer to an object of type of_port_mod_prop_ethernet.
 * @param advertise Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_mod_prop_ethernet_advertise_get(
    of_port_mod_prop_ethernet_t *obj,
    uint32_t *advertise)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_MOD_PROP_ETHERNET);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, advertise);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set advertise in an object of type of_port_mod_prop_ethernet.
 * @param obj Pointer to an object of type of_port_mod_prop_ethernet.
 * @param advertise The value to write into the object
 */
void
of_port_mod_prop_ethernet_advertise_set(
    of_port_mod_prop_ethernet_t *obj,
    uint32_t advertise)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_MOD_PROP_ETHERNET);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, advertise);

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
of_port_mod_prop_experimenter_wire_object_id_get(of_object_t *obj, of_object_id_t *id)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_4: {
        uint32_t value = U32_NTOH(*(uint32_t *)(buf + 4)); /* experimenter */
        switch (value) {
        default:
            *id = OF_PORT_MOD_PROP_EXPERIMENTER;
            break;
        }
        break;
    }
    default:
        LOCI_ASSERT(0);
    }
}


/**
 * \defgroup of_port_mod_prop_experimenter of_port_mod_prop_experimenter
 */

/**
 * Create a new of_port_mod_prop_experimenter object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_port_mod_prop_experimenter
 */

of_object_t *
of_port_mod_prop_experimenter_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_PORT_MOD_PROP_EXPERIMENTER];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_port_mod_prop_experimenter_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_port_mod_prop_experimenter.
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
of_port_mod_prop_experimenter_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_PORT_MOD_PROP_EXPERIMENTER] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_PORT_MOD_PROP_EXPERIMENTER];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_PORT_MOD_PROP_EXPERIMENTER;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get experimenter from an object of type of_port_mod_prop_experimenter.
 * @param obj Pointer to an object of type of_port_mod_prop_experimenter.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_mod_prop_experimenter_experimenter_get(
    of_port_mod_prop_experimenter_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_MOD_PROP_EXPERIMENTER);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
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
 * Set experimenter in an object of type of_port_mod_prop_experimenter.
 * @param obj Pointer to an object of type of_port_mod_prop_experimenter.
 * @param experimenter The value to write into the object
 */
void
of_port_mod_prop_experimenter_experimenter_set(
    of_port_mod_prop_experimenter_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_MOD_PROP_EXPERIMENTER);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
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
 * Get exp_type from an object of type of_port_mod_prop_experimenter.
 * @param obj Pointer to an object of type of_port_mod_prop_experimenter.
 * @param exp_type Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_mod_prop_experimenter_exp_type_get(
    of_port_mod_prop_experimenter_t *obj,
    uint32_t *exp_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_MOD_PROP_EXPERIMENTER);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, exp_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set exp_type in an object of type of_port_mod_prop_experimenter.
 * @param obj Pointer to an object of type of_port_mod_prop_experimenter.
 * @param exp_type The value to write into the object
 */
void
of_port_mod_prop_experimenter_exp_type_set(
    of_port_mod_prop_experimenter_t *obj,
    uint32_t exp_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_MOD_PROP_EXPERIMENTER);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, exp_type);

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
of_port_mod_prop_optical_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0x1); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_port_mod_prop_optical of_port_mod_prop_optical
 */

/**
 * Create a new of_port_mod_prop_optical object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_port_mod_prop_optical
 */

of_object_t *
of_port_mod_prop_optical_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_PORT_MOD_PROP_OPTICAL];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_port_mod_prop_optical_init(obj, version, bytes, 0);
    of_port_mod_prop_optical_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_port_mod_prop_optical.
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
of_port_mod_prop_optical_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_PORT_MOD_PROP_OPTICAL] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_PORT_MOD_PROP_OPTICAL];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_PORT_MOD_PROP_OPTICAL;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get configure from an object of type of_port_mod_prop_optical.
 * @param obj Pointer to an object of type of_port_mod_prop_optical.
 * @param configure Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_mod_prop_optical_configure_get(
    of_port_mod_prop_optical_t *obj,
    uint32_t *configure)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_MOD_PROP_OPTICAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, configure);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set configure in an object of type of_port_mod_prop_optical.
 * @param obj Pointer to an object of type of_port_mod_prop_optical.
 * @param configure The value to write into the object
 */
void
of_port_mod_prop_optical_configure_set(
    of_port_mod_prop_optical_t *obj,
    uint32_t configure)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_MOD_PROP_OPTICAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, configure);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get freq_ldma from an object of type of_port_mod_prop_optical.
 * @param obj Pointer to an object of type of_port_mod_prop_optical.
 * @param freq_ldma Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_mod_prop_optical_freq_ldma_get(
    of_port_mod_prop_optical_t *obj,
    uint32_t *freq_ldma)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_MOD_PROP_OPTICAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, freq_ldma);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set freq_ldma in an object of type of_port_mod_prop_optical.
 * @param obj Pointer to an object of type of_port_mod_prop_optical.
 * @param freq_ldma The value to write into the object
 */
void
of_port_mod_prop_optical_freq_ldma_set(
    of_port_mod_prop_optical_t *obj,
    uint32_t freq_ldma)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_MOD_PROP_OPTICAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, freq_ldma);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get fl_offset from an object of type of_port_mod_prop_optical.
 * @param obj Pointer to an object of type of_port_mod_prop_optical.
 * @param fl_offset Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_mod_prop_optical_fl_offset_get(
    of_port_mod_prop_optical_t *obj,
    uint32_t *fl_offset)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_MOD_PROP_OPTICAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, fl_offset);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set fl_offset in an object of type of_port_mod_prop_optical.
 * @param obj Pointer to an object of type of_port_mod_prop_optical.
 * @param fl_offset The value to write into the object
 */
void
of_port_mod_prop_optical_fl_offset_set(
    of_port_mod_prop_optical_t *obj,
    uint32_t fl_offset)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_MOD_PROP_OPTICAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, fl_offset);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get grid_span from an object of type of_port_mod_prop_optical.
 * @param obj Pointer to an object of type of_port_mod_prop_optical.
 * @param grid_span Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_mod_prop_optical_grid_span_get(
    of_port_mod_prop_optical_t *obj,
    uint32_t *grid_span)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_MOD_PROP_OPTICAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, grid_span);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set grid_span in an object of type of_port_mod_prop_optical.
 * @param obj Pointer to an object of type of_port_mod_prop_optical.
 * @param grid_span The value to write into the object
 */
void
of_port_mod_prop_optical_grid_span_set(
    of_port_mod_prop_optical_t *obj,
    uint32_t grid_span)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_MOD_PROP_OPTICAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, grid_span);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get tx_pwr from an object of type of_port_mod_prop_optical.
 * @param obj Pointer to an object of type of_port_mod_prop_optical.
 * @param tx_pwr Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_mod_prop_optical_tx_pwr_get(
    of_port_mod_prop_optical_t *obj,
    uint32_t *tx_pwr)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_MOD_PROP_OPTICAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, tx_pwr);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set tx_pwr in an object of type of_port_mod_prop_optical.
 * @param obj Pointer to an object of type of_port_mod_prop_optical.
 * @param tx_pwr The value to write into the object
 */
void
of_port_mod_prop_optical_tx_pwr_set(
    of_port_mod_prop_optical_t *obj,
    uint32_t tx_pwr)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_MOD_PROP_OPTICAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, tx_pwr);

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
of_port_stats_prop_wire_object_id_get(of_object_t *obj, of_object_id_t *id)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_4: {
        uint16_t value = U16_NTOH(*(uint16_t *)(buf + 0)); /* type */
        switch (value) {
        case 0x0:
            *id = OF_PORT_STATS_PROP_ETHERNET;
            break;
        case 0x1:
            *id = OF_PORT_STATS_PROP_OPTICAL;
            break;
        case 0xffff:
            of_port_stats_prop_experimenter_wire_object_id_get(obj, id);
            break;
        default:
            *id = OF_PORT_STATS_PROP;
            break;
        }
        break;
    }
    default:
        LOCI_ASSERT(0);
    }
}


/**
 * \defgroup of_port_stats_prop of_port_stats_prop
 */

/**
 * Create a new of_port_stats_prop object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_port_stats_prop
 */

of_object_t *
of_port_stats_prop_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_PORT_STATS_PROP];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_port_stats_prop_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_port_stats_prop.
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
of_port_stats_prop_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_PORT_STATS_PROP] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_PORT_STATS_PROP];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_PORT_STATS_PROP;

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
of_port_stats_prop_ethernet_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0x0); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_port_stats_prop_ethernet of_port_stats_prop_ethernet
 */

/**
 * Create a new of_port_stats_prop_ethernet object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_port_stats_prop_ethernet
 */

of_object_t *
of_port_stats_prop_ethernet_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_PORT_STATS_PROP_ETHERNET];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_port_stats_prop_ethernet_init(obj, version, bytes, 0);
    of_port_stats_prop_ethernet_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_port_stats_prop_ethernet.
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
of_port_stats_prop_ethernet_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_PORT_STATS_PROP_ETHERNET] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_PORT_STATS_PROP_ETHERNET];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_PORT_STATS_PROP_ETHERNET;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get rx_frame_err from an object of type of_port_stats_prop_ethernet.
 * @param obj Pointer to an object of type of_port_stats_prop_ethernet.
 * @param rx_frame_err Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_port_stats_prop_ethernet_rx_frame_err_get(
    of_port_stats_prop_ethernet_t *obj,
    uint64_t *rx_frame_err)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_STATS_PROP_ETHERNET);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, rx_frame_err);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set rx_frame_err in an object of type of_port_stats_prop_ethernet.
 * @param obj Pointer to an object of type of_port_stats_prop_ethernet.
 * @param rx_frame_err The value to write into the object
 */
void
of_port_stats_prop_ethernet_rx_frame_err_set(
    of_port_stats_prop_ethernet_t *obj,
    uint64_t rx_frame_err)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_STATS_PROP_ETHERNET);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, rx_frame_err);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get rx_over_err from an object of type of_port_stats_prop_ethernet.
 * @param obj Pointer to an object of type of_port_stats_prop_ethernet.
 * @param rx_over_err Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_port_stats_prop_ethernet_rx_over_err_get(
    of_port_stats_prop_ethernet_t *obj,
    uint64_t *rx_over_err)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_STATS_PROP_ETHERNET);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, rx_over_err);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set rx_over_err in an object of type of_port_stats_prop_ethernet.
 * @param obj Pointer to an object of type of_port_stats_prop_ethernet.
 * @param rx_over_err The value to write into the object
 */
void
of_port_stats_prop_ethernet_rx_over_err_set(
    of_port_stats_prop_ethernet_t *obj,
    uint64_t rx_over_err)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_STATS_PROP_ETHERNET);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, rx_over_err);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get rx_crc_err from an object of type of_port_stats_prop_ethernet.
 * @param obj Pointer to an object of type of_port_stats_prop_ethernet.
 * @param rx_crc_err Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_port_stats_prop_ethernet_rx_crc_err_get(
    of_port_stats_prop_ethernet_t *obj,
    uint64_t *rx_crc_err)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_STATS_PROP_ETHERNET);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, rx_crc_err);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set rx_crc_err in an object of type of_port_stats_prop_ethernet.
 * @param obj Pointer to an object of type of_port_stats_prop_ethernet.
 * @param rx_crc_err The value to write into the object
 */
void
of_port_stats_prop_ethernet_rx_crc_err_set(
    of_port_stats_prop_ethernet_t *obj,
    uint64_t rx_crc_err)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_STATS_PROP_ETHERNET);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, rx_crc_err);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get collisions from an object of type of_port_stats_prop_ethernet.
 * @param obj Pointer to an object of type of_port_stats_prop_ethernet.
 * @param collisions Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_port_stats_prop_ethernet_collisions_get(
    of_port_stats_prop_ethernet_t *obj,
    uint64_t *collisions)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_STATS_PROP_ETHERNET);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 32;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, collisions);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set collisions in an object of type of_port_stats_prop_ethernet.
 * @param obj Pointer to an object of type of_port_stats_prop_ethernet.
 * @param collisions The value to write into the object
 */
void
of_port_stats_prop_ethernet_collisions_set(
    of_port_stats_prop_ethernet_t *obj,
    uint64_t collisions)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_STATS_PROP_ETHERNET);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_4:
        offset = 32;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, collisions);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
