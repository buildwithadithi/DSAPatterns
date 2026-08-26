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
    int preIndex = 0;  // global index for preorder traversal

    TreeNode* buildTreeHelper(vector<int>& preorder, int inStart, int inEnd, unordered_map<int,int>& inMap) {
        if (inStart > inEnd) return nullptr;

        // Pick current root from preorder
        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        // Split inorder into left and right parts
        int inRoot = inMap[rootVal];

        // Build left and right subtrees
        root->left = buildTreeHelper(preorder, inStart, inRoot - 1, inMap);
        root->right = buildTreeHelper(preorder, inRoot + 1, inEnd, inMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inMap;
        for (int i = 0; i < inorder.size(); i++)
            inMap[inorder[i]] = i;

        return buildTreeHelper(preorder, 0, inorder.size() - 1, inMap);
    }
};