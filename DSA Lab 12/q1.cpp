#include <iostream>
#include <string>
using namespace std;

void searchString(string,string);

int main()
{
    cout<<"Enter the string that you wanna search in:";
    string str1;
    getline(cin,str1);
    cout<<"Enter the string youd like to search:";
    string str2;
    getline(cin,str2);
    cout<<"indexes present(none if empty):";
    searchString(str1,str2);
    return 0;
}

void searchString(string str,string value)
{
    for(int i=0;i<str.size();i++)
    {
        bool found=true;
        for(int j=0;j<value.size();j++)
            if(str[i+j]!=value[j])found=false;
        if(found)cout<<i<<" ";
    }
    cout<<"\nComparisons:"<<str.size()*value.size();
}