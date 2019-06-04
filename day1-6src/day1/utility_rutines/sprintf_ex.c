#include<stdio.h>

void main()
{
	char buff1[10];
	char buff2[10];
	char buff[100];

	printf("Please input two buffer:");
	scanf("%s %s", buff1, buff2);
	
	sprintf(buff, "Total input: %s %s", buff1, buff2);
	//strcpy(buff, buff1);
	printf("%s\n", buff);

}
