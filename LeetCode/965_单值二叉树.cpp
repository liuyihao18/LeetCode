// 965_µ¥Öµ¶þ²æÊ÷.cpp
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
    bool bfs(TreeNode* root, int val) {
        if (!root) return true;
        if (root->val != val) return false;
        return bfs(root->left, val) && bfs(root->right, val);
    }
public:
    bool isUnivalTree(TreeNode* root) {
        if (!root) return false;
        int val = root->val;
        return bfs(root, val);
    }
};