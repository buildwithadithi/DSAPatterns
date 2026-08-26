#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution {
public:
    void dfs(TreeNode* root, int targetSum, vector<int> path, int sum, vector<vector<int>>& res){
        if(root == nullptr){
            return;
        }

        path.push_back(root->val);
        sum += root->val;

        if(!root->left && !root->right){
            if(sum == targetSum){
                res.push_back(path);
                return;
            }
        }
        dfs(root->left, targetSum, path, sum, res);
        dfs(root->right, targetSum, path, sum, res);

        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;
        
        dfs(root, targetSum, path, 0, res);
        return res;
    }
};