#include <iostream>
using namespace std;

void linearSearch(string element,string* arr,int size)
{
    for(int i=0,steps=1;i<size;i++,steps++) 
       if(arr[i]==element)
         {
            cout<<"linear search of "<<element<<endl;
            cout<<"the index is "<<i<<endl;
            cout<<"number of steps:"<<steps<<endl;
            return;
         }
    cout<<"element not found:"<<element<<endl;
}

void binarySearch(string element, string* arr, int size)
{
    int low = 0, high = size - 1;
    int steps = 0;

    while (low <= high)
    {
        steps++;
        int mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            cout << "binary search of " << element << endl;
            cout << "the index is " << mid << endl;
            cout << "number of steps: " << steps << endl;
            return;
        }
        else if (element < arr[mid])high = mid - 1;
        else low = mid + 1;
    }

    cout << "element not found:"<<element<<endl;
}
int main()
{   
    string arr[]=
    {
        "Ahmed", "Ali", "Basit", "Karim", "Rizwan", 
        "Sarwar", "Tariq", "Taufiq", "Yasin", "Zulfiqar"
    };
    linearSearch("Aftab",arr,10);
    binarySearch("Aftab",arr,10);
    cout<<"\n-----------------------------------\n";
    linearSearch("Rizwan",arr,10);
    binarySearch("Rizwan",arr,10);
    cout<<"\n-----------------------------------\n";
    linearSearch("Tariq",arr,10);
    binarySearch("Tariq",arr,10);
    cout<<"\n-----------------------------------\n";
    return 0;
}
