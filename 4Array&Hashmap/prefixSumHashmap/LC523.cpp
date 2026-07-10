#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        mp[0] = -1;  // handles subarrays starting from index 0

        int prefixSum = 0;

        for(int i = 0; i < nums.size(); i++) {

            prefixSum += nums[i];

            int rem = prefixSum % k;

            if(mp.count(rem)) {

                if(i - mp[rem] >= 2)
                    return true;

            } else {

                mp[rem] = i; // store first occurrence only
            }
        }

        return false;
    }
};