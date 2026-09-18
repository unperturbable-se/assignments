#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void signalHandler(int sig) {
    const char msg[] = "Caught SIGINT\n";
    printf("\nsignal sent by OS:%d",sig);
    exit(sig);
}

int main() 
{ 
    signal(SIGINT, signalHandler); 
    while (1) {
        printf("Hello World!\n");
        sleep(1);
    }

    return 0; 
}