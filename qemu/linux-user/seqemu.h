#ifndef SEQEMU_H
#define SEQEMU_H

#include "qemu/osdep.h"
#include "qemu.h"

#include <stdint.h>

extern unsigned long seqemu_guest_base;
extern struct image_info seqemu_image_info;

void seqemu_print_debug(void);
void seqemu_save_guest_base(unsigned long base);
void seqemu_print_guest_base(void);
void seqemu_save_image_info(struct image_info *info);
void seqemu_print_image_info(void);

// feature-002 Filtering the Dangerous Functions

void seqemu_bswap_2(void *p);
void seqemu_bswap_4(void *p);

void seqemu_read_elf(int fd);

typedef struct{
	char *name;
	//unsigned int addr;
	unsigned int got_addr;
	unsigned int plt_addr;
	unsigned int type;

}Seqemu_target_func;

#define SEQEMU_MAX_FUNCTION_NAME_LENGTH 100
#define SEQEMU_FUNC_TYPE_DANGEROUS 0x1
#define SEQEMU_FUNC_TYPE_FORMAT 0x2
#define SEQEMU_FUNC_TYPE_MALLOC 0x3
#define SEQEMU_FUNC_TYPE_BUFFER 0x4
#define SEQEMU_FUNC_TYPE_OTHER 0x5


// feature-005 Restricting Format String
void seqemu_check_format_string(CPUArchState *env);

// feature-006 Checking Control Flow
void seqemu_check_control_flow(CPUArchState *env);

// feature-007 Checking Heap Chunk
void seqemu_check_heap_metadata(CPUArchState *env);

#endif /* SEQEMU_H */
