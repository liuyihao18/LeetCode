// 3375_ʹ�����ֵȫ��ΪK�����ٲ�������.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> s;
        for (auto num : nums) {
            s.insert(num);
        }
        if (*s.begin() < k) {
            return -1;
        }
        else if (*s.begin() == k) {
            return static_cast<int>(s.size() - 1);
        }
        else {
            return static_cast<int>(s.size());
        }
    }
};