// 891_�����п��֮��.cpp
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
���ߣ����۹ٷ����
���ӣ�https ://leetcode.cn/problems/sum-of-subsequence-widths/solutions/1976655/zi-xu-lie-kuan-du-zhi-he-by-leetcode-sol-649q/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/
