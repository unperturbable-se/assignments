#include<stdio.h>
#include<stdlib.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include <pthread.h>
int main()
{
    pid_t p;
    int fd = shm_open("Hello",O_CREAT|O_RDWR,0666);
    pthread_mutex_t sync;
    pthread_mutex_init(&sync,NULL);
    ftruncate(fd,4096);
    p = fork();
    if (p==0)
    {
        pthread_mutex_lock(&sync);
        char* mem = mmap(0,4096,PROT_WRITE|PROT_READ,MAP_SHARED,fd,0);
        fscanf(stdin,"%s",mem);
        pthread_mutex_unlock(&sync);
    }
    else
    {
        sleep(2);
        char* mem = mmap(0,4096,PROT_WRITE|PROT_READ,MAP_SHARED,fd,0);
        pthread_mutex_lock(&sync);
        printf("%d\n",strlen(mem));
        //strcpy(mem,"revString");
        pthread_mutex_unlock(&sync);
        shm_unlink("Hello");
    }
    
    
}