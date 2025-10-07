// 687_最长同值路径.cpp
#include "stdafx.h"
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
    int result = 0;
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int leftPath = dfs(root->left);
        int rightPath = dfs(root->right);
        int leftSamePath = 0;
        int rightSamePath = 0;
        if (root->left && root->left->val == root->val) {
            leftSamePath = leftPath + 1;
        }
        if (root->right && root->right->val == root->val) {
            rightSamePath = rightPath + 1;
        }
        result = max(result, leftSamePath + rightSamePath);
        return max(leftSamePath, rightSamePath);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        result = 0;
        dfs(root);
        return result;
    }
};
