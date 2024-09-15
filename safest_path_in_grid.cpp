/*
Q2812 Find the Safest path in a grid

!! Important and hard Question
*/

#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution
{
public:
  vector<int> rowDir = {-1, 1, 0, 0};
  vector<int> colDir = {0, 0, 1, -1};

  bool isValid(vector<vector<bool>> &visited, int i, int j)
  {
    if (i < 0 || i >= visited.size() || j < 0 || j >= visited[0].size() || visited[i][j])
    {
      return false;
    }
    return true;
  }

  bool isSafe(vector<vector<int>> &distToThief, int safeDist)
  {
    int m = distToThief.size();
    int n = distToThief[0].size();
    if (distToThief[0][0] < safeDist || distToThief[m - 1][n - 1] < safeDist)
    {
      return false;
    }

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty())
    {
      auto [currRow, currCol] = q.front();
      q.pop();

      if (currRow == m - 1 && currCol == n - 1)
      {
        return true;
      }

      for (int dirIdx = 0; dirIdx < 4; dirIdx++)
      {
        int newRow = currRow + rowDir[dirIdx], newCol = currCol + colDir[dirIdx];
        if (isValid(visited, newRow, newCol) && distToThief[newRow][newCol] >= safeDist)
        {
          visited[newRow][newCol] = true;
          q.push({newRow, newCol});
        }
      }
    }

    return false;
  }

  int maximumSafenessFactor(vector<vector<int>> &grid)
  {
    int m = grid.size();
    int n = grid[0].size();

    queue<pair<int, int>> q;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    vector<vector<int>> distToThief(m, vector<int>(n, -1));

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 1)
        {
          visited[i][j] = true;
          q.push({i, j});
        }
      }
    }

    int len = 0;
    while (!q.empty())
    {
      int qSize = q.size();
      while (qSize--)
      {
        int currRow = q.front().first, currCol = q.front().second;
        q.pop();

        distToThief[currRow][currCol] = len;

        for (int dirIdx = 0; dirIdx < 4; dirIdx++)
        {
          int newRow = currRow + rowDir[dirIdx], newCol = currCol + colDir[dirIdx];
          if (!isValid(visited, newRow, newCol))
            continue;

          visited[newRow][newCol] = true;
          q.push({newRow, newCol});
        }
      }
      len++;
    }

    int low = 0, high = len;
    int ans = 0;

    while (low <= high)
    {
      int mid = low + (high - low) / 2;

      if (isSafe(distToThief, mid))
      {
        ans = mid;
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }

    return ans;
  }
};

/*
Input: grid = [[0,0,0,1],[0,0,0,0],[0,0,0,0],[1,0,0,0]]
Output: 2
Explanation: The path depicted in the picture above has a safeness factor of 2 since:
- The closest cell of the path to the thief at cell (0, 3) is cell (1, 2). The distance between them is | 0 - 1 | + | 3 - 2 | = 2.
- The closest cell of the path to the thief at cell (3, 0) is cell (3, 2). The distance between them is | 3 - 3 | + | 0 - 2 | = 2.
It can be shown that there are no other paths with a higher safeness factor.
*/
