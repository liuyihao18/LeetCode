// 337_¥Úº“ΩŸ…·_III.cpp
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
    pair<int, int> _rob(TreeNode* root) {
        if (!root) {
            return { 0,0 };
        }
        pair<int, int> lres = _rob(root->left);
        pair<int, int> rres = _rob(root->right);
        return { root->val + lres.second + rres.second, max(lres.first, lres.second) + max(rres.first, rres.second) };
    }
public:
    int rob(TreeNode* root) {
        pair<int, int> res = _rob(root);
        return max(res.first, res.second);
    }
};
