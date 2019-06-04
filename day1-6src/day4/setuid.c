/*
 $ id
 $ ./setuid
  error : Operation not permitted
 $ sudo ./setuid
 [sudo] password for qkboo:
 $ ls -l test.txt
   -rw-r--r-- 1 501 dialout 9 May 30 03:33 test.txt
 */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int fd, state;
    state = setuid(2000); // 계정의 UID /etc/passwd 파일 참조

    if (state < 0)
    {
        perror("error ");
        return -1;
    }
    if ((fd = open("test.txt", O_CREAT | O_RDWR, S_IRWXU | S_IRUSR)) < 0)
    {
        perror("open");
        return -1;
    }
    close(fd);
    return 0;
}
