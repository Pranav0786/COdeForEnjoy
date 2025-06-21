// code studio

#include<bits/stdc++.h>
using namespace std;
#define ll long long


// recursive solution
class Solution {
public:
    int solve( int i , int k , vector<int>&price )
    {
        if( i == 0 )
            return k * price[0] ;
        int notPick = solve( i-1 , k , price ) ;
        int pick = 0 ;
        int rod = i+1 ;
        if( k >= rod )	pick += price[i] + solve( i , k-rod , price ) ;
        return max( pick , notPick ) ;
    }

    int cutRod(vector<int> &price, int n)
    {
        return solve( price.size()-1 , n , price ) ;
    }

};


// memoization solution
class Solution {
public:
    int solve( int i , int k , vector<int>&price , vector<vector<int>> &dp )
    {
        if( i == 0 )
            return k * price[0] ;
        if( dp[i][k] != -1 ) return dp[i][k] ;
        int notPick = solve( i-1 , k , price , dp ) ;
        int pick = 0 ;
        int rod = i+1 ;
        if( k >= rod )	pick += price[i] + solve( i , k-rod , price ,dp ) ;
        return dp[i][k] =  max( pick , notPick ) ;
    }

    int cutRod(vector<int> &price, int n)
    {
        vector<vector<int>> dp(price.size(), vector<int>(n + 1, -1));
        return solve( price.size()-1 , n , price , dp ) ;
    }

};



// tabulation solution
class Solution {
public:
    int cutRod(vector<int> &price, int n)
    {
        vector<vector<int>> dp(price.size(), vector<int>(n + 1, 0));
        for( int j = 0 ; j <= n ; j++ )
            dp[0][j] = j * price[0] ;
        for( int i = 1 ; i < price.size() ; i++ )
        {
            for( int j = 0 ; j <= n ; j++ )
            {
                int notPick = dp[i-1][j] ;
                int pick = 0 ;
                int rod = i+1 ;
                if( j >= rod )	pick += price[i] + dp[i][j-rod] ;
                dp[i][j] =  max( pick , notPick ) ;
            }
        } 
        return dp[price.size()-1][n] ;
    }
    
};



// space optimized solution
class Solution {
public:
    int cutRod(vector<int> &price, int n)
    {
        vector<int> prev(n+1, 0) , curr(n+1,0) ;
        for( int j = 0 ; j <= n ; j++ )
            prev[j] = j * price[0] ;
        for( int i = 1 ; i < price.size() ; i++ )
        {
            for( int j = 0 ; j <= n ; j++ )
            {
                int notPick = prev[j] ;
                int pick = 0 ;
                int rod = i+1 ;
                if( j >= rod )	pick += price[i] + curr[j-rod] ;
                curr[j] =  max( pick , notPick ) ;
            }
            prev = curr ;
        } 
        return prev[n] ;
    }

};



