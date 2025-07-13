// gfg


#include<bits/stdc++.h>
#define ll long long
using namespace std ;



class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> dis(n + 1, INT_MAX), parent(n + 1);
        for (int i = 1; i <= n; i++) parent[i] = i;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dis[1] = 0;
        pq.push({0, 1});

        while (!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto& it : adj[node]) {
                int adjNode = it.first;
                int weight = it.second;

                if (dis[adjNode] > wt + weight) {
                    dis[adjNode] = wt + weight;
                    parent[adjNode] = node;
                    pq.push({dis[adjNode], adjNode});
                }
            }
        }

        if (dis[n] == INT_MAX) return {-1};

        vector<int> path;
        for (int v = n; v != parent[v]; v = parent[v]) {
            path.push_back(v);
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        return path;
    }
};





