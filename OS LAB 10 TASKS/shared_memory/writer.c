#include <stdio.h>
#include <fcntl.h>
#include<sys/mman.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    int num=7;
    int fd=shm_open("hello",O_CREAT|O_RDWR,0666);
    ftruncate(fd,4096);
    char* memory_buffer=mmap(0,4096,PROT_WRITE,MAP_SHARED,fd,0);
    char* hello="hello how are you";
    //memcpy(memory_buffer,hello,sizeof(char)*strlen(hello));
    strcpy(memory_buffer,hello);
    return 0;
}