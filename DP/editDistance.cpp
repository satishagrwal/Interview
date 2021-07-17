/*
Given two words word1 of length m and word2 of length n.
find the minimum number of operations required to convert
word1 to word2 in Time and Space Complexity O(mn). 

We have the following 3 operations permitted on a word:

1. Insert a character 
2. Delete a character
3. Replace a character

Example:

Input:

word1 = "horse"
word2 = "ros"

Output: 3

Explanation:

horse -> rorse (replace h with r)
rorse -> rose (remove r)
rose -> ros (remove e)

*/

#include <bits/stdc++.h> 
using namespace std; 
  
// function to find the minimum of three numbers 
int min(int x, int y, int z) 
{ 
    return min(min(x, y), z); 
} 
  
int editDistanceProblem(string str1, string str2, int m, int n) 
{ 
    // Create a table to store results 
    int matrix[m + 1][n + 1]; 
  
    // Fill matrix[][] in bottom up manner 
    for (int i = 0; i <= m; i++)\
    { 
        for (int j = 0; j <= n; j++) 
        { 
            // If first string is empty, only option is to 
            // insert all characters of second string 
            if (i == 0)
            {
                matrix[i][j] = j; // Min. operations = j 
            }
            // If second string is empty, only option is to 
            // remove all characters of second string 
            else if (j == 0)
            {
                matrix[i][j] = i; // Min. operations = i 
            }
            // If last characters are same, ignore last char 
            // and recur for remaining string 
            else if (str1[i - 1] == str2[j - 1])
            {
                matrix[i][j] = matrix[i - 1][j - 1]; 
            }
            // If the last character is different, consider all 
            // possibilities and find the minimum 
            else
            {
                matrix[i][j] = 1 + min(matrix[i][j - 1], // Insert 
                                   matrix[i - 1][j], // Remove 
                                   matrix[i - 1][j - 1]); // Replace 
            }
        } 
    }
    return matrix[m][n]; 
} 
  

int main() 
{ 
    string str1 = "sunday"; 
    string str2 = "saturday"; 
  
    cout << editDistanceProblem(str1, str2, str1.length(), str2.length()); 
  
    return 0; 
} 
