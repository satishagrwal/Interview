/*
20 in binary is 00010100
Toggling 3rd bit of n
16 in binary is 00010000
*/

#include <bits/stdc++.h>
using namespace std;

int toggleKthBit(int num, int k)
{
    int mask = 1;
	  return num ^ mask << (k-1); 
}

// Driver program to test above
int main()
{
    unsigned int n = 20;
    unsigned int k = 3;
    cout << toggleKthBit(n, k);
    return 0;
}
