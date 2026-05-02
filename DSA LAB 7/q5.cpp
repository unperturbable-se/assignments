#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;
    Node(int d): data(d), next(nullptr) {}
};

void quickSort(Node** head) 
{
    if(!*head || !(*head)->next) return;
    Node *pivot = *head, *less = nullptr, *more = nullptr, *curr = (*head)->next;
    while(curr) 
    {
        Node* tmp = curr->next;
        if(curr->data < pivot->data) { curr->next = less; less = curr; }
        else { curr->next = more; more = curr; }
        curr = tmp;
    }
    quickSort(&less);
    quickSort(&more);
    Node* tmp = less;
    if(tmp) { while(tmp->next) tmp = tmp->next; tmp->next = pivot; } 
    else less = pivot;
    pivot->next = more;
    *head = less;
}

void printList(Node* head) 
{
    while(head) { cout << head->data << " "; head = head->next; }
}

int main() 
{
    int arr[] = {10,7,8,9,1,5,3};
    Node* head = new Node(arr[0]), *curr = head;
    for(int i=1;i<7;i++) { curr->next = new Node(arr[i]); curr = curr->next; }
    quickSort(&head);
    printList(head);
}
