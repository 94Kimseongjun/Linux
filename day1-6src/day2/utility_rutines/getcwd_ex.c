#include <stdio.h>
#include <unistd.h>

int main(void)
{
    char* cwd;
    char wd[200];

    cwd = getcwd(NULL, 200);
    printf("Current Dir: %s\n", cwd);

    chdir("../");
    getcwd(wd, 200);
    printf("Current Dir: %s\n", wd);

    return 0;
}
