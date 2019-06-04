#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char buff[100] = "This is a good book.";
    int i;
	// argv에서 검색문자를 받아 일치하는 것 일치하지 않는 것
	//
    i = strspn(buff, argv); /* i는 0 : 'T'가 일치 안됨 */
    i = strspn(buff, argv); /* i는 8 : 'a'가 일치 안됨 */
    i = strspn(buff, argv); /* i는 0 : 'T'가 일치 안됨 */

    return 0;
}
