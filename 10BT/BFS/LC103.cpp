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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        queue<TreeNode *> q;
        vector<vector<int>> res;

        if (root == nullptr)
        {
            return res;
        }
        q.push(root);
        int level = 0;

        while (!q.empty())
        {
            int size = q.size();
            vector<int> ans;
            while (size--)
            {
                TreeNode *node = q.front();
                q.pop();

                ans.push_back(node->val);

                if (node->left)
                {
                    q.push(node->left);
                }

                if (node->right)
                {
                    q.push(node->right);
                }
            }

            if (level % 2 == 0)
            {
                res.push_back(ans);
            }
            else
            {
                reverse(ans.begin(), ans.end());
                res.push_back(ans);
            }
            level++;
        }
        return res;
    }
};