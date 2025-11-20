#include <iostream>
using namespace std;

void insertionSort(int* arr, int size, int gap) 
{
    for (int i = gap; i < size; i++) 
    {
        int insert = arr[i];
        int j;
        for (j = i - gap; j >= 0 && arr[j] > insert; j -= gap)
            arr[j + gap] = arr[j];
        arr[j + gap] = insert;
    }
}
void shellSort(int arr[], int size)
{
    for (int gap = size / 2; gap > 0; gap /= 2)
        insertionSort(arr,size,gap);
}

int main()
{
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    shellSort(arr, n);

    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
