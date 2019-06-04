/*
 * tmpfile() function is used to produce/create a temporary file.
 *  - tmp file opens in binary update mode; 'wb+'
 *  - the created tmp file will automatically be 
 *     deleted after the termination of program
 *  - 
 * 
 $ ./tmpfile_ex
 Temporary file is created
 Hello GeeksforGeeks
 */

#include <stdio.h>
#include <unistd.h>

int main()
{
    char str[] = "Hello tmpfile()";
    int i = 0;

    FILE *tmp = tmpfile();
    if (tmp == NULL)
    {
        printf("Unable to create tmp file\n");
        return 0;
    }
    //
    while (str[i] != '\0')
    {
        fputc(str[i], tmp);
    }
    // point the beginning of the file stream
    rewind(tmp);

    puts("Temporary file is created\n"); 
    while (!feof(tmp))
        //putc(fgetc(tmp), stdout);
        putchar(fgetc(tmp)); 
}