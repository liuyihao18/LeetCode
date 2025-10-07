// 623_在二叉树中增加一行.cpp
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
        int depth;
        State(TreeNode* node, int depth) : node(node), depth(depth) {}
    };
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val, root, nullptr);
            return newRoot;
        }
        queue<State> q;
        q.emplace(root, 1);
        while (!q.empty()) {
            State curr = q.front();
            if (curr.depth == depth - 1) {
                break;
            }
            q.pop();
            if (curr.node->left) {
                q.emplace(curr.node->left, curr.depth + 1);
            }
            if (curr.node->right) {
                q.emplace(curr.node->right, curr.depth + 1);
            }
        }
        while (!q.empty()) {
            State curr = q.front();
            q.pop();
            TreeNode* newLeftNode = new TreeNode(val, nullptr, nullptr);
            TreeNode* newRightNode = new TreeNode(val, nullptr, nullptr);
            if (curr.node->left) {
                newLeftNode->left = curr.node->left;
            }
            if (curr.node->right) {
                newRightNode->right = curr.node->right;
            }
            curr.node->left = newLeftNode;
            curr.node->right = newRightNode;
        }
        return root;
    }
};
