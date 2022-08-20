// 654_×î´ó¶þ²æÊ÷.cpp
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
    using pos = vector<int>::iterator;
    TreeNode* constructMaximumBinaryTree(vector<int>& nums, pos l, pos r) {
        if (r == l) {
            return nullptr;
        }
        auto m = max_element(l, r);
        TreeNode* root = new TreeNode(*m);
        root->left = constructMaximumBinaryTree(nums, l, m);
        root->right = constructMaximumBinaryTree(nums, m + 1, r);
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinaryTree(nums, nums.begin(), nums.end());
    }
};
