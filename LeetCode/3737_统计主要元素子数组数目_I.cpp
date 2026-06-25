// 3737_统计主要元素子数组数目_I.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int countMajoritySubarrays(const vector<int>& nums, int target) {
        const size_t n = nums.size();
        vector<int> counts(n + 1, 0);
        for (size_t i = 0; i < n; i++)
        {
            counts[i + 1] = counts[i] + (nums[i] == target);
        }
        int result = 0;
        for (size_t i = 0; i < n;i++)
        {
	        for (size_t j = i; j < n; j++)
	        {
		        if (2 * (counts[j + 1] - counts[i]) > static_cast<int>(j - i + 1))
		        {
                    result++;
		        } 
	        }
        }
        return result;
    }
};
