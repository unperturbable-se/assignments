#include <iostream>
#include <string>
#include <stack>
using namespace std;

void rabinKarpSearch(string,string);

int main()
{
    cout<<"Enter the string that you wanna search in:";
    string str1;
    getline(cin,str1);
    cout<<"Enter the string youd like to search:";
    string str2;
    getline(cin,str2);
    rabinKarpSearch(str1,str2);
    return 0;
}

void rabinKarpSearch(string str, string value)
{
    stack<int> st;
    long long mod = 999999937;
    long long base = 10;

    int m = value.size();
    int n = str.size();
    if (m > n) return;

    long long power = 1;
    for (int i = 1; i < m; i++)
        power = (power * base) % mod;

    long long valueHash = 0;
    for (int i = 0; i < m; i++)
        valueHash = (valueHash * base + value[i]) % mod;

    long long hash = 0;
    for (int i = 0; i < m; i++)
        hash = (hash * base + str[i]) % mod;

    if (hash == valueHash)
        st.push(0);

    for (int i = m; i < n; i++)
    {
        hash = (hash - str[i - m] * power) % mod;
        if (hash < 0) hash += mod;
        hash = (hash * base) % mod;
        hash = (hash + str[i]) % mod;

        if (hash == valueHash)
            st.push(i - m + 1);
    }

    cout << "Indeces found:";
    while (!st.empty()) { cout << st.top() << ' '; st.pop(); }
}