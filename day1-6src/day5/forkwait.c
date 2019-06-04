#include <sys/types.h>
#include <unistd.h>

static int glob = 6;

int main(void)
{
    pid_t pid;
    int var = 88;

    if ((pid = fork()) < 0)
    {
        perror("fork error");
        exit(-1);
    }
    else if (pid == 0) // child
    {
        execl("/bin/ls", "ls", "-l", (char *)0);
        exit(0);
    }
    else
    { // parent
        wait(NULL);
        printf("pid = %d, var = %d\n", getpid(), var);
    }
    return 0;
}