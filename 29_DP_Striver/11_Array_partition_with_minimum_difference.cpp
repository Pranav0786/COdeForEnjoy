// code studio

#include<bits/stdc++.h>
using namespace std;
#define ll long long



int minSubsetSumDifference(vector<int>& nums, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++) sum += nums[i];

    vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    if (nums[0] <= sum)
        dp[0][nums[0]] = true;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= sum; j++) {
            bool notPick = dp[i - 1][j];
            bool pick = false;
            if (j >= nums[i])
                pick = dp[i - 1][j - nums[i]];
            dp[i][j] = pick || notPick;
        }
    }

    int mini = INT_MAX;
    for (int i = 0; i <= sum / 2; i++) {
        if (dp[n - 1][i])
            mini = min(mini, abs((sum - i) - i));
    }
    return mini;
}



