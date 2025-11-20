#include <iostream>
using namespace std;

template<typename T>
struct Node
{
    T val;
    Node<T>* next=nullptr;
    Node<T>* prev=nullptr;
    Node(T val):val{val}{}
    void push(T value)
    {
        if(next)
        {
            Node* temp=new Node(value);
            temp->prev=this;
            temp->next=next;
            next->prev=temp;
            next=temp;
            return;
        }
        next=new Node(value);
        next->prev=this;
    }
};

template<typename T>
class Stack
{
 Node<T>* top=nullptr;
 public:
 T peek()
 {
    if(top)return top->val;
    return {};
 }

 void push(T val)
 {
    if(!top)top=new Node(val);
    else
    {
       top->push(val);
       top=top->next;
    }
 }

 void pop()
 {
    if(!top)return;
    if(!top->prev){delete top;top=nullptr;return;}
    top=top->prev;
    delete top->next;
    top->next=nullptr;
 }
};

class BrowsingHistory
{
  Stack<string>s;
  public:
  bool display()
  {
    cout<<"Options:\n";
    cout<<"0.Exit\n";
    cout<<"1.Go to URL\n";
    cout<<"2.Display current URL\n";
    cout<<"3.Go Back\n";
    int option;
    cout<<"Option:";
    cin>>option;
    switch(option)
    {
        case 0:
               return 0;
        case 1:
               {
                string url;
                cout<<"Enter the url:";
                cin>>url;
                s.push(url);
                return 1;
               }
        case 2:
               {
                cout<<s.peek()<<endl;
                return 1;
               }
        case 3:
               {
                s.pop();
                return 1;
               }
        default: cout<<"Invalid option";
    }
    return 1;
  }
};


int main()
{
    BrowsingHistory h;
    while(h.display())
    {
      //system("Pause");
      //system("cls");
    }
    return 0;
}