/*
Q786 Kth Smallest Prime Freaction
*/

#include <iostream>
#include <vector>
#include "../../../usr/include/c++/11/bits/algorithmfwd.h"
using namespace std;

class Solution
{
public:
  vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
  {
    vector<pair<float, pair<int, int>>> fract;

    // Populate the fract vector
    for (int j = arr.size() - 1; j >= 0; --j)
    {
      for (int i = 0; i < arr.size(); ++i)
      {
        float fraction = static_cast<float>(arr[i]) / arr[j];
        fract.push_back({fraction, {arr[i], arr[j]}});
      }
    }

    // Sort the fract vector based on the fraction
    sort(fract.begin(), fract.end());

    // Access the kth smallest prime fraction
    vector<int> res(2, 0);
    res[0] = fract[k - 1].second.first;  // Adjust index since k is 1-based
    res[1] = fract[k - 1].second.second; // Adjust index since k is 1-based

    return res;
  }
};

/*
Input: arr = [1,2,3,5], k = 3
Output: [2,5]
Explanation: The fractions to be considered in sorted order are:
1/5, 1/3, 2/5, 1/2, 3/5, and 2/3.
The third fraction is 2/5.
*/