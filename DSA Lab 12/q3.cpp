#include <iostream>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int badCharShift(char pattern[], int m, char c) {
    for (int i = m - 1; i >= 0; i--) {
        if (pattern[i] == c) return i;
    }
    return -1;
}

int main() {
    char DNA[] = "ACGTACGTGACG";
    char pattern[] = "ACG";
    int n = 0;
    while (DNA[n] != '\0') n++;
    int m = 0;
    while (pattern[m] != '\0') m++;

    int positions[100]; 
    int posCount = 0;
    int s = 0;
    while (s <= n - m) {
        int j = m - 1;
        while (j >= 0 && pattern[j] == DNA[s + j]) j--;
        if (j < 0) {
            positions[posCount++] = s;
            if (s + m < n)
                s += m - badCharShift(pattern, m, DNA[s + m]);
            else
                s += 1;
        } else {
            s += max(1, j - badCharShift(pattern, m, DNA[s + j]));
        }
    }

    for (int i = 0; i < posCount; i++) cout << positions[i] << " ";
    cout << endl;
}
