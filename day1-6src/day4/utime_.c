/* utime.c */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <utime.h>

int main(int argc, char *argv[])
{
    int i;
    struct stat statbuf;
    struct utimbuf timebuf;
    char buf[30];
    for (i = 1; i < argc; i++)
    {
        if (stat(argv[i], &statbuf) < 0) /* fetch current times */
        {
            sprintf(buf, "%s: stat error", argv[i]);
            perror(buf);
            continue;
        }

        if (open(argv[i], O_RDWR | O_TRUNC) < 0) /* truncate */
        {
            sprintf(buf, "%s: open error", argv[i]);
            perror(buf);
            continue;
        }

        timebuf.actime = statbuf.st_atime;
        timebuf.modtime = statbuf.st_mtime;
        if (utime(argv[i], &timebuf) < 0) /* reset times */
        {
            sprintf(buf, "%s: utime error", argv[i]);
            perror(buf);
            continue;
        }
    }
    return 0;
}