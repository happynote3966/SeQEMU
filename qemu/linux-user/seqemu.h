#ifndef SEQEMU_H
#define SEQEMU_H

#include "qemu/osdep.h"
#include "qemu.h"

#include <stdint.h>
#include <regex.h>
extern unsigned long seqemu_guest_base;
extern struct image_info seqemu_image_info;
// feature-011 add options of security feature
extern int seqemu_disable_dangerous;
extern int seqemu_disable_format;
extern int seqemu_disable_buffer;
extern int seqemu_disable_heap;

void seqemu_print_debug(void);
void seqemu_save_guest_base(unsigned long base);
void seqemu_print_guest_base(void);
void seqemu_save_image_info(struct image_info *info);
void seqemu_print_image_info(void);

// feature-011 add options of security feature
// feature-012 Checking System Call
void handle_arg_disable_dangerous(const char *arg);
void handle_arg_disable_format(const char *arg);
void handle_arg_disable_buffer(const char *arg);
void handle_arg_disable_heap(const char *arg);
void handle_arg_disable_syscall(const char *arg);
// feature-014 Adding function honey pot
void handle_arg_disable_honeypot(const char *arg);
void handle_arg_disable_all(const char *arg);
void handle_arg_seqemu(const char *arg);

// feature-002 Filtering the Dangerous Functions
// feature-010 Random output of Characters
// feature-015 Function List from Files
void seqemu_read_elf(int fd);
void seqemu_elf_open_func_list(void);
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
#define SEQEMU_FUNC_TYPE_LIBC_START_MAIN 0x6

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

// feature-012 Checking System Call
void seqemu_check_entry_point(CPUArchState *env);
void seqemu_check_libc_start_main(CPUArchState *env);
void seqemu_check_system_call(CPUArchState *env);
// feature-013 Adding System Call Filtering List
void seqemu_load_syscall_filtering_list(void);

typedef struct{
	unsigned int syscall_number;
	unsigned int has_arg;
	unsigned int arg_index;
	unsigned int arg_type;//0 ... num, 1 ... str
	union{
		char *str;
		int num;
	}u;
}Seqemu_syscall_filtering_list;

// feature-014 Adding Function Honey Pot
void seqemu_function_honey_pot(CPUArchState *env);
void seqemu_open_honeypot_logfile(void);
void seqemu_honeypot_open_function_list(void);
void seqemu_honeypot_write_log(char *func, char *log);

typedef struct{
	char *name;
	unsigned int arg_index;
}Seqemu_honeypot_function_list;

// feature-016 Add self NX

void seqemu_self_nx(CPUArchState *env);

#endif /* SEQEMU_H */
