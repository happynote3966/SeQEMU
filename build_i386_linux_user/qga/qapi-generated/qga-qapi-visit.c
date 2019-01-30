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
#include "qga-qapi-visit.h"

void visit_type_q_obj_guest_sync_delimited_arg_members(Visitor *v, q_obj_guest_sync_delimited_arg *obj, Error **errp)
{
    Error *err = NULL;

    visit_type_int(v, "id", &obj->id, &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_q_obj_guest_sync_arg_members(Visitor *v, q_obj_guest_sync_arg *obj, Error **errp)
{
    Error *err = NULL;

    visit_type_int(v, "id", &obj->id, &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_q_obj_guest_set_time_arg_members(Visitor *v, q_obj_guest_set_time_arg *obj, Error **errp)
{
    Error *err = NULL;

    if (visit_optional(v, "time", &obj->has_time)) {
        visit_type_int(v, "time", &obj->time, &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_GuestAgentCommandInfo_members(Visitor *v, GuestAgentCommandInfo *obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, "name", &obj->name, &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, "enabled", &obj->enabled, &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, "success-response", &obj->success_response, &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_GuestAgentCommandInfo(Visitor *v, const char *name, GuestAgentCommandInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, name, (void **)obj, sizeof(GuestAgentCommandInfo), &err);
    if (err) {
        goto out;
    }
    if (!*obj) {
        goto out_obj;
    }
    visit_type_GuestAgentCommandInfo_members(v, *obj, &err);
    if (err) {
        goto out_obj;
    }
    visit_check_struct(v, &err);
out_obj:
    visit_end_struct(v, (void **)obj);
    if (err && visit_is_input(v)) {
        qapi_free_GuestAgentCommandInfo(*obj);
        *obj = NULL;
    }
out:
    error_propagate(errp, err);
}

void visit_type_GuestAgentCommandInfoList(Visitor *v, const char *name, GuestAgentCommandInfoList **obj, Error **errp)
{
    Error *err = NULL;
    GuestAgentCommandInfoList *tail;
    size_t size = sizeof(**obj);

    visit_start_list(v, name, (GenericList **)obj, size, &err);
    if (err) {
        goto out;
    }

    for (tail = *obj; tail;
         tail = (GuestAgentCommandInfoList *)visit_next_list(v, (GenericList *)tail, size)) {
        visit_type_GuestAgentCommandInfo(v, NULL, &tail->value, &err);
        if (err) {
            break;
        }
    }

    if (!err) {
        visit_check_list(v, &err);
    }
    visit_end_list(v, (void **)obj);
    if (err && visit_is_input(v)) {
        qapi_free_GuestAgentCommandInfoList(*obj);
        *obj = NULL;
    }
out:
    error_propagate(errp, err);
}

void visit_type_GuestAgentInfo_members(Visitor *v, GuestAgentInfo *obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, "version", &obj->version, &err);
    if (err) {
        goto out;
    }
    visit_type_GuestAgentCommandInfoList(v, "supported_commands", &obj->supported_commands, &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_GuestAgentInfo(Visitor *v, const char *name, GuestAgentInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, name, (void **)obj, sizeof(GuestAgentInfo), &err);
    if (err) {
        goto out;
    }
    if (!*obj) {
        goto out_obj;
    }
    visit_type_GuestAgentInfo_members(v, *obj, &err);
    if (err) {
        goto out_obj;
    }
    visit_check_struct(v, &err);
out_obj:
    visit_end_struct(v, (void **)obj);
    if (err && visit_is_input(v)) {
        qapi_free_GuestAgentInfo(*obj);
        *obj = NULL;
    }
out:
    error_propagate(errp, err);
}

void visit_type_q_obj_guest_shutdown_arg_members(Visitor *v, q_obj_guest_shutdown_arg *obj, Error **errp)
{
    Error *err = NULL;

    if (visit_optional(v, "mode", &obj->has_mode)) {
        visit_type_str(v, "mode", &obj->mode, &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_q_obj_guest_file_open_arg_members(Visitor *v, q_obj_guest_file_open_arg *obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, "path", &obj->path, &err);
    if (err) {
        goto out;
    }
    if (visit_optional(v, "mode", &obj->has_mode)) {
        visit_type_str(v, "mode", &obj->mode, &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_q_obj_guest_file_close_arg_members(Visitor *v, q_obj_guest_file_close_arg *obj, Error **errp)
{
    Error *err = NULL;

    visit_type_int(v, "handle", &obj->handle, &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_GuestFileRead_members(Visitor *v, GuestFileRead *obj, Error **errp)
{
    Error *err = NULL;

    visit_type_int(v, "count", &obj->count, &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, "buf-b64", &obj->buf_b64, &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, "eof", &obj->eof, &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_GuestFileRead(Visitor *v, const char *name, GuestFileRead **obj, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, name, (void **)obj, sizeof(GuestFileRead), &err);
    if (err) {
        goto out;
    }
    if (!*obj) {
        goto out_obj;
    }
    visit_type_GuestFileRead_members(v, *obj, &err);
    if (err) {
        goto out_obj;
    }
    visit_check_struct(v, &err);
out_obj:
    visit_end_struct(v, (void **)obj);
    if (err && visit_is_input(v)) {
        qapi_free_GuestFileRead(*obj);
        *obj = NULL;
    }
out:
    error_propagate(errp, err);
}

void visit_type_q_obj_guest_file_read_arg_members(Visitor *v, q_obj_guest_file_read_arg *obj, Error **errp)
{
    Error *err = NULL;

    visit_type_int(v, "handle", &obj->handle, &err);
    if (err) {
        goto out;
    }
    if (visit_optional(v, "count", &obj->has_count)) {
        visit_type_int(v, "count", &obj->count, &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_GuestFileWrite_members(Visitor *v, GuestFileWrite *obj, Error **errp)
{
    Error *err = NULL;

    visit_type_int(v, "count", &obj->count, &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, "eof", &obj->eof, &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_GuestFileWrite(Visitor *v, const char *name, GuestFileWrite **obj, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, name, (void **)obj, sizeof(GuestFileWrite), &err);
    if (err) {
        goto out;
    }
    if (!*obj) {
        goto out_obj;
    }
    visit_type_GuestFileWrite_members(v, *obj, &err);
    if (err) {
        goto out_obj;
    }
    visit_check_struct(v, &err);
out_obj:
    visit_end_struct(v, (void **)obj);
    if (err && visit_is_input(v)) {
        qapi_free_GuestFileWrite(*obj);
        *obj = NULL;
    }
out:
    error_propagate(errp, err);
}

void visit_type_q_obj_guest_file_write_arg_members(Visitor *v, q_obj_guest_file_write_arg *obj, Error **errp)
{
    Error *err = NULL;

    visit_type_int(v, "handle", &obj->handle, &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, "buf-b64", &obj->buf_b64, &err);
    if (err) {
        goto out;
    }
    if (visit_optional(v, "count", &obj->has_count)) {
        visit_type_int(v, "count", &obj->count, &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_GuestFileSeek_members(Visitor *v, GuestFileSeek *obj, Error **errp)
{
    Error *err = NULL;

    visit_type_int(v, "position", &obj->position, &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, "eof", &obj->eof, &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_GuestFileSeek(Visitor *v, const char *name, GuestFileSeek **obj, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, name, (void **)obj, sizeof(GuestFileSeek), &err);
    if (err) {
        goto out;
    }
    if (!*obj) {
        goto out_obj;
    }
    visit_type_GuestFileSeek_members(v, *obj, &err);
    if (err) {
        goto out_obj;
    }
    visit_check_struct(v, &err);
out_obj:
    visit_end_struct(v, (void **)obj);
    if (err && visit_is_input(v)) {
        qapi_free_GuestFileSeek(*obj);
        *obj = NULL;
    }
out:
    error_propagate(errp, err);
}

void visit_type_QGASeek(Visitor *v, const char *name, QGASeek *obj, Error **errp)
{
    int value = *obj;
    visit_type_enum(v, name, &value, &QGASeek_lookup, errp);
    *obj = value;
}

void visit_type_GuestFileWhence(Visitor *v, const char *name, GuestFileWhence **obj, Error **errp)
{
    Error *err = NULL;

    visit_start_alternate(v, name, (GenericAlternate **)obj, sizeof(**obj),
                          &err);
    if (err) {
        goto out;
    }
    if (!*obj) {
        goto out_obj;
    }
    switch ((*obj)->type) {
    case QTYPE_QNUM:
        visit_type_int(v, name, &(*obj)->u.value, &err);
        break;
    case QTYPE_QSTRING:
        visit_type_QGASeek(v, name, &(*obj)->u.name, &err);
        break;
    case QTYPE_NONE:
        abort();
    default:
        error_setg(&err, QERR_INVALID_PARAMETER_TYPE, name ? name : "null",
                   "GuestFileWhence");
    }
out_obj:
    visit_end_alternate(v, (void **)obj);
    if (err && visit_is_input(v)) {
        qapi_free_GuestFileWhence(*obj);
        *obj = NULL;
    }
out:
    error_propagate(errp, err);
}

void visit_type_q_obj_guest_file_seek_arg_members(Visitor *v, q_obj_guest_file_seek_arg *obj, Error **errp)
{
    Error *err = NULL;

    visit_type_int(v, "handle", &obj->handle, &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, "offset", &obj->offset, &err);
    if (err) {
        goto out;
    }
    visit_type_GuestFileWhence(v, "whence", &obj->whence, &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_q_obj_guest_file_flush_arg_members(Visitor *v, q_obj_guest_file_flush_arg *obj, Error **errp)
{
    Error *err = NULL;

    visit_type_int(v, "handle", &obj->handle, &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_GuestFsfreezeStatus(Visitor *v, const char *name, GuestFsfreezeStatus *obj, Error **errp)
{
    int value = *obj;
    visit_type_enum(v, name, &value, &GuestFsfreezeStatus_lookup, errp);
    *obj = value;
}

void visit_type_q_obj_guest_fsfreeze_freeze_list_arg_members(Visitor *v, q_obj_guest_fsfreeze_freeze_list_arg *obj, Error **errp)
{
    Error *err = NULL;

    if (visit_optional(v, "mountpoints", &obj->has_mountpoints)) {
        visit_type_strList(v, "mountpoints", &obj->mountpoints, &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_GuestFilesystemTrimResult_members(Visitor *v, GuestFilesystemTrimResult *obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, "path", &obj->path, &err);
    if (err) {
        goto out;
    }
    if (visit_optional(v, "trimmed", &obj->has_trimmed)) {
        visit_type_int(v, "trimmed", &obj->trimmed, &err);
        if (err) {
            goto out;
        }
    }
    if (visit_optional(v, "minimum", &obj->has_minimum)) {
        visit_type_int(v, "minimum", &obj->minimum, &err);
        if (err) {
            goto out;
        }
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

void visit_type_GuestFilesystemTrimResult(Visitor *v, const char *name, GuestFilesystemTrimResult **obj, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, name, (void **)obj, sizeof(GuestFilesystemTrimResult), &err);
    if (err) {
        goto out;
    }
    if (!*obj) {
        goto out_obj;
    }
    visit_type_GuestFilesystemTrimResult_members(v, *obj, &err);
    if (err) {
        goto out_obj;
    }
    visit_check_struct(v, &err);
out_obj:
    visit_end_struct(v, (void **)obj);
    if (err && visit_is_input(v)) {
        qapi_free_GuestFilesystemTrimResult(*obj);
        *obj = NULL;
    }
out:
    error_propagate(errp, err);
}

void visit_type_GuestFilesystemTrimResultList(Visitor *v, const char *name, GuestFilesystemTrimResultList **obj, Error **errp)
{
    Error *err = NULL;
    GuestFilesystemTrimResultList *tail;
    size_t size = sizeof(**obj);

    visit_start_list(v, name, (GenericList **)obj, size, &err);
    if (err) {
        goto out;
    }

    for (tail = *obj; tail;
         tail = (GuestFilesystemTrimResultList *)visit_next_list(v, (GenericList *)tail, size)) {
        visit_type_GuestFilesystemTrimResult(v, NULL, &tail->value, &err);
        if (err) {
            break;
        }
    }

    if (!err) {
        visit_check_list(v, &err);
    }
    visit_end_list(v, (void **)obj);
    if (err && visit_is_input(v)) {
        qapi_free_GuestFilesystemTrimResultList(*obj);
        *obj = NULL;
    }
out:
    error_propagate(errp, err);
}

void visit_type_GuestFilesystemTrimResponse_members(Visitor *v, GuestFilesystemTrimResponse *obj, Error **errp)
{
    Error *err = NULL;

    visit_type_GuestFilesystemTrimResultList(v, "paths", &obj->paths, &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_GuestFilesystemTrimResponse(Visitor *v, const char *name, GuestFilesystemTrimResponse **obj, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, name, (void **)obj, sizeof(GuestFilesystemTrimResponse), &err);
    if (err) {
        goto out;
    }
    if (!*obj) {
        goto out_obj;
    }
    visit_type_GuestFilesystemTrimResponse_members(v, *obj, &err);
    if (err) {
        goto out_obj;
    }
    visit_check_struct(v, &err);
out_obj:
    visit_end_struct(v, (void **)obj);
    if (err && visit_is_input(v)) {
        qapi_free_GuestFilesystemTrimResponse(*obj);
        *obj = NULL;
    }
out:
    error_propagate(errp, err);
}

void visit_type_q_obj_guest_fstrim_arg_members(Visitor *v, q_obj_guest_fstrim_arg *obj, Error **errp)
{
    Error *err = NULL;

    if (visit_optional(v, "minimum", &obj->has_minimum)) {
        visit_type_int(v, "minimum", &obj->minimum, &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_GuestIpAddressType(Visitor *v, const char *name, GuestIpAddressType *obj, Error **errp)
{
    int value = *obj;
    visit_type_enum(v, name, &value, &GuestIpAddressType_lookup, errp);
    *obj = value;
}

void visit_type_GuestIpAddress_members(Visitor *v, GuestIpAddress *obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, "ip-address", &obj->ip_address, &err);
    if (err) {
        goto out;
    }
    visit_type_GuestIpAddressType(v, "ip-address-type", &obj->ip_address_type, &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, "prefix", &obj->prefix, &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_GuestIpAddress(Visitor *v, const char *name, GuestIpAddress **obj, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, name, (void **)obj, sizeof(GuestIpAddress), &err);
    if (err) {
        goto out;
    }
    if (!*obj) {
        goto out_obj;
    }
    visit_type_GuestIpAddress_members(v, *obj, &err);
    if (err) {
        goto out_obj;
    }
    visit_check_struct(v, &err);
out_obj:
    visit_end_struct(v, (void **)obj);
    if (err && visit_is_input(v)) {
        qapi_free_GuestIpAddress(*obj);
        *obj = NULL;
    }
out:
    error_propagate(errp, err);
}

void visit_type_GuestNetworkInterfaceStat_members(Visitor *v, GuestNetworkInterfaceStat *obj, Error **errp)
{
    Error *err = NULL;

    visit_type_uint64(v, "rx-bytes", &obj->rx_bytes, &err);
    if (err) {
        goto out;
    }
    visit_type_uint64(v, "rx-packets", &obj->rx_packets, &err);
    if (err) {
        goto out;
    }
    visit_type_uint64(v, "rx-errs", &obj->rx_errs, &err);
    if (err) {
        goto out;
    }
    visit_type_uint64(v, "rx-dropped", &obj->rx_dropped, &err);
    if (err) {
        goto out;
    }
    visit_type_uint64(v, "tx-bytes", &obj->tx_bytes, &err);
    if (err) {
        goto out;
    }
    visit_type_uint64(v, "tx-packets", &obj->tx_packets, &err);
    if (err) {
        goto out;
    }
    visit_type_uint64(v, "tx-errs", &obj->tx_errs, &err);
    if (err) {
        goto out;
    }
    visit_type_uint64(v, "tx-dropped", &obj->tx_dropped, &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_GuestNetworkInterfaceStat(Visitor *v, const char *name, GuestNetworkInterfaceStat **obj, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, name, (void **)obj, sizeof(GuestNetworkInterfaceStat), &err);
    if (err) {
        goto out;
    }
    if (!*obj) {
        goto out_obj;
    }
    visit_type_GuestNetworkInterfaceStat_members(v, *obj, &err);
    if (err) {
        goto out_obj;
    }
    visit_check_struct(v, &err);
out_obj:
    visit_end_struct(v, (void **)obj);
    if (err && visit_is_input(v)) {
        qapi_free_GuestNetworkInterfaceStat(*obj);
        *obj = NULL;
    }
out:
    error_propagate(errp, err);
}

void visit_type_GuestIpAddressList(Visitor *v, const char *name, GuestIpAddressList **obj, Error **errp)
{
    Error *err = NULL;
    GuestIpAddressList *tail;
    size_t size = sizeof(**obj);

    visit_start_list(v, name, (GenericList **)obj, size, &err);
    if (err) {
        goto out;
    }

    for (tail = *obj; tail;
         tail = (GuestIpAddressList *)visit_next_list(v, (GenericList *)tail, size)) {
        visit_type_GuestIpAddress(v, NULL, &tail->value, &err);
        if (err) {
            break;
        }
    }

    if (!err) {
        visit_check_list(v, &err);
    }
    visit_end_list(v, (void **)obj);
    if (err && visit_is_input(v)) {
        qapi_free_GuestIpAddressList(*obj);
        *obj = NULL;
    }
out:
    error_propagate(errp, err);
}

void visit_type_GuestNetworkInterface_members(Visitor *v, GuestNetworkInterface *obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, "name", &obj->name, &err);
    if (err) {
        goto out;
    }
    if (visit_optional(v, "hardware-address", &obj->has_hardware_address)) {
        visit_type_str(v, "hardware-address", &obj->hardware_address, &err);
        if (err) {
            goto out;
        }
    }
    if (visit_optional(v, "ip-addresses", &obj->has_ip_addresses)) {
        visit_type_GuestIpAddressList(v, "ip-addresses", &obj->ip_addresses, &err);
        if (err) {
            goto out;
        }
    }
    if (visit_optional(v, "statistics", &obj->has_statistics)) {
        visit_type_GuestNetworkInterfaceStat(v, "statistics", &obj->statistics, &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_GuestNetworkInterface(Visitor *v, const char *name, GuestNetworkInterface **obj, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, name, (void **)obj, sizeof(GuestNetworkInterface), &err);
    if (err) {
        goto out;
    }
    if (!*obj) {
        goto out_obj;
    }
    visit_type_GuestNetworkInterface_members(v, *obj, &err);
    if (err) {
        goto out_obj;
    }
    visit_check_struct(v, &err);
out_obj:
    visit_end_struct(v, (void **)obj);
    if (err && visit_is_input(v)) {
        qapi_free_GuestNetworkInterface(*obj);
        *obj = NULL;
    }
out:
    error_propagate(errp, err);
}

void visit_type_GuestNetworkInterfaceList(Visitor *v, const char *name, GuestNetworkInterfaceList **obj, Error **errp)
{
    Error *err = NULL;
    GuestNetworkInterfaceList *tail;
    size_t size = sizeof(**obj);

    visit_start_list(v, name, (GenericList **)obj, size, &err);
    if (err) {
        goto out;
    }

    for (tail = *obj; tail;
         tail = (GuestNetworkInterfaceList *)visit_next_list(v, (GenericList *)tail, size)) {
        visit_type_GuestNetworkInterface(v, NULL, &tail->value, &err);
        if (err) {
            break;
        }
    }

    if (!err) {
        visit_check_list(v, &err);
    }
    visit_end_list(v, (void **)obj);
    if (err && visit_is_input(v)) {
        qapi_free_GuestNetworkInterfaceList(*obj);
        *obj = NULL;
    }
out:
    error_propagate(errp, err);
}

void visit_type_GuestLogicalProcessor_members(Visitor *v, GuestLogicalProcessor *obj, Error **errp)
{
    Error *err = NULL;

    visit_type_int(v, "logical-id", &obj->logical_id, &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, "online", &obj->online, &err);
    if (err) {
        goto out;
    }
    if (visit_optional(v, "can-offline", &obj->has_can_offline)) {
        visit_type_bool(v, "can-offline", &obj->can_offline, &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_GuestLogicalProcessor(Visitor *v, const char *name, GuestLogicalProcessor **obj, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, name, (void **)obj, sizeof(GuestLogicalProcessor), &err);
    if (err) {
        goto out;
    }
    if (!*obj) {
        goto out_obj;
    }
    visit_type_GuestLogicalProcessor_members(v, *obj, &err);
    if (err) {
        goto out_obj;
    }
    visit_check_struct(v, &err);
out_obj:
    visit_end_struct(v, (void **)obj);
    if (err && visit_is_input(v)) {
        qapi_free_GuestLogicalProcessor(*obj);
        *obj = NULL;
    }
out:
    error_propagate(errp, err);
}

void visit_type_GuestLogicalProcessorList(Visitor *v, const char *name, GuestLogicalProcessorList **obj, Error **errp)
{
    Error *err = NULL;
    GuestLogicalProcessorList *tail;
    size_t size = sizeof(**obj);

    visit_start_list(v, name, (GenericList **)obj, size, &err);
    if (err) {
        goto out;
    }

    for (tail = *obj; tail;
         tail = (GuestLogicalProcessorList *)visit_next_list(v, (GenericList *)tail, size)) {
        visit_type_GuestLogicalProcessor(v, NULL, &tail->value, &err);
        if (err) {
            break;
        }
    }

    if (!err) {
        visit_check_list(v, &err);
    }
    visit_end_list(v, (void **)obj);
    if (err && visit_is_input(v)) {
        qapi_free_GuestLogicalProcessorList(*obj);
        *obj = NULL;
    }
out:
    error_propagate(errp, err);
}

void visit_type_q_obj_guest_set_vcpus_arg_members(Visitor *v, q_obj_guest_set_vcpus_arg *obj, Error **errp)
{
    Error *err = NULL;

    visit_type_GuestLogicalProcessorList(v, "vcpus", &obj->vcpus, &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_GuestDiskBusType(Visitor *v, const char *name, GuestDiskBusType *obj, Error **errp)
{
    int value = *obj;
    visit_type_enum(v, name, &value, &GuestDiskBusType_lookup, errp);
    *obj = value;
}

void visit_type_GuestPCIAddress_members(Visitor *v, GuestPCIAddress *obj, Error **errp)
{
    Error *err = NULL;

    visit_type_int(v, "domain", &obj->domain, &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, "bus", &obj->bus, &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, "slot", &obj->slot, &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, "function", &obj->function, &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_GuestPCIAddress(Visitor *v, const char *name, GuestPCIAddress **obj, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, name, (void **)obj, sizeof(GuestPCIAddress), &err);
    if (err) {
        goto out;
    }
    if (!*obj) {
        goto out_obj;
    }
    visit_type_GuestPCIAddress_members(v, *obj, &err);
    if (err) {
        goto out_obj;
    }
    visit_check_struct(v, &err);
out_obj:
    visit_end_struct(v, (void **)obj);
    if (err && visit_is_input(v)) {
        qapi_free_GuestPCIAddress(*obj);
        *obj = NULL;
    }
out:
    error_propagate(errp, err);
}

void visit_type_GuestDiskAddress_members(Visitor *v, GuestDiskAddress *obj, Error **errp)
{
    Error *err = NULL;

    visit_type_GuestPCIAddress(v, "pci-controller", &obj->pci_controller, &err);
    if (err) {
        goto out;
    }
    visit_type_GuestDiskBusType(v, "bus-type", &obj->bus_type, &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, "bus", &obj->bus, &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, "target", &obj->target, &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, "unit", &obj->unit, &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_GuestDiskAddress(Visitor *v, const char *name, GuestDiskAddress **obj, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, name, (void **)obj, sizeof(GuestDiskAddress), &err);
    if (err) {
        goto out;
    }
    if (!*obj) {
        goto out_obj;
    }
    visit_type_GuestDiskAddress_members(v, *obj, &err);
    if (err) {
        goto out_obj;
    }
    visit_check_struct(v, &err);
out_obj:
    visit_end_struct(v, (void **)obj);
    if (err && visit_is_input(v)) {
        qapi_free_GuestDiskAddress(*obj);
        *obj = NULL;
    }
out:
    error_propagate(errp, err);
}

void visit_type_GuestDiskAddressList(Visitor *v, const char *name, GuestDiskAddressList **obj, Error **errp)
{
    Error *err = NULL;
    GuestDiskAddressList *tail;
    size_t size = sizeof(**obj);

    visit_start_list(v, name, (GenericList **)obj, size, &err);
    if (err) {
        goto out;
    }

    for (tail = *obj; tail;
         tail = (GuestDiskAddressList *)visit_next_list(v, (GenericList *)tail, size)) {
        visit_type_GuestDiskAddress(v, NULL, &tail->value, &err);
        if (err) {
            break;
        }
    }

    if (!err) {
        visit_check_list(v, &err);
    }
    visit_end_list(v, (void **)obj);
    if (err && visit_is_input(v)) {
        qapi_free_GuestDiskAddressList(*obj);
        *obj = NULL;
    }
out:
    error_propagate(errp, err);
}

void visit_type_GuestFilesystemInfo_members(Visitor *v, GuestFilesystemInfo *obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, "name", &obj->name, &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, "mountpoint", &obj->mountpoint, &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, "type", &obj->type, &err);
    if (err) {
        goto out;
    }
    if (visit_optional(v, "used-bytes", &obj->has_used_bytes)) {
        visit_type_uint64(v, "used-bytes", &obj->used_bytes, &err);
        if (err) {
            goto out;
        }
    }
    if (visit_optional(v, "total-bytes", &obj->has_total_bytes)) {
        visit_type_uint64(v, "total-bytes", &obj->total_bytes, &err);
        if (err) {
            goto out;
        }
    }
    visit_type_GuestDiskAddressList(v, "disk", &obj->disk, &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_GuestFilesystemInfo(Visitor *v, const char *name, GuestFilesystemInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, name, (void **)obj, sizeof(GuestFilesystemInfo), &err);
    if (err) {
        goto out;
    }
    if (!*obj) {
        goto out_obj;
    }
    visit_type_GuestFilesystemInfo_members(v, *obj, &err);
    if (err) {
        goto out_obj;
    }
    visit_check_struct(v, &err);
out_obj:
    visit_end_struct(v, (void **)obj);
    if (err && visit_is_input(v)) {
        qapi_free_GuestFilesystemInfo(*obj);
        *obj = NULL;
    }
out:
    error_propagate(errp, err);
}

void visit_type_GuestFilesystemInfoList(Visitor *v, const char *name, GuestFilesystemInfoList **obj, Error **errp)
{
    Error *err = NULL;
    GuestFilesystemInfoList *tail;
    size_t size = sizeof(**obj);

    visit_start_list(v, name, (GenericList **)obj, size, &err);
    if (err) {
        goto out;
    }

    for (tail = *obj; tail;
         tail = (GuestFilesystemInfoList *)visit_next_list(v, (GenericList *)tail, size)) {
        visit_type_GuestFilesystemInfo(v, NULL, &tail->value, &err);
        if (err) {
            break;
        }
    }

    if (!err) {
        visit_check_list(v, &err);
    }
    visit_end_list(v, (void **)obj);
    if (err && visit_is_input(v)) {
        qapi_free_GuestFilesystemInfoList(*obj);
        *obj = NULL;
    }
out:
    error_propagate(errp, err);
}

void visit_type_q_obj_guest_set_user_password_arg_members(Visitor *v, q_obj_guest_set_user_password_arg *obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, "username", &obj->username, &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, "password", &obj->password, &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, "crypted", &obj->crypted, &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_GuestMemoryBlock_members(Visitor *v, GuestMemoryBlock *obj, Error **errp)
{
    Error *err = NULL;

    visit_type_uint64(v, "phys-index", &obj->phys_index, &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, "online", &obj->online, &err);
    if (err) {
        goto out;
    }
    if (visit_optional(v, "can-offline", &obj->has_can_offline)) {
        visit_type_bool(v, "can-offline", &obj->can_offline, &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_GuestMemoryBlock(Visitor *v, const char *name, GuestMemoryBlock **obj, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, name, (void **)obj, sizeof(GuestMemoryBlock), &err);
    if (err) {
        goto out;
    }
    if (!*obj) {
        goto out_obj;
    }
    visit_type_GuestMemoryBlock_members(v, *obj, &err);
    if (err) {
        goto out_obj;
    }
    visit_check_struct(v, &err);
out_obj:
    visit_end_struct(v, (void **)obj);
    if (err && visit_is_input(v)) {
        qapi_free_GuestMemoryBlock(*obj);
        *obj = NULL;
    }
out:
    error_propagate(errp, err);
}

void visit_type_GuestMemoryBlockList(Visitor *v, const char *name, GuestMemoryBlockList **obj, Error **errp)
{
    Error *err = NULL;
    GuestMemoryBlockList *tail;
    size_t size = sizeof(**obj);

    visit_start_list(v, name, (GenericList **)obj, size, &err);
    if (err) {
        goto out;
    }

    for (tail = *obj; tail;
         tail = (GuestMemoryBlockList *)visit_next_list(v, (GenericList *)tail, size)) {
        visit_type_GuestMemoryBlock(v, NULL, &tail->value, &err);
        if (err) {
            break;
        }
    }

    if (!err) {
        visit_check_list(v, &err);
    }
    visit_end_list(v, (void **)obj);
    if (err && visit_is_input(v)) {
        qapi_free_GuestMemoryBlockList(*obj);
        *obj = NULL;
    }
out:
    error_propagate(errp, err);
}

void visit_type_GuestMemoryBlockResponseType(Visitor *v, const char *name, GuestMemoryBlockResponseType *obj, Error **errp)
{
    int value = *obj;
    visit_type_enum(v, name, &value, &GuestMemoryBlockResponseType_lookup, errp);
    *obj = value;
}

void visit_type_GuestMemoryBlockResponse_members(Visitor *v, GuestMemoryBlockResponse *obj, Error **errp)
{
    Error *err = NULL;

    visit_type_uint64(v, "phys-index", &obj->phys_index, &err);
    if (err) {
        goto out;
    }
    visit_type_GuestMemoryBlockResponseType(v, "response", &obj->response, &err);
    if (err) {
        goto out;
    }
    if (visit_optional(v, "error-code", &obj->has_error_code)) {
        visit_type_int(v, "error-code", &obj->error_code, &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_GuestMemoryBlockResponse(Visitor *v, const char *name, GuestMemoryBlockResponse **obj, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, name, (void **)obj, sizeof(GuestMemoryBlockResponse), &err);
    if (err) {
        goto out;
    }
    if (!*obj) {
        goto out_obj;
    }
    visit_type_GuestMemoryBlockResponse_members(v, *obj, &err);
    if (err) {
        goto out_obj;
    }
    visit_check_struct(v, &err);
out_obj:
    visit_end_struct(v, (void **)obj);
    if (err && visit_is_input(v)) {
        qapi_free_GuestMemoryBlockResponse(*obj);
        *obj = NULL;
    }
out:
    error_propagate(errp, err);
}

void visit_type_q_obj_guest_set_memory_blocks_arg_members(Visitor *v, q_obj_guest_set_memory_blocks_arg *obj, Error **errp)
{
    Error *err = NULL;

    visit_type_GuestMemoryBlockList(v, "mem-blks", &obj->mem_blks, &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_GuestMemoryBlockResponseList(Visitor *v, const char *name, GuestMemoryBlockResponseList **obj, Error **errp)
{
    Error *err = NULL;
    GuestMemoryBlockResponseList *tail;
    size_t size = sizeof(**obj);

    visit_start_list(v, name, (GenericList **)obj, size, &err);
    if (err) {
        goto out;
    }

    for (tail = *obj; tail;
         tail = (GuestMemoryBlockResponseList *)visit_next_list(v, (GenericList *)tail, size)) {
        visit_type_GuestMemoryBlockResponse(v, NULL, &tail->value, &err);
        if (err) {
            break;
        }
    }

    if (!err) {
        visit_check_list(v, &err);
    }
    visit_end_list(v, (void **)obj);
    if (err && visit_is_input(v)) {
        qapi_free_GuestMemoryBlockResponseList(*obj);
        *obj = NULL;
    }
out:
    error_propagate(errp, err);
}

void visit_type_GuestMemoryBlockInfo_members(Visitor *v, GuestMemoryBlockInfo *obj, Error **errp)
{
    Error *err = NULL;

    visit_type_uint64(v, "size", &obj->size, &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_GuestMemoryBlockInfo(Visitor *v, const char *name, GuestMemoryBlockInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, name, (void **)obj, sizeof(GuestMemoryBlockInfo), &err);
    if (err) {
        goto out;
    }
    if (!*obj) {
        goto out_obj;
    }
    visit_type_GuestMemoryBlockInfo_members(v, *obj, &err);
    if (err) {
        goto out_obj;
    }
    visit_check_struct(v, &err);
out_obj:
    visit_end_struct(v, (void **)obj);
    if (err && visit_is_input(v)) {
        qapi_free_GuestMemoryBlockInfo(*obj);
        *obj = NULL;
    }
out:
    error_propagate(errp, err);
}

void visit_type_GuestExecStatus_members(Visitor *v, GuestExecStatus *obj, Error **errp)
{
    Error *err = NULL;

    visit_type_bool(v, "exited", &obj->exited, &err);
    if (err) {
        goto out;
    }
    if (visit_optional(v, "exitcode", &obj->has_exitcode)) {
        visit_type_int(v, "exitcode", &obj->exitcode, &err);
        if (err) {
            goto out;
        }
    }
    if (visit_optional(v, "signal", &obj->has_signal)) {
        visit_type_int(v, "signal", &obj->signal, &err);
        if (err) {
            goto out;
        }
    }
    if (visit_optional(v, "out-data", &obj->has_out_data)) {
        visit_type_str(v, "out-data", &obj->out_data, &err);
        if (err) {
            goto out;
        }
    }
    if (visit_optional(v, "err-data", &obj->has_err_data)) {
        visit_type_str(v, "err-data", &obj->err_data, &err);
        if (err) {
            goto out;
        }
    }
    if (visit_optional(v, "out-truncated", &obj->has_out_truncated)) {
        visit_type_bool(v, "out-truncated", &obj->out_truncated, &err);
        if (err) {
            goto out;
        }
    }
    if (visit_optional(v, "err-truncated", &obj->has_err_truncated)) {
        visit_type_bool(v, "err-truncated", &obj->err_truncated, &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_GuestExecStatus(Visitor *v, const char *name, GuestExecStatus **obj, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, name, (void **)obj, sizeof(GuestExecStatus), &err);
    if (err) {
        goto out;
    }
    if (!*obj) {
        goto out_obj;
    }
    visit_type_GuestExecStatus_members(v, *obj, &err);
    if (err) {
        goto out_obj;
    }
    visit_check_struct(v, &err);
out_obj:
    visit_end_struct(v, (void **)obj);
    if (err && visit_is_input(v)) {
        qapi_free_GuestExecStatus(*obj);
        *obj = NULL;
    }
out:
    error_propagate(errp, err);
}

void visit_type_q_obj_guest_exec_status_arg_members(Visitor *v, q_obj_guest_exec_status_arg *obj, Error **errp)
{
    Error *err = NULL;

    visit_type_int(v, "pid", &obj->pid, &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_GuestExec_members(Visitor *v, GuestExec *obj, Error **errp)
{
    Error *err = NULL;

    visit_type_int(v, "pid", &obj->pid, &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_GuestExec(Visitor *v, const char *name, GuestExec **obj, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, name, (void **)obj, sizeof(GuestExec), &err);
    if (err) {
        goto out;
    }
    if (!*obj) {
        goto out_obj;
    }
    visit_type_GuestExec_members(v, *obj, &err);
    if (err) {
        goto out_obj;
    }
    visit_check_struct(v, &err);
out_obj:
    visit_end_struct(v, (void **)obj);
    if (err && visit_is_input(v)) {
        qapi_free_GuestExec(*obj);
        *obj = NULL;
    }
out:
    error_propagate(errp, err);
}

void visit_type_q_obj_guest_exec_arg_members(Visitor *v, q_obj_guest_exec_arg *obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, "path", &obj->path, &err);
    if (err) {
        goto out;
    }
    if (visit_optional(v, "arg", &obj->has_arg)) {
        visit_type_strList(v, "arg", &obj->arg, &err);
        if (err) {
            goto out;
        }
    }
    if (visit_optional(v, "env", &obj->has_env)) {
        visit_type_strList(v, "env", &obj->env, &err);
        if (err) {
            goto out;
        }
    }
    if (visit_optional(v, "input-data", &obj->has_input_data)) {
        visit_type_str(v, "input-data", &obj->input_data, &err);
        if (err) {
            goto out;
        }
    }
    if (visit_optional(v, "capture-output", &obj->has_capture_output)) {
        visit_type_bool(v, "capture-output", &obj->capture_output, &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_GuestHostName_members(Visitor *v, GuestHostName *obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, "host-name", &obj->host_name, &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_GuestHostName(Visitor *v, const char *name, GuestHostName **obj, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, name, (void **)obj, sizeof(GuestHostName), &err);
    if (err) {
        goto out;
    }
    if (!*obj) {
        goto out_obj;
    }
    visit_type_GuestHostName_members(v, *obj, &err);
    if (err) {
        goto out_obj;
    }
    visit_check_struct(v, &err);
out_obj:
    visit_end_struct(v, (void **)obj);
    if (err && visit_is_input(v)) {
        qapi_free_GuestHostName(*obj);
        *obj = NULL;
    }
out:
    error_propagate(errp, err);
}

void visit_type_GuestUser_members(Visitor *v, GuestUser *obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, "user", &obj->user, &err);
    if (err) {
        goto out;
    }
    visit_type_number(v, "login-time", &obj->login_time, &err);
    if (err) {
        goto out;
    }
    if (visit_optional(v, "domain", &obj->has_domain)) {
        visit_type_str(v, "domain", &obj->domain, &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_GuestUser(Visitor *v, const char *name, GuestUser **obj, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, name, (void **)obj, sizeof(GuestUser), &err);
    if (err) {
        goto out;
    }
    if (!*obj) {
        goto out_obj;
    }
    visit_type_GuestUser_members(v, *obj, &err);
    if (err) {
        goto out_obj;
    }
    visit_check_struct(v, &err);
out_obj:
    visit_end_struct(v, (void **)obj);
    if (err && visit_is_input(v)) {
        qapi_free_GuestUser(*obj);
        *obj = NULL;
    }
out:
    error_propagate(errp, err);
}

void visit_type_GuestUserList(Visitor *v, const char *name, GuestUserList **obj, Error **errp)
{
    Error *err = NULL;
    GuestUserList *tail;
    size_t size = sizeof(**obj);

    visit_start_list(v, name, (GenericList **)obj, size, &err);
    if (err) {
        goto out;
    }

    for (tail = *obj; tail;
         tail = (GuestUserList *)visit_next_list(v, (GenericList *)tail, size)) {
        visit_type_GuestUser(v, NULL, &tail->value, &err);
        if (err) {
            break;
        }
    }

    if (!err) {
        visit_check_list(v, &err);
    }
    visit_end_list(v, (void **)obj);
    if (err && visit_is_input(v)) {
        qapi_free_GuestUserList(*obj);
        *obj = NULL;
    }
out:
    error_propagate(errp, err);
}

void visit_type_GuestTimezone_members(Visitor *v, GuestTimezone *obj, Error **errp)
{
    Error *err = NULL;

    if (visit_optional(v, "zone", &obj->has_zone)) {
        visit_type_str(v, "zone", &obj->zone, &err);
        if (err) {
            goto out;
        }
    }
    visit_type_int(v, "offset", &obj->offset, &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_GuestTimezone(Visitor *v, const char *name, GuestTimezone **obj, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, name, (void **)obj, sizeof(GuestTimezone), &err);
    if (err) {
        goto out;
    }
    if (!*obj) {
        goto out_obj;
    }
    visit_type_GuestTimezone_members(v, *obj, &err);
    if (err) {
        goto out_obj;
    }
    visit_check_struct(v, &err);
out_obj:
    visit_end_struct(v, (void **)obj);
    if (err && visit_is_input(v)) {
        qapi_free_GuestTimezone(*obj);
        *obj = NULL;
    }
out:
    error_propagate(errp, err);
}

void visit_type_GuestOSInfo_members(Visitor *v, GuestOSInfo *obj, Error **errp)
{
    Error *err = NULL;

    if (visit_optional(v, "kernel-release", &obj->has_kernel_release)) {
        visit_type_str(v, "kernel-release", &obj->kernel_release, &err);
        if (err) {
            goto out;
        }
    }
    if (visit_optional(v, "kernel-version", &obj->has_kernel_version)) {
        visit_type_str(v, "kernel-version", &obj->kernel_version, &err);
        if (err) {
            goto out;
        }
    }
    if (visit_optional(v, "machine", &obj->has_machine)) {
        visit_type_str(v, "machine", &obj->machine, &err);
        if (err) {
            goto out;
        }
    }
    if (visit_optional(v, "id", &obj->has_id)) {
        visit_type_str(v, "id", &obj->id, &err);
        if (err) {
            goto out;
        }
    }
    if (visit_optional(v, "name", &obj->has_name)) {
        visit_type_str(v, "name", &obj->name, &err);
        if (err) {
            goto out;
        }
    }
    if (visit_optional(v, "pretty-name", &obj->has_pretty_name)) {
        visit_type_str(v, "pretty-name", &obj->pretty_name, &err);
        if (err) {
            goto out;
        }
    }
    if (visit_optional(v, "version", &obj->has_version)) {
        visit_type_str(v, "version", &obj->version, &err);
        if (err) {
            goto out;
        }
    }
    if (visit_optional(v, "version-id", &obj->has_version_id)) {
        visit_type_str(v, "version-id", &obj->version_id, &err);
        if (err) {
            goto out;
        }
    }
    if (visit_optional(v, "variant", &obj->has_variant)) {
        visit_type_str(v, "variant", &obj->variant, &err);
        if (err) {
            goto out;
        }
    }
    if (visit_optional(v, "variant-id", &obj->has_variant_id)) {
        visit_type_str(v, "variant-id", &obj->variant_id, &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_GuestOSInfo(Visitor *v, const char *name, GuestOSInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, name, (void **)obj, sizeof(GuestOSInfo), &err);
    if (err) {
        goto out;
    }
    if (!*obj) {
        goto out_obj;
    }
    visit_type_GuestOSInfo_members(v, *obj, &err);
    if (err) {
        goto out_obj;
    }
    visit_check_struct(v, &err);
out_obj:
    visit_end_struct(v, (void **)obj);
    if (err && visit_is_input(v)) {
        qapi_free_GuestOSInfo(*obj);
        *obj = NULL;
    }
out:
    error_propagate(errp, err);
}
/* Dummy declaration to prevent empty .o file */
char dummy_qga_qapi_visit_c;
