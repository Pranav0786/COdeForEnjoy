#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    vector<int> lis(vector<int> &nums, vector<int> &dp)
    {
        int n = nums.size();
        int maxi = 1;
        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (nums[i] > nums[prev] && 1 + dp[prev] > dp[i])
                    dp[i] = 1 + dp[prev];
            }
            if (dp[i] > maxi)
                maxi = dp[i];
        }
        return dp;
    }
    int LongestBitonicSequence(int n, vector<int> &nums)
    {
        vector<int> dp1(n, 1), dp2(n, 1);
        dp1 = lis(nums, dp1);
        reverse(nums.begin(), nums.end());
        dp2 = lis(nums, dp2); 
        reverse(dp2.begin(), dp2.end());
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, dp1[i] + dp2[i] - 1);
        }
        return ans;
    }
};
