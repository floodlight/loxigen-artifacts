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
    if (table_feature_prop == OF_EXPERIMENTER_TYPE) {
        return OF_TABLE_FEATURE_PROP_EXPERIMENTER;
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

        if (subtype == 56) {
            return OF_BSN_CONTROLLER_CONNECTIONS_REQUEST;
        }

        if (subtype == 21) {
            return OF_BSN_BW_CLEAR_DATA_REQUEST;
        }

        if (subtype == 42) {
            return OF_BSN_SET_LACP_REPLY;
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

        if (subtype == 52) {
            return OF_BSN_GET_SWITCH_PIPELINE_REPLY;
        }

        if (subtype == 18) {
            return OF_BSN_BW_ENABLE_SET_REQUEST;
        }

        if (subtype == 57) {
            return OF_BSN_CONTROLLER_CONNECTIONS_REPLY;
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

        if (subtype == 4) {
            return OF_BSN_GET_MIRRORING_REQUEST;
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

#define OF_BSN_TLV_ITEM_COUNT 8


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
    OF_OBJECT_INVALID              /* 7 (Invalid) */
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
    OF_OBJECT_INVALID              /* 7 (Invalid) */
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
    OF_OBJECT_INVALID              /* 7 (Invalid) */
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
    OF_BSN_TLV_IDLE_NOTIFICATION   /* 7 */
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
    20,   /* 12: of_bsn_bw_clear_data_reply */
    16,   /* 13: of_bsn_bw_clear_data_request */
    20,   /* 14: of_bsn_bw_enable_get_reply */
    16,   /* 15: of_bsn_bw_enable_get_request */
    24,   /* 16: of_bsn_bw_enable_set_reply */
    20,   /* 17: of_bsn_bw_enable_set_request */
    -1,   /* 18: of_bsn_controller_connections_reply */
    -1,   /* 19: of_bsn_controller_connections_request */
    -1,   /* 20: of_bsn_flow_idle */
    -1,   /* 21: of_bsn_flow_idle_enable_get_reply */
    -1,   /* 22: of_bsn_flow_idle_enable_get_request */
    -1,   /* 23: of_bsn_flow_idle_enable_set_reply */
    -1,   /* 24: of_bsn_flow_idle_enable_set_request */
    -1,   /* 25: of_bsn_gentable_bucket_stats_reply */
    -1,   /* 26: of_bsn_gentable_bucket_stats_request */
    -1,   /* 27: of_bsn_gentable_clear_reply */
    -1,   /* 28: of_bsn_gentable_clear_request */
    -1,   /* 29: of_bsn_gentable_desc_stats_reply */
    -1,   /* 30: of_bsn_gentable_desc_stats_request */
    -1,   /* 31: of_bsn_gentable_entry_add */
    -1,   /* 32: of_bsn_gentable_entry_delete */
    -1,   /* 33: of_bsn_gentable_entry_desc_stats_reply */
    -1,   /* 34: of_bsn_gentable_entry_desc_stats_request */
    -1,   /* 35: of_bsn_gentable_entry_stats_reply */
    -1,   /* 36: of_bsn_gentable_entry_stats_request */
    -1,   /* 37: of_bsn_gentable_set_buckets_size */
    -1,   /* 38: of_bsn_gentable_stats_reply */
    -1,   /* 39: of_bsn_gentable_stats_request */
    16,   /* 40: of_bsn_get_interfaces_reply */
    16,   /* 41: of_bsn_get_interfaces_request */
    24,   /* 42: of_bsn_get_ip_mask_reply */
    24,   /* 43: of_bsn_get_ip_mask_request */
    24,   /* 44: of_bsn_get_l2_table_reply */
    16,   /* 45: of_bsn_get_l2_table_request */
    20,   /* 46: of_bsn_get_mirroring_reply */
    20,   /* 47: of_bsn_get_mirroring_request */
    -1,   /* 48: of_bsn_get_switch_pipeline_reply */
    -1,   /* 49: of_bsn_get_switch_pipeline_request */
    16,   /* 50: of_bsn_header */
    24,   /* 51: of_bsn_hybrid_get_reply */
    16,   /* 52: of_bsn_hybrid_get_request */
    -1,   /* 53: of_bsn_lacp_convergence_notif */
    -1,   /* 54: of_bsn_lacp_stats_reply */
    -1,   /* 55: of_bsn_lacp_stats_request */
    23,   /* 56: of_bsn_pdu_rx_reply */
    26,   /* 57: of_bsn_pdu_rx_request */
    19,   /* 58: of_bsn_pdu_rx_timeout */
    23,   /* 59: of_bsn_pdu_tx_reply */
    26,   /* 60: of_bsn_pdu_tx_request */
    -1,   /* 61: of_bsn_port_counter_stats_reply */
    -1,   /* 62: of_bsn_port_counter_stats_request */
    -1,   /* 63: of_bsn_role_status */
    24,   /* 64: of_bsn_set_ip_mask */
    24,   /* 65: of_bsn_set_l2_table_reply */
    24,   /* 66: of_bsn_set_l2_table_request */
    -1,   /* 67: of_bsn_set_lacp_reply */
    -1,   /* 68: of_bsn_set_lacp_request */
    20,   /* 69: of_bsn_set_mirroring */
    20,   /* 70: of_bsn_set_pktin_suppression_reply */
    32,   /* 71: of_bsn_set_pktin_suppression_request */
    -1,   /* 72: of_bsn_set_switch_pipeline_reply */
    -1,   /* 73: of_bsn_set_switch_pipeline_request */
    20,   /* 74: of_bsn_shell_command */
    16,   /* 75: of_bsn_shell_output */
    20,   /* 76: of_bsn_shell_status */
    24,   /* 77: of_bsn_stats_reply */
    24,   /* 78: of_bsn_stats_request */
    -1,   /* 79: of_bsn_switch_pipeline_stats_reply */
    -1,   /* 80: of_bsn_switch_pipeline_stats_request */
    -1,   /* 81: of_bsn_time_reply */
    -1,   /* 82: of_bsn_time_request */
    24,   /* 83: of_bsn_virtual_port_create_reply */
    48,   /* 84: of_bsn_virtual_port_create_request */
    20,   /* 85: of_bsn_virtual_port_remove_reply */
    20,   /* 86: of_bsn_virtual_port_remove_request */
    -1,   /* 87: of_bsn_vlan_counter_stats_reply */
    -1,   /* 88: of_bsn_vlan_counter_stats_request */
    1068, /* 89: of_desc_stats_reply */
    12,   /* 90: of_desc_stats_request */
    8,    /* 91: of_echo_reply */
    8,    /* 92: of_echo_request */
    10,   /* 93: of_error_msg */
    16,   /* 94: of_experimenter */
    -1,   /* 95: of_experimenter_error_msg */
    16,   /* 96: of_experimenter_stats_reply */
    16,   /* 97: of_experimenter_stats_request */
    32,   /* 98: of_features_reply */
    8,    /* 99: of_features_request */
    72,   /* 100: of_flow_add */
    72,   /* 101: of_flow_delete */
    72,   /* 102: of_flow_delete_strict */
    72,   /* 103: of_flow_mod */
    12,   /* 104: of_flow_mod_failed_error_msg */
    72,   /* 105: of_flow_modify */
    72,   /* 106: of_flow_modify_strict */
    88,   /* 107: of_flow_removed */
    12,   /* 108: of_flow_stats_reply */
    56,   /* 109: of_flow_stats_request */
    12,   /* 110: of_get_config_reply */
    8,    /* 111: of_get_config_request */
    -1,   /* 112: of_group_add */
    -1,   /* 113: of_group_delete */
    -1,   /* 114: of_group_desc_stats_reply */
    -1,   /* 115: of_group_desc_stats_request */
    -1,   /* 116: of_group_features_stats_reply */
    -1,   /* 117: of_group_features_stats_request */
    -1,   /* 118: of_group_mod */
    -1,   /* 119: of_group_mod_failed_error_msg */
    -1,   /* 120: of_group_modify */
    -1,   /* 121: of_group_stats_reply */
    -1,   /* 122: of_group_stats_request */
    8,    /* 123: of_hello */
    12,   /* 124: of_hello_failed_error_msg */
    -1,   /* 125: of_meter_config_stats_reply */
    -1,   /* 126: of_meter_config_stats_request */
    -1,   /* 127: of_meter_features_stats_reply */
    -1,   /* 128: of_meter_features_stats_request */
    -1,   /* 129: of_meter_mod */
    -1,   /* 130: of_meter_mod_failed_error_msg */
    -1,   /* 131: of_meter_stats_reply */
    -1,   /* 132: of_meter_stats_request */
    20,   /* 133: of_nicira_controller_role_reply */
    20,   /* 134: of_nicira_controller_role_request */
    16,   /* 135: of_nicira_header */
    18,   /* 136: of_packet_in */
    16,   /* 137: of_packet_out */
    -1,   /* 138: of_port_desc_stats_reply */
    -1,   /* 139: of_port_desc_stats_request */
    32,   /* 140: of_port_mod */
    12,   /* 141: of_port_mod_failed_error_msg */
    12,   /* 142: of_port_stats_reply */
    20,   /* 143: of_port_stats_request */
    64,   /* 144: of_port_status */
    16,   /* 145: of_queue_get_config_reply */
    12,   /* 146: of_queue_get_config_request */
    12,   /* 147: of_queue_op_failed_error_msg */
    12,   /* 148: of_queue_stats_reply */
    20,   /* 149: of_queue_stats_request */
    -1,   /* 150: of_role_reply */
    -1,   /* 151: of_role_request */
    -1,   /* 152: of_role_request_failed_error_msg */
    12,   /* 153: of_set_config */
    12,   /* 154: of_stats_reply */
    12,   /* 155: of_stats_request */
    -1,   /* 156: of_switch_config_failed_error_msg */
    -1,   /* 157: of_table_features_failed_error_msg */
    -1,   /* 158: of_table_features_stats_reply */
    -1,   /* 159: of_table_features_stats_request */
    16,   /* 160: of_table_mod */
    -1,   /* 161: of_table_mod_failed_error_msg */
    12,   /* 162: of_table_stats_reply */
    12,   /* 163: of_table_stats_request */
    8,    /* 164: of_action */
    16,   /* 165: of_action_bsn */
    24,   /* 166: of_action_bsn_mirror */
    16,   /* 167: of_action_bsn_set_tunnel_dst */
    -1,   /* 168: of_action_copy_ttl_in */
    -1,   /* 169: of_action_copy_ttl_out */
    -1,   /* 170: of_action_dec_mpls_ttl */
    -1,   /* 171: of_action_dec_nw_ttl */
    16,   /* 172: of_action_enqueue */
    8,    /* 173: of_action_experimenter */
    -1,   /* 174: of_action_group */
    8,    /* 175: of_action_header */
    -1,   /* 176: of_action_id */
    -1,   /* 177: of_action_id_bsn */
    -1,   /* 178: of_action_id_bsn_mirror */
    -1,   /* 179: of_action_id_bsn_set_tunnel_dst */
    -1,   /* 180: of_action_id_copy_ttl_in */
    -1,   /* 181: of_action_id_copy_ttl_out */
    -1,   /* 182: of_action_id_dec_mpls_ttl */
    -1,   /* 183: of_action_id_dec_nw_ttl */
    -1,   /* 184: of_action_id_experimenter */
    -1,   /* 185: of_action_id_group */
    -1,   /* 186: of_action_id_header */
    -1,   /* 187: of_action_id_nicira */
    -1,   /* 188: of_action_id_nicira_dec_ttl */
    -1,   /* 189: of_action_id_output */
    -1,   /* 190: of_action_id_pop_mpls */
    -1,   /* 191: of_action_id_pop_pbb */
    -1,   /* 192: of_action_id_pop_vlan */
    -1,   /* 193: of_action_id_push_mpls */
    -1,   /* 194: of_action_id_push_pbb */
    -1,   /* 195: of_action_id_push_vlan */
    -1,   /* 196: of_action_id_set_field */
    -1,   /* 197: of_action_id_set_mpls_ttl */
    -1,   /* 198: of_action_id_set_nw_ttl */
    -1,   /* 199: of_action_id_set_queue */
    16,   /* 200: of_action_nicira */
    16,   /* 201: of_action_nicira_dec_ttl */
    8,    /* 202: of_action_output */
    -1,   /* 203: of_action_pop_mpls */
    -1,   /* 204: of_action_pop_pbb */
    -1,   /* 205: of_action_pop_vlan */
    -1,   /* 206: of_action_push_mpls */
    -1,   /* 207: of_action_push_pbb */
    -1,   /* 208: of_action_push_vlan */
    16,   /* 209: of_action_set_dl_dst */
    16,   /* 210: of_action_set_dl_src */
    -1,   /* 211: of_action_set_field */
    -1,   /* 212: of_action_set_mpls_label */
    -1,   /* 213: of_action_set_mpls_tc */
    -1,   /* 214: of_action_set_mpls_ttl */
    8,    /* 215: of_action_set_nw_dst */
    -1,   /* 216: of_action_set_nw_ecn */
    8,    /* 217: of_action_set_nw_src */
    8,    /* 218: of_action_set_nw_tos */
    -1,   /* 219: of_action_set_nw_ttl */
    -1,   /* 220: of_action_set_queue */
    8,    /* 221: of_action_set_tp_dst */
    8,    /* 222: of_action_set_tp_src */
    8,    /* 223: of_action_set_vlan_pcp */
    8,    /* 224: of_action_set_vlan_vid */
    8,    /* 225: of_action_strip_vlan */
    -1,   /* 226: of_bsn_controller_connection */
    -1,   /* 227: of_bsn_gentable_bucket_stats_entry */
    -1,   /* 228: of_bsn_gentable_desc_stats_entry */
    -1,   /* 229: of_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 230: of_bsn_gentable_entry_stats_entry */
    -1,   /* 231: of_bsn_gentable_stats_entry */
    32,   /* 232: of_bsn_interface */
    -1,   /* 233: of_bsn_lacp_stats_entry */
    -1,   /* 234: of_bsn_port_counter_stats_entry */
    -1,   /* 235: of_bsn_switch_pipeline_stats_entry */
    -1,   /* 236: of_bsn_tlv */
    -1,   /* 237: of_bsn_tlv_header */
    -1,   /* 238: of_bsn_tlv_idle_notification */
    -1,   /* 239: of_bsn_tlv_idle_time */
    -1,   /* 240: of_bsn_tlv_ipv4 */
    -1,   /* 241: of_bsn_tlv_mac */
    -1,   /* 242: of_bsn_tlv_port */
    -1,   /* 243: of_bsn_tlv_rx_packets */
    -1,   /* 244: of_bsn_tlv_tx_packets */
    -1,   /* 245: of_bsn_tlv_vlan_vid */
    -1,   /* 246: of_bsn_vlan_counter_stats_entry */
    4,    /* 247: of_bsn_vport */
    4,    /* 248: of_bsn_vport_header */
    32,   /* 249: of_bsn_vport_q_in_q */
    -1,   /* 250: of_bucket */
    -1,   /* 251: of_bucket_counter */
    -1,   /* 252: of_experimenter_stats_header */
    88,   /* 253: of_flow_stats_entry */
    -1,   /* 254: of_group_desc_stats_entry */
    -1,   /* 255: of_group_stats_entry */
    8,    /* 256: of_header */
    -1,   /* 257: of_hello_elem */
    -1,   /* 258: of_hello_elem_header */
    -1,   /* 259: of_hello_elem_versionbitmap */
    -1,   /* 260: of_instruction */
    -1,   /* 261: of_instruction_apply_actions */
    -1,   /* 262: of_instruction_bsn */
    -1,   /* 263: of_instruction_bsn_disable_src_mac_check */
    -1,   /* 264: of_instruction_clear_actions */
    -1,   /* 265: of_instruction_experimenter */
    -1,   /* 266: of_instruction_goto_table */
    -1,   /* 267: of_instruction_header */
    -1,   /* 268: of_instruction_id */
    -1,   /* 269: of_instruction_id_apply_actions */
    -1,   /* 270: of_instruction_id_bsn */
    -1,   /* 271: of_instruction_id_bsn_disable_src_mac_check */
    -1,   /* 272: of_instruction_id_clear_actions */
    -1,   /* 273: of_instruction_id_experimenter */
    -1,   /* 274: of_instruction_id_goto_table */
    -1,   /* 275: of_instruction_id_header */
    -1,   /* 276: of_instruction_id_meter */
    -1,   /* 277: of_instruction_id_write_actions */
    -1,   /* 278: of_instruction_id_write_metadata */
    -1,   /* 279: of_instruction_meter */
    -1,   /* 280: of_instruction_write_actions */
    -1,   /* 281: of_instruction_write_metadata */
    40,   /* 282: of_match_v1 */
    -1,   /* 283: of_match_v2 */
    -1,   /* 284: of_match_v3 */
    -1,   /* 285: of_meter_band */
    -1,   /* 286: of_meter_band_drop */
    -1,   /* 287: of_meter_band_dscp_remark */
    -1,   /* 288: of_meter_band_experimenter */
    -1,   /* 289: of_meter_band_header */
    -1,   /* 290: of_meter_band_stats */
    -1,   /* 291: of_meter_config */
    -1,   /* 292: of_meter_features */
    -1,   /* 293: of_meter_stats */
    -1,   /* 294: of_oxm */
    -1,   /* 295: of_oxm_arp_op */
    -1,   /* 296: of_oxm_arp_op_masked */
    -1,   /* 297: of_oxm_arp_sha */
    -1,   /* 298: of_oxm_arp_sha_masked */
    -1,   /* 299: of_oxm_arp_spa */
    -1,   /* 300: of_oxm_arp_spa_masked */
    -1,   /* 301: of_oxm_arp_tha */
    -1,   /* 302: of_oxm_arp_tha_masked */
    -1,   /* 303: of_oxm_arp_tpa */
    -1,   /* 304: of_oxm_arp_tpa_masked */
    -1,   /* 305: of_oxm_bsn_global_vrf_allowed */
    -1,   /* 306: of_oxm_bsn_global_vrf_allowed_masked */
    -1,   /* 307: of_oxm_bsn_in_ports_128 */
    -1,   /* 308: of_oxm_bsn_in_ports_128_masked */
    -1,   /* 309: of_oxm_bsn_l3_dst_class_id */
    -1,   /* 310: of_oxm_bsn_l3_dst_class_id_masked */
    -1,   /* 311: of_oxm_bsn_l3_interface_class_id */
    -1,   /* 312: of_oxm_bsn_l3_interface_class_id_masked */
    -1,   /* 313: of_oxm_bsn_l3_src_class_id */
    -1,   /* 314: of_oxm_bsn_l3_src_class_id_masked */
    -1,   /* 315: of_oxm_bsn_lag_id */
    -1,   /* 316: of_oxm_bsn_lag_id_masked */
    -1,   /* 317: of_oxm_bsn_vrf */
    -1,   /* 318: of_oxm_bsn_vrf_masked */
    -1,   /* 319: of_oxm_eth_dst */
    -1,   /* 320: of_oxm_eth_dst_masked */
    -1,   /* 321: of_oxm_eth_src */
    -1,   /* 322: of_oxm_eth_src_masked */
    -1,   /* 323: of_oxm_eth_type */
    -1,   /* 324: of_oxm_eth_type_masked */
    -1,   /* 325: of_oxm_header */
    -1,   /* 326: of_oxm_icmpv4_code */
    -1,   /* 327: of_oxm_icmpv4_code_masked */
    -1,   /* 328: of_oxm_icmpv4_type */
    -1,   /* 329: of_oxm_icmpv4_type_masked */
    -1,   /* 330: of_oxm_icmpv6_code */
    -1,   /* 331: of_oxm_icmpv6_code_masked */
    -1,   /* 332: of_oxm_icmpv6_type */
    -1,   /* 333: of_oxm_icmpv6_type_masked */
    -1,   /* 334: of_oxm_in_phy_port */
    -1,   /* 335: of_oxm_in_phy_port_masked */
    -1,   /* 336: of_oxm_in_port */
    -1,   /* 337: of_oxm_in_port_masked */
    -1,   /* 338: of_oxm_ip_dscp */
    -1,   /* 339: of_oxm_ip_dscp_masked */
    -1,   /* 340: of_oxm_ip_ecn */
    -1,   /* 341: of_oxm_ip_ecn_masked */
    -1,   /* 342: of_oxm_ip_proto */
    -1,   /* 343: of_oxm_ip_proto_masked */
    -1,   /* 344: of_oxm_ipv4_dst */
    -1,   /* 345: of_oxm_ipv4_dst_masked */
    -1,   /* 346: of_oxm_ipv4_src */
    -1,   /* 347: of_oxm_ipv4_src_masked */
    -1,   /* 348: of_oxm_ipv6_dst */
    -1,   /* 349: of_oxm_ipv6_dst_masked */
    -1,   /* 350: of_oxm_ipv6_flabel */
    -1,   /* 351: of_oxm_ipv6_flabel_masked */
    -1,   /* 352: of_oxm_ipv6_nd_sll */
    -1,   /* 353: of_oxm_ipv6_nd_sll_masked */
    -1,   /* 354: of_oxm_ipv6_nd_target */
    -1,   /* 355: of_oxm_ipv6_nd_target_masked */
    -1,   /* 356: of_oxm_ipv6_nd_tll */
    -1,   /* 357: of_oxm_ipv6_nd_tll_masked */
    -1,   /* 358: of_oxm_ipv6_src */
    -1,   /* 359: of_oxm_ipv6_src_masked */
    -1,   /* 360: of_oxm_metadata */
    -1,   /* 361: of_oxm_metadata_masked */
    -1,   /* 362: of_oxm_mpls_label */
    -1,   /* 363: of_oxm_mpls_label_masked */
    -1,   /* 364: of_oxm_mpls_tc */
    -1,   /* 365: of_oxm_mpls_tc_masked */
    -1,   /* 366: of_oxm_sctp_dst */
    -1,   /* 367: of_oxm_sctp_dst_masked */
    -1,   /* 368: of_oxm_sctp_src */
    -1,   /* 369: of_oxm_sctp_src_masked */
    -1,   /* 370: of_oxm_tcp_dst */
    -1,   /* 371: of_oxm_tcp_dst_masked */
    -1,   /* 372: of_oxm_tcp_src */
    -1,   /* 373: of_oxm_tcp_src_masked */
    -1,   /* 374: of_oxm_udp_dst */
    -1,   /* 375: of_oxm_udp_dst_masked */
    -1,   /* 376: of_oxm_udp_src */
    -1,   /* 377: of_oxm_udp_src_masked */
    -1,   /* 378: of_oxm_vlan_pcp */
    -1,   /* 379: of_oxm_vlan_pcp_masked */
    -1,   /* 380: of_oxm_vlan_vid */
    -1,   /* 381: of_oxm_vlan_vid_masked */
    8,    /* 382: of_packet_queue */
    48,   /* 383: of_port_desc */
    104,  /* 384: of_port_stats_entry */
    8,    /* 385: of_queue_prop */
    -1,   /* 386: of_queue_prop_experimenter */
    8,    /* 387: of_queue_prop_header */
    -1,   /* 388: of_queue_prop_max_rate */
    16,   /* 389: of_queue_prop_min_rate */
    32,   /* 390: of_queue_stats_entry */
    -1,   /* 391: of_table_feature_prop */
    -1,   /* 392: of_table_feature_prop_apply_actions */
    -1,   /* 393: of_table_feature_prop_apply_actions_miss */
    -1,   /* 394: of_table_feature_prop_apply_setfield */
    -1,   /* 395: of_table_feature_prop_apply_setfield_miss */
    -1,   /* 396: of_table_feature_prop_experimenter */
    -1,   /* 397: of_table_feature_prop_header */
    -1,   /* 398: of_table_feature_prop_instructions */
    -1,   /* 399: of_table_feature_prop_instructions_miss */
    -1,   /* 400: of_table_feature_prop_match */
    -1,   /* 401: of_table_feature_prop_next_tables */
    -1,   /* 402: of_table_feature_prop_next_tables_miss */
    -1,   /* 403: of_table_feature_prop_wildcards */
    -1,   /* 404: of_table_feature_prop_write_actions */
    -1,   /* 405: of_table_feature_prop_write_actions_miss */
    -1,   /* 406: of_table_feature_prop_write_setfield */
    -1,   /* 407: of_table_feature_prop_write_setfield_miss */
    -1,   /* 408: of_table_features */
    64,   /* 409: of_table_stats_entry */
    -1,   /* 410: of_uint32 */
    -1,   /* 411: of_uint64 */
    -1,   /* 412: of_uint8 */
    0,    /* 413: of_list_action */
    -1,   /* 414: of_list_action_id */
    -1,   /* 415: of_list_bsn_controller_connection */
    -1,   /* 416: of_list_bsn_gentable_bucket_stats_entry */
    -1,   /* 417: of_list_bsn_gentable_desc_stats_entry */
    -1,   /* 418: of_list_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 419: of_list_bsn_gentable_entry_stats_entry */
    -1,   /* 420: of_list_bsn_gentable_stats_entry */
    0,    /* 421: of_list_bsn_interface */
    -1,   /* 422: of_list_bsn_lacp_stats_entry */
    -1,   /* 423: of_list_bsn_port_counter_stats_entry */
    -1,   /* 424: of_list_bsn_switch_pipeline_stats_entry */
    -1,   /* 425: of_list_bsn_tlv */
    -1,   /* 426: of_list_bsn_vlan_counter_stats_entry */
    -1,   /* 427: of_list_bucket */
    -1,   /* 428: of_list_bucket_counter */
    0,    /* 429: of_list_flow_stats_entry */
    -1,   /* 430: of_list_group_desc_stats_entry */
    -1,   /* 431: of_list_group_stats_entry */
    -1,   /* 432: of_list_hello_elem */
    -1,   /* 433: of_list_instruction */
    -1,   /* 434: of_list_meter_band */
    -1,   /* 435: of_list_meter_band_stats */
    -1,   /* 436: of_list_meter_stats */
    -1,   /* 437: of_list_oxm */
    0,    /* 438: of_list_packet_queue */
    0,    /* 439: of_list_port_desc */
    0,    /* 440: of_list_port_stats_entry */
    0,    /* 441: of_list_queue_prop */
    0,    /* 442: of_list_queue_stats_entry */
    -1,   /* 443: of_list_table_feature_prop */
    -1,   /* 444: of_list_table_features */
    0,    /* 445: of_list_table_stats_entry */
    -1,   /* 446: of_list_uint32 */
    -1,   /* 447: of_list_uint64 */
    -1    /* 448: of_list_uint8 */
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
    20,   /* 12: of_bsn_bw_clear_data_reply */
    16,   /* 13: of_bsn_bw_clear_data_request */
    20,   /* 14: of_bsn_bw_enable_get_reply */
    16,   /* 15: of_bsn_bw_enable_get_request */
    24,   /* 16: of_bsn_bw_enable_set_reply */
    20,   /* 17: of_bsn_bw_enable_set_request */
    -1,   /* 18: of_bsn_controller_connections_reply */
    -1,   /* 19: of_bsn_controller_connections_request */
    -1,   /* 20: of_bsn_flow_idle */
    -1,   /* 21: of_bsn_flow_idle_enable_get_reply */
    -1,   /* 22: of_bsn_flow_idle_enable_get_request */
    -1,   /* 23: of_bsn_flow_idle_enable_set_reply */
    -1,   /* 24: of_bsn_flow_idle_enable_set_request */
    -1,   /* 25: of_bsn_gentable_bucket_stats_reply */
    -1,   /* 26: of_bsn_gentable_bucket_stats_request */
    -1,   /* 27: of_bsn_gentable_clear_reply */
    -1,   /* 28: of_bsn_gentable_clear_request */
    -1,   /* 29: of_bsn_gentable_desc_stats_reply */
    -1,   /* 30: of_bsn_gentable_desc_stats_request */
    -1,   /* 31: of_bsn_gentable_entry_add */
    -1,   /* 32: of_bsn_gentable_entry_delete */
    -1,   /* 33: of_bsn_gentable_entry_desc_stats_reply */
    -1,   /* 34: of_bsn_gentable_entry_desc_stats_request */
    -1,   /* 35: of_bsn_gentable_entry_stats_reply */
    -1,   /* 36: of_bsn_gentable_entry_stats_request */
    -1,   /* 37: of_bsn_gentable_set_buckets_size */
    -1,   /* 38: of_bsn_gentable_stats_reply */
    -1,   /* 39: of_bsn_gentable_stats_request */
    16,   /* 40: of_bsn_get_interfaces_reply */
    16,   /* 41: of_bsn_get_interfaces_request */
    -1,   /* 42: of_bsn_get_ip_mask_reply */
    -1,   /* 43: of_bsn_get_ip_mask_request */
    -1,   /* 44: of_bsn_get_l2_table_reply */
    -1,   /* 45: of_bsn_get_l2_table_request */
    20,   /* 46: of_bsn_get_mirroring_reply */
    20,   /* 47: of_bsn_get_mirroring_request */
    -1,   /* 48: of_bsn_get_switch_pipeline_reply */
    -1,   /* 49: of_bsn_get_switch_pipeline_request */
    16,   /* 50: of_bsn_header */
    -1,   /* 51: of_bsn_hybrid_get_reply */
    -1,   /* 52: of_bsn_hybrid_get_request */
    -1,   /* 53: of_bsn_lacp_convergence_notif */
    -1,   /* 54: of_bsn_lacp_stats_reply */
    -1,   /* 55: of_bsn_lacp_stats_request */
    25,   /* 56: of_bsn_pdu_rx_reply */
    28,   /* 57: of_bsn_pdu_rx_request */
    21,   /* 58: of_bsn_pdu_rx_timeout */
    25,   /* 59: of_bsn_pdu_tx_reply */
    28,   /* 60: of_bsn_pdu_tx_request */
    -1,   /* 61: of_bsn_port_counter_stats_reply */
    -1,   /* 62: of_bsn_port_counter_stats_request */
    -1,   /* 63: of_bsn_role_status */
    -1,   /* 64: of_bsn_set_ip_mask */
    -1,   /* 65: of_bsn_set_l2_table_reply */
    -1,   /* 66: of_bsn_set_l2_table_request */
    -1,   /* 67: of_bsn_set_lacp_reply */
    -1,   /* 68: of_bsn_set_lacp_request */
    20,   /* 69: of_bsn_set_mirroring */
    20,   /* 70: of_bsn_set_pktin_suppression_reply */
    32,   /* 71: of_bsn_set_pktin_suppression_request */
    -1,   /* 72: of_bsn_set_switch_pipeline_reply */
    -1,   /* 73: of_bsn_set_switch_pipeline_request */
    -1,   /* 74: of_bsn_shell_command */
    -1,   /* 75: of_bsn_shell_output */
    -1,   /* 76: of_bsn_shell_status */
    24,   /* 77: of_bsn_stats_reply */
    24,   /* 78: of_bsn_stats_request */
    -1,   /* 79: of_bsn_switch_pipeline_stats_reply */
    -1,   /* 80: of_bsn_switch_pipeline_stats_request */
    -1,   /* 81: of_bsn_time_reply */
    -1,   /* 82: of_bsn_time_request */
    24,   /* 83: of_bsn_virtual_port_create_reply */
    48,   /* 84: of_bsn_virtual_port_create_request */
    20,   /* 85: of_bsn_virtual_port_remove_reply */
    20,   /* 86: of_bsn_virtual_port_remove_request */
    -1,   /* 87: of_bsn_vlan_counter_stats_reply */
    -1,   /* 88: of_bsn_vlan_counter_stats_request */
    1072, /* 89: of_desc_stats_reply */
    16,   /* 90: of_desc_stats_request */
    8,    /* 91: of_echo_reply */
    8,    /* 92: of_echo_request */
    10,   /* 93: of_error_msg */
    16,   /* 94: of_experimenter */
    -1,   /* 95: of_experimenter_error_msg */
    24,   /* 96: of_experimenter_stats_reply */
    24,   /* 97: of_experimenter_stats_request */
    32,   /* 98: of_features_reply */
    8,    /* 99: of_features_request */
    136,  /* 100: of_flow_add */
    136,  /* 101: of_flow_delete */
    136,  /* 102: of_flow_delete_strict */
    136,  /* 103: of_flow_mod */
    12,   /* 104: of_flow_mod_failed_error_msg */
    136,  /* 105: of_flow_modify */
    136,  /* 106: of_flow_modify_strict */
    136,  /* 107: of_flow_removed */
    16,   /* 108: of_flow_stats_reply */
    136,  /* 109: of_flow_stats_request */
    12,   /* 110: of_get_config_reply */
    8,    /* 111: of_get_config_request */
    16,   /* 112: of_group_add */
    16,   /* 113: of_group_delete */
    16,   /* 114: of_group_desc_stats_reply */
    16,   /* 115: of_group_desc_stats_request */
    -1,   /* 116: of_group_features_stats_reply */
    -1,   /* 117: of_group_features_stats_request */
    16,   /* 118: of_group_mod */
    12,   /* 119: of_group_mod_failed_error_msg */
    16,   /* 120: of_group_modify */
    16,   /* 121: of_group_stats_reply */
    24,   /* 122: of_group_stats_request */
    8,    /* 123: of_hello */
    12,   /* 124: of_hello_failed_error_msg */
    -1,   /* 125: of_meter_config_stats_reply */
    -1,   /* 126: of_meter_config_stats_request */
    -1,   /* 127: of_meter_features_stats_reply */
    -1,   /* 128: of_meter_features_stats_request */
    -1,   /* 129: of_meter_mod */
    -1,   /* 130: of_meter_mod_failed_error_msg */
    -1,   /* 131: of_meter_stats_reply */
    -1,   /* 132: of_meter_stats_request */
    -1,   /* 133: of_nicira_controller_role_reply */
    -1,   /* 134: of_nicira_controller_role_request */
    16,   /* 135: of_nicira_header */
    24,   /* 136: of_packet_in */
    24,   /* 137: of_packet_out */
    -1,   /* 138: of_port_desc_stats_reply */
    -1,   /* 139: of_port_desc_stats_request */
    40,   /* 140: of_port_mod */
    12,   /* 141: of_port_mod_failed_error_msg */
    16,   /* 142: of_port_stats_reply */
    24,   /* 143: of_port_stats_request */
    80,   /* 144: of_port_status */
    16,   /* 145: of_queue_get_config_reply */
    16,   /* 146: of_queue_get_config_request */
    12,   /* 147: of_queue_op_failed_error_msg */
    16,   /* 148: of_queue_stats_reply */
    24,   /* 149: of_queue_stats_request */
    -1,   /* 150: of_role_reply */
    -1,   /* 151: of_role_request */
    -1,   /* 152: of_role_request_failed_error_msg */
    12,   /* 153: of_set_config */
    16,   /* 154: of_stats_reply */
    16,   /* 155: of_stats_request */
    12,   /* 156: of_switch_config_failed_error_msg */
    -1,   /* 157: of_table_features_failed_error_msg */
    -1,   /* 158: of_table_features_stats_reply */
    -1,   /* 159: of_table_features_stats_request */
    16,   /* 160: of_table_mod */
    12,   /* 161: of_table_mod_failed_error_msg */
    16,   /* 162: of_table_stats_reply */
    16,   /* 163: of_table_stats_request */
    8,    /* 164: of_action */
    16,   /* 165: of_action_bsn */
    24,   /* 166: of_action_bsn_mirror */
    16,   /* 167: of_action_bsn_set_tunnel_dst */
    8,    /* 168: of_action_copy_ttl_in */
    8,    /* 169: of_action_copy_ttl_out */
    8,    /* 170: of_action_dec_mpls_ttl */
    8,    /* 171: of_action_dec_nw_ttl */
    -1,   /* 172: of_action_enqueue */
    8,    /* 173: of_action_experimenter */
    8,    /* 174: of_action_group */
    8,    /* 175: of_action_header */
    -1,   /* 176: of_action_id */
    -1,   /* 177: of_action_id_bsn */
    -1,   /* 178: of_action_id_bsn_mirror */
    -1,   /* 179: of_action_id_bsn_set_tunnel_dst */
    -1,   /* 180: of_action_id_copy_ttl_in */
    -1,   /* 181: of_action_id_copy_ttl_out */
    -1,   /* 182: of_action_id_dec_mpls_ttl */
    -1,   /* 183: of_action_id_dec_nw_ttl */
    -1,   /* 184: of_action_id_experimenter */
    -1,   /* 185: of_action_id_group */
    -1,   /* 186: of_action_id_header */
    -1,   /* 187: of_action_id_nicira */
    -1,   /* 188: of_action_id_nicira_dec_ttl */
    -1,   /* 189: of_action_id_output */
    -1,   /* 190: of_action_id_pop_mpls */
    -1,   /* 191: of_action_id_pop_pbb */
    -1,   /* 192: of_action_id_pop_vlan */
    -1,   /* 193: of_action_id_push_mpls */
    -1,   /* 194: of_action_id_push_pbb */
    -1,   /* 195: of_action_id_push_vlan */
    -1,   /* 196: of_action_id_set_field */
    -1,   /* 197: of_action_id_set_mpls_ttl */
    -1,   /* 198: of_action_id_set_nw_ttl */
    -1,   /* 199: of_action_id_set_queue */
    16,   /* 200: of_action_nicira */
    16,   /* 201: of_action_nicira_dec_ttl */
    16,   /* 202: of_action_output */
    8,    /* 203: of_action_pop_mpls */
    -1,   /* 204: of_action_pop_pbb */
    8,    /* 205: of_action_pop_vlan */
    8,    /* 206: of_action_push_mpls */
    -1,   /* 207: of_action_push_pbb */
    8,    /* 208: of_action_push_vlan */
    16,   /* 209: of_action_set_dl_dst */
    16,   /* 210: of_action_set_dl_src */
    -1,   /* 211: of_action_set_field */
    8,    /* 212: of_action_set_mpls_label */
    8,    /* 213: of_action_set_mpls_tc */
    8,    /* 214: of_action_set_mpls_ttl */
    8,    /* 215: of_action_set_nw_dst */
    8,    /* 216: of_action_set_nw_ecn */
    8,    /* 217: of_action_set_nw_src */
    8,    /* 218: of_action_set_nw_tos */
    8,    /* 219: of_action_set_nw_ttl */
    8,    /* 220: of_action_set_queue */
    8,    /* 221: of_action_set_tp_dst */
    8,    /* 222: of_action_set_tp_src */
    8,    /* 223: of_action_set_vlan_pcp */
    8,    /* 224: of_action_set_vlan_vid */
    -1,   /* 225: of_action_strip_vlan */
    -1,   /* 226: of_bsn_controller_connection */
    -1,   /* 227: of_bsn_gentable_bucket_stats_entry */
    -1,   /* 228: of_bsn_gentable_desc_stats_entry */
    -1,   /* 229: of_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 230: of_bsn_gentable_entry_stats_entry */
    -1,   /* 231: of_bsn_gentable_stats_entry */
    32,   /* 232: of_bsn_interface */
    -1,   /* 233: of_bsn_lacp_stats_entry */
    -1,   /* 234: of_bsn_port_counter_stats_entry */
    -1,   /* 235: of_bsn_switch_pipeline_stats_entry */
    -1,   /* 236: of_bsn_tlv */
    -1,   /* 237: of_bsn_tlv_header */
    -1,   /* 238: of_bsn_tlv_idle_notification */
    -1,   /* 239: of_bsn_tlv_idle_time */
    -1,   /* 240: of_bsn_tlv_ipv4 */
    -1,   /* 241: of_bsn_tlv_mac */
    -1,   /* 242: of_bsn_tlv_port */
    -1,   /* 243: of_bsn_tlv_rx_packets */
    -1,   /* 244: of_bsn_tlv_tx_packets */
    -1,   /* 245: of_bsn_tlv_vlan_vid */
    -1,   /* 246: of_bsn_vlan_counter_stats_entry */
    4,    /* 247: of_bsn_vport */
    4,    /* 248: of_bsn_vport_header */
    32,   /* 249: of_bsn_vport_q_in_q */
    16,   /* 250: of_bucket */
    16,   /* 251: of_bucket_counter */
    -1,   /* 252: of_experimenter_stats_header */
    136,  /* 253: of_flow_stats_entry */
    8,    /* 254: of_group_desc_stats_entry */
    32,   /* 255: of_group_stats_entry */
    8,    /* 256: of_header */
    -1,   /* 257: of_hello_elem */
    -1,   /* 258: of_hello_elem_header */
    -1,   /* 259: of_hello_elem_versionbitmap */
    8,    /* 260: of_instruction */
    8,    /* 261: of_instruction_apply_actions */
    -1,   /* 262: of_instruction_bsn */
    -1,   /* 263: of_instruction_bsn_disable_src_mac_check */
    8,    /* 264: of_instruction_clear_actions */
    8,    /* 265: of_instruction_experimenter */
    8,    /* 266: of_instruction_goto_table */
    8,    /* 267: of_instruction_header */
    -1,   /* 268: of_instruction_id */
    -1,   /* 269: of_instruction_id_apply_actions */
    -1,   /* 270: of_instruction_id_bsn */
    -1,   /* 271: of_instruction_id_bsn_disable_src_mac_check */
    -1,   /* 272: of_instruction_id_clear_actions */
    -1,   /* 273: of_instruction_id_experimenter */
    -1,   /* 274: of_instruction_id_goto_table */
    -1,   /* 275: of_instruction_id_header */
    -1,   /* 276: of_instruction_id_meter */
    -1,   /* 277: of_instruction_id_write_actions */
    -1,   /* 278: of_instruction_id_write_metadata */
    -1,   /* 279: of_instruction_meter */
    8,    /* 280: of_instruction_write_actions */
    24,   /* 281: of_instruction_write_metadata */
    -1,   /* 282: of_match_v1 */
    88,   /* 283: of_match_v2 */
    -1,   /* 284: of_match_v3 */
    -1,   /* 285: of_meter_band */
    -1,   /* 286: of_meter_band_drop */
    -1,   /* 287: of_meter_band_dscp_remark */
    -1,   /* 288: of_meter_band_experimenter */
    -1,   /* 289: of_meter_band_header */
    -1,   /* 290: of_meter_band_stats */
    -1,   /* 291: of_meter_config */
    -1,   /* 292: of_meter_features */
    -1,   /* 293: of_meter_stats */
    -1,   /* 294: of_oxm */
    -1,   /* 295: of_oxm_arp_op */
    -1,   /* 296: of_oxm_arp_op_masked */
    -1,   /* 297: of_oxm_arp_sha */
    -1,   /* 298: of_oxm_arp_sha_masked */
    -1,   /* 299: of_oxm_arp_spa */
    -1,   /* 300: of_oxm_arp_spa_masked */
    -1,   /* 301: of_oxm_arp_tha */
    -1,   /* 302: of_oxm_arp_tha_masked */
    -1,   /* 303: of_oxm_arp_tpa */
    -1,   /* 304: of_oxm_arp_tpa_masked */
    -1,   /* 305: of_oxm_bsn_global_vrf_allowed */
    -1,   /* 306: of_oxm_bsn_global_vrf_allowed_masked */
    -1,   /* 307: of_oxm_bsn_in_ports_128 */
    -1,   /* 308: of_oxm_bsn_in_ports_128_masked */
    -1,   /* 309: of_oxm_bsn_l3_dst_class_id */
    -1,   /* 310: of_oxm_bsn_l3_dst_class_id_masked */
    -1,   /* 311: of_oxm_bsn_l3_interface_class_id */
    -1,   /* 312: of_oxm_bsn_l3_interface_class_id_masked */
    -1,   /* 313: of_oxm_bsn_l3_src_class_id */
    -1,   /* 314: of_oxm_bsn_l3_src_class_id_masked */
    -1,   /* 315: of_oxm_bsn_lag_id */
    -1,   /* 316: of_oxm_bsn_lag_id_masked */
    -1,   /* 317: of_oxm_bsn_vrf */
    -1,   /* 318: of_oxm_bsn_vrf_masked */
    -1,   /* 319: of_oxm_eth_dst */
    -1,   /* 320: of_oxm_eth_dst_masked */
    -1,   /* 321: of_oxm_eth_src */
    -1,   /* 322: of_oxm_eth_src_masked */
    -1,   /* 323: of_oxm_eth_type */
    -1,   /* 324: of_oxm_eth_type_masked */
    -1,   /* 325: of_oxm_header */
    -1,   /* 326: of_oxm_icmpv4_code */
    -1,   /* 327: of_oxm_icmpv4_code_masked */
    -1,   /* 328: of_oxm_icmpv4_type */
    -1,   /* 329: of_oxm_icmpv4_type_masked */
    -1,   /* 330: of_oxm_icmpv6_code */
    -1,   /* 331: of_oxm_icmpv6_code_masked */
    -1,   /* 332: of_oxm_icmpv6_type */
    -1,   /* 333: of_oxm_icmpv6_type_masked */
    -1,   /* 334: of_oxm_in_phy_port */
    -1,   /* 335: of_oxm_in_phy_port_masked */
    -1,   /* 336: of_oxm_in_port */
    -1,   /* 337: of_oxm_in_port_masked */
    -1,   /* 338: of_oxm_ip_dscp */
    -1,   /* 339: of_oxm_ip_dscp_masked */
    -1,   /* 340: of_oxm_ip_ecn */
    -1,   /* 341: of_oxm_ip_ecn_masked */
    -1,   /* 342: of_oxm_ip_proto */
    -1,   /* 343: of_oxm_ip_proto_masked */
    -1,   /* 344: of_oxm_ipv4_dst */
    -1,   /* 345: of_oxm_ipv4_dst_masked */
    -1,   /* 346: of_oxm_ipv4_src */
    -1,   /* 347: of_oxm_ipv4_src_masked */
    -1,   /* 348: of_oxm_ipv6_dst */
    -1,   /* 349: of_oxm_ipv6_dst_masked */
    -1,   /* 350: of_oxm_ipv6_flabel */
    -1,   /* 351: of_oxm_ipv6_flabel_masked */
    -1,   /* 352: of_oxm_ipv6_nd_sll */
    -1,   /* 353: of_oxm_ipv6_nd_sll_masked */
    -1,   /* 354: of_oxm_ipv6_nd_target */
    -1,   /* 355: of_oxm_ipv6_nd_target_masked */
    -1,   /* 356: of_oxm_ipv6_nd_tll */
    -1,   /* 357: of_oxm_ipv6_nd_tll_masked */
    -1,   /* 358: of_oxm_ipv6_src */
    -1,   /* 359: of_oxm_ipv6_src_masked */
    -1,   /* 360: of_oxm_metadata */
    -1,   /* 361: of_oxm_metadata_masked */
    -1,   /* 362: of_oxm_mpls_label */
    -1,   /* 363: of_oxm_mpls_label_masked */
    -1,   /* 364: of_oxm_mpls_tc */
    -1,   /* 365: of_oxm_mpls_tc_masked */
    -1,   /* 366: of_oxm_sctp_dst */
    -1,   /* 367: of_oxm_sctp_dst_masked */
    -1,   /* 368: of_oxm_sctp_src */
    -1,   /* 369: of_oxm_sctp_src_masked */
    -1,   /* 370: of_oxm_tcp_dst */
    -1,   /* 371: of_oxm_tcp_dst_masked */
    -1,   /* 372: of_oxm_tcp_src */
    -1,   /* 373: of_oxm_tcp_src_masked */
    -1,   /* 374: of_oxm_udp_dst */
    -1,   /* 375: of_oxm_udp_dst_masked */
    -1,   /* 376: of_oxm_udp_src */
    -1,   /* 377: of_oxm_udp_src_masked */
    -1,   /* 378: of_oxm_vlan_pcp */
    -1,   /* 379: of_oxm_vlan_pcp_masked */
    -1,   /* 380: of_oxm_vlan_vid */
    -1,   /* 381: of_oxm_vlan_vid_masked */
    8,    /* 382: of_packet_queue */
    64,   /* 383: of_port_desc */
    104,  /* 384: of_port_stats_entry */
    8,    /* 385: of_queue_prop */
    -1,   /* 386: of_queue_prop_experimenter */
    8,    /* 387: of_queue_prop_header */
    -1,   /* 388: of_queue_prop_max_rate */
    16,   /* 389: of_queue_prop_min_rate */
    32,   /* 390: of_queue_stats_entry */
    -1,   /* 391: of_table_feature_prop */
    -1,   /* 392: of_table_feature_prop_apply_actions */
    -1,   /* 393: of_table_feature_prop_apply_actions_miss */
    -1,   /* 394: of_table_feature_prop_apply_setfield */
    -1,   /* 395: of_table_feature_prop_apply_setfield_miss */
    -1,   /* 396: of_table_feature_prop_experimenter */
    -1,   /* 397: of_table_feature_prop_header */
    -1,   /* 398: of_table_feature_prop_instructions */
    -1,   /* 399: of_table_feature_prop_instructions_miss */
    -1,   /* 400: of_table_feature_prop_match */
    -1,   /* 401: of_table_feature_prop_next_tables */
    -1,   /* 402: of_table_feature_prop_next_tables_miss */
    -1,   /* 403: of_table_feature_prop_wildcards */
    -1,   /* 404: of_table_feature_prop_write_actions */
    -1,   /* 405: of_table_feature_prop_write_actions_miss */
    -1,   /* 406: of_table_feature_prop_write_setfield */
    -1,   /* 407: of_table_feature_prop_write_setfield_miss */
    -1,   /* 408: of_table_features */
    88,   /* 409: of_table_stats_entry */
    -1,   /* 410: of_uint32 */
    -1,   /* 411: of_uint64 */
    -1,   /* 412: of_uint8 */
    0,    /* 413: of_list_action */
    -1,   /* 414: of_list_action_id */
    -1,   /* 415: of_list_bsn_controller_connection */
    -1,   /* 416: of_list_bsn_gentable_bucket_stats_entry */
    -1,   /* 417: of_list_bsn_gentable_desc_stats_entry */
    -1,   /* 418: of_list_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 419: of_list_bsn_gentable_entry_stats_entry */
    -1,   /* 420: of_list_bsn_gentable_stats_entry */
    0,    /* 421: of_list_bsn_interface */
    -1,   /* 422: of_list_bsn_lacp_stats_entry */
    -1,   /* 423: of_list_bsn_port_counter_stats_entry */
    -1,   /* 424: of_list_bsn_switch_pipeline_stats_entry */
    -1,   /* 425: of_list_bsn_tlv */
    -1,   /* 426: of_list_bsn_vlan_counter_stats_entry */
    0,    /* 427: of_list_bucket */
    0,    /* 428: of_list_bucket_counter */
    0,    /* 429: of_list_flow_stats_entry */
    0,    /* 430: of_list_group_desc_stats_entry */
    0,    /* 431: of_list_group_stats_entry */
    -1,   /* 432: of_list_hello_elem */
    0,    /* 433: of_list_instruction */
    -1,   /* 434: of_list_meter_band */
    -1,   /* 435: of_list_meter_band_stats */
    -1,   /* 436: of_list_meter_stats */
    -1,   /* 437: of_list_oxm */
    0,    /* 438: of_list_packet_queue */
    0,    /* 439: of_list_port_desc */
    0,    /* 440: of_list_port_stats_entry */
    0,    /* 441: of_list_queue_prop */
    0,    /* 442: of_list_queue_stats_entry */
    -1,   /* 443: of_list_table_feature_prop */
    -1,   /* 444: of_list_table_features */
    0,    /* 445: of_list_table_stats_entry */
    -1,   /* 446: of_list_uint32 */
    -1,   /* 447: of_list_uint64 */
    -1    /* 448: of_list_uint8 */
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
    20,   /* 12: of_bsn_bw_clear_data_reply */
    16,   /* 13: of_bsn_bw_clear_data_request */
    20,   /* 14: of_bsn_bw_enable_get_reply */
    16,   /* 15: of_bsn_bw_enable_get_request */
    24,   /* 16: of_bsn_bw_enable_set_reply */
    20,   /* 17: of_bsn_bw_enable_set_request */
    -1,   /* 18: of_bsn_controller_connections_reply */
    -1,   /* 19: of_bsn_controller_connections_request */
    -1,   /* 20: of_bsn_flow_idle */
    -1,   /* 21: of_bsn_flow_idle_enable_get_reply */
    -1,   /* 22: of_bsn_flow_idle_enable_get_request */
    -1,   /* 23: of_bsn_flow_idle_enable_set_reply */
    -1,   /* 24: of_bsn_flow_idle_enable_set_request */
    -1,   /* 25: of_bsn_gentable_bucket_stats_reply */
    -1,   /* 26: of_bsn_gentable_bucket_stats_request */
    -1,   /* 27: of_bsn_gentable_clear_reply */
    -1,   /* 28: of_bsn_gentable_clear_request */
    -1,   /* 29: of_bsn_gentable_desc_stats_reply */
    -1,   /* 30: of_bsn_gentable_desc_stats_request */
    -1,   /* 31: of_bsn_gentable_entry_add */
    -1,   /* 32: of_bsn_gentable_entry_delete */
    -1,   /* 33: of_bsn_gentable_entry_desc_stats_reply */
    -1,   /* 34: of_bsn_gentable_entry_desc_stats_request */
    -1,   /* 35: of_bsn_gentable_entry_stats_reply */
    -1,   /* 36: of_bsn_gentable_entry_stats_request */
    -1,   /* 37: of_bsn_gentable_set_buckets_size */
    -1,   /* 38: of_bsn_gentable_stats_reply */
    -1,   /* 39: of_bsn_gentable_stats_request */
    16,   /* 40: of_bsn_get_interfaces_reply */
    16,   /* 41: of_bsn_get_interfaces_request */
    -1,   /* 42: of_bsn_get_ip_mask_reply */
    -1,   /* 43: of_bsn_get_ip_mask_request */
    -1,   /* 44: of_bsn_get_l2_table_reply */
    -1,   /* 45: of_bsn_get_l2_table_request */
    20,   /* 46: of_bsn_get_mirroring_reply */
    20,   /* 47: of_bsn_get_mirroring_request */
    -1,   /* 48: of_bsn_get_switch_pipeline_reply */
    -1,   /* 49: of_bsn_get_switch_pipeline_request */
    16,   /* 50: of_bsn_header */
    -1,   /* 51: of_bsn_hybrid_get_reply */
    -1,   /* 52: of_bsn_hybrid_get_request */
    -1,   /* 53: of_bsn_lacp_convergence_notif */
    -1,   /* 54: of_bsn_lacp_stats_reply */
    -1,   /* 55: of_bsn_lacp_stats_request */
    25,   /* 56: of_bsn_pdu_rx_reply */
    28,   /* 57: of_bsn_pdu_rx_request */
    21,   /* 58: of_bsn_pdu_rx_timeout */
    25,   /* 59: of_bsn_pdu_tx_reply */
    28,   /* 60: of_bsn_pdu_tx_request */
    -1,   /* 61: of_bsn_port_counter_stats_reply */
    -1,   /* 62: of_bsn_port_counter_stats_request */
    -1,   /* 63: of_bsn_role_status */
    -1,   /* 64: of_bsn_set_ip_mask */
    -1,   /* 65: of_bsn_set_l2_table_reply */
    -1,   /* 66: of_bsn_set_l2_table_request */
    -1,   /* 67: of_bsn_set_lacp_reply */
    -1,   /* 68: of_bsn_set_lacp_request */
    20,   /* 69: of_bsn_set_mirroring */
    20,   /* 70: of_bsn_set_pktin_suppression_reply */
    32,   /* 71: of_bsn_set_pktin_suppression_request */
    -1,   /* 72: of_bsn_set_switch_pipeline_reply */
    -1,   /* 73: of_bsn_set_switch_pipeline_request */
    -1,   /* 74: of_bsn_shell_command */
    -1,   /* 75: of_bsn_shell_output */
    -1,   /* 76: of_bsn_shell_status */
    24,   /* 77: of_bsn_stats_reply */
    24,   /* 78: of_bsn_stats_request */
    -1,   /* 79: of_bsn_switch_pipeline_stats_reply */
    -1,   /* 80: of_bsn_switch_pipeline_stats_request */
    -1,   /* 81: of_bsn_time_reply */
    -1,   /* 82: of_bsn_time_request */
    24,   /* 83: of_bsn_virtual_port_create_reply */
    48,   /* 84: of_bsn_virtual_port_create_request */
    20,   /* 85: of_bsn_virtual_port_remove_reply */
    20,   /* 86: of_bsn_virtual_port_remove_request */
    -1,   /* 87: of_bsn_vlan_counter_stats_reply */
    -1,   /* 88: of_bsn_vlan_counter_stats_request */
    1072, /* 89: of_desc_stats_reply */
    16,   /* 90: of_desc_stats_request */
    8,    /* 91: of_echo_reply */
    8,    /* 92: of_echo_request */
    10,   /* 93: of_error_msg */
    16,   /* 94: of_experimenter */
    16,   /* 95: of_experimenter_error_msg */
    24,   /* 96: of_experimenter_stats_reply */
    24,   /* 97: of_experimenter_stats_request */
    32,   /* 98: of_features_reply */
    8,    /* 99: of_features_request */
    56,   /* 100: of_flow_add */
    56,   /* 101: of_flow_delete */
    56,   /* 102: of_flow_delete_strict */
    56,   /* 103: of_flow_mod */
    12,   /* 104: of_flow_mod_failed_error_msg */
    56,   /* 105: of_flow_modify */
    56,   /* 106: of_flow_modify_strict */
    56,   /* 107: of_flow_removed */
    16,   /* 108: of_flow_stats_reply */
    56,   /* 109: of_flow_stats_request */
    12,   /* 110: of_get_config_reply */
    8,    /* 111: of_get_config_request */
    16,   /* 112: of_group_add */
    16,   /* 113: of_group_delete */
    16,   /* 114: of_group_desc_stats_reply */
    16,   /* 115: of_group_desc_stats_request */
    56,   /* 116: of_group_features_stats_reply */
    16,   /* 117: of_group_features_stats_request */
    16,   /* 118: of_group_mod */
    12,   /* 119: of_group_mod_failed_error_msg */
    16,   /* 120: of_group_modify */
    16,   /* 121: of_group_stats_reply */
    24,   /* 122: of_group_stats_request */
    8,    /* 123: of_hello */
    12,   /* 124: of_hello_failed_error_msg */
    -1,   /* 125: of_meter_config_stats_reply */
    -1,   /* 126: of_meter_config_stats_request */
    -1,   /* 127: of_meter_features_stats_reply */
    -1,   /* 128: of_meter_features_stats_request */
    -1,   /* 129: of_meter_mod */
    -1,   /* 130: of_meter_mod_failed_error_msg */
    -1,   /* 131: of_meter_stats_reply */
    -1,   /* 132: of_meter_stats_request */
    -1,   /* 133: of_nicira_controller_role_reply */
    -1,   /* 134: of_nicira_controller_role_request */
    16,   /* 135: of_nicira_header */
    24,   /* 136: of_packet_in */
    24,   /* 137: of_packet_out */
    -1,   /* 138: of_port_desc_stats_reply */
    -1,   /* 139: of_port_desc_stats_request */
    40,   /* 140: of_port_mod */
    12,   /* 141: of_port_mod_failed_error_msg */
    16,   /* 142: of_port_stats_reply */
    24,   /* 143: of_port_stats_request */
    80,   /* 144: of_port_status */
    16,   /* 145: of_queue_get_config_reply */
    16,   /* 146: of_queue_get_config_request */
    12,   /* 147: of_queue_op_failed_error_msg */
    16,   /* 148: of_queue_stats_reply */
    24,   /* 149: of_queue_stats_request */
    24,   /* 150: of_role_reply */
    24,   /* 151: of_role_request */
    12,   /* 152: of_role_request_failed_error_msg */
    12,   /* 153: of_set_config */
    16,   /* 154: of_stats_reply */
    16,   /* 155: of_stats_request */
    12,   /* 156: of_switch_config_failed_error_msg */
    -1,   /* 157: of_table_features_failed_error_msg */
    -1,   /* 158: of_table_features_stats_reply */
    -1,   /* 159: of_table_features_stats_request */
    16,   /* 160: of_table_mod */
    12,   /* 161: of_table_mod_failed_error_msg */
    16,   /* 162: of_table_stats_reply */
    16,   /* 163: of_table_stats_request */
    8,    /* 164: of_action */
    16,   /* 165: of_action_bsn */
    24,   /* 166: of_action_bsn_mirror */
    16,   /* 167: of_action_bsn_set_tunnel_dst */
    8,    /* 168: of_action_copy_ttl_in */
    8,    /* 169: of_action_copy_ttl_out */
    8,    /* 170: of_action_dec_mpls_ttl */
    8,    /* 171: of_action_dec_nw_ttl */
    -1,   /* 172: of_action_enqueue */
    8,    /* 173: of_action_experimenter */
    8,    /* 174: of_action_group */
    8,    /* 175: of_action_header */
    -1,   /* 176: of_action_id */
    -1,   /* 177: of_action_id_bsn */
    -1,   /* 178: of_action_id_bsn_mirror */
    -1,   /* 179: of_action_id_bsn_set_tunnel_dst */
    -1,   /* 180: of_action_id_copy_ttl_in */
    -1,   /* 181: of_action_id_copy_ttl_out */
    -1,   /* 182: of_action_id_dec_mpls_ttl */
    -1,   /* 183: of_action_id_dec_nw_ttl */
    -1,   /* 184: of_action_id_experimenter */
    -1,   /* 185: of_action_id_group */
    -1,   /* 186: of_action_id_header */
    -1,   /* 187: of_action_id_nicira */
    -1,   /* 188: of_action_id_nicira_dec_ttl */
    -1,   /* 189: of_action_id_output */
    -1,   /* 190: of_action_id_pop_mpls */
    -1,   /* 191: of_action_id_pop_pbb */
    -1,   /* 192: of_action_id_pop_vlan */
    -1,   /* 193: of_action_id_push_mpls */
    -1,   /* 194: of_action_id_push_pbb */
    -1,   /* 195: of_action_id_push_vlan */
    -1,   /* 196: of_action_id_set_field */
    -1,   /* 197: of_action_id_set_mpls_ttl */
    -1,   /* 198: of_action_id_set_nw_ttl */
    -1,   /* 199: of_action_id_set_queue */
    16,   /* 200: of_action_nicira */
    16,   /* 201: of_action_nicira_dec_ttl */
    16,   /* 202: of_action_output */
    8,    /* 203: of_action_pop_mpls */
    -1,   /* 204: of_action_pop_pbb */
    8,    /* 205: of_action_pop_vlan */
    8,    /* 206: of_action_push_mpls */
    -1,   /* 207: of_action_push_pbb */
    8,    /* 208: of_action_push_vlan */
    -1,   /* 209: of_action_set_dl_dst */
    -1,   /* 210: of_action_set_dl_src */
    4,    /* 211: of_action_set_field */
    -1,   /* 212: of_action_set_mpls_label */
    -1,   /* 213: of_action_set_mpls_tc */
    8,    /* 214: of_action_set_mpls_ttl */
    -1,   /* 215: of_action_set_nw_dst */
    -1,   /* 216: of_action_set_nw_ecn */
    -1,   /* 217: of_action_set_nw_src */
    -1,   /* 218: of_action_set_nw_tos */
    8,    /* 219: of_action_set_nw_ttl */
    8,    /* 220: of_action_set_queue */
    -1,   /* 221: of_action_set_tp_dst */
    -1,   /* 222: of_action_set_tp_src */
    -1,   /* 223: of_action_set_vlan_pcp */
    -1,   /* 224: of_action_set_vlan_vid */
    -1,   /* 225: of_action_strip_vlan */
    -1,   /* 226: of_bsn_controller_connection */
    -1,   /* 227: of_bsn_gentable_bucket_stats_entry */
    -1,   /* 228: of_bsn_gentable_desc_stats_entry */
    -1,   /* 229: of_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 230: of_bsn_gentable_entry_stats_entry */
    -1,   /* 231: of_bsn_gentable_stats_entry */
    32,   /* 232: of_bsn_interface */
    -1,   /* 233: of_bsn_lacp_stats_entry */
    -1,   /* 234: of_bsn_port_counter_stats_entry */
    -1,   /* 235: of_bsn_switch_pipeline_stats_entry */
    -1,   /* 236: of_bsn_tlv */
    -1,   /* 237: of_bsn_tlv_header */
    -1,   /* 238: of_bsn_tlv_idle_notification */
    -1,   /* 239: of_bsn_tlv_idle_time */
    -1,   /* 240: of_bsn_tlv_ipv4 */
    -1,   /* 241: of_bsn_tlv_mac */
    -1,   /* 242: of_bsn_tlv_port */
    -1,   /* 243: of_bsn_tlv_rx_packets */
    -1,   /* 244: of_bsn_tlv_tx_packets */
    -1,   /* 245: of_bsn_tlv_vlan_vid */
    -1,   /* 246: of_bsn_vlan_counter_stats_entry */
    4,    /* 247: of_bsn_vport */
    4,    /* 248: of_bsn_vport_header */
    32,   /* 249: of_bsn_vport_q_in_q */
    16,   /* 250: of_bucket */
    16,   /* 251: of_bucket_counter */
    -1,   /* 252: of_experimenter_stats_header */
    56,   /* 253: of_flow_stats_entry */
    8,    /* 254: of_group_desc_stats_entry */
    32,   /* 255: of_group_stats_entry */
    8,    /* 256: of_header */
    -1,   /* 257: of_hello_elem */
    -1,   /* 258: of_hello_elem_header */
    -1,   /* 259: of_hello_elem_versionbitmap */
    8,    /* 260: of_instruction */
    8,    /* 261: of_instruction_apply_actions */
    -1,   /* 262: of_instruction_bsn */
    -1,   /* 263: of_instruction_bsn_disable_src_mac_check */
    8,    /* 264: of_instruction_clear_actions */
    8,    /* 265: of_instruction_experimenter */
    8,    /* 266: of_instruction_goto_table */
    8,    /* 267: of_instruction_header */
    -1,   /* 268: of_instruction_id */
    -1,   /* 269: of_instruction_id_apply_actions */
    -1,   /* 270: of_instruction_id_bsn */
    -1,   /* 271: of_instruction_id_bsn_disable_src_mac_check */
    -1,   /* 272: of_instruction_id_clear_actions */
    -1,   /* 273: of_instruction_id_experimenter */
    -1,   /* 274: of_instruction_id_goto_table */
    -1,   /* 275: of_instruction_id_header */
    -1,   /* 276: of_instruction_id_meter */
    -1,   /* 277: of_instruction_id_write_actions */
    -1,   /* 278: of_instruction_id_write_metadata */
    -1,   /* 279: of_instruction_meter */
    8,    /* 280: of_instruction_write_actions */
    24,   /* 281: of_instruction_write_metadata */
    -1,   /* 282: of_match_v1 */
    -1,   /* 283: of_match_v2 */
    4,    /* 284: of_match_v3 */
    -1,   /* 285: of_meter_band */
    -1,   /* 286: of_meter_band_drop */
    -1,   /* 287: of_meter_band_dscp_remark */
    -1,   /* 288: of_meter_band_experimenter */
    -1,   /* 289: of_meter_band_header */
    -1,   /* 290: of_meter_band_stats */
    -1,   /* 291: of_meter_config */
    -1,   /* 292: of_meter_features */
    -1,   /* 293: of_meter_stats */
    4,    /* 294: of_oxm */
    6,    /* 295: of_oxm_arp_op */
    8,    /* 296: of_oxm_arp_op_masked */
    10,   /* 297: of_oxm_arp_sha */
    16,   /* 298: of_oxm_arp_sha_masked */
    8,    /* 299: of_oxm_arp_spa */
    12,   /* 300: of_oxm_arp_spa_masked */
    10,   /* 301: of_oxm_arp_tha */
    16,   /* 302: of_oxm_arp_tha_masked */
    8,    /* 303: of_oxm_arp_tpa */
    12,   /* 304: of_oxm_arp_tpa_masked */
    5,    /* 305: of_oxm_bsn_global_vrf_allowed */
    6,    /* 306: of_oxm_bsn_global_vrf_allowed_masked */
    20,   /* 307: of_oxm_bsn_in_ports_128 */
    36,   /* 308: of_oxm_bsn_in_ports_128_masked */
    8,    /* 309: of_oxm_bsn_l3_dst_class_id */
    12,   /* 310: of_oxm_bsn_l3_dst_class_id_masked */
    8,    /* 311: of_oxm_bsn_l3_interface_class_id */
    12,   /* 312: of_oxm_bsn_l3_interface_class_id_masked */
    8,    /* 313: of_oxm_bsn_l3_src_class_id */
    12,   /* 314: of_oxm_bsn_l3_src_class_id_masked */
    8,    /* 315: of_oxm_bsn_lag_id */
    12,   /* 316: of_oxm_bsn_lag_id_masked */
    8,    /* 317: of_oxm_bsn_vrf */
    12,   /* 318: of_oxm_bsn_vrf_masked */
    10,   /* 319: of_oxm_eth_dst */
    16,   /* 320: of_oxm_eth_dst_masked */
    10,   /* 321: of_oxm_eth_src */
    16,   /* 322: of_oxm_eth_src_masked */
    6,    /* 323: of_oxm_eth_type */
    8,    /* 324: of_oxm_eth_type_masked */
    4,    /* 325: of_oxm_header */
    5,    /* 326: of_oxm_icmpv4_code */
    6,    /* 327: of_oxm_icmpv4_code_masked */
    5,    /* 328: of_oxm_icmpv4_type */
    6,    /* 329: of_oxm_icmpv4_type_masked */
    5,    /* 330: of_oxm_icmpv6_code */
    6,    /* 331: of_oxm_icmpv6_code_masked */
    5,    /* 332: of_oxm_icmpv6_type */
    6,    /* 333: of_oxm_icmpv6_type_masked */
    8,    /* 334: of_oxm_in_phy_port */
    12,   /* 335: of_oxm_in_phy_port_masked */
    8,    /* 336: of_oxm_in_port */
    12,   /* 337: of_oxm_in_port_masked */
    5,    /* 338: of_oxm_ip_dscp */
    6,    /* 339: of_oxm_ip_dscp_masked */
    5,    /* 340: of_oxm_ip_ecn */
    6,    /* 341: of_oxm_ip_ecn_masked */
    5,    /* 342: of_oxm_ip_proto */
    6,    /* 343: of_oxm_ip_proto_masked */
    8,    /* 344: of_oxm_ipv4_dst */
    12,   /* 345: of_oxm_ipv4_dst_masked */
    8,    /* 346: of_oxm_ipv4_src */
    12,   /* 347: of_oxm_ipv4_src_masked */
    20,   /* 348: of_oxm_ipv6_dst */
    36,   /* 349: of_oxm_ipv6_dst_masked */
    8,    /* 350: of_oxm_ipv6_flabel */
    12,   /* 351: of_oxm_ipv6_flabel_masked */
    10,   /* 352: of_oxm_ipv6_nd_sll */
    16,   /* 353: of_oxm_ipv6_nd_sll_masked */
    20,   /* 354: of_oxm_ipv6_nd_target */
    36,   /* 355: of_oxm_ipv6_nd_target_masked */
    10,   /* 356: of_oxm_ipv6_nd_tll */
    16,   /* 357: of_oxm_ipv6_nd_tll_masked */
    20,   /* 358: of_oxm_ipv6_src */
    36,   /* 359: of_oxm_ipv6_src_masked */
    12,   /* 360: of_oxm_metadata */
    20,   /* 361: of_oxm_metadata_masked */
    8,    /* 362: of_oxm_mpls_label */
    12,   /* 363: of_oxm_mpls_label_masked */
    5,    /* 364: of_oxm_mpls_tc */
    6,    /* 365: of_oxm_mpls_tc_masked */
    6,    /* 366: of_oxm_sctp_dst */
    8,    /* 367: of_oxm_sctp_dst_masked */
    6,    /* 368: of_oxm_sctp_src */
    8,    /* 369: of_oxm_sctp_src_masked */
    6,    /* 370: of_oxm_tcp_dst */
    8,    /* 371: of_oxm_tcp_dst_masked */
    6,    /* 372: of_oxm_tcp_src */
    8,    /* 373: of_oxm_tcp_src_masked */
    6,    /* 374: of_oxm_udp_dst */
    8,    /* 375: of_oxm_udp_dst_masked */
    6,    /* 376: of_oxm_udp_src */
    8,    /* 377: of_oxm_udp_src_masked */
    5,    /* 378: of_oxm_vlan_pcp */
    6,    /* 379: of_oxm_vlan_pcp_masked */
    6,    /* 380: of_oxm_vlan_vid */
    8,    /* 381: of_oxm_vlan_vid_masked */
    16,   /* 382: of_packet_queue */
    64,   /* 383: of_port_desc */
    104,  /* 384: of_port_stats_entry */
    8,    /* 385: of_queue_prop */
    16,   /* 386: of_queue_prop_experimenter */
    8,    /* 387: of_queue_prop_header */
    16,   /* 388: of_queue_prop_max_rate */
    16,   /* 389: of_queue_prop_min_rate */
    32,   /* 390: of_queue_stats_entry */
    -1,   /* 391: of_table_feature_prop */
    -1,   /* 392: of_table_feature_prop_apply_actions */
    -1,   /* 393: of_table_feature_prop_apply_actions_miss */
    -1,   /* 394: of_table_feature_prop_apply_setfield */
    -1,   /* 395: of_table_feature_prop_apply_setfield_miss */
    -1,   /* 396: of_table_feature_prop_experimenter */
    -1,   /* 397: of_table_feature_prop_header */
    -1,   /* 398: of_table_feature_prop_instructions */
    -1,   /* 399: of_table_feature_prop_instructions_miss */
    -1,   /* 400: of_table_feature_prop_match */
    -1,   /* 401: of_table_feature_prop_next_tables */
    -1,   /* 402: of_table_feature_prop_next_tables_miss */
    -1,   /* 403: of_table_feature_prop_wildcards */
    -1,   /* 404: of_table_feature_prop_write_actions */
    -1,   /* 405: of_table_feature_prop_write_actions_miss */
    -1,   /* 406: of_table_feature_prop_write_setfield */
    -1,   /* 407: of_table_feature_prop_write_setfield_miss */
    -1,   /* 408: of_table_features */
    128,  /* 409: of_table_stats_entry */
    -1,   /* 410: of_uint32 */
    -1,   /* 411: of_uint64 */
    -1,   /* 412: of_uint8 */
    0,    /* 413: of_list_action */
    -1,   /* 414: of_list_action_id */
    -1,   /* 415: of_list_bsn_controller_connection */
    -1,   /* 416: of_list_bsn_gentable_bucket_stats_entry */
    -1,   /* 417: of_list_bsn_gentable_desc_stats_entry */
    -1,   /* 418: of_list_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 419: of_list_bsn_gentable_entry_stats_entry */
    -1,   /* 420: of_list_bsn_gentable_stats_entry */
    0,    /* 421: of_list_bsn_interface */
    -1,   /* 422: of_list_bsn_lacp_stats_entry */
    -1,   /* 423: of_list_bsn_port_counter_stats_entry */
    -1,   /* 424: of_list_bsn_switch_pipeline_stats_entry */
    -1,   /* 425: of_list_bsn_tlv */
    -1,   /* 426: of_list_bsn_vlan_counter_stats_entry */
    0,    /* 427: of_list_bucket */
    0,    /* 428: of_list_bucket_counter */
    0,    /* 429: of_list_flow_stats_entry */
    0,    /* 430: of_list_group_desc_stats_entry */
    0,    /* 431: of_list_group_stats_entry */
    -1,   /* 432: of_list_hello_elem */
    0,    /* 433: of_list_instruction */
    -1,   /* 434: of_list_meter_band */
    -1,   /* 435: of_list_meter_band_stats */
    -1,   /* 436: of_list_meter_stats */
    0,    /* 437: of_list_oxm */
    0,    /* 438: of_list_packet_queue */
    0,    /* 439: of_list_port_desc */
    0,    /* 440: of_list_port_stats_entry */
    0,    /* 441: of_list_queue_prop */
    0,    /* 442: of_list_queue_stats_entry */
    -1,   /* 443: of_list_table_feature_prop */
    -1,   /* 444: of_list_table_features */
    0,    /* 445: of_list_table_stats_entry */
    -1,   /* 446: of_list_uint32 */
    -1,   /* 447: of_list_uint64 */
    -1    /* 448: of_list_uint8 */
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
    20,   /* 12: of_bsn_bw_clear_data_reply */
    16,   /* 13: of_bsn_bw_clear_data_request */
    20,   /* 14: of_bsn_bw_enable_get_reply */
    16,   /* 15: of_bsn_bw_enable_get_request */
    24,   /* 16: of_bsn_bw_enable_set_reply */
    20,   /* 17: of_bsn_bw_enable_set_request */
    16,   /* 18: of_bsn_controller_connections_reply */
    16,   /* 19: of_bsn_controller_connections_request */
    40,   /* 20: of_bsn_flow_idle */
    20,   /* 21: of_bsn_flow_idle_enable_get_reply */
    16,   /* 22: of_bsn_flow_idle_enable_get_request */
    24,   /* 23: of_bsn_flow_idle_enable_set_reply */
    20,   /* 24: of_bsn_flow_idle_enable_set_request */
    24,   /* 25: of_bsn_gentable_bucket_stats_reply */
    26,   /* 26: of_bsn_gentable_bucket_stats_request */
    28,   /* 27: of_bsn_gentable_clear_reply */
    52,   /* 28: of_bsn_gentable_clear_request */
    24,   /* 29: of_bsn_gentable_desc_stats_reply */
    24,   /* 30: of_bsn_gentable_desc_stats_request */
    36,   /* 31: of_bsn_gentable_entry_add */
    18,   /* 32: of_bsn_gentable_entry_delete */
    24,   /* 33: of_bsn_gentable_entry_desc_stats_reply */
    60,   /* 34: of_bsn_gentable_entry_desc_stats_request */
    24,   /* 35: of_bsn_gentable_entry_stats_reply */
    60,   /* 36: of_bsn_gentable_entry_stats_request */
    24,   /* 37: of_bsn_gentable_set_buckets_size */
    24,   /* 38: of_bsn_gentable_stats_reply */
    24,   /* 39: of_bsn_gentable_stats_request */
    16,   /* 40: of_bsn_get_interfaces_reply */
    16,   /* 41: of_bsn_get_interfaces_request */
    -1,   /* 42: of_bsn_get_ip_mask_reply */
    -1,   /* 43: of_bsn_get_ip_mask_request */
    -1,   /* 44: of_bsn_get_l2_table_reply */
    -1,   /* 45: of_bsn_get_l2_table_request */
    20,   /* 46: of_bsn_get_mirroring_reply */
    20,   /* 47: of_bsn_get_mirroring_request */
    272,  /* 48: of_bsn_get_switch_pipeline_reply */
    16,   /* 49: of_bsn_get_switch_pipeline_request */
    16,   /* 50: of_bsn_header */
    -1,   /* 51: of_bsn_hybrid_get_reply */
    -1,   /* 52: of_bsn_hybrid_get_request */
    52,   /* 53: of_bsn_lacp_convergence_notif */
    24,   /* 54: of_bsn_lacp_stats_reply */
    24,   /* 55: of_bsn_lacp_stats_request */
    25,   /* 56: of_bsn_pdu_rx_reply */
    28,   /* 57: of_bsn_pdu_rx_request */
    21,   /* 58: of_bsn_pdu_rx_timeout */
    25,   /* 59: of_bsn_pdu_tx_reply */
    28,   /* 60: of_bsn_pdu_tx_request */
    24,   /* 61: of_bsn_port_counter_stats_reply */
    28,   /* 62: of_bsn_port_counter_stats_request */
    32,   /* 63: of_bsn_role_status */
    -1,   /* 64: of_bsn_set_ip_mask */
    -1,   /* 65: of_bsn_set_l2_table_reply */
    -1,   /* 66: of_bsn_set_l2_table_request */
    24,   /* 67: of_bsn_set_lacp_reply */
    38,   /* 68: of_bsn_set_lacp_request */
    20,   /* 69: of_bsn_set_mirroring */
    20,   /* 70: of_bsn_set_pktin_suppression_reply */
    32,   /* 71: of_bsn_set_pktin_suppression_request */
    20,   /* 72: of_bsn_set_switch_pipeline_reply */
    272,  /* 73: of_bsn_set_switch_pipeline_request */
    -1,   /* 74: of_bsn_shell_command */
    -1,   /* 75: of_bsn_shell_output */
    -1,   /* 76: of_bsn_shell_status */
    24,   /* 77: of_bsn_stats_reply */
    24,   /* 78: of_bsn_stats_request */
    24,   /* 79: of_bsn_switch_pipeline_stats_reply */
    24,   /* 80: of_bsn_switch_pipeline_stats_request */
    24,   /* 81: of_bsn_time_reply */
    16,   /* 82: of_bsn_time_request */
    24,   /* 83: of_bsn_virtual_port_create_reply */
    48,   /* 84: of_bsn_virtual_port_create_request */
    20,   /* 85: of_bsn_virtual_port_remove_reply */
    20,   /* 86: of_bsn_virtual_port_remove_request */
    24,   /* 87: of_bsn_vlan_counter_stats_reply */
    26,   /* 88: of_bsn_vlan_counter_stats_request */
    1072, /* 89: of_desc_stats_reply */
    16,   /* 90: of_desc_stats_request */
    8,    /* 91: of_echo_reply */
    8,    /* 92: of_echo_request */
    10,   /* 93: of_error_msg */
    16,   /* 94: of_experimenter */
    16,   /* 95: of_experimenter_error_msg */
    24,   /* 96: of_experimenter_stats_reply */
    24,   /* 97: of_experimenter_stats_request */
    32,   /* 98: of_features_reply */
    8,    /* 99: of_features_request */
    56,   /* 100: of_flow_add */
    56,   /* 101: of_flow_delete */
    56,   /* 102: of_flow_delete_strict */
    56,   /* 103: of_flow_mod */
    12,   /* 104: of_flow_mod_failed_error_msg */
    56,   /* 105: of_flow_modify */
    56,   /* 106: of_flow_modify_strict */
    56,   /* 107: of_flow_removed */
    16,   /* 108: of_flow_stats_reply */
    56,   /* 109: of_flow_stats_request */
    12,   /* 110: of_get_config_reply */
    8,    /* 111: of_get_config_request */
    16,   /* 112: of_group_add */
    16,   /* 113: of_group_delete */
    16,   /* 114: of_group_desc_stats_reply */
    16,   /* 115: of_group_desc_stats_request */
    56,   /* 116: of_group_features_stats_reply */
    16,   /* 117: of_group_features_stats_request */
    16,   /* 118: of_group_mod */
    12,   /* 119: of_group_mod_failed_error_msg */
    16,   /* 120: of_group_modify */
    16,   /* 121: of_group_stats_reply */
    24,   /* 122: of_group_stats_request */
    8,    /* 123: of_hello */
    12,   /* 124: of_hello_failed_error_msg */
    16,   /* 125: of_meter_config_stats_reply */
    24,   /* 126: of_meter_config_stats_request */
    32,   /* 127: of_meter_features_stats_reply */
    16,   /* 128: of_meter_features_stats_request */
    16,   /* 129: of_meter_mod */
    12,   /* 130: of_meter_mod_failed_error_msg */
    16,   /* 131: of_meter_stats_reply */
    24,   /* 132: of_meter_stats_request */
    -1,   /* 133: of_nicira_controller_role_reply */
    -1,   /* 134: of_nicira_controller_role_request */
    16,   /* 135: of_nicira_header */
    32,   /* 136: of_packet_in */
    24,   /* 137: of_packet_out */
    16,   /* 138: of_port_desc_stats_reply */
    16,   /* 139: of_port_desc_stats_request */
    40,   /* 140: of_port_mod */
    12,   /* 141: of_port_mod_failed_error_msg */
    16,   /* 142: of_port_stats_reply */
    24,   /* 143: of_port_stats_request */
    80,   /* 144: of_port_status */
    16,   /* 145: of_queue_get_config_reply */
    16,   /* 146: of_queue_get_config_request */
    12,   /* 147: of_queue_op_failed_error_msg */
    16,   /* 148: of_queue_stats_reply */
    24,   /* 149: of_queue_stats_request */
    24,   /* 150: of_role_reply */
    24,   /* 151: of_role_request */
    12,   /* 152: of_role_request_failed_error_msg */
    12,   /* 153: of_set_config */
    16,   /* 154: of_stats_reply */
    16,   /* 155: of_stats_request */
    12,   /* 156: of_switch_config_failed_error_msg */
    12,   /* 157: of_table_features_failed_error_msg */
    16,   /* 158: of_table_features_stats_reply */
    16,   /* 159: of_table_features_stats_request */
    16,   /* 160: of_table_mod */
    12,   /* 161: of_table_mod_failed_error_msg */
    16,   /* 162: of_table_stats_reply */
    16,   /* 163: of_table_stats_request */
    8,    /* 164: of_action */
    16,   /* 165: of_action_bsn */
    24,   /* 166: of_action_bsn_mirror */
    16,   /* 167: of_action_bsn_set_tunnel_dst */
    8,    /* 168: of_action_copy_ttl_in */
    8,    /* 169: of_action_copy_ttl_out */
    8,    /* 170: of_action_dec_mpls_ttl */
    8,    /* 171: of_action_dec_nw_ttl */
    -1,   /* 172: of_action_enqueue */
    8,    /* 173: of_action_experimenter */
    8,    /* 174: of_action_group */
    8,    /* 175: of_action_header */
    8,    /* 176: of_action_id */
    16,   /* 177: of_action_id_bsn */
    15,   /* 178: of_action_id_bsn_mirror */
    12,   /* 179: of_action_id_bsn_set_tunnel_dst */
    8,    /* 180: of_action_id_copy_ttl_in */
    8,    /* 181: of_action_id_copy_ttl_out */
    8,    /* 182: of_action_id_dec_mpls_ttl */
    8,    /* 183: of_action_id_dec_nw_ttl */
    8,    /* 184: of_action_id_experimenter */
    4,    /* 185: of_action_id_group */
    8,    /* 186: of_action_id_header */
    16,   /* 187: of_action_id_nicira */
    16,   /* 188: of_action_id_nicira_dec_ttl */
    10,   /* 189: of_action_id_output */
    6,    /* 190: of_action_id_pop_mpls */
    8,    /* 191: of_action_id_pop_pbb */
    8,    /* 192: of_action_id_pop_vlan */
    6,    /* 193: of_action_id_push_mpls */
    6,    /* 194: of_action_id_push_pbb */
    6,    /* 195: of_action_id_push_vlan */
    4,    /* 196: of_action_id_set_field */
    7,    /* 197: of_action_id_set_mpls_ttl */
    7,    /* 198: of_action_id_set_nw_ttl */
    4,    /* 199: of_action_id_set_queue */
    16,   /* 200: of_action_nicira */
    16,   /* 201: of_action_nicira_dec_ttl */
    16,   /* 202: of_action_output */
    8,    /* 203: of_action_pop_mpls */
    8,    /* 204: of_action_pop_pbb */
    8,    /* 205: of_action_pop_vlan */
    8,    /* 206: of_action_push_mpls */
    8,    /* 207: of_action_push_pbb */
    8,    /* 208: of_action_push_vlan */
    -1,   /* 209: of_action_set_dl_dst */
    -1,   /* 210: of_action_set_dl_src */
    4,    /* 211: of_action_set_field */
    -1,   /* 212: of_action_set_mpls_label */
    -1,   /* 213: of_action_set_mpls_tc */
    8,    /* 214: of_action_set_mpls_ttl */
    -1,   /* 215: of_action_set_nw_dst */
    -1,   /* 216: of_action_set_nw_ecn */
    -1,   /* 217: of_action_set_nw_src */
    -1,   /* 218: of_action_set_nw_tos */
    8,    /* 219: of_action_set_nw_ttl */
    8,    /* 220: of_action_set_queue */
    -1,   /* 221: of_action_set_tp_dst */
    -1,   /* 222: of_action_set_tp_src */
    -1,   /* 223: of_action_set_vlan_pcp */
    -1,   /* 224: of_action_set_vlan_vid */
    -1,   /* 225: of_action_strip_vlan */
    264,  /* 226: of_bsn_controller_connection */
    16,   /* 227: of_bsn_gentable_bucket_stats_entry */
    48,   /* 228: of_bsn_gentable_desc_stats_entry */
    20,   /* 229: of_bsn_gentable_entry_desc_stats_entry */
    4,    /* 230: of_bsn_gentable_entry_stats_entry */
    24,   /* 231: of_bsn_gentable_stats_entry */
    32,   /* 232: of_bsn_interface */
    36,   /* 233: of_bsn_lacp_stats_entry */
    8,    /* 234: of_bsn_port_counter_stats_entry */
    256,  /* 235: of_bsn_switch_pipeline_stats_entry */
    4,    /* 236: of_bsn_tlv */
    4,    /* 237: of_bsn_tlv_header */
    4,    /* 238: of_bsn_tlv_idle_notification */
    12,   /* 239: of_bsn_tlv_idle_time */
    8,    /* 240: of_bsn_tlv_ipv4 */
    10,   /* 241: of_bsn_tlv_mac */
    8,    /* 242: of_bsn_tlv_port */
    12,   /* 243: of_bsn_tlv_rx_packets */
    12,   /* 244: of_bsn_tlv_tx_packets */
    6,    /* 245: of_bsn_tlv_vlan_vid */
    8,    /* 246: of_bsn_vlan_counter_stats_entry */
    4,    /* 247: of_bsn_vport */
    4,    /* 248: of_bsn_vport_header */
    32,   /* 249: of_bsn_vport_q_in_q */
    16,   /* 250: of_bucket */
    16,   /* 251: of_bucket_counter */
    8,    /* 252: of_experimenter_stats_header */
    56,   /* 253: of_flow_stats_entry */
    8,    /* 254: of_group_desc_stats_entry */
    40,   /* 255: of_group_stats_entry */
    8,    /* 256: of_header */
    4,    /* 257: of_hello_elem */
    4,    /* 258: of_hello_elem_header */
    4,    /* 259: of_hello_elem_versionbitmap */
    4,    /* 260: of_instruction */
    8,    /* 261: of_instruction_apply_actions */
    16,   /* 262: of_instruction_bsn */
    16,   /* 263: of_instruction_bsn_disable_src_mac_check */
    8,    /* 264: of_instruction_clear_actions */
    8,    /* 265: of_instruction_experimenter */
    8,    /* 266: of_instruction_goto_table */
    4,    /* 267: of_instruction_header */
    4,    /* 268: of_instruction_id */
    8,    /* 269: of_instruction_id_apply_actions */
    16,   /* 270: of_instruction_id_bsn */
    16,   /* 271: of_instruction_id_bsn_disable_src_mac_check */
    8,    /* 272: of_instruction_id_clear_actions */
    8,    /* 273: of_instruction_id_experimenter */
    7,    /* 274: of_instruction_id_goto_table */
    4,    /* 275: of_instruction_id_header */
    4,    /* 276: of_instruction_id_meter */
    8,    /* 277: of_instruction_id_write_actions */
    8,    /* 278: of_instruction_id_write_metadata */
    8,    /* 279: of_instruction_meter */
    8,    /* 280: of_instruction_write_actions */
    24,   /* 281: of_instruction_write_metadata */
    -1,   /* 282: of_match_v1 */
    -1,   /* 283: of_match_v2 */
    4,    /* 284: of_match_v3 */
    4,    /* 285: of_meter_band */
    16,   /* 286: of_meter_band_drop */
    16,   /* 287: of_meter_band_dscp_remark */
    16,   /* 288: of_meter_band_experimenter */
    4,    /* 289: of_meter_band_header */
    16,   /* 290: of_meter_band_stats */
    8,    /* 291: of_meter_config */
    16,   /* 292: of_meter_features */
    40,   /* 293: of_meter_stats */
    4,    /* 294: of_oxm */
    6,    /* 295: of_oxm_arp_op */
    8,    /* 296: of_oxm_arp_op_masked */
    10,   /* 297: of_oxm_arp_sha */
    16,   /* 298: of_oxm_arp_sha_masked */
    8,    /* 299: of_oxm_arp_spa */
    12,   /* 300: of_oxm_arp_spa_masked */
    10,   /* 301: of_oxm_arp_tha */
    16,   /* 302: of_oxm_arp_tha_masked */
    8,    /* 303: of_oxm_arp_tpa */
    12,   /* 304: of_oxm_arp_tpa_masked */
    5,    /* 305: of_oxm_bsn_global_vrf_allowed */
    6,    /* 306: of_oxm_bsn_global_vrf_allowed_masked */
    20,   /* 307: of_oxm_bsn_in_ports_128 */
    36,   /* 308: of_oxm_bsn_in_ports_128_masked */
    8,    /* 309: of_oxm_bsn_l3_dst_class_id */
    12,   /* 310: of_oxm_bsn_l3_dst_class_id_masked */
    8,    /* 311: of_oxm_bsn_l3_interface_class_id */
    12,   /* 312: of_oxm_bsn_l3_interface_class_id_masked */
    8,    /* 313: of_oxm_bsn_l3_src_class_id */
    12,   /* 314: of_oxm_bsn_l3_src_class_id_masked */
    8,    /* 315: of_oxm_bsn_lag_id */
    12,   /* 316: of_oxm_bsn_lag_id_masked */
    8,    /* 317: of_oxm_bsn_vrf */
    12,   /* 318: of_oxm_bsn_vrf_masked */
    10,   /* 319: of_oxm_eth_dst */
    16,   /* 320: of_oxm_eth_dst_masked */
    10,   /* 321: of_oxm_eth_src */
    16,   /* 322: of_oxm_eth_src_masked */
    6,    /* 323: of_oxm_eth_type */
    8,    /* 324: of_oxm_eth_type_masked */
    4,    /* 325: of_oxm_header */
    5,    /* 326: of_oxm_icmpv4_code */
    6,    /* 327: of_oxm_icmpv4_code_masked */
    5,    /* 328: of_oxm_icmpv4_type */
    6,    /* 329: of_oxm_icmpv4_type_masked */
    5,    /* 330: of_oxm_icmpv6_code */
    6,    /* 331: of_oxm_icmpv6_code_masked */
    5,    /* 332: of_oxm_icmpv6_type */
    6,    /* 333: of_oxm_icmpv6_type_masked */
    8,    /* 334: of_oxm_in_phy_port */
    12,   /* 335: of_oxm_in_phy_port_masked */
    8,    /* 336: of_oxm_in_port */
    12,   /* 337: of_oxm_in_port_masked */
    5,    /* 338: of_oxm_ip_dscp */
    6,    /* 339: of_oxm_ip_dscp_masked */
    5,    /* 340: of_oxm_ip_ecn */
    6,    /* 341: of_oxm_ip_ecn_masked */
    5,    /* 342: of_oxm_ip_proto */
    6,    /* 343: of_oxm_ip_proto_masked */
    8,    /* 344: of_oxm_ipv4_dst */
    12,   /* 345: of_oxm_ipv4_dst_masked */
    8,    /* 346: of_oxm_ipv4_src */
    12,   /* 347: of_oxm_ipv4_src_masked */
    20,   /* 348: of_oxm_ipv6_dst */
    36,   /* 349: of_oxm_ipv6_dst_masked */
    8,    /* 350: of_oxm_ipv6_flabel */
    12,   /* 351: of_oxm_ipv6_flabel_masked */
    10,   /* 352: of_oxm_ipv6_nd_sll */
    16,   /* 353: of_oxm_ipv6_nd_sll_masked */
    20,   /* 354: of_oxm_ipv6_nd_target */
    36,   /* 355: of_oxm_ipv6_nd_target_masked */
    10,   /* 356: of_oxm_ipv6_nd_tll */
    16,   /* 357: of_oxm_ipv6_nd_tll_masked */
    20,   /* 358: of_oxm_ipv6_src */
    36,   /* 359: of_oxm_ipv6_src_masked */
    12,   /* 360: of_oxm_metadata */
    20,   /* 361: of_oxm_metadata_masked */
    8,    /* 362: of_oxm_mpls_label */
    12,   /* 363: of_oxm_mpls_label_masked */
    5,    /* 364: of_oxm_mpls_tc */
    6,    /* 365: of_oxm_mpls_tc_masked */
    6,    /* 366: of_oxm_sctp_dst */
    8,    /* 367: of_oxm_sctp_dst_masked */
    6,    /* 368: of_oxm_sctp_src */
    8,    /* 369: of_oxm_sctp_src_masked */
    6,    /* 370: of_oxm_tcp_dst */
    8,    /* 371: of_oxm_tcp_dst_masked */
    6,    /* 372: of_oxm_tcp_src */
    8,    /* 373: of_oxm_tcp_src_masked */
    6,    /* 374: of_oxm_udp_dst */
    8,    /* 375: of_oxm_udp_dst_masked */
    6,    /* 376: of_oxm_udp_src */
    8,    /* 377: of_oxm_udp_src_masked */
    5,    /* 378: of_oxm_vlan_pcp */
    6,    /* 379: of_oxm_vlan_pcp_masked */
    6,    /* 380: of_oxm_vlan_vid */
    8,    /* 381: of_oxm_vlan_vid_masked */
    16,   /* 382: of_packet_queue */
    64,   /* 383: of_port_desc */
    112,  /* 384: of_port_stats_entry */
    8,    /* 385: of_queue_prop */
    16,   /* 386: of_queue_prop_experimenter */
    8,    /* 387: of_queue_prop_header */
    16,   /* 388: of_queue_prop_max_rate */
    16,   /* 389: of_queue_prop_min_rate */
    40,   /* 390: of_queue_stats_entry */
    4,    /* 391: of_table_feature_prop */
    4,    /* 392: of_table_feature_prop_apply_actions */
    4,    /* 393: of_table_feature_prop_apply_actions_miss */
    4,    /* 394: of_table_feature_prop_apply_setfield */
    4,    /* 395: of_table_feature_prop_apply_setfield_miss */
    12,   /* 396: of_table_feature_prop_experimenter */
    4,    /* 397: of_table_feature_prop_header */
    4,    /* 398: of_table_feature_prop_instructions */
    4,    /* 399: of_table_feature_prop_instructions_miss */
    4,    /* 400: of_table_feature_prop_match */
    4,    /* 401: of_table_feature_prop_next_tables */
    4,    /* 402: of_table_feature_prop_next_tables_miss */
    4,    /* 403: of_table_feature_prop_wildcards */
    4,    /* 404: of_table_feature_prop_write_actions */
    4,    /* 405: of_table_feature_prop_write_actions_miss */
    4,    /* 406: of_table_feature_prop_write_setfield */
    4,    /* 407: of_table_feature_prop_write_setfield_miss */
    64,   /* 408: of_table_features */
    24,   /* 409: of_table_stats_entry */
    4,    /* 410: of_uint32 */
    8,    /* 411: of_uint64 */
    1,    /* 412: of_uint8 */
    0,    /* 413: of_list_action */
    0,    /* 414: of_list_action_id */
    0,    /* 415: of_list_bsn_controller_connection */
    0,    /* 416: of_list_bsn_gentable_bucket_stats_entry */
    0,    /* 417: of_list_bsn_gentable_desc_stats_entry */
    0,    /* 418: of_list_bsn_gentable_entry_desc_stats_entry */
    0,    /* 419: of_list_bsn_gentable_entry_stats_entry */
    0,    /* 420: of_list_bsn_gentable_stats_entry */
    0,    /* 421: of_list_bsn_interface */
    0,    /* 422: of_list_bsn_lacp_stats_entry */
    0,    /* 423: of_list_bsn_port_counter_stats_entry */
    0,    /* 424: of_list_bsn_switch_pipeline_stats_entry */
    0,    /* 425: of_list_bsn_tlv */
    0,    /* 426: of_list_bsn_vlan_counter_stats_entry */
    0,    /* 427: of_list_bucket */
    0,    /* 428: of_list_bucket_counter */
    0,    /* 429: of_list_flow_stats_entry */
    0,    /* 430: of_list_group_desc_stats_entry */
    0,    /* 431: of_list_group_stats_entry */
    0,    /* 432: of_list_hello_elem */
    0,    /* 433: of_list_instruction */
    0,    /* 434: of_list_meter_band */
    0,    /* 435: of_list_meter_band_stats */
    0,    /* 436: of_list_meter_stats */
    0,    /* 437: of_list_oxm */
    0,    /* 438: of_list_packet_queue */
    0,    /* 439: of_list_port_desc */
    0,    /* 440: of_list_port_stats_entry */
    0,    /* 441: of_list_queue_prop */
    0,    /* 442: of_list_queue_stats_entry */
    0,    /* 443: of_list_table_feature_prop */
    0,    /* 444: of_list_table_features */
    0,    /* 445: of_list_table_stats_entry */
    0,    /* 446: of_list_uint32 */
    0,    /* 447: of_list_uint64 */
    0     /* 448: of_list_uint8 */
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
    0,    /* 12: of_bsn_bw_clear_data_reply */
    0,    /* 13: of_bsn_bw_clear_data_request */
    0,    /* 14: of_bsn_bw_enable_get_reply */
    0,    /* 15: of_bsn_bw_enable_get_request */
    0,    /* 16: of_bsn_bw_enable_set_reply */
    0,    /* 17: of_bsn_bw_enable_set_request */
    -1,   /* 18: of_bsn_controller_connections_reply */
    -1,   /* 19: of_bsn_controller_connections_request */
    -1,   /* 20: of_bsn_flow_idle */
    -1,   /* 21: of_bsn_flow_idle_enable_get_reply */
    -1,   /* 22: of_bsn_flow_idle_enable_get_request */
    -1,   /* 23: of_bsn_flow_idle_enable_set_reply */
    -1,   /* 24: of_bsn_flow_idle_enable_set_request */
    -1,   /* 25: of_bsn_gentable_bucket_stats_reply */
    -1,   /* 26: of_bsn_gentable_bucket_stats_request */
    -1,   /* 27: of_bsn_gentable_clear_reply */
    -1,   /* 28: of_bsn_gentable_clear_request */
    -1,   /* 29: of_bsn_gentable_desc_stats_reply */
    -1,   /* 30: of_bsn_gentable_desc_stats_request */
    -1,   /* 31: of_bsn_gentable_entry_add */
    -1,   /* 32: of_bsn_gentable_entry_delete */
    -1,   /* 33: of_bsn_gentable_entry_desc_stats_reply */
    -1,   /* 34: of_bsn_gentable_entry_desc_stats_request */
    -1,   /* 35: of_bsn_gentable_entry_stats_reply */
    -1,   /* 36: of_bsn_gentable_entry_stats_request */
    -1,   /* 37: of_bsn_gentable_set_buckets_size */
    -1,   /* 38: of_bsn_gentable_stats_reply */
    -1,   /* 39: of_bsn_gentable_stats_request */
    0,    /* 40: of_bsn_get_interfaces_reply */
    0,    /* 41: of_bsn_get_interfaces_request */
    0,    /* 42: of_bsn_get_ip_mask_reply */
    0,    /* 43: of_bsn_get_ip_mask_request */
    0,    /* 44: of_bsn_get_l2_table_reply */
    0,    /* 45: of_bsn_get_l2_table_request */
    0,    /* 46: of_bsn_get_mirroring_reply */
    0,    /* 47: of_bsn_get_mirroring_request */
    -1,   /* 48: of_bsn_get_switch_pipeline_reply */
    -1,   /* 49: of_bsn_get_switch_pipeline_request */
    0,    /* 50: of_bsn_header */
    0,    /* 51: of_bsn_hybrid_get_reply */
    0,    /* 52: of_bsn_hybrid_get_request */
    -1,   /* 53: of_bsn_lacp_convergence_notif */
    -1,   /* 54: of_bsn_lacp_stats_reply */
    -1,   /* 55: of_bsn_lacp_stats_request */
    0,    /* 56: of_bsn_pdu_rx_reply */
    0,    /* 57: of_bsn_pdu_rx_request */
    0,    /* 58: of_bsn_pdu_rx_timeout */
    0,    /* 59: of_bsn_pdu_tx_reply */
    0,    /* 60: of_bsn_pdu_tx_request */
    -1,   /* 61: of_bsn_port_counter_stats_reply */
    -1,   /* 62: of_bsn_port_counter_stats_request */
    -1,   /* 63: of_bsn_role_status */
    0,    /* 64: of_bsn_set_ip_mask */
    0,    /* 65: of_bsn_set_l2_table_reply */
    0,    /* 66: of_bsn_set_l2_table_request */
    -1,   /* 67: of_bsn_set_lacp_reply */
    -1,   /* 68: of_bsn_set_lacp_request */
    0,    /* 69: of_bsn_set_mirroring */
    0,    /* 70: of_bsn_set_pktin_suppression_reply */
    0,    /* 71: of_bsn_set_pktin_suppression_request */
    -1,   /* 72: of_bsn_set_switch_pipeline_reply */
    -1,   /* 73: of_bsn_set_switch_pipeline_request */
    0,    /* 74: of_bsn_shell_command */
    0,    /* 75: of_bsn_shell_output */
    0,    /* 76: of_bsn_shell_status */
    0,    /* 77: of_bsn_stats_reply */
    0,    /* 78: of_bsn_stats_request */
    -1,   /* 79: of_bsn_switch_pipeline_stats_reply */
    -1,   /* 80: of_bsn_switch_pipeline_stats_request */
    -1,   /* 81: of_bsn_time_reply */
    -1,   /* 82: of_bsn_time_request */
    0,    /* 83: of_bsn_virtual_port_create_reply */
    0,    /* 84: of_bsn_virtual_port_create_request */
    0,    /* 85: of_bsn_virtual_port_remove_reply */
    0,    /* 86: of_bsn_virtual_port_remove_request */
    -1,   /* 87: of_bsn_vlan_counter_stats_reply */
    -1,   /* 88: of_bsn_vlan_counter_stats_request */
    0,    /* 89: of_desc_stats_reply */
    0,    /* 90: of_desc_stats_request */
    0,    /* 91: of_echo_reply */
    0,    /* 92: of_echo_request */
    0,    /* 93: of_error_msg */
    0,    /* 94: of_experimenter */
    -1,   /* 95: of_experimenter_error_msg */
    0,    /* 96: of_experimenter_stats_reply */
    0,    /* 97: of_experimenter_stats_request */
    0,    /* 98: of_features_reply */
    0,    /* 99: of_features_request */
    0,    /* 100: of_flow_add */
    0,    /* 101: of_flow_delete */
    0,    /* 102: of_flow_delete_strict */
    0,    /* 103: of_flow_mod */
    0,    /* 104: of_flow_mod_failed_error_msg */
    0,    /* 105: of_flow_modify */
    0,    /* 106: of_flow_modify_strict */
    0,    /* 107: of_flow_removed */
    0,    /* 108: of_flow_stats_reply */
    0,    /* 109: of_flow_stats_request */
    0,    /* 110: of_get_config_reply */
    0,    /* 111: of_get_config_request */
    -1,   /* 112: of_group_add */
    -1,   /* 113: of_group_delete */
    -1,   /* 114: of_group_desc_stats_reply */
    -1,   /* 115: of_group_desc_stats_request */
    -1,   /* 116: of_group_features_stats_reply */
    -1,   /* 117: of_group_features_stats_request */
    -1,   /* 118: of_group_mod */
    -1,   /* 119: of_group_mod_failed_error_msg */
    -1,   /* 120: of_group_modify */
    -1,   /* 121: of_group_stats_reply */
    -1,   /* 122: of_group_stats_request */
    0,    /* 123: of_hello */
    0,    /* 124: of_hello_failed_error_msg */
    -1,   /* 125: of_meter_config_stats_reply */
    -1,   /* 126: of_meter_config_stats_request */
    -1,   /* 127: of_meter_features_stats_reply */
    -1,   /* 128: of_meter_features_stats_request */
    -1,   /* 129: of_meter_mod */
    -1,   /* 130: of_meter_mod_failed_error_msg */
    -1,   /* 131: of_meter_stats_reply */
    -1,   /* 132: of_meter_stats_request */
    0,    /* 133: of_nicira_controller_role_reply */
    0,    /* 134: of_nicira_controller_role_request */
    0,    /* 135: of_nicira_header */
    0,    /* 136: of_packet_in */
    0,    /* 137: of_packet_out */
    -1,   /* 138: of_port_desc_stats_reply */
    -1,   /* 139: of_port_desc_stats_request */
    0,    /* 140: of_port_mod */
    0,    /* 141: of_port_mod_failed_error_msg */
    0,    /* 142: of_port_stats_reply */
    0,    /* 143: of_port_stats_request */
    0,    /* 144: of_port_status */
    0,    /* 145: of_queue_get_config_reply */
    0,    /* 146: of_queue_get_config_request */
    0,    /* 147: of_queue_op_failed_error_msg */
    0,    /* 148: of_queue_stats_reply */
    0,    /* 149: of_queue_stats_request */
    -1,   /* 150: of_role_reply */
    -1,   /* 151: of_role_request */
    -1,   /* 152: of_role_request_failed_error_msg */
    0,    /* 153: of_set_config */
    0,    /* 154: of_stats_reply */
    0,    /* 155: of_stats_request */
    -1,   /* 156: of_switch_config_failed_error_msg */
    -1,   /* 157: of_table_features_failed_error_msg */
    -1,   /* 158: of_table_features_stats_reply */
    -1,   /* 159: of_table_features_stats_request */
    0,    /* 160: of_table_mod */
    -1,   /* 161: of_table_mod_failed_error_msg */
    0,    /* 162: of_table_stats_reply */
    0,    /* 163: of_table_stats_request */
    0,    /* 164: of_action */
    0,    /* 165: of_action_bsn */
    0,    /* 166: of_action_bsn_mirror */
    0,    /* 167: of_action_bsn_set_tunnel_dst */
    -1,   /* 168: of_action_copy_ttl_in */
    -1,   /* 169: of_action_copy_ttl_out */
    -1,   /* 170: of_action_dec_mpls_ttl */
    -1,   /* 171: of_action_dec_nw_ttl */
    0,    /* 172: of_action_enqueue */
    0,    /* 173: of_action_experimenter */
    -1,   /* 174: of_action_group */
    0,    /* 175: of_action_header */
    -1,   /* 176: of_action_id */
    -1,   /* 177: of_action_id_bsn */
    -1,   /* 178: of_action_id_bsn_mirror */
    -1,   /* 179: of_action_id_bsn_set_tunnel_dst */
    -1,   /* 180: of_action_id_copy_ttl_in */
    -1,   /* 181: of_action_id_copy_ttl_out */
    -1,   /* 182: of_action_id_dec_mpls_ttl */
    -1,   /* 183: of_action_id_dec_nw_ttl */
    -1,   /* 184: of_action_id_experimenter */
    -1,   /* 185: of_action_id_group */
    -1,   /* 186: of_action_id_header */
    -1,   /* 187: of_action_id_nicira */
    -1,   /* 188: of_action_id_nicira_dec_ttl */
    -1,   /* 189: of_action_id_output */
    -1,   /* 190: of_action_id_pop_mpls */
    -1,   /* 191: of_action_id_pop_pbb */
    -1,   /* 192: of_action_id_pop_vlan */
    -1,   /* 193: of_action_id_push_mpls */
    -1,   /* 194: of_action_id_push_pbb */
    -1,   /* 195: of_action_id_push_vlan */
    -1,   /* 196: of_action_id_set_field */
    -1,   /* 197: of_action_id_set_mpls_ttl */
    -1,   /* 198: of_action_id_set_nw_ttl */
    -1,   /* 199: of_action_id_set_queue */
    0,    /* 200: of_action_nicira */
    0,    /* 201: of_action_nicira_dec_ttl */
    0,    /* 202: of_action_output */
    -1,   /* 203: of_action_pop_mpls */
    -1,   /* 204: of_action_pop_pbb */
    -1,   /* 205: of_action_pop_vlan */
    -1,   /* 206: of_action_push_mpls */
    -1,   /* 207: of_action_push_pbb */
    -1,   /* 208: of_action_push_vlan */
    0,    /* 209: of_action_set_dl_dst */
    0,    /* 210: of_action_set_dl_src */
    -1,   /* 211: of_action_set_field */
    -1,   /* 212: of_action_set_mpls_label */
    -1,   /* 213: of_action_set_mpls_tc */
    -1,   /* 214: of_action_set_mpls_ttl */
    0,    /* 215: of_action_set_nw_dst */
    -1,   /* 216: of_action_set_nw_ecn */
    0,    /* 217: of_action_set_nw_src */
    0,    /* 218: of_action_set_nw_tos */
    -1,   /* 219: of_action_set_nw_ttl */
    -1,   /* 220: of_action_set_queue */
    0,    /* 221: of_action_set_tp_dst */
    0,    /* 222: of_action_set_tp_src */
    0,    /* 223: of_action_set_vlan_pcp */
    0,    /* 224: of_action_set_vlan_vid */
    0,    /* 225: of_action_strip_vlan */
    -1,   /* 226: of_bsn_controller_connection */
    -1,   /* 227: of_bsn_gentable_bucket_stats_entry */
    -1,   /* 228: of_bsn_gentable_desc_stats_entry */
    -1,   /* 229: of_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 230: of_bsn_gentable_entry_stats_entry */
    -1,   /* 231: of_bsn_gentable_stats_entry */
    0,    /* 232: of_bsn_interface */
    -1,   /* 233: of_bsn_lacp_stats_entry */
    -1,   /* 234: of_bsn_port_counter_stats_entry */
    -1,   /* 235: of_bsn_switch_pipeline_stats_entry */
    -1,   /* 236: of_bsn_tlv */
    -1,   /* 237: of_bsn_tlv_header */
    -1,   /* 238: of_bsn_tlv_idle_notification */
    -1,   /* 239: of_bsn_tlv_idle_time */
    -1,   /* 240: of_bsn_tlv_ipv4 */
    -1,   /* 241: of_bsn_tlv_mac */
    -1,   /* 242: of_bsn_tlv_port */
    -1,   /* 243: of_bsn_tlv_rx_packets */
    -1,   /* 244: of_bsn_tlv_tx_packets */
    -1,   /* 245: of_bsn_tlv_vlan_vid */
    -1,   /* 246: of_bsn_vlan_counter_stats_entry */
    0,    /* 247: of_bsn_vport */
    0,    /* 248: of_bsn_vport_header */
    0,    /* 249: of_bsn_vport_q_in_q */
    -1,   /* 250: of_bucket */
    -1,   /* 251: of_bucket_counter */
    -1,   /* 252: of_experimenter_stats_header */
    0,    /* 253: of_flow_stats_entry */
    -1,   /* 254: of_group_desc_stats_entry */
    -1,   /* 255: of_group_stats_entry */
    0,    /* 256: of_header */
    -1,   /* 257: of_hello_elem */
    -1,   /* 258: of_hello_elem_header */
    -1,   /* 259: of_hello_elem_versionbitmap */
    -1,   /* 260: of_instruction */
    -1,   /* 261: of_instruction_apply_actions */
    -1,   /* 262: of_instruction_bsn */
    -1,   /* 263: of_instruction_bsn_disable_src_mac_check */
    -1,   /* 264: of_instruction_clear_actions */
    -1,   /* 265: of_instruction_experimenter */
    -1,   /* 266: of_instruction_goto_table */
    -1,   /* 267: of_instruction_header */
    -1,   /* 268: of_instruction_id */
    -1,   /* 269: of_instruction_id_apply_actions */
    -1,   /* 270: of_instruction_id_bsn */
    -1,   /* 271: of_instruction_id_bsn_disable_src_mac_check */
    -1,   /* 272: of_instruction_id_clear_actions */
    -1,   /* 273: of_instruction_id_experimenter */
    -1,   /* 274: of_instruction_id_goto_table */
    -1,   /* 275: of_instruction_id_header */
    -1,   /* 276: of_instruction_id_meter */
    -1,   /* 277: of_instruction_id_write_actions */
    -1,   /* 278: of_instruction_id_write_metadata */
    -1,   /* 279: of_instruction_meter */
    -1,   /* 280: of_instruction_write_actions */
    -1,   /* 281: of_instruction_write_metadata */
    0,    /* 282: of_match_v1 */
    -1,   /* 283: of_match_v2 */
    -1,   /* 284: of_match_v3 */
    -1,   /* 285: of_meter_band */
    -1,   /* 286: of_meter_band_drop */
    -1,   /* 287: of_meter_band_dscp_remark */
    -1,   /* 288: of_meter_band_experimenter */
    -1,   /* 289: of_meter_band_header */
    -1,   /* 290: of_meter_band_stats */
    -1,   /* 291: of_meter_config */
    -1,   /* 292: of_meter_features */
    -1,   /* 293: of_meter_stats */
    -1,   /* 294: of_oxm */
    -1,   /* 295: of_oxm_arp_op */
    -1,   /* 296: of_oxm_arp_op_masked */
    -1,   /* 297: of_oxm_arp_sha */
    -1,   /* 298: of_oxm_arp_sha_masked */
    -1,   /* 299: of_oxm_arp_spa */
    -1,   /* 300: of_oxm_arp_spa_masked */
    -1,   /* 301: of_oxm_arp_tha */
    -1,   /* 302: of_oxm_arp_tha_masked */
    -1,   /* 303: of_oxm_arp_tpa */
    -1,   /* 304: of_oxm_arp_tpa_masked */
    -1,   /* 305: of_oxm_bsn_global_vrf_allowed */
    -1,   /* 306: of_oxm_bsn_global_vrf_allowed_masked */
    -1,   /* 307: of_oxm_bsn_in_ports_128 */
    -1,   /* 308: of_oxm_bsn_in_ports_128_masked */
    -1,   /* 309: of_oxm_bsn_l3_dst_class_id */
    -1,   /* 310: of_oxm_bsn_l3_dst_class_id_masked */
    -1,   /* 311: of_oxm_bsn_l3_interface_class_id */
    -1,   /* 312: of_oxm_bsn_l3_interface_class_id_masked */
    -1,   /* 313: of_oxm_bsn_l3_src_class_id */
    -1,   /* 314: of_oxm_bsn_l3_src_class_id_masked */
    -1,   /* 315: of_oxm_bsn_lag_id */
    -1,   /* 316: of_oxm_bsn_lag_id_masked */
    -1,   /* 317: of_oxm_bsn_vrf */
    -1,   /* 318: of_oxm_bsn_vrf_masked */
    -1,   /* 319: of_oxm_eth_dst */
    -1,   /* 320: of_oxm_eth_dst_masked */
    -1,   /* 321: of_oxm_eth_src */
    -1,   /* 322: of_oxm_eth_src_masked */
    -1,   /* 323: of_oxm_eth_type */
    -1,   /* 324: of_oxm_eth_type_masked */
    -1,   /* 325: of_oxm_header */
    -1,   /* 326: of_oxm_icmpv4_code */
    -1,   /* 327: of_oxm_icmpv4_code_masked */
    -1,   /* 328: of_oxm_icmpv4_type */
    -1,   /* 329: of_oxm_icmpv4_type_masked */
    -1,   /* 330: of_oxm_icmpv6_code */
    -1,   /* 331: of_oxm_icmpv6_code_masked */
    -1,   /* 332: of_oxm_icmpv6_type */
    -1,   /* 333: of_oxm_icmpv6_type_masked */
    -1,   /* 334: of_oxm_in_phy_port */
    -1,   /* 335: of_oxm_in_phy_port_masked */
    -1,   /* 336: of_oxm_in_port */
    -1,   /* 337: of_oxm_in_port_masked */
    -1,   /* 338: of_oxm_ip_dscp */
    -1,   /* 339: of_oxm_ip_dscp_masked */
    -1,   /* 340: of_oxm_ip_ecn */
    -1,   /* 341: of_oxm_ip_ecn_masked */
    -1,   /* 342: of_oxm_ip_proto */
    -1,   /* 343: of_oxm_ip_proto_masked */
    -1,   /* 344: of_oxm_ipv4_dst */
    -1,   /* 345: of_oxm_ipv4_dst_masked */
    -1,   /* 346: of_oxm_ipv4_src */
    -1,   /* 347: of_oxm_ipv4_src_masked */
    -1,   /* 348: of_oxm_ipv6_dst */
    -1,   /* 349: of_oxm_ipv6_dst_masked */
    -1,   /* 350: of_oxm_ipv6_flabel */
    -1,   /* 351: of_oxm_ipv6_flabel_masked */
    -1,   /* 352: of_oxm_ipv6_nd_sll */
    -1,   /* 353: of_oxm_ipv6_nd_sll_masked */
    -1,   /* 354: of_oxm_ipv6_nd_target */
    -1,   /* 355: of_oxm_ipv6_nd_target_masked */
    -1,   /* 356: of_oxm_ipv6_nd_tll */
    -1,   /* 357: of_oxm_ipv6_nd_tll_masked */
    -1,   /* 358: of_oxm_ipv6_src */
    -1,   /* 359: of_oxm_ipv6_src_masked */
    -1,   /* 360: of_oxm_metadata */
    -1,   /* 361: of_oxm_metadata_masked */
    -1,   /* 362: of_oxm_mpls_label */
    -1,   /* 363: of_oxm_mpls_label_masked */
    -1,   /* 364: of_oxm_mpls_tc */
    -1,   /* 365: of_oxm_mpls_tc_masked */
    -1,   /* 366: of_oxm_sctp_dst */
    -1,   /* 367: of_oxm_sctp_dst_masked */
    -1,   /* 368: of_oxm_sctp_src */
    -1,   /* 369: of_oxm_sctp_src_masked */
    -1,   /* 370: of_oxm_tcp_dst */
    -1,   /* 371: of_oxm_tcp_dst_masked */
    -1,   /* 372: of_oxm_tcp_src */
    -1,   /* 373: of_oxm_tcp_src_masked */
    -1,   /* 374: of_oxm_udp_dst */
    -1,   /* 375: of_oxm_udp_dst_masked */
    -1,   /* 376: of_oxm_udp_src */
    -1,   /* 377: of_oxm_udp_src_masked */
    -1,   /* 378: of_oxm_vlan_pcp */
    -1,   /* 379: of_oxm_vlan_pcp_masked */
    -1,   /* 380: of_oxm_vlan_vid */
    -1,   /* 381: of_oxm_vlan_vid_masked */
    0,    /* 382: of_packet_queue */
    0,    /* 383: of_port_desc */
    0,    /* 384: of_port_stats_entry */
    0,    /* 385: of_queue_prop */
    -1,   /* 386: of_queue_prop_experimenter */
    0,    /* 387: of_queue_prop_header */
    -1,   /* 388: of_queue_prop_max_rate */
    0,    /* 389: of_queue_prop_min_rate */
    0,    /* 390: of_queue_stats_entry */
    -1,   /* 391: of_table_feature_prop */
    -1,   /* 392: of_table_feature_prop_apply_actions */
    -1,   /* 393: of_table_feature_prop_apply_actions_miss */
    -1,   /* 394: of_table_feature_prop_apply_setfield */
    -1,   /* 395: of_table_feature_prop_apply_setfield_miss */
    -1,   /* 396: of_table_feature_prop_experimenter */
    -1,   /* 397: of_table_feature_prop_header */
    -1,   /* 398: of_table_feature_prop_instructions */
    -1,   /* 399: of_table_feature_prop_instructions_miss */
    -1,   /* 400: of_table_feature_prop_match */
    -1,   /* 401: of_table_feature_prop_next_tables */
    -1,   /* 402: of_table_feature_prop_next_tables_miss */
    -1,   /* 403: of_table_feature_prop_wildcards */
    -1,   /* 404: of_table_feature_prop_write_actions */
    -1,   /* 405: of_table_feature_prop_write_actions_miss */
    -1,   /* 406: of_table_feature_prop_write_setfield */
    -1,   /* 407: of_table_feature_prop_write_setfield_miss */
    -1,   /* 408: of_table_features */
    0,    /* 409: of_table_stats_entry */
    -1,   /* 410: of_uint32 */
    -1,   /* 411: of_uint64 */
    -1,   /* 412: of_uint8 */
    0,    /* 413: of_list_action */
    -1,   /* 414: of_list_action_id */
    -1,   /* 415: of_list_bsn_controller_connection */
    -1,   /* 416: of_list_bsn_gentable_bucket_stats_entry */
    -1,   /* 417: of_list_bsn_gentable_desc_stats_entry */
    -1,   /* 418: of_list_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 419: of_list_bsn_gentable_entry_stats_entry */
    -1,   /* 420: of_list_bsn_gentable_stats_entry */
    0,    /* 421: of_list_bsn_interface */
    -1,   /* 422: of_list_bsn_lacp_stats_entry */
    -1,   /* 423: of_list_bsn_port_counter_stats_entry */
    -1,   /* 424: of_list_bsn_switch_pipeline_stats_entry */
    -1,   /* 425: of_list_bsn_tlv */
    -1,   /* 426: of_list_bsn_vlan_counter_stats_entry */
    -1,   /* 427: of_list_bucket */
    -1,   /* 428: of_list_bucket_counter */
    0,    /* 429: of_list_flow_stats_entry */
    -1,   /* 430: of_list_group_desc_stats_entry */
    -1,   /* 431: of_list_group_stats_entry */
    -1,   /* 432: of_list_hello_elem */
    -1,   /* 433: of_list_instruction */
    -1,   /* 434: of_list_meter_band */
    -1,   /* 435: of_list_meter_band_stats */
    -1,   /* 436: of_list_meter_stats */
    -1,   /* 437: of_list_oxm */
    0,    /* 438: of_list_packet_queue */
    0,    /* 439: of_list_port_desc */
    0,    /* 440: of_list_port_stats_entry */
    0,    /* 441: of_list_queue_prop */
    0,    /* 442: of_list_queue_stats_entry */
    -1,   /* 443: of_list_table_feature_prop */
    -1,   /* 444: of_list_table_features */
    0,    /* 445: of_list_table_stats_entry */
    -1,   /* 446: of_list_uint32 */
    -1,   /* 447: of_list_uint64 */
    -1    /* 448: of_list_uint8 */
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
    0,    /* 12: of_bsn_bw_clear_data_reply */
    0,    /* 13: of_bsn_bw_clear_data_request */
    0,    /* 14: of_bsn_bw_enable_get_reply */
    0,    /* 15: of_bsn_bw_enable_get_request */
    0,    /* 16: of_bsn_bw_enable_set_reply */
    0,    /* 17: of_bsn_bw_enable_set_request */
    -1,   /* 18: of_bsn_controller_connections_reply */
    -1,   /* 19: of_bsn_controller_connections_request */
    -1,   /* 20: of_bsn_flow_idle */
    -1,   /* 21: of_bsn_flow_idle_enable_get_reply */
    -1,   /* 22: of_bsn_flow_idle_enable_get_request */
    -1,   /* 23: of_bsn_flow_idle_enable_set_reply */
    -1,   /* 24: of_bsn_flow_idle_enable_set_request */
    -1,   /* 25: of_bsn_gentable_bucket_stats_reply */
    -1,   /* 26: of_bsn_gentable_bucket_stats_request */
    -1,   /* 27: of_bsn_gentable_clear_reply */
    -1,   /* 28: of_bsn_gentable_clear_request */
    -1,   /* 29: of_bsn_gentable_desc_stats_reply */
    -1,   /* 30: of_bsn_gentable_desc_stats_request */
    -1,   /* 31: of_bsn_gentable_entry_add */
    -1,   /* 32: of_bsn_gentable_entry_delete */
    -1,   /* 33: of_bsn_gentable_entry_desc_stats_reply */
    -1,   /* 34: of_bsn_gentable_entry_desc_stats_request */
    -1,   /* 35: of_bsn_gentable_entry_stats_reply */
    -1,   /* 36: of_bsn_gentable_entry_stats_request */
    -1,   /* 37: of_bsn_gentable_set_buckets_size */
    -1,   /* 38: of_bsn_gentable_stats_reply */
    -1,   /* 39: of_bsn_gentable_stats_request */
    0,    /* 40: of_bsn_get_interfaces_reply */
    0,    /* 41: of_bsn_get_interfaces_request */
    -1,   /* 42: of_bsn_get_ip_mask_reply */
    -1,   /* 43: of_bsn_get_ip_mask_request */
    -1,   /* 44: of_bsn_get_l2_table_reply */
    -1,   /* 45: of_bsn_get_l2_table_request */
    0,    /* 46: of_bsn_get_mirroring_reply */
    0,    /* 47: of_bsn_get_mirroring_request */
    -1,   /* 48: of_bsn_get_switch_pipeline_reply */
    -1,   /* 49: of_bsn_get_switch_pipeline_request */
    0,    /* 50: of_bsn_header */
    -1,   /* 51: of_bsn_hybrid_get_reply */
    -1,   /* 52: of_bsn_hybrid_get_request */
    -1,   /* 53: of_bsn_lacp_convergence_notif */
    -1,   /* 54: of_bsn_lacp_stats_reply */
    -1,   /* 55: of_bsn_lacp_stats_request */
    0,    /* 56: of_bsn_pdu_rx_reply */
    0,    /* 57: of_bsn_pdu_rx_request */
    0,    /* 58: of_bsn_pdu_rx_timeout */
    0,    /* 59: of_bsn_pdu_tx_reply */
    0,    /* 60: of_bsn_pdu_tx_request */
    -1,   /* 61: of_bsn_port_counter_stats_reply */
    -1,   /* 62: of_bsn_port_counter_stats_request */
    -1,   /* 63: of_bsn_role_status */
    -1,   /* 64: of_bsn_set_ip_mask */
    -1,   /* 65: of_bsn_set_l2_table_reply */
    -1,   /* 66: of_bsn_set_l2_table_request */
    -1,   /* 67: of_bsn_set_lacp_reply */
    -1,   /* 68: of_bsn_set_lacp_request */
    0,    /* 69: of_bsn_set_mirroring */
    0,    /* 70: of_bsn_set_pktin_suppression_reply */
    0,    /* 71: of_bsn_set_pktin_suppression_request */
    -1,   /* 72: of_bsn_set_switch_pipeline_reply */
    -1,   /* 73: of_bsn_set_switch_pipeline_request */
    -1,   /* 74: of_bsn_shell_command */
    -1,   /* 75: of_bsn_shell_output */
    -1,   /* 76: of_bsn_shell_status */
    0,    /* 77: of_bsn_stats_reply */
    0,    /* 78: of_bsn_stats_request */
    -1,   /* 79: of_bsn_switch_pipeline_stats_reply */
    -1,   /* 80: of_bsn_switch_pipeline_stats_request */
    -1,   /* 81: of_bsn_time_reply */
    -1,   /* 82: of_bsn_time_request */
    0,    /* 83: of_bsn_virtual_port_create_reply */
    0,    /* 84: of_bsn_virtual_port_create_request */
    0,    /* 85: of_bsn_virtual_port_remove_reply */
    0,    /* 86: of_bsn_virtual_port_remove_request */
    -1,   /* 87: of_bsn_vlan_counter_stats_reply */
    -1,   /* 88: of_bsn_vlan_counter_stats_request */
    0,    /* 89: of_desc_stats_reply */
    0,    /* 90: of_desc_stats_request */
    0,    /* 91: of_echo_reply */
    0,    /* 92: of_echo_request */
    0,    /* 93: of_error_msg */
    0,    /* 94: of_experimenter */
    -1,   /* 95: of_experimenter_error_msg */
    0,    /* 96: of_experimenter_stats_reply */
    0,    /* 97: of_experimenter_stats_request */
    0,    /* 98: of_features_reply */
    0,    /* 99: of_features_request */
    0,    /* 100: of_flow_add */
    0,    /* 101: of_flow_delete */
    0,    /* 102: of_flow_delete_strict */
    0,    /* 103: of_flow_mod */
    0,    /* 104: of_flow_mod_failed_error_msg */
    0,    /* 105: of_flow_modify */
    0,    /* 106: of_flow_modify_strict */
    0,    /* 107: of_flow_removed */
    0,    /* 108: of_flow_stats_reply */
    0,    /* 109: of_flow_stats_request */
    0,    /* 110: of_get_config_reply */
    0,    /* 111: of_get_config_request */
    0,    /* 112: of_group_add */
    0,    /* 113: of_group_delete */
    0,    /* 114: of_group_desc_stats_reply */
    0,    /* 115: of_group_desc_stats_request */
    -1,   /* 116: of_group_features_stats_reply */
    -1,   /* 117: of_group_features_stats_request */
    0,    /* 118: of_group_mod */
    0,    /* 119: of_group_mod_failed_error_msg */
    0,    /* 120: of_group_modify */
    0,    /* 121: of_group_stats_reply */
    0,    /* 122: of_group_stats_request */
    0,    /* 123: of_hello */
    0,    /* 124: of_hello_failed_error_msg */
    -1,   /* 125: of_meter_config_stats_reply */
    -1,   /* 126: of_meter_config_stats_request */
    -1,   /* 127: of_meter_features_stats_reply */
    -1,   /* 128: of_meter_features_stats_request */
    -1,   /* 129: of_meter_mod */
    -1,   /* 130: of_meter_mod_failed_error_msg */
    -1,   /* 131: of_meter_stats_reply */
    -1,   /* 132: of_meter_stats_request */
    -1,   /* 133: of_nicira_controller_role_reply */
    -1,   /* 134: of_nicira_controller_role_request */
    0,    /* 135: of_nicira_header */
    0,    /* 136: of_packet_in */
    0,    /* 137: of_packet_out */
    -1,   /* 138: of_port_desc_stats_reply */
    -1,   /* 139: of_port_desc_stats_request */
    0,    /* 140: of_port_mod */
    0,    /* 141: of_port_mod_failed_error_msg */
    0,    /* 142: of_port_stats_reply */
    0,    /* 143: of_port_stats_request */
    0,    /* 144: of_port_status */
    0,    /* 145: of_queue_get_config_reply */
    0,    /* 146: of_queue_get_config_request */
    0,    /* 147: of_queue_op_failed_error_msg */
    0,    /* 148: of_queue_stats_reply */
    0,    /* 149: of_queue_stats_request */
    -1,   /* 150: of_role_reply */
    -1,   /* 151: of_role_request */
    -1,   /* 152: of_role_request_failed_error_msg */
    0,    /* 153: of_set_config */
    0,    /* 154: of_stats_reply */
    0,    /* 155: of_stats_request */
    0,    /* 156: of_switch_config_failed_error_msg */
    -1,   /* 157: of_table_features_failed_error_msg */
    -1,   /* 158: of_table_features_stats_reply */
    -1,   /* 159: of_table_features_stats_request */
    0,    /* 160: of_table_mod */
    0,    /* 161: of_table_mod_failed_error_msg */
    0,    /* 162: of_table_stats_reply */
    0,    /* 163: of_table_stats_request */
    0,    /* 164: of_action */
    0,    /* 165: of_action_bsn */
    0,    /* 166: of_action_bsn_mirror */
    0,    /* 167: of_action_bsn_set_tunnel_dst */
    0,    /* 168: of_action_copy_ttl_in */
    0,    /* 169: of_action_copy_ttl_out */
    0,    /* 170: of_action_dec_mpls_ttl */
    0,    /* 171: of_action_dec_nw_ttl */
    -1,   /* 172: of_action_enqueue */
    0,    /* 173: of_action_experimenter */
    0,    /* 174: of_action_group */
    0,    /* 175: of_action_header */
    -1,   /* 176: of_action_id */
    -1,   /* 177: of_action_id_bsn */
    -1,   /* 178: of_action_id_bsn_mirror */
    -1,   /* 179: of_action_id_bsn_set_tunnel_dst */
    -1,   /* 180: of_action_id_copy_ttl_in */
    -1,   /* 181: of_action_id_copy_ttl_out */
    -1,   /* 182: of_action_id_dec_mpls_ttl */
    -1,   /* 183: of_action_id_dec_nw_ttl */
    -1,   /* 184: of_action_id_experimenter */
    -1,   /* 185: of_action_id_group */
    -1,   /* 186: of_action_id_header */
    -1,   /* 187: of_action_id_nicira */
    -1,   /* 188: of_action_id_nicira_dec_ttl */
    -1,   /* 189: of_action_id_output */
    -1,   /* 190: of_action_id_pop_mpls */
    -1,   /* 191: of_action_id_pop_pbb */
    -1,   /* 192: of_action_id_pop_vlan */
    -1,   /* 193: of_action_id_push_mpls */
    -1,   /* 194: of_action_id_push_pbb */
    -1,   /* 195: of_action_id_push_vlan */
    -1,   /* 196: of_action_id_set_field */
    -1,   /* 197: of_action_id_set_mpls_ttl */
    -1,   /* 198: of_action_id_set_nw_ttl */
    -1,   /* 199: of_action_id_set_queue */
    0,    /* 200: of_action_nicira */
    0,    /* 201: of_action_nicira_dec_ttl */
    0,    /* 202: of_action_output */
    0,    /* 203: of_action_pop_mpls */
    -1,   /* 204: of_action_pop_pbb */
    0,    /* 205: of_action_pop_vlan */
    0,    /* 206: of_action_push_mpls */
    -1,   /* 207: of_action_push_pbb */
    0,    /* 208: of_action_push_vlan */
    0,    /* 209: of_action_set_dl_dst */
    0,    /* 210: of_action_set_dl_src */
    -1,   /* 211: of_action_set_field */
    0,    /* 212: of_action_set_mpls_label */
    0,    /* 213: of_action_set_mpls_tc */
    0,    /* 214: of_action_set_mpls_ttl */
    0,    /* 215: of_action_set_nw_dst */
    0,    /* 216: of_action_set_nw_ecn */
    0,    /* 217: of_action_set_nw_src */
    0,    /* 218: of_action_set_nw_tos */
    0,    /* 219: of_action_set_nw_ttl */
    0,    /* 220: of_action_set_queue */
    0,    /* 221: of_action_set_tp_dst */
    0,    /* 222: of_action_set_tp_src */
    0,    /* 223: of_action_set_vlan_pcp */
    0,    /* 224: of_action_set_vlan_vid */
    -1,   /* 225: of_action_strip_vlan */
    -1,   /* 226: of_bsn_controller_connection */
    -1,   /* 227: of_bsn_gentable_bucket_stats_entry */
    -1,   /* 228: of_bsn_gentable_desc_stats_entry */
    -1,   /* 229: of_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 230: of_bsn_gentable_entry_stats_entry */
    -1,   /* 231: of_bsn_gentable_stats_entry */
    0,    /* 232: of_bsn_interface */
    -1,   /* 233: of_bsn_lacp_stats_entry */
    -1,   /* 234: of_bsn_port_counter_stats_entry */
    -1,   /* 235: of_bsn_switch_pipeline_stats_entry */
    -1,   /* 236: of_bsn_tlv */
    -1,   /* 237: of_bsn_tlv_header */
    -1,   /* 238: of_bsn_tlv_idle_notification */
    -1,   /* 239: of_bsn_tlv_idle_time */
    -1,   /* 240: of_bsn_tlv_ipv4 */
    -1,   /* 241: of_bsn_tlv_mac */
    -1,   /* 242: of_bsn_tlv_port */
    -1,   /* 243: of_bsn_tlv_rx_packets */
    -1,   /* 244: of_bsn_tlv_tx_packets */
    -1,   /* 245: of_bsn_tlv_vlan_vid */
    -1,   /* 246: of_bsn_vlan_counter_stats_entry */
    0,    /* 247: of_bsn_vport */
    0,    /* 248: of_bsn_vport_header */
    0,    /* 249: of_bsn_vport_q_in_q */
    0,    /* 250: of_bucket */
    0,    /* 251: of_bucket_counter */
    -1,   /* 252: of_experimenter_stats_header */
    0,    /* 253: of_flow_stats_entry */
    0,    /* 254: of_group_desc_stats_entry */
    0,    /* 255: of_group_stats_entry */
    0,    /* 256: of_header */
    -1,   /* 257: of_hello_elem */
    -1,   /* 258: of_hello_elem_header */
    -1,   /* 259: of_hello_elem_versionbitmap */
    0,    /* 260: of_instruction */
    0,    /* 261: of_instruction_apply_actions */
    -1,   /* 262: of_instruction_bsn */
    -1,   /* 263: of_instruction_bsn_disable_src_mac_check */
    0,    /* 264: of_instruction_clear_actions */
    0,    /* 265: of_instruction_experimenter */
    0,    /* 266: of_instruction_goto_table */
    0,    /* 267: of_instruction_header */
    -1,   /* 268: of_instruction_id */
    -1,   /* 269: of_instruction_id_apply_actions */
    -1,   /* 270: of_instruction_id_bsn */
    -1,   /* 271: of_instruction_id_bsn_disable_src_mac_check */
    -1,   /* 272: of_instruction_id_clear_actions */
    -1,   /* 273: of_instruction_id_experimenter */
    -1,   /* 274: of_instruction_id_goto_table */
    -1,   /* 275: of_instruction_id_header */
    -1,   /* 276: of_instruction_id_meter */
    -1,   /* 277: of_instruction_id_write_actions */
    -1,   /* 278: of_instruction_id_write_metadata */
    -1,   /* 279: of_instruction_meter */
    0,    /* 280: of_instruction_write_actions */
    0,    /* 281: of_instruction_write_metadata */
    -1,   /* 282: of_match_v1 */
    0,    /* 283: of_match_v2 */
    -1,   /* 284: of_match_v3 */
    -1,   /* 285: of_meter_band */
    -1,   /* 286: of_meter_band_drop */
    -1,   /* 287: of_meter_band_dscp_remark */
    -1,   /* 288: of_meter_band_experimenter */
    -1,   /* 289: of_meter_band_header */
    -1,   /* 290: of_meter_band_stats */
    -1,   /* 291: of_meter_config */
    -1,   /* 292: of_meter_features */
    -1,   /* 293: of_meter_stats */
    -1,   /* 294: of_oxm */
    -1,   /* 295: of_oxm_arp_op */
    -1,   /* 296: of_oxm_arp_op_masked */
    -1,   /* 297: of_oxm_arp_sha */
    -1,   /* 298: of_oxm_arp_sha_masked */
    -1,   /* 299: of_oxm_arp_spa */
    -1,   /* 300: of_oxm_arp_spa_masked */
    -1,   /* 301: of_oxm_arp_tha */
    -1,   /* 302: of_oxm_arp_tha_masked */
    -1,   /* 303: of_oxm_arp_tpa */
    -1,   /* 304: of_oxm_arp_tpa_masked */
    -1,   /* 305: of_oxm_bsn_global_vrf_allowed */
    -1,   /* 306: of_oxm_bsn_global_vrf_allowed_masked */
    -1,   /* 307: of_oxm_bsn_in_ports_128 */
    -1,   /* 308: of_oxm_bsn_in_ports_128_masked */
    -1,   /* 309: of_oxm_bsn_l3_dst_class_id */
    -1,   /* 310: of_oxm_bsn_l3_dst_class_id_masked */
    -1,   /* 311: of_oxm_bsn_l3_interface_class_id */
    -1,   /* 312: of_oxm_bsn_l3_interface_class_id_masked */
    -1,   /* 313: of_oxm_bsn_l3_src_class_id */
    -1,   /* 314: of_oxm_bsn_l3_src_class_id_masked */
    -1,   /* 315: of_oxm_bsn_lag_id */
    -1,   /* 316: of_oxm_bsn_lag_id_masked */
    -1,   /* 317: of_oxm_bsn_vrf */
    -1,   /* 318: of_oxm_bsn_vrf_masked */
    -1,   /* 319: of_oxm_eth_dst */
    -1,   /* 320: of_oxm_eth_dst_masked */
    -1,   /* 321: of_oxm_eth_src */
    -1,   /* 322: of_oxm_eth_src_masked */
    -1,   /* 323: of_oxm_eth_type */
    -1,   /* 324: of_oxm_eth_type_masked */
    -1,   /* 325: of_oxm_header */
    -1,   /* 326: of_oxm_icmpv4_code */
    -1,   /* 327: of_oxm_icmpv4_code_masked */
    -1,   /* 328: of_oxm_icmpv4_type */
    -1,   /* 329: of_oxm_icmpv4_type_masked */
    -1,   /* 330: of_oxm_icmpv6_code */
    -1,   /* 331: of_oxm_icmpv6_code_masked */
    -1,   /* 332: of_oxm_icmpv6_type */
    -1,   /* 333: of_oxm_icmpv6_type_masked */
    -1,   /* 334: of_oxm_in_phy_port */
    -1,   /* 335: of_oxm_in_phy_port_masked */
    -1,   /* 336: of_oxm_in_port */
    -1,   /* 337: of_oxm_in_port_masked */
    -1,   /* 338: of_oxm_ip_dscp */
    -1,   /* 339: of_oxm_ip_dscp_masked */
    -1,   /* 340: of_oxm_ip_ecn */
    -1,   /* 341: of_oxm_ip_ecn_masked */
    -1,   /* 342: of_oxm_ip_proto */
    -1,   /* 343: of_oxm_ip_proto_masked */
    -1,   /* 344: of_oxm_ipv4_dst */
    -1,   /* 345: of_oxm_ipv4_dst_masked */
    -1,   /* 346: of_oxm_ipv4_src */
    -1,   /* 347: of_oxm_ipv4_src_masked */
    -1,   /* 348: of_oxm_ipv6_dst */
    -1,   /* 349: of_oxm_ipv6_dst_masked */
    -1,   /* 350: of_oxm_ipv6_flabel */
    -1,   /* 351: of_oxm_ipv6_flabel_masked */
    -1,   /* 352: of_oxm_ipv6_nd_sll */
    -1,   /* 353: of_oxm_ipv6_nd_sll_masked */
    -1,   /* 354: of_oxm_ipv6_nd_target */
    -1,   /* 355: of_oxm_ipv6_nd_target_masked */
    -1,   /* 356: of_oxm_ipv6_nd_tll */
    -1,   /* 357: of_oxm_ipv6_nd_tll_masked */
    -1,   /* 358: of_oxm_ipv6_src */
    -1,   /* 359: of_oxm_ipv6_src_masked */
    -1,   /* 360: of_oxm_metadata */
    -1,   /* 361: of_oxm_metadata_masked */
    -1,   /* 362: of_oxm_mpls_label */
    -1,   /* 363: of_oxm_mpls_label_masked */
    -1,   /* 364: of_oxm_mpls_tc */
    -1,   /* 365: of_oxm_mpls_tc_masked */
    -1,   /* 366: of_oxm_sctp_dst */
    -1,   /* 367: of_oxm_sctp_dst_masked */
    -1,   /* 368: of_oxm_sctp_src */
    -1,   /* 369: of_oxm_sctp_src_masked */
    -1,   /* 370: of_oxm_tcp_dst */
    -1,   /* 371: of_oxm_tcp_dst_masked */
    -1,   /* 372: of_oxm_tcp_src */
    -1,   /* 373: of_oxm_tcp_src_masked */
    -1,   /* 374: of_oxm_udp_dst */
    -1,   /* 375: of_oxm_udp_dst_masked */
    -1,   /* 376: of_oxm_udp_src */
    -1,   /* 377: of_oxm_udp_src_masked */
    -1,   /* 378: of_oxm_vlan_pcp */
    -1,   /* 379: of_oxm_vlan_pcp_masked */
    -1,   /* 380: of_oxm_vlan_vid */
    -1,   /* 381: of_oxm_vlan_vid_masked */
    0,    /* 382: of_packet_queue */
    0,    /* 383: of_port_desc */
    0,    /* 384: of_port_stats_entry */
    0,    /* 385: of_queue_prop */
    -1,   /* 386: of_queue_prop_experimenter */
    0,    /* 387: of_queue_prop_header */
    -1,   /* 388: of_queue_prop_max_rate */
    0,    /* 389: of_queue_prop_min_rate */
    0,    /* 390: of_queue_stats_entry */
    -1,   /* 391: of_table_feature_prop */
    -1,   /* 392: of_table_feature_prop_apply_actions */
    -1,   /* 393: of_table_feature_prop_apply_actions_miss */
    -1,   /* 394: of_table_feature_prop_apply_setfield */
    -1,   /* 395: of_table_feature_prop_apply_setfield_miss */
    -1,   /* 396: of_table_feature_prop_experimenter */
    -1,   /* 397: of_table_feature_prop_header */
    -1,   /* 398: of_table_feature_prop_instructions */
    -1,   /* 399: of_table_feature_prop_instructions_miss */
    -1,   /* 400: of_table_feature_prop_match */
    -1,   /* 401: of_table_feature_prop_next_tables */
    -1,   /* 402: of_table_feature_prop_next_tables_miss */
    -1,   /* 403: of_table_feature_prop_wildcards */
    -1,   /* 404: of_table_feature_prop_write_actions */
    -1,   /* 405: of_table_feature_prop_write_actions_miss */
    -1,   /* 406: of_table_feature_prop_write_setfield */
    -1,   /* 407: of_table_feature_prop_write_setfield_miss */
    -1,   /* 408: of_table_features */
    0,    /* 409: of_table_stats_entry */
    -1,   /* 410: of_uint32 */
    -1,   /* 411: of_uint64 */
    -1,   /* 412: of_uint8 */
    0,    /* 413: of_list_action */
    -1,   /* 414: of_list_action_id */
    -1,   /* 415: of_list_bsn_controller_connection */
    -1,   /* 416: of_list_bsn_gentable_bucket_stats_entry */
    -1,   /* 417: of_list_bsn_gentable_desc_stats_entry */
    -1,   /* 418: of_list_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 419: of_list_bsn_gentable_entry_stats_entry */
    -1,   /* 420: of_list_bsn_gentable_stats_entry */
    0,    /* 421: of_list_bsn_interface */
    -1,   /* 422: of_list_bsn_lacp_stats_entry */
    -1,   /* 423: of_list_bsn_port_counter_stats_entry */
    -1,   /* 424: of_list_bsn_switch_pipeline_stats_entry */
    -1,   /* 425: of_list_bsn_tlv */
    -1,   /* 426: of_list_bsn_vlan_counter_stats_entry */
    0,    /* 427: of_list_bucket */
    0,    /* 428: of_list_bucket_counter */
    0,    /* 429: of_list_flow_stats_entry */
    0,    /* 430: of_list_group_desc_stats_entry */
    0,    /* 431: of_list_group_stats_entry */
    -1,   /* 432: of_list_hello_elem */
    0,    /* 433: of_list_instruction */
    -1,   /* 434: of_list_meter_band */
    -1,   /* 435: of_list_meter_band_stats */
    -1,   /* 436: of_list_meter_stats */
    -1,   /* 437: of_list_oxm */
    0,    /* 438: of_list_packet_queue */
    0,    /* 439: of_list_port_desc */
    0,    /* 440: of_list_port_stats_entry */
    0,    /* 441: of_list_queue_prop */
    0,    /* 442: of_list_queue_stats_entry */
    -1,   /* 443: of_list_table_feature_prop */
    -1,   /* 444: of_list_table_features */
    0,    /* 445: of_list_table_stats_entry */
    -1,   /* 446: of_list_uint32 */
    -1,   /* 447: of_list_uint64 */
    -1    /* 448: of_list_uint8 */
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
    0,    /* 12: of_bsn_bw_clear_data_reply */
    0,    /* 13: of_bsn_bw_clear_data_request */
    0,    /* 14: of_bsn_bw_enable_get_reply */
    0,    /* 15: of_bsn_bw_enable_get_request */
    0,    /* 16: of_bsn_bw_enable_set_reply */
    0,    /* 17: of_bsn_bw_enable_set_request */
    -1,   /* 18: of_bsn_controller_connections_reply */
    -1,   /* 19: of_bsn_controller_connections_request */
    -1,   /* 20: of_bsn_flow_idle */
    -1,   /* 21: of_bsn_flow_idle_enable_get_reply */
    -1,   /* 22: of_bsn_flow_idle_enable_get_request */
    -1,   /* 23: of_bsn_flow_idle_enable_set_reply */
    -1,   /* 24: of_bsn_flow_idle_enable_set_request */
    -1,   /* 25: of_bsn_gentable_bucket_stats_reply */
    -1,   /* 26: of_bsn_gentable_bucket_stats_request */
    -1,   /* 27: of_bsn_gentable_clear_reply */
    -1,   /* 28: of_bsn_gentable_clear_request */
    -1,   /* 29: of_bsn_gentable_desc_stats_reply */
    -1,   /* 30: of_bsn_gentable_desc_stats_request */
    -1,   /* 31: of_bsn_gentable_entry_add */
    -1,   /* 32: of_bsn_gentable_entry_delete */
    -1,   /* 33: of_bsn_gentable_entry_desc_stats_reply */
    -1,   /* 34: of_bsn_gentable_entry_desc_stats_request */
    -1,   /* 35: of_bsn_gentable_entry_stats_reply */
    -1,   /* 36: of_bsn_gentable_entry_stats_request */
    -1,   /* 37: of_bsn_gentable_set_buckets_size */
    -1,   /* 38: of_bsn_gentable_stats_reply */
    -1,   /* 39: of_bsn_gentable_stats_request */
    0,    /* 40: of_bsn_get_interfaces_reply */
    0,    /* 41: of_bsn_get_interfaces_request */
    -1,   /* 42: of_bsn_get_ip_mask_reply */
    -1,   /* 43: of_bsn_get_ip_mask_request */
    -1,   /* 44: of_bsn_get_l2_table_reply */
    -1,   /* 45: of_bsn_get_l2_table_request */
    0,    /* 46: of_bsn_get_mirroring_reply */
    0,    /* 47: of_bsn_get_mirroring_request */
    -1,   /* 48: of_bsn_get_switch_pipeline_reply */
    -1,   /* 49: of_bsn_get_switch_pipeline_request */
    0,    /* 50: of_bsn_header */
    -1,   /* 51: of_bsn_hybrid_get_reply */
    -1,   /* 52: of_bsn_hybrid_get_request */
    -1,   /* 53: of_bsn_lacp_convergence_notif */
    -1,   /* 54: of_bsn_lacp_stats_reply */
    -1,   /* 55: of_bsn_lacp_stats_request */
    0,    /* 56: of_bsn_pdu_rx_reply */
    0,    /* 57: of_bsn_pdu_rx_request */
    0,    /* 58: of_bsn_pdu_rx_timeout */
    0,    /* 59: of_bsn_pdu_tx_reply */
    0,    /* 60: of_bsn_pdu_tx_request */
    -1,   /* 61: of_bsn_port_counter_stats_reply */
    -1,   /* 62: of_bsn_port_counter_stats_request */
    -1,   /* 63: of_bsn_role_status */
    -1,   /* 64: of_bsn_set_ip_mask */
    -1,   /* 65: of_bsn_set_l2_table_reply */
    -1,   /* 66: of_bsn_set_l2_table_request */
    -1,   /* 67: of_bsn_set_lacp_reply */
    -1,   /* 68: of_bsn_set_lacp_request */
    0,    /* 69: of_bsn_set_mirroring */
    0,    /* 70: of_bsn_set_pktin_suppression_reply */
    0,    /* 71: of_bsn_set_pktin_suppression_request */
    -1,   /* 72: of_bsn_set_switch_pipeline_reply */
    -1,   /* 73: of_bsn_set_switch_pipeline_request */
    -1,   /* 74: of_bsn_shell_command */
    -1,   /* 75: of_bsn_shell_output */
    -1,   /* 76: of_bsn_shell_status */
    0,    /* 77: of_bsn_stats_reply */
    0,    /* 78: of_bsn_stats_request */
    -1,   /* 79: of_bsn_switch_pipeline_stats_reply */
    -1,   /* 80: of_bsn_switch_pipeline_stats_request */
    -1,   /* 81: of_bsn_time_reply */
    -1,   /* 82: of_bsn_time_request */
    0,    /* 83: of_bsn_virtual_port_create_reply */
    0,    /* 84: of_bsn_virtual_port_create_request */
    0,    /* 85: of_bsn_virtual_port_remove_reply */
    0,    /* 86: of_bsn_virtual_port_remove_request */
    -1,   /* 87: of_bsn_vlan_counter_stats_reply */
    -1,   /* 88: of_bsn_vlan_counter_stats_request */
    0,    /* 89: of_desc_stats_reply */
    0,    /* 90: of_desc_stats_request */
    0,    /* 91: of_echo_reply */
    0,    /* 92: of_echo_request */
    0,    /* 93: of_error_msg */
    0,    /* 94: of_experimenter */
    0,    /* 95: of_experimenter_error_msg */
    0,    /* 96: of_experimenter_stats_reply */
    0,    /* 97: of_experimenter_stats_request */
    0,    /* 98: of_features_reply */
    0,    /* 99: of_features_request */
    0,    /* 100: of_flow_add */
    0,    /* 101: of_flow_delete */
    0,    /* 102: of_flow_delete_strict */
    0,    /* 103: of_flow_mod */
    0,    /* 104: of_flow_mod_failed_error_msg */
    0,    /* 105: of_flow_modify */
    0,    /* 106: of_flow_modify_strict */
    0,    /* 107: of_flow_removed */
    0,    /* 108: of_flow_stats_reply */
    0,    /* 109: of_flow_stats_request */
    0,    /* 110: of_get_config_reply */
    0,    /* 111: of_get_config_request */
    0,    /* 112: of_group_add */
    0,    /* 113: of_group_delete */
    0,    /* 114: of_group_desc_stats_reply */
    0,    /* 115: of_group_desc_stats_request */
    0,    /* 116: of_group_features_stats_reply */
    0,    /* 117: of_group_features_stats_request */
    0,    /* 118: of_group_mod */
    0,    /* 119: of_group_mod_failed_error_msg */
    0,    /* 120: of_group_modify */
    0,    /* 121: of_group_stats_reply */
    0,    /* 122: of_group_stats_request */
    0,    /* 123: of_hello */
    0,    /* 124: of_hello_failed_error_msg */
    -1,   /* 125: of_meter_config_stats_reply */
    -1,   /* 126: of_meter_config_stats_request */
    -1,   /* 127: of_meter_features_stats_reply */
    -1,   /* 128: of_meter_features_stats_request */
    -1,   /* 129: of_meter_mod */
    -1,   /* 130: of_meter_mod_failed_error_msg */
    -1,   /* 131: of_meter_stats_reply */
    -1,   /* 132: of_meter_stats_request */
    -1,   /* 133: of_nicira_controller_role_reply */
    -1,   /* 134: of_nicira_controller_role_request */
    0,    /* 135: of_nicira_header */
    2,    /* 136: of_packet_in */
    0,    /* 137: of_packet_out */
    -1,   /* 138: of_port_desc_stats_reply */
    -1,   /* 139: of_port_desc_stats_request */
    0,    /* 140: of_port_mod */
    0,    /* 141: of_port_mod_failed_error_msg */
    0,    /* 142: of_port_stats_reply */
    0,    /* 143: of_port_stats_request */
    0,    /* 144: of_port_status */
    0,    /* 145: of_queue_get_config_reply */
    0,    /* 146: of_queue_get_config_request */
    0,    /* 147: of_queue_op_failed_error_msg */
    0,    /* 148: of_queue_stats_reply */
    0,    /* 149: of_queue_stats_request */
    0,    /* 150: of_role_reply */
    0,    /* 151: of_role_request */
    0,    /* 152: of_role_request_failed_error_msg */
    0,    /* 153: of_set_config */
    0,    /* 154: of_stats_reply */
    0,    /* 155: of_stats_request */
    0,    /* 156: of_switch_config_failed_error_msg */
    -1,   /* 157: of_table_features_failed_error_msg */
    -1,   /* 158: of_table_features_stats_reply */
    -1,   /* 159: of_table_features_stats_request */
    0,    /* 160: of_table_mod */
    0,    /* 161: of_table_mod_failed_error_msg */
    0,    /* 162: of_table_stats_reply */
    0,    /* 163: of_table_stats_request */
    0,    /* 164: of_action */
    0,    /* 165: of_action_bsn */
    0,    /* 166: of_action_bsn_mirror */
    0,    /* 167: of_action_bsn_set_tunnel_dst */
    0,    /* 168: of_action_copy_ttl_in */
    0,    /* 169: of_action_copy_ttl_out */
    0,    /* 170: of_action_dec_mpls_ttl */
    0,    /* 171: of_action_dec_nw_ttl */
    -1,   /* 172: of_action_enqueue */
    0,    /* 173: of_action_experimenter */
    0,    /* 174: of_action_group */
    0,    /* 175: of_action_header */
    -1,   /* 176: of_action_id */
    -1,   /* 177: of_action_id_bsn */
    -1,   /* 178: of_action_id_bsn_mirror */
    -1,   /* 179: of_action_id_bsn_set_tunnel_dst */
    -1,   /* 180: of_action_id_copy_ttl_in */
    -1,   /* 181: of_action_id_copy_ttl_out */
    -1,   /* 182: of_action_id_dec_mpls_ttl */
    -1,   /* 183: of_action_id_dec_nw_ttl */
    -1,   /* 184: of_action_id_experimenter */
    -1,   /* 185: of_action_id_group */
    -1,   /* 186: of_action_id_header */
    -1,   /* 187: of_action_id_nicira */
    -1,   /* 188: of_action_id_nicira_dec_ttl */
    -1,   /* 189: of_action_id_output */
    -1,   /* 190: of_action_id_pop_mpls */
    -1,   /* 191: of_action_id_pop_pbb */
    -1,   /* 192: of_action_id_pop_vlan */
    -1,   /* 193: of_action_id_push_mpls */
    -1,   /* 194: of_action_id_push_pbb */
    -1,   /* 195: of_action_id_push_vlan */
    -1,   /* 196: of_action_id_set_field */
    -1,   /* 197: of_action_id_set_mpls_ttl */
    -1,   /* 198: of_action_id_set_nw_ttl */
    -1,   /* 199: of_action_id_set_queue */
    0,    /* 200: of_action_nicira */
    0,    /* 201: of_action_nicira_dec_ttl */
    0,    /* 202: of_action_output */
    0,    /* 203: of_action_pop_mpls */
    -1,   /* 204: of_action_pop_pbb */
    0,    /* 205: of_action_pop_vlan */
    0,    /* 206: of_action_push_mpls */
    -1,   /* 207: of_action_push_pbb */
    0,    /* 208: of_action_push_vlan */
    -1,   /* 209: of_action_set_dl_dst */
    -1,   /* 210: of_action_set_dl_src */
    0,    /* 211: of_action_set_field */
    -1,   /* 212: of_action_set_mpls_label */
    -1,   /* 213: of_action_set_mpls_tc */
    0,    /* 214: of_action_set_mpls_ttl */
    -1,   /* 215: of_action_set_nw_dst */
    -1,   /* 216: of_action_set_nw_ecn */
    -1,   /* 217: of_action_set_nw_src */
    -1,   /* 218: of_action_set_nw_tos */
    0,    /* 219: of_action_set_nw_ttl */
    0,    /* 220: of_action_set_queue */
    -1,   /* 221: of_action_set_tp_dst */
    -1,   /* 222: of_action_set_tp_src */
    -1,   /* 223: of_action_set_vlan_pcp */
    -1,   /* 224: of_action_set_vlan_vid */
    -1,   /* 225: of_action_strip_vlan */
    -1,   /* 226: of_bsn_controller_connection */
    -1,   /* 227: of_bsn_gentable_bucket_stats_entry */
    -1,   /* 228: of_bsn_gentable_desc_stats_entry */
    -1,   /* 229: of_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 230: of_bsn_gentable_entry_stats_entry */
    -1,   /* 231: of_bsn_gentable_stats_entry */
    0,    /* 232: of_bsn_interface */
    -1,   /* 233: of_bsn_lacp_stats_entry */
    -1,   /* 234: of_bsn_port_counter_stats_entry */
    -1,   /* 235: of_bsn_switch_pipeline_stats_entry */
    -1,   /* 236: of_bsn_tlv */
    -1,   /* 237: of_bsn_tlv_header */
    -1,   /* 238: of_bsn_tlv_idle_notification */
    -1,   /* 239: of_bsn_tlv_idle_time */
    -1,   /* 240: of_bsn_tlv_ipv4 */
    -1,   /* 241: of_bsn_tlv_mac */
    -1,   /* 242: of_bsn_tlv_port */
    -1,   /* 243: of_bsn_tlv_rx_packets */
    -1,   /* 244: of_bsn_tlv_tx_packets */
    -1,   /* 245: of_bsn_tlv_vlan_vid */
    -1,   /* 246: of_bsn_vlan_counter_stats_entry */
    0,    /* 247: of_bsn_vport */
    0,    /* 248: of_bsn_vport_header */
    0,    /* 249: of_bsn_vport_q_in_q */
    0,    /* 250: of_bucket */
    0,    /* 251: of_bucket_counter */
    -1,   /* 252: of_experimenter_stats_header */
    0,    /* 253: of_flow_stats_entry */
    0,    /* 254: of_group_desc_stats_entry */
    0,    /* 255: of_group_stats_entry */
    0,    /* 256: of_header */
    -1,   /* 257: of_hello_elem */
    -1,   /* 258: of_hello_elem_header */
    -1,   /* 259: of_hello_elem_versionbitmap */
    0,    /* 260: of_instruction */
    0,    /* 261: of_instruction_apply_actions */
    -1,   /* 262: of_instruction_bsn */
    -1,   /* 263: of_instruction_bsn_disable_src_mac_check */
    0,    /* 264: of_instruction_clear_actions */
    0,    /* 265: of_instruction_experimenter */
    0,    /* 266: of_instruction_goto_table */
    0,    /* 267: of_instruction_header */
    -1,   /* 268: of_instruction_id */
    -1,   /* 269: of_instruction_id_apply_actions */
    -1,   /* 270: of_instruction_id_bsn */
    -1,   /* 271: of_instruction_id_bsn_disable_src_mac_check */
    -1,   /* 272: of_instruction_id_clear_actions */
    -1,   /* 273: of_instruction_id_experimenter */
    -1,   /* 274: of_instruction_id_goto_table */
    -1,   /* 275: of_instruction_id_header */
    -1,   /* 276: of_instruction_id_meter */
    -1,   /* 277: of_instruction_id_write_actions */
    -1,   /* 278: of_instruction_id_write_metadata */
    -1,   /* 279: of_instruction_meter */
    0,    /* 280: of_instruction_write_actions */
    0,    /* 281: of_instruction_write_metadata */
    -1,   /* 282: of_match_v1 */
    -1,   /* 283: of_match_v2 */
    0,    /* 284: of_match_v3 */
    -1,   /* 285: of_meter_band */
    -1,   /* 286: of_meter_band_drop */
    -1,   /* 287: of_meter_band_dscp_remark */
    -1,   /* 288: of_meter_band_experimenter */
    -1,   /* 289: of_meter_band_header */
    -1,   /* 290: of_meter_band_stats */
    -1,   /* 291: of_meter_config */
    -1,   /* 292: of_meter_features */
    -1,   /* 293: of_meter_stats */
    0,    /* 294: of_oxm */
    0,    /* 295: of_oxm_arp_op */
    0,    /* 296: of_oxm_arp_op_masked */
    0,    /* 297: of_oxm_arp_sha */
    0,    /* 298: of_oxm_arp_sha_masked */
    0,    /* 299: of_oxm_arp_spa */
    0,    /* 300: of_oxm_arp_spa_masked */
    0,    /* 301: of_oxm_arp_tha */
    0,    /* 302: of_oxm_arp_tha_masked */
    0,    /* 303: of_oxm_arp_tpa */
    0,    /* 304: of_oxm_arp_tpa_masked */
    0,    /* 305: of_oxm_bsn_global_vrf_allowed */
    0,    /* 306: of_oxm_bsn_global_vrf_allowed_masked */
    0,    /* 307: of_oxm_bsn_in_ports_128 */
    0,    /* 308: of_oxm_bsn_in_ports_128_masked */
    0,    /* 309: of_oxm_bsn_l3_dst_class_id */
    0,    /* 310: of_oxm_bsn_l3_dst_class_id_masked */
    0,    /* 311: of_oxm_bsn_l3_interface_class_id */
    0,    /* 312: of_oxm_bsn_l3_interface_class_id_masked */
    0,    /* 313: of_oxm_bsn_l3_src_class_id */
    0,    /* 314: of_oxm_bsn_l3_src_class_id_masked */
    0,    /* 315: of_oxm_bsn_lag_id */
    0,    /* 316: of_oxm_bsn_lag_id_masked */
    0,    /* 317: of_oxm_bsn_vrf */
    0,    /* 318: of_oxm_bsn_vrf_masked */
    0,    /* 319: of_oxm_eth_dst */
    0,    /* 320: of_oxm_eth_dst_masked */
    0,    /* 321: of_oxm_eth_src */
    0,    /* 322: of_oxm_eth_src_masked */
    0,    /* 323: of_oxm_eth_type */
    0,    /* 324: of_oxm_eth_type_masked */
    0,    /* 325: of_oxm_header */
    0,    /* 326: of_oxm_icmpv4_code */
    0,    /* 327: of_oxm_icmpv4_code_masked */
    0,    /* 328: of_oxm_icmpv4_type */
    0,    /* 329: of_oxm_icmpv4_type_masked */
    0,    /* 330: of_oxm_icmpv6_code */
    0,    /* 331: of_oxm_icmpv6_code_masked */
    0,    /* 332: of_oxm_icmpv6_type */
    0,    /* 333: of_oxm_icmpv6_type_masked */
    0,    /* 334: of_oxm_in_phy_port */
    0,    /* 335: of_oxm_in_phy_port_masked */
    0,    /* 336: of_oxm_in_port */
    0,    /* 337: of_oxm_in_port_masked */
    0,    /* 338: of_oxm_ip_dscp */
    0,    /* 339: of_oxm_ip_dscp_masked */
    0,    /* 340: of_oxm_ip_ecn */
    0,    /* 341: of_oxm_ip_ecn_masked */
    0,    /* 342: of_oxm_ip_proto */
    0,    /* 343: of_oxm_ip_proto_masked */
    0,    /* 344: of_oxm_ipv4_dst */
    0,    /* 345: of_oxm_ipv4_dst_masked */
    0,    /* 346: of_oxm_ipv4_src */
    0,    /* 347: of_oxm_ipv4_src_masked */
    0,    /* 348: of_oxm_ipv6_dst */
    0,    /* 349: of_oxm_ipv6_dst_masked */
    0,    /* 350: of_oxm_ipv6_flabel */
    0,    /* 351: of_oxm_ipv6_flabel_masked */
    0,    /* 352: of_oxm_ipv6_nd_sll */
    0,    /* 353: of_oxm_ipv6_nd_sll_masked */
    0,    /* 354: of_oxm_ipv6_nd_target */
    0,    /* 355: of_oxm_ipv6_nd_target_masked */
    0,    /* 356: of_oxm_ipv6_nd_tll */
    0,    /* 357: of_oxm_ipv6_nd_tll_masked */
    0,    /* 358: of_oxm_ipv6_src */
    0,    /* 359: of_oxm_ipv6_src_masked */
    0,    /* 360: of_oxm_metadata */
    0,    /* 361: of_oxm_metadata_masked */
    0,    /* 362: of_oxm_mpls_label */
    0,    /* 363: of_oxm_mpls_label_masked */
    0,    /* 364: of_oxm_mpls_tc */
    0,    /* 365: of_oxm_mpls_tc_masked */
    0,    /* 366: of_oxm_sctp_dst */
    0,    /* 367: of_oxm_sctp_dst_masked */
    0,    /* 368: of_oxm_sctp_src */
    0,    /* 369: of_oxm_sctp_src_masked */
    0,    /* 370: of_oxm_tcp_dst */
    0,    /* 371: of_oxm_tcp_dst_masked */
    0,    /* 372: of_oxm_tcp_src */
    0,    /* 373: of_oxm_tcp_src_masked */
    0,    /* 374: of_oxm_udp_dst */
    0,    /* 375: of_oxm_udp_dst_masked */
    0,    /* 376: of_oxm_udp_src */
    0,    /* 377: of_oxm_udp_src_masked */
    0,    /* 378: of_oxm_vlan_pcp */
    0,    /* 379: of_oxm_vlan_pcp_masked */
    0,    /* 380: of_oxm_vlan_vid */
    0,    /* 381: of_oxm_vlan_vid_masked */
    0,    /* 382: of_packet_queue */
    0,    /* 383: of_port_desc */
    0,    /* 384: of_port_stats_entry */
    0,    /* 385: of_queue_prop */
    0,    /* 386: of_queue_prop_experimenter */
    0,    /* 387: of_queue_prop_header */
    0,    /* 388: of_queue_prop_max_rate */
    0,    /* 389: of_queue_prop_min_rate */
    0,    /* 390: of_queue_stats_entry */
    -1,   /* 391: of_table_feature_prop */
    -1,   /* 392: of_table_feature_prop_apply_actions */
    -1,   /* 393: of_table_feature_prop_apply_actions_miss */
    -1,   /* 394: of_table_feature_prop_apply_setfield */
    -1,   /* 395: of_table_feature_prop_apply_setfield_miss */
    -1,   /* 396: of_table_feature_prop_experimenter */
    -1,   /* 397: of_table_feature_prop_header */
    -1,   /* 398: of_table_feature_prop_instructions */
    -1,   /* 399: of_table_feature_prop_instructions_miss */
    -1,   /* 400: of_table_feature_prop_match */
    -1,   /* 401: of_table_feature_prop_next_tables */
    -1,   /* 402: of_table_feature_prop_next_tables_miss */
    -1,   /* 403: of_table_feature_prop_wildcards */
    -1,   /* 404: of_table_feature_prop_write_actions */
    -1,   /* 405: of_table_feature_prop_write_actions_miss */
    -1,   /* 406: of_table_feature_prop_write_setfield */
    -1,   /* 407: of_table_feature_prop_write_setfield_miss */
    -1,   /* 408: of_table_features */
    0,    /* 409: of_table_stats_entry */
    -1,   /* 410: of_uint32 */
    -1,   /* 411: of_uint64 */
    -1,   /* 412: of_uint8 */
    0,    /* 413: of_list_action */
    -1,   /* 414: of_list_action_id */
    -1,   /* 415: of_list_bsn_controller_connection */
    -1,   /* 416: of_list_bsn_gentable_bucket_stats_entry */
    -1,   /* 417: of_list_bsn_gentable_desc_stats_entry */
    -1,   /* 418: of_list_bsn_gentable_entry_desc_stats_entry */
    -1,   /* 419: of_list_bsn_gentable_entry_stats_entry */
    -1,   /* 420: of_list_bsn_gentable_stats_entry */
    0,    /* 421: of_list_bsn_interface */
    -1,   /* 422: of_list_bsn_lacp_stats_entry */
    -1,   /* 423: of_list_bsn_port_counter_stats_entry */
    -1,   /* 424: of_list_bsn_switch_pipeline_stats_entry */
    -1,   /* 425: of_list_bsn_tlv */
    -1,   /* 426: of_list_bsn_vlan_counter_stats_entry */
    0,    /* 427: of_list_bucket */
    0,    /* 428: of_list_bucket_counter */
    0,    /* 429: of_list_flow_stats_entry */
    0,    /* 430: of_list_group_desc_stats_entry */
    0,    /* 431: of_list_group_stats_entry */
    -1,   /* 432: of_list_hello_elem */
    0,    /* 433: of_list_instruction */
    -1,   /* 434: of_list_meter_band */
    -1,   /* 435: of_list_meter_band_stats */
    -1,   /* 436: of_list_meter_stats */
    0,    /* 437: of_list_oxm */
    0,    /* 438: of_list_packet_queue */
    0,    /* 439: of_list_port_desc */
    0,    /* 440: of_list_port_stats_entry */
    0,    /* 441: of_list_queue_prop */
    0,    /* 442: of_list_queue_stats_entry */
    -1,   /* 443: of_list_table_feature_prop */
    -1,   /* 444: of_list_table_features */
    0,    /* 445: of_list_table_stats_entry */
    -1,   /* 446: of_list_uint32 */
    -1,   /* 447: of_list_uint64 */
    -1    /* 448: of_list_uint8 */
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
    0,    /* 12: of_bsn_bw_clear_data_reply */
    0,    /* 13: of_bsn_bw_clear_data_request */
    0,    /* 14: of_bsn_bw_enable_get_reply */
    0,    /* 15: of_bsn_bw_enable_get_request */
    0,    /* 16: of_bsn_bw_enable_set_reply */
    0,    /* 17: of_bsn_bw_enable_set_request */
    0,    /* 18: of_bsn_controller_connections_reply */
    0,    /* 19: of_bsn_controller_connections_request */
    0,    /* 20: of_bsn_flow_idle */
    0,    /* 21: of_bsn_flow_idle_enable_get_reply */
    0,    /* 22: of_bsn_flow_idle_enable_get_request */
    0,    /* 23: of_bsn_flow_idle_enable_set_reply */
    0,    /* 24: of_bsn_flow_idle_enable_set_request */
    0,    /* 25: of_bsn_gentable_bucket_stats_reply */
    0,    /* 26: of_bsn_gentable_bucket_stats_request */
    0,    /* 27: of_bsn_gentable_clear_reply */
    0,    /* 28: of_bsn_gentable_clear_request */
    0,    /* 29: of_bsn_gentable_desc_stats_reply */
    0,    /* 30: of_bsn_gentable_desc_stats_request */
    0,    /* 31: of_bsn_gentable_entry_add */
    0,    /* 32: of_bsn_gentable_entry_delete */
    0,    /* 33: of_bsn_gentable_entry_desc_stats_reply */
    0,    /* 34: of_bsn_gentable_entry_desc_stats_request */
    0,    /* 35: of_bsn_gentable_entry_stats_reply */
    0,    /* 36: of_bsn_gentable_entry_stats_request */
    0,    /* 37: of_bsn_gentable_set_buckets_size */
    0,    /* 38: of_bsn_gentable_stats_reply */
    0,    /* 39: of_bsn_gentable_stats_request */
    0,    /* 40: of_bsn_get_interfaces_reply */
    0,    /* 41: of_bsn_get_interfaces_request */
    -1,   /* 42: of_bsn_get_ip_mask_reply */
    -1,   /* 43: of_bsn_get_ip_mask_request */
    -1,   /* 44: of_bsn_get_l2_table_reply */
    -1,   /* 45: of_bsn_get_l2_table_request */
    0,    /* 46: of_bsn_get_mirroring_reply */
    0,    /* 47: of_bsn_get_mirroring_request */
    0,    /* 48: of_bsn_get_switch_pipeline_reply */
    0,    /* 49: of_bsn_get_switch_pipeline_request */
    0,    /* 50: of_bsn_header */
    -1,   /* 51: of_bsn_hybrid_get_reply */
    -1,   /* 52: of_bsn_hybrid_get_request */
    0,    /* 53: of_bsn_lacp_convergence_notif */
    0,    /* 54: of_bsn_lacp_stats_reply */
    0,    /* 55: of_bsn_lacp_stats_request */
    0,    /* 56: of_bsn_pdu_rx_reply */
    0,    /* 57: of_bsn_pdu_rx_request */
    0,    /* 58: of_bsn_pdu_rx_timeout */
    0,    /* 59: of_bsn_pdu_tx_reply */
    0,    /* 60: of_bsn_pdu_tx_request */
    0,    /* 61: of_bsn_port_counter_stats_reply */
    0,    /* 62: of_bsn_port_counter_stats_request */
    0,    /* 63: of_bsn_role_status */
    -1,   /* 64: of_bsn_set_ip_mask */
    -1,   /* 65: of_bsn_set_l2_table_reply */
    -1,   /* 66: of_bsn_set_l2_table_request */
    0,    /* 67: of_bsn_set_lacp_reply */
    0,    /* 68: of_bsn_set_lacp_request */
    0,    /* 69: of_bsn_set_mirroring */
    0,    /* 70: of_bsn_set_pktin_suppression_reply */
    0,    /* 71: of_bsn_set_pktin_suppression_request */
    0,    /* 72: of_bsn_set_switch_pipeline_reply */
    0,    /* 73: of_bsn_set_switch_pipeline_request */
    -1,   /* 74: of_bsn_shell_command */
    -1,   /* 75: of_bsn_shell_output */
    -1,   /* 76: of_bsn_shell_status */
    0,    /* 77: of_bsn_stats_reply */
    0,    /* 78: of_bsn_stats_request */
    0,    /* 79: of_bsn_switch_pipeline_stats_reply */
    0,    /* 80: of_bsn_switch_pipeline_stats_request */
    0,    /* 81: of_bsn_time_reply */
    0,    /* 82: of_bsn_time_request */
    0,    /* 83: of_bsn_virtual_port_create_reply */
    0,    /* 84: of_bsn_virtual_port_create_request */
    0,    /* 85: of_bsn_virtual_port_remove_reply */
    0,    /* 86: of_bsn_virtual_port_remove_request */
    0,    /* 87: of_bsn_vlan_counter_stats_reply */
    0,    /* 88: of_bsn_vlan_counter_stats_request */
    0,    /* 89: of_desc_stats_reply */
    0,    /* 90: of_desc_stats_request */
    0,    /* 91: of_echo_reply */
    0,    /* 92: of_echo_request */
    0,    /* 93: of_error_msg */
    0,    /* 94: of_experimenter */
    0,    /* 95: of_experimenter_error_msg */
    0,    /* 96: of_experimenter_stats_reply */
    0,    /* 97: of_experimenter_stats_request */
    0,    /* 98: of_features_reply */
    0,    /* 99: of_features_request */
    0,    /* 100: of_flow_add */
    0,    /* 101: of_flow_delete */
    0,    /* 102: of_flow_delete_strict */
    0,    /* 103: of_flow_mod */
    0,    /* 104: of_flow_mod_failed_error_msg */
    0,    /* 105: of_flow_modify */
    0,    /* 106: of_flow_modify_strict */
    0,    /* 107: of_flow_removed */
    0,    /* 108: of_flow_stats_reply */
    0,    /* 109: of_flow_stats_request */
    0,    /* 110: of_get_config_reply */
    0,    /* 111: of_get_config_request */
    0,    /* 112: of_group_add */
    0,    /* 113: of_group_delete */
    0,    /* 114: of_group_desc_stats_reply */
    0,    /* 115: of_group_desc_stats_request */
    0,    /* 116: of_group_features_stats_reply */
    0,    /* 117: of_group_features_stats_request */
    0,    /* 118: of_group_mod */
    0,    /* 119: of_group_mod_failed_error_msg */
    0,    /* 120: of_group_modify */
    0,    /* 121: of_group_stats_reply */
    0,    /* 122: of_group_stats_request */
    0,    /* 123: of_hello */
    0,    /* 124: of_hello_failed_error_msg */
    0,    /* 125: of_meter_config_stats_reply */
    0,    /* 126: of_meter_config_stats_request */
    0,    /* 127: of_meter_features_stats_reply */
    0,    /* 128: of_meter_features_stats_request */
    0,    /* 129: of_meter_mod */
    0,    /* 130: of_meter_mod_failed_error_msg */
    0,    /* 131: of_meter_stats_reply */
    0,    /* 132: of_meter_stats_request */
    -1,   /* 133: of_nicira_controller_role_reply */
    -1,   /* 134: of_nicira_controller_role_request */
    0,    /* 135: of_nicira_header */
    2,    /* 136: of_packet_in */
    0,    /* 137: of_packet_out */
    0,    /* 138: of_port_desc_stats_reply */
    0,    /* 139: of_port_desc_stats_request */
    0,    /* 140: of_port_mod */
    0,    /* 141: of_port_mod_failed_error_msg */
    0,    /* 142: of_port_stats_reply */
    0,    /* 143: of_port_stats_request */
    0,    /* 144: of_port_status */
    0,    /* 145: of_queue_get_config_reply */
    0,    /* 146: of_queue_get_config_request */
    0,    /* 147: of_queue_op_failed_error_msg */
    0,    /* 148: of_queue_stats_reply */
    0,    /* 149: of_queue_stats_request */
    0,    /* 150: of_role_reply */
    0,    /* 151: of_role_request */
    0,    /* 152: of_role_request_failed_error_msg */
    0,    /* 153: of_set_config */
    0,    /* 154: of_stats_reply */
    0,    /* 155: of_stats_request */
    0,    /* 156: of_switch_config_failed_error_msg */
    0,    /* 157: of_table_features_failed_error_msg */
    0,    /* 158: of_table_features_stats_reply */
    0,    /* 159: of_table_features_stats_request */
    0,    /* 160: of_table_mod */
    0,    /* 161: of_table_mod_failed_error_msg */
    0,    /* 162: of_table_stats_reply */
    0,    /* 163: of_table_stats_request */
    0,    /* 164: of_action */
    0,    /* 165: of_action_bsn */
    0,    /* 166: of_action_bsn_mirror */
    0,    /* 167: of_action_bsn_set_tunnel_dst */
    0,    /* 168: of_action_copy_ttl_in */
    0,    /* 169: of_action_copy_ttl_out */
    0,    /* 170: of_action_dec_mpls_ttl */
    0,    /* 171: of_action_dec_nw_ttl */
    -1,   /* 172: of_action_enqueue */
    0,    /* 173: of_action_experimenter */
    0,    /* 174: of_action_group */
    0,    /* 175: of_action_header */
    0,    /* 176: of_action_id */
    0,    /* 177: of_action_id_bsn */
    0,    /* 178: of_action_id_bsn_mirror */
    0,    /* 179: of_action_id_bsn_set_tunnel_dst */
    0,    /* 180: of_action_id_copy_ttl_in */
    0,    /* 181: of_action_id_copy_ttl_out */
    0,    /* 182: of_action_id_dec_mpls_ttl */
    0,    /* 183: of_action_id_dec_nw_ttl */
    0,    /* 184: of_action_id_experimenter */
    0,    /* 185: of_action_id_group */
    0,    /* 186: of_action_id_header */
    0,    /* 187: of_action_id_nicira */
    0,    /* 188: of_action_id_nicira_dec_ttl */
    0,    /* 189: of_action_id_output */
    0,    /* 190: of_action_id_pop_mpls */
    0,    /* 191: of_action_id_pop_pbb */
    0,    /* 192: of_action_id_pop_vlan */
    0,    /* 193: of_action_id_push_mpls */
    0,    /* 194: of_action_id_push_pbb */
    0,    /* 195: of_action_id_push_vlan */
    0,    /* 196: of_action_id_set_field */
    0,    /* 197: of_action_id_set_mpls_ttl */
    0,    /* 198: of_action_id_set_nw_ttl */
    0,    /* 199: of_action_id_set_queue */
    0,    /* 200: of_action_nicira */
    0,    /* 201: of_action_nicira_dec_ttl */
    0,    /* 202: of_action_output */
    0,    /* 203: of_action_pop_mpls */
    0,    /* 204: of_action_pop_pbb */
    0,    /* 205: of_action_pop_vlan */
    0,    /* 206: of_action_push_mpls */
    0,    /* 207: of_action_push_pbb */
    0,    /* 208: of_action_push_vlan */
    -1,   /* 209: of_action_set_dl_dst */
    -1,   /* 210: of_action_set_dl_src */
    0,    /* 211: of_action_set_field */
    -1,   /* 212: of_action_set_mpls_label */
    -1,   /* 213: of_action_set_mpls_tc */
    0,    /* 214: of_action_set_mpls_ttl */
    -1,   /* 215: of_action_set_nw_dst */
    -1,   /* 216: of_action_set_nw_ecn */
    -1,   /* 217: of_action_set_nw_src */
    -1,   /* 218: of_action_set_nw_tos */
    0,    /* 219: of_action_set_nw_ttl */
    0,    /* 220: of_action_set_queue */
    -1,   /* 221: of_action_set_tp_dst */
    -1,   /* 222: of_action_set_tp_src */
    -1,   /* 223: of_action_set_vlan_pcp */
    -1,   /* 224: of_action_set_vlan_vid */
    -1,   /* 225: of_action_strip_vlan */
    0,    /* 226: of_bsn_controller_connection */
    0,    /* 227: of_bsn_gentable_bucket_stats_entry */
    0,    /* 228: of_bsn_gentable_desc_stats_entry */
    0,    /* 229: of_bsn_gentable_entry_desc_stats_entry */
    0,    /* 230: of_bsn_gentable_entry_stats_entry */
    0,    /* 231: of_bsn_gentable_stats_entry */
    0,    /* 232: of_bsn_interface */
    0,    /* 233: of_bsn_lacp_stats_entry */
    0,    /* 234: of_bsn_port_counter_stats_entry */
    0,    /* 235: of_bsn_switch_pipeline_stats_entry */
    0,    /* 236: of_bsn_tlv */
    0,    /* 237: of_bsn_tlv_header */
    0,    /* 238: of_bsn_tlv_idle_notification */
    0,    /* 239: of_bsn_tlv_idle_time */
    0,    /* 240: of_bsn_tlv_ipv4 */
    0,    /* 241: of_bsn_tlv_mac */
    0,    /* 242: of_bsn_tlv_port */
    0,    /* 243: of_bsn_tlv_rx_packets */
    0,    /* 244: of_bsn_tlv_tx_packets */
    0,    /* 245: of_bsn_tlv_vlan_vid */
    0,    /* 246: of_bsn_vlan_counter_stats_entry */
    0,    /* 247: of_bsn_vport */
    0,    /* 248: of_bsn_vport_header */
    0,    /* 249: of_bsn_vport_q_in_q */
    0,    /* 250: of_bucket */
    0,    /* 251: of_bucket_counter */
    0,    /* 252: of_experimenter_stats_header */
    0,    /* 253: of_flow_stats_entry */
    0,    /* 254: of_group_desc_stats_entry */
    0,    /* 255: of_group_stats_entry */
    0,    /* 256: of_header */
    0,    /* 257: of_hello_elem */
    0,    /* 258: of_hello_elem_header */
    0,    /* 259: of_hello_elem_versionbitmap */
    0,    /* 260: of_instruction */
    0,    /* 261: of_instruction_apply_actions */
    0,    /* 262: of_instruction_bsn */
    0,    /* 263: of_instruction_bsn_disable_src_mac_check */
    0,    /* 264: of_instruction_clear_actions */
    0,    /* 265: of_instruction_experimenter */
    0,    /* 266: of_instruction_goto_table */
    0,    /* 267: of_instruction_header */
    0,    /* 268: of_instruction_id */
    0,    /* 269: of_instruction_id_apply_actions */
    0,    /* 270: of_instruction_id_bsn */
    0,    /* 271: of_instruction_id_bsn_disable_src_mac_check */
    0,    /* 272: of_instruction_id_clear_actions */
    0,    /* 273: of_instruction_id_experimenter */
    0,    /* 274: of_instruction_id_goto_table */
    0,    /* 275: of_instruction_id_header */
    0,    /* 276: of_instruction_id_meter */
    0,    /* 277: of_instruction_id_write_actions */
    0,    /* 278: of_instruction_id_write_metadata */
    0,    /* 279: of_instruction_meter */
    0,    /* 280: of_instruction_write_actions */
    0,    /* 281: of_instruction_write_metadata */
    -1,   /* 282: of_match_v1 */
    -1,   /* 283: of_match_v2 */
    0,    /* 284: of_match_v3 */
    0,    /* 285: of_meter_band */
    0,    /* 286: of_meter_band_drop */
    0,    /* 287: of_meter_band_dscp_remark */
    0,    /* 288: of_meter_band_experimenter */
    0,    /* 289: of_meter_band_header */
    0,    /* 290: of_meter_band_stats */
    0,    /* 291: of_meter_config */
    0,    /* 292: of_meter_features */
    0,    /* 293: of_meter_stats */
    0,    /* 294: of_oxm */
    0,    /* 295: of_oxm_arp_op */
    0,    /* 296: of_oxm_arp_op_masked */
    0,    /* 297: of_oxm_arp_sha */
    0,    /* 298: of_oxm_arp_sha_masked */
    0,    /* 299: of_oxm_arp_spa */
    0,    /* 300: of_oxm_arp_spa_masked */
    0,    /* 301: of_oxm_arp_tha */
    0,    /* 302: of_oxm_arp_tha_masked */
    0,    /* 303: of_oxm_arp_tpa */
    0,    /* 304: of_oxm_arp_tpa_masked */
    0,    /* 305: of_oxm_bsn_global_vrf_allowed */
    0,    /* 306: of_oxm_bsn_global_vrf_allowed_masked */
    0,    /* 307: of_oxm_bsn_in_ports_128 */
    0,    /* 308: of_oxm_bsn_in_ports_128_masked */
    0,    /* 309: of_oxm_bsn_l3_dst_class_id */
    0,    /* 310: of_oxm_bsn_l3_dst_class_id_masked */
    0,    /* 311: of_oxm_bsn_l3_interface_class_id */
    0,    /* 312: of_oxm_bsn_l3_interface_class_id_masked */
    0,    /* 313: of_oxm_bsn_l3_src_class_id */
    0,    /* 314: of_oxm_bsn_l3_src_class_id_masked */
    0,    /* 315: of_oxm_bsn_lag_id */
    0,    /* 316: of_oxm_bsn_lag_id_masked */
    0,    /* 317: of_oxm_bsn_vrf */
    0,    /* 318: of_oxm_bsn_vrf_masked */
    0,    /* 319: of_oxm_eth_dst */
    0,    /* 320: of_oxm_eth_dst_masked */
    0,    /* 321: of_oxm_eth_src */
    0,    /* 322: of_oxm_eth_src_masked */
    0,    /* 323: of_oxm_eth_type */
    0,    /* 324: of_oxm_eth_type_masked */
    0,    /* 325: of_oxm_header */
    0,    /* 326: of_oxm_icmpv4_code */
    0,    /* 327: of_oxm_icmpv4_code_masked */
    0,    /* 328: of_oxm_icmpv4_type */
    0,    /* 329: of_oxm_icmpv4_type_masked */
    0,    /* 330: of_oxm_icmpv6_code */
    0,    /* 331: of_oxm_icmpv6_code_masked */
    0,    /* 332: of_oxm_icmpv6_type */
    0,    /* 333: of_oxm_icmpv6_type_masked */
    0,    /* 334: of_oxm_in_phy_port */
    0,    /* 335: of_oxm_in_phy_port_masked */
    0,    /* 336: of_oxm_in_port */
    0,    /* 337: of_oxm_in_port_masked */
    0,    /* 338: of_oxm_ip_dscp */
    0,    /* 339: of_oxm_ip_dscp_masked */
    0,    /* 340: of_oxm_ip_ecn */
    0,    /* 341: of_oxm_ip_ecn_masked */
    0,    /* 342: of_oxm_ip_proto */
    0,    /* 343: of_oxm_ip_proto_masked */
    0,    /* 344: of_oxm_ipv4_dst */
    0,    /* 345: of_oxm_ipv4_dst_masked */
    0,    /* 346: of_oxm_ipv4_src */
    0,    /* 347: of_oxm_ipv4_src_masked */
    0,    /* 348: of_oxm_ipv6_dst */
    0,    /* 349: of_oxm_ipv6_dst_masked */
    0,    /* 350: of_oxm_ipv6_flabel */
    0,    /* 351: of_oxm_ipv6_flabel_masked */
    0,    /* 352: of_oxm_ipv6_nd_sll */
    0,    /* 353: of_oxm_ipv6_nd_sll_masked */
    0,    /* 354: of_oxm_ipv6_nd_target */
    0,    /* 355: of_oxm_ipv6_nd_target_masked */
    0,    /* 356: of_oxm_ipv6_nd_tll */
    0,    /* 357: of_oxm_ipv6_nd_tll_masked */
    0,    /* 358: of_oxm_ipv6_src */
    0,    /* 359: of_oxm_ipv6_src_masked */
    0,    /* 360: of_oxm_metadata */
    0,    /* 361: of_oxm_metadata_masked */
    0,    /* 362: of_oxm_mpls_label */
    0,    /* 363: of_oxm_mpls_label_masked */
    0,    /* 364: of_oxm_mpls_tc */
    0,    /* 365: of_oxm_mpls_tc_masked */
    0,    /* 366: of_oxm_sctp_dst */
    0,    /* 367: of_oxm_sctp_dst_masked */
    0,    /* 368: of_oxm_sctp_src */
    0,    /* 369: of_oxm_sctp_src_masked */
    0,    /* 370: of_oxm_tcp_dst */
    0,    /* 371: of_oxm_tcp_dst_masked */
    0,    /* 372: of_oxm_tcp_src */
    0,    /* 373: of_oxm_tcp_src_masked */
    0,    /* 374: of_oxm_udp_dst */
    0,    /* 375: of_oxm_udp_dst_masked */
    0,    /* 376: of_oxm_udp_src */
    0,    /* 377: of_oxm_udp_src_masked */
    0,    /* 378: of_oxm_vlan_pcp */
    0,    /* 379: of_oxm_vlan_pcp_masked */
    0,    /* 380: of_oxm_vlan_vid */
    0,    /* 381: of_oxm_vlan_vid_masked */
    0,    /* 382: of_packet_queue */
    0,    /* 383: of_port_desc */
    0,    /* 384: of_port_stats_entry */
    0,    /* 385: of_queue_prop */
    0,    /* 386: of_queue_prop_experimenter */
    0,    /* 387: of_queue_prop_header */
    0,    /* 388: of_queue_prop_max_rate */
    0,    /* 389: of_queue_prop_min_rate */
    0,    /* 390: of_queue_stats_entry */
    0,    /* 391: of_table_feature_prop */
    0,    /* 392: of_table_feature_prop_apply_actions */
    0,    /* 393: of_table_feature_prop_apply_actions_miss */
    0,    /* 394: of_table_feature_prop_apply_setfield */
    0,    /* 395: of_table_feature_prop_apply_setfield_miss */
    0,    /* 396: of_table_feature_prop_experimenter */
    0,    /* 397: of_table_feature_prop_header */
    0,    /* 398: of_table_feature_prop_instructions */
    0,    /* 399: of_table_feature_prop_instructions_miss */
    0,    /* 400: of_table_feature_prop_match */
    0,    /* 401: of_table_feature_prop_next_tables */
    0,    /* 402: of_table_feature_prop_next_tables_miss */
    0,    /* 403: of_table_feature_prop_wildcards */
    0,    /* 404: of_table_feature_prop_write_actions */
    0,    /* 405: of_table_feature_prop_write_actions_miss */
    0,    /* 406: of_table_feature_prop_write_setfield */
    0,    /* 407: of_table_feature_prop_write_setfield_miss */
    0,    /* 408: of_table_features */
    0,    /* 409: of_table_stats_entry */
    0,    /* 410: of_uint32 */
    0,    /* 411: of_uint64 */
    0,    /* 412: of_uint8 */
    0,    /* 413: of_list_action */
    0,    /* 414: of_list_action_id */
    0,    /* 415: of_list_bsn_controller_connection */
    0,    /* 416: of_list_bsn_gentable_bucket_stats_entry */
    0,    /* 417: of_list_bsn_gentable_desc_stats_entry */
    0,    /* 418: of_list_bsn_gentable_entry_desc_stats_entry */
    0,    /* 419: of_list_bsn_gentable_entry_stats_entry */
    0,    /* 420: of_list_bsn_gentable_stats_entry */
    0,    /* 421: of_list_bsn_interface */
    0,    /* 422: of_list_bsn_lacp_stats_entry */
    0,    /* 423: of_list_bsn_port_counter_stats_entry */
    0,    /* 424: of_list_bsn_switch_pipeline_stats_entry */
    0,    /* 425: of_list_bsn_tlv */
    0,    /* 426: of_list_bsn_vlan_counter_stats_entry */
    0,    /* 427: of_list_bucket */
    0,    /* 428: of_list_bucket_counter */
    0,    /* 429: of_list_flow_stats_entry */
    0,    /* 430: of_list_group_desc_stats_entry */
    0,    /* 431: of_list_group_stats_entry */
    0,    /* 432: of_list_hello_elem */
    0,    /* 433: of_list_instruction */
    0,    /* 434: of_list_meter_band */
    0,    /* 435: of_list_meter_band_stats */
    0,    /* 436: of_list_meter_stats */
    0,    /* 437: of_list_oxm */
    0,    /* 438: of_list_packet_queue */
    0,    /* 439: of_list_port_desc */
    0,    /* 440: of_list_port_stats_entry */
    0,    /* 441: of_list_queue_prop */
    0,    /* 442: of_list_queue_stats_entry */
    0,    /* 443: of_list_table_feature_prop */
    0,    /* 444: of_list_table_features */
    0,    /* 445: of_list_table_stats_entry */
    0,    /* 446: of_list_uint32 */
    0,    /* 447: of_list_uint64 */
    0     /* 448: of_list_uint8 */
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
    ASSERT(OF_OBJECT_TO_WBUF(obj) != NULL);
    // ASSERT(obj is message)
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
    ASSERT(OF_OBJECT_TO_WBUF(obj) != NULL);
    // ASSERT(obj is message)
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
    ASSERT(wbuf != NULL);

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
    ASSERT(wbuf != NULL);

    of_wire_buffer_u16_set(wbuf, 
        OF_OBJECT_ABSOLUTE_OFFSET(obj, TLV16_WIRE_LENGTH_OFFSET), bytes);
}

/**
 * Get the type field from the wire for a standard TLV object that uses
 * uint16 for both type and length.
 * @param obj The object being referenced
 * @param wire_type (out) Where to store the type
 */

static void
of_tlv16_wire_type_get(of_object_t *obj, int *wire_type)
{
    uint16_t val16;
    of_wire_buffer_t *wbuf = OF_OBJECT_TO_WBUF(obj);

    of_wire_buffer_u16_get(wbuf, OF_OBJECT_ABSOLUTE_OFFSET(obj, 
           TLV16_WIRE_TYPE_OFFSET), &val16);

    *wire_type = val16;
}

/**
 * Get the object ID of an extended action
 * @param obj The object being referenced
 * @param id Where to store the object ID
 * @fixme:  This should be auto generated
 *
 * If unable to map to known extension, set id to generic "experimenter"
 */

#define OF_ACTION_EXPERIMENTER_ID_OFFSET 4
#define OF_ACTION_EXPERIMENTER_SUBTYPE_OFFSET 8


static void
extension_action_object_id_get(of_object_t *obj, of_object_id_t *id)
{
    uint32_t exp_id;
    uint8_t *buf;

    *id = OF_ACTION_EXPERIMENTER;

    buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    
    buf_u32_get(buf + OF_ACTION_EXPERIMENTER_ID_OFFSET, &exp_id);

    switch (exp_id) {
    case OF_EXPERIMENTER_ID_BSN: {
        uint32_t subtype;
        buf_u32_get(buf + OF_ACTION_EXPERIMENTER_SUBTYPE_OFFSET, &subtype);
        switch (subtype) {
        case 1: *id = OF_ACTION_BSN_MIRROR; break;
        case 2: *id = OF_ACTION_BSN_SET_TUNNEL_DST; break;
        }
        break;
    }
    case OF_EXPERIMENTER_ID_NICIRA: {
        uint16_t subtype;
        buf_u16_get(buf + OF_ACTION_EXPERIMENTER_SUBTYPE_OFFSET, &subtype);
        switch (subtype) {
        case 18: *id = OF_ACTION_NICIRA_DEC_TTL; break;
        }
        break;
    }
    }
}

/**
 * Get the object ID of an extended action
 * @param obj The object being referenced
 * @param id Where to store the object ID
 * @fixme:  This should be auto generated
 *
 * If unable to map to known extension, set id to generic "experimenter"
 */

static void
extension_action_id_object_id_get(of_object_t *obj, of_object_id_t *id)
{
    uint32_t exp_id;
    uint8_t *buf;

    *id = OF_ACTION_ID_EXPERIMENTER;

    buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    
    buf_u32_get(buf + OF_ACTION_EXPERIMENTER_ID_OFFSET, &exp_id);

    switch (exp_id) {
    case OF_EXPERIMENTER_ID_BSN: {
        uint32_t subtype;
        buf_u32_get(buf + OF_ACTION_EXPERIMENTER_SUBTYPE_OFFSET, &subtype);
        switch (subtype) {
        case 1: *id = OF_ACTION_ID_BSN_MIRROR; break;
        case 2: *id = OF_ACTION_ID_BSN_SET_TUNNEL_DST; break;
        }
        break;
    }
    case OF_EXPERIMENTER_ID_NICIRA: {
        uint16_t subtype;
        buf_u16_get(buf + OF_ACTION_EXPERIMENTER_SUBTYPE_OFFSET, &subtype);
        switch (subtype) {
        case 18: *id = OF_ACTION_ID_NICIRA_DEC_TTL; break;
        }
        break;
    }
    }
}


/**
 * Get the object ID based on the wire buffer for an action object
 * @param obj The object being referenced
 * @param id Where to store the object ID
 */


void
of_action_wire_object_id_get(of_object_t *obj, of_object_id_t *id)
{
    int wire_type;

    of_tlv16_wire_type_get(obj, &wire_type);
    if (wire_type == OF_EXPERIMENTER_TYPE) {
        extension_action_object_id_get(obj, id);
        return;
    }

    ASSERT(wire_type >= 0 && wire_type < OF_ACTION_ITEM_COUNT);

    *id = of_action_type_to_id[obj->version][wire_type];
    ASSERT(*id != OF_OBJECT_INVALID);
}

/**
 * Get the object ID based on the wire buffer for an action ID object
 * @param obj The object being referenced
 * @param id Where to store the object ID
 */


void
of_action_id_wire_object_id_get(of_object_t *obj, of_object_id_t *id)
{
    int wire_type;

    of_tlv16_wire_type_get(obj, &wire_type);
    if (wire_type == OF_EXPERIMENTER_TYPE) {
        extension_action_id_object_id_get(obj, id);
        return;
    }

    ASSERT(wire_type >= 0 && wire_type < OF_ACTION_ID_ITEM_COUNT);

    *id = of_action_id_type_to_id[obj->version][wire_type];
    ASSERT(*id != OF_OBJECT_INVALID);
}

/**
 * @fixme to do when we have instruction extensions
 * See extension_action above
 */

static int
extension_instruction_object_id_get(of_object_t *obj, of_object_id_t *id)
{
    uint32_t exp_id;
    uint8_t *buf;

    *id = OF_INSTRUCTION_EXPERIMENTER;

    buf = OF_OBJECT_BUFFER_INDEX(obj, 0);

    buf_u32_get(buf + OF_INSTRUCTION_EXPERIMENTER_ID_OFFSET, &exp_id);

    switch (exp_id) {
    case OF_EXPERIMENTER_ID_BSN: {
        uint32_t subtype;
        buf_u32_get(buf + OF_INSTRUCTION_EXPERIMENTER_SUBTYPE_OFFSET, &subtype);
        switch (subtype) {
        case 0: *id = OF_INSTRUCTION_BSN_DISABLE_SRC_MAC_CHECK; break;
        }
        break;
    }
    }

    return OF_ERROR_NONE;
}

/**
 * Get the object ID based on the wire buffer for an instruction object
 * @param obj The object being referenced
 * @param id Where to store the object ID
 */

void
of_instruction_wire_object_id_get(of_object_t *obj, of_object_id_t *id)
{
    int wire_type;

    of_tlv16_wire_type_get(obj, &wire_type);
    if (wire_type == OF_EXPERIMENTER_TYPE) {
        extension_instruction_object_id_get(obj, id);
        return;
    }

    ASSERT(wire_type >= 0 && wire_type < OF_INSTRUCTION_ITEM_COUNT);

    *id = of_instruction_type_to_id[obj->version][wire_type];
    ASSERT(*id != OF_OBJECT_INVALID);
}


/**
 * @fixme to do when we have queue_prop extensions
 * See extension_action above
 */

static void
extension_queue_prop_object_id_get(of_object_t *obj, of_object_id_t *id)
{
    (void)obj;

    *id = OF_QUEUE_PROP_EXPERIMENTER;
}

/**
 * Get the object ID based on the wire buffer for an queue_prop object
 * @param obj The object being referenced
 * @param id Where to store the object ID
 */

void
of_queue_prop_wire_object_id_get(of_object_t *obj, of_object_id_t *id)
{
    int wire_type;

    of_tlv16_wire_type_get(obj, &wire_type);
    if (wire_type == OF_EXPERIMENTER_TYPE) {
        extension_queue_prop_object_id_get(obj, id);
        return;
    }

    ASSERT(wire_type >= 0 && wire_type < OF_QUEUE_PROP_ITEM_COUNT);

    *id = of_queue_prop_type_to_id[obj->version][wire_type];
    ASSERT(*id != OF_OBJECT_INVALID);
}


/**
 * @fixme to do when we have table_feature_prop extensions
 * See extension_action above
 */

static void
extension_table_feature_prop_object_id_get(of_object_t *obj, of_object_id_t *id)
{
    (void)obj;

    *id = OF_TABLE_FEATURE_PROP_EXPERIMENTER;
}

/**
 * Table feature property object ID determination
 *
 * @param obj The object being referenced
 * @param id Where to store the object ID
 */

void
of_table_feature_prop_wire_object_id_get(of_object_t *obj, of_object_id_t *id)
{
    int wire_type;

    of_tlv16_wire_type_get(obj, &wire_type);
    if (wire_type == OF_EXPERIMENTER_TYPE) {
        extension_table_feature_prop_object_id_get(obj, id);
        return;
    }

    ASSERT(wire_type >= 0 && wire_type < OF_TABLE_FEATURE_PROP_ITEM_COUNT);

    *id = of_table_feature_prop_type_to_id[obj->version][wire_type];
    ASSERT(*id != OF_OBJECT_INVALID);
}

/**
 * Get the object ID based on the wire buffer for meter_band object
 * @param obj The object being referenced
 * @param id Where to store the object ID
 */

void
of_meter_band_wire_object_id_get(of_object_t *obj, of_object_id_t *id)
{
    int wire_type;

    of_tlv16_wire_type_get(obj, &wire_type);
    if (wire_type == OF_EXPERIMENTER_TYPE) {
        *id = OF_METER_BAND_EXPERIMENTER;
        return;
    }

    ASSERT(wire_type >= 0 && wire_type < OF_METER_BAND_ITEM_COUNT);

    *id = of_meter_band_type_to_id[obj->version][wire_type];
    ASSERT(*id != OF_OBJECT_INVALID);
}

/**
 * Get the object ID based on the wire buffer for a hello_elem object
 * @param obj The object being referenced
 * @param id Where to store the object ID
 */

void
of_hello_elem_wire_object_id_get(of_object_t *obj, of_object_id_t *id)
{
    int wire_type;

    of_tlv16_wire_type_get(obj, &wire_type);
    ASSERT(wire_type >= 0 && wire_type < OF_HELLO_ELEM_ITEM_COUNT);
    *id = of_hello_elem_type_to_id[obj->version][wire_type];
    ASSERT(*id != OF_OBJECT_INVALID);
}

/**
 * Get the object ID based on the wire buffer for a bsn_tlv object
 * @param obj The object being referenced
 * @param id Where to store the object ID
 */

void
of_bsn_tlv_wire_object_id_get(of_object_t *obj, of_object_id_t *id)
{
    int wire_type;

    of_tlv16_wire_type_get(obj, &wire_type);
    ASSERT(wire_type >= 0 && wire_type < OF_BSN_TLV_ITEM_COUNT);
    *id = of_bsn_tlv_type_to_id[obj->version][wire_type];
    ASSERT(*id != OF_OBJECT_INVALID);
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
        ASSERT(wbuf != NULL);                                           \
        of_wire_buffer_u32_get(wbuf,                                    \
            OF_OBJECT_ABSOLUTE_OFFSET(obj, OXM_HDR_OFFSET), (tl_p));    \
    } while (0)

#define _SET_OXM_TYPE_LEN(obj, tl_p, wbuf) do {                         \
        wbuf = OF_OBJECT_TO_WBUF(obj);                                  \
        ASSERT(wbuf != NULL);                                           \
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

/**
 * Get the object ID of an OXM object based on the wire buffer type
 * @param obj The object whose wire buffer is an OXM type
 * @param id (out) Where the ID is stored 
 */

void
of_oxm_wire_object_id_get(of_object_t *obj, of_object_id_t *id)
{
    uint32_t type_len;
    of_wire_buffer_t *wbuf;

    _GET_OXM_TYPE_LEN(obj, &type_len, wbuf);
    *id = of_oxm_to_object_id(type_len, obj->version);
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

    ASSERT(wbuf != NULL);

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
    ASSERT(wbuf != NULL);

    /* ASSERT(obj is u16-len entry) */

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

    ASSERT(wbuf != NULL);

    /* ASSERT(obj is packet queue obj) */
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

    ASSERT(wbuf != NULL);

    /* ASSERT(obj is packet queue obj) */
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
    ASSERT(obj->parent != NULL);
    ASSERT(obj->parent->object_id == OF_METER_STATS);

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
    ASSERT(wbuf != NULL);
    of_wire_buffer_u16_get(wbuf, 
               OF_OBJECT_ABSOLUTE_OFFSET(obj, OF_METER_STATS_LENGTH_OFFSET),
               &val16);
    *bytes = val16;
}

void
of_meter_stats_wire_length_set(of_object_t *obj, int bytes)
{
    of_wire_buffer_t *wbuf = OF_OBJECT_TO_WBUF(obj);
    ASSERT(wbuf != NULL);

    of_wire_buffer_u16_set(wbuf, 
        OF_OBJECT_ABSOLUTE_OFFSET(obj, OF_METER_STATS_LENGTH_OFFSET), bytes);
}

/*
 * Non-message extension push wire values
 */

int
of_extension_object_wire_push(of_object_t *obj)
{
    of_action_bsn_mirror_t *action_mirror;
    of_action_id_bsn_mirror_t *action_id_mirror;
    of_action_bsn_set_tunnel_dst_t *action_set_tunnel_dst;
    of_action_id_bsn_set_tunnel_dst_t *action_id_set_tunnel_dst;
    of_action_nicira_dec_ttl_t *action_nicira_dec_ttl;
    of_action_id_nicira_dec_ttl_t *action_id_nicira_dec_ttl;

    /* Push exp type, subtype */
    switch (obj->object_id) {
    case OF_ACTION_BSN_MIRROR:
        action_mirror = (of_action_bsn_mirror_t *)obj;
        of_action_bsn_mirror_experimenter_set(action_mirror,
            OF_EXPERIMENTER_ID_BSN);
        of_action_bsn_mirror_subtype_set(action_mirror, 1);
        break;
    case OF_ACTION_ID_BSN_MIRROR:
        action_id_mirror = (of_action_id_bsn_mirror_t *)obj;
        of_action_id_bsn_mirror_experimenter_set(action_id_mirror,
            OF_EXPERIMENTER_ID_BSN);
        of_action_id_bsn_mirror_subtype_set(action_id_mirror, 1);
        break;
    case OF_ACTION_BSN_SET_TUNNEL_DST:
        action_set_tunnel_dst = (of_action_bsn_set_tunnel_dst_t *)obj;
        of_action_bsn_set_tunnel_dst_experimenter_set(action_set_tunnel_dst,
            OF_EXPERIMENTER_ID_BSN);
        of_action_bsn_set_tunnel_dst_subtype_set(action_set_tunnel_dst, 2);
        break;
    case OF_ACTION_ID_BSN_SET_TUNNEL_DST:
        action_id_set_tunnel_dst = (of_action_id_bsn_set_tunnel_dst_t *)obj;
        of_action_id_bsn_set_tunnel_dst_experimenter_set(action_id_set_tunnel_dst,
            OF_EXPERIMENTER_ID_BSN);
        of_action_id_bsn_set_tunnel_dst_subtype_set(action_id_set_tunnel_dst, 2);
        break;
    case OF_ACTION_NICIRA_DEC_TTL:
        action_nicira_dec_ttl = (of_action_nicira_dec_ttl_t *)obj;
        of_action_nicira_dec_ttl_experimenter_set(action_nicira_dec_ttl,
            OF_EXPERIMENTER_ID_NICIRA);
        of_action_nicira_dec_ttl_subtype_set(action_nicira_dec_ttl, 18);
        break;
    case OF_ACTION_ID_NICIRA_DEC_TTL:
        action_id_nicira_dec_ttl = (of_action_id_nicira_dec_ttl_t *)obj;
        of_action_id_nicira_dec_ttl_experimenter_set(action_id_nicira_dec_ttl,
            OF_EXPERIMENTER_ID_NICIRA);
        of_action_id_nicira_dec_ttl_subtype_set(action_id_nicira_dec_ttl, 18);
        break;
    default:
        break;
    }

    return OF_ERROR_NONE;
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
        }
    }
    return OF_OBJECT_INVALID;
}
