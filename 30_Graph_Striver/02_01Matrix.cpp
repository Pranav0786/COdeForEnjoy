// leetcode 542


#include<bits/stdc++.h>
using namespace std;
#define ll long long



class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size() , m = mat[0].size() ;   
        vector<vector<int>>vis(n,vector<int>(m,0)) ;
        vector<vector<int>>dis(n,vector<int>(m,0)) ;
        queue<pair<pair<int,int>,int>>q ; 
        for( int i = 0 ; i < n ; i++ )
        {
            for( int j = 0 ; j < m ; j++ )
            {
                if( mat[i][j] == 0 )
                {
                    q.push({{i,j},0}) ; 
                    vis[i][j] = 1 ; 
                }
                else
                    vis[i][j] = 0 ;
            }
        }
        int delrow[] = {-1,0,1,0} ;
        int delcol[] = {0,1,0,-1} ;
        while( !q.empty() )
        {
            auto it = q.front() ; 
            q.pop() ; 
            int x = it.first.first , y = it.first.second , d = it.second ; 
            dis[x][y] = d ; 
            for( int i = 0 ; i < 4 ; i++ )
            {
                int newx = x + delrow[i] , newy = y + delcol[i] ;
                if( newx >= 0 && newx < n && newy >= 0 && newy < m && !vis[newx][newy] )
                {
                    vis[newx][newy] = 1 ; 
                    q.push({{newx,newy},d+1}) ; 
                }
            }
        }
        return dis ;
    }
};


