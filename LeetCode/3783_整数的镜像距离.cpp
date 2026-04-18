// 3783_ÕûÊıµÄ¾µÏñ¾àÀë.cpp
#include "stdafx.h"
ustd

class Solution {
public:
	int mirrorDistance(const int n) {
		auto flipInt = [](int x)
		{
			int y = 0;
			while (x)
			{
				y = y * 10 + x % 10;
				x /= 10;
			}
			return y;
		};
		return abs(n - flipInt(n));
	}
};
