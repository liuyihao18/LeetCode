// 2364_统计坏数对的数目.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        // j - i == nums[j] - nums[i] => nums[i] - i == nums[j] - j
        int n = static_cast<int>(nums.size());
        for (int i = 0; i < n; i++) {
            nums[i] -= i;
        }
        sort(nums.begin(), nums.end());
        int i = 0, j = 0;
        long long result = 0;
        while (j < n) {
            while (j < n && nums[j] == nums[i]) {
                j++;
            }
            int temp = j - i;
            result += 1LL * temp * (temp - 1LL) / 2LL;
            i = j;
        }
        result = 1LL * n * (n - 1LL) / 2LL - result;
        return result;
    }
};
