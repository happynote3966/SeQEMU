#include <stdio.h>
int main(void){
	char buf[100] = {0};

	fgets(buf,sizeof(buf),stdin);
	printf("%s",buf);
	memset(buf,0x0,sizeof(buf));

	fgets(buf,sizeof(buf),stdin);
	printf("%s",buf);
	memset(buf,0x0,sizeof(buf));

	fgets(buf,sizeof(buf),stdin);
	printf("%s",buf);
	memset(buf,0x0,sizeof(buf));

	return 0;
}

