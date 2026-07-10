#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();
        int removed = 0;

        int minEnd = intervals[0][1];

        for (int i = 1; i < n; i++) {
            if (intervals[i][0] < minEnd) {
                // Overlap: remove one interval
                removed++;

                // Keep the interval with the smaller end time
                minEnd = min(minEnd, intervals[i][1]);
            } else {
                // No overlap: accept current interval
                minEnd = intervals[i][1];
            }
        }

        return removed;
    }
};