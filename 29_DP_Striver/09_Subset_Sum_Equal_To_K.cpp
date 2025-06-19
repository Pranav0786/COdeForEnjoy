// Code studio

#include<bits/stdc++.h>
using namespace std;
#define ll long long

// recursion solution
class Solution {
public:
    bool solve( vector<int>&arr , int i , int k )
    {
        if( k == 0 )
            return true ;
        if( i < 0 )
            return false ;
        bool notPick = solve( arr , i-1 , k ) ;
        bool pick = false ;
        if( k >= arr[i] ) 
            pick = solve( arr , i-1 , k - arr[i] ) ;
        return pick || notPick ;
    }

    bool subsetSumToK(int n, int k, vector<int> &arr) {
        return solve( arr , n-1 , k ) ;
    }
};


// memoization solution
class Solution {
public:
    bool solve(vector<int>& arr, int i, int k, vector<vector<int>>& dp) {
        if (k == 0) return true;
        if (i == 0) return arr[0] == k;

        if (dp[i][k] != -1) return dp[i][k];

        bool notPick = solve(arr, i - 1, k, dp);
        bool pick = false;
        if (k >= arr[i])
            pick = solve(arr, i - 1, k - arr[i], dp);

        return dp[i][k] = pick || notPick;
    }

    bool subsetSumToK(int n, int k, vector<int>& arr) {
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return solve(arr, n - 1, k, dp);
    }


};


// tabulation solution
class Solution {
public:
    bool subsetSumToK(int n, int k, vector<int>& arr) {
        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
        for (int i = 0; i < n; i++)
            dp[i][0] = true;
        if (arr[0] <= k)
            dp[0][arr[0]] = true;
        for (int i = 1; i < n; i++) 
        {
            for (int j = 1; j <= k; j++) 
            {
                bool notPick = dp[i - 1][j];
                bool pick = false;
                if (j >= arr[i])
                    pick = dp[i - 1][j - arr[i]];
                dp[i][j] = pick || notPick;
            }
        }
        return dp[n - 1][k];
    }

};


// space optimized solution
class Solution {
public:
    

} ;