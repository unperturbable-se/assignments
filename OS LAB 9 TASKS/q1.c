#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sigint_handler(int signum)
{
    fprintf(stdout,"Caught sigint signal %d",signum);
}

int main()
{
    if(signal(SIGINT,sigint_handler)==SIG_ERR)
    {
        printf("Error setting up signal handler");
        return -1;
    }
    while(1)sleep(1);
    return 0;
}