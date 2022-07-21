// 814_¶þ²æÊ÷¼ôÖ¦.cpp
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
    bool prune(TreeNode* root) {
        bool left1 = root->left ? prune(root->left) : false;
        if (!left1) root->left = nullptr;
        bool right1 = root->right ? prune(root->right) : false;
        if (!right1) root->right = nullptr;
        return left1 || right1 || root->val == 1;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (prune(root)) return root;
        else return nullptr;
    }
};
