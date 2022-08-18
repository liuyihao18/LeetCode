// 1224_������Ƶ��.cpp
#include "custom.h"
ustd

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int, int> freq, count;
        int res = 0, maxFreq = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count[nums[i]] > 0) {
                freq[count[nums[i]]]--;
            }
            count[nums[i]]++;
            maxFreq = max(maxFreq, count[nums[i]]);
            freq[count[nums[i]]]++;
            bool ok = maxFreq == 1 ||
                freq[maxFreq] * maxFreq + freq[maxFreq - 1] * (maxFreq - 1) == i + 1 && freq[maxFreq] == 1 ||
                freq[maxFreq] * maxFreq + 1 == i + 1 && freq[1] == 1;
            if (ok) {
                res = max(res, i + 1);
            }
        }
        return res;
    }
};
/*
���ߣ�LeetCode - Solution
���ӣ�https ://leetcode.cn/problems/maximum-equal-frequency/solution/zui-da-xiang-deng-pin-lu-by-leetcode-sol-5y2m/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/
