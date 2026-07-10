#include <bits/stdc++.h>
class Solution {
public:
    bool canFinish(int speed, vector<int>& piles, int h) {
        long long totalHr = 0;

        for (int pile : piles) {
            totalHr += (1LL * pile + speed - 1) / speed;

            if (totalHr > h)
                return false;
        }

        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canFinish(mid, piles, h))
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};