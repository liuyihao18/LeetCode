// 1798_���ܹ��������ֵ�������Ŀ.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        int res = 1;
        sort(coins.begin(), coins.end());
        for (auto& i : coins) {
            if (i > res) {
                break;
            }
            res += i;
        }
        return res;
    }
};
/*
���ߣ����۹ٷ����
���ӣ�https ://leetcode.cn/problems/maximum-number-of-consecutive-values-you-can-make/solutions/2090079/ni-neng-gou-zao-chu-lian-xu-zhi-de-zui-d-wci4/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/
