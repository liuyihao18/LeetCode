// 2799_统计完全子数组的数目.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        size_t n = nums.size();
        set<int> s(nums.begin(), nums.end());
        size_t i = 0, j = 0;
        map<int, size_t> m;
        int result = 0;
        while (j < n) {
            m[nums[j]]++;
            while (i <= j && m.size() == s.size()) {
                result += static_cast<int>(n - j);
                if (--m[nums[i]] == 0) {
                    m.erase(nums[i]);
                }
                i++;
            }
            j++;
        }
        return result;
    }
};
