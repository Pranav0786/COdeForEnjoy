// Leetcode 416

#include<bits/stdc++.h>
using namespace std;
#define ll long long


// recursion solution
class Solution {
public:

    bool solve( int i , int k , vector<int>&nums )
    {
        if( i == 0 ) return k == 0 ;
        if( k == 0 )
            return true ;
        bool notPick = solve( i-1 , k , nums ) ;
        bool pick = false ;
        if( k >= nums[i] ) 
            pick = solve( i-1 , k-nums[i] , nums ) ;
        return pick || notPick ;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size() ;
        int sum = 0 ;
        for( int i = 0 ; i < n ; i++ )
            sum += nums[i] ;
        if( sum %2 != 0 )
            return false ;
        int k = sum / 2 ;
        
        return solve( n-1 , k , nums ) ;
    }
};



// memoization solution
class Solution {
public:

    bool solve( int i , int k , vector<int>&nums , vector<vector<int>>&dp )
    {
        if( k == 0 ) return true ;
        if( i == 0 ) return nums[0] == 0 ;
        if( dp[i][k] != -1 ) return dp[i][k] ;

        bool notPick = solve( i-1 , k , nums , dp ) ;
        bool pick = false ;
        if( k >= nums[i] ) 
            pick = solve( i-1 , k-nums[i] , nums , dp ) ;
        return dp[i][k] = pick || notPick ;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size() ;
        int sum = 0 ;
        for( int i = 0 ; i < n ; i++ )
            sum += nums[i] ;
        if( sum %2 != 0 )
            return false ;
        int k = sum / 2 ;
        vector<vector<int>>dp( n , vector<int>(k+1 , -1) ) ;
        return solve( n-1 , k , nums , dp ) ;
    }
};



// tabulation solution
class Solution {
public:

    bool canPartition(vector<int>& nums) {
        int n = nums.size() ;
        int sum = 0 ;
        for( int i = 0 ; i < n ; i++ )
            sum += nums[i] ;
        if( sum %2 != 0 )
            return false ;
        
        int k = sum / 2 ;
        vector<vector<bool>>dp( n , vector<bool>(k+1 , 0) ) ;
        for( int i = 0 ; i < n ; i++ )
            dp[i][0] = true ;
        if( nums[0] <= k )
            dp[0][nums[0]] = true ;
        for( int i = 1 ; i < n  ;i++ )
        {
            for( int j = 1 ; j <= k ; j++ )
            {
                bool notPick = dp[i-1][j] ;
                bool pick = false ;
                if( j >= nums[i] ) 
                    pick = dp[i-1][j-nums[i]] ;
                dp[i][j] = pick || notPick ;
            }
        }
        return dp[n-1][k] ;
    }
};




// space optimization solution
class Solution {
public:

    bool canPartition(vector<int>& nums) {
        int n = nums.size() ;
        int sum = 0 ;
        for( int i = 0 ; i < n ; i++ )
            sum += nums[i] ;
        if( sum %2 != 0 )
            return false ;
        
        int k = sum / 2 ;
        vector<bool> prev(k+1, 0) , curr(k+1 ,0) ;
        for( int i = 0 ; i < n ; i++ )
            prev[0] = true ;
        if( nums[0] <= k )
            prev[nums[0]] = true ;
        for( int i = 1 ; i < n  ;i++ )
        {
            for( int j = 1 ; j <= k ; j++ )
            {
                bool notPick = prev[j] ;
                bool pick = false ;
                if( j >= nums[i] ) 
                    pick = prev[j-nums[i]] ;
                curr[j] = pick || notPick ;
            }
            prev = curr ;
        }
        return prev[k] ;
    }
};



