#include <iostream>
using namespace std;


int binarySearch(int element, int* arr, int size)
{
    int low = 0, high = size - 1;
    int steps = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == element) return mid;
        
        else if (element < arr[mid])high = mid - 1;
        else low = mid + 1;
    }

    cout << "element not found:"<<element<<endl;
    return -1;
}
int main()
{   
    int arr[]{123,159,335,679,789,945,975,1033,1345,1945};
    for(int i=0;i<10;i++)cout<<arr[i]<<' ';
    
    cout<<"\nthe index of 1033 is:"<<binarySearch(1033,arr,10);
     return 0;
}
