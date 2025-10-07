// 796_Ðý×ª×Ö·û´®.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return 0;
        }
        size_t n = s.size();
        for (size_t i = 0; i < n; i++) {
            size_t j = 0;
            for (; j < n; j++) {
                if (goal[j] != s[(i + j) % n]) {
                    break;
                }
            }
            if (j == n) {
                return true;
            }
        }
        return false;
    }
};
