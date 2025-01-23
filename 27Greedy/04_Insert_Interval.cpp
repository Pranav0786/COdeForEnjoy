//  leetcode 57

#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>&arr, vector<int>&node) {
        vector<vector<int>>ans ;
        int i = 0  , n = arr.size() ;
        while( i < n && arr[i][1] < node[0] )
        {
            ans.push_back( arr[i] ) ;
            i++ ;
        }
        while( i < n && arr[i][0] <= node[1] )
        {
            node[0] = min( node[0] , arr[i][0] ) ;
            node[1] = max( node[1] , arr[i][1] ) ;
            i++ ;
        }
        ans.push_back( node ) ;
        while( i < n )
        {
            ans.push_back( arr[i] ) ;
            i++ ;
        }
        return ans ;
    }
};

