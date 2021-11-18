// 563_¶þ²æÊ÷µÄÆÂ¶È.cpp
#include "custom.h"
ustd

/**
 * Definition for a binary tree node.
 */ 
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
 
class Solution {
    int tilt = 0;
    int _sum(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int sum_left = _sum(root->left);
        int sum_right = _sum(root->right);
        tilt += abs(sum_left - sum_right);
        return sum_left + root->val + sum_right;
    }
    int _tilt(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return abs(_sum(root->left) - _sum(root->right)) + _tilt(root->left) + _tilt(root->right);
    }
public:
    int findTilt(TreeNode* root) {
        _sum(root);
        return tilt;
    }
};
