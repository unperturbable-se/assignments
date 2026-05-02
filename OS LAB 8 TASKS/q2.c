#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct array{
    int * arr;int size;
} array;

double average;
long long minimum;
long long maximum;

void* avg(void* a)
{
 array* b=a;
 long long sum=0;
 for(int i=0;i<b->size;i++)
 {
    sum+=b->arr[i];
 }
 average=sum/b->size;
}

void* min(void* a)
{
 array* b=a;
 minimum=b->arr[0];
 for(int i=1;i<b->size;i++)
 {
    if(b->arr[i]<minimum)minimum=b->arr[i];
 }
}

void* max(void* a)
{
 array* b=a;
 maximum=b->arr[0];
 for(int i=1;i<b->size;i++)
 {
    if(b->arr[i]>maximum)maximum=b->arr[i];
 }
}

void main()
{
    int arr[]={7,5,23,3,6,4,7,4,2,5,3,2,5,6,3,5,6,4,3,5,6};
    int size=21;
    array a;
    a.arr=arr;
    a.size=size;
    pthread_t threads[3];
    pthread_create(&threads[0],NULL,avg,&a);
    pthread_create(&threads[1],NULL,min,&a);
    pthread_create(&threads[2],NULL,max,&a);
    for(int i=0;i<3;i++)pthread_join(threads[i],NULL);
    printf("\nThe minimum number is %d",minimum);
    printf("\nThe maximum number is %d",maximum);
    printf("\nThe average number is %.3f\n",average);

}