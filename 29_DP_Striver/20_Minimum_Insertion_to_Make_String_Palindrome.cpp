// Leetcode 1312


#include<bits/stdc++.h>
using namespace std;
#define ll long long


class Solution {
public:

    int longestPalindromeSubseq(string s1) {
        int n = s1.size();
        string s2 = s1;
        reverse(s2.begin(), s2.end());

        vector<int>prev(n+1 , 0 ) , curr(n+1 , 0 ) ;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr ;
        }
        return prev[n];
    }


    int minInsertions(string s) {
        // n - longest palin sunsequence
        int n1 = s.size() ;
        return n1 - longestPalindromeSubseq(s) ;
    }
};