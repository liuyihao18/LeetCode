// 508_出现次数最多的子树元素和.cpp
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
    int dfs(TreeNode* root, map<int, size_t>& m) {
        int sum = root->val;
        if (root->left) {
            sum += dfs(root->left, m);
        }
        if (root->right) {
            sum += dfs(root->right, m);
        }
        m[sum]++;
        return sum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int, size_t> m;
        if (root) {
            dfs(root, m);
        }
        size_t maxVal = 0;
        for (const auto& [key, val] : m) {
            maxVal = max(maxVal, val);
        }
        vector<int> result;
        for (const auto& [key, val] : m) {
            if (val == maxVal) {
                result.push_back(key);
            }
        }
        return result;
    }
};
