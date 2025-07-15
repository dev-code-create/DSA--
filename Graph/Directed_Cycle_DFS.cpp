#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfsVis)
  {
    vis[node] = 1;
    dfsVis[node] = 1;

    for (auto neighbor : adj[node])
    {
      if (!vis[neighbor])
      {
        if (dfs(neighbor, adj, vis, dfsVis))
          return true;
      }
      else if (dfsVis[neighbor])
      {
        return true;
      }
    }
    dfsVis[node] = 0;
    return false;
  }

  bool isCyclic(int V, vector<int> adj[])
  {
    vector<int> vis(V, 0), dfsVis(V, 0);
    for (int i = 0; i < V; i++)
    {
      if (!vis[i])
      {
        if (dfs(i, adj, vis, dfsVis))
          return true;
      }
    }
    return false;
  }
};

void addEdge(vector<int> adj[], int u, int v)
{
  adj[u].push_back(v);
}

int main()
{
  int V = 4;
  vector<int> adj[V];

  addEdge(adj, 0, 1);
  addEdge(adj, 1, 2);
  addEdge(adj, 2, 3);

  Solution obj;
  if (obj.isCyclic(V, adj))
  {
    cout << "Cycle Detection\n";
  }
  else
  {
    cout << "No Cycle";
  }
  return 0;
}