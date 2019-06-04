#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {

	if( argc < 3) {
		printf("Usage: strlen <STR1> <STR2>\n");
		exit(1);
	}

	
    printf( "argv: %s %s\n", argv[1], argv[2] );
	printf( "compare: %d\n", strcmp(argv[1], argv[2]));
	return 0;
}
