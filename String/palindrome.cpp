/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 
Constraints:
1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPalindrome(string s) 
{
    int left = 0;
    int right = s.size() - 1;
    
    while (left < right) {
        // 1. Skip non-alphanumeric characters from the left
        if (!isalnum(s[left])) {
            left++;
        } 
        // 2. Skip non-alphanumeric characters from the right
        else if (!isalnum(s[right])) {
            right--;
        } 
        // 3. Compare characters (converted to lowercase)
        else {
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }
    }
    return true;
}

int main() 
{
    string str = "A man, a plan, a canal: Panama";
    //srting str = ""race a car"";
    cout << isPalindrome(str);
    return 0;
}
