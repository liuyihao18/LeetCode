// 696_计数二进制子串.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int countBinarySubstrings(const string& s) {
        int result{};
        int c1{}, c2{1};
        for (size_t i{1}, n{ s.size() }; i < n; i++) {
            if (s[i] == s[i - 1]) {
                c2++;
            }
            else {
                result += min(c1, c2);
                c1 = c2;
                c2 = 1;
            }
        }
        result += min(c1, c2);
        return result;
    }
};
