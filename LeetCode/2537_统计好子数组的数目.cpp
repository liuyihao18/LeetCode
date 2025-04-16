// 2537_ͳ�ƺ����������Ŀ.cpp
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
            count += m[nums[r++]]++;
            while (count >= k) {
                result += n - r + 1;
                count -= --m[nums[l++]];
            }
        }
        return result;
    }
};
