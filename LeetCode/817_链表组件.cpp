// 817_Á´±í×é¼þ.cpp
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
    int numComponents(ListNode* head, vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int result = 0;
        int size = 0;
        ListNode* curr = head;
        while (curr) {
            auto iter = lower_bound(nums.begin(), nums.end(), curr->val);
            if (iter == nums.end() || *iter != curr->val) {
                if (size > 0) {
                    result++;
                }
                size = 0;
            }
            else {
                size++;
            }
            curr = curr->next;
        }
        if (size > 0) {
            result++;
        }
        return result;
    }
};
