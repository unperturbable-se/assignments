#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int comparisons = 0;

enum selectionType { FIRST, LAST, MIDDLE, RANDOM, MEDIAN };
selectionType s;

int partition(int arr[], int low, int high) 
{
    int pivotIndex;
    switch(s)
    {
        case FIRST: pivotIndex = low; break;
        case LAST: pivotIndex = high; break;
        case MIDDLE: pivotIndex = low + (high-low)/2; break;
        case RANDOM: pivotIndex = low + rand() % (high-low+1); break;
        case MEDIAN: {
            int mid = low + (high-low)/2;
            int a = arr[low], b = arr[mid], c = arr[high];
            if((a>b)^(a>c)) pivotIndex = low;
            else if((b>a)^(b>c)) pivotIndex = mid;
            else pivotIndex = high;
            break;
        }
    }

    swap(arr[low], arr[pivotIndex]);
    int pivot = arr[low];
    int i = low + 1;
    for(int j = low + 1; j <= high; j++) 
    {
        comparisons++;
        if(arr[j] < pivot) 
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[low], arr[i-1]);
    return i-1;
}

void quickSort(int arr[], int low, int high) 
{
    if(low < high) 
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main()
{
    srand(time(0));
    s = FIRST; 

    int arr[] = {10, 7, 8, 9, 1, 5, 3};
    int n = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, 0, n-1);

    cout << "Sorted array(FIRST): ";
    for(int i=0;i<n;i++) cout << arr[i] << " ";
    cout << "\nComparisons: " << comparisons<<"\n\n\n";
    comparisons=0;
//--------------------------------------------------
    s = LAST; 

    int arr1[] = {10, 7, 8, 9, 1, 5, 3};

    quickSort(arr, 0, n-1);

    cout << "Sorted array(last): ";
    for(int i=0;i<n;i++) cout << arr1[i] << " ";
    cout << "\nComparisons: " << comparisons<<"\n\n\n";
    comparisons=0;
//--------------------------------------------------
    s = MIDDLE; 

    int arr2[] = {10, 7, 8, 9, 1, 5, 3};

    quickSort(arr2, 0, n-1);

    cout << "Sorted array(middle): ";
    for(int i=0;i<n;i++) cout << arr2[i] << " ";
    cout << "\nComparisons: " << comparisons<<"\n\n\n";
    comparisons=0;

//--------------------------------------------------
    s = RANDOM; 

    int arr3[] = {10, 7, 8, 9, 1, 5, 3};

    quickSort(arr3, 0, n-1);

    cout << "Sorted array(random): ";
    for(int i=0;i<n;i++) cout << arr3[i] << " ";
    cout << "\nComparisons: " << comparisons<<"\n\n\n";
    comparisons=0;

//--------------------------------------------------
    s = MEDIAN; 

    int arr4[] = {10, 7, 8, 9, 1, 5, 3};

    quickSort(arr4, 0, n-1);

    cout << "Sorted array(median): ";
    for(int i=0;i<n;i++) cout << arr4[i] << " ";
    cout << "\nComparisons: " << comparisons<<"\n\n\n";
    comparisons=0;
}
