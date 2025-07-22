// gfg

#include<bits/stdc++.h>
#define ll long long
using namespace std;


class Solution {
  public:
    int timer = 0 ;
    void dfs( int node , int parent , vector<int>&vis , vector<int> adj[] , vector<int>&low , vector<int>&tin , vector<int>&mark){
        vis[node] = 1 ;
        tin[node] = low[node] = timer ;
        timer++ ;
        int child = 0 ;
        for (auto it : adj[node] ){
            if( it == parent) continue ;
            if(!vis[it]){
                dfs(it,node , vis,adj,low,tin,mark) ;
                low[node] = min( low[node] , low[it] ) ;
                if( low[it] >= tin[node] && parent != -1 ){
                    mark[node] = 1 ;
                }
                child++ ;
            }
            else {
                low[node] = min( low[node] , low[it] ) ; 
            }
        }
        if( child > 1 && parent == -1 )
            mark[node] = 1 ;
    }
    vector<int> articulationPoints(int n, vector<int> adj[]) {
        vector<int>vis(n,0) ;
        vector<int>tin(n) , low(n) , mark(n,0); 
        for( int i = 0 ; i < n ; i++ ){
            if( !vis[i] ) {
                dfs(i,-1,vis,adj ,low,tin,mark) ;
            }
        }
        vector<int> ans ;
        for( int i= 0 ; i < n ; i++ ){
            if( mark[i] ){
                ans.push_back(i) ;
            }
        }
        if( ans.size() == 0 ) return {-1} ;
        return ans ;
    }
};