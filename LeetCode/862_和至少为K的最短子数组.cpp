// 862_������ΪK�����������.cpp
#include "custom.h"
ustd

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        size_t n = nums.size();
        vector<long> preSumArr(n + 1);
        for (size_t i = 0; i < n; i++) {
            preSumArr[i + 1] = preSumArr[i] + nums[i];
        }
        int res = static_cast<int>(n) + 1;
        deque<int> qu;
        for (int i = 0; i <= n; i++) {
            long curSum = preSumArr[i];
            while (!qu.empty() && curSum - preSumArr[qu.front()] >= k) {
                res = min(res, i - qu.front());
                qu.pop_front();
            }
            while (!qu.empty() && preSumArr[qu.back()] >= curSum) {
                qu.pop_back();
            }
            qu.push_back(i);
        }
        return res < n + 1 ? res : -1;
    }
};
/*
���ߣ�LeetCode - Solution
���ӣ�https ://leetcode.cn/problems/shortest-subarray-with-sum-at-least-k/solution/he-zhi-shao-wei-k-de-zui-duan-zi-shu-zu-57ffq/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/
