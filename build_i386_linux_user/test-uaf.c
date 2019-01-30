#include <stdio.h>
#include <stdlib.h>
int main()
{
	char *ptr = (char *)malloc(sizeof(char) * 20);
	fgets(ptr,20,stdin);

	free(ptr);

	fgets(ptr,20,stdin);

	return 0;

}

