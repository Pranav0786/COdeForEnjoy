// Leetcode 947

#include<bits/stdc++.h>
#define ll long long
using namespace std;


class DisjointSet {
    vector<int> rank , parent , size;
public :
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
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size() ;
        int maxrow = 0 , maxcol = 0 ;
        for( auto it : stones ){
            maxrow = max( maxrow , it[0] ) ;
            maxcol = max( maxcol , it[1] ) ;
        }
        DisjointSet ds( maxrow + maxcol +1  ) ;
        unordered_map<int,int> stoneNodes ;
        for( auto it : stones ){
            int nodeRow = it[0] ;
            int nodeCol = it[1] + maxrow + 1 ;
            ds.UnionBySize(nodeRow , nodeCol) ;
            stoneNodes[nodeRow] = 1 ;
            stoneNodes[nodeCol] = 1 ;
        }

        int cnt = 0 ;
        for( auto it : stoneNodes){
            if( ds.findParent(it.first) == it.first )
                cnt++ ;
        }
        return n - cnt ;
    }
};