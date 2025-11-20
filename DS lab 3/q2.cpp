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
void deleteNode(Node* head,int pos)
{
    Node* curr=head;
    Node* temp=nullptr;
    if(pos==0)
    {
      head=head->next;
      delete curr;
      return;
    }
    
    temp=head;
    curr=head->next->next;
    for(int i=1;i<pos;i++)
    {
      curr=curr->next;
      temp=temp->next;
    }
    delete temp->next;
    temp->next=curr;
}

void insertNode(Node* head,int pos,int val)
{
    if(pos==0)
    {
        Node* curr=new Node(val);
        curr->next=head;
        head=curr;
        return;
    }

    Node* back=head;
    Node* front=head->next;
    for(int i=1;i<pos;i++)back=back->next;
    front=back->next;
    back->next=new Node(val);
    back->next->next=front;
}

int getVal(Node* head,int pos)
{
    Node* curr=head;
    for(int i=0;i<pos;i++)curr=curr->next;
    return curr->val;
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
    Node* temp=head;
    curr->next=new Node(3);
    curr=curr->next;
    curr->next=new Node(4);
    curr=curr->next;
    curr->next=new Node(4);
    curr=curr->next;
    curr->next=new Node(2);
    curr=curr->next;
    curr->next=new Node(1);
    curr=curr->next;
    curr->next=new Node(9);
    curr=curr->next;
    //7 3 4 4 2 1 9

    while(true)
    {
        cout<<"Current List:";
        display(head);
        cout<<endl;
        cout<<"Enter the number:";
        int num;
        cin>>num;
        for(int i=0;i<num;i++)
        {
            int val=head->val;
            head=head->next;
            delete temp;
            temp=temp->next;
            curr->next=new Node(val);
            curr=curr->next;
        }
    }
    return 0;
}