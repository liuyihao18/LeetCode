// 590_N²æÊ÷µÄºóÐò±éÀú.cpp
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
    void postOrder(Node* root, vector<int>& result) {
        if (root) {
            for (auto child : root->children) {
                postOrder(child, result);
            }
            result.push_back(root->val);
        }
    }
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        postOrder(root, result);
        return result;
    }
};
