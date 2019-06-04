#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    /*if(argc < 2) {
        printf("Usage: program <strings>");
        exit(0);
    }*/

    if((line = inputLine()) == NULL)
        break;
    
    
	int len;
	len = strlen(argv);
    printf( "argv %s \n", argv );
    printf( "argv %d \n", len );
	return 0;
}


char * inputLine(void)
{
    int c, n;
    static char line[BUFSIZ + 1];
    
    n = 0;
    while((c = getc(stdin)) != '\n') {
        if( c == EOF ) return(NULL);
        if( n < BUFSIZ) line(n++) = c;
    }
    line[n] = '\0';
    return(line);
}

void outputLine(char *line) {
    char *p;
    for (p = line; *p != '\0'; p++)
        putc(*p, stdout);
    putc('\n', stdout);
}
