/*
 * fork_ex3.c
 * fork한 프로세스에 대한 wait() 테스트
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
  pid = fork();
  if(pid > 0) {                         /* 부모프로세스가 수행하는 부분*/
    printf("[parent] waiting...\n");
    wait(&status);
    printf("[parent] status: %d\n", status);
  }
  else if(pid == 0) {                   /* 자식프로세스가 수행하는 부분*/
    sleep(1);
    printf("[child]  bye!\n");
    exit(1234); //
  }
  else {
    printf("fail to fork child process\n");
  }
  printf("Bye Bye!\n");
  return 0;

}//end-of-main

void cleanupaction(void) {
  printf("Clean-up action\n");
}

void errors(char *msg, int code) {
  perror(msg);
  exit(code);
}
