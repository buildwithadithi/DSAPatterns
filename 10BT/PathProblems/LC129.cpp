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
    void dfs(TreeNode* root, string path, int& sum) {

        if (root == nullptr) {
            return;
        }

        path += to_string(root->val);

        if(!root->left && !root->right){
            sum += stoi(path);
            return;
        }

        dfs(root->left, path, sum);
        dfs(root->right, path, sum);

        return;
    }

        int sumNumbers(TreeNode * root) {

            int sum = 0;
            string path = "";
            dfs(root, path, sum);
            return sum;
        }
    };