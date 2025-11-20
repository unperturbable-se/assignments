#include<iostream>
using namespace std;

void insertAt(int newIndex, int oldIndex, int* arr)
{
    if (oldIndex <= newIndex) return;
    int val = arr[oldIndex];
    for (int i = oldIndex; i > newIndex; i--) arr[i] = arr[i - 1];
    arr[newIndex] = val;
}

void insertionSort(int* arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] < arr[j])
            {
                insertAt(j, i, arr);
                break;
            }
        }
    }
}

int main()
{
    int arr[] = {20, 12, 15, 2, 10, 1, 13, 9, 5};
    insertionSort(arr, 9);
    insertAt(4,8,arr); //largest in the middle
    for (int i = 0; i < 9; i++) cout << arr[i] << ' ';
    return 0;
}
