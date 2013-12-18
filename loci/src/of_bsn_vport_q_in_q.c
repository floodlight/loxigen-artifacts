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
of_bsn_vport_q_in_q_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x0); /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_bsn_vport_q_in_q of_bsn_vport_q_in_q
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_vport_q_in_q_push_wire_values(of_bsn_vport_q_in_q_t *obj)
{

    of_bsn_vport_q_in_q_push_wire_types(obj);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_vport_q_in_q object
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
 * \ingroup of_bsn_vport_q_in_q
 */

of_bsn_vport_q_in_q_t *
of_bsn_vport_q_in_q_new(of_version_t version)
{
    of_bsn_vport_q_in_q_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_VPORT_Q_IN_Q] + of_object_extra_len[version][OF_BSN_VPORT_Q_IN_Q];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_vport_q_in_q_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_vport_q_in_q_init(obj, version, bytes, 0);

    if (of_bsn_vport_q_in_q_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_vport_q_in_q.
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
of_bsn_vport_q_in_q_init(of_bsn_vport_q_in_q_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    ASSERT(of_object_fixed_len[version][OF_BSN_VPORT_Q_IN_Q] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_VPORT_Q_IN_Q] + of_object_extra_len[version][OF_BSN_VPORT_Q_IN_Q];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_VPORT_Q_IN_Q;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_bsn_vport_q_in_q_push_wire_types;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get port_no from an object of type of_bsn_vport_q_in_q.
 * @param obj Pointer to an object of type of_bsn_vport_q_in_q.
 * @param port_no Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_vport_q_in_q_port_no_get(
    of_bsn_vport_q_in_q_t *obj,
    uint32_t *port_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_VPORT_Q_IN_Q);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, port_no);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set port_no in an object of type of_bsn_vport_q_in_q.
 * @param obj Pointer to an object of type of_bsn_vport_q_in_q.
 * @param port_no The value to write into the object
 */
void
of_bsn_vport_q_in_q_port_no_set(
    of_bsn_vport_q_in_q_t *obj,
    uint32_t port_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_VPORT_Q_IN_Q);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, port_no);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get ingress_tpid from an object of type of_bsn_vport_q_in_q.
 * @param obj Pointer to an object of type of_bsn_vport_q_in_q.
 * @param ingress_tpid Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_vport_q_in_q_ingress_tpid_get(
    of_bsn_vport_q_in_q_t *obj,
    uint16_t *ingress_tpid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_VPORT_Q_IN_Q);
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
    of_wire_buffer_u16_get(wbuf, abs_offset, ingress_tpid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set ingress_tpid in an object of type of_bsn_vport_q_in_q.
 * @param obj Pointer to an object of type of_bsn_vport_q_in_q.
 * @param ingress_tpid The value to write into the object
 */
void
of_bsn_vport_q_in_q_ingress_tpid_set(
    of_bsn_vport_q_in_q_t *obj,
    uint16_t ingress_tpid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_VPORT_Q_IN_Q);
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
    of_wire_buffer_u16_set(wbuf, abs_offset, ingress_tpid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get ingress_vlan_id from an object of type of_bsn_vport_q_in_q.
 * @param obj Pointer to an object of type of_bsn_vport_q_in_q.
 * @param ingress_vlan_id Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_vport_q_in_q_ingress_vlan_id_get(
    of_bsn_vport_q_in_q_t *obj,
    uint16_t *ingress_vlan_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_VPORT_Q_IN_Q);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 10;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, ingress_vlan_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set ingress_vlan_id in an object of type of_bsn_vport_q_in_q.
 * @param obj Pointer to an object of type of_bsn_vport_q_in_q.
 * @param ingress_vlan_id The value to write into the object
 */
void
of_bsn_vport_q_in_q_ingress_vlan_id_set(
    of_bsn_vport_q_in_q_t *obj,
    uint16_t ingress_vlan_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_VPORT_Q_IN_Q);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 10;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, ingress_vlan_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get egress_tpid from an object of type of_bsn_vport_q_in_q.
 * @param obj Pointer to an object of type of_bsn_vport_q_in_q.
 * @param egress_tpid Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_vport_q_in_q_egress_tpid_get(
    of_bsn_vport_q_in_q_t *obj,
    uint16_t *egress_tpid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_VPORT_Q_IN_Q);
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
    of_wire_buffer_u16_get(wbuf, abs_offset, egress_tpid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set egress_tpid in an object of type of_bsn_vport_q_in_q.
 * @param obj Pointer to an object of type of_bsn_vport_q_in_q.
 * @param egress_tpid The value to write into the object
 */
void
of_bsn_vport_q_in_q_egress_tpid_set(
    of_bsn_vport_q_in_q_t *obj,
    uint16_t egress_tpid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_VPORT_Q_IN_Q);
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
    of_wire_buffer_u16_set(wbuf, abs_offset, egress_tpid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get egress_vlan_id from an object of type of_bsn_vport_q_in_q.
 * @param obj Pointer to an object of type of_bsn_vport_q_in_q.
 * @param egress_vlan_id Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_vport_q_in_q_egress_vlan_id_get(
    of_bsn_vport_q_in_q_t *obj,
    uint16_t *egress_vlan_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_VPORT_Q_IN_Q);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 14;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, egress_vlan_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set egress_vlan_id in an object of type of_bsn_vport_q_in_q.
 * @param obj Pointer to an object of type of_bsn_vport_q_in_q.
 * @param egress_vlan_id The value to write into the object
 */
void
of_bsn_vport_q_in_q_egress_vlan_id_set(
    of_bsn_vport_q_in_q_t *obj,
    uint16_t egress_vlan_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_VPORT_Q_IN_Q);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        offset = 14;
        break;
    default:
        ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, egress_vlan_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get if_name from an object of type of_bsn_vport_q_in_q.
 * @param obj Pointer to an object of type of_bsn_vport_q_in_q.
 * @param if_name Pointer to the child object of type
 * of_port_name_t to be filled out.
 *
 */
void
of_bsn_vport_q_in_q_if_name_get(
    of_bsn_vport_q_in_q_t *obj,
    of_port_name_t *if_name)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_VPORT_Q_IN_Q);
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
    of_wire_buffer_port_name_get(wbuf, abs_offset, if_name);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set if_name in an object of type of_bsn_vport_q_in_q.
 * @param obj Pointer to an object of type of_bsn_vport_q_in_q.
 * @param if_name The value to write into the object
 */
void
of_bsn_vport_q_in_q_if_name_set(
    of_bsn_vport_q_in_q_t *obj,
    of_port_name_t if_name)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    ASSERT(obj->object_id == OF_BSN_VPORT_Q_IN_Q);
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
    of_wire_buffer_port_name_set(wbuf, abs_offset, if_name);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
