#include <stdio.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void h(int s){ printf("Signal received in thread!\n"); exit(0); }
void* r(void* a){ while(1){ printf("Thread running...\n"); sleep(1); } }
void* w(void* a){ signal(SIGUSR1, h); while(1) sleep(1); }
int main()
{
    pthread_t t1, t2;
    pthread_create(&t1, NULL, r, NULL);
    pthread_create(&t2, NULL, w, NULL);
    pthread_join(t1, NULL);
}