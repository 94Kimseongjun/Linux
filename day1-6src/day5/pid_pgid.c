/* day5/pid_pgid.c
$ pig_pgid
PID : 2297
PGRP : 2297
PGID(0) : 2297
PGID(2287) : 2285
*/
#include <unistd.h>
#include <stdio.h>
  
int main(void) {
    printf("PID : %d\n", (int)getpid());
    printf("PGRP : %d\n", (int)getpgrp());
    printf("PGID(0) : %d\n", (int)getpgid(0));
    printf("PGID(2287) : %d\n", (int)getpgid(2287));

    return 0;
}