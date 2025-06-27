// Leetcode 1043


#include<bits/stdc++.h>
using namespace std;
#define ll long long


// recursion solution
class Solution {
public:
    int solve(  int i , int k , int n ,vector<int>&arr )
    {
        if( i == n ) return 0 ;
        int len = 0 ;
        int maxi = -1e8 ;
        int maxAns = -1e8 ;
        for( int j = i ; j < min(i+k , n) ; j++ )
        {
            len++ ;
            maxi = max( maxi , arr[j] ) ;
            int sum = len * maxi + solve( j+1 , k , n , arr ) ;
            maxAns = max( maxAns , sum ) ;
        }
        return maxAns ;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size() ;
        return solve(0,k,n,arr) ;
    }
};



// memoization solution
class Solution {
public:
    int solve(  int i , int k , int n ,vector<int>&arr , vector<int>&dp )
    {
        if( i == n ) return 0 ;
        if( dp[i] != -1  ) return  dp[i] ;
        int len = 0 ;
        int maxi = -1e8 ;
        int maxAns = -1e8 ;
        for( int j = i ; j < min(i+k , n) ; j++ )
        {
            len++ ;
            maxi = max( maxi , arr[j] ) ;
            int sum = len * maxi + solve( j+1 , k , n , arr ,dp ) ;
            maxAns = max( maxAns , sum ) ;
        }
        return dp[i] = maxAns ;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size() ;
        vector<int>dp(n,-1) ;
        return solve(0,k,n,arr,dp) ;
    }
};


// tabulation solution
