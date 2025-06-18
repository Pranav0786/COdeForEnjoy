#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution_0 {
public:
    int solve( vector<int>& nums , vector<int>& dp  , int i )
    {
        if( i == 0  )
            return nums[i] ;
        if( i < 0 )
            return 0 ;
        if( dp[i] != -1 )
            return dp[i] ;
        int pick = nums[i] + solve( nums , dp , i-2 ) ;
        int not_pick = solve( nums , dp , i-1 ) ;
        return dp[i] = max( pick , not_pick )  ;
    }
    int nonAdjacent(vector<int>& nums) {
        int n = nums.size() ;
        vector<int>dp(n , -1 ) ;
        int ans = solve( nums , dp , n-1 ) ;
        return ans ;
    }
};



class Solution_1 {
public:
    int nonAdjacent(vector<int>& nums) {
        int n = nums.size() ;
        int prev = nums[0] ;
        int prev2 = 0 ;
        for( int i = 1 ; i < n ; i++ )
        {
            int take = nums[i] ;
            if( i > 1 ) 
                take += prev2 ;
            int notTake = 0 + prev ;

            int curr = max( take , notTake ) ;
            prev2 = prev ;
            prev = curr ;
        }
        return prev ;
    }
};


