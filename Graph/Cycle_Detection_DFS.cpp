#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool dfs(int node, int parent, vector<int> adj[], vector<int> &vis)
  {
    vis[node] = 1;
    for (auto neighbor : adj[node])
    {
      if (!vis[neighbor])
      {
        if (dfs(neighbor, node, adj, vis))
        {
          return true;
        }
        else if (neighbor != parent)
        {
          return true;
        }
      }
    }
  }

  bool isCycle(int V, vector<int> adj[])
  {
    vector<int> vis(V, 0);

    for (int i = 0; i < V; i++)
    {
      if (!vis[i])
      {
        if (dfs(i, -1, adj, vis))
          return true;
      }
    }
  }
};

void addEdge(vector<int> adj[], int u, int v)
{
  adj[u].push_back(v);
  adj[v].push_back(u);
}

int main()
{
  int V = 5;
  vector<int> adj[V];

  // Construct graph
  addEdge(adj, 0, 1);
  addEdge(adj, 1, 2);
  addEdge(adj, 2, 3);
  addEdge(adj, 3, 4);
  // addEdge(adj, 4, 1); // Uncomment to add a cycle

  Solution obj;
  if (obj.isCycle(V, adj))
    cout << "Cycle Detected\n";
  else
    cout << "No Cycle\n";

  return 0;
}