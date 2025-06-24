// Leetcode 1143 

#include<bits/stdc++.h>
using namespace std;
#define ll long long


// recursive solution
class Solution {
public:
    int solve( int i1 , int i2 , string &s1 , string &s2 )
    {
        if( i1 < 0 || i2 < 0 ) return 0 ;
        if( s1[i1] == s2[i2] ) return 1 + solve( i1-1 , i2-1 , s1 , s2 ) ;
        return max( solve( i1-1 , i2 , s1 , s2 ) , solve( i1 , i2-1 , s1 , s2 ) ) ;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size() , n2 = text2.size() ;
        return solve( n1-1 , n2-1 , text1 , text2 ) ;
    }
};


// memoization solution
class Solution {
public:
    int solve( int i , int j , string &s1 , string &s2 ,  vector<vector<int>> &dp )
    {
        if( i < 0 || j < 0 ) return 0 ;
        if( dp[i][j] != -1 ) return dp[i][j] ;
        if( s1[i] == s2[j] )  return dp[i][j] = 1 + solve( i-1 , j-1 , s1 , s2 , dp ) ;
        return dp[i][j] = max( solve( i-1 , j , s1 , s2 , dp ) , solve( i , j-1 , s1 , s2 , dp ) ) ;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size() , n2 = text2.size() ;
        vector<vector<int>>dp(n1 , vector<int>(n2,-1)) ;
        return solve( n1-1 , n2-1 , text1 , text2 ,dp ) ;
    }
};



// tabulation solution
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, 0));
        
        dp[0][0] = (s1[0] == s2[0]);
        for (int i = 1; i < n1; i++)
            dp[i][0] = max(dp[i-1][0], int(s1[i] == s2[0]));
        for (int j = 1; j < n2; j++)
            dp[0][j] = max(dp[0][j-1], int(s1[0] == s2[j]));

        for (int i = 1; i < n1; i++) {
            for (int j = 1; j < n2; j++) {
                if (s1[i] == s2[j])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n1-1][n2-1];
    }
};



// space optimized solution
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        vector<int> prev(n2 + 1, 0), curr(n2 + 1, 0);

        for (int j = 0; j < n2; j++)
            prev[j + 1] = (s1[0] == s2[j]) ? 1 : prev[j];

        for (int i = 1; i < n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (s1[i] == s2[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        return prev[n2];
    }
};



