// 891_子序列宽度之和.cpp
#include "custom.h"
ustd

class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long res = 0, mod = static_cast<long long>(1e9) + 7;
        long long x = nums[0], y = 2;
        for (size_t j = 1; j < nums.size(); j++) {
            res = (res + nums[j] * (y - 1) - x) % mod;
            x = (x * 2 + nums[j]) % mod;
            y = y * 2 % mod;
        }
        return static_cast<int>((res + mod) % mod);
    }
};
/*
作者：力扣官方题解
链接：https ://leetcode.cn/problems/sum-of-subsequence-widths/solutions/1976655/zi-xu-lie-kuan-du-zhi-he-by-leetcode-sol-649q/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
