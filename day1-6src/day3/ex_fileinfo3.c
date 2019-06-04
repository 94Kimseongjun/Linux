#include <stdio.h>
#include <unistd.h>

void fileinfo(FILE *fp);

int main()
{
    putchar('e');
    fileinfo(stdout);
    putchar('h');
    fileinfo(stdout);
    putchar('p');
    fileinfo(stdout);
    putchar('u');
    fileinfo(stdout);
    putchar('b');
    fileinfo(stdout);
    putchar('\n');
    fileinfo(stdout);
    putchar('a');
    fileinfo(stdout);
    return 0;
}
void fileinfo(FILE *fp)
{
    printf("--------------------------------------------\n");
    printf("_fileno: %d\n", fp->_fileno);
    printf("_flags : %#x\n", fp->_flags);
    int dcnt = (fp->_IO_read_end - fp->_IO_read_ptr);
    printf("data count : %d\n", dcnt);
    printf("_IO_read_base : %s\n", fp->_IO_read_base);
    printf("_IO_read_ptr : %s\n", fp->_IO_read_ptr);
}