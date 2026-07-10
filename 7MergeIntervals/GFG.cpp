//Meeting room

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canAttend(vector<vector<int>> &arr) {
        sort(arr.begin(), arr.end());

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i][0] < arr[i - 1][1])
                return false;
        }

        return true;
    }
};

// ans is not required since we donot merge intervals here. Only comparing with previous vector is enough since it is sorted.
class Solution {
public:
    bool canAttend(vector<vector<int>> &arr) {
        sort(arr.begin(), arr.end());

        vector<vector<int>> ans;
        ans.push_back(arr[0]);

        int n = arr.size();

        for (int i = 1; i < n; i++) {
            if (arr[i][0] < ans.back()[1]) {
                return false;
            } else {
                ans.push_back(arr[i]);
            }
        }
        return true;
    }
};