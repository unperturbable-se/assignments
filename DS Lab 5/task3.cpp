#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

int lengthTailRecursive(Node* head, int count)
{
    if (head == nullptr)
    {
        return count;
    }

    return lengthTailRecursive(head->next, count + 1);
}

int length(Node* head)
{
    return lengthTailRecursive(head, 0);
}

void insertAtEnd(Node*& head, int value)
{
    Node* newNode = new Node{value, nullptr};

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

int main()
{
    Node* head = nullptr;

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);

    cout << "Length of linked list: " << length(head) << endl;

    return 0;
}
