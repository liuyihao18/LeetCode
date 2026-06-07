// 2196_根据描述创建二叉树.cpp
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_map<int, bool> isRoot;
        for (const vector<int>& description : descriptions) {
            const int parent = description[0];
            const int child = description[1];
            const int isLeft = description[2];
            if (!nodes.contains(parent)) {
                nodes[parent] = new TreeNode(parent);
                isRoot[parent] = true;
            }
            if (!nodes.contains(child)) {
                nodes[child] = new TreeNode(child);
            }
            isRoot[child] = false;
            if (isLeft) {
                nodes[parent]->left = nodes[child];
            }
            else {
                nodes[parent]->right = nodes[child];
            }
        }
        for (auto&& [key, val] : isRoot) {
            if (val) {
                return nodes[key];
            }
        }
        return nullptr;
    }
};
