#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int dij(int n, int source, vector<vector<pair<int, int>>>& adj) {

        vector<int> dist(n + 1, INT_MAX);

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        dist[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            int distance = curr.first;
            int node = curr.second;

            if (distance > dist[node])
                continue;

            for (auto edge : adj[node]) {

                int neigh = edge.first;
                int wt = edge.second;

                int newD = distance + wt;

                if (newD < dist[neigh]) {
                    dist[neigh] = newD;
                    pq.push({newD, neigh});
                }
            }
        }

        int maxi = 0;

        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX)
                return -1;

            maxi = max(maxi, dist[i]);
        }

        return maxi;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto e : times) {

            int u = e[0];
            int v = e[1];
            int wt = e[2];

            adj[u].push_back({v, wt});
        }

        return dij(n, k, adj);
    }
};