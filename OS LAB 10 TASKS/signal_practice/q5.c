#include <stdio.h>
#include <signal.h>
#include <unistd.h>
void h(int s)
{
    if(s == SIGUSR1) printf("User-defined signal 1 received\n");
    else if(s == SIGUSR2) printf("User-defined signal 2 received\n");
}
int main()
{
    signal(SIGUSR1, h); signal(SIGUSR2, h);
    while(1)
    {
        printf("Waiting for signal...\n");
        sleep(1);
    }
}