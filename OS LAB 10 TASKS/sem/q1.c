#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t library[100];
sem_t library_writers[100];
static volatile int routine; //reading=0 writing=1
pthread_mutex_t routine_lock;
void * routine_manager(void*)
{
  routine=0;
  while(1)
  {
    sleep(1);
    //pthread_mutex_lock(&routine_lock);
    routine+=1;
    routine%=1;
    //pthread_mutex_unlock(&routine_lock);
  }
}

void* read_book(void* a)
{
    int book_number=*(int*)a;
    sem_wait(&library[book_number]);
    for(int i=0;i<5;i++)
    {
        //pthread_mutex_lock(&routine_lock);
        if(routine==1)
        {
            //pthread_mutex_unlock(&routine_lock);
            while(1)
            {
                //pthread_mutex_lock(&routine_lock);
                if(routine==0)
                {
                    //pthread_mutex_unlock(&routine_lock);
                    break;
                }
                //pthread_mutex_unlock(&routine_lock);
                sleep(1);
            }
        }
        printf("\nReading book(thread %d)",book_number);
        sleep(1);
    }
    sem_post(&library[book_number]);
}

void* write_book(void* a)
{
    int book_number=*(int*)a;
    sem_wait(&library_writers[book_number]);
    for(int i=0;i<5;i++)
    {
        //pthread_mutex_lock(&routine_lock);
        if(routine==0)
        {
            //pthread_mutex_unlock(&routine_lock);
            while(1)
            {
                //pthread_mutex_lock(&routine_lock);
                if(routine==1)
                {
                    //pthread_mutex_unlock(&routine_lock);
                    break;
                }
                //pthread_mutex_unlock(&routine_lock);
                sleep(1);
            }
        }
        printf("\nWriting book(thread %d)",book_number);
        sleep(1);
    }
    sem_post(&library_writers[book_number]);
}

int main() {
    pthread_t routine_handler_thread;
    //pthread_mutex_init(&routine_lock,NULL);
    pthread_create(&routine_handler_thread,NULL,routine_manager,NULL);
    pthread_t readers[20];
    pthread_t writers[10];
    for(int i=0;i<100;i++)sem_init(&library[i],0,5); //i allowed only 5 readers at a time
    for(int i=0;i<100;i++)sem_init(&library_writers[i],0,1); // only 1 writer allowed

    //for ease sake reader i reads book i and writer j writes book j
    for(int i=0;i<20;i++)pthread_create(&readers[i],NULL,read_book,(void*)&i);
    for(int i=0;i<10;i++)pthread_create(&writers[i],NULL,write_book,(void*)&i);
    return 0;
}