// 437_Â·¾¶×ÜºÍ III.cpp
#include "custom.h"
ustd

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void _dfs(TreeNode* root,vector<int>& vals, int targetSum, int& result) {
        if (!root) {
            return;
        }
        vals.push_back(root->val);
        int sum = 0;
        for (auto iter = vals.rbegin(); iter != vals.rend(); ++iter) {
            sum += *iter;
            if (sum == targetSum) {
                ++result;
            }
        }
        _dfs(root->left, vals, targetSum, result);
        _dfs(root->right, vals, targetSum, result);
        vals.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> vals;
        int result{ 0 };
        _dfs(root, vals, targetSum, result);
        return result;
    }
};