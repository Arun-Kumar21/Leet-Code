/*
Q1863. Sum of All Subset XOR Totals
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // time complexity -> O(2^n)
  int findXORofTotal(vector<int> &nums, int index, int XOR)
  {
    // base case
    if (index == nums.size())
      return XOR;

    int pick = findXORofTotal(nums, index + 1, XOR ^ nums[index]);
    int nopick = findXORofTotal(nums, index + 1, XOR);

    return nopick + pick;
  }

  int subsetXORSum(vector<int> &nums)
  {
    return findXORofTotal(nums, 0, 0);
  }

  /*
    Second approach
  */

  // time complexity -> O(N)
  int MostOptimiseWay(vector<int> &nums)
  {
    int totalXor = 0;

    // fixing the bit values
    for (int element : nums)
    {
      totalXor = totalXor | element;
    }

    // since each element occur in 2^n/2 subsets, multiplying set digit with (2^n)/2
    return totalXor << (nums.size() - 1);
  }
};

/*
Input: nums = [1,3]
Output: 6
Explanation: The 4 subsets of [1,3] are:
- The empty subset has an XOR total of 0.
- [1] has an XOR total of 1.
- [3] has an XOR total of 3.
- [1,3] has an XOR total of 1 XOR 3 = 2.
0 + 1 + 3 + 2 = 6
*/