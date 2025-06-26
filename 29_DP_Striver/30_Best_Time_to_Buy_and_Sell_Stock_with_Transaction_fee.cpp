// Leetcode 714

#include<bits/stdc++.h>
using namespace std;
#define ll long long


// recursive solution
class Solution {
public:
    int solve( int i , int buy , int fee , int n , vector<int>&prices ) 
    {
        if( i == n ) return 0 ;
        if(buy)
            return max(-prices[i]+solve(i+1,0,fee,n,prices) , solve(i+1,1,fee,n,prices) ) ;
        return max( prices[i]+solve(i+1,1,fee,n,prices)-fee , solve(i+1,0,fee,n,prices) ) ;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size() ;
        return solve(0,1,fee,n,prices) ;
    }
};


// memoization solution
class Solution {
public:
    int solve( int i , int buy , int fee , int n , vector<int>&prices , vector<vector<int>> &dp ) 
    {
        if( i == n ) return 0 ;
        if( dp[i][buy] != -1 )  return dp[i][buy] ;
        if(buy)
            return dp[i][buy] = max(-prices[i]+solve(i+1,0,fee,n,prices,dp) , solve(i+1,1,fee,n,prices,dp) ) ;
        return dp[i][buy] = max( prices[i]+solve(i+1,1,fee,n,prices,dp)-fee , solve(i+1,0,fee,n,prices,dp) ) ;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size() ;
        vector<vector<int>>dp( n , vector<int>(2,-1) ) ;
        return solve(0,1,fee,n,prices,dp) ;
    }
};




// tabulation solution
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size() ;
        vector<vector<int>>dp( n+1 , vector<int>(2,0) ) ;
        for( int i = n-1 ; i >= 0 ; i-- )
        {
            dp[i][1] = max(-prices[i]+dp[i+1][0] , dp[i+1][1] ) ;
            dp[i][0] = max( prices[i]-fee +dp[i+1][1]  , dp[i+1][0] ) ;
        }
        return dp[0][1] ;
    }
};



// space optimized solution
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size() ;
        vector<int> front(2,0) , curr(2,0) ;
        for( int i = n-1 ; i >= 0 ; i-- )
        {
            curr[1] = max(-prices[i]+front[0] , front[1] ) ;
            curr[0] = max( prices[i]-fee +front[1]  , front[0] ) ;
            front = curr ;
        }
        return curr[1] ;
    }
};