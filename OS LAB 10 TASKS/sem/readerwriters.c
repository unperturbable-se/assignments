#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

sem_t library_writers[100];
static volatile int routine;
sem_t library_readers[100];

void* read_book(void* a)
{
    int book_id=*(int*)a;
    sleep(1);
    sem_wait(&library_readers[book_id]); //reserve book
    for(int i=0;i<5;i++)
    {
        while(routine==1)
        {
            //printf("\nBook %d forcefully returned\n",book_id);
            //sem_post(&library_readers[book_id]); //restore book
            //return NULL;
            sleep(1);
        }
        printf("\nBook %d is being read\n",book_id);
        sleep(1);
    }
    printf("\nBook %d returned\n",book_id);
    sem_post(&library_readers[book_id]); 
}

void* write_book(void* a)
{
    int book_id=*(int*)a;
    sem_wait(&library_writers[book_id]);
    for(int i=0;i<10;i++)
    {
        while(routine==0)
        {
            sleep(1);
            //printf("\nBook %d forcefully returned\n",book_id);
            //sem_post(&library_writers[book_id]); //restore book
            //return NULL;
        }
        printf("\nBook %d is being edited\n",book_id);
        sleep(1);
    }
}

void* routine_switcher(void*)
{
    routine=0;
    while(1)
    {
        sleep(3);
        routine+=1;
        routine%=1;
    }
}

int main(void)
{
    pthread_t routine_handler;
    pthread_create(&routine_handler,NULL,routine_switcher,NULL);
    pthread_t readers[100];
    pthread_t writers[20];
    for(int i=0;i<100;i++)
    {
        sem_init(&library_readers[i],0,5); //max 5 readers
        pthread_create(&readers[i],NULL,read_book,&i);
    }

    for(int i=0;i<20;i++)
    {
        sem_init(&library_writers[i],0,1); //max 1 writer
        pthread_create(&writers[i],NULL,write_book,&i);
    }
    for(int i=0;i<100;i++)pthread_join(readers[i],NULL);
    for(int i=0;i<20;i++)pthread_join(writers[i],NULL);
    return 0;
}