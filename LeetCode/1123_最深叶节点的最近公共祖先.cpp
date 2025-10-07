// 1123_最深叶节点的最近公共祖先.cpp
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
    pair<TreeNode*, int> dfs(TreeNode* root) {
        if (!root) {
            return { root, -1 };
        }
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        if (left.second > right.second) {
            return { left.first, left.second + 1 };
        }
        if (right.second > left.second) {
            return { right.first, right.second + 1 };
        }
        return { root, left.second + 1 };
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).first;
    }
};
