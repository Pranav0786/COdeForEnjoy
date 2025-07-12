#include <bits/stdc++.h>
using namespace std;
#define ll long long

// bfs
class Solution
{
public:
    bool detect(int src, vector<vector<int>> &adj, int vis[])
    {
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});
        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for (auto i : adj[node])
            {
                if (!vis[i])
                {
                    vis[i] = 1;
                    q.push({i, node});
                }
                else if (parent != i)
                    return true;
            }
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);
        for (auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int vis[V] = {0};
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (detect(i, adj, vis))
                    return true;
            }
        }
        return false;
    }
};

// dfs
class Solution
{
public:
    bool detect(int node, int parent, vector<vector<int>> &adj, int vis[])
    {
        vis[node] = 1;
        for (auto i : adj[node])
        {
            if (!vis[i])
            {
                if (detect(i, node, adj, vis))
                    return true; // propagate true
            }
            else if (i != parent)
                return true;
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);
        for (auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int vis[V] = {0};
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (detect(i, -1, adj, vis))
                    return true; // pass -1 as parent for root
            }
        }
        return false;
    }
};



