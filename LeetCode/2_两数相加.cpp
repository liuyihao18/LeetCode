// 2_两数相加.cpp
#include "stdafx.h"
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* ptr1 = l1, * ptr2 = l2;
        ListNode* head = new ListNode, * curr = head;
        while (ptr1 && ptr2) {
            int digit = ptr1->val + ptr2->val + carry;
            carry = digit > 9 ? 1 : 0;
            digit = digit > 9 ? digit - 10 : digit;
            curr->next = new ListNode(digit);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            curr = curr->next;
        }
        while (ptr1) {
            int digit = ptr1->val + carry;
            carry = digit > 9 ? 1 : 0;
            digit = digit > 9 ? digit - 10 : digit;
            curr->next = new ListNode(digit);
            ptr1 = ptr1->next;
            curr = curr->next;
        }
        while (ptr2) {
            int digit = ptr2->val + carry;
            carry = digit > 9 ? 1 : 0;
            digit = digit > 9 ? digit - 10 : digit;
            curr->next = new ListNode(digit);
            ptr2 = ptr2->next;
            curr = curr->next;
        }
        if (carry) curr->next = new ListNode(1);
        curr = head;
        head = head->next;
        delete curr;
        return head;
    }
};
