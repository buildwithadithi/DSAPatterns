#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int node, vector<vector<int>> &rooms, vector<bool> &visited)
    {

        visited[node] = true;

        for (int neighbor : rooms[node])
        {

            if (!visited[neighbor])
            {
                dfs(neighbor, rooms, visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int n = rooms.size();
        vector<bool> visited(n, false);

        dfs(0, rooms, visited);

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                return false;
            }
        }
        return true;
    }
};