/* AUTOMATICALLY GENERATED, DO NOT MODIFY */

/*
 * Schema-defined QAPI types
 *
 * Copyright IBM, Corp. 2011
 * Copyright (c) 2013-2018 Red Hat Inc.
 *
 * This work is licensed under the terms of the GNU LGPL, version 2.1 or later.
 * See the COPYING.LIB file in the top-level directory.
 */

#ifndef QAPI_TYPES_JOB_H
#define QAPI_TYPES_JOB_H

#include "qapi/qapi-builtin-types.h"

typedef enum JobType {
    JOB_TYPE_COMMIT = 0,
    JOB_TYPE_STREAM = 1,
    JOB_TYPE_MIRROR = 2,
    JOB_TYPE_BACKUP = 3,
    JOB_TYPE_CREATE = 4,
    JOB_TYPE__MAX = 5,
} JobType;

#define JobType_str(val) \
    qapi_enum_lookup(&JobType_lookup, (val))

extern const QEnumLookup JobType_lookup;

typedef enum JobStatus {
    JOB_STATUS_UNDEFINED = 0,
    JOB_STATUS_CREATED = 1,
    JOB_STATUS_RUNNING = 2,
    JOB_STATUS_PAUSED = 3,
    JOB_STATUS_READY = 4,
    JOB_STATUS_STANDBY = 5,
    JOB_STATUS_WAITING = 6,
    JOB_STATUS_PENDING = 7,
    JOB_STATUS_ABORTING = 8,
    JOB_STATUS_CONCLUDED = 9,
    JOB_STATUS_NULL = 10,
    JOB_STATUS__MAX = 11,
} JobStatus;

#define JobStatus_str(val) \
    qapi_enum_lookup(&JobStatus_lookup, (val))

extern const QEnumLookup JobStatus_lookup;

typedef enum JobVerb {
    JOB_VERB_CANCEL = 0,
    JOB_VERB_PAUSE = 1,
    JOB_VERB_RESUME = 2,
    JOB_VERB_SET_SPEED = 3,
    JOB_VERB_COMPLETE = 4,
    JOB_VERB_DISMISS = 5,
    JOB_VERB_FINALIZE = 6,
    JOB_VERB__MAX = 7,
} JobVerb;

#define JobVerb_str(val) \
    qapi_enum_lookup(&JobVerb_lookup, (val))

extern const QEnumLookup JobVerb_lookup;

typedef struct q_obj_JOB_STATUS_CHANGE_arg q_obj_JOB_STATUS_CHANGE_arg;

typedef struct q_obj_job_pause_arg q_obj_job_pause_arg;

typedef struct q_obj_job_resume_arg q_obj_job_resume_arg;

typedef struct q_obj_job_cancel_arg q_obj_job_cancel_arg;

typedef struct q_obj_job_complete_arg q_obj_job_complete_arg;

typedef struct q_obj_job_dismiss_arg q_obj_job_dismiss_arg;

typedef struct q_obj_job_finalize_arg q_obj_job_finalize_arg;

typedef struct JobInfo JobInfo;

typedef struct JobInfoList JobInfoList;

struct q_obj_JOB_STATUS_CHANGE_arg {
    char *id;
    JobStatus status;
};

struct q_obj_job_pause_arg {
    char *id;
};

struct q_obj_job_resume_arg {
    char *id;
};

struct q_obj_job_cancel_arg {
    char *id;
};

struct q_obj_job_complete_arg {
    char *id;
};

struct q_obj_job_dismiss_arg {
    char *id;
};

struct q_obj_job_finalize_arg {
    char *id;
};

struct JobInfo {
    char *id;
    JobType type;
    JobStatus status;
    int64_t current_progress;
    int64_t total_progress;
    bool has_error;
    char *error;
};

void qapi_free_JobInfo(JobInfo *obj);

struct JobInfoList {
    JobInfoList *next;
    JobInfo *value;
};

void qapi_free_JobInfoList(JobInfoList *obj);

#endif /* QAPI_TYPES_JOB_H */
