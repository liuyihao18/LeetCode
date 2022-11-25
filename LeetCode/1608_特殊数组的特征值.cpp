// 1608_特殊数组的特征值.cpp
#include "custom.h"
ustd

class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = static_cast<int>(nums.size());
        while (left <= right) { // [left, right]
            int mid = (left + right) / 2;
            auto iter = lower_bound(nums.begin(), nums.end(), mid);
            auto x = distance(iter, nums.end());
            if (x < mid) {
                right = mid - 1;
            }
            else if (x > mid) {
                left = mid + 1;
            }
            else {
                return static_cast<int>(x);
            }
        }
        return -1;
    }
};
