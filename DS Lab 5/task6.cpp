#include <iostream>
#include <vector>
using namespace std;

#define JaggedArray vector<vector<int>>

int sum(JaggedArray arr)
{
    int sum=0;
    for(int i=0;i<arr.size();i++)
      for(int j=0;j<arr[i].size();j++)sum+=arr[i][j];
    return sum;
}

int main()
{
    JaggedArray arr;
    arr.push_back({1,5,4,3,6,4,3,2,5,6,4,2,12,5,2,5});
    arr.push_back({1,3,4,3,5,3,5,3,5,4,5,3,5});
    arr.push_back({1,4,3,4,3,6,5,3,6,6,5,4,32,4,3,2,2,4,3,5,34,5});
    arr.push_back({1,4,2,4,3,5,34,5,4,5,345,4,5,3});
    cout<<"sum of all elements in the jagged array is:"<<sum(arr);
    return 0;
}