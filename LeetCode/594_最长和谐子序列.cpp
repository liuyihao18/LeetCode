// 594_最长和谐子序列.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, size_t> counts;
        for_each(nums.begin(), nums.end(), [&](int num) {
            counts[num]++;
            });
        if (counts.size() == 1) {
            return 0;
        }
        auto iter = counts.begin();
        size_t max_sum = 0;
        while (true) {
            auto prev = iter;
            auto next = ++iter;
            if (next == counts.end()) {
                break;
            }
            if ((next->first - prev->first) == 1) {
                max_sum = max(max_sum, next->second + prev->second);
            }
        }
        return static_cast<int>(max_sum);
    }
};
