// 2553_分割数组中数字的数位.cpp
#include "stdafx.h"
ustd

class Solution {
public:
	vector<int> separateDigits(const vector<int>& nums) {
		vector<int> result;
		ranges::for_each(views::reverse(nums), [&result](int num)
		{
			while (num > 0)
			{
				result.push_back(num % 10);
				num /= 10;
			}
		});
		ranges::reverse(result);
		return result;
	}
};
