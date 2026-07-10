#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int dfs(int r, int c, vector<vector<int>>& grid){

        int m = grid.size();
        int n = grid[0].size();

        if(r < 0 || r >= m || c < 0 || c >= n || !grid[r][c]){
            return 0;
        }

        grid[r][c] = 0;

        int count = 0;

        return 1 + dfs(r-1, c, grid) + dfs(r+1, c, grid) + dfs(r, c-1, grid) + dfs(r, c+1, grid);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        int maxi = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]){
                    maxi = max(maxi, dfs(i, j, grid));
                }
            }
        }
        return maxi;
    }
};