/*
Two strings of length m and n. 
Find algorithm the length of their longest common subsequence 
in Time Complexity and Space complexity O(mn).

Example:

ABCDEF
AEDNEK

LCS : ADE
Length: 3

*/

#include<bits/stdc++.h>  
using namespace std; 
  
int max(int a, int b);  
  
/* Returns length of LCS for array1[0..m-1], array2[0..n-1] */
int lcs( char *array1, char *array2, int m, int n ) 
{  
    if(m == 0 || n == 0)
    {
      return 0;
    }
  
    int matrix[m + 1][n + 1];  
    int i, j;  
      
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
          }
          else
          {
            matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);  
          }
       }  
    }  
          
    /* matrix[m][n] contains length of LCS  
    for array1[0..n-1] and array2[0..m-1] */
    return matrix[m][n];  
}  

int max(int a, int b)  
{  
    return (a > b)? a : b;  
}  
  
 
int main()  
{  
    char array1[] = "ABCDEF";  
    char array2[] = "AEDNEK";  
      
    int m = strlen(array1);  
    int n = strlen(array2);  
      
    cout << "Length of LCS is " 
         << lcs( array1, array2, m, n );  
      
    return 0;  
}  
