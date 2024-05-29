/*
Q1404. Number of Steps to Reduce a Number in Binary Representation to One
*/

#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int numSteps(string s)
  {
    int steps = 0;
    while (s != "1")
    {
      if (s.back() == '0')
      {
        // If the last character is '0', divide by 2 (remove the last character)
        s.pop_back();
      }
      else
      {
        // If the last character is '1', add 1
        int i = s.size() - 1;
        while (i >= 0 && s[i] == '1')
        {
          s[i] = '0';
          i--;
        }
        if (i >= 0)
        {
          s[i] = '1';
        }
        else
        {
          // If all bits were '1', we need to add a '1' at the front
          s.insert(s.begin(), '1');
        }
      }
      steps++;
    }
    return steps;
  }
};
