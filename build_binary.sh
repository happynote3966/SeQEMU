#!/bin/sh

mkdir build_i386_linux_user
cd build_i386_linux_user


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

gcc -o test-dangerous-disable-sec -m32 -fno-PIE -z execstack -fno-stack-protector -fno-PIE -Wl,-z,norelro test-dangerous.c
gcc -o test-dangerous-no-execstack -m32 -fno-PIE -fno-stack-protector -Wl,-z,norelro test-dangerous.c
gcc -o test-dangerous-stack-protector -m32 -fno-PIE -z execstack -fstack-protector -Wl,-z,norelro test-dangerous.c
gcc -o test-dangerous-relro-lazy -m32 -fno-PIE -z execstack -fno-stack-protector -Wl,-z,relro,-z,lazy test-dangerous.c
gcc -o test-dangerous-relro-now -m32 -fno-PIE -z execstack -fno-stack-protector -Wl,-z,relro,-z,now test-dangerous.c
gcc -o test-dangerous-pie -m32 -fPIE -pie -z execstack -fno-stack-protector -Wl,-z,norelro test-dangerous.c

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

cat <<EOF > test-malloc.c
#include <stdio.h>
#include <malloc.h>

int main(void){
	char *ptr;

	ptr = (char *)malloc(sizeof(char) * 20);
	printf("[USER] Pointer = 0x%p\n",ptr);
	fgets(ptr,20,stdin);
	printf("%s\n",ptr);
	free(ptr);
	free(ptr);

	return 0;
}

EOF

gcc -o test-malloc -m32 test-malloc.c

