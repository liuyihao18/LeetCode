// 998_×î´ó¶þ²æÊ÷_II.cpp
#include "stdafx.h"
ustd

//  Definition for a binary tree node.
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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if (val > root->val) {
            return new TreeNode(val, root, nullptr);
        }
        TreeNode* parent = nullptr;
        TreeNode* curr = root;
        while (curr && val < curr->val) {
            parent = curr;
            curr = curr->right;
        }
        parent->right = new TreeNode(val, curr, nullptr);
        return root;
    }
};
