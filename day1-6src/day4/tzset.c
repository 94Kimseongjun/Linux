#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/timeb.h>

int main()
{
    char *tzstr = "TZ=PST8PDT";
    struct timeb t;

    putenv(tzstr);
    tzset();
    ftime(&t);

    printf("Seconds since 1/1/1970 GMT: %ld\n", t.time);
    printf("Thousandths of a second: %d\n", t.millitm);
    printf("Difference between local time and GMT: %d\n", t.timezone);
    printf("Daylight savings in effect (1) not (0): %d\n", t.dstflag);

    return 0;
}
