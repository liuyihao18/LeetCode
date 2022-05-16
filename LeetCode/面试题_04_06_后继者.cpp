// 面试题_04_06_后继者.cpp
#include "custom.h"
ustd

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> s;
        TreeNode* curr = root;
        while (curr) {
            s.push(curr);
            if (curr->val == p->val) {
                break;
            }
            else if (curr->val < p->val) {
                curr = curr->right;
            }
            else {
                curr = curr->left;
            }
        }
        while (!s.empty()) {
            curr = s.top();
            s.pop();
            if (curr->val == p->val) {
                if (curr->right) {
                    curr = curr->right;
                    while (curr->left) {
                        curr = curr->left;
                    }
                    return curr;
                }
            }
            else if (curr->val > p->val) {
                return curr;
            }
        }
        return NULL;
    }
};
