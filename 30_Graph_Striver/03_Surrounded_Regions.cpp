// Leetcode 130


#include<bits/stdc++.h>
using namespace std;
#define ll long long


class Solution {
public:
    void dfs( int i , int j , vector<vector<int>>&vis , vector<vector<char>>& mat )
    {
        vis[i][j] = 1 ;
        int n = mat.size() , m = mat[0].size() ;
        int delrow[] = {-1,0,+1,0} ;
        int delcol[] = {0,+1,0,-1} ;
        for( int k = 0 ; k < 4 ; k++ )
        {
            int nrow = i + delrow[k] ;
            int ncol = j + delcol[k] ;
            if( nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 'O' )
                dfs(nrow, ncol , vis , mat ) ;
        } 
    }
    void solve(vector<vector<char>>& mat) {
        int n = mat.size() ;
        int m = mat[0].size() ;
        vector<vector<int>> vis( n ,vector<int>(m,0)) ;
        for( int i = 0 ; i < n ; i++ )
        {
            for( int j = 0 ; j < m ; j++ )
            {
                if( i == 0 || j == 0 || i == n-1 || j == m-1 )
                {
                    if( mat[i][j] == 'O' && !vis[i][j] ) 
                    {
                        dfs(i,j,vis,mat) ;
                    }
                }
            }
        }
        for( int i = 0 ; i < n ; i++ )
        {
            for( int j = 0 ; j < m ; j++ )
            {
                if( mat[i][j] == 'O' && !vis[i][j] ) 
                    mat[i][j] = 'X' ;
            }
        }
    }
};


