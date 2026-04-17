// 3761_镜像对之间最小绝对距离.cpp
#include "stdafx.h"
ustd

class Solution {
public:
	int minMirrorPairDistance(vector<int>& nums) {
		auto reverse = [](int num)
		{
			int res = 0;
			while (num > 0)
			{
				res = res * 10 + num % 10;
				num /= 10;
			}
			return res;
		};
		unordered_map<int, int> index;
		int minDistance = INT_MAX;
		for (int i = 0, n = static_cast<int>(nums.size()); i < n; i++)
		{
			const int num = nums[i];
			if (index.contains(num))
			{
				minDistance = min(minDistance, i - index[num]);
			}
			index[reverse(num)] = i;
		}
		return minDistance == INT_MAX ? -1 : minDistance;
	}
};
