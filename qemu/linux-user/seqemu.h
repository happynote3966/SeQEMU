#ifndef SEQEMU_H
#define SEQEMU_H

#include "qemu/osdep.h"
#include "qemu.h"

#include <stdint.h>
#include <regex.h>
extern unsigned long seqemu_guest_base;
extern struct image_info seqemu_image_info;

void seqemu_print_debug(void);
void seqemu_save_guest_base(unsigned long base);
void seqemu_print_guest_base(void);
void seqemu_save_image_info(struct image_info *info);
void seqemu_print_image_info(void);

// feature-002 Filtering the Dangerous Functions
// feature-010 Random output of Characters
void seqemu_bswap_2(void *p);
void seqemu_bswap_4(void *p);

void seqemu_read_elf(int fd);
void seqemu_random_output_of_characters(void);
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
// feature-009 PowerUp the Restricting Format String feature
unsigned int seqemu_util_count_format_string_parameter(char *format_string);

regmatch_t *seqemu_util_get_pointer_of_format_string_parameter(char *format_string);

unsigned int seqemu_util_is_n_format(char *s, unsigned int len);
void seqemu_util_adjust_stack_args(unsigned int erase_arg_index, unsigned int number_of_args,target_ulong first_arg);


// feature-006 Checking Control Flow
void seqemu_check_control_flow(CPUArchState *env);

// feature-007 Checking Heap Chunk
void seqemu_check_heap_metadata(CPUArchState *env);

#endif /* SEQEMU_H */
