#include <iostream>
using namespace std;
struct Node
{
    int val;
    Node* next;
    Node():next{nullptr} {};
    Node(int val):val{val},next{nullptr} {};
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

int searchElement(Node* head,int value)
{
  int index=0;
  Node* curr=head;
  while(curr)
  {
    if(curr->val==value)return index;
    index++;
    curr=curr->next;
  }
  cout<<" element not found";
  return -1; //not found
}

int main()
{
    int arr[]{1,4,5,6,7,4,2,5,6};
    Node* head;
    arrToList(arr,9,head);
    cout<<"found element "<<2<<" in index:"<<searchElement(head,2)<<endl;
    cout<<"found element "<<4<<" in index:"<<searchElement(head,4)<<endl;
    cout<<"found element "<<6<<" in index:"<<searchElement(head,6)<<endl;
    cout<<"found element "<<9<<" in index:"<<searchElement(head,9)<<endl;
    cout<<"found element "<<1<<" in index:"<<searchElement(head,1)<<endl;
    cout<<"found element "<<7<<" in index:"<<searchElement(head,7)<<endl;
    return 0;
}
