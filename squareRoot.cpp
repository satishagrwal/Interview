#include <bits/stdc++.h>
using namespace std;

double Square(double n, double i, double j)
{
	double mid = (i + j) / 2;
	double mul = mid * mid;

	if (mul == n)
  {
		return mid;
  }
	// If mul is less than n, recur second half
	else if (mul < n)
  {
		return Square(n, mid, j);
  }
	// Else recur first half
	else
  {
		return Square(n, i, mid);
  }
}

void findSqrt(double n)
{
	double i = 1;

	// While the square root is not found
	bool found = false;
	while (!found)
  {
		// If n is a perfect square
		if (i * i == n)
    {
			cout<<i<<endl;
			found = true;
		}
		else if (i * i > n) 
    {
			// Square root will lie in the
			// interval i-1 and i
			double res = Square(n, i - 1, i);
			cout<< res;
			found = true;
		}
		i++;
	}
}

int main()
{
	double n = 3;
	findSqrt(n);
	return 0;
}
