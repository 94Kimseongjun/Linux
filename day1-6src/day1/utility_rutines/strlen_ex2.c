#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
	char buff[100] = "Korea";
    char *pstr = buff;

	int len;
	len = strlen(buff);
    printf( "strlen(buff) %d \n", len );
	len = strlen(pstr);
    printf( "strlen(pstr) %d \n", len );
	len = strlen("A book");
    printf( "strlen('A buook') %d \n", len );
	len = strlen(&buff[2]);
    printf( "strlen(&buff[2]) %d \n", len ); //
	return 0;
}
