#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dp;
    int solve(int i, vector<int> &cost){
        if(i==0 || i==1){
            return 0;
        }
        if (dp[i] != -1)
            return dp[i];
            
        int tot_cost = min(cost[i-1]+solve(i-1, cost), cost[i-2]+solve(i-2, cost));

        return dp[i] = tot_cost;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.assign(n+1, -1);

        return solve(n, cost);
    }
};