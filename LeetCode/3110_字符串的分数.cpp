// 3110_�ַ����ķ���.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int scoreOfString(string s) {
        int score = 0;
        for (size_t i = 0; i + 1 < s.size(); i++) {
            score += abs(s[i + 1] - s[i]);
        }
        return score;
    }
};