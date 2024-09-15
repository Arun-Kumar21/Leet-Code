/*
You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.
*/

// Greedy Approach

#include <iostream>
#include <vector>
#include "../../../usr/include/c++/11/bits/algorithmfwd.h"
using namespace std;

class Solution
{
public:
  int numRescueBoats(std::vector<int> &people, int limit)
  {
    sort(people.begin(), people.end());

    int boats = 0;
    int i = 0;                 // lightest person
    int j = people.size() - 1; // heaviest person

    while (i <= j)
    {

      if (people[i] + people[j] <= limit)
      {
        i++; // Lightest person can go with the heaviest
      }

      // Heaviest person alone will always go in a boat
      j--;

      boats++; // increase one boat
    }

    return boats;
  }
};

/*
Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)
*/