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
    vector<double> averageOfLevels(TreeNode *root)
    {

        vector<double> ans;

        queue<TreeNode *> q;

        if (root == nullptr)
        {
            return ans;
        }

        q.push(root);
        int size;

        while (!q.empty())
        {

            size = q.size();
            int n = size;
            long long int sum = 0;

            while (size > 0)
            {
                TreeNode *node = q.front();
                q.pop();

                sum += node->val;

                if (node->left)
                {
                    q.push(node->left);
                }

                if (node->right)
                {
                    q.push(node->right);
                }
                size--;
            }
            double avg = (double)sum / n;
            ans.push_back(avg);
        }
        return ans;
    }
};