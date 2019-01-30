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

#include "qemu/osdep.h"
#include "qapi/dealloc-visitor.h"
#include "qapi-types-common.h"
#include "qapi-visit-common.h"

const QEnumLookup QapiErrorClass_lookup = {
    .array = (const char *const[]) {
        [QAPI_ERROR_CLASS_GENERICERROR] = "GenericError",
        [QAPI_ERROR_CLASS_COMMANDNOTFOUND] = "CommandNotFound",
        [QAPI_ERROR_CLASS_DEVICENOTACTIVE] = "DeviceNotActive",
        [QAPI_ERROR_CLASS_DEVICENOTFOUND] = "DeviceNotFound",
        [QAPI_ERROR_CLASS_KVMMISSINGCAP] = "KVMMissingCap",
    },
    .size = QAPI_ERROR_CLASS__MAX
};

const QEnumLookup IoOperationType_lookup = {
    .array = (const char *const[]) {
        [IO_OPERATION_TYPE_READ] = "read",
        [IO_OPERATION_TYPE_WRITE] = "write",
    },
    .size = IO_OPERATION_TYPE__MAX
};

const QEnumLookup OnOffAuto_lookup = {
    .array = (const char *const[]) {
        [ON_OFF_AUTO_AUTO] = "auto",
        [ON_OFF_AUTO_ON] = "on",
        [ON_OFF_AUTO_OFF] = "off",
    },
    .size = ON_OFF_AUTO__MAX
};

const QEnumLookup OnOffSplit_lookup = {
    .array = (const char *const[]) {
        [ON_OFF_SPLIT_ON] = "on",
        [ON_OFF_SPLIT_OFF] = "off",
        [ON_OFF_SPLIT_SPLIT] = "split",
    },
    .size = ON_OFF_SPLIT__MAX
};

void qapi_free_String(String *obj)
{
    Visitor *v;

    if (!obj) {
        return;
    }

    v = qapi_dealloc_visitor_new();
    visit_type_String(v, NULL, &obj, NULL);
    visit_free(v);
}

void qapi_free_StrOrNull(StrOrNull *obj)
{
    Visitor *v;

    if (!obj) {
        return;
    }

    v = qapi_dealloc_visitor_new();
    visit_type_StrOrNull(v, NULL, &obj, NULL);
    visit_free(v);
}

const QEnumLookup OffAutoPCIBAR_lookup = {
    .array = (const char *const[]) {
        [OFF_AUTOPCIBAR_OFF] = "off",
        [OFF_AUTOPCIBAR_AUTO] = "auto",
        [OFF_AUTOPCIBAR_BAR0] = "bar0",
        [OFF_AUTOPCIBAR_BAR1] = "bar1",
        [OFF_AUTOPCIBAR_BAR2] = "bar2",
        [OFF_AUTOPCIBAR_BAR3] = "bar3",
        [OFF_AUTOPCIBAR_BAR4] = "bar4",
        [OFF_AUTOPCIBAR_BAR5] = "bar5",
    },
    .size = OFF_AUTOPCIBAR__MAX
};

const QEnumLookup SysEmuTarget_lookup = {
    .array = (const char *const[]) {
        [SYS_EMU_TARGET_AARCH64] = "aarch64",
        [SYS_EMU_TARGET_ALPHA] = "alpha",
        [SYS_EMU_TARGET_ARM] = "arm",
        [SYS_EMU_TARGET_CRIS] = "cris",
        [SYS_EMU_TARGET_HPPA] = "hppa",
        [SYS_EMU_TARGET_I386] = "i386",
        [SYS_EMU_TARGET_LM32] = "lm32",
        [SYS_EMU_TARGET_M68K] = "m68k",
        [SYS_EMU_TARGET_MICROBLAZE] = "microblaze",
        [SYS_EMU_TARGET_MICROBLAZEEL] = "microblazeel",
        [SYS_EMU_TARGET_MIPS] = "mips",
        [SYS_EMU_TARGET_MIPS64] = "mips64",
        [SYS_EMU_TARGET_MIPS64EL] = "mips64el",
        [SYS_EMU_TARGET_MIPSEL] = "mipsel",
        [SYS_EMU_TARGET_MOXIE] = "moxie",
        [SYS_EMU_TARGET_NIOS2] = "nios2",
        [SYS_EMU_TARGET_OR1K] = "or1k",
        [SYS_EMU_TARGET_PPC] = "ppc",
        [SYS_EMU_TARGET_PPC64] = "ppc64",
        [SYS_EMU_TARGET_PPCEMB] = "ppcemb",
        [SYS_EMU_TARGET_RISCV32] = "riscv32",
        [SYS_EMU_TARGET_RISCV64] = "riscv64",
        [SYS_EMU_TARGET_S390X] = "s390x",
        [SYS_EMU_TARGET_SH4] = "sh4",
        [SYS_EMU_TARGET_SH4EB] = "sh4eb",
        [SYS_EMU_TARGET_SPARC] = "sparc",
        [SYS_EMU_TARGET_SPARC64] = "sparc64",
        [SYS_EMU_TARGET_TRICORE] = "tricore",
        [SYS_EMU_TARGET_UNICORE32] = "unicore32",
        [SYS_EMU_TARGET_X86_64] = "x86_64",
        [SYS_EMU_TARGET_XTENSA] = "xtensa",
        [SYS_EMU_TARGET_XTENSAEB] = "xtensaeb",
    },
    .size = SYS_EMU_TARGET__MAX
};
/* Dummy declaration to prevent empty .o file */
char dummy_qapi_types_common_c;
