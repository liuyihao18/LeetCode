// 2027_转换字符串的最少操作次数.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int minimumMoves(string s) {
        int result = 0;
        for (size_t i = 0; i < s.size();) {
            if (s[i] == 'X') {
                for (size_t j = 0; j < 3 && i + j < s.size(); j++) {
                    s[i + j] = 'O';
                }
                i += 3;
                result++;
            }
            else {
                i++;
            }
        }
        return result;
    }
};
