// 面试题_01_02_判定是否互为字符重排.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }
};
