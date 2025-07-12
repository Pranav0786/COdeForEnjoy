// gfg

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    void dfs(int i, int j, int bi, int bj, vector<pair<int, int>> &temp, vector<vector<int>> &vis, vector<vector<int>> &grid)
    {
        vis[i][j] = 1;
        int n = grid.size(), m = grid[0].size();
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};
        temp.push_back({i - bi, j - bj});
        for (int k = 0; k < 4; k++)
        {
            int nr = i + delrow[k], nc = j + delcol[k];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && !vis[nr][nc])
                dfs(nr, nc, bi, bj, temp, vis, grid);
        }
    }
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])
                {
                    int bi = i, bj = j;
                    vector<pair<int, int>> temp;
                    dfs(i, j, bi, bj, temp, vis, grid);
                    st.insert(temp);
                }
            }
        }
        return st.size();
    }
};


