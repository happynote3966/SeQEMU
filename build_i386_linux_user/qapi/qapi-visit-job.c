/* AUTOMATICALLY GENERATED, DO NOT MODIFY */

/*
 * Schema-defined QAPI visitors
 *
 * Copyright IBM, Corp. 2011
 * Copyright (C) 2014-2018 Red Hat, Inc.
 *
 * This work is licensed under the terms of the GNU LGPL, version 2.1 or later.
 * See the COPYING.LIB file in the top-level directory.
 */

#include "qemu/osdep.h"
#include "qemu-common.h"
#include "qapi/error.h"
#include "qapi/qmp/qerror.h"
#include "qapi-visit-job.h"

void visit_type_JobType(Visitor *v, const char *name, JobType *obj, Error **errp)
{
    int value = *obj;
    visit_type_enum(v, name, &value, &JobType_lookup, errp);
    *obj = value;
}

void visit_type_JobStatus(Visitor *v, const char *name, JobStatus *obj, Error **errp)
{
    int value = *obj;
    visit_type_enum(v, name, &value, &JobStatus_lookup, errp);
    *obj = value;
}

void visit_type_JobVerb(Visitor *v, const char *name, JobVerb *obj, Error **errp)
{
    int value = *obj;
    visit_type_enum(v, name, &value, &JobVerb_lookup, errp);
    *obj = value;
}

void visit_type_q_obj_JOB_STATUS_CHANGE_arg_members(Visitor *v, q_obj_JOB_STATUS_CHANGE_arg *obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, "id", &obj->id, &err);
    if (err) {
        goto out;
    }
    visit_type_JobStatus(v, "status", &obj->status, &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_q_obj_job_pause_arg_members(Visitor *v, q_obj_job_pause_arg *obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, "id", &obj->id, &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_q_obj_job_resume_arg_members(Visitor *v, q_obj_job_resume_arg *obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, "id", &obj->id, &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_q_obj_job_cancel_arg_members(Visitor *v, q_obj_job_cancel_arg *obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, "id", &obj->id, &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_q_obj_job_complete_arg_members(Visitor *v, q_obj_job_complete_arg *obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, "id", &obj->id, &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_q_obj_job_dismiss_arg_members(Visitor *v, q_obj_job_dismiss_arg *obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, "id", &obj->id, &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_q_obj_job_finalize_arg_members(Visitor *v, q_obj_job_finalize_arg *obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, "id", &obj->id, &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_JobInfo_members(Visitor *v, JobInfo *obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, "id", &obj->id, &err);
    if (err) {
        goto out;
    }
    visit_type_JobType(v, "type", &obj->type, &err);
    if (err) {
        goto out;
    }
    visit_type_JobStatus(v, "status", &obj->status, &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, "current-progress", &obj->current_progress, &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, "total-progress", &obj->total_progress, &err);
    if (err) {
        goto out;
    }
    if (visit_optional(v, "error", &obj->has_error)) {
        visit_type_str(v, "error", &obj->error, &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_JobInfo(Visitor *v, const char *name, JobInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, name, (void **)obj, sizeof(JobInfo), &err);
    if (err) {
        goto out;
    }
    if (!*obj) {
        goto out_obj;
    }
    visit_type_JobInfo_members(v, *obj, &err);
    if (err) {
        goto out_obj;
    }
    visit_check_struct(v, &err);
out_obj:
    visit_end_struct(v, (void **)obj);
    if (err && visit_is_input(v)) {
        qapi_free_JobInfo(*obj);
        *obj = NULL;
    }
out:
    error_propagate(errp, err);
}

void visit_type_JobInfoList(Visitor *v, const char *name, JobInfoList **obj, Error **errp)
{
    Error *err = NULL;
    JobInfoList *tail;
    size_t size = sizeof(**obj);

    visit_start_list(v, name, (GenericList **)obj, size, &err);
    if (err) {
        goto out;
    }

    for (tail = *obj; tail;
         tail = (JobInfoList *)visit_next_list(v, (GenericList *)tail, size)) {
        visit_type_JobInfo(v, NULL, &tail->value, &err);
        if (err) {
            break;
        }
    }

    if (!err) {
        visit_check_list(v, &err);
    }
    visit_end_list(v, (void **)obj);
    if (err && visit_is_input(v)) {
        qapi_free_JobInfoList(*obj);
        *obj = NULL;
    }
out:
    error_propagate(errp, err);
}
/* Dummy declaration to prevent empty .o file */
char dummy_qapi_visit_job_c;
