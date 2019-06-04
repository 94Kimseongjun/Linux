#include <stdio.h>
#include <stdlib.h>

int sum(int i);

int main()
{
	printf("%d\n", sum(10));
	return 0;
}

int sum(int i)
{
	return i + sum(i-1);
}
