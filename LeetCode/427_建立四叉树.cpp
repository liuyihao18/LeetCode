// 427_½¨Á¢ËÄ²æÊ÷.cpp
#include "custom.h"
ustd

// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};


class Solution {
private:
    void devide(Node* root, size_t x1, size_t x2, size_t y1, size_t y2, const vector<vector<int>>& grid){
        if (x1 == x2 /* && y1 == y2 */) {
            root->isLeaf = true;
            root->val = grid[x1][y1];
            return;
        }
        size_t x = (x1 + x2) / 2;
        size_t y = (y1 + y2) / 2;
        root->topRight = new Node();
        devide(root->topRight, x1, x, y + 1, y2, grid);
        root->bottomRight = new Node();
        devide(root->bottomRight, x + 1, x2, y + 1, y2, grid);
        root->bottomLeft = new Node();
        devide(root->bottomLeft, x + 1, x2, y1, y, grid);
        root->topLeft = new Node();
        devide(root->topLeft, x1, x, y1, y, grid);
        if (root->topRight->isLeaf &&
            root->bottomRight->isLeaf &&
            root->bottomLeft->isLeaf &&
            root->topLeft->isLeaf &&
            root->topRight->val == root->bottomRight->val &&
            root->bottomRight->val == root->bottomLeft->val &&
            root->bottomLeft->val == root->topLeft->val) {
            root->isLeaf = true;
            root->val = root->topRight->val;
            delete root->topRight;
            root->topRight = NULL;
            delete root->bottomRight;
            root->bottomRight = NULL;
            delete root->bottomLeft;
            root->bottomLeft = NULL;
            delete root->topLeft;
            root->topLeft = NULL;
        }
        else {
            root->isLeaf = false;
            root->val = true;
        }
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        size_t n = grid.size();
        Node* root = new Node();
        devide(root, 0, n - 1, 0, n - 1, grid);
        return root;
    }
};
