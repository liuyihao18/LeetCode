// 572_ÁíÒ»¿ÃÊ÷µÄ×ÓÊ÷.cpp
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
    bool isStrictSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr) {
            return true;
        }
        else if (root == nullptr || subRoot == nullptr) {
            return false;
        }
        if (root->val != subRoot->val) {
            return false;
        }
        return isStrictSubtree(root->left, subRoot->left) && isStrictSubtree(root->right, subRoot->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr) {
            return true;
        }
        else if (root == nullptr || subRoot == nullptr) {
            return false;
        }
        if (isStrictSubtree(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
