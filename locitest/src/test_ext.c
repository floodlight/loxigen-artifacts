/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */

/**
 * Test extensions
 */

#include <locitest/test_common.h>

/**
 * Simple tests for extension objects
 */

int
test_ext_objs(void)
{
    of_action_bsn_mirror_t *obj;

    obj = of_action_bsn_mirror_new(OF_VERSION_1_0);
    TEST_ASSERT(obj != NULL);
    TEST_ASSERT(obj->object_id == OF_ACTION_BSN_MIRROR);

    return TEST_PASS;
}
