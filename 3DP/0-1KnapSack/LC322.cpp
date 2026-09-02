#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solve(int index, int amount,
              vector<int>& coins,
              vector<vector<int>>& dp) {

        // Amount completed
        if (amount == 0)
            return 0;

        // No coins left
        if (index == coins.size())
            return 1e9;

        if (dp[index][amount] != -1)
            return dp[index][amount];

        // Not Take
        int notTake =
            solve(index + 1, amount, coins, dp);

        // Take
        int take = 1e9;

        if (coins[index] <= amount) {
            take = 1 + solve(
                index,
                amount - coins[index],
                coins,
                dp
            );
        }

        return dp[index][amount] =
            min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(amount + 1, -1)
        );

        int ans = solve(0, amount, coins, dp);

        return (ans >= 1e9) ? -1 : ans;
    }
};