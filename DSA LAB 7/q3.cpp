#include <iostream>
using namespace std;

template<typename T>
void Merge(T* arr1,T* arr2,int size1,int size2)
{
  T* merged=new T[size1+size2];
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

template<typename T>
void mergeSort(T* arr,int size)
{
    if(size<2)return;
    int mid=size/2;
    mergeSort<T>(arr,mid);
    mergeSort<T>(arr+mid,size-mid);
    Merge<T>(arr,arr+mid,mid,size-mid);
}

struct Participant
{
  string name;
  int finishTime;
  void display()
  {
    cout<<name<<"--Time:"<<finishTime<<endl;
  }
  bool operator<(Participant& b)
  {
    return (finishTime<b.finishTime);
  }
  bool operator>(Participant& b)
  {
    return (finishTime>b.finishTime);
  }
  bool operator<=(Participant& b)
  {
    return (finishTime<=b.finishTime);
  }
};

int main()
{
    Participant arr[13];
    for(int i=0;i<13;i++)
    {
        cout<<"\nenter name and finish time for participant "<<i<<":  ";
        cin>>arr[i].name>>arr[i].finishTime;
    }
    mergeSort<Participant> (arr,13);
    for(int i=0;i<5;i++)
    {
        cout<<"\n"<<i<<". ";
        arr[i].display();
    }
    return 0;
}

//raed 12 aed 1 rahd 18 hgd 19 kkaed 56 rud 178 rjd 67 rajd 177 rkked 189 rlled 121 rld 121 rayd 12 JOHN 144