// Leetcode 1976

#include<bits/stdc++.h>
#define ll long long
using namespace std;


class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto &i : roads) {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }

        vector<long long> dis(n, LLONG_MAX), path(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        dis[0] = 0;
        path[0] = 1;
        pq.push({0, 0});

        int mod = 1e9 + 7;

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dis[node]) continue;

            for (auto &[adjnode, wt] : adj[node]) {
                long long newDist = d + wt;
                if (newDist == dis[adjnode]) {
                    path[adjnode] = (path[adjnode] + path[node]) % mod;
                } 
                else if (newDist < dis[adjnode]) {
                    dis[adjnode] = newDist;
                    path[adjnode] = path[node];
                    pq.push({newDist, adjnode});
                }
            }
        }

        return path[n - 1];
    }
};


