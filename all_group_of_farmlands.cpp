/*
You are given a 0-indexed m x n binary matrix land where a 0 represents a hectare of forested land and a 1 represents a hectare of farmland.

To keep the land organized, there are designated rectangular areas of hectares that consist entirely of farmland. These rectangular areas are called groups. No two groups are adjacent, meaning farmland in one group is not four-directionally adjacent to another farmland in a different group.

land can be represented by a coordinate system where the top left corner of land is (0, 0) and the bottom right corner of land is (m-1, n-1). Find the coordinates of the top left and bottom right corner of each group of farmland. A group of farmland with a top left corner at (r1, c1) and a bottom right corner at (r2, c2) is represented by the 4-length array [r1, c1, r2, c2].

Return a 2D array containing the 4-length arrays described above for each group of farmland in land. If there are no groups of farmland, return an empty array. You may return the answer in any order.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  void dfs(vector<vector<int>> &land, int i, int j, vector<int> &boundaries)
  {
    int m = land.size();
    int n = land[0].size();

    if (i < 0 || i >= m || j < 0 || j >= n || land[i][j] != 1)
    {
      return;
    }

    // Mark the cell as visited
    land[i][j] = -1;

    // Update boundaries
    boundaries[0] = min(boundaries[0], i); // minRow
    boundaries[1] = min(boundaries[1], j); // minCol
    boundaries[2] = max(boundaries[2], i); // maxRow
    boundaries[3] = max(boundaries[3], j); // maxCol

    // Perform DFS in all four directions
    dfs(land, i - 1, j, boundaries); // Up
    dfs(land, i + 1, j, boundaries); // Down
    dfs(land, i, j - 1, boundaries); // Left
    dfs(land, i, j + 1, boundaries); // Right
  }

  vector<vector<int>> findFarmland(vector<vector<int>> &land)
  {
    int m = land.size();
    int n = land[0].size();
    vector<vector<int>> result;

    for (int i = 0; i < m; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        if (land[i][j] == 1)
        {
          // Initialize boundaries
          vector<int> boundaries = {i, j, i, j};

          // Perform DFS to find the boundaries of the farmland group
          dfs(land, i, j, boundaries);

          // Add the group's boundaries to the result
          result.push_back(boundaries);
        }
      }
    }

    return result;
  }
};

/*
Input: land = [[1,0,0],[0,1,1],[0,1,1]]
Output: [[0,0,0,0],[1,1,2,2]]
Explanation:
The first group has a top left corner at land[0][0] and a bottom right corner at land[0][0].
The second group has a top left corner at land[1][1] and a bottom right corner at land[2][2]
*/