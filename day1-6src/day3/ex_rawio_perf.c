/**********************************************************************
* ex_performance.c                                                    *
* exmple source – test I/O performance         
* http://ehpub.co.kr/리눅스-시스템-프로그래밍-5-4-raw-입출력과-표준-입출력/       *
**********************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

void UsingRawIO();
void UsingBufferedIO(int bsize);
int main()
{
    clock_t st, et;

    st = clock();
    UsingRawIO();
    et = clock();
    printf("RAW I/O:%u\n", (unsigned)(et - st));

    int i = 0;
    for (i = 0; i < 8000; i += 500)
    {
        st = clock();
        UsingBufferedIO(i);
        et = clock();
        printf("Buffered I/O bsize<%d> :%u\n", i, (unsigned)(et - st));
    }

    return 0;
}
void UsingRawIO()
{
    int fd = open("test", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    int i = 0;
    for (i = 0; i < 100000; i++)
    {
        write(fd, &i, 1);
    }
    close(fd);
    remove("test");
}
void UsingBufferedIO(int bsize)
{
    char buf[8000];
    FILE *fp = fopen("test", "w");
    setvbuf(fp, buf, _IOFBF, bsize);
    int i = 0;
    char data = 'a';
    for (i = 0; i < 100000; i++)
    {
        fwrite(&data, 1, 1, fp);
    }
    fclose(fp);
}
