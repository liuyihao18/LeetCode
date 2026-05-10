// 61_Ğı×ªÁ´±í.cpp
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
    int travelList(ListNode* head, ListNode** tailPtr)
    {
        ListNode* tail = head;
        int n = 1;
        while (tail->next != nullptr)
        {
            tail = tail->next;
            n++;
        }
        if (tailPtr)
        {
            *tailPtr = tail;
        }
        return n;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0)
        {
            return head;
        }
        ListNode* tail;
        int n = travelList(head, &tail);
        k %= n;
        if (k == 0)
        {
            return head;
        }
        ListNode* newHeadPrev = nullptr;
        ListNode* newHead = head;
        while (n > k)
        {
            newHeadPrev = newHead;
            newHead = newHead->next;
            n--;
        }
        newHeadPrev->next = nullptr;
        tail->next = head;
        return newHead;
    }
};
