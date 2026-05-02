#include <iostream>
using namespace std;

void selectionSort(int* arr,int size)
{
    int min,minIndex;
    for(int i=0;i<size;i++)
    {
        min=arr[i];
        minIndex=i;
        for(int j=i+1;j<size;j++)
        {
            if(arr[j]<min)
            {
                min=arr[j];
                minIndex=j;
            }
        }
        arr[minIndex]=arr[i];
        arr[i]=min;
    }
}

int main()
{
    int arr[]{4,5,6,7,2,3,1,5,2,6,4,2,0};
    
    cout<<"first four elements(before sorting)\n";
    for(int i=0;i<4;i++)cout<<arr[i]<<' ';
    cout<<"\nfirst four elements(after sorting)\n";
    selectionSort(arr,13);
    for(int i=0;i<4;i++)cout<<arr[i]<<' ';
    return 0;
}