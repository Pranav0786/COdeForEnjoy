// gfg

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    void toposort(int node, vector<pair<int, int>> adj[], int vis[], stack<int> &st)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            int v = it.first;
            if (!vis[v])
                toposort(v, adj, vis, st);
        }
        st.push(node);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>> &edges)
    {
        vector<pair<int, int>> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u = edges[i][0], v = edges[i][1], d = edges[i][2];
            adj[u].push_back({v, d});
        }
        // find toposort
        int vis[V] = {0};
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                toposort(i, adj, vis, st);
        }

        // do dist
        vector<int> dis(V, INT_MAX);
        dis[0] = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (dis[node] != INT_MAX)
            {
                for (auto i : adj[node])
                {
                    int v = i.first;
                    int d = i.second;
                    if (dis[node] + d < dis[v])
                        dis[v] = dis[node] + d;
                }
            }
        }
        for (int i = 0; i < V; i++)
        {
            if (dis[i] == INT_MAX)
                dis[i] = -1;
        }
        return dis;
    }
};



