#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{
    int fd=shm_open("hello",O_RDONLY,0666);
    char* memory_buffer=mmap(0,4096,PROT_READ,MAP_SHARED,fd,0);
    printf("%s",memory_buffer);
    shm_unlink("hello");
    return 0;
}
