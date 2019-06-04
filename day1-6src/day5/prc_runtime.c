/***********************************************************************
 * 프로세스 수행 시간 구하기, times 함수와 struct tms 형식 이용.
 * 5개의 자식 프로세스를 생성하여 표준 출력에 문자를 반복 출력하는 구문으로
 * CPU 시간을 측정하는 예제 코드입니다.
 **********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/times.h>

void do_in_child(int seq, int rval);

int main()
{
    srand((unsigned)time(0));

    int i = 0;
    for (i = 0; i < 5; i++)
    {
        do_in_child(i + 1, rand() % 10);
    }

    int rval = 0;
    pid_t cpid = 0;
    while (i > 0)
    {
        cpid = wait(&rval);
        printf("cpid:%d exit status:%#x\n", cpid, rval);
        i--;
    }

    for (i = 0; i < 10000000; i++)
    {
        putchar('-');
    }

    struct tms buf;
    times(&buf);

    printf("USER CPU time:%d \n", buf.tms_utime);
    printf("SYSTEM CPU time:%d \n", buf.tms_stime);
    printf("Children's USER CPU time:%d \n", buf.tms_cutime);
    printf("Children's SYSTEM CPU time:%d \n", buf.tms_cstime);
    return 0;
}
void do_in_child(int seq, int rval)
{
    pid_t cpid = fork();

    if (cpid == -1)
    {
        perror("error fork");
        return;
    }

    if (cpid > 0)
    {
        printf("fork child pid:%u\n", cpid);
    }
    else
    {
        printf("pid:%d sleep %d seconds\n", getpid(), rval);

        int i = 0;
        for (i = 0; i < 10000000; i++)
        {
            putchar('.');
        }

        exit(seq);
    }
}