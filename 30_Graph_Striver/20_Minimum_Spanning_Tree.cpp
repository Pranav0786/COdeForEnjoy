#include<bits/stdc++.h>
#define ll long long
using namespace std;

// prims algorithm
class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue<pair<int,int>,
        vector<pair<int,int>>, greater<pair<int,int>>> pq ;
        vector<int> vis(V,0) ;
        int sum = 0 ;
        pq.push({0,0}) ;  // wt , node
        while( !pq.empty() ) {
            int node = pq.top().second ;
            int wt = pq.top().first ;
            pq.pop() ;
            if( vis[node] == 1 ) continue ;
            vis[node] = 1 ;
            sum += wt ;
            for( auto i : adj[node] ){
                int adjNode = i[0] ;
                int d = i[1] ;
                if( !vis[adjNode] ){
                    pq.push({d,adjNode}) ;
                }
            }
        }
        return sum ;
    }
};


// kruskals algorithm
class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        
    }
};