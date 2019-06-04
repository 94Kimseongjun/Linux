//------------------------------------------------------------------------
// fork_ex.c
// fork(), exec_() 함수 동작을 이해
//------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

void cleanupaction(void);

int main(int argc, char **argv)
{
  pid_t pid;
  int i;

  for (size_t i = 0; i < 3; i++)
  {
    printf("before fork[%d]\n", i);
    sleep(1);
  }

  // fork
  pid = fork();
  if (pid > 0) /* 부모프로세스가 수행하는 부분*/
  {
    for (size_t i = 0; i < 7; i++)
    {
      printf("parent [%d] i = %d\n", getpid(), i);
      sleep(1);
    }
    atexit(cleanupaction);
  }
  else if (pid == 0) /* 자식프로세스가 수행하는 부분*/
  {
    for (size_t i = 0; i < 5; i++)
    {
      printf("child[%d] i = %d\n", getpid(), i);
      sleep(1);
      // execl("/bin/ls", "ls", "-l", (char *)0);
    }
  }
  else
  {
    printf("fail to fork child process\n");
  }
  return 0;

} //end-of-main

void cleanupaction(void)
{
  printf("PID[%d] Clean-up action\n", getpid());
}
