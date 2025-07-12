// Leetcode 126

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    vector<vector<string>> findLadders(string bw, string ew, vector<string> &w)
    {
        unordered_set<string> st(w.begin(), w.end());
        queue<vector<string>> q;
        q.push({bw});
        vector<string> usedOnLevel;
        usedOnLevel.push_back(bw);
        int level = 0;
        vector<vector<string>> ans;
        while (!q.empty())
        {
            vector<string> vec = q.front();
            q.pop();
            // erase all words that has been used on previous level
            if (vec.size() > level)
            {
                level++;
                for (auto it : usedOnLevel)
                    st.erase(it);
            }
            string word = vec.back();
            // store the ans
            if (word == ew)
            {
                if (ans.size() == 0)
                    ans.push_back(vec);
                else if (ans[0].size() == vec.size())
                    ans.push_back(vec);
            }
            for (int i = 0; i < word.size(); i++)
            {
                char original = word[i];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    word[i] = c;
                    if (st.count(word) > 0)
                    {
                        vec.push_back(word);
                        q.push(vec);
                        // mark as visited at level
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
};



