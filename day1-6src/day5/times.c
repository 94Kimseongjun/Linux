#include <sys/times.h>
#include <stdio.h>
#include <unistd.h>

static void pr_times(clock_t, struct tms *, struct tms *);
static void do_cmd(char *);

int main(int argc, char *argv[])
{
    int i;
    for (i = 1; i < argc; i++)
        do_cmd(argv[i]);
    return 0;
}
static void do_cmd(char *cmd)
{
    struct tms tmsstart, tmsend;
    clock_t start, end;
    int status;
    fprintf(stderr, "\ncommand: %s\n", cmd);
    if ((start = times(&tmsstart)) == -1)
    { /* starting values */
        perror("times error");
        return -1;
    }
    if ((status = system(cmd)) < 0)
    { /* execute command */
        perror("system() error");
        return -1;
    }
    if ((end = times(&tmsend)) == -1)
    { /* ending values */
        perror("times error");
        return -1;
    }
    pr_times(end - start, &tmsstart, &tmsend);
    pr_exit(status);
}