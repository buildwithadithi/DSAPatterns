#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    class Disjoint{
        vector<int> rank, parent, size;
    public:  
        Disjoint(int n){
        rank.resize(n, 0);
        parent.resize(n);

        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }

        int findP(int node){
            if(node == parent[node]){
                return node;
            }
            return parent[node] = findP(parent[node]);
        }

        void unionByRank(int u, int v){
            int up_u = findP(u);
            int up_v = findP(v);

            if(up_u == up_v){
                return;
            }
            if(rank[up_u] > rank[up_v]){
                parent[up_v] = up_u;
            }else if(rank[up_u] < rank[up_v]){
                parent[up_u] = up_v;
            }else{
                parent[up_v] = up_u;
                rank[up_u]++;
            }
        }
        // void printP(){
        //     for(int i=0; i<parent.size(); i++){
        //         cout << "parent[" << i << "] = " << parent[i] << "\n";
        //     }
        // }
        };
    
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        Disjoint ds(n);
        vector<bool> res;
        for(int i=0; i<n-1; i++){
            if(abs(nums[i] - nums[i+1]) <= maxDiff){
                ds.unionByRank(i, i+1);
            }
        }
        // ds.printP();
        for(int i=0; i<queries.size(); i++){
        
            if(ds.findP(queries[i][0]) == ds.findP(queries[i][1])){
                res.push_back(true);
            }else{
                res.push_back(false);
            }
        }
        return res;
    }
};