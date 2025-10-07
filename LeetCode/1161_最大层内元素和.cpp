// 1161_最大层内元素和.cpp
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
    struct State {
        TreeNode* node;
        int level;
        State(TreeNode* node, int level) : node(node), level(level) {}
    };
public:
    int maxLevelSum(TreeNode* root) {
        queue<State> q;
        q.emplace(root, 1);
        int maxSum = INT_MIN;
        int sum = 0;
        int maxSumLevel = 1;
        int currLevel = 1;
        while (!q.empty()) {
            State curr = q.front();
            q.pop();
            if (curr.level > currLevel) {
                if (sum > maxSum) {
                    maxSum = sum;
                    maxSumLevel = currLevel;
                }
                sum = 0;
                currLevel = curr.level;
            }
            sum += curr.node->val;
            if (curr.node->left) {
                q.emplace(curr.node->left, curr.level + 1);
            }
            if (curr.node->right) {
                q.emplace(curr.node->right, curr.level + 1);
            }
        }
        if (sum > maxSum) {
            maxSum = sum;
            maxSumLevel = currLevel;
        }
        return maxSumLevel;
    }
};
