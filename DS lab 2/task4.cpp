#include <iostream>
using namespace std;

bool hasMutualFriend(int arr[5][5],int e1,int e2)
{
  for(int i=0;i<5;i++)
    if(arr[e1][i]==1 && arr[e2][i]==1)return true;
  return false;
}

int main()
{
    int arr[5][5]
    {
        {0, 1, 0, 1, 1},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 1},
        {1, 1, 0, 1, 0}
    };

    cout << "index 0 and 4 " << (hasMutualFriend(arr, 0, 4) ? "have" : "don't have") << " mutual friend\n";
    cout << "index 1 and 2 " << (hasMutualFriend(arr, 1, 2) ? "have" : "don't have") << " mutual friend\n";
    return 0;
}