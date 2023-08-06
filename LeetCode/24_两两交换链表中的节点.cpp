// 24_两两交换链表中的节点.cpp
#include "custom.h"
ustd
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* pre = nullptr;
        auto first = head, second = first->next;
        head = head->next;
        while (first && second) {
            if (pre) pre->next = second;
            first->next = second->next;
            second->next = first;
            pre = first;
            first = first->next;
            if (first) second = first->next;
        }
        return head;
    }
};
