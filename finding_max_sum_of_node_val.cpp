/*
3068. Find the Maximum Sum of Node Values
*/

#include <bits/stdc++.h>
using namespace std;

// using dynamic programming
#include <vector>
using namespace std;

class Solution
{
public:
  vector<long long> dp;

  long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges)
  {
    int n = nums.size();
    dp.resize(edges.size());

    long long maxSum = 0;
    for (int i = 0; i < n; i++)
    {
      maxSum += nums[i];
    }

    for (int i = 0; i < edges.size(); i++)
    {
      vector<int> temp = nums;
      for (int j = 0; j < edges[i].size(); j++)
      {
        int u = edges[i][j]; // vertex connected by the edge
        temp[u] ^= k;        // Apply XOR operation to the vertex separately
      }

      long long sum = 0;
      for (int j = 0; j < temp.size(); j++)
      {
        sum += temp[j];
      }

      dp[i] = sum;
    }

    for (int i = 0; i < dp.size(); i++)
    {
      maxSum = max(maxSum, dp[i]);
    }

    return maxSum;
  }
};

//!! not a correct solution