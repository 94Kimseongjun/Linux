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
  int fd;

  printf("GID is %d : %d\n", getegid(), getgid());
  setegid(65536); // /etc/group 파일 참조

  fd = open("test.txt", O_WRONLY | O_CREAT, S_IRWXU);
  close(fd);

  printf("GID is %d : %d\n", getegid(), getgid());
  setegid(getgid());

  fd = open("test2.txt", O_WRONLY | O_CREAT, S_IRWXU);
  printf("GID is %d : %d\n", getegid(), getgid());
  close(fd);
  return 0;
}