// 2341_�������γɶ�������.cpp
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
