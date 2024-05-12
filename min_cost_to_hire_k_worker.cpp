/*
Q857 Minimum Cost to Hire 7 Workers
*/

// Not Optimised

#include <bits/stdc++.h>
using namespace std;

double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
{
  int n = quality.size();
  // vector to store a pair of wage-to-quality ratio ans quality
  vector<pair<double, int>> workers;
  double ans = numeric_limits<double>::max();
  for (int i = 0; i < n; i++)
  {
    // populating workers
    workers.push_back({static_cast<double>(wage[i]) / quality[i], quality[i]});
  }
  // sorting the workers vector to start with minimum wage-to-worker ratio
  sort(workers.begin(), workers.end());
  // Initialising sum of all the Qualities of selected workers with zero
  int sumQuality = 0;
  // maxHeap to maintain k-selected workers with their quality respectively
  priority_queue<int> kLowest;
  for (auto &worker : workers)
  {
    double ratio = worker.first;
    int quality = worker.second;
    // updating sum of qualities
    sumQuality += quality;
    // pushing quality of the worker in max-heap
    kLowest.push(quality);
    // whenever size of max-heap exceeds k , maximum of qualities gets removed
    if (kLowest.size() > k)
    {
      // sumQuality also needs to be updated
      sumQuality -= kLowest.top();
      kLowest.pop();
    }
    if (kLowest.size() == k)
    {
      // update ans with ratio(The rate of unit of quality)*sumQuality
      ans = min(ans, ratio * sumQuality);
    }
  }
  return ans;
}

int main()
{
  vector<int> quality = {3, 1, 10, 10, 1};
  vector<int> wage = {4, 8, 2, 2, 7};
  double ans = mincostToHireWorkers(quality, wage, 3);
  cout << ans;
  return 0;
}