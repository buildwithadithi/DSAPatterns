#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis,
             vector<int>& ans) {

        vis[node] = 1; // Currently visiting

        for (int neigh : adj[node]) {

            if (vis[neigh] == 0) {

                if (!dfs(neigh, adj, vis, ans))
                    return false;

            }
            else if (vis[neigh] == 1) {

                // Cycle found
                return false;

            }

            // vis[neigh] == 2
            // Already processed, so do nothing.
        }

        vis[node] = 2;      // Completely processed
        ans.push_back(node);

        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        // Build graph: prerequisite -> course
        for (auto &edge : prerequisites) {
            int course = edge[0];
            int prereq = edge[1];

            adj[prereq].push_back(course);
        }

        vector<int> vis(numCourses, 0);
        vector<int> ans;

        for (int i = 0; i < numCourses; i++) {

            if (vis[i] == 0) {

                if (!dfs(i, adj, vis, ans))
                    return {};

            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};