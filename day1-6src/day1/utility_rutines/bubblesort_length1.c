#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NSTRINGS 16    /* max. number of strings */
#define MAXLENGTH 1024 /* max. length of one string */

char *inputLine(void);

int main(int argc, char **argv)
{
    int n, nstrings;
    char *p, *q, *line;
    char *strptrs[NSTRINGS];
    char strings[NSTRINGS][MAXLENGTH];

    for (nstrings = 0; nstrings < NSTRINGS; nstrings++)
    {
        if ((line = inputLine()) == NULL)
            break;
        for (p = line, q = strings[nstrings]; *p != '\0'; p++, q++)
            *q = *p;
        *q = '\0';
        strptrs[nstrings] = strings[nstrings];
    }
    
    printf("strptrs : %s\n", *strptrs);
    printf("strings : %s\n", *strings);

    return 0;
}

char *inputLine(void)
{
    int c, n;
    static char line[BUFSIZ + 1];
    n = 0;
    while ((c = getc(stdin)) != '\n')
    {
        if (c == EOF)
            return (NULL);
        if (n < BUFSIZ)
            line[n++] = c;
    }
    line[n] = '\0';
    return (line);
}

