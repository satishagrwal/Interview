/*
Given n non-negative integers representing an elevation map where 
the width of each bar is 1, compute how much water it can trap after raining.

Example:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array 
[0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Input: height = [4,2,0,3,2,5]
Output: 9

*/
#include <bits/stdc++.h>
using namespace std;

int findWater(int arr[], int n)
{
  // To store water, array length should be
  // greater than 2, otherwise it won't trap 
  // water.
  if(n <= 2)
    return 0;
/*
// For every element of the array
for (int i = 1; i < n-1; i++) 
{
   int left = arr[i];
   for (int j=0; j<i; j++)
   {
       left = max(left, arr[j]);
	
	int right = arr[i];
	for (int j=i+1; j<n; j++)
	{
           right = max(right, arr[j]);
	}
		
	// Update the maximum water
	res = res + (min(left, right) - arr[i]); 
     }
*/
	
/*
int left_max = 0, right_max = 0;

// indices to traverse the array
int lo = 0, hi = n - 1;

while (lo <= hi)
{
	if (arr[lo] < arr[hi])
	{
		if (arr[lo] > left_max)
		{
		 	// update max in left
			left_max = arr[lo];
		}
		else
		{
			// water on curr element = max - curr
			res += left_max - arr[lo];
		}
		lo++;
	}
	else
	{
		if (arr[hi] > right_max)
		{
			// update right maximum
			right_max = arr[hi];
		else
		{
			res += right_max - arr[hi];
		}
		hi--;
	}
}
*/
  
   int leftMax[n];
   int rightMax[n];
   int res = 0;
   
   leftMax[0] = arr[0];
   for(int i = 1; i < n; i++)
   {
      leftMax[i] = max(leftMax[i-1], arr[i]);
   }
  
   rightMax[n-1] = arr[n-1];
   for(int i = n-2; i >= 0; i--)
   {
      rightMax[i] = max(rightMax[i+1], arr[i]);
   }
   for(int i = 0; i < n; i++)
   {
     res += min(leftMax[i], rightMax[i]) - arr[i];
   }
  
   return res;
}

int main()
{
	int arr[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Maximum water that can be accumulated is "
		<< findWater(arr, n);
	return 0;
}
