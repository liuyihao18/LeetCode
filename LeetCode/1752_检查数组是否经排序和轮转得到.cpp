// 1752_检查数组是否经排序和轮转得到.cpp
#include "stdafx.h"
ustd

class Solution {
public:
	bool check(const vector<int>& nums) 	{
		const int n = static_cast<int>(nums.size());
		const int minIndex = static_cast<int>(ranges::min_element(nums) - nums.begin());
		// 往回找，看看最小元素出现了几次
		int count = 1;
		for (int i = 1; i < n; i++) 
		{
			if (const int j = (minIndex - i + n) % n;
				nums[j] == nums[minIndex]) 
			{
				count++;
			}
			else
			{
				break;
			}
		}
		// 排除头尾接壤的最小元素
		for (int i = 0; i + count < n; i++)
		{
			const int i1 = (minIndex + i) % n;
			const int i2 = (minIndex + i + 1) % n;
			if (nums[i1] > nums[i2])
			{
				return false;
			}
		}
		return true;
	}
};

/*
class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> origin = nums;
        sort(origin.begin(), origin.end());
        for (size_t offset = 0; offset < nums.size(); offset++) {
            size_t i = 0;
            for (; i < nums.size(); i++) {
                if (nums[i] != origin[(i + offset) % nums.size()]) {
                    break;
                }
            }
            if (i == nums.size()) {
                return true;
            }
        }
        return false;
    }
};
*/
