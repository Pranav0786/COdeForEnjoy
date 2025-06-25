// Leetcode 122

#include<bits/stdc++.h>
using namespace std;
#define ll long long


// recursion solution
class Solution {
public:
    int solve( int i , bool buy , int n , vector<int>& prices )
    {
        if( i == n ) return 0 ;
        if(buy) 
            return max( -prices[i] + solve(i+1 , false , n ,prices) , solve(i+1 , true , n , prices) ) ;
        return max( prices[i] + solve(i+1, true , n ,prices) , solve(i+1 , false , n , prices) ) ;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ;
        return solve(0 , true , n , prices ) ;
    }
};



// memoization solution
class Solution {
public:
    int solve( int i , bool buy , int n , vector<int>& prices , vector<vector<int>> &dp )
    {
        if( i == n ) return 0 ;
        if (dp[i][buy] != -1) return dp[i][buy];
        if(buy) 
            return dp[i][buy] = max( -prices[i] + solve(i+1 , false , n ,prices,dp) , solve(i+1 , true , n , prices,dp) ) ;
        return dp[i][buy] = max( prices[i] + solve(i+1, true , n ,prices,dp) , solve(i+1 , false , n , prices,dp) ) ;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size() ;
        vector<vector<int>>dp(n , vector<int>(2,-1)) ;
        return solve(0 , true , n , prices , dp) ;
    }
};



// tabulation solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ;
        vector<vector<int>>dp(n+1 , vector<int>(2,0)) ;
        for(int i = n-1 ; i >= 0 ; i--)
        {
            for(int buy = 0 ; buy <= 1 ; buy++)
            {
                if(buy)
                    dp[i][buy] = max( -prices[i] + dp[i+1][0] , dp[i+1][1] ) ;
                else
                    dp[i][buy] = max( prices[i] + dp[i+1][1] , dp[i+1][0] ) ;
            }
        }
        return dp[0][1] ;
    }
};  




// space optimization solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ;
        vector<int> front(2,0) , curr(2,0) ;
        for(int i = n-1 ; i >= 0 ; i--)
        {
            for(int buy = 0 ; buy <= 1 ; buy++)
            {
                if(buy)
                    curr[buy] = max( -prices[i] + front[0] , front[1] ) ;
                else
                    curr[buy] = max( prices[i] + front[1] , front[0] ) ;
            }
            front = curr ;
        }
        return front[1] ;
    }
};  




