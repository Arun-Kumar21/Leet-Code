/*
Q1442. Count Triplets That Can Form Two Arrays of Equal XOR
*/

#include <bits/stdc++.h>
using namespace std;

/*
O(n^3)

class Solution
{
public:
  int countTriplets(vector<int> &arr)
  {
    int N = arr.size();
    int res = 0;

    for (int i = 0; i < N; i++)
    {
      int a = 0;
      for (int j = i + 1; j < N; j++)
      {
        a ^= arr[j - 1];
        int b = 0;
        for (int k = j; k < N; k++)
        {
          b ^= arr[k];

          if (a == b)
            res += 1;
        }
      }
    }
    return res;
  }
};

*/

// O(n^2)

class Solution
{
public:
  int countTriplets(vector<int> &arr)
  {
    int N = arr.size();
    int res = 0;

    for (int i = 0; i < N; i++)
    {
      int curr_XOR = arr[i];

      for (int k = i + 1; k < N; k++)
      {
        curr_XOR ^= arr[k];

        if (curr_XOR == 0)
          res += k - i;
      }
    }

    return res;
  }
};