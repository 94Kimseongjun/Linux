/*
 * fork_ex4.c
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
  pid_t pid1, pid2;
  int status;

  pid1 = pid2 = -1;

  // fork
  pid1 = fork();
  if(pid1 > 0) {
    pid2 = fork();
  }

  if( pid1 > 0 && pid2 > 0) {        /* 부모프로세스가 수행하는 부분*/
    waitpid(pid2, &status, 0);
    printf("[parent] child2 exit: %d\n", status);
    waitpid(pid1, &status, 0);
    printf("[parent] child1 exit: %d\n", status);
  }
  else if( pid1 == 0 && pid2 == -1 ) { /* child1 */
    sleep(1);
    exit(1);
  }
  else if( pid1 > 0 && pid2 == 0) {    /* child2 */
    sleep(2);
    exit(2);
  }
  else {
    printf("Failed to fork\n");
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
