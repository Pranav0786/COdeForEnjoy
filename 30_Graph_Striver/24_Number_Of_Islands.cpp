// gfg

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
    
    bool isvalide( int i , int j , int n , int m ){
        if( i >= 0 && j >= 0 && i < n  && j < m ) 
            return true ;
        return false ;
    }
    
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n*m) ;
        vector<vector<int>> vis(n , vector<int>(m,0)) ;
        int cnt = 0 ;
        vector<int> ans ;
        for( auto it : operators ){
            int row = it[0] ;
            int col = it[1] ;
            if( vis[row][col] == 1 ){
                ans.push_back(cnt) ;
                continue ;
            }
            vis[row][col] = 1 ;
            cnt++ ;
            int dr[] = {-1,0,+1,0} ;
            int dc[] = {0,+1,0,-1} ;
            for( int i = 0 ; i < 4 ; i++ ){
                int adjRow = row + dr[i] ;
                int adjCol = col + dc[i] ;
                if( isvalide( adjRow , adjCol , n , m )){
                    if( vis[adjRow][adjCol] == 1 ){
                        int nodeNo = row * m + col ;
                        int adjNodeNo = adjRow * m + adjCol ;
                        if( ds.findParent(nodeNo) != ds.findParent(adjNodeNo) ){
                            cnt-- ;
                            ds.UnionBySize(nodeNo , adjNodeNo) ;
                        }
                    }
                }
            }
            ans.push_back(cnt) ;
        }
        
        return ans ;
    }
};



