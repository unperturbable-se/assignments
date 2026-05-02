#include <iostream>
using namespace std;

void computeLPS(char pattern[], int m, int lps[]) {
    int length = 0;
    lps[0] = 0;
    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) length = lps[length - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int main() {
    char text[] = "babababc";
    char pattern[] = "abab";
    int n = 0, m = 0;
    while (text[n] != '\0') n++;
    while (pattern[m] != '\0') m++;

    int lps[100]; 
    computeLPS(pattern, m, lps);

    int positions[100]; 
    int posCount = 0;

    int i = 0, j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++; j++;
        }
        if (j == m) {
            positions[posCount++] = i - j;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }

    for (int k = 0; k < posCount; k++) cout << positions[k] << " ";
    cout << endl;
}
