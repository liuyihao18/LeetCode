// 901_��Ʊ�۸���.cpp
#include "stdafx.h"
ustd

class StockSpanner {
public:
    StockSpanner() {
        this->stk.emplace(-1, INT_MAX);
        this->idx = -1;
    }

    int next(int price) {
        idx++;
        while (price >= stk.top().second) {
            stk.pop();
        }
        int ret = idx - stk.top().first;
        stk.emplace(idx, price);
        return ret;
    }

private:
    stack<pair<int, int>> stk;
    int idx;
};
/*
���ߣ�LeetCode - Solution
���ӣ�https ://leetcode.cn/problems/online-stock-span/solution/gu-piao-jie-ge-kua-du-by-leetcode-soluti-5cm7/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
