// Binary search on answer

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, m;
    vector<vector<int>> dist;

    bool isPossible(int k) {

        if (dist[0][0] < k)
            return false;

        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        q.push({0, 0});
        vis[0][0] = 1;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!q.empty()) {

            auto it = q.front();
            q.pop();

            int r = it.first;
            int c = it.second;

            if (r == n - 1 && c == m - 1)
                return true;

            for (int i = 0; i < 4; i++) {

                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < m &&
                    !vis[nr][nc] &&
                    dist[nr][nc] >= k) {

                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();

        dist.assign(n, vector<int>(m, INT_MAX));

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        int low = INT_MAX;
        int high = INT_MIN;

        while (!q.empty()) {

            auto it = q.front();
            q.pop();

            int r = it.first;
            int c = it.second;

            low = min(low, dist[r][c]);
            high = max(high, dist[r][c]);

            for (int i = 0; i < 4; i++) {

                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < m &&
                    dist[nr][nc] == INT_MAX) {

                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (isPossible(mid))
                low = mid + 1;
            else
                high = mid - 1;
        }

        return high;
    }
};