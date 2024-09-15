/*
Q140. Word Break II
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<string> wordBreak(string s, vector<string> &wordDict)
  {
    vector<string> result;
    for (string w : wordDict)
    {
      if (s.substr(0, w.length()) == w)
      {
        if (w.length() == s.length())
          result.push_back(w);

        // recursively call this function for remaining string
        else
        {
          vector<string> temp = wordBreak(s.substr(w.length()), wordDict);
          for (string t : temp)
            result.push_back(w + " " + t);
        }
      }
    }
    return result;
  }
};