// code studio

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// recursion solution
class Solution
{
public:
    ll solve(int i, int j, int istrue, string &exp)
    {
        int mod = 1000000007;
        if (i > j)
            return 0;
        if (i == j)
        {
            if (istrue)
                return exp[i] == 'T';
            else
                return exp[i] == 'F';
        }
        ll ways = 0;
        for (int idx = i + 1; idx <= j - 1; idx += 2)
        {
            ll lt = solve(i, idx - 1, 1, exp);
            ll lf = solve(i, idx - 1, 0, exp);
            ll rt = solve(idx + 1, j, 1, exp);
            ll rf = solve(idx + 1, j, 0, exp);

            if (exp[idx] == '&')
            {
                if (istrue)
                    ways = (ways + (rt * lt) % mod) % mod;
                else
                    ways = (ways + (rt * lf) % mod + (lt * rf) % mod + (lf * rf) % mod) % mod;
            }
            else if (exp[idx] == '|')
            {
                if (istrue)
                    ways = (ways + (rt * lf) % mod + (lt * rf) % mod + (lt * rt) % mod) % mod;
                else
                    ways = (ways + (rf * lf) % mod) % mod;
            }
            else
            {
                if (istrue)
                    ways = (ways + (rt * lf) % mod + (rf * lt) % mod) % mod;
                else
                    ways = (ways + (rf * lf) % mod + (rt * lt) % mod) % mod;
            }
        }
        return ways;
    }

    int evaluateExp(string &exp)
    {
        int n = exp.size();
        return solve(0, n - 1, 1, exp);
    }
};

// memoization solution
class Solution
{
public:
    ll solve(int i, int j, int istrue, string &exp, vector<vector<vector<int>>> &dp)
    {
        int mod = 1000000007;
        if (i > j)
            return 0;
        if (i == j)
        {
            if (istrue)
                return exp[i] == 'T';
            else
                return exp[i] == 'F';
        }
        if (dp[i][j][istrue] != -1)
            return dp[i][j][istrue];
        ll ways = 0;
        for (int idx = i + 1; idx <= j - 1; idx += 2)
        {
            ll lt = solve(i, idx - 1, 1, exp, dp);
            ll lf = solve(i, idx - 1, 0, exp, dp);
            ll rt = solve(idx + 1, j, 1, exp, dp);
            ll rf = solve(idx + 1, j, 0, exp, dp);

            if (exp[idx] == '&')
            {
                if (istrue)
                    ways = (ways + (rt * lt) % mod) % mod;
                else
                    ways = (ways + (rt * lf) % mod + (lt * rf) % mod + (lf * rf) % mod) % mod;
            }
            else if (exp[idx] == '|')
            {
                if (istrue)
                    ways = (ways + (rt * lf) % mod + (lt * rf) % mod + (lt * rt) % mod) % mod;
                else
                    ways = (ways + (rf * lf) % mod) % mod;
            }
            else
            {
                if (istrue)
                    ways = (ways + (rt * lf) % mod + (rf * lt) % mod) % mod;
                else
                    ways = (ways + (rf * lf) % mod + (rt * lt) % mod) % mod;
            }
        }
        return dp[i][j][istrue] = ways;
    }

    int evaluateExp(string &exp)
    {
        int n = exp.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return solve(0, n - 1, 1, exp, dp);
    }
};





class Solution
{
public:

};

class Solution
{
public:
};