// leetcode 300

#include<bits/stdc++.h>
using namespace std;
#define ll long long


// memoization solution
class Solution {
public:
    int solve( int i , int prevI, int n , vector<int>&nums , vector<vector<int>>&dp )
    {
        if( i >= n  ) return 0 ;
        if( dp[i][prevI+1] != -1 ) return dp[i][prevI+1] ;
        int nottake = solve( i+1 , prevI , n ,nums ,dp) ;
        int take = 0 ;
        if( prevI == -1 || nums[i] > nums[prevI] ) take = 1 + solve(i+1 , i , n , nums ,dp ) ;
        return dp[i][prevI+1] = max( nottake , take ) ;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size() ;
        vector<vector<int>>dp ( n , vector<int>(n , -1) ) ;
        return solve(0,-1 , n ,nums ,dp) ;
    }
};



