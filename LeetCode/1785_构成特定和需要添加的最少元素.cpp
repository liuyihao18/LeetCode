// 1785_构成特定和需要添加的最少元素.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        long long diff = abs(sum - goal);
        int result = static_cast<int>((diff + limit - 1) / limit);
        return result;
    }
};
