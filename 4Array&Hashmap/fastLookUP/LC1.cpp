#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (index.count(complement)) {
                return {index[complement], i};  
            }
            index[nums[i]] = i; 
        }
        return {-1, -1};
    }
};