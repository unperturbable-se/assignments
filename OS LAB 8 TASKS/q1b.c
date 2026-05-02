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
    for(long long i=start;i<stop;i++){c[i]=a[i]+b[i];printf("%f+%f=%f\n",a[i],b[i],c[i]);}
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

    pthread_t threads[10];
    for(int i=0;i<10;i++)
    {
        start=(size/10)*i;
        stop=start+(size/10);
        pthread_create(&threads[i],NULL,addArray,NULL);
    }
    for(int i=0;i<10;i++)pthread_join(threads[i],NULL);
    for(int i=0;i<size;i++)printf("\nIndex %d of c: %.1f",i,c[i]);
    free(a);free(b);free(c);
    return 0;
}