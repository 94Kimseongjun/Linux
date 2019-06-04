/*
 reanme file1 file2
*/
#include <stdio.h>

int main(int argc, char **argv)
{
    if (rename(argv[1], argv[2]) < 0)
        perror("error : ");
    else
        printf("success\n");
}