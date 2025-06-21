// Code studio

#include<bits/stdc++.h>
using namespace std;
#define ll long long



// recursion solution
class Solution {
public:
    int solve(int i, int k, vector<int>& arr) {
        int mod = 1e9 + 7;
        if (i == 0) {
            if (k == 0 && arr[0] == 0) return 2; // {} and {0}
            if (k == 0 || arr[0] == k) return 1;
            return 0;
        }

        int notPick = solve(i - 1, k, arr);
        int pick = 0;
        if (k >= arr[i])
            pick = solve(i - 1, k - arr[i], arr);

        return (pick + notPick) % mod;
    }

    int findWays(vector<int>& arr, int k) {
        int n = arr.size();
        return solve(n - 1, k, arr);
    }

} ;


// memoization solution
class Solution {
public:
    int solve(int i, int k, vector<int>& arr, vector<vector<int>>&dp ) {
        int mod = 1e9 + 7;
        if (i == 0) {
            if (k == 0 && arr[0] == 0) return 2; // {} and {0}
            if (k == 0 || arr[0] == k) return 1;
            return 0;
        }
        if( dp[i][k] != -1 ) return dp[i][k] ;

        int notPick = solve(i - 1, k, arr , dp ) ;
        int pick = 0;
        if (k >= arr[i])
            pick = solve(i - 1, k - arr[i], arr , dp );

        return dp[i][k] =  (pick + notPick) % mod;
    }

    int findWays(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>>dp(n , vector<int>(k+1 , -1 )) ; 
        return solve(n - 1, k, arr , dp );
    }

} ;



// tabulation solution
class Solution {
public:
    int findWays(vector<int>& arr, int k) {
        int n = arr.size();
        int mod = 1e9 + 7;
        vector<vector<int>>dp(n , vector<int>(k+1 , 0 )) ; 
        for (int j = 0; j <= k; j++) {
            if (arr[0] == 0 && j == 0) dp[0][j] = 2;     
            else if (j == 0 || arr[0] == j) dp[0][j] = 1; 
            else dp[0][j] = 0;
        }
        for( int i = 1 ; i < n ; i++ )
        {
            for( int j = 0 ; j <= k ; j++ )
            {
                int notPick = dp[i - 1][j] ;
                int pick = 0;
                if (j >= arr[i])
                    pick = dp[i - 1][j - arr[i]] ;

                dp[i][j] =  (pick + notPick) % mod;
            }
        }
        return dp[n-1][k] ;
    }

} ;


// space optimization solution
class Solution {
public:
    
    int findWays(vector<int>& arr, int k) {
        int n = arr.size();
        int mod = 1e9 + 7;
        vector<int> prev(k+1, 0 ) , curr(k+1 , 0 ) ; 
        for (int j = 0; j <= k; j++) {
            if (arr[0] == 0 && j == 0) prev[j] = 2;     
            else if (j == 0 || arr[0] == j) prev[j] = 1; 
            else prev[j] = 0;
        }
        for( int i = 1 ; i < n ; i++ )
        {
            for( int j = 0 ; j <= k ; j++ )
            {
                int notPick = prev[j] ;
                int pick = 0;
                if (j >= arr[i])
                    pick = prev[j - arr[i]] ;

                curr[j] =  (pick + notPick) % mod;
            }
            prev = curr ;
        }
        return prev[k] ;
    }


} ;



