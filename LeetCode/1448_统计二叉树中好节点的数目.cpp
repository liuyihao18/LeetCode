// 1448_统计二叉树中好节点的数目.cpp
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
    using State = pair<TreeNode*, int>;
public:
    int goodNodes(TreeNode* root) {
        int result = 0;
        queue<State> q;
        q.emplace(root, INT_MIN);
        while (!q.empty()) {
            State s = q.front();
            q.pop();
            if (s.first->val >= s.second) {
                result++;
            }
            if (s.first->left) {
                q.emplace(s.first->left, max(s.first->val, s.second));
            }
            if (s.first->right) {
                q.emplace(s.first->right, max(s.first->val, s.second));
            }
        }
        return result;
    }
};
