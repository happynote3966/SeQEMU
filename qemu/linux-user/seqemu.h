#ifndef SEQEMU_H
#define SEQEMU_H

#include "qemu/osdep.h"
#include "qemu.h"


extern unsigned long seqemu_guest_base;
extern struct image_info seqemu_image_info;

void seqemu_print_debug(void);
void seqemu_save_guest_base(unsigned long base);
void seqemu_print_guest_base(void);
void seqemu_save_image_info(struct image_info *info);
void seqemu_print_image_info(void);

#endif /* SEQEMU_H */
