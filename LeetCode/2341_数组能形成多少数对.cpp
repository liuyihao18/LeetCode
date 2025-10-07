// 2341_数组能形成多少数对.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        map<int, int> m;
        for (auto num : nums) {
            m[num]++;
        }
        int x = 0, y = 0;
        for (auto& [_, c] : m) {
            x += c / 2;
            y += c % 2;
        }
        return { x,y };
    }
};
