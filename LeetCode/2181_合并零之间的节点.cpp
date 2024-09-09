// 2181_合并零之间的节点.cpp
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
    ListNode* mergeNodes(ListNode* head) {
        int sum = 0;
        ListNode* prev = head;
        ListNode* curr = head->next;
        while (curr) {
            if (curr->val == 0) {
                curr->val = sum;
                sum = 0;
                prev->next = curr;
                prev = curr;
            }
            else {
                sum += curr->val;
            }
            curr = curr->next;
        }
        return head->next;
    }
};
