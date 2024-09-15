/*
Q861 Score After Flipping Matrix


You are given an m x n binary matrix grid.

A move consists of choosing any row or column and toggling each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).

Every row of the matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

Return the highest possible score after making any number of moves (including zero moves).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int matrixScore(vector<vector<int>> &grid)
  {
    int m = grid.size();
    int n = grid[0].size();

    // row check
    for (int i = 0; i < m; i++)
    {
      if (grid[i][0] == 0)
      {
        for (int j = 0; j < n; j++)
        {
          grid[i][j] = 1 - grid[i][j];
        }
      }
    }

    // col check
    for (int j = 0; j < n; j++)
    {
      int countZeros = 0, countOne = 0;

      for (int i = 0; i < m; i++)
      {
        if (grid[i][j] == 0)
          countZeros += 1;

        else
        {
          countOne += 1;
        }
      }

      if (countOne > countZeros)
      {
        for (int i = 0; i < m; i++)
          grid[i][j] = 1 - grid[i][j];
      }
    }

    // Calculate the score of the matrix
    int score = 0;
    for (int i = 0; i < m; i++)
    {
      int rowScore = 0;
      for (int j = 0; j < n; j++)
      {
        rowScore = (rowScore << 1) + grid[i][j];
      }
      score += rowScore;
    }

    return score;
  }
};

/*
Input: grid = [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
Output: 39
Explanation: 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
*/