/*
count fixed lengh of distinct substring from given string.

Input: abcdabc
output: 4
abc, bcd, cda, dab
*/
#include<bits/stdc++.h>
using namespace std;

int countDistinctSubstring(string str, int len)
{
	set<string> result ;

	for (int i = 0; i <= str.length(); i++)
	{
		for (int j = 1; j <= len; j++)
		{
		   string s = str.substr(i, j);
       if(s.length() == len)
       {
			    result.insert(s);
       }
		}
	}
	return result.size();
}

int main()
{
	string str = "abcdabc";
	cout << (countDistinctSubstring(str, 3));
  return 0;
}

