// Leetcode  1631


#include<bits/stdc++.h>
#define ll long long
using namespace std ;


class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h ) {
        int n = h.size() ;
        int m = h[0].size() ;
        queue<pair<int,pair<int,int>>> q ; // d ,{i,j}
        vector<vector<int>>vis(n , vector<int>(m, INT_MAX) ) ;
        vis[0][0] = 0 ;
        q.push({0,{0,0}}) ;
        int dx[] = {0,1,0,-1} ;
        int dy[] = {-1,0,1,0} ;
        while( !q.empty() ) {
            int d = q.front().first ;
            int i = q.front().second.first ;
            int j = q.front().second.second ;
            q.pop() ;
            for( int k = 0 ; k < 4 ; k++ ){
                int nx = i+dx[k] , ny = j+dy[k] ;
                if( nx >= 0 && ny >= 0 && nx < n && ny < m ){
                    int diff = abs( h[nx][ny] - h[i][j] ) ;
                    diff = max( diff , d ) ;
                    if( vis[nx][ny] > diff ){
                        vis[nx][ny] = diff ;
                        q.push({diff , {nx,ny}}) ;
                    }
                }
            }
        }
        return vis[n-1][m-1] ;
    }
};


