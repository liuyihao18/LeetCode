// 430_扁平化多级双向链表.cpp
#include "custom.h"
ustd

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* _flatten(Node* head) {
        auto p = head;
        Node* pre = nullptr;
        while (p) {
            if (p->child) {
                auto child_head = p->child;
                auto child_tail = _flatten(p->child);
                auto q = p->next;
                p->next = child_head;
                child_head->prev = p;
                child_tail->next = q;
                if (q) q->prev = child_tail;
                p->child = nullptr;
                pre = child_tail;
                p = q;
            }
            else {
                pre = p;
                p = p->next;
            }
        }
        return pre;
    }
    Node* flatten(Node* head) {
        _flatten(head);
        return head;
    }
};