/*
 * 쉘 ID를 전달해 pid로서 ppid, sid 정보를 얻는다. 
 $ ps
 PID TTY ...
 1234 pts/4 ...

 $ sid_ex 1234 0
 */

#include <sys/types.h>
#include <unistd.h>

main(int argc, char *argv[])
{
    pid_t pid;
    int interval;

    if(argc != 3)
        exit(1);

    pid = atoi(argv[1]);
    interval = atoi(argv[2]);

    printf("shell process...\n");
    printf("process id:%d, group id:%d, session id:%d\n",
        pid, getpgid(pid), getsid(pid));
    printf("current process.. not daemon...\n");
    printf("process id:%d, group id:%d, session id:%d\n",
        getpid(), getpgrp(), getsid(0));

    sleep(interval);
}