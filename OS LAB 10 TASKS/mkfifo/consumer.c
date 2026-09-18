#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

#define fifo "/tmp/hellobruhhs"

int main(void)
{
    int fd=open(fifo,O_RDONLY);
    char buffer[100];
    read(fd,buffer,100);
    printf("%s",buffer);
    //unlink(fifo);
    return 0;
}