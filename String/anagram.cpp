#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;

    // Assuming lowercase English letters only
    int count[26] = {0};

    for (int i = 0; i < s.size(); i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) return false;
    }

    return true;
}

int main() {
    string s = "satish";
    string t = "hssait";
    cout <<"Anagram :" << isAnagram(s, t)<<endl;
    return 0;
}
