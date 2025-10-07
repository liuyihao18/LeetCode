// 1302_层数最深叶子节点的和.cpp
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
    int deepestLeavesSum(TreeNode* root) {
        queue<pair<TreeNode*, size_t>> q;
        q.emplace(root, 1);
        int currSum = 0;
        size_t currDepth = 0;
        while (!q.empty()) {
            pair<TreeNode*, size_t> curr = q.front();
            q.pop();
            auto node = curr.first;
            auto depth = curr.second;
            if (depth > currDepth) {
                currSum = 0;
                currDepth = depth;
            }
            currSum += node->val;
            if (node->left) q.emplace(node->left, depth + 1);
            if (node->right) q.emplace(node->right, depth + 1);
        }
        return currSum;
    }
};
