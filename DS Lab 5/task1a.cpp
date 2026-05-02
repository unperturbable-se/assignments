#include <iostream>
using namespace std;

struct Node
{
  int val;
  Node* next;
  Node(int v):val{v},next{nullptr} {}
};

void arrToList(int* arr,int size,Node*& head)
{
    if(size==0){head=nullptr;return;}
    head=new Node(arr[0]);
    Node* curr=head;
    for(int i=1;i<size;i++)
    {
        curr->next=new Node(arr[i]);
        curr=curr->next;
    }
}

void display(Node*& head)
{
    Node* curr=head;
    while(curr)
    {
        cout<<curr->val<<' ';
        curr=curr->next;
    }
}

Node* _reverse(Node*&head)
{
    if(head->next)_reverse(head->next)->next=head;
    return head;
}

void reverse(Node*& head)
{
    Node* tail=head;
    while(tail->next)tail=tail->next;
    _reverse(head);
    head->next=nullptr;
    head=tail;
}



int main()
{
    int arr[]{1,3,4,5,3,5,6};
    Node* head;
    arrToList(arr,7,head);
    Node* curr=head;
    while(curr->next)curr=curr->next;
    curr->next=new Node(-129);
    reverse(head);
    display(head);
    return 0;
}