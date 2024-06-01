/*
Q3110. Score of a String
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int scoreOfString(string s)
  {
    int score = 0;

    for (int i = 0; i < s.length() - 1; i++)
    {
      // score += abs(int(s[i]) - int(s[i + 1]));

      int a = s[i];
      int b = s[i + 1];

      if (a > b)
      {
        score += a - b;
      }
      else
      {
        score += b - a;
      }
    }
    return score;
  }
};

int main()
{
  Solution mysol;
  string s = "hello";

  int ans = mysol.scoreOfString(s);

  cout << ans;
  return 0;
}