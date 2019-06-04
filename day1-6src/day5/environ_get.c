/* day5/environ.c
*/
#include <unistd.h>
#include <stdio.h>
  
int main(int argc, char **argv, char **envp) {

    char *val;

    val = getenv("SHELL");
    if (val == NULL)
        printf("SHELL not defined\n");
    else
        printf("SHELL = %s\n", val);

    return 0;
}