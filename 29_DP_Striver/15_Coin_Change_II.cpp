// Leetcode 518

#include<bits/stdc++.h>
using namespace std;
#define ll long long


// recursive solution
class Solution {
public:
    int solve( int i , int k , vector<int>& nums ) 
    {
        if (i == 0) 
        {
            if( k % nums[0] == 0 ) return 1;
            else return 0;
        }
        int notPick = solve( i-1 , k , nums ) ;
        int pick = 0 ;
        if( k >= nums[i] ) 
            pick = solve( i , k-nums[i] , nums ) ;
        return pick + notPick ;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size() ;
        return solve( n-1 , amount , coins ) ;
    }
};




// memoization solution
class Solution {
public:
    int solve( int i , int k , vector<int>& nums , vector<vector<int>>&dp ) 
    {
        if (i == 0) 
        {
            if( k % nums[0] == 0 ) return 1;
            else return 0;
        }
        if( dp[i][k] != -1 ) return dp[i][k] ;
        int notPick = solve( i-1 , k , nums , dp ) ;
        int pick = 0 ;
        if( k >= nums[i] ) 
            pick = solve( i , k-nums[i] , nums , dp ) ;
        return dp[i][k] =  pick + notPick ;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size() ;
        vector<vector<int>>dp( n , vector<int>(amount+1 , -1 ) ) ;
        return solve( n-1 , amount , coins , dp ) ;
    }
};



