#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited){
        visited[node] = true;

        for(int neighbor: adj[node]){
            if(!visited[neighbor]){
                dfs(neighbor, adj, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        vector<vector<int>> adj(n, vector<int>(n, 0));
        vector<bool> visited(n, false);
        int count=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if((i!=j )&& (isConnected[i][j])){
                    adj[i].push_back(j);
                }
            }
        }
        
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(i, adj, visited);
                count += 1;
            }
        }
        return count;
    }
};