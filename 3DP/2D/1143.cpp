#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;

    int lcs(int i, int j, string& t1, string& t2){
        if(i == t1.length() || j == t2.length()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(t1[i] == t2[j]){
            dp[i][j] = 1 + lcs(i+1, j+1, t1, t2);
        }else{
            dp[i][j] = max(lcs(i+1, j, t1, t2), lcs(i, j+1, t1, t2));
        }
        return dp[i][j];
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();

        dp.assign(m, vector<int> (n, -1));
        return lcs(0, 0, text1, text2);
    }
};