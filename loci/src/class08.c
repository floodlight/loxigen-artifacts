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
of_role_request_failed_error_msg_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x1; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0xb); /* err_type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_role_request_failed_error_msg of_role_request_failed_error_msg
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_role_request_failed_error_msg_push_wire_values(of_role_request_failed_error_msg_t *obj)
{

    of_role_request_failed_error_msg_push_wire_types(obj);

    /* Message obj; set length */
    of_message_t msg;

    if ((msg = OF_OBJECT_TO_MESSAGE(obj)) != NULL) {
        of_message_length_set(msg, obj->length);
    }

    return OF_ERROR_NONE;
}

/**
 * Create a new of_role_request_failed_error_msg object
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
 * \ingroup of_role_request_failed_error_msg
 */

of_role_request_failed_error_msg_t *
of_role_request_failed_error_msg_new(of_version_t version)
{
    of_role_request_failed_error_msg_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ROLE_REQUEST_FAILED_ERROR_MSG] + of_object_extra_len[version][OF_ROLE_REQUEST_FAILED_ERROR_MSG];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_role_request_failed_error_msg_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_role_request_failed_error_msg_init(obj, version, bytes, 0);

    if (of_role_request_failed_error_msg_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_role_request_failed_error_msg.
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
of_role_request_failed_error_msg_init(of_role_request_failed_error_msg_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_ROLE_REQUEST_FAILED_ERROR_MSG] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ROLE_REQUEST_FAILED_ERROR_MSG] + of_object_extra_len[version][OF_ROLE_REQUEST_FAILED_ERROR_MSG];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ROLE_REQUEST_FAILED_ERROR_MSG;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_role_request_failed_error_msg_push_wire_types;

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
 * Create a new of_role_request_failed_error_msg object and bind it to an existing message
 *
 * @param msg The message to bind the new object to
 * @return Pointer to the newly create object or NULL on error
 *
 * \ingroup of_role_request_failed_error_msg
 */

of_role_request_failed_error_msg_t *
of_role_request_failed_error_msg_new_from_message(of_message_t msg)
{
    of_role_request_failed_error_msg_t *obj = NULL;
    of_version_t version;
    int length;

    if (msg == NULL) return NULL;

    version = of_message_version_get(msg);
    if (!OF_VERSION_OKAY(version)) return NULL;

    length = of_message_length_get(msg);

    if ((obj = (of_role_request_failed_error_msg_t *)of_object_new(-1)) == NULL) {
        return NULL;
    }

    of_role_request_failed_error_msg_init(obj, version, 0, 0);

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
 * Get xid from an object of type of_role_request_failed_error_msg.
 * @param obj Pointer to an object of type of_role_request_failed_error_msg.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_role_request_failed_error_msg_xid_get(
    of_role_request_failed_error_msg_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ROLE_REQUEST_FAILED_ERROR_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
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
 * Set xid in an object of type of_role_request_failed_error_msg.
 * @param obj Pointer to an object of type of_role_request_failed_error_msg.
 * @param xid The value to write into the object
 */
void
of_role_request_failed_error_msg_xid_set(
    of_role_request_failed_error_msg_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ROLE_REQUEST_FAILED_ERROR_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
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
 * Get code from an object of type of_role_request_failed_error_msg.
 * @param obj Pointer to an object of type of_role_request_failed_error_msg.
 * @param code Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_role_request_failed_error_msg_code_get(
    of_role_request_failed_error_msg_t *obj,
    uint16_t *code)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ROLE_REQUEST_FAILED_ERROR_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
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
 * Set code in an object of type of_role_request_failed_error_msg.
 * @param obj Pointer to an object of type of_role_request_failed_error_msg.
 * @param code The value to write into the object
 */
void
of_role_request_failed_error_msg_code_set(
    of_role_request_failed_error_msg_t *obj,
    uint16_t code)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ROLE_REQUEST_FAILED_ERROR_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
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
 * Get data from an object of type of_role_request_failed_error_msg.
 * @param obj Pointer to an object of type of_role_request_failed_error_msg.
 * @param data Pointer to the child object of type
 * of_octets_t to be filled out.
 *
 */
void
of_role_request_failed_error_msg_data_get(
    of_role_request_failed_error_msg_t *obj,
    of_octets_t *data)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_ROLE_REQUEST_FAILED_ERROR_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
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
 * Set data in an object of type of_role_request_failed_error_msg.
 * @param obj Pointer to an object of type of_role_request_failed_error_msg.
 * @param data The value to write into the object
 */
int WARN_UNUSED_RESULT
of_role_request_failed_error_msg_data_set(
    of_role_request_failed_error_msg_t *obj,
    of_octets_t *data)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_ROLE_REQUEST_FAILED_ERROR_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
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


/**
 * \defgroup of_action_id of_action_id
 */

/**
 * Create a new of_action_id object
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
 * \ingroup of_action_id
 */

of_action_id_t *
of_action_id_new(of_version_t version)
{
    of_action_id_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_ID] + of_object_extra_len[version][OF_ACTION_ID];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_action_id_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_action_id_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_action_id.
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
of_action_id_init(of_action_id_t *obj_p,
    of_version_t version, int bytes, int clean_wire)
{
    of_action_id_header_t *obj;

    obj = &obj_p->header;  /* Need instantiable subclass */

    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_ID] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_ID] + of_object_extra_len[version][OF_ACTION_ID];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_ID;

    /* Set up the object's function pointers */

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_action_id_wire_object_id_get;

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
 * \defgroup of_action_id_experimenter of_action_id_experimenter
 */

/**
 * Create a new of_action_id_experimenter object
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
 * \ingroup of_action_id_experimenter
 */

of_action_id_experimenter_t *
of_action_id_experimenter_new(of_version_t version)
{
    of_action_id_experimenter_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_ID_EXPERIMENTER] + of_object_extra_len[version][OF_ACTION_ID_EXPERIMENTER];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_action_id_experimenter_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_action_id_experimenter_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_action_id_experimenter.
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
of_action_id_experimenter_init(of_action_id_experimenter_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_ID_EXPERIMENTER] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_ID_EXPERIMENTER] + of_object_extra_len[version][OF_ACTION_ID_EXPERIMENTER];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_ID_EXPERIMENTER;

    /* Set up the object's function pointers */

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_action_id_wire_object_id_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get experimenter from an object of type of_action_id_experimenter.
 * @param obj Pointer to an object of type of_action_id_experimenter.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_action_id_experimenter_experimenter_get(
    of_action_id_experimenter_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_ID_EXPERIMENTER);
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
 * Set experimenter in an object of type of_action_id_experimenter.
 * @param obj Pointer to an object of type of_action_id_experimenter.
 * @param experimenter The value to write into the object
 */
void
of_action_id_experimenter_experimenter_set(
    of_action_id_experimenter_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_ID_EXPERIMENTER);
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
 * \defgroup of_action_id_bsn of_action_id_bsn
 */

/**
 * Create a new of_action_id_bsn object
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
 * \ingroup of_action_id_bsn
 */

of_action_id_bsn_t *
of_action_id_bsn_new(of_version_t version)
{
    of_action_id_bsn_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_ID_BSN] + of_object_extra_len[version][OF_ACTION_ID_BSN];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_action_id_bsn_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_action_id_bsn_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_action_id_bsn.
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
of_action_id_bsn_init(of_action_id_bsn_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_ID_BSN] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_ID_BSN] + of_object_extra_len[version][OF_ACTION_ID_BSN];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_ID_BSN;

    /* Set up the object's function pointers */

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_action_id_wire_object_id_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get experimenter from an object of type of_action_id_bsn.
 * @param obj Pointer to an object of type of_action_id_bsn.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_action_id_bsn_experimenter_get(
    of_action_id_bsn_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_ID_BSN);
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
 * Set experimenter in an object of type of_action_id_bsn.
 * @param obj Pointer to an object of type of_action_id_bsn.
 * @param experimenter The value to write into the object
 */
void
of_action_id_bsn_experimenter_set(
    of_action_id_bsn_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_ID_BSN);
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
 * Get subtype from an object of type of_action_id_bsn.
 * @param obj Pointer to an object of type of_action_id_bsn.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_action_id_bsn_subtype_get(
    of_action_id_bsn_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_ID_BSN);
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
 * Set subtype in an object of type of_action_id_bsn.
 * @param obj Pointer to an object of type of_action_id_bsn.
 * @param subtype The value to write into the object
 */
void
of_action_id_bsn_subtype_set(
    of_action_id_bsn_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_ID_BSN);
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
of_action_id_bsn_mirror_push_wire_types(of_object_t *obj)
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
 * \defgroup of_action_id_bsn_mirror of_action_id_bsn_mirror
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_action_id_bsn_mirror_push_wire_values(of_action_id_bsn_mirror_t *obj)
{

    of_action_id_bsn_mirror_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_action_id_bsn_mirror object
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
 * \ingroup of_action_id_bsn_mirror
 */

of_action_id_bsn_mirror_t *
of_action_id_bsn_mirror_new(of_version_t version)
{
    of_action_id_bsn_mirror_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_ID_BSN_MIRROR] + of_object_extra_len[version][OF_ACTION_ID_BSN_MIRROR];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_action_id_bsn_mirror_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_action_id_bsn_mirror_init(obj, version, bytes, 0);

    if (of_action_id_bsn_mirror_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_action_id_bsn_mirror.
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
of_action_id_bsn_mirror_init(of_action_id_bsn_mirror_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_ID_BSN_MIRROR] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_ID_BSN_MIRROR] + of_object_extra_len[version][OF_ACTION_ID_BSN_MIRROR];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_ID_BSN_MIRROR;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_action_id_bsn_mirror_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_action_id_wire_object_id_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get experimenter from an object of type of_action_id_bsn_mirror.
 * @param obj Pointer to an object of type of_action_id_bsn_mirror.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_action_id_bsn_mirror_experimenter_get(
    of_action_id_bsn_mirror_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_ID_BSN_MIRROR);
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
 * Set experimenter in an object of type of_action_id_bsn_mirror.
 * @param obj Pointer to an object of type of_action_id_bsn_mirror.
 * @param experimenter The value to write into the object
 */
void
of_action_id_bsn_mirror_experimenter_set(
    of_action_id_bsn_mirror_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_ID_BSN_MIRROR);
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
 * Get subtype from an object of type of_action_id_bsn_mirror.
 * @param obj Pointer to an object of type of_action_id_bsn_mirror.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_action_id_bsn_mirror_subtype_get(
    of_action_id_bsn_mirror_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_ID_BSN_MIRROR);
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
 * Set subtype in an object of type of_action_id_bsn_mirror.
 * @param obj Pointer to an object of type of_action_id_bsn_mirror.
 * @param subtype The value to write into the object
 */
void
of_action_id_bsn_mirror_subtype_set(
    of_action_id_bsn_mirror_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_ID_BSN_MIRROR);
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
of_action_id_bsn_set_tunnel_dst_push_wire_types(of_object_t *obj)
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
 * \defgroup of_action_id_bsn_set_tunnel_dst of_action_id_bsn_set_tunnel_dst
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_action_id_bsn_set_tunnel_dst_push_wire_values(of_action_id_bsn_set_tunnel_dst_t *obj)
{

    of_action_id_bsn_set_tunnel_dst_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_action_id_bsn_set_tunnel_dst object
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
 * \ingroup of_action_id_bsn_set_tunnel_dst
 */

of_action_id_bsn_set_tunnel_dst_t *
of_action_id_bsn_set_tunnel_dst_new(of_version_t version)
{
    of_action_id_bsn_set_tunnel_dst_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_ID_BSN_SET_TUNNEL_DST] + of_object_extra_len[version][OF_ACTION_ID_BSN_SET_TUNNEL_DST];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_action_id_bsn_set_tunnel_dst_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_action_id_bsn_set_tunnel_dst_init(obj, version, bytes, 0);

    if (of_action_id_bsn_set_tunnel_dst_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_action_id_bsn_set_tunnel_dst.
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
of_action_id_bsn_set_tunnel_dst_init(of_action_id_bsn_set_tunnel_dst_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_ID_BSN_SET_TUNNEL_DST] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_ID_BSN_SET_TUNNEL_DST] + of_object_extra_len[version][OF_ACTION_ID_BSN_SET_TUNNEL_DST];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_ID_BSN_SET_TUNNEL_DST;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_action_id_bsn_set_tunnel_dst_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_action_id_wire_object_id_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get experimenter from an object of type of_action_id_bsn_set_tunnel_dst.
 * @param obj Pointer to an object of type of_action_id_bsn_set_tunnel_dst.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_action_id_bsn_set_tunnel_dst_experimenter_get(
    of_action_id_bsn_set_tunnel_dst_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_ID_BSN_SET_TUNNEL_DST);
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
 * Set experimenter in an object of type of_action_id_bsn_set_tunnel_dst.
 * @param obj Pointer to an object of type of_action_id_bsn_set_tunnel_dst.
 * @param experimenter The value to write into the object
 */
void
of_action_id_bsn_set_tunnel_dst_experimenter_set(
    of_action_id_bsn_set_tunnel_dst_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_ID_BSN_SET_TUNNEL_DST);
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
 * Get subtype from an object of type of_action_id_bsn_set_tunnel_dst.
 * @param obj Pointer to an object of type of_action_id_bsn_set_tunnel_dst.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_action_id_bsn_set_tunnel_dst_subtype_get(
    of_action_id_bsn_set_tunnel_dst_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_ID_BSN_SET_TUNNEL_DST);
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
 * Set subtype in an object of type of_action_id_bsn_set_tunnel_dst.
 * @param obj Pointer to an object of type of_action_id_bsn_set_tunnel_dst.
 * @param subtype The value to write into the object
 */
void
of_action_id_bsn_set_tunnel_dst_subtype_set(
    of_action_id_bsn_set_tunnel_dst_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_ID_BSN_SET_TUNNEL_DST);
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
of_action_id_copy_ttl_in_push_wire_types(of_object_t *obj)
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
 * \defgroup of_action_id_copy_ttl_in of_action_id_copy_ttl_in
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_action_id_copy_ttl_in_push_wire_values(of_action_id_copy_ttl_in_t *obj)
{

    of_action_id_copy_ttl_in_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_action_id_copy_ttl_in object
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
 * \ingroup of_action_id_copy_ttl_in
 */

of_action_id_copy_ttl_in_t *
of_action_id_copy_ttl_in_new(of_version_t version)
{
    of_action_id_copy_ttl_in_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_ID_COPY_TTL_IN] + of_object_extra_len[version][OF_ACTION_ID_COPY_TTL_IN];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_action_id_copy_ttl_in_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_action_id_copy_ttl_in_init(obj, version, bytes, 0);

    if (of_action_id_copy_ttl_in_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_action_id_copy_ttl_in.
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
of_action_id_copy_ttl_in_init(of_action_id_copy_ttl_in_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_ID_COPY_TTL_IN] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_ID_COPY_TTL_IN] + of_object_extra_len[version][OF_ACTION_ID_COPY_TTL_IN];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_ID_COPY_TTL_IN;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_action_id_copy_ttl_in_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_action_id_wire_object_id_get;

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
of_action_id_copy_ttl_out_push_wire_types(of_object_t *obj)
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
 * \defgroup of_action_id_copy_ttl_out of_action_id_copy_ttl_out
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_action_id_copy_ttl_out_push_wire_values(of_action_id_copy_ttl_out_t *obj)
{

    of_action_id_copy_ttl_out_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_action_id_copy_ttl_out object
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
 * \ingroup of_action_id_copy_ttl_out
 */

of_action_id_copy_ttl_out_t *
of_action_id_copy_ttl_out_new(of_version_t version)
{
    of_action_id_copy_ttl_out_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_ID_COPY_TTL_OUT] + of_object_extra_len[version][OF_ACTION_ID_COPY_TTL_OUT];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_action_id_copy_ttl_out_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_action_id_copy_ttl_out_init(obj, version, bytes, 0);

    if (of_action_id_copy_ttl_out_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_action_id_copy_ttl_out.
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
of_action_id_copy_ttl_out_init(of_action_id_copy_ttl_out_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_ID_COPY_TTL_OUT] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_ID_COPY_TTL_OUT] + of_object_extra_len[version][OF_ACTION_ID_COPY_TTL_OUT];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_ID_COPY_TTL_OUT;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_action_id_copy_ttl_out_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_action_id_wire_object_id_get;

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
of_action_id_dec_mpls_ttl_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x10); /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_action_id_dec_mpls_ttl of_action_id_dec_mpls_ttl
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_action_id_dec_mpls_ttl_push_wire_values(of_action_id_dec_mpls_ttl_t *obj)
{

    of_action_id_dec_mpls_ttl_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_action_id_dec_mpls_ttl object
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
 * \ingroup of_action_id_dec_mpls_ttl
 */

of_action_id_dec_mpls_ttl_t *
of_action_id_dec_mpls_ttl_new(of_version_t version)
{
    of_action_id_dec_mpls_ttl_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_ID_DEC_MPLS_TTL] + of_object_extra_len[version][OF_ACTION_ID_DEC_MPLS_TTL];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_action_id_dec_mpls_ttl_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_action_id_dec_mpls_ttl_init(obj, version, bytes, 0);

    if (of_action_id_dec_mpls_ttl_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_action_id_dec_mpls_ttl.
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
of_action_id_dec_mpls_ttl_init(of_action_id_dec_mpls_ttl_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_ID_DEC_MPLS_TTL] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_ID_DEC_MPLS_TTL] + of_object_extra_len[version][OF_ACTION_ID_DEC_MPLS_TTL];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_ID_DEC_MPLS_TTL;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_action_id_dec_mpls_ttl_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_action_id_wire_object_id_get;

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
of_action_id_dec_nw_ttl_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x18); /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_action_id_dec_nw_ttl of_action_id_dec_nw_ttl
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_action_id_dec_nw_ttl_push_wire_values(of_action_id_dec_nw_ttl_t *obj)
{

    of_action_id_dec_nw_ttl_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_action_id_dec_nw_ttl object
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
 * \ingroup of_action_id_dec_nw_ttl
 */

of_action_id_dec_nw_ttl_t *
of_action_id_dec_nw_ttl_new(of_version_t version)
{
    of_action_id_dec_nw_ttl_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_ID_DEC_NW_TTL] + of_object_extra_len[version][OF_ACTION_ID_DEC_NW_TTL];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_action_id_dec_nw_ttl_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_action_id_dec_nw_ttl_init(obj, version, bytes, 0);

    if (of_action_id_dec_nw_ttl_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_action_id_dec_nw_ttl.
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
of_action_id_dec_nw_ttl_init(of_action_id_dec_nw_ttl_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_ID_DEC_NW_TTL] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_ID_DEC_NW_TTL] + of_object_extra_len[version][OF_ACTION_ID_DEC_NW_TTL];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_ID_DEC_NW_TTL;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_action_id_dec_nw_ttl_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_action_id_wire_object_id_get;

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
of_action_id_group_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x16); /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_action_id_group of_action_id_group
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_action_id_group_push_wire_values(of_action_id_group_t *obj)
{

    of_action_id_group_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_action_id_group object
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
 * \ingroup of_action_id_group
 */

of_action_id_group_t *
of_action_id_group_new(of_version_t version)
{
    of_action_id_group_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_ID_GROUP] + of_object_extra_len[version][OF_ACTION_ID_GROUP];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_action_id_group_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_action_id_group_init(obj, version, bytes, 0);

    if (of_action_id_group_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_action_id_group.
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
of_action_id_group_init(of_action_id_group_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_ID_GROUP] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_ID_GROUP] + of_object_extra_len[version][OF_ACTION_ID_GROUP];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_ID_GROUP;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_action_id_group_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_action_id_wire_object_id_get;

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
 * \defgroup of_action_id_nicira of_action_id_nicira
 */

/**
 * Create a new of_action_id_nicira object
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
 * \ingroup of_action_id_nicira
 */

of_action_id_nicira_t *
of_action_id_nicira_new(of_version_t version)
{
    of_action_id_nicira_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_ID_NICIRA] + of_object_extra_len[version][OF_ACTION_ID_NICIRA];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_action_id_nicira_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_action_id_nicira_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_action_id_nicira.
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
of_action_id_nicira_init(of_action_id_nicira_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_ID_NICIRA] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_ID_NICIRA] + of_object_extra_len[version][OF_ACTION_ID_NICIRA];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_ID_NICIRA;

    /* Set up the object's function pointers */

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_action_id_wire_object_id_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get experimenter from an object of type of_action_id_nicira.
 * @param obj Pointer to an object of type of_action_id_nicira.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_action_id_nicira_experimenter_get(
    of_action_id_nicira_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_ID_NICIRA);
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
 * Set experimenter in an object of type of_action_id_nicira.
 * @param obj Pointer to an object of type of_action_id_nicira.
 * @param experimenter The value to write into the object
 */
void
of_action_id_nicira_experimenter_set(
    of_action_id_nicira_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_ID_NICIRA);
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
 * Get subtype from an object of type of_action_id_nicira.
 * @param obj Pointer to an object of type of_action_id_nicira.
 * @param subtype Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_action_id_nicira_subtype_get(
    of_action_id_nicira_t *obj,
    uint16_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_ID_NICIRA);
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
    of_wire_buffer_u16_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_action_id_nicira.
 * @param obj Pointer to an object of type of_action_id_nicira.
 * @param subtype The value to write into the object
 */
void
of_action_id_nicira_subtype_set(
    of_action_id_nicira_t *obj,
    uint16_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_ID_NICIRA);
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
    of_wire_buffer_u16_set(wbuf, abs_offset, subtype);

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
of_action_id_nicira_dec_ttl_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0xffff); /* type */
        *(uint32_t *)(buf + 4) = htobe32(0x2320); /* experimenter */
        *(uint16_t *)(buf + 8) = htobe16(0x12); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_action_id_nicira_dec_ttl of_action_id_nicira_dec_ttl
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_action_id_nicira_dec_ttl_push_wire_values(of_action_id_nicira_dec_ttl_t *obj)
{

    of_action_id_nicira_dec_ttl_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_action_id_nicira_dec_ttl object
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
 * \ingroup of_action_id_nicira_dec_ttl
 */

of_action_id_nicira_dec_ttl_t *
of_action_id_nicira_dec_ttl_new(of_version_t version)
{
    of_action_id_nicira_dec_ttl_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_ID_NICIRA_DEC_TTL] + of_object_extra_len[version][OF_ACTION_ID_NICIRA_DEC_TTL];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_action_id_nicira_dec_ttl_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_action_id_nicira_dec_ttl_init(obj, version, bytes, 0);

    if (of_action_id_nicira_dec_ttl_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_action_id_nicira_dec_ttl.
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
of_action_id_nicira_dec_ttl_init(of_action_id_nicira_dec_ttl_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_ID_NICIRA_DEC_TTL] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_ID_NICIRA_DEC_TTL] + of_object_extra_len[version][OF_ACTION_ID_NICIRA_DEC_TTL];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_ID_NICIRA_DEC_TTL;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_action_id_nicira_dec_ttl_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_action_id_wire_object_id_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get experimenter from an object of type of_action_id_nicira_dec_ttl.
 * @param obj Pointer to an object of type of_action_id_nicira_dec_ttl.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_action_id_nicira_dec_ttl_experimenter_get(
    of_action_id_nicira_dec_ttl_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_ID_NICIRA_DEC_TTL);
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
 * Set experimenter in an object of type of_action_id_nicira_dec_ttl.
 * @param obj Pointer to an object of type of_action_id_nicira_dec_ttl.
 * @param experimenter The value to write into the object
 */
void
of_action_id_nicira_dec_ttl_experimenter_set(
    of_action_id_nicira_dec_ttl_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_ID_NICIRA_DEC_TTL);
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
 * Get subtype from an object of type of_action_id_nicira_dec_ttl.
 * @param obj Pointer to an object of type of_action_id_nicira_dec_ttl.
 * @param subtype Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_action_id_nicira_dec_ttl_subtype_get(
    of_action_id_nicira_dec_ttl_t *obj,
    uint16_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_ID_NICIRA_DEC_TTL);
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
    of_wire_buffer_u16_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_action_id_nicira_dec_ttl.
 * @param obj Pointer to an object of type of_action_id_nicira_dec_ttl.
 * @param subtype The value to write into the object
 */
void
of_action_id_nicira_dec_ttl_subtype_set(
    of_action_id_nicira_dec_ttl_t *obj,
    uint16_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_ID_NICIRA_DEC_TTL);
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
    of_wire_buffer_u16_set(wbuf, abs_offset, subtype);

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
of_action_id_output_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x0); /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_action_id_output of_action_id_output
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_action_id_output_push_wire_values(of_action_id_output_t *obj)
{

    of_action_id_output_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_action_id_output object
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
 * \ingroup of_action_id_output
 */

of_action_id_output_t *
of_action_id_output_new(of_version_t version)
{
    of_action_id_output_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_ID_OUTPUT] + of_object_extra_len[version][OF_ACTION_ID_OUTPUT];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_action_id_output_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_action_id_output_init(obj, version, bytes, 0);

    if (of_action_id_output_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_action_id_output.
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
of_action_id_output_init(of_action_id_output_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_ID_OUTPUT] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_ID_OUTPUT] + of_object_extra_len[version][OF_ACTION_ID_OUTPUT];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_ID_OUTPUT;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_action_id_output_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_action_id_wire_object_id_get;

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
of_action_id_pop_mpls_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x14); /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_action_id_pop_mpls of_action_id_pop_mpls
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_action_id_pop_mpls_push_wire_values(of_action_id_pop_mpls_t *obj)
{

    of_action_id_pop_mpls_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_action_id_pop_mpls object
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
 * \ingroup of_action_id_pop_mpls
 */

of_action_id_pop_mpls_t *
of_action_id_pop_mpls_new(of_version_t version)
{
    of_action_id_pop_mpls_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_ID_POP_MPLS] + of_object_extra_len[version][OF_ACTION_ID_POP_MPLS];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_action_id_pop_mpls_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_action_id_pop_mpls_init(obj, version, bytes, 0);

    if (of_action_id_pop_mpls_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_action_id_pop_mpls.
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
of_action_id_pop_mpls_init(of_action_id_pop_mpls_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_ID_POP_MPLS] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_ID_POP_MPLS] + of_object_extra_len[version][OF_ACTION_ID_POP_MPLS];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_ID_POP_MPLS;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_action_id_pop_mpls_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_action_id_wire_object_id_get;

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
of_action_pop_pbb_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x1b); /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_action_pop_pbb of_action_pop_pbb
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_action_pop_pbb_push_wire_values(of_action_pop_pbb_t *obj)
{

    of_action_pop_pbb_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_action_pop_pbb object
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
 * \ingroup of_action_pop_pbb
 */

of_action_pop_pbb_t *
of_action_pop_pbb_new(of_version_t version)
{
    of_action_pop_pbb_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_POP_PBB] + of_object_extra_len[version][OF_ACTION_POP_PBB];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_action_pop_pbb_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_action_pop_pbb_init(obj, version, bytes, 0);

    if (of_action_pop_pbb_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_action_pop_pbb.
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
of_action_pop_pbb_init(of_action_pop_pbb_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_POP_PBB] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_POP_PBB] + of_object_extra_len[version][OF_ACTION_POP_PBB];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_POP_PBB;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_action_pop_pbb_push_wire_types;

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
of_action_id_pop_pbb_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x1b); /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_action_id_pop_pbb of_action_id_pop_pbb
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_action_id_pop_pbb_push_wire_values(of_action_id_pop_pbb_t *obj)
{

    of_action_id_pop_pbb_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_action_id_pop_pbb object
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
 * \ingroup of_action_id_pop_pbb
 */

of_action_id_pop_pbb_t *
of_action_id_pop_pbb_new(of_version_t version)
{
    of_action_id_pop_pbb_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_ID_POP_PBB] + of_object_extra_len[version][OF_ACTION_ID_POP_PBB];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_action_id_pop_pbb_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_action_id_pop_pbb_init(obj, version, bytes, 0);

    if (of_action_id_pop_pbb_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_action_id_pop_pbb.
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
of_action_id_pop_pbb_init(of_action_id_pop_pbb_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_ID_POP_PBB] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_ID_POP_PBB] + of_object_extra_len[version][OF_ACTION_ID_POP_PBB];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_ID_POP_PBB;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_action_id_pop_pbb_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_action_id_wire_object_id_get;

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
of_action_id_pop_vlan_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x12); /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_action_id_pop_vlan of_action_id_pop_vlan
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_action_id_pop_vlan_push_wire_values(of_action_id_pop_vlan_t *obj)
{

    of_action_id_pop_vlan_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_action_id_pop_vlan object
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
 * \ingroup of_action_id_pop_vlan
 */

of_action_id_pop_vlan_t *
of_action_id_pop_vlan_new(of_version_t version)
{
    of_action_id_pop_vlan_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_ID_POP_VLAN] + of_object_extra_len[version][OF_ACTION_ID_POP_VLAN];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_action_id_pop_vlan_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_action_id_pop_vlan_init(obj, version, bytes, 0);

    if (of_action_id_pop_vlan_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_action_id_pop_vlan.
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
of_action_id_pop_vlan_init(of_action_id_pop_vlan_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_ID_POP_VLAN] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_ID_POP_VLAN] + of_object_extra_len[version][OF_ACTION_ID_POP_VLAN];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_ID_POP_VLAN;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_action_id_pop_vlan_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_action_id_wire_object_id_get;

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
of_action_id_push_mpls_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x13); /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_action_id_push_mpls of_action_id_push_mpls
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_action_id_push_mpls_push_wire_values(of_action_id_push_mpls_t *obj)
{

    of_action_id_push_mpls_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_action_id_push_mpls object
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
 * \ingroup of_action_id_push_mpls
 */

of_action_id_push_mpls_t *
of_action_id_push_mpls_new(of_version_t version)
{
    of_action_id_push_mpls_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_ID_PUSH_MPLS] + of_object_extra_len[version][OF_ACTION_ID_PUSH_MPLS];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_action_id_push_mpls_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_action_id_push_mpls_init(obj, version, bytes, 0);

    if (of_action_id_push_mpls_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_action_id_push_mpls.
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
of_action_id_push_mpls_init(of_action_id_push_mpls_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_ID_PUSH_MPLS] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_ID_PUSH_MPLS] + of_object_extra_len[version][OF_ACTION_ID_PUSH_MPLS];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_ID_PUSH_MPLS;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_action_id_push_mpls_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_action_id_wire_object_id_get;

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
of_action_push_pbb_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x1a); /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_action_push_pbb of_action_push_pbb
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_action_push_pbb_push_wire_values(of_action_push_pbb_t *obj)
{

    of_action_push_pbb_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_action_push_pbb object
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
 * \ingroup of_action_push_pbb
 */

of_action_push_pbb_t *
of_action_push_pbb_new(of_version_t version)
{
    of_action_push_pbb_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_PUSH_PBB] + of_object_extra_len[version][OF_ACTION_PUSH_PBB];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_action_push_pbb_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_action_push_pbb_init(obj, version, bytes, 0);

    if (of_action_push_pbb_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_action_push_pbb.
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
of_action_push_pbb_init(of_action_push_pbb_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_PUSH_PBB] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_PUSH_PBB] + of_object_extra_len[version][OF_ACTION_PUSH_PBB];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_PUSH_PBB;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_action_push_pbb_push_wire_types;

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
 * Get ethertype from an object of type of_action_push_pbb.
 * @param obj Pointer to an object of type of_action_push_pbb.
 * @param ethertype Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_action_push_pbb_ethertype_get(
    of_action_push_pbb_t *obj,
    uint16_t *ethertype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_PUSH_PBB);
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
    of_wire_buffer_u16_get(wbuf, abs_offset, ethertype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set ethertype in an object of type of_action_push_pbb.
 * @param obj Pointer to an object of type of_action_push_pbb.
 * @param ethertype The value to write into the object
 */
void
of_action_push_pbb_ethertype_set(
    of_action_push_pbb_t *obj,
    uint16_t ethertype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_PUSH_PBB);
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
    of_wire_buffer_u16_set(wbuf, abs_offset, ethertype);

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
of_action_id_push_pbb_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x1a); /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_action_id_push_pbb of_action_id_push_pbb
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_action_id_push_pbb_push_wire_values(of_action_id_push_pbb_t *obj)
{

    of_action_id_push_pbb_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_action_id_push_pbb object
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
 * \ingroup of_action_id_push_pbb
 */

of_action_id_push_pbb_t *
of_action_id_push_pbb_new(of_version_t version)
{
    of_action_id_push_pbb_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_ID_PUSH_PBB] + of_object_extra_len[version][OF_ACTION_ID_PUSH_PBB];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_action_id_push_pbb_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_action_id_push_pbb_init(obj, version, bytes, 0);

    if (of_action_id_push_pbb_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_action_id_push_pbb.
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
of_action_id_push_pbb_init(of_action_id_push_pbb_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_ID_PUSH_PBB] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_ID_PUSH_PBB] + of_object_extra_len[version][OF_ACTION_ID_PUSH_PBB];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_ID_PUSH_PBB;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_action_id_push_pbb_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_action_id_wire_object_id_get;

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
of_action_id_push_vlan_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x11); /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_action_id_push_vlan of_action_id_push_vlan
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_action_id_push_vlan_push_wire_values(of_action_id_push_vlan_t *obj)
{

    of_action_id_push_vlan_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_action_id_push_vlan object
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
 * \ingroup of_action_id_push_vlan
 */

of_action_id_push_vlan_t *
of_action_id_push_vlan_new(of_version_t version)
{
    of_action_id_push_vlan_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_ID_PUSH_VLAN] + of_object_extra_len[version][OF_ACTION_ID_PUSH_VLAN];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_action_id_push_vlan_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_action_id_push_vlan_init(obj, version, bytes, 0);

    if (of_action_id_push_vlan_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_action_id_push_vlan.
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
of_action_id_push_vlan_init(of_action_id_push_vlan_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_ID_PUSH_VLAN] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_ID_PUSH_VLAN] + of_object_extra_len[version][OF_ACTION_ID_PUSH_VLAN];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_ID_PUSH_VLAN;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_action_id_push_vlan_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_action_id_wire_object_id_get;

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
of_action_id_set_field_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x19); /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_action_id_set_field of_action_id_set_field
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_action_id_set_field_push_wire_values(of_action_id_set_field_t *obj)
{

    of_action_id_set_field_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_action_id_set_field object
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
 * \ingroup of_action_id_set_field
 */

of_action_id_set_field_t *
of_action_id_set_field_new(of_version_t version)
{
    of_action_id_set_field_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_ID_SET_FIELD] + of_object_extra_len[version][OF_ACTION_ID_SET_FIELD];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_action_id_set_field_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_action_id_set_field_init(obj, version, bytes, 0);

    if (of_action_id_set_field_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_action_id_set_field.
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
of_action_id_set_field_init(of_action_id_set_field_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_ID_SET_FIELD] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_ID_SET_FIELD] + of_object_extra_len[version][OF_ACTION_ID_SET_FIELD];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_ID_SET_FIELD;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_action_id_set_field_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_action_id_wire_object_id_get;

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
of_action_id_set_mpls_ttl_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0xf); /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_action_id_set_mpls_ttl of_action_id_set_mpls_ttl
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_action_id_set_mpls_ttl_push_wire_values(of_action_id_set_mpls_ttl_t *obj)
{

    of_action_id_set_mpls_ttl_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_action_id_set_mpls_ttl object
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
 * \ingroup of_action_id_set_mpls_ttl
 */

of_action_id_set_mpls_ttl_t *
of_action_id_set_mpls_ttl_new(of_version_t version)
{
    of_action_id_set_mpls_ttl_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_ID_SET_MPLS_TTL] + of_object_extra_len[version][OF_ACTION_ID_SET_MPLS_TTL];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_action_id_set_mpls_ttl_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_action_id_set_mpls_ttl_init(obj, version, bytes, 0);

    if (of_action_id_set_mpls_ttl_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_action_id_set_mpls_ttl.
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
of_action_id_set_mpls_ttl_init(of_action_id_set_mpls_ttl_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_ID_SET_MPLS_TTL] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_ID_SET_MPLS_TTL] + of_object_extra_len[version][OF_ACTION_ID_SET_MPLS_TTL];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_ID_SET_MPLS_TTL;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_action_id_set_mpls_ttl_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_action_id_wire_object_id_get;

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
of_action_id_set_nw_ttl_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x17); /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_action_id_set_nw_ttl of_action_id_set_nw_ttl
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_action_id_set_nw_ttl_push_wire_values(of_action_id_set_nw_ttl_t *obj)
{

    of_action_id_set_nw_ttl_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_action_id_set_nw_ttl object
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
 * \ingroup of_action_id_set_nw_ttl
 */

of_action_id_set_nw_ttl_t *
of_action_id_set_nw_ttl_new(of_version_t version)
{
    of_action_id_set_nw_ttl_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_ID_SET_NW_TTL] + of_object_extra_len[version][OF_ACTION_ID_SET_NW_TTL];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_action_id_set_nw_ttl_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_action_id_set_nw_ttl_init(obj, version, bytes, 0);

    if (of_action_id_set_nw_ttl_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_action_id_set_nw_ttl.
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
of_action_id_set_nw_ttl_init(of_action_id_set_nw_ttl_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_ID_SET_NW_TTL] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_ID_SET_NW_TTL] + of_object_extra_len[version][OF_ACTION_ID_SET_NW_TTL];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_ID_SET_NW_TTL;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_action_id_set_nw_ttl_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_action_id_wire_object_id_get;

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
of_action_id_set_queue_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x15); /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_action_id_set_queue of_action_id_set_queue
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_action_id_set_queue_push_wire_values(of_action_id_set_queue_t *obj)
{

    of_action_id_set_queue_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_action_id_set_queue object
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
 * \ingroup of_action_id_set_queue
 */

of_action_id_set_queue_t *
of_action_id_set_queue_new(of_version_t version)
{
    of_action_id_set_queue_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_ID_SET_QUEUE] + of_object_extra_len[version][OF_ACTION_ID_SET_QUEUE];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_action_id_set_queue_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_action_id_set_queue_init(obj, version, bytes, 0);

    if (of_action_id_set_queue_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_action_id_set_queue.
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
of_action_id_set_queue_init(of_action_id_set_queue_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_ID_SET_QUEUE] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_ID_SET_QUEUE] + of_object_extra_len[version][OF_ACTION_ID_SET_QUEUE];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_ID_SET_QUEUE;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_action_id_set_queue_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_action_id_wire_object_id_get;

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
of_async_get_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x1b; /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_async_get_reply of_async_get_reply
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_async_get_reply_push_wire_values(of_async_get_reply_t *obj)
{

    of_async_get_reply_push_wire_types(obj);

    /* Message obj; set length */
    of_message_t msg;

    if ((msg = OF_OBJECT_TO_MESSAGE(obj)) != NULL) {
        of_message_length_set(msg, obj->length);
    }

    return OF_ERROR_NONE;
}

/**
 * Create a new of_async_get_reply object
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
 * \ingroup of_async_get_reply
 */

of_async_get_reply_t *
of_async_get_reply_new(of_version_t version)
{
    of_async_get_reply_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ASYNC_GET_REPLY] + of_object_extra_len[version][OF_ASYNC_GET_REPLY];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_async_get_reply_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_async_get_reply_init(obj, version, bytes, 0);

    if (of_async_get_reply_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_async_get_reply.
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
of_async_get_reply_init(of_async_get_reply_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_ASYNC_GET_REPLY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ASYNC_GET_REPLY] + of_object_extra_len[version][OF_ASYNC_GET_REPLY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ASYNC_GET_REPLY;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_async_get_reply_push_wire_types;

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
 * Create a new of_async_get_reply object and bind it to an existing message
 *
 * @param msg The message to bind the new object to
 * @return Pointer to the newly create object or NULL on error
 *
 * \ingroup of_async_get_reply
 */

of_async_get_reply_t *
of_async_get_reply_new_from_message(of_message_t msg)
{
    of_async_get_reply_t *obj = NULL;
    of_version_t version;
    int length;

    if (msg == NULL) return NULL;

    version = of_message_version_get(msg);
    if (!OF_VERSION_OKAY(version)) return NULL;

    length = of_message_length_get(msg);

    if ((obj = (of_async_get_reply_t *)of_object_new(-1)) == NULL) {
        return NULL;
    }

    of_async_get_reply_init(obj, version, 0, 0);

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
 * Get xid from an object of type of_async_get_reply.
 * @param obj Pointer to an object of type of_async_get_reply.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_async_get_reply_xid_get(
    of_async_get_reply_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ASYNC_GET_REPLY);
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
 * Set xid in an object of type of_async_get_reply.
 * @param obj Pointer to an object of type of_async_get_reply.
 * @param xid The value to write into the object
 */
void
of_async_get_reply_xid_set(
    of_async_get_reply_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ASYNC_GET_REPLY);
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
 * Get packet_in_mask_equal_master from an object of type of_async_get_reply.
 * @param obj Pointer to an object of type of_async_get_reply.
 * @param packet_in_mask_equal_master Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_async_get_reply_packet_in_mask_equal_master_get(
    of_async_get_reply_t *obj,
    uint32_t *packet_in_mask_equal_master)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ASYNC_GET_REPLY);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, packet_in_mask_equal_master);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set packet_in_mask_equal_master in an object of type of_async_get_reply.
 * @param obj Pointer to an object of type of_async_get_reply.
 * @param packet_in_mask_equal_master The value to write into the object
 */
void
of_async_get_reply_packet_in_mask_equal_master_set(
    of_async_get_reply_t *obj,
    uint32_t packet_in_mask_equal_master)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ASYNC_GET_REPLY);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, packet_in_mask_equal_master);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get packet_in_mask_slave from an object of type of_async_get_reply.
 * @param obj Pointer to an object of type of_async_get_reply.
 * @param packet_in_mask_slave Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_async_get_reply_packet_in_mask_slave_get(
    of_async_get_reply_t *obj,
    uint32_t *packet_in_mask_slave)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ASYNC_GET_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, packet_in_mask_slave);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set packet_in_mask_slave in an object of type of_async_get_reply.
 * @param obj Pointer to an object of type of_async_get_reply.
 * @param packet_in_mask_slave The value to write into the object
 */
void
of_async_get_reply_packet_in_mask_slave_set(
    of_async_get_reply_t *obj,
    uint32_t packet_in_mask_slave)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ASYNC_GET_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, packet_in_mask_slave);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get port_status_mask_equal_master from an object of type of_async_get_reply.
 * @param obj Pointer to an object of type of_async_get_reply.
 * @param port_status_mask_equal_master Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_async_get_reply_port_status_mask_equal_master_get(
    of_async_get_reply_t *obj,
    uint32_t *port_status_mask_equal_master)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ASYNC_GET_REPLY);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, port_status_mask_equal_master);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set port_status_mask_equal_master in an object of type of_async_get_reply.
 * @param obj Pointer to an object of type of_async_get_reply.
 * @param port_status_mask_equal_master The value to write into the object
 */
void
of_async_get_reply_port_status_mask_equal_master_set(
    of_async_get_reply_t *obj,
    uint32_t port_status_mask_equal_master)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ASYNC_GET_REPLY);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, port_status_mask_equal_master);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get port_status_mask_slave from an object of type of_async_get_reply.
 * @param obj Pointer to an object of type of_async_get_reply.
 * @param port_status_mask_slave Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_async_get_reply_port_status_mask_slave_get(
    of_async_get_reply_t *obj,
    uint32_t *port_status_mask_slave)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ASYNC_GET_REPLY);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, port_status_mask_slave);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set port_status_mask_slave in an object of type of_async_get_reply.
 * @param obj Pointer to an object of type of_async_get_reply.
 * @param port_status_mask_slave The value to write into the object
 */
void
of_async_get_reply_port_status_mask_slave_set(
    of_async_get_reply_t *obj,
    uint32_t port_status_mask_slave)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ASYNC_GET_REPLY);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, port_status_mask_slave);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get flow_removed_mask_equal_master from an object of type of_async_get_reply.
 * @param obj Pointer to an object of type of_async_get_reply.
 * @param flow_removed_mask_equal_master Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_async_get_reply_flow_removed_mask_equal_master_get(
    of_async_get_reply_t *obj,
    uint32_t *flow_removed_mask_equal_master)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ASYNC_GET_REPLY);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, flow_removed_mask_equal_master);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set flow_removed_mask_equal_master in an object of type of_async_get_reply.
 * @param obj Pointer to an object of type of_async_get_reply.
 * @param flow_removed_mask_equal_master The value to write into the object
 */
void
of_async_get_reply_flow_removed_mask_equal_master_set(
    of_async_get_reply_t *obj,
    uint32_t flow_removed_mask_equal_master)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ASYNC_GET_REPLY);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, flow_removed_mask_equal_master);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get flow_removed_mask_slave from an object of type of_async_get_reply.
 * @param obj Pointer to an object of type of_async_get_reply.
 * @param flow_removed_mask_slave Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_async_get_reply_flow_removed_mask_slave_get(
    of_async_get_reply_t *obj,
    uint32_t *flow_removed_mask_slave)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ASYNC_GET_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 28;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, flow_removed_mask_slave);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set flow_removed_mask_slave in an object of type of_async_get_reply.
 * @param obj Pointer to an object of type of_async_get_reply.
 * @param flow_removed_mask_slave The value to write into the object
 */
void
of_async_get_reply_flow_removed_mask_slave_set(
    of_async_get_reply_t *obj,
    uint32_t flow_removed_mask_slave)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ASYNC_GET_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 28;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, flow_removed_mask_slave);

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
of_async_get_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x1a; /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_async_get_request of_async_get_request
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_async_get_request_push_wire_values(of_async_get_request_t *obj)
{

    of_async_get_request_push_wire_types(obj);

    /* Message obj; set length */
    of_message_t msg;

    if ((msg = OF_OBJECT_TO_MESSAGE(obj)) != NULL) {
        of_message_length_set(msg, obj->length);
    }

    return OF_ERROR_NONE;
}

/**
 * Create a new of_async_get_request object
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
 * \ingroup of_async_get_request
 */

of_async_get_request_t *
of_async_get_request_new(of_version_t version)
{
    of_async_get_request_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ASYNC_GET_REQUEST] + of_object_extra_len[version][OF_ASYNC_GET_REQUEST];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_async_get_request_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_async_get_request_init(obj, version, bytes, 0);

    if (of_async_get_request_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_async_get_request.
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
of_async_get_request_init(of_async_get_request_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_ASYNC_GET_REQUEST] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ASYNC_GET_REQUEST] + of_object_extra_len[version][OF_ASYNC_GET_REQUEST];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ASYNC_GET_REQUEST;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_async_get_request_push_wire_types;

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
 * Create a new of_async_get_request object and bind it to an existing message
 *
 * @param msg The message to bind the new object to
 * @return Pointer to the newly create object or NULL on error
 *
 * \ingroup of_async_get_request
 */

of_async_get_request_t *
of_async_get_request_new_from_message(of_message_t msg)
{
    of_async_get_request_t *obj = NULL;
    of_version_t version;
    int length;

    if (msg == NULL) return NULL;

    version = of_message_version_get(msg);
    if (!OF_VERSION_OKAY(version)) return NULL;

    length = of_message_length_get(msg);

    if ((obj = (of_async_get_request_t *)of_object_new(-1)) == NULL) {
        return NULL;
    }

    of_async_get_request_init(obj, version, 0, 0);

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
 * Get xid from an object of type of_async_get_request.
 * @param obj Pointer to an object of type of_async_get_request.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_async_get_request_xid_get(
    of_async_get_request_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ASYNC_GET_REQUEST);
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
 * Set xid in an object of type of_async_get_request.
 * @param obj Pointer to an object of type of_async_get_request.
 * @param xid The value to write into the object
 */
void
of_async_get_request_xid_set(
    of_async_get_request_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ASYNC_GET_REQUEST);
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
 * Get packet_in_mask_equal_master from an object of type of_async_get_request.
 * @param obj Pointer to an object of type of_async_get_request.
 * @param packet_in_mask_equal_master Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_async_get_request_packet_in_mask_equal_master_get(
    of_async_get_request_t *obj,
    uint32_t *packet_in_mask_equal_master)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ASYNC_GET_REQUEST);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, packet_in_mask_equal_master);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set packet_in_mask_equal_master in an object of type of_async_get_request.
 * @param obj Pointer to an object of type of_async_get_request.
 * @param packet_in_mask_equal_master The value to write into the object
 */
void
of_async_get_request_packet_in_mask_equal_master_set(
    of_async_get_request_t *obj,
    uint32_t packet_in_mask_equal_master)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ASYNC_GET_REQUEST);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, packet_in_mask_equal_master);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get packet_in_mask_slave from an object of type of_async_get_request.
 * @param obj Pointer to an object of type of_async_get_request.
 * @param packet_in_mask_slave Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_async_get_request_packet_in_mask_slave_get(
    of_async_get_request_t *obj,
    uint32_t *packet_in_mask_slave)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ASYNC_GET_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, packet_in_mask_slave);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set packet_in_mask_slave in an object of type of_async_get_request.
 * @param obj Pointer to an object of type of_async_get_request.
 * @param packet_in_mask_slave The value to write into the object
 */
void
of_async_get_request_packet_in_mask_slave_set(
    of_async_get_request_t *obj,
    uint32_t packet_in_mask_slave)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ASYNC_GET_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, packet_in_mask_slave);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get port_status_mask_equal_master from an object of type of_async_get_request.
 * @param obj Pointer to an object of type of_async_get_request.
 * @param port_status_mask_equal_master Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_async_get_request_port_status_mask_equal_master_get(
    of_async_get_request_t *obj,
    uint32_t *port_status_mask_equal_master)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ASYNC_GET_REQUEST);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, port_status_mask_equal_master);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set port_status_mask_equal_master in an object of type of_async_get_request.
 * @param obj Pointer to an object of type of_async_get_request.
 * @param port_status_mask_equal_master The value to write into the object
 */
void
of_async_get_request_port_status_mask_equal_master_set(
    of_async_get_request_t *obj,
    uint32_t port_status_mask_equal_master)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ASYNC_GET_REQUEST);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, port_status_mask_equal_master);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get port_status_mask_slave from an object of type of_async_get_request.
 * @param obj Pointer to an object of type of_async_get_request.
 * @param port_status_mask_slave Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_async_get_request_port_status_mask_slave_get(
    of_async_get_request_t *obj,
    uint32_t *port_status_mask_slave)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ASYNC_GET_REQUEST);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, port_status_mask_slave);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set port_status_mask_slave in an object of type of_async_get_request.
 * @param obj Pointer to an object of type of_async_get_request.
 * @param port_status_mask_slave The value to write into the object
 */
void
of_async_get_request_port_status_mask_slave_set(
    of_async_get_request_t *obj,
    uint32_t port_status_mask_slave)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ASYNC_GET_REQUEST);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, port_status_mask_slave);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get flow_removed_mask_equal_master from an object of type of_async_get_request.
 * @param obj Pointer to an object of type of_async_get_request.
 * @param flow_removed_mask_equal_master Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_async_get_request_flow_removed_mask_equal_master_get(
    of_async_get_request_t *obj,
    uint32_t *flow_removed_mask_equal_master)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ASYNC_GET_REQUEST);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, flow_removed_mask_equal_master);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set flow_removed_mask_equal_master in an object of type of_async_get_request.
 * @param obj Pointer to an object of type of_async_get_request.
 * @param flow_removed_mask_equal_master The value to write into the object
 */
void
of_async_get_request_flow_removed_mask_equal_master_set(
    of_async_get_request_t *obj,
    uint32_t flow_removed_mask_equal_master)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ASYNC_GET_REQUEST);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, flow_removed_mask_equal_master);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get flow_removed_mask_slave from an object of type of_async_get_request.
 * @param obj Pointer to an object of type of_async_get_request.
 * @param flow_removed_mask_slave Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_async_get_request_flow_removed_mask_slave_get(
    of_async_get_request_t *obj,
    uint32_t *flow_removed_mask_slave)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ASYNC_GET_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 28;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, flow_removed_mask_slave);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set flow_removed_mask_slave in an object of type of_async_get_request.
 * @param obj Pointer to an object of type of_async_get_request.
 * @param flow_removed_mask_slave The value to write into the object
 */
void
of_async_get_request_flow_removed_mask_slave_set(
    of_async_get_request_t *obj,
    uint32_t flow_removed_mask_slave)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ASYNC_GET_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 28;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, flow_removed_mask_slave);

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
of_async_set_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x1c; /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_async_set of_async_set
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_async_set_push_wire_values(of_async_set_t *obj)
{

    of_async_set_push_wire_types(obj);

    /* Message obj; set length */
    of_message_t msg;

    if ((msg = OF_OBJECT_TO_MESSAGE(obj)) != NULL) {
        of_message_length_set(msg, obj->length);
    }

    return OF_ERROR_NONE;
}

/**
 * Create a new of_async_set object
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
 * \ingroup of_async_set
 */

of_async_set_t *
of_async_set_new(of_version_t version)
{
    of_async_set_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ASYNC_SET] + of_object_extra_len[version][OF_ASYNC_SET];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_async_set_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_async_set_init(obj, version, bytes, 0);

    if (of_async_set_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_async_set.
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
of_async_set_init(of_async_set_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_ASYNC_SET] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ASYNC_SET] + of_object_extra_len[version][OF_ASYNC_SET];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ASYNC_SET;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_async_set_push_wire_types;

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
 * Create a new of_async_set object and bind it to an existing message
 *
 * @param msg The message to bind the new object to
 * @return Pointer to the newly create object or NULL on error
 *
 * \ingroup of_async_set
 */

of_async_set_t *
of_async_set_new_from_message(of_message_t msg)
{
    of_async_set_t *obj = NULL;
    of_version_t version;
    int length;

    if (msg == NULL) return NULL;

    version = of_message_version_get(msg);
    if (!OF_VERSION_OKAY(version)) return NULL;

    length = of_message_length_get(msg);

    if ((obj = (of_async_set_t *)of_object_new(-1)) == NULL) {
        return NULL;
    }

    of_async_set_init(obj, version, 0, 0);

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
 * Get xid from an object of type of_async_set.
 * @param obj Pointer to an object of type of_async_set.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_async_set_xid_get(
    of_async_set_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ASYNC_SET);
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
 * Set xid in an object of type of_async_set.
 * @param obj Pointer to an object of type of_async_set.
 * @param xid The value to write into the object
 */
void
of_async_set_xid_set(
    of_async_set_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ASYNC_SET);
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
 * Get packet_in_mask_equal_master from an object of type of_async_set.
 * @param obj Pointer to an object of type of_async_set.
 * @param packet_in_mask_equal_master Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_async_set_packet_in_mask_equal_master_get(
    of_async_set_t *obj,
    uint32_t *packet_in_mask_equal_master)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ASYNC_SET);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, packet_in_mask_equal_master);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set packet_in_mask_equal_master in an object of type of_async_set.
 * @param obj Pointer to an object of type of_async_set.
 * @param packet_in_mask_equal_master The value to write into the object
 */
void
of_async_set_packet_in_mask_equal_master_set(
    of_async_set_t *obj,
    uint32_t packet_in_mask_equal_master)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ASYNC_SET);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, packet_in_mask_equal_master);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get packet_in_mask_slave from an object of type of_async_set.
 * @param obj Pointer to an object of type of_async_set.
 * @param packet_in_mask_slave Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_async_set_packet_in_mask_slave_get(
    of_async_set_t *obj,
    uint32_t *packet_in_mask_slave)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ASYNC_SET);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, packet_in_mask_slave);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set packet_in_mask_slave in an object of type of_async_set.
 * @param obj Pointer to an object of type of_async_set.
 * @param packet_in_mask_slave The value to write into the object
 */
void
of_async_set_packet_in_mask_slave_set(
    of_async_set_t *obj,
    uint32_t packet_in_mask_slave)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ASYNC_SET);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, packet_in_mask_slave);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get port_status_mask_equal_master from an object of type of_async_set.
 * @param obj Pointer to an object of type of_async_set.
 * @param port_status_mask_equal_master Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_async_set_port_status_mask_equal_master_get(
    of_async_set_t *obj,
    uint32_t *port_status_mask_equal_master)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ASYNC_SET);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, port_status_mask_equal_master);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set port_status_mask_equal_master in an object of type of_async_set.
 * @param obj Pointer to an object of type of_async_set.
 * @param port_status_mask_equal_master The value to write into the object
 */
void
of_async_set_port_status_mask_equal_master_set(
    of_async_set_t *obj,
    uint32_t port_status_mask_equal_master)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ASYNC_SET);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, port_status_mask_equal_master);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get port_status_mask_slave from an object of type of_async_set.
 * @param obj Pointer to an object of type of_async_set.
 * @param port_status_mask_slave Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_async_set_port_status_mask_slave_get(
    of_async_set_t *obj,
    uint32_t *port_status_mask_slave)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ASYNC_SET);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, port_status_mask_slave);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set port_status_mask_slave in an object of type of_async_set.
 * @param obj Pointer to an object of type of_async_set.
 * @param port_status_mask_slave The value to write into the object
 */
void
of_async_set_port_status_mask_slave_set(
    of_async_set_t *obj,
    uint32_t port_status_mask_slave)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ASYNC_SET);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, port_status_mask_slave);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get flow_removed_mask_equal_master from an object of type of_async_set.
 * @param obj Pointer to an object of type of_async_set.
 * @param flow_removed_mask_equal_master Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_async_set_flow_removed_mask_equal_master_get(
    of_async_set_t *obj,
    uint32_t *flow_removed_mask_equal_master)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ASYNC_SET);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, flow_removed_mask_equal_master);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set flow_removed_mask_equal_master in an object of type of_async_set.
 * @param obj Pointer to an object of type of_async_set.
 * @param flow_removed_mask_equal_master The value to write into the object
 */
void
of_async_set_flow_removed_mask_equal_master_set(
    of_async_set_t *obj,
    uint32_t flow_removed_mask_equal_master)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ASYNC_SET);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, flow_removed_mask_equal_master);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get flow_removed_mask_slave from an object of type of_async_set.
 * @param obj Pointer to an object of type of_async_set.
 * @param flow_removed_mask_slave Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_async_set_flow_removed_mask_slave_get(
    of_async_set_t *obj,
    uint32_t *flow_removed_mask_slave)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ASYNC_SET);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 28;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, flow_removed_mask_slave);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set flow_removed_mask_slave in an object of type of_async_set.
 * @param obj Pointer to an object of type of_async_set.
 * @param flow_removed_mask_slave The value to write into the object
 */
void
of_async_set_flow_removed_mask_slave_set(
    of_async_set_t *obj,
    uint32_t flow_removed_mask_slave)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ASYNC_SET);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 28;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, flow_removed_mask_slave);

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
of_bsn_arp_idle_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x3c); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_bsn_arp_idle of_bsn_arp_idle
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_arp_idle_push_wire_values(of_bsn_arp_idle_t *obj)
{

    of_bsn_arp_idle_push_wire_types(obj);

    /* Message obj; set length */
    of_message_t msg;

    if ((msg = OF_OBJECT_TO_MESSAGE(obj)) != NULL) {
        of_message_length_set(msg, obj->length);
    }

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_arp_idle object
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
 * \ingroup of_bsn_arp_idle
 */

of_bsn_arp_idle_t *
of_bsn_arp_idle_new(of_version_t version)
{
    of_bsn_arp_idle_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_ARP_IDLE] + of_object_extra_len[version][OF_BSN_ARP_IDLE];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_arp_idle_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_arp_idle_init(obj, version, bytes, 0);

    if (of_bsn_arp_idle_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_arp_idle.
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
of_bsn_arp_idle_init(of_bsn_arp_idle_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_ARP_IDLE] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_ARP_IDLE] + of_object_extra_len[version][OF_BSN_ARP_IDLE];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_ARP_IDLE;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_bsn_arp_idle_push_wire_types;

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
 * Create a new of_bsn_arp_idle object and bind it to an existing message
 *
 * @param msg The message to bind the new object to
 * @return Pointer to the newly create object or NULL on error
 *
 * \ingroup of_bsn_arp_idle
 */

of_bsn_arp_idle_t *
of_bsn_arp_idle_new_from_message(of_message_t msg)
{
    of_bsn_arp_idle_t *obj = NULL;
    of_version_t version;
    int length;

    if (msg == NULL) return NULL;

    version = of_message_version_get(msg);
    if (!OF_VERSION_OKAY(version)) return NULL;

    length = of_message_length_get(msg);

    if ((obj = (of_bsn_arp_idle_t *)of_object_new(-1)) == NULL) {
        return NULL;
    }

    of_bsn_arp_idle_init(obj, version, 0, 0);

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
 * Get xid from an object of type of_bsn_arp_idle.
 * @param obj Pointer to an object of type of_bsn_arp_idle.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_arp_idle_xid_get(
    of_bsn_arp_idle_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_ARP_IDLE);
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
 * Set xid in an object of type of_bsn_arp_idle.
 * @param obj Pointer to an object of type of_bsn_arp_idle.
 * @param xid The value to write into the object
 */
void
of_bsn_arp_idle_xid_set(
    of_bsn_arp_idle_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_ARP_IDLE);
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
 * Get experimenter from an object of type of_bsn_arp_idle.
 * @param obj Pointer to an object of type of_bsn_arp_idle.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_arp_idle_experimenter_get(
    of_bsn_arp_idle_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_ARP_IDLE);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_bsn_arp_idle.
 * @param obj Pointer to an object of type of_bsn_arp_idle.
 * @param experimenter The value to write into the object
 */
void
of_bsn_arp_idle_experimenter_set(
    of_bsn_arp_idle_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_ARP_IDLE);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_bsn_arp_idle.
 * @param obj Pointer to an object of type of_bsn_arp_idle.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_arp_idle_subtype_get(
    of_bsn_arp_idle_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_ARP_IDLE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
 * Set subtype in an object of type of_bsn_arp_idle.
 * @param obj Pointer to an object of type of_bsn_arp_idle.
 * @param subtype The value to write into the object
 */
void
of_bsn_arp_idle_subtype_set(
    of_bsn_arp_idle_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_ARP_IDLE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
 * Get vlan_vid from an object of type of_bsn_arp_idle.
 * @param obj Pointer to an object of type of_bsn_arp_idle.
 * @param vlan_vid Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_arp_idle_vlan_vid_get(
    of_bsn_arp_idle_t *obj,
    uint16_t *vlan_vid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_ARP_IDLE);
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
    of_wire_buffer_u16_get(wbuf, abs_offset, vlan_vid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set vlan_vid in an object of type of_bsn_arp_idle.
 * @param obj Pointer to an object of type of_bsn_arp_idle.
 * @param vlan_vid The value to write into the object
 */
void
of_bsn_arp_idle_vlan_vid_set(
    of_bsn_arp_idle_t *obj,
    uint16_t vlan_vid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_ARP_IDLE);
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
    of_wire_buffer_u16_set(wbuf, abs_offset, vlan_vid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get ipv4_addr from an object of type of_bsn_arp_idle.
 * @param obj Pointer to an object of type of_bsn_arp_idle.
 * @param ipv4_addr Pointer to the child object of type
 * of_ipv4_t to be filled out.
 *
 */
void
of_bsn_arp_idle_ipv4_addr_get(
    of_bsn_arp_idle_t *obj,
    of_ipv4_t *ipv4_addr)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_ARP_IDLE);
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
    of_wire_buffer_ipv4_get(wbuf, abs_offset, ipv4_addr);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set ipv4_addr in an object of type of_bsn_arp_idle.
 * @param obj Pointer to an object of type of_bsn_arp_idle.
 * @param ipv4_addr The value to write into the object
 */
void
of_bsn_arp_idle_ipv4_addr_set(
    of_bsn_arp_idle_t *obj,
    of_ipv4_t ipv4_addr)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_ARP_IDLE);
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
    of_wire_buffer_ipv4_set(wbuf, abs_offset, ipv4_addr);

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
 * \defgroup of_bsn_controller_connection of_bsn_controller_connection
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_controller_connection_push_wire_values(of_bsn_controller_connection_t *obj)
{

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_controller_connection object
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
 * \ingroup of_bsn_controller_connection
 */

of_bsn_controller_connection_t *
of_bsn_controller_connection_new(of_version_t version)
{
    of_bsn_controller_connection_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_CONTROLLER_CONNECTION] + of_object_extra_len[version][OF_BSN_CONTROLLER_CONNECTION];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_controller_connection_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_controller_connection_init(obj, version, bytes, 0);

    if (of_bsn_controller_connection_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_controller_connection.
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
of_bsn_controller_connection_init(of_bsn_controller_connection_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_CONTROLLER_CONNECTION] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_CONTROLLER_CONNECTION] + of_object_extra_len[version][OF_BSN_CONTROLLER_CONNECTION];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_CONTROLLER_CONNECTION;

    /* Set up the object's function pointers */

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get state from an object of type of_bsn_controller_connection.
 * @param obj Pointer to an object of type of_bsn_controller_connection.
 * @param state Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_bsn_controller_connection_state_get(
    of_bsn_controller_connection_t *obj,
    uint8_t *state)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_CONTROLLER_CONNECTION);
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
    of_wire_buffer_u8_get(wbuf, abs_offset, state);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set state in an object of type of_bsn_controller_connection.
 * @param obj Pointer to an object of type of_bsn_controller_connection.
 * @param state The value to write into the object
 */
void
of_bsn_controller_connection_state_set(
    of_bsn_controller_connection_t *obj,
    uint8_t state)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_CONTROLLER_CONNECTION);
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
    of_wire_buffer_u8_set(wbuf, abs_offset, state);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get auxiliary_id from an object of type of_bsn_controller_connection.
 * @param obj Pointer to an object of type of_bsn_controller_connection.
 * @param auxiliary_id Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_bsn_controller_connection_auxiliary_id_get(
    of_bsn_controller_connection_t *obj,
    uint8_t *auxiliary_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_CONTROLLER_CONNECTION);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 1;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, auxiliary_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set auxiliary_id in an object of type of_bsn_controller_connection.
 * @param obj Pointer to an object of type of_bsn_controller_connection.
 * @param auxiliary_id The value to write into the object
 */
void
of_bsn_controller_connection_auxiliary_id_set(
    of_bsn_controller_connection_t *obj,
    uint8_t auxiliary_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_CONTROLLER_CONNECTION);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 1;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, auxiliary_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get role from an object of type of_bsn_controller_connection.
 * @param obj Pointer to an object of type of_bsn_controller_connection.
 * @param role Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_controller_connection_role_get(
    of_bsn_controller_connection_t *obj,
    uint32_t *role)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_CONTROLLER_CONNECTION);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, role);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set role in an object of type of_bsn_controller_connection.
 * @param obj Pointer to an object of type of_bsn_controller_connection.
 * @param role The value to write into the object
 */
void
of_bsn_controller_connection_role_set(
    of_bsn_controller_connection_t *obj,
    uint32_t role)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_CONTROLLER_CONNECTION);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, role);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get uri from an object of type of_bsn_controller_connection.
 * @param obj Pointer to an object of type of_bsn_controller_connection.
 * @param uri Pointer to the child object of type
 * of_desc_str_t to be filled out.
 *
 */
void
of_bsn_controller_connection_uri_get(
    of_bsn_controller_connection_t *obj,
    of_desc_str_t *uri)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_CONTROLLER_CONNECTION);
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
    of_wire_buffer_desc_str_get(wbuf, abs_offset, uri);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set uri in an object of type of_bsn_controller_connection.
 * @param obj Pointer to an object of type of_bsn_controller_connection.
 * @param uri The value to write into the object
 */
void
of_bsn_controller_connection_uri_set(
    of_bsn_controller_connection_t *obj,
    of_desc_str_t uri)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_CONTROLLER_CONNECTION);
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
    of_wire_buffer_desc_str_set(wbuf, abs_offset, uri);

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
of_bsn_controller_connections_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x39); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_bsn_controller_connections_reply of_bsn_controller_connections_reply
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_controller_connections_reply_push_wire_values(of_bsn_controller_connections_reply_t *obj)
{

    of_bsn_controller_connections_reply_push_wire_types(obj);

    /* Message obj; set length */
    of_message_t msg;

    if ((msg = OF_OBJECT_TO_MESSAGE(obj)) != NULL) {
        of_message_length_set(msg, obj->length);
    }

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_controller_connections_reply object
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
 * \ingroup of_bsn_controller_connections_reply
 */

of_bsn_controller_connections_reply_t *
of_bsn_controller_connections_reply_new(of_version_t version)
{
    of_bsn_controller_connections_reply_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_CONTROLLER_CONNECTIONS_REPLY] + of_object_extra_len[version][OF_BSN_CONTROLLER_CONNECTIONS_REPLY];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_controller_connections_reply_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_controller_connections_reply_init(obj, version, bytes, 0);

    if (of_bsn_controller_connections_reply_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_controller_connections_reply.
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
of_bsn_controller_connections_reply_init(of_bsn_controller_connections_reply_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_CONTROLLER_CONNECTIONS_REPLY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_CONTROLLER_CONNECTIONS_REPLY] + of_object_extra_len[version][OF_BSN_CONTROLLER_CONNECTIONS_REPLY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_CONTROLLER_CONNECTIONS_REPLY;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_bsn_controller_connections_reply_push_wire_types;

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
 * Create a new of_bsn_controller_connections_reply object and bind it to an existing message
 *
 * @param msg The message to bind the new object to
 * @return Pointer to the newly create object or NULL on error
 *
 * \ingroup of_bsn_controller_connections_reply
 */

of_bsn_controller_connections_reply_t *
of_bsn_controller_connections_reply_new_from_message(of_message_t msg)
{
    of_bsn_controller_connections_reply_t *obj = NULL;
    of_version_t version;
    int length;

    if (msg == NULL) return NULL;

    version = of_message_version_get(msg);
    if (!OF_VERSION_OKAY(version)) return NULL;

    length = of_message_length_get(msg);

    if ((obj = (of_bsn_controller_connections_reply_t *)of_object_new(-1)) == NULL) {
        return NULL;
    }

    of_bsn_controller_connections_reply_init(obj, version, 0, 0);

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
 * Get xid from an object of type of_bsn_controller_connections_reply.
 * @param obj Pointer to an object of type of_bsn_controller_connections_reply.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_controller_connections_reply_xid_get(
    of_bsn_controller_connections_reply_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_CONTROLLER_CONNECTIONS_REPLY);
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
 * Set xid in an object of type of_bsn_controller_connections_reply.
 * @param obj Pointer to an object of type of_bsn_controller_connections_reply.
 * @param xid The value to write into the object
 */
void
of_bsn_controller_connections_reply_xid_set(
    of_bsn_controller_connections_reply_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_CONTROLLER_CONNECTIONS_REPLY);
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
 * Get experimenter from an object of type of_bsn_controller_connections_reply.
 * @param obj Pointer to an object of type of_bsn_controller_connections_reply.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_controller_connections_reply_experimenter_get(
    of_bsn_controller_connections_reply_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_CONTROLLER_CONNECTIONS_REPLY);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_bsn_controller_connections_reply.
 * @param obj Pointer to an object of type of_bsn_controller_connections_reply.
 * @param experimenter The value to write into the object
 */
void
of_bsn_controller_connections_reply_experimenter_set(
    of_bsn_controller_connections_reply_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_CONTROLLER_CONNECTIONS_REPLY);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_bsn_controller_connections_reply.
 * @param obj Pointer to an object of type of_bsn_controller_connections_reply.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_controller_connections_reply_subtype_get(
    of_bsn_controller_connections_reply_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_CONTROLLER_CONNECTIONS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
 * Set subtype in an object of type of_bsn_controller_connections_reply.
 * @param obj Pointer to an object of type of_bsn_controller_connections_reply.
 * @param subtype The value to write into the object
 */
void
of_bsn_controller_connections_reply_subtype_set(
    of_bsn_controller_connections_reply_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_CONTROLLER_CONNECTIONS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
 * Bind an object of type of_list_bsn_controller_connection_t to the parent of type of_bsn_controller_connections_reply for
 * member connections
 * @param obj Pointer to an object of type of_bsn_controller_connections_reply.
 * @param connections Pointer to the child object of type
 * of_list_bsn_controller_connection_t to be filled out.
 * \ingroup of_bsn_controller_connections_reply
 *
 * The parameter connections is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_bsn_controller_connections_reply_connections_bind(
    of_bsn_controller_connections_reply_t *obj,
    of_list_bsn_controller_connection_t *connections)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_BSN_CONTROLLER_CONNECTIONS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
    of_list_bsn_controller_connection_init(connections, obj->version, 0, 1);
    /* Attach to parent */
    connections->parent = (of_object_t *)obj;
    connections->wire_object.wbuf = obj->wire_object.wbuf;
    connections->wire_object.obj_offset = abs_offset;
    connections->wire_object.owned = 0;
    connections->length = cur_len;

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of connections into a new variable of type of_list_bsn_controller_connection_t from
 * a of_bsn_controller_connections_reply instance.
 *
 * @param obj Pointer to the source of type of_bsn_controller_connections_reply_t
 * @returns A pointer to a new instance of type of_list_bsn_controller_connection_t whose contents
 * match that of connections from source
 * @returns NULL if an error occurs
 */
of_list_bsn_controller_connection_t *
of_bsn_controller_connections_reply_connections_get(of_bsn_controller_connections_reply_t *obj) {
    of_list_bsn_controller_connection_t _connections;
    of_list_bsn_controller_connection_t *_connections_ptr;

    of_bsn_controller_connections_reply_connections_bind(obj, &_connections);
    _connections_ptr = (of_list_bsn_controller_connection_t *)of_object_dup(&_connections);
    return _connections_ptr;
}

/**
 * Set connections in an object of type of_bsn_controller_connections_reply.
 * @param obj Pointer to an object of type of_bsn_controller_connections_reply.
 * @param connections Pointer to the child of type of_list_bsn_controller_connection_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_bsn_controller_connections_reply_connections_set(
    of_bsn_controller_connections_reply_t *obj,
    of_list_bsn_controller_connection_t *connections)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_BSN_CONTROLLER_CONNECTIONS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
    new_len = connections->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wire_object.wbuf == connections->wire_object.wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(connections, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(connections, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    if (connections->wire_length_set != NULL) {
        connections->wire_length_set((of_object_t *)connections, connections->length);
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
