#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char s1[] = "This is test for strtok, tokenizing string";
	
	char *ptr;
	ptr = strtok(s1, " ");
	
	//while( ptr = strtok(NULL, " "))
//		printf("%s\n", ptr);
	while( ptr =! NULL )
		printf("%s\n", ptr);
		ptr = strtok(NULL, " ");

	return 0;
}
