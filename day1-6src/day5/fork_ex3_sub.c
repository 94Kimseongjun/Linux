/*
 * fork_ex3_sub.c
 * fork_ex3에서 execl로 실행할 프로레스
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
  printf("[fork_ex3_sub]  PPID:%d, PID:%d\n", getppid(), getpid());
  return 0;

}//end-of-main
