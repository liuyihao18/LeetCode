// 462_�����ƶ�����ʹ����Ԫ�����_II.cpp
#include "custom.h"
ustd

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        size_t middle = nums.size() / 2;
        nth_element(nums.begin(), nums.begin() + middle, nums.end()); // ��λ��
        int result = accumulate(nums.begin(), nums.end(), 0, [&](int sum, int num) {
            return sum + abs(num - nums[middle]);
            });
        return result;
    }
};
