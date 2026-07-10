#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        unordered_set<string> dead(deadends.begin(), deadends.end());

        if (dead.count("0000"))
            return -1;

        unordered_set<string> visited;
        queue<pair<string, int>> q;

        q.push({"0000", 0});
        visited.insert("0000");

        while (!q.empty()) {

            auto [state, moves] = q.front();
            q.pop();

            if (state == target)
                return moves;

            for (int i = 0; i < 4; i++) {

                string temp = state;

                // Rotate forward
                temp[i] = ((state[i] - '0' + 1) % 10) + '0';
                if (!dead.count(temp) && !visited.count(temp)) {
                    visited.insert(temp);
                    q.push({temp, moves + 1});
                }

                // Rotate backward
                temp = state;
                temp[i] = ((state[i] - '0' + 9) % 10) + '0';
                if (!dead.count(temp) && !visited.count(temp)) {
                    visited.insert(temp);
                    q.push({temp, moves + 1});
                }
            }
        }

        return -1;
    }
};