// 515_在每个树行中找最大值.cpp
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
        int height;
        State(TreeNode* node, int height) : node(node), height(height) {}
    };
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root) {
            return {};
        }
        queue<State> q;
        q.emplace(root, 0);
        int currHeight = 0;
        int currMax = INT_MIN;
        vector<int> result;
        while (!q.empty()) {
            State curr = q.front();
            q.pop();
            if (curr.height > currHeight) {              
                currHeight++;
                result.push_back(currMax);
                currMax = INT_MIN;
            }
            currMax = max(currMax, curr.node->val);
            if (curr.node->left) {
                q.emplace(curr.node->left, curr.height + 1);
            }
            if (curr.node->right) {
                q.emplace(curr.node->right, curr.height + 1);
            }
        }
        result.push_back(currMax);
        return result;
    }
};
