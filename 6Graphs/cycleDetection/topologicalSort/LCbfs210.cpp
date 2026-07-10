#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build graph
        for (auto &edge : prerequisites) {
            int course = edge[0];
            int prereq = edge[1];

            adj[prereq].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        // Push all courses having indegree 0
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> ans;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (int neigh : adj[node]) {
                indegree[neigh]--;

                if (indegree[neigh] == 0)
                    q.push(neigh);
            }
        }

        // Cycle exists
        if (ans.size() != numCourses)
            return {};

        return ans;
    }
};