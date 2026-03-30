// 2840_判断通过操作能否让字符串相等_II.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    bool checkStrings(string_view s1, string_view s2) {
        array<int, 26> s1OddCount, s1EvenCount, s2OddCount, s2EvenCount;
        const size_t n = s1.size();
        for (size_t i = 0; i < n; i += 2)
        {
            s1EvenCount[s1[i] - 'a']++;
            s2EvenCount[s2[i] - 'a']++;
        }
        for (size_t i = 1; i < n; i+=2)
        {
            s1OddCount[s1[i] - 'a']++;
            s2OddCount[s2[i] - 'a']++;
        }
        return s1OddCount == s2OddCount && s1EvenCount == s2EvenCount;
    }
};
