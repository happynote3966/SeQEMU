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

#ifndef QGA_QAPI_TYPES_H
#define QGA_QAPI_TYPES_H

#include "qapi/qapi-builtin-types.h"

typedef struct q_obj_guest_sync_delimited_arg q_obj_guest_sync_delimited_arg;

typedef struct q_obj_guest_sync_arg q_obj_guest_sync_arg;

typedef struct q_obj_guest_set_time_arg q_obj_guest_set_time_arg;

typedef struct GuestAgentCommandInfo GuestAgentCommandInfo;

typedef struct GuestAgentCommandInfoList GuestAgentCommandInfoList;

typedef struct GuestAgentInfo GuestAgentInfo;

typedef struct q_obj_guest_shutdown_arg q_obj_guest_shutdown_arg;

typedef struct q_obj_guest_file_open_arg q_obj_guest_file_open_arg;

typedef struct q_obj_guest_file_close_arg q_obj_guest_file_close_arg;

typedef struct GuestFileRead GuestFileRead;

typedef struct q_obj_guest_file_read_arg q_obj_guest_file_read_arg;

typedef struct GuestFileWrite GuestFileWrite;

typedef struct q_obj_guest_file_write_arg q_obj_guest_file_write_arg;

typedef struct GuestFileSeek GuestFileSeek;

typedef enum QGASeek {
    QGA_SEEK_SET = 0,
    QGA_SEEK_CUR = 1,
    QGA_SEEK_END = 2,
    QGA_SEEK__MAX = 3,
} QGASeek;

#define QGASeek_str(val) \
    qapi_enum_lookup(&QGASeek_lookup, (val))

extern const QEnumLookup QGASeek_lookup;

typedef struct GuestFileWhence GuestFileWhence;

typedef struct q_obj_guest_file_seek_arg q_obj_guest_file_seek_arg;

typedef struct q_obj_guest_file_flush_arg q_obj_guest_file_flush_arg;

typedef enum GuestFsfreezeStatus {
    GUEST_FSFREEZE_STATUS_THAWED = 0,
    GUEST_FSFREEZE_STATUS_FROZEN = 1,
    GUEST_FSFREEZE_STATUS__MAX = 2,
} GuestFsfreezeStatus;

#define GuestFsfreezeStatus_str(val) \
    qapi_enum_lookup(&GuestFsfreezeStatus_lookup, (val))

extern const QEnumLookup GuestFsfreezeStatus_lookup;

typedef struct q_obj_guest_fsfreeze_freeze_list_arg q_obj_guest_fsfreeze_freeze_list_arg;

typedef struct GuestFilesystemTrimResult GuestFilesystemTrimResult;

typedef struct GuestFilesystemTrimResultList GuestFilesystemTrimResultList;

typedef struct GuestFilesystemTrimResponse GuestFilesystemTrimResponse;

typedef struct q_obj_guest_fstrim_arg q_obj_guest_fstrim_arg;

typedef enum GuestIpAddressType {
    GUEST_IP_ADDRESS_TYPE_IPV4 = 0,
    GUEST_IP_ADDRESS_TYPE_IPV6 = 1,
    GUEST_IP_ADDRESS_TYPE__MAX = 2,
} GuestIpAddressType;

#define GuestIpAddressType_str(val) \
    qapi_enum_lookup(&GuestIpAddressType_lookup, (val))

extern const QEnumLookup GuestIpAddressType_lookup;

typedef struct GuestIpAddress GuestIpAddress;

typedef struct GuestNetworkInterfaceStat GuestNetworkInterfaceStat;

typedef struct GuestIpAddressList GuestIpAddressList;

typedef struct GuestNetworkInterface GuestNetworkInterface;

typedef struct GuestNetworkInterfaceList GuestNetworkInterfaceList;

typedef struct GuestLogicalProcessor GuestLogicalProcessor;

typedef struct GuestLogicalProcessorList GuestLogicalProcessorList;

typedef struct q_obj_guest_set_vcpus_arg q_obj_guest_set_vcpus_arg;

typedef enum GuestDiskBusType {
    GUEST_DISK_BUS_TYPE_IDE = 0,
    GUEST_DISK_BUS_TYPE_FDC = 1,
    GUEST_DISK_BUS_TYPE_SCSI = 2,
    GUEST_DISK_BUS_TYPE_VIRTIO = 3,
    GUEST_DISK_BUS_TYPE_XEN = 4,
    GUEST_DISK_BUS_TYPE_USB = 5,
    GUEST_DISK_BUS_TYPE_UML = 6,
    GUEST_DISK_BUS_TYPE_SATA = 7,
    GUEST_DISK_BUS_TYPE_SD = 8,
    GUEST_DISK_BUS_TYPE_UNKNOWN = 9,
    GUEST_DISK_BUS_TYPE_IEEE1394 = 10,
    GUEST_DISK_BUS_TYPE_SSA = 11,
    GUEST_DISK_BUS_TYPE_FIBRE = 12,
    GUEST_DISK_BUS_TYPE_RAID = 13,
    GUEST_DISK_BUS_TYPE_ISCSI = 14,
    GUEST_DISK_BUS_TYPE_SAS = 15,
    GUEST_DISK_BUS_TYPE_MMC = 16,
    GUEST_DISK_BUS_TYPE_VIRTUAL = 17,
    GUEST_DISK_BUS_TYPE_FILE_BACKED_VIRTUAL = 18,
    GUEST_DISK_BUS_TYPE__MAX = 19,
} GuestDiskBusType;

#define GuestDiskBusType_str(val) \
    qapi_enum_lookup(&GuestDiskBusType_lookup, (val))

extern const QEnumLookup GuestDiskBusType_lookup;

typedef struct GuestPCIAddress GuestPCIAddress;

typedef struct GuestDiskAddress GuestDiskAddress;

typedef struct GuestDiskAddressList GuestDiskAddressList;

typedef struct GuestFilesystemInfo GuestFilesystemInfo;

typedef struct GuestFilesystemInfoList GuestFilesystemInfoList;

typedef struct q_obj_guest_set_user_password_arg q_obj_guest_set_user_password_arg;

typedef struct GuestMemoryBlock GuestMemoryBlock;

typedef struct GuestMemoryBlockList GuestMemoryBlockList;

typedef enum GuestMemoryBlockResponseType {
    GUEST_MEMORY_BLOCK_RESPONSE_TYPE_SUCCESS = 0,
    GUEST_MEMORY_BLOCK_RESPONSE_TYPE_NOT_FOUND = 1,
    GUEST_MEMORY_BLOCK_RESPONSE_TYPE_OPERATION_NOT_SUPPORTED = 2,
    GUEST_MEMORY_BLOCK_RESPONSE_TYPE_OPERATION_FAILED = 3,
    GUEST_MEMORY_BLOCK_RESPONSE_TYPE__MAX = 4,
} GuestMemoryBlockResponseType;

#define GuestMemoryBlockResponseType_str(val) \
    qapi_enum_lookup(&GuestMemoryBlockResponseType_lookup, (val))

extern const QEnumLookup GuestMemoryBlockResponseType_lookup;

typedef struct GuestMemoryBlockResponse GuestMemoryBlockResponse;

typedef struct q_obj_guest_set_memory_blocks_arg q_obj_guest_set_memory_blocks_arg;

typedef struct GuestMemoryBlockResponseList GuestMemoryBlockResponseList;

typedef struct GuestMemoryBlockInfo GuestMemoryBlockInfo;

typedef struct GuestExecStatus GuestExecStatus;

typedef struct q_obj_guest_exec_status_arg q_obj_guest_exec_status_arg;

typedef struct GuestExec GuestExec;

typedef struct q_obj_guest_exec_arg q_obj_guest_exec_arg;

typedef struct GuestHostName GuestHostName;

typedef struct GuestUser GuestUser;

typedef struct GuestUserList GuestUserList;

typedef struct GuestTimezone GuestTimezone;

typedef struct GuestOSInfo GuestOSInfo;

struct q_obj_guest_sync_delimited_arg {
    int64_t id;
};

struct q_obj_guest_sync_arg {
    int64_t id;
};

struct q_obj_guest_set_time_arg {
    bool has_time;
    int64_t time;
};

struct GuestAgentCommandInfo {
    char *name;
    bool enabled;
    bool success_response;
};

void qapi_free_GuestAgentCommandInfo(GuestAgentCommandInfo *obj);

struct GuestAgentCommandInfoList {
    GuestAgentCommandInfoList *next;
    GuestAgentCommandInfo *value;
};

void qapi_free_GuestAgentCommandInfoList(GuestAgentCommandInfoList *obj);

struct GuestAgentInfo {
    char *version;
    GuestAgentCommandInfoList *supported_commands;
};

void qapi_free_GuestAgentInfo(GuestAgentInfo *obj);

struct q_obj_guest_shutdown_arg {
    bool has_mode;
    char *mode;
};

struct q_obj_guest_file_open_arg {
    char *path;
    bool has_mode;
    char *mode;
};

struct q_obj_guest_file_close_arg {
    int64_t handle;
};

struct GuestFileRead {
    int64_t count;
    char *buf_b64;
    bool eof;
};

void qapi_free_GuestFileRead(GuestFileRead *obj);

struct q_obj_guest_file_read_arg {
    int64_t handle;
    bool has_count;
    int64_t count;
};

struct GuestFileWrite {
    int64_t count;
    bool eof;
};

void qapi_free_GuestFileWrite(GuestFileWrite *obj);

struct q_obj_guest_file_write_arg {
    int64_t handle;
    char *buf_b64;
    bool has_count;
    int64_t count;
};

struct GuestFileSeek {
    int64_t position;
    bool eof;
};

void qapi_free_GuestFileSeek(GuestFileSeek *obj);

struct GuestFileWhence {
    QType type;
    union { /* union tag is @type */
        int64_t value;
        QGASeek name;
    } u;
};

void qapi_free_GuestFileWhence(GuestFileWhence *obj);

struct q_obj_guest_file_seek_arg {
    int64_t handle;
    int64_t offset;
    GuestFileWhence *whence;
};

struct q_obj_guest_file_flush_arg {
    int64_t handle;
};

struct q_obj_guest_fsfreeze_freeze_list_arg {
    bool has_mountpoints;
    strList *mountpoints;
};

struct GuestFilesystemTrimResult {
    char *path;
    bool has_trimmed;
    int64_t trimmed;
    bool has_minimum;
    int64_t minimum;
    bool has_error;
    char *error;
};

void qapi_free_GuestFilesystemTrimResult(GuestFilesystemTrimResult *obj);

struct GuestFilesystemTrimResultList {
    GuestFilesystemTrimResultList *next;
    GuestFilesystemTrimResult *value;
};

void qapi_free_GuestFilesystemTrimResultList(GuestFilesystemTrimResultList *obj);

struct GuestFilesystemTrimResponse {
    GuestFilesystemTrimResultList *paths;
};

void qapi_free_GuestFilesystemTrimResponse(GuestFilesystemTrimResponse *obj);

struct q_obj_guest_fstrim_arg {
    bool has_minimum;
    int64_t minimum;
};

struct GuestIpAddress {
    char *ip_address;
    GuestIpAddressType ip_address_type;
    int64_t prefix;
};

void qapi_free_GuestIpAddress(GuestIpAddress *obj);

struct GuestNetworkInterfaceStat {
    uint64_t rx_bytes;
    uint64_t rx_packets;
    uint64_t rx_errs;
    uint64_t rx_dropped;
    uint64_t tx_bytes;
    uint64_t tx_packets;
    uint64_t tx_errs;
    uint64_t tx_dropped;
};

void qapi_free_GuestNetworkInterfaceStat(GuestNetworkInterfaceStat *obj);

struct GuestIpAddressList {
    GuestIpAddressList *next;
    GuestIpAddress *value;
};

void qapi_free_GuestIpAddressList(GuestIpAddressList *obj);

struct GuestNetworkInterface {
    char *name;
    bool has_hardware_address;
    char *hardware_address;
    bool has_ip_addresses;
    GuestIpAddressList *ip_addresses;
    bool has_statistics;
    GuestNetworkInterfaceStat *statistics;
};

void qapi_free_GuestNetworkInterface(GuestNetworkInterface *obj);

struct GuestNetworkInterfaceList {
    GuestNetworkInterfaceList *next;
    GuestNetworkInterface *value;
};

void qapi_free_GuestNetworkInterfaceList(GuestNetworkInterfaceList *obj);

struct GuestLogicalProcessor {
    int64_t logical_id;
    bool online;
    bool has_can_offline;
    bool can_offline;
};

void qapi_free_GuestLogicalProcessor(GuestLogicalProcessor *obj);

struct GuestLogicalProcessorList {
    GuestLogicalProcessorList *next;
    GuestLogicalProcessor *value;
};

void qapi_free_GuestLogicalProcessorList(GuestLogicalProcessorList *obj);

struct q_obj_guest_set_vcpus_arg {
    GuestLogicalProcessorList *vcpus;
};

struct GuestPCIAddress {
    int64_t domain;
    int64_t bus;
    int64_t slot;
    int64_t function;
};

void qapi_free_GuestPCIAddress(GuestPCIAddress *obj);

struct GuestDiskAddress {
    GuestPCIAddress *pci_controller;
    GuestDiskBusType bus_type;
    int64_t bus;
    int64_t target;
    int64_t unit;
};

void qapi_free_GuestDiskAddress(GuestDiskAddress *obj);

struct GuestDiskAddressList {
    GuestDiskAddressList *next;
    GuestDiskAddress *value;
};

void qapi_free_GuestDiskAddressList(GuestDiskAddressList *obj);

struct GuestFilesystemInfo {
    char *name;
    char *mountpoint;
    char *type;
    bool has_used_bytes;
    uint64_t used_bytes;
    bool has_total_bytes;
    uint64_t total_bytes;
    GuestDiskAddressList *disk;
};

void qapi_free_GuestFilesystemInfo(GuestFilesystemInfo *obj);

struct GuestFilesystemInfoList {
    GuestFilesystemInfoList *next;
    GuestFilesystemInfo *value;
};

void qapi_free_GuestFilesystemInfoList(GuestFilesystemInfoList *obj);

struct q_obj_guest_set_user_password_arg {
    char *username;
    char *password;
    bool crypted;
};

struct GuestMemoryBlock {
    uint64_t phys_index;
    bool online;
    bool has_can_offline;
    bool can_offline;
};

void qapi_free_GuestMemoryBlock(GuestMemoryBlock *obj);

struct GuestMemoryBlockList {
    GuestMemoryBlockList *next;
    GuestMemoryBlock *value;
};

void qapi_free_GuestMemoryBlockList(GuestMemoryBlockList *obj);

struct GuestMemoryBlockResponse {
    uint64_t phys_index;
    GuestMemoryBlockResponseType response;
    bool has_error_code;
    int64_t error_code;
};

void qapi_free_GuestMemoryBlockResponse(GuestMemoryBlockResponse *obj);

struct q_obj_guest_set_memory_blocks_arg {
    GuestMemoryBlockList *mem_blks;
};

struct GuestMemoryBlockResponseList {
    GuestMemoryBlockResponseList *next;
    GuestMemoryBlockResponse *value;
};

void qapi_free_GuestMemoryBlockResponseList(GuestMemoryBlockResponseList *obj);

struct GuestMemoryBlockInfo {
    uint64_t size;
};

void qapi_free_GuestMemoryBlockInfo(GuestMemoryBlockInfo *obj);

struct GuestExecStatus {
    bool exited;
    bool has_exitcode;
    int64_t exitcode;
    bool has_signal;
    int64_t signal;
    bool has_out_data;
    char *out_data;
    bool has_err_data;
    char *err_data;
    bool has_out_truncated;
    bool out_truncated;
    bool has_err_truncated;
    bool err_truncated;
};

void qapi_free_GuestExecStatus(GuestExecStatus *obj);

struct q_obj_guest_exec_status_arg {
    int64_t pid;
};

struct GuestExec {
    int64_t pid;
};

void qapi_free_GuestExec(GuestExec *obj);

struct q_obj_guest_exec_arg {
    char *path;
    bool has_arg;
    strList *arg;
    bool has_env;
    strList *env;
    bool has_input_data;
    char *input_data;
    bool has_capture_output;
    bool capture_output;
};

struct GuestHostName {
    char *host_name;
};

void qapi_free_GuestHostName(GuestHostName *obj);

struct GuestUser {
    char *user;
    double login_time;
    bool has_domain;
    char *domain;
};

void qapi_free_GuestUser(GuestUser *obj);

struct GuestUserList {
    GuestUserList *next;
    GuestUser *value;
};

void qapi_free_GuestUserList(GuestUserList *obj);

struct GuestTimezone {
    bool has_zone;
    char *zone;
    int64_t offset;
};

void qapi_free_GuestTimezone(GuestTimezone *obj);

struct GuestOSInfo {
    bool has_kernel_release;
    char *kernel_release;
    bool has_kernel_version;
    char *kernel_version;
    bool has_machine;
    char *machine;
    bool has_id;
    char *id;
    bool has_name;
    char *name;
    bool has_pretty_name;
    char *pretty_name;
    bool has_version;
    char *version;
    bool has_version_id;
    char *version_id;
    bool has_variant;
    char *variant;
    bool has_variant_id;
    char *variant_id;
};

void qapi_free_GuestOSInfo(GuestOSInfo *obj);

#endif /* QGA_QAPI_TYPES_H */
