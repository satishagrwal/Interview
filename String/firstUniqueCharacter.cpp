#include <iostream>
using namespace std;

char firstUniqChar(string s) {
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        bool found = false;

        for (int j = 0; j < n; ++j) {
            if (i != j && s[i] == s[j]) {
                found = true;
                break;
            }
        }
        if (!found) 
            return s[i];
    }

    return '$';
}
/*
char firstUniqChar(string str) {
    int count[256] = {0}; // Frequency array for ASCII

    // Pass 1: Count occurrences - O(n)
    for (char c : str) {
        count[(unsigned char)c]++;
    }

    // Pass 2: Find first character with count 1 - O(n)
    for (char c : str) {
        if (count[(unsigned char)c] == 1) {
            return c;
        }
    }
    return '\0';
}
*/
int main() {
    string s = "satish";
    cout << firstUniqChar(s);
    return 0;
}
