//  leetcode 435

#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int ct =1 , lastendTime = intervals[0][1] ;
        for( int i =1 ; i < intervals.size() ; i++ )
        {
            if( intervals[i][0] >= lastendTime )
            {
                ct++ ;
                lastendTime = intervals[i][1] ;
            }
        }
        return intervals.size() - ct ;

    }
};