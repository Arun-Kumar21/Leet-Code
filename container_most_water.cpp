/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.
*/

#include <iostream>
#include <vector>
using namespace std;

// sliding window concept

class Solution
{
public:
  int maxArea(vector<int> &height)
  {
    int area = 0, left = 0, right = height.size() - 1;
    while (left != right)
    {
      int currentArea = min(height[left], height[right]) * (right - left);

      if (height[left] > height[right])
      {
        right--;
      }

      else
      {
        left++;
      }

      area = max(currentArea, area);
    }

    return area;
  }
};

/*
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
*/