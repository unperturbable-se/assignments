#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    int fd=shm_open("hello",O_CREAT|O_RDWR,0666);
    ftruncate(fd,4096);
    char* memory_buffer=mmap(0,4096,PROT_WRITE,MAP_SHARED,fd,0);
    char* hello="\nhello world how are you\n";
    strcpy(memory_buffer,hello);
    return 0;
}
