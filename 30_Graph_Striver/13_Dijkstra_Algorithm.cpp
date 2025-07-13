#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {
        vector<vector<vector<int>>> adj(V);
        for (auto i : edges)
        {
            int u = i[0], v = i[1], w = i[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        set<pair<int, int>> st; // {distance, node}
        vector<int> dis(V, INT_MAX);
        dis[src] = 0;
        st.insert({0, src});

        while (!st.empty())
        {
            auto it = *st.begin();
            st.erase(st.begin());
            int node = it.second;
            int wt = it.first;

            for (auto &i : adj[node])
            {
                int node1 = i[0];
                int d = i[1];

                if (dis[node1] > d + wt)
                {
                    if (dis[node1] != INT_MAX)
                    {
                        st.erase({dis[node1], node1});
                    }
                    dis[node1] = d + wt;
                    st.insert({dis[node1], node1});
                }
            }
        }
        return dis;
    }
};
