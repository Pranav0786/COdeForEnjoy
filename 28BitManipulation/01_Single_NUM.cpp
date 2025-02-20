// leetcode 136

#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0 ;
        for( int i = 0 ; i < nums.size() ; i++ )
            ans ^= nums[i] ;
        return ans ;
    }
};