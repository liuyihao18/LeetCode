// 857_雇佣K名工人的最低成本.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        /**
        * totalC * (quality[hi] / totalQ) >= wage[hi];
        * totalC >= (wage[hi] / quality[hi]) * totalQ
        * So we should enumerate the minimum of {wage[hi] / quality[hi]} 
        * (maximum if given array h) and the minimum of totalQ
        * and compute the production.
        */
        size_t n = quality.size();
        vector<size_t> h(n, 0);
        iota(h.begin(), h.end(), 0);
        // 权重排序
        sort(h.begin(), h.end(), [&](size_t h1, size_t h2) {
            return wage[h1] * quality[h2] < wage[h2] * quality[h1];
            });
        double result = 1e9;
        double totalQ = 0.0;
        // 权重小的工作量中低的
        priority_queue<int, vector<int>, less<int>> q;
        for (size_t i = 0; i + 1 < k; i++) {
            totalQ += quality[h[i]];
            q.push(quality[h[i]]);
        }
        // 枚举权重高的，加上工作量低的，计算总花费
        for (size_t i = static_cast<size_t>(k) - 1; i < n; i++) {
            size_t idx = h[i];
            totalQ += quality[idx];
            q.push(quality[idx]);
            double totalC = (wage[idx] * 1.0 * totalQ) / quality[idx];
            result = min(totalC, result);
            totalQ -= q.top();
            q.pop();
        }
        return result;
    }
};
