#include <stdio.h>
#include <fcntl.h>

int main()
{
    char *fname = "test.txt";
    int fd;
    if ((fd = creat(fname, 0666)) < 0)
    {
        perror("creat( )");
        return -1;
    }
    printf("First printf is on the screen.");
    fflush(stdout);
    dup2(fd, stdout); /* 1 == stdout */
    printf("Second printf is in this file.\n");
    return 0;
}
