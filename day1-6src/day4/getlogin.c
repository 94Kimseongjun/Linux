#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    char buf[256] = "";

    printf("login user name:%s\n", getlogin());
    
    cuserid(buf);
    printf("effective user name:%s\n", buf);

    return 0;
}