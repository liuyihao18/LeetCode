// 3653_区间乘法查询后的异或_I.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, const vector<vector<int>>& queries) {
    	for (auto&& query : queries)
        {
            const int l = query[0];
            const int r = query[1];
            const int k = query[2];
            const int v = query[3];
            for (int i = l; i <= r; i += k)
            {
                const long long num = 1LL * nums[i] * v % static_cast<long long>(1e9 + 7);
                nums[i] = static_cast<int>(num);
            }
        }
        return accumulate(nums.begin(), nums.end(), 0, [](const int a, const int b) { return a ^ b; });
    }
};
