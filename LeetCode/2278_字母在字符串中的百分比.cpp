// 2278_��ĸ���ַ����еİٷֱ�.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int percentageLetter(string s, char letter) {
        return static_cast<int>(count(s.begin(), s.end(), letter) * 100 / s.size());
    }
};

