#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

sem_t order_buffer;
static int order_id;
pthread_mutex_t orderNum;

void* placeOrder(void*)
{
    static int id=0;
    pthread_mutex_lock(&orderNum);
    order_id=id++;
    printf("\nOrder Placed-->order id:%d",order_id);
    pthread_mutex_unlock(&orderNum);
    sem_post(&order_buffer);
}

void* pickOrder(void* p)
{
  int delivery_id=*(int*)p;
  while(1)
  {
     sem_wait(&order_buffer);
     if(pthread_mutex_trylock(&orderNum)==0)
        {
            printf("\nOrder recieved by deliveryman %d-->order id:%d",delivery_id,order_id);
            sleep(1);
            pthread_mutex_unlock(&orderNum);
        }
  }
}

int main(void)
{
    pthread_mutex_init(&orderNum,NULL);
    sem_init(&order_buffer,0,0);
    pthread_t customers[130];
    pthread_t deliverymen[5];
    for(int i=0;i<5;i++)pthread_create(&deliverymen[i],NULL,pickOrder,&i);
    for(int i=0;i<130;i++)pthread_create(&customers[i],NULL,placeOrder,&i);
    for(int i=0;i<130;i++)pthread_join(customers[i],NULL);
    return 0;
}