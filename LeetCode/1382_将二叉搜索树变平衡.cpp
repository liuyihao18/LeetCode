// 1382_将二叉搜索树变平衡.cpp
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
private:
    vector<int> orders;

    void inOrder(TreeNode* root) {
        if (!root) return;
        inOrder(root->left);
        orders.emplace_back(root->val);
        inOrder(root->right);
    }

    void build(TreeNode*& root, int left, int right) {
        if (left > right) return;
        int mid = (left + right) >> 1;
        root = new TreeNode(orders[mid]);
        build(root->left, left, mid - 1);
        build(root->right, mid + 1, right);
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        inOrder(root);
        build(root, 0, static_cast<int>(orders.size() - 1));
        return root;
    }
};
