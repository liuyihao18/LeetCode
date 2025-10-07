// 1759_统计同构子字符串的数目.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int countHomogenous(string s) {
        int i = 0, j = 0, n = static_cast<int>(s.size());
        int result = 0;
        int temp = 0;
        const int remainder = (int)1e9 + 7;
        while (j < s.size()) {
            if (s[j] == s[i]) {
                temp += (j - i + 1) % remainder;
                temp %= remainder;
                j++;
            }
            else {
                result += temp;
                result %= remainder;
                temp = 0;
                i = j;
            }
        }
        result += temp;
        result %= remainder;
        return result;
    }
};
