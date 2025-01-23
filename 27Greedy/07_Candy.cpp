// leetcode 135

#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int candy(vector<int>& r ) {
        int n = r.size() ;
        int sum = 1 ;
        int i = 1 ;
        while( i < n )
        {
            if( r[i] == r[i-1] ) 
            {
                sum++ ;
                i++ ; 
                continue ;
            }
            int peak = 1 ;
            while( i < n  && r[i] > r[i-1] ) 
            {
                peak++ ;
                sum += peak ;
                i++ ;
            }
            int down = 1 ;
            while( i < n && r[i] < r[i-1] ) 
            {
                sum += down ;
                i++ ;
                down++ ;
            }
            if( down > peak )
                sum += down - peak ;
        }
        return sum ;
    }
};

