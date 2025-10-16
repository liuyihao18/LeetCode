// 2598_执行操作后的最大MEX.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> count(value, 0);
        for (int num : nums) {
			count[static_cast<size_t>((num % value + value) % value)]++;
        }
        auto iter = min_element(count.begin(), count.end());
		return *iter * value + static_cast<int>(distance(count.begin(), iter));
    }
};
