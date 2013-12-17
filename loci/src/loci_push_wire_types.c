/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */

/****************************************************************
 *
 * Functions for each concrete class that set the type fields
 *
 ****************************************************************/

#include <loci/loci.h>
#include <loci/of_message.h>
#include <endian.h>

#ifdef __GNUC__
#define UNREACHABLE() __builtin_unreachable()
#else
#define UNREACHABLE()
#endif

/*
 * In a separate function to give the compiler the choice of whether to inline.
 */
static unsigned char *
loci_object_to_buffer(of_object_t *obj)
{
    return OF_OBJECT_BUFFER_INDEX(obj, 0);
}


void
of_action_bsn_mirror_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0xffff); /* type */
        *(uint32_t *)(buf + 4) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 8) = htobe32(0x1); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_bsn_set_tunnel_dst_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0xffff); /* type */
        *(uint32_t *)(buf + 4) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 8) = htobe32(0x2); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_enqueue_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint16_t *)(buf + 0) = htobe16(0xb); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_nicira_dec_ttl_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0xffff); /* type */
        *(uint32_t *)(buf + 4) = htobe32(0x2320); /* experimenter */
        *(uint16_t *)(buf + 8) = htobe16(0x12); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_output_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
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

void
of_action_set_dl_dst_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint16_t *)(buf + 0) = htobe16(0x5); /* type */
        break;
    case OF_VERSION_1_1:
        *(uint16_t *)(buf + 0) = htobe16(0x4); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_set_dl_src_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint16_t *)(buf + 0) = htobe16(0x4); /* type */
        break;
    case OF_VERSION_1_1:
        *(uint16_t *)(buf + 0) = htobe16(0x3); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_set_nw_dst_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint16_t *)(buf + 0) = htobe16(0x7); /* type */
        break;
    case OF_VERSION_1_1:
        *(uint16_t *)(buf + 0) = htobe16(0x6); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_set_nw_src_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint16_t *)(buf + 0) = htobe16(0x6); /* type */
        break;
    case OF_VERSION_1_1:
        *(uint16_t *)(buf + 0) = htobe16(0x5); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_set_nw_tos_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint16_t *)(buf + 0) = htobe16(0x8); /* type */
        break;
    case OF_VERSION_1_1:
        *(uint16_t *)(buf + 0) = htobe16(0x7); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_set_tp_dst_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
        *(uint16_t *)(buf + 0) = htobe16(0xa); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_set_tp_src_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
        *(uint16_t *)(buf + 0) = htobe16(0x9); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_set_vlan_pcp_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
        *(uint16_t *)(buf + 0) = htobe16(0x2); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_set_vlan_vid_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
        *(uint16_t *)(buf + 0) = htobe16(0x1); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_strip_vlan_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint16_t *)(buf + 0) = htobe16(0x3); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_aggregate_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x11; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x2); /* stats_type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x13; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x2); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_aggregate_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x10; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x2); /* stats_type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x12; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x2); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bad_action_error_msg_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x1; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x2); /* err_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bad_request_error_msg_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x1; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x1); /* err_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_barrier_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x13; /* type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x15; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_barrier_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x12; /* type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x14; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_bw_clear_data_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x16); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_bw_clear_data_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x15); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_bw_enable_get_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x14); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_bw_enable_get_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x13); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_bw_enable_set_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x17); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_bw_enable_set_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x12); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_get_interfaces_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0xa); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_get_interfaces_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x9); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_get_ip_mask_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x2); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_get_ip_mask_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x1); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_get_l2_table_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0xe); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_get_l2_table_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0xd); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_get_mirroring_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x5); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_get_mirroring_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x4); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_hybrid_get_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x1c); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_hybrid_get_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x1b); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_pdu_rx_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x22); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_pdu_rx_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
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

void
of_bsn_pdu_rx_timeout_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x23); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_pdu_tx_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x20); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_pdu_tx_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x1f); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_set_ip_mask_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x0); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_set_l2_table_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x18); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_set_l2_table_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0xc); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_set_mirroring_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x3); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_set_pktin_suppression_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x19); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_set_pktin_suppression_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0xb); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_shell_command_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x6); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_shell_output_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x7); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_shell_status_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x8); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_virtual_port_create_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x10); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_vport_q_in_q_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
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

void
of_bsn_virtual_port_create_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0xf); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_virtual_port_remove_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x1a); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_virtual_port_remove_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x11); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_desc_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x11; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x0); /* stats_type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x13; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x0); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_desc_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x10; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x0); /* stats_type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x12; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x0); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_echo_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x3; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_echo_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x2; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_features_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x6; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_features_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x5; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_flow_add_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0xe; /* type */
        *(uint16_t *)(buf + 56) = htobe16(0x0); /* _command */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0xe; /* type */
        *(uint8_t *)(buf + 25) = 0x0; /* _command */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_flow_delete_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0xe; /* type */
        *(uint16_t *)(buf + 56) = htobe16(0x3); /* _command */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0xe; /* type */
        *(uint8_t *)(buf + 25) = 0x3; /* _command */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_flow_delete_strict_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0xe; /* type */
        *(uint16_t *)(buf + 56) = htobe16(0x4); /* _command */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0xe; /* type */
        *(uint8_t *)(buf + 25) = 0x4; /* _command */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_flow_mod_failed_error_msg_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x1; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x3); /* err_type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x1; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x5); /* err_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_flow_modify_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0xe; /* type */
        *(uint16_t *)(buf + 56) = htobe16(0x1); /* _command */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0xe; /* type */
        *(uint8_t *)(buf + 25) = 0x1; /* _command */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_flow_modify_strict_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0xe; /* type */
        *(uint16_t *)(buf + 56) = htobe16(0x2); /* _command */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0xe; /* type */
        *(uint8_t *)(buf + 25) = 0x2; /* _command */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_flow_removed_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0xb; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_flow_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x11; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x1); /* stats_type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x13; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x1); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_flow_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x10; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x1); /* stats_type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x12; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x1); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_get_config_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x8; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_get_config_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x7; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_hello_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x0; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_hello_failed_error_msg_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x1; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x0); /* err_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_nicira_controller_role_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x2320); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0xb); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_nicira_controller_role_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x2320); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0xa); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_packet_in_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
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

void
of_packet_out_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0xd; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_port_mod_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0xf; /* type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x10; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_port_mod_failed_error_msg_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x1; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x4); /* err_type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x1; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x7); /* err_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_port_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x11; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x4); /* stats_type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x13; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x4); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_port_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x10; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x4); /* stats_type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x12; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x4); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_port_status_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0xc; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_queue_get_config_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x15; /* type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x17; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_queue_get_config_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x14; /* type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x16; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_queue_op_failed_error_msg_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x1; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x5); /* err_type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x1; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x9); /* err_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_queue_prop_min_rate_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x1); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_queue_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x11; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x5); /* stats_type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x13; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x5); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_queue_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x10; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x5); /* stats_type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x12; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x5); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_set_config_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x9; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_mod_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x16; /* type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x11; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x11; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x3); /* stats_type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x13; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x3); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x10; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x3); /* stats_type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x12; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x3); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_copy_ttl_in_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0xc); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_copy_ttl_out_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0xb); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_dec_mpls_ttl_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x10); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_dec_nw_ttl_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x18); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_group_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x16); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_pop_mpls_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x14); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_pop_vlan_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x12); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_push_mpls_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x13); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_push_vlan_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x11); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_set_mpls_label_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
        *(uint16_t *)(buf + 0) = htobe16(0xd); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_set_mpls_tc_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
        *(uint16_t *)(buf + 0) = htobe16(0xe); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_set_mpls_ttl_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0xf); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_set_nw_ecn_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
        *(uint16_t *)(buf + 0) = htobe16(0x8); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_set_nw_ttl_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x17); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_set_queue_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x15); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bad_instruction_error_msg_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x1; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x3); /* err_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bad_match_error_msg_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x1; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x4); /* err_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_group_add_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0xf; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x0); /* command */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_group_delete_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0xf; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x2); /* command */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_group_desc_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x13; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x7); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_group_desc_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x12; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x7); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_group_mod_failed_error_msg_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x1; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x6); /* err_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_group_modify_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0xf; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x1); /* command */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_group_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x13; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x6); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_group_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x12; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x6); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_instruction_apply_actions_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x4); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_instruction_clear_actions_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x5); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_instruction_goto_table_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x1); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_instruction_write_actions_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x3); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_instruction_write_metadata_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x2); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_match_v2_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
        *(uint16_t *)(buf + 0) = htobe16(0x0); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_switch_config_failed_error_msg_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x1; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0xa); /* err_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_mod_failed_error_msg_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x1; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x8); /* err_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_set_field_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x19); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_experimenter_error_msg_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x1; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0xffff); /* err_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_group_features_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
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

void
of_group_features_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x12; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x8); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_match_v3_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x1); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_arp_op_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80002a02); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_arp_op_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80002b04); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_arp_sha_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80003006); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_arp_sha_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x8000310c); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_arp_spa_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80002c04); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_arp_spa_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80002d08); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_arp_tha_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80003206); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_arp_tha_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x8000330c); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_arp_tpa_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80002e04); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_arp_tpa_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80002f08); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_bsn_global_vrf_allowed_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x30601); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_bsn_global_vrf_allowed_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x30702); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_bsn_in_ports_128_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x30010); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_bsn_in_ports_128_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x30120); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_bsn_l3_dst_class_id_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x30c04); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_bsn_l3_dst_class_id_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x30d08); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_bsn_l3_interface_class_id_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x30804); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_bsn_l3_interface_class_id_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x30908); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_bsn_l3_src_class_id_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x30a04); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_bsn_l3_src_class_id_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x30b08); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_bsn_lag_id_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x30204); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_bsn_lag_id_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x30308); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_bsn_vrf_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x30404); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_bsn_vrf_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x30508); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_eth_dst_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80000606); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_eth_dst_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x8000070c); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_eth_src_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80000806); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_eth_src_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x8000090c); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_eth_type_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80000a02); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_eth_type_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80000b04); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_icmpv4_code_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80002801); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_icmpv4_code_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80002902); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_icmpv4_type_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80002601); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_icmpv4_type_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80002702); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_icmpv6_code_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80003c01); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_icmpv6_code_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80003d02); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_icmpv6_type_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80003a01); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_icmpv6_type_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80003b02); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_in_phy_port_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80000204); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_in_phy_port_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80000308); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_in_port_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80000004); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_in_port_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80000108); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ip_dscp_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80001001); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ip_dscp_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80001102); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ip_ecn_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80001201); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ip_ecn_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80001302); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ip_proto_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80001401); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ip_proto_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80001502); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ipv4_dst_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80001804); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ipv4_dst_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80001908); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ipv4_src_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80001604); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ipv4_src_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80001708); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ipv6_dst_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80003610); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ipv6_dst_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80003720); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ipv6_flabel_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80003804); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ipv6_flabel_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80003908); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ipv6_nd_sll_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80004006); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ipv6_nd_sll_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x8000410c); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ipv6_nd_target_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80003e10); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ipv6_nd_target_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80003f20); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ipv6_nd_tll_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80004206); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ipv6_nd_tll_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x8000430c); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ipv6_src_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80003410); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_ipv6_src_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80003520); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_metadata_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80000408); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_metadata_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80000510); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_mpls_label_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80004404); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_mpls_label_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80004508); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_mpls_tc_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80004601); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_mpls_tc_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80004702); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_sctp_dst_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80002402); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_sctp_dst_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80002504); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_sctp_src_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80002202); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_sctp_src_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80002304); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_tcp_dst_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80001c02); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_tcp_dst_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80001d04); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_tcp_src_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80001a02); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_tcp_src_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80001b04); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_udp_dst_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80002002); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_udp_dst_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80002104); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_udp_src_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80001e02); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_udp_src_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80001f04); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_vlan_pcp_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80000e01); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_vlan_pcp_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80000f02); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_vlan_vid_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80000c02); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_oxm_vlan_vid_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = htobe32(0x80000d04); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_queue_prop_max_rate_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x2); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_role_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x19; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_role_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x18; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_role_request_failed_error_msg_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
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

void
of_action_id_bsn_mirror_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
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

void
of_action_id_bsn_set_tunnel_dst_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
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

void
of_action_id_copy_ttl_in_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0xc); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_id_copy_ttl_out_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0xb); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_id_dec_mpls_ttl_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x10); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_id_dec_nw_ttl_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x18); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_id_group_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x16); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_id_nicira_dec_ttl_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
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

void
of_action_id_output_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x0); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_id_pop_mpls_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x14); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_pop_pbb_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x1b); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_id_pop_pbb_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x1b); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_id_pop_vlan_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x12); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_id_push_mpls_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x13); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_push_pbb_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x1a); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_id_push_pbb_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x1a); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_id_push_vlan_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x11); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_id_set_field_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x19); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_id_set_mpls_ttl_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0xf); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_id_set_nw_ttl_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x17); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_action_id_set_queue_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x15); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_async_get_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x1b; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_async_get_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x1a; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_async_set_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x1c; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_controller_connections_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
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

void
of_bsn_controller_connections_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x38); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_flow_idle_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x28); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_flow_idle_enable_get_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x27); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_flow_idle_enable_get_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x26); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_flow_idle_enable_set_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x25); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_flow_idle_enable_set_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x24); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_get_switch_pipeline_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x34); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_get_switch_pipeline_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x33); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_lacp_convergence_notif_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
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

void
of_bsn_lacp_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x13; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0xffff); /* stats_type */
        *(uint32_t *)(buf + 16) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 20) = htobe32(0x1); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_lacp_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x12; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0xffff); /* stats_type */
        *(uint32_t *)(buf + 16) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 20) = htobe32(0x1); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_port_counter_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x13; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0xffff); /* stats_type */
        *(uint32_t *)(buf + 16) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 20) = htobe32(0x8); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_port_counter_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x12; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0xffff); /* stats_type */
        *(uint32_t *)(buf + 16) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 20) = htobe32(0x8); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_role_status_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x37); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_set_lacp_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x2a); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_set_lacp_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x29); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_set_switch_pipeline_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x36); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_set_switch_pipeline_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x35); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_switch_pipeline_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x13; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0xffff); /* stats_type */
        *(uint32_t *)(buf + 16) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 20) = htobe32(0x6); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_switch_pipeline_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x12; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0xffff); /* stats_type */
        *(uint32_t *)(buf + 16) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 20) = htobe32(0x6); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_time_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x2d); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_time_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x2c); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_bsn_vlan_counter_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
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

void
of_bsn_vlan_counter_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
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

void
of_hello_elem_versionbitmap_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x1); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_instruction_id_apply_actions_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x4); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_instruction_bsn_disable_src_mac_check_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
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

void
of_instruction_id_bsn_disable_src_mac_check_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
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

void
of_instruction_id_clear_actions_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x5); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_instruction_id_goto_table_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x1); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_instruction_meter_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x6); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_instruction_id_meter_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x6); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_instruction_id_write_actions_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x3); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_instruction_id_write_metadata_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x2); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_meter_band_drop_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x1); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_meter_band_dscp_remark_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x2); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_meter_band_experimenter_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0xffff); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_meter_config_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x13; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0xa); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_meter_config_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x12; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0xa); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_meter_features_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x13; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0xb); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_meter_features_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x12; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0xb); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_meter_mod_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x1d; /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_meter_mod_failed_error_msg_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x1; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0xc); /* err_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_meter_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x13; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x9); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_meter_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x12; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0x9); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_port_desc_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x13; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0xd); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_port_desc_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x12; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0xd); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_feature_prop_apply_actions_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x6); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_feature_prop_apply_actions_miss_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x7); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_feature_prop_apply_setfield_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0xe); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_feature_prop_apply_setfield_miss_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0xf); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_feature_prop_experimenter_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0xffff); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_feature_prop_instructions_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x0); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_feature_prop_instructions_miss_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x1); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_feature_prop_match_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x8); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_feature_prop_next_tables_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x2); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_feature_prop_next_tables_miss_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x3); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_feature_prop_wildcards_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0xa); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_feature_prop_write_actions_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x4); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_feature_prop_write_actions_miss_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x5); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_feature_prop_write_setfield_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0xc); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_feature_prop_write_setfield_miss_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0xd); /* type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_features_failed_error_msg_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x1; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0xd); /* err_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_features_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x13; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0xc); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}

void
of_table_features_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = loci_object_to_buffer(obj);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x12; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0xc); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}
