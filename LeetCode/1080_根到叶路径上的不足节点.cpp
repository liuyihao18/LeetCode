// 1080_根到叶路径上的不足节点.cpp
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
    int sufficientSubset(TreeNode* root, int limit, int sum) {
        if (!root) return INT_MIN;
        sum += root->val;
        // 叶子节点
        if (!root->left && !root->right) {
            return sum;
        }
        // 非叶节点
        int left_sum = sufficientSubset(root->left, limit, sum);
        if (left_sum < limit) {
            delete root->left;
            root->left = nullptr;
        }
        int right_sum = sufficientSubset(root->right, limit, sum);
        if (right_sum < limit) {
            delete root->right;
            root->right = nullptr;
        }
        return max(left_sum, right_sum);
    }
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        int sum = sufficientSubset(root, limit, 0);
        if (sum < limit) return nullptr;
        else return root;
    }
};
