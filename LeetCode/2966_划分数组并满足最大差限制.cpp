// 2966_划分数组并满足最大差限制.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        size_t n = nums.size();
        for (size_t i = 0; i + 2 < n; i += 3) {
            if (nums[i + 2] - nums[i] > k) {
                return {};
            }
            results.push_back({ nums[i], nums[i + 1], nums[i + 2] });
        }
        return results;
    }
};
