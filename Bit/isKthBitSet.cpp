/*
Input : n = 5, k = 1
Output : true
5 is represented as 101 in binary and has its first bit set.

Input : n = 2, k = 3
Output : false
2 is represented as 10 in binary, all higher i.e. beyond MSB, bits are NOT SET.
*/

#include <bits/stdc++.h>
using namespace std;

bool isKthBitSet(int num, int k)
{
    int mask = 1;
	
	if(num & (mask << k-1))
	{
       return true;
	}
	return false;  
}

// Driver program to test above
int main()
{
    unsigned int n = 4;
    unsigned int k = 1;
    cout << isKthBitSet(n, k);
    return 0;
}
