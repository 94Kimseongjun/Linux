#include<stdio.h>

void main()
{
	char buff[100];
	char* pstr = "phone";
	strcpy(buff, pstr);

	printf("pstr: %s\n", pstr);
	printf("buff: %s\n", buff);

	printf("buff(%d), pstr(%d)\n", strlen(buff), strlen(pstr));

	printf("buff vs pstr : %d\n", strncmp(buff, pstr, 4));	
}
