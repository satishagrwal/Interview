/*
  20 in binary is 00010100
  Turning 4th bit on
  28 in binary is 00011100
*/

#include <bits/stdc++.h>
using namespace std;

int turnOnKthBit(int num, int k)
{
   int mask = 1;
	 return num | (mask << k-1); 
}

// Driver program to test above
int main()
{
    int n = 20;
    int k = 4;
    cout << turnOnKthBit(n, k);
    return 0;
}
