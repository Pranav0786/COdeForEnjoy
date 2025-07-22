// Leetcode 1334

#include<bits/stdc++.h>
#define ll long long
using namespace std;


class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dis(n , vector<int>(n,INT_MAX)) ;
        for( auto i : edges) {
            int j = i[0] , k = i[1] , w = i[2] ;
            dis[j][k] = w ; dis[k][j] = w ;  
        }
        for( int i = 0 ; i < n ; i++) 
            dis[i][i] = 0 ;
        for( int k = 0 ; k < n ; k++ ){
            for( int i = 0 ; i < n ; i++ ){
                for( int j = 0 ; j < n ; j++ ){
                    if( dis[i][k] == INT_MAX || dis[k][j] == INT_MAX ) 
                        continue ;
                    dis[i][j] = min( dis[i][j] , dis[i][k] + dis[k][j] ) ;
                }
            }
        }
        int ans = n+1 ;
        int city = -1 ;
        for( int i = 0 ; i < n ; i++ ){
            int ct = 0 ;
            for( int j = 0 ; j < n ; j++ ){
                if( dis[i][j] <= distanceThreshold ){
                    ct++ ;
                }
            }
            if( ct <= ans ){
                ans = ct ;
                city = i ;
            }
        }
        return city ;
    }
};

