// 23_合并K个升序链表.cpp
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
    struct CMP {
        bool operator()(const ListNode* const l1, const ListNode* const l2) const {
            if (!l1) return false;
            if (!l2) return true;
            return l1->val > l2->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, CMP> pq(lists.begin(), lists.end());
        ListNode* head = new ListNode(), *curr = head;
        while (!pq.empty()) {
            ListNode* top = pq.top();
            pq.pop();
            if (!top) continue;
            curr->next = top;
            curr = curr->next;
            top = top->next;
            if (top) pq.push(top);
        }
        curr = head;
        head = head->next;
        delete curr;
        return head;
    }
};
