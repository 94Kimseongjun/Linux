#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

int main(int argc, char **argv)
{
    char buf[255];
    if (chdir(argv[1]) == -1)
    {
        perror("error");
        return -1;
    }

    if (getcwd(buf, PATH_MAX) == NULL)
        perror("error getcwd");
    else
        printf("현재 작업 디렉토리 : %s\n", buf);

    return 0;
}