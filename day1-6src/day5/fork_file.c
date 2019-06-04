/*
 * fork()로 한 파일을 사용
 */

#include <sys/types.h>
#include <stdio.h>


int main(void)
{
    pid_t pid;
    if ((pid = fork()) < 0)
    {
        perror("fork error");
        return -1;
    }
    else if (pid == 0)
    {
        child_fileio();
    }
    else
    {
        charatatime("output from parent\n");
    }
    return 0;
}
void child_fileio()
{
        if ((fp = fopen("testfile.txt", "w+")) == NULL)
        {
            perror("fopen error");
            return -1;
        }
        fputs(buf, fp);
        
}