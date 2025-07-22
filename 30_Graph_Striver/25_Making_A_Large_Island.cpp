// Leetcode 827

#include<bits/stdc++.h>
#define ll long long
using namespace std;



class DisjointSet {
public :
    vector<int> rank , parent , size;
    DisjointSet(int n ) {
        rank.resize(n + 1 , 0) ;
        parent.resize(n+1) ;
        size.resize(n+1 , 1) ;
        for( int i = 0 ; i<= n ; i++ )
            parent[i] = i ;
    }
    int findParent( int node ){
        if( node == parent[node] ) return node ;
        return parent[node] = findParent( parent[node]) ; 
    }
    void UnionByRank(int u , int v ){
        int ultp_u = findParent(u) ;
        int ultp_v = findParent(v) ;
        if( ultp_u == ultp_v ) return ;
        if( rank[ultp_u] < rank[ultp_v]){
            parent[ultp_u] = ultp_v ;
        }
        else if( rank[ultp_v] < rank[ultp_u] ){
            parent[ultp_v] = ultp_u ;
        }
        else {
            parent[ultp_v] = ultp_u ;
            rank[ultp_u]++ ;
        }
    }
    void UnionBySize(int u , int v ){
        int ultp_u = findParent(u) ;
        int ultp_v = findParent(v) ;
        if( ultp_u == ultp_v ) return ;
        if( size[ultp_u] < size[ultp_v] ){
            parent[ultp_u] = ultp_v ;
            size[ultp_v] += size[ultp_u] ;
        }
        else {
            parent[ultp_v] = ultp_u ;
            size[ultp_u] += size[ultp_v] ;
        }
    }
} ;



class Solution {
    bool isvalide( int newr , int newc , int n ){
        return newr >= 0 && newr < n && newc >= 0 && newc < n ;
    }
    
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size() ;
        DisjointSet ds(n*n) ;
        for( int row = 0 ; row < n ; row++ ){
            for( int col = 0 ; col < n ; col++ ){
                if( grid[row][col] == 0 ) continue ;
                int dr[] = {-1,0,+1,0} ;
                int dc[] = {0,+1,0,-1} ;
                for( int i = 0 ; i < 4 ; i++ ){
                    int newr = row + dr[i] ;
                    int newc = col + dc[i] ;
                    if( isvalide(newr , newc , n ) && grid[newr][newc] == 1 ){
                        int nodeNo = row * n + col ;
                        int adjNodeNo = newr * n + newc ;
                        ds.UnionBySize(nodeNo , adjNodeNo) ;
                    }
                }
            }
        }

        int mx = 0 ;
        for( int row = 0 ; row < n ; row++ ){
            for( int col = 0 ; col < n ; col++ ){
                if( grid[row][col] == 1 ) continue ;
                int dr[] = {-1,0,+1,0} ;
                int dc[] = {0,+1,0,-1} ;
                set<int>components ;
                for( int i = 0 ; i < 4 ; i++ ){
                    int newr = row + dr[i] ;
                    int newc = col + dc[i] ;
                    if( isvalide(newr , newc , n )  ){
                        if( grid[newr][newc] == 1 ){
                            components.insert(ds.findParent(newr * n + newc)) ;
                        }
                    }
                }
                int totalsize = 0 ;
                for( auto it : components ){
                    totalsize += ds.size[it] ;
                }
                mx = max( mx , totalsize +1) ;
            }
        }
        
        for( int cellNo = 0 ; cellNo < n*n ; cellNo++ ){
            mx = max( mx , ds.size[ds.findParent(cellNo)]) ;
        }
        return mx ;
    }
};


