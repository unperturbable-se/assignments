#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sigint_handler(int signum)
{
    printf("ctrl+c pressed\n");
    exit(signum);
}

int main()
{
    struct sigaction sa;
    sa.sa_handler=SIGINT;
    return 0;
}