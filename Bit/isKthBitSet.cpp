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
