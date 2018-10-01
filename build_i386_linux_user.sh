#!/bin/sh

mkdir build_i386_linux_user
cd build_i386_linux_user

../qemu/configure --target-list=i386-linux-user --enable-debug-info --enable-debug --enable-debug-tcg

make -j2

cat <<EOF > test.c
#include <stdio.h>
#include <string.h>
#include <malloc.h>
int main(void){
	int i;
	for(i = 0; i < 100; i++){
		printf("[%d] Hello world!\n",i);
	}
	printf("Exited!\n");

	char *buf = (char *)malloc(sizeof(char) * 10);
	gets(buf);
	memcpy(buf,buf,10);
	free(buf);

	return 0;
}

EOF

gcc -o test -m32 test.c
