#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node* next;
    Node(int v)
    {
        val = v;
        next = nullptr;
    }
};

void deleteList(Node* head)
{
    Node* prev;
    while (head)
    {
        prev = head;
        head = head->next;
        delete prev;
    }
}

void deleteNode(Node* head, int pos)
{
    Node* curr = head;
    Node* temp = nullptr;

    if (pos == 0)
    {
        head = head->next;
        delete curr;
        return;
    }

    temp = head;
    curr = head->next->next;
    for (int i = 1; i < pos; i++)
    {
        curr = curr->next;
        temp = temp->next;
    }
    delete temp->next;
    temp->next = curr;
}

void insertNode(Node* head, int pos, int val)
{
    if (pos == 0)
    {
        Node* curr = new Node(val);
        curr->next = head;
        head = curr;
        return;
    }

    Node* back = head;
    Node* front = head->next;
    for (int i = 1; i < pos; i++)
        back = back->next;
    front = back->next;
    back->next = new Node(val);
    back->next->next = front;
}

void display(Node* head)
{
    Node* curr = head;
    while (curr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    int arr[] = {3, 1, 2, 5, 8};
    int n = 5;

    cout << "Initial Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    Node* head = new Node(arr[0]);
    Node* curr = head;
    for (int i = 1; i < n; i++)
    {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }

    cout << "Linked List after creation from array: ";
    display(head);

    curr->next = new Node(9);
    cout << "After adding 9 at the end: ";
    display(head);

    insertNode(head, 3, 11);
    cout << "After inserting 11 at position 3: ";
    display(head);

    Node* newHead = new Node(4);
    newHead->next = head;
    head = newHead;
    cout << "After inserting 4 at the front: ";
    display(head);

    curr = head;
    int pos = 0;
    while (curr)
    {
        if (curr->val == 1)
        {
            deleteNode(head, pos);
            break;
        }
        curr = curr->next;
        pos++;
    }
    cout << "After deleting 1: ";
    display(head);

    curr = head;
    pos = 0;
    while (curr)
    {
        if (curr->val == 2)
        {
            deleteNode(head, pos);
            break;
        }
        curr = curr->next;
        pos++;
    }
    cout << "After deleting 2: ";
    display(head);

    curr = head;
    pos = 0;
    while (curr)
    {
        if (curr->val == 5)
        {
            deleteNode(head, pos);
            break;
        }
        curr = curr->next;
        pos++;
    }
    cout << "After deleting 5: ";
    display(head);

    deleteList(head);
    return 0;
}
