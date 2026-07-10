#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(int row, int col, vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        queue<pair<int, int>> q;
        q.push({row, col});
        grid[row][col] = 0;

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        while (!q.empty()) {
            auto p = q.front();
            int r = p.first;
            int c = p.second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                    grid[nr][nc] == 1) {
                    grid[nr][nc] = 0;
                    q.push({nr, nc});
                }
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // Remove all boundary-connected land
        for (int i = 0; i < m; i++) {
            if (grid[i][0]) bfs(i, 0, grid);
            if (grid[i][n - 1]) bfs(i, n - 1, grid);
        }

        for (int j = 1; j < n-1; j++) {
            if (grid[0][j]) bfs(0, j, grid);
            if (grid[m - 1][j]) bfs(m - 1, j, grid);
        }

        // Count remaining land cells
        int count = 0;
        for (auto &row : grid)
            for (int cell : row)
                count += cell;

        return count;
    }
};