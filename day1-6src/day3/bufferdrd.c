#include <stdio.h>
#include <fcntl.h>

struct student
{
    int sno;
    char name[10];
    int point;
};

int main()
{

    struct student base;
    FILE *fp = fopen("student.dat", "rb");
    fread(&base, sizeof(struct student), 1, fp);
    fclose(fp);

    printf("번호    이름    점수\n");
    printf("%-12d %s %d\n", base.sno, base.name, base.point);

    return 0;
}
