#!/bin/sh

mkdir build_i386_linux_user
cd build_i386_linux_user

../qemu/configure --target-list=i386-linux-user --enable-debug-info --enable-debug --enable-debug-tcg

make -j2

cat <<EOF > test-all.c
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

gcc -o test-all -m32 test-all.c


cat <<EOF > test-dangerous.c
#include <stdio.h>
int main(void){
	char buf[100];
	gets(buf);
	printf(buf);
	return 0;
}

EOF

gcc -o test-dangerous -m32 test-dangerous.c


cat <<EOF > test-format.c
#include <stdio.h>
char format_string[] = "formatstring %n %n %n\n";
char print_string[] = "print_string\n";
int main(void){
	int i = 100;
	printf(format_string,i,i,print_string);
	return 0;
}

EOF

gcc -o test-format -m32 test-format.c

cat <<EOF > test-buffer.c
#include <stdio.h>

void func(void){
	char buf[10];
	fgets(buf,30,stdin);
	puts(buf);
}

int main(void){
	func();
	printf("OK! Control Flow is protected!\n");
	return 0;
}

EOF

gcc -o test-buffer -m32 test-buffer.c -fno-stack-protector

cp -R ../resources ./
