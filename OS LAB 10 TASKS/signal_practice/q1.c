#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
void h(int s)
{
    char c;
    printf("\nInterrupt signal received! Exit? (Y/N): ");
    scanf("%c", &c);
    if(c == 'Y' || c == 'y') exit(0);
}
int main()
{
    signal(SIGINT, h);
    while(1);
}