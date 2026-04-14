// 3740_三个相等元素之间的最小距离_I.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int minimumDistance(const vector<int>& nums) {
        unordered_map<int, vector<int>> um;
        for (int i = 0, n = static_cast<int>(nums.size()); i < n; i++)
        {
            um[nums[i]].push_back(i);
        }
        int result = INT_MAX;
        for (auto& value : um | views::values)
        {
            for (int i = 0, n = static_cast<int>(value.size()); i + 2 < n; i++)
            {
                const int distance = (value[i + 2] - value[i]) * 2;
                result = min(result, distance);
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};