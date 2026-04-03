// 2839_判断通过操作能否让字符串相等_I.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    bool canBeEqual(const string_view s1, const string_view s2) {
        return (s1[0] == s2[0] && s1[2] == s2[2] ||
            s1[0] == s2[2] && s1[2] == s2[0]) &&
            (s1[1] == s2[1] && s1[3] == s2[3] ||
            s1[1] == s2[3] && s1[3] == s2[1]);
    }
};
