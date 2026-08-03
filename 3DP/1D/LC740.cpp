#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dp;

    int solve(int i, int maxVal, vector<int>& points) {
        if (i > maxVal)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        return dp[i] = max(
            points[i] + solve(i + 2, maxVal, points),
            solve(i + 1, maxVal, points)
        );
    }

    int deleteAndEarn(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());

        vector<int> points(maxVal + 1, 0);

        for (int num : nums)
            points[num] += num;

        dp.assign(maxVal + 1, -1);

        return solve(0, maxVal, points);
    }
};