#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void reverseString(vector<char>& s)
{
   int left = 0;
   int right = s.size() -1;
   
   while( left < right)
   {
       std::swap(s[left], s[right]);
       left++;
       right--;
   }
}

int main() {
    std::vector<char> vec = {'c', 'o', 'd', 'e'};
    reverseString(vec);
    
    for (char c : vec) {
        cout << c;
    }
    cout << endl;
    return 0;
}
