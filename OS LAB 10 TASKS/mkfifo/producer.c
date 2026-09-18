#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

#define fifo "/tmp/hellobruhhs"

int main(void)
{
    mkfifo(fifo,0666);
    int fd=open(fifo,O_WRONLY);
    char* buffer="Hello the other guy how are you?";
    write(fd,buffer,strlen(buffer));
    //close(fd);
    return 0;
}