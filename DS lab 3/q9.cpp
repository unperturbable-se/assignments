#include <iostream>
using namespace std;

struct Node
{
   int val;
   Node* next;
   Node(int v){val=v;next=nullptr;}
};
void steal(Node*& thiefTail, Node*& victim)
{
    if (!victim || !victim->next) return;

    Node* stolen = victim->next;
    victim->next = stolen->next;

    thiefTail->next = stolen;
    thiefTail = thiefTail->next;
    thiefTail->next = nullptr;
}

void mergeAltNode(Node* head)
{
    if (!head || !head->next) return;

    Node* curr = head;
    Node* alts = new Node(0);
    Node* altTail = alts;

    int i = 1;
    while (curr && curr->next)
    {
        if (i % 2 != 0)
        {
            steal(altTail, curr);
        }
        else
        {
            curr = curr->next;
        }
        i++;
    }

    curr = head;
    while (curr->next) curr = curr->next;

    curr->next = alts->next;

    delete alts;
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
     cout<<"before:";
     display(head);
     mergeAltNode(head);
     cout<<"\nafter:";
     display(head);
     return 0;

}