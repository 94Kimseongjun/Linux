/* 동작 이상함... */

#include <time.h>

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    time_t tm_st;
    time_t tm_nd;

    int tm_day, tm_hour, tm_min, tm_sec;
    double d_diff;
    struct tm user_time;

    user_time.tm_year = 2007 - 1900;
    user_time.tm_mon = 7; // 2 - 1
    user_time.tm_mday = 1;
    user_time.tm_hour = 10;
    user_time.tm_min = 12;
    user_time.tm_sec = 50;
    user_time.tm_isdst = 0; //섬머타임 사용 안함

    printf("%d\n", mktime(&user_time));

    time(&tm_nd);

    d_diff = difftime(tm_nd, tm_st);
    tm_day = d_diff / (60 * 60 * 24);
    d_diff = d_diff - (tm_day * 60 * 60 * 24);
    tm_hour = d_diff / (60 * 60);
    tm_min = d_diff / 60;
    d_diff = d_diff - (tm_min * 60);
    tm_sec = d_diff;

    printf("%d일 %d시 %d분 %d\n", tm_day, tm_hour, tm_min, tm_sec);
    return 0;
}