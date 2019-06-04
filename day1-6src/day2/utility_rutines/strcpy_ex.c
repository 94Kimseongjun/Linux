#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char buff[100];
    char *pstr = "phone";
    strcpy(buff, pstr); /* buff는 복사될 주소, pstr은 복사할 주소 */

    printf("*pstr = %s\n", pstr);
    printf("buff = %s\n", buff);
    return 0;
}
