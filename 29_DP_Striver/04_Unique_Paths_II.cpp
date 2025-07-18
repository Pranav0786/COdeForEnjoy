// LeetCode 63

#include<bits/stdc++.h>
using namespace std;
#define ll long long

// recursion solution 
class Solution {
public:
    int solve( vector<vector<int>>& grid , int i , int j )
    {
        if( i == 0 && j == 0 && grid[i][j] != -1 )
            return 1 ;
        if( i == 0 && j == 0 )
            return 0 ;
        if( i < 0 || j < 0 )
            return 0 ;
        if( grid[i][j] == -1 )
            return 0 ;
        int up = solve( grid , i-1 , j ) ;
        int left = solve( grid , i , j-1 ) ;
        return left + up ;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size() ;
        int n = grid[0].size() ;
        for( int i = 0 ; i < m ; i++ )
        {
            for( int j = 0 ; j < n ; j++ )
            {
                if( grid[i][j] == 1 )
                    grid[i][j] = -1 ;
            }
        }
        return solve( grid , m-1 , n-1 ) ;
    }
};


// memorization solution
class Solution {
public:
    int solve( vector<vector<int>>& grid , int i , int j , vector<vector<int>>&dp )
    {
        if( i == 0 && j == 0 && grid[i][j] != -1 )
            return 1 ;
        if( i == 0 && j == 0 )
            return 0 ;
        if( i < 0 || j < 0 )
            return 0 ;
        if( grid[i][j] == -1 )
            return 0 ;
        if( dp[i][j] != -1 )
            return dp[i][j] ;
        int up = solve( grid , i-1 , j , dp ) ;
        int left = solve( grid , i , j-1 , dp ) ;
        return dp[i][j] =  left + up ;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size() ;
        int n = grid[0].size() ;
        for( int i = 0 ; i < m ; i++ )
        {
            for( int j = 0 ; j < n ; j++ )
            {
                if( grid[i][j] == 1 )
                    grid[i][j] = -1 ;
            }
        }
        vector<vector<int>>dp(m , vector<int>( n , -1 ) ) ;
        return solve( grid , m-1 , n-1 , dp ) ;
    }
};


// tabulation solution
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size() ;
        int n = grid[0].size() ;
        for( int i = 0 ; i < m ; i++ )
        {
            for( int j = 0 ; j < n ; j++ )
            {
                if( grid[i][j] == 1 )
                    grid[i][j] = -1 ;
            }
        }
        vector<vector<int>>dp( m , vector<int>(n , -1 ) ) ;
        for( int i = 0 ; i < m ; i++ )
        {
            for( int j = 0 ; j < n ; j++ )
            {
                if( grid[i][j] == -1 )
                    dp[i][j] = 0 ;
                else if( i == 0 && j == 0 )
                    dp[i][j] = 1 ;
                else
                {
                    int up = 0 , left = 0 ;
                    if( i > 0 )
                        up = dp[i-1][j] ;
                    if( j > 0 )
                        left = dp[i][j-1] ;
                    dp[i][j] = up + left ;
                }
            }
        }
        return dp[m-1][n-1] ;
    }
};


// space optimized solution
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size() ;
        int n = grid[0].size() ;
        for( int i = 0 ; i < m ; i++ )
        {
            for( int j = 0 ; j < n ; j++ )
            {
                if( grid[i][j] == 1 )
                    grid[i][j] = -1 ;
            }
        }
        vector<int>prev( n , 0 ) ;
        for( int i = 0 ; i < m ; i++ )
        {
            vector<int>temp( n , 0 ) ;
            for( int j = 0 ; j < n ; j++ )
            {
                if( grid[i][j] == -1 )
                    temp[j] = 0 ;
                else if( i == 0 && j == 0 )
                    temp[j] = 1 ;
                else
                {
                    int up = 0 , left = 0 ;
                    if( i > 0 )
                        up = prev[j] ;
                    if( j > 0 )
                        left = temp[j-1] ;
                    temp[j] = up + left ;
                }
            }
            prev = temp ;
        }
        return prev[n-1] ;
    }
};


