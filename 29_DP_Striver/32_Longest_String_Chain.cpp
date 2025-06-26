// Leetcode 1048

#include<bits/stdc++.h>
using namespace std;
#define ll long long



class Solution {
public:

    bool check( string &a , string &b ) 
    {
        if( a.size() != b.size()+1 ) return false ;
        int first = 0 , second = 0 ;
        while( first < a.size() ) 
        {
            if( a[first] == b[second] )
            {
                first++ ; second++ ;
            }
            else first++ ;
        }
        if(first == a.size() && second == b.size() )  return true ;
        return false ;
    }

    static bool comp( string &s1 , string &s2 )
    {
        return s1.size() < s2.size() ;
    }

    int longestStrChain(vector<string>& w) {
        int n = w.size() ;
        vector<int>dp(n,1) ;
        sort(w.begin() , w.end() , comp ) ;
        int maxi = 1 ;
        for( int i = 0 ; i< n ; i++ )
        {
            for( int prev = 0 ; prev < i ; prev++ )
            {
                if( check(w[i] , w[prev] ) &&   1 + dp[prev] > dp[i]   )
                    dp[i] = 1+ dp[prev] ;
            }
            if( dp[i] > maxi ) maxi = dp[i] ;
        }
        return maxi ;
    }
};