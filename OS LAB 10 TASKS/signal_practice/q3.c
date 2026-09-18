#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>


void h(int s){ printf("Child terminated by parent\n"); exit(0); }
int main()
{
    pid_t p = fork();
    if(p == 0)
    { 
        signal(SIGTERM, h); 
        while(1)
        {
            printf("Child process running...\n"); 
            sleep(1);
        }
    }
    else
    {
        sleep(5);
        kill(p, SIGTERM);
    };
}