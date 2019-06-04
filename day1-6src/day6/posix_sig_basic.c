/* vim: set ts=4 sw=4: */
/* Filename    : posix_sig_basic.c
 * Description : simple signal model
 * Author      : SunYoung Kim <sunyzero@gmail.com>
 * Notes       : sigaction & signal mask
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

void sa_handler_usr(int signum);

int main()
{
    struct sigaction sa_usr1;
    struct sigaction sa_usr2;

    memset(&sa_usr1, 0, sizeof(struct sigaction));
    sa_usr1.sa_handler = sa_handler_usr;
    sigfillset(&sa_usr1.sa_mask);

    memset(&sa_usr2, 0, sizeof(struct sigaction));
    sa_usr2.sa_handler = sa_handler_usr;
    //sa_usr2.sa_flags = SA_NODEFER; // SA_NODEEP 적용후 같은 시그널에도 인터럽트
    sigemptyset(&sa_usr2.sa_mask);

    // SIGUSR1, SIGUSR2 로 핸들러를 다루어 본다.
    sigaction(SIGUSR1, &sa_usr1, NULL); // filled sa_mask
    sigaction(SIGUSR2, &sa_usr2, NULL); // empty sa_mask

    printf("[MAIN] SIGNAL-Handler installed, pid(%d)\n", getpid());
    for (;;)
    {
        pause();
        printf("[MAIN] Recv SIGNAL...\n");
    }
    return EXIT_SUCCESS;
}

void sa_handler_usr(int signum)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("\tSignal(%s):%d sec.\n", signum == SIGUSR1 ? "USR1" : "USR2", i);
        sleep(1);
    }
}
