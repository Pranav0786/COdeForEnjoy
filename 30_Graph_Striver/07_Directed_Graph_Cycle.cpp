#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    bool dfs(int i, vector<vector<int>> &adj, vector<int> &vis, vector<int> &path)
    {
        vis[i] = 1;
        path[i] = 1;
        for (auto j : adj[i])
        {
            if (!vis[j])
            {
                if (dfs(j, adj, vis, path) == true)
                    return true;
            }
            else if (path[j] == 1)
                return true;
        }
        path[i] = 0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);
        for (auto &e : edges)
        {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
        }
        vector<int> vis(V, 0), path(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, adj, vis, path) == true)
                    return true;
            }
        }
        return false;
    }
};



