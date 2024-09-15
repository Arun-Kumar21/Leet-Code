/*
Q78. Subset
*/

#include <bits/stdc++.h>
using namespace std;

#include <vector>
using namespace std;

class Solution
{
public:
  vector<vector<int>> subsets(vector<int> &nums)
  {
    vector<vector<int>> result;
    vector<int> subset;
    findSubsets(nums, subset, 0, result);
    return result;
  }

private:
  void findSubsets(vector<int> &nums, vector<int> &subset, int index, vector<vector<int>> &result)
  {
    // Add the current subset to the result
    result.push_back(subset);

    // Iterate through the remaining elements
    for (int i = index; i < nums.size(); ++i)
    {
      // Include the current element in the subset
      subset.push_back(nums[i]);

      // Recurse with the next index
      findSubsets(nums, subset, i + 1, result);

      // Backtrack by removing the last element
      subset.pop_back();
    }
  }
};

/*
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/