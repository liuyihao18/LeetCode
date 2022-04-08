// 429_N²æÊ÷µÄ²ãÐò±éÀú.cpp
#include "custom.h"
ustd

// Definition for a Node.
class Node {
public:
    int val;
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
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> result;
        queue<pair<size_t, Node*>> q;
        q.push({ 0, root });
        size_t floor = 0;
        result.push_back(vector<int>());
        while (!q.empty()) {
            pair<size_t, Node*> curr = q.front();
            Node* node = curr.second;
            q.pop();
            if (curr.first > floor) {
                result.push_back(vector<int>());
                floor = curr.first;
            }
            result[floor].push_back(node->val);
            for (auto child : node->children) {
                q.push({ floor + 1, child });
            }
        }
        return result;
    }
};
