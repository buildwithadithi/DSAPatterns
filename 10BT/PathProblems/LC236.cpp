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

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root,
                                   TreeNode *p,
                                   TreeNode *q)
    {

        if (root == nullptr || root == p || root == q)
        {
            return root;
        }

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left != nullptr && right != nullptr)
        {
            return root;
        }

        if (left != nullptr)
        {
            return left;
        }

        return right;
    }
};

class Solution
{
public:
    bool search(TreeNode *root, TreeNode *k, vector<TreeNode *> &path)
    {

        if (root == nullptr)
        {
            return false;
        }

        path.push_back(root);

        if (root == k)
        {
            return true;
        }

        if (search(root->left, k, path) || search(root->right, k, path))
        {
            return true;
        }

        path.pop_back();
        return false;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root,
                                   TreeNode *p,
                                   TreeNode *q)
    {

        vector<TreeNode *> pp;
        vector<TreeNode *> qp;

        search(root, p, pp);
        search(root, q, qp);

        int i = 0;
        TreeNode *ans = nullptr;

        while (i < pp.size() &&
               i < qp.size() &&
               pp[i] == qp[i])
        {

            ans = pp[i];
            i++;
        }

        return ans;
    }
};