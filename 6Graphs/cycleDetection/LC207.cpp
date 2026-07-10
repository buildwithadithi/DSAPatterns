#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj,
             vector<int>& vis, vector<int>& pathVis) {

        vis[node] = 1;
        pathVis[node] = 1;

        for (int neigh : adj[node]) {

            if (!vis[neigh]) {
                if (!dfs(neigh, adj, vis, pathVis))
                    return false;
            }
            else if (pathVis[neigh]) {
                // Cycle found
                return false;
            }
        }

        pathVis[node] = 0;   // Backtracking
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for (auto &e : prerequisites) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (!dfs(i, adj, vis, pathVis))
                    return false;
            }
        }

        return true;
    }
};