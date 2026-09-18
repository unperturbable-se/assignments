#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#define read_end 0
#define write_end 1

int main(void)
{
    int pipes[2];
    pipe(pipes);
    if(fork()==0)
    {
        char input[100];
        scanf("%s",input);
        write(pipes[write_end],input,strlen(input));
        //sleep(1);
    }
    else
    {
        //sleep(1);
        char output[100];
        read(pipes[read_end],output,100);
        printf("\nMessage sent by child:%s\n",output);
    }
}