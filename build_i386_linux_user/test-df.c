#include <stdio.h>
#include <malloc.h>

int main(void){
	char *ptr;

	ptr = (char *)malloc(sizeof(char) * 20);
	printf("Pointer = %p\n",ptr);
	printf("Input message : ");
	fgets(ptr,20,stdin);
	printf("%s\nLet's Double free!\n",ptr);

	free(ptr);
	free(ptr);

	printf("Double Free is End!\n");

	return 0;
}

