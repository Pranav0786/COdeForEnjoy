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


