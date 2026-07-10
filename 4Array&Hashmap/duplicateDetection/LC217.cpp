#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> mp;

        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size(); i++){
            if(mp.count(nums[i])){
                return true;
            }
            mp.insert(nums[i]);
        }
        return false;
    }
};