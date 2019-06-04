/* 4장 / char.c */
#include <stdio.h>

int main(int argc, char **argv)
{
    FILE *in, *out;
    char line[BUFSIZ];
    if (argc != 3)
    {
        fprintf(stderr, "Usage: append-line file1 file2\n");
        return -1;
    }

    if ((in = fopen(argv[1], "r")) == NULL)
    {
        perror(argv[1]);
        return -1;
    }

    if ((out = fopen(argv[2], "a")) == NULL)
    {
        perror(argv[2]);
        return -1;
    }
    while (fgets(line, sizeof(line), in) != NULL)
        fputs(line, out);
    fclose(out);
    fclose(in);

    return 0;
}