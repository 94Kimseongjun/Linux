/*
 * fork_ex3.c
 * fork한 프로세스의 PID, PPID 정보와
 * execl한 프로세스의 PID< PPID
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void errors(char *msg, int code);
void cleanupaction(void);

int main(int argc, char **argv)
{
  pid_t pid;
  int status;

  // fork
  if( (pid = fork()) > 0) {                         /* 부모프로세스가 수행하는 부분*/
    printf("[fork_ex3]  PPID:%d, PID:%d\n", getppid(), getpid());
    sleep(1);
  }
  else if(pid == 0) {                   /* 자식프로세스가 수행하는 부분*/
    printf("[fork_ex3]  PPID:%d, PID:%d\n", getppid(), getpid());
    execl("fork_ex3_sub", "fork_ex3_sub", (char* )0);
  }
  else {
    printf("fail to fork child process\n");
  }
  return 0;

}//end-of-main

void cleanupaction(void) {
  printf("Clean-up action\n");
}

void errors(char *msg, int code) {
  perror(msg);
  exit(code);
}
