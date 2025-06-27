// Leetcode 132

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// recursion solution
class Solution
{
public:
    bool isPalindrome(int i, int j, string &s)
    {
        while (i <= j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(int i, int n, string &s)
    {
        if (i == n)
            return 0;
        string temp = "";
        int minCost = 1e8;
        for (int j = i; j < n; j++)
        {
            if (isPalindrome(i, j, s))
            {
                int cost = 1 + solve(j + 1, n, s);
                minCost = min(minCost, cost);
            }
        }
        return minCost;
    }
    int minCut(string s)
    {
        int n = s.size();
        return solve(0, n, s) - 1;
    }
};

// memoization solution
class Solution
{
public:
    bool isPalindrome(int i, int j, string &s)
    {
        while (i <= j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(int i, int n, string &s, vector<int> &dp)
    {
        if (i == n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int minCost = 1e8;
        for (int j = i; j < n; j++)
        {
            if (isPalindrome(i, j, s))
            {
                int cost = 1 + solve(j + 1, n, s, dp);
                minCost = min(minCost, cost);
            }
        }
        return dp[i] = minCost;
    }
    int minCut(string s)
    {
        int n = s.size();
        vector<int> dp(n, -1);
        return solve(0, n, s, dp) - 1;
    }
};

// tabulation solution
class Solution
{
public:
    bool isPalindrome(int i, int j, string &s)
    {
        while (i <= j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int minCut(string s)
    {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            int minCost = 1e8;
            for (int j = i; j < n; j++)
            {
                if (isPalindrome(i, j, s))
                {
                    int cost = 1 + dp[j + 1];
                    minCost = min(minCost, cost);
                }
            }
            dp[i] = minCost;
        }
        return dp[0] - 1;
    }
};

