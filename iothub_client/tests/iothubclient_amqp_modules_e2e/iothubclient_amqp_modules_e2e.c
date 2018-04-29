// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include "testrunnerswitcher.h"
#include "iothubclient_common_e2e.h"
#include "iothubtransportamqp.h"

static TEST_MUTEX_HANDLE g_dllByDll;

BEGIN_TEST_SUITE(iothubclient_amqp_modules_e2e)

    TEST_SUITE_INITIALIZE(TestClassInitialize)
    {
        TEST_INITIALIZE_MEMORY_DEBUG(g_dllByDll);
        e2e_init(TEST_AMQP, true);
    }

    TEST_SUITE_CLEANUP(TestClassCleanup)
    {
        e2e_deinit();
        TEST_DEINITIALIZE_MEMORY_DEBUG(g_dllByDll);
    }

    TEST_FUNCTION(IotHub_AMQP_Modules_modules_SendEvent_e2e_sas)
    {
        e2e_send_event_test_sas(AMQP_Protocol);
    }

    TEST_FUNCTION(IotHub_AMQP_Modules_modules_RecvMessage_E2ETest_sas)
    {
        e2e_recv_message_test_sas(AMQP_Protocol);
    }

END_TEST_SUITE(iothubclient_amqp_modules_e2e)
