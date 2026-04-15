// 2515_到目标字符串的最短距离.cpp
#include "stdafx.h"
ustd

class Solution {
public:
	int closestTarget(const vector<string>& words, const string_view target, const int startIndex) {
		const int n = static_cast<int>(words.size());
		int ans = -1;
		for (int i = 0; i < n; i++)
		{
			if (const int forwardIndex = (startIndex + i) % n,
			              backwardIndex = (startIndex - i + n) % n;
				words[forwardIndex] == target || words[backwardIndex] == target)
			{
				ans = i;
				break;
			}
		}
		return ans;
	}
};
