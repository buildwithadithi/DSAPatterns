#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int prev;
    int mini = INT_MAX;
    bool first = true;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (!first) {
            mini = min(mini, root->val - prev);
        }

        prev = root->val;
        first = false;

        inorder(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return mini;
    }
};

class Solution {
public:
    int prev = -1;
    int mini = INT_MAX;

    void inorder(TreeNode* root) {
        if (!root) {
            return;
        }

        inorder(root->left);

        if (prev != -1) {
            mini = min(mini, root->val - prev);
        }

        prev = root->val;

        inorder(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return mini;
    }
};