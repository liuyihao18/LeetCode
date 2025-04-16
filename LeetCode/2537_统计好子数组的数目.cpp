// 2537_统计好子数组的数目.cpp
#include "custom.h"
ustd

class Solution {
public:
    long long countGood(vector<int>& nums, long long k) {
        size_t l = 0, r = 0, n = nums.size();
        unordered_map<int, long long> m;
        long long result = 0;
        long long count = 0;
        while (r < n) {
            count += m[nums[r]]++;
            while (count >= k) {
                result += n - r;
                count -= --m[nums[l]];
                l++;
            }
            r++;
        }
        return result;
    }
};
