// 1732_找到最高海拔.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int result = 0;
        int curr = 0;
        for (auto g : gain) {
            curr += g;
            result = max(result, curr);
        }
        return result;
    }
};
