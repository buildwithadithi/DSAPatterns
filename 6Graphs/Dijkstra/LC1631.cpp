#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int row = heights.size();
        int col = heights[0].size();

        vector<vector<int>> effort(row, vector<int>(col, INT_MAX));

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            pq;

        effort[0][0] = 0;
        pq.push({0, 0, 0});

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!pq.empty()) {
            tuple<int, int, int> curr = pq.top();
            pq.pop();

            int Tnoweffort = get<0>(curr);
            int r = get<1>(curr);
            int c = get<2>(curr);

            if (r == row - 1 && c == col - 1) {
                return Tnoweffort;
            }
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nr >= row || nc < 0 || nc >= col) {
                    continue;
                }

                int newEffort =
                    max(Tnoweffort, abs(heights[r][c] - heights[nr][nc]));

                if (newEffort < effort[nr][nc]) {
                    effort[nr][nc] = newEffort;
                    pq.push({newEffort, nr, nc});
                }
            }
        }
        return 0;
    }
};