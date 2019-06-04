#include <time.h>

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    struct tm tm_ptr;
    time_t the_time;
    int i;

    // 2002년 2월 8일 23시 50분 50초 에 대한
    // Unix Time 를 되돌려준다.
    tm_ptr.tm_year = 102; // 2002 - 1900
    tm_ptr.tm_mon = 1;    // 2 - 1
    tm_ptr.tm_mday = 8;
    tm_ptr.tm_hour = 23;
    tm_ptr.tm_min = 50;
    tm_ptr.tm_sec = 50;

    printf("%d\n", mktime(&tm_ptr));
}