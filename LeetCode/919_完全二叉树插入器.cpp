// 919_完全二叉树插入器.cpp
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
 
class CBTInserter {
    size_t size;
    TreeNode* root;
    template<class T> 
    T bit_width(T num) {
        if (num == 0) {
            return 0;
        }
        T cnt = 0;
        while (num > 0) {
            cnt++;
            num >>= 1;
        }
        return cnt;
    }
public:
    CBTInserter(TreeNode* root) {
        this->root = root;
        this->size = 0;
        queue<TreeNode*> qu;
        qu.emplace(root);
        while (!qu.empty()) {
            TreeNode* curr = qu.front();
            qu.pop();
            ++size;
            if (curr->left) {
                qu.emplace(curr->left);
            }
            if (curr->right) {
                qu.emplace(curr->right);
            }
        }
    }

    int insert(int val) {
        ++size;
        auto w = bit_width(size);
        TreeNode* curr = root;
        for (size_t i = w - 1; i > 1; i--) {
            if (size >> (i - 1) & 1) {
                curr = curr->right;
            }
            else {
                curr = curr->left;
            }
        }
        if (size & 1) {
            curr->right = new TreeNode(val);
        }
        else {
            curr->left = new TreeNode(val);
        }
        return curr->val;
    }

    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
