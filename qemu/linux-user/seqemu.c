#include "seqemu.h"
//#include "qemu.h"	// image_info
//#include "include/exec/user/abitypes.h" // abi_ulong
//#include <stdio.h>	// fprintf

unsigned long seqemu_guest_base;
struct image_info seqemu_image_info;


void seqemu_print_debug(void){
    fprintf(stderr,"SEQEMU DEBUGGING!\n");
}

void seqemu_save_guest_base(unsigned long base){
    seqemu_guest_base = base;
}

void seqemu_print_guest_base(void){
    fprintf(stderr,"[DEBUG] GUEST BASE = %lx\n",seqemu_guest_base);
}


void seqemu_save_image_info(struct image_info *info){

	seqemu_image_info.start_brk = info->start_brk;
	seqemu_image_info.end_code = info->end_code;
	seqemu_image_info.start_code = info->start_code;
	seqemu_image_info.start_data = info->start_data;
	seqemu_image_info.end_data = info->end_data;
	seqemu_image_info.start_stack = info->start_stack;
	seqemu_image_info.brk = info->brk;
	seqemu_image_info.entry = info->entry;
	seqemu_image_info.arg_start = info->arg_start;
	seqemu_image_info.arg_end = info->arg_end;
	seqemu_image_info.saved_auxv = info->saved_auxv;
}

void seqemu_print_image_info(void){
	unsigned long b = seqemu_guest_base;
	fprintf(stderr,"start_brk   =0x%lx [0x%x]\n",seqemu_image_info.start_brk + b, seqemu_image_info.start_brk);
	fprintf(stderr,"end_code    =0x%lx [0x%x]\n",seqemu_image_info.end_code + b, seqemu_image_info.end_code);
	fprintf(stderr,"start_code  =0x%lx [0x%x]\n",seqemu_image_info.start_code + b, seqemu_image_info.start_code);
	fprintf(stderr,"start_data  =0x%lx [0x%x]\n",seqemu_image_info.start_data + b, seqemu_image_info.start_data);
	fprintf(stderr,"end_data    =0x%lx [0x%x]\n",seqemu_image_info.end_data + b, seqemu_image_info.end_data);
	fprintf(stderr,"start_stack =0x%lx [0x%x]\n",seqemu_image_info.start_stack + b, seqemu_image_info.start_stack);
	fprintf(stderr,"brk         =0x%lx [0x%x]\n",seqemu_image_info.brk + b, seqemu_image_info.brk);
	fprintf(stderr,"entry       =0x%lx [0x%x]\n",seqemu_image_info.entry + b, seqemu_image_info.entry);
	fprintf(stderr,"argv_start  =0x%lx [0x%x]\n",seqemu_image_info.arg_start + b, seqemu_image_info.arg_start);
	fprintf(stderr,"env_start   =0x%lx [0x%x]\n",seqemu_image_info.arg_end + (abi_ulong)sizeof(abi_ulong) + b, seqemu_image_info.arg_end + (abi_ulong)sizeof(abi_ulong));
	fprintf(stderr,"auxv_start  =0x%lx [0x%x]\n",seqemu_image_info.saved_auxv + b, seqemu_image_info.saved_auxv);
}
