#include <bits/stdc++.h>
class Solution {
public:
    bool isPossible(int cap, vector<int> &weights, int days){
        int count = 1;  // Start with day 1
        int sum = 0;

        for(int i = 0; i < weights.size(); i++){

            // If a single package exceeds capacity
            if(weights[i] > cap)
                return false;

            if(sum + weights[i] > cap){
                count++;
                sum = weights[i];
            }else{
                sum += weights[i];
            }
        }

        return count <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int low = *max_element(weights.begin(), weights.end());
        int high = 0;

        for(int i = 0; i < n; i++){
            high += weights[i];
        }

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(isPossible(mid, weights, days)){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return low;
    }
};