/*
$ ls -l test.txt
-rw-r--r-- 1 qkboo qkboo 4 May 30 12:42 test.txt
$ sudo ./getpwname
1000 33
4$ ls -l test.txt
-rw-r--r-- 1 qkboo www-data 4 May 30 12:42 test.txt
 */
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>

int main()
{
    struct passwd *u_info;
    struct group *g_info;

    u_info = getpwnam("qkboo");
    g_info = getgrnam("www-data");

    printf("%d %d\n", u_info->pw_uid, g_info->gr_gid);

    chown("test.txt", u_info->pw_uid, g_info->gr_gid);
    return 0;
}
