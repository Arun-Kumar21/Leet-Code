/*
Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
  bool increasingTriplet(vector<int> &nums)
  {
    int first = INT_MAX, second = INT_MAX;

    for (int num : nums)
    {
      if (num <= first)
      {
        // first storing first shortest element of vector
        first = num;
      }

      else if (num <= second)
      {
        // second store second shortest element of vector
        second = num;
      }

      else
      {
        // We found a number greater than both first and second
        return true;
      }
    }

    return false;
  }
};

/*
Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.
*/