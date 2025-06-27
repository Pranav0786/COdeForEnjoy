#include <bits/stdc++.h>
using namespace std;
#define ll long long



// recursion solution
class Solution
{
public:
    int solve(int i, int j, vector<int> &arr)
    {
        if (i == j)
            return 0;
        int mini = 1e8;
        for (int k = i; k <= j - 1; k++)
        {
            int steps = arr[i - 1] * arr[k] * arr[j] + solve(i, k, arr) + solve(k + 1, j, arr);
            mini = min(mini, steps);
        }
        return mini;
    }

    int matrixMultiplication(vector<int> &arr, int N)
    {
        return solve(1, N - 1, arr);
    }
};


// memoization solution
class Solution
{
public:
    int solve(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (i == j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int mini = 1e8;
        for (int k = i; k <= j - 1; k++)
        {
            int steps = arr[i - 1] * arr[k] * arr[j] + solve(i, k, arr, dp) + solve(k + 1, j, arr, dp);
            mini = min(mini, steps);
        }
        return dp[i][j] = mini;
    }

    int matrixMultiplication(vector<int> &arr, int N)
    {
        vector<vector<int>> dp(N, vector<int>(N, -1));
        return solve(1, N - 1, arr, dp);
    }
};


// tabulation solution
class Solution
{
public:
    int matrixMultiplication(vector<int> &arr, int N)
    {
        vector<vector<int>> dp(N, vector<int>(N, 0));
        for (int i = N - 1; i >= 1; i--)
        {
            for (int j = i + 1; j < N; j++)
            {
                int mini = 1e8;
                for (int k = i; k <= j - 1; k++)
                {
                    int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                    mini = min(mini, steps);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][N - 1];
    }
};



