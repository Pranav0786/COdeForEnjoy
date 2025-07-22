// Leetcode 721

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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size() ;
        unordered_map<string,int>mapMailNode ;
        DisjointSet ds(n) ;
        for( int i = 0 ; i < n ; i++ ){
            for( int j =1 ; j < accounts[i].size() ; j++ ){
                string mail = accounts[i][j] ;
                if( mapMailNode.find(mail) == mapMailNode.end() ) 
                    mapMailNode[mail] = i ;
                else
                    ds.UnionBySize(i , mapMailNode[mail]) ;
            }
        }
        vector<vector<string>> mergeMail(n) ;
        for( auto it : mapMailNode ){
            string mail = it.first ;
            int node = ds.findParent(it.second) ;
            mergeMail[node].push_back(mail) ;
        }
        vector<vector<string>> ans ;
        for( int i = 0 ; i < n ; i++ ){
            if( mergeMail[i].size() == 0 ) continue ;
            sort(mergeMail[i].begin() , mergeMail[i].end() ) ;
            vector<string> temp ;
            temp.push_back(accounts[i][0]) ;
            for( auto it : mergeMail[i] )
                temp.push_back(it) ;
            ans.push_back(temp) ;
        }
        return ans ;
    }
};


