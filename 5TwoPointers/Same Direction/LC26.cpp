#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l=0;
        int r=1;
        int n=nums.size();

        while(r<n){
            if(nums[l] == nums[r]){
                r++;
            }else{
                nums[l+1] = nums[r];
                l++;
                r++;
            }
        }
        return l+1;
    }
};