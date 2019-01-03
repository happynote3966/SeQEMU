/* AUTOMATICALLY GENERATED, DO NOT MODIFY */

/*
 * Schema-defined QAPI/QMP events
 *
 * Copyright (c) 2014 Wenchao Xia
 * Copyright (c) 2015-2018 Red Hat Inc.
 *
 * This work is licensed under the terms of the GNU LGPL, version 2.1 or later.
 * See the COPYING.LIB file in the top-level directory.
 */

#ifndef QAPI_EVENTS_H
#define QAPI_EVENTS_H

#include "qapi-events-common.h"
#include "qapi-events-sockets.h"
#include "qapi-events-run-state.h"
#include "qapi-events-crypto.h"
#include "qapi-events-block.h"
#include "qapi-events-char.h"
#include "qapi-events-job.h"
#include "qapi-events-net.h"
#include "qapi-events-rocker.h"
#include "qapi-events-tpm.h"
#include "qapi-events-ui.h"
#include "qapi-events-migration.h"
#include "qapi-events-transaction.h"
#include "qapi-events-trace.h"
#include "qapi-events-introspect.h"
#include "qapi-events-misc.h"
#include "qapi/util.h"
#include "qapi-types.h"


typedef enum QAPIEvent {
    QAPI_EVENT_SHUTDOWN = 0,
    QAPI_EVENT_POWERDOWN = 1,
    QAPI_EVENT_RESET = 2,
    QAPI_EVENT_STOP = 3,
    QAPI_EVENT_RESUME = 4,
    QAPI_EVENT_SUSPEND = 5,
    QAPI_EVENT_SUSPEND_DISK = 6,
    QAPI_EVENT_WAKEUP = 7,
    QAPI_EVENT_WATCHDOG = 8,
    QAPI_EVENT_GUEST_PANICKED = 9,
    QAPI_EVENT_JOB_STATUS_CHANGE = 10,
    QAPI_EVENT_BLOCK_IMAGE_CORRUPTED = 11,
    QAPI_EVENT_BLOCK_IO_ERROR = 12,
    QAPI_EVENT_BLOCK_JOB_COMPLETED = 13,
    QAPI_EVENT_BLOCK_JOB_CANCELLED = 14,
    QAPI_EVENT_BLOCK_JOB_ERROR = 15,
    QAPI_EVENT_BLOCK_JOB_READY = 16,
    QAPI_EVENT_BLOCK_JOB_PENDING = 17,
    QAPI_EVENT_BLOCK_WRITE_THRESHOLD = 18,
    QAPI_EVENT_DEVICE_TRAY_MOVED = 19,
    QAPI_EVENT_PR_MANAGER_STATUS_CHANGED = 20,
    QAPI_EVENT_QUORUM_FAILURE = 21,
    QAPI_EVENT_QUORUM_REPORT_BAD = 22,
    QAPI_EVENT_VSERPORT_CHANGE = 23,
    QAPI_EVENT_NIC_RX_FILTER_CHANGED = 24,
    QAPI_EVENT_SPICE_CONNECTED = 25,
    QAPI_EVENT_SPICE_INITIALIZED = 26,
    QAPI_EVENT_SPICE_DISCONNECTED = 27,
    QAPI_EVENT_SPICE_MIGRATE_COMPLETED = 28,
    QAPI_EVENT_VNC_CONNECTED = 29,
    QAPI_EVENT_VNC_INITIALIZED = 30,
    QAPI_EVENT_VNC_DISCONNECTED = 31,
    QAPI_EVENT_MIGRATION = 32,
    QAPI_EVENT_MIGRATION_PASS = 33,
    QAPI_EVENT_BALLOON_CHANGE = 34,
    QAPI_EVENT_DEVICE_DELETED = 35,
    QAPI_EVENT_DUMP_COMPLETED = 36,
    QAPI_EVENT_MEM_UNPLUG_ERROR = 37,
    QAPI_EVENT_ACPI_DEVICE_OST = 38,
    QAPI_EVENT_RTC_CHANGE = 39,
    QAPI_EVENT_COMMAND_DROPPED = 40,
    QAPI_EVENT__MAX = 41,
} QAPIEvent;

#define QAPIEvent_str(val) \
    qapi_enum_lookup(&QAPIEvent_lookup, (val))

extern const QEnumLookup QAPIEvent_lookup;

#endif /* QAPI_EVENTS_H */
