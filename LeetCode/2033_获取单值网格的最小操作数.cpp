// 2033_获取单值网格的最小操作数.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int minOperations(const vector<vector<int>>& grid, const int x) {
        map<int, int> counts;
        for (auto&& row : grid)
        {
	        for (auto&& num : row)
	        {
                counts[num]++;
	        }
        }

        int ops = 0;
        const int num0 = counts.begin()->first;
        for (auto&& [num, count] : counts)
        {
            const int distance = num - num0;
            if (distance % x != 0)
            {
                return -1;
            }
            ops += distance / x * count;
        }

        const int m = static_cast<int>(grid.size());
        const int n = static_cast<int>(grid.front().size());
        int leftCount = 0;
        int rightCount = m * n;

        const int end = counts.rbegin()->first;
        int target = counts.begin()->first;
        auto iter = counts.begin();
        int minOps = ops;
        while (target <= end)
        {
            if (target == iter->first)
            {
                leftCount += iter->second;
                rightCount -= iter->second;
                ++iter;
            }
            target += x;
            ops += leftCount;
            ops -= rightCount;
            minOps = min(minOps, ops);
        }
        return minOps;
    }
};
