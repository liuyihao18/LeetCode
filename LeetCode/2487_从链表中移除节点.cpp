// 2487_从链表中移除节点.cpp
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
    ListNode* removeNodes(ListNode* head) {
        vector<int> st;
        ListNode* virtualHead = new ListNode();
        virtualHead->next = head;
        ListNode* prev = virtualHead;
        ListNode* curr = head;
        while (curr) {
            while (!st.empty() && st.back() < curr->val) {
                st.pop_back();
            }
            st.push_back(curr->val);
            curr = curr->next;
        }
        curr = head;
        size_t i = 0;
        while (curr) {
            if (curr->val < st[i]) {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
            else {
                prev = curr;
                curr = curr->next;
                i++;
            }
        }
        head = virtualHead->next;
        delete virtualHead;
        return head;
    }
};
