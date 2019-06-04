/*
  루트 디렉토리을 열어 디렉토리 엔트리를 출력
 */

#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    struct dirent *item;
    DIR *dp;
    dp = opendir("/");
    while ((item = readdir(dp)) != NULL)
    {
        printf("%s %ld\n", item->d_name, item->d_ino);
    }
    // if (dp != NULL)
    // {
    //     for (;;)
    //     {
    //         item = readdir(dp);
    //         if (item == NULL)
    //             break;
    //         printf("DIR : %s\n", item->d_name);

    //         return 0;
    //     }
    // }
    closedir(dp);
    return 0;
}