// 2006_��ľ���ֵΪK��������Ŀ.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        map<int, int> m;
        for (auto num : nums) {
            m[num]++;
        }
        int result = 0;
        for (const auto& [key, val] : m) {
            if (m.count(key + k)) {
                result += val * m[key + k];
            }
        }
        return result;
    }
};
