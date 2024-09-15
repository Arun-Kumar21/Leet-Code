/*
Q1219 Path with Maximum Gold
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // rows and cols in grid vector;
  int m, n;
  vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
  int DFS(vector<vector<int>> &grid, int i, int j)
  {

    if (i >= m || i < 0 || j >= n || j < 0 || grid[i][j] == 0)
    {
      return 0; // Zero gold
    }

    int cellGold = grid[i][j];
    grid[i][j] = 0;

    int maxGold = 0;

    // up, down, left, right
    for (vector<int> &dir : directions)
    {
      int new_i = i + dir[0];
      int new_j = j + dir[1];

      maxGold = max(maxGold, DFS(grid, new_i, new_j));
    }

    grid[i][j] = cellGold;
    return cellGold + maxGold;
  }

  int getMaximumGold(vector<vector<int>> &grid)
  {
    m = grid.size();
    n = grid[0].size();

    int maxGold = 0;

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {

        if (grid[i][j] != 0)
        {
          // It has gold
          maxGold = max(maxGold, DFS(grid, i, j));
        }
      }
    }

    return maxGold;
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