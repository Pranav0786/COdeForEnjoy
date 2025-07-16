// Leetcode  1091



#include<bits/stdc++.h>
#define ll long long
using namespace std ;


class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        vector<vector<int>> dirs = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},          {0, 1},
            {1, -1}, {1, 0}, {1, 1}
        };

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1; 

        while(!q.empty()) {
            int x = q.front().first , y = q.front().second ;
            q.pop();
            int dist = grid[x][y];

            if(x == n - 1 && y == n - 1) return dist;

            for(auto i : dirs) {
                int nx = x + i[0];
                int ny = y + i[1];

                if(nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0) {
                    grid[nx][ny] = dist + 1;
                    q.push({nx, ny});
                }
            }
        }

        return -1;
    }
};
