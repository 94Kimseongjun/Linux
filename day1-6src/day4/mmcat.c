#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>

#ifndef MAP_FILE
#define MAP_FILE 0
#endif

int main(int argc, char *argv[])
{
    int fd;
    struct stat st;
    caddr_t base, ptr;
    while (--argc)
    {
        if ((fd = open(*++argv, O_RDONLY, 0)) < 0)
        {
            perror(*argv);
            continue;
        }
        fstat(fd, &st);

        base = mmap(0, st.st_size, PROT_READ, MAP_SHARED, fd, 0);
        if (base == MAP_FAILED)
        {
            perror(*argv);
            close(fd);
            continue;
        }
        close(fd);
        for (ptr = base; ptr < &base[st.st_size]; ptr++)
            putchar(*ptr);
        munmap(base, st.st_size);
    }
    return 0;
}