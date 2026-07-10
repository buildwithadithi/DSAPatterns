#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bfs(vector<vector<int>> &adj, vector<int>& restricted){
        queue<int> q;
        unordered_set<int> mp(restricted.begin(), restricted.end());

        unordered_set<int> visited;
        if (mp.count(0))
            return 0;

        q.push(0);
        visited.insert(0);

        int count = 1;

        while (!q.empty()) {

            int node = q.front();
          
            q.pop();

            for(int neigh: adj[node]){
                if(!mp.count(neigh) && !visited.count(neigh)){
                    q.push(neigh);
                    count++;
                    visited.insert(neigh);
                }
            }   
        }

        return count;
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {

        vector<vector<int>> adj(n);
        for(auto e: edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return bfs(adj, restricted);
    }
};