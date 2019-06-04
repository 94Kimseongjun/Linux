#include <sys/utsname.h>
#include <sys/param.h>
#include <unistd.h>

int main()
{
    struct utsname name;
    char hostname[1024];

    uname(&name);
    printf("sysname : %s\n", name.sysname);
    printf("nodename : %s\n", name.nodename);
    printf("release : %s\n", name.release);
    printf("version : %s\n", name.version);
    printf("machine : %s\n", name.machine);
    gethostname(hostname, MAXHOSTNAMELEN);
    printf("hostname : %s\n", hostname);
}