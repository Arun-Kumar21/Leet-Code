/*
1608. Special Array With X Elements Greater Than or Equal X
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int specialArray(vector<int> &nums)
  {
    std::sort(nums.begin(), nums.end());

    int n = nums.size();
    for (int x = 0; x <= n; ++x)
    {
      // Count how many numbers are greater than or equal to x
      int count = 0;
      for (int i = 0; i < n; ++i)
      {
        if (nums[i] >= x)
        {
          count = n - i; // All remaining numbers are >= x
          break;
        }
      }
      if (count == x)
      {
        return x;
      }
    }

    return -1;
  }
};