//------------------------------------------------------------------------
// fork_ex1.c
// fork(), exec_() 함수 동작을 이해
//------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

void cleanupaction(void);
void child_start();

int main(int argc, char **argv)
{
    pid_t pid;
    int status;

    puts("\t parent process started.....!\n");

    // 1. fork()
    if ((pid = fork()) > 0) /* 부모프로세스가 수행하는 부분*/
    {
        printf("\n\t** parent : [my pid: %d] my child pid = %d\n",
               getpid(), pid);
        // 클린업 콜백
        atexit(cleanupaction);
    }
    else if (pid == 0) /* 자식프로세스가 수행하는 부분*/
    {
        child_start();
    }
    else
    {
        err_say("fail to fork child process\n", -1);
    }
    return 0;

} //end-of-main

void cleanupaction(void)
{
    printf("Clean-up action\n");
}

void child_start()
{
    puts("\t child process start...");
    printf("\t** child : [my pid: %d] my parent pid = %d\n", getpid(), getppid());
    printf("\n\t** exec() 함수로 ls 명령을 수행합니다\n");
    execlp("ls", "ls", NULL);

    // 아래가 실행된다면 exec 함수에서 에러가 난 경우임
    perror("exec error at child: ");
    exit(0);
}
