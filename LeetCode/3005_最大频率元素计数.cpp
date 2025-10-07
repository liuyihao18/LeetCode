// 3005_最大频率元素计数.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> frequencies(101, 0);
        for (int num : nums) {
            frequencies[num]++;
        }
        int maxFrequency = max_element(frequencies.begin(), frequencies.end()).operator*();
        int maxFrequencyCount = static_cast<int>(count(frequencies.begin(), frequencies.end(), maxFrequency));
        return maxFrequency * maxFrequencyCount;
    }
};
