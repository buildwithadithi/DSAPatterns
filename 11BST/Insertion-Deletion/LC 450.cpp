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
    TreeNode* findMin(TreeNode* root) {
        if (!root->left) {
            return root;
        }
        return findMin(root->left);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return nullptr;
        }

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }
            else if (!root->left) {
                return root->right;
            }
            else if (!root->right) {
                return root->left;
            }
            else {
                TreeNode* inO = findMin(root->right);
                root->val = inO->val;
                root->right = deleteNode(root->right, inO->val);
            }
        }

        return root;
    }
};