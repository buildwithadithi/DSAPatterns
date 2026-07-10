#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dp;

    int solve(int i, string &s) {
        int n = s.size();

        if (i == n)
            return 1;

        if (s[i] == '0')
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int ways = solve(i + 1, s);

        if (i + 1 < n) {
            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');

            if (num >= 10 && num <= 26)
                ways += solve(i + 2, s);
        }

        return dp[i] = ways;
    }

    int numDecodings(string s) {
        int n = s.size();
        dp.assign(n, -1);

        return solve(0, s);
    }
};