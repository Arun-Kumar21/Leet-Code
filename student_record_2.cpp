/*
Q552. Student Attendance Record II
*/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

class Solution
{
public:
  long long dp[100001][3][3];

  long long solve(int n, int absentCount, int consecLateCount)
  {
    // base case
    if (n == 0)
      return 1;

    if (dp[n][absentCount][consecLateCount] != -1)
    {
      return dp[n][absentCount][consecLateCount];
    }

    long long ans = 0;

    // P today
    ans = (solve(n - 1, absentCount, 0)) % mod;

    // Absent today
    if (absentCount < 1)
      ans = (ans + solve(n - 1, absentCount + 1, 0)) % mod;

    // Late today
    if (consecLateCount < 2)
      ans = (ans + solve(n - 1, absentCount, consecLateCount + 1)) % mod;

    return dp[n][absentCount][consecLateCount] = ans % mod;
  }

  int checkRecord(int n)
  {
    memset(dp, -1, sizeof(dp));
    return solve(n, 0, 0);
  }
};