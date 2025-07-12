// Leetcode 127


#include<bits/stdc++.h>
using namespace std;
#define ll long long


class Solution {
public:
    int ladderLength(string bw, string ew, vector<string>& w) {
        unordered_set<string> st(w.begin() , w.end() ) ;
        queue<pair<string,int>>q ;
        q.push({bw , 1}) ;
        st.erase(bw) ;
        while( !q.empty() ) 
        {
            string word = q.front().first ;
            int step = q.front().second ;
            q.pop() ;
            if( word == ew ) return step ;
            for( int i = 0 ; i < word.size() ; i++ )
            {
                char original = word[i] ;
                for( char ch = 'a' ; ch <= 'z' ; ch++ )
                {
                    word[i] = ch ;
                    if( st.find(word) != st.end() ) 
                    {
                        st.erase(word) ;
                        q.push({word , step+1} ) ;
                    }
                }
                word[i] = original ;
            }
        }
        return 0 ;
    }
};


