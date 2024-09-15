/*
You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  void dfs(vector<vector<int>> &grid, int i, int j, int &perimeter, int m, int n)
  {

    // if island is out of bound of grid or water then return
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
    {
      perimeter++;
      return;
    }

    // if there is no more unvisited land then return
    else if (grid[i][j] == -1)
    {
      return;
    }

    // make visited land piece -1 (dfs not stuck in loop)
    grid[i][j] = -1;

    // running dfs for each neighbour of land
    dfs(grid, i, j + 1, perimeter, m, n);
    dfs(grid, i + 1, j, perimeter, m, n);
    dfs(grid, i - 1, j, perimeter, m, n);
    dfs(grid, i, j - 1, perimeter, m, n);
  }

  int islandPerimeter(vector<vector<int>> &grid)
  {

    // Nos. of columns and rows in grid
    int m = grid.size();
    int n = grid[0].size();

    int perimeter = 0;

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
      {
        // Finding first land piece
        if (grid[i][j] == 1)

          // Visiting all land pieces connected with first land piece
          dfs(grid, i, j, perimeter, m, n);
      }
    return perimeter;
  }
};

/*

Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.

*/