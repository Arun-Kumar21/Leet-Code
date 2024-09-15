/*
Q260. Single Number III
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> singleNumber(vector<int> &nums)
  {
    int txor = 0;
    for (int num : nums)
      txor ^= num;

    unsigned int mask = txor & -(unsigned int)txor;

    vector<int> res(2, 0);

    for (int num : nums)
    {
      if ((num & mask) == 0)
        res[0] ^= num;
      else
        res[1] ^= num;
    }

    return res;
  }
};
