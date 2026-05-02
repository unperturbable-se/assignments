#include <iostream>
using namespace std;

struct Node
{
   int val;
   Node* next;
   Node(int v){val=v;next=nullptr;}
};


void deleteVal(Node*& head,int pos)
{
    if(!head || pos<0){cout<<"\nout of bounds\n";return;}
    Node* curr=head;
    if(pos==0)
    {
        head=head->next;
        delete curr;
        return;
    }
    int index{0};
    while(index<pos-1)
    {
      if(!curr){cout<<"\nout of bounds\n";return;}
      curr=curr->next;
      index++;
    }
    if(!curr->next){cout<<"\nout of bounds\n";return;}
    Node* next;
    if(curr->next->next)next=curr->next->next;
    delete curr->next;
    curr->next=next;
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

void arrToList(int* arr,int size,Node* head)
{
    if(size==0)return;
    head->val=arr[0];
    Node* curr=head;
    for(int i=1;i<size;i++)
    {
      curr->next=new Node(arr[i]);
      curr=curr->next;
    }
}

int main()
{
  int arr2[]{1,2,34,5,3,4,2,4,2,2};
  Node* larr2=new Node(0);
  arrToList(arr2,10,larr2);
  while(true)
  {
    cout<<"\narray:";
    display(larr2);
    cout<<endl;
    cout<<"index to remove:";
    int index;
    cin>>index;
    deleteVal(larr2,index);
  }
  return 0;
}