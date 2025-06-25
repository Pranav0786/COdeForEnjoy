// Leetcode 123

#include<bits/stdc++.h>
using namespace std;
#define ll long long

// recursion solution
class Solution
{
    public:
    int solve(int i, int buy, int cap, vector<int> &prices, int n)
    {
        if (i == n || cap == 0) return 0;
        if (buy)
            return max(-prices[i] + solve(i + 1, 0, cap, prices, n), solve(i + 1, 1, cap, prices, n));
        return max(prices[i] + solve(i + 1, 1, cap - 1, prices, n), solve(i + 1, 0, cap, prices, n));
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        return solve(0, 1, 2, prices, n);
    }
};


// memoization solution
class Solution
{
    public:
    int solve(int i, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp)
    {
        if (i == prices.size() || cap == 0) return 0;
        if (dp[i][buy][cap] != -1) return dp[i][buy][cap];
        if (buy)            
            return dp[i][buy][cap] = max(-prices[i] + solve(i + 1, 0, cap, prices, dp), solve(i + 1, 1, cap, prices, dp));
        return dp[i][buy][cap] = max(prices[i] + solve(i + 1, 1, cap - 1, prices, dp), solve(i + 1, 0, cap, prices, dp));
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(0, 1, 2, prices, dp);
    }
};

// tabulation solution
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int cap = 1; cap <= 2; cap++)
                {
                    if (buy)
                        dp[i][buy][cap] = max(-prices[i] + dp[i + 1][0][cap], dp[i + 1][1][cap]);
                    else
                        dp[i][buy][cap] = max(prices[i] + dp[i + 1][1][cap - 1], dp[i + 1][0][cap]);
                }
            }
        }
        return dp[0][1][2];
    }
};

// space optimization solution
class Solution
{
    public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> ahead(2, vector<int>(3, 0)), curr(2, vector<int>(3, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int cap = 1; cap <= 2; cap++)
                {
                    if (buy)        
                        curr[buy][cap] = max(-prices[i] + ahead[0][cap], ahead[1][cap]);
                    else       
                        curr[buy][cap] = max(prices[i] + ahead[1][cap - 1], ahead[0][cap]);
                }
            }
            ahead = curr;
        }
        return ahead[1][2];
    }
};  



