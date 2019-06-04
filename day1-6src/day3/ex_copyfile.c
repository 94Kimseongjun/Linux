#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// 사용하기 쉽도록 표준입력,출력,에러를 다른 이름으로 정의 한다.
#define STDIN 0
#define STDOUT 1
#define STDERR 2

int main(int argc, char **argv)
{
    char *orgfile, *dstfile;
    int rfd, wfd;
    int readn;
    char buf[80];

    if (argc != 3)
    {
        printf("Usage : %s [src file] [dst file]\n", argv[0]);
        return 1;
    }

    orgfile = argv[1];
    dstfile = argv[2];

    rfd = open(orgfile, O_RDONLY);

    if (rfd < 0) // 에러 체크를 한다.
    {
        perror("org file open err :");
        return 0;
    }

    wfd = open(dstfile, O_WRONLY | O_CREAT, 0755);

    if (wfd < 0) // 에러 체크를 한다.
    {
        perror("dst file open err :");
        return 0;
    }

    // 원본파일로 부터 데이터를 읽은다음 읽어들인 데이터의 크기만큼 복사파일에 쓴다.
    while ((readn = read(rfd, buf, 80)) > 0)
    {
        write(wfd, buf, readn);
    }
    close(rfd);
    close(wfd);
    return 1;
}