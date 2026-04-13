// 1848_到目标元素的最小距离.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int getMinDistance(const vector<int>& nums, const int target, const int start) {
        int ans = INT_MAX;
        for (int i = 0, n = static_cast<int>(nums.size()); i < n; i++)
        {
	        if (nums[i] == target)
	        {
                ans = min(ans, abs(i - start));
	        }
        }
        return ans;
    }
};
