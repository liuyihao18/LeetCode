// 2574_左右元素和的差值.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<int> leftRightDifference(const vector<int>& nums) {
        const int totalSum = accumulate(begin(nums), end(nums), 0);
        vector<int> results(size(nums));
    	int leftSum = 0;
		for (size_t i = 0, n = size(nums); i < n; i++)
		{
            const int rightSum = totalSum - leftSum - nums[i];
            results[i] = abs(leftSum - rightSum);
            leftSum += nums[i];
		}
        return results;
    }
};
