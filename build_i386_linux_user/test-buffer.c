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

