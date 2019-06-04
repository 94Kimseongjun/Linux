#include<stdio.h>

void main()
{
	char buff1[10];
	char buff2[10];
	char buff[100];

	printf("Please input two buffer:");
	scanf("%s %s", buff1, buff2);

	strcpy(buff, buff1);

	printf("buff(%d),buff2(%d)\n", strlen(buff), strlen(buff2));
	printf("buff vs buff2 : %d\n", strcmp(buff, buff2));

	char* t = strcat(buff, buff2);
	printf("Result buff: %s\n", t);
}
