#include <stdio.h>
#include <string.h>
#include <time.h>
 
int main(void)
{
    time_t now_time;
    struct tm *now_date;
    char buf[100];
    time(&now_time); //현재 시각을 구한다.
 
    now_date = localtime(&now_time);//초 단위 값을 지역 시각(DateTime)을 구한다.
    strcpy(buf,asctime(now_date));//버퍼에 현재 시각을 출력
    puts(buf);    //표준 출력 스트림에 출력
    return 0;
}