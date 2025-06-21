// Leetcode 494 

#include<bits/stdc++.h>
using namespace std;
#define ll long long


class Solution {
public:

    int findWays(vector<int> &arr, int k)
    {
        int n = arr.size() ;
        int mod = 1e9 + 7 ; 
        vector<int> prev(k + 1, 0), curr(k + 1, 0) ;
        for (int j = 0; j <= k; j++)
        {
            if (arr[0] == 0 && j == 0)
                prev[j] = 2 ;
            else if (j == 0 || arr[0] == j)
                prev[j] = 1 ;
            else
                prev[j] = 0 ;
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                int notPick = prev[j] ;
                int pick = 0;
                if (j >= arr[i])
                    pick = prev[j - arr[i]] ;

                curr[j] = (pick + notPick) % mod ;
            }
            prev = curr ;
        }
        return prev[k] ;
    }

    int findTargetSumWays(vector<int>& arr, int d ) {
        int sum = 0 ;
        for( auto &i : arr )  sum += i ;
        if( (sum - d) % 2 || sum - d < 0 )   return 0 ;
        int k = (sum - d )/2 ;
        return findWays(arr , k ) ;
    }
};