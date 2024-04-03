// 1379_找出克隆二叉树中的相同节点.cpp
#include "custom.h"
ustd


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == nullptr) {
            return nullptr;
        }
        if (original == target) {
            return cloned;
        }
        auto left = getTargetCopy(original->left, cloned->left, target);
        auto right = getTargetCopy(original->right, cloned->right, target);
        return left ? left : right;
    }
};
