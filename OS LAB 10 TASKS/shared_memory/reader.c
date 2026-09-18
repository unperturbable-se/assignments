#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
int main(void)
{
    int fd=shm_open("hello",O_RDONLY,0666);
    char* ptr=mmap(0,4096,PROT_READ,MAP_SHARED,fd,0);
    printf("%s",ptr);
    shm_unlink("hello");
    return 0;
