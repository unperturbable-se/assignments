#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node* next;
    Node* curr;
    Node(int v):val{v}{};
};

class Circular
{
    Node* head;
    Node* tail;
    Node* curr;
    int size;
    public:
    Circular(int arr[],int siz)
    {
        size=siz;
        if(siz==0)return;
        head=new Node(arr[0]);
        curr=head;
        for(int i=1;i<siz;i++)
        {
         curr->next=new Node(arr[i]);
         curr=curr->next;
        }
        tail=curr;
        tail->next=head;
    }

    void display()
    {
        curr=head;
        for(int i=0;i<size;i++){cout<<curr->val<<" ";curr=curr->next;}
        cout<<endl;
    }

    void delet(int pos)
    {
      if(pos==0)
      {
        head=head->next;
        delete tail->next;
        tail->next=head;
        return;
      }
      if(pos>=size || pos<0)return;
      curr=head;
      for(int i=0;i<pos;i++)curr=curr->next;
      Node* temp=curr->next->next;
      delete curr->next;
      curr->next=temp;
      size--;
    }

   void insert(int pos, int val)
{
    if(pos == 0)
    {
        tail->next = new Node(val);
        curr = tail->next;
        curr->next = head;
        head = curr;
        return;
    }
    if(pos > size || pos < 0) return;

    curr = head;
    for(int i = 0; i < pos - 1; i++) curr = curr->next;

    Node* temp = curr->next;
    curr->next = new Node(val);
    curr->next->next = temp;


    if(pos == size)
        tail = curr->next;

    size++;
}

    
    ~Circular()
    {
      if(!head)return;curr=head;
      while(curr)
      {
        head=head->next;
        delete curr;
        curr=head;
      }
    }

};

int main()
{
    int arr[]{2,4,5,1,6,-1,3};
    Circular abc(arr,7);
    abc.display();
     cout << "\nInserting 0 at position 7 (end of the list):\n";
    abc.insert(7, 0);
    abc.display();

    cout << "\nInserting 0 at position 0 (beginning of the list):\n";
    abc.insert(0, 0);
    abc.display();

    cout << "\nInserting 0 at position 4:\n";
    abc.insert(4, 0);
    abc.display();

    cout << "\nDeleting node at position 6:\n";
    abc.delet(6);
    abc.display();

    return 0;
}




