// 2597_美丽子集的数目.cpp
#include "custom.h"
ustd

class Solution {
    int beautifulSubsets(const vector<int>& nums, size_t j, unordered_map<int, int>& us, int k, int& result) {
        for (size_t i = j; i < nums.size(); i++) {
            if (us.count(nums[i])) {
                continue;
            }
            result++;
            us[nums[i] - k]++;
            us[nums[i] + k]++;
            beautifulSubsets(nums, i + 1, us, k, result);
            if (--us[nums[i] - k] == 0) {
                us.erase(nums[i] - k);
            }
            if (--us[nums[i] + k] == 0) {
                us.erase(nums[i] + k);
            }
        }
        return result;
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> us;
        int result = 0;
        beautifulSubsets(nums, 0, us, k, result);
        return result;
    }
};
