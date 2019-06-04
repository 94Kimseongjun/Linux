#include <sys/sysinfo.h>

int main()
{
    struct sysinfo info;
    sysinfo(&info);
    printf("load: %d %d %d\n",
           info.loads[0], info.loads[1], info.loads[2]);
    printf("mem : %d %d %d\n",
           info.totalram,
           info.totalram - info.freeram,
           info.freeram);
    return 0;
}