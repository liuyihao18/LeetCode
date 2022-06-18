// 剑指_Offer_II_029_排序的循环链表.cpp
#include "custom.h"
ustd

// Definition for a Node.
class Node {
public:
    int val{ 0 };
    Node* next{ NULL };

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

typedef Node ListNode;

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (head == NULL) {
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        int minVal = INT_MAX;
        int maxVal = INT_MIN;
        Node* curr = head;
        Node* maxValNode = head;
        while (true) {
            minVal = min(minVal, curr->val);
            if (curr->val >= maxVal) {
                maxVal = curr->val;
                maxValNode = curr;
            }
            curr = curr->next; 
            if (curr == head) {
                break;
            }
        }
        while (curr->val == maxVal) {
            maxValNode = curr;
            curr = curr->next;
            if (curr == head) {
                break;
            }
        }
        Node* pre = maxValNode;
        curr = pre->next;
        if (insertVal > minVal && insertVal < maxVal) {
            while (curr->val < insertVal) {
                pre = curr;
                curr = curr->next;
            }
        }
        Node* insertNode = new Node(insertVal, curr);
        pre->next = insertNode;
        return head;
    }
};
