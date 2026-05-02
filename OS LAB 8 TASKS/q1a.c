#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define size 10000000
float* a;
float* b;
float *c;
long long start;
long long stop;

void* addArray(void*)
{
    for(long long i=start;i<stop;i++){c[i]=a[i]+b[i];printf("index %d:%f+%f=%f\n",i,a[i],b[i],c[i]);}
}



int main(void)
{
    a=malloc(sizeof(float)*size);
    b=malloc(sizeof(float)*size);
    c=malloc(sizeof(float)*size);
    for(long long i=0;i<size;i++)
    {
        a[i]=5;
        b[i]=6;
        
    }
    start=0;stop=size;
    addArray(NULL);
    free(a);free(b);free(c);
    return 0;
}