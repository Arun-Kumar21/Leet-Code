/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  void solve(vector<vector<char>> &grid, int i, int j, int m, int n)
  {

    // checking land peice is not out of bound or water on it
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0')
    {
      return;
    }

    grid[i][j] = '0';

    // running dfs for each neighbour of land
    solve(grid, i + 1, j, m, n);
    solve(grid, i, j + 1, m, n);
    solve(grid, i - 1, j, m, n);
    solve(grid, i, j - 1, m, n);
  }

  int numIslands(vector<vector<char>> &grid)
  {

    // Nos. of columns and rows in grid
    int m = grid.size();
    int n = grid[0].size();

    // number of island in grid (initialize with zero)
    int nums = 0;

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
        if (grid[i][j] == '1')
        {
          solve(grid, i, j, m, n);
          nums++;
        }
    }

    return nums;
  }
};

/*
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*/