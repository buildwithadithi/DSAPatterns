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
    int leftH(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        return 1 + leftH(root->left);
    }

    int rightH(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        return 1 + rightH(root->right);
    }

    int countNodes(TreeNode* root) {

        if (root == nullptr) {
            return 0;
        }

        int left = leftH(root->left);
        int right = rightH(root->right);

        if(left == right){
            return (1 << (left + 1)) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};