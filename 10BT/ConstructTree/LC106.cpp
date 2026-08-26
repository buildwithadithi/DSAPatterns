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
    TreeNode* buildTreeHelper(vector<int>& postorder, int inStart, int inEnd, int& postIndex, unordered_map<int,int>& inMap) {
        if (inStart > inEnd) return nullptr;

        // Pick current root from postorder
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        // Find root in inorder
        int inRoot = inMap[rootVal];

        // Important: build RIGHT before LEFT
        root->right = buildTreeHelper(postorder, inRoot + 1, inEnd, postIndex, inMap);
        root->left  = buildTreeHelper(postorder, inStart, inRoot - 1, postIndex, inMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> inMap;
        for (int i = 0; i < inorder.size(); i++)
            inMap[inorder[i]] = i;
        
        int postIndex = postorder.size() - 1; // start from last element of postorder
        return buildTreeHelper(postorder, 0, inorder.size() - 1, postIndex, inMap);
    }
};