// 3702_按位异或非零的最长子序列.cpp
#include "stdafx.h"
ustd

class Solution {
public:
	int longestSubsequence(vector<int>& nums) {
		const bool allZero = ranges::all_of(nums, [](const int num) { return num == 0; });
		const int xorSum = accumulate(begin(nums), end(nums), 0, [](const int sum, const int num)
		{
			return sum ^ num;
		});
		return allZero ? 0 : xorSum == 0 ? static_cast<int>(nums.size()) - 1 : static_cast<int>(nums.size());
	}
};
