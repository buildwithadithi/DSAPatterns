#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();

        queue<pair<int,int>> q;
        q.push({row, col});
        board[row][col] = '#';

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto front = q.front();
            int r = front.first;
            int c = front.second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < m &&
                    nc >= 0 && nc < n &&
                    board[nr][nc] == 'O') {

                    board[nr][nc] = '#';
                    q.push({nr, nc});
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') bfs(i, 0, board);
            if (board[i][n - 1] == 'O') bfs(i, n - 1, board);
        }

        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') bfs(0, j, board);
            if (board[m - 1][j] == 'O') bfs(m - 1, j, board);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};