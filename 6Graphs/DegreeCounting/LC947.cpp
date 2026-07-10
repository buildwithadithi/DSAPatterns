#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        vector<int> indegree(n + 1, 0);
        vector<int> outdegree(n + 1, 0);

        for (auto &e : trust) {
            int u = e[0];
            int v = e[1];

            outdegree[u]++;
            indegree[v]++;
        }

        for (int i = 1; i <= n; i++) {
            if (outdegree[i] == 0 && indegree[i] == n - 1) {
                return i;
            }
        }

        return -1;
    }
};