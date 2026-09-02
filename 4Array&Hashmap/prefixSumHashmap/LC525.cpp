#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n);
        int currSum = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        int maxi = 0;

        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                nums[i] = -1;
            }
        }

        for(int j=0; j<n; j++){
            currSum += nums[j];
            
            if(mp.count(currSum)){
                maxi = max(maxi, j-mp[currSum]);
            }else{
                mp[currSum] = j;
            }
        }
        return maxi;
    }
};

// no need to store prefix, think if u really need it.