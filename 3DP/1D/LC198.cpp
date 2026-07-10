#include <bits/stdc++.h>
class Solution {
public:
    int solve(int i, vector<int>& dp,vector<int>& nums){
        if(i==0){
            return dp[0] = 0;
        }
        if(i==1){
            return dp[1] = nums[0];
        }
        if(dp[i]!=-1){
            return dp[i];
        }

        int take = solve(i-2, dp, nums) + nums[i-1];
        int notTake =  solve(i-1, dp, nums);

        return dp[i] = max(take, notTake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1, -1);
        return solve(n, dp, nums);
    }
};