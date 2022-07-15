// 558_ËÄ²æÊ÷½»¼¯.cpp
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
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if (quadTree1->isLeaf) {
            if (quadTree1->val) {
                return new Node(true, true);
            }
            else {
                return new Node(quadTree2->val, quadTree2->isLeaf,
                    quadTree2->topLeft, quadTree2->topRight,
                    quadTree2->bottomLeft, quadTree2->bottomRight
                );
            }
        }
        if (quadTree2->isLeaf) {
            if (quadTree2->val) {
                return new Node(true, true);
            }
            else {
                return new Node(quadTree1->val, quadTree1->isLeaf,
                    quadTree1->topLeft, quadTree1->topRight,
                    quadTree1->bottomLeft, quadTree1->bottomRight
                );
            }
        }
        Node* topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
        Node* topRight = intersect(quadTree1->topRight, quadTree2->topRight);
        Node* bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        Node* bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf) {
            if (topLeft->val && topRight->val && bottomLeft->val && bottomRight->val) {
                return new Node(true, true);
            }
            else if (!topLeft->val && !topRight->val && !bottomLeft->val && !bottomRight->val) {
                return new Node(false, true);
            }
        }
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }
};
