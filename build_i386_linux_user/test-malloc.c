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

