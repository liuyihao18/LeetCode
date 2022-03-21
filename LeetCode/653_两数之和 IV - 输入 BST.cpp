// 653_两数之和 IV - 输入 BST.cpp
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
    void inOrder(TreeNode* root, vector<int>& v) {
        if (root) {
            inOrder(root->left, v);
            v.push_back(root->val);
            inOrder(root->right, v);
        }
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        inOrder(root, v);
        if (v.size() == 1) {
            return false;
        }
        int max_val = v.back();
        for (auto iter = v.begin(); iter != v.end(); ++iter) {
            auto _iter = lower_bound(v.begin(), v.end(), k - *iter);
            if (_iter != v.end() && _iter != iter) {
                if (*_iter + *iter == k) {
                    return true;
                }
            }
        }
        return false;
    }
};
