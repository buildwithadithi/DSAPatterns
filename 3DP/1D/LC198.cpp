//solve(i) = maximum money from the first i houses
/*Disadvantages:

* You constantly have to think, “Is i a house number or an array index?”
* The i - 1 adjustment appears repeatedly, making off-by-one errors more likely.
*/
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

//This is better approach
// Array indexed
//solve(i) = maximum money from houses 0 to i
/*
Advantages:

* ✅ Matches the array indexing directly.
* ✅ This is the version you’ll see in interviews, editorials, and most solutions.
* ✅ Easier to extend to variations like House Robber II.
* ✅ No need to convert between “number of houses” and array indices.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, vector<int>& nums, vector<int>& dp) {
        if (i < 0)
            return 0;

        if (i == 0)
            return nums[0];

        if (dp[i] != -1)
            return dp[i];

        int take = nums[i] + solve(i - 2, nums, dp);
        int notTake = solve(i - 1, nums, dp);

        return dp[i] = max(take, notTake);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(n - 1, nums, dp);
    }
};