// Leetcode 72

#include<bits/stdc++.h>
using namespace std;
#define ll long long


// recursion solution
class Solution {
public:

    int solve( int i , int j , string &a , string &b ) 
    {
        if( i < 0 ) return j+1 ;
        if( j < 0 ) return i+1 ; 
        if( a[i] == b[j] ) return solve(i-1 , j-1 , a, b ) ;
        int in = 1 + solve(i , j-1,a,b) ;
        int de = 1 + solve(i-1 , j ,a,b ) ;
        int re = 1 + solve( i-1 , j-1 , a, b ) ;
        return min( {in,re,de} ) ;
    }
    int minDistance(string w1, string w2) {
        int n = w1.size() , m = w2.size() ;
        return solve(n-1,m-1, w1,w2 ) ;
    }
};



// memoization solution
class Solution {
public:

    int solve( int i , int j , string &a , string &b ,  vector<vector<int>>& dp ) 
    {
        if( i < 0 ) return j+1 ;
        if( j < 0 ) return i+1 ; 
        if( dp[i][j] != -1 ) return dp[i][j] ;
        if( a[i] == b[j] ) return dp[i][j] = solve(i-1 , j-1 , a, b ,dp) ;
        int in = 1 + solve(i , j-1,a,b ,dp ) ;
        int de = 1 + solve(i-1 , j ,a,b , dp ) ;
        int re = 1 + solve( i-1 , j-1 , a, b , dp ) ;
        return dp[i][j] = min( {in,re,de} ) ;
    }
    int minDistance(string w1, string w2) {
        int n = w1.size() , m = w2.size() ;
        vector<vector<int>>dp(n , vector<int>(m,-1)) ;
        return solve(n-1,m-1, w1,w2 , dp) ;
    }
};




// tabulation solution
class Solution {
public:

    int minDistance(string a, string b) {
        int n = a.size() , m = b.size() ;
        vector<vector<int>>dp(n+1 , vector<int>(m+1,0)) ;
        for( int i = 0 ; i <= n ; i++ ) dp[i][0] = i ;
        for( int j = 0 ; j  <= m ; j++ ) dp[0][j] = j ;
        for( int i = 1 ; i <= n ; i++ )
        {
            for( int j = 1 ; j <= m ; j++ )
            {
                if( a[i-1] == b[j-1] ) dp[i][j] = dp[i-1][j-1] ;
                else
                {
                    int in = 1 + dp[i][j-1] ;
                    int de = 1 + dp[i-1][j]  ;
                    int re = 1 + dp[i-1][j-1] ;
                    dp[i][j] = min( {in,re,de} ) ;
                }
            }
        }
        return dp[n][m] ;
    }
};




// space optimized solution
class Solution {
public:

    int minDistance(string a, string b) {
        int n = a.size() , m = b.size() ;
        vector<int> prev(m+1,0) , curr(m+1,0) ;
        for( int j = 0 ; j  <= m ; j++ ) prev[j] = j ;
        for( int i = 1 ; i <= n ; i++ )
        {
            curr[0] = i ;
            for( int j = 1 ; j <= m ; j++ )
            {
                if( a[i-1] == b[j-1] ) curr[j] = prev[j-1] ;
                else
                {
                    int in = 1 + curr[j-1] ;
                    int de = 1 + prev[j]  ;
                    int re = 1 + prev[j-1] ;
                    curr[j] = min( {in,re,de} ) ;
                }
            }
            prev = curr ;
        }
        return prev[m] ;
    }
};


