// 449_序列化和反序列化二叉搜索树.cpp
#include "custom.h"
ustd

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
    string preOrder(TreeNode* root) {
        if (!root) {
            return "";
        }
        return to_string(root->val) + " " + preOrder(root->left) + " " + preOrder(root->right);
    }
    vector<int> split(string data) {
        vector<int> result;
        string temp;
        for (auto c : data) {
            if (c == ' ') {
                if (!temp.empty()) {
                    result.push_back(stoi(temp));
                }
                temp = "";
            }
            else {
                temp += c;
            }
        }
        if (!temp.empty()) {
            result.push_back(stoi(temp));
        }
        return result;
    }
    TreeNode* construct(const vector<int>& pOrder) {
        if (pOrder.size() == 0) {
            return nullptr;
        }
        if (pOrder.size() == 1) {
            return new TreeNode(pOrder[0]);
        }
        TreeNode* root = new TreeNode(pOrder[0]);
        auto iter = find_if(pOrder.begin() + 1, pOrder.end(), [&](int child) { return child > pOrder[0]; });
        root->left = construct(vector<int>(pOrder.begin() + 1, iter));
        root->right = construct(vector<int>(iter, pOrder.end()));
        return root;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return preOrder(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> order = split(data);
        return construct(order);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
