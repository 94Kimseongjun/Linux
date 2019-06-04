#include <sys/types.h>

static int glob = 6;

int main()
{

    int var; /* automatic variable on the stack */
    pid_t pid;
    var = 88;
    printf("before vfork\n"); /* we don't flush stdio */

    if ((pid = vfork()) < 0)
    {
        perror("vfork error");
        return -1;
    }
    else if (pid == 0) /* child */
    {
        glob++; /* modify parent's variables */
        var++;
        printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);
        _exit(0); /* child terminates */
    }
    else
    {
        printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);
    }
    /* parent */
    // printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);
    return 0;
}