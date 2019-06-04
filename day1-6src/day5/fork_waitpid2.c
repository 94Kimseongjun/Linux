/*
 * fork_ex5.c
 * waitpid()에서 WNOHANG 옵션 사용
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

  if ((pid = fork()) > 0)
  { /* 부모프로세스가 수행하는 부분*/
    while (!waitpid(pid, &status, WNOHANG))
    {
      printf("[parent] status: %d\n", status++);
      sleep(1);
    }
    printf("[parent] child exit: %d\n", status);
  }
  else if (pid == 0)
  { /* child1 */
    sleep(5);
    printf("bye child!\n");
    exit(1);
  }
  else
  {
    printf("Failed to fork\n");
  }

  printf("Bye Bye!\n");
  return 0;
} //end-of-main

void cleanupaction(void)
{
  printf("Clean-up action\n");
}

void errors(char *msg, int code)
{
  perror(msg);
  exit(code);
}
