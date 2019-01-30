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

