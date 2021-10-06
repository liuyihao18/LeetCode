// 414_���������.cpp
#include "custom.h"
ustd

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // ����һ
        /*
        set<int, greater<>> s(nums.begin(), nums.end());
        if (s.size() < 3) {
            return *s.begin();
        }
        else {
            return *(++(++s.begin()));
        }
        */
        // ������
        sort(nums.begin(), nums.end(), greater<>());
        auto last = unique(nums.begin(), nums.end());
        if (last - nums.begin() < 3) {
            return nums[0];
        }
        else {
            return nums[2];
        }
    }
};