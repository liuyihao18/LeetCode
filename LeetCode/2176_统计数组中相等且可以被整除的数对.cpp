// 2176_统计数组中相等且可以被整除的数对.cpp
#include "custom.h"
ustd

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = static_cast<int>(nums.size());
        map<int, vector<int>> m;
        for (int i = 0; i < n; i++) {
            m[nums[i]].push_back(i);
        }
        int result = 0;
        for (const auto& [_, index] : m) {
            // 最差情况下复杂度仍为平方
            // 但是有可能可以通过一些方法加速
            for (size_t i = 0; i < index.size(); i++) {
                for (size_t j = i + 1; j < index.size(); j++) {
                    if (index[i] * index[j] % k == 0) {
                        result++;
                    }
                }
            }
        }
        return result;
    }
};
