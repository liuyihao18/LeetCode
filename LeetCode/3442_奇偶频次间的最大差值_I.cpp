// 3442_奇偶频次间的最大差值_I.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int maxDifference(string s) {
        vector<int> counts(26, 0);
        for (char c : s) {
            counts[static_cast<size_t>(c - 'a')]++;
        }
        int odd_count_max = 0;
        int even_count_min = 1000;
        for (int count : counts) {
            if (count == 0) {
                continue;
            }
            if (count & 1) {
                odd_count_max = max(odd_count_max, count);
            }
            else {
                even_count_min = min(even_count_min, count);
            }
        }
        return odd_count_max - even_count_min;
    }
};
