/* http://ehpub.co.kr/리눅스-시스템-프로그래밍-5-10-파일-스트림-작업-위치/ */

#include <stdio.h>

#define MAX_NAME_LEN 20

typedef struct _Student Student;
struct _Student
{
    char name[MAX_NAME_LEN + 1];
    int age;
    int num;
};

void store_students();
void search_student();

int main()
{
    store_students();
    search_student();
    return 0;
}

void store_students()
{
    Student base[4] = {
        {"홍길동", 20, 3}, {"강감찬", 30, 4}, {"김유신", 70, 1}, {"이순신", 35, 2}};
    FILE *fp = fopen("students.dat", "wb");
    fwrite(base, sizeof(Student), 4, fp);
    fclose(fp);
}
void search_student()
{
    FILE *fp = fopen("students.dat", "rb");
    fseek(fp, 0, SEEK_END);
    int mcnt = ftell(fp) / sizeof(Student);
    rewind(fp);

    int nth = 0;
    printf("원하는 순번(1~%d):", mcnt);
    scanf("%d", &nth);
    if ((nth <= 0) || (nth > mcnt))
    {
        printf("잘못 입력하였습니다.\n");
        return;
    }

    fseek(fp, (nth - 1) * sizeof(Student), SEEK_SET);

    Student student;
    fread(&student, sizeof(Student), 1, fp);
    fclose(fp);
    printf("이름:%s 번호:%d 나이:%d\n", student.name, student.num, student.age);
}