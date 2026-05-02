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
    void enqueue(int patronID)
    {
        if(rear < 99)
        {
            rear++;
            arr[rear] = patronID;
        }
        else
        {
            cout << "Queue is full\n";
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
        cout << "Queue is empty\n";
        return -1;
    }
    bool isEmpty()
    {
        return front > rear;
    }
    void display()
    {
        if(isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Patrons waiting in queue: ";
        for(int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main()
{
    Queue libraryQueue;
    int choice, patronID;
    while(true)
    {
        cout << "1. Add patron to queue\n2. Complete patron transaction\n3. Display queue\n4. Exit\nChoice: ";
        cin >> choice;
        if(choice == 1)
        {
            cout << "Enter Patron ID: ";
            cin >> patronID;
            libraryQueue.enqueue(patronID);
        }
        else if(choice == 2)
        {
            int served = libraryQueue.dequeue();
            if(served != -1)
            {
                cout << "Patron " << served << "'s transaction completed.\n";
            }
        }
        else if(choice == 3)
        {
            libraryQueue.display();
        }
        else if(choice == 4)
        {
            break;
        }
        else
        {
            cout << "Invalid choice\n";
        }
    }
}
