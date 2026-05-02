#include <iostream>
using namespace std;
struct Node
{
    int val;
    Node* next;
    Node* prev;
    Node(int v){val=v;next=nullptr;prev=nullptr;}
    void push(int v)
    {
        if(next)
        {
            Node* temp=next;
            next=new Node(v);
            next->prev=this;
            next->next=temp;
            temp->prev=next;
            return;
        }
        next=new Node(v);
        next->prev=this;
    }
};


void mergeList(Node*& L,Node*& M)
{
    if(!L){L=M;return;}
    Node* curr=L;
    while(curr->next)curr=curr->next;
    curr->next=M;
    M->prev=curr;
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
  Node* head=new Node(0);
  head->push(9);head->push(5);head->push(4);head->push(2);head->push(2);
  Node* head1=new Node(0);
  head1->push(9);head1->push(6);head1->push(1);head1->push(9);head1->push(1);
  cout<<"\nL:";
  display(head);
  cout<<"\nM:";
  display(head1);
  mergeList(head,head1);
  cout<<"\nL(after concatenation):";
  display(head);
  return 0;
}