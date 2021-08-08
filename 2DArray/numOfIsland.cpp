/*
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) 
connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid
are surrounded by water.
The area of an island is the number of cells with a value 1 in the island.
Return the maximum area of an island in grid. If there is no island, return 0.

Input:
          M = [[0,0,1,0,0,0,0,1,0,0,0,0,0],
               [0,0,0,0,0,0,0,1,1,1,0,0,0],
               [0,1,1,0,1,0,0,0,0,0,0,0,0],
               [0,1,0,0,1,1,0,0,1,0,1,0,0],
               [0,1,0,0,1,1,0,0,1,1,1,0,0],
               [0,0,0,0,0,0,0,0,0,0,1,0,0],
               [0,0,0,0,0,0,0,1,1,1,0,0,0],
               [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.
*/
#include <bits/stdc++.h>
using namespace std;

// Function to do DFS for a 2D
// boolean matrix. It only considers
// the 4 neighbours as adjacent vertices
void DFS(vector<vector<int>> &M, int i, int j, int ROW,
		int COL)
{
	if (i < 0 || j < 0 || i > (ROW - 1) || j > (COL - 1) || M[i][j] != 1)
	{
		return;
	}

	if (M[i][j] == 1)
	{
    // Marking as visited
		M[i][j] = 2;
    
		DFS(M, i + 1, j, ROW, COL);	 //right side traversal
		DFS(M, i - 1, j, ROW, COL);	 //left side traversal
		DFS(M, i, j + 1, ROW, COL);	 //upward side traversal
		DFS(M, i, j - 1, ROW, COL);	 //downward side traversal
	}
}

int countIslands(vector<vector<int>> &M)
{
	int ROW = M.size();
	int COL = M[0].size();
	int count = 0;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (M[i][j] == 1)
			{
				count++;
				DFS(M, i, j, ROW, COL);	 
			}
		}
	}
	return count;
}

int main()
{
	vector<vector<int>> M = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                             {0,0,0,0,0,0,0,1,1,1,0,0,0},
                             {0,1,1,0,1,0,0,0,0,0,0,0,0},
                             {0,1,0,0,1,1,0,0,1,0,1,0,0},
                             {0,1,0,0,1,1,0,0,1,1,1,0,0},
                             {0,0,0,0,0,0,0,0,0,0,1,0,0}, 
                             {0,0,0,0,0,0,0,1,1,1,0,0,0},
                             {0,0,0,0,0,0,0,1,1,0,0,0,0}};

	cout << "Number of islands is: " << countIslands(M);
	return 0;
}
