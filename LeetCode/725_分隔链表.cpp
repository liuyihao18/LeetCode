// 725_分隔链表.cpp
#include "stdafx.h"
ustd

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length = 0;
        auto p = head;
        while (p) {
            length++;
            p = p->next;
        }
        int avg_length = length / k; // 平均长度
        int remainder = length - avg_length * k; // int remainder = length % k; // 余数
        vector<ListNode*> result;
        ListNode* pred = nullptr;
        p = head;
        for (int i = 0; i < k; i++) {
            result.push_back(p);
            int go_next = i < remainder ? avg_length + 1 : avg_length;
            while (go_next > 0) {
                go_next--;
                if (p) {
                    pred = p; 
                    p = p->next;
                }
            }
            if (pred) pred->next = nullptr;
        }
        return result;
    }
};