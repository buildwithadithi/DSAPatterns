#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited)
    {
        visited[node] = true;
        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                dfs(neighbor, adj, visited);
            }
        }
    }
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        for (auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(source, adj, visited);
        return (visited[destination]);
    }
};

/*
It passes because passing by value does not make the algorithm incorrect. It only makes it less efficient.

When you call:

dfs(source, adj, visited);

a copy of adj is created.

Then inside DFS:

dfs(neighbor, adj, visited);

another copy of adj is created.

And so on.

The important thing is that you never modify adj inside DFS. You're only reading from it:

for (int neighbor : adj[node])

So whether DFS uses the original graph or a copy of the graph, the traversal result is exactly the same.
Calling:

dfs(0, adj, visited);

creates:

adj_copy1

Then:

dfs(1, adj_copy1, visited);

creates:

adj_copy2

Both copies contain the same graph, so DFS still visits the correct nodes.

Why isn't it failing?

LeetCode tests for:

Correctness
Time limit

The graph sizes in this problem aren't large enough for the extra copying to always exceed the time limit.

So your solution is:

✅ Correct

but

❌ Unnecessarily expensive

What extra work is happening?

Assume:

n = 200000
edges = 200000

The adjacency list may contain hundreds of thousands of integers.

Every recursive call copies all of them:

dfs(neighbor, adj, visited);

So instead of:

O(V + E)

you are effectively doing something closer to:

O((V + E) × number_of_dfs_calls)

which can become enormous.
*/

/*class Solution {
public:
    bool dfs(int node, int destination,
             vector<vector<int>>& adj,
             vector<bool>& visited) {

        if (node == destination)
            return true;

        visited[node] = true;

        for (int nei : adj[node]) {
            if (!visited[nei] &&
                dfs(nei, destination, adj, visited))
                return true;
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges,
                   int source, int destination) {

        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return dfs(source, destination, adj, visited);
    }
};
*/