// leetcode 29

#include<bits/stdc++.h>
using namespace std;
#define ll long long


class Solution {
public:
    int divide(int dividend, int divisor) {
        if( dividend == divisor ) return 1;
        bool isnegative = false;
        if( (dividend < 0 && divisor > 0 ) || (dividend > 0 && divisor < 0) ) {
            isnegative = true;
        }
        int d = abs(divisor);
        int n = abs(dividend);
        int ans = 0 ;
        while( n >= d ) {
            int ct = 0 ;
            while( n >= (d << (ct + 1)) ) {
                ct++;
            }
            ans += (1 << ct );
            n -= (d << ct);
        }
        if( ans >= INT_MAX && !isnegative ) 
            return INT_MAX;
        if( ans >= INT_MAX && isnegative ) 
            return INT_MIN;     
        return isnegative ? -ans : ans; 

    }
};