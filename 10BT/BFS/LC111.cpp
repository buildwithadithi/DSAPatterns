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
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        queue<TreeNode *> q;
        q.push(root);

        int depth = 1;

        while (!q.empty())
        {
            int size = q.size();

            while (size--)
            {
                TreeNode *node = q.front();
                q.pop();

                // First leaf we encounter = minimum depth
                if (node->left == nullptr && node->right == nullptr)
                    return depth;

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }

            depth++;
        }

        return depth;
    }
};

/*
class Solution {
public:
    int d(TreeNode* root) {
        if (root == nullptr) {
            return INT_MAX;
        }

        int left = d(root->left);
        int right = d(root->right);

        if (left == INT_MAX && right == INT_MAX) {
            return 1;
        }

        return 1 + min(left, right);
    }

    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return d(root);
    }
};
*/ 