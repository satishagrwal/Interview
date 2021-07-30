/*
Given a non-negative number n and two values l and r. 
The problem is to toggle the bits in the range l to r in
the binary representation of n, i.e, to toggle bits from the
rightmost lth bit to the rightmost rth bit.
A toggle operation flips a bit 0 to 1 and a bit 1 to 0.

Constraint: 1 <= l <= r <= number of bits in the binary representation of n.

Input : n = 17, l = 2, r = 3
Output : 23
(17)10 = (10001)2
(23)10 = (10111)2
The bits in the range 2 to 3 in the binary
representation of 17 are toggled.

Input : n = 50, l = 2, r = 5
Output : 44
*/

#include <bits/stdc++.h>
using namespace std;

// function to toggle bits in the given range
int toggleBitsFromLToR(int num, int l, int r)
{
    int val = 0;
    int power = 0;
    int mask = 1;
	 int i=1;
	    //Include all rightmost bits as it is
	    while(i<l)
	    {
	        if(mask&num)
	        {
	            val += pow(2,power);
	        }
	        mask<<=1;
	        power+=1;
	        ++i;
	    }
	   //Toggle bits in range and include
	    while(i<=r)
	    {
	        if(!(mask&num))
	        {
	            val += pow(2,power);
	        }
	        mask<<=1;
	        power+=1;
	        ++i;
	    }
	    //Include all leftmost bits as it is
	    while(i<=16)
	    {
	        if(mask&num)
	        {
	            val += pow(2,power);
	        }
	        mask<<=1;
	        power+=1;
	        ++i;
	    }
	    return val;  
}

// Driver program to test above
int main()
{
    unsigned int n = 50;
    unsigned int l = 2, r = 5;
    cout << toggleBitsFromLToR(n, l, r);
    return 0;
}
