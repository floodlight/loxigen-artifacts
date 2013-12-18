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
of_bsn_lacp_convergence_notif_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x2b); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_bsn_lacp_convergence_notif of_bsn_lacp_convergence_notif
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_lacp_convergence_notif_push_wire_values(of_bsn_lacp_convergence_notif_t *obj)
{

    of_bsn_lacp_convergence_notif_push_wire_types(obj);

    /* Message obj; set length */
    of_message_t msg;

    if ((msg = OF_OBJECT_TO_MESSAGE(obj)) != NULL) {
        of_message_length_set(msg, obj->length);
    }

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_lacp_convergence_notif object
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
 * \ingroup of_bsn_lacp_convergence_notif
 */

of_bsn_lacp_convergence_notif_t *
of_bsn_lacp_convergence_notif_new(of_version_t version)
{
    of_bsn_lacp_convergence_notif_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_LACP_CONVERGENCE_NOTIF] + of_object_extra_len[version][OF_BSN_LACP_CONVERGENCE_NOTIF];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_lacp_convergence_notif_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_lacp_convergence_notif_init(obj, version, bytes, 0);

    if (of_bsn_lacp_convergence_notif_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_lacp_convergence_notif.
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
of_bsn_lacp_convergence_notif_init(of_bsn_lacp_convergence_notif_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    ASSERT(of_object_fixed_len[version][OF_BSN_LACP_CONVERGENCE_NOTIF] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_LACP_CONVERGENCE_NOTIF] + of_object_extra_len[version][OF_BSN_LACP_CONVERGENCE_NOTIF];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_LACP_CONVERGENCE_NOTIF;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_bsn_lacp_convergence_notif_push_wire_types;

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
 * Create a new of_bsn_lacp_convergence_notif object and bind it to an existing message
 *
 * @param msg The message to bind the new object to
 * @return Pointer to the newly create object or NULL on error
 *
 * \ingroup of_bsn_lacp_convergence_notif
 */

of_bsn_lacp_convergence_notif_t *
of_bsn_lacp_convergence_notif_new_from_message(of_message_t msg)
{
    of_bsn_lacp_convergence_notif_t *obj = NULL;
    of_version_t version;
    int length;

    if (msg == NULL) return NULL;

    version = of_message_version_get(msg);
    if (!OF_VERSION_OKAY(version)) return NULL;

    length = of_message_length_get(msg);

    if ((obj = (of_bsn_lacp_convergence_notif_t *)of_object_new(-1)) == NULL) {
        return NULL;
    }

    of_bsn_lacp_convergence_notif_init(obj, version, 0, 0);

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
 * Get xid from an object of type of_bsn_lacp_convergence_notif.
 * @param obj Pointer to an object of type of_bsn_lacp_convergence_notif.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_lacp_convergence_notif_xid_get(
    of_bsn_lacp_convergence_notif_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_LACP_CONVERGENCE_NOTIF);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_bsn_lacp_convergence_notif.
 * @param obj Pointer to an object of type of_bsn_lacp_convergence_notif.
 * @param xid The value to write into the object
 */
void
of_bsn_lacp_convergence_notif_xid_set(
    of_bsn_lacp_convergence_notif_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_LACP_CONVERGENCE_NOTIF);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_bsn_lacp_convergence_notif.
 * @param obj Pointer to an object of type of_bsn_lacp_convergence_notif.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_lacp_convergence_notif_experimenter_get(
    of_bsn_lacp_convergence_notif_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_LACP_CONVERGENCE_NOTIF);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
 * Set experimenter in an object of type of_bsn_lacp_convergence_notif.
 * @param obj Pointer to an object of type of_bsn_lacp_convergence_notif.
 * @param experimenter The value to write into the object
 */
void
of_bsn_lacp_convergence_notif_experimenter_set(
    of_bsn_lacp_convergence_notif_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_LACP_CONVERGENCE_NOTIF);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
 * Get subtype from an object of type of_bsn_lacp_convergence_notif.
 * @param obj Pointer to an object of type of_bsn_lacp_convergence_notif.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_lacp_convergence_notif_subtype_get(
    of_bsn_lacp_convergence_notif_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_LACP_CONVERGENCE_NOTIF);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
 * Set subtype in an object of type of_bsn_lacp_convergence_notif.
 * @param obj Pointer to an object of type of_bsn_lacp_convergence_notif.
 * @param subtype The value to write into the object
 */
void
of_bsn_lacp_convergence_notif_subtype_set(
    of_bsn_lacp_convergence_notif_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_LACP_CONVERGENCE_NOTIF);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
 * Get convergence_status from an object of type of_bsn_lacp_convergence_notif.
 * @param obj Pointer to an object of type of_bsn_lacp_convergence_notif.
 * @param convergence_status Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_bsn_lacp_convergence_notif_convergence_status_get(
    of_bsn_lacp_convergence_notif_t *obj,
    uint8_t *convergence_status)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_LACP_CONVERGENCE_NOTIF);
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
    of_wire_buffer_u8_get(wbuf, abs_offset, convergence_status);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set convergence_status in an object of type of_bsn_lacp_convergence_notif.
 * @param obj Pointer to an object of type of_bsn_lacp_convergence_notif.
 * @param convergence_status The value to write into the object
 */
void
of_bsn_lacp_convergence_notif_convergence_status_set(
    of_bsn_lacp_convergence_notif_t *obj,
    uint8_t convergence_status)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_LACP_CONVERGENCE_NOTIF);
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
    of_wire_buffer_u8_set(wbuf, abs_offset, convergence_status);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get port_no from an object of type of_bsn_lacp_convergence_notif.
 * @param obj Pointer to an object of type of_bsn_lacp_convergence_notif.
 * @param port_no Pointer to the child object of type
 * of_port_no_t to be filled out.
 *
 */
void
of_bsn_lacp_convergence_notif_port_no_get(
    of_bsn_lacp_convergence_notif_t *obj,
    of_port_no_t *port_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_LACP_CONVERGENCE_NOTIF);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
 * Set port_no in an object of type of_bsn_lacp_convergence_notif.
 * @param obj Pointer to an object of type of_bsn_lacp_convergence_notif.
 * @param port_no The value to write into the object
 */
void
of_bsn_lacp_convergence_notif_port_no_set(
    of_bsn_lacp_convergence_notif_t *obj,
    of_port_no_t port_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_LACP_CONVERGENCE_NOTIF);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
 * Get actor_sys_priority from an object of type of_bsn_lacp_convergence_notif.
 * @param obj Pointer to an object of type of_bsn_lacp_convergence_notif.
 * @param actor_sys_priority Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_lacp_convergence_notif_actor_sys_priority_get(
    of_bsn_lacp_convergence_notif_t *obj,
    uint16_t *actor_sys_priority)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_LACP_CONVERGENCE_NOTIF);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, actor_sys_priority);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set actor_sys_priority in an object of type of_bsn_lacp_convergence_notif.
 * @param obj Pointer to an object of type of_bsn_lacp_convergence_notif.
 * @param actor_sys_priority The value to write into the object
 */
void
of_bsn_lacp_convergence_notif_actor_sys_priority_set(
    of_bsn_lacp_convergence_notif_t *obj,
    uint16_t actor_sys_priority)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_LACP_CONVERGENCE_NOTIF);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, actor_sys_priority);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get actor_sys_mac from an object of type of_bsn_lacp_convergence_notif.
 * @param obj Pointer to an object of type of_bsn_lacp_convergence_notif.
 * @param actor_sys_mac Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_bsn_lacp_convergence_notif_actor_sys_mac_get(
    of_bsn_lacp_convergence_notif_t *obj,
    of_mac_addr_t *actor_sys_mac)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_LACP_CONVERGENCE_NOTIF);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 26;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_get(wbuf, abs_offset, actor_sys_mac);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set actor_sys_mac in an object of type of_bsn_lacp_convergence_notif.
 * @param obj Pointer to an object of type of_bsn_lacp_convergence_notif.
 * @param actor_sys_mac The value to write into the object
 */
void
of_bsn_lacp_convergence_notif_actor_sys_mac_set(
    of_bsn_lacp_convergence_notif_t *obj,
    of_mac_addr_t actor_sys_mac)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_LACP_CONVERGENCE_NOTIF);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 26;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_set(wbuf, abs_offset, actor_sys_mac);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get actor_port_priority from an object of type of_bsn_lacp_convergence_notif.
 * @param obj Pointer to an object of type of_bsn_lacp_convergence_notif.
 * @param actor_port_priority Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_lacp_convergence_notif_actor_port_priority_get(
    of_bsn_lacp_convergence_notif_t *obj,
    uint16_t *actor_port_priority)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_LACP_CONVERGENCE_NOTIF);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 32;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, actor_port_priority);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set actor_port_priority in an object of type of_bsn_lacp_convergence_notif.
 * @param obj Pointer to an object of type of_bsn_lacp_convergence_notif.
 * @param actor_port_priority The value to write into the object
 */
void
of_bsn_lacp_convergence_notif_actor_port_priority_set(
    of_bsn_lacp_convergence_notif_t *obj,
    uint16_t actor_port_priority)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_LACP_CONVERGENCE_NOTIF);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 32;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, actor_port_priority);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get actor_port_num from an object of type of_bsn_lacp_convergence_notif.
 * @param obj Pointer to an object of type of_bsn_lacp_convergence_notif.
 * @param actor_port_num Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_lacp_convergence_notif_actor_port_num_get(
    of_bsn_lacp_convergence_notif_t *obj,
    uint16_t *actor_port_num)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_LACP_CONVERGENCE_NOTIF);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 34;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, actor_port_num);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set actor_port_num in an object of type of_bsn_lacp_convergence_notif.
 * @param obj Pointer to an object of type of_bsn_lacp_convergence_notif.
 * @param actor_port_num The value to write into the object
 */
void
of_bsn_lacp_convergence_notif_actor_port_num_set(
    of_bsn_lacp_convergence_notif_t *obj,
    uint16_t actor_port_num)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_LACP_CONVERGENCE_NOTIF);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 34;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, actor_port_num);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get actor_key from an object of type of_bsn_lacp_convergence_notif.
 * @param obj Pointer to an object of type of_bsn_lacp_convergence_notif.
 * @param actor_key Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_lacp_convergence_notif_actor_key_get(
    of_bsn_lacp_convergence_notif_t *obj,
    uint16_t *actor_key)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_LACP_CONVERGENCE_NOTIF);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 36;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, actor_key);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set actor_key in an object of type of_bsn_lacp_convergence_notif.
 * @param obj Pointer to an object of type of_bsn_lacp_convergence_notif.
 * @param actor_key The value to write into the object
 */
void
of_bsn_lacp_convergence_notif_actor_key_set(
    of_bsn_lacp_convergence_notif_t *obj,
    uint16_t actor_key)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_LACP_CONVERGENCE_NOTIF);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 36;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, actor_key);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get partner_sys_priority from an object of type of_bsn_lacp_convergence_notif.
 * @param obj Pointer to an object of type of_bsn_lacp_convergence_notif.
 * @param partner_sys_priority Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_lacp_convergence_notif_partner_sys_priority_get(
    of_bsn_lacp_convergence_notif_t *obj,
    uint16_t *partner_sys_priority)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_LACP_CONVERGENCE_NOTIF);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 38;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, partner_sys_priority);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set partner_sys_priority in an object of type of_bsn_lacp_convergence_notif.
 * @param obj Pointer to an object of type of_bsn_lacp_convergence_notif.
 * @param partner_sys_priority The value to write into the object
 */
void
of_bsn_lacp_convergence_notif_partner_sys_priority_set(
    of_bsn_lacp_convergence_notif_t *obj,
    uint16_t partner_sys_priority)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_LACP_CONVERGENCE_NOTIF);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 38;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, partner_sys_priority);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get partner_sys_mac from an object of type of_bsn_lacp_convergence_notif.
 * @param obj Pointer to an object of type of_bsn_lacp_convergence_notif.
 * @param partner_sys_mac Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_bsn_lacp_convergence_notif_partner_sys_mac_get(
    of_bsn_lacp_convergence_notif_t *obj,
    of_mac_addr_t *partner_sys_mac)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_LACP_CONVERGENCE_NOTIF);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 40;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_get(wbuf, abs_offset, partner_sys_mac);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set partner_sys_mac in an object of type of_bsn_lacp_convergence_notif.
 * @param obj Pointer to an object of type of_bsn_lacp_convergence_notif.
 * @param partner_sys_mac The value to write into the object
 */
void
of_bsn_lacp_convergence_notif_partner_sys_mac_set(
    of_bsn_lacp_convergence_notif_t *obj,
    of_mac_addr_t partner_sys_mac)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_LACP_CONVERGENCE_NOTIF);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 40;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_set(wbuf, abs_offset, partner_sys_mac);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get partner_port_priority from an object of type of_bsn_lacp_convergence_notif.
 * @param obj Pointer to an object of type of_bsn_lacp_convergence_notif.
 * @param partner_port_priority Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_lacp_convergence_notif_partner_port_priority_get(
    of_bsn_lacp_convergence_notif_t *obj,
    uint16_t *partner_port_priority)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_LACP_CONVERGENCE_NOTIF);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 46;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, partner_port_priority);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set partner_port_priority in an object of type of_bsn_lacp_convergence_notif.
 * @param obj Pointer to an object of type of_bsn_lacp_convergence_notif.
 * @param partner_port_priority The value to write into the object
 */
void
of_bsn_lacp_convergence_notif_partner_port_priority_set(
    of_bsn_lacp_convergence_notif_t *obj,
    uint16_t partner_port_priority)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_LACP_CONVERGENCE_NOTIF);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 46;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, partner_port_priority);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get partner_port_num from an object of type of_bsn_lacp_convergence_notif.
 * @param obj Pointer to an object of type of_bsn_lacp_convergence_notif.
 * @param partner_port_num Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_lacp_convergence_notif_partner_port_num_get(
    of_bsn_lacp_convergence_notif_t *obj,
    uint16_t *partner_port_num)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_LACP_CONVERGENCE_NOTIF);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 48;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, partner_port_num);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set partner_port_num in an object of type of_bsn_lacp_convergence_notif.
 * @param obj Pointer to an object of type of_bsn_lacp_convergence_notif.
 * @param partner_port_num The value to write into the object
 */
void
of_bsn_lacp_convergence_notif_partner_port_num_set(
    of_bsn_lacp_convergence_notif_t *obj,
    uint16_t partner_port_num)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_LACP_CONVERGENCE_NOTIF);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 48;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, partner_port_num);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get partner_key from an object of type of_bsn_lacp_convergence_notif.
 * @param obj Pointer to an object of type of_bsn_lacp_convergence_notif.
 * @param partner_key Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_lacp_convergence_notif_partner_key_get(
    of_bsn_lacp_convergence_notif_t *obj,
    uint16_t *partner_key)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_LACP_CONVERGENCE_NOTIF);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 50;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, partner_key);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set partner_key in an object of type of_bsn_lacp_convergence_notif.
 * @param obj Pointer to an object of type of_bsn_lacp_convergence_notif.
 * @param partner_key The value to write into the object
 */
void
of_bsn_lacp_convergence_notif_partner_key_set(
    of_bsn_lacp_convergence_notif_t *obj,
    uint16_t partner_key)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_LACP_CONVERGENCE_NOTIF);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 50;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, partner_key);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
