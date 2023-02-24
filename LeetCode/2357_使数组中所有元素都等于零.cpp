// 2357_使数组中所有元素都等于零.cpp
#include "custom.h"
ustd

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int result = 0;
        sort(nums.begin(), nums.end(), greater<>());
        while (nums.size() > 0) {
            while (nums.size() > 0 && nums.back() == 0) {
                nums.pop_back();
            }
            if (nums.size() > 0) {
                for (auto& num : nums) {
                    num -= nums.back();
                }
                result++;
            }
        }
        return result;
    }
};
