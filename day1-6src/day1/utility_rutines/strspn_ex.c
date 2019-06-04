#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char buff[100] = "This is a good book.";
    int i;
    i = strspn(buff, "abcde"); /* i는 0 : 'T'가 일치 안됨 */
    i = strspn(buff, "This "); /* i는 8 : 'a'가 일치 안됨 */
    i = strspn(buff, "12345"); /* i는 0 : 'T'가 일치 안됨 */

    return 0;
}
