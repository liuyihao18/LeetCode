// 2576_���������±�.cpp
#include "custom.h"
ustd

class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = static_cast<int>(nums.size());
        int l = 0, r = n / 2;
        auto check = [&](int m) {
            for (int i = 0; i < m; i++) {
                if (nums[i] * 2 > nums[n - m + i]) {
                    return false;
                }
            }
            return true;
        };
        while (l < r) {
            int m = (l + r + 1) >> 1;
            if (check(m)) {
                l = m;
            }
            else {
                r = m - 1;
            }
        }
        return l * 2;
    }
};
/*
���ߣ����۹ٷ����
���ӣ�https ://leetcode.cn/problems/find-the-maximum-number-of-marked-indices/solutions/2905207/qiu-chu-zui-duo-biao-ji-xia-biao-by-leet-0j2m/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/