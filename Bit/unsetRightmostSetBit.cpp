/*
20 in binary is 00010100
Rightmost bit of 20 is unset
16 in binary is 00010000
*/

#include <iostream>
#include <bitset>
using namespace std;

unsigned unsetRightmostSetBit(unsigned num)
{
	return num & (num - 1);
}

int main()
{
	int n = 20;

	cout << n << " in binary is " << bitset<8>(n) << endl;

	cout << "Rightmost bit of " << n << " is unset\n";
	n = unsetRightmostSetBit(n);

	cout << n << " in binary is " << bitset<8>(n) << endl;

	return 0;
}      
