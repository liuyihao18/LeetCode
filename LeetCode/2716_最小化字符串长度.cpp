// 2716_最小化字符串长度.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int minimizedStringLength(string s) {
        sort(s.begin(), s.end());
        auto iter = unique(s.begin(), s.end());
        return static_cast<int>(iter - s.begin());
        // return static_cast<int>(set<char>(s.begin(), s.end()).size());
    }
};