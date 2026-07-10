#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    int solve(int i, int W, vector<int>& val,
              vector<int>& wt, vector<vector<int>>& dp) {

        if (i == 0 || W == 0)
            return dp[i][W] = 0;

        if (dp[i][W] != -1)
            return dp[i][W];

        int take = 0;

        if (wt[i - 1] <= W)
            take = val[i - 1] +
                   solve(i - 1, W - wt[i - 1], val, wt, dp);

        int notTake = solve(i - 1, W, val, wt, dp);

        return dp[i][W] = max(take, notTake);
    }

    int knapsack(int W, vector<int>& val, vector<int>& wt) {

        int n = val.size();

        vector<vector<int>> dp(n + 1,
                               vector<int>(W + 1, -1));

        return solve(n, W, val, wt, dp);
    }
};