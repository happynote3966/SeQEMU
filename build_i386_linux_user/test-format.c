#include <stdio.h>
char format_string[] = "formatstring %n %x %x\n";
char print_string[] = "print_string\n";
int main(void){
	int i = 100;
	printf(format_string,1,2,3);
	return 0;
}

