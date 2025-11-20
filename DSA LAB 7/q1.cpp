#include <iostream>
#include <queue>
using namespace std;

struct Student 
{
    string name; 
    int score; 
    Student* next;
    Student(string n,int s):name(n),score(s),next(nullptr){}
    void display()
    {
        cout<<"\nName:"<<name<<"  Score:"<<score;
        if(next)next->display();
    }
};

void countSort(Student*& students,int exp)
{
    if(!students) return;
    queue<Student*> b[10]; 
    Student* curr=students;
    while(curr)
    {
        Student* next=curr->next; 
        curr->next=nullptr; 
        b[(curr->score/exp)%10].push(curr); 
        curr=next;
    }
    Student *head=nullptr, *tail=nullptr;
    for(int i=0;i<10;i++) 
    while(!b[i].empty())
    {
        Student* node=b[i].front(); b[i].pop(); 
        if(!head) head=tail=node; 
        else tail->next=node, tail=node;
    }
    students=head;
}

void radixSort(Student*& head)
{
    if(!head) return; 
    int maxScore=0; 
    for(Student* curr=head; curr; curr=curr->next) 
        if(curr->score>maxScore) 
           maxScore=curr->score;
    for(int exp=1; maxScore/exp>0; exp*=10) countSort(head,exp);
}

int binarySearch(Student* left, int right, int sc)
{
    if (right <= 0 || !left) return -1; 

    int middle = right / 2;
    Student* midNode = left;

    for (int i = 0; i < middle; i++)
        midNode = midNode->next;

    if (midNode->score == sc)
        return middle; 
    else if (midNode->score < sc)
    {
        int res = binarySearch(midNode->next, right - middle - 1, sc);
        if (res == -1) return -1;
        return middle + 1 + res; 
    }
    else 
    return binarySearch(left, middle, sc);
}

int main()
{
    Student* head=new Student("Alice",78);
    auto curr=head;
    curr->next=new Student("James",34);
    curr=curr->next;
    curr->next=new Student("bourne",1267);
    curr=curr->next;
    curr->next=new Student("I",5432);
    curr=curr->next;
    curr->next=new Student("AM",1643);
    curr=curr->next;
    curr->next=new Student("John",123);
    curr=curr->next;
    curr->next=new Student("Cena",231);
    curr=curr->next;
    curr->next=new Student("bro",425);
    curr=curr->next;
    radixSort(head);    
    head->display();

    int choice=0;
    while(true)
    {
        cout<<"\nEnter a value(-99 to exit):";
        cin>>choice;
        if(choice==-99)break;
        int index=binarySearch(head,8,choice);
        if(index==-1)cout<<"\nIndex not found";
        else cout<<"\nThe Index is "<<index;
    }
    return 0;
}