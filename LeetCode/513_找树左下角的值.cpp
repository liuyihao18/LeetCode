// 513_ÕÒÊ÷×óÏÂ½ÇµÄÖµ.cpp
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
    using State = pair<TreeNode*, int>;
#define node first
#define height second
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<State> q;
        q.emplace(root, 0);
        int maxHeight = -1;
        int leftValue = 0;
        while (!q.empty()) {
            State curr = q.front();
            q.pop();
            if (curr.height > maxHeight) {
                maxHeight = curr.height;
                leftValue = curr.node->val;
            }
            if (curr.node->left) {
                q.emplace(curr.node->left, curr.height + 1);
            }
            if (curr.node->right) {
                q.emplace(curr.node->right, curr.height + 1);
            }
        }
        return leftValue;
    }
};
