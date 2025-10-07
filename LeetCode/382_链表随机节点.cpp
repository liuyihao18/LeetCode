// 382_链表随机节点.cpp
#include "stdafx.h"
ustd

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
    ListNode* head;
    size_t length;
public:
    Solution(ListNode* head) : head(head), length(0) {
        while (head) {
            length++;
            head = head->next;
        }
    }

    int getRandom() {
        size_t n = rand() % length;
        ListNode* p = head;
        for (size_t i = 0; i < n; i++, p = p->next) {}
        return p->val;
    }

    /* 水塘抽样
    int getRandom() {
        int i = 1, ans = 0;
        for (auto node = head; node; node = node->next) {
            if (rand() % i == 0) { // 1/i 的概率选中（替换为答案）
                ans = node->val;
            }
            ++i;
        }
        return ans;
    }
     */
    /*
    作者：LeetCode - Solution
        链接：https ://leetcode-cn.com/problems/linked-list-random-node/solution/lian-biao-sui-ji-jie-dian-by-leetcode-so-x6it/
    来源：力扣（LeetCode）
        著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
     */
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
