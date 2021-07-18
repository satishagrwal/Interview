/*
Given an array arr[] of length N and an integer X, the task is to find the number of subsets with a sum equal to X.

Examples: 

Input: arr[] = {1, 2, 3, 3}, X = 6 
Output: 3 
All the possible subsets are {1, 2, 3}, 
{1, 2, 3} and {3, 3}
 

Input: arr[] = {1, 1, 1, 1}, X = 1 
Output: 4 
*/

#include <bits/stdc++.h> 

using namespace std;
// Function to return the required count 
int findCnt(int *arr, int required_sum, int n) 
{
   int matrix[n+1][required_sum+1];
   
   matrix[0][0] = 1;
   
   for(int i =1 ; i <= required_sum; i++)
   {
      matrix[0][i] = 0;    
   }
   
   for(int j =1; j <= n; j++)
   {
      matrix[j][0] = 1;    
   }
   
   for(int i = 1; i <= n; i++)
   {
       for(int j = 1; j <= required_sum; j++)
       {
           if(arr[i-1] > j)
           {
               matrix[i][j] = matrix[i-1][j];
           }
           else
           {
               matrix[i][j] = matrix[i-1][j] + matrix[i-1][j -arr[i-1]];
           }
       }
   }
   
   return matrix[n][required_sum];
   
} 

int main() 
{ 
    int arr[] = { 1, 2, 3, 3 }; 
    int n = sizeof(arr) / sizeof(int); 
    int x = 6; 
  
    printf("Count=%d",findCnt(arr, x, n)); 
  
    return 0; 
} 
