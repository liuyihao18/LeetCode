// 1609_ÆæÅ¼Ê÷.cpp
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
    map<int, int> level_val;
    bool dfs(TreeNode* root, int level) {
        if (!root) {
            return true;
        }
        if (level & 1) {
            if (root->val & 1) {
                return false;
            }
            if (level_val.find(level) != level_val.end() && root->val >= level_val[level]) {
                return false;
            }
        }
        else {
            if (!(root->val & 1)) {
                return false;
            }
            if (level_val.find(level) != level_val.end() && root->val <= level_val[level]) {
                return false;
            }
        }
        level_val[level] = root->val;
        return dfs(root->left, level + 1) && dfs(root->right, level + 1);
    }
public:
    bool isEvenOddTree(TreeNode* root) {
        return dfs(root, 0);
    }
};
