#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0)
            return;

        grid[r][c] = 0;

        dfs(r - 1, c, grid);
        dfs(r + 1, c, grid);
        dfs(r, c - 1, grid);
        dfs(r, c + 1, grid);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // Remove boundary-connected land
        for (int i = 0; i < m; i++) {
            if (grid[i][0]) dfs(i, 0, grid);
            if (grid[i][n - 1]) dfs(i, n - 1, grid);
        }

        for (int j = 0; j < n; j++) {
            if (grid[0][j]) dfs(0, j, grid);
            if (grid[m - 1][j]) dfs(m - 1, j, grid);
        }

        int count = 0;

        for (auto &row : grid)
            for (int cell : row)
                count += cell;

        return count;
    }
};