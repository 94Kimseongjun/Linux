/*
 * mkfifo(char* path-name, mode_t mode)
 * mkfifo() makes a FIFO a special file with name 'path-name'. 
 * ---------------------------------------------------
 * fifoex1, fifoex2 program doing read & write.
 * fifoex1.c : writes first then read, 
 * fifoex2.c : read first then write.
 */

#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main() 
{ 
    int fd; 
  
    char * myfifo = "/tmp/myfifo"; 
  
    mkfifo(myfifo, 0666);     // 네임드 FIFO 파일을 생성한다 
  
    char arr1[80], arr2[80]; 

    while (1) 
    { 
        fd = open(myfifo, O_WRONLY); 
  
        // Take an input arr2ing from user. 80 is maximum length 
        fgets(arr2, 80, stdin); 
  
        // Write the input arr2ing on FIFO and close it 
        write(fd, arr2, strlen(arr2)+1); 
        close(fd); 
  
        // Open FIFO for Read only 
        fd = open(myfifo, O_RDONLY); 
  
        // Read from FIFO 
        read(fd, arr1, sizeof(arr1)); 
  
        // Print the read message 
        printf("User2: %s\n", arr1); 
        close(fd); 
    } 
    return 0; 
} 