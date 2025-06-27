// Leetcode 1547


#include<bits/stdc++.h>
using namespace std;
#define ll long long


// recursion solution
class Solution {
public:
    int solve( int i  , int j , vector<int>&cuts )
    {
        if( i > j ) return 0 ;
        int mini = 1e8 ;
        for( int idx = i ; idx <= j ; idx++ )
        {
            int cost = cuts[j+1] - cuts[i-1] + solve(i,idx-1,cuts) + solve(idx+1 , j , cuts) ;
            mini = min( mini , cost) ;
        }
        return mini ;

    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0) ;
        cuts.push_back(n) ;
        sort( cuts.begin() , cuts.end() ) ;
        return solve( 1 , cuts.size()-2 , cuts ) ;
    }
};




// memoization solution
class Solution {
public:
    int solve( int i  , int j , vector<int>&cuts , vector<vector<int>>&dp )
    {
        if( i > j ) return 0 ;
        if( dp[i][j] != -1 ) return dp[i][j] ;
        int mini = 1e8 ;
        for( int idx = i ; idx <= j ; idx++ )
        {
            int cost = cuts[j+1] - cuts[i-1] + solve(i,idx-1,cuts,dp) + solve(idx+1 , j , cuts,dp) ;
            mini = min( mini , cost) ;
        }
        return dp[i][j] =  mini ;

    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0) ;
        cuts.push_back(n) ;
        sort( cuts.begin() , cuts.end() ) ;
        vector<vector<int>> dp( cuts.size() , vector<int>( cuts.size() , -1) ) ;
        return solve( 1 , cuts.size()-2 , cuts , dp ) ;
    }
};




// tabulation solution
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));

        for (int len = 2; len < m; len++) {
            for (int i = 0; i + len < m; i++) {
                int j = i + len;
                int mini = 1e8;
                for (int idx = i + 1; idx < j; idx++) {
                    int cost = cuts[j] - cuts[i] + dp[i][idx] + dp[idx][j];
                    mini = min(mini, cost);
                }
                dp[i][j] = mini;
            }
        }
        return dp[0][m - 1];
    }
};





