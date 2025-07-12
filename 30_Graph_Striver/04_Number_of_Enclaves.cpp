// Leetcode 1020


#include<bits/stdc++.h>
using namespace std;
#define ll long long


class Solution {
public:
    void dfs( int i , int j , vector<vector<int>> & vis , vector<vector<int>>& grid )
    {
        vis[i][j] = 1 ;
        int n = grid.size() ;
        int m = grid[0].size() ;
        int delrow[] = {-1,0,+1,0} ;
        int delcol[] = {0,+1,0,-1} ;
        for(  int k = 0 ; k < 4 ; k++ )
        {
            int nr = i + delrow[k] ;
            int nc = j + delcol[k] ;
            if( nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == 1 )
                dfs( nr,nc,vis,grid ) ;
        } 
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        vector<vector<int>> vis(n,vector<int>(m,0)) ;
        for( int j = 0 ; j < m ; j++ )
        {
            if( grid[0][j] == 1 && !vis[0][j] ) 
                dfs(0,j,vis,grid) ;
            if( grid[n-1][j] == 1 && !vis[n-1][j] ) 
                dfs(n-1,j,vis,grid) ;
        }
        for( int i = 0 ; i < n ; i++ )
        {
            if( grid[i][0] == 1 && !vis[i][0] ) 
                dfs( i,0,vis,grid) ;
            if( grid[i][m-1] == 1 && !vis[i][m-1] )
                dfs( i , m-1, vis, grid ) ;
        }
        int ans = 0 ;
        for( int i = 0 ; i < n ; i++ )
        {
            for( int j = 0 ; j < m ; j++ )
            {
                if( grid[i][j] == 1 && !vis[i][j] )  ans++ ;
            }
        }
        return ans ;
    }
};


