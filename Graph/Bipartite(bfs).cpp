#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // BFS function to check bipartite for a component
  bool bfsCheck(int start, vector<vector<int>> &graph, vector<int> &color)
  {
    queue<int> q;
    q.push(start);
    color[start] = 0; // Start with color 0

    while (!q.empty())
    {
      int node = q.front();
      q.pop();

      for (int neighbor : graph[node])
      {
        if (color[neighbor] == -1)
        {
          // Assign alternate color
          color[neighbor] = 1 - color[node];
          q.push(neighbor);
        }
        else if (color[neighbor] == color[node])
        {
          // Same color on adjacent nodes -> not bipartite
          return false;
        }
      }
    }
    return true;
  }

  // Main function to check if the graph is bipartite
  bool isBipartite(vector<vector<int>> &graph)
  {
    int V = graph.size();
    vector<int> color(V, -1); // -1: uncolored, 0 & 1: two colors

    // Traverse each node (to handle disconnected components)
    for (int i = 0; i < V; i++)
    {
      if (color[i] == -1)
      {
        if (!bfsCheck(i, graph, color))
        {
          return false; // If any component is not bipartite
        }
      }
    }

    return true; // Entire graph is bipartite
  }
};

// Example usage
int main()
{
  // Example input from LeetCode
  vector<vector<int>> graph = {
      {1, 2, 3}, // Node 0
      {0, 2},    // Node 1
      {0, 1, 3}, // Node 2
      {0, 2}     // Node 3
  };

  Solution sol;
  bool result = sol.isBipartite(graph);

  if (result)
    cout << "The graph is bipartite." << endl;
  else
    cout << "The graph is NOT bipartite." << endl;

  return 0;
}