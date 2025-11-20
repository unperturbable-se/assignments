#include <iostream>
using namespace std;

class Queue
{
    int arr[100];
    int front;
    int rear;
public:
    Queue()
    {
        front = 0;
        rear = -1;
    }
    void enqueue(int x)
    {
        if(rear < 99)
        {
            rear++;
            arr[rear] = x;
        }
    }
    int dequeue()
    {
        if(front <= rear)
        {
            int val = arr[front];
            front++;
            return val;
        }
        return -1;
    }
    bool isEmpty()
    {
        return front > rear;
    }
};

int main()
{
    Queue q;
    int customers[] = {13,7,4,1,6,8,10};
    for(int i = 0; i < 7; i++)
    {
        q.enqueue(customers[i]);
    }
    while(!q.isEmpty())
    {
        cout << "Serving customer ID: " << q.dequeue() << "\n";
    }
}

