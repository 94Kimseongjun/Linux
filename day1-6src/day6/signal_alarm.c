#include <stdio.h>
#include <unistd.h>
#include <signal.h>

static void sig_handler(int);

int counter = 0;

int main(void)
{
    if (signal(SIGALRM, sig_handler) == SIG_ERR)
    {
        perror("can't catch SIGALRM");
        return -1;
    }
    // alarm(1);
    while(1)
        ;
        
    // for (;;)        pause();

    return 0;
}

void sig_handler(int signo) /* argument is signal number */
{
    printf("Alarm count: %d !\n", counter++);
    alarm(1);
}