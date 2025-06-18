// Leetcode 120 

#include<bits/stdc++.h>
using namespace std;
#define ll long long

// recursion solution
class Solution {
public:
    int solve( vector<vector<int>>&tri , int m  , int i , int j )
    {
        if( i == m-1 )
            return tri[i][j] ;
        int down = tri[i][j] + solve( tri , m , i+1 , j ) ;
        int dia = tri[i][j] + solve( tri , m , i+1 , j+1 ) ;
        return min( down , dia ) ;
    }
    int minimumTotal(vector<vector<int>>& tri) {
        int m = tri.size() ;
        return solve( tri , m , 0 , 0 ) ;
    }
};


// memoization solution
class Solution {
public:
    int solve( vector<vector<int>>&tri , int m  , int i , int j , vector<vector<int>>&dp )
    {
        if( i == m-1 )
            return tri[i][j] ;
        if( dp[i][j] != -1 )
            return dp[i][j] ;
        int down = tri[i][j] + solve( tri , m , i+1 , j , dp ) ;
        int dia = tri[i][j] + solve( tri , m , i+1 , j+1 , dp ) ;
        return dp[i][j] =  min( down , dia ) ;
    }
    int minimumTotal(vector<vector<int>>& tri) {
        int m = tri.size() ;
        vector<vector<int>>dp(m , vector<int>(m , -1) ) ;
        return solve( tri , m , 0 , 0 , dp ) ;
    }
};


// tabulation solution
class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int m = tri.size() ;
        vector<vector<int>>dp(m , vector<int>(m , 0) ) ;
        for( int j = 0 ; j < m ; j++ )
            dp[m-1][j] = tri[m-1][j] ;
        for( int i = m-2 ; i >= 0 ; i-- )
        {
            for( int j = i ; j >= 0 ; j-- )
            {
                int d = tri[i][j] + dp[i+1][j] ;
                int dg = tri[i][j] + dp[i+1][j+1] ;
                dp[i][j] = min( d , dg ) ;
            }
        }
        return dp[0][0] ;
    }
};



// space optimization solution
class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int m = tri.size() ;
        vector<int>front(m,0) ;
        for( int j = 0 ; j < m ; j++ )
            front[j] = tri[m-1][j] ;
        for( int i = m-2 ; i >= 0 ; i-- )
        {
            vector<int>temp(m,0) ;
            for( int j = i ; j >= 0 ; j-- )
            {
                int d = tri[i][j] + front[j] ;
                int dg = tri[i][j] + front[j+1] ;
                temp[j] = min( d , dg ) ;
            }
            front = temp ;
        }
        return front[0] ;
    }
};



