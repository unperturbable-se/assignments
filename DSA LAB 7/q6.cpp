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


void Merge(int* arr1,int* arr2,int size1,int size2)
{
  int* merged=new int[size1+size2];
  int i,j,k;
  for(i=0,j=0,k=0;i<size1&&j<size2;k++)
  {
    if(arr1[i]<=arr2[j])
     merged[k]=arr1[i++];
    else
     merged[k]=arr2[j++];
  }
  while(i<size1)merged[k++]=arr1[i++];
  while(j<size2)merged[k++]=arr2[j++];
  for(int i=0;i<size1+size2;i++) arr1[i]=merged[i];
  delete[] merged;
}


void mergeSort(int* arr,int size)
{
    if(size<2)return;
    int mid=size/2;
    mergeSort(arr,mid);
    mergeSort(arr+mid,size-mid);
    Merge(arr,arr+mid,mid,size-mid);
}

int main()
{
    int arr1[10] = {12, 7, 9, 21, 3, 15, 6, 10, 18, 5};
    int arr2[10] = {8, 2, 14, 1, 19, 11, 13, 4, 16, 17};

    int combinedRadix[20];
    for(int i=0;i<10;i++) { combinedRadix[i]=arr1[i]; combinedRadix[i+10]=arr2[i]; }
    radixSort(combinedRadix, 20);
    cout<<"Radix Sort(merge):";
    for(int i=0;i<20;i++) cout << combinedRadix[i] << " ";

    int combinedMerge[20];
    for(int i=0;i<10;i++) { combinedMerge[i]=arr1[i]; combinedMerge[i+10]=arr2[i]; }
    mergeSort(combinedMerge, 20);
    cout<<"\nMerge Sort(merge):";
    for(int i=0;i<20;i++) cout << combinedMerge[i] << " ";
}