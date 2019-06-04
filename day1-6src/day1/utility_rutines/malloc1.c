#include <stdio.h>
#include <stdlib.h>

void main()
{
	char *s1;
	s1 = malloc( sizeof(char) * 100);

	printf("Please input:");
	scanf("%s", s1);

	printf("%s\n", s1);

	free(s1);
}
