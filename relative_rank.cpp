#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
  vector<string> findRelativeRanks(vector<int> &score)
  {
    priority_queue<pair<int, int>> pq; // Pair of score and its original index

    // Push scores along with their indices into the priority queue
    for (int i = 0; i < score.size(); ++i)
    {
      pq.push({score[i], i});
    }

    vector<string> res(score.size());

    int count = 0;
    while (!pq.empty())
    {
      int sc = pq.top().first;
      int index = pq.top().second;
      pq.pop();

      if (count == 0)
        res[index] = "Gold Medal";
      else if (count == 1)
        res[index] = "Silver Medal";
      else if (count == 2)
        res[index] = "Bronze Medal";
      else
        res[index] = to_string(count + 1);

      ++count;
    }

    return res;
  }
};