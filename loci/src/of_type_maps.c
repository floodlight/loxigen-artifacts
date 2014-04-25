/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */

/****************************************************************
 *
 * Functions related to mapping wire values to object types
 * and lengths
 *
 ****************************************************************/

#include <loci/loci.h>
#include <loci/of_message.h>

#define OF_INSTRUCTION_EXPERIMENTER_ID_OFFSET 4
#define OF_INSTRUCTION_EXPERIMENTER_SUBTYPE_OFFSET 8


/**
 * action wire type to object ID array.
 * Treat as private; use function accessor below
 */

extern const of_object_id_t *const of_action_type_to_id[OF_VERSION_ARRAY_MAX];

#define OF_ACTION_ITEM_COUNT 28


/**
 * Map an action wire value to an OF object
 * @param action The action type wire value
 * @param version The version associated with the check
 * @return The action OF object type
 * @return OF_OBJECT_INVALID if type does not map to an object
 *
 */
of_object_id_t
of_action_to_object_id(int action, of_version_t version)
{
    if (!OF_VERSION_OKAY(version)) {
        return OF_OBJECT_INVALID;
    }
    if (action == OF_EXPERIMENTER_TYPE) {
        return OF_ACTION_EXPERIMENTER;
    }
    if (action < 0 || action >= OF_ACTION_ITEM_COUNT) {
        return OF_OBJECT_INVALID;
    }

    return of_action_type_to_id[version][action];
}

/**
 * action_id wire type to object ID array.
 * Treat as private; use function accessor below
 */

extern const of_object_id_t *const of_action_id_type_to_id[OF_VERSION_ARRAY_MAX];

#define OF_ACTION_ID_ITEM_COUNT 28


/**
 * Map an action_id wire value to an OF object
 * @param action_id The action_id type wire value
 * @param version The version associated with the check
 * @return The action_id OF object type
 * @return OF_OBJECT_INVALID if type does not map to an object
 *
 */
of_object_id_t
of_action_id_to_object_id(int action_id, of_version_t version)
{
    if (!OF_VERSION_OKAY(version)) {
        return OF_OBJECT_INVALID;
    }
    if (action_id == OF_EXPERIMENTER_TYPE) {
        return OF_ACTION_ID_EXPERIMENTER;
    }
    if (action_id < 0 || action_id >= OF_ACTION_ID_ITEM_COUNT) {
        return OF_OBJECT_INVALID;
    }

    return of_action_id_type_to_id[version][action_id];
}

/**
 * instruction wire type to object ID array.
 * Treat as private; use function accessor below
 */

extern const of_object_id_t *const of_instruction_type_to_id[OF_VERSION_ARRAY_MAX];

#define OF_INSTRUCTION_ITEM_COUNT 7


/**
 * Map an instruction wire value to an OF object
 * @param instruction The instruction type wire value
 * @param version The version associated with the check
 * @return The instruction OF object type
 * @return OF_OBJECT_INVALID if type does not map to an object
 *
 */
of_object_id_t
of_instruction_to_object_id(int instruction, of_version_t version)
{
    if (!OF_VERSION_OKAY(version)) {
        return OF_OBJECT_INVALID;
    }
    if (instruction == OF_EXPERIMENTER_TYPE) {
        return OF_INSTRUCTION_EXPERIMENTER;
    }
    if (instruction < 0 || instruction >= OF_INSTRUCTION_ITEM_COUNT) {
        return OF_OBJECT_INVALID;
    }

    return of_instruction_type_to_id[version][instruction];
}

/**
 * instruction_id wire type to object ID array.
 * Treat as private; use function accessor below
 */

extern const of_object_id_t *const of_instruction_id_type_to_id[OF_VERSION_ARRAY_MAX];

#define OF_INSTRUCTION_ID_ITEM_COUNT 7


/**
 * Map an instruction_id wire value to an OF object
 * @param instruction_id The instruction_id type wire value
 * @param version The version associated with the check
 * @return The instruction_id OF object type
 * @return OF_OBJECT_INVALID if type does not map to an object
 *
 */
of_object_id_t
of_instruction_id_to_object_id(int instruction_id, of_version_t version)
{
    if (!OF_VERSION_OKAY(version)) {
        return OF_OBJECT_INVALID;
    }
    if (instruction_id == OF_EXPERIMENTER_TYPE) {
        return OF_INSTRUCTION_ID_EXPERIMENTER;
    }
    if (instruction_id < 0 || instruction_id >= OF_INSTRUCTION_ID_ITEM_COUNT) {
        return OF_OBJECT_INVALID;
    }

    return of_instruction_id_type_to_id[version][instruction_id];
}

/**
 * queue_prop wire type to object ID array.
 * Treat as private; use function accessor below
 */

extern const of_object_id_t *const of_queue_prop_type_to_id[OF_VERSION_ARRAY_MAX];

#define OF_QUEUE_PROP_ITEM_COUNT 3


/**
 * Map an queue_prop wire value to an OF object
 * @param queue_prop The queue_prop type wire value
 * @param version The version associated with the check
 * @return The queue_prop OF object type
 * @return OF_OBJECT_INVALID if type does not map to an object
 *
 */
of_object_id_t
of_queue_prop_to_object_id(int queue_prop, of_version_t version)
{
    if (!OF_VERSION_OKAY(version)) {
        return OF_OBJECT_INVALID;
    }
    if (queue_prop == OF_EXPERIMENTER_TYPE) {
        return OF_QUEUE_PROP_EXPERIMENTER;
    }
    if (queue_prop < 0 || queue_prop >= OF_QUEUE_PROP_ITEM_COUNT) {
        return OF_OBJECT_INVALID;
    }

    return of_queue_prop_type_to_id[version][queue_prop];
}

/**
 * table_feature_prop wire type to object ID array.
 * Treat as private; use function accessor below
 */

extern const of_object_id_t *const of_table_feature_prop_type_to_id[OF_VERSION_ARRAY_MAX];

#define OF_TABLE_FEATURE_PROP_ITEM_COUNT 16


/**
 * Map an table_feature_prop wire value to an OF object
 * @param table_feature_prop The table_feature_prop type wire value
 * @param version The version associated with the check
 * @return The table_feature_prop OF object type
 * @return OF_OBJECT_INVALID if type does not map to an object
 *
 */
of_object_id_t
of_table_feature_prop_to_object_id(int table_feature_prop, of_version_t version)
{
    if (!OF_VERSION_OKAY(version)) {
        return OF_OBJECT_INVALID;
    }
    if (table_feature_prop == 0xfffe) {
        return OF_TABLE_FEATURE_PROP_EXPERIMENTER;
    }
    if (table_feature_prop == 0xffff) {
        return OF_TABLE_FEATURE_PROP_EXPERIMENTER_MISS;
    }
    if (table_feature_prop < 0 || table_feature_prop >= OF_TABLE_FEATURE_PROP_ITEM_COUNT) {
        return OF_OBJECT_INVALID;
    }

    return of_table_feature_prop_type_to_id[version][table_feature_prop];
}

/**
 * meter_band wire type to object ID array.
 * Treat as private; use function accessor below
 */

extern const of_object_id_t *const of_meter_band_type_to_id[OF_VERSION_ARRAY_MAX];

#define OF_METER_BAND_ITEM_COUNT 3


/**
 * Map an meter_band wire value to an OF object
 * @param meter_band The meter_band type wire value
 * @param version The version associated with the check
 * @return The meter_band OF object type
 * @return OF_OBJECT_INVALID if type does not map to an object
 *
 */
of_object_id_t
of_meter_band_to_object_id(int meter_band, of_version_t version)
{
    if (!OF_VERSION_OKAY(version)) {
        return OF_OBJECT_INVALID;
    }
    if (meter_band == OF_EXPERIMENTER_TYPE) {
        return OF_METER_BAND_EXPERIMENTER;
    }
    if (meter_band < 0 || meter_band >= OF_METER_BAND_ITEM_COUNT) {
        return OF_OBJECT_INVALID;
    }

    return of_meter_band_type_to_id[version][meter_band];
}

/**
 * hello_elem wire type to object ID array.
 * Treat as private; use function accessor below
 */

extern const of_object_id_t *const of_hello_elem_type_to_id[OF_VERSION_ARRAY_MAX];

#define OF_HELLO_ELEM_ITEM_COUNT 2


/**
 * Map an hello_elem wire value to an OF object
 * @param hello_elem The hello_elem type wire value
 * @param version The version associated with the check
 * @return The hello_elem OF object type
 * @return OF_OBJECT_INVALID if type does not map to an object
 *
 */
of_object_id_t
of_hello_elem_to_object_id(int hello_elem, of_version_t version)
{
    if (!OF_VERSION_OKAY(version)) {
        return OF_OBJECT_INVALID;
    }
    if (hello_elem < 0 || hello_elem >= OF_HELLO_ELEM_ITEM_COUNT) {
        return OF_OBJECT_INVALID;
    }

    return of_hello_elem_type_to_id[version][hello_elem];
}

/**
 * stats_reply wire type to object ID array.
 * Treat as private; use function accessor below
 */

extern const of_object_id_t *const of_stats_reply_type_to_id[OF_VERSION_ARRAY_MAX];

#define OF_STATS_REPLY_ITEM_COUNT 14


/**
 * Map an stats_reply wire value to an OF object
 * @param stats_reply The stats_reply type wire value
 * @param version The version associated with the check
 * @return The stats_reply OF object type
 * @return OF_OBJECT_INVALID if type does not map to an object
 *
 */
of_object_id_t
of_stats_reply_to_object_id(int stats_reply, of_version_t version)
{
    if (!OF_VERSION_OKAY(version)) {
        return OF_OBJECT_INVALID;
    }
    if (stats_reply == OF_EXPERIMENTER_TYPE) {
        return OF_EXPERIMENTER_STATS_REPLY;
    }
    if (stats_reply < 0 || stats_reply >= OF_STATS_REPLY_ITEM_COUNT) {
        return OF_OBJECT_INVALID;
    }

    return of_stats_reply_type_to_id[version][stats_reply];
}

/**
 * stats_request wire type to object ID array.
 * Treat as private; use function accessor below
 */

extern const of_object_id_t *const of_stats_request_type_to_id[OF_VERSION_ARRAY_MAX];

#define OF_STATS_REQUEST_ITEM_COUNT 14


/**
 * Map an stats_request wire value to an OF object
 * @param stats_request The stats_request type wire value
 * @param version The version associated with the check
 * @return The stats_request OF object type
 * @return OF_OBJECT_INVALID if type does not map to an object
 *
 */
of_object_id_t
of_stats_request_to_object_id(int stats_request, of_version_t version)
{
    if (!OF_VERSION_OKAY(version)) {
        return OF_OBJECT_INVALID;
    }
    if (stats_request == OF_EXPERIMENTER_TYPE) {
        return OF_EXPERIMENTER_STATS_REQUEST;
    }
    if (stats_request < 0 || stats_request >= OF_STATS_REQUEST_ITEM_COUNT) {
        return OF_OBJECT_INVALID;
    }

    return of_stats_request_type_to_id[version][stats_request];
}

/**
 * error_msg wire type to object ID array.
 * Treat as private; use function accessor below
 */

extern const of_object_id_t *const of_error_msg_type_to_id[OF_VERSION_ARRAY_MAX];

#define OF_ERROR_MSG_ITEM_COUNT 14


/**
 * Map an error_msg wire value to an OF object
 * @param error_msg The error_msg type wire value
 * @param version The version associated with the check
 * @return The error_msg OF object type
 * @return OF_OBJECT_INVALID if type does not map to an object
 *
 */
of_object_id_t
of_error_msg_to_object_id(uint16_t error_msg, of_version_t version)
{
    if (!OF_VERSION_OKAY(version)) {
        return OF_OBJECT_INVALID;
    }
    if (error_msg == OF_EXPERIMENTER_TYPE) {
        return OF_EXPERIMENTER_ERROR_MSG;
    }
    if (error_msg < 0 || error_msg >= OF_ERROR_MSG_ITEM_COUNT) {
        return OF_OBJECT_INVALID;
    }

    return of_error_msg_type_to_id[version][error_msg];
}

/**
 * flow_mod wire type to object ID array.
 * Treat as private; use function accessor below
 */

extern const of_object_id_t *const of_flow_mod_type_to_id[OF_VERSION_ARRAY_MAX];

#define OF_FLOW_MOD_ITEM_COUNT 5


/**
 * Map an flow_mod wire value to an OF object
 * @param flow_mod The flow_mod type wire value
 * @param version The version associated with the check
 * @return The flow_mod OF object type
 * @return OF_OBJECT_INVALID if type does not map to an object
 *
 */
of_object_id_t
of_flow_mod_to_object_id(int flow_mod, of_version_t version)
{
    if (!OF_VERSION_OKAY(version)) {
        return OF_OBJECT_INVALID;
    }
    if (flow_mod < 0 || flow_mod >= OF_FLOW_MOD_ITEM_COUNT) {
        return OF_OBJECT_INVALID;
    }

    return of_flow_mod_type_to_id[version][flow_mod];
}

/**
 * group_mod wire type to object ID array.
 * Treat as private; use function accessor below
 */

extern const of_object_id_t *const of_group_mod_type_to_id[OF_VERSION_ARRAY_MAX];

#define OF_GROUP_MOD_ITEM_COUNT 3


/**
 * Map an group_mod wire value to an OF object
 * @param group_mod The group_mod type wire value
 * @param version The version associated with the check
 * @return The group_mod OF object type
 * @return OF_OBJECT_INVALID if type does not map to an object
 *
 */
of_object_id_t
of_group_mod_to_object_id(int group_mod, of_version_t version)
{
    if (!OF_VERSION_OKAY(version)) {
        return OF_OBJECT_INVALID;
    }
    if (group_mod < 0 || group_mod >= OF_GROUP_MOD_ITEM_COUNT) {
        return OF_OBJECT_INVALID;
    }

    return of_group_mod_type_to_id[version][group_mod];
}

/* NOTE: We could optimize the OXM and only generate OF 1.2 versions. */

/**
 * oxm wire type to object ID array.
 * Treat as private; use function accessor below
 */

extern const of_object_id_t *const of_oxm_type_to_id[OF_VERSION_ARRAY_MAX];

#define OF_OXM_ITEM_COUNT 72


/**
 * Map an oxm wire value to an OF object
 * @param oxm The oxm type wire value
 * @param version The version associated with the check
 * @return The oxm OF object type
 * @return OF_OBJECT_INVALID if type does not map to an object
 *
 */
of_object_id_t
of_oxm_to_object_id(uint32_t type_len, of_version_t version)
{
    if (!OF_VERSION_OKAY(version)) {
        return OF_OBJECT_INVALID;
    }

    uint16_t class = (type_len >> 16) & 0xffff;
    uint8_t masked_type = (type_len >> 8) & 0xff;

    if (class == 0x8000) {
        if (masked_type < 0 || masked_type >= OF_OXM_ITEM_COUNT) {
            return OF_OBJECT_INVALID;
        }

        return of_oxm_type_to_id[version][masked_type];
    } else if (class == 0x0003) {
        switch (masked_type) {
        case 0x00: return OF_OXM_BSN_IN_PORTS_128;
        case 0x01: return OF_OXM_BSN_IN_PORTS_128_MASKED;
        case 0x02: return OF_OXM_BSN_LAG_ID;
        case 0x03: return OF_OXM_BSN_LAG_ID_MASKED;
        case 0x04: return OF_OXM_BSN_VRF;
        case 0x05: return OF_OXM_BSN_VRF_MASKED;
        case 0x06: return OF_OXM_BSN_GLOBAL_VRF_ALLOWED;
        case 0x07: return OF_OXM_BSN_GLOBAL_VRF_ALLOWED_MASKED;
        case 0x08: return OF_OXM_BSN_L3_INTERFACE_CLASS_ID;
        case 0x09: return OF_OXM_BSN_L3_INTERFACE_CLASS_ID_MASKED;
        case 0x0a: return OF_OXM_BSN_L3_SRC_CLASS_ID;
        case 0x0b: return OF_OXM_BSN_L3_SRC_CLASS_ID_MASKED;
        case 0x0c: return OF_OXM_BSN_L3_DST_CLASS_ID;
        case 0x0d: return OF_OXM_BSN_L3_DST_CLASS_ID_MASKED;
        case 0x10: return OF_OXM_BSN_UDF0;
        case 0x11: return OF_OXM_BSN_UDF0_MASKED;
        case 0x12: return OF_OXM_BSN_UDF1;
        case 0x13: return OF_OXM_BSN_UDF1_MASKED;
        case 0x14: return OF_OXM_BSN_UDF2;
        case 0x15: return OF_OXM_BSN_UDF2_MASKED;
        case 0x16: return OF_OXM_BSN_UDF3;
        case 0x17: return OF_OXM_BSN_UDF3_MASKED;
        case 0x18: return OF_OXM_BSN_UDF4;
        case 0x19: return OF_OXM_BSN_UDF4_MASKED;
        case 0x1a: return OF_OXM_BSN_UDF5;
        case 0x1b: return OF_OXM_BSN_UDF5_MASKED;
        case 0x1c: return OF_OXM_BSN_UDF6;
        case 0x1d: return OF_OXM_BSN_UDF6_MASKED;
        case 0x1e: return OF_OXM_BSN_UDF7;
        case 0x1f: return OF_OXM_BSN_UDF7_MASKED;
        default: return OF_OBJECT_INVALID;
        }
    } else {
        return OF_OBJECT_INVALID;
    }
}

/**
 * @brief Map a message known to be an exp msg to the proper object
 *
 * Assume that the message is a vendor/experimenter message.  Determine
 * the specific object type for the message.
 * @param msg An OF message object (uint8_t *)
 * @param length The number of bytes in the message (for error checking)
 * @param version Version of message
 * @returns object ID of specific type if recognized or OF_EXPERIMENTER if not
 *
 * @todo put OF_EXPERIMENTER_<name> in loci_base.h
 */

of_object_id_t
of_message_experimenter_to_object_id(of_message_t msg, of_version_t version) {
    uint32_t experimenter_id;
    uint32_t subtype;

    /* Extract experimenter and subtype value; look for match from type maps */
    experimenter_id = of_message_experimenter_id_get(msg);
    subtype = of_message_experimenter_subtype_get(msg);

    /* Do a simple if/else search for the ver, experimenter and subtype */

    if ((experimenter_id == OF_EXPERIMENTER_ID_NICIRA) &&
            (version == OF_VERSION_1_0)) {

        if (subtype == 10) {
            return OF_NICIRA_CONTROLLER_ROLE_REQUEST;
        }

        if (subtype == 11) {
            return OF_NICIRA_CONTROLLER_ROLE_REPLY;
        }

    }

    if ((experimenter_id == OF_EXPERIMENTER_ID_BSN) &&
            (version == OF_VERSION_1_0)) {

        if (subtype == 9) {
            return OF_BSN_GET_INTERFACES_REQUEST;
        }

        if (subtype == 1) {
            return OF_BSN_GET_IP_MASK_REQUEST;
        }

        if (subtype == 34) {
            return OF_BSN_PDU_RX_REPLY;
        }

        if (subtype == 22) {
            return OF_BSN_BW_CLEAR_DATA_REPLY;
        }

        if (subtype == 25) {
            return OF_BSN_SET_PKTIN_SUPPRESSION_REPLY;
        }

        if (subtype == 28) {
            return OF_BSN_HYBRID_GET_REPLY;
        }

        if (subtype == 14) {
            return OF_BSN_GET_L2_TABLE_REPLY;
        }

        if (subtype == 26) {
            return OF_BSN_VIRTUAL_PORT_REMOVE_REPLY;
        }

        if (subtype == 11) {
            return OF_BSN_SET_PKTIN_SUPPRESSION_REQUEST;
        }

        if (subtype == 7) {
            return OF_BSN_SHELL_OUTPUT;
        }

        if (subtype == 6) {
            return OF_BSN_SHELL_COMMAND;
        }

        if (subtype == 5) {
            return OF_BSN_GET_MIRRORING_REPLY;
        }

        if (subtype == 13) {
            return OF_BSN_GET_L2_TABLE_REQUEST;
        }

        if (subtype == 32) {
            return OF_BSN_PDU_TX_REPLY;
        }

        if (subtype == 20) {
            return OF_BSN_BW_ENABLE_GET_REPLY;
        }

        if (subtype == 23) {
            return OF_BSN_BW_ENABLE_SET_REPLY;
        }

        if (subtype == 17) {
            return OF_BSN_VIRTUAL_PORT_REMOVE_REQUEST;
        }

        if (subtype == 8) {
            return OF_BSN_SHELL_STATUS;
        }

        if (subtype == 10) {
            return OF_BSN_GET_INTERFACES_REPLY;
        }

        if (subtype == 24) {
            return OF_BSN_SET_L2_TABLE_REPLY;
        }

        if (subtype == 2) {
            return OF_BSN_GET_IP_MASK_REPLY;
        }

        if (subtype == 21) {
            return OF_BSN_BW_CLEAR_DATA_REQUEST;
        }

        if (subtype == 0) {
            return OF_BSN_SET_IP_MASK;
        }

        if (subtype == 35) {
            return OF_BSN_PDU_RX_TIMEOUT;
        }

        if (subtype == 33) {
            return OF_BSN_PDU_RX_REQUEST;
        }

        if (subtype == 15) {
            return OF_BSN_VIRTUAL_PORT_CREATE_REQUEST;
        }

        if (subtype == 3) {
            return OF_BSN_SET_MIRRORING;
        }

        if (subtype == 31) {
            return OF_BSN_PDU_TX_REQUEST;
        }

        if (subtype == 16) {
            return OF_BSN_VIRTUAL_PORT_CREATE_REPLY;
        }

        if (subtype == 18) {
            return OF_BSN_BW_ENABLE_SET_REQUEST;
        }

        if (subtype == 4) {
            return OF_BSN_GET_MIRRORING_REQUEST;
        }

        if (subtype == 19) {
            return OF_BSN_BW_ENABLE_GET_REQUEST;
        }

        if (subtype == 12) {
            return OF_BSN_SET_L2_TABLE_REQUEST;
        }

        if (subtype == 27) {
            return OF_BSN_HYBRID_GET_REQUEST;
        }

    }

    if ((experimenter_id == OF_EXPERIMENTER_ID_BSN) &&
            (version == OF_VERSION_1_1)) {

        if (subtype == 9) {
            return OF_BSN_GET_INTERFACES_REQUEST;
        }

        if (subtype == 34) {
            return OF_BSN_PDU_RX_REPLY;
        }

        if (subtype == 22) {
            return OF_BSN_BW_CLEAR_DATA_REPLY;
        }

        if (subtype == 25) {
            return OF_BSN_SET_PKTIN_SUPPRESSION_REPLY;
        }

        if (subtype == 16) {
            return OF_BSN_VIRTUAL_PORT_CREATE_REPLY;
        }

        if (subtype == 11) {
            return OF_BSN_SET_PKTIN_SUPPRESSION_REQUEST;
        }

        if (subtype == 5) {
            return OF_BSN_GET_MIRRORING_REPLY;
        }

        if (subtype == 32) {
            return OF_BSN_PDU_TX_REPLY;
        }

        if (subtype == 20) {
            return OF_BSN_BW_ENABLE_GET_REPLY;
        }

        if (subtype == 23) {
            return OF_BSN_BW_ENABLE_SET_REPLY;
        }

        if (subtype == 17) {
            return OF_BSN_VIRTUAL_PORT_REMOVE_REQUEST;
        }

        if (subtype == 10) {
            return OF_BSN_GET_INTERFACES_REPLY;
        }

        if (subtype == 3) {
            return OF_BSN_SET_MIRRORING;
        }

        if (subtype == 21) {
            return OF_BSN_BW_CLEAR_DATA_REQUEST;
        }

        if (subtype == 35) {
            return OF_BSN_PDU_RX_TIMEOUT;
        }

        if (subtype == 33) {
            return OF_BSN_PDU_RX_REQUEST;
        }

        if (subtype == 15) {
            return OF_BSN_VIRTUAL_PORT_CREATE_REQUEST;
        }

        if (subtype == 31) {
            return OF_BSN_PDU_TX_REQUEST;
        }

        if (subtype == 26) {
            return OF_BSN_VIRTUAL_PORT_REMOVE_REPLY;
        }

        if (subtype == 18) {
            return OF_BSN_BW_ENABLE_SET_REQUEST;
        }

        if (subtype == 19) {
            return OF_BSN_BW_ENABLE_GET_REQUEST;
        }

        if (subtype == 4) {
            return OF_BSN_GET_MIRRORING_REQUEST;
        }

    }

    if ((experimenter_id == OF_EXPERIMENTER_ID_BSN) &&
            (version == OF_VERSION_1_2)) {

        if (subtype == 9) {
            return OF_BSN_GET_INTERFACES_REQUEST;
        }

        if (subtype == 34) {
            return OF_BSN_PDU_RX_REPLY;
        }

        if (subtype == 22) {
            return OF_BSN_BW_CLEAR_DATA_REPLY;
        }

        if (subtype == 25) {
            return OF_BSN_SET_PKTIN_SUPPRESSION_REPLY;
        }

        if (subtype == 16) {
            return OF_BSN_VIRTUAL_PORT_CREATE_REPLY;
        }

        if (subtype == 11) {
            return OF_BSN_SET_PKTIN_SUPPRESSION_REQUEST;
        }

        if (subtype == 5) {
            return OF_BSN_GET_MIRRORING_REPLY;
        }

        if (subtype == 32) {
            return OF_BSN_PDU_TX_REPLY;
        }

        if (subtype == 20) {
            return OF_BSN_BW_ENABLE_GET_REPLY;
        }

        if (subtype == 23) {
            return OF_BSN_BW_ENABLE_SET_REPLY;
        }

        if (subtype == 17) {
            return OF_BSN_VIRTUAL_PORT_REMOVE_REQUEST;
        }

        if (subtype == 10) {
            return OF_BSN_GET_INTERFACES_REPLY;
        }

        if (subtype == 3) {
            return OF_BSN_SET_MIRRORING;
        }

        if (subtype == 21) {
            return OF_BSN_BW_CLEAR_DATA_REQUEST;
        }

        if (subtype == 35) {
            return OF_BSN_PDU_RX_TIMEOUT;
        }

        if (subtype == 33) {
            return OF_BSN_PDU_RX_REQUEST;
        }

        if (subtype == 15) {
            return OF_BSN_VIRTUAL_PORT_CREATE_REQUEST;
        }

        if (subtype == 31) {
            return OF_BSN_PDU_TX_REQUEST;
        }

        if (subtype == 26) {
            return OF_BSN_VIRTUAL_PORT_REMOVE_REPLY;
        }

        if (subtype == 18) {
            return OF_BSN_BW_ENABLE_SET_REQUEST;
        }

        if (subtype == 19) {
            return OF_BSN_BW_ENABLE_GET_REQUEST;
        }

        if (subtype == 4) {
            return OF_BSN_GET_MIRRORING_REQUEST;
        }

    }

    if ((experimenter_id == OF_EXPERIMENTER_ID_BSN) &&
            (version == OF_VERSION_1_3)) {

        if (subtype == 43) {
            return OF_BSN_LACP_CONVERGENCE_NOTIF;
        }

        if (subtype == 9) {
            return OF_BSN_GET_INTERFACES_REQUEST;
        }

        if (subtype == 50) {
            return OF_BSN_GENTABLE_SET_BUCKETS_SIZE;
        }

        if (subtype == 17) {
            return OF_BSN_VIRTUAL_PORT_REMOVE_REQUEST;
        }

        if (subtype == 34) {
            return OF_BSN_PDU_RX_REPLY;
        }

        if (subtype == 22) {
            return OF_BSN_BW_CLEAR_DATA_REPLY;
        }

        if (subtype == 25) {
            return OF_BSN_SET_PKTIN_SUPPRESSION_REPLY;
        }

        if (subtype == 45) {
            return OF_BSN_TIME_REPLY;
        }

        if (subtype == 49) {
            return OF_BSN_GENTABLE_CLEAR_REPLY;
        }

        if (subtype == 16) {
            return OF_BSN_VIRTUAL_PORT_CREATE_REPLY;
        }

        if (subtype == 41) {
            return OF_BSN_SET_LACP_REQUEST;
        }

        if (subtype == 11) {
            return OF_BSN_SET_PKTIN_SUPPRESSION_REQUEST;
        }

        if (subtype == 5) {
            return OF_BSN_GET_MIRRORING_REPLY;
        }

        if (subtype == 36) {
            return OF_BSN_FLOW_IDLE_ENABLE_SET_REQUEST;
        }

        if (subtype == 32) {
            return OF_BSN_PDU_TX_REPLY;
        }

        if (subtype == 15) {
            return OF_BSN_VIRTUAL_PORT_CREATE_REQUEST;
        }

        if (subtype == 38) {
            return OF_BSN_FLOW_IDLE_ENABLE_GET_REQUEST;
        }

        if (subtype == 20) {
            return OF_BSN_BW_ENABLE_GET_REPLY;
        }

        if (subtype == 23) {
            return OF_BSN_BW_ENABLE_SET_REPLY;
        }

        if (subtype == 44) {
            return OF_BSN_TIME_REQUEST;
        }

        if (subtype == 10) {
            return OF_BSN_GET_INTERFACES_REPLY;
        }

        if (subtype == 3) {
            return OF_BSN_SET_MIRRORING;
        }

        if (subtype == 61) {
            return OF_BSN_TABLE_SET_BUCKETS_SIZE;
        }

        if (subtype == 56) {
            return OF_BSN_CONTROLLER_CONNECTIONS_REQUEST;
        }

        if (subtype == 59) {
            return OF_BSN_SET_AUX_CXNS_REPLY;
        }

        if (subtype == 21) {
            return OF_BSN_BW_CLEAR_DATA_REQUEST;
        }

        if (subtype == 60) {
            return OF_BSN_ARP_IDLE;
        }

        if (subtype == 53) {
            return OF_BSN_SET_SWITCH_PIPELINE_REQUEST;
        }

        if (subtype == 35) {
            return OF_BSN_PDU_RX_TIMEOUT;
        }

        if (subtype == 48) {
            return OF_BSN_GENTABLE_CLEAR_REQUEST;
        }

        if (subtype == 33) {
            return OF_BSN_PDU_RX_REQUEST;
        }

        if (subtype == 51) {
            return OF_BSN_GET_SWITCH_PIPELINE_REQUEST;
        }

        if (subtype == 54) {
            return OF_BSN_SET_SWITCH_PIPELINE_REPLY;
        }

        if (subtype == 26) {
            return OF_BSN_VIRTUAL_PORT_REMOVE_REPLY;
        }

        if (subtype == 47) {
            return OF_BSN_GENTABLE_ENTRY_DELETE;
        }

        if (subtype == 39) {
            return OF_BSN_FLOW_IDLE_ENABLE_GET_REPLY;
        }

        if (subtype == 31) {
            return OF_BSN_PDU_TX_REQUEST;
        }

        if (subtype == 42) {
            return OF_BSN_SET_LACP_REPLY;
        }

        if (subtype == 52) {
            return OF_BSN_GET_SWITCH_PIPELINE_REPLY;
        }

        if (subtype == 18) {
            return OF_BSN_BW_ENABLE_SET_REQUEST;
        }

        if (subtype == 4) {
            return OF_BSN_GET_MIRRORING_REQUEST;
        }

        if (subtype == 37) {
            return OF_BSN_FLOW_IDLE_ENABLE_SET_REPLY;
        }

        if (subtype == 40) {
            return OF_BSN_FLOW_IDLE;
        }

        if (subtype == 19) {
            return OF_BSN_BW_ENABLE_GET_REQUEST;
        }

        if (subtype == 46) {
            return OF_BSN_GENTABLE_ENTRY_ADD;
        }

        if (subtype == 58) {
            return OF_BSN_SET_AUX_CXNS_REQUEST;
        }

        if (subtype == 57) {
            return OF_BSN_CONTROLLER_CONNECTIONS_REPLY;
        }

        if (subtype == 55) {
            return OF_BSN_ROLE_STATUS;
        }

    }

    return OF_EXPERIMENTER;
}

/**
 * message wire type to object ID array.
 * Treat as private; use function accessor below
 */

extern const of_object_id_t *const of_message_type_to_id[OF_VERSION_ARRAY_MAX];

#define OF_MESSAGE_ITEM_COUNT 30


/**
 * Extract the type info from the message and determine its object type
 * @param msg An OF message object (uint8_t *)
 * @param length The number of bytes in the message (for error checking)
 * @returns object ID or OF_OBJECT_INVALID if parse error
 */

of_object_id_t
of_message_to_object_id(of_message_t msg, int length) {
    uint8_t type;
    of_version_t ver;
    of_object_id_t obj_id;
    uint16_t stats_type;
    uint16_t err_type;
    uint8_t flow_mod_cmd;
    uint32_t experimenter, subtype;
    uint16_t group_mod_cmd;

    if (length < OF_MESSAGE_MIN_LENGTH) {
        return OF_OBJECT_INVALID;
    }
    type = of_message_type_get(msg);
    ver = of_message_version_get(msg);
    if (!OF_VERSION_OKAY(ver)) {
        return OF_OBJECT_INVALID;
    }

    if (type >= OF_MESSAGE_ITEM_COUNT) {
        return OF_OBJECT_INVALID;
    }

    obj_id = of_message_type_to_id[ver][type];

    /* Remap to specific message if known */
    if (obj_id == OF_EXPERIMENTER) {
        if (length < OF_MESSAGE_EXPERIMENTER_MIN_LENGTH) {
            return OF_OBJECT_INVALID;
        }
        return of_message_experimenter_to_object_id(msg, ver);
    }

    /* Remap to add/delete/strict version */
    if (obj_id == OF_FLOW_MOD) {
        if (length < OF_MESSAGE_MIN_FLOW_MOD_LENGTH(ver)) {
            return OF_OBJECT_INVALID;
        }
        flow_mod_cmd = of_message_flow_mod_command_get(msg, ver);
        obj_id = of_flow_mod_to_object_id(flow_mod_cmd, ver);
    }

    if ((obj_id == OF_STATS_REQUEST) || (obj_id == OF_STATS_REPLY)) {
        if (length < OF_MESSAGE_MIN_STATS_LENGTH) {
            return OF_OBJECT_INVALID;
        }
        stats_type = of_message_stats_type_get(msg);
        if (stats_type == OF_STATS_TYPE_EXPERIMENTER) {
            if (length < OF_MESSAGE_STATS_EXPERIMENTER_MIN_LENGTH) {
                return OF_OBJECT_INVALID;
            }
            experimenter = of_message_stats_experimenter_id_get(msg);
            subtype = of_message_stats_experimenter_subtype_get(msg);
            if (obj_id == OF_STATS_REQUEST) {
                obj_id = of_experimenter_stats_request_to_object_id(experimenter, subtype, ver);
            } else {
                obj_id = of_experimenter_stats_reply_to_object_id(experimenter, subtype, ver);
            }
        } else {
            if (obj_id == OF_STATS_REQUEST) {
                obj_id = of_stats_request_to_object_id(stats_type, ver);
            } else {
                obj_id = of_stats_reply_to_object_id(stats_type, ver);
            }
        }
    }

    if (obj_id == OF_ERROR_MSG) {
        if (length < OF_MESSAGE_MIN_ERROR_LENGTH) {
            return OF_OBJECT_INVALID;
        }
        err_type = of_message_error_type_get(msg);
        obj_id = of_error_msg_to_object_id(err_type, ver);
    }

    if (obj_id == OF_GROUP_MOD) {
        if (length < OF_MESSAGE_MIN_GROUP_MOD_LENGTH) {
            return OF_OBJECT_INVALID;
        }
        group_mod_cmd = of_message_group_mod_command_get(msg);
        obj_id = of_group_mod_to_object_id(group_mod_cmd, ver);
    }

    return obj_id;
}

/**
 * bsn_tlv wire type to object ID array.
 * Treat as private; use function accessor below
 */

extern const of_object_id_t *const of_bsn_tlv_type_to_id[OF_VERSION_ARRAY_MAX];

#define OF_BSN_TLV_ITEM_COUNT 20


/**
 * Map an bsn_tlv wire value to an OF object
 * @param bsn_tlv The bsn_tlv type wire value
 * @param version The version associated with the check
 * @return The bsn_tlv OF object type
 * @return OF_OBJECT_INVALID if type does not map to an object
 *
 */
of_object_id_t
of_bsn_tlv_to_object_id(int bsn_tlv, of_version_t version)
{
    if (!OF_VERSION_OKAY(version)) {
        return OF_OBJECT_INVALID;
    }
    if (bsn_tlv < 0 || bsn_tlv >= OF_BSN_TLV_ITEM_COUNT) {
        return OF_OBJECT_INVALID;
    }

    return of_bsn_tlv_type_to_id[version][bsn_tlv];
}
static const of_object_id_t
of_error_msg_type_to_id_v1[OF_ERROR_MSG_ITEM_COUNT] = {
    OF_HELLO_FAILED_ERROR_MSG,     /* 0 */
    OF_BAD_REQUEST_ERROR_MSG,      /* 1 */
    OF_BAD_ACTION_ERROR_MSG,       /* 2 */
    OF_FLOW_MOD_FAILED_ERROR_MSG,  /* 3 */
    OF_PORT_MOD_FAILED_ERROR_MSG,  /* 4 */
    OF_QUEUE_OP_FAILED_ERROR_MSG,  /* 5 */
    OF_OBJECT_INVALID,             /* 6 (Invalid) */
    OF_OBJECT_INVALID,             /* 7 (Invalid) */
    OF_OBJECT_INVALID,             /* 8 (Invalid) */
    OF_OBJECT_INVALID,             /* 9 (Invalid) */
    OF_OBJECT_INVALID,             /* 10 (Invalid) */
    OF_OBJECT_INVALID,             /* 11 (Invalid) */
    OF_OBJECT_INVALID,             /* 12 (Invalid) */
    OF_OBJECT_INVALID              /* 13 (Invalid) */
};
static const of_object_id_t
of_error_msg_type_to_id_v2[OF_ERROR_MSG_ITEM_COUNT] = {
    OF_HELLO_FAILED_ERROR_MSG,     /* 0 */
    OF_BAD_REQUEST_ERROR_MSG,      /* 1 */
    OF_BAD_ACTION_ERROR_MSG,       /* 2 */
    OF_BAD_INSTRUCTION_ERROR_MSG,  /* 3 */
    OF_BAD_MATCH_ERROR_MSG,        /* 4 */
    OF_FLOW_MOD_FAILED_ERROR_MSG,  /* 5 */
    OF_GROUP_MOD_FAILED_ERROR_MSG, /* 6 */
    OF_PORT_MOD_FAILED_ERROR_MSG,  /* 7 */
    OF_TABLE_MOD_FAILED_ERROR_MSG, /* 8 */
    OF_QUEUE_OP_FAILED_ERROR_MSG,  /* 9 */
    OF_SWITCH_CONFIG_FAILED_ERROR_MSG, /* 10 */
    OF_OBJECT_INVALID,             /* 11 (Invalid) */
    OF_OBJECT_INVALID,             /* 12 (Invalid) */
    OF_OBJECT_INVALID              /* 13 (Invalid) */
};
static const of_object_id_t
of_error_msg_type_to_id_v3[OF_ERROR_MSG_ITEM_COUNT] = {
    OF_HELLO_FAILED_ERROR_MSG,     /* 0 */
    OF_BAD_REQUEST_ERROR_MSG,      /* 1 */
    OF_BAD_ACTION_ERROR_MSG,       /* 2 */
    OF_BAD_INSTRUCTION_ERROR_MSG,  /* 3 */
    OF_BAD_MATCH_ERROR_MSG,        /* 4 */
    OF_FLOW_MOD_FAILED_ERROR_MSG,  /* 5 */
    OF_GROUP_MOD_FAILED_ERROR_MSG, /* 6 */
    OF_PORT_MOD_FAILED_ERROR_MSG,  /* 7 */
    OF_TABLE_MOD_FAILED_ERROR_MSG, /* 8 */
    OF_QUEUE_OP_FAILED_ERROR_MSG,  /* 9 */
    OF_SWITCH_CONFIG_FAILED_ERROR_MSG, /* 10 */
    OF_ROLE_REQUEST_FAILED_ERROR_MSG, /* 11 */
    OF_OBJECT_INVALID,             /* 12 (Invalid) */
    OF_OBJECT_INVALID              /* 13 (Invalid) */
};
static const of_object_id_t
of_error_msg_type_to_id_v4[OF_ERROR_MSG_ITEM_COUNT] = {
    OF_HELLO_FAILED_ERROR_MSG,     /* 0 */
    OF_BAD_REQUEST_ERROR_MSG,      /* 1 */
    OF_BAD_ACTION_ERROR_MSG,       /* 2 */
    OF_BAD_INSTRUCTION_ERROR_MSG,  /* 3 */
    OF_BAD_MATCH_ERROR_MSG,        /* 4 */
    OF_FLOW_MOD_FAILED_ERROR_MSG,  /* 5 */
    OF_GROUP_MOD_FAILED_ERROR_MSG, /* 6 */
    OF_PORT_MOD_FAILED_ERROR_MSG,  /* 7 */
    OF_TABLE_MOD_FAILED_ERROR_MSG, /* 8 */
    OF_QUEUE_OP_FAILED_ERROR_MSG,  /* 9 */
    OF_SWITCH_CONFIG_FAILED_ERROR_MSG, /* 10 */
    OF_ROLE_REQUEST_FAILED_ERROR_MSG, /* 11 */
    OF_METER_MOD_FAILED_ERROR_MSG, /* 12 */
    OF_TABLE_FEATURES_FAILED_ERROR_MSG /* 13 */
};

/**
 * Maps from of_error_msg wire type values to LOCI object ids
 *
 * Indexed by wire version which is 1-based.
 */

const of_object_id_t *const of_error_msg_type_to_id[OF_VERSION_ARRAY_MAX] = {
    NULL,
    of_error_msg_type_to_id_v1,
    of_error_msg_type_to_id_v2,
    of_error_msg_type_to_id_v3,
    of_error_msg_type_to_id_v4,

};

static const of_object_id_t
of_action_type_to_id_v1[OF_ACTION_ITEM_COUNT] = {
    OF_ACTION_OUTPUT,              /* 0 */
    OF_ACTION_SET_VLAN_VID,        /* 1 */
    OF_ACTION_SET_VLAN_PCP,        /* 2 */
    OF_ACTION_STRIP_VLAN,          /* 3 */
    OF_ACTION_SET_DL_SRC,          /* 4 */
    OF_ACTION_SET_DL_DST,          /* 5 */
    OF_ACTION_SET_NW_SRC,          /* 6 */
    OF_ACTION_SET_NW_DST,          /* 7 */
    OF_ACTION_SET_NW_TOS,          /* 8 */
    OF_ACTION_SET_TP_SRC,          /* 9 */
    OF_ACTION_SET_TP_DST,          /* 10 */
    OF_ACTION_ENQUEUE,             /* 11 */
    OF_OBJECT_INVALID,             /* 12 (Invalid) */
    OF_OBJECT_INVALID,             /* 13 (Invalid) */
    OF_OBJECT_INVALID,             /* 14 (Invalid) */
    OF_OBJECT_INVALID,             /* 15 (Invalid) */
    OF_OBJECT_INVALID,             /* 16 (Invalid) */
    OF_OBJECT_INVALID,             /* 17 (Invalid) */
    OF_OBJECT_INVALID,             /* 18 (Invalid) */
    OF_OBJECT_INVALID,             /* 19 (Invalid) */
    OF_OBJECT_INVALID,             /* 20 (Invalid) */
    OF_OBJECT_INVALID,             /* 21 (Invalid) */
    OF_OBJECT_INVALID,             /* 22 (Invalid) */
    OF_OBJECT_INVALID,             /* 23 (Invalid) */
    OF_OBJECT_INVALID,             /* 24 (Invalid) */
    OF_OBJECT_INVALID,             /* 25 (Invalid) */
    OF_OBJECT_INVALID,             /* 26 (Invalid) */
    OF_OBJECT_INVALID              /* 27 (Invalid) */
};
static const of_object_id_t
of_action_type_to_id_v2[OF_ACTION_ITEM_COUNT] = {
    OF_ACTION_OUTPUT,              /* 0 */
    OF_ACTION_SET_VLAN_VID,        /* 1 */
    OF_ACTION_SET_VLAN_PCP,        /* 2 */
    OF_ACTION_SET_DL_SRC,          /* 3 */
    OF_ACTION_SET_DL_DST,          /* 4 */
    OF_ACTION_SET_NW_SRC,          /* 5 */
    OF_ACTION_SET_NW_DST,          /* 6 */
    OF_ACTION_SET_NW_TOS,          /* 7 */
    OF_ACTION_SET_NW_ECN,          /* 8 */
    OF_ACTION_SET_TP_SRC,          /* 9 */
    OF_ACTION_SET_TP_DST,          /* 10 */
    OF_ACTION_COPY_TTL_OUT,        /* 11 */
    OF_ACTION_COPY_TTL_IN,         /* 12 */
    OF_ACTION_SET_MPLS_LABEL,      /* 13 */
    OF_ACTION_SET_MPLS_TC,         /* 14 */
    OF_ACTION_SET_MPLS_TTL,        /* 15 */
    OF_ACTION_DEC_MPLS_TTL,        /* 16 */
    OF_ACTION_PUSH_VLAN,           /* 17 */
    OF_ACTION_POP_VLAN,            /* 18 */
    OF_ACTION_PUSH_MPLS,           /* 19 */
    OF_ACTION_POP_MPLS,            /* 20 */
    OF_ACTION_SET_QUEUE,           /* 21 */
    OF_ACTION_GROUP,               /* 22 */
    OF_ACTION_SET_NW_TTL,          /* 23 */
    OF_ACTION_DEC_NW_TTL,          /* 24 */
    OF_OBJECT_INVALID,             /* 25 (Invalid) */
    OF_OBJECT_INVALID,             /* 26 (Invalid) */
    OF_OBJECT_INVALID              /* 27 (Invalid) */
};
static const of_object_id_t
of_action_type_to_id_v3[OF_ACTION_ITEM_COUNT] = {
    OF_ACTION_OUTPUT,              /* 0 */
    OF_OBJECT_INVALID,             /* 1 (Invalid) */
    OF_OBJECT_INVALID,             /* 2 (Invalid) */
    OF_OBJECT_INVALID,             /* 3 (Invalid) */
    OF_OBJECT_INVALID,             /* 4 (Invalid) */
    OF_OBJECT_INVALID,             /* 5 (Invalid) */
    OF_OBJECT_INVALID,             /* 6 (Invalid) */
    OF_OBJECT_INVALID,             /* 7 (Invalid) */
    OF_OBJECT_INVALID,             /* 8 (Invalid) */
    OF_OBJECT_INVALID,             /* 9 (Invalid) */
    OF_OBJECT_INVALID,             /* 10 (Invalid) */
    OF_ACTION_COPY_TTL_OUT,        /* 11 */
    OF_ACTION_COPY_TTL_IN,         /* 12 */
    OF_OBJECT_INVALID,             /* 13 (Invalid) */
    OF_OBJECT_INVALID,             /* 14 (Invalid) */
    OF_ACTION_SET_MPLS_TTL,        /* 15 */
    OF_ACTION_DEC_MPLS_TTL,        /* 16 */
    OF_ACTION_PUSH_VLAN,           /* 17 */
    OF_ACTION_POP_VLAN,            /* 18 */
    OF_ACTION_PUSH_MPLS,           /* 19 */
    OF_ACTION_POP_MPLS,            /* 20 */
    OF_ACTION_SET_QUEUE,           /* 21 */
    OF_ACTION_GROUP,               /* 22 */
    OF_ACTION_SET_NW_TTL,          /* 23 */
    OF_ACTION_DEC_NW_TTL,          /* 24 */
    OF_ACTION_SET_FIELD,           /* 25 */
    OF_OBJECT_INVALID,             /* 26 (Invalid) */
    OF_OBJECT_INVALID              /* 27 (Invalid) */
};
static const of_object_id_t
of_action_type_to_id_v4[OF_ACTION_ITEM_COUNT] = {
    OF_ACTION_OUTPUT,              /* 0 */
    OF_OBJECT_INVALID,             /* 1 (Invalid) */
    OF_OBJECT_INVALID,             /* 2 (Invalid) */
    OF_OBJECT_INVALID,             /* 3 (Invalid) */
    OF_OBJECT_INVALID,             /* 4 (Invalid) */
    OF_OBJECT_INVALID,             /* 5 (Invalid) */
    OF_OBJECT_INVALID,             /* 6 (Invalid) */
    OF_OBJECT_INVALID,             /* 7 (Invalid) */
    OF_OBJECT_INVALID,             /* 8 (Invalid) */
    OF_OBJECT_INVALID,             /* 9 (Invalid) */
    OF_OBJECT_INVALID,             /* 10 (Invalid) */
    OF_ACTION_COPY_TTL_OUT,        /* 11 */
    OF_ACTION_COPY_TTL_IN,         /* 12 */
    OF_OBJECT_INVALID,             /* 13 (Invalid) */
    OF_OBJECT_INVALID,             /* 14 (Invalid) */
    OF_ACTION_SET_MPLS_TTL,        /* 15 */
    OF_ACTION_DEC_MPLS_TTL,        /* 16 */
    OF_ACTION_PUSH_VLAN,           /* 17 */
    OF_ACTION_POP_VLAN,            /* 18 */
    OF_ACTION_PUSH_MPLS,           /* 19 */
    OF_ACTION_POP_MPLS,            /* 20 */
    OF_ACTION_SET_QUEUE,           /* 21 */
    OF_ACTION_GROUP,               /* 22 */
    OF_ACTION_SET_NW_TTL,          /* 23 */
    OF_ACTION_DEC_NW_TTL,          /* 24 */
    OF_ACTION_SET_FIELD,           /* 25 */
    OF_ACTION_PUSH_PBB,            /* 26 */
    OF_ACTION_POP_PBB              /* 27 */
};

/**
 * Maps from of_action wire type values to LOCI object ids
 *
 * Indexed by wire version which is 1-based.
 */

const of_object_id_t *const of_action_type_to_id[OF_VERSION_ARRAY_MAX] = {
    NULL,
    of_action_type_to_id_v1,
    of_action_type_to_id_v2,
    of_action_type_to_id_v3,
    of_action_type_to_id_v4,

};

static const of_object_id_t
of_action_id_type_to_id_v1[OF_ACTION_ID_ITEM_COUNT] = {
    OF_OBJECT_INVALID,             /* 0 (Invalid) */
    OF_OBJECT_INVALID,             /* 1 (Invalid) */
    OF_OBJECT_INVALID,             /* 2 (Invalid) */
    OF_OBJECT_INVALID,             /* 3 (Invalid) */
    OF_OBJECT_INVALID,             /* 4 (Invalid) */
    OF_OBJECT_INVALID,             /* 5 (Invalid) */
    OF_OBJECT_INVALID,             /* 6 (Invalid) */
    OF_OBJECT_INVALID,             /* 7 (Invalid) */
    OF_OBJECT_INVALID,             /* 8 (Invalid) */
    OF_OBJECT_INVALID,             /* 9 (Invalid) */
    OF_OBJECT_INVALID,             /* 10 (Invalid) */
    OF_OBJECT_INVALID,             /* 11 (Invalid) */
    OF_OBJECT_INVALID,             /* 12 (Invalid) */
    OF_OBJECT_INVALID,             /* 13 (Invalid) */
    OF_OBJECT_INVALID,             /* 14 (Invalid) */
    OF_OBJECT_INVALID,             /* 15 (Invalid) */
    OF_OBJECT_INVALID,             /* 16 (Invalid) */
    OF_OBJECT_INVALID,             /* 17 (Invalid) */
    OF_OBJECT_INVALID,             /* 18 (Invalid) */
    OF_OBJECT_INVALID,             /* 19 (Invalid) */
    OF_OBJECT_INVALID,             /* 20 (Invalid) */
    OF_OBJECT_INVALID,             /* 21 (Invalid) */
    OF_OBJECT_INVALID,             /* 22 (Invalid) */
    OF_OBJECT_INVALID,             /* 23 (Invalid) */
    OF_OBJECT_INVALID,             /* 24 (Invalid) */
    OF_OBJECT_INVALID,             /* 25 (Invalid) */
    OF_OBJECT_INVALID,             /* 26 (Invalid) */
    OF_OBJECT_INVALID              /* 27 (Invalid) */
};
static const of_object_id_t
of_action_id_type_to_id_v2[OF_ACTION_ID_ITEM_COUNT] = {
    OF_OBJECT_INVALID,             /* 0 (Invalid) */
    OF_OBJECT_INVALID,             /* 1 (Invalid) */
    OF_OBJECT_INVALID,             /* 2 (Invalid) */
    OF_OBJECT_INVALID,             /* 3 (Invalid) */
    OF_OBJECT_INVALID,             /* 4 (Invalid) */
    OF_OBJECT_INVALID,             /* 5 (Invalid) */
    OF_OBJECT_INVALID,             /* 6 (Invalid) */
    OF_OBJECT_INVALID,             /* 7 (Invalid) */
    OF_OBJECT_INVALID,             /* 8 (Invalid) */
    OF_OBJECT_INVALID,             /* 9 (Invalid) */
    OF_OBJECT_INVALID,             /* 10 (Invalid) */
    OF_OBJECT_INVALID,             /* 11 (Invalid) */
    OF_OBJECT_INVALID,             /* 12 (Invalid) */
    OF_OBJECT_INVALID,             /* 13 (Invalid) */
    OF_OBJECT_INVALID,             /* 14 (Invalid) */
    OF_OBJECT_INVALID,             /* 15 (Invalid) */
    OF_OBJECT_INVALID,             /* 16 (Invalid) */
    OF_OBJECT_INVALID,             /* 17 (Invalid) */
    OF_OBJECT_INVALID,             /* 18 (Invalid) */
    OF_OBJECT_INVALID,             /* 19 (Invalid) */
    OF_OBJECT_INVALID,             /* 20 (Invalid) */
    OF_OBJECT_INVALID,             /* 21 (Invalid) */
    OF_OBJECT_INVALID,             /* 22 (Invalid) */
    OF_OBJECT_INVALID,             /* 23 (Invalid) */
    OF_OBJECT_INVALID,             /* 24 (Invalid) */
    OF_OBJECT_INVALID,             /* 25 (Invalid) */
    OF_OBJECT_INVALID,             /* 26 (Invalid) */
    OF_OBJECT_INVALID              /* 27 (Invalid) */
};
static const of_object_id_t
of_action_id_type_to_id_v3[OF_ACTION_ID_ITEM_COUNT] = {
    OF_OBJECT_INVALID,             /* 0 (Invalid) */
    OF_OBJECT_INVALID,             /* 1 (Invalid) */
    OF_OBJECT_INVALID,             /* 2 (Invalid) */
    OF_OBJECT_INVALID,             /* 3 (Invalid) */
    OF_OBJECT_INVALID,             /* 4 (Invalid) */
    OF_OBJECT_INVALID,             /* 5 (Invalid) */
    OF_OBJECT_INVALID,             /* 6 (Invalid) */
    OF_OBJECT_INVALID,             /* 7 (Invalid) */
    OF_OBJECT_INVALID,             /* 8 (Invalid) */
    OF_OBJECT_INVALID,             /* 9 (Invalid) */
    OF_OBJECT_INVALID,             /* 10 (Invalid) */
    OF_OBJECT_INVALID,             /* 11 (Invalid) */
    OF_OBJECT_INVALID,             /* 12 (Invalid) */
    OF_OBJECT_INVALID,             /* 13 (Invalid) */
    OF_OBJECT_INVALID,             /* 14 (Invalid) */
    OF_OBJECT_INVALID,             /* 15 (Invalid) */
    OF_OBJECT_INVALID,             /* 16 (Invalid) */
    OF_OBJECT_INVALID,             /* 17 (Invalid) */
    OF_OBJECT_INVALID,             /* 18 (Invalid) */
    OF_OBJECT_INVALID,             /* 19 (Invalid) */
    OF_OBJECT_INVALID,             /* 20 (Invalid) */
    OF_OBJECT_INVALID,             /* 21 (Invalid) */
    OF_OBJECT_INVALID,             /* 22 (Invalid) */
    OF_OBJECT_INVALID,             /* 23 (Invalid) */
    OF_OBJECT_INVALID,             /* 24 (Invalid) */
    OF_OBJECT_INVALID,             /* 25 (Invalid) */
    OF_OBJECT_INVALID,             /* 26 (Invalid) */
    OF_OBJECT_INVALID              /* 27 (Invalid) */
};
static const of_object_id_t
of_action_id_type_to_id_v4[OF_ACTION_ID_ITEM_COUNT] = {
    OF_ACTION_ID_OUTPUT,           /* 0 */
    OF_OBJECT_INVALID,             /* 1 (Invalid) */
    OF_OBJECT_INVALID,             /* 2 (Invalid) */
    OF_OBJECT_INVALID,             /* 3 (Invalid) */
    OF_OBJECT_INVALID,             /* 4 (Invalid) */
    OF_OBJECT_INVALID,             /* 5 (Invalid) */
    OF_OBJECT_INVALID,             /* 6 (Invalid) */
    OF_OBJECT_INVALID,             /* 7 (Invalid) */
    OF_OBJECT_INVALID,             /* 8 (Invalid) */
    OF_OBJECT_INVALID,             /* 9 (Invalid) */
    OF_OBJECT_INVALID,             /* 10 (Invalid) */
    OF_ACTION_ID_COPY_TTL_OUT,     /* 11 */
    OF_ACTION_ID_COPY_TTL_IN,      /* 12 */
    OF_OBJECT_INVALID,             /* 13 (Invalid) */
    OF_OBJECT_INVALID,             /* 14 (Invalid) */
    OF_ACTION_ID_SET_MPLS_TTL,     /* 15 */
    OF_ACTION_ID_DEC_MPLS_TTL,     /* 16 */
    OF_ACTION_ID_PUSH_VLAN,        /* 17 */
    OF_ACTION_ID_POP_VLAN,         /* 18 */
    OF_ACTION_ID_PUSH_MPLS,        /* 19 */
    OF_ACTION_ID_POP_MPLS,         /* 20 */
    OF_ACTION_ID_SET_QUEUE,        /* 21 */
    OF_ACTION_ID_GROUP,            /* 22 */
    OF_ACTION_ID_SET_NW_TTL,       /* 23 */
    OF_ACTION_ID_DEC_NW_TTL,       /* 24 */
    OF_ACTION_ID_SET_FIELD,        /* 25 */
    OF_ACTION_ID_PUSH_PBB,         /* 26 */
    OF_ACTION_ID_POP_PBB           /* 27 */
};

/**
 * Maps from of_action_id wire type values to LOCI object ids
 *
 * Indexed by wire version which is 1-based.
 */

const of_object_id_t *const of_action_id_type_to_id[OF_VERSION_ARRAY_MAX] = {
    NULL,
    of_action_id_type_to_id_v1,
    of_action_id_type_to_id_v2,
    of_action_id_type_to_id_v3,
    of_action_id_type_to_id_v4,

};

static const of_object_id_t
of_instruction_type_to_id_v1[OF_INSTRUCTION_ITEM_COUNT] = {
    OF_OBJECT_INVALID,             /* 0 (Invalid) */
    OF_OBJECT_INVALID,             /* 1 (Invalid) */
    OF_OBJECT_INVALID,             /* 2 (Invalid) */
    OF_OBJECT_INVALID,             /* 3 (Invalid) */
    OF_OBJECT_INVALID,             /* 4 (Invalid) */
    OF_OBJECT_INVALID,             /* 5 (Invalid) */
    OF_OBJECT_INVALID              /* 6 (Invalid) */
};
static const of_object_id_t
of_instruction_type_to_id_v2[OF_INSTRUCTION_ITEM_COUNT] = {
    OF_OBJECT_INVALID,             /* 0 (Invalid) */
    OF_INSTRUCTION_GOTO_TABLE,     /* 1 */
    OF_INSTRUCTION_WRITE_METADATA, /* 2 */
    OF_INSTRUCTION_WRITE_ACTIONS,  /* 3 */
    OF_INSTRUCTION_APPLY_ACTIONS,  /* 4 */
    OF_INSTRUCTION_CLEAR_ACTIONS,  /* 5 */
    OF_OBJECT_INVALID              /* 6 (Invalid) */
};
static const of_object_id_t
of_instruction_type_to_id_v3[OF_INSTRUCTION_ITEM_COUNT] = {
    OF_OBJECT_INVALID,             /* 0 (Invalid) */
    OF_INSTRUCTION_GOTO_TABLE,     /* 1 */
    OF_INSTRUCTION_WRITE_METADATA, /* 2 */
    OF_INSTRUCTION_WRITE_ACTIONS,  /* 3 */
    OF_INSTRUCTION_APPLY_ACTIONS,  /* 4 */
    OF_INSTRUCTION_CLEAR_ACTIONS,  /* 5 */
    OF_OBJECT_INVALID              /* 6 (Invalid) */
};
static const of_object_id_t
of_instruction_type_to_id_v4[OF_INSTRUCTION_ITEM_COUNT] = {
    OF_OBJECT_INVALID,             /* 0 (Invalid) */
    OF_INSTRUCTION_GOTO_TABLE,     /* 1 */
    OF_INSTRUCTION_WRITE_METADATA, /* 2 */
    OF_INSTRUCTION_WRITE_ACTIONS,  /* 3 */
    OF_INSTRUCTION_APPLY_ACTIONS,  /* 4 */
    OF_INSTRUCTION_CLEAR_ACTIONS,  /* 5 */
    OF_INSTRUCTION_METER           /* 6 */
};

/**
 * Maps from of_instruction wire type values to LOCI object ids
 *
 * Indexed by wire version which is 1-based.
 */

const of_object_id_t *const of_instruction_type_to_id[OF_VERSION_ARRAY_MAX] = {
    NULL,
    of_instruction_type_to_id_v1,
    of_instruction_type_to_id_v2,
    of_instruction_type_to_id_v3,
    of_instruction_type_to_id_v4,

};

static const of_object_id_t
of_instruction_id_type_to_id_v1[OF_INSTRUCTION_ID_ITEM_COUNT] = {
    OF_OBJECT_INVALID,             /* 0 (Invalid) */
    OF_OBJECT_INVALID,             /* 1 (Invalid) */
    OF_OBJECT_INVALID,             /* 2 (Invalid) */
    OF_OBJECT_INVALID,             /* 3 (Invalid) */
    OF_OBJECT_INVALID,             /* 4 (Invalid) */
    OF_OBJECT_INVALID,             /* 5 (Invalid) */
    OF_OBJECT_INVALID              /* 6 (Invalid) */
};
static const of_object_id_t
of_instruction_id_type_to_id_v2[OF_INSTRUCTION_ID_ITEM_COUNT] = {
    OF_OBJECT_INVALID,             /* 0 (Invalid) */
    OF_OBJECT_INVALID,             /* 1 (Invalid) */
    OF_OBJECT_INVALID,             /* 2 (Invalid) */
    OF_OBJECT_INVALID,             /* 3 (Invalid) */
    OF_OBJECT_INVALID,             /* 4 (Invalid) */
    OF_OBJECT_INVALID,             /* 5 (Invalid) */
    OF_OBJECT_INVALID              /* 6 (Invalid) */
};
static const of_object_id_t
of_instruction_id_type_to_id_v3[OF_INSTRUCTION_ID_ITEM_COUNT] = {
    OF_OBJECT_INVALID,             /* 0 (Invalid) */
    OF_OBJECT_INVALID,             /* 1 (Invalid) */
    OF_OBJECT_INVALID,             /* 2 (Invalid) */
    OF_OBJECT_INVALID,             /* 3 (Invalid) */
    OF_OBJECT_INVALID,             /* 4 (Invalid) */
    OF_OBJECT_INVALID,             /* 5 (Invalid) */
    OF_OBJECT_INVALID              /* 6 (Invalid) */
};
static const of_object_id_t
of_instruction_id_type_to_id_v4[OF_INSTRUCTION_ID_ITEM_COUNT] = {
    OF_OBJECT_INVALID,             /* 0 (Invalid) */
    OF_INSTRUCTION_ID_GOTO_TABLE,  /* 1 */
    OF_INSTRUCTION_ID_WRITE_METADATA, /* 2 */
    OF_INSTRUCTION_ID_WRITE_ACTIONS, /* 3 */
    OF_INSTRUCTION_ID_APPLY_ACTIONS, /* 4 */
    OF_INSTRUCTION_ID_CLEAR_ACTIONS, /* 5 */
    OF_INSTRUCTION_ID_METER        /* 6 */
};

/**
 * Maps from of_instruction_id wire type values to LOCI object ids
 *
 * Indexed by wire version which is 1-based.
 */

const of_object_id_t *const of_instruction_id_type_to_id[OF_VERSION_ARRAY_MAX] = {
    NULL,
    of_instruction_id_type_to_id_v1,
    of_instruction_id_type_to_id_v2,
    of_instruction_id_type_to_id_v3,
    of_instruction_id_type_to_id_v4,

};

static const of_object_id_t
of_queue_prop_type_to_id_v1[OF_QUEUE_PROP_ITEM_COUNT] = {
    OF_OBJECT_INVALID,             /* 0 (Invalid) */
    OF_QUEUE_PROP_MIN_RATE,        /* 1 */
    OF_OBJECT_INVALID              /* 2 (Invalid) */
};
static const of_object_id_t
of_queue_prop_type_to_id_v2[OF_QUEUE_PROP_ITEM_COUNT] = {
    OF_OBJECT_INVALID,             /* 0 (Invalid) */
    OF_QUEUE_PROP_MIN_RATE,        /* 1 */
    OF_OBJECT_INVALID              /* 2 (Invalid) */
};
static const of_object_id_t
of_queue_prop_type_to_id_v3[OF_QUEUE_PROP_ITEM_COUNT] = {
    OF_OBJECT_INVALID,             /* 0 (Invalid) */
    OF_QUEUE_PROP_MIN_RATE,        /* 1 */
    OF_QUEUE_PROP_MAX_RATE         /* 2 */
};
static const of_object_id_t
of_queue_prop_type_to_id_v4[OF_QUEUE_PROP_ITEM_COUNT] = {
    OF_OBJECT_INVALID,             /* 0 (Invalid) */
    OF_QUEUE_PROP_MIN_RATE,        /* 1 */
    OF_QUEUE_PROP_MAX_RATE         /* 2 */
};

/**
 * Maps from of_queue_prop wire type values to LOCI object ids
 *
 * Indexed by wire version which is 1-based.
 */

const of_object_id_t *const of_queue_prop_type_to_id[OF_VERSION_ARRAY_MAX] = {
    NULL,
    of_queue_prop_type_to_id_v1,
    of_queue_prop_type_to_id_v2,
    of_queue_prop_type_to_id_v3,
    of_queue_prop_type_to_id_v4,

};

static const of_object_id_t
of_table_feature_prop_type_to_id_v1[OF_TABLE_FEATURE_PROP_ITEM_COUNT] = {
    OF_OBJECT_INVALID,             /* 0 (Invalid) */
    OF_OBJECT_INVALID,             /* 1 (Invalid) */
    OF_OBJECT_INVALID,             /* 2 (Invalid) */
    OF_OBJECT_INVALID,             /* 3 (Invalid) */
    OF_OBJECT_INVALID,             /* 4 (Invalid) */
    OF_OBJECT_INVALID,             /* 5 (Invalid) */
    OF_OBJECT_INVALID,             /* 6 (Invalid) */
    OF_OBJECT_INVALID,             /* 7 (Invalid) */
    OF_OBJECT_INVALID,             /* 8 (Invalid) */
    OF_OBJECT_INVALID,             /* 9 (Invalid) */
    OF_OBJECT_INVALID,             /* 10 (Invalid) */
    OF_OBJECT_INVALID,             /* 11 (Invalid) */
    OF_OBJECT_INVALID,             /* 12 (Invalid) */
    OF_OBJECT_INVALID,             /* 13 (Invalid) */
    OF_OBJECT_INVALID,             /* 14 (Invalid) */
    OF_OBJECT_INVALID              /* 15 (Invalid) */
};
static const of_object_id_t
of_table_feature_prop_type_to_id_v2[OF_TABLE_FEATURE_PROP_ITEM_COUNT] = {
    OF_OBJECT_INVALID,             /* 0 (Invalid) */
    OF_OBJECT_INVALID,             /* 1 (Invalid) */
    OF_OBJECT_INVALID,             /* 2 (Invalid) */
    OF_OBJECT_INVALID,             /* 3 (Invalid) */
    OF_OBJECT_INVALID,             /* 4 (Invalid) */
    OF_OBJECT_INVALID,             /* 5 (Invalid) */
    OF_OBJECT_INVALID,             /* 6 (Invalid) */
    OF_OBJECT_INVALID,             /* 7 (Invalid) */
    OF_OBJECT_INVALID,             /* 8 (Invalid) */
    OF_OBJECT_INVALID,             /* 9 (Invalid) */
    OF_OBJECT_INVALID,             /* 10 (Invalid) */
    OF_OBJECT_INVALID,             /* 11 (Invalid) */
    OF_OBJECT_INVALID,             /* 12 (Invalid) */
    OF_OBJECT_INVALID,             /* 13 (Invalid) */
    OF_OBJECT_INVALID,             /* 14 (Invalid) */
    OF_OBJECT_INVALID              /* 15 (Invalid) */
};
static const of_object_id_t
of_table_feature_prop_type_to_id_v3[OF_TABLE_FEATURE_PROP_ITEM_COUNT] = {
    OF_OBJECT_INVALID,             /* 0 (Invalid) */
    OF_OBJECT_INVALID,             /* 1 (Invalid) */
    OF_OBJECT_INVALID,             /* 2 (Invalid) */
    OF_OBJECT_INVALID,             /* 3 (Invalid) */
    OF_OBJECT_INVALID,             /* 4 (Invalid) */
    OF_OBJECT_INVALID,             /* 5 (Invalid) */
    OF_OBJECT_INVALID,             /* 6 (Invalid) */
    OF_OBJECT_INVALID,             /* 7 (Invalid) */
    OF_OBJECT_INVALID,             /* 8 (Invalid) */
    OF_OBJECT_INVALID,             /* 9 (Invalid) */
    OF_OBJECT_INVALID,             /* 10 (Invalid) */
    OF_OBJECT_INVALID,             /* 11 (Invalid) */
    OF_OBJECT_INVALID,             /* 12 (Invalid) */
    OF_OBJECT_INVALID,             /* 13 (Invalid) */
    OF_OBJECT_INVALID,             /* 14 (Invalid) */
    OF_OBJECT_INVALID              /* 15 (Invalid) */
};
static const of_object_id_t
of_table_feature_prop_type_to_id_v4[OF_TABLE_FEATURE_PROP_ITEM_COUNT] = {
    OF_TABLE_FEATURE_PROP_INSTRUCTIONS, /* 0 */
    OF_TABLE_FEATURE_PROP_INSTRUCTIONS_MISS, /* 1 */
    OF_TABLE_FEATURE_PROP_NEXT_TABLES, /* 2 */
    OF_TABLE_FEATURE_PROP_NEXT_TABLES_MISS, /* 3 */
    OF_TABLE_FEATURE_PROP_WRITE_ACTIONS, /* 4 */
    OF_TABLE_FEATURE_PROP_WRITE_ACTIONS_MISS, /* 5 */
    OF_TABLE_FEATURE_PROP_APPLY_ACTIONS, /* 6 */
    OF_TABLE_FEATURE_PROP_APPLY_ACTIONS_MISS, /* 7 */
    OF_TABLE_FEATURE_PROP_MATCH,   /* 8 */
    OF_OBJECT_INVALID,             /* 9 (Invalid) */
    OF_TABLE_FEATURE_PROP_WILDCARDS, /* 10 */
    OF_OBJECT_INVALID,             /* 11 (Invalid) */
    OF_TABLE_FEATURE_PROP_WRITE_SETFIELD, /* 12 */
    OF_TABLE_FEATURE_PROP_WRITE_SETFIELD_MISS, /* 13 */
    OF_TABLE_FEATURE_PROP_APPLY_SETFIELD, /* 14 */
    OF_TABLE_FEATURE_PROP_APPLY_SETFIELD_MISS /* 15 */
};

/**
 * Maps from of_table_feature_prop wire type values to LOCI object ids
 *
 * Indexed by wire version which is 1-based.
 */

const of_object_id_t *const of_table_feature_prop_type_to_id[OF_VERSION_ARRAY_MAX] = {
    NULL,
    of_table_feature_prop_type_to_id_v1,
    of_table_feature_prop_type_to_id_v2,
    of_table_feature_prop_type_to_id_v3,
    of_table_feature_prop_type_to_id_v4,

};

static const of_object_id_t
of_meter_band_type_to_id_v1[OF_METER_BAND_ITEM_COUNT] = {
    OF_OBJECT_INVALID,             /* 0 (Invalid) */
    OF_OBJECT_INVALID,             /* 1 (Invalid) */
    OF_OBJECT_INVALID              /* 2 (Invalid) */
};
static const of_object_id_t
of_meter_band_type_to_id_v2[OF_METER_BAND_ITEM_COUNT] = {
    OF_OBJECT_INVALID,             /* 0 (Invalid) */
    OF_OBJECT_INVALID,             /* 1 (Invalid) */
    OF_OBJECT_INVALID              /* 2 (Invalid) */
};
static const of_object_id_t
of_meter_band_type_to_id_v3[OF_METER_BAND_ITEM_COUNT] = {
    OF_OBJECT_INVALID,             /* 0 (Invalid) */
    OF_OBJECT_INVALID,             /* 1 (Invalid) */
    OF_OBJECT_INVALID              /* 2 (Invalid) */
};
static const of_object_id_t
of_meter_band_type_to_id_v4[OF_METER_BAND_ITEM_COUNT] = {
    OF_OBJECT_INVALID,             /* 0 (Invalid) */
    OF_METER_BAND_DROP,            /* 1 */
    OF_METER_BAND_DSCP_REMARK      /* 2 */
};

/**
 * Maps from of_meter_band wire type values to LOCI object ids
 *
 * Indexed by wire version which is 1-based.
 */

const of_object_id_t *const of_meter_band_type_to_id[OF_VERSION_ARRAY_MAX] = {
    NULL,
    of_meter_band_type_to_id_v1,
    of_meter_band_type_to_id_v2,
    of_meter_band_type_to_id_v3,
    of_meter_band_type_to_id_v4,

};

static const of_object_id_t
of_hello_elem_type_to_id_v1[OF_HELLO_ELEM_ITEM_COUNT] = {
    OF_OBJECT_INVALID,             /* 0 (Invalid) */
    OF_OBJECT_INVALID              /* 1 (Invalid) */
};
static const of_object_id_t
of_hello_elem_type_to_id_v2[OF_HELLO_ELEM_ITEM_COUNT] = {
    OF_OBJECT_INVALID,             /* 0 (Invalid) */
    OF_OBJECT_INVALID              /* 1 (Invalid) */
};
static const of_object_id_t
of_hello_elem_type_to_id_v3[OF_HELLO_ELEM_ITEM_COUNT] = {
    OF_OBJECT_INVALID,             /* 0 (Invalid) */
    OF_OBJECT_INVALID              /* 1 (Invalid) */
};
static const of_object_id_t
of_hello_elem_type_to_id_v4[OF_HELLO_ELEM_ITEM_COUNT] = {
    OF_OBJECT_INVALID,             /* 0 (Invalid) */
    OF_HELLO_ELEM_VERSIONBITMAP    /* 1 */
};

/**
 * Maps from of_hello_elem wire type values to LOCI object ids
 *
 * Indexed by wire version which is 1-based.
 */

const of_object_id_t *const of_hello_elem_type_to_id[OF_VERSION_ARRAY_MAX] = {
    NULL,
    of_hello_elem_type_to_id_v1,
    of_hello_elem_type_to_id_v2,
    of_hello_elem_type_to_id_v3,
    of_hello_elem_type_to_id_v4,

};

static const of_object_id_t
of_group_mod_type_to_id_v1[OF_GROUP_MOD_ITEM_COUNT] = {
    OF_OBJECT_INVALID,             /* 0 (Invalid) */
    OF_OBJECT_INVALID,             /* 1 (Invalid) */
    OF_OBJECT_INVALID              /* 2 (Invalid) */
};
static const of_object_id_t
of_group_mod_type_to_id_v2[OF_GROUP_MOD_ITEM_COUNT] = {
    OF_GROUP_ADD,                  /* 0 */
    OF_GROUP_MODIFY,               /* 1 */
    OF_GROUP_DELETE                /* 2 */
};
static const of_object_id_t
of_group_mod_type_to_id_v3[OF_GROUP_MOD_ITEM_COUNT] = {
    OF_GROUP_ADD,                  /* 0 */
    OF_GROUP_MODIFY,               /* 1 */
    OF_GROUP_DELETE                /* 2 */
};
static const of_object_id_t
of_group_mod_type_to_id_v4[OF_GROUP_MOD_ITEM_COUNT] = {
    OF_GROUP_ADD,                  /* 0 */
    OF_GROUP_MODIFY,               /* 1 */
    OF_GROUP_DELETE                /* 2 */
};

/**
 * Maps from of_group_mod wire type values to LOCI object ids
 *
 * Indexed by wire version which is 1-based.
 */

const of_object_id_t *const of_group_mod_type_to_id[OF_VERSION_ARRAY_MAX] = {
    NULL,
    of_group_mod_type_to_id_v1,
    of_group_mod_type_to_id_v2,
    of_group_mod_type_to_id_v3,
    of_group_mod_type_to_id_v4,

};

static const of_object_id_t
of_stats_request_type_to_id_v1[OF_STATS_REQUEST_ITEM_COUNT] = {
    OF_DESC_STATS_REQUEST,         /* 0 */
    OF_FLOW_STATS_REQUEST,         /* 1 */
    OF_AGGREGATE_STATS_REQUEST,    /* 2 */
    OF_TABLE_STATS_REQUEST,        /* 3 */
    OF_PORT_STATS_REQUEST,         /* 4 */
    OF_QUEUE_STATS_REQUEST,        /* 5 */
    OF_OBJECT_INVALID,             /* 6 (Invalid) */
    OF_OBJECT_INVALID,             /* 7 (Invalid) */
    OF_OBJECT_INVALID,             /* 8 (Invalid) */
    OF_OBJECT_INVALID,             /* 9 (Invalid) */
    OF_OBJECT_INVALID,             /* 10 (Invalid) */
    OF_OBJECT_INVALID,             /* 11 (Invalid) */
    OF_OBJECT_INVALID,             /* 12 (Invalid) */
    OF_OBJECT_INVALID              /* 13 (Invalid) */
};
static const of_object_id_t
of_stats_request_type_to_id_v2[OF_STATS_REQUEST_ITEM_COUNT] = {
    OF_DESC_STATS_REQUEST,         /* 0 */
    OF_FLOW_STATS_REQUEST,         /* 1 */
    OF_AGGREGATE_STATS_REQUEST,    /* 2 */
    OF_TABLE_STATS_REQUEST,        /* 3 */
    OF_PORT_STATS_REQUEST,         /* 4 */
    OF_QUEUE_STATS_REQUEST,        /* 5 */
    OF_GROUP_STATS_REQUEST,        /* 6 */
    OF_GROUP_DESC_STATS_REQUEST,   /* 7 */
    OF_OBJECT_INVALID,             /* 8 (Invalid) */
    OF_OBJECT_INVALID,             /* 9 (Invalid) */
    OF_OBJECT_INVALID,             /* 10 (Invalid) */
    OF_OBJECT_INVALID,             /* 11 (Invalid) */
    OF_OBJECT_INVALID,             /* 12 (Invalid) */
    OF_OBJECT_INVALID              /* 13 (Invalid) */
};
static const of_object_id_t
of_stats_request_type_to_id_v3[OF_STATS_REQUEST_ITEM_COUNT] = {
    OF_DESC_STATS_REQUEST,         /* 0 */
    OF_FLOW_STATS_REQUEST,         /* 1 */
    OF_AGGREGATE_STATS_REQUEST,    /* 2 */
    OF_TABLE_STATS_REQUEST,        /* 3 */
    OF_PORT_STATS_REQUEST,         /* 4 */
    OF_QUEUE_STATS_REQUEST,        /* 5 */
    OF_GROUP_STATS_REQUEST,        /* 6 */
    OF_GROUP_DESC_STATS_REQUEST,   /* 7 */
    OF_GROUP_FEATURES_STATS_REQUEST, /* 8 */
    OF_OBJECT_INVALID,             /* 9 (Invalid) */
    OF_OBJECT_INVALID,             /* 10 (Invalid) */
    OF_OBJECT_INVALID,             /* 11 (Invalid) */
    OF_OBJECT_INVALID,             /* 12 (Invalid) */
    OF_OBJECT_INVALID              /* 13 (Invalid) */
};
static const of_object_id_t
of_stats_request_type_to_id_v4[OF_STATS_REQUEST_ITEM_COUNT] = {
    OF_DESC_STATS_REQUEST,         /* 0 */
    OF_FLOW_STATS_REQUEST,         /* 1 */
    OF_AGGREGATE_STATS_REQUEST,    /* 2 */
    OF_TABLE_STATS_REQUEST,        /* 3 */
    OF_PORT_STATS_REQUEST,         /* 4 */
    OF_QUEUE_STATS_REQUEST,        /* 5 */
    OF_GROUP_STATS_REQUEST,        /* 6 */
    OF_GROUP_DESC_STATS_REQUEST,   /* 7 */
    OF_GROUP_FEATURES_STATS_REQUEST, /* 8 */
    OF_METER_STATS_REQUEST,        /* 9 */
    OF_METER_CONFIG_STATS_REQUEST, /* 10 */
    OF_METER_FEATURES_STATS_REQUEST, /* 11 */
    OF_TABLE_FEATURES_STATS_REQUEST, /* 12 */
    OF_PORT_DESC_STATS_REQUEST     /* 13 */
};

/**
 * Maps from of_stats_request wire type values to LOCI object ids
 *
 * Indexed by wire version which is 1-based.
 */

const of_object_id_t *const of_stats_request_type_to_id[OF_VERSION_ARRAY_MAX] = {
    NULL,
    of_stats_request_type_to_id_v1,
    of_stats_request_type_to_id_v2,
    of_stats_request_type_to_id_v3,
    of_stats_request_type_to_id_v4,

};

static const of_object_id_t
of_stats_reply_type_to_id_v1[OF_STATS_REPLY_ITEM_COUNT] = {
    OF_DESC_STATS_REPLY,           /* 0 */
    OF_FLOW_STATS_REPLY,           /* 1 */
    OF_AGGREGATE_STATS_REPLY,      /* 2 */
    OF_TABLE_STATS_REPLY,          /* 3 */
    OF_PORT_STATS_REPLY,           /* 4 */
    OF_QUEUE_STATS_REPLY,          /* 5 */
    OF_OBJECT_INVALID,             /* 6 (Invalid) */
    OF_OBJECT_INVALID,             /* 7 (Invalid) */
    OF_OBJECT_INVALID,             /* 8 (Invalid) */
    OF_OBJECT_INVALID,             /* 9 (Invalid) */
    OF_OBJECT_INVALID,             /* 10 (Invalid) */
    OF_OBJECT_INVALID,             /* 11 (Invalid) */
    OF_OBJECT_INVALID,             /* 12 (Invalid) */
    OF_OBJECT_INVALID              /* 13 (Invalid) */
};
static const of_object_id_t
of_stats_reply_type_to_id_v2[OF_STATS_REPLY_ITEM_COUNT] = {
    OF_DESC_STATS_REPLY,           /* 0 */
    OF_FLOW_STATS_REPLY,           /* 1 */
    OF_AGGREGATE_STATS_REPLY,      /* 2 */
    OF_TABLE_STATS_REPLY,          /* 3 */
    OF_PORT_STATS_REPLY,           /* 4 */
    OF_QUEUE_STATS_REPLY,          /* 5 */
    OF_GROUP_STATS_REPLY,          /* 6 */
    OF_GROUP_DESC_STATS_REPLY,     /* 7 */
    OF_OBJECT_INVALID,             /* 8 (Invalid) */
    OF_OBJECT_INVALID,             /* 9 (Invalid) */
    OF_OBJECT_INVALID,             /* 10 (Invalid) */
    OF_OBJECT_INVALID,             /* 11 (Invalid) */
    OF_OBJECT_INVALID,             /* 12 (Invalid) */
    OF_OBJECT_INVALID              /* 13 (Invalid) */
};
static const of_object_id_t
of_stats_reply_type_to_id_v3[OF_STATS_REPLY_ITEM_COUNT] = {
    OF_DESC_STATS_REPLY,           /* 0 */
    OF_FLOW_STATS_REPLY,           /* 1 */
    OF_AGGREGATE_STATS_REPLY,      /* 2 */
    OF_TABLE_STATS_REPLY,          /* 3 */
    OF_PORT_STATS_REPLY,           /* 4 */
    OF_QUEUE_STATS_REPLY,          /* 5 */
    OF_GROUP_STATS_REPLY,          /* 6 */
    OF_GROUP_DESC_STATS_REPLY,     /* 7 */
    OF_GROUP_FEATURES_STATS_REPLY, /* 8 */
    OF_OBJECT_INVALID,             /* 9 (Invalid) */
    OF_OBJECT_INVALID,             /* 10 (Invalid) */
    OF_OBJECT_INVALID,             /* 11 (Invalid) */
    OF_OBJECT_INVALID,             /* 12 (Invalid) */
    OF_OBJECT_INVALID              /* 13 (Invalid) */
};
static const of_object_id_t
of_stats_reply_type_to_id_v4[OF_STATS_REPLY_ITEM_COUNT] = {
    OF_DESC_STATS_REPLY,           /* 0 */
    OF_FLOW_STATS_REPLY,           /* 1 */
    OF_AGGREGATE_STATS_REPLY,      /* 2 */
    OF_TABLE_STATS_REPLY,          /* 3 */
    OF_PORT_STATS_REPLY,           /* 4 */
    OF_QUEUE_STATS_REPLY,          /* 5 */
    OF_GROUP_STATS_REPLY,          /* 6 */
    OF_GROUP_DESC_STATS_REPLY,     /* 7 */
    OF_GROUP_FEATURES_STATS_REPLY, /* 8 */
    OF_METER_STATS_REPLY,          /* 9 */
    OF_METER_CONFIG_STATS_REPLY,   /* 10 */
    OF_METER_FEATURES_STATS_REPLY, /* 11 */
    OF_TABLE_FEATURES_STATS_REPLY, /* 12 */
    OF_PORT_DESC_STATS_REPLY       /* 13 */
};

/**
 * Maps from of_stats_reply wire type values to LOCI object ids
 *
 * Indexed by wire version which is 1-based.
 */

const of_object_id_t *const of_stats_reply_type_to_id[OF_VERSION_ARRAY_MAX] = {
    NULL,
    of_stats_reply_type_to_id_v1,
    of_stats_reply_type_to_id_v2,
    of_stats_reply_type_to_id_v3,
    of_stats_reply_type_to_id_v4,

};

static const of_object_id_t
of_flow_mod_type_to_id_v1[OF_FLOW_MOD_ITEM_COUNT] = {
    OF_FLOW_ADD,                   /* 0 */
    OF_FLOW_MODIFY,                /* 1 */
    OF_FLOW_MODIFY_STRICT,         /* 2 */
    OF_FLOW_DELETE,                /* 3 */
    OF_FLOW_DELETE_STRICT          /* 4 */
};
static const of_object_id_t
of_flow_mod_type_to_id_v2[OF_FLOW_MOD_ITEM_COUNT] = {
    OF_FLOW_ADD,                   /* 0 */
    OF_FLOW_MODIFY,                /* 1 */
    OF_FLOW_MODIFY_STRICT,         /* 2 */
    OF_FLOW_DELETE,                /* 3 */
    OF_FLOW_DELETE_STRICT          /* 4 */
};
static const of_object_id_t
of_flow_mod_type_to_id_v3[OF_FLOW_MOD_ITEM_COUNT] = {
    OF_FLOW_ADD,                   /* 0 */
    OF_FLOW_MODIFY,                /* 1 */
    OF_FLOW_MODIFY_STRICT,         /* 2 */
    OF_FLOW_DELETE,                /* 3 */
    OF_FLOW_DELETE_STRICT          /* 4 */
};
static const of_object_id_t
of_flow_mod_type_to_id_v4[OF_FLOW_MOD_ITEM_COUNT] = {
    OF_FLOW_ADD,                   /* 0 */
    OF_FLOW_MODIFY,                /* 1 */
    OF_FLOW_MODIFY_STRICT,         /* 2 */
    OF_FLOW_DELETE,                /* 3 */
    OF_FLOW_DELETE_STRICT          /* 4 */
};

/**
 * Maps from of_flow_mod wire type values to LOCI object ids
 *
 * Indexed by wire version which is 1-based.
 */

const of_object_id_t *const of_flow_mod_type_to_id[OF_VERSION_ARRAY_MAX] = {
    NULL,
    of_flow_mod_type_to_id_v1,
    of_flow_mod_type_to_id_v2,
    of_flow_mod_type_to_id_v3,
    of_flow_mod_type_to_id_v4,

};

static const of_object_id_t
of_oxm_type_to_id_v1[OF_OXM_ITEM_COUNT] = {
    OF_OBJECT_INVALID,             /* 0 (Invalid) */
    OF_OBJECT_INVALID,             /* 1 (Invalid) */
    OF_OBJECT_INVALID,             /* 2 (Invalid) */
    OF_OBJECT_INVALID,             /* 3 (Invalid) */
    OF_OBJECT_INVALID,             /* 4 (Invalid) */
    OF_OBJECT_INVALID,             /* 5 (Invalid) */
    OF_OBJECT_INVALID,             /* 6 (Invalid) */
    OF_OBJECT_INVALID,             /* 7 (Invalid) */
    OF_OBJECT_INVALID,             /* 8 (Invalid) */
    OF_OBJECT_INVALID,             /* 9 (Invalid) */
    OF_OBJECT_INVALID,             /* 10 (Invalid) */
    OF_OBJECT_INVALID,             /* 11 (Invalid) */
    OF_OBJECT_INVALID,             /* 12 (Invalid) */
    OF_OBJECT_INVALID,             /* 13 (Invalid) */
    OF_OBJECT_INVALID,             /* 14 (Invalid) */
    OF_OBJECT_INVALID,             /* 15 (Invalid) */
    OF_OBJECT_INVALID,             /* 16 (Invalid) */
    OF_OBJECT_INVALID,             /* 17 (Invalid) */
    OF_OBJECT_INVALID,             /* 18 (Invalid) */
    OF_OBJECT_INVALID,             /* 19 (Invalid) */
    OF_OBJECT_INVALID,             /* 20 (Invalid) */
    OF_OBJECT_INVALID,             /* 21 (Invalid) */
    OF_OBJECT_INVALID,             /* 22 (Invalid) */
    OF_OBJECT_INVALID,             /* 23 (Invalid) */
    OF_OBJECT_INVALID,             /* 24 (Invalid) */
    OF_OBJECT_INVALID,             /* 25 (Invalid) */
    OF_OBJECT_INVALID,             /* 26 (Invalid) */
    OF_OBJECT_INVALID,             /* 27 (Invalid) */
    OF_OBJECT_INVALID,             /* 28 (Invalid) */
    OF_OBJECT_INVALID,             /* 29 (Invalid) */
    OF_OBJECT_INVALID,             /* 30 (Invalid) */
    OF_OBJECT_INVALID,             /* 31 (Invalid) */
    OF_OBJECT_INVALID,             /* 32 (Invalid) */
    OF_OBJECT_INVALID,             /* 33 (Invalid) */
    OF_OBJECT_INVALID,             /* 34 (Invalid) */
    OF_OBJECT_INVALID,             /* 35 (Invalid) */
    OF_OBJECT_INVALID,             /* 36 (Invalid) */
    OF_OBJECT_INVALID,             /* 37 (Invalid) */
    OF_OBJECT_INVALID,             /* 38 (Invalid) */
    OF_OBJECT_INVALID,             /* 39 (Invalid) */
    OF_OBJECT_INVALID,             /* 40 (Invalid) */
    OF_OBJECT_INVALID,             /* 41 (Invalid) */
    OF_OBJECT_INVALID,             /* 42 (Invalid) */
    OF_OBJECT_INVALID,             /* 43 (Invalid) */
    OF_OBJECT_INVALID,             /* 44 (Invalid) */
    OF_OBJECT_INVALID,             /* 45 (Invalid) */
    OF_OBJECT_INVALID,             /* 46 (Invalid) */
    OF_OBJECT_INVALID,             /* 47 (Invalid) */
    OF_OBJECT_INVALID,             /* 48 (Invalid) */
    OF_OBJECT_INVALID,             /* 49 (Invalid) */
    OF_OBJECT_INVALID,             /* 50 (Invalid) */
    OF_OBJECT_INVALID,             /* 51 (Invalid) */
    OF_OBJECT_INVALID,             /* 52 (Invalid) */
    OF_OBJECT_INVALID,             /* 53 (Invalid) */
    OF_OBJECT_INVALID,             /* 54 (Invalid) */
    OF_OBJECT_INVALID,             /* 55 (Invalid) */
    OF_OBJECT_INVALID,             /* 56 (Invalid) */
    OF_OBJECT_INVALID,             /* 57 (Invalid) */
    OF_OBJECT_INVALID,             /* 58 (Invalid) */
    OF_OBJECT_INVALID,             /* 59 (Invalid) */
    OF_OBJECT_INVALID,             /* 60 (Invalid) */
    OF_OBJECT_INVALID,             /* 61 (Invalid) */
    OF_OBJECT_INVALID,             /* 62 (Invalid) */
    OF_OBJECT_INVALID,             /* 63 (Invalid) */
    OF_OBJECT_INVALID,             /* 64 (Invalid) */
    OF_OBJECT_INVALID,             /* 65 (Invalid) */
    OF_OBJECT_INVALID,             /* 66 (Invalid) */
    OF_OBJECT_INVALID,             /* 67 (Invalid) */
    OF_OBJECT_INVALID,             /* 68 (Invalid) */
    OF_OBJECT_INVALID,             /* 69 (Invalid) */
    OF_OBJECT_INVALID,             /* 70 (Invalid) */
    OF_OBJECT_INVALID              /* 71 (Invalid) */
};
static const of_object_id_t
of_oxm_type_to_id_v2[OF_OXM_ITEM_COUNT] = {
    OF_OBJECT_INVALID,             /* 0 (Invalid) */
    OF_OBJECT_INVALID,             /* 1 (Invalid) */
    OF_OBJECT_INVALID,             /* 2 (Invalid) */
    OF_OBJECT_INVALID,             /* 3 (Invalid) */
    OF_OBJECT_INVALID,             /* 4 (Invalid) */
    OF_OBJECT_INVALID,             /* 5 (Invalid) */
    OF_OBJECT_INVALID,             /* 6 (Invalid) */
    OF_OBJECT_INVALID,             /* 7 (Invalid) */
    OF_OBJECT_INVALID,             /* 8 (Invalid) */
    OF_OBJECT_INVALID,             /* 9 (Invalid) */
    OF_OBJECT_INVALID,             /* 10 (Invalid) */
    OF_OBJECT_INVALID,             /* 11 (Invalid) */
    OF_OBJECT_INVALID,             /* 12 (Invalid) */
    OF_OBJECT_INVALID,             /* 13 (Invalid) */
    OF_OBJECT_INVALID,             /* 14 (Invalid) */
    OF_OBJECT_INVALID,             /* 15 (Invalid) */
    OF_OBJECT_INVALID,             /* 16 (Invalid) */
    OF_OBJECT_INVALID,             /* 17 (Invalid) */
    OF_OBJECT_INVALID,             /* 18 (Invalid) */
    OF_OBJECT_INVALID,             /* 19 (Invalid) */
    OF_OBJECT_INVALID,             /* 20 (Invalid) */
    OF_OBJECT_INVALID,             /* 21 (Invalid) */
    OF_OBJECT_INVALID,             /* 22 (Invalid) */
    OF_OBJECT_INVALID,             /* 23 (Invalid) */
    OF_OBJECT_INVALID,             /* 24 (Invalid) */
    OF_OBJECT_INVALID,             /* 25 (Invalid) */
    OF_OBJECT_INVALID,             /* 26 (Invalid) */
    OF_OBJECT_INVALID,             /* 27 (Invalid) */
    OF_OBJECT_INVALID,             /* 28 (Invalid) */
    OF_OBJECT_INVALID,             /* 29 (Invalid) */
    OF_OBJECT_INVALID,             /* 30 (Invalid) */
    OF_OBJECT_INVALID,             /* 31 (Invalid) */
    OF_OBJECT_INVALID,             /* 32 (Invalid) */
    OF_OBJECT_INVALID,             /* 33 (Invalid) */
    OF_OBJECT_INVALID,             /* 34 (Invalid) */
    OF_OBJECT_INVALID,             /* 35 (Invalid) */
    OF_OBJECT_INVALID,             /* 36 (Invalid) */
    OF_OBJECT_INVALID,             /* 37 (Invalid) */
    OF_OBJECT_INVALID,             /* 38 (Invalid) */
    OF_OBJECT_INVALID,             /* 39 (Invalid) */
    OF_OBJECT_INVALID,             /* 40 (Invalid) */
    OF_OBJECT_INVALID,             /* 41 (Invalid) */
    OF_OBJECT_INVALID,             /* 42 (Invalid) */
    OF_OBJECT_INVALID,             /* 43 (Invalid) */
    OF_OBJECT_INVALID,             /* 44 (Invalid) */
    OF_OBJECT_INVALID,             /* 45 (Invalid) */
    OF_OBJECT_INVALID,             /* 46 (Invalid) */
    OF_OBJECT_INVALID,             /* 47 (Invalid) */
    OF_OBJECT_INVALID,             /* 48 (Invalid) */
    OF_OBJECT_INVALID,             /* 49 (Invalid) */
    OF_OBJECT_INVALID,             /* 50 (Invalid) */
    OF_OBJECT_INVALID,             /* 51 (Invalid) */
    OF_OBJECT_INVALID,             /* 52 (Invalid) */
    OF_OBJECT_INVALID,             /* 53 (Invalid) */
    OF_OBJECT_INVALID,             /* 54 (Invalid) */
    OF_OBJECT_INVALID,             /* 55 (Invalid) */
    OF_OBJECT_INVALID,             /* 56 (Invalid) */
    OF_OBJECT_INVALID,             /* 57 (Invalid) */
    OF_OBJECT_INVALID,             /* 58 (Invalid) */
    OF_OBJECT_INVALID,             /* 59 (Invalid) */
    OF_OBJECT_INVALID,             /* 60 (Invalid) */
    OF_OBJECT_INVALID,             /* 61 (Invalid) */
    OF_OBJECT_INVALID,             /* 62 (Invalid) */
    OF_OBJECT_INVALID,             /* 63 (Invalid) */
    OF_OBJECT_INVALID,             /* 64 (Invalid) */
    OF_OBJECT_INVALID,             /* 65 (Invalid) */
    OF_OBJECT_INVALID,             /* 66 (Invalid) */
    OF_OBJECT_INVALID,             /* 67 (Invalid) */
    OF_OBJECT_INVALID,             /* 68 (Invalid) */
    OF_OBJECT_INVALID,             /* 69 (Invalid) */
    OF_OBJECT_INVALID,             /* 70 (Invalid) */
    OF_OBJECT_INVALID              /* 71 (Invalid) */
};
static const of_object_id_t
of_oxm_type_to_id_v3[OF_OXM_ITEM_COUNT] = {
    OF_OXM_IN_PORT,                /* 0 */
    OF_OXM_IN_PORT_MASKED,         /* 1 */
    OF_OXM_IN_PHY_PORT,            /* 2 */
    OF_OXM_IN_PHY_PORT_MASKED,     /* 3 */
    OF_OXM_METADATA,               /* 4 */
    OF_OXM_METADATA_MASKED,        /* 5 */
    OF_OXM_ETH_DST,                /* 6 */
    OF_OXM_ETH_DST_MASKED,         /* 7 */
    OF_OXM_ETH_SRC,                /* 8 */
    OF_OXM_ETH_SRC_MASKED,         /* 9 */
    OF_OXM_ETH_TYPE,               /* 10 */
    OF_OXM_ETH_TYPE_MASKED,        /* 11 */
    OF_OXM_VLAN_VID,               /* 12 */
    OF_OXM_VLAN_VID_MASKED,        /* 13 */
    OF_OXM_VLAN_PCP,               /* 14 */
    OF_OXM_VLAN_PCP_MASKED,        /* 15 */
    OF_OXM_IP_DSCP,                /* 16 */
    OF_OXM_IP_DSCP_MASKED,         /* 17 */
    OF_OXM_IP_ECN,                 /* 18 */
    OF_OXM_IP_ECN_MASKED,          /* 19 */
    OF_OXM_IP_PROTO,               /* 20 */
    OF_OXM_IP_PROTO_MASKED,        /* 21 */
    OF_OXM_IPV4_SRC,               /* 22 */
    OF_OXM_IPV4_SRC_MASKED,        /* 23 */
    OF_OXM_IPV4_DST,               /* 24 */
    OF_OXM_IPV4_DST_MASKED,        /* 25 */
    OF_OXM_TCP_SRC,                /* 26 */
    OF_OXM_TCP_SRC_MASKED,         /* 27 */
    OF_OXM_TCP_DST,                /* 28 */
    OF_OXM_TCP_DST_MASKED,         /* 29 */
    OF_OXM_UDP_SRC,                /* 30 */
    OF_OXM_UDP_SRC_MASKED,         /* 31 */
    OF_OXM_UDP_DST,                /* 32 */
    OF_OXM_UDP_DST_MASKED,         /* 33 */
    OF_OXM_SCTP_SRC,               /* 34 */
    OF_OXM_SCTP_SRC_MASKED,        /* 35 */
    OF_OXM_SCTP_DST,               /* 36 */
    OF_OXM_SCTP_DST_MASKED,        /* 37 */
    OF_OXM_ICMPV4_TYPE,            /* 38 */
    OF_OXM_ICMPV4_TYPE_MASKED,     /* 39 */
    OF_OXM_ICMPV4_CODE,            /* 40 */
    OF_OXM_ICMPV4_CODE_MASKED,     /* 41 */
    OF_OXM_ARP_OP,                 /* 42 */
    OF_OXM_ARP_OP_MASKED,          /* 43 */
    OF_OXM_ARP_SPA,                /* 44 */
    OF_OXM_ARP_SPA_MASKED,         /* 45 */
    OF_OXM_ARP_TPA,                /* 46 */
    OF_OXM_ARP_TPA_MASKED,         /* 47 */
    OF_OXM_ARP_SHA,                /* 48 */
    OF_OXM_ARP_SHA_MASKED,         /* 49 */
    OF_OXM_ARP_THA,                /* 50 */
    OF_OXM_ARP_THA_MASKED,         /* 51 */
    OF_OXM_IPV6_SRC,               /* 52 */
    OF_OXM_IPV6_SRC_MASKED,        /* 53 */
    OF_OXM_IPV6_DST,               /* 54 */
    OF_OXM_IPV6_DST_MASKED,        /* 55 */
    OF_OXM_IPV6_FLABEL,            /* 56 */
    OF_OXM_IPV6_FLABEL_MASKED,     /* 57 */
    OF_OXM_ICMPV6_TYPE,            /* 58 */
    OF_OXM_ICMPV6_TYPE_MASKED,     /* 59 */
    OF_OXM_ICMPV6_CODE,            /* 60 */
    OF_OXM_ICMPV6_CODE_MASKED,     /* 61 */
    OF_OXM_IPV6_ND_TARGET,         /* 62 */
    OF_OXM_IPV6_ND_TARGET_MASKED,  /* 63 */
    OF_OXM_IPV6_ND_SLL,            /* 64 */
    OF_OXM_IPV6_ND_SLL_MASKED,     /* 65 */
    OF_OXM_IPV6_ND_TLL,            /* 66 */
    OF_OXM_IPV6_ND_TLL_MASKED,     /* 67 */
    OF_OXM_MPLS_LABEL,             /* 68 */
    OF_OXM_MPLS_LABEL_MASKED,      /* 69 */
    OF_OXM_MPLS_TC,                /* 70 */
    OF_OXM_MPLS_TC_MASKED          /* 71 */
};
static const of_object_id_t
of_oxm_type_to_id_v4[OF_OXM_ITEM_COUNT] = {
    OF_OXM_IN_PORT,                /* 0 */
    OF_OXM_IN_PORT_MASKED,         /* 1 */
    OF_OXM_IN_PHY_PORT,            /* 2 */
    OF_OXM_IN_PHY_PORT_MASKED,     /* 3 */
    OF_OXM_METADATA,               /* 4 */
    OF_OXM_METADATA_MASKED,        /* 5 */
    OF_OXM_ETH_DST,                /* 6 */
    OF_OXM_ETH_DST_MASKED,         /* 7 */
    OF_OXM_ETH_SRC,                /* 8 */
    OF_OXM_ETH_SRC_MASKED,         /* 9 */
    OF_OXM_ETH_TYPE,               /* 10 */
    OF_OXM_ETH_TYPE_MASKED,        /* 11 */
    OF_OXM_VLAN_VID,               /* 12 */
    OF_OXM_VLAN_VID_MASKED,        /* 13 */
    OF_OXM_VLAN_PCP,               /* 14 */
    OF_OXM_VLAN_PCP_MASKED,        /* 15 */
    OF_OXM_IP_DSCP,                /* 16 */
    OF_OXM_IP_DSCP_MASKED,         /* 17 */
    OF_OXM_IP_ECN,                 /* 18 */
    OF_OXM_IP_ECN_MASKED,          /* 19 */
    OF_OXM_IP_PROTO,               /* 20 */
    OF_OXM_IP_PROTO_MASKED,        /* 21 */
    OF_OXM_IPV4_SRC,               /* 22 */
    OF_OXM_IPV4_SRC_MASKED,        /* 23 */
    OF_OXM_IPV4_DST,               /* 24 */
    OF_OXM_IPV4_DST_MASKED,        /* 25 */
    OF_OXM_TCP_SRC,                /* 26 */
    OF_OXM_TCP_SRC_MASKED,         /* 27 */
    OF_OXM_TCP_DST,                /* 28 */
    OF_OXM_TCP_DST_MASKED,         /* 29 */
    OF_OXM_UDP_SRC,                /* 30 */
    OF_OXM_UDP_SRC_MASKED,         /* 31 */
    OF_OXM_UDP_DST,                /* 32 */
    OF_OXM_UDP_DST_MASKED,         /* 33 */
    OF_OXM_SCTP_SRC,               /* 34 */
    OF_OXM_SCTP_SRC_MASKED,        /* 35 */
    OF_OXM_SCTP_DST,               /* 36 */
    OF_OXM_SCTP_DST_MASKED,        /* 37 */
    OF_OXM_ICMPV4_TYPE,            /* 38 */
    OF_OXM_ICMPV4_TYPE_MASKED,     /* 39 */
    OF_OXM_ICMPV4_CODE,            /* 40 */
    OF_OXM_ICMPV4_CODE_MASKED,     /* 41 */
    OF_OXM_ARP_OP,                 /* 42 */
    OF_OXM_ARP_OP_MASKED,          /* 43 */
    OF_OXM_ARP_SPA,                /* 44 */
    OF_OXM_ARP_SPA_MASKED,         /* 45 */
    OF_OXM_ARP_TPA,                /* 46 */
    OF_OXM_ARP_TPA_MASKED,         /* 47 */
    OF_OXM_ARP_SHA,                /* 48 */
    OF_OXM_ARP_SHA_MASKED,         /* 49 */
    OF_OXM_ARP_THA,                /* 50 */
    OF_OXM_ARP_THA_MASKED,         /* 51 */
    OF_OXM_IPV6_SRC,               /* 52 */
    OF_OXM_IPV6_SRC_MASKED,        /* 53 */
    OF_OXM_IPV6_DST,               /* 54 */
    OF_OXM_IPV6_DST_MASKED,        /* 55 */
    OF_OXM_IPV6_FLABEL,            /* 56 */
    OF_OXM_IPV6_FLABEL_MASKED,     /* 57 */
    OF_OXM_ICMPV6_TYPE,            /* 58 */
    OF_OXM_ICMPV6_TYPE_MASKED,     /* 59 */
    OF_OXM_ICMPV6_CODE,            /* 60 */
    OF_OXM_ICMPV6_CODE_MASKED,     /* 61 */
    OF_OXM_IPV6_ND_TARGET,         /* 62 */
    OF_OXM_IPV6_ND_TARGET_MASKED,  /* 63 */
    OF_OXM_IPV6_ND_SLL,            /* 64 */
    OF_OXM_IPV6_ND_SLL_MASKED,     /* 65 */
    OF_OXM_IPV6_ND_TLL,            /* 66 */
    OF_OXM_IPV6_ND_TLL_MASKED,     /* 67 */
    OF_OXM_MPLS_LABEL,             /* 68 */
    OF_OXM_MPLS_LABEL_MASKED,      /* 69 */
    OF_OXM_MPLS_TC,                /* 70 */
    OF_OXM_MPLS_TC_MASKED          /* 71 */
};

/**
 * Maps from of_oxm wire type values to LOCI object ids
 *
 * Indexed by wire version which is 1-based.
 */

const of_object_id_t *const of_oxm_type_to_id[OF_VERSION_ARRAY_MAX] = {
    NULL,
    of_oxm_type_to_id_v1,
    of_oxm_type_to_id_v2,
    of_oxm_type_to_id_v3,
    of_oxm_type_to_id_v4,

};

static const of_object_id_t
of_message_type_to_id_v1[OF_MESSAGE_ITEM_COUNT] = {
    OF_HELLO,                      /* 0 */
    OF_ERROR_MSG,                  /* 1 */
    OF_ECHO_REQUEST,               /* 2 */
    OF_ECHO_REPLY,                 /* 3 */
    OF_EXPERIMENTER,               /* 4 */
    OF_FEATURES_REQUEST,           /* 5 */
    OF_FEATURES_REPLY,             /* 6 */
    OF_GET_CONFIG_REQUEST,         /* 7 */
    OF_GET_CONFIG_REPLY,           /* 8 */
    OF_SET_CONFIG,                 /* 9 */
    OF_PACKET_IN,                  /* 10 */
    OF_FLOW_REMOVED,               /* 11 */
    OF_PORT_STATUS,                /* 12 */
    OF_PACKET_OUT,                 /* 13 */
    OF_FLOW_MOD,                   /* 14 */
    OF_PORT_MOD,                   /* 15 */
    OF_STATS_REQUEST,              /* 16 */
    OF_STATS_REPLY,                /* 17 */
    OF_BARRIER_REQUEST,            /* 18 */
    OF_BARRIER_REPLY,              /* 19 */
    OF_QUEUE_GET_CONFIG_REQUEST,   /* 20 */
    OF_QUEUE_GET_CONFIG_REPLY,     /* 21 */
    OF_TABLE_MOD,                  /* 22 */
    OF_OBJECT_INVALID,             /* 23 (Invalid) */
    OF_OBJECT_INVALID,             /* 24 (Invalid) */
    OF_OBJECT_INVALID,             /* 25 (Invalid) */
    OF_OBJECT_INVALID,             /* 26 (Invalid) */
    OF_OBJECT_INVALID,             /* 27 (Invalid) */
    OF_OBJECT_INVALID,             /* 28 (Invalid) */
    OF_OBJECT_INVALID              /* 29 (Invalid) */
};
static const of_object_id_t
of_message_type_to_id_v2[OF_MESSAGE_ITEM_COUNT] = {
    OF_HELLO,                      /* 0 */
    OF_ERROR_MSG,                  /* 1 */
    OF_ECHO_REQUEST,               /* 2 */
    OF_ECHO_REPLY,                 /* 3 */
    OF_EXPERIMENTER,               /* 4 */
    OF_FEATURES_REQUEST,           /* 5 */
    OF_FEATURES_REPLY,             /* 6 */
    OF_GET_CONFIG_REQUEST,         /* 7 */
    OF_GET_CONFIG_REPLY,           /* 8 */
    OF_SET_CONFIG,                 /* 9 */
    OF_PACKET_IN,                  /* 10 */
    OF_FLOW_REMOVED,               /* 11 */
    OF_PORT_STATUS,                /* 12 */
    OF_PACKET_OUT,                 /* 13 */
    OF_FLOW_MOD,                   /* 14 */
    OF_GROUP_MOD,                  /* 15 */
    OF_PORT_MOD,                   /* 16 */
    OF_TABLE_MOD,                  /* 17 */
    OF_STATS_REQUEST,              /* 18 */
    OF_STATS_REPLY,                /* 19 */
    OF_BARRIER_REQUEST,            /* 20 */
    OF_BARRIER_REPLY,              /* 21 */
    OF_QUEUE_GET_CONFIG_REQUEST,   /* 22 */
    OF_QUEUE_GET_CONFIG_REPLY,     /* 23 */
    OF_OBJECT_INVALID,             /* 24 (Invalid) */
    OF_OBJECT_INVALID,             /* 25 (Invalid) */
    OF_OBJECT_INVALID,             /* 26 (Invalid) */
    OF_OBJECT_INVALID,             /* 27 (Invalid) */
    OF_OBJECT_INVALID,             /* 28 (Invalid) */
    OF_OBJECT_INVALID              /* 29 (Invalid) */
};
static const of_object_id_t
of_message_type_to_id_v3[OF_MESSAGE_ITEM_COUNT] = {
    OF_HELLO,                      /* 0 */
    OF_ERROR_MSG,                  /* 1 */
    OF_ECHO_REQUEST,               /* 2 */
    OF_ECHO_REPLY,                 /* 3 */
    OF_EXPERIMENTER,               /* 4 */
    OF_FEATURES_REQUEST,           /* 5 */
    OF_FEATURES_REPLY,             /* 6 */
    OF_GET_CONFIG_REQUEST,         /* 7 */
    OF_GET_CONFIG_REPLY,           /* 8 */
    OF_SET_CONFIG,                 /* 9 */
    OF_PACKET_IN,                  /* 10 */
    OF_FLOW_REMOVED,               /* 11 */
    OF_PORT_STATUS,                /* 12 */
    OF_PACKET_OUT,                 /* 13 */
    OF_FLOW_MOD,                   /* 14 */
    OF_GROUP_MOD,                  /* 15 */
    OF_PORT_MOD,                   /* 16 */
    OF_TABLE_MOD,                  /* 17 */
    OF_STATS_REQUEST,              /* 18 */
    OF_STATS_REPLY,                /* 19 */
    OF_BARRIER_REQUEST,            /* 20 */
    OF_BARRIER_REPLY,              /* 21 */
    OF_QUEUE_GET_CONFIG_REQUEST,   /* 22 */
    OF_QUEUE_GET_CONFIG_REPLY,     /* 23 */
    OF_ROLE_REQUEST,               /* 24 */
    OF_ROLE_REPLY,                 /* 25 */
    OF_OBJECT_INVALID,             /* 26 (Invalid) */
    OF_OBJECT_INVALID,             /* 27 (Invalid) */
    OF_OBJECT_INVALID,             /* 28 (Invalid) */
    OF_OBJECT_INVALID              /* 29 (Invalid) */
};
static const of_object_id_t
of_message_type_to_id_v4[OF_MESSAGE_ITEM_COUNT] = {
    OF_HELLO,                      /* 0 */
    OF_ERROR_MSG,                  /* 1 */
    OF_ECHO_REQUEST,               /* 2 */
    OF_ECHO_REPLY,                 /* 3 */
    OF_EXPERIMENTER,               /* 4 */
    OF_FEATURES_REQUEST,           /* 5 */
    OF_FEATURES_REPLY,             /* 6 */
    OF_GET_CONFIG_REQUEST,         /* 7 */
    OF_GET_CONFIG_REPLY,           /* 8 */
    OF_SET_CONFIG,                 /* 9 */
    OF_PACKET_IN,                  /* 10 */
    OF_FLOW_REMOVED,               /* 11 */
    OF_PORT_STATUS,                /* 12 */
    OF_PACKET_OUT,                 /* 13 */
    OF_FLOW_MOD,                   /* 14 */
    OF_GROUP_MOD,                  /* 15 */
    OF_PORT_MOD,                   /* 16 */
    OF_TABLE_MOD,                  /* 17 */
    OF_STATS_REQUEST,              /* 18 */
    OF_STATS_REPLY,                /* 19 */
    OF_BARRIER_REQUEST,            /* 20 */
    OF_BARRIER_REPLY,              /* 21 */
    OF_QUEUE_GET_CONFIG_REQUEST,   /* 22 */
    OF_QUEUE_GET_CONFIG_REPLY,     /* 23 */
    OF_ROLE_REQUEST,               /* 24 */
    OF_ROLE_REPLY,                 /* 25 */
    OF_ASYNC_GET_REQUEST,          /* 26 */
    OF_ASYNC_GET_REPLY,            /* 27 */
    OF_ASYNC_SET,                  /* 28 */
    OF_METER_MOD                   /* 29 */
};

/**
 * Maps from of_message wire type values to LOCI object ids
 *
 * Indexed by wire version which is 1-based.
 */

const of_object_id_t *const of_message_type_to_id[OF_VERSION_ARRAY_MAX] = {
    NULL,
    of_message_type_to_id_v1,
    of_message_type_to_id_v2,
    of_message_type_to_id_v3,
    of_message_type_to_id_v4,

};

static const of_object_id_t
of_bsn_tlv_type_to_id_v1[OF_BSN_TLV_ITEM_COUNT] = {
    OF_OBJECT_INVALID,             /* 0 (Invalid) */
    OF_OBJECT_INVALID,             /* 1 (Invalid) */
    OF_OBJECT_INVALID,             /* 2 (Invalid) */
    OF_OBJECT_INVALID,             /* 3 (Invalid) */
    OF_OBJECT_INVALID,             /* 4 (Invalid) */
    OF_OBJECT_INVALID,             /* 5 (Invalid) */
    OF_OBJECT_INVALID,             /* 6 (Invalid) */
    OF_OBJECT_INVALID,             /* 7 (Invalid) */
    OF_OBJECT_INVALID,             /* 8 (Invalid) */
    OF_OBJECT_INVALID,             /* 9 (Invalid) */
    OF_OBJECT_INVALID,             /* 10 (Invalid) */
    OF_OBJECT_INVALID,             /* 11 (Invalid) */
    OF_OBJECT_INVALID,             /* 12 (Invalid) */
    OF_OBJECT_INVALID,             /* 13 (Invalid) */
    OF_OBJECT_INVALID,             /* 14 (Invalid) */
    OF_OBJECT_INVALID,             /* 15 (Invalid) */
    OF_OBJECT_INVALID,             /* 16 (Invalid) */
    OF_OBJECT_INVALID,             /* 17 (Invalid) */
    OF_OBJECT_INVALID,             /* 18 (Invalid) */
    OF_OBJECT_INVALID              /* 19 (Invalid) */
};
static const of_object_id_t
of_bsn_tlv_type_to_id_v2[OF_BSN_TLV_ITEM_COUNT] = {
    OF_OBJECT_INVALID,             /* 0 (Invalid) */
    OF_OBJECT_INVALID,             /* 1 (Invalid) */
    OF_OBJECT_INVALID,             /* 2 (Invalid) */
    OF_OBJECT_INVALID,             /* 3 (Invalid) */
    OF_OBJECT_INVALID,             /* 4 (Invalid) */
    OF_OBJECT_INVALID,             /* 5 (Invalid) */
    OF_OBJECT_INVALID,             /* 6 (Invalid) */
    OF_OBJECT_INVALID,             /* 7 (Invalid) */
    OF_OBJECT_INVALID,             /* 8 (Invalid) */
    OF_OBJECT_INVALID,             /* 9 (Invalid) */
    OF_OBJECT_INVALID,             /* 10 (Invalid) */
    OF_OBJECT_INVALID,             /* 11 (Invalid) */
    OF_OBJECT_INVALID,             /* 12 (Invalid) */
    OF_OBJECT_INVALID,             /* 13 (Invalid) */
    OF_OBJECT_INVALID,             /* 14 (Invalid) */
    OF_OBJECT_INVALID,             /* 15 (Invalid) */
    OF_OBJECT_INVALID,             /* 16 (Invalid) */
    OF_OBJECT_INVALID,             /* 17 (Invalid) */
    OF_OBJECT_INVALID,             /* 18 (Invalid) */
    OF_OBJECT_INVALID              /* 19 (Invalid) */
};
static const of_object_id_t
of_bsn_tlv_type_to_id_v3[OF_BSN_TLV_ITEM_COUNT] = {
    OF_OBJECT_INVALID,             /* 0 (Invalid) */
    OF_OBJECT_INVALID,             /* 1 (Invalid) */
    OF_OBJECT_INVALID,             /* 2 (Invalid) */
    OF_OBJECT_INVALID,             /* 3 (Invalid) */
    OF_OBJECT_INVALID,             /* 4 (Invalid) */
    OF_OBJECT_INVALID,             /* 5 (Invalid) */
    OF_OBJECT_INVALID,             /* 6 (Invalid) */
    OF_OBJECT_INVALID,             /* 7 (Invalid) */
    OF_OBJECT_INVALID,             /* 8 (Invalid) */
    OF_OBJECT_INVALID,             /* 9 (Invalid) */
    OF_OBJECT_INVALID,             /* 10 (Invalid) */
    OF_OBJECT_INVALID,             /* 11 (Invalid) */
    OF_OBJECT_INVALID,             /* 12 (Invalid) */
    OF_OBJECT_INVALID,             /* 13 (Invalid) */
    OF_OBJECT_INVALID,             /* 14 (Invalid) */
    OF_OBJECT_INVALID,             /* 15 (Invalid) */
    OF_OBJECT_INVALID,             /* 16 (Invalid) */
    OF_OBJECT_INVALID,             /* 17 (Invalid) */
    OF_OBJECT_INVALID,             /* 18 (Invalid) */
    OF_OBJECT_INVALID              /* 19 (Invalid) */
};
static const of_object_id_t
of_bsn_tlv_type_to_id_v4[OF_BSN_TLV_ITEM_COUNT] = {
    OF_BSN_TLV_PORT,               /* 0 */
    OF_BSN_TLV_MAC,                /* 1 */
    OF_BSN_TLV_RX_PACKETS,         /* 2 */
    OF_BSN_TLV_TX_PACKETS,         /* 3 */
    OF_BSN_TLV_IPV4,               /* 4 */
    OF_BSN_TLV_IDLE_TIME,          /* 5 */
    OF_BSN_TLV_VLAN_VID,           /* 6 */
    OF_BSN_TLV_IDLE_NOTIFICATION,  /* 7 */
    OF_BSN_TLV_IDLE_TIMEOUT,       /* 8 */
    OF_BSN_TLV_UNICAST_QUERY_TIMEOUT, /* 9 */
    OF_BSN_TLV_BROADCAST_QUERY_TIMEOUT, /* 10 */
    OF_BSN_TLV_REQUEST_PACKETS,    /* 11 */
    OF_BSN_TLV_REPLY_PACKETS,      /* 12 */
    OF_BSN_TLV_MISS_PACKETS,       /* 13 */
    OF_BSN_TLV_CIRCUIT_ID,         /* 14 */
    OF_BSN_TLV_UDF_ID,             /* 15 */
    OF_BSN_TLV_UDF_ANCHOR,         /* 16 */
    OF_BSN_TLV_UDF_OFFSET,         /* 17 */
    OF_BSN_TLV_UDF_LENGTH,         /* 18 */
    OF_BSN_TLV_VRF                 /* 19 */
};

/**
 * Maps from of_bsn_tlv wire type values to LOCI object ids
 *
 * Indexed by wire version which is 1-based.
 */

const of_object_id_t *const of_bsn_tlv_type_to_id[OF_VERSION_ARRAY_MAX] = {
    NULL,
    of_bsn_tlv_type_to_id_v1,
    of_bsn_tlv_type_to_id_v2,
    of_bsn_tlv_type_to_id_v3,
    of_bsn_tlv_type_to_id_v4,

};


/**
 * An array with the number of bytes in the fixed length part
 * of each OF object
 */

static const int
of_object_fixed_len_v1[OF_OBJECT_COUNT] = {
    -1,   /* of_object is not instantiable */
    36,   /* 1: of_aggregate_stats_reply */
    56,   /* 2: of_aggregate_stats_request */
    -1,   /* 3: of_async_get_reply */
    -1,   /* 4: of_async_get_request */
    -1,   /* 5: of_async_set */
    12,   /* 6: of_bad_action_error_msg */
    -1,   /* 7: of_bad_instruction_error_msg */
    -1,   /* 8: of_bad_match_error_msg */
    12,   /* 9: of_bad_request_error_msg */
    8,    /* 10: of_barrier_reply */
    8,    /* 11: of_barrier_request */
    -1,   /* 12: of_bsn_arp_idle */
    20,   /* 13: of_bsn_bw_clear_data_reply */
    16,   /* 14: of_bsn_bw_clear_data_request */
    20,   /* 15: of_bsn_bw_enable_get_reply */
    16,   /* 16: of_bsn_bw_enable_get_request */
    24,   /* 17: of_bsn_bw_enable_set_reply */
    20,   /* 18: of_bsn_bw_enable_set_request */
    -1,   /* 19: of_bsn_controller_connections_reply */
    -1,   /* 20: of_bsn_controller_connections_request */
    -1,   /* 21: of_bsn_debug_counter_desc_stats_reply */
    -1,   /* 22: of_bsn_debug_counter_desc_stats_request */
    -1,   /* 23: of_bsn_debug_counter_stats_reply */
    -1,   /* 24: of_bsn_debug_counter_stats_request */
    -1,   /* 25: of_bsn_flow_checksum_bucket_stats_reply */
    -1,   /* 26: of_bsn_flow_checksum_bucket_stats_request */
    -1,   /* 27: of_bsn_flow_idle */
    -1,   /* 28: of_bsn_flow_idle_enable_get_reply */
    -1,   /* 29: of_bsn_flow_idle_enable_get_request */
    -1,   /* 30: of_bsn_flow_idle_enable_set_reply */
    -1,   /* 31: of_bsn_flow_idle_enable_set_request */
    -1,   /* 32: of_bsn_gentable_bucket_stats_reply */
    -1,   /* 33: of_bsn_gentable_bucket_stats_request */
    -1,   /* 34: of_bsn_gentable_clear_reply */
    -1,   /* 35: of_bsn_gentable_clear_request */
    -1,   /* 36: of_bsn_gentable_desc_stats_reply */
    -1,   /* 37: of_bsn_gentable_desc_stats_request */
    -1,   /* 38: of_bsn_gentable_entry_add */
    -1,   /* 39: of_bsn_gentable_entry_delete */
    -1,   /* 40: of_bsn_gentable_entry_desc_stats_reply */
    -1,   /* 41: of_bsn_gentable_entry_desc_stats_request */
    -1,   /* 42: of_bsn_gentable_entry_stats_reply */
    -1,   /* 43: of_bsn_gentable_entry_stats_request */
    -1,   /* 44: of_bsn_gentable_set_buckets_size */
    -1,   /* 45: of_bsn_gentable_stats_reply */
    -1,   /* 46: of_bsn_gentable_stats_request */
    16,   /* 47: of_bsn_get_interfaces_reply */
    16,   /* 48: of_bsn_get_interfaces_request */
    24,   /* 49: of_bsn_get_ip_mask_reply */
    24,   /* 50: of_bsn_get_ip_mask_request */
    24,   /* 51: of_bsn_get_l2_table_reply */
    16,   /* 52: of_bsn_get_l2_table_request */
    20,   /* 53: of_bsn_get_mirroring_reply */
    20,   /* 54: of_bsn_get_mirroring_request */
    -1,   /* 55: of_bsn_get_switch_pipeline_reply */
    -1,   /* 56: of_bsn_get_switch_pipeline_request */
    16,   /* 57: of_bsn_header */
    24,   /* 58: of_bsn_hybrid_get_reply */
    16,   /* 59: of_bsn_hybrid_get_request */
    -1,   /* 60: of_bsn_image_desc_stats_reply */
    -1,   /* 61: of_bsn_image_desc_stats_request */
    -1,   /* 62: of_bsn_lacp_convergence_notif */
    -1,   /* 63: of_bsn_lacp_stats_reply */
    -1,   /* 64: of_bsn_lacp_stats_request */
    23,   /* 65: of_bsn_pdu_rx_reply */
    26,   /* 66: of_bsn_pdu_rx_request */
    19,   /* 67: of_bsn_pdu_rx_timeout */
    23,   /* 68: of_bsn_pdu_tx_reply */
    26,   /* 69: of_bsn_pdu_tx_request */
    -1,   /* 70: of_bsn_port_counter_stats_reply */
    -1,   /* 71: of_bsn_port_counter_stats_request */
    -1,   /* 72: of_bsn_role_status */
    -1,   /* 73: of_bsn_set_aux_cxns_reply */
    -1,   /* 74: of_bsn_set_aux_cxns_request */
    24,   /* 75: of_bsn_set_ip_mask */
    24,   /* 76: of_bsn_set_l2_table_reply */
    24,   /* 77: of_bsn_set_l2_table_request */
    -1,   /* 78: of_bsn_set_lacp_reply */
    -1,   /* 79: of_bsn_set_lacp_request */
    20,   /* 80: of_bsn_set_mirroring */
    20,   /* 81: of_bsn_set_pktin_suppression_reply */
    32,   /* 82: of_bsn_set_pktin_suppression_request */
    -1,   /* 83: of_bsn_set_switch_pipeline_reply */
    -1,   /* 84: of_bsn_set_switch_pipeline_request */
    20,   /* 85: of_bsn_shell_command */
    16,   /* 86: of_bsn_shell_output */
    20,   /* 87: of_bsn_shell_status */
    24,   /* 88: of_bsn_stats_reply */
    24,   /* 89: of_bsn_stats_request */
    -1,   /* 90: of_bsn_switch_pipeline_stats_reply */
    -1,   /* 91: of_bsn_switch_pipeline_stats_request */
    -1,   /* 92: of_bsn_table_checksum_stats_reply */
    -1,   /* 93: of_bsn_table_checksum_stats_request */
    -1,   /* 94: of_bsn_table_set_buckets_size */
    -1,   /* 95: of_bsn_time_reply */
    -1,   /* 96: of_bsn_time_request */
    24,   /* 97: of_bsn_virtual_port_create_reply */
    20,   /* 98: of_bsn_virtual_port_create_request */
    20,   /* 99: of_bsn_virtual_port_remove_reply */
    20,   /* 100: of_bsn_virtual_port_remove_request */
    -1,   /* 101: of_bsn_vlan_counter_stats_reply */
    -1,   /* 102: of_bsn_vlan_counter_stats_request */
    1068, /* 103: of_desc_stats_reply */
    12,   /* 104: of_desc_stats_request */
    8,    /* 105: of_echo_reply */
    8,    /* 106: of_echo_request */
    10,   /* 107: of_error_msg */
    16,   /* 108: of_experimenter */
    -1,   /* 109: of_experimenter_error_msg */
    16,   /* 110: of_experimenter_stats_reply */
    16,   /* 111: of_experimenter_stats_request */
    32,   /* 112: of_features_reply */
    8,    /* 113: of_features_request */
    72,   /* 114: of_flow_add */
    72,   /* 115: of_flow_delete */
    72,   /* 116: of_flow_delete_strict */
    72,   /* 117: of_flow_mod */
    12,   /* 118: of_flow_mod_failed_error_msg */
    72,   /* 119: of_flow_modify */
    72,   /* 120: of_flow_modify_strict */
    88,   /* 121: of_flow_removed */
    12,   /* 122: of_flow_stats_reply */
    56,   /* 123: of_flow_stats_request */
    12,   /* 124: of_get_config_reply */
    8,    /* 125: of_get_config_request */
    -1,   /* 126: of_group_add */
    -1,   /* 127: of_group_delete */
    -1,   /* 128: of_group_desc_stats_reply */
    -1,   /* 129: of_group_desc_stats_request */
    -1,   /* 130: of_group_features_stats_reply */
    -1,   /* 131: of_group_features_stats_request */
    -1,   /* 132: of_group_mod */
    -1,   /* 133: of_group_mod_failed_error_msg */
    -1,   /* 134: of_group_modify */
    -1,   /* 135: of_group_stats_reply */
    -1,   /* 136: of_group_stats_request */
    8,    /* 137: of_header */
    8,    /* 138: of_hello */
    12,   /* 139: of_hello_failed_error_msg */
    -1,   /* 140: of_meter_config_stats_reply */
    -1,   /* 141: of_meter_config_stats_request */
    -1,   /* 142: of_meter_features_stats_reply */
    -1,   /* 143: of_meter_features_stats_request */
    -1,   /* 144: of_meter_mod */
    -1,   /* 145: of_meter_mod_failed_error_msg */
    -1,   /* 146: of_meter_stats_reply */
    -1,   /* 147: of_meter_stats_request */
    20,   /* 148: of_nicira_controller_role_reply */
    20,   /* 149: of_nicira_controller_role_request */
    16,   /* 150: of_nicira_header */
    18,   /* 151: of_packet_in */
    16,   /* 152: of_packet_out */
    -1,   /* 153: of_port_desc_stats_reply */
    -1,   /* 154: of_port_desc_stats_request */
    32,   /* 155: of_port_mod */
    12,   /* 156: of_port_mod_failed_error_msg */
    12,   /* 157: of_port_stats_reply */
    20,   /* 158: of_port_stats_request */
    64,   /* 159: of_port_status */
    16,   /* 160: of_queue_get_config_reply */
    12,   /* 161: of_queue_get_config_request */
    12,   /* 162: of_queue_op_failed_error_msg */
    12,   /* 163: of_queue_stats_reply */
    20,   /* 164: of_queue_stats_request */
    -1,   /* 165: of_role_reply */
    -1,   /* 166: of_role_request */
    -1,   /* 167: of_role_request_failed_error_msg */
    12,   /* 168: of_set_config */
    12,   /* 169: of_stats_reply */
    12,   /* 170: of_stats_request */
    -1,   /* 171: of_switch_config_failed_error_msg */
    -1,   /* 172: of_table_features_failed_error_msg */
    -1,   /* 173: of_table_features_stats_reply */
    -1,   /* 174: of_table_features_stats_request */
    16,   /* 175: of_table_mod */
    -1,   /* 176: of_table_mod_failed_error_msg */
    12,   /* 177: of_table_stats_reply */
    12,   /* 178: of_table_stats_request */
    8,    /* 179: of_action */
    16,   /* 180: of_action_bsn */
    24,   /* 181: of_action_bsn_mirror */
    16,   /* 182: of_action_bsn_set_tunnel_dst */
    -1,   /* 183: of_action_copy_ttl_in */
    -1,   /* 184: of_action_copy_ttl_out */
    -1,   /* 185: of_action_dec_mpls_ttl */
    -1,   /* 186: of_action_dec_nw_ttl */
    16,   /* 187: of_action_enqueue */
    8,    /* 188: of_action_experimenter */
    -1,   /* 189: of_action_group */
    8,    /* 190: of_action_header */
    -1,   /* 191: of_action_id */
    -1,   /* 192: of_action_id_bsn */
    -1,   /* 193: of_action_id_bsn_mirror */
    -1,   /* 194: of_action_id_bsn_set_tunnel_dst */
    -1,   /* 195: of_action_id_copy_ttl_in */
    -1,   /* 196: of_action_id_copy_ttl_out */
    -1,   /* 197: of_action_id_dec_mpls_ttl */
    -1,   /* 198: of_action_id_dec_nw_ttl */
    -1,   /* 199: of_action_id_experimenter */
    -1,   /* 200: of_action_id_group */
    -1,   /* 201: of_action_id_header */
    -1,   /* 202: of_action_id_nicira */
    -1,   /* 203: of_action_id_nicira_dec_ttl */
    -1,   /* 204: of_action_id_output */
    -1,   /* 205: of_action_id_pop_mpls */
    -1,   /* 206: of_action_id_pop_pbb */
    -1,   /* 207: of_action_id_pop_vlan */
    -1,   /* 208: of_action_id_push_mpls */
    -1,   /* 209: of_action_id_push_pbb */
    -1,   /* 210: of_action_id_push_vlan */
    -1,   /* 211: of_action_id_set_field */
    -1,   /* 212: of_action_id_set_mpls_ttl */
    -1,   /* 213: of_action_id_set_nw_ttl */
    -1,   /* 214: of_action_id_set_queue */
    16,   /* 215: of_action_nicira */
    16,   /* 216: of_action_nicira_dec_ttl */
    8,    /* 217: of_action_output */
    -1,   /* 218: of_action_pop_mpls */
    -1,   /* 219: of_action_pop_pbb */
    -1,   /* 220: of_action_pop_vlan */
    -1,   /* 221: of_action_push_mpls */
    -1,   /* 222: of_action_push_pbb */
    -1,   /* 223: of_action_push_vlan */
    16,   /* 224: of_action_set_dl_dst */
    16,   /* 225: of_action_set_dl_src */
    -1,   /* 226: of_action_set_field */
    -1,   /* 227: of_action_set_mpls_label */
    -1,   /* 228: of_action_set_mpls_tc */
    -1,   /* 229: of_action_set_mpls_ttl */
    8,    /* 230: of_action_set_nw_dst */
    -1,   /* 231: of_action_set_nw_ecn */
    8,    /* 232: of_action_set_nw_src */
    8,    /* 233: of_action_set_nw_tos */
    -1,   /* 234: of_action_set_nw_ttl */
    -1,   /* 235: of_action_set_queue */
    8,    /* 236: of_action_set_tp_dst */
    8,    /* 237: of_action_set_tp_src */
    8,    /* 238: of_action_set_vlan_pcp */
    8,    /* 239: of_action_set_vlan_vid */
    8,    /* 240: of_action_strip_vlan */
    -1,   /* 241: of_bsn_controller_connection */
    -1,   /* 242: of_bsn_debug_counter_desc_stats_entry */
    -1,   /* 243: of_bsn_debug_counter_stats_entry */
    -1,   /* 244: of_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 245: of_bsn_gentable_bucket_stats_entry */
    -1,   /* 246: of_bsn_gentable_desc_stats_entry */
    -1,   /* 247: of_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 248: of_bsn_gentable_entry_stats_entry */
    -1,   /* 249: of_bsn_gentable_stats_entry */
    32,   /* 250: of_bsn_interface */
    -1,   /* 251: of_bsn_lacp_stats_entry */
    -1,   /* 252: of_bsn_port_counter_stats_entry */
    -1,   /* 253: of_bsn_switch_pipeline_stats_entry */
    -1,   /* 254: of_bsn_table_checksum_stats_entry */
    -1,   /* 255: of_bsn_tlv */
    -1,   /* 256: of_bsn_tlv_broadcast_query_timeout */
    -1,   /* 257: of_bsn_tlv_circuit_id */
    -1,   /* 258: of_bsn_tlv_header */
    -1,   /* 259: of_bsn_tlv_idle_notification */
    -1,   /* 260: of_bsn_tlv_idle_time */
    -1,   /* 261: of_bsn_tlv_idle_timeout */
    -1,   /* 262: of_bsn_tlv_ipv4 */
    -1,   /* 263: of_bsn_tlv_mac */
    -1,   /* 264: of_bsn_tlv_miss_packets */
    -1,   /* 265: of_bsn_tlv_port */
    -1,   /* 266: of_bsn_tlv_reply_packets */
    -1,   /* 267: of_bsn_tlv_request_packets */
    -1,   /* 268: of_bsn_tlv_rx_packets */
    -1,   /* 269: of_bsn_tlv_tx_packets */
    -1,   /* 270: of_bsn_tlv_udf_anchor */
    -1,   /* 271: of_bsn_tlv_udf_id */
    -1,   /* 272: of_bsn_tlv_udf_length */
    -1,   /* 273: of_bsn_tlv_udf_offset */
    -1,   /* 274: of_bsn_tlv_unicast_query_timeout */
    -1,   /* 275: of_bsn_tlv_vlan_vid */
    -1,   /* 276: of_bsn_tlv_vrf */
    -1,   /* 277: of_bsn_vlan_counter_stats_entry */
    4,    /* 278: of_bsn_vport */
    4,    /* 279: of_bsn_vport_header */
    54,   /* 280: of_bsn_vport_l2gre */
    32,   /* 281: of_bsn_vport_q_in_q */
    -1,   /* 282: of_bucket */
    -1,   /* 283: of_bucket_counter */
    88,   /* 284: of_flow_stats_entry */
    -1,   /* 285: of_group_desc_stats_entry */
    -1,   /* 286: of_group_stats_entry */
    -1,   /* 287: of_hello_elem */
    -1,   /* 288: of_hello_elem_header */
    -1,   /* 289: of_hello_elem_versionbitmap */
    -1,   /* 290: of_instruction */
    -1,   /* 291: of_instruction_apply_actions */
    -1,   /* 292: of_instruction_bsn */
    -1,   /* 293: of_instruction_bsn_arp_offload */
    -1,   /* 294: of_instruction_bsn_deny */
    -1,   /* 295: of_instruction_bsn_dhcp_offload */
    -1,   /* 296: of_instruction_bsn_disable_split_horizon_check */
    -1,   /* 297: of_instruction_bsn_disable_src_mac_check */
    -1,   /* 298: of_instruction_bsn_packet_of_death */
    -1,   /* 299: of_instruction_bsn_permit */
    -1,   /* 300: of_instruction_bsn_prioritize_pdus */
    -1,   /* 301: of_instruction_clear_actions */
    -1,   /* 302: of_instruction_experimenter */
    -1,   /* 303: of_instruction_goto_table */
    -1,   /* 304: of_instruction_header */
    -1,   /* 305: of_instruction_id */
    -1,   /* 306: of_instruction_id_apply_actions */
    -1,   /* 307: of_instruction_id_bsn */
    -1,   /* 308: of_instruction_id_bsn_arp_offload */
    -1,   /* 309: of_instruction_id_bsn_deny */
    -1,   /* 310: of_instruction_id_bsn_dhcp_offload */
    -1,   /* 311: of_instruction_id_bsn_disable_split_horizon_check */
    -1,   /* 312: of_instruction_id_bsn_disable_src_mac_check */
    -1,   /* 313: of_instruction_id_bsn_packet_of_death */
    -1,   /* 314: of_instruction_id_bsn_permit */
    -1,   /* 315: of_instruction_id_bsn_prioritize_pdus */
    -1,   /* 316: of_instruction_id_clear_actions */
    -1,   /* 317: of_instruction_id_experimenter */
    -1,   /* 318: of_instruction_id_goto_table */
    -1,   /* 319: of_instruction_id_header */
    -1,   /* 320: of_instruction_id_meter */
    -1,   /* 321: of_instruction_id_write_actions */
    -1,   /* 322: of_instruction_id_write_metadata */
    -1,   /* 323: of_instruction_meter */
    -1,   /* 324: of_instruction_write_actions */
    -1,   /* 325: of_instruction_write_metadata */
    40,   /* 326: of_match_v1 */
    -1,   /* 327: of_match_v2 */
    -1,   /* 328: of_match_v3 */
    -1,   /* 329: of_meter_band */
    -1,   /* 330: of_meter_band_drop */
    -1,   /* 331: of_meter_band_dscp_remark */
    -1,   /* 332: of_meter_band_experimenter */
    -1,   /* 333: of_meter_band_header */
    -1,   /* 334: of_meter_band_stats */
    -1,   /* 335: of_meter_config */
    -1,   /* 336: of_meter_features */
    -1,   /* 337: of_meter_stats */
    -1,   /* 338: of_oxm */
    -1,   /* 339: of_oxm_arp_op */
    -1,   /* 340: of_oxm_arp_op_masked */
    -1,   /* 341: of_oxm_arp_sha */
    -1,   /* 342: of_oxm_arp_sha_masked */
    -1,   /* 343: of_oxm_arp_spa */
    -1,   /* 344: of_oxm_arp_spa_masked */
    -1,   /* 345: of_oxm_arp_tha */
    -1,   /* 346: of_oxm_arp_tha_masked */
    -1,   /* 347: of_oxm_arp_tpa */
    -1,   /* 348: of_oxm_arp_tpa_masked */
    -1,   /* 349: of_oxm_bsn_egr_port_group_id */
    -1,   /* 350: of_oxm_bsn_egr_port_group_id_masked */
    -1,   /* 351: of_oxm_bsn_global_vrf_allowed */
    -1,   /* 352: of_oxm_bsn_global_vrf_allowed_masked */
    -1,   /* 353: of_oxm_bsn_in_ports_128 */
    -1,   /* 354: of_oxm_bsn_in_ports_128_masked */
    -1,   /* 355: of_oxm_bsn_l3_dst_class_id */
    -1,   /* 356: of_oxm_bsn_l3_dst_class_id_masked */
    -1,   /* 357: of_oxm_bsn_l3_interface_class_id */
    -1,   /* 358: of_oxm_bsn_l3_interface_class_id_masked */
    -1,   /* 359: of_oxm_bsn_l3_src_class_id */
    -1,   /* 360: of_oxm_bsn_l3_src_class_id_masked */
    -1,   /* 361: of_oxm_bsn_lag_id */
    -1,   /* 362: of_oxm_bsn_lag_id_masked */
    -1,   /* 363: of_oxm_bsn_udf0 */
    -1,   /* 364: of_oxm_bsn_udf0_masked */
    -1,   /* 365: of_oxm_bsn_udf1 */
    -1,   /* 366: of_oxm_bsn_udf1_masked */
    -1,   /* 367: of_oxm_bsn_udf2 */
    -1,   /* 368: of_oxm_bsn_udf2_masked */
    -1,   /* 369: of_oxm_bsn_udf3 */
    -1,   /* 370: of_oxm_bsn_udf3_masked */
    -1,   /* 371: of_oxm_bsn_udf4 */
    -1,   /* 372: of_oxm_bsn_udf4_masked */
    -1,   /* 373: of_oxm_bsn_udf5 */
    -1,   /* 374: of_oxm_bsn_udf5_masked */
    -1,   /* 375: of_oxm_bsn_udf6 */
    -1,   /* 376: of_oxm_bsn_udf6_masked */
    -1,   /* 377: of_oxm_bsn_udf7 */
    -1,   /* 378: of_oxm_bsn_udf7_masked */
    -1,   /* 379: of_oxm_bsn_vrf */
    -1,   /* 380: of_oxm_bsn_vrf_masked */
    -1,   /* 381: of_oxm_eth_dst */
    -1,   /* 382: of_oxm_eth_dst_masked */
    -1,   /* 383: of_oxm_eth_src */
    -1,   /* 384: of_oxm_eth_src_masked */
    -1,   /* 385: of_oxm_eth_type */
    -1,   /* 386: of_oxm_eth_type_masked */
    -1,   /* 387: of_oxm_header */
    -1,   /* 388: of_oxm_icmpv4_code */
    -1,   /* 389: of_oxm_icmpv4_code_masked */
    -1,   /* 390: of_oxm_icmpv4_type */
    -1,   /* 391: of_oxm_icmpv4_type_masked */
    -1,   /* 392: of_oxm_icmpv6_code */
    -1,   /* 393: of_oxm_icmpv6_code_masked */
    -1,   /* 394: of_oxm_icmpv6_type */
    -1,   /* 395: of_oxm_icmpv6_type_masked */
    -1,   /* 396: of_oxm_in_phy_port */
    -1,   /* 397: of_oxm_in_phy_port_masked */
    -1,   /* 398: of_oxm_in_port */
    -1,   /* 399: of_oxm_in_port_masked */
    -1,   /* 400: of_oxm_ip_dscp */
    -1,   /* 401: of_oxm_ip_dscp_masked */
    -1,   /* 402: of_oxm_ip_ecn */
    -1,   /* 403: of_oxm_ip_ecn_masked */
    -1,   /* 404: of_oxm_ip_proto */
    -1,   /* 405: of_oxm_ip_proto_masked */
    -1,   /* 406: of_oxm_ipv4_dst */
    -1,   /* 407: of_oxm_ipv4_dst_masked */
    -1,   /* 408: of_oxm_ipv4_src */
    -1,   /* 409: of_oxm_ipv4_src_masked */
    -1,   /* 410: of_oxm_ipv6_dst */
    -1,   /* 411: of_oxm_ipv6_dst_masked */
    -1,   /* 412: of_oxm_ipv6_flabel */
    -1,   /* 413: of_oxm_ipv6_flabel_masked */
    -1,   /* 414: of_oxm_ipv6_nd_sll */
    -1,   /* 415: of_oxm_ipv6_nd_sll_masked */
    -1,   /* 416: of_oxm_ipv6_nd_target */
    -1,   /* 417: of_oxm_ipv6_nd_target_masked */
    -1,   /* 418: of_oxm_ipv6_nd_tll */
    -1,   /* 419: of_oxm_ipv6_nd_tll_masked */
    -1,   /* 420: of_oxm_ipv6_src */
    -1,   /* 421: of_oxm_ipv6_src_masked */
    -1,   /* 422: of_oxm_metadata */
    -1,   /* 423: of_oxm_metadata_masked */
    -1,   /* 424: of_oxm_mpls_label */
    -1,   /* 425: of_oxm_mpls_label_masked */
    -1,   /* 426: of_oxm_mpls_tc */
    -1,   /* 427: of_oxm_mpls_tc_masked */
    -1,   /* 428: of_oxm_sctp_dst */
    -1,   /* 429: of_oxm_sctp_dst_masked */
    -1,   /* 430: of_oxm_sctp_src */
    -1,   /* 431: of_oxm_sctp_src_masked */
    -1,   /* 432: of_oxm_tcp_dst */
    -1,   /* 433: of_oxm_tcp_dst_masked */
    -1,   /* 434: of_oxm_tcp_src */
    -1,   /* 435: of_oxm_tcp_src_masked */
    -1,   /* 436: of_oxm_udp_dst */
    -1,   /* 437: of_oxm_udp_dst_masked */
    -1,   /* 438: of_oxm_udp_src */
    -1,   /* 439: of_oxm_udp_src_masked */
    -1,   /* 440: of_oxm_vlan_pcp */
    -1,   /* 441: of_oxm_vlan_pcp_masked */
    -1,   /* 442: of_oxm_vlan_vid */
    -1,   /* 443: of_oxm_vlan_vid_masked */
    8,    /* 444: of_packet_queue */
    48,   /* 445: of_port_desc */
    104,  /* 446: of_port_stats_entry */
    8,    /* 447: of_queue_prop */
    -1,   /* 448: of_queue_prop_experimenter */
    8,    /* 449: of_queue_prop_header */
    -1,   /* 450: of_queue_prop_max_rate */
    16,   /* 451: of_queue_prop_min_rate */
    32,   /* 452: of_queue_stats_entry */
    -1,   /* 453: of_table_feature_prop */
    -1,   /* 454: of_table_feature_prop_apply_actions */
    -1,   /* 455: of_table_feature_prop_apply_actions_miss */
    -1,   /* 456: of_table_feature_prop_apply_setfield */
    -1,   /* 457: of_table_feature_prop_apply_setfield_miss */
    -1,   /* 458: of_table_feature_prop_experimenter */
    -1,   /* 459: of_table_feature_prop_experimenter_miss */
    -1,   /* 460: of_table_feature_prop_header */
    -1,   /* 461: of_table_feature_prop_instructions */
    -1,   /* 462: of_table_feature_prop_instructions_miss */
    -1,   /* 463: of_table_feature_prop_match */
    -1,   /* 464: of_table_feature_prop_next_tables */
    -1,   /* 465: of_table_feature_prop_next_tables_miss */
    -1,   /* 466: of_table_feature_prop_wildcards */
    -1,   /* 467: of_table_feature_prop_write_actions */
    -1,   /* 468: of_table_feature_prop_write_actions_miss */
    -1,   /* 469: of_table_feature_prop_write_setfield */
    -1,   /* 470: of_table_feature_prop_write_setfield_miss */
    -1,   /* 471: of_table_features */
    64,   /* 472: of_table_stats_entry */
    -1,   /* 473: of_uint32 */
    -1,   /* 474: of_uint64 */
    -1,   /* 475: of_uint8 */
    0,    /* 476: of_list_action */
    -1,   /* 477: of_list_action_id */
    -1,   /* 478: of_list_bsn_controller_connection */
    -1,   /* 479: of_list_bsn_debug_counter_desc_stats_entry */
    -1,   /* 480: of_list_bsn_debug_counter_stats_entry */
    -1,   /* 481: of_list_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 482: of_list_bsn_gentable_bucket_stats_entry */
    -1,   /* 483: of_list_bsn_gentable_desc_stats_entry */
    -1,   /* 484: of_list_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 485: of_list_bsn_gentable_entry_stats_entry */
    -1,   /* 486: of_list_bsn_gentable_stats_entry */
    0,    /* 487: of_list_bsn_interface */
    -1,   /* 488: of_list_bsn_lacp_stats_entry */
    -1,   /* 489: of_list_bsn_port_counter_stats_entry */
    -1,   /* 490: of_list_bsn_switch_pipeline_stats_entry */
    -1,   /* 491: of_list_bsn_table_checksum_stats_entry */
    -1,   /* 492: of_list_bsn_tlv */
    -1,   /* 493: of_list_bsn_vlan_counter_stats_entry */
    -1,   /* 494: of_list_bucket */
    -1,   /* 495: of_list_bucket_counter */
    0,    /* 496: of_list_flow_stats_entry */
    -1,   /* 497: of_list_group_desc_stats_entry */
    -1,   /* 498: of_list_group_stats_entry */
    -1,   /* 499: of_list_hello_elem */
    -1,   /* 500: of_list_instruction */
    -1,   /* 501: of_list_instruction_id */
    -1,   /* 502: of_list_meter_band */
    -1,   /* 503: of_list_meter_band_stats */
    -1,   /* 504: of_list_meter_stats */
    -1,   /* 505: of_list_oxm */
    0,    /* 506: of_list_packet_queue */
    0,    /* 507: of_list_port_desc */
    0,    /* 508: of_list_port_stats_entry */
    0,    /* 509: of_list_queue_prop */
    0,    /* 510: of_list_queue_stats_entry */
    -1,   /* 511: of_list_table_feature_prop */
    -1,   /* 512: of_list_table_features */
    0,    /* 513: of_list_table_stats_entry */
    -1,   /* 514: of_list_uint32 */
    -1,   /* 515: of_list_uint64 */
    -1    /* 516: of_list_uint8 */
};

static const int
of_object_fixed_len_v2[OF_OBJECT_COUNT] = {
    -1,   /* of_object is not instantiable */
    40,   /* 1: of_aggregate_stats_reply */
    136,  /* 2: of_aggregate_stats_request */
    -1,   /* 3: of_async_get_reply */
    -1,   /* 4: of_async_get_request */
    -1,   /* 5: of_async_set */
    12,   /* 6: of_bad_action_error_msg */
    12,   /* 7: of_bad_instruction_error_msg */
    12,   /* 8: of_bad_match_error_msg */
    12,   /* 9: of_bad_request_error_msg */
    8,    /* 10: of_barrier_reply */
    8,    /* 11: of_barrier_request */
    -1,   /* 12: of_bsn_arp_idle */
    20,   /* 13: of_bsn_bw_clear_data_reply */
    16,   /* 14: of_bsn_bw_clear_data_request */
    20,   /* 15: of_bsn_bw_enable_get_reply */
    16,   /* 16: of_bsn_bw_enable_get_request */
    24,   /* 17: of_bsn_bw_enable_set_reply */
    20,   /* 18: of_bsn_bw_enable_set_request */
    -1,   /* 19: of_bsn_controller_connections_reply */
    -1,   /* 20: of_bsn_controller_connections_request */
    -1,   /* 21: of_bsn_debug_counter_desc_stats_reply */
    -1,   /* 22: of_bsn_debug_counter_desc_stats_request */
    -1,   /* 23: of_bsn_debug_counter_stats_reply */
    -1,   /* 24: of_bsn_debug_counter_stats_request */
    -1,   /* 25: of_bsn_flow_checksum_bucket_stats_reply */
    -1,   /* 26: of_bsn_flow_checksum_bucket_stats_request */
    -1,   /* 27: of_bsn_flow_idle */
    -1,   /* 28: of_bsn_flow_idle_enable_get_reply */
    -1,   /* 29: of_bsn_flow_idle_enable_get_request */
    -1,   /* 30: of_bsn_flow_idle_enable_set_reply */
    -1,   /* 31: of_bsn_flow_idle_enable_set_request */
    -1,   /* 32: of_bsn_gentable_bucket_stats_reply */
    -1,   /* 33: of_bsn_gentable_bucket_stats_request */
    -1,   /* 34: of_bsn_gentable_clear_reply */
    -1,   /* 35: of_bsn_gentable_clear_request */
    -1,   /* 36: of_bsn_gentable_desc_stats_reply */
    -1,   /* 37: of_bsn_gentable_desc_stats_request */
    -1,   /* 38: of_bsn_gentable_entry_add */
    -1,   /* 39: of_bsn_gentable_entry_delete */
    -1,   /* 40: of_bsn_gentable_entry_desc_stats_reply */
    -1,   /* 41: of_bsn_gentable_entry_desc_stats_request */
    -1,   /* 42: of_bsn_gentable_entry_stats_reply */
    -1,   /* 43: of_bsn_gentable_entry_stats_request */
    -1,   /* 44: of_bsn_gentable_set_buckets_size */
    -1,   /* 45: of_bsn_gentable_stats_reply */
    -1,   /* 46: of_bsn_gentable_stats_request */
    16,   /* 47: of_bsn_get_interfaces_reply */
    16,   /* 48: of_bsn_get_interfaces_request */
    -1,   /* 49: of_bsn_get_ip_mask_reply */
    -1,   /* 50: of_bsn_get_ip_mask_request */
    -1,   /* 51: of_bsn_get_l2_table_reply */
    -1,   /* 52: of_bsn_get_l2_table_request */
    20,   /* 53: of_bsn_get_mirroring_reply */
    20,   /* 54: of_bsn_get_mirroring_request */
    -1,   /* 55: of_bsn_get_switch_pipeline_reply */
    -1,   /* 56: of_bsn_get_switch_pipeline_request */
    16,   /* 57: of_bsn_header */
    -1,   /* 58: of_bsn_hybrid_get_reply */
    -1,   /* 59: of_bsn_hybrid_get_request */
    -1,   /* 60: of_bsn_image_desc_stats_reply */
    -1,   /* 61: of_bsn_image_desc_stats_request */
    -1,   /* 62: of_bsn_lacp_convergence_notif */
    -1,   /* 63: of_bsn_lacp_stats_reply */
    -1,   /* 64: of_bsn_lacp_stats_request */
    25,   /* 65: of_bsn_pdu_rx_reply */
    28,   /* 66: of_bsn_pdu_rx_request */
    21,   /* 67: of_bsn_pdu_rx_timeout */
    25,   /* 68: of_bsn_pdu_tx_reply */
    28,   /* 69: of_bsn_pdu_tx_request */
    -1,   /* 70: of_bsn_port_counter_stats_reply */
    -1,   /* 71: of_bsn_port_counter_stats_request */
    -1,   /* 72: of_bsn_role_status */
    -1,   /* 73: of_bsn_set_aux_cxns_reply */
    -1,   /* 74: of_bsn_set_aux_cxns_request */
    -1,   /* 75: of_bsn_set_ip_mask */
    -1,   /* 76: of_bsn_set_l2_table_reply */
    -1,   /* 77: of_bsn_set_l2_table_request */
    -1,   /* 78: of_bsn_set_lacp_reply */
    -1,   /* 79: of_bsn_set_lacp_request */
    20,   /* 80: of_bsn_set_mirroring */
    20,   /* 81: of_bsn_set_pktin_suppression_reply */
    32,   /* 82: of_bsn_set_pktin_suppression_request */
    -1,   /* 83: of_bsn_set_switch_pipeline_reply */
    -1,   /* 84: of_bsn_set_switch_pipeline_request */
    -1,   /* 85: of_bsn_shell_command */
    -1,   /* 86: of_bsn_shell_output */
    -1,   /* 87: of_bsn_shell_status */
    24,   /* 88: of_bsn_stats_reply */
    24,   /* 89: of_bsn_stats_request */
    -1,   /* 90: of_bsn_switch_pipeline_stats_reply */
    -1,   /* 91: of_bsn_switch_pipeline_stats_request */
    -1,   /* 92: of_bsn_table_checksum_stats_reply */
    -1,   /* 93: of_bsn_table_checksum_stats_request */
    -1,   /* 94: of_bsn_table_set_buckets_size */
    -1,   /* 95: of_bsn_time_reply */
    -1,   /* 96: of_bsn_time_request */
    24,   /* 97: of_bsn_virtual_port_create_reply */
    20,   /* 98: of_bsn_virtual_port_create_request */
    20,   /* 99: of_bsn_virtual_port_remove_reply */
    20,   /* 100: of_bsn_virtual_port_remove_request */
    -1,   /* 101: of_bsn_vlan_counter_stats_reply */
    -1,   /* 102: of_bsn_vlan_counter_stats_request */
    1072, /* 103: of_desc_stats_reply */
    16,   /* 104: of_desc_stats_request */
    8,    /* 105: of_echo_reply */
    8,    /* 106: of_echo_request */
    10,   /* 107: of_error_msg */
    16,   /* 108: of_experimenter */
    -1,   /* 109: of_experimenter_error_msg */
    24,   /* 110: of_experimenter_stats_reply */
    24,   /* 111: of_experimenter_stats_request */
    32,   /* 112: of_features_reply */
    8,    /* 113: of_features_request */
    136,  /* 114: of_flow_add */
    136,  /* 115: of_flow_delete */
    136,  /* 116: of_flow_delete_strict */
    136,  /* 117: of_flow_mod */
    12,   /* 118: of_flow_mod_failed_error_msg */
    136,  /* 119: of_flow_modify */
    136,  /* 120: of_flow_modify_strict */
    136,  /* 121: of_flow_removed */
    16,   /* 122: of_flow_stats_reply */
    136,  /* 123: of_flow_stats_request */
    12,   /* 124: of_get_config_reply */
    8,    /* 125: of_get_config_request */
    16,   /* 126: of_group_add */
    16,   /* 127: of_group_delete */
    16,   /* 128: of_group_desc_stats_reply */
    16,   /* 129: of_group_desc_stats_request */
    -1,   /* 130: of_group_features_stats_reply */
    -1,   /* 131: of_group_features_stats_request */
    16,   /* 132: of_group_mod */
    12,   /* 133: of_group_mod_failed_error_msg */
    16,   /* 134: of_group_modify */
    16,   /* 135: of_group_stats_reply */
    24,   /* 136: of_group_stats_request */
    8,    /* 137: of_header */
    8,    /* 138: of_hello */
    12,   /* 139: of_hello_failed_error_msg */
    -1,   /* 140: of_meter_config_stats_reply */
    -1,   /* 141: of_meter_config_stats_request */
    -1,   /* 142: of_meter_features_stats_reply */
    -1,   /* 143: of_meter_features_stats_request */
    -1,   /* 144: of_meter_mod */
    -1,   /* 145: of_meter_mod_failed_error_msg */
    -1,   /* 146: of_meter_stats_reply */
    -1,   /* 147: of_meter_stats_request */
    -1,   /* 148: of_nicira_controller_role_reply */
    -1,   /* 149: of_nicira_controller_role_request */
    16,   /* 150: of_nicira_header */
    24,   /* 151: of_packet_in */
    24,   /* 152: of_packet_out */
    -1,   /* 153: of_port_desc_stats_reply */
    -1,   /* 154: of_port_desc_stats_request */
    40,   /* 155: of_port_mod */
    12,   /* 156: of_port_mod_failed_error_msg */
    16,   /* 157: of_port_stats_reply */
    24,   /* 158: of_port_stats_request */
    80,   /* 159: of_port_status */
    16,   /* 160: of_queue_get_config_reply */
    16,   /* 161: of_queue_get_config_request */
    12,   /* 162: of_queue_op_failed_error_msg */
    16,   /* 163: of_queue_stats_reply */
    24,   /* 164: of_queue_stats_request */
    -1,   /* 165: of_role_reply */
    -1,   /* 166: of_role_request */
    -1,   /* 167: of_role_request_failed_error_msg */
    12,   /* 168: of_set_config */
    16,   /* 169: of_stats_reply */
    16,   /* 170: of_stats_request */
    12,   /* 171: of_switch_config_failed_error_msg */
    -1,   /* 172: of_table_features_failed_error_msg */
    -1,   /* 173: of_table_features_stats_reply */
    -1,   /* 174: of_table_features_stats_request */
    16,   /* 175: of_table_mod */
    12,   /* 176: of_table_mod_failed_error_msg */
    16,   /* 177: of_table_stats_reply */
    16,   /* 178: of_table_stats_request */
    8,    /* 179: of_action */
    16,   /* 180: of_action_bsn */
    24,   /* 181: of_action_bsn_mirror */
    16,   /* 182: of_action_bsn_set_tunnel_dst */
    8,    /* 183: of_action_copy_ttl_in */
    8,    /* 184: of_action_copy_ttl_out */
    8,    /* 185: of_action_dec_mpls_ttl */
    8,    /* 186: of_action_dec_nw_ttl */
    -1,   /* 187: of_action_enqueue */
    8,    /* 188: of_action_experimenter */
    8,    /* 189: of_action_group */
    8,    /* 190: of_action_header */
    -1,   /* 191: of_action_id */
    -1,   /* 192: of_action_id_bsn */
    -1,   /* 193: of_action_id_bsn_mirror */
    -1,   /* 194: of_action_id_bsn_set_tunnel_dst */
    -1,   /* 195: of_action_id_copy_ttl_in */
    -1,   /* 196: of_action_id_copy_ttl_out */
    -1,   /* 197: of_action_id_dec_mpls_ttl */
    -1,   /* 198: of_action_id_dec_nw_ttl */
    -1,   /* 199: of_action_id_experimenter */
    -1,   /* 200: of_action_id_group */
    -1,   /* 201: of_action_id_header */
    -1,   /* 202: of_action_id_nicira */
    -1,   /* 203: of_action_id_nicira_dec_ttl */
    -1,   /* 204: of_action_id_output */
    -1,   /* 205: of_action_id_pop_mpls */
    -1,   /* 206: of_action_id_pop_pbb */
    -1,   /* 207: of_action_id_pop_vlan */
    -1,   /* 208: of_action_id_push_mpls */
    -1,   /* 209: of_action_id_push_pbb */
    -1,   /* 210: of_action_id_push_vlan */
    -1,   /* 211: of_action_id_set_field */
    -1,   /* 212: of_action_id_set_mpls_ttl */
    -1,   /* 213: of_action_id_set_nw_ttl */
    -1,   /* 214: of_action_id_set_queue */
    16,   /* 215: of_action_nicira */
    16,   /* 216: of_action_nicira_dec_ttl */
    16,   /* 217: of_action_output */
    8,    /* 218: of_action_pop_mpls */
    -1,   /* 219: of_action_pop_pbb */
    8,    /* 220: of_action_pop_vlan */
    8,    /* 221: of_action_push_mpls */
    -1,   /* 222: of_action_push_pbb */
    8,    /* 223: of_action_push_vlan */
    16,   /* 224: of_action_set_dl_dst */
    16,   /* 225: of_action_set_dl_src */
    -1,   /* 226: of_action_set_field */
    8,    /* 227: of_action_set_mpls_label */
    8,    /* 228: of_action_set_mpls_tc */
    8,    /* 229: of_action_set_mpls_ttl */
    8,    /* 230: of_action_set_nw_dst */
    8,    /* 231: of_action_set_nw_ecn */
    8,    /* 232: of_action_set_nw_src */
    8,    /* 233: of_action_set_nw_tos */
    8,    /* 234: of_action_set_nw_ttl */
    8,    /* 235: of_action_set_queue */
    8,    /* 236: of_action_set_tp_dst */
    8,    /* 237: of_action_set_tp_src */
    8,    /* 238: of_action_set_vlan_pcp */
    8,    /* 239: of_action_set_vlan_vid */
    -1,   /* 240: of_action_strip_vlan */
    -1,   /* 241: of_bsn_controller_connection */
    -1,   /* 242: of_bsn_debug_counter_desc_stats_entry */
    -1,   /* 243: of_bsn_debug_counter_stats_entry */
    -1,   /* 244: of_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 245: of_bsn_gentable_bucket_stats_entry */
    -1,   /* 246: of_bsn_gentable_desc_stats_entry */
    -1,   /* 247: of_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 248: of_bsn_gentable_entry_stats_entry */
    -1,   /* 249: of_bsn_gentable_stats_entry */
    32,   /* 250: of_bsn_interface */
    -1,   /* 251: of_bsn_lacp_stats_entry */
    -1,   /* 252: of_bsn_port_counter_stats_entry */
    -1,   /* 253: of_bsn_switch_pipeline_stats_entry */
    -1,   /* 254: of_bsn_table_checksum_stats_entry */
    -1,   /* 255: of_bsn_tlv */
    -1,   /* 256: of_bsn_tlv_broadcast_query_timeout */
    -1,   /* 257: of_bsn_tlv_circuit_id */
    -1,   /* 258: of_bsn_tlv_header */
    -1,   /* 259: of_bsn_tlv_idle_notification */
    -1,   /* 260: of_bsn_tlv_idle_time */
    -1,   /* 261: of_bsn_tlv_idle_timeout */
    -1,   /* 262: of_bsn_tlv_ipv4 */
    -1,   /* 263: of_bsn_tlv_mac */
    -1,   /* 264: of_bsn_tlv_miss_packets */
    -1,   /* 265: of_bsn_tlv_port */
    -1,   /* 266: of_bsn_tlv_reply_packets */
    -1,   /* 267: of_bsn_tlv_request_packets */
    -1,   /* 268: of_bsn_tlv_rx_packets */
    -1,   /* 269: of_bsn_tlv_tx_packets */
    -1,   /* 270: of_bsn_tlv_udf_anchor */
    -1,   /* 271: of_bsn_tlv_udf_id */
    -1,   /* 272: of_bsn_tlv_udf_length */
    -1,   /* 273: of_bsn_tlv_udf_offset */
    -1,   /* 274: of_bsn_tlv_unicast_query_timeout */
    -1,   /* 275: of_bsn_tlv_vlan_vid */
    -1,   /* 276: of_bsn_tlv_vrf */
    -1,   /* 277: of_bsn_vlan_counter_stats_entry */
    4,    /* 278: of_bsn_vport */
    4,    /* 279: of_bsn_vport_header */
    56,   /* 280: of_bsn_vport_l2gre */
    32,   /* 281: of_bsn_vport_q_in_q */
    16,   /* 282: of_bucket */
    16,   /* 283: of_bucket_counter */
    136,  /* 284: of_flow_stats_entry */
    8,    /* 285: of_group_desc_stats_entry */
    32,   /* 286: of_group_stats_entry */
    -1,   /* 287: of_hello_elem */
    -1,   /* 288: of_hello_elem_header */
    -1,   /* 289: of_hello_elem_versionbitmap */
    8,    /* 290: of_instruction */
    8,    /* 291: of_instruction_apply_actions */
    -1,   /* 292: of_instruction_bsn */
    -1,   /* 293: of_instruction_bsn_arp_offload */
    -1,   /* 294: of_instruction_bsn_deny */
    -1,   /* 295: of_instruction_bsn_dhcp_offload */
    -1,   /* 296: of_instruction_bsn_disable_split_horizon_check */
    -1,   /* 297: of_instruction_bsn_disable_src_mac_check */
    -1,   /* 298: of_instruction_bsn_packet_of_death */
    -1,   /* 299: of_instruction_bsn_permit */
    -1,   /* 300: of_instruction_bsn_prioritize_pdus */
    8,    /* 301: of_instruction_clear_actions */
    8,    /* 302: of_instruction_experimenter */
    8,    /* 303: of_instruction_goto_table */
    8,    /* 304: of_instruction_header */
    -1,   /* 305: of_instruction_id */
    -1,   /* 306: of_instruction_id_apply_actions */
    -1,   /* 307: of_instruction_id_bsn */
    -1,   /* 308: of_instruction_id_bsn_arp_offload */
    -1,   /* 309: of_instruction_id_bsn_deny */
    -1,   /* 310: of_instruction_id_bsn_dhcp_offload */
    -1,   /* 311: of_instruction_id_bsn_disable_split_horizon_check */
    -1,   /* 312: of_instruction_id_bsn_disable_src_mac_check */
    -1,   /* 313: of_instruction_id_bsn_packet_of_death */
    -1,   /* 314: of_instruction_id_bsn_permit */
    -1,   /* 315: of_instruction_id_bsn_prioritize_pdus */
    -1,   /* 316: of_instruction_id_clear_actions */
    -1,   /* 317: of_instruction_id_experimenter */
    -1,   /* 318: of_instruction_id_goto_table */
    -1,   /* 319: of_instruction_id_header */
    -1,   /* 320: of_instruction_id_meter */
    -1,   /* 321: of_instruction_id_write_actions */
    -1,   /* 322: of_instruction_id_write_metadata */
    -1,   /* 323: of_instruction_meter */
    8,    /* 324: of_instruction_write_actions */
    24,   /* 325: of_instruction_write_metadata */
    -1,   /* 326: of_match_v1 */
    88,   /* 327: of_match_v2 */
    -1,   /* 328: of_match_v3 */
    -1,   /* 329: of_meter_band */
    -1,   /* 330: of_meter_band_drop */
    -1,   /* 331: of_meter_band_dscp_remark */
    -1,   /* 332: of_meter_band_experimenter */
    -1,   /* 333: of_meter_band_header */
    -1,   /* 334: of_meter_band_stats */
    -1,   /* 335: of_meter_config */
    -1,   /* 336: of_meter_features */
    -1,   /* 337: of_meter_stats */
    -1,   /* 338: of_oxm */
    -1,   /* 339: of_oxm_arp_op */
    -1,   /* 340: of_oxm_arp_op_masked */
    -1,   /* 341: of_oxm_arp_sha */
    -1,   /* 342: of_oxm_arp_sha_masked */
    -1,   /* 343: of_oxm_arp_spa */
    -1,   /* 344: of_oxm_arp_spa_masked */
    -1,   /* 345: of_oxm_arp_tha */
    -1,   /* 346: of_oxm_arp_tha_masked */
    -1,   /* 347: of_oxm_arp_tpa */
    -1,   /* 348: of_oxm_arp_tpa_masked */
    -1,   /* 349: of_oxm_bsn_egr_port_group_id */
    -1,   /* 350: of_oxm_bsn_egr_port_group_id_masked */
    -1,   /* 351: of_oxm_bsn_global_vrf_allowed */
    -1,   /* 352: of_oxm_bsn_global_vrf_allowed_masked */
    -1,   /* 353: of_oxm_bsn_in_ports_128 */
    -1,   /* 354: of_oxm_bsn_in_ports_128_masked */
    -1,   /* 355: of_oxm_bsn_l3_dst_class_id */
    -1,   /* 356: of_oxm_bsn_l3_dst_class_id_masked */
    -1,   /* 357: of_oxm_bsn_l3_interface_class_id */
    -1,   /* 358: of_oxm_bsn_l3_interface_class_id_masked */
    -1,   /* 359: of_oxm_bsn_l3_src_class_id */
    -1,   /* 360: of_oxm_bsn_l3_src_class_id_masked */
    -1,   /* 361: of_oxm_bsn_lag_id */
    -1,   /* 362: of_oxm_bsn_lag_id_masked */
    -1,   /* 363: of_oxm_bsn_udf0 */
    -1,   /* 364: of_oxm_bsn_udf0_masked */
    -1,   /* 365: of_oxm_bsn_udf1 */
    -1,   /* 366: of_oxm_bsn_udf1_masked */
    -1,   /* 367: of_oxm_bsn_udf2 */
    -1,   /* 368: of_oxm_bsn_udf2_masked */
    -1,   /* 369: of_oxm_bsn_udf3 */
    -1,   /* 370: of_oxm_bsn_udf3_masked */
    -1,   /* 371: of_oxm_bsn_udf4 */
    -1,   /* 372: of_oxm_bsn_udf4_masked */
    -1,   /* 373: of_oxm_bsn_udf5 */
    -1,   /* 374: of_oxm_bsn_udf5_masked */
    -1,   /* 375: of_oxm_bsn_udf6 */
    -1,   /* 376: of_oxm_bsn_udf6_masked */
    -1,   /* 377: of_oxm_bsn_udf7 */
    -1,   /* 378: of_oxm_bsn_udf7_masked */
    -1,   /* 379: of_oxm_bsn_vrf */
    -1,   /* 380: of_oxm_bsn_vrf_masked */
    -1,   /* 381: of_oxm_eth_dst */
    -1,   /* 382: of_oxm_eth_dst_masked */
    -1,   /* 383: of_oxm_eth_src */
    -1,   /* 384: of_oxm_eth_src_masked */
    -1,   /* 385: of_oxm_eth_type */
    -1,   /* 386: of_oxm_eth_type_masked */
    -1,   /* 387: of_oxm_header */
    -1,   /* 388: of_oxm_icmpv4_code */
    -1,   /* 389: of_oxm_icmpv4_code_masked */
    -1,   /* 390: of_oxm_icmpv4_type */
    -1,   /* 391: of_oxm_icmpv4_type_masked */
    -1,   /* 392: of_oxm_icmpv6_code */
    -1,   /* 393: of_oxm_icmpv6_code_masked */
    -1,   /* 394: of_oxm_icmpv6_type */
    -1,   /* 395: of_oxm_icmpv6_type_masked */
    -1,   /* 396: of_oxm_in_phy_port */
    -1,   /* 397: of_oxm_in_phy_port_masked */
    -1,   /* 398: of_oxm_in_port */
    -1,   /* 399: of_oxm_in_port_masked */
    -1,   /* 400: of_oxm_ip_dscp */
    -1,   /* 401: of_oxm_ip_dscp_masked */
    -1,   /* 402: of_oxm_ip_ecn */
    -1,   /* 403: of_oxm_ip_ecn_masked */
    -1,   /* 404: of_oxm_ip_proto */
    -1,   /* 405: of_oxm_ip_proto_masked */
    -1,   /* 406: of_oxm_ipv4_dst */
    -1,   /* 407: of_oxm_ipv4_dst_masked */
    -1,   /* 408: of_oxm_ipv4_src */
    -1,   /* 409: of_oxm_ipv4_src_masked */
    -1,   /* 410: of_oxm_ipv6_dst */
    -1,   /* 411: of_oxm_ipv6_dst_masked */
    -1,   /* 412: of_oxm_ipv6_flabel */
    -1,   /* 413: of_oxm_ipv6_flabel_masked */
    -1,   /* 414: of_oxm_ipv6_nd_sll */
    -1,   /* 415: of_oxm_ipv6_nd_sll_masked */
    -1,   /* 416: of_oxm_ipv6_nd_target */
    -1,   /* 417: of_oxm_ipv6_nd_target_masked */
    -1,   /* 418: of_oxm_ipv6_nd_tll */
    -1,   /* 419: of_oxm_ipv6_nd_tll_masked */
    -1,   /* 420: of_oxm_ipv6_src */
    -1,   /* 421: of_oxm_ipv6_src_masked */
    -1,   /* 422: of_oxm_metadata */
    -1,   /* 423: of_oxm_metadata_masked */
    -1,   /* 424: of_oxm_mpls_label */
    -1,   /* 425: of_oxm_mpls_label_masked */
    -1,   /* 426: of_oxm_mpls_tc */
    -1,   /* 427: of_oxm_mpls_tc_masked */
    -1,   /* 428: of_oxm_sctp_dst */
    -1,   /* 429: of_oxm_sctp_dst_masked */
    -1,   /* 430: of_oxm_sctp_src */
    -1,   /* 431: of_oxm_sctp_src_masked */
    -1,   /* 432: of_oxm_tcp_dst */
    -1,   /* 433: of_oxm_tcp_dst_masked */
    -1,   /* 434: of_oxm_tcp_src */
    -1,   /* 435: of_oxm_tcp_src_masked */
    -1,   /* 436: of_oxm_udp_dst */
    -1,   /* 437: of_oxm_udp_dst_masked */
    -1,   /* 438: of_oxm_udp_src */
    -1,   /* 439: of_oxm_udp_src_masked */
    -1,   /* 440: of_oxm_vlan_pcp */
    -1,   /* 441: of_oxm_vlan_pcp_masked */
    -1,   /* 442: of_oxm_vlan_vid */
    -1,   /* 443: of_oxm_vlan_vid_masked */
    8,    /* 444: of_packet_queue */
    64,   /* 445: of_port_desc */
    104,  /* 446: of_port_stats_entry */
    8,    /* 447: of_queue_prop */
    -1,   /* 448: of_queue_prop_experimenter */
    8,    /* 449: of_queue_prop_header */
    -1,   /* 450: of_queue_prop_max_rate */
    16,   /* 451: of_queue_prop_min_rate */
    32,   /* 452: of_queue_stats_entry */
    -1,   /* 453: of_table_feature_prop */
    -1,   /* 454: of_table_feature_prop_apply_actions */
    -1,   /* 455: of_table_feature_prop_apply_actions_miss */
    -1,   /* 456: of_table_feature_prop_apply_setfield */
    -1,   /* 457: of_table_feature_prop_apply_setfield_miss */
    -1,   /* 458: of_table_feature_prop_experimenter */
    -1,   /* 459: of_table_feature_prop_experimenter_miss */
    -1,   /* 460: of_table_feature_prop_header */
    -1,   /* 461: of_table_feature_prop_instructions */
    -1,   /* 462: of_table_feature_prop_instructions_miss */
    -1,   /* 463: of_table_feature_prop_match */
    -1,   /* 464: of_table_feature_prop_next_tables */
    -1,   /* 465: of_table_feature_prop_next_tables_miss */
    -1,   /* 466: of_table_feature_prop_wildcards */
    -1,   /* 467: of_table_feature_prop_write_actions */
    -1,   /* 468: of_table_feature_prop_write_actions_miss */
    -1,   /* 469: of_table_feature_prop_write_setfield */
    -1,   /* 470: of_table_feature_prop_write_setfield_miss */
    -1,   /* 471: of_table_features */
    88,   /* 472: of_table_stats_entry */
    -1,   /* 473: of_uint32 */
    -1,   /* 474: of_uint64 */
    -1,   /* 475: of_uint8 */
    0,    /* 476: of_list_action */
    -1,   /* 477: of_list_action_id */
    -1,   /* 478: of_list_bsn_controller_connection */
    -1,   /* 479: of_list_bsn_debug_counter_desc_stats_entry */
    -1,   /* 480: of_list_bsn_debug_counter_stats_entry */
    -1,   /* 481: of_list_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 482: of_list_bsn_gentable_bucket_stats_entry */
    -1,   /* 483: of_list_bsn_gentable_desc_stats_entry */
    -1,   /* 484: of_list_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 485: of_list_bsn_gentable_entry_stats_entry */
    -1,   /* 486: of_list_bsn_gentable_stats_entry */
    0,    /* 487: of_list_bsn_interface */
    -1,   /* 488: of_list_bsn_lacp_stats_entry */
    -1,   /* 489: of_list_bsn_port_counter_stats_entry */
    -1,   /* 490: of_list_bsn_switch_pipeline_stats_entry */
    -1,   /* 491: of_list_bsn_table_checksum_stats_entry */
    -1,   /* 492: of_list_bsn_tlv */
    -1,   /* 493: of_list_bsn_vlan_counter_stats_entry */
    0,    /* 494: of_list_bucket */
    0,    /* 495: of_list_bucket_counter */
    0,    /* 496: of_list_flow_stats_entry */
    0,    /* 497: of_list_group_desc_stats_entry */
    0,    /* 498: of_list_group_stats_entry */
    -1,   /* 499: of_list_hello_elem */
    0,    /* 500: of_list_instruction */
    -1,   /* 501: of_list_instruction_id */
    -1,   /* 502: of_list_meter_band */
    -1,   /* 503: of_list_meter_band_stats */
    -1,   /* 504: of_list_meter_stats */
    -1,   /* 505: of_list_oxm */
    0,    /* 506: of_list_packet_queue */
    0,    /* 507: of_list_port_desc */
    0,    /* 508: of_list_port_stats_entry */
    0,    /* 509: of_list_queue_prop */
    0,    /* 510: of_list_queue_stats_entry */
    -1,   /* 511: of_list_table_feature_prop */
    -1,   /* 512: of_list_table_features */
    0,    /* 513: of_list_table_stats_entry */
    -1,   /* 514: of_list_uint32 */
    -1,   /* 515: of_list_uint64 */
    -1    /* 516: of_list_uint8 */
};

static const int
of_object_fixed_len_v3[OF_OBJECT_COUNT] = {
    -1,   /* of_object is not instantiable */
    40,   /* 1: of_aggregate_stats_reply */
    56,   /* 2: of_aggregate_stats_request */
    -1,   /* 3: of_async_get_reply */
    -1,   /* 4: of_async_get_request */
    -1,   /* 5: of_async_set */
    12,   /* 6: of_bad_action_error_msg */
    12,   /* 7: of_bad_instruction_error_msg */
    12,   /* 8: of_bad_match_error_msg */
    12,   /* 9: of_bad_request_error_msg */
    8,    /* 10: of_barrier_reply */
    8,    /* 11: of_barrier_request */
    -1,   /* 12: of_bsn_arp_idle */
    20,   /* 13: of_bsn_bw_clear_data_reply */
    16,   /* 14: of_bsn_bw_clear_data_request */
    20,   /* 15: of_bsn_bw_enable_get_reply */
    16,   /* 16: of_bsn_bw_enable_get_request */
    24,   /* 17: of_bsn_bw_enable_set_reply */
    20,   /* 18: of_bsn_bw_enable_set_request */
    -1,   /* 19: of_bsn_controller_connections_reply */
    -1,   /* 20: of_bsn_controller_connections_request */
    -1,   /* 21: of_bsn_debug_counter_desc_stats_reply */
    -1,   /* 22: of_bsn_debug_counter_desc_stats_request */
    -1,   /* 23: of_bsn_debug_counter_stats_reply */
    -1,   /* 24: of_bsn_debug_counter_stats_request */
    -1,   /* 25: of_bsn_flow_checksum_bucket_stats_reply */
    -1,   /* 26: of_bsn_flow_checksum_bucket_stats_request */
    -1,   /* 27: of_bsn_flow_idle */
    -1,   /* 28: of_bsn_flow_idle_enable_get_reply */
    -1,   /* 29: of_bsn_flow_idle_enable_get_request */
    -1,   /* 30: of_bsn_flow_idle_enable_set_reply */
    -1,   /* 31: of_bsn_flow_idle_enable_set_request */
    -1,   /* 32: of_bsn_gentable_bucket_stats_reply */
    -1,   /* 33: of_bsn_gentable_bucket_stats_request */
    -1,   /* 34: of_bsn_gentable_clear_reply */
    -1,   /* 35: of_bsn_gentable_clear_request */
    -1,   /* 36: of_bsn_gentable_desc_stats_reply */
    -1,   /* 37: of_bsn_gentable_desc_stats_request */
    -1,   /* 38: of_bsn_gentable_entry_add */
    -1,   /* 39: of_bsn_gentable_entry_delete */
    -1,   /* 40: of_bsn_gentable_entry_desc_stats_reply */
    -1,   /* 41: of_bsn_gentable_entry_desc_stats_request */
    -1,   /* 42: of_bsn_gentable_entry_stats_reply */
    -1,   /* 43: of_bsn_gentable_entry_stats_request */
    -1,   /* 44: of_bsn_gentable_set_buckets_size */
    -1,   /* 45: of_bsn_gentable_stats_reply */
    -1,   /* 46: of_bsn_gentable_stats_request */
    16,   /* 47: of_bsn_get_interfaces_reply */
    16,   /* 48: of_bsn_get_interfaces_request */
    -1,   /* 49: of_bsn_get_ip_mask_reply */
    -1,   /* 50: of_bsn_get_ip_mask_request */
    -1,   /* 51: of_bsn_get_l2_table_reply */
    -1,   /* 52: of_bsn_get_l2_table_request */
    20,   /* 53: of_bsn_get_mirroring_reply */
    20,   /* 54: of_bsn_get_mirroring_request */
    -1,   /* 55: of_bsn_get_switch_pipeline_reply */
    -1,   /* 56: of_bsn_get_switch_pipeline_request */
    16,   /* 57: of_bsn_header */
    -1,   /* 58: of_bsn_hybrid_get_reply */
    -1,   /* 59: of_bsn_hybrid_get_request */
    -1,   /* 60: of_bsn_image_desc_stats_reply */
    -1,   /* 61: of_bsn_image_desc_stats_request */
    -1,   /* 62: of_bsn_lacp_convergence_notif */
    -1,   /* 63: of_bsn_lacp_stats_reply */
    -1,   /* 64: of_bsn_lacp_stats_request */
    25,   /* 65: of_bsn_pdu_rx_reply */
    28,   /* 66: of_bsn_pdu_rx_request */
    21,   /* 67: of_bsn_pdu_rx_timeout */
    25,   /* 68: of_bsn_pdu_tx_reply */
    28,   /* 69: of_bsn_pdu_tx_request */
    -1,   /* 70: of_bsn_port_counter_stats_reply */
    -1,   /* 71: of_bsn_port_counter_stats_request */
    -1,   /* 72: of_bsn_role_status */
    -1,   /* 73: of_bsn_set_aux_cxns_reply */
    -1,   /* 74: of_bsn_set_aux_cxns_request */
    -1,   /* 75: of_bsn_set_ip_mask */
    -1,   /* 76: of_bsn_set_l2_table_reply */
    -1,   /* 77: of_bsn_set_l2_table_request */
    -1,   /* 78: of_bsn_set_lacp_reply */
    -1,   /* 79: of_bsn_set_lacp_request */
    20,   /* 80: of_bsn_set_mirroring */
    20,   /* 81: of_bsn_set_pktin_suppression_reply */
    32,   /* 82: of_bsn_set_pktin_suppression_request */
    -1,   /* 83: of_bsn_set_switch_pipeline_reply */
    -1,   /* 84: of_bsn_set_switch_pipeline_request */
    -1,   /* 85: of_bsn_shell_command */
    -1,   /* 86: of_bsn_shell_output */
    -1,   /* 87: of_bsn_shell_status */
    24,   /* 88: of_bsn_stats_reply */
    24,   /* 89: of_bsn_stats_request */
    -1,   /* 90: of_bsn_switch_pipeline_stats_reply */
    -1,   /* 91: of_bsn_switch_pipeline_stats_request */
    -1,   /* 92: of_bsn_table_checksum_stats_reply */
    -1,   /* 93: of_bsn_table_checksum_stats_request */
    -1,   /* 94: of_bsn_table_set_buckets_size */
    -1,   /* 95: of_bsn_time_reply */
    -1,   /* 96: of_bsn_time_request */
    24,   /* 97: of_bsn_virtual_port_create_reply */
    20,   /* 98: of_bsn_virtual_port_create_request */
    20,   /* 99: of_bsn_virtual_port_remove_reply */
    20,   /* 100: of_bsn_virtual_port_remove_request */
    -1,   /* 101: of_bsn_vlan_counter_stats_reply */
    -1,   /* 102: of_bsn_vlan_counter_stats_request */
    1072, /* 103: of_desc_stats_reply */
    16,   /* 104: of_desc_stats_request */
    8,    /* 105: of_echo_reply */
    8,    /* 106: of_echo_request */
    10,   /* 107: of_error_msg */
    16,   /* 108: of_experimenter */
    16,   /* 109: of_experimenter_error_msg */
    24,   /* 110: of_experimenter_stats_reply */
    24,   /* 111: of_experimenter_stats_request */
    32,   /* 112: of_features_reply */
    8,    /* 113: of_features_request */
    56,   /* 114: of_flow_add */
    56,   /* 115: of_flow_delete */
    56,   /* 116: of_flow_delete_strict */
    56,   /* 117: of_flow_mod */
    12,   /* 118: of_flow_mod_failed_error_msg */
    56,   /* 119: of_flow_modify */
    56,   /* 120: of_flow_modify_strict */
    56,   /* 121: of_flow_removed */
    16,   /* 122: of_flow_stats_reply */
    56,   /* 123: of_flow_stats_request */
    12,   /* 124: of_get_config_reply */
    8,    /* 125: of_get_config_request */
    16,   /* 126: of_group_add */
    16,   /* 127: of_group_delete */
    16,   /* 128: of_group_desc_stats_reply */
    16,   /* 129: of_group_desc_stats_request */
    56,   /* 130: of_group_features_stats_reply */
    16,   /* 131: of_group_features_stats_request */
    16,   /* 132: of_group_mod */
    12,   /* 133: of_group_mod_failed_error_msg */
    16,   /* 134: of_group_modify */
    16,   /* 135: of_group_stats_reply */
    24,   /* 136: of_group_stats_request */
    8,    /* 137: of_header */
    8,    /* 138: of_hello */
    12,   /* 139: of_hello_failed_error_msg */
    -1,   /* 140: of_meter_config_stats_reply */
    -1,   /* 141: of_meter_config_stats_request */
    -1,   /* 142: of_meter_features_stats_reply */
    -1,   /* 143: of_meter_features_stats_request */
    -1,   /* 144: of_meter_mod */
    -1,   /* 145: of_meter_mod_failed_error_msg */
    -1,   /* 146: of_meter_stats_reply */
    -1,   /* 147: of_meter_stats_request */
    -1,   /* 148: of_nicira_controller_role_reply */
    -1,   /* 149: of_nicira_controller_role_request */
    16,   /* 150: of_nicira_header */
    24,   /* 151: of_packet_in */
    24,   /* 152: of_packet_out */
    -1,   /* 153: of_port_desc_stats_reply */
    -1,   /* 154: of_port_desc_stats_request */
    40,   /* 155: of_port_mod */
    12,   /* 156: of_port_mod_failed_error_msg */
    16,   /* 157: of_port_stats_reply */
    24,   /* 158: of_port_stats_request */
    80,   /* 159: of_port_status */
    16,   /* 160: of_queue_get_config_reply */
    16,   /* 161: of_queue_get_config_request */
    12,   /* 162: of_queue_op_failed_error_msg */
    16,   /* 163: of_queue_stats_reply */
    24,   /* 164: of_queue_stats_request */
    24,   /* 165: of_role_reply */
    24,   /* 166: of_role_request */
    12,   /* 167: of_role_request_failed_error_msg */
    12,   /* 168: of_set_config */
    16,   /* 169: of_stats_reply */
    16,   /* 170: of_stats_request */
    12,   /* 171: of_switch_config_failed_error_msg */
    -1,   /* 172: of_table_features_failed_error_msg */
    -1,   /* 173: of_table_features_stats_reply */
    -1,   /* 174: of_table_features_stats_request */
    16,   /* 175: of_table_mod */
    12,   /* 176: of_table_mod_failed_error_msg */
    16,   /* 177: of_table_stats_reply */
    16,   /* 178: of_table_stats_request */
    8,    /* 179: of_action */
    16,   /* 180: of_action_bsn */
    24,   /* 181: of_action_bsn_mirror */
    16,   /* 182: of_action_bsn_set_tunnel_dst */
    8,    /* 183: of_action_copy_ttl_in */
    8,    /* 184: of_action_copy_ttl_out */
    8,    /* 185: of_action_dec_mpls_ttl */
    8,    /* 186: of_action_dec_nw_ttl */
    -1,   /* 187: of_action_enqueue */
    8,    /* 188: of_action_experimenter */
    8,    /* 189: of_action_group */
    8,    /* 190: of_action_header */
    -1,   /* 191: of_action_id */
    -1,   /* 192: of_action_id_bsn */
    -1,   /* 193: of_action_id_bsn_mirror */
    -1,   /* 194: of_action_id_bsn_set_tunnel_dst */
    -1,   /* 195: of_action_id_copy_ttl_in */
    -1,   /* 196: of_action_id_copy_ttl_out */
    -1,   /* 197: of_action_id_dec_mpls_ttl */
    -1,   /* 198: of_action_id_dec_nw_ttl */
    -1,   /* 199: of_action_id_experimenter */
    -1,   /* 200: of_action_id_group */
    -1,   /* 201: of_action_id_header */
    -1,   /* 202: of_action_id_nicira */
    -1,   /* 203: of_action_id_nicira_dec_ttl */
    -1,   /* 204: of_action_id_output */
    -1,   /* 205: of_action_id_pop_mpls */
    -1,   /* 206: of_action_id_pop_pbb */
    -1,   /* 207: of_action_id_pop_vlan */
    -1,   /* 208: of_action_id_push_mpls */
    -1,   /* 209: of_action_id_push_pbb */
    -1,   /* 210: of_action_id_push_vlan */
    -1,   /* 211: of_action_id_set_field */
    -1,   /* 212: of_action_id_set_mpls_ttl */
    -1,   /* 213: of_action_id_set_nw_ttl */
    -1,   /* 214: of_action_id_set_queue */
    16,   /* 215: of_action_nicira */
    16,   /* 216: of_action_nicira_dec_ttl */
    16,   /* 217: of_action_output */
    8,    /* 218: of_action_pop_mpls */
    -1,   /* 219: of_action_pop_pbb */
    8,    /* 220: of_action_pop_vlan */
    8,    /* 221: of_action_push_mpls */
    -1,   /* 222: of_action_push_pbb */
    8,    /* 223: of_action_push_vlan */
    -1,   /* 224: of_action_set_dl_dst */
    -1,   /* 225: of_action_set_dl_src */
    8,    /* 226: of_action_set_field */
    -1,   /* 227: of_action_set_mpls_label */
    -1,   /* 228: of_action_set_mpls_tc */
    8,    /* 229: of_action_set_mpls_ttl */
    -1,   /* 230: of_action_set_nw_dst */
    -1,   /* 231: of_action_set_nw_ecn */
    -1,   /* 232: of_action_set_nw_src */
    -1,   /* 233: of_action_set_nw_tos */
    8,    /* 234: of_action_set_nw_ttl */
    8,    /* 235: of_action_set_queue */
    -1,   /* 236: of_action_set_tp_dst */
    -1,   /* 237: of_action_set_tp_src */
    -1,   /* 238: of_action_set_vlan_pcp */
    -1,   /* 239: of_action_set_vlan_vid */
    -1,   /* 240: of_action_strip_vlan */
    -1,   /* 241: of_bsn_controller_connection */
    -1,   /* 242: of_bsn_debug_counter_desc_stats_entry */
    -1,   /* 243: of_bsn_debug_counter_stats_entry */
    -1,   /* 244: of_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 245: of_bsn_gentable_bucket_stats_entry */
    -1,   /* 246: of_bsn_gentable_desc_stats_entry */
    -1,   /* 247: of_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 248: of_bsn_gentable_entry_stats_entry */
    -1,   /* 249: of_bsn_gentable_stats_entry */
    32,   /* 250: of_bsn_interface */
    -1,   /* 251: of_bsn_lacp_stats_entry */
    -1,   /* 252: of_bsn_port_counter_stats_entry */
    -1,   /* 253: of_bsn_switch_pipeline_stats_entry */
    -1,   /* 254: of_bsn_table_checksum_stats_entry */
    -1,   /* 255: of_bsn_tlv */
    -1,   /* 256: of_bsn_tlv_broadcast_query_timeout */
    -1,   /* 257: of_bsn_tlv_circuit_id */
    -1,   /* 258: of_bsn_tlv_header */
    -1,   /* 259: of_bsn_tlv_idle_notification */
    -1,   /* 260: of_bsn_tlv_idle_time */
    -1,   /* 261: of_bsn_tlv_idle_timeout */
    -1,   /* 262: of_bsn_tlv_ipv4 */
    -1,   /* 263: of_bsn_tlv_mac */
    -1,   /* 264: of_bsn_tlv_miss_packets */
    -1,   /* 265: of_bsn_tlv_port */
    -1,   /* 266: of_bsn_tlv_reply_packets */
    -1,   /* 267: of_bsn_tlv_request_packets */
    -1,   /* 268: of_bsn_tlv_rx_packets */
    -1,   /* 269: of_bsn_tlv_tx_packets */
    -1,   /* 270: of_bsn_tlv_udf_anchor */
    -1,   /* 271: of_bsn_tlv_udf_id */
    -1,   /* 272: of_bsn_tlv_udf_length */
    -1,   /* 273: of_bsn_tlv_udf_offset */
    -1,   /* 274: of_bsn_tlv_unicast_query_timeout */
    -1,   /* 275: of_bsn_tlv_vlan_vid */
    -1,   /* 276: of_bsn_tlv_vrf */
    -1,   /* 277: of_bsn_vlan_counter_stats_entry */
    4,    /* 278: of_bsn_vport */
    4,    /* 279: of_bsn_vport_header */
    56,   /* 280: of_bsn_vport_l2gre */
    32,   /* 281: of_bsn_vport_q_in_q */
    16,   /* 282: of_bucket */
    16,   /* 283: of_bucket_counter */
    56,   /* 284: of_flow_stats_entry */
    8,    /* 285: of_group_desc_stats_entry */
    32,   /* 286: of_group_stats_entry */
    -1,   /* 287: of_hello_elem */
    -1,   /* 288: of_hello_elem_header */
    -1,   /* 289: of_hello_elem_versionbitmap */
    8,    /* 290: of_instruction */
    8,    /* 291: of_instruction_apply_actions */
    -1,   /* 292: of_instruction_bsn */
    -1,   /* 293: of_instruction_bsn_arp_offload */
    -1,   /* 294: of_instruction_bsn_deny */
    -1,   /* 295: of_instruction_bsn_dhcp_offload */
    -1,   /* 296: of_instruction_bsn_disable_split_horizon_check */
    -1,   /* 297: of_instruction_bsn_disable_src_mac_check */
    -1,   /* 298: of_instruction_bsn_packet_of_death */
    -1,   /* 299: of_instruction_bsn_permit */
    -1,   /* 300: of_instruction_bsn_prioritize_pdus */
    8,    /* 301: of_instruction_clear_actions */
    8,    /* 302: of_instruction_experimenter */
    8,    /* 303: of_instruction_goto_table */
    8,    /* 304: of_instruction_header */
    -1,   /* 305: of_instruction_id */
    -1,   /* 306: of_instruction_id_apply_actions */
    -1,   /* 307: of_instruction_id_bsn */
    -1,   /* 308: of_instruction_id_bsn_arp_offload */
    -1,   /* 309: of_instruction_id_bsn_deny */
    -1,   /* 310: of_instruction_id_bsn_dhcp_offload */
    -1,   /* 311: of_instruction_id_bsn_disable_split_horizon_check */
    -1,   /* 312: of_instruction_id_bsn_disable_src_mac_check */
    -1,   /* 313: of_instruction_id_bsn_packet_of_death */
    -1,   /* 314: of_instruction_id_bsn_permit */
    -1,   /* 315: of_instruction_id_bsn_prioritize_pdus */
    -1,   /* 316: of_instruction_id_clear_actions */
    -1,   /* 317: of_instruction_id_experimenter */
    -1,   /* 318: of_instruction_id_goto_table */
    -1,   /* 319: of_instruction_id_header */
    -1,   /* 320: of_instruction_id_meter */
    -1,   /* 321: of_instruction_id_write_actions */
    -1,   /* 322: of_instruction_id_write_metadata */
    -1,   /* 323: of_instruction_meter */
    8,    /* 324: of_instruction_write_actions */
    24,   /* 325: of_instruction_write_metadata */
    -1,   /* 326: of_match_v1 */
    -1,   /* 327: of_match_v2 */
    4,    /* 328: of_match_v3 */
    -1,   /* 329: of_meter_band */
    -1,   /* 330: of_meter_band_drop */
    -1,   /* 331: of_meter_band_dscp_remark */
    -1,   /* 332: of_meter_band_experimenter */
    -1,   /* 333: of_meter_band_header */
    -1,   /* 334: of_meter_band_stats */
    -1,   /* 335: of_meter_config */
    -1,   /* 336: of_meter_features */
    -1,   /* 337: of_meter_stats */
    4,    /* 338: of_oxm */
    6,    /* 339: of_oxm_arp_op */
    8,    /* 340: of_oxm_arp_op_masked */
    10,   /* 341: of_oxm_arp_sha */
    16,   /* 342: of_oxm_arp_sha_masked */
    8,    /* 343: of_oxm_arp_spa */
    12,   /* 344: of_oxm_arp_spa_masked */
    10,   /* 345: of_oxm_arp_tha */
    16,   /* 346: of_oxm_arp_tha_masked */
    8,    /* 347: of_oxm_arp_tpa */
    12,   /* 348: of_oxm_arp_tpa_masked */
    8,    /* 349: of_oxm_bsn_egr_port_group_id */
    12,   /* 350: of_oxm_bsn_egr_port_group_id_masked */
    5,    /* 351: of_oxm_bsn_global_vrf_allowed */
    6,    /* 352: of_oxm_bsn_global_vrf_allowed_masked */
    20,   /* 353: of_oxm_bsn_in_ports_128 */
    36,   /* 354: of_oxm_bsn_in_ports_128_masked */
    8,    /* 355: of_oxm_bsn_l3_dst_class_id */
    12,   /* 356: of_oxm_bsn_l3_dst_class_id_masked */
    8,    /* 357: of_oxm_bsn_l3_interface_class_id */
    12,   /* 358: of_oxm_bsn_l3_interface_class_id_masked */
    8,    /* 359: of_oxm_bsn_l3_src_class_id */
    12,   /* 360: of_oxm_bsn_l3_src_class_id_masked */
    8,    /* 361: of_oxm_bsn_lag_id */
    12,   /* 362: of_oxm_bsn_lag_id_masked */
    8,    /* 363: of_oxm_bsn_udf0 */
    12,   /* 364: of_oxm_bsn_udf0_masked */
    8,    /* 365: of_oxm_bsn_udf1 */
    12,   /* 366: of_oxm_bsn_udf1_masked */
    8,    /* 367: of_oxm_bsn_udf2 */
    12,   /* 368: of_oxm_bsn_udf2_masked */
    8,    /* 369: of_oxm_bsn_udf3 */
    12,   /* 370: of_oxm_bsn_udf3_masked */
    8,    /* 371: of_oxm_bsn_udf4 */
    12,   /* 372: of_oxm_bsn_udf4_masked */
    8,    /* 373: of_oxm_bsn_udf5 */
    12,   /* 374: of_oxm_bsn_udf5_masked */
    8,    /* 375: of_oxm_bsn_udf6 */
    12,   /* 376: of_oxm_bsn_udf6_masked */
    8,    /* 377: of_oxm_bsn_udf7 */
    12,   /* 378: of_oxm_bsn_udf7_masked */
    8,    /* 379: of_oxm_bsn_vrf */
    12,   /* 380: of_oxm_bsn_vrf_masked */
    10,   /* 381: of_oxm_eth_dst */
    16,   /* 382: of_oxm_eth_dst_masked */
    10,   /* 383: of_oxm_eth_src */
    16,   /* 384: of_oxm_eth_src_masked */
    6,    /* 385: of_oxm_eth_type */
    8,    /* 386: of_oxm_eth_type_masked */
    4,    /* 387: of_oxm_header */
    5,    /* 388: of_oxm_icmpv4_code */
    6,    /* 389: of_oxm_icmpv4_code_masked */
    5,    /* 390: of_oxm_icmpv4_type */
    6,    /* 391: of_oxm_icmpv4_type_masked */
    5,    /* 392: of_oxm_icmpv6_code */
    6,    /* 393: of_oxm_icmpv6_code_masked */
    5,    /* 394: of_oxm_icmpv6_type */
    6,    /* 395: of_oxm_icmpv6_type_masked */
    8,    /* 396: of_oxm_in_phy_port */
    12,   /* 397: of_oxm_in_phy_port_masked */
    8,    /* 398: of_oxm_in_port */
    12,   /* 399: of_oxm_in_port_masked */
    5,    /* 400: of_oxm_ip_dscp */
    6,    /* 401: of_oxm_ip_dscp_masked */
    5,    /* 402: of_oxm_ip_ecn */
    6,    /* 403: of_oxm_ip_ecn_masked */
    5,    /* 404: of_oxm_ip_proto */
    6,    /* 405: of_oxm_ip_proto_masked */
    8,    /* 406: of_oxm_ipv4_dst */
    12,   /* 407: of_oxm_ipv4_dst_masked */
    8,    /* 408: of_oxm_ipv4_src */
    12,   /* 409: of_oxm_ipv4_src_masked */
    20,   /* 410: of_oxm_ipv6_dst */
    36,   /* 411: of_oxm_ipv6_dst_masked */
    8,    /* 412: of_oxm_ipv6_flabel */
    12,   /* 413: of_oxm_ipv6_flabel_masked */
    10,   /* 414: of_oxm_ipv6_nd_sll */
    16,   /* 415: of_oxm_ipv6_nd_sll_masked */
    20,   /* 416: of_oxm_ipv6_nd_target */
    36,   /* 417: of_oxm_ipv6_nd_target_masked */
    10,   /* 418: of_oxm_ipv6_nd_tll */
    16,   /* 419: of_oxm_ipv6_nd_tll_masked */
    20,   /* 420: of_oxm_ipv6_src */
    36,   /* 421: of_oxm_ipv6_src_masked */
    12,   /* 422: of_oxm_metadata */
    20,   /* 423: of_oxm_metadata_masked */
    8,    /* 424: of_oxm_mpls_label */
    12,   /* 425: of_oxm_mpls_label_masked */
    5,    /* 426: of_oxm_mpls_tc */
    6,    /* 427: of_oxm_mpls_tc_masked */
    6,    /* 428: of_oxm_sctp_dst */
    8,    /* 429: of_oxm_sctp_dst_masked */
    6,    /* 430: of_oxm_sctp_src */
    8,    /* 431: of_oxm_sctp_src_masked */
    6,    /* 432: of_oxm_tcp_dst */
    8,    /* 433: of_oxm_tcp_dst_masked */
    6,    /* 434: of_oxm_tcp_src */
    8,    /* 435: of_oxm_tcp_src_masked */
    6,    /* 436: of_oxm_udp_dst */
    8,    /* 437: of_oxm_udp_dst_masked */
    6,    /* 438: of_oxm_udp_src */
    8,    /* 439: of_oxm_udp_src_masked */
    5,    /* 440: of_oxm_vlan_pcp */
    6,    /* 441: of_oxm_vlan_pcp_masked */
    6,    /* 442: of_oxm_vlan_vid */
    8,    /* 443: of_oxm_vlan_vid_masked */
    16,   /* 444: of_packet_queue */
    64,   /* 445: of_port_desc */
    104,  /* 446: of_port_stats_entry */
    8,    /* 447: of_queue_prop */
    16,   /* 448: of_queue_prop_experimenter */
    8,    /* 449: of_queue_prop_header */
    16,   /* 450: of_queue_prop_max_rate */
    16,   /* 451: of_queue_prop_min_rate */
    32,   /* 452: of_queue_stats_entry */
    -1,   /* 453: of_table_feature_prop */
    -1,   /* 454: of_table_feature_prop_apply_actions */
    -1,   /* 455: of_table_feature_prop_apply_actions_miss */
    -1,   /* 456: of_table_feature_prop_apply_setfield */
    -1,   /* 457: of_table_feature_prop_apply_setfield_miss */
    -1,   /* 458: of_table_feature_prop_experimenter */
    -1,   /* 459: of_table_feature_prop_experimenter_miss */
    -1,   /* 460: of_table_feature_prop_header */
    -1,   /* 461: of_table_feature_prop_instructions */
    -1,   /* 462: of_table_feature_prop_instructions_miss */
    -1,   /* 463: of_table_feature_prop_match */
    -1,   /* 464: of_table_feature_prop_next_tables */
    -1,   /* 465: of_table_feature_prop_next_tables_miss */
    -1,   /* 466: of_table_feature_prop_wildcards */
    -1,   /* 467: of_table_feature_prop_write_actions */
    -1,   /* 468: of_table_feature_prop_write_actions_miss */
    -1,   /* 469: of_table_feature_prop_write_setfield */
    -1,   /* 470: of_table_feature_prop_write_setfield_miss */
    -1,   /* 471: of_table_features */
    128,  /* 472: of_table_stats_entry */
    -1,   /* 473: of_uint32 */
    -1,   /* 474: of_uint64 */
    -1,   /* 475: of_uint8 */
    0,    /* 476: of_list_action */
    -1,   /* 477: of_list_action_id */
    -1,   /* 478: of_list_bsn_controller_connection */
    -1,   /* 479: of_list_bsn_debug_counter_desc_stats_entry */
    -1,   /* 480: of_list_bsn_debug_counter_stats_entry */
    -1,   /* 481: of_list_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 482: of_list_bsn_gentable_bucket_stats_entry */
    -1,   /* 483: of_list_bsn_gentable_desc_stats_entry */
    -1,   /* 484: of_list_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 485: of_list_bsn_gentable_entry_stats_entry */
    -1,   /* 486: of_list_bsn_gentable_stats_entry */
    0,    /* 487: of_list_bsn_interface */
    -1,   /* 488: of_list_bsn_lacp_stats_entry */
    -1,   /* 489: of_list_bsn_port_counter_stats_entry */
    -1,   /* 490: of_list_bsn_switch_pipeline_stats_entry */
    -1,   /* 491: of_list_bsn_table_checksum_stats_entry */
    -1,   /* 492: of_list_bsn_tlv */
    -1,   /* 493: of_list_bsn_vlan_counter_stats_entry */
    0,    /* 494: of_list_bucket */
    0,    /* 495: of_list_bucket_counter */
    0,    /* 496: of_list_flow_stats_entry */
    0,    /* 497: of_list_group_desc_stats_entry */
    0,    /* 498: of_list_group_stats_entry */
    -1,   /* 499: of_list_hello_elem */
    0,    /* 500: of_list_instruction */
    -1,   /* 501: of_list_instruction_id */
    -1,   /* 502: of_list_meter_band */
    -1,   /* 503: of_list_meter_band_stats */
    -1,   /* 504: of_list_meter_stats */
    0,    /* 505: of_list_oxm */
    0,    /* 506: of_list_packet_queue */
    0,    /* 507: of_list_port_desc */
    0,    /* 508: of_list_port_stats_entry */
    0,    /* 509: of_list_queue_prop */
    0,    /* 510: of_list_queue_stats_entry */
    -1,   /* 511: of_list_table_feature_prop */
    -1,   /* 512: of_list_table_features */
    0,    /* 513: of_list_table_stats_entry */
    -1,   /* 514: of_list_uint32 */
    -1,   /* 515: of_list_uint64 */
    -1    /* 516: of_list_uint8 */
};

static const int
of_object_fixed_len_v4[OF_OBJECT_COUNT] = {
    -1,   /* of_object is not instantiable */
    40,   /* 1: of_aggregate_stats_reply */
    56,   /* 2: of_aggregate_stats_request */
    32,   /* 3: of_async_get_reply */
    32,   /* 4: of_async_get_request */
    32,   /* 5: of_async_set */
    12,   /* 6: of_bad_action_error_msg */
    12,   /* 7: of_bad_instruction_error_msg */
    12,   /* 8: of_bad_match_error_msg */
    12,   /* 9: of_bad_request_error_msg */
    8,    /* 10: of_barrier_reply */
    8,    /* 11: of_barrier_request */
    24,   /* 12: of_bsn_arp_idle */
    20,   /* 13: of_bsn_bw_clear_data_reply */
    16,   /* 14: of_bsn_bw_clear_data_request */
    20,   /* 15: of_bsn_bw_enable_get_reply */
    16,   /* 16: of_bsn_bw_enable_get_request */
    24,   /* 17: of_bsn_bw_enable_set_reply */
    20,   /* 18: of_bsn_bw_enable_set_request */
    16,   /* 19: of_bsn_controller_connections_reply */
    16,   /* 20: of_bsn_controller_connections_request */
    24,   /* 21: of_bsn_debug_counter_desc_stats_reply */
    24,   /* 22: of_bsn_debug_counter_desc_stats_request */
    24,   /* 23: of_bsn_debug_counter_stats_reply */
    24,   /* 24: of_bsn_debug_counter_stats_request */
    24,   /* 25: of_bsn_flow_checksum_bucket_stats_reply */
    25,   /* 26: of_bsn_flow_checksum_bucket_stats_request */
    40,   /* 27: of_bsn_flow_idle */
    20,   /* 28: of_bsn_flow_idle_enable_get_reply */
    16,   /* 29: of_bsn_flow_idle_enable_get_request */
    24,   /* 30: of_bsn_flow_idle_enable_set_reply */
    20,   /* 31: of_bsn_flow_idle_enable_set_request */
    24,   /* 32: of_bsn_gentable_bucket_stats_reply */
    26,   /* 33: of_bsn_gentable_bucket_stats_request */
    28,   /* 34: of_bsn_gentable_clear_reply */
    52,   /* 35: of_bsn_gentable_clear_request */
    24,   /* 36: of_bsn_gentable_desc_stats_reply */
    24,   /* 37: of_bsn_gentable_desc_stats_request */
    36,   /* 38: of_bsn_gentable_entry_add */
    18,   /* 39: of_bsn_gentable_entry_delete */
    24,   /* 40: of_bsn_gentable_entry_desc_stats_reply */
    60,   /* 41: of_bsn_gentable_entry_desc_stats_request */
    24,   /* 42: of_bsn_gentable_entry_stats_reply */
    60,   /* 43: of_bsn_gentable_entry_stats_request */
    24,   /* 44: of_bsn_gentable_set_buckets_size */
    24,   /* 45: of_bsn_gentable_stats_reply */
    24,   /* 46: of_bsn_gentable_stats_request */
    16,   /* 47: of_bsn_get_interfaces_reply */
    16,   /* 48: of_bsn_get_interfaces_request */
    -1,   /* 49: of_bsn_get_ip_mask_reply */
    -1,   /* 50: of_bsn_get_ip_mask_request */
    -1,   /* 51: of_bsn_get_l2_table_reply */
    -1,   /* 52: of_bsn_get_l2_table_request */
    20,   /* 53: of_bsn_get_mirroring_reply */
    20,   /* 54: of_bsn_get_mirroring_request */
    272,  /* 55: of_bsn_get_switch_pipeline_reply */
    16,   /* 56: of_bsn_get_switch_pipeline_request */
    16,   /* 57: of_bsn_header */
    -1,   /* 58: of_bsn_hybrid_get_reply */
    -1,   /* 59: of_bsn_hybrid_get_request */
    536,  /* 60: of_bsn_image_desc_stats_reply */
    24,   /* 61: of_bsn_image_desc_stats_request */
    52,   /* 62: of_bsn_lacp_convergence_notif */
    24,   /* 63: of_bsn_lacp_stats_reply */
    24,   /* 64: of_bsn_lacp_stats_request */
    25,   /* 65: of_bsn_pdu_rx_reply */
    28,   /* 66: of_bsn_pdu_rx_request */
    21,   /* 67: of_bsn_pdu_rx_timeout */
    25,   /* 68: of_bsn_pdu_tx_reply */
    28,   /* 69: of_bsn_pdu_tx_request */
    24,   /* 70: of_bsn_port_counter_stats_reply */
    28,   /* 71: of_bsn_port_counter_stats_request */
    32,   /* 72: of_bsn_role_status */
    24,   /* 73: of_bsn_set_aux_cxns_reply */
    20,   /* 74: of_bsn_set_aux_cxns_request */
    -1,   /* 75: of_bsn_set_ip_mask */
    -1,   /* 76: of_bsn_set_l2_table_reply */
    -1,   /* 77: of_bsn_set_l2_table_request */
    24,   /* 78: of_bsn_set_lacp_reply */
    38,   /* 79: of_bsn_set_lacp_request */
    20,   /* 80: of_bsn_set_mirroring */
    20,   /* 81: of_bsn_set_pktin_suppression_reply */
    32,   /* 82: of_bsn_set_pktin_suppression_request */
    20,   /* 83: of_bsn_set_switch_pipeline_reply */
    272,  /* 84: of_bsn_set_switch_pipeline_request */
    -1,   /* 85: of_bsn_shell_command */
    -1,   /* 86: of_bsn_shell_output */
    -1,   /* 87: of_bsn_shell_status */
    24,   /* 88: of_bsn_stats_reply */
    24,   /* 89: of_bsn_stats_request */
    24,   /* 90: of_bsn_switch_pipeline_stats_reply */
    24,   /* 91: of_bsn_switch_pipeline_stats_request */
    24,   /* 92: of_bsn_table_checksum_stats_reply */
    24,   /* 93: of_bsn_table_checksum_stats_request */
    24,   /* 94: of_bsn_table_set_buckets_size */
    24,   /* 95: of_bsn_time_reply */
    16,   /* 96: of_bsn_time_request */
    24,   /* 97: of_bsn_virtual_port_create_reply */
    20,   /* 98: of_bsn_virtual_port_create_request */
    20,   /* 99: of_bsn_virtual_port_remove_reply */
    20,   /* 100: of_bsn_virtual_port_remove_request */
    24,   /* 101: of_bsn_vlan_counter_stats_reply */
    26,   /* 102: of_bsn_vlan_counter_stats_request */
    1072, /* 103: of_desc_stats_reply */
    16,   /* 104: of_desc_stats_request */
    8,    /* 105: of_echo_reply */
    8,    /* 106: of_echo_request */
    10,   /* 107: of_error_msg */
    16,   /* 108: of_experimenter */
    16,   /* 109: of_experimenter_error_msg */
    24,   /* 110: of_experimenter_stats_reply */
    24,   /* 111: of_experimenter_stats_request */
    32,   /* 112: of_features_reply */
    8,    /* 113: of_features_request */
    56,   /* 114: of_flow_add */
    56,   /* 115: of_flow_delete */
    56,   /* 116: of_flow_delete_strict */
    56,   /* 117: of_flow_mod */
    12,   /* 118: of_flow_mod_failed_error_msg */
    56,   /* 119: of_flow_modify */
    56,   /* 120: of_flow_modify_strict */
    56,   /* 121: of_flow_removed */
    16,   /* 122: of_flow_stats_reply */
    56,   /* 123: of_flow_stats_request */
    12,   /* 124: of_get_config_reply */
    8,    /* 125: of_get_config_request */
    16,   /* 126: of_group_add */
    16,   /* 127: of_group_delete */
    16,   /* 128: of_group_desc_stats_reply */
    16,   /* 129: of_group_desc_stats_request */
    56,   /* 130: of_group_features_stats_reply */
    16,   /* 131: of_group_features_stats_request */
    16,   /* 132: of_group_mod */
    12,   /* 133: of_group_mod_failed_error_msg */
    16,   /* 134: of_group_modify */
    16,   /* 135: of_group_stats_reply */
    24,   /* 136: of_group_stats_request */
    8,    /* 137: of_header */
    8,    /* 138: of_hello */
    12,   /* 139: of_hello_failed_error_msg */
    16,   /* 140: of_meter_config_stats_reply */
    24,   /* 141: of_meter_config_stats_request */
    32,   /* 142: of_meter_features_stats_reply */
    16,   /* 143: of_meter_features_stats_request */
    16,   /* 144: of_meter_mod */
    12,   /* 145: of_meter_mod_failed_error_msg */
    16,   /* 146: of_meter_stats_reply */
    24,   /* 147: of_meter_stats_request */
    -1,   /* 148: of_nicira_controller_role_reply */
    -1,   /* 149: of_nicira_controller_role_request */
    16,   /* 150: of_nicira_header */
    32,   /* 151: of_packet_in */
    24,   /* 152: of_packet_out */
    16,   /* 153: of_port_desc_stats_reply */
    16,   /* 154: of_port_desc_stats_request */
    40,   /* 155: of_port_mod */
    12,   /* 156: of_port_mod_failed_error_msg */
    16,   /* 157: of_port_stats_reply */
    24,   /* 158: of_port_stats_request */
    80,   /* 159: of_port_status */
    16,   /* 160: of_queue_get_config_reply */
    16,   /* 161: of_queue_get_config_request */
    12,   /* 162: of_queue_op_failed_error_msg */
    16,   /* 163: of_queue_stats_reply */
    24,   /* 164: of_queue_stats_request */
    24,   /* 165: of_role_reply */
    24,   /* 166: of_role_request */
    12,   /* 167: of_role_request_failed_error_msg */
    12,   /* 168: of_set_config */
    16,   /* 169: of_stats_reply */
    16,   /* 170: of_stats_request */
    12,   /* 171: of_switch_config_failed_error_msg */
    12,   /* 172: of_table_features_failed_error_msg */
    16,   /* 173: of_table_features_stats_reply */
    16,   /* 174: of_table_features_stats_request */
    16,   /* 175: of_table_mod */
    12,   /* 176: of_table_mod_failed_error_msg */
    16,   /* 177: of_table_stats_reply */
    16,   /* 178: of_table_stats_request */
    8,    /* 179: of_action */
    16,   /* 180: of_action_bsn */
    24,   /* 181: of_action_bsn_mirror */
    16,   /* 182: of_action_bsn_set_tunnel_dst */
    8,    /* 183: of_action_copy_ttl_in */
    8,    /* 184: of_action_copy_ttl_out */
    8,    /* 185: of_action_dec_mpls_ttl */
    8,    /* 186: of_action_dec_nw_ttl */
    -1,   /* 187: of_action_enqueue */
    8,    /* 188: of_action_experimenter */
    8,    /* 189: of_action_group */
    8,    /* 190: of_action_header */
    4,    /* 191: of_action_id */
    12,   /* 192: of_action_id_bsn */
    12,   /* 193: of_action_id_bsn_mirror */
    12,   /* 194: of_action_id_bsn_set_tunnel_dst */
    4,    /* 195: of_action_id_copy_ttl_in */
    4,    /* 196: of_action_id_copy_ttl_out */
    4,    /* 197: of_action_id_dec_mpls_ttl */
    4,    /* 198: of_action_id_dec_nw_ttl */
    8,    /* 199: of_action_id_experimenter */
    4,    /* 200: of_action_id_group */
    4,    /* 201: of_action_id_header */
    10,   /* 202: of_action_id_nicira */
    10,   /* 203: of_action_id_nicira_dec_ttl */
    4,    /* 204: of_action_id_output */
    4,    /* 205: of_action_id_pop_mpls */
    4,    /* 206: of_action_id_pop_pbb */
    4,    /* 207: of_action_id_pop_vlan */
    4,    /* 208: of_action_id_push_mpls */
    4,    /* 209: of_action_id_push_pbb */
    4,    /* 210: of_action_id_push_vlan */
    4,    /* 211: of_action_id_set_field */
    4,    /* 212: of_action_id_set_mpls_ttl */
    4,    /* 213: of_action_id_set_nw_ttl */
    4,    /* 214: of_action_id_set_queue */
    16,   /* 215: of_action_nicira */
    16,   /* 216: of_action_nicira_dec_ttl */
    16,   /* 217: of_action_output */
    8,    /* 218: of_action_pop_mpls */
    8,    /* 219: of_action_pop_pbb */
    8,    /* 220: of_action_pop_vlan */
    8,    /* 221: of_action_push_mpls */
    8,    /* 222: of_action_push_pbb */
    8,    /* 223: of_action_push_vlan */
    -1,   /* 224: of_action_set_dl_dst */
    -1,   /* 225: of_action_set_dl_src */
    8,    /* 226: of_action_set_field */
    -1,   /* 227: of_action_set_mpls_label */
    -1,   /* 228: of_action_set_mpls_tc */
    8,    /* 229: of_action_set_mpls_ttl */
    -1,   /* 230: of_action_set_nw_dst */
    -1,   /* 231: of_action_set_nw_ecn */
    -1,   /* 232: of_action_set_nw_src */
    -1,   /* 233: of_action_set_nw_tos */
    8,    /* 234: of_action_set_nw_ttl */
    8,    /* 235: of_action_set_queue */
    -1,   /* 236: of_action_set_tp_dst */
    -1,   /* 237: of_action_set_tp_src */
    -1,   /* 238: of_action_set_vlan_pcp */
    -1,   /* 239: of_action_set_vlan_vid */
    -1,   /* 240: of_action_strip_vlan */
    264,  /* 241: of_bsn_controller_connection */
    328,  /* 242: of_bsn_debug_counter_desc_stats_entry */
    16,   /* 243: of_bsn_debug_counter_stats_entry */
    8,    /* 244: of_bsn_flow_checksum_bucket_stats_entry */
    16,   /* 245: of_bsn_gentable_bucket_stats_entry */
    48,   /* 246: of_bsn_gentable_desc_stats_entry */
    20,   /* 247: of_bsn_gentable_entry_desc_stats_entry */
    4,    /* 248: of_bsn_gentable_entry_stats_entry */
    24,   /* 249: of_bsn_gentable_stats_entry */
    32,   /* 250: of_bsn_interface */
    36,   /* 251: of_bsn_lacp_stats_entry */
    8,    /* 252: of_bsn_port_counter_stats_entry */
    256,  /* 253: of_bsn_switch_pipeline_stats_entry */
    9,    /* 254: of_bsn_table_checksum_stats_entry */
    4,    /* 255: of_bsn_tlv */
    8,    /* 256: of_bsn_tlv_broadcast_query_timeout */
    4,    /* 257: of_bsn_tlv_circuit_id */
    4,    /* 258: of_bsn_tlv_header */
    4,    /* 259: of_bsn_tlv_idle_notification */
    12,   /* 260: of_bsn_tlv_idle_time */
    8,    /* 261: of_bsn_tlv_idle_timeout */
    8,    /* 262: of_bsn_tlv_ipv4 */
    10,   /* 263: of_bsn_tlv_mac */
    12,   /* 264: of_bsn_tlv_miss_packets */
    8,    /* 265: of_bsn_tlv_port */
    12,   /* 266: of_bsn_tlv_reply_packets */
    12,   /* 267: of_bsn_tlv_request_packets */
    12,   /* 268: of_bsn_tlv_rx_packets */
    12,   /* 269: of_bsn_tlv_tx_packets */
    6,    /* 270: of_bsn_tlv_udf_anchor */
    6,    /* 271: of_bsn_tlv_udf_id */
    6,    /* 272: of_bsn_tlv_udf_length */
    6,    /* 273: of_bsn_tlv_udf_offset */
    8,    /* 274: of_bsn_tlv_unicast_query_timeout */
    6,    /* 275: of_bsn_tlv_vlan_vid */
    8,    /* 276: of_bsn_tlv_vrf */
    8,    /* 277: of_bsn_vlan_counter_stats_entry */
    4,    /* 278: of_bsn_vport */
    4,    /* 279: of_bsn_vport_header */
    56,   /* 280: of_bsn_vport_l2gre */
    32,   /* 281: of_bsn_vport_q_in_q */
    16,   /* 282: of_bucket */
    16,   /* 283: of_bucket_counter */
    56,   /* 284: of_flow_stats_entry */
    8,    /* 285: of_group_desc_stats_entry */
    40,   /* 286: of_group_stats_entry */
    4,    /* 287: of_hello_elem */
    4,    /* 288: of_hello_elem_header */
    4,    /* 289: of_hello_elem_versionbitmap */
    4,    /* 290: of_instruction */
    8,    /* 291: of_instruction_apply_actions */
    16,   /* 292: of_instruction_bsn */
    16,   /* 293: of_instruction_bsn_arp_offload */
    16,   /* 294: of_instruction_bsn_deny */
    16,   /* 295: of_instruction_bsn_dhcp_offload */
    16,   /* 296: of_instruction_bsn_disable_split_horizon_check */
    16,   /* 297: of_instruction_bsn_disable_src_mac_check */
    16,   /* 298: of_instruction_bsn_packet_of_death */
    16,   /* 299: of_instruction_bsn_permit */
    16,   /* 300: of_instruction_bsn_prioritize_pdus */
    8,    /* 301: of_instruction_clear_actions */
    8,    /* 302: of_instruction_experimenter */
    8,    /* 303: of_instruction_goto_table */
    4,    /* 304: of_instruction_header */
    4,    /* 305: of_instruction_id */
    4,    /* 306: of_instruction_id_apply_actions */
    12,   /* 307: of_instruction_id_bsn */
    12,   /* 308: of_instruction_id_bsn_arp_offload */
    12,   /* 309: of_instruction_id_bsn_deny */
    12,   /* 310: of_instruction_id_bsn_dhcp_offload */
    12,   /* 311: of_instruction_id_bsn_disable_split_horizon_check */
    12,   /* 312: of_instruction_id_bsn_disable_src_mac_check */
    12,   /* 313: of_instruction_id_bsn_packet_of_death */
    12,   /* 314: of_instruction_id_bsn_permit */
    12,   /* 315: of_instruction_id_bsn_prioritize_pdus */
    4,    /* 316: of_instruction_id_clear_actions */
    8,    /* 317: of_instruction_id_experimenter */
    4,    /* 318: of_instruction_id_goto_table */
    4,    /* 319: of_instruction_id_header */
    4,    /* 320: of_instruction_id_meter */
    4,    /* 321: of_instruction_id_write_actions */
    4,    /* 322: of_instruction_id_write_metadata */
    8,    /* 323: of_instruction_meter */
    8,    /* 324: of_instruction_write_actions */
    24,   /* 325: of_instruction_write_metadata */
    -1,   /* 326: of_match_v1 */
    -1,   /* 327: of_match_v2 */
    4,    /* 328: of_match_v3 */
    4,    /* 329: of_meter_band */
    16,   /* 330: of_meter_band_drop */
    16,   /* 331: of_meter_band_dscp_remark */
    16,   /* 332: of_meter_band_experimenter */
    4,    /* 333: of_meter_band_header */
    16,   /* 334: of_meter_band_stats */
    8,    /* 335: of_meter_config */
    16,   /* 336: of_meter_features */
    40,   /* 337: of_meter_stats */
    4,    /* 338: of_oxm */
    6,    /* 339: of_oxm_arp_op */
    8,    /* 340: of_oxm_arp_op_masked */
    10,   /* 341: of_oxm_arp_sha */
    16,   /* 342: of_oxm_arp_sha_masked */
    8,    /* 343: of_oxm_arp_spa */
    12,   /* 344: of_oxm_arp_spa_masked */
    10,   /* 345: of_oxm_arp_tha */
    16,   /* 346: of_oxm_arp_tha_masked */
    8,    /* 347: of_oxm_arp_tpa */
    12,   /* 348: of_oxm_arp_tpa_masked */
    8,    /* 349: of_oxm_bsn_egr_port_group_id */
    12,   /* 350: of_oxm_bsn_egr_port_group_id_masked */
    5,    /* 351: of_oxm_bsn_global_vrf_allowed */
    6,    /* 352: of_oxm_bsn_global_vrf_allowed_masked */
    20,   /* 353: of_oxm_bsn_in_ports_128 */
    36,   /* 354: of_oxm_bsn_in_ports_128_masked */
    8,    /* 355: of_oxm_bsn_l3_dst_class_id */
    12,   /* 356: of_oxm_bsn_l3_dst_class_id_masked */
    8,    /* 357: of_oxm_bsn_l3_interface_class_id */
    12,   /* 358: of_oxm_bsn_l3_interface_class_id_masked */
    8,    /* 359: of_oxm_bsn_l3_src_class_id */
    12,   /* 360: of_oxm_bsn_l3_src_class_id_masked */
    8,    /* 361: of_oxm_bsn_lag_id */
    12,   /* 362: of_oxm_bsn_lag_id_masked */
    8,    /* 363: of_oxm_bsn_udf0 */
    12,   /* 364: of_oxm_bsn_udf0_masked */
    8,    /* 365: of_oxm_bsn_udf1 */
    12,   /* 366: of_oxm_bsn_udf1_masked */
    8,    /* 367: of_oxm_bsn_udf2 */
    12,   /* 368: of_oxm_bsn_udf2_masked */
    8,    /* 369: of_oxm_bsn_udf3 */
    12,   /* 370: of_oxm_bsn_udf3_masked */
    8,    /* 371: of_oxm_bsn_udf4 */
    12,   /* 372: of_oxm_bsn_udf4_masked */
    8,    /* 373: of_oxm_bsn_udf5 */
    12,   /* 374: of_oxm_bsn_udf5_masked */
    8,    /* 375: of_oxm_bsn_udf6 */
    12,   /* 376: of_oxm_bsn_udf6_masked */
    8,    /* 377: of_oxm_bsn_udf7 */
    12,   /* 378: of_oxm_bsn_udf7_masked */
    8,    /* 379: of_oxm_bsn_vrf */
    12,   /* 380: of_oxm_bsn_vrf_masked */
    10,   /* 381: of_oxm_eth_dst */
    16,   /* 382: of_oxm_eth_dst_masked */
    10,   /* 383: of_oxm_eth_src */
    16,   /* 384: of_oxm_eth_src_masked */
    6,    /* 385: of_oxm_eth_type */
    8,    /* 386: of_oxm_eth_type_masked */
    4,    /* 387: of_oxm_header */
    5,    /* 388: of_oxm_icmpv4_code */
    6,    /* 389: of_oxm_icmpv4_code_masked */
    5,    /* 390: of_oxm_icmpv4_type */
    6,    /* 391: of_oxm_icmpv4_type_masked */
    5,    /* 392: of_oxm_icmpv6_code */
    6,    /* 393: of_oxm_icmpv6_code_masked */
    5,    /* 394: of_oxm_icmpv6_type */
    6,    /* 395: of_oxm_icmpv6_type_masked */
    8,    /* 396: of_oxm_in_phy_port */
    12,   /* 397: of_oxm_in_phy_port_masked */
    8,    /* 398: of_oxm_in_port */
    12,   /* 399: of_oxm_in_port_masked */
    5,    /* 400: of_oxm_ip_dscp */
    6,    /* 401: of_oxm_ip_dscp_masked */
    5,    /* 402: of_oxm_ip_ecn */
    6,    /* 403: of_oxm_ip_ecn_masked */
    5,    /* 404: of_oxm_ip_proto */
    6,    /* 405: of_oxm_ip_proto_masked */
    8,    /* 406: of_oxm_ipv4_dst */
    12,   /* 407: of_oxm_ipv4_dst_masked */
    8,    /* 408: of_oxm_ipv4_src */
    12,   /* 409: of_oxm_ipv4_src_masked */
    20,   /* 410: of_oxm_ipv6_dst */
    36,   /* 411: of_oxm_ipv6_dst_masked */
    8,    /* 412: of_oxm_ipv6_flabel */
    12,   /* 413: of_oxm_ipv6_flabel_masked */
    10,   /* 414: of_oxm_ipv6_nd_sll */
    16,   /* 415: of_oxm_ipv6_nd_sll_masked */
    20,   /* 416: of_oxm_ipv6_nd_target */
    36,   /* 417: of_oxm_ipv6_nd_target_masked */
    10,   /* 418: of_oxm_ipv6_nd_tll */
    16,   /* 419: of_oxm_ipv6_nd_tll_masked */
    20,   /* 420: of_oxm_ipv6_src */
    36,   /* 421: of_oxm_ipv6_src_masked */
    12,   /* 422: of_oxm_metadata */
    20,   /* 423: of_oxm_metadata_masked */
    8,    /* 424: of_oxm_mpls_label */
    12,   /* 425: of_oxm_mpls_label_masked */
    5,    /* 426: of_oxm_mpls_tc */
    6,    /* 427: of_oxm_mpls_tc_masked */
    6,    /* 428: of_oxm_sctp_dst */
    8,    /* 429: of_oxm_sctp_dst_masked */
    6,    /* 430: of_oxm_sctp_src */
    8,    /* 431: of_oxm_sctp_src_masked */
    6,    /* 432: of_oxm_tcp_dst */
    8,    /* 433: of_oxm_tcp_dst_masked */
    6,    /* 434: of_oxm_tcp_src */
    8,    /* 435: of_oxm_tcp_src_masked */
    6,    /* 436: of_oxm_udp_dst */
    8,    /* 437: of_oxm_udp_dst_masked */
    6,    /* 438: of_oxm_udp_src */
    8,    /* 439: of_oxm_udp_src_masked */
    5,    /* 440: of_oxm_vlan_pcp */
    6,    /* 441: of_oxm_vlan_pcp_masked */
    6,    /* 442: of_oxm_vlan_vid */
    8,    /* 443: of_oxm_vlan_vid_masked */
    16,   /* 444: of_packet_queue */
    64,   /* 445: of_port_desc */
    112,  /* 446: of_port_stats_entry */
    8,    /* 447: of_queue_prop */
    16,   /* 448: of_queue_prop_experimenter */
    8,    /* 449: of_queue_prop_header */
    16,   /* 450: of_queue_prop_max_rate */
    16,   /* 451: of_queue_prop_min_rate */
    40,   /* 452: of_queue_stats_entry */
    4,    /* 453: of_table_feature_prop */
    4,    /* 454: of_table_feature_prop_apply_actions */
    4,    /* 455: of_table_feature_prop_apply_actions_miss */
    4,    /* 456: of_table_feature_prop_apply_setfield */
    4,    /* 457: of_table_feature_prop_apply_setfield_miss */
    12,   /* 458: of_table_feature_prop_experimenter */
    12,   /* 459: of_table_feature_prop_experimenter_miss */
    4,    /* 460: of_table_feature_prop_header */
    4,    /* 461: of_table_feature_prop_instructions */
    4,    /* 462: of_table_feature_prop_instructions_miss */
    4,    /* 463: of_table_feature_prop_match */
    4,    /* 464: of_table_feature_prop_next_tables */
    4,    /* 465: of_table_feature_prop_next_tables_miss */
    4,    /* 466: of_table_feature_prop_wildcards */
    4,    /* 467: of_table_feature_prop_write_actions */
    4,    /* 468: of_table_feature_prop_write_actions_miss */
    4,    /* 469: of_table_feature_prop_write_setfield */
    4,    /* 470: of_table_feature_prop_write_setfield_miss */
    64,   /* 471: of_table_features */
    24,   /* 472: of_table_stats_entry */
    4,    /* 473: of_uint32 */
    8,    /* 474: of_uint64 */
    1,    /* 475: of_uint8 */
    0,    /* 476: of_list_action */
    0,    /* 477: of_list_action_id */
    0,    /* 478: of_list_bsn_controller_connection */
    0,    /* 479: of_list_bsn_debug_counter_desc_stats_entry */
    0,    /* 480: of_list_bsn_debug_counter_stats_entry */
    0,    /* 481: of_list_bsn_flow_checksum_bucket_stats_entry */
    0,    /* 482: of_list_bsn_gentable_bucket_stats_entry */
    0,    /* 483: of_list_bsn_gentable_desc_stats_entry */
    0,    /* 484: of_list_bsn_gentable_entry_desc_stats_entry */
    0,    /* 485: of_list_bsn_gentable_entry_stats_entry */
    0,    /* 486: of_list_bsn_gentable_stats_entry */
    0,    /* 487: of_list_bsn_interface */
    0,    /* 488: of_list_bsn_lacp_stats_entry */
    0,    /* 489: of_list_bsn_port_counter_stats_entry */
    0,    /* 490: of_list_bsn_switch_pipeline_stats_entry */
    0,    /* 491: of_list_bsn_table_checksum_stats_entry */
    0,    /* 492: of_list_bsn_tlv */
    0,    /* 493: of_list_bsn_vlan_counter_stats_entry */
    0,    /* 494: of_list_bucket */
    0,    /* 495: of_list_bucket_counter */
    0,    /* 496: of_list_flow_stats_entry */
    0,    /* 497: of_list_group_desc_stats_entry */
    0,    /* 498: of_list_group_stats_entry */
    0,    /* 499: of_list_hello_elem */
    0,    /* 500: of_list_instruction */
    0,    /* 501: of_list_instruction_id */
    0,    /* 502: of_list_meter_band */
    0,    /* 503: of_list_meter_band_stats */
    0,    /* 504: of_list_meter_stats */
    0,    /* 505: of_list_oxm */
    0,    /* 506: of_list_packet_queue */
    0,    /* 507: of_list_port_desc */
    0,    /* 508: of_list_port_stats_entry */
    0,    /* 509: of_list_queue_prop */
    0,    /* 510: of_list_queue_stats_entry */
    0,    /* 511: of_list_table_feature_prop */
    0,    /* 512: of_list_table_features */
    0,    /* 513: of_list_table_stats_entry */
    0,    /* 514: of_list_uint32 */
    0,    /* 515: of_list_uint64 */
    0     /* 516: of_list_uint8 */
};

/**
 * Unified map of fixed length part of each object
 */
const int *const of_object_fixed_len[OF_VERSION_ARRAY_MAX] = {
    NULL,
    of_object_fixed_len_v1,
    of_object_fixed_len_v2,
    of_object_fixed_len_v3,
    of_object_fixed_len_v4,

};

/**
 * An array with the number of bytes in the extra length part
 * of each OF object
 */

static const int
of_object_extra_len_v1[OF_OBJECT_COUNT] = {
    -1,   /* of_object is not instantiable */
    0,    /* 1: of_aggregate_stats_reply */
    0,    /* 2: of_aggregate_stats_request */
    -1,   /* 3: of_async_get_reply */
    -1,   /* 4: of_async_get_request */
    -1,   /* 5: of_async_set */
    0,    /* 6: of_bad_action_error_msg */
    -1,   /* 7: of_bad_instruction_error_msg */
    -1,   /* 8: of_bad_match_error_msg */
    0,    /* 9: of_bad_request_error_msg */
    0,    /* 10: of_barrier_reply */
    0,    /* 11: of_barrier_request */
    -1,   /* 12: of_bsn_arp_idle */
    0,    /* 13: of_bsn_bw_clear_data_reply */
    0,    /* 14: of_bsn_bw_clear_data_request */
    0,    /* 15: of_bsn_bw_enable_get_reply */
    0,    /* 16: of_bsn_bw_enable_get_request */
    0,    /* 17: of_bsn_bw_enable_set_reply */
    0,    /* 18: of_bsn_bw_enable_set_request */
    -1,   /* 19: of_bsn_controller_connections_reply */
    -1,   /* 20: of_bsn_controller_connections_request */
    -1,   /* 21: of_bsn_debug_counter_desc_stats_reply */
    -1,   /* 22: of_bsn_debug_counter_desc_stats_request */
    -1,   /* 23: of_bsn_debug_counter_stats_reply */
    -1,   /* 24: of_bsn_debug_counter_stats_request */
    -1,   /* 25: of_bsn_flow_checksum_bucket_stats_reply */
    -1,   /* 26: of_bsn_flow_checksum_bucket_stats_request */
    -1,   /* 27: of_bsn_flow_idle */
    -1,   /* 28: of_bsn_flow_idle_enable_get_reply */
    -1,   /* 29: of_bsn_flow_idle_enable_get_request */
    -1,   /* 30: of_bsn_flow_idle_enable_set_reply */
    -1,   /* 31: of_bsn_flow_idle_enable_set_request */
    -1,   /* 32: of_bsn_gentable_bucket_stats_reply */
    -1,   /* 33: of_bsn_gentable_bucket_stats_request */
    -1,   /* 34: of_bsn_gentable_clear_reply */
    -1,   /* 35: of_bsn_gentable_clear_request */
    -1,   /* 36: of_bsn_gentable_desc_stats_reply */
    -1,   /* 37: of_bsn_gentable_desc_stats_request */
    -1,   /* 38: of_bsn_gentable_entry_add */
    -1,   /* 39: of_bsn_gentable_entry_delete */
    -1,   /* 40: of_bsn_gentable_entry_desc_stats_reply */
    -1,   /* 41: of_bsn_gentable_entry_desc_stats_request */
    -1,   /* 42: of_bsn_gentable_entry_stats_reply */
    -1,   /* 43: of_bsn_gentable_entry_stats_request */
    -1,   /* 44: of_bsn_gentable_set_buckets_size */
    -1,   /* 45: of_bsn_gentable_stats_reply */
    -1,   /* 46: of_bsn_gentable_stats_request */
    0,    /* 47: of_bsn_get_interfaces_reply */
    0,    /* 48: of_bsn_get_interfaces_request */
    0,    /* 49: of_bsn_get_ip_mask_reply */
    0,    /* 50: of_bsn_get_ip_mask_request */
    0,    /* 51: of_bsn_get_l2_table_reply */
    0,    /* 52: of_bsn_get_l2_table_request */
    0,    /* 53: of_bsn_get_mirroring_reply */
    0,    /* 54: of_bsn_get_mirroring_request */
    -1,   /* 55: of_bsn_get_switch_pipeline_reply */
    -1,   /* 56: of_bsn_get_switch_pipeline_request */
    0,    /* 57: of_bsn_header */
    0,    /* 58: of_bsn_hybrid_get_reply */
    0,    /* 59: of_bsn_hybrid_get_request */
    -1,   /* 60: of_bsn_image_desc_stats_reply */
    -1,   /* 61: of_bsn_image_desc_stats_request */
    -1,   /* 62: of_bsn_lacp_convergence_notif */
    -1,   /* 63: of_bsn_lacp_stats_reply */
    -1,   /* 64: of_bsn_lacp_stats_request */
    0,    /* 65: of_bsn_pdu_rx_reply */
    0,    /* 66: of_bsn_pdu_rx_request */
    0,    /* 67: of_bsn_pdu_rx_timeout */
    0,    /* 68: of_bsn_pdu_tx_reply */
    0,    /* 69: of_bsn_pdu_tx_request */
    -1,   /* 70: of_bsn_port_counter_stats_reply */
    -1,   /* 71: of_bsn_port_counter_stats_request */
    -1,   /* 72: of_bsn_role_status */
    -1,   /* 73: of_bsn_set_aux_cxns_reply */
    -1,   /* 74: of_bsn_set_aux_cxns_request */
    0,    /* 75: of_bsn_set_ip_mask */
    0,    /* 76: of_bsn_set_l2_table_reply */
    0,    /* 77: of_bsn_set_l2_table_request */
    -1,   /* 78: of_bsn_set_lacp_reply */
    -1,   /* 79: of_bsn_set_lacp_request */
    0,    /* 80: of_bsn_set_mirroring */
    0,    /* 81: of_bsn_set_pktin_suppression_reply */
    0,    /* 82: of_bsn_set_pktin_suppression_request */
    -1,   /* 83: of_bsn_set_switch_pipeline_reply */
    -1,   /* 84: of_bsn_set_switch_pipeline_request */
    0,    /* 85: of_bsn_shell_command */
    0,    /* 86: of_bsn_shell_output */
    0,    /* 87: of_bsn_shell_status */
    0,    /* 88: of_bsn_stats_reply */
    0,    /* 89: of_bsn_stats_request */
    -1,   /* 90: of_bsn_switch_pipeline_stats_reply */
    -1,   /* 91: of_bsn_switch_pipeline_stats_request */
    -1,   /* 92: of_bsn_table_checksum_stats_reply */
    -1,   /* 93: of_bsn_table_checksum_stats_request */
    -1,   /* 94: of_bsn_table_set_buckets_size */
    -1,   /* 95: of_bsn_time_reply */
    -1,   /* 96: of_bsn_time_request */
    0,    /* 97: of_bsn_virtual_port_create_reply */
    0,    /* 98: of_bsn_virtual_port_create_request */
    0,    /* 99: of_bsn_virtual_port_remove_reply */
    0,    /* 100: of_bsn_virtual_port_remove_request */
    -1,   /* 101: of_bsn_vlan_counter_stats_reply */
    -1,   /* 102: of_bsn_vlan_counter_stats_request */
    0,    /* 103: of_desc_stats_reply */
    0,    /* 104: of_desc_stats_request */
    0,    /* 105: of_echo_reply */
    0,    /* 106: of_echo_request */
    0,    /* 107: of_error_msg */
    0,    /* 108: of_experimenter */
    -1,   /* 109: of_experimenter_error_msg */
    0,    /* 110: of_experimenter_stats_reply */
    0,    /* 111: of_experimenter_stats_request */
    0,    /* 112: of_features_reply */
    0,    /* 113: of_features_request */
    0,    /* 114: of_flow_add */
    0,    /* 115: of_flow_delete */
    0,    /* 116: of_flow_delete_strict */
    0,    /* 117: of_flow_mod */
    0,    /* 118: of_flow_mod_failed_error_msg */
    0,    /* 119: of_flow_modify */
    0,    /* 120: of_flow_modify_strict */
    0,    /* 121: of_flow_removed */
    0,    /* 122: of_flow_stats_reply */
    0,    /* 123: of_flow_stats_request */
    0,    /* 124: of_get_config_reply */
    0,    /* 125: of_get_config_request */
    -1,   /* 126: of_group_add */
    -1,   /* 127: of_group_delete */
    -1,   /* 128: of_group_desc_stats_reply */
    -1,   /* 129: of_group_desc_stats_request */
    -1,   /* 130: of_group_features_stats_reply */
    -1,   /* 131: of_group_features_stats_request */
    -1,   /* 132: of_group_mod */
    -1,   /* 133: of_group_mod_failed_error_msg */
    -1,   /* 134: of_group_modify */
    -1,   /* 135: of_group_stats_reply */
    -1,   /* 136: of_group_stats_request */
    0,    /* 137: of_header */
    0,    /* 138: of_hello */
    0,    /* 139: of_hello_failed_error_msg */
    -1,   /* 140: of_meter_config_stats_reply */
    -1,   /* 141: of_meter_config_stats_request */
    -1,   /* 142: of_meter_features_stats_reply */
    -1,   /* 143: of_meter_features_stats_request */
    -1,   /* 144: of_meter_mod */
    -1,   /* 145: of_meter_mod_failed_error_msg */
    -1,   /* 146: of_meter_stats_reply */
    -1,   /* 147: of_meter_stats_request */
    0,    /* 148: of_nicira_controller_role_reply */
    0,    /* 149: of_nicira_controller_role_request */
    0,    /* 150: of_nicira_header */
    0,    /* 151: of_packet_in */
    0,    /* 152: of_packet_out */
    -1,   /* 153: of_port_desc_stats_reply */
    -1,   /* 154: of_port_desc_stats_request */
    0,    /* 155: of_port_mod */
    0,    /* 156: of_port_mod_failed_error_msg */
    0,    /* 157: of_port_stats_reply */
    0,    /* 158: of_port_stats_request */
    0,    /* 159: of_port_status */
    0,    /* 160: of_queue_get_config_reply */
    0,    /* 161: of_queue_get_config_request */
    0,    /* 162: of_queue_op_failed_error_msg */
    0,    /* 163: of_queue_stats_reply */
    0,    /* 164: of_queue_stats_request */
    -1,   /* 165: of_role_reply */
    -1,   /* 166: of_role_request */
    -1,   /* 167: of_role_request_failed_error_msg */
    0,    /* 168: of_set_config */
    0,    /* 169: of_stats_reply */
    0,    /* 170: of_stats_request */
    -1,   /* 171: of_switch_config_failed_error_msg */
    -1,   /* 172: of_table_features_failed_error_msg */
    -1,   /* 173: of_table_features_stats_reply */
    -1,   /* 174: of_table_features_stats_request */
    0,    /* 175: of_table_mod */
    -1,   /* 176: of_table_mod_failed_error_msg */
    0,    /* 177: of_table_stats_reply */
    0,    /* 178: of_table_stats_request */
    0,    /* 179: of_action */
    0,    /* 180: of_action_bsn */
    0,    /* 181: of_action_bsn_mirror */
    0,    /* 182: of_action_bsn_set_tunnel_dst */
    -1,   /* 183: of_action_copy_ttl_in */
    -1,   /* 184: of_action_copy_ttl_out */
    -1,   /* 185: of_action_dec_mpls_ttl */
    -1,   /* 186: of_action_dec_nw_ttl */
    0,    /* 187: of_action_enqueue */
    0,    /* 188: of_action_experimenter */
    -1,   /* 189: of_action_group */
    0,    /* 190: of_action_header */
    -1,   /* 191: of_action_id */
    -1,   /* 192: of_action_id_bsn */
    -1,   /* 193: of_action_id_bsn_mirror */
    -1,   /* 194: of_action_id_bsn_set_tunnel_dst */
    -1,   /* 195: of_action_id_copy_ttl_in */
    -1,   /* 196: of_action_id_copy_ttl_out */
    -1,   /* 197: of_action_id_dec_mpls_ttl */
    -1,   /* 198: of_action_id_dec_nw_ttl */
    -1,   /* 199: of_action_id_experimenter */
    -1,   /* 200: of_action_id_group */
    -1,   /* 201: of_action_id_header */
    -1,   /* 202: of_action_id_nicira */
    -1,   /* 203: of_action_id_nicira_dec_ttl */
    -1,   /* 204: of_action_id_output */
    -1,   /* 205: of_action_id_pop_mpls */
    -1,   /* 206: of_action_id_pop_pbb */
    -1,   /* 207: of_action_id_pop_vlan */
    -1,   /* 208: of_action_id_push_mpls */
    -1,   /* 209: of_action_id_push_pbb */
    -1,   /* 210: of_action_id_push_vlan */
    -1,   /* 211: of_action_id_set_field */
    -1,   /* 212: of_action_id_set_mpls_ttl */
    -1,   /* 213: of_action_id_set_nw_ttl */
    -1,   /* 214: of_action_id_set_queue */
    0,    /* 215: of_action_nicira */
    0,    /* 216: of_action_nicira_dec_ttl */
    0,    /* 217: of_action_output */
    -1,   /* 218: of_action_pop_mpls */
    -1,   /* 219: of_action_pop_pbb */
    -1,   /* 220: of_action_pop_vlan */
    -1,   /* 221: of_action_push_mpls */
    -1,   /* 222: of_action_push_pbb */
    -1,   /* 223: of_action_push_vlan */
    0,    /* 224: of_action_set_dl_dst */
    0,    /* 225: of_action_set_dl_src */
    -1,   /* 226: of_action_set_field */
    -1,   /* 227: of_action_set_mpls_label */
    -1,   /* 228: of_action_set_mpls_tc */
    -1,   /* 229: of_action_set_mpls_ttl */
    0,    /* 230: of_action_set_nw_dst */
    -1,   /* 231: of_action_set_nw_ecn */
    0,    /* 232: of_action_set_nw_src */
    0,    /* 233: of_action_set_nw_tos */
    -1,   /* 234: of_action_set_nw_ttl */
    -1,   /* 235: of_action_set_queue */
    0,    /* 236: of_action_set_tp_dst */
    0,    /* 237: of_action_set_tp_src */
    0,    /* 238: of_action_set_vlan_pcp */
    0,    /* 239: of_action_set_vlan_vid */
    0,    /* 240: of_action_strip_vlan */
    -1,   /* 241: of_bsn_controller_connection */
    -1,   /* 242: of_bsn_debug_counter_desc_stats_entry */
    -1,   /* 243: of_bsn_debug_counter_stats_entry */
    -1,   /* 244: of_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 245: of_bsn_gentable_bucket_stats_entry */
    -1,   /* 246: of_bsn_gentable_desc_stats_entry */
    -1,   /* 247: of_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 248: of_bsn_gentable_entry_stats_entry */
    -1,   /* 249: of_bsn_gentable_stats_entry */
    0,    /* 250: of_bsn_interface */
    -1,   /* 251: of_bsn_lacp_stats_entry */
    -1,   /* 252: of_bsn_port_counter_stats_entry */
    -1,   /* 253: of_bsn_switch_pipeline_stats_entry */
    -1,   /* 254: of_bsn_table_checksum_stats_entry */
    -1,   /* 255: of_bsn_tlv */
    -1,   /* 256: of_bsn_tlv_broadcast_query_timeout */
    -1,   /* 257: of_bsn_tlv_circuit_id */
    -1,   /* 258: of_bsn_tlv_header */
    -1,   /* 259: of_bsn_tlv_idle_notification */
    -1,   /* 260: of_bsn_tlv_idle_time */
    -1,   /* 261: of_bsn_tlv_idle_timeout */
    -1,   /* 262: of_bsn_tlv_ipv4 */
    -1,   /* 263: of_bsn_tlv_mac */
    -1,   /* 264: of_bsn_tlv_miss_packets */
    -1,   /* 265: of_bsn_tlv_port */
    -1,   /* 266: of_bsn_tlv_reply_packets */
    -1,   /* 267: of_bsn_tlv_request_packets */
    -1,   /* 268: of_bsn_tlv_rx_packets */
    -1,   /* 269: of_bsn_tlv_tx_packets */
    -1,   /* 270: of_bsn_tlv_udf_anchor */
    -1,   /* 271: of_bsn_tlv_udf_id */
    -1,   /* 272: of_bsn_tlv_udf_length */
    -1,   /* 273: of_bsn_tlv_udf_offset */
    -1,   /* 274: of_bsn_tlv_unicast_query_timeout */
    -1,   /* 275: of_bsn_tlv_vlan_vid */
    -1,   /* 276: of_bsn_tlv_vrf */
    -1,   /* 277: of_bsn_vlan_counter_stats_entry */
    0,    /* 278: of_bsn_vport */
    0,    /* 279: of_bsn_vport_header */
    0,    /* 280: of_bsn_vport_l2gre */
    0,    /* 281: of_bsn_vport_q_in_q */
    -1,   /* 282: of_bucket */
    -1,   /* 283: of_bucket_counter */
    0,    /* 284: of_flow_stats_entry */
    -1,   /* 285: of_group_desc_stats_entry */
    -1,   /* 286: of_group_stats_entry */
    -1,   /* 287: of_hello_elem */
    -1,   /* 288: of_hello_elem_header */
    -1,   /* 289: of_hello_elem_versionbitmap */
    -1,   /* 290: of_instruction */
    -1,   /* 291: of_instruction_apply_actions */
    -1,   /* 292: of_instruction_bsn */
    -1,   /* 293: of_instruction_bsn_arp_offload */
    -1,   /* 294: of_instruction_bsn_deny */
    -1,   /* 295: of_instruction_bsn_dhcp_offload */
    -1,   /* 296: of_instruction_bsn_disable_split_horizon_check */
    -1,   /* 297: of_instruction_bsn_disable_src_mac_check */
    -1,   /* 298: of_instruction_bsn_packet_of_death */
    -1,   /* 299: of_instruction_bsn_permit */
    -1,   /* 300: of_instruction_bsn_prioritize_pdus */
    -1,   /* 301: of_instruction_clear_actions */
    -1,   /* 302: of_instruction_experimenter */
    -1,   /* 303: of_instruction_goto_table */
    -1,   /* 304: of_instruction_header */
    -1,   /* 305: of_instruction_id */
    -1,   /* 306: of_instruction_id_apply_actions */
    -1,   /* 307: of_instruction_id_bsn */
    -1,   /* 308: of_instruction_id_bsn_arp_offload */
    -1,   /* 309: of_instruction_id_bsn_deny */
    -1,   /* 310: of_instruction_id_bsn_dhcp_offload */
    -1,   /* 311: of_instruction_id_bsn_disable_split_horizon_check */
    -1,   /* 312: of_instruction_id_bsn_disable_src_mac_check */
    -1,   /* 313: of_instruction_id_bsn_packet_of_death */
    -1,   /* 314: of_instruction_id_bsn_permit */
    -1,   /* 315: of_instruction_id_bsn_prioritize_pdus */
    -1,   /* 316: of_instruction_id_clear_actions */
    -1,   /* 317: of_instruction_id_experimenter */
    -1,   /* 318: of_instruction_id_goto_table */
    -1,   /* 319: of_instruction_id_header */
    -1,   /* 320: of_instruction_id_meter */
    -1,   /* 321: of_instruction_id_write_actions */
    -1,   /* 322: of_instruction_id_write_metadata */
    -1,   /* 323: of_instruction_meter */
    -1,   /* 324: of_instruction_write_actions */
    -1,   /* 325: of_instruction_write_metadata */
    0,    /* 326: of_match_v1 */
    -1,   /* 327: of_match_v2 */
    -1,   /* 328: of_match_v3 */
    -1,   /* 329: of_meter_band */
    -1,   /* 330: of_meter_band_drop */
    -1,   /* 331: of_meter_band_dscp_remark */
    -1,   /* 332: of_meter_band_experimenter */
    -1,   /* 333: of_meter_band_header */
    -1,   /* 334: of_meter_band_stats */
    -1,   /* 335: of_meter_config */
    -1,   /* 336: of_meter_features */
    -1,   /* 337: of_meter_stats */
    -1,   /* 338: of_oxm */
    -1,   /* 339: of_oxm_arp_op */
    -1,   /* 340: of_oxm_arp_op_masked */
    -1,   /* 341: of_oxm_arp_sha */
    -1,   /* 342: of_oxm_arp_sha_masked */
    -1,   /* 343: of_oxm_arp_spa */
    -1,   /* 344: of_oxm_arp_spa_masked */
    -1,   /* 345: of_oxm_arp_tha */
    -1,   /* 346: of_oxm_arp_tha_masked */
    -1,   /* 347: of_oxm_arp_tpa */
    -1,   /* 348: of_oxm_arp_tpa_masked */
    -1,   /* 349: of_oxm_bsn_egr_port_group_id */
    -1,   /* 350: of_oxm_bsn_egr_port_group_id_masked */
    -1,   /* 351: of_oxm_bsn_global_vrf_allowed */
    -1,   /* 352: of_oxm_bsn_global_vrf_allowed_masked */
    -1,   /* 353: of_oxm_bsn_in_ports_128 */
    -1,   /* 354: of_oxm_bsn_in_ports_128_masked */
    -1,   /* 355: of_oxm_bsn_l3_dst_class_id */
    -1,   /* 356: of_oxm_bsn_l3_dst_class_id_masked */
    -1,   /* 357: of_oxm_bsn_l3_interface_class_id */
    -1,   /* 358: of_oxm_bsn_l3_interface_class_id_masked */
    -1,   /* 359: of_oxm_bsn_l3_src_class_id */
    -1,   /* 360: of_oxm_bsn_l3_src_class_id_masked */
    -1,   /* 361: of_oxm_bsn_lag_id */
    -1,   /* 362: of_oxm_bsn_lag_id_masked */
    -1,   /* 363: of_oxm_bsn_udf0 */
    -1,   /* 364: of_oxm_bsn_udf0_masked */
    -1,   /* 365: of_oxm_bsn_udf1 */
    -1,   /* 366: of_oxm_bsn_udf1_masked */
    -1,   /* 367: of_oxm_bsn_udf2 */
    -1,   /* 368: of_oxm_bsn_udf2_masked */
    -1,   /* 369: of_oxm_bsn_udf3 */
    -1,   /* 370: of_oxm_bsn_udf3_masked */
    -1,   /* 371: of_oxm_bsn_udf4 */
    -1,   /* 372: of_oxm_bsn_udf4_masked */
    -1,   /* 373: of_oxm_bsn_udf5 */
    -1,   /* 374: of_oxm_bsn_udf5_masked */
    -1,   /* 375: of_oxm_bsn_udf6 */
    -1,   /* 376: of_oxm_bsn_udf6_masked */
    -1,   /* 377: of_oxm_bsn_udf7 */
    -1,   /* 378: of_oxm_bsn_udf7_masked */
    -1,   /* 379: of_oxm_bsn_vrf */
    -1,   /* 380: of_oxm_bsn_vrf_masked */
    -1,   /* 381: of_oxm_eth_dst */
    -1,   /* 382: of_oxm_eth_dst_masked */
    -1,   /* 383: of_oxm_eth_src */
    -1,   /* 384: of_oxm_eth_src_masked */
    -1,   /* 385: of_oxm_eth_type */
    -1,   /* 386: of_oxm_eth_type_masked */
    -1,   /* 387: of_oxm_header */
    -1,   /* 388: of_oxm_icmpv4_code */
    -1,   /* 389: of_oxm_icmpv4_code_masked */
    -1,   /* 390: of_oxm_icmpv4_type */
    -1,   /* 391: of_oxm_icmpv4_type_masked */
    -1,   /* 392: of_oxm_icmpv6_code */
    -1,   /* 393: of_oxm_icmpv6_code_masked */
    -1,   /* 394: of_oxm_icmpv6_type */
    -1,   /* 395: of_oxm_icmpv6_type_masked */
    -1,   /* 396: of_oxm_in_phy_port */
    -1,   /* 397: of_oxm_in_phy_port_masked */
    -1,   /* 398: of_oxm_in_port */
    -1,   /* 399: of_oxm_in_port_masked */
    -1,   /* 400: of_oxm_ip_dscp */
    -1,   /* 401: of_oxm_ip_dscp_masked */
    -1,   /* 402: of_oxm_ip_ecn */
    -1,   /* 403: of_oxm_ip_ecn_masked */
    -1,   /* 404: of_oxm_ip_proto */
    -1,   /* 405: of_oxm_ip_proto_masked */
    -1,   /* 406: of_oxm_ipv4_dst */
    -1,   /* 407: of_oxm_ipv4_dst_masked */
    -1,   /* 408: of_oxm_ipv4_src */
    -1,   /* 409: of_oxm_ipv4_src_masked */
    -1,   /* 410: of_oxm_ipv6_dst */
    -1,   /* 411: of_oxm_ipv6_dst_masked */
    -1,   /* 412: of_oxm_ipv6_flabel */
    -1,   /* 413: of_oxm_ipv6_flabel_masked */
    -1,   /* 414: of_oxm_ipv6_nd_sll */
    -1,   /* 415: of_oxm_ipv6_nd_sll_masked */
    -1,   /* 416: of_oxm_ipv6_nd_target */
    -1,   /* 417: of_oxm_ipv6_nd_target_masked */
    -1,   /* 418: of_oxm_ipv6_nd_tll */
    -1,   /* 419: of_oxm_ipv6_nd_tll_masked */
    -1,   /* 420: of_oxm_ipv6_src */
    -1,   /* 421: of_oxm_ipv6_src_masked */
    -1,   /* 422: of_oxm_metadata */
    -1,   /* 423: of_oxm_metadata_masked */
    -1,   /* 424: of_oxm_mpls_label */
    -1,   /* 425: of_oxm_mpls_label_masked */
    -1,   /* 426: of_oxm_mpls_tc */
    -1,   /* 427: of_oxm_mpls_tc_masked */
    -1,   /* 428: of_oxm_sctp_dst */
    -1,   /* 429: of_oxm_sctp_dst_masked */
    -1,   /* 430: of_oxm_sctp_src */
    -1,   /* 431: of_oxm_sctp_src_masked */
    -1,   /* 432: of_oxm_tcp_dst */
    -1,   /* 433: of_oxm_tcp_dst_masked */
    -1,   /* 434: of_oxm_tcp_src */
    -1,   /* 435: of_oxm_tcp_src_masked */
    -1,   /* 436: of_oxm_udp_dst */
    -1,   /* 437: of_oxm_udp_dst_masked */
    -1,   /* 438: of_oxm_udp_src */
    -1,   /* 439: of_oxm_udp_src_masked */
    -1,   /* 440: of_oxm_vlan_pcp */
    -1,   /* 441: of_oxm_vlan_pcp_masked */
    -1,   /* 442: of_oxm_vlan_vid */
    -1,   /* 443: of_oxm_vlan_vid_masked */
    0,    /* 444: of_packet_queue */
    0,    /* 445: of_port_desc */
    0,    /* 446: of_port_stats_entry */
    0,    /* 447: of_queue_prop */
    -1,   /* 448: of_queue_prop_experimenter */
    0,    /* 449: of_queue_prop_header */
    -1,   /* 450: of_queue_prop_max_rate */
    0,    /* 451: of_queue_prop_min_rate */
    0,    /* 452: of_queue_stats_entry */
    -1,   /* 453: of_table_feature_prop */
    -1,   /* 454: of_table_feature_prop_apply_actions */
    -1,   /* 455: of_table_feature_prop_apply_actions_miss */
    -1,   /* 456: of_table_feature_prop_apply_setfield */
    -1,   /* 457: of_table_feature_prop_apply_setfield_miss */
    -1,   /* 458: of_table_feature_prop_experimenter */
    -1,   /* 459: of_table_feature_prop_experimenter_miss */
    -1,   /* 460: of_table_feature_prop_header */
    -1,   /* 461: of_table_feature_prop_instructions */
    -1,   /* 462: of_table_feature_prop_instructions_miss */
    -1,   /* 463: of_table_feature_prop_match */
    -1,   /* 464: of_table_feature_prop_next_tables */
    -1,   /* 465: of_table_feature_prop_next_tables_miss */
    -1,   /* 466: of_table_feature_prop_wildcards */
    -1,   /* 467: of_table_feature_prop_write_actions */
    -1,   /* 468: of_table_feature_prop_write_actions_miss */
    -1,   /* 469: of_table_feature_prop_write_setfield */
    -1,   /* 470: of_table_feature_prop_write_setfield_miss */
    -1,   /* 471: of_table_features */
    0,    /* 472: of_table_stats_entry */
    -1,   /* 473: of_uint32 */
    -1,   /* 474: of_uint64 */
    -1,   /* 475: of_uint8 */
    0,    /* 476: of_list_action */
    -1,   /* 477: of_list_action_id */
    -1,   /* 478: of_list_bsn_controller_connection */
    -1,   /* 479: of_list_bsn_debug_counter_desc_stats_entry */
    -1,   /* 480: of_list_bsn_debug_counter_stats_entry */
    -1,   /* 481: of_list_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 482: of_list_bsn_gentable_bucket_stats_entry */
    -1,   /* 483: of_list_bsn_gentable_desc_stats_entry */
    -1,   /* 484: of_list_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 485: of_list_bsn_gentable_entry_stats_entry */
    -1,   /* 486: of_list_bsn_gentable_stats_entry */
    0,    /* 487: of_list_bsn_interface */
    -1,   /* 488: of_list_bsn_lacp_stats_entry */
    -1,   /* 489: of_list_bsn_port_counter_stats_entry */
    -1,   /* 490: of_list_bsn_switch_pipeline_stats_entry */
    -1,   /* 491: of_list_bsn_table_checksum_stats_entry */
    -1,   /* 492: of_list_bsn_tlv */
    -1,   /* 493: of_list_bsn_vlan_counter_stats_entry */
    -1,   /* 494: of_list_bucket */
    -1,   /* 495: of_list_bucket_counter */
    0,    /* 496: of_list_flow_stats_entry */
    -1,   /* 497: of_list_group_desc_stats_entry */
    -1,   /* 498: of_list_group_stats_entry */
    -1,   /* 499: of_list_hello_elem */
    -1,   /* 500: of_list_instruction */
    -1,   /* 501: of_list_instruction_id */
    -1,   /* 502: of_list_meter_band */
    -1,   /* 503: of_list_meter_band_stats */
    -1,   /* 504: of_list_meter_stats */
    -1,   /* 505: of_list_oxm */
    0,    /* 506: of_list_packet_queue */
    0,    /* 507: of_list_port_desc */
    0,    /* 508: of_list_port_stats_entry */
    0,    /* 509: of_list_queue_prop */
    0,    /* 510: of_list_queue_stats_entry */
    -1,   /* 511: of_list_table_feature_prop */
    -1,   /* 512: of_list_table_features */
    0,    /* 513: of_list_table_stats_entry */
    -1,   /* 514: of_list_uint32 */
    -1,   /* 515: of_list_uint64 */
    -1    /* 516: of_list_uint8 */
};

static const int
of_object_extra_len_v2[OF_OBJECT_COUNT] = {
    -1,   /* of_object is not instantiable */
    0,    /* 1: of_aggregate_stats_reply */
    0,    /* 2: of_aggregate_stats_request */
    -1,   /* 3: of_async_get_reply */
    -1,   /* 4: of_async_get_request */
    -1,   /* 5: of_async_set */
    0,    /* 6: of_bad_action_error_msg */
    0,    /* 7: of_bad_instruction_error_msg */
    0,    /* 8: of_bad_match_error_msg */
    0,    /* 9: of_bad_request_error_msg */
    0,    /* 10: of_barrier_reply */
    0,    /* 11: of_barrier_request */
    -1,   /* 12: of_bsn_arp_idle */
    0,    /* 13: of_bsn_bw_clear_data_reply */
    0,    /* 14: of_bsn_bw_clear_data_request */
    0,    /* 15: of_bsn_bw_enable_get_reply */
    0,    /* 16: of_bsn_bw_enable_get_request */
    0,    /* 17: of_bsn_bw_enable_set_reply */
    0,    /* 18: of_bsn_bw_enable_set_request */
    -1,   /* 19: of_bsn_controller_connections_reply */
    -1,   /* 20: of_bsn_controller_connections_request */
    -1,   /* 21: of_bsn_debug_counter_desc_stats_reply */
    -1,   /* 22: of_bsn_debug_counter_desc_stats_request */
    -1,   /* 23: of_bsn_debug_counter_stats_reply */
    -1,   /* 24: of_bsn_debug_counter_stats_request */
    -1,   /* 25: of_bsn_flow_checksum_bucket_stats_reply */
    -1,   /* 26: of_bsn_flow_checksum_bucket_stats_request */
    -1,   /* 27: of_bsn_flow_idle */
    -1,   /* 28: of_bsn_flow_idle_enable_get_reply */
    -1,   /* 29: of_bsn_flow_idle_enable_get_request */
    -1,   /* 30: of_bsn_flow_idle_enable_set_reply */
    -1,   /* 31: of_bsn_flow_idle_enable_set_request */
    -1,   /* 32: of_bsn_gentable_bucket_stats_reply */
    -1,   /* 33: of_bsn_gentable_bucket_stats_request */
    -1,   /* 34: of_bsn_gentable_clear_reply */
    -1,   /* 35: of_bsn_gentable_clear_request */
    -1,   /* 36: of_bsn_gentable_desc_stats_reply */
    -1,   /* 37: of_bsn_gentable_desc_stats_request */
    -1,   /* 38: of_bsn_gentable_entry_add */
    -1,   /* 39: of_bsn_gentable_entry_delete */
    -1,   /* 40: of_bsn_gentable_entry_desc_stats_reply */
    -1,   /* 41: of_bsn_gentable_entry_desc_stats_request */
    -1,   /* 42: of_bsn_gentable_entry_stats_reply */
    -1,   /* 43: of_bsn_gentable_entry_stats_request */
    -1,   /* 44: of_bsn_gentable_set_buckets_size */
    -1,   /* 45: of_bsn_gentable_stats_reply */
    -1,   /* 46: of_bsn_gentable_stats_request */
    0,    /* 47: of_bsn_get_interfaces_reply */
    0,    /* 48: of_bsn_get_interfaces_request */
    -1,   /* 49: of_bsn_get_ip_mask_reply */
    -1,   /* 50: of_bsn_get_ip_mask_request */
    -1,   /* 51: of_bsn_get_l2_table_reply */
    -1,   /* 52: of_bsn_get_l2_table_request */
    0,    /* 53: of_bsn_get_mirroring_reply */
    0,    /* 54: of_bsn_get_mirroring_request */
    -1,   /* 55: of_bsn_get_switch_pipeline_reply */
    -1,   /* 56: of_bsn_get_switch_pipeline_request */
    0,    /* 57: of_bsn_header */
    -1,   /* 58: of_bsn_hybrid_get_reply */
    -1,   /* 59: of_bsn_hybrid_get_request */
    -1,   /* 60: of_bsn_image_desc_stats_reply */
    -1,   /* 61: of_bsn_image_desc_stats_request */
    -1,   /* 62: of_bsn_lacp_convergence_notif */
    -1,   /* 63: of_bsn_lacp_stats_reply */
    -1,   /* 64: of_bsn_lacp_stats_request */
    0,    /* 65: of_bsn_pdu_rx_reply */
    0,    /* 66: of_bsn_pdu_rx_request */
    0,    /* 67: of_bsn_pdu_rx_timeout */
    0,    /* 68: of_bsn_pdu_tx_reply */
    0,    /* 69: of_bsn_pdu_tx_request */
    -1,   /* 70: of_bsn_port_counter_stats_reply */
    -1,   /* 71: of_bsn_port_counter_stats_request */
    -1,   /* 72: of_bsn_role_status */
    -1,   /* 73: of_bsn_set_aux_cxns_reply */
    -1,   /* 74: of_bsn_set_aux_cxns_request */
    -1,   /* 75: of_bsn_set_ip_mask */
    -1,   /* 76: of_bsn_set_l2_table_reply */
    -1,   /* 77: of_bsn_set_l2_table_request */
    -1,   /* 78: of_bsn_set_lacp_reply */
    -1,   /* 79: of_bsn_set_lacp_request */
    0,    /* 80: of_bsn_set_mirroring */
    0,    /* 81: of_bsn_set_pktin_suppression_reply */
    0,    /* 82: of_bsn_set_pktin_suppression_request */
    -1,   /* 83: of_bsn_set_switch_pipeline_reply */
    -1,   /* 84: of_bsn_set_switch_pipeline_request */
    -1,   /* 85: of_bsn_shell_command */
    -1,   /* 86: of_bsn_shell_output */
    -1,   /* 87: of_bsn_shell_status */
    0,    /* 88: of_bsn_stats_reply */
    0,    /* 89: of_bsn_stats_request */
    -1,   /* 90: of_bsn_switch_pipeline_stats_reply */
    -1,   /* 91: of_bsn_switch_pipeline_stats_request */
    -1,   /* 92: of_bsn_table_checksum_stats_reply */
    -1,   /* 93: of_bsn_table_checksum_stats_request */
    -1,   /* 94: of_bsn_table_set_buckets_size */
    -1,   /* 95: of_bsn_time_reply */
    -1,   /* 96: of_bsn_time_request */
    0,    /* 97: of_bsn_virtual_port_create_reply */
    0,    /* 98: of_bsn_virtual_port_create_request */
    0,    /* 99: of_bsn_virtual_port_remove_reply */
    0,    /* 100: of_bsn_virtual_port_remove_request */
    -1,   /* 101: of_bsn_vlan_counter_stats_reply */
    -1,   /* 102: of_bsn_vlan_counter_stats_request */
    0,    /* 103: of_desc_stats_reply */
    0,    /* 104: of_desc_stats_request */
    0,    /* 105: of_echo_reply */
    0,    /* 106: of_echo_request */
    0,    /* 107: of_error_msg */
    0,    /* 108: of_experimenter */
    -1,   /* 109: of_experimenter_error_msg */
    0,    /* 110: of_experimenter_stats_reply */
    0,    /* 111: of_experimenter_stats_request */
    0,    /* 112: of_features_reply */
    0,    /* 113: of_features_request */
    0,    /* 114: of_flow_add */
    0,    /* 115: of_flow_delete */
    0,    /* 116: of_flow_delete_strict */
    0,    /* 117: of_flow_mod */
    0,    /* 118: of_flow_mod_failed_error_msg */
    0,    /* 119: of_flow_modify */
    0,    /* 120: of_flow_modify_strict */
    0,    /* 121: of_flow_removed */
    0,    /* 122: of_flow_stats_reply */
    0,    /* 123: of_flow_stats_request */
    0,    /* 124: of_get_config_reply */
    0,    /* 125: of_get_config_request */
    0,    /* 126: of_group_add */
    0,    /* 127: of_group_delete */
    0,    /* 128: of_group_desc_stats_reply */
    0,    /* 129: of_group_desc_stats_request */
    -1,   /* 130: of_group_features_stats_reply */
    -1,   /* 131: of_group_features_stats_request */
    0,    /* 132: of_group_mod */
    0,    /* 133: of_group_mod_failed_error_msg */
    0,    /* 134: of_group_modify */
    0,    /* 135: of_group_stats_reply */
    0,    /* 136: of_group_stats_request */
    0,    /* 137: of_header */
    0,    /* 138: of_hello */
    0,    /* 139: of_hello_failed_error_msg */
    -1,   /* 140: of_meter_config_stats_reply */
    -1,   /* 141: of_meter_config_stats_request */
    -1,   /* 142: of_meter_features_stats_reply */
    -1,   /* 143: of_meter_features_stats_request */
    -1,   /* 144: of_meter_mod */
    -1,   /* 145: of_meter_mod_failed_error_msg */
    -1,   /* 146: of_meter_stats_reply */
    -1,   /* 147: of_meter_stats_request */
    -1,   /* 148: of_nicira_controller_role_reply */
    -1,   /* 149: of_nicira_controller_role_request */
    0,    /* 150: of_nicira_header */
    0,    /* 151: of_packet_in */
    0,    /* 152: of_packet_out */
    -1,   /* 153: of_port_desc_stats_reply */
    -1,   /* 154: of_port_desc_stats_request */
    0,    /* 155: of_port_mod */
    0,    /* 156: of_port_mod_failed_error_msg */
    0,    /* 157: of_port_stats_reply */
    0,    /* 158: of_port_stats_request */
    0,    /* 159: of_port_status */
    0,    /* 160: of_queue_get_config_reply */
    0,    /* 161: of_queue_get_config_request */
    0,    /* 162: of_queue_op_failed_error_msg */
    0,    /* 163: of_queue_stats_reply */
    0,    /* 164: of_queue_stats_request */
    -1,   /* 165: of_role_reply */
    -1,   /* 166: of_role_request */
    -1,   /* 167: of_role_request_failed_error_msg */
    0,    /* 168: of_set_config */
    0,    /* 169: of_stats_reply */
    0,    /* 170: of_stats_request */
    0,    /* 171: of_switch_config_failed_error_msg */
    -1,   /* 172: of_table_features_failed_error_msg */
    -1,   /* 173: of_table_features_stats_reply */
    -1,   /* 174: of_table_features_stats_request */
    0,    /* 175: of_table_mod */
    0,    /* 176: of_table_mod_failed_error_msg */
    0,    /* 177: of_table_stats_reply */
    0,    /* 178: of_table_stats_request */
    0,    /* 179: of_action */
    0,    /* 180: of_action_bsn */
    0,    /* 181: of_action_bsn_mirror */
    0,    /* 182: of_action_bsn_set_tunnel_dst */
    0,    /* 183: of_action_copy_ttl_in */
    0,    /* 184: of_action_copy_ttl_out */
    0,    /* 185: of_action_dec_mpls_ttl */
    0,    /* 186: of_action_dec_nw_ttl */
    -1,   /* 187: of_action_enqueue */
    0,    /* 188: of_action_experimenter */
    0,    /* 189: of_action_group */
    0,    /* 190: of_action_header */
    -1,   /* 191: of_action_id */
    -1,   /* 192: of_action_id_bsn */
    -1,   /* 193: of_action_id_bsn_mirror */
    -1,   /* 194: of_action_id_bsn_set_tunnel_dst */
    -1,   /* 195: of_action_id_copy_ttl_in */
    -1,   /* 196: of_action_id_copy_ttl_out */
    -1,   /* 197: of_action_id_dec_mpls_ttl */
    -1,   /* 198: of_action_id_dec_nw_ttl */
    -1,   /* 199: of_action_id_experimenter */
    -1,   /* 200: of_action_id_group */
    -1,   /* 201: of_action_id_header */
    -1,   /* 202: of_action_id_nicira */
    -1,   /* 203: of_action_id_nicira_dec_ttl */
    -1,   /* 204: of_action_id_output */
    -1,   /* 205: of_action_id_pop_mpls */
    -1,   /* 206: of_action_id_pop_pbb */
    -1,   /* 207: of_action_id_pop_vlan */
    -1,   /* 208: of_action_id_push_mpls */
    -1,   /* 209: of_action_id_push_pbb */
    -1,   /* 210: of_action_id_push_vlan */
    -1,   /* 211: of_action_id_set_field */
    -1,   /* 212: of_action_id_set_mpls_ttl */
    -1,   /* 213: of_action_id_set_nw_ttl */
    -1,   /* 214: of_action_id_set_queue */
    0,    /* 215: of_action_nicira */
    0,    /* 216: of_action_nicira_dec_ttl */
    0,    /* 217: of_action_output */
    0,    /* 218: of_action_pop_mpls */
    -1,   /* 219: of_action_pop_pbb */
    0,    /* 220: of_action_pop_vlan */
    0,    /* 221: of_action_push_mpls */
    -1,   /* 222: of_action_push_pbb */
    0,    /* 223: of_action_push_vlan */
    0,    /* 224: of_action_set_dl_dst */
    0,    /* 225: of_action_set_dl_src */
    -1,   /* 226: of_action_set_field */
    0,    /* 227: of_action_set_mpls_label */
    0,    /* 228: of_action_set_mpls_tc */
    0,    /* 229: of_action_set_mpls_ttl */
    0,    /* 230: of_action_set_nw_dst */
    0,    /* 231: of_action_set_nw_ecn */
    0,    /* 232: of_action_set_nw_src */
    0,    /* 233: of_action_set_nw_tos */
    0,    /* 234: of_action_set_nw_ttl */
    0,    /* 235: of_action_set_queue */
    0,    /* 236: of_action_set_tp_dst */
    0,    /* 237: of_action_set_tp_src */
    0,    /* 238: of_action_set_vlan_pcp */
    0,    /* 239: of_action_set_vlan_vid */
    -1,   /* 240: of_action_strip_vlan */
    -1,   /* 241: of_bsn_controller_connection */
    -1,   /* 242: of_bsn_debug_counter_desc_stats_entry */
    -1,   /* 243: of_bsn_debug_counter_stats_entry */
    -1,   /* 244: of_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 245: of_bsn_gentable_bucket_stats_entry */
    -1,   /* 246: of_bsn_gentable_desc_stats_entry */
    -1,   /* 247: of_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 248: of_bsn_gentable_entry_stats_entry */
    -1,   /* 249: of_bsn_gentable_stats_entry */
    0,    /* 250: of_bsn_interface */
    -1,   /* 251: of_bsn_lacp_stats_entry */
    -1,   /* 252: of_bsn_port_counter_stats_entry */
    -1,   /* 253: of_bsn_switch_pipeline_stats_entry */
    -1,   /* 254: of_bsn_table_checksum_stats_entry */
    -1,   /* 255: of_bsn_tlv */
    -1,   /* 256: of_bsn_tlv_broadcast_query_timeout */
    -1,   /* 257: of_bsn_tlv_circuit_id */
    -1,   /* 258: of_bsn_tlv_header */
    -1,   /* 259: of_bsn_tlv_idle_notification */
    -1,   /* 260: of_bsn_tlv_idle_time */
    -1,   /* 261: of_bsn_tlv_idle_timeout */
    -1,   /* 262: of_bsn_tlv_ipv4 */
    -1,   /* 263: of_bsn_tlv_mac */
    -1,   /* 264: of_bsn_tlv_miss_packets */
    -1,   /* 265: of_bsn_tlv_port */
    -1,   /* 266: of_bsn_tlv_reply_packets */
    -1,   /* 267: of_bsn_tlv_request_packets */
    -1,   /* 268: of_bsn_tlv_rx_packets */
    -1,   /* 269: of_bsn_tlv_tx_packets */
    -1,   /* 270: of_bsn_tlv_udf_anchor */
    -1,   /* 271: of_bsn_tlv_udf_id */
    -1,   /* 272: of_bsn_tlv_udf_length */
    -1,   /* 273: of_bsn_tlv_udf_offset */
    -1,   /* 274: of_bsn_tlv_unicast_query_timeout */
    -1,   /* 275: of_bsn_tlv_vlan_vid */
    -1,   /* 276: of_bsn_tlv_vrf */
    -1,   /* 277: of_bsn_vlan_counter_stats_entry */
    0,    /* 278: of_bsn_vport */
    0,    /* 279: of_bsn_vport_header */
    0,    /* 280: of_bsn_vport_l2gre */
    0,    /* 281: of_bsn_vport_q_in_q */
    0,    /* 282: of_bucket */
    0,    /* 283: of_bucket_counter */
    0,    /* 284: of_flow_stats_entry */
    0,    /* 285: of_group_desc_stats_entry */
    0,    /* 286: of_group_stats_entry */
    -1,   /* 287: of_hello_elem */
    -1,   /* 288: of_hello_elem_header */
    -1,   /* 289: of_hello_elem_versionbitmap */
    0,    /* 290: of_instruction */
    0,    /* 291: of_instruction_apply_actions */
    -1,   /* 292: of_instruction_bsn */
    -1,   /* 293: of_instruction_bsn_arp_offload */
    -1,   /* 294: of_instruction_bsn_deny */
    -1,   /* 295: of_instruction_bsn_dhcp_offload */
    -1,   /* 296: of_instruction_bsn_disable_split_horizon_check */
    -1,   /* 297: of_instruction_bsn_disable_src_mac_check */
    -1,   /* 298: of_instruction_bsn_packet_of_death */
    -1,   /* 299: of_instruction_bsn_permit */
    -1,   /* 300: of_instruction_bsn_prioritize_pdus */
    0,    /* 301: of_instruction_clear_actions */
    0,    /* 302: of_instruction_experimenter */
    0,    /* 303: of_instruction_goto_table */
    0,    /* 304: of_instruction_header */
    -1,   /* 305: of_instruction_id */
    -1,   /* 306: of_instruction_id_apply_actions */
    -1,   /* 307: of_instruction_id_bsn */
    -1,   /* 308: of_instruction_id_bsn_arp_offload */
    -1,   /* 309: of_instruction_id_bsn_deny */
    -1,   /* 310: of_instruction_id_bsn_dhcp_offload */
    -1,   /* 311: of_instruction_id_bsn_disable_split_horizon_check */
    -1,   /* 312: of_instruction_id_bsn_disable_src_mac_check */
    -1,   /* 313: of_instruction_id_bsn_packet_of_death */
    -1,   /* 314: of_instruction_id_bsn_permit */
    -1,   /* 315: of_instruction_id_bsn_prioritize_pdus */
    -1,   /* 316: of_instruction_id_clear_actions */
    -1,   /* 317: of_instruction_id_experimenter */
    -1,   /* 318: of_instruction_id_goto_table */
    -1,   /* 319: of_instruction_id_header */
    -1,   /* 320: of_instruction_id_meter */
    -1,   /* 321: of_instruction_id_write_actions */
    -1,   /* 322: of_instruction_id_write_metadata */
    -1,   /* 323: of_instruction_meter */
    0,    /* 324: of_instruction_write_actions */
    0,    /* 325: of_instruction_write_metadata */
    -1,   /* 326: of_match_v1 */
    0,    /* 327: of_match_v2 */
    -1,   /* 328: of_match_v3 */
    -1,   /* 329: of_meter_band */
    -1,   /* 330: of_meter_band_drop */
    -1,   /* 331: of_meter_band_dscp_remark */
    -1,   /* 332: of_meter_band_experimenter */
    -1,   /* 333: of_meter_band_header */
    -1,   /* 334: of_meter_band_stats */
    -1,   /* 335: of_meter_config */
    -1,   /* 336: of_meter_features */
    -1,   /* 337: of_meter_stats */
    -1,   /* 338: of_oxm */
    -1,   /* 339: of_oxm_arp_op */
    -1,   /* 340: of_oxm_arp_op_masked */
    -1,   /* 341: of_oxm_arp_sha */
    -1,   /* 342: of_oxm_arp_sha_masked */
    -1,   /* 343: of_oxm_arp_spa */
    -1,   /* 344: of_oxm_arp_spa_masked */
    -1,   /* 345: of_oxm_arp_tha */
    -1,   /* 346: of_oxm_arp_tha_masked */
    -1,   /* 347: of_oxm_arp_tpa */
    -1,   /* 348: of_oxm_arp_tpa_masked */
    -1,   /* 349: of_oxm_bsn_egr_port_group_id */
    -1,   /* 350: of_oxm_bsn_egr_port_group_id_masked */
    -1,   /* 351: of_oxm_bsn_global_vrf_allowed */
    -1,   /* 352: of_oxm_bsn_global_vrf_allowed_masked */
    -1,   /* 353: of_oxm_bsn_in_ports_128 */
    -1,   /* 354: of_oxm_bsn_in_ports_128_masked */
    -1,   /* 355: of_oxm_bsn_l3_dst_class_id */
    -1,   /* 356: of_oxm_bsn_l3_dst_class_id_masked */
    -1,   /* 357: of_oxm_bsn_l3_interface_class_id */
    -1,   /* 358: of_oxm_bsn_l3_interface_class_id_masked */
    -1,   /* 359: of_oxm_bsn_l3_src_class_id */
    -1,   /* 360: of_oxm_bsn_l3_src_class_id_masked */
    -1,   /* 361: of_oxm_bsn_lag_id */
    -1,   /* 362: of_oxm_bsn_lag_id_masked */
    -1,   /* 363: of_oxm_bsn_udf0 */
    -1,   /* 364: of_oxm_bsn_udf0_masked */
    -1,   /* 365: of_oxm_bsn_udf1 */
    -1,   /* 366: of_oxm_bsn_udf1_masked */
    -1,   /* 367: of_oxm_bsn_udf2 */
    -1,   /* 368: of_oxm_bsn_udf2_masked */
    -1,   /* 369: of_oxm_bsn_udf3 */
    -1,   /* 370: of_oxm_bsn_udf3_masked */
    -1,   /* 371: of_oxm_bsn_udf4 */
    -1,   /* 372: of_oxm_bsn_udf4_masked */
    -1,   /* 373: of_oxm_bsn_udf5 */
    -1,   /* 374: of_oxm_bsn_udf5_masked */
    -1,   /* 375: of_oxm_bsn_udf6 */
    -1,   /* 376: of_oxm_bsn_udf6_masked */
    -1,   /* 377: of_oxm_bsn_udf7 */
    -1,   /* 378: of_oxm_bsn_udf7_masked */
    -1,   /* 379: of_oxm_bsn_vrf */
    -1,   /* 380: of_oxm_bsn_vrf_masked */
    -1,   /* 381: of_oxm_eth_dst */
    -1,   /* 382: of_oxm_eth_dst_masked */
    -1,   /* 383: of_oxm_eth_src */
    -1,   /* 384: of_oxm_eth_src_masked */
    -1,   /* 385: of_oxm_eth_type */
    -1,   /* 386: of_oxm_eth_type_masked */
    -1,   /* 387: of_oxm_header */
    -1,   /* 388: of_oxm_icmpv4_code */
    -1,   /* 389: of_oxm_icmpv4_code_masked */
    -1,   /* 390: of_oxm_icmpv4_type */
    -1,   /* 391: of_oxm_icmpv4_type_masked */
    -1,   /* 392: of_oxm_icmpv6_code */
    -1,   /* 393: of_oxm_icmpv6_code_masked */
    -1,   /* 394: of_oxm_icmpv6_type */
    -1,   /* 395: of_oxm_icmpv6_type_masked */
    -1,   /* 396: of_oxm_in_phy_port */
    -1,   /* 397: of_oxm_in_phy_port_masked */
    -1,   /* 398: of_oxm_in_port */
    -1,   /* 399: of_oxm_in_port_masked */
    -1,   /* 400: of_oxm_ip_dscp */
    -1,   /* 401: of_oxm_ip_dscp_masked */
    -1,   /* 402: of_oxm_ip_ecn */
    -1,   /* 403: of_oxm_ip_ecn_masked */
    -1,   /* 404: of_oxm_ip_proto */
    -1,   /* 405: of_oxm_ip_proto_masked */
    -1,   /* 406: of_oxm_ipv4_dst */
    -1,   /* 407: of_oxm_ipv4_dst_masked */
    -1,   /* 408: of_oxm_ipv4_src */
    -1,   /* 409: of_oxm_ipv4_src_masked */
    -1,   /* 410: of_oxm_ipv6_dst */
    -1,   /* 411: of_oxm_ipv6_dst_masked */
    -1,   /* 412: of_oxm_ipv6_flabel */
    -1,   /* 413: of_oxm_ipv6_flabel_masked */
    -1,   /* 414: of_oxm_ipv6_nd_sll */
    -1,   /* 415: of_oxm_ipv6_nd_sll_masked */
    -1,   /* 416: of_oxm_ipv6_nd_target */
    -1,   /* 417: of_oxm_ipv6_nd_target_masked */
    -1,   /* 418: of_oxm_ipv6_nd_tll */
    -1,   /* 419: of_oxm_ipv6_nd_tll_masked */
    -1,   /* 420: of_oxm_ipv6_src */
    -1,   /* 421: of_oxm_ipv6_src_masked */
    -1,   /* 422: of_oxm_metadata */
    -1,   /* 423: of_oxm_metadata_masked */
    -1,   /* 424: of_oxm_mpls_label */
    -1,   /* 425: of_oxm_mpls_label_masked */
    -1,   /* 426: of_oxm_mpls_tc */
    -1,   /* 427: of_oxm_mpls_tc_masked */
    -1,   /* 428: of_oxm_sctp_dst */
    -1,   /* 429: of_oxm_sctp_dst_masked */
    -1,   /* 430: of_oxm_sctp_src */
    -1,   /* 431: of_oxm_sctp_src_masked */
    -1,   /* 432: of_oxm_tcp_dst */
    -1,   /* 433: of_oxm_tcp_dst_masked */
    -1,   /* 434: of_oxm_tcp_src */
    -1,   /* 435: of_oxm_tcp_src_masked */
    -1,   /* 436: of_oxm_udp_dst */
    -1,   /* 437: of_oxm_udp_dst_masked */
    -1,   /* 438: of_oxm_udp_src */
    -1,   /* 439: of_oxm_udp_src_masked */
    -1,   /* 440: of_oxm_vlan_pcp */
    -1,   /* 441: of_oxm_vlan_pcp_masked */
    -1,   /* 442: of_oxm_vlan_vid */
    -1,   /* 443: of_oxm_vlan_vid_masked */
    0,    /* 444: of_packet_queue */
    0,    /* 445: of_port_desc */
    0,    /* 446: of_port_stats_entry */
    0,    /* 447: of_queue_prop */
    -1,   /* 448: of_queue_prop_experimenter */
    0,    /* 449: of_queue_prop_header */
    -1,   /* 450: of_queue_prop_max_rate */
    0,    /* 451: of_queue_prop_min_rate */
    0,    /* 452: of_queue_stats_entry */
    -1,   /* 453: of_table_feature_prop */
    -1,   /* 454: of_table_feature_prop_apply_actions */
    -1,   /* 455: of_table_feature_prop_apply_actions_miss */
    -1,   /* 456: of_table_feature_prop_apply_setfield */
    -1,   /* 457: of_table_feature_prop_apply_setfield_miss */
    -1,   /* 458: of_table_feature_prop_experimenter */
    -1,   /* 459: of_table_feature_prop_experimenter_miss */
    -1,   /* 460: of_table_feature_prop_header */
    -1,   /* 461: of_table_feature_prop_instructions */
    -1,   /* 462: of_table_feature_prop_instructions_miss */
    -1,   /* 463: of_table_feature_prop_match */
    -1,   /* 464: of_table_feature_prop_next_tables */
    -1,   /* 465: of_table_feature_prop_next_tables_miss */
    -1,   /* 466: of_table_feature_prop_wildcards */
    -1,   /* 467: of_table_feature_prop_write_actions */
    -1,   /* 468: of_table_feature_prop_write_actions_miss */
    -1,   /* 469: of_table_feature_prop_write_setfield */
    -1,   /* 470: of_table_feature_prop_write_setfield_miss */
    -1,   /* 471: of_table_features */
    0,    /* 472: of_table_stats_entry */
    -1,   /* 473: of_uint32 */
    -1,   /* 474: of_uint64 */
    -1,   /* 475: of_uint8 */
    0,    /* 476: of_list_action */
    -1,   /* 477: of_list_action_id */
    -1,   /* 478: of_list_bsn_controller_connection */
    -1,   /* 479: of_list_bsn_debug_counter_desc_stats_entry */
    -1,   /* 480: of_list_bsn_debug_counter_stats_entry */
    -1,   /* 481: of_list_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 482: of_list_bsn_gentable_bucket_stats_entry */
    -1,   /* 483: of_list_bsn_gentable_desc_stats_entry */
    -1,   /* 484: of_list_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 485: of_list_bsn_gentable_entry_stats_entry */
    -1,   /* 486: of_list_bsn_gentable_stats_entry */
    0,    /* 487: of_list_bsn_interface */
    -1,   /* 488: of_list_bsn_lacp_stats_entry */
    -1,   /* 489: of_list_bsn_port_counter_stats_entry */
    -1,   /* 490: of_list_bsn_switch_pipeline_stats_entry */
    -1,   /* 491: of_list_bsn_table_checksum_stats_entry */
    -1,   /* 492: of_list_bsn_tlv */
    -1,   /* 493: of_list_bsn_vlan_counter_stats_entry */
    0,    /* 494: of_list_bucket */
    0,    /* 495: of_list_bucket_counter */
    0,    /* 496: of_list_flow_stats_entry */
    0,    /* 497: of_list_group_desc_stats_entry */
    0,    /* 498: of_list_group_stats_entry */
    -1,   /* 499: of_list_hello_elem */
    0,    /* 500: of_list_instruction */
    -1,   /* 501: of_list_instruction_id */
    -1,   /* 502: of_list_meter_band */
    -1,   /* 503: of_list_meter_band_stats */
    -1,   /* 504: of_list_meter_stats */
    -1,   /* 505: of_list_oxm */
    0,    /* 506: of_list_packet_queue */
    0,    /* 507: of_list_port_desc */
    0,    /* 508: of_list_port_stats_entry */
    0,    /* 509: of_list_queue_prop */
    0,    /* 510: of_list_queue_stats_entry */
    -1,   /* 511: of_list_table_feature_prop */
    -1,   /* 512: of_list_table_features */
    0,    /* 513: of_list_table_stats_entry */
    -1,   /* 514: of_list_uint32 */
    -1,   /* 515: of_list_uint64 */
    -1    /* 516: of_list_uint8 */
};

static const int
of_object_extra_len_v3[OF_OBJECT_COUNT] = {
    -1,   /* of_object is not instantiable */
    0,    /* 1: of_aggregate_stats_reply */
    0,    /* 2: of_aggregate_stats_request */
    -1,   /* 3: of_async_get_reply */
    -1,   /* 4: of_async_get_request */
    -1,   /* 5: of_async_set */
    0,    /* 6: of_bad_action_error_msg */
    0,    /* 7: of_bad_instruction_error_msg */
    0,    /* 8: of_bad_match_error_msg */
    0,    /* 9: of_bad_request_error_msg */
    0,    /* 10: of_barrier_reply */
    0,    /* 11: of_barrier_request */
    -1,   /* 12: of_bsn_arp_idle */
    0,    /* 13: of_bsn_bw_clear_data_reply */
    0,    /* 14: of_bsn_bw_clear_data_request */
    0,    /* 15: of_bsn_bw_enable_get_reply */
    0,    /* 16: of_bsn_bw_enable_get_request */
    0,    /* 17: of_bsn_bw_enable_set_reply */
    0,    /* 18: of_bsn_bw_enable_set_request */
    -1,   /* 19: of_bsn_controller_connections_reply */
    -1,   /* 20: of_bsn_controller_connections_request */
    -1,   /* 21: of_bsn_debug_counter_desc_stats_reply */
    -1,   /* 22: of_bsn_debug_counter_desc_stats_request */
    -1,   /* 23: of_bsn_debug_counter_stats_reply */
    -1,   /* 24: of_bsn_debug_counter_stats_request */
    -1,   /* 25: of_bsn_flow_checksum_bucket_stats_reply */
    -1,   /* 26: of_bsn_flow_checksum_bucket_stats_request */
    -1,   /* 27: of_bsn_flow_idle */
    -1,   /* 28: of_bsn_flow_idle_enable_get_reply */
    -1,   /* 29: of_bsn_flow_idle_enable_get_request */
    -1,   /* 30: of_bsn_flow_idle_enable_set_reply */
    -1,   /* 31: of_bsn_flow_idle_enable_set_request */
    -1,   /* 32: of_bsn_gentable_bucket_stats_reply */
    -1,   /* 33: of_bsn_gentable_bucket_stats_request */
    -1,   /* 34: of_bsn_gentable_clear_reply */
    -1,   /* 35: of_bsn_gentable_clear_request */
    -1,   /* 36: of_bsn_gentable_desc_stats_reply */
    -1,   /* 37: of_bsn_gentable_desc_stats_request */
    -1,   /* 38: of_bsn_gentable_entry_add */
    -1,   /* 39: of_bsn_gentable_entry_delete */
    -1,   /* 40: of_bsn_gentable_entry_desc_stats_reply */
    -1,   /* 41: of_bsn_gentable_entry_desc_stats_request */
    -1,   /* 42: of_bsn_gentable_entry_stats_reply */
    -1,   /* 43: of_bsn_gentable_entry_stats_request */
    -1,   /* 44: of_bsn_gentable_set_buckets_size */
    -1,   /* 45: of_bsn_gentable_stats_reply */
    -1,   /* 46: of_bsn_gentable_stats_request */
    0,    /* 47: of_bsn_get_interfaces_reply */
    0,    /* 48: of_bsn_get_interfaces_request */
    -1,   /* 49: of_bsn_get_ip_mask_reply */
    -1,   /* 50: of_bsn_get_ip_mask_request */
    -1,   /* 51: of_bsn_get_l2_table_reply */
    -1,   /* 52: of_bsn_get_l2_table_request */
    0,    /* 53: of_bsn_get_mirroring_reply */
    0,    /* 54: of_bsn_get_mirroring_request */
    -1,   /* 55: of_bsn_get_switch_pipeline_reply */
    -1,   /* 56: of_bsn_get_switch_pipeline_request */
    0,    /* 57: of_bsn_header */
    -1,   /* 58: of_bsn_hybrid_get_reply */
    -1,   /* 59: of_bsn_hybrid_get_request */
    -1,   /* 60: of_bsn_image_desc_stats_reply */
    -1,   /* 61: of_bsn_image_desc_stats_request */
    -1,   /* 62: of_bsn_lacp_convergence_notif */
    -1,   /* 63: of_bsn_lacp_stats_reply */
    -1,   /* 64: of_bsn_lacp_stats_request */
    0,    /* 65: of_bsn_pdu_rx_reply */
    0,    /* 66: of_bsn_pdu_rx_request */
    0,    /* 67: of_bsn_pdu_rx_timeout */
    0,    /* 68: of_bsn_pdu_tx_reply */
    0,    /* 69: of_bsn_pdu_tx_request */
    -1,   /* 70: of_bsn_port_counter_stats_reply */
    -1,   /* 71: of_bsn_port_counter_stats_request */
    -1,   /* 72: of_bsn_role_status */
    -1,   /* 73: of_bsn_set_aux_cxns_reply */
    -1,   /* 74: of_bsn_set_aux_cxns_request */
    -1,   /* 75: of_bsn_set_ip_mask */
    -1,   /* 76: of_bsn_set_l2_table_reply */
    -1,   /* 77: of_bsn_set_l2_table_request */
    -1,   /* 78: of_bsn_set_lacp_reply */
    -1,   /* 79: of_bsn_set_lacp_request */
    0,    /* 80: of_bsn_set_mirroring */
    0,    /* 81: of_bsn_set_pktin_suppression_reply */
    0,    /* 82: of_bsn_set_pktin_suppression_request */
    -1,   /* 83: of_bsn_set_switch_pipeline_reply */
    -1,   /* 84: of_bsn_set_switch_pipeline_request */
    -1,   /* 85: of_bsn_shell_command */
    -1,   /* 86: of_bsn_shell_output */
    -1,   /* 87: of_bsn_shell_status */
    0,    /* 88: of_bsn_stats_reply */
    0,    /* 89: of_bsn_stats_request */
    -1,   /* 90: of_bsn_switch_pipeline_stats_reply */
    -1,   /* 91: of_bsn_switch_pipeline_stats_request */
    -1,   /* 92: of_bsn_table_checksum_stats_reply */
    -1,   /* 93: of_bsn_table_checksum_stats_request */
    -1,   /* 94: of_bsn_table_set_buckets_size */
    -1,   /* 95: of_bsn_time_reply */
    -1,   /* 96: of_bsn_time_request */
    0,    /* 97: of_bsn_virtual_port_create_reply */
    0,    /* 98: of_bsn_virtual_port_create_request */
    0,    /* 99: of_bsn_virtual_port_remove_reply */
    0,    /* 100: of_bsn_virtual_port_remove_request */
    -1,   /* 101: of_bsn_vlan_counter_stats_reply */
    -1,   /* 102: of_bsn_vlan_counter_stats_request */
    0,    /* 103: of_desc_stats_reply */
    0,    /* 104: of_desc_stats_request */
    0,    /* 105: of_echo_reply */
    0,    /* 106: of_echo_request */
    0,    /* 107: of_error_msg */
    0,    /* 108: of_experimenter */
    0,    /* 109: of_experimenter_error_msg */
    0,    /* 110: of_experimenter_stats_reply */
    0,    /* 111: of_experimenter_stats_request */
    0,    /* 112: of_features_reply */
    0,    /* 113: of_features_request */
    0,    /* 114: of_flow_add */
    0,    /* 115: of_flow_delete */
    0,    /* 116: of_flow_delete_strict */
    0,    /* 117: of_flow_mod */
    0,    /* 118: of_flow_mod_failed_error_msg */
    0,    /* 119: of_flow_modify */
    0,    /* 120: of_flow_modify_strict */
    0,    /* 121: of_flow_removed */
    0,    /* 122: of_flow_stats_reply */
    0,    /* 123: of_flow_stats_request */
    0,    /* 124: of_get_config_reply */
    0,    /* 125: of_get_config_request */
    0,    /* 126: of_group_add */
    0,    /* 127: of_group_delete */
    0,    /* 128: of_group_desc_stats_reply */
    0,    /* 129: of_group_desc_stats_request */
    0,    /* 130: of_group_features_stats_reply */
    0,    /* 131: of_group_features_stats_request */
    0,    /* 132: of_group_mod */
    0,    /* 133: of_group_mod_failed_error_msg */
    0,    /* 134: of_group_modify */
    0,    /* 135: of_group_stats_reply */
    0,    /* 136: of_group_stats_request */
    0,    /* 137: of_header */
    0,    /* 138: of_hello */
    0,    /* 139: of_hello_failed_error_msg */
    -1,   /* 140: of_meter_config_stats_reply */
    -1,   /* 141: of_meter_config_stats_request */
    -1,   /* 142: of_meter_features_stats_reply */
    -1,   /* 143: of_meter_features_stats_request */
    -1,   /* 144: of_meter_mod */
    -1,   /* 145: of_meter_mod_failed_error_msg */
    -1,   /* 146: of_meter_stats_reply */
    -1,   /* 147: of_meter_stats_request */
    -1,   /* 148: of_nicira_controller_role_reply */
    -1,   /* 149: of_nicira_controller_role_request */
    0,    /* 150: of_nicira_header */
    2,    /* 151: of_packet_in */
    0,    /* 152: of_packet_out */
    -1,   /* 153: of_port_desc_stats_reply */
    -1,   /* 154: of_port_desc_stats_request */
    0,    /* 155: of_port_mod */
    0,    /* 156: of_port_mod_failed_error_msg */
    0,    /* 157: of_port_stats_reply */
    0,    /* 158: of_port_stats_request */
    0,    /* 159: of_port_status */
    0,    /* 160: of_queue_get_config_reply */
    0,    /* 161: of_queue_get_config_request */
    0,    /* 162: of_queue_op_failed_error_msg */
    0,    /* 163: of_queue_stats_reply */
    0,    /* 164: of_queue_stats_request */
    0,    /* 165: of_role_reply */
    0,    /* 166: of_role_request */
    0,    /* 167: of_role_request_failed_error_msg */
    0,    /* 168: of_set_config */
    0,    /* 169: of_stats_reply */
    0,    /* 170: of_stats_request */
    0,    /* 171: of_switch_config_failed_error_msg */
    -1,   /* 172: of_table_features_failed_error_msg */
    -1,   /* 173: of_table_features_stats_reply */
    -1,   /* 174: of_table_features_stats_request */
    0,    /* 175: of_table_mod */
    0,    /* 176: of_table_mod_failed_error_msg */
    0,    /* 177: of_table_stats_reply */
    0,    /* 178: of_table_stats_request */
    0,    /* 179: of_action */
    0,    /* 180: of_action_bsn */
    0,    /* 181: of_action_bsn_mirror */
    0,    /* 182: of_action_bsn_set_tunnel_dst */
    0,    /* 183: of_action_copy_ttl_in */
    0,    /* 184: of_action_copy_ttl_out */
    0,    /* 185: of_action_dec_mpls_ttl */
    0,    /* 186: of_action_dec_nw_ttl */
    -1,   /* 187: of_action_enqueue */
    0,    /* 188: of_action_experimenter */
    0,    /* 189: of_action_group */
    0,    /* 190: of_action_header */
    -1,   /* 191: of_action_id */
    -1,   /* 192: of_action_id_bsn */
    -1,   /* 193: of_action_id_bsn_mirror */
    -1,   /* 194: of_action_id_bsn_set_tunnel_dst */
    -1,   /* 195: of_action_id_copy_ttl_in */
    -1,   /* 196: of_action_id_copy_ttl_out */
    -1,   /* 197: of_action_id_dec_mpls_ttl */
    -1,   /* 198: of_action_id_dec_nw_ttl */
    -1,   /* 199: of_action_id_experimenter */
    -1,   /* 200: of_action_id_group */
    -1,   /* 201: of_action_id_header */
    -1,   /* 202: of_action_id_nicira */
    -1,   /* 203: of_action_id_nicira_dec_ttl */
    -1,   /* 204: of_action_id_output */
    -1,   /* 205: of_action_id_pop_mpls */
    -1,   /* 206: of_action_id_pop_pbb */
    -1,   /* 207: of_action_id_pop_vlan */
    -1,   /* 208: of_action_id_push_mpls */
    -1,   /* 209: of_action_id_push_pbb */
    -1,   /* 210: of_action_id_push_vlan */
    -1,   /* 211: of_action_id_set_field */
    -1,   /* 212: of_action_id_set_mpls_ttl */
    -1,   /* 213: of_action_id_set_nw_ttl */
    -1,   /* 214: of_action_id_set_queue */
    0,    /* 215: of_action_nicira */
    0,    /* 216: of_action_nicira_dec_ttl */
    0,    /* 217: of_action_output */
    0,    /* 218: of_action_pop_mpls */
    -1,   /* 219: of_action_pop_pbb */
    0,    /* 220: of_action_pop_vlan */
    0,    /* 221: of_action_push_mpls */
    -1,   /* 222: of_action_push_pbb */
    0,    /* 223: of_action_push_vlan */
    -1,   /* 224: of_action_set_dl_dst */
    -1,   /* 225: of_action_set_dl_src */
    0,    /* 226: of_action_set_field */
    -1,   /* 227: of_action_set_mpls_label */
    -1,   /* 228: of_action_set_mpls_tc */
    0,    /* 229: of_action_set_mpls_ttl */
    -1,   /* 230: of_action_set_nw_dst */
    -1,   /* 231: of_action_set_nw_ecn */
    -1,   /* 232: of_action_set_nw_src */
    -1,   /* 233: of_action_set_nw_tos */
    0,    /* 234: of_action_set_nw_ttl */
    0,    /* 235: of_action_set_queue */
    -1,   /* 236: of_action_set_tp_dst */
    -1,   /* 237: of_action_set_tp_src */
    -1,   /* 238: of_action_set_vlan_pcp */
    -1,   /* 239: of_action_set_vlan_vid */
    -1,   /* 240: of_action_strip_vlan */
    -1,   /* 241: of_bsn_controller_connection */
    -1,   /* 242: of_bsn_debug_counter_desc_stats_entry */
    -1,   /* 243: of_bsn_debug_counter_stats_entry */
    -1,   /* 244: of_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 245: of_bsn_gentable_bucket_stats_entry */
    -1,   /* 246: of_bsn_gentable_desc_stats_entry */
    -1,   /* 247: of_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 248: of_bsn_gentable_entry_stats_entry */
    -1,   /* 249: of_bsn_gentable_stats_entry */
    0,    /* 250: of_bsn_interface */
    -1,   /* 251: of_bsn_lacp_stats_entry */
    -1,   /* 252: of_bsn_port_counter_stats_entry */
    -1,   /* 253: of_bsn_switch_pipeline_stats_entry */
    -1,   /* 254: of_bsn_table_checksum_stats_entry */
    -1,   /* 255: of_bsn_tlv */
    -1,   /* 256: of_bsn_tlv_broadcast_query_timeout */
    -1,   /* 257: of_bsn_tlv_circuit_id */
    -1,   /* 258: of_bsn_tlv_header */
    -1,   /* 259: of_bsn_tlv_idle_notification */
    -1,   /* 260: of_bsn_tlv_idle_time */
    -1,   /* 261: of_bsn_tlv_idle_timeout */
    -1,   /* 262: of_bsn_tlv_ipv4 */
    -1,   /* 263: of_bsn_tlv_mac */
    -1,   /* 264: of_bsn_tlv_miss_packets */
    -1,   /* 265: of_bsn_tlv_port */
    -1,   /* 266: of_bsn_tlv_reply_packets */
    -1,   /* 267: of_bsn_tlv_request_packets */
    -1,   /* 268: of_bsn_tlv_rx_packets */
    -1,   /* 269: of_bsn_tlv_tx_packets */
    -1,   /* 270: of_bsn_tlv_udf_anchor */
    -1,   /* 271: of_bsn_tlv_udf_id */
    -1,   /* 272: of_bsn_tlv_udf_length */
    -1,   /* 273: of_bsn_tlv_udf_offset */
    -1,   /* 274: of_bsn_tlv_unicast_query_timeout */
    -1,   /* 275: of_bsn_tlv_vlan_vid */
    -1,   /* 276: of_bsn_tlv_vrf */
    -1,   /* 277: of_bsn_vlan_counter_stats_entry */
    0,    /* 278: of_bsn_vport */
    0,    /* 279: of_bsn_vport_header */
    0,    /* 280: of_bsn_vport_l2gre */
    0,    /* 281: of_bsn_vport_q_in_q */
    0,    /* 282: of_bucket */
    0,    /* 283: of_bucket_counter */
    0,    /* 284: of_flow_stats_entry */
    0,    /* 285: of_group_desc_stats_entry */
    0,    /* 286: of_group_stats_entry */
    -1,   /* 287: of_hello_elem */
    -1,   /* 288: of_hello_elem_header */
    -1,   /* 289: of_hello_elem_versionbitmap */
    0,    /* 290: of_instruction */
    0,    /* 291: of_instruction_apply_actions */
    -1,   /* 292: of_instruction_bsn */
    -1,   /* 293: of_instruction_bsn_arp_offload */
    -1,   /* 294: of_instruction_bsn_deny */
    -1,   /* 295: of_instruction_bsn_dhcp_offload */
    -1,   /* 296: of_instruction_bsn_disable_split_horizon_check */
    -1,   /* 297: of_instruction_bsn_disable_src_mac_check */
    -1,   /* 298: of_instruction_bsn_packet_of_death */
    -1,   /* 299: of_instruction_bsn_permit */
    -1,   /* 300: of_instruction_bsn_prioritize_pdus */
    0,    /* 301: of_instruction_clear_actions */
    0,    /* 302: of_instruction_experimenter */
    0,    /* 303: of_instruction_goto_table */
    0,    /* 304: of_instruction_header */
    -1,   /* 305: of_instruction_id */
    -1,   /* 306: of_instruction_id_apply_actions */
    -1,   /* 307: of_instruction_id_bsn */
    -1,   /* 308: of_instruction_id_bsn_arp_offload */
    -1,   /* 309: of_instruction_id_bsn_deny */
    -1,   /* 310: of_instruction_id_bsn_dhcp_offload */
    -1,   /* 311: of_instruction_id_bsn_disable_split_horizon_check */
    -1,   /* 312: of_instruction_id_bsn_disable_src_mac_check */
    -1,   /* 313: of_instruction_id_bsn_packet_of_death */
    -1,   /* 314: of_instruction_id_bsn_permit */
    -1,   /* 315: of_instruction_id_bsn_prioritize_pdus */
    -1,   /* 316: of_instruction_id_clear_actions */
    -1,   /* 317: of_instruction_id_experimenter */
    -1,   /* 318: of_instruction_id_goto_table */
    -1,   /* 319: of_instruction_id_header */
    -1,   /* 320: of_instruction_id_meter */
    -1,   /* 321: of_instruction_id_write_actions */
    -1,   /* 322: of_instruction_id_write_metadata */
    -1,   /* 323: of_instruction_meter */
    0,    /* 324: of_instruction_write_actions */
    0,    /* 325: of_instruction_write_metadata */
    -1,   /* 326: of_match_v1 */
    -1,   /* 327: of_match_v2 */
    0,    /* 328: of_match_v3 */
    -1,   /* 329: of_meter_band */
    -1,   /* 330: of_meter_band_drop */
    -1,   /* 331: of_meter_band_dscp_remark */
    -1,   /* 332: of_meter_band_experimenter */
    -1,   /* 333: of_meter_band_header */
    -1,   /* 334: of_meter_band_stats */
    -1,   /* 335: of_meter_config */
    -1,   /* 336: of_meter_features */
    -1,   /* 337: of_meter_stats */
    0,    /* 338: of_oxm */
    0,    /* 339: of_oxm_arp_op */
    0,    /* 340: of_oxm_arp_op_masked */
    0,    /* 341: of_oxm_arp_sha */
    0,    /* 342: of_oxm_arp_sha_masked */
    0,    /* 343: of_oxm_arp_spa */
    0,    /* 344: of_oxm_arp_spa_masked */
    0,    /* 345: of_oxm_arp_tha */
    0,    /* 346: of_oxm_arp_tha_masked */
    0,    /* 347: of_oxm_arp_tpa */
    0,    /* 348: of_oxm_arp_tpa_masked */
    0,    /* 349: of_oxm_bsn_egr_port_group_id */
    0,    /* 350: of_oxm_bsn_egr_port_group_id_masked */
    0,    /* 351: of_oxm_bsn_global_vrf_allowed */
    0,    /* 352: of_oxm_bsn_global_vrf_allowed_masked */
    0,    /* 353: of_oxm_bsn_in_ports_128 */
    0,    /* 354: of_oxm_bsn_in_ports_128_masked */
    0,    /* 355: of_oxm_bsn_l3_dst_class_id */
    0,    /* 356: of_oxm_bsn_l3_dst_class_id_masked */
    0,    /* 357: of_oxm_bsn_l3_interface_class_id */
    0,    /* 358: of_oxm_bsn_l3_interface_class_id_masked */
    0,    /* 359: of_oxm_bsn_l3_src_class_id */
    0,    /* 360: of_oxm_bsn_l3_src_class_id_masked */
    0,    /* 361: of_oxm_bsn_lag_id */
    0,    /* 362: of_oxm_bsn_lag_id_masked */
    0,    /* 363: of_oxm_bsn_udf0 */
    0,    /* 364: of_oxm_bsn_udf0_masked */
    0,    /* 365: of_oxm_bsn_udf1 */
    0,    /* 366: of_oxm_bsn_udf1_masked */
    0,    /* 367: of_oxm_bsn_udf2 */
    0,    /* 368: of_oxm_bsn_udf2_masked */
    0,    /* 369: of_oxm_bsn_udf3 */
    0,    /* 370: of_oxm_bsn_udf3_masked */
    0,    /* 371: of_oxm_bsn_udf4 */
    0,    /* 372: of_oxm_bsn_udf4_masked */
    0,    /* 373: of_oxm_bsn_udf5 */
    0,    /* 374: of_oxm_bsn_udf5_masked */
    0,    /* 375: of_oxm_bsn_udf6 */
    0,    /* 376: of_oxm_bsn_udf6_masked */
    0,    /* 377: of_oxm_bsn_udf7 */
    0,    /* 378: of_oxm_bsn_udf7_masked */
    0,    /* 379: of_oxm_bsn_vrf */
    0,    /* 380: of_oxm_bsn_vrf_masked */
    0,    /* 381: of_oxm_eth_dst */
    0,    /* 382: of_oxm_eth_dst_masked */
    0,    /* 383: of_oxm_eth_src */
    0,    /* 384: of_oxm_eth_src_masked */
    0,    /* 385: of_oxm_eth_type */
    0,    /* 386: of_oxm_eth_type_masked */
    0,    /* 387: of_oxm_header */
    0,    /* 388: of_oxm_icmpv4_code */
    0,    /* 389: of_oxm_icmpv4_code_masked */
    0,    /* 390: of_oxm_icmpv4_type */
    0,    /* 391: of_oxm_icmpv4_type_masked */
    0,    /* 392: of_oxm_icmpv6_code */
    0,    /* 393: of_oxm_icmpv6_code_masked */
    0,    /* 394: of_oxm_icmpv6_type */
    0,    /* 395: of_oxm_icmpv6_type_masked */
    0,    /* 396: of_oxm_in_phy_port */
    0,    /* 397: of_oxm_in_phy_port_masked */
    0,    /* 398: of_oxm_in_port */
    0,    /* 399: of_oxm_in_port_masked */
    0,    /* 400: of_oxm_ip_dscp */
    0,    /* 401: of_oxm_ip_dscp_masked */
    0,    /* 402: of_oxm_ip_ecn */
    0,    /* 403: of_oxm_ip_ecn_masked */
    0,    /* 404: of_oxm_ip_proto */
    0,    /* 405: of_oxm_ip_proto_masked */
    0,    /* 406: of_oxm_ipv4_dst */
    0,    /* 407: of_oxm_ipv4_dst_masked */
    0,    /* 408: of_oxm_ipv4_src */
    0,    /* 409: of_oxm_ipv4_src_masked */
    0,    /* 410: of_oxm_ipv6_dst */
    0,    /* 411: of_oxm_ipv6_dst_masked */
    0,    /* 412: of_oxm_ipv6_flabel */
    0,    /* 413: of_oxm_ipv6_flabel_masked */
    0,    /* 414: of_oxm_ipv6_nd_sll */
    0,    /* 415: of_oxm_ipv6_nd_sll_masked */
    0,    /* 416: of_oxm_ipv6_nd_target */
    0,    /* 417: of_oxm_ipv6_nd_target_masked */
    0,    /* 418: of_oxm_ipv6_nd_tll */
    0,    /* 419: of_oxm_ipv6_nd_tll_masked */
    0,    /* 420: of_oxm_ipv6_src */
    0,    /* 421: of_oxm_ipv6_src_masked */
    0,    /* 422: of_oxm_metadata */
    0,    /* 423: of_oxm_metadata_masked */
    0,    /* 424: of_oxm_mpls_label */
    0,    /* 425: of_oxm_mpls_label_masked */
    0,    /* 426: of_oxm_mpls_tc */
    0,    /* 427: of_oxm_mpls_tc_masked */
    0,    /* 428: of_oxm_sctp_dst */
    0,    /* 429: of_oxm_sctp_dst_masked */
    0,    /* 430: of_oxm_sctp_src */
    0,    /* 431: of_oxm_sctp_src_masked */
    0,    /* 432: of_oxm_tcp_dst */
    0,    /* 433: of_oxm_tcp_dst_masked */
    0,    /* 434: of_oxm_tcp_src */
    0,    /* 435: of_oxm_tcp_src_masked */
    0,    /* 436: of_oxm_udp_dst */
    0,    /* 437: of_oxm_udp_dst_masked */
    0,    /* 438: of_oxm_udp_src */
    0,    /* 439: of_oxm_udp_src_masked */
    0,    /* 440: of_oxm_vlan_pcp */
    0,    /* 441: of_oxm_vlan_pcp_masked */
    0,    /* 442: of_oxm_vlan_vid */
    0,    /* 443: of_oxm_vlan_vid_masked */
    0,    /* 444: of_packet_queue */
    0,    /* 445: of_port_desc */
    0,    /* 446: of_port_stats_entry */
    0,    /* 447: of_queue_prop */
    0,    /* 448: of_queue_prop_experimenter */
    0,    /* 449: of_queue_prop_header */
    0,    /* 450: of_queue_prop_max_rate */
    0,    /* 451: of_queue_prop_min_rate */
    0,    /* 452: of_queue_stats_entry */
    -1,   /* 453: of_table_feature_prop */
    -1,   /* 454: of_table_feature_prop_apply_actions */
    -1,   /* 455: of_table_feature_prop_apply_actions_miss */
    -1,   /* 456: of_table_feature_prop_apply_setfield */
    -1,   /* 457: of_table_feature_prop_apply_setfield_miss */
    -1,   /* 458: of_table_feature_prop_experimenter */
    -1,   /* 459: of_table_feature_prop_experimenter_miss */
    -1,   /* 460: of_table_feature_prop_header */
    -1,   /* 461: of_table_feature_prop_instructions */
    -1,   /* 462: of_table_feature_prop_instructions_miss */
    -1,   /* 463: of_table_feature_prop_match */
    -1,   /* 464: of_table_feature_prop_next_tables */
    -1,   /* 465: of_table_feature_prop_next_tables_miss */
    -1,   /* 466: of_table_feature_prop_wildcards */
    -1,   /* 467: of_table_feature_prop_write_actions */
    -1,   /* 468: of_table_feature_prop_write_actions_miss */
    -1,   /* 469: of_table_feature_prop_write_setfield */
    -1,   /* 470: of_table_feature_prop_write_setfield_miss */
    -1,   /* 471: of_table_features */
    0,    /* 472: of_table_stats_entry */
    -1,   /* 473: of_uint32 */
    -1,   /* 474: of_uint64 */
    -1,   /* 475: of_uint8 */
    0,    /* 476: of_list_action */
    -1,   /* 477: of_list_action_id */
    -1,   /* 478: of_list_bsn_controller_connection */
    -1,   /* 479: of_list_bsn_debug_counter_desc_stats_entry */
    -1,   /* 480: of_list_bsn_debug_counter_stats_entry */
    -1,   /* 481: of_list_bsn_flow_checksum_bucket_stats_entry */
    -1,   /* 482: of_list_bsn_gentable_bucket_stats_entry */
    -1,   /* 483: of_list_bsn_gentable_desc_stats_entry */
    -1,   /* 484: of_list_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 485: of_list_bsn_gentable_entry_stats_entry */
    -1,   /* 486: of_list_bsn_gentable_stats_entry */
    0,    /* 487: of_list_bsn_interface */
    -1,   /* 488: of_list_bsn_lacp_stats_entry */
    -1,   /* 489: of_list_bsn_port_counter_stats_entry */
    -1,   /* 490: of_list_bsn_switch_pipeline_stats_entry */
    -1,   /* 491: of_list_bsn_table_checksum_stats_entry */
    -1,   /* 492: of_list_bsn_tlv */
    -1,   /* 493: of_list_bsn_vlan_counter_stats_entry */
    0,    /* 494: of_list_bucket */
    0,    /* 495: of_list_bucket_counter */
    0,    /* 496: of_list_flow_stats_entry */
    0,    /* 497: of_list_group_desc_stats_entry */
    0,    /* 498: of_list_group_stats_entry */
    -1,   /* 499: of_list_hello_elem */
    0,    /* 500: of_list_instruction */
    -1,   /* 501: of_list_instruction_id */
    -1,   /* 502: of_list_meter_band */
    -1,   /* 503: of_list_meter_band_stats */
    -1,   /* 504: of_list_meter_stats */
    0,    /* 505: of_list_oxm */
    0,    /* 506: of_list_packet_queue */
    0,    /* 507: of_list_port_desc */
    0,    /* 508: of_list_port_stats_entry */
    0,    /* 509: of_list_queue_prop */
    0,    /* 510: of_list_queue_stats_entry */
    -1,   /* 511: of_list_table_feature_prop */
    -1,   /* 512: of_list_table_features */
    0,    /* 513: of_list_table_stats_entry */
    -1,   /* 514: of_list_uint32 */
    -1,   /* 515: of_list_uint64 */
    -1    /* 516: of_list_uint8 */
};

static const int
of_object_extra_len_v4[OF_OBJECT_COUNT] = {
    -1,   /* of_object is not instantiable */
    0,    /* 1: of_aggregate_stats_reply */
    0,    /* 2: of_aggregate_stats_request */
    0,    /* 3: of_async_get_reply */
    0,    /* 4: of_async_get_request */
    0,    /* 5: of_async_set */
    0,    /* 6: of_bad_action_error_msg */
    0,    /* 7: of_bad_instruction_error_msg */
    0,    /* 8: of_bad_match_error_msg */
    0,    /* 9: of_bad_request_error_msg */
    0,    /* 10: of_barrier_reply */
    0,    /* 11: of_barrier_request */
    0,    /* 12: of_bsn_arp_idle */
    0,    /* 13: of_bsn_bw_clear_data_reply */
    0,    /* 14: of_bsn_bw_clear_data_request */
    0,    /* 15: of_bsn_bw_enable_get_reply */
    0,    /* 16: of_bsn_bw_enable_get_request */
    0,    /* 17: of_bsn_bw_enable_set_reply */
    0,    /* 18: of_bsn_bw_enable_set_request */
    0,    /* 19: of_bsn_controller_connections_reply */
    0,    /* 20: of_bsn_controller_connections_request */
    0,    /* 21: of_bsn_debug_counter_desc_stats_reply */
    0,    /* 22: of_bsn_debug_counter_desc_stats_request */
    0,    /* 23: of_bsn_debug_counter_stats_reply */
    0,    /* 24: of_bsn_debug_counter_stats_request */
    0,    /* 25: of_bsn_flow_checksum_bucket_stats_reply */
    0,    /* 26: of_bsn_flow_checksum_bucket_stats_request */
    0,    /* 27: of_bsn_flow_idle */
    0,    /* 28: of_bsn_flow_idle_enable_get_reply */
    0,    /* 29: of_bsn_flow_idle_enable_get_request */
    0,    /* 30: of_bsn_flow_idle_enable_set_reply */
    0,    /* 31: of_bsn_flow_idle_enable_set_request */
    0,    /* 32: of_bsn_gentable_bucket_stats_reply */
    0,    /* 33: of_bsn_gentable_bucket_stats_request */
    0,    /* 34: of_bsn_gentable_clear_reply */
    0,    /* 35: of_bsn_gentable_clear_request */
    0,    /* 36: of_bsn_gentable_desc_stats_reply */
    0,    /* 37: of_bsn_gentable_desc_stats_request */
    0,    /* 38: of_bsn_gentable_entry_add */
    0,    /* 39: of_bsn_gentable_entry_delete */
    0,    /* 40: of_bsn_gentable_entry_desc_stats_reply */
    0,    /* 41: of_bsn_gentable_entry_desc_stats_request */
    0,    /* 42: of_bsn_gentable_entry_stats_reply */
    0,    /* 43: of_bsn_gentable_entry_stats_request */
    0,    /* 44: of_bsn_gentable_set_buckets_size */
    0,    /* 45: of_bsn_gentable_stats_reply */
    0,    /* 46: of_bsn_gentable_stats_request */
    0,    /* 47: of_bsn_get_interfaces_reply */
    0,    /* 48: of_bsn_get_interfaces_request */
    -1,   /* 49: of_bsn_get_ip_mask_reply */
    -1,   /* 50: of_bsn_get_ip_mask_request */
    -1,   /* 51: of_bsn_get_l2_table_reply */
    -1,   /* 52: of_bsn_get_l2_table_request */
    0,    /* 53: of_bsn_get_mirroring_reply */
    0,    /* 54: of_bsn_get_mirroring_request */
    0,    /* 55: of_bsn_get_switch_pipeline_reply */
    0,    /* 56: of_bsn_get_switch_pipeline_request */
    0,    /* 57: of_bsn_header */
    -1,   /* 58: of_bsn_hybrid_get_reply */
    -1,   /* 59: of_bsn_hybrid_get_request */
    0,    /* 60: of_bsn_image_desc_stats_reply */
    0,    /* 61: of_bsn_image_desc_stats_request */
    0,    /* 62: of_bsn_lacp_convergence_notif */
    0,    /* 63: of_bsn_lacp_stats_reply */
    0,    /* 64: of_bsn_lacp_stats_request */
    0,    /* 65: of_bsn_pdu_rx_reply */
    0,    /* 66: of_bsn_pdu_rx_request */
    0,    /* 67: of_bsn_pdu_rx_timeout */
    0,    /* 68: of_bsn_pdu_tx_reply */
    0,    /* 69: of_bsn_pdu_tx_request */
    0,    /* 70: of_bsn_port_counter_stats_reply */
    0,    /* 71: of_bsn_port_counter_stats_request */
    0,    /* 72: of_bsn_role_status */
    0,    /* 73: of_bsn_set_aux_cxns_reply */
    0,    /* 74: of_bsn_set_aux_cxns_request */
    -1,   /* 75: of_bsn_set_ip_mask */
    -1,   /* 76: of_bsn_set_l2_table_reply */
    -1,   /* 77: of_bsn_set_l2_table_request */
    0,    /* 78: of_bsn_set_lacp_reply */
    0,    /* 79: of_bsn_set_lacp_request */
    0,    /* 80: of_bsn_set_mirroring */
    0,    /* 81: of_bsn_set_pktin_suppression_reply */
    0,    /* 82: of_bsn_set_pktin_suppression_request */
    0,    /* 83: of_bsn_set_switch_pipeline_reply */
    0,    /* 84: of_bsn_set_switch_pipeline_request */
    -1,   /* 85: of_bsn_shell_command */
    -1,   /* 86: of_bsn_shell_output */
    -1,   /* 87: of_bsn_shell_status */
    0,    /* 88: of_bsn_stats_reply */
    0,    /* 89: of_bsn_stats_request */
    0,    /* 90: of_bsn_switch_pipeline_stats_reply */
    0,    /* 91: of_bsn_switch_pipeline_stats_request */
    0,    /* 92: of_bsn_table_checksum_stats_reply */
    0,    /* 93: of_bsn_table_checksum_stats_request */
    0,    /* 94: of_bsn_table_set_buckets_size */
    0,    /* 95: of_bsn_time_reply */
    0,    /* 96: of_bsn_time_request */
    0,    /* 97: of_bsn_virtual_port_create_reply */
    0,    /* 98: of_bsn_virtual_port_create_request */
    0,    /* 99: of_bsn_virtual_port_remove_reply */
    0,    /* 100: of_bsn_virtual_port_remove_request */
    0,    /* 101: of_bsn_vlan_counter_stats_reply */
    0,    /* 102: of_bsn_vlan_counter_stats_request */
    0,    /* 103: of_desc_stats_reply */
    0,    /* 104: of_desc_stats_request */
    0,    /* 105: of_echo_reply */
    0,    /* 106: of_echo_request */
    0,    /* 107: of_error_msg */
    0,    /* 108: of_experimenter */
    0,    /* 109: of_experimenter_error_msg */
    0,    /* 110: of_experimenter_stats_reply */
    0,    /* 111: of_experimenter_stats_request */
    0,    /* 112: of_features_reply */
    0,    /* 113: of_features_request */
    0,    /* 114: of_flow_add */
    0,    /* 115: of_flow_delete */
    0,    /* 116: of_flow_delete_strict */
    0,    /* 117: of_flow_mod */
    0,    /* 118: of_flow_mod_failed_error_msg */
    0,    /* 119: of_flow_modify */
    0,    /* 120: of_flow_modify_strict */
    0,    /* 121: of_flow_removed */
    0,    /* 122: of_flow_stats_reply */
    0,    /* 123: of_flow_stats_request */
    0,    /* 124: of_get_config_reply */
    0,    /* 125: of_get_config_request */
    0,    /* 126: of_group_add */
    0,    /* 127: of_group_delete */
    0,    /* 128: of_group_desc_stats_reply */
    0,    /* 129: of_group_desc_stats_request */
    0,    /* 130: of_group_features_stats_reply */
    0,    /* 131: of_group_features_stats_request */
    0,    /* 132: of_group_mod */
    0,    /* 133: of_group_mod_failed_error_msg */
    0,    /* 134: of_group_modify */
    0,    /* 135: of_group_stats_reply */
    0,    /* 136: of_group_stats_request */
    0,    /* 137: of_header */
    0,    /* 138: of_hello */
    0,    /* 139: of_hello_failed_error_msg */
    0,    /* 140: of_meter_config_stats_reply */
    0,    /* 141: of_meter_config_stats_request */
    0,    /* 142: of_meter_features_stats_reply */
    0,    /* 143: of_meter_features_stats_request */
    0,    /* 144: of_meter_mod */
    0,    /* 145: of_meter_mod_failed_error_msg */
    0,    /* 146: of_meter_stats_reply */
    0,    /* 147: of_meter_stats_request */
    -1,   /* 148: of_nicira_controller_role_reply */
    -1,   /* 149: of_nicira_controller_role_request */
    0,    /* 150: of_nicira_header */
    2,    /* 151: of_packet_in */
    0,    /* 152: of_packet_out */
    0,    /* 153: of_port_desc_stats_reply */
    0,    /* 154: of_port_desc_stats_request */
    0,    /* 155: of_port_mod */
    0,    /* 156: of_port_mod_failed_error_msg */
    0,    /* 157: of_port_stats_reply */
    0,    /* 158: of_port_stats_request */
    0,    /* 159: of_port_status */
    0,    /* 160: of_queue_get_config_reply */
    0,    /* 161: of_queue_get_config_request */
    0,    /* 162: of_queue_op_failed_error_msg */
    0,    /* 163: of_queue_stats_reply */
    0,    /* 164: of_queue_stats_request */
    0,    /* 165: of_role_reply */
    0,    /* 166: of_role_request */
    0,    /* 167: of_role_request_failed_error_msg */
    0,    /* 168: of_set_config */
    0,    /* 169: of_stats_reply */
    0,    /* 170: of_stats_request */
    0,    /* 171: of_switch_config_failed_error_msg */
    0,    /* 172: of_table_features_failed_error_msg */
    0,    /* 173: of_table_features_stats_reply */
    0,    /* 174: of_table_features_stats_request */
    0,    /* 175: of_table_mod */
    0,    /* 176: of_table_mod_failed_error_msg */
    0,    /* 177: of_table_stats_reply */
    0,    /* 178: of_table_stats_request */
    0,    /* 179: of_action */
    0,    /* 180: of_action_bsn */
    0,    /* 181: of_action_bsn_mirror */
    0,    /* 182: of_action_bsn_set_tunnel_dst */
    0,    /* 183: of_action_copy_ttl_in */
    0,    /* 184: of_action_copy_ttl_out */
    0,    /* 185: of_action_dec_mpls_ttl */
    0,    /* 186: of_action_dec_nw_ttl */
    -1,   /* 187: of_action_enqueue */
    0,    /* 188: of_action_experimenter */
    0,    /* 189: of_action_group */
    0,    /* 190: of_action_header */
    0,    /* 191: of_action_id */
    0,    /* 192: of_action_id_bsn */
    0,    /* 193: of_action_id_bsn_mirror */
    0,    /* 194: of_action_id_bsn_set_tunnel_dst */
    0,    /* 195: of_action_id_copy_ttl_in */
    0,    /* 196: of_action_id_copy_ttl_out */
    0,    /* 197: of_action_id_dec_mpls_ttl */
    0,    /* 198: of_action_id_dec_nw_ttl */
    0,    /* 199: of_action_id_experimenter */
    0,    /* 200: of_action_id_group */
    0,    /* 201: of_action_id_header */
    0,    /* 202: of_action_id_nicira */
    0,    /* 203: of_action_id_nicira_dec_ttl */
    0,    /* 204: of_action_id_output */
    0,    /* 205: of_action_id_pop_mpls */
    0,    /* 206: of_action_id_pop_pbb */
    0,    /* 207: of_action_id_pop_vlan */
    0,    /* 208: of_action_id_push_mpls */
    0,    /* 209: of_action_id_push_pbb */
    0,    /* 210: of_action_id_push_vlan */
    0,    /* 211: of_action_id_set_field */
    0,    /* 212: of_action_id_set_mpls_ttl */
    0,    /* 213: of_action_id_set_nw_ttl */
    0,    /* 214: of_action_id_set_queue */
    0,    /* 215: of_action_nicira */
    0,    /* 216: of_action_nicira_dec_ttl */
    0,    /* 217: of_action_output */
    0,    /* 218: of_action_pop_mpls */
    0,    /* 219: of_action_pop_pbb */
    0,    /* 220: of_action_pop_vlan */
    0,    /* 221: of_action_push_mpls */
    0,    /* 222: of_action_push_pbb */
    0,    /* 223: of_action_push_vlan */
    -1,   /* 224: of_action_set_dl_dst */
    -1,   /* 225: of_action_set_dl_src */
    0,    /* 226: of_action_set_field */
    -1,   /* 227: of_action_set_mpls_label */
    -1,   /* 228: of_action_set_mpls_tc */
    0,    /* 229: of_action_set_mpls_ttl */
    -1,   /* 230: of_action_set_nw_dst */
    -1,   /* 231: of_action_set_nw_ecn */
    -1,   /* 232: of_action_set_nw_src */
    -1,   /* 233: of_action_set_nw_tos */
    0,    /* 234: of_action_set_nw_ttl */
    0,    /* 235: of_action_set_queue */
    -1,   /* 236: of_action_set_tp_dst */
    -1,   /* 237: of_action_set_tp_src */
    -1,   /* 238: of_action_set_vlan_pcp */
    -1,   /* 239: of_action_set_vlan_vid */
    -1,   /* 240: of_action_strip_vlan */
    0,    /* 241: of_bsn_controller_connection */
    0,    /* 242: of_bsn_debug_counter_desc_stats_entry */
    0,    /* 243: of_bsn_debug_counter_stats_entry */
    0,    /* 244: of_bsn_flow_checksum_bucket_stats_entry */
    0,    /* 245: of_bsn_gentable_bucket_stats_entry */
    0,    /* 246: of_bsn_gentable_desc_stats_entry */
    0,    /* 247: of_bsn_gentable_entry_desc_stats_entry */
    0,    /* 248: of_bsn_gentable_entry_stats_entry */
    0,    /* 249: of_bsn_gentable_stats_entry */
    0,    /* 250: of_bsn_interface */
    0,    /* 251: of_bsn_lacp_stats_entry */
    0,    /* 252: of_bsn_port_counter_stats_entry */
    0,    /* 253: of_bsn_switch_pipeline_stats_entry */
    0,    /* 254: of_bsn_table_checksum_stats_entry */
    0,    /* 255: of_bsn_tlv */
    0,    /* 256: of_bsn_tlv_broadcast_query_timeout */
    0,    /* 257: of_bsn_tlv_circuit_id */
    0,    /* 258: of_bsn_tlv_header */
    0,    /* 259: of_bsn_tlv_idle_notification */
    0,    /* 260: of_bsn_tlv_idle_time */
    0,    /* 261: of_bsn_tlv_idle_timeout */
    0,    /* 262: of_bsn_tlv_ipv4 */
    0,    /* 263: of_bsn_tlv_mac */
    0,    /* 264: of_bsn_tlv_miss_packets */
    0,    /* 265: of_bsn_tlv_port */
    0,    /* 266: of_bsn_tlv_reply_packets */
    0,    /* 267: of_bsn_tlv_request_packets */
    0,    /* 268: of_bsn_tlv_rx_packets */
    0,    /* 269: of_bsn_tlv_tx_packets */
    0,    /* 270: of_bsn_tlv_udf_anchor */
    0,    /* 271: of_bsn_tlv_udf_id */
    0,    /* 272: of_bsn_tlv_udf_length */
    0,    /* 273: of_bsn_tlv_udf_offset */
    0,    /* 274: of_bsn_tlv_unicast_query_timeout */
    0,    /* 275: of_bsn_tlv_vlan_vid */
    0,    /* 276: of_bsn_tlv_vrf */
    0,    /* 277: of_bsn_vlan_counter_stats_entry */
    0,    /* 278: of_bsn_vport */
    0,    /* 279: of_bsn_vport_header */
    0,    /* 280: of_bsn_vport_l2gre */
    0,    /* 281: of_bsn_vport_q_in_q */
    0,    /* 282: of_bucket */
    0,    /* 283: of_bucket_counter */
    0,    /* 284: of_flow_stats_entry */
    0,    /* 285: of_group_desc_stats_entry */
    0,    /* 286: of_group_stats_entry */
    0,    /* 287: of_hello_elem */
    0,    /* 288: of_hello_elem_header */
    0,    /* 289: of_hello_elem_versionbitmap */
    0,    /* 290: of_instruction */
    0,    /* 291: of_instruction_apply_actions */
    0,    /* 292: of_instruction_bsn */
    0,    /* 293: of_instruction_bsn_arp_offload */
    0,    /* 294: of_instruction_bsn_deny */
    0,    /* 295: of_instruction_bsn_dhcp_offload */
    0,    /* 296: of_instruction_bsn_disable_split_horizon_check */
    0,    /* 297: of_instruction_bsn_disable_src_mac_check */
    0,    /* 298: of_instruction_bsn_packet_of_death */
    0,    /* 299: of_instruction_bsn_permit */
    0,    /* 300: of_instruction_bsn_prioritize_pdus */
    0,    /* 301: of_instruction_clear_actions */
    0,    /* 302: of_instruction_experimenter */
    0,    /* 303: of_instruction_goto_table */
    0,    /* 304: of_instruction_header */
    0,    /* 305: of_instruction_id */
    0,    /* 306: of_instruction_id_apply_actions */
    0,    /* 307: of_instruction_id_bsn */
    0,    /* 308: of_instruction_id_bsn_arp_offload */
    0,    /* 309: of_instruction_id_bsn_deny */
    0,    /* 310: of_instruction_id_bsn_dhcp_offload */
    0,    /* 311: of_instruction_id_bsn_disable_split_horizon_check */
    0,    /* 312: of_instruction_id_bsn_disable_src_mac_check */
    0,    /* 313: of_instruction_id_bsn_packet_of_death */
    0,    /* 314: of_instruction_id_bsn_permit */
    0,    /* 315: of_instruction_id_bsn_prioritize_pdus */
    0,    /* 316: of_instruction_id_clear_actions */
    0,    /* 317: of_instruction_id_experimenter */
    0,    /* 318: of_instruction_id_goto_table */
    0,    /* 319: of_instruction_id_header */
    0,    /* 320: of_instruction_id_meter */
    0,    /* 321: of_instruction_id_write_actions */
    0,    /* 322: of_instruction_id_write_metadata */
    0,    /* 323: of_instruction_meter */
    0,    /* 324: of_instruction_write_actions */
    0,    /* 325: of_instruction_write_metadata */
    -1,   /* 326: of_match_v1 */
    -1,   /* 327: of_match_v2 */
    0,    /* 328: of_match_v3 */
    0,    /* 329: of_meter_band */
    0,    /* 330: of_meter_band_drop */
    0,    /* 331: of_meter_band_dscp_remark */
    0,    /* 332: of_meter_band_experimenter */
    0,    /* 333: of_meter_band_header */
    0,    /* 334: of_meter_band_stats */
    0,    /* 335: of_meter_config */
    0,    /* 336: of_meter_features */
    0,    /* 337: of_meter_stats */
    0,    /* 338: of_oxm */
    0,    /* 339: of_oxm_arp_op */
    0,    /* 340: of_oxm_arp_op_masked */
    0,    /* 341: of_oxm_arp_sha */
    0,    /* 342: of_oxm_arp_sha_masked */
    0,    /* 343: of_oxm_arp_spa */
    0,    /* 344: of_oxm_arp_spa_masked */
    0,    /* 345: of_oxm_arp_tha */
    0,    /* 346: of_oxm_arp_tha_masked */
    0,    /* 347: of_oxm_arp_tpa */
    0,    /* 348: of_oxm_arp_tpa_masked */
    0,    /* 349: of_oxm_bsn_egr_port_group_id */
    0,    /* 350: of_oxm_bsn_egr_port_group_id_masked */
    0,    /* 351: of_oxm_bsn_global_vrf_allowed */
    0,    /* 352: of_oxm_bsn_global_vrf_allowed_masked */
    0,    /* 353: of_oxm_bsn_in_ports_128 */
    0,    /* 354: of_oxm_bsn_in_ports_128_masked */
    0,    /* 355: of_oxm_bsn_l3_dst_class_id */
    0,    /* 356: of_oxm_bsn_l3_dst_class_id_masked */
    0,    /* 357: of_oxm_bsn_l3_interface_class_id */
    0,    /* 358: of_oxm_bsn_l3_interface_class_id_masked */
    0,    /* 359: of_oxm_bsn_l3_src_class_id */
    0,    /* 360: of_oxm_bsn_l3_src_class_id_masked */
    0,    /* 361: of_oxm_bsn_lag_id */
    0,    /* 362: of_oxm_bsn_lag_id_masked */
    0,    /* 363: of_oxm_bsn_udf0 */
    0,    /* 364: of_oxm_bsn_udf0_masked */
    0,    /* 365: of_oxm_bsn_udf1 */
    0,    /* 366: of_oxm_bsn_udf1_masked */
    0,    /* 367: of_oxm_bsn_udf2 */
    0,    /* 368: of_oxm_bsn_udf2_masked */
    0,    /* 369: of_oxm_bsn_udf3 */
    0,    /* 370: of_oxm_bsn_udf3_masked */
    0,    /* 371: of_oxm_bsn_udf4 */
    0,    /* 372: of_oxm_bsn_udf4_masked */
    0,    /* 373: of_oxm_bsn_udf5 */
    0,    /* 374: of_oxm_bsn_udf5_masked */
    0,    /* 375: of_oxm_bsn_udf6 */
    0,    /* 376: of_oxm_bsn_udf6_masked */
    0,    /* 377: of_oxm_bsn_udf7 */
    0,    /* 378: of_oxm_bsn_udf7_masked */
    0,    /* 379: of_oxm_bsn_vrf */
    0,    /* 380: of_oxm_bsn_vrf_masked */
    0,    /* 381: of_oxm_eth_dst */
    0,    /* 382: of_oxm_eth_dst_masked */
    0,    /* 383: of_oxm_eth_src */
    0,    /* 384: of_oxm_eth_src_masked */
    0,    /* 385: of_oxm_eth_type */
    0,    /* 386: of_oxm_eth_type_masked */
    0,    /* 387: of_oxm_header */
    0,    /* 388: of_oxm_icmpv4_code */
    0,    /* 389: of_oxm_icmpv4_code_masked */
    0,    /* 390: of_oxm_icmpv4_type */
    0,    /* 391: of_oxm_icmpv4_type_masked */
    0,    /* 392: of_oxm_icmpv6_code */
    0,    /* 393: of_oxm_icmpv6_code_masked */
    0,    /* 394: of_oxm_icmpv6_type */
    0,    /* 395: of_oxm_icmpv6_type_masked */
    0,    /* 396: of_oxm_in_phy_port */
    0,    /* 397: of_oxm_in_phy_port_masked */
    0,    /* 398: of_oxm_in_port */
    0,    /* 399: of_oxm_in_port_masked */
    0,    /* 400: of_oxm_ip_dscp */
    0,    /* 401: of_oxm_ip_dscp_masked */
    0,    /* 402: of_oxm_ip_ecn */
    0,    /* 403: of_oxm_ip_ecn_masked */
    0,    /* 404: of_oxm_ip_proto */
    0,    /* 405: of_oxm_ip_proto_masked */
    0,    /* 406: of_oxm_ipv4_dst */
    0,    /* 407: of_oxm_ipv4_dst_masked */
    0,    /* 408: of_oxm_ipv4_src */
    0,    /* 409: of_oxm_ipv4_src_masked */
    0,    /* 410: of_oxm_ipv6_dst */
    0,    /* 411: of_oxm_ipv6_dst_masked */
    0,    /* 412: of_oxm_ipv6_flabel */
    0,    /* 413: of_oxm_ipv6_flabel_masked */
    0,    /* 414: of_oxm_ipv6_nd_sll */
    0,    /* 415: of_oxm_ipv6_nd_sll_masked */
    0,    /* 416: of_oxm_ipv6_nd_target */
    0,    /* 417: of_oxm_ipv6_nd_target_masked */
    0,    /* 418: of_oxm_ipv6_nd_tll */
    0,    /* 419: of_oxm_ipv6_nd_tll_masked */
    0,    /* 420: of_oxm_ipv6_src */
    0,    /* 421: of_oxm_ipv6_src_masked */
    0,    /* 422: of_oxm_metadata */
    0,    /* 423: of_oxm_metadata_masked */
    0,    /* 424: of_oxm_mpls_label */
    0,    /* 425: of_oxm_mpls_label_masked */
    0,    /* 426: of_oxm_mpls_tc */
    0,    /* 427: of_oxm_mpls_tc_masked */
    0,    /* 428: of_oxm_sctp_dst */
    0,    /* 429: of_oxm_sctp_dst_masked */
    0,    /* 430: of_oxm_sctp_src */
    0,    /* 431: of_oxm_sctp_src_masked */
    0,    /* 432: of_oxm_tcp_dst */
    0,    /* 433: of_oxm_tcp_dst_masked */
    0,    /* 434: of_oxm_tcp_src */
    0,    /* 435: of_oxm_tcp_src_masked */
    0,    /* 436: of_oxm_udp_dst */
    0,    /* 437: of_oxm_udp_dst_masked */
    0,    /* 438: of_oxm_udp_src */
    0,    /* 439: of_oxm_udp_src_masked */
    0,    /* 440: of_oxm_vlan_pcp */
    0,    /* 441: of_oxm_vlan_pcp_masked */
    0,    /* 442: of_oxm_vlan_vid */
    0,    /* 443: of_oxm_vlan_vid_masked */
    0,    /* 444: of_packet_queue */
    0,    /* 445: of_port_desc */
    0,    /* 446: of_port_stats_entry */
    0,    /* 447: of_queue_prop */
    0,    /* 448: of_queue_prop_experimenter */
    0,    /* 449: of_queue_prop_header */
    0,    /* 450: of_queue_prop_max_rate */
    0,    /* 451: of_queue_prop_min_rate */
    0,    /* 452: of_queue_stats_entry */
    0,    /* 453: of_table_feature_prop */
    0,    /* 454: of_table_feature_prop_apply_actions */
    0,    /* 455: of_table_feature_prop_apply_actions_miss */
    0,    /* 456: of_table_feature_prop_apply_setfield */
    0,    /* 457: of_table_feature_prop_apply_setfield_miss */
    0,    /* 458: of_table_feature_prop_experimenter */
    0,    /* 459: of_table_feature_prop_experimenter_miss */
    0,    /* 460: of_table_feature_prop_header */
    0,    /* 461: of_table_feature_prop_instructions */
    0,    /* 462: of_table_feature_prop_instructions_miss */
    0,    /* 463: of_table_feature_prop_match */
    0,    /* 464: of_table_feature_prop_next_tables */
    0,    /* 465: of_table_feature_prop_next_tables_miss */
    0,    /* 466: of_table_feature_prop_wildcards */
    0,    /* 467: of_table_feature_prop_write_actions */
    0,    /* 468: of_table_feature_prop_write_actions_miss */
    0,    /* 469: of_table_feature_prop_write_setfield */
    0,    /* 470: of_table_feature_prop_write_setfield_miss */
    0,    /* 471: of_table_features */
    0,    /* 472: of_table_stats_entry */
    0,    /* 473: of_uint32 */
    0,    /* 474: of_uint64 */
    0,    /* 475: of_uint8 */
    0,    /* 476: of_list_action */
    0,    /* 477: of_list_action_id */
    0,    /* 478: of_list_bsn_controller_connection */
    0,    /* 479: of_list_bsn_debug_counter_desc_stats_entry */
    0,    /* 480: of_list_bsn_debug_counter_stats_entry */
    0,    /* 481: of_list_bsn_flow_checksum_bucket_stats_entry */
    0,    /* 482: of_list_bsn_gentable_bucket_stats_entry */
    0,    /* 483: of_list_bsn_gentable_desc_stats_entry */
    0,    /* 484: of_list_bsn_gentable_entry_desc_stats_entry */
    0,    /* 485: of_list_bsn_gentable_entry_stats_entry */
    0,    /* 486: of_list_bsn_gentable_stats_entry */
    0,    /* 487: of_list_bsn_interface */
    0,    /* 488: of_list_bsn_lacp_stats_entry */
    0,    /* 489: of_list_bsn_port_counter_stats_entry */
    0,    /* 490: of_list_bsn_switch_pipeline_stats_entry */
    0,    /* 491: of_list_bsn_table_checksum_stats_entry */
    0,    /* 492: of_list_bsn_tlv */
    0,    /* 493: of_list_bsn_vlan_counter_stats_entry */
    0,    /* 494: of_list_bucket */
    0,    /* 495: of_list_bucket_counter */
    0,    /* 496: of_list_flow_stats_entry */
    0,    /* 497: of_list_group_desc_stats_entry */
    0,    /* 498: of_list_group_stats_entry */
    0,    /* 499: of_list_hello_elem */
    0,    /* 500: of_list_instruction */
    0,    /* 501: of_list_instruction_id */
    0,    /* 502: of_list_meter_band */
    0,    /* 503: of_list_meter_band_stats */
    0,    /* 504: of_list_meter_stats */
    0,    /* 505: of_list_oxm */
    0,    /* 506: of_list_packet_queue */
    0,    /* 507: of_list_port_desc */
    0,    /* 508: of_list_port_stats_entry */
    0,    /* 509: of_list_queue_prop */
    0,    /* 510: of_list_queue_stats_entry */
    0,    /* 511: of_list_table_feature_prop */
    0,    /* 512: of_list_table_features */
    0,    /* 513: of_list_table_stats_entry */
    0,    /* 514: of_list_uint32 */
    0,    /* 515: of_list_uint64 */
    0     /* 516: of_list_uint8 */
};

/**
 * Unified map of extra length part of each object
 */
const int *const of_object_extra_len[OF_VERSION_ARRAY_MAX] = {
    NULL,
    of_object_extra_len_v1,
    of_object_extra_len_v2,
    of_object_extra_len_v3,
    of_object_extra_len_v4,

};


/****************************************************************
 * Top level OpenFlow message length functions
 ****************************************************************/

/**
 * Get the length of a message object as reported on the wire
 * @param obj The object to check
 * @param bytes (out) Where the length is stored
 * @returns OF_ERROR_ code
 */
void
of_object_message_wire_length_get(of_object_t *obj, int *bytes)
{
    LOCI_ASSERT(OF_OBJECT_TO_WBUF(obj) != NULL);
    // LOCI_ASSERT(obj is message)
    *bytes = of_message_length_get(OF_OBJECT_TO_MESSAGE(obj));
}

/**
 * Set the length of a message object as reported on the wire
 * @param obj The object to check
 * @param bytes The new length of the object
 * @returns OF_ERROR_ code
 */
void
of_object_message_wire_length_set(of_object_t *obj, int bytes)
{
    LOCI_ASSERT(OF_OBJECT_TO_WBUF(obj) != NULL);
    // LOCI_ASSERT(obj is message)
    of_message_length_set(OF_OBJECT_TO_MESSAGE(obj), bytes);
}

/****************************************************************
 * TLV16 type/length functions
 ****************************************************************/

/**
 * Many objects are TLVs and use uint16 for the type and length values
 * stored on the wire at the beginning of the buffer.
 */
#define TLV16_WIRE_TYPE_OFFSET 0
#define TLV16_WIRE_LENGTH_OFFSET 2

/**
 * Get the length field from the wire for a standard TLV
 * object that uses uint16 for both type and length.
 * @param obj The object being referenced
 * @param bytes (out) Where to store the length
 */

void
of_tlv16_wire_length_get(of_object_t *obj, int *bytes)
{
    uint16_t val16;
    of_wire_buffer_t *wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    of_wire_buffer_u16_get(wbuf, 
           OF_OBJECT_ABSOLUTE_OFFSET(obj, TLV16_WIRE_LENGTH_OFFSET), &val16);
    *bytes = val16;
}

/**
 * Set the length field in the wire buffer for a standard TLV
 * object that uses uint16 for both type and length.
 * @param obj The object being referenced
 * @param bytes The length value to use
 */

void
of_tlv16_wire_length_set(of_object_t *obj, int bytes)
{
    of_wire_buffer_t *wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    of_wire_buffer_u16_set(wbuf, 
        OF_OBJECT_ABSOLUTE_OFFSET(obj, TLV16_WIRE_LENGTH_OFFSET), bytes);
}


/****************************************************************
 * OXM type/length functions.
 ****************************************************************/

/* Where does the OXM type-length header lie in the buffer */
#define OXM_HDR_OFFSET 0

/**
 * Get the OXM header (type-length fields) from the wire buffer
 * associated with an OXM object
 *
 * Will return if error; set hdr to the OXM header
 */

#define _GET_OXM_TYPE_LEN(obj, tl_p, wbuf) do {                         \
        wbuf = OF_OBJECT_TO_WBUF(obj);                                  \
        LOCI_ASSERT(wbuf != NULL);                                           \
        of_wire_buffer_u32_get(wbuf,                                    \
            OF_OBJECT_ABSOLUTE_OFFSET(obj, OXM_HDR_OFFSET), (tl_p));    \
    } while (0)

#define _SET_OXM_TYPE_LEN(obj, tl_p, wbuf) do {                         \
        wbuf = OF_OBJECT_TO_WBUF(obj);                                  \
        LOCI_ASSERT(wbuf != NULL);                                           \
        of_wire_buffer_u32_set(wbuf,                                    \
            OF_OBJECT_ABSOLUTE_OFFSET(obj, OXM_HDR_OFFSET), (tl_p));    \
    } while (0)

/**
 * Get the length of an OXM object from the wire buffer
 * @param obj The object whose wire buffer is an OXM type
 * @param bytes (out) Where length is stored 
 */

void
of_oxm_wire_length_get(of_object_t *obj, int *bytes)
{
    uint32_t type_len;
    of_wire_buffer_t *wbuf;

    _GET_OXM_TYPE_LEN(obj, &type_len, wbuf);
    *bytes = OF_OXM_LENGTH_GET(type_len);
}

#define OF_U16_LEN_LENGTH_OFFSET 0

/**
 * Get the wire length for an object with a uint16 length as first member
 * @param obj The object being referenced
 * @param bytes Pointer to location to store length
 */
void
of_u16_len_wire_length_get(of_object_t *obj, int *bytes)
{
    of_wire_buffer_t *wbuf = OF_OBJECT_TO_WBUF(obj);
    uint16_t u16;

    LOCI_ASSERT(wbuf != NULL);

    of_wire_buffer_u16_get(wbuf, 
           OF_OBJECT_ABSOLUTE_OFFSET(obj, OF_U16_LEN_LENGTH_OFFSET),
           &u16);

    *bytes = u16;
}

/**
 * Set the wire length for an object with a uint16 length as first member
 * @param obj The object being referenced
 * @param bytes The length of the object
 */

void
of_u16_len_wire_length_set(of_object_t *obj, int bytes)
{
    of_wire_buffer_t *wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* LOCI_ASSERT(obj is u16-len entry) */

    of_wire_buffer_u16_set(wbuf, 
           OF_OBJECT_ABSOLUTE_OFFSET(obj, OF_U16_LEN_LENGTH_OFFSET),
           bytes);
}


#define OF_PACKET_QUEUE_LENGTH_OFFSET(ver) \
    (((ver) >= OF_VERSION_1_2) ? 8 : 4)

/**
 * Get the wire length for a packet queue object
 * @param obj The object being referenced
 * @param bytes Pointer to location to store length
 *
 * The length is a uint16 at the offset indicated above
 */
void
of_packet_queue_wire_length_get(of_object_t *obj, int *bytes)
{
    of_wire_buffer_t *wbuf = OF_OBJECT_TO_WBUF(obj);
    uint16_t u16;
    int offset;

    LOCI_ASSERT(wbuf != NULL);

    /* LOCI_ASSERT(obj is packet queue obj) */
    offset = OF_PACKET_QUEUE_LENGTH_OFFSET(obj->version);
    of_wire_buffer_u16_get(wbuf, OF_OBJECT_ABSOLUTE_OFFSET(obj, offset),
                           &u16);

    *bytes = u16;
}

/**
 * Set the wire length for a 1.2 packet queue object
 * @param obj The object being referenced
 * @param bytes The length of the object
 *
 * The length is a uint16 at the offset indicated above
 */

void
of_packet_queue_wire_length_set(of_object_t *obj, int bytes)
{
    of_wire_buffer_t *wbuf = OF_OBJECT_TO_WBUF(obj);
    int offset;

    LOCI_ASSERT(wbuf != NULL);

    /* LOCI_ASSERT(obj is packet queue obj) */
    offset = OF_PACKET_QUEUE_LENGTH_OFFSET(obj->version);
    of_wire_buffer_u16_set(wbuf, OF_OBJECT_ABSOLUTE_OFFSET(obj, offset),
                                  bytes);
}

/**
 * Get the wire length for a meter band stats list
 * @param obj The object being referenced
 * @param bytes Pointer to location to store length
 *
 * Must a meter_stats object as a parent
 */

void
of_list_meter_band_stats_wire_length_get(of_object_t *obj, int *bytes)
{
    LOCI_ASSERT(obj->parent != NULL);
    LOCI_ASSERT(obj->parent->object_id == OF_METER_STATS);

    /* We're counting on the parent being properly initialized already.
     * The length is stored in a uint16 at offset 4 of the parent.
     */
    *bytes = obj->parent->length - OF_OBJECT_FIXED_LENGTH(obj->parent);
}

#define OF_METER_STATS_LENGTH_OFFSET 4

/**
 * Get/set the wire length for a meter stats object
 * @param obj The object being referenced
 * @param bytes Pointer to location to store length
 *
 * It's almost a TLV....
 */

void
of_meter_stats_wire_length_get(of_object_t *obj, int *bytes)
{
    uint16_t val16;
    of_wire_buffer_t *wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);
    of_wire_buffer_u16_get(wbuf, 
               OF_OBJECT_ABSOLUTE_OFFSET(obj, OF_METER_STATS_LENGTH_OFFSET),
               &val16);
    *bytes = val16;
}

void
of_meter_stats_wire_length_set(of_object_t *obj, int bytes)
{
    of_wire_buffer_t *wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    of_wire_buffer_u16_set(wbuf, 
        OF_OBJECT_ABSOLUTE_OFFSET(obj, OF_METER_STATS_LENGTH_OFFSET), bytes);
}

int
of_experimenter_stats_request_to_object_id(uint32_t experimenter, uint32_t subtype, int ver)
{
    switch (experimenter) {
    case OF_EXPERIMENTER_ID_BSN:
        switch (subtype) {
        case 1: return OF_BSN_LACP_STATS_REQUEST;
        case 2: return OF_BSN_GENTABLE_ENTRY_DESC_STATS_REQUEST;
        case 3: return OF_BSN_GENTABLE_ENTRY_STATS_REQUEST;
        case 4: return OF_BSN_GENTABLE_DESC_STATS_REQUEST;
        case 5: return OF_BSN_GENTABLE_BUCKET_STATS_REQUEST;
        case 6: return OF_BSN_SWITCH_PIPELINE_STATS_REQUEST;
        case 7: return OF_BSN_GENTABLE_STATS_REQUEST;
        case 8: return OF_BSN_PORT_COUNTER_STATS_REQUEST;
        case 9: return OF_BSN_VLAN_COUNTER_STATS_REQUEST;
        case 10: return OF_BSN_FLOW_CHECKSUM_BUCKET_STATS_REQUEST;
        case 11: return OF_BSN_TABLE_CHECKSUM_STATS_REQUEST;
        case 12: return OF_BSN_DEBUG_COUNTER_STATS_REQUEST;
        case 13: return OF_BSN_DEBUG_COUNTER_DESC_STATS_REQUEST;
        case 14: return OF_BSN_IMAGE_DESC_STATS_REQUEST;
        }
    }
    return OF_OBJECT_INVALID;
}

int
of_experimenter_stats_reply_to_object_id(uint32_t experimenter, uint32_t subtype, int ver)
{
    switch (experimenter) {
    case OF_EXPERIMENTER_ID_BSN:
        switch (subtype) {
        case 1: return OF_BSN_LACP_STATS_REPLY;
        case 2: return OF_BSN_GENTABLE_ENTRY_DESC_STATS_REPLY;
        case 3: return OF_BSN_GENTABLE_ENTRY_STATS_REPLY;
        case 4: return OF_BSN_GENTABLE_DESC_STATS_REPLY;
        case 5: return OF_BSN_GENTABLE_BUCKET_STATS_REPLY;
        case 6: return OF_BSN_SWITCH_PIPELINE_STATS_REPLY;
        case 7: return OF_BSN_GENTABLE_STATS_REPLY;
        case 8: return OF_BSN_PORT_COUNTER_STATS_REPLY;
        case 9: return OF_BSN_VLAN_COUNTER_STATS_REPLY;
        case 10: return OF_BSN_FLOW_CHECKSUM_BUCKET_STATS_REPLY;
        case 11: return OF_BSN_TABLE_CHECKSUM_STATS_REPLY;
        case 12: return OF_BSN_DEBUG_COUNTER_STATS_REPLY;
        case 13: return OF_BSN_DEBUG_COUNTER_DESC_STATS_REPLY;
        case 14: return OF_BSN_IMAGE_DESC_STATS_REPLY;
        }
    }
    return OF_OBJECT_INVALID;
}
