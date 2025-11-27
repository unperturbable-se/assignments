#include<iostream>
using namespace std;

struct Node
{
    string val;
    Node* next=nullptr;
    Node(string val):val{val}{}
    void push(string val)
    {
        if(next)next->push(val);
        else next=new Node(val);
    }
    
    void display()
    {
        cout<<'{'<<val<<"}  ";
        if(next)next->display();
    }

    bool search(string val)
    {
        if(val==this->val)return true;
        if(next)return next->search(val);
        return false;
    }
};

class Dictionary
{
  Node* buckets[100];
  int hashingFunction(string value)
  {
    int sum=0;
    for(int i=0;i<value.size();i++)sum+=value[i];
    return sum%100;
  }
  public:
  void add_record(string val)
  {
    int index=hashingFunction(val);
    if(!buckets[index])buckets[index]=new Node(val);
    else buckets[index]->push(val);
  }
  Dictionary()
  {
    for(int i=0;i<100;i++)buckets[i]=nullptr;
  }

  void print_dictionary()
  {
    for(int i=0;i<100;i++)
    {
        if(buckets[i]){buckets[i]->display();cout<<endl;}
    }
  }

  void word_search(string val)
  {
    int index=hashingFunction(val);
    if(!buckets[index] || !buckets[index]->search(val))cout<<"ERROR: "<<val<<" not found\n";
    else cout<<val<<" found\n";
  }

};

int main()
{
    Dictionary dict;
    dict.add_record("Harry potter");       
    dict.add_record("jrr tolkien");       
    dict.add_record("hello");       
    dict.add_record("sydney");       
    dict.add_record("wimpy kid");       
    dict.add_record("spoooks apprentice");       

    dict.print_dictionary();
    dict.word_search("Harry potter");
    dict.word_search("unknownbook");
    dict.word_search("jrr tolkien");
    return 0;
}