/* http://ehpub.co.kr/리눅스-시스템-프로그래밍-5-9-바이너리-모드-입출력/ */
#include <stdio.h>

#define MAX_NAME_LEN 20
typedef struct _Member Member;
struct _Member
{
    char name[MAX_NAME_LEN + 1];
    int age;
    int num;
};

void Write();
void Read();
int main()
{
    Write();
    Read();
    return 0;
}

void Write()
{
    Member base[4] =
        {
            {"홍길동", 20, 3}, {"강감찬", 30, 4}, {"김유신", 70, 1}, {"이순신", 35, 2}};
    FILE *fp = fopen("memdata", "wb");
    fwrite(base, sizeof(Member), 4, fp);
    fclose(fp);
}
void Read()
{
    Member base[4];
    FILE *fp = fopen("memdata", "rb");
    fread(base, sizeof(Member), 4, fp);
    fclose(fp);
    int i = 0;

    printf("이름    번호    나이\n");
    for (i = 0; i < 4; i++)
    {
        printf("%-12s %-6d %d\n", base[i].name, base[i].num, base[i].age);
    }
}