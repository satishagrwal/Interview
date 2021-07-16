/*Given an expression string exp, examine whether the pairs and the orders of
“{“, “}”, “(“, “)”, “[“, “]” are correct in expression.

Example:

Input: exp = “[()]{}{[()()]()}” 
Output: Balanced

Input: exp = “[(])” 
Output: Not Balanced 

*/

#include <iostream>
#include<stack>

using namespace std;

bool isBracketsBalanced(string expr)
{
	stack<char> s;
	char x;

	for (int i = 0; i < expr.length(); i++)
	{
		if (expr[i] == '(' || expr[i] == '['
			|| expr[i] == '{')
		{
			s.push(expr[i]);
			continue;
		}

		if (s.empty())
    {
			return false;
    }
    
		switch (expr[i])
    {
		  case ')':
        {
			      x = s.top();
			      s.pop();
			      if (x == '{' || x == '[')
            {
				      return false;
            }
         }
			   break;

		  case '}':
          {
						x = s.top();
			      s.pop();
			      if (x == '(' || x == '[')
            {
				      return false;
            }
          }
			    break;

		   case ']':
            {
		           	x = s.top();
			          s.pop();
			          if (x == '(' || x == '{')
                {
				           return false;
                }
            }
			      break;
		    }
	}
	return (s.empty());
}


int main()
{
	string expr = "{()}[]";

	if (isBracketsBalanced(expr))
  {
		cout << "Balanced";
  }
	else
  {
		cout << "Not Balanced";
  }
	return 0;
}
