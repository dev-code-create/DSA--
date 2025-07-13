#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void dfs(int node, vector<int> adj[], int vis[], vector<int> &result)
  {
    vis[node] = 1;
    result.push_back(node);

    for (auto neighbour : adj[node])
    {
      if (!vis[neighbour])
      {
        dfs(neighbour, adj, vis, result);
      }
    }
  }

  vector<int> dfsOfGraph(int V, vector<int> adj[])
  {
    int vis[V] = {0};
    vector<int> result;
    dfs(0, adj, vis, result);
    return result;
  };
};

// helper function
void addEdge(vector<int> adj[], int u, int v)
{
  adj[u].push_back(v);
  adj[v].push_back(u);
}

void printResult(vector<int> &res)
{
  for (int x : res)
  {
    cout << x << " ";
  }
  cout << endl;
}

int main()
{
  vector<int> adj[6];
  addEdge(adj, 0, 1);
  addEdge(adj, 1, 2);
  addEdge(adj, 1, 3);
  addEdge(adj, 0, 4);

  Solution obj;
  vector<int> result = obj.dfsOfGraph(5, adj);
  printResult(result);
  return 0;
}