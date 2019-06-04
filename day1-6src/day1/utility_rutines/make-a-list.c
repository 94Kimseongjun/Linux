#include <stdio.h>
#include <string.h>

void outputLine(char *);
char *inputLine(void);

int main(int argc, char **argv)
{
    int len;
    char *line;
    char list[1024];
    len = sizeof(list) - 2;
    list[0] = '\0';
    while ((line = inputLine()) != NULL)
    {
        len += strlen(line) + 2;
        if (len >= sizeof(list))
        {
            if (list[0] != '\0')
                outputLine(list);
            strcpy(list, line);
            len = strlen(line);
        }
        else
        {
            strcat(list, ", ");
            strcat(list, line);
        }
    }
    if (list[0] != '\0')
        outputLine(list);
    return 0;
}

/* second */
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

void outputLine(char *line)
{
    char *p;
    for (p = line; *p != '\0'; p++)
        putc(*p, stdout);
    putc('\n', stdout);
}