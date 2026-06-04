// 3751_范围内总波动值_I.cpp
#include "stdafx.h"
ustd

class Solution {
public:
	int totalWaviness(const int num1, const int num2) {
		auto calculateWaviness = [](const int num)
		{
			const string str = to_string(num);
			if (str.size() < 3) return 0;
			int waviness = 0;
			for (size_t i = 1, n = str.size(); i + 1 < n; i++)
			{
				if (str[i] < str[i - 1] && str[i] < str[i + 1] ||
					str[i] > str[i - 1] && str[i] > str[i + 1])
				{
					waviness++;
				}
			}
			return waviness;
		};
		int waviness = 0;
		for (int num = num1; num <= num2; num++)
		{
			waviness += calculateWaviness(num);
		}
		return waviness;
	}
};
