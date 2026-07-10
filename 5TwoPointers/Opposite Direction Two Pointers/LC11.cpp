#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r = height.size()-1;
        int maxArea = INT_MIN;

        while(l<r){
            int len = min(height[l], height[r]);
            int b = r-l;

            maxArea = max(maxArea, len*b);

            if(height[l] <= height[r]){
                l++;
            }else{
                r--;
            }
        }
        return maxArea;
    }
};