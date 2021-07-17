/*
Given two character array1 and array2, find the length of the longest common substring.

Example:

Input : 
array1 = “zxabcdezy”
array2 = “yzabcdezx”

Common: abcdez

Output :
Length of LCS is 6.

*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// Function to find Longest common substring of sequences
// X[0..m-1] and Y[0..n-1]
int LCS(char *array1, char *array2, int m, int n)
{
	//Write your code here
	if(m == 0 || n == 0)
    {
      return 0;
    }
  
    int matrix[m + 1][n + 1];  
    int i, j;  
    int max = 0;  
    /* Following steps build matrix[m+1][n+1] in  
       bottom up fashion. 
       Note that matrix[i][j] contains length of LCS of array1[0..i-1] 
       and array2[0..j-1] */
    for (i = 0; i <= m; i++)  
    {  
       for (j = 0; j <= n; j++)  
       {  
          if (i == 0 || j == 0) 
          {
            matrix[i][j] = 0;  
          }
          else if (array1[i - 1] == array2[j - 1])
          {
            matrix[i][j] = matrix[i - 1][j - 1] + 1;  

            if(max < matrix[i][j])
            {
                max = matrix[i][j];
            }
          }
          else
          {
             matrix[i][j] = 0; 
          }
       }  
    }
    return max;  
}

int main()  
{  
    char array1[] = "zxabcdezy";  
    char array2[] = "yzabcdezx";  
      
    int m = strlen(array1);  
    int n = strlen(array2);  
      
    cout << "Length of LCS is " 
         << LCS( array1, array2, m, n );  
      
    return 0;  
}  
