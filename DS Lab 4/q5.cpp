#include <iostream>
using namespace std;

void bubbleSort(int* arr,int size)
{
    for(int i=0;i<size;i++)
        for(int j=size-1;j>i;j--)
         if(arr[j]<arr[j-1])swap(arr[j],arr[j-1]);
}

int main()
{
    int years[]={2022, 2023, 2024, 2022, 2023, 2024};
    cout<<"\nunsorted:";
    for(int i=0;i<6;i++)cout<<years[i]<<' ';

    bubbleSort(years,6);
    cout<<"\nsorted:";
    for(int i=0;i<6;i++)cout<<years[i]<<' ';

    return 0;
}