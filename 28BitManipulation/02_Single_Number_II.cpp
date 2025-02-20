// leetcode 137

#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int once = 0 , twos = 0 ;
        for( int i = 0 ; i < nums.size() ; i++ )
        {
            once = ( once ^ nums[i] ) & ~twos ;
            twos = ( twos ^ nums[i] ) & ~once ;
        }
        return once ;
    }
};