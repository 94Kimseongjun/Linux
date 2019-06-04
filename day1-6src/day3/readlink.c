#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    char buf[300];
    int n;

    n = readlink('/usr/lib/libgjs.so.0.0.0', buf, 300);
    buf[n] = '\0';

    printf("%s\n", buf);
    return 0;
}