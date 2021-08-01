/*
Given a number N, the task is to check whether the count of the set and unset bits in the given number are same. 

Input: 12
Output: Yes
1100 is the binary representation of 12
which has 2 set and 2 unset bits 

Input: 14
Output: No
*/

#include <bits/stdc++.h>
using namespace std;

bool isSetUnsetBitEqual(int num)
{
	int set = 0, unset = 0;
  bool ret = false;
  
	// iterate for all bits of a number
	while (num)
  {
		if (num & 1)
    {
			set++;
    }
		else
    {
			unset++;
    }
		num = num >> 1;
	}

	if (set == unset)
  {
		ret = true;
  }
	
  return ret;
}

int main()
{
	int n = 12;
	if (isSetUnsetBitEqual(n))
  {
		cout << "YES";
  }
	else
  {
		cout << "NO";
  }
	return 0;
}
