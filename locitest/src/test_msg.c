/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */

/**
 *
 * AUTOMATICALLY GENERATED FILE.  Edits will be lost on regen.
 *
 * Message-scalar tests for all versions
 */

#include <locitest/test_common.h>

static int
test_of_aggregate_stats_reply_create_OF_VERSION_1_0(void)
{
    of_aggregate_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_aggregate_stats_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 36);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_AGGREGATE_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_aggregate_stats_reply_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_aggregate_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_aggregate_stats_reply_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_aggregate_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_aggregate_stats_request_create_OF_VERSION_1_0(void)
{
    of_aggregate_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_aggregate_stats_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_AGGREGATE_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_aggregate_stats_request_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_aggregate_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_aggregate_stats_request_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_aggregate_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bad_action_error_msg_create_OF_VERSION_1_0(void)
{
    of_bad_action_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bad_action_error_msg_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BAD_ACTION_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BAD_ACTION_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_bad_action_error_msg_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bad_action_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bad_action_error_msg_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bad_action_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_bad_request_error_msg_create_OF_VERSION_1_0(void)
{
    of_bad_request_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bad_request_error_msg_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BAD_REQUEST_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BAD_REQUEST_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_bad_request_error_msg_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bad_request_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bad_request_error_msg_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bad_request_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_barrier_reply_create_OF_VERSION_1_0(void)
{
    of_barrier_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_barrier_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BARRIER_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BARRIER_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_barrier_reply_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_barrier_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_barrier_reply_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_barrier_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_barrier_request_create_OF_VERSION_1_0(void)
{
    of_barrier_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_barrier_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BARRIER_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BARRIER_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_barrier_request_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_barrier_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_barrier_request_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_barrier_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_bw_clear_data_reply_create_OF_VERSION_1_0(void)
{
    of_bsn_bw_clear_data_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_bw_clear_data_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_CLEAR_DATA_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_BW_CLEAR_DATA_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_bw_clear_data_reply_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_bw_clear_data_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_bw_clear_data_reply_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_bw_clear_data_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_bw_clear_data_request_create_OF_VERSION_1_0(void)
{
    of_bsn_bw_clear_data_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_bw_clear_data_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_CLEAR_DATA_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_BW_CLEAR_DATA_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_bw_clear_data_request_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_bw_clear_data_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_bw_clear_data_request_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_bw_clear_data_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_bw_enable_get_reply_create_OF_VERSION_1_0(void)
{
    of_bsn_bw_enable_get_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_bw_enable_get_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_ENABLE_GET_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_BW_ENABLE_GET_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_bw_enable_get_reply_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_bw_enable_get_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_bw_enable_get_reply_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_bw_enable_get_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_bw_enable_get_request_create_OF_VERSION_1_0(void)
{
    of_bsn_bw_enable_get_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_bw_enable_get_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_ENABLE_GET_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_BW_ENABLE_GET_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_bw_enable_get_request_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_bw_enable_get_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_bw_enable_get_request_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_bw_enable_get_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_bw_enable_set_reply_create_OF_VERSION_1_0(void)
{
    of_bsn_bw_enable_set_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_bw_enable_set_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_ENABLE_SET_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_BW_ENABLE_SET_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_bw_enable_set_reply_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_bw_enable_set_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_bw_enable_set_reply_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_bw_enable_set_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_bw_enable_set_request_create_OF_VERSION_1_0(void)
{
    of_bsn_bw_enable_set_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_bw_enable_set_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_ENABLE_SET_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_BW_ENABLE_SET_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_bw_enable_set_request_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_bw_enable_set_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_bw_enable_set_request_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_bw_enable_set_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_get_interfaces_reply_create_OF_VERSION_1_0(void)
{
    of_bsn_get_interfaces_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_get_interfaces_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_INTERFACES_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GET_INTERFACES_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_get_interfaces_reply_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_get_interfaces_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_get_interfaces_reply_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_get_interfaces_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_get_interfaces_request_create_OF_VERSION_1_0(void)
{
    of_bsn_get_interfaces_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_get_interfaces_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_INTERFACES_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GET_INTERFACES_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_get_interfaces_request_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_get_interfaces_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_get_interfaces_request_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_get_interfaces_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_get_ip_mask_reply_create_OF_VERSION_1_0(void)
{
    of_bsn_get_ip_mask_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_get_ip_mask_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_IP_MASK_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GET_IP_MASK_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_get_ip_mask_reply_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_get_ip_mask_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_get_ip_mask_reply_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_get_ip_mask_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_get_ip_mask_request_create_OF_VERSION_1_0(void)
{
    of_bsn_get_ip_mask_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_get_ip_mask_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_IP_MASK_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GET_IP_MASK_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_get_ip_mask_request_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_get_ip_mask_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_get_ip_mask_request_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_get_ip_mask_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_get_l2_table_reply_create_OF_VERSION_1_0(void)
{
    of_bsn_get_l2_table_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_get_l2_table_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_L2_TABLE_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GET_L2_TABLE_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_get_l2_table_reply_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_get_l2_table_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_get_l2_table_reply_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_get_l2_table_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_get_l2_table_request_create_OF_VERSION_1_0(void)
{
    of_bsn_get_l2_table_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_get_l2_table_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_L2_TABLE_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GET_L2_TABLE_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_get_l2_table_request_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_get_l2_table_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_get_l2_table_request_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_get_l2_table_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_get_mirroring_reply_create_OF_VERSION_1_0(void)
{
    of_bsn_get_mirroring_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_get_mirroring_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_MIRRORING_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GET_MIRRORING_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_get_mirroring_reply_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_get_mirroring_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_get_mirroring_reply_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_get_mirroring_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_get_mirroring_request_create_OF_VERSION_1_0(void)
{
    of_bsn_get_mirroring_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_get_mirroring_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_MIRRORING_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GET_MIRRORING_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_get_mirroring_request_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_get_mirroring_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_get_mirroring_request_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_get_mirroring_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_hybrid_get_reply_create_OF_VERSION_1_0(void)
{
    of_bsn_hybrid_get_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_hybrid_get_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_HYBRID_GET_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_HYBRID_GET_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_hybrid_get_reply_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_hybrid_get_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_hybrid_get_reply_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_hybrid_get_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_hybrid_get_request_create_OF_VERSION_1_0(void)
{
    of_bsn_hybrid_get_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_hybrid_get_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_HYBRID_GET_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_HYBRID_GET_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_hybrid_get_request_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_hybrid_get_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_hybrid_get_request_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_hybrid_get_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_pdu_rx_reply_create_OF_VERSION_1_0(void)
{
    of_bsn_pdu_rx_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_pdu_rx_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 23);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_RX_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_PDU_RX_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_pdu_rx_reply_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_pdu_rx_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_pdu_rx_reply_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_pdu_rx_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_pdu_rx_request_create_OF_VERSION_1_0(void)
{
    of_bsn_pdu_rx_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_pdu_rx_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 26);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_RX_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_PDU_RX_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_pdu_rx_request_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_pdu_rx_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_pdu_rx_request_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_pdu_rx_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_pdu_rx_timeout_create_OF_VERSION_1_0(void)
{
    of_bsn_pdu_rx_timeout_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_pdu_rx_timeout_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 19);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_RX_TIMEOUT);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_PDU_RX_TIMEOUT);

    /* Set up incrementing values for scalar members */
    value = of_bsn_pdu_rx_timeout_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_pdu_rx_timeout_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_pdu_rx_timeout_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_pdu_rx_timeout_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_pdu_tx_reply_create_OF_VERSION_1_0(void)
{
    of_bsn_pdu_tx_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_pdu_tx_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 23);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_TX_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_PDU_TX_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_pdu_tx_reply_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_pdu_tx_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_pdu_tx_reply_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_pdu_tx_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_pdu_tx_request_create_OF_VERSION_1_0(void)
{
    of_bsn_pdu_tx_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_pdu_tx_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 26);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_TX_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_PDU_TX_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_pdu_tx_request_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_pdu_tx_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_pdu_tx_request_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_pdu_tx_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_set_ip_mask_create_OF_VERSION_1_0(void)
{
    of_bsn_set_ip_mask_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_set_ip_mask_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_IP_MASK);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_SET_IP_MASK);

    /* Set up incrementing values for scalar members */
    value = of_bsn_set_ip_mask_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_set_ip_mask_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_set_ip_mask_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_set_ip_mask_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_set_l2_table_reply_create_OF_VERSION_1_0(void)
{
    of_bsn_set_l2_table_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_set_l2_table_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_L2_TABLE_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_SET_L2_TABLE_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_set_l2_table_reply_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_set_l2_table_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_set_l2_table_reply_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_set_l2_table_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_set_l2_table_request_create_OF_VERSION_1_0(void)
{
    of_bsn_set_l2_table_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_set_l2_table_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_L2_TABLE_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_SET_L2_TABLE_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_set_l2_table_request_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_set_l2_table_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_set_l2_table_request_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_set_l2_table_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_set_mirroring_create_OF_VERSION_1_0(void)
{
    of_bsn_set_mirroring_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_set_mirroring_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_MIRRORING);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_SET_MIRRORING);

    /* Set up incrementing values for scalar members */
    value = of_bsn_set_mirroring_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_set_mirroring_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_set_mirroring_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_set_mirroring_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_set_pktin_suppression_reply_create_OF_VERSION_1_0(void)
{
    of_bsn_set_pktin_suppression_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_set_pktin_suppression_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_PKTIN_SUPPRESSION_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_SET_PKTIN_SUPPRESSION_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_set_pktin_suppression_reply_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_set_pktin_suppression_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_set_pktin_suppression_reply_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_set_pktin_suppression_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_set_pktin_suppression_request_create_OF_VERSION_1_0(void)
{
    of_bsn_set_pktin_suppression_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_set_pktin_suppression_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_PKTIN_SUPPRESSION_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_SET_PKTIN_SUPPRESSION_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_set_pktin_suppression_request_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_set_pktin_suppression_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_set_pktin_suppression_request_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_set_pktin_suppression_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_shell_command_create_OF_VERSION_1_0(void)
{
    of_bsn_shell_command_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_shell_command_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SHELL_COMMAND);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_SHELL_COMMAND);

    /* Set up incrementing values for scalar members */
    value = of_bsn_shell_command_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_shell_command_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_shell_command_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_shell_command_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_shell_output_create_OF_VERSION_1_0(void)
{
    of_bsn_shell_output_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_shell_output_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SHELL_OUTPUT);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_SHELL_OUTPUT);

    /* Set up incrementing values for scalar members */
    value = of_bsn_shell_output_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_shell_output_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_shell_output_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_shell_output_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_shell_status_create_OF_VERSION_1_0(void)
{
    of_bsn_shell_status_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_shell_status_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SHELL_STATUS);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_SHELL_STATUS);

    /* Set up incrementing values for scalar members */
    value = of_bsn_shell_status_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_shell_status_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_shell_status_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_shell_status_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_virtual_port_create_reply_create_OF_VERSION_1_0(void)
{
    of_bsn_virtual_port_create_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_virtual_port_create_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VIRTUAL_PORT_CREATE_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_VIRTUAL_PORT_CREATE_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_virtual_port_create_reply_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_virtual_port_create_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_virtual_port_create_reply_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_virtual_port_create_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_virtual_port_create_request_create_OF_VERSION_1_0(void)
{
    of_bsn_virtual_port_create_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_virtual_port_create_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VIRTUAL_PORT_CREATE_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_VIRTUAL_PORT_CREATE_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_virtual_port_create_request_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_virtual_port_create_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_virtual_port_create_request_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_virtual_port_create_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_virtual_port_remove_reply_create_OF_VERSION_1_0(void)
{
    of_bsn_virtual_port_remove_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_virtual_port_remove_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VIRTUAL_PORT_REMOVE_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_VIRTUAL_PORT_REMOVE_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_virtual_port_remove_reply_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_virtual_port_remove_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_virtual_port_remove_reply_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_virtual_port_remove_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_virtual_port_remove_request_create_OF_VERSION_1_0(void)
{
    of_bsn_virtual_port_remove_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_virtual_port_remove_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VIRTUAL_PORT_REMOVE_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_VIRTUAL_PORT_REMOVE_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_virtual_port_remove_request_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_virtual_port_remove_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_virtual_port_remove_request_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_virtual_port_remove_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_desc_stats_reply_create_OF_VERSION_1_0(void)
{
    of_desc_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_desc_stats_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 1068);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_DESC_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_DESC_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_desc_stats_reply_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_desc_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_desc_stats_reply_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_desc_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_desc_stats_request_create_OF_VERSION_1_0(void)
{
    of_desc_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_desc_stats_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_DESC_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_DESC_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_desc_stats_request_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_desc_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_desc_stats_request_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_desc_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_echo_reply_create_OF_VERSION_1_0(void)
{
    of_echo_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_echo_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ECHO_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_ECHO_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_echo_reply_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_echo_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_echo_reply_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_echo_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_echo_request_create_OF_VERSION_1_0(void)
{
    of_echo_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_echo_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ECHO_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_ECHO_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_echo_request_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_echo_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_echo_request_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_echo_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_features_reply_create_OF_VERSION_1_0(void)
{
    of_features_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_features_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FEATURES_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FEATURES_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_features_reply_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_features_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_features_reply_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_features_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_features_request_create_OF_VERSION_1_0(void)
{
    of_features_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_features_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FEATURES_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FEATURES_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_features_request_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_features_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_features_request_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_features_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_add_create_OF_VERSION_1_0(void)
{
    of_flow_add_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_add_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 72);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_ADD);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_ADD);

    /* Set up incrementing values for scalar members */
    value = of_flow_add_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_add_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_add_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_add_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_delete_create_OF_VERSION_1_0(void)
{
    of_flow_delete_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_delete_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 72);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_DELETE);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_DELETE);

    /* Set up incrementing values for scalar members */
    value = of_flow_delete_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_delete_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_delete_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_delete_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_delete_strict_create_OF_VERSION_1_0(void)
{
    of_flow_delete_strict_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_delete_strict_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 72);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_DELETE_STRICT);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_DELETE_STRICT);

    /* Set up incrementing values for scalar members */
    value = of_flow_delete_strict_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_delete_strict_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_delete_strict_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_delete_strict_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_mod_failed_error_msg_create_OF_VERSION_1_0(void)
{
    of_flow_mod_failed_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_mod_failed_error_msg_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_MOD_FAILED_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_MOD_FAILED_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_flow_mod_failed_error_msg_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_mod_failed_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_mod_failed_error_msg_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_mod_failed_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_modify_create_OF_VERSION_1_0(void)
{
    of_flow_modify_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_modify_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 72);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_MODIFY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_MODIFY);

    /* Set up incrementing values for scalar members */
    value = of_flow_modify_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_modify_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_modify_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_modify_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_modify_strict_create_OF_VERSION_1_0(void)
{
    of_flow_modify_strict_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_modify_strict_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 72);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_MODIFY_STRICT);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_MODIFY_STRICT);

    /* Set up incrementing values for scalar members */
    value = of_flow_modify_strict_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_modify_strict_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_modify_strict_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_modify_strict_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_removed_create_OF_VERSION_1_0(void)
{
    of_flow_removed_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_removed_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 88);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_REMOVED);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_REMOVED);

    /* Set up incrementing values for scalar members */
    value = of_flow_removed_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_removed_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_removed_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_removed_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_stats_reply_create_OF_VERSION_1_0(void)
{
    of_flow_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_stats_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_flow_stats_reply_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_stats_reply_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_stats_request_create_OF_VERSION_1_0(void)
{
    of_flow_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_stats_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_flow_stats_request_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_stats_request_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_get_config_reply_create_OF_VERSION_1_0(void)
{
    of_get_config_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_get_config_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GET_CONFIG_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GET_CONFIG_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_get_config_reply_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_get_config_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_get_config_reply_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_get_config_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_get_config_request_create_OF_VERSION_1_0(void)
{
    of_get_config_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_get_config_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GET_CONFIG_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GET_CONFIG_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_get_config_request_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_get_config_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_get_config_request_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_get_config_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_hello_create_OF_VERSION_1_0(void)
{
    of_hello_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_hello_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_HELLO);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_HELLO);

    /* Set up incrementing values for scalar members */
    value = of_hello_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_hello_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_hello_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_hello_delete(obj);

    return TEST_PASS;
}

static int
test_of_hello_failed_error_msg_create_OF_VERSION_1_0(void)
{
    of_hello_failed_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_hello_failed_error_msg_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_HELLO_FAILED_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_HELLO_FAILED_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_hello_failed_error_msg_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_hello_failed_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_hello_failed_error_msg_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_hello_failed_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_nicira_controller_role_reply_create_OF_VERSION_1_0(void)
{
    of_nicira_controller_role_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_nicira_controller_role_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_NICIRA_CONTROLLER_ROLE_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_NICIRA_CONTROLLER_ROLE_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_nicira_controller_role_reply_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_nicira_controller_role_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_nicira_controller_role_reply_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_nicira_controller_role_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_nicira_controller_role_request_create_OF_VERSION_1_0(void)
{
    of_nicira_controller_role_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_nicira_controller_role_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_NICIRA_CONTROLLER_ROLE_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_NICIRA_CONTROLLER_ROLE_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_nicira_controller_role_request_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_nicira_controller_role_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_nicira_controller_role_request_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_nicira_controller_role_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_packet_in_create_OF_VERSION_1_0(void)
{
    of_packet_in_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_packet_in_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 18);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PACKET_IN);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_PACKET_IN);

    /* Set up incrementing values for scalar members */
    value = of_packet_in_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_packet_in_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_packet_in_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_packet_in_delete(obj);

    return TEST_PASS;
}

static int
test_of_packet_out_create_OF_VERSION_1_0(void)
{
    of_packet_out_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_packet_out_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PACKET_OUT);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_PACKET_OUT);

    /* Set up incrementing values for scalar members */
    value = of_packet_out_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_packet_out_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_packet_out_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_packet_out_delete(obj);

    return TEST_PASS;
}

static int
test_of_port_mod_create_OF_VERSION_1_0(void)
{
    of_port_mod_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_port_mod_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_MOD);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_PORT_MOD);

    /* Set up incrementing values for scalar members */
    value = of_port_mod_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_port_mod_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_port_mod_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_port_mod_delete(obj);

    return TEST_PASS;
}

static int
test_of_port_mod_failed_error_msg_create_OF_VERSION_1_0(void)
{
    of_port_mod_failed_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_port_mod_failed_error_msg_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_MOD_FAILED_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_PORT_MOD_FAILED_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_port_mod_failed_error_msg_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_port_mod_failed_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_port_mod_failed_error_msg_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_port_mod_failed_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_port_stats_reply_create_OF_VERSION_1_0(void)
{
    of_port_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_port_stats_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_PORT_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_port_stats_reply_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_port_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_port_stats_reply_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_port_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_port_stats_request_create_OF_VERSION_1_0(void)
{
    of_port_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_port_stats_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_PORT_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_port_stats_request_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_port_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_port_stats_request_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_port_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_port_status_create_OF_VERSION_1_0(void)
{
    of_port_status_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_port_status_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 64);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_STATUS);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_PORT_STATUS);

    /* Set up incrementing values for scalar members */
    value = of_port_status_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_port_status_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_port_status_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_port_status_delete(obj);

    return TEST_PASS;
}

static int
test_of_queue_get_config_reply_create_OF_VERSION_1_0(void)
{
    of_queue_get_config_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_queue_get_config_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_GET_CONFIG_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_QUEUE_GET_CONFIG_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_queue_get_config_reply_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_queue_get_config_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_queue_get_config_reply_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_queue_get_config_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_queue_get_config_request_create_OF_VERSION_1_0(void)
{
    of_queue_get_config_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_queue_get_config_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_GET_CONFIG_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_QUEUE_GET_CONFIG_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_queue_get_config_request_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_queue_get_config_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_queue_get_config_request_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_queue_get_config_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_queue_op_failed_error_msg_create_OF_VERSION_1_0(void)
{
    of_queue_op_failed_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_queue_op_failed_error_msg_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_OP_FAILED_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_QUEUE_OP_FAILED_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_queue_op_failed_error_msg_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_queue_op_failed_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_queue_op_failed_error_msg_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_queue_op_failed_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_queue_stats_reply_create_OF_VERSION_1_0(void)
{
    of_queue_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_queue_stats_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_QUEUE_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_queue_stats_reply_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_queue_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_queue_stats_reply_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_queue_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_queue_stats_request_create_OF_VERSION_1_0(void)
{
    of_queue_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_queue_stats_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_QUEUE_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_queue_stats_request_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_queue_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_queue_stats_request_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_queue_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_set_config_create_OF_VERSION_1_0(void)
{
    of_set_config_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_set_config_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_SET_CONFIG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_SET_CONFIG);

    /* Set up incrementing values for scalar members */
    value = of_set_config_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_set_config_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_set_config_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_set_config_delete(obj);

    return TEST_PASS;
}

static int
test_of_table_mod_create_OF_VERSION_1_0(void)
{
    of_table_mod_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_table_mod_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_MOD);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_TABLE_MOD);

    /* Set up incrementing values for scalar members */
    value = of_table_mod_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_table_mod_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_table_mod_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_table_mod_delete(obj);

    return TEST_PASS;
}

static int
test_of_table_stats_reply_create_OF_VERSION_1_0(void)
{
    of_table_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_table_stats_reply_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_TABLE_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_table_stats_reply_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_table_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_table_stats_reply_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_table_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_table_stats_request_create_OF_VERSION_1_0(void)
{
    of_table_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_table_stats_request_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_0);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_TABLE_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_table_stats_request_OF_VERSION_1_0_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_table_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_table_stats_request_OF_VERSION_1_0_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_table_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_aggregate_stats_reply_create_OF_VERSION_1_1(void)
{
    of_aggregate_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_aggregate_stats_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 40);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_AGGREGATE_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_aggregate_stats_reply_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_aggregate_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_aggregate_stats_reply_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_aggregate_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_aggregate_stats_request_create_OF_VERSION_1_1(void)
{
    of_aggregate_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_aggregate_stats_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 136);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_AGGREGATE_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_aggregate_stats_request_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_aggregate_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_aggregate_stats_request_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_aggregate_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bad_action_error_msg_create_OF_VERSION_1_1(void)
{
    of_bad_action_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bad_action_error_msg_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BAD_ACTION_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BAD_ACTION_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_bad_action_error_msg_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bad_action_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bad_action_error_msg_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bad_action_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_bad_instruction_error_msg_create_OF_VERSION_1_1(void)
{
    of_bad_instruction_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bad_instruction_error_msg_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BAD_INSTRUCTION_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BAD_INSTRUCTION_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_bad_instruction_error_msg_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bad_instruction_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bad_instruction_error_msg_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bad_instruction_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_bad_match_error_msg_create_OF_VERSION_1_1(void)
{
    of_bad_match_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bad_match_error_msg_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BAD_MATCH_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BAD_MATCH_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_bad_match_error_msg_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bad_match_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bad_match_error_msg_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bad_match_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_bad_request_error_msg_create_OF_VERSION_1_1(void)
{
    of_bad_request_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bad_request_error_msg_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BAD_REQUEST_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BAD_REQUEST_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_bad_request_error_msg_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bad_request_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bad_request_error_msg_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bad_request_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_barrier_reply_create_OF_VERSION_1_1(void)
{
    of_barrier_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_barrier_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BARRIER_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BARRIER_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_barrier_reply_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_barrier_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_barrier_reply_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_barrier_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_barrier_request_create_OF_VERSION_1_1(void)
{
    of_barrier_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_barrier_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BARRIER_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BARRIER_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_barrier_request_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_barrier_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_barrier_request_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_barrier_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_bw_clear_data_reply_create_OF_VERSION_1_1(void)
{
    of_bsn_bw_clear_data_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_bw_clear_data_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_CLEAR_DATA_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_BW_CLEAR_DATA_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_bw_clear_data_reply_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_bw_clear_data_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_bw_clear_data_reply_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_bw_clear_data_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_bw_clear_data_request_create_OF_VERSION_1_1(void)
{
    of_bsn_bw_clear_data_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_bw_clear_data_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_CLEAR_DATA_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_BW_CLEAR_DATA_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_bw_clear_data_request_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_bw_clear_data_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_bw_clear_data_request_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_bw_clear_data_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_bw_enable_get_reply_create_OF_VERSION_1_1(void)
{
    of_bsn_bw_enable_get_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_bw_enable_get_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_ENABLE_GET_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_BW_ENABLE_GET_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_bw_enable_get_reply_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_bw_enable_get_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_bw_enable_get_reply_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_bw_enable_get_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_bw_enable_get_request_create_OF_VERSION_1_1(void)
{
    of_bsn_bw_enable_get_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_bw_enable_get_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_ENABLE_GET_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_BW_ENABLE_GET_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_bw_enable_get_request_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_bw_enable_get_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_bw_enable_get_request_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_bw_enable_get_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_bw_enable_set_reply_create_OF_VERSION_1_1(void)
{
    of_bsn_bw_enable_set_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_bw_enable_set_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_ENABLE_SET_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_BW_ENABLE_SET_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_bw_enable_set_reply_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_bw_enable_set_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_bw_enable_set_reply_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_bw_enable_set_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_bw_enable_set_request_create_OF_VERSION_1_1(void)
{
    of_bsn_bw_enable_set_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_bw_enable_set_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_ENABLE_SET_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_BW_ENABLE_SET_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_bw_enable_set_request_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_bw_enable_set_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_bw_enable_set_request_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_bw_enable_set_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_get_interfaces_reply_create_OF_VERSION_1_1(void)
{
    of_bsn_get_interfaces_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_get_interfaces_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_INTERFACES_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GET_INTERFACES_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_get_interfaces_reply_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_get_interfaces_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_get_interfaces_reply_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_get_interfaces_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_get_interfaces_request_create_OF_VERSION_1_1(void)
{
    of_bsn_get_interfaces_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_get_interfaces_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_INTERFACES_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GET_INTERFACES_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_get_interfaces_request_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_get_interfaces_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_get_interfaces_request_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_get_interfaces_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_get_mirroring_reply_create_OF_VERSION_1_1(void)
{
    of_bsn_get_mirroring_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_get_mirroring_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_MIRRORING_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GET_MIRRORING_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_get_mirroring_reply_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_get_mirroring_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_get_mirroring_reply_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_get_mirroring_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_get_mirroring_request_create_OF_VERSION_1_1(void)
{
    of_bsn_get_mirroring_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_get_mirroring_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_MIRRORING_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GET_MIRRORING_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_get_mirroring_request_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_get_mirroring_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_get_mirroring_request_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_get_mirroring_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_pdu_rx_reply_create_OF_VERSION_1_1(void)
{
    of_bsn_pdu_rx_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_pdu_rx_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 25);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_RX_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_PDU_RX_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_pdu_rx_reply_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_pdu_rx_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_pdu_rx_reply_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_pdu_rx_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_pdu_rx_request_create_OF_VERSION_1_1(void)
{
    of_bsn_pdu_rx_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_pdu_rx_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 28);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_RX_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_PDU_RX_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_pdu_rx_request_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_pdu_rx_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_pdu_rx_request_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_pdu_rx_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_pdu_rx_timeout_create_OF_VERSION_1_1(void)
{
    of_bsn_pdu_rx_timeout_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_pdu_rx_timeout_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 21);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_RX_TIMEOUT);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_PDU_RX_TIMEOUT);

    /* Set up incrementing values for scalar members */
    value = of_bsn_pdu_rx_timeout_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_pdu_rx_timeout_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_pdu_rx_timeout_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_pdu_rx_timeout_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_pdu_tx_reply_create_OF_VERSION_1_1(void)
{
    of_bsn_pdu_tx_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_pdu_tx_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 25);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_TX_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_PDU_TX_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_pdu_tx_reply_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_pdu_tx_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_pdu_tx_reply_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_pdu_tx_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_pdu_tx_request_create_OF_VERSION_1_1(void)
{
    of_bsn_pdu_tx_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_pdu_tx_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 28);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_TX_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_PDU_TX_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_pdu_tx_request_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_pdu_tx_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_pdu_tx_request_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_pdu_tx_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_set_mirroring_create_OF_VERSION_1_1(void)
{
    of_bsn_set_mirroring_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_set_mirroring_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_MIRRORING);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_SET_MIRRORING);

    /* Set up incrementing values for scalar members */
    value = of_bsn_set_mirroring_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_set_mirroring_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_set_mirroring_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_set_mirroring_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_set_pktin_suppression_reply_create_OF_VERSION_1_1(void)
{
    of_bsn_set_pktin_suppression_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_set_pktin_suppression_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_PKTIN_SUPPRESSION_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_SET_PKTIN_SUPPRESSION_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_set_pktin_suppression_reply_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_set_pktin_suppression_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_set_pktin_suppression_reply_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_set_pktin_suppression_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_set_pktin_suppression_request_create_OF_VERSION_1_1(void)
{
    of_bsn_set_pktin_suppression_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_set_pktin_suppression_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_PKTIN_SUPPRESSION_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_SET_PKTIN_SUPPRESSION_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_set_pktin_suppression_request_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_set_pktin_suppression_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_set_pktin_suppression_request_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_set_pktin_suppression_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_virtual_port_create_reply_create_OF_VERSION_1_1(void)
{
    of_bsn_virtual_port_create_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_virtual_port_create_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VIRTUAL_PORT_CREATE_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_VIRTUAL_PORT_CREATE_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_virtual_port_create_reply_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_virtual_port_create_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_virtual_port_create_reply_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_virtual_port_create_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_virtual_port_create_request_create_OF_VERSION_1_1(void)
{
    of_bsn_virtual_port_create_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_virtual_port_create_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VIRTUAL_PORT_CREATE_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_VIRTUAL_PORT_CREATE_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_virtual_port_create_request_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_virtual_port_create_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_virtual_port_create_request_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_virtual_port_create_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_virtual_port_remove_reply_create_OF_VERSION_1_1(void)
{
    of_bsn_virtual_port_remove_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_virtual_port_remove_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VIRTUAL_PORT_REMOVE_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_VIRTUAL_PORT_REMOVE_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_virtual_port_remove_reply_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_virtual_port_remove_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_virtual_port_remove_reply_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_virtual_port_remove_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_virtual_port_remove_request_create_OF_VERSION_1_1(void)
{
    of_bsn_virtual_port_remove_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_virtual_port_remove_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VIRTUAL_PORT_REMOVE_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_VIRTUAL_PORT_REMOVE_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_virtual_port_remove_request_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_virtual_port_remove_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_virtual_port_remove_request_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_virtual_port_remove_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_desc_stats_reply_create_OF_VERSION_1_1(void)
{
    of_desc_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_desc_stats_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 1072);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_DESC_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_DESC_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_desc_stats_reply_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_desc_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_desc_stats_reply_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_desc_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_desc_stats_request_create_OF_VERSION_1_1(void)
{
    of_desc_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_desc_stats_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_DESC_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_DESC_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_desc_stats_request_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_desc_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_desc_stats_request_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_desc_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_echo_reply_create_OF_VERSION_1_1(void)
{
    of_echo_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_echo_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ECHO_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_ECHO_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_echo_reply_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_echo_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_echo_reply_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_echo_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_echo_request_create_OF_VERSION_1_1(void)
{
    of_echo_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_echo_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ECHO_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_ECHO_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_echo_request_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_echo_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_echo_request_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_echo_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_features_reply_create_OF_VERSION_1_1(void)
{
    of_features_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_features_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FEATURES_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FEATURES_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_features_reply_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_features_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_features_reply_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_features_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_features_request_create_OF_VERSION_1_1(void)
{
    of_features_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_features_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FEATURES_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FEATURES_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_features_request_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_features_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_features_request_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_features_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_add_create_OF_VERSION_1_1(void)
{
    of_flow_add_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_add_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 136);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_ADD);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_ADD);

    /* Set up incrementing values for scalar members */
    value = of_flow_add_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_add_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_add_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_add_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_delete_create_OF_VERSION_1_1(void)
{
    of_flow_delete_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_delete_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 136);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_DELETE);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_DELETE);

    /* Set up incrementing values for scalar members */
    value = of_flow_delete_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_delete_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_delete_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_delete_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_delete_strict_create_OF_VERSION_1_1(void)
{
    of_flow_delete_strict_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_delete_strict_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 136);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_DELETE_STRICT);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_DELETE_STRICT);

    /* Set up incrementing values for scalar members */
    value = of_flow_delete_strict_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_delete_strict_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_delete_strict_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_delete_strict_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_mod_failed_error_msg_create_OF_VERSION_1_1(void)
{
    of_flow_mod_failed_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_mod_failed_error_msg_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_MOD_FAILED_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_MOD_FAILED_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_flow_mod_failed_error_msg_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_mod_failed_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_mod_failed_error_msg_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_mod_failed_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_modify_create_OF_VERSION_1_1(void)
{
    of_flow_modify_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_modify_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 136);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_MODIFY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_MODIFY);

    /* Set up incrementing values for scalar members */
    value = of_flow_modify_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_modify_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_modify_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_modify_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_modify_strict_create_OF_VERSION_1_1(void)
{
    of_flow_modify_strict_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_modify_strict_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 136);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_MODIFY_STRICT);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_MODIFY_STRICT);

    /* Set up incrementing values for scalar members */
    value = of_flow_modify_strict_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_modify_strict_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_modify_strict_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_modify_strict_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_removed_create_OF_VERSION_1_1(void)
{
    of_flow_removed_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_removed_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 136);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_REMOVED);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_REMOVED);

    /* Set up incrementing values for scalar members */
    value = of_flow_removed_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_removed_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_removed_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_removed_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_stats_reply_create_OF_VERSION_1_1(void)
{
    of_flow_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_stats_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_flow_stats_reply_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_stats_reply_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_stats_request_create_OF_VERSION_1_1(void)
{
    of_flow_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_stats_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 136);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_flow_stats_request_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_stats_request_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_get_config_reply_create_OF_VERSION_1_1(void)
{
    of_get_config_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_get_config_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GET_CONFIG_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GET_CONFIG_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_get_config_reply_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_get_config_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_get_config_reply_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_get_config_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_get_config_request_create_OF_VERSION_1_1(void)
{
    of_get_config_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_get_config_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GET_CONFIG_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GET_CONFIG_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_get_config_request_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_get_config_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_get_config_request_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_get_config_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_group_add_create_OF_VERSION_1_1(void)
{
    of_group_add_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_group_add_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_ADD);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GROUP_ADD);

    /* Set up incrementing values for scalar members */
    value = of_group_add_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_group_add_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_group_add_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_group_add_delete(obj);

    return TEST_PASS;
}

static int
test_of_group_delete_create_OF_VERSION_1_1(void)
{
    of_group_delete_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_group_delete_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_DELETE);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GROUP_DELETE);

    /* Set up incrementing values for scalar members */
    value = of_group_delete_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_group_delete_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_group_delete_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_group_delete_delete(obj);

    return TEST_PASS;
}

static int
test_of_group_desc_stats_reply_create_OF_VERSION_1_1(void)
{
    of_group_desc_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_group_desc_stats_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_DESC_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GROUP_DESC_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_group_desc_stats_reply_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_group_desc_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_group_desc_stats_reply_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_group_desc_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_group_desc_stats_request_create_OF_VERSION_1_1(void)
{
    of_group_desc_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_group_desc_stats_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_DESC_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GROUP_DESC_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_group_desc_stats_request_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_group_desc_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_group_desc_stats_request_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_group_desc_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_group_mod_failed_error_msg_create_OF_VERSION_1_1(void)
{
    of_group_mod_failed_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_group_mod_failed_error_msg_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_MOD_FAILED_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GROUP_MOD_FAILED_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_group_mod_failed_error_msg_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_group_mod_failed_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_group_mod_failed_error_msg_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_group_mod_failed_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_group_modify_create_OF_VERSION_1_1(void)
{
    of_group_modify_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_group_modify_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_MODIFY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GROUP_MODIFY);

    /* Set up incrementing values for scalar members */
    value = of_group_modify_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_group_modify_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_group_modify_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_group_modify_delete(obj);

    return TEST_PASS;
}

static int
test_of_group_stats_reply_create_OF_VERSION_1_1(void)
{
    of_group_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_group_stats_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GROUP_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_group_stats_reply_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_group_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_group_stats_reply_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_group_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_group_stats_request_create_OF_VERSION_1_1(void)
{
    of_group_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_group_stats_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GROUP_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_group_stats_request_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_group_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_group_stats_request_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_group_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_hello_create_OF_VERSION_1_1(void)
{
    of_hello_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_hello_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_HELLO);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_HELLO);

    /* Set up incrementing values for scalar members */
    value = of_hello_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_hello_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_hello_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_hello_delete(obj);

    return TEST_PASS;
}

static int
test_of_hello_failed_error_msg_create_OF_VERSION_1_1(void)
{
    of_hello_failed_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_hello_failed_error_msg_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_HELLO_FAILED_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_HELLO_FAILED_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_hello_failed_error_msg_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_hello_failed_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_hello_failed_error_msg_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_hello_failed_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_packet_in_create_OF_VERSION_1_1(void)
{
    of_packet_in_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_packet_in_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PACKET_IN);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_PACKET_IN);

    /* Set up incrementing values for scalar members */
    value = of_packet_in_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_packet_in_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_packet_in_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_packet_in_delete(obj);

    return TEST_PASS;
}

static int
test_of_packet_out_create_OF_VERSION_1_1(void)
{
    of_packet_out_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_packet_out_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PACKET_OUT);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_PACKET_OUT);

    /* Set up incrementing values for scalar members */
    value = of_packet_out_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_packet_out_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_packet_out_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_packet_out_delete(obj);

    return TEST_PASS;
}

static int
test_of_port_mod_create_OF_VERSION_1_1(void)
{
    of_port_mod_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_port_mod_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 40);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_MOD);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_PORT_MOD);

    /* Set up incrementing values for scalar members */
    value = of_port_mod_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_port_mod_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_port_mod_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_port_mod_delete(obj);

    return TEST_PASS;
}

static int
test_of_port_mod_failed_error_msg_create_OF_VERSION_1_1(void)
{
    of_port_mod_failed_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_port_mod_failed_error_msg_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_MOD_FAILED_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_PORT_MOD_FAILED_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_port_mod_failed_error_msg_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_port_mod_failed_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_port_mod_failed_error_msg_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_port_mod_failed_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_port_stats_reply_create_OF_VERSION_1_1(void)
{
    of_port_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_port_stats_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_PORT_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_port_stats_reply_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_port_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_port_stats_reply_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_port_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_port_stats_request_create_OF_VERSION_1_1(void)
{
    of_port_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_port_stats_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_PORT_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_port_stats_request_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_port_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_port_stats_request_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_port_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_port_status_create_OF_VERSION_1_1(void)
{
    of_port_status_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_port_status_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 80);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_STATUS);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_PORT_STATUS);

    /* Set up incrementing values for scalar members */
    value = of_port_status_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_port_status_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_port_status_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_port_status_delete(obj);

    return TEST_PASS;
}

static int
test_of_queue_get_config_reply_create_OF_VERSION_1_1(void)
{
    of_queue_get_config_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_queue_get_config_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_GET_CONFIG_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_QUEUE_GET_CONFIG_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_queue_get_config_reply_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_queue_get_config_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_queue_get_config_reply_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_queue_get_config_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_queue_get_config_request_create_OF_VERSION_1_1(void)
{
    of_queue_get_config_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_queue_get_config_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_GET_CONFIG_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_QUEUE_GET_CONFIG_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_queue_get_config_request_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_queue_get_config_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_queue_get_config_request_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_queue_get_config_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_queue_op_failed_error_msg_create_OF_VERSION_1_1(void)
{
    of_queue_op_failed_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_queue_op_failed_error_msg_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_OP_FAILED_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_QUEUE_OP_FAILED_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_queue_op_failed_error_msg_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_queue_op_failed_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_queue_op_failed_error_msg_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_queue_op_failed_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_queue_stats_reply_create_OF_VERSION_1_1(void)
{
    of_queue_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_queue_stats_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_QUEUE_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_queue_stats_reply_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_queue_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_queue_stats_reply_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_queue_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_queue_stats_request_create_OF_VERSION_1_1(void)
{
    of_queue_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_queue_stats_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_QUEUE_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_queue_stats_request_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_queue_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_queue_stats_request_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_queue_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_set_config_create_OF_VERSION_1_1(void)
{
    of_set_config_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_set_config_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_SET_CONFIG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_SET_CONFIG);

    /* Set up incrementing values for scalar members */
    value = of_set_config_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_set_config_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_set_config_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_set_config_delete(obj);

    return TEST_PASS;
}

static int
test_of_switch_config_failed_error_msg_create_OF_VERSION_1_1(void)
{
    of_switch_config_failed_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_switch_config_failed_error_msg_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_SWITCH_CONFIG_FAILED_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_SWITCH_CONFIG_FAILED_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_switch_config_failed_error_msg_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_switch_config_failed_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_switch_config_failed_error_msg_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_switch_config_failed_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_table_mod_create_OF_VERSION_1_1(void)
{
    of_table_mod_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_table_mod_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_MOD);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_TABLE_MOD);

    /* Set up incrementing values for scalar members */
    value = of_table_mod_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_table_mod_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_table_mod_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_table_mod_delete(obj);

    return TEST_PASS;
}

static int
test_of_table_mod_failed_error_msg_create_OF_VERSION_1_1(void)
{
    of_table_mod_failed_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_table_mod_failed_error_msg_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_MOD_FAILED_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_TABLE_MOD_FAILED_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_table_mod_failed_error_msg_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_table_mod_failed_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_table_mod_failed_error_msg_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_table_mod_failed_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_table_stats_reply_create_OF_VERSION_1_1(void)
{
    of_table_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_table_stats_reply_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_TABLE_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_table_stats_reply_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_table_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_table_stats_reply_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_table_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_table_stats_request_create_OF_VERSION_1_1(void)
{
    of_table_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_table_stats_request_new(OF_VERSION_1_1);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_1);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_TABLE_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_table_stats_request_OF_VERSION_1_1_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_table_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_table_stats_request_OF_VERSION_1_1_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_table_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_aggregate_stats_reply_create_OF_VERSION_1_2(void)
{
    of_aggregate_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_aggregate_stats_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 40);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_AGGREGATE_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_aggregate_stats_reply_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_aggregate_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_aggregate_stats_reply_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_aggregate_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_aggregate_stats_request_create_OF_VERSION_1_2(void)
{
    of_aggregate_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_aggregate_stats_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_AGGREGATE_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_aggregate_stats_request_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_aggregate_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_aggregate_stats_request_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_aggregate_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bad_action_error_msg_create_OF_VERSION_1_2(void)
{
    of_bad_action_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bad_action_error_msg_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BAD_ACTION_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BAD_ACTION_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_bad_action_error_msg_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bad_action_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bad_action_error_msg_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bad_action_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_bad_instruction_error_msg_create_OF_VERSION_1_2(void)
{
    of_bad_instruction_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bad_instruction_error_msg_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BAD_INSTRUCTION_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BAD_INSTRUCTION_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_bad_instruction_error_msg_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bad_instruction_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bad_instruction_error_msg_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bad_instruction_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_bad_match_error_msg_create_OF_VERSION_1_2(void)
{
    of_bad_match_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bad_match_error_msg_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BAD_MATCH_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BAD_MATCH_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_bad_match_error_msg_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bad_match_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bad_match_error_msg_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bad_match_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_bad_request_error_msg_create_OF_VERSION_1_2(void)
{
    of_bad_request_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bad_request_error_msg_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BAD_REQUEST_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BAD_REQUEST_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_bad_request_error_msg_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bad_request_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bad_request_error_msg_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bad_request_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_barrier_reply_create_OF_VERSION_1_2(void)
{
    of_barrier_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_barrier_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BARRIER_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BARRIER_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_barrier_reply_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_barrier_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_barrier_reply_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_barrier_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_barrier_request_create_OF_VERSION_1_2(void)
{
    of_barrier_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_barrier_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BARRIER_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BARRIER_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_barrier_request_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_barrier_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_barrier_request_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_barrier_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_bw_clear_data_reply_create_OF_VERSION_1_2(void)
{
    of_bsn_bw_clear_data_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_bw_clear_data_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_CLEAR_DATA_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_BW_CLEAR_DATA_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_bw_clear_data_reply_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_bw_clear_data_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_bw_clear_data_reply_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_bw_clear_data_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_bw_clear_data_request_create_OF_VERSION_1_2(void)
{
    of_bsn_bw_clear_data_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_bw_clear_data_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_CLEAR_DATA_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_BW_CLEAR_DATA_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_bw_clear_data_request_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_bw_clear_data_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_bw_clear_data_request_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_bw_clear_data_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_bw_enable_get_reply_create_OF_VERSION_1_2(void)
{
    of_bsn_bw_enable_get_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_bw_enable_get_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_ENABLE_GET_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_BW_ENABLE_GET_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_bw_enable_get_reply_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_bw_enable_get_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_bw_enable_get_reply_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_bw_enable_get_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_bw_enable_get_request_create_OF_VERSION_1_2(void)
{
    of_bsn_bw_enable_get_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_bw_enable_get_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_ENABLE_GET_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_BW_ENABLE_GET_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_bw_enable_get_request_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_bw_enable_get_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_bw_enable_get_request_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_bw_enable_get_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_bw_enable_set_reply_create_OF_VERSION_1_2(void)
{
    of_bsn_bw_enable_set_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_bw_enable_set_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_ENABLE_SET_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_BW_ENABLE_SET_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_bw_enable_set_reply_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_bw_enable_set_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_bw_enable_set_reply_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_bw_enable_set_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_bw_enable_set_request_create_OF_VERSION_1_2(void)
{
    of_bsn_bw_enable_set_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_bw_enable_set_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_ENABLE_SET_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_BW_ENABLE_SET_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_bw_enable_set_request_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_bw_enable_set_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_bw_enable_set_request_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_bw_enable_set_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_get_interfaces_reply_create_OF_VERSION_1_2(void)
{
    of_bsn_get_interfaces_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_get_interfaces_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_INTERFACES_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GET_INTERFACES_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_get_interfaces_reply_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_get_interfaces_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_get_interfaces_reply_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_get_interfaces_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_get_interfaces_request_create_OF_VERSION_1_2(void)
{
    of_bsn_get_interfaces_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_get_interfaces_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_INTERFACES_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GET_INTERFACES_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_get_interfaces_request_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_get_interfaces_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_get_interfaces_request_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_get_interfaces_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_get_mirroring_reply_create_OF_VERSION_1_2(void)
{
    of_bsn_get_mirroring_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_get_mirroring_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_MIRRORING_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GET_MIRRORING_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_get_mirroring_reply_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_get_mirroring_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_get_mirroring_reply_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_get_mirroring_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_get_mirroring_request_create_OF_VERSION_1_2(void)
{
    of_bsn_get_mirroring_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_get_mirroring_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_MIRRORING_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GET_MIRRORING_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_get_mirroring_request_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_get_mirroring_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_get_mirroring_request_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_get_mirroring_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_pdu_rx_reply_create_OF_VERSION_1_2(void)
{
    of_bsn_pdu_rx_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_pdu_rx_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 25);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_RX_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_PDU_RX_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_pdu_rx_reply_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_pdu_rx_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_pdu_rx_reply_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_pdu_rx_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_pdu_rx_request_create_OF_VERSION_1_2(void)
{
    of_bsn_pdu_rx_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_pdu_rx_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 28);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_RX_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_PDU_RX_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_pdu_rx_request_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_pdu_rx_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_pdu_rx_request_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_pdu_rx_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_pdu_rx_timeout_create_OF_VERSION_1_2(void)
{
    of_bsn_pdu_rx_timeout_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_pdu_rx_timeout_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 21);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_RX_TIMEOUT);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_PDU_RX_TIMEOUT);

    /* Set up incrementing values for scalar members */
    value = of_bsn_pdu_rx_timeout_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_pdu_rx_timeout_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_pdu_rx_timeout_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_pdu_rx_timeout_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_pdu_tx_reply_create_OF_VERSION_1_2(void)
{
    of_bsn_pdu_tx_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_pdu_tx_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 25);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_TX_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_PDU_TX_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_pdu_tx_reply_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_pdu_tx_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_pdu_tx_reply_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_pdu_tx_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_pdu_tx_request_create_OF_VERSION_1_2(void)
{
    of_bsn_pdu_tx_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_pdu_tx_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 28);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_TX_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_PDU_TX_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_pdu_tx_request_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_pdu_tx_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_pdu_tx_request_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_pdu_tx_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_set_mirroring_create_OF_VERSION_1_2(void)
{
    of_bsn_set_mirroring_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_set_mirroring_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_MIRRORING);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_SET_MIRRORING);

    /* Set up incrementing values for scalar members */
    value = of_bsn_set_mirroring_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_set_mirroring_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_set_mirroring_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_set_mirroring_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_set_pktin_suppression_reply_create_OF_VERSION_1_2(void)
{
    of_bsn_set_pktin_suppression_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_set_pktin_suppression_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_PKTIN_SUPPRESSION_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_SET_PKTIN_SUPPRESSION_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_set_pktin_suppression_reply_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_set_pktin_suppression_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_set_pktin_suppression_reply_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_set_pktin_suppression_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_set_pktin_suppression_request_create_OF_VERSION_1_2(void)
{
    of_bsn_set_pktin_suppression_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_set_pktin_suppression_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_PKTIN_SUPPRESSION_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_SET_PKTIN_SUPPRESSION_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_set_pktin_suppression_request_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_set_pktin_suppression_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_set_pktin_suppression_request_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_set_pktin_suppression_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_virtual_port_create_reply_create_OF_VERSION_1_2(void)
{
    of_bsn_virtual_port_create_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_virtual_port_create_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VIRTUAL_PORT_CREATE_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_VIRTUAL_PORT_CREATE_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_virtual_port_create_reply_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_virtual_port_create_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_virtual_port_create_reply_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_virtual_port_create_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_virtual_port_create_request_create_OF_VERSION_1_2(void)
{
    of_bsn_virtual_port_create_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_virtual_port_create_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VIRTUAL_PORT_CREATE_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_VIRTUAL_PORT_CREATE_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_virtual_port_create_request_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_virtual_port_create_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_virtual_port_create_request_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_virtual_port_create_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_virtual_port_remove_reply_create_OF_VERSION_1_2(void)
{
    of_bsn_virtual_port_remove_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_virtual_port_remove_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VIRTUAL_PORT_REMOVE_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_VIRTUAL_PORT_REMOVE_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_virtual_port_remove_reply_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_virtual_port_remove_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_virtual_port_remove_reply_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_virtual_port_remove_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_virtual_port_remove_request_create_OF_VERSION_1_2(void)
{
    of_bsn_virtual_port_remove_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_virtual_port_remove_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VIRTUAL_PORT_REMOVE_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_VIRTUAL_PORT_REMOVE_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_virtual_port_remove_request_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_virtual_port_remove_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_virtual_port_remove_request_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_virtual_port_remove_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_desc_stats_reply_create_OF_VERSION_1_2(void)
{
    of_desc_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_desc_stats_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 1072);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_DESC_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_DESC_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_desc_stats_reply_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_desc_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_desc_stats_reply_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_desc_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_desc_stats_request_create_OF_VERSION_1_2(void)
{
    of_desc_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_desc_stats_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_DESC_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_DESC_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_desc_stats_request_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_desc_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_desc_stats_request_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_desc_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_echo_reply_create_OF_VERSION_1_2(void)
{
    of_echo_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_echo_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ECHO_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_ECHO_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_echo_reply_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_echo_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_echo_reply_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_echo_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_echo_request_create_OF_VERSION_1_2(void)
{
    of_echo_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_echo_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ECHO_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_ECHO_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_echo_request_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_echo_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_echo_request_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_echo_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_features_reply_create_OF_VERSION_1_2(void)
{
    of_features_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_features_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FEATURES_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FEATURES_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_features_reply_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_features_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_features_reply_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_features_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_features_request_create_OF_VERSION_1_2(void)
{
    of_features_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_features_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FEATURES_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FEATURES_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_features_request_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_features_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_features_request_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_features_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_add_create_OF_VERSION_1_2(void)
{
    of_flow_add_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_add_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_ADD);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_ADD);

    /* Set up incrementing values for scalar members */
    value = of_flow_add_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_add_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_add_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_add_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_delete_create_OF_VERSION_1_2(void)
{
    of_flow_delete_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_delete_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_DELETE);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_DELETE);

    /* Set up incrementing values for scalar members */
    value = of_flow_delete_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_delete_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_delete_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_delete_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_delete_strict_create_OF_VERSION_1_2(void)
{
    of_flow_delete_strict_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_delete_strict_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_DELETE_STRICT);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_DELETE_STRICT);

    /* Set up incrementing values for scalar members */
    value = of_flow_delete_strict_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_delete_strict_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_delete_strict_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_delete_strict_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_mod_failed_error_msg_create_OF_VERSION_1_2(void)
{
    of_flow_mod_failed_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_mod_failed_error_msg_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_MOD_FAILED_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_MOD_FAILED_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_flow_mod_failed_error_msg_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_mod_failed_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_mod_failed_error_msg_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_mod_failed_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_modify_create_OF_VERSION_1_2(void)
{
    of_flow_modify_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_modify_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_MODIFY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_MODIFY);

    /* Set up incrementing values for scalar members */
    value = of_flow_modify_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_modify_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_modify_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_modify_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_modify_strict_create_OF_VERSION_1_2(void)
{
    of_flow_modify_strict_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_modify_strict_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_MODIFY_STRICT);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_MODIFY_STRICT);

    /* Set up incrementing values for scalar members */
    value = of_flow_modify_strict_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_modify_strict_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_modify_strict_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_modify_strict_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_removed_create_OF_VERSION_1_2(void)
{
    of_flow_removed_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_removed_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_REMOVED);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_REMOVED);

    /* Set up incrementing values for scalar members */
    value = of_flow_removed_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_removed_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_removed_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_removed_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_stats_reply_create_OF_VERSION_1_2(void)
{
    of_flow_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_stats_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_flow_stats_reply_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_stats_reply_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_stats_request_create_OF_VERSION_1_2(void)
{
    of_flow_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_stats_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_flow_stats_request_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_stats_request_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_get_config_reply_create_OF_VERSION_1_2(void)
{
    of_get_config_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_get_config_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GET_CONFIG_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GET_CONFIG_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_get_config_reply_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_get_config_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_get_config_reply_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_get_config_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_get_config_request_create_OF_VERSION_1_2(void)
{
    of_get_config_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_get_config_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GET_CONFIG_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GET_CONFIG_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_get_config_request_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_get_config_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_get_config_request_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_get_config_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_group_add_create_OF_VERSION_1_2(void)
{
    of_group_add_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_group_add_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_ADD);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GROUP_ADD);

    /* Set up incrementing values for scalar members */
    value = of_group_add_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_group_add_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_group_add_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_group_add_delete(obj);

    return TEST_PASS;
}

static int
test_of_group_delete_create_OF_VERSION_1_2(void)
{
    of_group_delete_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_group_delete_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_DELETE);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GROUP_DELETE);

    /* Set up incrementing values for scalar members */
    value = of_group_delete_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_group_delete_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_group_delete_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_group_delete_delete(obj);

    return TEST_PASS;
}

static int
test_of_group_desc_stats_reply_create_OF_VERSION_1_2(void)
{
    of_group_desc_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_group_desc_stats_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_DESC_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GROUP_DESC_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_group_desc_stats_reply_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_group_desc_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_group_desc_stats_reply_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_group_desc_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_group_desc_stats_request_create_OF_VERSION_1_2(void)
{
    of_group_desc_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_group_desc_stats_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_DESC_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GROUP_DESC_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_group_desc_stats_request_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_group_desc_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_group_desc_stats_request_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_group_desc_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_group_features_stats_reply_create_OF_VERSION_1_2(void)
{
    of_group_features_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_group_features_stats_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GROUP_FEATURES_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_group_features_stats_reply_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_group_features_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_group_features_stats_reply_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_group_features_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_group_features_stats_request_create_OF_VERSION_1_2(void)
{
    of_group_features_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_group_features_stats_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GROUP_FEATURES_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_group_features_stats_request_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_group_features_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_group_features_stats_request_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_group_features_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_group_mod_failed_error_msg_create_OF_VERSION_1_2(void)
{
    of_group_mod_failed_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_group_mod_failed_error_msg_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_MOD_FAILED_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GROUP_MOD_FAILED_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_group_mod_failed_error_msg_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_group_mod_failed_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_group_mod_failed_error_msg_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_group_mod_failed_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_group_modify_create_OF_VERSION_1_2(void)
{
    of_group_modify_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_group_modify_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_MODIFY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GROUP_MODIFY);

    /* Set up incrementing values for scalar members */
    value = of_group_modify_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_group_modify_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_group_modify_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_group_modify_delete(obj);

    return TEST_PASS;
}

static int
test_of_group_stats_reply_create_OF_VERSION_1_2(void)
{
    of_group_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_group_stats_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GROUP_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_group_stats_reply_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_group_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_group_stats_reply_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_group_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_group_stats_request_create_OF_VERSION_1_2(void)
{
    of_group_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_group_stats_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GROUP_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_group_stats_request_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_group_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_group_stats_request_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_group_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_hello_create_OF_VERSION_1_2(void)
{
    of_hello_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_hello_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_HELLO);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_HELLO);

    /* Set up incrementing values for scalar members */
    value = of_hello_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_hello_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_hello_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_hello_delete(obj);

    return TEST_PASS;
}

static int
test_of_hello_failed_error_msg_create_OF_VERSION_1_2(void)
{
    of_hello_failed_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_hello_failed_error_msg_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_HELLO_FAILED_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_HELLO_FAILED_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_hello_failed_error_msg_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_hello_failed_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_hello_failed_error_msg_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_hello_failed_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_packet_in_create_OF_VERSION_1_2(void)
{
    of_packet_in_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_packet_in_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 26);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PACKET_IN);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_PACKET_IN);

    /* Set up incrementing values for scalar members */
    value = of_packet_in_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_packet_in_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_packet_in_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_packet_in_delete(obj);

    return TEST_PASS;
}

static int
test_of_packet_out_create_OF_VERSION_1_2(void)
{
    of_packet_out_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_packet_out_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PACKET_OUT);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_PACKET_OUT);

    /* Set up incrementing values for scalar members */
    value = of_packet_out_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_packet_out_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_packet_out_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_packet_out_delete(obj);

    return TEST_PASS;
}

static int
test_of_port_mod_create_OF_VERSION_1_2(void)
{
    of_port_mod_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_port_mod_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 40);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_MOD);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_PORT_MOD);

    /* Set up incrementing values for scalar members */
    value = of_port_mod_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_port_mod_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_port_mod_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_port_mod_delete(obj);

    return TEST_PASS;
}

static int
test_of_port_mod_failed_error_msg_create_OF_VERSION_1_2(void)
{
    of_port_mod_failed_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_port_mod_failed_error_msg_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_MOD_FAILED_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_PORT_MOD_FAILED_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_port_mod_failed_error_msg_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_port_mod_failed_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_port_mod_failed_error_msg_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_port_mod_failed_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_port_stats_reply_create_OF_VERSION_1_2(void)
{
    of_port_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_port_stats_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_PORT_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_port_stats_reply_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_port_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_port_stats_reply_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_port_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_port_stats_request_create_OF_VERSION_1_2(void)
{
    of_port_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_port_stats_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_PORT_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_port_stats_request_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_port_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_port_stats_request_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_port_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_port_status_create_OF_VERSION_1_2(void)
{
    of_port_status_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_port_status_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 80);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_STATUS);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_PORT_STATUS);

    /* Set up incrementing values for scalar members */
    value = of_port_status_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_port_status_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_port_status_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_port_status_delete(obj);

    return TEST_PASS;
}

static int
test_of_queue_get_config_reply_create_OF_VERSION_1_2(void)
{
    of_queue_get_config_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_queue_get_config_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_GET_CONFIG_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_QUEUE_GET_CONFIG_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_queue_get_config_reply_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_queue_get_config_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_queue_get_config_reply_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_queue_get_config_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_queue_get_config_request_create_OF_VERSION_1_2(void)
{
    of_queue_get_config_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_queue_get_config_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_GET_CONFIG_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_QUEUE_GET_CONFIG_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_queue_get_config_request_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_queue_get_config_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_queue_get_config_request_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_queue_get_config_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_queue_op_failed_error_msg_create_OF_VERSION_1_2(void)
{
    of_queue_op_failed_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_queue_op_failed_error_msg_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_OP_FAILED_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_QUEUE_OP_FAILED_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_queue_op_failed_error_msg_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_queue_op_failed_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_queue_op_failed_error_msg_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_queue_op_failed_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_queue_stats_reply_create_OF_VERSION_1_2(void)
{
    of_queue_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_queue_stats_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_QUEUE_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_queue_stats_reply_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_queue_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_queue_stats_reply_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_queue_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_queue_stats_request_create_OF_VERSION_1_2(void)
{
    of_queue_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_queue_stats_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_QUEUE_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_queue_stats_request_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_queue_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_queue_stats_request_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_queue_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_role_reply_create_OF_VERSION_1_2(void)
{
    of_role_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_role_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ROLE_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_ROLE_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_role_reply_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_role_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_role_reply_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_role_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_role_request_create_OF_VERSION_1_2(void)
{
    of_role_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_role_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ROLE_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_ROLE_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_role_request_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_role_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_role_request_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_role_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_role_request_failed_error_msg_create_OF_VERSION_1_2(void)
{
    of_role_request_failed_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_role_request_failed_error_msg_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ROLE_REQUEST_FAILED_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_ROLE_REQUEST_FAILED_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_role_request_failed_error_msg_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_role_request_failed_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_role_request_failed_error_msg_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_role_request_failed_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_set_config_create_OF_VERSION_1_2(void)
{
    of_set_config_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_set_config_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_SET_CONFIG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_SET_CONFIG);

    /* Set up incrementing values for scalar members */
    value = of_set_config_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_set_config_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_set_config_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_set_config_delete(obj);

    return TEST_PASS;
}

static int
test_of_switch_config_failed_error_msg_create_OF_VERSION_1_2(void)
{
    of_switch_config_failed_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_switch_config_failed_error_msg_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_SWITCH_CONFIG_FAILED_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_SWITCH_CONFIG_FAILED_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_switch_config_failed_error_msg_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_switch_config_failed_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_switch_config_failed_error_msg_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_switch_config_failed_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_table_mod_create_OF_VERSION_1_2(void)
{
    of_table_mod_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_table_mod_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_MOD);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_TABLE_MOD);

    /* Set up incrementing values for scalar members */
    value = of_table_mod_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_table_mod_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_table_mod_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_table_mod_delete(obj);

    return TEST_PASS;
}

static int
test_of_table_mod_failed_error_msg_create_OF_VERSION_1_2(void)
{
    of_table_mod_failed_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_table_mod_failed_error_msg_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_MOD_FAILED_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_TABLE_MOD_FAILED_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_table_mod_failed_error_msg_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_table_mod_failed_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_table_mod_failed_error_msg_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_table_mod_failed_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_table_stats_reply_create_OF_VERSION_1_2(void)
{
    of_table_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_table_stats_reply_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_TABLE_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_table_stats_reply_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_table_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_table_stats_reply_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_table_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_table_stats_request_create_OF_VERSION_1_2(void)
{
    of_table_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_table_stats_request_new(OF_VERSION_1_2);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_2);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_TABLE_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_table_stats_request_OF_VERSION_1_2_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_table_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_table_stats_request_OF_VERSION_1_2_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_table_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_aggregate_stats_reply_create_OF_VERSION_1_3(void)
{
    of_aggregate_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_aggregate_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 40);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_AGGREGATE_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_aggregate_stats_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_aggregate_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_aggregate_stats_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_aggregate_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_aggregate_stats_request_create_OF_VERSION_1_3(void)
{
    of_aggregate_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_aggregate_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_AGGREGATE_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_aggregate_stats_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_aggregate_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_aggregate_stats_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_aggregate_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_async_get_reply_create_OF_VERSION_1_3(void)
{
    of_async_get_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_async_get_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ASYNC_GET_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_ASYNC_GET_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_async_get_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_async_get_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_async_get_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_async_get_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_async_get_request_create_OF_VERSION_1_3(void)
{
    of_async_get_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_async_get_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ASYNC_GET_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_ASYNC_GET_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_async_get_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_async_get_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_async_get_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_async_get_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_async_set_create_OF_VERSION_1_3(void)
{
    of_async_set_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_async_set_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ASYNC_SET);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_ASYNC_SET);

    /* Set up incrementing values for scalar members */
    value = of_async_set_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_async_set_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_async_set_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_async_set_delete(obj);

    return TEST_PASS;
}

static int
test_of_bad_action_error_msg_create_OF_VERSION_1_3(void)
{
    of_bad_action_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bad_action_error_msg_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BAD_ACTION_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BAD_ACTION_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_bad_action_error_msg_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bad_action_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bad_action_error_msg_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bad_action_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_bad_instruction_error_msg_create_OF_VERSION_1_3(void)
{
    of_bad_instruction_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bad_instruction_error_msg_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BAD_INSTRUCTION_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BAD_INSTRUCTION_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_bad_instruction_error_msg_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bad_instruction_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bad_instruction_error_msg_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bad_instruction_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_bad_match_error_msg_create_OF_VERSION_1_3(void)
{
    of_bad_match_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bad_match_error_msg_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BAD_MATCH_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BAD_MATCH_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_bad_match_error_msg_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bad_match_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bad_match_error_msg_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bad_match_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_bad_request_error_msg_create_OF_VERSION_1_3(void)
{
    of_bad_request_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bad_request_error_msg_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BAD_REQUEST_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BAD_REQUEST_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_bad_request_error_msg_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bad_request_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bad_request_error_msg_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bad_request_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_barrier_reply_create_OF_VERSION_1_3(void)
{
    of_barrier_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_barrier_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BARRIER_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BARRIER_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_barrier_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_barrier_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_barrier_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_barrier_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_barrier_request_create_OF_VERSION_1_3(void)
{
    of_barrier_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_barrier_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BARRIER_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BARRIER_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_barrier_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_barrier_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_barrier_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_barrier_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_arp_idle_create_OF_VERSION_1_3(void)
{
    of_bsn_arp_idle_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_arp_idle_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_ARP_IDLE);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_ARP_IDLE);

    /* Set up incrementing values for scalar members */
    value = of_bsn_arp_idle_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_arp_idle_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_arp_idle_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_arp_idle_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_bw_clear_data_reply_create_OF_VERSION_1_3(void)
{
    of_bsn_bw_clear_data_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_bw_clear_data_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_CLEAR_DATA_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_BW_CLEAR_DATA_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_bw_clear_data_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_bw_clear_data_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_bw_clear_data_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_bw_clear_data_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_bw_clear_data_request_create_OF_VERSION_1_3(void)
{
    of_bsn_bw_clear_data_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_bw_clear_data_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_CLEAR_DATA_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_BW_CLEAR_DATA_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_bw_clear_data_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_bw_clear_data_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_bw_clear_data_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_bw_clear_data_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_bw_enable_get_reply_create_OF_VERSION_1_3(void)
{
    of_bsn_bw_enable_get_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_bw_enable_get_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_ENABLE_GET_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_BW_ENABLE_GET_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_bw_enable_get_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_bw_enable_get_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_bw_enable_get_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_bw_enable_get_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_bw_enable_get_request_create_OF_VERSION_1_3(void)
{
    of_bsn_bw_enable_get_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_bw_enable_get_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_ENABLE_GET_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_BW_ENABLE_GET_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_bw_enable_get_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_bw_enable_get_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_bw_enable_get_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_bw_enable_get_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_bw_enable_set_reply_create_OF_VERSION_1_3(void)
{
    of_bsn_bw_enable_set_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_bw_enable_set_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_ENABLE_SET_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_BW_ENABLE_SET_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_bw_enable_set_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_bw_enable_set_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_bw_enable_set_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_bw_enable_set_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_bw_enable_set_request_create_OF_VERSION_1_3(void)
{
    of_bsn_bw_enable_set_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_bw_enable_set_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_ENABLE_SET_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_BW_ENABLE_SET_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_bw_enable_set_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_bw_enable_set_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_bw_enable_set_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_bw_enable_set_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_controller_connections_reply_create_OF_VERSION_1_3(void)
{
    of_bsn_controller_connections_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_controller_connections_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_CONTROLLER_CONNECTIONS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_CONTROLLER_CONNECTIONS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_controller_connections_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_controller_connections_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_controller_connections_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_controller_connections_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_controller_connections_request_create_OF_VERSION_1_3(void)
{
    of_bsn_controller_connections_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_controller_connections_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_CONTROLLER_CONNECTIONS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_CONTROLLER_CONNECTIONS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_controller_connections_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_controller_connections_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_controller_connections_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_controller_connections_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_debug_counter_desc_stats_reply_create_OF_VERSION_1_3(void)
{
    of_bsn_debug_counter_desc_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_debug_counter_desc_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_DEBUG_COUNTER_DESC_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_DEBUG_COUNTER_DESC_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_debug_counter_desc_stats_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_debug_counter_desc_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_debug_counter_desc_stats_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_debug_counter_desc_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_debug_counter_desc_stats_request_create_OF_VERSION_1_3(void)
{
    of_bsn_debug_counter_desc_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_debug_counter_desc_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_DEBUG_COUNTER_DESC_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_DEBUG_COUNTER_DESC_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_debug_counter_desc_stats_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_debug_counter_desc_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_debug_counter_desc_stats_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_debug_counter_desc_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_debug_counter_stats_reply_create_OF_VERSION_1_3(void)
{
    of_bsn_debug_counter_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_debug_counter_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_DEBUG_COUNTER_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_DEBUG_COUNTER_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_debug_counter_stats_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_debug_counter_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_debug_counter_stats_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_debug_counter_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_debug_counter_stats_request_create_OF_VERSION_1_3(void)
{
    of_bsn_debug_counter_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_debug_counter_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_DEBUG_COUNTER_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_DEBUG_COUNTER_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_debug_counter_stats_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_debug_counter_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_debug_counter_stats_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_debug_counter_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_error_create_OF_VERSION_1_3(void)
{
    of_bsn_error_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_error_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 272);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_ERROR);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_ERROR);

    /* Set up incrementing values for scalar members */
    value = of_bsn_error_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_error_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_error_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_error_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_flow_checksum_bucket_stats_reply_create_OF_VERSION_1_3(void)
{
    of_bsn_flow_checksum_bucket_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_flow_checksum_bucket_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_FLOW_CHECKSUM_BUCKET_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_FLOW_CHECKSUM_BUCKET_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_flow_checksum_bucket_stats_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_flow_checksum_bucket_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_flow_checksum_bucket_stats_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_flow_checksum_bucket_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_flow_checksum_bucket_stats_request_create_OF_VERSION_1_3(void)
{
    of_bsn_flow_checksum_bucket_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_flow_checksum_bucket_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 25);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_FLOW_CHECKSUM_BUCKET_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_FLOW_CHECKSUM_BUCKET_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_flow_checksum_bucket_stats_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_flow_checksum_bucket_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_flow_checksum_bucket_stats_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_flow_checksum_bucket_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_flow_idle_create_OF_VERSION_1_3(void)
{
    of_bsn_flow_idle_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_flow_idle_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 40);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_FLOW_IDLE);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_FLOW_IDLE);

    /* Set up incrementing values for scalar members */
    value = of_bsn_flow_idle_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_flow_idle_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_flow_idle_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_flow_idle_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_flow_idle_enable_get_reply_create_OF_VERSION_1_3(void)
{
    of_bsn_flow_idle_enable_get_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_flow_idle_enable_get_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_FLOW_IDLE_ENABLE_GET_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_FLOW_IDLE_ENABLE_GET_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_flow_idle_enable_get_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_flow_idle_enable_get_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_flow_idle_enable_get_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_flow_idle_enable_get_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_flow_idle_enable_get_request_create_OF_VERSION_1_3(void)
{
    of_bsn_flow_idle_enable_get_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_flow_idle_enable_get_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_FLOW_IDLE_ENABLE_GET_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_FLOW_IDLE_ENABLE_GET_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_flow_idle_enable_get_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_flow_idle_enable_get_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_flow_idle_enable_get_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_flow_idle_enable_get_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_flow_idle_enable_set_reply_create_OF_VERSION_1_3(void)
{
    of_bsn_flow_idle_enable_set_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_flow_idle_enable_set_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_FLOW_IDLE_ENABLE_SET_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_FLOW_IDLE_ENABLE_SET_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_flow_idle_enable_set_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_flow_idle_enable_set_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_flow_idle_enable_set_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_flow_idle_enable_set_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_flow_idle_enable_set_request_create_OF_VERSION_1_3(void)
{
    of_bsn_flow_idle_enable_set_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_flow_idle_enable_set_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_FLOW_IDLE_ENABLE_SET_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_FLOW_IDLE_ENABLE_SET_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_flow_idle_enable_set_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_flow_idle_enable_set_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_flow_idle_enable_set_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_flow_idle_enable_set_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_generic_stats_reply_create_OF_VERSION_1_3(void)
{
    of_bsn_generic_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_generic_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GENERIC_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GENERIC_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_generic_stats_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_generic_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_generic_stats_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_generic_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_generic_stats_request_create_OF_VERSION_1_3(void)
{
    of_bsn_generic_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_generic_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 88);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GENERIC_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GENERIC_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_generic_stats_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_generic_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_generic_stats_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_generic_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_gentable_bucket_stats_reply_create_OF_VERSION_1_3(void)
{
    of_bsn_gentable_bucket_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_gentable_bucket_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GENTABLE_BUCKET_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GENTABLE_BUCKET_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_gentable_bucket_stats_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_gentable_bucket_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_gentable_bucket_stats_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_gentable_bucket_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_gentable_bucket_stats_request_create_OF_VERSION_1_3(void)
{
    of_bsn_gentable_bucket_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_gentable_bucket_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 26);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GENTABLE_BUCKET_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GENTABLE_BUCKET_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_gentable_bucket_stats_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_gentable_bucket_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_gentable_bucket_stats_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_gentable_bucket_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_gentable_clear_reply_create_OF_VERSION_1_3(void)
{
    of_bsn_gentable_clear_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_gentable_clear_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 28);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GENTABLE_CLEAR_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GENTABLE_CLEAR_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_gentable_clear_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_gentable_clear_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_gentable_clear_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_gentable_clear_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_gentable_clear_request_create_OF_VERSION_1_3(void)
{
    of_bsn_gentable_clear_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_gentable_clear_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 52);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GENTABLE_CLEAR_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GENTABLE_CLEAR_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_gentable_clear_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_gentable_clear_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_gentable_clear_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_gentable_clear_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_gentable_desc_stats_reply_create_OF_VERSION_1_3(void)
{
    of_bsn_gentable_desc_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_gentable_desc_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GENTABLE_DESC_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GENTABLE_DESC_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_gentable_desc_stats_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_gentable_desc_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_gentable_desc_stats_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_gentable_desc_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_gentable_desc_stats_request_create_OF_VERSION_1_3(void)
{
    of_bsn_gentable_desc_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_gentable_desc_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GENTABLE_DESC_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GENTABLE_DESC_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_gentable_desc_stats_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_gentable_desc_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_gentable_desc_stats_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_gentable_desc_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_gentable_entry_add_create_OF_VERSION_1_3(void)
{
    of_bsn_gentable_entry_add_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_gentable_entry_add_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 36);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GENTABLE_ENTRY_ADD);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GENTABLE_ENTRY_ADD);

    /* Set up incrementing values for scalar members */
    value = of_bsn_gentable_entry_add_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_gentable_entry_add_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_gentable_entry_add_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_gentable_entry_add_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_gentable_entry_delete_create_OF_VERSION_1_3(void)
{
    of_bsn_gentable_entry_delete_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_gentable_entry_delete_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 18);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GENTABLE_ENTRY_DELETE);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GENTABLE_ENTRY_DELETE);

    /* Set up incrementing values for scalar members */
    value = of_bsn_gentable_entry_delete_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_gentable_entry_delete_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_gentable_entry_delete_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_gentable_entry_delete_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_gentable_entry_desc_stats_reply_create_OF_VERSION_1_3(void)
{
    of_bsn_gentable_entry_desc_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_gentable_entry_desc_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GENTABLE_ENTRY_DESC_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GENTABLE_ENTRY_DESC_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_gentable_entry_desc_stats_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_gentable_entry_desc_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_gentable_entry_desc_stats_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_gentable_entry_desc_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_gentable_entry_desc_stats_request_create_OF_VERSION_1_3(void)
{
    of_bsn_gentable_entry_desc_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_gentable_entry_desc_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 60);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GENTABLE_ENTRY_DESC_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GENTABLE_ENTRY_DESC_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_gentable_entry_desc_stats_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_gentable_entry_desc_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_gentable_entry_desc_stats_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_gentable_entry_desc_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_gentable_entry_stats_reply_create_OF_VERSION_1_3(void)
{
    of_bsn_gentable_entry_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_gentable_entry_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GENTABLE_ENTRY_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GENTABLE_ENTRY_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_gentable_entry_stats_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_gentable_entry_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_gentable_entry_stats_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_gentable_entry_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_gentable_entry_stats_request_create_OF_VERSION_1_3(void)
{
    of_bsn_gentable_entry_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_gentable_entry_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 60);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GENTABLE_ENTRY_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GENTABLE_ENTRY_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_gentable_entry_stats_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_gentable_entry_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_gentable_entry_stats_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_gentable_entry_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_gentable_error_create_OF_VERSION_1_3(void)
{
    of_bsn_gentable_error_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_gentable_error_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 276);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GENTABLE_ERROR);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GENTABLE_ERROR);

    /* Set up incrementing values for scalar members */
    value = of_bsn_gentable_error_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_gentable_error_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_gentable_error_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_gentable_error_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_gentable_set_buckets_size_create_OF_VERSION_1_3(void)
{
    of_bsn_gentable_set_buckets_size_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_gentable_set_buckets_size_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GENTABLE_SET_BUCKETS_SIZE);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GENTABLE_SET_BUCKETS_SIZE);

    /* Set up incrementing values for scalar members */
    value = of_bsn_gentable_set_buckets_size_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_gentable_set_buckets_size_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_gentable_set_buckets_size_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_gentable_set_buckets_size_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_gentable_stats_reply_create_OF_VERSION_1_3(void)
{
    of_bsn_gentable_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_gentable_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GENTABLE_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GENTABLE_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_gentable_stats_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_gentable_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_gentable_stats_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_gentable_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_gentable_stats_request_create_OF_VERSION_1_3(void)
{
    of_bsn_gentable_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_gentable_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GENTABLE_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GENTABLE_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_gentable_stats_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_gentable_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_gentable_stats_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_gentable_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_get_interfaces_reply_create_OF_VERSION_1_3(void)
{
    of_bsn_get_interfaces_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_get_interfaces_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_INTERFACES_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GET_INTERFACES_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_get_interfaces_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_get_interfaces_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_get_interfaces_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_get_interfaces_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_get_interfaces_request_create_OF_VERSION_1_3(void)
{
    of_bsn_get_interfaces_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_get_interfaces_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_INTERFACES_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GET_INTERFACES_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_get_interfaces_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_get_interfaces_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_get_interfaces_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_get_interfaces_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_get_mirroring_reply_create_OF_VERSION_1_3(void)
{
    of_bsn_get_mirroring_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_get_mirroring_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_MIRRORING_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GET_MIRRORING_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_get_mirroring_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_get_mirroring_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_get_mirroring_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_get_mirroring_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_get_mirroring_request_create_OF_VERSION_1_3(void)
{
    of_bsn_get_mirroring_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_get_mirroring_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_MIRRORING_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GET_MIRRORING_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_get_mirroring_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_get_mirroring_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_get_mirroring_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_get_mirroring_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_get_switch_pipeline_reply_create_OF_VERSION_1_3(void)
{
    of_bsn_get_switch_pipeline_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_get_switch_pipeline_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 272);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_SWITCH_PIPELINE_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GET_SWITCH_PIPELINE_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_get_switch_pipeline_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_get_switch_pipeline_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_get_switch_pipeline_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_get_switch_pipeline_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_get_switch_pipeline_request_create_OF_VERSION_1_3(void)
{
    of_bsn_get_switch_pipeline_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_get_switch_pipeline_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_SWITCH_PIPELINE_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GET_SWITCH_PIPELINE_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_get_switch_pipeline_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_get_switch_pipeline_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_get_switch_pipeline_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_get_switch_pipeline_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_image_desc_stats_reply_create_OF_VERSION_1_3(void)
{
    of_bsn_image_desc_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_image_desc_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 536);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_IMAGE_DESC_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_IMAGE_DESC_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_image_desc_stats_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_image_desc_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_image_desc_stats_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_image_desc_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_image_desc_stats_request_create_OF_VERSION_1_3(void)
{
    of_bsn_image_desc_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_image_desc_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_IMAGE_DESC_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_IMAGE_DESC_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_image_desc_stats_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_image_desc_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_image_desc_stats_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_image_desc_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_lacp_convergence_notif_create_OF_VERSION_1_3(void)
{
    of_bsn_lacp_convergence_notif_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_lacp_convergence_notif_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 52);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_LACP_CONVERGENCE_NOTIF);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_LACP_CONVERGENCE_NOTIF);

    /* Set up incrementing values for scalar members */
    value = of_bsn_lacp_convergence_notif_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_lacp_convergence_notif_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_lacp_convergence_notif_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_lacp_convergence_notif_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_lacp_stats_reply_create_OF_VERSION_1_3(void)
{
    of_bsn_lacp_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_lacp_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_LACP_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_LACP_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_lacp_stats_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_lacp_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_lacp_stats_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_lacp_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_lacp_stats_request_create_OF_VERSION_1_3(void)
{
    of_bsn_lacp_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_lacp_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_LACP_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_LACP_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_lacp_stats_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_lacp_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_lacp_stats_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_lacp_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_log_create_OF_VERSION_1_3(void)
{
    of_bsn_log_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_log_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 17);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_LOG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_LOG);

    /* Set up incrementing values for scalar members */
    value = of_bsn_log_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_log_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_log_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_log_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_lua_command_reply_create_OF_VERSION_1_3(void)
{
    of_bsn_lua_command_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_lua_command_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_LUA_COMMAND_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_LUA_COMMAND_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_lua_command_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_lua_command_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_lua_command_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_lua_command_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_lua_command_request_create_OF_VERSION_1_3(void)
{
    of_bsn_lua_command_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_lua_command_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_LUA_COMMAND_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_LUA_COMMAND_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_lua_command_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_lua_command_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_lua_command_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_lua_command_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_lua_notification_create_OF_VERSION_1_3(void)
{
    of_bsn_lua_notification_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_lua_notification_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_LUA_NOTIFICATION);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_LUA_NOTIFICATION);

    /* Set up incrementing values for scalar members */
    value = of_bsn_lua_notification_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_lua_notification_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_lua_notification_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_lua_notification_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_lua_upload_create_OF_VERSION_1_3(void)
{
    of_bsn_lua_upload_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_lua_upload_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 82);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_LUA_UPLOAD);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_LUA_UPLOAD);

    /* Set up incrementing values for scalar members */
    value = of_bsn_lua_upload_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_lua_upload_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_lua_upload_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_lua_upload_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_pdu_rx_reply_create_OF_VERSION_1_3(void)
{
    of_bsn_pdu_rx_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_pdu_rx_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 25);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_RX_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_PDU_RX_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_pdu_rx_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_pdu_rx_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_pdu_rx_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_pdu_rx_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_pdu_rx_request_create_OF_VERSION_1_3(void)
{
    of_bsn_pdu_rx_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_pdu_rx_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 28);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_RX_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_PDU_RX_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_pdu_rx_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_pdu_rx_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_pdu_rx_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_pdu_rx_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_pdu_rx_timeout_create_OF_VERSION_1_3(void)
{
    of_bsn_pdu_rx_timeout_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_pdu_rx_timeout_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 21);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_RX_TIMEOUT);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_PDU_RX_TIMEOUT);

    /* Set up incrementing values for scalar members */
    value = of_bsn_pdu_rx_timeout_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_pdu_rx_timeout_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_pdu_rx_timeout_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_pdu_rx_timeout_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_pdu_tx_reply_create_OF_VERSION_1_3(void)
{
    of_bsn_pdu_tx_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_pdu_tx_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 25);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_TX_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_PDU_TX_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_pdu_tx_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_pdu_tx_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_pdu_tx_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_pdu_tx_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_pdu_tx_request_create_OF_VERSION_1_3(void)
{
    of_bsn_pdu_tx_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_pdu_tx_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 28);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_TX_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_PDU_TX_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_pdu_tx_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_pdu_tx_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_pdu_tx_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_pdu_tx_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_port_counter_stats_reply_create_OF_VERSION_1_3(void)
{
    of_bsn_port_counter_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_port_counter_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PORT_COUNTER_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_PORT_COUNTER_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_port_counter_stats_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_port_counter_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_port_counter_stats_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_port_counter_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_port_counter_stats_request_create_OF_VERSION_1_3(void)
{
    of_bsn_port_counter_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_port_counter_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 28);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PORT_COUNTER_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_PORT_COUNTER_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_port_counter_stats_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_port_counter_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_port_counter_stats_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_port_counter_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_role_status_create_OF_VERSION_1_3(void)
{
    of_bsn_role_status_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_role_status_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_ROLE_STATUS);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_ROLE_STATUS);

    /* Set up incrementing values for scalar members */
    value = of_bsn_role_status_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_role_status_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_role_status_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_role_status_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_set_aux_cxns_reply_create_OF_VERSION_1_3(void)
{
    of_bsn_set_aux_cxns_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_set_aux_cxns_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_AUX_CXNS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_SET_AUX_CXNS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_set_aux_cxns_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_set_aux_cxns_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_set_aux_cxns_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_set_aux_cxns_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_set_aux_cxns_request_create_OF_VERSION_1_3(void)
{
    of_bsn_set_aux_cxns_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_set_aux_cxns_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_AUX_CXNS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_SET_AUX_CXNS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_set_aux_cxns_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_set_aux_cxns_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_set_aux_cxns_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_set_aux_cxns_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_set_lacp_reply_create_OF_VERSION_1_3(void)
{
    of_bsn_set_lacp_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_set_lacp_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_LACP_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_SET_LACP_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_set_lacp_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_set_lacp_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_set_lacp_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_set_lacp_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_set_lacp_request_create_OF_VERSION_1_3(void)
{
    of_bsn_set_lacp_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_set_lacp_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 38);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_LACP_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_SET_LACP_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_set_lacp_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_set_lacp_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_set_lacp_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_set_lacp_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_set_mirroring_create_OF_VERSION_1_3(void)
{
    of_bsn_set_mirroring_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_set_mirroring_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_MIRRORING);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_SET_MIRRORING);

    /* Set up incrementing values for scalar members */
    value = of_bsn_set_mirroring_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_set_mirroring_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_set_mirroring_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_set_mirroring_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_set_pktin_suppression_reply_create_OF_VERSION_1_3(void)
{
    of_bsn_set_pktin_suppression_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_set_pktin_suppression_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_PKTIN_SUPPRESSION_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_SET_PKTIN_SUPPRESSION_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_set_pktin_suppression_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_set_pktin_suppression_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_set_pktin_suppression_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_set_pktin_suppression_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_set_pktin_suppression_request_create_OF_VERSION_1_3(void)
{
    of_bsn_set_pktin_suppression_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_set_pktin_suppression_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_PKTIN_SUPPRESSION_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_SET_PKTIN_SUPPRESSION_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_set_pktin_suppression_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_set_pktin_suppression_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_set_pktin_suppression_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_set_pktin_suppression_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_set_switch_pipeline_reply_create_OF_VERSION_1_3(void)
{
    of_bsn_set_switch_pipeline_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_set_switch_pipeline_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_SWITCH_PIPELINE_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_SET_SWITCH_PIPELINE_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_set_switch_pipeline_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_set_switch_pipeline_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_set_switch_pipeline_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_set_switch_pipeline_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_set_switch_pipeline_request_create_OF_VERSION_1_3(void)
{
    of_bsn_set_switch_pipeline_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_set_switch_pipeline_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 272);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_SWITCH_PIPELINE_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_SET_SWITCH_PIPELINE_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_set_switch_pipeline_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_set_switch_pipeline_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_set_switch_pipeline_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_set_switch_pipeline_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_switch_pipeline_stats_reply_create_OF_VERSION_1_3(void)
{
    of_bsn_switch_pipeline_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_switch_pipeline_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SWITCH_PIPELINE_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_SWITCH_PIPELINE_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_switch_pipeline_stats_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_switch_pipeline_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_switch_pipeline_stats_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_switch_pipeline_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_switch_pipeline_stats_request_create_OF_VERSION_1_3(void)
{
    of_bsn_switch_pipeline_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_switch_pipeline_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SWITCH_PIPELINE_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_SWITCH_PIPELINE_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_switch_pipeline_stats_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_switch_pipeline_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_switch_pipeline_stats_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_switch_pipeline_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_table_checksum_stats_reply_create_OF_VERSION_1_3(void)
{
    of_bsn_table_checksum_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_table_checksum_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_TABLE_CHECKSUM_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_table_checksum_stats_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_table_checksum_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_table_checksum_stats_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_table_checksum_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_table_checksum_stats_request_create_OF_VERSION_1_3(void)
{
    of_bsn_table_checksum_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_table_checksum_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_TABLE_CHECKSUM_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_table_checksum_stats_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_table_checksum_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_table_checksum_stats_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_table_checksum_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_table_set_buckets_size_create_OF_VERSION_1_3(void)
{
    of_bsn_table_set_buckets_size_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_table_set_buckets_size_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_TABLE_SET_BUCKETS_SIZE);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_TABLE_SET_BUCKETS_SIZE);

    /* Set up incrementing values for scalar members */
    value = of_bsn_table_set_buckets_size_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_table_set_buckets_size_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_table_set_buckets_size_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_table_set_buckets_size_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_time_reply_create_OF_VERSION_1_3(void)
{
    of_bsn_time_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_time_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_TIME_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_TIME_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_time_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_time_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_time_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_time_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_time_request_create_OF_VERSION_1_3(void)
{
    of_bsn_time_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_time_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_TIME_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_TIME_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_time_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_time_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_time_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_time_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_virtual_port_create_reply_create_OF_VERSION_1_3(void)
{
    of_bsn_virtual_port_create_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_virtual_port_create_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VIRTUAL_PORT_CREATE_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_VIRTUAL_PORT_CREATE_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_virtual_port_create_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_virtual_port_create_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_virtual_port_create_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_virtual_port_create_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_virtual_port_create_request_create_OF_VERSION_1_3(void)
{
    of_bsn_virtual_port_create_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_virtual_port_create_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VIRTUAL_PORT_CREATE_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_VIRTUAL_PORT_CREATE_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_virtual_port_create_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_virtual_port_create_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_virtual_port_create_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_virtual_port_create_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_virtual_port_remove_reply_create_OF_VERSION_1_3(void)
{
    of_bsn_virtual_port_remove_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_virtual_port_remove_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VIRTUAL_PORT_REMOVE_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_VIRTUAL_PORT_REMOVE_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_virtual_port_remove_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_virtual_port_remove_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_virtual_port_remove_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_virtual_port_remove_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_virtual_port_remove_request_create_OF_VERSION_1_3(void)
{
    of_bsn_virtual_port_remove_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_virtual_port_remove_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VIRTUAL_PORT_REMOVE_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_VIRTUAL_PORT_REMOVE_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_virtual_port_remove_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_virtual_port_remove_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_virtual_port_remove_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_virtual_port_remove_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_vlan_counter_clear_create_OF_VERSION_1_3(void)
{
    of_bsn_vlan_counter_clear_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_vlan_counter_clear_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 18);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VLAN_COUNTER_CLEAR);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_VLAN_COUNTER_CLEAR);

    /* Set up incrementing values for scalar members */
    value = of_bsn_vlan_counter_clear_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_vlan_counter_clear_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_vlan_counter_clear_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_vlan_counter_clear_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_vlan_counter_stats_reply_create_OF_VERSION_1_3(void)
{
    of_bsn_vlan_counter_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_vlan_counter_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VLAN_COUNTER_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_VLAN_COUNTER_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_vlan_counter_stats_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_vlan_counter_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_vlan_counter_stats_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_vlan_counter_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_vlan_counter_stats_request_create_OF_VERSION_1_3(void)
{
    of_bsn_vlan_counter_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_vlan_counter_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 26);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VLAN_COUNTER_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_VLAN_COUNTER_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_vlan_counter_stats_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_vlan_counter_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_vlan_counter_stats_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_vlan_counter_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_vrf_counter_stats_reply_create_OF_VERSION_1_3(void)
{
    of_bsn_vrf_counter_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_vrf_counter_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VRF_COUNTER_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_VRF_COUNTER_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_vrf_counter_stats_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_vrf_counter_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_vrf_counter_stats_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_vrf_counter_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_vrf_counter_stats_request_create_OF_VERSION_1_3(void)
{
    of_bsn_vrf_counter_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_vrf_counter_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 28);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VRF_COUNTER_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_VRF_COUNTER_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_vrf_counter_stats_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_vrf_counter_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_vrf_counter_stats_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_vrf_counter_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_desc_stats_reply_create_OF_VERSION_1_3(void)
{
    of_desc_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_desc_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 1072);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_DESC_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_DESC_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_desc_stats_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_desc_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_desc_stats_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_desc_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_desc_stats_request_create_OF_VERSION_1_3(void)
{
    of_desc_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_desc_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_DESC_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_DESC_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_desc_stats_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_desc_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_desc_stats_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_desc_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_echo_reply_create_OF_VERSION_1_3(void)
{
    of_echo_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_echo_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ECHO_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_ECHO_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_echo_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_echo_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_echo_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_echo_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_echo_request_create_OF_VERSION_1_3(void)
{
    of_echo_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_echo_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ECHO_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_ECHO_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_echo_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_echo_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_echo_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_echo_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_features_reply_create_OF_VERSION_1_3(void)
{
    of_features_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_features_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FEATURES_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FEATURES_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_features_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_features_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_features_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_features_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_features_request_create_OF_VERSION_1_3(void)
{
    of_features_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_features_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FEATURES_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FEATURES_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_features_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_features_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_features_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_features_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_add_create_OF_VERSION_1_3(void)
{
    of_flow_add_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_add_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_ADD);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_ADD);

    /* Set up incrementing values for scalar members */
    value = of_flow_add_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_add_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_add_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_add_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_delete_create_OF_VERSION_1_3(void)
{
    of_flow_delete_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_delete_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_DELETE);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_DELETE);

    /* Set up incrementing values for scalar members */
    value = of_flow_delete_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_delete_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_delete_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_delete_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_delete_strict_create_OF_VERSION_1_3(void)
{
    of_flow_delete_strict_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_delete_strict_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_DELETE_STRICT);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_DELETE_STRICT);

    /* Set up incrementing values for scalar members */
    value = of_flow_delete_strict_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_delete_strict_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_delete_strict_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_delete_strict_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_mod_failed_error_msg_create_OF_VERSION_1_3(void)
{
    of_flow_mod_failed_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_mod_failed_error_msg_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_MOD_FAILED_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_MOD_FAILED_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_flow_mod_failed_error_msg_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_mod_failed_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_mod_failed_error_msg_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_mod_failed_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_modify_create_OF_VERSION_1_3(void)
{
    of_flow_modify_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_modify_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_MODIFY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_MODIFY);

    /* Set up incrementing values for scalar members */
    value = of_flow_modify_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_modify_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_modify_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_modify_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_modify_strict_create_OF_VERSION_1_3(void)
{
    of_flow_modify_strict_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_modify_strict_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_MODIFY_STRICT);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_MODIFY_STRICT);

    /* Set up incrementing values for scalar members */
    value = of_flow_modify_strict_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_modify_strict_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_modify_strict_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_modify_strict_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_removed_create_OF_VERSION_1_3(void)
{
    of_flow_removed_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_removed_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_REMOVED);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_REMOVED);

    /* Set up incrementing values for scalar members */
    value = of_flow_removed_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_removed_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_removed_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_removed_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_stats_reply_create_OF_VERSION_1_3(void)
{
    of_flow_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_flow_stats_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_stats_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_stats_request_create_OF_VERSION_1_3(void)
{
    of_flow_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_flow_stats_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_stats_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_get_config_reply_create_OF_VERSION_1_3(void)
{
    of_get_config_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_get_config_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GET_CONFIG_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GET_CONFIG_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_get_config_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_get_config_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_get_config_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_get_config_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_get_config_request_create_OF_VERSION_1_3(void)
{
    of_get_config_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_get_config_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GET_CONFIG_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GET_CONFIG_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_get_config_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_get_config_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_get_config_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_get_config_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_group_add_create_OF_VERSION_1_3(void)
{
    of_group_add_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_group_add_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_ADD);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GROUP_ADD);

    /* Set up incrementing values for scalar members */
    value = of_group_add_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_group_add_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_group_add_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_group_add_delete(obj);

    return TEST_PASS;
}

static int
test_of_group_delete_create_OF_VERSION_1_3(void)
{
    of_group_delete_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_group_delete_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_DELETE);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GROUP_DELETE);

    /* Set up incrementing values for scalar members */
    value = of_group_delete_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_group_delete_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_group_delete_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_group_delete_delete(obj);

    return TEST_PASS;
}

static int
test_of_group_desc_stats_reply_create_OF_VERSION_1_3(void)
{
    of_group_desc_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_group_desc_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_DESC_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GROUP_DESC_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_group_desc_stats_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_group_desc_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_group_desc_stats_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_group_desc_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_group_desc_stats_request_create_OF_VERSION_1_3(void)
{
    of_group_desc_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_group_desc_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_DESC_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GROUP_DESC_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_group_desc_stats_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_group_desc_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_group_desc_stats_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_group_desc_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_group_features_stats_reply_create_OF_VERSION_1_3(void)
{
    of_group_features_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_group_features_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GROUP_FEATURES_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_group_features_stats_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_group_features_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_group_features_stats_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_group_features_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_group_features_stats_request_create_OF_VERSION_1_3(void)
{
    of_group_features_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_group_features_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GROUP_FEATURES_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_group_features_stats_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_group_features_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_group_features_stats_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_group_features_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_group_mod_failed_error_msg_create_OF_VERSION_1_3(void)
{
    of_group_mod_failed_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_group_mod_failed_error_msg_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_MOD_FAILED_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GROUP_MOD_FAILED_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_group_mod_failed_error_msg_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_group_mod_failed_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_group_mod_failed_error_msg_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_group_mod_failed_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_group_modify_create_OF_VERSION_1_3(void)
{
    of_group_modify_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_group_modify_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_MODIFY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GROUP_MODIFY);

    /* Set up incrementing values for scalar members */
    value = of_group_modify_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_group_modify_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_group_modify_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_group_modify_delete(obj);

    return TEST_PASS;
}

static int
test_of_group_stats_reply_create_OF_VERSION_1_3(void)
{
    of_group_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_group_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GROUP_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_group_stats_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_group_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_group_stats_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_group_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_group_stats_request_create_OF_VERSION_1_3(void)
{
    of_group_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_group_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GROUP_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_group_stats_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_group_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_group_stats_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_group_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_hello_create_OF_VERSION_1_3(void)
{
    of_hello_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_hello_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_HELLO);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_HELLO);

    /* Set up incrementing values for scalar members */
    value = of_hello_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_hello_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_hello_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_hello_delete(obj);

    return TEST_PASS;
}

static int
test_of_hello_failed_error_msg_create_OF_VERSION_1_3(void)
{
    of_hello_failed_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_hello_failed_error_msg_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_HELLO_FAILED_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_HELLO_FAILED_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_hello_failed_error_msg_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_hello_failed_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_hello_failed_error_msg_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_hello_failed_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_meter_config_stats_reply_create_OF_VERSION_1_3(void)
{
    of_meter_config_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_meter_config_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_METER_CONFIG_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_METER_CONFIG_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_meter_config_stats_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_meter_config_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_meter_config_stats_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_meter_config_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_meter_config_stats_request_create_OF_VERSION_1_3(void)
{
    of_meter_config_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_meter_config_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_METER_CONFIG_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_METER_CONFIG_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_meter_config_stats_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_meter_config_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_meter_config_stats_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_meter_config_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_meter_features_stats_reply_create_OF_VERSION_1_3(void)
{
    of_meter_features_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_meter_features_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_METER_FEATURES_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_METER_FEATURES_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_meter_features_stats_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_meter_features_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_meter_features_stats_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_meter_features_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_meter_features_stats_request_create_OF_VERSION_1_3(void)
{
    of_meter_features_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_meter_features_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_METER_FEATURES_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_METER_FEATURES_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_meter_features_stats_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_meter_features_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_meter_features_stats_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_meter_features_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_meter_mod_create_OF_VERSION_1_3(void)
{
    of_meter_mod_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_meter_mod_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_METER_MOD);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_METER_MOD);

    /* Set up incrementing values for scalar members */
    value = of_meter_mod_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_meter_mod_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_meter_mod_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_meter_mod_delete(obj);

    return TEST_PASS;
}

static int
test_of_meter_mod_failed_error_msg_create_OF_VERSION_1_3(void)
{
    of_meter_mod_failed_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_meter_mod_failed_error_msg_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_METER_MOD_FAILED_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_METER_MOD_FAILED_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_meter_mod_failed_error_msg_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_meter_mod_failed_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_meter_mod_failed_error_msg_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_meter_mod_failed_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_meter_stats_reply_create_OF_VERSION_1_3(void)
{
    of_meter_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_meter_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_METER_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_METER_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_meter_stats_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_meter_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_meter_stats_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_meter_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_meter_stats_request_create_OF_VERSION_1_3(void)
{
    of_meter_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_meter_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_METER_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_METER_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_meter_stats_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_meter_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_meter_stats_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_meter_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_packet_in_create_OF_VERSION_1_3(void)
{
    of_packet_in_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_packet_in_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 34);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PACKET_IN);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_PACKET_IN);

    /* Set up incrementing values for scalar members */
    value = of_packet_in_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_packet_in_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_packet_in_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_packet_in_delete(obj);

    return TEST_PASS;
}

static int
test_of_packet_out_create_OF_VERSION_1_3(void)
{
    of_packet_out_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_packet_out_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PACKET_OUT);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_PACKET_OUT);

    /* Set up incrementing values for scalar members */
    value = of_packet_out_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_packet_out_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_packet_out_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_packet_out_delete(obj);

    return TEST_PASS;
}

static int
test_of_port_desc_stats_reply_create_OF_VERSION_1_3(void)
{
    of_port_desc_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_port_desc_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_DESC_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_PORT_DESC_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_port_desc_stats_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_port_desc_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_port_desc_stats_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_port_desc_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_port_desc_stats_request_create_OF_VERSION_1_3(void)
{
    of_port_desc_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_port_desc_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_DESC_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_PORT_DESC_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_port_desc_stats_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_port_desc_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_port_desc_stats_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_port_desc_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_port_mod_create_OF_VERSION_1_3(void)
{
    of_port_mod_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_port_mod_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 40);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_MOD);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_PORT_MOD);

    /* Set up incrementing values for scalar members */
    value = of_port_mod_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_port_mod_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_port_mod_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_port_mod_delete(obj);

    return TEST_PASS;
}

static int
test_of_port_mod_failed_error_msg_create_OF_VERSION_1_3(void)
{
    of_port_mod_failed_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_port_mod_failed_error_msg_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_MOD_FAILED_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_PORT_MOD_FAILED_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_port_mod_failed_error_msg_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_port_mod_failed_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_port_mod_failed_error_msg_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_port_mod_failed_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_port_stats_reply_create_OF_VERSION_1_3(void)
{
    of_port_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_port_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_PORT_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_port_stats_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_port_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_port_stats_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_port_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_port_stats_request_create_OF_VERSION_1_3(void)
{
    of_port_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_port_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_PORT_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_port_stats_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_port_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_port_stats_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_port_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_port_status_create_OF_VERSION_1_3(void)
{
    of_port_status_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_port_status_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 80);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_STATUS);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_PORT_STATUS);

    /* Set up incrementing values for scalar members */
    value = of_port_status_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_port_status_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_port_status_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_port_status_delete(obj);

    return TEST_PASS;
}

static int
test_of_queue_get_config_reply_create_OF_VERSION_1_3(void)
{
    of_queue_get_config_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_queue_get_config_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_GET_CONFIG_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_QUEUE_GET_CONFIG_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_queue_get_config_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_queue_get_config_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_queue_get_config_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_queue_get_config_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_queue_get_config_request_create_OF_VERSION_1_3(void)
{
    of_queue_get_config_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_queue_get_config_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_GET_CONFIG_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_QUEUE_GET_CONFIG_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_queue_get_config_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_queue_get_config_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_queue_get_config_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_queue_get_config_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_queue_op_failed_error_msg_create_OF_VERSION_1_3(void)
{
    of_queue_op_failed_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_queue_op_failed_error_msg_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_OP_FAILED_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_QUEUE_OP_FAILED_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_queue_op_failed_error_msg_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_queue_op_failed_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_queue_op_failed_error_msg_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_queue_op_failed_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_queue_stats_reply_create_OF_VERSION_1_3(void)
{
    of_queue_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_queue_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_QUEUE_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_queue_stats_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_queue_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_queue_stats_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_queue_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_queue_stats_request_create_OF_VERSION_1_3(void)
{
    of_queue_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_queue_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_QUEUE_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_queue_stats_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_queue_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_queue_stats_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_queue_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_role_reply_create_OF_VERSION_1_3(void)
{
    of_role_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_role_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ROLE_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_ROLE_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_role_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_role_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_role_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_role_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_role_request_create_OF_VERSION_1_3(void)
{
    of_role_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_role_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ROLE_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_ROLE_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_role_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_role_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_role_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_role_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_role_request_failed_error_msg_create_OF_VERSION_1_3(void)
{
    of_role_request_failed_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_role_request_failed_error_msg_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ROLE_REQUEST_FAILED_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_ROLE_REQUEST_FAILED_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_role_request_failed_error_msg_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_role_request_failed_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_role_request_failed_error_msg_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_role_request_failed_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_set_config_create_OF_VERSION_1_3(void)
{
    of_set_config_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_set_config_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_SET_CONFIG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_SET_CONFIG);

    /* Set up incrementing values for scalar members */
    value = of_set_config_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_set_config_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_set_config_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_set_config_delete(obj);

    return TEST_PASS;
}

static int
test_of_switch_config_failed_error_msg_create_OF_VERSION_1_3(void)
{
    of_switch_config_failed_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_switch_config_failed_error_msg_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_SWITCH_CONFIG_FAILED_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_SWITCH_CONFIG_FAILED_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_switch_config_failed_error_msg_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_switch_config_failed_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_switch_config_failed_error_msg_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_switch_config_failed_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_table_features_failed_error_msg_create_OF_VERSION_1_3(void)
{
    of_table_features_failed_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_table_features_failed_error_msg_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_FEATURES_FAILED_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_TABLE_FEATURES_FAILED_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_table_features_failed_error_msg_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_table_features_failed_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_table_features_failed_error_msg_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_table_features_failed_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_table_features_stats_reply_create_OF_VERSION_1_3(void)
{
    of_table_features_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_table_features_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_FEATURES_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_TABLE_FEATURES_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_table_features_stats_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_table_features_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_table_features_stats_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_table_features_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_table_features_stats_request_create_OF_VERSION_1_3(void)
{
    of_table_features_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_table_features_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_FEATURES_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_TABLE_FEATURES_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_table_features_stats_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_table_features_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_table_features_stats_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_table_features_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_table_mod_create_OF_VERSION_1_3(void)
{
    of_table_mod_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_table_mod_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_MOD);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_TABLE_MOD);

    /* Set up incrementing values for scalar members */
    value = of_table_mod_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_table_mod_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_table_mod_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_table_mod_delete(obj);

    return TEST_PASS;
}

static int
test_of_table_mod_failed_error_msg_create_OF_VERSION_1_3(void)
{
    of_table_mod_failed_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_table_mod_failed_error_msg_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_MOD_FAILED_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_TABLE_MOD_FAILED_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_table_mod_failed_error_msg_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_table_mod_failed_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_table_mod_failed_error_msg_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_table_mod_failed_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_table_stats_reply_create_OF_VERSION_1_3(void)
{
    of_table_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_table_stats_reply_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_TABLE_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_table_stats_reply_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_table_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_table_stats_reply_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_table_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_table_stats_request_create_OF_VERSION_1_3(void)
{
    of_table_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_table_stats_request_new(OF_VERSION_1_3);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_3);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_TABLE_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_table_stats_request_OF_VERSION_1_3_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_table_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_table_stats_request_OF_VERSION_1_3_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_table_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_aggregate_stats_reply_create_OF_VERSION_1_4(void)
{
    of_aggregate_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_aggregate_stats_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 40);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_AGGREGATE_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_aggregate_stats_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_aggregate_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_aggregate_stats_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_aggregate_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_aggregate_stats_request_create_OF_VERSION_1_4(void)
{
    of_aggregate_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_aggregate_stats_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_AGGREGATE_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_aggregate_stats_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_aggregate_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_aggregate_stats_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_aggregate_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_async_config_failed_error_msg_create_OF_VERSION_1_4(void)
{
    of_async_config_failed_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_async_config_failed_error_msg_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ASYNC_CONFIG_FAILED_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_ASYNC_CONFIG_FAILED_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_async_config_failed_error_msg_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_async_config_failed_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_async_config_failed_error_msg_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_async_config_failed_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_async_get_reply_create_OF_VERSION_1_4(void)
{
    of_async_get_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_async_get_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ASYNC_GET_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_ASYNC_GET_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_async_get_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_async_get_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_async_get_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_async_get_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_async_get_request_create_OF_VERSION_1_4(void)
{
    of_async_get_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_async_get_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ASYNC_GET_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_ASYNC_GET_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_async_get_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_async_get_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_async_get_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_async_get_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_async_set_create_OF_VERSION_1_4(void)
{
    of_async_set_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_async_set_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ASYNC_SET);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_ASYNC_SET);

    /* Set up incrementing values for scalar members */
    value = of_async_set_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_async_set_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_async_set_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_async_set_delete(obj);

    return TEST_PASS;
}

static int
test_of_bad_action_error_msg_create_OF_VERSION_1_4(void)
{
    of_bad_action_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bad_action_error_msg_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BAD_ACTION_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BAD_ACTION_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_bad_action_error_msg_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bad_action_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bad_action_error_msg_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bad_action_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_bad_instruction_error_msg_create_OF_VERSION_1_4(void)
{
    of_bad_instruction_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bad_instruction_error_msg_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BAD_INSTRUCTION_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BAD_INSTRUCTION_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_bad_instruction_error_msg_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bad_instruction_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bad_instruction_error_msg_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bad_instruction_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_bad_match_error_msg_create_OF_VERSION_1_4(void)
{
    of_bad_match_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bad_match_error_msg_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BAD_MATCH_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BAD_MATCH_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_bad_match_error_msg_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bad_match_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bad_match_error_msg_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bad_match_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_bad_property_error_msg_create_OF_VERSION_1_4(void)
{
    of_bad_property_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bad_property_error_msg_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BAD_PROPERTY_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BAD_PROPERTY_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_bad_property_error_msg_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bad_property_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bad_property_error_msg_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bad_property_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_bad_request_error_msg_create_OF_VERSION_1_4(void)
{
    of_bad_request_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bad_request_error_msg_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BAD_REQUEST_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BAD_REQUEST_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_bad_request_error_msg_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bad_request_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bad_request_error_msg_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bad_request_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_barrier_reply_create_OF_VERSION_1_4(void)
{
    of_barrier_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_barrier_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BARRIER_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BARRIER_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_barrier_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_barrier_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_barrier_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_barrier_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_barrier_request_create_OF_VERSION_1_4(void)
{
    of_barrier_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_barrier_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BARRIER_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BARRIER_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_barrier_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_barrier_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_barrier_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_barrier_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_arp_idle_create_OF_VERSION_1_4(void)
{
    of_bsn_arp_idle_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_arp_idle_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_ARP_IDLE);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_ARP_IDLE);

    /* Set up incrementing values for scalar members */
    value = of_bsn_arp_idle_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_arp_idle_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_arp_idle_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_arp_idle_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_bw_clear_data_reply_create_OF_VERSION_1_4(void)
{
    of_bsn_bw_clear_data_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_bw_clear_data_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_CLEAR_DATA_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_BW_CLEAR_DATA_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_bw_clear_data_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_bw_clear_data_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_bw_clear_data_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_bw_clear_data_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_bw_clear_data_request_create_OF_VERSION_1_4(void)
{
    of_bsn_bw_clear_data_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_bw_clear_data_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_CLEAR_DATA_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_BW_CLEAR_DATA_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_bw_clear_data_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_bw_clear_data_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_bw_clear_data_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_bw_clear_data_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_bw_enable_get_reply_create_OF_VERSION_1_4(void)
{
    of_bsn_bw_enable_get_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_bw_enable_get_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_ENABLE_GET_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_BW_ENABLE_GET_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_bw_enable_get_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_bw_enable_get_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_bw_enable_get_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_bw_enable_get_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_bw_enable_get_request_create_OF_VERSION_1_4(void)
{
    of_bsn_bw_enable_get_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_bw_enable_get_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_ENABLE_GET_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_BW_ENABLE_GET_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_bw_enable_get_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_bw_enable_get_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_bw_enable_get_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_bw_enable_get_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_bw_enable_set_reply_create_OF_VERSION_1_4(void)
{
    of_bsn_bw_enable_set_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_bw_enable_set_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_ENABLE_SET_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_BW_ENABLE_SET_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_bw_enable_set_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_bw_enable_set_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_bw_enable_set_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_bw_enable_set_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_bw_enable_set_request_create_OF_VERSION_1_4(void)
{
    of_bsn_bw_enable_set_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_bw_enable_set_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_BW_ENABLE_SET_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_BW_ENABLE_SET_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_bw_enable_set_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_bw_enable_set_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_bw_enable_set_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_bw_enable_set_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_controller_connections_reply_create_OF_VERSION_1_4(void)
{
    of_bsn_controller_connections_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_controller_connections_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_CONTROLLER_CONNECTIONS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_CONTROLLER_CONNECTIONS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_controller_connections_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_controller_connections_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_controller_connections_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_controller_connections_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_controller_connections_request_create_OF_VERSION_1_4(void)
{
    of_bsn_controller_connections_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_controller_connections_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_CONTROLLER_CONNECTIONS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_CONTROLLER_CONNECTIONS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_controller_connections_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_controller_connections_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_controller_connections_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_controller_connections_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_debug_counter_desc_stats_reply_create_OF_VERSION_1_4(void)
{
    of_bsn_debug_counter_desc_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_debug_counter_desc_stats_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_DEBUG_COUNTER_DESC_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_DEBUG_COUNTER_DESC_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_debug_counter_desc_stats_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_debug_counter_desc_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_debug_counter_desc_stats_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_debug_counter_desc_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_debug_counter_desc_stats_request_create_OF_VERSION_1_4(void)
{
    of_bsn_debug_counter_desc_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_debug_counter_desc_stats_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_DEBUG_COUNTER_DESC_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_DEBUG_COUNTER_DESC_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_debug_counter_desc_stats_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_debug_counter_desc_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_debug_counter_desc_stats_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_debug_counter_desc_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_debug_counter_stats_reply_create_OF_VERSION_1_4(void)
{
    of_bsn_debug_counter_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_debug_counter_stats_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_DEBUG_COUNTER_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_DEBUG_COUNTER_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_debug_counter_stats_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_debug_counter_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_debug_counter_stats_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_debug_counter_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_debug_counter_stats_request_create_OF_VERSION_1_4(void)
{
    of_bsn_debug_counter_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_debug_counter_stats_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_DEBUG_COUNTER_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_DEBUG_COUNTER_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_debug_counter_stats_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_debug_counter_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_debug_counter_stats_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_debug_counter_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_error_create_OF_VERSION_1_4(void)
{
    of_bsn_error_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_error_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 272);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_ERROR);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_ERROR);

    /* Set up incrementing values for scalar members */
    value = of_bsn_error_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_error_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_error_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_error_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_flow_checksum_bucket_stats_reply_create_OF_VERSION_1_4(void)
{
    of_bsn_flow_checksum_bucket_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_flow_checksum_bucket_stats_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_FLOW_CHECKSUM_BUCKET_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_FLOW_CHECKSUM_BUCKET_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_flow_checksum_bucket_stats_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_flow_checksum_bucket_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_flow_checksum_bucket_stats_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_flow_checksum_bucket_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_flow_checksum_bucket_stats_request_create_OF_VERSION_1_4(void)
{
    of_bsn_flow_checksum_bucket_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_flow_checksum_bucket_stats_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 25);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_FLOW_CHECKSUM_BUCKET_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_FLOW_CHECKSUM_BUCKET_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_flow_checksum_bucket_stats_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_flow_checksum_bucket_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_flow_checksum_bucket_stats_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_flow_checksum_bucket_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_flow_idle_create_OF_VERSION_1_4(void)
{
    of_bsn_flow_idle_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_flow_idle_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 40);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_FLOW_IDLE);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_FLOW_IDLE);

    /* Set up incrementing values for scalar members */
    value = of_bsn_flow_idle_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_flow_idle_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_flow_idle_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_flow_idle_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_flow_idle_enable_get_reply_create_OF_VERSION_1_4(void)
{
    of_bsn_flow_idle_enable_get_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_flow_idle_enable_get_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_FLOW_IDLE_ENABLE_GET_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_FLOW_IDLE_ENABLE_GET_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_flow_idle_enable_get_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_flow_idle_enable_get_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_flow_idle_enable_get_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_flow_idle_enable_get_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_flow_idle_enable_get_request_create_OF_VERSION_1_4(void)
{
    of_bsn_flow_idle_enable_get_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_flow_idle_enable_get_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_FLOW_IDLE_ENABLE_GET_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_FLOW_IDLE_ENABLE_GET_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_flow_idle_enable_get_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_flow_idle_enable_get_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_flow_idle_enable_get_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_flow_idle_enable_get_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_flow_idle_enable_set_reply_create_OF_VERSION_1_4(void)
{
    of_bsn_flow_idle_enable_set_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_flow_idle_enable_set_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_FLOW_IDLE_ENABLE_SET_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_FLOW_IDLE_ENABLE_SET_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_flow_idle_enable_set_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_flow_idle_enable_set_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_flow_idle_enable_set_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_flow_idle_enable_set_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_flow_idle_enable_set_request_create_OF_VERSION_1_4(void)
{
    of_bsn_flow_idle_enable_set_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_flow_idle_enable_set_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_FLOW_IDLE_ENABLE_SET_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_FLOW_IDLE_ENABLE_SET_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_flow_idle_enable_set_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_flow_idle_enable_set_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_flow_idle_enable_set_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_flow_idle_enable_set_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_generic_async_create_OF_VERSION_1_4(void)
{
    of_bsn_generic_async_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_generic_async_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 80);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GENERIC_ASYNC);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GENERIC_ASYNC);

    /* Set up incrementing values for scalar members */
    value = of_bsn_generic_async_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_generic_async_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_generic_async_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_generic_async_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_generic_command_create_OF_VERSION_1_4(void)
{
    of_bsn_generic_command_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_generic_command_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 80);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GENERIC_COMMAND);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GENERIC_COMMAND);

    /* Set up incrementing values for scalar members */
    value = of_bsn_generic_command_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_generic_command_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_generic_command_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_generic_command_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_generic_command_reply_create_OF_VERSION_1_4(void)
{
    of_bsn_generic_command_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_generic_command_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GENERIC_COMMAND_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GENERIC_COMMAND_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_generic_command_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_generic_command_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_generic_command_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_generic_command_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_generic_stats_reply_create_OF_VERSION_1_4(void)
{
    of_bsn_generic_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_generic_stats_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GENERIC_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GENERIC_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_generic_stats_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_generic_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_generic_stats_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_generic_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_generic_stats_request_create_OF_VERSION_1_4(void)
{
    of_bsn_generic_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_generic_stats_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 88);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GENERIC_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GENERIC_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_generic_stats_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_generic_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_generic_stats_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_generic_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_gentable_bucket_stats_reply_create_OF_VERSION_1_4(void)
{
    of_bsn_gentable_bucket_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_gentable_bucket_stats_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GENTABLE_BUCKET_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GENTABLE_BUCKET_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_gentable_bucket_stats_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_gentable_bucket_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_gentable_bucket_stats_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_gentable_bucket_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_gentable_bucket_stats_request_create_OF_VERSION_1_4(void)
{
    of_bsn_gentable_bucket_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_gentable_bucket_stats_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 26);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GENTABLE_BUCKET_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GENTABLE_BUCKET_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_gentable_bucket_stats_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_gentable_bucket_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_gentable_bucket_stats_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_gentable_bucket_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_gentable_clear_reply_create_OF_VERSION_1_4(void)
{
    of_bsn_gentable_clear_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_gentable_clear_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 28);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GENTABLE_CLEAR_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GENTABLE_CLEAR_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_gentable_clear_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_gentable_clear_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_gentable_clear_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_gentable_clear_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_gentable_clear_request_create_OF_VERSION_1_4(void)
{
    of_bsn_gentable_clear_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_gentable_clear_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 52);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GENTABLE_CLEAR_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GENTABLE_CLEAR_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_gentable_clear_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_gentable_clear_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_gentable_clear_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_gentable_clear_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_gentable_desc_stats_reply_create_OF_VERSION_1_4(void)
{
    of_bsn_gentable_desc_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_gentable_desc_stats_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GENTABLE_DESC_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GENTABLE_DESC_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_gentable_desc_stats_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_gentable_desc_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_gentable_desc_stats_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_gentable_desc_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_gentable_desc_stats_request_create_OF_VERSION_1_4(void)
{
    of_bsn_gentable_desc_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_gentable_desc_stats_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GENTABLE_DESC_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GENTABLE_DESC_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_gentable_desc_stats_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_gentable_desc_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_gentable_desc_stats_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_gentable_desc_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_gentable_entry_add_create_OF_VERSION_1_4(void)
{
    of_bsn_gentable_entry_add_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_gentable_entry_add_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 36);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GENTABLE_ENTRY_ADD);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GENTABLE_ENTRY_ADD);

    /* Set up incrementing values for scalar members */
    value = of_bsn_gentable_entry_add_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_gentable_entry_add_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_gentable_entry_add_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_gentable_entry_add_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_gentable_entry_delete_create_OF_VERSION_1_4(void)
{
    of_bsn_gentable_entry_delete_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_gentable_entry_delete_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 18);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GENTABLE_ENTRY_DELETE);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GENTABLE_ENTRY_DELETE);

    /* Set up incrementing values for scalar members */
    value = of_bsn_gentable_entry_delete_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_gentable_entry_delete_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_gentable_entry_delete_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_gentable_entry_delete_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_gentable_entry_desc_stats_reply_create_OF_VERSION_1_4(void)
{
    of_bsn_gentable_entry_desc_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_gentable_entry_desc_stats_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GENTABLE_ENTRY_DESC_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GENTABLE_ENTRY_DESC_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_gentable_entry_desc_stats_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_gentable_entry_desc_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_gentable_entry_desc_stats_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_gentable_entry_desc_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_gentable_entry_desc_stats_request_create_OF_VERSION_1_4(void)
{
    of_bsn_gentable_entry_desc_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_gentable_entry_desc_stats_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 60);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GENTABLE_ENTRY_DESC_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GENTABLE_ENTRY_DESC_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_gentable_entry_desc_stats_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_gentable_entry_desc_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_gentable_entry_desc_stats_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_gentable_entry_desc_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_gentable_entry_stats_reply_create_OF_VERSION_1_4(void)
{
    of_bsn_gentable_entry_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_gentable_entry_stats_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GENTABLE_ENTRY_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GENTABLE_ENTRY_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_gentable_entry_stats_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_gentable_entry_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_gentable_entry_stats_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_gentable_entry_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_gentable_entry_stats_request_create_OF_VERSION_1_4(void)
{
    of_bsn_gentable_entry_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_gentable_entry_stats_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 60);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GENTABLE_ENTRY_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GENTABLE_ENTRY_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_gentable_entry_stats_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_gentable_entry_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_gentable_entry_stats_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_gentable_entry_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_gentable_error_create_OF_VERSION_1_4(void)
{
    of_bsn_gentable_error_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_gentable_error_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 276);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GENTABLE_ERROR);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GENTABLE_ERROR);

    /* Set up incrementing values for scalar members */
    value = of_bsn_gentable_error_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_gentable_error_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_gentable_error_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_gentable_error_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_gentable_set_buckets_size_create_OF_VERSION_1_4(void)
{
    of_bsn_gentable_set_buckets_size_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_gentable_set_buckets_size_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GENTABLE_SET_BUCKETS_SIZE);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GENTABLE_SET_BUCKETS_SIZE);

    /* Set up incrementing values for scalar members */
    value = of_bsn_gentable_set_buckets_size_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_gentable_set_buckets_size_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_gentable_set_buckets_size_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_gentable_set_buckets_size_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_gentable_stats_reply_create_OF_VERSION_1_4(void)
{
    of_bsn_gentable_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_gentable_stats_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GENTABLE_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GENTABLE_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_gentable_stats_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_gentable_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_gentable_stats_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_gentable_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_gentable_stats_request_create_OF_VERSION_1_4(void)
{
    of_bsn_gentable_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_gentable_stats_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GENTABLE_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GENTABLE_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_gentable_stats_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_gentable_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_gentable_stats_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_gentable_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_get_interfaces_reply_create_OF_VERSION_1_4(void)
{
    of_bsn_get_interfaces_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_get_interfaces_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_INTERFACES_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GET_INTERFACES_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_get_interfaces_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_get_interfaces_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_get_interfaces_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_get_interfaces_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_get_interfaces_request_create_OF_VERSION_1_4(void)
{
    of_bsn_get_interfaces_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_get_interfaces_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_INTERFACES_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GET_INTERFACES_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_get_interfaces_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_get_interfaces_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_get_interfaces_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_get_interfaces_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_get_mirroring_reply_create_OF_VERSION_1_4(void)
{
    of_bsn_get_mirroring_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_get_mirroring_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_MIRRORING_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GET_MIRRORING_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_get_mirroring_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_get_mirroring_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_get_mirroring_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_get_mirroring_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_get_mirroring_request_create_OF_VERSION_1_4(void)
{
    of_bsn_get_mirroring_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_get_mirroring_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_MIRRORING_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GET_MIRRORING_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_get_mirroring_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_get_mirroring_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_get_mirroring_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_get_mirroring_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_get_switch_pipeline_reply_create_OF_VERSION_1_4(void)
{
    of_bsn_get_switch_pipeline_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_get_switch_pipeline_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 272);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_SWITCH_PIPELINE_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GET_SWITCH_PIPELINE_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_get_switch_pipeline_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_get_switch_pipeline_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_get_switch_pipeline_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_get_switch_pipeline_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_get_switch_pipeline_request_create_OF_VERSION_1_4(void)
{
    of_bsn_get_switch_pipeline_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_get_switch_pipeline_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_GET_SWITCH_PIPELINE_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_GET_SWITCH_PIPELINE_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_get_switch_pipeline_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_get_switch_pipeline_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_get_switch_pipeline_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_get_switch_pipeline_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_image_desc_stats_reply_create_OF_VERSION_1_4(void)
{
    of_bsn_image_desc_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_image_desc_stats_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 536);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_IMAGE_DESC_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_IMAGE_DESC_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_image_desc_stats_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_image_desc_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_image_desc_stats_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_image_desc_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_image_desc_stats_request_create_OF_VERSION_1_4(void)
{
    of_bsn_image_desc_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_image_desc_stats_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_IMAGE_DESC_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_IMAGE_DESC_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_image_desc_stats_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_image_desc_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_image_desc_stats_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_image_desc_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_lacp_convergence_notif_create_OF_VERSION_1_4(void)
{
    of_bsn_lacp_convergence_notif_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_lacp_convergence_notif_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 52);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_LACP_CONVERGENCE_NOTIF);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_LACP_CONVERGENCE_NOTIF);

    /* Set up incrementing values for scalar members */
    value = of_bsn_lacp_convergence_notif_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_lacp_convergence_notif_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_lacp_convergence_notif_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_lacp_convergence_notif_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_lacp_stats_reply_create_OF_VERSION_1_4(void)
{
    of_bsn_lacp_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_lacp_stats_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_LACP_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_LACP_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_lacp_stats_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_lacp_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_lacp_stats_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_lacp_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_lacp_stats_request_create_OF_VERSION_1_4(void)
{
    of_bsn_lacp_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_lacp_stats_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_LACP_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_LACP_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_lacp_stats_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_lacp_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_lacp_stats_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_lacp_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_log_create_OF_VERSION_1_4(void)
{
    of_bsn_log_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_log_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 17);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_LOG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_LOG);

    /* Set up incrementing values for scalar members */
    value = of_bsn_log_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_log_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_log_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_log_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_lua_command_reply_create_OF_VERSION_1_4(void)
{
    of_bsn_lua_command_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_lua_command_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_LUA_COMMAND_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_LUA_COMMAND_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_lua_command_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_lua_command_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_lua_command_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_lua_command_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_lua_command_request_create_OF_VERSION_1_4(void)
{
    of_bsn_lua_command_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_lua_command_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_LUA_COMMAND_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_LUA_COMMAND_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_lua_command_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_lua_command_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_lua_command_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_lua_command_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_lua_notification_create_OF_VERSION_1_4(void)
{
    of_bsn_lua_notification_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_lua_notification_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_LUA_NOTIFICATION);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_LUA_NOTIFICATION);

    /* Set up incrementing values for scalar members */
    value = of_bsn_lua_notification_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_lua_notification_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_lua_notification_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_lua_notification_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_lua_upload_create_OF_VERSION_1_4(void)
{
    of_bsn_lua_upload_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_lua_upload_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 82);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_LUA_UPLOAD);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_LUA_UPLOAD);

    /* Set up incrementing values for scalar members */
    value = of_bsn_lua_upload_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_lua_upload_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_lua_upload_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_lua_upload_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_pdu_rx_reply_create_OF_VERSION_1_4(void)
{
    of_bsn_pdu_rx_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_pdu_rx_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 25);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_RX_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_PDU_RX_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_pdu_rx_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_pdu_rx_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_pdu_rx_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_pdu_rx_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_pdu_rx_request_create_OF_VERSION_1_4(void)
{
    of_bsn_pdu_rx_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_pdu_rx_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 28);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_RX_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_PDU_RX_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_pdu_rx_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_pdu_rx_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_pdu_rx_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_pdu_rx_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_pdu_rx_timeout_create_OF_VERSION_1_4(void)
{
    of_bsn_pdu_rx_timeout_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_pdu_rx_timeout_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 21);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_RX_TIMEOUT);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_PDU_RX_TIMEOUT);

    /* Set up incrementing values for scalar members */
    value = of_bsn_pdu_rx_timeout_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_pdu_rx_timeout_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_pdu_rx_timeout_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_pdu_rx_timeout_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_pdu_tx_reply_create_OF_VERSION_1_4(void)
{
    of_bsn_pdu_tx_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_pdu_tx_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 25);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_TX_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_PDU_TX_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_pdu_tx_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_pdu_tx_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_pdu_tx_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_pdu_tx_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_pdu_tx_request_create_OF_VERSION_1_4(void)
{
    of_bsn_pdu_tx_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_pdu_tx_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 28);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PDU_TX_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_PDU_TX_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_pdu_tx_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_pdu_tx_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_pdu_tx_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_pdu_tx_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_port_counter_stats_reply_create_OF_VERSION_1_4(void)
{
    of_bsn_port_counter_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_port_counter_stats_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PORT_COUNTER_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_PORT_COUNTER_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_port_counter_stats_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_port_counter_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_port_counter_stats_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_port_counter_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_port_counter_stats_request_create_OF_VERSION_1_4(void)
{
    of_bsn_port_counter_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_port_counter_stats_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 28);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_PORT_COUNTER_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_PORT_COUNTER_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_port_counter_stats_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_port_counter_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_port_counter_stats_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_port_counter_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_set_aux_cxns_reply_create_OF_VERSION_1_4(void)
{
    of_bsn_set_aux_cxns_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_set_aux_cxns_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_AUX_CXNS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_SET_AUX_CXNS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_set_aux_cxns_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_set_aux_cxns_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_set_aux_cxns_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_set_aux_cxns_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_set_aux_cxns_request_create_OF_VERSION_1_4(void)
{
    of_bsn_set_aux_cxns_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_set_aux_cxns_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_AUX_CXNS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_SET_AUX_CXNS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_set_aux_cxns_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_set_aux_cxns_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_set_aux_cxns_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_set_aux_cxns_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_set_lacp_reply_create_OF_VERSION_1_4(void)
{
    of_bsn_set_lacp_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_set_lacp_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_LACP_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_SET_LACP_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_set_lacp_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_set_lacp_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_set_lacp_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_set_lacp_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_set_lacp_request_create_OF_VERSION_1_4(void)
{
    of_bsn_set_lacp_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_set_lacp_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 38);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_LACP_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_SET_LACP_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_set_lacp_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_set_lacp_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_set_lacp_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_set_lacp_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_set_mirroring_create_OF_VERSION_1_4(void)
{
    of_bsn_set_mirroring_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_set_mirroring_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_MIRRORING);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_SET_MIRRORING);

    /* Set up incrementing values for scalar members */
    value = of_bsn_set_mirroring_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_set_mirroring_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_set_mirroring_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_set_mirroring_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_set_pktin_suppression_reply_create_OF_VERSION_1_4(void)
{
    of_bsn_set_pktin_suppression_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_set_pktin_suppression_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_PKTIN_SUPPRESSION_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_SET_PKTIN_SUPPRESSION_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_set_pktin_suppression_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_set_pktin_suppression_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_set_pktin_suppression_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_set_pktin_suppression_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_set_pktin_suppression_request_create_OF_VERSION_1_4(void)
{
    of_bsn_set_pktin_suppression_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_set_pktin_suppression_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_PKTIN_SUPPRESSION_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_SET_PKTIN_SUPPRESSION_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_set_pktin_suppression_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_set_pktin_suppression_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_set_pktin_suppression_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_set_pktin_suppression_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_set_switch_pipeline_reply_create_OF_VERSION_1_4(void)
{
    of_bsn_set_switch_pipeline_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_set_switch_pipeline_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_SWITCH_PIPELINE_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_SET_SWITCH_PIPELINE_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_set_switch_pipeline_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_set_switch_pipeline_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_set_switch_pipeline_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_set_switch_pipeline_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_set_switch_pipeline_request_create_OF_VERSION_1_4(void)
{
    of_bsn_set_switch_pipeline_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_set_switch_pipeline_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 272);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SET_SWITCH_PIPELINE_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_SET_SWITCH_PIPELINE_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_set_switch_pipeline_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_set_switch_pipeline_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_set_switch_pipeline_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_set_switch_pipeline_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_switch_pipeline_stats_reply_create_OF_VERSION_1_4(void)
{
    of_bsn_switch_pipeline_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_switch_pipeline_stats_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SWITCH_PIPELINE_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_SWITCH_PIPELINE_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_switch_pipeline_stats_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_switch_pipeline_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_switch_pipeline_stats_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_switch_pipeline_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_switch_pipeline_stats_request_create_OF_VERSION_1_4(void)
{
    of_bsn_switch_pipeline_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_switch_pipeline_stats_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_SWITCH_PIPELINE_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_SWITCH_PIPELINE_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_switch_pipeline_stats_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_switch_pipeline_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_switch_pipeline_stats_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_switch_pipeline_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_table_checksum_stats_reply_create_OF_VERSION_1_4(void)
{
    of_bsn_table_checksum_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_table_checksum_stats_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_TABLE_CHECKSUM_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_table_checksum_stats_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_table_checksum_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_table_checksum_stats_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_table_checksum_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_table_checksum_stats_request_create_OF_VERSION_1_4(void)
{
    of_bsn_table_checksum_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_table_checksum_stats_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_TABLE_CHECKSUM_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_table_checksum_stats_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_table_checksum_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_table_checksum_stats_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_table_checksum_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_table_set_buckets_size_create_OF_VERSION_1_4(void)
{
    of_bsn_table_set_buckets_size_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_table_set_buckets_size_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_TABLE_SET_BUCKETS_SIZE);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_TABLE_SET_BUCKETS_SIZE);

    /* Set up incrementing values for scalar members */
    value = of_bsn_table_set_buckets_size_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_table_set_buckets_size_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_table_set_buckets_size_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_table_set_buckets_size_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_takeover_create_OF_VERSION_1_4(void)
{
    of_bsn_takeover_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_takeover_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_TAKEOVER);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_TAKEOVER);

    /* Set up incrementing values for scalar members */
    value = of_bsn_takeover_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_takeover_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_takeover_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_takeover_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_time_reply_create_OF_VERSION_1_4(void)
{
    of_bsn_time_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_time_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_TIME_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_TIME_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_time_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_time_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_time_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_time_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_time_request_create_OF_VERSION_1_4(void)
{
    of_bsn_time_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_time_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_TIME_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_TIME_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_time_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_time_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_time_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_time_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_virtual_port_create_reply_create_OF_VERSION_1_4(void)
{
    of_bsn_virtual_port_create_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_virtual_port_create_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VIRTUAL_PORT_CREATE_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_VIRTUAL_PORT_CREATE_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_virtual_port_create_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_virtual_port_create_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_virtual_port_create_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_virtual_port_create_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_virtual_port_create_request_create_OF_VERSION_1_4(void)
{
    of_bsn_virtual_port_create_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_virtual_port_create_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VIRTUAL_PORT_CREATE_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_VIRTUAL_PORT_CREATE_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_virtual_port_create_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_virtual_port_create_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_virtual_port_create_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_virtual_port_create_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_virtual_port_remove_reply_create_OF_VERSION_1_4(void)
{
    of_bsn_virtual_port_remove_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_virtual_port_remove_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VIRTUAL_PORT_REMOVE_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_VIRTUAL_PORT_REMOVE_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_virtual_port_remove_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_virtual_port_remove_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_virtual_port_remove_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_virtual_port_remove_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_virtual_port_remove_request_create_OF_VERSION_1_4(void)
{
    of_bsn_virtual_port_remove_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_virtual_port_remove_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 20);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VIRTUAL_PORT_REMOVE_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_VIRTUAL_PORT_REMOVE_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_virtual_port_remove_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_virtual_port_remove_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_virtual_port_remove_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_virtual_port_remove_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_vlan_counter_clear_create_OF_VERSION_1_4(void)
{
    of_bsn_vlan_counter_clear_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_vlan_counter_clear_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 18);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VLAN_COUNTER_CLEAR);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_VLAN_COUNTER_CLEAR);

    /* Set up incrementing values for scalar members */
    value = of_bsn_vlan_counter_clear_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_vlan_counter_clear_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_vlan_counter_clear_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_vlan_counter_clear_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_vlan_counter_stats_reply_create_OF_VERSION_1_4(void)
{
    of_bsn_vlan_counter_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_vlan_counter_stats_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VLAN_COUNTER_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_VLAN_COUNTER_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_vlan_counter_stats_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_vlan_counter_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_vlan_counter_stats_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_vlan_counter_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_vlan_counter_stats_request_create_OF_VERSION_1_4(void)
{
    of_bsn_vlan_counter_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_vlan_counter_stats_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 26);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VLAN_COUNTER_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_VLAN_COUNTER_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_vlan_counter_stats_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_vlan_counter_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_vlan_counter_stats_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_vlan_counter_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_vrf_counter_stats_reply_create_OF_VERSION_1_4(void)
{
    of_bsn_vrf_counter_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_vrf_counter_stats_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VRF_COUNTER_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_VRF_COUNTER_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_bsn_vrf_counter_stats_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_vrf_counter_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_vrf_counter_stats_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_vrf_counter_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_bsn_vrf_counter_stats_request_create_OF_VERSION_1_4(void)
{
    of_bsn_vrf_counter_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bsn_vrf_counter_stats_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 28);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BSN_VRF_COUNTER_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BSN_VRF_COUNTER_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_bsn_vrf_counter_stats_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bsn_vrf_counter_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bsn_vrf_counter_stats_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bsn_vrf_counter_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_bundle_add_msg_create_OF_VERSION_1_4(void)
{
    of_bundle_add_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bundle_add_msg_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BUNDLE_ADD_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BUNDLE_ADD_MSG);

    /* Set up incrementing values for scalar members */
    value = of_bundle_add_msg_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bundle_add_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bundle_add_msg_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bundle_add_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_bundle_ctrl_msg_create_OF_VERSION_1_4(void)
{
    of_bundle_ctrl_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bundle_ctrl_msg_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BUNDLE_CTRL_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BUNDLE_CTRL_MSG);

    /* Set up incrementing values for scalar members */
    value = of_bundle_ctrl_msg_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bundle_ctrl_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bundle_ctrl_msg_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bundle_ctrl_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_bundle_failed_error_msg_create_OF_VERSION_1_4(void)
{
    of_bundle_failed_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_bundle_failed_error_msg_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_BUNDLE_FAILED_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_BUNDLE_FAILED_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_bundle_failed_error_msg_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_bundle_failed_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_bundle_failed_error_msg_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_bundle_failed_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_desc_stats_reply_create_OF_VERSION_1_4(void)
{
    of_desc_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_desc_stats_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 1072);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_DESC_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_DESC_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_desc_stats_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_desc_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_desc_stats_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_desc_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_desc_stats_request_create_OF_VERSION_1_4(void)
{
    of_desc_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_desc_stats_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_DESC_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_DESC_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_desc_stats_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_desc_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_desc_stats_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_desc_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_echo_reply_create_OF_VERSION_1_4(void)
{
    of_echo_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_echo_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ECHO_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_ECHO_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_echo_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_echo_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_echo_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_echo_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_echo_request_create_OF_VERSION_1_4(void)
{
    of_echo_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_echo_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ECHO_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_ECHO_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_echo_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_echo_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_echo_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_echo_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_features_reply_create_OF_VERSION_1_4(void)
{
    of_features_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_features_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FEATURES_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FEATURES_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_features_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_features_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_features_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_features_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_features_request_create_OF_VERSION_1_4(void)
{
    of_features_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_features_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FEATURES_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FEATURES_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_features_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_features_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_features_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_features_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_add_create_OF_VERSION_1_4(void)
{
    of_flow_add_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_add_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_ADD);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_ADD);

    /* Set up incrementing values for scalar members */
    value = of_flow_add_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_add_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_add_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_add_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_delete_create_OF_VERSION_1_4(void)
{
    of_flow_delete_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_delete_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_DELETE);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_DELETE);

    /* Set up incrementing values for scalar members */
    value = of_flow_delete_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_delete_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_delete_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_delete_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_delete_strict_create_OF_VERSION_1_4(void)
{
    of_flow_delete_strict_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_delete_strict_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_DELETE_STRICT);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_DELETE_STRICT);

    /* Set up incrementing values for scalar members */
    value = of_flow_delete_strict_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_delete_strict_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_delete_strict_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_delete_strict_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_mod_failed_error_msg_create_OF_VERSION_1_4(void)
{
    of_flow_mod_failed_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_mod_failed_error_msg_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_MOD_FAILED_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_MOD_FAILED_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_flow_mod_failed_error_msg_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_mod_failed_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_mod_failed_error_msg_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_mod_failed_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_modify_create_OF_VERSION_1_4(void)
{
    of_flow_modify_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_modify_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_MODIFY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_MODIFY);

    /* Set up incrementing values for scalar members */
    value = of_flow_modify_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_modify_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_modify_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_modify_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_modify_strict_create_OF_VERSION_1_4(void)
{
    of_flow_modify_strict_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_modify_strict_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_MODIFY_STRICT);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_MODIFY_STRICT);

    /* Set up incrementing values for scalar members */
    value = of_flow_modify_strict_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_modify_strict_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_modify_strict_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_modify_strict_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_monitor_failed_error_msg_create_OF_VERSION_1_4(void)
{
    of_flow_monitor_failed_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_monitor_failed_error_msg_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_MONITOR_FAILED_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_MONITOR_FAILED_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_flow_monitor_failed_error_msg_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_monitor_failed_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_monitor_failed_error_msg_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_monitor_failed_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_removed_create_OF_VERSION_1_4(void)
{
    of_flow_removed_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_removed_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_REMOVED);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_REMOVED);

    /* Set up incrementing values for scalar members */
    value = of_flow_removed_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_removed_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_removed_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_removed_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_stats_reply_create_OF_VERSION_1_4(void)
{
    of_flow_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_stats_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_flow_stats_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_stats_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_flow_stats_request_create_OF_VERSION_1_4(void)
{
    of_flow_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_flow_stats_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_FLOW_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_FLOW_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_flow_stats_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_flow_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_flow_stats_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_flow_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_get_config_reply_create_OF_VERSION_1_4(void)
{
    of_get_config_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_get_config_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GET_CONFIG_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GET_CONFIG_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_get_config_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_get_config_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_get_config_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_get_config_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_get_config_request_create_OF_VERSION_1_4(void)
{
    of_get_config_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_get_config_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GET_CONFIG_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GET_CONFIG_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_get_config_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_get_config_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_get_config_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_get_config_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_group_add_create_OF_VERSION_1_4(void)
{
    of_group_add_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_group_add_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_ADD);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GROUP_ADD);

    /* Set up incrementing values for scalar members */
    value = of_group_add_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_group_add_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_group_add_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_group_add_delete(obj);

    return TEST_PASS;
}

static int
test_of_group_delete_create_OF_VERSION_1_4(void)
{
    of_group_delete_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_group_delete_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_DELETE);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GROUP_DELETE);

    /* Set up incrementing values for scalar members */
    value = of_group_delete_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_group_delete_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_group_delete_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_group_delete_delete(obj);

    return TEST_PASS;
}

static int
test_of_group_desc_stats_reply_create_OF_VERSION_1_4(void)
{
    of_group_desc_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_group_desc_stats_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_DESC_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GROUP_DESC_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_group_desc_stats_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_group_desc_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_group_desc_stats_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_group_desc_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_group_desc_stats_request_create_OF_VERSION_1_4(void)
{
    of_group_desc_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_group_desc_stats_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_DESC_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GROUP_DESC_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_group_desc_stats_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_group_desc_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_group_desc_stats_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_group_desc_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_group_features_stats_reply_create_OF_VERSION_1_4(void)
{
    of_group_features_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_group_features_stats_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GROUP_FEATURES_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_group_features_stats_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_group_features_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_group_features_stats_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_group_features_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_group_features_stats_request_create_OF_VERSION_1_4(void)
{
    of_group_features_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_group_features_stats_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GROUP_FEATURES_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_group_features_stats_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_group_features_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_group_features_stats_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_group_features_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_group_mod_failed_error_msg_create_OF_VERSION_1_4(void)
{
    of_group_mod_failed_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_group_mod_failed_error_msg_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_MOD_FAILED_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GROUP_MOD_FAILED_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_group_mod_failed_error_msg_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_group_mod_failed_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_group_mod_failed_error_msg_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_group_mod_failed_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_group_modify_create_OF_VERSION_1_4(void)
{
    of_group_modify_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_group_modify_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_MODIFY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GROUP_MODIFY);

    /* Set up incrementing values for scalar members */
    value = of_group_modify_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_group_modify_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_group_modify_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_group_modify_delete(obj);

    return TEST_PASS;
}

static int
test_of_group_stats_reply_create_OF_VERSION_1_4(void)
{
    of_group_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_group_stats_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GROUP_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_group_stats_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_group_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_group_stats_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_group_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_group_stats_request_create_OF_VERSION_1_4(void)
{
    of_group_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_group_stats_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_GROUP_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_GROUP_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_group_stats_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_group_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_group_stats_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_group_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_hello_create_OF_VERSION_1_4(void)
{
    of_hello_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_hello_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 8);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_HELLO);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_HELLO);

    /* Set up incrementing values for scalar members */
    value = of_hello_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_hello_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_hello_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_hello_delete(obj);

    return TEST_PASS;
}

static int
test_of_hello_failed_error_msg_create_OF_VERSION_1_4(void)
{
    of_hello_failed_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_hello_failed_error_msg_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_HELLO_FAILED_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_HELLO_FAILED_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_hello_failed_error_msg_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_hello_failed_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_hello_failed_error_msg_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_hello_failed_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_meter_config_stats_reply_create_OF_VERSION_1_4(void)
{
    of_meter_config_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_meter_config_stats_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_METER_CONFIG_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_METER_CONFIG_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_meter_config_stats_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_meter_config_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_meter_config_stats_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_meter_config_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_meter_config_stats_request_create_OF_VERSION_1_4(void)
{
    of_meter_config_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_meter_config_stats_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_METER_CONFIG_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_METER_CONFIG_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_meter_config_stats_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_meter_config_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_meter_config_stats_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_meter_config_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_meter_features_stats_reply_create_OF_VERSION_1_4(void)
{
    of_meter_features_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_meter_features_stats_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_METER_FEATURES_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_METER_FEATURES_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_meter_features_stats_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_meter_features_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_meter_features_stats_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_meter_features_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_meter_features_stats_request_create_OF_VERSION_1_4(void)
{
    of_meter_features_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_meter_features_stats_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_METER_FEATURES_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_METER_FEATURES_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_meter_features_stats_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_meter_features_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_meter_features_stats_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_meter_features_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_meter_mod_create_OF_VERSION_1_4(void)
{
    of_meter_mod_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_meter_mod_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_METER_MOD);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_METER_MOD);

    /* Set up incrementing values for scalar members */
    value = of_meter_mod_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_meter_mod_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_meter_mod_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_meter_mod_delete(obj);

    return TEST_PASS;
}

static int
test_of_meter_mod_failed_error_msg_create_OF_VERSION_1_4(void)
{
    of_meter_mod_failed_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_meter_mod_failed_error_msg_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_METER_MOD_FAILED_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_METER_MOD_FAILED_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_meter_mod_failed_error_msg_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_meter_mod_failed_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_meter_mod_failed_error_msg_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_meter_mod_failed_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_meter_stats_reply_create_OF_VERSION_1_4(void)
{
    of_meter_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_meter_stats_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_METER_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_METER_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_meter_stats_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_meter_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_meter_stats_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_meter_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_meter_stats_request_create_OF_VERSION_1_4(void)
{
    of_meter_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_meter_stats_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_METER_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_METER_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_meter_stats_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_meter_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_meter_stats_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_meter_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_packet_in_create_OF_VERSION_1_4(void)
{
    of_packet_in_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_packet_in_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 34);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PACKET_IN);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_PACKET_IN);

    /* Set up incrementing values for scalar members */
    value = of_packet_in_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_packet_in_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_packet_in_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_packet_in_delete(obj);

    return TEST_PASS;
}

static int
test_of_packet_out_create_OF_VERSION_1_4(void)
{
    of_packet_out_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_packet_out_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PACKET_OUT);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_PACKET_OUT);

    /* Set up incrementing values for scalar members */
    value = of_packet_out_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_packet_out_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_packet_out_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_packet_out_delete(obj);

    return TEST_PASS;
}

static int
test_of_port_desc_stats_reply_create_OF_VERSION_1_4(void)
{
    of_port_desc_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_port_desc_stats_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_DESC_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_PORT_DESC_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_port_desc_stats_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_port_desc_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_port_desc_stats_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_port_desc_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_port_desc_stats_request_create_OF_VERSION_1_4(void)
{
    of_port_desc_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_port_desc_stats_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_DESC_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_PORT_DESC_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_port_desc_stats_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_port_desc_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_port_desc_stats_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_port_desc_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_port_mod_create_OF_VERSION_1_4(void)
{
    of_port_mod_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_port_mod_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 32);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_MOD);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_PORT_MOD);

    /* Set up incrementing values for scalar members */
    value = of_port_mod_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_port_mod_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_port_mod_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_port_mod_delete(obj);

    return TEST_PASS;
}

static int
test_of_port_mod_failed_error_msg_create_OF_VERSION_1_4(void)
{
    of_port_mod_failed_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_port_mod_failed_error_msg_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_MOD_FAILED_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_PORT_MOD_FAILED_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_port_mod_failed_error_msg_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_port_mod_failed_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_port_mod_failed_error_msg_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_port_mod_failed_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_port_stats_reply_create_OF_VERSION_1_4(void)
{
    of_port_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_port_stats_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_PORT_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_port_stats_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_port_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_port_stats_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_port_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_port_stats_request_create_OF_VERSION_1_4(void)
{
    of_port_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_port_stats_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_PORT_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_port_stats_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_port_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_port_stats_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_port_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_port_status_create_OF_VERSION_1_4(void)
{
    of_port_status_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_port_status_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 56);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_PORT_STATUS);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_PORT_STATUS);

    /* Set up incrementing values for scalar members */
    value = of_port_status_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_port_status_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_port_status_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_port_status_delete(obj);

    return TEST_PASS;
}

static int
test_of_queue_desc_stats_reply_create_OF_VERSION_1_4(void)
{
    of_queue_desc_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_queue_desc_stats_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_DESC_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_QUEUE_DESC_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_queue_desc_stats_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_queue_desc_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_queue_desc_stats_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_queue_desc_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_queue_desc_stats_request_create_OF_VERSION_1_4(void)
{
    of_queue_desc_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_queue_desc_stats_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_DESC_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_QUEUE_DESC_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_queue_desc_stats_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_queue_desc_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_queue_desc_stats_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_queue_desc_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_queue_op_failed_error_msg_create_OF_VERSION_1_4(void)
{
    of_queue_op_failed_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_queue_op_failed_error_msg_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_OP_FAILED_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_QUEUE_OP_FAILED_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_queue_op_failed_error_msg_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_queue_op_failed_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_queue_op_failed_error_msg_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_queue_op_failed_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_queue_stats_reply_create_OF_VERSION_1_4(void)
{
    of_queue_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_queue_stats_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_QUEUE_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_queue_stats_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_queue_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_queue_stats_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_queue_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_queue_stats_request_create_OF_VERSION_1_4(void)
{
    of_queue_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_queue_stats_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_QUEUE_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_QUEUE_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_queue_stats_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_queue_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_queue_stats_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_queue_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_requestforward_create_OF_VERSION_1_4(void)
{
    of_requestforward_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_requestforward_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_REQUESTFORWARD);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_REQUESTFORWARD);

    /* Set up incrementing values for scalar members */
    value = of_requestforward_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_requestforward_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_requestforward_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_requestforward_delete(obj);

    return TEST_PASS;
}

static int
test_of_role_reply_create_OF_VERSION_1_4(void)
{
    of_role_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_role_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ROLE_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_ROLE_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_role_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_role_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_role_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_role_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_role_request_create_OF_VERSION_1_4(void)
{
    of_role_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_role_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ROLE_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_ROLE_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_role_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_role_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_role_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_role_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_role_request_failed_error_msg_create_OF_VERSION_1_4(void)
{
    of_role_request_failed_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_role_request_failed_error_msg_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ROLE_REQUEST_FAILED_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_ROLE_REQUEST_FAILED_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_role_request_failed_error_msg_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_role_request_failed_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_role_request_failed_error_msg_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_role_request_failed_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_role_status_create_OF_VERSION_1_4(void)
{
    of_role_status_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_role_status_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 24);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_ROLE_STATUS);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_ROLE_STATUS);

    /* Set up incrementing values for scalar members */
    value = of_role_status_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_role_status_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_role_status_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_role_status_delete(obj);

    return TEST_PASS;
}

static int
test_of_set_config_create_OF_VERSION_1_4(void)
{
    of_set_config_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_set_config_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_SET_CONFIG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_SET_CONFIG);

    /* Set up incrementing values for scalar members */
    value = of_set_config_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_set_config_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_set_config_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_set_config_delete(obj);

    return TEST_PASS;
}

static int
test_of_switch_config_failed_error_msg_create_OF_VERSION_1_4(void)
{
    of_switch_config_failed_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_switch_config_failed_error_msg_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_SWITCH_CONFIG_FAILED_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_SWITCH_CONFIG_FAILED_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_switch_config_failed_error_msg_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_switch_config_failed_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_switch_config_failed_error_msg_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_switch_config_failed_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_table_desc_stats_reply_create_OF_VERSION_1_4(void)
{
    of_table_desc_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_table_desc_stats_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_DESC_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_TABLE_DESC_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_table_desc_stats_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_table_desc_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_table_desc_stats_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_table_desc_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_table_desc_stats_request_create_OF_VERSION_1_4(void)
{
    of_table_desc_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_table_desc_stats_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_DESC_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_TABLE_DESC_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_table_desc_stats_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_table_desc_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_table_desc_stats_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_table_desc_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_table_features_failed_error_msg_create_OF_VERSION_1_4(void)
{
    of_table_features_failed_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_table_features_failed_error_msg_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_FEATURES_FAILED_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_TABLE_FEATURES_FAILED_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_table_features_failed_error_msg_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_table_features_failed_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_table_features_failed_error_msg_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_table_features_failed_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_table_features_stats_reply_create_OF_VERSION_1_4(void)
{
    of_table_features_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_table_features_stats_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_FEATURES_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_TABLE_FEATURES_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_table_features_stats_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_table_features_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_table_features_stats_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_table_features_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_table_features_stats_request_create_OF_VERSION_1_4(void)
{
    of_table_features_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_table_features_stats_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_FEATURES_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_TABLE_FEATURES_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_table_features_stats_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_table_features_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_table_features_stats_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_table_features_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_table_mod_create_OF_VERSION_1_4(void)
{
    of_table_mod_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_table_mod_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_MOD);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_TABLE_MOD);

    /* Set up incrementing values for scalar members */
    value = of_table_mod_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_table_mod_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_table_mod_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_table_mod_delete(obj);

    return TEST_PASS;
}

static int
test_of_table_mod_failed_error_msg_create_OF_VERSION_1_4(void)
{
    of_table_mod_failed_error_msg_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_table_mod_failed_error_msg_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 12);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_MOD_FAILED_ERROR_MSG);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_TABLE_MOD_FAILED_ERROR_MSG);

    /* Set up incrementing values for scalar members */
    value = of_table_mod_failed_error_msg_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_table_mod_failed_error_msg_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_table_mod_failed_error_msg_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_table_mod_failed_error_msg_delete(obj);

    return TEST_PASS;
}

static int
test_of_table_stats_reply_create_OF_VERSION_1_4(void)
{
    of_table_stats_reply_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_table_stats_reply_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_STATS_REPLY);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_TABLE_STATS_REPLY);

    /* Set up incrementing values for scalar members */
    value = of_table_stats_reply_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_table_stats_reply_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_table_stats_reply_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_table_stats_reply_delete(obj);

    return TEST_PASS;
}

static int
test_of_table_stats_request_create_OF_VERSION_1_4(void)
{
    of_table_stats_request_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_table_stats_request_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 16);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_STATS_REQUEST);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_TABLE_STATS_REQUEST);

    /* Set up incrementing values for scalar members */
    value = of_table_stats_request_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_table_stats_request_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_table_stats_request_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_table_stats_request_delete(obj);

    return TEST_PASS;
}

static int
test_of_table_status_create_OF_VERSION_1_4(void)
{
    of_table_status_t *obj;
    uint8_t *msg_buf;
    int value;
    of_object_id_t object_id;
    int len;

    obj = of_table_status_new(OF_VERSION_1_4);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->version == OF_VERSION_1_4);
    TEST_ASSERT(obj->length == 28);
    TEST_ASSERT(obj->parent == NULL);
    TEST_ASSERT(obj->object_id == OF_TABLE_STATUS);

    of_header_wire_object_id_get(obj, &object_id);
    TEST_ASSERT(object_id == OF_TABLE_STATUS);

    /* Set up incrementing values for scalar members */
    value = of_table_status_OF_VERSION_1_4_populate_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    len = obj->length;

    /* Grab the underlying buffer from the message */
    of_object_wire_buffer_steal((of_object_t *)obj, &msg_buf);
    TEST_ASSERT(msg_buf != NULL);
    of_table_status_delete(obj);
    obj = of_object_new_from_message(OF_BUFFER_TO_MESSAGE(msg_buf), len);

    TEST_ASSERT(obj != NULL);

    /* @fixme Set up all message objects (recursively?) */

    value = of_table_status_OF_VERSION_1_4_check_scalars(obj, 1);
    TEST_ASSERT(value != 0);

    of_table_status_delete(obj);

    return TEST_PASS;
}

int
run_message_tests(void)
{
    RUN_TEST(of_aggregate_stats_reply_create_OF_VERSION_1_0);
    RUN_TEST(of_aggregate_stats_request_create_OF_VERSION_1_0);
    RUN_TEST(of_bad_action_error_msg_create_OF_VERSION_1_0);
    RUN_TEST(of_bad_request_error_msg_create_OF_VERSION_1_0);
    RUN_TEST(of_barrier_reply_create_OF_VERSION_1_0);
    RUN_TEST(of_barrier_request_create_OF_VERSION_1_0);
    RUN_TEST(of_bsn_bw_clear_data_reply_create_OF_VERSION_1_0);
    RUN_TEST(of_bsn_bw_clear_data_request_create_OF_VERSION_1_0);
    RUN_TEST(of_bsn_bw_enable_get_reply_create_OF_VERSION_1_0);
    RUN_TEST(of_bsn_bw_enable_get_request_create_OF_VERSION_1_0);
    RUN_TEST(of_bsn_bw_enable_set_reply_create_OF_VERSION_1_0);
    RUN_TEST(of_bsn_bw_enable_set_request_create_OF_VERSION_1_0);
    RUN_TEST(of_bsn_get_interfaces_reply_create_OF_VERSION_1_0);
    RUN_TEST(of_bsn_get_interfaces_request_create_OF_VERSION_1_0);
    RUN_TEST(of_bsn_get_ip_mask_reply_create_OF_VERSION_1_0);
    RUN_TEST(of_bsn_get_ip_mask_request_create_OF_VERSION_1_0);
    RUN_TEST(of_bsn_get_l2_table_reply_create_OF_VERSION_1_0);
    RUN_TEST(of_bsn_get_l2_table_request_create_OF_VERSION_1_0);
    RUN_TEST(of_bsn_get_mirroring_reply_create_OF_VERSION_1_0);
    RUN_TEST(of_bsn_get_mirroring_request_create_OF_VERSION_1_0);
    RUN_TEST(of_bsn_hybrid_get_reply_create_OF_VERSION_1_0);
    RUN_TEST(of_bsn_hybrid_get_request_create_OF_VERSION_1_0);
    RUN_TEST(of_bsn_pdu_rx_reply_create_OF_VERSION_1_0);
    RUN_TEST(of_bsn_pdu_rx_request_create_OF_VERSION_1_0);
    RUN_TEST(of_bsn_pdu_rx_timeout_create_OF_VERSION_1_0);
    RUN_TEST(of_bsn_pdu_tx_reply_create_OF_VERSION_1_0);
    RUN_TEST(of_bsn_pdu_tx_request_create_OF_VERSION_1_0);
    RUN_TEST(of_bsn_set_ip_mask_create_OF_VERSION_1_0);
    RUN_TEST(of_bsn_set_l2_table_reply_create_OF_VERSION_1_0);
    RUN_TEST(of_bsn_set_l2_table_request_create_OF_VERSION_1_0);
    RUN_TEST(of_bsn_set_mirroring_create_OF_VERSION_1_0);
    RUN_TEST(of_bsn_set_pktin_suppression_reply_create_OF_VERSION_1_0);
    RUN_TEST(of_bsn_set_pktin_suppression_request_create_OF_VERSION_1_0);
    RUN_TEST(of_bsn_shell_command_create_OF_VERSION_1_0);
    RUN_TEST(of_bsn_shell_output_create_OF_VERSION_1_0);
    RUN_TEST(of_bsn_shell_status_create_OF_VERSION_1_0);
    RUN_TEST(of_bsn_virtual_port_create_reply_create_OF_VERSION_1_0);
    RUN_TEST(of_bsn_virtual_port_create_request_create_OF_VERSION_1_0);
    RUN_TEST(of_bsn_virtual_port_remove_reply_create_OF_VERSION_1_0);
    RUN_TEST(of_bsn_virtual_port_remove_request_create_OF_VERSION_1_0);
    RUN_TEST(of_desc_stats_reply_create_OF_VERSION_1_0);
    RUN_TEST(of_desc_stats_request_create_OF_VERSION_1_0);
    RUN_TEST(of_echo_reply_create_OF_VERSION_1_0);
    RUN_TEST(of_echo_request_create_OF_VERSION_1_0);
    RUN_TEST(of_features_reply_create_OF_VERSION_1_0);
    RUN_TEST(of_features_request_create_OF_VERSION_1_0);
    RUN_TEST(of_flow_add_create_OF_VERSION_1_0);
    RUN_TEST(of_flow_delete_create_OF_VERSION_1_0);
    RUN_TEST(of_flow_delete_strict_create_OF_VERSION_1_0);
    RUN_TEST(of_flow_mod_failed_error_msg_create_OF_VERSION_1_0);
    RUN_TEST(of_flow_modify_create_OF_VERSION_1_0);
    RUN_TEST(of_flow_modify_strict_create_OF_VERSION_1_0);
    RUN_TEST(of_flow_removed_create_OF_VERSION_1_0);
    RUN_TEST(of_flow_stats_reply_create_OF_VERSION_1_0);
    RUN_TEST(of_flow_stats_request_create_OF_VERSION_1_0);
    RUN_TEST(of_get_config_reply_create_OF_VERSION_1_0);
    RUN_TEST(of_get_config_request_create_OF_VERSION_1_0);
    RUN_TEST(of_hello_create_OF_VERSION_1_0);
    RUN_TEST(of_hello_failed_error_msg_create_OF_VERSION_1_0);
    RUN_TEST(of_nicira_controller_role_reply_create_OF_VERSION_1_0);
    RUN_TEST(of_nicira_controller_role_request_create_OF_VERSION_1_0);
    RUN_TEST(of_packet_in_create_OF_VERSION_1_0);
    RUN_TEST(of_packet_out_create_OF_VERSION_1_0);
    RUN_TEST(of_port_mod_create_OF_VERSION_1_0);
    RUN_TEST(of_port_mod_failed_error_msg_create_OF_VERSION_1_0);
    RUN_TEST(of_port_stats_reply_create_OF_VERSION_1_0);
    RUN_TEST(of_port_stats_request_create_OF_VERSION_1_0);
    RUN_TEST(of_port_status_create_OF_VERSION_1_0);
    RUN_TEST(of_queue_get_config_reply_create_OF_VERSION_1_0);
    RUN_TEST(of_queue_get_config_request_create_OF_VERSION_1_0);
    RUN_TEST(of_queue_op_failed_error_msg_create_OF_VERSION_1_0);
    RUN_TEST(of_queue_stats_reply_create_OF_VERSION_1_0);
    RUN_TEST(of_queue_stats_request_create_OF_VERSION_1_0);
    RUN_TEST(of_set_config_create_OF_VERSION_1_0);
    RUN_TEST(of_table_mod_create_OF_VERSION_1_0);
    RUN_TEST(of_table_stats_reply_create_OF_VERSION_1_0);
    RUN_TEST(of_table_stats_request_create_OF_VERSION_1_0);
    RUN_TEST(of_aggregate_stats_reply_create_OF_VERSION_1_1);
    RUN_TEST(of_aggregate_stats_request_create_OF_VERSION_1_1);
    RUN_TEST(of_bad_action_error_msg_create_OF_VERSION_1_1);
    RUN_TEST(of_bad_instruction_error_msg_create_OF_VERSION_1_1);
    RUN_TEST(of_bad_match_error_msg_create_OF_VERSION_1_1);
    RUN_TEST(of_bad_request_error_msg_create_OF_VERSION_1_1);
    RUN_TEST(of_barrier_reply_create_OF_VERSION_1_1);
    RUN_TEST(of_barrier_request_create_OF_VERSION_1_1);
    RUN_TEST(of_bsn_bw_clear_data_reply_create_OF_VERSION_1_1);
    RUN_TEST(of_bsn_bw_clear_data_request_create_OF_VERSION_1_1);
    RUN_TEST(of_bsn_bw_enable_get_reply_create_OF_VERSION_1_1);
    RUN_TEST(of_bsn_bw_enable_get_request_create_OF_VERSION_1_1);
    RUN_TEST(of_bsn_bw_enable_set_reply_create_OF_VERSION_1_1);
    RUN_TEST(of_bsn_bw_enable_set_request_create_OF_VERSION_1_1);
    RUN_TEST(of_bsn_get_interfaces_reply_create_OF_VERSION_1_1);
    RUN_TEST(of_bsn_get_interfaces_request_create_OF_VERSION_1_1);
    RUN_TEST(of_bsn_get_mirroring_reply_create_OF_VERSION_1_1);
    RUN_TEST(of_bsn_get_mirroring_request_create_OF_VERSION_1_1);
    RUN_TEST(of_bsn_pdu_rx_reply_create_OF_VERSION_1_1);
    RUN_TEST(of_bsn_pdu_rx_request_create_OF_VERSION_1_1);
    RUN_TEST(of_bsn_pdu_rx_timeout_create_OF_VERSION_1_1);
    RUN_TEST(of_bsn_pdu_tx_reply_create_OF_VERSION_1_1);
    RUN_TEST(of_bsn_pdu_tx_request_create_OF_VERSION_1_1);
    RUN_TEST(of_bsn_set_mirroring_create_OF_VERSION_1_1);
    RUN_TEST(of_bsn_set_pktin_suppression_reply_create_OF_VERSION_1_1);
    RUN_TEST(of_bsn_set_pktin_suppression_request_create_OF_VERSION_1_1);
    RUN_TEST(of_bsn_virtual_port_create_reply_create_OF_VERSION_1_1);
    RUN_TEST(of_bsn_virtual_port_create_request_create_OF_VERSION_1_1);
    RUN_TEST(of_bsn_virtual_port_remove_reply_create_OF_VERSION_1_1);
    RUN_TEST(of_bsn_virtual_port_remove_request_create_OF_VERSION_1_1);
    RUN_TEST(of_desc_stats_reply_create_OF_VERSION_1_1);
    RUN_TEST(of_desc_stats_request_create_OF_VERSION_1_1);
    RUN_TEST(of_echo_reply_create_OF_VERSION_1_1);
    RUN_TEST(of_echo_request_create_OF_VERSION_1_1);
    RUN_TEST(of_features_reply_create_OF_VERSION_1_1);
    RUN_TEST(of_features_request_create_OF_VERSION_1_1);
    RUN_TEST(of_flow_add_create_OF_VERSION_1_1);
    RUN_TEST(of_flow_delete_create_OF_VERSION_1_1);
    RUN_TEST(of_flow_delete_strict_create_OF_VERSION_1_1);
    RUN_TEST(of_flow_mod_failed_error_msg_create_OF_VERSION_1_1);
    RUN_TEST(of_flow_modify_create_OF_VERSION_1_1);
    RUN_TEST(of_flow_modify_strict_create_OF_VERSION_1_1);
    RUN_TEST(of_flow_removed_create_OF_VERSION_1_1);
    RUN_TEST(of_flow_stats_reply_create_OF_VERSION_1_1);
    RUN_TEST(of_flow_stats_request_create_OF_VERSION_1_1);
    RUN_TEST(of_get_config_reply_create_OF_VERSION_1_1);
    RUN_TEST(of_get_config_request_create_OF_VERSION_1_1);
    RUN_TEST(of_group_add_create_OF_VERSION_1_1);
    RUN_TEST(of_group_delete_create_OF_VERSION_1_1);
    RUN_TEST(of_group_desc_stats_reply_create_OF_VERSION_1_1);
    RUN_TEST(of_group_desc_stats_request_create_OF_VERSION_1_1);
    RUN_TEST(of_group_mod_failed_error_msg_create_OF_VERSION_1_1);
    RUN_TEST(of_group_modify_create_OF_VERSION_1_1);
    RUN_TEST(of_group_stats_reply_create_OF_VERSION_1_1);
    RUN_TEST(of_group_stats_request_create_OF_VERSION_1_1);
    RUN_TEST(of_hello_create_OF_VERSION_1_1);
    RUN_TEST(of_hello_failed_error_msg_create_OF_VERSION_1_1);
    RUN_TEST(of_packet_in_create_OF_VERSION_1_1);
    RUN_TEST(of_packet_out_create_OF_VERSION_1_1);
    RUN_TEST(of_port_mod_create_OF_VERSION_1_1);
    RUN_TEST(of_port_mod_failed_error_msg_create_OF_VERSION_1_1);
    RUN_TEST(of_port_stats_reply_create_OF_VERSION_1_1);
    RUN_TEST(of_port_stats_request_create_OF_VERSION_1_1);
    RUN_TEST(of_port_status_create_OF_VERSION_1_1);
    RUN_TEST(of_queue_get_config_reply_create_OF_VERSION_1_1);
    RUN_TEST(of_queue_get_config_request_create_OF_VERSION_1_1);
    RUN_TEST(of_queue_op_failed_error_msg_create_OF_VERSION_1_1);
    RUN_TEST(of_queue_stats_reply_create_OF_VERSION_1_1);
    RUN_TEST(of_queue_stats_request_create_OF_VERSION_1_1);
    RUN_TEST(of_set_config_create_OF_VERSION_1_1);
    RUN_TEST(of_switch_config_failed_error_msg_create_OF_VERSION_1_1);
    RUN_TEST(of_table_mod_create_OF_VERSION_1_1);
    RUN_TEST(of_table_mod_failed_error_msg_create_OF_VERSION_1_1);
    RUN_TEST(of_table_stats_reply_create_OF_VERSION_1_1);
    RUN_TEST(of_table_stats_request_create_OF_VERSION_1_1);
    RUN_TEST(of_aggregate_stats_reply_create_OF_VERSION_1_2);
    RUN_TEST(of_aggregate_stats_request_create_OF_VERSION_1_2);
    RUN_TEST(of_bad_action_error_msg_create_OF_VERSION_1_2);
    RUN_TEST(of_bad_instruction_error_msg_create_OF_VERSION_1_2);
    RUN_TEST(of_bad_match_error_msg_create_OF_VERSION_1_2);
    RUN_TEST(of_bad_request_error_msg_create_OF_VERSION_1_2);
    RUN_TEST(of_barrier_reply_create_OF_VERSION_1_2);
    RUN_TEST(of_barrier_request_create_OF_VERSION_1_2);
    RUN_TEST(of_bsn_bw_clear_data_reply_create_OF_VERSION_1_2);
    RUN_TEST(of_bsn_bw_clear_data_request_create_OF_VERSION_1_2);
    RUN_TEST(of_bsn_bw_enable_get_reply_create_OF_VERSION_1_2);
    RUN_TEST(of_bsn_bw_enable_get_request_create_OF_VERSION_1_2);
    RUN_TEST(of_bsn_bw_enable_set_reply_create_OF_VERSION_1_2);
    RUN_TEST(of_bsn_bw_enable_set_request_create_OF_VERSION_1_2);
    RUN_TEST(of_bsn_get_interfaces_reply_create_OF_VERSION_1_2);
    RUN_TEST(of_bsn_get_interfaces_request_create_OF_VERSION_1_2);
    RUN_TEST(of_bsn_get_mirroring_reply_create_OF_VERSION_1_2);
    RUN_TEST(of_bsn_get_mirroring_request_create_OF_VERSION_1_2);
    RUN_TEST(of_bsn_pdu_rx_reply_create_OF_VERSION_1_2);
    RUN_TEST(of_bsn_pdu_rx_request_create_OF_VERSION_1_2);
    RUN_TEST(of_bsn_pdu_rx_timeout_create_OF_VERSION_1_2);
    RUN_TEST(of_bsn_pdu_tx_reply_create_OF_VERSION_1_2);
    RUN_TEST(of_bsn_pdu_tx_request_create_OF_VERSION_1_2);
    RUN_TEST(of_bsn_set_mirroring_create_OF_VERSION_1_2);
    RUN_TEST(of_bsn_set_pktin_suppression_reply_create_OF_VERSION_1_2);
    RUN_TEST(of_bsn_set_pktin_suppression_request_create_OF_VERSION_1_2);
    RUN_TEST(of_bsn_virtual_port_create_reply_create_OF_VERSION_1_2);
    RUN_TEST(of_bsn_virtual_port_create_request_create_OF_VERSION_1_2);
    RUN_TEST(of_bsn_virtual_port_remove_reply_create_OF_VERSION_1_2);
    RUN_TEST(of_bsn_virtual_port_remove_request_create_OF_VERSION_1_2);
    RUN_TEST(of_desc_stats_reply_create_OF_VERSION_1_2);
    RUN_TEST(of_desc_stats_request_create_OF_VERSION_1_2);
    RUN_TEST(of_echo_reply_create_OF_VERSION_1_2);
    RUN_TEST(of_echo_request_create_OF_VERSION_1_2);
    RUN_TEST(of_features_reply_create_OF_VERSION_1_2);
    RUN_TEST(of_features_request_create_OF_VERSION_1_2);
    RUN_TEST(of_flow_add_create_OF_VERSION_1_2);
    RUN_TEST(of_flow_delete_create_OF_VERSION_1_2);
    RUN_TEST(of_flow_delete_strict_create_OF_VERSION_1_2);
    RUN_TEST(of_flow_mod_failed_error_msg_create_OF_VERSION_1_2);
    RUN_TEST(of_flow_modify_create_OF_VERSION_1_2);
    RUN_TEST(of_flow_modify_strict_create_OF_VERSION_1_2);
    RUN_TEST(of_flow_removed_create_OF_VERSION_1_2);
    RUN_TEST(of_flow_stats_reply_create_OF_VERSION_1_2);
    RUN_TEST(of_flow_stats_request_create_OF_VERSION_1_2);
    RUN_TEST(of_get_config_reply_create_OF_VERSION_1_2);
    RUN_TEST(of_get_config_request_create_OF_VERSION_1_2);
    RUN_TEST(of_group_add_create_OF_VERSION_1_2);
    RUN_TEST(of_group_delete_create_OF_VERSION_1_2);
    RUN_TEST(of_group_desc_stats_reply_create_OF_VERSION_1_2);
    RUN_TEST(of_group_desc_stats_request_create_OF_VERSION_1_2);
    RUN_TEST(of_group_features_stats_reply_create_OF_VERSION_1_2);
    RUN_TEST(of_group_features_stats_request_create_OF_VERSION_1_2);
    RUN_TEST(of_group_mod_failed_error_msg_create_OF_VERSION_1_2);
    RUN_TEST(of_group_modify_create_OF_VERSION_1_2);
    RUN_TEST(of_group_stats_reply_create_OF_VERSION_1_2);
    RUN_TEST(of_group_stats_request_create_OF_VERSION_1_2);
    RUN_TEST(of_hello_create_OF_VERSION_1_2);
    RUN_TEST(of_hello_failed_error_msg_create_OF_VERSION_1_2);
    RUN_TEST(of_packet_in_create_OF_VERSION_1_2);
    RUN_TEST(of_packet_out_create_OF_VERSION_1_2);
    RUN_TEST(of_port_mod_create_OF_VERSION_1_2);
    RUN_TEST(of_port_mod_failed_error_msg_create_OF_VERSION_1_2);
    RUN_TEST(of_port_stats_reply_create_OF_VERSION_1_2);
    RUN_TEST(of_port_stats_request_create_OF_VERSION_1_2);
    RUN_TEST(of_port_status_create_OF_VERSION_1_2);
    RUN_TEST(of_queue_get_config_reply_create_OF_VERSION_1_2);
    RUN_TEST(of_queue_get_config_request_create_OF_VERSION_1_2);
    RUN_TEST(of_queue_op_failed_error_msg_create_OF_VERSION_1_2);
    RUN_TEST(of_queue_stats_reply_create_OF_VERSION_1_2);
    RUN_TEST(of_queue_stats_request_create_OF_VERSION_1_2);
    RUN_TEST(of_role_reply_create_OF_VERSION_1_2);
    RUN_TEST(of_role_request_create_OF_VERSION_1_2);
    RUN_TEST(of_role_request_failed_error_msg_create_OF_VERSION_1_2);
    RUN_TEST(of_set_config_create_OF_VERSION_1_2);
    RUN_TEST(of_switch_config_failed_error_msg_create_OF_VERSION_1_2);
    RUN_TEST(of_table_mod_create_OF_VERSION_1_2);
    RUN_TEST(of_table_mod_failed_error_msg_create_OF_VERSION_1_2);
    RUN_TEST(of_table_stats_reply_create_OF_VERSION_1_2);
    RUN_TEST(of_table_stats_request_create_OF_VERSION_1_2);
    RUN_TEST(of_aggregate_stats_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_aggregate_stats_request_create_OF_VERSION_1_3);
    RUN_TEST(of_async_get_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_async_get_request_create_OF_VERSION_1_3);
    RUN_TEST(of_async_set_create_OF_VERSION_1_3);
    RUN_TEST(of_bad_action_error_msg_create_OF_VERSION_1_3);
    RUN_TEST(of_bad_instruction_error_msg_create_OF_VERSION_1_3);
    RUN_TEST(of_bad_match_error_msg_create_OF_VERSION_1_3);
    RUN_TEST(of_bad_request_error_msg_create_OF_VERSION_1_3);
    RUN_TEST(of_barrier_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_barrier_request_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_arp_idle_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_bw_clear_data_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_bw_clear_data_request_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_bw_enable_get_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_bw_enable_get_request_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_bw_enable_set_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_bw_enable_set_request_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_controller_connections_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_controller_connections_request_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_debug_counter_desc_stats_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_debug_counter_desc_stats_request_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_debug_counter_stats_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_debug_counter_stats_request_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_error_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_flow_checksum_bucket_stats_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_flow_checksum_bucket_stats_request_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_flow_idle_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_flow_idle_enable_get_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_flow_idle_enable_get_request_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_flow_idle_enable_set_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_flow_idle_enable_set_request_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_generic_stats_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_generic_stats_request_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_gentable_bucket_stats_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_gentable_bucket_stats_request_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_gentable_clear_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_gentable_clear_request_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_gentable_desc_stats_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_gentable_desc_stats_request_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_gentable_entry_add_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_gentable_entry_delete_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_gentable_entry_desc_stats_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_gentable_entry_desc_stats_request_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_gentable_entry_stats_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_gentable_entry_stats_request_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_gentable_error_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_gentable_set_buckets_size_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_gentable_stats_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_gentable_stats_request_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_get_interfaces_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_get_interfaces_request_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_get_mirroring_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_get_mirroring_request_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_get_switch_pipeline_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_get_switch_pipeline_request_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_image_desc_stats_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_image_desc_stats_request_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_lacp_convergence_notif_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_lacp_stats_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_lacp_stats_request_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_log_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_lua_command_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_lua_command_request_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_lua_notification_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_lua_upload_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_pdu_rx_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_pdu_rx_request_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_pdu_rx_timeout_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_pdu_tx_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_pdu_tx_request_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_port_counter_stats_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_port_counter_stats_request_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_role_status_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_set_aux_cxns_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_set_aux_cxns_request_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_set_lacp_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_set_lacp_request_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_set_mirroring_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_set_pktin_suppression_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_set_pktin_suppression_request_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_set_switch_pipeline_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_set_switch_pipeline_request_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_switch_pipeline_stats_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_switch_pipeline_stats_request_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_table_checksum_stats_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_table_checksum_stats_request_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_table_set_buckets_size_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_time_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_time_request_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_virtual_port_create_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_virtual_port_create_request_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_virtual_port_remove_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_virtual_port_remove_request_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_vlan_counter_clear_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_vlan_counter_stats_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_vlan_counter_stats_request_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_vrf_counter_stats_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_bsn_vrf_counter_stats_request_create_OF_VERSION_1_3);
    RUN_TEST(of_desc_stats_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_desc_stats_request_create_OF_VERSION_1_3);
    RUN_TEST(of_echo_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_echo_request_create_OF_VERSION_1_3);
    RUN_TEST(of_features_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_features_request_create_OF_VERSION_1_3);
    RUN_TEST(of_flow_add_create_OF_VERSION_1_3);
    RUN_TEST(of_flow_delete_create_OF_VERSION_1_3);
    RUN_TEST(of_flow_delete_strict_create_OF_VERSION_1_3);
    RUN_TEST(of_flow_mod_failed_error_msg_create_OF_VERSION_1_3);
    RUN_TEST(of_flow_modify_create_OF_VERSION_1_3);
    RUN_TEST(of_flow_modify_strict_create_OF_VERSION_1_3);
    RUN_TEST(of_flow_removed_create_OF_VERSION_1_3);
    RUN_TEST(of_flow_stats_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_flow_stats_request_create_OF_VERSION_1_3);
    RUN_TEST(of_get_config_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_get_config_request_create_OF_VERSION_1_3);
    RUN_TEST(of_group_add_create_OF_VERSION_1_3);
    RUN_TEST(of_group_delete_create_OF_VERSION_1_3);
    RUN_TEST(of_group_desc_stats_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_group_desc_stats_request_create_OF_VERSION_1_3);
    RUN_TEST(of_group_features_stats_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_group_features_stats_request_create_OF_VERSION_1_3);
    RUN_TEST(of_group_mod_failed_error_msg_create_OF_VERSION_1_3);
    RUN_TEST(of_group_modify_create_OF_VERSION_1_3);
    RUN_TEST(of_group_stats_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_group_stats_request_create_OF_VERSION_1_3);
    RUN_TEST(of_hello_create_OF_VERSION_1_3);
    RUN_TEST(of_hello_failed_error_msg_create_OF_VERSION_1_3);
    RUN_TEST(of_meter_config_stats_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_meter_config_stats_request_create_OF_VERSION_1_3);
    RUN_TEST(of_meter_features_stats_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_meter_features_stats_request_create_OF_VERSION_1_3);
    RUN_TEST(of_meter_mod_create_OF_VERSION_1_3);
    RUN_TEST(of_meter_mod_failed_error_msg_create_OF_VERSION_1_3);
    RUN_TEST(of_meter_stats_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_meter_stats_request_create_OF_VERSION_1_3);
    RUN_TEST(of_packet_in_create_OF_VERSION_1_3);
    RUN_TEST(of_packet_out_create_OF_VERSION_1_3);
    RUN_TEST(of_port_desc_stats_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_port_desc_stats_request_create_OF_VERSION_1_3);
    RUN_TEST(of_port_mod_create_OF_VERSION_1_3);
    RUN_TEST(of_port_mod_failed_error_msg_create_OF_VERSION_1_3);
    RUN_TEST(of_port_stats_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_port_stats_request_create_OF_VERSION_1_3);
    RUN_TEST(of_port_status_create_OF_VERSION_1_3);
    RUN_TEST(of_queue_get_config_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_queue_get_config_request_create_OF_VERSION_1_3);
    RUN_TEST(of_queue_op_failed_error_msg_create_OF_VERSION_1_3);
    RUN_TEST(of_queue_stats_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_queue_stats_request_create_OF_VERSION_1_3);
    RUN_TEST(of_role_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_role_request_create_OF_VERSION_1_3);
    RUN_TEST(of_role_request_failed_error_msg_create_OF_VERSION_1_3);
    RUN_TEST(of_set_config_create_OF_VERSION_1_3);
    RUN_TEST(of_switch_config_failed_error_msg_create_OF_VERSION_1_3);
    RUN_TEST(of_table_features_failed_error_msg_create_OF_VERSION_1_3);
    RUN_TEST(of_table_features_stats_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_table_features_stats_request_create_OF_VERSION_1_3);
    RUN_TEST(of_table_mod_create_OF_VERSION_1_3);
    RUN_TEST(of_table_mod_failed_error_msg_create_OF_VERSION_1_3);
    RUN_TEST(of_table_stats_reply_create_OF_VERSION_1_3);
    RUN_TEST(of_table_stats_request_create_OF_VERSION_1_3);
    RUN_TEST(of_aggregate_stats_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_aggregate_stats_request_create_OF_VERSION_1_4);
    RUN_TEST(of_async_config_failed_error_msg_create_OF_VERSION_1_4);
    RUN_TEST(of_async_get_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_async_get_request_create_OF_VERSION_1_4);
    RUN_TEST(of_async_set_create_OF_VERSION_1_4);
    RUN_TEST(of_bad_action_error_msg_create_OF_VERSION_1_4);
    RUN_TEST(of_bad_instruction_error_msg_create_OF_VERSION_1_4);
    RUN_TEST(of_bad_match_error_msg_create_OF_VERSION_1_4);
    RUN_TEST(of_bad_property_error_msg_create_OF_VERSION_1_4);
    RUN_TEST(of_bad_request_error_msg_create_OF_VERSION_1_4);
    RUN_TEST(of_barrier_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_barrier_request_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_arp_idle_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_bw_clear_data_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_bw_clear_data_request_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_bw_enable_get_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_bw_enable_get_request_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_bw_enable_set_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_bw_enable_set_request_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_controller_connections_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_controller_connections_request_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_debug_counter_desc_stats_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_debug_counter_desc_stats_request_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_debug_counter_stats_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_debug_counter_stats_request_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_error_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_flow_checksum_bucket_stats_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_flow_checksum_bucket_stats_request_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_flow_idle_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_flow_idle_enable_get_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_flow_idle_enable_get_request_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_flow_idle_enable_set_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_flow_idle_enable_set_request_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_generic_async_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_generic_command_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_generic_command_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_generic_stats_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_generic_stats_request_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_gentable_bucket_stats_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_gentable_bucket_stats_request_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_gentable_clear_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_gentable_clear_request_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_gentable_desc_stats_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_gentable_desc_stats_request_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_gentable_entry_add_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_gentable_entry_delete_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_gentable_entry_desc_stats_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_gentable_entry_desc_stats_request_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_gentable_entry_stats_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_gentable_entry_stats_request_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_gentable_error_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_gentable_set_buckets_size_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_gentable_stats_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_gentable_stats_request_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_get_interfaces_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_get_interfaces_request_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_get_mirroring_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_get_mirroring_request_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_get_switch_pipeline_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_get_switch_pipeline_request_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_image_desc_stats_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_image_desc_stats_request_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_lacp_convergence_notif_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_lacp_stats_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_lacp_stats_request_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_log_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_lua_command_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_lua_command_request_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_lua_notification_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_lua_upload_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_pdu_rx_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_pdu_rx_request_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_pdu_rx_timeout_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_pdu_tx_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_pdu_tx_request_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_port_counter_stats_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_port_counter_stats_request_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_set_aux_cxns_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_set_aux_cxns_request_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_set_lacp_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_set_lacp_request_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_set_mirroring_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_set_pktin_suppression_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_set_pktin_suppression_request_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_set_switch_pipeline_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_set_switch_pipeline_request_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_switch_pipeline_stats_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_switch_pipeline_stats_request_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_table_checksum_stats_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_table_checksum_stats_request_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_table_set_buckets_size_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_takeover_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_time_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_time_request_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_virtual_port_create_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_virtual_port_create_request_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_virtual_port_remove_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_virtual_port_remove_request_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_vlan_counter_clear_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_vlan_counter_stats_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_vlan_counter_stats_request_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_vrf_counter_stats_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_bsn_vrf_counter_stats_request_create_OF_VERSION_1_4);
    RUN_TEST(of_bundle_add_msg_create_OF_VERSION_1_4);
    RUN_TEST(of_bundle_ctrl_msg_create_OF_VERSION_1_4);
    RUN_TEST(of_bundle_failed_error_msg_create_OF_VERSION_1_4);
    RUN_TEST(of_desc_stats_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_desc_stats_request_create_OF_VERSION_1_4);
    RUN_TEST(of_echo_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_echo_request_create_OF_VERSION_1_4);
    RUN_TEST(of_features_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_features_request_create_OF_VERSION_1_4);
    RUN_TEST(of_flow_add_create_OF_VERSION_1_4);
    RUN_TEST(of_flow_delete_create_OF_VERSION_1_4);
    RUN_TEST(of_flow_delete_strict_create_OF_VERSION_1_4);
    RUN_TEST(of_flow_mod_failed_error_msg_create_OF_VERSION_1_4);
    RUN_TEST(of_flow_modify_create_OF_VERSION_1_4);
    RUN_TEST(of_flow_modify_strict_create_OF_VERSION_1_4);
    RUN_TEST(of_flow_monitor_failed_error_msg_create_OF_VERSION_1_4);
    RUN_TEST(of_flow_removed_create_OF_VERSION_1_4);
    RUN_TEST(of_flow_stats_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_flow_stats_request_create_OF_VERSION_1_4);
    RUN_TEST(of_get_config_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_get_config_request_create_OF_VERSION_1_4);
    RUN_TEST(of_group_add_create_OF_VERSION_1_4);
    RUN_TEST(of_group_delete_create_OF_VERSION_1_4);
    RUN_TEST(of_group_desc_stats_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_group_desc_stats_request_create_OF_VERSION_1_4);
    RUN_TEST(of_group_features_stats_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_group_features_stats_request_create_OF_VERSION_1_4);
    RUN_TEST(of_group_mod_failed_error_msg_create_OF_VERSION_1_4);
    RUN_TEST(of_group_modify_create_OF_VERSION_1_4);
    RUN_TEST(of_group_stats_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_group_stats_request_create_OF_VERSION_1_4);
    RUN_TEST(of_hello_create_OF_VERSION_1_4);
    RUN_TEST(of_hello_failed_error_msg_create_OF_VERSION_1_4);
    RUN_TEST(of_meter_config_stats_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_meter_config_stats_request_create_OF_VERSION_1_4);
    RUN_TEST(of_meter_features_stats_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_meter_features_stats_request_create_OF_VERSION_1_4);
    RUN_TEST(of_meter_mod_create_OF_VERSION_1_4);
    RUN_TEST(of_meter_mod_failed_error_msg_create_OF_VERSION_1_4);
    RUN_TEST(of_meter_stats_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_meter_stats_request_create_OF_VERSION_1_4);
    RUN_TEST(of_packet_in_create_OF_VERSION_1_4);
    RUN_TEST(of_packet_out_create_OF_VERSION_1_4);
    RUN_TEST(of_port_desc_stats_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_port_desc_stats_request_create_OF_VERSION_1_4);
    RUN_TEST(of_port_mod_create_OF_VERSION_1_4);
    RUN_TEST(of_port_mod_failed_error_msg_create_OF_VERSION_1_4);
    RUN_TEST(of_port_stats_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_port_stats_request_create_OF_VERSION_1_4);
    RUN_TEST(of_port_status_create_OF_VERSION_1_4);
    RUN_TEST(of_queue_desc_stats_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_queue_desc_stats_request_create_OF_VERSION_1_4);
    RUN_TEST(of_queue_op_failed_error_msg_create_OF_VERSION_1_4);
    RUN_TEST(of_queue_stats_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_queue_stats_request_create_OF_VERSION_1_4);
    RUN_TEST(of_requestforward_create_OF_VERSION_1_4);
    RUN_TEST(of_role_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_role_request_create_OF_VERSION_1_4);
    RUN_TEST(of_role_request_failed_error_msg_create_OF_VERSION_1_4);
    RUN_TEST(of_role_status_create_OF_VERSION_1_4);
    RUN_TEST(of_set_config_create_OF_VERSION_1_4);
    RUN_TEST(of_switch_config_failed_error_msg_create_OF_VERSION_1_4);
    RUN_TEST(of_table_desc_stats_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_table_desc_stats_request_create_OF_VERSION_1_4);
    RUN_TEST(of_table_features_failed_error_msg_create_OF_VERSION_1_4);
    RUN_TEST(of_table_features_stats_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_table_features_stats_request_create_OF_VERSION_1_4);
    RUN_TEST(of_table_mod_create_OF_VERSION_1_4);
    RUN_TEST(of_table_mod_failed_error_msg_create_OF_VERSION_1_4);
    RUN_TEST(of_table_stats_reply_create_OF_VERSION_1_4);
    RUN_TEST(of_table_stats_request_create_OF_VERSION_1_4);
    RUN_TEST(of_table_status_create_OF_VERSION_1_4);

    return TEST_PASS;
}
