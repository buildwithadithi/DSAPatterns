#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<int> len(n, 1);
        vector<int> count(n, 1);

        int maxi = 1;

        for(int i = 0; i < n; i++) {

            for(int prev = 0; prev < i; prev++) {

                if(nums[prev] < nums[i]) {

                    if(len[prev] + 1 > len[i]) {

                        len[i] = len[prev] + 1;
                        count[i] = count[prev];
                    }
                    else if(len[prev] + 1 == len[i]) {

                        count[i] += count[prev];
                    }
                }
            }

            maxi = max(maxi, len[i]);
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {

            if(len[i] == maxi)
                ans += count[i];
        }

        return ans;
    }
};