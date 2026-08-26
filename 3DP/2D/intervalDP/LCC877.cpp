#include <bits/stdc++.h>
using namespace std;
// Our function returns
// game(i, j)

// =

// Maximum score difference (Current Player − Other Player) from interval [i...j].
class Solution {
public:
    vector<vector<int>> dp;
    int game(int i, int j, vector<int>& piles){
            if (i == j){
                return piles[i];
            }
            if (dp[i][j]!=-1){
                return dp[i][j];
            }
            int left = piles[i] - game(i+1, j, piles);
            int right = piles[j] - game(i, j-1, piles);
            return dp[i][j] = max(left, right);
    }
    

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        dp.assign(n, vector<int> (n, -1));
        int diff = game(0, n-1, piles);
        return (diff>0);
    } 
};