#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool binarySearch(int row, int target, vector<vector<int>>& matrix) {
        int low = 0;
        int high = matrix[0].size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (matrix[row][mid] == target)
                return true;
            else if (matrix[row][mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;

        int m = matrix.size();
        int n = matrix[0].size();

        int top = 0, bottom = m - 1;

        while (top <= bottom) {
            int midRow = top + (bottom - top) / 2;

            if (target >= matrix[midRow][0] &&
                target <= matrix[midRow][n - 1]) {
                return binarySearch(midRow, target, matrix);
            }
            else if (target < matrix[midRow][0]) {
                bottom = midRow - 1;
            }
            else {
                top = midRow + 1;
            }
        }

        return false;
    }
};