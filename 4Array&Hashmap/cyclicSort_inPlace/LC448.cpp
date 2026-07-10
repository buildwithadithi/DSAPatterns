#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> mp;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            mp.insert(nums[i]);
        }

        for(int j=1; j<=nums.size(); j++){
            if(!mp.count(j)){
                ans.push_back(j);
            }
        }
        return ans;
    }
};