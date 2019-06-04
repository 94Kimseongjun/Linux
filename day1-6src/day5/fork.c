#include <sys/types.h>
#include <unistd.h>

static int glob = 6; /* external variable in initialized data */
char buf[] = "a write to stdout\n";

int main(void)
{
    int var; /* automatic variable on the stack */
    pid_t pid;
    var = 88;
    if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1)
    {
        perror("write error");
        return -1;
    }
    printf("before fork\n");

    if ((pid = fork()) < 0)
        perror("fork error"); // child
    else if (pid == 0)
    {
        glob++;
        var++;
    }
    else // parent
        sleep(2);
    printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);
    return 0;
}