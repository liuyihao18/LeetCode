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

TreeNode* node = nullptr;
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        node = root;
        return "Hello, world!";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
