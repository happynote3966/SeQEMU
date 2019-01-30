#include <stdio.h>

char format1[] = "%x %n %x";
char format2[] = "%d %3$n %x";

int main(void){
	puts(format1);
	printf(format1,1,2,3);
	printf("\n\n");

	puts(format2);
	printf(format2,1,2,3);
	printf("\n");

	return 0;
}
