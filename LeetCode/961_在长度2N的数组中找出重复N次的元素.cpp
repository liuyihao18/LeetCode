// 961_在长度2N的数组中找出重复N次的元素.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        set<int> s;
        for (auto num : nums) {
            if (s.count(num)) {
                return num;
            }
            s.insert(num);
        }
        return -1;
    }
};
