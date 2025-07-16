// gfg 

#include<bits/stdc++.h>
#define ll long long
using namespace std ;


class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int mod = 1e5 ;
        vector<int> dis(mod,INT_MAX) ;
        queue<pair<int,int>>q  ; // steps , no.
        dis[start] = 0 ;
        q.push({0,start}) ;
        while(!q.empty()){
            int step = q.front().first ;
            int num = q.front().second ;
            q.pop() ;
            if( num == end ) return step ;
            for( auto i : arr ){
                int newNum = (num * i) % mod;
                if (dis[newNum] > step + 1) {
                    dis[newNum] = step + 1;
                    q.push({dis[newNum], newNum});
                }
            }
        }
        return -1 ;
    }
};


