#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>

void stprintf_time(time_t, char *);

int main()
{
    int i;
    time_t the_time;
    char buffer[255];
    time(&the_time);
    printf("현재 시간은 %ld 초\n", the_time);
    stprintf_time(the_time, buffer);
    printf("%s\n", buffer);
    return 0;
}

void stprintf_time(time_t org_time, char *time_str)
{
    struct tm *tm_ptr;
    tm_ptr = localtime(&org_time);
    sprintf(time_str, "%d/%d/%d %d:%d:%d",
            tm_ptr->tm_year + 1900, tm_ptr->tm_mon + 1, tm_ptr->tm_mday, tm_ptr->tm_hour, tm_ptr->tm_min, tm_ptr->tm_sec);
}
