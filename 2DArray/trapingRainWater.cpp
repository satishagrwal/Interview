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
    return o;
  
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
