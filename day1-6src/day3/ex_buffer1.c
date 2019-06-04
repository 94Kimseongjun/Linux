#include <stdio.h>
#include <unistd.h>

int main()
{
    putchar('e');
    sleep(1);
    fputc('H', stderr);

    putchar('h');
    sleep(1);
    fputc('e', stderr);

    putchar('\n');
    sleep(1);
    fputc('l', stderr);

    putchar('p');
    sleep(1);
    fputc('l', stderr);

    putchar('u');
    sleep(1);
    fputc('o', stderr);

    putchar('b');
    sleep(1);
    fputc('!', stderr);

    putchar('\n');
    sleep(1);
    fputc('\n', stderr);

    return 0;
}