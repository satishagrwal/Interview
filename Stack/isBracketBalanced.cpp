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
        stack<char> st;

        for( int i = 0; i < expr.size(); i++ )
        {
            if( expr[i] == '(' || expr[i] == '{' || expr[i] == '[' )
            {
                st.push(expr[i]);
            }
            else
            {
                if(st.empty())
                {
                   return false;
                }
                char top = st.top();
                st.pop();
                
                switch (expr[i])
                {
                   case  ')' :
                   {
                      if( top != '(' )
                      {
                         return false;
                      }
                    }
                    break;

                    case  '}' :
                    {
                       if( top != '{')
                       {
                          return false;
                       }
                    }
                    break;

                    case  ']' :
                    {
                       if( top != '[' )
                       {
                          return false;
                       }
                    }
                    break;
                }    
            }
        }
        return(st.empty());
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
