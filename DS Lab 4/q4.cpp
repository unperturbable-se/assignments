#include <iostream>
using namespace std;

bool hasDuplicate(int* arr,int size)
{
    for(int i=0;i<size;i++)
       for(int j=i+1;j<size;j++)
            if(arr[i]==arr[j])return true;
    return false;
}

int main()
{
    int arr[]={1,3,2,6,5,8,53,9};
    int arr1[]={1,3,2,6,5,8,53,9,9};
    cout<<"\narr:";
    for(int i=0;i<8;i++)cout<<arr[i]<<' ';
    cout<<"\n has duplicate?"<<((hasDuplicate(arr,8))? " yes":" no");

    cout<<"\narr1:";
    for(int i=0;i<9;i++)cout<<arr1[i]<<' ';
    cout<<"\n has duplicate?"<<((hasDuplicate(arr1,9))? " yes":" no");

    return 0;
}