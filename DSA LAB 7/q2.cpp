#include <iostream>
#include <queue>
using namespace std;

void countSort(int* arr,int size,int exp)
{
    queue<int> buckets[10];
    int digit;
    for(int i=0;i<size;i++)
    {
        digit=(arr[i]/exp)%10;
        buckets[digit].push(arr[i]);
    }

    int index=0;
    for(int i=0;i<10;i++)
    {
        while(!buckets[i].empty())
        {
            arr[index++]=buckets[i].front();
            buckets[i].pop();
        }
    }
}

void radixSort(int* arr,int size)
{
    if(!size)return;
    int max=arr[0];
    for(int i=0;i<size;i++)
       if(arr[i]>max)max=arr[i];
    for(int exp=1;max>0;max/=10,exp*=10)
       countSort(arr,size,exp);
}

int main()
{
    int arr[]{36,987,654,2,20,99,456,957,555,420,66,3};
    cout<<"original:";
    for(int i=0;i<12;i++)cout<<arr[i]<<' ';
    radixSort(arr,12);
    cout<<"\nSorted(Ascending):";
    for(int i=0;i<12;i++)cout<<arr[i]<<' ';

    for(int i=0,j=12-1;i<j;i++,j--)swap(arr[i],arr[j]);
    cout<<"\nSorted(Descending):";
    for(int i=0;i<12;i++)cout<<arr[i]<<' ';
    return 0;
}