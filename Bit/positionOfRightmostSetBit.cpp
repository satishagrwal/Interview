/*
20 in binary is 00010100
The position of the rightmost set bit is 3
*/

#include <iostream>
#include <bitset>
using namespace std;

int positionOfRightmostSetBit(int num)
{
  int mask = 1;
	// if the number is odd, return 1
	if (num & mask)
  {
		return 1;
	}

	// Unset rightmost bit and xor with the number itself
	num = num ^ (num & (num - 1));

	// Find the position of the only set bit in the result by doing right shift;
	int pos = 0;
	while (num)
	{
		num = num >> 1;
		pos++;
	}
	return pos;
}

int main()
{
	int n = 20;

	cout << n << " in binary is " << bitset<8>(n) << endl;
	cout << "The position of the rightmost set bit is "<<positionOfRightmostSetBit(n);

	return 0;
}
