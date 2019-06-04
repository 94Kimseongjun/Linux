/*
 * 프로세스에서 setsid()를 호출해 새로운 세션 리더가 되어 데몬 프로세스가 된다.
 $ ./set_sid
 ...
 $ ps -ef |grep set_sid

 * 터미널 연결을 끊고 다시 접속해 데몬 프로세스가 유지 된느지 확인한다.
 * 
 */

#include <sys/types.h>
#include <unistd.h>

main()
{
    pid_t pid;

    if((pid = fork()) > 0)
    {
        sleep(1);
        exit(1);
    }
    else if(pid == 0)
    {
        printf("old session id: %d\n", getsid(0));
        printf("new session id: %d\n", setsid());
        sleep(600);
    }
}
