#include <iostream>
using namespace std;
class Box
{
  int* randomInteger;
  public:
  Box(int a):randomInteger{new int(a)}{}
  Box(Box& a):randomInteger{new int(*a.randomInteger)}{}
  void operator=(Box&b){randomInteger=b.randomInteger;} //I intentionally used shallow copy
  ~Box(){delete randomInteger;}
  int getValue(){return *randomInteger;}
  void setValue(int val){*randomInteger=val;}
};

int main()
{
    Box original(12);
    cout<<"\noriginal:"<<original.getValue()<<endl;
    Box deep(original);
    cout<<"\nDeep Copy:"<<deep.getValue()<<endl;
    deep.setValue(28);
    cout<<"\nDeep Copy:"<<deep.getValue()<<endl;
    cout<<"\noriginal:"<<original.getValue()<<endl;

    Box shallow(0);
    shallow=original;
    cout<<"\nShallow Copy:"<<shallow.getValue()<<endl;
    shallow.setValue(28);
    cout<<"\nShallow Copy:"<<shallow.getValue()<<endl;
    cout<<"\noriginal:"<<original.getValue()<<endl;

    return 0;
}