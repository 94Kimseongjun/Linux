/*
$ cat > test.txt
abcdefgh
$ ./tcntlex test.txt
 */

#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd, val;
    pid_t pid;
    char buf[10];

    struct stat statbuf;
    struct flock lock;

    if ((fd = open("lockfile", O_RDWR | O_CREAT | O_TRUNC, 0644)) < 0)
    {
        perror("open error ");
        return -1;
    }
    if (write(fd, "abcdef", 6) != 6)
    {
        perror("write error ");
        return -1;
    }
    /* rw-r-Sr-- 비트 설정 */
    if (fstat(fd, &statbuf) < 0)
    {
        perror("fstat error ");
        return -1;
    }
    if (fchmod(fd, (statbuf.st_mode & ~S_IXGRP) | S_ISGID) < 0)
    {
        perror("fchmod error ");
        return -1;
    }

    if ((pid = fork()) < 0)
        perror("fork error ");
    else if (pid > 0)
    { /* parent process */
        lock.l_type = F_WRLCK;
        lock.l_start = 0;
        lock.l_whence = SEEK_SET;
        lock.l_len = 0;
        if (fcntl(fd, F_SETLK, &lock) < 0) // 파일 전체에 write-lock 설정
        {
            perror("fcntl error ");
            return -1;
        }
        sleep(10);
        if (waitpid(pid, NULL, 0) < 0)
        {
            perror("waitpid error ");
            return -1;
        }
        /* child process */
        sleep(10);
        if ((val = fcntl(fd, F_GETFL, 0)) < 0)
        {
            perror("fcntl error ");
            return -1;
        }
        val |= O_NONBLOCK;
        if (fcntl(fd, F_SETFL, val) < 0) // nonblocking 입출력 설정 { perror("fcntl error"); return -1; }
            lseek(fd, 0, SEEK_SET);
        if (read(fd, buf, 6) < 0)
            perror("read failure !mandatory locking works");
        printf("read success !mandatory locking doesn’t work\n");
    }
    return 0;
}