// Leetcode 516

#include<bits/stdc++.h>
using namespace std;
#define ll long long


// recursive solution
class Solution {
public:

    int solve( int i , int j , string &s1 , string &s2 )
    {
        if( i < 0 || j < 0 ) return 0 ;
        if( s1[i] == s2[j] ) return 1 + solve( i-1 , j-1 , s1 , s2 ) ;
        return max( solve( i-1 , j , s1 , s2) , solve( i , j-1 , s1 , s2 ) ) ;
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size() ;
        string s2 = s ;
        reverse( s2.begin() , s2.end() ) ;
        return solve( n-1 , n-1 , s , s2 ) ;
    }
};


// memoization solution
class Solution {
public:

    int solve( int i , int j , string &s1 , string &s2 ,vector<vector<int>>&dp )
    {
        if( i < 0 || j < 0 ) return 0 ;
        if( dp[i][j] != -1) return dp[i][j] ;
        if( s1[i] == s2[j] ) return dp[i][j] = 1 + solve( i-1 , j-1 , s1 , s2 , dp) ;
        return dp[i][j] = max( solve( i-1 , j , s1 , s2 , dp ) , solve( i , j-1 , s1 , s2 , dp ) ) ;
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size() ;
        string s2 = s ;
        reverse( s2.begin() , s2.end() ) ;
        vector<vector<int>>dp(n , vector<int>(n , -1) ) ;
        return solve( n-1 , n-1 , s , s2 , dp ) ;
    }
};


// tabulation solution
class Solution {
public:
    int longestPalindromeSubseq(string s1) {
        int n = s1.size();
        string s2 = s1;
        reverse(s2.begin(), s2.end());

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n][n];
    }
};




// space optimized solution
class Solution {
public:
    int longestPalindromeSubseq(string s1) {
        int n = s1.size();
        string s2 = s1;
        reverse(s2.begin(), s2.end());

        vector<int>prev(n+1 , 0 ) , curr(n+1 , 0 ) ;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr ;
        }

        return prev[n];
    }
};


