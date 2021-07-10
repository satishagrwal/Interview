/*
Set S consists of numbers of the form 2P*3Q, where P and Q are non-negative integers.
Sequence A contains the elements of set S in ascending order. The first few elements 
of A are:

A[0] = 1
A[1] = 2
A[2] = 3
A[3] = 4
A[4] = 6
A[5] = 8
A[6] = 9 
A[7] = 12
A[8] = 16
A[9] = 18
 
 A function 
 int solution(int N);
 
 that, given a non-negative integer N, returns the value A[N].
 Example, given N=4 the function should return 6.
 
 Assume that:
  N is an integer within the range [0..200]
*/

#include <iostream>
#include<math.h>
#include<vector>
using namespace std;

bool check(int n)
{
	int maximum = -1;

	while (!(n % 2))
	{
		maximum = max(maximum, 2);
		n = n/2;
	}

	for (int i = 3; i <= sqrt(n); i += 2)
	{
		while (n % i == 0)
		{
			maximum = max(maximum,i);
			n = n / i;
		}
	}

	if (n > 2)
	{
		maximum = max(maximum, n);
	}
	
	return (maximum <= 3);
}

int solution(int N)
{
    std::vector<int> g;
    
    for(int count = 1; count <=200; count++ )
    {
        if(check(count))
        {
          g.push_back(count);    
        }
    }
    
    std::cout << g[N] << std::endl;
}

int main()
{
	solution(4);
	return 0;
}
