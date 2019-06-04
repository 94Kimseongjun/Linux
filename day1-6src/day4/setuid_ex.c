/**********************************************************************
* ex_setuid.c                                                         *
* exmple source – set user id                                         *
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("Usage: %s [user id]\n",argv[0]);
        printf("*** user id is number ***\n");
        return 1;
    }

    printf("real user id:%d effective user id:%d\n",getuid(), geteuid());
    uid_t uid=atoi(argv[1]);
    setuid(uid);
    printf("real user id:%d effective user id:%d\n",getuid(), geteuid());

    return 0;
}