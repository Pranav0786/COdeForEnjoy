// gfg

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>> &adj, int src)
    {
        int n = adj.size();
        vector<int> dis(n, INT_MAX);
        dis[src] = 0;
        queue<pair<int, int>> q;
        q.push({src, 0});
        while (!q.empty())
        {
            int node = q.front().first;
            int d = q.front().second;
            q.pop();
            for (auto i : adj[node])
            {
                int distance = d + 1;
                if (dis[i] > distance)
                {
                    dis[i] = distance;
                    q.push({i, distance});
                }
            }
        }
        for (auto &i : dis)
        {
            if (i == INT_MAX)
                i = -1;
        }
        return dis;
    }
};