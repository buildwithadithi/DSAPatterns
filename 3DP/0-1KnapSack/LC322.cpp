#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int idx, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        // Amount formed
        if (amount == 0)
            return 1;

        // No coins left
        if (idx == coins.size())
            return 0;

        if (dp[idx][amount] != -1)
            return dp[idx][amount];

        // Skip current coin
        int notTake = solve(idx + 1, amount, coins, dp);

        // Take current coin (stay at same index)
        int take = 0;
        if (coins[idx] <= amount)
            take = solve(idx, amount - coins[idx], coins, dp);

        return dp[idx][amount] = take + notTake;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        return solve(0, amount, coins, dp);
    }
};