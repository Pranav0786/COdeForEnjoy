// Leetcode 44

#include<bits/stdc++.h>
using namespace std;
#define ll long long


// recursion solution
class Solution {
public:
    bool solve(int i, int j, string &s, string &p) {
        if (i < 0 && j < 0) return true;
        if (i < 0 && j >= 0) return false;
        if (i >= 0 && j < 0) {
            for (int k = 0; k <= i; k++) {
                if (p[k] != '*') return false;
            }
            return true;
        }

        if (p[i] == s[j] || p[i] == '?') return solve(i - 1, j - 1, s, p);
        if (p[i] == '*') return solve(i - 1, j, s, p) || solve(i, j - 1, s, p);
        return false;
    }

    bool isMatch(string s, string p) {
        int n = p.size(), m = s.size();
        return solve(n - 1, m - 1, s, p);
    }
};




// memoization solution
class Solution {
public:
    bool solve(int i, int j, string &s, string &p, vector<vector<int>>&dp) {
        if (i < 0 && j < 0) return true;
        if (i < 0 && j >= 0) return false;
        if (i >= 0 && j < 0) {
            for (int k = 0; k <= i; k++) {
                if (p[k] != '*') return false;
            }
            return true;
        }
        if( dp[i][j] != -1 ) return dp[i][j] ;
        if (p[i] == s[j] || p[i] == '?') return dp[i][j] =  solve(i - 1, j - 1, s, p,dp);
        if (p[i] == '*') return dp[i][j] = solve(i - 1, j, s, p ,dp ) || solve(i, j - 1, s, p,dp) ;
        return dp[i][j] =  false;
    }

    bool isMatch(string s, string p) {
        int n = p.size(), m = s.size();
        vector<vector<int>>dp(n , vector<int>(m,-1)) ;
        return solve(n - 1, m - 1, s, p,dp);
    }
};




// tabulation solution
class Solution {
public:

    bool isMatch(string s, string p) {
        int n = p.size(), m = s.size();
        vector<vector<bool>>dp(n+1 , vector<bool>(m+1,false)) ;
        dp[0][0] = true ;
        // Handle pattern vs empty string (s is empty)
        for (int i = 1; i <= n; i++) {
            if (p[i - 1] == '*')
                dp[i][0] = dp[i - 1][0];
        }
        
        for( int i =1 ; i<= n ; i++ )
        {
            for( int j = 1 ; j<= m ; j++ )
            {
                if (p[i-1] == s[j-1] || p[i-1] == '?') dp[i][j] =  dp[i - 1][j - 1] ;
                else if (p[i-1] == '*')  dp[i][j] = dp[i - 1][j] || dp[i][j - 1] ;
            }
        }
        return dp[n][m] ;
    }
};





// space optimized solution
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.size(), m = s.size();
        vector<bool> prev(m + 1, false), curr(m + 1, false);

        prev[0] = true;

        for (int i = 1; i <= n; i++) {
            curr[0] = true;
            for (int k = 0; k < i; k++) {
                if (p[k] != '*') {
                    curr[0] = false;
                    break;
                }
            }

            for (int j = 1; j <= m; j++) {
                if (p[i - 1] == s[j - 1] || p[i - 1] == '?') {
                    curr[j] = prev[j - 1];
                } else if (p[i - 1] == '*') {
                    curr[j] = prev[j] || curr[j - 1];
                } else {
                    curr[j] = false;
                }
            }

            prev = curr;
        }

        return prev[m];
    }
};





