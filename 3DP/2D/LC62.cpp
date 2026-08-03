#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    int paths(int i, int j, int m, int n){
        if(i >=m || j>= n){
            return 0;
        }
        if(i == m-1 && j==n-1){
            return 1;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        return dp[i][j] = paths(i+1, j, m,n) + paths(i,j+1,m, n);
    }
    int uniquePaths(int m, int n) {
        dp.assign(m, vector<int>(n, -1));

        return paths(0,0,m, n);
    }
};