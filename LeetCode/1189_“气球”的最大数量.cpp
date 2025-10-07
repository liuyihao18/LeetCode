// 1189_“气球”的最大数量.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> counts(128, 0);
        for (auto c : text) {
            counts[c]++;
        }
        map<char, int> needs{
            // ballon
            {'a', 1},
            {'b', 1},
            {'l', 2},
            {'n', 1},
            {'o', 2},
        };
        int result = INT_MAX;
        for (const auto& [key, val] : needs) {
            result = min(result, counts[key] / val);
        }
        return result;
    }
};
