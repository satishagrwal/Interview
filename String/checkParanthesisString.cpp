/*
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:
1) Any left parenthesis '(' must have a corresponding right parenthesis ')'.
2) Any right parenthesis ')' must have a corresponding left parenthesis '('.
3) Left parenthesis '(' must go before the corresponding right parenthesis ')'.

'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

Constraints:

1 <= s.length <= 100
s[i] is '(', ')' or '*'.

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "(*)"
Output: true
Example 3:

Input: s = "(*))"
Output: true
*/

#include <bits/stdc++.h>
using namespace std;

bool checkValidString(string s)
{
    if(s.length() < 1 || s.length() > 100)
    {
        return false;
    }
    
    stack<int> open, star;
    
    for(int i = 0; s[i] !='\0'; i++)
    {
        if(s[i] == '(')
        {
            open.push(i);
        }
        else if(s[i] == '*')
        {
            star.push(i);
        }
        else
        {
            if(!open.empty())
            {
                open.pop();
            }
            else if(!star.empty())
            {
                star.pop();
            }
            else
            {
                return false;
            }
        }
    }
    
    if(!open.empty())
    {
        if(!star.empty())
        {
            return false;
        }
        else if(open.top() < star.top())
        {
            open.pop();
            star.pop();
        }
        else
        {
            return false;
        }
    }
    
    return true;
}
int main()
{
   string expresion = ")*()";
   
   if(checkValidString(expresion))
   {
     cout<<"True"<<endl;
   }
   else
   {
       cout<<"false"<<endl;
   }
   return true;
}
