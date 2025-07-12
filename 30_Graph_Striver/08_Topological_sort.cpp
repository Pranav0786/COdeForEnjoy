
#include<bits/stdc++.h>
using namespace std;
#define ll long long



class Solution {
  public:   
    void dfs( int i , vector<int>&vis , vector<vector<int>> &adj , stack<int>&st )
    {
        vis[i] = 1 ;
        for( auto j : adj[i] )
        {
            if( !vis[j] ) 
                dfs( j , vis , adj , st ) ;
        }
        st.push(i) ;
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V) ;
        for( int i = 0 ; i < edges.size() ; i++ )
        {
            int u = edges[i][0] , v = edges[i][1] ;
            adj[u].push_back(v) ;
        }
        stack<int>st ;
        vector<int>vis(V,0) ;
        for( int i = 0 ; i<V ; i++ )
        {
            if(!vis[i]) 
                dfs( i , vis , adj , st) ;
        }
        vector<int> ans ;
        while( !st.empty() ) 
        {
            ans.push_back( st.top() ) ;
            st.pop() ;
        }
        return ans ;
    }
};


