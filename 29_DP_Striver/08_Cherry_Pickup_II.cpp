// Leetcode 1463

#include<bits/stdc++.h>
using namespace std;
#define ll long long


// recursion solution
class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j1, int j2) {
        int m = grid.size(), n = grid[0].size();
        if (j1 < 0 || j1 >= n || j2 < 0 || j2 >= n)
            return -1e8;
        
        if (i == m - 1) 
        {
            if (j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }
        
        int ans = -1e8;
        for (int dj1 = -1; dj1 <= 1; dj1++) 
        {
            for (int dj2 = -1; dj2 <= 1; dj2++) 
            {
                int val = 0;
                if (j1 == j2)
                    val = grid[i][j1];
                else
                    val = grid[i][j1] + grid[i][j2];
                val += solve(grid, i + 1, j1 + dj1, j2 + dj2);
                ans = max(ans, val);
            }
        }
        return ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        return solve(grid, 0, 0, n - 1);
    }
};



// memoization solution
class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j1, int j2 , vector<vector<vector<int>>> &dp ) {
        int m = grid.size(), n = grid[0].size();
        if (j1 < 0 || j1 >= n || j2 < 0 || j2 >= n)
            return -1e8;
        
        if (i == m - 1) 
        {
            if (j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }
        if( dp[i][j1][j2] != -1 )
            return dp[i][j1][j2] ;
        int ans = -1e8;
        for (int dj1 = -1; dj1 <= 1; dj1++) 
        {
            for (int dj2 = -1; dj2 <= 1; dj2++) 
            {
                int val = 0;
                if (j1 == j2)
                    val = grid[i][j1];
                else
                    val = grid[i][j1] + grid[i][j2];
                val += solve(grid, i + 1, j1 + dj1, j2 + dj2 , dp );
                ans = max(ans, val);
            }
        }
        return dp[i][j1][j2] =  ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return solve(grid, 0, 0, n - 1 , dp );
    }
};



// tabulation solution
class Solution {
public:

    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));
        
        // base cases
        for( int j1 = 0 ; j1 < n ; j1++ )
        {
            for( int j2 = 0 ; j2 <n ; j2++ )
            {
                if( j1 == j2 )
                    dp[m-1][j1][j2] = grid[m-1][j1] ;
                else
                    dp[m-1][j1][j2] = grid[m-1][j1] + grid[m-1][j2] ;
            }
        }

        for( int i = m-2 ; i>=0 ; i-- )
        {
            for( int j1 = 0 ; j1 < n ; j1++ )
            {
                for( int j2 = 0 ; j2 < n ; j2++ )
                {
                    int ans = -1e8;
                    for (int dj1 = -1; dj1 <= 1; dj1++) 
                    {
                        for (int dj2 = -1; dj2 <= 1; dj2++) 
                        {
                            int val = 0;
                            if (j1 == j2)
                                val = grid[i][j1];
                            else
                                val = grid[i][j1] + grid[i][j2];
                            if( j1+dj1 >= 0 && j1+dj1 < n && j2+dj2 >= 0 && j2+dj2 < n )
                                val += dp[i + 1][j1+dj1][j2+dj2] ;
                            else
                                val += -1e8 ;
                            ans = max(ans, val);
                        }
                    }
                    dp[i][j1][j2] =  ans;
                }
            }
        }
        return dp[0][0][n-1] ;
    }
};



// optimized solution
class Solution {
public:

    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> front(n, vector<int>(n, 0));
        vector<vector<int>> curr(n, vector<int>(n, 0));

        
        // base cases
        for( int j1 = 0 ; j1 < n ; j1++ )
        {
            for( int j2 = 0 ; j2 <n ; j2++ )
            {
                if( j1 == j2 )
                    front[j1][j2] = grid[m-1][j1] ;
                else
                    front[j1][j2] = grid[m-1][j1] + grid[m-1][j2] ;
            }
        }

        for( int i = m-2 ; i>=0 ; i-- )
        {
            for( int j1 = 0 ; j1 < n ; j1++ )
            {
                for( int j2 = 0 ; j2 < n ; j2++ )
                {
                    int ans = -1e8;
                    for (int dj1 = -1; dj1 <= 1; dj1++) 
                    {
                        for (int dj2 = -1; dj2 <= 1; dj2++) 
                        {
                            int val = 0;
                            if (j1 == j2)
                                val = grid[i][j1];
                            else
                                val = grid[i][j1] + grid[i][j2];
                            if( j1+dj1 >= 0 && j1+dj1 < n && j2+dj2 >= 0 && j2+dj2 < n )
                                val += front[j1+dj1][j2+dj2] ;
                            else
                                val += -1e8 ;
                            ans = max(ans, val);
                        }
                    }
                    curr[j1][j2] =  ans;
                }
            }
            front  = curr ;
        }
        return front[0][n-1] ;
    }
};



