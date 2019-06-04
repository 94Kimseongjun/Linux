#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {

	if( argc < 2) {
		print("Usage: strlen <STRINGS>");
		exit(1);
	}

	int len;
	len = strlen(argv);
    printf( "argv: %s \n", argv );
    printf( "strlen(argv) %d \n", len );
	return 0;
}
