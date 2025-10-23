// 3461_判断操作后字符串中的数字是否相等_I.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.size() > 2) {
            string temp;
            for (size_t i = 0; i + 1 < s.size(); i++) {
				temp += to_string((s[i] - '0' + s[i + 1] - '0') % 10);
            }
            s = std::move(temp);
        }
		return s[0] == s[1];
    }
};
