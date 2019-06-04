#include <string.h>
#include <stdlib.h>
#include <pwd.h>
#include <unistd.h>
#include <utmpx.h>

int main(void)
{
    struct utmpx *utx;

    printf("-----------------\n");
    printf(" Login User\n");
    printf("-----------------\n");
    while ((utx = getutxent()) != NULL)
    {
        if (utx->ut_type != USER_PROCESS)
            continue;
        printf("%10s %5s\n", utx->ut_user, utx->ut_line);
    }
    return 0;
}
