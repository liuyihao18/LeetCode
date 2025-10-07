// 624_数组列表中的最大距离.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int maximum1 = INT_MIN, minimum1 = INT_MAX;
        size_t maximum1_idx = -1, minimum1_idx = -1;
        size_t n = arrays.size();
        for (size_t i = 0; i < n; i++) {
            if (arrays[i].back() > maximum1) {
                maximum1 = arrays[i].back();
                maximum1_idx = i;
            }
            if (arrays[i].front() < minimum1) {
                minimum1 = arrays[i].front();
                minimum1_idx = i;
            }
        }
        int maximum2 = INT_MIN, minimum2 = INT_MAX;
        for (size_t i = 0; i < n; i++) {
            if (i != minimum1_idx && arrays[i].back() > maximum2) {
                maximum2 = arrays[i].back();
            }
            if (i != maximum1_idx && arrays[i].front() < minimum2) {
                minimum2 = arrays[i].front();
            }
        }
        return max(maximum1 - minimum2, maximum2 - minimum1);
    }
};
