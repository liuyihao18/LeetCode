// 445_两数相加_II.cpp
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
        stack<int> s1, s2, sum;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        while (!s1.empty() && !s2.empty()) {
            int digit = s1.top() + s2.top() + carry;
            s1.pop();
            s2.pop();
            carry = digit > 9 ? 1 : 0;
            digit = digit > 9 ? digit - 10 : digit;
            sum.push(digit);
        }
        while (!s1.empty()) {
            int digit = s1.top() + carry;
            s1.pop();
            carry = digit > 9 ? 1 : 0;
            digit = digit > 9 ? digit - 10 : digit;
            sum.push(digit);
        }
        while (!s2.empty()) {
            int digit = s2.top() + carry;
            s2.pop();
            carry = digit > 9 ? 1 : 0;
            digit = digit > 9 ? digit - 10 : digit;
            sum.push(digit);
        }
        if (carry) sum.push(carry);
        ListNode* head = new ListNode, * curr = head;
        while (!sum.empty()) {
            curr->next = new ListNode(sum.top());
            sum.pop();
            curr = curr->next;
        }
        curr = head->next;
        delete head;
        return curr;
    }
};
