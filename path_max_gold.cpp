/*
Q1219 Path with Maximum Gold

!! NOT OTPIMISE;
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{

  // declaring rows and cols as global var, so they available for every function
  int rows, cols;

public:
  int getMaximumGold(vector<vector<int>> &grid)
  {
    rows = grid.size();
    cols = grid[0].size();

    vector<vector<int>> visited(rows, vector<int>(cols, 0));

    // storing total gold
    int totalGold = 0;
    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
      {
        totalGold += grid[i][j];
      }
    }

    int maxGold = 0;

    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
      {
        maxGold = max(maxGold, dfs(grid, visited, i, j));
        if (maxGold == totalGold)
        {
          return maxGold;
        }
      }
    }
    return maxGold;
  }

  int dfs(vector<vector<int>> &grid, vector<vector<int>> &visited, int row, int col)
  {
    // check for out of bound , visited and zero gold conditions
    if (row >= rows || col >= cols || visited[row][col] == 1 || grid[row][col] == 0)
    {
      return 0;
    }

    visited[row][col] = 1;

    int maxGold = 0;
    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    for (int i = 0; i < 4; i++)
    {
      int nextRow = row + dir[i][0];
      int nextCol = col + dir[i][1];
      if (nextRow >= 0 && nextRow < rows && nextCol >= 0 && nextCol < cols)
      {
        maxGold = max(maxGold, dfs(grid, visited, nextRow, nextCol));
      }
    }

    visited[row][col] = 0;

    return grid[row][col] + maxGold;
  }
};

/*
Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
Output: 28
Explanation:
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.
*/