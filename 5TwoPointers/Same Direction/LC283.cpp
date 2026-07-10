#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};

/*
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l=0;
        int r=1;
        int n = nums.size();

        while(r<n){
            if(nums[l] == 0){
                if(nums[r]!=0){
                    swap(nums[l], nums[r]);
                    l++;
                    r++;
                }else{
                    r++;
                    cout<< "r in else: "<< r;
                }
            }else{
                l++;
                r++;
            }
        }
    }
};
*/