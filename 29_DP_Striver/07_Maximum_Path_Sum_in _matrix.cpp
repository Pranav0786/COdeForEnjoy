#include<bits/stdc++.h>
using namespace std;
#define ll long long


// recursive solution (wrong solution)
class Solution {
public:
    int solve( vector<vector<int>>&mat , int n , int i , int j )
    {
        if( i == 0 )
            return mat[i][j] ;
        if( j < 0 || j >= n )
            return -1e8 ;
        int up = mat[i][j] + solve( mat  , n , i-1 , j ) ;
        int left = mat[i][j] + solve( mat , n , i-1 , j-1 ) ;
        int right = mat[i][j] + solve( mat , n , i-1 , j+1 ) ;
        return max( up , max( left , right ) ) ;
    }

    int getMaxPathSum(vector<vector<int>> &mat)
    {
        int m = mat.size() ;
        int n = mat[0].size() ;
        int ans = -1e8 ;
        for( int j = 0 ; j < n ; j++ )
            ans = max( ans , solve( mat , n , m-1 , j )) ;
        return ans ;
    }

} ;



// memoization solution (wrong solution)
class Solution {
public:
    int solve( vector<vector<int>>&mat , int m , int n , int i , int j , vector<vector<int>>&dp)
    {
        if (i == m - 1)
            return mat[i][j];
        if (j < 0 || j >= n)
            return -1e9;
        if (dp[i][j] != -1)
            return dp[i][j];
        int down = mat[i][j] + solve(mat, m, n, i + 1, j, dp);
        int left = mat[i][j] + solve(mat, m, n, i + 1, j - 1, dp);
        int right = mat[i][j] + solve(mat, m, n, i + 1, j + 1, dp);
        return dp[i][j] = max(down, max(left, right));
    }

    int getMaxPathSum(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        int ans = INT_MIN;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for (int j = 0; j < n; j++)
            ans = max(ans, solve(mat, m, n, 0, j, dp));
        return ans;
    }
};


// tabulation solution
class Solution {
public:

    int getMaxPathSum(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        int ans = -1e8;
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++)
            dp[0][j] = mat[0][j];

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int up = mat[i][j] + dp[i - 1][j];
                int left = mat[i][j] + (j > 0 ? dp[i - 1][j - 1] : -1e8);
                int right = mat[i][j] + (j < m - 1 ? dp[i - 1][j + 1] : -1e8);
                dp[i][j] = max({up, left, right});
            }
        }

        for (int j = 0; j < m; j++)
            ans = max(ans, dp[n - 1][j]);

        return ans;
    }

};



// space optimized solution
class Solution {
public:
    int getMaxPathSum(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        int ans = -1e8;
        vector<int>prev(m,0) , temp(n,0) ;

        for (int j = 0; j < m; j++)
            prev[j] = mat[0][j];

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int up = mat[i][j] + prev[j];
                int left = mat[i][j] + (j > 0 ? prev[j - 1] : -1e8);
                int right = mat[i][j] + (j < m - 1 ? prev[j + 1] : -1e8);
                temp[j] = max({up, left, right});
            }
            prev = temp ;
        }

        for (int j = 0; j < m; j++)
            ans = max(ans, prev[j]);

        return ans;
    }


} ;

