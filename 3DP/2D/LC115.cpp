#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<long long>> dp;

    long long solve(int i, int j, string &s, string &t) {

        // Successfully formed the target string
        if (j == t.length())
            return 1;

        // Source string exhausted but target still remains
        if (i == s.length())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == t[j]) {
            // Take the current character OR skip it
            return dp[i][j] = solve(i + 1, j + 1, s, t)
                            + solve(i + 1, j, s, t);
        }

        // Characters don't match, skip current character of s
        return dp[i][j] = solve(i + 1, j, s, t);
    }

    int numDistinct(string s, string t) {

        int m = s.length();
        int n = t.length();

        dp.assign(m, vector<long long>(n, -1));

        return solve(0, 0, s, t);
    }
};