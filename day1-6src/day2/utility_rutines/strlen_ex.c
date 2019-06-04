#include <stdio.h>

int string_length(char* pstr) {/* 반환값은 int형 */

	int len = 0;
       	while(*pstr++)
	      len++;
	return len;
}

int main(int argc, char** argv) {
	int len;
	len = string_length("korea");
       	printf( "길이: %d \n", len );
	return 0;
}
