#include <errno.h>
#include <stdio.h>
#include <unistd.h>

static void pr_sysconf(char *, int);
static void pr_pathconf(char *, char *, int);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "usage: a.out <dirname>\n");
        return -1;
    }
    pr_sysconf("ARG_MAX =", _SC_ARG_MAX);
    pr_sysconf("CHILD_MAX =", _SC_CHILD_MAX);
    pr_sysconf("clock ticks/second =", _SC_CLK_TCK);
    pr_sysconf("NGROUPS_MAX =", _SC_NGROUPS_MAX);
    pr_sysconf("OPEN_MAX =", _SC_OPEN_MAX);

#ifdef _SC_STREAM_MAX
    pr_sysconf("STREAM_MAX=", _SC_STREAM_MAX);
#endif
#ifdef _SC_TZNAME_MAX
    pr_sysconf("TZNAME_MAX =", _SC_TZNAME_MAX);
#endif
    pr_sysconf("_POSIX_JOB_CONTROL =", _SC_JOB_CONTROL);
    pr_sysconf("_POSIX_SAVED_IDS =", _SC_SAVED_IDS);
    pr_sysconf("_POSIX_VERSION =", _SC_VERSION);

    pr_pathconf("MAX_CANON =", "/dev/tty", _PC_MAX_CANON);
    pr_pathconf("MAX_INPUT =", "/dev/tty", _PC_MAX_INPUT);
    pr_pathconf("_POSIX_VDISABLE =", "/dev/tty", _PC_VDISABLE);
    pr_pathconf("LINK_MAX =", argv[1], _PC_LINK_MAX);
    pr_pathconf("NAME_MAX =", argv[1], _PC_NAME_MAX);
    pr_pathconf("PATH_MAX =", argv[1], _PC_PATH_MAX);

    pr_pathconf("_POSIX_CHOWN_RESTRICTED =", argv[1], _PC_CHOWN_RESTRICTED);

    // 소켓 사이즈
    printf("MAX socket size: %d\n", getdtablesize());
    return 0;
}

static void pr_sysconf(char *mesg, int name)
{
    long val;
    fputs(mesg, stdout);
    errno = 0;
    if ((val = sysconf(name)) < 0)
    {
        if (errno != 0)
        {
            fprintf(stderr, "sysconf error\n");
            exit(1);
        }
        fputs(" (not defined) \n", stdout);
    }
    else
        printf(" %ld\n", val);
}

static void pr_pathconf(char *mesg, char *path, int name)
{
    long val;
    fputs(mesg, stdout);
    errno = 0;
    if ((val = pathconf(path, name)) < 0)
    {
        if (errno != 0)
        {
            fprintf(stderr,
                    "pathconf error, path = %s\n", path);
            exit(1);
        }
        fputs(" (no limit)\n", stdout);
    }
    else
        printf(" %ld\n", val);
}