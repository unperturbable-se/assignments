#include <iostream>
using namespace std;

struct Node
{
  Node* next=nullptr;
  Node* prev=nullptr;
  string val;
  Node(string val):val{val}{}
};


class Stack
{
  Node* top=nullptr;
  public:
  string peek()
  {
    if(!top)return "List is empty";
    return top->val;
  }

  void push(string val)
  {
    if(!top)top=new Node(val);
    else 
    {
        top->next=new Node(val);
        top->next->prev=top;
        top=top->next;
    }
  }

  string pop()
  {
    if(!top)return "List is empty";
    string a=top->val;
    if(!top->prev){delete top;top=nullptr;}
    else
    {
        top=top->prev;
        delete top->next;
        top->next=nullptr;
    }
    return a;
  }

  bool isEmpty(){return top? false:true;}
};

class TodoList
{
  Stack list;
  public:
  bool display()
  {
    system("Pause");
    system("cls");
    cout<<"TODO LIST\n";
    cout<<"1.ADD A NEW TASK\n";
    cout<<"2.COMPLETE THE CURRENT TASK\n";
    cout<<"3.DISPLAY THE CURRENT TASK\n";
    cout<<"ENTER AN OPTION(-1 TO EXIT):";
    int option;
    cin>>option;
    system("cls");
    switch(option)
    {

        case -1:
             return 0;
        case 1:
             {
               cout<<"Enter the task:";
               string task;
               cin.ignore(1,'\n');
               getline(cin,task);
               list.push(task);
               break;
             }   
        case 2:
             if(list.isEmpty())cout<<"There is no task pending\n";
             else list.pop();
        case 3:
             cout<<"Current Task:"<<list.peek()<<endl;
             break;
        default:
             cout<<"invalid choice\n";
    }
    return 1;
  }
};


int main()
{
    TodoList t;
    while(t.display()){}
    return 0;
}