#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int src, int dest, vector<vector<int>>& adj, vector<int>& vis) {

        if (src == dest)
            return true;

        vis[src] = 1;

        for (int neigh : adj[src]) {
            if (!vis[neigh]) {
                if (dfs(neigh, dest, adj, vis))
                    return true;
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();
        vector<vector<int>> adj(n + 1);

        for (auto &edge : edges) {

            int u = edge[0];
            int v = edge[1];

            vector<int> vis(n + 1, 0);

            // If u and v are already connected,
            // this edge is redundant.
            if (!adj[u].empty() && !adj[v].empty()) {
                if (dfs(u, v, adj, vis))
                    return edge;
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};