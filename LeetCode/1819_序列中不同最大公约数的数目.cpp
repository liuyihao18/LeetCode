// 1819_�����в�ͬ���Լ������Ŀ.cpp
#include "custom.h"
ustd

class Solution {
    int gcd(int a, int b) {
        while (b > 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<bool> occured(maxVal + 1, false);
        for (int num : nums) {
            occured[num] = true;
        }
        int ans = 0;
        for (int i = 1; i <= maxVal; i++) {
            int subGcd = 0;
            for (int j = i; j <= maxVal; j += i) {
                if (occured[j]) {
                    if (subGcd == 0) {
                        subGcd = j;
                    }
                    else {
                        subGcd = gcd(subGcd, j);
                    }
                    if (subGcd == i) {
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
/*
���ߣ����۹ٷ����
���ӣ�https ://leetcode.cn/problems/number-of-different-subsequences-gcds/solutions/2060230/xu-lie-zhong-bu-tong-zui-da-gong-yue-shu-ha1j/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/
