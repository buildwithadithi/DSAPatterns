#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int, int>>> adj(n);

        for (auto e : flights) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            adj[u].push_back({v, wt});
        }

        // cost, node, flights taken
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

        dist[src][0] = 0;
        pq.push({0, src, 0});

        while (!pq.empty()) {

            auto current = pq.top();
            int cost = get<0>(current);
            int node = get<1>(current);
            int flightsTaken = get<2>(current);
            pq.pop();

            if (node == dst)
                return cost;

            if (flightsTaken == k + 1)
                continue;

            for (pair<int, int> edge : adj[node]) {
                int neigh = edge.first;
                int wt = edge.second;

                int newCost = cost + wt;
                int newFlights = flightsTaken + 1;

                if (newCost < dist[neigh][newFlights]) {

                    dist[neigh][newFlights] = newCost;

                    pq.push({
                        newCost,
                        neigh,
                        newFlights
                    });
                }
            }
        }

        return -1;
    }
};