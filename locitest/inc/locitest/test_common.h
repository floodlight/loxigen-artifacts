/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */

/*
 * Test header file
 *
 * AUTOMATICALLY GENERATED FILE.  Edits will be lost on regen.
 */

#if !defined(_TEST_COMMON_H_)
#define _TEST_COMMON_H_

#define DISABLE_WARN_UNUSED_RESULT
#include <loci/loci.h>
#include <locitest/of_dup.h>
#include <locitest/unittest.h>

extern int global_error;
extern int exit_on_error;

/* @todo Make option for -k to continue tests if errors */
#define RUN_TEST(test) do {                                             \
        int rv;                                                         \
        TESTCASE(test, rv);                                             \
        if (rv != TEST_PASS) {                                          \
            global_error=1;                                             \
            if (exit_on_error) return(1);                               \
        }                                                               \
    } while(0)

#define TEST_OK(op) TEST_ASSERT((op) == OF_ERROR_NONE)
#define TEST_INDIGO_OK(op) TEST_ASSERT((op) == INDIGO_ERROR_NONE)

/*
 * Declarations of functions to populate scalar values in a a class
 */

extern void of_test_str_fill(uint8_t *buf, int value, int len);
extern int of_test_str_check(uint8_t *buf, int value, int len);


extern int of_octets_populate(of_octets_t *octets, int value);
extern int of_octets_check(of_octets_t *octets, int value);
extern int of_match_populate(of_match_t *match, of_version_t version,
                             int value);
extern int of_match_check(of_match_t *match, of_version_t version, int value);
extern int test_ident_macros(void);
extern int test_dump_objs(void);

/* In test_match_utils.c */
extern int test_match_utils(void);

extern int run_unified_accessor_tests(void);
extern int run_match_tests(void);
extern int run_utility_tests(void);

extern int run_scalar_acc_tests(void);
extern int run_list_tests(void);
extern int run_message_tests(void);

extern int run_validator_tests(void);

extern int run_list_limits_tests(void);

extern int test_ext_objs(void);
extern int test_datafiles(void);


extern int of_aggregate_stats_reply_OF_VERSION_1_0_populate(
    of_aggregate_stats_reply_t *obj, int value);
extern int of_aggregate_stats_reply_OF_VERSION_1_0_check(
    of_aggregate_stats_reply_t *obj, int value);
extern int of_aggregate_stats_reply_OF_VERSION_1_0_populate_scalars(
    of_aggregate_stats_reply_t *obj, int value);
extern int of_aggregate_stats_reply_OF_VERSION_1_0_check_scalars(
    of_aggregate_stats_reply_t *obj, int value);

extern int of_aggregate_stats_request_OF_VERSION_1_0_populate(
    of_aggregate_stats_request_t *obj, int value);
extern int of_aggregate_stats_request_OF_VERSION_1_0_check(
    of_aggregate_stats_request_t *obj, int value);
extern int of_aggregate_stats_request_OF_VERSION_1_0_populate_scalars(
    of_aggregate_stats_request_t *obj, int value);
extern int of_aggregate_stats_request_OF_VERSION_1_0_check_scalars(
    of_aggregate_stats_request_t *obj, int value);

extern int of_bad_action_error_msg_OF_VERSION_1_0_populate(
    of_bad_action_error_msg_t *obj, int value);
extern int of_bad_action_error_msg_OF_VERSION_1_0_check(
    of_bad_action_error_msg_t *obj, int value);
extern int of_bad_action_error_msg_OF_VERSION_1_0_populate_scalars(
    of_bad_action_error_msg_t *obj, int value);
extern int of_bad_action_error_msg_OF_VERSION_1_0_check_scalars(
    of_bad_action_error_msg_t *obj, int value);

extern int of_bad_request_error_msg_OF_VERSION_1_0_populate(
    of_bad_request_error_msg_t *obj, int value);
extern int of_bad_request_error_msg_OF_VERSION_1_0_check(
    of_bad_request_error_msg_t *obj, int value);
extern int of_bad_request_error_msg_OF_VERSION_1_0_populate_scalars(
    of_bad_request_error_msg_t *obj, int value);
extern int of_bad_request_error_msg_OF_VERSION_1_0_check_scalars(
    of_bad_request_error_msg_t *obj, int value);

extern int of_barrier_reply_OF_VERSION_1_0_populate(
    of_barrier_reply_t *obj, int value);
extern int of_barrier_reply_OF_VERSION_1_0_check(
    of_barrier_reply_t *obj, int value);
extern int of_barrier_reply_OF_VERSION_1_0_populate_scalars(
    of_barrier_reply_t *obj, int value);
extern int of_barrier_reply_OF_VERSION_1_0_check_scalars(
    of_barrier_reply_t *obj, int value);

extern int of_barrier_request_OF_VERSION_1_0_populate(
    of_barrier_request_t *obj, int value);
extern int of_barrier_request_OF_VERSION_1_0_check(
    of_barrier_request_t *obj, int value);
extern int of_barrier_request_OF_VERSION_1_0_populate_scalars(
    of_barrier_request_t *obj, int value);
extern int of_barrier_request_OF_VERSION_1_0_check_scalars(
    of_barrier_request_t *obj, int value);

extern int of_bsn_bw_clear_data_reply_OF_VERSION_1_0_populate(
    of_bsn_bw_clear_data_reply_t *obj, int value);
extern int of_bsn_bw_clear_data_reply_OF_VERSION_1_0_check(
    of_bsn_bw_clear_data_reply_t *obj, int value);
extern int of_bsn_bw_clear_data_reply_OF_VERSION_1_0_populate_scalars(
    of_bsn_bw_clear_data_reply_t *obj, int value);
extern int of_bsn_bw_clear_data_reply_OF_VERSION_1_0_check_scalars(
    of_bsn_bw_clear_data_reply_t *obj, int value);

extern int of_bsn_bw_clear_data_request_OF_VERSION_1_0_populate(
    of_bsn_bw_clear_data_request_t *obj, int value);
extern int of_bsn_bw_clear_data_request_OF_VERSION_1_0_check(
    of_bsn_bw_clear_data_request_t *obj, int value);
extern int of_bsn_bw_clear_data_request_OF_VERSION_1_0_populate_scalars(
    of_bsn_bw_clear_data_request_t *obj, int value);
extern int of_bsn_bw_clear_data_request_OF_VERSION_1_0_check_scalars(
    of_bsn_bw_clear_data_request_t *obj, int value);

extern int of_bsn_bw_enable_get_reply_OF_VERSION_1_0_populate(
    of_bsn_bw_enable_get_reply_t *obj, int value);
extern int of_bsn_bw_enable_get_reply_OF_VERSION_1_0_check(
    of_bsn_bw_enable_get_reply_t *obj, int value);
extern int of_bsn_bw_enable_get_reply_OF_VERSION_1_0_populate_scalars(
    of_bsn_bw_enable_get_reply_t *obj, int value);
extern int of_bsn_bw_enable_get_reply_OF_VERSION_1_0_check_scalars(
    of_bsn_bw_enable_get_reply_t *obj, int value);

extern int of_bsn_bw_enable_get_request_OF_VERSION_1_0_populate(
    of_bsn_bw_enable_get_request_t *obj, int value);
extern int of_bsn_bw_enable_get_request_OF_VERSION_1_0_check(
    of_bsn_bw_enable_get_request_t *obj, int value);
extern int of_bsn_bw_enable_get_request_OF_VERSION_1_0_populate_scalars(
    of_bsn_bw_enable_get_request_t *obj, int value);
extern int of_bsn_bw_enable_get_request_OF_VERSION_1_0_check_scalars(
    of_bsn_bw_enable_get_request_t *obj, int value);

extern int of_bsn_bw_enable_set_reply_OF_VERSION_1_0_populate(
    of_bsn_bw_enable_set_reply_t *obj, int value);
extern int of_bsn_bw_enable_set_reply_OF_VERSION_1_0_check(
    of_bsn_bw_enable_set_reply_t *obj, int value);
extern int of_bsn_bw_enable_set_reply_OF_VERSION_1_0_populate_scalars(
    of_bsn_bw_enable_set_reply_t *obj, int value);
extern int of_bsn_bw_enable_set_reply_OF_VERSION_1_0_check_scalars(
    of_bsn_bw_enable_set_reply_t *obj, int value);

extern int of_bsn_bw_enable_set_request_OF_VERSION_1_0_populate(
    of_bsn_bw_enable_set_request_t *obj, int value);
extern int of_bsn_bw_enable_set_request_OF_VERSION_1_0_check(
    of_bsn_bw_enable_set_request_t *obj, int value);
extern int of_bsn_bw_enable_set_request_OF_VERSION_1_0_populate_scalars(
    of_bsn_bw_enable_set_request_t *obj, int value);
extern int of_bsn_bw_enable_set_request_OF_VERSION_1_0_check_scalars(
    of_bsn_bw_enable_set_request_t *obj, int value);

extern int of_bsn_get_interfaces_reply_OF_VERSION_1_0_populate(
    of_bsn_get_interfaces_reply_t *obj, int value);
extern int of_bsn_get_interfaces_reply_OF_VERSION_1_0_check(
    of_bsn_get_interfaces_reply_t *obj, int value);
extern int of_bsn_get_interfaces_reply_OF_VERSION_1_0_populate_scalars(
    of_bsn_get_interfaces_reply_t *obj, int value);
extern int of_bsn_get_interfaces_reply_OF_VERSION_1_0_check_scalars(
    of_bsn_get_interfaces_reply_t *obj, int value);

extern int of_bsn_get_interfaces_request_OF_VERSION_1_0_populate(
    of_bsn_get_interfaces_request_t *obj, int value);
extern int of_bsn_get_interfaces_request_OF_VERSION_1_0_check(
    of_bsn_get_interfaces_request_t *obj, int value);
extern int of_bsn_get_interfaces_request_OF_VERSION_1_0_populate_scalars(
    of_bsn_get_interfaces_request_t *obj, int value);
extern int of_bsn_get_interfaces_request_OF_VERSION_1_0_check_scalars(
    of_bsn_get_interfaces_request_t *obj, int value);

extern int of_bsn_get_ip_mask_reply_OF_VERSION_1_0_populate(
    of_bsn_get_ip_mask_reply_t *obj, int value);
extern int of_bsn_get_ip_mask_reply_OF_VERSION_1_0_check(
    of_bsn_get_ip_mask_reply_t *obj, int value);
extern int of_bsn_get_ip_mask_reply_OF_VERSION_1_0_populate_scalars(
    of_bsn_get_ip_mask_reply_t *obj, int value);
extern int of_bsn_get_ip_mask_reply_OF_VERSION_1_0_check_scalars(
    of_bsn_get_ip_mask_reply_t *obj, int value);

extern int of_bsn_get_ip_mask_request_OF_VERSION_1_0_populate(
    of_bsn_get_ip_mask_request_t *obj, int value);
extern int of_bsn_get_ip_mask_request_OF_VERSION_1_0_check(
    of_bsn_get_ip_mask_request_t *obj, int value);
extern int of_bsn_get_ip_mask_request_OF_VERSION_1_0_populate_scalars(
    of_bsn_get_ip_mask_request_t *obj, int value);
extern int of_bsn_get_ip_mask_request_OF_VERSION_1_0_check_scalars(
    of_bsn_get_ip_mask_request_t *obj, int value);

extern int of_bsn_get_l2_table_reply_OF_VERSION_1_0_populate(
    of_bsn_get_l2_table_reply_t *obj, int value);
extern int of_bsn_get_l2_table_reply_OF_VERSION_1_0_check(
    of_bsn_get_l2_table_reply_t *obj, int value);
extern int of_bsn_get_l2_table_reply_OF_VERSION_1_0_populate_scalars(
    of_bsn_get_l2_table_reply_t *obj, int value);
extern int of_bsn_get_l2_table_reply_OF_VERSION_1_0_check_scalars(
    of_bsn_get_l2_table_reply_t *obj, int value);

extern int of_bsn_get_l2_table_request_OF_VERSION_1_0_populate(
    of_bsn_get_l2_table_request_t *obj, int value);
extern int of_bsn_get_l2_table_request_OF_VERSION_1_0_check(
    of_bsn_get_l2_table_request_t *obj, int value);
extern int of_bsn_get_l2_table_request_OF_VERSION_1_0_populate_scalars(
    of_bsn_get_l2_table_request_t *obj, int value);
extern int of_bsn_get_l2_table_request_OF_VERSION_1_0_check_scalars(
    of_bsn_get_l2_table_request_t *obj, int value);

extern int of_bsn_get_mirroring_reply_OF_VERSION_1_0_populate(
    of_bsn_get_mirroring_reply_t *obj, int value);
extern int of_bsn_get_mirroring_reply_OF_VERSION_1_0_check(
    of_bsn_get_mirroring_reply_t *obj, int value);
extern int of_bsn_get_mirroring_reply_OF_VERSION_1_0_populate_scalars(
    of_bsn_get_mirroring_reply_t *obj, int value);
extern int of_bsn_get_mirroring_reply_OF_VERSION_1_0_check_scalars(
    of_bsn_get_mirroring_reply_t *obj, int value);

extern int of_bsn_get_mirroring_request_OF_VERSION_1_0_populate(
    of_bsn_get_mirroring_request_t *obj, int value);
extern int of_bsn_get_mirroring_request_OF_VERSION_1_0_check(
    of_bsn_get_mirroring_request_t *obj, int value);
extern int of_bsn_get_mirroring_request_OF_VERSION_1_0_populate_scalars(
    of_bsn_get_mirroring_request_t *obj, int value);
extern int of_bsn_get_mirroring_request_OF_VERSION_1_0_check_scalars(
    of_bsn_get_mirroring_request_t *obj, int value);

extern int of_bsn_hybrid_get_reply_OF_VERSION_1_0_populate(
    of_bsn_hybrid_get_reply_t *obj, int value);
extern int of_bsn_hybrid_get_reply_OF_VERSION_1_0_check(
    of_bsn_hybrid_get_reply_t *obj, int value);
extern int of_bsn_hybrid_get_reply_OF_VERSION_1_0_populate_scalars(
    of_bsn_hybrid_get_reply_t *obj, int value);
extern int of_bsn_hybrid_get_reply_OF_VERSION_1_0_check_scalars(
    of_bsn_hybrid_get_reply_t *obj, int value);

extern int of_bsn_hybrid_get_request_OF_VERSION_1_0_populate(
    of_bsn_hybrid_get_request_t *obj, int value);
extern int of_bsn_hybrid_get_request_OF_VERSION_1_0_check(
    of_bsn_hybrid_get_request_t *obj, int value);
extern int of_bsn_hybrid_get_request_OF_VERSION_1_0_populate_scalars(
    of_bsn_hybrid_get_request_t *obj, int value);
extern int of_bsn_hybrid_get_request_OF_VERSION_1_0_check_scalars(
    of_bsn_hybrid_get_request_t *obj, int value);

extern int of_bsn_pdu_rx_reply_OF_VERSION_1_0_populate(
    of_bsn_pdu_rx_reply_t *obj, int value);
extern int of_bsn_pdu_rx_reply_OF_VERSION_1_0_check(
    of_bsn_pdu_rx_reply_t *obj, int value);
extern int of_bsn_pdu_rx_reply_OF_VERSION_1_0_populate_scalars(
    of_bsn_pdu_rx_reply_t *obj, int value);
extern int of_bsn_pdu_rx_reply_OF_VERSION_1_0_check_scalars(
    of_bsn_pdu_rx_reply_t *obj, int value);

extern int of_bsn_pdu_rx_request_OF_VERSION_1_0_populate(
    of_bsn_pdu_rx_request_t *obj, int value);
extern int of_bsn_pdu_rx_request_OF_VERSION_1_0_check(
    of_bsn_pdu_rx_request_t *obj, int value);
extern int of_bsn_pdu_rx_request_OF_VERSION_1_0_populate_scalars(
    of_bsn_pdu_rx_request_t *obj, int value);
extern int of_bsn_pdu_rx_request_OF_VERSION_1_0_check_scalars(
    of_bsn_pdu_rx_request_t *obj, int value);

extern int of_bsn_pdu_rx_timeout_OF_VERSION_1_0_populate(
    of_bsn_pdu_rx_timeout_t *obj, int value);
extern int of_bsn_pdu_rx_timeout_OF_VERSION_1_0_check(
    of_bsn_pdu_rx_timeout_t *obj, int value);
extern int of_bsn_pdu_rx_timeout_OF_VERSION_1_0_populate_scalars(
    of_bsn_pdu_rx_timeout_t *obj, int value);
extern int of_bsn_pdu_rx_timeout_OF_VERSION_1_0_check_scalars(
    of_bsn_pdu_rx_timeout_t *obj, int value);

extern int of_bsn_pdu_tx_reply_OF_VERSION_1_0_populate(
    of_bsn_pdu_tx_reply_t *obj, int value);
extern int of_bsn_pdu_tx_reply_OF_VERSION_1_0_check(
    of_bsn_pdu_tx_reply_t *obj, int value);
extern int of_bsn_pdu_tx_reply_OF_VERSION_1_0_populate_scalars(
    of_bsn_pdu_tx_reply_t *obj, int value);
extern int of_bsn_pdu_tx_reply_OF_VERSION_1_0_check_scalars(
    of_bsn_pdu_tx_reply_t *obj, int value);

extern int of_bsn_pdu_tx_request_OF_VERSION_1_0_populate(
    of_bsn_pdu_tx_request_t *obj, int value);
extern int of_bsn_pdu_tx_request_OF_VERSION_1_0_check(
    of_bsn_pdu_tx_request_t *obj, int value);
extern int of_bsn_pdu_tx_request_OF_VERSION_1_0_populate_scalars(
    of_bsn_pdu_tx_request_t *obj, int value);
extern int of_bsn_pdu_tx_request_OF_VERSION_1_0_check_scalars(
    of_bsn_pdu_tx_request_t *obj, int value);

extern int of_bsn_set_ip_mask_OF_VERSION_1_0_populate(
    of_bsn_set_ip_mask_t *obj, int value);
extern int of_bsn_set_ip_mask_OF_VERSION_1_0_check(
    of_bsn_set_ip_mask_t *obj, int value);
extern int of_bsn_set_ip_mask_OF_VERSION_1_0_populate_scalars(
    of_bsn_set_ip_mask_t *obj, int value);
extern int of_bsn_set_ip_mask_OF_VERSION_1_0_check_scalars(
    of_bsn_set_ip_mask_t *obj, int value);

extern int of_bsn_set_l2_table_reply_OF_VERSION_1_0_populate(
    of_bsn_set_l2_table_reply_t *obj, int value);
extern int of_bsn_set_l2_table_reply_OF_VERSION_1_0_check(
    of_bsn_set_l2_table_reply_t *obj, int value);
extern int of_bsn_set_l2_table_reply_OF_VERSION_1_0_populate_scalars(
    of_bsn_set_l2_table_reply_t *obj, int value);
extern int of_bsn_set_l2_table_reply_OF_VERSION_1_0_check_scalars(
    of_bsn_set_l2_table_reply_t *obj, int value);

extern int of_bsn_set_l2_table_request_OF_VERSION_1_0_populate(
    of_bsn_set_l2_table_request_t *obj, int value);
extern int of_bsn_set_l2_table_request_OF_VERSION_1_0_check(
    of_bsn_set_l2_table_request_t *obj, int value);
extern int of_bsn_set_l2_table_request_OF_VERSION_1_0_populate_scalars(
    of_bsn_set_l2_table_request_t *obj, int value);
extern int of_bsn_set_l2_table_request_OF_VERSION_1_0_check_scalars(
    of_bsn_set_l2_table_request_t *obj, int value);

extern int of_bsn_set_mirroring_OF_VERSION_1_0_populate(
    of_bsn_set_mirroring_t *obj, int value);
extern int of_bsn_set_mirroring_OF_VERSION_1_0_check(
    of_bsn_set_mirroring_t *obj, int value);
extern int of_bsn_set_mirroring_OF_VERSION_1_0_populate_scalars(
    of_bsn_set_mirroring_t *obj, int value);
extern int of_bsn_set_mirroring_OF_VERSION_1_0_check_scalars(
    of_bsn_set_mirroring_t *obj, int value);

extern int of_bsn_set_pktin_suppression_reply_OF_VERSION_1_0_populate(
    of_bsn_set_pktin_suppression_reply_t *obj, int value);
extern int of_bsn_set_pktin_suppression_reply_OF_VERSION_1_0_check(
    of_bsn_set_pktin_suppression_reply_t *obj, int value);
extern int of_bsn_set_pktin_suppression_reply_OF_VERSION_1_0_populate_scalars(
    of_bsn_set_pktin_suppression_reply_t *obj, int value);
extern int of_bsn_set_pktin_suppression_reply_OF_VERSION_1_0_check_scalars(
    of_bsn_set_pktin_suppression_reply_t *obj, int value);

extern int of_bsn_set_pktin_suppression_request_OF_VERSION_1_0_populate(
    of_bsn_set_pktin_suppression_request_t *obj, int value);
extern int of_bsn_set_pktin_suppression_request_OF_VERSION_1_0_check(
    of_bsn_set_pktin_suppression_request_t *obj, int value);
extern int of_bsn_set_pktin_suppression_request_OF_VERSION_1_0_populate_scalars(
    of_bsn_set_pktin_suppression_request_t *obj, int value);
extern int of_bsn_set_pktin_suppression_request_OF_VERSION_1_0_check_scalars(
    of_bsn_set_pktin_suppression_request_t *obj, int value);

extern int of_bsn_shell_command_OF_VERSION_1_0_populate(
    of_bsn_shell_command_t *obj, int value);
extern int of_bsn_shell_command_OF_VERSION_1_0_check(
    of_bsn_shell_command_t *obj, int value);
extern int of_bsn_shell_command_OF_VERSION_1_0_populate_scalars(
    of_bsn_shell_command_t *obj, int value);
extern int of_bsn_shell_command_OF_VERSION_1_0_check_scalars(
    of_bsn_shell_command_t *obj, int value);

extern int of_bsn_shell_output_OF_VERSION_1_0_populate(
    of_bsn_shell_output_t *obj, int value);
extern int of_bsn_shell_output_OF_VERSION_1_0_check(
    of_bsn_shell_output_t *obj, int value);
extern int of_bsn_shell_output_OF_VERSION_1_0_populate_scalars(
    of_bsn_shell_output_t *obj, int value);
extern int of_bsn_shell_output_OF_VERSION_1_0_check_scalars(
    of_bsn_shell_output_t *obj, int value);

extern int of_bsn_shell_status_OF_VERSION_1_0_populate(
    of_bsn_shell_status_t *obj, int value);
extern int of_bsn_shell_status_OF_VERSION_1_0_check(
    of_bsn_shell_status_t *obj, int value);
extern int of_bsn_shell_status_OF_VERSION_1_0_populate_scalars(
    of_bsn_shell_status_t *obj, int value);
extern int of_bsn_shell_status_OF_VERSION_1_0_check_scalars(
    of_bsn_shell_status_t *obj, int value);

extern int of_bsn_virtual_port_create_reply_OF_VERSION_1_0_populate(
    of_bsn_virtual_port_create_reply_t *obj, int value);
extern int of_bsn_virtual_port_create_reply_OF_VERSION_1_0_check(
    of_bsn_virtual_port_create_reply_t *obj, int value);
extern int of_bsn_virtual_port_create_reply_OF_VERSION_1_0_populate_scalars(
    of_bsn_virtual_port_create_reply_t *obj, int value);
extern int of_bsn_virtual_port_create_reply_OF_VERSION_1_0_check_scalars(
    of_bsn_virtual_port_create_reply_t *obj, int value);

extern int of_bsn_virtual_port_create_request_OF_VERSION_1_0_populate(
    of_bsn_virtual_port_create_request_t *obj, int value);
extern int of_bsn_virtual_port_create_request_OF_VERSION_1_0_check(
    of_bsn_virtual_port_create_request_t *obj, int value);
extern int of_bsn_virtual_port_create_request_OF_VERSION_1_0_populate_scalars(
    of_bsn_virtual_port_create_request_t *obj, int value);
extern int of_bsn_virtual_port_create_request_OF_VERSION_1_0_check_scalars(
    of_bsn_virtual_port_create_request_t *obj, int value);

extern int of_bsn_virtual_port_remove_reply_OF_VERSION_1_0_populate(
    of_bsn_virtual_port_remove_reply_t *obj, int value);
extern int of_bsn_virtual_port_remove_reply_OF_VERSION_1_0_check(
    of_bsn_virtual_port_remove_reply_t *obj, int value);
extern int of_bsn_virtual_port_remove_reply_OF_VERSION_1_0_populate_scalars(
    of_bsn_virtual_port_remove_reply_t *obj, int value);
extern int of_bsn_virtual_port_remove_reply_OF_VERSION_1_0_check_scalars(
    of_bsn_virtual_port_remove_reply_t *obj, int value);

extern int of_bsn_virtual_port_remove_request_OF_VERSION_1_0_populate(
    of_bsn_virtual_port_remove_request_t *obj, int value);
extern int of_bsn_virtual_port_remove_request_OF_VERSION_1_0_check(
    of_bsn_virtual_port_remove_request_t *obj, int value);
extern int of_bsn_virtual_port_remove_request_OF_VERSION_1_0_populate_scalars(
    of_bsn_virtual_port_remove_request_t *obj, int value);
extern int of_bsn_virtual_port_remove_request_OF_VERSION_1_0_check_scalars(
    of_bsn_virtual_port_remove_request_t *obj, int value);

extern int of_desc_stats_reply_OF_VERSION_1_0_populate(
    of_desc_stats_reply_t *obj, int value);
extern int of_desc_stats_reply_OF_VERSION_1_0_check(
    of_desc_stats_reply_t *obj, int value);
extern int of_desc_stats_reply_OF_VERSION_1_0_populate_scalars(
    of_desc_stats_reply_t *obj, int value);
extern int of_desc_stats_reply_OF_VERSION_1_0_check_scalars(
    of_desc_stats_reply_t *obj, int value);

extern int of_desc_stats_request_OF_VERSION_1_0_populate(
    of_desc_stats_request_t *obj, int value);
extern int of_desc_stats_request_OF_VERSION_1_0_check(
    of_desc_stats_request_t *obj, int value);
extern int of_desc_stats_request_OF_VERSION_1_0_populate_scalars(
    of_desc_stats_request_t *obj, int value);
extern int of_desc_stats_request_OF_VERSION_1_0_check_scalars(
    of_desc_stats_request_t *obj, int value);

extern int of_echo_reply_OF_VERSION_1_0_populate(
    of_echo_reply_t *obj, int value);
extern int of_echo_reply_OF_VERSION_1_0_check(
    of_echo_reply_t *obj, int value);
extern int of_echo_reply_OF_VERSION_1_0_populate_scalars(
    of_echo_reply_t *obj, int value);
extern int of_echo_reply_OF_VERSION_1_0_check_scalars(
    of_echo_reply_t *obj, int value);

extern int of_echo_request_OF_VERSION_1_0_populate(
    of_echo_request_t *obj, int value);
extern int of_echo_request_OF_VERSION_1_0_check(
    of_echo_request_t *obj, int value);
extern int of_echo_request_OF_VERSION_1_0_populate_scalars(
    of_echo_request_t *obj, int value);
extern int of_echo_request_OF_VERSION_1_0_check_scalars(
    of_echo_request_t *obj, int value);

extern int of_features_reply_OF_VERSION_1_0_populate(
    of_features_reply_t *obj, int value);
extern int of_features_reply_OF_VERSION_1_0_check(
    of_features_reply_t *obj, int value);
extern int of_features_reply_OF_VERSION_1_0_populate_scalars(
    of_features_reply_t *obj, int value);
extern int of_features_reply_OF_VERSION_1_0_check_scalars(
    of_features_reply_t *obj, int value);

extern int of_features_request_OF_VERSION_1_0_populate(
    of_features_request_t *obj, int value);
extern int of_features_request_OF_VERSION_1_0_check(
    of_features_request_t *obj, int value);
extern int of_features_request_OF_VERSION_1_0_populate_scalars(
    of_features_request_t *obj, int value);
extern int of_features_request_OF_VERSION_1_0_check_scalars(
    of_features_request_t *obj, int value);

extern int of_flow_add_OF_VERSION_1_0_populate(
    of_flow_add_t *obj, int value);
extern int of_flow_add_OF_VERSION_1_0_check(
    of_flow_add_t *obj, int value);
extern int of_flow_add_OF_VERSION_1_0_populate_scalars(
    of_flow_add_t *obj, int value);
extern int of_flow_add_OF_VERSION_1_0_check_scalars(
    of_flow_add_t *obj, int value);

extern int of_flow_delete_OF_VERSION_1_0_populate(
    of_flow_delete_t *obj, int value);
extern int of_flow_delete_OF_VERSION_1_0_check(
    of_flow_delete_t *obj, int value);
extern int of_flow_delete_OF_VERSION_1_0_populate_scalars(
    of_flow_delete_t *obj, int value);
extern int of_flow_delete_OF_VERSION_1_0_check_scalars(
    of_flow_delete_t *obj, int value);

extern int of_flow_delete_strict_OF_VERSION_1_0_populate(
    of_flow_delete_strict_t *obj, int value);
extern int of_flow_delete_strict_OF_VERSION_1_0_check(
    of_flow_delete_strict_t *obj, int value);
extern int of_flow_delete_strict_OF_VERSION_1_0_populate_scalars(
    of_flow_delete_strict_t *obj, int value);
extern int of_flow_delete_strict_OF_VERSION_1_0_check_scalars(
    of_flow_delete_strict_t *obj, int value);

extern int of_flow_mod_failed_error_msg_OF_VERSION_1_0_populate(
    of_flow_mod_failed_error_msg_t *obj, int value);
extern int of_flow_mod_failed_error_msg_OF_VERSION_1_0_check(
    of_flow_mod_failed_error_msg_t *obj, int value);
extern int of_flow_mod_failed_error_msg_OF_VERSION_1_0_populate_scalars(
    of_flow_mod_failed_error_msg_t *obj, int value);
extern int of_flow_mod_failed_error_msg_OF_VERSION_1_0_check_scalars(
    of_flow_mod_failed_error_msg_t *obj, int value);

extern int of_flow_modify_OF_VERSION_1_0_populate(
    of_flow_modify_t *obj, int value);
extern int of_flow_modify_OF_VERSION_1_0_check(
    of_flow_modify_t *obj, int value);
extern int of_flow_modify_OF_VERSION_1_0_populate_scalars(
    of_flow_modify_t *obj, int value);
extern int of_flow_modify_OF_VERSION_1_0_check_scalars(
    of_flow_modify_t *obj, int value);

extern int of_flow_modify_strict_OF_VERSION_1_0_populate(
    of_flow_modify_strict_t *obj, int value);
extern int of_flow_modify_strict_OF_VERSION_1_0_check(
    of_flow_modify_strict_t *obj, int value);
extern int of_flow_modify_strict_OF_VERSION_1_0_populate_scalars(
    of_flow_modify_strict_t *obj, int value);
extern int of_flow_modify_strict_OF_VERSION_1_0_check_scalars(
    of_flow_modify_strict_t *obj, int value);

extern int of_flow_removed_OF_VERSION_1_0_populate(
    of_flow_removed_t *obj, int value);
extern int of_flow_removed_OF_VERSION_1_0_check(
    of_flow_removed_t *obj, int value);
extern int of_flow_removed_OF_VERSION_1_0_populate_scalars(
    of_flow_removed_t *obj, int value);
extern int of_flow_removed_OF_VERSION_1_0_check_scalars(
    of_flow_removed_t *obj, int value);

extern int of_flow_stats_reply_OF_VERSION_1_0_populate(
    of_flow_stats_reply_t *obj, int value);
extern int of_flow_stats_reply_OF_VERSION_1_0_check(
    of_flow_stats_reply_t *obj, int value);
extern int of_flow_stats_reply_OF_VERSION_1_0_populate_scalars(
    of_flow_stats_reply_t *obj, int value);
extern int of_flow_stats_reply_OF_VERSION_1_0_check_scalars(
    of_flow_stats_reply_t *obj, int value);

extern int of_flow_stats_request_OF_VERSION_1_0_populate(
    of_flow_stats_request_t *obj, int value);
extern int of_flow_stats_request_OF_VERSION_1_0_check(
    of_flow_stats_request_t *obj, int value);
extern int of_flow_stats_request_OF_VERSION_1_0_populate_scalars(
    of_flow_stats_request_t *obj, int value);
extern int of_flow_stats_request_OF_VERSION_1_0_check_scalars(
    of_flow_stats_request_t *obj, int value);

extern int of_get_config_reply_OF_VERSION_1_0_populate(
    of_get_config_reply_t *obj, int value);
extern int of_get_config_reply_OF_VERSION_1_0_check(
    of_get_config_reply_t *obj, int value);
extern int of_get_config_reply_OF_VERSION_1_0_populate_scalars(
    of_get_config_reply_t *obj, int value);
extern int of_get_config_reply_OF_VERSION_1_0_check_scalars(
    of_get_config_reply_t *obj, int value);

extern int of_get_config_request_OF_VERSION_1_0_populate(
    of_get_config_request_t *obj, int value);
extern int of_get_config_request_OF_VERSION_1_0_check(
    of_get_config_request_t *obj, int value);
extern int of_get_config_request_OF_VERSION_1_0_populate_scalars(
    of_get_config_request_t *obj, int value);
extern int of_get_config_request_OF_VERSION_1_0_check_scalars(
    of_get_config_request_t *obj, int value);

extern int of_hello_OF_VERSION_1_0_populate(
    of_hello_t *obj, int value);
extern int of_hello_OF_VERSION_1_0_check(
    of_hello_t *obj, int value);
extern int of_hello_OF_VERSION_1_0_populate_scalars(
    of_hello_t *obj, int value);
extern int of_hello_OF_VERSION_1_0_check_scalars(
    of_hello_t *obj, int value);

extern int of_hello_failed_error_msg_OF_VERSION_1_0_populate(
    of_hello_failed_error_msg_t *obj, int value);
extern int of_hello_failed_error_msg_OF_VERSION_1_0_check(
    of_hello_failed_error_msg_t *obj, int value);
extern int of_hello_failed_error_msg_OF_VERSION_1_0_populate_scalars(
    of_hello_failed_error_msg_t *obj, int value);
extern int of_hello_failed_error_msg_OF_VERSION_1_0_check_scalars(
    of_hello_failed_error_msg_t *obj, int value);

extern int of_nicira_controller_role_reply_OF_VERSION_1_0_populate(
    of_nicira_controller_role_reply_t *obj, int value);
extern int of_nicira_controller_role_reply_OF_VERSION_1_0_check(
    of_nicira_controller_role_reply_t *obj, int value);
extern int of_nicira_controller_role_reply_OF_VERSION_1_0_populate_scalars(
    of_nicira_controller_role_reply_t *obj, int value);
extern int of_nicira_controller_role_reply_OF_VERSION_1_0_check_scalars(
    of_nicira_controller_role_reply_t *obj, int value);

extern int of_nicira_controller_role_request_OF_VERSION_1_0_populate(
    of_nicira_controller_role_request_t *obj, int value);
extern int of_nicira_controller_role_request_OF_VERSION_1_0_check(
    of_nicira_controller_role_request_t *obj, int value);
extern int of_nicira_controller_role_request_OF_VERSION_1_0_populate_scalars(
    of_nicira_controller_role_request_t *obj, int value);
extern int of_nicira_controller_role_request_OF_VERSION_1_0_check_scalars(
    of_nicira_controller_role_request_t *obj, int value);

extern int of_packet_in_OF_VERSION_1_0_populate(
    of_packet_in_t *obj, int value);
extern int of_packet_in_OF_VERSION_1_0_check(
    of_packet_in_t *obj, int value);
extern int of_packet_in_OF_VERSION_1_0_populate_scalars(
    of_packet_in_t *obj, int value);
extern int of_packet_in_OF_VERSION_1_0_check_scalars(
    of_packet_in_t *obj, int value);

extern int of_packet_out_OF_VERSION_1_0_populate(
    of_packet_out_t *obj, int value);
extern int of_packet_out_OF_VERSION_1_0_check(
    of_packet_out_t *obj, int value);
extern int of_packet_out_OF_VERSION_1_0_populate_scalars(
    of_packet_out_t *obj, int value);
extern int of_packet_out_OF_VERSION_1_0_check_scalars(
    of_packet_out_t *obj, int value);

extern int of_port_mod_OF_VERSION_1_0_populate(
    of_port_mod_t *obj, int value);
extern int of_port_mod_OF_VERSION_1_0_check(
    of_port_mod_t *obj, int value);
extern int of_port_mod_OF_VERSION_1_0_populate_scalars(
    of_port_mod_t *obj, int value);
extern int of_port_mod_OF_VERSION_1_0_check_scalars(
    of_port_mod_t *obj, int value);

extern int of_port_mod_failed_error_msg_OF_VERSION_1_0_populate(
    of_port_mod_failed_error_msg_t *obj, int value);
extern int of_port_mod_failed_error_msg_OF_VERSION_1_0_check(
    of_port_mod_failed_error_msg_t *obj, int value);
extern int of_port_mod_failed_error_msg_OF_VERSION_1_0_populate_scalars(
    of_port_mod_failed_error_msg_t *obj, int value);
extern int of_port_mod_failed_error_msg_OF_VERSION_1_0_check_scalars(
    of_port_mod_failed_error_msg_t *obj, int value);

extern int of_port_stats_reply_OF_VERSION_1_0_populate(
    of_port_stats_reply_t *obj, int value);
extern int of_port_stats_reply_OF_VERSION_1_0_check(
    of_port_stats_reply_t *obj, int value);
extern int of_port_stats_reply_OF_VERSION_1_0_populate_scalars(
    of_port_stats_reply_t *obj, int value);
extern int of_port_stats_reply_OF_VERSION_1_0_check_scalars(
    of_port_stats_reply_t *obj, int value);

extern int of_port_stats_request_OF_VERSION_1_0_populate(
    of_port_stats_request_t *obj, int value);
extern int of_port_stats_request_OF_VERSION_1_0_check(
    of_port_stats_request_t *obj, int value);
extern int of_port_stats_request_OF_VERSION_1_0_populate_scalars(
    of_port_stats_request_t *obj, int value);
extern int of_port_stats_request_OF_VERSION_1_0_check_scalars(
    of_port_stats_request_t *obj, int value);

extern int of_port_status_OF_VERSION_1_0_populate(
    of_port_status_t *obj, int value);
extern int of_port_status_OF_VERSION_1_0_check(
    of_port_status_t *obj, int value);
extern int of_port_status_OF_VERSION_1_0_populate_scalars(
    of_port_status_t *obj, int value);
extern int of_port_status_OF_VERSION_1_0_check_scalars(
    of_port_status_t *obj, int value);

extern int of_queue_get_config_reply_OF_VERSION_1_0_populate(
    of_queue_get_config_reply_t *obj, int value);
extern int of_queue_get_config_reply_OF_VERSION_1_0_check(
    of_queue_get_config_reply_t *obj, int value);
extern int of_queue_get_config_reply_OF_VERSION_1_0_populate_scalars(
    of_queue_get_config_reply_t *obj, int value);
extern int of_queue_get_config_reply_OF_VERSION_1_0_check_scalars(
    of_queue_get_config_reply_t *obj, int value);

extern int of_queue_get_config_request_OF_VERSION_1_0_populate(
    of_queue_get_config_request_t *obj, int value);
extern int of_queue_get_config_request_OF_VERSION_1_0_check(
    of_queue_get_config_request_t *obj, int value);
extern int of_queue_get_config_request_OF_VERSION_1_0_populate_scalars(
    of_queue_get_config_request_t *obj, int value);
extern int of_queue_get_config_request_OF_VERSION_1_0_check_scalars(
    of_queue_get_config_request_t *obj, int value);

extern int of_queue_op_failed_error_msg_OF_VERSION_1_0_populate(
    of_queue_op_failed_error_msg_t *obj, int value);
extern int of_queue_op_failed_error_msg_OF_VERSION_1_0_check(
    of_queue_op_failed_error_msg_t *obj, int value);
extern int of_queue_op_failed_error_msg_OF_VERSION_1_0_populate_scalars(
    of_queue_op_failed_error_msg_t *obj, int value);
extern int of_queue_op_failed_error_msg_OF_VERSION_1_0_check_scalars(
    of_queue_op_failed_error_msg_t *obj, int value);

extern int of_queue_stats_reply_OF_VERSION_1_0_populate(
    of_queue_stats_reply_t *obj, int value);
extern int of_queue_stats_reply_OF_VERSION_1_0_check(
    of_queue_stats_reply_t *obj, int value);
extern int of_queue_stats_reply_OF_VERSION_1_0_populate_scalars(
    of_queue_stats_reply_t *obj, int value);
extern int of_queue_stats_reply_OF_VERSION_1_0_check_scalars(
    of_queue_stats_reply_t *obj, int value);

extern int of_queue_stats_request_OF_VERSION_1_0_populate(
    of_queue_stats_request_t *obj, int value);
extern int of_queue_stats_request_OF_VERSION_1_0_check(
    of_queue_stats_request_t *obj, int value);
extern int of_queue_stats_request_OF_VERSION_1_0_populate_scalars(
    of_queue_stats_request_t *obj, int value);
extern int of_queue_stats_request_OF_VERSION_1_0_check_scalars(
    of_queue_stats_request_t *obj, int value);

extern int of_set_config_OF_VERSION_1_0_populate(
    of_set_config_t *obj, int value);
extern int of_set_config_OF_VERSION_1_0_check(
    of_set_config_t *obj, int value);
extern int of_set_config_OF_VERSION_1_0_populate_scalars(
    of_set_config_t *obj, int value);
extern int of_set_config_OF_VERSION_1_0_check_scalars(
    of_set_config_t *obj, int value);

extern int of_table_mod_OF_VERSION_1_0_populate(
    of_table_mod_t *obj, int value);
extern int of_table_mod_OF_VERSION_1_0_check(
    of_table_mod_t *obj, int value);
extern int of_table_mod_OF_VERSION_1_0_populate_scalars(
    of_table_mod_t *obj, int value);
extern int of_table_mod_OF_VERSION_1_0_check_scalars(
    of_table_mod_t *obj, int value);

extern int of_table_stats_reply_OF_VERSION_1_0_populate(
    of_table_stats_reply_t *obj, int value);
extern int of_table_stats_reply_OF_VERSION_1_0_check(
    of_table_stats_reply_t *obj, int value);
extern int of_table_stats_reply_OF_VERSION_1_0_populate_scalars(
    of_table_stats_reply_t *obj, int value);
extern int of_table_stats_reply_OF_VERSION_1_0_check_scalars(
    of_table_stats_reply_t *obj, int value);

extern int of_table_stats_request_OF_VERSION_1_0_populate(
    of_table_stats_request_t *obj, int value);
extern int of_table_stats_request_OF_VERSION_1_0_check(
    of_table_stats_request_t *obj, int value);
extern int of_table_stats_request_OF_VERSION_1_0_populate_scalars(
    of_table_stats_request_t *obj, int value);
extern int of_table_stats_request_OF_VERSION_1_0_check_scalars(
    of_table_stats_request_t *obj, int value);

extern int of_action_bsn_checksum_OF_VERSION_1_0_populate(
    of_action_bsn_checksum_t *obj, int value);
extern int of_action_bsn_checksum_OF_VERSION_1_0_check(
    of_action_bsn_checksum_t *obj, int value);
extern int of_action_bsn_checksum_OF_VERSION_1_0_populate_scalars(
    of_action_bsn_checksum_t *obj, int value);
extern int of_action_bsn_checksum_OF_VERSION_1_0_check_scalars(
    of_action_bsn_checksum_t *obj, int value);

extern int of_action_bsn_mirror_OF_VERSION_1_0_populate(
    of_action_bsn_mirror_t *obj, int value);
extern int of_action_bsn_mirror_OF_VERSION_1_0_check(
    of_action_bsn_mirror_t *obj, int value);
extern int of_action_bsn_mirror_OF_VERSION_1_0_populate_scalars(
    of_action_bsn_mirror_t *obj, int value);
extern int of_action_bsn_mirror_OF_VERSION_1_0_check_scalars(
    of_action_bsn_mirror_t *obj, int value);

extern int of_action_bsn_set_tunnel_dst_OF_VERSION_1_0_populate(
    of_action_bsn_set_tunnel_dst_t *obj, int value);
extern int of_action_bsn_set_tunnel_dst_OF_VERSION_1_0_check(
    of_action_bsn_set_tunnel_dst_t *obj, int value);
extern int of_action_bsn_set_tunnel_dst_OF_VERSION_1_0_populate_scalars(
    of_action_bsn_set_tunnel_dst_t *obj, int value);
extern int of_action_bsn_set_tunnel_dst_OF_VERSION_1_0_check_scalars(
    of_action_bsn_set_tunnel_dst_t *obj, int value);

extern int of_action_enqueue_OF_VERSION_1_0_populate(
    of_action_enqueue_t *obj, int value);
extern int of_action_enqueue_OF_VERSION_1_0_check(
    of_action_enqueue_t *obj, int value);
extern int of_action_enqueue_OF_VERSION_1_0_populate_scalars(
    of_action_enqueue_t *obj, int value);
extern int of_action_enqueue_OF_VERSION_1_0_check_scalars(
    of_action_enqueue_t *obj, int value);

extern int of_action_nicira_dec_ttl_OF_VERSION_1_0_populate(
    of_action_nicira_dec_ttl_t *obj, int value);
extern int of_action_nicira_dec_ttl_OF_VERSION_1_0_check(
    of_action_nicira_dec_ttl_t *obj, int value);
extern int of_action_nicira_dec_ttl_OF_VERSION_1_0_populate_scalars(
    of_action_nicira_dec_ttl_t *obj, int value);
extern int of_action_nicira_dec_ttl_OF_VERSION_1_0_check_scalars(
    of_action_nicira_dec_ttl_t *obj, int value);

extern int of_action_output_OF_VERSION_1_0_populate(
    of_action_output_t *obj, int value);
extern int of_action_output_OF_VERSION_1_0_check(
    of_action_output_t *obj, int value);
extern int of_action_output_OF_VERSION_1_0_populate_scalars(
    of_action_output_t *obj, int value);
extern int of_action_output_OF_VERSION_1_0_check_scalars(
    of_action_output_t *obj, int value);

extern int of_action_set_dl_dst_OF_VERSION_1_0_populate(
    of_action_set_dl_dst_t *obj, int value);
extern int of_action_set_dl_dst_OF_VERSION_1_0_check(
    of_action_set_dl_dst_t *obj, int value);
extern int of_action_set_dl_dst_OF_VERSION_1_0_populate_scalars(
    of_action_set_dl_dst_t *obj, int value);
extern int of_action_set_dl_dst_OF_VERSION_1_0_check_scalars(
    of_action_set_dl_dst_t *obj, int value);

extern int of_action_set_dl_src_OF_VERSION_1_0_populate(
    of_action_set_dl_src_t *obj, int value);
extern int of_action_set_dl_src_OF_VERSION_1_0_check(
    of_action_set_dl_src_t *obj, int value);
extern int of_action_set_dl_src_OF_VERSION_1_0_populate_scalars(
    of_action_set_dl_src_t *obj, int value);
extern int of_action_set_dl_src_OF_VERSION_1_0_check_scalars(
    of_action_set_dl_src_t *obj, int value);

extern int of_action_set_nw_dst_OF_VERSION_1_0_populate(
    of_action_set_nw_dst_t *obj, int value);
extern int of_action_set_nw_dst_OF_VERSION_1_0_check(
    of_action_set_nw_dst_t *obj, int value);
extern int of_action_set_nw_dst_OF_VERSION_1_0_populate_scalars(
    of_action_set_nw_dst_t *obj, int value);
extern int of_action_set_nw_dst_OF_VERSION_1_0_check_scalars(
    of_action_set_nw_dst_t *obj, int value);

extern int of_action_set_nw_src_OF_VERSION_1_0_populate(
    of_action_set_nw_src_t *obj, int value);
extern int of_action_set_nw_src_OF_VERSION_1_0_check(
    of_action_set_nw_src_t *obj, int value);
extern int of_action_set_nw_src_OF_VERSION_1_0_populate_scalars(
    of_action_set_nw_src_t *obj, int value);
extern int of_action_set_nw_src_OF_VERSION_1_0_check_scalars(
    of_action_set_nw_src_t *obj, int value);

extern int of_action_set_nw_tos_OF_VERSION_1_0_populate(
    of_action_set_nw_tos_t *obj, int value);
extern int of_action_set_nw_tos_OF_VERSION_1_0_check(
    of_action_set_nw_tos_t *obj, int value);
extern int of_action_set_nw_tos_OF_VERSION_1_0_populate_scalars(
    of_action_set_nw_tos_t *obj, int value);
extern int of_action_set_nw_tos_OF_VERSION_1_0_check_scalars(
    of_action_set_nw_tos_t *obj, int value);

extern int of_action_set_tp_dst_OF_VERSION_1_0_populate(
    of_action_set_tp_dst_t *obj, int value);
extern int of_action_set_tp_dst_OF_VERSION_1_0_check(
    of_action_set_tp_dst_t *obj, int value);
extern int of_action_set_tp_dst_OF_VERSION_1_0_populate_scalars(
    of_action_set_tp_dst_t *obj, int value);
extern int of_action_set_tp_dst_OF_VERSION_1_0_check_scalars(
    of_action_set_tp_dst_t *obj, int value);

extern int of_action_set_tp_src_OF_VERSION_1_0_populate(
    of_action_set_tp_src_t *obj, int value);
extern int of_action_set_tp_src_OF_VERSION_1_0_check(
    of_action_set_tp_src_t *obj, int value);
extern int of_action_set_tp_src_OF_VERSION_1_0_populate_scalars(
    of_action_set_tp_src_t *obj, int value);
extern int of_action_set_tp_src_OF_VERSION_1_0_check_scalars(
    of_action_set_tp_src_t *obj, int value);

extern int of_action_set_vlan_pcp_OF_VERSION_1_0_populate(
    of_action_set_vlan_pcp_t *obj, int value);
extern int of_action_set_vlan_pcp_OF_VERSION_1_0_check(
    of_action_set_vlan_pcp_t *obj, int value);
extern int of_action_set_vlan_pcp_OF_VERSION_1_0_populate_scalars(
    of_action_set_vlan_pcp_t *obj, int value);
extern int of_action_set_vlan_pcp_OF_VERSION_1_0_check_scalars(
    of_action_set_vlan_pcp_t *obj, int value);

extern int of_action_set_vlan_vid_OF_VERSION_1_0_populate(
    of_action_set_vlan_vid_t *obj, int value);
extern int of_action_set_vlan_vid_OF_VERSION_1_0_check(
    of_action_set_vlan_vid_t *obj, int value);
extern int of_action_set_vlan_vid_OF_VERSION_1_0_populate_scalars(
    of_action_set_vlan_vid_t *obj, int value);
extern int of_action_set_vlan_vid_OF_VERSION_1_0_check_scalars(
    of_action_set_vlan_vid_t *obj, int value);

extern int of_action_strip_vlan_OF_VERSION_1_0_populate(
    of_action_strip_vlan_t *obj, int value);
extern int of_action_strip_vlan_OF_VERSION_1_0_check(
    of_action_strip_vlan_t *obj, int value);
extern int of_action_strip_vlan_OF_VERSION_1_0_populate_scalars(
    of_action_strip_vlan_t *obj, int value);
extern int of_action_strip_vlan_OF_VERSION_1_0_check_scalars(
    of_action_strip_vlan_t *obj, int value);

extern int of_bsn_interface_OF_VERSION_1_0_populate(
    of_bsn_interface_t *obj, int value);
extern int of_bsn_interface_OF_VERSION_1_0_check(
    of_bsn_interface_t *obj, int value);
extern int of_bsn_interface_OF_VERSION_1_0_populate_scalars(
    of_bsn_interface_t *obj, int value);
extern int of_bsn_interface_OF_VERSION_1_0_check_scalars(
    of_bsn_interface_t *obj, int value);

extern int of_bsn_vport_l2gre_OF_VERSION_1_0_populate(
    of_bsn_vport_l2gre_t *obj, int value);
extern int of_bsn_vport_l2gre_OF_VERSION_1_0_check(
    of_bsn_vport_l2gre_t *obj, int value);
extern int of_bsn_vport_l2gre_OF_VERSION_1_0_populate_scalars(
    of_bsn_vport_l2gre_t *obj, int value);
extern int of_bsn_vport_l2gre_OF_VERSION_1_0_check_scalars(
    of_bsn_vport_l2gre_t *obj, int value);

extern int of_bsn_vport_q_in_q_OF_VERSION_1_0_populate(
    of_bsn_vport_q_in_q_t *obj, int value);
extern int of_bsn_vport_q_in_q_OF_VERSION_1_0_check(
    of_bsn_vport_q_in_q_t *obj, int value);
extern int of_bsn_vport_q_in_q_OF_VERSION_1_0_populate_scalars(
    of_bsn_vport_q_in_q_t *obj, int value);
extern int of_bsn_vport_q_in_q_OF_VERSION_1_0_check_scalars(
    of_bsn_vport_q_in_q_t *obj, int value);

extern int of_flow_stats_entry_OF_VERSION_1_0_populate(
    of_flow_stats_entry_t *obj, int value);
extern int of_flow_stats_entry_OF_VERSION_1_0_check(
    of_flow_stats_entry_t *obj, int value);
extern int of_flow_stats_entry_OF_VERSION_1_0_populate_scalars(
    of_flow_stats_entry_t *obj, int value);
extern int of_flow_stats_entry_OF_VERSION_1_0_check_scalars(
    of_flow_stats_entry_t *obj, int value);

extern int of_match_v1_OF_VERSION_1_0_populate(
    of_match_v1_t *obj, int value);
extern int of_match_v1_OF_VERSION_1_0_check(
    of_match_v1_t *obj, int value);
extern int of_match_v1_OF_VERSION_1_0_populate_scalars(
    of_match_v1_t *obj, int value);
extern int of_match_v1_OF_VERSION_1_0_check_scalars(
    of_match_v1_t *obj, int value);

extern int of_packet_queue_OF_VERSION_1_0_populate(
    of_packet_queue_t *obj, int value);
extern int of_packet_queue_OF_VERSION_1_0_check(
    of_packet_queue_t *obj, int value);
extern int of_packet_queue_OF_VERSION_1_0_populate_scalars(
    of_packet_queue_t *obj, int value);
extern int of_packet_queue_OF_VERSION_1_0_check_scalars(
    of_packet_queue_t *obj, int value);

extern int of_port_desc_OF_VERSION_1_0_populate(
    of_port_desc_t *obj, int value);
extern int of_port_desc_OF_VERSION_1_0_check(
    of_port_desc_t *obj, int value);
extern int of_port_desc_OF_VERSION_1_0_populate_scalars(
    of_port_desc_t *obj, int value);
extern int of_port_desc_OF_VERSION_1_0_check_scalars(
    of_port_desc_t *obj, int value);

extern int of_port_stats_entry_OF_VERSION_1_0_populate(
    of_port_stats_entry_t *obj, int value);
extern int of_port_stats_entry_OF_VERSION_1_0_check(
    of_port_stats_entry_t *obj, int value);
extern int of_port_stats_entry_OF_VERSION_1_0_populate_scalars(
    of_port_stats_entry_t *obj, int value);
extern int of_port_stats_entry_OF_VERSION_1_0_check_scalars(
    of_port_stats_entry_t *obj, int value);

extern int of_queue_prop_min_rate_OF_VERSION_1_0_populate(
    of_queue_prop_min_rate_t *obj, int value);
extern int of_queue_prop_min_rate_OF_VERSION_1_0_check(
    of_queue_prop_min_rate_t *obj, int value);
extern int of_queue_prop_min_rate_OF_VERSION_1_0_populate_scalars(
    of_queue_prop_min_rate_t *obj, int value);
extern int of_queue_prop_min_rate_OF_VERSION_1_0_check_scalars(
    of_queue_prop_min_rate_t *obj, int value);

extern int of_queue_stats_entry_OF_VERSION_1_0_populate(
    of_queue_stats_entry_t *obj, int value);
extern int of_queue_stats_entry_OF_VERSION_1_0_check(
    of_queue_stats_entry_t *obj, int value);
extern int of_queue_stats_entry_OF_VERSION_1_0_populate_scalars(
    of_queue_stats_entry_t *obj, int value);
extern int of_queue_stats_entry_OF_VERSION_1_0_check_scalars(
    of_queue_stats_entry_t *obj, int value);

extern int of_table_stats_entry_OF_VERSION_1_0_populate(
    of_table_stats_entry_t *obj, int value);
extern int of_table_stats_entry_OF_VERSION_1_0_check(
    of_table_stats_entry_t *obj, int value);
extern int of_table_stats_entry_OF_VERSION_1_0_populate_scalars(
    of_table_stats_entry_t *obj, int value);
extern int of_table_stats_entry_OF_VERSION_1_0_check_scalars(
    of_table_stats_entry_t *obj, int value);

extern int of_list_action_OF_VERSION_1_0_populate(
    of_list_action_t *obj, int value);
extern int of_list_action_OF_VERSION_1_0_check(
    of_list_action_t *obj, int value);
extern int of_list_action_OF_VERSION_1_0_populate_scalars(
    of_list_action_t *obj, int value);
extern int of_list_action_OF_VERSION_1_0_check_scalars(
    of_list_action_t *obj, int value);

extern int of_list_bsn_interface_OF_VERSION_1_0_populate(
    of_list_bsn_interface_t *obj, int value);
extern int of_list_bsn_interface_OF_VERSION_1_0_check(
    of_list_bsn_interface_t *obj, int value);
extern int of_list_bsn_interface_OF_VERSION_1_0_populate_scalars(
    of_list_bsn_interface_t *obj, int value);
extern int of_list_bsn_interface_OF_VERSION_1_0_check_scalars(
    of_list_bsn_interface_t *obj, int value);

extern int of_list_flow_stats_entry_OF_VERSION_1_0_populate(
    of_list_flow_stats_entry_t *obj, int value);
extern int of_list_flow_stats_entry_OF_VERSION_1_0_check(
    of_list_flow_stats_entry_t *obj, int value);
extern int of_list_flow_stats_entry_OF_VERSION_1_0_populate_scalars(
    of_list_flow_stats_entry_t *obj, int value);
extern int of_list_flow_stats_entry_OF_VERSION_1_0_check_scalars(
    of_list_flow_stats_entry_t *obj, int value);

extern int of_list_packet_queue_OF_VERSION_1_0_populate(
    of_list_packet_queue_t *obj, int value);
extern int of_list_packet_queue_OF_VERSION_1_0_check(
    of_list_packet_queue_t *obj, int value);
extern int of_list_packet_queue_OF_VERSION_1_0_populate_scalars(
    of_list_packet_queue_t *obj, int value);
extern int of_list_packet_queue_OF_VERSION_1_0_check_scalars(
    of_list_packet_queue_t *obj, int value);

extern int of_list_port_desc_OF_VERSION_1_0_populate(
    of_list_port_desc_t *obj, int value);
extern int of_list_port_desc_OF_VERSION_1_0_check(
    of_list_port_desc_t *obj, int value);
extern int of_list_port_desc_OF_VERSION_1_0_populate_scalars(
    of_list_port_desc_t *obj, int value);
extern int of_list_port_desc_OF_VERSION_1_0_check_scalars(
    of_list_port_desc_t *obj, int value);

extern int of_list_port_stats_entry_OF_VERSION_1_0_populate(
    of_list_port_stats_entry_t *obj, int value);
extern int of_list_port_stats_entry_OF_VERSION_1_0_check(
    of_list_port_stats_entry_t *obj, int value);
extern int of_list_port_stats_entry_OF_VERSION_1_0_populate_scalars(
    of_list_port_stats_entry_t *obj, int value);
extern int of_list_port_stats_entry_OF_VERSION_1_0_check_scalars(
    of_list_port_stats_entry_t *obj, int value);

extern int of_list_queue_prop_OF_VERSION_1_0_populate(
    of_list_queue_prop_t *obj, int value);
extern int of_list_queue_prop_OF_VERSION_1_0_check(
    of_list_queue_prop_t *obj, int value);
extern int of_list_queue_prop_OF_VERSION_1_0_populate_scalars(
    of_list_queue_prop_t *obj, int value);
extern int of_list_queue_prop_OF_VERSION_1_0_check_scalars(
    of_list_queue_prop_t *obj, int value);

extern int of_list_queue_stats_entry_OF_VERSION_1_0_populate(
    of_list_queue_stats_entry_t *obj, int value);
extern int of_list_queue_stats_entry_OF_VERSION_1_0_check(
    of_list_queue_stats_entry_t *obj, int value);
extern int of_list_queue_stats_entry_OF_VERSION_1_0_populate_scalars(
    of_list_queue_stats_entry_t *obj, int value);
extern int of_list_queue_stats_entry_OF_VERSION_1_0_check_scalars(
    of_list_queue_stats_entry_t *obj, int value);

extern int of_list_table_stats_entry_OF_VERSION_1_0_populate(
    of_list_table_stats_entry_t *obj, int value);
extern int of_list_table_stats_entry_OF_VERSION_1_0_check(
    of_list_table_stats_entry_t *obj, int value);
extern int of_list_table_stats_entry_OF_VERSION_1_0_populate_scalars(
    of_list_table_stats_entry_t *obj, int value);
extern int of_list_table_stats_entry_OF_VERSION_1_0_check_scalars(
    of_list_table_stats_entry_t *obj, int value);

extern int of_aggregate_stats_reply_OF_VERSION_1_1_populate(
    of_aggregate_stats_reply_t *obj, int value);
extern int of_aggregate_stats_reply_OF_VERSION_1_1_check(
    of_aggregate_stats_reply_t *obj, int value);
extern int of_aggregate_stats_reply_OF_VERSION_1_1_populate_scalars(
    of_aggregate_stats_reply_t *obj, int value);
extern int of_aggregate_stats_reply_OF_VERSION_1_1_check_scalars(
    of_aggregate_stats_reply_t *obj, int value);

extern int of_aggregate_stats_request_OF_VERSION_1_1_populate(
    of_aggregate_stats_request_t *obj, int value);
extern int of_aggregate_stats_request_OF_VERSION_1_1_check(
    of_aggregate_stats_request_t *obj, int value);
extern int of_aggregate_stats_request_OF_VERSION_1_1_populate_scalars(
    of_aggregate_stats_request_t *obj, int value);
extern int of_aggregate_stats_request_OF_VERSION_1_1_check_scalars(
    of_aggregate_stats_request_t *obj, int value);

extern int of_bad_action_error_msg_OF_VERSION_1_1_populate(
    of_bad_action_error_msg_t *obj, int value);
extern int of_bad_action_error_msg_OF_VERSION_1_1_check(
    of_bad_action_error_msg_t *obj, int value);
extern int of_bad_action_error_msg_OF_VERSION_1_1_populate_scalars(
    of_bad_action_error_msg_t *obj, int value);
extern int of_bad_action_error_msg_OF_VERSION_1_1_check_scalars(
    of_bad_action_error_msg_t *obj, int value);

extern int of_bad_instruction_error_msg_OF_VERSION_1_1_populate(
    of_bad_instruction_error_msg_t *obj, int value);
extern int of_bad_instruction_error_msg_OF_VERSION_1_1_check(
    of_bad_instruction_error_msg_t *obj, int value);
extern int of_bad_instruction_error_msg_OF_VERSION_1_1_populate_scalars(
    of_bad_instruction_error_msg_t *obj, int value);
extern int of_bad_instruction_error_msg_OF_VERSION_1_1_check_scalars(
    of_bad_instruction_error_msg_t *obj, int value);

extern int of_bad_match_error_msg_OF_VERSION_1_1_populate(
    of_bad_match_error_msg_t *obj, int value);
extern int of_bad_match_error_msg_OF_VERSION_1_1_check(
    of_bad_match_error_msg_t *obj, int value);
extern int of_bad_match_error_msg_OF_VERSION_1_1_populate_scalars(
    of_bad_match_error_msg_t *obj, int value);
extern int of_bad_match_error_msg_OF_VERSION_1_1_check_scalars(
    of_bad_match_error_msg_t *obj, int value);

extern int of_bad_request_error_msg_OF_VERSION_1_1_populate(
    of_bad_request_error_msg_t *obj, int value);
extern int of_bad_request_error_msg_OF_VERSION_1_1_check(
    of_bad_request_error_msg_t *obj, int value);
extern int of_bad_request_error_msg_OF_VERSION_1_1_populate_scalars(
    of_bad_request_error_msg_t *obj, int value);
extern int of_bad_request_error_msg_OF_VERSION_1_1_check_scalars(
    of_bad_request_error_msg_t *obj, int value);

extern int of_barrier_reply_OF_VERSION_1_1_populate(
    of_barrier_reply_t *obj, int value);
extern int of_barrier_reply_OF_VERSION_1_1_check(
    of_barrier_reply_t *obj, int value);
extern int of_barrier_reply_OF_VERSION_1_1_populate_scalars(
    of_barrier_reply_t *obj, int value);
extern int of_barrier_reply_OF_VERSION_1_1_check_scalars(
    of_barrier_reply_t *obj, int value);

extern int of_barrier_request_OF_VERSION_1_1_populate(
    of_barrier_request_t *obj, int value);
extern int of_barrier_request_OF_VERSION_1_1_check(
    of_barrier_request_t *obj, int value);
extern int of_barrier_request_OF_VERSION_1_1_populate_scalars(
    of_barrier_request_t *obj, int value);
extern int of_barrier_request_OF_VERSION_1_1_check_scalars(
    of_barrier_request_t *obj, int value);

extern int of_bsn_bw_clear_data_reply_OF_VERSION_1_1_populate(
    of_bsn_bw_clear_data_reply_t *obj, int value);
extern int of_bsn_bw_clear_data_reply_OF_VERSION_1_1_check(
    of_bsn_bw_clear_data_reply_t *obj, int value);
extern int of_bsn_bw_clear_data_reply_OF_VERSION_1_1_populate_scalars(
    of_bsn_bw_clear_data_reply_t *obj, int value);
extern int of_bsn_bw_clear_data_reply_OF_VERSION_1_1_check_scalars(
    of_bsn_bw_clear_data_reply_t *obj, int value);

extern int of_bsn_bw_clear_data_request_OF_VERSION_1_1_populate(
    of_bsn_bw_clear_data_request_t *obj, int value);
extern int of_bsn_bw_clear_data_request_OF_VERSION_1_1_check(
    of_bsn_bw_clear_data_request_t *obj, int value);
extern int of_bsn_bw_clear_data_request_OF_VERSION_1_1_populate_scalars(
    of_bsn_bw_clear_data_request_t *obj, int value);
extern int of_bsn_bw_clear_data_request_OF_VERSION_1_1_check_scalars(
    of_bsn_bw_clear_data_request_t *obj, int value);

extern int of_bsn_bw_enable_get_reply_OF_VERSION_1_1_populate(
    of_bsn_bw_enable_get_reply_t *obj, int value);
extern int of_bsn_bw_enable_get_reply_OF_VERSION_1_1_check(
    of_bsn_bw_enable_get_reply_t *obj, int value);
extern int of_bsn_bw_enable_get_reply_OF_VERSION_1_1_populate_scalars(
    of_bsn_bw_enable_get_reply_t *obj, int value);
extern int of_bsn_bw_enable_get_reply_OF_VERSION_1_1_check_scalars(
    of_bsn_bw_enable_get_reply_t *obj, int value);

extern int of_bsn_bw_enable_get_request_OF_VERSION_1_1_populate(
    of_bsn_bw_enable_get_request_t *obj, int value);
extern int of_bsn_bw_enable_get_request_OF_VERSION_1_1_check(
    of_bsn_bw_enable_get_request_t *obj, int value);
extern int of_bsn_bw_enable_get_request_OF_VERSION_1_1_populate_scalars(
    of_bsn_bw_enable_get_request_t *obj, int value);
extern int of_bsn_bw_enable_get_request_OF_VERSION_1_1_check_scalars(
    of_bsn_bw_enable_get_request_t *obj, int value);

extern int of_bsn_bw_enable_set_reply_OF_VERSION_1_1_populate(
    of_bsn_bw_enable_set_reply_t *obj, int value);
extern int of_bsn_bw_enable_set_reply_OF_VERSION_1_1_check(
    of_bsn_bw_enable_set_reply_t *obj, int value);
extern int of_bsn_bw_enable_set_reply_OF_VERSION_1_1_populate_scalars(
    of_bsn_bw_enable_set_reply_t *obj, int value);
extern int of_bsn_bw_enable_set_reply_OF_VERSION_1_1_check_scalars(
    of_bsn_bw_enable_set_reply_t *obj, int value);

extern int of_bsn_bw_enable_set_request_OF_VERSION_1_1_populate(
    of_bsn_bw_enable_set_request_t *obj, int value);
extern int of_bsn_bw_enable_set_request_OF_VERSION_1_1_check(
    of_bsn_bw_enable_set_request_t *obj, int value);
extern int of_bsn_bw_enable_set_request_OF_VERSION_1_1_populate_scalars(
    of_bsn_bw_enable_set_request_t *obj, int value);
extern int of_bsn_bw_enable_set_request_OF_VERSION_1_1_check_scalars(
    of_bsn_bw_enable_set_request_t *obj, int value);

extern int of_bsn_get_interfaces_reply_OF_VERSION_1_1_populate(
    of_bsn_get_interfaces_reply_t *obj, int value);
extern int of_bsn_get_interfaces_reply_OF_VERSION_1_1_check(
    of_bsn_get_interfaces_reply_t *obj, int value);
extern int of_bsn_get_interfaces_reply_OF_VERSION_1_1_populate_scalars(
    of_bsn_get_interfaces_reply_t *obj, int value);
extern int of_bsn_get_interfaces_reply_OF_VERSION_1_1_check_scalars(
    of_bsn_get_interfaces_reply_t *obj, int value);

extern int of_bsn_get_interfaces_request_OF_VERSION_1_1_populate(
    of_bsn_get_interfaces_request_t *obj, int value);
extern int of_bsn_get_interfaces_request_OF_VERSION_1_1_check(
    of_bsn_get_interfaces_request_t *obj, int value);
extern int of_bsn_get_interfaces_request_OF_VERSION_1_1_populate_scalars(
    of_bsn_get_interfaces_request_t *obj, int value);
extern int of_bsn_get_interfaces_request_OF_VERSION_1_1_check_scalars(
    of_bsn_get_interfaces_request_t *obj, int value);

extern int of_bsn_get_mirroring_reply_OF_VERSION_1_1_populate(
    of_bsn_get_mirroring_reply_t *obj, int value);
extern int of_bsn_get_mirroring_reply_OF_VERSION_1_1_check(
    of_bsn_get_mirroring_reply_t *obj, int value);
extern int of_bsn_get_mirroring_reply_OF_VERSION_1_1_populate_scalars(
    of_bsn_get_mirroring_reply_t *obj, int value);
extern int of_bsn_get_mirroring_reply_OF_VERSION_1_1_check_scalars(
    of_bsn_get_mirroring_reply_t *obj, int value);

extern int of_bsn_get_mirroring_request_OF_VERSION_1_1_populate(
    of_bsn_get_mirroring_request_t *obj, int value);
extern int of_bsn_get_mirroring_request_OF_VERSION_1_1_check(
    of_bsn_get_mirroring_request_t *obj, int value);
extern int of_bsn_get_mirroring_request_OF_VERSION_1_1_populate_scalars(
    of_bsn_get_mirroring_request_t *obj, int value);
extern int of_bsn_get_mirroring_request_OF_VERSION_1_1_check_scalars(
    of_bsn_get_mirroring_request_t *obj, int value);

extern int of_bsn_pdu_rx_reply_OF_VERSION_1_1_populate(
    of_bsn_pdu_rx_reply_t *obj, int value);
extern int of_bsn_pdu_rx_reply_OF_VERSION_1_1_check(
    of_bsn_pdu_rx_reply_t *obj, int value);
extern int of_bsn_pdu_rx_reply_OF_VERSION_1_1_populate_scalars(
    of_bsn_pdu_rx_reply_t *obj, int value);
extern int of_bsn_pdu_rx_reply_OF_VERSION_1_1_check_scalars(
    of_bsn_pdu_rx_reply_t *obj, int value);

extern int of_bsn_pdu_rx_request_OF_VERSION_1_1_populate(
    of_bsn_pdu_rx_request_t *obj, int value);
extern int of_bsn_pdu_rx_request_OF_VERSION_1_1_check(
    of_bsn_pdu_rx_request_t *obj, int value);
extern int of_bsn_pdu_rx_request_OF_VERSION_1_1_populate_scalars(
    of_bsn_pdu_rx_request_t *obj, int value);
extern int of_bsn_pdu_rx_request_OF_VERSION_1_1_check_scalars(
    of_bsn_pdu_rx_request_t *obj, int value);

extern int of_bsn_pdu_rx_timeout_OF_VERSION_1_1_populate(
    of_bsn_pdu_rx_timeout_t *obj, int value);
extern int of_bsn_pdu_rx_timeout_OF_VERSION_1_1_check(
    of_bsn_pdu_rx_timeout_t *obj, int value);
extern int of_bsn_pdu_rx_timeout_OF_VERSION_1_1_populate_scalars(
    of_bsn_pdu_rx_timeout_t *obj, int value);
extern int of_bsn_pdu_rx_timeout_OF_VERSION_1_1_check_scalars(
    of_bsn_pdu_rx_timeout_t *obj, int value);

extern int of_bsn_pdu_tx_reply_OF_VERSION_1_1_populate(
    of_bsn_pdu_tx_reply_t *obj, int value);
extern int of_bsn_pdu_tx_reply_OF_VERSION_1_1_check(
    of_bsn_pdu_tx_reply_t *obj, int value);
extern int of_bsn_pdu_tx_reply_OF_VERSION_1_1_populate_scalars(
    of_bsn_pdu_tx_reply_t *obj, int value);
extern int of_bsn_pdu_tx_reply_OF_VERSION_1_1_check_scalars(
    of_bsn_pdu_tx_reply_t *obj, int value);

extern int of_bsn_pdu_tx_request_OF_VERSION_1_1_populate(
    of_bsn_pdu_tx_request_t *obj, int value);
extern int of_bsn_pdu_tx_request_OF_VERSION_1_1_check(
    of_bsn_pdu_tx_request_t *obj, int value);
extern int of_bsn_pdu_tx_request_OF_VERSION_1_1_populate_scalars(
    of_bsn_pdu_tx_request_t *obj, int value);
extern int of_bsn_pdu_tx_request_OF_VERSION_1_1_check_scalars(
    of_bsn_pdu_tx_request_t *obj, int value);

extern int of_bsn_set_mirroring_OF_VERSION_1_1_populate(
    of_bsn_set_mirroring_t *obj, int value);
extern int of_bsn_set_mirroring_OF_VERSION_1_1_check(
    of_bsn_set_mirroring_t *obj, int value);
extern int of_bsn_set_mirroring_OF_VERSION_1_1_populate_scalars(
    of_bsn_set_mirroring_t *obj, int value);
extern int of_bsn_set_mirroring_OF_VERSION_1_1_check_scalars(
    of_bsn_set_mirroring_t *obj, int value);

extern int of_bsn_set_pktin_suppression_reply_OF_VERSION_1_1_populate(
    of_bsn_set_pktin_suppression_reply_t *obj, int value);
extern int of_bsn_set_pktin_suppression_reply_OF_VERSION_1_1_check(
    of_bsn_set_pktin_suppression_reply_t *obj, int value);
extern int of_bsn_set_pktin_suppression_reply_OF_VERSION_1_1_populate_scalars(
    of_bsn_set_pktin_suppression_reply_t *obj, int value);
extern int of_bsn_set_pktin_suppression_reply_OF_VERSION_1_1_check_scalars(
    of_bsn_set_pktin_suppression_reply_t *obj, int value);

extern int of_bsn_set_pktin_suppression_request_OF_VERSION_1_1_populate(
    of_bsn_set_pktin_suppression_request_t *obj, int value);
extern int of_bsn_set_pktin_suppression_request_OF_VERSION_1_1_check(
    of_bsn_set_pktin_suppression_request_t *obj, int value);
extern int of_bsn_set_pktin_suppression_request_OF_VERSION_1_1_populate_scalars(
    of_bsn_set_pktin_suppression_request_t *obj, int value);
extern int of_bsn_set_pktin_suppression_request_OF_VERSION_1_1_check_scalars(
    of_bsn_set_pktin_suppression_request_t *obj, int value);

extern int of_bsn_virtual_port_create_reply_OF_VERSION_1_1_populate(
    of_bsn_virtual_port_create_reply_t *obj, int value);
extern int of_bsn_virtual_port_create_reply_OF_VERSION_1_1_check(
    of_bsn_virtual_port_create_reply_t *obj, int value);
extern int of_bsn_virtual_port_create_reply_OF_VERSION_1_1_populate_scalars(
    of_bsn_virtual_port_create_reply_t *obj, int value);
extern int of_bsn_virtual_port_create_reply_OF_VERSION_1_1_check_scalars(
    of_bsn_virtual_port_create_reply_t *obj, int value);

extern int of_bsn_virtual_port_create_request_OF_VERSION_1_1_populate(
    of_bsn_virtual_port_create_request_t *obj, int value);
extern int of_bsn_virtual_port_create_request_OF_VERSION_1_1_check(
    of_bsn_virtual_port_create_request_t *obj, int value);
extern int of_bsn_virtual_port_create_request_OF_VERSION_1_1_populate_scalars(
    of_bsn_virtual_port_create_request_t *obj, int value);
extern int of_bsn_virtual_port_create_request_OF_VERSION_1_1_check_scalars(
    of_bsn_virtual_port_create_request_t *obj, int value);

extern int of_bsn_virtual_port_remove_reply_OF_VERSION_1_1_populate(
    of_bsn_virtual_port_remove_reply_t *obj, int value);
extern int of_bsn_virtual_port_remove_reply_OF_VERSION_1_1_check(
    of_bsn_virtual_port_remove_reply_t *obj, int value);
extern int of_bsn_virtual_port_remove_reply_OF_VERSION_1_1_populate_scalars(
    of_bsn_virtual_port_remove_reply_t *obj, int value);
extern int of_bsn_virtual_port_remove_reply_OF_VERSION_1_1_check_scalars(
    of_bsn_virtual_port_remove_reply_t *obj, int value);

extern int of_bsn_virtual_port_remove_request_OF_VERSION_1_1_populate(
    of_bsn_virtual_port_remove_request_t *obj, int value);
extern int of_bsn_virtual_port_remove_request_OF_VERSION_1_1_check(
    of_bsn_virtual_port_remove_request_t *obj, int value);
extern int of_bsn_virtual_port_remove_request_OF_VERSION_1_1_populate_scalars(
    of_bsn_virtual_port_remove_request_t *obj, int value);
extern int of_bsn_virtual_port_remove_request_OF_VERSION_1_1_check_scalars(
    of_bsn_virtual_port_remove_request_t *obj, int value);

extern int of_desc_stats_reply_OF_VERSION_1_1_populate(
    of_desc_stats_reply_t *obj, int value);
extern int of_desc_stats_reply_OF_VERSION_1_1_check(
    of_desc_stats_reply_t *obj, int value);
extern int of_desc_stats_reply_OF_VERSION_1_1_populate_scalars(
    of_desc_stats_reply_t *obj, int value);
extern int of_desc_stats_reply_OF_VERSION_1_1_check_scalars(
    of_desc_stats_reply_t *obj, int value);

extern int of_desc_stats_request_OF_VERSION_1_1_populate(
    of_desc_stats_request_t *obj, int value);
extern int of_desc_stats_request_OF_VERSION_1_1_check(
    of_desc_stats_request_t *obj, int value);
extern int of_desc_stats_request_OF_VERSION_1_1_populate_scalars(
    of_desc_stats_request_t *obj, int value);
extern int of_desc_stats_request_OF_VERSION_1_1_check_scalars(
    of_desc_stats_request_t *obj, int value);

extern int of_echo_reply_OF_VERSION_1_1_populate(
    of_echo_reply_t *obj, int value);
extern int of_echo_reply_OF_VERSION_1_1_check(
    of_echo_reply_t *obj, int value);
extern int of_echo_reply_OF_VERSION_1_1_populate_scalars(
    of_echo_reply_t *obj, int value);
extern int of_echo_reply_OF_VERSION_1_1_check_scalars(
    of_echo_reply_t *obj, int value);

extern int of_echo_request_OF_VERSION_1_1_populate(
    of_echo_request_t *obj, int value);
extern int of_echo_request_OF_VERSION_1_1_check(
    of_echo_request_t *obj, int value);
extern int of_echo_request_OF_VERSION_1_1_populate_scalars(
    of_echo_request_t *obj, int value);
extern int of_echo_request_OF_VERSION_1_1_check_scalars(
    of_echo_request_t *obj, int value);

extern int of_features_reply_OF_VERSION_1_1_populate(
    of_features_reply_t *obj, int value);
extern int of_features_reply_OF_VERSION_1_1_check(
    of_features_reply_t *obj, int value);
extern int of_features_reply_OF_VERSION_1_1_populate_scalars(
    of_features_reply_t *obj, int value);
extern int of_features_reply_OF_VERSION_1_1_check_scalars(
    of_features_reply_t *obj, int value);

extern int of_features_request_OF_VERSION_1_1_populate(
    of_features_request_t *obj, int value);
extern int of_features_request_OF_VERSION_1_1_check(
    of_features_request_t *obj, int value);
extern int of_features_request_OF_VERSION_1_1_populate_scalars(
    of_features_request_t *obj, int value);
extern int of_features_request_OF_VERSION_1_1_check_scalars(
    of_features_request_t *obj, int value);

extern int of_flow_add_OF_VERSION_1_1_populate(
    of_flow_add_t *obj, int value);
extern int of_flow_add_OF_VERSION_1_1_check(
    of_flow_add_t *obj, int value);
extern int of_flow_add_OF_VERSION_1_1_populate_scalars(
    of_flow_add_t *obj, int value);
extern int of_flow_add_OF_VERSION_1_1_check_scalars(
    of_flow_add_t *obj, int value);

extern int of_flow_delete_OF_VERSION_1_1_populate(
    of_flow_delete_t *obj, int value);
extern int of_flow_delete_OF_VERSION_1_1_check(
    of_flow_delete_t *obj, int value);
extern int of_flow_delete_OF_VERSION_1_1_populate_scalars(
    of_flow_delete_t *obj, int value);
extern int of_flow_delete_OF_VERSION_1_1_check_scalars(
    of_flow_delete_t *obj, int value);

extern int of_flow_delete_strict_OF_VERSION_1_1_populate(
    of_flow_delete_strict_t *obj, int value);
extern int of_flow_delete_strict_OF_VERSION_1_1_check(
    of_flow_delete_strict_t *obj, int value);
extern int of_flow_delete_strict_OF_VERSION_1_1_populate_scalars(
    of_flow_delete_strict_t *obj, int value);
extern int of_flow_delete_strict_OF_VERSION_1_1_check_scalars(
    of_flow_delete_strict_t *obj, int value);

extern int of_flow_mod_failed_error_msg_OF_VERSION_1_1_populate(
    of_flow_mod_failed_error_msg_t *obj, int value);
extern int of_flow_mod_failed_error_msg_OF_VERSION_1_1_check(
    of_flow_mod_failed_error_msg_t *obj, int value);
extern int of_flow_mod_failed_error_msg_OF_VERSION_1_1_populate_scalars(
    of_flow_mod_failed_error_msg_t *obj, int value);
extern int of_flow_mod_failed_error_msg_OF_VERSION_1_1_check_scalars(
    of_flow_mod_failed_error_msg_t *obj, int value);

extern int of_flow_modify_OF_VERSION_1_1_populate(
    of_flow_modify_t *obj, int value);
extern int of_flow_modify_OF_VERSION_1_1_check(
    of_flow_modify_t *obj, int value);
extern int of_flow_modify_OF_VERSION_1_1_populate_scalars(
    of_flow_modify_t *obj, int value);
extern int of_flow_modify_OF_VERSION_1_1_check_scalars(
    of_flow_modify_t *obj, int value);

extern int of_flow_modify_strict_OF_VERSION_1_1_populate(
    of_flow_modify_strict_t *obj, int value);
extern int of_flow_modify_strict_OF_VERSION_1_1_check(
    of_flow_modify_strict_t *obj, int value);
extern int of_flow_modify_strict_OF_VERSION_1_1_populate_scalars(
    of_flow_modify_strict_t *obj, int value);
extern int of_flow_modify_strict_OF_VERSION_1_1_check_scalars(
    of_flow_modify_strict_t *obj, int value);

extern int of_flow_removed_OF_VERSION_1_1_populate(
    of_flow_removed_t *obj, int value);
extern int of_flow_removed_OF_VERSION_1_1_check(
    of_flow_removed_t *obj, int value);
extern int of_flow_removed_OF_VERSION_1_1_populate_scalars(
    of_flow_removed_t *obj, int value);
extern int of_flow_removed_OF_VERSION_1_1_check_scalars(
    of_flow_removed_t *obj, int value);

extern int of_flow_stats_reply_OF_VERSION_1_1_populate(
    of_flow_stats_reply_t *obj, int value);
extern int of_flow_stats_reply_OF_VERSION_1_1_check(
    of_flow_stats_reply_t *obj, int value);
extern int of_flow_stats_reply_OF_VERSION_1_1_populate_scalars(
    of_flow_stats_reply_t *obj, int value);
extern int of_flow_stats_reply_OF_VERSION_1_1_check_scalars(
    of_flow_stats_reply_t *obj, int value);

extern int of_flow_stats_request_OF_VERSION_1_1_populate(
    of_flow_stats_request_t *obj, int value);
extern int of_flow_stats_request_OF_VERSION_1_1_check(
    of_flow_stats_request_t *obj, int value);
extern int of_flow_stats_request_OF_VERSION_1_1_populate_scalars(
    of_flow_stats_request_t *obj, int value);
extern int of_flow_stats_request_OF_VERSION_1_1_check_scalars(
    of_flow_stats_request_t *obj, int value);

extern int of_get_config_reply_OF_VERSION_1_1_populate(
    of_get_config_reply_t *obj, int value);
extern int of_get_config_reply_OF_VERSION_1_1_check(
    of_get_config_reply_t *obj, int value);
extern int of_get_config_reply_OF_VERSION_1_1_populate_scalars(
    of_get_config_reply_t *obj, int value);
extern int of_get_config_reply_OF_VERSION_1_1_check_scalars(
    of_get_config_reply_t *obj, int value);

extern int of_get_config_request_OF_VERSION_1_1_populate(
    of_get_config_request_t *obj, int value);
extern int of_get_config_request_OF_VERSION_1_1_check(
    of_get_config_request_t *obj, int value);
extern int of_get_config_request_OF_VERSION_1_1_populate_scalars(
    of_get_config_request_t *obj, int value);
extern int of_get_config_request_OF_VERSION_1_1_check_scalars(
    of_get_config_request_t *obj, int value);

extern int of_group_add_OF_VERSION_1_1_populate(
    of_group_add_t *obj, int value);
extern int of_group_add_OF_VERSION_1_1_check(
    of_group_add_t *obj, int value);
extern int of_group_add_OF_VERSION_1_1_populate_scalars(
    of_group_add_t *obj, int value);
extern int of_group_add_OF_VERSION_1_1_check_scalars(
    of_group_add_t *obj, int value);

extern int of_group_delete_OF_VERSION_1_1_populate(
    of_group_delete_t *obj, int value);
extern int of_group_delete_OF_VERSION_1_1_check(
    of_group_delete_t *obj, int value);
extern int of_group_delete_OF_VERSION_1_1_populate_scalars(
    of_group_delete_t *obj, int value);
extern int of_group_delete_OF_VERSION_1_1_check_scalars(
    of_group_delete_t *obj, int value);

extern int of_group_desc_stats_reply_OF_VERSION_1_1_populate(
    of_group_desc_stats_reply_t *obj, int value);
extern int of_group_desc_stats_reply_OF_VERSION_1_1_check(
    of_group_desc_stats_reply_t *obj, int value);
extern int of_group_desc_stats_reply_OF_VERSION_1_1_populate_scalars(
    of_group_desc_stats_reply_t *obj, int value);
extern int of_group_desc_stats_reply_OF_VERSION_1_1_check_scalars(
    of_group_desc_stats_reply_t *obj, int value);

extern int of_group_desc_stats_request_OF_VERSION_1_1_populate(
    of_group_desc_stats_request_t *obj, int value);
extern int of_group_desc_stats_request_OF_VERSION_1_1_check(
    of_group_desc_stats_request_t *obj, int value);
extern int of_group_desc_stats_request_OF_VERSION_1_1_populate_scalars(
    of_group_desc_stats_request_t *obj, int value);
extern int of_group_desc_stats_request_OF_VERSION_1_1_check_scalars(
    of_group_desc_stats_request_t *obj, int value);

extern int of_group_mod_failed_error_msg_OF_VERSION_1_1_populate(
    of_group_mod_failed_error_msg_t *obj, int value);
extern int of_group_mod_failed_error_msg_OF_VERSION_1_1_check(
    of_group_mod_failed_error_msg_t *obj, int value);
extern int of_group_mod_failed_error_msg_OF_VERSION_1_1_populate_scalars(
    of_group_mod_failed_error_msg_t *obj, int value);
extern int of_group_mod_failed_error_msg_OF_VERSION_1_1_check_scalars(
    of_group_mod_failed_error_msg_t *obj, int value);

extern int of_group_modify_OF_VERSION_1_1_populate(
    of_group_modify_t *obj, int value);
extern int of_group_modify_OF_VERSION_1_1_check(
    of_group_modify_t *obj, int value);
extern int of_group_modify_OF_VERSION_1_1_populate_scalars(
    of_group_modify_t *obj, int value);
extern int of_group_modify_OF_VERSION_1_1_check_scalars(
    of_group_modify_t *obj, int value);

extern int of_group_stats_reply_OF_VERSION_1_1_populate(
    of_group_stats_reply_t *obj, int value);
extern int of_group_stats_reply_OF_VERSION_1_1_check(
    of_group_stats_reply_t *obj, int value);
extern int of_group_stats_reply_OF_VERSION_1_1_populate_scalars(
    of_group_stats_reply_t *obj, int value);
extern int of_group_stats_reply_OF_VERSION_1_1_check_scalars(
    of_group_stats_reply_t *obj, int value);

extern int of_group_stats_request_OF_VERSION_1_1_populate(
    of_group_stats_request_t *obj, int value);
extern int of_group_stats_request_OF_VERSION_1_1_check(
    of_group_stats_request_t *obj, int value);
extern int of_group_stats_request_OF_VERSION_1_1_populate_scalars(
    of_group_stats_request_t *obj, int value);
extern int of_group_stats_request_OF_VERSION_1_1_check_scalars(
    of_group_stats_request_t *obj, int value);

extern int of_hello_OF_VERSION_1_1_populate(
    of_hello_t *obj, int value);
extern int of_hello_OF_VERSION_1_1_check(
    of_hello_t *obj, int value);
extern int of_hello_OF_VERSION_1_1_populate_scalars(
    of_hello_t *obj, int value);
extern int of_hello_OF_VERSION_1_1_check_scalars(
    of_hello_t *obj, int value);

extern int of_hello_failed_error_msg_OF_VERSION_1_1_populate(
    of_hello_failed_error_msg_t *obj, int value);
extern int of_hello_failed_error_msg_OF_VERSION_1_1_check(
    of_hello_failed_error_msg_t *obj, int value);
extern int of_hello_failed_error_msg_OF_VERSION_1_1_populate_scalars(
    of_hello_failed_error_msg_t *obj, int value);
extern int of_hello_failed_error_msg_OF_VERSION_1_1_check_scalars(
    of_hello_failed_error_msg_t *obj, int value);

extern int of_packet_in_OF_VERSION_1_1_populate(
    of_packet_in_t *obj, int value);
extern int of_packet_in_OF_VERSION_1_1_check(
    of_packet_in_t *obj, int value);
extern int of_packet_in_OF_VERSION_1_1_populate_scalars(
    of_packet_in_t *obj, int value);
extern int of_packet_in_OF_VERSION_1_1_check_scalars(
    of_packet_in_t *obj, int value);

extern int of_packet_out_OF_VERSION_1_1_populate(
    of_packet_out_t *obj, int value);
extern int of_packet_out_OF_VERSION_1_1_check(
    of_packet_out_t *obj, int value);
extern int of_packet_out_OF_VERSION_1_1_populate_scalars(
    of_packet_out_t *obj, int value);
extern int of_packet_out_OF_VERSION_1_1_check_scalars(
    of_packet_out_t *obj, int value);

extern int of_port_mod_OF_VERSION_1_1_populate(
    of_port_mod_t *obj, int value);
extern int of_port_mod_OF_VERSION_1_1_check(
    of_port_mod_t *obj, int value);
extern int of_port_mod_OF_VERSION_1_1_populate_scalars(
    of_port_mod_t *obj, int value);
extern int of_port_mod_OF_VERSION_1_1_check_scalars(
    of_port_mod_t *obj, int value);

extern int of_port_mod_failed_error_msg_OF_VERSION_1_1_populate(
    of_port_mod_failed_error_msg_t *obj, int value);
extern int of_port_mod_failed_error_msg_OF_VERSION_1_1_check(
    of_port_mod_failed_error_msg_t *obj, int value);
extern int of_port_mod_failed_error_msg_OF_VERSION_1_1_populate_scalars(
    of_port_mod_failed_error_msg_t *obj, int value);
extern int of_port_mod_failed_error_msg_OF_VERSION_1_1_check_scalars(
    of_port_mod_failed_error_msg_t *obj, int value);

extern int of_port_stats_reply_OF_VERSION_1_1_populate(
    of_port_stats_reply_t *obj, int value);
extern int of_port_stats_reply_OF_VERSION_1_1_check(
    of_port_stats_reply_t *obj, int value);
extern int of_port_stats_reply_OF_VERSION_1_1_populate_scalars(
    of_port_stats_reply_t *obj, int value);
extern int of_port_stats_reply_OF_VERSION_1_1_check_scalars(
    of_port_stats_reply_t *obj, int value);

extern int of_port_stats_request_OF_VERSION_1_1_populate(
    of_port_stats_request_t *obj, int value);
extern int of_port_stats_request_OF_VERSION_1_1_check(
    of_port_stats_request_t *obj, int value);
extern int of_port_stats_request_OF_VERSION_1_1_populate_scalars(
    of_port_stats_request_t *obj, int value);
extern int of_port_stats_request_OF_VERSION_1_1_check_scalars(
    of_port_stats_request_t *obj, int value);

extern int of_port_status_OF_VERSION_1_1_populate(
    of_port_status_t *obj, int value);
extern int of_port_status_OF_VERSION_1_1_check(
    of_port_status_t *obj, int value);
extern int of_port_status_OF_VERSION_1_1_populate_scalars(
    of_port_status_t *obj, int value);
extern int of_port_status_OF_VERSION_1_1_check_scalars(
    of_port_status_t *obj, int value);

extern int of_queue_get_config_reply_OF_VERSION_1_1_populate(
    of_queue_get_config_reply_t *obj, int value);
extern int of_queue_get_config_reply_OF_VERSION_1_1_check(
    of_queue_get_config_reply_t *obj, int value);
extern int of_queue_get_config_reply_OF_VERSION_1_1_populate_scalars(
    of_queue_get_config_reply_t *obj, int value);
extern int of_queue_get_config_reply_OF_VERSION_1_1_check_scalars(
    of_queue_get_config_reply_t *obj, int value);

extern int of_queue_get_config_request_OF_VERSION_1_1_populate(
    of_queue_get_config_request_t *obj, int value);
extern int of_queue_get_config_request_OF_VERSION_1_1_check(
    of_queue_get_config_request_t *obj, int value);
extern int of_queue_get_config_request_OF_VERSION_1_1_populate_scalars(
    of_queue_get_config_request_t *obj, int value);
extern int of_queue_get_config_request_OF_VERSION_1_1_check_scalars(
    of_queue_get_config_request_t *obj, int value);

extern int of_queue_op_failed_error_msg_OF_VERSION_1_1_populate(
    of_queue_op_failed_error_msg_t *obj, int value);
extern int of_queue_op_failed_error_msg_OF_VERSION_1_1_check(
    of_queue_op_failed_error_msg_t *obj, int value);
extern int of_queue_op_failed_error_msg_OF_VERSION_1_1_populate_scalars(
    of_queue_op_failed_error_msg_t *obj, int value);
extern int of_queue_op_failed_error_msg_OF_VERSION_1_1_check_scalars(
    of_queue_op_failed_error_msg_t *obj, int value);

extern int of_queue_stats_reply_OF_VERSION_1_1_populate(
    of_queue_stats_reply_t *obj, int value);
extern int of_queue_stats_reply_OF_VERSION_1_1_check(
    of_queue_stats_reply_t *obj, int value);
extern int of_queue_stats_reply_OF_VERSION_1_1_populate_scalars(
    of_queue_stats_reply_t *obj, int value);
extern int of_queue_stats_reply_OF_VERSION_1_1_check_scalars(
    of_queue_stats_reply_t *obj, int value);

extern int of_queue_stats_request_OF_VERSION_1_1_populate(
    of_queue_stats_request_t *obj, int value);
extern int of_queue_stats_request_OF_VERSION_1_1_check(
    of_queue_stats_request_t *obj, int value);
extern int of_queue_stats_request_OF_VERSION_1_1_populate_scalars(
    of_queue_stats_request_t *obj, int value);
extern int of_queue_stats_request_OF_VERSION_1_1_check_scalars(
    of_queue_stats_request_t *obj, int value);

extern int of_set_config_OF_VERSION_1_1_populate(
    of_set_config_t *obj, int value);
extern int of_set_config_OF_VERSION_1_1_check(
    of_set_config_t *obj, int value);
extern int of_set_config_OF_VERSION_1_1_populate_scalars(
    of_set_config_t *obj, int value);
extern int of_set_config_OF_VERSION_1_1_check_scalars(
    of_set_config_t *obj, int value);

extern int of_switch_config_failed_error_msg_OF_VERSION_1_1_populate(
    of_switch_config_failed_error_msg_t *obj, int value);
extern int of_switch_config_failed_error_msg_OF_VERSION_1_1_check(
    of_switch_config_failed_error_msg_t *obj, int value);
extern int of_switch_config_failed_error_msg_OF_VERSION_1_1_populate_scalars(
    of_switch_config_failed_error_msg_t *obj, int value);
extern int of_switch_config_failed_error_msg_OF_VERSION_1_1_check_scalars(
    of_switch_config_failed_error_msg_t *obj, int value);

extern int of_table_mod_OF_VERSION_1_1_populate(
    of_table_mod_t *obj, int value);
extern int of_table_mod_OF_VERSION_1_1_check(
    of_table_mod_t *obj, int value);
extern int of_table_mod_OF_VERSION_1_1_populate_scalars(
    of_table_mod_t *obj, int value);
extern int of_table_mod_OF_VERSION_1_1_check_scalars(
    of_table_mod_t *obj, int value);

extern int of_table_mod_failed_error_msg_OF_VERSION_1_1_populate(
    of_table_mod_failed_error_msg_t *obj, int value);
extern int of_table_mod_failed_error_msg_OF_VERSION_1_1_check(
    of_table_mod_failed_error_msg_t *obj, int value);
extern int of_table_mod_failed_error_msg_OF_VERSION_1_1_populate_scalars(
    of_table_mod_failed_error_msg_t *obj, int value);
extern int of_table_mod_failed_error_msg_OF_VERSION_1_1_check_scalars(
    of_table_mod_failed_error_msg_t *obj, int value);

extern int of_table_stats_reply_OF_VERSION_1_1_populate(
    of_table_stats_reply_t *obj, int value);
extern int of_table_stats_reply_OF_VERSION_1_1_check(
    of_table_stats_reply_t *obj, int value);
extern int of_table_stats_reply_OF_VERSION_1_1_populate_scalars(
    of_table_stats_reply_t *obj, int value);
extern int of_table_stats_reply_OF_VERSION_1_1_check_scalars(
    of_table_stats_reply_t *obj, int value);

extern int of_table_stats_request_OF_VERSION_1_1_populate(
    of_table_stats_request_t *obj, int value);
extern int of_table_stats_request_OF_VERSION_1_1_check(
    of_table_stats_request_t *obj, int value);
extern int of_table_stats_request_OF_VERSION_1_1_populate_scalars(
    of_table_stats_request_t *obj, int value);
extern int of_table_stats_request_OF_VERSION_1_1_check_scalars(
    of_table_stats_request_t *obj, int value);

extern int of_action_bsn_checksum_OF_VERSION_1_1_populate(
    of_action_bsn_checksum_t *obj, int value);
extern int of_action_bsn_checksum_OF_VERSION_1_1_check(
    of_action_bsn_checksum_t *obj, int value);
extern int of_action_bsn_checksum_OF_VERSION_1_1_populate_scalars(
    of_action_bsn_checksum_t *obj, int value);
extern int of_action_bsn_checksum_OF_VERSION_1_1_check_scalars(
    of_action_bsn_checksum_t *obj, int value);

extern int of_action_bsn_mirror_OF_VERSION_1_1_populate(
    of_action_bsn_mirror_t *obj, int value);
extern int of_action_bsn_mirror_OF_VERSION_1_1_check(
    of_action_bsn_mirror_t *obj, int value);
extern int of_action_bsn_mirror_OF_VERSION_1_1_populate_scalars(
    of_action_bsn_mirror_t *obj, int value);
extern int of_action_bsn_mirror_OF_VERSION_1_1_check_scalars(
    of_action_bsn_mirror_t *obj, int value);

extern int of_action_bsn_set_tunnel_dst_OF_VERSION_1_1_populate(
    of_action_bsn_set_tunnel_dst_t *obj, int value);
extern int of_action_bsn_set_tunnel_dst_OF_VERSION_1_1_check(
    of_action_bsn_set_tunnel_dst_t *obj, int value);
extern int of_action_bsn_set_tunnel_dst_OF_VERSION_1_1_populate_scalars(
    of_action_bsn_set_tunnel_dst_t *obj, int value);
extern int of_action_bsn_set_tunnel_dst_OF_VERSION_1_1_check_scalars(
    of_action_bsn_set_tunnel_dst_t *obj, int value);

extern int of_action_copy_ttl_in_OF_VERSION_1_1_populate(
    of_action_copy_ttl_in_t *obj, int value);
extern int of_action_copy_ttl_in_OF_VERSION_1_1_check(
    of_action_copy_ttl_in_t *obj, int value);
extern int of_action_copy_ttl_in_OF_VERSION_1_1_populate_scalars(
    of_action_copy_ttl_in_t *obj, int value);
extern int of_action_copy_ttl_in_OF_VERSION_1_1_check_scalars(
    of_action_copy_ttl_in_t *obj, int value);

extern int of_action_copy_ttl_out_OF_VERSION_1_1_populate(
    of_action_copy_ttl_out_t *obj, int value);
extern int of_action_copy_ttl_out_OF_VERSION_1_1_check(
    of_action_copy_ttl_out_t *obj, int value);
extern int of_action_copy_ttl_out_OF_VERSION_1_1_populate_scalars(
    of_action_copy_ttl_out_t *obj, int value);
extern int of_action_copy_ttl_out_OF_VERSION_1_1_check_scalars(
    of_action_copy_ttl_out_t *obj, int value);

extern int of_action_dec_mpls_ttl_OF_VERSION_1_1_populate(
    of_action_dec_mpls_ttl_t *obj, int value);
extern int of_action_dec_mpls_ttl_OF_VERSION_1_1_check(
    of_action_dec_mpls_ttl_t *obj, int value);
extern int of_action_dec_mpls_ttl_OF_VERSION_1_1_populate_scalars(
    of_action_dec_mpls_ttl_t *obj, int value);
extern int of_action_dec_mpls_ttl_OF_VERSION_1_1_check_scalars(
    of_action_dec_mpls_ttl_t *obj, int value);

extern int of_action_dec_nw_ttl_OF_VERSION_1_1_populate(
    of_action_dec_nw_ttl_t *obj, int value);
extern int of_action_dec_nw_ttl_OF_VERSION_1_1_check(
    of_action_dec_nw_ttl_t *obj, int value);
extern int of_action_dec_nw_ttl_OF_VERSION_1_1_populate_scalars(
    of_action_dec_nw_ttl_t *obj, int value);
extern int of_action_dec_nw_ttl_OF_VERSION_1_1_check_scalars(
    of_action_dec_nw_ttl_t *obj, int value);

extern int of_action_group_OF_VERSION_1_1_populate(
    of_action_group_t *obj, int value);
extern int of_action_group_OF_VERSION_1_1_check(
    of_action_group_t *obj, int value);
extern int of_action_group_OF_VERSION_1_1_populate_scalars(
    of_action_group_t *obj, int value);
extern int of_action_group_OF_VERSION_1_1_check_scalars(
    of_action_group_t *obj, int value);

extern int of_action_nicira_dec_ttl_OF_VERSION_1_1_populate(
    of_action_nicira_dec_ttl_t *obj, int value);
extern int of_action_nicira_dec_ttl_OF_VERSION_1_1_check(
    of_action_nicira_dec_ttl_t *obj, int value);
extern int of_action_nicira_dec_ttl_OF_VERSION_1_1_populate_scalars(
    of_action_nicira_dec_ttl_t *obj, int value);
extern int of_action_nicira_dec_ttl_OF_VERSION_1_1_check_scalars(
    of_action_nicira_dec_ttl_t *obj, int value);

extern int of_action_output_OF_VERSION_1_1_populate(
    of_action_output_t *obj, int value);
extern int of_action_output_OF_VERSION_1_1_check(
    of_action_output_t *obj, int value);
extern int of_action_output_OF_VERSION_1_1_populate_scalars(
    of_action_output_t *obj, int value);
extern int of_action_output_OF_VERSION_1_1_check_scalars(
    of_action_output_t *obj, int value);

extern int of_action_pop_mpls_OF_VERSION_1_1_populate(
    of_action_pop_mpls_t *obj, int value);
extern int of_action_pop_mpls_OF_VERSION_1_1_check(
    of_action_pop_mpls_t *obj, int value);
extern int of_action_pop_mpls_OF_VERSION_1_1_populate_scalars(
    of_action_pop_mpls_t *obj, int value);
extern int of_action_pop_mpls_OF_VERSION_1_1_check_scalars(
    of_action_pop_mpls_t *obj, int value);

extern int of_action_pop_vlan_OF_VERSION_1_1_populate(
    of_action_pop_vlan_t *obj, int value);
extern int of_action_pop_vlan_OF_VERSION_1_1_check(
    of_action_pop_vlan_t *obj, int value);
extern int of_action_pop_vlan_OF_VERSION_1_1_populate_scalars(
    of_action_pop_vlan_t *obj, int value);
extern int of_action_pop_vlan_OF_VERSION_1_1_check_scalars(
    of_action_pop_vlan_t *obj, int value);

extern int of_action_push_mpls_OF_VERSION_1_1_populate(
    of_action_push_mpls_t *obj, int value);
extern int of_action_push_mpls_OF_VERSION_1_1_check(
    of_action_push_mpls_t *obj, int value);
extern int of_action_push_mpls_OF_VERSION_1_1_populate_scalars(
    of_action_push_mpls_t *obj, int value);
extern int of_action_push_mpls_OF_VERSION_1_1_check_scalars(
    of_action_push_mpls_t *obj, int value);

extern int of_action_push_vlan_OF_VERSION_1_1_populate(
    of_action_push_vlan_t *obj, int value);
extern int of_action_push_vlan_OF_VERSION_1_1_check(
    of_action_push_vlan_t *obj, int value);
extern int of_action_push_vlan_OF_VERSION_1_1_populate_scalars(
    of_action_push_vlan_t *obj, int value);
extern int of_action_push_vlan_OF_VERSION_1_1_check_scalars(
    of_action_push_vlan_t *obj, int value);

extern int of_action_set_dl_dst_OF_VERSION_1_1_populate(
    of_action_set_dl_dst_t *obj, int value);
extern int of_action_set_dl_dst_OF_VERSION_1_1_check(
    of_action_set_dl_dst_t *obj, int value);
extern int of_action_set_dl_dst_OF_VERSION_1_1_populate_scalars(
    of_action_set_dl_dst_t *obj, int value);
extern int of_action_set_dl_dst_OF_VERSION_1_1_check_scalars(
    of_action_set_dl_dst_t *obj, int value);

extern int of_action_set_dl_src_OF_VERSION_1_1_populate(
    of_action_set_dl_src_t *obj, int value);
extern int of_action_set_dl_src_OF_VERSION_1_1_check(
    of_action_set_dl_src_t *obj, int value);
extern int of_action_set_dl_src_OF_VERSION_1_1_populate_scalars(
    of_action_set_dl_src_t *obj, int value);
extern int of_action_set_dl_src_OF_VERSION_1_1_check_scalars(
    of_action_set_dl_src_t *obj, int value);

extern int of_action_set_mpls_label_OF_VERSION_1_1_populate(
    of_action_set_mpls_label_t *obj, int value);
extern int of_action_set_mpls_label_OF_VERSION_1_1_check(
    of_action_set_mpls_label_t *obj, int value);
extern int of_action_set_mpls_label_OF_VERSION_1_1_populate_scalars(
    of_action_set_mpls_label_t *obj, int value);
extern int of_action_set_mpls_label_OF_VERSION_1_1_check_scalars(
    of_action_set_mpls_label_t *obj, int value);

extern int of_action_set_mpls_tc_OF_VERSION_1_1_populate(
    of_action_set_mpls_tc_t *obj, int value);
extern int of_action_set_mpls_tc_OF_VERSION_1_1_check(
    of_action_set_mpls_tc_t *obj, int value);
extern int of_action_set_mpls_tc_OF_VERSION_1_1_populate_scalars(
    of_action_set_mpls_tc_t *obj, int value);
extern int of_action_set_mpls_tc_OF_VERSION_1_1_check_scalars(
    of_action_set_mpls_tc_t *obj, int value);

extern int of_action_set_mpls_ttl_OF_VERSION_1_1_populate(
    of_action_set_mpls_ttl_t *obj, int value);
extern int of_action_set_mpls_ttl_OF_VERSION_1_1_check(
    of_action_set_mpls_ttl_t *obj, int value);
extern int of_action_set_mpls_ttl_OF_VERSION_1_1_populate_scalars(
    of_action_set_mpls_ttl_t *obj, int value);
extern int of_action_set_mpls_ttl_OF_VERSION_1_1_check_scalars(
    of_action_set_mpls_ttl_t *obj, int value);

extern int of_action_set_nw_dst_OF_VERSION_1_1_populate(
    of_action_set_nw_dst_t *obj, int value);
extern int of_action_set_nw_dst_OF_VERSION_1_1_check(
    of_action_set_nw_dst_t *obj, int value);
extern int of_action_set_nw_dst_OF_VERSION_1_1_populate_scalars(
    of_action_set_nw_dst_t *obj, int value);
extern int of_action_set_nw_dst_OF_VERSION_1_1_check_scalars(
    of_action_set_nw_dst_t *obj, int value);

extern int of_action_set_nw_ecn_OF_VERSION_1_1_populate(
    of_action_set_nw_ecn_t *obj, int value);
extern int of_action_set_nw_ecn_OF_VERSION_1_1_check(
    of_action_set_nw_ecn_t *obj, int value);
extern int of_action_set_nw_ecn_OF_VERSION_1_1_populate_scalars(
    of_action_set_nw_ecn_t *obj, int value);
extern int of_action_set_nw_ecn_OF_VERSION_1_1_check_scalars(
    of_action_set_nw_ecn_t *obj, int value);

extern int of_action_set_nw_src_OF_VERSION_1_1_populate(
    of_action_set_nw_src_t *obj, int value);
extern int of_action_set_nw_src_OF_VERSION_1_1_check(
    of_action_set_nw_src_t *obj, int value);
extern int of_action_set_nw_src_OF_VERSION_1_1_populate_scalars(
    of_action_set_nw_src_t *obj, int value);
extern int of_action_set_nw_src_OF_VERSION_1_1_check_scalars(
    of_action_set_nw_src_t *obj, int value);

extern int of_action_set_nw_tos_OF_VERSION_1_1_populate(
    of_action_set_nw_tos_t *obj, int value);
extern int of_action_set_nw_tos_OF_VERSION_1_1_check(
    of_action_set_nw_tos_t *obj, int value);
extern int of_action_set_nw_tos_OF_VERSION_1_1_populate_scalars(
    of_action_set_nw_tos_t *obj, int value);
extern int of_action_set_nw_tos_OF_VERSION_1_1_check_scalars(
    of_action_set_nw_tos_t *obj, int value);

extern int of_action_set_nw_ttl_OF_VERSION_1_1_populate(
    of_action_set_nw_ttl_t *obj, int value);
extern int of_action_set_nw_ttl_OF_VERSION_1_1_check(
    of_action_set_nw_ttl_t *obj, int value);
extern int of_action_set_nw_ttl_OF_VERSION_1_1_populate_scalars(
    of_action_set_nw_ttl_t *obj, int value);
extern int of_action_set_nw_ttl_OF_VERSION_1_1_check_scalars(
    of_action_set_nw_ttl_t *obj, int value);

extern int of_action_set_queue_OF_VERSION_1_1_populate(
    of_action_set_queue_t *obj, int value);
extern int of_action_set_queue_OF_VERSION_1_1_check(
    of_action_set_queue_t *obj, int value);
extern int of_action_set_queue_OF_VERSION_1_1_populate_scalars(
    of_action_set_queue_t *obj, int value);
extern int of_action_set_queue_OF_VERSION_1_1_check_scalars(
    of_action_set_queue_t *obj, int value);

extern int of_action_set_tp_dst_OF_VERSION_1_1_populate(
    of_action_set_tp_dst_t *obj, int value);
extern int of_action_set_tp_dst_OF_VERSION_1_1_check(
    of_action_set_tp_dst_t *obj, int value);
extern int of_action_set_tp_dst_OF_VERSION_1_1_populate_scalars(
    of_action_set_tp_dst_t *obj, int value);
extern int of_action_set_tp_dst_OF_VERSION_1_1_check_scalars(
    of_action_set_tp_dst_t *obj, int value);

extern int of_action_set_tp_src_OF_VERSION_1_1_populate(
    of_action_set_tp_src_t *obj, int value);
extern int of_action_set_tp_src_OF_VERSION_1_1_check(
    of_action_set_tp_src_t *obj, int value);
extern int of_action_set_tp_src_OF_VERSION_1_1_populate_scalars(
    of_action_set_tp_src_t *obj, int value);
extern int of_action_set_tp_src_OF_VERSION_1_1_check_scalars(
    of_action_set_tp_src_t *obj, int value);

extern int of_action_set_vlan_pcp_OF_VERSION_1_1_populate(
    of_action_set_vlan_pcp_t *obj, int value);
extern int of_action_set_vlan_pcp_OF_VERSION_1_1_check(
    of_action_set_vlan_pcp_t *obj, int value);
extern int of_action_set_vlan_pcp_OF_VERSION_1_1_populate_scalars(
    of_action_set_vlan_pcp_t *obj, int value);
extern int of_action_set_vlan_pcp_OF_VERSION_1_1_check_scalars(
    of_action_set_vlan_pcp_t *obj, int value);

extern int of_action_set_vlan_vid_OF_VERSION_1_1_populate(
    of_action_set_vlan_vid_t *obj, int value);
extern int of_action_set_vlan_vid_OF_VERSION_1_1_check(
    of_action_set_vlan_vid_t *obj, int value);
extern int of_action_set_vlan_vid_OF_VERSION_1_1_populate_scalars(
    of_action_set_vlan_vid_t *obj, int value);
extern int of_action_set_vlan_vid_OF_VERSION_1_1_check_scalars(
    of_action_set_vlan_vid_t *obj, int value);

extern int of_bsn_interface_OF_VERSION_1_1_populate(
    of_bsn_interface_t *obj, int value);
extern int of_bsn_interface_OF_VERSION_1_1_check(
    of_bsn_interface_t *obj, int value);
extern int of_bsn_interface_OF_VERSION_1_1_populate_scalars(
    of_bsn_interface_t *obj, int value);
extern int of_bsn_interface_OF_VERSION_1_1_check_scalars(
    of_bsn_interface_t *obj, int value);

extern int of_bsn_vport_l2gre_OF_VERSION_1_1_populate(
    of_bsn_vport_l2gre_t *obj, int value);
extern int of_bsn_vport_l2gre_OF_VERSION_1_1_check(
    of_bsn_vport_l2gre_t *obj, int value);
extern int of_bsn_vport_l2gre_OF_VERSION_1_1_populate_scalars(
    of_bsn_vport_l2gre_t *obj, int value);
extern int of_bsn_vport_l2gre_OF_VERSION_1_1_check_scalars(
    of_bsn_vport_l2gre_t *obj, int value);

extern int of_bsn_vport_q_in_q_OF_VERSION_1_1_populate(
    of_bsn_vport_q_in_q_t *obj, int value);
extern int of_bsn_vport_q_in_q_OF_VERSION_1_1_check(
    of_bsn_vport_q_in_q_t *obj, int value);
extern int of_bsn_vport_q_in_q_OF_VERSION_1_1_populate_scalars(
    of_bsn_vport_q_in_q_t *obj, int value);
extern int of_bsn_vport_q_in_q_OF_VERSION_1_1_check_scalars(
    of_bsn_vport_q_in_q_t *obj, int value);

extern int of_bucket_OF_VERSION_1_1_populate(
    of_bucket_t *obj, int value);
extern int of_bucket_OF_VERSION_1_1_check(
    of_bucket_t *obj, int value);
extern int of_bucket_OF_VERSION_1_1_populate_scalars(
    of_bucket_t *obj, int value);
extern int of_bucket_OF_VERSION_1_1_check_scalars(
    of_bucket_t *obj, int value);

extern int of_bucket_counter_OF_VERSION_1_1_populate(
    of_bucket_counter_t *obj, int value);
extern int of_bucket_counter_OF_VERSION_1_1_check(
    of_bucket_counter_t *obj, int value);
extern int of_bucket_counter_OF_VERSION_1_1_populate_scalars(
    of_bucket_counter_t *obj, int value);
extern int of_bucket_counter_OF_VERSION_1_1_check_scalars(
    of_bucket_counter_t *obj, int value);

extern int of_flow_stats_entry_OF_VERSION_1_1_populate(
    of_flow_stats_entry_t *obj, int value);
extern int of_flow_stats_entry_OF_VERSION_1_1_check(
    of_flow_stats_entry_t *obj, int value);
extern int of_flow_stats_entry_OF_VERSION_1_1_populate_scalars(
    of_flow_stats_entry_t *obj, int value);
extern int of_flow_stats_entry_OF_VERSION_1_1_check_scalars(
    of_flow_stats_entry_t *obj, int value);

extern int of_group_desc_stats_entry_OF_VERSION_1_1_populate(
    of_group_desc_stats_entry_t *obj, int value);
extern int of_group_desc_stats_entry_OF_VERSION_1_1_check(
    of_group_desc_stats_entry_t *obj, int value);
extern int of_group_desc_stats_entry_OF_VERSION_1_1_populate_scalars(
    of_group_desc_stats_entry_t *obj, int value);
extern int of_group_desc_stats_entry_OF_VERSION_1_1_check_scalars(
    of_group_desc_stats_entry_t *obj, int value);

extern int of_group_stats_entry_OF_VERSION_1_1_populate(
    of_group_stats_entry_t *obj, int value);
extern int of_group_stats_entry_OF_VERSION_1_1_check(
    of_group_stats_entry_t *obj, int value);
extern int of_group_stats_entry_OF_VERSION_1_1_populate_scalars(
    of_group_stats_entry_t *obj, int value);
extern int of_group_stats_entry_OF_VERSION_1_1_check_scalars(
    of_group_stats_entry_t *obj, int value);

extern int of_instruction_apply_actions_OF_VERSION_1_1_populate(
    of_instruction_apply_actions_t *obj, int value);
extern int of_instruction_apply_actions_OF_VERSION_1_1_check(
    of_instruction_apply_actions_t *obj, int value);
extern int of_instruction_apply_actions_OF_VERSION_1_1_populate_scalars(
    of_instruction_apply_actions_t *obj, int value);
extern int of_instruction_apply_actions_OF_VERSION_1_1_check_scalars(
    of_instruction_apply_actions_t *obj, int value);

extern int of_instruction_clear_actions_OF_VERSION_1_1_populate(
    of_instruction_clear_actions_t *obj, int value);
extern int of_instruction_clear_actions_OF_VERSION_1_1_check(
    of_instruction_clear_actions_t *obj, int value);
extern int of_instruction_clear_actions_OF_VERSION_1_1_populate_scalars(
    of_instruction_clear_actions_t *obj, int value);
extern int of_instruction_clear_actions_OF_VERSION_1_1_check_scalars(
    of_instruction_clear_actions_t *obj, int value);

extern int of_instruction_goto_table_OF_VERSION_1_1_populate(
    of_instruction_goto_table_t *obj, int value);
extern int of_instruction_goto_table_OF_VERSION_1_1_check(
    of_instruction_goto_table_t *obj, int value);
extern int of_instruction_goto_table_OF_VERSION_1_1_populate_scalars(
    of_instruction_goto_table_t *obj, int value);
extern int of_instruction_goto_table_OF_VERSION_1_1_check_scalars(
    of_instruction_goto_table_t *obj, int value);

extern int of_instruction_write_actions_OF_VERSION_1_1_populate(
    of_instruction_write_actions_t *obj, int value);
extern int of_instruction_write_actions_OF_VERSION_1_1_check(
    of_instruction_write_actions_t *obj, int value);
extern int of_instruction_write_actions_OF_VERSION_1_1_populate_scalars(
    of_instruction_write_actions_t *obj, int value);
extern int of_instruction_write_actions_OF_VERSION_1_1_check_scalars(
    of_instruction_write_actions_t *obj, int value);

extern int of_instruction_write_metadata_OF_VERSION_1_1_populate(
    of_instruction_write_metadata_t *obj, int value);
extern int of_instruction_write_metadata_OF_VERSION_1_1_check(
    of_instruction_write_metadata_t *obj, int value);
extern int of_instruction_write_metadata_OF_VERSION_1_1_populate_scalars(
    of_instruction_write_metadata_t *obj, int value);
extern int of_instruction_write_metadata_OF_VERSION_1_1_check_scalars(
    of_instruction_write_metadata_t *obj, int value);

extern int of_match_v2_OF_VERSION_1_1_populate(
    of_match_v2_t *obj, int value);
extern int of_match_v2_OF_VERSION_1_1_check(
    of_match_v2_t *obj, int value);
extern int of_match_v2_OF_VERSION_1_1_populate_scalars(
    of_match_v2_t *obj, int value);
extern int of_match_v2_OF_VERSION_1_1_check_scalars(
    of_match_v2_t *obj, int value);

extern int of_packet_queue_OF_VERSION_1_1_populate(
    of_packet_queue_t *obj, int value);
extern int of_packet_queue_OF_VERSION_1_1_check(
    of_packet_queue_t *obj, int value);
extern int of_packet_queue_OF_VERSION_1_1_populate_scalars(
    of_packet_queue_t *obj, int value);
extern int of_packet_queue_OF_VERSION_1_1_check_scalars(
    of_packet_queue_t *obj, int value);

extern int of_port_desc_OF_VERSION_1_1_populate(
    of_port_desc_t *obj, int value);
extern int of_port_desc_OF_VERSION_1_1_check(
    of_port_desc_t *obj, int value);
extern int of_port_desc_OF_VERSION_1_1_populate_scalars(
    of_port_desc_t *obj, int value);
extern int of_port_desc_OF_VERSION_1_1_check_scalars(
    of_port_desc_t *obj, int value);

extern int of_port_stats_entry_OF_VERSION_1_1_populate(
    of_port_stats_entry_t *obj, int value);
extern int of_port_stats_entry_OF_VERSION_1_1_check(
    of_port_stats_entry_t *obj, int value);
extern int of_port_stats_entry_OF_VERSION_1_1_populate_scalars(
    of_port_stats_entry_t *obj, int value);
extern int of_port_stats_entry_OF_VERSION_1_1_check_scalars(
    of_port_stats_entry_t *obj, int value);

extern int of_queue_prop_min_rate_OF_VERSION_1_1_populate(
    of_queue_prop_min_rate_t *obj, int value);
extern int of_queue_prop_min_rate_OF_VERSION_1_1_check(
    of_queue_prop_min_rate_t *obj, int value);
extern int of_queue_prop_min_rate_OF_VERSION_1_1_populate_scalars(
    of_queue_prop_min_rate_t *obj, int value);
extern int of_queue_prop_min_rate_OF_VERSION_1_1_check_scalars(
    of_queue_prop_min_rate_t *obj, int value);

extern int of_queue_stats_entry_OF_VERSION_1_1_populate(
    of_queue_stats_entry_t *obj, int value);
extern int of_queue_stats_entry_OF_VERSION_1_1_check(
    of_queue_stats_entry_t *obj, int value);
extern int of_queue_stats_entry_OF_VERSION_1_1_populate_scalars(
    of_queue_stats_entry_t *obj, int value);
extern int of_queue_stats_entry_OF_VERSION_1_1_check_scalars(
    of_queue_stats_entry_t *obj, int value);

extern int of_table_stats_entry_OF_VERSION_1_1_populate(
    of_table_stats_entry_t *obj, int value);
extern int of_table_stats_entry_OF_VERSION_1_1_check(
    of_table_stats_entry_t *obj, int value);
extern int of_table_stats_entry_OF_VERSION_1_1_populate_scalars(
    of_table_stats_entry_t *obj, int value);
extern int of_table_stats_entry_OF_VERSION_1_1_check_scalars(
    of_table_stats_entry_t *obj, int value);

extern int of_list_action_OF_VERSION_1_1_populate(
    of_list_action_t *obj, int value);
extern int of_list_action_OF_VERSION_1_1_check(
    of_list_action_t *obj, int value);
extern int of_list_action_OF_VERSION_1_1_populate_scalars(
    of_list_action_t *obj, int value);
extern int of_list_action_OF_VERSION_1_1_check_scalars(
    of_list_action_t *obj, int value);

extern int of_list_bsn_interface_OF_VERSION_1_1_populate(
    of_list_bsn_interface_t *obj, int value);
extern int of_list_bsn_interface_OF_VERSION_1_1_check(
    of_list_bsn_interface_t *obj, int value);
extern int of_list_bsn_interface_OF_VERSION_1_1_populate_scalars(
    of_list_bsn_interface_t *obj, int value);
extern int of_list_bsn_interface_OF_VERSION_1_1_check_scalars(
    of_list_bsn_interface_t *obj, int value);

extern int of_list_bucket_OF_VERSION_1_1_populate(
    of_list_bucket_t *obj, int value);
extern int of_list_bucket_OF_VERSION_1_1_check(
    of_list_bucket_t *obj, int value);
extern int of_list_bucket_OF_VERSION_1_1_populate_scalars(
    of_list_bucket_t *obj, int value);
extern int of_list_bucket_OF_VERSION_1_1_check_scalars(
    of_list_bucket_t *obj, int value);

extern int of_list_bucket_counter_OF_VERSION_1_1_populate(
    of_list_bucket_counter_t *obj, int value);
extern int of_list_bucket_counter_OF_VERSION_1_1_check(
    of_list_bucket_counter_t *obj, int value);
extern int of_list_bucket_counter_OF_VERSION_1_1_populate_scalars(
    of_list_bucket_counter_t *obj, int value);
extern int of_list_bucket_counter_OF_VERSION_1_1_check_scalars(
    of_list_bucket_counter_t *obj, int value);

extern int of_list_flow_stats_entry_OF_VERSION_1_1_populate(
    of_list_flow_stats_entry_t *obj, int value);
extern int of_list_flow_stats_entry_OF_VERSION_1_1_check(
    of_list_flow_stats_entry_t *obj, int value);
extern int of_list_flow_stats_entry_OF_VERSION_1_1_populate_scalars(
    of_list_flow_stats_entry_t *obj, int value);
extern int of_list_flow_stats_entry_OF_VERSION_1_1_check_scalars(
    of_list_flow_stats_entry_t *obj, int value);

extern int of_list_group_desc_stats_entry_OF_VERSION_1_1_populate(
    of_list_group_desc_stats_entry_t *obj, int value);
extern int of_list_group_desc_stats_entry_OF_VERSION_1_1_check(
    of_list_group_desc_stats_entry_t *obj, int value);
extern int of_list_group_desc_stats_entry_OF_VERSION_1_1_populate_scalars(
    of_list_group_desc_stats_entry_t *obj, int value);
extern int of_list_group_desc_stats_entry_OF_VERSION_1_1_check_scalars(
    of_list_group_desc_stats_entry_t *obj, int value);

extern int of_list_group_stats_entry_OF_VERSION_1_1_populate(
    of_list_group_stats_entry_t *obj, int value);
extern int of_list_group_stats_entry_OF_VERSION_1_1_check(
    of_list_group_stats_entry_t *obj, int value);
extern int of_list_group_stats_entry_OF_VERSION_1_1_populate_scalars(
    of_list_group_stats_entry_t *obj, int value);
extern int of_list_group_stats_entry_OF_VERSION_1_1_check_scalars(
    of_list_group_stats_entry_t *obj, int value);

extern int of_list_instruction_OF_VERSION_1_1_populate(
    of_list_instruction_t *obj, int value);
extern int of_list_instruction_OF_VERSION_1_1_check(
    of_list_instruction_t *obj, int value);
extern int of_list_instruction_OF_VERSION_1_1_populate_scalars(
    of_list_instruction_t *obj, int value);
extern int of_list_instruction_OF_VERSION_1_1_check_scalars(
    of_list_instruction_t *obj, int value);

extern int of_list_packet_queue_OF_VERSION_1_1_populate(
    of_list_packet_queue_t *obj, int value);
extern int of_list_packet_queue_OF_VERSION_1_1_check(
    of_list_packet_queue_t *obj, int value);
extern int of_list_packet_queue_OF_VERSION_1_1_populate_scalars(
    of_list_packet_queue_t *obj, int value);
extern int of_list_packet_queue_OF_VERSION_1_1_check_scalars(
    of_list_packet_queue_t *obj, int value);

extern int of_list_port_desc_OF_VERSION_1_1_populate(
    of_list_port_desc_t *obj, int value);
extern int of_list_port_desc_OF_VERSION_1_1_check(
    of_list_port_desc_t *obj, int value);
extern int of_list_port_desc_OF_VERSION_1_1_populate_scalars(
    of_list_port_desc_t *obj, int value);
extern int of_list_port_desc_OF_VERSION_1_1_check_scalars(
    of_list_port_desc_t *obj, int value);

extern int of_list_port_stats_entry_OF_VERSION_1_1_populate(
    of_list_port_stats_entry_t *obj, int value);
extern int of_list_port_stats_entry_OF_VERSION_1_1_check(
    of_list_port_stats_entry_t *obj, int value);
extern int of_list_port_stats_entry_OF_VERSION_1_1_populate_scalars(
    of_list_port_stats_entry_t *obj, int value);
extern int of_list_port_stats_entry_OF_VERSION_1_1_check_scalars(
    of_list_port_stats_entry_t *obj, int value);

extern int of_list_queue_prop_OF_VERSION_1_1_populate(
    of_list_queue_prop_t *obj, int value);
extern int of_list_queue_prop_OF_VERSION_1_1_check(
    of_list_queue_prop_t *obj, int value);
extern int of_list_queue_prop_OF_VERSION_1_1_populate_scalars(
    of_list_queue_prop_t *obj, int value);
extern int of_list_queue_prop_OF_VERSION_1_1_check_scalars(
    of_list_queue_prop_t *obj, int value);

extern int of_list_queue_stats_entry_OF_VERSION_1_1_populate(
    of_list_queue_stats_entry_t *obj, int value);
extern int of_list_queue_stats_entry_OF_VERSION_1_1_check(
    of_list_queue_stats_entry_t *obj, int value);
extern int of_list_queue_stats_entry_OF_VERSION_1_1_populate_scalars(
    of_list_queue_stats_entry_t *obj, int value);
extern int of_list_queue_stats_entry_OF_VERSION_1_1_check_scalars(
    of_list_queue_stats_entry_t *obj, int value);

extern int of_list_table_stats_entry_OF_VERSION_1_1_populate(
    of_list_table_stats_entry_t *obj, int value);
extern int of_list_table_stats_entry_OF_VERSION_1_1_check(
    of_list_table_stats_entry_t *obj, int value);
extern int of_list_table_stats_entry_OF_VERSION_1_1_populate_scalars(
    of_list_table_stats_entry_t *obj, int value);
extern int of_list_table_stats_entry_OF_VERSION_1_1_check_scalars(
    of_list_table_stats_entry_t *obj, int value);

extern int of_aggregate_stats_reply_OF_VERSION_1_2_populate(
    of_aggregate_stats_reply_t *obj, int value);
extern int of_aggregate_stats_reply_OF_VERSION_1_2_check(
    of_aggregate_stats_reply_t *obj, int value);
extern int of_aggregate_stats_reply_OF_VERSION_1_2_populate_scalars(
    of_aggregate_stats_reply_t *obj, int value);
extern int of_aggregate_stats_reply_OF_VERSION_1_2_check_scalars(
    of_aggregate_stats_reply_t *obj, int value);

extern int of_aggregate_stats_request_OF_VERSION_1_2_populate(
    of_aggregate_stats_request_t *obj, int value);
extern int of_aggregate_stats_request_OF_VERSION_1_2_check(
    of_aggregate_stats_request_t *obj, int value);
extern int of_aggregate_stats_request_OF_VERSION_1_2_populate_scalars(
    of_aggregate_stats_request_t *obj, int value);
extern int of_aggregate_stats_request_OF_VERSION_1_2_check_scalars(
    of_aggregate_stats_request_t *obj, int value);

extern int of_bad_action_error_msg_OF_VERSION_1_2_populate(
    of_bad_action_error_msg_t *obj, int value);
extern int of_bad_action_error_msg_OF_VERSION_1_2_check(
    of_bad_action_error_msg_t *obj, int value);
extern int of_bad_action_error_msg_OF_VERSION_1_2_populate_scalars(
    of_bad_action_error_msg_t *obj, int value);
extern int of_bad_action_error_msg_OF_VERSION_1_2_check_scalars(
    of_bad_action_error_msg_t *obj, int value);

extern int of_bad_instruction_error_msg_OF_VERSION_1_2_populate(
    of_bad_instruction_error_msg_t *obj, int value);
extern int of_bad_instruction_error_msg_OF_VERSION_1_2_check(
    of_bad_instruction_error_msg_t *obj, int value);
extern int of_bad_instruction_error_msg_OF_VERSION_1_2_populate_scalars(
    of_bad_instruction_error_msg_t *obj, int value);
extern int of_bad_instruction_error_msg_OF_VERSION_1_2_check_scalars(
    of_bad_instruction_error_msg_t *obj, int value);

extern int of_bad_match_error_msg_OF_VERSION_1_2_populate(
    of_bad_match_error_msg_t *obj, int value);
extern int of_bad_match_error_msg_OF_VERSION_1_2_check(
    of_bad_match_error_msg_t *obj, int value);
extern int of_bad_match_error_msg_OF_VERSION_1_2_populate_scalars(
    of_bad_match_error_msg_t *obj, int value);
extern int of_bad_match_error_msg_OF_VERSION_1_2_check_scalars(
    of_bad_match_error_msg_t *obj, int value);

extern int of_bad_request_error_msg_OF_VERSION_1_2_populate(
    of_bad_request_error_msg_t *obj, int value);
extern int of_bad_request_error_msg_OF_VERSION_1_2_check(
    of_bad_request_error_msg_t *obj, int value);
extern int of_bad_request_error_msg_OF_VERSION_1_2_populate_scalars(
    of_bad_request_error_msg_t *obj, int value);
extern int of_bad_request_error_msg_OF_VERSION_1_2_check_scalars(
    of_bad_request_error_msg_t *obj, int value);

extern int of_barrier_reply_OF_VERSION_1_2_populate(
    of_barrier_reply_t *obj, int value);
extern int of_barrier_reply_OF_VERSION_1_2_check(
    of_barrier_reply_t *obj, int value);
extern int of_barrier_reply_OF_VERSION_1_2_populate_scalars(
    of_barrier_reply_t *obj, int value);
extern int of_barrier_reply_OF_VERSION_1_2_check_scalars(
    of_barrier_reply_t *obj, int value);

extern int of_barrier_request_OF_VERSION_1_2_populate(
    of_barrier_request_t *obj, int value);
extern int of_barrier_request_OF_VERSION_1_2_check(
    of_barrier_request_t *obj, int value);
extern int of_barrier_request_OF_VERSION_1_2_populate_scalars(
    of_barrier_request_t *obj, int value);
extern int of_barrier_request_OF_VERSION_1_2_check_scalars(
    of_barrier_request_t *obj, int value);

extern int of_bsn_bw_clear_data_reply_OF_VERSION_1_2_populate(
    of_bsn_bw_clear_data_reply_t *obj, int value);
extern int of_bsn_bw_clear_data_reply_OF_VERSION_1_2_check(
    of_bsn_bw_clear_data_reply_t *obj, int value);
extern int of_bsn_bw_clear_data_reply_OF_VERSION_1_2_populate_scalars(
    of_bsn_bw_clear_data_reply_t *obj, int value);
extern int of_bsn_bw_clear_data_reply_OF_VERSION_1_2_check_scalars(
    of_bsn_bw_clear_data_reply_t *obj, int value);

extern int of_bsn_bw_clear_data_request_OF_VERSION_1_2_populate(
    of_bsn_bw_clear_data_request_t *obj, int value);
extern int of_bsn_bw_clear_data_request_OF_VERSION_1_2_check(
    of_bsn_bw_clear_data_request_t *obj, int value);
extern int of_bsn_bw_clear_data_request_OF_VERSION_1_2_populate_scalars(
    of_bsn_bw_clear_data_request_t *obj, int value);
extern int of_bsn_bw_clear_data_request_OF_VERSION_1_2_check_scalars(
    of_bsn_bw_clear_data_request_t *obj, int value);

extern int of_bsn_bw_enable_get_reply_OF_VERSION_1_2_populate(
    of_bsn_bw_enable_get_reply_t *obj, int value);
extern int of_bsn_bw_enable_get_reply_OF_VERSION_1_2_check(
    of_bsn_bw_enable_get_reply_t *obj, int value);
extern int of_bsn_bw_enable_get_reply_OF_VERSION_1_2_populate_scalars(
    of_bsn_bw_enable_get_reply_t *obj, int value);
extern int of_bsn_bw_enable_get_reply_OF_VERSION_1_2_check_scalars(
    of_bsn_bw_enable_get_reply_t *obj, int value);

extern int of_bsn_bw_enable_get_request_OF_VERSION_1_2_populate(
    of_bsn_bw_enable_get_request_t *obj, int value);
extern int of_bsn_bw_enable_get_request_OF_VERSION_1_2_check(
    of_bsn_bw_enable_get_request_t *obj, int value);
extern int of_bsn_bw_enable_get_request_OF_VERSION_1_2_populate_scalars(
    of_bsn_bw_enable_get_request_t *obj, int value);
extern int of_bsn_bw_enable_get_request_OF_VERSION_1_2_check_scalars(
    of_bsn_bw_enable_get_request_t *obj, int value);

extern int of_bsn_bw_enable_set_reply_OF_VERSION_1_2_populate(
    of_bsn_bw_enable_set_reply_t *obj, int value);
extern int of_bsn_bw_enable_set_reply_OF_VERSION_1_2_check(
    of_bsn_bw_enable_set_reply_t *obj, int value);
extern int of_bsn_bw_enable_set_reply_OF_VERSION_1_2_populate_scalars(
    of_bsn_bw_enable_set_reply_t *obj, int value);
extern int of_bsn_bw_enable_set_reply_OF_VERSION_1_2_check_scalars(
    of_bsn_bw_enable_set_reply_t *obj, int value);

extern int of_bsn_bw_enable_set_request_OF_VERSION_1_2_populate(
    of_bsn_bw_enable_set_request_t *obj, int value);
extern int of_bsn_bw_enable_set_request_OF_VERSION_1_2_check(
    of_bsn_bw_enable_set_request_t *obj, int value);
extern int of_bsn_bw_enable_set_request_OF_VERSION_1_2_populate_scalars(
    of_bsn_bw_enable_set_request_t *obj, int value);
extern int of_bsn_bw_enable_set_request_OF_VERSION_1_2_check_scalars(
    of_bsn_bw_enable_set_request_t *obj, int value);

extern int of_bsn_get_interfaces_reply_OF_VERSION_1_2_populate(
    of_bsn_get_interfaces_reply_t *obj, int value);
extern int of_bsn_get_interfaces_reply_OF_VERSION_1_2_check(
    of_bsn_get_interfaces_reply_t *obj, int value);
extern int of_bsn_get_interfaces_reply_OF_VERSION_1_2_populate_scalars(
    of_bsn_get_interfaces_reply_t *obj, int value);
extern int of_bsn_get_interfaces_reply_OF_VERSION_1_2_check_scalars(
    of_bsn_get_interfaces_reply_t *obj, int value);

extern int of_bsn_get_interfaces_request_OF_VERSION_1_2_populate(
    of_bsn_get_interfaces_request_t *obj, int value);
extern int of_bsn_get_interfaces_request_OF_VERSION_1_2_check(
    of_bsn_get_interfaces_request_t *obj, int value);
extern int of_bsn_get_interfaces_request_OF_VERSION_1_2_populate_scalars(
    of_bsn_get_interfaces_request_t *obj, int value);
extern int of_bsn_get_interfaces_request_OF_VERSION_1_2_check_scalars(
    of_bsn_get_interfaces_request_t *obj, int value);

extern int of_bsn_get_mirroring_reply_OF_VERSION_1_2_populate(
    of_bsn_get_mirroring_reply_t *obj, int value);
extern int of_bsn_get_mirroring_reply_OF_VERSION_1_2_check(
    of_bsn_get_mirroring_reply_t *obj, int value);
extern int of_bsn_get_mirroring_reply_OF_VERSION_1_2_populate_scalars(
    of_bsn_get_mirroring_reply_t *obj, int value);
extern int of_bsn_get_mirroring_reply_OF_VERSION_1_2_check_scalars(
    of_bsn_get_mirroring_reply_t *obj, int value);

extern int of_bsn_get_mirroring_request_OF_VERSION_1_2_populate(
    of_bsn_get_mirroring_request_t *obj, int value);
extern int of_bsn_get_mirroring_request_OF_VERSION_1_2_check(
    of_bsn_get_mirroring_request_t *obj, int value);
extern int of_bsn_get_mirroring_request_OF_VERSION_1_2_populate_scalars(
    of_bsn_get_mirroring_request_t *obj, int value);
extern int of_bsn_get_mirroring_request_OF_VERSION_1_2_check_scalars(
    of_bsn_get_mirroring_request_t *obj, int value);

extern int of_bsn_pdu_rx_reply_OF_VERSION_1_2_populate(
    of_bsn_pdu_rx_reply_t *obj, int value);
extern int of_bsn_pdu_rx_reply_OF_VERSION_1_2_check(
    of_bsn_pdu_rx_reply_t *obj, int value);
extern int of_bsn_pdu_rx_reply_OF_VERSION_1_2_populate_scalars(
    of_bsn_pdu_rx_reply_t *obj, int value);
extern int of_bsn_pdu_rx_reply_OF_VERSION_1_2_check_scalars(
    of_bsn_pdu_rx_reply_t *obj, int value);

extern int of_bsn_pdu_rx_request_OF_VERSION_1_2_populate(
    of_bsn_pdu_rx_request_t *obj, int value);
extern int of_bsn_pdu_rx_request_OF_VERSION_1_2_check(
    of_bsn_pdu_rx_request_t *obj, int value);
extern int of_bsn_pdu_rx_request_OF_VERSION_1_2_populate_scalars(
    of_bsn_pdu_rx_request_t *obj, int value);
extern int of_bsn_pdu_rx_request_OF_VERSION_1_2_check_scalars(
    of_bsn_pdu_rx_request_t *obj, int value);

extern int of_bsn_pdu_rx_timeout_OF_VERSION_1_2_populate(
    of_bsn_pdu_rx_timeout_t *obj, int value);
extern int of_bsn_pdu_rx_timeout_OF_VERSION_1_2_check(
    of_bsn_pdu_rx_timeout_t *obj, int value);
extern int of_bsn_pdu_rx_timeout_OF_VERSION_1_2_populate_scalars(
    of_bsn_pdu_rx_timeout_t *obj, int value);
extern int of_bsn_pdu_rx_timeout_OF_VERSION_1_2_check_scalars(
    of_bsn_pdu_rx_timeout_t *obj, int value);

extern int of_bsn_pdu_tx_reply_OF_VERSION_1_2_populate(
    of_bsn_pdu_tx_reply_t *obj, int value);
extern int of_bsn_pdu_tx_reply_OF_VERSION_1_2_check(
    of_bsn_pdu_tx_reply_t *obj, int value);
extern int of_bsn_pdu_tx_reply_OF_VERSION_1_2_populate_scalars(
    of_bsn_pdu_tx_reply_t *obj, int value);
extern int of_bsn_pdu_tx_reply_OF_VERSION_1_2_check_scalars(
    of_bsn_pdu_tx_reply_t *obj, int value);

extern int of_bsn_pdu_tx_request_OF_VERSION_1_2_populate(
    of_bsn_pdu_tx_request_t *obj, int value);
extern int of_bsn_pdu_tx_request_OF_VERSION_1_2_check(
    of_bsn_pdu_tx_request_t *obj, int value);
extern int of_bsn_pdu_tx_request_OF_VERSION_1_2_populate_scalars(
    of_bsn_pdu_tx_request_t *obj, int value);
extern int of_bsn_pdu_tx_request_OF_VERSION_1_2_check_scalars(
    of_bsn_pdu_tx_request_t *obj, int value);

extern int of_bsn_set_mirroring_OF_VERSION_1_2_populate(
    of_bsn_set_mirroring_t *obj, int value);
extern int of_bsn_set_mirroring_OF_VERSION_1_2_check(
    of_bsn_set_mirroring_t *obj, int value);
extern int of_bsn_set_mirroring_OF_VERSION_1_2_populate_scalars(
    of_bsn_set_mirroring_t *obj, int value);
extern int of_bsn_set_mirroring_OF_VERSION_1_2_check_scalars(
    of_bsn_set_mirroring_t *obj, int value);

extern int of_bsn_set_pktin_suppression_reply_OF_VERSION_1_2_populate(
    of_bsn_set_pktin_suppression_reply_t *obj, int value);
extern int of_bsn_set_pktin_suppression_reply_OF_VERSION_1_2_check(
    of_bsn_set_pktin_suppression_reply_t *obj, int value);
extern int of_bsn_set_pktin_suppression_reply_OF_VERSION_1_2_populate_scalars(
    of_bsn_set_pktin_suppression_reply_t *obj, int value);
extern int of_bsn_set_pktin_suppression_reply_OF_VERSION_1_2_check_scalars(
    of_bsn_set_pktin_suppression_reply_t *obj, int value);

extern int of_bsn_set_pktin_suppression_request_OF_VERSION_1_2_populate(
    of_bsn_set_pktin_suppression_request_t *obj, int value);
extern int of_bsn_set_pktin_suppression_request_OF_VERSION_1_2_check(
    of_bsn_set_pktin_suppression_request_t *obj, int value);
extern int of_bsn_set_pktin_suppression_request_OF_VERSION_1_2_populate_scalars(
    of_bsn_set_pktin_suppression_request_t *obj, int value);
extern int of_bsn_set_pktin_suppression_request_OF_VERSION_1_2_check_scalars(
    of_bsn_set_pktin_suppression_request_t *obj, int value);

extern int of_bsn_virtual_port_create_reply_OF_VERSION_1_2_populate(
    of_bsn_virtual_port_create_reply_t *obj, int value);
extern int of_bsn_virtual_port_create_reply_OF_VERSION_1_2_check(
    of_bsn_virtual_port_create_reply_t *obj, int value);
extern int of_bsn_virtual_port_create_reply_OF_VERSION_1_2_populate_scalars(
    of_bsn_virtual_port_create_reply_t *obj, int value);
extern int of_bsn_virtual_port_create_reply_OF_VERSION_1_2_check_scalars(
    of_bsn_virtual_port_create_reply_t *obj, int value);

extern int of_bsn_virtual_port_create_request_OF_VERSION_1_2_populate(
    of_bsn_virtual_port_create_request_t *obj, int value);
extern int of_bsn_virtual_port_create_request_OF_VERSION_1_2_check(
    of_bsn_virtual_port_create_request_t *obj, int value);
extern int of_bsn_virtual_port_create_request_OF_VERSION_1_2_populate_scalars(
    of_bsn_virtual_port_create_request_t *obj, int value);
extern int of_bsn_virtual_port_create_request_OF_VERSION_1_2_check_scalars(
    of_bsn_virtual_port_create_request_t *obj, int value);

extern int of_bsn_virtual_port_remove_reply_OF_VERSION_1_2_populate(
    of_bsn_virtual_port_remove_reply_t *obj, int value);
extern int of_bsn_virtual_port_remove_reply_OF_VERSION_1_2_check(
    of_bsn_virtual_port_remove_reply_t *obj, int value);
extern int of_bsn_virtual_port_remove_reply_OF_VERSION_1_2_populate_scalars(
    of_bsn_virtual_port_remove_reply_t *obj, int value);
extern int of_bsn_virtual_port_remove_reply_OF_VERSION_1_2_check_scalars(
    of_bsn_virtual_port_remove_reply_t *obj, int value);

extern int of_bsn_virtual_port_remove_request_OF_VERSION_1_2_populate(
    of_bsn_virtual_port_remove_request_t *obj, int value);
extern int of_bsn_virtual_port_remove_request_OF_VERSION_1_2_check(
    of_bsn_virtual_port_remove_request_t *obj, int value);
extern int of_bsn_virtual_port_remove_request_OF_VERSION_1_2_populate_scalars(
    of_bsn_virtual_port_remove_request_t *obj, int value);
extern int of_bsn_virtual_port_remove_request_OF_VERSION_1_2_check_scalars(
    of_bsn_virtual_port_remove_request_t *obj, int value);

extern int of_desc_stats_reply_OF_VERSION_1_2_populate(
    of_desc_stats_reply_t *obj, int value);
extern int of_desc_stats_reply_OF_VERSION_1_2_check(
    of_desc_stats_reply_t *obj, int value);
extern int of_desc_stats_reply_OF_VERSION_1_2_populate_scalars(
    of_desc_stats_reply_t *obj, int value);
extern int of_desc_stats_reply_OF_VERSION_1_2_check_scalars(
    of_desc_stats_reply_t *obj, int value);

extern int of_desc_stats_request_OF_VERSION_1_2_populate(
    of_desc_stats_request_t *obj, int value);
extern int of_desc_stats_request_OF_VERSION_1_2_check(
    of_desc_stats_request_t *obj, int value);
extern int of_desc_stats_request_OF_VERSION_1_2_populate_scalars(
    of_desc_stats_request_t *obj, int value);
extern int of_desc_stats_request_OF_VERSION_1_2_check_scalars(
    of_desc_stats_request_t *obj, int value);

extern int of_echo_reply_OF_VERSION_1_2_populate(
    of_echo_reply_t *obj, int value);
extern int of_echo_reply_OF_VERSION_1_2_check(
    of_echo_reply_t *obj, int value);
extern int of_echo_reply_OF_VERSION_1_2_populate_scalars(
    of_echo_reply_t *obj, int value);
extern int of_echo_reply_OF_VERSION_1_2_check_scalars(
    of_echo_reply_t *obj, int value);

extern int of_echo_request_OF_VERSION_1_2_populate(
    of_echo_request_t *obj, int value);
extern int of_echo_request_OF_VERSION_1_2_check(
    of_echo_request_t *obj, int value);
extern int of_echo_request_OF_VERSION_1_2_populate_scalars(
    of_echo_request_t *obj, int value);
extern int of_echo_request_OF_VERSION_1_2_check_scalars(
    of_echo_request_t *obj, int value);

extern int of_features_reply_OF_VERSION_1_2_populate(
    of_features_reply_t *obj, int value);
extern int of_features_reply_OF_VERSION_1_2_check(
    of_features_reply_t *obj, int value);
extern int of_features_reply_OF_VERSION_1_2_populate_scalars(
    of_features_reply_t *obj, int value);
extern int of_features_reply_OF_VERSION_1_2_check_scalars(
    of_features_reply_t *obj, int value);

extern int of_features_request_OF_VERSION_1_2_populate(
    of_features_request_t *obj, int value);
extern int of_features_request_OF_VERSION_1_2_check(
    of_features_request_t *obj, int value);
extern int of_features_request_OF_VERSION_1_2_populate_scalars(
    of_features_request_t *obj, int value);
extern int of_features_request_OF_VERSION_1_2_check_scalars(
    of_features_request_t *obj, int value);

extern int of_flow_add_OF_VERSION_1_2_populate(
    of_flow_add_t *obj, int value);
extern int of_flow_add_OF_VERSION_1_2_check(
    of_flow_add_t *obj, int value);
extern int of_flow_add_OF_VERSION_1_2_populate_scalars(
    of_flow_add_t *obj, int value);
extern int of_flow_add_OF_VERSION_1_2_check_scalars(
    of_flow_add_t *obj, int value);

extern int of_flow_delete_OF_VERSION_1_2_populate(
    of_flow_delete_t *obj, int value);
extern int of_flow_delete_OF_VERSION_1_2_check(
    of_flow_delete_t *obj, int value);
extern int of_flow_delete_OF_VERSION_1_2_populate_scalars(
    of_flow_delete_t *obj, int value);
extern int of_flow_delete_OF_VERSION_1_2_check_scalars(
    of_flow_delete_t *obj, int value);

extern int of_flow_delete_strict_OF_VERSION_1_2_populate(
    of_flow_delete_strict_t *obj, int value);
extern int of_flow_delete_strict_OF_VERSION_1_2_check(
    of_flow_delete_strict_t *obj, int value);
extern int of_flow_delete_strict_OF_VERSION_1_2_populate_scalars(
    of_flow_delete_strict_t *obj, int value);
extern int of_flow_delete_strict_OF_VERSION_1_2_check_scalars(
    of_flow_delete_strict_t *obj, int value);

extern int of_flow_mod_failed_error_msg_OF_VERSION_1_2_populate(
    of_flow_mod_failed_error_msg_t *obj, int value);
extern int of_flow_mod_failed_error_msg_OF_VERSION_1_2_check(
    of_flow_mod_failed_error_msg_t *obj, int value);
extern int of_flow_mod_failed_error_msg_OF_VERSION_1_2_populate_scalars(
    of_flow_mod_failed_error_msg_t *obj, int value);
extern int of_flow_mod_failed_error_msg_OF_VERSION_1_2_check_scalars(
    of_flow_mod_failed_error_msg_t *obj, int value);

extern int of_flow_modify_OF_VERSION_1_2_populate(
    of_flow_modify_t *obj, int value);
extern int of_flow_modify_OF_VERSION_1_2_check(
    of_flow_modify_t *obj, int value);
extern int of_flow_modify_OF_VERSION_1_2_populate_scalars(
    of_flow_modify_t *obj, int value);
extern int of_flow_modify_OF_VERSION_1_2_check_scalars(
    of_flow_modify_t *obj, int value);

extern int of_flow_modify_strict_OF_VERSION_1_2_populate(
    of_flow_modify_strict_t *obj, int value);
extern int of_flow_modify_strict_OF_VERSION_1_2_check(
    of_flow_modify_strict_t *obj, int value);
extern int of_flow_modify_strict_OF_VERSION_1_2_populate_scalars(
    of_flow_modify_strict_t *obj, int value);
extern int of_flow_modify_strict_OF_VERSION_1_2_check_scalars(
    of_flow_modify_strict_t *obj, int value);

extern int of_flow_removed_OF_VERSION_1_2_populate(
    of_flow_removed_t *obj, int value);
extern int of_flow_removed_OF_VERSION_1_2_check(
    of_flow_removed_t *obj, int value);
extern int of_flow_removed_OF_VERSION_1_2_populate_scalars(
    of_flow_removed_t *obj, int value);
extern int of_flow_removed_OF_VERSION_1_2_check_scalars(
    of_flow_removed_t *obj, int value);

extern int of_flow_stats_reply_OF_VERSION_1_2_populate(
    of_flow_stats_reply_t *obj, int value);
extern int of_flow_stats_reply_OF_VERSION_1_2_check(
    of_flow_stats_reply_t *obj, int value);
extern int of_flow_stats_reply_OF_VERSION_1_2_populate_scalars(
    of_flow_stats_reply_t *obj, int value);
extern int of_flow_stats_reply_OF_VERSION_1_2_check_scalars(
    of_flow_stats_reply_t *obj, int value);

extern int of_flow_stats_request_OF_VERSION_1_2_populate(
    of_flow_stats_request_t *obj, int value);
extern int of_flow_stats_request_OF_VERSION_1_2_check(
    of_flow_stats_request_t *obj, int value);
extern int of_flow_stats_request_OF_VERSION_1_2_populate_scalars(
    of_flow_stats_request_t *obj, int value);
extern int of_flow_stats_request_OF_VERSION_1_2_check_scalars(
    of_flow_stats_request_t *obj, int value);

extern int of_get_config_reply_OF_VERSION_1_2_populate(
    of_get_config_reply_t *obj, int value);
extern int of_get_config_reply_OF_VERSION_1_2_check(
    of_get_config_reply_t *obj, int value);
extern int of_get_config_reply_OF_VERSION_1_2_populate_scalars(
    of_get_config_reply_t *obj, int value);
extern int of_get_config_reply_OF_VERSION_1_2_check_scalars(
    of_get_config_reply_t *obj, int value);

extern int of_get_config_request_OF_VERSION_1_2_populate(
    of_get_config_request_t *obj, int value);
extern int of_get_config_request_OF_VERSION_1_2_check(
    of_get_config_request_t *obj, int value);
extern int of_get_config_request_OF_VERSION_1_2_populate_scalars(
    of_get_config_request_t *obj, int value);
extern int of_get_config_request_OF_VERSION_1_2_check_scalars(
    of_get_config_request_t *obj, int value);

extern int of_group_add_OF_VERSION_1_2_populate(
    of_group_add_t *obj, int value);
extern int of_group_add_OF_VERSION_1_2_check(
    of_group_add_t *obj, int value);
extern int of_group_add_OF_VERSION_1_2_populate_scalars(
    of_group_add_t *obj, int value);
extern int of_group_add_OF_VERSION_1_2_check_scalars(
    of_group_add_t *obj, int value);

extern int of_group_delete_OF_VERSION_1_2_populate(
    of_group_delete_t *obj, int value);
extern int of_group_delete_OF_VERSION_1_2_check(
    of_group_delete_t *obj, int value);
extern int of_group_delete_OF_VERSION_1_2_populate_scalars(
    of_group_delete_t *obj, int value);
extern int of_group_delete_OF_VERSION_1_2_check_scalars(
    of_group_delete_t *obj, int value);

extern int of_group_desc_stats_reply_OF_VERSION_1_2_populate(
    of_group_desc_stats_reply_t *obj, int value);
extern int of_group_desc_stats_reply_OF_VERSION_1_2_check(
    of_group_desc_stats_reply_t *obj, int value);
extern int of_group_desc_stats_reply_OF_VERSION_1_2_populate_scalars(
    of_group_desc_stats_reply_t *obj, int value);
extern int of_group_desc_stats_reply_OF_VERSION_1_2_check_scalars(
    of_group_desc_stats_reply_t *obj, int value);

extern int of_group_desc_stats_request_OF_VERSION_1_2_populate(
    of_group_desc_stats_request_t *obj, int value);
extern int of_group_desc_stats_request_OF_VERSION_1_2_check(
    of_group_desc_stats_request_t *obj, int value);
extern int of_group_desc_stats_request_OF_VERSION_1_2_populate_scalars(
    of_group_desc_stats_request_t *obj, int value);
extern int of_group_desc_stats_request_OF_VERSION_1_2_check_scalars(
    of_group_desc_stats_request_t *obj, int value);

extern int of_group_features_stats_reply_OF_VERSION_1_2_populate(
    of_group_features_stats_reply_t *obj, int value);
extern int of_group_features_stats_reply_OF_VERSION_1_2_check(
    of_group_features_stats_reply_t *obj, int value);
extern int of_group_features_stats_reply_OF_VERSION_1_2_populate_scalars(
    of_group_features_stats_reply_t *obj, int value);
extern int of_group_features_stats_reply_OF_VERSION_1_2_check_scalars(
    of_group_features_stats_reply_t *obj, int value);

extern int of_group_features_stats_request_OF_VERSION_1_2_populate(
    of_group_features_stats_request_t *obj, int value);
extern int of_group_features_stats_request_OF_VERSION_1_2_check(
    of_group_features_stats_request_t *obj, int value);
extern int of_group_features_stats_request_OF_VERSION_1_2_populate_scalars(
    of_group_features_stats_request_t *obj, int value);
extern int of_group_features_stats_request_OF_VERSION_1_2_check_scalars(
    of_group_features_stats_request_t *obj, int value);

extern int of_group_mod_failed_error_msg_OF_VERSION_1_2_populate(
    of_group_mod_failed_error_msg_t *obj, int value);
extern int of_group_mod_failed_error_msg_OF_VERSION_1_2_check(
    of_group_mod_failed_error_msg_t *obj, int value);
extern int of_group_mod_failed_error_msg_OF_VERSION_1_2_populate_scalars(
    of_group_mod_failed_error_msg_t *obj, int value);
extern int of_group_mod_failed_error_msg_OF_VERSION_1_2_check_scalars(
    of_group_mod_failed_error_msg_t *obj, int value);

extern int of_group_modify_OF_VERSION_1_2_populate(
    of_group_modify_t *obj, int value);
extern int of_group_modify_OF_VERSION_1_2_check(
    of_group_modify_t *obj, int value);
extern int of_group_modify_OF_VERSION_1_2_populate_scalars(
    of_group_modify_t *obj, int value);
extern int of_group_modify_OF_VERSION_1_2_check_scalars(
    of_group_modify_t *obj, int value);

extern int of_group_stats_reply_OF_VERSION_1_2_populate(
    of_group_stats_reply_t *obj, int value);
extern int of_group_stats_reply_OF_VERSION_1_2_check(
    of_group_stats_reply_t *obj, int value);
extern int of_group_stats_reply_OF_VERSION_1_2_populate_scalars(
    of_group_stats_reply_t *obj, int value);
extern int of_group_stats_reply_OF_VERSION_1_2_check_scalars(
    of_group_stats_reply_t *obj, int value);

extern int of_group_stats_request_OF_VERSION_1_2_populate(
    of_group_stats_request_t *obj, int value);
extern int of_group_stats_request_OF_VERSION_1_2_check(
    of_group_stats_request_t *obj, int value);
extern int of_group_stats_request_OF_VERSION_1_2_populate_scalars(
    of_group_stats_request_t *obj, int value);
extern int of_group_stats_request_OF_VERSION_1_2_check_scalars(
    of_group_stats_request_t *obj, int value);

extern int of_hello_OF_VERSION_1_2_populate(
    of_hello_t *obj, int value);
extern int of_hello_OF_VERSION_1_2_check(
    of_hello_t *obj, int value);
extern int of_hello_OF_VERSION_1_2_populate_scalars(
    of_hello_t *obj, int value);
extern int of_hello_OF_VERSION_1_2_check_scalars(
    of_hello_t *obj, int value);

extern int of_hello_failed_error_msg_OF_VERSION_1_2_populate(
    of_hello_failed_error_msg_t *obj, int value);
extern int of_hello_failed_error_msg_OF_VERSION_1_2_check(
    of_hello_failed_error_msg_t *obj, int value);
extern int of_hello_failed_error_msg_OF_VERSION_1_2_populate_scalars(
    of_hello_failed_error_msg_t *obj, int value);
extern int of_hello_failed_error_msg_OF_VERSION_1_2_check_scalars(
    of_hello_failed_error_msg_t *obj, int value);

extern int of_packet_in_OF_VERSION_1_2_populate(
    of_packet_in_t *obj, int value);
extern int of_packet_in_OF_VERSION_1_2_check(
    of_packet_in_t *obj, int value);
extern int of_packet_in_OF_VERSION_1_2_populate_scalars(
    of_packet_in_t *obj, int value);
extern int of_packet_in_OF_VERSION_1_2_check_scalars(
    of_packet_in_t *obj, int value);

extern int of_packet_out_OF_VERSION_1_2_populate(
    of_packet_out_t *obj, int value);
extern int of_packet_out_OF_VERSION_1_2_check(
    of_packet_out_t *obj, int value);
extern int of_packet_out_OF_VERSION_1_2_populate_scalars(
    of_packet_out_t *obj, int value);
extern int of_packet_out_OF_VERSION_1_2_check_scalars(
    of_packet_out_t *obj, int value);

extern int of_port_mod_OF_VERSION_1_2_populate(
    of_port_mod_t *obj, int value);
extern int of_port_mod_OF_VERSION_1_2_check(
    of_port_mod_t *obj, int value);
extern int of_port_mod_OF_VERSION_1_2_populate_scalars(
    of_port_mod_t *obj, int value);
extern int of_port_mod_OF_VERSION_1_2_check_scalars(
    of_port_mod_t *obj, int value);

extern int of_port_mod_failed_error_msg_OF_VERSION_1_2_populate(
    of_port_mod_failed_error_msg_t *obj, int value);
extern int of_port_mod_failed_error_msg_OF_VERSION_1_2_check(
    of_port_mod_failed_error_msg_t *obj, int value);
extern int of_port_mod_failed_error_msg_OF_VERSION_1_2_populate_scalars(
    of_port_mod_failed_error_msg_t *obj, int value);
extern int of_port_mod_failed_error_msg_OF_VERSION_1_2_check_scalars(
    of_port_mod_failed_error_msg_t *obj, int value);

extern int of_port_stats_reply_OF_VERSION_1_2_populate(
    of_port_stats_reply_t *obj, int value);
extern int of_port_stats_reply_OF_VERSION_1_2_check(
    of_port_stats_reply_t *obj, int value);
extern int of_port_stats_reply_OF_VERSION_1_2_populate_scalars(
    of_port_stats_reply_t *obj, int value);
extern int of_port_stats_reply_OF_VERSION_1_2_check_scalars(
    of_port_stats_reply_t *obj, int value);

extern int of_port_stats_request_OF_VERSION_1_2_populate(
    of_port_stats_request_t *obj, int value);
extern int of_port_stats_request_OF_VERSION_1_2_check(
    of_port_stats_request_t *obj, int value);
extern int of_port_stats_request_OF_VERSION_1_2_populate_scalars(
    of_port_stats_request_t *obj, int value);
extern int of_port_stats_request_OF_VERSION_1_2_check_scalars(
    of_port_stats_request_t *obj, int value);

extern int of_port_status_OF_VERSION_1_2_populate(
    of_port_status_t *obj, int value);
extern int of_port_status_OF_VERSION_1_2_check(
    of_port_status_t *obj, int value);
extern int of_port_status_OF_VERSION_1_2_populate_scalars(
    of_port_status_t *obj, int value);
extern int of_port_status_OF_VERSION_1_2_check_scalars(
    of_port_status_t *obj, int value);

extern int of_queue_get_config_reply_OF_VERSION_1_2_populate(
    of_queue_get_config_reply_t *obj, int value);
extern int of_queue_get_config_reply_OF_VERSION_1_2_check(
    of_queue_get_config_reply_t *obj, int value);
extern int of_queue_get_config_reply_OF_VERSION_1_2_populate_scalars(
    of_queue_get_config_reply_t *obj, int value);
extern int of_queue_get_config_reply_OF_VERSION_1_2_check_scalars(
    of_queue_get_config_reply_t *obj, int value);

extern int of_queue_get_config_request_OF_VERSION_1_2_populate(
    of_queue_get_config_request_t *obj, int value);
extern int of_queue_get_config_request_OF_VERSION_1_2_check(
    of_queue_get_config_request_t *obj, int value);
extern int of_queue_get_config_request_OF_VERSION_1_2_populate_scalars(
    of_queue_get_config_request_t *obj, int value);
extern int of_queue_get_config_request_OF_VERSION_1_2_check_scalars(
    of_queue_get_config_request_t *obj, int value);

extern int of_queue_op_failed_error_msg_OF_VERSION_1_2_populate(
    of_queue_op_failed_error_msg_t *obj, int value);
extern int of_queue_op_failed_error_msg_OF_VERSION_1_2_check(
    of_queue_op_failed_error_msg_t *obj, int value);
extern int of_queue_op_failed_error_msg_OF_VERSION_1_2_populate_scalars(
    of_queue_op_failed_error_msg_t *obj, int value);
extern int of_queue_op_failed_error_msg_OF_VERSION_1_2_check_scalars(
    of_queue_op_failed_error_msg_t *obj, int value);

extern int of_queue_stats_reply_OF_VERSION_1_2_populate(
    of_queue_stats_reply_t *obj, int value);
extern int of_queue_stats_reply_OF_VERSION_1_2_check(
    of_queue_stats_reply_t *obj, int value);
extern int of_queue_stats_reply_OF_VERSION_1_2_populate_scalars(
    of_queue_stats_reply_t *obj, int value);
extern int of_queue_stats_reply_OF_VERSION_1_2_check_scalars(
    of_queue_stats_reply_t *obj, int value);

extern int of_queue_stats_request_OF_VERSION_1_2_populate(
    of_queue_stats_request_t *obj, int value);
extern int of_queue_stats_request_OF_VERSION_1_2_check(
    of_queue_stats_request_t *obj, int value);
extern int of_queue_stats_request_OF_VERSION_1_2_populate_scalars(
    of_queue_stats_request_t *obj, int value);
extern int of_queue_stats_request_OF_VERSION_1_2_check_scalars(
    of_queue_stats_request_t *obj, int value);

extern int of_role_reply_OF_VERSION_1_2_populate(
    of_role_reply_t *obj, int value);
extern int of_role_reply_OF_VERSION_1_2_check(
    of_role_reply_t *obj, int value);
extern int of_role_reply_OF_VERSION_1_2_populate_scalars(
    of_role_reply_t *obj, int value);
extern int of_role_reply_OF_VERSION_1_2_check_scalars(
    of_role_reply_t *obj, int value);

extern int of_role_request_OF_VERSION_1_2_populate(
    of_role_request_t *obj, int value);
extern int of_role_request_OF_VERSION_1_2_check(
    of_role_request_t *obj, int value);
extern int of_role_request_OF_VERSION_1_2_populate_scalars(
    of_role_request_t *obj, int value);
extern int of_role_request_OF_VERSION_1_2_check_scalars(
    of_role_request_t *obj, int value);

extern int of_role_request_failed_error_msg_OF_VERSION_1_2_populate(
    of_role_request_failed_error_msg_t *obj, int value);
extern int of_role_request_failed_error_msg_OF_VERSION_1_2_check(
    of_role_request_failed_error_msg_t *obj, int value);
extern int of_role_request_failed_error_msg_OF_VERSION_1_2_populate_scalars(
    of_role_request_failed_error_msg_t *obj, int value);
extern int of_role_request_failed_error_msg_OF_VERSION_1_2_check_scalars(
    of_role_request_failed_error_msg_t *obj, int value);

extern int of_set_config_OF_VERSION_1_2_populate(
    of_set_config_t *obj, int value);
extern int of_set_config_OF_VERSION_1_2_check(
    of_set_config_t *obj, int value);
extern int of_set_config_OF_VERSION_1_2_populate_scalars(
    of_set_config_t *obj, int value);
extern int of_set_config_OF_VERSION_1_2_check_scalars(
    of_set_config_t *obj, int value);

extern int of_switch_config_failed_error_msg_OF_VERSION_1_2_populate(
    of_switch_config_failed_error_msg_t *obj, int value);
extern int of_switch_config_failed_error_msg_OF_VERSION_1_2_check(
    of_switch_config_failed_error_msg_t *obj, int value);
extern int of_switch_config_failed_error_msg_OF_VERSION_1_2_populate_scalars(
    of_switch_config_failed_error_msg_t *obj, int value);
extern int of_switch_config_failed_error_msg_OF_VERSION_1_2_check_scalars(
    of_switch_config_failed_error_msg_t *obj, int value);

extern int of_table_mod_OF_VERSION_1_2_populate(
    of_table_mod_t *obj, int value);
extern int of_table_mod_OF_VERSION_1_2_check(
    of_table_mod_t *obj, int value);
extern int of_table_mod_OF_VERSION_1_2_populate_scalars(
    of_table_mod_t *obj, int value);
extern int of_table_mod_OF_VERSION_1_2_check_scalars(
    of_table_mod_t *obj, int value);

extern int of_table_mod_failed_error_msg_OF_VERSION_1_2_populate(
    of_table_mod_failed_error_msg_t *obj, int value);
extern int of_table_mod_failed_error_msg_OF_VERSION_1_2_check(
    of_table_mod_failed_error_msg_t *obj, int value);
extern int of_table_mod_failed_error_msg_OF_VERSION_1_2_populate_scalars(
    of_table_mod_failed_error_msg_t *obj, int value);
extern int of_table_mod_failed_error_msg_OF_VERSION_1_2_check_scalars(
    of_table_mod_failed_error_msg_t *obj, int value);

extern int of_table_stats_reply_OF_VERSION_1_2_populate(
    of_table_stats_reply_t *obj, int value);
extern int of_table_stats_reply_OF_VERSION_1_2_check(
    of_table_stats_reply_t *obj, int value);
extern int of_table_stats_reply_OF_VERSION_1_2_populate_scalars(
    of_table_stats_reply_t *obj, int value);
extern int of_table_stats_reply_OF_VERSION_1_2_check_scalars(
    of_table_stats_reply_t *obj, int value);

extern int of_table_stats_request_OF_VERSION_1_2_populate(
    of_table_stats_request_t *obj, int value);
extern int of_table_stats_request_OF_VERSION_1_2_check(
    of_table_stats_request_t *obj, int value);
extern int of_table_stats_request_OF_VERSION_1_2_populate_scalars(
    of_table_stats_request_t *obj, int value);
extern int of_table_stats_request_OF_VERSION_1_2_check_scalars(
    of_table_stats_request_t *obj, int value);

extern int of_action_bsn_checksum_OF_VERSION_1_2_populate(
    of_action_bsn_checksum_t *obj, int value);
extern int of_action_bsn_checksum_OF_VERSION_1_2_check(
    of_action_bsn_checksum_t *obj, int value);
extern int of_action_bsn_checksum_OF_VERSION_1_2_populate_scalars(
    of_action_bsn_checksum_t *obj, int value);
extern int of_action_bsn_checksum_OF_VERSION_1_2_check_scalars(
    of_action_bsn_checksum_t *obj, int value);

extern int of_action_bsn_mirror_OF_VERSION_1_2_populate(
    of_action_bsn_mirror_t *obj, int value);
extern int of_action_bsn_mirror_OF_VERSION_1_2_check(
    of_action_bsn_mirror_t *obj, int value);
extern int of_action_bsn_mirror_OF_VERSION_1_2_populate_scalars(
    of_action_bsn_mirror_t *obj, int value);
extern int of_action_bsn_mirror_OF_VERSION_1_2_check_scalars(
    of_action_bsn_mirror_t *obj, int value);

extern int of_action_bsn_set_tunnel_dst_OF_VERSION_1_2_populate(
    of_action_bsn_set_tunnel_dst_t *obj, int value);
extern int of_action_bsn_set_tunnel_dst_OF_VERSION_1_2_check(
    of_action_bsn_set_tunnel_dst_t *obj, int value);
extern int of_action_bsn_set_tunnel_dst_OF_VERSION_1_2_populate_scalars(
    of_action_bsn_set_tunnel_dst_t *obj, int value);
extern int of_action_bsn_set_tunnel_dst_OF_VERSION_1_2_check_scalars(
    of_action_bsn_set_tunnel_dst_t *obj, int value);

extern int of_action_copy_ttl_in_OF_VERSION_1_2_populate(
    of_action_copy_ttl_in_t *obj, int value);
extern int of_action_copy_ttl_in_OF_VERSION_1_2_check(
    of_action_copy_ttl_in_t *obj, int value);
extern int of_action_copy_ttl_in_OF_VERSION_1_2_populate_scalars(
    of_action_copy_ttl_in_t *obj, int value);
extern int of_action_copy_ttl_in_OF_VERSION_1_2_check_scalars(
    of_action_copy_ttl_in_t *obj, int value);

extern int of_action_copy_ttl_out_OF_VERSION_1_2_populate(
    of_action_copy_ttl_out_t *obj, int value);
extern int of_action_copy_ttl_out_OF_VERSION_1_2_check(
    of_action_copy_ttl_out_t *obj, int value);
extern int of_action_copy_ttl_out_OF_VERSION_1_2_populate_scalars(
    of_action_copy_ttl_out_t *obj, int value);
extern int of_action_copy_ttl_out_OF_VERSION_1_2_check_scalars(
    of_action_copy_ttl_out_t *obj, int value);

extern int of_action_dec_mpls_ttl_OF_VERSION_1_2_populate(
    of_action_dec_mpls_ttl_t *obj, int value);
extern int of_action_dec_mpls_ttl_OF_VERSION_1_2_check(
    of_action_dec_mpls_ttl_t *obj, int value);
extern int of_action_dec_mpls_ttl_OF_VERSION_1_2_populate_scalars(
    of_action_dec_mpls_ttl_t *obj, int value);
extern int of_action_dec_mpls_ttl_OF_VERSION_1_2_check_scalars(
    of_action_dec_mpls_ttl_t *obj, int value);

extern int of_action_dec_nw_ttl_OF_VERSION_1_2_populate(
    of_action_dec_nw_ttl_t *obj, int value);
extern int of_action_dec_nw_ttl_OF_VERSION_1_2_check(
    of_action_dec_nw_ttl_t *obj, int value);
extern int of_action_dec_nw_ttl_OF_VERSION_1_2_populate_scalars(
    of_action_dec_nw_ttl_t *obj, int value);
extern int of_action_dec_nw_ttl_OF_VERSION_1_2_check_scalars(
    of_action_dec_nw_ttl_t *obj, int value);

extern int of_action_group_OF_VERSION_1_2_populate(
    of_action_group_t *obj, int value);
extern int of_action_group_OF_VERSION_1_2_check(
    of_action_group_t *obj, int value);
extern int of_action_group_OF_VERSION_1_2_populate_scalars(
    of_action_group_t *obj, int value);
extern int of_action_group_OF_VERSION_1_2_check_scalars(
    of_action_group_t *obj, int value);

extern int of_action_nicira_dec_ttl_OF_VERSION_1_2_populate(
    of_action_nicira_dec_ttl_t *obj, int value);
extern int of_action_nicira_dec_ttl_OF_VERSION_1_2_check(
    of_action_nicira_dec_ttl_t *obj, int value);
extern int of_action_nicira_dec_ttl_OF_VERSION_1_2_populate_scalars(
    of_action_nicira_dec_ttl_t *obj, int value);
extern int of_action_nicira_dec_ttl_OF_VERSION_1_2_check_scalars(
    of_action_nicira_dec_ttl_t *obj, int value);

extern int of_action_output_OF_VERSION_1_2_populate(
    of_action_output_t *obj, int value);
extern int of_action_output_OF_VERSION_1_2_check(
    of_action_output_t *obj, int value);
extern int of_action_output_OF_VERSION_1_2_populate_scalars(
    of_action_output_t *obj, int value);
extern int of_action_output_OF_VERSION_1_2_check_scalars(
    of_action_output_t *obj, int value);

extern int of_action_pop_mpls_OF_VERSION_1_2_populate(
    of_action_pop_mpls_t *obj, int value);
extern int of_action_pop_mpls_OF_VERSION_1_2_check(
    of_action_pop_mpls_t *obj, int value);
extern int of_action_pop_mpls_OF_VERSION_1_2_populate_scalars(
    of_action_pop_mpls_t *obj, int value);
extern int of_action_pop_mpls_OF_VERSION_1_2_check_scalars(
    of_action_pop_mpls_t *obj, int value);

extern int of_action_pop_vlan_OF_VERSION_1_2_populate(
    of_action_pop_vlan_t *obj, int value);
extern int of_action_pop_vlan_OF_VERSION_1_2_check(
    of_action_pop_vlan_t *obj, int value);
extern int of_action_pop_vlan_OF_VERSION_1_2_populate_scalars(
    of_action_pop_vlan_t *obj, int value);
extern int of_action_pop_vlan_OF_VERSION_1_2_check_scalars(
    of_action_pop_vlan_t *obj, int value);

extern int of_action_push_mpls_OF_VERSION_1_2_populate(
    of_action_push_mpls_t *obj, int value);
extern int of_action_push_mpls_OF_VERSION_1_2_check(
    of_action_push_mpls_t *obj, int value);
extern int of_action_push_mpls_OF_VERSION_1_2_populate_scalars(
    of_action_push_mpls_t *obj, int value);
extern int of_action_push_mpls_OF_VERSION_1_2_check_scalars(
    of_action_push_mpls_t *obj, int value);

extern int of_action_push_vlan_OF_VERSION_1_2_populate(
    of_action_push_vlan_t *obj, int value);
extern int of_action_push_vlan_OF_VERSION_1_2_check(
    of_action_push_vlan_t *obj, int value);
extern int of_action_push_vlan_OF_VERSION_1_2_populate_scalars(
    of_action_push_vlan_t *obj, int value);
extern int of_action_push_vlan_OF_VERSION_1_2_check_scalars(
    of_action_push_vlan_t *obj, int value);

extern int of_action_set_field_OF_VERSION_1_2_populate(
    of_action_set_field_t *obj, int value);
extern int of_action_set_field_OF_VERSION_1_2_check(
    of_action_set_field_t *obj, int value);
extern int of_action_set_field_OF_VERSION_1_2_populate_scalars(
    of_action_set_field_t *obj, int value);
extern int of_action_set_field_OF_VERSION_1_2_check_scalars(
    of_action_set_field_t *obj, int value);

extern int of_action_set_mpls_ttl_OF_VERSION_1_2_populate(
    of_action_set_mpls_ttl_t *obj, int value);
extern int of_action_set_mpls_ttl_OF_VERSION_1_2_check(
    of_action_set_mpls_ttl_t *obj, int value);
extern int of_action_set_mpls_ttl_OF_VERSION_1_2_populate_scalars(
    of_action_set_mpls_ttl_t *obj, int value);
extern int of_action_set_mpls_ttl_OF_VERSION_1_2_check_scalars(
    of_action_set_mpls_ttl_t *obj, int value);

extern int of_action_set_nw_ttl_OF_VERSION_1_2_populate(
    of_action_set_nw_ttl_t *obj, int value);
extern int of_action_set_nw_ttl_OF_VERSION_1_2_check(
    of_action_set_nw_ttl_t *obj, int value);
extern int of_action_set_nw_ttl_OF_VERSION_1_2_populate_scalars(
    of_action_set_nw_ttl_t *obj, int value);
extern int of_action_set_nw_ttl_OF_VERSION_1_2_check_scalars(
    of_action_set_nw_ttl_t *obj, int value);

extern int of_action_set_queue_OF_VERSION_1_2_populate(
    of_action_set_queue_t *obj, int value);
extern int of_action_set_queue_OF_VERSION_1_2_check(
    of_action_set_queue_t *obj, int value);
extern int of_action_set_queue_OF_VERSION_1_2_populate_scalars(
    of_action_set_queue_t *obj, int value);
extern int of_action_set_queue_OF_VERSION_1_2_check_scalars(
    of_action_set_queue_t *obj, int value);

extern int of_bsn_interface_OF_VERSION_1_2_populate(
    of_bsn_interface_t *obj, int value);
extern int of_bsn_interface_OF_VERSION_1_2_check(
    of_bsn_interface_t *obj, int value);
extern int of_bsn_interface_OF_VERSION_1_2_populate_scalars(
    of_bsn_interface_t *obj, int value);
extern int of_bsn_interface_OF_VERSION_1_2_check_scalars(
    of_bsn_interface_t *obj, int value);

extern int of_bsn_vport_l2gre_OF_VERSION_1_2_populate(
    of_bsn_vport_l2gre_t *obj, int value);
extern int of_bsn_vport_l2gre_OF_VERSION_1_2_check(
    of_bsn_vport_l2gre_t *obj, int value);
extern int of_bsn_vport_l2gre_OF_VERSION_1_2_populate_scalars(
    of_bsn_vport_l2gre_t *obj, int value);
extern int of_bsn_vport_l2gre_OF_VERSION_1_2_check_scalars(
    of_bsn_vport_l2gre_t *obj, int value);

extern int of_bsn_vport_q_in_q_OF_VERSION_1_2_populate(
    of_bsn_vport_q_in_q_t *obj, int value);
extern int of_bsn_vport_q_in_q_OF_VERSION_1_2_check(
    of_bsn_vport_q_in_q_t *obj, int value);
extern int of_bsn_vport_q_in_q_OF_VERSION_1_2_populate_scalars(
    of_bsn_vport_q_in_q_t *obj, int value);
extern int of_bsn_vport_q_in_q_OF_VERSION_1_2_check_scalars(
    of_bsn_vport_q_in_q_t *obj, int value);

extern int of_bucket_OF_VERSION_1_2_populate(
    of_bucket_t *obj, int value);
extern int of_bucket_OF_VERSION_1_2_check(
    of_bucket_t *obj, int value);
extern int of_bucket_OF_VERSION_1_2_populate_scalars(
    of_bucket_t *obj, int value);
extern int of_bucket_OF_VERSION_1_2_check_scalars(
    of_bucket_t *obj, int value);

extern int of_bucket_counter_OF_VERSION_1_2_populate(
    of_bucket_counter_t *obj, int value);
extern int of_bucket_counter_OF_VERSION_1_2_check(
    of_bucket_counter_t *obj, int value);
extern int of_bucket_counter_OF_VERSION_1_2_populate_scalars(
    of_bucket_counter_t *obj, int value);
extern int of_bucket_counter_OF_VERSION_1_2_check_scalars(
    of_bucket_counter_t *obj, int value);

extern int of_flow_stats_entry_OF_VERSION_1_2_populate(
    of_flow_stats_entry_t *obj, int value);
extern int of_flow_stats_entry_OF_VERSION_1_2_check(
    of_flow_stats_entry_t *obj, int value);
extern int of_flow_stats_entry_OF_VERSION_1_2_populate_scalars(
    of_flow_stats_entry_t *obj, int value);
extern int of_flow_stats_entry_OF_VERSION_1_2_check_scalars(
    of_flow_stats_entry_t *obj, int value);

extern int of_group_desc_stats_entry_OF_VERSION_1_2_populate(
    of_group_desc_stats_entry_t *obj, int value);
extern int of_group_desc_stats_entry_OF_VERSION_1_2_check(
    of_group_desc_stats_entry_t *obj, int value);
extern int of_group_desc_stats_entry_OF_VERSION_1_2_populate_scalars(
    of_group_desc_stats_entry_t *obj, int value);
extern int of_group_desc_stats_entry_OF_VERSION_1_2_check_scalars(
    of_group_desc_stats_entry_t *obj, int value);

extern int of_group_stats_entry_OF_VERSION_1_2_populate(
    of_group_stats_entry_t *obj, int value);
extern int of_group_stats_entry_OF_VERSION_1_2_check(
    of_group_stats_entry_t *obj, int value);
extern int of_group_stats_entry_OF_VERSION_1_2_populate_scalars(
    of_group_stats_entry_t *obj, int value);
extern int of_group_stats_entry_OF_VERSION_1_2_check_scalars(
    of_group_stats_entry_t *obj, int value);

extern int of_instruction_apply_actions_OF_VERSION_1_2_populate(
    of_instruction_apply_actions_t *obj, int value);
extern int of_instruction_apply_actions_OF_VERSION_1_2_check(
    of_instruction_apply_actions_t *obj, int value);
extern int of_instruction_apply_actions_OF_VERSION_1_2_populate_scalars(
    of_instruction_apply_actions_t *obj, int value);
extern int of_instruction_apply_actions_OF_VERSION_1_2_check_scalars(
    of_instruction_apply_actions_t *obj, int value);

extern int of_instruction_clear_actions_OF_VERSION_1_2_populate(
    of_instruction_clear_actions_t *obj, int value);
extern int of_instruction_clear_actions_OF_VERSION_1_2_check(
    of_instruction_clear_actions_t *obj, int value);
extern int of_instruction_clear_actions_OF_VERSION_1_2_populate_scalars(
    of_instruction_clear_actions_t *obj, int value);
extern int of_instruction_clear_actions_OF_VERSION_1_2_check_scalars(
    of_instruction_clear_actions_t *obj, int value);

extern int of_instruction_goto_table_OF_VERSION_1_2_populate(
    of_instruction_goto_table_t *obj, int value);
extern int of_instruction_goto_table_OF_VERSION_1_2_check(
    of_instruction_goto_table_t *obj, int value);
extern int of_instruction_goto_table_OF_VERSION_1_2_populate_scalars(
    of_instruction_goto_table_t *obj, int value);
extern int of_instruction_goto_table_OF_VERSION_1_2_check_scalars(
    of_instruction_goto_table_t *obj, int value);

extern int of_instruction_write_actions_OF_VERSION_1_2_populate(
    of_instruction_write_actions_t *obj, int value);
extern int of_instruction_write_actions_OF_VERSION_1_2_check(
    of_instruction_write_actions_t *obj, int value);
extern int of_instruction_write_actions_OF_VERSION_1_2_populate_scalars(
    of_instruction_write_actions_t *obj, int value);
extern int of_instruction_write_actions_OF_VERSION_1_2_check_scalars(
    of_instruction_write_actions_t *obj, int value);

extern int of_instruction_write_metadata_OF_VERSION_1_2_populate(
    of_instruction_write_metadata_t *obj, int value);
extern int of_instruction_write_metadata_OF_VERSION_1_2_check(
    of_instruction_write_metadata_t *obj, int value);
extern int of_instruction_write_metadata_OF_VERSION_1_2_populate_scalars(
    of_instruction_write_metadata_t *obj, int value);
extern int of_instruction_write_metadata_OF_VERSION_1_2_check_scalars(
    of_instruction_write_metadata_t *obj, int value);

extern int of_match_v3_OF_VERSION_1_2_populate(
    of_match_v3_t *obj, int value);
extern int of_match_v3_OF_VERSION_1_2_check(
    of_match_v3_t *obj, int value);
extern int of_match_v3_OF_VERSION_1_2_populate_scalars(
    of_match_v3_t *obj, int value);
extern int of_match_v3_OF_VERSION_1_2_check_scalars(
    of_match_v3_t *obj, int value);

extern int of_oxm_arp_op_OF_VERSION_1_2_populate(
    of_oxm_arp_op_t *obj, int value);
extern int of_oxm_arp_op_OF_VERSION_1_2_check(
    of_oxm_arp_op_t *obj, int value);
extern int of_oxm_arp_op_OF_VERSION_1_2_populate_scalars(
    of_oxm_arp_op_t *obj, int value);
extern int of_oxm_arp_op_OF_VERSION_1_2_check_scalars(
    of_oxm_arp_op_t *obj, int value);

extern int of_oxm_arp_op_masked_OF_VERSION_1_2_populate(
    of_oxm_arp_op_masked_t *obj, int value);
extern int of_oxm_arp_op_masked_OF_VERSION_1_2_check(
    of_oxm_arp_op_masked_t *obj, int value);
extern int of_oxm_arp_op_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_arp_op_masked_t *obj, int value);
extern int of_oxm_arp_op_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_arp_op_masked_t *obj, int value);

extern int of_oxm_arp_sha_OF_VERSION_1_2_populate(
    of_oxm_arp_sha_t *obj, int value);
extern int of_oxm_arp_sha_OF_VERSION_1_2_check(
    of_oxm_arp_sha_t *obj, int value);
extern int of_oxm_arp_sha_OF_VERSION_1_2_populate_scalars(
    of_oxm_arp_sha_t *obj, int value);
extern int of_oxm_arp_sha_OF_VERSION_1_2_check_scalars(
    of_oxm_arp_sha_t *obj, int value);

extern int of_oxm_arp_sha_masked_OF_VERSION_1_2_populate(
    of_oxm_arp_sha_masked_t *obj, int value);
extern int of_oxm_arp_sha_masked_OF_VERSION_1_2_check(
    of_oxm_arp_sha_masked_t *obj, int value);
extern int of_oxm_arp_sha_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_arp_sha_masked_t *obj, int value);
extern int of_oxm_arp_sha_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_arp_sha_masked_t *obj, int value);

extern int of_oxm_arp_spa_OF_VERSION_1_2_populate(
    of_oxm_arp_spa_t *obj, int value);
extern int of_oxm_arp_spa_OF_VERSION_1_2_check(
    of_oxm_arp_spa_t *obj, int value);
extern int of_oxm_arp_spa_OF_VERSION_1_2_populate_scalars(
    of_oxm_arp_spa_t *obj, int value);
extern int of_oxm_arp_spa_OF_VERSION_1_2_check_scalars(
    of_oxm_arp_spa_t *obj, int value);

extern int of_oxm_arp_spa_masked_OF_VERSION_1_2_populate(
    of_oxm_arp_spa_masked_t *obj, int value);
extern int of_oxm_arp_spa_masked_OF_VERSION_1_2_check(
    of_oxm_arp_spa_masked_t *obj, int value);
extern int of_oxm_arp_spa_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_arp_spa_masked_t *obj, int value);
extern int of_oxm_arp_spa_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_arp_spa_masked_t *obj, int value);

extern int of_oxm_arp_tha_OF_VERSION_1_2_populate(
    of_oxm_arp_tha_t *obj, int value);
extern int of_oxm_arp_tha_OF_VERSION_1_2_check(
    of_oxm_arp_tha_t *obj, int value);
extern int of_oxm_arp_tha_OF_VERSION_1_2_populate_scalars(
    of_oxm_arp_tha_t *obj, int value);
extern int of_oxm_arp_tha_OF_VERSION_1_2_check_scalars(
    of_oxm_arp_tha_t *obj, int value);

extern int of_oxm_arp_tha_masked_OF_VERSION_1_2_populate(
    of_oxm_arp_tha_masked_t *obj, int value);
extern int of_oxm_arp_tha_masked_OF_VERSION_1_2_check(
    of_oxm_arp_tha_masked_t *obj, int value);
extern int of_oxm_arp_tha_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_arp_tha_masked_t *obj, int value);
extern int of_oxm_arp_tha_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_arp_tha_masked_t *obj, int value);

extern int of_oxm_arp_tpa_OF_VERSION_1_2_populate(
    of_oxm_arp_tpa_t *obj, int value);
extern int of_oxm_arp_tpa_OF_VERSION_1_2_check(
    of_oxm_arp_tpa_t *obj, int value);
extern int of_oxm_arp_tpa_OF_VERSION_1_2_populate_scalars(
    of_oxm_arp_tpa_t *obj, int value);
extern int of_oxm_arp_tpa_OF_VERSION_1_2_check_scalars(
    of_oxm_arp_tpa_t *obj, int value);

extern int of_oxm_arp_tpa_masked_OF_VERSION_1_2_populate(
    of_oxm_arp_tpa_masked_t *obj, int value);
extern int of_oxm_arp_tpa_masked_OF_VERSION_1_2_check(
    of_oxm_arp_tpa_masked_t *obj, int value);
extern int of_oxm_arp_tpa_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_arp_tpa_masked_t *obj, int value);
extern int of_oxm_arp_tpa_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_arp_tpa_masked_t *obj, int value);

extern int of_oxm_bsn_egr_port_group_id_OF_VERSION_1_2_populate(
    of_oxm_bsn_egr_port_group_id_t *obj, int value);
extern int of_oxm_bsn_egr_port_group_id_OF_VERSION_1_2_check(
    of_oxm_bsn_egr_port_group_id_t *obj, int value);
extern int of_oxm_bsn_egr_port_group_id_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_egr_port_group_id_t *obj, int value);
extern int of_oxm_bsn_egr_port_group_id_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_egr_port_group_id_t *obj, int value);

extern int of_oxm_bsn_egr_port_group_id_masked_OF_VERSION_1_2_populate(
    of_oxm_bsn_egr_port_group_id_masked_t *obj, int value);
extern int of_oxm_bsn_egr_port_group_id_masked_OF_VERSION_1_2_check(
    of_oxm_bsn_egr_port_group_id_masked_t *obj, int value);
extern int of_oxm_bsn_egr_port_group_id_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_egr_port_group_id_masked_t *obj, int value);
extern int of_oxm_bsn_egr_port_group_id_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_egr_port_group_id_masked_t *obj, int value);

extern int of_oxm_bsn_global_vrf_allowed_OF_VERSION_1_2_populate(
    of_oxm_bsn_global_vrf_allowed_t *obj, int value);
extern int of_oxm_bsn_global_vrf_allowed_OF_VERSION_1_2_check(
    of_oxm_bsn_global_vrf_allowed_t *obj, int value);
extern int of_oxm_bsn_global_vrf_allowed_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_global_vrf_allowed_t *obj, int value);
extern int of_oxm_bsn_global_vrf_allowed_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_global_vrf_allowed_t *obj, int value);

extern int of_oxm_bsn_global_vrf_allowed_masked_OF_VERSION_1_2_populate(
    of_oxm_bsn_global_vrf_allowed_masked_t *obj, int value);
extern int of_oxm_bsn_global_vrf_allowed_masked_OF_VERSION_1_2_check(
    of_oxm_bsn_global_vrf_allowed_masked_t *obj, int value);
extern int of_oxm_bsn_global_vrf_allowed_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_global_vrf_allowed_masked_t *obj, int value);
extern int of_oxm_bsn_global_vrf_allowed_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_global_vrf_allowed_masked_t *obj, int value);

extern int of_oxm_bsn_in_ports_128_OF_VERSION_1_2_populate(
    of_oxm_bsn_in_ports_128_t *obj, int value);
extern int of_oxm_bsn_in_ports_128_OF_VERSION_1_2_check(
    of_oxm_bsn_in_ports_128_t *obj, int value);
extern int of_oxm_bsn_in_ports_128_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_in_ports_128_t *obj, int value);
extern int of_oxm_bsn_in_ports_128_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_in_ports_128_t *obj, int value);

extern int of_oxm_bsn_in_ports_128_masked_OF_VERSION_1_2_populate(
    of_oxm_bsn_in_ports_128_masked_t *obj, int value);
extern int of_oxm_bsn_in_ports_128_masked_OF_VERSION_1_2_check(
    of_oxm_bsn_in_ports_128_masked_t *obj, int value);
extern int of_oxm_bsn_in_ports_128_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_in_ports_128_masked_t *obj, int value);
extern int of_oxm_bsn_in_ports_128_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_in_ports_128_masked_t *obj, int value);

extern int of_oxm_bsn_in_ports_512_OF_VERSION_1_2_populate(
    of_oxm_bsn_in_ports_512_t *obj, int value);
extern int of_oxm_bsn_in_ports_512_OF_VERSION_1_2_check(
    of_oxm_bsn_in_ports_512_t *obj, int value);
extern int of_oxm_bsn_in_ports_512_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_in_ports_512_t *obj, int value);
extern int of_oxm_bsn_in_ports_512_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_in_ports_512_t *obj, int value);

extern int of_oxm_bsn_in_ports_512_masked_OF_VERSION_1_2_populate(
    of_oxm_bsn_in_ports_512_masked_t *obj, int value);
extern int of_oxm_bsn_in_ports_512_masked_OF_VERSION_1_2_check(
    of_oxm_bsn_in_ports_512_masked_t *obj, int value);
extern int of_oxm_bsn_in_ports_512_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_in_ports_512_masked_t *obj, int value);
extern int of_oxm_bsn_in_ports_512_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_in_ports_512_masked_t *obj, int value);

extern int of_oxm_bsn_ingress_port_group_id_OF_VERSION_1_2_populate(
    of_oxm_bsn_ingress_port_group_id_t *obj, int value);
extern int of_oxm_bsn_ingress_port_group_id_OF_VERSION_1_2_check(
    of_oxm_bsn_ingress_port_group_id_t *obj, int value);
extern int of_oxm_bsn_ingress_port_group_id_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_ingress_port_group_id_t *obj, int value);
extern int of_oxm_bsn_ingress_port_group_id_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_ingress_port_group_id_t *obj, int value);

extern int of_oxm_bsn_ingress_port_group_id_masked_OF_VERSION_1_2_populate(
    of_oxm_bsn_ingress_port_group_id_masked_t *obj, int value);
extern int of_oxm_bsn_ingress_port_group_id_masked_OF_VERSION_1_2_check(
    of_oxm_bsn_ingress_port_group_id_masked_t *obj, int value);
extern int of_oxm_bsn_ingress_port_group_id_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_ingress_port_group_id_masked_t *obj, int value);
extern int of_oxm_bsn_ingress_port_group_id_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_ingress_port_group_id_masked_t *obj, int value);

extern int of_oxm_bsn_ip_fragmentation_OF_VERSION_1_2_populate(
    of_oxm_bsn_ip_fragmentation_t *obj, int value);
extern int of_oxm_bsn_ip_fragmentation_OF_VERSION_1_2_check(
    of_oxm_bsn_ip_fragmentation_t *obj, int value);
extern int of_oxm_bsn_ip_fragmentation_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_ip_fragmentation_t *obj, int value);
extern int of_oxm_bsn_ip_fragmentation_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_ip_fragmentation_t *obj, int value);

extern int of_oxm_bsn_ip_fragmentation_masked_OF_VERSION_1_2_populate(
    of_oxm_bsn_ip_fragmentation_masked_t *obj, int value);
extern int of_oxm_bsn_ip_fragmentation_masked_OF_VERSION_1_2_check(
    of_oxm_bsn_ip_fragmentation_masked_t *obj, int value);
extern int of_oxm_bsn_ip_fragmentation_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_ip_fragmentation_masked_t *obj, int value);
extern int of_oxm_bsn_ip_fragmentation_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_ip_fragmentation_masked_t *obj, int value);

extern int of_oxm_bsn_l2_cache_hit_OF_VERSION_1_2_populate(
    of_oxm_bsn_l2_cache_hit_t *obj, int value);
extern int of_oxm_bsn_l2_cache_hit_OF_VERSION_1_2_check(
    of_oxm_bsn_l2_cache_hit_t *obj, int value);
extern int of_oxm_bsn_l2_cache_hit_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_l2_cache_hit_t *obj, int value);
extern int of_oxm_bsn_l2_cache_hit_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_l2_cache_hit_t *obj, int value);

extern int of_oxm_bsn_l2_cache_hit_masked_OF_VERSION_1_2_populate(
    of_oxm_bsn_l2_cache_hit_masked_t *obj, int value);
extern int of_oxm_bsn_l2_cache_hit_masked_OF_VERSION_1_2_check(
    of_oxm_bsn_l2_cache_hit_masked_t *obj, int value);
extern int of_oxm_bsn_l2_cache_hit_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_l2_cache_hit_masked_t *obj, int value);
extern int of_oxm_bsn_l2_cache_hit_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_l2_cache_hit_masked_t *obj, int value);

extern int of_oxm_bsn_l3_dst_class_id_OF_VERSION_1_2_populate(
    of_oxm_bsn_l3_dst_class_id_t *obj, int value);
extern int of_oxm_bsn_l3_dst_class_id_OF_VERSION_1_2_check(
    of_oxm_bsn_l3_dst_class_id_t *obj, int value);
extern int of_oxm_bsn_l3_dst_class_id_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_l3_dst_class_id_t *obj, int value);
extern int of_oxm_bsn_l3_dst_class_id_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_l3_dst_class_id_t *obj, int value);

extern int of_oxm_bsn_l3_dst_class_id_masked_OF_VERSION_1_2_populate(
    of_oxm_bsn_l3_dst_class_id_masked_t *obj, int value);
extern int of_oxm_bsn_l3_dst_class_id_masked_OF_VERSION_1_2_check(
    of_oxm_bsn_l3_dst_class_id_masked_t *obj, int value);
extern int of_oxm_bsn_l3_dst_class_id_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_l3_dst_class_id_masked_t *obj, int value);
extern int of_oxm_bsn_l3_dst_class_id_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_l3_dst_class_id_masked_t *obj, int value);

extern int of_oxm_bsn_l3_interface_class_id_OF_VERSION_1_2_populate(
    of_oxm_bsn_l3_interface_class_id_t *obj, int value);
extern int of_oxm_bsn_l3_interface_class_id_OF_VERSION_1_2_check(
    of_oxm_bsn_l3_interface_class_id_t *obj, int value);
extern int of_oxm_bsn_l3_interface_class_id_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_l3_interface_class_id_t *obj, int value);
extern int of_oxm_bsn_l3_interface_class_id_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_l3_interface_class_id_t *obj, int value);

extern int of_oxm_bsn_l3_interface_class_id_masked_OF_VERSION_1_2_populate(
    of_oxm_bsn_l3_interface_class_id_masked_t *obj, int value);
extern int of_oxm_bsn_l3_interface_class_id_masked_OF_VERSION_1_2_check(
    of_oxm_bsn_l3_interface_class_id_masked_t *obj, int value);
extern int of_oxm_bsn_l3_interface_class_id_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_l3_interface_class_id_masked_t *obj, int value);
extern int of_oxm_bsn_l3_interface_class_id_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_l3_interface_class_id_masked_t *obj, int value);

extern int of_oxm_bsn_l3_src_class_id_OF_VERSION_1_2_populate(
    of_oxm_bsn_l3_src_class_id_t *obj, int value);
extern int of_oxm_bsn_l3_src_class_id_OF_VERSION_1_2_check(
    of_oxm_bsn_l3_src_class_id_t *obj, int value);
extern int of_oxm_bsn_l3_src_class_id_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_l3_src_class_id_t *obj, int value);
extern int of_oxm_bsn_l3_src_class_id_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_l3_src_class_id_t *obj, int value);

extern int of_oxm_bsn_l3_src_class_id_masked_OF_VERSION_1_2_populate(
    of_oxm_bsn_l3_src_class_id_masked_t *obj, int value);
extern int of_oxm_bsn_l3_src_class_id_masked_OF_VERSION_1_2_check(
    of_oxm_bsn_l3_src_class_id_masked_t *obj, int value);
extern int of_oxm_bsn_l3_src_class_id_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_l3_src_class_id_masked_t *obj, int value);
extern int of_oxm_bsn_l3_src_class_id_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_l3_src_class_id_masked_t *obj, int value);

extern int of_oxm_bsn_lag_id_OF_VERSION_1_2_populate(
    of_oxm_bsn_lag_id_t *obj, int value);
extern int of_oxm_bsn_lag_id_OF_VERSION_1_2_check(
    of_oxm_bsn_lag_id_t *obj, int value);
extern int of_oxm_bsn_lag_id_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_lag_id_t *obj, int value);
extern int of_oxm_bsn_lag_id_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_lag_id_t *obj, int value);

extern int of_oxm_bsn_lag_id_masked_OF_VERSION_1_2_populate(
    of_oxm_bsn_lag_id_masked_t *obj, int value);
extern int of_oxm_bsn_lag_id_masked_OF_VERSION_1_2_check(
    of_oxm_bsn_lag_id_masked_t *obj, int value);
extern int of_oxm_bsn_lag_id_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_lag_id_masked_t *obj, int value);
extern int of_oxm_bsn_lag_id_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_lag_id_masked_t *obj, int value);

extern int of_oxm_bsn_tcp_flags_OF_VERSION_1_2_populate(
    of_oxm_bsn_tcp_flags_t *obj, int value);
extern int of_oxm_bsn_tcp_flags_OF_VERSION_1_2_check(
    of_oxm_bsn_tcp_flags_t *obj, int value);
extern int of_oxm_bsn_tcp_flags_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_tcp_flags_t *obj, int value);
extern int of_oxm_bsn_tcp_flags_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_tcp_flags_t *obj, int value);

extern int of_oxm_bsn_tcp_flags_masked_OF_VERSION_1_2_populate(
    of_oxm_bsn_tcp_flags_masked_t *obj, int value);
extern int of_oxm_bsn_tcp_flags_masked_OF_VERSION_1_2_check(
    of_oxm_bsn_tcp_flags_masked_t *obj, int value);
extern int of_oxm_bsn_tcp_flags_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_tcp_flags_masked_t *obj, int value);
extern int of_oxm_bsn_tcp_flags_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_tcp_flags_masked_t *obj, int value);

extern int of_oxm_bsn_udf0_OF_VERSION_1_2_populate(
    of_oxm_bsn_udf0_t *obj, int value);
extern int of_oxm_bsn_udf0_OF_VERSION_1_2_check(
    of_oxm_bsn_udf0_t *obj, int value);
extern int of_oxm_bsn_udf0_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_udf0_t *obj, int value);
extern int of_oxm_bsn_udf0_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_udf0_t *obj, int value);

extern int of_oxm_bsn_udf0_masked_OF_VERSION_1_2_populate(
    of_oxm_bsn_udf0_masked_t *obj, int value);
extern int of_oxm_bsn_udf0_masked_OF_VERSION_1_2_check(
    of_oxm_bsn_udf0_masked_t *obj, int value);
extern int of_oxm_bsn_udf0_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_udf0_masked_t *obj, int value);
extern int of_oxm_bsn_udf0_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_udf0_masked_t *obj, int value);

extern int of_oxm_bsn_udf1_OF_VERSION_1_2_populate(
    of_oxm_bsn_udf1_t *obj, int value);
extern int of_oxm_bsn_udf1_OF_VERSION_1_2_check(
    of_oxm_bsn_udf1_t *obj, int value);
extern int of_oxm_bsn_udf1_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_udf1_t *obj, int value);
extern int of_oxm_bsn_udf1_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_udf1_t *obj, int value);

extern int of_oxm_bsn_udf1_masked_OF_VERSION_1_2_populate(
    of_oxm_bsn_udf1_masked_t *obj, int value);
extern int of_oxm_bsn_udf1_masked_OF_VERSION_1_2_check(
    of_oxm_bsn_udf1_masked_t *obj, int value);
extern int of_oxm_bsn_udf1_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_udf1_masked_t *obj, int value);
extern int of_oxm_bsn_udf1_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_udf1_masked_t *obj, int value);

extern int of_oxm_bsn_udf2_OF_VERSION_1_2_populate(
    of_oxm_bsn_udf2_t *obj, int value);
extern int of_oxm_bsn_udf2_OF_VERSION_1_2_check(
    of_oxm_bsn_udf2_t *obj, int value);
extern int of_oxm_bsn_udf2_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_udf2_t *obj, int value);
extern int of_oxm_bsn_udf2_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_udf2_t *obj, int value);

extern int of_oxm_bsn_udf2_masked_OF_VERSION_1_2_populate(
    of_oxm_bsn_udf2_masked_t *obj, int value);
extern int of_oxm_bsn_udf2_masked_OF_VERSION_1_2_check(
    of_oxm_bsn_udf2_masked_t *obj, int value);
extern int of_oxm_bsn_udf2_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_udf2_masked_t *obj, int value);
extern int of_oxm_bsn_udf2_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_udf2_masked_t *obj, int value);

extern int of_oxm_bsn_udf3_OF_VERSION_1_2_populate(
    of_oxm_bsn_udf3_t *obj, int value);
extern int of_oxm_bsn_udf3_OF_VERSION_1_2_check(
    of_oxm_bsn_udf3_t *obj, int value);
extern int of_oxm_bsn_udf3_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_udf3_t *obj, int value);
extern int of_oxm_bsn_udf3_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_udf3_t *obj, int value);

extern int of_oxm_bsn_udf3_masked_OF_VERSION_1_2_populate(
    of_oxm_bsn_udf3_masked_t *obj, int value);
extern int of_oxm_bsn_udf3_masked_OF_VERSION_1_2_check(
    of_oxm_bsn_udf3_masked_t *obj, int value);
extern int of_oxm_bsn_udf3_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_udf3_masked_t *obj, int value);
extern int of_oxm_bsn_udf3_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_udf3_masked_t *obj, int value);

extern int of_oxm_bsn_udf4_OF_VERSION_1_2_populate(
    of_oxm_bsn_udf4_t *obj, int value);
extern int of_oxm_bsn_udf4_OF_VERSION_1_2_check(
    of_oxm_bsn_udf4_t *obj, int value);
extern int of_oxm_bsn_udf4_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_udf4_t *obj, int value);
extern int of_oxm_bsn_udf4_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_udf4_t *obj, int value);

extern int of_oxm_bsn_udf4_masked_OF_VERSION_1_2_populate(
    of_oxm_bsn_udf4_masked_t *obj, int value);
extern int of_oxm_bsn_udf4_masked_OF_VERSION_1_2_check(
    of_oxm_bsn_udf4_masked_t *obj, int value);
extern int of_oxm_bsn_udf4_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_udf4_masked_t *obj, int value);
extern int of_oxm_bsn_udf4_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_udf4_masked_t *obj, int value);

extern int of_oxm_bsn_udf5_OF_VERSION_1_2_populate(
    of_oxm_bsn_udf5_t *obj, int value);
extern int of_oxm_bsn_udf5_OF_VERSION_1_2_check(
    of_oxm_bsn_udf5_t *obj, int value);
extern int of_oxm_bsn_udf5_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_udf5_t *obj, int value);
extern int of_oxm_bsn_udf5_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_udf5_t *obj, int value);

extern int of_oxm_bsn_udf5_masked_OF_VERSION_1_2_populate(
    of_oxm_bsn_udf5_masked_t *obj, int value);
extern int of_oxm_bsn_udf5_masked_OF_VERSION_1_2_check(
    of_oxm_bsn_udf5_masked_t *obj, int value);
extern int of_oxm_bsn_udf5_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_udf5_masked_t *obj, int value);
extern int of_oxm_bsn_udf5_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_udf5_masked_t *obj, int value);

extern int of_oxm_bsn_udf6_OF_VERSION_1_2_populate(
    of_oxm_bsn_udf6_t *obj, int value);
extern int of_oxm_bsn_udf6_OF_VERSION_1_2_check(
    of_oxm_bsn_udf6_t *obj, int value);
extern int of_oxm_bsn_udf6_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_udf6_t *obj, int value);
extern int of_oxm_bsn_udf6_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_udf6_t *obj, int value);

extern int of_oxm_bsn_udf6_masked_OF_VERSION_1_2_populate(
    of_oxm_bsn_udf6_masked_t *obj, int value);
extern int of_oxm_bsn_udf6_masked_OF_VERSION_1_2_check(
    of_oxm_bsn_udf6_masked_t *obj, int value);
extern int of_oxm_bsn_udf6_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_udf6_masked_t *obj, int value);
extern int of_oxm_bsn_udf6_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_udf6_masked_t *obj, int value);

extern int of_oxm_bsn_udf7_OF_VERSION_1_2_populate(
    of_oxm_bsn_udf7_t *obj, int value);
extern int of_oxm_bsn_udf7_OF_VERSION_1_2_check(
    of_oxm_bsn_udf7_t *obj, int value);
extern int of_oxm_bsn_udf7_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_udf7_t *obj, int value);
extern int of_oxm_bsn_udf7_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_udf7_t *obj, int value);

extern int of_oxm_bsn_udf7_masked_OF_VERSION_1_2_populate(
    of_oxm_bsn_udf7_masked_t *obj, int value);
extern int of_oxm_bsn_udf7_masked_OF_VERSION_1_2_check(
    of_oxm_bsn_udf7_masked_t *obj, int value);
extern int of_oxm_bsn_udf7_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_udf7_masked_t *obj, int value);
extern int of_oxm_bsn_udf7_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_udf7_masked_t *obj, int value);

extern int of_oxm_bsn_vlan_xlate_port_group_id_OF_VERSION_1_2_populate(
    of_oxm_bsn_vlan_xlate_port_group_id_t *obj, int value);
extern int of_oxm_bsn_vlan_xlate_port_group_id_OF_VERSION_1_2_check(
    of_oxm_bsn_vlan_xlate_port_group_id_t *obj, int value);
extern int of_oxm_bsn_vlan_xlate_port_group_id_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_vlan_xlate_port_group_id_t *obj, int value);
extern int of_oxm_bsn_vlan_xlate_port_group_id_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_vlan_xlate_port_group_id_t *obj, int value);

extern int of_oxm_bsn_vlan_xlate_port_group_id_masked_OF_VERSION_1_2_populate(
    of_oxm_bsn_vlan_xlate_port_group_id_masked_t *obj, int value);
extern int of_oxm_bsn_vlan_xlate_port_group_id_masked_OF_VERSION_1_2_check(
    of_oxm_bsn_vlan_xlate_port_group_id_masked_t *obj, int value);
extern int of_oxm_bsn_vlan_xlate_port_group_id_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_vlan_xlate_port_group_id_masked_t *obj, int value);
extern int of_oxm_bsn_vlan_xlate_port_group_id_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_vlan_xlate_port_group_id_masked_t *obj, int value);

extern int of_oxm_bsn_vrf_OF_VERSION_1_2_populate(
    of_oxm_bsn_vrf_t *obj, int value);
extern int of_oxm_bsn_vrf_OF_VERSION_1_2_check(
    of_oxm_bsn_vrf_t *obj, int value);
extern int of_oxm_bsn_vrf_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_vrf_t *obj, int value);
extern int of_oxm_bsn_vrf_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_vrf_t *obj, int value);

extern int of_oxm_bsn_vrf_masked_OF_VERSION_1_2_populate(
    of_oxm_bsn_vrf_masked_t *obj, int value);
extern int of_oxm_bsn_vrf_masked_OF_VERSION_1_2_check(
    of_oxm_bsn_vrf_masked_t *obj, int value);
extern int of_oxm_bsn_vrf_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_bsn_vrf_masked_t *obj, int value);
extern int of_oxm_bsn_vrf_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_bsn_vrf_masked_t *obj, int value);

extern int of_oxm_eth_dst_OF_VERSION_1_2_populate(
    of_oxm_eth_dst_t *obj, int value);
extern int of_oxm_eth_dst_OF_VERSION_1_2_check(
    of_oxm_eth_dst_t *obj, int value);
extern int of_oxm_eth_dst_OF_VERSION_1_2_populate_scalars(
    of_oxm_eth_dst_t *obj, int value);
extern int of_oxm_eth_dst_OF_VERSION_1_2_check_scalars(
    of_oxm_eth_dst_t *obj, int value);

extern int of_oxm_eth_dst_masked_OF_VERSION_1_2_populate(
    of_oxm_eth_dst_masked_t *obj, int value);
extern int of_oxm_eth_dst_masked_OF_VERSION_1_2_check(
    of_oxm_eth_dst_masked_t *obj, int value);
extern int of_oxm_eth_dst_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_eth_dst_masked_t *obj, int value);
extern int of_oxm_eth_dst_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_eth_dst_masked_t *obj, int value);

extern int of_oxm_eth_src_OF_VERSION_1_2_populate(
    of_oxm_eth_src_t *obj, int value);
extern int of_oxm_eth_src_OF_VERSION_1_2_check(
    of_oxm_eth_src_t *obj, int value);
extern int of_oxm_eth_src_OF_VERSION_1_2_populate_scalars(
    of_oxm_eth_src_t *obj, int value);
extern int of_oxm_eth_src_OF_VERSION_1_2_check_scalars(
    of_oxm_eth_src_t *obj, int value);

extern int of_oxm_eth_src_masked_OF_VERSION_1_2_populate(
    of_oxm_eth_src_masked_t *obj, int value);
extern int of_oxm_eth_src_masked_OF_VERSION_1_2_check(
    of_oxm_eth_src_masked_t *obj, int value);
extern int of_oxm_eth_src_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_eth_src_masked_t *obj, int value);
extern int of_oxm_eth_src_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_eth_src_masked_t *obj, int value);

extern int of_oxm_eth_type_OF_VERSION_1_2_populate(
    of_oxm_eth_type_t *obj, int value);
extern int of_oxm_eth_type_OF_VERSION_1_2_check(
    of_oxm_eth_type_t *obj, int value);
extern int of_oxm_eth_type_OF_VERSION_1_2_populate_scalars(
    of_oxm_eth_type_t *obj, int value);
extern int of_oxm_eth_type_OF_VERSION_1_2_check_scalars(
    of_oxm_eth_type_t *obj, int value);

extern int of_oxm_eth_type_masked_OF_VERSION_1_2_populate(
    of_oxm_eth_type_masked_t *obj, int value);
extern int of_oxm_eth_type_masked_OF_VERSION_1_2_check(
    of_oxm_eth_type_masked_t *obj, int value);
extern int of_oxm_eth_type_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_eth_type_masked_t *obj, int value);
extern int of_oxm_eth_type_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_eth_type_masked_t *obj, int value);

extern int of_oxm_icmpv4_code_OF_VERSION_1_2_populate(
    of_oxm_icmpv4_code_t *obj, int value);
extern int of_oxm_icmpv4_code_OF_VERSION_1_2_check(
    of_oxm_icmpv4_code_t *obj, int value);
extern int of_oxm_icmpv4_code_OF_VERSION_1_2_populate_scalars(
    of_oxm_icmpv4_code_t *obj, int value);
extern int of_oxm_icmpv4_code_OF_VERSION_1_2_check_scalars(
    of_oxm_icmpv4_code_t *obj, int value);

extern int of_oxm_icmpv4_code_masked_OF_VERSION_1_2_populate(
    of_oxm_icmpv4_code_masked_t *obj, int value);
extern int of_oxm_icmpv4_code_masked_OF_VERSION_1_2_check(
    of_oxm_icmpv4_code_masked_t *obj, int value);
extern int of_oxm_icmpv4_code_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_icmpv4_code_masked_t *obj, int value);
extern int of_oxm_icmpv4_code_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_icmpv4_code_masked_t *obj, int value);

extern int of_oxm_icmpv4_type_OF_VERSION_1_2_populate(
    of_oxm_icmpv4_type_t *obj, int value);
extern int of_oxm_icmpv4_type_OF_VERSION_1_2_check(
    of_oxm_icmpv4_type_t *obj, int value);
extern int of_oxm_icmpv4_type_OF_VERSION_1_2_populate_scalars(
    of_oxm_icmpv4_type_t *obj, int value);
extern int of_oxm_icmpv4_type_OF_VERSION_1_2_check_scalars(
    of_oxm_icmpv4_type_t *obj, int value);

extern int of_oxm_icmpv4_type_masked_OF_VERSION_1_2_populate(
    of_oxm_icmpv4_type_masked_t *obj, int value);
extern int of_oxm_icmpv4_type_masked_OF_VERSION_1_2_check(
    of_oxm_icmpv4_type_masked_t *obj, int value);
extern int of_oxm_icmpv4_type_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_icmpv4_type_masked_t *obj, int value);
extern int of_oxm_icmpv4_type_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_icmpv4_type_masked_t *obj, int value);

extern int of_oxm_icmpv6_code_OF_VERSION_1_2_populate(
    of_oxm_icmpv6_code_t *obj, int value);
extern int of_oxm_icmpv6_code_OF_VERSION_1_2_check(
    of_oxm_icmpv6_code_t *obj, int value);
extern int of_oxm_icmpv6_code_OF_VERSION_1_2_populate_scalars(
    of_oxm_icmpv6_code_t *obj, int value);
extern int of_oxm_icmpv6_code_OF_VERSION_1_2_check_scalars(
    of_oxm_icmpv6_code_t *obj, int value);

extern int of_oxm_icmpv6_code_masked_OF_VERSION_1_2_populate(
    of_oxm_icmpv6_code_masked_t *obj, int value);
extern int of_oxm_icmpv6_code_masked_OF_VERSION_1_2_check(
    of_oxm_icmpv6_code_masked_t *obj, int value);
extern int of_oxm_icmpv6_code_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_icmpv6_code_masked_t *obj, int value);
extern int of_oxm_icmpv6_code_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_icmpv6_code_masked_t *obj, int value);

extern int of_oxm_icmpv6_type_OF_VERSION_1_2_populate(
    of_oxm_icmpv6_type_t *obj, int value);
extern int of_oxm_icmpv6_type_OF_VERSION_1_2_check(
    of_oxm_icmpv6_type_t *obj, int value);
extern int of_oxm_icmpv6_type_OF_VERSION_1_2_populate_scalars(
    of_oxm_icmpv6_type_t *obj, int value);
extern int of_oxm_icmpv6_type_OF_VERSION_1_2_check_scalars(
    of_oxm_icmpv6_type_t *obj, int value);

extern int of_oxm_icmpv6_type_masked_OF_VERSION_1_2_populate(
    of_oxm_icmpv6_type_masked_t *obj, int value);
extern int of_oxm_icmpv6_type_masked_OF_VERSION_1_2_check(
    of_oxm_icmpv6_type_masked_t *obj, int value);
extern int of_oxm_icmpv6_type_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_icmpv6_type_masked_t *obj, int value);
extern int of_oxm_icmpv6_type_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_icmpv6_type_masked_t *obj, int value);

extern int of_oxm_in_phy_port_OF_VERSION_1_2_populate(
    of_oxm_in_phy_port_t *obj, int value);
extern int of_oxm_in_phy_port_OF_VERSION_1_2_check(
    of_oxm_in_phy_port_t *obj, int value);
extern int of_oxm_in_phy_port_OF_VERSION_1_2_populate_scalars(
    of_oxm_in_phy_port_t *obj, int value);
extern int of_oxm_in_phy_port_OF_VERSION_1_2_check_scalars(
    of_oxm_in_phy_port_t *obj, int value);

extern int of_oxm_in_phy_port_masked_OF_VERSION_1_2_populate(
    of_oxm_in_phy_port_masked_t *obj, int value);
extern int of_oxm_in_phy_port_masked_OF_VERSION_1_2_check(
    of_oxm_in_phy_port_masked_t *obj, int value);
extern int of_oxm_in_phy_port_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_in_phy_port_masked_t *obj, int value);
extern int of_oxm_in_phy_port_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_in_phy_port_masked_t *obj, int value);

extern int of_oxm_in_port_OF_VERSION_1_2_populate(
    of_oxm_in_port_t *obj, int value);
extern int of_oxm_in_port_OF_VERSION_1_2_check(
    of_oxm_in_port_t *obj, int value);
extern int of_oxm_in_port_OF_VERSION_1_2_populate_scalars(
    of_oxm_in_port_t *obj, int value);
extern int of_oxm_in_port_OF_VERSION_1_2_check_scalars(
    of_oxm_in_port_t *obj, int value);

extern int of_oxm_in_port_masked_OF_VERSION_1_2_populate(
    of_oxm_in_port_masked_t *obj, int value);
extern int of_oxm_in_port_masked_OF_VERSION_1_2_check(
    of_oxm_in_port_masked_t *obj, int value);
extern int of_oxm_in_port_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_in_port_masked_t *obj, int value);
extern int of_oxm_in_port_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_in_port_masked_t *obj, int value);

extern int of_oxm_ip_dscp_OF_VERSION_1_2_populate(
    of_oxm_ip_dscp_t *obj, int value);
extern int of_oxm_ip_dscp_OF_VERSION_1_2_check(
    of_oxm_ip_dscp_t *obj, int value);
extern int of_oxm_ip_dscp_OF_VERSION_1_2_populate_scalars(
    of_oxm_ip_dscp_t *obj, int value);
extern int of_oxm_ip_dscp_OF_VERSION_1_2_check_scalars(
    of_oxm_ip_dscp_t *obj, int value);

extern int of_oxm_ip_dscp_masked_OF_VERSION_1_2_populate(
    of_oxm_ip_dscp_masked_t *obj, int value);
extern int of_oxm_ip_dscp_masked_OF_VERSION_1_2_check(
    of_oxm_ip_dscp_masked_t *obj, int value);
extern int of_oxm_ip_dscp_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_ip_dscp_masked_t *obj, int value);
extern int of_oxm_ip_dscp_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_ip_dscp_masked_t *obj, int value);

extern int of_oxm_ip_ecn_OF_VERSION_1_2_populate(
    of_oxm_ip_ecn_t *obj, int value);
extern int of_oxm_ip_ecn_OF_VERSION_1_2_check(
    of_oxm_ip_ecn_t *obj, int value);
extern int of_oxm_ip_ecn_OF_VERSION_1_2_populate_scalars(
    of_oxm_ip_ecn_t *obj, int value);
extern int of_oxm_ip_ecn_OF_VERSION_1_2_check_scalars(
    of_oxm_ip_ecn_t *obj, int value);

extern int of_oxm_ip_ecn_masked_OF_VERSION_1_2_populate(
    of_oxm_ip_ecn_masked_t *obj, int value);
extern int of_oxm_ip_ecn_masked_OF_VERSION_1_2_check(
    of_oxm_ip_ecn_masked_t *obj, int value);
extern int of_oxm_ip_ecn_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_ip_ecn_masked_t *obj, int value);
extern int of_oxm_ip_ecn_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_ip_ecn_masked_t *obj, int value);

extern int of_oxm_ip_proto_OF_VERSION_1_2_populate(
    of_oxm_ip_proto_t *obj, int value);
extern int of_oxm_ip_proto_OF_VERSION_1_2_check(
    of_oxm_ip_proto_t *obj, int value);
extern int of_oxm_ip_proto_OF_VERSION_1_2_populate_scalars(
    of_oxm_ip_proto_t *obj, int value);
extern int of_oxm_ip_proto_OF_VERSION_1_2_check_scalars(
    of_oxm_ip_proto_t *obj, int value);

extern int of_oxm_ip_proto_masked_OF_VERSION_1_2_populate(
    of_oxm_ip_proto_masked_t *obj, int value);
extern int of_oxm_ip_proto_masked_OF_VERSION_1_2_check(
    of_oxm_ip_proto_masked_t *obj, int value);
extern int of_oxm_ip_proto_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_ip_proto_masked_t *obj, int value);
extern int of_oxm_ip_proto_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_ip_proto_masked_t *obj, int value);

extern int of_oxm_ipv4_dst_OF_VERSION_1_2_populate(
    of_oxm_ipv4_dst_t *obj, int value);
extern int of_oxm_ipv4_dst_OF_VERSION_1_2_check(
    of_oxm_ipv4_dst_t *obj, int value);
extern int of_oxm_ipv4_dst_OF_VERSION_1_2_populate_scalars(
    of_oxm_ipv4_dst_t *obj, int value);
extern int of_oxm_ipv4_dst_OF_VERSION_1_2_check_scalars(
    of_oxm_ipv4_dst_t *obj, int value);

extern int of_oxm_ipv4_dst_masked_OF_VERSION_1_2_populate(
    of_oxm_ipv4_dst_masked_t *obj, int value);
extern int of_oxm_ipv4_dst_masked_OF_VERSION_1_2_check(
    of_oxm_ipv4_dst_masked_t *obj, int value);
extern int of_oxm_ipv4_dst_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_ipv4_dst_masked_t *obj, int value);
extern int of_oxm_ipv4_dst_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_ipv4_dst_masked_t *obj, int value);

extern int of_oxm_ipv4_src_OF_VERSION_1_2_populate(
    of_oxm_ipv4_src_t *obj, int value);
extern int of_oxm_ipv4_src_OF_VERSION_1_2_check(
    of_oxm_ipv4_src_t *obj, int value);
extern int of_oxm_ipv4_src_OF_VERSION_1_2_populate_scalars(
    of_oxm_ipv4_src_t *obj, int value);
extern int of_oxm_ipv4_src_OF_VERSION_1_2_check_scalars(
    of_oxm_ipv4_src_t *obj, int value);

extern int of_oxm_ipv4_src_masked_OF_VERSION_1_2_populate(
    of_oxm_ipv4_src_masked_t *obj, int value);
extern int of_oxm_ipv4_src_masked_OF_VERSION_1_2_check(
    of_oxm_ipv4_src_masked_t *obj, int value);
extern int of_oxm_ipv4_src_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_ipv4_src_masked_t *obj, int value);
extern int of_oxm_ipv4_src_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_ipv4_src_masked_t *obj, int value);

extern int of_oxm_ipv6_dst_OF_VERSION_1_2_populate(
    of_oxm_ipv6_dst_t *obj, int value);
extern int of_oxm_ipv6_dst_OF_VERSION_1_2_check(
    of_oxm_ipv6_dst_t *obj, int value);
extern int of_oxm_ipv6_dst_OF_VERSION_1_2_populate_scalars(
    of_oxm_ipv6_dst_t *obj, int value);
extern int of_oxm_ipv6_dst_OF_VERSION_1_2_check_scalars(
    of_oxm_ipv6_dst_t *obj, int value);

extern int of_oxm_ipv6_dst_masked_OF_VERSION_1_2_populate(
    of_oxm_ipv6_dst_masked_t *obj, int value);
extern int of_oxm_ipv6_dst_masked_OF_VERSION_1_2_check(
    of_oxm_ipv6_dst_masked_t *obj, int value);
extern int of_oxm_ipv6_dst_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_ipv6_dst_masked_t *obj, int value);
extern int of_oxm_ipv6_dst_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_ipv6_dst_masked_t *obj, int value);

extern int of_oxm_ipv6_flabel_OF_VERSION_1_2_populate(
    of_oxm_ipv6_flabel_t *obj, int value);
extern int of_oxm_ipv6_flabel_OF_VERSION_1_2_check(
    of_oxm_ipv6_flabel_t *obj, int value);
extern int of_oxm_ipv6_flabel_OF_VERSION_1_2_populate_scalars(
    of_oxm_ipv6_flabel_t *obj, int value);
extern int of_oxm_ipv6_flabel_OF_VERSION_1_2_check_scalars(
    of_oxm_ipv6_flabel_t *obj, int value);

extern int of_oxm_ipv6_flabel_masked_OF_VERSION_1_2_populate(
    of_oxm_ipv6_flabel_masked_t *obj, int value);
extern int of_oxm_ipv6_flabel_masked_OF_VERSION_1_2_check(
    of_oxm_ipv6_flabel_masked_t *obj, int value);
extern int of_oxm_ipv6_flabel_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_ipv6_flabel_masked_t *obj, int value);
extern int of_oxm_ipv6_flabel_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_ipv6_flabel_masked_t *obj, int value);

extern int of_oxm_ipv6_nd_sll_OF_VERSION_1_2_populate(
    of_oxm_ipv6_nd_sll_t *obj, int value);
extern int of_oxm_ipv6_nd_sll_OF_VERSION_1_2_check(
    of_oxm_ipv6_nd_sll_t *obj, int value);
extern int of_oxm_ipv6_nd_sll_OF_VERSION_1_2_populate_scalars(
    of_oxm_ipv6_nd_sll_t *obj, int value);
extern int of_oxm_ipv6_nd_sll_OF_VERSION_1_2_check_scalars(
    of_oxm_ipv6_nd_sll_t *obj, int value);

extern int of_oxm_ipv6_nd_sll_masked_OF_VERSION_1_2_populate(
    of_oxm_ipv6_nd_sll_masked_t *obj, int value);
extern int of_oxm_ipv6_nd_sll_masked_OF_VERSION_1_2_check(
    of_oxm_ipv6_nd_sll_masked_t *obj, int value);
extern int of_oxm_ipv6_nd_sll_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_ipv6_nd_sll_masked_t *obj, int value);
extern int of_oxm_ipv6_nd_sll_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_ipv6_nd_sll_masked_t *obj, int value);

extern int of_oxm_ipv6_nd_target_OF_VERSION_1_2_populate(
    of_oxm_ipv6_nd_target_t *obj, int value);
extern int of_oxm_ipv6_nd_target_OF_VERSION_1_2_check(
    of_oxm_ipv6_nd_target_t *obj, int value);
extern int of_oxm_ipv6_nd_target_OF_VERSION_1_2_populate_scalars(
    of_oxm_ipv6_nd_target_t *obj, int value);
extern int of_oxm_ipv6_nd_target_OF_VERSION_1_2_check_scalars(
    of_oxm_ipv6_nd_target_t *obj, int value);

extern int of_oxm_ipv6_nd_target_masked_OF_VERSION_1_2_populate(
    of_oxm_ipv6_nd_target_masked_t *obj, int value);
extern int of_oxm_ipv6_nd_target_masked_OF_VERSION_1_2_check(
    of_oxm_ipv6_nd_target_masked_t *obj, int value);
extern int of_oxm_ipv6_nd_target_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_ipv6_nd_target_masked_t *obj, int value);
extern int of_oxm_ipv6_nd_target_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_ipv6_nd_target_masked_t *obj, int value);

extern int of_oxm_ipv6_nd_tll_OF_VERSION_1_2_populate(
    of_oxm_ipv6_nd_tll_t *obj, int value);
extern int of_oxm_ipv6_nd_tll_OF_VERSION_1_2_check(
    of_oxm_ipv6_nd_tll_t *obj, int value);
extern int of_oxm_ipv6_nd_tll_OF_VERSION_1_2_populate_scalars(
    of_oxm_ipv6_nd_tll_t *obj, int value);
extern int of_oxm_ipv6_nd_tll_OF_VERSION_1_2_check_scalars(
    of_oxm_ipv6_nd_tll_t *obj, int value);

extern int of_oxm_ipv6_nd_tll_masked_OF_VERSION_1_2_populate(
    of_oxm_ipv6_nd_tll_masked_t *obj, int value);
extern int of_oxm_ipv6_nd_tll_masked_OF_VERSION_1_2_check(
    of_oxm_ipv6_nd_tll_masked_t *obj, int value);
extern int of_oxm_ipv6_nd_tll_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_ipv6_nd_tll_masked_t *obj, int value);
extern int of_oxm_ipv6_nd_tll_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_ipv6_nd_tll_masked_t *obj, int value);

extern int of_oxm_ipv6_src_OF_VERSION_1_2_populate(
    of_oxm_ipv6_src_t *obj, int value);
extern int of_oxm_ipv6_src_OF_VERSION_1_2_check(
    of_oxm_ipv6_src_t *obj, int value);
extern int of_oxm_ipv6_src_OF_VERSION_1_2_populate_scalars(
    of_oxm_ipv6_src_t *obj, int value);
extern int of_oxm_ipv6_src_OF_VERSION_1_2_check_scalars(
    of_oxm_ipv6_src_t *obj, int value);

extern int of_oxm_ipv6_src_masked_OF_VERSION_1_2_populate(
    of_oxm_ipv6_src_masked_t *obj, int value);
extern int of_oxm_ipv6_src_masked_OF_VERSION_1_2_check(
    of_oxm_ipv6_src_masked_t *obj, int value);
extern int of_oxm_ipv6_src_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_ipv6_src_masked_t *obj, int value);
extern int of_oxm_ipv6_src_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_ipv6_src_masked_t *obj, int value);

extern int of_oxm_metadata_OF_VERSION_1_2_populate(
    of_oxm_metadata_t *obj, int value);
extern int of_oxm_metadata_OF_VERSION_1_2_check(
    of_oxm_metadata_t *obj, int value);
extern int of_oxm_metadata_OF_VERSION_1_2_populate_scalars(
    of_oxm_metadata_t *obj, int value);
extern int of_oxm_metadata_OF_VERSION_1_2_check_scalars(
    of_oxm_metadata_t *obj, int value);

extern int of_oxm_metadata_masked_OF_VERSION_1_2_populate(
    of_oxm_metadata_masked_t *obj, int value);
extern int of_oxm_metadata_masked_OF_VERSION_1_2_check(
    of_oxm_metadata_masked_t *obj, int value);
extern int of_oxm_metadata_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_metadata_masked_t *obj, int value);
extern int of_oxm_metadata_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_metadata_masked_t *obj, int value);

extern int of_oxm_mpls_label_OF_VERSION_1_2_populate(
    of_oxm_mpls_label_t *obj, int value);
extern int of_oxm_mpls_label_OF_VERSION_1_2_check(
    of_oxm_mpls_label_t *obj, int value);
extern int of_oxm_mpls_label_OF_VERSION_1_2_populate_scalars(
    of_oxm_mpls_label_t *obj, int value);
extern int of_oxm_mpls_label_OF_VERSION_1_2_check_scalars(
    of_oxm_mpls_label_t *obj, int value);

extern int of_oxm_mpls_label_masked_OF_VERSION_1_2_populate(
    of_oxm_mpls_label_masked_t *obj, int value);
extern int of_oxm_mpls_label_masked_OF_VERSION_1_2_check(
    of_oxm_mpls_label_masked_t *obj, int value);
extern int of_oxm_mpls_label_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_mpls_label_masked_t *obj, int value);
extern int of_oxm_mpls_label_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_mpls_label_masked_t *obj, int value);

extern int of_oxm_mpls_tc_OF_VERSION_1_2_populate(
    of_oxm_mpls_tc_t *obj, int value);
extern int of_oxm_mpls_tc_OF_VERSION_1_2_check(
    of_oxm_mpls_tc_t *obj, int value);
extern int of_oxm_mpls_tc_OF_VERSION_1_2_populate_scalars(
    of_oxm_mpls_tc_t *obj, int value);
extern int of_oxm_mpls_tc_OF_VERSION_1_2_check_scalars(
    of_oxm_mpls_tc_t *obj, int value);

extern int of_oxm_mpls_tc_masked_OF_VERSION_1_2_populate(
    of_oxm_mpls_tc_masked_t *obj, int value);
extern int of_oxm_mpls_tc_masked_OF_VERSION_1_2_check(
    of_oxm_mpls_tc_masked_t *obj, int value);
extern int of_oxm_mpls_tc_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_mpls_tc_masked_t *obj, int value);
extern int of_oxm_mpls_tc_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_mpls_tc_masked_t *obj, int value);

extern int of_oxm_ovs_tcp_flags_OF_VERSION_1_2_populate(
    of_oxm_ovs_tcp_flags_t *obj, int value);
extern int of_oxm_ovs_tcp_flags_OF_VERSION_1_2_check(
    of_oxm_ovs_tcp_flags_t *obj, int value);
extern int of_oxm_ovs_tcp_flags_OF_VERSION_1_2_populate_scalars(
    of_oxm_ovs_tcp_flags_t *obj, int value);
extern int of_oxm_ovs_tcp_flags_OF_VERSION_1_2_check_scalars(
    of_oxm_ovs_tcp_flags_t *obj, int value);

extern int of_oxm_ovs_tcp_flags_masked_OF_VERSION_1_2_populate(
    of_oxm_ovs_tcp_flags_masked_t *obj, int value);
extern int of_oxm_ovs_tcp_flags_masked_OF_VERSION_1_2_check(
    of_oxm_ovs_tcp_flags_masked_t *obj, int value);
extern int of_oxm_ovs_tcp_flags_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_ovs_tcp_flags_masked_t *obj, int value);
extern int of_oxm_ovs_tcp_flags_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_ovs_tcp_flags_masked_t *obj, int value);

extern int of_oxm_sctp_dst_OF_VERSION_1_2_populate(
    of_oxm_sctp_dst_t *obj, int value);
extern int of_oxm_sctp_dst_OF_VERSION_1_2_check(
    of_oxm_sctp_dst_t *obj, int value);
extern int of_oxm_sctp_dst_OF_VERSION_1_2_populate_scalars(
    of_oxm_sctp_dst_t *obj, int value);
extern int of_oxm_sctp_dst_OF_VERSION_1_2_check_scalars(
    of_oxm_sctp_dst_t *obj, int value);

extern int of_oxm_sctp_dst_masked_OF_VERSION_1_2_populate(
    of_oxm_sctp_dst_masked_t *obj, int value);
extern int of_oxm_sctp_dst_masked_OF_VERSION_1_2_check(
    of_oxm_sctp_dst_masked_t *obj, int value);
extern int of_oxm_sctp_dst_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_sctp_dst_masked_t *obj, int value);
extern int of_oxm_sctp_dst_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_sctp_dst_masked_t *obj, int value);

extern int of_oxm_sctp_src_OF_VERSION_1_2_populate(
    of_oxm_sctp_src_t *obj, int value);
extern int of_oxm_sctp_src_OF_VERSION_1_2_check(
    of_oxm_sctp_src_t *obj, int value);
extern int of_oxm_sctp_src_OF_VERSION_1_2_populate_scalars(
    of_oxm_sctp_src_t *obj, int value);
extern int of_oxm_sctp_src_OF_VERSION_1_2_check_scalars(
    of_oxm_sctp_src_t *obj, int value);

extern int of_oxm_sctp_src_masked_OF_VERSION_1_2_populate(
    of_oxm_sctp_src_masked_t *obj, int value);
extern int of_oxm_sctp_src_masked_OF_VERSION_1_2_check(
    of_oxm_sctp_src_masked_t *obj, int value);
extern int of_oxm_sctp_src_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_sctp_src_masked_t *obj, int value);
extern int of_oxm_sctp_src_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_sctp_src_masked_t *obj, int value);

extern int of_oxm_tcp_dst_OF_VERSION_1_2_populate(
    of_oxm_tcp_dst_t *obj, int value);
extern int of_oxm_tcp_dst_OF_VERSION_1_2_check(
    of_oxm_tcp_dst_t *obj, int value);
extern int of_oxm_tcp_dst_OF_VERSION_1_2_populate_scalars(
    of_oxm_tcp_dst_t *obj, int value);
extern int of_oxm_tcp_dst_OF_VERSION_1_2_check_scalars(
    of_oxm_tcp_dst_t *obj, int value);

extern int of_oxm_tcp_dst_masked_OF_VERSION_1_2_populate(
    of_oxm_tcp_dst_masked_t *obj, int value);
extern int of_oxm_tcp_dst_masked_OF_VERSION_1_2_check(
    of_oxm_tcp_dst_masked_t *obj, int value);
extern int of_oxm_tcp_dst_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_tcp_dst_masked_t *obj, int value);
extern int of_oxm_tcp_dst_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_tcp_dst_masked_t *obj, int value);

extern int of_oxm_tcp_src_OF_VERSION_1_2_populate(
    of_oxm_tcp_src_t *obj, int value);
extern int of_oxm_tcp_src_OF_VERSION_1_2_check(
    of_oxm_tcp_src_t *obj, int value);
extern int of_oxm_tcp_src_OF_VERSION_1_2_populate_scalars(
    of_oxm_tcp_src_t *obj, int value);
extern int of_oxm_tcp_src_OF_VERSION_1_2_check_scalars(
    of_oxm_tcp_src_t *obj, int value);

extern int of_oxm_tcp_src_masked_OF_VERSION_1_2_populate(
    of_oxm_tcp_src_masked_t *obj, int value);
extern int of_oxm_tcp_src_masked_OF_VERSION_1_2_check(
    of_oxm_tcp_src_masked_t *obj, int value);
extern int of_oxm_tcp_src_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_tcp_src_masked_t *obj, int value);
extern int of_oxm_tcp_src_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_tcp_src_masked_t *obj, int value);

extern int of_oxm_tunnel_ipv4_dst_OF_VERSION_1_2_populate(
    of_oxm_tunnel_ipv4_dst_t *obj, int value);
extern int of_oxm_tunnel_ipv4_dst_OF_VERSION_1_2_check(
    of_oxm_tunnel_ipv4_dst_t *obj, int value);
extern int of_oxm_tunnel_ipv4_dst_OF_VERSION_1_2_populate_scalars(
    of_oxm_tunnel_ipv4_dst_t *obj, int value);
extern int of_oxm_tunnel_ipv4_dst_OF_VERSION_1_2_check_scalars(
    of_oxm_tunnel_ipv4_dst_t *obj, int value);

extern int of_oxm_tunnel_ipv4_dst_masked_OF_VERSION_1_2_populate(
    of_oxm_tunnel_ipv4_dst_masked_t *obj, int value);
extern int of_oxm_tunnel_ipv4_dst_masked_OF_VERSION_1_2_check(
    of_oxm_tunnel_ipv4_dst_masked_t *obj, int value);
extern int of_oxm_tunnel_ipv4_dst_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_tunnel_ipv4_dst_masked_t *obj, int value);
extern int of_oxm_tunnel_ipv4_dst_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_tunnel_ipv4_dst_masked_t *obj, int value);

extern int of_oxm_tunnel_ipv4_src_OF_VERSION_1_2_populate(
    of_oxm_tunnel_ipv4_src_t *obj, int value);
extern int of_oxm_tunnel_ipv4_src_OF_VERSION_1_2_check(
    of_oxm_tunnel_ipv4_src_t *obj, int value);
extern int of_oxm_tunnel_ipv4_src_OF_VERSION_1_2_populate_scalars(
    of_oxm_tunnel_ipv4_src_t *obj, int value);
extern int of_oxm_tunnel_ipv4_src_OF_VERSION_1_2_check_scalars(
    of_oxm_tunnel_ipv4_src_t *obj, int value);

extern int of_oxm_tunnel_ipv4_src_masked_OF_VERSION_1_2_populate(
    of_oxm_tunnel_ipv4_src_masked_t *obj, int value);
extern int of_oxm_tunnel_ipv4_src_masked_OF_VERSION_1_2_check(
    of_oxm_tunnel_ipv4_src_masked_t *obj, int value);
extern int of_oxm_tunnel_ipv4_src_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_tunnel_ipv4_src_masked_t *obj, int value);
extern int of_oxm_tunnel_ipv4_src_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_tunnel_ipv4_src_masked_t *obj, int value);

extern int of_oxm_udp_dst_OF_VERSION_1_2_populate(
    of_oxm_udp_dst_t *obj, int value);
extern int of_oxm_udp_dst_OF_VERSION_1_2_check(
    of_oxm_udp_dst_t *obj, int value);
extern int of_oxm_udp_dst_OF_VERSION_1_2_populate_scalars(
    of_oxm_udp_dst_t *obj, int value);
extern int of_oxm_udp_dst_OF_VERSION_1_2_check_scalars(
    of_oxm_udp_dst_t *obj, int value);

extern int of_oxm_udp_dst_masked_OF_VERSION_1_2_populate(
    of_oxm_udp_dst_masked_t *obj, int value);
extern int of_oxm_udp_dst_masked_OF_VERSION_1_2_check(
    of_oxm_udp_dst_masked_t *obj, int value);
extern int of_oxm_udp_dst_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_udp_dst_masked_t *obj, int value);
extern int of_oxm_udp_dst_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_udp_dst_masked_t *obj, int value);

extern int of_oxm_udp_src_OF_VERSION_1_2_populate(
    of_oxm_udp_src_t *obj, int value);
extern int of_oxm_udp_src_OF_VERSION_1_2_check(
    of_oxm_udp_src_t *obj, int value);
extern int of_oxm_udp_src_OF_VERSION_1_2_populate_scalars(
    of_oxm_udp_src_t *obj, int value);
extern int of_oxm_udp_src_OF_VERSION_1_2_check_scalars(
    of_oxm_udp_src_t *obj, int value);

extern int of_oxm_udp_src_masked_OF_VERSION_1_2_populate(
    of_oxm_udp_src_masked_t *obj, int value);
extern int of_oxm_udp_src_masked_OF_VERSION_1_2_check(
    of_oxm_udp_src_masked_t *obj, int value);
extern int of_oxm_udp_src_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_udp_src_masked_t *obj, int value);
extern int of_oxm_udp_src_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_udp_src_masked_t *obj, int value);

extern int of_oxm_vlan_pcp_OF_VERSION_1_2_populate(
    of_oxm_vlan_pcp_t *obj, int value);
extern int of_oxm_vlan_pcp_OF_VERSION_1_2_check(
    of_oxm_vlan_pcp_t *obj, int value);
extern int of_oxm_vlan_pcp_OF_VERSION_1_2_populate_scalars(
    of_oxm_vlan_pcp_t *obj, int value);
extern int of_oxm_vlan_pcp_OF_VERSION_1_2_check_scalars(
    of_oxm_vlan_pcp_t *obj, int value);

extern int of_oxm_vlan_pcp_masked_OF_VERSION_1_2_populate(
    of_oxm_vlan_pcp_masked_t *obj, int value);
extern int of_oxm_vlan_pcp_masked_OF_VERSION_1_2_check(
    of_oxm_vlan_pcp_masked_t *obj, int value);
extern int of_oxm_vlan_pcp_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_vlan_pcp_masked_t *obj, int value);
extern int of_oxm_vlan_pcp_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_vlan_pcp_masked_t *obj, int value);

extern int of_oxm_vlan_vid_OF_VERSION_1_2_populate(
    of_oxm_vlan_vid_t *obj, int value);
extern int of_oxm_vlan_vid_OF_VERSION_1_2_check(
    of_oxm_vlan_vid_t *obj, int value);
extern int of_oxm_vlan_vid_OF_VERSION_1_2_populate_scalars(
    of_oxm_vlan_vid_t *obj, int value);
extern int of_oxm_vlan_vid_OF_VERSION_1_2_check_scalars(
    of_oxm_vlan_vid_t *obj, int value);

extern int of_oxm_vlan_vid_masked_OF_VERSION_1_2_populate(
    of_oxm_vlan_vid_masked_t *obj, int value);
extern int of_oxm_vlan_vid_masked_OF_VERSION_1_2_check(
    of_oxm_vlan_vid_masked_t *obj, int value);
extern int of_oxm_vlan_vid_masked_OF_VERSION_1_2_populate_scalars(
    of_oxm_vlan_vid_masked_t *obj, int value);
extern int of_oxm_vlan_vid_masked_OF_VERSION_1_2_check_scalars(
    of_oxm_vlan_vid_masked_t *obj, int value);

extern int of_packet_queue_OF_VERSION_1_2_populate(
    of_packet_queue_t *obj, int value);
extern int of_packet_queue_OF_VERSION_1_2_check(
    of_packet_queue_t *obj, int value);
extern int of_packet_queue_OF_VERSION_1_2_populate_scalars(
    of_packet_queue_t *obj, int value);
extern int of_packet_queue_OF_VERSION_1_2_check_scalars(
    of_packet_queue_t *obj, int value);

extern int of_port_desc_OF_VERSION_1_2_populate(
    of_port_desc_t *obj, int value);
extern int of_port_desc_OF_VERSION_1_2_check(
    of_port_desc_t *obj, int value);
extern int of_port_desc_OF_VERSION_1_2_populate_scalars(
    of_port_desc_t *obj, int value);
extern int of_port_desc_OF_VERSION_1_2_check_scalars(
    of_port_desc_t *obj, int value);

extern int of_port_stats_entry_OF_VERSION_1_2_populate(
    of_port_stats_entry_t *obj, int value);
extern int of_port_stats_entry_OF_VERSION_1_2_check(
    of_port_stats_entry_t *obj, int value);
extern int of_port_stats_entry_OF_VERSION_1_2_populate_scalars(
    of_port_stats_entry_t *obj, int value);
extern int of_port_stats_entry_OF_VERSION_1_2_check_scalars(
    of_port_stats_entry_t *obj, int value);

extern int of_queue_prop_max_rate_OF_VERSION_1_2_populate(
    of_queue_prop_max_rate_t *obj, int value);
extern int of_queue_prop_max_rate_OF_VERSION_1_2_check(
    of_queue_prop_max_rate_t *obj, int value);
extern int of_queue_prop_max_rate_OF_VERSION_1_2_populate_scalars(
    of_queue_prop_max_rate_t *obj, int value);
extern int of_queue_prop_max_rate_OF_VERSION_1_2_check_scalars(
    of_queue_prop_max_rate_t *obj, int value);

extern int of_queue_prop_min_rate_OF_VERSION_1_2_populate(
    of_queue_prop_min_rate_t *obj, int value);
extern int of_queue_prop_min_rate_OF_VERSION_1_2_check(
    of_queue_prop_min_rate_t *obj, int value);
extern int of_queue_prop_min_rate_OF_VERSION_1_2_populate_scalars(
    of_queue_prop_min_rate_t *obj, int value);
extern int of_queue_prop_min_rate_OF_VERSION_1_2_check_scalars(
    of_queue_prop_min_rate_t *obj, int value);

extern int of_queue_stats_entry_OF_VERSION_1_2_populate(
    of_queue_stats_entry_t *obj, int value);
extern int of_queue_stats_entry_OF_VERSION_1_2_check(
    of_queue_stats_entry_t *obj, int value);
extern int of_queue_stats_entry_OF_VERSION_1_2_populate_scalars(
    of_queue_stats_entry_t *obj, int value);
extern int of_queue_stats_entry_OF_VERSION_1_2_check_scalars(
    of_queue_stats_entry_t *obj, int value);

extern int of_table_stats_entry_OF_VERSION_1_2_populate(
    of_table_stats_entry_t *obj, int value);
extern int of_table_stats_entry_OF_VERSION_1_2_check(
    of_table_stats_entry_t *obj, int value);
extern int of_table_stats_entry_OF_VERSION_1_2_populate_scalars(
    of_table_stats_entry_t *obj, int value);
extern int of_table_stats_entry_OF_VERSION_1_2_check_scalars(
    of_table_stats_entry_t *obj, int value);

extern int of_list_action_OF_VERSION_1_2_populate(
    of_list_action_t *obj, int value);
extern int of_list_action_OF_VERSION_1_2_check(
    of_list_action_t *obj, int value);
extern int of_list_action_OF_VERSION_1_2_populate_scalars(
    of_list_action_t *obj, int value);
extern int of_list_action_OF_VERSION_1_2_check_scalars(
    of_list_action_t *obj, int value);

extern int of_list_bsn_interface_OF_VERSION_1_2_populate(
    of_list_bsn_interface_t *obj, int value);
extern int of_list_bsn_interface_OF_VERSION_1_2_check(
    of_list_bsn_interface_t *obj, int value);
extern int of_list_bsn_interface_OF_VERSION_1_2_populate_scalars(
    of_list_bsn_interface_t *obj, int value);
extern int of_list_bsn_interface_OF_VERSION_1_2_check_scalars(
    of_list_bsn_interface_t *obj, int value);

extern int of_list_bucket_OF_VERSION_1_2_populate(
    of_list_bucket_t *obj, int value);
extern int of_list_bucket_OF_VERSION_1_2_check(
    of_list_bucket_t *obj, int value);
extern int of_list_bucket_OF_VERSION_1_2_populate_scalars(
    of_list_bucket_t *obj, int value);
extern int of_list_bucket_OF_VERSION_1_2_check_scalars(
    of_list_bucket_t *obj, int value);

extern int of_list_bucket_counter_OF_VERSION_1_2_populate(
    of_list_bucket_counter_t *obj, int value);
extern int of_list_bucket_counter_OF_VERSION_1_2_check(
    of_list_bucket_counter_t *obj, int value);
extern int of_list_bucket_counter_OF_VERSION_1_2_populate_scalars(
    of_list_bucket_counter_t *obj, int value);
extern int of_list_bucket_counter_OF_VERSION_1_2_check_scalars(
    of_list_bucket_counter_t *obj, int value);

extern int of_list_flow_stats_entry_OF_VERSION_1_2_populate(
    of_list_flow_stats_entry_t *obj, int value);
extern int of_list_flow_stats_entry_OF_VERSION_1_2_check(
    of_list_flow_stats_entry_t *obj, int value);
extern int of_list_flow_stats_entry_OF_VERSION_1_2_populate_scalars(
    of_list_flow_stats_entry_t *obj, int value);
extern int of_list_flow_stats_entry_OF_VERSION_1_2_check_scalars(
    of_list_flow_stats_entry_t *obj, int value);

extern int of_list_group_desc_stats_entry_OF_VERSION_1_2_populate(
    of_list_group_desc_stats_entry_t *obj, int value);
extern int of_list_group_desc_stats_entry_OF_VERSION_1_2_check(
    of_list_group_desc_stats_entry_t *obj, int value);
extern int of_list_group_desc_stats_entry_OF_VERSION_1_2_populate_scalars(
    of_list_group_desc_stats_entry_t *obj, int value);
extern int of_list_group_desc_stats_entry_OF_VERSION_1_2_check_scalars(
    of_list_group_desc_stats_entry_t *obj, int value);

extern int of_list_group_stats_entry_OF_VERSION_1_2_populate(
    of_list_group_stats_entry_t *obj, int value);
extern int of_list_group_stats_entry_OF_VERSION_1_2_check(
    of_list_group_stats_entry_t *obj, int value);
extern int of_list_group_stats_entry_OF_VERSION_1_2_populate_scalars(
    of_list_group_stats_entry_t *obj, int value);
extern int of_list_group_stats_entry_OF_VERSION_1_2_check_scalars(
    of_list_group_stats_entry_t *obj, int value);

extern int of_list_instruction_OF_VERSION_1_2_populate(
    of_list_instruction_t *obj, int value);
extern int of_list_instruction_OF_VERSION_1_2_check(
    of_list_instruction_t *obj, int value);
extern int of_list_instruction_OF_VERSION_1_2_populate_scalars(
    of_list_instruction_t *obj, int value);
extern int of_list_instruction_OF_VERSION_1_2_check_scalars(
    of_list_instruction_t *obj, int value);

extern int of_list_oxm_OF_VERSION_1_2_populate(
    of_list_oxm_t *obj, int value);
extern int of_list_oxm_OF_VERSION_1_2_check(
    of_list_oxm_t *obj, int value);
extern int of_list_oxm_OF_VERSION_1_2_populate_scalars(
    of_list_oxm_t *obj, int value);
extern int of_list_oxm_OF_VERSION_1_2_check_scalars(
    of_list_oxm_t *obj, int value);

extern int of_list_packet_queue_OF_VERSION_1_2_populate(
    of_list_packet_queue_t *obj, int value);
extern int of_list_packet_queue_OF_VERSION_1_2_check(
    of_list_packet_queue_t *obj, int value);
extern int of_list_packet_queue_OF_VERSION_1_2_populate_scalars(
    of_list_packet_queue_t *obj, int value);
extern int of_list_packet_queue_OF_VERSION_1_2_check_scalars(
    of_list_packet_queue_t *obj, int value);

extern int of_list_port_desc_OF_VERSION_1_2_populate(
    of_list_port_desc_t *obj, int value);
extern int of_list_port_desc_OF_VERSION_1_2_check(
    of_list_port_desc_t *obj, int value);
extern int of_list_port_desc_OF_VERSION_1_2_populate_scalars(
    of_list_port_desc_t *obj, int value);
extern int of_list_port_desc_OF_VERSION_1_2_check_scalars(
    of_list_port_desc_t *obj, int value);

extern int of_list_port_stats_entry_OF_VERSION_1_2_populate(
    of_list_port_stats_entry_t *obj, int value);
extern int of_list_port_stats_entry_OF_VERSION_1_2_check(
    of_list_port_stats_entry_t *obj, int value);
extern int of_list_port_stats_entry_OF_VERSION_1_2_populate_scalars(
    of_list_port_stats_entry_t *obj, int value);
extern int of_list_port_stats_entry_OF_VERSION_1_2_check_scalars(
    of_list_port_stats_entry_t *obj, int value);

extern int of_list_queue_prop_OF_VERSION_1_2_populate(
    of_list_queue_prop_t *obj, int value);
extern int of_list_queue_prop_OF_VERSION_1_2_check(
    of_list_queue_prop_t *obj, int value);
extern int of_list_queue_prop_OF_VERSION_1_2_populate_scalars(
    of_list_queue_prop_t *obj, int value);
extern int of_list_queue_prop_OF_VERSION_1_2_check_scalars(
    of_list_queue_prop_t *obj, int value);

extern int of_list_queue_stats_entry_OF_VERSION_1_2_populate(
    of_list_queue_stats_entry_t *obj, int value);
extern int of_list_queue_stats_entry_OF_VERSION_1_2_check(
    of_list_queue_stats_entry_t *obj, int value);
extern int of_list_queue_stats_entry_OF_VERSION_1_2_populate_scalars(
    of_list_queue_stats_entry_t *obj, int value);
extern int of_list_queue_stats_entry_OF_VERSION_1_2_check_scalars(
    of_list_queue_stats_entry_t *obj, int value);

extern int of_list_table_stats_entry_OF_VERSION_1_2_populate(
    of_list_table_stats_entry_t *obj, int value);
extern int of_list_table_stats_entry_OF_VERSION_1_2_check(
    of_list_table_stats_entry_t *obj, int value);
extern int of_list_table_stats_entry_OF_VERSION_1_2_populate_scalars(
    of_list_table_stats_entry_t *obj, int value);
extern int of_list_table_stats_entry_OF_VERSION_1_2_check_scalars(
    of_list_table_stats_entry_t *obj, int value);

extern int of_aggregate_stats_reply_OF_VERSION_1_3_populate(
    of_aggregate_stats_reply_t *obj, int value);
extern int of_aggregate_stats_reply_OF_VERSION_1_3_check(
    of_aggregate_stats_reply_t *obj, int value);
extern int of_aggregate_stats_reply_OF_VERSION_1_3_populate_scalars(
    of_aggregate_stats_reply_t *obj, int value);
extern int of_aggregate_stats_reply_OF_VERSION_1_3_check_scalars(
    of_aggregate_stats_reply_t *obj, int value);

extern int of_aggregate_stats_request_OF_VERSION_1_3_populate(
    of_aggregate_stats_request_t *obj, int value);
extern int of_aggregate_stats_request_OF_VERSION_1_3_check(
    of_aggregate_stats_request_t *obj, int value);
extern int of_aggregate_stats_request_OF_VERSION_1_3_populate_scalars(
    of_aggregate_stats_request_t *obj, int value);
extern int of_aggregate_stats_request_OF_VERSION_1_3_check_scalars(
    of_aggregate_stats_request_t *obj, int value);

extern int of_async_get_reply_OF_VERSION_1_3_populate(
    of_async_get_reply_t *obj, int value);
extern int of_async_get_reply_OF_VERSION_1_3_check(
    of_async_get_reply_t *obj, int value);
extern int of_async_get_reply_OF_VERSION_1_3_populate_scalars(
    of_async_get_reply_t *obj, int value);
extern int of_async_get_reply_OF_VERSION_1_3_check_scalars(
    of_async_get_reply_t *obj, int value);

extern int of_async_get_request_OF_VERSION_1_3_populate(
    of_async_get_request_t *obj, int value);
extern int of_async_get_request_OF_VERSION_1_3_check(
    of_async_get_request_t *obj, int value);
extern int of_async_get_request_OF_VERSION_1_3_populate_scalars(
    of_async_get_request_t *obj, int value);
extern int of_async_get_request_OF_VERSION_1_3_check_scalars(
    of_async_get_request_t *obj, int value);

extern int of_async_set_OF_VERSION_1_3_populate(
    of_async_set_t *obj, int value);
extern int of_async_set_OF_VERSION_1_3_check(
    of_async_set_t *obj, int value);
extern int of_async_set_OF_VERSION_1_3_populate_scalars(
    of_async_set_t *obj, int value);
extern int of_async_set_OF_VERSION_1_3_check_scalars(
    of_async_set_t *obj, int value);

extern int of_bad_action_error_msg_OF_VERSION_1_3_populate(
    of_bad_action_error_msg_t *obj, int value);
extern int of_bad_action_error_msg_OF_VERSION_1_3_check(
    of_bad_action_error_msg_t *obj, int value);
extern int of_bad_action_error_msg_OF_VERSION_1_3_populate_scalars(
    of_bad_action_error_msg_t *obj, int value);
extern int of_bad_action_error_msg_OF_VERSION_1_3_check_scalars(
    of_bad_action_error_msg_t *obj, int value);

extern int of_bad_instruction_error_msg_OF_VERSION_1_3_populate(
    of_bad_instruction_error_msg_t *obj, int value);
extern int of_bad_instruction_error_msg_OF_VERSION_1_3_check(
    of_bad_instruction_error_msg_t *obj, int value);
extern int of_bad_instruction_error_msg_OF_VERSION_1_3_populate_scalars(
    of_bad_instruction_error_msg_t *obj, int value);
extern int of_bad_instruction_error_msg_OF_VERSION_1_3_check_scalars(
    of_bad_instruction_error_msg_t *obj, int value);

extern int of_bad_match_error_msg_OF_VERSION_1_3_populate(
    of_bad_match_error_msg_t *obj, int value);
extern int of_bad_match_error_msg_OF_VERSION_1_3_check(
    of_bad_match_error_msg_t *obj, int value);
extern int of_bad_match_error_msg_OF_VERSION_1_3_populate_scalars(
    of_bad_match_error_msg_t *obj, int value);
extern int of_bad_match_error_msg_OF_VERSION_1_3_check_scalars(
    of_bad_match_error_msg_t *obj, int value);

extern int of_bad_request_error_msg_OF_VERSION_1_3_populate(
    of_bad_request_error_msg_t *obj, int value);
extern int of_bad_request_error_msg_OF_VERSION_1_3_check(
    of_bad_request_error_msg_t *obj, int value);
extern int of_bad_request_error_msg_OF_VERSION_1_3_populate_scalars(
    of_bad_request_error_msg_t *obj, int value);
extern int of_bad_request_error_msg_OF_VERSION_1_3_check_scalars(
    of_bad_request_error_msg_t *obj, int value);

extern int of_barrier_reply_OF_VERSION_1_3_populate(
    of_barrier_reply_t *obj, int value);
extern int of_barrier_reply_OF_VERSION_1_3_check(
    of_barrier_reply_t *obj, int value);
extern int of_barrier_reply_OF_VERSION_1_3_populate_scalars(
    of_barrier_reply_t *obj, int value);
extern int of_barrier_reply_OF_VERSION_1_3_check_scalars(
    of_barrier_reply_t *obj, int value);

extern int of_barrier_request_OF_VERSION_1_3_populate(
    of_barrier_request_t *obj, int value);
extern int of_barrier_request_OF_VERSION_1_3_check(
    of_barrier_request_t *obj, int value);
extern int of_barrier_request_OF_VERSION_1_3_populate_scalars(
    of_barrier_request_t *obj, int value);
extern int of_barrier_request_OF_VERSION_1_3_check_scalars(
    of_barrier_request_t *obj, int value);

extern int of_bsn_arp_idle_OF_VERSION_1_3_populate(
    of_bsn_arp_idle_t *obj, int value);
extern int of_bsn_arp_idle_OF_VERSION_1_3_check(
    of_bsn_arp_idle_t *obj, int value);
extern int of_bsn_arp_idle_OF_VERSION_1_3_populate_scalars(
    of_bsn_arp_idle_t *obj, int value);
extern int of_bsn_arp_idle_OF_VERSION_1_3_check_scalars(
    of_bsn_arp_idle_t *obj, int value);

extern int of_bsn_bw_clear_data_reply_OF_VERSION_1_3_populate(
    of_bsn_bw_clear_data_reply_t *obj, int value);
extern int of_bsn_bw_clear_data_reply_OF_VERSION_1_3_check(
    of_bsn_bw_clear_data_reply_t *obj, int value);
extern int of_bsn_bw_clear_data_reply_OF_VERSION_1_3_populate_scalars(
    of_bsn_bw_clear_data_reply_t *obj, int value);
extern int of_bsn_bw_clear_data_reply_OF_VERSION_1_3_check_scalars(
    of_bsn_bw_clear_data_reply_t *obj, int value);

extern int of_bsn_bw_clear_data_request_OF_VERSION_1_3_populate(
    of_bsn_bw_clear_data_request_t *obj, int value);
extern int of_bsn_bw_clear_data_request_OF_VERSION_1_3_check(
    of_bsn_bw_clear_data_request_t *obj, int value);
extern int of_bsn_bw_clear_data_request_OF_VERSION_1_3_populate_scalars(
    of_bsn_bw_clear_data_request_t *obj, int value);
extern int of_bsn_bw_clear_data_request_OF_VERSION_1_3_check_scalars(
    of_bsn_bw_clear_data_request_t *obj, int value);

extern int of_bsn_bw_enable_get_reply_OF_VERSION_1_3_populate(
    of_bsn_bw_enable_get_reply_t *obj, int value);
extern int of_bsn_bw_enable_get_reply_OF_VERSION_1_3_check(
    of_bsn_bw_enable_get_reply_t *obj, int value);
extern int of_bsn_bw_enable_get_reply_OF_VERSION_1_3_populate_scalars(
    of_bsn_bw_enable_get_reply_t *obj, int value);
extern int of_bsn_bw_enable_get_reply_OF_VERSION_1_3_check_scalars(
    of_bsn_bw_enable_get_reply_t *obj, int value);

extern int of_bsn_bw_enable_get_request_OF_VERSION_1_3_populate(
    of_bsn_bw_enable_get_request_t *obj, int value);
extern int of_bsn_bw_enable_get_request_OF_VERSION_1_3_check(
    of_bsn_bw_enable_get_request_t *obj, int value);
extern int of_bsn_bw_enable_get_request_OF_VERSION_1_3_populate_scalars(
    of_bsn_bw_enable_get_request_t *obj, int value);
extern int of_bsn_bw_enable_get_request_OF_VERSION_1_3_check_scalars(
    of_bsn_bw_enable_get_request_t *obj, int value);

extern int of_bsn_bw_enable_set_reply_OF_VERSION_1_3_populate(
    of_bsn_bw_enable_set_reply_t *obj, int value);
extern int of_bsn_bw_enable_set_reply_OF_VERSION_1_3_check(
    of_bsn_bw_enable_set_reply_t *obj, int value);
extern int of_bsn_bw_enable_set_reply_OF_VERSION_1_3_populate_scalars(
    of_bsn_bw_enable_set_reply_t *obj, int value);
extern int of_bsn_bw_enable_set_reply_OF_VERSION_1_3_check_scalars(
    of_bsn_bw_enable_set_reply_t *obj, int value);

extern int of_bsn_bw_enable_set_request_OF_VERSION_1_3_populate(
    of_bsn_bw_enable_set_request_t *obj, int value);
extern int of_bsn_bw_enable_set_request_OF_VERSION_1_3_check(
    of_bsn_bw_enable_set_request_t *obj, int value);
extern int of_bsn_bw_enable_set_request_OF_VERSION_1_3_populate_scalars(
    of_bsn_bw_enable_set_request_t *obj, int value);
extern int of_bsn_bw_enable_set_request_OF_VERSION_1_3_check_scalars(
    of_bsn_bw_enable_set_request_t *obj, int value);

extern int of_bsn_controller_connections_reply_OF_VERSION_1_3_populate(
    of_bsn_controller_connections_reply_t *obj, int value);
extern int of_bsn_controller_connections_reply_OF_VERSION_1_3_check(
    of_bsn_controller_connections_reply_t *obj, int value);
extern int of_bsn_controller_connections_reply_OF_VERSION_1_3_populate_scalars(
    of_bsn_controller_connections_reply_t *obj, int value);
extern int of_bsn_controller_connections_reply_OF_VERSION_1_3_check_scalars(
    of_bsn_controller_connections_reply_t *obj, int value);

extern int of_bsn_controller_connections_request_OF_VERSION_1_3_populate(
    of_bsn_controller_connections_request_t *obj, int value);
extern int of_bsn_controller_connections_request_OF_VERSION_1_3_check(
    of_bsn_controller_connections_request_t *obj, int value);
extern int of_bsn_controller_connections_request_OF_VERSION_1_3_populate_scalars(
    of_bsn_controller_connections_request_t *obj, int value);
extern int of_bsn_controller_connections_request_OF_VERSION_1_3_check_scalars(
    of_bsn_controller_connections_request_t *obj, int value);

extern int of_bsn_debug_counter_desc_stats_reply_OF_VERSION_1_3_populate(
    of_bsn_debug_counter_desc_stats_reply_t *obj, int value);
extern int of_bsn_debug_counter_desc_stats_reply_OF_VERSION_1_3_check(
    of_bsn_debug_counter_desc_stats_reply_t *obj, int value);
extern int of_bsn_debug_counter_desc_stats_reply_OF_VERSION_1_3_populate_scalars(
    of_bsn_debug_counter_desc_stats_reply_t *obj, int value);
extern int of_bsn_debug_counter_desc_stats_reply_OF_VERSION_1_3_check_scalars(
    of_bsn_debug_counter_desc_stats_reply_t *obj, int value);

extern int of_bsn_debug_counter_desc_stats_request_OF_VERSION_1_3_populate(
    of_bsn_debug_counter_desc_stats_request_t *obj, int value);
extern int of_bsn_debug_counter_desc_stats_request_OF_VERSION_1_3_check(
    of_bsn_debug_counter_desc_stats_request_t *obj, int value);
extern int of_bsn_debug_counter_desc_stats_request_OF_VERSION_1_3_populate_scalars(
    of_bsn_debug_counter_desc_stats_request_t *obj, int value);
extern int of_bsn_debug_counter_desc_stats_request_OF_VERSION_1_3_check_scalars(
    of_bsn_debug_counter_desc_stats_request_t *obj, int value);

extern int of_bsn_debug_counter_stats_reply_OF_VERSION_1_3_populate(
    of_bsn_debug_counter_stats_reply_t *obj, int value);
extern int of_bsn_debug_counter_stats_reply_OF_VERSION_1_3_check(
    of_bsn_debug_counter_stats_reply_t *obj, int value);
extern int of_bsn_debug_counter_stats_reply_OF_VERSION_1_3_populate_scalars(
    of_bsn_debug_counter_stats_reply_t *obj, int value);
extern int of_bsn_debug_counter_stats_reply_OF_VERSION_1_3_check_scalars(
    of_bsn_debug_counter_stats_reply_t *obj, int value);

extern int of_bsn_debug_counter_stats_request_OF_VERSION_1_3_populate(
    of_bsn_debug_counter_stats_request_t *obj, int value);
extern int of_bsn_debug_counter_stats_request_OF_VERSION_1_3_check(
    of_bsn_debug_counter_stats_request_t *obj, int value);
extern int of_bsn_debug_counter_stats_request_OF_VERSION_1_3_populate_scalars(
    of_bsn_debug_counter_stats_request_t *obj, int value);
extern int of_bsn_debug_counter_stats_request_OF_VERSION_1_3_check_scalars(
    of_bsn_debug_counter_stats_request_t *obj, int value);

extern int of_bsn_error_OF_VERSION_1_3_populate(
    of_bsn_error_t *obj, int value);
extern int of_bsn_error_OF_VERSION_1_3_check(
    of_bsn_error_t *obj, int value);
extern int of_bsn_error_OF_VERSION_1_3_populate_scalars(
    of_bsn_error_t *obj, int value);
extern int of_bsn_error_OF_VERSION_1_3_check_scalars(
    of_bsn_error_t *obj, int value);

extern int of_bsn_flow_checksum_bucket_stats_reply_OF_VERSION_1_3_populate(
    of_bsn_flow_checksum_bucket_stats_reply_t *obj, int value);
extern int of_bsn_flow_checksum_bucket_stats_reply_OF_VERSION_1_3_check(
    of_bsn_flow_checksum_bucket_stats_reply_t *obj, int value);
extern int of_bsn_flow_checksum_bucket_stats_reply_OF_VERSION_1_3_populate_scalars(
    of_bsn_flow_checksum_bucket_stats_reply_t *obj, int value);
extern int of_bsn_flow_checksum_bucket_stats_reply_OF_VERSION_1_3_check_scalars(
    of_bsn_flow_checksum_bucket_stats_reply_t *obj, int value);

extern int of_bsn_flow_checksum_bucket_stats_request_OF_VERSION_1_3_populate(
    of_bsn_flow_checksum_bucket_stats_request_t *obj, int value);
extern int of_bsn_flow_checksum_bucket_stats_request_OF_VERSION_1_3_check(
    of_bsn_flow_checksum_bucket_stats_request_t *obj, int value);
extern int of_bsn_flow_checksum_bucket_stats_request_OF_VERSION_1_3_populate_scalars(
    of_bsn_flow_checksum_bucket_stats_request_t *obj, int value);
extern int of_bsn_flow_checksum_bucket_stats_request_OF_VERSION_1_3_check_scalars(
    of_bsn_flow_checksum_bucket_stats_request_t *obj, int value);

extern int of_bsn_flow_idle_OF_VERSION_1_3_populate(
    of_bsn_flow_idle_t *obj, int value);
extern int of_bsn_flow_idle_OF_VERSION_1_3_check(
    of_bsn_flow_idle_t *obj, int value);
extern int of_bsn_flow_idle_OF_VERSION_1_3_populate_scalars(
    of_bsn_flow_idle_t *obj, int value);
extern int of_bsn_flow_idle_OF_VERSION_1_3_check_scalars(
    of_bsn_flow_idle_t *obj, int value);

extern int of_bsn_flow_idle_enable_get_reply_OF_VERSION_1_3_populate(
    of_bsn_flow_idle_enable_get_reply_t *obj, int value);
extern int of_bsn_flow_idle_enable_get_reply_OF_VERSION_1_3_check(
    of_bsn_flow_idle_enable_get_reply_t *obj, int value);
extern int of_bsn_flow_idle_enable_get_reply_OF_VERSION_1_3_populate_scalars(
    of_bsn_flow_idle_enable_get_reply_t *obj, int value);
extern int of_bsn_flow_idle_enable_get_reply_OF_VERSION_1_3_check_scalars(
    of_bsn_flow_idle_enable_get_reply_t *obj, int value);

extern int of_bsn_flow_idle_enable_get_request_OF_VERSION_1_3_populate(
    of_bsn_flow_idle_enable_get_request_t *obj, int value);
extern int of_bsn_flow_idle_enable_get_request_OF_VERSION_1_3_check(
    of_bsn_flow_idle_enable_get_request_t *obj, int value);
extern int of_bsn_flow_idle_enable_get_request_OF_VERSION_1_3_populate_scalars(
    of_bsn_flow_idle_enable_get_request_t *obj, int value);
extern int of_bsn_flow_idle_enable_get_request_OF_VERSION_1_3_check_scalars(
    of_bsn_flow_idle_enable_get_request_t *obj, int value);

extern int of_bsn_flow_idle_enable_set_reply_OF_VERSION_1_3_populate(
    of_bsn_flow_idle_enable_set_reply_t *obj, int value);
extern int of_bsn_flow_idle_enable_set_reply_OF_VERSION_1_3_check(
    of_bsn_flow_idle_enable_set_reply_t *obj, int value);
extern int of_bsn_flow_idle_enable_set_reply_OF_VERSION_1_3_populate_scalars(
    of_bsn_flow_idle_enable_set_reply_t *obj, int value);
extern int of_bsn_flow_idle_enable_set_reply_OF_VERSION_1_3_check_scalars(
    of_bsn_flow_idle_enable_set_reply_t *obj, int value);

extern int of_bsn_flow_idle_enable_set_request_OF_VERSION_1_3_populate(
    of_bsn_flow_idle_enable_set_request_t *obj, int value);
extern int of_bsn_flow_idle_enable_set_request_OF_VERSION_1_3_check(
    of_bsn_flow_idle_enable_set_request_t *obj, int value);
extern int of_bsn_flow_idle_enable_set_request_OF_VERSION_1_3_populate_scalars(
    of_bsn_flow_idle_enable_set_request_t *obj, int value);
extern int of_bsn_flow_idle_enable_set_request_OF_VERSION_1_3_check_scalars(
    of_bsn_flow_idle_enable_set_request_t *obj, int value);

extern int of_bsn_generic_stats_reply_OF_VERSION_1_3_populate(
    of_bsn_generic_stats_reply_t *obj, int value);
extern int of_bsn_generic_stats_reply_OF_VERSION_1_3_check(
    of_bsn_generic_stats_reply_t *obj, int value);
extern int of_bsn_generic_stats_reply_OF_VERSION_1_3_populate_scalars(
    of_bsn_generic_stats_reply_t *obj, int value);
extern int of_bsn_generic_stats_reply_OF_VERSION_1_3_check_scalars(
    of_bsn_generic_stats_reply_t *obj, int value);

extern int of_bsn_generic_stats_request_OF_VERSION_1_3_populate(
    of_bsn_generic_stats_request_t *obj, int value);
extern int of_bsn_generic_stats_request_OF_VERSION_1_3_check(
    of_bsn_generic_stats_request_t *obj, int value);
extern int of_bsn_generic_stats_request_OF_VERSION_1_3_populate_scalars(
    of_bsn_generic_stats_request_t *obj, int value);
extern int of_bsn_generic_stats_request_OF_VERSION_1_3_check_scalars(
    of_bsn_generic_stats_request_t *obj, int value);

extern int of_bsn_gentable_bucket_stats_reply_OF_VERSION_1_3_populate(
    of_bsn_gentable_bucket_stats_reply_t *obj, int value);
extern int of_bsn_gentable_bucket_stats_reply_OF_VERSION_1_3_check(
    of_bsn_gentable_bucket_stats_reply_t *obj, int value);
extern int of_bsn_gentable_bucket_stats_reply_OF_VERSION_1_3_populate_scalars(
    of_bsn_gentable_bucket_stats_reply_t *obj, int value);
extern int of_bsn_gentable_bucket_stats_reply_OF_VERSION_1_3_check_scalars(
    of_bsn_gentable_bucket_stats_reply_t *obj, int value);

extern int of_bsn_gentable_bucket_stats_request_OF_VERSION_1_3_populate(
    of_bsn_gentable_bucket_stats_request_t *obj, int value);
extern int of_bsn_gentable_bucket_stats_request_OF_VERSION_1_3_check(
    of_bsn_gentable_bucket_stats_request_t *obj, int value);
extern int of_bsn_gentable_bucket_stats_request_OF_VERSION_1_3_populate_scalars(
    of_bsn_gentable_bucket_stats_request_t *obj, int value);
extern int of_bsn_gentable_bucket_stats_request_OF_VERSION_1_3_check_scalars(
    of_bsn_gentable_bucket_stats_request_t *obj, int value);

extern int of_bsn_gentable_clear_reply_OF_VERSION_1_3_populate(
    of_bsn_gentable_clear_reply_t *obj, int value);
extern int of_bsn_gentable_clear_reply_OF_VERSION_1_3_check(
    of_bsn_gentable_clear_reply_t *obj, int value);
extern int of_bsn_gentable_clear_reply_OF_VERSION_1_3_populate_scalars(
    of_bsn_gentable_clear_reply_t *obj, int value);
extern int of_bsn_gentable_clear_reply_OF_VERSION_1_3_check_scalars(
    of_bsn_gentable_clear_reply_t *obj, int value);

extern int of_bsn_gentable_clear_request_OF_VERSION_1_3_populate(
    of_bsn_gentable_clear_request_t *obj, int value);
extern int of_bsn_gentable_clear_request_OF_VERSION_1_3_check(
    of_bsn_gentable_clear_request_t *obj, int value);
extern int of_bsn_gentable_clear_request_OF_VERSION_1_3_populate_scalars(
    of_bsn_gentable_clear_request_t *obj, int value);
extern int of_bsn_gentable_clear_request_OF_VERSION_1_3_check_scalars(
    of_bsn_gentable_clear_request_t *obj, int value);

extern int of_bsn_gentable_desc_stats_reply_OF_VERSION_1_3_populate(
    of_bsn_gentable_desc_stats_reply_t *obj, int value);
extern int of_bsn_gentable_desc_stats_reply_OF_VERSION_1_3_check(
    of_bsn_gentable_desc_stats_reply_t *obj, int value);
extern int of_bsn_gentable_desc_stats_reply_OF_VERSION_1_3_populate_scalars(
    of_bsn_gentable_desc_stats_reply_t *obj, int value);
extern int of_bsn_gentable_desc_stats_reply_OF_VERSION_1_3_check_scalars(
    of_bsn_gentable_desc_stats_reply_t *obj, int value);

extern int of_bsn_gentable_desc_stats_request_OF_VERSION_1_3_populate(
    of_bsn_gentable_desc_stats_request_t *obj, int value);
extern int of_bsn_gentable_desc_stats_request_OF_VERSION_1_3_check(
    of_bsn_gentable_desc_stats_request_t *obj, int value);
extern int of_bsn_gentable_desc_stats_request_OF_VERSION_1_3_populate_scalars(
    of_bsn_gentable_desc_stats_request_t *obj, int value);
extern int of_bsn_gentable_desc_stats_request_OF_VERSION_1_3_check_scalars(
    of_bsn_gentable_desc_stats_request_t *obj, int value);

extern int of_bsn_gentable_entry_add_OF_VERSION_1_3_populate(
    of_bsn_gentable_entry_add_t *obj, int value);
extern int of_bsn_gentable_entry_add_OF_VERSION_1_3_check(
    of_bsn_gentable_entry_add_t *obj, int value);
extern int of_bsn_gentable_entry_add_OF_VERSION_1_3_populate_scalars(
    of_bsn_gentable_entry_add_t *obj, int value);
extern int of_bsn_gentable_entry_add_OF_VERSION_1_3_check_scalars(
    of_bsn_gentable_entry_add_t *obj, int value);

extern int of_bsn_gentable_entry_delete_OF_VERSION_1_3_populate(
    of_bsn_gentable_entry_delete_t *obj, int value);
extern int of_bsn_gentable_entry_delete_OF_VERSION_1_3_check(
    of_bsn_gentable_entry_delete_t *obj, int value);
extern int of_bsn_gentable_entry_delete_OF_VERSION_1_3_populate_scalars(
    of_bsn_gentable_entry_delete_t *obj, int value);
extern int of_bsn_gentable_entry_delete_OF_VERSION_1_3_check_scalars(
    of_bsn_gentable_entry_delete_t *obj, int value);

extern int of_bsn_gentable_entry_desc_stats_reply_OF_VERSION_1_3_populate(
    of_bsn_gentable_entry_desc_stats_reply_t *obj, int value);
extern int of_bsn_gentable_entry_desc_stats_reply_OF_VERSION_1_3_check(
    of_bsn_gentable_entry_desc_stats_reply_t *obj, int value);
extern int of_bsn_gentable_entry_desc_stats_reply_OF_VERSION_1_3_populate_scalars(
    of_bsn_gentable_entry_desc_stats_reply_t *obj, int value);
extern int of_bsn_gentable_entry_desc_stats_reply_OF_VERSION_1_3_check_scalars(
    of_bsn_gentable_entry_desc_stats_reply_t *obj, int value);

extern int of_bsn_gentable_entry_desc_stats_request_OF_VERSION_1_3_populate(
    of_bsn_gentable_entry_desc_stats_request_t *obj, int value);
extern int of_bsn_gentable_entry_desc_stats_request_OF_VERSION_1_3_check(
    of_bsn_gentable_entry_desc_stats_request_t *obj, int value);
extern int of_bsn_gentable_entry_desc_stats_request_OF_VERSION_1_3_populate_scalars(
    of_bsn_gentable_entry_desc_stats_request_t *obj, int value);
extern int of_bsn_gentable_entry_desc_stats_request_OF_VERSION_1_3_check_scalars(
    of_bsn_gentable_entry_desc_stats_request_t *obj, int value);

extern int of_bsn_gentable_entry_stats_reply_OF_VERSION_1_3_populate(
    of_bsn_gentable_entry_stats_reply_t *obj, int value);
extern int of_bsn_gentable_entry_stats_reply_OF_VERSION_1_3_check(
    of_bsn_gentable_entry_stats_reply_t *obj, int value);
extern int of_bsn_gentable_entry_stats_reply_OF_VERSION_1_3_populate_scalars(
    of_bsn_gentable_entry_stats_reply_t *obj, int value);
extern int of_bsn_gentable_entry_stats_reply_OF_VERSION_1_3_check_scalars(
    of_bsn_gentable_entry_stats_reply_t *obj, int value);

extern int of_bsn_gentable_entry_stats_request_OF_VERSION_1_3_populate(
    of_bsn_gentable_entry_stats_request_t *obj, int value);
extern int of_bsn_gentable_entry_stats_request_OF_VERSION_1_3_check(
    of_bsn_gentable_entry_stats_request_t *obj, int value);
extern int of_bsn_gentable_entry_stats_request_OF_VERSION_1_3_populate_scalars(
    of_bsn_gentable_entry_stats_request_t *obj, int value);
extern int of_bsn_gentable_entry_stats_request_OF_VERSION_1_3_check_scalars(
    of_bsn_gentable_entry_stats_request_t *obj, int value);

extern int of_bsn_gentable_error_OF_VERSION_1_3_populate(
    of_bsn_gentable_error_t *obj, int value);
extern int of_bsn_gentable_error_OF_VERSION_1_3_check(
    of_bsn_gentable_error_t *obj, int value);
extern int of_bsn_gentable_error_OF_VERSION_1_3_populate_scalars(
    of_bsn_gentable_error_t *obj, int value);
extern int of_bsn_gentable_error_OF_VERSION_1_3_check_scalars(
    of_bsn_gentable_error_t *obj, int value);

extern int of_bsn_gentable_set_buckets_size_OF_VERSION_1_3_populate(
    of_bsn_gentable_set_buckets_size_t *obj, int value);
extern int of_bsn_gentable_set_buckets_size_OF_VERSION_1_3_check(
    of_bsn_gentable_set_buckets_size_t *obj, int value);
extern int of_bsn_gentable_set_buckets_size_OF_VERSION_1_3_populate_scalars(
    of_bsn_gentable_set_buckets_size_t *obj, int value);
extern int of_bsn_gentable_set_buckets_size_OF_VERSION_1_3_check_scalars(
    of_bsn_gentable_set_buckets_size_t *obj, int value);

extern int of_bsn_gentable_stats_reply_OF_VERSION_1_3_populate(
    of_bsn_gentable_stats_reply_t *obj, int value);
extern int of_bsn_gentable_stats_reply_OF_VERSION_1_3_check(
    of_bsn_gentable_stats_reply_t *obj, int value);
extern int of_bsn_gentable_stats_reply_OF_VERSION_1_3_populate_scalars(
    of_bsn_gentable_stats_reply_t *obj, int value);
extern int of_bsn_gentable_stats_reply_OF_VERSION_1_3_check_scalars(
    of_bsn_gentable_stats_reply_t *obj, int value);

extern int of_bsn_gentable_stats_request_OF_VERSION_1_3_populate(
    of_bsn_gentable_stats_request_t *obj, int value);
extern int of_bsn_gentable_stats_request_OF_VERSION_1_3_check(
    of_bsn_gentable_stats_request_t *obj, int value);
extern int of_bsn_gentable_stats_request_OF_VERSION_1_3_populate_scalars(
    of_bsn_gentable_stats_request_t *obj, int value);
extern int of_bsn_gentable_stats_request_OF_VERSION_1_3_check_scalars(
    of_bsn_gentable_stats_request_t *obj, int value);

extern int of_bsn_get_interfaces_reply_OF_VERSION_1_3_populate(
    of_bsn_get_interfaces_reply_t *obj, int value);
extern int of_bsn_get_interfaces_reply_OF_VERSION_1_3_check(
    of_bsn_get_interfaces_reply_t *obj, int value);
extern int of_bsn_get_interfaces_reply_OF_VERSION_1_3_populate_scalars(
    of_bsn_get_interfaces_reply_t *obj, int value);
extern int of_bsn_get_interfaces_reply_OF_VERSION_1_3_check_scalars(
    of_bsn_get_interfaces_reply_t *obj, int value);

extern int of_bsn_get_interfaces_request_OF_VERSION_1_3_populate(
    of_bsn_get_interfaces_request_t *obj, int value);
extern int of_bsn_get_interfaces_request_OF_VERSION_1_3_check(
    of_bsn_get_interfaces_request_t *obj, int value);
extern int of_bsn_get_interfaces_request_OF_VERSION_1_3_populate_scalars(
    of_bsn_get_interfaces_request_t *obj, int value);
extern int of_bsn_get_interfaces_request_OF_VERSION_1_3_check_scalars(
    of_bsn_get_interfaces_request_t *obj, int value);

extern int of_bsn_get_mirroring_reply_OF_VERSION_1_3_populate(
    of_bsn_get_mirroring_reply_t *obj, int value);
extern int of_bsn_get_mirroring_reply_OF_VERSION_1_3_check(
    of_bsn_get_mirroring_reply_t *obj, int value);
extern int of_bsn_get_mirroring_reply_OF_VERSION_1_3_populate_scalars(
    of_bsn_get_mirroring_reply_t *obj, int value);
extern int of_bsn_get_mirroring_reply_OF_VERSION_1_3_check_scalars(
    of_bsn_get_mirroring_reply_t *obj, int value);

extern int of_bsn_get_mirroring_request_OF_VERSION_1_3_populate(
    of_bsn_get_mirroring_request_t *obj, int value);
extern int of_bsn_get_mirroring_request_OF_VERSION_1_3_check(
    of_bsn_get_mirroring_request_t *obj, int value);
extern int of_bsn_get_mirroring_request_OF_VERSION_1_3_populate_scalars(
    of_bsn_get_mirroring_request_t *obj, int value);
extern int of_bsn_get_mirroring_request_OF_VERSION_1_3_check_scalars(
    of_bsn_get_mirroring_request_t *obj, int value);

extern int of_bsn_get_switch_pipeline_reply_OF_VERSION_1_3_populate(
    of_bsn_get_switch_pipeline_reply_t *obj, int value);
extern int of_bsn_get_switch_pipeline_reply_OF_VERSION_1_3_check(
    of_bsn_get_switch_pipeline_reply_t *obj, int value);
extern int of_bsn_get_switch_pipeline_reply_OF_VERSION_1_3_populate_scalars(
    of_bsn_get_switch_pipeline_reply_t *obj, int value);
extern int of_bsn_get_switch_pipeline_reply_OF_VERSION_1_3_check_scalars(
    of_bsn_get_switch_pipeline_reply_t *obj, int value);

extern int of_bsn_get_switch_pipeline_request_OF_VERSION_1_3_populate(
    of_bsn_get_switch_pipeline_request_t *obj, int value);
extern int of_bsn_get_switch_pipeline_request_OF_VERSION_1_3_check(
    of_bsn_get_switch_pipeline_request_t *obj, int value);
extern int of_bsn_get_switch_pipeline_request_OF_VERSION_1_3_populate_scalars(
    of_bsn_get_switch_pipeline_request_t *obj, int value);
extern int of_bsn_get_switch_pipeline_request_OF_VERSION_1_3_check_scalars(
    of_bsn_get_switch_pipeline_request_t *obj, int value);

extern int of_bsn_image_desc_stats_reply_OF_VERSION_1_3_populate(
    of_bsn_image_desc_stats_reply_t *obj, int value);
extern int of_bsn_image_desc_stats_reply_OF_VERSION_1_3_check(
    of_bsn_image_desc_stats_reply_t *obj, int value);
extern int of_bsn_image_desc_stats_reply_OF_VERSION_1_3_populate_scalars(
    of_bsn_image_desc_stats_reply_t *obj, int value);
extern int of_bsn_image_desc_stats_reply_OF_VERSION_1_3_check_scalars(
    of_bsn_image_desc_stats_reply_t *obj, int value);

extern int of_bsn_image_desc_stats_request_OF_VERSION_1_3_populate(
    of_bsn_image_desc_stats_request_t *obj, int value);
extern int of_bsn_image_desc_stats_request_OF_VERSION_1_3_check(
    of_bsn_image_desc_stats_request_t *obj, int value);
extern int of_bsn_image_desc_stats_request_OF_VERSION_1_3_populate_scalars(
    of_bsn_image_desc_stats_request_t *obj, int value);
extern int of_bsn_image_desc_stats_request_OF_VERSION_1_3_check_scalars(
    of_bsn_image_desc_stats_request_t *obj, int value);

extern int of_bsn_lacp_convergence_notif_OF_VERSION_1_3_populate(
    of_bsn_lacp_convergence_notif_t *obj, int value);
extern int of_bsn_lacp_convergence_notif_OF_VERSION_1_3_check(
    of_bsn_lacp_convergence_notif_t *obj, int value);
extern int of_bsn_lacp_convergence_notif_OF_VERSION_1_3_populate_scalars(
    of_bsn_lacp_convergence_notif_t *obj, int value);
extern int of_bsn_lacp_convergence_notif_OF_VERSION_1_3_check_scalars(
    of_bsn_lacp_convergence_notif_t *obj, int value);

extern int of_bsn_lacp_stats_reply_OF_VERSION_1_3_populate(
    of_bsn_lacp_stats_reply_t *obj, int value);
extern int of_bsn_lacp_stats_reply_OF_VERSION_1_3_check(
    of_bsn_lacp_stats_reply_t *obj, int value);
extern int of_bsn_lacp_stats_reply_OF_VERSION_1_3_populate_scalars(
    of_bsn_lacp_stats_reply_t *obj, int value);
extern int of_bsn_lacp_stats_reply_OF_VERSION_1_3_check_scalars(
    of_bsn_lacp_stats_reply_t *obj, int value);

extern int of_bsn_lacp_stats_request_OF_VERSION_1_3_populate(
    of_bsn_lacp_stats_request_t *obj, int value);
extern int of_bsn_lacp_stats_request_OF_VERSION_1_3_check(
    of_bsn_lacp_stats_request_t *obj, int value);
extern int of_bsn_lacp_stats_request_OF_VERSION_1_3_populate_scalars(
    of_bsn_lacp_stats_request_t *obj, int value);
extern int of_bsn_lacp_stats_request_OF_VERSION_1_3_check_scalars(
    of_bsn_lacp_stats_request_t *obj, int value);

extern int of_bsn_log_OF_VERSION_1_3_populate(
    of_bsn_log_t *obj, int value);
extern int of_bsn_log_OF_VERSION_1_3_check(
    of_bsn_log_t *obj, int value);
extern int of_bsn_log_OF_VERSION_1_3_populate_scalars(
    of_bsn_log_t *obj, int value);
extern int of_bsn_log_OF_VERSION_1_3_check_scalars(
    of_bsn_log_t *obj, int value);

extern int of_bsn_lua_command_reply_OF_VERSION_1_3_populate(
    of_bsn_lua_command_reply_t *obj, int value);
extern int of_bsn_lua_command_reply_OF_VERSION_1_3_check(
    of_bsn_lua_command_reply_t *obj, int value);
extern int of_bsn_lua_command_reply_OF_VERSION_1_3_populate_scalars(
    of_bsn_lua_command_reply_t *obj, int value);
extern int of_bsn_lua_command_reply_OF_VERSION_1_3_check_scalars(
    of_bsn_lua_command_reply_t *obj, int value);

extern int of_bsn_lua_command_request_OF_VERSION_1_3_populate(
    of_bsn_lua_command_request_t *obj, int value);
extern int of_bsn_lua_command_request_OF_VERSION_1_3_check(
    of_bsn_lua_command_request_t *obj, int value);
extern int of_bsn_lua_command_request_OF_VERSION_1_3_populate_scalars(
    of_bsn_lua_command_request_t *obj, int value);
extern int of_bsn_lua_command_request_OF_VERSION_1_3_check_scalars(
    of_bsn_lua_command_request_t *obj, int value);

extern int of_bsn_lua_notification_OF_VERSION_1_3_populate(
    of_bsn_lua_notification_t *obj, int value);
extern int of_bsn_lua_notification_OF_VERSION_1_3_check(
    of_bsn_lua_notification_t *obj, int value);
extern int of_bsn_lua_notification_OF_VERSION_1_3_populate_scalars(
    of_bsn_lua_notification_t *obj, int value);
extern int of_bsn_lua_notification_OF_VERSION_1_3_check_scalars(
    of_bsn_lua_notification_t *obj, int value);

extern int of_bsn_lua_upload_OF_VERSION_1_3_populate(
    of_bsn_lua_upload_t *obj, int value);
extern int of_bsn_lua_upload_OF_VERSION_1_3_check(
    of_bsn_lua_upload_t *obj, int value);
extern int of_bsn_lua_upload_OF_VERSION_1_3_populate_scalars(
    of_bsn_lua_upload_t *obj, int value);
extern int of_bsn_lua_upload_OF_VERSION_1_3_check_scalars(
    of_bsn_lua_upload_t *obj, int value);

extern int of_bsn_pdu_rx_reply_OF_VERSION_1_3_populate(
    of_bsn_pdu_rx_reply_t *obj, int value);
extern int of_bsn_pdu_rx_reply_OF_VERSION_1_3_check(
    of_bsn_pdu_rx_reply_t *obj, int value);
extern int of_bsn_pdu_rx_reply_OF_VERSION_1_3_populate_scalars(
    of_bsn_pdu_rx_reply_t *obj, int value);
extern int of_bsn_pdu_rx_reply_OF_VERSION_1_3_check_scalars(
    of_bsn_pdu_rx_reply_t *obj, int value);

extern int of_bsn_pdu_rx_request_OF_VERSION_1_3_populate(
    of_bsn_pdu_rx_request_t *obj, int value);
extern int of_bsn_pdu_rx_request_OF_VERSION_1_3_check(
    of_bsn_pdu_rx_request_t *obj, int value);
extern int of_bsn_pdu_rx_request_OF_VERSION_1_3_populate_scalars(
    of_bsn_pdu_rx_request_t *obj, int value);
extern int of_bsn_pdu_rx_request_OF_VERSION_1_3_check_scalars(
    of_bsn_pdu_rx_request_t *obj, int value);

extern int of_bsn_pdu_rx_timeout_OF_VERSION_1_3_populate(
    of_bsn_pdu_rx_timeout_t *obj, int value);
extern int of_bsn_pdu_rx_timeout_OF_VERSION_1_3_check(
    of_bsn_pdu_rx_timeout_t *obj, int value);
extern int of_bsn_pdu_rx_timeout_OF_VERSION_1_3_populate_scalars(
    of_bsn_pdu_rx_timeout_t *obj, int value);
extern int of_bsn_pdu_rx_timeout_OF_VERSION_1_3_check_scalars(
    of_bsn_pdu_rx_timeout_t *obj, int value);

extern int of_bsn_pdu_tx_reply_OF_VERSION_1_3_populate(
    of_bsn_pdu_tx_reply_t *obj, int value);
extern int of_bsn_pdu_tx_reply_OF_VERSION_1_3_check(
    of_bsn_pdu_tx_reply_t *obj, int value);
extern int of_bsn_pdu_tx_reply_OF_VERSION_1_3_populate_scalars(
    of_bsn_pdu_tx_reply_t *obj, int value);
extern int of_bsn_pdu_tx_reply_OF_VERSION_1_3_check_scalars(
    of_bsn_pdu_tx_reply_t *obj, int value);

extern int of_bsn_pdu_tx_request_OF_VERSION_1_3_populate(
    of_bsn_pdu_tx_request_t *obj, int value);
extern int of_bsn_pdu_tx_request_OF_VERSION_1_3_check(
    of_bsn_pdu_tx_request_t *obj, int value);
extern int of_bsn_pdu_tx_request_OF_VERSION_1_3_populate_scalars(
    of_bsn_pdu_tx_request_t *obj, int value);
extern int of_bsn_pdu_tx_request_OF_VERSION_1_3_check_scalars(
    of_bsn_pdu_tx_request_t *obj, int value);

extern int of_bsn_port_counter_stats_reply_OF_VERSION_1_3_populate(
    of_bsn_port_counter_stats_reply_t *obj, int value);
extern int of_bsn_port_counter_stats_reply_OF_VERSION_1_3_check(
    of_bsn_port_counter_stats_reply_t *obj, int value);
extern int of_bsn_port_counter_stats_reply_OF_VERSION_1_3_populate_scalars(
    of_bsn_port_counter_stats_reply_t *obj, int value);
extern int of_bsn_port_counter_stats_reply_OF_VERSION_1_3_check_scalars(
    of_bsn_port_counter_stats_reply_t *obj, int value);

extern int of_bsn_port_counter_stats_request_OF_VERSION_1_3_populate(
    of_bsn_port_counter_stats_request_t *obj, int value);
extern int of_bsn_port_counter_stats_request_OF_VERSION_1_3_check(
    of_bsn_port_counter_stats_request_t *obj, int value);
extern int of_bsn_port_counter_stats_request_OF_VERSION_1_3_populate_scalars(
    of_bsn_port_counter_stats_request_t *obj, int value);
extern int of_bsn_port_counter_stats_request_OF_VERSION_1_3_check_scalars(
    of_bsn_port_counter_stats_request_t *obj, int value);

extern int of_bsn_role_status_OF_VERSION_1_3_populate(
    of_bsn_role_status_t *obj, int value);
extern int of_bsn_role_status_OF_VERSION_1_3_check(
    of_bsn_role_status_t *obj, int value);
extern int of_bsn_role_status_OF_VERSION_1_3_populate_scalars(
    of_bsn_role_status_t *obj, int value);
extern int of_bsn_role_status_OF_VERSION_1_3_check_scalars(
    of_bsn_role_status_t *obj, int value);

extern int of_bsn_set_aux_cxns_reply_OF_VERSION_1_3_populate(
    of_bsn_set_aux_cxns_reply_t *obj, int value);
extern int of_bsn_set_aux_cxns_reply_OF_VERSION_1_3_check(
    of_bsn_set_aux_cxns_reply_t *obj, int value);
extern int of_bsn_set_aux_cxns_reply_OF_VERSION_1_3_populate_scalars(
    of_bsn_set_aux_cxns_reply_t *obj, int value);
extern int of_bsn_set_aux_cxns_reply_OF_VERSION_1_3_check_scalars(
    of_bsn_set_aux_cxns_reply_t *obj, int value);

extern int of_bsn_set_aux_cxns_request_OF_VERSION_1_3_populate(
    of_bsn_set_aux_cxns_request_t *obj, int value);
extern int of_bsn_set_aux_cxns_request_OF_VERSION_1_3_check(
    of_bsn_set_aux_cxns_request_t *obj, int value);
extern int of_bsn_set_aux_cxns_request_OF_VERSION_1_3_populate_scalars(
    of_bsn_set_aux_cxns_request_t *obj, int value);
extern int of_bsn_set_aux_cxns_request_OF_VERSION_1_3_check_scalars(
    of_bsn_set_aux_cxns_request_t *obj, int value);

extern int of_bsn_set_lacp_reply_OF_VERSION_1_3_populate(
    of_bsn_set_lacp_reply_t *obj, int value);
extern int of_bsn_set_lacp_reply_OF_VERSION_1_3_check(
    of_bsn_set_lacp_reply_t *obj, int value);
extern int of_bsn_set_lacp_reply_OF_VERSION_1_3_populate_scalars(
    of_bsn_set_lacp_reply_t *obj, int value);
extern int of_bsn_set_lacp_reply_OF_VERSION_1_3_check_scalars(
    of_bsn_set_lacp_reply_t *obj, int value);

extern int of_bsn_set_lacp_request_OF_VERSION_1_3_populate(
    of_bsn_set_lacp_request_t *obj, int value);
extern int of_bsn_set_lacp_request_OF_VERSION_1_3_check(
    of_bsn_set_lacp_request_t *obj, int value);
extern int of_bsn_set_lacp_request_OF_VERSION_1_3_populate_scalars(
    of_bsn_set_lacp_request_t *obj, int value);
extern int of_bsn_set_lacp_request_OF_VERSION_1_3_check_scalars(
    of_bsn_set_lacp_request_t *obj, int value);

extern int of_bsn_set_mirroring_OF_VERSION_1_3_populate(
    of_bsn_set_mirroring_t *obj, int value);
extern int of_bsn_set_mirroring_OF_VERSION_1_3_check(
    of_bsn_set_mirroring_t *obj, int value);
extern int of_bsn_set_mirroring_OF_VERSION_1_3_populate_scalars(
    of_bsn_set_mirroring_t *obj, int value);
extern int of_bsn_set_mirroring_OF_VERSION_1_3_check_scalars(
    of_bsn_set_mirroring_t *obj, int value);

extern int of_bsn_set_pktin_suppression_reply_OF_VERSION_1_3_populate(
    of_bsn_set_pktin_suppression_reply_t *obj, int value);
extern int of_bsn_set_pktin_suppression_reply_OF_VERSION_1_3_check(
    of_bsn_set_pktin_suppression_reply_t *obj, int value);
extern int of_bsn_set_pktin_suppression_reply_OF_VERSION_1_3_populate_scalars(
    of_bsn_set_pktin_suppression_reply_t *obj, int value);
extern int of_bsn_set_pktin_suppression_reply_OF_VERSION_1_3_check_scalars(
    of_bsn_set_pktin_suppression_reply_t *obj, int value);

extern int of_bsn_set_pktin_suppression_request_OF_VERSION_1_3_populate(
    of_bsn_set_pktin_suppression_request_t *obj, int value);
extern int of_bsn_set_pktin_suppression_request_OF_VERSION_1_3_check(
    of_bsn_set_pktin_suppression_request_t *obj, int value);
extern int of_bsn_set_pktin_suppression_request_OF_VERSION_1_3_populate_scalars(
    of_bsn_set_pktin_suppression_request_t *obj, int value);
extern int of_bsn_set_pktin_suppression_request_OF_VERSION_1_3_check_scalars(
    of_bsn_set_pktin_suppression_request_t *obj, int value);

extern int of_bsn_set_switch_pipeline_reply_OF_VERSION_1_3_populate(
    of_bsn_set_switch_pipeline_reply_t *obj, int value);
extern int of_bsn_set_switch_pipeline_reply_OF_VERSION_1_3_check(
    of_bsn_set_switch_pipeline_reply_t *obj, int value);
extern int of_bsn_set_switch_pipeline_reply_OF_VERSION_1_3_populate_scalars(
    of_bsn_set_switch_pipeline_reply_t *obj, int value);
extern int of_bsn_set_switch_pipeline_reply_OF_VERSION_1_3_check_scalars(
    of_bsn_set_switch_pipeline_reply_t *obj, int value);

extern int of_bsn_set_switch_pipeline_request_OF_VERSION_1_3_populate(
    of_bsn_set_switch_pipeline_request_t *obj, int value);
extern int of_bsn_set_switch_pipeline_request_OF_VERSION_1_3_check(
    of_bsn_set_switch_pipeline_request_t *obj, int value);
extern int of_bsn_set_switch_pipeline_request_OF_VERSION_1_3_populate_scalars(
    of_bsn_set_switch_pipeline_request_t *obj, int value);
extern int of_bsn_set_switch_pipeline_request_OF_VERSION_1_3_check_scalars(
    of_bsn_set_switch_pipeline_request_t *obj, int value);

extern int of_bsn_switch_pipeline_stats_reply_OF_VERSION_1_3_populate(
    of_bsn_switch_pipeline_stats_reply_t *obj, int value);
extern int of_bsn_switch_pipeline_stats_reply_OF_VERSION_1_3_check(
    of_bsn_switch_pipeline_stats_reply_t *obj, int value);
extern int of_bsn_switch_pipeline_stats_reply_OF_VERSION_1_3_populate_scalars(
    of_bsn_switch_pipeline_stats_reply_t *obj, int value);
extern int of_bsn_switch_pipeline_stats_reply_OF_VERSION_1_3_check_scalars(
    of_bsn_switch_pipeline_stats_reply_t *obj, int value);

extern int of_bsn_switch_pipeline_stats_request_OF_VERSION_1_3_populate(
    of_bsn_switch_pipeline_stats_request_t *obj, int value);
extern int of_bsn_switch_pipeline_stats_request_OF_VERSION_1_3_check(
    of_bsn_switch_pipeline_stats_request_t *obj, int value);
extern int of_bsn_switch_pipeline_stats_request_OF_VERSION_1_3_populate_scalars(
    of_bsn_switch_pipeline_stats_request_t *obj, int value);
extern int of_bsn_switch_pipeline_stats_request_OF_VERSION_1_3_check_scalars(
    of_bsn_switch_pipeline_stats_request_t *obj, int value);

extern int of_bsn_table_checksum_stats_reply_OF_VERSION_1_3_populate(
    of_bsn_table_checksum_stats_reply_t *obj, int value);
extern int of_bsn_table_checksum_stats_reply_OF_VERSION_1_3_check(
    of_bsn_table_checksum_stats_reply_t *obj, int value);
extern int of_bsn_table_checksum_stats_reply_OF_VERSION_1_3_populate_scalars(
    of_bsn_table_checksum_stats_reply_t *obj, int value);
extern int of_bsn_table_checksum_stats_reply_OF_VERSION_1_3_check_scalars(
    of_bsn_table_checksum_stats_reply_t *obj, int value);

extern int of_bsn_table_checksum_stats_request_OF_VERSION_1_3_populate(
    of_bsn_table_checksum_stats_request_t *obj, int value);
extern int of_bsn_table_checksum_stats_request_OF_VERSION_1_3_check(
    of_bsn_table_checksum_stats_request_t *obj, int value);
extern int of_bsn_table_checksum_stats_request_OF_VERSION_1_3_populate_scalars(
    of_bsn_table_checksum_stats_request_t *obj, int value);
extern int of_bsn_table_checksum_stats_request_OF_VERSION_1_3_check_scalars(
    of_bsn_table_checksum_stats_request_t *obj, int value);

extern int of_bsn_table_set_buckets_size_OF_VERSION_1_3_populate(
    of_bsn_table_set_buckets_size_t *obj, int value);
extern int of_bsn_table_set_buckets_size_OF_VERSION_1_3_check(
    of_bsn_table_set_buckets_size_t *obj, int value);
extern int of_bsn_table_set_buckets_size_OF_VERSION_1_3_populate_scalars(
    of_bsn_table_set_buckets_size_t *obj, int value);
extern int of_bsn_table_set_buckets_size_OF_VERSION_1_3_check_scalars(
    of_bsn_table_set_buckets_size_t *obj, int value);

extern int of_bsn_time_reply_OF_VERSION_1_3_populate(
    of_bsn_time_reply_t *obj, int value);
extern int of_bsn_time_reply_OF_VERSION_1_3_check(
    of_bsn_time_reply_t *obj, int value);
extern int of_bsn_time_reply_OF_VERSION_1_3_populate_scalars(
    of_bsn_time_reply_t *obj, int value);
extern int of_bsn_time_reply_OF_VERSION_1_3_check_scalars(
    of_bsn_time_reply_t *obj, int value);

extern int of_bsn_time_request_OF_VERSION_1_3_populate(
    of_bsn_time_request_t *obj, int value);
extern int of_bsn_time_request_OF_VERSION_1_3_check(
    of_bsn_time_request_t *obj, int value);
extern int of_bsn_time_request_OF_VERSION_1_3_populate_scalars(
    of_bsn_time_request_t *obj, int value);
extern int of_bsn_time_request_OF_VERSION_1_3_check_scalars(
    of_bsn_time_request_t *obj, int value);

extern int of_bsn_virtual_port_create_reply_OF_VERSION_1_3_populate(
    of_bsn_virtual_port_create_reply_t *obj, int value);
extern int of_bsn_virtual_port_create_reply_OF_VERSION_1_3_check(
    of_bsn_virtual_port_create_reply_t *obj, int value);
extern int of_bsn_virtual_port_create_reply_OF_VERSION_1_3_populate_scalars(
    of_bsn_virtual_port_create_reply_t *obj, int value);
extern int of_bsn_virtual_port_create_reply_OF_VERSION_1_3_check_scalars(
    of_bsn_virtual_port_create_reply_t *obj, int value);

extern int of_bsn_virtual_port_create_request_OF_VERSION_1_3_populate(
    of_bsn_virtual_port_create_request_t *obj, int value);
extern int of_bsn_virtual_port_create_request_OF_VERSION_1_3_check(
    of_bsn_virtual_port_create_request_t *obj, int value);
extern int of_bsn_virtual_port_create_request_OF_VERSION_1_3_populate_scalars(
    of_bsn_virtual_port_create_request_t *obj, int value);
extern int of_bsn_virtual_port_create_request_OF_VERSION_1_3_check_scalars(
    of_bsn_virtual_port_create_request_t *obj, int value);

extern int of_bsn_virtual_port_remove_reply_OF_VERSION_1_3_populate(
    of_bsn_virtual_port_remove_reply_t *obj, int value);
extern int of_bsn_virtual_port_remove_reply_OF_VERSION_1_3_check(
    of_bsn_virtual_port_remove_reply_t *obj, int value);
extern int of_bsn_virtual_port_remove_reply_OF_VERSION_1_3_populate_scalars(
    of_bsn_virtual_port_remove_reply_t *obj, int value);
extern int of_bsn_virtual_port_remove_reply_OF_VERSION_1_3_check_scalars(
    of_bsn_virtual_port_remove_reply_t *obj, int value);

extern int of_bsn_virtual_port_remove_request_OF_VERSION_1_3_populate(
    of_bsn_virtual_port_remove_request_t *obj, int value);
extern int of_bsn_virtual_port_remove_request_OF_VERSION_1_3_check(
    of_bsn_virtual_port_remove_request_t *obj, int value);
extern int of_bsn_virtual_port_remove_request_OF_VERSION_1_3_populate_scalars(
    of_bsn_virtual_port_remove_request_t *obj, int value);
extern int of_bsn_virtual_port_remove_request_OF_VERSION_1_3_check_scalars(
    of_bsn_virtual_port_remove_request_t *obj, int value);

extern int of_bsn_vlan_counter_clear_OF_VERSION_1_3_populate(
    of_bsn_vlan_counter_clear_t *obj, int value);
extern int of_bsn_vlan_counter_clear_OF_VERSION_1_3_check(
    of_bsn_vlan_counter_clear_t *obj, int value);
extern int of_bsn_vlan_counter_clear_OF_VERSION_1_3_populate_scalars(
    of_bsn_vlan_counter_clear_t *obj, int value);
extern int of_bsn_vlan_counter_clear_OF_VERSION_1_3_check_scalars(
    of_bsn_vlan_counter_clear_t *obj, int value);

extern int of_bsn_vlan_counter_stats_reply_OF_VERSION_1_3_populate(
    of_bsn_vlan_counter_stats_reply_t *obj, int value);
extern int of_bsn_vlan_counter_stats_reply_OF_VERSION_1_3_check(
    of_bsn_vlan_counter_stats_reply_t *obj, int value);
extern int of_bsn_vlan_counter_stats_reply_OF_VERSION_1_3_populate_scalars(
    of_bsn_vlan_counter_stats_reply_t *obj, int value);
extern int of_bsn_vlan_counter_stats_reply_OF_VERSION_1_3_check_scalars(
    of_bsn_vlan_counter_stats_reply_t *obj, int value);

extern int of_bsn_vlan_counter_stats_request_OF_VERSION_1_3_populate(
    of_bsn_vlan_counter_stats_request_t *obj, int value);
extern int of_bsn_vlan_counter_stats_request_OF_VERSION_1_3_check(
    of_bsn_vlan_counter_stats_request_t *obj, int value);
extern int of_bsn_vlan_counter_stats_request_OF_VERSION_1_3_populate_scalars(
    of_bsn_vlan_counter_stats_request_t *obj, int value);
extern int of_bsn_vlan_counter_stats_request_OF_VERSION_1_3_check_scalars(
    of_bsn_vlan_counter_stats_request_t *obj, int value);

extern int of_bsn_vrf_counter_stats_reply_OF_VERSION_1_3_populate(
    of_bsn_vrf_counter_stats_reply_t *obj, int value);
extern int of_bsn_vrf_counter_stats_reply_OF_VERSION_1_3_check(
    of_bsn_vrf_counter_stats_reply_t *obj, int value);
extern int of_bsn_vrf_counter_stats_reply_OF_VERSION_1_3_populate_scalars(
    of_bsn_vrf_counter_stats_reply_t *obj, int value);
extern int of_bsn_vrf_counter_stats_reply_OF_VERSION_1_3_check_scalars(
    of_bsn_vrf_counter_stats_reply_t *obj, int value);

extern int of_bsn_vrf_counter_stats_request_OF_VERSION_1_3_populate(
    of_bsn_vrf_counter_stats_request_t *obj, int value);
extern int of_bsn_vrf_counter_stats_request_OF_VERSION_1_3_check(
    of_bsn_vrf_counter_stats_request_t *obj, int value);
extern int of_bsn_vrf_counter_stats_request_OF_VERSION_1_3_populate_scalars(
    of_bsn_vrf_counter_stats_request_t *obj, int value);
extern int of_bsn_vrf_counter_stats_request_OF_VERSION_1_3_check_scalars(
    of_bsn_vrf_counter_stats_request_t *obj, int value);

extern int of_desc_stats_reply_OF_VERSION_1_3_populate(
    of_desc_stats_reply_t *obj, int value);
extern int of_desc_stats_reply_OF_VERSION_1_3_check(
    of_desc_stats_reply_t *obj, int value);
extern int of_desc_stats_reply_OF_VERSION_1_3_populate_scalars(
    of_desc_stats_reply_t *obj, int value);
extern int of_desc_stats_reply_OF_VERSION_1_3_check_scalars(
    of_desc_stats_reply_t *obj, int value);

extern int of_desc_stats_request_OF_VERSION_1_3_populate(
    of_desc_stats_request_t *obj, int value);
extern int of_desc_stats_request_OF_VERSION_1_3_check(
    of_desc_stats_request_t *obj, int value);
extern int of_desc_stats_request_OF_VERSION_1_3_populate_scalars(
    of_desc_stats_request_t *obj, int value);
extern int of_desc_stats_request_OF_VERSION_1_3_check_scalars(
    of_desc_stats_request_t *obj, int value);

extern int of_echo_reply_OF_VERSION_1_3_populate(
    of_echo_reply_t *obj, int value);
extern int of_echo_reply_OF_VERSION_1_3_check(
    of_echo_reply_t *obj, int value);
extern int of_echo_reply_OF_VERSION_1_3_populate_scalars(
    of_echo_reply_t *obj, int value);
extern int of_echo_reply_OF_VERSION_1_3_check_scalars(
    of_echo_reply_t *obj, int value);

extern int of_echo_request_OF_VERSION_1_3_populate(
    of_echo_request_t *obj, int value);
extern int of_echo_request_OF_VERSION_1_3_check(
    of_echo_request_t *obj, int value);
extern int of_echo_request_OF_VERSION_1_3_populate_scalars(
    of_echo_request_t *obj, int value);
extern int of_echo_request_OF_VERSION_1_3_check_scalars(
    of_echo_request_t *obj, int value);

extern int of_features_reply_OF_VERSION_1_3_populate(
    of_features_reply_t *obj, int value);
extern int of_features_reply_OF_VERSION_1_3_check(
    of_features_reply_t *obj, int value);
extern int of_features_reply_OF_VERSION_1_3_populate_scalars(
    of_features_reply_t *obj, int value);
extern int of_features_reply_OF_VERSION_1_3_check_scalars(
    of_features_reply_t *obj, int value);

extern int of_features_request_OF_VERSION_1_3_populate(
    of_features_request_t *obj, int value);
extern int of_features_request_OF_VERSION_1_3_check(
    of_features_request_t *obj, int value);
extern int of_features_request_OF_VERSION_1_3_populate_scalars(
    of_features_request_t *obj, int value);
extern int of_features_request_OF_VERSION_1_3_check_scalars(
    of_features_request_t *obj, int value);

extern int of_flow_add_OF_VERSION_1_3_populate(
    of_flow_add_t *obj, int value);
extern int of_flow_add_OF_VERSION_1_3_check(
    of_flow_add_t *obj, int value);
extern int of_flow_add_OF_VERSION_1_3_populate_scalars(
    of_flow_add_t *obj, int value);
extern int of_flow_add_OF_VERSION_1_3_check_scalars(
    of_flow_add_t *obj, int value);

extern int of_flow_delete_OF_VERSION_1_3_populate(
    of_flow_delete_t *obj, int value);
extern int of_flow_delete_OF_VERSION_1_3_check(
    of_flow_delete_t *obj, int value);
extern int of_flow_delete_OF_VERSION_1_3_populate_scalars(
    of_flow_delete_t *obj, int value);
extern int of_flow_delete_OF_VERSION_1_3_check_scalars(
    of_flow_delete_t *obj, int value);

extern int of_flow_delete_strict_OF_VERSION_1_3_populate(
    of_flow_delete_strict_t *obj, int value);
extern int of_flow_delete_strict_OF_VERSION_1_3_check(
    of_flow_delete_strict_t *obj, int value);
extern int of_flow_delete_strict_OF_VERSION_1_3_populate_scalars(
    of_flow_delete_strict_t *obj, int value);
extern int of_flow_delete_strict_OF_VERSION_1_3_check_scalars(
    of_flow_delete_strict_t *obj, int value);

extern int of_flow_mod_failed_error_msg_OF_VERSION_1_3_populate(
    of_flow_mod_failed_error_msg_t *obj, int value);
extern int of_flow_mod_failed_error_msg_OF_VERSION_1_3_check(
    of_flow_mod_failed_error_msg_t *obj, int value);
extern int of_flow_mod_failed_error_msg_OF_VERSION_1_3_populate_scalars(
    of_flow_mod_failed_error_msg_t *obj, int value);
extern int of_flow_mod_failed_error_msg_OF_VERSION_1_3_check_scalars(
    of_flow_mod_failed_error_msg_t *obj, int value);

extern int of_flow_modify_OF_VERSION_1_3_populate(
    of_flow_modify_t *obj, int value);
extern int of_flow_modify_OF_VERSION_1_3_check(
    of_flow_modify_t *obj, int value);
extern int of_flow_modify_OF_VERSION_1_3_populate_scalars(
    of_flow_modify_t *obj, int value);
extern int of_flow_modify_OF_VERSION_1_3_check_scalars(
    of_flow_modify_t *obj, int value);

extern int of_flow_modify_strict_OF_VERSION_1_3_populate(
    of_flow_modify_strict_t *obj, int value);
extern int of_flow_modify_strict_OF_VERSION_1_3_check(
    of_flow_modify_strict_t *obj, int value);
extern int of_flow_modify_strict_OF_VERSION_1_3_populate_scalars(
    of_flow_modify_strict_t *obj, int value);
extern int of_flow_modify_strict_OF_VERSION_1_3_check_scalars(
    of_flow_modify_strict_t *obj, int value);

extern int of_flow_removed_OF_VERSION_1_3_populate(
    of_flow_removed_t *obj, int value);
extern int of_flow_removed_OF_VERSION_1_3_check(
    of_flow_removed_t *obj, int value);
extern int of_flow_removed_OF_VERSION_1_3_populate_scalars(
    of_flow_removed_t *obj, int value);
extern int of_flow_removed_OF_VERSION_1_3_check_scalars(
    of_flow_removed_t *obj, int value);

extern int of_flow_stats_reply_OF_VERSION_1_3_populate(
    of_flow_stats_reply_t *obj, int value);
extern int of_flow_stats_reply_OF_VERSION_1_3_check(
    of_flow_stats_reply_t *obj, int value);
extern int of_flow_stats_reply_OF_VERSION_1_3_populate_scalars(
    of_flow_stats_reply_t *obj, int value);
extern int of_flow_stats_reply_OF_VERSION_1_3_check_scalars(
    of_flow_stats_reply_t *obj, int value);

extern int of_flow_stats_request_OF_VERSION_1_3_populate(
    of_flow_stats_request_t *obj, int value);
extern int of_flow_stats_request_OF_VERSION_1_3_check(
    of_flow_stats_request_t *obj, int value);
extern int of_flow_stats_request_OF_VERSION_1_3_populate_scalars(
    of_flow_stats_request_t *obj, int value);
extern int of_flow_stats_request_OF_VERSION_1_3_check_scalars(
    of_flow_stats_request_t *obj, int value);

extern int of_get_config_reply_OF_VERSION_1_3_populate(
    of_get_config_reply_t *obj, int value);
extern int of_get_config_reply_OF_VERSION_1_3_check(
    of_get_config_reply_t *obj, int value);
extern int of_get_config_reply_OF_VERSION_1_3_populate_scalars(
    of_get_config_reply_t *obj, int value);
extern int of_get_config_reply_OF_VERSION_1_3_check_scalars(
    of_get_config_reply_t *obj, int value);

extern int of_get_config_request_OF_VERSION_1_3_populate(
    of_get_config_request_t *obj, int value);
extern int of_get_config_request_OF_VERSION_1_3_check(
    of_get_config_request_t *obj, int value);
extern int of_get_config_request_OF_VERSION_1_3_populate_scalars(
    of_get_config_request_t *obj, int value);
extern int of_get_config_request_OF_VERSION_1_3_check_scalars(
    of_get_config_request_t *obj, int value);

extern int of_group_add_OF_VERSION_1_3_populate(
    of_group_add_t *obj, int value);
extern int of_group_add_OF_VERSION_1_3_check(
    of_group_add_t *obj, int value);
extern int of_group_add_OF_VERSION_1_3_populate_scalars(
    of_group_add_t *obj, int value);
extern int of_group_add_OF_VERSION_1_3_check_scalars(
    of_group_add_t *obj, int value);

extern int of_group_delete_OF_VERSION_1_3_populate(
    of_group_delete_t *obj, int value);
extern int of_group_delete_OF_VERSION_1_3_check(
    of_group_delete_t *obj, int value);
extern int of_group_delete_OF_VERSION_1_3_populate_scalars(
    of_group_delete_t *obj, int value);
extern int of_group_delete_OF_VERSION_1_3_check_scalars(
    of_group_delete_t *obj, int value);

extern int of_group_desc_stats_reply_OF_VERSION_1_3_populate(
    of_group_desc_stats_reply_t *obj, int value);
extern int of_group_desc_stats_reply_OF_VERSION_1_3_check(
    of_group_desc_stats_reply_t *obj, int value);
extern int of_group_desc_stats_reply_OF_VERSION_1_3_populate_scalars(
    of_group_desc_stats_reply_t *obj, int value);
extern int of_group_desc_stats_reply_OF_VERSION_1_3_check_scalars(
    of_group_desc_stats_reply_t *obj, int value);

extern int of_group_desc_stats_request_OF_VERSION_1_3_populate(
    of_group_desc_stats_request_t *obj, int value);
extern int of_group_desc_stats_request_OF_VERSION_1_3_check(
    of_group_desc_stats_request_t *obj, int value);
extern int of_group_desc_stats_request_OF_VERSION_1_3_populate_scalars(
    of_group_desc_stats_request_t *obj, int value);
extern int of_group_desc_stats_request_OF_VERSION_1_3_check_scalars(
    of_group_desc_stats_request_t *obj, int value);

extern int of_group_features_stats_reply_OF_VERSION_1_3_populate(
    of_group_features_stats_reply_t *obj, int value);
extern int of_group_features_stats_reply_OF_VERSION_1_3_check(
    of_group_features_stats_reply_t *obj, int value);
extern int of_group_features_stats_reply_OF_VERSION_1_3_populate_scalars(
    of_group_features_stats_reply_t *obj, int value);
extern int of_group_features_stats_reply_OF_VERSION_1_3_check_scalars(
    of_group_features_stats_reply_t *obj, int value);

extern int of_group_features_stats_request_OF_VERSION_1_3_populate(
    of_group_features_stats_request_t *obj, int value);
extern int of_group_features_stats_request_OF_VERSION_1_3_check(
    of_group_features_stats_request_t *obj, int value);
extern int of_group_features_stats_request_OF_VERSION_1_3_populate_scalars(
    of_group_features_stats_request_t *obj, int value);
extern int of_group_features_stats_request_OF_VERSION_1_3_check_scalars(
    of_group_features_stats_request_t *obj, int value);

extern int of_group_mod_failed_error_msg_OF_VERSION_1_3_populate(
    of_group_mod_failed_error_msg_t *obj, int value);
extern int of_group_mod_failed_error_msg_OF_VERSION_1_3_check(
    of_group_mod_failed_error_msg_t *obj, int value);
extern int of_group_mod_failed_error_msg_OF_VERSION_1_3_populate_scalars(
    of_group_mod_failed_error_msg_t *obj, int value);
extern int of_group_mod_failed_error_msg_OF_VERSION_1_3_check_scalars(
    of_group_mod_failed_error_msg_t *obj, int value);

extern int of_group_modify_OF_VERSION_1_3_populate(
    of_group_modify_t *obj, int value);
extern int of_group_modify_OF_VERSION_1_3_check(
    of_group_modify_t *obj, int value);
extern int of_group_modify_OF_VERSION_1_3_populate_scalars(
    of_group_modify_t *obj, int value);
extern int of_group_modify_OF_VERSION_1_3_check_scalars(
    of_group_modify_t *obj, int value);

extern int of_group_stats_reply_OF_VERSION_1_3_populate(
    of_group_stats_reply_t *obj, int value);
extern int of_group_stats_reply_OF_VERSION_1_3_check(
    of_group_stats_reply_t *obj, int value);
extern int of_group_stats_reply_OF_VERSION_1_3_populate_scalars(
    of_group_stats_reply_t *obj, int value);
extern int of_group_stats_reply_OF_VERSION_1_3_check_scalars(
    of_group_stats_reply_t *obj, int value);

extern int of_group_stats_request_OF_VERSION_1_3_populate(
    of_group_stats_request_t *obj, int value);
extern int of_group_stats_request_OF_VERSION_1_3_check(
    of_group_stats_request_t *obj, int value);
extern int of_group_stats_request_OF_VERSION_1_3_populate_scalars(
    of_group_stats_request_t *obj, int value);
extern int of_group_stats_request_OF_VERSION_1_3_check_scalars(
    of_group_stats_request_t *obj, int value);

extern int of_hello_OF_VERSION_1_3_populate(
    of_hello_t *obj, int value);
extern int of_hello_OF_VERSION_1_3_check(
    of_hello_t *obj, int value);
extern int of_hello_OF_VERSION_1_3_populate_scalars(
    of_hello_t *obj, int value);
extern int of_hello_OF_VERSION_1_3_check_scalars(
    of_hello_t *obj, int value);

extern int of_hello_failed_error_msg_OF_VERSION_1_3_populate(
    of_hello_failed_error_msg_t *obj, int value);
extern int of_hello_failed_error_msg_OF_VERSION_1_3_check(
    of_hello_failed_error_msg_t *obj, int value);
extern int of_hello_failed_error_msg_OF_VERSION_1_3_populate_scalars(
    of_hello_failed_error_msg_t *obj, int value);
extern int of_hello_failed_error_msg_OF_VERSION_1_3_check_scalars(
    of_hello_failed_error_msg_t *obj, int value);

extern int of_meter_config_stats_reply_OF_VERSION_1_3_populate(
    of_meter_config_stats_reply_t *obj, int value);
extern int of_meter_config_stats_reply_OF_VERSION_1_3_check(
    of_meter_config_stats_reply_t *obj, int value);
extern int of_meter_config_stats_reply_OF_VERSION_1_3_populate_scalars(
    of_meter_config_stats_reply_t *obj, int value);
extern int of_meter_config_stats_reply_OF_VERSION_1_3_check_scalars(
    of_meter_config_stats_reply_t *obj, int value);

extern int of_meter_config_stats_request_OF_VERSION_1_3_populate(
    of_meter_config_stats_request_t *obj, int value);
extern int of_meter_config_stats_request_OF_VERSION_1_3_check(
    of_meter_config_stats_request_t *obj, int value);
extern int of_meter_config_stats_request_OF_VERSION_1_3_populate_scalars(
    of_meter_config_stats_request_t *obj, int value);
extern int of_meter_config_stats_request_OF_VERSION_1_3_check_scalars(
    of_meter_config_stats_request_t *obj, int value);

extern int of_meter_features_stats_reply_OF_VERSION_1_3_populate(
    of_meter_features_stats_reply_t *obj, int value);
extern int of_meter_features_stats_reply_OF_VERSION_1_3_check(
    of_meter_features_stats_reply_t *obj, int value);
extern int of_meter_features_stats_reply_OF_VERSION_1_3_populate_scalars(
    of_meter_features_stats_reply_t *obj, int value);
extern int of_meter_features_stats_reply_OF_VERSION_1_3_check_scalars(
    of_meter_features_stats_reply_t *obj, int value);

extern int of_meter_features_stats_request_OF_VERSION_1_3_populate(
    of_meter_features_stats_request_t *obj, int value);
extern int of_meter_features_stats_request_OF_VERSION_1_3_check(
    of_meter_features_stats_request_t *obj, int value);
extern int of_meter_features_stats_request_OF_VERSION_1_3_populate_scalars(
    of_meter_features_stats_request_t *obj, int value);
extern int of_meter_features_stats_request_OF_VERSION_1_3_check_scalars(
    of_meter_features_stats_request_t *obj, int value);

extern int of_meter_mod_OF_VERSION_1_3_populate(
    of_meter_mod_t *obj, int value);
extern int of_meter_mod_OF_VERSION_1_3_check(
    of_meter_mod_t *obj, int value);
extern int of_meter_mod_OF_VERSION_1_3_populate_scalars(
    of_meter_mod_t *obj, int value);
extern int of_meter_mod_OF_VERSION_1_3_check_scalars(
    of_meter_mod_t *obj, int value);

extern int of_meter_mod_failed_error_msg_OF_VERSION_1_3_populate(
    of_meter_mod_failed_error_msg_t *obj, int value);
extern int of_meter_mod_failed_error_msg_OF_VERSION_1_3_check(
    of_meter_mod_failed_error_msg_t *obj, int value);
extern int of_meter_mod_failed_error_msg_OF_VERSION_1_3_populate_scalars(
    of_meter_mod_failed_error_msg_t *obj, int value);
extern int of_meter_mod_failed_error_msg_OF_VERSION_1_3_check_scalars(
    of_meter_mod_failed_error_msg_t *obj, int value);

extern int of_meter_stats_reply_OF_VERSION_1_3_populate(
    of_meter_stats_reply_t *obj, int value);
extern int of_meter_stats_reply_OF_VERSION_1_3_check(
    of_meter_stats_reply_t *obj, int value);
extern int of_meter_stats_reply_OF_VERSION_1_3_populate_scalars(
    of_meter_stats_reply_t *obj, int value);
extern int of_meter_stats_reply_OF_VERSION_1_3_check_scalars(
    of_meter_stats_reply_t *obj, int value);

extern int of_meter_stats_request_OF_VERSION_1_3_populate(
    of_meter_stats_request_t *obj, int value);
extern int of_meter_stats_request_OF_VERSION_1_3_check(
    of_meter_stats_request_t *obj, int value);
extern int of_meter_stats_request_OF_VERSION_1_3_populate_scalars(
    of_meter_stats_request_t *obj, int value);
extern int of_meter_stats_request_OF_VERSION_1_3_check_scalars(
    of_meter_stats_request_t *obj, int value);

extern int of_packet_in_OF_VERSION_1_3_populate(
    of_packet_in_t *obj, int value);
extern int of_packet_in_OF_VERSION_1_3_check(
    of_packet_in_t *obj, int value);
extern int of_packet_in_OF_VERSION_1_3_populate_scalars(
    of_packet_in_t *obj, int value);
extern int of_packet_in_OF_VERSION_1_3_check_scalars(
    of_packet_in_t *obj, int value);

extern int of_packet_out_OF_VERSION_1_3_populate(
    of_packet_out_t *obj, int value);
extern int of_packet_out_OF_VERSION_1_3_check(
    of_packet_out_t *obj, int value);
extern int of_packet_out_OF_VERSION_1_3_populate_scalars(
    of_packet_out_t *obj, int value);
extern int of_packet_out_OF_VERSION_1_3_check_scalars(
    of_packet_out_t *obj, int value);

extern int of_port_desc_stats_reply_OF_VERSION_1_3_populate(
    of_port_desc_stats_reply_t *obj, int value);
extern int of_port_desc_stats_reply_OF_VERSION_1_3_check(
    of_port_desc_stats_reply_t *obj, int value);
extern int of_port_desc_stats_reply_OF_VERSION_1_3_populate_scalars(
    of_port_desc_stats_reply_t *obj, int value);
extern int of_port_desc_stats_reply_OF_VERSION_1_3_check_scalars(
    of_port_desc_stats_reply_t *obj, int value);

extern int of_port_desc_stats_request_OF_VERSION_1_3_populate(
    of_port_desc_stats_request_t *obj, int value);
extern int of_port_desc_stats_request_OF_VERSION_1_3_check(
    of_port_desc_stats_request_t *obj, int value);
extern int of_port_desc_stats_request_OF_VERSION_1_3_populate_scalars(
    of_port_desc_stats_request_t *obj, int value);
extern int of_port_desc_stats_request_OF_VERSION_1_3_check_scalars(
    of_port_desc_stats_request_t *obj, int value);

extern int of_port_mod_OF_VERSION_1_3_populate(
    of_port_mod_t *obj, int value);
extern int of_port_mod_OF_VERSION_1_3_check(
    of_port_mod_t *obj, int value);
extern int of_port_mod_OF_VERSION_1_3_populate_scalars(
    of_port_mod_t *obj, int value);
extern int of_port_mod_OF_VERSION_1_3_check_scalars(
    of_port_mod_t *obj, int value);

extern int of_port_mod_failed_error_msg_OF_VERSION_1_3_populate(
    of_port_mod_failed_error_msg_t *obj, int value);
extern int of_port_mod_failed_error_msg_OF_VERSION_1_3_check(
    of_port_mod_failed_error_msg_t *obj, int value);
extern int of_port_mod_failed_error_msg_OF_VERSION_1_3_populate_scalars(
    of_port_mod_failed_error_msg_t *obj, int value);
extern int of_port_mod_failed_error_msg_OF_VERSION_1_3_check_scalars(
    of_port_mod_failed_error_msg_t *obj, int value);

extern int of_port_stats_reply_OF_VERSION_1_3_populate(
    of_port_stats_reply_t *obj, int value);
extern int of_port_stats_reply_OF_VERSION_1_3_check(
    of_port_stats_reply_t *obj, int value);
extern int of_port_stats_reply_OF_VERSION_1_3_populate_scalars(
    of_port_stats_reply_t *obj, int value);
extern int of_port_stats_reply_OF_VERSION_1_3_check_scalars(
    of_port_stats_reply_t *obj, int value);

extern int of_port_stats_request_OF_VERSION_1_3_populate(
    of_port_stats_request_t *obj, int value);
extern int of_port_stats_request_OF_VERSION_1_3_check(
    of_port_stats_request_t *obj, int value);
extern int of_port_stats_request_OF_VERSION_1_3_populate_scalars(
    of_port_stats_request_t *obj, int value);
extern int of_port_stats_request_OF_VERSION_1_3_check_scalars(
    of_port_stats_request_t *obj, int value);

extern int of_port_status_OF_VERSION_1_3_populate(
    of_port_status_t *obj, int value);
extern int of_port_status_OF_VERSION_1_3_check(
    of_port_status_t *obj, int value);
extern int of_port_status_OF_VERSION_1_3_populate_scalars(
    of_port_status_t *obj, int value);
extern int of_port_status_OF_VERSION_1_3_check_scalars(
    of_port_status_t *obj, int value);

extern int of_queue_get_config_reply_OF_VERSION_1_3_populate(
    of_queue_get_config_reply_t *obj, int value);
extern int of_queue_get_config_reply_OF_VERSION_1_3_check(
    of_queue_get_config_reply_t *obj, int value);
extern int of_queue_get_config_reply_OF_VERSION_1_3_populate_scalars(
    of_queue_get_config_reply_t *obj, int value);
extern int of_queue_get_config_reply_OF_VERSION_1_3_check_scalars(
    of_queue_get_config_reply_t *obj, int value);

extern int of_queue_get_config_request_OF_VERSION_1_3_populate(
    of_queue_get_config_request_t *obj, int value);
extern int of_queue_get_config_request_OF_VERSION_1_3_check(
    of_queue_get_config_request_t *obj, int value);
extern int of_queue_get_config_request_OF_VERSION_1_3_populate_scalars(
    of_queue_get_config_request_t *obj, int value);
extern int of_queue_get_config_request_OF_VERSION_1_3_check_scalars(
    of_queue_get_config_request_t *obj, int value);

extern int of_queue_op_failed_error_msg_OF_VERSION_1_3_populate(
    of_queue_op_failed_error_msg_t *obj, int value);
extern int of_queue_op_failed_error_msg_OF_VERSION_1_3_check(
    of_queue_op_failed_error_msg_t *obj, int value);
extern int of_queue_op_failed_error_msg_OF_VERSION_1_3_populate_scalars(
    of_queue_op_failed_error_msg_t *obj, int value);
extern int of_queue_op_failed_error_msg_OF_VERSION_1_3_check_scalars(
    of_queue_op_failed_error_msg_t *obj, int value);

extern int of_queue_stats_reply_OF_VERSION_1_3_populate(
    of_queue_stats_reply_t *obj, int value);
extern int of_queue_stats_reply_OF_VERSION_1_3_check(
    of_queue_stats_reply_t *obj, int value);
extern int of_queue_stats_reply_OF_VERSION_1_3_populate_scalars(
    of_queue_stats_reply_t *obj, int value);
extern int of_queue_stats_reply_OF_VERSION_1_3_check_scalars(
    of_queue_stats_reply_t *obj, int value);

extern int of_queue_stats_request_OF_VERSION_1_3_populate(
    of_queue_stats_request_t *obj, int value);
extern int of_queue_stats_request_OF_VERSION_1_3_check(
    of_queue_stats_request_t *obj, int value);
extern int of_queue_stats_request_OF_VERSION_1_3_populate_scalars(
    of_queue_stats_request_t *obj, int value);
extern int of_queue_stats_request_OF_VERSION_1_3_check_scalars(
    of_queue_stats_request_t *obj, int value);

extern int of_role_reply_OF_VERSION_1_3_populate(
    of_role_reply_t *obj, int value);
extern int of_role_reply_OF_VERSION_1_3_check(
    of_role_reply_t *obj, int value);
extern int of_role_reply_OF_VERSION_1_3_populate_scalars(
    of_role_reply_t *obj, int value);
extern int of_role_reply_OF_VERSION_1_3_check_scalars(
    of_role_reply_t *obj, int value);

extern int of_role_request_OF_VERSION_1_3_populate(
    of_role_request_t *obj, int value);
extern int of_role_request_OF_VERSION_1_3_check(
    of_role_request_t *obj, int value);
extern int of_role_request_OF_VERSION_1_3_populate_scalars(
    of_role_request_t *obj, int value);
extern int of_role_request_OF_VERSION_1_3_check_scalars(
    of_role_request_t *obj, int value);

extern int of_role_request_failed_error_msg_OF_VERSION_1_3_populate(
    of_role_request_failed_error_msg_t *obj, int value);
extern int of_role_request_failed_error_msg_OF_VERSION_1_3_check(
    of_role_request_failed_error_msg_t *obj, int value);
extern int of_role_request_failed_error_msg_OF_VERSION_1_3_populate_scalars(
    of_role_request_failed_error_msg_t *obj, int value);
extern int of_role_request_failed_error_msg_OF_VERSION_1_3_check_scalars(
    of_role_request_failed_error_msg_t *obj, int value);

extern int of_set_config_OF_VERSION_1_3_populate(
    of_set_config_t *obj, int value);
extern int of_set_config_OF_VERSION_1_3_check(
    of_set_config_t *obj, int value);
extern int of_set_config_OF_VERSION_1_3_populate_scalars(
    of_set_config_t *obj, int value);
extern int of_set_config_OF_VERSION_1_3_check_scalars(
    of_set_config_t *obj, int value);

extern int of_switch_config_failed_error_msg_OF_VERSION_1_3_populate(
    of_switch_config_failed_error_msg_t *obj, int value);
extern int of_switch_config_failed_error_msg_OF_VERSION_1_3_check(
    of_switch_config_failed_error_msg_t *obj, int value);
extern int of_switch_config_failed_error_msg_OF_VERSION_1_3_populate_scalars(
    of_switch_config_failed_error_msg_t *obj, int value);
extern int of_switch_config_failed_error_msg_OF_VERSION_1_3_check_scalars(
    of_switch_config_failed_error_msg_t *obj, int value);

extern int of_table_features_failed_error_msg_OF_VERSION_1_3_populate(
    of_table_features_failed_error_msg_t *obj, int value);
extern int of_table_features_failed_error_msg_OF_VERSION_1_3_check(
    of_table_features_failed_error_msg_t *obj, int value);
extern int of_table_features_failed_error_msg_OF_VERSION_1_3_populate_scalars(
    of_table_features_failed_error_msg_t *obj, int value);
extern int of_table_features_failed_error_msg_OF_VERSION_1_3_check_scalars(
    of_table_features_failed_error_msg_t *obj, int value);

extern int of_table_features_stats_reply_OF_VERSION_1_3_populate(
    of_table_features_stats_reply_t *obj, int value);
extern int of_table_features_stats_reply_OF_VERSION_1_3_check(
    of_table_features_stats_reply_t *obj, int value);
extern int of_table_features_stats_reply_OF_VERSION_1_3_populate_scalars(
    of_table_features_stats_reply_t *obj, int value);
extern int of_table_features_stats_reply_OF_VERSION_1_3_check_scalars(
    of_table_features_stats_reply_t *obj, int value);

extern int of_table_features_stats_request_OF_VERSION_1_3_populate(
    of_table_features_stats_request_t *obj, int value);
extern int of_table_features_stats_request_OF_VERSION_1_3_check(
    of_table_features_stats_request_t *obj, int value);
extern int of_table_features_stats_request_OF_VERSION_1_3_populate_scalars(
    of_table_features_stats_request_t *obj, int value);
extern int of_table_features_stats_request_OF_VERSION_1_3_check_scalars(
    of_table_features_stats_request_t *obj, int value);

extern int of_table_mod_OF_VERSION_1_3_populate(
    of_table_mod_t *obj, int value);
extern int of_table_mod_OF_VERSION_1_3_check(
    of_table_mod_t *obj, int value);
extern int of_table_mod_OF_VERSION_1_3_populate_scalars(
    of_table_mod_t *obj, int value);
extern int of_table_mod_OF_VERSION_1_3_check_scalars(
    of_table_mod_t *obj, int value);

extern int of_table_mod_failed_error_msg_OF_VERSION_1_3_populate(
    of_table_mod_failed_error_msg_t *obj, int value);
extern int of_table_mod_failed_error_msg_OF_VERSION_1_3_check(
    of_table_mod_failed_error_msg_t *obj, int value);
extern int of_table_mod_failed_error_msg_OF_VERSION_1_3_populate_scalars(
    of_table_mod_failed_error_msg_t *obj, int value);
extern int of_table_mod_failed_error_msg_OF_VERSION_1_3_check_scalars(
    of_table_mod_failed_error_msg_t *obj, int value);

extern int of_table_stats_reply_OF_VERSION_1_3_populate(
    of_table_stats_reply_t *obj, int value);
extern int of_table_stats_reply_OF_VERSION_1_3_check(
    of_table_stats_reply_t *obj, int value);
extern int of_table_stats_reply_OF_VERSION_1_3_populate_scalars(
    of_table_stats_reply_t *obj, int value);
extern int of_table_stats_reply_OF_VERSION_1_3_check_scalars(
    of_table_stats_reply_t *obj, int value);

extern int of_table_stats_request_OF_VERSION_1_3_populate(
    of_table_stats_request_t *obj, int value);
extern int of_table_stats_request_OF_VERSION_1_3_check(
    of_table_stats_request_t *obj, int value);
extern int of_table_stats_request_OF_VERSION_1_3_populate_scalars(
    of_table_stats_request_t *obj, int value);
extern int of_table_stats_request_OF_VERSION_1_3_check_scalars(
    of_table_stats_request_t *obj, int value);

extern int of_action_bsn_checksum_OF_VERSION_1_3_populate(
    of_action_bsn_checksum_t *obj, int value);
extern int of_action_bsn_checksum_OF_VERSION_1_3_check(
    of_action_bsn_checksum_t *obj, int value);
extern int of_action_bsn_checksum_OF_VERSION_1_3_populate_scalars(
    of_action_bsn_checksum_t *obj, int value);
extern int of_action_bsn_checksum_OF_VERSION_1_3_check_scalars(
    of_action_bsn_checksum_t *obj, int value);

extern int of_action_bsn_gentable_OF_VERSION_1_3_populate(
    of_action_bsn_gentable_t *obj, int value);
extern int of_action_bsn_gentable_OF_VERSION_1_3_check(
    of_action_bsn_gentable_t *obj, int value);
extern int of_action_bsn_gentable_OF_VERSION_1_3_populate_scalars(
    of_action_bsn_gentable_t *obj, int value);
extern int of_action_bsn_gentable_OF_VERSION_1_3_check_scalars(
    of_action_bsn_gentable_t *obj, int value);

extern int of_action_bsn_mirror_OF_VERSION_1_3_populate(
    of_action_bsn_mirror_t *obj, int value);
extern int of_action_bsn_mirror_OF_VERSION_1_3_check(
    of_action_bsn_mirror_t *obj, int value);
extern int of_action_bsn_mirror_OF_VERSION_1_3_populate_scalars(
    of_action_bsn_mirror_t *obj, int value);
extern int of_action_bsn_mirror_OF_VERSION_1_3_check_scalars(
    of_action_bsn_mirror_t *obj, int value);

extern int of_action_bsn_set_tunnel_dst_OF_VERSION_1_3_populate(
    of_action_bsn_set_tunnel_dst_t *obj, int value);
extern int of_action_bsn_set_tunnel_dst_OF_VERSION_1_3_check(
    of_action_bsn_set_tunnel_dst_t *obj, int value);
extern int of_action_bsn_set_tunnel_dst_OF_VERSION_1_3_populate_scalars(
    of_action_bsn_set_tunnel_dst_t *obj, int value);
extern int of_action_bsn_set_tunnel_dst_OF_VERSION_1_3_check_scalars(
    of_action_bsn_set_tunnel_dst_t *obj, int value);

extern int of_action_copy_ttl_in_OF_VERSION_1_3_populate(
    of_action_copy_ttl_in_t *obj, int value);
extern int of_action_copy_ttl_in_OF_VERSION_1_3_check(
    of_action_copy_ttl_in_t *obj, int value);
extern int of_action_copy_ttl_in_OF_VERSION_1_3_populate_scalars(
    of_action_copy_ttl_in_t *obj, int value);
extern int of_action_copy_ttl_in_OF_VERSION_1_3_check_scalars(
    of_action_copy_ttl_in_t *obj, int value);

extern int of_action_copy_ttl_out_OF_VERSION_1_3_populate(
    of_action_copy_ttl_out_t *obj, int value);
extern int of_action_copy_ttl_out_OF_VERSION_1_3_check(
    of_action_copy_ttl_out_t *obj, int value);
extern int of_action_copy_ttl_out_OF_VERSION_1_3_populate_scalars(
    of_action_copy_ttl_out_t *obj, int value);
extern int of_action_copy_ttl_out_OF_VERSION_1_3_check_scalars(
    of_action_copy_ttl_out_t *obj, int value);

extern int of_action_dec_mpls_ttl_OF_VERSION_1_3_populate(
    of_action_dec_mpls_ttl_t *obj, int value);
extern int of_action_dec_mpls_ttl_OF_VERSION_1_3_check(
    of_action_dec_mpls_ttl_t *obj, int value);
extern int of_action_dec_mpls_ttl_OF_VERSION_1_3_populate_scalars(
    of_action_dec_mpls_ttl_t *obj, int value);
extern int of_action_dec_mpls_ttl_OF_VERSION_1_3_check_scalars(
    of_action_dec_mpls_ttl_t *obj, int value);

extern int of_action_dec_nw_ttl_OF_VERSION_1_3_populate(
    of_action_dec_nw_ttl_t *obj, int value);
extern int of_action_dec_nw_ttl_OF_VERSION_1_3_check(
    of_action_dec_nw_ttl_t *obj, int value);
extern int of_action_dec_nw_ttl_OF_VERSION_1_3_populate_scalars(
    of_action_dec_nw_ttl_t *obj, int value);
extern int of_action_dec_nw_ttl_OF_VERSION_1_3_check_scalars(
    of_action_dec_nw_ttl_t *obj, int value);

extern int of_action_group_OF_VERSION_1_3_populate(
    of_action_group_t *obj, int value);
extern int of_action_group_OF_VERSION_1_3_check(
    of_action_group_t *obj, int value);
extern int of_action_group_OF_VERSION_1_3_populate_scalars(
    of_action_group_t *obj, int value);
extern int of_action_group_OF_VERSION_1_3_check_scalars(
    of_action_group_t *obj, int value);

extern int of_action_id_bsn_checksum_OF_VERSION_1_3_populate(
    of_action_id_bsn_checksum_t *obj, int value);
extern int of_action_id_bsn_checksum_OF_VERSION_1_3_check(
    of_action_id_bsn_checksum_t *obj, int value);
extern int of_action_id_bsn_checksum_OF_VERSION_1_3_populate_scalars(
    of_action_id_bsn_checksum_t *obj, int value);
extern int of_action_id_bsn_checksum_OF_VERSION_1_3_check_scalars(
    of_action_id_bsn_checksum_t *obj, int value);

extern int of_action_id_bsn_gentable_OF_VERSION_1_3_populate(
    of_action_id_bsn_gentable_t *obj, int value);
extern int of_action_id_bsn_gentable_OF_VERSION_1_3_check(
    of_action_id_bsn_gentable_t *obj, int value);
extern int of_action_id_bsn_gentable_OF_VERSION_1_3_populate_scalars(
    of_action_id_bsn_gentable_t *obj, int value);
extern int of_action_id_bsn_gentable_OF_VERSION_1_3_check_scalars(
    of_action_id_bsn_gentable_t *obj, int value);

extern int of_action_id_bsn_mirror_OF_VERSION_1_3_populate(
    of_action_id_bsn_mirror_t *obj, int value);
extern int of_action_id_bsn_mirror_OF_VERSION_1_3_check(
    of_action_id_bsn_mirror_t *obj, int value);
extern int of_action_id_bsn_mirror_OF_VERSION_1_3_populate_scalars(
    of_action_id_bsn_mirror_t *obj, int value);
extern int of_action_id_bsn_mirror_OF_VERSION_1_3_check_scalars(
    of_action_id_bsn_mirror_t *obj, int value);

extern int of_action_id_bsn_set_tunnel_dst_OF_VERSION_1_3_populate(
    of_action_id_bsn_set_tunnel_dst_t *obj, int value);
extern int of_action_id_bsn_set_tunnel_dst_OF_VERSION_1_3_check(
    of_action_id_bsn_set_tunnel_dst_t *obj, int value);
extern int of_action_id_bsn_set_tunnel_dst_OF_VERSION_1_3_populate_scalars(
    of_action_id_bsn_set_tunnel_dst_t *obj, int value);
extern int of_action_id_bsn_set_tunnel_dst_OF_VERSION_1_3_check_scalars(
    of_action_id_bsn_set_tunnel_dst_t *obj, int value);

extern int of_action_id_copy_ttl_in_OF_VERSION_1_3_populate(
    of_action_id_copy_ttl_in_t *obj, int value);
extern int of_action_id_copy_ttl_in_OF_VERSION_1_3_check(
    of_action_id_copy_ttl_in_t *obj, int value);
extern int of_action_id_copy_ttl_in_OF_VERSION_1_3_populate_scalars(
    of_action_id_copy_ttl_in_t *obj, int value);
extern int of_action_id_copy_ttl_in_OF_VERSION_1_3_check_scalars(
    of_action_id_copy_ttl_in_t *obj, int value);

extern int of_action_id_copy_ttl_out_OF_VERSION_1_3_populate(
    of_action_id_copy_ttl_out_t *obj, int value);
extern int of_action_id_copy_ttl_out_OF_VERSION_1_3_check(
    of_action_id_copy_ttl_out_t *obj, int value);
extern int of_action_id_copy_ttl_out_OF_VERSION_1_3_populate_scalars(
    of_action_id_copy_ttl_out_t *obj, int value);
extern int of_action_id_copy_ttl_out_OF_VERSION_1_3_check_scalars(
    of_action_id_copy_ttl_out_t *obj, int value);

extern int of_action_id_dec_mpls_ttl_OF_VERSION_1_3_populate(
    of_action_id_dec_mpls_ttl_t *obj, int value);
extern int of_action_id_dec_mpls_ttl_OF_VERSION_1_3_check(
    of_action_id_dec_mpls_ttl_t *obj, int value);
extern int of_action_id_dec_mpls_ttl_OF_VERSION_1_3_populate_scalars(
    of_action_id_dec_mpls_ttl_t *obj, int value);
extern int of_action_id_dec_mpls_ttl_OF_VERSION_1_3_check_scalars(
    of_action_id_dec_mpls_ttl_t *obj, int value);

extern int of_action_id_dec_nw_ttl_OF_VERSION_1_3_populate(
    of_action_id_dec_nw_ttl_t *obj, int value);
extern int of_action_id_dec_nw_ttl_OF_VERSION_1_3_check(
    of_action_id_dec_nw_ttl_t *obj, int value);
extern int of_action_id_dec_nw_ttl_OF_VERSION_1_3_populate_scalars(
    of_action_id_dec_nw_ttl_t *obj, int value);
extern int of_action_id_dec_nw_ttl_OF_VERSION_1_3_check_scalars(
    of_action_id_dec_nw_ttl_t *obj, int value);

extern int of_action_id_group_OF_VERSION_1_3_populate(
    of_action_id_group_t *obj, int value);
extern int of_action_id_group_OF_VERSION_1_3_check(
    of_action_id_group_t *obj, int value);
extern int of_action_id_group_OF_VERSION_1_3_populate_scalars(
    of_action_id_group_t *obj, int value);
extern int of_action_id_group_OF_VERSION_1_3_check_scalars(
    of_action_id_group_t *obj, int value);

extern int of_action_id_nicira_dec_ttl_OF_VERSION_1_3_populate(
    of_action_id_nicira_dec_ttl_t *obj, int value);
extern int of_action_id_nicira_dec_ttl_OF_VERSION_1_3_check(
    of_action_id_nicira_dec_ttl_t *obj, int value);
extern int of_action_id_nicira_dec_ttl_OF_VERSION_1_3_populate_scalars(
    of_action_id_nicira_dec_ttl_t *obj, int value);
extern int of_action_id_nicira_dec_ttl_OF_VERSION_1_3_check_scalars(
    of_action_id_nicira_dec_ttl_t *obj, int value);

extern int of_action_id_output_OF_VERSION_1_3_populate(
    of_action_id_output_t *obj, int value);
extern int of_action_id_output_OF_VERSION_1_3_check(
    of_action_id_output_t *obj, int value);
extern int of_action_id_output_OF_VERSION_1_3_populate_scalars(
    of_action_id_output_t *obj, int value);
extern int of_action_id_output_OF_VERSION_1_3_check_scalars(
    of_action_id_output_t *obj, int value);

extern int of_action_id_pop_mpls_OF_VERSION_1_3_populate(
    of_action_id_pop_mpls_t *obj, int value);
extern int of_action_id_pop_mpls_OF_VERSION_1_3_check(
    of_action_id_pop_mpls_t *obj, int value);
extern int of_action_id_pop_mpls_OF_VERSION_1_3_populate_scalars(
    of_action_id_pop_mpls_t *obj, int value);
extern int of_action_id_pop_mpls_OF_VERSION_1_3_check_scalars(
    of_action_id_pop_mpls_t *obj, int value);

extern int of_action_id_pop_pbb_OF_VERSION_1_3_populate(
    of_action_id_pop_pbb_t *obj, int value);
extern int of_action_id_pop_pbb_OF_VERSION_1_3_check(
    of_action_id_pop_pbb_t *obj, int value);
extern int of_action_id_pop_pbb_OF_VERSION_1_3_populate_scalars(
    of_action_id_pop_pbb_t *obj, int value);
extern int of_action_id_pop_pbb_OF_VERSION_1_3_check_scalars(
    of_action_id_pop_pbb_t *obj, int value);

extern int of_action_id_pop_vlan_OF_VERSION_1_3_populate(
    of_action_id_pop_vlan_t *obj, int value);
extern int of_action_id_pop_vlan_OF_VERSION_1_3_check(
    of_action_id_pop_vlan_t *obj, int value);
extern int of_action_id_pop_vlan_OF_VERSION_1_3_populate_scalars(
    of_action_id_pop_vlan_t *obj, int value);
extern int of_action_id_pop_vlan_OF_VERSION_1_3_check_scalars(
    of_action_id_pop_vlan_t *obj, int value);

extern int of_action_id_push_mpls_OF_VERSION_1_3_populate(
    of_action_id_push_mpls_t *obj, int value);
extern int of_action_id_push_mpls_OF_VERSION_1_3_check(
    of_action_id_push_mpls_t *obj, int value);
extern int of_action_id_push_mpls_OF_VERSION_1_3_populate_scalars(
    of_action_id_push_mpls_t *obj, int value);
extern int of_action_id_push_mpls_OF_VERSION_1_3_check_scalars(
    of_action_id_push_mpls_t *obj, int value);

extern int of_action_id_push_pbb_OF_VERSION_1_3_populate(
    of_action_id_push_pbb_t *obj, int value);
extern int of_action_id_push_pbb_OF_VERSION_1_3_check(
    of_action_id_push_pbb_t *obj, int value);
extern int of_action_id_push_pbb_OF_VERSION_1_3_populate_scalars(
    of_action_id_push_pbb_t *obj, int value);
extern int of_action_id_push_pbb_OF_VERSION_1_3_check_scalars(
    of_action_id_push_pbb_t *obj, int value);

extern int of_action_id_push_vlan_OF_VERSION_1_3_populate(
    of_action_id_push_vlan_t *obj, int value);
extern int of_action_id_push_vlan_OF_VERSION_1_3_check(
    of_action_id_push_vlan_t *obj, int value);
extern int of_action_id_push_vlan_OF_VERSION_1_3_populate_scalars(
    of_action_id_push_vlan_t *obj, int value);
extern int of_action_id_push_vlan_OF_VERSION_1_3_check_scalars(
    of_action_id_push_vlan_t *obj, int value);

extern int of_action_id_set_field_OF_VERSION_1_3_populate(
    of_action_id_set_field_t *obj, int value);
extern int of_action_id_set_field_OF_VERSION_1_3_check(
    of_action_id_set_field_t *obj, int value);
extern int of_action_id_set_field_OF_VERSION_1_3_populate_scalars(
    of_action_id_set_field_t *obj, int value);
extern int of_action_id_set_field_OF_VERSION_1_3_check_scalars(
    of_action_id_set_field_t *obj, int value);

extern int of_action_id_set_mpls_ttl_OF_VERSION_1_3_populate(
    of_action_id_set_mpls_ttl_t *obj, int value);
extern int of_action_id_set_mpls_ttl_OF_VERSION_1_3_check(
    of_action_id_set_mpls_ttl_t *obj, int value);
extern int of_action_id_set_mpls_ttl_OF_VERSION_1_3_populate_scalars(
    of_action_id_set_mpls_ttl_t *obj, int value);
extern int of_action_id_set_mpls_ttl_OF_VERSION_1_3_check_scalars(
    of_action_id_set_mpls_ttl_t *obj, int value);

extern int of_action_id_set_nw_ttl_OF_VERSION_1_3_populate(
    of_action_id_set_nw_ttl_t *obj, int value);
extern int of_action_id_set_nw_ttl_OF_VERSION_1_3_check(
    of_action_id_set_nw_ttl_t *obj, int value);
extern int of_action_id_set_nw_ttl_OF_VERSION_1_3_populate_scalars(
    of_action_id_set_nw_ttl_t *obj, int value);
extern int of_action_id_set_nw_ttl_OF_VERSION_1_3_check_scalars(
    of_action_id_set_nw_ttl_t *obj, int value);

extern int of_action_id_set_queue_OF_VERSION_1_3_populate(
    of_action_id_set_queue_t *obj, int value);
extern int of_action_id_set_queue_OF_VERSION_1_3_check(
    of_action_id_set_queue_t *obj, int value);
extern int of_action_id_set_queue_OF_VERSION_1_3_populate_scalars(
    of_action_id_set_queue_t *obj, int value);
extern int of_action_id_set_queue_OF_VERSION_1_3_check_scalars(
    of_action_id_set_queue_t *obj, int value);

extern int of_action_nicira_dec_ttl_OF_VERSION_1_3_populate(
    of_action_nicira_dec_ttl_t *obj, int value);
extern int of_action_nicira_dec_ttl_OF_VERSION_1_3_check(
    of_action_nicira_dec_ttl_t *obj, int value);
extern int of_action_nicira_dec_ttl_OF_VERSION_1_3_populate_scalars(
    of_action_nicira_dec_ttl_t *obj, int value);
extern int of_action_nicira_dec_ttl_OF_VERSION_1_3_check_scalars(
    of_action_nicira_dec_ttl_t *obj, int value);

extern int of_action_output_OF_VERSION_1_3_populate(
    of_action_output_t *obj, int value);
extern int of_action_output_OF_VERSION_1_3_check(
    of_action_output_t *obj, int value);
extern int of_action_output_OF_VERSION_1_3_populate_scalars(
    of_action_output_t *obj, int value);
extern int of_action_output_OF_VERSION_1_3_check_scalars(
    of_action_output_t *obj, int value);

extern int of_action_pop_mpls_OF_VERSION_1_3_populate(
    of_action_pop_mpls_t *obj, int value);
extern int of_action_pop_mpls_OF_VERSION_1_3_check(
    of_action_pop_mpls_t *obj, int value);
extern int of_action_pop_mpls_OF_VERSION_1_3_populate_scalars(
    of_action_pop_mpls_t *obj, int value);
extern int of_action_pop_mpls_OF_VERSION_1_3_check_scalars(
    of_action_pop_mpls_t *obj, int value);

extern int of_action_pop_pbb_OF_VERSION_1_3_populate(
    of_action_pop_pbb_t *obj, int value);
extern int of_action_pop_pbb_OF_VERSION_1_3_check(
    of_action_pop_pbb_t *obj, int value);
extern int of_action_pop_pbb_OF_VERSION_1_3_populate_scalars(
    of_action_pop_pbb_t *obj, int value);
extern int of_action_pop_pbb_OF_VERSION_1_3_check_scalars(
    of_action_pop_pbb_t *obj, int value);

extern int of_action_pop_vlan_OF_VERSION_1_3_populate(
    of_action_pop_vlan_t *obj, int value);
extern int of_action_pop_vlan_OF_VERSION_1_3_check(
    of_action_pop_vlan_t *obj, int value);
extern int of_action_pop_vlan_OF_VERSION_1_3_populate_scalars(
    of_action_pop_vlan_t *obj, int value);
extern int of_action_pop_vlan_OF_VERSION_1_3_check_scalars(
    of_action_pop_vlan_t *obj, int value);

extern int of_action_push_mpls_OF_VERSION_1_3_populate(
    of_action_push_mpls_t *obj, int value);
extern int of_action_push_mpls_OF_VERSION_1_3_check(
    of_action_push_mpls_t *obj, int value);
extern int of_action_push_mpls_OF_VERSION_1_3_populate_scalars(
    of_action_push_mpls_t *obj, int value);
extern int of_action_push_mpls_OF_VERSION_1_3_check_scalars(
    of_action_push_mpls_t *obj, int value);

extern int of_action_push_pbb_OF_VERSION_1_3_populate(
    of_action_push_pbb_t *obj, int value);
extern int of_action_push_pbb_OF_VERSION_1_3_check(
    of_action_push_pbb_t *obj, int value);
extern int of_action_push_pbb_OF_VERSION_1_3_populate_scalars(
    of_action_push_pbb_t *obj, int value);
extern int of_action_push_pbb_OF_VERSION_1_3_check_scalars(
    of_action_push_pbb_t *obj, int value);

extern int of_action_push_vlan_OF_VERSION_1_3_populate(
    of_action_push_vlan_t *obj, int value);
extern int of_action_push_vlan_OF_VERSION_1_3_check(
    of_action_push_vlan_t *obj, int value);
extern int of_action_push_vlan_OF_VERSION_1_3_populate_scalars(
    of_action_push_vlan_t *obj, int value);
extern int of_action_push_vlan_OF_VERSION_1_3_check_scalars(
    of_action_push_vlan_t *obj, int value);

extern int of_action_set_field_OF_VERSION_1_3_populate(
    of_action_set_field_t *obj, int value);
extern int of_action_set_field_OF_VERSION_1_3_check(
    of_action_set_field_t *obj, int value);
extern int of_action_set_field_OF_VERSION_1_3_populate_scalars(
    of_action_set_field_t *obj, int value);
extern int of_action_set_field_OF_VERSION_1_3_check_scalars(
    of_action_set_field_t *obj, int value);

extern int of_action_set_mpls_ttl_OF_VERSION_1_3_populate(
    of_action_set_mpls_ttl_t *obj, int value);
extern int of_action_set_mpls_ttl_OF_VERSION_1_3_check(
    of_action_set_mpls_ttl_t *obj, int value);
extern int of_action_set_mpls_ttl_OF_VERSION_1_3_populate_scalars(
    of_action_set_mpls_ttl_t *obj, int value);
extern int of_action_set_mpls_ttl_OF_VERSION_1_3_check_scalars(
    of_action_set_mpls_ttl_t *obj, int value);

extern int of_action_set_nw_ttl_OF_VERSION_1_3_populate(
    of_action_set_nw_ttl_t *obj, int value);
extern int of_action_set_nw_ttl_OF_VERSION_1_3_check(
    of_action_set_nw_ttl_t *obj, int value);
extern int of_action_set_nw_ttl_OF_VERSION_1_3_populate_scalars(
    of_action_set_nw_ttl_t *obj, int value);
extern int of_action_set_nw_ttl_OF_VERSION_1_3_check_scalars(
    of_action_set_nw_ttl_t *obj, int value);

extern int of_action_set_queue_OF_VERSION_1_3_populate(
    of_action_set_queue_t *obj, int value);
extern int of_action_set_queue_OF_VERSION_1_3_check(
    of_action_set_queue_t *obj, int value);
extern int of_action_set_queue_OF_VERSION_1_3_populate_scalars(
    of_action_set_queue_t *obj, int value);
extern int of_action_set_queue_OF_VERSION_1_3_check_scalars(
    of_action_set_queue_t *obj, int value);

extern int of_bsn_controller_connection_OF_VERSION_1_3_populate(
    of_bsn_controller_connection_t *obj, int value);
extern int of_bsn_controller_connection_OF_VERSION_1_3_check(
    of_bsn_controller_connection_t *obj, int value);
extern int of_bsn_controller_connection_OF_VERSION_1_3_populate_scalars(
    of_bsn_controller_connection_t *obj, int value);
extern int of_bsn_controller_connection_OF_VERSION_1_3_check_scalars(
    of_bsn_controller_connection_t *obj, int value);

extern int of_bsn_debug_counter_desc_stats_entry_OF_VERSION_1_3_populate(
    of_bsn_debug_counter_desc_stats_entry_t *obj, int value);
extern int of_bsn_debug_counter_desc_stats_entry_OF_VERSION_1_3_check(
    of_bsn_debug_counter_desc_stats_entry_t *obj, int value);
extern int of_bsn_debug_counter_desc_stats_entry_OF_VERSION_1_3_populate_scalars(
    of_bsn_debug_counter_desc_stats_entry_t *obj, int value);
extern int of_bsn_debug_counter_desc_stats_entry_OF_VERSION_1_3_check_scalars(
    of_bsn_debug_counter_desc_stats_entry_t *obj, int value);

extern int of_bsn_debug_counter_stats_entry_OF_VERSION_1_3_populate(
    of_bsn_debug_counter_stats_entry_t *obj, int value);
extern int of_bsn_debug_counter_stats_entry_OF_VERSION_1_3_check(
    of_bsn_debug_counter_stats_entry_t *obj, int value);
extern int of_bsn_debug_counter_stats_entry_OF_VERSION_1_3_populate_scalars(
    of_bsn_debug_counter_stats_entry_t *obj, int value);
extern int of_bsn_debug_counter_stats_entry_OF_VERSION_1_3_check_scalars(
    of_bsn_debug_counter_stats_entry_t *obj, int value);

extern int of_bsn_flow_checksum_bucket_stats_entry_OF_VERSION_1_3_populate(
    of_bsn_flow_checksum_bucket_stats_entry_t *obj, int value);
extern int of_bsn_flow_checksum_bucket_stats_entry_OF_VERSION_1_3_check(
    of_bsn_flow_checksum_bucket_stats_entry_t *obj, int value);
extern int of_bsn_flow_checksum_bucket_stats_entry_OF_VERSION_1_3_populate_scalars(
    of_bsn_flow_checksum_bucket_stats_entry_t *obj, int value);
extern int of_bsn_flow_checksum_bucket_stats_entry_OF_VERSION_1_3_check_scalars(
    of_bsn_flow_checksum_bucket_stats_entry_t *obj, int value);

extern int of_bsn_generic_stats_entry_OF_VERSION_1_3_populate(
    of_bsn_generic_stats_entry_t *obj, int value);
extern int of_bsn_generic_stats_entry_OF_VERSION_1_3_check(
    of_bsn_generic_stats_entry_t *obj, int value);
extern int of_bsn_generic_stats_entry_OF_VERSION_1_3_populate_scalars(
    of_bsn_generic_stats_entry_t *obj, int value);
extern int of_bsn_generic_stats_entry_OF_VERSION_1_3_check_scalars(
    of_bsn_generic_stats_entry_t *obj, int value);

extern int of_bsn_gentable_bucket_stats_entry_OF_VERSION_1_3_populate(
    of_bsn_gentable_bucket_stats_entry_t *obj, int value);
extern int of_bsn_gentable_bucket_stats_entry_OF_VERSION_1_3_check(
    of_bsn_gentable_bucket_stats_entry_t *obj, int value);
extern int of_bsn_gentable_bucket_stats_entry_OF_VERSION_1_3_populate_scalars(
    of_bsn_gentable_bucket_stats_entry_t *obj, int value);
extern int of_bsn_gentable_bucket_stats_entry_OF_VERSION_1_3_check_scalars(
    of_bsn_gentable_bucket_stats_entry_t *obj, int value);

extern int of_bsn_gentable_desc_stats_entry_OF_VERSION_1_3_populate(
    of_bsn_gentable_desc_stats_entry_t *obj, int value);
extern int of_bsn_gentable_desc_stats_entry_OF_VERSION_1_3_check(
    of_bsn_gentable_desc_stats_entry_t *obj, int value);
extern int of_bsn_gentable_desc_stats_entry_OF_VERSION_1_3_populate_scalars(
    of_bsn_gentable_desc_stats_entry_t *obj, int value);
extern int of_bsn_gentable_desc_stats_entry_OF_VERSION_1_3_check_scalars(
    of_bsn_gentable_desc_stats_entry_t *obj, int value);

extern int of_bsn_gentable_entry_desc_stats_entry_OF_VERSION_1_3_populate(
    of_bsn_gentable_entry_desc_stats_entry_t *obj, int value);
extern int of_bsn_gentable_entry_desc_stats_entry_OF_VERSION_1_3_check(
    of_bsn_gentable_entry_desc_stats_entry_t *obj, int value);
extern int of_bsn_gentable_entry_desc_stats_entry_OF_VERSION_1_3_populate_scalars(
    of_bsn_gentable_entry_desc_stats_entry_t *obj, int value);
extern int of_bsn_gentable_entry_desc_stats_entry_OF_VERSION_1_3_check_scalars(
    of_bsn_gentable_entry_desc_stats_entry_t *obj, int value);

extern int of_bsn_gentable_entry_stats_entry_OF_VERSION_1_3_populate(
    of_bsn_gentable_entry_stats_entry_t *obj, int value);
extern int of_bsn_gentable_entry_stats_entry_OF_VERSION_1_3_check(
    of_bsn_gentable_entry_stats_entry_t *obj, int value);
extern int of_bsn_gentable_entry_stats_entry_OF_VERSION_1_3_populate_scalars(
    of_bsn_gentable_entry_stats_entry_t *obj, int value);
extern int of_bsn_gentable_entry_stats_entry_OF_VERSION_1_3_check_scalars(
    of_bsn_gentable_entry_stats_entry_t *obj, int value);

extern int of_bsn_gentable_stats_entry_OF_VERSION_1_3_populate(
    of_bsn_gentable_stats_entry_t *obj, int value);
extern int of_bsn_gentable_stats_entry_OF_VERSION_1_3_check(
    of_bsn_gentable_stats_entry_t *obj, int value);
extern int of_bsn_gentable_stats_entry_OF_VERSION_1_3_populate_scalars(
    of_bsn_gentable_stats_entry_t *obj, int value);
extern int of_bsn_gentable_stats_entry_OF_VERSION_1_3_check_scalars(
    of_bsn_gentable_stats_entry_t *obj, int value);

extern int of_bsn_interface_OF_VERSION_1_3_populate(
    of_bsn_interface_t *obj, int value);
extern int of_bsn_interface_OF_VERSION_1_3_check(
    of_bsn_interface_t *obj, int value);
extern int of_bsn_interface_OF_VERSION_1_3_populate_scalars(
    of_bsn_interface_t *obj, int value);
extern int of_bsn_interface_OF_VERSION_1_3_check_scalars(
    of_bsn_interface_t *obj, int value);

extern int of_bsn_lacp_stats_entry_OF_VERSION_1_3_populate(
    of_bsn_lacp_stats_entry_t *obj, int value);
extern int of_bsn_lacp_stats_entry_OF_VERSION_1_3_check(
    of_bsn_lacp_stats_entry_t *obj, int value);
extern int of_bsn_lacp_stats_entry_OF_VERSION_1_3_populate_scalars(
    of_bsn_lacp_stats_entry_t *obj, int value);
extern int of_bsn_lacp_stats_entry_OF_VERSION_1_3_check_scalars(
    of_bsn_lacp_stats_entry_t *obj, int value);

extern int of_bsn_port_counter_stats_entry_OF_VERSION_1_3_populate(
    of_bsn_port_counter_stats_entry_t *obj, int value);
extern int of_bsn_port_counter_stats_entry_OF_VERSION_1_3_check(
    of_bsn_port_counter_stats_entry_t *obj, int value);
extern int of_bsn_port_counter_stats_entry_OF_VERSION_1_3_populate_scalars(
    of_bsn_port_counter_stats_entry_t *obj, int value);
extern int of_bsn_port_counter_stats_entry_OF_VERSION_1_3_check_scalars(
    of_bsn_port_counter_stats_entry_t *obj, int value);

extern int of_bsn_switch_pipeline_stats_entry_OF_VERSION_1_3_populate(
    of_bsn_switch_pipeline_stats_entry_t *obj, int value);
extern int of_bsn_switch_pipeline_stats_entry_OF_VERSION_1_3_check(
    of_bsn_switch_pipeline_stats_entry_t *obj, int value);
extern int of_bsn_switch_pipeline_stats_entry_OF_VERSION_1_3_populate_scalars(
    of_bsn_switch_pipeline_stats_entry_t *obj, int value);
extern int of_bsn_switch_pipeline_stats_entry_OF_VERSION_1_3_check_scalars(
    of_bsn_switch_pipeline_stats_entry_t *obj, int value);

extern int of_bsn_table_checksum_stats_entry_OF_VERSION_1_3_populate(
    of_bsn_table_checksum_stats_entry_t *obj, int value);
extern int of_bsn_table_checksum_stats_entry_OF_VERSION_1_3_check(
    of_bsn_table_checksum_stats_entry_t *obj, int value);
extern int of_bsn_table_checksum_stats_entry_OF_VERSION_1_3_populate_scalars(
    of_bsn_table_checksum_stats_entry_t *obj, int value);
extern int of_bsn_table_checksum_stats_entry_OF_VERSION_1_3_check_scalars(
    of_bsn_table_checksum_stats_entry_t *obj, int value);

extern int of_bsn_tlv_actor_key_OF_VERSION_1_3_populate(
    of_bsn_tlv_actor_key_t *obj, int value);
extern int of_bsn_tlv_actor_key_OF_VERSION_1_3_check(
    of_bsn_tlv_actor_key_t *obj, int value);
extern int of_bsn_tlv_actor_key_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_actor_key_t *obj, int value);
extern int of_bsn_tlv_actor_key_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_actor_key_t *obj, int value);

extern int of_bsn_tlv_actor_port_num_OF_VERSION_1_3_populate(
    of_bsn_tlv_actor_port_num_t *obj, int value);
extern int of_bsn_tlv_actor_port_num_OF_VERSION_1_3_check(
    of_bsn_tlv_actor_port_num_t *obj, int value);
extern int of_bsn_tlv_actor_port_num_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_actor_port_num_t *obj, int value);
extern int of_bsn_tlv_actor_port_num_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_actor_port_num_t *obj, int value);

extern int of_bsn_tlv_actor_port_priority_OF_VERSION_1_3_populate(
    of_bsn_tlv_actor_port_priority_t *obj, int value);
extern int of_bsn_tlv_actor_port_priority_OF_VERSION_1_3_check(
    of_bsn_tlv_actor_port_priority_t *obj, int value);
extern int of_bsn_tlv_actor_port_priority_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_actor_port_priority_t *obj, int value);
extern int of_bsn_tlv_actor_port_priority_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_actor_port_priority_t *obj, int value);

extern int of_bsn_tlv_actor_state_OF_VERSION_1_3_populate(
    of_bsn_tlv_actor_state_t *obj, int value);
extern int of_bsn_tlv_actor_state_OF_VERSION_1_3_check(
    of_bsn_tlv_actor_state_t *obj, int value);
extern int of_bsn_tlv_actor_state_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_actor_state_t *obj, int value);
extern int of_bsn_tlv_actor_state_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_actor_state_t *obj, int value);

extern int of_bsn_tlv_actor_system_mac_OF_VERSION_1_3_populate(
    of_bsn_tlv_actor_system_mac_t *obj, int value);
extern int of_bsn_tlv_actor_system_mac_OF_VERSION_1_3_check(
    of_bsn_tlv_actor_system_mac_t *obj, int value);
extern int of_bsn_tlv_actor_system_mac_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_actor_system_mac_t *obj, int value);
extern int of_bsn_tlv_actor_system_mac_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_actor_system_mac_t *obj, int value);

extern int of_bsn_tlv_actor_system_priority_OF_VERSION_1_3_populate(
    of_bsn_tlv_actor_system_priority_t *obj, int value);
extern int of_bsn_tlv_actor_system_priority_OF_VERSION_1_3_check(
    of_bsn_tlv_actor_system_priority_t *obj, int value);
extern int of_bsn_tlv_actor_system_priority_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_actor_system_priority_t *obj, int value);
extern int of_bsn_tlv_actor_system_priority_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_actor_system_priority_t *obj, int value);

extern int of_bsn_tlv_anchor_OF_VERSION_1_3_populate(
    of_bsn_tlv_anchor_t *obj, int value);
extern int of_bsn_tlv_anchor_OF_VERSION_1_3_check(
    of_bsn_tlv_anchor_t *obj, int value);
extern int of_bsn_tlv_anchor_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_anchor_t *obj, int value);
extern int of_bsn_tlv_anchor_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_anchor_t *obj, int value);

extern int of_bsn_tlv_apply_bytes_OF_VERSION_1_3_populate(
    of_bsn_tlv_apply_bytes_t *obj, int value);
extern int of_bsn_tlv_apply_bytes_OF_VERSION_1_3_check(
    of_bsn_tlv_apply_bytes_t *obj, int value);
extern int of_bsn_tlv_apply_bytes_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_apply_bytes_t *obj, int value);
extern int of_bsn_tlv_apply_bytes_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_apply_bytes_t *obj, int value);

extern int of_bsn_tlv_apply_packets_OF_VERSION_1_3_populate(
    of_bsn_tlv_apply_packets_t *obj, int value);
extern int of_bsn_tlv_apply_packets_OF_VERSION_1_3_check(
    of_bsn_tlv_apply_packets_t *obj, int value);
extern int of_bsn_tlv_apply_packets_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_apply_packets_t *obj, int value);
extern int of_bsn_tlv_apply_packets_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_apply_packets_t *obj, int value);

extern int of_bsn_tlv_auto_negotiation_OF_VERSION_1_3_populate(
    of_bsn_tlv_auto_negotiation_t *obj, int value);
extern int of_bsn_tlv_auto_negotiation_OF_VERSION_1_3_check(
    of_bsn_tlv_auto_negotiation_t *obj, int value);
extern int of_bsn_tlv_auto_negotiation_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_auto_negotiation_t *obj, int value);
extern int of_bsn_tlv_auto_negotiation_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_auto_negotiation_t *obj, int value);

extern int of_bsn_tlv_broadcast_query_timeout_OF_VERSION_1_3_populate(
    of_bsn_tlv_broadcast_query_timeout_t *obj, int value);
extern int of_bsn_tlv_broadcast_query_timeout_OF_VERSION_1_3_check(
    of_bsn_tlv_broadcast_query_timeout_t *obj, int value);
extern int of_bsn_tlv_broadcast_query_timeout_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_broadcast_query_timeout_t *obj, int value);
extern int of_bsn_tlv_broadcast_query_timeout_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_broadcast_query_timeout_t *obj, int value);

extern int of_bsn_tlv_broadcast_rate_OF_VERSION_1_3_populate(
    of_bsn_tlv_broadcast_rate_t *obj, int value);
extern int of_bsn_tlv_broadcast_rate_OF_VERSION_1_3_check(
    of_bsn_tlv_broadcast_rate_t *obj, int value);
extern int of_bsn_tlv_broadcast_rate_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_broadcast_rate_t *obj, int value);
extern int of_bsn_tlv_broadcast_rate_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_broadcast_rate_t *obj, int value);

extern int of_bsn_tlv_bucket_OF_VERSION_1_3_populate(
    of_bsn_tlv_bucket_t *obj, int value);
extern int of_bsn_tlv_bucket_OF_VERSION_1_3_check(
    of_bsn_tlv_bucket_t *obj, int value);
extern int of_bsn_tlv_bucket_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_bucket_t *obj, int value);
extern int of_bsn_tlv_bucket_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_bucket_t *obj, int value);

extern int of_bsn_tlv_circuit_id_OF_VERSION_1_3_populate(
    of_bsn_tlv_circuit_id_t *obj, int value);
extern int of_bsn_tlv_circuit_id_OF_VERSION_1_3_check(
    of_bsn_tlv_circuit_id_t *obj, int value);
extern int of_bsn_tlv_circuit_id_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_circuit_id_t *obj, int value);
extern int of_bsn_tlv_circuit_id_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_circuit_id_t *obj, int value);

extern int of_bsn_tlv_convergence_status_OF_VERSION_1_3_populate(
    of_bsn_tlv_convergence_status_t *obj, int value);
extern int of_bsn_tlv_convergence_status_OF_VERSION_1_3_check(
    of_bsn_tlv_convergence_status_t *obj, int value);
extern int of_bsn_tlv_convergence_status_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_convergence_status_t *obj, int value);
extern int of_bsn_tlv_convergence_status_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_convergence_status_t *obj, int value);

extern int of_bsn_tlv_cpu_lag_OF_VERSION_1_3_populate(
    of_bsn_tlv_cpu_lag_t *obj, int value);
extern int of_bsn_tlv_cpu_lag_OF_VERSION_1_3_check(
    of_bsn_tlv_cpu_lag_t *obj, int value);
extern int of_bsn_tlv_cpu_lag_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_cpu_lag_t *obj, int value);
extern int of_bsn_tlv_cpu_lag_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_cpu_lag_t *obj, int value);

extern int of_bsn_tlv_crc_enabled_OF_VERSION_1_3_populate(
    of_bsn_tlv_crc_enabled_t *obj, int value);
extern int of_bsn_tlv_crc_enabled_OF_VERSION_1_3_check(
    of_bsn_tlv_crc_enabled_t *obj, int value);
extern int of_bsn_tlv_crc_enabled_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_crc_enabled_t *obj, int value);
extern int of_bsn_tlv_crc_enabled_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_crc_enabled_t *obj, int value);

extern int of_bsn_tlv_data_OF_VERSION_1_3_populate(
    of_bsn_tlv_data_t *obj, int value);
extern int of_bsn_tlv_data_OF_VERSION_1_3_check(
    of_bsn_tlv_data_t *obj, int value);
extern int of_bsn_tlv_data_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_data_t *obj, int value);
extern int of_bsn_tlv_data_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_data_t *obj, int value);

extern int of_bsn_tlv_data_mask_OF_VERSION_1_3_populate(
    of_bsn_tlv_data_mask_t *obj, int value);
extern int of_bsn_tlv_data_mask_OF_VERSION_1_3_check(
    of_bsn_tlv_data_mask_t *obj, int value);
extern int of_bsn_tlv_data_mask_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_data_mask_t *obj, int value);
extern int of_bsn_tlv_data_mask_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_data_mask_t *obj, int value);

extern int of_bsn_tlv_decap_OF_VERSION_1_3_populate(
    of_bsn_tlv_decap_t *obj, int value);
extern int of_bsn_tlv_decap_OF_VERSION_1_3_check(
    of_bsn_tlv_decap_t *obj, int value);
extern int of_bsn_tlv_decap_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_decap_t *obj, int value);
extern int of_bsn_tlv_decap_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_decap_t *obj, int value);

extern int of_bsn_tlv_disable_src_mac_check_OF_VERSION_1_3_populate(
    of_bsn_tlv_disable_src_mac_check_t *obj, int value);
extern int of_bsn_tlv_disable_src_mac_check_OF_VERSION_1_3_check(
    of_bsn_tlv_disable_src_mac_check_t *obj, int value);
extern int of_bsn_tlv_disable_src_mac_check_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_disable_src_mac_check_t *obj, int value);
extern int of_bsn_tlv_disable_src_mac_check_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_disable_src_mac_check_t *obj, int value);

extern int of_bsn_tlv_drop_OF_VERSION_1_3_populate(
    of_bsn_tlv_drop_t *obj, int value);
extern int of_bsn_tlv_drop_OF_VERSION_1_3_check(
    of_bsn_tlv_drop_t *obj, int value);
extern int of_bsn_tlv_drop_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_drop_t *obj, int value);
extern int of_bsn_tlv_drop_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_drop_t *obj, int value);

extern int of_bsn_tlv_dscp_OF_VERSION_1_3_populate(
    of_bsn_tlv_dscp_t *obj, int value);
extern int of_bsn_tlv_dscp_OF_VERSION_1_3_check(
    of_bsn_tlv_dscp_t *obj, int value);
extern int of_bsn_tlv_dscp_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_dscp_t *obj, int value);
extern int of_bsn_tlv_dscp_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_dscp_t *obj, int value);

extern int of_bsn_tlv_ecn_OF_VERSION_1_3_populate(
    of_bsn_tlv_ecn_t *obj, int value);
extern int of_bsn_tlv_ecn_OF_VERSION_1_3_check(
    of_bsn_tlv_ecn_t *obj, int value);
extern int of_bsn_tlv_ecn_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_ecn_t *obj, int value);
extern int of_bsn_tlv_ecn_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_ecn_t *obj, int value);

extern int of_bsn_tlv_egress_only_OF_VERSION_1_3_populate(
    of_bsn_tlv_egress_only_t *obj, int value);
extern int of_bsn_tlv_egress_only_OF_VERSION_1_3_check(
    of_bsn_tlv_egress_only_t *obj, int value);
extern int of_bsn_tlv_egress_only_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_egress_only_t *obj, int value);
extern int of_bsn_tlv_egress_only_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_egress_only_t *obj, int value);

extern int of_bsn_tlv_egress_port_group_id_OF_VERSION_1_3_populate(
    of_bsn_tlv_egress_port_group_id_t *obj, int value);
extern int of_bsn_tlv_egress_port_group_id_OF_VERSION_1_3_check(
    of_bsn_tlv_egress_port_group_id_t *obj, int value);
extern int of_bsn_tlv_egress_port_group_id_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_egress_port_group_id_t *obj, int value);
extern int of_bsn_tlv_egress_port_group_id_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_egress_port_group_id_t *obj, int value);

extern int of_bsn_tlv_enhanced_hash_capability_OF_VERSION_1_3_populate(
    of_bsn_tlv_enhanced_hash_capability_t *obj, int value);
extern int of_bsn_tlv_enhanced_hash_capability_OF_VERSION_1_3_check(
    of_bsn_tlv_enhanced_hash_capability_t *obj, int value);
extern int of_bsn_tlv_enhanced_hash_capability_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_enhanced_hash_capability_t *obj, int value);
extern int of_bsn_tlv_enhanced_hash_capability_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_enhanced_hash_capability_t *obj, int value);

extern int of_bsn_tlv_eth_dst_OF_VERSION_1_3_populate(
    of_bsn_tlv_eth_dst_t *obj, int value);
extern int of_bsn_tlv_eth_dst_OF_VERSION_1_3_check(
    of_bsn_tlv_eth_dst_t *obj, int value);
extern int of_bsn_tlv_eth_dst_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_eth_dst_t *obj, int value);
extern int of_bsn_tlv_eth_dst_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_eth_dst_t *obj, int value);

extern int of_bsn_tlv_eth_src_OF_VERSION_1_3_populate(
    of_bsn_tlv_eth_src_t *obj, int value);
extern int of_bsn_tlv_eth_src_OF_VERSION_1_3_check(
    of_bsn_tlv_eth_src_t *obj, int value);
extern int of_bsn_tlv_eth_src_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_eth_src_t *obj, int value);
extern int of_bsn_tlv_eth_src_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_eth_src_t *obj, int value);

extern int of_bsn_tlv_eth_type_OF_VERSION_1_3_populate(
    of_bsn_tlv_eth_type_t *obj, int value);
extern int of_bsn_tlv_eth_type_OF_VERSION_1_3_check(
    of_bsn_tlv_eth_type_t *obj, int value);
extern int of_bsn_tlv_eth_type_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_eth_type_t *obj, int value);
extern int of_bsn_tlv_eth_type_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_eth_type_t *obj, int value);

extern int of_bsn_tlv_external_gateway_ip_OF_VERSION_1_3_populate(
    of_bsn_tlv_external_gateway_ip_t *obj, int value);
extern int of_bsn_tlv_external_gateway_ip_OF_VERSION_1_3_check(
    of_bsn_tlv_external_gateway_ip_t *obj, int value);
extern int of_bsn_tlv_external_gateway_ip_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_external_gateway_ip_t *obj, int value);
extern int of_bsn_tlv_external_gateway_ip_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_external_gateway_ip_t *obj, int value);

extern int of_bsn_tlv_external_gateway_mac_OF_VERSION_1_3_populate(
    of_bsn_tlv_external_gateway_mac_t *obj, int value);
extern int of_bsn_tlv_external_gateway_mac_OF_VERSION_1_3_check(
    of_bsn_tlv_external_gateway_mac_t *obj, int value);
extern int of_bsn_tlv_external_gateway_mac_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_external_gateway_mac_t *obj, int value);
extern int of_bsn_tlv_external_gateway_mac_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_external_gateway_mac_t *obj, int value);

extern int of_bsn_tlv_external_ip_OF_VERSION_1_3_populate(
    of_bsn_tlv_external_ip_t *obj, int value);
extern int of_bsn_tlv_external_ip_OF_VERSION_1_3_check(
    of_bsn_tlv_external_ip_t *obj, int value);
extern int of_bsn_tlv_external_ip_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_external_ip_t *obj, int value);
extern int of_bsn_tlv_external_ip_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_external_ip_t *obj, int value);

extern int of_bsn_tlv_external_mac_OF_VERSION_1_3_populate(
    of_bsn_tlv_external_mac_t *obj, int value);
extern int of_bsn_tlv_external_mac_OF_VERSION_1_3_check(
    of_bsn_tlv_external_mac_t *obj, int value);
extern int of_bsn_tlv_external_mac_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_external_mac_t *obj, int value);
extern int of_bsn_tlv_external_mac_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_external_mac_t *obj, int value);

extern int of_bsn_tlv_external_netmask_OF_VERSION_1_3_populate(
    of_bsn_tlv_external_netmask_t *obj, int value);
extern int of_bsn_tlv_external_netmask_OF_VERSION_1_3_check(
    of_bsn_tlv_external_netmask_t *obj, int value);
extern int of_bsn_tlv_external_netmask_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_external_netmask_t *obj, int value);
extern int of_bsn_tlv_external_netmask_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_external_netmask_t *obj, int value);

extern int of_bsn_tlv_force_link_up_OF_VERSION_1_3_populate(
    of_bsn_tlv_force_link_up_t *obj, int value);
extern int of_bsn_tlv_force_link_up_OF_VERSION_1_3_check(
    of_bsn_tlv_force_link_up_t *obj, int value);
extern int of_bsn_tlv_force_link_up_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_force_link_up_t *obj, int value);
extern int of_bsn_tlv_force_link_up_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_force_link_up_t *obj, int value);

extern int of_bsn_tlv_forward_error_correction_OF_VERSION_1_3_populate(
    of_bsn_tlv_forward_error_correction_t *obj, int value);
extern int of_bsn_tlv_forward_error_correction_OF_VERSION_1_3_check(
    of_bsn_tlv_forward_error_correction_t *obj, int value);
extern int of_bsn_tlv_forward_error_correction_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_forward_error_correction_t *obj, int value);
extern int of_bsn_tlv_forward_error_correction_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_forward_error_correction_t *obj, int value);

extern int of_bsn_tlv_generation_id_OF_VERSION_1_3_populate(
    of_bsn_tlv_generation_id_t *obj, int value);
extern int of_bsn_tlv_generation_id_OF_VERSION_1_3_check(
    of_bsn_tlv_generation_id_t *obj, int value);
extern int of_bsn_tlv_generation_id_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_generation_id_t *obj, int value);
extern int of_bsn_tlv_generation_id_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_generation_id_t *obj, int value);

extern int of_bsn_tlv_hash_algorithm_OF_VERSION_1_3_populate(
    of_bsn_tlv_hash_algorithm_t *obj, int value);
extern int of_bsn_tlv_hash_algorithm_OF_VERSION_1_3_check(
    of_bsn_tlv_hash_algorithm_t *obj, int value);
extern int of_bsn_tlv_hash_algorithm_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_hash_algorithm_t *obj, int value);
extern int of_bsn_tlv_hash_algorithm_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_hash_algorithm_t *obj, int value);

extern int of_bsn_tlv_hash_gtp_header_match_OF_VERSION_1_3_populate(
    of_bsn_tlv_hash_gtp_header_match_t *obj, int value);
extern int of_bsn_tlv_hash_gtp_header_match_OF_VERSION_1_3_check(
    of_bsn_tlv_hash_gtp_header_match_t *obj, int value);
extern int of_bsn_tlv_hash_gtp_header_match_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_hash_gtp_header_match_t *obj, int value);
extern int of_bsn_tlv_hash_gtp_header_match_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_hash_gtp_header_match_t *obj, int value);

extern int of_bsn_tlv_hash_gtp_port_match_OF_VERSION_1_3_populate(
    of_bsn_tlv_hash_gtp_port_match_t *obj, int value);
extern int of_bsn_tlv_hash_gtp_port_match_OF_VERSION_1_3_check(
    of_bsn_tlv_hash_gtp_port_match_t *obj, int value);
extern int of_bsn_tlv_hash_gtp_port_match_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_hash_gtp_port_match_t *obj, int value);
extern int of_bsn_tlv_hash_gtp_port_match_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_hash_gtp_port_match_t *obj, int value);

extern int of_bsn_tlv_hash_packet_field_OF_VERSION_1_3_populate(
    of_bsn_tlv_hash_packet_field_t *obj, int value);
extern int of_bsn_tlv_hash_packet_field_OF_VERSION_1_3_check(
    of_bsn_tlv_hash_packet_field_t *obj, int value);
extern int of_bsn_tlv_hash_packet_field_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_hash_packet_field_t *obj, int value);
extern int of_bsn_tlv_hash_packet_field_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_hash_packet_field_t *obj, int value);

extern int of_bsn_tlv_hash_packet_type_OF_VERSION_1_3_populate(
    of_bsn_tlv_hash_packet_type_t *obj, int value);
extern int of_bsn_tlv_hash_packet_type_OF_VERSION_1_3_check(
    of_bsn_tlv_hash_packet_type_t *obj, int value);
extern int of_bsn_tlv_hash_packet_type_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_hash_packet_type_t *obj, int value);
extern int of_bsn_tlv_hash_packet_type_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_hash_packet_type_t *obj, int value);

extern int of_bsn_tlv_hash_seed_OF_VERSION_1_3_populate(
    of_bsn_tlv_hash_seed_t *obj, int value);
extern int of_bsn_tlv_hash_seed_OF_VERSION_1_3_check(
    of_bsn_tlv_hash_seed_t *obj, int value);
extern int of_bsn_tlv_hash_seed_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_hash_seed_t *obj, int value);
extern int of_bsn_tlv_hash_seed_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_hash_seed_t *obj, int value);

extern int of_bsn_tlv_hash_type_OF_VERSION_1_3_populate(
    of_bsn_tlv_hash_type_t *obj, int value);
extern int of_bsn_tlv_hash_type_OF_VERSION_1_3_check(
    of_bsn_tlv_hash_type_t *obj, int value);
extern int of_bsn_tlv_hash_type_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_hash_type_t *obj, int value);
extern int of_bsn_tlv_hash_type_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_hash_type_t *obj, int value);

extern int of_bsn_tlv_header_size_OF_VERSION_1_3_populate(
    of_bsn_tlv_header_size_t *obj, int value);
extern int of_bsn_tlv_header_size_OF_VERSION_1_3_check(
    of_bsn_tlv_header_size_t *obj, int value);
extern int of_bsn_tlv_header_size_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_header_size_t *obj, int value);
extern int of_bsn_tlv_header_size_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_header_size_t *obj, int value);

extern int of_bsn_tlv_icmp_code_OF_VERSION_1_3_populate(
    of_bsn_tlv_icmp_code_t *obj, int value);
extern int of_bsn_tlv_icmp_code_OF_VERSION_1_3_check(
    of_bsn_tlv_icmp_code_t *obj, int value);
extern int of_bsn_tlv_icmp_code_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_icmp_code_t *obj, int value);
extern int of_bsn_tlv_icmp_code_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_icmp_code_t *obj, int value);

extern int of_bsn_tlv_icmp_id_OF_VERSION_1_3_populate(
    of_bsn_tlv_icmp_id_t *obj, int value);
extern int of_bsn_tlv_icmp_id_OF_VERSION_1_3_check(
    of_bsn_tlv_icmp_id_t *obj, int value);
extern int of_bsn_tlv_icmp_id_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_icmp_id_t *obj, int value);
extern int of_bsn_tlv_icmp_id_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_icmp_id_t *obj, int value);

extern int of_bsn_tlv_icmp_type_OF_VERSION_1_3_populate(
    of_bsn_tlv_icmp_type_t *obj, int value);
extern int of_bsn_tlv_icmp_type_OF_VERSION_1_3_check(
    of_bsn_tlv_icmp_type_t *obj, int value);
extern int of_bsn_tlv_icmp_type_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_icmp_type_t *obj, int value);
extern int of_bsn_tlv_icmp_type_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_icmp_type_t *obj, int value);

extern int of_bsn_tlv_icmpv6_chksum_OF_VERSION_1_3_populate(
    of_bsn_tlv_icmpv6_chksum_t *obj, int value);
extern int of_bsn_tlv_icmpv6_chksum_OF_VERSION_1_3_check(
    of_bsn_tlv_icmpv6_chksum_t *obj, int value);
extern int of_bsn_tlv_icmpv6_chksum_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_icmpv6_chksum_t *obj, int value);
extern int of_bsn_tlv_icmpv6_chksum_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_icmpv6_chksum_t *obj, int value);

extern int of_bsn_tlv_idle_notification_OF_VERSION_1_3_populate(
    of_bsn_tlv_idle_notification_t *obj, int value);
extern int of_bsn_tlv_idle_notification_OF_VERSION_1_3_check(
    of_bsn_tlv_idle_notification_t *obj, int value);
extern int of_bsn_tlv_idle_notification_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_idle_notification_t *obj, int value);
extern int of_bsn_tlv_idle_notification_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_idle_notification_t *obj, int value);

extern int of_bsn_tlv_idle_time_OF_VERSION_1_3_populate(
    of_bsn_tlv_idle_time_t *obj, int value);
extern int of_bsn_tlv_idle_time_OF_VERSION_1_3_check(
    of_bsn_tlv_idle_time_t *obj, int value);
extern int of_bsn_tlv_idle_time_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_idle_time_t *obj, int value);
extern int of_bsn_tlv_idle_time_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_idle_time_t *obj, int value);

extern int of_bsn_tlv_idle_timeout_OF_VERSION_1_3_populate(
    of_bsn_tlv_idle_timeout_t *obj, int value);
extern int of_bsn_tlv_idle_timeout_OF_VERSION_1_3_check(
    of_bsn_tlv_idle_timeout_t *obj, int value);
extern int of_bsn_tlv_idle_timeout_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_idle_timeout_t *obj, int value);
extern int of_bsn_tlv_idle_timeout_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_idle_timeout_t *obj, int value);

extern int of_bsn_tlv_igmp_snooping_OF_VERSION_1_3_populate(
    of_bsn_tlv_igmp_snooping_t *obj, int value);
extern int of_bsn_tlv_igmp_snooping_OF_VERSION_1_3_check(
    of_bsn_tlv_igmp_snooping_t *obj, int value);
extern int of_bsn_tlv_igmp_snooping_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_igmp_snooping_t *obj, int value);
extern int of_bsn_tlv_igmp_snooping_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_igmp_snooping_t *obj, int value);

extern int of_bsn_tlv_ingress_port_group_id_OF_VERSION_1_3_populate(
    of_bsn_tlv_ingress_port_group_id_t *obj, int value);
extern int of_bsn_tlv_ingress_port_group_id_OF_VERSION_1_3_check(
    of_bsn_tlv_ingress_port_group_id_t *obj, int value);
extern int of_bsn_tlv_ingress_port_group_id_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_ingress_port_group_id_t *obj, int value);
extern int of_bsn_tlv_ingress_port_group_id_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_ingress_port_group_id_t *obj, int value);

extern int of_bsn_tlv_internal_gateway_mac_OF_VERSION_1_3_populate(
    of_bsn_tlv_internal_gateway_mac_t *obj, int value);
extern int of_bsn_tlv_internal_gateway_mac_OF_VERSION_1_3_check(
    of_bsn_tlv_internal_gateway_mac_t *obj, int value);
extern int of_bsn_tlv_internal_gateway_mac_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_internal_gateway_mac_t *obj, int value);
extern int of_bsn_tlv_internal_gateway_mac_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_internal_gateway_mac_t *obj, int value);

extern int of_bsn_tlv_internal_mac_OF_VERSION_1_3_populate(
    of_bsn_tlv_internal_mac_t *obj, int value);
extern int of_bsn_tlv_internal_mac_OF_VERSION_1_3_check(
    of_bsn_tlv_internal_mac_t *obj, int value);
extern int of_bsn_tlv_internal_mac_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_internal_mac_t *obj, int value);
extern int of_bsn_tlv_internal_mac_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_internal_mac_t *obj, int value);

extern int of_bsn_tlv_interval_OF_VERSION_1_3_populate(
    of_bsn_tlv_interval_t *obj, int value);
extern int of_bsn_tlv_interval_OF_VERSION_1_3_check(
    of_bsn_tlv_interval_t *obj, int value);
extern int of_bsn_tlv_interval_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_interval_t *obj, int value);
extern int of_bsn_tlv_interval_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_interval_t *obj, int value);

extern int of_bsn_tlv_ip_proto_OF_VERSION_1_3_populate(
    of_bsn_tlv_ip_proto_t *obj, int value);
extern int of_bsn_tlv_ip_proto_OF_VERSION_1_3_check(
    of_bsn_tlv_ip_proto_t *obj, int value);
extern int of_bsn_tlv_ip_proto_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_ip_proto_t *obj, int value);
extern int of_bsn_tlv_ip_proto_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_ip_proto_t *obj, int value);

extern int of_bsn_tlv_ipv4_OF_VERSION_1_3_populate(
    of_bsn_tlv_ipv4_t *obj, int value);
extern int of_bsn_tlv_ipv4_OF_VERSION_1_3_check(
    of_bsn_tlv_ipv4_t *obj, int value);
extern int of_bsn_tlv_ipv4_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_ipv4_t *obj, int value);
extern int of_bsn_tlv_ipv4_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_ipv4_t *obj, int value);

extern int of_bsn_tlv_ipv4_dst_OF_VERSION_1_3_populate(
    of_bsn_tlv_ipv4_dst_t *obj, int value);
extern int of_bsn_tlv_ipv4_dst_OF_VERSION_1_3_check(
    of_bsn_tlv_ipv4_dst_t *obj, int value);
extern int of_bsn_tlv_ipv4_dst_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_ipv4_dst_t *obj, int value);
extern int of_bsn_tlv_ipv4_dst_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_ipv4_dst_t *obj, int value);

extern int of_bsn_tlv_ipv4_netmask_OF_VERSION_1_3_populate(
    of_bsn_tlv_ipv4_netmask_t *obj, int value);
extern int of_bsn_tlv_ipv4_netmask_OF_VERSION_1_3_check(
    of_bsn_tlv_ipv4_netmask_t *obj, int value);
extern int of_bsn_tlv_ipv4_netmask_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_ipv4_netmask_t *obj, int value);
extern int of_bsn_tlv_ipv4_netmask_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_ipv4_netmask_t *obj, int value);

extern int of_bsn_tlv_ipv4_src_OF_VERSION_1_3_populate(
    of_bsn_tlv_ipv4_src_t *obj, int value);
extern int of_bsn_tlv_ipv4_src_OF_VERSION_1_3_check(
    of_bsn_tlv_ipv4_src_t *obj, int value);
extern int of_bsn_tlv_ipv4_src_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_ipv4_src_t *obj, int value);
extern int of_bsn_tlv_ipv4_src_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_ipv4_src_t *obj, int value);

extern int of_bsn_tlv_ipv6_OF_VERSION_1_3_populate(
    of_bsn_tlv_ipv6_t *obj, int value);
extern int of_bsn_tlv_ipv6_OF_VERSION_1_3_check(
    of_bsn_tlv_ipv6_t *obj, int value);
extern int of_bsn_tlv_ipv6_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_ipv6_t *obj, int value);
extern int of_bsn_tlv_ipv6_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_ipv6_t *obj, int value);

extern int of_bsn_tlv_ipv6_dst_OF_VERSION_1_3_populate(
    of_bsn_tlv_ipv6_dst_t *obj, int value);
extern int of_bsn_tlv_ipv6_dst_OF_VERSION_1_3_check(
    of_bsn_tlv_ipv6_dst_t *obj, int value);
extern int of_bsn_tlv_ipv6_dst_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_ipv6_dst_t *obj, int value);
extern int of_bsn_tlv_ipv6_dst_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_ipv6_dst_t *obj, int value);

extern int of_bsn_tlv_ipv6_prefix_OF_VERSION_1_3_populate(
    of_bsn_tlv_ipv6_prefix_t *obj, int value);
extern int of_bsn_tlv_ipv6_prefix_OF_VERSION_1_3_check(
    of_bsn_tlv_ipv6_prefix_t *obj, int value);
extern int of_bsn_tlv_ipv6_prefix_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_ipv6_prefix_t *obj, int value);
extern int of_bsn_tlv_ipv6_prefix_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_ipv6_prefix_t *obj, int value);

extern int of_bsn_tlv_ipv6_src_OF_VERSION_1_3_populate(
    of_bsn_tlv_ipv6_src_t *obj, int value);
extern int of_bsn_tlv_ipv6_src_OF_VERSION_1_3_check(
    of_bsn_tlv_ipv6_src_t *obj, int value);
extern int of_bsn_tlv_ipv6_src_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_ipv6_src_t *obj, int value);
extern int of_bsn_tlv_ipv6_src_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_ipv6_src_t *obj, int value);

extern int of_bsn_tlv_known_multicast_rate_OF_VERSION_1_3_populate(
    of_bsn_tlv_known_multicast_rate_t *obj, int value);
extern int of_bsn_tlv_known_multicast_rate_OF_VERSION_1_3_check(
    of_bsn_tlv_known_multicast_rate_t *obj, int value);
extern int of_bsn_tlv_known_multicast_rate_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_known_multicast_rate_t *obj, int value);
extern int of_bsn_tlv_known_multicast_rate_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_known_multicast_rate_t *obj, int value);

extern int of_bsn_tlv_l2_multicast_lookup_OF_VERSION_1_3_populate(
    of_bsn_tlv_l2_multicast_lookup_t *obj, int value);
extern int of_bsn_tlv_l2_multicast_lookup_OF_VERSION_1_3_check(
    of_bsn_tlv_l2_multicast_lookup_t *obj, int value);
extern int of_bsn_tlv_l2_multicast_lookup_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_l2_multicast_lookup_t *obj, int value);
extern int of_bsn_tlv_l2_multicast_lookup_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_l2_multicast_lookup_t *obj, int value);

extern int of_bsn_tlv_l3_dst_class_id_OF_VERSION_1_3_populate(
    of_bsn_tlv_l3_dst_class_id_t *obj, int value);
extern int of_bsn_tlv_l3_dst_class_id_OF_VERSION_1_3_check(
    of_bsn_tlv_l3_dst_class_id_t *obj, int value);
extern int of_bsn_tlv_l3_dst_class_id_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_l3_dst_class_id_t *obj, int value);
extern int of_bsn_tlv_l3_dst_class_id_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_l3_dst_class_id_t *obj, int value);

extern int of_bsn_tlv_l3_interface_class_id_OF_VERSION_1_3_populate(
    of_bsn_tlv_l3_interface_class_id_t *obj, int value);
extern int of_bsn_tlv_l3_interface_class_id_OF_VERSION_1_3_check(
    of_bsn_tlv_l3_interface_class_id_t *obj, int value);
extern int of_bsn_tlv_l3_interface_class_id_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_l3_interface_class_id_t *obj, int value);
extern int of_bsn_tlv_l3_interface_class_id_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_l3_interface_class_id_t *obj, int value);

extern int of_bsn_tlv_l3_src_class_id_OF_VERSION_1_3_populate(
    of_bsn_tlv_l3_src_class_id_t *obj, int value);
extern int of_bsn_tlv_l3_src_class_id_OF_VERSION_1_3_check(
    of_bsn_tlv_l3_src_class_id_t *obj, int value);
extern int of_bsn_tlv_l3_src_class_id_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_l3_src_class_id_t *obj, int value);
extern int of_bsn_tlv_l3_src_class_id_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_l3_src_class_id_t *obj, int value);

extern int of_bsn_tlv_lag_options_OF_VERSION_1_3_populate(
    of_bsn_tlv_lag_options_t *obj, int value);
extern int of_bsn_tlv_lag_options_OF_VERSION_1_3_check(
    of_bsn_tlv_lag_options_t *obj, int value);
extern int of_bsn_tlv_lag_options_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_lag_options_t *obj, int value);
extern int of_bsn_tlv_lag_options_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_lag_options_t *obj, int value);

extern int of_bsn_tlv_loopback_mode_OF_VERSION_1_3_populate(
    of_bsn_tlv_loopback_mode_t *obj, int value);
extern int of_bsn_tlv_loopback_mode_OF_VERSION_1_3_check(
    of_bsn_tlv_loopback_mode_t *obj, int value);
extern int of_bsn_tlv_loopback_mode_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_loopback_mode_t *obj, int value);
extern int of_bsn_tlv_loopback_mode_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_loopback_mode_t *obj, int value);

extern int of_bsn_tlv_loopback_port_OF_VERSION_1_3_populate(
    of_bsn_tlv_loopback_port_t *obj, int value);
extern int of_bsn_tlv_loopback_port_OF_VERSION_1_3_check(
    of_bsn_tlv_loopback_port_t *obj, int value);
extern int of_bsn_tlv_loopback_port_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_loopback_port_t *obj, int value);
extern int of_bsn_tlv_loopback_port_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_loopback_port_t *obj, int value);

extern int of_bsn_tlv_mac_OF_VERSION_1_3_populate(
    of_bsn_tlv_mac_t *obj, int value);
extern int of_bsn_tlv_mac_OF_VERSION_1_3_check(
    of_bsn_tlv_mac_t *obj, int value);
extern int of_bsn_tlv_mac_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_mac_t *obj, int value);
extern int of_bsn_tlv_mac_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_mac_t *obj, int value);

extern int of_bsn_tlv_mac_mask_OF_VERSION_1_3_populate(
    of_bsn_tlv_mac_mask_t *obj, int value);
extern int of_bsn_tlv_mac_mask_OF_VERSION_1_3_check(
    of_bsn_tlv_mac_mask_t *obj, int value);
extern int of_bsn_tlv_mac_mask_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_mac_mask_t *obj, int value);
extern int of_bsn_tlv_mac_mask_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_mac_mask_t *obj, int value);

extern int of_bsn_tlv_mcg_type_vxlan_OF_VERSION_1_3_populate(
    of_bsn_tlv_mcg_type_vxlan_t *obj, int value);
extern int of_bsn_tlv_mcg_type_vxlan_OF_VERSION_1_3_check(
    of_bsn_tlv_mcg_type_vxlan_t *obj, int value);
extern int of_bsn_tlv_mcg_type_vxlan_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_mcg_type_vxlan_t *obj, int value);
extern int of_bsn_tlv_mcg_type_vxlan_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_mcg_type_vxlan_t *obj, int value);

extern int of_bsn_tlv_miss_packets_OF_VERSION_1_3_populate(
    of_bsn_tlv_miss_packets_t *obj, int value);
extern int of_bsn_tlv_miss_packets_OF_VERSION_1_3_check(
    of_bsn_tlv_miss_packets_t *obj, int value);
extern int of_bsn_tlv_miss_packets_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_miss_packets_t *obj, int value);
extern int of_bsn_tlv_miss_packets_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_miss_packets_t *obj, int value);

extern int of_bsn_tlv_mpls_control_word_OF_VERSION_1_3_populate(
    of_bsn_tlv_mpls_control_word_t *obj, int value);
extern int of_bsn_tlv_mpls_control_word_OF_VERSION_1_3_check(
    of_bsn_tlv_mpls_control_word_t *obj, int value);
extern int of_bsn_tlv_mpls_control_word_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_mpls_control_word_t *obj, int value);
extern int of_bsn_tlv_mpls_control_word_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_mpls_control_word_t *obj, int value);

extern int of_bsn_tlv_mpls_label_OF_VERSION_1_3_populate(
    of_bsn_tlv_mpls_label_t *obj, int value);
extern int of_bsn_tlv_mpls_label_OF_VERSION_1_3_check(
    of_bsn_tlv_mpls_label_t *obj, int value);
extern int of_bsn_tlv_mpls_label_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_mpls_label_t *obj, int value);
extern int of_bsn_tlv_mpls_label_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_mpls_label_t *obj, int value);

extern int of_bsn_tlv_mpls_sequenced_OF_VERSION_1_3_populate(
    of_bsn_tlv_mpls_sequenced_t *obj, int value);
extern int of_bsn_tlv_mpls_sequenced_OF_VERSION_1_3_check(
    of_bsn_tlv_mpls_sequenced_t *obj, int value);
extern int of_bsn_tlv_mpls_sequenced_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_mpls_sequenced_t *obj, int value);
extern int of_bsn_tlv_mpls_sequenced_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_mpls_sequenced_t *obj, int value);

extern int of_bsn_tlv_multicast_interface_id_OF_VERSION_1_3_populate(
    of_bsn_tlv_multicast_interface_id_t *obj, int value);
extern int of_bsn_tlv_multicast_interface_id_OF_VERSION_1_3_check(
    of_bsn_tlv_multicast_interface_id_t *obj, int value);
extern int of_bsn_tlv_multicast_interface_id_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_multicast_interface_id_t *obj, int value);
extern int of_bsn_tlv_multicast_interface_id_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_multicast_interface_id_t *obj, int value);

extern int of_bsn_tlv_name_OF_VERSION_1_3_populate(
    of_bsn_tlv_name_t *obj, int value);
extern int of_bsn_tlv_name_OF_VERSION_1_3_check(
    of_bsn_tlv_name_t *obj, int value);
extern int of_bsn_tlv_name_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_name_t *obj, int value);
extern int of_bsn_tlv_name_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_name_t *obj, int value);

extern int of_bsn_tlv_ndp_offload_OF_VERSION_1_3_populate(
    of_bsn_tlv_ndp_offload_t *obj, int value);
extern int of_bsn_tlv_ndp_offload_OF_VERSION_1_3_check(
    of_bsn_tlv_ndp_offload_t *obj, int value);
extern int of_bsn_tlv_ndp_offload_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_ndp_offload_t *obj, int value);
extern int of_bsn_tlv_ndp_offload_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_ndp_offload_t *obj, int value);

extern int of_bsn_tlv_ndp_static_OF_VERSION_1_3_populate(
    of_bsn_tlv_ndp_static_t *obj, int value);
extern int of_bsn_tlv_ndp_static_OF_VERSION_1_3_check(
    of_bsn_tlv_ndp_static_t *obj, int value);
extern int of_bsn_tlv_ndp_static_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_ndp_static_t *obj, int value);
extern int of_bsn_tlv_ndp_static_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_ndp_static_t *obj, int value);

extern int of_bsn_tlv_negate_OF_VERSION_1_3_populate(
    of_bsn_tlv_negate_t *obj, int value);
extern int of_bsn_tlv_negate_OF_VERSION_1_3_check(
    of_bsn_tlv_negate_t *obj, int value);
extern int of_bsn_tlv_negate_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_negate_t *obj, int value);
extern int of_bsn_tlv_negate_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_negate_t *obj, int value);

extern int of_bsn_tlv_next_hop_ipv4_OF_VERSION_1_3_populate(
    of_bsn_tlv_next_hop_ipv4_t *obj, int value);
extern int of_bsn_tlv_next_hop_ipv4_OF_VERSION_1_3_check(
    of_bsn_tlv_next_hop_ipv4_t *obj, int value);
extern int of_bsn_tlv_next_hop_ipv4_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_next_hop_ipv4_t *obj, int value);
extern int of_bsn_tlv_next_hop_ipv4_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_next_hop_ipv4_t *obj, int value);

extern int of_bsn_tlv_next_hop_mac_OF_VERSION_1_3_populate(
    of_bsn_tlv_next_hop_mac_t *obj, int value);
extern int of_bsn_tlv_next_hop_mac_OF_VERSION_1_3_check(
    of_bsn_tlv_next_hop_mac_t *obj, int value);
extern int of_bsn_tlv_next_hop_mac_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_next_hop_mac_t *obj, int value);
extern int of_bsn_tlv_next_hop_mac_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_next_hop_mac_t *obj, int value);

extern int of_bsn_tlv_nexthop_type_vxlan_OF_VERSION_1_3_populate(
    of_bsn_tlv_nexthop_type_vxlan_t *obj, int value);
extern int of_bsn_tlv_nexthop_type_vxlan_OF_VERSION_1_3_check(
    of_bsn_tlv_nexthop_type_vxlan_t *obj, int value);
extern int of_bsn_tlv_nexthop_type_vxlan_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_nexthop_type_vxlan_t *obj, int value);
extern int of_bsn_tlv_nexthop_type_vxlan_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_nexthop_type_vxlan_t *obj, int value);

extern int of_bsn_tlv_no_arp_response_OF_VERSION_1_3_populate(
    of_bsn_tlv_no_arp_response_t *obj, int value);
extern int of_bsn_tlv_no_arp_response_OF_VERSION_1_3_check(
    of_bsn_tlv_no_arp_response_t *obj, int value);
extern int of_bsn_tlv_no_arp_response_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_no_arp_response_t *obj, int value);
extern int of_bsn_tlv_no_arp_response_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_no_arp_response_t *obj, int value);

extern int of_bsn_tlv_no_ns_response_OF_VERSION_1_3_populate(
    of_bsn_tlv_no_ns_response_t *obj, int value);
extern int of_bsn_tlv_no_ns_response_OF_VERSION_1_3_check(
    of_bsn_tlv_no_ns_response_t *obj, int value);
extern int of_bsn_tlv_no_ns_response_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_no_ns_response_t *obj, int value);
extern int of_bsn_tlv_no_ns_response_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_no_ns_response_t *obj, int value);

extern int of_bsn_tlv_offset_OF_VERSION_1_3_populate(
    of_bsn_tlv_offset_t *obj, int value);
extern int of_bsn_tlv_offset_OF_VERSION_1_3_check(
    of_bsn_tlv_offset_t *obj, int value);
extern int of_bsn_tlv_offset_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_offset_t *obj, int value);
extern int of_bsn_tlv_offset_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_offset_t *obj, int value);

extern int of_bsn_tlv_optics_always_enabled_OF_VERSION_1_3_populate(
    of_bsn_tlv_optics_always_enabled_t *obj, int value);
extern int of_bsn_tlv_optics_always_enabled_OF_VERSION_1_3_check(
    of_bsn_tlv_optics_always_enabled_t *obj, int value);
extern int of_bsn_tlv_optics_always_enabled_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_optics_always_enabled_t *obj, int value);
extern int of_bsn_tlv_optics_always_enabled_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_optics_always_enabled_t *obj, int value);

extern int of_bsn_tlv_outer_src_mac_OF_VERSION_1_3_populate(
    of_bsn_tlv_outer_src_mac_t *obj, int value);
extern int of_bsn_tlv_outer_src_mac_OF_VERSION_1_3_check(
    of_bsn_tlv_outer_src_mac_t *obj, int value);
extern int of_bsn_tlv_outer_src_mac_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_outer_src_mac_t *obj, int value);
extern int of_bsn_tlv_outer_src_mac_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_outer_src_mac_t *obj, int value);

extern int of_bsn_tlv_parent_port_OF_VERSION_1_3_populate(
    of_bsn_tlv_parent_port_t *obj, int value);
extern int of_bsn_tlv_parent_port_OF_VERSION_1_3_check(
    of_bsn_tlv_parent_port_t *obj, int value);
extern int of_bsn_tlv_parent_port_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_parent_port_t *obj, int value);
extern int of_bsn_tlv_parent_port_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_parent_port_t *obj, int value);

extern int of_bsn_tlv_partner_key_OF_VERSION_1_3_populate(
    of_bsn_tlv_partner_key_t *obj, int value);
extern int of_bsn_tlv_partner_key_OF_VERSION_1_3_check(
    of_bsn_tlv_partner_key_t *obj, int value);
extern int of_bsn_tlv_partner_key_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_partner_key_t *obj, int value);
extern int of_bsn_tlv_partner_key_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_partner_key_t *obj, int value);

extern int of_bsn_tlv_partner_port_num_OF_VERSION_1_3_populate(
    of_bsn_tlv_partner_port_num_t *obj, int value);
extern int of_bsn_tlv_partner_port_num_OF_VERSION_1_3_check(
    of_bsn_tlv_partner_port_num_t *obj, int value);
extern int of_bsn_tlv_partner_port_num_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_partner_port_num_t *obj, int value);
extern int of_bsn_tlv_partner_port_num_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_partner_port_num_t *obj, int value);

extern int of_bsn_tlv_partner_port_priority_OF_VERSION_1_3_populate(
    of_bsn_tlv_partner_port_priority_t *obj, int value);
extern int of_bsn_tlv_partner_port_priority_OF_VERSION_1_3_check(
    of_bsn_tlv_partner_port_priority_t *obj, int value);
extern int of_bsn_tlv_partner_port_priority_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_partner_port_priority_t *obj, int value);
extern int of_bsn_tlv_partner_port_priority_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_partner_port_priority_t *obj, int value);

extern int of_bsn_tlv_partner_state_OF_VERSION_1_3_populate(
    of_bsn_tlv_partner_state_t *obj, int value);
extern int of_bsn_tlv_partner_state_OF_VERSION_1_3_check(
    of_bsn_tlv_partner_state_t *obj, int value);
extern int of_bsn_tlv_partner_state_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_partner_state_t *obj, int value);
extern int of_bsn_tlv_partner_state_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_partner_state_t *obj, int value);

extern int of_bsn_tlv_partner_system_mac_OF_VERSION_1_3_populate(
    of_bsn_tlv_partner_system_mac_t *obj, int value);
extern int of_bsn_tlv_partner_system_mac_OF_VERSION_1_3_check(
    of_bsn_tlv_partner_system_mac_t *obj, int value);
extern int of_bsn_tlv_partner_system_mac_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_partner_system_mac_t *obj, int value);
extern int of_bsn_tlv_partner_system_mac_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_partner_system_mac_t *obj, int value);

extern int of_bsn_tlv_partner_system_priority_OF_VERSION_1_3_populate(
    of_bsn_tlv_partner_system_priority_t *obj, int value);
extern int of_bsn_tlv_partner_system_priority_OF_VERSION_1_3_check(
    of_bsn_tlv_partner_system_priority_t *obj, int value);
extern int of_bsn_tlv_partner_system_priority_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_partner_system_priority_t *obj, int value);
extern int of_bsn_tlv_partner_system_priority_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_partner_system_priority_t *obj, int value);

extern int of_bsn_tlv_pdua_rx_instance_OF_VERSION_1_3_populate(
    of_bsn_tlv_pdua_rx_instance_t *obj, int value);
extern int of_bsn_tlv_pdua_rx_instance_OF_VERSION_1_3_check(
    of_bsn_tlv_pdua_rx_instance_t *obj, int value);
extern int of_bsn_tlv_pdua_rx_instance_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_pdua_rx_instance_t *obj, int value);
extern int of_bsn_tlv_pdua_rx_instance_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_pdua_rx_instance_t *obj, int value);

extern int of_bsn_tlv_port_OF_VERSION_1_3_populate(
    of_bsn_tlv_port_t *obj, int value);
extern int of_bsn_tlv_port_OF_VERSION_1_3_check(
    of_bsn_tlv_port_t *obj, int value);
extern int of_bsn_tlv_port_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_port_t *obj, int value);
extern int of_bsn_tlv_port_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_port_t *obj, int value);

extern int of_bsn_tlv_port_speed_gbps_OF_VERSION_1_3_populate(
    of_bsn_tlv_port_speed_gbps_t *obj, int value);
extern int of_bsn_tlv_port_speed_gbps_OF_VERSION_1_3_check(
    of_bsn_tlv_port_speed_gbps_t *obj, int value);
extern int of_bsn_tlv_port_speed_gbps_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_port_speed_gbps_t *obj, int value);
extern int of_bsn_tlv_port_speed_gbps_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_port_speed_gbps_t *obj, int value);

extern int of_bsn_tlv_port_usage_OF_VERSION_1_3_populate(
    of_bsn_tlv_port_usage_t *obj, int value);
extern int of_bsn_tlv_port_usage_OF_VERSION_1_3_check(
    of_bsn_tlv_port_usage_t *obj, int value);
extern int of_bsn_tlv_port_usage_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_port_usage_t *obj, int value);
extern int of_bsn_tlv_port_usage_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_port_usage_t *obj, int value);

extern int of_bsn_tlv_port_vxlan_mode_OF_VERSION_1_3_populate(
    of_bsn_tlv_port_vxlan_mode_t *obj, int value);
extern int of_bsn_tlv_port_vxlan_mode_OF_VERSION_1_3_check(
    of_bsn_tlv_port_vxlan_mode_t *obj, int value);
extern int of_bsn_tlv_port_vxlan_mode_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_port_vxlan_mode_t *obj, int value);
extern int of_bsn_tlv_port_vxlan_mode_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_port_vxlan_mode_t *obj, int value);

extern int of_bsn_tlv_priority_OF_VERSION_1_3_populate(
    of_bsn_tlv_priority_t *obj, int value);
extern int of_bsn_tlv_priority_OF_VERSION_1_3_check(
    of_bsn_tlv_priority_t *obj, int value);
extern int of_bsn_tlv_priority_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_priority_t *obj, int value);
extern int of_bsn_tlv_priority_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_priority_t *obj, int value);

extern int of_bsn_tlv_push_vlan_on_ingress_OF_VERSION_1_3_populate(
    of_bsn_tlv_push_vlan_on_ingress_t *obj, int value);
extern int of_bsn_tlv_push_vlan_on_ingress_OF_VERSION_1_3_check(
    of_bsn_tlv_push_vlan_on_ingress_t *obj, int value);
extern int of_bsn_tlv_push_vlan_on_ingress_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_push_vlan_on_ingress_t *obj, int value);
extern int of_bsn_tlv_push_vlan_on_ingress_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_push_vlan_on_ingress_t *obj, int value);

extern int of_bsn_tlv_qos_priority_OF_VERSION_1_3_populate(
    of_bsn_tlv_qos_priority_t *obj, int value);
extern int of_bsn_tlv_qos_priority_OF_VERSION_1_3_check(
    of_bsn_tlv_qos_priority_t *obj, int value);
extern int of_bsn_tlv_qos_priority_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_qos_priority_t *obj, int value);
extern int of_bsn_tlv_qos_priority_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_qos_priority_t *obj, int value);

extern int of_bsn_tlv_queue_id_OF_VERSION_1_3_populate(
    of_bsn_tlv_queue_id_t *obj, int value);
extern int of_bsn_tlv_queue_id_OF_VERSION_1_3_check(
    of_bsn_tlv_queue_id_t *obj, int value);
extern int of_bsn_tlv_queue_id_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_queue_id_t *obj, int value);
extern int of_bsn_tlv_queue_id_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_queue_id_t *obj, int value);

extern int of_bsn_tlv_queue_weight_OF_VERSION_1_3_populate(
    of_bsn_tlv_queue_weight_t *obj, int value);
extern int of_bsn_tlv_queue_weight_OF_VERSION_1_3_check(
    of_bsn_tlv_queue_weight_t *obj, int value);
extern int of_bsn_tlv_queue_weight_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_queue_weight_t *obj, int value);
extern int of_bsn_tlv_queue_weight_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_queue_weight_t *obj, int value);

extern int of_bsn_tlv_rate_limit_OF_VERSION_1_3_populate(
    of_bsn_tlv_rate_limit_t *obj, int value);
extern int of_bsn_tlv_rate_limit_OF_VERSION_1_3_check(
    of_bsn_tlv_rate_limit_t *obj, int value);
extern int of_bsn_tlv_rate_limit_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_rate_limit_t *obj, int value);
extern int of_bsn_tlv_rate_limit_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_rate_limit_t *obj, int value);

extern int of_bsn_tlv_rate_unit_OF_VERSION_1_3_populate(
    of_bsn_tlv_rate_unit_t *obj, int value);
extern int of_bsn_tlv_rate_unit_OF_VERSION_1_3_check(
    of_bsn_tlv_rate_unit_t *obj, int value);
extern int of_bsn_tlv_rate_unit_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_rate_unit_t *obj, int value);
extern int of_bsn_tlv_rate_unit_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_rate_unit_t *obj, int value);

extern int of_bsn_tlv_record_packets_OF_VERSION_1_3_populate(
    of_bsn_tlv_record_packets_t *obj, int value);
extern int of_bsn_tlv_record_packets_OF_VERSION_1_3_check(
    of_bsn_tlv_record_packets_t *obj, int value);
extern int of_bsn_tlv_record_packets_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_record_packets_t *obj, int value);
extern int of_bsn_tlv_record_packets_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_record_packets_t *obj, int value);

extern int of_bsn_tlv_reference_OF_VERSION_1_3_populate(
    of_bsn_tlv_reference_t *obj, int value);
extern int of_bsn_tlv_reference_OF_VERSION_1_3_check(
    of_bsn_tlv_reference_t *obj, int value);
extern int of_bsn_tlv_reference_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_reference_t *obj, int value);
extern int of_bsn_tlv_reference_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_reference_t *obj, int value);

extern int of_bsn_tlv_reply_packets_OF_VERSION_1_3_populate(
    of_bsn_tlv_reply_packets_t *obj, int value);
extern int of_bsn_tlv_reply_packets_OF_VERSION_1_3_check(
    of_bsn_tlv_reply_packets_t *obj, int value);
extern int of_bsn_tlv_reply_packets_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_reply_packets_t *obj, int value);
extern int of_bsn_tlv_reply_packets_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_reply_packets_t *obj, int value);

extern int of_bsn_tlv_request_packets_OF_VERSION_1_3_populate(
    of_bsn_tlv_request_packets_t *obj, int value);
extern int of_bsn_tlv_request_packets_OF_VERSION_1_3_check(
    of_bsn_tlv_request_packets_t *obj, int value);
extern int of_bsn_tlv_request_packets_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_request_packets_t *obj, int value);
extern int of_bsn_tlv_request_packets_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_request_packets_t *obj, int value);

extern int of_bsn_tlv_rest_server_OF_VERSION_1_3_populate(
    of_bsn_tlv_rest_server_t *obj, int value);
extern int of_bsn_tlv_rest_server_OF_VERSION_1_3_check(
    of_bsn_tlv_rest_server_t *obj, int value);
extern int of_bsn_tlv_rest_server_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_rest_server_t *obj, int value);
extern int of_bsn_tlv_rest_server_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_rest_server_t *obj, int value);

extern int of_bsn_tlv_routing_param_OF_VERSION_1_3_populate(
    of_bsn_tlv_routing_param_t *obj, int value);
extern int of_bsn_tlv_routing_param_OF_VERSION_1_3_check(
    of_bsn_tlv_routing_param_t *obj, int value);
extern int of_bsn_tlv_routing_param_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_routing_param_t *obj, int value);
extern int of_bsn_tlv_routing_param_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_routing_param_t *obj, int value);

extern int of_bsn_tlv_rx_bytes_OF_VERSION_1_3_populate(
    of_bsn_tlv_rx_bytes_t *obj, int value);
extern int of_bsn_tlv_rx_bytes_OF_VERSION_1_3_check(
    of_bsn_tlv_rx_bytes_t *obj, int value);
extern int of_bsn_tlv_rx_bytes_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_rx_bytes_t *obj, int value);
extern int of_bsn_tlv_rx_bytes_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_rx_bytes_t *obj, int value);

extern int of_bsn_tlv_rx_packets_OF_VERSION_1_3_populate(
    of_bsn_tlv_rx_packets_t *obj, int value);
extern int of_bsn_tlv_rx_packets_OF_VERSION_1_3_check(
    of_bsn_tlv_rx_packets_t *obj, int value);
extern int of_bsn_tlv_rx_packets_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_rx_packets_t *obj, int value);
extern int of_bsn_tlv_rx_packets_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_rx_packets_t *obj, int value);

extern int of_bsn_tlv_sampling_rate_OF_VERSION_1_3_populate(
    of_bsn_tlv_sampling_rate_t *obj, int value);
extern int of_bsn_tlv_sampling_rate_OF_VERSION_1_3_check(
    of_bsn_tlv_sampling_rate_t *obj, int value);
extern int of_bsn_tlv_sampling_rate_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_sampling_rate_t *obj, int value);
extern int of_bsn_tlv_sampling_rate_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_sampling_rate_t *obj, int value);

extern int of_bsn_tlv_set_loopback_mode_OF_VERSION_1_3_populate(
    of_bsn_tlv_set_loopback_mode_t *obj, int value);
extern int of_bsn_tlv_set_loopback_mode_OF_VERSION_1_3_check(
    of_bsn_tlv_set_loopback_mode_t *obj, int value);
extern int of_bsn_tlv_set_loopback_mode_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_set_loopback_mode_t *obj, int value);
extern int of_bsn_tlv_set_loopback_mode_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_set_loopback_mode_t *obj, int value);

extern int of_bsn_tlv_status_OF_VERSION_1_3_populate(
    of_bsn_tlv_status_t *obj, int value);
extern int of_bsn_tlv_status_OF_VERSION_1_3_check(
    of_bsn_tlv_status_t *obj, int value);
extern int of_bsn_tlv_status_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_status_t *obj, int value);
extern int of_bsn_tlv_status_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_status_t *obj, int value);

extern int of_bsn_tlv_strip_mpls_l2_on_ingress_OF_VERSION_1_3_populate(
    of_bsn_tlv_strip_mpls_l2_on_ingress_t *obj, int value);
extern int of_bsn_tlv_strip_mpls_l2_on_ingress_OF_VERSION_1_3_check(
    of_bsn_tlv_strip_mpls_l2_on_ingress_t *obj, int value);
extern int of_bsn_tlv_strip_mpls_l2_on_ingress_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_strip_mpls_l2_on_ingress_t *obj, int value);
extern int of_bsn_tlv_strip_mpls_l2_on_ingress_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_strip_mpls_l2_on_ingress_t *obj, int value);

extern int of_bsn_tlv_strip_mpls_l3_on_ingress_OF_VERSION_1_3_populate(
    of_bsn_tlv_strip_mpls_l3_on_ingress_t *obj, int value);
extern int of_bsn_tlv_strip_mpls_l3_on_ingress_OF_VERSION_1_3_check(
    of_bsn_tlv_strip_mpls_l3_on_ingress_t *obj, int value);
extern int of_bsn_tlv_strip_mpls_l3_on_ingress_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_strip_mpls_l3_on_ingress_t *obj, int value);
extern int of_bsn_tlv_strip_mpls_l3_on_ingress_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_strip_mpls_l3_on_ingress_t *obj, int value);

extern int of_bsn_tlv_strip_vlan_on_egress_OF_VERSION_1_3_populate(
    of_bsn_tlv_strip_vlan_on_egress_t *obj, int value);
extern int of_bsn_tlv_strip_vlan_on_egress_OF_VERSION_1_3_check(
    of_bsn_tlv_strip_vlan_on_egress_t *obj, int value);
extern int of_bsn_tlv_strip_vlan_on_egress_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_strip_vlan_on_egress_t *obj, int value);
extern int of_bsn_tlv_strip_vlan_on_egress_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_strip_vlan_on_egress_t *obj, int value);

extern int of_bsn_tlv_sub_agent_id_OF_VERSION_1_3_populate(
    of_bsn_tlv_sub_agent_id_t *obj, int value);
extern int of_bsn_tlv_sub_agent_id_OF_VERSION_1_3_check(
    of_bsn_tlv_sub_agent_id_t *obj, int value);
extern int of_bsn_tlv_sub_agent_id_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_sub_agent_id_t *obj, int value);
extern int of_bsn_tlv_sub_agent_id_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_sub_agent_id_t *obj, int value);

extern int of_bsn_tlv_tcp_dst_OF_VERSION_1_3_populate(
    of_bsn_tlv_tcp_dst_t *obj, int value);
extern int of_bsn_tlv_tcp_dst_OF_VERSION_1_3_check(
    of_bsn_tlv_tcp_dst_t *obj, int value);
extern int of_bsn_tlv_tcp_dst_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_tcp_dst_t *obj, int value);
extern int of_bsn_tlv_tcp_dst_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_tcp_dst_t *obj, int value);

extern int of_bsn_tlv_tcp_flags_OF_VERSION_1_3_populate(
    of_bsn_tlv_tcp_flags_t *obj, int value);
extern int of_bsn_tlv_tcp_flags_OF_VERSION_1_3_check(
    of_bsn_tlv_tcp_flags_t *obj, int value);
extern int of_bsn_tlv_tcp_flags_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_tcp_flags_t *obj, int value);
extern int of_bsn_tlv_tcp_flags_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_tcp_flags_t *obj, int value);

extern int of_bsn_tlv_tcp_src_OF_VERSION_1_3_populate(
    of_bsn_tlv_tcp_src_t *obj, int value);
extern int of_bsn_tlv_tcp_src_OF_VERSION_1_3_check(
    of_bsn_tlv_tcp_src_t *obj, int value);
extern int of_bsn_tlv_tcp_src_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_tcp_src_t *obj, int value);
extern int of_bsn_tlv_tcp_src_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_tcp_src_t *obj, int value);

extern int of_bsn_tlv_timestamp_OF_VERSION_1_3_populate(
    of_bsn_tlv_timestamp_t *obj, int value);
extern int of_bsn_tlv_timestamp_OF_VERSION_1_3_check(
    of_bsn_tlv_timestamp_t *obj, int value);
extern int of_bsn_tlv_timestamp_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_timestamp_t *obj, int value);
extern int of_bsn_tlv_timestamp_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_timestamp_t *obj, int value);

extern int of_bsn_tlv_ttl_OF_VERSION_1_3_populate(
    of_bsn_tlv_ttl_t *obj, int value);
extern int of_bsn_tlv_ttl_OF_VERSION_1_3_check(
    of_bsn_tlv_ttl_t *obj, int value);
extern int of_bsn_tlv_ttl_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_ttl_t *obj, int value);
extern int of_bsn_tlv_ttl_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_ttl_t *obj, int value);

extern int of_bsn_tlv_tunnel_capability_OF_VERSION_1_3_populate(
    of_bsn_tlv_tunnel_capability_t *obj, int value);
extern int of_bsn_tlv_tunnel_capability_OF_VERSION_1_3_check(
    of_bsn_tlv_tunnel_capability_t *obj, int value);
extern int of_bsn_tlv_tunnel_capability_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_tunnel_capability_t *obj, int value);
extern int of_bsn_tlv_tunnel_capability_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_tunnel_capability_t *obj, int value);

extern int of_bsn_tlv_tx_bytes_OF_VERSION_1_3_populate(
    of_bsn_tlv_tx_bytes_t *obj, int value);
extern int of_bsn_tlv_tx_bytes_OF_VERSION_1_3_check(
    of_bsn_tlv_tx_bytes_t *obj, int value);
extern int of_bsn_tlv_tx_bytes_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_tx_bytes_t *obj, int value);
extern int of_bsn_tlv_tx_bytes_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_tx_bytes_t *obj, int value);

extern int of_bsn_tlv_tx_packets_OF_VERSION_1_3_populate(
    of_bsn_tlv_tx_packets_t *obj, int value);
extern int of_bsn_tlv_tx_packets_OF_VERSION_1_3_check(
    of_bsn_tlv_tx_packets_t *obj, int value);
extern int of_bsn_tlv_tx_packets_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_tx_packets_t *obj, int value);
extern int of_bsn_tlv_tx_packets_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_tx_packets_t *obj, int value);

extern int of_bsn_tlv_udf_anchor_OF_VERSION_1_3_populate(
    of_bsn_tlv_udf_anchor_t *obj, int value);
extern int of_bsn_tlv_udf_anchor_OF_VERSION_1_3_check(
    of_bsn_tlv_udf_anchor_t *obj, int value);
extern int of_bsn_tlv_udf_anchor_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_udf_anchor_t *obj, int value);
extern int of_bsn_tlv_udf_anchor_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_udf_anchor_t *obj, int value);

extern int of_bsn_tlv_udf_id_OF_VERSION_1_3_populate(
    of_bsn_tlv_udf_id_t *obj, int value);
extern int of_bsn_tlv_udf_id_OF_VERSION_1_3_check(
    of_bsn_tlv_udf_id_t *obj, int value);
extern int of_bsn_tlv_udf_id_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_udf_id_t *obj, int value);
extern int of_bsn_tlv_udf_id_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_udf_id_t *obj, int value);

extern int of_bsn_tlv_udf_length_OF_VERSION_1_3_populate(
    of_bsn_tlv_udf_length_t *obj, int value);
extern int of_bsn_tlv_udf_length_OF_VERSION_1_3_check(
    of_bsn_tlv_udf_length_t *obj, int value);
extern int of_bsn_tlv_udf_length_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_udf_length_t *obj, int value);
extern int of_bsn_tlv_udf_length_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_udf_length_t *obj, int value);

extern int of_bsn_tlv_udf_offset_OF_VERSION_1_3_populate(
    of_bsn_tlv_udf_offset_t *obj, int value);
extern int of_bsn_tlv_udf_offset_OF_VERSION_1_3_check(
    of_bsn_tlv_udf_offset_t *obj, int value);
extern int of_bsn_tlv_udf_offset_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_udf_offset_t *obj, int value);
extern int of_bsn_tlv_udf_offset_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_udf_offset_t *obj, int value);

extern int of_bsn_tlv_udp_dst_OF_VERSION_1_3_populate(
    of_bsn_tlv_udp_dst_t *obj, int value);
extern int of_bsn_tlv_udp_dst_OF_VERSION_1_3_check(
    of_bsn_tlv_udp_dst_t *obj, int value);
extern int of_bsn_tlv_udp_dst_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_udp_dst_t *obj, int value);
extern int of_bsn_tlv_udp_dst_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_udp_dst_t *obj, int value);

extern int of_bsn_tlv_udp_src_OF_VERSION_1_3_populate(
    of_bsn_tlv_udp_src_t *obj, int value);
extern int of_bsn_tlv_udp_src_OF_VERSION_1_3_check(
    of_bsn_tlv_udp_src_t *obj, int value);
extern int of_bsn_tlv_udp_src_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_udp_src_t *obj, int value);
extern int of_bsn_tlv_udp_src_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_udp_src_t *obj, int value);

extern int of_bsn_tlv_uint64_list_OF_VERSION_1_3_populate(
    of_bsn_tlv_uint64_list_t *obj, int value);
extern int of_bsn_tlv_uint64_list_OF_VERSION_1_3_check(
    of_bsn_tlv_uint64_list_t *obj, int value);
extern int of_bsn_tlv_uint64_list_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_uint64_list_t *obj, int value);
extern int of_bsn_tlv_uint64_list_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_uint64_list_t *obj, int value);

extern int of_bsn_tlv_unicast_query_timeout_OF_VERSION_1_3_populate(
    of_bsn_tlv_unicast_query_timeout_t *obj, int value);
extern int of_bsn_tlv_unicast_query_timeout_OF_VERSION_1_3_check(
    of_bsn_tlv_unicast_query_timeout_t *obj, int value);
extern int of_bsn_tlv_unicast_query_timeout_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_unicast_query_timeout_t *obj, int value);
extern int of_bsn_tlv_unicast_query_timeout_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_unicast_query_timeout_t *obj, int value);

extern int of_bsn_tlv_unicast_rate_OF_VERSION_1_3_populate(
    of_bsn_tlv_unicast_rate_t *obj, int value);
extern int of_bsn_tlv_unicast_rate_OF_VERSION_1_3_check(
    of_bsn_tlv_unicast_rate_t *obj, int value);
extern int of_bsn_tlv_unicast_rate_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_unicast_rate_t *obj, int value);
extern int of_bsn_tlv_unicast_rate_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_unicast_rate_t *obj, int value);

extern int of_bsn_tlv_unknown_multicast_rate_OF_VERSION_1_3_populate(
    of_bsn_tlv_unknown_multicast_rate_t *obj, int value);
extern int of_bsn_tlv_unknown_multicast_rate_OF_VERSION_1_3_check(
    of_bsn_tlv_unknown_multicast_rate_t *obj, int value);
extern int of_bsn_tlv_unknown_multicast_rate_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_unknown_multicast_rate_t *obj, int value);
extern int of_bsn_tlv_unknown_multicast_rate_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_unknown_multicast_rate_t *obj, int value);

extern int of_bsn_tlv_untagged_OF_VERSION_1_3_populate(
    of_bsn_tlv_untagged_t *obj, int value);
extern int of_bsn_tlv_untagged_OF_VERSION_1_3_check(
    of_bsn_tlv_untagged_t *obj, int value);
extern int of_bsn_tlv_untagged_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_untagged_t *obj, int value);
extern int of_bsn_tlv_untagged_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_untagged_t *obj, int value);

extern int of_bsn_tlv_uri_scheme_OF_VERSION_1_3_populate(
    of_bsn_tlv_uri_scheme_t *obj, int value);
extern int of_bsn_tlv_uri_scheme_OF_VERSION_1_3_check(
    of_bsn_tlv_uri_scheme_t *obj, int value);
extern int of_bsn_tlv_uri_scheme_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_uri_scheme_t *obj, int value);
extern int of_bsn_tlv_uri_scheme_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_uri_scheme_t *obj, int value);

extern int of_bsn_tlv_use_packet_state_OF_VERSION_1_3_populate(
    of_bsn_tlv_use_packet_state_t *obj, int value);
extern int of_bsn_tlv_use_packet_state_OF_VERSION_1_3_check(
    of_bsn_tlv_use_packet_state_t *obj, int value);
extern int of_bsn_tlv_use_packet_state_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_use_packet_state_t *obj, int value);
extern int of_bsn_tlv_use_packet_state_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_use_packet_state_t *obj, int value);

extern int of_bsn_tlv_vfi_OF_VERSION_1_3_populate(
    of_bsn_tlv_vfi_t *obj, int value);
extern int of_bsn_tlv_vfi_OF_VERSION_1_3_check(
    of_bsn_tlv_vfi_t *obj, int value);
extern int of_bsn_tlv_vfi_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_vfi_t *obj, int value);
extern int of_bsn_tlv_vfi_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_vfi_t *obj, int value);

extern int of_bsn_tlv_vfp_class_id_OF_VERSION_1_3_populate(
    of_bsn_tlv_vfp_class_id_t *obj, int value);
extern int of_bsn_tlv_vfp_class_id_OF_VERSION_1_3_check(
    of_bsn_tlv_vfp_class_id_t *obj, int value);
extern int of_bsn_tlv_vfp_class_id_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_vfp_class_id_t *obj, int value);
extern int of_bsn_tlv_vfp_class_id_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_vfp_class_id_t *obj, int value);

extern int of_bsn_tlv_virtual_OF_VERSION_1_3_populate(
    of_bsn_tlv_virtual_t *obj, int value);
extern int of_bsn_tlv_virtual_OF_VERSION_1_3_check(
    of_bsn_tlv_virtual_t *obj, int value);
extern int of_bsn_tlv_virtual_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_virtual_t *obj, int value);
extern int of_bsn_tlv_virtual_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_virtual_t *obj, int value);

extern int of_bsn_tlv_vlan_mac_list_OF_VERSION_1_3_populate(
    of_bsn_tlv_vlan_mac_list_t *obj, int value);
extern int of_bsn_tlv_vlan_mac_list_OF_VERSION_1_3_check(
    of_bsn_tlv_vlan_mac_list_t *obj, int value);
extern int of_bsn_tlv_vlan_mac_list_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_vlan_mac_list_t *obj, int value);
extern int of_bsn_tlv_vlan_mac_list_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_vlan_mac_list_t *obj, int value);

extern int of_bsn_tlv_vlan_pcp_OF_VERSION_1_3_populate(
    of_bsn_tlv_vlan_pcp_t *obj, int value);
extern int of_bsn_tlv_vlan_pcp_OF_VERSION_1_3_check(
    of_bsn_tlv_vlan_pcp_t *obj, int value);
extern int of_bsn_tlv_vlan_pcp_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_vlan_pcp_t *obj, int value);
extern int of_bsn_tlv_vlan_pcp_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_vlan_pcp_t *obj, int value);

extern int of_bsn_tlv_vlan_vid_OF_VERSION_1_3_populate(
    of_bsn_tlv_vlan_vid_t *obj, int value);
extern int of_bsn_tlv_vlan_vid_OF_VERSION_1_3_check(
    of_bsn_tlv_vlan_vid_t *obj, int value);
extern int of_bsn_tlv_vlan_vid_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_vlan_vid_t *obj, int value);
extern int of_bsn_tlv_vlan_vid_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_vlan_vid_t *obj, int value);

extern int of_bsn_tlv_vlan_vid_mask_OF_VERSION_1_3_populate(
    of_bsn_tlv_vlan_vid_mask_t *obj, int value);
extern int of_bsn_tlv_vlan_vid_mask_OF_VERSION_1_3_check(
    of_bsn_tlv_vlan_vid_mask_t *obj, int value);
extern int of_bsn_tlv_vlan_vid_mask_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_vlan_vid_mask_t *obj, int value);
extern int of_bsn_tlv_vlan_vid_mask_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_vlan_vid_mask_t *obj, int value);

extern int of_bsn_tlv_vni_OF_VERSION_1_3_populate(
    of_bsn_tlv_vni_t *obj, int value);
extern int of_bsn_tlv_vni_OF_VERSION_1_3_check(
    of_bsn_tlv_vni_t *obj, int value);
extern int of_bsn_tlv_vni_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_vni_t *obj, int value);
extern int of_bsn_tlv_vni_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_vni_t *obj, int value);

extern int of_bsn_tlv_vpn_key_OF_VERSION_1_3_populate(
    of_bsn_tlv_vpn_key_t *obj, int value);
extern int of_bsn_tlv_vpn_key_OF_VERSION_1_3_check(
    of_bsn_tlv_vpn_key_t *obj, int value);
extern int of_bsn_tlv_vpn_key_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_vpn_key_t *obj, int value);
extern int of_bsn_tlv_vpn_key_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_vpn_key_t *obj, int value);

extern int of_bsn_tlv_vrf_OF_VERSION_1_3_populate(
    of_bsn_tlv_vrf_t *obj, int value);
extern int of_bsn_tlv_vrf_OF_VERSION_1_3_check(
    of_bsn_tlv_vrf_t *obj, int value);
extern int of_bsn_tlv_vrf_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_vrf_t *obj, int value);
extern int of_bsn_tlv_vrf_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_vrf_t *obj, int value);

extern int of_bsn_tlv_vxlan_egress_lag_OF_VERSION_1_3_populate(
    of_bsn_tlv_vxlan_egress_lag_t *obj, int value);
extern int of_bsn_tlv_vxlan_egress_lag_OF_VERSION_1_3_check(
    of_bsn_tlv_vxlan_egress_lag_t *obj, int value);
extern int of_bsn_tlv_vxlan_egress_lag_OF_VERSION_1_3_populate_scalars(
    of_bsn_tlv_vxlan_egress_lag_t *obj, int value);
extern int of_bsn_tlv_vxlan_egress_lag_OF_VERSION_1_3_check_scalars(
    of_bsn_tlv_vxlan_egress_lag_t *obj, int value);

extern int of_bsn_vlan_counter_stats_entry_OF_VERSION_1_3_populate(
    of_bsn_vlan_counter_stats_entry_t *obj, int value);
extern int of_bsn_vlan_counter_stats_entry_OF_VERSION_1_3_check(
    of_bsn_vlan_counter_stats_entry_t *obj, int value);
extern int of_bsn_vlan_counter_stats_entry_OF_VERSION_1_3_populate_scalars(
    of_bsn_vlan_counter_stats_entry_t *obj, int value);
extern int of_bsn_vlan_counter_stats_entry_OF_VERSION_1_3_check_scalars(
    of_bsn_vlan_counter_stats_entry_t *obj, int value);

extern int of_bsn_vlan_mac_OF_VERSION_1_3_populate(
    of_bsn_vlan_mac_t *obj, int value);
extern int of_bsn_vlan_mac_OF_VERSION_1_3_check(
    of_bsn_vlan_mac_t *obj, int value);
extern int of_bsn_vlan_mac_OF_VERSION_1_3_populate_scalars(
    of_bsn_vlan_mac_t *obj, int value);
extern int of_bsn_vlan_mac_OF_VERSION_1_3_check_scalars(
    of_bsn_vlan_mac_t *obj, int value);

extern int of_bsn_vport_l2gre_OF_VERSION_1_3_populate(
    of_bsn_vport_l2gre_t *obj, int value);
extern int of_bsn_vport_l2gre_OF_VERSION_1_3_check(
    of_bsn_vport_l2gre_t *obj, int value);
extern int of_bsn_vport_l2gre_OF_VERSION_1_3_populate_scalars(
    of_bsn_vport_l2gre_t *obj, int value);
extern int of_bsn_vport_l2gre_OF_VERSION_1_3_check_scalars(
    of_bsn_vport_l2gre_t *obj, int value);

extern int of_bsn_vport_q_in_q_OF_VERSION_1_3_populate(
    of_bsn_vport_q_in_q_t *obj, int value);
extern int of_bsn_vport_q_in_q_OF_VERSION_1_3_check(
    of_bsn_vport_q_in_q_t *obj, int value);
extern int of_bsn_vport_q_in_q_OF_VERSION_1_3_populate_scalars(
    of_bsn_vport_q_in_q_t *obj, int value);
extern int of_bsn_vport_q_in_q_OF_VERSION_1_3_check_scalars(
    of_bsn_vport_q_in_q_t *obj, int value);

extern int of_bsn_vrf_counter_stats_entry_OF_VERSION_1_3_populate(
    of_bsn_vrf_counter_stats_entry_t *obj, int value);
extern int of_bsn_vrf_counter_stats_entry_OF_VERSION_1_3_check(
    of_bsn_vrf_counter_stats_entry_t *obj, int value);
extern int of_bsn_vrf_counter_stats_entry_OF_VERSION_1_3_populate_scalars(
    of_bsn_vrf_counter_stats_entry_t *obj, int value);
extern int of_bsn_vrf_counter_stats_entry_OF_VERSION_1_3_check_scalars(
    of_bsn_vrf_counter_stats_entry_t *obj, int value);

extern int of_bucket_OF_VERSION_1_3_populate(
    of_bucket_t *obj, int value);
extern int of_bucket_OF_VERSION_1_3_check(
    of_bucket_t *obj, int value);
extern int of_bucket_OF_VERSION_1_3_populate_scalars(
    of_bucket_t *obj, int value);
extern int of_bucket_OF_VERSION_1_3_check_scalars(
    of_bucket_t *obj, int value);

extern int of_bucket_counter_OF_VERSION_1_3_populate(
    of_bucket_counter_t *obj, int value);
extern int of_bucket_counter_OF_VERSION_1_3_check(
    of_bucket_counter_t *obj, int value);
extern int of_bucket_counter_OF_VERSION_1_3_populate_scalars(
    of_bucket_counter_t *obj, int value);
extern int of_bucket_counter_OF_VERSION_1_3_check_scalars(
    of_bucket_counter_t *obj, int value);

extern int of_flow_stats_entry_OF_VERSION_1_3_populate(
    of_flow_stats_entry_t *obj, int value);
extern int of_flow_stats_entry_OF_VERSION_1_3_check(
    of_flow_stats_entry_t *obj, int value);
extern int of_flow_stats_entry_OF_VERSION_1_3_populate_scalars(
    of_flow_stats_entry_t *obj, int value);
extern int of_flow_stats_entry_OF_VERSION_1_3_check_scalars(
    of_flow_stats_entry_t *obj, int value);

extern int of_group_desc_stats_entry_OF_VERSION_1_3_populate(
    of_group_desc_stats_entry_t *obj, int value);
extern int of_group_desc_stats_entry_OF_VERSION_1_3_check(
    of_group_desc_stats_entry_t *obj, int value);
extern int of_group_desc_stats_entry_OF_VERSION_1_3_populate_scalars(
    of_group_desc_stats_entry_t *obj, int value);
extern int of_group_desc_stats_entry_OF_VERSION_1_3_check_scalars(
    of_group_desc_stats_entry_t *obj, int value);

extern int of_group_stats_entry_OF_VERSION_1_3_populate(
    of_group_stats_entry_t *obj, int value);
extern int of_group_stats_entry_OF_VERSION_1_3_check(
    of_group_stats_entry_t *obj, int value);
extern int of_group_stats_entry_OF_VERSION_1_3_populate_scalars(
    of_group_stats_entry_t *obj, int value);
extern int of_group_stats_entry_OF_VERSION_1_3_check_scalars(
    of_group_stats_entry_t *obj, int value);

extern int of_hello_elem_versionbitmap_OF_VERSION_1_3_populate(
    of_hello_elem_versionbitmap_t *obj, int value);
extern int of_hello_elem_versionbitmap_OF_VERSION_1_3_check(
    of_hello_elem_versionbitmap_t *obj, int value);
extern int of_hello_elem_versionbitmap_OF_VERSION_1_3_populate_scalars(
    of_hello_elem_versionbitmap_t *obj, int value);
extern int of_hello_elem_versionbitmap_OF_VERSION_1_3_check_scalars(
    of_hello_elem_versionbitmap_t *obj, int value);

extern int of_instruction_apply_actions_OF_VERSION_1_3_populate(
    of_instruction_apply_actions_t *obj, int value);
extern int of_instruction_apply_actions_OF_VERSION_1_3_check(
    of_instruction_apply_actions_t *obj, int value);
extern int of_instruction_apply_actions_OF_VERSION_1_3_populate_scalars(
    of_instruction_apply_actions_t *obj, int value);
extern int of_instruction_apply_actions_OF_VERSION_1_3_check_scalars(
    of_instruction_apply_actions_t *obj, int value);

extern int of_instruction_bsn_arp_offload_OF_VERSION_1_3_populate(
    of_instruction_bsn_arp_offload_t *obj, int value);
extern int of_instruction_bsn_arp_offload_OF_VERSION_1_3_check(
    of_instruction_bsn_arp_offload_t *obj, int value);
extern int of_instruction_bsn_arp_offload_OF_VERSION_1_3_populate_scalars(
    of_instruction_bsn_arp_offload_t *obj, int value);
extern int of_instruction_bsn_arp_offload_OF_VERSION_1_3_check_scalars(
    of_instruction_bsn_arp_offload_t *obj, int value);

extern int of_instruction_bsn_auto_negotiation_OF_VERSION_1_3_populate(
    of_instruction_bsn_auto_negotiation_t *obj, int value);
extern int of_instruction_bsn_auto_negotiation_OF_VERSION_1_3_check(
    of_instruction_bsn_auto_negotiation_t *obj, int value);
extern int of_instruction_bsn_auto_negotiation_OF_VERSION_1_3_populate_scalars(
    of_instruction_bsn_auto_negotiation_t *obj, int value);
extern int of_instruction_bsn_auto_negotiation_OF_VERSION_1_3_check_scalars(
    of_instruction_bsn_auto_negotiation_t *obj, int value);

extern int of_instruction_bsn_deny_OF_VERSION_1_3_populate(
    of_instruction_bsn_deny_t *obj, int value);
extern int of_instruction_bsn_deny_OF_VERSION_1_3_check(
    of_instruction_bsn_deny_t *obj, int value);
extern int of_instruction_bsn_deny_OF_VERSION_1_3_populate_scalars(
    of_instruction_bsn_deny_t *obj, int value);
extern int of_instruction_bsn_deny_OF_VERSION_1_3_check_scalars(
    of_instruction_bsn_deny_t *obj, int value);

extern int of_instruction_bsn_dhcp_offload_OF_VERSION_1_3_populate(
    of_instruction_bsn_dhcp_offload_t *obj, int value);
extern int of_instruction_bsn_dhcp_offload_OF_VERSION_1_3_check(
    of_instruction_bsn_dhcp_offload_t *obj, int value);
extern int of_instruction_bsn_dhcp_offload_OF_VERSION_1_3_populate_scalars(
    of_instruction_bsn_dhcp_offload_t *obj, int value);
extern int of_instruction_bsn_dhcp_offload_OF_VERSION_1_3_check_scalars(
    of_instruction_bsn_dhcp_offload_t *obj, int value);

extern int of_instruction_bsn_disable_l3_OF_VERSION_1_3_populate(
    of_instruction_bsn_disable_l3_t *obj, int value);
extern int of_instruction_bsn_disable_l3_OF_VERSION_1_3_check(
    of_instruction_bsn_disable_l3_t *obj, int value);
extern int of_instruction_bsn_disable_l3_OF_VERSION_1_3_populate_scalars(
    of_instruction_bsn_disable_l3_t *obj, int value);
extern int of_instruction_bsn_disable_l3_OF_VERSION_1_3_check_scalars(
    of_instruction_bsn_disable_l3_t *obj, int value);

extern int of_instruction_bsn_disable_split_horizon_check_OF_VERSION_1_3_populate(
    of_instruction_bsn_disable_split_horizon_check_t *obj, int value);
extern int of_instruction_bsn_disable_split_horizon_check_OF_VERSION_1_3_check(
    of_instruction_bsn_disable_split_horizon_check_t *obj, int value);
extern int of_instruction_bsn_disable_split_horizon_check_OF_VERSION_1_3_populate_scalars(
    of_instruction_bsn_disable_split_horizon_check_t *obj, int value);
extern int of_instruction_bsn_disable_split_horizon_check_OF_VERSION_1_3_check_scalars(
    of_instruction_bsn_disable_split_horizon_check_t *obj, int value);

extern int of_instruction_bsn_disable_src_mac_check_OF_VERSION_1_3_populate(
    of_instruction_bsn_disable_src_mac_check_t *obj, int value);
extern int of_instruction_bsn_disable_src_mac_check_OF_VERSION_1_3_check(
    of_instruction_bsn_disable_src_mac_check_t *obj, int value);
extern int of_instruction_bsn_disable_src_mac_check_OF_VERSION_1_3_populate_scalars(
    of_instruction_bsn_disable_src_mac_check_t *obj, int value);
extern int of_instruction_bsn_disable_src_mac_check_OF_VERSION_1_3_check_scalars(
    of_instruction_bsn_disable_src_mac_check_t *obj, int value);

extern int of_instruction_bsn_disable_vlan_counters_OF_VERSION_1_3_populate(
    of_instruction_bsn_disable_vlan_counters_t *obj, int value);
extern int of_instruction_bsn_disable_vlan_counters_OF_VERSION_1_3_check(
    of_instruction_bsn_disable_vlan_counters_t *obj, int value);
extern int of_instruction_bsn_disable_vlan_counters_OF_VERSION_1_3_populate_scalars(
    of_instruction_bsn_disable_vlan_counters_t *obj, int value);
extern int of_instruction_bsn_disable_vlan_counters_OF_VERSION_1_3_check_scalars(
    of_instruction_bsn_disable_vlan_counters_t *obj, int value);

extern int of_instruction_bsn_hash_select_OF_VERSION_1_3_populate(
    of_instruction_bsn_hash_select_t *obj, int value);
extern int of_instruction_bsn_hash_select_OF_VERSION_1_3_check(
    of_instruction_bsn_hash_select_t *obj, int value);
extern int of_instruction_bsn_hash_select_OF_VERSION_1_3_populate_scalars(
    of_instruction_bsn_hash_select_t *obj, int value);
extern int of_instruction_bsn_hash_select_OF_VERSION_1_3_check_scalars(
    of_instruction_bsn_hash_select_t *obj, int value);

extern int of_instruction_bsn_internal_priority_OF_VERSION_1_3_populate(
    of_instruction_bsn_internal_priority_t *obj, int value);
extern int of_instruction_bsn_internal_priority_OF_VERSION_1_3_check(
    of_instruction_bsn_internal_priority_t *obj, int value);
extern int of_instruction_bsn_internal_priority_OF_VERSION_1_3_populate_scalars(
    of_instruction_bsn_internal_priority_t *obj, int value);
extern int of_instruction_bsn_internal_priority_OF_VERSION_1_3_check_scalars(
    of_instruction_bsn_internal_priority_t *obj, int value);

extern int of_instruction_bsn_ndp_offload_OF_VERSION_1_3_populate(
    of_instruction_bsn_ndp_offload_t *obj, int value);
extern int of_instruction_bsn_ndp_offload_OF_VERSION_1_3_check(
    of_instruction_bsn_ndp_offload_t *obj, int value);
extern int of_instruction_bsn_ndp_offload_OF_VERSION_1_3_populate_scalars(
    of_instruction_bsn_ndp_offload_t *obj, int value);
extern int of_instruction_bsn_ndp_offload_OF_VERSION_1_3_check_scalars(
    of_instruction_bsn_ndp_offload_t *obj, int value);

extern int of_instruction_bsn_packet_of_death_OF_VERSION_1_3_populate(
    of_instruction_bsn_packet_of_death_t *obj, int value);
extern int of_instruction_bsn_packet_of_death_OF_VERSION_1_3_check(
    of_instruction_bsn_packet_of_death_t *obj, int value);
extern int of_instruction_bsn_packet_of_death_OF_VERSION_1_3_populate_scalars(
    of_instruction_bsn_packet_of_death_t *obj, int value);
extern int of_instruction_bsn_packet_of_death_OF_VERSION_1_3_check_scalars(
    of_instruction_bsn_packet_of_death_t *obj, int value);

extern int of_instruction_bsn_permit_OF_VERSION_1_3_populate(
    of_instruction_bsn_permit_t *obj, int value);
extern int of_instruction_bsn_permit_OF_VERSION_1_3_check(
    of_instruction_bsn_permit_t *obj, int value);
extern int of_instruction_bsn_permit_OF_VERSION_1_3_populate_scalars(
    of_instruction_bsn_permit_t *obj, int value);
extern int of_instruction_bsn_permit_OF_VERSION_1_3_check_scalars(
    of_instruction_bsn_permit_t *obj, int value);

extern int of_instruction_bsn_prioritize_pdus_OF_VERSION_1_3_populate(
    of_instruction_bsn_prioritize_pdus_t *obj, int value);
extern int of_instruction_bsn_prioritize_pdus_OF_VERSION_1_3_check(
    of_instruction_bsn_prioritize_pdus_t *obj, int value);
extern int of_instruction_bsn_prioritize_pdus_OF_VERSION_1_3_populate_scalars(
    of_instruction_bsn_prioritize_pdus_t *obj, int value);
extern int of_instruction_bsn_prioritize_pdus_OF_VERSION_1_3_check_scalars(
    of_instruction_bsn_prioritize_pdus_t *obj, int value);

extern int of_instruction_bsn_require_vlan_xlate_OF_VERSION_1_3_populate(
    of_instruction_bsn_require_vlan_xlate_t *obj, int value);
extern int of_instruction_bsn_require_vlan_xlate_OF_VERSION_1_3_check(
    of_instruction_bsn_require_vlan_xlate_t *obj, int value);
extern int of_instruction_bsn_require_vlan_xlate_OF_VERSION_1_3_populate_scalars(
    of_instruction_bsn_require_vlan_xlate_t *obj, int value);
extern int of_instruction_bsn_require_vlan_xlate_OF_VERSION_1_3_check_scalars(
    of_instruction_bsn_require_vlan_xlate_t *obj, int value);

extern int of_instruction_bsn_span_destination_OF_VERSION_1_3_populate(
    of_instruction_bsn_span_destination_t *obj, int value);
extern int of_instruction_bsn_span_destination_OF_VERSION_1_3_check(
    of_instruction_bsn_span_destination_t *obj, int value);
extern int of_instruction_bsn_span_destination_OF_VERSION_1_3_populate_scalars(
    of_instruction_bsn_span_destination_t *obj, int value);
extern int of_instruction_bsn_span_destination_OF_VERSION_1_3_check_scalars(
    of_instruction_bsn_span_destination_t *obj, int value);

extern int of_instruction_clear_actions_OF_VERSION_1_3_populate(
    of_instruction_clear_actions_t *obj, int value);
extern int of_instruction_clear_actions_OF_VERSION_1_3_check(
    of_instruction_clear_actions_t *obj, int value);
extern int of_instruction_clear_actions_OF_VERSION_1_3_populate_scalars(
    of_instruction_clear_actions_t *obj, int value);
extern int of_instruction_clear_actions_OF_VERSION_1_3_check_scalars(
    of_instruction_clear_actions_t *obj, int value);

extern int of_instruction_goto_table_OF_VERSION_1_3_populate(
    of_instruction_goto_table_t *obj, int value);
extern int of_instruction_goto_table_OF_VERSION_1_3_check(
    of_instruction_goto_table_t *obj, int value);
extern int of_instruction_goto_table_OF_VERSION_1_3_populate_scalars(
    of_instruction_goto_table_t *obj, int value);
extern int of_instruction_goto_table_OF_VERSION_1_3_check_scalars(
    of_instruction_goto_table_t *obj, int value);

extern int of_instruction_id_apply_actions_OF_VERSION_1_3_populate(
    of_instruction_id_apply_actions_t *obj, int value);
extern int of_instruction_id_apply_actions_OF_VERSION_1_3_check(
    of_instruction_id_apply_actions_t *obj, int value);
extern int of_instruction_id_apply_actions_OF_VERSION_1_3_populate_scalars(
    of_instruction_id_apply_actions_t *obj, int value);
extern int of_instruction_id_apply_actions_OF_VERSION_1_3_check_scalars(
    of_instruction_id_apply_actions_t *obj, int value);

extern int of_instruction_id_bsn_arp_offload_OF_VERSION_1_3_populate(
    of_instruction_id_bsn_arp_offload_t *obj, int value);
extern int of_instruction_id_bsn_arp_offload_OF_VERSION_1_3_check(
    of_instruction_id_bsn_arp_offload_t *obj, int value);
extern int of_instruction_id_bsn_arp_offload_OF_VERSION_1_3_populate_scalars(
    of_instruction_id_bsn_arp_offload_t *obj, int value);
extern int of_instruction_id_bsn_arp_offload_OF_VERSION_1_3_check_scalars(
    of_instruction_id_bsn_arp_offload_t *obj, int value);

extern int of_instruction_id_bsn_auto_negotiation_OF_VERSION_1_3_populate(
    of_instruction_id_bsn_auto_negotiation_t *obj, int value);
extern int of_instruction_id_bsn_auto_negotiation_OF_VERSION_1_3_check(
    of_instruction_id_bsn_auto_negotiation_t *obj, int value);
extern int of_instruction_id_bsn_auto_negotiation_OF_VERSION_1_3_populate_scalars(
    of_instruction_id_bsn_auto_negotiation_t *obj, int value);
extern int of_instruction_id_bsn_auto_negotiation_OF_VERSION_1_3_check_scalars(
    of_instruction_id_bsn_auto_negotiation_t *obj, int value);

extern int of_instruction_id_bsn_deny_OF_VERSION_1_3_populate(
    of_instruction_id_bsn_deny_t *obj, int value);
extern int of_instruction_id_bsn_deny_OF_VERSION_1_3_check(
    of_instruction_id_bsn_deny_t *obj, int value);
extern int of_instruction_id_bsn_deny_OF_VERSION_1_3_populate_scalars(
    of_instruction_id_bsn_deny_t *obj, int value);
extern int of_instruction_id_bsn_deny_OF_VERSION_1_3_check_scalars(
    of_instruction_id_bsn_deny_t *obj, int value);

extern int of_instruction_id_bsn_dhcp_offload_OF_VERSION_1_3_populate(
    of_instruction_id_bsn_dhcp_offload_t *obj, int value);
extern int of_instruction_id_bsn_dhcp_offload_OF_VERSION_1_3_check(
    of_instruction_id_bsn_dhcp_offload_t *obj, int value);
extern int of_instruction_id_bsn_dhcp_offload_OF_VERSION_1_3_populate_scalars(
    of_instruction_id_bsn_dhcp_offload_t *obj, int value);
extern int of_instruction_id_bsn_dhcp_offload_OF_VERSION_1_3_check_scalars(
    of_instruction_id_bsn_dhcp_offload_t *obj, int value);

extern int of_instruction_id_bsn_disable_l3_OF_VERSION_1_3_populate(
    of_instruction_id_bsn_disable_l3_t *obj, int value);
extern int of_instruction_id_bsn_disable_l3_OF_VERSION_1_3_check(
    of_instruction_id_bsn_disable_l3_t *obj, int value);
extern int of_instruction_id_bsn_disable_l3_OF_VERSION_1_3_populate_scalars(
    of_instruction_id_bsn_disable_l3_t *obj, int value);
extern int of_instruction_id_bsn_disable_l3_OF_VERSION_1_3_check_scalars(
    of_instruction_id_bsn_disable_l3_t *obj, int value);

extern int of_instruction_id_bsn_disable_split_horizon_check_OF_VERSION_1_3_populate(
    of_instruction_id_bsn_disable_split_horizon_check_t *obj, int value);
extern int of_instruction_id_bsn_disable_split_horizon_check_OF_VERSION_1_3_check(
    of_instruction_id_bsn_disable_split_horizon_check_t *obj, int value);
extern int of_instruction_id_bsn_disable_split_horizon_check_OF_VERSION_1_3_populate_scalars(
    of_instruction_id_bsn_disable_split_horizon_check_t *obj, int value);
extern int of_instruction_id_bsn_disable_split_horizon_check_OF_VERSION_1_3_check_scalars(
    of_instruction_id_bsn_disable_split_horizon_check_t *obj, int value);

extern int of_instruction_id_bsn_disable_src_mac_check_OF_VERSION_1_3_populate(
    of_instruction_id_bsn_disable_src_mac_check_t *obj, int value);
extern int of_instruction_id_bsn_disable_src_mac_check_OF_VERSION_1_3_check(
    of_instruction_id_bsn_disable_src_mac_check_t *obj, int value);
extern int of_instruction_id_bsn_disable_src_mac_check_OF_VERSION_1_3_populate_scalars(
    of_instruction_id_bsn_disable_src_mac_check_t *obj, int value);
extern int of_instruction_id_bsn_disable_src_mac_check_OF_VERSION_1_3_check_scalars(
    of_instruction_id_bsn_disable_src_mac_check_t *obj, int value);

extern int of_instruction_id_bsn_disable_vlan_counters_OF_VERSION_1_3_populate(
    of_instruction_id_bsn_disable_vlan_counters_t *obj, int value);
extern int of_instruction_id_bsn_disable_vlan_counters_OF_VERSION_1_3_check(
    of_instruction_id_bsn_disable_vlan_counters_t *obj, int value);
extern int of_instruction_id_bsn_disable_vlan_counters_OF_VERSION_1_3_populate_scalars(
    of_instruction_id_bsn_disable_vlan_counters_t *obj, int value);
extern int of_instruction_id_bsn_disable_vlan_counters_OF_VERSION_1_3_check_scalars(
    of_instruction_id_bsn_disable_vlan_counters_t *obj, int value);

extern int of_instruction_id_bsn_hash_select_OF_VERSION_1_3_populate(
    of_instruction_id_bsn_hash_select_t *obj, int value);
extern int of_instruction_id_bsn_hash_select_OF_VERSION_1_3_check(
    of_instruction_id_bsn_hash_select_t *obj, int value);
extern int of_instruction_id_bsn_hash_select_OF_VERSION_1_3_populate_scalars(
    of_instruction_id_bsn_hash_select_t *obj, int value);
extern int of_instruction_id_bsn_hash_select_OF_VERSION_1_3_check_scalars(
    of_instruction_id_bsn_hash_select_t *obj, int value);

extern int of_instruction_id_bsn_internal_priority_OF_VERSION_1_3_populate(
    of_instruction_id_bsn_internal_priority_t *obj, int value);
extern int of_instruction_id_bsn_internal_priority_OF_VERSION_1_3_check(
    of_instruction_id_bsn_internal_priority_t *obj, int value);
extern int of_instruction_id_bsn_internal_priority_OF_VERSION_1_3_populate_scalars(
    of_instruction_id_bsn_internal_priority_t *obj, int value);
extern int of_instruction_id_bsn_internal_priority_OF_VERSION_1_3_check_scalars(
    of_instruction_id_bsn_internal_priority_t *obj, int value);

extern int of_instruction_id_bsn_ndp_offload_OF_VERSION_1_3_populate(
    of_instruction_id_bsn_ndp_offload_t *obj, int value);
extern int of_instruction_id_bsn_ndp_offload_OF_VERSION_1_3_check(
    of_instruction_id_bsn_ndp_offload_t *obj, int value);
extern int of_instruction_id_bsn_ndp_offload_OF_VERSION_1_3_populate_scalars(
    of_instruction_id_bsn_ndp_offload_t *obj, int value);
extern int of_instruction_id_bsn_ndp_offload_OF_VERSION_1_3_check_scalars(
    of_instruction_id_bsn_ndp_offload_t *obj, int value);

extern int of_instruction_id_bsn_packet_of_death_OF_VERSION_1_3_populate(
    of_instruction_id_bsn_packet_of_death_t *obj, int value);
extern int of_instruction_id_bsn_packet_of_death_OF_VERSION_1_3_check(
    of_instruction_id_bsn_packet_of_death_t *obj, int value);
extern int of_instruction_id_bsn_packet_of_death_OF_VERSION_1_3_populate_scalars(
    of_instruction_id_bsn_packet_of_death_t *obj, int value);
extern int of_instruction_id_bsn_packet_of_death_OF_VERSION_1_3_check_scalars(
    of_instruction_id_bsn_packet_of_death_t *obj, int value);

extern int of_instruction_id_bsn_permit_OF_VERSION_1_3_populate(
    of_instruction_id_bsn_permit_t *obj, int value);
extern int of_instruction_id_bsn_permit_OF_VERSION_1_3_check(
    of_instruction_id_bsn_permit_t *obj, int value);
extern int of_instruction_id_bsn_permit_OF_VERSION_1_3_populate_scalars(
    of_instruction_id_bsn_permit_t *obj, int value);
extern int of_instruction_id_bsn_permit_OF_VERSION_1_3_check_scalars(
    of_instruction_id_bsn_permit_t *obj, int value);

extern int of_instruction_id_bsn_prioritize_pdus_OF_VERSION_1_3_populate(
    of_instruction_id_bsn_prioritize_pdus_t *obj, int value);
extern int of_instruction_id_bsn_prioritize_pdus_OF_VERSION_1_3_check(
    of_instruction_id_bsn_prioritize_pdus_t *obj, int value);
extern int of_instruction_id_bsn_prioritize_pdus_OF_VERSION_1_3_populate_scalars(
    of_instruction_id_bsn_prioritize_pdus_t *obj, int value);
extern int of_instruction_id_bsn_prioritize_pdus_OF_VERSION_1_3_check_scalars(
    of_instruction_id_bsn_prioritize_pdus_t *obj, int value);

extern int of_instruction_id_bsn_require_vlan_xlate_OF_VERSION_1_3_populate(
    of_instruction_id_bsn_require_vlan_xlate_t *obj, int value);
extern int of_instruction_id_bsn_require_vlan_xlate_OF_VERSION_1_3_check(
    of_instruction_id_bsn_require_vlan_xlate_t *obj, int value);
extern int of_instruction_id_bsn_require_vlan_xlate_OF_VERSION_1_3_populate_scalars(
    of_instruction_id_bsn_require_vlan_xlate_t *obj, int value);
extern int of_instruction_id_bsn_require_vlan_xlate_OF_VERSION_1_3_check_scalars(
    of_instruction_id_bsn_require_vlan_xlate_t *obj, int value);

extern int of_instruction_id_bsn_span_destination_OF_VERSION_1_3_populate(
    of_instruction_id_bsn_span_destination_t *obj, int value);
extern int of_instruction_id_bsn_span_destination_OF_VERSION_1_3_check(
    of_instruction_id_bsn_span_destination_t *obj, int value);
extern int of_instruction_id_bsn_span_destination_OF_VERSION_1_3_populate_scalars(
    of_instruction_id_bsn_span_destination_t *obj, int value);
extern int of_instruction_id_bsn_span_destination_OF_VERSION_1_3_check_scalars(
    of_instruction_id_bsn_span_destination_t *obj, int value);

extern int of_instruction_id_clear_actions_OF_VERSION_1_3_populate(
    of_instruction_id_clear_actions_t *obj, int value);
extern int of_instruction_id_clear_actions_OF_VERSION_1_3_check(
    of_instruction_id_clear_actions_t *obj, int value);
extern int of_instruction_id_clear_actions_OF_VERSION_1_3_populate_scalars(
    of_instruction_id_clear_actions_t *obj, int value);
extern int of_instruction_id_clear_actions_OF_VERSION_1_3_check_scalars(
    of_instruction_id_clear_actions_t *obj, int value);

extern int of_instruction_id_goto_table_OF_VERSION_1_3_populate(
    of_instruction_id_goto_table_t *obj, int value);
extern int of_instruction_id_goto_table_OF_VERSION_1_3_check(
    of_instruction_id_goto_table_t *obj, int value);
extern int of_instruction_id_goto_table_OF_VERSION_1_3_populate_scalars(
    of_instruction_id_goto_table_t *obj, int value);
extern int of_instruction_id_goto_table_OF_VERSION_1_3_check_scalars(
    of_instruction_id_goto_table_t *obj, int value);

extern int of_instruction_id_meter_OF_VERSION_1_3_populate(
    of_instruction_id_meter_t *obj, int value);
extern int of_instruction_id_meter_OF_VERSION_1_3_check(
    of_instruction_id_meter_t *obj, int value);
extern int of_instruction_id_meter_OF_VERSION_1_3_populate_scalars(
    of_instruction_id_meter_t *obj, int value);
extern int of_instruction_id_meter_OF_VERSION_1_3_check_scalars(
    of_instruction_id_meter_t *obj, int value);

extern int of_instruction_id_write_actions_OF_VERSION_1_3_populate(
    of_instruction_id_write_actions_t *obj, int value);
extern int of_instruction_id_write_actions_OF_VERSION_1_3_check(
    of_instruction_id_write_actions_t *obj, int value);
extern int of_instruction_id_write_actions_OF_VERSION_1_3_populate_scalars(
    of_instruction_id_write_actions_t *obj, int value);
extern int of_instruction_id_write_actions_OF_VERSION_1_3_check_scalars(
    of_instruction_id_write_actions_t *obj, int value);

extern int of_instruction_id_write_metadata_OF_VERSION_1_3_populate(
    of_instruction_id_write_metadata_t *obj, int value);
extern int of_instruction_id_write_metadata_OF_VERSION_1_3_check(
    of_instruction_id_write_metadata_t *obj, int value);
extern int of_instruction_id_write_metadata_OF_VERSION_1_3_populate_scalars(
    of_instruction_id_write_metadata_t *obj, int value);
extern int of_instruction_id_write_metadata_OF_VERSION_1_3_check_scalars(
    of_instruction_id_write_metadata_t *obj, int value);

extern int of_instruction_meter_OF_VERSION_1_3_populate(
    of_instruction_meter_t *obj, int value);
extern int of_instruction_meter_OF_VERSION_1_3_check(
    of_instruction_meter_t *obj, int value);
extern int of_instruction_meter_OF_VERSION_1_3_populate_scalars(
    of_instruction_meter_t *obj, int value);
extern int of_instruction_meter_OF_VERSION_1_3_check_scalars(
    of_instruction_meter_t *obj, int value);

extern int of_instruction_write_actions_OF_VERSION_1_3_populate(
    of_instruction_write_actions_t *obj, int value);
extern int of_instruction_write_actions_OF_VERSION_1_3_check(
    of_instruction_write_actions_t *obj, int value);
extern int of_instruction_write_actions_OF_VERSION_1_3_populate_scalars(
    of_instruction_write_actions_t *obj, int value);
extern int of_instruction_write_actions_OF_VERSION_1_3_check_scalars(
    of_instruction_write_actions_t *obj, int value);

extern int of_instruction_write_metadata_OF_VERSION_1_3_populate(
    of_instruction_write_metadata_t *obj, int value);
extern int of_instruction_write_metadata_OF_VERSION_1_3_check(
    of_instruction_write_metadata_t *obj, int value);
extern int of_instruction_write_metadata_OF_VERSION_1_3_populate_scalars(
    of_instruction_write_metadata_t *obj, int value);
extern int of_instruction_write_metadata_OF_VERSION_1_3_check_scalars(
    of_instruction_write_metadata_t *obj, int value);

extern int of_match_v3_OF_VERSION_1_3_populate(
    of_match_v3_t *obj, int value);
extern int of_match_v3_OF_VERSION_1_3_check(
    of_match_v3_t *obj, int value);
extern int of_match_v3_OF_VERSION_1_3_populate_scalars(
    of_match_v3_t *obj, int value);
extern int of_match_v3_OF_VERSION_1_3_check_scalars(
    of_match_v3_t *obj, int value);

extern int of_meter_band_drop_OF_VERSION_1_3_populate(
    of_meter_band_drop_t *obj, int value);
extern int of_meter_band_drop_OF_VERSION_1_3_check(
    of_meter_band_drop_t *obj, int value);
extern int of_meter_band_drop_OF_VERSION_1_3_populate_scalars(
    of_meter_band_drop_t *obj, int value);
extern int of_meter_band_drop_OF_VERSION_1_3_check_scalars(
    of_meter_band_drop_t *obj, int value);

extern int of_meter_band_dscp_remark_OF_VERSION_1_3_populate(
    of_meter_band_dscp_remark_t *obj, int value);
extern int of_meter_band_dscp_remark_OF_VERSION_1_3_check(
    of_meter_band_dscp_remark_t *obj, int value);
extern int of_meter_band_dscp_remark_OF_VERSION_1_3_populate_scalars(
    of_meter_band_dscp_remark_t *obj, int value);
extern int of_meter_band_dscp_remark_OF_VERSION_1_3_check_scalars(
    of_meter_band_dscp_remark_t *obj, int value);

extern int of_meter_band_experimenter_OF_VERSION_1_3_populate(
    of_meter_band_experimenter_t *obj, int value);
extern int of_meter_band_experimenter_OF_VERSION_1_3_check(
    of_meter_band_experimenter_t *obj, int value);
extern int of_meter_band_experimenter_OF_VERSION_1_3_populate_scalars(
    of_meter_band_experimenter_t *obj, int value);
extern int of_meter_band_experimenter_OF_VERSION_1_3_check_scalars(
    of_meter_band_experimenter_t *obj, int value);

extern int of_meter_band_stats_OF_VERSION_1_3_populate(
    of_meter_band_stats_t *obj, int value);
extern int of_meter_band_stats_OF_VERSION_1_3_check(
    of_meter_band_stats_t *obj, int value);
extern int of_meter_band_stats_OF_VERSION_1_3_populate_scalars(
    of_meter_band_stats_t *obj, int value);
extern int of_meter_band_stats_OF_VERSION_1_3_check_scalars(
    of_meter_band_stats_t *obj, int value);

extern int of_meter_config_OF_VERSION_1_3_populate(
    of_meter_config_t *obj, int value);
extern int of_meter_config_OF_VERSION_1_3_check(
    of_meter_config_t *obj, int value);
extern int of_meter_config_OF_VERSION_1_3_populate_scalars(
    of_meter_config_t *obj, int value);
extern int of_meter_config_OF_VERSION_1_3_check_scalars(
    of_meter_config_t *obj, int value);

extern int of_meter_features_OF_VERSION_1_3_populate(
    of_meter_features_t *obj, int value);
extern int of_meter_features_OF_VERSION_1_3_check(
    of_meter_features_t *obj, int value);
extern int of_meter_features_OF_VERSION_1_3_populate_scalars(
    of_meter_features_t *obj, int value);
extern int of_meter_features_OF_VERSION_1_3_check_scalars(
    of_meter_features_t *obj, int value);

extern int of_meter_stats_OF_VERSION_1_3_populate(
    of_meter_stats_t *obj, int value);
extern int of_meter_stats_OF_VERSION_1_3_check(
    of_meter_stats_t *obj, int value);
extern int of_meter_stats_OF_VERSION_1_3_populate_scalars(
    of_meter_stats_t *obj, int value);
extern int of_meter_stats_OF_VERSION_1_3_check_scalars(
    of_meter_stats_t *obj, int value);

extern int of_oxm_arp_op_OF_VERSION_1_3_populate(
    of_oxm_arp_op_t *obj, int value);
extern int of_oxm_arp_op_OF_VERSION_1_3_check(
    of_oxm_arp_op_t *obj, int value);
extern int of_oxm_arp_op_OF_VERSION_1_3_populate_scalars(
    of_oxm_arp_op_t *obj, int value);
extern int of_oxm_arp_op_OF_VERSION_1_3_check_scalars(
    of_oxm_arp_op_t *obj, int value);

extern int of_oxm_arp_op_masked_OF_VERSION_1_3_populate(
    of_oxm_arp_op_masked_t *obj, int value);
extern int of_oxm_arp_op_masked_OF_VERSION_1_3_check(
    of_oxm_arp_op_masked_t *obj, int value);
extern int of_oxm_arp_op_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_arp_op_masked_t *obj, int value);
extern int of_oxm_arp_op_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_arp_op_masked_t *obj, int value);

extern int of_oxm_arp_sha_OF_VERSION_1_3_populate(
    of_oxm_arp_sha_t *obj, int value);
extern int of_oxm_arp_sha_OF_VERSION_1_3_check(
    of_oxm_arp_sha_t *obj, int value);
extern int of_oxm_arp_sha_OF_VERSION_1_3_populate_scalars(
    of_oxm_arp_sha_t *obj, int value);
extern int of_oxm_arp_sha_OF_VERSION_1_3_check_scalars(
    of_oxm_arp_sha_t *obj, int value);

extern int of_oxm_arp_sha_masked_OF_VERSION_1_3_populate(
    of_oxm_arp_sha_masked_t *obj, int value);
extern int of_oxm_arp_sha_masked_OF_VERSION_1_3_check(
    of_oxm_arp_sha_masked_t *obj, int value);
extern int of_oxm_arp_sha_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_arp_sha_masked_t *obj, int value);
extern int of_oxm_arp_sha_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_arp_sha_masked_t *obj, int value);

extern int of_oxm_arp_spa_OF_VERSION_1_3_populate(
    of_oxm_arp_spa_t *obj, int value);
extern int of_oxm_arp_spa_OF_VERSION_1_3_check(
    of_oxm_arp_spa_t *obj, int value);
extern int of_oxm_arp_spa_OF_VERSION_1_3_populate_scalars(
    of_oxm_arp_spa_t *obj, int value);
extern int of_oxm_arp_spa_OF_VERSION_1_3_check_scalars(
    of_oxm_arp_spa_t *obj, int value);

extern int of_oxm_arp_spa_masked_OF_VERSION_1_3_populate(
    of_oxm_arp_spa_masked_t *obj, int value);
extern int of_oxm_arp_spa_masked_OF_VERSION_1_3_check(
    of_oxm_arp_spa_masked_t *obj, int value);
extern int of_oxm_arp_spa_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_arp_spa_masked_t *obj, int value);
extern int of_oxm_arp_spa_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_arp_spa_masked_t *obj, int value);

extern int of_oxm_arp_tha_OF_VERSION_1_3_populate(
    of_oxm_arp_tha_t *obj, int value);
extern int of_oxm_arp_tha_OF_VERSION_1_3_check(
    of_oxm_arp_tha_t *obj, int value);
extern int of_oxm_arp_tha_OF_VERSION_1_3_populate_scalars(
    of_oxm_arp_tha_t *obj, int value);
extern int of_oxm_arp_tha_OF_VERSION_1_3_check_scalars(
    of_oxm_arp_tha_t *obj, int value);

extern int of_oxm_arp_tha_masked_OF_VERSION_1_3_populate(
    of_oxm_arp_tha_masked_t *obj, int value);
extern int of_oxm_arp_tha_masked_OF_VERSION_1_3_check(
    of_oxm_arp_tha_masked_t *obj, int value);
extern int of_oxm_arp_tha_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_arp_tha_masked_t *obj, int value);
extern int of_oxm_arp_tha_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_arp_tha_masked_t *obj, int value);

extern int of_oxm_arp_tpa_OF_VERSION_1_3_populate(
    of_oxm_arp_tpa_t *obj, int value);
extern int of_oxm_arp_tpa_OF_VERSION_1_3_check(
    of_oxm_arp_tpa_t *obj, int value);
extern int of_oxm_arp_tpa_OF_VERSION_1_3_populate_scalars(
    of_oxm_arp_tpa_t *obj, int value);
extern int of_oxm_arp_tpa_OF_VERSION_1_3_check_scalars(
    of_oxm_arp_tpa_t *obj, int value);

extern int of_oxm_arp_tpa_masked_OF_VERSION_1_3_populate(
    of_oxm_arp_tpa_masked_t *obj, int value);
extern int of_oxm_arp_tpa_masked_OF_VERSION_1_3_check(
    of_oxm_arp_tpa_masked_t *obj, int value);
extern int of_oxm_arp_tpa_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_arp_tpa_masked_t *obj, int value);
extern int of_oxm_arp_tpa_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_arp_tpa_masked_t *obj, int value);

extern int of_oxm_bsn_egr_port_group_id_OF_VERSION_1_3_populate(
    of_oxm_bsn_egr_port_group_id_t *obj, int value);
extern int of_oxm_bsn_egr_port_group_id_OF_VERSION_1_3_check(
    of_oxm_bsn_egr_port_group_id_t *obj, int value);
extern int of_oxm_bsn_egr_port_group_id_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_egr_port_group_id_t *obj, int value);
extern int of_oxm_bsn_egr_port_group_id_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_egr_port_group_id_t *obj, int value);

extern int of_oxm_bsn_egr_port_group_id_masked_OF_VERSION_1_3_populate(
    of_oxm_bsn_egr_port_group_id_masked_t *obj, int value);
extern int of_oxm_bsn_egr_port_group_id_masked_OF_VERSION_1_3_check(
    of_oxm_bsn_egr_port_group_id_masked_t *obj, int value);
extern int of_oxm_bsn_egr_port_group_id_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_egr_port_group_id_masked_t *obj, int value);
extern int of_oxm_bsn_egr_port_group_id_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_egr_port_group_id_masked_t *obj, int value);

extern int of_oxm_bsn_global_vrf_allowed_OF_VERSION_1_3_populate(
    of_oxm_bsn_global_vrf_allowed_t *obj, int value);
extern int of_oxm_bsn_global_vrf_allowed_OF_VERSION_1_3_check(
    of_oxm_bsn_global_vrf_allowed_t *obj, int value);
extern int of_oxm_bsn_global_vrf_allowed_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_global_vrf_allowed_t *obj, int value);
extern int of_oxm_bsn_global_vrf_allowed_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_global_vrf_allowed_t *obj, int value);

extern int of_oxm_bsn_global_vrf_allowed_masked_OF_VERSION_1_3_populate(
    of_oxm_bsn_global_vrf_allowed_masked_t *obj, int value);
extern int of_oxm_bsn_global_vrf_allowed_masked_OF_VERSION_1_3_check(
    of_oxm_bsn_global_vrf_allowed_masked_t *obj, int value);
extern int of_oxm_bsn_global_vrf_allowed_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_global_vrf_allowed_masked_t *obj, int value);
extern int of_oxm_bsn_global_vrf_allowed_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_global_vrf_allowed_masked_t *obj, int value);

extern int of_oxm_bsn_in_ports_128_OF_VERSION_1_3_populate(
    of_oxm_bsn_in_ports_128_t *obj, int value);
extern int of_oxm_bsn_in_ports_128_OF_VERSION_1_3_check(
    of_oxm_bsn_in_ports_128_t *obj, int value);
extern int of_oxm_bsn_in_ports_128_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_in_ports_128_t *obj, int value);
extern int of_oxm_bsn_in_ports_128_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_in_ports_128_t *obj, int value);

extern int of_oxm_bsn_in_ports_128_masked_OF_VERSION_1_3_populate(
    of_oxm_bsn_in_ports_128_masked_t *obj, int value);
extern int of_oxm_bsn_in_ports_128_masked_OF_VERSION_1_3_check(
    of_oxm_bsn_in_ports_128_masked_t *obj, int value);
extern int of_oxm_bsn_in_ports_128_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_in_ports_128_masked_t *obj, int value);
extern int of_oxm_bsn_in_ports_128_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_in_ports_128_masked_t *obj, int value);

extern int of_oxm_bsn_in_ports_512_OF_VERSION_1_3_populate(
    of_oxm_bsn_in_ports_512_t *obj, int value);
extern int of_oxm_bsn_in_ports_512_OF_VERSION_1_3_check(
    of_oxm_bsn_in_ports_512_t *obj, int value);
extern int of_oxm_bsn_in_ports_512_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_in_ports_512_t *obj, int value);
extern int of_oxm_bsn_in_ports_512_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_in_ports_512_t *obj, int value);

extern int of_oxm_bsn_in_ports_512_masked_OF_VERSION_1_3_populate(
    of_oxm_bsn_in_ports_512_masked_t *obj, int value);
extern int of_oxm_bsn_in_ports_512_masked_OF_VERSION_1_3_check(
    of_oxm_bsn_in_ports_512_masked_t *obj, int value);
extern int of_oxm_bsn_in_ports_512_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_in_ports_512_masked_t *obj, int value);
extern int of_oxm_bsn_in_ports_512_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_in_ports_512_masked_t *obj, int value);

extern int of_oxm_bsn_ingress_port_group_id_OF_VERSION_1_3_populate(
    of_oxm_bsn_ingress_port_group_id_t *obj, int value);
extern int of_oxm_bsn_ingress_port_group_id_OF_VERSION_1_3_check(
    of_oxm_bsn_ingress_port_group_id_t *obj, int value);
extern int of_oxm_bsn_ingress_port_group_id_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_ingress_port_group_id_t *obj, int value);
extern int of_oxm_bsn_ingress_port_group_id_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_ingress_port_group_id_t *obj, int value);

extern int of_oxm_bsn_ingress_port_group_id_masked_OF_VERSION_1_3_populate(
    of_oxm_bsn_ingress_port_group_id_masked_t *obj, int value);
extern int of_oxm_bsn_ingress_port_group_id_masked_OF_VERSION_1_3_check(
    of_oxm_bsn_ingress_port_group_id_masked_t *obj, int value);
extern int of_oxm_bsn_ingress_port_group_id_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_ingress_port_group_id_masked_t *obj, int value);
extern int of_oxm_bsn_ingress_port_group_id_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_ingress_port_group_id_masked_t *obj, int value);

extern int of_oxm_bsn_inner_eth_dst_OF_VERSION_1_3_populate(
    of_oxm_bsn_inner_eth_dst_t *obj, int value);
extern int of_oxm_bsn_inner_eth_dst_OF_VERSION_1_3_check(
    of_oxm_bsn_inner_eth_dst_t *obj, int value);
extern int of_oxm_bsn_inner_eth_dst_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_inner_eth_dst_t *obj, int value);
extern int of_oxm_bsn_inner_eth_dst_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_inner_eth_dst_t *obj, int value);

extern int of_oxm_bsn_inner_eth_dst_masked_OF_VERSION_1_3_populate(
    of_oxm_bsn_inner_eth_dst_masked_t *obj, int value);
extern int of_oxm_bsn_inner_eth_dst_masked_OF_VERSION_1_3_check(
    of_oxm_bsn_inner_eth_dst_masked_t *obj, int value);
extern int of_oxm_bsn_inner_eth_dst_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_inner_eth_dst_masked_t *obj, int value);
extern int of_oxm_bsn_inner_eth_dst_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_inner_eth_dst_masked_t *obj, int value);

extern int of_oxm_bsn_inner_eth_src_OF_VERSION_1_3_populate(
    of_oxm_bsn_inner_eth_src_t *obj, int value);
extern int of_oxm_bsn_inner_eth_src_OF_VERSION_1_3_check(
    of_oxm_bsn_inner_eth_src_t *obj, int value);
extern int of_oxm_bsn_inner_eth_src_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_inner_eth_src_t *obj, int value);
extern int of_oxm_bsn_inner_eth_src_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_inner_eth_src_t *obj, int value);

extern int of_oxm_bsn_inner_eth_src_masked_OF_VERSION_1_3_populate(
    of_oxm_bsn_inner_eth_src_masked_t *obj, int value);
extern int of_oxm_bsn_inner_eth_src_masked_OF_VERSION_1_3_check(
    of_oxm_bsn_inner_eth_src_masked_t *obj, int value);
extern int of_oxm_bsn_inner_eth_src_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_inner_eth_src_masked_t *obj, int value);
extern int of_oxm_bsn_inner_eth_src_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_inner_eth_src_masked_t *obj, int value);

extern int of_oxm_bsn_inner_vlan_vid_OF_VERSION_1_3_populate(
    of_oxm_bsn_inner_vlan_vid_t *obj, int value);
extern int of_oxm_bsn_inner_vlan_vid_OF_VERSION_1_3_check(
    of_oxm_bsn_inner_vlan_vid_t *obj, int value);
extern int of_oxm_bsn_inner_vlan_vid_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_inner_vlan_vid_t *obj, int value);
extern int of_oxm_bsn_inner_vlan_vid_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_inner_vlan_vid_t *obj, int value);

extern int of_oxm_bsn_inner_vlan_vid_masked_OF_VERSION_1_3_populate(
    of_oxm_bsn_inner_vlan_vid_masked_t *obj, int value);
extern int of_oxm_bsn_inner_vlan_vid_masked_OF_VERSION_1_3_check(
    of_oxm_bsn_inner_vlan_vid_masked_t *obj, int value);
extern int of_oxm_bsn_inner_vlan_vid_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_inner_vlan_vid_masked_t *obj, int value);
extern int of_oxm_bsn_inner_vlan_vid_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_inner_vlan_vid_masked_t *obj, int value);

extern int of_oxm_bsn_ip_fragmentation_OF_VERSION_1_3_populate(
    of_oxm_bsn_ip_fragmentation_t *obj, int value);
extern int of_oxm_bsn_ip_fragmentation_OF_VERSION_1_3_check(
    of_oxm_bsn_ip_fragmentation_t *obj, int value);
extern int of_oxm_bsn_ip_fragmentation_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_ip_fragmentation_t *obj, int value);
extern int of_oxm_bsn_ip_fragmentation_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_ip_fragmentation_t *obj, int value);

extern int of_oxm_bsn_ip_fragmentation_masked_OF_VERSION_1_3_populate(
    of_oxm_bsn_ip_fragmentation_masked_t *obj, int value);
extern int of_oxm_bsn_ip_fragmentation_masked_OF_VERSION_1_3_check(
    of_oxm_bsn_ip_fragmentation_masked_t *obj, int value);
extern int of_oxm_bsn_ip_fragmentation_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_ip_fragmentation_masked_t *obj, int value);
extern int of_oxm_bsn_ip_fragmentation_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_ip_fragmentation_masked_t *obj, int value);

extern int of_oxm_bsn_l2_cache_hit_OF_VERSION_1_3_populate(
    of_oxm_bsn_l2_cache_hit_t *obj, int value);
extern int of_oxm_bsn_l2_cache_hit_OF_VERSION_1_3_check(
    of_oxm_bsn_l2_cache_hit_t *obj, int value);
extern int of_oxm_bsn_l2_cache_hit_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_l2_cache_hit_t *obj, int value);
extern int of_oxm_bsn_l2_cache_hit_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_l2_cache_hit_t *obj, int value);

extern int of_oxm_bsn_l2_cache_hit_masked_OF_VERSION_1_3_populate(
    of_oxm_bsn_l2_cache_hit_masked_t *obj, int value);
extern int of_oxm_bsn_l2_cache_hit_masked_OF_VERSION_1_3_check(
    of_oxm_bsn_l2_cache_hit_masked_t *obj, int value);
extern int of_oxm_bsn_l2_cache_hit_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_l2_cache_hit_masked_t *obj, int value);
extern int of_oxm_bsn_l2_cache_hit_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_l2_cache_hit_masked_t *obj, int value);

extern int of_oxm_bsn_l3_dst_class_id_OF_VERSION_1_3_populate(
    of_oxm_bsn_l3_dst_class_id_t *obj, int value);
extern int of_oxm_bsn_l3_dst_class_id_OF_VERSION_1_3_check(
    of_oxm_bsn_l3_dst_class_id_t *obj, int value);
extern int of_oxm_bsn_l3_dst_class_id_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_l3_dst_class_id_t *obj, int value);
extern int of_oxm_bsn_l3_dst_class_id_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_l3_dst_class_id_t *obj, int value);

extern int of_oxm_bsn_l3_dst_class_id_masked_OF_VERSION_1_3_populate(
    of_oxm_bsn_l3_dst_class_id_masked_t *obj, int value);
extern int of_oxm_bsn_l3_dst_class_id_masked_OF_VERSION_1_3_check(
    of_oxm_bsn_l3_dst_class_id_masked_t *obj, int value);
extern int of_oxm_bsn_l3_dst_class_id_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_l3_dst_class_id_masked_t *obj, int value);
extern int of_oxm_bsn_l3_dst_class_id_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_l3_dst_class_id_masked_t *obj, int value);

extern int of_oxm_bsn_l3_interface_class_id_OF_VERSION_1_3_populate(
    of_oxm_bsn_l3_interface_class_id_t *obj, int value);
extern int of_oxm_bsn_l3_interface_class_id_OF_VERSION_1_3_check(
    of_oxm_bsn_l3_interface_class_id_t *obj, int value);
extern int of_oxm_bsn_l3_interface_class_id_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_l3_interface_class_id_t *obj, int value);
extern int of_oxm_bsn_l3_interface_class_id_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_l3_interface_class_id_t *obj, int value);

extern int of_oxm_bsn_l3_interface_class_id_masked_OF_VERSION_1_3_populate(
    of_oxm_bsn_l3_interface_class_id_masked_t *obj, int value);
extern int of_oxm_bsn_l3_interface_class_id_masked_OF_VERSION_1_3_check(
    of_oxm_bsn_l3_interface_class_id_masked_t *obj, int value);
extern int of_oxm_bsn_l3_interface_class_id_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_l3_interface_class_id_masked_t *obj, int value);
extern int of_oxm_bsn_l3_interface_class_id_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_l3_interface_class_id_masked_t *obj, int value);

extern int of_oxm_bsn_l3_src_class_id_OF_VERSION_1_3_populate(
    of_oxm_bsn_l3_src_class_id_t *obj, int value);
extern int of_oxm_bsn_l3_src_class_id_OF_VERSION_1_3_check(
    of_oxm_bsn_l3_src_class_id_t *obj, int value);
extern int of_oxm_bsn_l3_src_class_id_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_l3_src_class_id_t *obj, int value);
extern int of_oxm_bsn_l3_src_class_id_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_l3_src_class_id_t *obj, int value);

extern int of_oxm_bsn_l3_src_class_id_masked_OF_VERSION_1_3_populate(
    of_oxm_bsn_l3_src_class_id_masked_t *obj, int value);
extern int of_oxm_bsn_l3_src_class_id_masked_OF_VERSION_1_3_check(
    of_oxm_bsn_l3_src_class_id_masked_t *obj, int value);
extern int of_oxm_bsn_l3_src_class_id_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_l3_src_class_id_masked_t *obj, int value);
extern int of_oxm_bsn_l3_src_class_id_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_l3_src_class_id_masked_t *obj, int value);

extern int of_oxm_bsn_lag_id_OF_VERSION_1_3_populate(
    of_oxm_bsn_lag_id_t *obj, int value);
extern int of_oxm_bsn_lag_id_OF_VERSION_1_3_check(
    of_oxm_bsn_lag_id_t *obj, int value);
extern int of_oxm_bsn_lag_id_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_lag_id_t *obj, int value);
extern int of_oxm_bsn_lag_id_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_lag_id_t *obj, int value);

extern int of_oxm_bsn_lag_id_masked_OF_VERSION_1_3_populate(
    of_oxm_bsn_lag_id_masked_t *obj, int value);
extern int of_oxm_bsn_lag_id_masked_OF_VERSION_1_3_check(
    of_oxm_bsn_lag_id_masked_t *obj, int value);
extern int of_oxm_bsn_lag_id_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_lag_id_masked_t *obj, int value);
extern int of_oxm_bsn_lag_id_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_lag_id_masked_t *obj, int value);

extern int of_oxm_bsn_tcp_flags_OF_VERSION_1_3_populate(
    of_oxm_bsn_tcp_flags_t *obj, int value);
extern int of_oxm_bsn_tcp_flags_OF_VERSION_1_3_check(
    of_oxm_bsn_tcp_flags_t *obj, int value);
extern int of_oxm_bsn_tcp_flags_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_tcp_flags_t *obj, int value);
extern int of_oxm_bsn_tcp_flags_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_tcp_flags_t *obj, int value);

extern int of_oxm_bsn_tcp_flags_masked_OF_VERSION_1_3_populate(
    of_oxm_bsn_tcp_flags_masked_t *obj, int value);
extern int of_oxm_bsn_tcp_flags_masked_OF_VERSION_1_3_check(
    of_oxm_bsn_tcp_flags_masked_t *obj, int value);
extern int of_oxm_bsn_tcp_flags_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_tcp_flags_masked_t *obj, int value);
extern int of_oxm_bsn_tcp_flags_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_tcp_flags_masked_t *obj, int value);

extern int of_oxm_bsn_udf0_OF_VERSION_1_3_populate(
    of_oxm_bsn_udf0_t *obj, int value);
extern int of_oxm_bsn_udf0_OF_VERSION_1_3_check(
    of_oxm_bsn_udf0_t *obj, int value);
extern int of_oxm_bsn_udf0_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_udf0_t *obj, int value);
extern int of_oxm_bsn_udf0_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_udf0_t *obj, int value);

extern int of_oxm_bsn_udf0_masked_OF_VERSION_1_3_populate(
    of_oxm_bsn_udf0_masked_t *obj, int value);
extern int of_oxm_bsn_udf0_masked_OF_VERSION_1_3_check(
    of_oxm_bsn_udf0_masked_t *obj, int value);
extern int of_oxm_bsn_udf0_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_udf0_masked_t *obj, int value);
extern int of_oxm_bsn_udf0_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_udf0_masked_t *obj, int value);

extern int of_oxm_bsn_udf1_OF_VERSION_1_3_populate(
    of_oxm_bsn_udf1_t *obj, int value);
extern int of_oxm_bsn_udf1_OF_VERSION_1_3_check(
    of_oxm_bsn_udf1_t *obj, int value);
extern int of_oxm_bsn_udf1_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_udf1_t *obj, int value);
extern int of_oxm_bsn_udf1_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_udf1_t *obj, int value);

extern int of_oxm_bsn_udf1_masked_OF_VERSION_1_3_populate(
    of_oxm_bsn_udf1_masked_t *obj, int value);
extern int of_oxm_bsn_udf1_masked_OF_VERSION_1_3_check(
    of_oxm_bsn_udf1_masked_t *obj, int value);
extern int of_oxm_bsn_udf1_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_udf1_masked_t *obj, int value);
extern int of_oxm_bsn_udf1_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_udf1_masked_t *obj, int value);

extern int of_oxm_bsn_udf2_OF_VERSION_1_3_populate(
    of_oxm_bsn_udf2_t *obj, int value);
extern int of_oxm_bsn_udf2_OF_VERSION_1_3_check(
    of_oxm_bsn_udf2_t *obj, int value);
extern int of_oxm_bsn_udf2_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_udf2_t *obj, int value);
extern int of_oxm_bsn_udf2_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_udf2_t *obj, int value);

extern int of_oxm_bsn_udf2_masked_OF_VERSION_1_3_populate(
    of_oxm_bsn_udf2_masked_t *obj, int value);
extern int of_oxm_bsn_udf2_masked_OF_VERSION_1_3_check(
    of_oxm_bsn_udf2_masked_t *obj, int value);
extern int of_oxm_bsn_udf2_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_udf2_masked_t *obj, int value);
extern int of_oxm_bsn_udf2_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_udf2_masked_t *obj, int value);

extern int of_oxm_bsn_udf3_OF_VERSION_1_3_populate(
    of_oxm_bsn_udf3_t *obj, int value);
extern int of_oxm_bsn_udf3_OF_VERSION_1_3_check(
    of_oxm_bsn_udf3_t *obj, int value);
extern int of_oxm_bsn_udf3_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_udf3_t *obj, int value);
extern int of_oxm_bsn_udf3_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_udf3_t *obj, int value);

extern int of_oxm_bsn_udf3_masked_OF_VERSION_1_3_populate(
    of_oxm_bsn_udf3_masked_t *obj, int value);
extern int of_oxm_bsn_udf3_masked_OF_VERSION_1_3_check(
    of_oxm_bsn_udf3_masked_t *obj, int value);
extern int of_oxm_bsn_udf3_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_udf3_masked_t *obj, int value);
extern int of_oxm_bsn_udf3_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_udf3_masked_t *obj, int value);

extern int of_oxm_bsn_udf4_OF_VERSION_1_3_populate(
    of_oxm_bsn_udf4_t *obj, int value);
extern int of_oxm_bsn_udf4_OF_VERSION_1_3_check(
    of_oxm_bsn_udf4_t *obj, int value);
extern int of_oxm_bsn_udf4_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_udf4_t *obj, int value);
extern int of_oxm_bsn_udf4_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_udf4_t *obj, int value);

extern int of_oxm_bsn_udf4_masked_OF_VERSION_1_3_populate(
    of_oxm_bsn_udf4_masked_t *obj, int value);
extern int of_oxm_bsn_udf4_masked_OF_VERSION_1_3_check(
    of_oxm_bsn_udf4_masked_t *obj, int value);
extern int of_oxm_bsn_udf4_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_udf4_masked_t *obj, int value);
extern int of_oxm_bsn_udf4_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_udf4_masked_t *obj, int value);

extern int of_oxm_bsn_udf5_OF_VERSION_1_3_populate(
    of_oxm_bsn_udf5_t *obj, int value);
extern int of_oxm_bsn_udf5_OF_VERSION_1_3_check(
    of_oxm_bsn_udf5_t *obj, int value);
extern int of_oxm_bsn_udf5_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_udf5_t *obj, int value);
extern int of_oxm_bsn_udf5_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_udf5_t *obj, int value);

extern int of_oxm_bsn_udf5_masked_OF_VERSION_1_3_populate(
    of_oxm_bsn_udf5_masked_t *obj, int value);
extern int of_oxm_bsn_udf5_masked_OF_VERSION_1_3_check(
    of_oxm_bsn_udf5_masked_t *obj, int value);
extern int of_oxm_bsn_udf5_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_udf5_masked_t *obj, int value);
extern int of_oxm_bsn_udf5_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_udf5_masked_t *obj, int value);

extern int of_oxm_bsn_udf6_OF_VERSION_1_3_populate(
    of_oxm_bsn_udf6_t *obj, int value);
extern int of_oxm_bsn_udf6_OF_VERSION_1_3_check(
    of_oxm_bsn_udf6_t *obj, int value);
extern int of_oxm_bsn_udf6_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_udf6_t *obj, int value);
extern int of_oxm_bsn_udf6_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_udf6_t *obj, int value);

extern int of_oxm_bsn_udf6_masked_OF_VERSION_1_3_populate(
    of_oxm_bsn_udf6_masked_t *obj, int value);
extern int of_oxm_bsn_udf6_masked_OF_VERSION_1_3_check(
    of_oxm_bsn_udf6_masked_t *obj, int value);
extern int of_oxm_bsn_udf6_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_udf6_masked_t *obj, int value);
extern int of_oxm_bsn_udf6_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_udf6_masked_t *obj, int value);

extern int of_oxm_bsn_udf7_OF_VERSION_1_3_populate(
    of_oxm_bsn_udf7_t *obj, int value);
extern int of_oxm_bsn_udf7_OF_VERSION_1_3_check(
    of_oxm_bsn_udf7_t *obj, int value);
extern int of_oxm_bsn_udf7_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_udf7_t *obj, int value);
extern int of_oxm_bsn_udf7_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_udf7_t *obj, int value);

extern int of_oxm_bsn_udf7_masked_OF_VERSION_1_3_populate(
    of_oxm_bsn_udf7_masked_t *obj, int value);
extern int of_oxm_bsn_udf7_masked_OF_VERSION_1_3_check(
    of_oxm_bsn_udf7_masked_t *obj, int value);
extern int of_oxm_bsn_udf7_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_udf7_masked_t *obj, int value);
extern int of_oxm_bsn_udf7_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_udf7_masked_t *obj, int value);

extern int of_oxm_bsn_vfi_OF_VERSION_1_3_populate(
    of_oxm_bsn_vfi_t *obj, int value);
extern int of_oxm_bsn_vfi_OF_VERSION_1_3_check(
    of_oxm_bsn_vfi_t *obj, int value);
extern int of_oxm_bsn_vfi_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_vfi_t *obj, int value);
extern int of_oxm_bsn_vfi_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_vfi_t *obj, int value);

extern int of_oxm_bsn_vfi_masked_OF_VERSION_1_3_populate(
    of_oxm_bsn_vfi_masked_t *obj, int value);
extern int of_oxm_bsn_vfi_masked_OF_VERSION_1_3_check(
    of_oxm_bsn_vfi_masked_t *obj, int value);
extern int of_oxm_bsn_vfi_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_vfi_masked_t *obj, int value);
extern int of_oxm_bsn_vfi_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_vfi_masked_t *obj, int value);

extern int of_oxm_bsn_vlan_xlate_port_group_id_OF_VERSION_1_3_populate(
    of_oxm_bsn_vlan_xlate_port_group_id_t *obj, int value);
extern int of_oxm_bsn_vlan_xlate_port_group_id_OF_VERSION_1_3_check(
    of_oxm_bsn_vlan_xlate_port_group_id_t *obj, int value);
extern int of_oxm_bsn_vlan_xlate_port_group_id_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_vlan_xlate_port_group_id_t *obj, int value);
extern int of_oxm_bsn_vlan_xlate_port_group_id_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_vlan_xlate_port_group_id_t *obj, int value);

extern int of_oxm_bsn_vlan_xlate_port_group_id_masked_OF_VERSION_1_3_populate(
    of_oxm_bsn_vlan_xlate_port_group_id_masked_t *obj, int value);
extern int of_oxm_bsn_vlan_xlate_port_group_id_masked_OF_VERSION_1_3_check(
    of_oxm_bsn_vlan_xlate_port_group_id_masked_t *obj, int value);
extern int of_oxm_bsn_vlan_xlate_port_group_id_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_vlan_xlate_port_group_id_masked_t *obj, int value);
extern int of_oxm_bsn_vlan_xlate_port_group_id_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_vlan_xlate_port_group_id_masked_t *obj, int value);

extern int of_oxm_bsn_vrf_OF_VERSION_1_3_populate(
    of_oxm_bsn_vrf_t *obj, int value);
extern int of_oxm_bsn_vrf_OF_VERSION_1_3_check(
    of_oxm_bsn_vrf_t *obj, int value);
extern int of_oxm_bsn_vrf_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_vrf_t *obj, int value);
extern int of_oxm_bsn_vrf_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_vrf_t *obj, int value);

extern int of_oxm_bsn_vrf_masked_OF_VERSION_1_3_populate(
    of_oxm_bsn_vrf_masked_t *obj, int value);
extern int of_oxm_bsn_vrf_masked_OF_VERSION_1_3_check(
    of_oxm_bsn_vrf_masked_t *obj, int value);
extern int of_oxm_bsn_vrf_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_vrf_masked_t *obj, int value);
extern int of_oxm_bsn_vrf_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_vrf_masked_t *obj, int value);

extern int of_oxm_bsn_vxlan_network_id_OF_VERSION_1_3_populate(
    of_oxm_bsn_vxlan_network_id_t *obj, int value);
extern int of_oxm_bsn_vxlan_network_id_OF_VERSION_1_3_check(
    of_oxm_bsn_vxlan_network_id_t *obj, int value);
extern int of_oxm_bsn_vxlan_network_id_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_vxlan_network_id_t *obj, int value);
extern int of_oxm_bsn_vxlan_network_id_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_vxlan_network_id_t *obj, int value);

extern int of_oxm_bsn_vxlan_network_id_masked_OF_VERSION_1_3_populate(
    of_oxm_bsn_vxlan_network_id_masked_t *obj, int value);
extern int of_oxm_bsn_vxlan_network_id_masked_OF_VERSION_1_3_check(
    of_oxm_bsn_vxlan_network_id_masked_t *obj, int value);
extern int of_oxm_bsn_vxlan_network_id_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_bsn_vxlan_network_id_masked_t *obj, int value);
extern int of_oxm_bsn_vxlan_network_id_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_bsn_vxlan_network_id_masked_t *obj, int value);

extern int of_oxm_eth_dst_OF_VERSION_1_3_populate(
    of_oxm_eth_dst_t *obj, int value);
extern int of_oxm_eth_dst_OF_VERSION_1_3_check(
    of_oxm_eth_dst_t *obj, int value);
extern int of_oxm_eth_dst_OF_VERSION_1_3_populate_scalars(
    of_oxm_eth_dst_t *obj, int value);
extern int of_oxm_eth_dst_OF_VERSION_1_3_check_scalars(
    of_oxm_eth_dst_t *obj, int value);

extern int of_oxm_eth_dst_masked_OF_VERSION_1_3_populate(
    of_oxm_eth_dst_masked_t *obj, int value);
extern int of_oxm_eth_dst_masked_OF_VERSION_1_3_check(
    of_oxm_eth_dst_masked_t *obj, int value);
extern int of_oxm_eth_dst_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_eth_dst_masked_t *obj, int value);
extern int of_oxm_eth_dst_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_eth_dst_masked_t *obj, int value);

extern int of_oxm_eth_src_OF_VERSION_1_3_populate(
    of_oxm_eth_src_t *obj, int value);
extern int of_oxm_eth_src_OF_VERSION_1_3_check(
    of_oxm_eth_src_t *obj, int value);
extern int of_oxm_eth_src_OF_VERSION_1_3_populate_scalars(
    of_oxm_eth_src_t *obj, int value);
extern int of_oxm_eth_src_OF_VERSION_1_3_check_scalars(
    of_oxm_eth_src_t *obj, int value);

extern int of_oxm_eth_src_masked_OF_VERSION_1_3_populate(
    of_oxm_eth_src_masked_t *obj, int value);
extern int of_oxm_eth_src_masked_OF_VERSION_1_3_check(
    of_oxm_eth_src_masked_t *obj, int value);
extern int of_oxm_eth_src_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_eth_src_masked_t *obj, int value);
extern int of_oxm_eth_src_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_eth_src_masked_t *obj, int value);

extern int of_oxm_eth_type_OF_VERSION_1_3_populate(
    of_oxm_eth_type_t *obj, int value);
extern int of_oxm_eth_type_OF_VERSION_1_3_check(
    of_oxm_eth_type_t *obj, int value);
extern int of_oxm_eth_type_OF_VERSION_1_3_populate_scalars(
    of_oxm_eth_type_t *obj, int value);
extern int of_oxm_eth_type_OF_VERSION_1_3_check_scalars(
    of_oxm_eth_type_t *obj, int value);

extern int of_oxm_eth_type_masked_OF_VERSION_1_3_populate(
    of_oxm_eth_type_masked_t *obj, int value);
extern int of_oxm_eth_type_masked_OF_VERSION_1_3_check(
    of_oxm_eth_type_masked_t *obj, int value);
extern int of_oxm_eth_type_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_eth_type_masked_t *obj, int value);
extern int of_oxm_eth_type_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_eth_type_masked_t *obj, int value);

extern int of_oxm_icmpv4_code_OF_VERSION_1_3_populate(
    of_oxm_icmpv4_code_t *obj, int value);
extern int of_oxm_icmpv4_code_OF_VERSION_1_3_check(
    of_oxm_icmpv4_code_t *obj, int value);
extern int of_oxm_icmpv4_code_OF_VERSION_1_3_populate_scalars(
    of_oxm_icmpv4_code_t *obj, int value);
extern int of_oxm_icmpv4_code_OF_VERSION_1_3_check_scalars(
    of_oxm_icmpv4_code_t *obj, int value);

extern int of_oxm_icmpv4_code_masked_OF_VERSION_1_3_populate(
    of_oxm_icmpv4_code_masked_t *obj, int value);
extern int of_oxm_icmpv4_code_masked_OF_VERSION_1_3_check(
    of_oxm_icmpv4_code_masked_t *obj, int value);
extern int of_oxm_icmpv4_code_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_icmpv4_code_masked_t *obj, int value);
extern int of_oxm_icmpv4_code_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_icmpv4_code_masked_t *obj, int value);

extern int of_oxm_icmpv4_type_OF_VERSION_1_3_populate(
    of_oxm_icmpv4_type_t *obj, int value);
extern int of_oxm_icmpv4_type_OF_VERSION_1_3_check(
    of_oxm_icmpv4_type_t *obj, int value);
extern int of_oxm_icmpv4_type_OF_VERSION_1_3_populate_scalars(
    of_oxm_icmpv4_type_t *obj, int value);
extern int of_oxm_icmpv4_type_OF_VERSION_1_3_check_scalars(
    of_oxm_icmpv4_type_t *obj, int value);

extern int of_oxm_icmpv4_type_masked_OF_VERSION_1_3_populate(
    of_oxm_icmpv4_type_masked_t *obj, int value);
extern int of_oxm_icmpv4_type_masked_OF_VERSION_1_3_check(
    of_oxm_icmpv4_type_masked_t *obj, int value);
extern int of_oxm_icmpv4_type_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_icmpv4_type_masked_t *obj, int value);
extern int of_oxm_icmpv4_type_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_icmpv4_type_masked_t *obj, int value);

extern int of_oxm_icmpv6_code_OF_VERSION_1_3_populate(
    of_oxm_icmpv6_code_t *obj, int value);
extern int of_oxm_icmpv6_code_OF_VERSION_1_3_check(
    of_oxm_icmpv6_code_t *obj, int value);
extern int of_oxm_icmpv6_code_OF_VERSION_1_3_populate_scalars(
    of_oxm_icmpv6_code_t *obj, int value);
extern int of_oxm_icmpv6_code_OF_VERSION_1_3_check_scalars(
    of_oxm_icmpv6_code_t *obj, int value);

extern int of_oxm_icmpv6_code_masked_OF_VERSION_1_3_populate(
    of_oxm_icmpv6_code_masked_t *obj, int value);
extern int of_oxm_icmpv6_code_masked_OF_VERSION_1_3_check(
    of_oxm_icmpv6_code_masked_t *obj, int value);
extern int of_oxm_icmpv6_code_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_icmpv6_code_masked_t *obj, int value);
extern int of_oxm_icmpv6_code_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_icmpv6_code_masked_t *obj, int value);

extern int of_oxm_icmpv6_type_OF_VERSION_1_3_populate(
    of_oxm_icmpv6_type_t *obj, int value);
extern int of_oxm_icmpv6_type_OF_VERSION_1_3_check(
    of_oxm_icmpv6_type_t *obj, int value);
extern int of_oxm_icmpv6_type_OF_VERSION_1_3_populate_scalars(
    of_oxm_icmpv6_type_t *obj, int value);
extern int of_oxm_icmpv6_type_OF_VERSION_1_3_check_scalars(
    of_oxm_icmpv6_type_t *obj, int value);

extern int of_oxm_icmpv6_type_masked_OF_VERSION_1_3_populate(
    of_oxm_icmpv6_type_masked_t *obj, int value);
extern int of_oxm_icmpv6_type_masked_OF_VERSION_1_3_check(
    of_oxm_icmpv6_type_masked_t *obj, int value);
extern int of_oxm_icmpv6_type_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_icmpv6_type_masked_t *obj, int value);
extern int of_oxm_icmpv6_type_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_icmpv6_type_masked_t *obj, int value);

extern int of_oxm_in_phy_port_OF_VERSION_1_3_populate(
    of_oxm_in_phy_port_t *obj, int value);
extern int of_oxm_in_phy_port_OF_VERSION_1_3_check(
    of_oxm_in_phy_port_t *obj, int value);
extern int of_oxm_in_phy_port_OF_VERSION_1_3_populate_scalars(
    of_oxm_in_phy_port_t *obj, int value);
extern int of_oxm_in_phy_port_OF_VERSION_1_3_check_scalars(
    of_oxm_in_phy_port_t *obj, int value);

extern int of_oxm_in_phy_port_masked_OF_VERSION_1_3_populate(
    of_oxm_in_phy_port_masked_t *obj, int value);
extern int of_oxm_in_phy_port_masked_OF_VERSION_1_3_check(
    of_oxm_in_phy_port_masked_t *obj, int value);
extern int of_oxm_in_phy_port_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_in_phy_port_masked_t *obj, int value);
extern int of_oxm_in_phy_port_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_in_phy_port_masked_t *obj, int value);

extern int of_oxm_in_port_OF_VERSION_1_3_populate(
    of_oxm_in_port_t *obj, int value);
extern int of_oxm_in_port_OF_VERSION_1_3_check(
    of_oxm_in_port_t *obj, int value);
extern int of_oxm_in_port_OF_VERSION_1_3_populate_scalars(
    of_oxm_in_port_t *obj, int value);
extern int of_oxm_in_port_OF_VERSION_1_3_check_scalars(
    of_oxm_in_port_t *obj, int value);

extern int of_oxm_in_port_masked_OF_VERSION_1_3_populate(
    of_oxm_in_port_masked_t *obj, int value);
extern int of_oxm_in_port_masked_OF_VERSION_1_3_check(
    of_oxm_in_port_masked_t *obj, int value);
extern int of_oxm_in_port_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_in_port_masked_t *obj, int value);
extern int of_oxm_in_port_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_in_port_masked_t *obj, int value);

extern int of_oxm_ip_dscp_OF_VERSION_1_3_populate(
    of_oxm_ip_dscp_t *obj, int value);
extern int of_oxm_ip_dscp_OF_VERSION_1_3_check(
    of_oxm_ip_dscp_t *obj, int value);
extern int of_oxm_ip_dscp_OF_VERSION_1_3_populate_scalars(
    of_oxm_ip_dscp_t *obj, int value);
extern int of_oxm_ip_dscp_OF_VERSION_1_3_check_scalars(
    of_oxm_ip_dscp_t *obj, int value);

extern int of_oxm_ip_dscp_masked_OF_VERSION_1_3_populate(
    of_oxm_ip_dscp_masked_t *obj, int value);
extern int of_oxm_ip_dscp_masked_OF_VERSION_1_3_check(
    of_oxm_ip_dscp_masked_t *obj, int value);
extern int of_oxm_ip_dscp_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_ip_dscp_masked_t *obj, int value);
extern int of_oxm_ip_dscp_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_ip_dscp_masked_t *obj, int value);

extern int of_oxm_ip_ecn_OF_VERSION_1_3_populate(
    of_oxm_ip_ecn_t *obj, int value);
extern int of_oxm_ip_ecn_OF_VERSION_1_3_check(
    of_oxm_ip_ecn_t *obj, int value);
extern int of_oxm_ip_ecn_OF_VERSION_1_3_populate_scalars(
    of_oxm_ip_ecn_t *obj, int value);
extern int of_oxm_ip_ecn_OF_VERSION_1_3_check_scalars(
    of_oxm_ip_ecn_t *obj, int value);

extern int of_oxm_ip_ecn_masked_OF_VERSION_1_3_populate(
    of_oxm_ip_ecn_masked_t *obj, int value);
extern int of_oxm_ip_ecn_masked_OF_VERSION_1_3_check(
    of_oxm_ip_ecn_masked_t *obj, int value);
extern int of_oxm_ip_ecn_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_ip_ecn_masked_t *obj, int value);
extern int of_oxm_ip_ecn_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_ip_ecn_masked_t *obj, int value);

extern int of_oxm_ip_proto_OF_VERSION_1_3_populate(
    of_oxm_ip_proto_t *obj, int value);
extern int of_oxm_ip_proto_OF_VERSION_1_3_check(
    of_oxm_ip_proto_t *obj, int value);
extern int of_oxm_ip_proto_OF_VERSION_1_3_populate_scalars(
    of_oxm_ip_proto_t *obj, int value);
extern int of_oxm_ip_proto_OF_VERSION_1_3_check_scalars(
    of_oxm_ip_proto_t *obj, int value);

extern int of_oxm_ip_proto_masked_OF_VERSION_1_3_populate(
    of_oxm_ip_proto_masked_t *obj, int value);
extern int of_oxm_ip_proto_masked_OF_VERSION_1_3_check(
    of_oxm_ip_proto_masked_t *obj, int value);
extern int of_oxm_ip_proto_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_ip_proto_masked_t *obj, int value);
extern int of_oxm_ip_proto_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_ip_proto_masked_t *obj, int value);

extern int of_oxm_ipv4_dst_OF_VERSION_1_3_populate(
    of_oxm_ipv4_dst_t *obj, int value);
extern int of_oxm_ipv4_dst_OF_VERSION_1_3_check(
    of_oxm_ipv4_dst_t *obj, int value);
extern int of_oxm_ipv4_dst_OF_VERSION_1_3_populate_scalars(
    of_oxm_ipv4_dst_t *obj, int value);
extern int of_oxm_ipv4_dst_OF_VERSION_1_3_check_scalars(
    of_oxm_ipv4_dst_t *obj, int value);

extern int of_oxm_ipv4_dst_masked_OF_VERSION_1_3_populate(
    of_oxm_ipv4_dst_masked_t *obj, int value);
extern int of_oxm_ipv4_dst_masked_OF_VERSION_1_3_check(
    of_oxm_ipv4_dst_masked_t *obj, int value);
extern int of_oxm_ipv4_dst_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_ipv4_dst_masked_t *obj, int value);
extern int of_oxm_ipv4_dst_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_ipv4_dst_masked_t *obj, int value);

extern int of_oxm_ipv4_src_OF_VERSION_1_3_populate(
    of_oxm_ipv4_src_t *obj, int value);
extern int of_oxm_ipv4_src_OF_VERSION_1_3_check(
    of_oxm_ipv4_src_t *obj, int value);
extern int of_oxm_ipv4_src_OF_VERSION_1_3_populate_scalars(
    of_oxm_ipv4_src_t *obj, int value);
extern int of_oxm_ipv4_src_OF_VERSION_1_3_check_scalars(
    of_oxm_ipv4_src_t *obj, int value);

extern int of_oxm_ipv4_src_masked_OF_VERSION_1_3_populate(
    of_oxm_ipv4_src_masked_t *obj, int value);
extern int of_oxm_ipv4_src_masked_OF_VERSION_1_3_check(
    of_oxm_ipv4_src_masked_t *obj, int value);
extern int of_oxm_ipv4_src_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_ipv4_src_masked_t *obj, int value);
extern int of_oxm_ipv4_src_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_ipv4_src_masked_t *obj, int value);

extern int of_oxm_ipv6_dst_OF_VERSION_1_3_populate(
    of_oxm_ipv6_dst_t *obj, int value);
extern int of_oxm_ipv6_dst_OF_VERSION_1_3_check(
    of_oxm_ipv6_dst_t *obj, int value);
extern int of_oxm_ipv6_dst_OF_VERSION_1_3_populate_scalars(
    of_oxm_ipv6_dst_t *obj, int value);
extern int of_oxm_ipv6_dst_OF_VERSION_1_3_check_scalars(
    of_oxm_ipv6_dst_t *obj, int value);

extern int of_oxm_ipv6_dst_masked_OF_VERSION_1_3_populate(
    of_oxm_ipv6_dst_masked_t *obj, int value);
extern int of_oxm_ipv6_dst_masked_OF_VERSION_1_3_check(
    of_oxm_ipv6_dst_masked_t *obj, int value);
extern int of_oxm_ipv6_dst_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_ipv6_dst_masked_t *obj, int value);
extern int of_oxm_ipv6_dst_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_ipv6_dst_masked_t *obj, int value);

extern int of_oxm_ipv6_exthdr_OF_VERSION_1_3_populate(
    of_oxm_ipv6_exthdr_t *obj, int value);
extern int of_oxm_ipv6_exthdr_OF_VERSION_1_3_check(
    of_oxm_ipv6_exthdr_t *obj, int value);
extern int of_oxm_ipv6_exthdr_OF_VERSION_1_3_populate_scalars(
    of_oxm_ipv6_exthdr_t *obj, int value);
extern int of_oxm_ipv6_exthdr_OF_VERSION_1_3_check_scalars(
    of_oxm_ipv6_exthdr_t *obj, int value);

extern int of_oxm_ipv6_exthdr_masked_OF_VERSION_1_3_populate(
    of_oxm_ipv6_exthdr_masked_t *obj, int value);
extern int of_oxm_ipv6_exthdr_masked_OF_VERSION_1_3_check(
    of_oxm_ipv6_exthdr_masked_t *obj, int value);
extern int of_oxm_ipv6_exthdr_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_ipv6_exthdr_masked_t *obj, int value);
extern int of_oxm_ipv6_exthdr_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_ipv6_exthdr_masked_t *obj, int value);

extern int of_oxm_ipv6_flabel_OF_VERSION_1_3_populate(
    of_oxm_ipv6_flabel_t *obj, int value);
extern int of_oxm_ipv6_flabel_OF_VERSION_1_3_check(
    of_oxm_ipv6_flabel_t *obj, int value);
extern int of_oxm_ipv6_flabel_OF_VERSION_1_3_populate_scalars(
    of_oxm_ipv6_flabel_t *obj, int value);
extern int of_oxm_ipv6_flabel_OF_VERSION_1_3_check_scalars(
    of_oxm_ipv6_flabel_t *obj, int value);

extern int of_oxm_ipv6_flabel_masked_OF_VERSION_1_3_populate(
    of_oxm_ipv6_flabel_masked_t *obj, int value);
extern int of_oxm_ipv6_flabel_masked_OF_VERSION_1_3_check(
    of_oxm_ipv6_flabel_masked_t *obj, int value);
extern int of_oxm_ipv6_flabel_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_ipv6_flabel_masked_t *obj, int value);
extern int of_oxm_ipv6_flabel_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_ipv6_flabel_masked_t *obj, int value);

extern int of_oxm_ipv6_nd_sll_OF_VERSION_1_3_populate(
    of_oxm_ipv6_nd_sll_t *obj, int value);
extern int of_oxm_ipv6_nd_sll_OF_VERSION_1_3_check(
    of_oxm_ipv6_nd_sll_t *obj, int value);
extern int of_oxm_ipv6_nd_sll_OF_VERSION_1_3_populate_scalars(
    of_oxm_ipv6_nd_sll_t *obj, int value);
extern int of_oxm_ipv6_nd_sll_OF_VERSION_1_3_check_scalars(
    of_oxm_ipv6_nd_sll_t *obj, int value);

extern int of_oxm_ipv6_nd_sll_masked_OF_VERSION_1_3_populate(
    of_oxm_ipv6_nd_sll_masked_t *obj, int value);
extern int of_oxm_ipv6_nd_sll_masked_OF_VERSION_1_3_check(
    of_oxm_ipv6_nd_sll_masked_t *obj, int value);
extern int of_oxm_ipv6_nd_sll_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_ipv6_nd_sll_masked_t *obj, int value);
extern int of_oxm_ipv6_nd_sll_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_ipv6_nd_sll_masked_t *obj, int value);

extern int of_oxm_ipv6_nd_target_OF_VERSION_1_3_populate(
    of_oxm_ipv6_nd_target_t *obj, int value);
extern int of_oxm_ipv6_nd_target_OF_VERSION_1_3_check(
    of_oxm_ipv6_nd_target_t *obj, int value);
extern int of_oxm_ipv6_nd_target_OF_VERSION_1_3_populate_scalars(
    of_oxm_ipv6_nd_target_t *obj, int value);
extern int of_oxm_ipv6_nd_target_OF_VERSION_1_3_check_scalars(
    of_oxm_ipv6_nd_target_t *obj, int value);

extern int of_oxm_ipv6_nd_target_masked_OF_VERSION_1_3_populate(
    of_oxm_ipv6_nd_target_masked_t *obj, int value);
extern int of_oxm_ipv6_nd_target_masked_OF_VERSION_1_3_check(
    of_oxm_ipv6_nd_target_masked_t *obj, int value);
extern int of_oxm_ipv6_nd_target_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_ipv6_nd_target_masked_t *obj, int value);
extern int of_oxm_ipv6_nd_target_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_ipv6_nd_target_masked_t *obj, int value);

extern int of_oxm_ipv6_nd_tll_OF_VERSION_1_3_populate(
    of_oxm_ipv6_nd_tll_t *obj, int value);
extern int of_oxm_ipv6_nd_tll_OF_VERSION_1_3_check(
    of_oxm_ipv6_nd_tll_t *obj, int value);
extern int of_oxm_ipv6_nd_tll_OF_VERSION_1_3_populate_scalars(
    of_oxm_ipv6_nd_tll_t *obj, int value);
extern int of_oxm_ipv6_nd_tll_OF_VERSION_1_3_check_scalars(
    of_oxm_ipv6_nd_tll_t *obj, int value);

extern int of_oxm_ipv6_nd_tll_masked_OF_VERSION_1_3_populate(
    of_oxm_ipv6_nd_tll_masked_t *obj, int value);
extern int of_oxm_ipv6_nd_tll_masked_OF_VERSION_1_3_check(
    of_oxm_ipv6_nd_tll_masked_t *obj, int value);
extern int of_oxm_ipv6_nd_tll_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_ipv6_nd_tll_masked_t *obj, int value);
extern int of_oxm_ipv6_nd_tll_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_ipv6_nd_tll_masked_t *obj, int value);

extern int of_oxm_ipv6_src_OF_VERSION_1_3_populate(
    of_oxm_ipv6_src_t *obj, int value);
extern int of_oxm_ipv6_src_OF_VERSION_1_3_check(
    of_oxm_ipv6_src_t *obj, int value);
extern int of_oxm_ipv6_src_OF_VERSION_1_3_populate_scalars(
    of_oxm_ipv6_src_t *obj, int value);
extern int of_oxm_ipv6_src_OF_VERSION_1_3_check_scalars(
    of_oxm_ipv6_src_t *obj, int value);

extern int of_oxm_ipv6_src_masked_OF_VERSION_1_3_populate(
    of_oxm_ipv6_src_masked_t *obj, int value);
extern int of_oxm_ipv6_src_masked_OF_VERSION_1_3_check(
    of_oxm_ipv6_src_masked_t *obj, int value);
extern int of_oxm_ipv6_src_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_ipv6_src_masked_t *obj, int value);
extern int of_oxm_ipv6_src_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_ipv6_src_masked_t *obj, int value);

extern int of_oxm_metadata_OF_VERSION_1_3_populate(
    of_oxm_metadata_t *obj, int value);
extern int of_oxm_metadata_OF_VERSION_1_3_check(
    of_oxm_metadata_t *obj, int value);
extern int of_oxm_metadata_OF_VERSION_1_3_populate_scalars(
    of_oxm_metadata_t *obj, int value);
extern int of_oxm_metadata_OF_VERSION_1_3_check_scalars(
    of_oxm_metadata_t *obj, int value);

extern int of_oxm_metadata_masked_OF_VERSION_1_3_populate(
    of_oxm_metadata_masked_t *obj, int value);
extern int of_oxm_metadata_masked_OF_VERSION_1_3_check(
    of_oxm_metadata_masked_t *obj, int value);
extern int of_oxm_metadata_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_metadata_masked_t *obj, int value);
extern int of_oxm_metadata_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_metadata_masked_t *obj, int value);

extern int of_oxm_mpls_bos_OF_VERSION_1_3_populate(
    of_oxm_mpls_bos_t *obj, int value);
extern int of_oxm_mpls_bos_OF_VERSION_1_3_check(
    of_oxm_mpls_bos_t *obj, int value);
extern int of_oxm_mpls_bos_OF_VERSION_1_3_populate_scalars(
    of_oxm_mpls_bos_t *obj, int value);
extern int of_oxm_mpls_bos_OF_VERSION_1_3_check_scalars(
    of_oxm_mpls_bos_t *obj, int value);

extern int of_oxm_mpls_bos_masked_OF_VERSION_1_3_populate(
    of_oxm_mpls_bos_masked_t *obj, int value);
extern int of_oxm_mpls_bos_masked_OF_VERSION_1_3_check(
    of_oxm_mpls_bos_masked_t *obj, int value);
extern int of_oxm_mpls_bos_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_mpls_bos_masked_t *obj, int value);
extern int of_oxm_mpls_bos_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_mpls_bos_masked_t *obj, int value);

extern int of_oxm_mpls_label_OF_VERSION_1_3_populate(
    of_oxm_mpls_label_t *obj, int value);
extern int of_oxm_mpls_label_OF_VERSION_1_3_check(
    of_oxm_mpls_label_t *obj, int value);
extern int of_oxm_mpls_label_OF_VERSION_1_3_populate_scalars(
    of_oxm_mpls_label_t *obj, int value);
extern int of_oxm_mpls_label_OF_VERSION_1_3_check_scalars(
    of_oxm_mpls_label_t *obj, int value);

extern int of_oxm_mpls_label_masked_OF_VERSION_1_3_populate(
    of_oxm_mpls_label_masked_t *obj, int value);
extern int of_oxm_mpls_label_masked_OF_VERSION_1_3_check(
    of_oxm_mpls_label_masked_t *obj, int value);
extern int of_oxm_mpls_label_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_mpls_label_masked_t *obj, int value);
extern int of_oxm_mpls_label_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_mpls_label_masked_t *obj, int value);

extern int of_oxm_mpls_tc_OF_VERSION_1_3_populate(
    of_oxm_mpls_tc_t *obj, int value);
extern int of_oxm_mpls_tc_OF_VERSION_1_3_check(
    of_oxm_mpls_tc_t *obj, int value);
extern int of_oxm_mpls_tc_OF_VERSION_1_3_populate_scalars(
    of_oxm_mpls_tc_t *obj, int value);
extern int of_oxm_mpls_tc_OF_VERSION_1_3_check_scalars(
    of_oxm_mpls_tc_t *obj, int value);

extern int of_oxm_mpls_tc_masked_OF_VERSION_1_3_populate(
    of_oxm_mpls_tc_masked_t *obj, int value);
extern int of_oxm_mpls_tc_masked_OF_VERSION_1_3_check(
    of_oxm_mpls_tc_masked_t *obj, int value);
extern int of_oxm_mpls_tc_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_mpls_tc_masked_t *obj, int value);
extern int of_oxm_mpls_tc_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_mpls_tc_masked_t *obj, int value);

extern int of_oxm_ovs_tcp_flags_OF_VERSION_1_3_populate(
    of_oxm_ovs_tcp_flags_t *obj, int value);
extern int of_oxm_ovs_tcp_flags_OF_VERSION_1_3_check(
    of_oxm_ovs_tcp_flags_t *obj, int value);
extern int of_oxm_ovs_tcp_flags_OF_VERSION_1_3_populate_scalars(
    of_oxm_ovs_tcp_flags_t *obj, int value);
extern int of_oxm_ovs_tcp_flags_OF_VERSION_1_3_check_scalars(
    of_oxm_ovs_tcp_flags_t *obj, int value);

extern int of_oxm_ovs_tcp_flags_masked_OF_VERSION_1_3_populate(
    of_oxm_ovs_tcp_flags_masked_t *obj, int value);
extern int of_oxm_ovs_tcp_flags_masked_OF_VERSION_1_3_check(
    of_oxm_ovs_tcp_flags_masked_t *obj, int value);
extern int of_oxm_ovs_tcp_flags_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_ovs_tcp_flags_masked_t *obj, int value);
extern int of_oxm_ovs_tcp_flags_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_ovs_tcp_flags_masked_t *obj, int value);

extern int of_oxm_sctp_dst_OF_VERSION_1_3_populate(
    of_oxm_sctp_dst_t *obj, int value);
extern int of_oxm_sctp_dst_OF_VERSION_1_3_check(
    of_oxm_sctp_dst_t *obj, int value);
extern int of_oxm_sctp_dst_OF_VERSION_1_3_populate_scalars(
    of_oxm_sctp_dst_t *obj, int value);
extern int of_oxm_sctp_dst_OF_VERSION_1_3_check_scalars(
    of_oxm_sctp_dst_t *obj, int value);

extern int of_oxm_sctp_dst_masked_OF_VERSION_1_3_populate(
    of_oxm_sctp_dst_masked_t *obj, int value);
extern int of_oxm_sctp_dst_masked_OF_VERSION_1_3_check(
    of_oxm_sctp_dst_masked_t *obj, int value);
extern int of_oxm_sctp_dst_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_sctp_dst_masked_t *obj, int value);
extern int of_oxm_sctp_dst_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_sctp_dst_masked_t *obj, int value);

extern int of_oxm_sctp_src_OF_VERSION_1_3_populate(
    of_oxm_sctp_src_t *obj, int value);
extern int of_oxm_sctp_src_OF_VERSION_1_3_check(
    of_oxm_sctp_src_t *obj, int value);
extern int of_oxm_sctp_src_OF_VERSION_1_3_populate_scalars(
    of_oxm_sctp_src_t *obj, int value);
extern int of_oxm_sctp_src_OF_VERSION_1_3_check_scalars(
    of_oxm_sctp_src_t *obj, int value);

extern int of_oxm_sctp_src_masked_OF_VERSION_1_3_populate(
    of_oxm_sctp_src_masked_t *obj, int value);
extern int of_oxm_sctp_src_masked_OF_VERSION_1_3_check(
    of_oxm_sctp_src_masked_t *obj, int value);
extern int of_oxm_sctp_src_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_sctp_src_masked_t *obj, int value);
extern int of_oxm_sctp_src_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_sctp_src_masked_t *obj, int value);

extern int of_oxm_tcp_dst_OF_VERSION_1_3_populate(
    of_oxm_tcp_dst_t *obj, int value);
extern int of_oxm_tcp_dst_OF_VERSION_1_3_check(
    of_oxm_tcp_dst_t *obj, int value);
extern int of_oxm_tcp_dst_OF_VERSION_1_3_populate_scalars(
    of_oxm_tcp_dst_t *obj, int value);
extern int of_oxm_tcp_dst_OF_VERSION_1_3_check_scalars(
    of_oxm_tcp_dst_t *obj, int value);

extern int of_oxm_tcp_dst_masked_OF_VERSION_1_3_populate(
    of_oxm_tcp_dst_masked_t *obj, int value);
extern int of_oxm_tcp_dst_masked_OF_VERSION_1_3_check(
    of_oxm_tcp_dst_masked_t *obj, int value);
extern int of_oxm_tcp_dst_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_tcp_dst_masked_t *obj, int value);
extern int of_oxm_tcp_dst_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_tcp_dst_masked_t *obj, int value);

extern int of_oxm_tcp_src_OF_VERSION_1_3_populate(
    of_oxm_tcp_src_t *obj, int value);
extern int of_oxm_tcp_src_OF_VERSION_1_3_check(
    of_oxm_tcp_src_t *obj, int value);
extern int of_oxm_tcp_src_OF_VERSION_1_3_populate_scalars(
    of_oxm_tcp_src_t *obj, int value);
extern int of_oxm_tcp_src_OF_VERSION_1_3_check_scalars(
    of_oxm_tcp_src_t *obj, int value);

extern int of_oxm_tcp_src_masked_OF_VERSION_1_3_populate(
    of_oxm_tcp_src_masked_t *obj, int value);
extern int of_oxm_tcp_src_masked_OF_VERSION_1_3_check(
    of_oxm_tcp_src_masked_t *obj, int value);
extern int of_oxm_tcp_src_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_tcp_src_masked_t *obj, int value);
extern int of_oxm_tcp_src_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_tcp_src_masked_t *obj, int value);

extern int of_oxm_tunnel_id_OF_VERSION_1_3_populate(
    of_oxm_tunnel_id_t *obj, int value);
extern int of_oxm_tunnel_id_OF_VERSION_1_3_check(
    of_oxm_tunnel_id_t *obj, int value);
extern int of_oxm_tunnel_id_OF_VERSION_1_3_populate_scalars(
    of_oxm_tunnel_id_t *obj, int value);
extern int of_oxm_tunnel_id_OF_VERSION_1_3_check_scalars(
    of_oxm_tunnel_id_t *obj, int value);

extern int of_oxm_tunnel_id_masked_OF_VERSION_1_3_populate(
    of_oxm_tunnel_id_masked_t *obj, int value);
extern int of_oxm_tunnel_id_masked_OF_VERSION_1_3_check(
    of_oxm_tunnel_id_masked_t *obj, int value);
extern int of_oxm_tunnel_id_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_tunnel_id_masked_t *obj, int value);
extern int of_oxm_tunnel_id_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_tunnel_id_masked_t *obj, int value);

extern int of_oxm_tunnel_ipv4_dst_OF_VERSION_1_3_populate(
    of_oxm_tunnel_ipv4_dst_t *obj, int value);
extern int of_oxm_tunnel_ipv4_dst_OF_VERSION_1_3_check(
    of_oxm_tunnel_ipv4_dst_t *obj, int value);
extern int of_oxm_tunnel_ipv4_dst_OF_VERSION_1_3_populate_scalars(
    of_oxm_tunnel_ipv4_dst_t *obj, int value);
extern int of_oxm_tunnel_ipv4_dst_OF_VERSION_1_3_check_scalars(
    of_oxm_tunnel_ipv4_dst_t *obj, int value);

extern int of_oxm_tunnel_ipv4_dst_masked_OF_VERSION_1_3_populate(
    of_oxm_tunnel_ipv4_dst_masked_t *obj, int value);
extern int of_oxm_tunnel_ipv4_dst_masked_OF_VERSION_1_3_check(
    of_oxm_tunnel_ipv4_dst_masked_t *obj, int value);
extern int of_oxm_tunnel_ipv4_dst_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_tunnel_ipv4_dst_masked_t *obj, int value);
extern int of_oxm_tunnel_ipv4_dst_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_tunnel_ipv4_dst_masked_t *obj, int value);

extern int of_oxm_tunnel_ipv4_src_OF_VERSION_1_3_populate(
    of_oxm_tunnel_ipv4_src_t *obj, int value);
extern int of_oxm_tunnel_ipv4_src_OF_VERSION_1_3_check(
    of_oxm_tunnel_ipv4_src_t *obj, int value);
extern int of_oxm_tunnel_ipv4_src_OF_VERSION_1_3_populate_scalars(
    of_oxm_tunnel_ipv4_src_t *obj, int value);
extern int of_oxm_tunnel_ipv4_src_OF_VERSION_1_3_check_scalars(
    of_oxm_tunnel_ipv4_src_t *obj, int value);

extern int of_oxm_tunnel_ipv4_src_masked_OF_VERSION_1_3_populate(
    of_oxm_tunnel_ipv4_src_masked_t *obj, int value);
extern int of_oxm_tunnel_ipv4_src_masked_OF_VERSION_1_3_check(
    of_oxm_tunnel_ipv4_src_masked_t *obj, int value);
extern int of_oxm_tunnel_ipv4_src_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_tunnel_ipv4_src_masked_t *obj, int value);
extern int of_oxm_tunnel_ipv4_src_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_tunnel_ipv4_src_masked_t *obj, int value);

extern int of_oxm_udp_dst_OF_VERSION_1_3_populate(
    of_oxm_udp_dst_t *obj, int value);
extern int of_oxm_udp_dst_OF_VERSION_1_3_check(
    of_oxm_udp_dst_t *obj, int value);
extern int of_oxm_udp_dst_OF_VERSION_1_3_populate_scalars(
    of_oxm_udp_dst_t *obj, int value);
extern int of_oxm_udp_dst_OF_VERSION_1_3_check_scalars(
    of_oxm_udp_dst_t *obj, int value);

extern int of_oxm_udp_dst_masked_OF_VERSION_1_3_populate(
    of_oxm_udp_dst_masked_t *obj, int value);
extern int of_oxm_udp_dst_masked_OF_VERSION_1_3_check(
    of_oxm_udp_dst_masked_t *obj, int value);
extern int of_oxm_udp_dst_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_udp_dst_masked_t *obj, int value);
extern int of_oxm_udp_dst_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_udp_dst_masked_t *obj, int value);

extern int of_oxm_udp_src_OF_VERSION_1_3_populate(
    of_oxm_udp_src_t *obj, int value);
extern int of_oxm_udp_src_OF_VERSION_1_3_check(
    of_oxm_udp_src_t *obj, int value);
extern int of_oxm_udp_src_OF_VERSION_1_3_populate_scalars(
    of_oxm_udp_src_t *obj, int value);
extern int of_oxm_udp_src_OF_VERSION_1_3_check_scalars(
    of_oxm_udp_src_t *obj, int value);

extern int of_oxm_udp_src_masked_OF_VERSION_1_3_populate(
    of_oxm_udp_src_masked_t *obj, int value);
extern int of_oxm_udp_src_masked_OF_VERSION_1_3_check(
    of_oxm_udp_src_masked_t *obj, int value);
extern int of_oxm_udp_src_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_udp_src_masked_t *obj, int value);
extern int of_oxm_udp_src_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_udp_src_masked_t *obj, int value);

extern int of_oxm_vlan_pcp_OF_VERSION_1_3_populate(
    of_oxm_vlan_pcp_t *obj, int value);
extern int of_oxm_vlan_pcp_OF_VERSION_1_3_check(
    of_oxm_vlan_pcp_t *obj, int value);
extern int of_oxm_vlan_pcp_OF_VERSION_1_3_populate_scalars(
    of_oxm_vlan_pcp_t *obj, int value);
extern int of_oxm_vlan_pcp_OF_VERSION_1_3_check_scalars(
    of_oxm_vlan_pcp_t *obj, int value);

extern int of_oxm_vlan_pcp_masked_OF_VERSION_1_3_populate(
    of_oxm_vlan_pcp_masked_t *obj, int value);
extern int of_oxm_vlan_pcp_masked_OF_VERSION_1_3_check(
    of_oxm_vlan_pcp_masked_t *obj, int value);
extern int of_oxm_vlan_pcp_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_vlan_pcp_masked_t *obj, int value);
extern int of_oxm_vlan_pcp_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_vlan_pcp_masked_t *obj, int value);

extern int of_oxm_vlan_vid_OF_VERSION_1_3_populate(
    of_oxm_vlan_vid_t *obj, int value);
extern int of_oxm_vlan_vid_OF_VERSION_1_3_check(
    of_oxm_vlan_vid_t *obj, int value);
extern int of_oxm_vlan_vid_OF_VERSION_1_3_populate_scalars(
    of_oxm_vlan_vid_t *obj, int value);
extern int of_oxm_vlan_vid_OF_VERSION_1_3_check_scalars(
    of_oxm_vlan_vid_t *obj, int value);

extern int of_oxm_vlan_vid_masked_OF_VERSION_1_3_populate(
    of_oxm_vlan_vid_masked_t *obj, int value);
extern int of_oxm_vlan_vid_masked_OF_VERSION_1_3_check(
    of_oxm_vlan_vid_masked_t *obj, int value);
extern int of_oxm_vlan_vid_masked_OF_VERSION_1_3_populate_scalars(
    of_oxm_vlan_vid_masked_t *obj, int value);
extern int of_oxm_vlan_vid_masked_OF_VERSION_1_3_check_scalars(
    of_oxm_vlan_vid_masked_t *obj, int value);

extern int of_packet_queue_OF_VERSION_1_3_populate(
    of_packet_queue_t *obj, int value);
extern int of_packet_queue_OF_VERSION_1_3_check(
    of_packet_queue_t *obj, int value);
extern int of_packet_queue_OF_VERSION_1_3_populate_scalars(
    of_packet_queue_t *obj, int value);
extern int of_packet_queue_OF_VERSION_1_3_check_scalars(
    of_packet_queue_t *obj, int value);

extern int of_port_desc_OF_VERSION_1_3_populate(
    of_port_desc_t *obj, int value);
extern int of_port_desc_OF_VERSION_1_3_check(
    of_port_desc_t *obj, int value);
extern int of_port_desc_OF_VERSION_1_3_populate_scalars(
    of_port_desc_t *obj, int value);
extern int of_port_desc_OF_VERSION_1_3_check_scalars(
    of_port_desc_t *obj, int value);

extern int of_port_stats_entry_OF_VERSION_1_3_populate(
    of_port_stats_entry_t *obj, int value);
extern int of_port_stats_entry_OF_VERSION_1_3_check(
    of_port_stats_entry_t *obj, int value);
extern int of_port_stats_entry_OF_VERSION_1_3_populate_scalars(
    of_port_stats_entry_t *obj, int value);
extern int of_port_stats_entry_OF_VERSION_1_3_check_scalars(
    of_port_stats_entry_t *obj, int value);

extern int of_queue_prop_max_rate_OF_VERSION_1_3_populate(
    of_queue_prop_max_rate_t *obj, int value);
extern int of_queue_prop_max_rate_OF_VERSION_1_3_check(
    of_queue_prop_max_rate_t *obj, int value);
extern int of_queue_prop_max_rate_OF_VERSION_1_3_populate_scalars(
    of_queue_prop_max_rate_t *obj, int value);
extern int of_queue_prop_max_rate_OF_VERSION_1_3_check_scalars(
    of_queue_prop_max_rate_t *obj, int value);

extern int of_queue_prop_min_rate_OF_VERSION_1_3_populate(
    of_queue_prop_min_rate_t *obj, int value);
extern int of_queue_prop_min_rate_OF_VERSION_1_3_check(
    of_queue_prop_min_rate_t *obj, int value);
extern int of_queue_prop_min_rate_OF_VERSION_1_3_populate_scalars(
    of_queue_prop_min_rate_t *obj, int value);
extern int of_queue_prop_min_rate_OF_VERSION_1_3_check_scalars(
    of_queue_prop_min_rate_t *obj, int value);

extern int of_queue_stats_entry_OF_VERSION_1_3_populate(
    of_queue_stats_entry_t *obj, int value);
extern int of_queue_stats_entry_OF_VERSION_1_3_check(
    of_queue_stats_entry_t *obj, int value);
extern int of_queue_stats_entry_OF_VERSION_1_3_populate_scalars(
    of_queue_stats_entry_t *obj, int value);
extern int of_queue_stats_entry_OF_VERSION_1_3_check_scalars(
    of_queue_stats_entry_t *obj, int value);

extern int of_table_feature_prop_apply_actions_OF_VERSION_1_3_populate(
    of_table_feature_prop_apply_actions_t *obj, int value);
extern int of_table_feature_prop_apply_actions_OF_VERSION_1_3_check(
    of_table_feature_prop_apply_actions_t *obj, int value);
extern int of_table_feature_prop_apply_actions_OF_VERSION_1_3_populate_scalars(
    of_table_feature_prop_apply_actions_t *obj, int value);
extern int of_table_feature_prop_apply_actions_OF_VERSION_1_3_check_scalars(
    of_table_feature_prop_apply_actions_t *obj, int value);

extern int of_table_feature_prop_apply_actions_miss_OF_VERSION_1_3_populate(
    of_table_feature_prop_apply_actions_miss_t *obj, int value);
extern int of_table_feature_prop_apply_actions_miss_OF_VERSION_1_3_check(
    of_table_feature_prop_apply_actions_miss_t *obj, int value);
extern int of_table_feature_prop_apply_actions_miss_OF_VERSION_1_3_populate_scalars(
    of_table_feature_prop_apply_actions_miss_t *obj, int value);
extern int of_table_feature_prop_apply_actions_miss_OF_VERSION_1_3_check_scalars(
    of_table_feature_prop_apply_actions_miss_t *obj, int value);

extern int of_table_feature_prop_apply_setfield_OF_VERSION_1_3_populate(
    of_table_feature_prop_apply_setfield_t *obj, int value);
extern int of_table_feature_prop_apply_setfield_OF_VERSION_1_3_check(
    of_table_feature_prop_apply_setfield_t *obj, int value);
extern int of_table_feature_prop_apply_setfield_OF_VERSION_1_3_populate_scalars(
    of_table_feature_prop_apply_setfield_t *obj, int value);
extern int of_table_feature_prop_apply_setfield_OF_VERSION_1_3_check_scalars(
    of_table_feature_prop_apply_setfield_t *obj, int value);

extern int of_table_feature_prop_apply_setfield_miss_OF_VERSION_1_3_populate(
    of_table_feature_prop_apply_setfield_miss_t *obj, int value);
extern int of_table_feature_prop_apply_setfield_miss_OF_VERSION_1_3_check(
    of_table_feature_prop_apply_setfield_miss_t *obj, int value);
extern int of_table_feature_prop_apply_setfield_miss_OF_VERSION_1_3_populate_scalars(
    of_table_feature_prop_apply_setfield_miss_t *obj, int value);
extern int of_table_feature_prop_apply_setfield_miss_OF_VERSION_1_3_check_scalars(
    of_table_feature_prop_apply_setfield_miss_t *obj, int value);

extern int of_table_feature_prop_instructions_OF_VERSION_1_3_populate(
    of_table_feature_prop_instructions_t *obj, int value);
extern int of_table_feature_prop_instructions_OF_VERSION_1_3_check(
    of_table_feature_prop_instructions_t *obj, int value);
extern int of_table_feature_prop_instructions_OF_VERSION_1_3_populate_scalars(
    of_table_feature_prop_instructions_t *obj, int value);
extern int of_table_feature_prop_instructions_OF_VERSION_1_3_check_scalars(
    of_table_feature_prop_instructions_t *obj, int value);

extern int of_table_feature_prop_instructions_miss_OF_VERSION_1_3_populate(
    of_table_feature_prop_instructions_miss_t *obj, int value);
extern int of_table_feature_prop_instructions_miss_OF_VERSION_1_3_check(
    of_table_feature_prop_instructions_miss_t *obj, int value);
extern int of_table_feature_prop_instructions_miss_OF_VERSION_1_3_populate_scalars(
    of_table_feature_prop_instructions_miss_t *obj, int value);
extern int of_table_feature_prop_instructions_miss_OF_VERSION_1_3_check_scalars(
    of_table_feature_prop_instructions_miss_t *obj, int value);

extern int of_table_feature_prop_match_OF_VERSION_1_3_populate(
    of_table_feature_prop_match_t *obj, int value);
extern int of_table_feature_prop_match_OF_VERSION_1_3_check(
    of_table_feature_prop_match_t *obj, int value);
extern int of_table_feature_prop_match_OF_VERSION_1_3_populate_scalars(
    of_table_feature_prop_match_t *obj, int value);
extern int of_table_feature_prop_match_OF_VERSION_1_3_check_scalars(
    of_table_feature_prop_match_t *obj, int value);

extern int of_table_feature_prop_next_tables_OF_VERSION_1_3_populate(
    of_table_feature_prop_next_tables_t *obj, int value);
extern int of_table_feature_prop_next_tables_OF_VERSION_1_3_check(
    of_table_feature_prop_next_tables_t *obj, int value);
extern int of_table_feature_prop_next_tables_OF_VERSION_1_3_populate_scalars(
    of_table_feature_prop_next_tables_t *obj, int value);
extern int of_table_feature_prop_next_tables_OF_VERSION_1_3_check_scalars(
    of_table_feature_prop_next_tables_t *obj, int value);

extern int of_table_feature_prop_next_tables_miss_OF_VERSION_1_3_populate(
    of_table_feature_prop_next_tables_miss_t *obj, int value);
extern int of_table_feature_prop_next_tables_miss_OF_VERSION_1_3_check(
    of_table_feature_prop_next_tables_miss_t *obj, int value);
extern int of_table_feature_prop_next_tables_miss_OF_VERSION_1_3_populate_scalars(
    of_table_feature_prop_next_tables_miss_t *obj, int value);
extern int of_table_feature_prop_next_tables_miss_OF_VERSION_1_3_check_scalars(
    of_table_feature_prop_next_tables_miss_t *obj, int value);

extern int of_table_feature_prop_wildcards_OF_VERSION_1_3_populate(
    of_table_feature_prop_wildcards_t *obj, int value);
extern int of_table_feature_prop_wildcards_OF_VERSION_1_3_check(
    of_table_feature_prop_wildcards_t *obj, int value);
extern int of_table_feature_prop_wildcards_OF_VERSION_1_3_populate_scalars(
    of_table_feature_prop_wildcards_t *obj, int value);
extern int of_table_feature_prop_wildcards_OF_VERSION_1_3_check_scalars(
    of_table_feature_prop_wildcards_t *obj, int value);

extern int of_table_feature_prop_write_actions_OF_VERSION_1_3_populate(
    of_table_feature_prop_write_actions_t *obj, int value);
extern int of_table_feature_prop_write_actions_OF_VERSION_1_3_check(
    of_table_feature_prop_write_actions_t *obj, int value);
extern int of_table_feature_prop_write_actions_OF_VERSION_1_3_populate_scalars(
    of_table_feature_prop_write_actions_t *obj, int value);
extern int of_table_feature_prop_write_actions_OF_VERSION_1_3_check_scalars(
    of_table_feature_prop_write_actions_t *obj, int value);

extern int of_table_feature_prop_write_actions_miss_OF_VERSION_1_3_populate(
    of_table_feature_prop_write_actions_miss_t *obj, int value);
extern int of_table_feature_prop_write_actions_miss_OF_VERSION_1_3_check(
    of_table_feature_prop_write_actions_miss_t *obj, int value);
extern int of_table_feature_prop_write_actions_miss_OF_VERSION_1_3_populate_scalars(
    of_table_feature_prop_write_actions_miss_t *obj, int value);
extern int of_table_feature_prop_write_actions_miss_OF_VERSION_1_3_check_scalars(
    of_table_feature_prop_write_actions_miss_t *obj, int value);

extern int of_table_feature_prop_write_setfield_OF_VERSION_1_3_populate(
    of_table_feature_prop_write_setfield_t *obj, int value);
extern int of_table_feature_prop_write_setfield_OF_VERSION_1_3_check(
    of_table_feature_prop_write_setfield_t *obj, int value);
extern int of_table_feature_prop_write_setfield_OF_VERSION_1_3_populate_scalars(
    of_table_feature_prop_write_setfield_t *obj, int value);
extern int of_table_feature_prop_write_setfield_OF_VERSION_1_3_check_scalars(
    of_table_feature_prop_write_setfield_t *obj, int value);

extern int of_table_feature_prop_write_setfield_miss_OF_VERSION_1_3_populate(
    of_table_feature_prop_write_setfield_miss_t *obj, int value);
extern int of_table_feature_prop_write_setfield_miss_OF_VERSION_1_3_check(
    of_table_feature_prop_write_setfield_miss_t *obj, int value);
extern int of_table_feature_prop_write_setfield_miss_OF_VERSION_1_3_populate_scalars(
    of_table_feature_prop_write_setfield_miss_t *obj, int value);
extern int of_table_feature_prop_write_setfield_miss_OF_VERSION_1_3_check_scalars(
    of_table_feature_prop_write_setfield_miss_t *obj, int value);

extern int of_table_features_OF_VERSION_1_3_populate(
    of_table_features_t *obj, int value);
extern int of_table_features_OF_VERSION_1_3_check(
    of_table_features_t *obj, int value);
extern int of_table_features_OF_VERSION_1_3_populate_scalars(
    of_table_features_t *obj, int value);
extern int of_table_features_OF_VERSION_1_3_check_scalars(
    of_table_features_t *obj, int value);

extern int of_table_stats_entry_OF_VERSION_1_3_populate(
    of_table_stats_entry_t *obj, int value);
extern int of_table_stats_entry_OF_VERSION_1_3_check(
    of_table_stats_entry_t *obj, int value);
extern int of_table_stats_entry_OF_VERSION_1_3_populate_scalars(
    of_table_stats_entry_t *obj, int value);
extern int of_table_stats_entry_OF_VERSION_1_3_check_scalars(
    of_table_stats_entry_t *obj, int value);

extern int of_uint32_OF_VERSION_1_3_populate(
    of_uint32_t *obj, int value);
extern int of_uint32_OF_VERSION_1_3_check(
    of_uint32_t *obj, int value);
extern int of_uint32_OF_VERSION_1_3_populate_scalars(
    of_uint32_t *obj, int value);
extern int of_uint32_OF_VERSION_1_3_check_scalars(
    of_uint32_t *obj, int value);

extern int of_uint64_OF_VERSION_1_3_populate(
    of_uint64_t *obj, int value);
extern int of_uint64_OF_VERSION_1_3_check(
    of_uint64_t *obj, int value);
extern int of_uint64_OF_VERSION_1_3_populate_scalars(
    of_uint64_t *obj, int value);
extern int of_uint64_OF_VERSION_1_3_check_scalars(
    of_uint64_t *obj, int value);

extern int of_uint8_OF_VERSION_1_3_populate(
    of_uint8_t *obj, int value);
extern int of_uint8_OF_VERSION_1_3_check(
    of_uint8_t *obj, int value);
extern int of_uint8_OF_VERSION_1_3_populate_scalars(
    of_uint8_t *obj, int value);
extern int of_uint8_OF_VERSION_1_3_check_scalars(
    of_uint8_t *obj, int value);

extern int of_list_action_OF_VERSION_1_3_populate(
    of_list_action_t *obj, int value);
extern int of_list_action_OF_VERSION_1_3_check(
    of_list_action_t *obj, int value);
extern int of_list_action_OF_VERSION_1_3_populate_scalars(
    of_list_action_t *obj, int value);
extern int of_list_action_OF_VERSION_1_3_check_scalars(
    of_list_action_t *obj, int value);

extern int of_list_action_id_OF_VERSION_1_3_populate(
    of_list_action_id_t *obj, int value);
extern int of_list_action_id_OF_VERSION_1_3_check(
    of_list_action_id_t *obj, int value);
extern int of_list_action_id_OF_VERSION_1_3_populate_scalars(
    of_list_action_id_t *obj, int value);
extern int of_list_action_id_OF_VERSION_1_3_check_scalars(
    of_list_action_id_t *obj, int value);

extern int of_list_bsn_controller_connection_OF_VERSION_1_3_populate(
    of_list_bsn_controller_connection_t *obj, int value);
extern int of_list_bsn_controller_connection_OF_VERSION_1_3_check(
    of_list_bsn_controller_connection_t *obj, int value);
extern int of_list_bsn_controller_connection_OF_VERSION_1_3_populate_scalars(
    of_list_bsn_controller_connection_t *obj, int value);
extern int of_list_bsn_controller_connection_OF_VERSION_1_3_check_scalars(
    of_list_bsn_controller_connection_t *obj, int value);

extern int of_list_bsn_debug_counter_desc_stats_entry_OF_VERSION_1_3_populate(
    of_list_bsn_debug_counter_desc_stats_entry_t *obj, int value);
extern int of_list_bsn_debug_counter_desc_stats_entry_OF_VERSION_1_3_check(
    of_list_bsn_debug_counter_desc_stats_entry_t *obj, int value);
extern int of_list_bsn_debug_counter_desc_stats_entry_OF_VERSION_1_3_populate_scalars(
    of_list_bsn_debug_counter_desc_stats_entry_t *obj, int value);
extern int of_list_bsn_debug_counter_desc_stats_entry_OF_VERSION_1_3_check_scalars(
    of_list_bsn_debug_counter_desc_stats_entry_t *obj, int value);

extern int of_list_bsn_debug_counter_stats_entry_OF_VERSION_1_3_populate(
    of_list_bsn_debug_counter_stats_entry_t *obj, int value);
extern int of_list_bsn_debug_counter_stats_entry_OF_VERSION_1_3_check(
    of_list_bsn_debug_counter_stats_entry_t *obj, int value);
extern int of_list_bsn_debug_counter_stats_entry_OF_VERSION_1_3_populate_scalars(
    of_list_bsn_debug_counter_stats_entry_t *obj, int value);
extern int of_list_bsn_debug_counter_stats_entry_OF_VERSION_1_3_check_scalars(
    of_list_bsn_debug_counter_stats_entry_t *obj, int value);

extern int of_list_bsn_flow_checksum_bucket_stats_entry_OF_VERSION_1_3_populate(
    of_list_bsn_flow_checksum_bucket_stats_entry_t *obj, int value);
extern int of_list_bsn_flow_checksum_bucket_stats_entry_OF_VERSION_1_3_check(
    of_list_bsn_flow_checksum_bucket_stats_entry_t *obj, int value);
extern int of_list_bsn_flow_checksum_bucket_stats_entry_OF_VERSION_1_3_populate_scalars(
    of_list_bsn_flow_checksum_bucket_stats_entry_t *obj, int value);
extern int of_list_bsn_flow_checksum_bucket_stats_entry_OF_VERSION_1_3_check_scalars(
    of_list_bsn_flow_checksum_bucket_stats_entry_t *obj, int value);

extern int of_list_bsn_generic_stats_entry_OF_VERSION_1_3_populate(
    of_list_bsn_generic_stats_entry_t *obj, int value);
extern int of_list_bsn_generic_stats_entry_OF_VERSION_1_3_check(
    of_list_bsn_generic_stats_entry_t *obj, int value);
extern int of_list_bsn_generic_stats_entry_OF_VERSION_1_3_populate_scalars(
    of_list_bsn_generic_stats_entry_t *obj, int value);
extern int of_list_bsn_generic_stats_entry_OF_VERSION_1_3_check_scalars(
    of_list_bsn_generic_stats_entry_t *obj, int value);

extern int of_list_bsn_gentable_bucket_stats_entry_OF_VERSION_1_3_populate(
    of_list_bsn_gentable_bucket_stats_entry_t *obj, int value);
extern int of_list_bsn_gentable_bucket_stats_entry_OF_VERSION_1_3_check(
    of_list_bsn_gentable_bucket_stats_entry_t *obj, int value);
extern int of_list_bsn_gentable_bucket_stats_entry_OF_VERSION_1_3_populate_scalars(
    of_list_bsn_gentable_bucket_stats_entry_t *obj, int value);
extern int of_list_bsn_gentable_bucket_stats_entry_OF_VERSION_1_3_check_scalars(
    of_list_bsn_gentable_bucket_stats_entry_t *obj, int value);

extern int of_list_bsn_gentable_desc_stats_entry_OF_VERSION_1_3_populate(
    of_list_bsn_gentable_desc_stats_entry_t *obj, int value);
extern int of_list_bsn_gentable_desc_stats_entry_OF_VERSION_1_3_check(
    of_list_bsn_gentable_desc_stats_entry_t *obj, int value);
extern int of_list_bsn_gentable_desc_stats_entry_OF_VERSION_1_3_populate_scalars(
    of_list_bsn_gentable_desc_stats_entry_t *obj, int value);
extern int of_list_bsn_gentable_desc_stats_entry_OF_VERSION_1_3_check_scalars(
    of_list_bsn_gentable_desc_stats_entry_t *obj, int value);

extern int of_list_bsn_gentable_entry_desc_stats_entry_OF_VERSION_1_3_populate(
    of_list_bsn_gentable_entry_desc_stats_entry_t *obj, int value);
extern int of_list_bsn_gentable_entry_desc_stats_entry_OF_VERSION_1_3_check(
    of_list_bsn_gentable_entry_desc_stats_entry_t *obj, int value);
extern int of_list_bsn_gentable_entry_desc_stats_entry_OF_VERSION_1_3_populate_scalars(
    of_list_bsn_gentable_entry_desc_stats_entry_t *obj, int value);
extern int of_list_bsn_gentable_entry_desc_stats_entry_OF_VERSION_1_3_check_scalars(
    of_list_bsn_gentable_entry_desc_stats_entry_t *obj, int value);

extern int of_list_bsn_gentable_entry_stats_entry_OF_VERSION_1_3_populate(
    of_list_bsn_gentable_entry_stats_entry_t *obj, int value);
extern int of_list_bsn_gentable_entry_stats_entry_OF_VERSION_1_3_check(
    of_list_bsn_gentable_entry_stats_entry_t *obj, int value);
extern int of_list_bsn_gentable_entry_stats_entry_OF_VERSION_1_3_populate_scalars(
    of_list_bsn_gentable_entry_stats_entry_t *obj, int value);
extern int of_list_bsn_gentable_entry_stats_entry_OF_VERSION_1_3_check_scalars(
    of_list_bsn_gentable_entry_stats_entry_t *obj, int value);

extern int of_list_bsn_gentable_stats_entry_OF_VERSION_1_3_populate(
    of_list_bsn_gentable_stats_entry_t *obj, int value);
extern int of_list_bsn_gentable_stats_entry_OF_VERSION_1_3_check(
    of_list_bsn_gentable_stats_entry_t *obj, int value);
extern int of_list_bsn_gentable_stats_entry_OF_VERSION_1_3_populate_scalars(
    of_list_bsn_gentable_stats_entry_t *obj, int value);
extern int of_list_bsn_gentable_stats_entry_OF_VERSION_1_3_check_scalars(
    of_list_bsn_gentable_stats_entry_t *obj, int value);

extern int of_list_bsn_interface_OF_VERSION_1_3_populate(
    of_list_bsn_interface_t *obj, int value);
extern int of_list_bsn_interface_OF_VERSION_1_3_check(
    of_list_bsn_interface_t *obj, int value);
extern int of_list_bsn_interface_OF_VERSION_1_3_populate_scalars(
    of_list_bsn_interface_t *obj, int value);
extern int of_list_bsn_interface_OF_VERSION_1_3_check_scalars(
    of_list_bsn_interface_t *obj, int value);

extern int of_list_bsn_lacp_stats_entry_OF_VERSION_1_3_populate(
    of_list_bsn_lacp_stats_entry_t *obj, int value);
extern int of_list_bsn_lacp_stats_entry_OF_VERSION_1_3_check(
    of_list_bsn_lacp_stats_entry_t *obj, int value);
extern int of_list_bsn_lacp_stats_entry_OF_VERSION_1_3_populate_scalars(
    of_list_bsn_lacp_stats_entry_t *obj, int value);
extern int of_list_bsn_lacp_stats_entry_OF_VERSION_1_3_check_scalars(
    of_list_bsn_lacp_stats_entry_t *obj, int value);

extern int of_list_bsn_port_counter_stats_entry_OF_VERSION_1_3_populate(
    of_list_bsn_port_counter_stats_entry_t *obj, int value);
extern int of_list_bsn_port_counter_stats_entry_OF_VERSION_1_3_check(
    of_list_bsn_port_counter_stats_entry_t *obj, int value);
extern int of_list_bsn_port_counter_stats_entry_OF_VERSION_1_3_populate_scalars(
    of_list_bsn_port_counter_stats_entry_t *obj, int value);
extern int of_list_bsn_port_counter_stats_entry_OF_VERSION_1_3_check_scalars(
    of_list_bsn_port_counter_stats_entry_t *obj, int value);

extern int of_list_bsn_switch_pipeline_stats_entry_OF_VERSION_1_3_populate(
    of_list_bsn_switch_pipeline_stats_entry_t *obj, int value);
extern int of_list_bsn_switch_pipeline_stats_entry_OF_VERSION_1_3_check(
    of_list_bsn_switch_pipeline_stats_entry_t *obj, int value);
extern int of_list_bsn_switch_pipeline_stats_entry_OF_VERSION_1_3_populate_scalars(
    of_list_bsn_switch_pipeline_stats_entry_t *obj, int value);
extern int of_list_bsn_switch_pipeline_stats_entry_OF_VERSION_1_3_check_scalars(
    of_list_bsn_switch_pipeline_stats_entry_t *obj, int value);

extern int of_list_bsn_table_checksum_stats_entry_OF_VERSION_1_3_populate(
    of_list_bsn_table_checksum_stats_entry_t *obj, int value);
extern int of_list_bsn_table_checksum_stats_entry_OF_VERSION_1_3_check(
    of_list_bsn_table_checksum_stats_entry_t *obj, int value);
extern int of_list_bsn_table_checksum_stats_entry_OF_VERSION_1_3_populate_scalars(
    of_list_bsn_table_checksum_stats_entry_t *obj, int value);
extern int of_list_bsn_table_checksum_stats_entry_OF_VERSION_1_3_check_scalars(
    of_list_bsn_table_checksum_stats_entry_t *obj, int value);

extern int of_list_bsn_tlv_OF_VERSION_1_3_populate(
    of_list_bsn_tlv_t *obj, int value);
extern int of_list_bsn_tlv_OF_VERSION_1_3_check(
    of_list_bsn_tlv_t *obj, int value);
extern int of_list_bsn_tlv_OF_VERSION_1_3_populate_scalars(
    of_list_bsn_tlv_t *obj, int value);
extern int of_list_bsn_tlv_OF_VERSION_1_3_check_scalars(
    of_list_bsn_tlv_t *obj, int value);

extern int of_list_bsn_vlan_counter_stats_entry_OF_VERSION_1_3_populate(
    of_list_bsn_vlan_counter_stats_entry_t *obj, int value);
extern int of_list_bsn_vlan_counter_stats_entry_OF_VERSION_1_3_check(
    of_list_bsn_vlan_counter_stats_entry_t *obj, int value);
extern int of_list_bsn_vlan_counter_stats_entry_OF_VERSION_1_3_populate_scalars(
    of_list_bsn_vlan_counter_stats_entry_t *obj, int value);
extern int of_list_bsn_vlan_counter_stats_entry_OF_VERSION_1_3_check_scalars(
    of_list_bsn_vlan_counter_stats_entry_t *obj, int value);

extern int of_list_bsn_vlan_mac_OF_VERSION_1_3_populate(
    of_list_bsn_vlan_mac_t *obj, int value);
extern int of_list_bsn_vlan_mac_OF_VERSION_1_3_check(
    of_list_bsn_vlan_mac_t *obj, int value);
extern int of_list_bsn_vlan_mac_OF_VERSION_1_3_populate_scalars(
    of_list_bsn_vlan_mac_t *obj, int value);
extern int of_list_bsn_vlan_mac_OF_VERSION_1_3_check_scalars(
    of_list_bsn_vlan_mac_t *obj, int value);

extern int of_list_bsn_vrf_counter_stats_entry_OF_VERSION_1_3_populate(
    of_list_bsn_vrf_counter_stats_entry_t *obj, int value);
extern int of_list_bsn_vrf_counter_stats_entry_OF_VERSION_1_3_check(
    of_list_bsn_vrf_counter_stats_entry_t *obj, int value);
extern int of_list_bsn_vrf_counter_stats_entry_OF_VERSION_1_3_populate_scalars(
    of_list_bsn_vrf_counter_stats_entry_t *obj, int value);
extern int of_list_bsn_vrf_counter_stats_entry_OF_VERSION_1_3_check_scalars(
    of_list_bsn_vrf_counter_stats_entry_t *obj, int value);

extern int of_list_bucket_OF_VERSION_1_3_populate(
    of_list_bucket_t *obj, int value);
extern int of_list_bucket_OF_VERSION_1_3_check(
    of_list_bucket_t *obj, int value);
extern int of_list_bucket_OF_VERSION_1_3_populate_scalars(
    of_list_bucket_t *obj, int value);
extern int of_list_bucket_OF_VERSION_1_3_check_scalars(
    of_list_bucket_t *obj, int value);

extern int of_list_bucket_counter_OF_VERSION_1_3_populate(
    of_list_bucket_counter_t *obj, int value);
extern int of_list_bucket_counter_OF_VERSION_1_3_check(
    of_list_bucket_counter_t *obj, int value);
extern int of_list_bucket_counter_OF_VERSION_1_3_populate_scalars(
    of_list_bucket_counter_t *obj, int value);
extern int of_list_bucket_counter_OF_VERSION_1_3_check_scalars(
    of_list_bucket_counter_t *obj, int value);

extern int of_list_flow_stats_entry_OF_VERSION_1_3_populate(
    of_list_flow_stats_entry_t *obj, int value);
extern int of_list_flow_stats_entry_OF_VERSION_1_3_check(
    of_list_flow_stats_entry_t *obj, int value);
extern int of_list_flow_stats_entry_OF_VERSION_1_3_populate_scalars(
    of_list_flow_stats_entry_t *obj, int value);
extern int of_list_flow_stats_entry_OF_VERSION_1_3_check_scalars(
    of_list_flow_stats_entry_t *obj, int value);

extern int of_list_group_desc_stats_entry_OF_VERSION_1_3_populate(
    of_list_group_desc_stats_entry_t *obj, int value);
extern int of_list_group_desc_stats_entry_OF_VERSION_1_3_check(
    of_list_group_desc_stats_entry_t *obj, int value);
extern int of_list_group_desc_stats_entry_OF_VERSION_1_3_populate_scalars(
    of_list_group_desc_stats_entry_t *obj, int value);
extern int of_list_group_desc_stats_entry_OF_VERSION_1_3_check_scalars(
    of_list_group_desc_stats_entry_t *obj, int value);

extern int of_list_group_stats_entry_OF_VERSION_1_3_populate(
    of_list_group_stats_entry_t *obj, int value);
extern int of_list_group_stats_entry_OF_VERSION_1_3_check(
    of_list_group_stats_entry_t *obj, int value);
extern int of_list_group_stats_entry_OF_VERSION_1_3_populate_scalars(
    of_list_group_stats_entry_t *obj, int value);
extern int of_list_group_stats_entry_OF_VERSION_1_3_check_scalars(
    of_list_group_stats_entry_t *obj, int value);

extern int of_list_hello_elem_OF_VERSION_1_3_populate(
    of_list_hello_elem_t *obj, int value);
extern int of_list_hello_elem_OF_VERSION_1_3_check(
    of_list_hello_elem_t *obj, int value);
extern int of_list_hello_elem_OF_VERSION_1_3_populate_scalars(
    of_list_hello_elem_t *obj, int value);
extern int of_list_hello_elem_OF_VERSION_1_3_check_scalars(
    of_list_hello_elem_t *obj, int value);

extern int of_list_instruction_OF_VERSION_1_3_populate(
    of_list_instruction_t *obj, int value);
extern int of_list_instruction_OF_VERSION_1_3_check(
    of_list_instruction_t *obj, int value);
extern int of_list_instruction_OF_VERSION_1_3_populate_scalars(
    of_list_instruction_t *obj, int value);
extern int of_list_instruction_OF_VERSION_1_3_check_scalars(
    of_list_instruction_t *obj, int value);

extern int of_list_instruction_id_OF_VERSION_1_3_populate(
    of_list_instruction_id_t *obj, int value);
extern int of_list_instruction_id_OF_VERSION_1_3_check(
    of_list_instruction_id_t *obj, int value);
extern int of_list_instruction_id_OF_VERSION_1_3_populate_scalars(
    of_list_instruction_id_t *obj, int value);
extern int of_list_instruction_id_OF_VERSION_1_3_check_scalars(
    of_list_instruction_id_t *obj, int value);

extern int of_list_meter_band_OF_VERSION_1_3_populate(
    of_list_meter_band_t *obj, int value);
extern int of_list_meter_band_OF_VERSION_1_3_check(
    of_list_meter_band_t *obj, int value);
extern int of_list_meter_band_OF_VERSION_1_3_populate_scalars(
    of_list_meter_band_t *obj, int value);
extern int of_list_meter_band_OF_VERSION_1_3_check_scalars(
    of_list_meter_band_t *obj, int value);

extern int of_list_meter_band_stats_OF_VERSION_1_3_populate(
    of_list_meter_band_stats_t *obj, int value);
extern int of_list_meter_band_stats_OF_VERSION_1_3_check(
    of_list_meter_band_stats_t *obj, int value);
extern int of_list_meter_band_stats_OF_VERSION_1_3_populate_scalars(
    of_list_meter_band_stats_t *obj, int value);
extern int of_list_meter_band_stats_OF_VERSION_1_3_check_scalars(
    of_list_meter_band_stats_t *obj, int value);

extern int of_list_meter_config_OF_VERSION_1_3_populate(
    of_list_meter_config_t *obj, int value);
extern int of_list_meter_config_OF_VERSION_1_3_check(
    of_list_meter_config_t *obj, int value);
extern int of_list_meter_config_OF_VERSION_1_3_populate_scalars(
    of_list_meter_config_t *obj, int value);
extern int of_list_meter_config_OF_VERSION_1_3_check_scalars(
    of_list_meter_config_t *obj, int value);

extern int of_list_meter_stats_OF_VERSION_1_3_populate(
    of_list_meter_stats_t *obj, int value);
extern int of_list_meter_stats_OF_VERSION_1_3_check(
    of_list_meter_stats_t *obj, int value);
extern int of_list_meter_stats_OF_VERSION_1_3_populate_scalars(
    of_list_meter_stats_t *obj, int value);
extern int of_list_meter_stats_OF_VERSION_1_3_check_scalars(
    of_list_meter_stats_t *obj, int value);

extern int of_list_oxm_OF_VERSION_1_3_populate(
    of_list_oxm_t *obj, int value);
extern int of_list_oxm_OF_VERSION_1_3_check(
    of_list_oxm_t *obj, int value);
extern int of_list_oxm_OF_VERSION_1_3_populate_scalars(
    of_list_oxm_t *obj, int value);
extern int of_list_oxm_OF_VERSION_1_3_check_scalars(
    of_list_oxm_t *obj, int value);

extern int of_list_packet_queue_OF_VERSION_1_3_populate(
    of_list_packet_queue_t *obj, int value);
extern int of_list_packet_queue_OF_VERSION_1_3_check(
    of_list_packet_queue_t *obj, int value);
extern int of_list_packet_queue_OF_VERSION_1_3_populate_scalars(
    of_list_packet_queue_t *obj, int value);
extern int of_list_packet_queue_OF_VERSION_1_3_check_scalars(
    of_list_packet_queue_t *obj, int value);

extern int of_list_port_desc_OF_VERSION_1_3_populate(
    of_list_port_desc_t *obj, int value);
extern int of_list_port_desc_OF_VERSION_1_3_check(
    of_list_port_desc_t *obj, int value);
extern int of_list_port_desc_OF_VERSION_1_3_populate_scalars(
    of_list_port_desc_t *obj, int value);
extern int of_list_port_desc_OF_VERSION_1_3_check_scalars(
    of_list_port_desc_t *obj, int value);

extern int of_list_port_stats_entry_OF_VERSION_1_3_populate(
    of_list_port_stats_entry_t *obj, int value);
extern int of_list_port_stats_entry_OF_VERSION_1_3_check(
    of_list_port_stats_entry_t *obj, int value);
extern int of_list_port_stats_entry_OF_VERSION_1_3_populate_scalars(
    of_list_port_stats_entry_t *obj, int value);
extern int of_list_port_stats_entry_OF_VERSION_1_3_check_scalars(
    of_list_port_stats_entry_t *obj, int value);

extern int of_list_queue_prop_OF_VERSION_1_3_populate(
    of_list_queue_prop_t *obj, int value);
extern int of_list_queue_prop_OF_VERSION_1_3_check(
    of_list_queue_prop_t *obj, int value);
extern int of_list_queue_prop_OF_VERSION_1_3_populate_scalars(
    of_list_queue_prop_t *obj, int value);
extern int of_list_queue_prop_OF_VERSION_1_3_check_scalars(
    of_list_queue_prop_t *obj, int value);

extern int of_list_queue_stats_entry_OF_VERSION_1_3_populate(
    of_list_queue_stats_entry_t *obj, int value);
extern int of_list_queue_stats_entry_OF_VERSION_1_3_check(
    of_list_queue_stats_entry_t *obj, int value);
extern int of_list_queue_stats_entry_OF_VERSION_1_3_populate_scalars(
    of_list_queue_stats_entry_t *obj, int value);
extern int of_list_queue_stats_entry_OF_VERSION_1_3_check_scalars(
    of_list_queue_stats_entry_t *obj, int value);

extern int of_list_table_feature_prop_OF_VERSION_1_3_populate(
    of_list_table_feature_prop_t *obj, int value);
extern int of_list_table_feature_prop_OF_VERSION_1_3_check(
    of_list_table_feature_prop_t *obj, int value);
extern int of_list_table_feature_prop_OF_VERSION_1_3_populate_scalars(
    of_list_table_feature_prop_t *obj, int value);
extern int of_list_table_feature_prop_OF_VERSION_1_3_check_scalars(
    of_list_table_feature_prop_t *obj, int value);

extern int of_list_table_features_OF_VERSION_1_3_populate(
    of_list_table_features_t *obj, int value);
extern int of_list_table_features_OF_VERSION_1_3_check(
    of_list_table_features_t *obj, int value);
extern int of_list_table_features_OF_VERSION_1_3_populate_scalars(
    of_list_table_features_t *obj, int value);
extern int of_list_table_features_OF_VERSION_1_3_check_scalars(
    of_list_table_features_t *obj, int value);

extern int of_list_table_stats_entry_OF_VERSION_1_3_populate(
    of_list_table_stats_entry_t *obj, int value);
extern int of_list_table_stats_entry_OF_VERSION_1_3_check(
    of_list_table_stats_entry_t *obj, int value);
extern int of_list_table_stats_entry_OF_VERSION_1_3_populate_scalars(
    of_list_table_stats_entry_t *obj, int value);
extern int of_list_table_stats_entry_OF_VERSION_1_3_check_scalars(
    of_list_table_stats_entry_t *obj, int value);

extern int of_list_uint32_OF_VERSION_1_3_populate(
    of_list_uint32_t *obj, int value);
extern int of_list_uint32_OF_VERSION_1_3_check(
    of_list_uint32_t *obj, int value);
extern int of_list_uint32_OF_VERSION_1_3_populate_scalars(
    of_list_uint32_t *obj, int value);
extern int of_list_uint32_OF_VERSION_1_3_check_scalars(
    of_list_uint32_t *obj, int value);

extern int of_list_uint64_OF_VERSION_1_3_populate(
    of_list_uint64_t *obj, int value);
extern int of_list_uint64_OF_VERSION_1_3_check(
    of_list_uint64_t *obj, int value);
extern int of_list_uint64_OF_VERSION_1_3_populate_scalars(
    of_list_uint64_t *obj, int value);
extern int of_list_uint64_OF_VERSION_1_3_check_scalars(
    of_list_uint64_t *obj, int value);

extern int of_list_uint8_OF_VERSION_1_3_populate(
    of_list_uint8_t *obj, int value);
extern int of_list_uint8_OF_VERSION_1_3_check(
    of_list_uint8_t *obj, int value);
extern int of_list_uint8_OF_VERSION_1_3_populate_scalars(
    of_list_uint8_t *obj, int value);
extern int of_list_uint8_OF_VERSION_1_3_check_scalars(
    of_list_uint8_t *obj, int value);

extern int of_aggregate_stats_reply_OF_VERSION_1_4_populate(
    of_aggregate_stats_reply_t *obj, int value);
extern int of_aggregate_stats_reply_OF_VERSION_1_4_check(
    of_aggregate_stats_reply_t *obj, int value);
extern int of_aggregate_stats_reply_OF_VERSION_1_4_populate_scalars(
    of_aggregate_stats_reply_t *obj, int value);
extern int of_aggregate_stats_reply_OF_VERSION_1_4_check_scalars(
    of_aggregate_stats_reply_t *obj, int value);

extern int of_aggregate_stats_request_OF_VERSION_1_4_populate(
    of_aggregate_stats_request_t *obj, int value);
extern int of_aggregate_stats_request_OF_VERSION_1_4_check(
    of_aggregate_stats_request_t *obj, int value);
extern int of_aggregate_stats_request_OF_VERSION_1_4_populate_scalars(
    of_aggregate_stats_request_t *obj, int value);
extern int of_aggregate_stats_request_OF_VERSION_1_4_check_scalars(
    of_aggregate_stats_request_t *obj, int value);

extern int of_async_config_failed_error_msg_OF_VERSION_1_4_populate(
    of_async_config_failed_error_msg_t *obj, int value);
extern int of_async_config_failed_error_msg_OF_VERSION_1_4_check(
    of_async_config_failed_error_msg_t *obj, int value);
extern int of_async_config_failed_error_msg_OF_VERSION_1_4_populate_scalars(
    of_async_config_failed_error_msg_t *obj, int value);
extern int of_async_config_failed_error_msg_OF_VERSION_1_4_check_scalars(
    of_async_config_failed_error_msg_t *obj, int value);

extern int of_async_get_reply_OF_VERSION_1_4_populate(
    of_async_get_reply_t *obj, int value);
extern int of_async_get_reply_OF_VERSION_1_4_check(
    of_async_get_reply_t *obj, int value);
extern int of_async_get_reply_OF_VERSION_1_4_populate_scalars(
    of_async_get_reply_t *obj, int value);
extern int of_async_get_reply_OF_VERSION_1_4_check_scalars(
    of_async_get_reply_t *obj, int value);

extern int of_async_get_request_OF_VERSION_1_4_populate(
    of_async_get_request_t *obj, int value);
extern int of_async_get_request_OF_VERSION_1_4_check(
    of_async_get_request_t *obj, int value);
extern int of_async_get_request_OF_VERSION_1_4_populate_scalars(
    of_async_get_request_t *obj, int value);
extern int of_async_get_request_OF_VERSION_1_4_check_scalars(
    of_async_get_request_t *obj, int value);

extern int of_async_set_OF_VERSION_1_4_populate(
    of_async_set_t *obj, int value);
extern int of_async_set_OF_VERSION_1_4_check(
    of_async_set_t *obj, int value);
extern int of_async_set_OF_VERSION_1_4_populate_scalars(
    of_async_set_t *obj, int value);
extern int of_async_set_OF_VERSION_1_4_check_scalars(
    of_async_set_t *obj, int value);

extern int of_bad_action_error_msg_OF_VERSION_1_4_populate(
    of_bad_action_error_msg_t *obj, int value);
extern int of_bad_action_error_msg_OF_VERSION_1_4_check(
    of_bad_action_error_msg_t *obj, int value);
extern int of_bad_action_error_msg_OF_VERSION_1_4_populate_scalars(
    of_bad_action_error_msg_t *obj, int value);
extern int of_bad_action_error_msg_OF_VERSION_1_4_check_scalars(
    of_bad_action_error_msg_t *obj, int value);

extern int of_bad_instruction_error_msg_OF_VERSION_1_4_populate(
    of_bad_instruction_error_msg_t *obj, int value);
extern int of_bad_instruction_error_msg_OF_VERSION_1_4_check(
    of_bad_instruction_error_msg_t *obj, int value);
extern int of_bad_instruction_error_msg_OF_VERSION_1_4_populate_scalars(
    of_bad_instruction_error_msg_t *obj, int value);
extern int of_bad_instruction_error_msg_OF_VERSION_1_4_check_scalars(
    of_bad_instruction_error_msg_t *obj, int value);

extern int of_bad_match_error_msg_OF_VERSION_1_4_populate(
    of_bad_match_error_msg_t *obj, int value);
extern int of_bad_match_error_msg_OF_VERSION_1_4_check(
    of_bad_match_error_msg_t *obj, int value);
extern int of_bad_match_error_msg_OF_VERSION_1_4_populate_scalars(
    of_bad_match_error_msg_t *obj, int value);
extern int of_bad_match_error_msg_OF_VERSION_1_4_check_scalars(
    of_bad_match_error_msg_t *obj, int value);

extern int of_bad_property_error_msg_OF_VERSION_1_4_populate(
    of_bad_property_error_msg_t *obj, int value);
extern int of_bad_property_error_msg_OF_VERSION_1_4_check(
    of_bad_property_error_msg_t *obj, int value);
extern int of_bad_property_error_msg_OF_VERSION_1_4_populate_scalars(
    of_bad_property_error_msg_t *obj, int value);
extern int of_bad_property_error_msg_OF_VERSION_1_4_check_scalars(
    of_bad_property_error_msg_t *obj, int value);

extern int of_bad_request_error_msg_OF_VERSION_1_4_populate(
    of_bad_request_error_msg_t *obj, int value);
extern int of_bad_request_error_msg_OF_VERSION_1_4_check(
    of_bad_request_error_msg_t *obj, int value);
extern int of_bad_request_error_msg_OF_VERSION_1_4_populate_scalars(
    of_bad_request_error_msg_t *obj, int value);
extern int of_bad_request_error_msg_OF_VERSION_1_4_check_scalars(
    of_bad_request_error_msg_t *obj, int value);

extern int of_barrier_reply_OF_VERSION_1_4_populate(
    of_barrier_reply_t *obj, int value);
extern int of_barrier_reply_OF_VERSION_1_4_check(
    of_barrier_reply_t *obj, int value);
extern int of_barrier_reply_OF_VERSION_1_4_populate_scalars(
    of_barrier_reply_t *obj, int value);
extern int of_barrier_reply_OF_VERSION_1_4_check_scalars(
    of_barrier_reply_t *obj, int value);

extern int of_barrier_request_OF_VERSION_1_4_populate(
    of_barrier_request_t *obj, int value);
extern int of_barrier_request_OF_VERSION_1_4_check(
    of_barrier_request_t *obj, int value);
extern int of_barrier_request_OF_VERSION_1_4_populate_scalars(
    of_barrier_request_t *obj, int value);
extern int of_barrier_request_OF_VERSION_1_4_check_scalars(
    of_barrier_request_t *obj, int value);

extern int of_bsn_arp_idle_OF_VERSION_1_4_populate(
    of_bsn_arp_idle_t *obj, int value);
extern int of_bsn_arp_idle_OF_VERSION_1_4_check(
    of_bsn_arp_idle_t *obj, int value);
extern int of_bsn_arp_idle_OF_VERSION_1_4_populate_scalars(
    of_bsn_arp_idle_t *obj, int value);
extern int of_bsn_arp_idle_OF_VERSION_1_4_check_scalars(
    of_bsn_arp_idle_t *obj, int value);

extern int of_bsn_bw_clear_data_reply_OF_VERSION_1_4_populate(
    of_bsn_bw_clear_data_reply_t *obj, int value);
extern int of_bsn_bw_clear_data_reply_OF_VERSION_1_4_check(
    of_bsn_bw_clear_data_reply_t *obj, int value);
extern int of_bsn_bw_clear_data_reply_OF_VERSION_1_4_populate_scalars(
    of_bsn_bw_clear_data_reply_t *obj, int value);
extern int of_bsn_bw_clear_data_reply_OF_VERSION_1_4_check_scalars(
    of_bsn_bw_clear_data_reply_t *obj, int value);

extern int of_bsn_bw_clear_data_request_OF_VERSION_1_4_populate(
    of_bsn_bw_clear_data_request_t *obj, int value);
extern int of_bsn_bw_clear_data_request_OF_VERSION_1_4_check(
    of_bsn_bw_clear_data_request_t *obj, int value);
extern int of_bsn_bw_clear_data_request_OF_VERSION_1_4_populate_scalars(
    of_bsn_bw_clear_data_request_t *obj, int value);
extern int of_bsn_bw_clear_data_request_OF_VERSION_1_4_check_scalars(
    of_bsn_bw_clear_data_request_t *obj, int value);

extern int of_bsn_bw_enable_get_reply_OF_VERSION_1_4_populate(
    of_bsn_bw_enable_get_reply_t *obj, int value);
extern int of_bsn_bw_enable_get_reply_OF_VERSION_1_4_check(
    of_bsn_bw_enable_get_reply_t *obj, int value);
extern int of_bsn_bw_enable_get_reply_OF_VERSION_1_4_populate_scalars(
    of_bsn_bw_enable_get_reply_t *obj, int value);
extern int of_bsn_bw_enable_get_reply_OF_VERSION_1_4_check_scalars(
    of_bsn_bw_enable_get_reply_t *obj, int value);

extern int of_bsn_bw_enable_get_request_OF_VERSION_1_4_populate(
    of_bsn_bw_enable_get_request_t *obj, int value);
extern int of_bsn_bw_enable_get_request_OF_VERSION_1_4_check(
    of_bsn_bw_enable_get_request_t *obj, int value);
extern int of_bsn_bw_enable_get_request_OF_VERSION_1_4_populate_scalars(
    of_bsn_bw_enable_get_request_t *obj, int value);
extern int of_bsn_bw_enable_get_request_OF_VERSION_1_4_check_scalars(
    of_bsn_bw_enable_get_request_t *obj, int value);

extern int of_bsn_bw_enable_set_reply_OF_VERSION_1_4_populate(
    of_bsn_bw_enable_set_reply_t *obj, int value);
extern int of_bsn_bw_enable_set_reply_OF_VERSION_1_4_check(
    of_bsn_bw_enable_set_reply_t *obj, int value);
extern int of_bsn_bw_enable_set_reply_OF_VERSION_1_4_populate_scalars(
    of_bsn_bw_enable_set_reply_t *obj, int value);
extern int of_bsn_bw_enable_set_reply_OF_VERSION_1_4_check_scalars(
    of_bsn_bw_enable_set_reply_t *obj, int value);

extern int of_bsn_bw_enable_set_request_OF_VERSION_1_4_populate(
    of_bsn_bw_enable_set_request_t *obj, int value);
extern int of_bsn_bw_enable_set_request_OF_VERSION_1_4_check(
    of_bsn_bw_enable_set_request_t *obj, int value);
extern int of_bsn_bw_enable_set_request_OF_VERSION_1_4_populate_scalars(
    of_bsn_bw_enable_set_request_t *obj, int value);
extern int of_bsn_bw_enable_set_request_OF_VERSION_1_4_check_scalars(
    of_bsn_bw_enable_set_request_t *obj, int value);

extern int of_bsn_controller_connections_reply_OF_VERSION_1_4_populate(
    of_bsn_controller_connections_reply_t *obj, int value);
extern int of_bsn_controller_connections_reply_OF_VERSION_1_4_check(
    of_bsn_controller_connections_reply_t *obj, int value);
extern int of_bsn_controller_connections_reply_OF_VERSION_1_4_populate_scalars(
    of_bsn_controller_connections_reply_t *obj, int value);
extern int of_bsn_controller_connections_reply_OF_VERSION_1_4_check_scalars(
    of_bsn_controller_connections_reply_t *obj, int value);

extern int of_bsn_controller_connections_request_OF_VERSION_1_4_populate(
    of_bsn_controller_connections_request_t *obj, int value);
extern int of_bsn_controller_connections_request_OF_VERSION_1_4_check(
    of_bsn_controller_connections_request_t *obj, int value);
extern int of_bsn_controller_connections_request_OF_VERSION_1_4_populate_scalars(
    of_bsn_controller_connections_request_t *obj, int value);
extern int of_bsn_controller_connections_request_OF_VERSION_1_4_check_scalars(
    of_bsn_controller_connections_request_t *obj, int value);

extern int of_bsn_debug_counter_desc_stats_reply_OF_VERSION_1_4_populate(
    of_bsn_debug_counter_desc_stats_reply_t *obj, int value);
extern int of_bsn_debug_counter_desc_stats_reply_OF_VERSION_1_4_check(
    of_bsn_debug_counter_desc_stats_reply_t *obj, int value);
extern int of_bsn_debug_counter_desc_stats_reply_OF_VERSION_1_4_populate_scalars(
    of_bsn_debug_counter_desc_stats_reply_t *obj, int value);
extern int of_bsn_debug_counter_desc_stats_reply_OF_VERSION_1_4_check_scalars(
    of_bsn_debug_counter_desc_stats_reply_t *obj, int value);

extern int of_bsn_debug_counter_desc_stats_request_OF_VERSION_1_4_populate(
    of_bsn_debug_counter_desc_stats_request_t *obj, int value);
extern int of_bsn_debug_counter_desc_stats_request_OF_VERSION_1_4_check(
    of_bsn_debug_counter_desc_stats_request_t *obj, int value);
extern int of_bsn_debug_counter_desc_stats_request_OF_VERSION_1_4_populate_scalars(
    of_bsn_debug_counter_desc_stats_request_t *obj, int value);
extern int of_bsn_debug_counter_desc_stats_request_OF_VERSION_1_4_check_scalars(
    of_bsn_debug_counter_desc_stats_request_t *obj, int value);

extern int of_bsn_debug_counter_stats_reply_OF_VERSION_1_4_populate(
    of_bsn_debug_counter_stats_reply_t *obj, int value);
extern int of_bsn_debug_counter_stats_reply_OF_VERSION_1_4_check(
    of_bsn_debug_counter_stats_reply_t *obj, int value);
extern int of_bsn_debug_counter_stats_reply_OF_VERSION_1_4_populate_scalars(
    of_bsn_debug_counter_stats_reply_t *obj, int value);
extern int of_bsn_debug_counter_stats_reply_OF_VERSION_1_4_check_scalars(
    of_bsn_debug_counter_stats_reply_t *obj, int value);

extern int of_bsn_debug_counter_stats_request_OF_VERSION_1_4_populate(
    of_bsn_debug_counter_stats_request_t *obj, int value);
extern int of_bsn_debug_counter_stats_request_OF_VERSION_1_4_check(
    of_bsn_debug_counter_stats_request_t *obj, int value);
extern int of_bsn_debug_counter_stats_request_OF_VERSION_1_4_populate_scalars(
    of_bsn_debug_counter_stats_request_t *obj, int value);
extern int of_bsn_debug_counter_stats_request_OF_VERSION_1_4_check_scalars(
    of_bsn_debug_counter_stats_request_t *obj, int value);

extern int of_bsn_error_OF_VERSION_1_4_populate(
    of_bsn_error_t *obj, int value);
extern int of_bsn_error_OF_VERSION_1_4_check(
    of_bsn_error_t *obj, int value);
extern int of_bsn_error_OF_VERSION_1_4_populate_scalars(
    of_bsn_error_t *obj, int value);
extern int of_bsn_error_OF_VERSION_1_4_check_scalars(
    of_bsn_error_t *obj, int value);

extern int of_bsn_flow_checksum_bucket_stats_reply_OF_VERSION_1_4_populate(
    of_bsn_flow_checksum_bucket_stats_reply_t *obj, int value);
extern int of_bsn_flow_checksum_bucket_stats_reply_OF_VERSION_1_4_check(
    of_bsn_flow_checksum_bucket_stats_reply_t *obj, int value);
extern int of_bsn_flow_checksum_bucket_stats_reply_OF_VERSION_1_4_populate_scalars(
    of_bsn_flow_checksum_bucket_stats_reply_t *obj, int value);
extern int of_bsn_flow_checksum_bucket_stats_reply_OF_VERSION_1_4_check_scalars(
    of_bsn_flow_checksum_bucket_stats_reply_t *obj, int value);

extern int of_bsn_flow_checksum_bucket_stats_request_OF_VERSION_1_4_populate(
    of_bsn_flow_checksum_bucket_stats_request_t *obj, int value);
extern int of_bsn_flow_checksum_bucket_stats_request_OF_VERSION_1_4_check(
    of_bsn_flow_checksum_bucket_stats_request_t *obj, int value);
extern int of_bsn_flow_checksum_bucket_stats_request_OF_VERSION_1_4_populate_scalars(
    of_bsn_flow_checksum_bucket_stats_request_t *obj, int value);
extern int of_bsn_flow_checksum_bucket_stats_request_OF_VERSION_1_4_check_scalars(
    of_bsn_flow_checksum_bucket_stats_request_t *obj, int value);

extern int of_bsn_flow_idle_OF_VERSION_1_4_populate(
    of_bsn_flow_idle_t *obj, int value);
extern int of_bsn_flow_idle_OF_VERSION_1_4_check(
    of_bsn_flow_idle_t *obj, int value);
extern int of_bsn_flow_idle_OF_VERSION_1_4_populate_scalars(
    of_bsn_flow_idle_t *obj, int value);
extern int of_bsn_flow_idle_OF_VERSION_1_4_check_scalars(
    of_bsn_flow_idle_t *obj, int value);

extern int of_bsn_flow_idle_enable_get_reply_OF_VERSION_1_4_populate(
    of_bsn_flow_idle_enable_get_reply_t *obj, int value);
extern int of_bsn_flow_idle_enable_get_reply_OF_VERSION_1_4_check(
    of_bsn_flow_idle_enable_get_reply_t *obj, int value);
extern int of_bsn_flow_idle_enable_get_reply_OF_VERSION_1_4_populate_scalars(
    of_bsn_flow_idle_enable_get_reply_t *obj, int value);
extern int of_bsn_flow_idle_enable_get_reply_OF_VERSION_1_4_check_scalars(
    of_bsn_flow_idle_enable_get_reply_t *obj, int value);

extern int of_bsn_flow_idle_enable_get_request_OF_VERSION_1_4_populate(
    of_bsn_flow_idle_enable_get_request_t *obj, int value);
extern int of_bsn_flow_idle_enable_get_request_OF_VERSION_1_4_check(
    of_bsn_flow_idle_enable_get_request_t *obj, int value);
extern int of_bsn_flow_idle_enable_get_request_OF_VERSION_1_4_populate_scalars(
    of_bsn_flow_idle_enable_get_request_t *obj, int value);
extern int of_bsn_flow_idle_enable_get_request_OF_VERSION_1_4_check_scalars(
    of_bsn_flow_idle_enable_get_request_t *obj, int value);

extern int of_bsn_flow_idle_enable_set_reply_OF_VERSION_1_4_populate(
    of_bsn_flow_idle_enable_set_reply_t *obj, int value);
extern int of_bsn_flow_idle_enable_set_reply_OF_VERSION_1_4_check(
    of_bsn_flow_idle_enable_set_reply_t *obj, int value);
extern int of_bsn_flow_idle_enable_set_reply_OF_VERSION_1_4_populate_scalars(
    of_bsn_flow_idle_enable_set_reply_t *obj, int value);
extern int of_bsn_flow_idle_enable_set_reply_OF_VERSION_1_4_check_scalars(
    of_bsn_flow_idle_enable_set_reply_t *obj, int value);

extern int of_bsn_flow_idle_enable_set_request_OF_VERSION_1_4_populate(
    of_bsn_flow_idle_enable_set_request_t *obj, int value);
extern int of_bsn_flow_idle_enable_set_request_OF_VERSION_1_4_check(
    of_bsn_flow_idle_enable_set_request_t *obj, int value);
extern int of_bsn_flow_idle_enable_set_request_OF_VERSION_1_4_populate_scalars(
    of_bsn_flow_idle_enable_set_request_t *obj, int value);
extern int of_bsn_flow_idle_enable_set_request_OF_VERSION_1_4_check_scalars(
    of_bsn_flow_idle_enable_set_request_t *obj, int value);

extern int of_bsn_generic_async_OF_VERSION_1_4_populate(
    of_bsn_generic_async_t *obj, int value);
extern int of_bsn_generic_async_OF_VERSION_1_4_check(
    of_bsn_generic_async_t *obj, int value);
extern int of_bsn_generic_async_OF_VERSION_1_4_populate_scalars(
    of_bsn_generic_async_t *obj, int value);
extern int of_bsn_generic_async_OF_VERSION_1_4_check_scalars(
    of_bsn_generic_async_t *obj, int value);

extern int of_bsn_generic_command_OF_VERSION_1_4_populate(
    of_bsn_generic_command_t *obj, int value);
extern int of_bsn_generic_command_OF_VERSION_1_4_check(
    of_bsn_generic_command_t *obj, int value);
extern int of_bsn_generic_command_OF_VERSION_1_4_populate_scalars(
    of_bsn_generic_command_t *obj, int value);
extern int of_bsn_generic_command_OF_VERSION_1_4_check_scalars(
    of_bsn_generic_command_t *obj, int value);

extern int of_bsn_generic_stats_reply_OF_VERSION_1_4_populate(
    of_bsn_generic_stats_reply_t *obj, int value);
extern int of_bsn_generic_stats_reply_OF_VERSION_1_4_check(
    of_bsn_generic_stats_reply_t *obj, int value);
extern int of_bsn_generic_stats_reply_OF_VERSION_1_4_populate_scalars(
    of_bsn_generic_stats_reply_t *obj, int value);
extern int of_bsn_generic_stats_reply_OF_VERSION_1_4_check_scalars(
    of_bsn_generic_stats_reply_t *obj, int value);

extern int of_bsn_generic_stats_request_OF_VERSION_1_4_populate(
    of_bsn_generic_stats_request_t *obj, int value);
extern int of_bsn_generic_stats_request_OF_VERSION_1_4_check(
    of_bsn_generic_stats_request_t *obj, int value);
extern int of_bsn_generic_stats_request_OF_VERSION_1_4_populate_scalars(
    of_bsn_generic_stats_request_t *obj, int value);
extern int of_bsn_generic_stats_request_OF_VERSION_1_4_check_scalars(
    of_bsn_generic_stats_request_t *obj, int value);

extern int of_bsn_gentable_bucket_stats_reply_OF_VERSION_1_4_populate(
    of_bsn_gentable_bucket_stats_reply_t *obj, int value);
extern int of_bsn_gentable_bucket_stats_reply_OF_VERSION_1_4_check(
    of_bsn_gentable_bucket_stats_reply_t *obj, int value);
extern int of_bsn_gentable_bucket_stats_reply_OF_VERSION_1_4_populate_scalars(
    of_bsn_gentable_bucket_stats_reply_t *obj, int value);
extern int of_bsn_gentable_bucket_stats_reply_OF_VERSION_1_4_check_scalars(
    of_bsn_gentable_bucket_stats_reply_t *obj, int value);

extern int of_bsn_gentable_bucket_stats_request_OF_VERSION_1_4_populate(
    of_bsn_gentable_bucket_stats_request_t *obj, int value);
extern int of_bsn_gentable_bucket_stats_request_OF_VERSION_1_4_check(
    of_bsn_gentable_bucket_stats_request_t *obj, int value);
extern int of_bsn_gentable_bucket_stats_request_OF_VERSION_1_4_populate_scalars(
    of_bsn_gentable_bucket_stats_request_t *obj, int value);
extern int of_bsn_gentable_bucket_stats_request_OF_VERSION_1_4_check_scalars(
    of_bsn_gentable_bucket_stats_request_t *obj, int value);

extern int of_bsn_gentable_clear_reply_OF_VERSION_1_4_populate(
    of_bsn_gentable_clear_reply_t *obj, int value);
extern int of_bsn_gentable_clear_reply_OF_VERSION_1_4_check(
    of_bsn_gentable_clear_reply_t *obj, int value);
extern int of_bsn_gentable_clear_reply_OF_VERSION_1_4_populate_scalars(
    of_bsn_gentable_clear_reply_t *obj, int value);
extern int of_bsn_gentable_clear_reply_OF_VERSION_1_4_check_scalars(
    of_bsn_gentable_clear_reply_t *obj, int value);

extern int of_bsn_gentable_clear_request_OF_VERSION_1_4_populate(
    of_bsn_gentable_clear_request_t *obj, int value);
extern int of_bsn_gentable_clear_request_OF_VERSION_1_4_check(
    of_bsn_gentable_clear_request_t *obj, int value);
extern int of_bsn_gentable_clear_request_OF_VERSION_1_4_populate_scalars(
    of_bsn_gentable_clear_request_t *obj, int value);
extern int of_bsn_gentable_clear_request_OF_VERSION_1_4_check_scalars(
    of_bsn_gentable_clear_request_t *obj, int value);

extern int of_bsn_gentable_desc_stats_reply_OF_VERSION_1_4_populate(
    of_bsn_gentable_desc_stats_reply_t *obj, int value);
extern int of_bsn_gentable_desc_stats_reply_OF_VERSION_1_4_check(
    of_bsn_gentable_desc_stats_reply_t *obj, int value);
extern int of_bsn_gentable_desc_stats_reply_OF_VERSION_1_4_populate_scalars(
    of_bsn_gentable_desc_stats_reply_t *obj, int value);
extern int of_bsn_gentable_desc_stats_reply_OF_VERSION_1_4_check_scalars(
    of_bsn_gentable_desc_stats_reply_t *obj, int value);

extern int of_bsn_gentable_desc_stats_request_OF_VERSION_1_4_populate(
    of_bsn_gentable_desc_stats_request_t *obj, int value);
extern int of_bsn_gentable_desc_stats_request_OF_VERSION_1_4_check(
    of_bsn_gentable_desc_stats_request_t *obj, int value);
extern int of_bsn_gentable_desc_stats_request_OF_VERSION_1_4_populate_scalars(
    of_bsn_gentable_desc_stats_request_t *obj, int value);
extern int of_bsn_gentable_desc_stats_request_OF_VERSION_1_4_check_scalars(
    of_bsn_gentable_desc_stats_request_t *obj, int value);

extern int of_bsn_gentable_entry_add_OF_VERSION_1_4_populate(
    of_bsn_gentable_entry_add_t *obj, int value);
extern int of_bsn_gentable_entry_add_OF_VERSION_1_4_check(
    of_bsn_gentable_entry_add_t *obj, int value);
extern int of_bsn_gentable_entry_add_OF_VERSION_1_4_populate_scalars(
    of_bsn_gentable_entry_add_t *obj, int value);
extern int of_bsn_gentable_entry_add_OF_VERSION_1_4_check_scalars(
    of_bsn_gentable_entry_add_t *obj, int value);

extern int of_bsn_gentable_entry_delete_OF_VERSION_1_4_populate(
    of_bsn_gentable_entry_delete_t *obj, int value);
extern int of_bsn_gentable_entry_delete_OF_VERSION_1_4_check(
    of_bsn_gentable_entry_delete_t *obj, int value);
extern int of_bsn_gentable_entry_delete_OF_VERSION_1_4_populate_scalars(
    of_bsn_gentable_entry_delete_t *obj, int value);
extern int of_bsn_gentable_entry_delete_OF_VERSION_1_4_check_scalars(
    of_bsn_gentable_entry_delete_t *obj, int value);

extern int of_bsn_gentable_entry_desc_stats_reply_OF_VERSION_1_4_populate(
    of_bsn_gentable_entry_desc_stats_reply_t *obj, int value);
extern int of_bsn_gentable_entry_desc_stats_reply_OF_VERSION_1_4_check(
    of_bsn_gentable_entry_desc_stats_reply_t *obj, int value);
extern int of_bsn_gentable_entry_desc_stats_reply_OF_VERSION_1_4_populate_scalars(
    of_bsn_gentable_entry_desc_stats_reply_t *obj, int value);
extern int of_bsn_gentable_entry_desc_stats_reply_OF_VERSION_1_4_check_scalars(
    of_bsn_gentable_entry_desc_stats_reply_t *obj, int value);

extern int of_bsn_gentable_entry_desc_stats_request_OF_VERSION_1_4_populate(
    of_bsn_gentable_entry_desc_stats_request_t *obj, int value);
extern int of_bsn_gentable_entry_desc_stats_request_OF_VERSION_1_4_check(
    of_bsn_gentable_entry_desc_stats_request_t *obj, int value);
extern int of_bsn_gentable_entry_desc_stats_request_OF_VERSION_1_4_populate_scalars(
    of_bsn_gentable_entry_desc_stats_request_t *obj, int value);
extern int of_bsn_gentable_entry_desc_stats_request_OF_VERSION_1_4_check_scalars(
    of_bsn_gentable_entry_desc_stats_request_t *obj, int value);

extern int of_bsn_gentable_entry_stats_reply_OF_VERSION_1_4_populate(
    of_bsn_gentable_entry_stats_reply_t *obj, int value);
extern int of_bsn_gentable_entry_stats_reply_OF_VERSION_1_4_check(
    of_bsn_gentable_entry_stats_reply_t *obj, int value);
extern int of_bsn_gentable_entry_stats_reply_OF_VERSION_1_4_populate_scalars(
    of_bsn_gentable_entry_stats_reply_t *obj, int value);
extern int of_bsn_gentable_entry_stats_reply_OF_VERSION_1_4_check_scalars(
    of_bsn_gentable_entry_stats_reply_t *obj, int value);

extern int of_bsn_gentable_entry_stats_request_OF_VERSION_1_4_populate(
    of_bsn_gentable_entry_stats_request_t *obj, int value);
extern int of_bsn_gentable_entry_stats_request_OF_VERSION_1_4_check(
    of_bsn_gentable_entry_stats_request_t *obj, int value);
extern int of_bsn_gentable_entry_stats_request_OF_VERSION_1_4_populate_scalars(
    of_bsn_gentable_entry_stats_request_t *obj, int value);
extern int of_bsn_gentable_entry_stats_request_OF_VERSION_1_4_check_scalars(
    of_bsn_gentable_entry_stats_request_t *obj, int value);

extern int of_bsn_gentable_error_OF_VERSION_1_4_populate(
    of_bsn_gentable_error_t *obj, int value);
extern int of_bsn_gentable_error_OF_VERSION_1_4_check(
    of_bsn_gentable_error_t *obj, int value);
extern int of_bsn_gentable_error_OF_VERSION_1_4_populate_scalars(
    of_bsn_gentable_error_t *obj, int value);
extern int of_bsn_gentable_error_OF_VERSION_1_4_check_scalars(
    of_bsn_gentable_error_t *obj, int value);

extern int of_bsn_gentable_set_buckets_size_OF_VERSION_1_4_populate(
    of_bsn_gentable_set_buckets_size_t *obj, int value);
extern int of_bsn_gentable_set_buckets_size_OF_VERSION_1_4_check(
    of_bsn_gentable_set_buckets_size_t *obj, int value);
extern int of_bsn_gentable_set_buckets_size_OF_VERSION_1_4_populate_scalars(
    of_bsn_gentable_set_buckets_size_t *obj, int value);
extern int of_bsn_gentable_set_buckets_size_OF_VERSION_1_4_check_scalars(
    of_bsn_gentable_set_buckets_size_t *obj, int value);

extern int of_bsn_gentable_stats_reply_OF_VERSION_1_4_populate(
    of_bsn_gentable_stats_reply_t *obj, int value);
extern int of_bsn_gentable_stats_reply_OF_VERSION_1_4_check(
    of_bsn_gentable_stats_reply_t *obj, int value);
extern int of_bsn_gentable_stats_reply_OF_VERSION_1_4_populate_scalars(
    of_bsn_gentable_stats_reply_t *obj, int value);
extern int of_bsn_gentable_stats_reply_OF_VERSION_1_4_check_scalars(
    of_bsn_gentable_stats_reply_t *obj, int value);

extern int of_bsn_gentable_stats_request_OF_VERSION_1_4_populate(
    of_bsn_gentable_stats_request_t *obj, int value);
extern int of_bsn_gentable_stats_request_OF_VERSION_1_4_check(
    of_bsn_gentable_stats_request_t *obj, int value);
extern int of_bsn_gentable_stats_request_OF_VERSION_1_4_populate_scalars(
    of_bsn_gentable_stats_request_t *obj, int value);
extern int of_bsn_gentable_stats_request_OF_VERSION_1_4_check_scalars(
    of_bsn_gentable_stats_request_t *obj, int value);

extern int of_bsn_get_interfaces_reply_OF_VERSION_1_4_populate(
    of_bsn_get_interfaces_reply_t *obj, int value);
extern int of_bsn_get_interfaces_reply_OF_VERSION_1_4_check(
    of_bsn_get_interfaces_reply_t *obj, int value);
extern int of_bsn_get_interfaces_reply_OF_VERSION_1_4_populate_scalars(
    of_bsn_get_interfaces_reply_t *obj, int value);
extern int of_bsn_get_interfaces_reply_OF_VERSION_1_4_check_scalars(
    of_bsn_get_interfaces_reply_t *obj, int value);

extern int of_bsn_get_interfaces_request_OF_VERSION_1_4_populate(
    of_bsn_get_interfaces_request_t *obj, int value);
extern int of_bsn_get_interfaces_request_OF_VERSION_1_4_check(
    of_bsn_get_interfaces_request_t *obj, int value);
extern int of_bsn_get_interfaces_request_OF_VERSION_1_4_populate_scalars(
    of_bsn_get_interfaces_request_t *obj, int value);
extern int of_bsn_get_interfaces_request_OF_VERSION_1_4_check_scalars(
    of_bsn_get_interfaces_request_t *obj, int value);

extern int of_bsn_get_mirroring_reply_OF_VERSION_1_4_populate(
    of_bsn_get_mirroring_reply_t *obj, int value);
extern int of_bsn_get_mirroring_reply_OF_VERSION_1_4_check(
    of_bsn_get_mirroring_reply_t *obj, int value);
extern int of_bsn_get_mirroring_reply_OF_VERSION_1_4_populate_scalars(
    of_bsn_get_mirroring_reply_t *obj, int value);
extern int of_bsn_get_mirroring_reply_OF_VERSION_1_4_check_scalars(
    of_bsn_get_mirroring_reply_t *obj, int value);

extern int of_bsn_get_mirroring_request_OF_VERSION_1_4_populate(
    of_bsn_get_mirroring_request_t *obj, int value);
extern int of_bsn_get_mirroring_request_OF_VERSION_1_4_check(
    of_bsn_get_mirroring_request_t *obj, int value);
extern int of_bsn_get_mirroring_request_OF_VERSION_1_4_populate_scalars(
    of_bsn_get_mirroring_request_t *obj, int value);
extern int of_bsn_get_mirroring_request_OF_VERSION_1_4_check_scalars(
    of_bsn_get_mirroring_request_t *obj, int value);

extern int of_bsn_get_switch_pipeline_reply_OF_VERSION_1_4_populate(
    of_bsn_get_switch_pipeline_reply_t *obj, int value);
extern int of_bsn_get_switch_pipeline_reply_OF_VERSION_1_4_check(
    of_bsn_get_switch_pipeline_reply_t *obj, int value);
extern int of_bsn_get_switch_pipeline_reply_OF_VERSION_1_4_populate_scalars(
    of_bsn_get_switch_pipeline_reply_t *obj, int value);
extern int of_bsn_get_switch_pipeline_reply_OF_VERSION_1_4_check_scalars(
    of_bsn_get_switch_pipeline_reply_t *obj, int value);

extern int of_bsn_get_switch_pipeline_request_OF_VERSION_1_4_populate(
    of_bsn_get_switch_pipeline_request_t *obj, int value);
extern int of_bsn_get_switch_pipeline_request_OF_VERSION_1_4_check(
    of_bsn_get_switch_pipeline_request_t *obj, int value);
extern int of_bsn_get_switch_pipeline_request_OF_VERSION_1_4_populate_scalars(
    of_bsn_get_switch_pipeline_request_t *obj, int value);
extern int of_bsn_get_switch_pipeline_request_OF_VERSION_1_4_check_scalars(
    of_bsn_get_switch_pipeline_request_t *obj, int value);

extern int of_bsn_image_desc_stats_reply_OF_VERSION_1_4_populate(
    of_bsn_image_desc_stats_reply_t *obj, int value);
extern int of_bsn_image_desc_stats_reply_OF_VERSION_1_4_check(
    of_bsn_image_desc_stats_reply_t *obj, int value);
extern int of_bsn_image_desc_stats_reply_OF_VERSION_1_4_populate_scalars(
    of_bsn_image_desc_stats_reply_t *obj, int value);
extern int of_bsn_image_desc_stats_reply_OF_VERSION_1_4_check_scalars(
    of_bsn_image_desc_stats_reply_t *obj, int value);

extern int of_bsn_image_desc_stats_request_OF_VERSION_1_4_populate(
    of_bsn_image_desc_stats_request_t *obj, int value);
extern int of_bsn_image_desc_stats_request_OF_VERSION_1_4_check(
    of_bsn_image_desc_stats_request_t *obj, int value);
extern int of_bsn_image_desc_stats_request_OF_VERSION_1_4_populate_scalars(
    of_bsn_image_desc_stats_request_t *obj, int value);
extern int of_bsn_image_desc_stats_request_OF_VERSION_1_4_check_scalars(
    of_bsn_image_desc_stats_request_t *obj, int value);

extern int of_bsn_lacp_convergence_notif_OF_VERSION_1_4_populate(
    of_bsn_lacp_convergence_notif_t *obj, int value);
extern int of_bsn_lacp_convergence_notif_OF_VERSION_1_4_check(
    of_bsn_lacp_convergence_notif_t *obj, int value);
extern int of_bsn_lacp_convergence_notif_OF_VERSION_1_4_populate_scalars(
    of_bsn_lacp_convergence_notif_t *obj, int value);
extern int of_bsn_lacp_convergence_notif_OF_VERSION_1_4_check_scalars(
    of_bsn_lacp_convergence_notif_t *obj, int value);

extern int of_bsn_lacp_stats_reply_OF_VERSION_1_4_populate(
    of_bsn_lacp_stats_reply_t *obj, int value);
extern int of_bsn_lacp_stats_reply_OF_VERSION_1_4_check(
    of_bsn_lacp_stats_reply_t *obj, int value);
extern int of_bsn_lacp_stats_reply_OF_VERSION_1_4_populate_scalars(
    of_bsn_lacp_stats_reply_t *obj, int value);
extern int of_bsn_lacp_stats_reply_OF_VERSION_1_4_check_scalars(
    of_bsn_lacp_stats_reply_t *obj, int value);

extern int of_bsn_lacp_stats_request_OF_VERSION_1_4_populate(
    of_bsn_lacp_stats_request_t *obj, int value);
extern int of_bsn_lacp_stats_request_OF_VERSION_1_4_check(
    of_bsn_lacp_stats_request_t *obj, int value);
extern int of_bsn_lacp_stats_request_OF_VERSION_1_4_populate_scalars(
    of_bsn_lacp_stats_request_t *obj, int value);
extern int of_bsn_lacp_stats_request_OF_VERSION_1_4_check_scalars(
    of_bsn_lacp_stats_request_t *obj, int value);

extern int of_bsn_log_OF_VERSION_1_4_populate(
    of_bsn_log_t *obj, int value);
extern int of_bsn_log_OF_VERSION_1_4_check(
    of_bsn_log_t *obj, int value);
extern int of_bsn_log_OF_VERSION_1_4_populate_scalars(
    of_bsn_log_t *obj, int value);
extern int of_bsn_log_OF_VERSION_1_4_check_scalars(
    of_bsn_log_t *obj, int value);

extern int of_bsn_lua_command_reply_OF_VERSION_1_4_populate(
    of_bsn_lua_command_reply_t *obj, int value);
extern int of_bsn_lua_command_reply_OF_VERSION_1_4_check(
    of_bsn_lua_command_reply_t *obj, int value);
extern int of_bsn_lua_command_reply_OF_VERSION_1_4_populate_scalars(
    of_bsn_lua_command_reply_t *obj, int value);
extern int of_bsn_lua_command_reply_OF_VERSION_1_4_check_scalars(
    of_bsn_lua_command_reply_t *obj, int value);

extern int of_bsn_lua_command_request_OF_VERSION_1_4_populate(
    of_bsn_lua_command_request_t *obj, int value);
extern int of_bsn_lua_command_request_OF_VERSION_1_4_check(
    of_bsn_lua_command_request_t *obj, int value);
extern int of_bsn_lua_command_request_OF_VERSION_1_4_populate_scalars(
    of_bsn_lua_command_request_t *obj, int value);
extern int of_bsn_lua_command_request_OF_VERSION_1_4_check_scalars(
    of_bsn_lua_command_request_t *obj, int value);

extern int of_bsn_lua_notification_OF_VERSION_1_4_populate(
    of_bsn_lua_notification_t *obj, int value);
extern int of_bsn_lua_notification_OF_VERSION_1_4_check(
    of_bsn_lua_notification_t *obj, int value);
extern int of_bsn_lua_notification_OF_VERSION_1_4_populate_scalars(
    of_bsn_lua_notification_t *obj, int value);
extern int of_bsn_lua_notification_OF_VERSION_1_4_check_scalars(
    of_bsn_lua_notification_t *obj, int value);

extern int of_bsn_lua_upload_OF_VERSION_1_4_populate(
    of_bsn_lua_upload_t *obj, int value);
extern int of_bsn_lua_upload_OF_VERSION_1_4_check(
    of_bsn_lua_upload_t *obj, int value);
extern int of_bsn_lua_upload_OF_VERSION_1_4_populate_scalars(
    of_bsn_lua_upload_t *obj, int value);
extern int of_bsn_lua_upload_OF_VERSION_1_4_check_scalars(
    of_bsn_lua_upload_t *obj, int value);

extern int of_bsn_pdu_rx_reply_OF_VERSION_1_4_populate(
    of_bsn_pdu_rx_reply_t *obj, int value);
extern int of_bsn_pdu_rx_reply_OF_VERSION_1_4_check(
    of_bsn_pdu_rx_reply_t *obj, int value);
extern int of_bsn_pdu_rx_reply_OF_VERSION_1_4_populate_scalars(
    of_bsn_pdu_rx_reply_t *obj, int value);
extern int of_bsn_pdu_rx_reply_OF_VERSION_1_4_check_scalars(
    of_bsn_pdu_rx_reply_t *obj, int value);

extern int of_bsn_pdu_rx_request_OF_VERSION_1_4_populate(
    of_bsn_pdu_rx_request_t *obj, int value);
extern int of_bsn_pdu_rx_request_OF_VERSION_1_4_check(
    of_bsn_pdu_rx_request_t *obj, int value);
extern int of_bsn_pdu_rx_request_OF_VERSION_1_4_populate_scalars(
    of_bsn_pdu_rx_request_t *obj, int value);
extern int of_bsn_pdu_rx_request_OF_VERSION_1_4_check_scalars(
    of_bsn_pdu_rx_request_t *obj, int value);

extern int of_bsn_pdu_rx_timeout_OF_VERSION_1_4_populate(
    of_bsn_pdu_rx_timeout_t *obj, int value);
extern int of_bsn_pdu_rx_timeout_OF_VERSION_1_4_check(
    of_bsn_pdu_rx_timeout_t *obj, int value);
extern int of_bsn_pdu_rx_timeout_OF_VERSION_1_4_populate_scalars(
    of_bsn_pdu_rx_timeout_t *obj, int value);
extern int of_bsn_pdu_rx_timeout_OF_VERSION_1_4_check_scalars(
    of_bsn_pdu_rx_timeout_t *obj, int value);

extern int of_bsn_pdu_tx_reply_OF_VERSION_1_4_populate(
    of_bsn_pdu_tx_reply_t *obj, int value);
extern int of_bsn_pdu_tx_reply_OF_VERSION_1_4_check(
    of_bsn_pdu_tx_reply_t *obj, int value);
extern int of_bsn_pdu_tx_reply_OF_VERSION_1_4_populate_scalars(
    of_bsn_pdu_tx_reply_t *obj, int value);
extern int of_bsn_pdu_tx_reply_OF_VERSION_1_4_check_scalars(
    of_bsn_pdu_tx_reply_t *obj, int value);

extern int of_bsn_pdu_tx_request_OF_VERSION_1_4_populate(
    of_bsn_pdu_tx_request_t *obj, int value);
extern int of_bsn_pdu_tx_request_OF_VERSION_1_4_check(
    of_bsn_pdu_tx_request_t *obj, int value);
extern int of_bsn_pdu_tx_request_OF_VERSION_1_4_populate_scalars(
    of_bsn_pdu_tx_request_t *obj, int value);
extern int of_bsn_pdu_tx_request_OF_VERSION_1_4_check_scalars(
    of_bsn_pdu_tx_request_t *obj, int value);

extern int of_bsn_port_counter_stats_reply_OF_VERSION_1_4_populate(
    of_bsn_port_counter_stats_reply_t *obj, int value);
extern int of_bsn_port_counter_stats_reply_OF_VERSION_1_4_check(
    of_bsn_port_counter_stats_reply_t *obj, int value);
extern int of_bsn_port_counter_stats_reply_OF_VERSION_1_4_populate_scalars(
    of_bsn_port_counter_stats_reply_t *obj, int value);
extern int of_bsn_port_counter_stats_reply_OF_VERSION_1_4_check_scalars(
    of_bsn_port_counter_stats_reply_t *obj, int value);

extern int of_bsn_port_counter_stats_request_OF_VERSION_1_4_populate(
    of_bsn_port_counter_stats_request_t *obj, int value);
extern int of_bsn_port_counter_stats_request_OF_VERSION_1_4_check(
    of_bsn_port_counter_stats_request_t *obj, int value);
extern int of_bsn_port_counter_stats_request_OF_VERSION_1_4_populate_scalars(
    of_bsn_port_counter_stats_request_t *obj, int value);
extern int of_bsn_port_counter_stats_request_OF_VERSION_1_4_check_scalars(
    of_bsn_port_counter_stats_request_t *obj, int value);

extern int of_bsn_set_aux_cxns_reply_OF_VERSION_1_4_populate(
    of_bsn_set_aux_cxns_reply_t *obj, int value);
extern int of_bsn_set_aux_cxns_reply_OF_VERSION_1_4_check(
    of_bsn_set_aux_cxns_reply_t *obj, int value);
extern int of_bsn_set_aux_cxns_reply_OF_VERSION_1_4_populate_scalars(
    of_bsn_set_aux_cxns_reply_t *obj, int value);
extern int of_bsn_set_aux_cxns_reply_OF_VERSION_1_4_check_scalars(
    of_bsn_set_aux_cxns_reply_t *obj, int value);

extern int of_bsn_set_aux_cxns_request_OF_VERSION_1_4_populate(
    of_bsn_set_aux_cxns_request_t *obj, int value);
extern int of_bsn_set_aux_cxns_request_OF_VERSION_1_4_check(
    of_bsn_set_aux_cxns_request_t *obj, int value);
extern int of_bsn_set_aux_cxns_request_OF_VERSION_1_4_populate_scalars(
    of_bsn_set_aux_cxns_request_t *obj, int value);
extern int of_bsn_set_aux_cxns_request_OF_VERSION_1_4_check_scalars(
    of_bsn_set_aux_cxns_request_t *obj, int value);

extern int of_bsn_set_lacp_reply_OF_VERSION_1_4_populate(
    of_bsn_set_lacp_reply_t *obj, int value);
extern int of_bsn_set_lacp_reply_OF_VERSION_1_4_check(
    of_bsn_set_lacp_reply_t *obj, int value);
extern int of_bsn_set_lacp_reply_OF_VERSION_1_4_populate_scalars(
    of_bsn_set_lacp_reply_t *obj, int value);
extern int of_bsn_set_lacp_reply_OF_VERSION_1_4_check_scalars(
    of_bsn_set_lacp_reply_t *obj, int value);

extern int of_bsn_set_lacp_request_OF_VERSION_1_4_populate(
    of_bsn_set_lacp_request_t *obj, int value);
extern int of_bsn_set_lacp_request_OF_VERSION_1_4_check(
    of_bsn_set_lacp_request_t *obj, int value);
extern int of_bsn_set_lacp_request_OF_VERSION_1_4_populate_scalars(
    of_bsn_set_lacp_request_t *obj, int value);
extern int of_bsn_set_lacp_request_OF_VERSION_1_4_check_scalars(
    of_bsn_set_lacp_request_t *obj, int value);

extern int of_bsn_set_mirroring_OF_VERSION_1_4_populate(
    of_bsn_set_mirroring_t *obj, int value);
extern int of_bsn_set_mirroring_OF_VERSION_1_4_check(
    of_bsn_set_mirroring_t *obj, int value);
extern int of_bsn_set_mirroring_OF_VERSION_1_4_populate_scalars(
    of_bsn_set_mirroring_t *obj, int value);
extern int of_bsn_set_mirroring_OF_VERSION_1_4_check_scalars(
    of_bsn_set_mirroring_t *obj, int value);

extern int of_bsn_set_pktin_suppression_reply_OF_VERSION_1_4_populate(
    of_bsn_set_pktin_suppression_reply_t *obj, int value);
extern int of_bsn_set_pktin_suppression_reply_OF_VERSION_1_4_check(
    of_bsn_set_pktin_suppression_reply_t *obj, int value);
extern int of_bsn_set_pktin_suppression_reply_OF_VERSION_1_4_populate_scalars(
    of_bsn_set_pktin_suppression_reply_t *obj, int value);
extern int of_bsn_set_pktin_suppression_reply_OF_VERSION_1_4_check_scalars(
    of_bsn_set_pktin_suppression_reply_t *obj, int value);

extern int of_bsn_set_pktin_suppression_request_OF_VERSION_1_4_populate(
    of_bsn_set_pktin_suppression_request_t *obj, int value);
extern int of_bsn_set_pktin_suppression_request_OF_VERSION_1_4_check(
    of_bsn_set_pktin_suppression_request_t *obj, int value);
extern int of_bsn_set_pktin_suppression_request_OF_VERSION_1_4_populate_scalars(
    of_bsn_set_pktin_suppression_request_t *obj, int value);
extern int of_bsn_set_pktin_suppression_request_OF_VERSION_1_4_check_scalars(
    of_bsn_set_pktin_suppression_request_t *obj, int value);

extern int of_bsn_set_switch_pipeline_reply_OF_VERSION_1_4_populate(
    of_bsn_set_switch_pipeline_reply_t *obj, int value);
extern int of_bsn_set_switch_pipeline_reply_OF_VERSION_1_4_check(
    of_bsn_set_switch_pipeline_reply_t *obj, int value);
extern int of_bsn_set_switch_pipeline_reply_OF_VERSION_1_4_populate_scalars(
    of_bsn_set_switch_pipeline_reply_t *obj, int value);
extern int of_bsn_set_switch_pipeline_reply_OF_VERSION_1_4_check_scalars(
    of_bsn_set_switch_pipeline_reply_t *obj, int value);

extern int of_bsn_set_switch_pipeline_request_OF_VERSION_1_4_populate(
    of_bsn_set_switch_pipeline_request_t *obj, int value);
extern int of_bsn_set_switch_pipeline_request_OF_VERSION_1_4_check(
    of_bsn_set_switch_pipeline_request_t *obj, int value);
extern int of_bsn_set_switch_pipeline_request_OF_VERSION_1_4_populate_scalars(
    of_bsn_set_switch_pipeline_request_t *obj, int value);
extern int of_bsn_set_switch_pipeline_request_OF_VERSION_1_4_check_scalars(
    of_bsn_set_switch_pipeline_request_t *obj, int value);

extern int of_bsn_switch_pipeline_stats_reply_OF_VERSION_1_4_populate(
    of_bsn_switch_pipeline_stats_reply_t *obj, int value);
extern int of_bsn_switch_pipeline_stats_reply_OF_VERSION_1_4_check(
    of_bsn_switch_pipeline_stats_reply_t *obj, int value);
extern int of_bsn_switch_pipeline_stats_reply_OF_VERSION_1_4_populate_scalars(
    of_bsn_switch_pipeline_stats_reply_t *obj, int value);
extern int of_bsn_switch_pipeline_stats_reply_OF_VERSION_1_4_check_scalars(
    of_bsn_switch_pipeline_stats_reply_t *obj, int value);

extern int of_bsn_switch_pipeline_stats_request_OF_VERSION_1_4_populate(
    of_bsn_switch_pipeline_stats_request_t *obj, int value);
extern int of_bsn_switch_pipeline_stats_request_OF_VERSION_1_4_check(
    of_bsn_switch_pipeline_stats_request_t *obj, int value);
extern int of_bsn_switch_pipeline_stats_request_OF_VERSION_1_4_populate_scalars(
    of_bsn_switch_pipeline_stats_request_t *obj, int value);
extern int of_bsn_switch_pipeline_stats_request_OF_VERSION_1_4_check_scalars(
    of_bsn_switch_pipeline_stats_request_t *obj, int value);

extern int of_bsn_table_checksum_stats_reply_OF_VERSION_1_4_populate(
    of_bsn_table_checksum_stats_reply_t *obj, int value);
extern int of_bsn_table_checksum_stats_reply_OF_VERSION_1_4_check(
    of_bsn_table_checksum_stats_reply_t *obj, int value);
extern int of_bsn_table_checksum_stats_reply_OF_VERSION_1_4_populate_scalars(
    of_bsn_table_checksum_stats_reply_t *obj, int value);
extern int of_bsn_table_checksum_stats_reply_OF_VERSION_1_4_check_scalars(
    of_bsn_table_checksum_stats_reply_t *obj, int value);

extern int of_bsn_table_checksum_stats_request_OF_VERSION_1_4_populate(
    of_bsn_table_checksum_stats_request_t *obj, int value);
extern int of_bsn_table_checksum_stats_request_OF_VERSION_1_4_check(
    of_bsn_table_checksum_stats_request_t *obj, int value);
extern int of_bsn_table_checksum_stats_request_OF_VERSION_1_4_populate_scalars(
    of_bsn_table_checksum_stats_request_t *obj, int value);
extern int of_bsn_table_checksum_stats_request_OF_VERSION_1_4_check_scalars(
    of_bsn_table_checksum_stats_request_t *obj, int value);

extern int of_bsn_table_set_buckets_size_OF_VERSION_1_4_populate(
    of_bsn_table_set_buckets_size_t *obj, int value);
extern int of_bsn_table_set_buckets_size_OF_VERSION_1_4_check(
    of_bsn_table_set_buckets_size_t *obj, int value);
extern int of_bsn_table_set_buckets_size_OF_VERSION_1_4_populate_scalars(
    of_bsn_table_set_buckets_size_t *obj, int value);
extern int of_bsn_table_set_buckets_size_OF_VERSION_1_4_check_scalars(
    of_bsn_table_set_buckets_size_t *obj, int value);

extern int of_bsn_takeover_OF_VERSION_1_4_populate(
    of_bsn_takeover_t *obj, int value);
extern int of_bsn_takeover_OF_VERSION_1_4_check(
    of_bsn_takeover_t *obj, int value);
extern int of_bsn_takeover_OF_VERSION_1_4_populate_scalars(
    of_bsn_takeover_t *obj, int value);
extern int of_bsn_takeover_OF_VERSION_1_4_check_scalars(
    of_bsn_takeover_t *obj, int value);

extern int of_bsn_time_reply_OF_VERSION_1_4_populate(
    of_bsn_time_reply_t *obj, int value);
extern int of_bsn_time_reply_OF_VERSION_1_4_check(
    of_bsn_time_reply_t *obj, int value);
extern int of_bsn_time_reply_OF_VERSION_1_4_populate_scalars(
    of_bsn_time_reply_t *obj, int value);
extern int of_bsn_time_reply_OF_VERSION_1_4_check_scalars(
    of_bsn_time_reply_t *obj, int value);

extern int of_bsn_time_request_OF_VERSION_1_4_populate(
    of_bsn_time_request_t *obj, int value);
extern int of_bsn_time_request_OF_VERSION_1_4_check(
    of_bsn_time_request_t *obj, int value);
extern int of_bsn_time_request_OF_VERSION_1_4_populate_scalars(
    of_bsn_time_request_t *obj, int value);
extern int of_bsn_time_request_OF_VERSION_1_4_check_scalars(
    of_bsn_time_request_t *obj, int value);

extern int of_bsn_virtual_port_create_reply_OF_VERSION_1_4_populate(
    of_bsn_virtual_port_create_reply_t *obj, int value);
extern int of_bsn_virtual_port_create_reply_OF_VERSION_1_4_check(
    of_bsn_virtual_port_create_reply_t *obj, int value);
extern int of_bsn_virtual_port_create_reply_OF_VERSION_1_4_populate_scalars(
    of_bsn_virtual_port_create_reply_t *obj, int value);
extern int of_bsn_virtual_port_create_reply_OF_VERSION_1_4_check_scalars(
    of_bsn_virtual_port_create_reply_t *obj, int value);

extern int of_bsn_virtual_port_create_request_OF_VERSION_1_4_populate(
    of_bsn_virtual_port_create_request_t *obj, int value);
extern int of_bsn_virtual_port_create_request_OF_VERSION_1_4_check(
    of_bsn_virtual_port_create_request_t *obj, int value);
extern int of_bsn_virtual_port_create_request_OF_VERSION_1_4_populate_scalars(
    of_bsn_virtual_port_create_request_t *obj, int value);
extern int of_bsn_virtual_port_create_request_OF_VERSION_1_4_check_scalars(
    of_bsn_virtual_port_create_request_t *obj, int value);

extern int of_bsn_virtual_port_remove_reply_OF_VERSION_1_4_populate(
    of_bsn_virtual_port_remove_reply_t *obj, int value);
extern int of_bsn_virtual_port_remove_reply_OF_VERSION_1_4_check(
    of_bsn_virtual_port_remove_reply_t *obj, int value);
extern int of_bsn_virtual_port_remove_reply_OF_VERSION_1_4_populate_scalars(
    of_bsn_virtual_port_remove_reply_t *obj, int value);
extern int of_bsn_virtual_port_remove_reply_OF_VERSION_1_4_check_scalars(
    of_bsn_virtual_port_remove_reply_t *obj, int value);

extern int of_bsn_virtual_port_remove_request_OF_VERSION_1_4_populate(
    of_bsn_virtual_port_remove_request_t *obj, int value);
extern int of_bsn_virtual_port_remove_request_OF_VERSION_1_4_check(
    of_bsn_virtual_port_remove_request_t *obj, int value);
extern int of_bsn_virtual_port_remove_request_OF_VERSION_1_4_populate_scalars(
    of_bsn_virtual_port_remove_request_t *obj, int value);
extern int of_bsn_virtual_port_remove_request_OF_VERSION_1_4_check_scalars(
    of_bsn_virtual_port_remove_request_t *obj, int value);

extern int of_bsn_vlan_counter_clear_OF_VERSION_1_4_populate(
    of_bsn_vlan_counter_clear_t *obj, int value);
extern int of_bsn_vlan_counter_clear_OF_VERSION_1_4_check(
    of_bsn_vlan_counter_clear_t *obj, int value);
extern int of_bsn_vlan_counter_clear_OF_VERSION_1_4_populate_scalars(
    of_bsn_vlan_counter_clear_t *obj, int value);
extern int of_bsn_vlan_counter_clear_OF_VERSION_1_4_check_scalars(
    of_bsn_vlan_counter_clear_t *obj, int value);

extern int of_bsn_vlan_counter_stats_reply_OF_VERSION_1_4_populate(
    of_bsn_vlan_counter_stats_reply_t *obj, int value);
extern int of_bsn_vlan_counter_stats_reply_OF_VERSION_1_4_check(
    of_bsn_vlan_counter_stats_reply_t *obj, int value);
extern int of_bsn_vlan_counter_stats_reply_OF_VERSION_1_4_populate_scalars(
    of_bsn_vlan_counter_stats_reply_t *obj, int value);
extern int of_bsn_vlan_counter_stats_reply_OF_VERSION_1_4_check_scalars(
    of_bsn_vlan_counter_stats_reply_t *obj, int value);

extern int of_bsn_vlan_counter_stats_request_OF_VERSION_1_4_populate(
    of_bsn_vlan_counter_stats_request_t *obj, int value);
extern int of_bsn_vlan_counter_stats_request_OF_VERSION_1_4_check(
    of_bsn_vlan_counter_stats_request_t *obj, int value);
extern int of_bsn_vlan_counter_stats_request_OF_VERSION_1_4_populate_scalars(
    of_bsn_vlan_counter_stats_request_t *obj, int value);
extern int of_bsn_vlan_counter_stats_request_OF_VERSION_1_4_check_scalars(
    of_bsn_vlan_counter_stats_request_t *obj, int value);

extern int of_bsn_vrf_counter_stats_reply_OF_VERSION_1_4_populate(
    of_bsn_vrf_counter_stats_reply_t *obj, int value);
extern int of_bsn_vrf_counter_stats_reply_OF_VERSION_1_4_check(
    of_bsn_vrf_counter_stats_reply_t *obj, int value);
extern int of_bsn_vrf_counter_stats_reply_OF_VERSION_1_4_populate_scalars(
    of_bsn_vrf_counter_stats_reply_t *obj, int value);
extern int of_bsn_vrf_counter_stats_reply_OF_VERSION_1_4_check_scalars(
    of_bsn_vrf_counter_stats_reply_t *obj, int value);

extern int of_bsn_vrf_counter_stats_request_OF_VERSION_1_4_populate(
    of_bsn_vrf_counter_stats_request_t *obj, int value);
extern int of_bsn_vrf_counter_stats_request_OF_VERSION_1_4_check(
    of_bsn_vrf_counter_stats_request_t *obj, int value);
extern int of_bsn_vrf_counter_stats_request_OF_VERSION_1_4_populate_scalars(
    of_bsn_vrf_counter_stats_request_t *obj, int value);
extern int of_bsn_vrf_counter_stats_request_OF_VERSION_1_4_check_scalars(
    of_bsn_vrf_counter_stats_request_t *obj, int value);

extern int of_bundle_add_msg_OF_VERSION_1_4_populate(
    of_bundle_add_msg_t *obj, int value);
extern int of_bundle_add_msg_OF_VERSION_1_4_check(
    of_bundle_add_msg_t *obj, int value);
extern int of_bundle_add_msg_OF_VERSION_1_4_populate_scalars(
    of_bundle_add_msg_t *obj, int value);
extern int of_bundle_add_msg_OF_VERSION_1_4_check_scalars(
    of_bundle_add_msg_t *obj, int value);

extern int of_bundle_ctrl_msg_OF_VERSION_1_4_populate(
    of_bundle_ctrl_msg_t *obj, int value);
extern int of_bundle_ctrl_msg_OF_VERSION_1_4_check(
    of_bundle_ctrl_msg_t *obj, int value);
extern int of_bundle_ctrl_msg_OF_VERSION_1_4_populate_scalars(
    of_bundle_ctrl_msg_t *obj, int value);
extern int of_bundle_ctrl_msg_OF_VERSION_1_4_check_scalars(
    of_bundle_ctrl_msg_t *obj, int value);

extern int of_bundle_failed_error_msg_OF_VERSION_1_4_populate(
    of_bundle_failed_error_msg_t *obj, int value);
extern int of_bundle_failed_error_msg_OF_VERSION_1_4_check(
    of_bundle_failed_error_msg_t *obj, int value);
extern int of_bundle_failed_error_msg_OF_VERSION_1_4_populate_scalars(
    of_bundle_failed_error_msg_t *obj, int value);
extern int of_bundle_failed_error_msg_OF_VERSION_1_4_check_scalars(
    of_bundle_failed_error_msg_t *obj, int value);

extern int of_desc_stats_reply_OF_VERSION_1_4_populate(
    of_desc_stats_reply_t *obj, int value);
extern int of_desc_stats_reply_OF_VERSION_1_4_check(
    of_desc_stats_reply_t *obj, int value);
extern int of_desc_stats_reply_OF_VERSION_1_4_populate_scalars(
    of_desc_stats_reply_t *obj, int value);
extern int of_desc_stats_reply_OF_VERSION_1_4_check_scalars(
    of_desc_stats_reply_t *obj, int value);

extern int of_desc_stats_request_OF_VERSION_1_4_populate(
    of_desc_stats_request_t *obj, int value);
extern int of_desc_stats_request_OF_VERSION_1_4_check(
    of_desc_stats_request_t *obj, int value);
extern int of_desc_stats_request_OF_VERSION_1_4_populate_scalars(
    of_desc_stats_request_t *obj, int value);
extern int of_desc_stats_request_OF_VERSION_1_4_check_scalars(
    of_desc_stats_request_t *obj, int value);

extern int of_echo_reply_OF_VERSION_1_4_populate(
    of_echo_reply_t *obj, int value);
extern int of_echo_reply_OF_VERSION_1_4_check(
    of_echo_reply_t *obj, int value);
extern int of_echo_reply_OF_VERSION_1_4_populate_scalars(
    of_echo_reply_t *obj, int value);
extern int of_echo_reply_OF_VERSION_1_4_check_scalars(
    of_echo_reply_t *obj, int value);

extern int of_echo_request_OF_VERSION_1_4_populate(
    of_echo_request_t *obj, int value);
extern int of_echo_request_OF_VERSION_1_4_check(
    of_echo_request_t *obj, int value);
extern int of_echo_request_OF_VERSION_1_4_populate_scalars(
    of_echo_request_t *obj, int value);
extern int of_echo_request_OF_VERSION_1_4_check_scalars(
    of_echo_request_t *obj, int value);

extern int of_features_reply_OF_VERSION_1_4_populate(
    of_features_reply_t *obj, int value);
extern int of_features_reply_OF_VERSION_1_4_check(
    of_features_reply_t *obj, int value);
extern int of_features_reply_OF_VERSION_1_4_populate_scalars(
    of_features_reply_t *obj, int value);
extern int of_features_reply_OF_VERSION_1_4_check_scalars(
    of_features_reply_t *obj, int value);

extern int of_features_request_OF_VERSION_1_4_populate(
    of_features_request_t *obj, int value);
extern int of_features_request_OF_VERSION_1_4_check(
    of_features_request_t *obj, int value);
extern int of_features_request_OF_VERSION_1_4_populate_scalars(
    of_features_request_t *obj, int value);
extern int of_features_request_OF_VERSION_1_4_check_scalars(
    of_features_request_t *obj, int value);

extern int of_flow_add_OF_VERSION_1_4_populate(
    of_flow_add_t *obj, int value);
extern int of_flow_add_OF_VERSION_1_4_check(
    of_flow_add_t *obj, int value);
extern int of_flow_add_OF_VERSION_1_4_populate_scalars(
    of_flow_add_t *obj, int value);
extern int of_flow_add_OF_VERSION_1_4_check_scalars(
    of_flow_add_t *obj, int value);

extern int of_flow_delete_OF_VERSION_1_4_populate(
    of_flow_delete_t *obj, int value);
extern int of_flow_delete_OF_VERSION_1_4_check(
    of_flow_delete_t *obj, int value);
extern int of_flow_delete_OF_VERSION_1_4_populate_scalars(
    of_flow_delete_t *obj, int value);
extern int of_flow_delete_OF_VERSION_1_4_check_scalars(
    of_flow_delete_t *obj, int value);

extern int of_flow_delete_strict_OF_VERSION_1_4_populate(
    of_flow_delete_strict_t *obj, int value);
extern int of_flow_delete_strict_OF_VERSION_1_4_check(
    of_flow_delete_strict_t *obj, int value);
extern int of_flow_delete_strict_OF_VERSION_1_4_populate_scalars(
    of_flow_delete_strict_t *obj, int value);
extern int of_flow_delete_strict_OF_VERSION_1_4_check_scalars(
    of_flow_delete_strict_t *obj, int value);

extern int of_flow_mod_failed_error_msg_OF_VERSION_1_4_populate(
    of_flow_mod_failed_error_msg_t *obj, int value);
extern int of_flow_mod_failed_error_msg_OF_VERSION_1_4_check(
    of_flow_mod_failed_error_msg_t *obj, int value);
extern int of_flow_mod_failed_error_msg_OF_VERSION_1_4_populate_scalars(
    of_flow_mod_failed_error_msg_t *obj, int value);
extern int of_flow_mod_failed_error_msg_OF_VERSION_1_4_check_scalars(
    of_flow_mod_failed_error_msg_t *obj, int value);

extern int of_flow_modify_OF_VERSION_1_4_populate(
    of_flow_modify_t *obj, int value);
extern int of_flow_modify_OF_VERSION_1_4_check(
    of_flow_modify_t *obj, int value);
extern int of_flow_modify_OF_VERSION_1_4_populate_scalars(
    of_flow_modify_t *obj, int value);
extern int of_flow_modify_OF_VERSION_1_4_check_scalars(
    of_flow_modify_t *obj, int value);

extern int of_flow_modify_strict_OF_VERSION_1_4_populate(
    of_flow_modify_strict_t *obj, int value);
extern int of_flow_modify_strict_OF_VERSION_1_4_check(
    of_flow_modify_strict_t *obj, int value);
extern int of_flow_modify_strict_OF_VERSION_1_4_populate_scalars(
    of_flow_modify_strict_t *obj, int value);
extern int of_flow_modify_strict_OF_VERSION_1_4_check_scalars(
    of_flow_modify_strict_t *obj, int value);

extern int of_flow_monitor_failed_error_msg_OF_VERSION_1_4_populate(
    of_flow_monitor_failed_error_msg_t *obj, int value);
extern int of_flow_monitor_failed_error_msg_OF_VERSION_1_4_check(
    of_flow_monitor_failed_error_msg_t *obj, int value);
extern int of_flow_monitor_failed_error_msg_OF_VERSION_1_4_populate_scalars(
    of_flow_monitor_failed_error_msg_t *obj, int value);
extern int of_flow_monitor_failed_error_msg_OF_VERSION_1_4_check_scalars(
    of_flow_monitor_failed_error_msg_t *obj, int value);

extern int of_flow_removed_OF_VERSION_1_4_populate(
    of_flow_removed_t *obj, int value);
extern int of_flow_removed_OF_VERSION_1_4_check(
    of_flow_removed_t *obj, int value);
extern int of_flow_removed_OF_VERSION_1_4_populate_scalars(
    of_flow_removed_t *obj, int value);
extern int of_flow_removed_OF_VERSION_1_4_check_scalars(
    of_flow_removed_t *obj, int value);

extern int of_flow_stats_reply_OF_VERSION_1_4_populate(
    of_flow_stats_reply_t *obj, int value);
extern int of_flow_stats_reply_OF_VERSION_1_4_check(
    of_flow_stats_reply_t *obj, int value);
extern int of_flow_stats_reply_OF_VERSION_1_4_populate_scalars(
    of_flow_stats_reply_t *obj, int value);
extern int of_flow_stats_reply_OF_VERSION_1_4_check_scalars(
    of_flow_stats_reply_t *obj, int value);

extern int of_flow_stats_request_OF_VERSION_1_4_populate(
    of_flow_stats_request_t *obj, int value);
extern int of_flow_stats_request_OF_VERSION_1_4_check(
    of_flow_stats_request_t *obj, int value);
extern int of_flow_stats_request_OF_VERSION_1_4_populate_scalars(
    of_flow_stats_request_t *obj, int value);
extern int of_flow_stats_request_OF_VERSION_1_4_check_scalars(
    of_flow_stats_request_t *obj, int value);

extern int of_get_config_reply_OF_VERSION_1_4_populate(
    of_get_config_reply_t *obj, int value);
extern int of_get_config_reply_OF_VERSION_1_4_check(
    of_get_config_reply_t *obj, int value);
extern int of_get_config_reply_OF_VERSION_1_4_populate_scalars(
    of_get_config_reply_t *obj, int value);
extern int of_get_config_reply_OF_VERSION_1_4_check_scalars(
    of_get_config_reply_t *obj, int value);

extern int of_get_config_request_OF_VERSION_1_4_populate(
    of_get_config_request_t *obj, int value);
extern int of_get_config_request_OF_VERSION_1_4_check(
    of_get_config_request_t *obj, int value);
extern int of_get_config_request_OF_VERSION_1_4_populate_scalars(
    of_get_config_request_t *obj, int value);
extern int of_get_config_request_OF_VERSION_1_4_check_scalars(
    of_get_config_request_t *obj, int value);

extern int of_group_add_OF_VERSION_1_4_populate(
    of_group_add_t *obj, int value);
extern int of_group_add_OF_VERSION_1_4_check(
    of_group_add_t *obj, int value);
extern int of_group_add_OF_VERSION_1_4_populate_scalars(
    of_group_add_t *obj, int value);
extern int of_group_add_OF_VERSION_1_4_check_scalars(
    of_group_add_t *obj, int value);

extern int of_group_delete_OF_VERSION_1_4_populate(
    of_group_delete_t *obj, int value);
extern int of_group_delete_OF_VERSION_1_4_check(
    of_group_delete_t *obj, int value);
extern int of_group_delete_OF_VERSION_1_4_populate_scalars(
    of_group_delete_t *obj, int value);
extern int of_group_delete_OF_VERSION_1_4_check_scalars(
    of_group_delete_t *obj, int value);

extern int of_group_desc_stats_reply_OF_VERSION_1_4_populate(
    of_group_desc_stats_reply_t *obj, int value);
extern int of_group_desc_stats_reply_OF_VERSION_1_4_check(
    of_group_desc_stats_reply_t *obj, int value);
extern int of_group_desc_stats_reply_OF_VERSION_1_4_populate_scalars(
    of_group_desc_stats_reply_t *obj, int value);
extern int of_group_desc_stats_reply_OF_VERSION_1_4_check_scalars(
    of_group_desc_stats_reply_t *obj, int value);

extern int of_group_desc_stats_request_OF_VERSION_1_4_populate(
    of_group_desc_stats_request_t *obj, int value);
extern int of_group_desc_stats_request_OF_VERSION_1_4_check(
    of_group_desc_stats_request_t *obj, int value);
extern int of_group_desc_stats_request_OF_VERSION_1_4_populate_scalars(
    of_group_desc_stats_request_t *obj, int value);
extern int of_group_desc_stats_request_OF_VERSION_1_4_check_scalars(
    of_group_desc_stats_request_t *obj, int value);

extern int of_group_features_stats_reply_OF_VERSION_1_4_populate(
    of_group_features_stats_reply_t *obj, int value);
extern int of_group_features_stats_reply_OF_VERSION_1_4_check(
    of_group_features_stats_reply_t *obj, int value);
extern int of_group_features_stats_reply_OF_VERSION_1_4_populate_scalars(
    of_group_features_stats_reply_t *obj, int value);
extern int of_group_features_stats_reply_OF_VERSION_1_4_check_scalars(
    of_group_features_stats_reply_t *obj, int value);

extern int of_group_features_stats_request_OF_VERSION_1_4_populate(
    of_group_features_stats_request_t *obj, int value);
extern int of_group_features_stats_request_OF_VERSION_1_4_check(
    of_group_features_stats_request_t *obj, int value);
extern int of_group_features_stats_request_OF_VERSION_1_4_populate_scalars(
    of_group_features_stats_request_t *obj, int value);
extern int of_group_features_stats_request_OF_VERSION_1_4_check_scalars(
    of_group_features_stats_request_t *obj, int value);

extern int of_group_mod_failed_error_msg_OF_VERSION_1_4_populate(
    of_group_mod_failed_error_msg_t *obj, int value);
extern int of_group_mod_failed_error_msg_OF_VERSION_1_4_check(
    of_group_mod_failed_error_msg_t *obj, int value);
extern int of_group_mod_failed_error_msg_OF_VERSION_1_4_populate_scalars(
    of_group_mod_failed_error_msg_t *obj, int value);
extern int of_group_mod_failed_error_msg_OF_VERSION_1_4_check_scalars(
    of_group_mod_failed_error_msg_t *obj, int value);

extern int of_group_modify_OF_VERSION_1_4_populate(
    of_group_modify_t *obj, int value);
extern int of_group_modify_OF_VERSION_1_4_check(
    of_group_modify_t *obj, int value);
extern int of_group_modify_OF_VERSION_1_4_populate_scalars(
    of_group_modify_t *obj, int value);
extern int of_group_modify_OF_VERSION_1_4_check_scalars(
    of_group_modify_t *obj, int value);

extern int of_group_stats_reply_OF_VERSION_1_4_populate(
    of_group_stats_reply_t *obj, int value);
extern int of_group_stats_reply_OF_VERSION_1_4_check(
    of_group_stats_reply_t *obj, int value);
extern int of_group_stats_reply_OF_VERSION_1_4_populate_scalars(
    of_group_stats_reply_t *obj, int value);
extern int of_group_stats_reply_OF_VERSION_1_4_check_scalars(
    of_group_stats_reply_t *obj, int value);

extern int of_group_stats_request_OF_VERSION_1_4_populate(
    of_group_stats_request_t *obj, int value);
extern int of_group_stats_request_OF_VERSION_1_4_check(
    of_group_stats_request_t *obj, int value);
extern int of_group_stats_request_OF_VERSION_1_4_populate_scalars(
    of_group_stats_request_t *obj, int value);
extern int of_group_stats_request_OF_VERSION_1_4_check_scalars(
    of_group_stats_request_t *obj, int value);

extern int of_hello_OF_VERSION_1_4_populate(
    of_hello_t *obj, int value);
extern int of_hello_OF_VERSION_1_4_check(
    of_hello_t *obj, int value);
extern int of_hello_OF_VERSION_1_4_populate_scalars(
    of_hello_t *obj, int value);
extern int of_hello_OF_VERSION_1_4_check_scalars(
    of_hello_t *obj, int value);

extern int of_hello_failed_error_msg_OF_VERSION_1_4_populate(
    of_hello_failed_error_msg_t *obj, int value);
extern int of_hello_failed_error_msg_OF_VERSION_1_4_check(
    of_hello_failed_error_msg_t *obj, int value);
extern int of_hello_failed_error_msg_OF_VERSION_1_4_populate_scalars(
    of_hello_failed_error_msg_t *obj, int value);
extern int of_hello_failed_error_msg_OF_VERSION_1_4_check_scalars(
    of_hello_failed_error_msg_t *obj, int value);

extern int of_meter_config_stats_reply_OF_VERSION_1_4_populate(
    of_meter_config_stats_reply_t *obj, int value);
extern int of_meter_config_stats_reply_OF_VERSION_1_4_check(
    of_meter_config_stats_reply_t *obj, int value);
extern int of_meter_config_stats_reply_OF_VERSION_1_4_populate_scalars(
    of_meter_config_stats_reply_t *obj, int value);
extern int of_meter_config_stats_reply_OF_VERSION_1_4_check_scalars(
    of_meter_config_stats_reply_t *obj, int value);

extern int of_meter_config_stats_request_OF_VERSION_1_4_populate(
    of_meter_config_stats_request_t *obj, int value);
extern int of_meter_config_stats_request_OF_VERSION_1_4_check(
    of_meter_config_stats_request_t *obj, int value);
extern int of_meter_config_stats_request_OF_VERSION_1_4_populate_scalars(
    of_meter_config_stats_request_t *obj, int value);
extern int of_meter_config_stats_request_OF_VERSION_1_4_check_scalars(
    of_meter_config_stats_request_t *obj, int value);

extern int of_meter_features_stats_reply_OF_VERSION_1_4_populate(
    of_meter_features_stats_reply_t *obj, int value);
extern int of_meter_features_stats_reply_OF_VERSION_1_4_check(
    of_meter_features_stats_reply_t *obj, int value);
extern int of_meter_features_stats_reply_OF_VERSION_1_4_populate_scalars(
    of_meter_features_stats_reply_t *obj, int value);
extern int of_meter_features_stats_reply_OF_VERSION_1_4_check_scalars(
    of_meter_features_stats_reply_t *obj, int value);

extern int of_meter_features_stats_request_OF_VERSION_1_4_populate(
    of_meter_features_stats_request_t *obj, int value);
extern int of_meter_features_stats_request_OF_VERSION_1_4_check(
    of_meter_features_stats_request_t *obj, int value);
extern int of_meter_features_stats_request_OF_VERSION_1_4_populate_scalars(
    of_meter_features_stats_request_t *obj, int value);
extern int of_meter_features_stats_request_OF_VERSION_1_4_check_scalars(
    of_meter_features_stats_request_t *obj, int value);

extern int of_meter_mod_OF_VERSION_1_4_populate(
    of_meter_mod_t *obj, int value);
extern int of_meter_mod_OF_VERSION_1_4_check(
    of_meter_mod_t *obj, int value);
extern int of_meter_mod_OF_VERSION_1_4_populate_scalars(
    of_meter_mod_t *obj, int value);
extern int of_meter_mod_OF_VERSION_1_4_check_scalars(
    of_meter_mod_t *obj, int value);

extern int of_meter_mod_failed_error_msg_OF_VERSION_1_4_populate(
    of_meter_mod_failed_error_msg_t *obj, int value);
extern int of_meter_mod_failed_error_msg_OF_VERSION_1_4_check(
    of_meter_mod_failed_error_msg_t *obj, int value);
extern int of_meter_mod_failed_error_msg_OF_VERSION_1_4_populate_scalars(
    of_meter_mod_failed_error_msg_t *obj, int value);
extern int of_meter_mod_failed_error_msg_OF_VERSION_1_4_check_scalars(
    of_meter_mod_failed_error_msg_t *obj, int value);

extern int of_meter_stats_reply_OF_VERSION_1_4_populate(
    of_meter_stats_reply_t *obj, int value);
extern int of_meter_stats_reply_OF_VERSION_1_4_check(
    of_meter_stats_reply_t *obj, int value);
extern int of_meter_stats_reply_OF_VERSION_1_4_populate_scalars(
    of_meter_stats_reply_t *obj, int value);
extern int of_meter_stats_reply_OF_VERSION_1_4_check_scalars(
    of_meter_stats_reply_t *obj, int value);

extern int of_meter_stats_request_OF_VERSION_1_4_populate(
    of_meter_stats_request_t *obj, int value);
extern int of_meter_stats_request_OF_VERSION_1_4_check(
    of_meter_stats_request_t *obj, int value);
extern int of_meter_stats_request_OF_VERSION_1_4_populate_scalars(
    of_meter_stats_request_t *obj, int value);
extern int of_meter_stats_request_OF_VERSION_1_4_check_scalars(
    of_meter_stats_request_t *obj, int value);

extern int of_packet_in_OF_VERSION_1_4_populate(
    of_packet_in_t *obj, int value);
extern int of_packet_in_OF_VERSION_1_4_check(
    of_packet_in_t *obj, int value);
extern int of_packet_in_OF_VERSION_1_4_populate_scalars(
    of_packet_in_t *obj, int value);
extern int of_packet_in_OF_VERSION_1_4_check_scalars(
    of_packet_in_t *obj, int value);

extern int of_packet_out_OF_VERSION_1_4_populate(
    of_packet_out_t *obj, int value);
extern int of_packet_out_OF_VERSION_1_4_check(
    of_packet_out_t *obj, int value);
extern int of_packet_out_OF_VERSION_1_4_populate_scalars(
    of_packet_out_t *obj, int value);
extern int of_packet_out_OF_VERSION_1_4_check_scalars(
    of_packet_out_t *obj, int value);

extern int of_port_desc_stats_reply_OF_VERSION_1_4_populate(
    of_port_desc_stats_reply_t *obj, int value);
extern int of_port_desc_stats_reply_OF_VERSION_1_4_check(
    of_port_desc_stats_reply_t *obj, int value);
extern int of_port_desc_stats_reply_OF_VERSION_1_4_populate_scalars(
    of_port_desc_stats_reply_t *obj, int value);
extern int of_port_desc_stats_reply_OF_VERSION_1_4_check_scalars(
    of_port_desc_stats_reply_t *obj, int value);

extern int of_port_desc_stats_request_OF_VERSION_1_4_populate(
    of_port_desc_stats_request_t *obj, int value);
extern int of_port_desc_stats_request_OF_VERSION_1_4_check(
    of_port_desc_stats_request_t *obj, int value);
extern int of_port_desc_stats_request_OF_VERSION_1_4_populate_scalars(
    of_port_desc_stats_request_t *obj, int value);
extern int of_port_desc_stats_request_OF_VERSION_1_4_check_scalars(
    of_port_desc_stats_request_t *obj, int value);

extern int of_port_mod_OF_VERSION_1_4_populate(
    of_port_mod_t *obj, int value);
extern int of_port_mod_OF_VERSION_1_4_check(
    of_port_mod_t *obj, int value);
extern int of_port_mod_OF_VERSION_1_4_populate_scalars(
    of_port_mod_t *obj, int value);
extern int of_port_mod_OF_VERSION_1_4_check_scalars(
    of_port_mod_t *obj, int value);

extern int of_port_mod_failed_error_msg_OF_VERSION_1_4_populate(
    of_port_mod_failed_error_msg_t *obj, int value);
extern int of_port_mod_failed_error_msg_OF_VERSION_1_4_check(
    of_port_mod_failed_error_msg_t *obj, int value);
extern int of_port_mod_failed_error_msg_OF_VERSION_1_4_populate_scalars(
    of_port_mod_failed_error_msg_t *obj, int value);
extern int of_port_mod_failed_error_msg_OF_VERSION_1_4_check_scalars(
    of_port_mod_failed_error_msg_t *obj, int value);

extern int of_port_stats_reply_OF_VERSION_1_4_populate(
    of_port_stats_reply_t *obj, int value);
extern int of_port_stats_reply_OF_VERSION_1_4_check(
    of_port_stats_reply_t *obj, int value);
extern int of_port_stats_reply_OF_VERSION_1_4_populate_scalars(
    of_port_stats_reply_t *obj, int value);
extern int of_port_stats_reply_OF_VERSION_1_4_check_scalars(
    of_port_stats_reply_t *obj, int value);

extern int of_port_stats_request_OF_VERSION_1_4_populate(
    of_port_stats_request_t *obj, int value);
extern int of_port_stats_request_OF_VERSION_1_4_check(
    of_port_stats_request_t *obj, int value);
extern int of_port_stats_request_OF_VERSION_1_4_populate_scalars(
    of_port_stats_request_t *obj, int value);
extern int of_port_stats_request_OF_VERSION_1_4_check_scalars(
    of_port_stats_request_t *obj, int value);

extern int of_port_status_OF_VERSION_1_4_populate(
    of_port_status_t *obj, int value);
extern int of_port_status_OF_VERSION_1_4_check(
    of_port_status_t *obj, int value);
extern int of_port_status_OF_VERSION_1_4_populate_scalars(
    of_port_status_t *obj, int value);
extern int of_port_status_OF_VERSION_1_4_check_scalars(
    of_port_status_t *obj, int value);

extern int of_queue_desc_stats_reply_OF_VERSION_1_4_populate(
    of_queue_desc_stats_reply_t *obj, int value);
extern int of_queue_desc_stats_reply_OF_VERSION_1_4_check(
    of_queue_desc_stats_reply_t *obj, int value);
extern int of_queue_desc_stats_reply_OF_VERSION_1_4_populate_scalars(
    of_queue_desc_stats_reply_t *obj, int value);
extern int of_queue_desc_stats_reply_OF_VERSION_1_4_check_scalars(
    of_queue_desc_stats_reply_t *obj, int value);

extern int of_queue_desc_stats_request_OF_VERSION_1_4_populate(
    of_queue_desc_stats_request_t *obj, int value);
extern int of_queue_desc_stats_request_OF_VERSION_1_4_check(
    of_queue_desc_stats_request_t *obj, int value);
extern int of_queue_desc_stats_request_OF_VERSION_1_4_populate_scalars(
    of_queue_desc_stats_request_t *obj, int value);
extern int of_queue_desc_stats_request_OF_VERSION_1_4_check_scalars(
    of_queue_desc_stats_request_t *obj, int value);

extern int of_queue_op_failed_error_msg_OF_VERSION_1_4_populate(
    of_queue_op_failed_error_msg_t *obj, int value);
extern int of_queue_op_failed_error_msg_OF_VERSION_1_4_check(
    of_queue_op_failed_error_msg_t *obj, int value);
extern int of_queue_op_failed_error_msg_OF_VERSION_1_4_populate_scalars(
    of_queue_op_failed_error_msg_t *obj, int value);
extern int of_queue_op_failed_error_msg_OF_VERSION_1_4_check_scalars(
    of_queue_op_failed_error_msg_t *obj, int value);

extern int of_queue_stats_reply_OF_VERSION_1_4_populate(
    of_queue_stats_reply_t *obj, int value);
extern int of_queue_stats_reply_OF_VERSION_1_4_check(
    of_queue_stats_reply_t *obj, int value);
extern int of_queue_stats_reply_OF_VERSION_1_4_populate_scalars(
    of_queue_stats_reply_t *obj, int value);
extern int of_queue_stats_reply_OF_VERSION_1_4_check_scalars(
    of_queue_stats_reply_t *obj, int value);

extern int of_queue_stats_request_OF_VERSION_1_4_populate(
    of_queue_stats_request_t *obj, int value);
extern int of_queue_stats_request_OF_VERSION_1_4_check(
    of_queue_stats_request_t *obj, int value);
extern int of_queue_stats_request_OF_VERSION_1_4_populate_scalars(
    of_queue_stats_request_t *obj, int value);
extern int of_queue_stats_request_OF_VERSION_1_4_check_scalars(
    of_queue_stats_request_t *obj, int value);

extern int of_requestforward_OF_VERSION_1_4_populate(
    of_requestforward_t *obj, int value);
extern int of_requestforward_OF_VERSION_1_4_check(
    of_requestforward_t *obj, int value);
extern int of_requestforward_OF_VERSION_1_4_populate_scalars(
    of_requestforward_t *obj, int value);
extern int of_requestforward_OF_VERSION_1_4_check_scalars(
    of_requestforward_t *obj, int value);

extern int of_role_reply_OF_VERSION_1_4_populate(
    of_role_reply_t *obj, int value);
extern int of_role_reply_OF_VERSION_1_4_check(
    of_role_reply_t *obj, int value);
extern int of_role_reply_OF_VERSION_1_4_populate_scalars(
    of_role_reply_t *obj, int value);
extern int of_role_reply_OF_VERSION_1_4_check_scalars(
    of_role_reply_t *obj, int value);

extern int of_role_request_OF_VERSION_1_4_populate(
    of_role_request_t *obj, int value);
extern int of_role_request_OF_VERSION_1_4_check(
    of_role_request_t *obj, int value);
extern int of_role_request_OF_VERSION_1_4_populate_scalars(
    of_role_request_t *obj, int value);
extern int of_role_request_OF_VERSION_1_4_check_scalars(
    of_role_request_t *obj, int value);

extern int of_role_request_failed_error_msg_OF_VERSION_1_4_populate(
    of_role_request_failed_error_msg_t *obj, int value);
extern int of_role_request_failed_error_msg_OF_VERSION_1_4_check(
    of_role_request_failed_error_msg_t *obj, int value);
extern int of_role_request_failed_error_msg_OF_VERSION_1_4_populate_scalars(
    of_role_request_failed_error_msg_t *obj, int value);
extern int of_role_request_failed_error_msg_OF_VERSION_1_4_check_scalars(
    of_role_request_failed_error_msg_t *obj, int value);

extern int of_role_status_OF_VERSION_1_4_populate(
    of_role_status_t *obj, int value);
extern int of_role_status_OF_VERSION_1_4_check(
    of_role_status_t *obj, int value);
extern int of_role_status_OF_VERSION_1_4_populate_scalars(
    of_role_status_t *obj, int value);
extern int of_role_status_OF_VERSION_1_4_check_scalars(
    of_role_status_t *obj, int value);

extern int of_set_config_OF_VERSION_1_4_populate(
    of_set_config_t *obj, int value);
extern int of_set_config_OF_VERSION_1_4_check(
    of_set_config_t *obj, int value);
extern int of_set_config_OF_VERSION_1_4_populate_scalars(
    of_set_config_t *obj, int value);
extern int of_set_config_OF_VERSION_1_4_check_scalars(
    of_set_config_t *obj, int value);

extern int of_switch_config_failed_error_msg_OF_VERSION_1_4_populate(
    of_switch_config_failed_error_msg_t *obj, int value);
extern int of_switch_config_failed_error_msg_OF_VERSION_1_4_check(
    of_switch_config_failed_error_msg_t *obj, int value);
extern int of_switch_config_failed_error_msg_OF_VERSION_1_4_populate_scalars(
    of_switch_config_failed_error_msg_t *obj, int value);
extern int of_switch_config_failed_error_msg_OF_VERSION_1_4_check_scalars(
    of_switch_config_failed_error_msg_t *obj, int value);

extern int of_table_desc_stats_reply_OF_VERSION_1_4_populate(
    of_table_desc_stats_reply_t *obj, int value);
extern int of_table_desc_stats_reply_OF_VERSION_1_4_check(
    of_table_desc_stats_reply_t *obj, int value);
extern int of_table_desc_stats_reply_OF_VERSION_1_4_populate_scalars(
    of_table_desc_stats_reply_t *obj, int value);
extern int of_table_desc_stats_reply_OF_VERSION_1_4_check_scalars(
    of_table_desc_stats_reply_t *obj, int value);

extern int of_table_desc_stats_request_OF_VERSION_1_4_populate(
    of_table_desc_stats_request_t *obj, int value);
extern int of_table_desc_stats_request_OF_VERSION_1_4_check(
    of_table_desc_stats_request_t *obj, int value);
extern int of_table_desc_stats_request_OF_VERSION_1_4_populate_scalars(
    of_table_desc_stats_request_t *obj, int value);
extern int of_table_desc_stats_request_OF_VERSION_1_4_check_scalars(
    of_table_desc_stats_request_t *obj, int value);

extern int of_table_features_failed_error_msg_OF_VERSION_1_4_populate(
    of_table_features_failed_error_msg_t *obj, int value);
extern int of_table_features_failed_error_msg_OF_VERSION_1_4_check(
    of_table_features_failed_error_msg_t *obj, int value);
extern int of_table_features_failed_error_msg_OF_VERSION_1_4_populate_scalars(
    of_table_features_failed_error_msg_t *obj, int value);
extern int of_table_features_failed_error_msg_OF_VERSION_1_4_check_scalars(
    of_table_features_failed_error_msg_t *obj, int value);

extern int of_table_features_stats_reply_OF_VERSION_1_4_populate(
    of_table_features_stats_reply_t *obj, int value);
extern int of_table_features_stats_reply_OF_VERSION_1_4_check(
    of_table_features_stats_reply_t *obj, int value);
extern int of_table_features_stats_reply_OF_VERSION_1_4_populate_scalars(
    of_table_features_stats_reply_t *obj, int value);
extern int of_table_features_stats_reply_OF_VERSION_1_4_check_scalars(
    of_table_features_stats_reply_t *obj, int value);

extern int of_table_features_stats_request_OF_VERSION_1_4_populate(
    of_table_features_stats_request_t *obj, int value);
extern int of_table_features_stats_request_OF_VERSION_1_4_check(
    of_table_features_stats_request_t *obj, int value);
extern int of_table_features_stats_request_OF_VERSION_1_4_populate_scalars(
    of_table_features_stats_request_t *obj, int value);
extern int of_table_features_stats_request_OF_VERSION_1_4_check_scalars(
    of_table_features_stats_request_t *obj, int value);

extern int of_table_mod_OF_VERSION_1_4_populate(
    of_table_mod_t *obj, int value);
extern int of_table_mod_OF_VERSION_1_4_check(
    of_table_mod_t *obj, int value);
extern int of_table_mod_OF_VERSION_1_4_populate_scalars(
    of_table_mod_t *obj, int value);
extern int of_table_mod_OF_VERSION_1_4_check_scalars(
    of_table_mod_t *obj, int value);

extern int of_table_mod_failed_error_msg_OF_VERSION_1_4_populate(
    of_table_mod_failed_error_msg_t *obj, int value);
extern int of_table_mod_failed_error_msg_OF_VERSION_1_4_check(
    of_table_mod_failed_error_msg_t *obj, int value);
extern int of_table_mod_failed_error_msg_OF_VERSION_1_4_populate_scalars(
    of_table_mod_failed_error_msg_t *obj, int value);
extern int of_table_mod_failed_error_msg_OF_VERSION_1_4_check_scalars(
    of_table_mod_failed_error_msg_t *obj, int value);

extern int of_table_stats_reply_OF_VERSION_1_4_populate(
    of_table_stats_reply_t *obj, int value);
extern int of_table_stats_reply_OF_VERSION_1_4_check(
    of_table_stats_reply_t *obj, int value);
extern int of_table_stats_reply_OF_VERSION_1_4_populate_scalars(
    of_table_stats_reply_t *obj, int value);
extern int of_table_stats_reply_OF_VERSION_1_4_check_scalars(
    of_table_stats_reply_t *obj, int value);

extern int of_table_stats_request_OF_VERSION_1_4_populate(
    of_table_stats_request_t *obj, int value);
extern int of_table_stats_request_OF_VERSION_1_4_check(
    of_table_stats_request_t *obj, int value);
extern int of_table_stats_request_OF_VERSION_1_4_populate_scalars(
    of_table_stats_request_t *obj, int value);
extern int of_table_stats_request_OF_VERSION_1_4_check_scalars(
    of_table_stats_request_t *obj, int value);

extern int of_table_status_OF_VERSION_1_4_populate(
    of_table_status_t *obj, int value);
extern int of_table_status_OF_VERSION_1_4_check(
    of_table_status_t *obj, int value);
extern int of_table_status_OF_VERSION_1_4_populate_scalars(
    of_table_status_t *obj, int value);
extern int of_table_status_OF_VERSION_1_4_check_scalars(
    of_table_status_t *obj, int value);

extern int of_action_bsn_checksum_OF_VERSION_1_4_populate(
    of_action_bsn_checksum_t *obj, int value);
extern int of_action_bsn_checksum_OF_VERSION_1_4_check(
    of_action_bsn_checksum_t *obj, int value);
extern int of_action_bsn_checksum_OF_VERSION_1_4_populate_scalars(
    of_action_bsn_checksum_t *obj, int value);
extern int of_action_bsn_checksum_OF_VERSION_1_4_check_scalars(
    of_action_bsn_checksum_t *obj, int value);

extern int of_action_bsn_gentable_OF_VERSION_1_4_populate(
    of_action_bsn_gentable_t *obj, int value);
extern int of_action_bsn_gentable_OF_VERSION_1_4_check(
    of_action_bsn_gentable_t *obj, int value);
extern int of_action_bsn_gentable_OF_VERSION_1_4_populate_scalars(
    of_action_bsn_gentable_t *obj, int value);
extern int of_action_bsn_gentable_OF_VERSION_1_4_check_scalars(
    of_action_bsn_gentable_t *obj, int value);

extern int of_action_bsn_mirror_OF_VERSION_1_4_populate(
    of_action_bsn_mirror_t *obj, int value);
extern int of_action_bsn_mirror_OF_VERSION_1_4_check(
    of_action_bsn_mirror_t *obj, int value);
extern int of_action_bsn_mirror_OF_VERSION_1_4_populate_scalars(
    of_action_bsn_mirror_t *obj, int value);
extern int of_action_bsn_mirror_OF_VERSION_1_4_check_scalars(
    of_action_bsn_mirror_t *obj, int value);

extern int of_action_bsn_set_tunnel_dst_OF_VERSION_1_4_populate(
    of_action_bsn_set_tunnel_dst_t *obj, int value);
extern int of_action_bsn_set_tunnel_dst_OF_VERSION_1_4_check(
    of_action_bsn_set_tunnel_dst_t *obj, int value);
extern int of_action_bsn_set_tunnel_dst_OF_VERSION_1_4_populate_scalars(
    of_action_bsn_set_tunnel_dst_t *obj, int value);
extern int of_action_bsn_set_tunnel_dst_OF_VERSION_1_4_check_scalars(
    of_action_bsn_set_tunnel_dst_t *obj, int value);

extern int of_action_copy_ttl_in_OF_VERSION_1_4_populate(
    of_action_copy_ttl_in_t *obj, int value);
extern int of_action_copy_ttl_in_OF_VERSION_1_4_check(
    of_action_copy_ttl_in_t *obj, int value);
extern int of_action_copy_ttl_in_OF_VERSION_1_4_populate_scalars(
    of_action_copy_ttl_in_t *obj, int value);
extern int of_action_copy_ttl_in_OF_VERSION_1_4_check_scalars(
    of_action_copy_ttl_in_t *obj, int value);

extern int of_action_copy_ttl_out_OF_VERSION_1_4_populate(
    of_action_copy_ttl_out_t *obj, int value);
extern int of_action_copy_ttl_out_OF_VERSION_1_4_check(
    of_action_copy_ttl_out_t *obj, int value);
extern int of_action_copy_ttl_out_OF_VERSION_1_4_populate_scalars(
    of_action_copy_ttl_out_t *obj, int value);
extern int of_action_copy_ttl_out_OF_VERSION_1_4_check_scalars(
    of_action_copy_ttl_out_t *obj, int value);

extern int of_action_dec_mpls_ttl_OF_VERSION_1_4_populate(
    of_action_dec_mpls_ttl_t *obj, int value);
extern int of_action_dec_mpls_ttl_OF_VERSION_1_4_check(
    of_action_dec_mpls_ttl_t *obj, int value);
extern int of_action_dec_mpls_ttl_OF_VERSION_1_4_populate_scalars(
    of_action_dec_mpls_ttl_t *obj, int value);
extern int of_action_dec_mpls_ttl_OF_VERSION_1_4_check_scalars(
    of_action_dec_mpls_ttl_t *obj, int value);

extern int of_action_dec_nw_ttl_OF_VERSION_1_4_populate(
    of_action_dec_nw_ttl_t *obj, int value);
extern int of_action_dec_nw_ttl_OF_VERSION_1_4_check(
    of_action_dec_nw_ttl_t *obj, int value);
extern int of_action_dec_nw_ttl_OF_VERSION_1_4_populate_scalars(
    of_action_dec_nw_ttl_t *obj, int value);
extern int of_action_dec_nw_ttl_OF_VERSION_1_4_check_scalars(
    of_action_dec_nw_ttl_t *obj, int value);

extern int of_action_group_OF_VERSION_1_4_populate(
    of_action_group_t *obj, int value);
extern int of_action_group_OF_VERSION_1_4_check(
    of_action_group_t *obj, int value);
extern int of_action_group_OF_VERSION_1_4_populate_scalars(
    of_action_group_t *obj, int value);
extern int of_action_group_OF_VERSION_1_4_check_scalars(
    of_action_group_t *obj, int value);

extern int of_action_id_bsn_checksum_OF_VERSION_1_4_populate(
    of_action_id_bsn_checksum_t *obj, int value);
extern int of_action_id_bsn_checksum_OF_VERSION_1_4_check(
    of_action_id_bsn_checksum_t *obj, int value);
extern int of_action_id_bsn_checksum_OF_VERSION_1_4_populate_scalars(
    of_action_id_bsn_checksum_t *obj, int value);
extern int of_action_id_bsn_checksum_OF_VERSION_1_4_check_scalars(
    of_action_id_bsn_checksum_t *obj, int value);

extern int of_action_id_bsn_gentable_OF_VERSION_1_4_populate(
    of_action_id_bsn_gentable_t *obj, int value);
extern int of_action_id_bsn_gentable_OF_VERSION_1_4_check(
    of_action_id_bsn_gentable_t *obj, int value);
extern int of_action_id_bsn_gentable_OF_VERSION_1_4_populate_scalars(
    of_action_id_bsn_gentable_t *obj, int value);
extern int of_action_id_bsn_gentable_OF_VERSION_1_4_check_scalars(
    of_action_id_bsn_gentable_t *obj, int value);

extern int of_action_id_bsn_mirror_OF_VERSION_1_4_populate(
    of_action_id_bsn_mirror_t *obj, int value);
extern int of_action_id_bsn_mirror_OF_VERSION_1_4_check(
    of_action_id_bsn_mirror_t *obj, int value);
extern int of_action_id_bsn_mirror_OF_VERSION_1_4_populate_scalars(
    of_action_id_bsn_mirror_t *obj, int value);
extern int of_action_id_bsn_mirror_OF_VERSION_1_4_check_scalars(
    of_action_id_bsn_mirror_t *obj, int value);

extern int of_action_id_bsn_set_tunnel_dst_OF_VERSION_1_4_populate(
    of_action_id_bsn_set_tunnel_dst_t *obj, int value);
extern int of_action_id_bsn_set_tunnel_dst_OF_VERSION_1_4_check(
    of_action_id_bsn_set_tunnel_dst_t *obj, int value);
extern int of_action_id_bsn_set_tunnel_dst_OF_VERSION_1_4_populate_scalars(
    of_action_id_bsn_set_tunnel_dst_t *obj, int value);
extern int of_action_id_bsn_set_tunnel_dst_OF_VERSION_1_4_check_scalars(
    of_action_id_bsn_set_tunnel_dst_t *obj, int value);

extern int of_action_id_copy_ttl_in_OF_VERSION_1_4_populate(
    of_action_id_copy_ttl_in_t *obj, int value);
extern int of_action_id_copy_ttl_in_OF_VERSION_1_4_check(
    of_action_id_copy_ttl_in_t *obj, int value);
extern int of_action_id_copy_ttl_in_OF_VERSION_1_4_populate_scalars(
    of_action_id_copy_ttl_in_t *obj, int value);
extern int of_action_id_copy_ttl_in_OF_VERSION_1_4_check_scalars(
    of_action_id_copy_ttl_in_t *obj, int value);

extern int of_action_id_copy_ttl_out_OF_VERSION_1_4_populate(
    of_action_id_copy_ttl_out_t *obj, int value);
extern int of_action_id_copy_ttl_out_OF_VERSION_1_4_check(
    of_action_id_copy_ttl_out_t *obj, int value);
extern int of_action_id_copy_ttl_out_OF_VERSION_1_4_populate_scalars(
    of_action_id_copy_ttl_out_t *obj, int value);
extern int of_action_id_copy_ttl_out_OF_VERSION_1_4_check_scalars(
    of_action_id_copy_ttl_out_t *obj, int value);

extern int of_action_id_dec_mpls_ttl_OF_VERSION_1_4_populate(
    of_action_id_dec_mpls_ttl_t *obj, int value);
extern int of_action_id_dec_mpls_ttl_OF_VERSION_1_4_check(
    of_action_id_dec_mpls_ttl_t *obj, int value);
extern int of_action_id_dec_mpls_ttl_OF_VERSION_1_4_populate_scalars(
    of_action_id_dec_mpls_ttl_t *obj, int value);
extern int of_action_id_dec_mpls_ttl_OF_VERSION_1_4_check_scalars(
    of_action_id_dec_mpls_ttl_t *obj, int value);

extern int of_action_id_dec_nw_ttl_OF_VERSION_1_4_populate(
    of_action_id_dec_nw_ttl_t *obj, int value);
extern int of_action_id_dec_nw_ttl_OF_VERSION_1_4_check(
    of_action_id_dec_nw_ttl_t *obj, int value);
extern int of_action_id_dec_nw_ttl_OF_VERSION_1_4_populate_scalars(
    of_action_id_dec_nw_ttl_t *obj, int value);
extern int of_action_id_dec_nw_ttl_OF_VERSION_1_4_check_scalars(
    of_action_id_dec_nw_ttl_t *obj, int value);

extern int of_action_id_group_OF_VERSION_1_4_populate(
    of_action_id_group_t *obj, int value);
extern int of_action_id_group_OF_VERSION_1_4_check(
    of_action_id_group_t *obj, int value);
extern int of_action_id_group_OF_VERSION_1_4_populate_scalars(
    of_action_id_group_t *obj, int value);
extern int of_action_id_group_OF_VERSION_1_4_check_scalars(
    of_action_id_group_t *obj, int value);

extern int of_action_id_nicira_dec_ttl_OF_VERSION_1_4_populate(
    of_action_id_nicira_dec_ttl_t *obj, int value);
extern int of_action_id_nicira_dec_ttl_OF_VERSION_1_4_check(
    of_action_id_nicira_dec_ttl_t *obj, int value);
extern int of_action_id_nicira_dec_ttl_OF_VERSION_1_4_populate_scalars(
    of_action_id_nicira_dec_ttl_t *obj, int value);
extern int of_action_id_nicira_dec_ttl_OF_VERSION_1_4_check_scalars(
    of_action_id_nicira_dec_ttl_t *obj, int value);

extern int of_action_id_output_OF_VERSION_1_4_populate(
    of_action_id_output_t *obj, int value);
extern int of_action_id_output_OF_VERSION_1_4_check(
    of_action_id_output_t *obj, int value);
extern int of_action_id_output_OF_VERSION_1_4_populate_scalars(
    of_action_id_output_t *obj, int value);
extern int of_action_id_output_OF_VERSION_1_4_check_scalars(
    of_action_id_output_t *obj, int value);

extern int of_action_id_pop_mpls_OF_VERSION_1_4_populate(
    of_action_id_pop_mpls_t *obj, int value);
extern int of_action_id_pop_mpls_OF_VERSION_1_4_check(
    of_action_id_pop_mpls_t *obj, int value);
extern int of_action_id_pop_mpls_OF_VERSION_1_4_populate_scalars(
    of_action_id_pop_mpls_t *obj, int value);
extern int of_action_id_pop_mpls_OF_VERSION_1_4_check_scalars(
    of_action_id_pop_mpls_t *obj, int value);

extern int of_action_id_pop_pbb_OF_VERSION_1_4_populate(
    of_action_id_pop_pbb_t *obj, int value);
extern int of_action_id_pop_pbb_OF_VERSION_1_4_check(
    of_action_id_pop_pbb_t *obj, int value);
extern int of_action_id_pop_pbb_OF_VERSION_1_4_populate_scalars(
    of_action_id_pop_pbb_t *obj, int value);
extern int of_action_id_pop_pbb_OF_VERSION_1_4_check_scalars(
    of_action_id_pop_pbb_t *obj, int value);

extern int of_action_id_pop_vlan_OF_VERSION_1_4_populate(
    of_action_id_pop_vlan_t *obj, int value);
extern int of_action_id_pop_vlan_OF_VERSION_1_4_check(
    of_action_id_pop_vlan_t *obj, int value);
extern int of_action_id_pop_vlan_OF_VERSION_1_4_populate_scalars(
    of_action_id_pop_vlan_t *obj, int value);
extern int of_action_id_pop_vlan_OF_VERSION_1_4_check_scalars(
    of_action_id_pop_vlan_t *obj, int value);

extern int of_action_id_push_mpls_OF_VERSION_1_4_populate(
    of_action_id_push_mpls_t *obj, int value);
extern int of_action_id_push_mpls_OF_VERSION_1_4_check(
    of_action_id_push_mpls_t *obj, int value);
extern int of_action_id_push_mpls_OF_VERSION_1_4_populate_scalars(
    of_action_id_push_mpls_t *obj, int value);
extern int of_action_id_push_mpls_OF_VERSION_1_4_check_scalars(
    of_action_id_push_mpls_t *obj, int value);

extern int of_action_id_push_pbb_OF_VERSION_1_4_populate(
    of_action_id_push_pbb_t *obj, int value);
extern int of_action_id_push_pbb_OF_VERSION_1_4_check(
    of_action_id_push_pbb_t *obj, int value);
extern int of_action_id_push_pbb_OF_VERSION_1_4_populate_scalars(
    of_action_id_push_pbb_t *obj, int value);
extern int of_action_id_push_pbb_OF_VERSION_1_4_check_scalars(
    of_action_id_push_pbb_t *obj, int value);

extern int of_action_id_push_vlan_OF_VERSION_1_4_populate(
    of_action_id_push_vlan_t *obj, int value);
extern int of_action_id_push_vlan_OF_VERSION_1_4_check(
    of_action_id_push_vlan_t *obj, int value);
extern int of_action_id_push_vlan_OF_VERSION_1_4_populate_scalars(
    of_action_id_push_vlan_t *obj, int value);
extern int of_action_id_push_vlan_OF_VERSION_1_4_check_scalars(
    of_action_id_push_vlan_t *obj, int value);

extern int of_action_id_set_field_OF_VERSION_1_4_populate(
    of_action_id_set_field_t *obj, int value);
extern int of_action_id_set_field_OF_VERSION_1_4_check(
    of_action_id_set_field_t *obj, int value);
extern int of_action_id_set_field_OF_VERSION_1_4_populate_scalars(
    of_action_id_set_field_t *obj, int value);
extern int of_action_id_set_field_OF_VERSION_1_4_check_scalars(
    of_action_id_set_field_t *obj, int value);

extern int of_action_id_set_mpls_ttl_OF_VERSION_1_4_populate(
    of_action_id_set_mpls_ttl_t *obj, int value);
extern int of_action_id_set_mpls_ttl_OF_VERSION_1_4_check(
    of_action_id_set_mpls_ttl_t *obj, int value);
extern int of_action_id_set_mpls_ttl_OF_VERSION_1_4_populate_scalars(
    of_action_id_set_mpls_ttl_t *obj, int value);
extern int of_action_id_set_mpls_ttl_OF_VERSION_1_4_check_scalars(
    of_action_id_set_mpls_ttl_t *obj, int value);

extern int of_action_id_set_nw_ttl_OF_VERSION_1_4_populate(
    of_action_id_set_nw_ttl_t *obj, int value);
extern int of_action_id_set_nw_ttl_OF_VERSION_1_4_check(
    of_action_id_set_nw_ttl_t *obj, int value);
extern int of_action_id_set_nw_ttl_OF_VERSION_1_4_populate_scalars(
    of_action_id_set_nw_ttl_t *obj, int value);
extern int of_action_id_set_nw_ttl_OF_VERSION_1_4_check_scalars(
    of_action_id_set_nw_ttl_t *obj, int value);

extern int of_action_id_set_queue_OF_VERSION_1_4_populate(
    of_action_id_set_queue_t *obj, int value);
extern int of_action_id_set_queue_OF_VERSION_1_4_check(
    of_action_id_set_queue_t *obj, int value);
extern int of_action_id_set_queue_OF_VERSION_1_4_populate_scalars(
    of_action_id_set_queue_t *obj, int value);
extern int of_action_id_set_queue_OF_VERSION_1_4_check_scalars(
    of_action_id_set_queue_t *obj, int value);

extern int of_action_nicira_dec_ttl_OF_VERSION_1_4_populate(
    of_action_nicira_dec_ttl_t *obj, int value);
extern int of_action_nicira_dec_ttl_OF_VERSION_1_4_check(
    of_action_nicira_dec_ttl_t *obj, int value);
extern int of_action_nicira_dec_ttl_OF_VERSION_1_4_populate_scalars(
    of_action_nicira_dec_ttl_t *obj, int value);
extern int of_action_nicira_dec_ttl_OF_VERSION_1_4_check_scalars(
    of_action_nicira_dec_ttl_t *obj, int value);

extern int of_action_output_OF_VERSION_1_4_populate(
    of_action_output_t *obj, int value);
extern int of_action_output_OF_VERSION_1_4_check(
    of_action_output_t *obj, int value);
extern int of_action_output_OF_VERSION_1_4_populate_scalars(
    of_action_output_t *obj, int value);
extern int of_action_output_OF_VERSION_1_4_check_scalars(
    of_action_output_t *obj, int value);

extern int of_action_pop_mpls_OF_VERSION_1_4_populate(
    of_action_pop_mpls_t *obj, int value);
extern int of_action_pop_mpls_OF_VERSION_1_4_check(
    of_action_pop_mpls_t *obj, int value);
extern int of_action_pop_mpls_OF_VERSION_1_4_populate_scalars(
    of_action_pop_mpls_t *obj, int value);
extern int of_action_pop_mpls_OF_VERSION_1_4_check_scalars(
    of_action_pop_mpls_t *obj, int value);

extern int of_action_pop_pbb_OF_VERSION_1_4_populate(
    of_action_pop_pbb_t *obj, int value);
extern int of_action_pop_pbb_OF_VERSION_1_4_check(
    of_action_pop_pbb_t *obj, int value);
extern int of_action_pop_pbb_OF_VERSION_1_4_populate_scalars(
    of_action_pop_pbb_t *obj, int value);
extern int of_action_pop_pbb_OF_VERSION_1_4_check_scalars(
    of_action_pop_pbb_t *obj, int value);

extern int of_action_pop_vlan_OF_VERSION_1_4_populate(
    of_action_pop_vlan_t *obj, int value);
extern int of_action_pop_vlan_OF_VERSION_1_4_check(
    of_action_pop_vlan_t *obj, int value);
extern int of_action_pop_vlan_OF_VERSION_1_4_populate_scalars(
    of_action_pop_vlan_t *obj, int value);
extern int of_action_pop_vlan_OF_VERSION_1_4_check_scalars(
    of_action_pop_vlan_t *obj, int value);

extern int of_action_push_mpls_OF_VERSION_1_4_populate(
    of_action_push_mpls_t *obj, int value);
extern int of_action_push_mpls_OF_VERSION_1_4_check(
    of_action_push_mpls_t *obj, int value);
extern int of_action_push_mpls_OF_VERSION_1_4_populate_scalars(
    of_action_push_mpls_t *obj, int value);
extern int of_action_push_mpls_OF_VERSION_1_4_check_scalars(
    of_action_push_mpls_t *obj, int value);

extern int of_action_push_pbb_OF_VERSION_1_4_populate(
    of_action_push_pbb_t *obj, int value);
extern int of_action_push_pbb_OF_VERSION_1_4_check(
    of_action_push_pbb_t *obj, int value);
extern int of_action_push_pbb_OF_VERSION_1_4_populate_scalars(
    of_action_push_pbb_t *obj, int value);
extern int of_action_push_pbb_OF_VERSION_1_4_check_scalars(
    of_action_push_pbb_t *obj, int value);

extern int of_action_push_vlan_OF_VERSION_1_4_populate(
    of_action_push_vlan_t *obj, int value);
extern int of_action_push_vlan_OF_VERSION_1_4_check(
    of_action_push_vlan_t *obj, int value);
extern int of_action_push_vlan_OF_VERSION_1_4_populate_scalars(
    of_action_push_vlan_t *obj, int value);
extern int of_action_push_vlan_OF_VERSION_1_4_check_scalars(
    of_action_push_vlan_t *obj, int value);

extern int of_action_set_field_OF_VERSION_1_4_populate(
    of_action_set_field_t *obj, int value);
extern int of_action_set_field_OF_VERSION_1_4_check(
    of_action_set_field_t *obj, int value);
extern int of_action_set_field_OF_VERSION_1_4_populate_scalars(
    of_action_set_field_t *obj, int value);
extern int of_action_set_field_OF_VERSION_1_4_check_scalars(
    of_action_set_field_t *obj, int value);

extern int of_action_set_mpls_ttl_OF_VERSION_1_4_populate(
    of_action_set_mpls_ttl_t *obj, int value);
extern int of_action_set_mpls_ttl_OF_VERSION_1_4_check(
    of_action_set_mpls_ttl_t *obj, int value);
extern int of_action_set_mpls_ttl_OF_VERSION_1_4_populate_scalars(
    of_action_set_mpls_ttl_t *obj, int value);
extern int of_action_set_mpls_ttl_OF_VERSION_1_4_check_scalars(
    of_action_set_mpls_ttl_t *obj, int value);

extern int of_action_set_nw_ttl_OF_VERSION_1_4_populate(
    of_action_set_nw_ttl_t *obj, int value);
extern int of_action_set_nw_ttl_OF_VERSION_1_4_check(
    of_action_set_nw_ttl_t *obj, int value);
extern int of_action_set_nw_ttl_OF_VERSION_1_4_populate_scalars(
    of_action_set_nw_ttl_t *obj, int value);
extern int of_action_set_nw_ttl_OF_VERSION_1_4_check_scalars(
    of_action_set_nw_ttl_t *obj, int value);

extern int of_action_set_queue_OF_VERSION_1_4_populate(
    of_action_set_queue_t *obj, int value);
extern int of_action_set_queue_OF_VERSION_1_4_check(
    of_action_set_queue_t *obj, int value);
extern int of_action_set_queue_OF_VERSION_1_4_populate_scalars(
    of_action_set_queue_t *obj, int value);
extern int of_action_set_queue_OF_VERSION_1_4_check_scalars(
    of_action_set_queue_t *obj, int value);

extern int of_async_config_prop_experimenter_master_OF_VERSION_1_4_populate(
    of_async_config_prop_experimenter_master_t *obj, int value);
extern int of_async_config_prop_experimenter_master_OF_VERSION_1_4_check(
    of_async_config_prop_experimenter_master_t *obj, int value);
extern int of_async_config_prop_experimenter_master_OF_VERSION_1_4_populate_scalars(
    of_async_config_prop_experimenter_master_t *obj, int value);
extern int of_async_config_prop_experimenter_master_OF_VERSION_1_4_check_scalars(
    of_async_config_prop_experimenter_master_t *obj, int value);

extern int of_async_config_prop_experimenter_slave_OF_VERSION_1_4_populate(
    of_async_config_prop_experimenter_slave_t *obj, int value);
extern int of_async_config_prop_experimenter_slave_OF_VERSION_1_4_check(
    of_async_config_prop_experimenter_slave_t *obj, int value);
extern int of_async_config_prop_experimenter_slave_OF_VERSION_1_4_populate_scalars(
    of_async_config_prop_experimenter_slave_t *obj, int value);
extern int of_async_config_prop_experimenter_slave_OF_VERSION_1_4_check_scalars(
    of_async_config_prop_experimenter_slave_t *obj, int value);

extern int of_async_config_prop_flow_removed_master_OF_VERSION_1_4_populate(
    of_async_config_prop_flow_removed_master_t *obj, int value);
extern int of_async_config_prop_flow_removed_master_OF_VERSION_1_4_check(
    of_async_config_prop_flow_removed_master_t *obj, int value);
extern int of_async_config_prop_flow_removed_master_OF_VERSION_1_4_populate_scalars(
    of_async_config_prop_flow_removed_master_t *obj, int value);
extern int of_async_config_prop_flow_removed_master_OF_VERSION_1_4_check_scalars(
    of_async_config_prop_flow_removed_master_t *obj, int value);

extern int of_async_config_prop_flow_removed_slave_OF_VERSION_1_4_populate(
    of_async_config_prop_flow_removed_slave_t *obj, int value);
extern int of_async_config_prop_flow_removed_slave_OF_VERSION_1_4_check(
    of_async_config_prop_flow_removed_slave_t *obj, int value);
extern int of_async_config_prop_flow_removed_slave_OF_VERSION_1_4_populate_scalars(
    of_async_config_prop_flow_removed_slave_t *obj, int value);
extern int of_async_config_prop_flow_removed_slave_OF_VERSION_1_4_check_scalars(
    of_async_config_prop_flow_removed_slave_t *obj, int value);

extern int of_async_config_prop_packet_in_master_OF_VERSION_1_4_populate(
    of_async_config_prop_packet_in_master_t *obj, int value);
extern int of_async_config_prop_packet_in_master_OF_VERSION_1_4_check(
    of_async_config_prop_packet_in_master_t *obj, int value);
extern int of_async_config_prop_packet_in_master_OF_VERSION_1_4_populate_scalars(
    of_async_config_prop_packet_in_master_t *obj, int value);
extern int of_async_config_prop_packet_in_master_OF_VERSION_1_4_check_scalars(
    of_async_config_prop_packet_in_master_t *obj, int value);

extern int of_async_config_prop_packet_in_slave_OF_VERSION_1_4_populate(
    of_async_config_prop_packet_in_slave_t *obj, int value);
extern int of_async_config_prop_packet_in_slave_OF_VERSION_1_4_check(
    of_async_config_prop_packet_in_slave_t *obj, int value);
extern int of_async_config_prop_packet_in_slave_OF_VERSION_1_4_populate_scalars(
    of_async_config_prop_packet_in_slave_t *obj, int value);
extern int of_async_config_prop_packet_in_slave_OF_VERSION_1_4_check_scalars(
    of_async_config_prop_packet_in_slave_t *obj, int value);

extern int of_async_config_prop_port_status_master_OF_VERSION_1_4_populate(
    of_async_config_prop_port_status_master_t *obj, int value);
extern int of_async_config_prop_port_status_master_OF_VERSION_1_4_check(
    of_async_config_prop_port_status_master_t *obj, int value);
extern int of_async_config_prop_port_status_master_OF_VERSION_1_4_populate_scalars(
    of_async_config_prop_port_status_master_t *obj, int value);
extern int of_async_config_prop_port_status_master_OF_VERSION_1_4_check_scalars(
    of_async_config_prop_port_status_master_t *obj, int value);

extern int of_async_config_prop_port_status_slave_OF_VERSION_1_4_populate(
    of_async_config_prop_port_status_slave_t *obj, int value);
extern int of_async_config_prop_port_status_slave_OF_VERSION_1_4_check(
    of_async_config_prop_port_status_slave_t *obj, int value);
extern int of_async_config_prop_port_status_slave_OF_VERSION_1_4_populate_scalars(
    of_async_config_prop_port_status_slave_t *obj, int value);
extern int of_async_config_prop_port_status_slave_OF_VERSION_1_4_check_scalars(
    of_async_config_prop_port_status_slave_t *obj, int value);

extern int of_async_config_prop_requestforward_master_OF_VERSION_1_4_populate(
    of_async_config_prop_requestforward_master_t *obj, int value);
extern int of_async_config_prop_requestforward_master_OF_VERSION_1_4_check(
    of_async_config_prop_requestforward_master_t *obj, int value);
extern int of_async_config_prop_requestforward_master_OF_VERSION_1_4_populate_scalars(
    of_async_config_prop_requestforward_master_t *obj, int value);
extern int of_async_config_prop_requestforward_master_OF_VERSION_1_4_check_scalars(
    of_async_config_prop_requestforward_master_t *obj, int value);

extern int of_async_config_prop_requestforward_slave_OF_VERSION_1_4_populate(
    of_async_config_prop_requestforward_slave_t *obj, int value);
extern int of_async_config_prop_requestforward_slave_OF_VERSION_1_4_check(
    of_async_config_prop_requestforward_slave_t *obj, int value);
extern int of_async_config_prop_requestforward_slave_OF_VERSION_1_4_populate_scalars(
    of_async_config_prop_requestforward_slave_t *obj, int value);
extern int of_async_config_prop_requestforward_slave_OF_VERSION_1_4_check_scalars(
    of_async_config_prop_requestforward_slave_t *obj, int value);

extern int of_async_config_prop_role_status_master_OF_VERSION_1_4_populate(
    of_async_config_prop_role_status_master_t *obj, int value);
extern int of_async_config_prop_role_status_master_OF_VERSION_1_4_check(
    of_async_config_prop_role_status_master_t *obj, int value);
extern int of_async_config_prop_role_status_master_OF_VERSION_1_4_populate_scalars(
    of_async_config_prop_role_status_master_t *obj, int value);
extern int of_async_config_prop_role_status_master_OF_VERSION_1_4_check_scalars(
    of_async_config_prop_role_status_master_t *obj, int value);

extern int of_async_config_prop_role_status_slave_OF_VERSION_1_4_populate(
    of_async_config_prop_role_status_slave_t *obj, int value);
extern int of_async_config_prop_role_status_slave_OF_VERSION_1_4_check(
    of_async_config_prop_role_status_slave_t *obj, int value);
extern int of_async_config_prop_role_status_slave_OF_VERSION_1_4_populate_scalars(
    of_async_config_prop_role_status_slave_t *obj, int value);
extern int of_async_config_prop_role_status_slave_OF_VERSION_1_4_check_scalars(
    of_async_config_prop_role_status_slave_t *obj, int value);

extern int of_async_config_prop_table_status_master_OF_VERSION_1_4_populate(
    of_async_config_prop_table_status_master_t *obj, int value);
extern int of_async_config_prop_table_status_master_OF_VERSION_1_4_check(
    of_async_config_prop_table_status_master_t *obj, int value);
extern int of_async_config_prop_table_status_master_OF_VERSION_1_4_populate_scalars(
    of_async_config_prop_table_status_master_t *obj, int value);
extern int of_async_config_prop_table_status_master_OF_VERSION_1_4_check_scalars(
    of_async_config_prop_table_status_master_t *obj, int value);

extern int of_async_config_prop_table_status_slave_OF_VERSION_1_4_populate(
    of_async_config_prop_table_status_slave_t *obj, int value);
extern int of_async_config_prop_table_status_slave_OF_VERSION_1_4_check(
    of_async_config_prop_table_status_slave_t *obj, int value);
extern int of_async_config_prop_table_status_slave_OF_VERSION_1_4_populate_scalars(
    of_async_config_prop_table_status_slave_t *obj, int value);
extern int of_async_config_prop_table_status_slave_OF_VERSION_1_4_check_scalars(
    of_async_config_prop_table_status_slave_t *obj, int value);

extern int of_bsn_controller_connection_OF_VERSION_1_4_populate(
    of_bsn_controller_connection_t *obj, int value);
extern int of_bsn_controller_connection_OF_VERSION_1_4_check(
    of_bsn_controller_connection_t *obj, int value);
extern int of_bsn_controller_connection_OF_VERSION_1_4_populate_scalars(
    of_bsn_controller_connection_t *obj, int value);
extern int of_bsn_controller_connection_OF_VERSION_1_4_check_scalars(
    of_bsn_controller_connection_t *obj, int value);

extern int of_bsn_debug_counter_desc_stats_entry_OF_VERSION_1_4_populate(
    of_bsn_debug_counter_desc_stats_entry_t *obj, int value);
extern int of_bsn_debug_counter_desc_stats_entry_OF_VERSION_1_4_check(
    of_bsn_debug_counter_desc_stats_entry_t *obj, int value);
extern int of_bsn_debug_counter_desc_stats_entry_OF_VERSION_1_4_populate_scalars(
    of_bsn_debug_counter_desc_stats_entry_t *obj, int value);
extern int of_bsn_debug_counter_desc_stats_entry_OF_VERSION_1_4_check_scalars(
    of_bsn_debug_counter_desc_stats_entry_t *obj, int value);

extern int of_bsn_debug_counter_stats_entry_OF_VERSION_1_4_populate(
    of_bsn_debug_counter_stats_entry_t *obj, int value);
extern int of_bsn_debug_counter_stats_entry_OF_VERSION_1_4_check(
    of_bsn_debug_counter_stats_entry_t *obj, int value);
extern int of_bsn_debug_counter_stats_entry_OF_VERSION_1_4_populate_scalars(
    of_bsn_debug_counter_stats_entry_t *obj, int value);
extern int of_bsn_debug_counter_stats_entry_OF_VERSION_1_4_check_scalars(
    of_bsn_debug_counter_stats_entry_t *obj, int value);

extern int of_bsn_flow_checksum_bucket_stats_entry_OF_VERSION_1_4_populate(
    of_bsn_flow_checksum_bucket_stats_entry_t *obj, int value);
extern int of_bsn_flow_checksum_bucket_stats_entry_OF_VERSION_1_4_check(
    of_bsn_flow_checksum_bucket_stats_entry_t *obj, int value);
extern int of_bsn_flow_checksum_bucket_stats_entry_OF_VERSION_1_4_populate_scalars(
    of_bsn_flow_checksum_bucket_stats_entry_t *obj, int value);
extern int of_bsn_flow_checksum_bucket_stats_entry_OF_VERSION_1_4_check_scalars(
    of_bsn_flow_checksum_bucket_stats_entry_t *obj, int value);

extern int of_bsn_generic_stats_entry_OF_VERSION_1_4_populate(
    of_bsn_generic_stats_entry_t *obj, int value);
extern int of_bsn_generic_stats_entry_OF_VERSION_1_4_check(
    of_bsn_generic_stats_entry_t *obj, int value);
extern int of_bsn_generic_stats_entry_OF_VERSION_1_4_populate_scalars(
    of_bsn_generic_stats_entry_t *obj, int value);
extern int of_bsn_generic_stats_entry_OF_VERSION_1_4_check_scalars(
    of_bsn_generic_stats_entry_t *obj, int value);

extern int of_bsn_gentable_bucket_stats_entry_OF_VERSION_1_4_populate(
    of_bsn_gentable_bucket_stats_entry_t *obj, int value);
extern int of_bsn_gentable_bucket_stats_entry_OF_VERSION_1_4_check(
    of_bsn_gentable_bucket_stats_entry_t *obj, int value);
extern int of_bsn_gentable_bucket_stats_entry_OF_VERSION_1_4_populate_scalars(
    of_bsn_gentable_bucket_stats_entry_t *obj, int value);
extern int of_bsn_gentable_bucket_stats_entry_OF_VERSION_1_4_check_scalars(
    of_bsn_gentable_bucket_stats_entry_t *obj, int value);

extern int of_bsn_gentable_desc_stats_entry_OF_VERSION_1_4_populate(
    of_bsn_gentable_desc_stats_entry_t *obj, int value);
extern int of_bsn_gentable_desc_stats_entry_OF_VERSION_1_4_check(
    of_bsn_gentable_desc_stats_entry_t *obj, int value);
extern int of_bsn_gentable_desc_stats_entry_OF_VERSION_1_4_populate_scalars(
    of_bsn_gentable_desc_stats_entry_t *obj, int value);
extern int of_bsn_gentable_desc_stats_entry_OF_VERSION_1_4_check_scalars(
    of_bsn_gentable_desc_stats_entry_t *obj, int value);

extern int of_bsn_gentable_entry_desc_stats_entry_OF_VERSION_1_4_populate(
    of_bsn_gentable_entry_desc_stats_entry_t *obj, int value);
extern int of_bsn_gentable_entry_desc_stats_entry_OF_VERSION_1_4_check(
    of_bsn_gentable_entry_desc_stats_entry_t *obj, int value);
extern int of_bsn_gentable_entry_desc_stats_entry_OF_VERSION_1_4_populate_scalars(
    of_bsn_gentable_entry_desc_stats_entry_t *obj, int value);
extern int of_bsn_gentable_entry_desc_stats_entry_OF_VERSION_1_4_check_scalars(
    of_bsn_gentable_entry_desc_stats_entry_t *obj, int value);

extern int of_bsn_gentable_entry_stats_entry_OF_VERSION_1_4_populate(
    of_bsn_gentable_entry_stats_entry_t *obj, int value);
extern int of_bsn_gentable_entry_stats_entry_OF_VERSION_1_4_check(
    of_bsn_gentable_entry_stats_entry_t *obj, int value);
extern int of_bsn_gentable_entry_stats_entry_OF_VERSION_1_4_populate_scalars(
    of_bsn_gentable_entry_stats_entry_t *obj, int value);
extern int of_bsn_gentable_entry_stats_entry_OF_VERSION_1_4_check_scalars(
    of_bsn_gentable_entry_stats_entry_t *obj, int value);

extern int of_bsn_gentable_stats_entry_OF_VERSION_1_4_populate(
    of_bsn_gentable_stats_entry_t *obj, int value);
extern int of_bsn_gentable_stats_entry_OF_VERSION_1_4_check(
    of_bsn_gentable_stats_entry_t *obj, int value);
extern int of_bsn_gentable_stats_entry_OF_VERSION_1_4_populate_scalars(
    of_bsn_gentable_stats_entry_t *obj, int value);
extern int of_bsn_gentable_stats_entry_OF_VERSION_1_4_check_scalars(
    of_bsn_gentable_stats_entry_t *obj, int value);

extern int of_bsn_interface_OF_VERSION_1_4_populate(
    of_bsn_interface_t *obj, int value);
extern int of_bsn_interface_OF_VERSION_1_4_check(
    of_bsn_interface_t *obj, int value);
extern int of_bsn_interface_OF_VERSION_1_4_populate_scalars(
    of_bsn_interface_t *obj, int value);
extern int of_bsn_interface_OF_VERSION_1_4_check_scalars(
    of_bsn_interface_t *obj, int value);

extern int of_bsn_lacp_stats_entry_OF_VERSION_1_4_populate(
    of_bsn_lacp_stats_entry_t *obj, int value);
extern int of_bsn_lacp_stats_entry_OF_VERSION_1_4_check(
    of_bsn_lacp_stats_entry_t *obj, int value);
extern int of_bsn_lacp_stats_entry_OF_VERSION_1_4_populate_scalars(
    of_bsn_lacp_stats_entry_t *obj, int value);
extern int of_bsn_lacp_stats_entry_OF_VERSION_1_4_check_scalars(
    of_bsn_lacp_stats_entry_t *obj, int value);

extern int of_bsn_port_counter_stats_entry_OF_VERSION_1_4_populate(
    of_bsn_port_counter_stats_entry_t *obj, int value);
extern int of_bsn_port_counter_stats_entry_OF_VERSION_1_4_check(
    of_bsn_port_counter_stats_entry_t *obj, int value);
extern int of_bsn_port_counter_stats_entry_OF_VERSION_1_4_populate_scalars(
    of_bsn_port_counter_stats_entry_t *obj, int value);
extern int of_bsn_port_counter_stats_entry_OF_VERSION_1_4_check_scalars(
    of_bsn_port_counter_stats_entry_t *obj, int value);

extern int of_bsn_switch_pipeline_stats_entry_OF_VERSION_1_4_populate(
    of_bsn_switch_pipeline_stats_entry_t *obj, int value);
extern int of_bsn_switch_pipeline_stats_entry_OF_VERSION_1_4_check(
    of_bsn_switch_pipeline_stats_entry_t *obj, int value);
extern int of_bsn_switch_pipeline_stats_entry_OF_VERSION_1_4_populate_scalars(
    of_bsn_switch_pipeline_stats_entry_t *obj, int value);
extern int of_bsn_switch_pipeline_stats_entry_OF_VERSION_1_4_check_scalars(
    of_bsn_switch_pipeline_stats_entry_t *obj, int value);

extern int of_bsn_table_checksum_stats_entry_OF_VERSION_1_4_populate(
    of_bsn_table_checksum_stats_entry_t *obj, int value);
extern int of_bsn_table_checksum_stats_entry_OF_VERSION_1_4_check(
    of_bsn_table_checksum_stats_entry_t *obj, int value);
extern int of_bsn_table_checksum_stats_entry_OF_VERSION_1_4_populate_scalars(
    of_bsn_table_checksum_stats_entry_t *obj, int value);
extern int of_bsn_table_checksum_stats_entry_OF_VERSION_1_4_check_scalars(
    of_bsn_table_checksum_stats_entry_t *obj, int value);

extern int of_bsn_tlv_actor_key_OF_VERSION_1_4_populate(
    of_bsn_tlv_actor_key_t *obj, int value);
extern int of_bsn_tlv_actor_key_OF_VERSION_1_4_check(
    of_bsn_tlv_actor_key_t *obj, int value);
extern int of_bsn_tlv_actor_key_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_actor_key_t *obj, int value);
extern int of_bsn_tlv_actor_key_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_actor_key_t *obj, int value);

extern int of_bsn_tlv_actor_port_num_OF_VERSION_1_4_populate(
    of_bsn_tlv_actor_port_num_t *obj, int value);
extern int of_bsn_tlv_actor_port_num_OF_VERSION_1_4_check(
    of_bsn_tlv_actor_port_num_t *obj, int value);
extern int of_bsn_tlv_actor_port_num_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_actor_port_num_t *obj, int value);
extern int of_bsn_tlv_actor_port_num_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_actor_port_num_t *obj, int value);

extern int of_bsn_tlv_actor_port_priority_OF_VERSION_1_4_populate(
    of_bsn_tlv_actor_port_priority_t *obj, int value);
extern int of_bsn_tlv_actor_port_priority_OF_VERSION_1_4_check(
    of_bsn_tlv_actor_port_priority_t *obj, int value);
extern int of_bsn_tlv_actor_port_priority_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_actor_port_priority_t *obj, int value);
extern int of_bsn_tlv_actor_port_priority_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_actor_port_priority_t *obj, int value);

extern int of_bsn_tlv_actor_state_OF_VERSION_1_4_populate(
    of_bsn_tlv_actor_state_t *obj, int value);
extern int of_bsn_tlv_actor_state_OF_VERSION_1_4_check(
    of_bsn_tlv_actor_state_t *obj, int value);
extern int of_bsn_tlv_actor_state_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_actor_state_t *obj, int value);
extern int of_bsn_tlv_actor_state_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_actor_state_t *obj, int value);

extern int of_bsn_tlv_actor_system_mac_OF_VERSION_1_4_populate(
    of_bsn_tlv_actor_system_mac_t *obj, int value);
extern int of_bsn_tlv_actor_system_mac_OF_VERSION_1_4_check(
    of_bsn_tlv_actor_system_mac_t *obj, int value);
extern int of_bsn_tlv_actor_system_mac_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_actor_system_mac_t *obj, int value);
extern int of_bsn_tlv_actor_system_mac_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_actor_system_mac_t *obj, int value);

extern int of_bsn_tlv_actor_system_priority_OF_VERSION_1_4_populate(
    of_bsn_tlv_actor_system_priority_t *obj, int value);
extern int of_bsn_tlv_actor_system_priority_OF_VERSION_1_4_check(
    of_bsn_tlv_actor_system_priority_t *obj, int value);
extern int of_bsn_tlv_actor_system_priority_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_actor_system_priority_t *obj, int value);
extern int of_bsn_tlv_actor_system_priority_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_actor_system_priority_t *obj, int value);

extern int of_bsn_tlv_anchor_OF_VERSION_1_4_populate(
    of_bsn_tlv_anchor_t *obj, int value);
extern int of_bsn_tlv_anchor_OF_VERSION_1_4_check(
    of_bsn_tlv_anchor_t *obj, int value);
extern int of_bsn_tlv_anchor_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_anchor_t *obj, int value);
extern int of_bsn_tlv_anchor_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_anchor_t *obj, int value);

extern int of_bsn_tlv_apply_bytes_OF_VERSION_1_4_populate(
    of_bsn_tlv_apply_bytes_t *obj, int value);
extern int of_bsn_tlv_apply_bytes_OF_VERSION_1_4_check(
    of_bsn_tlv_apply_bytes_t *obj, int value);
extern int of_bsn_tlv_apply_bytes_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_apply_bytes_t *obj, int value);
extern int of_bsn_tlv_apply_bytes_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_apply_bytes_t *obj, int value);

extern int of_bsn_tlv_apply_packets_OF_VERSION_1_4_populate(
    of_bsn_tlv_apply_packets_t *obj, int value);
extern int of_bsn_tlv_apply_packets_OF_VERSION_1_4_check(
    of_bsn_tlv_apply_packets_t *obj, int value);
extern int of_bsn_tlv_apply_packets_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_apply_packets_t *obj, int value);
extern int of_bsn_tlv_apply_packets_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_apply_packets_t *obj, int value);

extern int of_bsn_tlv_auto_negotiation_OF_VERSION_1_4_populate(
    of_bsn_tlv_auto_negotiation_t *obj, int value);
extern int of_bsn_tlv_auto_negotiation_OF_VERSION_1_4_check(
    of_bsn_tlv_auto_negotiation_t *obj, int value);
extern int of_bsn_tlv_auto_negotiation_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_auto_negotiation_t *obj, int value);
extern int of_bsn_tlv_auto_negotiation_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_auto_negotiation_t *obj, int value);

extern int of_bsn_tlv_broadcast_query_timeout_OF_VERSION_1_4_populate(
    of_bsn_tlv_broadcast_query_timeout_t *obj, int value);
extern int of_bsn_tlv_broadcast_query_timeout_OF_VERSION_1_4_check(
    of_bsn_tlv_broadcast_query_timeout_t *obj, int value);
extern int of_bsn_tlv_broadcast_query_timeout_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_broadcast_query_timeout_t *obj, int value);
extern int of_bsn_tlv_broadcast_query_timeout_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_broadcast_query_timeout_t *obj, int value);

extern int of_bsn_tlv_broadcast_rate_OF_VERSION_1_4_populate(
    of_bsn_tlv_broadcast_rate_t *obj, int value);
extern int of_bsn_tlv_broadcast_rate_OF_VERSION_1_4_check(
    of_bsn_tlv_broadcast_rate_t *obj, int value);
extern int of_bsn_tlv_broadcast_rate_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_broadcast_rate_t *obj, int value);
extern int of_bsn_tlv_broadcast_rate_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_broadcast_rate_t *obj, int value);

extern int of_bsn_tlv_bucket_OF_VERSION_1_4_populate(
    of_bsn_tlv_bucket_t *obj, int value);
extern int of_bsn_tlv_bucket_OF_VERSION_1_4_check(
    of_bsn_tlv_bucket_t *obj, int value);
extern int of_bsn_tlv_bucket_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_bucket_t *obj, int value);
extern int of_bsn_tlv_bucket_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_bucket_t *obj, int value);

extern int of_bsn_tlv_circuit_id_OF_VERSION_1_4_populate(
    of_bsn_tlv_circuit_id_t *obj, int value);
extern int of_bsn_tlv_circuit_id_OF_VERSION_1_4_check(
    of_bsn_tlv_circuit_id_t *obj, int value);
extern int of_bsn_tlv_circuit_id_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_circuit_id_t *obj, int value);
extern int of_bsn_tlv_circuit_id_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_circuit_id_t *obj, int value);

extern int of_bsn_tlv_convergence_status_OF_VERSION_1_4_populate(
    of_bsn_tlv_convergence_status_t *obj, int value);
extern int of_bsn_tlv_convergence_status_OF_VERSION_1_4_check(
    of_bsn_tlv_convergence_status_t *obj, int value);
extern int of_bsn_tlv_convergence_status_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_convergence_status_t *obj, int value);
extern int of_bsn_tlv_convergence_status_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_convergence_status_t *obj, int value);

extern int of_bsn_tlv_cpu_lag_OF_VERSION_1_4_populate(
    of_bsn_tlv_cpu_lag_t *obj, int value);
extern int of_bsn_tlv_cpu_lag_OF_VERSION_1_4_check(
    of_bsn_tlv_cpu_lag_t *obj, int value);
extern int of_bsn_tlv_cpu_lag_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_cpu_lag_t *obj, int value);
extern int of_bsn_tlv_cpu_lag_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_cpu_lag_t *obj, int value);

extern int of_bsn_tlv_crc_enabled_OF_VERSION_1_4_populate(
    of_bsn_tlv_crc_enabled_t *obj, int value);
extern int of_bsn_tlv_crc_enabled_OF_VERSION_1_4_check(
    of_bsn_tlv_crc_enabled_t *obj, int value);
extern int of_bsn_tlv_crc_enabled_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_crc_enabled_t *obj, int value);
extern int of_bsn_tlv_crc_enabled_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_crc_enabled_t *obj, int value);

extern int of_bsn_tlv_data_OF_VERSION_1_4_populate(
    of_bsn_tlv_data_t *obj, int value);
extern int of_bsn_tlv_data_OF_VERSION_1_4_check(
    of_bsn_tlv_data_t *obj, int value);
extern int of_bsn_tlv_data_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_data_t *obj, int value);
extern int of_bsn_tlv_data_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_data_t *obj, int value);

extern int of_bsn_tlv_data_mask_OF_VERSION_1_4_populate(
    of_bsn_tlv_data_mask_t *obj, int value);
extern int of_bsn_tlv_data_mask_OF_VERSION_1_4_check(
    of_bsn_tlv_data_mask_t *obj, int value);
extern int of_bsn_tlv_data_mask_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_data_mask_t *obj, int value);
extern int of_bsn_tlv_data_mask_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_data_mask_t *obj, int value);

extern int of_bsn_tlv_decap_OF_VERSION_1_4_populate(
    of_bsn_tlv_decap_t *obj, int value);
extern int of_bsn_tlv_decap_OF_VERSION_1_4_check(
    of_bsn_tlv_decap_t *obj, int value);
extern int of_bsn_tlv_decap_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_decap_t *obj, int value);
extern int of_bsn_tlv_decap_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_decap_t *obj, int value);

extern int of_bsn_tlv_disable_src_mac_check_OF_VERSION_1_4_populate(
    of_bsn_tlv_disable_src_mac_check_t *obj, int value);
extern int of_bsn_tlv_disable_src_mac_check_OF_VERSION_1_4_check(
    of_bsn_tlv_disable_src_mac_check_t *obj, int value);
extern int of_bsn_tlv_disable_src_mac_check_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_disable_src_mac_check_t *obj, int value);
extern int of_bsn_tlv_disable_src_mac_check_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_disable_src_mac_check_t *obj, int value);

extern int of_bsn_tlv_drop_OF_VERSION_1_4_populate(
    of_bsn_tlv_drop_t *obj, int value);
extern int of_bsn_tlv_drop_OF_VERSION_1_4_check(
    of_bsn_tlv_drop_t *obj, int value);
extern int of_bsn_tlv_drop_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_drop_t *obj, int value);
extern int of_bsn_tlv_drop_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_drop_t *obj, int value);

extern int of_bsn_tlv_dscp_OF_VERSION_1_4_populate(
    of_bsn_tlv_dscp_t *obj, int value);
extern int of_bsn_tlv_dscp_OF_VERSION_1_4_check(
    of_bsn_tlv_dscp_t *obj, int value);
extern int of_bsn_tlv_dscp_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_dscp_t *obj, int value);
extern int of_bsn_tlv_dscp_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_dscp_t *obj, int value);

extern int of_bsn_tlv_ecn_OF_VERSION_1_4_populate(
    of_bsn_tlv_ecn_t *obj, int value);
extern int of_bsn_tlv_ecn_OF_VERSION_1_4_check(
    of_bsn_tlv_ecn_t *obj, int value);
extern int of_bsn_tlv_ecn_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_ecn_t *obj, int value);
extern int of_bsn_tlv_ecn_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_ecn_t *obj, int value);

extern int of_bsn_tlv_egress_only_OF_VERSION_1_4_populate(
    of_bsn_tlv_egress_only_t *obj, int value);
extern int of_bsn_tlv_egress_only_OF_VERSION_1_4_check(
    of_bsn_tlv_egress_only_t *obj, int value);
extern int of_bsn_tlv_egress_only_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_egress_only_t *obj, int value);
extern int of_bsn_tlv_egress_only_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_egress_only_t *obj, int value);

extern int of_bsn_tlv_egress_port_group_id_OF_VERSION_1_4_populate(
    of_bsn_tlv_egress_port_group_id_t *obj, int value);
extern int of_bsn_tlv_egress_port_group_id_OF_VERSION_1_4_check(
    of_bsn_tlv_egress_port_group_id_t *obj, int value);
extern int of_bsn_tlv_egress_port_group_id_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_egress_port_group_id_t *obj, int value);
extern int of_bsn_tlv_egress_port_group_id_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_egress_port_group_id_t *obj, int value);

extern int of_bsn_tlv_enhanced_hash_capability_OF_VERSION_1_4_populate(
    of_bsn_tlv_enhanced_hash_capability_t *obj, int value);
extern int of_bsn_tlv_enhanced_hash_capability_OF_VERSION_1_4_check(
    of_bsn_tlv_enhanced_hash_capability_t *obj, int value);
extern int of_bsn_tlv_enhanced_hash_capability_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_enhanced_hash_capability_t *obj, int value);
extern int of_bsn_tlv_enhanced_hash_capability_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_enhanced_hash_capability_t *obj, int value);

extern int of_bsn_tlv_eth_dst_OF_VERSION_1_4_populate(
    of_bsn_tlv_eth_dst_t *obj, int value);
extern int of_bsn_tlv_eth_dst_OF_VERSION_1_4_check(
    of_bsn_tlv_eth_dst_t *obj, int value);
extern int of_bsn_tlv_eth_dst_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_eth_dst_t *obj, int value);
extern int of_bsn_tlv_eth_dst_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_eth_dst_t *obj, int value);

extern int of_bsn_tlv_eth_src_OF_VERSION_1_4_populate(
    of_bsn_tlv_eth_src_t *obj, int value);
extern int of_bsn_tlv_eth_src_OF_VERSION_1_4_check(
    of_bsn_tlv_eth_src_t *obj, int value);
extern int of_bsn_tlv_eth_src_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_eth_src_t *obj, int value);
extern int of_bsn_tlv_eth_src_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_eth_src_t *obj, int value);

extern int of_bsn_tlv_eth_type_OF_VERSION_1_4_populate(
    of_bsn_tlv_eth_type_t *obj, int value);
extern int of_bsn_tlv_eth_type_OF_VERSION_1_4_check(
    of_bsn_tlv_eth_type_t *obj, int value);
extern int of_bsn_tlv_eth_type_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_eth_type_t *obj, int value);
extern int of_bsn_tlv_eth_type_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_eth_type_t *obj, int value);

extern int of_bsn_tlv_external_gateway_ip_OF_VERSION_1_4_populate(
    of_bsn_tlv_external_gateway_ip_t *obj, int value);
extern int of_bsn_tlv_external_gateway_ip_OF_VERSION_1_4_check(
    of_bsn_tlv_external_gateway_ip_t *obj, int value);
extern int of_bsn_tlv_external_gateway_ip_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_external_gateway_ip_t *obj, int value);
extern int of_bsn_tlv_external_gateway_ip_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_external_gateway_ip_t *obj, int value);

extern int of_bsn_tlv_external_gateway_mac_OF_VERSION_1_4_populate(
    of_bsn_tlv_external_gateway_mac_t *obj, int value);
extern int of_bsn_tlv_external_gateway_mac_OF_VERSION_1_4_check(
    of_bsn_tlv_external_gateway_mac_t *obj, int value);
extern int of_bsn_tlv_external_gateway_mac_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_external_gateway_mac_t *obj, int value);
extern int of_bsn_tlv_external_gateway_mac_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_external_gateway_mac_t *obj, int value);

extern int of_bsn_tlv_external_ip_OF_VERSION_1_4_populate(
    of_bsn_tlv_external_ip_t *obj, int value);
extern int of_bsn_tlv_external_ip_OF_VERSION_1_4_check(
    of_bsn_tlv_external_ip_t *obj, int value);
extern int of_bsn_tlv_external_ip_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_external_ip_t *obj, int value);
extern int of_bsn_tlv_external_ip_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_external_ip_t *obj, int value);

extern int of_bsn_tlv_external_mac_OF_VERSION_1_4_populate(
    of_bsn_tlv_external_mac_t *obj, int value);
extern int of_bsn_tlv_external_mac_OF_VERSION_1_4_check(
    of_bsn_tlv_external_mac_t *obj, int value);
extern int of_bsn_tlv_external_mac_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_external_mac_t *obj, int value);
extern int of_bsn_tlv_external_mac_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_external_mac_t *obj, int value);

extern int of_bsn_tlv_external_netmask_OF_VERSION_1_4_populate(
    of_bsn_tlv_external_netmask_t *obj, int value);
extern int of_bsn_tlv_external_netmask_OF_VERSION_1_4_check(
    of_bsn_tlv_external_netmask_t *obj, int value);
extern int of_bsn_tlv_external_netmask_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_external_netmask_t *obj, int value);
extern int of_bsn_tlv_external_netmask_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_external_netmask_t *obj, int value);

extern int of_bsn_tlv_force_link_up_OF_VERSION_1_4_populate(
    of_bsn_tlv_force_link_up_t *obj, int value);
extern int of_bsn_tlv_force_link_up_OF_VERSION_1_4_check(
    of_bsn_tlv_force_link_up_t *obj, int value);
extern int of_bsn_tlv_force_link_up_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_force_link_up_t *obj, int value);
extern int of_bsn_tlv_force_link_up_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_force_link_up_t *obj, int value);

extern int of_bsn_tlv_forward_error_correction_OF_VERSION_1_4_populate(
    of_bsn_tlv_forward_error_correction_t *obj, int value);
extern int of_bsn_tlv_forward_error_correction_OF_VERSION_1_4_check(
    of_bsn_tlv_forward_error_correction_t *obj, int value);
extern int of_bsn_tlv_forward_error_correction_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_forward_error_correction_t *obj, int value);
extern int of_bsn_tlv_forward_error_correction_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_forward_error_correction_t *obj, int value);

extern int of_bsn_tlv_generation_id_OF_VERSION_1_4_populate(
    of_bsn_tlv_generation_id_t *obj, int value);
extern int of_bsn_tlv_generation_id_OF_VERSION_1_4_check(
    of_bsn_tlv_generation_id_t *obj, int value);
extern int of_bsn_tlv_generation_id_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_generation_id_t *obj, int value);
extern int of_bsn_tlv_generation_id_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_generation_id_t *obj, int value);

extern int of_bsn_tlv_hash_algorithm_OF_VERSION_1_4_populate(
    of_bsn_tlv_hash_algorithm_t *obj, int value);
extern int of_bsn_tlv_hash_algorithm_OF_VERSION_1_4_check(
    of_bsn_tlv_hash_algorithm_t *obj, int value);
extern int of_bsn_tlv_hash_algorithm_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_hash_algorithm_t *obj, int value);
extern int of_bsn_tlv_hash_algorithm_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_hash_algorithm_t *obj, int value);

extern int of_bsn_tlv_hash_gtp_header_match_OF_VERSION_1_4_populate(
    of_bsn_tlv_hash_gtp_header_match_t *obj, int value);
extern int of_bsn_tlv_hash_gtp_header_match_OF_VERSION_1_4_check(
    of_bsn_tlv_hash_gtp_header_match_t *obj, int value);
extern int of_bsn_tlv_hash_gtp_header_match_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_hash_gtp_header_match_t *obj, int value);
extern int of_bsn_tlv_hash_gtp_header_match_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_hash_gtp_header_match_t *obj, int value);

extern int of_bsn_tlv_hash_gtp_port_match_OF_VERSION_1_4_populate(
    of_bsn_tlv_hash_gtp_port_match_t *obj, int value);
extern int of_bsn_tlv_hash_gtp_port_match_OF_VERSION_1_4_check(
    of_bsn_tlv_hash_gtp_port_match_t *obj, int value);
extern int of_bsn_tlv_hash_gtp_port_match_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_hash_gtp_port_match_t *obj, int value);
extern int of_bsn_tlv_hash_gtp_port_match_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_hash_gtp_port_match_t *obj, int value);

extern int of_bsn_tlv_hash_packet_field_OF_VERSION_1_4_populate(
    of_bsn_tlv_hash_packet_field_t *obj, int value);
extern int of_bsn_tlv_hash_packet_field_OF_VERSION_1_4_check(
    of_bsn_tlv_hash_packet_field_t *obj, int value);
extern int of_bsn_tlv_hash_packet_field_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_hash_packet_field_t *obj, int value);
extern int of_bsn_tlv_hash_packet_field_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_hash_packet_field_t *obj, int value);

extern int of_bsn_tlv_hash_packet_type_OF_VERSION_1_4_populate(
    of_bsn_tlv_hash_packet_type_t *obj, int value);
extern int of_bsn_tlv_hash_packet_type_OF_VERSION_1_4_check(
    of_bsn_tlv_hash_packet_type_t *obj, int value);
extern int of_bsn_tlv_hash_packet_type_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_hash_packet_type_t *obj, int value);
extern int of_bsn_tlv_hash_packet_type_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_hash_packet_type_t *obj, int value);

extern int of_bsn_tlv_hash_seed_OF_VERSION_1_4_populate(
    of_bsn_tlv_hash_seed_t *obj, int value);
extern int of_bsn_tlv_hash_seed_OF_VERSION_1_4_check(
    of_bsn_tlv_hash_seed_t *obj, int value);
extern int of_bsn_tlv_hash_seed_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_hash_seed_t *obj, int value);
extern int of_bsn_tlv_hash_seed_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_hash_seed_t *obj, int value);

extern int of_bsn_tlv_hash_type_OF_VERSION_1_4_populate(
    of_bsn_tlv_hash_type_t *obj, int value);
extern int of_bsn_tlv_hash_type_OF_VERSION_1_4_check(
    of_bsn_tlv_hash_type_t *obj, int value);
extern int of_bsn_tlv_hash_type_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_hash_type_t *obj, int value);
extern int of_bsn_tlv_hash_type_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_hash_type_t *obj, int value);

extern int of_bsn_tlv_header_size_OF_VERSION_1_4_populate(
    of_bsn_tlv_header_size_t *obj, int value);
extern int of_bsn_tlv_header_size_OF_VERSION_1_4_check(
    of_bsn_tlv_header_size_t *obj, int value);
extern int of_bsn_tlv_header_size_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_header_size_t *obj, int value);
extern int of_bsn_tlv_header_size_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_header_size_t *obj, int value);

extern int of_bsn_tlv_icmp_code_OF_VERSION_1_4_populate(
    of_bsn_tlv_icmp_code_t *obj, int value);
extern int of_bsn_tlv_icmp_code_OF_VERSION_1_4_check(
    of_bsn_tlv_icmp_code_t *obj, int value);
extern int of_bsn_tlv_icmp_code_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_icmp_code_t *obj, int value);
extern int of_bsn_tlv_icmp_code_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_icmp_code_t *obj, int value);

extern int of_bsn_tlv_icmp_id_OF_VERSION_1_4_populate(
    of_bsn_tlv_icmp_id_t *obj, int value);
extern int of_bsn_tlv_icmp_id_OF_VERSION_1_4_check(
    of_bsn_tlv_icmp_id_t *obj, int value);
extern int of_bsn_tlv_icmp_id_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_icmp_id_t *obj, int value);
extern int of_bsn_tlv_icmp_id_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_icmp_id_t *obj, int value);

extern int of_bsn_tlv_icmp_type_OF_VERSION_1_4_populate(
    of_bsn_tlv_icmp_type_t *obj, int value);
extern int of_bsn_tlv_icmp_type_OF_VERSION_1_4_check(
    of_bsn_tlv_icmp_type_t *obj, int value);
extern int of_bsn_tlv_icmp_type_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_icmp_type_t *obj, int value);
extern int of_bsn_tlv_icmp_type_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_icmp_type_t *obj, int value);

extern int of_bsn_tlv_icmpv6_chksum_OF_VERSION_1_4_populate(
    of_bsn_tlv_icmpv6_chksum_t *obj, int value);
extern int of_bsn_tlv_icmpv6_chksum_OF_VERSION_1_4_check(
    of_bsn_tlv_icmpv6_chksum_t *obj, int value);
extern int of_bsn_tlv_icmpv6_chksum_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_icmpv6_chksum_t *obj, int value);
extern int of_bsn_tlv_icmpv6_chksum_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_icmpv6_chksum_t *obj, int value);

extern int of_bsn_tlv_idle_notification_OF_VERSION_1_4_populate(
    of_bsn_tlv_idle_notification_t *obj, int value);
extern int of_bsn_tlv_idle_notification_OF_VERSION_1_4_check(
    of_bsn_tlv_idle_notification_t *obj, int value);
extern int of_bsn_tlv_idle_notification_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_idle_notification_t *obj, int value);
extern int of_bsn_tlv_idle_notification_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_idle_notification_t *obj, int value);

extern int of_bsn_tlv_idle_time_OF_VERSION_1_4_populate(
    of_bsn_tlv_idle_time_t *obj, int value);
extern int of_bsn_tlv_idle_time_OF_VERSION_1_4_check(
    of_bsn_tlv_idle_time_t *obj, int value);
extern int of_bsn_tlv_idle_time_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_idle_time_t *obj, int value);
extern int of_bsn_tlv_idle_time_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_idle_time_t *obj, int value);

extern int of_bsn_tlv_idle_timeout_OF_VERSION_1_4_populate(
    of_bsn_tlv_idle_timeout_t *obj, int value);
extern int of_bsn_tlv_idle_timeout_OF_VERSION_1_4_check(
    of_bsn_tlv_idle_timeout_t *obj, int value);
extern int of_bsn_tlv_idle_timeout_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_idle_timeout_t *obj, int value);
extern int of_bsn_tlv_idle_timeout_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_idle_timeout_t *obj, int value);

extern int of_bsn_tlv_igmp_snooping_OF_VERSION_1_4_populate(
    of_bsn_tlv_igmp_snooping_t *obj, int value);
extern int of_bsn_tlv_igmp_snooping_OF_VERSION_1_4_check(
    of_bsn_tlv_igmp_snooping_t *obj, int value);
extern int of_bsn_tlv_igmp_snooping_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_igmp_snooping_t *obj, int value);
extern int of_bsn_tlv_igmp_snooping_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_igmp_snooping_t *obj, int value);

extern int of_bsn_tlv_ingress_port_group_id_OF_VERSION_1_4_populate(
    of_bsn_tlv_ingress_port_group_id_t *obj, int value);
extern int of_bsn_tlv_ingress_port_group_id_OF_VERSION_1_4_check(
    of_bsn_tlv_ingress_port_group_id_t *obj, int value);
extern int of_bsn_tlv_ingress_port_group_id_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_ingress_port_group_id_t *obj, int value);
extern int of_bsn_tlv_ingress_port_group_id_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_ingress_port_group_id_t *obj, int value);

extern int of_bsn_tlv_internal_gateway_mac_OF_VERSION_1_4_populate(
    of_bsn_tlv_internal_gateway_mac_t *obj, int value);
extern int of_bsn_tlv_internal_gateway_mac_OF_VERSION_1_4_check(
    of_bsn_tlv_internal_gateway_mac_t *obj, int value);
extern int of_bsn_tlv_internal_gateway_mac_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_internal_gateway_mac_t *obj, int value);
extern int of_bsn_tlv_internal_gateway_mac_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_internal_gateway_mac_t *obj, int value);

extern int of_bsn_tlv_internal_mac_OF_VERSION_1_4_populate(
    of_bsn_tlv_internal_mac_t *obj, int value);
extern int of_bsn_tlv_internal_mac_OF_VERSION_1_4_check(
    of_bsn_tlv_internal_mac_t *obj, int value);
extern int of_bsn_tlv_internal_mac_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_internal_mac_t *obj, int value);
extern int of_bsn_tlv_internal_mac_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_internal_mac_t *obj, int value);

extern int of_bsn_tlv_interval_OF_VERSION_1_4_populate(
    of_bsn_tlv_interval_t *obj, int value);
extern int of_bsn_tlv_interval_OF_VERSION_1_4_check(
    of_bsn_tlv_interval_t *obj, int value);
extern int of_bsn_tlv_interval_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_interval_t *obj, int value);
extern int of_bsn_tlv_interval_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_interval_t *obj, int value);

extern int of_bsn_tlv_ip_proto_OF_VERSION_1_4_populate(
    of_bsn_tlv_ip_proto_t *obj, int value);
extern int of_bsn_tlv_ip_proto_OF_VERSION_1_4_check(
    of_bsn_tlv_ip_proto_t *obj, int value);
extern int of_bsn_tlv_ip_proto_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_ip_proto_t *obj, int value);
extern int of_bsn_tlv_ip_proto_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_ip_proto_t *obj, int value);

extern int of_bsn_tlv_ipv4_OF_VERSION_1_4_populate(
    of_bsn_tlv_ipv4_t *obj, int value);
extern int of_bsn_tlv_ipv4_OF_VERSION_1_4_check(
    of_bsn_tlv_ipv4_t *obj, int value);
extern int of_bsn_tlv_ipv4_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_ipv4_t *obj, int value);
extern int of_bsn_tlv_ipv4_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_ipv4_t *obj, int value);

extern int of_bsn_tlv_ipv4_dst_OF_VERSION_1_4_populate(
    of_bsn_tlv_ipv4_dst_t *obj, int value);
extern int of_bsn_tlv_ipv4_dst_OF_VERSION_1_4_check(
    of_bsn_tlv_ipv4_dst_t *obj, int value);
extern int of_bsn_tlv_ipv4_dst_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_ipv4_dst_t *obj, int value);
extern int of_bsn_tlv_ipv4_dst_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_ipv4_dst_t *obj, int value);

extern int of_bsn_tlv_ipv4_netmask_OF_VERSION_1_4_populate(
    of_bsn_tlv_ipv4_netmask_t *obj, int value);
extern int of_bsn_tlv_ipv4_netmask_OF_VERSION_1_4_check(
    of_bsn_tlv_ipv4_netmask_t *obj, int value);
extern int of_bsn_tlv_ipv4_netmask_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_ipv4_netmask_t *obj, int value);
extern int of_bsn_tlv_ipv4_netmask_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_ipv4_netmask_t *obj, int value);

extern int of_bsn_tlv_ipv4_src_OF_VERSION_1_4_populate(
    of_bsn_tlv_ipv4_src_t *obj, int value);
extern int of_bsn_tlv_ipv4_src_OF_VERSION_1_4_check(
    of_bsn_tlv_ipv4_src_t *obj, int value);
extern int of_bsn_tlv_ipv4_src_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_ipv4_src_t *obj, int value);
extern int of_bsn_tlv_ipv4_src_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_ipv4_src_t *obj, int value);

extern int of_bsn_tlv_ipv6_OF_VERSION_1_4_populate(
    of_bsn_tlv_ipv6_t *obj, int value);
extern int of_bsn_tlv_ipv6_OF_VERSION_1_4_check(
    of_bsn_tlv_ipv6_t *obj, int value);
extern int of_bsn_tlv_ipv6_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_ipv6_t *obj, int value);
extern int of_bsn_tlv_ipv6_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_ipv6_t *obj, int value);

extern int of_bsn_tlv_ipv6_dst_OF_VERSION_1_4_populate(
    of_bsn_tlv_ipv6_dst_t *obj, int value);
extern int of_bsn_tlv_ipv6_dst_OF_VERSION_1_4_check(
    of_bsn_tlv_ipv6_dst_t *obj, int value);
extern int of_bsn_tlv_ipv6_dst_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_ipv6_dst_t *obj, int value);
extern int of_bsn_tlv_ipv6_dst_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_ipv6_dst_t *obj, int value);

extern int of_bsn_tlv_ipv6_prefix_OF_VERSION_1_4_populate(
    of_bsn_tlv_ipv6_prefix_t *obj, int value);
extern int of_bsn_tlv_ipv6_prefix_OF_VERSION_1_4_check(
    of_bsn_tlv_ipv6_prefix_t *obj, int value);
extern int of_bsn_tlv_ipv6_prefix_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_ipv6_prefix_t *obj, int value);
extern int of_bsn_tlv_ipv6_prefix_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_ipv6_prefix_t *obj, int value);

extern int of_bsn_tlv_ipv6_src_OF_VERSION_1_4_populate(
    of_bsn_tlv_ipv6_src_t *obj, int value);
extern int of_bsn_tlv_ipv6_src_OF_VERSION_1_4_check(
    of_bsn_tlv_ipv6_src_t *obj, int value);
extern int of_bsn_tlv_ipv6_src_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_ipv6_src_t *obj, int value);
extern int of_bsn_tlv_ipv6_src_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_ipv6_src_t *obj, int value);

extern int of_bsn_tlv_known_multicast_rate_OF_VERSION_1_4_populate(
    of_bsn_tlv_known_multicast_rate_t *obj, int value);
extern int of_bsn_tlv_known_multicast_rate_OF_VERSION_1_4_check(
    of_bsn_tlv_known_multicast_rate_t *obj, int value);
extern int of_bsn_tlv_known_multicast_rate_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_known_multicast_rate_t *obj, int value);
extern int of_bsn_tlv_known_multicast_rate_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_known_multicast_rate_t *obj, int value);

extern int of_bsn_tlv_l2_multicast_lookup_OF_VERSION_1_4_populate(
    of_bsn_tlv_l2_multicast_lookup_t *obj, int value);
extern int of_bsn_tlv_l2_multicast_lookup_OF_VERSION_1_4_check(
    of_bsn_tlv_l2_multicast_lookup_t *obj, int value);
extern int of_bsn_tlv_l2_multicast_lookup_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_l2_multicast_lookup_t *obj, int value);
extern int of_bsn_tlv_l2_multicast_lookup_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_l2_multicast_lookup_t *obj, int value);

extern int of_bsn_tlv_l3_dst_class_id_OF_VERSION_1_4_populate(
    of_bsn_tlv_l3_dst_class_id_t *obj, int value);
extern int of_bsn_tlv_l3_dst_class_id_OF_VERSION_1_4_check(
    of_bsn_tlv_l3_dst_class_id_t *obj, int value);
extern int of_bsn_tlv_l3_dst_class_id_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_l3_dst_class_id_t *obj, int value);
extern int of_bsn_tlv_l3_dst_class_id_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_l3_dst_class_id_t *obj, int value);

extern int of_bsn_tlv_l3_interface_class_id_OF_VERSION_1_4_populate(
    of_bsn_tlv_l3_interface_class_id_t *obj, int value);
extern int of_bsn_tlv_l3_interface_class_id_OF_VERSION_1_4_check(
    of_bsn_tlv_l3_interface_class_id_t *obj, int value);
extern int of_bsn_tlv_l3_interface_class_id_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_l3_interface_class_id_t *obj, int value);
extern int of_bsn_tlv_l3_interface_class_id_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_l3_interface_class_id_t *obj, int value);

extern int of_bsn_tlv_l3_src_class_id_OF_VERSION_1_4_populate(
    of_bsn_tlv_l3_src_class_id_t *obj, int value);
extern int of_bsn_tlv_l3_src_class_id_OF_VERSION_1_4_check(
    of_bsn_tlv_l3_src_class_id_t *obj, int value);
extern int of_bsn_tlv_l3_src_class_id_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_l3_src_class_id_t *obj, int value);
extern int of_bsn_tlv_l3_src_class_id_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_l3_src_class_id_t *obj, int value);

extern int of_bsn_tlv_lag_options_OF_VERSION_1_4_populate(
    of_bsn_tlv_lag_options_t *obj, int value);
extern int of_bsn_tlv_lag_options_OF_VERSION_1_4_check(
    of_bsn_tlv_lag_options_t *obj, int value);
extern int of_bsn_tlv_lag_options_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_lag_options_t *obj, int value);
extern int of_bsn_tlv_lag_options_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_lag_options_t *obj, int value);

extern int of_bsn_tlv_loopback_mode_OF_VERSION_1_4_populate(
    of_bsn_tlv_loopback_mode_t *obj, int value);
extern int of_bsn_tlv_loopback_mode_OF_VERSION_1_4_check(
    of_bsn_tlv_loopback_mode_t *obj, int value);
extern int of_bsn_tlv_loopback_mode_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_loopback_mode_t *obj, int value);
extern int of_bsn_tlv_loopback_mode_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_loopback_mode_t *obj, int value);

extern int of_bsn_tlv_loopback_port_OF_VERSION_1_4_populate(
    of_bsn_tlv_loopback_port_t *obj, int value);
extern int of_bsn_tlv_loopback_port_OF_VERSION_1_4_check(
    of_bsn_tlv_loopback_port_t *obj, int value);
extern int of_bsn_tlv_loopback_port_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_loopback_port_t *obj, int value);
extern int of_bsn_tlv_loopback_port_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_loopback_port_t *obj, int value);

extern int of_bsn_tlv_mac_OF_VERSION_1_4_populate(
    of_bsn_tlv_mac_t *obj, int value);
extern int of_bsn_tlv_mac_OF_VERSION_1_4_check(
    of_bsn_tlv_mac_t *obj, int value);
extern int of_bsn_tlv_mac_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_mac_t *obj, int value);
extern int of_bsn_tlv_mac_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_mac_t *obj, int value);

extern int of_bsn_tlv_mac_mask_OF_VERSION_1_4_populate(
    of_bsn_tlv_mac_mask_t *obj, int value);
extern int of_bsn_tlv_mac_mask_OF_VERSION_1_4_check(
    of_bsn_tlv_mac_mask_t *obj, int value);
extern int of_bsn_tlv_mac_mask_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_mac_mask_t *obj, int value);
extern int of_bsn_tlv_mac_mask_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_mac_mask_t *obj, int value);

extern int of_bsn_tlv_mcg_type_vxlan_OF_VERSION_1_4_populate(
    of_bsn_tlv_mcg_type_vxlan_t *obj, int value);
extern int of_bsn_tlv_mcg_type_vxlan_OF_VERSION_1_4_check(
    of_bsn_tlv_mcg_type_vxlan_t *obj, int value);
extern int of_bsn_tlv_mcg_type_vxlan_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_mcg_type_vxlan_t *obj, int value);
extern int of_bsn_tlv_mcg_type_vxlan_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_mcg_type_vxlan_t *obj, int value);

extern int of_bsn_tlv_miss_packets_OF_VERSION_1_4_populate(
    of_bsn_tlv_miss_packets_t *obj, int value);
extern int of_bsn_tlv_miss_packets_OF_VERSION_1_4_check(
    of_bsn_tlv_miss_packets_t *obj, int value);
extern int of_bsn_tlv_miss_packets_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_miss_packets_t *obj, int value);
extern int of_bsn_tlv_miss_packets_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_miss_packets_t *obj, int value);

extern int of_bsn_tlv_mpls_control_word_OF_VERSION_1_4_populate(
    of_bsn_tlv_mpls_control_word_t *obj, int value);
extern int of_bsn_tlv_mpls_control_word_OF_VERSION_1_4_check(
    of_bsn_tlv_mpls_control_word_t *obj, int value);
extern int of_bsn_tlv_mpls_control_word_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_mpls_control_word_t *obj, int value);
extern int of_bsn_tlv_mpls_control_word_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_mpls_control_word_t *obj, int value);

extern int of_bsn_tlv_mpls_label_OF_VERSION_1_4_populate(
    of_bsn_tlv_mpls_label_t *obj, int value);
extern int of_bsn_tlv_mpls_label_OF_VERSION_1_4_check(
    of_bsn_tlv_mpls_label_t *obj, int value);
extern int of_bsn_tlv_mpls_label_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_mpls_label_t *obj, int value);
extern int of_bsn_tlv_mpls_label_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_mpls_label_t *obj, int value);

extern int of_bsn_tlv_mpls_sequenced_OF_VERSION_1_4_populate(
    of_bsn_tlv_mpls_sequenced_t *obj, int value);
extern int of_bsn_tlv_mpls_sequenced_OF_VERSION_1_4_check(
    of_bsn_tlv_mpls_sequenced_t *obj, int value);
extern int of_bsn_tlv_mpls_sequenced_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_mpls_sequenced_t *obj, int value);
extern int of_bsn_tlv_mpls_sequenced_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_mpls_sequenced_t *obj, int value);

extern int of_bsn_tlv_multicast_interface_id_OF_VERSION_1_4_populate(
    of_bsn_tlv_multicast_interface_id_t *obj, int value);
extern int of_bsn_tlv_multicast_interface_id_OF_VERSION_1_4_check(
    of_bsn_tlv_multicast_interface_id_t *obj, int value);
extern int of_bsn_tlv_multicast_interface_id_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_multicast_interface_id_t *obj, int value);
extern int of_bsn_tlv_multicast_interface_id_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_multicast_interface_id_t *obj, int value);

extern int of_bsn_tlv_name_OF_VERSION_1_4_populate(
    of_bsn_tlv_name_t *obj, int value);
extern int of_bsn_tlv_name_OF_VERSION_1_4_check(
    of_bsn_tlv_name_t *obj, int value);
extern int of_bsn_tlv_name_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_name_t *obj, int value);
extern int of_bsn_tlv_name_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_name_t *obj, int value);

extern int of_bsn_tlv_ndp_offload_OF_VERSION_1_4_populate(
    of_bsn_tlv_ndp_offload_t *obj, int value);
extern int of_bsn_tlv_ndp_offload_OF_VERSION_1_4_check(
    of_bsn_tlv_ndp_offload_t *obj, int value);
extern int of_bsn_tlv_ndp_offload_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_ndp_offload_t *obj, int value);
extern int of_bsn_tlv_ndp_offload_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_ndp_offload_t *obj, int value);

extern int of_bsn_tlv_ndp_static_OF_VERSION_1_4_populate(
    of_bsn_tlv_ndp_static_t *obj, int value);
extern int of_bsn_tlv_ndp_static_OF_VERSION_1_4_check(
    of_bsn_tlv_ndp_static_t *obj, int value);
extern int of_bsn_tlv_ndp_static_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_ndp_static_t *obj, int value);
extern int of_bsn_tlv_ndp_static_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_ndp_static_t *obj, int value);

extern int of_bsn_tlv_negate_OF_VERSION_1_4_populate(
    of_bsn_tlv_negate_t *obj, int value);
extern int of_bsn_tlv_negate_OF_VERSION_1_4_check(
    of_bsn_tlv_negate_t *obj, int value);
extern int of_bsn_tlv_negate_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_negate_t *obj, int value);
extern int of_bsn_tlv_negate_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_negate_t *obj, int value);

extern int of_bsn_tlv_next_hop_ipv4_OF_VERSION_1_4_populate(
    of_bsn_tlv_next_hop_ipv4_t *obj, int value);
extern int of_bsn_tlv_next_hop_ipv4_OF_VERSION_1_4_check(
    of_bsn_tlv_next_hop_ipv4_t *obj, int value);
extern int of_bsn_tlv_next_hop_ipv4_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_next_hop_ipv4_t *obj, int value);
extern int of_bsn_tlv_next_hop_ipv4_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_next_hop_ipv4_t *obj, int value);

extern int of_bsn_tlv_next_hop_mac_OF_VERSION_1_4_populate(
    of_bsn_tlv_next_hop_mac_t *obj, int value);
extern int of_bsn_tlv_next_hop_mac_OF_VERSION_1_4_check(
    of_bsn_tlv_next_hop_mac_t *obj, int value);
extern int of_bsn_tlv_next_hop_mac_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_next_hop_mac_t *obj, int value);
extern int of_bsn_tlv_next_hop_mac_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_next_hop_mac_t *obj, int value);

extern int of_bsn_tlv_nexthop_type_vxlan_OF_VERSION_1_4_populate(
    of_bsn_tlv_nexthop_type_vxlan_t *obj, int value);
extern int of_bsn_tlv_nexthop_type_vxlan_OF_VERSION_1_4_check(
    of_bsn_tlv_nexthop_type_vxlan_t *obj, int value);
extern int of_bsn_tlv_nexthop_type_vxlan_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_nexthop_type_vxlan_t *obj, int value);
extern int of_bsn_tlv_nexthop_type_vxlan_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_nexthop_type_vxlan_t *obj, int value);

extern int of_bsn_tlv_no_arp_response_OF_VERSION_1_4_populate(
    of_bsn_tlv_no_arp_response_t *obj, int value);
extern int of_bsn_tlv_no_arp_response_OF_VERSION_1_4_check(
    of_bsn_tlv_no_arp_response_t *obj, int value);
extern int of_bsn_tlv_no_arp_response_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_no_arp_response_t *obj, int value);
extern int of_bsn_tlv_no_arp_response_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_no_arp_response_t *obj, int value);

extern int of_bsn_tlv_no_ns_response_OF_VERSION_1_4_populate(
    of_bsn_tlv_no_ns_response_t *obj, int value);
extern int of_bsn_tlv_no_ns_response_OF_VERSION_1_4_check(
    of_bsn_tlv_no_ns_response_t *obj, int value);
extern int of_bsn_tlv_no_ns_response_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_no_ns_response_t *obj, int value);
extern int of_bsn_tlv_no_ns_response_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_no_ns_response_t *obj, int value);

extern int of_bsn_tlv_offset_OF_VERSION_1_4_populate(
    of_bsn_tlv_offset_t *obj, int value);
extern int of_bsn_tlv_offset_OF_VERSION_1_4_check(
    of_bsn_tlv_offset_t *obj, int value);
extern int of_bsn_tlv_offset_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_offset_t *obj, int value);
extern int of_bsn_tlv_offset_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_offset_t *obj, int value);

extern int of_bsn_tlv_optics_always_enabled_OF_VERSION_1_4_populate(
    of_bsn_tlv_optics_always_enabled_t *obj, int value);
extern int of_bsn_tlv_optics_always_enabled_OF_VERSION_1_4_check(
    of_bsn_tlv_optics_always_enabled_t *obj, int value);
extern int of_bsn_tlv_optics_always_enabled_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_optics_always_enabled_t *obj, int value);
extern int of_bsn_tlv_optics_always_enabled_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_optics_always_enabled_t *obj, int value);

extern int of_bsn_tlv_outer_src_mac_OF_VERSION_1_4_populate(
    of_bsn_tlv_outer_src_mac_t *obj, int value);
extern int of_bsn_tlv_outer_src_mac_OF_VERSION_1_4_check(
    of_bsn_tlv_outer_src_mac_t *obj, int value);
extern int of_bsn_tlv_outer_src_mac_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_outer_src_mac_t *obj, int value);
extern int of_bsn_tlv_outer_src_mac_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_outer_src_mac_t *obj, int value);

extern int of_bsn_tlv_parent_port_OF_VERSION_1_4_populate(
    of_bsn_tlv_parent_port_t *obj, int value);
extern int of_bsn_tlv_parent_port_OF_VERSION_1_4_check(
    of_bsn_tlv_parent_port_t *obj, int value);
extern int of_bsn_tlv_parent_port_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_parent_port_t *obj, int value);
extern int of_bsn_tlv_parent_port_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_parent_port_t *obj, int value);

extern int of_bsn_tlv_partner_key_OF_VERSION_1_4_populate(
    of_bsn_tlv_partner_key_t *obj, int value);
extern int of_bsn_tlv_partner_key_OF_VERSION_1_4_check(
    of_bsn_tlv_partner_key_t *obj, int value);
extern int of_bsn_tlv_partner_key_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_partner_key_t *obj, int value);
extern int of_bsn_tlv_partner_key_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_partner_key_t *obj, int value);

extern int of_bsn_tlv_partner_port_num_OF_VERSION_1_4_populate(
    of_bsn_tlv_partner_port_num_t *obj, int value);
extern int of_bsn_tlv_partner_port_num_OF_VERSION_1_4_check(
    of_bsn_tlv_partner_port_num_t *obj, int value);
extern int of_bsn_tlv_partner_port_num_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_partner_port_num_t *obj, int value);
extern int of_bsn_tlv_partner_port_num_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_partner_port_num_t *obj, int value);

extern int of_bsn_tlv_partner_port_priority_OF_VERSION_1_4_populate(
    of_bsn_tlv_partner_port_priority_t *obj, int value);
extern int of_bsn_tlv_partner_port_priority_OF_VERSION_1_4_check(
    of_bsn_tlv_partner_port_priority_t *obj, int value);
extern int of_bsn_tlv_partner_port_priority_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_partner_port_priority_t *obj, int value);
extern int of_bsn_tlv_partner_port_priority_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_partner_port_priority_t *obj, int value);

extern int of_bsn_tlv_partner_state_OF_VERSION_1_4_populate(
    of_bsn_tlv_partner_state_t *obj, int value);
extern int of_bsn_tlv_partner_state_OF_VERSION_1_4_check(
    of_bsn_tlv_partner_state_t *obj, int value);
extern int of_bsn_tlv_partner_state_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_partner_state_t *obj, int value);
extern int of_bsn_tlv_partner_state_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_partner_state_t *obj, int value);

extern int of_bsn_tlv_partner_system_mac_OF_VERSION_1_4_populate(
    of_bsn_tlv_partner_system_mac_t *obj, int value);
extern int of_bsn_tlv_partner_system_mac_OF_VERSION_1_4_check(
    of_bsn_tlv_partner_system_mac_t *obj, int value);
extern int of_bsn_tlv_partner_system_mac_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_partner_system_mac_t *obj, int value);
extern int of_bsn_tlv_partner_system_mac_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_partner_system_mac_t *obj, int value);

extern int of_bsn_tlv_partner_system_priority_OF_VERSION_1_4_populate(
    of_bsn_tlv_partner_system_priority_t *obj, int value);
extern int of_bsn_tlv_partner_system_priority_OF_VERSION_1_4_check(
    of_bsn_tlv_partner_system_priority_t *obj, int value);
extern int of_bsn_tlv_partner_system_priority_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_partner_system_priority_t *obj, int value);
extern int of_bsn_tlv_partner_system_priority_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_partner_system_priority_t *obj, int value);

extern int of_bsn_tlv_pdua_rx_instance_OF_VERSION_1_4_populate(
    of_bsn_tlv_pdua_rx_instance_t *obj, int value);
extern int of_bsn_tlv_pdua_rx_instance_OF_VERSION_1_4_check(
    of_bsn_tlv_pdua_rx_instance_t *obj, int value);
extern int of_bsn_tlv_pdua_rx_instance_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_pdua_rx_instance_t *obj, int value);
extern int of_bsn_tlv_pdua_rx_instance_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_pdua_rx_instance_t *obj, int value);

extern int of_bsn_tlv_port_OF_VERSION_1_4_populate(
    of_bsn_tlv_port_t *obj, int value);
extern int of_bsn_tlv_port_OF_VERSION_1_4_check(
    of_bsn_tlv_port_t *obj, int value);
extern int of_bsn_tlv_port_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_port_t *obj, int value);
extern int of_bsn_tlv_port_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_port_t *obj, int value);

extern int of_bsn_tlv_port_speed_gbps_OF_VERSION_1_4_populate(
    of_bsn_tlv_port_speed_gbps_t *obj, int value);
extern int of_bsn_tlv_port_speed_gbps_OF_VERSION_1_4_check(
    of_bsn_tlv_port_speed_gbps_t *obj, int value);
extern int of_bsn_tlv_port_speed_gbps_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_port_speed_gbps_t *obj, int value);
extern int of_bsn_tlv_port_speed_gbps_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_port_speed_gbps_t *obj, int value);

extern int of_bsn_tlv_port_usage_OF_VERSION_1_4_populate(
    of_bsn_tlv_port_usage_t *obj, int value);
extern int of_bsn_tlv_port_usage_OF_VERSION_1_4_check(
    of_bsn_tlv_port_usage_t *obj, int value);
extern int of_bsn_tlv_port_usage_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_port_usage_t *obj, int value);
extern int of_bsn_tlv_port_usage_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_port_usage_t *obj, int value);

extern int of_bsn_tlv_port_vxlan_mode_OF_VERSION_1_4_populate(
    of_bsn_tlv_port_vxlan_mode_t *obj, int value);
extern int of_bsn_tlv_port_vxlan_mode_OF_VERSION_1_4_check(
    of_bsn_tlv_port_vxlan_mode_t *obj, int value);
extern int of_bsn_tlv_port_vxlan_mode_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_port_vxlan_mode_t *obj, int value);
extern int of_bsn_tlv_port_vxlan_mode_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_port_vxlan_mode_t *obj, int value);

extern int of_bsn_tlv_priority_OF_VERSION_1_4_populate(
    of_bsn_tlv_priority_t *obj, int value);
extern int of_bsn_tlv_priority_OF_VERSION_1_4_check(
    of_bsn_tlv_priority_t *obj, int value);
extern int of_bsn_tlv_priority_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_priority_t *obj, int value);
extern int of_bsn_tlv_priority_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_priority_t *obj, int value);

extern int of_bsn_tlv_push_vlan_on_ingress_OF_VERSION_1_4_populate(
    of_bsn_tlv_push_vlan_on_ingress_t *obj, int value);
extern int of_bsn_tlv_push_vlan_on_ingress_OF_VERSION_1_4_check(
    of_bsn_tlv_push_vlan_on_ingress_t *obj, int value);
extern int of_bsn_tlv_push_vlan_on_ingress_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_push_vlan_on_ingress_t *obj, int value);
extern int of_bsn_tlv_push_vlan_on_ingress_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_push_vlan_on_ingress_t *obj, int value);

extern int of_bsn_tlv_qos_priority_OF_VERSION_1_4_populate(
    of_bsn_tlv_qos_priority_t *obj, int value);
extern int of_bsn_tlv_qos_priority_OF_VERSION_1_4_check(
    of_bsn_tlv_qos_priority_t *obj, int value);
extern int of_bsn_tlv_qos_priority_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_qos_priority_t *obj, int value);
extern int of_bsn_tlv_qos_priority_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_qos_priority_t *obj, int value);

extern int of_bsn_tlv_queue_id_OF_VERSION_1_4_populate(
    of_bsn_tlv_queue_id_t *obj, int value);
extern int of_bsn_tlv_queue_id_OF_VERSION_1_4_check(
    of_bsn_tlv_queue_id_t *obj, int value);
extern int of_bsn_tlv_queue_id_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_queue_id_t *obj, int value);
extern int of_bsn_tlv_queue_id_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_queue_id_t *obj, int value);

extern int of_bsn_tlv_queue_weight_OF_VERSION_1_4_populate(
    of_bsn_tlv_queue_weight_t *obj, int value);
extern int of_bsn_tlv_queue_weight_OF_VERSION_1_4_check(
    of_bsn_tlv_queue_weight_t *obj, int value);
extern int of_bsn_tlv_queue_weight_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_queue_weight_t *obj, int value);
extern int of_bsn_tlv_queue_weight_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_queue_weight_t *obj, int value);

extern int of_bsn_tlv_rate_limit_OF_VERSION_1_4_populate(
    of_bsn_tlv_rate_limit_t *obj, int value);
extern int of_bsn_tlv_rate_limit_OF_VERSION_1_4_check(
    of_bsn_tlv_rate_limit_t *obj, int value);
extern int of_bsn_tlv_rate_limit_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_rate_limit_t *obj, int value);
extern int of_bsn_tlv_rate_limit_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_rate_limit_t *obj, int value);

extern int of_bsn_tlv_rate_unit_OF_VERSION_1_4_populate(
    of_bsn_tlv_rate_unit_t *obj, int value);
extern int of_bsn_tlv_rate_unit_OF_VERSION_1_4_check(
    of_bsn_tlv_rate_unit_t *obj, int value);
extern int of_bsn_tlv_rate_unit_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_rate_unit_t *obj, int value);
extern int of_bsn_tlv_rate_unit_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_rate_unit_t *obj, int value);

extern int of_bsn_tlv_record_packets_OF_VERSION_1_4_populate(
    of_bsn_tlv_record_packets_t *obj, int value);
extern int of_bsn_tlv_record_packets_OF_VERSION_1_4_check(
    of_bsn_tlv_record_packets_t *obj, int value);
extern int of_bsn_tlv_record_packets_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_record_packets_t *obj, int value);
extern int of_bsn_tlv_record_packets_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_record_packets_t *obj, int value);

extern int of_bsn_tlv_reference_OF_VERSION_1_4_populate(
    of_bsn_tlv_reference_t *obj, int value);
extern int of_bsn_tlv_reference_OF_VERSION_1_4_check(
    of_bsn_tlv_reference_t *obj, int value);
extern int of_bsn_tlv_reference_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_reference_t *obj, int value);
extern int of_bsn_tlv_reference_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_reference_t *obj, int value);

extern int of_bsn_tlv_reply_packets_OF_VERSION_1_4_populate(
    of_bsn_tlv_reply_packets_t *obj, int value);
extern int of_bsn_tlv_reply_packets_OF_VERSION_1_4_check(
    of_bsn_tlv_reply_packets_t *obj, int value);
extern int of_bsn_tlv_reply_packets_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_reply_packets_t *obj, int value);
extern int of_bsn_tlv_reply_packets_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_reply_packets_t *obj, int value);

extern int of_bsn_tlv_request_packets_OF_VERSION_1_4_populate(
    of_bsn_tlv_request_packets_t *obj, int value);
extern int of_bsn_tlv_request_packets_OF_VERSION_1_4_check(
    of_bsn_tlv_request_packets_t *obj, int value);
extern int of_bsn_tlv_request_packets_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_request_packets_t *obj, int value);
extern int of_bsn_tlv_request_packets_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_request_packets_t *obj, int value);

extern int of_bsn_tlv_rest_server_OF_VERSION_1_4_populate(
    of_bsn_tlv_rest_server_t *obj, int value);
extern int of_bsn_tlv_rest_server_OF_VERSION_1_4_check(
    of_bsn_tlv_rest_server_t *obj, int value);
extern int of_bsn_tlv_rest_server_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_rest_server_t *obj, int value);
extern int of_bsn_tlv_rest_server_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_rest_server_t *obj, int value);

extern int of_bsn_tlv_routing_param_OF_VERSION_1_4_populate(
    of_bsn_tlv_routing_param_t *obj, int value);
extern int of_bsn_tlv_routing_param_OF_VERSION_1_4_check(
    of_bsn_tlv_routing_param_t *obj, int value);
extern int of_bsn_tlv_routing_param_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_routing_param_t *obj, int value);
extern int of_bsn_tlv_routing_param_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_routing_param_t *obj, int value);

extern int of_bsn_tlv_rx_bytes_OF_VERSION_1_4_populate(
    of_bsn_tlv_rx_bytes_t *obj, int value);
extern int of_bsn_tlv_rx_bytes_OF_VERSION_1_4_check(
    of_bsn_tlv_rx_bytes_t *obj, int value);
extern int of_bsn_tlv_rx_bytes_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_rx_bytes_t *obj, int value);
extern int of_bsn_tlv_rx_bytes_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_rx_bytes_t *obj, int value);

extern int of_bsn_tlv_rx_packets_OF_VERSION_1_4_populate(
    of_bsn_tlv_rx_packets_t *obj, int value);
extern int of_bsn_tlv_rx_packets_OF_VERSION_1_4_check(
    of_bsn_tlv_rx_packets_t *obj, int value);
extern int of_bsn_tlv_rx_packets_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_rx_packets_t *obj, int value);
extern int of_bsn_tlv_rx_packets_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_rx_packets_t *obj, int value);

extern int of_bsn_tlv_sampling_rate_OF_VERSION_1_4_populate(
    of_bsn_tlv_sampling_rate_t *obj, int value);
extern int of_bsn_tlv_sampling_rate_OF_VERSION_1_4_check(
    of_bsn_tlv_sampling_rate_t *obj, int value);
extern int of_bsn_tlv_sampling_rate_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_sampling_rate_t *obj, int value);
extern int of_bsn_tlv_sampling_rate_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_sampling_rate_t *obj, int value);

extern int of_bsn_tlv_set_loopback_mode_OF_VERSION_1_4_populate(
    of_bsn_tlv_set_loopback_mode_t *obj, int value);
extern int of_bsn_tlv_set_loopback_mode_OF_VERSION_1_4_check(
    of_bsn_tlv_set_loopback_mode_t *obj, int value);
extern int of_bsn_tlv_set_loopback_mode_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_set_loopback_mode_t *obj, int value);
extern int of_bsn_tlv_set_loopback_mode_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_set_loopback_mode_t *obj, int value);

extern int of_bsn_tlv_status_OF_VERSION_1_4_populate(
    of_bsn_tlv_status_t *obj, int value);
extern int of_bsn_tlv_status_OF_VERSION_1_4_check(
    of_bsn_tlv_status_t *obj, int value);
extern int of_bsn_tlv_status_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_status_t *obj, int value);
extern int of_bsn_tlv_status_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_status_t *obj, int value);

extern int of_bsn_tlv_strip_mpls_l2_on_ingress_OF_VERSION_1_4_populate(
    of_bsn_tlv_strip_mpls_l2_on_ingress_t *obj, int value);
extern int of_bsn_tlv_strip_mpls_l2_on_ingress_OF_VERSION_1_4_check(
    of_bsn_tlv_strip_mpls_l2_on_ingress_t *obj, int value);
extern int of_bsn_tlv_strip_mpls_l2_on_ingress_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_strip_mpls_l2_on_ingress_t *obj, int value);
extern int of_bsn_tlv_strip_mpls_l2_on_ingress_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_strip_mpls_l2_on_ingress_t *obj, int value);

extern int of_bsn_tlv_strip_mpls_l3_on_ingress_OF_VERSION_1_4_populate(
    of_bsn_tlv_strip_mpls_l3_on_ingress_t *obj, int value);
extern int of_bsn_tlv_strip_mpls_l3_on_ingress_OF_VERSION_1_4_check(
    of_bsn_tlv_strip_mpls_l3_on_ingress_t *obj, int value);
extern int of_bsn_tlv_strip_mpls_l3_on_ingress_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_strip_mpls_l3_on_ingress_t *obj, int value);
extern int of_bsn_tlv_strip_mpls_l3_on_ingress_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_strip_mpls_l3_on_ingress_t *obj, int value);

extern int of_bsn_tlv_strip_vlan_on_egress_OF_VERSION_1_4_populate(
    of_bsn_tlv_strip_vlan_on_egress_t *obj, int value);
extern int of_bsn_tlv_strip_vlan_on_egress_OF_VERSION_1_4_check(
    of_bsn_tlv_strip_vlan_on_egress_t *obj, int value);
extern int of_bsn_tlv_strip_vlan_on_egress_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_strip_vlan_on_egress_t *obj, int value);
extern int of_bsn_tlv_strip_vlan_on_egress_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_strip_vlan_on_egress_t *obj, int value);

extern int of_bsn_tlv_sub_agent_id_OF_VERSION_1_4_populate(
    of_bsn_tlv_sub_agent_id_t *obj, int value);
extern int of_bsn_tlv_sub_agent_id_OF_VERSION_1_4_check(
    of_bsn_tlv_sub_agent_id_t *obj, int value);
extern int of_bsn_tlv_sub_agent_id_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_sub_agent_id_t *obj, int value);
extern int of_bsn_tlv_sub_agent_id_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_sub_agent_id_t *obj, int value);

extern int of_bsn_tlv_tcp_dst_OF_VERSION_1_4_populate(
    of_bsn_tlv_tcp_dst_t *obj, int value);
extern int of_bsn_tlv_tcp_dst_OF_VERSION_1_4_check(
    of_bsn_tlv_tcp_dst_t *obj, int value);
extern int of_bsn_tlv_tcp_dst_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_tcp_dst_t *obj, int value);
extern int of_bsn_tlv_tcp_dst_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_tcp_dst_t *obj, int value);

extern int of_bsn_tlv_tcp_flags_OF_VERSION_1_4_populate(
    of_bsn_tlv_tcp_flags_t *obj, int value);
extern int of_bsn_tlv_tcp_flags_OF_VERSION_1_4_check(
    of_bsn_tlv_tcp_flags_t *obj, int value);
extern int of_bsn_tlv_tcp_flags_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_tcp_flags_t *obj, int value);
extern int of_bsn_tlv_tcp_flags_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_tcp_flags_t *obj, int value);

extern int of_bsn_tlv_tcp_src_OF_VERSION_1_4_populate(
    of_bsn_tlv_tcp_src_t *obj, int value);
extern int of_bsn_tlv_tcp_src_OF_VERSION_1_4_check(
    of_bsn_tlv_tcp_src_t *obj, int value);
extern int of_bsn_tlv_tcp_src_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_tcp_src_t *obj, int value);
extern int of_bsn_tlv_tcp_src_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_tcp_src_t *obj, int value);

extern int of_bsn_tlv_timestamp_OF_VERSION_1_4_populate(
    of_bsn_tlv_timestamp_t *obj, int value);
extern int of_bsn_tlv_timestamp_OF_VERSION_1_4_check(
    of_bsn_tlv_timestamp_t *obj, int value);
extern int of_bsn_tlv_timestamp_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_timestamp_t *obj, int value);
extern int of_bsn_tlv_timestamp_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_timestamp_t *obj, int value);

extern int of_bsn_tlv_ttl_OF_VERSION_1_4_populate(
    of_bsn_tlv_ttl_t *obj, int value);
extern int of_bsn_tlv_ttl_OF_VERSION_1_4_check(
    of_bsn_tlv_ttl_t *obj, int value);
extern int of_bsn_tlv_ttl_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_ttl_t *obj, int value);
extern int of_bsn_tlv_ttl_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_ttl_t *obj, int value);

extern int of_bsn_tlv_tunnel_capability_OF_VERSION_1_4_populate(
    of_bsn_tlv_tunnel_capability_t *obj, int value);
extern int of_bsn_tlv_tunnel_capability_OF_VERSION_1_4_check(
    of_bsn_tlv_tunnel_capability_t *obj, int value);
extern int of_bsn_tlv_tunnel_capability_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_tunnel_capability_t *obj, int value);
extern int of_bsn_tlv_tunnel_capability_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_tunnel_capability_t *obj, int value);

extern int of_bsn_tlv_tx_bytes_OF_VERSION_1_4_populate(
    of_bsn_tlv_tx_bytes_t *obj, int value);
extern int of_bsn_tlv_tx_bytes_OF_VERSION_1_4_check(
    of_bsn_tlv_tx_bytes_t *obj, int value);
extern int of_bsn_tlv_tx_bytes_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_tx_bytes_t *obj, int value);
extern int of_bsn_tlv_tx_bytes_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_tx_bytes_t *obj, int value);

extern int of_bsn_tlv_tx_packets_OF_VERSION_1_4_populate(
    of_bsn_tlv_tx_packets_t *obj, int value);
extern int of_bsn_tlv_tx_packets_OF_VERSION_1_4_check(
    of_bsn_tlv_tx_packets_t *obj, int value);
extern int of_bsn_tlv_tx_packets_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_tx_packets_t *obj, int value);
extern int of_bsn_tlv_tx_packets_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_tx_packets_t *obj, int value);

extern int of_bsn_tlv_udf_anchor_OF_VERSION_1_4_populate(
    of_bsn_tlv_udf_anchor_t *obj, int value);
extern int of_bsn_tlv_udf_anchor_OF_VERSION_1_4_check(
    of_bsn_tlv_udf_anchor_t *obj, int value);
extern int of_bsn_tlv_udf_anchor_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_udf_anchor_t *obj, int value);
extern int of_bsn_tlv_udf_anchor_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_udf_anchor_t *obj, int value);

extern int of_bsn_tlv_udf_id_OF_VERSION_1_4_populate(
    of_bsn_tlv_udf_id_t *obj, int value);
extern int of_bsn_tlv_udf_id_OF_VERSION_1_4_check(
    of_bsn_tlv_udf_id_t *obj, int value);
extern int of_bsn_tlv_udf_id_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_udf_id_t *obj, int value);
extern int of_bsn_tlv_udf_id_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_udf_id_t *obj, int value);

extern int of_bsn_tlv_udf_length_OF_VERSION_1_4_populate(
    of_bsn_tlv_udf_length_t *obj, int value);
extern int of_bsn_tlv_udf_length_OF_VERSION_1_4_check(
    of_bsn_tlv_udf_length_t *obj, int value);
extern int of_bsn_tlv_udf_length_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_udf_length_t *obj, int value);
extern int of_bsn_tlv_udf_length_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_udf_length_t *obj, int value);

extern int of_bsn_tlv_udf_offset_OF_VERSION_1_4_populate(
    of_bsn_tlv_udf_offset_t *obj, int value);
extern int of_bsn_tlv_udf_offset_OF_VERSION_1_4_check(
    of_bsn_tlv_udf_offset_t *obj, int value);
extern int of_bsn_tlv_udf_offset_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_udf_offset_t *obj, int value);
extern int of_bsn_tlv_udf_offset_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_udf_offset_t *obj, int value);

extern int of_bsn_tlv_udp_dst_OF_VERSION_1_4_populate(
    of_bsn_tlv_udp_dst_t *obj, int value);
extern int of_bsn_tlv_udp_dst_OF_VERSION_1_4_check(
    of_bsn_tlv_udp_dst_t *obj, int value);
extern int of_bsn_tlv_udp_dst_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_udp_dst_t *obj, int value);
extern int of_bsn_tlv_udp_dst_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_udp_dst_t *obj, int value);

extern int of_bsn_tlv_udp_src_OF_VERSION_1_4_populate(
    of_bsn_tlv_udp_src_t *obj, int value);
extern int of_bsn_tlv_udp_src_OF_VERSION_1_4_check(
    of_bsn_tlv_udp_src_t *obj, int value);
extern int of_bsn_tlv_udp_src_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_udp_src_t *obj, int value);
extern int of_bsn_tlv_udp_src_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_udp_src_t *obj, int value);

extern int of_bsn_tlv_uint64_list_OF_VERSION_1_4_populate(
    of_bsn_tlv_uint64_list_t *obj, int value);
extern int of_bsn_tlv_uint64_list_OF_VERSION_1_4_check(
    of_bsn_tlv_uint64_list_t *obj, int value);
extern int of_bsn_tlv_uint64_list_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_uint64_list_t *obj, int value);
extern int of_bsn_tlv_uint64_list_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_uint64_list_t *obj, int value);

extern int of_bsn_tlv_unicast_query_timeout_OF_VERSION_1_4_populate(
    of_bsn_tlv_unicast_query_timeout_t *obj, int value);
extern int of_bsn_tlv_unicast_query_timeout_OF_VERSION_1_4_check(
    of_bsn_tlv_unicast_query_timeout_t *obj, int value);
extern int of_bsn_tlv_unicast_query_timeout_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_unicast_query_timeout_t *obj, int value);
extern int of_bsn_tlv_unicast_query_timeout_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_unicast_query_timeout_t *obj, int value);

extern int of_bsn_tlv_unicast_rate_OF_VERSION_1_4_populate(
    of_bsn_tlv_unicast_rate_t *obj, int value);
extern int of_bsn_tlv_unicast_rate_OF_VERSION_1_4_check(
    of_bsn_tlv_unicast_rate_t *obj, int value);
extern int of_bsn_tlv_unicast_rate_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_unicast_rate_t *obj, int value);
extern int of_bsn_tlv_unicast_rate_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_unicast_rate_t *obj, int value);

extern int of_bsn_tlv_unknown_multicast_rate_OF_VERSION_1_4_populate(
    of_bsn_tlv_unknown_multicast_rate_t *obj, int value);
extern int of_bsn_tlv_unknown_multicast_rate_OF_VERSION_1_4_check(
    of_bsn_tlv_unknown_multicast_rate_t *obj, int value);
extern int of_bsn_tlv_unknown_multicast_rate_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_unknown_multicast_rate_t *obj, int value);
extern int of_bsn_tlv_unknown_multicast_rate_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_unknown_multicast_rate_t *obj, int value);

extern int of_bsn_tlv_untagged_OF_VERSION_1_4_populate(
    of_bsn_tlv_untagged_t *obj, int value);
extern int of_bsn_tlv_untagged_OF_VERSION_1_4_check(
    of_bsn_tlv_untagged_t *obj, int value);
extern int of_bsn_tlv_untagged_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_untagged_t *obj, int value);
extern int of_bsn_tlv_untagged_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_untagged_t *obj, int value);

extern int of_bsn_tlv_uri_scheme_OF_VERSION_1_4_populate(
    of_bsn_tlv_uri_scheme_t *obj, int value);
extern int of_bsn_tlv_uri_scheme_OF_VERSION_1_4_check(
    of_bsn_tlv_uri_scheme_t *obj, int value);
extern int of_bsn_tlv_uri_scheme_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_uri_scheme_t *obj, int value);
extern int of_bsn_tlv_uri_scheme_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_uri_scheme_t *obj, int value);

extern int of_bsn_tlv_use_packet_state_OF_VERSION_1_4_populate(
    of_bsn_tlv_use_packet_state_t *obj, int value);
extern int of_bsn_tlv_use_packet_state_OF_VERSION_1_4_check(
    of_bsn_tlv_use_packet_state_t *obj, int value);
extern int of_bsn_tlv_use_packet_state_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_use_packet_state_t *obj, int value);
extern int of_bsn_tlv_use_packet_state_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_use_packet_state_t *obj, int value);

extern int of_bsn_tlv_vfi_OF_VERSION_1_4_populate(
    of_bsn_tlv_vfi_t *obj, int value);
extern int of_bsn_tlv_vfi_OF_VERSION_1_4_check(
    of_bsn_tlv_vfi_t *obj, int value);
extern int of_bsn_tlv_vfi_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_vfi_t *obj, int value);
extern int of_bsn_tlv_vfi_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_vfi_t *obj, int value);

extern int of_bsn_tlv_vfp_class_id_OF_VERSION_1_4_populate(
    of_bsn_tlv_vfp_class_id_t *obj, int value);
extern int of_bsn_tlv_vfp_class_id_OF_VERSION_1_4_check(
    of_bsn_tlv_vfp_class_id_t *obj, int value);
extern int of_bsn_tlv_vfp_class_id_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_vfp_class_id_t *obj, int value);
extern int of_bsn_tlv_vfp_class_id_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_vfp_class_id_t *obj, int value);

extern int of_bsn_tlv_virtual_OF_VERSION_1_4_populate(
    of_bsn_tlv_virtual_t *obj, int value);
extern int of_bsn_tlv_virtual_OF_VERSION_1_4_check(
    of_bsn_tlv_virtual_t *obj, int value);
extern int of_bsn_tlv_virtual_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_virtual_t *obj, int value);
extern int of_bsn_tlv_virtual_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_virtual_t *obj, int value);

extern int of_bsn_tlv_vlan_mac_list_OF_VERSION_1_4_populate(
    of_bsn_tlv_vlan_mac_list_t *obj, int value);
extern int of_bsn_tlv_vlan_mac_list_OF_VERSION_1_4_check(
    of_bsn_tlv_vlan_mac_list_t *obj, int value);
extern int of_bsn_tlv_vlan_mac_list_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_vlan_mac_list_t *obj, int value);
extern int of_bsn_tlv_vlan_mac_list_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_vlan_mac_list_t *obj, int value);

extern int of_bsn_tlv_vlan_pcp_OF_VERSION_1_4_populate(
    of_bsn_tlv_vlan_pcp_t *obj, int value);
extern int of_bsn_tlv_vlan_pcp_OF_VERSION_1_4_check(
    of_bsn_tlv_vlan_pcp_t *obj, int value);
extern int of_bsn_tlv_vlan_pcp_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_vlan_pcp_t *obj, int value);
extern int of_bsn_tlv_vlan_pcp_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_vlan_pcp_t *obj, int value);

extern int of_bsn_tlv_vlan_vid_OF_VERSION_1_4_populate(
    of_bsn_tlv_vlan_vid_t *obj, int value);
extern int of_bsn_tlv_vlan_vid_OF_VERSION_1_4_check(
    of_bsn_tlv_vlan_vid_t *obj, int value);
extern int of_bsn_tlv_vlan_vid_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_vlan_vid_t *obj, int value);
extern int of_bsn_tlv_vlan_vid_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_vlan_vid_t *obj, int value);

extern int of_bsn_tlv_vlan_vid_mask_OF_VERSION_1_4_populate(
    of_bsn_tlv_vlan_vid_mask_t *obj, int value);
extern int of_bsn_tlv_vlan_vid_mask_OF_VERSION_1_4_check(
    of_bsn_tlv_vlan_vid_mask_t *obj, int value);
extern int of_bsn_tlv_vlan_vid_mask_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_vlan_vid_mask_t *obj, int value);
extern int of_bsn_tlv_vlan_vid_mask_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_vlan_vid_mask_t *obj, int value);

extern int of_bsn_tlv_vni_OF_VERSION_1_4_populate(
    of_bsn_tlv_vni_t *obj, int value);
extern int of_bsn_tlv_vni_OF_VERSION_1_4_check(
    of_bsn_tlv_vni_t *obj, int value);
extern int of_bsn_tlv_vni_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_vni_t *obj, int value);
extern int of_bsn_tlv_vni_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_vni_t *obj, int value);

extern int of_bsn_tlv_vpn_key_OF_VERSION_1_4_populate(
    of_bsn_tlv_vpn_key_t *obj, int value);
extern int of_bsn_tlv_vpn_key_OF_VERSION_1_4_check(
    of_bsn_tlv_vpn_key_t *obj, int value);
extern int of_bsn_tlv_vpn_key_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_vpn_key_t *obj, int value);
extern int of_bsn_tlv_vpn_key_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_vpn_key_t *obj, int value);

extern int of_bsn_tlv_vrf_OF_VERSION_1_4_populate(
    of_bsn_tlv_vrf_t *obj, int value);
extern int of_bsn_tlv_vrf_OF_VERSION_1_4_check(
    of_bsn_tlv_vrf_t *obj, int value);
extern int of_bsn_tlv_vrf_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_vrf_t *obj, int value);
extern int of_bsn_tlv_vrf_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_vrf_t *obj, int value);

extern int of_bsn_tlv_vxlan_egress_lag_OF_VERSION_1_4_populate(
    of_bsn_tlv_vxlan_egress_lag_t *obj, int value);
extern int of_bsn_tlv_vxlan_egress_lag_OF_VERSION_1_4_check(
    of_bsn_tlv_vxlan_egress_lag_t *obj, int value);
extern int of_bsn_tlv_vxlan_egress_lag_OF_VERSION_1_4_populate_scalars(
    of_bsn_tlv_vxlan_egress_lag_t *obj, int value);
extern int of_bsn_tlv_vxlan_egress_lag_OF_VERSION_1_4_check_scalars(
    of_bsn_tlv_vxlan_egress_lag_t *obj, int value);

extern int of_bsn_vlan_counter_stats_entry_OF_VERSION_1_4_populate(
    of_bsn_vlan_counter_stats_entry_t *obj, int value);
extern int of_bsn_vlan_counter_stats_entry_OF_VERSION_1_4_check(
    of_bsn_vlan_counter_stats_entry_t *obj, int value);
extern int of_bsn_vlan_counter_stats_entry_OF_VERSION_1_4_populate_scalars(
    of_bsn_vlan_counter_stats_entry_t *obj, int value);
extern int of_bsn_vlan_counter_stats_entry_OF_VERSION_1_4_check_scalars(
    of_bsn_vlan_counter_stats_entry_t *obj, int value);

extern int of_bsn_vlan_mac_OF_VERSION_1_4_populate(
    of_bsn_vlan_mac_t *obj, int value);
extern int of_bsn_vlan_mac_OF_VERSION_1_4_check(
    of_bsn_vlan_mac_t *obj, int value);
extern int of_bsn_vlan_mac_OF_VERSION_1_4_populate_scalars(
    of_bsn_vlan_mac_t *obj, int value);
extern int of_bsn_vlan_mac_OF_VERSION_1_4_check_scalars(
    of_bsn_vlan_mac_t *obj, int value);

extern int of_bsn_vport_l2gre_OF_VERSION_1_4_populate(
    of_bsn_vport_l2gre_t *obj, int value);
extern int of_bsn_vport_l2gre_OF_VERSION_1_4_check(
    of_bsn_vport_l2gre_t *obj, int value);
extern int of_bsn_vport_l2gre_OF_VERSION_1_4_populate_scalars(
    of_bsn_vport_l2gre_t *obj, int value);
extern int of_bsn_vport_l2gre_OF_VERSION_1_4_check_scalars(
    of_bsn_vport_l2gre_t *obj, int value);

extern int of_bsn_vport_q_in_q_OF_VERSION_1_4_populate(
    of_bsn_vport_q_in_q_t *obj, int value);
extern int of_bsn_vport_q_in_q_OF_VERSION_1_4_check(
    of_bsn_vport_q_in_q_t *obj, int value);
extern int of_bsn_vport_q_in_q_OF_VERSION_1_4_populate_scalars(
    of_bsn_vport_q_in_q_t *obj, int value);
extern int of_bsn_vport_q_in_q_OF_VERSION_1_4_check_scalars(
    of_bsn_vport_q_in_q_t *obj, int value);

extern int of_bsn_vrf_counter_stats_entry_OF_VERSION_1_4_populate(
    of_bsn_vrf_counter_stats_entry_t *obj, int value);
extern int of_bsn_vrf_counter_stats_entry_OF_VERSION_1_4_check(
    of_bsn_vrf_counter_stats_entry_t *obj, int value);
extern int of_bsn_vrf_counter_stats_entry_OF_VERSION_1_4_populate_scalars(
    of_bsn_vrf_counter_stats_entry_t *obj, int value);
extern int of_bsn_vrf_counter_stats_entry_OF_VERSION_1_4_check_scalars(
    of_bsn_vrf_counter_stats_entry_t *obj, int value);

extern int of_bucket_OF_VERSION_1_4_populate(
    of_bucket_t *obj, int value);
extern int of_bucket_OF_VERSION_1_4_check(
    of_bucket_t *obj, int value);
extern int of_bucket_OF_VERSION_1_4_populate_scalars(
    of_bucket_t *obj, int value);
extern int of_bucket_OF_VERSION_1_4_check_scalars(
    of_bucket_t *obj, int value);

extern int of_bucket_counter_OF_VERSION_1_4_populate(
    of_bucket_counter_t *obj, int value);
extern int of_bucket_counter_OF_VERSION_1_4_check(
    of_bucket_counter_t *obj, int value);
extern int of_bucket_counter_OF_VERSION_1_4_populate_scalars(
    of_bucket_counter_t *obj, int value);
extern int of_bucket_counter_OF_VERSION_1_4_check_scalars(
    of_bucket_counter_t *obj, int value);

extern int of_flow_stats_entry_OF_VERSION_1_4_populate(
    of_flow_stats_entry_t *obj, int value);
extern int of_flow_stats_entry_OF_VERSION_1_4_check(
    of_flow_stats_entry_t *obj, int value);
extern int of_flow_stats_entry_OF_VERSION_1_4_populate_scalars(
    of_flow_stats_entry_t *obj, int value);
extern int of_flow_stats_entry_OF_VERSION_1_4_check_scalars(
    of_flow_stats_entry_t *obj, int value);

extern int of_group_desc_stats_entry_OF_VERSION_1_4_populate(
    of_group_desc_stats_entry_t *obj, int value);
extern int of_group_desc_stats_entry_OF_VERSION_1_4_check(
    of_group_desc_stats_entry_t *obj, int value);
extern int of_group_desc_stats_entry_OF_VERSION_1_4_populate_scalars(
    of_group_desc_stats_entry_t *obj, int value);
extern int of_group_desc_stats_entry_OF_VERSION_1_4_check_scalars(
    of_group_desc_stats_entry_t *obj, int value);

extern int of_group_stats_entry_OF_VERSION_1_4_populate(
    of_group_stats_entry_t *obj, int value);
extern int of_group_stats_entry_OF_VERSION_1_4_check(
    of_group_stats_entry_t *obj, int value);
extern int of_group_stats_entry_OF_VERSION_1_4_populate_scalars(
    of_group_stats_entry_t *obj, int value);
extern int of_group_stats_entry_OF_VERSION_1_4_check_scalars(
    of_group_stats_entry_t *obj, int value);

extern int of_hello_elem_versionbitmap_OF_VERSION_1_4_populate(
    of_hello_elem_versionbitmap_t *obj, int value);
extern int of_hello_elem_versionbitmap_OF_VERSION_1_4_check(
    of_hello_elem_versionbitmap_t *obj, int value);
extern int of_hello_elem_versionbitmap_OF_VERSION_1_4_populate_scalars(
    of_hello_elem_versionbitmap_t *obj, int value);
extern int of_hello_elem_versionbitmap_OF_VERSION_1_4_check_scalars(
    of_hello_elem_versionbitmap_t *obj, int value);

extern int of_instruction_apply_actions_OF_VERSION_1_4_populate(
    of_instruction_apply_actions_t *obj, int value);
extern int of_instruction_apply_actions_OF_VERSION_1_4_check(
    of_instruction_apply_actions_t *obj, int value);
extern int of_instruction_apply_actions_OF_VERSION_1_4_populate_scalars(
    of_instruction_apply_actions_t *obj, int value);
extern int of_instruction_apply_actions_OF_VERSION_1_4_check_scalars(
    of_instruction_apply_actions_t *obj, int value);

extern int of_instruction_bsn_arp_offload_OF_VERSION_1_4_populate(
    of_instruction_bsn_arp_offload_t *obj, int value);
extern int of_instruction_bsn_arp_offload_OF_VERSION_1_4_check(
    of_instruction_bsn_arp_offload_t *obj, int value);
extern int of_instruction_bsn_arp_offload_OF_VERSION_1_4_populate_scalars(
    of_instruction_bsn_arp_offload_t *obj, int value);
extern int of_instruction_bsn_arp_offload_OF_VERSION_1_4_check_scalars(
    of_instruction_bsn_arp_offload_t *obj, int value);

extern int of_instruction_bsn_auto_negotiation_OF_VERSION_1_4_populate(
    of_instruction_bsn_auto_negotiation_t *obj, int value);
extern int of_instruction_bsn_auto_negotiation_OF_VERSION_1_4_check(
    of_instruction_bsn_auto_negotiation_t *obj, int value);
extern int of_instruction_bsn_auto_negotiation_OF_VERSION_1_4_populate_scalars(
    of_instruction_bsn_auto_negotiation_t *obj, int value);
extern int of_instruction_bsn_auto_negotiation_OF_VERSION_1_4_check_scalars(
    of_instruction_bsn_auto_negotiation_t *obj, int value);

extern int of_instruction_bsn_deny_OF_VERSION_1_4_populate(
    of_instruction_bsn_deny_t *obj, int value);
extern int of_instruction_bsn_deny_OF_VERSION_1_4_check(
    of_instruction_bsn_deny_t *obj, int value);
extern int of_instruction_bsn_deny_OF_VERSION_1_4_populate_scalars(
    of_instruction_bsn_deny_t *obj, int value);
extern int of_instruction_bsn_deny_OF_VERSION_1_4_check_scalars(
    of_instruction_bsn_deny_t *obj, int value);

extern int of_instruction_bsn_dhcp_offload_OF_VERSION_1_4_populate(
    of_instruction_bsn_dhcp_offload_t *obj, int value);
extern int of_instruction_bsn_dhcp_offload_OF_VERSION_1_4_check(
    of_instruction_bsn_dhcp_offload_t *obj, int value);
extern int of_instruction_bsn_dhcp_offload_OF_VERSION_1_4_populate_scalars(
    of_instruction_bsn_dhcp_offload_t *obj, int value);
extern int of_instruction_bsn_dhcp_offload_OF_VERSION_1_4_check_scalars(
    of_instruction_bsn_dhcp_offload_t *obj, int value);

extern int of_instruction_bsn_disable_l3_OF_VERSION_1_4_populate(
    of_instruction_bsn_disable_l3_t *obj, int value);
extern int of_instruction_bsn_disable_l3_OF_VERSION_1_4_check(
    of_instruction_bsn_disable_l3_t *obj, int value);
extern int of_instruction_bsn_disable_l3_OF_VERSION_1_4_populate_scalars(
    of_instruction_bsn_disable_l3_t *obj, int value);
extern int of_instruction_bsn_disable_l3_OF_VERSION_1_4_check_scalars(
    of_instruction_bsn_disable_l3_t *obj, int value);

extern int of_instruction_bsn_disable_src_mac_check_OF_VERSION_1_4_populate(
    of_instruction_bsn_disable_src_mac_check_t *obj, int value);
extern int of_instruction_bsn_disable_src_mac_check_OF_VERSION_1_4_check(
    of_instruction_bsn_disable_src_mac_check_t *obj, int value);
extern int of_instruction_bsn_disable_src_mac_check_OF_VERSION_1_4_populate_scalars(
    of_instruction_bsn_disable_src_mac_check_t *obj, int value);
extern int of_instruction_bsn_disable_src_mac_check_OF_VERSION_1_4_check_scalars(
    of_instruction_bsn_disable_src_mac_check_t *obj, int value);

extern int of_instruction_bsn_disable_vlan_counters_OF_VERSION_1_4_populate(
    of_instruction_bsn_disable_vlan_counters_t *obj, int value);
extern int of_instruction_bsn_disable_vlan_counters_OF_VERSION_1_4_check(
    of_instruction_bsn_disable_vlan_counters_t *obj, int value);
extern int of_instruction_bsn_disable_vlan_counters_OF_VERSION_1_4_populate_scalars(
    of_instruction_bsn_disable_vlan_counters_t *obj, int value);
extern int of_instruction_bsn_disable_vlan_counters_OF_VERSION_1_4_check_scalars(
    of_instruction_bsn_disable_vlan_counters_t *obj, int value);

extern int of_instruction_bsn_hash_select_OF_VERSION_1_4_populate(
    of_instruction_bsn_hash_select_t *obj, int value);
extern int of_instruction_bsn_hash_select_OF_VERSION_1_4_check(
    of_instruction_bsn_hash_select_t *obj, int value);
extern int of_instruction_bsn_hash_select_OF_VERSION_1_4_populate_scalars(
    of_instruction_bsn_hash_select_t *obj, int value);
extern int of_instruction_bsn_hash_select_OF_VERSION_1_4_check_scalars(
    of_instruction_bsn_hash_select_t *obj, int value);

extern int of_instruction_bsn_internal_priority_OF_VERSION_1_4_populate(
    of_instruction_bsn_internal_priority_t *obj, int value);
extern int of_instruction_bsn_internal_priority_OF_VERSION_1_4_check(
    of_instruction_bsn_internal_priority_t *obj, int value);
extern int of_instruction_bsn_internal_priority_OF_VERSION_1_4_populate_scalars(
    of_instruction_bsn_internal_priority_t *obj, int value);
extern int of_instruction_bsn_internal_priority_OF_VERSION_1_4_check_scalars(
    of_instruction_bsn_internal_priority_t *obj, int value);

extern int of_instruction_bsn_ndp_offload_OF_VERSION_1_4_populate(
    of_instruction_bsn_ndp_offload_t *obj, int value);
extern int of_instruction_bsn_ndp_offload_OF_VERSION_1_4_check(
    of_instruction_bsn_ndp_offload_t *obj, int value);
extern int of_instruction_bsn_ndp_offload_OF_VERSION_1_4_populate_scalars(
    of_instruction_bsn_ndp_offload_t *obj, int value);
extern int of_instruction_bsn_ndp_offload_OF_VERSION_1_4_check_scalars(
    of_instruction_bsn_ndp_offload_t *obj, int value);

extern int of_instruction_bsn_packet_of_death_OF_VERSION_1_4_populate(
    of_instruction_bsn_packet_of_death_t *obj, int value);
extern int of_instruction_bsn_packet_of_death_OF_VERSION_1_4_check(
    of_instruction_bsn_packet_of_death_t *obj, int value);
extern int of_instruction_bsn_packet_of_death_OF_VERSION_1_4_populate_scalars(
    of_instruction_bsn_packet_of_death_t *obj, int value);
extern int of_instruction_bsn_packet_of_death_OF_VERSION_1_4_check_scalars(
    of_instruction_bsn_packet_of_death_t *obj, int value);

extern int of_instruction_bsn_permit_OF_VERSION_1_4_populate(
    of_instruction_bsn_permit_t *obj, int value);
extern int of_instruction_bsn_permit_OF_VERSION_1_4_check(
    of_instruction_bsn_permit_t *obj, int value);
extern int of_instruction_bsn_permit_OF_VERSION_1_4_populate_scalars(
    of_instruction_bsn_permit_t *obj, int value);
extern int of_instruction_bsn_permit_OF_VERSION_1_4_check_scalars(
    of_instruction_bsn_permit_t *obj, int value);

extern int of_instruction_bsn_prioritize_pdus_OF_VERSION_1_4_populate(
    of_instruction_bsn_prioritize_pdus_t *obj, int value);
extern int of_instruction_bsn_prioritize_pdus_OF_VERSION_1_4_check(
    of_instruction_bsn_prioritize_pdus_t *obj, int value);
extern int of_instruction_bsn_prioritize_pdus_OF_VERSION_1_4_populate_scalars(
    of_instruction_bsn_prioritize_pdus_t *obj, int value);
extern int of_instruction_bsn_prioritize_pdus_OF_VERSION_1_4_check_scalars(
    of_instruction_bsn_prioritize_pdus_t *obj, int value);

extern int of_instruction_bsn_require_vlan_xlate_OF_VERSION_1_4_populate(
    of_instruction_bsn_require_vlan_xlate_t *obj, int value);
extern int of_instruction_bsn_require_vlan_xlate_OF_VERSION_1_4_check(
    of_instruction_bsn_require_vlan_xlate_t *obj, int value);
extern int of_instruction_bsn_require_vlan_xlate_OF_VERSION_1_4_populate_scalars(
    of_instruction_bsn_require_vlan_xlate_t *obj, int value);
extern int of_instruction_bsn_require_vlan_xlate_OF_VERSION_1_4_check_scalars(
    of_instruction_bsn_require_vlan_xlate_t *obj, int value);

extern int of_instruction_bsn_span_destination_OF_VERSION_1_4_populate(
    of_instruction_bsn_span_destination_t *obj, int value);
extern int of_instruction_bsn_span_destination_OF_VERSION_1_4_check(
    of_instruction_bsn_span_destination_t *obj, int value);
extern int of_instruction_bsn_span_destination_OF_VERSION_1_4_populate_scalars(
    of_instruction_bsn_span_destination_t *obj, int value);
extern int of_instruction_bsn_span_destination_OF_VERSION_1_4_check_scalars(
    of_instruction_bsn_span_destination_t *obj, int value);

extern int of_instruction_clear_actions_OF_VERSION_1_4_populate(
    of_instruction_clear_actions_t *obj, int value);
extern int of_instruction_clear_actions_OF_VERSION_1_4_check(
    of_instruction_clear_actions_t *obj, int value);
extern int of_instruction_clear_actions_OF_VERSION_1_4_populate_scalars(
    of_instruction_clear_actions_t *obj, int value);
extern int of_instruction_clear_actions_OF_VERSION_1_4_check_scalars(
    of_instruction_clear_actions_t *obj, int value);

extern int of_instruction_goto_table_OF_VERSION_1_4_populate(
    of_instruction_goto_table_t *obj, int value);
extern int of_instruction_goto_table_OF_VERSION_1_4_check(
    of_instruction_goto_table_t *obj, int value);
extern int of_instruction_goto_table_OF_VERSION_1_4_populate_scalars(
    of_instruction_goto_table_t *obj, int value);
extern int of_instruction_goto_table_OF_VERSION_1_4_check_scalars(
    of_instruction_goto_table_t *obj, int value);

extern int of_instruction_id_apply_actions_OF_VERSION_1_4_populate(
    of_instruction_id_apply_actions_t *obj, int value);
extern int of_instruction_id_apply_actions_OF_VERSION_1_4_check(
    of_instruction_id_apply_actions_t *obj, int value);
extern int of_instruction_id_apply_actions_OF_VERSION_1_4_populate_scalars(
    of_instruction_id_apply_actions_t *obj, int value);
extern int of_instruction_id_apply_actions_OF_VERSION_1_4_check_scalars(
    of_instruction_id_apply_actions_t *obj, int value);

extern int of_instruction_id_bsn_arp_offload_OF_VERSION_1_4_populate(
    of_instruction_id_bsn_arp_offload_t *obj, int value);
extern int of_instruction_id_bsn_arp_offload_OF_VERSION_1_4_check(
    of_instruction_id_bsn_arp_offload_t *obj, int value);
extern int of_instruction_id_bsn_arp_offload_OF_VERSION_1_4_populate_scalars(
    of_instruction_id_bsn_arp_offload_t *obj, int value);
extern int of_instruction_id_bsn_arp_offload_OF_VERSION_1_4_check_scalars(
    of_instruction_id_bsn_arp_offload_t *obj, int value);

extern int of_instruction_id_bsn_auto_negotiation_OF_VERSION_1_4_populate(
    of_instruction_id_bsn_auto_negotiation_t *obj, int value);
extern int of_instruction_id_bsn_auto_negotiation_OF_VERSION_1_4_check(
    of_instruction_id_bsn_auto_negotiation_t *obj, int value);
extern int of_instruction_id_bsn_auto_negotiation_OF_VERSION_1_4_populate_scalars(
    of_instruction_id_bsn_auto_negotiation_t *obj, int value);
extern int of_instruction_id_bsn_auto_negotiation_OF_VERSION_1_4_check_scalars(
    of_instruction_id_bsn_auto_negotiation_t *obj, int value);

extern int of_instruction_id_bsn_deny_OF_VERSION_1_4_populate(
    of_instruction_id_bsn_deny_t *obj, int value);
extern int of_instruction_id_bsn_deny_OF_VERSION_1_4_check(
    of_instruction_id_bsn_deny_t *obj, int value);
extern int of_instruction_id_bsn_deny_OF_VERSION_1_4_populate_scalars(
    of_instruction_id_bsn_deny_t *obj, int value);
extern int of_instruction_id_bsn_deny_OF_VERSION_1_4_check_scalars(
    of_instruction_id_bsn_deny_t *obj, int value);

extern int of_instruction_id_bsn_dhcp_offload_OF_VERSION_1_4_populate(
    of_instruction_id_bsn_dhcp_offload_t *obj, int value);
extern int of_instruction_id_bsn_dhcp_offload_OF_VERSION_1_4_check(
    of_instruction_id_bsn_dhcp_offload_t *obj, int value);
extern int of_instruction_id_bsn_dhcp_offload_OF_VERSION_1_4_populate_scalars(
    of_instruction_id_bsn_dhcp_offload_t *obj, int value);
extern int of_instruction_id_bsn_dhcp_offload_OF_VERSION_1_4_check_scalars(
    of_instruction_id_bsn_dhcp_offload_t *obj, int value);

extern int of_instruction_id_bsn_disable_l3_OF_VERSION_1_4_populate(
    of_instruction_id_bsn_disable_l3_t *obj, int value);
extern int of_instruction_id_bsn_disable_l3_OF_VERSION_1_4_check(
    of_instruction_id_bsn_disable_l3_t *obj, int value);
extern int of_instruction_id_bsn_disable_l3_OF_VERSION_1_4_populate_scalars(
    of_instruction_id_bsn_disable_l3_t *obj, int value);
extern int of_instruction_id_bsn_disable_l3_OF_VERSION_1_4_check_scalars(
    of_instruction_id_bsn_disable_l3_t *obj, int value);

extern int of_instruction_id_bsn_disable_src_mac_check_OF_VERSION_1_4_populate(
    of_instruction_id_bsn_disable_src_mac_check_t *obj, int value);
extern int of_instruction_id_bsn_disable_src_mac_check_OF_VERSION_1_4_check(
    of_instruction_id_bsn_disable_src_mac_check_t *obj, int value);
extern int of_instruction_id_bsn_disable_src_mac_check_OF_VERSION_1_4_populate_scalars(
    of_instruction_id_bsn_disable_src_mac_check_t *obj, int value);
extern int of_instruction_id_bsn_disable_src_mac_check_OF_VERSION_1_4_check_scalars(
    of_instruction_id_bsn_disable_src_mac_check_t *obj, int value);

extern int of_instruction_id_bsn_disable_vlan_counters_OF_VERSION_1_4_populate(
    of_instruction_id_bsn_disable_vlan_counters_t *obj, int value);
extern int of_instruction_id_bsn_disable_vlan_counters_OF_VERSION_1_4_check(
    of_instruction_id_bsn_disable_vlan_counters_t *obj, int value);
extern int of_instruction_id_bsn_disable_vlan_counters_OF_VERSION_1_4_populate_scalars(
    of_instruction_id_bsn_disable_vlan_counters_t *obj, int value);
extern int of_instruction_id_bsn_disable_vlan_counters_OF_VERSION_1_4_check_scalars(
    of_instruction_id_bsn_disable_vlan_counters_t *obj, int value);

extern int of_instruction_id_bsn_hash_select_OF_VERSION_1_4_populate(
    of_instruction_id_bsn_hash_select_t *obj, int value);
extern int of_instruction_id_bsn_hash_select_OF_VERSION_1_4_check(
    of_instruction_id_bsn_hash_select_t *obj, int value);
extern int of_instruction_id_bsn_hash_select_OF_VERSION_1_4_populate_scalars(
    of_instruction_id_bsn_hash_select_t *obj, int value);
extern int of_instruction_id_bsn_hash_select_OF_VERSION_1_4_check_scalars(
    of_instruction_id_bsn_hash_select_t *obj, int value);

extern int of_instruction_id_bsn_internal_priority_OF_VERSION_1_4_populate(
    of_instruction_id_bsn_internal_priority_t *obj, int value);
extern int of_instruction_id_bsn_internal_priority_OF_VERSION_1_4_check(
    of_instruction_id_bsn_internal_priority_t *obj, int value);
extern int of_instruction_id_bsn_internal_priority_OF_VERSION_1_4_populate_scalars(
    of_instruction_id_bsn_internal_priority_t *obj, int value);
extern int of_instruction_id_bsn_internal_priority_OF_VERSION_1_4_check_scalars(
    of_instruction_id_bsn_internal_priority_t *obj, int value);

extern int of_instruction_id_bsn_ndp_offload_OF_VERSION_1_4_populate(
    of_instruction_id_bsn_ndp_offload_t *obj, int value);
extern int of_instruction_id_bsn_ndp_offload_OF_VERSION_1_4_check(
    of_instruction_id_bsn_ndp_offload_t *obj, int value);
extern int of_instruction_id_bsn_ndp_offload_OF_VERSION_1_4_populate_scalars(
    of_instruction_id_bsn_ndp_offload_t *obj, int value);
extern int of_instruction_id_bsn_ndp_offload_OF_VERSION_1_4_check_scalars(
    of_instruction_id_bsn_ndp_offload_t *obj, int value);

extern int of_instruction_id_bsn_packet_of_death_OF_VERSION_1_4_populate(
    of_instruction_id_bsn_packet_of_death_t *obj, int value);
extern int of_instruction_id_bsn_packet_of_death_OF_VERSION_1_4_check(
    of_instruction_id_bsn_packet_of_death_t *obj, int value);
extern int of_instruction_id_bsn_packet_of_death_OF_VERSION_1_4_populate_scalars(
    of_instruction_id_bsn_packet_of_death_t *obj, int value);
extern int of_instruction_id_bsn_packet_of_death_OF_VERSION_1_4_check_scalars(
    of_instruction_id_bsn_packet_of_death_t *obj, int value);

extern int of_instruction_id_bsn_permit_OF_VERSION_1_4_populate(
    of_instruction_id_bsn_permit_t *obj, int value);
extern int of_instruction_id_bsn_permit_OF_VERSION_1_4_check(
    of_instruction_id_bsn_permit_t *obj, int value);
extern int of_instruction_id_bsn_permit_OF_VERSION_1_4_populate_scalars(
    of_instruction_id_bsn_permit_t *obj, int value);
extern int of_instruction_id_bsn_permit_OF_VERSION_1_4_check_scalars(
    of_instruction_id_bsn_permit_t *obj, int value);

extern int of_instruction_id_bsn_prioritize_pdus_OF_VERSION_1_4_populate(
    of_instruction_id_bsn_prioritize_pdus_t *obj, int value);
extern int of_instruction_id_bsn_prioritize_pdus_OF_VERSION_1_4_check(
    of_instruction_id_bsn_prioritize_pdus_t *obj, int value);
extern int of_instruction_id_bsn_prioritize_pdus_OF_VERSION_1_4_populate_scalars(
    of_instruction_id_bsn_prioritize_pdus_t *obj, int value);
extern int of_instruction_id_bsn_prioritize_pdus_OF_VERSION_1_4_check_scalars(
    of_instruction_id_bsn_prioritize_pdus_t *obj, int value);

extern int of_instruction_id_bsn_require_vlan_xlate_OF_VERSION_1_4_populate(
    of_instruction_id_bsn_require_vlan_xlate_t *obj, int value);
extern int of_instruction_id_bsn_require_vlan_xlate_OF_VERSION_1_4_check(
    of_instruction_id_bsn_require_vlan_xlate_t *obj, int value);
extern int of_instruction_id_bsn_require_vlan_xlate_OF_VERSION_1_4_populate_scalars(
    of_instruction_id_bsn_require_vlan_xlate_t *obj, int value);
extern int of_instruction_id_bsn_require_vlan_xlate_OF_VERSION_1_4_check_scalars(
    of_instruction_id_bsn_require_vlan_xlate_t *obj, int value);

extern int of_instruction_id_bsn_span_destination_OF_VERSION_1_4_populate(
    of_instruction_id_bsn_span_destination_t *obj, int value);
extern int of_instruction_id_bsn_span_destination_OF_VERSION_1_4_check(
    of_instruction_id_bsn_span_destination_t *obj, int value);
extern int of_instruction_id_bsn_span_destination_OF_VERSION_1_4_populate_scalars(
    of_instruction_id_bsn_span_destination_t *obj, int value);
extern int of_instruction_id_bsn_span_destination_OF_VERSION_1_4_check_scalars(
    of_instruction_id_bsn_span_destination_t *obj, int value);

extern int of_instruction_id_clear_actions_OF_VERSION_1_4_populate(
    of_instruction_id_clear_actions_t *obj, int value);
extern int of_instruction_id_clear_actions_OF_VERSION_1_4_check(
    of_instruction_id_clear_actions_t *obj, int value);
extern int of_instruction_id_clear_actions_OF_VERSION_1_4_populate_scalars(
    of_instruction_id_clear_actions_t *obj, int value);
extern int of_instruction_id_clear_actions_OF_VERSION_1_4_check_scalars(
    of_instruction_id_clear_actions_t *obj, int value);

extern int of_instruction_id_goto_table_OF_VERSION_1_4_populate(
    of_instruction_id_goto_table_t *obj, int value);
extern int of_instruction_id_goto_table_OF_VERSION_1_4_check(
    of_instruction_id_goto_table_t *obj, int value);
extern int of_instruction_id_goto_table_OF_VERSION_1_4_populate_scalars(
    of_instruction_id_goto_table_t *obj, int value);
extern int of_instruction_id_goto_table_OF_VERSION_1_4_check_scalars(
    of_instruction_id_goto_table_t *obj, int value);

extern int of_instruction_id_meter_OF_VERSION_1_4_populate(
    of_instruction_id_meter_t *obj, int value);
extern int of_instruction_id_meter_OF_VERSION_1_4_check(
    of_instruction_id_meter_t *obj, int value);
extern int of_instruction_id_meter_OF_VERSION_1_4_populate_scalars(
    of_instruction_id_meter_t *obj, int value);
extern int of_instruction_id_meter_OF_VERSION_1_4_check_scalars(
    of_instruction_id_meter_t *obj, int value);

extern int of_instruction_id_write_actions_OF_VERSION_1_4_populate(
    of_instruction_id_write_actions_t *obj, int value);
extern int of_instruction_id_write_actions_OF_VERSION_1_4_check(
    of_instruction_id_write_actions_t *obj, int value);
extern int of_instruction_id_write_actions_OF_VERSION_1_4_populate_scalars(
    of_instruction_id_write_actions_t *obj, int value);
extern int of_instruction_id_write_actions_OF_VERSION_1_4_check_scalars(
    of_instruction_id_write_actions_t *obj, int value);

extern int of_instruction_id_write_metadata_OF_VERSION_1_4_populate(
    of_instruction_id_write_metadata_t *obj, int value);
extern int of_instruction_id_write_metadata_OF_VERSION_1_4_check(
    of_instruction_id_write_metadata_t *obj, int value);
extern int of_instruction_id_write_metadata_OF_VERSION_1_4_populate_scalars(
    of_instruction_id_write_metadata_t *obj, int value);
extern int of_instruction_id_write_metadata_OF_VERSION_1_4_check_scalars(
    of_instruction_id_write_metadata_t *obj, int value);

extern int of_instruction_meter_OF_VERSION_1_4_populate(
    of_instruction_meter_t *obj, int value);
extern int of_instruction_meter_OF_VERSION_1_4_check(
    of_instruction_meter_t *obj, int value);
extern int of_instruction_meter_OF_VERSION_1_4_populate_scalars(
    of_instruction_meter_t *obj, int value);
extern int of_instruction_meter_OF_VERSION_1_4_check_scalars(
    of_instruction_meter_t *obj, int value);

extern int of_instruction_write_actions_OF_VERSION_1_4_populate(
    of_instruction_write_actions_t *obj, int value);
extern int of_instruction_write_actions_OF_VERSION_1_4_check(
    of_instruction_write_actions_t *obj, int value);
extern int of_instruction_write_actions_OF_VERSION_1_4_populate_scalars(
    of_instruction_write_actions_t *obj, int value);
extern int of_instruction_write_actions_OF_VERSION_1_4_check_scalars(
    of_instruction_write_actions_t *obj, int value);

extern int of_instruction_write_metadata_OF_VERSION_1_4_populate(
    of_instruction_write_metadata_t *obj, int value);
extern int of_instruction_write_metadata_OF_VERSION_1_4_check(
    of_instruction_write_metadata_t *obj, int value);
extern int of_instruction_write_metadata_OF_VERSION_1_4_populate_scalars(
    of_instruction_write_metadata_t *obj, int value);
extern int of_instruction_write_metadata_OF_VERSION_1_4_check_scalars(
    of_instruction_write_metadata_t *obj, int value);

extern int of_match_v3_OF_VERSION_1_4_populate(
    of_match_v3_t *obj, int value);
extern int of_match_v3_OF_VERSION_1_4_check(
    of_match_v3_t *obj, int value);
extern int of_match_v3_OF_VERSION_1_4_populate_scalars(
    of_match_v3_t *obj, int value);
extern int of_match_v3_OF_VERSION_1_4_check_scalars(
    of_match_v3_t *obj, int value);

extern int of_meter_band_drop_OF_VERSION_1_4_populate(
    of_meter_band_drop_t *obj, int value);
extern int of_meter_band_drop_OF_VERSION_1_4_check(
    of_meter_band_drop_t *obj, int value);
extern int of_meter_band_drop_OF_VERSION_1_4_populate_scalars(
    of_meter_band_drop_t *obj, int value);
extern int of_meter_band_drop_OF_VERSION_1_4_check_scalars(
    of_meter_band_drop_t *obj, int value);

extern int of_meter_band_dscp_remark_OF_VERSION_1_4_populate(
    of_meter_band_dscp_remark_t *obj, int value);
extern int of_meter_band_dscp_remark_OF_VERSION_1_4_check(
    of_meter_band_dscp_remark_t *obj, int value);
extern int of_meter_band_dscp_remark_OF_VERSION_1_4_populate_scalars(
    of_meter_band_dscp_remark_t *obj, int value);
extern int of_meter_band_dscp_remark_OF_VERSION_1_4_check_scalars(
    of_meter_band_dscp_remark_t *obj, int value);

extern int of_meter_band_experimenter_OF_VERSION_1_4_populate(
    of_meter_band_experimenter_t *obj, int value);
extern int of_meter_band_experimenter_OF_VERSION_1_4_check(
    of_meter_band_experimenter_t *obj, int value);
extern int of_meter_band_experimenter_OF_VERSION_1_4_populate_scalars(
    of_meter_band_experimenter_t *obj, int value);
extern int of_meter_band_experimenter_OF_VERSION_1_4_check_scalars(
    of_meter_band_experimenter_t *obj, int value);

extern int of_meter_band_stats_OF_VERSION_1_4_populate(
    of_meter_band_stats_t *obj, int value);
extern int of_meter_band_stats_OF_VERSION_1_4_check(
    of_meter_band_stats_t *obj, int value);
extern int of_meter_band_stats_OF_VERSION_1_4_populate_scalars(
    of_meter_band_stats_t *obj, int value);
extern int of_meter_band_stats_OF_VERSION_1_4_check_scalars(
    of_meter_band_stats_t *obj, int value);

extern int of_meter_config_OF_VERSION_1_4_populate(
    of_meter_config_t *obj, int value);
extern int of_meter_config_OF_VERSION_1_4_check(
    of_meter_config_t *obj, int value);
extern int of_meter_config_OF_VERSION_1_4_populate_scalars(
    of_meter_config_t *obj, int value);
extern int of_meter_config_OF_VERSION_1_4_check_scalars(
    of_meter_config_t *obj, int value);

extern int of_meter_features_OF_VERSION_1_4_populate(
    of_meter_features_t *obj, int value);
extern int of_meter_features_OF_VERSION_1_4_check(
    of_meter_features_t *obj, int value);
extern int of_meter_features_OF_VERSION_1_4_populate_scalars(
    of_meter_features_t *obj, int value);
extern int of_meter_features_OF_VERSION_1_4_check_scalars(
    of_meter_features_t *obj, int value);

extern int of_meter_stats_OF_VERSION_1_4_populate(
    of_meter_stats_t *obj, int value);
extern int of_meter_stats_OF_VERSION_1_4_check(
    of_meter_stats_t *obj, int value);
extern int of_meter_stats_OF_VERSION_1_4_populate_scalars(
    of_meter_stats_t *obj, int value);
extern int of_meter_stats_OF_VERSION_1_4_check_scalars(
    of_meter_stats_t *obj, int value);

extern int of_oxm_arp_op_OF_VERSION_1_4_populate(
    of_oxm_arp_op_t *obj, int value);
extern int of_oxm_arp_op_OF_VERSION_1_4_check(
    of_oxm_arp_op_t *obj, int value);
extern int of_oxm_arp_op_OF_VERSION_1_4_populate_scalars(
    of_oxm_arp_op_t *obj, int value);
extern int of_oxm_arp_op_OF_VERSION_1_4_check_scalars(
    of_oxm_arp_op_t *obj, int value);

extern int of_oxm_arp_op_masked_OF_VERSION_1_4_populate(
    of_oxm_arp_op_masked_t *obj, int value);
extern int of_oxm_arp_op_masked_OF_VERSION_1_4_check(
    of_oxm_arp_op_masked_t *obj, int value);
extern int of_oxm_arp_op_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_arp_op_masked_t *obj, int value);
extern int of_oxm_arp_op_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_arp_op_masked_t *obj, int value);

extern int of_oxm_arp_sha_OF_VERSION_1_4_populate(
    of_oxm_arp_sha_t *obj, int value);
extern int of_oxm_arp_sha_OF_VERSION_1_4_check(
    of_oxm_arp_sha_t *obj, int value);
extern int of_oxm_arp_sha_OF_VERSION_1_4_populate_scalars(
    of_oxm_arp_sha_t *obj, int value);
extern int of_oxm_arp_sha_OF_VERSION_1_4_check_scalars(
    of_oxm_arp_sha_t *obj, int value);

extern int of_oxm_arp_sha_masked_OF_VERSION_1_4_populate(
    of_oxm_arp_sha_masked_t *obj, int value);
extern int of_oxm_arp_sha_masked_OF_VERSION_1_4_check(
    of_oxm_arp_sha_masked_t *obj, int value);
extern int of_oxm_arp_sha_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_arp_sha_masked_t *obj, int value);
extern int of_oxm_arp_sha_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_arp_sha_masked_t *obj, int value);

extern int of_oxm_arp_spa_OF_VERSION_1_4_populate(
    of_oxm_arp_spa_t *obj, int value);
extern int of_oxm_arp_spa_OF_VERSION_1_4_check(
    of_oxm_arp_spa_t *obj, int value);
extern int of_oxm_arp_spa_OF_VERSION_1_4_populate_scalars(
    of_oxm_arp_spa_t *obj, int value);
extern int of_oxm_arp_spa_OF_VERSION_1_4_check_scalars(
    of_oxm_arp_spa_t *obj, int value);

extern int of_oxm_arp_spa_masked_OF_VERSION_1_4_populate(
    of_oxm_arp_spa_masked_t *obj, int value);
extern int of_oxm_arp_spa_masked_OF_VERSION_1_4_check(
    of_oxm_arp_spa_masked_t *obj, int value);
extern int of_oxm_arp_spa_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_arp_spa_masked_t *obj, int value);
extern int of_oxm_arp_spa_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_arp_spa_masked_t *obj, int value);

extern int of_oxm_arp_tha_OF_VERSION_1_4_populate(
    of_oxm_arp_tha_t *obj, int value);
extern int of_oxm_arp_tha_OF_VERSION_1_4_check(
    of_oxm_arp_tha_t *obj, int value);
extern int of_oxm_arp_tha_OF_VERSION_1_4_populate_scalars(
    of_oxm_arp_tha_t *obj, int value);
extern int of_oxm_arp_tha_OF_VERSION_1_4_check_scalars(
    of_oxm_arp_tha_t *obj, int value);

extern int of_oxm_arp_tha_masked_OF_VERSION_1_4_populate(
    of_oxm_arp_tha_masked_t *obj, int value);
extern int of_oxm_arp_tha_masked_OF_VERSION_1_4_check(
    of_oxm_arp_tha_masked_t *obj, int value);
extern int of_oxm_arp_tha_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_arp_tha_masked_t *obj, int value);
extern int of_oxm_arp_tha_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_arp_tha_masked_t *obj, int value);

extern int of_oxm_arp_tpa_OF_VERSION_1_4_populate(
    of_oxm_arp_tpa_t *obj, int value);
extern int of_oxm_arp_tpa_OF_VERSION_1_4_check(
    of_oxm_arp_tpa_t *obj, int value);
extern int of_oxm_arp_tpa_OF_VERSION_1_4_populate_scalars(
    of_oxm_arp_tpa_t *obj, int value);
extern int of_oxm_arp_tpa_OF_VERSION_1_4_check_scalars(
    of_oxm_arp_tpa_t *obj, int value);

extern int of_oxm_arp_tpa_masked_OF_VERSION_1_4_populate(
    of_oxm_arp_tpa_masked_t *obj, int value);
extern int of_oxm_arp_tpa_masked_OF_VERSION_1_4_check(
    of_oxm_arp_tpa_masked_t *obj, int value);
extern int of_oxm_arp_tpa_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_arp_tpa_masked_t *obj, int value);
extern int of_oxm_arp_tpa_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_arp_tpa_masked_t *obj, int value);

extern int of_oxm_bsn_egr_port_group_id_OF_VERSION_1_4_populate(
    of_oxm_bsn_egr_port_group_id_t *obj, int value);
extern int of_oxm_bsn_egr_port_group_id_OF_VERSION_1_4_check(
    of_oxm_bsn_egr_port_group_id_t *obj, int value);
extern int of_oxm_bsn_egr_port_group_id_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_egr_port_group_id_t *obj, int value);
extern int of_oxm_bsn_egr_port_group_id_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_egr_port_group_id_t *obj, int value);

extern int of_oxm_bsn_egr_port_group_id_masked_OF_VERSION_1_4_populate(
    of_oxm_bsn_egr_port_group_id_masked_t *obj, int value);
extern int of_oxm_bsn_egr_port_group_id_masked_OF_VERSION_1_4_check(
    of_oxm_bsn_egr_port_group_id_masked_t *obj, int value);
extern int of_oxm_bsn_egr_port_group_id_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_egr_port_group_id_masked_t *obj, int value);
extern int of_oxm_bsn_egr_port_group_id_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_egr_port_group_id_masked_t *obj, int value);

extern int of_oxm_bsn_ifp_class_id_OF_VERSION_1_4_populate(
    of_oxm_bsn_ifp_class_id_t *obj, int value);
extern int of_oxm_bsn_ifp_class_id_OF_VERSION_1_4_check(
    of_oxm_bsn_ifp_class_id_t *obj, int value);
extern int of_oxm_bsn_ifp_class_id_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_ifp_class_id_t *obj, int value);
extern int of_oxm_bsn_ifp_class_id_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_ifp_class_id_t *obj, int value);

extern int of_oxm_bsn_ifp_class_id_masked_OF_VERSION_1_4_populate(
    of_oxm_bsn_ifp_class_id_masked_t *obj, int value);
extern int of_oxm_bsn_ifp_class_id_masked_OF_VERSION_1_4_check(
    of_oxm_bsn_ifp_class_id_masked_t *obj, int value);
extern int of_oxm_bsn_ifp_class_id_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_ifp_class_id_masked_t *obj, int value);
extern int of_oxm_bsn_ifp_class_id_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_ifp_class_id_masked_t *obj, int value);

extern int of_oxm_bsn_in_ports_128_OF_VERSION_1_4_populate(
    of_oxm_bsn_in_ports_128_t *obj, int value);
extern int of_oxm_bsn_in_ports_128_OF_VERSION_1_4_check(
    of_oxm_bsn_in_ports_128_t *obj, int value);
extern int of_oxm_bsn_in_ports_128_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_in_ports_128_t *obj, int value);
extern int of_oxm_bsn_in_ports_128_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_in_ports_128_t *obj, int value);

extern int of_oxm_bsn_in_ports_128_masked_OF_VERSION_1_4_populate(
    of_oxm_bsn_in_ports_128_masked_t *obj, int value);
extern int of_oxm_bsn_in_ports_128_masked_OF_VERSION_1_4_check(
    of_oxm_bsn_in_ports_128_masked_t *obj, int value);
extern int of_oxm_bsn_in_ports_128_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_in_ports_128_masked_t *obj, int value);
extern int of_oxm_bsn_in_ports_128_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_in_ports_128_masked_t *obj, int value);

extern int of_oxm_bsn_in_ports_512_OF_VERSION_1_4_populate(
    of_oxm_bsn_in_ports_512_t *obj, int value);
extern int of_oxm_bsn_in_ports_512_OF_VERSION_1_4_check(
    of_oxm_bsn_in_ports_512_t *obj, int value);
extern int of_oxm_bsn_in_ports_512_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_in_ports_512_t *obj, int value);
extern int of_oxm_bsn_in_ports_512_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_in_ports_512_t *obj, int value);

extern int of_oxm_bsn_in_ports_512_masked_OF_VERSION_1_4_populate(
    of_oxm_bsn_in_ports_512_masked_t *obj, int value);
extern int of_oxm_bsn_in_ports_512_masked_OF_VERSION_1_4_check(
    of_oxm_bsn_in_ports_512_masked_t *obj, int value);
extern int of_oxm_bsn_in_ports_512_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_in_ports_512_masked_t *obj, int value);
extern int of_oxm_bsn_in_ports_512_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_in_ports_512_masked_t *obj, int value);

extern int of_oxm_bsn_ingress_port_group_id_OF_VERSION_1_4_populate(
    of_oxm_bsn_ingress_port_group_id_t *obj, int value);
extern int of_oxm_bsn_ingress_port_group_id_OF_VERSION_1_4_check(
    of_oxm_bsn_ingress_port_group_id_t *obj, int value);
extern int of_oxm_bsn_ingress_port_group_id_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_ingress_port_group_id_t *obj, int value);
extern int of_oxm_bsn_ingress_port_group_id_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_ingress_port_group_id_t *obj, int value);

extern int of_oxm_bsn_ingress_port_group_id_masked_OF_VERSION_1_4_populate(
    of_oxm_bsn_ingress_port_group_id_masked_t *obj, int value);
extern int of_oxm_bsn_ingress_port_group_id_masked_OF_VERSION_1_4_check(
    of_oxm_bsn_ingress_port_group_id_masked_t *obj, int value);
extern int of_oxm_bsn_ingress_port_group_id_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_ingress_port_group_id_masked_t *obj, int value);
extern int of_oxm_bsn_ingress_port_group_id_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_ingress_port_group_id_masked_t *obj, int value);

extern int of_oxm_bsn_inner_eth_dst_OF_VERSION_1_4_populate(
    of_oxm_bsn_inner_eth_dst_t *obj, int value);
extern int of_oxm_bsn_inner_eth_dst_OF_VERSION_1_4_check(
    of_oxm_bsn_inner_eth_dst_t *obj, int value);
extern int of_oxm_bsn_inner_eth_dst_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_inner_eth_dst_t *obj, int value);
extern int of_oxm_bsn_inner_eth_dst_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_inner_eth_dst_t *obj, int value);

extern int of_oxm_bsn_inner_eth_dst_masked_OF_VERSION_1_4_populate(
    of_oxm_bsn_inner_eth_dst_masked_t *obj, int value);
extern int of_oxm_bsn_inner_eth_dst_masked_OF_VERSION_1_4_check(
    of_oxm_bsn_inner_eth_dst_masked_t *obj, int value);
extern int of_oxm_bsn_inner_eth_dst_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_inner_eth_dst_masked_t *obj, int value);
extern int of_oxm_bsn_inner_eth_dst_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_inner_eth_dst_masked_t *obj, int value);

extern int of_oxm_bsn_inner_eth_src_OF_VERSION_1_4_populate(
    of_oxm_bsn_inner_eth_src_t *obj, int value);
extern int of_oxm_bsn_inner_eth_src_OF_VERSION_1_4_check(
    of_oxm_bsn_inner_eth_src_t *obj, int value);
extern int of_oxm_bsn_inner_eth_src_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_inner_eth_src_t *obj, int value);
extern int of_oxm_bsn_inner_eth_src_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_inner_eth_src_t *obj, int value);

extern int of_oxm_bsn_inner_eth_src_masked_OF_VERSION_1_4_populate(
    of_oxm_bsn_inner_eth_src_masked_t *obj, int value);
extern int of_oxm_bsn_inner_eth_src_masked_OF_VERSION_1_4_check(
    of_oxm_bsn_inner_eth_src_masked_t *obj, int value);
extern int of_oxm_bsn_inner_eth_src_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_inner_eth_src_masked_t *obj, int value);
extern int of_oxm_bsn_inner_eth_src_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_inner_eth_src_masked_t *obj, int value);

extern int of_oxm_bsn_inner_vlan_vid_OF_VERSION_1_4_populate(
    of_oxm_bsn_inner_vlan_vid_t *obj, int value);
extern int of_oxm_bsn_inner_vlan_vid_OF_VERSION_1_4_check(
    of_oxm_bsn_inner_vlan_vid_t *obj, int value);
extern int of_oxm_bsn_inner_vlan_vid_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_inner_vlan_vid_t *obj, int value);
extern int of_oxm_bsn_inner_vlan_vid_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_inner_vlan_vid_t *obj, int value);

extern int of_oxm_bsn_inner_vlan_vid_masked_OF_VERSION_1_4_populate(
    of_oxm_bsn_inner_vlan_vid_masked_t *obj, int value);
extern int of_oxm_bsn_inner_vlan_vid_masked_OF_VERSION_1_4_check(
    of_oxm_bsn_inner_vlan_vid_masked_t *obj, int value);
extern int of_oxm_bsn_inner_vlan_vid_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_inner_vlan_vid_masked_t *obj, int value);
extern int of_oxm_bsn_inner_vlan_vid_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_inner_vlan_vid_masked_t *obj, int value);

extern int of_oxm_bsn_ip_fragmentation_OF_VERSION_1_4_populate(
    of_oxm_bsn_ip_fragmentation_t *obj, int value);
extern int of_oxm_bsn_ip_fragmentation_OF_VERSION_1_4_check(
    of_oxm_bsn_ip_fragmentation_t *obj, int value);
extern int of_oxm_bsn_ip_fragmentation_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_ip_fragmentation_t *obj, int value);
extern int of_oxm_bsn_ip_fragmentation_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_ip_fragmentation_t *obj, int value);

extern int of_oxm_bsn_ip_fragmentation_masked_OF_VERSION_1_4_populate(
    of_oxm_bsn_ip_fragmentation_masked_t *obj, int value);
extern int of_oxm_bsn_ip_fragmentation_masked_OF_VERSION_1_4_check(
    of_oxm_bsn_ip_fragmentation_masked_t *obj, int value);
extern int of_oxm_bsn_ip_fragmentation_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_ip_fragmentation_masked_t *obj, int value);
extern int of_oxm_bsn_ip_fragmentation_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_ip_fragmentation_masked_t *obj, int value);

extern int of_oxm_bsn_l2_cache_hit_OF_VERSION_1_4_populate(
    of_oxm_bsn_l2_cache_hit_t *obj, int value);
extern int of_oxm_bsn_l2_cache_hit_OF_VERSION_1_4_check(
    of_oxm_bsn_l2_cache_hit_t *obj, int value);
extern int of_oxm_bsn_l2_cache_hit_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_l2_cache_hit_t *obj, int value);
extern int of_oxm_bsn_l2_cache_hit_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_l2_cache_hit_t *obj, int value);

extern int of_oxm_bsn_l2_cache_hit_masked_OF_VERSION_1_4_populate(
    of_oxm_bsn_l2_cache_hit_masked_t *obj, int value);
extern int of_oxm_bsn_l2_cache_hit_masked_OF_VERSION_1_4_check(
    of_oxm_bsn_l2_cache_hit_masked_t *obj, int value);
extern int of_oxm_bsn_l2_cache_hit_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_l2_cache_hit_masked_t *obj, int value);
extern int of_oxm_bsn_l2_cache_hit_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_l2_cache_hit_masked_t *obj, int value);

extern int of_oxm_bsn_l3_interface_class_id_OF_VERSION_1_4_populate(
    of_oxm_bsn_l3_interface_class_id_t *obj, int value);
extern int of_oxm_bsn_l3_interface_class_id_OF_VERSION_1_4_check(
    of_oxm_bsn_l3_interface_class_id_t *obj, int value);
extern int of_oxm_bsn_l3_interface_class_id_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_l3_interface_class_id_t *obj, int value);
extern int of_oxm_bsn_l3_interface_class_id_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_l3_interface_class_id_t *obj, int value);

extern int of_oxm_bsn_l3_interface_class_id_masked_OF_VERSION_1_4_populate(
    of_oxm_bsn_l3_interface_class_id_masked_t *obj, int value);
extern int of_oxm_bsn_l3_interface_class_id_masked_OF_VERSION_1_4_check(
    of_oxm_bsn_l3_interface_class_id_masked_t *obj, int value);
extern int of_oxm_bsn_l3_interface_class_id_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_l3_interface_class_id_masked_t *obj, int value);
extern int of_oxm_bsn_l3_interface_class_id_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_l3_interface_class_id_masked_t *obj, int value);

extern int of_oxm_bsn_l3_src_class_id_OF_VERSION_1_4_populate(
    of_oxm_bsn_l3_src_class_id_t *obj, int value);
extern int of_oxm_bsn_l3_src_class_id_OF_VERSION_1_4_check(
    of_oxm_bsn_l3_src_class_id_t *obj, int value);
extern int of_oxm_bsn_l3_src_class_id_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_l3_src_class_id_t *obj, int value);
extern int of_oxm_bsn_l3_src_class_id_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_l3_src_class_id_t *obj, int value);

extern int of_oxm_bsn_l3_src_class_id_masked_OF_VERSION_1_4_populate(
    of_oxm_bsn_l3_src_class_id_masked_t *obj, int value);
extern int of_oxm_bsn_l3_src_class_id_masked_OF_VERSION_1_4_check(
    of_oxm_bsn_l3_src_class_id_masked_t *obj, int value);
extern int of_oxm_bsn_l3_src_class_id_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_l3_src_class_id_masked_t *obj, int value);
extern int of_oxm_bsn_l3_src_class_id_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_l3_src_class_id_masked_t *obj, int value);

extern int of_oxm_bsn_lag_id_OF_VERSION_1_4_populate(
    of_oxm_bsn_lag_id_t *obj, int value);
extern int of_oxm_bsn_lag_id_OF_VERSION_1_4_check(
    of_oxm_bsn_lag_id_t *obj, int value);
extern int of_oxm_bsn_lag_id_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_lag_id_t *obj, int value);
extern int of_oxm_bsn_lag_id_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_lag_id_t *obj, int value);

extern int of_oxm_bsn_lag_id_masked_OF_VERSION_1_4_populate(
    of_oxm_bsn_lag_id_masked_t *obj, int value);
extern int of_oxm_bsn_lag_id_masked_OF_VERSION_1_4_check(
    of_oxm_bsn_lag_id_masked_t *obj, int value);
extern int of_oxm_bsn_lag_id_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_lag_id_masked_t *obj, int value);
extern int of_oxm_bsn_lag_id_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_lag_id_masked_t *obj, int value);

extern int of_oxm_bsn_tcp_flags_OF_VERSION_1_4_populate(
    of_oxm_bsn_tcp_flags_t *obj, int value);
extern int of_oxm_bsn_tcp_flags_OF_VERSION_1_4_check(
    of_oxm_bsn_tcp_flags_t *obj, int value);
extern int of_oxm_bsn_tcp_flags_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_tcp_flags_t *obj, int value);
extern int of_oxm_bsn_tcp_flags_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_tcp_flags_t *obj, int value);

extern int of_oxm_bsn_tcp_flags_masked_OF_VERSION_1_4_populate(
    of_oxm_bsn_tcp_flags_masked_t *obj, int value);
extern int of_oxm_bsn_tcp_flags_masked_OF_VERSION_1_4_check(
    of_oxm_bsn_tcp_flags_masked_t *obj, int value);
extern int of_oxm_bsn_tcp_flags_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_tcp_flags_masked_t *obj, int value);
extern int of_oxm_bsn_tcp_flags_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_tcp_flags_masked_t *obj, int value);

extern int of_oxm_bsn_udf0_OF_VERSION_1_4_populate(
    of_oxm_bsn_udf0_t *obj, int value);
extern int of_oxm_bsn_udf0_OF_VERSION_1_4_check(
    of_oxm_bsn_udf0_t *obj, int value);
extern int of_oxm_bsn_udf0_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_udf0_t *obj, int value);
extern int of_oxm_bsn_udf0_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_udf0_t *obj, int value);

extern int of_oxm_bsn_udf0_masked_OF_VERSION_1_4_populate(
    of_oxm_bsn_udf0_masked_t *obj, int value);
extern int of_oxm_bsn_udf0_masked_OF_VERSION_1_4_check(
    of_oxm_bsn_udf0_masked_t *obj, int value);
extern int of_oxm_bsn_udf0_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_udf0_masked_t *obj, int value);
extern int of_oxm_bsn_udf0_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_udf0_masked_t *obj, int value);

extern int of_oxm_bsn_udf1_OF_VERSION_1_4_populate(
    of_oxm_bsn_udf1_t *obj, int value);
extern int of_oxm_bsn_udf1_OF_VERSION_1_4_check(
    of_oxm_bsn_udf1_t *obj, int value);
extern int of_oxm_bsn_udf1_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_udf1_t *obj, int value);
extern int of_oxm_bsn_udf1_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_udf1_t *obj, int value);

extern int of_oxm_bsn_udf1_masked_OF_VERSION_1_4_populate(
    of_oxm_bsn_udf1_masked_t *obj, int value);
extern int of_oxm_bsn_udf1_masked_OF_VERSION_1_4_check(
    of_oxm_bsn_udf1_masked_t *obj, int value);
extern int of_oxm_bsn_udf1_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_udf1_masked_t *obj, int value);
extern int of_oxm_bsn_udf1_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_udf1_masked_t *obj, int value);

extern int of_oxm_bsn_udf2_OF_VERSION_1_4_populate(
    of_oxm_bsn_udf2_t *obj, int value);
extern int of_oxm_bsn_udf2_OF_VERSION_1_4_check(
    of_oxm_bsn_udf2_t *obj, int value);
extern int of_oxm_bsn_udf2_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_udf2_t *obj, int value);
extern int of_oxm_bsn_udf2_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_udf2_t *obj, int value);

extern int of_oxm_bsn_udf2_masked_OF_VERSION_1_4_populate(
    of_oxm_bsn_udf2_masked_t *obj, int value);
extern int of_oxm_bsn_udf2_masked_OF_VERSION_1_4_check(
    of_oxm_bsn_udf2_masked_t *obj, int value);
extern int of_oxm_bsn_udf2_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_udf2_masked_t *obj, int value);
extern int of_oxm_bsn_udf2_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_udf2_masked_t *obj, int value);

extern int of_oxm_bsn_udf3_OF_VERSION_1_4_populate(
    of_oxm_bsn_udf3_t *obj, int value);
extern int of_oxm_bsn_udf3_OF_VERSION_1_4_check(
    of_oxm_bsn_udf3_t *obj, int value);
extern int of_oxm_bsn_udf3_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_udf3_t *obj, int value);
extern int of_oxm_bsn_udf3_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_udf3_t *obj, int value);

extern int of_oxm_bsn_udf3_masked_OF_VERSION_1_4_populate(
    of_oxm_bsn_udf3_masked_t *obj, int value);
extern int of_oxm_bsn_udf3_masked_OF_VERSION_1_4_check(
    of_oxm_bsn_udf3_masked_t *obj, int value);
extern int of_oxm_bsn_udf3_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_udf3_masked_t *obj, int value);
extern int of_oxm_bsn_udf3_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_udf3_masked_t *obj, int value);

extern int of_oxm_bsn_udf4_OF_VERSION_1_4_populate(
    of_oxm_bsn_udf4_t *obj, int value);
extern int of_oxm_bsn_udf4_OF_VERSION_1_4_check(
    of_oxm_bsn_udf4_t *obj, int value);
extern int of_oxm_bsn_udf4_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_udf4_t *obj, int value);
extern int of_oxm_bsn_udf4_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_udf4_t *obj, int value);

extern int of_oxm_bsn_udf4_masked_OF_VERSION_1_4_populate(
    of_oxm_bsn_udf4_masked_t *obj, int value);
extern int of_oxm_bsn_udf4_masked_OF_VERSION_1_4_check(
    of_oxm_bsn_udf4_masked_t *obj, int value);
extern int of_oxm_bsn_udf4_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_udf4_masked_t *obj, int value);
extern int of_oxm_bsn_udf4_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_udf4_masked_t *obj, int value);

extern int of_oxm_bsn_udf5_OF_VERSION_1_4_populate(
    of_oxm_bsn_udf5_t *obj, int value);
extern int of_oxm_bsn_udf5_OF_VERSION_1_4_check(
    of_oxm_bsn_udf5_t *obj, int value);
extern int of_oxm_bsn_udf5_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_udf5_t *obj, int value);
extern int of_oxm_bsn_udf5_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_udf5_t *obj, int value);

extern int of_oxm_bsn_udf5_masked_OF_VERSION_1_4_populate(
    of_oxm_bsn_udf5_masked_t *obj, int value);
extern int of_oxm_bsn_udf5_masked_OF_VERSION_1_4_check(
    of_oxm_bsn_udf5_masked_t *obj, int value);
extern int of_oxm_bsn_udf5_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_udf5_masked_t *obj, int value);
extern int of_oxm_bsn_udf5_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_udf5_masked_t *obj, int value);

extern int of_oxm_bsn_udf6_OF_VERSION_1_4_populate(
    of_oxm_bsn_udf6_t *obj, int value);
extern int of_oxm_bsn_udf6_OF_VERSION_1_4_check(
    of_oxm_bsn_udf6_t *obj, int value);
extern int of_oxm_bsn_udf6_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_udf6_t *obj, int value);
extern int of_oxm_bsn_udf6_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_udf6_t *obj, int value);

extern int of_oxm_bsn_udf6_masked_OF_VERSION_1_4_populate(
    of_oxm_bsn_udf6_masked_t *obj, int value);
extern int of_oxm_bsn_udf6_masked_OF_VERSION_1_4_check(
    of_oxm_bsn_udf6_masked_t *obj, int value);
extern int of_oxm_bsn_udf6_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_udf6_masked_t *obj, int value);
extern int of_oxm_bsn_udf6_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_udf6_masked_t *obj, int value);

extern int of_oxm_bsn_udf7_OF_VERSION_1_4_populate(
    of_oxm_bsn_udf7_t *obj, int value);
extern int of_oxm_bsn_udf7_OF_VERSION_1_4_check(
    of_oxm_bsn_udf7_t *obj, int value);
extern int of_oxm_bsn_udf7_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_udf7_t *obj, int value);
extern int of_oxm_bsn_udf7_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_udf7_t *obj, int value);

extern int of_oxm_bsn_udf7_masked_OF_VERSION_1_4_populate(
    of_oxm_bsn_udf7_masked_t *obj, int value);
extern int of_oxm_bsn_udf7_masked_OF_VERSION_1_4_check(
    of_oxm_bsn_udf7_masked_t *obj, int value);
extern int of_oxm_bsn_udf7_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_udf7_masked_t *obj, int value);
extern int of_oxm_bsn_udf7_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_udf7_masked_t *obj, int value);

extern int of_oxm_bsn_vfi_OF_VERSION_1_4_populate(
    of_oxm_bsn_vfi_t *obj, int value);
extern int of_oxm_bsn_vfi_OF_VERSION_1_4_check(
    of_oxm_bsn_vfi_t *obj, int value);
extern int of_oxm_bsn_vfi_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_vfi_t *obj, int value);
extern int of_oxm_bsn_vfi_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_vfi_t *obj, int value);

extern int of_oxm_bsn_vfi_masked_OF_VERSION_1_4_populate(
    of_oxm_bsn_vfi_masked_t *obj, int value);
extern int of_oxm_bsn_vfi_masked_OF_VERSION_1_4_check(
    of_oxm_bsn_vfi_masked_t *obj, int value);
extern int of_oxm_bsn_vfi_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_vfi_masked_t *obj, int value);
extern int of_oxm_bsn_vfi_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_vfi_masked_t *obj, int value);

extern int of_oxm_bsn_vlan_xlate_port_group_id_OF_VERSION_1_4_populate(
    of_oxm_bsn_vlan_xlate_port_group_id_t *obj, int value);
extern int of_oxm_bsn_vlan_xlate_port_group_id_OF_VERSION_1_4_check(
    of_oxm_bsn_vlan_xlate_port_group_id_t *obj, int value);
extern int of_oxm_bsn_vlan_xlate_port_group_id_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_vlan_xlate_port_group_id_t *obj, int value);
extern int of_oxm_bsn_vlan_xlate_port_group_id_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_vlan_xlate_port_group_id_t *obj, int value);

extern int of_oxm_bsn_vlan_xlate_port_group_id_masked_OF_VERSION_1_4_populate(
    of_oxm_bsn_vlan_xlate_port_group_id_masked_t *obj, int value);
extern int of_oxm_bsn_vlan_xlate_port_group_id_masked_OF_VERSION_1_4_check(
    of_oxm_bsn_vlan_xlate_port_group_id_masked_t *obj, int value);
extern int of_oxm_bsn_vlan_xlate_port_group_id_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_vlan_xlate_port_group_id_masked_t *obj, int value);
extern int of_oxm_bsn_vlan_xlate_port_group_id_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_vlan_xlate_port_group_id_masked_t *obj, int value);

extern int of_oxm_bsn_vrf_OF_VERSION_1_4_populate(
    of_oxm_bsn_vrf_t *obj, int value);
extern int of_oxm_bsn_vrf_OF_VERSION_1_4_check(
    of_oxm_bsn_vrf_t *obj, int value);
extern int of_oxm_bsn_vrf_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_vrf_t *obj, int value);
extern int of_oxm_bsn_vrf_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_vrf_t *obj, int value);

extern int of_oxm_bsn_vrf_masked_OF_VERSION_1_4_populate(
    of_oxm_bsn_vrf_masked_t *obj, int value);
extern int of_oxm_bsn_vrf_masked_OF_VERSION_1_4_check(
    of_oxm_bsn_vrf_masked_t *obj, int value);
extern int of_oxm_bsn_vrf_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_vrf_masked_t *obj, int value);
extern int of_oxm_bsn_vrf_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_vrf_masked_t *obj, int value);

extern int of_oxm_bsn_vxlan_network_id_OF_VERSION_1_4_populate(
    of_oxm_bsn_vxlan_network_id_t *obj, int value);
extern int of_oxm_bsn_vxlan_network_id_OF_VERSION_1_4_check(
    of_oxm_bsn_vxlan_network_id_t *obj, int value);
extern int of_oxm_bsn_vxlan_network_id_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_vxlan_network_id_t *obj, int value);
extern int of_oxm_bsn_vxlan_network_id_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_vxlan_network_id_t *obj, int value);

extern int of_oxm_bsn_vxlan_network_id_masked_OF_VERSION_1_4_populate(
    of_oxm_bsn_vxlan_network_id_masked_t *obj, int value);
extern int of_oxm_bsn_vxlan_network_id_masked_OF_VERSION_1_4_check(
    of_oxm_bsn_vxlan_network_id_masked_t *obj, int value);
extern int of_oxm_bsn_vxlan_network_id_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_bsn_vxlan_network_id_masked_t *obj, int value);
extern int of_oxm_bsn_vxlan_network_id_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_bsn_vxlan_network_id_masked_t *obj, int value);

extern int of_oxm_eth_dst_OF_VERSION_1_4_populate(
    of_oxm_eth_dst_t *obj, int value);
extern int of_oxm_eth_dst_OF_VERSION_1_4_check(
    of_oxm_eth_dst_t *obj, int value);
extern int of_oxm_eth_dst_OF_VERSION_1_4_populate_scalars(
    of_oxm_eth_dst_t *obj, int value);
extern int of_oxm_eth_dst_OF_VERSION_1_4_check_scalars(
    of_oxm_eth_dst_t *obj, int value);

extern int of_oxm_eth_dst_masked_OF_VERSION_1_4_populate(
    of_oxm_eth_dst_masked_t *obj, int value);
extern int of_oxm_eth_dst_masked_OF_VERSION_1_4_check(
    of_oxm_eth_dst_masked_t *obj, int value);
extern int of_oxm_eth_dst_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_eth_dst_masked_t *obj, int value);
extern int of_oxm_eth_dst_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_eth_dst_masked_t *obj, int value);

extern int of_oxm_eth_src_OF_VERSION_1_4_populate(
    of_oxm_eth_src_t *obj, int value);
extern int of_oxm_eth_src_OF_VERSION_1_4_check(
    of_oxm_eth_src_t *obj, int value);
extern int of_oxm_eth_src_OF_VERSION_1_4_populate_scalars(
    of_oxm_eth_src_t *obj, int value);
extern int of_oxm_eth_src_OF_VERSION_1_4_check_scalars(
    of_oxm_eth_src_t *obj, int value);

extern int of_oxm_eth_src_masked_OF_VERSION_1_4_populate(
    of_oxm_eth_src_masked_t *obj, int value);
extern int of_oxm_eth_src_masked_OF_VERSION_1_4_check(
    of_oxm_eth_src_masked_t *obj, int value);
extern int of_oxm_eth_src_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_eth_src_masked_t *obj, int value);
extern int of_oxm_eth_src_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_eth_src_masked_t *obj, int value);

extern int of_oxm_eth_type_OF_VERSION_1_4_populate(
    of_oxm_eth_type_t *obj, int value);
extern int of_oxm_eth_type_OF_VERSION_1_4_check(
    of_oxm_eth_type_t *obj, int value);
extern int of_oxm_eth_type_OF_VERSION_1_4_populate_scalars(
    of_oxm_eth_type_t *obj, int value);
extern int of_oxm_eth_type_OF_VERSION_1_4_check_scalars(
    of_oxm_eth_type_t *obj, int value);

extern int of_oxm_eth_type_masked_OF_VERSION_1_4_populate(
    of_oxm_eth_type_masked_t *obj, int value);
extern int of_oxm_eth_type_masked_OF_VERSION_1_4_check(
    of_oxm_eth_type_masked_t *obj, int value);
extern int of_oxm_eth_type_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_eth_type_masked_t *obj, int value);
extern int of_oxm_eth_type_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_eth_type_masked_t *obj, int value);

extern int of_oxm_icmpv4_code_OF_VERSION_1_4_populate(
    of_oxm_icmpv4_code_t *obj, int value);
extern int of_oxm_icmpv4_code_OF_VERSION_1_4_check(
    of_oxm_icmpv4_code_t *obj, int value);
extern int of_oxm_icmpv4_code_OF_VERSION_1_4_populate_scalars(
    of_oxm_icmpv4_code_t *obj, int value);
extern int of_oxm_icmpv4_code_OF_VERSION_1_4_check_scalars(
    of_oxm_icmpv4_code_t *obj, int value);

extern int of_oxm_icmpv4_code_masked_OF_VERSION_1_4_populate(
    of_oxm_icmpv4_code_masked_t *obj, int value);
extern int of_oxm_icmpv4_code_masked_OF_VERSION_1_4_check(
    of_oxm_icmpv4_code_masked_t *obj, int value);
extern int of_oxm_icmpv4_code_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_icmpv4_code_masked_t *obj, int value);
extern int of_oxm_icmpv4_code_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_icmpv4_code_masked_t *obj, int value);

extern int of_oxm_icmpv4_type_OF_VERSION_1_4_populate(
    of_oxm_icmpv4_type_t *obj, int value);
extern int of_oxm_icmpv4_type_OF_VERSION_1_4_check(
    of_oxm_icmpv4_type_t *obj, int value);
extern int of_oxm_icmpv4_type_OF_VERSION_1_4_populate_scalars(
    of_oxm_icmpv4_type_t *obj, int value);
extern int of_oxm_icmpv4_type_OF_VERSION_1_4_check_scalars(
    of_oxm_icmpv4_type_t *obj, int value);

extern int of_oxm_icmpv4_type_masked_OF_VERSION_1_4_populate(
    of_oxm_icmpv4_type_masked_t *obj, int value);
extern int of_oxm_icmpv4_type_masked_OF_VERSION_1_4_check(
    of_oxm_icmpv4_type_masked_t *obj, int value);
extern int of_oxm_icmpv4_type_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_icmpv4_type_masked_t *obj, int value);
extern int of_oxm_icmpv4_type_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_icmpv4_type_masked_t *obj, int value);

extern int of_oxm_icmpv6_code_OF_VERSION_1_4_populate(
    of_oxm_icmpv6_code_t *obj, int value);
extern int of_oxm_icmpv6_code_OF_VERSION_1_4_check(
    of_oxm_icmpv6_code_t *obj, int value);
extern int of_oxm_icmpv6_code_OF_VERSION_1_4_populate_scalars(
    of_oxm_icmpv6_code_t *obj, int value);
extern int of_oxm_icmpv6_code_OF_VERSION_1_4_check_scalars(
    of_oxm_icmpv6_code_t *obj, int value);

extern int of_oxm_icmpv6_code_masked_OF_VERSION_1_4_populate(
    of_oxm_icmpv6_code_masked_t *obj, int value);
extern int of_oxm_icmpv6_code_masked_OF_VERSION_1_4_check(
    of_oxm_icmpv6_code_masked_t *obj, int value);
extern int of_oxm_icmpv6_code_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_icmpv6_code_masked_t *obj, int value);
extern int of_oxm_icmpv6_code_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_icmpv6_code_masked_t *obj, int value);

extern int of_oxm_icmpv6_type_OF_VERSION_1_4_populate(
    of_oxm_icmpv6_type_t *obj, int value);
extern int of_oxm_icmpv6_type_OF_VERSION_1_4_check(
    of_oxm_icmpv6_type_t *obj, int value);
extern int of_oxm_icmpv6_type_OF_VERSION_1_4_populate_scalars(
    of_oxm_icmpv6_type_t *obj, int value);
extern int of_oxm_icmpv6_type_OF_VERSION_1_4_check_scalars(
    of_oxm_icmpv6_type_t *obj, int value);

extern int of_oxm_icmpv6_type_masked_OF_VERSION_1_4_populate(
    of_oxm_icmpv6_type_masked_t *obj, int value);
extern int of_oxm_icmpv6_type_masked_OF_VERSION_1_4_check(
    of_oxm_icmpv6_type_masked_t *obj, int value);
extern int of_oxm_icmpv6_type_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_icmpv6_type_masked_t *obj, int value);
extern int of_oxm_icmpv6_type_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_icmpv6_type_masked_t *obj, int value);

extern int of_oxm_in_phy_port_OF_VERSION_1_4_populate(
    of_oxm_in_phy_port_t *obj, int value);
extern int of_oxm_in_phy_port_OF_VERSION_1_4_check(
    of_oxm_in_phy_port_t *obj, int value);
extern int of_oxm_in_phy_port_OF_VERSION_1_4_populate_scalars(
    of_oxm_in_phy_port_t *obj, int value);
extern int of_oxm_in_phy_port_OF_VERSION_1_4_check_scalars(
    of_oxm_in_phy_port_t *obj, int value);

extern int of_oxm_in_phy_port_masked_OF_VERSION_1_4_populate(
    of_oxm_in_phy_port_masked_t *obj, int value);
extern int of_oxm_in_phy_port_masked_OF_VERSION_1_4_check(
    of_oxm_in_phy_port_masked_t *obj, int value);
extern int of_oxm_in_phy_port_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_in_phy_port_masked_t *obj, int value);
extern int of_oxm_in_phy_port_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_in_phy_port_masked_t *obj, int value);

extern int of_oxm_in_port_OF_VERSION_1_4_populate(
    of_oxm_in_port_t *obj, int value);
extern int of_oxm_in_port_OF_VERSION_1_4_check(
    of_oxm_in_port_t *obj, int value);
extern int of_oxm_in_port_OF_VERSION_1_4_populate_scalars(
    of_oxm_in_port_t *obj, int value);
extern int of_oxm_in_port_OF_VERSION_1_4_check_scalars(
    of_oxm_in_port_t *obj, int value);

extern int of_oxm_in_port_masked_OF_VERSION_1_4_populate(
    of_oxm_in_port_masked_t *obj, int value);
extern int of_oxm_in_port_masked_OF_VERSION_1_4_check(
    of_oxm_in_port_masked_t *obj, int value);
extern int of_oxm_in_port_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_in_port_masked_t *obj, int value);
extern int of_oxm_in_port_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_in_port_masked_t *obj, int value);

extern int of_oxm_ip_dscp_OF_VERSION_1_4_populate(
    of_oxm_ip_dscp_t *obj, int value);
extern int of_oxm_ip_dscp_OF_VERSION_1_4_check(
    of_oxm_ip_dscp_t *obj, int value);
extern int of_oxm_ip_dscp_OF_VERSION_1_4_populate_scalars(
    of_oxm_ip_dscp_t *obj, int value);
extern int of_oxm_ip_dscp_OF_VERSION_1_4_check_scalars(
    of_oxm_ip_dscp_t *obj, int value);

extern int of_oxm_ip_dscp_masked_OF_VERSION_1_4_populate(
    of_oxm_ip_dscp_masked_t *obj, int value);
extern int of_oxm_ip_dscp_masked_OF_VERSION_1_4_check(
    of_oxm_ip_dscp_masked_t *obj, int value);
extern int of_oxm_ip_dscp_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_ip_dscp_masked_t *obj, int value);
extern int of_oxm_ip_dscp_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_ip_dscp_masked_t *obj, int value);

extern int of_oxm_ip_ecn_OF_VERSION_1_4_populate(
    of_oxm_ip_ecn_t *obj, int value);
extern int of_oxm_ip_ecn_OF_VERSION_1_4_check(
    of_oxm_ip_ecn_t *obj, int value);
extern int of_oxm_ip_ecn_OF_VERSION_1_4_populate_scalars(
    of_oxm_ip_ecn_t *obj, int value);
extern int of_oxm_ip_ecn_OF_VERSION_1_4_check_scalars(
    of_oxm_ip_ecn_t *obj, int value);

extern int of_oxm_ip_ecn_masked_OF_VERSION_1_4_populate(
    of_oxm_ip_ecn_masked_t *obj, int value);
extern int of_oxm_ip_ecn_masked_OF_VERSION_1_4_check(
    of_oxm_ip_ecn_masked_t *obj, int value);
extern int of_oxm_ip_ecn_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_ip_ecn_masked_t *obj, int value);
extern int of_oxm_ip_ecn_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_ip_ecn_masked_t *obj, int value);

extern int of_oxm_ip_proto_OF_VERSION_1_4_populate(
    of_oxm_ip_proto_t *obj, int value);
extern int of_oxm_ip_proto_OF_VERSION_1_4_check(
    of_oxm_ip_proto_t *obj, int value);
extern int of_oxm_ip_proto_OF_VERSION_1_4_populate_scalars(
    of_oxm_ip_proto_t *obj, int value);
extern int of_oxm_ip_proto_OF_VERSION_1_4_check_scalars(
    of_oxm_ip_proto_t *obj, int value);

extern int of_oxm_ip_proto_masked_OF_VERSION_1_4_populate(
    of_oxm_ip_proto_masked_t *obj, int value);
extern int of_oxm_ip_proto_masked_OF_VERSION_1_4_check(
    of_oxm_ip_proto_masked_t *obj, int value);
extern int of_oxm_ip_proto_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_ip_proto_masked_t *obj, int value);
extern int of_oxm_ip_proto_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_ip_proto_masked_t *obj, int value);

extern int of_oxm_ipv4_dst_OF_VERSION_1_4_populate(
    of_oxm_ipv4_dst_t *obj, int value);
extern int of_oxm_ipv4_dst_OF_VERSION_1_4_check(
    of_oxm_ipv4_dst_t *obj, int value);
extern int of_oxm_ipv4_dst_OF_VERSION_1_4_populate_scalars(
    of_oxm_ipv4_dst_t *obj, int value);
extern int of_oxm_ipv4_dst_OF_VERSION_1_4_check_scalars(
    of_oxm_ipv4_dst_t *obj, int value);

extern int of_oxm_ipv4_dst_masked_OF_VERSION_1_4_populate(
    of_oxm_ipv4_dst_masked_t *obj, int value);
extern int of_oxm_ipv4_dst_masked_OF_VERSION_1_4_check(
    of_oxm_ipv4_dst_masked_t *obj, int value);
extern int of_oxm_ipv4_dst_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_ipv4_dst_masked_t *obj, int value);
extern int of_oxm_ipv4_dst_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_ipv4_dst_masked_t *obj, int value);

extern int of_oxm_ipv4_src_OF_VERSION_1_4_populate(
    of_oxm_ipv4_src_t *obj, int value);
extern int of_oxm_ipv4_src_OF_VERSION_1_4_check(
    of_oxm_ipv4_src_t *obj, int value);
extern int of_oxm_ipv4_src_OF_VERSION_1_4_populate_scalars(
    of_oxm_ipv4_src_t *obj, int value);
extern int of_oxm_ipv4_src_OF_VERSION_1_4_check_scalars(
    of_oxm_ipv4_src_t *obj, int value);

extern int of_oxm_ipv4_src_masked_OF_VERSION_1_4_populate(
    of_oxm_ipv4_src_masked_t *obj, int value);
extern int of_oxm_ipv4_src_masked_OF_VERSION_1_4_check(
    of_oxm_ipv4_src_masked_t *obj, int value);
extern int of_oxm_ipv4_src_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_ipv4_src_masked_t *obj, int value);
extern int of_oxm_ipv4_src_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_ipv4_src_masked_t *obj, int value);

extern int of_oxm_ipv6_dst_OF_VERSION_1_4_populate(
    of_oxm_ipv6_dst_t *obj, int value);
extern int of_oxm_ipv6_dst_OF_VERSION_1_4_check(
    of_oxm_ipv6_dst_t *obj, int value);
extern int of_oxm_ipv6_dst_OF_VERSION_1_4_populate_scalars(
    of_oxm_ipv6_dst_t *obj, int value);
extern int of_oxm_ipv6_dst_OF_VERSION_1_4_check_scalars(
    of_oxm_ipv6_dst_t *obj, int value);

extern int of_oxm_ipv6_dst_masked_OF_VERSION_1_4_populate(
    of_oxm_ipv6_dst_masked_t *obj, int value);
extern int of_oxm_ipv6_dst_masked_OF_VERSION_1_4_check(
    of_oxm_ipv6_dst_masked_t *obj, int value);
extern int of_oxm_ipv6_dst_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_ipv6_dst_masked_t *obj, int value);
extern int of_oxm_ipv6_dst_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_ipv6_dst_masked_t *obj, int value);

extern int of_oxm_ipv6_exthdr_OF_VERSION_1_4_populate(
    of_oxm_ipv6_exthdr_t *obj, int value);
extern int of_oxm_ipv6_exthdr_OF_VERSION_1_4_check(
    of_oxm_ipv6_exthdr_t *obj, int value);
extern int of_oxm_ipv6_exthdr_OF_VERSION_1_4_populate_scalars(
    of_oxm_ipv6_exthdr_t *obj, int value);
extern int of_oxm_ipv6_exthdr_OF_VERSION_1_4_check_scalars(
    of_oxm_ipv6_exthdr_t *obj, int value);

extern int of_oxm_ipv6_exthdr_masked_OF_VERSION_1_4_populate(
    of_oxm_ipv6_exthdr_masked_t *obj, int value);
extern int of_oxm_ipv6_exthdr_masked_OF_VERSION_1_4_check(
    of_oxm_ipv6_exthdr_masked_t *obj, int value);
extern int of_oxm_ipv6_exthdr_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_ipv6_exthdr_masked_t *obj, int value);
extern int of_oxm_ipv6_exthdr_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_ipv6_exthdr_masked_t *obj, int value);

extern int of_oxm_ipv6_flabel_OF_VERSION_1_4_populate(
    of_oxm_ipv6_flabel_t *obj, int value);
extern int of_oxm_ipv6_flabel_OF_VERSION_1_4_check(
    of_oxm_ipv6_flabel_t *obj, int value);
extern int of_oxm_ipv6_flabel_OF_VERSION_1_4_populate_scalars(
    of_oxm_ipv6_flabel_t *obj, int value);
extern int of_oxm_ipv6_flabel_OF_VERSION_1_4_check_scalars(
    of_oxm_ipv6_flabel_t *obj, int value);

extern int of_oxm_ipv6_flabel_masked_OF_VERSION_1_4_populate(
    of_oxm_ipv6_flabel_masked_t *obj, int value);
extern int of_oxm_ipv6_flabel_masked_OF_VERSION_1_4_check(
    of_oxm_ipv6_flabel_masked_t *obj, int value);
extern int of_oxm_ipv6_flabel_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_ipv6_flabel_masked_t *obj, int value);
extern int of_oxm_ipv6_flabel_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_ipv6_flabel_masked_t *obj, int value);

extern int of_oxm_ipv6_nd_sll_OF_VERSION_1_4_populate(
    of_oxm_ipv6_nd_sll_t *obj, int value);
extern int of_oxm_ipv6_nd_sll_OF_VERSION_1_4_check(
    of_oxm_ipv6_nd_sll_t *obj, int value);
extern int of_oxm_ipv6_nd_sll_OF_VERSION_1_4_populate_scalars(
    of_oxm_ipv6_nd_sll_t *obj, int value);
extern int of_oxm_ipv6_nd_sll_OF_VERSION_1_4_check_scalars(
    of_oxm_ipv6_nd_sll_t *obj, int value);

extern int of_oxm_ipv6_nd_sll_masked_OF_VERSION_1_4_populate(
    of_oxm_ipv6_nd_sll_masked_t *obj, int value);
extern int of_oxm_ipv6_nd_sll_masked_OF_VERSION_1_4_check(
    of_oxm_ipv6_nd_sll_masked_t *obj, int value);
extern int of_oxm_ipv6_nd_sll_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_ipv6_nd_sll_masked_t *obj, int value);
extern int of_oxm_ipv6_nd_sll_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_ipv6_nd_sll_masked_t *obj, int value);

extern int of_oxm_ipv6_nd_target_OF_VERSION_1_4_populate(
    of_oxm_ipv6_nd_target_t *obj, int value);
extern int of_oxm_ipv6_nd_target_OF_VERSION_1_4_check(
    of_oxm_ipv6_nd_target_t *obj, int value);
extern int of_oxm_ipv6_nd_target_OF_VERSION_1_4_populate_scalars(
    of_oxm_ipv6_nd_target_t *obj, int value);
extern int of_oxm_ipv6_nd_target_OF_VERSION_1_4_check_scalars(
    of_oxm_ipv6_nd_target_t *obj, int value);

extern int of_oxm_ipv6_nd_target_masked_OF_VERSION_1_4_populate(
    of_oxm_ipv6_nd_target_masked_t *obj, int value);
extern int of_oxm_ipv6_nd_target_masked_OF_VERSION_1_4_check(
    of_oxm_ipv6_nd_target_masked_t *obj, int value);
extern int of_oxm_ipv6_nd_target_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_ipv6_nd_target_masked_t *obj, int value);
extern int of_oxm_ipv6_nd_target_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_ipv6_nd_target_masked_t *obj, int value);

extern int of_oxm_ipv6_nd_tll_OF_VERSION_1_4_populate(
    of_oxm_ipv6_nd_tll_t *obj, int value);
extern int of_oxm_ipv6_nd_tll_OF_VERSION_1_4_check(
    of_oxm_ipv6_nd_tll_t *obj, int value);
extern int of_oxm_ipv6_nd_tll_OF_VERSION_1_4_populate_scalars(
    of_oxm_ipv6_nd_tll_t *obj, int value);
extern int of_oxm_ipv6_nd_tll_OF_VERSION_1_4_check_scalars(
    of_oxm_ipv6_nd_tll_t *obj, int value);

extern int of_oxm_ipv6_nd_tll_masked_OF_VERSION_1_4_populate(
    of_oxm_ipv6_nd_tll_masked_t *obj, int value);
extern int of_oxm_ipv6_nd_tll_masked_OF_VERSION_1_4_check(
    of_oxm_ipv6_nd_tll_masked_t *obj, int value);
extern int of_oxm_ipv6_nd_tll_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_ipv6_nd_tll_masked_t *obj, int value);
extern int of_oxm_ipv6_nd_tll_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_ipv6_nd_tll_masked_t *obj, int value);

extern int of_oxm_ipv6_src_OF_VERSION_1_4_populate(
    of_oxm_ipv6_src_t *obj, int value);
extern int of_oxm_ipv6_src_OF_VERSION_1_4_check(
    of_oxm_ipv6_src_t *obj, int value);
extern int of_oxm_ipv6_src_OF_VERSION_1_4_populate_scalars(
    of_oxm_ipv6_src_t *obj, int value);
extern int of_oxm_ipv6_src_OF_VERSION_1_4_check_scalars(
    of_oxm_ipv6_src_t *obj, int value);

extern int of_oxm_ipv6_src_masked_OF_VERSION_1_4_populate(
    of_oxm_ipv6_src_masked_t *obj, int value);
extern int of_oxm_ipv6_src_masked_OF_VERSION_1_4_check(
    of_oxm_ipv6_src_masked_t *obj, int value);
extern int of_oxm_ipv6_src_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_ipv6_src_masked_t *obj, int value);
extern int of_oxm_ipv6_src_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_ipv6_src_masked_t *obj, int value);

extern int of_oxm_metadata_OF_VERSION_1_4_populate(
    of_oxm_metadata_t *obj, int value);
extern int of_oxm_metadata_OF_VERSION_1_4_check(
    of_oxm_metadata_t *obj, int value);
extern int of_oxm_metadata_OF_VERSION_1_4_populate_scalars(
    of_oxm_metadata_t *obj, int value);
extern int of_oxm_metadata_OF_VERSION_1_4_check_scalars(
    of_oxm_metadata_t *obj, int value);

extern int of_oxm_metadata_masked_OF_VERSION_1_4_populate(
    of_oxm_metadata_masked_t *obj, int value);
extern int of_oxm_metadata_masked_OF_VERSION_1_4_check(
    of_oxm_metadata_masked_t *obj, int value);
extern int of_oxm_metadata_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_metadata_masked_t *obj, int value);
extern int of_oxm_metadata_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_metadata_masked_t *obj, int value);

extern int of_oxm_mpls_bos_OF_VERSION_1_4_populate(
    of_oxm_mpls_bos_t *obj, int value);
extern int of_oxm_mpls_bos_OF_VERSION_1_4_check(
    of_oxm_mpls_bos_t *obj, int value);
extern int of_oxm_mpls_bos_OF_VERSION_1_4_populate_scalars(
    of_oxm_mpls_bos_t *obj, int value);
extern int of_oxm_mpls_bos_OF_VERSION_1_4_check_scalars(
    of_oxm_mpls_bos_t *obj, int value);

extern int of_oxm_mpls_bos_masked_OF_VERSION_1_4_populate(
    of_oxm_mpls_bos_masked_t *obj, int value);
extern int of_oxm_mpls_bos_masked_OF_VERSION_1_4_check(
    of_oxm_mpls_bos_masked_t *obj, int value);
extern int of_oxm_mpls_bos_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_mpls_bos_masked_t *obj, int value);
extern int of_oxm_mpls_bos_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_mpls_bos_masked_t *obj, int value);

extern int of_oxm_mpls_label_OF_VERSION_1_4_populate(
    of_oxm_mpls_label_t *obj, int value);
extern int of_oxm_mpls_label_OF_VERSION_1_4_check(
    of_oxm_mpls_label_t *obj, int value);
extern int of_oxm_mpls_label_OF_VERSION_1_4_populate_scalars(
    of_oxm_mpls_label_t *obj, int value);
extern int of_oxm_mpls_label_OF_VERSION_1_4_check_scalars(
    of_oxm_mpls_label_t *obj, int value);

extern int of_oxm_mpls_label_masked_OF_VERSION_1_4_populate(
    of_oxm_mpls_label_masked_t *obj, int value);
extern int of_oxm_mpls_label_masked_OF_VERSION_1_4_check(
    of_oxm_mpls_label_masked_t *obj, int value);
extern int of_oxm_mpls_label_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_mpls_label_masked_t *obj, int value);
extern int of_oxm_mpls_label_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_mpls_label_masked_t *obj, int value);

extern int of_oxm_mpls_tc_OF_VERSION_1_4_populate(
    of_oxm_mpls_tc_t *obj, int value);
extern int of_oxm_mpls_tc_OF_VERSION_1_4_check(
    of_oxm_mpls_tc_t *obj, int value);
extern int of_oxm_mpls_tc_OF_VERSION_1_4_populate_scalars(
    of_oxm_mpls_tc_t *obj, int value);
extern int of_oxm_mpls_tc_OF_VERSION_1_4_check_scalars(
    of_oxm_mpls_tc_t *obj, int value);

extern int of_oxm_mpls_tc_masked_OF_VERSION_1_4_populate(
    of_oxm_mpls_tc_masked_t *obj, int value);
extern int of_oxm_mpls_tc_masked_OF_VERSION_1_4_check(
    of_oxm_mpls_tc_masked_t *obj, int value);
extern int of_oxm_mpls_tc_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_mpls_tc_masked_t *obj, int value);
extern int of_oxm_mpls_tc_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_mpls_tc_masked_t *obj, int value);

extern int of_oxm_ovs_tcp_flags_OF_VERSION_1_4_populate(
    of_oxm_ovs_tcp_flags_t *obj, int value);
extern int of_oxm_ovs_tcp_flags_OF_VERSION_1_4_check(
    of_oxm_ovs_tcp_flags_t *obj, int value);
extern int of_oxm_ovs_tcp_flags_OF_VERSION_1_4_populate_scalars(
    of_oxm_ovs_tcp_flags_t *obj, int value);
extern int of_oxm_ovs_tcp_flags_OF_VERSION_1_4_check_scalars(
    of_oxm_ovs_tcp_flags_t *obj, int value);

extern int of_oxm_ovs_tcp_flags_masked_OF_VERSION_1_4_populate(
    of_oxm_ovs_tcp_flags_masked_t *obj, int value);
extern int of_oxm_ovs_tcp_flags_masked_OF_VERSION_1_4_check(
    of_oxm_ovs_tcp_flags_masked_t *obj, int value);
extern int of_oxm_ovs_tcp_flags_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_ovs_tcp_flags_masked_t *obj, int value);
extern int of_oxm_ovs_tcp_flags_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_ovs_tcp_flags_masked_t *obj, int value);

extern int of_oxm_pbb_uca_OF_VERSION_1_4_populate(
    of_oxm_pbb_uca_t *obj, int value);
extern int of_oxm_pbb_uca_OF_VERSION_1_4_check(
    of_oxm_pbb_uca_t *obj, int value);
extern int of_oxm_pbb_uca_OF_VERSION_1_4_populate_scalars(
    of_oxm_pbb_uca_t *obj, int value);
extern int of_oxm_pbb_uca_OF_VERSION_1_4_check_scalars(
    of_oxm_pbb_uca_t *obj, int value);

extern int of_oxm_pbb_uca_masked_OF_VERSION_1_4_populate(
    of_oxm_pbb_uca_masked_t *obj, int value);
extern int of_oxm_pbb_uca_masked_OF_VERSION_1_4_check(
    of_oxm_pbb_uca_masked_t *obj, int value);
extern int of_oxm_pbb_uca_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_pbb_uca_masked_t *obj, int value);
extern int of_oxm_pbb_uca_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_pbb_uca_masked_t *obj, int value);

extern int of_oxm_sctp_dst_OF_VERSION_1_4_populate(
    of_oxm_sctp_dst_t *obj, int value);
extern int of_oxm_sctp_dst_OF_VERSION_1_4_check(
    of_oxm_sctp_dst_t *obj, int value);
extern int of_oxm_sctp_dst_OF_VERSION_1_4_populate_scalars(
    of_oxm_sctp_dst_t *obj, int value);
extern int of_oxm_sctp_dst_OF_VERSION_1_4_check_scalars(
    of_oxm_sctp_dst_t *obj, int value);

extern int of_oxm_sctp_dst_masked_OF_VERSION_1_4_populate(
    of_oxm_sctp_dst_masked_t *obj, int value);
extern int of_oxm_sctp_dst_masked_OF_VERSION_1_4_check(
    of_oxm_sctp_dst_masked_t *obj, int value);
extern int of_oxm_sctp_dst_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_sctp_dst_masked_t *obj, int value);
extern int of_oxm_sctp_dst_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_sctp_dst_masked_t *obj, int value);

extern int of_oxm_sctp_src_OF_VERSION_1_4_populate(
    of_oxm_sctp_src_t *obj, int value);
extern int of_oxm_sctp_src_OF_VERSION_1_4_check(
    of_oxm_sctp_src_t *obj, int value);
extern int of_oxm_sctp_src_OF_VERSION_1_4_populate_scalars(
    of_oxm_sctp_src_t *obj, int value);
extern int of_oxm_sctp_src_OF_VERSION_1_4_check_scalars(
    of_oxm_sctp_src_t *obj, int value);

extern int of_oxm_sctp_src_masked_OF_VERSION_1_4_populate(
    of_oxm_sctp_src_masked_t *obj, int value);
extern int of_oxm_sctp_src_masked_OF_VERSION_1_4_check(
    of_oxm_sctp_src_masked_t *obj, int value);
extern int of_oxm_sctp_src_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_sctp_src_masked_t *obj, int value);
extern int of_oxm_sctp_src_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_sctp_src_masked_t *obj, int value);

extern int of_oxm_tcp_dst_OF_VERSION_1_4_populate(
    of_oxm_tcp_dst_t *obj, int value);
extern int of_oxm_tcp_dst_OF_VERSION_1_4_check(
    of_oxm_tcp_dst_t *obj, int value);
extern int of_oxm_tcp_dst_OF_VERSION_1_4_populate_scalars(
    of_oxm_tcp_dst_t *obj, int value);
extern int of_oxm_tcp_dst_OF_VERSION_1_4_check_scalars(
    of_oxm_tcp_dst_t *obj, int value);

extern int of_oxm_tcp_dst_masked_OF_VERSION_1_4_populate(
    of_oxm_tcp_dst_masked_t *obj, int value);
extern int of_oxm_tcp_dst_masked_OF_VERSION_1_4_check(
    of_oxm_tcp_dst_masked_t *obj, int value);
extern int of_oxm_tcp_dst_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_tcp_dst_masked_t *obj, int value);
extern int of_oxm_tcp_dst_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_tcp_dst_masked_t *obj, int value);

extern int of_oxm_tcp_src_OF_VERSION_1_4_populate(
    of_oxm_tcp_src_t *obj, int value);
extern int of_oxm_tcp_src_OF_VERSION_1_4_check(
    of_oxm_tcp_src_t *obj, int value);
extern int of_oxm_tcp_src_OF_VERSION_1_4_populate_scalars(
    of_oxm_tcp_src_t *obj, int value);
extern int of_oxm_tcp_src_OF_VERSION_1_4_check_scalars(
    of_oxm_tcp_src_t *obj, int value);

extern int of_oxm_tcp_src_masked_OF_VERSION_1_4_populate(
    of_oxm_tcp_src_masked_t *obj, int value);
extern int of_oxm_tcp_src_masked_OF_VERSION_1_4_check(
    of_oxm_tcp_src_masked_t *obj, int value);
extern int of_oxm_tcp_src_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_tcp_src_masked_t *obj, int value);
extern int of_oxm_tcp_src_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_tcp_src_masked_t *obj, int value);

extern int of_oxm_tunnel_id_OF_VERSION_1_4_populate(
    of_oxm_tunnel_id_t *obj, int value);
extern int of_oxm_tunnel_id_OF_VERSION_1_4_check(
    of_oxm_tunnel_id_t *obj, int value);
extern int of_oxm_tunnel_id_OF_VERSION_1_4_populate_scalars(
    of_oxm_tunnel_id_t *obj, int value);
extern int of_oxm_tunnel_id_OF_VERSION_1_4_check_scalars(
    of_oxm_tunnel_id_t *obj, int value);

extern int of_oxm_tunnel_id_masked_OF_VERSION_1_4_populate(
    of_oxm_tunnel_id_masked_t *obj, int value);
extern int of_oxm_tunnel_id_masked_OF_VERSION_1_4_check(
    of_oxm_tunnel_id_masked_t *obj, int value);
extern int of_oxm_tunnel_id_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_tunnel_id_masked_t *obj, int value);
extern int of_oxm_tunnel_id_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_tunnel_id_masked_t *obj, int value);

extern int of_oxm_tunnel_ipv4_dst_OF_VERSION_1_4_populate(
    of_oxm_tunnel_ipv4_dst_t *obj, int value);
extern int of_oxm_tunnel_ipv4_dst_OF_VERSION_1_4_check(
    of_oxm_tunnel_ipv4_dst_t *obj, int value);
extern int of_oxm_tunnel_ipv4_dst_OF_VERSION_1_4_populate_scalars(
    of_oxm_tunnel_ipv4_dst_t *obj, int value);
extern int of_oxm_tunnel_ipv4_dst_OF_VERSION_1_4_check_scalars(
    of_oxm_tunnel_ipv4_dst_t *obj, int value);

extern int of_oxm_tunnel_ipv4_dst_masked_OF_VERSION_1_4_populate(
    of_oxm_tunnel_ipv4_dst_masked_t *obj, int value);
extern int of_oxm_tunnel_ipv4_dst_masked_OF_VERSION_1_4_check(
    of_oxm_tunnel_ipv4_dst_masked_t *obj, int value);
extern int of_oxm_tunnel_ipv4_dst_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_tunnel_ipv4_dst_masked_t *obj, int value);
extern int of_oxm_tunnel_ipv4_dst_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_tunnel_ipv4_dst_masked_t *obj, int value);

extern int of_oxm_tunnel_ipv4_src_OF_VERSION_1_4_populate(
    of_oxm_tunnel_ipv4_src_t *obj, int value);
extern int of_oxm_tunnel_ipv4_src_OF_VERSION_1_4_check(
    of_oxm_tunnel_ipv4_src_t *obj, int value);
extern int of_oxm_tunnel_ipv4_src_OF_VERSION_1_4_populate_scalars(
    of_oxm_tunnel_ipv4_src_t *obj, int value);
extern int of_oxm_tunnel_ipv4_src_OF_VERSION_1_4_check_scalars(
    of_oxm_tunnel_ipv4_src_t *obj, int value);

extern int of_oxm_tunnel_ipv4_src_masked_OF_VERSION_1_4_populate(
    of_oxm_tunnel_ipv4_src_masked_t *obj, int value);
extern int of_oxm_tunnel_ipv4_src_masked_OF_VERSION_1_4_check(
    of_oxm_tunnel_ipv4_src_masked_t *obj, int value);
extern int of_oxm_tunnel_ipv4_src_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_tunnel_ipv4_src_masked_t *obj, int value);
extern int of_oxm_tunnel_ipv4_src_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_tunnel_ipv4_src_masked_t *obj, int value);

extern int of_oxm_udp_dst_OF_VERSION_1_4_populate(
    of_oxm_udp_dst_t *obj, int value);
extern int of_oxm_udp_dst_OF_VERSION_1_4_check(
    of_oxm_udp_dst_t *obj, int value);
extern int of_oxm_udp_dst_OF_VERSION_1_4_populate_scalars(
    of_oxm_udp_dst_t *obj, int value);
extern int of_oxm_udp_dst_OF_VERSION_1_4_check_scalars(
    of_oxm_udp_dst_t *obj, int value);

extern int of_oxm_udp_dst_masked_OF_VERSION_1_4_populate(
    of_oxm_udp_dst_masked_t *obj, int value);
extern int of_oxm_udp_dst_masked_OF_VERSION_1_4_check(
    of_oxm_udp_dst_masked_t *obj, int value);
extern int of_oxm_udp_dst_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_udp_dst_masked_t *obj, int value);
extern int of_oxm_udp_dst_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_udp_dst_masked_t *obj, int value);

extern int of_oxm_udp_src_OF_VERSION_1_4_populate(
    of_oxm_udp_src_t *obj, int value);
extern int of_oxm_udp_src_OF_VERSION_1_4_check(
    of_oxm_udp_src_t *obj, int value);
extern int of_oxm_udp_src_OF_VERSION_1_4_populate_scalars(
    of_oxm_udp_src_t *obj, int value);
extern int of_oxm_udp_src_OF_VERSION_1_4_check_scalars(
    of_oxm_udp_src_t *obj, int value);

extern int of_oxm_udp_src_masked_OF_VERSION_1_4_populate(
    of_oxm_udp_src_masked_t *obj, int value);
extern int of_oxm_udp_src_masked_OF_VERSION_1_4_check(
    of_oxm_udp_src_masked_t *obj, int value);
extern int of_oxm_udp_src_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_udp_src_masked_t *obj, int value);
extern int of_oxm_udp_src_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_udp_src_masked_t *obj, int value);

extern int of_oxm_vlan_pcp_OF_VERSION_1_4_populate(
    of_oxm_vlan_pcp_t *obj, int value);
extern int of_oxm_vlan_pcp_OF_VERSION_1_4_check(
    of_oxm_vlan_pcp_t *obj, int value);
extern int of_oxm_vlan_pcp_OF_VERSION_1_4_populate_scalars(
    of_oxm_vlan_pcp_t *obj, int value);
extern int of_oxm_vlan_pcp_OF_VERSION_1_4_check_scalars(
    of_oxm_vlan_pcp_t *obj, int value);

extern int of_oxm_vlan_pcp_masked_OF_VERSION_1_4_populate(
    of_oxm_vlan_pcp_masked_t *obj, int value);
extern int of_oxm_vlan_pcp_masked_OF_VERSION_1_4_check(
    of_oxm_vlan_pcp_masked_t *obj, int value);
extern int of_oxm_vlan_pcp_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_vlan_pcp_masked_t *obj, int value);
extern int of_oxm_vlan_pcp_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_vlan_pcp_masked_t *obj, int value);

extern int of_oxm_vlan_vid_OF_VERSION_1_4_populate(
    of_oxm_vlan_vid_t *obj, int value);
extern int of_oxm_vlan_vid_OF_VERSION_1_4_check(
    of_oxm_vlan_vid_t *obj, int value);
extern int of_oxm_vlan_vid_OF_VERSION_1_4_populate_scalars(
    of_oxm_vlan_vid_t *obj, int value);
extern int of_oxm_vlan_vid_OF_VERSION_1_4_check_scalars(
    of_oxm_vlan_vid_t *obj, int value);

extern int of_oxm_vlan_vid_masked_OF_VERSION_1_4_populate(
    of_oxm_vlan_vid_masked_t *obj, int value);
extern int of_oxm_vlan_vid_masked_OF_VERSION_1_4_check(
    of_oxm_vlan_vid_masked_t *obj, int value);
extern int of_oxm_vlan_vid_masked_OF_VERSION_1_4_populate_scalars(
    of_oxm_vlan_vid_masked_t *obj, int value);
extern int of_oxm_vlan_vid_masked_OF_VERSION_1_4_check_scalars(
    of_oxm_vlan_vid_masked_t *obj, int value);

extern int of_packet_queue_OF_VERSION_1_4_populate(
    of_packet_queue_t *obj, int value);
extern int of_packet_queue_OF_VERSION_1_4_check(
    of_packet_queue_t *obj, int value);
extern int of_packet_queue_OF_VERSION_1_4_populate_scalars(
    of_packet_queue_t *obj, int value);
extern int of_packet_queue_OF_VERSION_1_4_check_scalars(
    of_packet_queue_t *obj, int value);

extern int of_port_desc_OF_VERSION_1_4_populate(
    of_port_desc_t *obj, int value);
extern int of_port_desc_OF_VERSION_1_4_check(
    of_port_desc_t *obj, int value);
extern int of_port_desc_OF_VERSION_1_4_populate_scalars(
    of_port_desc_t *obj, int value);
extern int of_port_desc_OF_VERSION_1_4_check_scalars(
    of_port_desc_t *obj, int value);

extern int of_port_desc_prop_bsn_breakout_OF_VERSION_1_4_populate(
    of_port_desc_prop_bsn_breakout_t *obj, int value);
extern int of_port_desc_prop_bsn_breakout_OF_VERSION_1_4_check(
    of_port_desc_prop_bsn_breakout_t *obj, int value);
extern int of_port_desc_prop_bsn_breakout_OF_VERSION_1_4_populate_scalars(
    of_port_desc_prop_bsn_breakout_t *obj, int value);
extern int of_port_desc_prop_bsn_breakout_OF_VERSION_1_4_check_scalars(
    of_port_desc_prop_bsn_breakout_t *obj, int value);

extern int of_port_desc_prop_bsn_forward_error_correction_OF_VERSION_1_4_populate(
    of_port_desc_prop_bsn_forward_error_correction_t *obj, int value);
extern int of_port_desc_prop_bsn_forward_error_correction_OF_VERSION_1_4_check(
    of_port_desc_prop_bsn_forward_error_correction_t *obj, int value);
extern int of_port_desc_prop_bsn_forward_error_correction_OF_VERSION_1_4_populate_scalars(
    of_port_desc_prop_bsn_forward_error_correction_t *obj, int value);
extern int of_port_desc_prop_bsn_forward_error_correction_OF_VERSION_1_4_check_scalars(
    of_port_desc_prop_bsn_forward_error_correction_t *obj, int value);

extern int of_port_desc_prop_bsn_generation_id_OF_VERSION_1_4_populate(
    of_port_desc_prop_bsn_generation_id_t *obj, int value);
extern int of_port_desc_prop_bsn_generation_id_OF_VERSION_1_4_check(
    of_port_desc_prop_bsn_generation_id_t *obj, int value);
extern int of_port_desc_prop_bsn_generation_id_OF_VERSION_1_4_populate_scalars(
    of_port_desc_prop_bsn_generation_id_t *obj, int value);
extern int of_port_desc_prop_bsn_generation_id_OF_VERSION_1_4_check_scalars(
    of_port_desc_prop_bsn_generation_id_t *obj, int value);

extern int of_port_desc_prop_bsn_speed_capabilities_OF_VERSION_1_4_populate(
    of_port_desc_prop_bsn_speed_capabilities_t *obj, int value);
extern int of_port_desc_prop_bsn_speed_capabilities_OF_VERSION_1_4_check(
    of_port_desc_prop_bsn_speed_capabilities_t *obj, int value);
extern int of_port_desc_prop_bsn_speed_capabilities_OF_VERSION_1_4_populate_scalars(
    of_port_desc_prop_bsn_speed_capabilities_t *obj, int value);
extern int of_port_desc_prop_bsn_speed_capabilities_OF_VERSION_1_4_check_scalars(
    of_port_desc_prop_bsn_speed_capabilities_t *obj, int value);

extern int of_port_desc_prop_bsn_uplink_OF_VERSION_1_4_populate(
    of_port_desc_prop_bsn_uplink_t *obj, int value);
extern int of_port_desc_prop_bsn_uplink_OF_VERSION_1_4_check(
    of_port_desc_prop_bsn_uplink_t *obj, int value);
extern int of_port_desc_prop_bsn_uplink_OF_VERSION_1_4_populate_scalars(
    of_port_desc_prop_bsn_uplink_t *obj, int value);
extern int of_port_desc_prop_bsn_uplink_OF_VERSION_1_4_check_scalars(
    of_port_desc_prop_bsn_uplink_t *obj, int value);

extern int of_port_desc_prop_ethernet_OF_VERSION_1_4_populate(
    of_port_desc_prop_ethernet_t *obj, int value);
extern int of_port_desc_prop_ethernet_OF_VERSION_1_4_check(
    of_port_desc_prop_ethernet_t *obj, int value);
extern int of_port_desc_prop_ethernet_OF_VERSION_1_4_populate_scalars(
    of_port_desc_prop_ethernet_t *obj, int value);
extern int of_port_desc_prop_ethernet_OF_VERSION_1_4_check_scalars(
    of_port_desc_prop_ethernet_t *obj, int value);

extern int of_port_desc_prop_optical_OF_VERSION_1_4_populate(
    of_port_desc_prop_optical_t *obj, int value);
extern int of_port_desc_prop_optical_OF_VERSION_1_4_check(
    of_port_desc_prop_optical_t *obj, int value);
extern int of_port_desc_prop_optical_OF_VERSION_1_4_populate_scalars(
    of_port_desc_prop_optical_t *obj, int value);
extern int of_port_desc_prop_optical_OF_VERSION_1_4_check_scalars(
    of_port_desc_prop_optical_t *obj, int value);

extern int of_port_mod_prop_ethernet_OF_VERSION_1_4_populate(
    of_port_mod_prop_ethernet_t *obj, int value);
extern int of_port_mod_prop_ethernet_OF_VERSION_1_4_check(
    of_port_mod_prop_ethernet_t *obj, int value);
extern int of_port_mod_prop_ethernet_OF_VERSION_1_4_populate_scalars(
    of_port_mod_prop_ethernet_t *obj, int value);
extern int of_port_mod_prop_ethernet_OF_VERSION_1_4_check_scalars(
    of_port_mod_prop_ethernet_t *obj, int value);

extern int of_port_mod_prop_optical_OF_VERSION_1_4_populate(
    of_port_mod_prop_optical_t *obj, int value);
extern int of_port_mod_prop_optical_OF_VERSION_1_4_check(
    of_port_mod_prop_optical_t *obj, int value);
extern int of_port_mod_prop_optical_OF_VERSION_1_4_populate_scalars(
    of_port_mod_prop_optical_t *obj, int value);
extern int of_port_mod_prop_optical_OF_VERSION_1_4_check_scalars(
    of_port_mod_prop_optical_t *obj, int value);

extern int of_port_stats_entry_OF_VERSION_1_4_populate(
    of_port_stats_entry_t *obj, int value);
extern int of_port_stats_entry_OF_VERSION_1_4_check(
    of_port_stats_entry_t *obj, int value);
extern int of_port_stats_entry_OF_VERSION_1_4_populate_scalars(
    of_port_stats_entry_t *obj, int value);
extern int of_port_stats_entry_OF_VERSION_1_4_check_scalars(
    of_port_stats_entry_t *obj, int value);

extern int of_port_stats_prop_ethernet_OF_VERSION_1_4_populate(
    of_port_stats_prop_ethernet_t *obj, int value);
extern int of_port_stats_prop_ethernet_OF_VERSION_1_4_check(
    of_port_stats_prop_ethernet_t *obj, int value);
extern int of_port_stats_prop_ethernet_OF_VERSION_1_4_populate_scalars(
    of_port_stats_prop_ethernet_t *obj, int value);
extern int of_port_stats_prop_ethernet_OF_VERSION_1_4_check_scalars(
    of_port_stats_prop_ethernet_t *obj, int value);

extern int of_port_stats_prop_experimenter_intel_OF_VERSION_1_4_populate(
    of_port_stats_prop_experimenter_intel_t *obj, int value);
extern int of_port_stats_prop_experimenter_intel_OF_VERSION_1_4_check(
    of_port_stats_prop_experimenter_intel_t *obj, int value);
extern int of_port_stats_prop_experimenter_intel_OF_VERSION_1_4_populate_scalars(
    of_port_stats_prop_experimenter_intel_t *obj, int value);
extern int of_port_stats_prop_experimenter_intel_OF_VERSION_1_4_check_scalars(
    of_port_stats_prop_experimenter_intel_t *obj, int value);

extern int of_port_stats_prop_optical_OF_VERSION_1_4_populate(
    of_port_stats_prop_optical_t *obj, int value);
extern int of_port_stats_prop_optical_OF_VERSION_1_4_check(
    of_port_stats_prop_optical_t *obj, int value);
extern int of_port_stats_prop_optical_OF_VERSION_1_4_populate_scalars(
    of_port_stats_prop_optical_t *obj, int value);
extern int of_port_stats_prop_optical_OF_VERSION_1_4_check_scalars(
    of_port_stats_prop_optical_t *obj, int value);

extern int of_queue_desc_OF_VERSION_1_4_populate(
    of_queue_desc_t *obj, int value);
extern int of_queue_desc_OF_VERSION_1_4_check(
    of_queue_desc_t *obj, int value);
extern int of_queue_desc_OF_VERSION_1_4_populate_scalars(
    of_queue_desc_t *obj, int value);
extern int of_queue_desc_OF_VERSION_1_4_check_scalars(
    of_queue_desc_t *obj, int value);

extern int of_queue_desc_prop_bsn_queue_name_OF_VERSION_1_4_populate(
    of_queue_desc_prop_bsn_queue_name_t *obj, int value);
extern int of_queue_desc_prop_bsn_queue_name_OF_VERSION_1_4_check(
    of_queue_desc_prop_bsn_queue_name_t *obj, int value);
extern int of_queue_desc_prop_bsn_queue_name_OF_VERSION_1_4_populate_scalars(
    of_queue_desc_prop_bsn_queue_name_t *obj, int value);
extern int of_queue_desc_prop_bsn_queue_name_OF_VERSION_1_4_check_scalars(
    of_queue_desc_prop_bsn_queue_name_t *obj, int value);

extern int of_queue_desc_prop_max_rate_OF_VERSION_1_4_populate(
    of_queue_desc_prop_max_rate_t *obj, int value);
extern int of_queue_desc_prop_max_rate_OF_VERSION_1_4_check(
    of_queue_desc_prop_max_rate_t *obj, int value);
extern int of_queue_desc_prop_max_rate_OF_VERSION_1_4_populate_scalars(
    of_queue_desc_prop_max_rate_t *obj, int value);
extern int of_queue_desc_prop_max_rate_OF_VERSION_1_4_check_scalars(
    of_queue_desc_prop_max_rate_t *obj, int value);

extern int of_queue_desc_prop_min_rate_OF_VERSION_1_4_populate(
    of_queue_desc_prop_min_rate_t *obj, int value);
extern int of_queue_desc_prop_min_rate_OF_VERSION_1_4_check(
    of_queue_desc_prop_min_rate_t *obj, int value);
extern int of_queue_desc_prop_min_rate_OF_VERSION_1_4_populate_scalars(
    of_queue_desc_prop_min_rate_t *obj, int value);
extern int of_queue_desc_prop_min_rate_OF_VERSION_1_4_check_scalars(
    of_queue_desc_prop_min_rate_t *obj, int value);

extern int of_queue_prop_max_rate_OF_VERSION_1_4_populate(
    of_queue_prop_max_rate_t *obj, int value);
extern int of_queue_prop_max_rate_OF_VERSION_1_4_check(
    of_queue_prop_max_rate_t *obj, int value);
extern int of_queue_prop_max_rate_OF_VERSION_1_4_populate_scalars(
    of_queue_prop_max_rate_t *obj, int value);
extern int of_queue_prop_max_rate_OF_VERSION_1_4_check_scalars(
    of_queue_prop_max_rate_t *obj, int value);

extern int of_queue_prop_min_rate_OF_VERSION_1_4_populate(
    of_queue_prop_min_rate_t *obj, int value);
extern int of_queue_prop_min_rate_OF_VERSION_1_4_check(
    of_queue_prop_min_rate_t *obj, int value);
extern int of_queue_prop_min_rate_OF_VERSION_1_4_populate_scalars(
    of_queue_prop_min_rate_t *obj, int value);
extern int of_queue_prop_min_rate_OF_VERSION_1_4_check_scalars(
    of_queue_prop_min_rate_t *obj, int value);

extern int of_queue_stats_entry_OF_VERSION_1_4_populate(
    of_queue_stats_entry_t *obj, int value);
extern int of_queue_stats_entry_OF_VERSION_1_4_check(
    of_queue_stats_entry_t *obj, int value);
extern int of_queue_stats_entry_OF_VERSION_1_4_populate_scalars(
    of_queue_stats_entry_t *obj, int value);
extern int of_queue_stats_entry_OF_VERSION_1_4_check_scalars(
    of_queue_stats_entry_t *obj, int value);

extern int of_table_desc_OF_VERSION_1_4_populate(
    of_table_desc_t *obj, int value);
extern int of_table_desc_OF_VERSION_1_4_check(
    of_table_desc_t *obj, int value);
extern int of_table_desc_OF_VERSION_1_4_populate_scalars(
    of_table_desc_t *obj, int value);
extern int of_table_desc_OF_VERSION_1_4_check_scalars(
    of_table_desc_t *obj, int value);

extern int of_table_feature_prop_apply_actions_OF_VERSION_1_4_populate(
    of_table_feature_prop_apply_actions_t *obj, int value);
extern int of_table_feature_prop_apply_actions_OF_VERSION_1_4_check(
    of_table_feature_prop_apply_actions_t *obj, int value);
extern int of_table_feature_prop_apply_actions_OF_VERSION_1_4_populate_scalars(
    of_table_feature_prop_apply_actions_t *obj, int value);
extern int of_table_feature_prop_apply_actions_OF_VERSION_1_4_check_scalars(
    of_table_feature_prop_apply_actions_t *obj, int value);

extern int of_table_feature_prop_apply_actions_miss_OF_VERSION_1_4_populate(
    of_table_feature_prop_apply_actions_miss_t *obj, int value);
extern int of_table_feature_prop_apply_actions_miss_OF_VERSION_1_4_check(
    of_table_feature_prop_apply_actions_miss_t *obj, int value);
extern int of_table_feature_prop_apply_actions_miss_OF_VERSION_1_4_populate_scalars(
    of_table_feature_prop_apply_actions_miss_t *obj, int value);
extern int of_table_feature_prop_apply_actions_miss_OF_VERSION_1_4_check_scalars(
    of_table_feature_prop_apply_actions_miss_t *obj, int value);

extern int of_table_feature_prop_apply_setfield_OF_VERSION_1_4_populate(
    of_table_feature_prop_apply_setfield_t *obj, int value);
extern int of_table_feature_prop_apply_setfield_OF_VERSION_1_4_check(
    of_table_feature_prop_apply_setfield_t *obj, int value);
extern int of_table_feature_prop_apply_setfield_OF_VERSION_1_4_populate_scalars(
    of_table_feature_prop_apply_setfield_t *obj, int value);
extern int of_table_feature_prop_apply_setfield_OF_VERSION_1_4_check_scalars(
    of_table_feature_prop_apply_setfield_t *obj, int value);

extern int of_table_feature_prop_apply_setfield_miss_OF_VERSION_1_4_populate(
    of_table_feature_prop_apply_setfield_miss_t *obj, int value);
extern int of_table_feature_prop_apply_setfield_miss_OF_VERSION_1_4_check(
    of_table_feature_prop_apply_setfield_miss_t *obj, int value);
extern int of_table_feature_prop_apply_setfield_miss_OF_VERSION_1_4_populate_scalars(
    of_table_feature_prop_apply_setfield_miss_t *obj, int value);
extern int of_table_feature_prop_apply_setfield_miss_OF_VERSION_1_4_check_scalars(
    of_table_feature_prop_apply_setfield_miss_t *obj, int value);

extern int of_table_feature_prop_instructions_OF_VERSION_1_4_populate(
    of_table_feature_prop_instructions_t *obj, int value);
extern int of_table_feature_prop_instructions_OF_VERSION_1_4_check(
    of_table_feature_prop_instructions_t *obj, int value);
extern int of_table_feature_prop_instructions_OF_VERSION_1_4_populate_scalars(
    of_table_feature_prop_instructions_t *obj, int value);
extern int of_table_feature_prop_instructions_OF_VERSION_1_4_check_scalars(
    of_table_feature_prop_instructions_t *obj, int value);

extern int of_table_feature_prop_instructions_miss_OF_VERSION_1_4_populate(
    of_table_feature_prop_instructions_miss_t *obj, int value);
extern int of_table_feature_prop_instructions_miss_OF_VERSION_1_4_check(
    of_table_feature_prop_instructions_miss_t *obj, int value);
extern int of_table_feature_prop_instructions_miss_OF_VERSION_1_4_populate_scalars(
    of_table_feature_prop_instructions_miss_t *obj, int value);
extern int of_table_feature_prop_instructions_miss_OF_VERSION_1_4_check_scalars(
    of_table_feature_prop_instructions_miss_t *obj, int value);

extern int of_table_feature_prop_match_OF_VERSION_1_4_populate(
    of_table_feature_prop_match_t *obj, int value);
extern int of_table_feature_prop_match_OF_VERSION_1_4_check(
    of_table_feature_prop_match_t *obj, int value);
extern int of_table_feature_prop_match_OF_VERSION_1_4_populate_scalars(
    of_table_feature_prop_match_t *obj, int value);
extern int of_table_feature_prop_match_OF_VERSION_1_4_check_scalars(
    of_table_feature_prop_match_t *obj, int value);

extern int of_table_feature_prop_next_tables_OF_VERSION_1_4_populate(
    of_table_feature_prop_next_tables_t *obj, int value);
extern int of_table_feature_prop_next_tables_OF_VERSION_1_4_check(
    of_table_feature_prop_next_tables_t *obj, int value);
extern int of_table_feature_prop_next_tables_OF_VERSION_1_4_populate_scalars(
    of_table_feature_prop_next_tables_t *obj, int value);
extern int of_table_feature_prop_next_tables_OF_VERSION_1_4_check_scalars(
    of_table_feature_prop_next_tables_t *obj, int value);

extern int of_table_feature_prop_next_tables_miss_OF_VERSION_1_4_populate(
    of_table_feature_prop_next_tables_miss_t *obj, int value);
extern int of_table_feature_prop_next_tables_miss_OF_VERSION_1_4_check(
    of_table_feature_prop_next_tables_miss_t *obj, int value);
extern int of_table_feature_prop_next_tables_miss_OF_VERSION_1_4_populate_scalars(
    of_table_feature_prop_next_tables_miss_t *obj, int value);
extern int of_table_feature_prop_next_tables_miss_OF_VERSION_1_4_check_scalars(
    of_table_feature_prop_next_tables_miss_t *obj, int value);

extern int of_table_feature_prop_table_sync_from_OF_VERSION_1_4_populate(
    of_table_feature_prop_table_sync_from_t *obj, int value);
extern int of_table_feature_prop_table_sync_from_OF_VERSION_1_4_check(
    of_table_feature_prop_table_sync_from_t *obj, int value);
extern int of_table_feature_prop_table_sync_from_OF_VERSION_1_4_populate_scalars(
    of_table_feature_prop_table_sync_from_t *obj, int value);
extern int of_table_feature_prop_table_sync_from_OF_VERSION_1_4_check_scalars(
    of_table_feature_prop_table_sync_from_t *obj, int value);

extern int of_table_feature_prop_wildcards_OF_VERSION_1_4_populate(
    of_table_feature_prop_wildcards_t *obj, int value);
extern int of_table_feature_prop_wildcards_OF_VERSION_1_4_check(
    of_table_feature_prop_wildcards_t *obj, int value);
extern int of_table_feature_prop_wildcards_OF_VERSION_1_4_populate_scalars(
    of_table_feature_prop_wildcards_t *obj, int value);
extern int of_table_feature_prop_wildcards_OF_VERSION_1_4_check_scalars(
    of_table_feature_prop_wildcards_t *obj, int value);

extern int of_table_feature_prop_write_actions_OF_VERSION_1_4_populate(
    of_table_feature_prop_write_actions_t *obj, int value);
extern int of_table_feature_prop_write_actions_OF_VERSION_1_4_check(
    of_table_feature_prop_write_actions_t *obj, int value);
extern int of_table_feature_prop_write_actions_OF_VERSION_1_4_populate_scalars(
    of_table_feature_prop_write_actions_t *obj, int value);
extern int of_table_feature_prop_write_actions_OF_VERSION_1_4_check_scalars(
    of_table_feature_prop_write_actions_t *obj, int value);

extern int of_table_feature_prop_write_actions_miss_OF_VERSION_1_4_populate(
    of_table_feature_prop_write_actions_miss_t *obj, int value);
extern int of_table_feature_prop_write_actions_miss_OF_VERSION_1_4_check(
    of_table_feature_prop_write_actions_miss_t *obj, int value);
extern int of_table_feature_prop_write_actions_miss_OF_VERSION_1_4_populate_scalars(
    of_table_feature_prop_write_actions_miss_t *obj, int value);
extern int of_table_feature_prop_write_actions_miss_OF_VERSION_1_4_check_scalars(
    of_table_feature_prop_write_actions_miss_t *obj, int value);

extern int of_table_feature_prop_write_setfield_OF_VERSION_1_4_populate(
    of_table_feature_prop_write_setfield_t *obj, int value);
extern int of_table_feature_prop_write_setfield_OF_VERSION_1_4_check(
    of_table_feature_prop_write_setfield_t *obj, int value);
extern int of_table_feature_prop_write_setfield_OF_VERSION_1_4_populate_scalars(
    of_table_feature_prop_write_setfield_t *obj, int value);
extern int of_table_feature_prop_write_setfield_OF_VERSION_1_4_check_scalars(
    of_table_feature_prop_write_setfield_t *obj, int value);

extern int of_table_feature_prop_write_setfield_miss_OF_VERSION_1_4_populate(
    of_table_feature_prop_write_setfield_miss_t *obj, int value);
extern int of_table_feature_prop_write_setfield_miss_OF_VERSION_1_4_check(
    of_table_feature_prop_write_setfield_miss_t *obj, int value);
extern int of_table_feature_prop_write_setfield_miss_OF_VERSION_1_4_populate_scalars(
    of_table_feature_prop_write_setfield_miss_t *obj, int value);
extern int of_table_feature_prop_write_setfield_miss_OF_VERSION_1_4_check_scalars(
    of_table_feature_prop_write_setfield_miss_t *obj, int value);

extern int of_table_features_OF_VERSION_1_4_populate(
    of_table_features_t *obj, int value);
extern int of_table_features_OF_VERSION_1_4_check(
    of_table_features_t *obj, int value);
extern int of_table_features_OF_VERSION_1_4_populate_scalars(
    of_table_features_t *obj, int value);
extern int of_table_features_OF_VERSION_1_4_check_scalars(
    of_table_features_t *obj, int value);

extern int of_table_mod_prop_eviction_OF_VERSION_1_4_populate(
    of_table_mod_prop_eviction_t *obj, int value);
extern int of_table_mod_prop_eviction_OF_VERSION_1_4_check(
    of_table_mod_prop_eviction_t *obj, int value);
extern int of_table_mod_prop_eviction_OF_VERSION_1_4_populate_scalars(
    of_table_mod_prop_eviction_t *obj, int value);
extern int of_table_mod_prop_eviction_OF_VERSION_1_4_check_scalars(
    of_table_mod_prop_eviction_t *obj, int value);

extern int of_table_mod_prop_vacancy_OF_VERSION_1_4_populate(
    of_table_mod_prop_vacancy_t *obj, int value);
extern int of_table_mod_prop_vacancy_OF_VERSION_1_4_check(
    of_table_mod_prop_vacancy_t *obj, int value);
extern int of_table_mod_prop_vacancy_OF_VERSION_1_4_populate_scalars(
    of_table_mod_prop_vacancy_t *obj, int value);
extern int of_table_mod_prop_vacancy_OF_VERSION_1_4_check_scalars(
    of_table_mod_prop_vacancy_t *obj, int value);

extern int of_table_stats_entry_OF_VERSION_1_4_populate(
    of_table_stats_entry_t *obj, int value);
extern int of_table_stats_entry_OF_VERSION_1_4_check(
    of_table_stats_entry_t *obj, int value);
extern int of_table_stats_entry_OF_VERSION_1_4_populate_scalars(
    of_table_stats_entry_t *obj, int value);
extern int of_table_stats_entry_OF_VERSION_1_4_check_scalars(
    of_table_stats_entry_t *obj, int value);

extern int of_uint32_OF_VERSION_1_4_populate(
    of_uint32_t *obj, int value);
extern int of_uint32_OF_VERSION_1_4_check(
    of_uint32_t *obj, int value);
extern int of_uint32_OF_VERSION_1_4_populate_scalars(
    of_uint32_t *obj, int value);
extern int of_uint32_OF_VERSION_1_4_check_scalars(
    of_uint32_t *obj, int value);

extern int of_uint64_OF_VERSION_1_4_populate(
    of_uint64_t *obj, int value);
extern int of_uint64_OF_VERSION_1_4_check(
    of_uint64_t *obj, int value);
extern int of_uint64_OF_VERSION_1_4_populate_scalars(
    of_uint64_t *obj, int value);
extern int of_uint64_OF_VERSION_1_4_check_scalars(
    of_uint64_t *obj, int value);

extern int of_uint8_OF_VERSION_1_4_populate(
    of_uint8_t *obj, int value);
extern int of_uint8_OF_VERSION_1_4_check(
    of_uint8_t *obj, int value);
extern int of_uint8_OF_VERSION_1_4_populate_scalars(
    of_uint8_t *obj, int value);
extern int of_uint8_OF_VERSION_1_4_check_scalars(
    of_uint8_t *obj, int value);

extern int of_list_action_OF_VERSION_1_4_populate(
    of_list_action_t *obj, int value);
extern int of_list_action_OF_VERSION_1_4_check(
    of_list_action_t *obj, int value);
extern int of_list_action_OF_VERSION_1_4_populate_scalars(
    of_list_action_t *obj, int value);
extern int of_list_action_OF_VERSION_1_4_check_scalars(
    of_list_action_t *obj, int value);

extern int of_list_action_id_OF_VERSION_1_4_populate(
    of_list_action_id_t *obj, int value);
extern int of_list_action_id_OF_VERSION_1_4_check(
    of_list_action_id_t *obj, int value);
extern int of_list_action_id_OF_VERSION_1_4_populate_scalars(
    of_list_action_id_t *obj, int value);
extern int of_list_action_id_OF_VERSION_1_4_check_scalars(
    of_list_action_id_t *obj, int value);

extern int of_list_async_config_prop_OF_VERSION_1_4_populate(
    of_list_async_config_prop_t *obj, int value);
extern int of_list_async_config_prop_OF_VERSION_1_4_check(
    of_list_async_config_prop_t *obj, int value);
extern int of_list_async_config_prop_OF_VERSION_1_4_populate_scalars(
    of_list_async_config_prop_t *obj, int value);
extern int of_list_async_config_prop_OF_VERSION_1_4_check_scalars(
    of_list_async_config_prop_t *obj, int value);

extern int of_list_bsn_controller_connection_OF_VERSION_1_4_populate(
    of_list_bsn_controller_connection_t *obj, int value);
extern int of_list_bsn_controller_connection_OF_VERSION_1_4_check(
    of_list_bsn_controller_connection_t *obj, int value);
extern int of_list_bsn_controller_connection_OF_VERSION_1_4_populate_scalars(
    of_list_bsn_controller_connection_t *obj, int value);
extern int of_list_bsn_controller_connection_OF_VERSION_1_4_check_scalars(
    of_list_bsn_controller_connection_t *obj, int value);

extern int of_list_bsn_debug_counter_desc_stats_entry_OF_VERSION_1_4_populate(
    of_list_bsn_debug_counter_desc_stats_entry_t *obj, int value);
extern int of_list_bsn_debug_counter_desc_stats_entry_OF_VERSION_1_4_check(
    of_list_bsn_debug_counter_desc_stats_entry_t *obj, int value);
extern int of_list_bsn_debug_counter_desc_stats_entry_OF_VERSION_1_4_populate_scalars(
    of_list_bsn_debug_counter_desc_stats_entry_t *obj, int value);
extern int of_list_bsn_debug_counter_desc_stats_entry_OF_VERSION_1_4_check_scalars(
    of_list_bsn_debug_counter_desc_stats_entry_t *obj, int value);

extern int of_list_bsn_debug_counter_stats_entry_OF_VERSION_1_4_populate(
    of_list_bsn_debug_counter_stats_entry_t *obj, int value);
extern int of_list_bsn_debug_counter_stats_entry_OF_VERSION_1_4_check(
    of_list_bsn_debug_counter_stats_entry_t *obj, int value);
extern int of_list_bsn_debug_counter_stats_entry_OF_VERSION_1_4_populate_scalars(
    of_list_bsn_debug_counter_stats_entry_t *obj, int value);
extern int of_list_bsn_debug_counter_stats_entry_OF_VERSION_1_4_check_scalars(
    of_list_bsn_debug_counter_stats_entry_t *obj, int value);

extern int of_list_bsn_flow_checksum_bucket_stats_entry_OF_VERSION_1_4_populate(
    of_list_bsn_flow_checksum_bucket_stats_entry_t *obj, int value);
extern int of_list_bsn_flow_checksum_bucket_stats_entry_OF_VERSION_1_4_check(
    of_list_bsn_flow_checksum_bucket_stats_entry_t *obj, int value);
extern int of_list_bsn_flow_checksum_bucket_stats_entry_OF_VERSION_1_4_populate_scalars(
    of_list_bsn_flow_checksum_bucket_stats_entry_t *obj, int value);
extern int of_list_bsn_flow_checksum_bucket_stats_entry_OF_VERSION_1_4_check_scalars(
    of_list_bsn_flow_checksum_bucket_stats_entry_t *obj, int value);

extern int of_list_bsn_generic_stats_entry_OF_VERSION_1_4_populate(
    of_list_bsn_generic_stats_entry_t *obj, int value);
extern int of_list_bsn_generic_stats_entry_OF_VERSION_1_4_check(
    of_list_bsn_generic_stats_entry_t *obj, int value);
extern int of_list_bsn_generic_stats_entry_OF_VERSION_1_4_populate_scalars(
    of_list_bsn_generic_stats_entry_t *obj, int value);
extern int of_list_bsn_generic_stats_entry_OF_VERSION_1_4_check_scalars(
    of_list_bsn_generic_stats_entry_t *obj, int value);

extern int of_list_bsn_gentable_bucket_stats_entry_OF_VERSION_1_4_populate(
    of_list_bsn_gentable_bucket_stats_entry_t *obj, int value);
extern int of_list_bsn_gentable_bucket_stats_entry_OF_VERSION_1_4_check(
    of_list_bsn_gentable_bucket_stats_entry_t *obj, int value);
extern int of_list_bsn_gentable_bucket_stats_entry_OF_VERSION_1_4_populate_scalars(
    of_list_bsn_gentable_bucket_stats_entry_t *obj, int value);
extern int of_list_bsn_gentable_bucket_stats_entry_OF_VERSION_1_4_check_scalars(
    of_list_bsn_gentable_bucket_stats_entry_t *obj, int value);

extern int of_list_bsn_gentable_desc_stats_entry_OF_VERSION_1_4_populate(
    of_list_bsn_gentable_desc_stats_entry_t *obj, int value);
extern int of_list_bsn_gentable_desc_stats_entry_OF_VERSION_1_4_check(
    of_list_bsn_gentable_desc_stats_entry_t *obj, int value);
extern int of_list_bsn_gentable_desc_stats_entry_OF_VERSION_1_4_populate_scalars(
    of_list_bsn_gentable_desc_stats_entry_t *obj, int value);
extern int of_list_bsn_gentable_desc_stats_entry_OF_VERSION_1_4_check_scalars(
    of_list_bsn_gentable_desc_stats_entry_t *obj, int value);

extern int of_list_bsn_gentable_entry_desc_stats_entry_OF_VERSION_1_4_populate(
    of_list_bsn_gentable_entry_desc_stats_entry_t *obj, int value);
extern int of_list_bsn_gentable_entry_desc_stats_entry_OF_VERSION_1_4_check(
    of_list_bsn_gentable_entry_desc_stats_entry_t *obj, int value);
extern int of_list_bsn_gentable_entry_desc_stats_entry_OF_VERSION_1_4_populate_scalars(
    of_list_bsn_gentable_entry_desc_stats_entry_t *obj, int value);
extern int of_list_bsn_gentable_entry_desc_stats_entry_OF_VERSION_1_4_check_scalars(
    of_list_bsn_gentable_entry_desc_stats_entry_t *obj, int value);

extern int of_list_bsn_gentable_entry_stats_entry_OF_VERSION_1_4_populate(
    of_list_bsn_gentable_entry_stats_entry_t *obj, int value);
extern int of_list_bsn_gentable_entry_stats_entry_OF_VERSION_1_4_check(
    of_list_bsn_gentable_entry_stats_entry_t *obj, int value);
extern int of_list_bsn_gentable_entry_stats_entry_OF_VERSION_1_4_populate_scalars(
    of_list_bsn_gentable_entry_stats_entry_t *obj, int value);
extern int of_list_bsn_gentable_entry_stats_entry_OF_VERSION_1_4_check_scalars(
    of_list_bsn_gentable_entry_stats_entry_t *obj, int value);

extern int of_list_bsn_gentable_stats_entry_OF_VERSION_1_4_populate(
    of_list_bsn_gentable_stats_entry_t *obj, int value);
extern int of_list_bsn_gentable_stats_entry_OF_VERSION_1_4_check(
    of_list_bsn_gentable_stats_entry_t *obj, int value);
extern int of_list_bsn_gentable_stats_entry_OF_VERSION_1_4_populate_scalars(
    of_list_bsn_gentable_stats_entry_t *obj, int value);
extern int of_list_bsn_gentable_stats_entry_OF_VERSION_1_4_check_scalars(
    of_list_bsn_gentable_stats_entry_t *obj, int value);

extern int of_list_bsn_interface_OF_VERSION_1_4_populate(
    of_list_bsn_interface_t *obj, int value);
extern int of_list_bsn_interface_OF_VERSION_1_4_check(
    of_list_bsn_interface_t *obj, int value);
extern int of_list_bsn_interface_OF_VERSION_1_4_populate_scalars(
    of_list_bsn_interface_t *obj, int value);
extern int of_list_bsn_interface_OF_VERSION_1_4_check_scalars(
    of_list_bsn_interface_t *obj, int value);

extern int of_list_bsn_lacp_stats_entry_OF_VERSION_1_4_populate(
    of_list_bsn_lacp_stats_entry_t *obj, int value);
extern int of_list_bsn_lacp_stats_entry_OF_VERSION_1_4_check(
    of_list_bsn_lacp_stats_entry_t *obj, int value);
extern int of_list_bsn_lacp_stats_entry_OF_VERSION_1_4_populate_scalars(
    of_list_bsn_lacp_stats_entry_t *obj, int value);
extern int of_list_bsn_lacp_stats_entry_OF_VERSION_1_4_check_scalars(
    of_list_bsn_lacp_stats_entry_t *obj, int value);

extern int of_list_bsn_port_counter_stats_entry_OF_VERSION_1_4_populate(
    of_list_bsn_port_counter_stats_entry_t *obj, int value);
extern int of_list_bsn_port_counter_stats_entry_OF_VERSION_1_4_check(
    of_list_bsn_port_counter_stats_entry_t *obj, int value);
extern int of_list_bsn_port_counter_stats_entry_OF_VERSION_1_4_populate_scalars(
    of_list_bsn_port_counter_stats_entry_t *obj, int value);
extern int of_list_bsn_port_counter_stats_entry_OF_VERSION_1_4_check_scalars(
    of_list_bsn_port_counter_stats_entry_t *obj, int value);

extern int of_list_bsn_switch_pipeline_stats_entry_OF_VERSION_1_4_populate(
    of_list_bsn_switch_pipeline_stats_entry_t *obj, int value);
extern int of_list_bsn_switch_pipeline_stats_entry_OF_VERSION_1_4_check(
    of_list_bsn_switch_pipeline_stats_entry_t *obj, int value);
extern int of_list_bsn_switch_pipeline_stats_entry_OF_VERSION_1_4_populate_scalars(
    of_list_bsn_switch_pipeline_stats_entry_t *obj, int value);
extern int of_list_bsn_switch_pipeline_stats_entry_OF_VERSION_1_4_check_scalars(
    of_list_bsn_switch_pipeline_stats_entry_t *obj, int value);

extern int of_list_bsn_table_checksum_stats_entry_OF_VERSION_1_4_populate(
    of_list_bsn_table_checksum_stats_entry_t *obj, int value);
extern int of_list_bsn_table_checksum_stats_entry_OF_VERSION_1_4_check(
    of_list_bsn_table_checksum_stats_entry_t *obj, int value);
extern int of_list_bsn_table_checksum_stats_entry_OF_VERSION_1_4_populate_scalars(
    of_list_bsn_table_checksum_stats_entry_t *obj, int value);
extern int of_list_bsn_table_checksum_stats_entry_OF_VERSION_1_4_check_scalars(
    of_list_bsn_table_checksum_stats_entry_t *obj, int value);

extern int of_list_bsn_tlv_OF_VERSION_1_4_populate(
    of_list_bsn_tlv_t *obj, int value);
extern int of_list_bsn_tlv_OF_VERSION_1_4_check(
    of_list_bsn_tlv_t *obj, int value);
extern int of_list_bsn_tlv_OF_VERSION_1_4_populate_scalars(
    of_list_bsn_tlv_t *obj, int value);
extern int of_list_bsn_tlv_OF_VERSION_1_4_check_scalars(
    of_list_bsn_tlv_t *obj, int value);

extern int of_list_bsn_vlan_counter_stats_entry_OF_VERSION_1_4_populate(
    of_list_bsn_vlan_counter_stats_entry_t *obj, int value);
extern int of_list_bsn_vlan_counter_stats_entry_OF_VERSION_1_4_check(
    of_list_bsn_vlan_counter_stats_entry_t *obj, int value);
extern int of_list_bsn_vlan_counter_stats_entry_OF_VERSION_1_4_populate_scalars(
    of_list_bsn_vlan_counter_stats_entry_t *obj, int value);
extern int of_list_bsn_vlan_counter_stats_entry_OF_VERSION_1_4_check_scalars(
    of_list_bsn_vlan_counter_stats_entry_t *obj, int value);

extern int of_list_bsn_vlan_mac_OF_VERSION_1_4_populate(
    of_list_bsn_vlan_mac_t *obj, int value);
extern int of_list_bsn_vlan_mac_OF_VERSION_1_4_check(
    of_list_bsn_vlan_mac_t *obj, int value);
extern int of_list_bsn_vlan_mac_OF_VERSION_1_4_populate_scalars(
    of_list_bsn_vlan_mac_t *obj, int value);
extern int of_list_bsn_vlan_mac_OF_VERSION_1_4_check_scalars(
    of_list_bsn_vlan_mac_t *obj, int value);

extern int of_list_bsn_vrf_counter_stats_entry_OF_VERSION_1_4_populate(
    of_list_bsn_vrf_counter_stats_entry_t *obj, int value);
extern int of_list_bsn_vrf_counter_stats_entry_OF_VERSION_1_4_check(
    of_list_bsn_vrf_counter_stats_entry_t *obj, int value);
extern int of_list_bsn_vrf_counter_stats_entry_OF_VERSION_1_4_populate_scalars(
    of_list_bsn_vrf_counter_stats_entry_t *obj, int value);
extern int of_list_bsn_vrf_counter_stats_entry_OF_VERSION_1_4_check_scalars(
    of_list_bsn_vrf_counter_stats_entry_t *obj, int value);

extern int of_list_bucket_OF_VERSION_1_4_populate(
    of_list_bucket_t *obj, int value);
extern int of_list_bucket_OF_VERSION_1_4_check(
    of_list_bucket_t *obj, int value);
extern int of_list_bucket_OF_VERSION_1_4_populate_scalars(
    of_list_bucket_t *obj, int value);
extern int of_list_bucket_OF_VERSION_1_4_check_scalars(
    of_list_bucket_t *obj, int value);

extern int of_list_bucket_counter_OF_VERSION_1_4_populate(
    of_list_bucket_counter_t *obj, int value);
extern int of_list_bucket_counter_OF_VERSION_1_4_check(
    of_list_bucket_counter_t *obj, int value);
extern int of_list_bucket_counter_OF_VERSION_1_4_populate_scalars(
    of_list_bucket_counter_t *obj, int value);
extern int of_list_bucket_counter_OF_VERSION_1_4_check_scalars(
    of_list_bucket_counter_t *obj, int value);

extern int of_list_bundle_prop_OF_VERSION_1_4_populate(
    of_list_bundle_prop_t *obj, int value);
extern int of_list_bundle_prop_OF_VERSION_1_4_check(
    of_list_bundle_prop_t *obj, int value);
extern int of_list_bundle_prop_OF_VERSION_1_4_populate_scalars(
    of_list_bundle_prop_t *obj, int value);
extern int of_list_bundle_prop_OF_VERSION_1_4_check_scalars(
    of_list_bundle_prop_t *obj, int value);

extern int of_list_flow_stats_entry_OF_VERSION_1_4_populate(
    of_list_flow_stats_entry_t *obj, int value);
extern int of_list_flow_stats_entry_OF_VERSION_1_4_check(
    of_list_flow_stats_entry_t *obj, int value);
extern int of_list_flow_stats_entry_OF_VERSION_1_4_populate_scalars(
    of_list_flow_stats_entry_t *obj, int value);
extern int of_list_flow_stats_entry_OF_VERSION_1_4_check_scalars(
    of_list_flow_stats_entry_t *obj, int value);

extern int of_list_group_desc_stats_entry_OF_VERSION_1_4_populate(
    of_list_group_desc_stats_entry_t *obj, int value);
extern int of_list_group_desc_stats_entry_OF_VERSION_1_4_check(
    of_list_group_desc_stats_entry_t *obj, int value);
extern int of_list_group_desc_stats_entry_OF_VERSION_1_4_populate_scalars(
    of_list_group_desc_stats_entry_t *obj, int value);
extern int of_list_group_desc_stats_entry_OF_VERSION_1_4_check_scalars(
    of_list_group_desc_stats_entry_t *obj, int value);

extern int of_list_group_stats_entry_OF_VERSION_1_4_populate(
    of_list_group_stats_entry_t *obj, int value);
extern int of_list_group_stats_entry_OF_VERSION_1_4_check(
    of_list_group_stats_entry_t *obj, int value);
extern int of_list_group_stats_entry_OF_VERSION_1_4_populate_scalars(
    of_list_group_stats_entry_t *obj, int value);
extern int of_list_group_stats_entry_OF_VERSION_1_4_check_scalars(
    of_list_group_stats_entry_t *obj, int value);

extern int of_list_hello_elem_OF_VERSION_1_4_populate(
    of_list_hello_elem_t *obj, int value);
extern int of_list_hello_elem_OF_VERSION_1_4_check(
    of_list_hello_elem_t *obj, int value);
extern int of_list_hello_elem_OF_VERSION_1_4_populate_scalars(
    of_list_hello_elem_t *obj, int value);
extern int of_list_hello_elem_OF_VERSION_1_4_check_scalars(
    of_list_hello_elem_t *obj, int value);

extern int of_list_instruction_OF_VERSION_1_4_populate(
    of_list_instruction_t *obj, int value);
extern int of_list_instruction_OF_VERSION_1_4_check(
    of_list_instruction_t *obj, int value);
extern int of_list_instruction_OF_VERSION_1_4_populate_scalars(
    of_list_instruction_t *obj, int value);
extern int of_list_instruction_OF_VERSION_1_4_check_scalars(
    of_list_instruction_t *obj, int value);

extern int of_list_instruction_id_OF_VERSION_1_4_populate(
    of_list_instruction_id_t *obj, int value);
extern int of_list_instruction_id_OF_VERSION_1_4_check(
    of_list_instruction_id_t *obj, int value);
extern int of_list_instruction_id_OF_VERSION_1_4_populate_scalars(
    of_list_instruction_id_t *obj, int value);
extern int of_list_instruction_id_OF_VERSION_1_4_check_scalars(
    of_list_instruction_id_t *obj, int value);

extern int of_list_meter_band_OF_VERSION_1_4_populate(
    of_list_meter_band_t *obj, int value);
extern int of_list_meter_band_OF_VERSION_1_4_check(
    of_list_meter_band_t *obj, int value);
extern int of_list_meter_band_OF_VERSION_1_4_populate_scalars(
    of_list_meter_band_t *obj, int value);
extern int of_list_meter_band_OF_VERSION_1_4_check_scalars(
    of_list_meter_band_t *obj, int value);

extern int of_list_meter_band_stats_OF_VERSION_1_4_populate(
    of_list_meter_band_stats_t *obj, int value);
extern int of_list_meter_band_stats_OF_VERSION_1_4_check(
    of_list_meter_band_stats_t *obj, int value);
extern int of_list_meter_band_stats_OF_VERSION_1_4_populate_scalars(
    of_list_meter_band_stats_t *obj, int value);
extern int of_list_meter_band_stats_OF_VERSION_1_4_check_scalars(
    of_list_meter_band_stats_t *obj, int value);

extern int of_list_meter_config_OF_VERSION_1_4_populate(
    of_list_meter_config_t *obj, int value);
extern int of_list_meter_config_OF_VERSION_1_4_check(
    of_list_meter_config_t *obj, int value);
extern int of_list_meter_config_OF_VERSION_1_4_populate_scalars(
    of_list_meter_config_t *obj, int value);
extern int of_list_meter_config_OF_VERSION_1_4_check_scalars(
    of_list_meter_config_t *obj, int value);

extern int of_list_meter_stats_OF_VERSION_1_4_populate(
    of_list_meter_stats_t *obj, int value);
extern int of_list_meter_stats_OF_VERSION_1_4_check(
    of_list_meter_stats_t *obj, int value);
extern int of_list_meter_stats_OF_VERSION_1_4_populate_scalars(
    of_list_meter_stats_t *obj, int value);
extern int of_list_meter_stats_OF_VERSION_1_4_check_scalars(
    of_list_meter_stats_t *obj, int value);

extern int of_list_oxm_OF_VERSION_1_4_populate(
    of_list_oxm_t *obj, int value);
extern int of_list_oxm_OF_VERSION_1_4_check(
    of_list_oxm_t *obj, int value);
extern int of_list_oxm_OF_VERSION_1_4_populate_scalars(
    of_list_oxm_t *obj, int value);
extern int of_list_oxm_OF_VERSION_1_4_check_scalars(
    of_list_oxm_t *obj, int value);

extern int of_list_port_desc_OF_VERSION_1_4_populate(
    of_list_port_desc_t *obj, int value);
extern int of_list_port_desc_OF_VERSION_1_4_check(
    of_list_port_desc_t *obj, int value);
extern int of_list_port_desc_OF_VERSION_1_4_populate_scalars(
    of_list_port_desc_t *obj, int value);
extern int of_list_port_desc_OF_VERSION_1_4_check_scalars(
    of_list_port_desc_t *obj, int value);

extern int of_list_port_desc_prop_OF_VERSION_1_4_populate(
    of_list_port_desc_prop_t *obj, int value);
extern int of_list_port_desc_prop_OF_VERSION_1_4_check(
    of_list_port_desc_prop_t *obj, int value);
extern int of_list_port_desc_prop_OF_VERSION_1_4_populate_scalars(
    of_list_port_desc_prop_t *obj, int value);
extern int of_list_port_desc_prop_OF_VERSION_1_4_check_scalars(
    of_list_port_desc_prop_t *obj, int value);

extern int of_list_port_mod_prop_OF_VERSION_1_4_populate(
    of_list_port_mod_prop_t *obj, int value);
extern int of_list_port_mod_prop_OF_VERSION_1_4_check(
    of_list_port_mod_prop_t *obj, int value);
extern int of_list_port_mod_prop_OF_VERSION_1_4_populate_scalars(
    of_list_port_mod_prop_t *obj, int value);
extern int of_list_port_mod_prop_OF_VERSION_1_4_check_scalars(
    of_list_port_mod_prop_t *obj, int value);

extern int of_list_port_stats_entry_OF_VERSION_1_4_populate(
    of_list_port_stats_entry_t *obj, int value);
extern int of_list_port_stats_entry_OF_VERSION_1_4_check(
    of_list_port_stats_entry_t *obj, int value);
extern int of_list_port_stats_entry_OF_VERSION_1_4_populate_scalars(
    of_list_port_stats_entry_t *obj, int value);
extern int of_list_port_stats_entry_OF_VERSION_1_4_check_scalars(
    of_list_port_stats_entry_t *obj, int value);

extern int of_list_port_stats_prop_OF_VERSION_1_4_populate(
    of_list_port_stats_prop_t *obj, int value);
extern int of_list_port_stats_prop_OF_VERSION_1_4_check(
    of_list_port_stats_prop_t *obj, int value);
extern int of_list_port_stats_prop_OF_VERSION_1_4_populate_scalars(
    of_list_port_stats_prop_t *obj, int value);
extern int of_list_port_stats_prop_OF_VERSION_1_4_check_scalars(
    of_list_port_stats_prop_t *obj, int value);

extern int of_list_queue_desc_OF_VERSION_1_4_populate(
    of_list_queue_desc_t *obj, int value);
extern int of_list_queue_desc_OF_VERSION_1_4_check(
    of_list_queue_desc_t *obj, int value);
extern int of_list_queue_desc_OF_VERSION_1_4_populate_scalars(
    of_list_queue_desc_t *obj, int value);
extern int of_list_queue_desc_OF_VERSION_1_4_check_scalars(
    of_list_queue_desc_t *obj, int value);

extern int of_list_queue_desc_prop_OF_VERSION_1_4_populate(
    of_list_queue_desc_prop_t *obj, int value);
extern int of_list_queue_desc_prop_OF_VERSION_1_4_check(
    of_list_queue_desc_prop_t *obj, int value);
extern int of_list_queue_desc_prop_OF_VERSION_1_4_populate_scalars(
    of_list_queue_desc_prop_t *obj, int value);
extern int of_list_queue_desc_prop_OF_VERSION_1_4_check_scalars(
    of_list_queue_desc_prop_t *obj, int value);

extern int of_list_queue_prop_OF_VERSION_1_4_populate(
    of_list_queue_prop_t *obj, int value);
extern int of_list_queue_prop_OF_VERSION_1_4_check(
    of_list_queue_prop_t *obj, int value);
extern int of_list_queue_prop_OF_VERSION_1_4_populate_scalars(
    of_list_queue_prop_t *obj, int value);
extern int of_list_queue_prop_OF_VERSION_1_4_check_scalars(
    of_list_queue_prop_t *obj, int value);

extern int of_list_queue_stats_entry_OF_VERSION_1_4_populate(
    of_list_queue_stats_entry_t *obj, int value);
extern int of_list_queue_stats_entry_OF_VERSION_1_4_check(
    of_list_queue_stats_entry_t *obj, int value);
extern int of_list_queue_stats_entry_OF_VERSION_1_4_populate_scalars(
    of_list_queue_stats_entry_t *obj, int value);
extern int of_list_queue_stats_entry_OF_VERSION_1_4_check_scalars(
    of_list_queue_stats_entry_t *obj, int value);

extern int of_list_queue_stats_prop_OF_VERSION_1_4_populate(
    of_list_queue_stats_prop_t *obj, int value);
extern int of_list_queue_stats_prop_OF_VERSION_1_4_check(
    of_list_queue_stats_prop_t *obj, int value);
extern int of_list_queue_stats_prop_OF_VERSION_1_4_populate_scalars(
    of_list_queue_stats_prop_t *obj, int value);
extern int of_list_queue_stats_prop_OF_VERSION_1_4_check_scalars(
    of_list_queue_stats_prop_t *obj, int value);

extern int of_list_role_prop_OF_VERSION_1_4_populate(
    of_list_role_prop_t *obj, int value);
extern int of_list_role_prop_OF_VERSION_1_4_check(
    of_list_role_prop_t *obj, int value);
extern int of_list_role_prop_OF_VERSION_1_4_populate_scalars(
    of_list_role_prop_t *obj, int value);
extern int of_list_role_prop_OF_VERSION_1_4_check_scalars(
    of_list_role_prop_t *obj, int value);

extern int of_list_table_desc_OF_VERSION_1_4_populate(
    of_list_table_desc_t *obj, int value);
extern int of_list_table_desc_OF_VERSION_1_4_check(
    of_list_table_desc_t *obj, int value);
extern int of_list_table_desc_OF_VERSION_1_4_populate_scalars(
    of_list_table_desc_t *obj, int value);
extern int of_list_table_desc_OF_VERSION_1_4_check_scalars(
    of_list_table_desc_t *obj, int value);

extern int of_list_table_feature_prop_OF_VERSION_1_4_populate(
    of_list_table_feature_prop_t *obj, int value);
extern int of_list_table_feature_prop_OF_VERSION_1_4_check(
    of_list_table_feature_prop_t *obj, int value);
extern int of_list_table_feature_prop_OF_VERSION_1_4_populate_scalars(
    of_list_table_feature_prop_t *obj, int value);
extern int of_list_table_feature_prop_OF_VERSION_1_4_check_scalars(
    of_list_table_feature_prop_t *obj, int value);

extern int of_list_table_features_OF_VERSION_1_4_populate(
    of_list_table_features_t *obj, int value);
extern int of_list_table_features_OF_VERSION_1_4_check(
    of_list_table_features_t *obj, int value);
extern int of_list_table_features_OF_VERSION_1_4_populate_scalars(
    of_list_table_features_t *obj, int value);
extern int of_list_table_features_OF_VERSION_1_4_check_scalars(
    of_list_table_features_t *obj, int value);

extern int of_list_table_mod_prop_OF_VERSION_1_4_populate(
    of_list_table_mod_prop_t *obj, int value);
extern int of_list_table_mod_prop_OF_VERSION_1_4_check(
    of_list_table_mod_prop_t *obj, int value);
extern int of_list_table_mod_prop_OF_VERSION_1_4_populate_scalars(
    of_list_table_mod_prop_t *obj, int value);
extern int of_list_table_mod_prop_OF_VERSION_1_4_check_scalars(
    of_list_table_mod_prop_t *obj, int value);

extern int of_list_table_stats_entry_OF_VERSION_1_4_populate(
    of_list_table_stats_entry_t *obj, int value);
extern int of_list_table_stats_entry_OF_VERSION_1_4_check(
    of_list_table_stats_entry_t *obj, int value);
extern int of_list_table_stats_entry_OF_VERSION_1_4_populate_scalars(
    of_list_table_stats_entry_t *obj, int value);
extern int of_list_table_stats_entry_OF_VERSION_1_4_check_scalars(
    of_list_table_stats_entry_t *obj, int value);

extern int of_list_uint32_OF_VERSION_1_4_populate(
    of_list_uint32_t *obj, int value);
extern int of_list_uint32_OF_VERSION_1_4_check(
    of_list_uint32_t *obj, int value);
extern int of_list_uint32_OF_VERSION_1_4_populate_scalars(
    of_list_uint32_t *obj, int value);
extern int of_list_uint32_OF_VERSION_1_4_check_scalars(
    of_list_uint32_t *obj, int value);

extern int of_list_uint64_OF_VERSION_1_4_populate(
    of_list_uint64_t *obj, int value);
extern int of_list_uint64_OF_VERSION_1_4_check(
    of_list_uint64_t *obj, int value);
extern int of_list_uint64_OF_VERSION_1_4_populate_scalars(
    of_list_uint64_t *obj, int value);
extern int of_list_uint64_OF_VERSION_1_4_check_scalars(
    of_list_uint64_t *obj, int value);

extern int of_list_uint8_OF_VERSION_1_4_populate(
    of_list_uint8_t *obj, int value);
extern int of_list_uint8_OF_VERSION_1_4_check(
    of_list_uint8_t *obj, int value);
extern int of_list_uint8_OF_VERSION_1_4_populate_scalars(
    of_list_uint8_t *obj, int value);
extern int of_list_uint8_OF_VERSION_1_4_check_scalars(
    of_list_uint8_t *obj, int value);

#endif /* _TEST_COMMON_H_ */
