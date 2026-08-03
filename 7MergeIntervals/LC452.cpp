#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
    if (points.empty()) return 0;

    sort(points.begin(), points.end());

    vector<vector<int>> ans;
    ans.push_back(points[0]);

    for (int i = 1; i < points.size(); i++) {
        if (points[i][0] <= ans.back()[1]) {
            ans.back()[1] = min(ans.back()[1], points[i][1]);
        } else {
            ans.push_back(points[i]);
        }
    }
    return ans.size();
}
};