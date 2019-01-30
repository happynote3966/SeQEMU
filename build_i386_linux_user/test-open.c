#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(void){
	int fd = open("flag.txt",O_RDONLY);
	printf("%d\n",open);
	return 0;
}

