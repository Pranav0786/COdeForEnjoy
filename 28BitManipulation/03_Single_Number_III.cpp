// leecode 260

#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        int xorr = 0;
        for (int i = 0; i < n; i++) {
            xorr ^= nums[i];
        }
        ll rightmost = (ll)xorr & -(ll)xorr;  
        int b1 = 0, b2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] & rightmost)
                b1 ^= nums[i];
            else
                b2 ^= nums[i];
        }
        return {b1, b2};
    }
};
