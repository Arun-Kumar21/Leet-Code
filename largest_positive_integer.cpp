/*
Given an integer array nums that does not contain any zeros, find the largest positive integer k such that -k also exists in the array.

Return the positive integer k. If there is no such integer, return -1.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
  int findMaxK(vector<int> &nums)
  {
    unordered_set<int> numSet(nums.begin(), nums.end());
    int maxK = -1;

    for (int num : nums)
    {
      // finding opposite of the num
      if (num > 0 && numSet.find(-num) != numSet.end())
      {
        // setting maximum num to max K
        maxK = max(maxK, num);
      }
    }

    return maxK != -1 ? maxK : -1;
  }
};

/*
Input: nums = [-1,10,6,7,-7,1]
Output: 7
Explanation: Both 1 and 7 have their corresponding negative values in the array. 7 has a larger value.
*/