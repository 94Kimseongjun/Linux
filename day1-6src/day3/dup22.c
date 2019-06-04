#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

// dup2 함수는 첫 번째 인자로 열려진 파일 디스크립터를 전달하고
// 두 번째 인자로 파일 디스크립터를 전달하면 첫 번째 인자로 열려진
// 파일 디스크립터가 참조하는 파일 테이블 엔트리를 두 번째 전달한 파일 디스크립터도 참조합니다.
// 만약 두 번째 인자로 전달한 파일 디스크립터가 열려진 파일 디스크립터일 때는 먼저 닫고 난 후에 복제합니다.

//  보통 dup2 함수는 정규 파일을 표준 출력으로 사용할 때 때 많이 사용합니다.

int main(int argc, char **argv)
{
    int fd = 0;
    if (argc != 2)
    {
        fprintf(stderr, "usage: %s [file name]\n", argv[0]);
        return 1;
    }
    fd = open(argv[1], O_WRONLY);
    if (fd == -1)
    {
        perror("failed open ");
        return 1;
    }
    if (dup2(fd, STDOUT_FILENO) == -1)
    {
        perror("failed dup2");
        return 1;
    }
    printf("hello world\n");
    close(fd);
    return 0;
}
