#include <bits/stdc++.h>
#include <vector>

class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool isLeftBoundary) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {

                if (isLeftBoundary) {
                    ans = mid;
                    high = mid - 1;
                }
                else {
                    ans = mid;
                    low = mid + 1;
                }

            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = binarySearch(nums, target, true);
        int last  = binarySearch(nums, target, false);

        return {first, last};
    }
};