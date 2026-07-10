#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 1)
            return;

        grid[r][c] = 1;

        dfs(r - 1, c, grid);
        dfs(r + 1, c, grid);
        dfs(r, c - 1, grid);
        dfs(r, c + 1, grid);
    }

    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; i++) {
            if (!grid[i][0])
                dfs(i, 0, grid);
            if (!grid[i][n - 1])
                dfs(i, n - 1, grid);
        }

        for (int j = 0; j < n; j++) {
            if (!grid[0][j])
                dfs(0, j, grid);
            if (!grid[m - 1][j])
                dfs(m - 1, j, grid);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    dfs(i, j, grid);
                    count++;
                }
            }
        }
        return count;
    }
};