// 655_Êä³ö¶þ²æÊ÷.cpp
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
    size_t getHeight(TreeNode* root) {
        if (!root) {
            return 0;
        }
        size_t heigth1 = getHeight(root->left);
        size_t height2 = getHeight(root->right);
        return max(heigth1, height2) + 1;
    }
public:
    vector<vector<string>> printTree(TreeNode* root) {
        size_t height = getHeight(root);
        size_t m = height;
        size_t n = (static_cast<size_t>(1) << height) - 1;
        vector<vector<string>> result(m, vector<string>(n));
        queue<pair<TreeNode*, pair<size_t, size_t>>> q;
        q.emplace(root, make_pair(0, (n - 1) / 2));
        while (!q.empty()) {
            pair<TreeNode*, pair<size_t, size_t>> curr = q.front();
            q.pop();
            result[curr.second.first][curr.second.second] = to_string(curr.first->val);
            if (curr.first->left || curr.first->right) {
                size_t offset = (static_cast<size_t>(1) << (height - curr.second.first - 2));
                if (curr.first->left) {
                    q.emplace(curr.first->left, make_pair(curr.second.first + 1, curr.second.second - offset));
                }
                if (curr.first->right) {
                    q.emplace(curr.first->right, make_pair(curr.second.first + 1, curr.second.second + offset));
                }
            }
        }
        return result;
    }
};
