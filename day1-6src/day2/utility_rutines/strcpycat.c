#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {

	if( argc < 3) {
		printf("Usage: strlen <STR1> <STR2>\n");
		exit(1);
	}

	char* str1;
	char* str2;

	strcpy(str1, argv[1]);
	strcpy(str2, argv[2]);
	
    printf( "argv: %s %s\n", str1, str2 );
	return 0;
}
