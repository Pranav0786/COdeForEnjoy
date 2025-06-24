// Leetcode 115

#include<bits/stdc++.h>
using namespace std;
#define ll long long


// recursion solution
class Solution {
public:
    int solve( int i , int j , string &s , string &t )
    {
        if( j < 0 ) return 1 ;
        if( i < 0 ) return 0 ;
        if( s[i] == t[j] ) return solve( i-1 , j-1 , s , t ) + solve(i-1 , j , s , t ) ;
        return solve(i-1 , j , s , t ) ;
    }
    int numDistinct(string s, string t) {
        int n = s.size() ;
        int m = t.size() ;
        return solve( n-1 , m-1 , s , t ) ;
    }
};


// memoization solution
class Solution {
public:
    int solve( int i , int j , string &s , string &t , vector<vector<int>> &dp )
    {
        if( j < 0 ) return 1 ;
        if( i < 0 ) return 0 ;
        if( dp[i][j] != -1 ) return dp[i][j] ; 
        if( s[i] == t[j] ) return dp[i][j] = solve( i-1 , j-1 , s , t ,dp) + solve(i-1 , j , s , t ,dp) ;
        return dp[i][j] = solve(i-1 , j , s , t ,dp ) ;
    }
    int numDistinct(string s, string t) {
        int n = s.size() ;
        int m = t.size() ;
        vector<vector<int>>dp(n , vector<int>(m,-1)) ;
        return solve( n-1 , m-1 , s , t , dp) ;
    }
};


// tabulation solution
class Solution {
public:
    unsigned long long numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(m + 1, 0));

        for (int i = 0; i <= n; i++) dp[i][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[n][m];
    }
};



// space optimization solution
class Solution {
public:
    unsigned long long numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<unsigned long long> prev(m + 1, 0), curr(m + 1, 0);
        prev[0] = 1;
        for (int i = 1; i <= n; i++) 
        {
            curr[0] = 1; // empty t is always subsequence of any s[0..i]
            for (int j = m; j >= 1; j--) 
            {
                if (s[i - 1] == t[j - 1])
                    curr[j] = prev[j - 1] + prev[j];
                else
                    curr[j] = prev[j];
            }
            prev = curr;
        }

        return prev[m];
    }
};



