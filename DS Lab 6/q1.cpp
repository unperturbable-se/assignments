#include <iostream>
using namespace std;




class Stack
{
  char* arr;
  int size;
  int topIndex=-1;
  public:
  Stack(int size):size{size},arr{new char[size]} {}
  void push(char val)
  {
    if(topIndex==size-1)return;
    arr[++topIndex]=val;
  }
  char pop()
  {
    if(topIndex==-1)return ' ';
    return arr[topIndex--];
  }


  char top()
  {
    if(topIndex!=-1)return arr[topIndex];
    return ' ';
  }


  ~Stack()
  {
    delete[] arr;
  }
};




bool isPalindrome(string str)
{
  Stack stac(str.size());
  for(auto element:str)stac.push(element);
  for(auto element:str)
  {
    if(element==stac.top())stac.pop();
    else return false;
  }
  return true;
}


int main()
{
    string s1="BORROWROB";
    string s2="BORROBWOOW";
    string s3="WOOW";
    cout<<s1<<" is"<<(isPalindrome(s1)? " a palindrome\n":" not a palindrome\n");
    cout<<s2<<" is"<<(isPalindrome(s2)? " a palindrome\n":" not a palindrome\n");
    cout<<s3<<" is"<<(isPalindrome(s3)? " a palindrome\n":" not a palindrome\n");
    return 0;
}



