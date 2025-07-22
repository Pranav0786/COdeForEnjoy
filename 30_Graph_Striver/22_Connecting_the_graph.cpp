// gfg


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
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        DisjointSet ds(n) ;
        int cntExtras = 0 ;
        for( auto i : edge ){
            int u = i[0] ;
            int v = i[1] ;
            if( ds.findParent(u) == ds.findParent(v) ) {
                cntExtras++ ;
            } else {
                ds.UnionBySize(u,v) ;
            }
        }
        int cntComp = 0 ;
        for( int i = 0 ; i < n ; i++ ){
            if( ds.parent[i] == i ) cntComp++ ;
        }
        int reqEdges = cntComp -1 ;
        if( reqEdges <= cntExtras )
            return reqEdges ;
        return -1 ;
    }
};


