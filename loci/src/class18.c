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
of_bsn_tlv_pim_hello_flood_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xb5); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_pim_hello_flood of_bsn_tlv_pim_hello_flood
 */

/**
 * Create a new of_bsn_tlv_pim_hello_flood object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_pim_hello_flood
 */

of_object_t *
of_bsn_tlv_pim_hello_flood_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_PIM_HELLO_FLOOD];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_pim_hello_flood_init(obj, version, bytes, 0);
    of_bsn_tlv_pim_hello_flood_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_pim_hello_flood.
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
of_bsn_tlv_pim_hello_flood_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_PIM_HELLO_FLOOD] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_PIM_HELLO_FLOOD];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_PIM_HELLO_FLOOD;

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
of_bsn_tlv_port_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0x0); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_port of_bsn_tlv_port
 */

/**
 * Create a new of_bsn_tlv_port object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_port
 */

of_object_t *
of_bsn_tlv_port_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_PORT];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_port_init(obj, version, bytes, 0);
    of_bsn_tlv_port_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_port.
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
of_bsn_tlv_port_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_PORT] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_PORT];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_PORT;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_bsn_tlv_port.
 * @param obj Pointer to an object of type of_bsn_tlv_port.
 * @param value Pointer to the child object of type
 * of_port_no_t to be filled out.
 *
 */
void
of_bsn_tlv_port_value_get(
    of_bsn_tlv_port_t *obj,
    of_port_no_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_PORT);
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
    of_wire_buffer_port_no_get(ver, wbuf, abs_offset, value);
    OF_PORT_NO_VALUE_CHECK(*value, ver);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_bsn_tlv_port.
 * @param obj Pointer to an object of type of_bsn_tlv_port.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_port_value_set(
    of_bsn_tlv_port_t *obj,
    of_port_no_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_PORT);
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
    of_wire_buffer_port_no_set(ver, wbuf, abs_offset, value);

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
of_bsn_tlv_port_mode_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xb3); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_port_mode of_bsn_tlv_port_mode
 */

/**
 * Create a new of_bsn_tlv_port_mode object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_port_mode
 */

of_object_t *
of_bsn_tlv_port_mode_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_PORT_MODE];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_port_mode_init(obj, version, bytes, 0);
    of_bsn_tlv_port_mode_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_port_mode.
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
of_bsn_tlv_port_mode_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_PORT_MODE] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_PORT_MODE];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_PORT_MODE;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_bsn_tlv_port_mode.
 * @param obj Pointer to an object of type of_bsn_tlv_port_mode.
 * @param value Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_tlv_port_mode_value_get(
    of_bsn_tlv_port_mode_t *obj,
    uint16_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_PORT_MODE);
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
 * Set value in an object of type of_bsn_tlv_port_mode.
 * @param obj Pointer to an object of type of_bsn_tlv_port_mode.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_port_mode_value_set(
    of_bsn_tlv_port_mode_t *obj,
    uint16_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_PORT_MODE);
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
of_bsn_tlv_port_speed_gbps_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0x9c); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_port_speed_gbps of_bsn_tlv_port_speed_gbps
 */

/**
 * Create a new of_bsn_tlv_port_speed_gbps object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_port_speed_gbps
 */

of_object_t *
of_bsn_tlv_port_speed_gbps_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_PORT_SPEED_GBPS];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_port_speed_gbps_init(obj, version, bytes, 0);
    of_bsn_tlv_port_speed_gbps_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_port_speed_gbps.
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
of_bsn_tlv_port_speed_gbps_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_PORT_SPEED_GBPS] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_PORT_SPEED_GBPS];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_PORT_SPEED_GBPS;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_bsn_tlv_port_speed_gbps.
 * @param obj Pointer to an object of type of_bsn_tlv_port_speed_gbps.
 * @param value Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_tlv_port_speed_gbps_value_get(
    of_bsn_tlv_port_speed_gbps_t *obj,
    uint32_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_PORT_SPEED_GBPS);
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
 * Set value in an object of type of_bsn_tlv_port_speed_gbps.
 * @param obj Pointer to an object of type of_bsn_tlv_port_speed_gbps.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_port_speed_gbps_value_set(
    of_bsn_tlv_port_speed_gbps_t *obj,
    uint32_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_PORT_SPEED_GBPS);
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
of_bsn_tlv_port_usage_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0x8d); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_port_usage of_bsn_tlv_port_usage
 */

/**
 * Create a new of_bsn_tlv_port_usage object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_port_usage
 */

of_object_t *
of_bsn_tlv_port_usage_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_PORT_USAGE];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_port_usage_init(obj, version, bytes, 0);
    of_bsn_tlv_port_usage_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_port_usage.
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
of_bsn_tlv_port_usage_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_PORT_USAGE] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_PORT_USAGE];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_PORT_USAGE;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_bsn_tlv_port_usage.
 * @param obj Pointer to an object of type of_bsn_tlv_port_usage.
 * @param value Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_tlv_port_usage_value_get(
    of_bsn_tlv_port_usage_t *obj,
    uint16_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_PORT_USAGE);
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
 * Set value in an object of type of_bsn_tlv_port_usage.
 * @param obj Pointer to an object of type of_bsn_tlv_port_usage.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_port_usage_value_set(
    of_bsn_tlv_port_usage_t *obj,
    uint16_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_PORT_USAGE);
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
of_bsn_tlv_port_vxlan_mode_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0x58); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_port_vxlan_mode of_bsn_tlv_port_vxlan_mode
 */

/**
 * Create a new of_bsn_tlv_port_vxlan_mode object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_port_vxlan_mode
 */

of_object_t *
of_bsn_tlv_port_vxlan_mode_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_PORT_VXLAN_MODE];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_port_vxlan_mode_init(obj, version, bytes, 0);
    of_bsn_tlv_port_vxlan_mode_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_port_vxlan_mode.
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
of_bsn_tlv_port_vxlan_mode_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_PORT_VXLAN_MODE] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_PORT_VXLAN_MODE];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_PORT_VXLAN_MODE;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_bsn_tlv_port_vxlan_mode.
 * @param obj Pointer to an object of type of_bsn_tlv_port_vxlan_mode.
 * @param value Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_bsn_tlv_port_vxlan_mode_value_get(
    of_bsn_tlv_port_vxlan_mode_t *obj,
    uint8_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_PORT_VXLAN_MODE);
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
 * Set value in an object of type of_bsn_tlv_port_vxlan_mode.
 * @param obj Pointer to an object of type of_bsn_tlv_port_vxlan_mode.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_port_vxlan_mode_value_set(
    of_bsn_tlv_port_vxlan_mode_t *obj,
    uint8_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_PORT_VXLAN_MODE);
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
of_bsn_tlv_preserve_vlan_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xba); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_preserve_vlan of_bsn_tlv_preserve_vlan
 */

/**
 * Create a new of_bsn_tlv_preserve_vlan object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_preserve_vlan
 */

of_object_t *
of_bsn_tlv_preserve_vlan_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_PRESERVE_VLAN];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_preserve_vlan_init(obj, version, bytes, 0);
    of_bsn_tlv_preserve_vlan_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_preserve_vlan.
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
of_bsn_tlv_preserve_vlan_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_PRESERVE_VLAN] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_PRESERVE_VLAN];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_PRESERVE_VLAN;

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
of_bsn_tlv_priority_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0x39); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_priority of_bsn_tlv_priority
 */

/**
 * Create a new of_bsn_tlv_priority object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_priority
 */

of_object_t *
of_bsn_tlv_priority_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_PRIORITY];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_priority_init(obj, version, bytes, 0);
    of_bsn_tlv_priority_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_priority.
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
of_bsn_tlv_priority_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_PRIORITY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_PRIORITY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_PRIORITY;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_bsn_tlv_priority.
 * @param obj Pointer to an object of type of_bsn_tlv_priority.
 * @param value Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_tlv_priority_value_get(
    of_bsn_tlv_priority_t *obj,
    uint32_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_PRIORITY);
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
 * Set value in an object of type of_bsn_tlv_priority.
 * @param obj Pointer to an object of type of_bsn_tlv_priority.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_priority_value_set(
    of_bsn_tlv_priority_t *obj,
    uint32_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_PRIORITY);
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
of_bsn_tlv_push_two_per_policy_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xdc); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_push_two_per_policy of_bsn_tlv_push_two_per_policy
 */

/**
 * Create a new of_bsn_tlv_push_two_per_policy object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_push_two_per_policy
 */

of_object_t *
of_bsn_tlv_push_two_per_policy_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_PUSH_TWO_PER_POLICY];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_push_two_per_policy_init(obj, version, bytes, 0);
    of_bsn_tlv_push_two_per_policy_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_push_two_per_policy.
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
of_bsn_tlv_push_two_per_policy_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_PUSH_TWO_PER_POLICY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_PUSH_TWO_PER_POLICY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_PUSH_TWO_PER_POLICY;

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
of_bsn_tlv_push_two_tags_capability_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xdb); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_push_two_tags_capability of_bsn_tlv_push_two_tags_capability
 */

/**
 * Create a new of_bsn_tlv_push_two_tags_capability object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_push_two_tags_capability
 */

of_object_t *
of_bsn_tlv_push_two_tags_capability_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_PUSH_TWO_TAGS_CAPABILITY];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_push_two_tags_capability_init(obj, version, bytes, 0);
    of_bsn_tlv_push_two_tags_capability_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_push_two_tags_capability.
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
of_bsn_tlv_push_two_tags_capability_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_PUSH_TWO_TAGS_CAPABILITY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_PUSH_TWO_TAGS_CAPABILITY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_PUSH_TWO_TAGS_CAPABILITY;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_bsn_tlv_push_two_tags_capability.
 * @param obj Pointer to an object of type of_bsn_tlv_push_two_tags_capability.
 * @param value Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_bsn_tlv_push_two_tags_capability_value_get(
    of_bsn_tlv_push_two_tags_capability_t *obj,
    uint8_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_PUSH_TWO_TAGS_CAPABILITY);
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
 * Set value in an object of type of_bsn_tlv_push_two_tags_capability.
 * @param obj Pointer to an object of type of_bsn_tlv_push_two_tags_capability.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_push_two_tags_capability_value_set(
    of_bsn_tlv_push_two_tags_capability_t *obj,
    uint8_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_PUSH_TWO_TAGS_CAPABILITY);
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
of_bsn_tlv_push_vlan_on_egress_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xa2); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_push_vlan_on_egress of_bsn_tlv_push_vlan_on_egress
 */

/**
 * Create a new of_bsn_tlv_push_vlan_on_egress object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_push_vlan_on_egress
 */

of_object_t *
of_bsn_tlv_push_vlan_on_egress_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_PUSH_VLAN_ON_EGRESS];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_push_vlan_on_egress_init(obj, version, bytes, 0);
    of_bsn_tlv_push_vlan_on_egress_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_push_vlan_on_egress.
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
of_bsn_tlv_push_vlan_on_egress_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_PUSH_VLAN_ON_EGRESS] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_PUSH_VLAN_ON_EGRESS];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_PUSH_VLAN_ON_EGRESS;

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
of_bsn_tlv_push_vlan_on_ingress_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0x80); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_push_vlan_on_ingress of_bsn_tlv_push_vlan_on_ingress
 */

/**
 * Create a new of_bsn_tlv_push_vlan_on_ingress object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_push_vlan_on_ingress
 */

of_object_t *
of_bsn_tlv_push_vlan_on_ingress_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_PUSH_VLAN_ON_INGRESS];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_push_vlan_on_ingress_init(obj, version, bytes, 0);
    of_bsn_tlv_push_vlan_on_ingress_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_push_vlan_on_ingress.
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
of_bsn_tlv_push_vlan_on_ingress_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_PUSH_VLAN_ON_INGRESS] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_PUSH_VLAN_ON_INGRESS];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_PUSH_VLAN_ON_INGRESS;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get flags from an object of type of_bsn_tlv_push_vlan_on_ingress.
 * @param obj Pointer to an object of type of_bsn_tlv_push_vlan_on_ingress.
 * @param flags Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_bsn_tlv_push_vlan_on_ingress_flags_get(
    of_bsn_tlv_push_vlan_on_ingress_t *obj,
    uint8_t *flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_PUSH_VLAN_ON_INGRESS);
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
    of_wire_buffer_u8_get(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set flags in an object of type of_bsn_tlv_push_vlan_on_ingress.
 * @param obj Pointer to an object of type of_bsn_tlv_push_vlan_on_ingress.
 * @param flags The value to write into the object
 */
void
of_bsn_tlv_push_vlan_on_ingress_flags_set(
    of_bsn_tlv_push_vlan_on_ingress_t *obj,
    uint8_t flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_PUSH_VLAN_ON_INGRESS);
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
    of_wire_buffer_u8_set(wbuf, abs_offset, flags);

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
of_bsn_tlv_qos_priority_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0x6c); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_qos_priority of_bsn_tlv_qos_priority
 */

/**
 * Create a new of_bsn_tlv_qos_priority object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_qos_priority
 */

of_object_t *
of_bsn_tlv_qos_priority_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_QOS_PRIORITY];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_qos_priority_init(obj, version, bytes, 0);
    of_bsn_tlv_qos_priority_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_qos_priority.
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
of_bsn_tlv_qos_priority_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_QOS_PRIORITY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_QOS_PRIORITY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_QOS_PRIORITY;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_bsn_tlv_qos_priority.
 * @param obj Pointer to an object of type of_bsn_tlv_qos_priority.
 * @param value Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_tlv_qos_priority_value_get(
    of_bsn_tlv_qos_priority_t *obj,
    uint32_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_QOS_PRIORITY);
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
 * Set value in an object of type of_bsn_tlv_qos_priority.
 * @param obj Pointer to an object of type of_bsn_tlv_qos_priority.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_qos_priority_value_set(
    of_bsn_tlv_qos_priority_t *obj,
    uint32_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_QOS_PRIORITY);
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
of_bsn_tlv_queue_id_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0x14); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_queue_id of_bsn_tlv_queue_id
 */

/**
 * Create a new of_bsn_tlv_queue_id object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_queue_id
 */

of_object_t *
of_bsn_tlv_queue_id_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_QUEUE_ID];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_queue_id_init(obj, version, bytes, 0);
    of_bsn_tlv_queue_id_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_queue_id.
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
of_bsn_tlv_queue_id_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_QUEUE_ID] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_QUEUE_ID];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_QUEUE_ID;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_bsn_tlv_queue_id.
 * @param obj Pointer to an object of type of_bsn_tlv_queue_id.
 * @param value Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_tlv_queue_id_value_get(
    of_bsn_tlv_queue_id_t *obj,
    uint32_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_QUEUE_ID);
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
 * Set value in an object of type of_bsn_tlv_queue_id.
 * @param obj Pointer to an object of type of_bsn_tlv_queue_id.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_queue_id_value_set(
    of_bsn_tlv_queue_id_t *obj,
    uint32_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_QUEUE_ID);
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
of_bsn_tlv_queue_weight_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0x15); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_queue_weight of_bsn_tlv_queue_weight
 */

/**
 * Create a new of_bsn_tlv_queue_weight object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_queue_weight
 */

of_object_t *
of_bsn_tlv_queue_weight_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_QUEUE_WEIGHT];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_queue_weight_init(obj, version, bytes, 0);
    of_bsn_tlv_queue_weight_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_queue_weight.
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
of_bsn_tlv_queue_weight_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_QUEUE_WEIGHT] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_QUEUE_WEIGHT];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_QUEUE_WEIGHT;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_bsn_tlv_queue_weight.
 * @param obj Pointer to an object of type of_bsn_tlv_queue_weight.
 * @param value Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_tlv_queue_weight_value_get(
    of_bsn_tlv_queue_weight_t *obj,
    uint32_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_QUEUE_WEIGHT);
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
 * Set value in an object of type of_bsn_tlv_queue_weight.
 * @param obj Pointer to an object of type of_bsn_tlv_queue_weight.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_queue_weight_value_set(
    of_bsn_tlv_queue_weight_t *obj,
    uint32_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_QUEUE_WEIGHT);
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
of_bsn_tlv_rate_limit_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0x74); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_rate_limit of_bsn_tlv_rate_limit
 */

/**
 * Create a new of_bsn_tlv_rate_limit object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_rate_limit
 */

of_object_t *
of_bsn_tlv_rate_limit_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_RATE_LIMIT];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_rate_limit_init(obj, version, bytes, 0);
    of_bsn_tlv_rate_limit_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_rate_limit.
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
of_bsn_tlv_rate_limit_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_RATE_LIMIT] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_RATE_LIMIT];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_RATE_LIMIT;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_bsn_tlv_rate_limit.
 * @param obj Pointer to an object of type of_bsn_tlv_rate_limit.
 * @param value Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_tlv_rate_limit_value_get(
    of_bsn_tlv_rate_limit_t *obj,
    uint32_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_RATE_LIMIT);
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
 * Set value in an object of type of_bsn_tlv_rate_limit.
 * @param obj Pointer to an object of type of_bsn_tlv_rate_limit.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_rate_limit_value_set(
    of_bsn_tlv_rate_limit_t *obj,
    uint32_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_RATE_LIMIT);
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
of_bsn_tlv_rate_unit_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0x59); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_rate_unit of_bsn_tlv_rate_unit
 */

/**
 * Create a new of_bsn_tlv_rate_unit object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_rate_unit
 */

of_object_t *
of_bsn_tlv_rate_unit_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_RATE_UNIT];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_rate_unit_init(obj, version, bytes, 0);
    of_bsn_tlv_rate_unit_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_rate_unit.
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
of_bsn_tlv_rate_unit_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_RATE_UNIT] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_RATE_UNIT];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_RATE_UNIT;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_bsn_tlv_rate_unit.
 * @param obj Pointer to an object of type of_bsn_tlv_rate_unit.
 * @param value Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_bsn_tlv_rate_unit_value_get(
    of_bsn_tlv_rate_unit_t *obj,
    uint8_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_RATE_UNIT);
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
 * Set value in an object of type of_bsn_tlv_rate_unit.
 * @param obj Pointer to an object of type of_bsn_tlv_rate_unit.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_rate_unit_value_set(
    of_bsn_tlv_rate_unit_t *obj,
    uint8_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_RATE_UNIT);
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
of_bsn_tlv_record_packets_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0x9b); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_record_packets of_bsn_tlv_record_packets
 */

/**
 * Create a new of_bsn_tlv_record_packets object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_record_packets
 */

of_object_t *
of_bsn_tlv_record_packets_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_RECORD_PACKETS];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_record_packets_init(obj, version, bytes, 0);
    of_bsn_tlv_record_packets_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_record_packets.
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
of_bsn_tlv_record_packets_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_RECORD_PACKETS] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_RECORD_PACKETS];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_RECORD_PACKETS;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_bsn_tlv_record_packets.
 * @param obj Pointer to an object of type of_bsn_tlv_record_packets.
 * @param value Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_tlv_record_packets_value_get(
    of_bsn_tlv_record_packets_t *obj,
    uint32_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_RECORD_PACKETS);
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
 * Set value in an object of type of_bsn_tlv_record_packets.
 * @param obj Pointer to an object of type of_bsn_tlv_record_packets.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_record_packets_value_set(
    of_bsn_tlv_record_packets_t *obj,
    uint32_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_RECORD_PACKETS);
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
of_bsn_tlv_redundant_mgmt_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xbd); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_redundant_mgmt of_bsn_tlv_redundant_mgmt
 */

/**
 * Create a new of_bsn_tlv_redundant_mgmt object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_redundant_mgmt
 */

of_object_t *
of_bsn_tlv_redundant_mgmt_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_REDUNDANT_MGMT];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_redundant_mgmt_init(obj, version, bytes, 0);
    of_bsn_tlv_redundant_mgmt_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_redundant_mgmt.
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
of_bsn_tlv_redundant_mgmt_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_REDUNDANT_MGMT] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_REDUNDANT_MGMT];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_REDUNDANT_MGMT;

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
of_bsn_tlv_reference_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0x3b); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_reference of_bsn_tlv_reference
 */

/**
 * Create a new of_bsn_tlv_reference object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_reference
 */

of_object_t *
of_bsn_tlv_reference_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_REFERENCE];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_reference_init(obj, version, bytes, 0);
    of_bsn_tlv_reference_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_reference.
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
of_bsn_tlv_reference_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_REFERENCE] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_REFERENCE];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_REFERENCE;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get table_id from an object of type of_bsn_tlv_reference.
 * @param obj Pointer to an object of type of_bsn_tlv_reference.
 * @param table_id Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_tlv_reference_table_id_get(
    of_bsn_tlv_reference_t *obj,
    uint16_t *table_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_REFERENCE);
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
    of_wire_buffer_u16_get(wbuf, abs_offset, table_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set table_id in an object of type of_bsn_tlv_reference.
 * @param obj Pointer to an object of type of_bsn_tlv_reference.
 * @param table_id The value to write into the object
 */
void
of_bsn_tlv_reference_table_id_set(
    of_bsn_tlv_reference_t *obj,
    uint16_t table_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_REFERENCE);
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
    of_wire_buffer_u16_set(wbuf, abs_offset, table_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Bind an object of type of_list_bsn_tlv_t to the parent of type of_bsn_tlv_reference for
 * member key
 * @param obj Pointer to an object of type of_bsn_tlv_reference.
 * @param key Pointer to the child object of type
 * of_list_bsn_tlv_t to be filled out.
 * \ingroup of_bsn_tlv_reference
 *
 * The parameter key is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_bsn_tlv_reference_key_bind(
    of_bsn_tlv_reference_t *obj,
    of_list_bsn_tlv_t *key)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_REFERENCE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 6;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_list_bsn_tlv_init(key, obj->version, 0, 1);
    /* Attach to parent */
    of_object_attach(obj, key, offset, cur_len);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of key into a new variable of type of_list_bsn_tlv_t from
 * a of_bsn_tlv_reference instance.
 *
 * @param obj Pointer to the source of type of_bsn_tlv_reference_t
 * @returns A pointer to a new instance of type of_list_bsn_tlv_t whose contents
 * match that of key from source
 * @returns NULL if an error occurs
 */
of_list_bsn_tlv_t *
of_bsn_tlv_reference_key_get(of_bsn_tlv_reference_t *obj) {
    of_list_bsn_tlv_t _key;
    of_list_bsn_tlv_t *_key_ptr;

    of_bsn_tlv_reference_key_bind(obj, &_key);
    _key_ptr = (of_list_bsn_tlv_t *)of_object_dup(&_key);
    return _key_ptr;
}

/**
 * Set key in an object of type of_bsn_tlv_reference.
 * @param obj Pointer to an object of type of_bsn_tlv_reference.
 * @param key Pointer to the child of type of_list_bsn_tlv_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_bsn_tlv_reference_key_set(
    of_bsn_tlv_reference_t *obj,
    of_list_bsn_tlv_t *key)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_REFERENCE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 6;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = key->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wbuf == key->wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(key, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(key, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    of_object_wire_length_set((of_object_t *)key, key->length);

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
of_bsn_tlv_remote_id_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xe0); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_remote_id of_bsn_tlv_remote_id
 */

/**
 * Create a new of_bsn_tlv_remote_id object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_remote_id
 */

of_object_t *
of_bsn_tlv_remote_id_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_REMOTE_ID];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_remote_id_init(obj, version, bytes, 0);
    of_bsn_tlv_remote_id_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_remote_id.
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
of_bsn_tlv_remote_id_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_REMOTE_ID] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_REMOTE_ID];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_REMOTE_ID;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_bsn_tlv_remote_id.
 * @param obj Pointer to an object of type of_bsn_tlv_remote_id.
 * @param value Pointer to the child object of type
 * of_octets_t to be filled out.
 *
 */
void
of_bsn_tlv_remote_id_value_get(
    of_bsn_tlv_remote_id_t *obj,
    of_octets_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_REMOTE_ID);
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
 * Set value in an object of type of_bsn_tlv_remote_id.
 * @param obj Pointer to an object of type of_bsn_tlv_remote_id.
 * @param value The value to write into the object
 */
int WARN_UNUSED_RESULT
of_bsn_tlv_remote_id_value_set(
    of_bsn_tlv_remote_id_t *obj,
    of_octets_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_REMOTE_ID);
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
of_bsn_tlv_reply_packets_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xc); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_reply_packets of_bsn_tlv_reply_packets
 */

/**
 * Create a new of_bsn_tlv_reply_packets object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_reply_packets
 */

of_object_t *
of_bsn_tlv_reply_packets_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_REPLY_PACKETS];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_reply_packets_init(obj, version, bytes, 0);
    of_bsn_tlv_reply_packets_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

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
of_bsn_tlv_reply_packets_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_REPLY_PACKETS] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_REPLY_PACKETS];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_REPLY_PACKETS;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
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
of_bsn_tlv_request_packets_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xb); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_request_packets of_bsn_tlv_request_packets
 */

/**
 * Create a new of_bsn_tlv_request_packets object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_request_packets
 */

of_object_t *
of_bsn_tlv_request_packets_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_REQUEST_PACKETS];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_request_packets_init(obj, version, bytes, 0);
    of_bsn_tlv_request_packets_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

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
of_bsn_tlv_request_packets_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_REQUEST_PACKETS] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_REQUEST_PACKETS];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_REQUEST_PACKETS;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
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
of_bsn_tlv_rest_server_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0x98); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_rest_server of_bsn_tlv_rest_server
 */

/**
 * Create a new of_bsn_tlv_rest_server object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_rest_server
 */

of_object_t *
of_bsn_tlv_rest_server_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_REST_SERVER];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_rest_server_init(obj, version, bytes, 0);
    of_bsn_tlv_rest_server_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_rest_server.
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
of_bsn_tlv_rest_server_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_REST_SERVER] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_REST_SERVER];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_REST_SERVER;

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
of_bsn_tlv_routing_param_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xa1); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_routing_param of_bsn_tlv_routing_param
 */

/**
 * Create a new of_bsn_tlv_routing_param object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_routing_param
 */

of_object_t *
of_bsn_tlv_routing_param_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_ROUTING_PARAM];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_routing_param_init(obj, version, bytes, 0);
    of_bsn_tlv_routing_param_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_routing_param.
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
of_bsn_tlv_routing_param_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_ROUTING_PARAM] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_ROUTING_PARAM];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_ROUTING_PARAM;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_bsn_tlv_routing_param.
 * @param obj Pointer to an object of type of_bsn_tlv_routing_param.
 * @param value Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_tlv_routing_param_value_get(
    of_bsn_tlv_routing_param_t *obj,
    uint16_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_ROUTING_PARAM);
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
 * Set value in an object of type of_bsn_tlv_routing_param.
 * @param obj Pointer to an object of type of_bsn_tlv_routing_param.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_routing_param_value_set(
    of_bsn_tlv_routing_param_t *obj,
    uint16_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_ROUTING_PARAM);
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
of_bsn_tlv_rx_bytes_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0x47); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_rx_bytes of_bsn_tlv_rx_bytes
 */

/**
 * Create a new of_bsn_tlv_rx_bytes object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_rx_bytes
 */

of_object_t *
of_bsn_tlv_rx_bytes_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_RX_BYTES];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_rx_bytes_init(obj, version, bytes, 0);
    of_bsn_tlv_rx_bytes_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_rx_bytes.
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
of_bsn_tlv_rx_bytes_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_RX_BYTES] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_RX_BYTES];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_RX_BYTES;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_bsn_tlv_rx_bytes.
 * @param obj Pointer to an object of type of_bsn_tlv_rx_bytes.
 * @param value Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_bsn_tlv_rx_bytes_value_get(
    of_bsn_tlv_rx_bytes_t *obj,
    uint64_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_RX_BYTES);
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
 * Set value in an object of type of_bsn_tlv_rx_bytes.
 * @param obj Pointer to an object of type of_bsn_tlv_rx_bytes.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_rx_bytes_value_set(
    of_bsn_tlv_rx_bytes_t *obj,
    uint64_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_RX_BYTES);
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
of_bsn_tlv_rx_packets_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0x2); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_rx_packets of_bsn_tlv_rx_packets
 */

/**
 * Create a new of_bsn_tlv_rx_packets object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_rx_packets
 */

of_object_t *
of_bsn_tlv_rx_packets_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_RX_PACKETS];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_rx_packets_init(obj, version, bytes, 0);
    of_bsn_tlv_rx_packets_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

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
of_bsn_tlv_rx_packets_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_RX_PACKETS] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_RX_PACKETS];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_RX_PACKETS;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
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
of_bsn_tlv_sampling_rate_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0x1e); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_sampling_rate of_bsn_tlv_sampling_rate
 */

/**
 * Create a new of_bsn_tlv_sampling_rate object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_sampling_rate
 */

of_object_t *
of_bsn_tlv_sampling_rate_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_SAMPLING_RATE];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_sampling_rate_init(obj, version, bytes, 0);
    of_bsn_tlv_sampling_rate_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_sampling_rate.
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
of_bsn_tlv_sampling_rate_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_SAMPLING_RATE] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_SAMPLING_RATE];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_SAMPLING_RATE;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_bsn_tlv_sampling_rate.
 * @param obj Pointer to an object of type of_bsn_tlv_sampling_rate.
 * @param value Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_tlv_sampling_rate_value_get(
    of_bsn_tlv_sampling_rate_t *obj,
    uint32_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_SAMPLING_RATE);
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
 * Set value in an object of type of_bsn_tlv_sampling_rate.
 * @param obj Pointer to an object of type of_bsn_tlv_sampling_rate.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_sampling_rate_value_set(
    of_bsn_tlv_sampling_rate_t *obj,
    uint32_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_SAMPLING_RATE);
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
of_bsn_tlv_sctp_dst_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xcb); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_sctp_dst of_bsn_tlv_sctp_dst
 */

/**
 * Create a new of_bsn_tlv_sctp_dst object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_sctp_dst
 */

of_object_t *
of_bsn_tlv_sctp_dst_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_SCTP_DST];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_sctp_dst_init(obj, version, bytes, 0);
    of_bsn_tlv_sctp_dst_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_sctp_dst.
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
of_bsn_tlv_sctp_dst_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_SCTP_DST] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_SCTP_DST];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_SCTP_DST;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_bsn_tlv_sctp_dst.
 * @param obj Pointer to an object of type of_bsn_tlv_sctp_dst.
 * @param value Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_tlv_sctp_dst_value_get(
    of_bsn_tlv_sctp_dst_t *obj,
    uint16_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_SCTP_DST);
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
 * Set value in an object of type of_bsn_tlv_sctp_dst.
 * @param obj Pointer to an object of type of_bsn_tlv_sctp_dst.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_sctp_dst_value_set(
    of_bsn_tlv_sctp_dst_t *obj,
    uint16_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_SCTP_DST);
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
of_bsn_tlv_sctp_src_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xca); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_sctp_src of_bsn_tlv_sctp_src
 */

/**
 * Create a new of_bsn_tlv_sctp_src object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_sctp_src
 */

of_object_t *
of_bsn_tlv_sctp_src_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_SCTP_SRC];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_sctp_src_init(obj, version, bytes, 0);
    of_bsn_tlv_sctp_src_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_sctp_src.
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
of_bsn_tlv_sctp_src_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_SCTP_SRC] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_SCTP_SRC];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_SCTP_SRC;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_bsn_tlv_sctp_src.
 * @param obj Pointer to an object of type of_bsn_tlv_sctp_src.
 * @param value Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_tlv_sctp_src_value_get(
    of_bsn_tlv_sctp_src_t *obj,
    uint16_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_SCTP_SRC);
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
 * Set value in an object of type of_bsn_tlv_sctp_src.
 * @param obj Pointer to an object of type of_bsn_tlv_sctp_src.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_sctp_src_value_set(
    of_bsn_tlv_sctp_src_t *obj,
    uint16_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_SCTP_SRC);
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
of_bsn_tlv_set_loopback_mode_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0x4a); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_set_loopback_mode of_bsn_tlv_set_loopback_mode
 */

/**
 * Create a new of_bsn_tlv_set_loopback_mode object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_set_loopback_mode
 */

of_object_t *
of_bsn_tlv_set_loopback_mode_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_SET_LOOPBACK_MODE];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_set_loopback_mode_init(obj, version, bytes, 0);
    of_bsn_tlv_set_loopback_mode_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_set_loopback_mode.
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
of_bsn_tlv_set_loopback_mode_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_SET_LOOPBACK_MODE] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_SET_LOOPBACK_MODE];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_SET_LOOPBACK_MODE;

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
of_bsn_tlv_socket_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xd4); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bsn_tlv_socket of_bsn_tlv_socket
 */

/**
 * Create a new of_bsn_tlv_socket object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bsn_tlv_socket
 */

of_object_t *
of_bsn_tlv_socket_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_SOCKET];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_socket_init(obj, version, bytes, 0);
    of_bsn_tlv_socket_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_socket.
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
of_bsn_tlv_socket_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_SOCKET] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_SOCKET];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_SOCKET;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_bsn_tlv_socket.
 * @param obj Pointer to an object of type of_bsn_tlv_socket.
 * @param value Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_tlv_socket_value_get(
    of_bsn_tlv_socket_t *obj,
    uint32_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_SOCKET);
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
 * Set value in an object of type of_bsn_tlv_socket.
 * @param obj Pointer to an object of type of_bsn_tlv_socket.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_socket_value_set(
    of_bsn_tlv_socket_t *obj,
    uint32_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_SOCKET);
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
