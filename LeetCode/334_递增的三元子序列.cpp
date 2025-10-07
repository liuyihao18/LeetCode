// 334_递增的三元子序列.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min_i = INT_MAX;
        pair<int, int> min_ij = { INT_MAX,INT_MAX };
        for (auto num : nums) {
            if (num < min_i) {
                min_i = num;
            }
            if (num > min_i && num < min_ij.second) {
                min_ij = { min_i, num };
            }
            if (num > min_ij.first && num < min_ij.second) {
                min_ij.second = num;
            }
            if (num > min_ij.second) {
                // cout << "(" << min_ij.first << ", " << min_ij.second << ", " << num << ")" << endl;
                return true;
            }
        }
        return false;
    }
};
