#include <iostream>
using namespace std;

struct Node
{
   int val;
   Node* next;
   Node(int v){val=v;next=nullptr;}
};
void deleteList(Node*head)
{
    Node* prev;
    while(head)
    {
        prev=head;
        head=head->next;
        delete prev;
    }
}
void evenBeforeOdd(Node* head)
{
 Node* newNode=new Node(0);
 Node* curr=head;
 Node* curr1;
 while(curr->val%2!=0)curr=curr->next;
 curr1=newNode;
 //curr=curr->next;
 while(curr)
 {
    if(curr->val%2==0)
    {
        curr1->next=new Node(curr->val);
        curr1=curr1->next;
    }
    curr=curr->next;
 }
 curr=head;
 while(curr->val%2==0)curr=curr->next;
 while(curr)
 {
    if(curr->val%2!=0)
    {
        curr1->next=new Node(curr->val);
        curr1=curr1->next;
    }
    curr=curr->next;
 }

 newNode=newNode->next;
 deleteList(head);
 head->val=newNode->val;
 head->next=newNode->next;
}

void display(Node* head)
{
     Node* curr=head;
     while(curr)
     {
        cout<<curr->val<<" ";
        curr=curr->next;
     }
}

int main()
{
    Node* head=new Node(7);
    Node* curr=head;
    curr->next=new Node(3);
    curr=curr->next;
    curr->next=new Node(4);
    curr=curr->next;
    curr->next=new Node(4);
    curr=curr->next;
    curr->next=new Node(2);
    curr=curr->next;
    curr->next=new Node(2);
    curr=curr->next;
    curr->next=new Node(5);
    curr=curr->next;
    curr->next=new Node(8);
    curr=curr->next;
    curr->next=new Node(32);
    curr=curr->next;
    curr->next=new Node(4);
    curr=curr->next;
    curr->next=new Node(1);
    curr=curr->next;
    curr->next=new Node(1);
    curr=curr->next;
    curr->next=new Node(9);
    curr=curr->next;
    cout<<"original:";
    display(head);
    cout<<endl;
    evenBeforeOdd(head);
    cout<<"\neven before odd:";
    display(head);
    return 0;
}