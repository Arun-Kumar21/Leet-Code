/*
Q1208. Get Equal Substrings Within Budget
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int equalSubstring(string s, string t, int maxCost)
  {
    int left = 0, right = 0;
    int currentCost = 0;
    int maxLength = 0;

    while (right < s.size())
    {
      // Calculate the cost to change s[right] to t[right]
      currentCost += abs(s[right] - t[right]);

      // If the current cost exceeds maxCost, shrink the window from the left
      while (currentCost > maxCost)
      {
        currentCost -= abs(s[left] - t[left]);
        left++;
      }

      // Update the maximum length of the window
      maxLength = max(maxLength, right - left + 1);
      right++;
    }

    return maxLength;
  }
};
