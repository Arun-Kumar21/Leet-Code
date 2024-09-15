/*
The Tribonacci sequence Tn is defined as follows:

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int tribonacci(int n)
  {
    if (n == 0)
      return 0;
    else if (n == 1 || n == 2)
      return 1;

    // Initialize a vector to store the Tribonacci sequence
    vector<int> tribonacci_sequence(n + 1);
    tribonacci_sequence[0] = 0;
    tribonacci_sequence[1] = 1;
    tribonacci_sequence[2] = 1;

    // Fill the vector using dynamic programming
    for (int i = 3; i <= n; ++i)
    {
      tribonacci_sequence[i] = tribonacci_sequence[i - 1] + tribonacci_sequence[i - 2] + tribonacci_sequence[i - 3];
    }

    // Return the nth term of the Tribonacci sequence
    return tribonacci_sequence[n];
  }
};

/*
Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
*/