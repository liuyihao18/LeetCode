// 521_最长特殊序列_Ⅰ.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int findLUSlength(string a, string b) {
        return a == b ? -1 : static_cast<int>(max(a.size(), b.size()));
    }
};
