#include <stdio.h>
#include <unistd.h>

int main()
{
    int c, number = 0;
    char op;
    FILE *fp;
    if ((fp = fopen("test.txt", "r")) == NULL)
    {
        perror("File open error");
        return -1;
    }
    while (!feof(fp))
    {
        while ((c = fgetc(fp)) != EOF && isdigit(c))
            number = 10 * number + c - '0';
        if (c == '\n')
            continue;
        fprintf(stdout, " Operand => %d\n", number);
        number = 0;
        if (c != EOF)
        {
            ungetc(c, fp);
            op = fgetc(fp);
            fprintf(stdout, "Operator => %c\n", op);
        }
    }
    return 0;
}