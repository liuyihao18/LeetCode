// 3349_检测相邻递增子数组_I.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        size_t n = nums.size();
        int result = 0;
        int prev = 0, cnt = 1;
        for (size_t i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                cnt++;
            }
            else
            {
                prev = cnt;
                cnt = 1;
            }
			result = max(result, min(prev, cnt));
            result = max(result, cnt / 2);
        }
        return result >= k;
    }
};
