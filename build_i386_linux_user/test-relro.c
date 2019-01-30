#include <stdio.h>

void hacked(char *s){
	printf("[HACKED] %s\n",s);
}

int main()
{
	void *got;
	unsigned int func;
	unsigned int num;
	puts("This is puts function output");
	puts("Please input number(no meaning)");

	scanf("%x",&num);
	
	num = 0x8049844;

	got = (void *)num;
	func = hacked;
	printf("%x %x\n",got,func);


	*(unsigned int *)got = func;

	puts("This is second puts function output");

	return 0;
}

