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

class Solution
{
public:
    int cnt = 0;
    void inorder(TreeNode *root, int &ans, int k)
    {
        if (root == NULL)
            return;
        // left, root, right
        inorder(root->left, ans, k);

        cnt++;
        if (cnt == k)
        {
            ans = root->val;
            return;
        }

        inorder(root->right, ans, k);
    }
    int kthSmallest(TreeNode *root, int k)
    {

        int ans;
        inorder(root, ans, k);
        return ans;
    }
};