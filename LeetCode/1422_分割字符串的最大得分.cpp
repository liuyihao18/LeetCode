// 1422_分割字符串的最大得分.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int maxScore(string s) {
        int score2 = 0;
        for (auto c : s) if (c == '1') ++score2;
        int score1 = 0;
        int maxScore = 0;
        for (size_t i = 1; i + 1 < s.size(); i++) {
            if (s[i] == '0') {
                ++score1;
            }
            else {
                --score2;
            }
            maxScore = max(maxScore, score1 + score2);
        }
        return maxScore;
    }
};
