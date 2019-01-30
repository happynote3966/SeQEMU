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

#ifndef QAPI_TYPES_COMMON_H
#define QAPI_TYPES_COMMON_H

#include "qapi/qapi-builtin-types.h"

typedef enum QapiErrorClass {
    QAPI_ERROR_CLASS_GENERICERROR = 0,
    QAPI_ERROR_CLASS_COMMANDNOTFOUND = 1,
    QAPI_ERROR_CLASS_DEVICENOTACTIVE = 2,
    QAPI_ERROR_CLASS_DEVICENOTFOUND = 3,
    QAPI_ERROR_CLASS_KVMMISSINGCAP = 4,
    QAPI_ERROR_CLASS__MAX = 5,
} QapiErrorClass;

#define QapiErrorClass_str(val) \
    qapi_enum_lookup(&QapiErrorClass_lookup, (val))

extern const QEnumLookup QapiErrorClass_lookup;

typedef enum IoOperationType {
    IO_OPERATION_TYPE_READ = 0,
    IO_OPERATION_TYPE_WRITE = 1,
    IO_OPERATION_TYPE__MAX = 2,
} IoOperationType;

#define IoOperationType_str(val) \
    qapi_enum_lookup(&IoOperationType_lookup, (val))

extern const QEnumLookup IoOperationType_lookup;

typedef enum OnOffAuto {
    ON_OFF_AUTO_AUTO = 0,
    ON_OFF_AUTO_ON = 1,
    ON_OFF_AUTO_OFF = 2,
    ON_OFF_AUTO__MAX = 3,
} OnOffAuto;

#define OnOffAuto_str(val) \
    qapi_enum_lookup(&OnOffAuto_lookup, (val))

extern const QEnumLookup OnOffAuto_lookup;

typedef enum OnOffSplit {
    ON_OFF_SPLIT_ON = 0,
    ON_OFF_SPLIT_OFF = 1,
    ON_OFF_SPLIT_SPLIT = 2,
    ON_OFF_SPLIT__MAX = 3,
} OnOffSplit;

#define OnOffSplit_str(val) \
    qapi_enum_lookup(&OnOffSplit_lookup, (val))

extern const QEnumLookup OnOffSplit_lookup;

typedef struct String String;

typedef struct StrOrNull StrOrNull;

typedef enum OffAutoPCIBAR {
    OFF_AUTOPCIBAR_OFF = 0,
    OFF_AUTOPCIBAR_AUTO = 1,
    OFF_AUTOPCIBAR_BAR0 = 2,
    OFF_AUTOPCIBAR_BAR1 = 3,
    OFF_AUTOPCIBAR_BAR2 = 4,
    OFF_AUTOPCIBAR_BAR3 = 5,
    OFF_AUTOPCIBAR_BAR4 = 6,
    OFF_AUTOPCIBAR_BAR5 = 7,
    OFF_AUTOPCIBAR__MAX = 8,
} OffAutoPCIBAR;

#define OffAutoPCIBAR_str(val) \
    qapi_enum_lookup(&OffAutoPCIBAR_lookup, (val))

extern const QEnumLookup OffAutoPCIBAR_lookup;

typedef enum SysEmuTarget {
    SYS_EMU_TARGET_AARCH64 = 0,
    SYS_EMU_TARGET_ALPHA = 1,
    SYS_EMU_TARGET_ARM = 2,
    SYS_EMU_TARGET_CRIS = 3,
    SYS_EMU_TARGET_HPPA = 4,
    SYS_EMU_TARGET_I386 = 5,
    SYS_EMU_TARGET_LM32 = 6,
    SYS_EMU_TARGET_M68K = 7,
    SYS_EMU_TARGET_MICROBLAZE = 8,
    SYS_EMU_TARGET_MICROBLAZEEL = 9,
    SYS_EMU_TARGET_MIPS = 10,
    SYS_EMU_TARGET_MIPS64 = 11,
    SYS_EMU_TARGET_MIPS64EL = 12,
    SYS_EMU_TARGET_MIPSEL = 13,
    SYS_EMU_TARGET_MOXIE = 14,
    SYS_EMU_TARGET_NIOS2 = 15,
    SYS_EMU_TARGET_OR1K = 16,
    SYS_EMU_TARGET_PPC = 17,
    SYS_EMU_TARGET_PPC64 = 18,
    SYS_EMU_TARGET_PPCEMB = 19,
    SYS_EMU_TARGET_RISCV32 = 20,
    SYS_EMU_TARGET_RISCV64 = 21,
    SYS_EMU_TARGET_S390X = 22,
    SYS_EMU_TARGET_SH4 = 23,
    SYS_EMU_TARGET_SH4EB = 24,
    SYS_EMU_TARGET_SPARC = 25,
    SYS_EMU_TARGET_SPARC64 = 26,
    SYS_EMU_TARGET_TRICORE = 27,
    SYS_EMU_TARGET_UNICORE32 = 28,
    SYS_EMU_TARGET_X86_64 = 29,
    SYS_EMU_TARGET_XTENSA = 30,
    SYS_EMU_TARGET_XTENSAEB = 31,
    SYS_EMU_TARGET__MAX = 32,
} SysEmuTarget;

#define SysEmuTarget_str(val) \
    qapi_enum_lookup(&SysEmuTarget_lookup, (val))

extern const QEnumLookup SysEmuTarget_lookup;

struct String {
    char *str;
};

void qapi_free_String(String *obj);

struct StrOrNull {
    QType type;
    union { /* union tag is @type */
        char *s;
        QNull *n;
    } u;
};

void qapi_free_StrOrNull(StrOrNull *obj);

#endif /* QAPI_TYPES_COMMON_H */
