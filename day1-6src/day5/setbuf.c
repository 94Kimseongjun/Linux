#include <sys/types.h>
#include <stdio.h>

static void charatatime(char *);

int main(void)
{
    pid_t pid;
    if ((pid = fork()) < 0)
    {
        perror("fork error");
        return -1;
    }
    else if (pid == 0)
    {
        charatatime("output from child\n");
    }
    else
    {
        charatatime("output from parent\n");
    }
    return 0;
}
static void charatatime(char *str)
{
    char *ptr;

    int c;
    setbuf(stdout, NULL); /* set unbuffered */
    for (ptr = str; c = *ptr++;)
        putc(c, stdout);
}