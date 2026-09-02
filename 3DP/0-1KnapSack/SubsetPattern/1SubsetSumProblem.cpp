#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	vector<vector<int>> dp;

	bool solve(int i, int sum, vector<int> &arr)
	{

		if (sum == 0)
			return true;

		if (i == arr.size())
			return false;

		if (dp[i][sum] != -1)
			return dp[i][sum];

		bool notTake = solve(i + 1, sum, arr);

		bool take = false;

		if (arr[i] <= sum)
			take = solve(i + 1, sum - arr[i], arr);

		return dp[i][sum] = take || notTake;
	}

	bool isSubsetSum(vector<int> &arr, int sum)
	{

		int n = arr.size();

		dp.assign(n, vector<int>(sum + 1, -1));
		return solve(0, sum, arr);
	}
};