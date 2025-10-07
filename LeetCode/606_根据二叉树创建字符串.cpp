// 606_根据二叉树创建字符串.cpp
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
public:
    string tree2str(TreeNode* root) {
        string result = to_string(root->val);
        if (root->right) {
            result += '(';
            if (root->left) {
                result += tree2str(root->left);
            }
            result += ')';
            result += '(';
            result += tree2str(root->right);
            result += ')';
        }
        else if (root->left) {
            result += '(';
            result += tree2str(root->left);
            result += ')';
        }
        return result;
    }
};
