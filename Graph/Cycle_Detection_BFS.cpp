#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool detectCycle(int src, vector<int> adj[], vector<int> &vis)
  {
    queue<pair<int, int>> q;
    vis[src] = 1;
    q.push({src, -1});

    while (!q.empty())
    {
      int node = q.front().first;
      int parent = q.front().second;
      q.pop();
      for (auto neighbor : adj[node])
      {
        if (!vis[neighbor])
        {
          vis[neighbor] = 1;
          q.push({neighbor, node});
        }
        else if (neighbor != parent)
        {
          return true;
        }
      }
    }
    return false;
  }

  bool isCycle(int V, vector<int> adj[])
  {
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
      if (!vis[i])
      {
        if (detectCycle(i, adj, vis))
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
  addEdge(adj, 0, 1);
  addEdge(adj, 1, 2);
  addEdge(adj, 2, 3);
  addEdge(adj, 3, 4);

  Solution obj;
  if (obj.isCycle(V, adj))
  {
    cout << "Cycle Detected/n";
  }
  else
  {
    cout << "No cycle";
  }

  return 0;
}