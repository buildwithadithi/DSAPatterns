#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {

        vector<vector<int>> ans;
        int i = 0;
        int n = intervals.size();

        // Add all intervals before newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }

        // Merge overlapping intervals
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        ans.push_back(newInterval);

        // Add remaining intervals
        while (i < n) {
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};

//Given in question non-overlapping intervals(noi) are given. So u can optimise by adding all noi at first and last. only merge the overlapping part.

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);

        sort(intervals.begin(), intervals.end());
        int n = intervals.size();

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for(int i=1; i<n; i++){
            if(intervals[i][0] <= ans.back()[1]){
                ans.back()[1] = max(intervals[i][1], ans.back()[1]);
            }else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};