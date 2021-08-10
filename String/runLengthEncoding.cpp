/*
Given a string, task is to complete the function encode that 
returns the run length encoded string for the given string.

Input:
str = aaaabbbccc
Output: a4b3c3

Explanation: a repeated 4 times
consecutively b 3 times, c also 3
times.
*/
#include <bits/stdc++.h>
using namespace std;

string printRLE(string str)
{
	int n = str.length();
	int count = 1;
	
	string res = "";
	
	for (int i = 0; i < n; i++) 
	{
		if(str[i] == str[i + 1])
		{
		  count++;  
		}
		else if( str[i] != str[i + 1]) 
		{
		    res = res + str[i] + std::to_string(count);
			count = 1;
		}
	}
	return res;
}

int main()
{
	string str = "aaabbccccaaa";
	cout<<printRLE(str);
	return 0;
}
