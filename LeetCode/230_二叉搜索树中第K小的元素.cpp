// 230_二叉搜索树中第K小的元素.cpp
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
    void _kthSmallest(TreeNode* root, vector<int>& arr) {
        if (root->left) {
            _kthSmallest(root->left, arr);
        }
        arr.push_back(root->val);
        if (root->right) {
            _kthSmallest(root->right, arr);
        }
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;
        if (root) {
            _kthSmallest(root, arr);
        }
        return arr[k - 1];
    }
};
