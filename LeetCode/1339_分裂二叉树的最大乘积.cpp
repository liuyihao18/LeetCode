// 1339_分裂二叉树的最大乘积.cpp
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
    unordered_map<const TreeNode*, long long> treeSum;
    long long calculateSum(const TreeNode* root)
    {
        if (root == nullptr) return 0;
        const long long leftSum = calculateSum(root->left);
        const long long rightSum = calculateSum(root->right);
        return treeSum[root] = leftSum + rightSum + root->val;
    }
    long long calculateMaxProduct(const TreeNode* root, const long long allSum)
    {
        long long product = 0;
	    if (root->left)
	    {
            product = max(product, treeSum[root->left] * (allSum - treeSum[root->left]));
            product = max(product, calculateMaxProduct(root->left, allSum));
	    }
        if (root->right)
        {
            product = max(product, treeSum[root->right] * (allSum - treeSum[root->right]));
            product = max(product, calculateMaxProduct(root->right, allSum));
        }
        return product;
    }
public:
    int maxProduct(const TreeNode* root) {
        calculateSum(root);
        return static_cast<int>(
            calculateMaxProduct(root, treeSum[root]) % static_cast<int>(1e9 + 7)
            );
    }
};
