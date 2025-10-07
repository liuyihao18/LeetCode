// 589_N²æÊ÷µÄÇ°Ðò±éÀú.cpp
#include "stdafx.h"
ustd

// Definition for a Node.
class Node {
public:
    int val{ 0 };
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
    void preOrder(Node* root, vector<int>& result) {
        if (root) {
            result.push_back(root->val);
            for (auto child : root->children) {
                preOrder(child, result);
            }
        }
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        preOrder(root, result);
        return result;
    }
};
