#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<int, int> dfs(int node, vector<vector<int>>& adj, vector<int>& vis,
                       vector<int>& indegree) {

        vis[node] = 1;

        int nodes = 1;
        int degree = indegree[node];

        for (int nei : adj[node]) {
            if (!vis[nei]) {
                pair<int, int> child = dfs(nei, adj, vis, indegree);
                int cnt = child.first;
                int sum = child.second;
                nodes += cnt;
                degree += sum;
            }
        }

        return {nodes, degree};
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int cnt = 0;

        vector<int> visited(n, 0);
        vector<int> indegree(n, 0);
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                pair<int, int> res = dfs(i, adj, visited, indegree);
                int m = res.first;
                int sumDegree = res.second;
                if ((m * (m - 1)) / 2 == sumDegree / 2) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};