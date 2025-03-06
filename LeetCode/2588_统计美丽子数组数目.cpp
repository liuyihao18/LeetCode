// 2588_ͳ��������������Ŀ.cpp
#include "custom.h"
ustd

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        size_t n = nums.size();
        vector<int> prefix(n, 0);
        int temp = 0;
        for (size_t i = 0; i < n; i++) {
            temp ^= nums[i];
            prefix[i] = temp;
        }
        long long result = 0;
        unordered_map<int, long long> um;
        um[0] = 1;
        for (size_t i = 0; i < n; i++) {
            result += um[prefix[i]];
            um[prefix[i]]++;
        }
        return result;
    }
};
