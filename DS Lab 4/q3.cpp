#include <iostream>
using namespace std;

void bubbleSort(string& str)
{
    for(int i=0;i<str.size();i++)
        for(int j=str.size()-1;j>i;j--)
         if(str[j]<str[j-1])swap(str[j],str[j-1]);
}

int main()
{
    string arr[] = {"banana", "apple", "cherry", "date", "grape"};
    for(int i=0;i<5;i++)cout<<arr[i]<<' ';
    cout<<endl;
    for(int i=0;i<5;i++)bubbleSort(arr[i]);
    for(int i=0;i<5;i++)cout<<arr[i]<<' ';
    return 0;
}