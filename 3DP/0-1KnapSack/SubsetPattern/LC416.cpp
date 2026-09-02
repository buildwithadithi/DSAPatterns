#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(int i, int sum, vector<int>& arr, vector<vector<int>>& dp) {

        if (sum == 0)
            return true;

        if (i == arr.size())
            return false;

        if (dp[i][sum] != -1)
            return dp[i][sum];

        bool notTake = solve(i + 1, sum, arr, dp);

        bool take = false;

        if (arr[i] <= sum)
            take = solve(i + 1, sum - arr[i], arr, dp);

        return dp[i][sum] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {

        int totSum = 0;

        for (int x : nums)
            totSum += x;

        if (totSum % 2)
            return false;

        int target = totSum / 2;
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return solve(0, target, nums, dp);
    }
};

// if you want to partition the array into two subsets with
//  equal sum, the total sum must be even.