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

#ifndef QGA_QAPI_EVENTS_H
#define QGA_QAPI_EVENTS_H

#include "qapi/util.h"
#include "qga-qapi-types.h"


typedef enum qga_QAPIEvent {
    QGA_QAPI_EVENT__MAX = 0,
} qga_QAPIEvent;

#define qga_QAPIEvent_str(val) \
    qapi_enum_lookup(&qga_QAPIEvent_lookup, (val))

extern const QEnumLookup qga_QAPIEvent_lookup;

#endif /* QGA_QAPI_EVENTS_H */
