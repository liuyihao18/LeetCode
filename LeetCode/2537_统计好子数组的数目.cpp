// 2537_统计好子数组的数目.cpp
#include "custom.h"
ustd

class Solution {
public:
    long long countGood(vector<int>& nums, long long k) {
        size_t l = 0, r = 0, n = nums.size();
        map<int, long long> m;
        long long result = 0;
        long long count = 0;
        while (r < n) {
            m[nums[r]]++;
            count += m[nums[r]] - 1;
            while (count >= k) {
                result += n - r;
                count -= m[nums[l]] - 1;
                m[nums[l]]--;
                if (m[nums[l]] == 0) {
                    m.erase(nums[l]);
                }
                l++;
            }
            r++;
        }
        return result;
    }
};
