// LeetCode 64

#include<bits/stdc++.h>
using namespace std;
#define ll long long

// recursion solution
class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j) {
        if (i == 0 && j == 0)
            return grid[0][0];
        if (i < 0 || j < 0)
            return INT_MAX; 
        int up = solve(grid, i - 1, j) ;
        if( up != INT_MAX )
            up += grid[i][j] ;
        int left = solve(grid, i, j - 1) ;
        if( left != INT_MAX )
            left += grid[i][j] ;
        return min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return solve(grid, m - 1, n - 1); 
    }
};


// memoization solution
class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j , vector<vector<int>>&dp ) {
        if (i == 0 && j == 0)
            return grid[0][0];
        if (i < 0 || j < 0)
            return INT_MAX; 
        if( dp[i][j] != -1 )
            return dp[i][j] ;
        int up = solve(grid, i - 1, j , dp ) ;
        if( up != INT_MAX )
            up += grid[i][j] ;
        int left = solve(grid, i, j - 1 , dp ) ;
        if( left != INT_MAX )
            left += grid[i][j] ;
        return dp[i][j] =  min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp( m , vector<int>(n,-1) ) ;
        return solve(grid, m - 1, n - 1 , dp ); 
    }
};


// tabulation solution
class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp( m , vector<int>(n,0) ) ;
        for( int i = 0 ; i < m ; i++ )
        {
            for( int j = 0 ; j < n ; j++ )
            {
                if( i == 0 && j == 0 )
                    dp[i][j] = grid[i][j] ;
                else
                {
                    int up = grid[i][j] ; 
                    int left = grid[i][j] ;
                    if( i > 0 )
                        up += dp[i-1][j] ;
                    else
                        up = INT_MAX ;
                    if( j > 0 )
                        left = dp[i][j-1] ;
                    else
                        left = INT_MAX ;
                    dp[i][j] = min( up , left ) ;
                }
            }
        }
        return dp[m-1][n-1] ;
    }
};



// space optimization solution
class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int>prev(n,0) ;
        for( int i = 0 ; i < m ; i++ )
        {   
            vector<int>temp(n,0) ;
            for( int j = 0 ; j < n ; j++ )
            {
                if( i == 0 && j == 0 )
                    temp[j] = grid[i][j] ;
                else
                {
                    int up = grid[i][j] ; 
                    int left = grid[i][j] ;
                    if( i > 0 )
                        up += prev[j] ;
                    else
                        up = INT_MAX ;
                    if( j > 0 )
                        left = temp[j-1] ;
                    else
                        left = INT_MAX ;
                    temp[j] = min( up , left ) ;
                }
            }
            prev = temp ;
        }
        return prev[n-1] ;
    }
};



