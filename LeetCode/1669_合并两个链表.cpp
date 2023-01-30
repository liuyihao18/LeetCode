// 1669_合并两个链表.cpp
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int i = 0;
        decltype(list1) pptr1 = nullptr;
        auto ptr1 = list1;
        while (i < a) {
            i++;
            pptr1 = ptr1;
            ptr1 = ptr1->next;
        }
        auto ptr2 = ptr1;
        while (i < b) {
            i++;
            ptr2 = ptr2->next;
        }
        if (pptr1)
            pptr1->next = list2;
        auto curr = list2;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = ptr2->next;
        while (ptr1 != ptr2) {
            auto temp = ptr1;
            ptr1 = ptr1->next;
            delete temp;
        }
        return list1;
    }
};
