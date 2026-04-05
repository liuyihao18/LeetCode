// 657_机器人能否返回原点.cpp
#include "stdafx.h"
ustd

class Solution {
public:
	bool judgeCircle(const string_view moves) {
		int x = 0, y = 0;
		std::map<char, std::function<void()>> functions;
		functions['R'] = [&x] { x++; };
		functions['U'] = [&y] { y++; };
		functions['L'] = [&x] { x--; };
		functions['D'] = [&y] { y--; };
		ranges::for_each(moves, [&](const char c)
		{
			functions[c]();
		});
		return x == 0 && y == 0;
	}
};
