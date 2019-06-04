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
    int ifd, ofd;
    char *ibuf, *obuf;
    struct stat statbuf;
    if (argc != 3)
    {
        printf("usage : %s sourcefile targetfile", argv[0]);
        return -1;
    }
    if ((ifd = open(argv[1], O_RDONLY)) < 0)
    {
        perror("open error ");
        return -1;
    }
    if ((ofd = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 0644)) < 0)
    {
        perror("open error ");
        return -1;
    }
    if (fstat(ifd, &statbuf) < 0) /* sourcefile 크기 정보 필요 */
    {
        perror("fstat error ");
        return -1;
    }

    /* 출력 파일의 크기를 미리 설정 */
    if (lseek(ofd, statbuf.st_size - 1, SEEK_SET) < 0)
    {
        perror("lseek error ");
        return -1;
    }
    if (write(ofd, "", 1) != 1)
    {
        perror("write error ");
        return -1;
    }
    /* sourcefile 메모리 매핑 */
    if ((ibuf = mmap(0, statbuf.st_size, PROT_READ, MAP_FILE | MAP_SHARED, ifd, 0)) < 0)
    {
        perror("mmap error ");
        return -1;
    }

    /* targetfile 메모리 매핑 */
    if ((obuf = mmap(0, statbuf.st_size, PROT_READ | PROT_WRITE, MAP_FILE | MAP_SHARED, ofd, 0)) < 0)
    {
        perror("mmap error ");
        return -1;
    }
    /* 파일 전체 복사 */
    memcpy(obuf, ibuf, statbuf.st_size);
    return 0;
}