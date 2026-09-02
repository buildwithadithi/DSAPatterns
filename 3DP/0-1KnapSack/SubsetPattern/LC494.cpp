#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int sum, vector<int>& nums) {

        if (i == nums.size())
            return (sum == 0);

        if (dp[i][sum] != -1)
            return dp[i][sum];

        int notTake = solve(i + 1, sum, nums);

        int take = 0;

        if (nums[i] <= sum)
            take = solve(i + 1, sum - nums[i], nums);

        return dp[i][sum] = take + notTake;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int totalSum = 0;

        for (int x : nums)
            totalSum += x;

        if (abs(target) > totalSum)
            return 0;

        if ((totalSum + target) % 2)
            return 0;

        int requiredSum = (totalSum + target) / 2;

        int n = nums.size();

        dp.assign(n, vector<int>(requiredSum + 1, -1));

        return solve(0, requiredSum, nums);
    }
};