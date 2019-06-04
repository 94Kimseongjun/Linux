/* utime.c 
 $ ls -l test.txt
 $ ls -lu test.txt
 $ ./utime test.txt
 $ ls -l test.txt
 $ ls -lu test.txt
  
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <utime.h>

int main(int argc, char *argv[])
{
    struct utimebuf *timebuf = NULL;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file name>\n", argv[0]);
        return 1;
    }

    if (utime(argv[1], timebuf) < 0)
    {
        printf("utime call error\n");
        return 1;
    }
    else
        printf("Success");

    return 0;
}
