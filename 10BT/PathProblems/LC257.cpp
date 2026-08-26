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
    void dfs(TreeNode* root, vector<string>& res, string path) {
        if (root == nullptr) {
            return;
        }

        if (!path.empty()) {
            path += "->";
        }

        path += to_string(root->val);

        if (root->left == nullptr && root->right == nullptr) {
            res.push_back(path);
            return;
        }

        dfs(root->left, res, path);
        dfs(root->right, res, path);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        dfs(root, res, "");
        return res;
    }
};