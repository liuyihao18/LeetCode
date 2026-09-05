// 3904_最小稳定下标_II.cpp
#include "stdafx.h"
ustd

class Solution {
public:
	int firstStableIndex(const vector<int>& nums, int k) {
		if (nums.empty())
		{
			return -1;
		}
		// maxElements[i] 表示下标小于等于 i 的最大值
		auto buildLeftMaxElements = [&nums](vector<int>& outMaxElements)
		{
			outMaxElements.clear();
			outMaxElements.resize(nums.size());
			outMaxElements[0] = nums[0];
			for (int i = 1, n = static_cast<int>(nums.size()); i < n; i++)
			{
				outMaxElements[i] = max(outMaxElements[i - 1], nums[i]);
			}
		};
		// minElements[i] 表示下标大于等于 i 的最小值
		auto buildRightMinElements = [&nums](vector<int>& outMinElements)
		{
			outMinElements.clear();
			outMinElements.resize(nums.size());
			outMinElements[nums.size() - 1] = nums[nums.size() - 1];
			for (int n = static_cast<int>(nums.size()), i = n - 2; i >= 0; i--)
			{
				outMinElements[i] = min(outMinElements[i + 1], nums[i]);
			}
		};
		vector<int> maxElements, minElements;
		buildLeftMaxElements(maxElements);
		buildRightMinElements(minElements);
		for (int i = 0, n =static_cast<int>(nums.size()); i < n; i++)
		{
			if (maxElements[i] - minElements[i] <= k)
			{
				return i;
			}
		}
		return -1;
	}
};
