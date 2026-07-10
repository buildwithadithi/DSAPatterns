#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> mp;
        mp[0] = 1;

        int currSum = 0;
        int ans = 0;

        for (int num : nums) {
            currSum += num;

            if (mp.count(currSum - k))
                ans += mp[currSum - k];

            mp[currSum]++;
        }

        return ans;
    }
};