// 110_Æ½ºâ¶þ²æÊ÷.cpp
#include "stdafx.h"
ustd

namespace {
    // Definition for a binary tree node.
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    };
}

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (!isBalanced(root->left)) return false;
        if (!isBalanced(root->right)) return false;
        int lHeight = getHeight(root->left);
        int rHeight = getHeight(root->right);
        if (abs(lHeight - rHeight) > 1) return false;
        return true;
    }
private:
    map<TreeNode*, int> heights;

    int getHeight(TreeNode* root) {
        if (!root) return 0;
        if (heights.count(root)) return heights[root];
        int lHeight = getHeight(root->left);
        int rHeight = getHeight(root->right);
        return heights[root] = max(lHeight, rHeight) + 1;
    }
};
