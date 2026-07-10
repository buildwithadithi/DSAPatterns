#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
	
	bool solve(int i, int sum, vector<int>& arr, vector<vector<int>> &dp) {
		if (sum == 0) {
			return dp[i][sum] = true;
		}
		
		if (i == 0) {
			return dp[i][sum] = false;
		}
		
		if (dp[i][sum] != -1)
			return dp[i][sum];
		
		bool notTake = solve(i - 1, sum, arr, dp);
		bool take = false;
		
		if (arr[i - 1] <= sum) {
			take = solve(i - 1, sum - arr[i - 1], arr, dp);
		}
		
		return dp[i][sum] = take || notTake;
	}
	bool isSubsetSum(vector<int>& arr, int sum) {
		// code here
		int n = arr.size();
		vector<vector<int>> dp(n+1, vector<int>(sum + 1, -1));
		return solve(n, sum, arr, dp);
	}
};