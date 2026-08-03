#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;

    int edit(int i, int j, string &word1, string &word2) {

        // word1 exhausted -> insert remaining characters of word2
        if (i == word1.length())
            return word2.length() - j;

        // word2 exhausted -> delete remaining characters of word1
        if (j == word2.length())
            return word1.length() - i;

        if (dp[i][j] != -1)
            return dp[i][j];

        // Characters already match
        if (word1[i] == word2[j])
            return dp[i][j] = edit(i + 1, j + 1, word1, word2);

        // Replace
        int replace = edit(i + 1, j + 1, word1, word2);

        // Delete
        int del = edit(i + 1, j, word1, word2);

        // Insert
        int insert = edit(i, j + 1, word1, word2);

        return dp[i][j] = 1 + min({replace, del, insert});
    }

    int minDistance(string word1, string word2) {

        int m = word1.length();
        int n = word2.length();

        dp.assign(m, vector<int>(n, -1));

        return edit(0, 0, word1, word2);
    }
};