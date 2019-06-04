/* 4장 / char.c */
#include <stdio.h>

int main(int argc, char **argv)
{
    FILE *fp;
    char buf[256];

    if (argc != 2)
    {
        fprintf(stderr, "Usage: filelineio file\n");
        return -1;
    }

    if ((fp = fopen(argv[1], "w+")) == NULL)
    {
        perror("fopen error");
        return -1;
    }
    fputs("Input String >> ", stdout);
    gets(buf);      /* '\n' 제거 */
    fputs(buf, fp); /* '\n'이 없는 상태 */
    // rewind(fp);                  // 교재 4장/42쪽
    // fgets(buf, sizeof(buf), fp); /* '\n'이 없는 상태 */
    puts(buf); /* '\n' 추가 */
    fclose(fp);

    return 0;
}