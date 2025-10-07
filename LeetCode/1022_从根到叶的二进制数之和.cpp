// 1022_从根到叶的二进制数之和.cpp
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
    void dfs(TreeNode* root, int num, int& sum) {
        num = (num << 1) | root->val;
        if (root->left == nullptr && root->right == nullptr) {
            sum += num;
        }
        if (root->left) {
            dfs(root->left, num, sum);
        }
        if (root->right) {
            dfs(root->right, num, sum);
        }
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        if (root) {
            int num = 0, sum = 0;
            dfs(root, num, sum);
            return sum;
        }
        else {
            return 0;
        }
    }
};
