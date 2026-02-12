// 3713_最长的平衡子串_I.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int longestBalanced(const string& s) {
        size_t n{ s.size() };
        int result{};
        for (size_t i{}; i < n; i++) {
            vector<int> cnts(26);
            int maxCnt = 0;
            int type = 0;
            for (size_t j{ i }; j < n; j++) {
                size_t index{ static_cast<size_t>(s[j] - 'a') };
                if (cnts[index] == 0) type++;
                maxCnt = max(maxCnt, ++cnts[index]);
                int length{ static_cast<int>(j - i + 1) };
                if (maxCnt * type == length) {
                    result = max(result, length);
                }
            }
        }
        return result;
    }
};
