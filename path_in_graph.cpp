/*
There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
  bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
  {
    vector<bool> visited(n, false);
    vector<vector<int>> graph(n);

    // Construct the graph
    for (const auto &edge : edges)
    {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }

    stack<int> stack;
    stack.push(source);

    while (!stack.empty())
    {
      int current = stack.top();
      stack.pop();

      if (current == destination)
        return true;

      if (!visited[current])
      {
        visited[current] = true;
        for (int neighbor : graph[current])
        {
          if (!visited[neighbor])
          {
            stack.push(neighbor);
          }
        }
      }
    }

    return false;
  }
};

/*
Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
Output: true
Explanation: There are two paths from vertex 0 to vertex 2:
- 0 → 1 → 2
- 0 → 2
*/