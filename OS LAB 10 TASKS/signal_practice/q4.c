#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
void h(int s){ printf("Time's up!\n"); exit(0); }
int main()
{
    signal(SIGALRM, h);
    alarm(5);
    while(1)
    {
        printf("Waiting for alarn...\n");
        sleep(1);
    }
}