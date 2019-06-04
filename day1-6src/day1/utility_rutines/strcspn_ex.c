/*
 * strcspn() 함수는 문자열에서 특정 문자 및 NULL 문자가 있는지 검색
 */
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char buff[100] = "This is a good book.";
    int i;
    i = strcspn(buff, "abcde"); /* I는 8 : 'a'가 검색됨 */
    i = strcspn(buff, "fghij"); /* i는 1 : 'h'가 검색됨 */
    i = strcspn(buff, "12345"); /* i는 20 : 일치되는 문자 없음 */
    i = strlen(buff);           /* i는 20 : 문자열의 길이 */

    return 0;
}
