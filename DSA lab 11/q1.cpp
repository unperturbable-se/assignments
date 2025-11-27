#include<iostream>
using namespace std;

struct Node
{
    char key;
    string val;
    Node* next=nullptr;
    Node(char key,string val):val{val},key{key}{}
    void push(char key,string val)
    {
        if(next)next->push(key,val);
        else next=new Node(key,val);
    }
    
    void display()
    {
        cout<<'{'<<key<<','<<val<<"}  ";
        if(next)next->display();
    }
};

class HashTable
{
  Node* buckets[26];
  int hashingFunction(char key)
  {
    return key%26;
  }

  int hashingFunction(string value)
  {
    int sum=0;
    for(int i=0;i<value.size();i++)sum+=value[i];
    return sum%26;
  }
  public:
  void insertUsingKey(char key,string val)
  {
    int index=hashingFunction(key);
    if(!buckets[index])buckets[index]=new Node(key,val);
    else buckets[index]->push(key,val);
  }
  void insertUsingVal(char key,string val)
  {
    int index=hashingFunction(val);
    if(!buckets[index])buckets[index]=new Node(key,val);
    else buckets[index]->push(key,val);
  }
  HashTable()
  {
    for(int i=0;i<26;i++)buckets[i]=nullptr;
  }

  void display()
  {
    for(int i=0;i<26;i++)
    {
        if(buckets[i]){buckets[i]->display();cout<<endl;}
    }
  }

};

int main()
{
    HashTable myhash;
    myhash.insertUsingKey('A',"aaaaa");
    myhash.insertUsingKey('B',"bbbbb");
    myhash.insertUsingKey('C',"ccccc");
    myhash.insertUsingKey('A',"zzzzz");
    cout<<"hashing using the key\n";
    myhash.display();

    HashTable yourhash;
    yourhash.insertUsingVal('A',"aaaaa");
    yourhash.insertUsingVal('B',"bbbbb");
    yourhash.insertUsingVal('C',"ccccc");
    yourhash.insertUsingVal('A',"zzzzz");
    cout<<"hashing using the val\n";
    yourhash.display();
    return 0;
}