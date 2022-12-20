// 1760_������������Ŀ����.cpp
#include "custom.h"
ustd

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int ans = 0;
        while (left <= right) {
            int y = (left + right) / 2;
            long long ops = 0;
            for (int x : nums) {
                ops += (x - 1) / y;
            }
            if (ops <= maxOperations) {
                ans = y;
                right = y - 1;
            }
            else {
                left = y + 1;
            }
        }
        return ans;
    }
};
/*
���ߣ����۹ٷ����
���ӣ�https ://leetcode.cn/problems/minimum-limit-of-balls-in-a-bag/solutions/2025611/dai-zi-li-zui-shao-shu-mu-de-qiu-by-leet-boay/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/
