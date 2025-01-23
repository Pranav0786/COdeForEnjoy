#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        sort( arr.begin() , arr.end() ) ;
        sort( dep.begin() , dep.end() ) ;
        int n = arr.size() ;
        int i = 1 , j = 0 ;
        int ans = 1 , ct = 1 ;
        while( i < n )
        {
            if( arr[i] > dep[j] ) 
            {
                ct-- ;
                j++ ;
            }
            else
            {
                ct++ ;
                i++ ;
            }
            ans = max( ans , ct ) ;
        }
        return ans ;
    }
};